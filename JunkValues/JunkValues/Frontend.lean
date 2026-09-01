module

public import JunkValues.Scan
public import Lean.Elab.Command

@[expose] public section

/-!
# Frontends: the linter, the commands, and the batch scan

Three ways in, for three different moments.

* **`linter.junkValues`** — warnings while you write, on the declaration you just wrote. This is the
  form the tool was asked for: *`B` uses the integral of `f + g`; if `f + g` is not integrable, that
  is `0`.* Off by default, because turning it on for a whole existing development at once produces
  a wall of true-but-unactioned findings; it is meant to be switched on per file, or per project once
  the backlog is dealt with.
* **`#junk_check f`** — the same analysis on demand, for one declaration or a whole namespace, with
  no commitment to keeping the file clean. This is what triage uses.
* **`scanProject`** — every declaration of a compiled project, for a tool that imports the project
  and writes a report. Referee is the intended consumer.

## Why the linter is off by default

Because the finding it produces is not an error. `unguarded` means nothing in scope rules the
collapse out, and on a first run over a real measure-theory development that is true of a great many
terms which are perfectly fine. A linter that is on by default and wrong most of the time gets
switched off permanently within a day. Off by default, switched on deliberately, and paired with a
discharger strong enough to clear the easy cases is the only version of this that survives contact
with a real project.

## The discharger option

`set_option linter.junkValues.discharger "fun_prop ;; norm_num"` is doing most of the work in any
project where this tool is useful, and the default (`""`, hypothesis lookup only) is the version that
needs no Mathlib. See `Guard.lean` for why it is source text rather than a fixed strategy, and
`dischargerOf` below for why several tactics are separated by `;;` rather than written as one
`first | … | …` — that distinction was a real bug, not a stylistic preference.
-/

open Lean Elab Command Meta

namespace JunkValues

register_option linter.junkValues : Bool := {
  defValue := false
  descr := "warn when a declaration uses an operation that collapses to a default value without \
    the condition for that collapse being ruled out"
}

register_option linter.junkValues.discharger : String := {
  defValue := ""
  descr := "alternative tactics for ruling out a junk value's condition, separated by `;;` and tried in \
    order, each of which must close the goal by itself — e.g. `fun_prop ;; norm_num`. Empty means \
    hypothesis lookup only. Tactics must exist in the file being checked; see `Frontend.lean` for \
    why this is a list rather than one `first | … | …`."
}

/-- Separator between alternative tactics in the discharger option. -/
def dischargerSeparator : String := ";;"

/-- Build the discharger a frontend should use: hypothesis lookup, plus the configured tactics.

The option may name **several** tactics separated by `;;`, tried in order, each of which has to close
the goal by itself. That is not the same as writing `first | a | b` in one tactic, and the difference
is not academic — it is a bug this package shipped for about an hour.

`first` commits to the first alternative that does not *fail*, and a tactic can succeed without
closing the goal. `first | assumption | norm_num | fun_prop` on `Integrable (fun a => f a + g a) μ`
commits to `norm_num`, which rewrites something, closes nothing, and never lets `fun_prop` run — so
a declaration that was correctly dismissed before becomes a false finding, and the only symptom is
that the tool reports slightly more. Splitting here instead means each alternative is judged on
whether the goal is *gone*, which is the only success condition that matters.

A tactic that does not parse is reported to the caller rather than dropped, so that a misspelled
`fun_prpo` is not silently a scan with no discharger at all. -/
def dischargerOf (script : String) : MetaM (Discharger × Array String) := do
  let scripts := (script.splitOn dischargerSeparator).map (·.trimAscii.toString) |>.filter (!·.isEmpty)
  let mut dischargers := #[assumptionDischarger]
  let mut problems := #[]
  for one in scripts do
    match ← tacticDischarger? one with
    | .ok tac => dischargers := dischargers.push tac
    | .error msg => problems := problems.push msg
  return (firstDischarger dischargers, problems)

/-- Assemble rules and configuration from the ambient options. Shared by every frontend so that
`#junk_check` and the linter cannot disagree about what they are checking.

Which rule sources run is not decided here: it is decided by what the file being checked imported.
See `RuleSet.lean`. -/
def setupOf (opts : Options) : MetaM (RuleSetReport × ScanConfig × Array String) := do
  let (discharger, dischargerProblems) ← dischargerOf (linter.junkValues.discharger.get opts)
  let report ← RuleSet.ofEnv opts
  return (report, { guard := { discharger } }, report.warnings ++ dischargerProblems)

/-! ## The linter -/

/-- Every `declId` in a command's syntax, resolved against the current namespace.

Best-effort by construction: it reads the names off the syntax tree rather than diffing the
environment, so a declaration introduced by a macro that does not expand to a visible `declId` — and
every auto-generated companion — is not linted. That is the right trade for a linter, which should
say something about what the author *wrote*; the batch scan is what covers everything. -/
def declIdsOf (stx : Syntax) : CommandElabM (Array Name) := do
  let ns ← getCurrNamespace
  let env ← getEnv
  let mut out := #[]
  for node in stx.topDown do
    if node.getKind == ``Lean.Parser.Command.declId then
      if node[0].isIdent then
        let id := node[0].getId
        -- Try the name as written and inside the current namespace; keep whichever exists.
        for candidate in #[ns ++ id, id] do
          if env.contains candidate && !out.contains candidate then
            out := out.push candidate
            break
  -- A `where` clause elaborates to a *sibling declaration* (`viaWhere.aux`) with no `declId` of its
  -- own, so the loop above cannot see it — and it is where the author's code actually went:
  --
  --     noncomputable def viaWhere (f : Ω → ℝ) : ℝ := aux f
  --       where aux (g : Ω → ℝ) : ℝ := ∫ ω, g ω ∂μ
  --
  -- Linting `viaWhere` alone reported nothing at all. So anything nested under a name this command
  -- declared is linted too. Iterating `constants.map₂` rather than `constants` is what makes this
  -- affordable: `map₂` is the current module's declarations only, tens of names, where the full map
  -- is every constant Mathlib has.
  --
  -- Compiler-generated helpers are excluded here rather than linted separately, because `scanDecl`
  -- already follows them and reports them against the declaration somebody wrote.
  let declared := out
  for (name, _) in env.constants.map₂ do
    if isCompilerGenerated name then continue
    if out.contains name then continue
    if declared.any (·.isPrefixOf name) then
      out := out.push name
  return out

/-- Render one finding as the warning text. -/
def warningOf (f : Finding) : MessageData :=
  let site := match f.site with
    | .statement => "in the statement of"
    | .body => "in the definition of"
  m!"junk value {site} `{f.decl}`: {f.message}"

/-- The linter: after each declaration, report the junk values it uses that nothing in scope rules
out.

Assembly failures (`RuleSetReport.warnings`) are reported once per command alongside the findings.
They are not findings and would ideally be said once per file, but a `Linter` has no per-file hook,
and saying them repeatedly is much better than the alternative of a scan quietly checking less than
the author thinks. -/
def junkValuesLinter : Linter where
  run := fun stx => do
    let opts ← getOptions
    unless linter.junkValues.get opts do return
    if (← get).messages.hasErrors then return
    let names ← declIdsOf stx
    if names.isEmpty then return
    liftTermElabM do
      let (report, cfg, warnings) ← setupOf opts
      for w in warnings do
        Linter.logLint linter.junkValues stx m!"{w}"
      for name in names do
        let scan ← scanDecl report.ruleSet cfg name
        for f in scan.findings do
          Linter.logLint linter.junkValues stx (warningOf f)
        if scan.truncated then
          Linter.logLint linter.junkValues stx
            m!"`{name}` has more junk-value occurrences than the scan's limit; the list above is \
              incomplete"

initialize addLinter junkValuesLinter

/-! ## Batch scan -/

/-- Every declaration a project's author actually wrote, in modules under `rootPrefix`.

A local, deliberately simple version of the classification `MeaningGraph.shouldExpose` does
properly — this package does not depend on that one either. A consumer that already has
`MeaningGraph` should pass its own list to `scanDecls` instead of using this. -/
def projectDecls (env : Environment) (rootPrefix : Name) : Array Name := Id.run do
  let mut out := #[]
  for idx in [0:env.header.modules.size] do
    let modName := env.header.modules[idx]!.module
    unless rootPrefix.isPrefixOf modName do continue
    for name in env.header.moduleData[idx]!.constNames do
      unless name.isInternal || name.isImplementationDetail || isPrivateName name do
        out := out.push name
  return out

/-- Scan a whole compiled project. The entry point for a tool that imports the project and writes a
report rather than warning in an editor.

Which rule sources run is decided by what the *calling process* imported, not by an argument here:
a tool that wants Mathlib's catalogue imports `JunkValues.Extra.Catalogue`. See `RuleSet.lean`. -/
def scanProject (rootPrefix : Name) (cfg : ScanConfig := {}) (opts : Options := {}) :
    MetaM (RuleSetReport × Array DeclScan × Array (Name × String)) := do
  let report ← RuleSet.ofEnv opts
  let names := projectDecls (← getEnv) rootPrefix
  let (scans, failed) ← scanDecls report.ruleSet cfg names
  return (report, scans, failed)

end JunkValues
