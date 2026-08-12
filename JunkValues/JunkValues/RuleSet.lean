module

public import JunkValues.Registry
public import Std.Data.HashMap

@[expose] public section

/-!
# Assembling the rules a scan runs with

The core answer is short: **the rules are the ones the project annotated with `@[junk_value]`**.
That is the whole of it, and a project that annotates its own definitions needs nothing else in this
file.

Everything beyond that — rules for Mathlib's junk values, rules found automatically by shape — is
optional, lives in `JunkValues/Extra/`, and reaches a scan through the registry below rather than by
this module knowing anything about it.

## Why a provider registry rather than a flag

Because the dependency has to point the other way. If `RuleSet.ofEnv` named the catalogue, then core
would depend on a list of Mathlib theorem names, and a project that just wants to lint its own
definitions would carry that list and the argument for it. Instead:

* core defines what a rule *source* is (`RuleProvider`) and consults whichever ones are registered;
* `Extra/Catalogue.lean` and `Extra/Discovery.lean` register themselves in an `initialize` block.

So **a rule source is switched on by importing it**. `import JunkValues` gives the annotation
attribute and the linter over the project's own rules; `import JunkValues.Extra.Catalogue` adds
Mathlib's. Nothing has to be passed through the linter's configuration, because the import already
said it. This is the same mechanism Lean itself uses to register linters, and it fails in the
readable direction: forget the import and you get fewer rules, never wrong ones.

## Failure is returned, not swallowed

A provider hands back its rules *and* an account of what it could not assemble — a catalogue entry
that no longer resolves, a tactic that will not parse. Both are how a rule set rots, and both are
invisible at the only moment they matter, which is when a scan quietly stops finding a class of
problem it used to find. So they are part of the return type rather than a log line, and every
frontend prints them.

## No `DiscrTree`

Rules are indexed by head constant into a `HashMap`, not by a discrimination tree. With rules in the
dozens and the head symbol already selecting all but a handful, a `DiscrTree` would buy a filter on
candidates that unification rejects in microseconds anyway. If a project ever registers hundreds of
rules about the same operation this is the thing to change, and `JunkRule` already carries the
`arity` pre-filter that would become the first key of such a tree.
-/

open Lean Meta

namespace JunkValues

/-- Rules indexed by the head constant of their pattern. -/
structure RuleSet where
  /-- Rules keyed by `JunkRule.head`. -/
  byHead : Std.HashMap Name (Array JunkRule) := ∅
  /-- Every rule, in the order the sources were folded. Kept for reporting what a scan ran with. -/
  rules : Array JunkRule := #[]
deriving Inhabited

/-- Add a rule, ignoring one whose source theorem is already present. Earlier sources therefore win,
which is what makes registration order a priority order: a project's own `@[junk_value]` note on a
theorem survives an optional source naming the same theorem. -/
def RuleSet.insert (rs : RuleSet) (rule : JunkRule) : RuleSet :=
  if rs.rules.any (·.source == rule.source) then rs
  else
    { byHead := rs.byHead.alter rule.head fun
        | some existing => some (existing.push rule)
        | none => some #[rule],
      rules := rs.rules.push rule }

/-- Rules that could fire on an application of `head`. -/
def RuleSet.forHead (rs : RuleSet) (head : Name) : Array JunkRule :=
  rs.byHead.getD head #[]

/-- What one optional rule source contributed. -/
structure ProviderResult where
  rules : Array JunkRule := #[]
  /-- What this source could not assemble, in reader-facing prose. Never empty for a source that
  silently found less than it should have — see the module docstring. -/
  problems : Array String := #[]
deriving Inhabited

/-- A source of rules other than the project's own `@[junk_value]` annotations.

`run` takes the ambient options so that a source can be switched off without being unimported —
discovery is expensive and reads `linter.junkValues.discovery`. A source that is unconditional
ignores them. -/
structure RuleProvider where
  /-- Short name, shown by `#junk_rules` next to what this source contributed. -/
  name : String
  /-- The rules, and anything that went wrong assembling them. -/
  run : Options → MetaM ProviderResult

/-- Every registered optional rule source, in registration order.

An `IO.Ref` rather than an environment extension because registration happens when a module is
*imported into the running process* (its `initialize` block runs), which is exactly the semantics
wanted: importing `JunkValues.Extra.Catalogue` switches the catalogue on for this process. The same
mechanism Lean uses for `addLinter`. -/
initialize ruleProviders : IO.Ref (Array RuleProvider) ← IO.mkRef #[]

/-- Register an optional rule source. Call from an `initialize` block in the module that defines it,
so that importing that module is what switches it on. -/
def registerRuleProvider (provider : RuleProvider) : IO Unit :=
  ruleProviders.modify (·.push provider)

/-- What assembling a rule set found, and what it could not. -/
structure RuleSetReport where
  ruleSet : RuleSet := {}
  /-- How many rules each source contributed, after deduplication, in registration order. Reported
  because "22 rules" and "22 rules, 21 of which nobody vouched for" are different situations. -/
  contributions : Array (String × Nat) := #[]
  /-- Everything any source could not assemble. -/
  problems : Array String := #[]
deriving Inhabited

/-- Lines a frontend should print before a scan's results. Empty when everything assembled. -/
def RuleSetReport.warnings (r : RuleSetReport) : Array String := r.problems

/-- Assemble the rule set: the project's own annotations first, then every registered optional
source in registration order.

Annotations come first because `RuleSet.insert` keeps the first rule for a given source theorem, so
a project that annotates a theorem an optional source also names gets its own note on the findings
rather than the imported one. -/
def RuleSet.ofEnv (opts : Options := {}) : MetaM RuleSetReport := do
  let mut ruleSet : RuleSet := {}
  for rule in declaredRules (← getEnv) do
    ruleSet := ruleSet.insert rule
  let mut report : RuleSetReport :=
    { ruleSet, contributions := #[("@[junk_value]", ruleSet.rules.size)] }
  for provider in ← ruleProviders.get do
    let result ← provider.run opts
    let before := report.ruleSet.rules.size
    let mut extended := report.ruleSet
    for rule in result.rules do
      extended := extended.insert rule
    report := {
      ruleSet := extended
      contributions := report.contributions.push (provider.name, extended.rules.size - before)
      problems := report.problems ++ result.problems }
  return report

end JunkValues
