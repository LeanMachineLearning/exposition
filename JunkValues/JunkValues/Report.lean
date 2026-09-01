module

public import Lean
public import Std.Data.HashMap
public import Std.Data.HashSet

@[expose] public section

/-!
# Findings: what the scan says, and what it refuses to say

A finding is not "this is a bug". It cannot be: whether `f + g` is integrable is a mathematical
question, and a linter that claimed to have settled it would be lying most of the time. A finding is
**evidence**, in the same sense the rest of this repository uses the word — here is a place where a
value collapses to a default, here is the condition under which it does, and here is what was tried
in order to rule that condition out.

That is why `Status` has three cases and not two. The one that matters is the middle one:

* `guarded` — the safety condition was *established*, from the declaration's own hypotheses or by a
  discharging tactic. Not reported by default; it is the answer to "did you look at this one".
* `unguarded` — nothing was established either way. **This is the finding.** It does not mean the
  term is junk; it means nothing in scope says it is not.
* `triggered` — the guard itself was established, so the default value is definitely taken. Rare,
  and much stronger than the other two: the term provably *is* the default.

## Why the strings

A `Finding` carries pretty-printed text rather than `Expr`s because the terms it describes live
under the binders of the declaration they were found in — `∫ y, f x y` inside `fun x => …` mentions
`x`, which is meaningless outside that scope. Rendering at the point of discovery, while the local
context is still in hand, is what makes a finding a value that can be put in a JSON file and read
somewhere else. It is the same reason `Referee.Highlight` stores rendered output rather than terms.

## Inherited risk

The user-facing request that motivated this tool was about *downstream* definitions: `B` uses an
integral that may be junk, and everything built on `B` inherits that. `inheritRisk` computes it, and
deliberately takes the dependency graph as a plain map rather than computing it, so that the caller
decides which edges count — statement-only edges for a theorem, statement-and-proof for a
definition. That is the same division of labour `MeaningGraph` makes for its own graph passes, and
for the same reason.
-/

open Lean

namespace JunkValues

/-- What was established about a junk-value occurrence. See the module docstring: the three cases
are "ruled out", "nothing known", and "definitely taken", and only the middle one is a finding. -/
inductive Status where
  /-- The safety condition was established — the value is not the default here. `how` names what
  established it (`"hypothesis hf"`, `"fun_prop"`, …). -/
  | guarded (how : String)
  /-- Neither the guard nor its negation could be established. The reportable case. -/
  | unguarded
  /-- The guard itself was established: this term *is* the default value. -/
  | triggered (how : String)
deriving Repr, Inhabited, BEq, ToJson, FromJson

/-- A short machine-readable tag, for grouping and for CSS classes on a rendered page. -/
def Status.slug : Status → String
  | .guarded _ => "guarded"
  | .unguarded => "unguarded"
  | .triggered _ => "triggered"

/-- Whether this status is worth putting in front of a reader. `guarded` occurrences are kept in the
data (they are the evidence that the scan looked) but are not findings. -/
def Status.isFinding : Status → Bool
  | .guarded _ => false
  | .unguarded | .triggered _ => true

/-- Which part of a declaration an occurrence was found in.

The distinction is not cosmetic, because the two carry different risks. In a **statement**, a junk
value is a *vacuity* risk: the theorem may be true for no reason, both sides having collapsed. In a
**body**, it is a *meaning* risk: the definition denotes something other than what its name says,
and every theorem about it inherits that. A reader triaging findings wants these apart. -/
inductive Site where
  /-- In the declaration's type: a vacuity risk. -/
  | statement
  /-- In the declaration's value: a meaning risk. -/
  | body
deriving Repr, Inhabited, BEq, DecidableEq, Hashable, ToJson, FromJson

/-- A short machine-readable tag. -/
def Site.slug : Site → String
  | .statement => "statement"
  | .body => "body"

/-- One place where a value may collapse to a default.

Everything is pre-rendered text; see the note on why in the module docstring. -/
structure Finding where
  /-- The declaration the occurrence was found in. -/
  decl : Name
  /-- Statement or body — vacuity risk or meaning risk. -/
  site : Site
  /-- The theorem the rule was read off, so a reader can check the claim being made about the
  default rather than taking this tool's word for it. -/
  rule : Name
  /-- The operation that has the junk value (`MeasureTheory.integral`, `deriv`, …). -/
  head : Name
  /-- The matched subterm, as it reads in the declaration. -/
  term : String
  /-- The conditions under which the value collapses, instantiated at this occurrence. This is the
  sentence the reader was promised: *if `f + g` is not integrable, then …* -/
  guards : Array String
  /-- What the value collapses to. Usually `0`, not always — see `klDiv` in the catalogue. -/
  value : String
  /-- What was established, and how. -/
  status : Status
  /-- The rule's note on what this default costs. Empty when the rule carries none. -/
  note : String := ""
deriving Repr, Inhabited, ToJson, FromJson

/-- The finding as one line of prose, which is the form the original request asked for:

> `if ¬Integrable (fun x => f x + g x) μ then ∫ (x : α), (f x + g x) ∂μ = 0`

Kept here rather than in a frontend because every frontend wants it and they should not each
reinvent the phrasing. -/
def Finding.message (f : Finding) : String :=
  let conds := String.intercalate " and " f.guards.toList
  let head := s!"if {conds} then {f.term} = {f.value}"
  let prov := s!" (by {f.rule})"
  let note := if f.note.isEmpty then "" else s!" — {f.note}"
  match f.status with
  | .unguarded => head ++ prov ++ note
  | .triggered how => s!"{f.term} = {f.value}: the condition holds ({how}){prov}{note}"
  | .guarded how => s!"not at risk ({how}): {head}{prov}"

/-- Every declaration reachable from `decl` in `deps` that has a reportable finding of its own.

This is the "downstream definitions" half of the request: `B` integrates something that may not be
integrable, so `C`, which is defined in terms of `B`, is at risk too — without any junk-value
operation appearing in `C` itself.

`deps` is the *transitive* dependency map, keyed by declaration; the caller chooses which edges it
was built from. Nothing here is transitive on its own, deliberately: making this function walk the
graph would mean it also had to decide what a cycle means, and the callers that have a graph already
have it closed. -/
def inheritRisk (deps : Std.HashMap Name (Array Name)) (atRisk : Std.HashSet Name)
    (decl : Name) : Array Name :=
  (deps.getD decl #[]).filter atRisk.contains

/-- The declarations with at least one reportable finding — the set `inheritRisk` is asked about. -/
def riskySet (findings : Array Finding) : Std.HashSet Name :=
  findings.foldl (init := ∅) fun acc f =>
    if f.status.isFinding then acc.insert f.decl else acc

end JunkValues
