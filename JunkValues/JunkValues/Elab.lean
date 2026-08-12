module

public import JunkValues.Frontend
public import Lean.Elab.Command
-- The linter and the two commands are *meta* declarations: they run during elaboration of the file
-- being checked, not at its runtime. Under the module system a `meta` definition may only use
-- definitions available at the meta phase, so everything they call has to be imported twice — once
-- for each phase. This is the same double import `Test/Deps.lean` needs for its `#guard`s.
meta import JunkValues.Frontend
meta import Lean.Elab.Command

@[expose] public section

/-!
# The editor-facing frontends: the linter and the two commands

Split from `Frontend.lean` for a reason the module system imposes rather than a design one: a
`meta def` cannot call a definition from its own module, so the elaborators cannot live beside the
configuration helpers they use. The division is worth stating anyway, because it is real — this
module is everything that runs *while a file is being elaborated*, and `Frontend.lean` is everything
that runs when a compiled project is analysed from outside.
-/

open Lean Elab Command Meta

namespace JunkValues

/-! ## Commands -/

/-- `#junk_check f` reports the junk values `f` uses, whether or not the linter is on.

With a namespace rather than a declaration it checks everything under it, which is the form triage
uses: `#junk_check MyProject.Chapter3`. -/
syntax (name := junkCheckCmd) "#junk_check" (ppSpace ident)? : command

@[command_elab junkCheckCmd]
meta def elabJunkCheck : CommandElab := fun stx => do
  let opts ← getOptions
  let target? := stx[1].getOptional?.map (·.getId)
  liftTermElabM do
    let (report, cfg, warnings) ← setupOf opts
    for w in warnings do logWarning m!"{w}"
    let env ← getEnv
    let names : Array Name ←
      match target? with
      | none => throwError "`#junk_check` needs a declaration or namespace to check"
      | some target =>
        if env.contains target then pure #[target]
        else
          -- A namespace: everything under it that a human wrote.
          let mut out := #[]
          for (name, info) in env.constants do
            if target.isPrefixOf name && !name.isInternal && !name.isImplementationDetail
                && !(info matches .ctorInfo _ | .recInfo _) then
              out := out.push name
          if out.isEmpty then
            throwError "`{target}` is neither a declaration nor a namespace with declarations in it"
          -- Sorted so that repeated runs are comparable; `env.constants` iterates in hash order.
          pure (out.qsort (·.toString < ·.toString))
    let (scans, failed) ← scanDecls report.ruleSet cfg names
    for (name, why) in failed do
      logWarning m!"could not scan `{name}`: {why}"
    if scans.isEmpty then
      logInfo m!"no junk values found in {names.size} declaration(s), with \
        {report.ruleSet.rules.size} rules"
    else
      let mut msg := m!""
      for scan in scans do
        for f in scan.findings do
          msg := msg ++ warningOf f ++ m!"\n"
      logInfo (msg ++ m!"\n{scans.size} of {names.size} declaration(s), \
        {report.ruleSet.rules.size} rules")

/-- `#junk_rules` lists the rules a scan would run with here, where each came from, and everything
that failed to assemble.

The command to run when a scan reports less than expected — most often because an optional rule
source was never imported, which this shows as a source contributing nothing (or not appearing at
all). -/
syntax (name := junkRulesCmd) "#junk_rules" : command

@[command_elab junkRulesCmd]
meta def elabJunkRules : CommandElab := fun _ => do
  let opts ← getOptions
  liftTermElabM do
    let report ← RuleSet.ofEnv opts
    for w in report.warnings do logWarning m!"{w}"
    let mut msg := m!"{report.ruleSet.rules.size} junk-value rules in scope"
    let sources := report.contributions.filter (·.2 > 0)
    if sources.isEmpty then
      msg := msg ++ m!".\n\nNothing has annotated a junk value with `@[junk_value]`, and no \
        optional rule source is imported. For Mathlib's junk values, add \
        `import JunkValues.Extra` — see `JunkValues/Extra.lean`.\n"
    else
      let from_ := ", ".intercalate (sources.toList.map fun (n, k) => s!"{k} from {n}")
      msg := msg ++ m!" ({from_}):\n"
      for rule in report.ruleSet.rules do
        msg := msg ++ m!"  {rule.head} (arity {rule.arity})  ←  {rule.source}\n"
    logInfo msg

end JunkValues
