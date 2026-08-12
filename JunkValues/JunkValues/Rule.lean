module

public import Lean

@[expose] public section

/-!
# Rules: what a junk value is, read off a theorem that proves it

A *junk value* is what a total function returns outside the domain its name suggests. Lean has no
partial functions, so `∫ x, f x ∂μ` has to mean *something* when `f` is not integrable, and what it
means is `0`. The convention is unavoidable and mostly harmless — until a definition is built on
top of one, at which point `B := ∫ x, (f x + g x) ∂μ` silently means `0` on exactly the inputs
where the reader most wants to know what it means.

## The rules are theorems, not a table

The obvious way to record "`integral` returns `0` when the integrand is not integrable" is a table
of constant names and conditions maintained by hand. This library does not do that, because such a
table is unchecked: nothing stops it from claiming a default value that the definition does not
have, or from going stale when the definition changes.

Instead a rule *is* a theorem, and it is the theorem that already exists:

```lean
theorem MeasureTheory.integral_undef {f : α → G} (h : ¬Integrable f μ) : ∫ a, f a ∂μ = 0
theorem deriv_zero_of_not_differentiableAt (h : ¬DifferentiableAt 𝕜 f x) : deriv f x = 0
theorem tsum_eq_zero_of_not_summable (h : ¬Summable f) : ∑' i, f i = 0
```

Each has the shape `∀ xs, g₁ → … → gₙ → lhs = rhs`. That is *exactly* a junk-value rule: `lhs` is
the pattern to look for, the `gᵢ` say when the value collapses, and `rhs` is what it collapses to.
Every part of the rule is therefore something the kernel has checked. The library cannot claim a
default value that is not real; the worst it can do is fail to know about one.

It also means the rule set is not this library's to curate. `@[junk_value]` registers a theorem in
the project being analysed, `Catalogue.lean` names the ones Mathlib already proves, and
`Discovery.lean` finds the rest by their shape.

## The second form: when the condition hides in the left-hand side

Some of the most important junk values are not stated conditionally at all:

```lean
theorem div_zero (a : α) : a / 0 = 0
theorem ENNReal.toReal_top : (⊤ : ℝ≥0∞).toReal = 0
theorem inv_zero : (0 : α)⁻¹ = 0
```

There is no hypothesis here; the condition is encoded by *specialising* an argument. Read naively,
the pattern `?a / 0` matches only a literal division by zero, which is the one case a reader can
already see. What is wanted is to match **every** division and ask whether the divisor is zero.

So a rule may nominate explicit argument positions of its left-hand side to **generalize**. Position
2 of `div_zero` turns the pattern `?a / 0` into `?a / ?b` and adds the guard `?b = 0`:

```lean
@[junk_value generalizing 2 "division by zero is zero, not undefined"]
theorem div_zero (a : α) : a / 0 = 0
```

This is sound for free, and by exactly the same argument the whole design rests on. If `?b = 0` then
`?a / ?b` and `?a / 0` are the same term by congruence, and the theorem says that one equals `0`. No
new trust is introduced: the generalized rule is a consequence of the annotated theorem, not a
claim beside it.

Positions are **1-based over the explicit arguments** of the left-hand side, which is what a reader
counts. They have to be written down rather than detected, and the reason is visible in Mathlib:
`Real.log_zero : log 0 = 0` is a junk value and `Real.log_one : log 1 = 0` is ordinary mathematics,
and nothing about their shapes tells them apart. (`div_zero`'s literal `0` is not even a closed term
— it carries the type and `OfNat` instance as metavariables — so "generalize the closed arguments"
would not work either.)

`Nat.sub` truncating needs none of this: `tsub_eq_zero_of_le : a ≤ b → a - b = 0` is already the
conditional form. It is worth knowing that it is *not* found by `Extra/Discovery.lean`, because its
guard `a ≤ b` is not a negation — one more reason the catalogue is written by hand.
-/

open Lean Meta

namespace JunkValues

/-- One junk-value rule: a theorem of the form `∀ xs, g₁ → … → gₙ → lhs = rhs`, together with the
part of its shape that indexing needs.

The theorem name is the rule. Everything else here is derived from it at registration time and kept
only so that scanning does not have to re-open every rule against every subterm; `openRule` recovers
the full statement when a candidate actually has to be matched. Nothing is cached that could
disagree with the theorem, because everything cached is recomputed from it.

The field layout is part of the `.olean` format — see the compatibility note in `Registry.lean`
before changing it. -/
structure JunkRule where
  /-- The theorem the rule was read off. -/
  source : Name
  /-- The head constant of the left-hand side: the operation that has the junk value. This is what
  the scan indexes on, so that a subterm is only matched against rules that could possibly fire. -/
  head : Name
  /-- Number of arguments applied to `head` in the pattern. Only a cheap pre-filter — a match still
  has to unify — but it rejects most candidates without entering the unifier. -/
  arity : Nat
  /-- How many of the rule's hypotheses are *negations* (`¬P`, `a ≠ b`).

  This is the strongest available signal that a conditional equation is about a junk value rather
  than an ordinary rewrite, and it was measured rather than guessed: over all of Mathlib, requiring
  a canonical default on the right-hand side alone admits 4422 theorems, the large majority of which
  are perfectly ordinary facts that happen to conclude in `= 0` or `= 1`
  (`ZMod.mul_inv_of_unit`, `IsCoatom.sup_eq_top_of_ne`). Requiring a negated hypothesis as well cuts
  that by an order of magnitude, because a junk value's condition is by its nature the *failure* of
  a domain condition — `¬Integrable`, `¬DifferentiableAt`, `¬Summable`.

  It is a count rather than a flag so that a consumer can rank by it, and it is recorded rather than
  enforced because the signal is not perfect in either direction: `Real.sqrt_eq_zero_of_nonpos` is a
  real junk value whose guard `x ≤ 0` is not a negation. `Discovery` requires it and so misses that
  one; the catalogue does not and so keeps it. -/
  negatedGuards : Nat := 0
  /-- Explicit argument positions of the pattern to generalize back into variables, 1-based — the
  second rule form described in the module docstring.

  Empty for an ordinary conditional rule. For `div_zero : a / 0 = 0` it is `#[2]`, which turns the
  pattern into `?a / ?b` and adds the guard `?b = 0`, so that the rule asks about every division
  rather than only about a literal one. -/
  generalize : Array Nat := #[]
  /-- The author's note on why this default is worth warning about, as written in the attribute.
  Empty when omitted. -/
  note : String := ""
deriving Repr, Inhabited, BEq, DecidableEq, Hashable

/-- A rule opened for matching: fresh metavariables for the theorem's binders, and its conclusion
split into the pattern and the value it collapses to.

Held together in one structure because the three parts are only meaningful with respect to the same
metavariable context. -/
structure OpenRule where
  /-- Metavariables standing for the theorem's binders, in declaration order. -/
  vars : Array Expr
  /-- Binder annotations, positionally parallel to `vars`. Needed to tell an instance argument
  (which the scan may synthesize) from a hypothesis (which becomes a guard). -/
  binderInfos : Array BinderInfo
  /-- The left-hand side of the conclusion: the pattern to match subterms against. -/
  lhs : Expr
  /-- The right-hand side: the junk value itself. -/
  rhs : Expr

/-- Instantiate `thm`'s type with fresh universe metavariables and open it up: metavariables for
every binder, and the conclusion split at `Eq`. Returns `none` if the constant does not exist or
does not conclude in an equation.

The fresh *level* metavariables matter and are easy to forget: a rule about `∫ : (α → G) → ℝ` is
universe-polymorphic, and matching it against a term whose universes are already fixed fails outright
if the theorem's universe parameters are left as rigid parameters. -/
def openRule (thm : Name) : MetaM (Option OpenRule) := do
  let some info := (← getEnv).find? thm | return none
  let lvls ← info.levelParams.mapM fun _ => mkFreshLevelMVar
  let type := info.type.instantiateLevelParams info.levelParams lvls
  let (vars, binderInfos, concl) ← forallMetaTelescope type
  let some (_, lhs, rhs) := concl.eq? | return none
  return some { vars, binderInfos, lhs, rhs }

/-- Whether the binder at this position is a *guard*: a hypothesis whose truth is what makes the
value collapse, as opposed to a piece of data the pattern is about.

Instance arguments are excluded even when they are propositions (a `Fact`-style instance is a side
condition the elaborator discharges, not something the reader is being asked to check), and
everything non-`Prop` is data. -/
def isGuardBinder (bi : BinderInfo) (binderType : Expr) : MetaM Bool := do
  if bi matches .instImplicit then return false
  isProp binderType

/-- Head constant of an expression, if it has one. The scan's index key, and the one part of a
rule's pattern that has to be a rigid constant for the rule to be findable at all. -/
def headConst? (e : Expr) : Option Name :=
  match e.getAppFn with
  | .const c _ => some c
  | _ => none

/-- Whether a proposition is stated as a negation: `¬P`, or `a ≠ b` which is notation for one.

Deliberately syntactic. Unfolding to find that some predicate is *definitionally* a negation would
be both slow over a large environment and beside the point: what is being detected is how the author
chose to *state* the condition, and a domain condition's failure is stated with `¬`. -/
def isNegatedProp (p : Expr) : Bool :=
  match p with
  | .app (.const ``Not []) _ => true
  | .app (.app (.app (.const ``Ne _) _) _) _ => true
  | _ => false

/-- Raw argument indices of the *explicit* arguments of an application, in order.

The translation between what a reader counts — "the second argument of `a / b`" — and where that
argument sits in an elaborated term, which for `HDiv.hDiv` is index 5 of 6 behind three type
arguments and an instance. -/
def explicitArgIndices (e : Expr) : MetaM (Array Nat) := do
  let args := e.getAppArgs
  let info ← getFunInfoNArgs e.getAppFn args.size
  let mut out := #[]
  for i in [0:args.size] do
    if let some p := info.paramInfo[i]? then
      if p.binderInfo matches .default then out := out.push i
  return out

/-- Read `thm` as a junk-value rule, or explain why it cannot be one.

The requirements are exactly what the scan needs in order to be able to say something: an equation
to match, a *constant* at the head of the pattern to index it by, and some condition under which the
collapse happens — either a hypothesis, or a `generalize` position that manufactures one. A rule
with neither states an unconditional identity, which is a `simp` lemma and not a warning about
anything.

`generalize` positions are validated here rather than at match time so that a position that does not
exist is an error where somebody wrote it. -/
def ruleOfTheorem? (thm : Name) (note : String := "") (generalize : Array Nat := #[]) :
    MetaM (Except String JunkRule) := do
  let some open_ ← openRule thm
    | return .error s!"`{thm}` does not exist, or its statement is not an equation"
  let .const head _ := open_.lhs.getAppFn
    | return .error s!"the left-hand side of `{thm}` is not headed by a constant, so there is \
        nothing to index the rule by"
  let mut guards := 0
  let mut negated := 0
  for h : i in [0:open_.vars.size] do
    let binderType ← inferType open_.vars[i]
    if ← isGuardBinder open_.binderInfos[i]! binderType then
      guards := guards + 1
      if isNegatedProp binderType then negated := negated + 1
  let explicits ← explicitArgIndices open_.lhs
  for position in generalize do
    if position == 0 || position > explicits.size then
      return .error s!"cannot generalize position {position}: the left-hand side of `{thm}` has \
        {explicits.size} explicit argument(s), and positions are counted from 1"
  if guards == 0 && generalize.isEmpty then
    return .error s!"`{thm}` has no hypothesis, so it states an unconditional identity rather than \
      a condition under which a value collapses to a default. If the condition is hidden in the \
      shape of the left-hand side — as in `a / 0 = 0` — name the argument position to generalize, \
      as `generalizing 2`"
  return .ok {
    source := thm, head, arity := open_.lhs.getAppNumArgs, negatedGuards := negated, generalize,
    note }

end JunkValues
