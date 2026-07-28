module

public import Lean

@[expose] public section

/-!
# `@[specifies]` — the theorems that specify a definition

A formalization's definitions are the part a reader has to take on faith: a proof can be checked by
the kernel, but nothing checks that `myDefinition` says what its name suggests. What settles that
question is a handful of theorems — that the definition agrees with the textbook formula on the
base case, that it is monotone, that it reduces to the classical notion in the classical case.

Those theorems already exist in most projects; what is missing is any record of *which* ones they
are. Nothing in the environment distinguishes a characterizing property of a definition from a step
in the proof of something else. `@[specifies]` is that record, written by the author at the point of
the theorem:

```lean
def entropy (p : Distribution α) : ℝ := …

@[specifies entropy "agrees with the textbook formula on finite supports"]
theorem entropy_eq_sum (p : Distribution α) (h : p.support.Finite) :
    entropy p = -∑ x ∈ h.toFinset, p x * Real.log (p x) := …

@[specifies entropy]
theorem entropy_nonneg (p : Distribution α) : 0 ≤ entropy p := …
```

Read back out of the compiled environment (`specEntries`), this gives a tool the two things it
could not otherwise derive: for a definition, the properties its author claims pin it down, and —
just as usefully — which definitions have no such claim at all.

## Importing this module

A file using the module system has to import this one at compile time — `meta import LeanSpec` —
because applying an attribute is a compile-time act and a runtime-phase import does not run the
initializer that registers it. Without that, `@[specifies]` is reported as an unknown attribute. A
file not using the module system just writes `import LeanSpec`.

## Why an attribute and not a metadata file

Because it cannot silently go stale. The target is an identifier, so it resolves against the
ambient namespaces, a typo is a compile error, and renaming the definition breaks the build at the
annotation. A sidecar file listing declaration names drifts out of date invisibly, which is the
one thing an auditing tool must not do.

## Reading the annotations from another process

The entries live in a persistent environment extension, so they survive into the `.olean` and can
be read by a tool that imports the project — provided that tool has the extension *registered*,
since imported entries are matched to extensions by name and unmatched ones are dropped. In
practice that means the reading process must link this library and call
`importModules (loadExts := true)`.

Two consequences worth knowing before changing this file:

* `SpecEntry`'s field layout is part of the on-disk format. Entries are deserialized as a memory
  image into whatever type the *reader's* copy of this library declares, and the reader may be
  built from a different revision than the project it is reading. Adding or reordering fields is
  therefore not a backwards-compatible change; if it has to happen, rename the extension too so
  that old entries are dropped rather than misread.
* The extension is named after `specExt` (`registerSimplePersistentEnvExtension` defaults its
  `name` to `decl_name%`), so renaming that constant silently invalidates every entry written by
  an older build.

## The attribute name

Attribute names are global and unqualified, and Lean rejects a duplicate registration outright: if
a project imports two libraries that both claim a name, neither can be imported. The obvious name
here, `spec`, is already Lean's own — `Std.Tactic.Do` registers `@[spec]` for the specifications
its `mvcgen` verification-condition generator consumes — so this library takes `specifies`, which
also reads better at the use site. The token is declared non-reserved (`&"specifies"`), so a
project can still use `specifies` as an ordinary identifier.
-/

open Lean

namespace LeanSpec

/-- One `@[specifies …]` annotation: the theorem it was written on, the definition that theorem is
claimed to specify, and the author's optional note on why it belongs in the specification.

The field layout is part of the `.olean` format — see the note on compatibility in the module
docstring before changing it. -/
structure SpecEntry where
  /-- The annotated theorem. -/
  theoremName : Name
  /-- The definition the theorem is part of the specification of. -/
  target : Name
  /-- The author's justification, as written in the attribute. Empty when omitted. -/
  comment : String := ""
deriving Repr, Inhabited, BEq

/-- Every `@[specifies]` annotation of the current module and of everything it imports, in
declaration order. -/
initialize specExt : SimplePersistentEnvExtension SpecEntry (Array SpecEntry) ←
  registerSimplePersistentEnvExtension {
    addEntryFn := Array.push
    addImportedFn := fun entries => entries.flatten
  }

/-- Every specification annotation visible in `env`, in declaration order (so a definition's
specification reads in the order its author wrote it, not alphabetically).

This is the entry point for tools. It is a plain array rather than a map because the interesting
groupings differ per consumer — by target, by theorem, by module — and building the one you want
from a single pass is cheaper than maintaining all of them here. -/
def specEntries (env : Environment) : Array SpecEntry :=
  specExt.getState env

/-- The definitions `thm` is annotated as specifying. Linear in the number of annotations in the
project; group `specEntries` yourself if you need this for every declaration. -/
def specTargetsOf (env : Environment) (thm : Name) : Array SpecEntry :=
  (specEntries env).filter (·.theoremName == thm)

/-- The theorems annotated as specifying `target`. Linear in the number of annotations in the
project; group `specEntries` yourself if you need this for every declaration. -/
def specTheoremsFor (env : Environment) (target : Name) : Array SpecEntry :=
  (specEntries env).filter (·.target == target)

/-! ## The attribute -/

/--
`@[specifies definition "why"]` marks a theorem as part of the specification of `definition`: one of
the properties its author offers as evidence that the definition is the intended one.

Both arguments are optional:

* `@[specifies]` infers the target from the theorem's own name, taking the innermost enclosing
  namespace that is a definition — so `@[specifies] theorem entropy_nonneg` in `namespace entropy`,
  or `@[specifies] theorem entropy.nonneg`, both mean `@[specifies entropy]`.
* the comment is free text, shown next to the theorem wherever the specification is presented. It
  should say what the property *buys* the reader, which the statement alone does not.

Apply it more than once for a theorem that specifies more than one definition
(`@[specifies foo, specifies bar]`).
-/
-- `priority := high` so that the argument-less `@[specifies]` is not ambiguous with `Attr.simple`,
-- the catch-all `ident`-shaped attribute parser, which also matches it. Without the priority both
-- parsers match to the same position and the category parser emits a `choice` node, which
-- `elabAttr` reports as the (nonexistent) attribute `choice`. The `add` handler below still
-- accepts an `Attr.simple` node, so the bare form keeps working whichever parser wins.
syntax (name := specifies) (priority := high) &"specifies" (ppSpace ident)? (ppSpace str)? : attr

register_option specifies.checkTargetMentioned : Bool := {
  defValue := true
  descr := "warn when a theorem carrying `@[specifies f]` does not mention `f` in its statement"
}

/-- Whether `info` is a proof, which is what a specification can neither be about nor stated on:
the point of `@[specifies]` is to say what a *definition* means, and a proof's meaning is already
its statement.

Decided from the type rather than from the constant's kind. `info matches .thmInfo _` looks like
the same test and is not: an attribute handler runs under the visibility scope of the declaration
it is applied to, and in that exported view a theorem of the current module does not arrive as a
`.thmInfo` — so the syntactic test silently passes theorems through. -/
private def isProof (info : ConstantInfo) : AttrM Bool :=
  Meta.MetaM.run' (Meta.isProp info.type)

/-- The definition a bare `@[specifies]` refers to: the innermost enclosing namespace of `declName`
that names something a specification can be about. Walks outwards (`Foo.Bar.baz` tries `Foo.Bar`,
then `Foo`) so that a theorem in a nested namespace still finds its subject, skipping ancestors
that are themselves proofs, and gives up when no ancestor names a constant at all — in which case
the author has to be explicit. -/
private partial def inferTarget (declName : Name) : AttrM (Option Name) :=
  go declName.getPrefix
where
  go : Name → AttrM (Option Name)
    | .anonymous => return none
    | n => do
      match (← getEnv).find? n with
      | some info => if ← isProof info then go n.getPrefix else return some n
      | none => go n.getPrefix

initialize registerBuiltinAttribute {
  name := `specifies
  descr := "mark this theorem as part of the specification of a definition"
  applicationTime := .afterTypeChecking
  add := fun declName stx attrKind => do
    unless attrKind == .global do
      throwError "`specifies` must be a global attribute: a specification is a claim about the \
        definition, not about a section or a namespace"
    -- `Attr.simple` is the bare `@[specifies]` as parsed by the catch-all attribute parser; see the
    -- note on the syntax declaration above.
    let (targetStx?, commentStx?) ←
      if stx.getKind == ``Lean.Parser.Attr.simple then
        pure (none, none)
      else match stx with
        | `(attr| specifies $[$targetStx?]? $[$commentStx?]?) => pure (targetStx?, commentStx?)
        | _ => throwError "invalid `specifies` attribute, expected \
          `@[specifies definition \"comment\"]`"
    let env ← getEnv
    unless (env.getModuleIdxFor? declName).isNone do
      throwError "cannot apply `specifies` to `{declName}`, which is declared in an imported \
        module: the annotation would not be recorded in this module's `.olean`"
    let some info := env.find? declName
      | throwError "unknown declaration `{declName}`"

    -- `@[specifies]` says "this statement is part of what `f` means", so it only makes sense on
    -- something that has a statement. Anything proving a proposition qualifies, so that a `lemma`
    -- elaborated as a `def` (or an `instance` of a `Prop`-valued class) is still accepted.
    unless (← isProof info) do
      throwError "`specifies` belongs on a theorem, but `{declName}` is not a proposition"

    let target ← match targetStx? with
      | some id => Elab.realizeGlobalConstNoOverloadWithInfo id
      | none =>
        match ← inferTarget declName with
        | some target => pure target
        | none =>
          throwError "cannot infer what `{declName}` specifies: no enclosing namespace of its \
            name is a declaration. Name the definition explicitly, as `@[specifies myDefinition]`"
    if target == declName then
      throwError "`{declName}` cannot be part of its own specification"
    let some targetInfo := env.find? target
      | throwError "unknown declaration `{target}`"
    if ← isProof targetInfo then
      throwError "`{target}` is itself a proof, but `specifies` names the definition that the \
        annotated theorem is a property of"

    if (specEntries env).any fun e => e.theoremName == declName && e.target == target then
      throwError "`{declName}` is already part of the specification of `{target}`"

    -- A theorem that never mentions its target is almost always a mistyped or copy-pasted
    -- annotation. It is only *almost* always, though — the target can be reached through an
    -- abbreviation, or hidden in a structure projection that the elaborated type does not name as
    -- a constant — so this is a warning, and a theorem living inside the target's namespace is
    -- taken as intent enough to say nothing at all.
    if specifies.checkTargetMentioned.get (← getOptions) then
      unless info.type.getUsedConstants.contains target || target.isPrefixOf declName do
        logWarning m!"`{declName}` is marked as part of the specification of `{target}`, but its \
          statement does not mention `{target}`. Set `specifies.checkTargetMentioned` to `false` \
          to silence this."

    let comment := (commentStx?.map TSyntax.getString).getD ""
    modifyEnv fun env =>
      specExt.addEntry (asyncDecl := declName) env { theoremName := declName, target, comment }
}

end LeanSpec
