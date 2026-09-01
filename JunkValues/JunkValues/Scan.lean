module

public import JunkValues.RuleSet
public import JunkValues.Guard
public import JunkValues.Report

@[expose] public section

/-!
# Scanning a declaration for junk values

Walk a declaration's statement and body; wherever a subterm matches a rule's pattern, instantiate
the rule's guards at that subterm, try to rule them out, and record what happened.

## Why the traversal enters binders properly

The obvious implementation folds over the `Expr` and never opens a `lam` or `forallE`. It is wrong
here for two reasons, both of which show up on the first real example.

A term found under a binder mentions that binder. `∫ y, f x y ∂μ` inside `fun x => …` has a loose
bound variable in it, so it cannot be printed, and its guard `Integrable (f x) μ` cannot be printed
either — the report would be full of `#0`. And the guard cannot be *discharged*: deciding whether
`f x` is integrable is exactly the kind of thing the surrounding hypotheses answer, and a fold has
thrown those away.

So `visit` opens every binder with `withLocalDecl`, and by the time it reaches a subterm the local
context is the one that subterm actually lives in — the declaration's own hypotheses, plus whatever
binders enclose the occurrence. That is what lets `assumption` and `fun_prop` do their jobs, and it
is why findings can be rendered at all. It also means the scan pays for a real `MetaM` local context
at every binder, which is the dominant cost and is worth it.

## Why findings are rendered here and not later

For the same reason: a `Finding` leaves this module as text because the free variables its terms
mention stop existing the moment the traversal unwinds. See the note in `Report.lean`.

## What the scan does not do

It does not decide whether the mathematics is wrong. `unguarded` means *nothing in scope rules this
out*, which on a first run over a real development is a large number of places, most of them fine.
The scan's job is to make the list finite and ordered; the discharger is what makes it short.
-/

open Lean Meta

namespace JunkValues

/-- How much of a declaration to look at, and what to report. -/
structure ScanConfig where
  /-- What to try when deciding whether an occurrence is ruled out. -/
  guard : GuardConfig := {}
  /-- Keep occurrences whose guard was successfully ruled out. Off by default — they are evidence
  that the scan looked, not findings — but a page that wants to show its work needs them. -/
  includeGuarded : Bool := false
  /-- Look inside the *values* of definitions. This is where the request's `def B := ∫ (f + g)`
  lives, so it is on by default. -/
  scanBodies : Bool := true
  /-- Look inside the values of *proofs* as well. Off by default: a junk value in the middle of a
  proof is usually a step that the proof itself goes on to justify, and the elaborated proof term of
  anything nontrivial is enormous. The statement of a theorem is scanned either way. -/
  scanProofs : Bool := false
  /-- Stop after this many occurrences in one declaration. A guard against a pathological term
  producing thousands of near-identical findings; reaching it is reported. -/
  maxPerDecl : Nat := 64

/-- Everything the scan of a single declaration produced. -/
structure DeclScan where
  decl : Name
  findings : Array Finding := #[]
  /-- `maxPerDecl` was reached, so this declaration's list is incomplete. Reported rather than
  silently truncated. -/
  truncated : Bool := false
deriving Inhabited

/-- Replace the nominated explicit argument positions of a pattern with fresh metavariables, and
return the equations that says what each one has to be for the rule to fire.

This is the second rule form: `?a / 0` becomes `?a / ?b` with the guard `?b = 0`, so the rule asks
about every division rather than about a literal one. Sound by congruence — see `Rule.lean`.

A position out of range is skipped rather than failing, because `ruleOfTheorem?` already rejected
those at registration; reaching one here would mean the rule was built by hand. -/
def generalizePattern (positions : Array Nat) (lhs : Expr) : MetaM (Expr × Array Expr) := do
  if positions.isEmpty then return (lhs, #[])
  let explicits ← explicitArgIndices lhs
  let mut args := lhs.getAppArgs
  let mut guards := #[]
  for position in positions do
    let some raw := explicits[position - 1]? | continue
    let some original := args[raw]? | continue
    let hole ← mkFreshExprMVar (← inferType original)
    args := args.set! raw hole
    guards := guards.push (← mkEq hole original)
  return (mkAppN lhs.getAppFn args, guards)

/-- Match one rule against one subterm, returning the instantiated guards and default value.

The interesting cases are the ones that are *not* a plain success:

* an unassigned **instance** argument is synthesized, because a rule stated for a general
  `NormedAddCommGroup` should still fire on a term whose instance the pattern did not touch;
* an unassigned **data** argument is left as a metavariable and allowed through, because some rules
  genuinely have one. `setToFun_undef` quantifies a bound `C` that appears only in its hypothesis,
  and the honest reading of the resulting finding is existential — *if there is a `C` with …* — which
  is what an unassigned `?C` prints as;
* an unassigned metavariable in the **value** is fatal. If the tool cannot say what the term
  collapses *to*, it has nothing to report.

Runs under `withNewMCtxDepth` so the rule's metavariables are assignable while nothing in the
caller's context is, and under `withoutModifyingState` so a failed or partial match cannot leak
assignments into the next subterm. -/
def matchRule? (rule : JunkRule) (e : Expr) : MetaM (Option (Array Expr × Expr)) :=
  withoutModifyingState <| withNewMCtxDepth do
    let some opened ← openRule rule.source | return none
    let (pattern, generalized) ← generalizePattern rule.generalize opened.lhs
    unless ← isDefEq pattern e do return none
    -- The generalization equations come first: "is the divisor zero" is the question the reader is
    -- being asked, and the rule's own hypotheses (if any) refine it.
    let mut guards := generalized
    for h : i in [0:opened.vars.size] do
      let v := opened.vars[i]
      if !(← instantiateMVars v).isMVar then continue
      let binderType ← instantiateMVars (← inferType v)
      if ← isGuardBinder opened.binderInfos[i]! binderType then
        guards := guards.push binderType
      else if opened.binderInfos[i]! matches .instImplicit then
        -- An instance the pattern did not determine has to be *synthesized*, and failing to
        -- synthesize it means the rule's theorem does not apply to this term at all — so the match
        -- fails rather than proceeding with the argument left open.
        --
        -- This is not a corner case, it is the difference between the arithmetic rules being usable
        -- and being worthless. `tsub_eq_zero_of_le` needs `OrderedSub α`, which `ℕ` and `ℝ≥0∞` have
        -- and `ℝ`, `ℤ` and `ℚ` do not — truncation is exactly what those types do not do. The
        -- instance never appears in the term `x - y`, so unification cannot assign it, and simply
        -- carrying on reported *every subtraction in every project* as a truncation.
        let .some inst ← trySynthInstance binderType | return none
        unless ← isDefEq v inst do return none
    let value ← instantiateMVars opened.rhs
    if value.hasExprMVar then return none
    return some (← guards.mapM instantiateMVars, value)

/-- Render an occurrence into a `Finding`, in the local context it was found in. -/
def mkFinding (decl : Name) (site : Site) (rule : JunkRule) (term : Expr)
    (guards : Array Expr) (value : Expr) (status : Status) : MetaM Finding := do
  return {
    decl, site, rule := rule.source, head := rule.head
    term := toString (← ppExpr term)
    guards := ← guards.mapM fun g => return toString (← ppExpr g)
    value := toString (← ppExpr value)
    status, note := rule.note }

/-- Try every rule that could fire on this subterm.

The arity pre-filter is not an optimisation only: it is what makes an over-applied junk value match
at the right node. `fderiv 𝕜 f x y` is an application of `fderiv` to 13 arguments and the rule is
about 12, so nothing is reported here — and the traversal's own recursion into the function part
reaches `fderiv 𝕜 f x`, which matches. Reporting at the outer node instead would name a term whose
type is not the one the rule's default value has. -/
def matchAt (rs : RuleSet) (cfg : ScanConfig) (decl : Name) (site : Site) (e : Expr) :
    MetaM (Array Finding) := do
  let some head := headConst? e | return #[]
  let candidates := rs.forHead head
  if candidates.isEmpty then return #[]
  let numArgs := e.getAppNumArgs
  let mut out := #[]
  for rule in candidates do
    if rule.arity != numArgs then continue
    let some (guards, value) ← matchRule? rule e | continue
    let status ← classify guards cfg.guard
    if cfg.includeGuarded || status.isFinding then
      out := out.push (← mkFinding decl site rule e guards value status)
  return out

/-- Walk an expression, opening every binder, collecting findings.

Recursion into both parts of an application is what finds nested occurrences — the inner integral of
`∫ x, (∫ y, f x y ∂ν) ∂μ`, and the partially applied node of an over-applied one. -/
partial def visit (rs : RuleSet) (cfg : ScanConfig) (decl : Name) (site : Site)
    (e : Expr) (acc : Array Finding) : MetaM (Array Finding) := do
  if acc.size ≥ cfg.maxPerDecl then return acc
  let acc := acc ++ (← matchAt rs cfg decl site e)
  let go := visit rs cfg decl site
  match e with
  | .app f a => go a (← go f acc)
  -- The binder's *type* is scanned outside the binder and the body inside it, so that a hypothesis
  -- is never in scope for the term that introduces it. Hoisted out of the continuation because a
  -- monadic action cannot be lifted across the `withLocalDecl` lambda.
  | .lam n t b bi =>
    let acc ← go t acc
    withLocalDecl n bi t fun x => go (b.instantiate1 x) acc
  | .forallE n t b bi =>
    let acc ← go t acc
    withLocalDecl n bi t fun x => go (b.instantiate1 x) acc
  | .letE n t v b _ =>
    let acc ← go v (← go t acc)
    withLetDecl n t v fun x => go (b.instantiate1 x) acc
  | .mdata _ b => go b acc
  | .proj _ _ b => go b acc
  | _ => return acc

/-- Drop occurrences that render identically under the same rule.

The same subterm often appears many times in one statement — `∫ f = ∫ f + 0` — and reporting each
is noise about one fact. Deduplication is on the rendered text rather than on the `Expr` because
that is what a reader sees: two occurrences a reader cannot tell apart are one finding. -/
def dedupFindings (findings : Array Finding) : Array Finding := Id.run do
  let mut seen : Std.HashSet (Name × Site × String) := ∅
  let mut out := #[]
  for f in findings do
    let key := (f.rule, f.site, f.term)
    unless seen.contains key do
      seen := seen.insert key
      out := out.push f
  return out

/-- Whether `n` is a name the compiler generated rather than one somebody wrote.

A deliberately small version of the classification `MeaningGraph.isInternalName` does properly; this
package does not depend on that one. What it has to catch is the family of helpers the equation
compiler attaches to a recursive definition — `_f`, `_sunfold`, `_unsafe_rec`, `match_1` — because
those are where a recursive definition's *body* actually ends up. -/
def isCompilerGenerated : Name → Bool
  | .anonymous => false
  | .num p _ => isCompilerGenerated p
  | .str p s =>
    s.startsWith "_"
      || (s.startsWith "match_" && !(s.drop 6).isEmpty && (s.drop 6).all Char.isDigit)
      || (s.startsWith "eq_" && !(s.drop 3).isEmpty && (s.drop 3).all Char.isDigit)
      || s == "eq_def" || s == "eq_unfold" || s == "induct" || s == "fun_cases"
      || isCompilerGenerated p

/-- The compiler-generated helpers of `decl` that `value` refers to.

Restricted to names nested under `decl`, so a definition's own helpers are followed and nothing else
is. A `where` clause's auxiliary is *not* one of these — `foo.aux` is a declaration somebody wrote,
gets scanned in its own right, and would be reported under its own name. -/
def compilerAuxOf (env : Environment) (decl : Name) (value : Expr) : Array Name :=
  value.getUsedConstants.filter fun c =>
    c != decl && decl.isPrefixOf c && isCompilerGenerated c && (env.find? c).isSome

/-- Scan one declaration: its statement always, its body when the configuration asks for it.

## Recursive definitions

A recursive definition's elaborated value is a wrapper; the body somebody wrote lives in helpers the
equation compiler generated (`countdown._f`, `countdown.match_1`). Scanning only `info.value?` finds
nothing in

```lean
def countdown : ℕ → ℕ
  | 0 => 0
  | (n+1) => countdown n - 1
```

— the value does not mention subtraction *at all*, so the truncation is invisible. So the scan
follows those helpers, transitively, and reports what it finds **against the declaration the author
wrote**, which is the only name a reader can act on. This is the same compensation `MeaningGraph`
makes for the same reason.

Both halves are walked by `visit` directly rather than by first entering a telescope, because
`visit` already opens `forallE` and `lam` — which means a hypothesis of a theorem is scanned with
the hypotheses *before* it in scope, and the conclusion with all of them. That is the scope a reader
would use to judge the same term. -/
def scanDecl (rs : RuleSet) (cfg : ScanConfig) (name : Name) : MetaM DeclScan := do
  let some info := (← getEnv).find? name | return { decl := name }
  -- Decided from the type, not from `ConstantInfo.thmInfo`: an attribute or an import can present
  -- a theorem of the current module as something else. Same reason `Characterization.isProof` does.
  let isProof ← isProp info.type
  -- The body's walk continues the statement's accumulator rather than starting a fresh one, so that
  -- `maxPerDecl` is a cap on the *declaration* — threading it was also what made `truncated`
  -- honest, since comparing the sum of two independently capped walks against the cap reported
  -- truncation for a declaration of exactly `maxPerDecl` findings that had not been cut at all.
  let mut found ← visit rs cfg name .statement info.type #[]
  if cfg.scanBodies && (cfg.scanProofs || !isProof) then
    -- A worklist rather than a recursion, over the declaration and its compiler-generated helpers.
    -- `seen` is what keeps a mutually-referring helper pair from looping.
    let mut queue := #[name]
    let mut seen : Std.HashSet Name := ∅
    while h : queue.size > 0 do
      let current := queue[queue.size - 1]
      queue := queue.pop
      if seen.contains current then continue
      seen := seen.insert current
      if found.size ≥ cfg.maxPerDecl then break
      let some currentInfo := (← getEnv).find? current | continue
      let some value := currentInfo.value? | continue
      found ← visit rs cfg name .body value found
      queue := queue ++ compilerAuxOf (← getEnv) name value
  return { decl := name, findings := dedupFindings found, truncated := found.size ≥ cfg.maxPerDecl }

/-- Scan many declarations, keeping only those with something to report.

Failures are contained per declaration: a single term that makes the unifier or a discharging tactic
throw must not lose the results for everything else in a library, so the exception is caught and the
declaration is skipped. It is skipped *visibly* — the caller gets the names in `failed` — for the
same reason unresolved catalogue entries are returned rather than logged. -/
def scanDecls (rs : RuleSet) (cfg : ScanConfig) (names : Array Name) :
    MetaM (Array DeclScan × Array (Name × String)) := do
  let mut out := #[]
  let mut failed := #[]
  for name in names do
    try
      let scan ← scanDecl rs cfg name
      unless scan.findings.isEmpty do out := out.push scan
    catch e =>
      failed := failed.push (name, ← e.toMessageData.toString)
  return (out, failed)

end JunkValues
