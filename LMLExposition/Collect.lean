import Lean
import Lean.DeclarationRange
import Lean.Meta.Instances
import Lean.Util.Sorry
import Lake.CLI.Main
import Lake.Load.Workspace
import MD4Lean
import VersoManual
import VersoManual.Markdown

open Lake
open Lean
open Lean.Meta
open Verso.Doc
open Verso.Genre
open Manual

namespace LMLExposition

open Verso.Output Html

/-- CLI options used to configure exposition generation. -/
structure Cli where
  rootPrefix : Option Name := none
  repoUrl : Option String := none
  siteUrl : Option String := none
  siteTitle : Option String := none
  outputDir : Option String := none
  excludeLibs : Array Name := #[]
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
  detailsUrl? : Option String := none
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
  proofText? : Option String
  source? : Option SourceInfo
  hasSorry : Bool
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
  dependsOnSorry : Bool := false
  deps : Array Name
  typeDeps : Array Name := #[]
  usedBy : Array Name := #[]
  transDeps : Array Name := #[]
  docstringBlock? : Option (Block Manual) := none
deriving Repr

/-- Exposed declarations grouped by Lean module. -/
structure ModuleInfo where
  name : Name
  path : String
  groupKey : String
  decls : Array DeclInfo
  docBlocks : Array (Block Manual) := #[]
deriving Repr

/-- Modules grouped by top-level chapter key. -/
structure GroupInfo where
  key : String
  modules : Array ModuleInfo
deriving Repr

/-- Data container for MarkdownSection. -/
structure MarkdownSection where
  title : String
  body : String
deriving Repr

/-- Command-line usage text shown for invalid arguments. -/
def usage : String :=
  String.intercalate "\n" [
    "Usage: lake exe exposition [options]",
    "",
    "Options:",
    "  --root PREFIX        Root module prefix to expose (default: first root library)",
    "  --repo-url URL       GitHub repo URL used for issue/source links",
    "  --site-url URL       Deployed site base URL, used to link the minimal Lean files into the",
    "                       live.lean-lang.org web editor",
    "  --title TITLE        Site title override",
    "  --output DIR         Output directory passed to Verso",
    "  --exclude-lib NAME   Exclude a root library when importing the target project",
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
  | flag :: _ =>
      .error s!"Unknown or incomplete option: {flag}\n\n{usage}"

/-- True if `s` is `pfx` followed by a non-empty sequence of digits, the naming convention used
by the compiler for auto-generated declarations like `match_1`, `eq_2`, `hcongr_11`. -/
def isPrefixWithDigitSuffix (pfx s : String) : Bool :=
  s.startsWith pfx &&
    let rest := s.drop pfx.length
    !rest.isEmpty && rest.toString.toList.all Char.isDigit

/-- Checks whether AuxComponent. -/
def isAuxComponent (s : String) : Bool :=
  s.startsWith "_"
    || isPrefixWithDigitSuffix "match_" s
    || isPrefixWithDigitSuffix "eq_" s || s == "eq_def" || s == "eq_unfold"
    || isPrefixWithDigitSuffix "hcongr_" s

/-- Checks whether InternalName. Note that `mk` is intentionally *not* listed: a name ending in `mk`
is the auto-generated structure constructor only when the environment says so (a `ctorInfo`), which
`shouldExpose` checks separately. A user declaration named `Foo.mk` (e.g. when a structure's real
constructor was renamed to free up `mk`) must not be hidden. -/
partial def isInternalName : Name → Bool
  | .anonymous => false
  | .num p _ => isInternalName p
  | .str p s =>
      isAuxComponent s
      || s ∈ ["brecOn", "below", "casesOn", "noConfusion", "noConfusionType",
              "recOn", "rec", "ind", "sizeOf_spec", "inject", "injEq",
              "ctorIdx", "ext_iff", "congr_simp"]
      || isInternalName p

/-- Checks whether PrefixName. -/
def hasPrefixName (n prefixName : Name) : Bool :=
  n == prefixName || match n with
    | .str p _ => hasPrefixName p prefixName
    | .num p _ => hasPrefixName p prefixName
    | .anonymous => false

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

/-- Builds the same `Block.docstring` value that `{docstring name}` would produce inside
a `#doc` page, by directly invoking Verso's signature/declaration-type computation. Returns
`none` if this fails for the given declaration (e.g. unsupported declaration shapes).

The pretty-printing context opens the declaration's own namespace and all of its ancestors, so
that `scoped` notation declared in those namespaces (e.g. order notation for a structure defined
there) is used instead of falling back to raw instance/projection names. -/
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

/-- Computes module NameOf. -/
def moduleNameOf (env : Environment) (name : Name) : Option Name := do
  let idx ← env.getModuleIdxFor? name
  env.header.moduleNames[idx.toNat]?

/-- True if `name` is defined in a project module (one whose name has `rootPrefix` as a prefix).
This is keyed on the declaration's *module*, not its name: a project's declaration names need not
share the root module prefix (e.g. module `LeanMachineLearning.…` declaring `Bandits.foo`). -/
def isProjectLocalConst (env : Environment) (rootPrefix : Name) (name : Name) : Bool :=
  (moduleNameOf env name).any (hasPrefixName · rootPrefix)

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

/-- Decides whether a declaration should appear in the exposition output. -/
def shouldExpose (env : Environment) (rootPrefix : Name) (name : Name) (info : ConstantInfo) : Bool :=
  if let some moduleName := moduleNameOf env name then
    if !hasPrefixName moduleName rootPrefix then
      false
    else if env.isProjectionFn name then
      false
    else if isInternalName name || name.isInternal || name.isImplementationDetail then
      false
    else if isAuxRecursor env name || isNoConfusion env name then
      false
    else match info with
      | .ctorInfo _ | .recInfo _ | .quotInfo _ => false
      | _ => true
  else if env.isProjectionFn name then
    false
  else
    false

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
      let snippet := (String.trimAscii (sliceSourceSnippet lines src)).toString
      match snippet.splitOn ":=" with
      | _prefix :: rest@(_ :: _) =>
          some <| (String.trimAscii (String.intercalate ":=" rest)).toString
      | _ =>
          some snippet
  | _, _ => none

/-- Checks whether SorryIn. -/
def hasSorryIn (info : ConstantInfo) : Bool :=
  info.type.hasSorry || info.value?.any Expr.hasSorry

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
def issueUrlOf (repoUrl? : Option String) (decl : Name) (moduleName : Name) (source? : Option SourceInfo) (hasSorry : Bool) : Option String :=
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
      s!"**Status:** {if hasSorry then "sorry" else "proved"}",
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

/-- One-level "used constants" for a declaration's type (and, if `includeValue`, also its
value/body), handling inductive constructor types and structure field-default functions: for
inductives/structures, `info.type` alone does not mention constructor field types, so those are
pulled in from the constructors' types and (for structures) field-default functions. -/
def usedConstantsOf (env : Environment) (name : Name) (info : ConstantInfo)
    (includeValue : Bool) : Array Name :=
  let typeUsed :=
    match info with
    | .inductInfo val =>
      val.ctors.foldl (fun acc ctorName =>
        match env.find? ctorName with
        | some ctorInfo => acc ++ ctorInfo.type.getUsedConstants
        | none => acc) info.type.getUsedConstants
    | _ => info.type.getUsedConstants
  if !includeValue then
    typeUsed
  else
    let valueUsed :=
      match info with
      | .defnInfo val => val.value.getUsedConstants
      | .thmInfo val => val.value.getUsedConstants
      | .inductInfo _ =>
        if (getStructureInfo? env name).isNone then
          #[]
        else
          (getStructureFields env name).foldl (fun acc fieldName =>
            match getDefaultFnForField? env name fieldName with
            | some defaultFn =>
              match env.find? defaultFn >>= ConstantInfo.value? with
              | some value => acc ++ value.getUsedConstants
              | none => acc
            | none => acc) #[]
      | _ => #[]
    typeUsed ++ valueUsed

/-- Expands `start` by following constants that are project-local (share `rootPrefix`) but are
not themselves exposed declarations — i.e. compiler-generated helpers such as `_proof_N`,
`match_..`, or structure field-default functions — recursively pulling in whatever *they* depend
on instead of stopping at their (uninformative) name. Exposed declarations and external
(non-project) constants are kept as-is without further expansion.

This mirrors the recursive dependency-collection idea from
https://github.com/mattrobball/lean-informal/blob/main/Informal/Deps.lean, bounded to the
project's own constants so it doesn't walk into upstream library internals. `cache` memoizes the
one-level expansion of internal helpers across declarations. -/
partial def expandThroughInternals (env : Environment) (rootPrefix : Name)
    (exposed : Std.HashSet Name) (cache : Std.HashMap Name (Array Name)) (start : Array Name) :
    Array Name × Std.HashMap Name (Array Name) :=
  go cache {} #[] start.toList
where
  go (cache : Std.HashMap Name (Array Name)) (visited : Std.HashSet Name) (acc : Array Name) :
      List Name → Array Name × Std.HashMap Name (Array Name)
    | [] => (acc, cache)
    | n :: rest =>
      if visited.contains n then
        go cache visited acc rest
      else
        let visited := visited.insert n
        let isInternalHelper := !exposed.contains n && isProjectLocalConst env rootPrefix n
        if !isInternalHelper then
          go cache visited (acc.push n) rest
        else
          match cache.get? n with
          | some deps => go cache visited acc (rest ++ deps.toList)
          | none =>
            match env.find? n with
            | none => go cache visited acc rest
            | some info =>
              let deps := usedConstantsOf env n info true
              go (cache.insert n deps) visited acc (rest ++ deps.toList)

/-- True if `name` is incomplete because of a `sorry`, looking *through* project-local
compiler-generated helpers (`_proof_N`, `match_..`, field defaults, ...) the same way
`expandThroughInternals` surfaces hidden dependencies. A direct `sorryAx` in the declaration's own
type/value, or in any such helper it transitively reaches, counts.

Exposed declarations and external (non-project) constants are *not* followed: a `sorry` reachable
only through an exposed declaration is surfaced separately by `attachDependsOnSorry`, and upstream
library constants are assumed sorry-free. This closes the gap where `hasSorryIn` alone would miss a
`sorry` that the elaborator lifted into an auxiliary `_proof_N` lemma. -/
partial def usesSorryThroughInternals (env : Environment) (rootPrefix : Name)
    (exposed : Std.HashSet Name) (name : Name) (info : ConstantInfo) : Bool :=
  hasSorryIn info || go {} (usedConstantsOf env name info true).toList
where
  go (visited : Std.HashSet Name) : List Name → Bool
    | [] => false
    | n :: rest =>
      if visited.contains n then
        go visited rest
      else
        let visited := visited.insert n
        let isInternalHelper := !exposed.contains n && isProjectLocalConst env rootPrefix n
        if !isInternalHelper then
          go visited rest
        else match env.find? n with
          | none => go visited rest
          | some info' =>
            if hasSorryIn info' then
              true
            else
              go visited (rest ++ (usedConstantsOf env n info' true).toList)

/-- All constants belonging to modules whose name has `rootPrefix`, paired with their module
name, gathered directly from `env.header.moduleData` so that the (typically much larger) set of
constants from imported libraries is never iterated. -/
def projectConstants (env : Environment) (rootPrefix : Name) : Array (Name × Name × ConstantInfo) :=
  (Array.range env.header.modules.size).foldl (fun acc idx =>
    let modName := env.header.modules[idx]!.module
    if hasPrefixName modName rootPrefix then
      let data := env.header.moduleData[idx]!
      (Array.zip data.constNames data.constants).foldl
        (fun acc2 (cname, cinfo) => acc2.push (cname, modName, cinfo)) acc
    else acc) #[]

/-- The `String` a string-literal `Expr` holds, if `e` is one. -/
private def exprStrLit? (e : Expr) : Option String :=
  match e with
  | .lit (.strVal s) => some s
  | _ => none

/-- Reconstructs the `Name` value that `e` builds, if `e` is a `Name.anonymous`/`Name.str`/
`Name.mkStr1..4` application. Notation and macro definitions store the constants they expand to as
pre-resolved `Name` *data* built this way (inside the embedded `Syntax`), so these references are
invisible to `Expr.getUsedConstants`; reconstructing them is how we recover the dependency. -/
partial def evalNameExpr? (e : Expr) : Option Name := do
  match e.getAppFnArgs with
  | (``Lean.Name.anonymous, _) => some .anonymous
  | (``Lean.Name.mkStr1, #[a]) => some (.str .anonymous (← exprStrLit? a))
  | (``Lean.Name.mkStr2, #[a, b]) =>
    some (.str (.str .anonymous (← exprStrLit? a)) (← exprStrLit? b))
  | (``Lean.Name.mkStr3, #[a, b, c]) =>
    some (.str (.str (.str .anonymous (← exprStrLit? a)) (← exprStrLit? b)) (← exprStrLit? c))
  | (``Lean.Name.mkStr4, #[a, b, c, d]) =>
    some (.str (.str (.str (.str .anonymous (← exprStrLit? a)) (← exprStrLit? b)) (← exprStrLit? c))
      (← exprStrLit? d))
  | (``Lean.Name.str, #[p, s]) => some (.str (← evalNameExpr? p) (← exprStrLit? s))
  | _ => none

/-- Every `Name` value embedded anywhere in `e` (reconstructed via `evalNameExpr?`). -/
partial def collectEmbeddedNames (e : Expr) : Array Name := Id.run do
  let mut acc : Array Name := #[]
  if let some n := evalNameExpr? e then acc := acc.push n
  match e with
  | .app f a => return acc ++ collectEmbeddedNames f ++ collectEmbeddedNames a
  | .lam _ t b _ => return acc ++ collectEmbeddedNames t ++ collectEmbeddedNames b
  | .forallE _ t b _ => return acc ++ collectEmbeddedNames t ++ collectEmbeddedNames b
  | .letE _ t v b _ =>
    return acc ++ collectEmbeddedNames t ++ collectEmbeddedNames v ++ collectEmbeddedNames b
  | .mdata _ b => return acc ++ collectEmbeddedNames b
  | .proj _ _ b => return acc ++ collectEmbeddedNames b
  | _ => return acc

/-- True if `n` names a notation/syntax parser (its type is `Lean.ParserDescr`/`TrailingParserDescr`). -/
def isNotationKind (env : Environment) (n : Name) : Bool :=
  match env.find? n with
  | some info => info.type.isConstOf ``Lean.ParserDescr || info.type.isConstOf ``Lean.TrailingParserDescr
  | none => false

/-- Maps each notation parser to the constants its expansion references. A notation's macro definition
embeds both its own parser kind and the constant(s) it abbreviates as pre-resolved `Name` data (see
`evalNameExpr?`). Scanning the project's definitions, any whose body embeds a notation kind `K`
contributes its other embedded (real) constants as dependencies of `K` — so `K`'s standalone
extraction inlines what it stands for instead of failing with `unknown constant`. -/
def notationExpansionDeps (env : Environment) (projectConsts : Array (Name × Name × ConstantInfo)) :
    Std.HashMap Name (Array Name) := Id.run do
  let mut m : Std.HashMap Name (Array Name) := {}
  for (_, _, cinfo) in projectConsts do
    if let .defnInfo v := cinfo then
      let names := (collectEmbeddedNames v.value).filter (env.contains ·)
      let kinds := names.filter (isNotationKind env ·)
      unless kinds.isEmpty do
        let realDeps := names.filter (!isNotationKind env ·)
        for k in kinds do
          m := m.insert k ((m.getD k #[]) ++ realDeps)
  return m

/-- Coercion type classes whose instances Lean unfolds at use sites: an elaborated term keeps only
the underlying `@[coe]` function, never the instance, so a coercion's dependency on its instance is
invisible to `getUsedConstants`. The instance must still be replayed for the source's `↑`/`⇑` to
elaborate. -/
def coercionClasses : List Name :=
  [``CoeFun, ``CoeSort, ``Coe, ``CoeTC, ``CoeHead, ``CoeTail, ``CoeHTCT, ``CoeOut, ``CoeDep]

/-- If `type` is, under its binders, a coercion-class application `Cls Src …`, the head constant of
`Src` (the type coerced *from*). -/
partial def coercionSourceType? (type : Expr) : Option Name :=
  match type with
  | .forallE _ _ b _ => coercionSourceType? b
  | _ =>
    let (fn, args) := type.getAppFnArgs
    if coercionClasses.contains fn && args.size ≥ 1 then args[0]!.getAppFn.constName?
    else none

/-- Maps a type's head constant to the exposed coercion instances coercing *from* it. A declaration
mentioning such a type needs these instances replayed so its source coercions still elaborate (the
instances themselves never appear in the elaborated term; see `coercionClasses`). -/
def coercionInstancesByType (env : Environment) (exposed : Std.HashSet Name)
    (projectConsts : Array (Name × Name × ConstantInfo)) : Std.HashMap Name (Array Name) := Id.run do
  let mut m : Std.HashMap Name (Array Name) := {}
  for (cname, _, cinfo) in projectConsts do
    if exposed.contains cname && Lean.Meta.isInstanceCore env cname then
      if let some src := coercionSourceType? cinfo.type then
        m := m.insert src ((m.getD src #[]).push cname)
  return m

/-- Collects all exposed declarations and computes their primary metadata. -/
def collectDecls (projectDir : System.FilePath) (rootPrefix : Name)
    (pkg : Lake.Package) (env : Environment) : IO (Array DeclInfo) := do
  let projectConsts := projectConstants env rootPrefix
  let exposed : Std.HashSet Name :=
    projectConsts.foldl (fun acc (name, _, info) =>
      if shouldExpose env rootPrefix name info then acc.insert name else acc) {}
  let simpTheorems ← runCoreIO env Lean.Meta.getSimpTheorems
  let simpLemmaNames : Std.HashSet Name :=
    simpTheorems.lemmaNames.fold (fun acc origin =>
      match origin with
      | .decl declName .. => acc.insert declName
      | _ => acc) {}
  let notationDeps := notationExpansionDeps env projectConsts
  let coercionInsts := coercionInstancesByType env exposed projectConsts
  -- Adds, for every referenced type with coercion instances, those instances (see `coercionClasses`).
  let addCoercionInsts (cs : Array Name) : Array Name :=
    cs ++ cs.foldl (fun acc c => acc ++ coercionInsts.getD c #[]) #[]
  let mut cache : Std.HashMap Name (Array Name) := {}
  let mut fileLines : Std.HashMap System.FilePath (Array String) := {}
  let mut decls := #[]
  for (name, moduleName, info) in projectConsts do
    if !shouldExpose env rootPrefix name info then
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
    -- One-level constants from the type (and, separately, type+value), then expanded through
    -- any project-local compiler-generated helpers (`_proof_N`, `match_..`, field defaults, ...)
    -- so that dependencies hidden behind those helpers are surfaced too.
    let typeUsedConstants := addCoercionInsts (usedConstantsOf env name info false)
    -- When this declaration *is* a notation, also depend on the constants it expands to (which are
    -- stored as `Name` data inside its macro and so invisible to `getUsedConstants`); see
    -- `notationExpansionDeps`. The reverse direction (a declaration whose *source* uses a notation)
    -- is handled syntactically during extraction, where the parsed syntax is available.
    -- `addCoercionInsts` similarly recovers coercion instances unfolded out of the elaborated term.
    let allUsedConstants :=
      addCoercionInsts (usedConstantsOf env name info true ++ notationDeps.getD name #[])
    let (typeExpanded, cache1) := expandThroughInternals env rootPrefix exposed cache typeUsedConstants
    let (allExpanded, cache2) := expandThroughInternals env rootPrefix exposed cache1 allUsedConstants
    cache := cache2
    let dedup (cs : Array Name) : Array Name :=
      cs.foldl (fun acc dep => if dep != name && !acc.contains dep then acc.push dep else acc) #[]
    let typeDeps := dedup typeExpanded
    let deps := dedup allExpanded
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
      proofText? := proofText?
      source? := source?
      hasSorry := usesSorryThroughInternals env rootPrefix exposed name info
      isLemma := isLemma
      isInstanceDecl := isInstanceDecl
      isAlias := isAliasFromSource source? lines
      deps := deps
      typeDeps := typeDeps
      docstringBlock? := docstringBlock?
    }
    decls := decls.push decl
  pure decls

/-- Adds reverse dependency links (`usedBy`) between exposed declarations. -/
def attachReverseDeps (decls : Array DeclInfo) : Array DeclInfo :=
  let exposed : Std.HashSet Name := decls.foldl (fun s decl => s.insert decl.name) {}
  let rev : Std.HashMap Name (Array Name) := decls.foldl
    (fun acc decl =>
      decl.deps.foldl
        (fun inner dep =>
          if exposed.contains dep then
            inner.insert dep ((inner.getD dep #[]).push decl.name)
          else
            inner)
        acc)
    {}
  decls.map fun decl => { decl with usedBy := (rev.getD decl.name #[]).qsort Name.lt }

/-- Computes the declarations reachable from `start` via `depsMap`, in *topological* order: every
declaration appears after all of the declarations it depends on (a depth-first post-order). This is
the order in which the declarations could be emitted into a single self-contained Lean file, with
each definition preceding its first use.

Cycles (e.g. mutual recursion) are tolerated: a node is marked visited on entry, so the walk
terminates, and the members of a cycle come out in some arbitrary but otherwise dependency-respecting
order. -/
partial def topologicalClosure (depsMap : Std.HashMap Name (Array Name)) (start : Array Name) :
    Array Name :=
  (start.foldl (fun (acc : Std.HashSet Name × Array Name) n => visit acc.1 acc.2 n) ({}, #[])).2
where
  visit (visited : Std.HashSet Name) (order : Array Name) (n : Name) :
      Std.HashSet Name × Array Name :=
    if visited.contains n then
      (visited, order)
    else
      -- Mark `n` before recursing so a dependency cycle cannot loop forever.
      let visited := visited.insert n
      let (visited, order) :=
        (depsMap.getD n #[]).foldl
          (fun (acc : Std.HashSet Name × Array Name) d => visit acc.1 acc.2 d) (visited, order)
      -- Emit `n` only after all of its dependencies have been emitted.
      (visited, order.push n)

/-- Adds the transitive closure of `deps` to each declaration as `transDeps`, topologically ordered
so that every dependency precedes the declarations that use it (suitable for emitting a minimal
standalone Lean file). Expansion follows only `typeDeps` for theorems (their proofs are not part of
what a reader must trust further) and `deps` (type + body) for everything else. An `alias`, though a
theorem, keeps its body verbatim during extraction, so it follows `deps` too. -/
def attachTransitiveDeps (decls : Array DeclInfo) : Array DeclInfo :=
  let startDeps (decl : DeclInfo) : Array Name :=
    if decl.kind == .theorem && !decl.isAlias then decl.typeDeps else decl.deps
  let depsMap : Std.HashMap Name (Array Name) :=
    decls.foldl (fun acc decl => acc.insert decl.name (startDeps decl)) {}
  decls.map fun decl =>
    let closure := topologicalClosure depsMap (startDeps decl)
    { decl with transDeps := closure.filter (· != decl.name) }

/-- Marks declarations that transitively depend on any `sorry`. -/
def attachDependsOnSorry (decls : Array DeclInfo) : Array DeclInfo :=
  Id.run do
    let exposed : Std.HashSet Name := decls.foldl (fun s decl => s.insert decl.name) {}
    let mut marked : Std.HashSet Name :=
      decls.foldl (fun s decl => if decl.hasSorry then s.insert decl.name else s) {}
    let mut changed := true
    while changed do
      changed := false
      for decl in decls do
        if !marked.contains decl.name then
          let depends := decl.deps.any fun dep => exposed.contains dep && marked.contains dep
          if depends then
            marked := marked.insert decl.name
            changed := true
    return decls.map fun decl => { decl with dependsOnSorry := marked.contains decl.name }


end LMLExposition
