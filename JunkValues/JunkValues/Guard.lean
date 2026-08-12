module

public import Lean
public import Lean.Elab.Tactic.Meta
public import JunkValues.Report

@[expose] public section

/-!
# Discharging: deciding whether an occurrence is already ruled out

Finding `∫ x, (f x + g x) ∂μ` in a declaration is the easy half. The half that decides whether the
tool is usable is the next question: **is `f + g` integrable here?** A tool that reports every
integral in a measure theory development has reported nothing.

The answer is usually in the declaration's own hypotheses, but almost never *literally*. A theorem
assuming `Integrable f μ` and `Integrable g μ` and integrating `f + g` is fine, and saying so needs
`Integrable.add` — which is to say, it needs a *tactic*, not a lookup.

## Two dischargers, and why the second one is a string

`assumptionDischarger` is the lookup: is the safety condition, up to defeq, one of the hypotheses in
scope. Cheap, needs nothing beyond Lean core, and names the hypothesis it found so the report can
say *why* an occurrence was dismissed.

`tacticDischarger` is the real one, and it takes the tactic as **source text** — `"fun_prop"`,
`"assumption"`, `"simp_all"`, `"measurability"`. That is not laziness: `fun_prop` is Mathlib's
tactic for exactly this class of goal (`Integrable`, `Measurable`, `Continuous`, `Differentiable`,
and it knows `Integrable.add`), and naming it as a constant here would make this package depend on
Mathlib, which the whole design refuses. A string is parsed against the environment being scanned,
so the tactic resolves if and only if the project being analysed imports it — and fails with a clear
message rather than a silent miss when it does not.

The consequence worth stating plainly: **on a project without `fun_prop`, this tool over-reports.**
That is the honest direction to fail in, but it is a real cost, and it is why the parse failure is
surfaced rather than swallowed.

## Why "safe" is the negation of the guard

A rule fires under `g₁ → … → gₙ → term = default`. The term is *safe* as soon as any one `gᵢ` is
false — refuting one hypothesis is enough to block the implication — and it is *definitely* the
default only when every `gᵢ` holds. Both directions are asymmetric in cost and in what they mean, so
`classify` runs them separately and reports which one landed.
-/

open Lean Meta

namespace JunkValues

/-- A way of trying to prove a goal in the local context of an occurrence.

`prove` returns a *description* of what proved the goal rather than a boolean, so that a dismissed
occurrence can say `"hypothesis hfg"` instead of `"trust me"`. That description is the only thing
standing between "the tool checked this" and "the tool skipped this", and the two are worth
distinguishing in the output. -/
structure Discharger where
  /-- Name of the strategy, for reports and for the default description. -/
  name : String
  /-- Try to prove `goal` in the ambient local context. `none` on failure. -/
  prove : Expr → MetaM (Option String)

/-- The proposition whose truth makes an occurrence safe: the negation of the guard, with double
negation and `Ne` collapsed so that the goal handed to a tactic is the one a human would write.

Without the collapse, a guard `¬Integrable f μ` would produce the goal `¬¬Integrable f μ`, which
`fun_prop` does not solve — the tactic knows integrability, not classical logic. -/
def safetyGoal (guard : Expr) : Expr :=
  match guard with
  | .app (.const ``Not []) p => p
  | .app (.app (.app (.const ``Ne us) α) a) b => mkAppN (.const ``Eq us) #[α, a, b]
  | g => .app (.const ``Not []) g

/-- Prove a goal from the hypotheses in scope, up to definitional equality, and name the hypothesis
that did it.

This is `assumption` with a report attached, and it is written out rather than delegated to the
tactic so that it works with no tactic framework and so that the hypothesis's *user-facing* name
reaches the finding. Implementation-detail and inaccessible hypotheses are skipped: naming one in a
report tells the reader nothing they can act on. -/
def assumptionDischarger : Discharger where
  name := "assumption"
  prove := fun goal => do
    for decl in ← getLCtx do
      if decl.isImplementationDetail then continue
      if ← isDefEq decl.type goal then
        let shown := if decl.userName.hasMacroScopes then "an anonymous hypothesis"
          else s!"hypothesis `{decl.userName}`"
        return some shown
    return none

/-- Run a tactic, given as source text, against the goal.

Parsed once at construction (`tacticDischarger?`) rather than per goal, both for speed and so that a
tactic that does not exist in the environment being scanned is one error at start-up instead of a
scan that quietly finds too much.

Every attempt runs under `withoutModifyingState`, so a tactic that partially solves the goal, or
assigns metavariables on its way to failing, cannot leak that into the next occurrence. Failure —
including elaboration errors and `sorry`-producing tactics — is `none`. -/
def tacticDischarger (label : String) (tac : Syntax) : Discharger where
  name := label
  prove := fun goal => withoutModifyingState do
    try
      -- A fresh heartbeat budget per occurrence: a scan visits thousands of goals, and without this
      -- the first slow one aborts every later one under a shared budget.
      Core.withCurrHeartbeats do
        let goalMVar ← mkFreshExprMVar goal
        let (remaining, _) ← Lean.Elab.runTactic goalMVar.mvarId! tac
        if remaining.isEmpty && !(← instantiateMVars goalMVar).hasSorry then
          return some label
        else
          return none
    catch _ => return none

/-- Build a `Discharger` from tactic source text, reporting a parse failure rather than degrading
into a discharger that never succeeds.

The error is a `String` and not a thrown exception because the caller — a CLI, a `#junk_check`
command — is better placed to say what to do about it than this function is. -/
def tacticDischarger? (script : String) : MetaM (Except String Discharger) := do
  match Parser.runParserCategory (← getEnv) `tactic script with
  | .error msg =>
    return .error s!"could not parse `{script}` as a tactic: {msg}. If this is a Mathlib tactic \
      (`fun_prop`, `measurability`), the project being scanned has to import it."
  | .ok stx => return .ok (tacticDischarger script stx)

/-- Try each discharger in turn, stopping at the first success. -/
def firstDischarger (ds : Array Discharger) : Discharger where
  name := String.intercalate " / " (ds.toList.map (·.name))
  prove := fun goal => do
    for d in ds do
      if let some how ← d.prove goal then return some how
    return none

/-- What to try, and how hard, when deciding whether an occurrence is at risk. -/
structure GuardConfig where
  /-- How to prove the safety condition. Defaults to hypothesis lookup alone, which needs no tactic
  framework; a frontend that knows the project imports Mathlib should add `fun_prop`. -/
  discharger : Discharger := assumptionDischarger
  /-- Also try to prove the guard *itself*, turning an occurrence into `triggered` when it succeeds.
  Worth having — a declaration whose hypotheses include `¬Integrable f μ` and which then integrates
  `f` is a much stronger finding than an unguarded one — but it doubles the discharge work, so a
  scan of a large library may want it off. -/
  checkTriggered : Bool := true

/-- Decide the status of an occurrence from its guards.

Order matters and is not arbitrary: safety is checked first because it is the common case and the
cheap one, and because an occurrence that is safe is not made interesting by also happening to have
a provable guard. -/
def classify (guards : Array Expr) (cfg : GuardConfig := {}) : MetaM Status := do
  -- Refuting a single guard blocks the implication, so any one suffices.
  for g in guards do
    if let some how ← cfg.discharger.prove (safetyGoal g) then
      return .guarded how
  if cfg.checkTriggered && !guards.isEmpty then
    let mut how? := none
    for g in guards do
      match ← cfg.discharger.prove g with
      | some how => how? := how? <|> some how
      | none => return .unguarded
    return .triggered (how?.getD cfg.discharger.name)
  return .unguarded

end JunkValues
