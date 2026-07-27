# Known issues in `extract`

Status of the standalone `.lean` files written by `exposition extract`, as measured by
`scripts/check-extracted-compile.sh`. Every number below comes from running that script over a
whole corpus; none of it is estimated.

## Current state

| target project | compiling | failing |
|---|---|---|
| brownian-motion | 1673 / 1677 | 4 |
| LML (`LeanMachineLearning`) | 696 / 698 | 2 |
| alpha-rar | 779 / 784 | 5 |
| **total** | **3148 / 3159 (99.65%)** | **11** |

Reproduce with, per project:

```bash
EXPOSITION=/path/to/lml-exposition/.lake/build/bin/exposition
lake env "$EXPOSITION" collect --root <Root> --data data.json     # add --exclude-lib for unbuilt libs
lake env "$EXPOSITION" extract --data data.json --output out      # same --exclude-lib as collect
/path/to/lml-exposition/scripts/check-extracted-compile.sh . out/html-multi/extracted
```

## Open issues

### 1. Private declarations are unreachable (5 files, alpha-rar)

**Symptom** `Unknown identifier 'core'` / `'tendstoVal'`.

**Cause** `AlphaRAR/Mathlib/Tactic/Tendsto.lean` declares `private partial def core` and
`private def tendstoVal`, used by the exposed tactic elaborator. Private names are
`_private.Module.0.Foo.bar`, whose first component starts with `_`, so `isInternalName` rejects
them in `shouldExpose`. They are therefore not merely outside a target's closure — they can never
enter one, and nothing emits them.

**Fix direction** Extraction needs a notion of "emit but do not display": a private project
declaration reachable from a kept declaration should be written into the standalone file while
staying off the site. That means separating the *exposure* predicate (what the site shows) from
the *emission* predicate (what a standalone file needs), which today are the same thing.

### 2. Tactic bodies name lemmas the elaborated term does not (2 files, LML)

**Symptom** `Unknown constant 'MeasureTheory.FiniteMeasure.toMeasure_sub'`.

**Cause** Dependency analysis is **term-level** (`Expr.getUsedConstants` over type and value), but a
kept tactic body is emitted as **source text**. `simp only [FiniteMeasure.toMeasure_sub]` names a
lemma that the elaborated proof term never references as a constant, so it is absent from `deps`
and `transDeps` and never emitted — even though it *is* an exposed project declaration.

**Fix direction** A syntactic closure over kept tactic bodies, exactly parallel to the existing
`usedNotations` handling in `writeAllExtractions` (which exists for this same reason: a notation
use is invisible to the term-level analysis). Collect the identifiers in a body we keep, resolve
them against exposed declarations, and add the matches to `keep`. Bounded risk, since the closure
only grows.

### 3. Tactic bodies that cannot run in a minimal file (2 files, brownian-motion)

**Symptom** ``Tactic `apply` failed: could not unify the conclusion of `@indistinguishable_of_…` ``.

**Cause** `where`-field proof bodies are now kept verbatim (see *Signature narrowing* below), and a
kept tactic has to actually elaborate. The minimal file deliberately does not replay `@[simp]` /
`@[measurability]` / `@[fun_prop]` registrations, and inlines only the declarations in the closure,
so a tactic that relied on the ambient environment can fail.

**Fix direction** No clean one. This is the standing cost of emitting tactic proofs rather than
`sorry`. Anything that makes more tactics run (replaying proof-elaboration attributes, widening the
closure) trades these failures against the much larger set documented under *Rejected: replaying all
`attribute` commands*.

### 4. `@[to_additive existing]` without its counterpart (2 files, brownian-motion)

**Symptom** ``@[to_additive] failed to add declaration `MeasureTheory.AEEqProcess.instAddGroup…` ``.

**Cause** `@[to_additive existing] instance instGroup` asserts that `instAddGroup` already exists —
it is declared as a *separate command* eight lines earlier in the same file. When that declaration
is outside the closure, `to_additive` stops linking and starts generating, and the generation then
fails on `pow_toGerm`, which is `@[simp]`-only and so has no registered additive counterpart.

Note this is **not** a gap in the same-command sibling closure (`commandSiblings`): those two
declarations come from different commands.

**Fix direction** Put the counterpart in the closure. That needs the name, i.e. `to_additive`'s
translation table, which is not reachable — the tool does not depend on Mathlib. A hand-rolled
`Group → AddGroup` name dictionary would work for the common algebraic classes but is fragile.
Do **not** try removing the attribute; see below.

## Rejected approaches

Each of these was implemented and measured. They are recorded so they are not retried.

### Stripping `@[to_additive existing]` — 5 → 339 failures

It looks inert: it links to a counterpart declared elsewhere rather than generating one. It is not.
The link it registers is what lets *later* plain `@[to_additive]` commands translate a type
mentioning the multiplicative declaration. Dropping it broke every downstream translation that
needed to map `Monoid γ` to `AddMonoid γ`. See `isDroppedAttribute`.

### Stripping `@[ext]` unconditionally

Correct for the theorem form (it only registers the lemma and proves an `_iff` converse whose proof
needs a `@[refl]` lemma outside the closure). Wrong for `structure`/`class`, where `@[ext]` is what
*defines* `Foo.ext` and `Foo.ext_iff`. Now guarded by `onStructure`; blast radius fell from 505
files to 7.

### Replaying all standalone `attribute` commands — 2 → 1623 failures

`attribute [measurability] measurableSet_setBot …` targets project declarations that most closures
do not contain, and pruning that checks only *exposed* declarations misses non-exposed ones. Only
`translationAttributes` (`to_additive`, `to_dual`) are replayed now, with a target test that
rejects any project-local constant outside `keep`. Proof-elaboration attributes are moot anyway in
a file whose proofs are `sorry`.

### Never sorrying a definition's tactic blocks ("generalized D")

| corpus | before | after |
|---|---|---|
| brownian-motion | 2 | **71** |
| LML | 0 | 2 |
| alpha-rar | 15 | 5 |

Rejected. 54 of the new brownian-motion failures are issue 3 above — proofs embedded in a larger
term generally cannot run in the minimal file. What is kept instead is only a block that *is* a
value (a direct child of `declValSimple` or `structInstFieldDef`); see `wholeValueTacticRanges`.
That variant is a net win (17 → 11 failures overall) but not free: it fixed 10 files in alpha-rar
and broke 4 elsewhere (2 under issue 2, 2 under issue 3).

## Background: signature narrowing

Worth understanding before touching the `sorry` logic, because it is unintuitive.

For a **definition**, Lean includes a section `variable` only when the value *mentions* it. A
`sorry` mentions nothing, so replacing a definition's value silently drops binders and changes its
signature:

```lean
variable {α β : Type*} [LinearOrder α] [TopologicalSpace β]

noncomputable def leftLimWithin (f : α → β) (s : Set α) (a : α) : β := by classical …
-- real body : {α β} → [LinearOrder α] → [TopologicalSpace β] → (α → β) → Set α → α → β
-- with sorry: {α β} →                                          (α → β) → Set α → α → β
```

Every use site passing those instances positionally (`@leftLimWithin αᵒᵈ β _ _ f s a`) then fails.
The same happens per field in `def ofSeq : MartDiffArray P where … mgdiff n i := by …`, which
dropped its `hmgdiff` binder.

**Theorems are not affected** — Lean's inclusion rule for a theorem does not consult its proof
term, which is why sorrying proofs (the bulk of what extraction does) is safe. Verified directly:
`thmSorry` and `thmBody` both keep `[LinearOrder α]`.

## Unrelated usability wart

`--exclude-lib` must be passed to **both** `collect` and `extract`. `collect` records `rootPrefix`
in `data.json`, but `extract` re-imports the project and re-derives the import roots from the
lakefile, so omitting the flag fails with `LMLTutorial.olean does not exist` even though the JSON
it was handed never mentions that library. Persisting the exclusion list (or the resolved import
set) in `CollectedData` would remove this.
