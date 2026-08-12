module

public import LeanSpec
-- The shared predicate under test is declared in the core characterization test module; the whole
-- point of this file is that its definitions live *here* and the predicate does not.
public import Test.Characterization
-- The attribute is applied at compile time, and the checks below read the extensions it writes
-- from inside `#eval`, which is compile-time too; both need these at that level.
meta import LeanSpec
meta import Test.Characterization

@[expose] public section

/-!
# Cross-module characterization

`Test/Characterization.lean` exercises the attribute within one module. This file exercises the
thing a single module cannot show: that a predicate and the definition it characterizes may live in
different modules, so that *one* shared predicate can characterize definitions across a library
instead of being copied into each of them.

Two directions, both real:

* a **local predicate** for an **imported definition** — the annotation is written where the
  predicate is;
* an **imported predicate** for a **local definition** — written with a standalone `attribute`
  command, since the predicate is not being declared here. This is the direction that matters: it
  is what lets `IsCondExp`-style predicates be shared.

The rejection is the case neither of those covers, where both sides are imported and the entry
would land in a module that nothing reaches it from.
-/

open Lean

namespace Referee.Test.CharacterizationExtra

open Referee.Test.Characterization (IsDouble double)

/-! ## An imported predicate characterizing a local definition

`IsDouble` is declared in `Test.Characterization`, where it already characterizes `double`. Here it
characterizes a second definition, registered against it from *this* module — which is where a
reader of that definition would look, and which is the whole point: one predicate, several
definitions, no copy of the predicate per module.

`eightyEight` is a numeral rather than anything built from `double`, so the two theorems below
belong unambiguously to its bundle. Written as `double 44` it would be *definitionally* an
application of the imported definition, and `statesExistence` would file the existence theorem
under `double` — correctly, since the statement really would be one about `double 44`. -/

/-- Eighty-eight. -/
def eightyEight : Nat := 88

attribute [characterization property eightyEight "the defining equation, the same predicate that \
characterizes `double`"] IsDouble

@[characterization existence]
theorem isDouble_eightyEight : IsDouble 44 eightyEight := rfl

@[characterization uniqueness]
theorem IsDouble.eq_eightyEight {m : Nat} (h : IsDouble 44 m) : m = eightyEight := h

/-! ## A local predicate characterizing an imported definition

The mirror image, and the direction that already worked: here the annotation is written where the
predicate is, and the definition is the imported one. -/

/-- `m` is `n` doubled, said through addition rather than through `n + n`. -/
@[characterization property double "the defining equation again, stated additively"]
def IsTwice (n m : Nat) : Prop := m = 2 * n

@[characterization existence]
theorem isTwice_double (n : Nat) : IsTwice n (double n) := by
  simp [IsTwice, double, Nat.two_mul]

@[characterization uniqueness]
theorem IsTwice.unique {n a b : Nat} (h₁ : IsTwice n a) (h₂ : IsTwice n b) : a = b :=
  h₁.trans h₂.symm

/-! ## Reading the annotations back

Both bundles have to come back complete, and `IsDouble` has to end up with *two* targets — the
imported `double` from the core module and the local `eightyEight` — since that is the whole
claim: one predicate, several definitions, no copying. -/

/-- The characterizations this module contributed: one side of each is declared here, and the
other is imported. Restricted to those, so that the bundles the core test module records — and the
partial entries its own rejection tests leave behind — do not appear. -/
private def dump (env : Environment) : String :=
  let ours := (LeanSpec.characterizations env).filter fun c =>
    (`Referee.Test.CharacterizationExtra).isPrefixOf c.property
      || (`Referee.Test.CharacterizationExtra).isPrefixOf c.target
  String.intercalate "\n" <| ours.toList.map fun c =>
    let names (es : Array LeanSpec.CharEntry) : String :=
      if es.isEmpty then "(none)"
      else String.intercalate ", " (es.toList.map (·.declName.toString))
    s!"{c.target} by {c.property}: existence {names c.existence}, \
      uniqueness {names c.uniqueness}, complete {c.isComplete}"

/--
info: Referee.Test.CharacterizationExtra.eightyEight by Referee.Test.Characterization.IsDouble: existence Referee.Test.CharacterizationExtra.isDouble_eightyEight, uniqueness Referee.Test.CharacterizationExtra.IsDouble.eq_eightyEight, complete true
Referee.Test.Characterization.double by Referee.Test.CharacterizationExtra.IsTwice: existence Referee.Test.CharacterizationExtra.isTwice_double, uniqueness Referee.Test.CharacterizationExtra.IsTwice.unique, complete true
-/
#guard_msgs in
#eval show CoreM Unit from do IO.println (dump (← getEnv))

-- The imported predicate carries a complete bundle for the definition declared here, and the
-- imported definition keeps the one it already had — neither module's entries clobber the other's.
-- Silent on success, so no expected message.
#guard_msgs in
#eval show CoreM Unit from do
  let env ← getEnv
  unless LeanSpec.isCharacterized env `Referee.Test.CharacterizationExtra.eightyEight do
    throwError "`eightyEight` is not characterized by the imported predicate"
  unless LeanSpec.isCharacterized env `Referee.Test.Characterization.double do
    throwError "`double` is characterized by predicates from both modules, and by neither now"
  unless LeanSpec.isCharacterized env `Referee.Test.Characterization.four do
    throwError "`four` lost the characterization its own module recorded"

/-! ## The rejection

Neither declaration is local, so the entry would be recorded in a module that a consumer reaching
`IsTriple` or `triple` through its own imports would never load. -/

/--
error: cannot record a characterization of `Referee.Test.Characterization.triple` by `Referee.Test.Characterization.IsEven`: both are declared in imported modules, so the entry would sit in a module neither of them points back to and a consumer reaching either through its own imports would not see it. Write the annotation in the module that declares one of them.
-/
#guard_msgs in
attribute [characterization property Referee.Test.Characterization.triple]
  Referee.Test.Characterization.IsEven

end Referee.Test.CharacterizationExtra
