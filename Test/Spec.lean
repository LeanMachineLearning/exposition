module

public import LeanSpec
-- The attribute is applied at compile time, and the checks below read the extension it writes from
-- inside `#eval`, which is compile-time too; both need `LeanSpec` at that level.
meta import LeanSpec

@[expose] public section

/-!
# Tests for the `@[specifies]` attribute

The `LeanSpec` package is small but it is not inert: it infers a target from a declaration's name,
rejects five kinds of misuse, and warns about a sixth. None of that is visible in the Referee
site — a rejected annotation is a build error in the *target* project, and a wrongly accepted one
becomes a silently wrong specification — so it is checked here.

Two kinds of check:

* the annotations this module writes are read back out of the environment and compared verbatim,
  which covers the recording, the inference of an omitted target, and repeated application;
* every rejection is exercised with `#guard_msgs`, which pins the exact message. That is
  deliberate: these messages are the whole user interface of the attribute, and an error that
  stops explaining what to do instead has regressed even though nothing fails to compile.

Run with `lake build Test`.
-/

open Lean

namespace Referee.Test.Spec

/-! ## Accepted forms -/

/-- Twice `n`. -/
def double (n : Nat) : Nat := 2 * n

/-- Three times `n`. -/
def triple (n : Nat) : Nat := 3 * n

@[specifies double "the textbook characterization"]
theorem double_zero : double 0 = 0 := rfl

-- Target omitted: taken from the enclosing namespace, which here is the definition itself.
@[specifies]
theorem double.one : double 1 = 2 := rfl

-- One theorem in the specification of two definitions, each with its own comment.
@[specifies double, specifies triple "relates the two at zero"]
theorem double_triple_zero : double 0 = triple 0 := rfl

/-- The annotations this module recorded, as `target: theorem — comment` lines.

Restricted to this namespace so that an annotation added elsewhere in the repository does not
break these expectations; `specEntries` returns imported entries too. -/
private def dump (env : Environment) : String :=
  let ours := (LeanSpec.specEntries env).filter fun entry =>
    (`Referee.Test.Spec).isPrefixOf entry.theoremName
  String.intercalate "\n" <| ours.toList.map fun entry =>
    let comment := if entry.comment.isEmpty then "" else s!" — {entry.comment}"
    s!"{entry.target}: {entry.theoremName}{comment}"

/--
info: Referee.Test.Spec.double: Referee.Test.Spec.double_zero — the textbook characterization
Referee.Test.Spec.double: Referee.Test.Spec.double.one
Referee.Test.Spec.double: Referee.Test.Spec.double_triple_zero
Referee.Test.Spec.triple: Referee.Test.Spec.double_triple_zero — relates the two at zero
-/
#guard_msgs in
#eval show CoreM Unit from do IO.println (dump (← getEnv))

/-! ## Rejections

Each of these is a mistake that would otherwise become a wrong entry in a project's published
specification, so the attribute refuses it at elaboration time rather than recording it. -/

theorem two_pos : 0 < 2 := by decide

/--
error: `Referee.Test.Spec.two_pos` is itself a proof, but `specifies` names the definition that the annotated theorem is a property of
-/
#guard_msgs in
@[specifies two_pos]
theorem target_is_a_theorem : double 1 = 2 := rfl

/-- error: `specifies` belongs on a theorem, but `Referee.Test.Spec.not_a_prop` is not a proposition -/
#guard_msgs in
@[specifies double]
def not_a_prop : Nat := 4

/-- error: `Referee.Test.Spec.duplicated` is already part of the specification of `Referee.Test.Spec.double` -/
#guard_msgs in
@[specifies double, specifies double]
theorem duplicated : double 0 = 0 := rfl

/--
error: `specifies` must be a global attribute: a specification is a claim about the definition, not about a section or a namespace
-/
#guard_msgs in
@[local specifies double]
theorem not_global : double 1 = 2 := rfl

/--
error: cannot infer what `Referee.Test.Spec.nothing_to_infer_from` specifies: no enclosing namespace of its name is a declaration. Name the definition explicitly, as `@[specifies myDefinition]`
-/
#guard_msgs in
@[specifies]
theorem nothing_to_infer_from : double 1 = 2 := rfl

-- Only reachable through `attribute`, since a theorem cannot name itself as it is being declared.
theorem self_referential : double 0 = 0 := rfl

/-- error: `Referee.Test.Spec.self_referential` cannot be part of its own specification -/
#guard_msgs in
attribute [specifies self_referential] self_referential

/-! ## The unmentioned-target warning

A theorem that never names its target is nearly always a copy-pasted annotation, but only nearly:
the target can hide behind an abbreviation or inside a projection. So this is a warning, it is
skipped for a theorem living in the target's namespace, and it can be switched off. -/

/--
warning: `Referee.Test.Spec.silent_about_double` is marked as part of the specification of `Referee.Test.Spec.double`, but its statement does not mention `Referee.Test.Spec.double`. Set `specifies.checkTargetMentioned` to `false` to silence this.
-/
#guard_msgs in
@[specifies double]
theorem silent_about_double : 1 + 1 = 2 := rfl

-- Silenced by the option: no message at all.
#guard_msgs in
set_option specifies.checkTargetMentioned false in
@[specifies double]
theorem silenced : 1 + 1 = 2 := rfl

-- Living in the target's namespace is taken as intent enough, with the check still on.
#guard_msgs in
@[specifies double]
theorem double.unrelated_statement : 1 + 1 = 2 := rfl

end Referee.Test.Spec
