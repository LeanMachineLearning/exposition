module

public import JunkValues.RuleSet

@[expose] public section

/-!
# Catalogue entries: the shared machinery, registering nothing

A *catalogue* is a hand-written list of upstream theorems that exhibit junk values, resolved against
whatever environment is being scanned. There is more than one — `Extra/Catalogue.lean` holds the
analytic ones, `Extra/Arithmetic.lean` the arithmetic ones — and this module is what they share.

## Why this module exists at all

Because a rule source is switched on by *importing* it, and that promise is only true if the sources
can be imported independently. When `Extra/Arithmetic.lean` took its entry type straight from
`Extra/Catalogue.lean`, importing the arithmetic rules also ran the analytic catalogue's
`initialize` block and switched it on — 35 rules where 13 were asked for. The granularity was a
claim in the documentation and not a fact about the code.

So the types and the resolver live here, where nothing registers itself, and each catalogue module
registers exactly its own provider. The rule to keep: **anything shared between two rule sources
belongs in a module with no `initialize` block in it.**
-/

open Lean Meta

namespace JunkValues

/-- One catalogue entry: an upstream theorem exhibiting a junk value, and what that default costs.

Every entry names its theorem as an unresolved `Name` *literal*, never a `` `` `` quotation, so this
package still compiles against Lean core alone and a project depending on it does not thereby depend
on Mathlib. Names are resolved against the environment being scanned. -/
structure CatalogueEntry where
  /-- The theorem, as an unresolved name. -/
  theoremName : Name
  /-- What the default costs a reader who did not notice it. Shown with every finding. -/
  note : String := ""
  /-- Explicit argument positions of the pattern to generalize, for an entry whose theorem states
  its condition by specialising an argument rather than by a hypothesis (`div_zero`). 1-based; see
  `Rule.lean`. -/
  generalize : Array Nat := #[]
deriving Repr, Inhabited, BEq

/-- What resolving a catalogue against an environment found, and what it could not.

The two failure kinds are kept apart because they mean different things. An **unresolved** entry
names a constant this environment does not have — renamed upstream, or in a module the project does
not import, and the second case is often benign. A **rejected** entry still exists but no longer has
the rule shape, which is the more dangerous of the two precisely because the name still resolves and
nothing else would notice. -/
structure CatalogueCheck where
  rules : Array JunkRule := #[]
  /-- Entries naming a constant this environment does not have. -/
  unresolved : Array Name := #[]
  /-- Entries that resolve but are no longer junk-value rules, with the reason. -/
  rejected : Array (Name × String) := #[]
deriving Inhabited

/-- Resolve every catalogue entry against the environment in hand.

This is also a catalogue's own verification: it is what keeps a "verified against Mathlib `…`" line
from being a claim nobody re-checks. Run it inside a project that has Mathlib and both failure lists
should be empty. -/
def checkCatalogue (catalogue : Array CatalogueEntry) : MetaM CatalogueCheck := do
  let mut result : CatalogueCheck := {}
  for entry in catalogue do
    if (← getEnv).find? entry.theoremName |>.isNone then
      result := { result with unresolved := result.unresolved.push entry.theoremName }
    else
      match ← ruleOfTheorem? entry.theoremName entry.note entry.generalize with
      | .ok rule => result := { result with rules := result.rules.push rule }
      | .error why =>
        result := { result with rejected := result.rejected.push (entry.theoremName, why) }
  return result

/-- Turn a catalogue into a rule source, with its failures rendered as reader-facing prose.

Both failure kinds say *the junk values it covers are not being checked*, in as many words, because
the whole hazard of a rotting catalogue is that it degrades into a scan that looks like it is
working. -/
def catalogueProvider (name : String) (catalogue : Array CatalogueEntry) : RuleProvider where
  name := name
  run := fun _ => do
    let check ← checkCatalogue catalogue
    let mut problems := #[]
    for missing in check.unresolved do
      problems := problems.push s!"{name} entry `{missing}` does not resolve in this environment: \
        it was renamed upstream, or the project does not import the module defining it. The junk \
        values it covers are NOT being checked."
    for (changed, why) in check.rejected do
      problems := problems.push s!"{name} entry `{changed}` exists but is no longer a junk-value \
        rule: {why}. The junk values it covers are NOT being checked."
    return { rules := check.rules, problems }

end JunkValues
