module

public import JunkValues.Extra.Entry

@[expose] public section

/-!
# Arithmetic junk values: division by zero, truncated subtraction, and collapsing coercions

**Optional, and separate from `Extra/Catalogue.lean` on purpose.** The rules here are the highest
volume in the package by a wide margin, because their patterns are `?a / ?b` and `?a - ?b` rather
than `∫ ?f ∂?μ` — they ask a question about *every division and every subtraction in the project*,
not about the handful of integrals.

That is exactly what makes them worth having. `x / y` is the junk value a reader is least likely to
think about, because nothing in the notation suggests a domain condition at all, and `y = 0` is a
case that a proof will often never mention. It is also why they are their own import: a project
should be able to take the analytic catalogue without taking a finding on every arithmetic
expression it contains.

## The three kinds here

**Division and inversion** state their condition by specialising an argument (`a / 0 = 0`), so they
need the second rule form — `generalizing`, see `Rule.lean`. Position 2 of `div_zero` turns the
pattern `?a / 0` into `?a / ?b` with the guard `?b = 0`, which is the difference between matching a
literal division by zero, which a reader can already see, and asking whether *this* divisor is zero,
which is the real question.

**Truncated subtraction** needs none of that: `tsub_eq_zero_of_le : a ≤ b → a - b = 0` is already
conditional. Worth noting that `Extra/Discovery.lean` does *not* find it, because its guard `a ≤ b`
is not a negation — the same blind spot that costs it `Real.sqrt_eq_zero_of_nonpos`, and one more
reason a catalogue is written by hand.

**Collapsing coercions** — `(⊤ : ℝ≥0∞).toReal = 0` — are the ones that matter most in a probability
development and are the least visible of the three. An infinite measure, an infinite divergence or
an unbounded moment silently becomes the real number `0`, which is a value the quantity genuinely
takes elsewhere. There is no syntactic trace of the collapse at the use site at all.

## Living with the noise

Every rule here fires often, so the discharger is doing more work than anywhere else in the package,
and hypothesis lookup alone will not be enough. A divisor that is a nonzero literal (`x / 2`) needs
arithmetic to dismiss, which means a discharger that can do arithmetic:

```lean
set_option linter.junkValues.discharger "norm_num ;; positivity ;; fun_prop"
```

The alternatives are separated by `;;` and each has to close the goal on its own. Writing them as a
single `first | norm_num | fun_prop` instead is a trap, and `Frontend.lean` documents why: `first`
commits to `norm_num`, which makes progress on an `Integrable` goal without closing it, and
`fun_prop` never runs.

Verified against Mathlib `9cebae57f41` (2026-07-26), toolchain `v4.33.0-rc1`.
-/

open Lean

namespace JunkValues

/-- Junk values of ordinary arithmetic: division, inversion, truncated subtraction, and the
coercions out of `ℝ≥0∞` and `EReal`.

Kept apart from `mathlibCatalogue` because of volume, not because of importance — see the module
docstring. -/
def arithmeticCatalogue : Array CatalogueEntry := #[
  -- Division. The condition is stated by specialising the divisor, so every entry generalizes
  -- position 2 to ask about the divisor actually in front of it.
  { theoremName := `div_zero, generalize := #[2],
    note := "division by zero is 0, not undefined — so `a / b = 0` carries no information about \
      `a` unless `b ≠ 0` is known" },
  { theoremName := `Nat.div_zero, generalize := #[2],
    note := "natural division by zero is 0 (and natural division truncates besides)" },
  { theoremName := `Int.ediv_zero, generalize := #[2],
    note := "integer division by zero is 0" },
  { theoremName := `EReal.div_zero, generalize := #[2],
    note := "division by zero in `EReal` is 0" },
  { theoremName := `ENNReal.div_zero, generalize := #[2],
    note := "division of a nonzero extended non-negative real by zero is ⊤, unlike every other \
      division-by-zero convention here" },
  { theoremName := `inv_zero, generalize := #[1],
    note := "the inverse of zero is zero, so `x⁻¹ = 0` does not mean `x` is large" },

  -- Truncated subtraction. Already conditional, so no generalization — and not something discovery
  -- finds, because `a ≤ b` is not a negation.
  { theoremName := `tsub_eq_zero_of_le,
    note := "truncated subtraction clamps at 0, so `a - b = 0` means `a ≤ b` rather than `a = b`" },

  -- Coercions out of the extended reals. The least visible junk values in the package: nothing at
  -- the use site suggests that a value was infinite.
  { theoremName := `ENNReal.toReal_top, generalize := #[1],
    note := "`(⊤ : ℝ≥0∞).toReal = 0`, so an infinite measure, moment or divergence silently becomes \
      the real number 0" },
  { theoremName := `ENNReal.toNNReal_top, generalize := #[1],
    note := "`(⊤ : ℝ≥0∞).toNNReal = 0`, the same collapse into `ℝ≥0`" },
  { theoremName := `EReal.toReal_top, generalize := #[1],
    note := "`(⊤ : EReal).toReal = 0`" },
  { theoremName := `EReal.toReal_bot, generalize := #[1],
    note := "`(⊥ : EReal).toReal = 0`, so both infinities coerce to the same real number" },

  -- Elementary functions whose junk value is a genuine value of the function elsewhere.
  --
  -- `Real.log_zero` is here and `Real.log_one` is deliberately not, although the two have identical
  -- shape (`Real.log c = 0` for a literal `c`) and either would be accepted by `generalizing 1`.
  -- `log 0 = 0` is a convention standing in for `-∞`; `log 1 = 0` is a theorem. Nothing about the
  -- statements distinguishes them, which is the argument in `Rule.lean` for why generalization
  -- positions are written down rather than inferred, in its sharpest form.
  { theoremName := `Real.log_zero, generalize := #[1],
    note := "`Real.log 0 = 0` by convention, which is also the value of `log` at 1" },

  -- Degree of the zero polynomial. Included because the collapse is to `⊥` rather than to a number,
  -- which makes it the one entry here a reader is likely to notice — and a useful contrast.
  { theoremName := `Polynomial.degree_zero, generalize := #[1],
    note := "the zero polynomial has degree ⊥ rather than a natural number, so a `degree` \
      comparison can hold for a reason unrelated to the polynomial's shape" }]

/-- The arithmetic catalogue as a rule source. Importing this module is what switches it on, and —
because the entry type lives in `Extra/Entry.lean` rather than beside another catalogue — importing
it switches on *only* this one; see `RuleSet.lean` and `Extra/Entry.lean`. -/
initialize registerRuleProvider (catalogueProvider "arithmetic" arithmeticCatalogue)

end JunkValues
