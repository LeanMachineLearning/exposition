# JunkValues

Where a definition silently means something else.

Lean has no partial functions, so every operation with a domain condition needs a value outside it.
`∫ x, f x ∂μ` is `0` when `f` is not integrable; `deriv f x` is `0` where `f` is not differentiable;
`∑' i, f i` is `0` when the family is not summable. The convention is necessary and almost always
harmless — until a definition is built on one:

```lean
noncomputable def B (f g : α → ℝ) (μ : Measure α) : ℝ := ∫ x, (f x + g x) ∂μ
```

`B` does not mean what it says. Wherever `f + g` is not integrable it means `0`, and every theorem
about `B` inherits that. Nothing in Lean warns about this, because nothing is *wrong*: the
definition elaborates, the proofs go through, and the statements are true.

```
warning: junk value in the definition of `B`:
  if ¬Integrable (fun a => f a + g a) μ then ∫ (x : α), f x + g x ∂μ = 0
  (by MeasureTheory.integral_undef)
  — a Bochner integral of a non-integrable function is 0, so an equation between two of them
    can hold vacuously
```

Depends on Lean core and nothing else — no Lake, no document format, and **no Mathlib**, though
Mathlib is where nearly every rule ships from. It lives in the
[`exposition`](https://github.com/LeanMachineLearning/exposition) repository, whose `referee` tool is
a consumer, but it is a separate Lake package precisely so that a project can lint its own
definitions without taking on that tool's build.

## What the package is

Two things:

1. **`@[junk_value]`** — the annotation that records that one of your definitions has a junk value,
   and the condition that produces it.
2. **the linter** — which reports, on every declaration you write, the junk values it uses that
   nothing in scope rules out.

Everything else serves those two. [`JunkValues/Extra/`](JunkValues/Extra/) is not part of them: it
answers the separate question of what to do about junk values in libraries you do not own and
cannot annotate, and it is opt-in by import. A project that annotates its own definitions never
needs it.

## The idea: rules are theorems

The obvious way to know that an integral collapses to `0` is a hand-maintained table of constants
and conditions. This library does not do that, because such a table is unchecked — nothing stops it
from claiming a default the definition does not have, or from going stale when the definition
changes.

Instead a rule **is** a theorem, and it is one that already exists:

```lean
theorem MeasureTheory.integral_undef {f : α → G} (h : ¬Integrable f μ) : ∫ a, f a ∂μ = 0
theorem deriv_zero_of_not_differentiableAt (h : ¬DifferentiableAt 𝕜 f x) : deriv f x = 0
theorem tsum_eq_zero_of_not_summable (h : ¬Summable f) : ∑' i, f i = 0
```

Each has the shape `∀ xs, g₁ → … → gₙ → lhs = rhs`, which is exactly a junk-value rule: `lhs` is the
pattern to look for, the `gᵢ` say when the value collapses, `rhs` is what it collapses to. Every
part has been checked by the kernel. **The tool cannot claim a default value that is not real**; the
worst it can do is fail to know about one.

That is also why the annotation goes on a **theorem** rather than on the definition: annotating the
definition would be an unchecked assertion, while annotating the theorem that proves the collapse is
not. The shape is checked where the attribute is written, so a theorem that cannot be a rule is an
error somebody can fix rather than a rule that silently never fires.

```lean
@[junk_value "a divergence between measures with no density is reported as infinite"]
theorem klDiv_of_not_integrable (h : ¬Integrable (llr μ ν) μ) : klDiv μ ν = ∞ := …
```

### Rules you did not write

The same reading applies to a theorem nobody annotated, which is what
[`JunkValues/Extra/`](JunkValues/Extra/) is for — and it is **optional**, reaching a scan through a
provider registry rather than through anything core knows about:

| | |
|---|---|
| [`Extra/Catalogue.lean`](JunkValues/Extra/Catalogue.lean) | Mathlib's analytic junk values — integrals, conditional expectations, derivatives, sums. Named by hand, verified against a stated revision. |
| [`Extra/Arithmetic.lean`](JunkValues/Extra/Arithmetic.lean) | Division by zero, truncated subtraction, and the coercions that collapse `⊤` to `0`. |
| [`Extra/Discovery.lean`](JunkValues/Extra/Discovery.lean) | Anything with the shape, found automatically. A catalogue-building aid, not a rule source. |

**A rule source is switched on by importing it.** `import JunkValues` gives the attribute and the
linter over your own rules; `import JunkValues.Extra` adds Mathlib's. Nothing has to be passed
through configuration, because the import already said it — and it fails in the readable direction:
forget the import and you get fewer rules, never wrong ones. `#junk_rules` says which source
contributed what, so a missing import is visible rather than silent.

Discovery additionally needs `set_option linter.junkValues.discovery true`, because over all of
Mathlib it proposes **1417** candidates against a catalogue of 22. It independently finds every
catalogued entry but one, so it is not missing the target — it is that no syntactic criterion
separates a junk value from a genuine default. `{a} ∩ s = ∅` when `a ∉ s` has exactly the same shape
as `∫ f = 0` when `f` is not integrable, and the difference — that `∅` is the right answer and `0`
is not — is a fact about the intent behind a definition. Run discovery to *find* candidates, read
them, and promote the real ones with `@[junk_value]`.

### When the condition hides in the left-hand side

Some of the most important junk values are not stated conditionally at all:

```lean
theorem div_zero (a : α) : a / 0 = 0
theorem ENNReal.toReal_top : (⊤ : ℝ≥0∞).toReal = 0
```

Read naively the pattern `?a / 0` matches only a literal division by zero — the one case a reader can
already see. So a rule may nominate explicit argument positions to **generalize**, turning `?a / 0`
into `?a / ?b` with the guard `?b = 0`:

```lean
@[junk_value generalizing 2 "division by zero is 0, not undefined"]
theorem div_zero (a : α) : a / 0 = 0
```

This costs no extra trust: if `?b = 0` then `?a / ?b` and `?a / 0` are the same term by congruence,
so the generalized rule is a *consequence* of the annotated theorem rather than a claim beside it.
Positions are 1-based over the explicit arguments, and they have to be written rather than detected —
`Real.log_zero : log 0 = 0` is a junk value and `Real.log_one : log 1 = 0` is ordinary mathematics,
and nothing about their shapes tells them apart.

Truncated subtraction needs none of this: `tsub_eq_zero_of_le : a ≤ b → a - b = 0` is already
conditional. Both live in [`Extra/Arithmetic.lean`](JunkValues/Extra/Arithmetic.lean), which is a
separate import because its patterns are `?a / ?b` and `?a - ?b` — it asks about *every* division and
subtraction in the project, which is the point of it and also the reason not to switch it on by
accident:

```
if b = 0 then a / b = 0                    (by div_zero)
if m ≤ n then m - n = 0                    (by tsub_eq_zero_of_le)
if x = ⊤ then x.toReal = 0                 (by ENNReal.toReal_top)
```

## The thing it lives or dies on

Finding occurrences is easy. **Dismissing them is what makes the tool usable**: reporting every
integral in a measure theory development reports nothing.

Almost every occurrence is fine, and fine for a reason that is one lemma away rather than literally
present — a theorem assuming `Integrable f μ` and `Integrable g μ` and integrating `f + g` needs
`Integrable.add` before anything can tell it is safe. So each occurrence's condition is instantiated
where it was found, in the real local context with the declaration's own hypotheses in scope, and
handed to a *discharger*.

Mathlib's `fun_prop` is exactly the tactic for this class of goal. It is named as a **string**
(`set_option linter.junkValues.discharger "fun_prop"`) rather than depended on, so that the tactic
resolves if and only if the project being scanned imports it. On the example above, that is the
difference between two findings and none:

```lean
-- reported: nothing says `f + g` is integrable
noncomputable def B (f g : α → ℝ) (μ : Measure α) : ℝ := ∫ x, (f x + g x) ∂μ

-- silent: `fun_prop` derives `Integrable (f + g) μ` from the two hypotheses
noncomputable def C (f g : α → ℝ) (μ : Measure α) (hf : Integrable f μ) (hg : Integrable g μ) : ℝ :=
  ∫ x, (f x + g x) ∂μ
```

Without a tactic discharger the tool falls back to hypothesis lookup and **over-reports**. That is
the honest direction to fail in, but it is a real cost.

## What it reports, and what it refuses to

| | |
|---|---|
| `guarded` | the condition was ruled out. Not a finding; kept as evidence the scan looked. |
| `unguarded` | nothing in scope rules the collapse out. **This is the finding.** |
| `triggered` | the condition was *proved*. The term provably is the default. Rare, and much stronger. |

A finding is evidence, never a verdict. Whether `f + g` is integrable is mathematics; a linter
claiming to have settled it would be lying most of the time. What the tool can honestly do is make
the list finite, ordered, and annotated with the exact condition each entry rests on.

Findings are split by **where** they were found, because the risk differs:

- in a **statement**, a junk value is a *vacuity* risk — the theorem may hold for no reason, both
  sides having collapsed;
- in a **body**, it is a *meaning* risk — the definition denotes something other than its name says,
  and everything downstream inherits it. `inheritRisk` is that inheritance.

Note also that the default is not always `0`, and not always bad: `klDiv` collapses to `⊤`, which is
the conservative direction. The tool reports the value and the rule's note, and lets the reader
judge.

## Use

```toml
# lakefile.toml
[[require]]
name = "JunkValues"
git = "https://github.com/LeanMachineLearning/exposition"
rev = "main"
subDir = "JunkValues"
```

```lean
-- lakefile.lean
require JunkValues from git
  "https://github.com/LeanMachineLearning/exposition" @ "main" / "JunkValues"
```

### Annotating, and the linter

The two halves of the core, in the order you meet them:

```lean
import JunkValues            -- your own annotated rules
import JunkValues.Extra      -- optional: Mathlib's junk values too

set_option linter.junkValues true
set_option linter.junkValues.discharger "fun_prop"

/-- Your own definition with a junk value, and the theorem that proves it. -/
@[junk_value "the estimator is 0 on samples with no variance, which is also its value at the mean"]
theorem myEstimator_of_not_ok (h : ¬ Ok s) : myEstimator s = 0 := …
```

The linter is off by default. Turning it on for an existing development produces a wall of
true-but-unactioned findings, so it is meant to be switched on per file, or per project once the
backlog is dealt with.

### On demand

```lean
#junk_check MyProject.entropy      -- one declaration
#junk_check MyProject.Chapter3     -- everything in a namespace
#junk_rules                        -- what the scan would run with, and what failed to assemble
```

`#junk_rules` is the command to run when a scan reports less than expected: catalogue entries that
no longer resolve are listed there rather than silently dropped.

### On a compiled project, from outside

```lean
open Lean JunkValues

def report (rootPrefix : Name) : MetaM Unit := do
  let (rules, scans, failed) ← scanProject rootPrefix
  for w in rules.warnings do IO.println s!"warning: {w}"
  for scan in scans do
    for f in scan.findings do IO.println s!"{f.decl}: {f.message}"
  for (name, why) in failed do IO.println s!"could not scan {name}: {why}"
```

Reading annotations back out of a compiled project needs this library linked into the reading
process and `importModules (loadExts := true)` — the same requirement, for the same reason, as
[`Characterization`](https://github.com/RemyDegenne/characterization).

## Tests

`lake build Test` runs the unit tests, which use a synthetic junk value and need no Mathlib.

The claims this package makes about integrals, division and truncated subtraction are claims about
*Mathlib's* definitions, so they are checked separately, against a real one:

```bash
scripts/run-integration-tests.sh /path/to/a/mathlib/project
```

Those tests are written as ordinary-looking probability code — a variance, a normalised integral, a
truncated subtraction — because every bug they have caught was invisible on a synthetic example and
obvious on real mathematics. Two of them are worth naming, since both were shipped and both were
found this way: subtraction in `ℝ` and `ℤ` was reported as truncating (the `OrderedSub` instance a
rule needs is not in the term, and failing to synthesize it was not treated as "the rule does not
apply"), and a junk value inside a *recursive* definition was found not at all (the body lives in
compiler-generated helpers, not in the declaration's own value).

## Limits

- **Arithmetic rules need an arithmetic discharger.** `x / 2` is reported unless something can prove
  `(2 : ℝ) ≠ 0`, which hypothesis lookup cannot. Set the discharger to a tactic that can:
  `set_option linter.junkValues.discharger "norm_num ;; fun_prop"`. The alternatives are separated
  by `;;` and each must close the goal on its own — writing them as one `first | norm_num | fun_prop`
  silently loses `fun_prop`, because `first` commits to `norm_num`, which makes progress on an
  `Integrable` goal without closing it.
- **Proof bodies are not scanned by default.** A junk value mid-proof is usually a step the proof
  goes on to justify, and elaborated proof terms are enormous.
- **The linter reads declaration names off the syntax tree**, plus anything nested under a name the
  command declared — so a `where` clause's auxiliary *is* linted, but an **anonymous `instance`**,
  which has no `declId` at all, is not. `#junk_check` and the batch scan both cover those.
- **Findings inside a recursive definition name inaccessible variables.** The body lives in
  compiler-generated helpers, so the guard reads `x✝.1 ≤ 1` rather than naming the author's binder.
  The finding is attributed to the right declaration and says the right thing; it just reads
  worse.
- **Over-reporting without a tactic discharger**, as above.
