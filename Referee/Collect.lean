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

@[expose] public section

/-!
# Collecting the exposed declarations of a project

Walks a compiled project's environment and builds one `DeclInfo` per exposed declaration:
signature, docstring, source location and snippet, kind, and dependency lists.

The dependency analysis itself lives in `LeanDeps` — a standalone module that knows nothing about
this tool's output. This file only decides *which* dependency edges Referee follows
(`graphDeps`: type-only for theorems) and attaches the results to `DeclInfo`.
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
  /-- An earlier `collect` output to diff the current one against (`--baseline`).

  A render-time flag for the same reason `--trust` is one: the comparison is a pure function of the
  two JSON files, so a reader can ask "what changed since v0.2" without re-importing anything. With
  none given, the site says nothing about revisions at all. -/
  baselinePath : Option String := none
  /-- What to call the baseline on the page (`--baseline-label`). Defaults to the file name. -/
  baselineLabel : Option String := none
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
deriving Repr, ToJson, FromJson, Inhabited

/-- Data container for BrowseData. -/
structure BrowseData where
  rows : Array BrowseRow
deriving Repr, ToJson, FromJson, Inhabited

/-- Data container for DetailsData. -/
structure DetailsData where
  summary : String
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
  /-- The upstream packages this declaration *directly* references, after `attachUpstreamPackages`
  has propagated them along the project's own dependency edges.

  "Directly" is the important word: these are the packages some constant of the declaration's
  project-level closure names, not the full set it rests on. The site closes them over the Lake
  dependency graph to get that — see the note on upstream packages above for why the two agree.

  Follows `graphDeps`: a theorem contributes what its *statement* mentions, not what its proof
  calls. An upstream proof is not a trust dependency — the kernel rechecked it, and anything left
  unproved in it surfaces as a `sorry` or an extra axiom, both of which `axioms` already reports
  transitively. What cannot be checked for you is an upstream *definition* your statement is about. -/
  upstreamPackages : Array Name := #[]
  deps : Array Name
  typeDeps : Array Name := #[]
  usedBy : Array Name := #[]
  transDeps : Array Name := #[]
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

The same rule `trustDepsOf` applies to dependency edges, applied here across revisions instead:
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
record, one package up. That is why the edges followed here are `graphDeps`: a theorem contributes
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

/-- Format version of `CollectedData`. Bump whenever `DeclInfo` or `CollectedData` gains or
changes a field, so that `build-site` fails with an actionable message rather than a field-level
decode error when handed a JSON file written by an older `collect`.

- 1: initial
- 2: adds `DeclInfo.hasOwnSorry` and `DeclInfo.axioms`
- 3: adds `DeclInfo.docText?`
- 4: adds `DeclInfo.specifies` and `DeclInfo.specifiedBy`
- 5: adds `CollectedData.packages` and `DeclInfo.upstreamPackages` -/
def collectedDataVersion : Nat := 5

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
  /-- Upstream constant ↦ its package, for the constants project statements name. Lets a dependency
  graph draw the upstream declarations a statement rests on. See `externalPackageMap`. -/
  externalPackages : Array (Name × Name) := #[]
deriving ToJson, FromJson

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
    "  --baseline PATH      An earlier `collect` output to compare against. Adds a Changes page,",
    "                       a badge on every declaration, and a Browse column saying what a",
    "                       reader of that revision has to read again. Omit it and the site says",
    "                       nothing about revisions",
    "  --baseline-label S   What to call the baseline on the page (default: its file name)",
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
  | "--baseline" :: path :: rest => do
      let cfg ← parseArgs rest
      pure { cfg with baselinePath := some path }
  | "--baseline-label" :: label :: rest => do
      let cfg ← parseArgs rest
      pure { cfg with baselineLabel := some label }
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

/-- Helper for mkInlineText. -/
def mkInlineText (s : String) : Inline Manual :=
  .text s

/-- Helper for mkCodeLink. -/
def mkCodeLink (link : LinkInfo) : Inline Manual :=
  match link.href? with
  | some href => .link #[.code link.label] href
  | none => .code link.label

/-- Helper for joinInlines. -/
def joinInlines (xs : List (Array (Inline Manual))) (sep : Array (Inline Manual)) : Array (Inline Manual) :=
  match xs with
  | [] => #[]
  | x :: rest => rest.foldl (fun acc item => acc ++ sep ++ item) x

/-- Helper for depParagraph. -/
def depParagraph (label : String) (links : Array LinkInfo) : Option (Block Manual) :=
  if links.isEmpty then
    none
  else
    let entries := links.toList.map fun link => #[mkCodeLink link]
    some <| .para <|
      #[.bold #[.text s!"{label}: "]] ++
      joinInlines entries #[.text " · "]

/-- Helper for depListBlock. -/
def depListBlock (links : Array LinkInfo) : Option (Block Manual) :=
  if links.isEmpty then
    none
  else
    let items := links.map fun link => Verso.Doc.ListItem.mk #[.para #[mkCodeLink link]]
    some <| .ul items

/-- Helper for codeListParagraph. -/
def codeListParagraph (label : String) (items : Array String) : Option (Block Manual) :=
  if items.isEmpty then
    none
  else
    let entries := items.toList.map fun item => #[.code item]
    some <| .para <|
      #[.bold #[.text s!"{label}: "]] ++
      joinInlines entries #[.text " · "]

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

/-- Helper for displaySignatureFallback. -/
def displaySignatureFallback (kind : DeclKind) (name : Name) (expandedSignature : String) : String :=
  s!"{declKeyword kind} {name.getString!} : {expandedSignature}"

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

/-- True if the cleaned source snippet for a `theorem`-kind declaration starts with the `lemma`
keyword rather than `theorem`. -/
def isLemmaFromSource (kind : DeclKind) (src? : Option SourceInfo) (lines : Array String) : Bool :=
  if kind != .theorem then
    false
  else match src? with
    | none => false
    | some src => (cleanDeclSnippet (sliceSourceSnippet lines src)).startsWith "lemma "

/-- True if the cleaned source snippet for a `theorem`-kind declaration starts with the
`instance` keyword (e.g. a `Prop`-valued instance whose `@[instance]` attribute was not picked
up by `declKindOf`). -/
def isInstanceFromSource (kind : DeclKind) (src? : Option SourceInfo) (lines : Array String) : Bool :=
  if kind != .theorem then
    false
  else match src? with
    | none => false
    | some src => (cleanDeclSnippet (sliceSourceSnippet lines src)).startsWith "instance "

/-- True if the declaration's source snippet starts with the `alias` keyword. Such declarations are
emitted verbatim (`alias … := target`), so their dependency closure must follow value dependencies. -/
def isAliasFromSource (src? : Option SourceInfo) (lines : Array String) : Bool :=
  match src? with
  | none => false
  | some src => (cleanDeclSnippet (sliceSourceSnippet lines src)).startsWith "alias "

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

/-- Builds a repository source link for a declaration location. -/
def sourceUrlOf (repoUrl? : Option String) (source? : Option SourceInfo) : Option String :=
  match repoUrl?, source? with
  | some repoUrl, some src => some s!"{repoUrl}/blob/main/{src.relPath}#L{src.line}"
  | _, _ => none

/-- Computes repository FileUrlOf. -/
def repoFileUrlOf (repoUrl? : Option String) (relPath : String) : Option String :=
  repoUrl?.map fun repoUrl => s!"{repoUrl}/blob/main/{relPath}"

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
every consumer of `deps`/`typeDeps` (graph edges, "Type/Body uses" links, the extraction closure)
already discards anything that isn't itself an exposed project declaration, and a name needing
this escape hatch is never one (`shouldExpose` already excludes internal/auto-generated names from
being exposed), so this can only drop names that were already inert. -/
def dropUnsafeDeps (decls : Array DeclInfo) : Array DeclInfo :=
  decls.map fun d => { d with
    deps := d.deps.filter isJsonSafeName
    typeDeps := d.typeDeps.filter isJsonSafeName
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

/-- The trust-relevant dependency edges of a declaration: the ones `graphDeps` picks, computed from
the raw `LeanDeps` result before a `DeclInfo` exists to ask. -/
def trustDepsOf (kind : DeclKind) (isAlias : Bool) (deps typeDeps : Array Name) : Array Name :=
  if kind == .theorem && !isAlias then typeDeps else deps

/-- Every constant outside the project that some declaration's *statement* names, paired with the
package it comes from.

Collected so that a declaration's dependency graph can show the upstream declarations it rests on,
not merely count them. Restricted to the trust-relevant edges (`trustDepsOf`) and to constants that
resolve to a package: this is the set that can appear as a node, and collecting all of `deps` instead
would multiply it by every proof-only reference, none of which the graph shows. -/
def externalPackageMap (env : Environment) (packages : Array PackageInfo) (rootPrefix : Name)
    (decls : Array DeclInfo) : Array (Name × Name) :=
  let acc := decls.foldl (init := ({} : Std.HashMap Name Name)) fun acc decl =>
    (trustDepsOf decl.kind decl.isAlias decl.deps decl.typeDeps).foldl (init := acc) fun acc dep =>
      if acc.contains dep then acc
      else match moduleNameOf env dep with
        | none => acc
        | some moduleName =>
          if hasPrefixName moduleName rootPrefix then acc
          else match modulePackageOf packages moduleName with
            | some pkg => acc.insert dep pkg
            | none => acc
  acc.toArray.qsort fun a b => Name.lt a.1 b.1

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
  let depsCtx := LeanDeps.Context.of env rootPrefix
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
  let mut cache : LeanDeps.Cache := {}
  let mut fileLines : Std.HashMap System.FilePath (Array String) := {}
  let mut decls := #[]
  for (name, moduleName, info) in depsCtx.constants do
    if !depsCtx.exposed.contains name then
      continue
    let ranges? ← findRanges? env name
    let source? ← toSourceInfo? projectDir pkg moduleName ranges?
    let lines ← match source? with
      | none => pure #[]
      | some src =>
        match fileLines.get? src.absPath with
        | some ls => pure ls
        | none => do
            let text ← IO.FS.readFile src.absPath
            let ls := (text.splitOn "\n").toArray
            fileLines := fileLines.insert src.absPath ls
            pure ls
    let kind := declKindOf env info name
    let expandedSignature ← ppExprString env info.type
    let displaySignature :=
      (displaySignatureFromSource kind source? lines).getD <|
        displaySignatureFallback kind name expandedSignature
    let proofText? := proofTextFromSource kind source? lines
    let isLemma := isLemmaFromSource kind source? lines
      || isSimpsGeneratedLemma env simpLemmaNames name info
    let isInstanceDecl := isInstanceFromSource kind source? lines
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
      hasOwnSorry := info.type.hasSorry || (info.value?.map Expr.hasSorry).getD false
      axioms := axs
      isLemma := isLemma
      isInstanceDecl := isInstanceDecl
      isAlias := isAliasFromSource source? lines
      specifies := specsByTheorem.getD name #[]
      -- One level here; `attachUpstreamPackages` propagates it along the project's own edges.
      -- The edges `graphDeps` picks: a theorem's *statement*, everything else's body too. A
      -- theorem's proof is not a trust dependency — the kernel checked it.
      upstreamPackages := directUpstreamPackages env packages rootPrefix
        (trustDepsOf kind (isAliasFromSource source? lines) declDeps.deps declDeps.typeDeps)
      deps := declDeps.deps
      typeDeps := declDeps.typeDeps
      docstringBlock? := docstringBlock?
    }
    decls := decls.push decl
  pure decls

/-! ## Dependency-graph passes

Each of these is a thin adapter that projects `decls` onto the plain `(name, deps)` graph the
`LeanDeps` passes work on, runs the pass, and writes the result back into the corresponding
`DeclInfo` field. What varies between them is only *which* edges they follow — full `deps` for
`usedBy`, `graphDeps` for the transitive closure.
-/

/-- Adds reverse dependency links (`usedBy`) between exposed declarations, sorted by name. -/
def attachReverseDeps (decls : Array DeclInfo) : Array DeclInfo :=
  let rev := LeanDeps.reverseDeps (decls.map fun decl => (decl.name, decl.deps))
  decls.map fun decl => { decl with usedBy := (rev.getD decl.name #[]).qsort Name.lt }

/-- The dependency set a declaration "counts" for graph/closure purposes: only `typeDeps` for
theorems (their proofs are not part of what a reader must trust further) and `deps` (type + body)
for everything else. An `alias`, though a theorem, keeps its body verbatim during extraction, so it
follows `deps` too. Shared by `attachTransitiveDeps` (the declaration detail page) and the
dependency graph, so both agree on what counts as a dependency. -/
def graphDeps (decl : DeclInfo) : Array Name :=
  trustDepsOf decl.kind decl.isAlias decl.deps decl.typeDeps

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

/-- Propagates the directly-referenced upstream packages along the project's own dependency edges,
so that each declaration's `upstreamPackages` covers everything its project-level closure touches.

Follows `graphDeps`, the same edges the rest of the site follows, for the reason recorded there: a
theorem's proof is not something a reader has to trust further, because the kernel checked it. What
a reader must take on faith from upstream is a *definition* appearing in a statement — and for a
definition, its body is part of its meaning, which is why `graphDeps` keeps body edges for
everything that is not a theorem.

Reuses `LeanDeps.transitiveDeps` for the closure rather than iterating a fixpoint: the closure is
over 784-ish project declarations, not over the environment, so it is cheap and already written. -/
def attachUpstreamPackages (decls : Array DeclInfo) : Array DeclInfo :=
  let depsMap : Std.HashMap Name (Array Name) :=
    decls.foldl (fun acc decl => acc.insert decl.name (graphDeps decl)) {}
  let ownPkgs : Std.HashMap Name (Array Name) :=
    decls.foldl (fun acc decl => acc.insert decl.name decl.upstreamPackages) {}
  decls.map fun decl =>
    let closure := #[decl.name] ++ LeanDeps.transitiveDeps depsMap decl.name
    let acc := closure.foldl (init := ({} : Std.HashSet Name)) fun acc name =>
      (ownPkgs.getD name #[]).foldl (init := acc) (·.insert ·)
    { decl with upstreamPackages := acc.toArray.qsort Name.lt }

/-- Adds the transitive closure of `deps` to each declaration as `transDeps`, topologically ordered
so that every dependency precedes the declarations that use it (suitable for emitting a minimal
standalone Lean file). See `graphDeps` for which dependencies are followed. -/
def attachTransitiveDeps (decls : Array DeclInfo) : Array DeclInfo :=
  let depsMap : Std.HashMap Name (Array Name) :=
    decls.foldl (fun acc decl => acc.insert decl.name (graphDeps decl)) {}
  decls.map fun decl => { decl with transDeps := LeanDeps.transitiveDeps depsMap decl.name }

end Referee
