module

public import JunkValues.RuleSet
public import Std.Data.HashSet

@[expose] public section

/-!
# Discovery: finding junk-value theorems by their shape

**Optional, and the least essential thing in this package.** The core is `@[junk_value]` and the
linter; the catalogue is the hand-checked answer for upstream junk values. This module is the other
end of that: given an environment, find every theorem that *is* a junk-value rule, whether or not
anybody said so.

It is off even when imported — it also needs `set_option linter.junkValues.discovery true` — because
it is expensive and, as the measurements below show, imprecise. Read the last section before
switching it on.

## The criterion is semantic, not a naming convention

Mathlib does have a convention — `_undef`, `_of_not_integrable`, `_eq_zero_of_not_differentiableAt`
— and keying on it would be easy and wrong. Names drift, the convention is not followed everywhere
(`Real.sqrt_eq_zero_of_nonpos` matches nothing regular), and a name is not evidence.

What is evidence is the shape of the statement:

1. the conclusion is an equation,
2. its left-hand side is headed by a constant — there is an operation to warn about,
3. at least one hypothesis — the collapse is *conditional*, so there is something to check,
4. the right-hand side is a **canonical default**: `0`, `1`, `∅`, `⊥`, `⊤`, `none`, `default`,
5. at least one hypothesis is a **negation** — `¬P` or `a ≠ b`.

Condition 4 says what makes a junk value dangerous rather than merely surprising: the operation
collapses onto a value *already in its range*, so nothing downstream can tell the collapse apart
from a real answer. `deriv f x = 0` is indistinguishable from a critical point, `∫ f = 0` from a
genuinely centred integrand, and that indistinguishability is the whole hazard.

Condition 5 exists because conditions 1–4 are nowhere near enough, which was measured rather than
guessed. Run over all of Mathlib without it, discovery admits **4422** theorems covering 1106
operations, and the large majority are ordinary mathematics that happens to conclude in `= 0` or
`= 1`: `ZMod.mul_inv_of_unit`, `IsCoatom.sup_eq_top_of_ne`, `Matrix.BlockTriangular.…_eq_one`,
every `mk.sizeOf_spec`. Nothing about `0` and `1` is rare enough to filter on. What *is*
characteristic of a junk value is that its condition is the **failure** of a domain condition, and
authors write that failure with `¬`.

The trade is stated in `JunkRule.negatedGuards`: condition 5 is not perfect in either direction, and
it costs `Real.sqrt_eq_zero_of_nonpos`, whose guard `x ≤ 0` is a genuine domain failure not written
as a negation. That is why the catalogue does not apply condition 5 and discovery does — a
hand-verified entry needs no heuristic, and an automatic sweep of 350,000 constants needs a strict
one. `requireNegatedGuard` turns it off for a caller who would rather triage the long list.

## Discovery is a catalogue-building aid, not a rule source

The measured numbers, over the whole of Mathlib: 4422 candidates on conditions 1–4, **1417** with
condition 5, against a hand-verified catalogue of 22. Discovery independently finds every catalogue
entry but one, so it is not missing the target — it is that the remaining 1400 are mostly not junk
values, and no *syntactic* criterion can fix that, because the distinction is semantic:

```lean
theorem Finset.singleton_inter_of_notMem (h : a ∉ s) : {a} ∩ s = ∅   -- ∅ is the right answer
theorem MeasureTheory.integral_undef      (h : ¬Integrable f μ) : ∫ a, f a ∂μ = 0  -- 0 is a lie
```

Both have all five properties. The difference is that `∅` is what the intersection genuinely *is*,
while `0` is what the integral was *defined to be* for want of anything better — and that is a fact
about the intent behind a definition, which no amount of looking at the statement will recover.

So discovery is aimed at the person assembling a catalogue, not at a scan. Run it over a project or
an unfamiliar area of Mathlib, read what it proposes, and promote the real ones with `@[junk_value]`
or a catalogue entry. It does earn its place at that job: on the run above it surfaced genuine junk
values nobody had catalogued, including the `getElem!` family (`Std.HashMap.getElem!_diff_of_…`),
which return `default` for an absent key and are the data-structure analogue of the whole problem.
That is why `RuleSources.discovery?` defaults to `none` and every frontend that enables it says how
many rules came from it and that nobody vouched for them.

## What it costs

Conditions 1 and 4 are cheap syntactic tests, so a pure `Expr` pre-filter (`looksLikeRule`) rejects
almost everything before any `MetaM` work happens; only survivors are opened with metavariables, and
conditions 3 and 5 are decided there. Over all of Mathlib — several hundred thousand constants —
the whole pass takes a few seconds.

## What it misses, deliberately

Junk values whose condition is not written as a hypothesis. `div_zero : a / 0 = 0` states the
collapse by *specialising the left-hand side* instead, and recovering a rule from it would mean
generalising the literal `0` back to a variable `?b` and synthesizing the guard `?b = 0`. That is a
coherent second rule form and it is not implemented. The reason is not difficulty but value: a
syntactically visible `0` in the denominator is something a reader can see, whereas the whole point
of the conditional form is that `¬Integrable (f + g) μ` is *not* visible in `∫ (f + g)`.
-/

open Lean Meta

namespace JunkValues

/-- Constants that head a canonical default value.

Written as `Name` literals rather than quotations because several of them (`Zero.zero`, `Bot.bot`,
`Top.top`) live in Mathlib, which this package does not depend on. A name that no environment
defines simply never matches.

`One.one` and the literal `1` are here alongside zero because the multiplicative junk value is just
as silent: `tprod_eq_one_of_not_multipliable` collapses an infinite product to `1`, which is also
the product of the constant-one family. -/
def defaultValueHeads : Array Name :=
  #[`OfNat.ofNat, `Zero.zero, `One.one, `EmptyCollection.emptyCollection,
    `Bot.bot, `Top.top, `Option.none, `Inhabited.default, `List.nil, `EmptyRelation]

/-- The conclusion of a (possibly dependent) function type: everything after the binders.

Returns an expression with loose bound variables, which is fine and is why this is pure: the only
thing asked of the result is the head constant of each side of its equation. -/
partial def conclusionOf : Expr → Expr
  | .forallE _ _ body _ => conclusionOf body
  | .mdata _ e => conclusionOf e
  | e => e

/-- The cheap pre-filter: does this type conclude in `lhs = default`, with a constant heading `lhs`?

Pure, no `MetaM`, no unfolding — it exists to reject the overwhelming majority of a large
environment before anything expensive happens. It deliberately does *not* check for the presence of
a hypothesis: that needs to know which binders are propositions, which needs types, which needs
`MetaM`. `ruleOfTheorem?` makes that check on the survivors. -/
def looksLikeRule (defaults : Std.HashSet Name) (type : Expr) : Bool :=
  match (conclusionOf type).eq? with
  | some (_, lhs, rhs) =>
    (headConst? lhs).isSome && (headConst? rhs).any defaults.contains
  | none => false

/-- Which constants a discovery pass should consider. -/
structure DiscoveryScope where
  /-- Only consider declarations in modules under this prefix. `none` means the whole environment,
  imports included — which is what finds Mathlib's rules, and what costs the most. -/
  moduleprefix? : Option Name := none
  /-- Skip declarations whose name contains an internal component. Compiler-generated equation
  lemmas conclude in equations by construction and would otherwise dominate the results. -/
  skipInternal : Bool := true
  /-- Require at least one hypothesis to be a negation (condition 5 in the module docstring).

  On by default, because without it a sweep of Mathlib returns thousands of ordinary conditional
  rewrites. Turn it off to see the long list — and to catch the junk values whose domain condition
  is stated positively, like `Real.sqrt_eq_zero_of_nonpos`. -/
  requireNegatedGuard : Bool := true

/-- Whether `name` is one discovery should look at. Deliberately conservative about auto-generated
names: an `.eq_1` equation lemma has the rule shape by construction and is never a rule. -/
def DiscoveryScope.admits (scope : DiscoveryScope) (env : Environment) (name : Name) : Bool :=
  if scope.skipInternal && (name.isInternal || name.isImplementationDetail || isPrivateName name) then
    false
  else match scope.moduleprefix? with
    | none => true
    | some pfx =>
      match env.getModuleIdxFor? name with
      | some idx => match env.header.moduleNames[idx.toNat]? with
        | some m => pfx.isPrefixOf m
        | none => false
      -- Declared in the current module rather than imported: in scope for a project-local pass.
      | none => true

/-- Every theorem in scope whose statement has the junk-value rule shape.

Two passes on purpose: the pure `looksLikeRule` filter over every constant, then `ruleOfTheorem?`
only on what survives. Anything that survives the first pass and fails the second is dropped
silently — unlike a *catalogue* entry that fails to resolve, a discovered non-rule is not something
anybody asserted, so there is nothing to report. -/
def discoverRules (scope : DiscoveryScope := {}) : MetaM (Array JunkRule) := do
  let env ← getEnv
  let defaults : Std.HashSet Name := defaultValueHeads.foldl .insert ∅
  let mut candidates : Array Name := #[]
  for (name, info) in env.constants do
    -- Only propositions can be rules, and `ConstantInfo.isTheorem` is not reliable across the
    -- visibility scopes an environment can be read in; the type test is (see
    -- `Characterization.isProof`).
    unless info matches .thmInfo _ | .axiomInfo _ do continue
    unless scope.admits env name do continue
    if looksLikeRule defaults info.type then
      candidates := candidates.push name
  let mut rules := #[]
  for name in candidates do
    if let .ok rule ← ruleOfTheorem? name then
      if !scope.requireNegatedGuard || rule.negatedGuards > 0 then
        rules := rules.push rule
  return rules

/-! ## As a rule source -/

register_option linter.junkValues.discovery : Bool := {
  defValue := false
  descr := "also use junk-value rules discovered by shape, rather than only the ones the project \
    annotated and the catalogue names. Slow, imprecise, and nobody has vouched for what it finds — \
    see `JunkValues/Extra/Discovery.lean`."
}

/-- Discovery as a rule source: switched on by importing this module *and* setting
`linter.junkValues.discovery`.

Two switches rather than one because the two say different things. The import says "this project is
willing to consider unvouched-for rules"; the option says "on this run, spend the time". Discovery
over a large environment is thousands of rules and several seconds, which is fine once while
building a catalogue and not fine on every command a linter sees. -/
def discoveryProvider : RuleProvider where
  name := "discovery"
  run := fun opts => do
    unless linter.junkValues.discovery.get opts do return {}
    let rules ← discoverRules {}
    return {
      rules
      problems := #[s!"discovery contributed {rules.size} rules found by shape alone. Nobody has \
        vouched for these: no syntactic criterion separates a junk value from a genuine default, so \
        treat them as candidates for `@[junk_value]` rather than as findings."] }

-- Importing this module makes discovery available; the option is what runs it. See `RuleSet.lean`.
initialize registerRuleProvider discoveryProvider

end JunkValues
