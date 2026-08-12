module

public import JunkValues.Extra.Entry

@[expose] public section

/-!
# The catalogue: junk-value theorems Mathlib already proves

**Optional.** The core of this package is `@[junk_value]` and the linter; a project that annotates
its own definitions needs nothing here. This module exists for the case where the junk value is
upstream, because `@[junk_value]` cannot cover Mathlib — nobody is going to annotate it.

Importing this module is what switches the catalogue on. See `RuleSet.lean` for why that is the
registration mechanism rather than a configuration flag.

## What is in it

Only entries that were run against a real Mathlib and confirmed to have the rule shape, with the
head constant and guard they were expected to have. The verification is a script, not a promise: see
`checkCatalogue` (in `Extra/Entry.lean`), which re-runs it against the environment in hand.

A catalogue entry that stops resolving is *reported*, never silently skipped — see `Extra/Entry.lean`
for why that matters more than it sounds.

Verified against Mathlib `9cebae57f41` (2026-07-26), toolchain `v4.33.0-rc1`.

## Why the notes are worth writing

Because the finding a reader can act on says what the default *costs*, and that is not derivable
from the theorem. Two entries here make the point by disagreeing: an integral collapsing to `0` is a
silent falsehood, while `klDiv` collapsing to `⊤` is arguably the safe direction — the same
mechanism, opposite consequences. A tool that reported only "has a default" would flatten that
distinction; the note is where it survives.
-/

open Lean

namespace JunkValues

/-- Junk-value theorems from Mathlib, grouped by the mathematics they come from.

Ordered by how often the operation shows up in an analysis or probability development rather than
alphabetically, so that reading the list top to bottom is a tour of the ways a statement in that
area can quietly say nothing. -/
def mathlibCatalogue : Array CatalogueEntry := #[
  -- Integration. The canonical case, and the one that motivated this tool: an integral of a
  -- non-integrable function is `0`, so an equation between two such integrals can hold for no
  -- reason at all.
  { theoremName := `MeasureTheory.integral_undef,
    note := "a Bochner integral of a non-integrable function is 0, so an equation between two of \
      them can hold vacuously" },
  -- `MeasureTheory.integral_non_aestronglyMeasurable` is deliberately *not* here, and the reason
  -- generalizes. `Integrable f μ` is `AEStronglyMeasurable f μ ∧ HasFiniteIntegral f μ`, so its
  -- guard `¬AEStronglyMeasurable f μ` implies the guard of `integral_undef` above. A rule whose
  -- guard is implied by another rule's on the same pattern can never produce a finding the other
  -- does not: it fires on exactly a subset of the terms, and is discharged on a superset. Including
  -- it doubled every integral finding on the first real run, which is how this was noticed.
  --
  -- The general rule for adding entries: two rules for the same operation earn their place only if
  -- neither guard implies the other.
  { theoremName := `intervalIntegral.integral_undef,
    note := "an interval integral of a function that is not interval-integrable is 0" },
  { theoremName := `circleIntegral.integral_undef,
    note := "a circle integral of a function that is not circle-integrable is 0" },
  { theoremName := `MeasureTheory.setToFun_undef,
    note := "the set-to-function integral of a non-integrable function is 0" },

  -- Conditional expectation. Same collapse, and harder to notice, because the integrability
  -- condition is about the function being conditioned rather than about anything in view.
  { theoremName := `MeasureTheory.condExp_of_not_integrable,
    note := "a conditional expectation of a non-integrable function is the zero function, not an \
      undefined one" },
  { theoremName := `MeasureTheory.condExpL1_undef,
    note := "the L¹ conditional expectation of a non-integrable function is 0" },
  { theoremName := `ProbabilityTheory.condVar_of_not_integrable,
    note := "a conditional variance is 0 when the squared deviation is not integrable — the same \
      value as for an a.s. constant random variable" },

  -- Infinite sums and products. `∑'` is the one most likely to appear in a statement whose author
  -- never considered divergence.
  { theoremName := `tsum_eq_zero_of_not_summable,
    note := "an unconditional sum of a non-summable family is 0, which is also the sum of the zero \
      family" },
  { theoremName := `tprod_eq_one_of_not_multipliable,
    note := "an unconditional product of a non-multipliable family is 1" },

  -- Differentiation. `deriv f x = 0` is the junk value that most looks like a real answer: it is
  -- what a genuinely differentiable function with a critical point gives.
  { theoremName := `deriv_zero_of_not_differentiableAt,
    note := "the derivative of a function not differentiable at the point is 0, indistinguishable \
      from a genuine critical point" },
  { theoremName := `derivWithin_zero_of_not_differentiableWithinAt,
    note := "a derivative within a set is 0 where the function is not differentiable within it" },
  { theoremName := `fderiv_zero_of_not_differentiableAt,
    note := "the Fréchet derivative of a function not differentiable at the point is the zero map" },
  { theoremName := `fderivWithin_zero_of_not_differentiableWithinAt,
    note := "a Fréchet derivative within a set is the zero map where the function is not \
      differentiable within it" },
  { theoremName := `gradient_eq_zero_of_not_differentiableAt,
    note := "the gradient of a function not differentiable at the point is 0" },
  { theoremName := `logDeriv_eq_zero_of_not_differentiableAt,
    note := "the logarithmic derivative of a function not differentiable at the point is 0" },

  -- Moment generating functions. The guard is an integrability condition on an exponential, which
  -- fails for heavy-tailed laws — precisely the case a bound is usually being proved about.
  { theoremName := `ProbabilityTheory.mgf_undef,
    note := "the moment generating function is 0 where the exponential moment does not exist, and \
      0 is not a value any genuine mgf takes" },
  { theoremName := `ProbabilityTheory.cgf_undef,
    note := "the cumulant generating function is 0 where the exponential moment does not exist, \
      which is also its value at t = 0" },
  { theoremName := `ProbabilityTheory.complexMGF_undef,
    note := "the complex mgf is 0 where the exponential moment does not exist" },

  -- Measures and divergences built from them.
  { theoremName := `MeasureTheory.tilted_of_not_integrable,
    note := "an exponentially tilted measure is the zero measure when the tilt is not integrable, \
      so it is not a probability measure" },
  { theoremName := `MeasureTheory.Measure.comap_undef,
    note := "the comap of a measure along a map that is not injective-with-measurable-image is the \
      zero measure" },
  { theoremName := `InformationTheory.klDiv_of_not_integrable,
    note := "the KL divergence is ⊤ when the log-likelihood ratio is not integrable — unlike the \
      other entries here this default is the conservative direction, and a bound proved against it \
      may still be worth having" },

  -- Elementary functions whose junk value is a genuine value of the function elsewhere.
  { theoremName := `Real.sqrt_eq_zero_of_nonpos,
    note := "the square root of a non-positive real is 0, which is also √0" }]

/-- The analytic catalogue as a rule source. Importing this module is what switches it on; see
`RuleSet.lean`. -/
initialize registerRuleProvider (catalogueProvider "catalogue" mathlibCatalogue)

end JunkValues
