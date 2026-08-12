module

public import JunkValues.Rule

@[expose] public section

/-!
# `@[junk_value]` — declaring that a theorem exhibits a default value

The attribute a project puts on its *own* junk-value theorems, so that a scan of the project knows
about the defaults its own definitions have. The rules for upstream libraries cannot be declared
this way — nobody is going to annotate Mathlib — and come from `Catalogue.lean` and
`Discovery.lean` instead.

```lean
@[junk_value "a divergence between measures with no density is reported as infinite"]
theorem klDiv_of_not_integrable (h : ¬Integrable (llr μ ν) μ) : klDiv μ ν = ∞ := …
```

The attribute checks the shape at the point of annotation (`ruleOfTheorem?`), so a theorem that
cannot be a rule is a compile error where it is written rather than a rule that silently never
fires.

## Reading the annotations from another process

Same mechanism, and the same two caveats, as [`LeanSpec`](../../LeanSpec/): entries live in a
persistent environment extension, survive into the `.olean`, and are matched back to extensions *by
name* when imported — so a reading process must link this library and call
`importModules (loadExts := true)`, and:

* `JunkRule`'s field layout is part of the on-disk format. Entries are deserialized as a memory image
  into whatever type the *reader's* copy of this library declares. Adding or reordering fields is not
  backwards-compatible; if it has to happen, rename the extension so old entries are dropped rather
  than misread.
* the extension is named after `junkExt`, so renaming that constant silently invalidates every entry
  written by an older build.

## Why the note is free text

Because the useful thing to say is *why this default is dangerous here*, and that is not derivable.
`= 0` for an integral is a catastrophe; `= ∞` for a divergence is arguably the safe choice. The
scan reports the value either way and the note is where the author says which of the two this is.
-/

open Lean

namespace JunkValues

/-- Every `@[junk_value]` annotation of the current module and of everything it imports, in
declaration order. -/
initialize junkExt : SimplePersistentEnvExtension JunkRule (Array JunkRule) ←
  registerSimplePersistentEnvExtension {
    addEntryFn := Array.push
    addImportedFn := fun entries => entries.flatten
  }

/-- Every rule declared with `@[junk_value]` and visible in `env`, in declaration order.

This is the entry point for tools that only want the *project's own* declared rules. A scan wants
`RuleSet.ofEnv` instead, which folds these together with the catalogue and with discovery. -/
def declaredRules (env : Environment) : Array JunkRule :=
  junkExt.getState env

/--
`@[junk_value "why it matters"]` marks a theorem as exhibiting a junk value: a condition under which
some operation collapses to a default, so that a scan can warn where that operation is used without
the condition being ruled out.

The theorem must have the shape `∀ xs, g₁ → … → gₙ → lhs = rhs` with a constant at the head of
`lhs`; anything else is rejected here rather than silently ignored.

Both parts are optional:

* `generalizing i j …` names **explicit argument positions of `lhs`, counted from 1**, to turn back
  into variables — for a theorem that states its condition by specialising an argument rather than
  by a hypothesis. `@[junk_value generalizing 2] theorem div_zero (a : α) : a / 0 = 0` asks about
  every division instead of about a literal `a / 0`. See `Rule.lean` for why this is sound and why
  the positions cannot be inferred. A theorem with no hypothesis *needs* this, and is rejected
  without it.
* the note is free text, shown with every finding this rule produces. It should say what the default
  *costs* — which the statement alone does not.
-/
syntax (name := junkValue) (priority := high) &"junk_value"
  (ppSpace &"generalizing" (ppSpace num)+)? (ppSpace str)? : attr

initialize registerBuiltinAttribute {
  name := `junkValue
  descr := "mark this theorem as exhibiting a junk value: a condition under which an operation \
    collapses to a default"
  applicationTime := .afterTypeChecking
  add := fun declName stx attrKind => do
    unless attrKind == .global do
      throwError "`junk_value` must be a global attribute: it records a fact about the definition, \
        not about a section or a namespace"
    -- `Attr.simple` is the bare `@[junk_value]` as parsed by the catch-all attribute parser; the
    -- same ambiguity `LeanSpec` documents, handled the same way.
    let (positions, noteStx?) ←
      if stx.getKind == ``Lean.Parser.Attr.simple then
        pure (#[], none)
      else match stx with
        | `(attr| junk_value $[generalizing $[$posStx]*]? $[$noteStx?]?) =>
          pure ((posStx.getD #[]).map (·.getNat), noteStx?)
        | _ => throwError "invalid `junk_value` attribute, expected \
            `@[junk_value generalizing 2 \"why\"]`, with both parts optional"
    let env ← getEnv
    unless (env.getModuleIdxFor? declName).isNone do
      throwError "cannot apply `junk_value` to `{declName}`, which is declared in an imported \
        module: the annotation would not be recorded in this module's `.olean`. Name it in a \
        catalogue instead"
    let note := (noteStx?.map TSyntax.getString).getD ""
    -- The shape check is the point of doing this at the annotation rather than at scan time: a
    -- theorem that cannot be a rule should fail where somebody can fix it.
    match ← Meta.MetaM.run' (ruleOfTheorem? declName note positions) with
    | .error msg => throwError "`{declName}` cannot be a junk-value rule: {msg}"
    | .ok rule => modifyEnv fun env => junkExt.addEntry (asyncDecl := declName) env rule
}

end JunkValues
