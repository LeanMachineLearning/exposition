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

namespace LeanExposition

open Verso.Output Html

/-- CLI options used to configure exposition generation. -/
structure Cli where
  projectDir : System.FilePath := "."
  rootPrefix : Option Name := none
  repoUrl : Option String := none
  siteTitle : Option String := none
  outputDir : Option String := none
  comparatorConfig : Option System.FilePath := none
  tfbExe : String := "extractDeps"
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
  tags : Array String := #[]
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
  dependsOnSorry : Bool := false
  inTfb : Bool := false
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

/-- Comparator-driven trusted-base configuration loaded from JSON. -/
structure ComparatorConfigInfo where
  challengeModule : String
  solutionModule : String
  theoremNames : Array Name
  permittedAxioms : Array String
  enableNanoda : Bool
deriving Repr

/-- Trusted-base closure and comparator availability information. -/
structure TrustedBaseInfo where
  names : Std.HashSet Name := {}
  comparator? : Option ComparatorConfigInfo := none
  comparatorInstalled : Bool := false
deriving Repr

/-- Data container for TargetStatementInfo. -/
structure TargetStatementInfo where
  theoremName : Name
  relPath : String
  line? : Option Nat := none
  statement? : Option String := none
deriving Repr

/-- Command-line usage text shown for invalid arguments. -/
def usage : String :=
  String.intercalate "\n" [
    "Usage: lake exe exposition [options]",
    "",
    "Options:",
    "  --project DIR        Path to the target Lean project (default: current directory)",
    "  --root PREFIX        Root module prefix to expose (default: first root library)",
    "  --repo-url URL       GitHub repo URL used for issue/source links",
    "  --title TITLE        Site title override",
    "  --output DIR         Output directory passed to Verso",
    "  --comparator-config  Comparator config file relative to the target project",
    "  --tfb-exe NAME       Lake executable used to compute the trusted-base closure",
    "  --exclude-lib NAME   Exclude a root library when importing the target project",
  ]

/-- Parses CLI arguments into `Cli`, or returns a usage error. -/
def parseArgs : List String → Except String Cli
  | [] => .ok {}
  | "--project" :: dir :: rest => do
      let cfg ← parseArgs rest
      pure { cfg with projectDir := dir }
  | "--root" :: root :: rest => do
      let cfg ← parseArgs rest
      pure { cfg with rootPrefix := some root.toName }
  | "--repo-url" :: url :: rest => do
      let cfg ← parseArgs rest
      pure { cfg with repoUrl := some url }
  | "--title" :: title :: rest => do
      let cfg ← parseArgs rest
      pure { cfg with siteTitle := some title }
  | "--output" :: out :: rest => do
      let cfg ← parseArgs rest
      pure { cfg with outputDir := some out }
  | "--comparator-config" :: path :: rest => do
      let cfg ← parseArgs rest
      pure { cfg with comparatorConfig := some path }
  | "--tfb-exe" :: exe :: rest => do
      let cfg ← parseArgs rest
      pure { cfg with tfbExe := exe }
  | "--exclude-lib" :: lib :: rest => do
      let cfg ← parseArgs rest
      pure { cfg with excludeLibs := cfg.excludeLibs.push lib.toName }
  | flag :: _ =>
      .error s!"Unknown or incomplete option: {flag}\n\n{usage}"

/-- Checks whether AuxComponent. -/
def isAuxComponent (s : String) : Bool :=
  s.startsWith "_" || s.startsWith "match_" || s.startsWith "proof_" || s.startsWith "eq_"

/-- Checks whether InternalName. -/
partial def isInternalName : Name → Bool
  | .anonymous => false
  | .num p _ => isInternalName p
  | .str p s =>
      isAuxComponent s
      || s ∈ ["brecOn", "below", "casesOn", "noConfusion", "noConfusionType",
              "recOn", "rec", "ind", "mk", "sizeOf_spec", "inject", "injEq",
              "ctorIdx", "ext_iff"]
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

/-- Computes anchor IdOf. -/
def anchorIdOf (name : Name) : String :=
  String.intercalate "___" (name.toString.splitOn ".")

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
def mkLinkParagraph (sourceUrl? issueUrl? detailsUrl? : Option String) : Option (Block Manual) :=
  let items :=
    ([detailsUrl?.map fun url => .link #[.text "Details"] url,
      sourceUrl?.map fun url => .link #[.text "Source"] url,
      issueUrl?.map fun url => .link #[.text "Open Issue"] url].filterMap id)
  if items.isEmpty then
    none
  else
    let entries := items.map fun item => #[item]
    some <| .para <|
      #[.bold #[.text "Actions: "]] ++ joinInlines entries #[.text " · "]

/-- Converts markdown text into `Block Manual` nodes. -/
def markdownToBlocks (doc : String) : Array (Block Manual) :=
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

/-- Helper for extractDepsName?. -/
def extractDepsName? (line : String) : Option Name :=
  let trimmed := (String.trimAscii line).toString
  if trimmed.startsWith "- `" then
    let rest := (trimmed.drop 3).toString
    match rest.splitOn "`" with
    | name :: _ => if name.isEmpty then none else some name.toName
    | [] => none
  else
    none

/-- Loads and validates optional comparator configuration from JSON. -/
def loadComparatorConfig? (projectDir : System.FilePath)
    (configPath? : Option System.FilePath := none) : IO (Option ComparatorConfigInfo) := do
  let cfgPath := projectDir / configPath?.getD "comparator.json"
  let text? ← readFileIfExists cfgPath
  match text? with
  | none => return none
  | some contents =>
      match Json.parse contents with
      | .error _ => pure none
      | .ok json =>
          let challenge? :=
            match json.getObjValAs? String "challenge_module" with
            | .ok value => some value
            | .error _ => none
          let solution? :=
            match json.getObjValAs? String "solution_module" with
            | .ok value => some value
            | .error _ => none
          let theoremNames? :=
            match json.getObjValAs? (Array String) "theorem_names" with
            | .ok value => some <| value.map String.toName
            | .error _ => none
          let permittedAxioms? :=
            match json.getObjValAs? (Array String) "permitted_axioms" with
            | .ok value => some value
            | .error _ => none
          let enableNanoda? :=
            match json.getObjValAs? Bool "enable_nanoda" with
            | .ok value => some value
            | .error _ => none
          match challenge?, solution?, theoremNames?, permittedAxioms?, enableNanoda? with
          | some challengeModule, some solutionModule, some theoremNames, some permittedAxioms, some enableNanoda =>
              pure <| some {
                challengeModule
                solutionModule
                theoremNames
                permittedAxioms
                enableNanoda
              }
          | _, _, _, _, _ => pure none

/-- Checks whether ComparatorInstalled. -/
def isComparatorInstalled : IO Bool := do
  let out ← IO.Process.output {
    cmd := "which"
    args := #["comparator"]
  }
  pure <| out.exitCode == 0

/-- Computes module RelPathOfString. -/
def moduleRelPathOfString (moduleName : String) : String :=
  s!"{moduleName.replace "." "/"}.lean"

/-- Finds DeclarationLine?. -/
def findDeclarationLine? (lines : Array String) (shortName : String) : Option Nat :=
  ((List.range lines.size).findSome? fun idx =>
    let trimmed := (String.trimAscii lines[idx]!).toString
    if trimmed.startsWith "theorem " && trimmed.contains shortName then
      some (idx + 1)
    else
      none)

/-- Loads theorem statement and source position from a challenge module. -/
def loadTargetStatementInfo (projectDir : System.FilePath) (challengeModule : String)
    (theoremName : Name) : IO TargetStatementInfo := do
  let relPath := moduleRelPathOfString challengeModule
  let filePath := projectDir / relPath
  let some contents ← readFileIfExists filePath
    | pure { theoremName, relPath }
  let lines := (contents.splitOn "\n").toArray
  let line? := findDeclarationLine? lines theoremName.getString!
  let statement? :=
    line?.bind fun line =>
      let snippet := String.intercalate "\n" <| (lines.toList.drop (line - 1))
      let head :=
        match snippet.splitOn ":=" with
        | first :: _ => (String.trimAscii first).toString
        | [] => (String.trimAscii snippet).toString
      if head.isEmpty then none else some head
  pure {
    theoremName
    relPath
    line?
    statement?
  }

/-- Builds a repository URL for a target theorem source location. -/
def targetSourceUrlOf (repoUrl? : Option String) (relPath : String) (line? : Option Nat) : Option String :=
  match repoUrl? with
  | none => none
  | some repoUrl =>
      some <| match line? with
        | some line => s!"{repoUrl}/blob/main/{relPath}#L{line}"
        | none => s!"{repoUrl}/blob/main/{relPath}"

/-- Renders trusted-base target theorem summaries for the site. -/
def loadTrustedBaseTargetBlocks (projectDir : System.FilePath) (repoUrl? : Option String)
    (tfbInfo : TrustedBaseInfo) : IO (Array (Block Manual)) := do
  match tfbInfo.comparator? with
  | none => pure #[]
  | some comparator =>
      let mut blocks : Array (Block Manual) := #[]
      for theoremName in comparator.theoremNames do
        let info ← loadTargetStatementInfo projectDir comparator.challengeModule theoremName
        blocks := blocks.push (.para #[.bold #[.text "Checked statement"]])
        match info.statement? with
        | some statement => blocks := blocks.push (.code statement)
        | none => blocks := blocks.push (.para #[.code theoremName.toString])
        let sourceLabel :=
          match info.line? with
          | some line => s!"{info.relPath}:{line}"
          | none => info.relPath
        let sourceInline :=
          match targetSourceUrlOf repoUrl? info.relPath info.line? with
          | some url => .link #[.text sourceLabel] url
          | none => .code sourceLabel
        blocks := blocks.push (.para #[.bold #[.text "Source: "], sourceInline])
      pure blocks

/-- Computes the trusted-base closure by running `lake exe extractDeps`. -/
def computeTrustedBaseNames (projectDir : System.FilePath) (rootPrefix : Name)
    (targets : Array Name) (tfbExe : String := "extractDeps") : IO (Std.HashSet Name) := do
  if targets.isEmpty then
    return {}
  let mut names : Std.HashSet Name := {}
  for target in targets do
    let out ← IO.Process.output {
      cmd := "lake"
      args := #["exe", tfbExe, target.toString, rootPrefix.toString]
      cwd := some projectDir
    }
    if out.exitCode != 0 then
      return {}
    for line in out.stdout.splitOn "\n" do
      if let some dep := extractDepsName? line then
        names := names.insert dep
  pure names

/-- Loads comparator config and trusted-base names into one record. -/
def loadTrustedBaseInfo (cfg : Cli) (rootPrefix : Name) : IO TrustedBaseInfo := do
  let comparator? ← loadComparatorConfig? cfg.projectDir cfg.comparatorConfig
  let comparatorInstalled ← isComparatorInstalled
  match comparator? with
  | none => pure { comparatorInstalled := comparatorInstalled }
  | some comparator =>
      let names ← computeTrustedBaseNames cfg.projectDir rootPrefix comparator.theoremNames cfg.tfbExe
      pure {
        names
        comparator? := some comparator
        comparatorInstalled := comparatorInstalled
      }

/-- Pretty-prints ExprString. -/
def ppExprString (env : Environment) (e : Expr) : IO String := do
  let ctx : PPContext := { env := env, opts := {} }
  return toString (← ctx.runMetaM (Meta.ppExpr e))

/-- Builds the same `Block.docstring` value that `{docstring name}` would produce inside
a `#doc` page, by directly invoking Verso's signature/declaration-type computation. Returns
`none` if this fails for the given declaration (e.g. unsupported declaration shapes). -/
def mkDocstringBlock? (env : Environment) (name : Name) : IO (Option (Block Manual)) := do
  let coreCtx : Core.Context := { fileName := "<exposition>", fileMap := default }
  let act : MetaM (Block Manual) := do
    let declType ← Block.Docstring.DeclType.ofName name
    let sig ← (Signature.forName name : Elab.TermElabM Signature).run' {}
    pure <| .other (Block.docstring name declType sig none #[]) #[]
  try
    let block ← (act.run' {}).toIO' coreCtx { env := env }
    pure (some block)
  catch _ =>
    pure none

/-- Reads SourceSnippet. -/
def readSourceSnippet (src : SourceInfo) : IO String := do
  let text ← IO.FS.readFile src.absPath
  let lines := (text.splitOn "\n").toArray
  let startIdx := src.line - 1
  let endIdx := min src.endLine lines.size
  let selected := (List.range (endIdx - startIdx)).map fun i => lines[startIdx + i]!
  pure <| String.intercalate "\n" selected

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
def displaySignatureFromSource (kind : DeclKind) (src? : Option SourceInfo) : IO (Option String) := do
  let some src := src? | return none
  let snippet := cleanDeclSnippet (← readSourceSnippet src)
  if snippet.isEmpty then
    return none
  let rendered :=
    match kind with
    | .definition | .structure | .typeclass | .inductive => snippet
    | _ => headBeforeAssignment snippet
  if rendered.isEmpty then
    return none
  return some rendered

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
def proofTextFromSource (kind : DeclKind) (src? : Option SourceInfo) : IO (Option String) := do
  match kind, src? with
  | .theorem, some src
  | .opaque, some src
  | .instance, some src =>
      let snippet := (String.trimAscii (← readSourceSnippet src)).toString
      match snippet.splitOn ":=" with
      | _prefix :: rest@(_ :: _) =>
          pure <| some <| (String.trimAscii (String.intercalate ":=" rest)).toString
      | _ =>
          pure <| some snippet
  | _, _ => pure none

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

/-- Helper for trustedBaseGroupHrefOf. -/
def trustedBaseGroupHrefOf (groupKey : String) : String :=
  s!"tfb-chapter-{slugify groupKey}/"

/-- Helper for trustedBaseModuleHrefOf. -/
def trustedBaseModuleHrefOf (modulePath : String) : String :=
  s!"tfb-module-{slugify modulePath}/"

/-- Computes path ForPart. -/
def pathForPart (groupKey modulePath : String) (declName : Name) : String :=
  s!"{groupHrefOf groupKey}{moduleHrefOf modulePath}#{anchorIdOf declName}"

/-- Computes path ForTrustedBasePart. -/
def pathForTrustedBasePart (groupKey modulePath : String) (declName : Name) : String :=
  s!"{trustedBaseGroupHrefOf groupKey}{trustedBaseModuleHrefOf modulePath}#{anchorIdOf declName}"

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

/-- Collects all exposed declarations and computes their primary metadata. -/
def collectDecls (projectDir : System.FilePath) (rootPrefix : Name)
    (pkg : Lake.Package) (env : Environment) : IO (Array DeclInfo) := do
  let mut decls := #[]
  for (name, info) in env.constants.toList do
    let some moduleName := moduleNameOf env name | continue
    if !shouldExpose env rootPrefix name info then
      continue
    let ranges? ← findRanges? env name
    let source? ← toSourceInfo? projectDir pkg moduleName ranges?
    let kind := declKindOf env info name
    let expandedSignature ← ppExprString env info.type
    let displaySignature :=
      (← displaySignatureFromSource kind source?).getD <|
        displaySignatureFallback kind name expandedSignature
    let proofText? ← proofTextFromSource kind source?
    let doc? ← findDocString? env name
    let docBlocks :=
      match doc? with
      | some doc => markdownToBlocks doc
      | none => #[]
    -- For inductives/structures, `info.type` is just the type former's type
    -- (e.g. `Type` or `Foo → Type`) and does not mention field/argument types.
    -- Those live in the constructors' types, so pull constants from there too.
    let typeUsedConstants :=
      match info with
      | .inductInfo val =>
        val.ctors.foldl (fun acc ctorName =>
          match env.find? ctorName with
          | some ctorInfo => acc ++ ctorInfo.type.getUsedConstants
          | none => acc) info.type.getUsedConstants
      | _ => info.type.getUsedConstants
    -- Constants used in the definition's/proof's body, not just its type.
    -- For structures/classes, field default values are auxiliary `_default`
    -- definitions, not visible in the constructor's type, so pull them in too.
    let valueUsedConstants :=
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
    let dedup (cs : Array Name) : Array Name :=
      cs.foldl (fun acc dep => if dep != name && !acc.contains dep then acc.push dep else acc) #[]
    let typeDeps := dedup typeUsedConstants
    let deps := dedup (typeUsedConstants ++ valueUsedConstants)
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
      hasSorry := hasSorryIn info
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

/-- Computes the set of declarations reachable from `start` via `depsMap`. -/
partial def transitiveClosure (depsMap : Std.HashMap Name (Array Name)) (start : Array Name) :
    Std.HashSet Name :=
  go {} start.toList
where
  go (visited : Std.HashSet Name) : List Name → Std.HashSet Name
    | [] => visited
    | n :: rest =>
      if visited.contains n then
        go visited rest
      else
        go (visited.insert n) ((depsMap.getD n #[]).toList ++ rest)

/-- Adds the transitive closure of `deps` (all declarations reachable, recursively) to each
declaration as `transDeps`. -/
def attachTransitiveDeps (decls : Array DeclInfo) : Array DeclInfo :=
  let depsMap : Std.HashMap Name (Array Name) :=
    decls.foldl (fun acc decl => acc.insert decl.name decl.deps) {}
  decls.map fun decl =>
    let closure := transitiveClosure depsMap decl.deps
    { decl with transDeps := (closure.toArray.filter (· != decl.name)).qsort Name.lt }

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

/-- Marks declarations that belong to the trusted-base closure. -/
def attachTrustedBaseFlags (tfb : Std.HashSet Name) (decls : Array DeclInfo) : Array DeclInfo :=
  decls.map fun decl => { decl with inTfb := tfb.contains decl.name }


end LeanExposition
