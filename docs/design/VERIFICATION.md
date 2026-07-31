# What of this could be proved correct

Referee is written in a proof assistant and tested with 491 `#guard`s. This document asks the
question that situation invites: which parts of the code could carry a *theorem* instead of a table
of examples, what would the theorem say, and what would it cost. Written as a menu to argue with,
not a plan — nothing here is committed to.

**Status.** Items 3, 4 and 5 are done, in [`Proofs/Diff.lean`](../../Proofs/Diff.lean), and so is
the provenance ledger (item 9 below), in [`Proofs/Provenance.lean`](../../Proofs/Provenance.lean).
Item 1 is half done: `intern`/`resolve` are **no longer `partial`**, which is what stood between
them and any theorem at all, with the reachable proofs in
[`Proofs/Collect.lean`](../../Proofs/Collect.lean) and the round trip itself still open for reasons
recorded there. `lake build Proofs`, and CI builds it. Sixty-two theorems plus sixteen private
supporting lemmas, no `sorry`, and no axioms beyond `propext`, `Classical.choice` and `Quot.sound`.
The rest of this document is still a menu.

The framing observation. Several of the functions below already have their correctness stated, in
prose, in their own docstrings: that `resolve` inverts `intern`, that table entry `i` references only
entries below `i`, that `asciiTagOf` is injective, that `stripEmptyScopes` keeps nesting balanced at
any depth, that `topologicalClosure` emits every declaration after its dependencies. Those sentences
are specifications. What is missing is not the statement but the proof — and in a codebase whose
whole purpose is to show a reader where trust has to start, its own diff module currently asks to be
believed on the strength of 64 examples.

## The three tiers

The dividing line is not "hard versus easy". It is whether there is anything a theorem could be
*about* at all.

| | |
|---|---|
| **Pure total functions over plain data** | Provable today, no refactor. `Diff`'s classification and comparison keys, `reverseDeps`, the small `Name`/`String` utilities. |
| **Pure but `partial`** | 40 `partial def`s across the repo, down from 43 once `Collect`'s three came off. A `partial def` in Lean is an opaque constant with no equations, so *nothing* about one can be proved. These need to become structural or well-founded recursions first. Most of the load-bearing code is here: `intern`/`resolve`, `topologicalClosure`, the `Expr` walks. |
| **`Environment`, `IO`, the frontend** | `shouldExpose`, `blameDeclarations`, `highlightSource`, most of `Website/Site.lean`. Out of reach: a specification would be a statement about Lean's own elaborator. |

Tier 2 is the whole story. The cost of verifying this library is mostly the cost of removing
`partial`, and that work has value on its own — a `partial def` is also a definition the kernel
cannot unfold and a reader cannot reason about.

## Ranked

### 1. The `intern`/`resolve` round trip — **`partial` removed; round trip open**

[`Referee/Collect.lean`](../../Referee/Collect.lean#L790-L865) — `internAux`, `resolveAgainst`,
`intern`, `resolve`.

This is the on-disk format for the entire pipeline. A corruption here is silent and total, and the
docstrings already state three theorems:

```lean
theorem intern_roundTrip (j : Json) :
    let (table, root) := intern j
    resolve table root = j

/-- The invariant `resolve`'s single forward pass is sound because of. -/
theorem intern_table_wellFounded (j : Json) (i : Nat) :
    ∀ r ∈ references ((intern j).1[i]!), r < i

/-- The guard genuinely buys unambiguity: with no `$i` key in the payload, nothing in the
encoding is confusable with a reference. -/
theorem intern_unambiguous (j : Json) (h : ¬ usesInternKey j) : …
```

The first is checked by `internRoundTrips` on three fixtures
([`Test/Collect.lean:684`](../../Test/Collect.lean#L684)). The second — stated as a comment on
`internAux` and relied on by `resolve` — is checked by nothing at all, not even a test.

**Status: `partial` removed; round trip still open.** The three walks — `usesInternKey`,
`internAux`, `resolveAgainst` — are now **total** ([`Referee/Collect.lean`](../../Referee/Collect.lean)),
and the reachable proofs are in [`Proofs/Collect.lean`](../../Proofs/Collect.lean). All 185
`#guard`s in `Test/Collect.lean` still pass.

*Why `partial` was there.* Never termination — every recursive call is on a strict subterm. Lean
could not *see* it. `Json` is a nested inductive whose object case holds a `Std.TreeMap.Raw`, and
folding that tree hands the termination checker a value with no evidence tying it to the tree.
`Array` and `List` ship `sizeOf_lt_of_mem`; the tree containers do not. That single gap is why every
recursion over `Json` in Lean core — `beq'`, `hash'`, `render`, `compress` — is *still* `partial`.

*What closed it.* Two lemmas, about twenty lines: `sizeOf_lt_of_mem_toListModel`, by induction on the
tree's internal `Impl`, and `objPairs_sizeOf`, which lifts it to the public `toList` through core's
`Impl.Const.toList_eq_toListModel_map`. The walks are then ordinary well-founded definitions on
`sizeOf j`. So `partial` here was a gap in the standard library, not a property of this code.

*What that bought.* The **equations**, which is the whole point — `resolveAgainst r (.str s) = .str s`
is now provable, and was not before. And `resolveAgainst.induct` / `usesInternKey.induct`: functional
induction principles **over `Json`**, which is the only induction over JSON available at all, since
the `induction` tactic refuses nested inductives outright.

*What is proved.* The forward-pass discipline, stated over an arbitrary resolver: the resolved table
has one entry per table entry, and entry `i` is resolved against the table built from **exactly the
entries below `i`** — the "already resolved when it is reached" half of the docstring's argument.
Plus the equations, that an empty table never substitutes (so an out-of-range index is left alone
rather than raising), and that `intern` really does decline, returning `(#[], j)`, when
`usesInternKey` fires.

*What still blocks the round trip.* Three things, and the second is the interesting one:

1. **`internAux.induct` does not exist.** Lean declines to derive it — "Cannot derive functional
   induction principle (please report this issue)". The encoder can only be reasoned about by hand.
2. **Structural equality is the wrong specification.** `resolveAgainst` rebuilds every object it
   passes through via `Json.mkObj`, which is `Json.obj ∘ Std.TreeMap.Raw.ofList`. A round trip
   therefore returns a *rebuilt* tree, and `ofList (m.toList) = m` is not available: `Json.obj`
   holds a `Raw` map with no well-formedness invariant, and core proves no `ofList`/`toList` inverse
   even for the well-formed case, since two differently shaped balanced trees can hold the same
   entries. The repo's own tests already have this right without saying so — `internRoundTrips`
   compares `.compress` output, not values. Stating the theorem properly means defining equality of
   JSON *contents* and proving the round trip up to that, not up to `=`. That is a reformulation of
   the goal, not just more proof.
3. **`LawfulBEq Json` cannot be synthesized**, because core's `beq'` is `partial`. `internAux`'s
   reverse index is a `Std.HashMap Json Nat`, so any argument about it needs that as a hypothesis.
   (`internAux` also sizes subtrees with the `partial` `Json.compress`; that one is harmless, since
   the threshold only decides which subtrees get tabled and the round trip holds either way.)

### 2. The token diff satisfies its interface

[`Referee/Diff.lean`](../../Referee/Diff.lean#L261-L326) — `alignTokens`, `trimTokens`,
`statementDiff`.

The correctness specification of a diff is a projection property, and it is nowhere tested:

```lean
theorem alignTokens_left (xs ys : Array String) :
    ((alignTokens xs ys).filter (·.kind ≠ "ins")).map (·.text) = xs

theorem alignTokens_right (xs ys : Array String) :
    ((alignTokens xs ys).filter (·.kind ≠ "del")).map (·.text) = ys
```

That is exactly *the rendered diff is not lying about either side*. `trimTokens` is a second
implementation of the same interface, reached above `maxAlignTokens`, and proving both against one
specification is what stops the fallback path from drifting away from the fast one. A third,
cheaper statement worth having: `statementDiff old new` yields `same`-only tokens iff
`statementTokens old = statementTokens new`.

**Cost.** `alignTokens` uses `set!` and `getElem!` against a flat-indexed table, so a direct proof
drags in index-bound reasoning. The clean route is a `List`-level reference LCS, proved correct, with
the array implementation proved to refine it. Optimality (the `same` count *is* the LCS length) is
provable too, but it is much more work and much less valuable than the projection property — a
suboptimal alignment renders badly, a non-projecting one renders a falsehood.

### 3. `normalizeSpace` is a canonical form — **proved**

[`Referee/Diff.lean`](../../Referee/Diff.lean#L183-L208) — `statementTokens`, `normalizeSpace`,
`statementKey`, `bodyKey`.

Every claim the Changes page makes rests on these keys being a genuine quotient of the text:

```lean
theorem normalizeSpace_idem (s : String) :
    normalizeSpace (normalizeSpace s) = normalizeSpace s

theorem normalizeSpace_eq_iff (s t : String) :
    normalizeSpace s = normalizeSpace t ↔ statementTokens s = statementTokens t

theorem statementTokens_ne_empty (s : String) : ∀ t ∈ statementTokens s, t ≠ ""
theorem statementTokens_no_ws (s : String) : ∀ t ∈ statementTokens s, ¬ t.any Char.isWhitespace
```

This is the formal content of the module's claim that a line break moving is not a change a referee
needs to hear about.

**Done**, and it turned out to be the only item here with real work in it. The tokenizer is a
`String.foldl`, and in this toolchain `String` has essentially no reasoning API of its own, so the
proofs bridge to `List Char` through `String.foldl_eq_foldl_toList` and induct there. The load is
carried by two lemmas: an invariant saying every committed token is non-empty and whitespace-free,
and a **round trip** — joining clean tokens with single spaces and re-tokenizing returns exactly
those tokens. Idempotence and the `↔` are corollaries. One trick keeps the round trip short: a
trailing space performs exactly the flush the tokenizer ends with, so the induction never has to
reason about a distinguished last token.

The `↔` is the one worth reading twice. Left to right it is the promise the module makes — whitespace
edits are invisible. Right to left, contrapositively, it is the promise the module does *not* make
out loud: every difference the tokenizer can see does reach the page. The comparison is neither
coarser nor finer than the tokenization, and that is now checked rather than assumed.

### 4. The `ChangeKind` design invariants — **proved**

[`Referee/Diff.lean`](../../Referee/Diff.lean#L153-L175) — `needsReaudit`, `movedMeaning`,
`attributable`, and [`directKind`](../../Referee/Diff.lean#L522).

Four predicates over one seven-constructor enumeration, written as four independent `match`es that
can silently drift apart. Each of these is a one-line `decide`:

```lean
theorem movedMeaning_needsReaudit (k : ChangeKind) : k.movedMeaning → k.needsReaudit

/-- The subtle point the docstrings argue at length: `upstream` is deliberately in both sets,
and is the only thing in both. -/
theorem attributable_movedMeaning (k : ChangeKind) :
    k.attributable → k.movedMeaning → k = .upstream

/-- Pass one never produces `.indirect`, which is what makes the propagation pass its sole
source. -/
theorem directKind_ne_indirect (old new : DeclInfo) : directKind old new ≠ .indirect
```

Cheap, and they turn prose arguments into things a later edit cannot break quietly. **Done**, along
with two more of the same kind that only became visible while writing them: `slug` and `label` are
both injective. Neither is decoration — the slug is a CSS hook *and* the Browse table's filter
value, so two kinds sharing one would be indistinguishable in the interface while the rest of the
tool kept them apart.

Two harder ones about `diff` itself, both worth the trouble because they are the module's headline
claims. First, the post-condition of the propagation pass: no change comes out `.indirect` with
empty `causes`, and every cause named is in `meaningChanged`. Second — and this is an unstated
invariant spanning two modules — the module docstring says indirect invalidation is found by
*closing* the changed set over `dataTransDeps`, while the implementation is a single `map`, not a
fixpoint. It is correct only because `dataTransDeps` is already transitively closed. Stating that as
a hypothesis and proving the pass idempotent under it is what makes the dependence explicit:

```lean
theorem propagate_fixpoint (h : ∀ d ∈ data.decls, TransitivelyClosed d.dataTransDeps) :
    propagate (propagate cs) = propagate cs
```

### 5. `looksLikeToolchainChurn` is gated as claimed — **proved**

[`Referee/Diff.lean:447`](../../Referee/Diff.lean#L447).

```lean
theorem fullyHashed_no_churn (r : DiffReport) : r.fullyHashed → ¬ r.looksLikeToolchainChurn
```

Two lines, and it makes the docstring's central safety claim machine-checked rather than argued.
`fullyHashed → usedHashes` came along with it, which is the arithmetic the page's "what measure was
this built on" sentence assumes.

### 6. `topologicalClosure` — **total; closed under dependencies; ordering still open**

[`LeanDeps/LeanDeps.lean`](../../LeanDeps/LeanDeps.lean), proofs in
[`Proofs/Deps.lean`](../../Proofs/Deps.lean).

This is the pass whose output is *executed*: `Referee/Extract.lean` emits a standalone file's
declarations in exactly this order, so a wrong answer is a file that does not compile. It is also
where the tool's most-assumed invariant lives.

**Total.** `visitFuel` takes an explicit fuel bounding recursion *depth*; `topologicalClosure` passes
`depsMap.size + 1`. And that bound is now **proved sufficient**: `unvisitedKeys` — how many keys the
walk has not yet entered — strictly decreases at every recursive call, because the walk descends only
from a node with dependencies (hence a key) and never twice from the same key.

**Proved.**

- **The closure is closed** (`transitiveDeps_closed`): if `y` is in a declaration's transitive
  closure and `z` is a dependency of `y`, then `z` is in that closure. Three features assume this
  and none of them states it — `Referee/Diff.lean` finds indirect invalidation with *one pass* over
  `dataTransDeps` rather than a fixpoint, which is correct only under this theorem;
  `Referee/Audit.lean` defines coverage as "every project declaration in its statement closure
  accepted too" and walks it bottom-up as a reading queue; and the declaration graph lays it out in
  rows by depth. A closure that was not closed would make all three wrong in the same direction —
  less to re-read, less to accept, less to look at — which reads exactly like a library with fewer
  dependencies.
- **No declaration is emitted twice** (`topologicalClosure_nodup`) — a file declaring the same
  constant twice does not compile, and nothing else would catch it.
- **Every root is emitted**, and the invariants underneath: the visited set and emitted order only
  grow; anything a call emits was unvisited when the call began; everything emitted has been
  visited; and everything visited has been emitted by the time the call that entered it returns.

**Still open: the ordering itself** — that each declaration appears after the ones it depends on.
The pieces are now all present: when `n` is pushed, each dependency has been visited
(`deps_visited`), hence emitted (`finished_preserved`), hence precedes `n` — *unless* it is an
ancestor still on the walk's stack, which is exactly a cycle. What remains is a reachability relation
and an acyclicity hypothesis. That is also the honest form of the docstring's "cycles are tolerated,
and their members come out in some arbitrary but otherwise dependency-respecting order" — a sentence
that, as written, is not a property that holds of anything, since inside a cycle some dependency
necessarily follows its dependent.

Alongside it, [`reverseDeps`](../../LeanDeps/LeanDeps.lean) is a plain fold, already total, and its
specification is a clean iff:

```lean
theorem mem_reverseDeps (nodes : Array (Name × Array Name)) (d m : Name) :
    m ∈ (reverseDeps nodes).getD d #[] ↔
      (∃ deps, (m, deps) ∈ nodes ∧ d ∈ deps) ∧ d ∈ nodes.map (·.1)
```

### 7. `applyEdits`

[`Referee/Extract.lean:300`](../../Referee/Extract.lean#L300).

Three independent producers — `attributeStripEdits`, `setOptionStripEdits`, `derivingReplacement?` —
feed one applier, and non-overlap of their edits is an *unstated* assumption of all three. Proving
`applyEdits` correct forces the precondition into the open:

```lean
theorem applyEdits_spec (h : Sorted edits) (h' : NonOverlapping edits) (hb : InRange edits) :
    applyEdits source cmdStart cmdEnd edits = interleave (slices source edits) (replacements edits)

theorem applyEdits_nil : applyEdits source cmdStart cmdEnd #[] = slice source cmdStart cmdEnd
```

and the interesting theorem is then that the union of the three producers satisfies it. This is
precisely the shape of code where an off-by-one lives undetected.

### 8. `stripEmptyScopes`

[`Referee/Extract.lean:896`](../../Referee/Extract.lean#L896).

The docstring claims two things: that nesting stays balanced regardless of how deep an empty block
is, and that a scope is kept iff it transitively contains a `hard` chunk. Both are ordinary
properties of the stack machine — but only reachable after splitting the function so that it returns
structure rather than a `String`, with rendering separated out. That refactor is an improvement on
its own terms, which is the usual pattern: making a function provable makes it better.

### 9. The provenance ledger — **proved**

[`Referee/Provenance.lean`](../../Referee/Provenance.lean) — `foldDecl`, `foldRevision`.

Not in the original list, and it should have been: it outranks everything above it except item 1.
Every other artifact the tool writes is regenerated from the environment next build, so a wrong
answer lasts until the bug is fixed. The ledger is **append-only and kept for the life of a
project** — a wrong answer written into it is wrong forever, and every later fold builds on it.

What is proved, in [`Proofs/Provenance.lean`](../../Proofs/Provenance.lean):

- **No spurious change.** When a declaration's hash matches what the ledger holds, the entry that
  comes out differs from the stored one in `statement` alone — refreshed by design, since it is the
  baseline the next fold compares against. `changedAt`, `changeCount` and `lastKind` are carried
  over untouched and the revision's change counter does not move. This is the invariant the ledger's
  value rests on, and the one that cannot be allowed to fail even once.
- **The counter is honest.** A revision never reports more declarations changed than it reports
  declarations. Both numbers appear on the page.
- **Nothing is forgotten.** An entry for a declaration this revision does not expose survives the
  fold — what the docstring promises about declarations that vanish and come back.
- **Append-only**, literally: dropping the appended revision returns the previous history unchanged.
- **The ledger only records moved meanings.** Every kind `provenanceKind` can return satisfies
  `movedMeaning`, so `lastKind` can never come to hold a kind that means nothing happened. This
  composes with item 4's `movedMeaning → needsReaudit` across the two modules.
- **Short abbreviations are not matched.** Below seven characters, a label matching no revision's
  `ref` exactly gets no date rather than the date of whichever revision shares its first characters.

**Cost.** One behavior-preserving refactor: `foldRevision`'s `for` loop became an `Array.foldl` over
a named `foldDecl`. The loop body ended in a `match`, which blocks core's `forIn`→`foldl` simp lemma
(it wants `fun a b => pure (.yield (f a b))` and cannot see past the match), so nothing about the
fold was reachable while it stayed a loop. The 48 existing `#guard`s pin the behavior and all still
pass.

**And one wall.** `foldRevision` ends by sorting entries with `Array.qsort`, and this toolchain
proves *nothing* about `qsort` — not that it permutes its input, not even that it preserves length.
So no property of `foldRevision.entries` can be stated at all; the results above are about the fold
that produces those entries. That is a standard-library gap rather than a Referee one, but it does
say something about the shape: the sort is presentational, the fold is the semantics, and burying
the first inside the second puts the whole result out of reach. Splitting them would make "every
entry the ledger had is still there" a statement about `foldRevision` itself.

## Carrying the proofs across the serialization gap

`transitiveDeps_closed` is a theorem about the **function** `LeanDeps.transitiveDeps`. What the site
renders is `DeclInfo.dataTransDeps`, loaded from `data.json`. Between them:

```
transitiveDeps  →  collect calls it  →  toJson + intern  →  parse + resolve + fromJson?  →  render
    proved            Collect.lean          unproved         provably out of reach (item 1)
```

Until now `loadCollectedData` checked the format version and **nothing else**. So the closure
properties were proved at one end of that chain and unchecked at the other, with the one link this
document shows is unreachable sitting in the middle. A theorem about a producer establishes nothing
about the value a consumer holds.

`CollectedData.integrityViolations` closes it from the other end: the proved properties, restated as
assertions on the *decoded* data, run on every `build-site`.

- a declaration never appears in its own closure;
- no closure has repeated entries (`topologicalClosure_nodup`);
- every direct dependency is in the closure (`mem_topologicalClosure_of_mem_start`);
- the closure is closed under taking dependencies (`transitiveDeps_closed`) — the one a reader could
  never spot, and the one three separate features assume.

Upstream constants are leaves: they carry no recorded edges, so a closure mentioning one is not
required to contain anything beyond it.

**Measured.** Zero violations on `LeanDeps` (48 declarations) and on `Referee` itself (777), about
two seconds including the decode. Deleting one name from one closure is caught and reported by name:

```
data3.json: collected data failed its own consistency checks:
  Referee.lemmaSyntaxKinds: dataTransDeps omits its direct dependency Lean.SyntaxNodeKind
```

with exit code 1, so CI stops rather than publishing a site whose closures are quietly wrong.
`Test/Collect.lean` pins that the checker *fires*: one fixture per property, each violating exactly
that property — a checker that can only pass is worth nothing.

**Why this ranks above another theorem.** It is the only thing here that defends against the failure
modes proofs cannot reach at all: a truncated write, a bad merge, a version skew, or a future change
that stops routing a closure through `LeanDeps.transitiveDeps` and quietly detaches every theorem
above from the data below.


## Pinning past bugs

A different way to choose targets: not "what is provable" but "what has already gone wrong". Three
fixes in the history assert an invariant somewhere — in a commit comment, in a docstring — that
nothing checks. Two of those invariants are now theorems.

**`b099a84`, Verso duplicate tags.** Two parts claiming the same `tag` leaves one without an external
ID, reported as `No external ID for <title>` with no hint that a collision is what happened. It
happens because a project may name a file after the definition it introduces — with
`--root Mathlib.Logic`, `Mathlib/Logic/Denumerable.lean` is its own chapter *and* its own module
*and* defines `Denumerable`. The fix prefixes each tag by kind, "making the collision impossible
rather than unlikely". That is a claim about four functions, and it is now six theorems: the four
tag families are pairwise disjoint for all inputs
([`Proofs/Collect.lean`](../../Proofs/Collect.lean)).

**`6b1da0c`, the changes page.** A change count of zero arises two ways — a declaration present all
along that never moved, and one added later that has not moved since — and the page rendered both as
"unchanged since the beginning", reporting a declaration added yesterday as part of the original
library. The fix added `seenFromStart`, with a comment stating what it relies on: *`changedAt` equals
`firstSeenAt` whenever the count is zero.* Nothing checked it. It is now `foldDecl_pushed_neverMoved`,
together with its other half, that `firstSeenAt` is immutable once set
([`Proofs/Provenance.lean`](../../Proofs/Provenance.lean)). Also pinned there:
`alreadyAt_foldRevision`, that the guard against folding the same revision twice actually fires for
every revision carrying a sha — the guard exists because a re-run would otherwise inflate the change
count permanently.

**`aaf381c`, `protected lemma` read as a theorem.** Out of reach, and the reason is the same
`String` wall as everywhere else. `isLemmaFromSource` matched `startsWith "lemma "`, so
`protected lemma foo` was classified as a theorem and promoted onto the Claims page. The fix added
`dropDeclModifiers`, and the theorem worth having is that prefixing a snippet with any modifier —
or a modifier and a newline, the case the docstring calls out — does not change what the
keyword-reader sees. But `dropDeclModifiers` is built from `String.drop`, `String.takeWhile` and
`String.trimAscii`, which in this toolchain return `String.Slice` values with no `toList` and no
lemmas. There is nothing to reason with.

The general lesson from all three: the invariant a bug fix depends on is usually written down, in
prose, in the commit or the docstring — and is usually the thing nothing checks. Reading the fix
history is a better way to pick proof targets than reading the code.

## What a proof attempt already found

[`anchorIdOf`](../../Referee/Collect.lean#L1126) is **not injective**, and it determines the
filename of every extracted `.lean` file:

```
anchorIdOf `Foo.bar      = "Foo___bar"    -- "." ↦ "___"
anchorIdOf `«Foo___bar»  = "Foo___bar"    -- single component, passed through
```

Two declarations mapping to one anchor means one extracted file silently overwrites the other, and
one declaration page's links point at another declaration. Contrived, but legal Lean, and nothing
anywhere detects it.

Its sibling [`asciiTagOf`](../../Referee/Collect.lean#L1143) *claims* injectivity in its docstring,
and appears to have it — `_` occurs in the output only as an escape delimiter, so the encoding is
unambiguous — but the claim is exactly what a `_x{hex}_` decoder plus `decode ∘ encode = id` would
settle. This collision class has bitten the project once already: the `induction_on₂` /
`induction_on₃` duplicate-tag failure recorded in that same docstring.

The cheap fix, independent of any proof: assert uniqueness of `anchorIdOf` over the collected
declarations at `collect` time, and fail loudly rather than overwrite.

## Out of reach, and one interesting middle case

The `Expr` traversals sit between tiers 2 and 3. `projStructureNames`, `collectEmbeddedNames` and
`dataWalkGo` walk a concrete inductive type, so completeness — *every constant name occurring in `e`
is reported* — is an ordinary induction. Except that all three memoize on a `Std.HashSet Expr`, and
the theorem that actually matters is that the memo never causes an *under*-report. Since a missing
edge means the site claims a result rests on less than it does, that is a soundness property of the
whole tool. Provable in principle; expensive in practice, and it needs the `partial` removed from a
walk whose termination argument is the memo itself.

`dataWalkGo`'s `Prop`-argument masking is not a program-correctness question at all. "Skipping the
arguments that fill `Prop`-valued parameters never drops a constant the definition's *data* depends
on" is a claim about proof irrelevance, and belongs to a different kind of proof than the rest of
this document.

Everything touching `Environment` is out: a specification for `shouldExpose` or `usedConstantsOf`
would be a statement about what Lean's own elaborator produces, and there is no model of that to
state it against. The same goes for `blameDeclarations` (git), `highlightSource` (the frontend), and
`Website/Site.lean` (rendering).

## Where to start

Items 3, 4 and 5 in one sitting — done, in [`Proofs/Diff.lean`](../../Proofs/Diff.lean). They needed
no refactor, and each converts a sentence already written in a docstring into a checked one. Item 9
followed, because the ledger is the one thing here that cannot be corrected by rebuilding. Next is
item 1, which is the place where a bug is both plausible and catastrophic.

A pattern worth noting after two rounds. Both times, what stood between the code and a proof was an
imperative loop, not the difficulty of the property: a `for` over an array in `Provenance`, a
`while` inside `Id.run do` in `alignTokens`. Core has the lemma to turn a yielding `forIn` into a
`foldl`, but it cannot see past a `match` in the body, and `while` goes through `Loop.forIn`, which
is `partial` and therefore proves nothing at all. Naming the step function and folding is a small,
behavior-preserving change that unlocks the whole thing. Where the properties are worth having, it
is the first move.

One thing this turned up on the way. `Proofs` is a Lake target but not a *default* one, so
`lake build` does not build it — and neither, for the same reason, did it ever build `Test`. CI ran
plain `lake build` with no test driver configured, so until now neither the 491 `#guard`s nor these
theorems were checked by it, and the build could go green with both broken. A proof nobody builds is
worth exactly as much as a test nobody runs. `.github/workflows/lean_action_ci.yml` now builds both
explicitly, before packaging the binary.

The measure of success is not a verified library — items 7 and 8 need refactors, item 6 needs a
termination argument, and the `Environment` half of the code is permanently out of reach. It is that
the modules a referee has to trust hardest, which are the pure ones, stop resting on examples.
