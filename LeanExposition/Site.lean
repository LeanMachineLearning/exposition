import Lean
import Lean.DeclarationRange
import Lean.Meta.Instances
import Lean.Util.Sorry
import Lake.CLI.Main
import Lake.Load.Workspace
import MD4Lean
import VersoManual
import VersoManual.Markdown
import LeanExposition.Theme
import LeanExposition.GraphJs
import LeanExposition.TocJs
import LeanExposition.Collect

open Lake
open Lean
open Lean.Meta
open Verso.Doc
open Verso.Genre
open Manual

namespace LeanExposition

open Verso.Output Html


/-- Returns the ordering rank for a module, with a large fallback value. -/
private def moduleRank (order : Std.HashMap Name Nat) (moduleName : Name) : Nat :=
  order.getD moduleName 1000000000

/-- Sorts modules by import rank, then by module path. -/
private def sortModules (order : Std.HashMap Name Nat) (mods : Array ModuleInfo) : Array ModuleInfo :=
  mods.qsort fun a b =>
    let ra := moduleRank order a.name
    let rb := moduleRank order b.name
    if ra == rb then a.path < b.path else ra < rb

/-- Sorts declarations inside each module using source order when available. -/
private def sortDeclsInModules (mods : Array ModuleInfo) : Array ModuleInfo :=
  mods.map fun modInfo =>
    let decls :=
      modInfo.decls.qsort fun a b =>
        match a.source?, b.source? with
        | some sa, some sb => if sa.line == sb.line then a.name.lt b.name else sa.line < sb.line
        | some _, none => true
        | none, some _ => false
        | none, none => a.name.lt b.name
    { modInfo with decls := decls }

/-- Builds module summaries from declarations and applies stable ordering. -/
private def buildModules (rootPrefix : Name) (order : Std.HashMap Name Nat) (decls : Array DeclInfo) : Array ModuleInfo :=
  let mods := moduleIndexMap decls |>.toArray.map fun (name, ds) => {
    name := name
    path := modulePathOf rootPrefix name
    groupKey := groupKeyOfModule rootPrefix name
    decls := ds
  }
  sortDeclsInModules <| sortModules order mods

/-- Builds chapter groups from modules and orders them by import rank. -/
private def buildGroups (order : Std.HashMap Name Nat) (mods : Array ModuleInfo) : Array GroupInfo :=
  let groupRank (group : GroupInfo) : Nat :=
    group.modules.foldl (fun best modInfo => min best (moduleRank order modInfo.name)) 1000000000
  groupIndexMap mods |>.toArray
    |>.map (fun (key, modules) => { key, modules := sortModules order modules })
    |>.qsort (fun a b =>
      let ra := groupRank a
      let rb := groupRank b
      if ra == rb then a.key < b.key else ra < rb)

/-- Builds a source-link paragraph when a source URL is available. -/
private def mkSourceParagraph (label : String) (url? : Option String) : Array (Block Manual) :=
  match url? with
  | some url => #[.para #[.bold #[.text "Source: "], .link #[.text label] url]]
  | none => #[]

/-- Constructs a generic markdown-backed documentation page part. -/
private def mkMarkdownPart (title : String) (fileSlug : String) (body : String)
    (sourceUrl? : Option String := none) (shortTitle? : Option String := none)
    (sourceLabel? : Option String := none)
    (subParts : Array (Part Manual) := #[]) : Part Manual :=
  {
    title := #[.text title]
    titleString := title
    metadata := some {
      file := some fileSlug
      shortTitle := shortTitle?
      tag := some (.provided fileSlug)
      number := false
    }
    content := mkSourceParagraph (sourceLabel?.getD title) sourceUrl? ++ markdownToBlocks body
    subParts := subParts
  }

/-- Loads overview/context pages from the project README when present. -/
private def loadProjectContextParts (projectDir : System.FilePath) (repoUrl? : Option String)
    : IO (Array (Block Manual) × Array (Part Manual)) := do
  let readmePath := projectDir / "README.md"
  let mut rootBlocks : Array (Block Manual) := #[]
  let mut parts : Array (Part Manual) := #[]

  if let some readme ← readFileIfExists readmePath then
    let sections := parseMarkdownSections readme
    let sections :=
      sections.takeWhile fun sec => sec.title != "Selected References"
    if let some overview := sections[0]? then
      rootBlocks := rootBlocks ++ #[.para #[.text "Project overview."]] ++ markdownToBlocks overview.body
      let contextSubParts :=
        sections.toList.drop 1 |>.toArray.map fun sec =>
          mkMarkdownPart sec.title s!"context-{slugify sec.title}" sec.body
      let contextPage := {
        title := #[.text "Overview"]
        titleString := "Overview"
        metadata := some {
          file := some "context"
          shortTitle := some "Overview"
          tag := some (.provided "project-context")
          number := false
          htmlSplit := .never
        }
        content := mkSourceParagraph "README.md" (repoFileUrlOf repoUrl? "README.md") ++ markdownToBlocks overview.body
        subParts := contextSubParts
      }
      parts := parts.push contextPage

  return (rootBlocks, parts)



block_extension Block.declCard (_payload : DeclCardData) where
  data := ToJson.toJson _payload
  traverse _ _ _ _ := pure none
  toTeX := some fun _goI goB _id _data contents => contents.mapM goB
  toHtml := some fun _goI goB _id data contents => do
    let .ok (payload : DeclCardData) := FromJson.fromJson? data
      | Verso.reportError s!"Could not decode declaration card data from {data.compress}"
        pure .empty
    let tags :=
      payload.tags.map fun tag =>
        let className :=
          if tag == "TFB" then "decl-card-tag tfb" else "decl-card-tag sorry"
        {{<span class={{className}}>{{tag}}</span>}}
    let tagsHtml :=
      if payload.tags.isEmpty then
        .empty
      else
        {{<div class="decl-card-tags">{{tags}}</div>}}
    pure {{
      <section class="decl-section" data-decl-kind={{payload.kindLabel}}>
        <h2 id={{payload.anchorId}} class="decl-heading">
          <code>{{payload.shortName}}</code>
          <a class="decl-permalink" href={{s!"#{payload.anchorId}"}} title="Permalink">"🔗"</a>
        </h2>
        <div class="decl-card">
          <div class="decl-card-header">
            <div class="decl-card-title">
              <span class="decl-card-label">{{payload.kindLabel}}</span>
              <code class="decl-card-name">{{payload.fullName}}</code>
            </div>
            <div class="decl-card-tagbar">{{tagsHtml}}</div>
          </div>
          <div class="decl-card-body">
            {{← contents.mapM goB}}
          </div>
        </div>
      </section>
    }}

block_extension Block.details (_payload : DetailsData) where
  data := ToJson.toJson _payload
  traverse _ _ _ _ := pure none
  toTeX := some fun _goI goB _id _data contents => contents.mapM goB
  toHtml := some fun _goI goB _id data contents => do
    let .ok (payload : DetailsData) := FromJson.fromJson? data
      | Verso.reportError s!"Could not decode details block data from {data.compress}"
        pure .empty
    pure {{
      <details>
        <summary>{{payload.summary}}</summary>
        {{← contents.mapM goB}}
      </details>
    }}

block_extension Block.graph (_payload : GraphData) where
  data := ToJson.toJson _payload
  traverse _ _ _ _ := pure none
  toTeX := some fun _ _ _ _ _ => pure .empty
  toHtml := some fun _ _ _ data _ => do
    let .ok (payload : GraphData) := FromJson.fromJson? data
      | Verso.reportError s!"Could not decode graph data from {data.compress}"
        pure .empty
    pure {{
      <div id="graph-root"></div>
      {{Html.tag "script" #[("id", "graph-data"), ("type", "application/json")] (.text false (ToJson.toJson payload).compress)}}
    }}

/-- Rendering configuration for the exposition site output. -/
private def renderConfig (hasTfb : Bool) : RenderConfig :=
  {
    emitTeX := false
    emitHtmlSingle := .no
    emitHtmlMulti := .immediately
    htmlDepth := 2
    rootTocDepth := some 1
    sectionTocDepth := some 1
    extraCss := [customCss]
    extraJs := [graphJs, tocJs hasTfb]
    extraHead := #[
      Html.tag "script" #[("src", "https://d3js.org/d3.v7.min.js")] .empty
    ]
  }

/-- Counts declarations that contain `sorry`. -/
private def countSorries (decls : Array DeclInfo) : Nat :=
  decls.foldl (fun n decl => n + if decl.hasSorry then 1 else 0) 0

/-- Counts total declarations across all groups/modules. -/
private def countDecls (groups : Array GroupInfo) : Nat :=
  groups.foldl (fun n group =>
    n + group.modules.foldl (fun inner modInfo => inner + modInfo.decls.size) 0) 0

/-- Builds dashboard summary blocks for chapter and module progress. -/
private def mkDashboardBlocks (groups : Array GroupInfo) : Array (Block Manual) :=
  groups.foldl (fun acc group =>
    let groupTotal := group.modules.foldl (fun n modInfo => n + modInfo.decls.size) 0
    let groupSorry := group.modules.foldl (fun n modInfo => n + countSorries modInfo.decls) 0
    let intro : Block Manual :=
      .para #[
        .bold #[.link #[.text <| humanizeWord group.key] (groupHrefOf group.key)],
        .text s!"  ({groupTotal} declarations, {groupSorry} with sorry)"
      ]
    let items := group.modules.map fun modInfo =>
      Verso.Doc.ListItem.mk #[
        .para #[
          .link #[.code modInfo.path] s!"{groupHrefOf group.key}{moduleHrefOf modInfo.path}",
          .text s!"  ({modInfo.decls.size} declarations, {countSorries modInfo.decls} with sorry)"
        ]
      ]
    acc ++ #[intro, .ul items]
  ) #[]

/-- Builds the reader-guide section linking to overview, TFB, and graph pages. -/
private def mkReaderGuideBlocks (hasContext hasTfb : Bool) : Array (Block Manual) :=
  let contextItems :=
    if hasContext then
      #[Verso.Doc.ListItem.mk #[
        .para #[
          .bold #[.link #[.text "Overview"] "context/"],
          .text " explains the repository scope and mathematical target."
        ]
      ]]
    else
      #[]
  let tfbItems :=
    if hasTfb then
      #[Verso.Doc.ListItem.mk #[
        .para #[
          .bold #[.link #[.text "Trusted Formalization Base"] "trusted-base/"],
          .text " shows the declarations a reader must trust for the comparator-facing theorem."
        ]
      ]]
    else
      #[]
  let graphItems := #[Verso.Doc.ListItem.mk #[
    .para #[
      .bold #[.link #[.text "Dependency Graph"] "graph/"],
      .text " provides the interactive dependency view."
    ]
  ]]
  let items := contextItems ++ tfbItems ++ graphItems
  if items.isEmpty then
    #[]
  else
    #[
      .para #[.bold #[.text "Reader guides"]],
      .ul items
    ]

/-- Builds an index view for trusted-base declarations grouped by chapter/module. -/
private def mkTrustedBaseIndexBlocks (groups : Array GroupInfo) : Array (Block Manual) :=
  if groups.isEmpty then
    #[]
  else
    #[.para #[.bold #[.text "Browse the trusted base by chapter."]]]
    ++ groups.foldl (fun acc group =>
      let groupTotal := group.modules.foldl (fun n modInfo => n + modInfo.decls.size) 0
      let moduleItems := group.modules.map fun modInfo =>
        let declLinks := modInfo.decls.map fun decl =>
          { label := decl.name.getString!
            href? := some <| pathForTrustedBasePart group.key modInfo.path decl.name }
        let linkBlock? :=
          if declLinks.isEmpty then
            none
          else
            let entries := declLinks.toList.map fun link => #[mkCodeLink link]
            some <| .para <| joinInlines entries #[.text " · "]
        let blocks : Array (Block Manual) := #[
          .para #[
            .bold #[.link #[.code modInfo.path] s!"{trustedBaseGroupHrefOf group.key}{trustedBaseModuleHrefOf modInfo.path}"],
            .text s!" ({modInfo.decls.size} declarations)"
          ]
        ]
        let blocks :=
          match linkBlock? with
          | some linkBlock => blocks.push linkBlock
          | none => blocks
        Verso.Doc.ListItem.mk blocks
      acc.push <| .other (Block.details {
        summary := s!"{humanizeWord group.key} ({groupTotal} declarations)"
      }) #[
        .para #[
          .text "Chapter page: ",
          .link #[.text <| humanizeWord group.key] (trustedBaseGroupHrefOf group.key)
        ],
        .ul moduleItems
      ]
    ) #[]

/-- Renders one declaration card with docs, statement, links, and dependencies. -/
private def mkDeclBlock (decl : DeclInfo) (repoUrl? : Option String)
    (declHrefs : Std.HashMap Name String) : Block Manual :=
  Id.run do
    let issueUrl := issueUrlOf repoUrl? decl.name decl.moduleName decl.source? decl.hasSorry
    let sourceUrl := sourceUrlOf repoUrl? decl.source?
    let mkLinks (deps : Array Name) := deps.filterMap fun dep =>
      declHrefs.get? dep |>.map fun href => { label := dep.getString!, href? := some href }
    let typeDepLinks := mkLinks decl.typeDeps
    let proofDepLinks := mkLinks <| decl.deps.filter (!decl.typeDeps.contains ·)
    let usedByLinks := mkLinks decl.usedBy
    let mut blocks : Array (Block Manual) := #[]
    blocks := blocks ++ decl.docBlocks
    let hasDoc := !decl.docBlocks.isEmpty
    if !hasDoc then
      blocks := blocks.push (.para #[.emph #[.text "No docstring."]])
    blocks := blocks.push (.para #[.bold #[.text "Statement"]])
    blocks := blocks.push (.code decl.displaySignature)
    if let some block := depListBlock typeDepLinks then
      blocks := blocks.push <| .other (Block.details { summary := s!"Type uses ({typeDepLinks.size})" }) #[block]
    if let some block := depListBlock proofDepLinks then
      blocks := blocks.push <| .other (Block.details { summary := s!"Body uses ({proofDepLinks.size})" }) #[block]
    if let some block := depListBlock usedByLinks then
      blocks := blocks.push <| .other (Block.details { summary := s!"Used by ({usedByLinks.size})" }) #[block]
    if let some block := mkLinkParagraph sourceUrl issueUrl then
      blocks := blocks.push block
    if let some proof := decl.proofText? then
      blocks := blocks.push <| .other (Block.details { summary := "Proof" }) #[.code proof]
    let cardData : DeclCardData := {
      anchorId := anchorIdOf decl.name
      shortName := decl.name.getString!
      kindLabel := decl.kind.label
      fullName := decl.name.toString
      tags := #[
        if decl.dependsOnSorry then some "depends transitively on sorry" else none,
        if decl.inTfb then some "TFB" else none
      ].filterMap id
    }
    .other (Block.declCard cardData) blocks

/-- Builds a module page from its declarations. -/
private def mkModulePart (moduleInfo : ModuleInfo) (repoUrl? : Option String)
    (declHrefs : Std.HashMap Name String) : Part Manual :=
  {
    title := #[.text moduleInfo.path]
    titleString := moduleInfo.path
    metadata := some {
      file := some s!"module-{slugify moduleInfo.path}"
      tag := some (.provided moduleInfo.name.toString)
      shortTitle := some moduleInfo.path
    }
    content := #[
      .para #[
        .text "Module ",
        .code moduleInfo.name.toString,
        .text s!" contains {moduleInfo.decls.size} exposed declarations."
      ]
    ] ++ moduleInfo.decls.map (fun decl => mkDeclBlock decl repoUrl? declHrefs)
    subParts := #[]
  }

/-- Builds a trusted-base module page from declarations in that module. -/
private def mkTrustedBaseModulePart (moduleInfo : ModuleInfo) (repoUrl? : Option String)
    (declHrefs : Std.HashMap Name String) : Part Manual :=
  {
    title := #[.text moduleInfo.path]
    titleString := moduleInfo.path
    metadata := some {
      file := some s!"tfb-module-{slugify moduleInfo.path}"
      tag := some (.provided s!"tfb-{moduleInfo.name}")
      shortTitle := some moduleInfo.path
    }
    content := #[
      .para #[
        .text "Module ",
        .code moduleInfo.name.toString,
        .text s!" contributes {moduleInfo.decls.size} declarations to the trusted formalization base."
      ]
    ] ++ moduleInfo.decls.map (fun decl => mkDeclBlock decl repoUrl? declHrefs)
    subParts := #[]
  }

/-- Builds a chapter page that contains regular module pages. -/
private def mkGroupPart (group : GroupInfo) (repoUrl? : Option String)
    (declHrefs : Std.HashMap Name String) : Part Manual :=
  let title := humanizeWord group.key
  {
    title := #[.text title]
    titleString := title
    metadata := some {
      file := some s!"chapter-{slugify group.key}"
      shortTitle := some title
      tag := some (.provided group.key)
    }
    content := #[
      .para #[.text s!"Modules in the {title} slice are grouped from the first path component after the project root."]
    ]
    subParts := group.modules.map fun moduleInfo => mkModulePart moduleInfo repoUrl? declHrefs
  }

/-- Builds a chapter page for the trusted-base view. -/
private def mkTrustedBaseGroupPart (group : GroupInfo) (repoUrl? : Option String)
    (declHrefs : Std.HashMap Name String) : Part Manual :=
  let title := humanizeWord group.key
  {
    title := #[.text title]
    titleString := title
    metadata := some {
      file := some s!"tfb-chapter-{slugify group.key}"
      shortTitle := some title
      tag := some (.provided s!"tfb-{group.key}")
    }
    content := #[
      .para #[.text s!"Modules in the {title} slice that contribute declarations to the trusted formalization base."]
    ]
    subParts := group.modules.map fun moduleInfo => mkTrustedBaseModulePart moduleInfo repoUrl? declHrefs
  }

/-- Builds the top-level trusted-base section and its chapter subpages. -/
private def mkTrustedBasePart (groups : Array GroupInfo) (repoUrl? : Option String)
    (declHrefs : Std.HashMap Name String) (targetBlocks : Array (Block Manual)) : Part Manual :=
  let declCount := countDecls groups
  let moduleCount := groups.foldl (fun n group => n + group.modules.size) 0
  let intro :=
    if declCount == 0 then
      #[.para #[.text "No exposed declarations were collected into the trusted formalization base from the comparator targets."]]
    else
      #[.para #[.text s!"This view collects the {declCount} exposed declarations across {moduleCount} modules that are reachable from the comparator target theorem statements."]]
  {
    title := #[.text "Trusted Formalization Base"]
    titleString := "Trusted Formalization Base"
    metadata := some {
      file := some "trusted-base"
      shortTitle := some "TFB"
      tag := some (.provided "trusted-base")
      number := false
    }
    content := #[
        .para #[.text "These are the exposed declarations a reader must trust in order to accept the comparator-facing theorem."]
      ]
      ++ targetBlocks
      ++ intro
      ++ mkTrustedBaseIndexBlocks groups
      ++ mkDashboardBlocks groups
    subParts := groups.map fun group => mkTrustedBaseGroupPart group repoUrl? declHrefs
  }

/-- Builds the interactive dependency graph page and graph payload. -/
private def mkGraphPart (decls : Array DeclInfo) (declHrefs : Std.HashMap Name String) : Part Manual :=
  let nodes := decls.map fun decl => {
    id := decl.name.toString
    label := decl.name.getString!
    kind := decl.kind.label
    status := if decl.hasSorry then "sorry" else "proved"
    groupKey := decl.groupKey
    moduleName := decl.modulePath
    href := declHrefs.getD decl.name (pathForPart decl.groupKey decl.modulePath decl.name)
  }
  let edges := decls.foldl (fun acc decl =>
    acc ++ decl.deps.filterMap (fun dep =>
      if declHrefs.contains dep then
        some { source := decl.name.toString, target := dep.toString }
      else
        none)) #[]
  let graphData : GraphData := { nodes, edges }
  {
    title := #[.text "Dependency Graph"]
    titleString := "Dependency Graph"
    metadata := some {
      file := some "graph"
      shortTitle := some "Graph"
      tag := some (.provided "graph")
    }
    content := #[
      .para #[.text "Interactive dependency view for exposed declarations."],
      .other (Block.graph graphData) #[]
    ]
    subParts := #[]
  }

/-- Builds the root site part with chapter pages and utility sections. -/
private def mkRootPart (cfg : Cli) (rootPrefix : Name) (groups : Array GroupInfo)
    (decls : Array DeclInfo) (declHrefs : Std.HashMap Name String)
    (introBlocks : Array (Block Manual)) (readerGuideBlocks : Array (Block Manual))
    (extraParts : Array (Part Manual)) : Part Manual :=
  let title := cfg.siteTitle.getD s!"{rootPrefix} exposition"
  {
    title := #[.text title]
    titleString := title
    metadata := some {
      file := some "index"
      shortTitle := some title
      number := false
    }
    content := #[.para #[.text "Auto-generated exposition for ", .code rootPrefix.toString, .text "."]]
      ++ introBlocks
      ++ readerGuideBlocks
      ++ mkDashboardBlocks groups
    subParts := (groups.map fun group => mkGroupPart group cfg.repoUrl declHrefs)
      ++ extraParts
      ++ #[mkGraphPart decls declHrefs]
  }

/-- Runs an IO action in a temporary working directory. -/
private def withCurrentDir {α : Type} (dir : System.FilePath) (act : IO α) : IO α := do
  let cwd ← IO.Process.getCurrentDir
  IO.Process.setCurrentDir dir
  try
    act
  finally
    IO.Process.setCurrentDir cwd

/-- Loads the Lake workspace located at `projectDir`. -/
private def loadWorkspaceAt (projectDir : System.FilePath) : IO Lake.Workspace := do
  let projectDir := projectDir.normalize
  let (elanInstall?, leanInstall?, lakeInstall?) ← Lake.findInstall?
  let cfg ← Lake.MonadError.runEIO <| Lake.mkLoadConfig { elanInstall?, leanInstall?, lakeInstall? }
  let ws? ← withCurrentDir projectDir <| Lake.loadWorkspace cfg |>.toBaseIO
  match ws? with
  | some ws => pure ws
  | none => throw <| IO.userError s!"failed to load Lake workspace at {projectDir}"

/-- Computes imports for root libraries, excluding configured libraries. -/
private def importRoots (ws : Lake.Workspace) (excludeLibs : Array Name) : Array Import := Id.run do
  let mut imports := #[]
  for lib in ws.root.leanLibs do
    if excludeLibs.contains lib.name then
      continue
    for root in lib.config.roots do
      imports := imports.push { module := root }
  imports

/-- Returns the first available root module prefix after exclusions. -/
private def firstRootPrefix (ws : Lake.Workspace) (excludeLibs : Array Name) : Option Name := do
  let lib ← ws.root.leanLibs.find? fun lib => !excludeLibs.contains lib.name
  lib.config.roots[0]?

/-- Imports project modules and constructs the Lean environment. -/
private unsafe def loadEnv (projectDir : System.FilePath) (ws : Lake.Workspace) (imports : Array Import) : IO Environment := do
  enableInitializersExecution
  Lean.searchPathRef.set ws.augmentedLeanPath
  withCurrentDir projectDir <| Lean.importModules imports {}

/-- Main entry point: collects data, builds pages, and runs the renderer. -/
unsafe def mainImpl (args : List String) : IO UInt32 := do
  let cfg ←
    match parseArgs args with
    | .ok cfg => pure cfg
    | .error err =>
        IO.eprintln err
        return 1
  let ws ← loadWorkspaceAt cfg.projectDir
  let some rootPrefix := cfg.rootPrefix <|> firstRootPrefix ws cfg.excludeLibs
    | IO.eprintln "Could not determine a root module prefix. Pass --root PREFIX."
      return 1
  let imports := importRoots ws cfg.excludeLibs
  let env ← loadEnv cfg.projectDir ws imports
  let decls ← collectDecls cfg.projectDir rootPrefix ws.root env
  if decls.isEmpty then
    let namedCount :=
      env.constants.toList.foldl (fun n entry =>
        let name := entry.1
        n + if hasPrefixName name rootPrefix then 1 else 0) 0
    IO.eprintln s!"No declarations exposed under module filtering. Declarations with matching name prefix: {namedCount}"
  else
    IO.println s!"Collected {decls.size} declarations under {rootPrefix}"
  let tfbInfo ← loadTrustedBaseInfo cfg rootPrefix
  let decls := decls |> attachReverseDeps |> attachDependsOnSorry |> attachTrustedBaseFlags tfbInfo.names
  let order ← moduleOrderMap cfg.projectDir rootPrefix
  let modules := buildModules rootPrefix order decls
  let groups := buildGroups order modules
  let declHrefs := declHrefMap decls
  let (introBlocks, extraParts) ← loadProjectContextParts cfg.projectDir cfg.repoUrl
  let tfbGroups := buildGroups order <| buildModules rootPrefix order <| decls.filter (·.inTfb)
  let targetBlocks ← loadTrustedBaseTargetBlocks cfg.projectDir cfg.repoUrl tfbInfo
  let hasContext := extraParts.any fun part => part.metadata.bind PartMetadata.file == some "context"
  let extraParts :=
    if tfbInfo.comparator?.isSome then
      extraParts.push <| mkTrustedBasePart tfbGroups cfg.repoUrl declHrefs targetBlocks
    else
      extraParts
  let readerGuideBlocks := mkReaderGuideBlocks hasContext tfbInfo.comparator?.isSome
  let root := mkRootPart cfg rootPrefix groups decls declHrefs introBlocks readerGuideBlocks extraParts
  let versoArgs :=
    match cfg.outputDir with
    | some out => ["--output", out]
    | none => []
  manualMain root (options := versoArgs) (config := renderConfig tfbInfo.comparator?.isSome)

end LeanExposition
