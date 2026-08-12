/-
Integration tests for `JunkValues`, against a real Mathlib.

These cannot be a Lake target of this package, because the package deliberately does not depend on
Mathlib — which is the whole point of it, and also the reason these tests exist: everything the
package claims about integrals, division and truncated subtraction is a claim about *Mathlib's*
definitions, and only a run against Mathlib can check it.

    scripts/run-integration-tests.sh MATHLIB_PROJECT_DIR

Every check below throws on failure, so the file either elaborates clean or the run fails. Nothing
here prints results for a human to eyeball: a test whose failure mode is "somebody notices the
output looks wrong" is not a test.

The declarations are written the way the code they are about is written — a variance, a normalised
integral, a Radon–Nikodym-ish ratio — because every bug this file has caught was invisible on a
synthetic example and obvious on ordinary-looking mathematics.
-/
import Mathlib
import JunkValues
import JunkValues.Extra

open Lean Meta MeasureTheory JunkValues
open scoped ENNReal

namespace JunkValues.RealLifeTest

/-! ## The code under test

Written as a normal development would write it. What each declaration is *supposed* to produce is
asserted further down, never here, so that reading this section is reading Lean rather than reading
a test fixture. -/

variable {Ω : Type*} [MeasurableSpace Ω] {μ : Measure Ω}

/-! ### Should be reported -/

/-- A variance written without any integrability hypothesis: both the outer integral and the inner
mean can collapse. -/
noncomputable def variance' (X : Ω → ℝ) (μ : Measure Ω) : ℝ :=
  ∫ ω, (X ω - ∫ y, X y ∂μ) ^ 2 ∂μ

/-- Normalising by a measure that may be zero *or* infinite: three separate collapses in one line. -/
noncomputable def normalise (X : Ω → ℝ) (μ : Measure Ω) : ℝ :=
  (∫ ω, X ω ∂μ) / (μ Set.univ).toReal

/-- Truncated subtraction on `ℕ`, which really does clamp. -/
def natGap (m n : ℕ) : ℕ := m - n

/-- Truncated subtraction on `ℝ≥0∞`, which also clamps. -/
noncomputable def ennGap (a b : ℝ≥0∞) : ℝ≥0∞ := a - b

/-- The author's code lives in the `where` auxiliary, which has no `declId` of its own. -/
noncomputable def viaWhere (f : Ω → ℝ) (μ : Measure Ω) : ℝ := aux f
  where aux (g : Ω → ℝ) : ℝ := ∫ ω, g ω ∂μ

/-- A recursive definition: the body ends up in compiler-generated helpers. -/
def countdown : ℕ → ℕ
  | 0 => 0
  | n + 1 => countdown n - 1

/-- The junk value is behind a `let`. -/
noncomputable def viaLet (f g : Ω → ℝ) (μ : Measure Ω) : ℝ :=
  let h := fun ω => f ω + g ω
  ∫ ω, h ω ∂μ

/-- The junk value is inside a `match` arm. -/
noncomputable def viaMatch (o : Option (Ω → ℝ)) (μ : Measure Ω) : ℝ :=
  match o with
  | none => 0
  | some f => ∫ ω, f ω ∂μ

/-- Over-application: `fderiv ℝ f x` is applied to a vector, so the junk value is at an inner node
of the application rather than at its head. -/
noncomputable def dirDeriv (f : ℝ → ℝ) (x v : ℝ) : ℝ := fderiv ℝ f x v

/-- A statement, not a definition: this equation can hold because both sides collapsed. -/
theorem vacuous (f g : Ω → ℝ) (μ : Measure Ω) :
    ∫ x, (f x + g x) ∂μ = ∫ x, (g x + f x) ∂μ := by simp [add_comm]

/-! ### Should NOT be reported

Ordinary correct code. Every one of these was a false positive at some point. -/

/-- Integer subtraction does not truncate: `ℤ` has no `OrderedSub`. -/
def intGap (m n : ℤ) : ℤ := m - n

/-- Neither does real subtraction. -/
noncomputable def realGap (x y : ℝ) : ℝ := x - y

/-- Division by a nonzero literal. -/
noncomputable def half (x : ℝ) : ℝ := x / 2

/-- Integrability is in scope, and `fun_prop` can see it. -/
noncomputable def meanOf (X : Ω → ℝ) (μ : Measure Ω) (_hX : Integrable X μ) : ℝ := ∫ ω, X ω ∂μ

/-- `fun_prop` has to combine two hypotheses through `Integrable.add` to clear this one, which is
the case the whole discharger design exists for. -/
noncomputable def sumOf (f g : Ω → ℝ) (μ : Measure Ω)
    (_hf : Integrable f μ) (_hg : Integrable g μ) : ℝ := ∫ ω, (f ω + g ω) ∂μ

/-- The divisor is known to be nonzero. -/
noncomputable def ratio (a b : ℝ) (_hb : b ≠ 0) : ℝ := a / b

/-- The same statement as `vacuous`, but with the integrability it needs. -/
theorem notVacuous (f g : Ω → ℝ) (μ : Measure Ω) (_hf : Integrable f μ) (_hg : Integrable g μ) :
    ∫ x, (f x + g x) ∂μ = ∫ x, (g x + f x) ∂μ := by simp [add_comm]

/-! ## The assertions -/

/-- Scan one declaration with the full rule set and a discharger strong enough for real code. -/
def scanOne (name : Name) : MetaM (Array Finding) := do
  let report ← RuleSet.ofEnv
  unless report.problems.isEmpty do
    throwError "the rule set did not assemble cleanly:{indentD (toMessageData report.problems)}"
  let (discharger, problems) ← dischargerOf "fun_prop ;; norm_num ;; positivity"
  unless problems.isEmpty do
    throwError "the discharger did not parse:{indentD (toMessageData problems)}"
  return (← scanDecl report.ruleSet { guard := { discharger } } name).findings

/-- Assert that `name` produces findings from exactly `expected` rules, as a set. Naming the rules
rather than counting them is what makes a failure legible: "expected `div_zero`, got
`ENNReal.toReal_top`" says what changed, and `2 ≠ 3` does not. -/
def expectRules (name : Name) (expected : Array Name) : MetaM Unit := do
  let findings ← scanOne name
  let got := findings.map (·.rule)
  for rule in expected do
    unless got.contains rule do
      throwError "`{name}` should be reported by `{rule}`, but was reported by \
        {got.toList} only"
  for rule in got do
    unless expected.contains rule do
      throwError "`{name}` was reported by `{rule}`, which was not expected. Expected \
        {expected.toList}"

/-- Assert that `name` is clean. -/
def expectClean (name : Name) : MetaM Unit := do
  let findings ← scanOne name
  unless findings.isEmpty do
    throwError "`{name}` should not be reported, but is:\
      {indentD (toMessageData (findings.map (·.message)).toList)}"

run_meta do
  -- Both integrals collapse independently, so `variance'` rests on two of them.
  expectRules ``variance' #[``MeasureTheory.integral_undef]
  -- Three genuinely different risks in one expression: a zero divisor, a non-integrable numerator,
  -- and an infinite measure that coerces to the real number 0.
  expectRules ``normalise #[``MeasureTheory.integral_undef, ``div_zero, ``ENNReal.toReal_top]
  expectRules ``natGap #[``tsub_eq_zero_of_le]
  expectRules ``ennGap #[``tsub_eq_zero_of_le]
  expectRules ``viaWhere.aux #[``MeasureTheory.integral_undef]
  expectRules ``countdown #[``tsub_eq_zero_of_le]
  expectRules ``viaLet #[``MeasureTheory.integral_undef]
  expectRules ``viaMatch #[``MeasureTheory.integral_undef]
  expectRules ``dirDeriv #[``fderiv_zero_of_not_differentiableAt]
  expectRules ``vacuous #[``MeasureTheory.integral_undef]

  expectClean ``intGap
  expectClean ``realGap
  expectClean ``half
  expectClean ``meanOf
  expectClean ``sumOf
  expectClean ``ratio
  expectClean ``notVacuous

-- A finding has to carry the *instantiated* condition, not the rule's abstract one. That sentence is
-- the entire user-facing product, so it is pinned rather than merely counted.
run_meta do
  let findings ← scanOne ``normalise
  let some divFinding := findings.find? (·.rule == ``div_zero)
    | throwError "expected a `div_zero` finding on `normalise`"
  unless divFinding.guards == #["(μ Set.univ).toReal = 0"] do
    throwError "the guard should be instantiated at the actual divisor, got {divFinding.guards}"
  unless divFinding.value == "0" do
    throwError "the reported default should be `0`, got `{divFinding.value}`"
  unless divFinding.site matches .body do
    throwError "an occurrence in a definition's value is a `body` finding"

  -- `vacuous` is a theorem, so its occurrences are a *vacuity* risk and must be labelled as such.
  let findings ← scanOne ``vacuous
  unless findings.all (·.site matches .statement) do
    throwError "occurrences in a theorem's statement must be reported against the statement"

-- The guard has to mention the binders it actually sits under. An inner integral inside an outer one
-- refers to the outer bound variable, and getting this wrong is what a naive `Expr` fold does.
run_meta do
  let findings ← scanOne ``variance'
  unless findings.any (fun f => f.guards.any (fun g => (g.splitOn "∫").length > 1)) do
    throwError "the outer integral's guard should mention the inner integral, got \
      {(findings.map (·.guards)).toList}"

-- The catalogues still resolve against this Mathlib: the check that keeps "verified against Mathlib
-- `…`" from being a claim nobody re-runs.
run_meta do
  for (label, catalogue) in [("analytic", mathlibCatalogue), ("arithmetic", arithmeticCatalogue)] do
    let check ← checkCatalogue catalogue
    unless check.unresolved.isEmpty do
      throwError "the {label} catalogue names constants this Mathlib does not have: \
        {check.unresolved.toList}. They were renamed upstream, and the junk values they cover are \
        no longer being checked."
    unless check.rejected.isEmpty do
      throwError "the {label} catalogue names constants that are no longer junk-value rules: \
        {(check.rejected.map Prod.fst).toList}. Their statements changed shape upstream."
    unless check.rules.size == catalogue.size do
      throwError "the {label} catalogue resolved {check.rules.size} of {catalogue.size} entries"

-- No discharger may be believed when it has not actually closed the goal. A tactic that proves
-- anything, and one that succeeds while changing nothing, both have to leave the finding standing.
run_meta do
  for script in ["sorry", "skip"] do
    let report ← RuleSet.ofEnv
    let .ok tac ← tacticDischarger? script | throwError "`{script}` should parse"
    let findings := (← scanDecl report.ruleSet { guard := { discharger := tac } } ``natGap).findings
    unless findings.size == 1 do
      throwError "`{script}` must not dismiss a finding, but `natGap` came back clean"

end JunkValues.RealLifeTest
