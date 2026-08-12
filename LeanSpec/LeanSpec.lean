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

/-- The declaration an entry about the pair `(a, b)` is anchored to — a local one.

Both attributes here relate two declarations, and neither requires them to be declared in the same
module: `attribute [specifies myDefinition] someImportedTheorem` and
`attribute [characterization property myDefinition] SomeImportedPredicate` are the shapes that let
one predicate characterize definitions in several modules without being copied into each. An
attribute writes its entry into the module being *elaborated*, so either of those records the claim
in a module that a reader of the local side reaches.

`none` when both are imported, which is the one configuration to reject: the entry would sit in a
module that neither `a` nor `b` points back to, so a consumer that reaches either of them through
its own imports would never see it.

The result also feeds `asyncDecl`, which has to name a declaration of the current async context
when there is one — under `@[attr]` on a declaration that context is the declaration itself, and a
standalone `attribute` command has none. -/
private def anchor? (env : Environment) (a b : Name) : Option Name :=
  if (env.getModuleIdxFor? a).isNone then some a
  else if (env.getModuleIdxFor? b).isNone then some b
  else none

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
    let some anchor := anchor? env declName target
      | throwError "cannot record that `{declName}` specifies `{target}`: both are declared in \
          imported modules, so the entry would sit in a module neither of them points back to and \
          a consumer reaching either through its own imports would not see it. Write the \
          annotation in the module that declares one of them."

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
      specExt.addEntry (asyncDecl := anchor) env { theoremName := declName, target, comment }
}

/-!
## `@[characterization]` — the theorems that pin a definition down

`@[specifies]` records a claim, and nothing checks it beyond the target resolving. A
*characterization* is the stronger thing, and it is checkable. It comes in three parts:

* a **property** — a predicate `P` with an argument of the definition's type;
* an **existence** theorem — that the definition satisfies `P`;
* a **uniqueness** theorem — that anything satisfying `P` is related to anything else satisfying
  `P` by some relation `R`.

Together those say: the definition is *the* object with property `P`, up to `R`.

```lean
@[characterization property entropy "the Shannon axioms"]
def IsEntropy (p : Distribution α) (h : ℝ) : Prop := …

@[characterization existence]
theorem isEntropy_entropy (p : Distribution α) : IsEntropy p (entropy p) := …

@[characterization uniqueness]
theorem IsEntropy.unique (h₁ : IsEntropy p x) (h₂ : IsEntropy p y) : x = y := …
```

The two theorems name the *predicate*, not the definition, and by default read it off their own
statements. The predicate is the hub because a definition can have more than one characterization
— entropy by the Shannon axioms and entropy by a variational formula — and hanging every part off
the definition would let a tool assemble the pieces of one into the other.

`R` is a relation rather than equality outright because plenty of objects are only determined up
to a.e. equality, or up to isomorphism.

### What is checked, and what is not

The shapes are checked by `isDefEq`, not by matching syntax: the existence theorem's statement has
to *be* `P … (definition …)`, and the uniqueness theorem's has to relate two objects that its own
hypotheses say satisfy `P`. A tool reading a complete bundle back out can therefore report
"characterized" as a checked fact rather than as an author's assertion, which is the whole
difference from `@[specifies]`.

What is *not* checked is that the characterization says anything. `P x := (x = definition)` is a
well-formed characterization that conveys nothing, and so is a `P` that is subtly the wrong
property. The checks buy well-formedness; the reader still has to read `P` and `R`, which is why
any presentation of a characterization has to show both in full, and why a predicate mentioning
the definition it characterizes draws a warning (`characterization.checkNotCircular`).

Two further gaps, both deliberate:

* nothing requires `P` to be `R`-invariant, so a bundle gives `P x → R x definition` and not the
  converse. The first is what a reader needs; the second is extra work for no gain here.
* uniqueness is propositional. "Unique up to *unique* isomorphism" is a term-level statement, and
  a characterization recorded here with `R x y := Nonempty (x ≃ y)` loses the canonicity. For
  universal properties, Mathlib's bundled `IsColimit`-style formulation is the right tool and this
  is a weaker shadow of it.

### Feeding `specEntries`

Both theorems of a characterization are also, trivially, part of the specification of the
definition, so each writes a `SpecEntry` as well. A consumer that only knows about `@[specifies]`
— "which definitions has nobody said anything about" — keeps working without learning about the
second extension.

### One attribute name, and no attribute on the relation

Attribute names are global and unqualified, and a collision between two libraries makes them
mutually un-importable (see the note on the `specifies` name above). The three roles therefore
share one registered name, distinguished by a mandatory keyword.

The relation gets no attribute at all: it is read off the uniqueness theorem's conclusion. That is
the only thing that could work — a relation like `Setoid.r s` is a partial application with no
declaration to annotate in the first place, and requiring one on `Eq` and `Filter.EventuallyEq`
would make every project re-annotate core and Mathlib before it could state a uniqueness theorem.

### Where the annotation lives

A predicate and the definition it characterizes need not be declared in the same module, and the
case that needs them not to be is a *shared* predicate — `IsCondExp`, say — registered against
each of several definitions from those definitions' own modules:

```lean
attribute [characterization property myDefinition] SomeImportedPredicate
```

An attribute writes its entry into the module being elaborated, so this records the claim where a
reader of `myDefinition` finds it. Without it a shared predicate would have to be copied, once per
definition, into every module that wanted to use it.

What is rejected is only the case where the two declarations an entry relates are *both* imported.
The entry would then sit in a module neither of them points back to, and a consumer that reached
either through its own imports would never see it. Same rule for `@[specifies]`, whose entries
relate a theorem and a definition.

### The same `.olean` caveats

`CharEntry`'s field layout, `CharRole`'s constructor list, and the name of `charExt` are all part
of the on-disk format, for exactly the reasons spelled out for `SpecEntry` in the module docstring.
-/

/-- Which of the three parts of a characterization a `@[characterization …]` annotation records.

The constructor list is part of the `.olean` format — see the note on compatibility in the module
docstring before changing it. -/
inductive CharRole where
  /-- The predicate an object of the definition's type may or may not satisfy. -/
  | property
  /-- The theorem that the definition satisfies the predicate. -/
  | existence
  /-- The theorem that the predicate determines its subject up to a relation. -/
  | uniqueness
deriving Repr, Inhabited, BEq

/-- The keyword that selects this role in the attribute. -/
def CharRole.keyword : CharRole → String
  | .property => "property"
  | .existence => "existence"
  | .uniqueness => "uniqueness"

/-- One `@[characterization …]` annotation: the declaration it was written on, which part of a
characterization that declaration is, and the predicate/definition pair the part belongs to.

Both `property` and `target` are recorded on every entry, including the theorems, so that the
parts of one characterization can be grouped without re-deriving anything — a predicate may
characterize more than one definition, and a theorem belongs to exactly one of those bundles.

The field layout is part of the `.olean` format — see the note on compatibility in the module
docstring before changing it. -/
structure CharEntry where
  /-- The annotated declaration. -/
  declName : Name
  /-- What this declaration contributes. -/
  role : CharRole
  /-- The characterizing predicate. Equal to `declName` on a `.property` entry. -/
  property : Name
  /-- The definition being characterized. -/
  target : Name
  /-- On a `.uniqueness` entry, the theorem's conclusion as written, pretty-printed with its own
  variable names (`x = y`, `f =ᵐ[μ] g`) — the "up to what" of the characterization, and the thing
  a presentation should show. Empty on the other roles. -/
  relation : String := ""
  /-- On a `.uniqueness` entry, the head constant of that conclusion (`Eq`,
  `Filter.EventuallyEq`, …), for grouping and filtering. Anonymous when there is none, and on the
  other roles. -/
  relationHead : Name := .anonymous
  /-- The author's justification, as written in the attribute. Empty when omitted. -/
  comment : String := ""
deriving Repr, Inhabited, BEq

/-- Every `@[characterization]` annotation of the current module and of everything it imports, in
declaration order. -/
initialize charExt : SimplePersistentEnvExtension CharEntry (Array CharEntry) ←
  registerSimplePersistentEnvExtension {
    addEntryFn := Array.push
    addImportedFn := fun entries => entries.flatten
  }

/-- Every characterization annotation visible in `env`, in declaration order. The entry point for
tools that want the parts; most will want `characterizations` instead, which assembles them. -/
def charEntries (env : Environment) : Array CharEntry :=
  charExt.getState env

/-- The definitions `pred` is registered as characterizing. Empty for a predicate that carries no
`@[characterization property]`, which is what the attribute uses to reject a theorem pointing at
something nobody declared to be a characterizing property. -/
def characterizedBy (env : Environment) (pred : Name) : Array Name :=
  (charEntries env).filterMap fun e =>
    if e.role == .property && e.property == pred then some e.target else none

/-- One definition, one property claimed to characterize it, and the theorems supplying the two
halves of that claim.

Assembled from `charEntries`; not itself persisted, so its layout is free to change. -/
structure Characterization where
  /-- The characterizing predicate. -/
  property : Name
  /-- The definition it characterizes. -/
  target : Name
  /-- The author's note on the predicate. -/
  comment : String := ""
  /-- The theorems stating that `target` satisfies `property`. -/
  existence : Array CharEntry := #[]
  /-- The theorems stating that `property` determines its subject up to a relation. -/
  uniqueness : Array CharEntry := #[]
deriving Repr, Inhabited

/-- Whether both halves of the claim are present. A characterization with a property and an
existence theorem but no uniqueness theorem says no more than a `@[specifies]` annotation does:
the definition has the property, and so might anything else. -/
def Characterization.isComplete (c : Characterization) : Bool :=
  !c.existence.isEmpty && !c.uniqueness.isEmpty

/-- Every characterization visible in `env`, complete or not, in declaration order of the
predicates.

Quadratic in the number of annotations, like `specTheoremsFor`; group `charEntries` yourself if
you need this for a whole library at once. -/
def characterizations (env : Environment) : Array Characterization :=
  let entries := charEntries env
  entries.filterMap fun p =>
    if p.role != .property then none
    else some {
      property := p.property
      target := p.target
      comment := p.comment
      existence := entries.filter fun e =>
        e.role == .existence && e.property == p.property && e.target == p.target
      uniqueness := entries.filter fun e =>
        e.role == .uniqueness && e.property == p.property && e.target == p.target }

/-- The characterizations claimed for `target`, complete or not. -/
def characterizationsOf (env : Environment) (target : Name) : Array Characterization :=
  (characterizations env).filter (·.target == target)

/-- Whether some property is claimed to characterize `target` *and* both halves of that claim have
been supplied. This is the question the audit asks: a definition that is merely specified is one a
reader has to take partly on faith, and one that is characterized is not. -/
def isCharacterized (env : Environment) (target : Name) : Bool :=
  (characterizationsOf env target).any (·.isComplete)

/-! ### Reading the shapes

Everything below decides, from elaborated types, whether a declaration really has the shape its
annotation claims. Three rules hold throughout:

* comparison is `isDefEq`, not syntactic matching, so a theorem stated in unfolded form still
  counts. The price is that the predicate has to be a `def`, `structure` or `class` the elaborator
  can see through, not something `opaque`.
* metavariables are created *inside* whatever telescope they will be unified against. A
  metavariable cannot be assigned a free variable introduced after it was created, so opening the
  predicate before entering the theorem's binders would make every check fail.
* a trial that may fail runs under `withoutModifyingState`, since a failed `isDefEq` can leave
  partial assignments behind that would poison the next trial.
-/

/-- `pred` applied to fresh metavariables, paired with the metavariable in its last argument
position — the *characterized slot*, the one an object of the definition's type goes into.

`none` when `pred` is not a predicate at all: it has to take at least one argument and land in
`Prop`. The last argument is the slot by convention; a predicate with several arguments of the
definition's type characterizes the last of them. -/
private def openPredicate (pred : Name) : MetaM (Option (Expr × Expr)) := do
  let P ← Meta.mkConstWithFreshMVarLevels pred
  let (args, _, body) ← Meta.forallMetaTelescope (← Meta.inferType P)
  if args.isEmpty then return none
  unless (← instantiateMVars body).isProp do return none
  return some (mkAppN P args, args.back!)

/-- `target` applied to fresh metavariables, at every arity from fully applied down to bare.

A characterization can be of the definition applied to its arguments (`IsCondExp μ f (μ[f|m])`,
the usual case) or of the definition itself as a function, and nothing in the annotation says
which, so both are tried — fully applied first, since that is what authors mean far more often. -/
private def openTargetAtEachArity (target : Name) : MetaM (Array Expr) := do
  let d ← Meta.mkConstWithFreshMVarLevels target
  let (args, _, _) ← Meta.forallMetaTelescope (← Meta.inferType d)
  return (Array.range (args.size + 1)).reverse.map fun k => mkAppN d (args.extract 0 k)

/-- Whether `pred` is a predicate on the type of `target`: its characterized slot accepts `target`
applied to some prefix of `target`'s own arguments. -/
private def isPredicateOn (pred target : Name) : MetaM Bool := do
  let some (_, slot) ← openPredicate pred | return false
  let slotType ← Meta.inferType slot
  for t in ← openTargetAtEachArity target do
    let tType ← Meta.inferType t
    if ← withoutModifyingState (Meta.isDefEq slotType tType) then return true
  return false

/-- Whether `thmType` states that `target` satisfies `pred` — that is, whether it is, under its
binders, `pred` applied to arguments whose last is `target` applied to some prefix of its own.

Forcing the slot to be `target` *before* unifying the whole statement is what makes a single
error message possible: without it a statement of the right shape about the wrong object would
leave the slot holding something else, or nothing at all.

The one false negative worth knowing about: the witness has to be *built from* the definition,
syntactically. `IsDouble 2 4` says that `double 2` satisfies `IsDouble 2`, and says it
definitionally, but unification cannot run `double` backwards to discover that, so it is rejected.
Writing the witness as `double 2` is both accepted and clearer. -/
private def statesExistence (thmType : Expr) (pred target : Name) : MetaM Bool :=
  Meta.forallTelescopeReducing thmType fun _ concl => do
    let some (papp, slot) ← openPredicate pred | return false
    for t in ← openTargetAtEachArity target do
      let ok ← withoutModifyingState do
        if ← Meta.isDefEq slot t then Meta.isDefEq concl papp else return false
      if ok then return true
    return false

/-- If `e` is `pred` applied to arguments, the object in its characterized slot.

`none` also when the slot comes back undetermined: a hypothesis that does not say *which* object
satisfies the property is not one the conclusion can be relating. -/
private def predSlotIn? (pred : Name) (e : Expr) : MetaM (Option Expr) :=
  withoutModifyingState do
    let some (papp, slot) ← openPredicate pred | return none
    unless ← Meta.isDefEq e papp do return none
    let s ← instantiateMVars slot
    -- `s` is built from the ambient free variables, so it outlives the state restore; a leftover
    -- metavariable would not.
    return if s.hasExprMVar then none else some s

/-- Whether `thmType` states that `pred` determines its subject up to a relation, and if so that
relation: the conclusion as written, and its head constant.

Two shapes are accepted, both after telescoping the binders:

* `… → pred … x → … → pred … y → R x y`, two hypotheses in `pred`, related to each other;
* `… → pred … x → … → R x (target …)`, one hypothesis, related to the definition itself. That is
  the form Mathlib usually writes (`condExp_unique`) and it is just as good: with the existence
  theorem in hand, `P x → R x definition` is exactly the conclusion a reader wants, and no
  symmetry of `R` is needed to get there.

The relation has to be *applied* — the conclusion's last two arguments are the related pair. One
written inline, as `Nonempty (x ≃ y)` is, has to be given a name and stated as `IsoRel x y`, which
a presentation wants anyway for the same reason it wants a named predicate: something to show the
reader and link to. -/
private def statesUniqueness (thmType : Expr) (pred target : Name) :
    MetaM (Option (String × Name)) :=
  Meta.forallTelescopeReducing thmType fun binders concl => do
    let args := concl.getAppArgs
    if args.size < 2 then return none
    let lhs := args[args.size - 2]!
    let rhs := args[args.size - 1]!
    let sameTerm (x y : Expr) : MetaM Bool := withoutModifyingState (Meta.isDefEq x y)
    -- whether the conclusion relates `a` and `b`, in either order
    let relates (a b : Expr) : MetaM Bool := do
      if (← sameTerm lhs a) && (← sameTerm rhs b) then return true
      if (← sameTerm lhs b) && (← sameTerm rhs a) then return true
      return false
    let mut slots := #[]
    for b in binders do
      if let some s ← predSlotIn? pred (← Meta.inferType b) then
        slots := slots.push s
    let mut ok := false
    for a in slots do
      for b in slots do
        unless a == b do
          if ← relates a b then ok := true
    unless ok do
      let targets ← openTargetAtEachArity target
      for a in slots do
        for t in targets do
          if ← relates a t then ok := true
    unless ok do return none
    return some ((← Meta.ppExpr concl).pretty (width := 1000),
      concl.getAppFn.constName?.getD .anonymous)

/-- The characterizing property `declName` is about, guessed from its own statement: for an
existence theorem the head of the conclusion, for a uniqueness theorem the head of the first
hypothesis that names one. Only constants already registered as characterizing properties count,
which is what keeps the guess from latching onto an unrelated `Membership` or `Filter`.

Deliberately syntactic where the shape checks are not: this decides *which* claim is being made,
and a near-miss here would silently file the annotation under the wrong predicate rather than
report that the author has to be explicit. -/
private def inferProperty (env : Environment) (thmType : Expr) (role : CharRole) :
    MetaM (Option Name) :=
  Meta.forallTelescopeReducing thmType fun binders concl => do
    let registered (n : Name) : Bool := !(characterizedBy env n).isEmpty
    if role == .existence then
      match concl.getAppFn.constName? with
      | some n => return if registered n then some n else none
      | none => return none
    for b in binders do
      if let some n := (← Meta.inferType b).getAppFn.constName? then
        if registered n then return some n
    return none

/-- The constants a candidate property is built out of. A `structure` or `class` has its fields'
types nowhere in here, so the circularity check below does not see through one — a limitation, not
a soundness hole, since the check is a warning either way. -/
private def predicateUses (info : ConstantInfo) : Array Name :=
  info.type.getUsedConstants ++ (info.value?.map Expr.getUsedConstants).getD #[]

/-- `` `a` ``, `` `a` and `b` ``, `` `a`, `b` and `c` `` — for listing candidate targets in an
error message. -/
private def andList (ns : Array Name) : MessageData :=
  match ns.toList.reverse with
  | [] => m!"nothing"
  | [n] => m!"`{n}`"
  | n :: rest =>
    m!"{MessageData.joinSep (rest.reverse.map fun r => m!"`{r}`") ", "} and `{n}`"

/-! ### The attribute -/

/--
`@[characterization property definition "why"]`, `@[characterization existence]` and
`@[characterization uniqueness]` mark the three parts of a claim that a definition is *the* object
with a given property: the predicate, the theorem that the definition satisfies it, and the
theorem that nothing else does — up to a relation read off that theorem's own conclusion.

```lean
@[characterization property entropy "the Shannon axioms"]
def IsEntropy (p : Distribution α) (h : ℝ) : Prop := …

@[characterization existence]
theorem isEntropy_entropy (p : Distribution α) : IsEntropy p (entropy p) := …

@[characterization uniqueness]
theorem IsEntropy.unique (h₁ : IsEntropy p x) (h₂ : IsEntropy p y) : x = y := …
```

The role keyword is required. The predicate on the two theorems is optional — by default it is
read off the statement — and can be given when the guess is wrong or ambiguous, as
`@[characterization uniqueness IsEntropy]`. A comment may follow in either position; on the
property it is the place to say what the characterization is *called*.

Unlike `@[specifies]`, the shapes are checked: a theorem whose statement is not what its role
claims is a build error, not a wrong entry in a published specification.
-/
syntax (name := characterization) (priority := high) &"characterization"
  ppSpace (&"property" <|> &"existence" <|> &"uniqueness")
  (ppSpace ident)? (ppSpace str)? : attr

register_option characterization.checkNotCircular : Bool := {
  defValue := true
  descr := "warn when a predicate carrying `@[characterization property f]` mentions `f`, which \
    would make the characterization vacuous"
}

/-- The role named by `stx`.

Three shapes have to be read, because the same source text arrives differently depending on which
parser produced it: a `&"keyword"` in an alternation becomes a wrapper node of kind
`token.property`, a bare one becomes an atom (whose kind is its own text), and `Attr.simple` would
deliver an identifier. All three carry the word in the last component of the kind, or in the
identifier. -/
private def roleOf? (stx : Syntax) : Option CharRole :=
  let word :=
    if stx.isIdent then toString stx.getId
    else match stx.getKind with
      | .str _ s => s
      | _ => ""
  match word with
  | "property" => some .property
  | "existence" => some .existence
  | "uniqueness" => some .uniqueness
  | _ => none

initialize registerBuiltinAttribute {
  name := `characterization
  descr := "mark this declaration as one of the three parts of a characterization of a definition"
  applicationTime := .afterTypeChecking
  add := fun declName stx attrKind => do
    unless attrKind == .global do
      throwError "`characterization` must be a global attribute: a characterization is a claim \
        about the definition, not about a section or a namespace"

    -- `@[characterization existence]` is an identifier followed by one identifier, which is also
    -- exactly what `Attr.simple` accepts. `priority := high` should mean the parser above wins,
    -- but both shapes are handled so that a change in that resolution is not a silent failure.
    let (roleStx, hubStx?, commentStx?) :=
      if stx.getKind == ``Lean.Parser.Attr.simple then
        (stx[1][0], none, none)
      else
        (stx[1], stx[2].getOptional?, stx[3].getOptional?)
    let some role := roleOf? roleStx
      | throwError "invalid `characterization` attribute, expected `@[characterization property \
          myDefinition]`, `@[characterization existence]` or `@[characterization uniqueness]`"
    let comment := (commentStx?.bind Syntax.isStrLit?).getD ""

    let env ← getEnv
    let some info := env.find? declName
      | throwError "unknown declaration `{declName}`"

    if role == .property then
      if ← isProof info then
        throwError "`characterization property` belongs on a predicate, but `{declName}` is a \
          proof. The property is the statement a characterization is *about*; the theorem that \
          the definition satisfies it carries `@[characterization existence]`"
      let some hubStx := hubStx?
        | throwError "`@[characterization property]` needs the definition it characterizes, as \
            `@[characterization property myDefinition]`"
      let target ← Elab.realizeGlobalConstNoOverloadWithInfo hubStx
      if target == declName then
        throwError "`{declName}` cannot characterize itself"
      let some targetInfo := env.find? target
        | throwError "unknown declaration `{target}`"
      if ← isProof targetInfo then
        throwError "`{target}` is itself a proof, but `characterization property` names the \
          definition the annotated predicate is a property of"
      unless ← Meta.MetaM.run' (isPredicateOn declName target) do
        throwError "`{declName}` cannot characterize `{target}`: a characterizing property has to \
          land in `Prop` with a last argument of the type its definition has, or returns, so that \
          `{declName} … ({target} …)` is a proposition. Here the property is\
          {indentExpr info.type}\nand the definition is{indentExpr targetInfo.type}"
      let some anchor := anchor? env declName target
        | throwError "cannot record a characterization of `{target}` by `{declName}`: both are \
            declared in imported modules, so the entry would sit in a module neither of them \
            points back to and a consumer reaching either through its own imports would not see \
            it. Write the annotation in the module that declares one of them."
      if (charEntries env).any fun e =>
          e.role == .property && e.declName == declName && e.target == target then
        throwError "`{declName}` is already registered as a characterizing property of `{target}`"

      -- A property that refers to the definition it characterizes is satisfied by that definition
      -- for no reason at all, and pins nothing down. Nearly always a mistake, but only nearly —
      -- the reference can sit in a side condition that carries none of the content — so it is a
      -- warning, as the corresponding check on `@[specifies]` is.
      if characterization.checkNotCircular.get (← getOptions) then
        if (predicateUses info).contains target then
          logWarning m!"`{declName}` is marked as a characterizing property of `{target}`, but it \
            mentions `{target}`: a property that refers to the definition it characterizes pins \
            nothing down. Set `characterization.checkNotCircular` to `false` to silence this."

      modifyEnv fun env =>
        charExt.addEntry (asyncDecl := anchor) env
          { declName, role := .property, property := declName, target, comment }
    else
      unless ← isProof info do
        throwError "`characterization {role.keyword}` belongs on a theorem, but `{declName}` is \
          not a proposition"
      let pred ← match hubStx? with
        | some id => Elab.realizeGlobalConstNoOverloadWithInfo id
        | none =>
          match ← Meta.MetaM.run' (inferProperty env info.type role) with
          | some p => pure p
          | none =>
            throwError "cannot tell which characterizing property `{declName}` is part of: \
              nothing in its statement is registered with `@[characterization property]`. Name it \
              explicitly, as `@[characterization {role.keyword} MyProperty]`"
      let targets := characterizedBy env pred
      if targets.isEmpty then
        throwError "`{pred}` is not a characterizing property: mark it with \
          `@[characterization property theDefinition]` before naming it here"

      -- A predicate may characterize more than one definition, and this theorem belongs to
      -- exactly one of those bundles; which one is settled by the statement, not by the author.
      let mut found : Option (Name × String × Name) := none
      for target in targets do
        if found.isSome then continue
        if role == .existence then
          if ← Meta.MetaM.run' (statesExistence info.type pred target) then
            found := some (target, "", .anonymous)
        else
          if let some (rel, relHead) ← Meta.MetaM.run' (statesUniqueness info.type pred target) then
            found := some (target, rel, relHead)
      let some (target, relation, relationHead) := found
        | if role == .existence then
            throwError "`{declName}` does not state that {andList targets} satisfies `{pred}`: \
              that would be `{pred} … x`, with `x` built from the definition. Its statement is\
              {indentExpr info.type}"
          else
            throwError "`{declName}` does not state that `{pred}` determines its subject: that \
              would end in a relation between two objects its hypotheses say satisfy `{pred}`, \
              or between one such object and {andList targets}. Its statement is\
              {indentExpr info.type}"

      let some anchor := anchor? env declName target
        | throwError "cannot record that `{declName}` is the {role.keyword} part of the \
            characterization of `{target}`: both are declared in imported modules, so the entry \
            would sit in a module neither of them points back to and a consumer reaching either \
            through its own imports would not see it. Write the annotation in the module that \
            declares one of them."
      if (charEntries env).any fun e =>
          e.role == role && e.declName == declName && e.property == pred && e.target == target then
        throwError "`{declName}` is already registered as the {role.keyword} part of the \
          characterization of `{target}` by `{pred}`"

      modifyEnv fun env =>
        charExt.addEntry (asyncDecl := anchor) env
          { declName, role, property := pred, target, relation, relationHead, comment }
      -- A theorem of a characterization is a fortiori part of the specification of the
      -- definition, so it is recorded as one too — see the note on `specEntries` above. Skipped
      -- when the author also wrote `@[specifies]`, whose own duplicate check is an error.
      unless (specEntries env).any fun e => e.theoremName == declName && e.target == target do
        modifyEnv fun env =>
          specExt.addEntry (asyncDecl := anchor) env
            { theoremName := declName, target, comment }
}

end LeanSpec
