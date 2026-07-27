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

@[expose] public section

/-!
# Collecting the exposed declarations of a project

Walks a compiled project's environment and builds one `DeclInfo` per exposed declaration:
signature, docstring, source location and snippet, kind, and dependency lists.

The dependency analysis itself lives in `LeanDeps` — a standalone module that knows nothing about
this tool's output. This file only decides *which* dependency edges the exposition follows
(`graphDeps`: type-only for theorems) and attaches the results to `DeclInfo`.
-/

open Lake
open Lean
open Lean.Meta
open Verso.Doc
open Verso.Genre
open Manual

namespace LMLExposition

open Verso.Output Html
open LeanDeps

/-- CLI options used to configure exposition generation. Shared across the `collect`,
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
  dependsOnSorry : Bool := false
deriving Repr, ToJson, FromJson, Inhabited

/-- Data container for DeclIndexData. -/
structure DeclIndexData where
  entries : Array DeclIndexEntry
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
  deps : Array Name
  typeDeps : Array Name := #[]
  usedBy : Array Name := #[]
  transDeps : Array Name := #[]
  docstringBlock? : Option (Block Manual) := none
deriving Repr, ToJson, FromJson

/-- The kind label to show for this declaration; see `displayKindLabel`. -/
def DeclInfo.displayKind (decl : DeclInfo) : String :=
  displayKindLabel decl.kind.label decl.isLemma decl.isInstanceDecl

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
- 3: adds `DeclInfo.docText?` -/
def collectedDataVersion : Nat := 3

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
deriving ToJson, FromJson

/-- Command-line usage text shown for invalid arguments. -/
def usage : String :=
  String.intercalate "\n" [
    "Usage: lake exe exposition [SUBCOMMAND] [options]",
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
  let coreCtx : Core.Context := { fileName := "<exposition>", fileMap := default, options }
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

/-- Strips InlineAttributePrefix. -/
def stripInlineAttributePrefix (line : String) : String :=
  let trimmed := (String.trimAscii line).toString
  if !trimmed.startsWith "@[" then
    trimmed
  else
    match trimmed.splitOn "]" with
    | _attr :: rest@(_ :: _) =>
        (String.trimAscii (String.intercalate "]" rest)).toString
    | _ => ""

/-- Drops LeadingDecorations. -/
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
        let remainder := stripInlineAttributePrefix line
        if remainder.isEmpty then
          dropLeadingDecorations rest
        else
          remainder :: rest
      else
        line :: rest

/-- Helper for cleanDeclSnippet. -/
def cleanDeclSnippet (snippet : String) : String :=
  (String.trimAscii (String.intercalate "\n" (dropLeadingDecorations (snippet.splitOn "\n")))).toString

/-- Helper for headBeforeAssignment. -/
def headBeforeAssignment (snippet : String) : String :=
  match snippet.splitOn ":=" with
  | first :: _ => (String.trimAscii first).toString
  | [] => (String.trimAscii snippet).toString

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
      match snippet.splitOn ":=" with
      | _prefix :: rest@(_ :: _) =>
          some <| (String.trimAscii (String.intercalate ":=" rest)).toString
      | _ =>
          some snippet
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
    s!"{repoUrl}/issues/new?title={title}&body={body}&labels=exposition-review"

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
    { fileName := "<exposition>", fileMap := default, options := {}, currNamespace := .anonymous, openDecls := [] }
    { env := env, ngen := { namePrefix := `_exposition } }

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

/-- Collects all exposed declarations and computes their primary metadata. The dependency lists
(`deps`, `typeDeps`) come from `LeanDeps`; everything else — signature, docstring, source snippet,
kind, `sorry` status — is computed here. -/
def collectDecls (projectDir : System.FilePath) (rootPrefix : Name)
    (pkg : Lake.Package) (env : Environment) : IO (Array DeclInfo) := do
  let depsCtx := LeanDeps.Context.of env rootPrefix
  let declAxioms ← axiomsOfDecls env (depsCtx.constants.filterMap fun (name, _, _) =>
    if depsCtx.exposed.contains name then some name else none)
  let simpTheorems ← runCoreIO env Lean.Meta.getSimpTheorems
  let simpLemmaNames : Std.HashSet Name :=
    simpTheorems.lemmaNames.fold (fun acc origin =>
      match origin with
      | .decl declName .. => acc.insert declName
      | _ => acc) {}
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
  if decl.kind == .theorem && !decl.isAlias then decl.typeDeps else decl.deps

/-- Adds the transitive closure of `deps` to each declaration as `transDeps`, topologically ordered
so that every dependency precedes the declarations that use it (suitable for emitting a minimal
standalone Lean file). See `graphDeps` for which dependencies are followed. -/
def attachTransitiveDeps (decls : Array DeclInfo) : Array DeclInfo :=
  let depsMap : Std.HashMap Name (Array Name) :=
    decls.foldl (fun acc decl => acc.insert decl.name (graphDeps decl)) {}
  decls.map fun decl => { decl with transDeps := LeanDeps.transitiveDeps depsMap decl.name }

end LMLExposition
