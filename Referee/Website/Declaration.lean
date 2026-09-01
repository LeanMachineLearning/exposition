module

public import Referee.Website.Graph

open Lean
open Lean.Meta
open Verso.Doc
open Verso.Genre
open Manual

namespace Referee

open Verso.Output Html
open MeaningGraph
open ChallengeGen
open SubVerso.Highlighting (Highlighted)

public section

/-!
# One declaration's page

Everything that renders a single declaration: the card at the top, then — each gated on the project
having the thing at all — what it rests on and how far that reaches outside the project, its
specification and any characterization of the definition it speaks for, how it changed since the
baseline, when its meaning last moved, the reader's own verdict on it, its dependency graph, and the
self-contained minimal file that is the artifact the whole tool exists to produce.

`mkDeclPart` at the bottom is the assembly, and the order the sections come in is the order the
questions arrive: what does it say, what does it rest on, has it moved, what have you made of it.
The rest of this file is the sections.
-/

/-- Renders one declaration card with docs, statement, links, and dependencies.

Rendered on the declaration's own page and nowhere else: module pages, the claims page and the
sorries page all list declarations compactly instead. The card therefore carries no "Details" link —
it used to, and once the module pages stopped showing cards it pointed at the page it was already
on. -/
private def mkDeclBlock (decl : DeclInfo) (ctx : SiteContext) : Block Manual :=
  Id.run do
    let issueUrl := issueUrlOf ctx.repoUrl? decl.name decl.moduleName decl.source? decl.dependsOnSorry
    let sourceUrl := sourceUrlOf ctx.repoUrl? decl.source? ctx.sourceRef
    let mut blocks : Array (Block Manual) := #[]
    blocks := blocks ++ decl.docBlocks
    let hasDoc := !decl.docBlocks.isEmpty
    if !hasDoc then
      blocks := blocks.push (.para #[.emph #[.text "No docstring."]])
    if let some docstringBlock := decl.docstringBlock? then
      blocks := blocks.push docstringBlock
    blocks := blocks.push (.para #[.bold #[.text "Code"]])
    -- Definitions show their body: the value *is* the content. Theorems show only the statement —
    -- the proof has its own section below, and repeating it here made the card twice as long for
    -- no gain. The highlighted rendering covers the whole command, so it is only used where the
    -- whole command is wanted; a statement-only view falls back to the trimmed source text, which
    -- loses hover types but keeps the pretty-printed signature above, which has them.
    --
    -- `Highlight.declCode` is what keeps the whole command from including the docstring: it is part
    -- of the command, and the card has just rendered it above. The text fallback never had the
    -- problem — `displaySignature` is cleaned of docstring and attributes at collection time — which
    -- is why the duplicate showed on definitions and structures and not on theorems.
    let showsBody :=
      match decl.kind with
      | .definition | .structure | .typeclass | .inductive => true
      | _ => false
    blocks := blocks.push <|
      if showsBody then
        leanCodeBlock ((ctx.declHighlights.get? decl.name).map (Highlight.declCode decl.name))
          decl.displaySignature
      else .code decl.displaySignature
    -- The proof, then the links. Nothing about the declaration's dependencies: "Type uses" and
    -- "Body uses" are both drawn in the graph directly below, and a second rendering of the same
    -- fact in the place a reader looks for what the declaration *says* is worse than none. "Used by"
    -- has no second home but answers a question this page is not for: who else depends on this is a
    -- property of the library, not of the claim.
    if let some proof := decl.proofText? then
      blocks := blocks.push <| .other (Block.details { summary := "Proof" }) #[.code proof]
    if let some block := mkLinkParagraph sourceUrl issueUrl then
      blocks := blocks.push block
    let cardData : DeclCardData := {
      anchorId := anchorIdOf decl.name
      kindLabel := decl.kind.label
      isLemma := decl.isLemma
      isInstanceDecl := decl.isInstanceDecl
      tags := #[
        if decl.dependsOnSorry then some "depends transitively on sorry" else none
      ].filterMap id
    }
    .other (Block.declCard cardData) blocks

/-! ## Audit surface and trust

The numbers and chains a reader needs in order to decide how much of a result they are being
asked to take on faith, rather than merely whether it is flagged. -/

/-- The distinct constants outside the project that a declaration's closure bottoms out in: its
imported assumptions, as opposed to the project declarations it builds on. Together with the
closure size this is the "how much must I accept to believe this" measure. -/
def externalConstants (decl : DeclInfo) (ctx : SiteContext) : Array Name :=
  let closure := #[decl.name] ++ decl.dataTransDeps
  let externals := closure.foldl (init := ({} : Std.HashSet Name)) fun acc name =>
    match ctx.declByName.get? name with
    | none => acc
    | some d => (meaningDeps d).foldl (init := acc) fun acc dep =>
        if ctx.declByName.contains dep then acc else acc.insert dep
  externals.toArray.qsort Name.lt

/-- A shortest chain of project declarations from `start` to one that itself contains a `sorry`,
following the same edges the closure follows.

`dependsOnSorry` alone sends a reader hunting: it says a gap exists somewhere below, not where.
Returns `none` when the declaration is clean, and also when the `sorry` is inherited from outside
the project — in which case no project declaration on the path owns it, and the caller says so
instead of pointing at an innocent one. -/
private def sorryChain (start : Name) (ctx : SiteContext) : Option (Array Name) := Id.run do
  let mut parents : Std.HashMap Name Name := {}
  let mut visited : Std.HashSet Name := ({} : Std.HashSet Name).insert start
  let mut frontier : Array Name := #[start]
  let mut culprit? : Option Name := none
  -- Bounded by the declaration count: a BFS visits each declaration at most once, and an explicit
  -- bound keeps this structurally terminating.
  for _ in [0:ctx.declByName.size] do
    if culprit?.isSome || frontier.isEmpty then
      break
    let mut next : Array Name := #[]
    for name in frontier do
      if let some d := ctx.declByName.get? name then
        if d.hasOwnSorry then
          culprit? := some name
          break
        -- `deps`, the raw type-and-body edges: a `sorry` reached only through a proof is still a
        -- real gap, and `dependsOnSorry` — which this chain exists to explain — is `collectAxioms`,
        -- which walks proofs. Neither `meaningDeps` nor `closureDeps` will do: both are `typeDeps`
        -- for a non-alias theorem, so the proof that reaches the `sorry` is exactly what they drop,
        -- and the chain would come back empty for the declarations that most need it.
        for dep in d.deps do
          if !visited.contains dep && ctx.declByName.contains dep then
            visited := visited.insert dep
            parents := parents.insert dep name
            next := next.push dep
    frontier := next
  let some culprit := culprit? | return none
  -- Walk parent pointers back to `start`, then reverse into dependency order.
  let mut path : Array Name := #[culprit]
  let mut cursor := culprit
  for _ in [0:ctx.declByName.size] do
    match parents.get? cursor with
    | none => break
    | some p =>
      path := path.push p
      cursor := p
  return some path.reverse

/-- Number of project declarations in a declaration's closure. Used both as the audit-surface
measure and to rank claims: among results nothing else builds on, the one resting on the most
machinery is usually the substantial one. -/
def closureSize (decl : DeclInfo) (ctx : SiteContext) : Nat :=
  (decl.dataTransDeps.filter ctx.declByName.contains).size

/-- A list of declarations rendered one per line with closure size, module, and trust status. The
workhorse index rendering: used for module contents, claims, and the trust checklist. -/
def declIndexList (decls : Array DeclInfo) (ctx : SiteContext)
    (noteOf : DeclInfo → String := fun _ => "") : Option (Block Manual) :=
  let entries := decls.filterMap fun decl => do
    let href ← ctx.declPageHrefs.get? decl.name
    pure {
      name := decl.name.toString
      href := href
      kind := decl.displayKind
      group := declGroupOfFields decl.kind.label decl.isLemma decl.isInstanceDecl
      deps := some (closureSize decl ctx)
      note := noteOf decl
      dependsOnSorry := decl.dependsOnSorry
      : DeclIndexEntry
    }
  if entries.isEmpty then none else some (.other (Block.declIndex { entries }) #[])

/-! ## Upstream trust

Everything else on this site measures the project. This measures what the project *rests* on, which
for a Mathlib-based development is the larger half by far — and which no amount of `sorry`-checking
inside the project can speak to. See the note in `Collect.lean` for why the analysis is
package-granular and why closing over the Lake graph is sound. -/

/-- The upstream packages a declaration's *statement* reaches into, closed over the Lake dependency
graph and bounded by what was actually loaded.

"Statement" rather than "closure": see the note in `Collect.lean`. An upstream proof is rechecked by
the kernel and needs no trust; an upstream definition a statement is about does. -/
def restsOnPackages (decl : DeclInfo) (ctx : SiteContext) : Array Name :=
  (trustClosure ctx.packages decl.upstreamPackages).toArray.filter (fun name =>
    ctx.loadedPackages.contains name &&
      !(ctx.packages.any fun pkg => pkg.name == name && (pkg.isProject || pkg.isToolchain)))
    |>.qsort Name.lt

/-- The unaudited packages whose definitions appear in a declaration's statement: what a reader is
asked to take on faith beyond the project and the toolchain. Empty when everything the statement
reaches has been vouched for. -/
private def untrustedPackagesOf (decl : DeclInfo) (ctx : SiteContext) : Array Name :=
  (restsOnPackages decl ctx).filter (!ctx.trusted.contains ·)

/-- The packages the project actually reaches, closed over the Lake graph, project excluded. -/
def reachedPackages (decls : Array DeclInfo) (ctx : SiteContext) : Array Name :=
  let direct := decls.foldl (init := #[]) fun acc decl => acc ++ decl.upstreamPackages
  (trustClosure ctx.packages direct).toArray.filter (fun name =>
    ctx.loadedPackages.contains name &&
      !(ctx.packages.any fun pkg => pkg.name == name && pkg.isProject))
    |>.qsort Name.lt

/-- The audit-surface and trust summary shown near the top of a declaration page. -/
private def mkAuditBlocks (decl : DeclInfo) (ctx : SiteContext) : Array (Block Manual) :=
  Id.run do
  let externals := externalConstants decl ctx
  let inProject := decl.dataTransDeps.filter ctx.declByName.contains
  let mut blocks : Array (Block Manual) := #[]
  blocks := blocks.push <| .para #[
    .bold #[.text "Audit surface: "],
    .text s!"{inProject.size} project declarations, {externals.size} external constants"
  ]
  -- Trust. The ordinary three axioms are what every classical Lean development uses, so they are
  -- reported as "nothing unusual" rather than listed; anything else is an actual assumption.
  let ordinary : Array Name := #[``Classical.choice, ``propext, ``Quot.sound]
  let unusual := decl.axioms.filter fun a => !ordinary.contains a && a != ``sorryAx
  if decl.dependsOnSorry then
    let reason : Array (Inline Manual) :=
      if decl.hasOwnSorry then
        #[.text "this declaration contains a ", .code "sorry"]
      else
        match sorryChain decl.name ctx with
        | some chain =>
          #[.text "depends on "] ++
            (joinInlines (chain.toList.map fun n => #[.code n.toString]) #[.text " → "]) ++
            #[.text ", which contains a ", .code "sorry"]
        | none => #[.text "inherits a ", .code "sorry", .text " from outside this project"]
    blocks := blocks.push <| .para <| #[.bold #[.text "⚠ Not fully proved: "]] ++ reason
  else
    blocks := blocks.push <| .para #[.bold #[.text "✓ Proved: "], .text "no ", .code "sorry",
      .text " anywhere in its closure"]
    -- The caveat hangs under the checkmark and not under the warning above it. A reader who sees
    -- "⚠ Not fully proved" already discounts the line; a checkmark is the one that invites being
    -- read as a verdict, which is the reading this paragraph exists to refuse. It says what the
    -- check *is* — this tool's reading of one build's recorded axioms — because every limitation
    -- below follows from that and from nothing else.
    blocks := blocks.push <| .para #[
      .text "This is the tool's own reading of one build's recorded axioms, and it is not robust \
        against an author who wants it to pass. Checking meant to be relied on should go through ",
      .link #[.text "Comparator"] "https://github.com/leanprover/comparator",
      .text ", which replays the proof through the kernel from an export against an explicit list \
        of permitted axioms."
    ]
  if !unusual.isEmpty then
    blocks := blocks.push <| .para <|
      #[.bold #[.text "Extra axioms: "]] ++
        joinInlines (unusual.toList.map fun a => #[.code a.toString]) #[.text " · "]
  -- Upstream trust. Only reported as a gap, and phrased as one about *meaning*: the proofs upstream
  -- are kernel-checked, so what is left to take on faith is what the statement is about.
  let untrusted := untrustedPackagesOf decl ctx
  if !untrusted.isEmpty then
    blocks := blocks.push <| .para <|
      #[.bold #[.text "Statement rests on unaudited definitions from: "]] ++
        joinInlines (untrusted.toList.map fun p => #[.code p.toString]) #[.text " · "] ++
        #[.text ". See ", .link #[.text "Sorries and assumptions"] "sorries/", .text "."]
  return blocks

/-! ## Specifications

The one thing on the site that is not derived. Everything else here — closures, `sorry` chains,
axioms — is computed from the environment and is true whether or not anyone thought about it. A
specification is a *claim*: the author saying "these properties are what this definition means".
The tool can only carry it, check that it points somewhere real, and — the part that does the
auditing work — show where it is absent.

All of it is gated on `SiteContext.usesSpecs`; see the note there. -/

/-- The theorems put forward as a definition's specification, with their statements.

Takes the links rather than the declaration because the caller filters them first: a theorem the
characterization above already showed is not shown again here. See `charShownNames`. -/
private def specTheoremRows (links : Array SpecLink) (ctx : SiteContext) : Array SpecRow :=
  links.map fun link =>
    match ctx.declByName.get? link.name with
    | some thm => {
        name := link.name.toString
        href := ctx.declPageHrefs.getD link.name ""
        kind := thm.displayKind
        comment := link.comment
        -- The statement is the point: a reader judges whether these properties pin the definition
        -- down by reading them, not by counting them.
        signature := thm.displaySignature
      }
    | none => { name := link.name.toString, kind := "Theorem", comment := link.comment }

/-- The definitions `decl` is declared to specify.

No statements here, unlike the other direction. The reader is on the theorem's page and already has
its statement above; what they are missing is which definition it speaks for — and a definition's
"statement" can be a whole structure body, which would swamp the note it is meant to carry. The
target may also be outside the project (a `Mathlib` definition), in which case there is no page to
link to and the name is shown plain.

Takes the links rather than the declaration for the same reason `specTheoremRows` does. -/
private def specTargetRows (links : Array SpecLink) (ctx : SiteContext) : Array SpecRow :=
  links.map fun link =>
    let target? := ctx.declByName.get? link.name
    { name := link.name.toString
      href := ctx.declPageHrefs.getD link.name ""
      kind := (target?.map (·.displayKind)).getD "Definition"
      comment := link.comment }

/-! ### Characterizations

The stronger claim, and the only one on the site whose *shape* has been machine-checked: that the
property really is a predicate on the definition's type, that the existence theorem really states
the definition satisfies it, that the uniqueness theorem really relates two objects satisfying it.

None of which says the claim is worth anything. `IsEntropy x := (x = entropy p)` passes every one of
those checks and pins nothing down, and a characterization up to a relation coarse enough — parity,
say — is barely a characterization at all. So the rendering shows the property's body and the
relation in full, and says plainly which half is checked and which half is the reader's job. A page
that reported "characterized ✓" and left it there would be worse than one that said nothing. -/

/-- One declaration of a characterization as a row: role, name, statement, and — on a uniqueness
row — the relation it stops at. -/
private def charPartRow (ctx : SiteContext) (role : String) (name : Name)
    (comment : String := "") (relation : String := "") : CharPartRow :=
  let decl? := ctx.declByName.get? name
  { role
    name := name.toString
    href := ctx.declPageHrefs.getD name ""
    kind := (decl?.map (·.displayKind)).getD ""
    comment
    relation
    -- Empty for a part outside the project, which then renders as a bare labelled link. The
    -- property is the one part where that really hurts, and it is also the part least likely to
    -- be elsewhere: a predicate written to characterize a project's own definition lives with it.
    signature := (decl?.map (·.displaySignature)).getD "" }

/-- The definition of the relation a characterization stops at, when there is one worth showing.

Three cases, and the order matters. A relation declared by the project gets its source form and a
link to its page. One from an upstream package has no page here, so it gets the pretty-printed type
and body the graph panels use — which for a relation is the informative half: `Filter.EventuallyEq`
has type `Filter α → (α → β) → (α → β) → Prop`, every argument reading as a hypothesis and nothing
saying it means `∀ᶠ x in l, f x = g x`. One from the toolchain gets nothing: `=` and `↔` are not
what a reader is stuck on, and `{α : Sort u} → α → α → Prop` in a slot meant to explain something
would be worse than an empty slot. -/
private def charRelationRow? (ctx : SiteContext) (head : Name) : Option CharPartRow :=
  if head.isAnonymous then none
  else match ctx.declByName.get? head with
    | some d =>
      some { role := "Relation"
             name := head.toString
             href := ctx.declPageHrefs.getD head ""
             kind := d.displayKind
             signature := d.displaySignature }
    | none =>
      match ctx.externalDecls.get? head with
      | none => none
      | some ext =>
        if ctx.toolchainPackages.contains ext.package then none
        else
          some { role := "Relation"
                 name := head.toString
                 kind := ext.package.toString
                 -- The same `signature := value` shape the upstream graph panels use, so an
                 -- upstream constant reads the same wherever the site shows one.
                 signature :=
                   if ext.value.isEmpty then ext.signature
                   else s!"{ext.signature}\n  :=\n{ext.value}" }

/-- The characterizations claimed for `decl`, as rendered rows.

The author's comment rides on the property row rather than on the bundle, because that is where
they wrote it and what it is about: `"the Shannon axioms"` names the property, not the claim. -/
private def charRows (decl : DeclInfo) (ctx : SiteContext) : Array CharRow :=
  decl.characterizedBy.map fun bundle =>
    { property := bundle.property.toString
      relations := bundle.uniqueness.filterMap fun u =>
        if u.relation.isEmpty then none else some u.relation
      hasExistence := !bundle.existence.isEmpty
      hasUniqueness := !bundle.uniqueness.isEmpty
      -- Deduplicated: several uniqueness theorems normally stop at the same relation, and
      -- repeating its definition once per theorem would bury the parts it is there to explain.
      relationDefs := (bundle.uniqueness.foldl (init := (#[] : Array Name)) fun acc u =>
        if acc.contains u.relationHead then acc else acc.push u.relationHead).filterMap
          (charRelationRow? ctx)
      parts :=
        #[charPartRow ctx "Property" bundle.property (comment := bundle.comment)]
          ++ bundle.existence.map (charPartRow ctx "Existence")
          ++ bundle.uniqueness.map fun u =>
              charPartRow ctx "Uniqueness" u.name (relation := u.relation) }

/-- The claims `decl` is one of the three parts of, for its own page.

The counterpart of `specTargetRows`, and no statements here for the same reason: the reader is on
the part's page with its statement above, and what they are missing is the claim it serves. -/
private def charPartOfRows (decl : DeclInfo) (ctx : SiteContext) : Array SpecRow :=
  decl.characterizes.map fun link =>
    { name := link.target.toString
      href := ctx.declPageHrefs.getD link.target ""
      kind :=
        match link.role with
        | "property" => "Characterizing property"
        | "existence" => "Existence"
        | "uniqueness" => "Uniqueness"
        | other => other
      comment :=
        match link.role with
        | "property" => "The property claimed to determine it."
        | "existence" => s!"States that it satisfies {link.property}."
        | "uniqueness" => s!"States that {link.property} determines its subject."
        | _ => "" }

/-- The characterization section of a declaration page.

Above the specification, not below it, because it answers the same question and answers it better:
a reader who has seen that `entropy` is the unique object with a given property does not need to
weigh a list of properties it happens to satisfy. When there is no characterization the section is
simply absent — unlike a missing specification, which is reported. A definition with no
characterization is the overwhelmingly common case even in a project that uses the attribute, and a
note on every page saying so would be nagging rather than auditing. -/
private def mkCharBlocks (decl : DeclInfo) (ctx : SiteContext) : Array (Block Manual) :=
  Id.run do
  if !ctx.usesChars then
    return #[]
  if decl.characterizedBy.isEmpty then
    -- A part of someone else's claim, which its own statement does not reveal. Rendered without a
    -- section heading of its own: it is a cross-reference, not a section.
    if decl.characterizes.isEmpty then
      return #[]
    return #[
      .para #[.bold #[.text "Part of a characterization"]],
      .other (Block.specList { entries := charPartOfRows decl ctx }) #[]
    ]
  let rows := charRows decl ctx
  let complete := rows.filter fun r => r.hasExistence && r.hasUniqueness
  let mut blocks : Array (Block Manual) := #[]
  blocks := blocks.push <|
    .other (Block.sectionHeading s!"Characterization ({decl.characterizedBy.size})") #[]
  blocks := blocks.push <| .para <|
    (if complete.isEmpty then
      #[.text "A property its author put forward as characterizing ", .code decl.name.toString,
        .text ", with the claim not yet complete — each card below says which half is missing. "]
    else
      #[.text "What the author offers as pinning ", .code decl.name.toString,
        .text " down completely: a property it satisfies, and a theorem that nothing else does. "])
    ++ #[.text "This is a stronger claim than a specification, and unlike a specification its \
      shape is checked — that the property is a predicate on ", .code decl.name.toString,
      .text "'s type, that the existence theorem states this definition satisfies it, and that the \
        uniqueness theorem relates two objects that do."]
  blocks := blocks.push <| .other (Block.charList { entries := rows }) #[]
  -- The caveat is not boilerplate and is not optional. The checked half is easy to mistake for the
  -- whole thing, and a reader who does so has been misled by this page rather than by the author.
  blocks := blocks.push <| .para #[
    .bold #[.text "What this does not settle. "],
    .text "Nothing checks that the property says the right thing: a property that mentions ",
    .code decl.name.toString,
    .text " itself would satisfy every test above and pin nothing down. Nor is the relation \
      anything but reported — a definition determined only up to a coarse relation is determined \
      correspondingly less, and ",
    .code "=", .text " is the strongest case rather than the only one. Both are printed above in \
      full because reading them is the only way to tell."
  ]
  if !decl.characterizes.isEmpty then
    blocks := blocks.push <| .para #[.bold #[.text "Part of a characterization"]]
    blocks := blocks.push <| .other (Block.specList { entries := charPartOfRows decl ctx }) #[]
  return blocks

/-- The declarations the characterization section directly above has already put on the page: for
each claim, its property and both kinds of theorem.

Both theorems of a characterization also register as `@[specifies]` annotations — see
`DeclInfo.characterizedBy` — so without this every characterized definition listed them twice on one
page: once inside the claim that determines it, and again a few lines below as loose properties it
happens to satisfy. The second listing is strictly weaker than the first and says nothing the first
did not, so it is the one that goes.

Empty when `usesChars` is false, which is exactly when no characterization is rendered: nothing is
ever hidden from the specification on the strength of a card the reader cannot see. -/
private def charShownNames (decl : DeclInfo) (ctx : SiteContext) : Std.HashSet Name :=
  if !ctx.usesChars then {} else
    decl.characterizedBy.foldl (init := ({} : Std.HashSet Name)) fun acc bundle =>
      let acc := bundle.existence.foldl (·.insert ·) (acc.insert bundle.property)
      bundle.uniqueness.foldl (fun acc u => acc.insert u.name) acc

/-- The claims the "Part of a characterization" listing has already named, for the other direction:
a theorem that is one of a claim's three parts also carries `@[specifies]` for the same target, so
the target is otherwise named twice on the theorem's page. -/
private def charShownTargets (decl : DeclInfo) (ctx : SiteContext) : Std.HashSet Name :=
  if !ctx.usesChars then {} else
    decl.characterizes.foldl (init := ({} : Std.HashSet Name)) fun acc link =>
      acc.insert link.target

/-- The specification section of a declaration page: two directions and one absence.

The absence is the reason this is worth rendering at all. A definition with a specification gets a
list a reader can check; a definition without one gets told so, in the same place, because "nobody
has said what this means" is exactly the finding an auditor is looking for and it is invisible
otherwise.

Both directions are filtered against what the characterization above already showed; see
`charShownNames`. The absence is *not* filtered — it is decided on the unfiltered annotations, so a
definition whose only `@[specifies]` theorems are its characterization's is told nothing rather than
told it has no specification. It has one; it is the section above. -/
private def mkSpecBlocks (decl : DeclInfo) (ctx : SiteContext) : Array (Block Manual) :=
  Id.run do
  if !ctx.usesSpecs then
    return #[]
  let shownNames := charShownNames decl ctx
  let specifiedBy := decl.specifiedBy.filter fun link => !shownNames.contains link.name
  let shownTargets := charShownTargets decl ctx
  let specifies := decl.specifies.filter fun link => !shownTargets.contains link.name
  let mut blocks : Array (Block Manual) := #[]
  if !specifiedBy.isEmpty then
    blocks := blocks.push <|
      .other (Block.sectionHeading s!"Specification ({specifiedBy.size})") #[]
    blocks := blocks.push <| .para <| #[
      .text "What the author offers as evidence that ", .code decl.name.toString,
      .text " is the intended definition. Each of these theorems is marked ", .code "@[specifies]",
      .text " in the source, so this list is the author's claim rather than anything derived."
    ] ++
      -- Said only when something was in fact dropped, and said here rather than as a note on the
      -- missing rows: a count that no longer matches the project's annotations is the one thing a
      -- reader might otherwise take for a bug in the site.
      (if specifiedBy.size == decl.specifiedBy.size then #[] else
        #[.text " The characterization's own theorems are not repeated here — they are above, in \
          the stronger claim they belong to."])
    blocks := blocks.push <|
      .other (Block.specList { entries := specTheoremRows specifiedBy ctx }) #[]
  else if decl.isDefinitionLike && decl.specifiedBy.isEmpty then
    blocks := blocks.push <| .para #[
      .bold #[.text "No specification. "],
      .text "No theorem in this project is marked as part of what ", .code decl.name.toString,
      .text " means, so nothing here settles whether it is the intended definition — that is a \
        judgement the reader has to make from the body."
    ]
  if !specifies.isEmpty then
    blocks := blocks.push <| .para #[.bold #[.text "Part of a specification"]]
    blocks := blocks.push <|
      .other (Block.specList { entries := specTargetRows specifies ctx }) #[]
  return blocks

/-! ## Revisions

Everything below is gated on `SiteContext.diff?`, i.e. on `--baseline` having been given. See
`Referee/Diff.lean` for what is compared and what the comparison costs. -/

/-- How many declarations' *meaning* rests on this one: the size of the re-reading a change to it
forces on someone who has already worked through the library.

The reverse of `dataTransDeps`, which follows `meaningDeps`, so it counts the declarations whose
statements this one is part of and not the ones whose proofs merely call it. -/
def dependentCount (name : Name) (ctx : SiteContext) : Nat :=
  ctx.dependentCounts.getD name 0

/-- Turns one change into the row both the Changes page and the declaration banner render. -/
def changeRowOf (change : DeclChange) (ctx : SiteContext) (since : String := "")
    : ChangeRowData :=
  let decl? := ctx.declByName.get? change.name
  let statementDiff? := do
    let old ← change.oldStatement?
    let decl ← decl?
    pure (statementDiff old decl.expandedSignature)
  {
    name := change.name.toString
    href := (ctx.declPageHrefs.get? change.name).getD ""
    module := (decl?.map (·.modulePath)).getD ""
    kind := change.kind.slug
    label := change.kind.label
    diff := statementDiff?.getD {}
    -- An addition has no baseline version to align against, so its statement is shown whole — and
    -- as the author wrote it rather than as elaborated, which for a Mathlib-heavy statement is the
    -- difference between three lines and twenty-five of instance binders. The *comparison* still
    -- runs on the elaborated type; only what is displayed here changes.
    statement := if change.kind == .added then (decl?.map (·.displaySignature)).getD "" else ""
    causes := change.causes.filterMap fun cause =>
      ctx.declPageHrefs.get? cause |>.map fun href =>
        { label := cause.toString, href? := some href }
    sinceDate := (ctx.provenance?.bind (·.dateForRef? since)).getD ""
    trustNotes := change.trustNotes
    dependents := dependentCount change.name ctx
    since := since
  }

/-- The banner at the top of a declaration page whose meaning moved since the baseline.

Nothing is rendered for a declaration that did not change, and nothing at all without a baseline: a
badge reading "unchanged" on 1400 pages is noise, and it is the changed ones a returning reader is
looking for. A proof-only change *is* shown, because it explains why the source no longer matches
the reader's notes — but it says in the same breath that no re-reading follows from it. -/
private def mkChangeBlocks (decl : DeclInfo) (ctx : SiteContext) : Array (Block Manual) :=
  match ctx.diff?, ctx.changes.get? decl.name with
  | some report, some change =>
    if change.isNoteworthy then
      #[.other (Block.changeBanner (changeRowOf change ctx (since := report.baselineLabel))) #[]]
    else #[]
  | _, _ => #[]

/-- The revision selector's payload, or nothing without a ledger. -/
def mkRevisionPickerBlocks (decls : Array DeclInfo) (ctx : SiteContext)
    : Array (Block Manual) :=
  match ctx.provenance? with
  | none => #[]
  | some p =>
    let rows := decls.filterMap fun decl =>
      (ctx.provEntries.get? decl.name).map fun entry => {
        name := decl.name.toString
        href := (ctx.declPageHrefs.get? decl.name).getD ""
        module := decl.modulePath
        changedAt := entry.changedAt
        firstSeenAt := entry.firstSeenAt
        everChanged := entry.changeCount > 0
        kind := entry.lastKind
        dependents := dependentCount decl.name ctx
        : RevisionPickerDecl
      }
    #[.other (Block.revisionPicker { revisions := p.revisions, decls := rows }) #[]]

/-- The provenance line for one declaration, or nothing at all.

Nothing without `--provenance`, and nothing for a declaration the ledger has never seen — which is
the normal state of anything added since the last fold, and says nothing worth a line. -/
private def mkProvenanceBlocks (decl : DeclInfo) (ctx : SiteContext) : Array (Block Manual) :=
  match ctx.provenance? with
  | none => #[]
  | some p =>
    match p.rowFor decl.name ctx.provEntries ctx.provEdits with
    | none => #[]
    | some row => #[.other (Block.provenanceLine row) #[]]

/-! ## Audit state

What a *reader* has decided, as opposed to what the environment says. See `Referee/Audit.lean` for
what acceptance is taken to mean and why coverage is derived rather than recorded. -/

/-- The statement closure of a declaration, as links, in dependency order.

The order is `dataTransDeps`', which is topological — every dependency precedes what uses it — for
the same reason the extraction closure is: it is a dependency-respecting order. A reading queue wants
exactly that, so it comes for free. The *contents* are the meaning closure, not the extraction one:
a reader asked to accept this declaration is not asked to accept a lemma some proof merely called. -/
private def auditClosureLinks (decl : DeclInfo) (ctx : SiteContext) : Array LinkInfo :=
  decl.dataTransDeps.filterMap fun dep =>
    if !ctx.declByName.contains dep then none
    else some { label := dep.toString, href? := ctx.declPageHrefs.get? dep }

/-- The verdict control at the top of a declaration page. -/
private def mkAuditControlBlocks (decl : DeclInfo) (ctx : SiteContext) : Array (Block Manual) :=
  #[.other (Block.auditControl {
      name := decl.name.toString
      project := ctx.rootPrefix.toString
      closure := auditClosureLinks decl ctx
      meaning := meaningKeyOf decl
      -- Positionally parallel to `closure`, so it is filtered by the same predicate.
      closureMeanings := decl.dataTransDeps.filterMap fun dep =>
        (ctx.declByName.get? dep).map meaningKeyOf
    }) #[]]

/-- The claims listing for `claims`, in the order given, with each row's docstring inlined.

The docstring is the declaration's own `docBlocks` — the very blocks its card renders — so the
listing says what each claim is about in the author's words, formatted as it is formatted
everywhere else. That is the whole reason this listing is built in Lean; see `ClaimRow`. -/
def mkClaimListBlock (claims : Array DeclInfo) (ctx : SiteContext) : Option (Block Manual) :=
  -- One pass, so that rows and docstrings cannot fall out of step: a claim with no page is dropped
  -- from both or from neither.
  let listed := claims.filter (ctx.declPageHrefs.contains ·.name)
  let rows := listed.map fun decl => ({
    name := decl.name.toString
    href := ctx.declPageHrefs.getD decl.name ""
    deps := closureSize decl ctx
    dependsOnSorry := decl.dependsOnSorry
    docLength := decl.docBlocks.size
    : ClaimRow })
  let docs := listed.flatMap (·.docBlocks)
  if rows.isEmpty then none else some (.other (Block.claimList { rows }) docs)

/-- The library, as a page listing claims with their audit state needs it.

Closures are emitted as indices into a shared name table. The same few hundred strings appear tens
of thousands of times across the closures of a library this size — brownian-motion has 116,519
transitive edges — and writing them out would put megabytes of duplicated text on one page.

With `featured?`, the result is an **excerpt**: the same payload cut down to those declarations and
everything in their closures. That subset is exactly what the rows need — a claim's coverage is a
question about its own closure and about nothing else — and it is what lets the landing page carry
the same live rows as the claims page without carrying the whole table twice. `names` and `decls`
stay parallel and `closure` still indexes into them, so the client renders an excerpt with the code
it renders the full table with.

`dataId` identifies the build either way, so it is computed over the whole library and not over
what survived the cut. -/
def mkAuditData (decls : Array DeclInfo) (ctx : SiteContext)
    (featured? : Option (Array Name) := none) : AuditData := Id.run do
  let kept : Array DeclInfo :=
    match featured? with
    | none => decls
    | some featured =>
      let wanted := featured.foldl (init := ({} : Std.HashSet Name)) fun acc name =>
        match ctx.declByName.get? name with
        | none => acc
        | some decl => decl.dataTransDeps.foldl (·.insert ·) (acc.insert name)
      decls.filter (wanted.contains ·.name)
  let names := kept.map (·.name)
  let index : Std.HashMap Name Nat :=
    names.zipIdx.foldl (fun acc (n, i) => acc.insert n i) {}
  let entries := kept.map fun decl => {
    kind := decl.displayKind
    group := declGroupOfFields decl.kind.label decl.isLemma decl.isInstanceDecl
    module := decl.modulePath
    href := (ctx.declPageHrefs.get? decl.name).getD ""
    claim := decl.isClaim
    sorryDep := decl.dependsOnSorry
    unspecified := decl.isDefinitionLike && decl.specifiedBy.isEmpty && ctx.usesSpecs
    change := ((ctx.changes.get? decl.name).map (·.kind.slug)).getD ""
    meaning := meaningKeyOf decl
    closure := decl.dataTransDeps.filterMap index.get?
    : AuditDecl
  }
  return {
    project := ctx.rootPrefix.toString
    dataId := dataFingerprint decls
    names := names.map (·.toString)
    decls := entries
    excerpt := featured?.isSome
    renamed := ((ctx.diff?.map (·.renamed)).getD #[]).map fun (a, b) => (a.toString, b.toString)
    baselineLabel := (ctx.diff?.map (·.baselineLabel)).getD ""
  }

/-- The minimal dependency file, inline.

This is the artifact the whole tool exists to produce: one self-contained Lean file holding
everything a reader must accept in order to make sense of the statement, with proofs replaced by
`sorry`. Previously it was reachable only as an off-site link to `live.lean-lang.org`; here it is
on the page, highlighted, with types on hover.

When the file failed to elaborate, that is stated rather than hidden — the highlighting pass *is*
an elaboration, so its errors are exactly the evidence that this particular minimal file is not
trustworthy as written. -/
private def mkMinimalFilePart (decl : DeclInfo) (ctx : SiteContext) : Option (Part Manual) :=
  match ctx.minimalFiles.get? (anchorIdOf decl.name) with
  | none => none
  | some file =>
    let status : Array (Block Manual) :=
      if file.errors.isEmpty then
        #[.para #[.text "This file was elaborated while the site was built, and compiles."]]
      else
        #[.para #[
            .bold #[.text "⚠ This minimal file does not compile. "],
            .text "Extraction is imperfect for this declaration. What the library proves is still \
              the statement on the declaration's own page; it is this standalone rendering of its \
              dependencies that is not usable as-is."
          ],
          .code (String.intercalate "\n" file.errors.toList)]
    some {
      title := #[.text "Minimal Lean file"]
      titleString := s!"Minimal Lean file for {decl.name}"
      metadata := some {
        file := some "minimal"
        shortTitle := some "Minimal file"
        tag := some (.provided (minimalFileTagOf decl.name))
        number := false
      }
      content := #[
        .para #[
          .text "Everything needed to make sense of ", .code decl.name.toString,
          .text ", in one self-contained file: its transitive dependencies inlined in \
            dependency order, with proofs replaced by ", .code "sorry",
          .text ". Hover any symbol for its type."
        ]
      ] ++ status ++
        #[.other (Block.lean file.code { showProofStates := false, defSite := some false }) #[]]
      subParts := #[]
    }

/-- The declaration-page pointers to its minimal file: the on-site page, the raw download, and the
web editor.

The on-site page is a subpage rather than inline content. That is a concession to size, not a
change of intent: highlighting carries a pretty-printed type for every token, which measured **46×**
the size of the Lean source it describes (10 MB of extracted files became 478 MB of highlighting).
Inlining that on every declaration page would have undone the page-size work entirely. One click,
on-site, fully interactive is the affordable version of "the minimal file is the point".

Three offers, each with its own condition, because they are three different artifacts:

* the **on-site page** needs `highlight-extracted`, which is what renders it;
* the **raw download** needs only `extract`, which wrote the file;
* the **web editor** needs `--site-url`, since `live.lean-lang.org` fetches the file over the
  network and so has to be told where the site is actually published.

They used to be one paragraph gated on the first condition alone, with the download and the editor
sharing a slot as either/or. Both halves of that were wrong. A run without highlighting published
every extracted file and linked none of them, and a run *with* `--site-url` silently dropped the
download — the editor is not a substitute for it, being a round trip through a third-party site
that cannot open a file the reader has no URL for. -/
def mkMinimalFileLink (decl : DeclInfo) (ctx : SiteContext) : Array (Block Manual) :=
  Id.run do
  let stem := anchorIdOf decl.name
  let mut offers : Array (Array (Inline Manual)) := #[]
  if let some file := ctx.minimalFiles.get? stem then
    -- Root-relative, because Verso puts a `<base href>` on every page pointing at the site root. A
    -- bare `minimal/` therefore resolved to `<root>/minimal/` — which is why this link led nowhere
    -- — rather than to the subpage of the declaration it is written on.
    let pageUrl := (ctx.declPageHrefs.getD decl.name "") ++ "minimal/"
    let note :=
      if file.errors.isEmpty then
        #[.text " (types on hover; verified to compile)"]
      else
        #[.text " (types on hover; ", .bold #[.text "⚠ does not currently compile"], .text ")"]
    offers := offers.push <|
      #[.link #[.bold #[.text "Read the minimal Lean file"]] pageUrl] ++ note
  if ctx.extractedStems.contains stem then
    offers := offers.push #[.link #[.text "download the raw file"] s!"extracted/{stem}.lean"]
    if let some base := ctx.siteUrl? then
      offers := offers.push
        #[.link #[.text "open it in the Lean web editor"] (leanEditorUrl base decl.name)]
  if offers.isEmpty then
    return #[]
  return #[.para <| #[.text "Self-contained, with its dependencies inlined and proofs replaced by ",
    .code "sorry", .text ": "] ++ joinInlines offers.toList #[.text " · "] ++ #[.text "."]]

/-- Deduplicates `names`, keeping the first occurrence of each. -/
private def dedupNames (names : Array Name) : Array Name :=
  (names.foldl (init := ((#[] : Array Name), ({} : Std.HashSet Name))) fun (out, seen) n =>
    if seen.contains n then (out, seen) else (out.push n, seen.insert n)).1

/-- The characterization views of a definition's dependency graph: one per complete claim.

The picture a declaration page draws by default is what the definition is *built from*, which for a
constructed object is an expensive answer to a question the reader may not be asking. A
characterization offers a second and usually far cheaper one: to know what an object *is* it is
enough to read the property that pins it down and the relation the uniqueness theorem stops at, and
neither of those mentions the construction. Building a stochastic integral is work; recognising one
is a predicate. This draws that second picture — the two seeds and everything they mean.

The definition and the two theorems are drawn but *not* expanded: their own dependencies enter only
where the picture already contains them. That is not a truncation to apologise for, it is the claim
the view is making, and the construction is one button away for a reader who wants it. What the
overlap shows is real either way — an edge from the property's closure into the definition means the
two genuinely share that dependency.

Only complete bundles get a view. Existence without uniqueness determines nothing, so offering it as
something to read *instead of* the construction would be a false economy — the reader would come
away thinking they knew what the object was. -/
private def mkCharGraphViews (decl : DeclInfo) (ctx : SiteContext) (baseSize : Nat) :
    Array GraphView :=
  decl.characterizedBy.filterMap fun bundle =>
    if !bundle.isComplete then none else
    -- The property, and each distinct relation the claim stops at. A toolchain relation (`Eq`,
    -- `Iff`) stays in the seed list and is dropped by `withUpstreamNodes`, on the same grounds as
    -- `charRelationRow?` drops it from the cards: a node labelled `Eq` explains nothing.
    let heads := bundle.uniqueness.foldl (init := (#[] : Array Name)) fun acc u =>
      if u.relationHead.isAnonymous then acc else acc.push u.relationHead
    let seeds := dedupNames (#[bundle.property] ++ heads)
    -- The seeds and their meaning closures: everything a reader has to accept in order to read the
    -- claim. A seed outside the project contributes no closure here and is drawn in the upstream
    -- band instead, which is why it is pinned below.
    let expanded := dedupNames <| seeds.foldl (init := #[]) fun acc s =>
      match ctx.declByName.get? s with
      | none => acc
      | some d => (acc.push s) ++ d.dataTransDeps
    -- The two theorems: nodes, not roots. Nothing below them is pulled in beyond what the seeds
    -- already reach, which for the existence theorem is the whole point — its statement names the
    -- definition, and following that would drag the construction back in through the side door.
    let claimNames := dedupNames
      (expanded ++ bundle.existence ++ bundle.uniqueness.map (·.name))
    let claimDecls := claimNames.filterMap ctx.declByName.get?
    let graphDecls := (dedupNames (claimNames.push decl.name)).filterMap ctx.declByName.get?
    -- `claimDecls` rather than `graphDecls` for the band, which differ by the definition alone: the
    -- upstream a view reports has to be the upstream of what it says you need, and the definition's
    -- own unaudited references are exactly what this view says you can skip. The theorems stay in,
    -- because a reader does read their statements — and because a property that lives upstream is
    -- drawn in the band, where its edges to those theorems are the only thing tying the picture
    -- together.
    let data := transitiveReduce
      (withUpstreamNodes
        (mkGraphData graphDecls ctx.declPageHrefs meaningDeps (focus? := decl.name)
          (projectName := ctx.rootPrefix.toString))
        claimDecls ctx meaningDeps (statements := seeds) (pinned := seeds))
    -- Exactly the nodes whose dependencies were not followed: the definition and the theorems,
    -- minus any of them the seeds' closures reached anyway — a predicate built with a proof term
    -- can genuinely contain one of its own theorems, and a node whose parents *are* all drawn must
    -- not claim otherwise.
    let expandedSet : Std.HashSet Name := expanded.foldl (·.insert ·) {}
    -- Keyed by the node's own id, which is the name as a string, rather than by `Name`: that is
    -- what the payload carries, and re-parsing it to compare would be a second chance to disagree.
    let cut : Std.HashSet String :=
      (#[decl.name] ++ bundle.existence ++ bundle.uniqueness.map (·.name)).foldl
        (init := {}) fun acc n => if expandedSet.contains n then acc else acc.insert n.toString
    let marked := data.nodes.map fun (n : GraphNode) =>
      if cut.contains n.id then { n with unexpanded := true } else n
    let data := { data with nodes := marked }
    some {
      label := s!"via {bundle.property.getString!}"
      -- The count last and stated flatly in both directions. A characterization is usually the
      -- cheaper thing to read and sometimes is not, and a note that only knew how to report a
      -- saving would be advertising rather than measuring.
      note := s!"What the claim itself rests on: the property {bundle.property}, the relation it \
        determines its subject up to, and everything those two mean. The definition and the claim's \
        theorems are drawn but not expanded — that is what the view claims, not a gap in it. \
        {data.nodes.size} nodes here against {baseSize} for the construction."
      unexpandedNote := s!"Drawn without its dependencies. This view follows what \
        {bundle.property} and the relation mean and stops there, so nothing above this node in the \
        picture is what it rests on — that is the Construction view's subject, left out here on \
        purpose rather than missing."
      nodes := data.nodes
      edges := data.edges }

/-- Builds a dedicated detail page for one declaration: its own card, its dependency graph, its
audit surface and trust summary, and the claims its author makes about it.

That is the order the questions come in. What is this (the card), what does it rest on (the graph),
what would accepting it cost and is anything wrong with it (the audit), and what did the author say
it means (the characterization, then the specification).

Deliberately *not* a card per transitive dependency, which is what an early version rendered: a
closure here reaches 522 declarations, and 522 cards is a page nobody reads. The one-line-per-entry
listings that replaced those cards are gone too, for the weaker form of the same reason — they
enumerated in text exactly what the picture directly above them draws. -/
def mkDeclPart (decl : DeclInfo) (ctx : SiteContext) : Part Manual :=
  Id.run do
  -- The graph's node set follows `meaningDeps` (via `dataTransDeps`), as everything the reader is
  -- shown does: a declaration reachable only through a proof embedded in some definition's value is
  -- not part of what this declaration means. The wider `transDeps` is the extraction closure and
  -- appears nowhere on the page.
  let graphDecls := #[decl] ++ (decl.dataTransDeps.filterMap ctx.declByName.get?)
  let mut blocks : Array (Block Manual) := #[]
  -- Above the card, not below it: a reader who accepted this declaration in the baseline has to
  -- learn that their reading is void *before* re-reading it, not after.
  blocks := blocks ++ mkChangeBlocks decl ctx
  blocks := blocks.push (mkDeclBlock decl ctx)
  -- Immediately under the card: "has this changed since I read it" is the question a returning
  -- reader asks before deciding whether to read it again, and it is about the card above.
  blocks := blocks ++ mkProvenanceBlocks decl ctx
  -- Still part of reading the declaration itself, so it stays with the card. Linked once: there
  -- used to be a second link further down whose relative path resolved *underneath* the declaration
  -- page and 404'd, and the page ended up advertising the same artifact three times.
  blocks := blocks ++ mkMinimalFileLink decl ctx
  -- Transitively reduced: 23 declarations here carry 68 direct edges, most of them implied by a
  -- longer path, and drawing all of them buries the structure in crossings and forces the layout
  -- so wide that it no longer fits the viewport. What survives is the *essential* dependency
  -- structure — every removed edge is still a real dependency, reachable along the path that
  -- remains. That invariant is why the reduction has to go through the condensation: on a graph
  -- with a cycle the naive rule breaks it outright, disconnecting the focus declaration from
  -- everything it rests on.
  let graphData := transitiveReduce
    (withUpstreamNodes
      (mkGraphData graphDecls ctx.declPageHrefs meaningDeps (focus? := decl.name)
        (projectName := ctx.rootPrefix.toString))
      graphDecls ctx meaningDeps (statements := #[decl.name]))
  -- A characterized definition gets a second picture of what it rests on *as a claim*; see
  -- `mkCharGraphViews`. Empty for everything else, and then the graph is exactly what it was.
  let charViews :=
    if ctx.usesChars then mkCharGraphViews decl ctx graphData.nodes.size else #[]
  let graphData :=
    if charViews.isEmpty then graphData
    else
      let others :=
        if charViews.size == 1 then "The other view asks" else "The other views ask"
      -- "Rests on nothing" is an answer and has to be given. On an uncharacterized page it is the
      -- paragraph above the graph; here that paragraph is suppressed, and the chrome no longer
      -- collapses to the lone-node hint either — the picture has structure in another view — so
      -- this note is the only place left that can say it.
      { graphData with
        viewLabel := "Construction"
        viewNote :=
          if graphData.nodes.size <= 1 then
            s!"Nothing to draw: {decl.name}'s own definition rests on no other declaration in this \
              project and names nothing from a package left unaudited. {others} what it takes to \
              recognise one instead, which is a different question."
          else
            s!"Everything {decl.name} is built from: the closure of its own definition. {others} \
              what it takes to recognise one instead — a different question, and usually a much \
              smaller one."
        views := charViews }
  blocks := blocks.push (.para #[.bold #[.text "Dependency graph"]])
  -- Drawn even when there is nothing to draw. Gating it on having dependencies made the shape of a
  -- declaration page vary with its content, so a reader could not tell "this rests on nothing" from
  -- "the graph is somewhere further down"; a lone node answers the question at a glance, and the
  -- answer is worth having. It also used to hide a graph that did have something to show: a
  -- declaration with no *project* dependencies can still name constants from an unaudited upstream
  -- package, and `withUpstreamNodes` draws those.
  -- Not said when there is a characterization view: "nothing to draw" would be read as a statement
  -- about the picture below it, which in that case has a second view with something in it.
  if graphData.nodes.size <= 1 && charViews.isEmpty then
    blocks := blocks.push (.para #[
      .emph #[.text "Nothing to draw. "],
      .text "Its statement rests on no other declaration in this project, and names nothing from a \
        package left unaudited — so the graph is this declaration alone. That is the answer, not a \
        missing picture."
    ])
  blocks := blocks.push (.other (Block.graph graphData) #[])
  -- Below the picture it is a verdict on. What accepting this declaration would cost is a question
  -- about the closure the graph has just drawn, and the control that records the answer belongs
  -- with the surface it is answering about rather than under the card.
  blocks := blocks ++ mkAuditControlBlocks decl ctx
  blocks := blocks ++ mkAuditBlocks decl ctx
  -- Last, because they answer a different and later question. Everything above says what this
  -- declaration costs to accept; these say what it means. The characterization comes first of the
  -- two: it answers that question and settles it, where a specification only narrows it — and what
  -- it shows is dropped from the specification rather than repeated there, see `charShownNames`.
  blocks := blocks ++ mkCharBlocks decl ctx
  blocks := blocks ++ mkSpecBlocks decl ctx
  return {
    title := #[.code decl.name.toString]
    titleString := decl.name.toString
    metadata := some {
      file := some s!"decl-{anchorIdOf decl.name}"
      shortTitle := some decl.name.getString!
      -- Explicit, so Verso does not derive a tag from the title: names differing only by a
      -- non-ASCII character (`induction_on₂` vs `induction_on₃`) derive the same one.
      tag := some (.provided (declTagOf decl.name))
      number := false
    }
    content := blocks
    subParts := (mkMinimalFilePart decl ctx).toArray
  }

end

end Referee
