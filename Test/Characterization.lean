module

public import LeanSpec
-- The attribute is applied at compile time, and the checks below read the extensions it writes
-- from inside `#eval`, which is compile-time too; both need `LeanSpec` at that level.
meta import LeanSpec

@[expose] public section

/-!
# Tests for the `@[characterization]` attribute

Where `@[specifies]` records a claim, `@[characterization]` records something the attribute
*checks*: that a predicate is a predicate on the definition's type, that a theorem really states
the definition satisfies it, that another really states the predicate determines its subject. That
checking is the whole value of the attribute, so this file exercises it from both sides.

Three kinds of check:

* the annotations this module writes are assembled with `characterizations` and compared verbatim,
  which covers the recording, the inference of an omitted predicate, the reading of the relation
  off a uniqueness statement, and the grouping of parts into bundles;
* the `SpecEntry` each characterization theorem also writes is read back, since a consumer that
  only knows about `@[specifies]` depends on it;
* every rejection is exercised with `#guard_msgs`, which pins the exact message — these messages
  are the whole user interface of the attribute, and one that stops explaining what to do instead
  has regressed even though nothing fails to compile.

Run with `lake build Test`.
-/

open Lean

namespace Referee.Test.Characterization

/-! ## Accepted forms

Everything here is Lean core only, so the definitions are arithmetic rather than the measure
theory the attribute is really for. The shapes are the point. -/

/-- Twice `n`. -/
def double (n : Nat) : Nat := n + n

/-- `m` is twice `n`. -/
@[characterization property double "the defining equation"]
def IsDouble (n m : Nat) : Prop := m = n + n

-- The predicate is omitted and read off the statement: the head of the conclusion.
@[characterization existence]
theorem isDouble_double (n : Nat) : IsDouble n (double n) := rfl

-- The predicate is omitted and read off the hypotheses.
@[characterization uniqueness]
theorem IsDouble.unique {n a b : Nat} (h₁ : IsDouble n a) (h₂ : IsDouble n b) : a = b :=
  Eq.trans h₁ (Eq.symm h₂)

/-- Three times `n`. -/
def triple (n : Nat) : Nat := n + n + n

/-- `m` is three times `n`. -/
@[characterization property triple]
def IsTriple (n m : Nat) : Prop := m = n + n + n

@[characterization existence]
theorem isTriple_triple (n : Nat) : IsTriple n (triple n) := rfl

-- The other accepted uniqueness shape, and the one Mathlib usually writes: a single hypothesis,
-- related to the definition itself rather than to a second arbitrary object.
@[characterization uniqueness]
theorem IsTriple.eq_triple {n m : Nat} (h : IsTriple n m) : m = triple n := h

/-! ### Uniqueness up to something other than equality

The reason the relation is read off the conclusion rather than assumed to be `Eq`. Here it is
parity; in practice it is a.e. equality or the existence of an isomorphism. `IsEven` really does
determine a natural number up to `SameParity`, so this is a complete and correct — if very
weak — characterization, which is exactly the point of the warning in the module docstring that
these checks buy well-formedness and not meaning. -/

/-- `a` and `b` leave the same remainder mod 2. -/
def SameParity (a b : Nat) : Prop := a % 2 = b % 2

/-- The number four. -/
def four : Nat := 4

/-- `n` is even. -/
@[characterization property four "determines a number only up to parity"]
def IsEven (n : Nat) : Prop := n % 2 = 0

@[characterization existence]
theorem isEven_four : IsEven four := rfl

@[characterization uniqueness]
theorem IsEven.unique {a b : Nat} (h₁ : IsEven a) (h₂ : IsEven b) : SameParity a b :=
  Eq.trans h₁ (Eq.symm h₂)

/-! ### An incomplete characterization

A property and an existence theorem with no uniqueness theorem says no more than a `@[specifies]`
annotation does, and `isComplete` is how a tool tells the two apart. -/

/-- Five. -/
def five : Nat := 5

/-- `n` is odd. -/
@[characterization property five]
def IsOdd (n : Nat) : Prop := n % 2 = 1

@[characterization existence]
theorem isOdd_five : IsOdd five := rfl

/-! ## Reading the annotations back -/

/-- The characterizations this module recorded.

Restricted to this namespace so that an annotation added elsewhere in the repository does not
break these expectations; `characterizations` returns imported entries too. -/
private def dump (env : Environment) : String :=
  let ours := (LeanSpec.characterizations env).filter fun c =>
    (`Referee.Test.Characterization).isPrefixOf c.property
  String.intercalate "\n" <| ours.toList.map fun c =>
    let comment := if c.comment.isEmpty then "" else s!" — {c.comment}"
    let names (es : Array LeanSpec.CharEntry) : String :=
      if es.isEmpty then "(none)"
      else String.intercalate ", " (es.toList.map (·.declName.toString))
    let ups := String.intercalate ", " (c.uniqueness.toList.map fun e =>
      s!"{e.relation} [{e.relationHead}]")
    String.intercalate "\n"
      [ s!"{c.target} by {c.property}{comment}",
        s!"  existence: {names c.existence}",
        s!"  uniqueness: {names c.uniqueness}",
        s!"  up to: {if ups.isEmpty then "(none)" else ups}",
        s!"  complete: {c.isComplete}" ]

/-- The specification entries this module recorded, which it never wrote a `@[specifies]` for:
every one of them is the side effect of a characterization theorem. -/
private def dumpSpec (env : Environment) : String :=
  let ours := (LeanSpec.specEntries env).filter fun e =>
    (`Referee.Test.Characterization).isPrefixOf e.theoremName
  String.intercalate "\n" <| ours.toList.map fun e => s!"{e.target}: {e.theoremName}"

/--
info: Referee.Test.Characterization.double by Referee.Test.Characterization.IsDouble — the defining equation
  existence: Referee.Test.Characterization.isDouble_double
  uniqueness: Referee.Test.Characterization.IsDouble.unique
  up to: a = b [Eq]
  complete: true
Referee.Test.Characterization.triple by Referee.Test.Characterization.IsTriple
  existence: Referee.Test.Characterization.isTriple_triple
  uniqueness: Referee.Test.Characterization.IsTriple.eq_triple
  up to: m = triple n [Eq]
  complete: true
Referee.Test.Characterization.four by Referee.Test.Characterization.IsEven — determines a number only up to parity
  existence: Referee.Test.Characterization.isEven_four
  uniqueness: Referee.Test.Characterization.IsEven.unique
  up to: SameParity a b [Referee.Test.Characterization.SameParity]
  complete: true
Referee.Test.Characterization.five by Referee.Test.Characterization.IsOdd
  existence: Referee.Test.Characterization.isOdd_five
  uniqueness: (none)
  up to: (none)
  complete: false
-/
#guard_msgs in
#eval show CoreM Unit from do IO.println (dump (← getEnv))

/--
info: Referee.Test.Characterization.double: Referee.Test.Characterization.isDouble_double
Referee.Test.Characterization.double: Referee.Test.Characterization.IsDouble.unique
Referee.Test.Characterization.triple: Referee.Test.Characterization.isTriple_triple
Referee.Test.Characterization.triple: Referee.Test.Characterization.IsTriple.eq_triple
Referee.Test.Characterization.four: Referee.Test.Characterization.isEven_four
Referee.Test.Characterization.four: Referee.Test.Characterization.IsEven.unique
Referee.Test.Characterization.five: Referee.Test.Characterization.isOdd_five
-/
#guard_msgs in
#eval show CoreM Unit from do IO.println (dumpSpec (← getEnv))

/-! ## Rejections

Each of these would otherwise become a wrong entry in a project's published specification — and,
worse than with `@[specifies]`, one a tool would present as *checked*. So the attribute refuses it
at elaboration time rather than recording it. -/

/-! ### The property -/

/--
error: `Referee.Test.Characterization.not_a_predicate_on_double` cannot characterize `Referee.Test.Characterization.double`: a characterizing property has to land in `Prop` with a last argument of the type its definition has, or returns, so that `Referee.Test.Characterization.not_a_predicate_on_double … (Referee.Test.Characterization.double …)` is a proposition. Here the property is
  String → Prop
and the definition is
  Nat → Nat
-/
#guard_msgs in
@[characterization property double]
def not_a_predicate_on_double (s : String) : Prop := s = s

/--
error: `characterization property` belongs on a predicate, but `Referee.Test.Characterization.property_on_a_proof` is a proof. The property is the statement a characterization is *about*; the theorem that the definition satisfies it carries `@[characterization existence]`
-/
#guard_msgs in
@[characterization property double]
theorem property_on_a_proof : 1 = 1 := rfl

theorem some_proof : 1 = 1 := rfl

/--
error: `Referee.Test.Characterization.some_proof` is itself a proof, but `characterization property` names the definition the annotated predicate is a property of
-/
#guard_msgs in
@[characterization property some_proof]
def IsWhatever (n : Nat) : Prop := n = n

/--
error: `@[characterization property]` needs the definition it characterizes, as `@[characterization property myDefinition]`
-/
#guard_msgs in
@[characterization property]
def no_definition_named (n : Nat) : Prop := n = n

-- Only reachable through `attribute`, since a definition cannot name itself as it is declared.
def IsSelf (n : Nat) : Prop := n = n

/-- error: `Referee.Test.Characterization.IsSelf` cannot characterize itself -/
#guard_msgs in
attribute [characterization property IsSelf] IsSelf

/--
error: `Referee.Test.Characterization.IsDoubleAgain` is already registered as a characterizing property of `Referee.Test.Characterization.double`
-/
#guard_msgs in
@[characterization property double, characterization property double]
def IsDoubleAgain (n m : Nat) : Prop := m = n + n

/-! ### The theorems -/

/--
error: `characterization existence` belongs on a theorem, but `Referee.Test.Characterization.existence_on_a_non_proposition` is not a proposition
-/
#guard_msgs in
@[characterization existence IsDouble]
def existence_on_a_non_proposition : Nat := 4

/--
error: `Referee.Test.Characterization.existence_of_the_wrong_shape` does not state that `Referee.Test.Characterization.double` satisfies `Referee.Test.Characterization.IsDouble`: that would be `Referee.Test.Characterization.IsDouble … x`, with `x` built from the definition. Its statement is
  ∀ (n : Nat), n = n
-/
#guard_msgs in
@[characterization existence IsDouble]
theorem existence_of_the_wrong_shape (n : Nat) : n = n := rfl

/--
error: `Referee.Test.Characterization.uniqueness_relating_nothing` does not state that `Referee.Test.Characterization.IsDouble` determines its subject: that would end in a relation between two objects its hypotheses say satisfy `Referee.Test.Characterization.IsDouble`, or between one such object and `Referee.Test.Characterization.double`. Its statement is
  ∀ {n a b : Nat}, IsDouble n a → IsDouble n b → 0 = 0
-/
#guard_msgs in
@[characterization uniqueness IsDouble]
theorem uniqueness_relating_nothing {n a b : Nat} (_ : IsDouble n a) (_ : IsDouble n b) :
    0 = 0 := rfl

/-- Not registered with `@[characterization property]`. -/
def NotAProperty (n : Nat) : Prop := n = n

/--
error: `Referee.Test.Characterization.NotAProperty` is not a characterizing property: mark it with `@[characterization property theDefinition]` before naming it here
-/
#guard_msgs in
@[characterization existence NotAProperty]
theorem names_an_unregistered_property : NotAProperty 3 := rfl

/--
error: cannot tell which characterizing property `Referee.Test.Characterization.nothing_to_infer_from` is part of: nothing in its statement is registered with `@[characterization property]`. Name it explicitly, as `@[characterization existence MyProperty]`
-/
#guard_msgs in
@[characterization existence]
theorem nothing_to_infer_from : double 1 = 2 := rfl

/--
error: `Referee.Test.Characterization.duplicated_existence` is already registered as the existence part of the characterization of `Referee.Test.Characterization.double` by `Referee.Test.Characterization.IsDouble`
-/
#guard_msgs in
@[characterization existence, characterization existence]
theorem duplicated_existence (n : Nat) : IsDouble n (double n) := rfl

/--
error: `characterization` must be a global attribute: a characterization is a claim about the definition, not about a section or a namespace
-/
#guard_msgs in
@[local characterization existence]
theorem not_global (n : Nat) : IsDouble n (double n) := rfl

/-! ## The circularity warning

A property that mentions the definition it characterizes is satisfied by that definition for no
reason at all. Nearly always a mistake, but only nearly — the reference can sit in a side
condition carrying none of the content — so it is a warning, and it can be switched off. -/

/-- Seven. -/
def seven : Nat := 7

/--
warning: `Referee.Test.Characterization.IsCircular` is marked as a characterizing property of `Referee.Test.Characterization.seven`, but it mentions `Referee.Test.Characterization.seven`: a property that refers to the definition it characterizes pins nothing down. Set `characterization.checkNotCircular` to `false` to silence this.
-/
#guard_msgs in
@[characterization property seven]
def IsCircular (n : Nat) : Prop := n = seven

#guard_msgs in
set_option characterization.checkNotCircular false in
@[characterization property seven]
def IsCircularSilenced (n : Nat) : Prop := n = seven ∧ True

end Referee.Test.Characterization
