# Proposed tools

Candidate additions to the site, ranked, with cost grounded in what the architecture already
provides. Written as a menu to argue with, not a plan: nothing here is committed to, except where
a section says otherwise.

The framing observation. Everything the site does today describes **one snapshot, passively**. The
three biggest gaps are that it cannot say what *changed*, cannot say what *falls* if something is
wrong, and cannot record what the referee has *done*. Those are the first three below.

Status: (1) and (3) are built — see [Revisions](#revisions-the-user-experience) and
[Audit state](#audit-state-what-was-built) for their designs, and the `--baseline` flag and Audit
State sections in [README.md](README.md). The rest are proposals.

## Tier A — pure functions of `data.json` (no new Lean phase, no re-import)

### 1. `referee diff old.json new.json` — what changed since I last read it

Refereeing is iterative: you read v1, the author revises, and you must not re-read 1677
declarations. Nothing in the Lean ecosystem does this, and the `typeDeps`/`deps` split makes the
*right* diff possible rather than a textual one:

- **statement changed** → audit invalidated, re-read;
- **proof changed only** → the kernel already rechecked it, no re-audit needed — the same argument
  the trust page makes for upstream proofs, applied across time;
- added / removed declarations;
- trust-surface deltas: new `sorry`s, new axioms, a package that became unaudited, a definition
  that lost its `@[specifies]`, an extraction that stopped compiling.

P1 already claims version-to-version diffing is nearly free, and it is: no environment, no
re-import. It also has an obvious CI form — "this PR changes 3 statements and introduces 1 sorry"
as a PR comment.

#### Revisions: the user experience

Not a subcommand producing a separate report, but a **dimension the whole site gains**:
`build-site --baseline old-data.json`, exactly parallel to `--trust` — a render-time flag over the
same `data.json`. With no `--baseline`, nothing on the site mentions revisions at all: no page, no
badge, no column, the same gating discipline as `SiteContext.usesSpecs`.

A separate artifact would have been the wrong shape. The referee's next move after "this statement
changed" is always "show me the declaration", so the diff has to live where the declarations are.

**The Changes page**, ordered by what it costs the reader to re-read — never alphabetically, never
by module:

```
Changes since v0.2                                    1677 decls → 1691

  ⚠ 3 statements changed          ← re-audit required
  ⚠ 47 results invalidated indirectly
  ⚠ 1 new sorry
  + 14 new declarations (2 claims)
  − 0 removed
  ✓ 2 sorries discharged
  · 231 proof-only changes        ← no re-audit required, collapsed

── Statements changed ─────────────────────────────────────────
  isBrownianMotion_iff                        Prob/Brownian.lean
    − theorem isBrownianMotion_iff (X : ℕ → Ω → ℝ) …
    + theorem isBrownianMotion_iff (X : ℝ≥0 → Ω → ℝ) …
    47 declarations rest on this statement
```

Only the first section is read in full; everything below it is triage.

**Indirect invalidation is the reason to build this at all.** A theorem whose own statement is
untouched, but whose statement mentions a definition that changed, now *means* something different
while looking byte-identical. `git diff` cannot show that, and a human re-reading the PR reliably
misses it. `transDeps` — already computed, already following `graphDeps` — closed over the changed
set gives it exactly.

What counts as a meaning change, in the same terms the trust page already uses: a declaration's
statement changing, or a **non-theorem's body** changing. A theorem's proof changing invalidates
nothing downstream, because the kernel rechecked it; a definition's body is part of its meaning, so
changing it changes every statement about it. That is precisely the `graphDeps` rule applied across
time rather than across the dependency graph.

**And its inverse, stated loudly.** The proof-only changes — the bulk of any real revision — are
collapsed, with the reason *on the page*: the kernel rechecked them, and a proof cannot change what
a theorem says. Telling the referee what they may skip is the feature.

**On a declaration page**, a banner above the card when its statement changed, carrying the
previous statement inline. For an indirectly invalidated theorem the banner instead names which
definitions in its statement moved, and links to them.

**On Browse**, one `Changed` column and filter — `statement` / `indirect` / `proof-only` / `new` /
`unchanged`. Filtering to statement + indirect and sorting by dependents gives the re-read queue,
expensive first.

**Two decisions that keep it from crying wolf.**

*Detect on the elaborated type, display the source form.* Reformatting, a renamed bound variable,
or a hypothesis moved into a `variable` line must not register as a statement change — and
conversely, editing a `variable` line changes a theorem's statement without touching a character of
its own source text. Only the elaborated type catches both, and `expandedSignature` already carries
it, so detection costs nothing new at collect time.

*Whitespace-normalize before comparing.* Pretty-printer output is not stable enough to compare
raw. The known residual risk is a toolchain bump churning every `expandedSignature` at once and
turning the page into 1677 false positives; the page says so where it reports the count, because
the failure is silent otherwise.

**Renames** are reported as a removal and an addition, with a note where the two statements
coincide. Evidence, not an inferred rename: the tool does not know intent and should not claim to.

**What it deliberately does not cover.** Extraction compile status lives in the
`extracted-highlighting/` output, not in `data.json`, so "this extraction stopped compiling" is out
of range for a diff of two data files. Reporting it would mean baselining a whole site rather than
one JSON file.

One practical consequence for authors: publish `data.json` beside each released site — which P1
argues for on its own merits — and `--baseline` costs the next build one flag.

### 2. Blast radius — "what if I don't believe X?"

Trust is a build flag (`--trust PKG`) and a per-declaration boolean. Make it a counterfactual the
reader can drive: click any declaration, axiom, `sorry`, or upstream package, and the site marks
everything downstream that dies with it. `usedBy` and the reverse closure are already computed, so
this is client-side.

Two numbers, both cheap and genuinely different: the **meaning** blast radius (follow `graphDeps` —
what stops saying what it seems to say) and the **trust** blast radius (follow full `deps` — what
stops being proved). Inverted, it ranks where audit effort pays: "the 10 declarations with the
largest downstream footprint". That is the scheduling question a referee actually has, and the site
currently answers it with nothing.

### 3. Audit state as a first-class artifact

Nobody reads 1677 declarations in one sitting. Per-declaration *accepted / rejected / question*,
stored client-side, plus three things that make it more than a checkbox:

- **propagation** — a theorem is audited only when its statement and every statement-dependency is
  accepted; the closure is already there, so the checklist can compute what is left instead of
  making the referee track it;
- **export / import as JSON**, so the state is a file: attachable to a report, diffable, and
  re-applicable after (1) says which acceptances the revision invalidated;
- **a generated Markdown report** — claims, trust ledger, unspecified definitions, `sorry` chains,
  plus the referee's own notes.

P7 says a reviewer's work product is links. The stronger version is that it is a file, and this
makes the site a work surface rather than a viewer — which no other Lean tool is.

#### Audit state: what was built

**The design turns on what "accepted" means.** One checkbox per declaration produces a number that
lies: a reader who accepts a regret bound without reading `IsAlgEnvSeq` has accepted a sentence.
So each declaration carries two things, and only one is the reader's to set — a **verdict** (unread
/ accepted / query, with a note), and derived **coverage**: accepted, *and* every project
declaration in its statement closure accepted too.

The state worth naming is the third that falls out, **accepted but not covered**. The Audit page
leads with covered claims, never with accepted declarations, because the flattering number is the
one that misleads.

Deliberately orthogonal to trust: a `sorry` never blocks acceptance. Accepting is a judgement about
meaning; whether something is proved is what the trust page is for.

**What ships.** A verdict control under the card on every declaration page, with the line saying
what accepting it would and would not cover; an Audit page with progress, per-claim reading queues,
open queries, and the accepted-but-not-covered list; a Verdict column and filter on Browse; export,
import and a generated Markdown report.

Three pieces were free because the data already existed:

- **the reading queue's order** — `transDeps` is topologically sorted, since the extractor needs
  that to emit a compilable minimal file, and a reader needs exactly the same order;
- **the bulk action** *accept this and everything its statement rests on* — the minimal file **is**
  the closure inlined, so it matches the artifact rather than being a shortcut around it;
- **the import interlock with (1)** — a build with `--baseline` knows which declarations a revision
  invalidated, so importing an older file drops exactly those acceptances and says so, and carries
  verdicts across a rename using the diff's identical-statement evidence.

**Sizing.** Coverage needs every declaration's closure, which is why closures ship as indices into a
shared name table on the audit page and nowhere else: LML's payload is 234 KB for 698 declarations,
where naming each of the 3,293 closure entries as a string would have been several times that, and
brownian-motion has 116,519 edges. Declaration pages carry only their own closure.

**Stated on the page, not just here.** Nothing is authenticated — the file is plain JSON anyone can
edit, and it must never be offered as evidence that a library was audited. Nothing is verified. And
`localStorage` is not storage: it is keyed by project name (GitHub Pages serves every project of an
account from one origin, so a path key would collide or break on a move), and it dies with a cleared
browser profile, which is why export is a button rather than a footnote.

**Not built, on purpose:** no server, no accounts, no multi-reviewer merge, no signatures. Each
turns a static site into an application with an operator, and once there is an operator the artifact
stops being a file the reader owns.

## Tier B — needs the environment (a `collect`-time addition)

### 4. Inhabitation: "is anything of this type ever built?"

The classic way a formalization is vacuously true — a beautiful theorem about `IsBrownianMotion X`
in a project that never constructs a Brownian motion, or a hypothesis class no instance satisfies.
It is derivable: for each definition / structure / class the project introduces, does any
declaration have it in its *conclusion* rather than only in its hypotheses? Report the evidence —
"appears in the statement of 34 theorems, constructed 0 times" — not a verdict, under the same
honesty rule as P11.

This is the exact companion to the Specifications page. `@[specifies]` asks *is the definition
right*; this asks *is it non-empty*. Neither subsumes the other, and this one is the
higher-severity finding.

### 5. A real TCB ledger

`axioms` is collected per declaration, but the trust page treats axioms as one uniform list. The
distinctions that matter, and the things `sorry` + axioms genuinely do not catch:

- `native_decide` → `Lean.ofReduceBool` / `ofReduceNat`, which trusts the **compiler**, not the
  kernel. Categorically larger than `Classical.choice`, and should never appear in the same list
  with it.
- `@[implemented_by]`, `@[extern]`, `unsafe`, `partial` — none are handled anywhere in
  [Referee/Collect.lean](Referee/Collect.lean) today. Each is a place where what runs is not what
  the kernel checked.
- `opaque` — asserts inhabitation without exhibiting it; the kind is already recorded, it is just
  not called out as a trust event.

One page, ordered by what each costs: kernel and the three standard axioms at the cheap end,
native_decide / in-project axioms / sorries / unaudited packages at the expensive end. Small work;
the axiom data exists and mostly needs classifying.

### 6. Statement unfolding — "what does this actually say?"

P4 names layer 2 as where *does this say what I think it says* is decided, and today the reader
chases definitions across pages to settle it. Precompute per theorem: the statement with project
definitions delta-unfolded one level, two levels, fully — and a `pp.notation false` view, which
catches custom notation hiding a nonstandard definition. Stepping through one unfold is very often
enough to see whether a definition is the intended one.

Storage is the risk, and §7 of [WEBSITE-DESIGN.md](WEBSITE-DESIGN.md) already taught that lesson:
store the *text* per level, highlight on demand.

### 7. Triviality check

Run `simp` / `exact?` / `decide` against each declaration on the Claims page. A headline claim that
`simp` closes alone is a finding worth surfacing. The per-declaration Lean fan-out (`--jobs`)
already exists, and this is far cheaper than `highlight-extracted`. The evidence is asymmetric, so
the page must say so: a hit is informative, a miss means nothing.

### 8. Path queries

Already scoped as unfinished in P8. Worth finishing because "why does A depend on B" is the one
graph question asked in words that no picture of a closure answers.

## Tier C — interop

### 9. Blueprint import

`leanblueprint` (`\lean{}`, `\leanok`, `\uses{}`) is how most large formalization projects record
intent, and it is the natural join: blueprint has the informal claims, Referee has the reality. It
yields which blueprint nodes have no Lean counterpart, and — the lie detector — which are marked
`\leanok` while pointing at a declaration whose closure contains a `sorry`.

### 10. Git provenance per declaration

When each *statement* last changed, and in which commit. That is what tells a referee "this was
edited after I read it", and it upgrades (1) from "diff two saved JSON files" to "diff against any
ref".

## Rejected

- **Mathlib-overlap detection** ("does this project restate something upstream already has"). A
  prospective-user question, not a referee one, and it fights the stated non-goals.

## If three get built

The diff (1), blast radius (2), and inhabitation (4). The first two are nearly free given the data
already computed; the third is the highest-severity finding class the site is currently blind to.
