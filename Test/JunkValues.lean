module

public import JunkValues
-- The checks below are `#guard`s and `run_meta` blocks, which Lean elaborates at compile time, so
-- the declarations under test have to be imported at that level too.
meta import JunkValues

@[expose] public section

/-!
# Tests for `JunkValues`

The **core** of the package: `@[junk_value]`, and the scan the linter reports from. The optional rule
sources are tested separately, in `Test/JunkValuesExtra.lean`.

Two halves.

The `#guard`s cover the pure functions — the safety-goal transformation, the rule set's indexing, the
reporting — which need no environment and no Mathlib.

The `run_meta` blocks cover the parts that need one, and they do it against a **synthetic junk
value** declared here: `myOp`, which really does collapse to `0` when `Good` fails, with a real proof
of it and a real `@[junk_value]` annotation on that proof. That is the point — the whole core path
(annotate a theorem → read it back out of the environment → find the pattern in a later declaration →
instantiate the guard → discharge it from the hypotheses) is exercised with no Mathlib in the picture
at all, which is exactly the claim the package makes about itself.

Run with `lake build Test`.
-/

open Lean Meta
open JunkValues

namespace JunkValues.Test

/-! ## Safety goals

The transformation that turns "the value collapses when `g`" into "the value is fine when …".
Double negation is collapsed because the goal is handed to a tactic that knows integrability, not
classical logic. -/

private def mkNotOf (p : Expr) : Expr := .app (.const ``Not []) p

#guard safetyGoal (mkNotOf (.const `P [])) == .const `P []
#guard safetyGoal (.const `P []) == mkNotOf (.const `P [])
-- `x ≠ y` is a guard like any other, and its safety goal is `x = y` rather than `¬(x ≠ y)`.
#guard safetyGoal (mkAppN (.const ``Ne [.zero]) #[.const `T [], .const `a [], .const `b []])
  == mkAppN (.const ``Eq [.zero]) #[.const `T [], .const `a [], .const `b []]

/-! ## Statuses and sites -/

#guard !(Status.guarded "hypothesis `h`").isFinding
#guard Status.unguarded.isFinding
#guard (Status.triggered "assumption").isFinding
#guard Status.unguarded.slug == "unguarded"
#guard Site.statement.slug == "statement"

/-! ## The reported sentence

This is the form the tool was asked for, so it is pinned. -/

private def sampleFinding : Finding where
  decl := `B
  site := .body
  rule := `MeasureTheory.integral_undef
  head := `MeasureTheory.integral
  term := "∫ (x : α), f x + g x ∂μ"
  guards := #["¬Integrable (fun a => f a + g a) μ"]
  value := "0"
  status := .unguarded

#guard sampleFinding.message ==
  "if ¬Integrable (fun a => f a + g a) μ then ∫ (x : α), f x + g x ∂μ = 0 \
   (by MeasureTheory.integral_undef)"

-- Several guards read as a conjunction: the value collapses only when all of them hold.
#guard { sampleFinding with guards := #["A", "B"] }.message ==
  "if A and B then ∫ (x : α), f x + g x ∂μ = 0 (by MeasureTheory.integral_undef)"

-- A `triggered` finding is a different sentence, because it is a much stronger claim.
#guard { sampleFinding with status := .triggered "hypothesis `hf`" }.message ==
  "∫ (x : α), f x + g x ∂μ = 0: the condition holds (hypothesis `hf`) \
   (by MeasureTheory.integral_undef)"

/-! ## Rule set indexing -/

private def ruleA : JunkRule := { source := `a_undef, head := `op, arity := 2 }
private def ruleB : JunkRule := { source := `b_undef, head := `op, arity := 3 }
private def ruleC : JunkRule := { source := `c_undef, head := `other, arity := 1 }

private def threeRules : RuleSet :=
  (((({} : RuleSet).insert ruleA).insert ruleB).insert ruleC)

#guard threeRules.rules.size == 3
#guard (threeRules.forHead `op).size == 2
#guard (threeRules.forHead `other).size == 1
#guard (threeRules.forHead `absent).size == 0
-- Re-inserting the same source theorem is a no-op, which is what makes source order a priority
-- order: a project's own `@[junk_value]` note survives a catalogue entry for the same theorem.
#guard (threeRules.insert ruleA).rules.size == 3
#guard (threeRules.insert { ruleA with note := "later" }).rules[0]!.note == ""

/-! ## Reporting failures to assemble

A catalogue entry that stops resolving must produce a *message*, because the alternative is a scan
that quietly checks less than the last one did. -/

#guard ({ problems := #["catalogue entry `gone` does not resolve"] } : RuleSetReport).warnings.size == 1
#guard ({} : RuleSetReport).warnings.isEmpty
-- A source that contributed nothing is still listed, so `#junk_rules` can say which import is missing.
#guard ({ contributions := #[("catalogue", 0)] } : RuleSetReport).contributions.size == 1

/-! ## Deduplication and inherited risk -/

#guard (dedupFindings #[sampleFinding, sampleFinding]).size == 1
#guard (dedupFindings #[sampleFinding, { sampleFinding with term := "other" }]).size == 2
-- The same term under a *different* rule is a different fact about it, and is kept.
#guard (dedupFindings #[sampleFinding, { sampleFinding with rule := `other_undef }]).size == 2
-- Statement and body are different findings even for an identical term.
#guard (dedupFindings #[sampleFinding, { sampleFinding with site := .statement }]).size == 2

#guard (riskySet #[sampleFinding]).contains `B
#guard !(riskySet #[{ sampleFinding with status := .guarded "hypothesis `h`" }]).contains `B

-- `C` depends on `B` and `Unrelated`; only `B` is at risk, so only `B` is inherited.
private def depsOf (ds : Array Name) : Std.HashMap Name (Array Name) := (∅ : Std.HashMap _ _).insert `C ds

#guard inheritRisk (depsOf #[`B, `Unrelated]) (riskySet #[sampleFinding]) `C == #[`B]
#guard inheritRisk (depsOf #[`Unrelated]) (riskySet #[sampleFinding]) `C == #[]

/-! ## End to end, on a synthetic junk value

`myOp` collapses to `0` exactly when `Good` fails, and `myOp_undef` proves it. Everything below goes
through the same path a Mathlib integral does. -/

/-- The domain condition. -/
def Good (f : Nat → Nat) : Prop := f 0 = 0

/-- An operation with a junk value: `0` outside `Good`. -/
def myOp (f : Nat → Nat) : Nat := if f 0 = 0 then 7 else 0

/-- The rule, with a real proof — and the annotation that is the core of this package. -/
@[junk_value "outside `Good` the operation is 0, which is also a value it takes inside `Good`"]
theorem myOp_undef (f : Nat → Nat) (h : ¬ Good f) : myOp f = 0 := ite_eq_right h

/-- A definition resting on the junk value, with nothing ruling it out. -/
def usesMyOp (f : Nat → Nat) : Nat := myOp f + 1

/-- The same, with the domain condition in scope. -/
def guardedUse (f : Nat → Nat) (_h : Good f) : Nat := myOp f + 1

/-- A definition whose hypothesis says the condition *fails*: the junk value is definitely taken. -/
def triggeredUse (f : Nat → Nat) (_h : ¬ Good f) : Nat := myOp f + 1

/-! ### The second rule form

`myDiv` states its junk value by *specialising* an argument rather than by a hypothesis, the shape
`div_zero` has. Without `generalizing` the pattern would match only a literal `myDiv a 0`; with it,
the rule asks about every divisor. -/

/-- Division that returns `0` on a zero divisor, like every division in Lean. -/
def myDiv (a b : Nat) : Nat := if b = 0 then 0 else a / b

/-- The rule, stated by specialising the divisor — no hypothesis anywhere in it. -/
@[junk_value generalizing 2 "division by zero is 0, so a zero quotient says nothing about `a`"]
theorem myDiv_zero (a : Nat) : myDiv a 0 = 0 := by simp [myDiv]

/-- A use with a variable divisor: nothing says it is nonzero. -/
def usesMyDiv (a b : Nat) : Nat := myDiv a b + 1

/-- The same, with the divisor known to be nonzero. -/
def guardedDiv (a b : Nat) (_h : b ≠ 0) : Nat := myDiv a b + 1

/-! ### Instance arguments the pattern does not determine

A regression test for the worst bug this package has had. `tsub_eq_zero_of_le : a ≤ b → a - b = 0`
requires `OrderedSub α`, which `ℕ` and `ℝ≥0∞` have and `ℝ`, `ℤ` and `ℚ` do not — truncation is
precisely what those types do *not* do. That instance never appears in the term `x - y`, so
unification cannot assign it; it has to be synthesized, and when synthesis *fails* the rule does not
apply. Carrying on with the argument left open reported every subtraction in every project.

Modelled here rather than described: `Op` is the operation, `Clamped` is the separate class that
makes it collapse, and `Blob` has the first without the second. -/

/-- An operation available on any type that has it. -/
class Op (α : Type) where op : α → α → α

/-- A default value for the collapse. -/
class Zed (α : Type) where zed : α

/-- The relation the guard is stated with. Available for *both* types below — this mirrors
`Preorder`, which `ℝ` has, and is what makes the guard fully determined. -/
class Small (α : Type) where small : α → α → Prop

/-- The property that makes `Op.op` collapse, and the only thing the clamping type has that the
other does not. This mirrors `OrderedSub`: it appears in the rule's binders and *nowhere in the
rule's guard or value*, which is precisely what made the bug invisible — with the instance left
unsynthesized there was no metavariable anywhere in the reported finding to notice it by. -/
class Clamped (α : Type) [Op α] [Zed α] [Small α] where
  clamped : ∀ {a b : α}, Small.small a b → Op.op a b = Zed.zed

/-- A type where the operation really does collapse: truncated subtraction on `Nat`. -/
instance : Op Nat := ⟨fun a b => a - b⟩
instance : Zed Nat := ⟨0⟩
instance : Small Nat := ⟨fun a b => a ≤ b⟩
instance : Clamped Nat where
  clamped {a b} h := by
    have hle : a ≤ b := h
    show a - b = 0
    omega

/-- A type with the operation, the default and the relation, but no collapse — the `ℝ` of this
test, which has `Sub` and `Preorder` and no `OrderedSub`. -/
structure Blob where val : Nat
instance : Op Blob := ⟨fun a b => ⟨a.val + b.val⟩⟩
instance : Zed Blob := ⟨⟨0⟩⟩
instance : Small Blob := ⟨fun a b => a.val ≤ b.val⟩
-- No `Clamped Blob`: the operation does not collapse here, and the rule must not fire on it.

/-- The rule. Its `[Clamped α]` argument appears in neither the pattern nor the guard, so a match
that leaves it unsynthesized produces a finding with nothing wrong-looking in it at all. -/
theorem op_eq_zed_of_small {α : Type} [Op α] [Zed α] [Small α] [Clamped α] {a b : α}
    (h : Small.small a b) : Op.op a b = Zed.zed := Clamped.clamped h

/-- Uses the operation at a type that *does* clamp: must be reported. -/
def clampingUse (a b : Nat) : Nat := Op.op a b

/-- Uses it at a type that does not: must be silent. -/
def nonClampingUse (a b : Blob) : Blob := Op.op a b

/-! ### Recursive definitions

The other bug worth pinning. A recursive definition's elaborated value is a wrapper, and the body
somebody wrote ends up in compiler-generated helpers — so scanning only the value found nothing at
all here, and the collapse was invisible. -/

/-- Recursive, and the only occurrence of the junk value is inside the recursion. -/
def countdown : Nat → Nat
  | 0 => 0
  | n + 1 => Op.op (countdown n) 1

run_meta do
  -- Reading a theorem as a rule.
  let .ok rule ← ruleOfTheorem? ``myOp_undef
    | throwError "myOp_undef should be readable as a junk-value rule"
  unless rule.head == ``myOp do throwError "expected head `myOp`, got `{rule.head}`"
  unless rule.arity == 1 do throwError "expected arity 1, got {rule.arity}"
  unless rule.negatedGuards == 1 do
    throwError "expected one negated guard, got {rule.negatedGuards}"

  -- The `@[junk_value]` annotation reached the environment extension, note and all. This is the
  -- core of the package: without it there is nothing for a scan to run with.
  let declared := declaredRules (← getEnv)
  let some annotated := declared.find? (·.source == ``myOp_undef)
    | throwError "`@[junk_value]` on `myOp_undef` did not reach `declaredRules`"
  unless annotated.head == ``myOp do
    throwError "the annotated rule has the wrong head `{annotated.head}`"
  if annotated.note.isEmpty then
    throwError "the note written in the attribute was dropped"

  -- ... and `RuleSet.ofEnv` picks it up with no optional source imported, attributing it to the
  -- annotation rather than to anything in `Extra`.
  let report ← RuleSet.ofEnv
  unless report.ruleSet.rules.any (·.source == ``myOp_undef) do
    throwError "`RuleSet.ofEnv` did not include the annotated rule"
  unless report.contributions.any (fun (name, n) => name == "@[junk_value]" && n > 0) do
    throwError "the annotated rule was not attributed to `@[junk_value]`"
  unless report.problems.isEmpty do
    throwError "a core-only rule set should have nothing to report: {report.problems}"

  -- A theorem with no hypothesis is an unconditional identity, not a rule.
  unless (← ruleOfTheorem? ``Nat.add_zero) matches .error _ do
    throwError "a hypothesis-free equation must be rejected as a rule"

  -- A constant that does not exist is rejected rather than throwing.
  unless (← ruleOfTheorem? `no_such_theorem) matches .error _ do
    throwError "a missing constant must be rejected as a rule"

  let rs : RuleSet := ({} : RuleSet).insert rule

  -- Found, guard instantiated at the occurrence, and nothing rules it out.
  let scan ← scanDecl rs {} ``usesMyOp
  unless scan.findings.size == 1 do
    throwError "expected one finding in `usesMyOp`, got {scan.findings.size}"
  let f := scan.findings[0]!
  unless f.status matches .unguarded do
    throwError "expected `usesMyOp` to be unguarded, got {repr f.status}"
  unless f.value == "0" do throwError "expected the default value `0`, got {f.value}"
  unless f.guards == #["¬Good f"] do
    throwError "expected the guard `¬Good f`, got {f.guards}"
  unless f.site matches .body do throwError "expected a body finding"

  -- The hypothesis in scope rules it out, so it is not reported at all.
  let scan ← scanDecl rs {} ``guardedUse
  unless scan.findings.isEmpty do
    throwError "expected `guardedUse` to be clean, got {scan.findings.size} finding(s)"

  -- ... but it is still *found*, and recorded as guarded, when the scan is asked to show its work.
  let scan ← scanDecl rs { includeGuarded := true } ``guardedUse
  unless scan.findings.size == 1 do
    throwError "expected the guarded occurrence to be visible with `includeGuarded`"
  unless scan.findings[0]!.status matches .guarded _ do
    throwError "expected a guarded status, got {repr scan.findings[0]!.status}"

  -- The second rule form. Without generalization the pattern `myDiv ?a 0` would not match
  -- `myDiv a b` at all, so this is the check that `generalizing` does something.
  let .ok divRule ← ruleOfTheorem? ``myDiv_zero "" #[2]
    | throwError "myDiv_zero should be readable as a rule once position 2 is generalized"
  unless divRule.generalize == #[2] do
    throwError "the generalization position was dropped, got {divRule.generalize}"

  -- Without it, the theorem has no hypothesis and is rejected outright — a rule that would
  -- otherwise match only a literal `myDiv a 0`.
  unless (← ruleOfTheorem? ``myDiv_zero) matches .error _ do
    throwError "a hypothesis-free equation with no generalization must be rejected"

  -- A position past the end of the explicit arguments is an error where it was written.
  unless (← ruleOfTheorem? ``myDiv_zero "" #[3]) matches .error _ do
    throwError "an out-of-range generalization position must be rejected"
  unless (← ruleOfTheorem? ``myDiv_zero "" #[0]) matches .error _ do
    throwError "generalization positions are 1-based, so 0 must be rejected"

  let divRules : RuleSet := ({} : RuleSet).insert divRule

  -- The guard is the equation generalization manufactured, instantiated at the actual divisor.
  let scan ← scanDecl divRules {} ``usesMyDiv
  unless scan.findings.size == 1 do
    throwError "expected one finding in `usesMyDiv`, got {scan.findings.size}"
  unless scan.findings[0]!.guards == #["b = 0"] do
    throwError "expected the guard `b = 0`, got {scan.findings[0]!.guards}"
  unless scan.findings[0]!.value == "0" do
    throwError "expected the default value `0`, got {scan.findings[0]!.value}"

  -- `b ≠ 0` in scope refutes that equation, so nothing is reported.
  let scan ← scanDecl divRules {} ``guardedDiv
  unless scan.findings.isEmpty do
    throwError "`b ≠ 0` should rule the collapse out, got {scan.findings.size} finding(s)"

  -- A hypothesis asserting the condition means the default is definitely taken.
  let scan ← scanDecl rs {} ``triggeredUse
  unless scan.findings.size == 1 do
    throwError "expected one finding in `triggeredUse`, got {scan.findings.size}"
  unless scan.findings[0]!.status matches .triggered _ do
    throwError "expected a triggered status, got {repr scan.findings[0]!.status}"


/-! ## Instance arguments, recursion, and dischargers that must not be believed

Regressions for bugs a synthetic example would never have shown; each was found by running the tool
over ordinary-looking probability code. -/

run_meta do
  let .ok opRule ← ruleOfTheorem? ``op_eq_zed_of_small
    | throwError "`op_eq_zed_of_small` should be readable as a rule"
  let rs : RuleSet := ({} : RuleSet).insert opRule

  -- Fires where the collapse really happens ...
  let scan ← scanDecl rs {} ``clampingUse
  unless scan.findings.size == 1 do
    throwError "expected the rule to fire at a clamping type, got {scan.findings.size} finding(s)"

  -- ... and NOT where the type merely has the operation. The rule's `[Clamped α]` argument is not
  -- determined by the pattern, so it has to be synthesized, and failing to synthesize it means the
  -- theorem does not apply. Reporting anyway is how every subtraction in `ℝ` and `ℤ` became a
  -- finding.
  let scan ← scanDecl rs {} ``nonClampingUse
  unless scan.findings.isEmpty do
    throwError "the rule must not fire at a type with no `Clamped` instance, got \
      {scan.findings.size} finding(s)"

  -- A recursive definition keeps its body in compiler-generated helpers, so the scan has to follow
  -- them — and report against the name somebody wrote, not against `countdown._f`.
  let scan ← scanDecl rs {} ``countdown
  unless scan.findings.size ≥ 1 do
    throwError "the occurrence inside the recursion was not found: a recursive definition's value \
      is a wrapper, and the body lives in its compiler-generated helpers"
  unless scan.findings.all (·.decl == ``countdown) do
    throwError "findings from a helper must be attributed to the declaration the author wrote"

run_meta do
  let .ok rule ← ruleOfTheorem? ``myOp_undef
    | throwError "myOp_undef should be readable as a junk-value rule"
  let rs : RuleSet := ({} : RuleSet).insert rule

  -- `usesMyOp` has nothing in scope that rules the collapse out, so *any* discharger that appears
  -- to prove `Good f` would silently dismiss a real finding. These two would.
  for (script, why) in
      [("sorry", "a discharger that proves anything"),
       ("skip", "a discharger that succeeds without closing the goal")] do
    let .ok tac ← tacticDischarger? script
      | throwError "`{script}` should parse as a tactic"
    let scan ← scanDecl rs { guard := { discharger := tac } } ``usesMyOp
    unless scan.findings.size == 1 do
      throwError "{why} (`{script}`) must not dismiss a finding, but `usesMyOp` came back clean"

  -- The discharger option is a `;;`-separated list precisely so that each alternative is judged on
  -- whether the goal is gone, rather than on whether it failed.
  let (_, problems) ← dischargerOf "skip ;; assumption"
  unless problems.isEmpty do
    throwError "both alternatives should parse, got {problems}"
  let (_, problems) ← dischargerOf "skip ;; not_a_tactic_at_all"
  unless problems.size == 1 do
    throwError "a misspelled alternative must be reported, not silently dropped"

  -- The per-declaration cap is a cap on the declaration, and reaching it is reported rather than
  -- silently truncating the list.
  let scan ← scanDecl rs { maxPerDecl := 1 } ``usesMyOp
  unless scan.truncated do throwError "reaching `maxPerDecl` must be reported"
  let scan ← scanDecl rs { maxPerDecl := 64 } ``usesMyOp
  if scan.truncated then throwError "a declaration well under the cap must not be marked truncated"

end JunkValues.Test
