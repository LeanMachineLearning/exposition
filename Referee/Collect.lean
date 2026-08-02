module

public import Lean
public import Lean.DeclarationRange
public import Lean.Meta.Instances
public import Lean.Util.Sorry
public import Lake.CLI.Main
public import Lake.Load.Workspace
public import MD4Lean
public import VersoManual
public import VersoManual.Markdown
public import LeanDeps
public import LeanSpec
public import Referee.SourceSyntax

@[expose] public section

/-!
# Collecting the exposed declarations of a project

Walks a compiled project's environment and builds one `DeclInfo` per exposed declaration:
signature, docstring, source location and snippet, kind, and dependency lists.

The dependency analysis itself lives in `LeanDeps` — a standalone module that knows nothing about
this tool's output. This file only decides *which* dependency edges Referee follows
(`meaningDeps` for what a declaration means and rests on, `closureDeps` for the wider extraction
closure) and attaches the results to `DeclInfo`.
-/

open Lake
open Lean
open Lean.Meta
open Verso.Doc
open Verso.Genre
open Manual

namespace Referee

open Verso.Output Html
open LeanDeps

/-- CLI options used to configure site generation. Shared across the `collect`,
`extract`, `build-site`, and `all` subcommands; each one only consults the fields relevant
to it. -/
structure Cli where
  rootPrefix : Option Name := none
  repoUrl : Option String := none
  siteUrl : Option String := none
  siteTitle : Option String := none
  outputDir : Option String := none
  excludeLibs : Array Name := #[]
  /-- Path to the collected-data JSON file: written by `collect`, read by `extract` and
  `build-site`. -/
  dataPath : Option String := none
  /-- Single module to process, used by the `highlight-module` worker subcommand. -/
  moduleName : Option Name := none
  /-- Directory of per-module highlighting JSON written by `highlight`. Read by `build-site`,
  which falls back to `<output>/highlighting` and renders plain code when it is absent. -/
  highlightingDir : Option String := none
  /-- Single input file, used by the `highlight-file` worker subcommand. -/
  inputPath : Option String := none
  /-- Maximum number of worker processes to run at once. Defaults to the CPU count. -/
  jobs : Option Nat := none
  /-- Packages the reader is told to take on trust (`--trust`), each standing for itself *and
  everything it depends on*: trusting `mathlib` trusts `batteries` and `aesop` with it, because
  Mathlib's own correctness already rests on them.

  A render-time flag, like `--repo-url`: the same `data.json` can be rendered with different trust
  sets, which is the point — "what if I have not audited LML" should not need re-importing the
  project. -/
  trustedPackages : Array Name := #[]
  /-- Draw declarations from *audited* packages in the graph's upstream band as well as unaudited
  ones (`--show-trusted-upstream`).

  Off by default, and the default is the interesting judgement. Drawing them answers "what is this
  statement about", but on a Mathlib-backed project it is a median of 21 nodes and a p90 of 53 per
  page — a band several times the size of the project structure underneath it, restating something
  the declaration's own code block at the top of the page already shows, with types on hover. What
  the band is *for* is the part no other view has: the packages nobody has vouched for. Those are
  always drawn.

  Kept as a flag rather than removed because the capability is cheap to carry — the data is collected
  either way — and because on a project whose upstream is small the answer could go the other way. -/
  showTrustedUpstream : Bool := false
  /-- An earlier `collect` output to diff the current one against (`--baseline`).

  A render-time flag for the same reason `--trust` is one: the comparison is a pure function of the
  two JSON files, so a reader can ask "what changed since v0.2" without re-importing anything. With
  none given, the site says nothing about revisions at all. -/
  baselinePath : Option String := none
  /-- What to call the baseline on the page (`--baseline-label`). Defaults to the file name. -/
  baselineLabel : Option String := none
  /-- A `semantic_hash export` JSONL file to read declaration hashes from (`--hashes`).

  A `collect`-time input rather than a render-time flag, unlike `--trust` and `--baseline`: the
  hashes are a property of the compiled environment, so they belong in `data.json` beside every
  other thing derived from it. Optional — without it every hash is `none` and the revision diff
  compares text, exactly as it did before the field existed. -/
  hashesPath : Option String := none
  /-- The provenance ledger (`--provenance`): written and updated by the `provenance` subcommand,
  read by `build-site`.

  One file for both directions, because the ledger is append-only: each run folds the current
  revision into whatever is already there. A render-time flag for `build-site`, gated exactly as
  `--baseline` is — without it the site says nothing about when anything changed. -/
  provenancePath : Option String := none
  /-- What to call this revision in the ledger (`--ref`). Defaults to `git describe --tags
  --always`, which prefers a tag and falls back to a short sha. -/
  revisionRef : Option String := none
deriving Repr

/-- Classification of exposed Lean declarations. -/
inductive DeclKind where
  | theorem
  | definition
  | opaque
  | structure
  | typeclass
  | inductive
  | axiom
  | instance
deriving Repr, BEq, Inhabited, ToJson, FromJson

/-- Human-readable label for each declaration kind. -/
def DeclKind.label : DeclKind → String
  | .theorem => "Theorem"
  | .definition => "Definition"
  | .opaque => "Opaque"
  | .structure => "Structure"
  | .typeclass => "Type Class"
  | .inductive => "Inductive"
  | .axiom => "Axiom"
  | .instance => "Instance"

/-- The kind label shown to a reader, which is finer-grained than `DeclKind`.

Lean records `lemma` and `theorem` as the same kind, and some declarations written with `instance`
elaborate to theorems, so `DeclKind.label` alone would show a `lemma` as "Theorem". A reader
comparing the site against the source should see the keyword the author actually wrote. -/
def displayKindLabel (kindLabel : String) (isLemma isInstanceDecl : Bool) : String :=
  if isInstanceDecl then "Instance"
  else if isLemma then "Lemma"
  else kindLabel

/-- Source file location (path and line range) for a declaration. -/
structure SourceInfo where
  relPath : String
  absPath : System.FilePath
  line : Nat
  endLine : Nat
deriving Repr, ToJson, FromJson

/-- Data container for LinkInfo. -/
structure LinkInfo where
  label : String
  href? : Option String := none
deriving Repr, ToJson, FromJson

/-- Data container for DeclCardData. -/
structure DeclCardData where
  anchorId : String
  shortName : String
  kindLabel : String
  fullName : String
  isLemma : Bool := false
  isInstanceDecl : Bool := false
  tags : Array String := #[]
deriving Repr, ToJson, FromJson, Inhabited

/-- One row of a declaration index: the listing used for module contents, the claims and trust
pages, and a declaration's dependency closures. -/
structure DeclIndexEntry where
  name : String
  href : String
  /-- The label shown to the reader (`displayKindLabel`). -/
  kind : String
  /-- `definition` / `lemma` / `theorem`, matching the sidebar's visibility toggles. -/
  group : String
  /-- Project declarations in its closure, where that is worth showing. -/
  deps : Option Nat := none
  /-- An extra fact about this row, shown after the kind and dependency count. Empty for most
  listings; used by the specification page to say how many properties a definition has. -/
  note : String := ""
  dependsOnSorry : Bool := false
deriving Repr, ToJson, FromJson, Inhabited

/-- Data container for DeclIndexData. -/
structure DeclIndexData where
  entries : Array DeclIndexEntry
deriving Repr, ToJson, FromJson, Inhabited

/-- One row of the claims listing.

The listing is rendered *here* rather than by `audit.js`, unlike everything else on that page,
because a row carries the declaration's docstring and the docstring has to be real markdown — the
same `docBlocks` the declaration's own card renders, through the same Verso pipeline, so that code
spans, emphasis and math look the way they look everywhere else. A client building rows from JSON
can only be handed text, and text is what it looked like.

What the browser still owns is the *state* on the row: coverage, verdict, and the button. Those
arrive as empty slots that `audit.js` fills and refills, which is also why the rows survive a
verdict change untouched — nothing is rebuilt, two spans are rewritten. -/
structure ClaimRow where
  name : String
  href : String
  /-- Project declarations in its statement closure. Shown until the browser replaces it with how
  many of them the reader has accepted, so a reader without JavaScript still gets the number. -/
  deps : Nat := 0
  dependsOnSorry : Bool := false
  /-- How many of the enclosing block's contents are this row's docstring. The rows share one flat
  array of contents — a block extension gets its children as a list, not as a tree — so each says
  how many of them are its own, and the renderer walks the two in step. -/
  docLength : Nat := 0
deriving Repr, ToJson, FromJson, Inhabited

/-- Data container for ClaimListData. The block's contents are every row's docstring blocks
concatenated, divided up by `ClaimRow.docLength`. -/
structure ClaimListData where
  rows : Array ClaimRow
deriving Repr, ToJson, FromJson, Inhabited

/-- One row of a specification listing: on a definition's page a theorem offered as part of its
specification, on a theorem's page a definition the theorem specifies.

Unlike `DeclIndexEntry` this carries the statement and the author's comment, because that is the
whole point of the listing: a reader should be able to judge whether the properties pin the
definition down without following a single link. -/
structure SpecRow where
  name : String
  /-- Empty when the declaration at the other end is not exposed and so has no page of its own. -/
  href : String := ""
  /-- The label shown to the reader (`displayKindLabel`). -/
  kind : String
  /-- The author's note on why this belongs in the specification. Empty when they wrote none. -/
  comment : String := ""
  /-- The statement, source form. Empty where the row is a bare link. -/
  signature : String := ""
deriving Repr, ToJson, FromJson, Inhabited

/-- Data container for SpecListData. -/
structure SpecListData where
  entries : Array SpecRow
deriving Repr, ToJson, FromJson, Inhabited

/-- One of the three declarations a characterization is made of, as rendered: the predicate, a
theorem that the definition satisfies it, or a theorem that nothing else does.

Carries the statement for the same reason `SpecRow` does, and more urgently. A characterization is
checked for *shape* and not for content, so the only thing that tells a reader whether it says
anything is the property's own body and the relation the uniqueness theorem stops at — both of
which are here. -/
structure CharPartRow where
  /-- `Property`, `Existence` or `Uniqueness`, as shown to the reader. -/
  role : String
  name : String
  /-- Empty when the declaration is not exposed and so has no page of its own. -/
  href : String := ""
  /-- The label shown to the reader (`displayKindLabel`). -/
  kind : String := ""
  /-- The author's note, from the attribute. Empty when they wrote none. -/
  comment : String := ""
  /-- On a uniqueness row, the relation it establishes, as written in its conclusion. Empty
  otherwise. -/
  relation : String := ""
  /-- The statement, source form. -/
  signature : String := ""
deriving Repr, ToJson, FromJson, Inhabited

/-- One characterization of a definition, as rendered. -/
structure CharRow where
  /-- The characterizing predicate, for the header sentence. -/
  property : String
  /-- The relations its uniqueness theorems establish, as written. Empty when there are none. -/
  relations : Array String := #[]
  /-- Whether a theorem states that the definition satisfies the property. -/
  hasExistence : Bool := false
  /-- Whether a theorem states that the property determines its subject.

  Kept apart from `hasExistence` rather than collapsed into one "complete" flag because the two
  gaps read differently and the card has to say which one it is: existence without uniqueness is a
  specification wearing a characterization's clothes, and uniqueness without existence is a claim
  about a property that may hold of nothing at all. -/
  hasUniqueness : Bool := false
  /-- The relations' own definitions, deduplicated, in the order the uniqueness theorems introduce
  them.

  Without these the banner names the claim's conclusion and does not say what it *is*:
  `Indistinguishable μ A ⟨M⟩` reads as reassurance whether it means "agree a.s. at every time" or
  something far weaker, and the reader cannot tell which without leaving the page. Since the
  relation is the one part of a characterization that is reported rather than checked, showing it
  is not a convenience.

  Empty for a relation from the toolchain — `=` and `↔` need no introduction, and printing
  `{α : Sort u} → α → α → Prop` where the point is to explain something would be noise. -/
  relationDefs : Array CharPartRow := #[]
  /-- The property, then the existence theorems, then the uniqueness theorems. -/
  parts : Array CharPartRow := #[]
deriving Repr, ToJson, FromJson, Inhabited

/-- Data container for `Block.charList`. -/
structure CharListData where
  entries : Array CharRow
deriving Repr, ToJson, FromJson, Inhabited

/-- One row of the Browse table: every exposed declaration, with the columns a reader sorts and
filters on. Deliberately light — no docstring or statement — since every row of the library rides
along in a single page. -/
structure BrowseRow where
  name : String
  href : String
  /-- Reader-facing kind (`displayKindLabel`). -/
  kind : String
  /-- `definition` / `lemma` / `theorem`, matching the sidebar's visibility toggles. -/
  group : String
  module : String
  chapter : String
  /-- Project declarations in its closure. -/
  deps : Nat
  /-- Distinct constants outside the project its closure bottoms out in. -/
  ext : Nat
  dependsOnSorry : Bool
  /-- Rests on an axiom beyond `Classical.choice`/`propext`/`Quot.sound`. -/
  extraAxioms : Bool
  /-- Theorems declared to be part of this declaration's specification. `none` for anything a
  specification cannot be about (see `DeclInfo.isDefinitionLike`), which is what lets the table
  distinguish "no specification" from "not the sort of thing that has one". -/
  specs : Option Nat := none
  /-- How it changed since the baseline (`ChangeKind.slug`), or `none` when the site was built
  without `--baseline`. The column and its filter exist only in the `some` case, so a site with no
  baseline is exactly the site it was before the field existed. -/
  change : Option String := none
  /-- What this declaration means now (`meaningKeyOf`), so the Verdict column can mark an
  acceptance recorded against a different meaning. Empty on a build without semantic hashes. -/
  meaning : String := ""
  /-- The revision at which its meaning last changed, or `none` without a provenance ledger — which
  is what makes the column and its sort disappear on a site that has none. -/
  changedRef : Option String := none
  /-- The date of that revision, `YYYY-MM-DD`, which is also what the column sorts on: it orders
  correctly as a string, and it is what a reader scans for. -/
  changedDate : String := ""
deriving Repr, ToJson, FromJson, Inhabited

/-- Data container for BrowseData. -/
structure BrowseData where
  rows : Array BrowseRow
  /-- The project name, which is the audit state's storage key.

  Carried here because the Verdict column needs it and this page has no other audit payload: the
  script that owns that state cannot look up a verdict without knowing which project's state to
  read, and it is deliberately the only thing that knows. -/
  project : String := ""
deriving Repr, ToJson, FromJson, Inhabited

/-- Data container for DetailsData. -/
structure DetailsData where
  summary : String
  /-- Rendered already open. The default is shut, which is what a fold is usually for; a chapter on
  the claims listing is the other case — folding it is for putting a chapter you are done with out
  of the way, not for hiding the page's contents until asked. -/
  startsOpen : Bool := false
  /-- Marks a fold whose summary is a heading rather than a control, so it can be styled as one. -/
  headingLevel : Option Nat := none
deriving Repr, ToJson, FromJson, Inhabited

/-- Data container for GraphNode. -/
structure GraphNode where
  id : String
  label : String
  kind : String
  status : String
  groupKey : String
  moduleName : String
  href : String
  /-- True for the declaration whose page this graph is on, so the reader can see at a glance
  which node the picture is about. False everywhere on the whole-repository graph. -/
  focus : Bool := false
  /-- The declaration's statement, source form, for the graph's side panel. -/
  signature : String := ""
  /-- The declaration's docstring, as written. Empty when it has none. -/
  doc : String := ""
  /-- What this declaration means now (`meaningKeyOf`), so the graph can mark the nodes a reader
  has accepted *without* marking the ones they accepted an earlier version of.

  The verdict itself lives in the browser and is never collected; only the key it has to be checked
  against travels with the node. Empty on a build without semantic hashes, which switches the
  staleness half of the check off exactly as it is switched off everywhere else. -/
  meaning : String := ""
  /-- The upstream package this node comes from, or `""` for a project declaration.

  Set on exactly the nodes that belong in the upstream *band* rather than in the dependency rows.
  They are all sinks — nothing in the graph precedes them — so they would otherwise pile into the top
  row and make it several thousand pixels wide; `graph.js` lays them out as a wrapped band grouped by
  this field instead. `status` says whether the package is audited (`"trusted"`/`"untrusted"`). -/
  upstream : String := ""
  /-- The package's depth in the workspace dependency graph (`packageRanks`), which is the order the
  band stacks in: a package sits above one that depends on it, so the band reads the same way the
  dependency rows below it do. -/
  upstreamRank : Nat := 0
deriving Repr, ToJson, FromJson

/-- Data container for GraphEdge. -/
structure GraphEdge where
  source : String
  target : String
deriving Repr, ToJson, FromJson

/-- Data container for GraphData. -/
structure GraphData where
  nodes : Array GraphNode
  edges : Array GraphEdge
  /-- What a node stands for, singular. Used in the graph's own explanatory text, so that a graph
  of modules does not describe itself as a graph of declarations. -/
  unit : String := "declaration"
  /-- The project's own name, which labels the first of its dependency rows the way each upstream
  package labels the first row of its block. -/
  projectName : String := ""
deriving Repr, ToJson, FromJson

/-- One end of a specification link, as written with the `@[specifies]` attribute of the `LeanSpec`
package: the declaration at the other end and the author's note on why the theorem belongs in the
specification (empty when they wrote none).

Used in both directions — on a theorem the `name` is the definition being specified, on a
definition it is a theorem specifying it — because both ends want the same comment. -/
structure SpecLink where
  name : Name
  comment : String := ""
deriving Repr, BEq, ToJson, FromJson, Inhabited

/-- A uniqueness theorem of a characterization, with the relation it stops at.

The relation is the whole load-bearing part and the reason it is carried as text rather than as a
name: `LeanSpec` reads it off the theorem's conclusion as written (`x = y`, `f =ᵐ[μ] g`,
`IsoRel a b`), which is what a reader needs to see, while the head constant is only good for
grouping. A characterization up to a coarse relation says correspondingly less, and nothing but
showing the relation can convey that. -/
structure CharUniqueness where
  name : Name
  /-- The relating conclusion as written, with the theorem's own variable names. -/
  relation : String := ""
  /-- Its head constant (`Eq`, `Filter.EventuallyEq`, …), anonymous when there is none. -/
  relationHead : Name := .anonymous
deriving Repr, BEq, ToJson, FromJson, Inhabited

/-- One characterization claimed for a definition, as written with the `@[characterization]`
attribute of the `LeanSpec` package: a predicate, the theorems saying the definition satisfies it,
and the theorems saying nothing else does.

Stronger than a `SpecLink` in exactly one way that matters to a reader, and it is worth being
precise about which. `@[specifies]` is an unchecked claim; the shapes here *are* checked — the
predicate really is a predicate on the definition's type, the existence theorem really states that
the definition satisfies it, the uniqueness theorem really relates two objects that satisfy it. What
is still not checked is whether the predicate says anything worth saying. So a complete bundle is
evidence, not proof, and the site has to print the property and the relation rather than merely
report that they exist. -/
structure CharBundle where
  /-- The characterizing predicate. -/
  property : Name
  /-- The author's note on the property, from the attribute. Empty when they wrote none. -/
  comment : String := ""
  /-- The theorems stating that the definition satisfies `property`, in declaration order. -/
  existence : Array Name := #[]
  /-- The theorems stating that `property` determines its subject, in declaration order. -/
  uniqueness : Array CharUniqueness := #[]
deriving Repr, BEq, ToJson, FromJson, Inhabited

/-- Whether both halves of the claim are present. A property with an existence theorem and no
uniqueness theorem says no more than a `@[specifies]` annotation does — the definition has the
property, and so, for all this says, might anything else. -/
def CharBundle.isComplete (b : CharBundle) : Bool :=
  !b.existence.isEmpty && !b.uniqueness.isEmpty

/-- The link from one of a characterization's three declarations back to the claim it is part of.

The reverse index of `characterizedBy`, computed by `attachCharacterizes`, and the reason a reader
who lands on `IsEntropy.unique` is told what it is for rather than left with a lemma about a
predicate. -/
structure CharPartLink where
  /-- The definition characterized. -/
  target : Name
  /-- The characterizing predicate. -/
  property : Name
  /-- `property`, `existence` or `uniqueness`. -/
  role : String
deriving Repr, BEq, ToJson, FromJson, Inhabited

/-- Fully collected metadata for one exposed declaration. -/
structure DeclInfo where
  name : Name
  moduleName : Name
  modulePath : String
  groupKey : String
  kind : DeclKind
  displaySignature : String
  expandedSignature : String
  docBlocks : Array (Block Manual)
  /-- The docstring as written, before markdown parsing. `docBlocks` is the rendered form and is
  the right thing for a page; this is kept for the places that need plain text, such as the
  dependency graph's side panel, which is built as JSON rather than as Verso blocks. -/
  docText? : Option String := none
  proofText? : Option String
  source? : Option SourceInfo
  /-- True if the declaration was written with the `lemma` keyword (a `theorem` alias used in
  Mathlib to mark less central results). -/
  isLemma : Bool := false
  /-- True if the declaration was written with the `instance` keyword but was not classified as
  `.instance` by `declKindOf`. -/
  isInstanceDecl : Bool := false
  /-- True if the declaration comes from an `alias` command. Unlike a real theorem, its body is kept
  verbatim during extraction (`alias … := target`) rather than replaced by `sorry`, so its transitive
  closure must follow value dependencies (the alias target), not just type dependencies. -/
  isAlias : Bool := false
  /-- True if `sorryAx` occurs anywhere in the declaration's transitive closure — whether the
  `sorry` is its own or inherited from something it rests on. Computed with `Lean.collectAxioms`,
  so it sees through compiler-generated helpers and into upstream libraries alike. -/
  dependsOnSorry : Bool := false
  /-- True if this declaration's *own* type or body contains a `sorry`. `dependsOnSorry` without
  `hasOwnSorry` means the gap is inherited, and the site has to point at where it actually is
  rather than blame this declaration for it. -/
  hasOwnSorry : Bool := false
  /-- Every axiom the declaration's closure rests on, i.e. what `#print axioms` reports. Beyond
  `Classical.choice`/`propext`/`Quot.sound` these are assumptions a reader is being asked to
  grant, so they are reported rather than collapsed into a flag. -/
  axioms : Array Name := #[]
  /-- For a theorem carrying `@[specifies …]`: the definitions its author declared it to be part of
  the specification of, in the order written.

  Almost everything else on `DeclInfo` is derived from the environment; this is not. It is the
  author's editorial claim about which properties pin a definition down, read back from the
  environment extension the `LeanSpec` package writes, and there is no way to infer it. Empty for
  every declaration of a project that does not use that package — which is why nothing downstream
  treats its absence as an error. The named definition need not be exposed, or even belong to this
  project. -/
  specifies : Array SpecLink := #[]
  /-- For a definition: the exposed theorems that carry `@[specifies thisDeclaration …]`, in
  declaration order. The reverse index of `specifies`, computed by `attachSpecifiedBy`. -/
  specifiedBy : Array SpecLink := #[]
  /-- For a definition: the characterizations its author claims for it — the strictly stronger
  claim that a property does not merely hold of it but *determines* it, up to a stated relation.

  Read from the same `LeanSpec` extension as `specifies`, and empty for a project that does not use
  the attribute. Both theorems of a characterization also register as `@[specifies]` annotations, so
  everything here is visible in `specifiedBy` too; this field is what lets the site tell a
  definition that has been pinned down from one that has merely been described. -/
  characterizedBy : Array CharBundle := #[]
  /-- For a declaration that is one of the three parts of a characterization: which claims it
  belongs to and in what role. The reverse index of `characterizedBy`, computed by
  `attachCharacterizes`. -/
  characterizes : Array CharPartLink := #[]
  /-- The upstream packages this declaration *directly* references, after `attachUpstreamPackages`
  has propagated them along the project's own dependency edges.

  "Directly" is the important word: these are the packages some constant of the declaration's
  project-level closure names, not the full set it rests on. The site closes them over the Lake
  dependency graph to get that — see the note on upstream packages above for why the two agree.

  Follows `meaningDeps`: a theorem contributes what its *statement* mentions, not what its proof
  calls. An upstream proof is not a trust dependency — the kernel rechecked it, and anything left
  unproved in it surfaces as a `sorry` or an extra axiom, both of which `axioms` already reports
  transitively. What cannot be checked for you is an upstream *definition* your statement is about. -/
  upstreamPackages : Array Name := #[]
  /-- The declaration's rename-invariant *semantic* hash, read from a `semantic_hash export` file
  (`collect --hashes`). Fixed-width hex, so it reads as an identifier rather than as a number
  someone might compare with `<`.

  Structural over the elaborated `Expr`, and — the property everything downstream rests on —
  **deep**: a referenced constant contributes *its* hash rather than its name, so this changes when
  the meaning of anything in the declaration's closure changes, upstream included. Invariant to
  renaming, to binder names, to `mdata`, and to how anything pretty-prints.

  `none` for a project collected without `--hashes`, and for any declaration the export did not
  cover; `Referee.Diff` falls back to comparing text per declaration, so absence degrades rather
  than breaks. -/
  semanticHash? : Option String := none
  /-- The same hash with theorem bodies hidden, so a theorem hashes by its *proposition*: proof
  subterms contribute the hash of the proposition they prove rather than of the term.

  This is `meaningDeps` computed at the `Expr` level by an independent implementation — a theorem's
  proof-irrelevant hash depends on its statement's closure and on nothing its proof merely calls —
  which is why the revision diff can use it directly as "did the meaning move". The pair
  (`semanticHash?` differs, this one does not) is exactly a proof-only change. -/
  proofIrrelHash? : Option String := none
  deps : Array Name
  typeDeps : Array Name := #[]
  /-- `deps` with the proofs inside the value skipped: what the declaration's statement and *data*
  rest on. See `LeanDeps.dataValueConstants` for why a bundled structure instance's proof fields are
  not part of its meaning, and `meaningDeps` for where this is used.

  Differs from `deps` only for `def`/`abbrev`/`instance`; equal to it for everything else. -/
  dataDeps : Array Name := #[]
  usedBy : Array Name := #[]
  transDeps : Array Name := #[]
  /-- The transitive closure of `meaningDeps`, topologically ordered, as `transDeps` is of
  `closureDeps`. Kept separate rather than replacing `transDeps` because `Referee.Extract` seeds each
  standalone file's `keep` set from `transDeps`, and a file whose kept tactic bodies lost the lemmas
  they call would no longer compile. -/
  dataTransDeps : Array Name := #[]
  docstringBlock? : Option (Block Manual) := none
deriving Repr, ToJson, FromJson

/-- The kind label to show for this declaration; see `displayKindLabel`. -/
def DeclInfo.displayKind (decl : DeclInfo) : String :=
  displayKindLabel decl.kind.label decl.isLemma decl.isInstanceDecl

/-- Whether this declaration is the kind of thing a specification can be *about*: something whose
meaning is chosen rather than proved.

Drives every "definitions without a specification" count, so what it excludes matters as much as
what it includes. Theorems are excluded because their meaning is their statement. Axioms are
excluded because an axiom *is* an assumption and the trust page already reports it as one.
Instances are excluded because a library has a great many of them, they are overwhelmingly
plumbing, and listing each one as an unspecified definition would bury the definitions that
actually want a specification. -/
def DeclInfo.isDefinitionLike (decl : DeclInfo) : Bool :=
  !decl.isInstanceDecl &&
    match decl.kind with
    | .definition | .structure | .typeclass | .inductive | .opaque => true
    | .theorem | .axiom | .instance => false

/-- Whether this is one of the library's *claims*: a result written with the `theorem` keyword
rather than `lemma`.

The one piece of editorial intent the tool cannot derive — Lean records both keywords as the same
kind — so it is read from the author's own signal and taken at face value. See `claimsOf` in
`Website/Site.lean` for what rests on it and why a derived rule was rejected. -/
def DeclInfo.isClaim (decl : DeclInfo) : Bool :=
  decl.kind == .theorem && !decl.isLemma && !decl.isInstanceDecl

/-- Whether a declaration's *body* is part of what it means, as opposed to being a proof the kernel
has already checked.

The same rule `meaningDepsOf` applies to dependency edges, applied here across revisions instead:
changing a definition's body changes the meaning of every statement about it, while changing a
theorem's proof changes nothing a reader has to re-read. An `alias` counts as a definition for this
purpose for the reason recorded on `DeclInfo.isAlias` — its body is kept verbatim. -/
def DeclInfo.bodyIsMeaning (decl : DeclInfo) : Bool :=
  decl.kind != .theorem || decl.isAlias

/-- Exposed declarations grouped by Lean module. -/
structure ModuleInfo where
  name : Name
  path : String
  groupKey : String
  decls : Array DeclInfo
  docBlocks : Array (Block Manual) := #[]
deriving Repr, ToJson, FromJson

/-- Modules grouped by top-level chapter key. -/
structure GroupInfo where
  key : String
  modules : Array ModuleInfo
deriving Repr, ToJson, FromJson

/-! ## Upstream packages

The project is not the whole of what a reader is asked to trust. `AlphaRAR` rests on
`LeanMachineLearning`, which rests on `mathlib`, and a referee may well have audited one and not the
other. Nothing else on the site says so: every measure here stops at the project boundary and
treats everything beyond it as given.

What is and is not a trust dependency upstream is worth being precise about, because the obvious
answer is wrong. An upstream *proof* needs no trust at all: the kernel rechecked it, and anything
left unproved in it arrives as a `sorry` or an extra axiom, both of which `axioms` and
`dependsOnSorry` already report transitively — through upstream packages included. So a theorem
whose proof calls a `LeanMachineLearning` lemma has learned nothing it needs to take on faith from
that call.

What does need trust is an upstream *definition* that a statement is about. If a theorem's statement
mentions `Learning.IsAlgEnvSeq`, then what the theorem *means* depends on that definition being the
intended one, and no proof anywhere settles that — it is the same gap `@[specifies]` exists to
record, one package up. That is why the edges followed here are `meaningDeps`: a theorem contributes
its statement, everything else contributes its body too, since a definition's body is its meaning.

What is recorded is deliberately package-granular rather than constant-granular, and the reason is
cost. `Lean.collectAxioms` gets away with a full closure walk per declaration only because axioms
for imported constants are precomputed in an environment extension, so the walk stops at the project
boundary; a genuine walk into Mathlib, 784 times over, is not affordable. Package granularity is
also *sound* to close transitively, which is what makes the cheap version correct rather than merely
cheap: a constant can only reference what its own package imports, so if a declaration's closure
reaches package `Q`, then `Q` is reachable in the Lake dependency graph from a package the
declaration references directly. Recording the directly-referenced packages and closing over the
Lake graph at render time therefore cannot miss a dependency — the direction that matters, since
under-reporting here would mean telling a reader they do not rest on code they do.
-/

/-- A package of the target's Lake workspace, as much of it as the audit needs.

`Lean` is the pseudo-package standing for the toolchain (`Init`, `Std`, `Lean`, `Lake`), which
belongs to no Lake package. Modelling it as one keeps module attribution uniform — it is matched by
root prefix like any other — and gives the trust graph a root to bottom out in. -/
structure PackageInfo where
  name : Name
  /-- Direct dependencies, by name, as declared in the workspace. -/
  deps : Array Name := #[]
  /-- The library roots the package declares, which is how a module is attributed to it. -/
  roots : Array Name := #[]
  /-- True for the project being exposed, which is never "upstream" of itself. -/
  isProject : Bool := false
  /-- True for the `Lean` pseudo-package. Always trusted: it is the compiler that checked
  everything else, so trusting it is not a choice a site can offer. -/
  isToolchain : Bool := false
deriving Repr, BEq, ToJson, FromJson, Inhabited

/-- Data container for MarkdownSection. -/
structure MarkdownSection where
  title : String
  body : String
deriving Repr, ToJson, FromJson

/-- An upstream constant a project statement names, with enough of it to be read in place.

These are the nodes a declaration's graph bottoms out in, and until now they were drawn with nothing
but their name: the panel showed the name again where a signature belongs and a canned sentence
where the docstring belongs. A reader asking "is this statement about the definition I think it is"
— the question the whole site exists to serve — could not answer it without leaving for another
site. The signature and docstring come straight out of the imported environment, which already has
both.

Not attached to `DeclInfo`: one upstream constant is named by many declarations, so this is a table
keyed by name, emitted once. -/
structure ExternalDeclInfo where
  name : Name
  /-- The package it comes from, as `PackageInfo.name`. -/
  package : Name
  /-- The module declaring it, for the panel's provenance line. -/
  moduleName : Name
  /-- Its pretty-printed type. -/
  signature : String
  /-- What it *says*, beyond the shape of its arguments: a definition's value, or a structure's
  fields. Empty for a theorem, whose type already is its statement, and for anything with no body to
  show.

  Without this the panel answers the wrong question for a definition. `Filter.Tendsto`'s type is
  `(α → β) → Filter α → Filter β → Prop`, which says it takes a function and two filters and yields a
  proposition — every argument reading as a hypothesis, and no hint that it *means* `map f l₁ ≤ l₂`.
  Since the whole point of these nodes is "is this the definition I think it is", the type alone
  cannot answer it. -/
  value : String := ""
  /-- Its docstring, or `""` when it has none — the panel distinguishes the two. -/
  doc : String := ""
  /-- Its own meaning edges, restricted to *its own package*, so the graph can draw an unaudited
  package's internal structure rather than a flat row of names. Empty unless the package was expanded
  (`CollectedData.expandedPackages`). Edges leaving the package are deliberately absent: they would
  reach either the project — which depends on the package, not the reverse — or a further package,
  whose own expansion is a separate question. -/
  deps : Array Name := #[]
deriving Repr, ToJson, FromJson, Inhabited

/-! ## Interning: sharing the collected data's repeated subtrees

The serialized data is dominated by repetition, and overwhelmingly in one field. Measured on
`brownian-motion` (1808 declarations, 67 MB): `DeclInfo.docstringBlock?` is 56.6 MB of the 73.5 MB
`decls` array — 77% — and inside it 19.2 MB is repeated JSON field names while 11.0 MB is the
docstrings of upstream constants, inlined once per *mention*: 54,778 occurrences of 1,014 distinct
strings, with `MeasurableSpace`'s docstring stored 2,770 times.

None of that is information. `intern` replaces every repeated subtree with an index into a table
carried alongside the data. On that project: **67.2 MB → 21.5 MB** (3.1×).

The reason this is worth a format change rather than just compressing the file — which would do
better on bytes, 13× — is that it shrinks the data *in memory* too, and memory is the wall a large
library hits first. `resolve` rebuilds each table entry exactly once, so every reference to it yields
the same `Json` value rather than a copy, and the sharing survives decoding wherever a field is a
`String` (`getStr?` hands back the existing object). Rendering the same site from the interned and
un-interned forms of one file, measured:

|  | file | peak RSS | wall |
|---|---|---|---|
| un-interned | 67.2 MB | 1022 MB | 13.9 s |
| interned | 21.5 MB | **532 MB** | 12.8 s |

Byte-identical output, half the memory, and slightly faster despite the extra pass — parsing a third
as much JSON more than pays for resolving it. Gzip would give neither of the last two.
-/

/-- The reserved object key marking a reference into the subtree table: `{"$i": 12}`.

A single character keeps the marker at nine bytes, which matters because references are the most
numerous thing in the encoded form. No Lean structure field or `Name` component can produce it, but
`intern` checks rather than assuming (see `usesInternKey`). -/
def internKey : String := "$i"

/-! ### Recursing over `Json` without `partial`

The three functions below walk a `Json` tree. Every recursive call is on a strict subterm, but Lean
cannot see that on its own: `Json` is a *nested* inductive whose object case holds a
`Std.TreeMap.Raw`, and folding over that tree hands the termination checker a value with no evidence
tying it to the tree. `Array` and `List` ship `sizeOf_lt_of_mem`; the tree containers do not. That
single gap is why every recursion over `Json` in Lean core — `beq'`, `hash'`, `render`, `compress` —
is `partial`.

The two lemmas here close it, and the walks below are therefore ordinary total definitions with
equations a proof can use. That matters because this is the on-disk format: `Proofs/Collect.lean`
proves that `resolve` inverts `intern`, which is not a statement one can even *make* about a
`partial def`. -/

/-- Values stored in a tree map are strict subterms of it, over the structural flattening
`toListModel` that core defines for verification. No well-formedness hypothesis: this is about the
tree's shape, not its ordering. -/
theorem sizeOf_lt_of_mem_toListModel {m : Std.DTreeMap.Internal.Impl String (fun _ => Json)}
    {p : (_ : String) × Json} (h : p ∈ m.toListModel) : sizeOf p.2 < sizeOf m := by
  induction m with
  | leaf => simp at h
  | inner sz k v l r ihl ihr =>
    rw [Std.DTreeMap.Internal.Impl.toListModel_inner] at h
    rcases List.mem_append.mp h with h' | h'
    · have := ihl h'; simp; omega
    · rcases List.mem_cons.mp h' with rfl | h''
      · simp; omega
      · have := ihr h''; simp; omega

/-- The same for the public `toList`, which is what the walks below iterate. This is the fact
`decreasing_by` needs in every object case. -/
theorem objPairs_sizeOf {fields : Std.TreeMap.Raw String Json} {p : String × Json}
    (h : p ∈ fields.toList) : sizeOf p.2 < sizeOf fields := by
  obtain ⟨⟨impl⟩⟩ := fields
  rw [Std.TreeMap.Raw.toList, Std.DTreeMap.Raw.Const.toList,
    Std.DTreeMap.Internal.Impl.Const.toList_eq_toListModel_map] at h
  obtain ⟨q, hq, rfl⟩ := List.mem_map.mp h
  have := sizeOf_lt_of_mem_toListModel hq
  simp at this ⊢
  omega

/-- True if any object in `j` already uses `internKey`.

`intern` refuses to encode such a document, because a payload object of exactly that shape would be
indistinguishable from a reference and would decode to something else entirely. Nothing Referee
serializes can produce the key, so this is a guard against a future field, not a live case. -/
def usesInternKey (j : Json) : Bool :=
  match j with
  | .obj fields => fields.toList.attach.any fun p => p.1.1 == internKey || usesInternKey p.1.2
  | .arr elems => elems.attach.any fun e => usesInternKey e.1
  | _ => false
termination_by sizeOf j
decreasing_by
  · have := objPairs_sizeOf p.2; simp; omega
  · have := Array.sizeOf_lt_of_mem e.2; simp; omega

/-- Smallest compressed size, in bytes, a subtree must reach before it is worth interning.

Chosen by measurement, not reasoning: the size/threshold curve is not monotonic, because interning
small nodes shrinks their parents, which makes *those* collide with each other in turn. On
`brownian-motion` the whole 10–20 range sits on one plateau at 3.17× and the cliff is at 22, where
the token objects that make up the bulk of a signature stop qualifying:

| threshold | 14 | 20 | 22 | 32 | 64 |
|---|---|---|---|---|---|
| factor | 3.17× | 3.18× | 2.95× | 2.40× | 2.14× |

20 is the top of the plateau, which is where the same file size comes with the fewest table entries
(76k rather than 80k) and so the least work in both `internAux` and `resolve`. Below about 10 nothing
can pay for itself anyway: a reference is nine bytes. -/
def internMinSize : Nat := 20

/-- Encoder state: the table in construction, and the reverse index that makes a repeat an O(1)
lookup rather than a scan.

The index is keyed on the *already-interned* node, so `Json`'s recursive `BEq`/`Hashable` only ever
walk a node's own fields plus its children's nine-byte references — never a whole subtree. That is
what keeps the pass linear in the document rather than quadratic in its depth. -/
structure InternState where
  table : Array Json := #[]
  index : Std.HashMap Json Nat := {}

/-- Interns one node, bottom-up: children first, then the node itself if it is large enough to pay
for a reference.

Because children are interned before their parent, every reference inside table entry `i` points to
an index below `i`. `resolve` relies on that ordering to rebuild the table in one forward pass. -/
def internAux (j : Json) (st0 : InternState) : Json × InternState :=
  let (node, st) : Json × InternState :=
    match j with
    | .arr elems =>
      let (out, st) := elems.attach.foldl (init := ((#[] : Array Json), st0))
        fun (acc : Array Json × InternState) e =>
          let (e', st') := internAux e.1 acc.2
          (acc.1.push e', st')
      (Json.arr out, st)
    | .obj fields =>
      -- `toList` is ascending by key, the order the previous `fields.foldl` produced; `out` is built
      -- reversed and handed to `mkObj`, which re-sorts, so the object is unchanged either way.
      let (out, st) := fields.toList.attach.foldl (init := (([] : List (String × Json)), st0))
        fun (acc : List (String × Json) × InternState) p =>
          let (v', st') := internAux p.1.2 acc.2
          ((p.1.1, v') :: acc.1, st')
      (Json.mkObj out, st)
    | leaf => (leaf, st0)
  -- A leaf is never tabled. `internMinSize` excludes every number and boolean, and a string long
  -- enough to qualify is already shared by the parse rather than copied per occurrence.
  let isComposite := match node with | .arr _ | .obj _ => true | _ => false
  if !isComposite || node.compress.length < internMinSize then
    (node, st)
  else
    match st.index[node]? with
    | some i => (Json.mkObj [(internKey, toJson i)], st)
    | none =>
      let i := st.table.size
      (Json.mkObj [(internKey, toJson i)],
        { table := st.table.push node, index := st.index.insert node i })
termination_by sizeOf j
decreasing_by
  · have := Array.sizeOf_lt_of_mem e.2; simp; omega
  · have := objPairs_sizeOf p.2; simp; omega

/-- Replaces every repeated subtree of `j` with a reference into a table, returning the table and the
rewritten document. Returns an empty table and `j` unchanged when `usesInternKey` says the document
could not be decoded unambiguously. -/
def intern (j : Json) : Array Json × Json :=
  if usesInternKey j then
    (#[], j)
  else
    let (root, st) := internAux j {}
    (st.table, root)

/-- Substitutes references in `j` against an already-resolved table.

A reference is an object whose only field is `internKey` carrying a whole number in range; anything
else is real data and is rebuilt field by field. An out-of-range index is left alone rather than
raising, which is what lets a document with an empty table round-trip unchanged. -/
def resolveAgainst (resolved : Array Json) (j : Json) : Json :=
  match j with
  | .arr elems => .arr (elems.attach.map fun e => resolveAgainst resolved e.1)
  | .obj fields =>
    let ref? : Option Nat := do
      let .num n ← fields.get? internKey | none
      guard (n.exponent == 0)
      guard (n.mantissa ≥ 0)
      let i := n.mantissa.toNat
      guard (i < resolved.size)
      pure i
    match ref? with
    | some i => resolved[i]!
    | none =>
      Json.mkObj <| (fields.toList.attach.foldl (init := (#[] : Array (String × Json)))
        fun acc p => acc.push (p.1.1, resolveAgainst resolved p.1.2)).toList
  | leaf => leaf
termination_by sizeOf j
decreasing_by
  · have := Array.sizeOf_lt_of_mem e.2; simp; omega
  · have := objPairs_sizeOf p.2; simp; omega

/-- Rebuilds a document `intern` encoded, resolving each table entry exactly once so that every
reference to it yields the *same* `Json` value.

That single-allocation property is the point, not merely the smaller file: the decoded tree shares
its repeated subtrees by pointer instead of holding a copy per occurrence. The forward pass is sound
because `internAux` tables children before parents, so entry `i` only ever references entries below
`i`, which are already resolved when it is reached. -/
def resolve (table : Array Json) (j : Json) : Json :=
  let resolved := table.foldl (init := (#[] : Array Json)) fun acc entry =>
    acc.push (resolveAgainst acc entry)
  resolveAgainst resolved j

/-- Format version of `CollectedData`. Bump whenever `DeclInfo` or `CollectedData` gains or
changes a field, so that `build-site` fails with an actionable message rather than a field-level
decode error when handed a JSON file written by an older `collect`.

- 1: initial
- 2: adds `DeclInfo.hasOwnSorry` and `DeclInfo.axioms`
- 3: adds `DeclInfo.docText?`
- 4: adds `DeclInfo.specifies` and `DeclInfo.specifiedBy`
- 5: adds `CollectedData.packages` and `DeclInfo.upstreamPackages`
- 6: adds `DeclInfo.semanticHash?` and `DeclInfo.proofIrrelHash?`
- 7: adds `DeclInfo.dataDeps` and `DeclInfo.dataTransDeps`
- 8: replaces `CollectedData.externalPackages` with `externalDecls`, which carries the signature and
  docstring of each upstream constant as well as its package
- 9: adds `ExternalDeclInfo.value`/`deps` and `CollectedData.expandedPackages`, the internal
  structure of the upstream packages small enough to walk
- 10: adds `DeclInfo.characterizedBy` and `DeclInfo.characterizes`
- 11: wraps the document in an `InternedData` envelope, sharing its repeated subtrees (see `intern`).
  No field of `CollectedData` changed; what changed is how it is written and read -/
def collectedDataVersion : Nat := 11

/-- The full result of the `collect` subcommand's analysis, persisted as JSON so `extract`
and `build-site` can run without re-importing the target project. `moduleOrder` and
`moduleDocs` are flattened to arrays (rather than `Std.HashMap`) purely for JSON-friendliness;
reconstruct the map at the consuming end. -/
structure CollectedData where
  version : Nat := collectedDataVersion
  rootPrefix : Name
  decls : Array DeclInfo
  moduleOrder : Array (Name × Nat)
  moduleDocs : Array (Name × Array (Block Manual))
  readmeText : Option String
  /-- The workspace's packages and their dependency edges, the graph `--trust` closes over. -/
  packages : Array PackageInfo := #[]
  /-- The packages with code actually loaded in the imported environment. See `loadedPackagesOf`:
  this is what stops a declared-but-unused dependency from being reported as trusted-or-not. -/
  loadedPackages : Array Name := #[]
  /-- The upstream constants project statements name, with what a reader needs in order to read one:
  its package, its module, its signature and its docstring. See `externalDeclsOf`. -/
  externalDecls : Array ExternalDeclInfo := #[]
  /-- The upstream packages whose internal structure was collected, i.e. those whose closure fitted
  inside `maxExpandedPackage`. Their declarations carry `ExternalDeclInfo.deps` and are drawn as a
  layered block; everything else is drawn as the flat surface it always was. -/
  expandedPackages : Array Name := #[]
deriving ToJson, FromJson

/-- What `collect` actually writes: a `CollectedData` with its repeated subtrees hoisted into
`interned` and replaced by references. See `intern` for why.

`version` is duplicated here rather than only inside `data` so that `loadCollectedData` can reject a
stale file by reading one top-level field, without decoding — or even resolving — the rest. -/
structure InternedData where
  version : Nat := collectedDataVersion
  /-- The shared subtree table. Entry `i` may reference only entries below `i`. Empty when interning
  was skipped, in which case `data` is an ordinary `CollectedData` document. -/
  interned : Array Json := #[]
  data : Json
deriving ToJson, FromJson

/-- Serializes `data`, interned. -/
def encodeCollectedData (data : CollectedData) : Json :=
  let (interned, root) := intern (toJson data)
  toJson { interned, data := root : InternedData }

/-- Inverse of `encodeCollectedData`. Separated from the file reading so it can be round-trip tested
without touching the disk. -/
def decodeCollectedData (json : Json) : Except String CollectedData := do
  let envelope : InternedData ← fromJson? json
  fromJson? (resolve envelope.interned envelope.data)

/-- Command-line usage text shown for invalid arguments. -/
def usage : String :=
  String.intercalate "\n" [
    "Usage: lake exe referee [SUBCOMMAND] [options]",
    "",
    "Subcommands:",
    "  collect              Import the target project and write collected declaration data as JSON.",
    "  extract              Read collected data and write standalone per-declaration .lean files.",
    "  extract-flat         Same, but rendered from the compiled environment instead of from",
    "                       source: unreadable but far more robust, as a fallback for files",
    "                       `extract` cannot make compile. Writes to <output>/html-multi/",
    "                       extracted-flat.",
    "  highlight            Elaborate each project module and write interactive-Lean highlighting",
    "                       to <output>/highlighting. Optional; without it the site renders plain",
    "                       code blocks.",
    "  highlight-extracted  Elaborate each extracted minimal .lean file and write its highlighting,",
    "                       plus whether it compiles, to <output>/extracted-highlighting. Requires",
    "                       `extract` to have run first.",
    "  provenance           Fold this revision into the provenance ledger: when each declaration's",
    "                       meaning last changed, and where its source was last edited. Needs a git",
    "                       working tree and semantic hashes, but no Lean environment.",
    "  build-site           Read collected data and render the Verso HTML site (no Lean env",
    "                       needed).",
    "  all                  Run collect, extract, and build-site in one process, without a JSON",
    "                       round-trip (default when no subcommand is given, for backward",
    "                       compatibility). Does not include the highlighting phases.",
    "",
    "  highlight-module / highlight-file are internal workers used by the two phases above; they",
    "  process a single module or file and are not meant to be invoked directly.",
    "",
    "Options:",
    "  --root PREFIX        Root module prefix to expose (default: first root library)",
    "  --repo-url URL       GitHub repo URL used for issue/source links",
    "  --site-url URL       Deployed site base URL, used to link the minimal Lean files into the",
    "                       live.lean-lang.org web editor",
    "  --title TITLE        Site title override",
    "  --output DIR         Output directory passed to Verso",
    "  --exclude-lib NAME   Exclude a root library when importing the target project",
    "  --data PATH          Collected-data JSON file: written by `collect`, read by `extract`",
    "                       and `build-site`",
    "  --highlighting DIR   Directory of per-module highlighting read by `build-site`",
    "                       (default: <output>/highlighting)",
    "  --jobs N             Worker processes to run at once in the highlighting phases",
    "                       (default: CPU count)",
    "  --trust PKG          Treat this upstream package, and everything it depends on, as",
    "                       audited. Repeatable. Anything left untrusted is reported on the",
    "                       trust page and on the pages of the declarations that rest on it",
    "  --show-trusted-upstream",
    "                       Also draw declarations from audited packages in each graph's upstream",
    "                       band. Off by default: unaudited packages are always drawn, and they",
    "                       are what the band exists to show",
    "  --baseline PATH      An earlier `collect` output to compare against. Adds a Changes page,",
    "                       a badge on every declaration, and a Browse column saying what a",
    "                       reader of that revision has to read again. Omit it and the site says",
    "                       nothing about revisions",
    "  --baseline-label S   What to call the baseline on the page (default: its file name)",
    "  --hashes PATH        JSONL written by `semantic_hash export`, giving each declaration a",
    "                       rename-invariant semantic hash. Read by `collect` and stored in the",
    "                       data file, where it becomes the key the revision diff compares on",
    "                       instead of pretty-printed types. Optional",
    "  --provenance PATH    The provenance ledger: when each declaration's meaning last changed,",
    "                       and in which revision. Written and extended by `provenance`, read by",
    "                       `build-site`. Optional; without it the site says nothing about when",
    "                       anything changed",
    "  --ref NAME           What to call this revision in the ledger (default: git describe)",
    "  --module NAME        Internal: the module `highlight-module` should process",
    "  --input FILE         Internal: the file `highlight-file` should process",
  ]

/-- Parses CLI arguments into `Cli`, or returns a usage error. -/
def parseArgs : List String → Except String Cli
  | [] => .ok {}
  | "--root" :: root :: rest => do
      let cfg ← parseArgs rest
      pure { cfg with rootPrefix := some root.toName }
  | "--repo-url" :: url :: rest => do
      let cfg ← parseArgs rest
      pure { cfg with repoUrl := some url }
  | "--site-url" :: url :: rest => do
      let cfg ← parseArgs rest
      pure { cfg with siteUrl := some url }
  | "--title" :: title :: rest => do
      let cfg ← parseArgs rest
      pure { cfg with siteTitle := some title }
  | "--output" :: out :: rest => do
      let cfg ← parseArgs rest
      pure { cfg with outputDir := some out }
  | "--exclude-lib" :: lib :: rest => do
      let cfg ← parseArgs rest
      pure { cfg with excludeLibs := cfg.excludeLibs.push lib.toName }
  | "--data" :: path :: rest => do
      let cfg ← parseArgs rest
      pure { cfg with dataPath := some path }
  | "--module" :: name :: rest => do
      let cfg ← parseArgs rest
      pure { cfg with moduleName := some name.toName }
  | "--highlighting" :: dir :: rest => do
      let cfg ← parseArgs rest
      pure { cfg with highlightingDir := some dir }
  | "--input" :: path :: rest => do
      let cfg ← parseArgs rest
      pure { cfg with inputPath := some path }
  | "--jobs" :: n :: rest => do
      let some n := n.toNat?
        | .error s!"--jobs expects a number, got: {n}"
      let cfg ← parseArgs rest
      pure { cfg with jobs := some n }
  | "--trust" :: name :: rest => do
      let cfg ← parseArgs rest
      pure { cfg with trustedPackages := cfg.trustedPackages.push name.toName }
  | "--show-trusted-upstream" :: rest => do
      let cfg ← parseArgs rest
      pure { cfg with showTrustedUpstream := true }
  | "--baseline" :: path :: rest => do
      let cfg ← parseArgs rest
      pure { cfg with baselinePath := some path }
  | "--baseline-label" :: label :: rest => do
      let cfg ← parseArgs rest
      pure { cfg with baselineLabel := some label }
  | "--hashes" :: path :: rest => do
      let cfg ← parseArgs rest
      pure { cfg with hashesPath := some path }
  | "--provenance" :: path :: rest => do
      let cfg ← parseArgs rest
      pure { cfg with provenancePath := some path }
  | "--ref" :: name :: rest => do
      let cfg ← parseArgs rest
      pure { cfg with revisionRef := some name }
  | flag :: _ =>
      .error s!"Unknown or incomplete option: {flag}\n\n{usage}"

/-- Helper for slugify. -/
def slugify (s : String) : String :=
  let pushChar (acc : String) (ch : Char) : String :=
    if ch.isAlphanum then
      acc.push (if ch.isUpper then ch.toLower else ch)
    else if acc.isEmpty || acc.back == '-' then
      acc
    else
      acc.push '-'
  let slug := s.foldl pushChar ""
  -- `pushChar` already drops leading and consecutive separators, but a separator emitted for a
  -- trailing non-alphanumeric run would dangle at the end, so strip any trailing `-`.
  let slug := String.ofList (slug.toList.reverse.dropWhile (· == '-')).reverse
  if slug.isEmpty then "item" else slug

/-- Helper for humanizeWord. -/
def humanizeWord (s : String) : String :=
  if s.isEmpty then
    s
  else
    let rec go (chars : List Char) (prevLower : Bool) (acc : String) :=
      match chars with
      | [] => acc
      | ch :: rest =>
          let insertSpace := prevLower && ch.isUpper
          let acc := if insertSpace then acc.push ' ' else acc
          go rest ch.isLower (acc.push ch)
    go s.toList false ""

/-- Computes name Components. -/
def nameComponents : Name → List String
  | .anonymous => []
  | .num p n => nameComponents p ++ [toString n]
  | .str p s => nameComponents p ++ [s]

/-- Computes module TailComponents. -/
def moduleTailComponents (rootPrefix moduleName : Name) : List String :=
  let root := nameComponents rootPrefix
  let full := nameComponents moduleName
  full.drop root.length

/-- Computes group KeyOfModule. -/
def groupKeyOfModule (rootPrefix moduleName : Name) : String :=
  match moduleTailComponents rootPrefix moduleName with
  | first :: _ => first
  | [] => rootPrefix.toString

/-- Computes module PathOf. -/
def modulePathOf (rootPrefix moduleName : Name) : String :=
  let tail := moduleTailComponents rootPrefix moduleName
  match tail with
  | [] => moduleName.toString
  | _ => String.intercalate "." tail

/-- Maps a declaration name to an identifier safe to use as a filename, URL, and HTML anchor:
namespace dots become `___`, and the characters forbidden in filenames on some operating systems
(Windows: `< > : " / \ | ? *`) are replaced by fullwidth Unicode lookalikes that are legal
everywhere. Notation declarations such as `«term𝓛[_|_;_]»` would otherwise produce a `|` in the
filename, which is illegal on Windows and rejected by Lean's module-name portability check. -/
def anchorIdOf (name : Name) : String :=
  let safeChar : Char → Char := fun c =>
    match c with
    | '<' => '＜' | '>' => '＞' | ':' => '：' | '"' => '＂' | '/' => '／'
    | '\\' => '＼' | '|' => '｜' | '?' => '？' | '*' => '＊'
    | _ => c
  (String.intercalate "___" (name.toString.splitOn ".")).map safeChar

/-- Maps a declaration name to a pure-ASCII identifier that is unique across declarations, for use
as an explicit Verso cross-reference tag.

`anchorIdOf` keeps non-ASCII characters, which is right for filenames and anchors but not for
Verso tags: when a declaration page does not provide its own tag, Verso derives one from the title
and non-ASCII characters do not survive that derivation. `induction_on`, `induction_on₂` and
`induction_on₃` therefore derived the *same* tag and the build failed with a duplicate-tag error.
Encoding every character outside `[A-Za-z0-9]` as `_xHEX_` keeps the mapping injective and the
result ASCII. -/
def asciiTagOf (name : Name) : String :=
  name.toString.foldl (init := "") fun acc c =>
    if c.isAlphanum then acc.push c
    else acc ++ s!"_x{String.ofList (Nat.toDigits 16 c.toNat)}_"

/-! ### Page tags

Verso keys every part by its `tag`, and two parts claiming the same one leaves one of them without
an external ID — reported at render time as `No external ID for <title>`, naming one of the two and
giving no hint that a collision is what happened.

The three kinds of page can genuinely want the same tag, because a project may name a file after the
definition it introduces. Mathlib does this everywhere: with `--root Mathlib.Logic`, the file
`Mathlib/Logic/Denumerable.lean` sits directly under the root, so it is its own chapter *and* its own
module, and it defines `Denumerable` — chapter, module and declaration all claiming `Denumerable`.
`Mathlib.Order` has 31 such cases and `Mathlib.Logic` 6, while `brownian-motion`, `alpha-rar` and
`LeanMachineLearning` have none between them: every one of their files lives in a subdirectory, so
chapter, module and declaration are always three different strings.

Prefixing by kind makes the collision impossible rather than unlikely. Within a kind the names are
already unique — chapter keys, module names and (via `asciiTagOf`) declaration names.

These are *not* the page's `file`, which is what its URL is built from and which was already distinct
in every case. Changing a tag therefore moves no page and breaks no link. -/

/-- Cross-reference tag of a chapter page. See *Page tags*. -/
def chapterTagOf (groupKey : String) : String := s!"chapter-{groupKey}"

/-- Cross-reference tag of a module page. See *Page tags*. -/
def moduleTagOf (moduleName : Name) : String := s!"module-{moduleName}"

/-- Cross-reference tag of a declaration page. See *Page tags*. -/
def declTagOf (name : Name) : String := s!"decl-{asciiTagOf name}"

/-- Cross-reference tag of a declaration's standalone-file page. See *Page tags*. -/
def minimalFileTagOf (name : Name) : String := s!"minimal-{asciiTagOf name}"

/-- Percent-encodes `s` (as UTF-8) for use in a URL path, escaping every byte outside the RFC 3986
unreserved set (`A-Za-z0-9` and `-_.~`). -/
def percentEncode (s : String) : String := Id.run do
  let hexDigit (n : Nat) : Char :=
    if n < 10 then Char.ofNat (0x30 + n) else Char.ofNat (0x41 + (n - 10))
  let unreserved (n : Nat) : Bool :=
    (n ≥ 0x41 && n ≤ 0x5A) || (n ≥ 0x61 && n ≤ 0x7A) || (n ≥ 0x30 && n ≤ 0x39)
      || n == 0x2D || n == 0x5F || n == 0x2E || n == 0x7E
  let mut out : Array Char := #[]
  for b in s.toUTF8.toList do
    let n := b.toNat
    if unreserved n then
      out := out.push (Char.ofNat n)
    else
      out := ((out.push '%').push (hexDigit (n / 16))).push (hexDigit (n % 16))
  return String.ofList out.toList

/-- A link to the live Lean web editor (live.lean-lang.org), pre-loaded (via its `#url=` parameter)
with the extracted standalone file for `name` served from the deployed site at `base`. -/
def leanEditorUrl (base : String) (name : Name) : String :=
  let sep := if base.endsWith "/" then "" else "/"
  s!"https://live.lean-lang.org/#url={base}{sep}extracted/{percentEncode (anchorIdOf name)}.lean"

/-- Helper for joinInlines. -/
def joinInlines (xs : List (Array (Inline Manual))) (sep : Array (Inline Manual)) : Array (Inline Manual) :=
  match xs with
  | [] => #[]
  | x :: rest => rest.foldl (fun acc item => acc ++ sep ++ item) x

/-- Helper for mkLinkParagraph. -/
def mkLinkParagraph (sourceUrl? issueUrl? : Option String) : Option (Block Manual) :=
  let items :=
    ([sourceUrl?.map fun url => .link #[.text "Source"] url,
      issueUrl?.map fun url => .link #[.text "Open Issue"] url].filterMap id)
  if items.isEmpty then
    none
  else
    let entries := items.map fun item => #[item]
    some <| .para <|
      #[.bold #[.text "Actions: "]] ++ joinInlines entries #[.text " · "]

/-- Drops lines that consist solely of a raw HTML tag (e.g. `<div align="center">` or `</div>`),
since `MD_FLAG_NOHTML` causes MD4Lean to render such lines as literal text instead of ignoring
them. -/
def stripHtmlOnlyLines (doc : String) : String :=
  let isHtmlOnlyLine (line : String) : Bool :=
    let trimmed := line.trimAscii
    trimmed.startsWith "<" && trimmed.endsWith ">" && !trimmed.startsWith "<!--"
  String.intercalate "\n" ((doc.splitOn "\n").filter (!isHtmlOnlyLine ·))

/-- Converts markdown text into `Block Manual` nodes. -/
def markdownToBlocks (doc : String) : Array (Block Manual) :=
  let doc := stripHtmlOnlyLines doc
  match MD4Lean.parse doc (MD4Lean.MD_DIALECT_GITHUB ||| MD4Lean.MD_FLAG_LATEXMATHSPANS ||| MD4Lean.MD_FLAG_NOHTML) with
  | none => #[.para #[.text doc]]
  | some parsed =>
      parsed.blocks.foldl
        (fun acc block =>
          match Verso.Genre.Manual.Markdown.blockFromMarkdown' block (handleHeaders := Verso.Genre.Manual.Markdown.strongEmphHeaders') with
          | .ok out => acc.push out
          | .error _ => acc.push (.para #[.text doc]))
        #[]

/-- Trims BlankLines. -/
def trimBlankLines (lines : List String) : List String :=
  let dropFront := lines.dropWhile (fun s => s.trimAscii.isEmpty)
  dropFront.reverse.dropWhile (fun s => s.trimAscii.isEmpty) |>.reverse

/-- Splits README text into sections keyed by `##` headings. -/
def parseMarkdownSections (text : String) : Array MarkdownSection := Id.run do
  let lines := text.splitOn "\n"
  let mut introLines : List String := []
  let mut currentTitle? : Option String := none
  let mut currentBody : List String := []
  let mut sections : Array MarkdownSection := #[]
  for line in lines do
    if line.startsWith "## " then
      match currentTitle? with
      | some title =>
          let body := String.intercalate "\n" (trimBlankLines currentBody.reverse)
          if !body.trimAscii.isEmpty then
            sections := sections.push { title, body }
      | none =>
          let intro := String.intercalate "\n" (trimBlankLines introLines.reverse)
          if !intro.trimAscii.isEmpty then
            sections := sections.push { title := "Overview", body := intro }
      currentTitle? := some (line.drop 3).trimAscii.toString
      currentBody := []
    else if line.startsWith "# " then
      continue
    else
      match currentTitle? with
      | some _ => currentBody := line :: currentBody
      | none => introLines := line :: introLines
  match currentTitle? with
  | some title =>
      let body := String.intercalate "\n" (trimBlankLines currentBody.reverse)
      if !body.trimAscii.isEmpty then
        sections := sections.push { title, body }
  | none =>
      let intro := String.intercalate "\n" (trimBlankLines introLines.reverse)
      if !intro.trimAscii.isEmpty then
        sections := sections.push { title := "Overview", body := intro }
  sections

/-- Reads a file when present, returning `none` when missing. -/
def readFileIfExists (path : System.FilePath) : IO (Option String) := do
  if ← path.pathExists then
    return some (← IO.FS.readFile path)
  return none

/-- Pretty-prints ExprString. -/
def ppExprString (env : Environment) (e : Expr) : IO String := do
  let ctx : PPContext := { env := env, opts := {} }
  return toString (← ctx.runMetaM (Meta.ppExpr e))

/-- The namespace `n` and all of its ancestor namespaces, innermost first. -/
partial def namespaceAncestors : Name → List Name
  | .anonymous => []
  | n => n :: namespaceAncestors n.getPrefix

set_option compiler.checkMeta false in
/-- Builds the same `Block.docstring` value that `{docstring name}` would produce inside
a `#doc` page, by directly invoking Verso's signature/declaration-type computation. Returns
`none` if this fails for the given declaration (e.g. unsupported declaration shapes).

The pretty-printing context opens the declaration's own namespace and all of its ancestors, so
that `scoped` notation declared in those namespaces (e.g. order notation for a structure defined
there) is used instead of falling back to raw instance/projection names.

`Block.Docstring.DeclType.ofName` and `Signature.forName` are `meta` in Verso: they are meant to
run while a `#doc` page elaborates. This tool calls them from the compiled executable instead, so
the module system's phase check has to be switched off for this one definition. Both are ordinary
`LEAN_EXPORT` symbols in Verso's library, so the call links and runs normally. -/
def mkDocstringBlock? (env : Environment) (name : Name) : IO (Option (Block Manual)) := do
  let options := Options.empty.setBool `pp.fieldNotation false
  let coreCtx : Core.Context := { fileName := "<referee>", fileMap := default, options }
  let openDecls := (namespaceAncestors name.getPrefix).map (OpenDecl.simple · [])
  let act : MetaM (Block Manual) := do
    let declType ← Block.Docstring.DeclType.ofName name
    let sig ← (Signature.forName name : Elab.TermElabM Signature).run' {}
    pure <| .other (Block.docstring name declType sig none #[]) #[]
  try
    let block ← (act.run' {}).toIO'
      { coreCtx with currNamespace := name.getPrefix, openDecls } { env := env }
    pure (some block)
  catch _ =>
    pure none

/-- Extracts a declaration's source snippet from an already-loaded array of the file's lines. -/
def sliceSourceSnippet (lines : Array String) (src : SourceInfo) : String :=
  let startIdx := src.line - 1
  let endIdx := min src.endLine lines.size
  let selected := (List.range (endIdx - startIdx)).map fun i => lines[startIdx + i]!
  String.intercalate "\n" selected

/-- Computes declaration Keyword. -/
def declKeyword : DeclKind → String
  | .theorem => "theorem"
  | .definition => "def"
  | .opaque => "opaque"
  | .structure => "structure"
  | .typeclass => "class"
  | .inductive => "inductive"
  | .axiom => "axiom"
  | .instance => "instance"

/-- The signature to show when a declaration has no usable source of its own: its pretty-printed
type, introduced by the keyword it was written with.

`isLemma` matters because the fallback is exactly what an *attribute-generated* declaration gets —
`to_dual` and `to_additive` leave the generated sibling with a source range covering only the
attribute — and rendering `theorem foo : …` inside a card labelled "Lemma" contradicts the label. -/
def displaySignatureFallback (kind : DeclKind) (name : Name) (expandedSignature : String)
    (isLemma : Bool := false) : String :=
  let keyword := if isLemma && kind == .theorem then "lemma" else declKeyword kind
  s!"{keyword} {name.getString!} : {expandedSignature}"

/-- Helper for stringContains. -/
def stringContains (haystack needle : String) : Bool :=
  (haystack.splitOn needle).length > 1

/-- Scans one line of an `@[…]` attribute that is still open, given the bracket `depth` reached so
far and whether the scan is inside a string literal.

Returns `.inl (depth, inString)` if the attribute is still unclosed at the end of the line, or
`.inr remainder` with what follows the `]` that closed it.

Counting depth, and tracking string literals, is what makes this correct rather than a search for
the first `]`: an attribute argument can contain a bracket (`@[specifies f "the a[i] case"]`), and
one that closes early would leave the tail of the attribute glued to the front of the statement. -/
def scanAttributeLine (chars : List Char) (depth : Nat) (inString : Bool) :
    (Nat × Bool) ⊕ String :=
  match chars with
  | [] => .inl (depth, inString)
  | c :: rest =>
    if inString then
      -- An escape consumes the next character, so `"\""` does not end the literal. At end of line
      -- this leaves the scan inside the string, which is also what Lean's string gap (`\` then a
      -- newline) needs.
      if c == '\\' then
        match rest with
        | [] => .inl (depth, true)
        | _ :: rest => scanAttributeLine rest depth true
      else scanAttributeLine rest depth (c != '"')
    else if c == '"' then scanAttributeLine rest depth true
    else if c == '[' then scanAttributeLine rest (depth + 1) false
    else if c == ']' then
      if depth ≤ 1 then .inr (String.ofList rest) else scanAttributeLine rest (depth - 1) false
    else scanAttributeLine rest depth false

/-- Drops a leading `@[…]` attribute from `lines`, which may span several of them, and returns what
follows it. -/
partial def dropAttributeBlock (lines : List String) : List String :=
  go lines 0 false
where
  go (lines : List String) (depth : Nat) (inString : Bool) : List String :=
    match lines with
    | [] => []
    | line :: rest =>
      match scanAttributeLine line.toList depth inString with
      | .inl (depth, inString) => go rest depth inString
      | .inr remainder => if remainder.trimAscii.isEmpty then rest else remainder :: rest

/-- Drops the docstrings and attributes preceding a declaration, so that what is left starts at the
declaration keyword. Everything downstream reads that first word: the displayed signature, and the
`lemma`/`instance`/`alias` detection that decides how a declaration is labelled and whether it
counts as a claim. -/
partial def dropLeadingDecorations (lines : List String) : List String :=
  let lines := lines.dropWhile (fun line => line.trimAscii.isEmpty)
  match lines with
  | [] => []
  | line :: rest =>
      let trimmed := (String.trimAscii line).toString
      if trimmed.startsWith "/-" then
        let rec dropCommentBlock : List String → List String
          | [] => []
          | commentLine :: remaining =>
              if stringContains commentLine "-/" then
                remaining
              else
                dropCommentBlock remaining
        dropLeadingDecorations (dropCommentBlock (line :: rest))
      else if trimmed.startsWith "@[" then
        dropLeadingDecorations (dropAttributeBlock (line :: rest))
      else
        line :: rest

/-- Helper for cleanDeclSnippet. -/
def cleanDeclSnippet (snippet : String) : String :=
  (String.trimAscii (String.intercalate "\n" (dropLeadingDecorations (snippet.splitOn "\n")))).toString

/-- How far past a declaration's recorded range to look for its keyword. Bounded so that a range
which cleans to nothing and is followed by no declaration cannot scan to the end of the file. -/
def declKeywordLookahead : Nat := 40

/-- The cleaned snippet to read a declaration's *keyword* from — the word that decides whether the
site labels it `lemma`, `theorem` or `instance`.

Usually this is just the cleaned source range. The exception, and the only reason this function
looks past that range, is an **attribute-generated declaration**. Given

```lean
@[to_dual min_le]
lemma le_max (x : ι) : f x ≤ max f := …
```

Lean records, for the generated `min_le`, a declaration range covering *only the attribute line*.
Cleaning it strips the attribute and leaves nothing, so the `lemma` the author wrote is never seen
and the declaration is labelled a theorem — which puts it on the Claims page, among the results the
library is asserting for its own sake. `to_additive` produces exactly the same shape, as does any
other attribute that generates a sibling declaration.

Only the keyword is taken from the following lines, never the statement. A generated declaration
says something *different* from the one it was generated from — `min_le` is not `le_max` — so its
displayed signature must keep coming from its own pretty-printed type. That is why this is separate
from `displaySignatureFromSource` rather than a fix inside it. -/
def keywordSnippet (src : SourceInfo) (lines : Array String) : String :=
  let cleaned := cleanDeclSnippet (sliceSourceSnippet lines src)
  if !cleaned.isEmpty then
    cleaned
  else
    let startIdx := src.line - 1
    let endIdx := min (startIdx + declKeywordLookahead) lines.size
    if endIdx ≤ startIdx then ""
    else
      let window := (List.range (endIdx - startIdx)).map fun i => lines[startIdx + i]!
      (String.trimAscii (String.intercalate "\n" (dropLeadingDecorations window))).toString

/-- Splits a declaration's source snippet at the `:=` separating its signature from its value, into
the part before and the part after.

The separator is the first `:=` **at bracket depth zero**, not simply the first one, and the
distinction is not academic. A statement may contain any number of `:=` tokens inside brackets — a
named argument (`Tendsto (β := ProbabilityMeasure …)`), a structure instance (`{ x := 1 }`), a
binder default (`(n : ℕ := 0)`) — and splitting on the first of them truncates the statement
mid-expression while handing its tail to the proof section. Depth counting is enough to tell them
apart, since the proof separator is the only one a declaration can have outside every bracket.

Returns `none` when there is no top-level `:=` at all, which is the ordinary case for an `axiom` or
a declaration whose value is given by `where` clauses. -/
def splitAtAssignment (snippet : String) : Option (String × String) := Id.run do
  let chars := snippet.toList
  let arr := chars.toArray
  let mut depth : Int := 0
  let mut cut : Option Nat := none
  for i in [0:arr.size] do
    if cut.isNone then
      let c := arr[i]!
      if c == '(' || c == '[' || c == '{' || c == '⟨' then
        depth := depth + 1
      else if c == ')' || c == ']' || c == '}' || c == '⟩' then
        depth := depth - 1
      else if c == ':' && depth == 0 && i + 1 < arr.size && arr[i + 1]! == '=' then
        cut := some i
  match cut with
  | none => return none
  | some k => return some (String.ofList (chars.take k), String.ofList (chars.drop (k + 2)))

/-- The signature part of a snippet: everything before the top-level `:=`, or the whole snippet
when it has none. -/
def headBeforeAssignment (snippet : String) : String :=
  match splitAtAssignment snippet with
  | some (head, _) => (String.trimAscii head).toString
  | none => (String.trimAscii snippet).toString

/-- Helper for headBeforeWhere. -/
def headBeforeWhere (snippet : String) : String :=
  let rec go (remaining : List String) (acc : List String) :=
    match remaining with
    | [] => String.intercalate "\n" acc.reverse
    | line :: rest =>
        let acc := line :: acc
        let trimmed := (String.trimAscii line).toString
        if trimmed == "where" || trimmed.endsWith " where" || trimmed.endsWith "where" then
          String.intercalate "\n" acc.reverse
        else
          go rest acc
  (String.trimAscii (go (snippet.splitOn "\n") [])).toString

/-- Helper for displaySignatureFromSource. -/
def displaySignatureFromSource (kind : DeclKind) (src? : Option SourceInfo) (lines : Array String) : Option String :=
  match src? with
  | none => none
  | some src =>
    let snippet := cleanDeclSnippet (sliceSourceSnippet lines src)
    if snippet.isEmpty then
      none
    else
      let rendered :=
        match kind with
        | .definition | .structure | .typeclass | .inductive => snippet
        | _ => headBeforeAssignment snippet
      if rendered.isEmpty then none else some rendered

/-! ## Reading a declaration's keyword from parsed syntax

Which keyword a declaration was written with is not recoverable from the compiled environment.
Mathlib's `lemma` is a macro that erases itself before elaboration —

```lean
@[macro «lemma»] def expandLemma : Macro := fun stx =>
  let stx := stx.modifyArg 1 fun stx =>
    let stx := stx.modifyArg 0 (mkAtomFrom · "theorem" (canonical := true))
    stx.setKind ``Parser.Command.theorem
  pure <| stx.setKind ``Parser.Command.declaration
```

— so the elaborator only ever sees a theorem, `ConstantInfo` has nowhere to record the word, and no
environment extension carries it. The source text is the only witness, which is why this is read
back rather than looked up.

Reading it by parsing rather than by matching the text is what makes it robust. `IO.processCommands`
re-elaborates the file against the already-loaded environment and hands back each command's `Syntax`,
so the answer comes from the same parser that accepted the file: modifiers on their own line, doc
comments, multi-line attribute blocks and `set_option … in` wrappers are all just structure. It also
settles the case the text can never settle — an *attribute-generated* declaration (`to_dual`,
`to_additive`) whose recorded range covers only the attribute line falls inside the generating
command, and so inherits its keyword by construction rather than by a lookahead heuristic.

The string-based readers below remain as the fallback for a declaration whose range no parsed
command covers.
-/

/-- What one parsed command says about the keyword its declarations were written with, and the line
range it covers.

Reduced to these flags at parse time rather than kept as `Syntax`: the whole point is one pass per
file, and holding every command's tree for every project module at once is a great deal of memory
for three bits. -/
structure CommandKeyword where
  startLine : Nat
  endLine : Nat
  isLemma : Bool
  isInstance : Bool
  isAlias : Bool
deriving Repr, Inhabited

/-- Parses `source` against `env` (`parseCommands`) and reports, per command, its line range and the
keyword its declarations were written with. -/
def commandKeywordsOf (env : Environment) (source : String) (filePath : String) :
    IO (Array CommandKeyword) := do
  let fileMap := source.toFileMap
  let commands ← parseCommands env source filePath
  return commands.filterMap fun stx =>
    match stx.getPos?, stx.getTailPos? with
    | some p, some e =>
      some {
        startLine := (fileMap.toPosition p).line
        endLine := (fileMap.toPosition e).line
        isLemma := containsSyntaxKind stx lemmaSyntaxKinds
        isInstance := containsSyntaxKind stx instanceSyntaxKinds
        isAlias := containsSyntaxKind stx aliasSyntaxKinds
      }
    | _, _ => none

/-- The command covering `line`, or `none` if no parsed command does.

Takes the last such command, so that a declaration inside a wrapper is attributed to the innermost
enclosing one when ranges overlap. -/
def commandKeywordAt? (cmds : Array CommandKeyword) (line : Nat) : Option CommandKeyword :=
  cmds.foldl (init := none) fun best c =>
    if c.startLine ≤ line && line ≤ c.endLine then
      match best with
      | some b => if c.startLine ≥ b.startLine then some c else best
      | none => some c
    else best

/-- The modifiers Lean allows between a declaration's attributes and its keyword.

Stripped only when reading the *keyword*, never from the displayed signature: `protected lemma foo`
is what the author wrote and is what the page should show. It is the classification that must look
past them, because `protected lemma` is still a lemma. -/
def declModifiers : Array String :=
  #["private", "protected", "public", "noncomputable", "unsafe", "partial", "nonrec", "scoped",
    "local", "meta"]

/-- Drops any leading `declModifiers` from a cleaned snippet, so the next word is the keyword.

Repeated because they combine: `protected noncomputable def`, `public meta def`.

Splits on *any* whitespace rather than on a space, because a modifier is routinely left on a line of
its own — `brownian-motion` writes

```lean
protected
lemma _root_.SupClosed.mem_countableSupClosure_iff …
```

and matching `"protected "` reads straight past that. -/
partial def dropDeclModifiers (s : String) : String :=
  let s := (String.trimAscii s).toString
  let word := (s.takeWhile (!·.isWhitespace)).toString
  if declModifiers.contains word then
    dropDeclModifiers (s.drop word.length).toString
  else
    s

/-- True if the cleaned source snippet for a `theorem`-kind declaration starts with the `lemma`
keyword rather than `theorem`.

The **fallback** for `commandKeywordsOf`, used only where no parsed command covers a declaration's
range. Reads past any visibility or binder modifier. Getting this wrong is not cosmetic: `isLemma`
feeds `DeclInfo.isClaim`, so a `protected lemma` read as a theorem is promoted onto the Claims page,
among the results the library asserts for their own sake. -/
def isLemmaFromSource (kind : DeclKind) (src? : Option SourceInfo) (lines : Array String) : Bool :=
  if kind != .theorem then
    false
  else match src? with
    | none => false
    | some src => (dropDeclModifiers (keywordSnippet src lines)).startsWith "lemma "

/-- True if the cleaned source snippet for a `theorem`-kind declaration starts with the
`instance` keyword (e.g. a `Prop`-valued instance whose `@[instance]` attribute was not picked
up by `declKindOf`). -/
def isInstanceFromSource (kind : DeclKind) (src? : Option SourceInfo) (lines : Array String) : Bool :=
  if kind != .theorem then
    false
  else match src? with
    | none => false
    | some src => (dropDeclModifiers (keywordSnippet src lines)).startsWith "instance "

/-- True if the declaration's source snippet starts with the `alias` keyword. Such declarations are
emitted verbatim (`alias … := target`), so their dependency closure must follow value dependencies. -/
def isAliasFromSource (src? : Option SourceInfo) (lines : Array String) : Bool :=
  match src? with
  | none => false
  | some src =>
    (dropDeclModifiers (cleanDeclSnippet (sliceSourceSnippet lines src))).startsWith "alias "

/-- True if `name`'s last component follows the standard naming convention for
compiler-generated instances (e.g. `instDecidableEqFoo` from a `deriving` clause), namely
`inst` followed by an uppercase letter. Such declarations are not written with the `instance`
keyword in the source (there is no source line to inspect), so `isInstanceFromSource` cannot
catch them. -/
def isInstanceName (name : Name) : Bool :=
  let s := name.getString!
  s.startsWith "inst" && s.length > 4 && (s.drop 4).front.isUpper

/-- All ways to split `s` at an internal underscore into a non-empty `(prefix, suffix)` pair. -/
def underscoreSplits (s : String) : List (String × String) :=
  let chars := s.toList
  (List.range chars.length).filterMap fun i =>
    if i > 0 && i < chars.length - 1 && chars[i]! == '_' then
      some (String.ofList (chars.take i), String.ofList (chars.drop (i + 1)))
    else
      none

/-- True if `name` looks like a `@[simps]`-generated projection lemma: a `@[simp]`-tagged
theorem whose short name has the form `<sibling>_<field>`, where `<sibling>` is itself a
declaration in the same namespace (the definition/instance the `@[simps]` attribute was applied
to). -/
def isSimpsGeneratedLemma (env : Environment) (simpLemmaNames : Std.HashSet Name) (name : Name)
    (info : ConstantInfo) : Bool :=
  match info with
  | .thmInfo _ =>
    simpLemmaNames.contains name &&
      match name with
      | .str pfx s =>
          (underscoreSplits s).any fun (sibling, _) => (env.find? (.str pfx sibling)).isSome
      | _ => false
  | _ => false

/-- Strips DeclPrefix. -/
def stripDeclPrefix (kind : DeclKind) (shortName : String) (signature : String) : String :=
  let pfx := s!"{declKeyword kind} {shortName}"
  match signature.dropPrefix? pfx with
  | some rest => (String.trimAscii rest.toString).toString
  | none => signature

/-- Splits TopLevelColon?. -/
def splitTopLevelColon? (s : String) : Option (String × String) :=
  let rec go (chars : List Char) (round curly square angled : Nat) (acc : List Char) : Option (String × String) :=
    match chars with
    | [] => none
    | ':' :: rest =>
        if round == 0 && curly == 0 && square == 0 && angled == 0 then
          some (
            (String.trimAscii (String.ofList acc.reverse)).toString,
            (String.trimAscii (String.ofList rest)).toString
          )
        else
          go rest round curly square angled (':' :: acc)
    | '(' :: rest => go rest (round + 1) curly square angled ('(' :: acc)
    | ')' :: rest => go rest (round - 1) curly square angled (')' :: acc)
    | '{' :: rest => go rest round (curly + 1) square angled ('{' :: acc)
    | '}' :: rest => go rest round (curly - 1) square angled ('}' :: acc)
    | '[' :: rest => go rest round curly (square + 1) angled ('[' :: acc)
    | ']' :: rest => go rest round curly (square - 1) angled (']' :: acc)
    | '⦃' :: rest => go rest round curly square (angled + 1) ('⦃' :: acc)
    | '⦄' :: rest => go rest round curly square (angled - 1) ('⦄' :: acc)
    | ch :: rest => go rest round curly square angled (ch :: acc)
  go s.toList 0 0 0 0 []

/-- Helper for signatureSections?. -/
def signatureSections? (kind : DeclKind) (shortName : String) (signature : String) : Option (String × String) :=
  match kind with
  | .theorem | .definition | .opaque | .axiom | .instance =>
      let remainder := stripDeclPrefix kind shortName signature
      splitTopLevelColon? remainder
  | _ => none

/-- Infers the display kind for a declaration from environment metadata. -/
def declKindOf (env : Environment) (info : ConstantInfo) (name : Name) : DeclKind :=
  if Lean.Meta.isInstanceCore env name then
    .instance
  else if isClass env name then
    .typeclass
  else match info with
    | .thmInfo _ => .theorem
    | .opaqueInfo _ => .opaque
    | .axiomInfo _ => .axiom
    | .inductInfo _ =>
        if (getStructureInfo? env name).isSome then
          .structure
        else
          .inductive
    | .defnInfo _ => .definition
    | _ => .definition

/-- Computes source PathForModule. -/
def sourcePathForModule (pkg : Lake.Package) (moduleName : Name) : Option System.FilePath :=
  (pkg.findModule? moduleName).map (·.leanFile)

/-- Computes module SourcePath. -/
def moduleSourcePath (projectDir : System.FilePath) (moduleName : Name) : System.FilePath :=
  projectDir / s!"{moduleName.toString.replace "." "/"}.lean"

/-- Parses ImportedModule?. -/
def parseImportedModule? (line : String) : Option Name :=
  let trimmed := (String.trimAscii line).toString
  let prefixes := ["public import ", "import "]
  prefixes.findSome? fun pfx =>
    if trimmed.startsWith pfx then
      let rest := (String.trimAscii (trimmed.drop pfx.length |>.toString)).toString
      if rest.isEmpty then none else some rest.toName
    else
      none

/-- Visits ModuleImports. -/
partial def visitModuleImports (projectDir : System.FilePath) (rootPrefix : Name)
    (moduleName : Name) (visited : Std.HashSet Name) (order : Std.HashMap Name Nat)
    (nextRank : Nat) : IO (Std.HashSet Name × Std.HashMap Name Nat × Nat) := do
  if visited.contains moduleName then
    return (visited, order, nextRank)
  let visited := visited.insert moduleName
  let text? ← readFileIfExists (moduleSourcePath projectDir moduleName)
  match text? with
  | none => return (visited, order, nextRank)
  | some contents =>
      let imports : List Name := (contents.splitOn "\n").filterMap parseImportedModule?
      let imports := imports.filter fun imported => imported != moduleName && hasPrefixName imported rootPrefix
      let mut visited := visited
      let mut order := order
      let mut nextRank := nextRank
      for imported in imports do
        if !order.contains imported then
          order := order.insert imported nextRank
          nextRank := nextRank + 1
        let (visited', order', nextRank') ← visitModuleImports projectDir rootPrefix imported visited order nextRank
        visited := visited'
        order := order'
        nextRank := nextRank'
      return (visited, order, nextRank)

/-- Computes import-traversal order used to rank modules and groups. -/
def moduleOrderMap (projectDir : System.FilePath) (rootPrefix : Name) : IO (Std.HashMap Name Nat) := do
  let rootFile := moduleSourcePath projectDir rootPrefix
  if !(← rootFile.pathExists) then
    return {}
  let initial : Std.HashMap Name Nat := {}
  let (_, order, _) ← visitModuleImports projectDir rootPrefix rootPrefix {} (initial.insert rootPrefix 0) 1
  return order

/-- Helper for proofTextFromSource. -/
def proofTextFromSource (kind : DeclKind) (src? : Option SourceInfo) (lines : Array String) : Option String :=
  match kind, src? with
  | .theorem, some src
  | .opaque, some src
  | .instance, some src =>
      -- Clean first, exactly as `displaySignatureFromSource` does. Without it the split below
      -- lands on a `:=` *inside an attribute* — `@[to_additive (attr := simp)]` made the "Proof"
      -- section start with `simp)]` followed by the entire declaration.
      let snippet := cleanDeclSnippet (sliceSourceSnippet lines src)
      match splitAtAssignment snippet with
      | some (_, proof) => some (String.trimAscii proof).toString
      | none => some snippet
  | _, _ => none

/-- Computes module IndexMap. -/
def moduleIndexMap (decls : Array DeclInfo) : Std.HashMap Name (Array DeclInfo) :=
  decls.foldl
    (fun acc decl => acc.insert decl.moduleName ((acc.getD decl.moduleName #[]).push decl))
    {}

/-- Computes group IndexMap. -/
def groupIndexMap (mods : Array ModuleInfo) : Std.HashMap String (Array ModuleInfo) :=
  mods.foldl
    (fun acc modInfo => acc.insert modInfo.groupKey ((acc.getD modInfo.groupKey #[]).push modInfo))
    {}

/-- Builds a prefilled GitHub issue URL for declaration review. -/
def issueUrlOf (repoUrl? : Option String) (decl : Name) (moduleName : Name) (source? : Option SourceInfo) (dependsOnSorry : Bool) : Option String :=
  repoUrl?.map fun repoUrl =>
    let title := s!"Review: {decl.getString!}"
    let sourceLine :=
      match source? with
      | some src => s!"**Source:** {src.relPath}:{src.line}"
      | none => "**Source:** unavailable"
    let body := String.intercalate "%0A" [
      s!"**Declaration:** `{decl}`",
      s!"**Module:** `{moduleName}`",
      sourceLine,
      s!"**Status:** {if dependsOnSorry then "sorry" else "proved"}",
      "",
      "---",
      "",
      "**Describe the issue:**",
      ""
    ]
    s!"{repoUrl}/issues/new?title={title}&body={body}&labels=referee-review"

/-- Builds a repository source link for a declaration location.

`ref` is the branch or commit to link into. It defaults to `main`, which is what every link here
used to be pinned to — and which quietly rots: a published site keeps pointing at line 88 of a file
that has moved on, so the link lands on whatever now happens to be there. Given a provenance
ledger, `build-site` passes the commit the ledger was folded at instead, and the links keep showing
the code the site was actually built from. -/
def sourceUrlOf (repoUrl? : Option String) (source? : Option SourceInfo) (ref : String := "main")
    : Option String :=
  match repoUrl?, source? with
  | some repoUrl, some src => some s!"{repoUrl}/blob/{ref}/{src.relPath}#L{src.line}"
  | _, _ => none

/-- Computes repository FileUrlOf. -/
def repoFileUrlOf (repoUrl? : Option String) (relPath : String) (ref : String := "main")
    : Option String :=
  repoUrl?.map fun repoUrl => s!"{repoUrl}/blob/{ref}/{relPath}"

/-- Computes group HrefOf. -/
def groupHrefOf (groupKey : String) : String :=
  s!"chapter-{slugify groupKey}/"

/-- Computes module HrefOf. -/
def moduleHrefOf (modulePath : String) : String :=
  s!"module-{slugify modulePath}/"

/-- Computes path ForPart. -/
def pathForPart (groupKey modulePath : String) (declName : Name) : String :=
  s!"{groupHrefOf groupKey}{moduleHrefOf modulePath}#{anchorIdOf declName}"

/-- Maps each declaration name to its generated page anchor path. -/
def declHrefMap (decls : Array DeclInfo) : Std.HashMap Name String :=
  decls.foldl
    (fun acc decl => acc.insert decl.name (pathForPart decl.groupKey decl.modulePath decl.name))
    {}

/-- Computes path ForDeclPage. -/
def pathForDeclPage (groupKey modulePath : String) (declName : Name) : String :=
  s!"{groupHrefOf groupKey}{moduleHrefOf modulePath}decl-{anchorIdOf declName}/"

/-- Maps each declaration name to its dedicated detail page. -/
def declPageHrefMap (decls : Array DeclInfo) : Std.HashMap Name String :=
  decls.foldl
    (fun acc decl => acc.insert decl.name (pathForDeclPage decl.groupKey decl.modulePath decl.name))
    {}

/-- Maps each declaration name to its `DeclInfo`. -/
def declByNameMap (decls : Array DeclInfo) : Std.HashMap Name DeclInfo :=
  decls.foldl (fun acc decl => acc.insert decl.name decl) {}

/-- True if `n` survives a round trip through `Name`'s JSON codec (`toString` then `toName`).
This is lossy for names containing characters outside a normal identifier — notably auto-generated
helper names from *external* libraries, which can embed hygiene markers like `_@.Mathlib.Foo.123`
that aren't valid surface syntax and so don't parse back to the original name. -/
def isJsonSafeName (n : Name) : Bool :=
  n.toString.toName == n

/-- Drops names that don't round-trip through JSON (see `isJsonSafeName`) from `deps`/`typeDeps`,
so that serializing `decls` for the `collect` subcommand can't fail. Safe to do unconditionally:
every consumer of `deps`/`typeDeps` (graph edges, the closure listings, the extraction closure)
already discards anything that isn't itself an exposed project declaration, and a name needing
this escape hatch is never one (`shouldExpose` already excludes internal/auto-generated names from
being exposed), so this can only drop names that were already inert. -/
def dropUnsafeDeps (decls : Array DeclInfo) : Array DeclInfo :=
  decls.map fun d => { d with
    deps := d.deps.filter isJsonSafeName
    typeDeps := d.typeDeps.filter isJsonSafeName
    dataDeps := d.dataDeps.filter isJsonSafeName
  }

/-- Helper for runCoreIO. -/
def runCoreIO {α : Type} (env : Environment) (x : CoreM α) : IO α := do
  x.toIO'
    { fileName := "<referee>", fileMap := default, options := {}, currNamespace := .anonymous, openDecls := [] }
    { env := env, ngen := { namePrefix := `_referee } }

/-- Retrieves declaration source ranges, returning `none` on failure. -/
def findRanges? (env : Environment) (name : Name) : IO (Option DeclarationRanges) := do
  try
    runCoreIO env (findDeclarationRanges? name)
  catch _ =>
    pure none

/-- Helper for relativeSourcePath. -/
def relativeSourcePath (projectDir absPath : System.FilePath) : IO String := do
  let projectDir ← IO.FS.realPath projectDir
  let absPath ← IO.FS.realPath absPath
  let project := projectDir.normalize.toString
  let path := absPath.normalize.toString
  match path.dropPrefix? (project ++ "/") with
  | some rel => pure rel.toString
  | none =>
      match path.dropPrefix? project with
      | some rel => pure <| (rel.toString.dropWhile (· == '/')).toString
      | none => pure path

/-- Converts declaration ranges into serializable source metadata. -/
def toSourceInfo? (projectDir : System.FilePath) (pkg : Lake.Package) (moduleName : Name) (ranges? : Option DeclarationRanges) : IO (Option SourceInfo) := do
  let some ranges := ranges? | return none
  let some absPath := sourcePathForModule pkg moduleName | return none
  let absPath ← IO.FS.realPath absPath
  let relPath ← relativeSourcePath projectDir absPath
  return some {
    relPath := relPath
    absPath := absPath
    line := ranges.range.pos.line
    endLine := ranges.range.endPos.line
  }

/-- Every exposed declaration's axiom set, via `Lean.collectAxioms`.

Lean precomputes each declaration's axiom set when the `.olean` is written and looks it up by
binary search for imported declarations, so this is a table lookup per declaration rather than a
walk of the closure. It also means the answer is the honest one: a `sorry` lifted into a
compiler-generated `_proof_N` helper counts, and so does one inherited from an upstream library.

This is the same answer `#print axioms` gives. Keeping the whole set rather than collapsing it to
"does this rest on `sorry`" is what lets the site report *what* a result assumes, not just whether
it is suspicious: `Classical.choice`/`propext`/`Quot.sound` are the ordinary three, while anything
else is a claim the reader has to accept on faith. -/
def axiomsOfDecls (env : Environment) (names : Array Name) : IO (Std.HashMap Name (Array Name)) :=
  runCoreIO env do
    let mut acc : Std.HashMap Name (Array Name) := {}
    for name in names do
      let axs ← Lean.collectAxioms name
      acc := acc.insert name (axs.qsort Name.lt)
    return acc

/-- Each package's depth in the workspace dependency graph: one more than the deepest package it
depends on, and `0` for one that depends on nothing.

This is the order the graph's upstream band stacks in. Mathlib depends on nothing else the reader
sees, so it goes on top; a package built on Mathlib goes below it; the project's own declarations go
below that, in the dependency rows. The band then reads the way the rest of the picture does —
everything sits below what it depends on — instead of being ordered by a property of the *reader*
(which packages they happened to audit), which says nothing about where a constant comes from.

Relaxed to a fixpoint rather than walked, bounded by the number of packages: a longest path in a DAG
cannot exceed that, and the bound is also what makes a dependency cycle terminate rather than
recurse forever. Workspaces have tens of packages, so the cost is irrelevant. -/
def packageRanks (packages : Array PackageInfo) : Std.HashMap Name Nat := Id.run do
  let mut rank : Std.HashMap Name Nat := packages.foldl (fun acc p => acc.insert p.name 0) {}
  for _ in [0:packages.size] do
    let mut changed := false
    for p in packages do
      let d := p.deps.foldl (fun m dep => max m (rank.getD dep 0 + 1)) 0
      if d > rank.getD p.name 0 then
        rank := rank.insert p.name d
        changed := true
    if !changed then break
  return rank

/-- The packages a reader is being told to trust, given the ones named with `--trust`: those, plus
everything they depend on, plus the toolchain.

Closing downwards is the whole semantics of the flag. Trusting Mathlib while treating `batteries` as
unaudited would be incoherent — Mathlib's own theorems rest on it — so naming a package necessarily
vouches for what it is built from. The toolchain is trusted unconditionally: it is the compiler and
kernel that checked every other package, so a site cannot coherently offer it as a choice.

Unknown names are *not* silently ignored; `unknownTrustedPackages` reports them, because a typo in
`--trust mathlbi` would otherwise read as a clean audit of nothing. -/
partial def trustClosure (packages : Array PackageInfo) (trusted : Array Name) : Std.HashSet Name :=
  let byName : Std.HashMap Name PackageInfo :=
    packages.foldl (fun acc pkg => acc.insert pkg.name pkg) {}
  go byName (trusted.toList ++
    (packages.filterMap fun pkg => if pkg.isToolchain then some pkg.name else none).toList) {}
where
  go (byName : Std.HashMap Name PackageInfo) (todo : List Name) (seen : Std.HashSet Name) :
      Std.HashSet Name :=
    match todo with
    | [] => seen
    | name :: rest =>
      if seen.contains name then go byName rest seen
      else
        let seen := seen.insert name
        match byName.get? name with
        | some pkg => go byName (pkg.deps.toList ++ rest) seen
        | none => go byName rest seen

/-- The `--trust` names that match no package in the workspace. See `trustClosure`. -/
def unknownTrustedPackages (packages : Array PackageInfo) (trusted : Array Name) : Array Name :=
  trusted.filter fun name => !packages.any (·.name == name)

/-- The `Lean` pseudo-package: the toolchain, which owns `Init`/`Std`/`Lean`/`Lake` and belongs to
no Lake package. -/
def toolchainPackage : PackageInfo where
  name := `Lean
  roots := #[`Init, `Std, `Lean, `Lake]
  isToolchain := true

/-- The workspace's packages, plus the `Lean` pseudo-package, with their declared dependencies and
library roots.

Roots come from the Lake configuration rather than from the modules actually present, because they
are what attributes a module to a package, and a package contributes roots whether or not this
particular project imports anything under them. -/
def packageInfosOf (ws : Lake.Workspace) (rootPrefix : Name) : Array PackageInfo :=
  -- `baseName`, not `keyName`: the latter carries Lake's workspace index (`mathlib.4`), which
  -- would be what `--trust` had to be spelled with and what the graph displayed.
  let named := ws.packages.map fun pkg =>
    let deps := pkg.depIdxs.filterMap fun i => ws.packages[i]?.map (·.baseName)
    let roots := pkg.leanLibs.flatMap (·.config.roots)
    { name := pkg.baseName
      deps := deps
      roots := roots
      -- By root prefix rather than by workspace position: `--root` may name a library of the root
      -- package, and it is the exposed library that "the project" means here.
      isProject := roots.any (hasPrefixName rootPrefix ·)
      : PackageInfo }
  named.push toolchainPackage

/-- Attributes each module of the environment to a package, by longest matching library root.

Longest wins so that a package whose root is nested under another's (`Foo.Bar` under `Foo`) claims
its own modules. A module matching no root at all is left unattributed and reported by `collect`
rather than silently folded into some package: it means the workspace's roots do not cover what the
project actually imports, and a trust claim over an incomplete attribution would be worthless. -/
def modulePackageOf (packages : Array PackageInfo) (moduleName : Name) : Option Name :=
  let candidates := packages.flatMap fun pkg =>
    pkg.roots.filterMap fun root =>
      if hasPrefixName moduleName root then some (root.getNumParts, pkg.name) else none
  let best : Option (Nat × Name) :=
    candidates.foldl (init := none) fun best (depth, name) =>
      match best with
      | some (bestDepth, _) => if depth > bestDepth then some (depth, name) else best
      | none => some (depth, name)
  best.map Prod.snd

/-- The packages with at least one module in the imported environment.

An exact bound on what any closure can possibly reach, and the thing that keeps the Lake-graph
closure from being useless. `LeanMachineLearning` *declares* a dependency on `verso` — it builds its
own site with it — so closing the Lake graph downwards reports every declaration that uses LML as
resting on Verso, SubVerso, MD4Lean and Illuminate too. None of that code is loaded here: no module
the project imports belongs to those packages, so no constant in any closure can live in one.
Intersecting with this set removes them without weakening the guarantee. -/
def loadedPackagesOf (env : Environment) (packages : Array PackageInfo) : Array Name :=
  let acc := env.header.moduleNames.foldl (init := ({} : Std.HashSet Name)) fun acc moduleName =>
    match modulePackageOf packages moduleName with
    | some pkg => acc.insert pkg
    | none => acc
  acc.toArray.qsort Name.lt

/-- The edges the project-local *closure* follows: type-only for theorems, type and body for
everything else. Computed from the raw `LeanDeps` result, before a `DeclInfo` exists to ask.

This is the wider of the two edge choices and exists for one consumer: `transDeps`, which
`Referee.Extract` seeds each standalone file from. A file whose kept tactic bodies lost the lemmas
they call would not compile, so this must stay closed over proofs. Everything that asks what a
declaration *means* or what a reader must *trust* uses `meaningDepsOf` instead. -/
def closureDepsOf (kind : DeclKind) (isAlias : Bool) (deps typeDeps : Array Name) : Array Name :=
  if kind == .theorem && !isAlias then typeDeps else deps

/-- The edges *meaning and trust* follow: nothing a proof merely calls.

Three cases, one principle. A theorem contributes its statement, not its proof — the kernel already
checked the proof, and anything left unproved in it arrives as a `sorry` or an extra axiom, both
reported transitively elsewhere. A definition contributes its type and the *data* in its value, but
not the proofs embedded in it: the obligations of a bundled structure (`left_inv`, `map_add'`, …)
are kernel-checked in exactly the same way and say nothing about what the definition means. An
`alias` contributes its value regardless, because it is emitted verbatim and its target is a genuine
dependency of the text.

An empty `dataDeps` beside a non-empty `deps` means the analysis was not run — `DeclInfo.dataDeps`
defaults to `#[]`, and a genuinely computed one is empty only when `deps` is, since it always
contains the type's constants. That case falls back to `deps`, so a `DeclInfo` built by hand (or
decoded from data an older `collect` wrote) reports too much rather than too little. Which way it
errs matters here and nowhere else: under-reporting would tell a reader they do not rest on code
they do. -/
def meaningDepsOf (kind : DeclKind) (isAlias : Bool) (deps typeDeps dataDeps : Array Name) :
    Array Name :=
  if isAlias then deps
  else if kind == .theorem then typeDeps
  else if dataDeps.isEmpty then deps
  else dataDeps

/-- Truncates `s` to `n` characters, marking that it was truncated. A panel-sized preview: the
declaration's own page carries the whole thing. -/
def clipTo (n : Nat) (s : String) : String :=
  let s := (String.trimAscii s).toString
  if s.length ≤ n then s else (s.take n).trimAscii.toString ++ "…"

/-- What an upstream constant says beyond its type: a definition's value, or a structure's fields
one per line. Empty for a theorem (its type is its statement, and its proof is not something a
reader of this site is being asked to read) and for anything else.

Clipped at `maxExternalValue`. `Expr` is a DAG and printed syntax is a tree, so a value can expand
by orders of magnitude — the failure recorded in `KNOWN-ISSUES.md`, where one target printed to
34 MB. `Meta.ppExpr` hides implicit arguments and so is far tamer than the fully-explicit printing
that produced that, but the cap is cheap and the panel is a preview either way. -/
def maxExternalValue : Nat := 1200

/-- See `maxExternalValue`. -/
def externalValueString (env : Environment) (info : ConstantInfo) : IO String := do
  match info with
  | .defnInfo val => return clipTo maxExternalValue (← ppExprString env val.value)
  | .inductInfo val =>
    -- A structure or class: what it says is its fields, which live in its single constructor's
    -- telescope after the structure's own parameters.
    match val.ctors with
    | [ctor] =>
      let lines ← runCoreIO env <| Lean.Meta.MetaM.run' do
        let some ci := (← getEnv).find? ctor | return (#[] : Array String)
        Lean.Meta.forallTelescopeReducing ci.type fun xs _ =>
          (xs.extract val.numParams xs.size).mapM fun x => do
            return s!"{← x.fvarId!.getUserName} : {← Lean.Meta.ppExpr (← Lean.Meta.inferType x)}"
      return clipTo maxExternalValue (String.intercalate "\n" lines.toList)
    | _ => return ""
  | _ => return ""

/-- The most constants one upstream package may contribute before it is left unexpanded.

The budget is what lets this run without knowing which packages the reader will trust. `--trust` is a
render-time flag by design, so `collect` cannot be told which packages matter; instead every upstream
package is walked and the ones that do not fit are abandoned. Mathlib exceeds this within a few steps
and is recorded as the flat surface it always was; a small sibling like `LeanMachineLearning` — 15
declarations of surface out of `AlphaRAR` — finishes immediately and gets its internal structure
drawn. The cutoff is a legibility bound as much as a cost one: a block of 500 nodes is not a picture
anyone reads. -/
def maxExpandedPackage : Nat := 500

/-- The meaning edges of an *upstream* constant: the same rule `meaningDepsOf` applies to the
project's own declarations, restated for a constant that has no `DeclInfo`.

A theorem contributes its statement, a definition its type and the data in its value, everything else
its type and whatever its constructors and field defaults mention. -/
def upstreamMeaningDeps (env : Environment) (name : Name) (info : ConstantInfo) :
    Lean.Meta.MetaM (Array Name) := do
  match info with
  | .thmInfo _ => return LeanDeps.exprUsedConstants info.type
  | .defnInfo _ =>
    return LeanDeps.usedConstantsOf env name info (includeValue := false)
      ++ (← LeanDeps.dataValueConstants info)
  | _ => return LeanDeps.usedConstantsOf env name info (includeValue := true)

/-- What a dependency of an upstream constant should appear as: itself, or — when it is a
compiler-generated helper — whatever it in turn references.

The same treatment `LeanDeps.expandThroughInternals` gives the project's own declarations, restated
here because that one is scoped to the project. Without it an `_autoParam` (the tactic behind a
structure field's default) or a `match_1` becomes a node in the picture, and nobody wrote it.
Recursion is guarded by `seen`, so a helper referring to itself terminates. -/
partial def upstreamVisibleDeps (env : Environment) (packages : Array PackageInfo) (pkg : Name)
    (seen : Std.HashSet Name) (d : Name) : Lean.Meta.MetaM (Array Name) := do
  if !LeanDeps.isInternalName d then return #[d]
  if seen.contains d then return #[]
  let some info := env.find? d | return #[]
  let ds ← try upstreamMeaningDeps env d info catch _ => pure #[]
  let mut out : Array Name := #[]
  for e in ds do
    if e == d then continue
    match moduleNameOf env e with
    | some m =>
      if modulePackageOf packages m == some pkg then
        out := out ++ (← upstreamVisibleDeps env packages pkg (seen.insert d) e)
    | none => pure ()
  return out

/-- Closes each upstream package's surface over the package's own internal edges, up to
`maxExpandedPackage`.

Returns the intra-package edges of every constant reached, and the packages that finished inside the
budget. A package that overruns contributes nothing: its constants keep the records `externalDeclsOf`
builds for them and are drawn flat, so overrunning degrades the picture rather than breaking it. -/
def expandUpstream (env : Environment) (packages : Array PackageInfo)
    (surface : Array (Name × Name)) : IO (Std.HashMap Name (Array Name) × Array Name) := do
  runCoreIO env <| Lean.Meta.MetaM.run' do
    let mut seeds : Std.HashMap Name (Array Name) := {}
    for (c, pkg) in surface do
      seeds := seeds.insert pkg ((seeds.getD pkg #[]).push c)
    let mut edges : Std.HashMap Name (Array Name) := {}
    let mut expanded : Array Name := #[]
    for (pkg, start) in seeds.toArray.qsort (fun a b => Name.lt a.1 b.1) do
      let mut pkgEdges : Std.HashMap Name (Array Name) := {}
      let mut seen : Std.HashSet Name := {}
      let mut frontier := start
      let mut withinBudget := true
      while withinBudget && !frontier.isEmpty do
        let mut next : Array Name := #[]
        for n in frontier do
          if seen.contains n then continue
          if seen.size ≥ maxExpandedPackage then
            withinBudget := false
            break
          seen := seen.insert n
          let some info := env.find? n | continue
          let ds ← try upstreamMeaningDeps env n info catch _ => pure #[]
          -- Only edges that stay inside the package. One leaving it either points at the project,
          -- which depends on the package rather than the other way round, or at another package,
          -- whose expansion is decided on its own terms.
          let mut acc : Std.HashSet Name := {}
          for d in ds do
            if d == n then continue
            match moduleNameOf env d with
            | some m =>
              if modulePackageOf packages m == some pkg then
                for v in ← upstreamVisibleDeps env packages pkg {} d do
                  if v != n then acc := acc.insert v
            | none => pure ()
          let inPkg := acc.toArray.qsort Name.lt
          pkgEdges := pkgEdges.insert n inPkg
          for d in inPkg do
            if !seen.contains d then next := next.push d
        frontier := next
      if withinBudget then
        expanded := expanded.push pkg
        for (k, v) in pkgEdges.toArray do
          edges := edges.insert k v
    return (edges, expanded)

/-- Every constant outside the project that some declaration's *statement* names, with its package,
module, signature and docstring.

Collected so that a declaration's dependency graph can show the upstream declarations it rests on,
not merely count them — and, since these are exactly the nodes where a reader's trust has to start,
so that clicking one answers "is this the definition I think it is" without leaving the site.
Restricted to the meaning edges (`meaningDepsOf`) and to constants that resolve to a package: this is
the set that can appear as a node, and collecting all of `deps` instead would multiply it by every
proof-only reference, none of which the graph shows.

The signature is pretty-printed here rather than at render time because `build-site` has no
environment: the whole point of the phase split is that it runs on the JSON alone. -/
def externalDeclsOf (env : Environment) (packages : Array PackageInfo) (rootPrefix : Name)
    (decls : Array DeclInfo) : IO (Array ExternalDeclInfo × Array Name) := do
  let byName := decls.foldl (init := ({} : Std.HashMap Name Name)) fun acc decl =>
    (meaningDepsOf decl.kind decl.isAlias decl.deps decl.typeDeps decl.dataDeps).foldl
      (init := acc) fun acc dep =>
      if acc.contains dep then acc
      else match moduleNameOf env dep with
        | none => acc
        | some moduleName =>
          if hasPrefixName moduleName rootPrefix then acc
          else match modulePackageOf packages moduleName with
            | some pkg => acc.insert dep pkg
            | none => acc
  -- Close each package over its own internal edges before building the records, because the closure
  -- reaches constants no project statement names and those need a record too — a node with no
  -- signature and no docstring is the thing this table exists to stop.
  let (edges, expanded) ← expandUpstream env packages
    (byName.toArray.qsort fun a b => Name.lt a.1 b.1)
  let mut all := byName
  for (name, _) in edges.toArray do
    if !all.contains name then
      match moduleNameOf env name with
      | none => pure ()
      | some m =>
        match modulePackageOf packages m with
        | some pkg => all := all.insert name pkg
        | none => pure ()
  let mut out : Array ExternalDeclInfo := #[]
  for (name, pkg) in all.toArray.qsort (fun a b => Name.lt a.1 b.1) do
    let some info := env.find? name | continue
    -- A failure to pretty-print one upstream type must not lose the whole table, so it degrades to
    -- the name, which is exactly what every node showed before this existed.
    let signature ← try ppExprString env info.type catch _ => pure name.toString
    let doc ← try pure ((← findDocString? env name).getD "") catch _ => pure ""
    let value ← try externalValueString env info catch _ => pure ""
    out := out.push {
      name := name
      package := pkg
      moduleName := (moduleNameOf env name).getD pkg
      signature := signature
      value := value
      doc := doc
      deps := edges.getD name #[]
    }
  return (out, expanded)

/-- The upstream packages a single declaration's own type and body reference, with the project's own
package dropped: the one-level part of `DeclInfo.upstreamPackages`, before propagation. -/
def directUpstreamPackages (env : Environment) (packages : Array PackageInfo)
    (rootPrefix : Name) (deps : Array Name) : Array Name :=
  let acc := deps.foldl (init := ({} : Std.HashSet Name)) fun acc dep =>
    match moduleNameOf env dep with
    | none => acc
    | some moduleName =>
      if hasPrefixName moduleName rootPrefix then acc
      else match modulePackageOf packages moduleName with
        | some pkg => acc.insert pkg
        | none => acc
  acc.toArray.qsort Name.lt

/-- Collects all exposed declarations and computes their primary metadata. The dependency lists
(`deps`, `typeDeps`) come from `LeanDeps`; everything else — signature, docstring, source snippet,
kind, `sorry` status — is computed here. -/
def collectDecls (projectDir : System.FilePath) (rootPrefix : Name)
    (pkg : Lake.Package) (env : Environment) (packages : Array PackageInfo := #[]) :
    IO (Array DeclInfo) := do
  -- `withDataValueConsts` is what lets `declDeps` report `dataDeps`; without it every `dataDeps`
  -- would silently equal `deps` and the graph would be unchanged. It needs `MetaM` because deciding
  -- whether a constructor field is `Prop`-valued is a typing question.
  let depsCtx ← runCoreIO env
    (Lean.Meta.MetaM.run' (LeanDeps.Context.of env rootPrefix).withDataValueConsts)
  let declAxioms ← axiomsOfDecls env (depsCtx.constants.filterMap fun (name, _, _) =>
    if depsCtx.exposed.contains name then some name else none)
  let simpTheorems ← runCoreIO env Lean.Meta.getSimpTheorems
  let simpLemmaNames : Std.HashSet Name :=
    simpTheorems.lemmaNames.fold (fun acc origin =>
      match origin with
      | .decl declName .. => acc.insert declName
      | _ => acc) {}
  -- The project's `@[specifies]` annotations, grouped by the theorem carrying them. Reading them
  -- needs no cooperation from the target beyond depending on `LeanSpec`: the entries ride in the
  -- `.olean`s and are matched to this process's copy of the extension by name during
  -- `importModules (loadExts := true)`. A project without the dependency yields an empty array.
  let specsByTheorem : Std.HashMap Name (Array SpecLink) :=
    (LeanSpec.specEntries env).foldl (init := {}) fun acc entry =>
      let link : SpecLink := { name := entry.target, comment := entry.comment }
      acc.insert entry.theoremName ((acc.getD entry.theoremName #[]).push link)
  -- The `@[characterization]` annotations, already assembled into bundles by `LeanSpec` and keyed
  -- by the definition each claims to pin down. Incomplete bundles are kept rather than dropped: a
  -- property with no uniqueness theorem is a claim its author started and did not finish, which is
  -- worth showing as such and not worth silently rendering as a characterization.
  let charsByTarget : Std.HashMap Name (Array CharBundle) :=
    (LeanSpec.characterizations env).foldl (init := {}) fun acc c =>
      let bundle : CharBundle := {
        property := c.property
        comment := c.comment
        existence := c.existence.map (·.declName)
        uniqueness := c.uniqueness.map fun e =>
          { name := e.declName, relation := e.relation, relationHead := e.relationHead } }
      acc.insert c.target ((acc.getD c.target #[]).push bundle)
  let mut cache : LeanDeps.Cache := {}
  let mut fileLines : Std.HashMap System.FilePath (Array String) := {}
  -- Parsed once per file alongside its lines, and for the same reason: every declaration in a module
  -- asks the same question of the same source.
  let mut fileCommands : Std.HashMap System.FilePath (Array CommandKeyword) := {}
  let mut decls := #[]
  for (name, moduleName, info) in depsCtx.constants do
    if !depsCtx.exposed.contains name then
      continue
    let ranges? ← findRanges? env name
    let source? ← toSourceInfo? projectDir pkg moduleName ranges?
    let mut text? : Option String := none
    let lines ← match source? with
      | none => pure #[]
      | some src =>
        match fileLines.get? src.absPath with
        | some ls => pure ls
        | none => do
            let text ← IO.FS.readFile src.absPath
            let ls := (text.splitOn "\n").toArray
            fileLines := fileLines.insert src.absPath ls
            text? := some text
            pure ls
    -- The command this declaration's range falls inside, which is where its keyword is read from.
    let cmd? ← match source? with
      | none => pure none
      | some src => do
        let cmds ← match fileCommands.get? src.absPath with
          | some cs => pure cs
          | none => do
              let text ← match text? with
                | some t => pure t
                | none => IO.FS.readFile src.absPath
              let cs ← commandKeywordsOf env text src.absPath.toString
              fileCommands := fileCommands.insert src.absPath cs
              pure cs
        pure (commandKeywordAt? cmds src.line)
    let kind := declKindOf env info name
    let expandedSignature ← ppExprString env info.type
    -- Parsed syntax when the range lands in a command, the source text otherwise.
    let isLemma := (kind == .theorem &&
        match cmd? with
        | some c => c.isLemma
        | none => isLemmaFromSource kind source? lines)
      || isSimpsGeneratedLemma env simpLemmaNames name info
    -- Before the signature, not after: an attribute-generated declaration has no source of its own
    -- to display and falls back to the pretty-printed type, which has to be introduced by the
    -- keyword the author actually wrote or the code block says `theorem` under a card labelled
    -- "Lemma".
    let displaySignature :=
      (displaySignatureFromSource kind source? lines).getD <|
        displaySignatureFallback kind name expandedSignature (isLemma := isLemma)
    let proofText? := proofTextFromSource kind source? lines
    let isInstanceDecl := kind == .theorem &&
      match cmd? with
      | some c => c.isInstance
      | none => isInstanceFromSource kind source? lines
    let isInstanceDecl := isInstanceDecl || (kind == .theorem && isInstanceName name)
    let doc? ← findDocString? env name
    let docBlocks :=
      match doc? with
      | some doc => markdownToBlocks doc
      | none => #[]
    -- The constants this declaration rests on, recovered by `LeanDeps` (which also looks through
    -- compiler-generated helpers and recovers the notation/coercion dependencies the elaborated
    -- term drops). The reverse notation direction — a declaration whose *source* uses a notation —
    -- is handled syntactically during extraction, where the parsed syntax is available.
    let (declDeps, cache') := depsCtx.declDeps cache name info
    cache := cache'
    let axs := declAxioms.getD name #[]
    let docstringBlock? ← mkDocstringBlock? env name
    let decl : DeclInfo := {
      name := name
      moduleName := moduleName
      modulePath := modulePathOf rootPrefix moduleName
      groupKey := groupKeyOfModule rootPrefix moduleName
      kind := kind
      displaySignature := displaySignature
      expandedSignature := expandedSignature
      docBlocks := docBlocks
      docText? := doc?
      proofText? := proofText?
      source? := source?
      dependsOnSorry := axs.contains ``sorryAx
      -- `allowOpaque := true` is required, not cosmetic: `ConstantInfo.value?` returns `none` for
      -- a `.thmInfo` without it, so every theorem — the declarations that actually carry a `sorry`
      -- in their proof — reported `hasOwnSorry := false`, and `sorryChain` then found no culprit
      -- and the page blamed the gap on an upstream package.
      hasOwnSorry := info.type.hasSorry ||
        ((info.value? (allowOpaque := true)).map Expr.hasSorry).getD false
      axioms := axs
      isLemma := isLemma
      isInstanceDecl := isInstanceDecl
      isAlias := match cmd? with
        | some c => c.isAlias
        | none => isAliasFromSource source? lines
      specifies := specsByTheorem.getD name #[]
      -- Only the forward direction here; `attachCharacterizes` fills in `characterizes` on the
      -- three declarations each bundle is made of, exactly as `attachSpecifiedBy` does.
      characterizedBy := charsByTarget.getD name #[]
      -- One level here; `attachUpstreamPackages` propagates it along the project's own edges.
      -- The edges `closureDeps` picks: a theorem's *statement*, everything else's body too. A
      -- theorem's proof is not a trust dependency — the kernel checked it.
      upstreamPackages := directUpstreamPackages env packages rootPrefix
        (meaningDepsOf kind (isAliasFromSource source? lines) declDeps.deps declDeps.typeDeps
          declDeps.dataDeps)
      deps := declDeps.deps
      typeDeps := declDeps.typeDeps
      dataDeps := declDeps.dataDeps
      docstringBlock? := docstringBlock?
    }
    decls := decls.push decl
  pure decls

/-! ## Dependency-graph passes

Each of these is a thin adapter that projects `decls` onto the plain `(name, deps)` graph the
`LeanDeps` passes work on, runs the pass, and writes the result back into the corresponding
`DeclInfo` field. What varies between them is only *which* edges they follow — full `deps` for
`usedBy`, `closureDeps` for the extraction closure and `meaningDeps` for the meaning closure.
-/

/-- Adds reverse dependency links (`usedBy`) between exposed declarations, sorted by name. -/
def attachReverseDeps (decls : Array DeclInfo) : Array DeclInfo :=
  let rev := LeanDeps.reverseDeps (decls.map fun decl => (decl.name, decl.deps))
  decls.map fun decl => { decl with usedBy := (rev.getD decl.name #[]).qsort Name.lt }

/-- `closureDepsOf` for a `DeclInfo`. Drives `transDeps`, and through it extraction; also the
module-level graph, which is about what a module needs in order to build rather than about what it
means.

Not a way to "see through proofs", despite being the wider of the two rules: it widens over
`meaningDeps` for *definitions* only, and for a non-alias theorem both are `typeDeps`. Anything that
has to follow a theorem's proof — the `sorry` chain is the one such caller — must take `decl.deps`
directly. -/
def closureDeps (decl : DeclInfo) : Array Name :=
  closureDepsOf decl.kind decl.isAlias decl.deps decl.typeDeps

/-- `meaningDepsOf` for a `DeclInfo`: what the declaration claims and what that claim rests on, with
every proof dropped.

This is what the site follows nearly everywhere — the dependency graph and its node set
(`dataTransDeps`), the upstream-trust analysis, the audit closure and its reading queues, and the
revision diff's meaning propagation. All of them ask a version of "what must I accept in order to
believe this", and the answer never includes a lemma some proof merely called. -/
def meaningDeps (decl : DeclInfo) : Array Name :=
  meaningDepsOf decl.kind decl.isAlias decl.deps decl.typeDeps decl.dataDeps

/-! ## Integrity of the collected data

`Proofs/Deps.lean` proves these properties of the *functions* that build the closures —
`transitiveDeps_closed`, `topologicalClosure_nodup`, `mem_topologicalClosure_of_mem_start`. What the
site renders is not those functions' output but a `CollectedData` that has been through `toJson`,
`intern`, a file, `Json.parse`, `resolve` and `fromJson?`. The round trip across that boundary is
*not* proved — see `Proofs/Collect.lean` for why it is out of reach in this toolchain — so a theorem
about the producer establishes nothing about the value the renderer holds.

These checks close that gap from the other end. They restate the proved properties as assertions on
the decoded data, so that a violation — from a corrupted file, a truncated write, a version skew, or
a future change that stops routing a closure through `LeanDeps.transitiveDeps` — is reported rather
than rendered.

The site is a trust instrument; rendering a closure that is quietly wrong is worse than failing.
-/

/-- How many violations to list before summarizing. A corrupt file tends to fail every check at
once, and a wall of near-identical lines buries the useful first one. -/
def maxReportedViolations : Nat := 12

/-- Internal consistency checks on decoded collected data, as reader-facing messages. Empty when
the data satisfies everything `Proofs/Deps.lean` proves of the functions that produced it.

Each check names the theorem it restates, so a failure points at whether the *property* is wrong or
the *data* is. -/
def CollectedData.integrityViolations (data : CollectedData) : Array String := Id.run do
  let byName : Std.HashMap Name DeclInfo :=
    data.decls.foldl (fun m d => m.insert d.name d) {}
  let mut out : Array String := #[]
  for decl in data.decls do
    for (label, closure, direct) in
        #[("transDeps", decl.transDeps, closureDeps decl),
          ("dataTransDeps", decl.dataTransDeps, meaningDeps decl)] do
      let inClosure : Std.HashSet Name := closure.foldl (fun s n => s.insert n) {}
      -- `transitiveDeps` filters the declaration itself out of its own closure.
      if closure.contains decl.name then
        out := out.push s!"{decl.name}: {label} contains the declaration itself"
      -- `topologicalClosure_nodup`.
      if inClosure.size != closure.size then
        out := out.push s!"{decl.name}: {label} has repeated entries           ({closure.size} entries, {inClosure.size} distinct)"
      -- `mem_topologicalClosure_of_mem_start`: the closure contains what it was seeded with.
      for d in direct do
        unless d == decl.name || inClosure.contains d do
          out := out.push s!"{decl.name}: {label} omits its direct dependency {d}"
      -- `transitiveDeps_closed`: the closure is closed under taking dependencies. Only project
      -- declarations have recorded edges; an upstream constant is a leaf here.
      for y in closure do
        if let some ydecl := byName[y]? then
          let yDirect := if label == "transDeps" then closureDeps ydecl else meaningDeps ydecl
          for z in yDirect do
            unless z == decl.name || inClosure.contains z do
              out := out.push s!"{decl.name}: {label} is not closed — contains {y},                 which depends on {z}, which is absent"
  return out

/-- Formats `integrityViolations` for a command-line error, truncated to `maxReportedViolations`. -/
def CollectedData.integrityReport (data : CollectedData) : Option String :=
  let vs := data.integrityViolations
  if vs.isEmpty then none
  else
    let shown := vs.extract 0 maxReportedViolations
    let more := if vs.size > maxReportedViolations then
        s!"\n  … and {vs.size - maxReportedViolations} more" else ""
    some <| "collected data failed its own consistency checks:\n  "
      ++ String.intercalate "\n  " shown.toList ++ more

/-- Adds the reverse of the `@[specifies]` links: each definition learns which of the exposed
theorems its author declared to be part of its specification.

Kept in declaration order rather than sorted by name, unlike `attachReverseDeps` — a specification
is a short, deliberately ordered list, and the order its author wrote it in is the order it reads
best in. A link whose target is not an exposed declaration (a Mathlib definition, say) simply has
nowhere to land here; it stays visible on the theorem's own `specifies`. -/
def attachSpecifiedBy (decls : Array DeclInfo) : Array DeclInfo :=
  let rev : Std.HashMap Name (Array SpecLink) :=
    decls.foldl (init := {}) fun acc decl =>
      decl.specifies.foldl (init := acc) fun acc link =>
        let back : SpecLink := { name := decl.name, comment := link.comment }
        acc.insert link.name ((acc.getD link.name #[]).push back)
  decls.map fun decl => { decl with specifiedBy := rev.getD decl.name #[] }

/-- Adds the reverse of the `@[characterization]` links: each of the three declarations a bundle is
made of learns which definition it helps pin down, and in what role.

The counterpart of `attachSpecifiedBy`, and needed for the same reason in the other direction. A
reader who lands on `IsEntropy.unique` sees a lemma about a predicate; what they are missing is that
it is the half of a claim about `entropy`, which nothing in the statement says. A part whose bundle
names a definition outside the project has nowhere to land in `characterizedBy`, so it never reaches
this function — the link is only ever built from bundles already attached to an exposed
definition. -/
def attachCharacterizes (decls : Array DeclInfo) : Array DeclInfo :=
  let rev : Std.HashMap Name (Array CharPartLink) :=
    decls.foldl (init := {}) fun acc decl =>
      decl.characterizedBy.foldl (init := acc) fun acc bundle =>
        let add (acc : Std.HashMap Name (Array CharPartLink)) (part : Name) (role : String) :=
          let link : CharPartLink := { target := decl.name, property := bundle.property, role }
          acc.insert part ((acc.getD part #[]).push link)
        let acc := add acc bundle.property "property"
        let acc := bundle.existence.foldl (fun acc n => add acc n "existence") acc
        bundle.uniqueness.foldl (fun acc u => add acc u.name "uniqueness") acc
  decls.map fun decl => { decl with characterizes := rev.getD decl.name #[] }

/-! ## Semantic hashes

Read from a JSONL file produced by [`semantic_hash export`](https://github.com/mathlib-initiative/semantic_hash),
one `{"name": ..., "hash": ..., "proofIrrelHash": ...}` object per line. That tool is run separately,
against the same project, and is not a build dependency of this one — which is deliberate. It
enforces a toolchain match against the project it reads, exactly as this tool does, and taking it as
a Lake dependency would mean a *third* toolchain that also has to line up. A file on disk has no
such constraint, and keeps the phase boundary the pipeline is built on: everything that needs the
environment produces data, and everything downstream is a pure function of it.

The hashes matter to Referee for one reason. `expandedSignature` is a *pretty-printed* elaborated
type, and a toolchain upgrade can change how every type in a library prints at once — which turns
the revision diff into a page telling the reader to re-audit everything. A structural hash of the
`Expr` cannot do that. See `Referee.Diff` for what it is used for and where it is not trusted. -/

/-- Renders a 64-bit hash as fixed-width hex.

Fixed width, and base 16, so the result reads as an identifier rather than as a number someone might
compare with `<` — these are compared for equality and for nothing else. -/
def hex16 (n : UInt64) : String :=
  let hexDigit (d : Nat) : Char :=
    if d < 10 then Char.ofNat (d + '0'.toNat) else Char.ofNat (d - 10 + 'a'.toNat)
  let rec go (n : UInt64) (fuel : Nat) (acc : String) : String :=
    match fuel with
    | 0 => acc
    | fuel + 1 => go (n / 16) fuel (String.singleton (hexDigit (n % 16).toNat) ++ acc)
  go n 16 ""

/-- Reads one hash field of a `semantic_hash` JSONL record.

Accepts a JSON string or a JSON number. Lean serializes `UInt64` as a *decimal string*, since
JavaScript cannot hold 64 bits in a number, so the string form is what the tool actually writes
today; the numeric branch is there so that a change of heart upstream degrades to nothing rather
than to a silently empty hash table. Either way the value is canonicalized to `hex16`, so a file
written under either convention compares equal to one written under the other. -/
def parseHashField? (j : Json) : Option String :=
  let n? : Option Nat :=
    match j with
    | .str s => s.toNat?
    | .num _ => j.getNat?.toOption
    | _ => none
  n?.map fun n => hex16 (UInt64.ofNat n)

/-- Declaration ↦ (`hash`, `proofIrrelHash`), read from a `semantic_hash export` JSONL file.

Lines that do not parse are skipped rather than fatal, and the caller reports the coverage it got.
A hash file is an *optimization of the comparison key*: a partial one costs a partial upgrade, and
failing the whole collection over a malformed line would trade a good outcome for no outcome. -/
def readSemanticHashes (path : System.FilePath) : IO (Std.HashMap Name (String × String)) := do
  let contents ← IO.FS.readFile path
  let mut out : Std.HashMap Name (String × String) := {}
  for line in contents.splitOn "\n" do
    -- No trimming: `Json.parse` already tolerates surrounding whitespace, and a line that is
    -- nothing but whitespace simply fails to parse and is skipped with the rest.
    if line.isEmpty then continue
    let .ok json := Json.parse line | continue
    let .ok nameStr := json.getObjValAs? String "name" | continue
    let some hash := (json.getObjVal? "hash").toOption.bind parseHashField? | continue
    let some proofIrrel :=
      (json.getObjVal? "proofIrrelHash").toOption.bind parseHashField? | continue
    let name := nameStr.toName
    if name.isAnonymous then continue
    out := out.insert name (hash, proofIrrel)
  return out

/-- Attaches the semantic hashes to the declarations they name.

A declaration the export does not mention keeps `none` and is compared as text, so this never has
to be complete to be useful. -/
def attachSemanticHashes (hashes : Std.HashMap Name (String × String))
    (decls : Array DeclInfo) : Array DeclInfo :=
  decls.map fun decl =>
    match hashes.get? decl.name with
    | some (hash, proofIrrel) =>
      { decl with semanticHash? := some hash, proofIrrelHash? := some proofIrrel }
    | none => decl

/-- Propagates the directly-referenced upstream packages along the project's own dependency edges,
so that each declaration's `upstreamPackages` covers everything its project-level closure touches.

Follows `meaningDeps`, the same edges the rest of the trust analysis follows, for the reason recorded
there: a proof is not something a reader has to trust further, because the kernel checked it. What a
reader must take on faith from upstream is a *definition* their statements are about — so a package
reached only by a lemma that some proof called is not a package this declaration rests on, whether
that proof is a theorem's or one bundled into a definition's value.

Reuses `LeanDeps.transitiveDeps` for the closure rather than iterating a fixpoint: the closure is
over 784-ish project declarations, not over the environment, so it is cheap and already written. -/
def attachUpstreamPackages (decls : Array DeclInfo) : Array DeclInfo :=
  let depsMap : Std.HashMap Name (Array Name) :=
    decls.foldl (fun acc decl => acc.insert decl.name (meaningDeps decl)) {}
  let ownPkgs : Std.HashMap Name (Array Name) :=
    decls.foldl (fun acc decl => acc.insert decl.name decl.upstreamPackages) {}
  decls.map fun decl =>
    let closure := #[decl.name] ++ LeanDeps.transitiveDeps depsMap decl.name
    let acc := closure.foldl (init := ({} : Std.HashSet Name)) fun acc name =>
      (ownPkgs.getD name #[]).foldl (init := acc) (·.insert ·)
    { decl with upstreamPackages := acc.toArray.qsort Name.lt }

/-- Adds the transitive closure of `closureDeps` to each declaration as `transDeps`, topologically
ordered so that every dependency precedes the declarations that use it (suitable for emitting a
minimal standalone Lean file).

This is the *extraction* closure and is deliberately wider than what the site reports: see
`dataTransDeps` for the meaning closure the reader is shown. -/
def attachTransitiveDeps (decls : Array DeclInfo) : Array DeclInfo :=
  let depsMap : Std.HashMap Name (Array Name) :=
    decls.foldl (fun acc decl => acc.insert decl.name (closureDeps decl)) {}
  decls.map fun decl => { decl with transDeps := LeanDeps.transitiveDeps depsMap decl.name }

/-- Adds the transitive closure of `meaningDeps` as `dataTransDeps`, exactly as
`attachTransitiveDeps` does for `closureDeps`.

This is the node set of a declaration's dependency graph: the declarations its *meaning* rests on.
Computed here rather than at render time so that the graph and the closure listings cannot disagree
about what counts, which is the same reason `transDeps` is precomputed. -/
def attachDataTransitiveDeps (decls : Array DeclInfo) : Array DeclInfo :=
  let depsMap : Std.HashMap Name (Array Name) :=
    decls.foldl (fun acc decl => acc.insert decl.name (meaningDeps decl)) {}
  decls.map fun decl => { decl with dataTransDeps := LeanDeps.transitiveDeps depsMap decl.name }

end Referee
