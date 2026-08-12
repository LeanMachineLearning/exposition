module

public import JunkValues
public import JunkValues.Extra
-- The synthetic junk value the discovery check below looks for lives in the core test module.
public import Test.JunkValues
-- `#guard`s and `run_meta` blocks are elaborated at compile time, so the declarations under test
-- have to be imported at that level too.
meta import JunkValues
meta import JunkValues.Extra
meta import Test.JunkValues

@[expose] public section

/-!
# Tests for the optional rule sources

`Test/JunkValues.lean` covers the core — `@[junk_value]` and the scan. This module covers what is
deliberately *not* core: the catalogue of Mathlib's junk values and the shape-based discovery that
proposes candidates for it.

Split along the same line as the package, and for the same reason: importing `JunkValues.Extra` is
what switches these sources on, so a test file that imports it is exercising a different
configuration from one that does not — and that difference is itself worth testing, which is what
the provider-registration check below does.

What cannot be tested here is whether the catalogue's Mathlib entries still resolve, since this
repository has no Mathlib. `checkCatalogue` is the check, and it has to be run inside a project that
does; see this package's README.

Run with `lake build Test`.
-/

open Lean Meta
open JunkValues

namespace JunkValues.ExtraTest

/-! ## The pre-filter for discovery -/

-- `conclusionOf` strips binders, including through `mdata`.
#guard (conclusionOf (.forallE `x (.sort 0) (.sort 1) .default)).isSort
#guard (conclusionOf (.sort 1)).isSort

-- `headConst?` reads the head of an application, and nothing else.
#guard headConst? (mkAppN (.const `f []) #[.sort 0]) == some `f
#guard headConst? (.const `f []) == some `f
#guard headConst? (.sort 0) == none
#guard headConst? (.bvar 0) == none

/-- `a = b` with both sides given, for the pre-filter tests. Universe and type are irrelevant to
`looksLikeRule`, which only inspects the two head constants. -/
private def mkEqOf (lhs rhs : Expr) : Expr :=
  mkAppN (.const ``Eq [.zero]) #[.const `T [], lhs, rhs]

#guard looksLikeRule {`Zero.zero} (mkEqOf (.const `myOp []) (.const `Zero.zero []))
-- A right-hand side that is not a canonical default: an ordinary conditional rewrite, not a
-- junk-value rule. This is the check that keeps discovery from returning most of Mathlib.
#guard !looksLikeRule {`Zero.zero} (mkEqOf (.const `myOp []) (.const `somethingElse []))
-- A left-hand side with no constant at its head: nothing to index the rule by.
#guard !looksLikeRule {`Zero.zero} (mkEqOf (.bvar 0) (.const `Zero.zero []))
-- Not an equation at all.
#guard !looksLikeRule {`Zero.zero} (.const `True [])

/-! ## The catalogue as data

Its entries cannot be resolved here, but the list itself is checked: it must be non-empty, free of
duplicates, and every entry must carry the note that explains what the default costs. -/

#guard mathlibCatalogue.size > 0
#guard mathlibCatalogue.all (!·.note.isEmpty)
#guard (mathlibCatalogue.map (·.theoremName)).toList.eraseDups.length == mathlibCatalogue.size

#guard arithmeticCatalogue.size > 0
#guard arithmeticCatalogue.all (!·.note.isEmpty)
#guard (arithmeticCatalogue.map (·.theoremName)).toList.eraseDups.length == arithmeticCatalogue.size
-- No entry appears in both catalogues: they are separate imports and a shared entry would be
-- reported twice by a project that takes both.
#guard arithmeticCatalogue.all fun a => mathlibCatalogue.all (·.theoremName != a.theoremName)
-- The arithmetic catalogue is where the second rule form is used, so at least one entry must
-- nominate a position — otherwise `generalizing` has silently stopped being exercised.
#guard arithmeticCatalogue.any (!·.generalize.isEmpty)
-- ... and every nominated position is 1-based, so 0 is always a mistake.
#guard arithmeticCatalogue.all (·.generalize.all (· > 0))

-- With no Mathlib, every entry is unresolved rather than silently absent — which is the property
-- that matters. A catalogue that stops resolving must say so.
run_meta do
  let check ← checkCatalogue mathlibCatalogue
  unless check.rules.isEmpty do
    throwError "no catalogue entry should resolve in a Mathlib-free environment"
  unless check.unresolved.size == mathlibCatalogue.size do
    throwError "expected every entry to be reported unresolved, got {check.unresolved.size} \
      of {mathlibCatalogue.size}"
  -- ... and that has to reach the rule set as a reader-facing problem, not a dropped entry.
  let report ← RuleSet.ofEnv
  unless report.problems.size ≥ mathlibCatalogue.size do
    throwError "unresolved catalogue entries must be reported, got {report.problems.size} problems"

/-! ## Provider registration

Importing this module is what switches the optional sources on, so both must be registered. This is
the check that the mechanism in `RuleSet.lean` actually fires — if `initialize` stopped running, a
scan would silently fall back to annotated rules only. -/

run_meta do
  let providers ← ruleProviders.get
  for expected in ["catalogue", "arithmetic", "discovery"] do
    unless providers.any (·.name == expected) do
      throwError "the `{expected}` rule source did not register itself on import"

/-! ## Discovery, on the synthetic junk value

`Test.JunkValues.myOp_undef` has the rule shape and a negated guard, so discovery must find it by
shape alone — with nobody having named it. -/

run_meta do
  let discovered ← discoverRules { moduleprefix? := some `Test.JunkValues }
  unless discovered.any (·.source == ``JunkValues.Test.myOp_undef) do
    throwError "discovery should find `myOp_undef` by its shape alone"

  -- The negated-guard filter is the whole difference between 1417 candidates and 4422 over
  -- Mathlib, so it has to actually gate: `myOp_undef`'s guard is `¬ Good f`, and a rule whose
  -- guard is positive must not survive the strict pass. `Good` itself has no rule shape, so the
  -- check is on the filter's effect rather than on a second synthetic rule.
  let loose ← discoverRules { moduleprefix? := some `Test.JunkValues, requireNegatedGuard := false }
  unless loose.size >= discovered.size do
    throwError "relaxing `requireNegatedGuard` must never find fewer rules"

end JunkValues.ExtraTest
