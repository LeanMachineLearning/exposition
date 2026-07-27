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
public import VersoManual.ExternalLean
public import SubVerso.Highlighting
public import SubVerso.Module
public import LMLExposition.Collect
public import LMLExposition.Extract
public import LMLExposition.ExtractFlat
public import LMLExposition.Highlight

open Lake
open Lean
open Lean.Meta
open Verso.Doc
open Verso.Genre
open Manual

namespace LMLExposition

open Verso.Output Html
open LeanDeps
open SubVerso.Highlighting (Highlighted)

/- The exposed section opens here rather than directly under the imports so that the
`block_extension` commands below can close it and run in a plain `public section`; the `open`s above
stay in the enclosing scope and so survive that gap. -/
@[expose] public section

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

/-- Builds the module-level doc comment (`/-! ... -/` at the top of the file) as blocks, using
heading levels demoted to bold/emph text so the module page is not split into multiple pages. -/
private def moduleDocBlocks (env : Environment) (name : Name) : Array (Block Manual) :=
  match Lean.getModuleDoc? env name with
  | none => #[]
  | some docs => docs.foldl (fun acc doc => acc ++ markdownToBlocks doc.doc) #[]

/-- Builds module summaries from declarations and applies stable ordering. `moduleDocs` is the
per-module doc-comment blocks computed once (with the live environment) during `collect`. -/
private def buildModules (rootPrefix : Name) (order : Std.HashMap Name Nat)
    (moduleDocs : Std.HashMap Name (Array (Block Manual))) (decls : Array DeclInfo) :
    Array ModuleInfo :=
  let mods := moduleIndexMap decls |>.toArray.map fun (name, ds) => {
    name := name
    path := modulePathOf rootPrefix name
    groupKey := groupKeyOfModule rootPrefix name
    decls := ds
    docBlocks := moduleDocs.getD name #[]
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

/-- The visibility group a declaration belongs to, matching the "Hide Definitions" /
"Hide Lemmas" / "Hide Theorems" toggles and the `data-decl-group` attribute on its card. -/
private def declGroupOfFields (kindLabel : String) (isLemma isInstanceDecl : Bool) : String :=
  let isMainTheorem := kindLabel == "Theorem" && !isLemma && !isInstanceDecl
  if isMainTheorem then "theorem"
  else if kindLabel == "Theorem" || kindLabel == "Instance" then "lemma"
  else "definition"

/- Not `@[expose]`: `block_extension` expands to a `public def X.descr := X.descr.inner` whose body
mentions the `private` definition the macro generates alongside it. That reference only resolves
while the body stays unexposed, so these three commands sit in a plain `public section`. -/
end
public section

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
        {{<span class="decl-card-tag sorry">{{Html.text false tag}}</span>}}
    let tagsHtml :=
      if payload.tags.isEmpty then
        .empty
      else
        {{<div class="decl-card-tags">{{tags}}</div>}}
    let isMainTheorem := payload.kindLabel == "Theorem" && !payload.isLemma && !payload.isInstanceDecl
    let displayLabel := displayKindLabel payload.kindLabel payload.isLemma payload.isInstanceDecl
    let isDefinition := declGroupOfFields payload.kindLabel payload.isLemma payload.isInstanceDecl == "definition"
    let cardClass :=
      if isMainTheorem then "decl-card decl-card--theorem"
      else if isDefinition then "decl-card decl-card--definition"
      else "decl-card"
    let labelClass := if isMainTheorem then "decl-card-label decl-card-label--theorem" else "decl-card-label"
    let declGroup := declGroupOfFields payload.kindLabel payload.isLemma payload.isInstanceDecl
    pure {{
      <section class="decl-section" data-decl-kind={{payload.kindLabel}} data-card-group={{declGroup}}>
        <h2 id={{payload.anchorId}} class="decl-heading">
          <code>{{payload.shortName}}</code>
          <a class="decl-permalink" href={{s!"#{payload.anchorId}"}} title="Permalink">"🔗"</a>
        </h2>
        <div class={{cardClass}}>
          <div class="decl-card-header">
            <div class="decl-card-title">
              <span class={{labelClass}}>{{displayLabel}}</span>
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

/- A list of declarations, one per row.

Each row carries `data-decl-group`, which is what the sidebar's "Hide Definitions / Lemmas /
Theorems" controls act on. Those controls used to reach only declaration *cards*; once module
pages became listings with a single card per page, they had almost nothing left to hide. Filtering
the listings is what they were for.

(A plain comment, not a docstring: `block_extension` does not take one.) -/
block_extension Block.declIndex (_payload : DeclIndexData) where
  data := ToJson.toJson _payload
  traverse _ _ _ _ := pure none
  toTeX := some fun _goI goB _id _data contents => contents.mapM goB
  toHtml := some fun _goI _goB _id data _ => do
    let .ok (payload : DeclIndexData) := FromJson.fromJson? data
      | Verso.reportError s!"Could not decode declaration index data from {data.compress}"
        pure .empty
    let rows := payload.entries.map fun entry =>
      -- Not named `meta`: that is a keyword in the module system.
      let metaText :=
        match entry.deps with
        | some n => s!"{entry.kind} · {n} deps"
        | none => entry.kind
      let flag :=
        if entry.dependsOnSorry then
          {{<span class="decl-index-flag">"depends on sorry"</span>}}
        else .empty
      {{
        <li class="decl-index-item" data-decl-group={{entry.group}}>
          <a class="decl-index-name" href={{entry.href}}><code>{{entry.name}}</code></a>
          <span class="decl-index-meta">{{metaText}}</span>
          {{flag}}
        </li>
      }}
    pure {{<ul class="decl-index">{{rows}}</ul>}}

/- A heading inside a page's content.

Verso's `Block` has no heading constructor — document structure comes from `Part`s, and the
markdown renderer demotes headings to bold text so that a docstring cannot split a page. This is
for the few headings the site writes itself, where a real `<h2>` is wanted. -/
block_extension Block.sectionHeading (_payload : String) where
  data := ToJson.toJson _payload
  traverse _ _ _ _ := pure none
  toTeX := some fun _goI goB _id _data contents => contents.mapM goB
  toHtml := some fun _goI _goB _id data _ => do
    let .ok (title : String) := FromJson.fromJson? data
      | Verso.reportError s!"Could not decode heading from {data.compress}"
        pure .empty
    pure {{<h2 class="site-heading">{{title}}</h2>}}

/- The Browse table.

Only the mount point and the data are emitted; `browse.js` builds the table. Sorting and filtering
over the whole library have to happen in the browser — Verso renders static HTML, so there is no
server to ask — and shipping rows as JSON rather than as markup keeps the page a good deal smaller
than the equivalent `<tr>`s would be. -/
block_extension Block.browseTable (_payload : BrowseData) where
  data := ToJson.toJson _payload
  traverse _ _ _ _ := pure none
  toTeX := some fun _goI goB _id _data contents => contents.mapM goB
  toHtml := some fun _goI _goB _id data _ => do
    let .ok (payload : BrowseData) := FromJson.fromJson? data
      | Verso.reportError s!"Could not decode browse data from {data.compress}"
        pure .empty
    pure {{
      <div id="browse-root">
        <noscript>"The Browse table needs JavaScript. Every declaration is also reachable from its
          module page."</noscript>
      </div>
      {{Html.tag "script" #[("id", "browse-data"), ("type", "application/json")]
          (.text false (ToJson.toJson payload).compress)}}
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

end
@[expose] public section

/-- The README text up to, but not including, a "Selected References" heading at any level.

A bibliography is the one part of a README that reads as noise on a generated exposition page,
and long enough to bury everything above it. -/
private def readmeUpToReferences (readme : String) : String :=
  let isReferencesHeading (line : String) : Bool :=
    let trimmed := (String.trimAscii line).toString
    let stripped := (String.trimAscii (trimmed.dropWhile (· == '#')).toString).toString
    trimmed.startsWith "#" && stripped == "Selected References"
  String.intercalate "\n" (readme.splitOn "\n" |>.takeWhile (!isReferencesHeading ·))

/-- Builds the project-overview section of the landing page from the README. Pure (the README text
is read once during `collect` and threaded through `CollectedData`), so `build-site` needs no
access to the project directory.

There is deliberately no separate "Overview" page. There used to be, and it rendered the same
`overview.body` the landing page already showed — 97% of its text was a duplicate, its only
addition being the link to `README.md`, which now sits under the heading here. -/
private def mkProjectOverviewBlocks (readmeText : Option String) (repoUrl? : Option String) :
    Array (Block Manual) := Id.run do
  let some readme := readmeText | return #[]
  -- The whole README, not its first section. This used to render only the text preceding the
  -- first `##` heading, which happened to be the entire file for a README that uses `#` and `###`
  -- but nothing in between — and was almost empty for one organised with `##`, where it captured
  -- only a stray `<div align="center">`.
  let body := readmeUpToReferences readme
  if body.trimAscii.isEmpty then return #[]
  #[.other (Block.sectionHeading "Project overview") #[]]
    ++ mkSourceParagraph "README.md" (repoFileUrlOf repoUrl? "README.md")
    ++ markdownToBlocks body


/-- D3, vendored rather than fetched from `d3js.org` at page load.

A site whose purpose is to let a reader verify a body of mathematics should not depend on a third
party being reachable — nor hand that third party a request log of who is reading what. Emitted
once as a file (not inlined per page: it is 280 KB and there are thousands of pages). BSD-3-Clause;
see `assets/d3.LICENSE`. -/
private def d3JsFile : JsFile where
  filename := "d3.v7.min.js"
  contents := JS.mk (include_str "assets/d3.v7.min.js")
  sourceMap? := none

/-! The site's own CSS and JS are emitted as **files** rather than inlined into every page.

Two reasons. Inlining put ~29 KB of identical CSS and JavaScript into each of several thousand
pages — around 100 MB of pure duplication for brownian-motion, and nothing the browser could
cache between pages. And it made iterating on style absurd: changing a margin meant rebuilding the
executable and re-rendering the whole site, minutes for a one-character edit. As files, the same
edit is `scripts/sync-assets.sh <site>` and a reload. -/

private def expositionCssFile : CssFile where
  filename := "exposition.css"
  contents := CSS.mk (include_str "assets/exposition.css")

private def graphJsFile : JsFile where
  filename := "graph.js"
  contents := JS.mk (include_str "assets/graph.js")
  sourceMap? := none
  -- `graph.js` reads the `d3` global at load time, so it must come after it.
  after := #["d3.v7.min.js"]

/-- Applies the reader's stored light/dark choice to `<html>` before the page paints. -/
private def themeBootJs : String :=
  "try{var t=localStorage.getItem('lean-exposition:theme');\
   if(t==='dark'||t==='light')document.documentElement.setAttribute('data-theme',t);}catch(e){}"

private def tocJsFile : JsFile where
  filename := "toc.js"
  contents := JS.mk (include_str "assets/toc.js")
  sourceMap? := none

private def browseJsFile : JsFile where
  filename := "browse.js"
  contents := JS.mk (include_str "assets/browse.js")
  sourceMap? := none

/-- Rendering configuration for the exposition site output. -/
private def renderConfig : RenderConfig :=
  {
    emitTeX := false
    emitHtmlSingle := .no
    emitHtmlMulti := .immediately
    -- 4, not 3: chapter → module → declaration → its minimal file. Without the extra level the
    -- minimal file would be inlined into the declaration page, which is precisely what its size
    -- rules out (see `mkMinimalFileLink`).
    htmlDepth := 4
    -- Both 0, so Verso emits no automatic sub-page table of contents anywhere. Every page that has
    -- sub-pages already lists them in a form that carries more information: the landing page has
    -- its claims and per-chapter breakdown, module pages list declarations with their kind,
    -- dependency count and trust flag, chapter pages list modules with their declaration counts,
    -- and a declaration page links its minimal file in context. The automatic list only repeated
    -- those, immediately below them. The sidebar carries the same navigation on every page.
    rootTocDepth := some 0
    sectionTocDepth := some 0
    extraCssFiles := {expositionCssFile}
    extraJsFiles := {d3JsFile, graphJsFile, tocJsFile, browseJsFile}
    -- Inline and in `<head>`, so the stored theme is applied before the first paint. Loading this
    -- as a file would let the light theme flash before the script ran.
    extraHead := #[Html.tag "script" #[] (.text false themeBootJs)]
  }

/-- Counts declarations in each visibility group, as `(definitions, lemmas, theorems)`. -/
private def countGroups (decls : Array DeclInfo) : Nat × Nat × Nat :=
  decls.foldl (fun (defs, lemmas, thms) decl =>
    match declGroupOfFields decl.kind.label decl.isLemma decl.isInstanceDecl with
    | "definition" => (defs + 1, lemmas, thms)
    | "lemma" => (defs, lemmas + 1, thms)
    | _ => (defs, lemmas, thms + 1)
  ) (0, 0, 0)

/-- Renders a `(definitions, lemmas, theorems)` count as a summary string. -/
private def groupCountsLabel (counts : Nat × Nat × Nat) : String :=
  let (defs, lemmas, thms) := counts
  s!"{defs} definitions, {lemmas} lemmas, {thms} theorems"

/-- Builds dashboard summary blocks for chapter and module progress. -/
private def mkDashboardBlocks (groups : Array GroupInfo) : Array (Block Manual) :=
  groups.foldl (fun acc group =>
    let groupCounts := group.modules.foldl (fun (defs, lemmas, thms) modInfo =>
      let (d, l, t) := countGroups modInfo.decls
      (defs + d, lemmas + l, thms + t)) (0, 0, 0)
    let intro : Block Manual :=
      .para #[
        .bold #[.link #[.text <| humanizeWord group.key] (groupHrefOf group.key)],
        .text s!"  ({groupCountsLabel groupCounts})"
      ]
    let items := group.modules.map fun modInfo =>
      Verso.Doc.ListItem.mk #[
        .para #[
          .link #[.code modInfo.path] s!"{groupHrefOf group.key}{moduleHrefOf modInfo.path}",
          .text s!"  ({groupCountsLabel (countGroups modInfo.decls)})"
        ]
      ]
    acc ++ #[intro, .ul items]
  ) #[]

/-- Truncates `s` to at most `n` characters, marking the cut so a reader knows there is more. -/
private def clipText (n : Nat) (s : String) : String :=
  let s := (String.trimAscii s).toString
  if s.length ≤ n then s else (s.take n).trimAscii.toString ++ "…"

/-- Reads the per-module highlighting JSON written by `highlight` and indexes it by the names
each command defines, so a declaration can be rendered as interactive Lean rather than as inert
text.

Missing or unreadable files are not an error: `build-site` must keep working without a
`highlight` pass, falling back to plain code blocks. Each module's JSON is decoded and reduced to
the entries we keep before moving to the next, since the whole corpus is far larger than the part
that is actually referenced. -/
private def loadHighlighting (dir : System.FilePath) : IO (Std.HashMap Name Highlighted) := do
  if !(← dir.pathExists) then
    return {}
  let mut acc : Std.HashMap Name Highlighted := {}
  for entry in (← dir.readDir) do
    if entry.path.extension != some "json" then
      continue
    let some result ← (do
        let text ← IO.FS.readFile entry.path
        let .ok json := Json.parse text | return none
        let .ok (r : Highlight.FileHighlighting) := Highlight.FileHighlighting.fromJson? json
          | return none
        return some r)
      | IO.eprintln s!"warning: could not read highlighting from {entry.path}"
        continue
    for item in result.items do
      for name in item.defines do
        acc := acc.insert name item.code
  return acc

/-- Renders highlighted Lean source as a block, or falls back to a plain code block when the
declaration has no highlighting (no `highlight` pass was run, or its module failed).

`defSite := false` matters: the same declaration is shown on many pages — its own, and every page
whose closure inlines it — and letting each occurrence register as a definition site would
produce duplicate cross-reference tags. -/
private def leanCodeBlock (hl? : Option Highlighted) (fallback : String) : Block Manual :=
  match hl? with
  | some hl => .other (Block.lean hl { showProofStates := false, defSite := some false }) #[]
  | none => .code fallback

/-- A minimal file's highlighted rendering plus whether it compiled. -/
private structure MinimalFile where
  code : Highlighted
  errors : Array String

/-- Reads the highlighting of the extracted minimal files written by `highlight-extracted`,
keyed by the `anchorIdOf` stem the extraction used.

The whole file is rendered as one `Highlighted` — the concatenation of its commands, which
reproduces the source including comments and blank lines, because `FrontendResult.updateLeading`
attaches the surrounding trivia to the commands. -/
private def loadMinimalFiles (dir : System.FilePath) :
    IO (Std.HashMap String MinimalFile) := do
  if !(← dir.pathExists) then
    return {}
  let mut acc : Std.HashMap String MinimalFile := {}
  for entry in (← dir.readDir) do
    if entry.path.extension != some "json" then
      continue
    let some stem := entry.path.fileStem | continue
    let some result ← (do
        let text ← IO.FS.readFile entry.path
        let .ok json := Json.parse text | return none
        let .ok (r : Highlight.FileHighlighting) := Highlight.FileHighlighting.fromJson? json
          | return none
        return some r)
      | IO.eprintln s!"warning: could not read minimal-file highlighting from {entry.path}"
        continue
    acc := acc.insert stem {
      code := .seq (result.items.map (·.code))
      errors := result.errors
    }
  return acc

/-- Shared lookup tables and configuration threaded through page-building helpers. -/
private structure SiteContext where
  repoUrl? : Option String
  siteUrl? : Option String
  declByName : Std.HashMap Name DeclInfo
  declHrefs : Std.HashMap Name String
  declPageHrefs : Std.HashMap Name String
  /-- Declaration name ↦ highlighted source, empty when no `highlight` pass was run. -/
  declHighlights : Std.HashMap Name Highlighted := {}
  /-- `anchorIdOf` stem ↦ the declaration's minimal file, empty without `highlight-extracted`. -/
  minimalFiles : Std.HashMap String MinimalFile := {}

/-- Renders one declaration card with docs, statement, links, and dependencies.

Rendered on the declaration's own page and nowhere else: module pages, the claims page and the
trust page all list declarations compactly instead. The card therefore carries no "Details" link —
it used to, and once the module pages stopped showing cards it pointed at the page it was already
on. -/
private def mkDeclBlock (decl : DeclInfo) (ctx : SiteContext) : Block Manual :=
  Id.run do
    let issueUrl := issueUrlOf ctx.repoUrl? decl.name decl.moduleName decl.source? decl.dependsOnSorry
    let sourceUrl := sourceUrlOf ctx.repoUrl? decl.source?
    let mkLinks (deps : Array Name) := deps.filterMap fun dep =>
      ctx.declHrefs.get? dep |>.map fun href => { label := dep.getString!, href? := some href }
    let typeDepLinks := mkLinks decl.typeDeps
    let proofDepLinks := mkLinks <| decl.deps.filter (!decl.typeDeps.contains ·)
    let usedByLinks := mkLinks decl.usedBy
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
    let showsBody :=
      match decl.kind with
      | .definition | .structure | .typeclass | .inductive => true
      | _ => false
    blocks := blocks.push <|
      if showsBody then leanCodeBlock (ctx.declHighlights.get? decl.name) decl.displaySignature
      else .code decl.displaySignature
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
      isLemma := decl.isLemma
      isInstanceDecl := decl.isInstanceDecl
      fullName := decl.name.toString
      tags := #[
        if decl.dependsOnSorry then some "depends transitively on sorry" else none
      ].filterMap id
    }
    .other (Block.declCard cardData) blocks

/-- Builds graph nodes/edges for `decls`, with edges only between declarations that are
themselves in `decls`. Each edge points from a dependency (the "parent") to the declaration
that depends on it (the "child"), so the arrow direction follows the order in which the
declarations must be established. `depsOf` picks which dependency set each edge follows: pass
`graphDeps` (type-only for theorems) on declaration detail pages, to match their transitive
closure, or `(·.deps)` (always type + body) for the full-repository graph. -/
private def mkGraphData (decls : Array DeclInfo) (declHrefs : Std.HashMap Name String)
    (depsOf : DeclInfo → Array Name) (focus? : Option Name := none) : GraphData :=
  let names : Std.HashSet Name := decls.foldl (fun acc d => acc.insert d.name) {}
  let nodes := decls.map fun decl => {
    id := decl.name.toString
    label := decl.name.getString!
    kind := decl.kind.label
    status := if decl.dependsOnSorry then "sorry" else "proved"
    groupKey := decl.groupKey
    moduleName := decl.modulePath
    -- Root-relative, with no `../` prefix: Verso emits a `<base href>` on every page pointing at
    -- the site root, so every relative href on the page — including these, which reach the DOM
    -- through JSON rather than through Verso's link handling — resolves from the root already.
    href := declHrefs.getD decl.name (pathForPart decl.groupKey decl.modulePath decl.name)
    focus := focus? == some decl.name
    -- Clipped: this rides along in every node of every graph, and a handful of declarations carry
    -- very long statements or docstrings. The panel is a preview; the page has the whole thing.
    signature := clipText 600 decl.displaySignature
    doc := clipText 600 (decl.docText?.getD "")
  }
  let edges := decls.foldl (fun acc decl =>
    acc ++ (depsOf decl).filterMap (fun dep =>
      if names.contains dep then
        some { source := dep.toString, target := decl.name.toString }
      else
        none)) #[]
  { nodes, edges }

/-- All nodes reachable from `start` via one or more edges of `adj`, tolerant of cycles (a node
already on the current path contributes nothing further rather than looping forever). Threads a
`cache` of already-computed results so repeated queries for the same node (common when many edges
share a source) are O(1) after the first. -/
private partial def reachableFrom (adj : Std.HashMap String (Array String))
    (cache : Std.HashMap String (Std.HashSet String)) (onPath : Std.HashSet String) (n : String) :
    Std.HashSet String × Std.HashMap String (Std.HashSet String) :=
  match cache.get? n with
  | some reached => (reached, cache)
  | none =>
    if onPath.contains n then
      ({}, cache)
    else
      let onPath := onPath.insert n
      let (reached, cache) := (adj.getD n #[]).foldl
        (init := (({} : Std.HashSet String), cache))
        (fun (reached, cache) m =>
          let reached := reached.insert m
          let (sub, cache) := reachableFrom adj cache onPath m
          (sub.fold (init := reached) (·.insert ·), cache))
      (reached, cache.insert n reached)

/-- Drops every edge that is implied by a longer path through other edges, the standard
transitive reduction of a DAG (tolerant of the rare dependency cycle). Meant for the full
dependency-graph page only: per-declaration graphs are already small, and keeping every direct
edge there makes each one exact (`A → B` always means `A` is a *direct* dependency of `B`). -/
private def transitiveReduce (data : GraphData) : GraphData :=
  let adj : Std.HashMap String (Array String) :=
    data.edges.foldl (fun acc e => acc.insert e.source ((acc.getD e.source #[]).push e.target)) {}
  let cache := data.nodes.foldl
    (fun cache n => (reachableFrom adj cache {} n.id).2)
    ({} : Std.HashMap String (Std.HashSet String))
  let edges := data.edges.filter fun e =>
    let siblings := adj.getD e.source #[]
    !siblings.any fun w => w != e.target && (cache.getD w {}).contains e.target
  { data with edges := edges }

/-! ## Audit surface and trust

The numbers and chains a reader needs in order to decide how much of a result they are being
asked to take on faith, rather than merely whether it is flagged. -/

/-- The distinct constants outside the project that a declaration's closure bottoms out in: its
imported assumptions, as opposed to the project declarations it builds on. Together with the
closure size this is the "how much must I accept to believe this" measure. -/
private def externalConstants (decl : DeclInfo) (ctx : SiteContext) : Array Name :=
  let closure := #[decl.name] ++ decl.transDeps
  let externals := closure.foldl (init := ({} : Std.HashSet Name)) fun acc name =>
    match ctx.declByName.get? name with
    | none => acc
    | some d => (graphDeps d).foldl (init := acc) fun acc dep =>
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
        for dep in graphDeps d do
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

/-- A compact one-line-per-entry listing of dependencies.

The reason this is not a list of cards: closures here reach 522 declarations, and rendering a full
card each produced 176k cards across the corpus and pages averaging 454 KB. A reader scanning a
closure wants names, kinds, and whether anything is flagged; the full statement is one click, or
in the minimal file. -/
private def compactDepList (names : Array Name) (ctx : SiteContext) : Option (Block Manual) :=
  let entries := names.filterMap fun name => do
    let d ← ctx.declByName.get? name
    let href ← ctx.declPageHrefs.get? name
    pure {
      name := name.toString
      href := href
      kind := d.displayKind
      group := declGroupOfFields d.kind.label d.isLemma d.isInstanceDecl
      dependsOnSorry := d.dependsOnSorry
      : DeclIndexEntry
    }
  if entries.isEmpty then none else some (.other (Block.declIndex { entries }) #[])

/-- Number of project declarations in a declaration's closure. Used both as the audit-surface
measure and to rank claims: among results nothing else builds on, the one resting on the most
machinery is usually the substantial one. -/
private def closureSize (decl : DeclInfo) (ctx : SiteContext) : Nat :=
  (decl.transDeps.filter ctx.declByName.contains).size

/-- A list of declarations rendered one per line with closure size, module, and trust status. The
workhorse index rendering: used for module contents, claims, and the trust checklist. -/
private def declIndexList (decls : Array DeclInfo) (ctx : SiteContext) : Option (Block Manual) :=
  let entries := decls.filterMap fun decl => do
    let href ← ctx.declPageHrefs.get? decl.name
    pure {
      name := decl.name.toString
      href := href
      kind := decl.displayKind
      group := declGroupOfFields decl.kind.label decl.isLemma decl.isInstanceDecl
      deps := some (closureSize decl ctx)
      dependsOnSorry := decl.dependsOnSorry
      : DeclIndexEntry
    }
  if entries.isEmpty then none else some (.other (Block.declIndex { entries }) #[])

/-- The audit-surface and trust summary shown near the top of a declaration page. -/
private def mkAuditBlocks (decl : DeclInfo) (ctx : SiteContext) : Array (Block Manual) :=
  Id.run do
  let externals := externalConstants decl ctx
  let inProject := decl.transDeps.filter ctx.declByName.contains
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
  if !unusual.isEmpty then
    blocks := blocks.push <| .para <|
      #[.bold #[.text "Extra axioms: "]] ++
        joinInlines (unusual.toList.map fun a => #[.code a.toString]) #[.text " · "]
  return blocks

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
        tag := some (.provided s!"minimal-{asciiTagOf decl.name}")
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

/-- The declaration-page pointer to its minimal file.

The file itself is a separate page rather than inline. That is a concession to size, not a change
of intent: highlighting carries a pretty-printed type for every token, which measured **46×** the
size of the Lean source it describes (10 MB of extracted files became 478 MB of highlighting).
Inlining that on every declaration page would have undone the page-size work entirely. One click,
on-site, fully interactive is the affordable version of "the minimal file is the point". -/
private def mkMinimalFileLink (decl : DeclInfo) (ctx : SiteContext) : Array (Block Manual) :=
  match ctx.minimalFiles.get? (anchorIdOf decl.name) with
  | none => #[]
  | some file =>
    let note :=
      if file.errors.isEmpty then
        #[.text " — self-contained, with types on hover; verified to compile."]
      else
        #[.text " — self-contained, with types on hover. ",
          .bold #[.text "⚠ does not currently compile"], .text "."]
    -- Both links are root-relative, because Verso puts a `<base href>` on every page pointing at
    -- the site root. A bare `minimal/` therefore resolved to `<root>/minimal/` — which is why this
    -- link led nowhere — rather than to the subpage of the declaration it is written on.
    let pageUrl := (ctx.declPageHrefs.getD decl.name "") ++ "minimal/"
    let rawUrl :=
      match ctx.siteUrl? with
      | some base => leanEditorUrl base decl.name
      | none => s!"extracted/{anchorIdOf decl.name}.lean"
    let rawLabel := if ctx.siteUrl?.isSome then "open in the Lean web editor" else "download the raw file"
    #[.para <| #[.link #[.bold #[.text "Read the minimal Lean file"]] pageUrl] ++ note
        ++ #[.text " Or ", .link #[.text rawLabel] rawUrl, .text "."]]

/-- Builds a dedicated detail page for one declaration: its own card, its audit surface and trust
summary, its local dependency graph, and compact listings of what it rests on.

Deliberately *not* a card per transitive dependency, which is what the previous version rendered:
see `compactDepList`. -/
private def mkDeclPart (decl : DeclInfo) (ctx : SiteContext) : Part Manual :=
  Id.run do
  let pageDecls := #[decl] ++ (decl.transDeps.filterMap ctx.declByName.get?)
  -- The minimal file is linked once, from `mkMinimalFileLink` below. There used to be a second
  -- link here whose relative path resolved *underneath* the declaration page and 404'd, and the
  -- page ended up advertising the same artifact three times.
  let mut blocks : Array (Block Manual) := #[]
  blocks := blocks.push (mkDeclBlock decl ctx)
  blocks := blocks ++ mkAuditBlocks decl ctx
  blocks := blocks ++ mkMinimalFileLink decl ctx
  if pageDecls.size > 1 then
    blocks := blocks.push (.para #[.bold #[.text "Dependency graph"]])
    -- Transitively reduced: 23 declarations here carry 68 direct edges, most of them implied by a
    -- longer path, and drawing all of them buries the structure in crossings and forces the layout
    -- so wide that it no longer fits the viewport. What survives is the *essential* dependency
    -- structure — every removed edge is still a real dependency, reachable along the path that
    -- remains.
    blocks := blocks.push (.other (Block.graph (transitiveReduce
      (mkGraphData pageDecls ctx.declPageHrefs graphDeps (focus? := decl.name)))) #[])
  -- Layer 2 of the audit: what the *statement* mentions. This is where "does this say what I
  -- think it says" is decided, so it is shown expanded and before the rest of the closure.
  let directTypeDeps := decl.typeDeps.filter ctx.declByName.contains
  if let some block := compactDepList directTypeDeps ctx then
    blocks := blocks.push
      (.para #[.bold #[.text s!"Its statement mentions ({directTypeDeps.size})"]])
    blocks := blocks.push block
  -- Layer 3: everything else it rests on. Affects trust rather than meaning, so it is folded.
  let rest := decl.transDeps.filter fun n =>
    ctx.declByName.contains n && !directTypeDeps.contains n
  if let some block := compactDepList rest ctx then
    blocks := blocks.push <|
      .other (Block.details { summary := s!"Everything it rests on ({rest.size})" }) #[block]
  return {
    title := #[.code decl.name.toString]
    titleString := decl.name.toString
    metadata := some {
      file := some s!"decl-{anchorIdOf decl.name}"
      shortTitle := some decl.name.getString!
      -- Explicit, so Verso does not derive a tag from the title: names differing only by a
      -- non-ASCII character (`induction_on₂` vs `induction_on₃`) derive the same one.
      tag := some (.provided (asciiTagOf decl.name))
      number := false
    }
    content := blocks
    subParts := (mkMinimalFilePart decl ctx).toArray
  }

/-- Builds a module page from its declarations. -/
private def mkModulePart (moduleInfo : ModuleInfo) (ctx : SiteContext) : Part Manual :=
  {
    title := #[.text moduleInfo.path]
    titleString := moduleInfo.path
    metadata := some {
      file := some s!"module-{slugify moduleInfo.path}"
      tag := some (.provided moduleInfo.name.toString)
      shortTitle := some moduleInfo.path
    }
    -- An index, not a transcript: one line per declaration rather than a full card each. Cards
    -- here duplicated every declaration page and made the largest module pages several megabytes.
    content := moduleInfo.docBlocks ++ #[
      .para #[
        .text "Module ",
        .code moduleInfo.name.toString,
        .text s!" contains {moduleInfo.decls.size} exposed declarations."
      ]
    ] ++ (declIndexList moduleInfo.decls ctx).toArray
    subParts := moduleInfo.decls.map (fun decl => mkDeclPart decl ctx)
  }

/-- A chapter's modules as a dependency graph: one node per module, and an edge from a module to
each module that uses something it declares.

The aggregate a human actually named. A graph over every declaration is unreadable at library
scale, but there are only tens of modules, and the question "in what order do I read this chapter"
is one the module graph answers and no other view does. -/
private def mkModuleGraphData (modules : Array ModuleInfo) (ctx : SiteContext) : GraphData :=
  let paths : Std.HashSet String := modules.foldl (fun acc m => acc.insert m.path) {}
  let nodes : Array GraphNode := modules.map fun modInfo =>
    let sorried := (modInfo.decls.filter (·.dependsOnSorry)).size
    let summary :=
      if sorried == 0 then s!"{modInfo.decls.size} declarations, all proved"
      else s!"{modInfo.decls.size} declarations; {sorried} depend on sorry"
    -- Each label drops its own chapter prefix. On a chapter page every node shares it, so it is
    -- pure width; across the project the chapter is already carried by the node's colour and by
    -- the side panel, and the full paths are long enough to shrink the whole drawing.
    let label :=
      (modInfo.path.dropPrefix? s!"{modInfo.groupKey}.").map (·.toString) |>.getD modInfo.path
    { id := modInfo.path
      label := label
      kind := "Module"
      status := if sorried > 0 then "sorry" else "proved"
      groupKey := modInfo.groupKey
      moduleName := modInfo.path
      href := s!"{groupHrefOf modInfo.groupKey}{moduleHrefOf modInfo.path}"
      doc := summary }
  let edges := modules.foldl (init := #[]) fun acc modInfo =>
    let sources := modInfo.decls.foldl (init := ({} : Std.HashSet String)) fun acc decl =>
      (graphDeps decl).foldl (init := acc) fun acc dep =>
        match ctx.declByName.get? dep with
        | some d => if d.modulePath != modInfo.path && paths.contains d.modulePath then
            acc.insert d.modulePath
          else acc
        | none => acc
    acc ++ sources.toArray.map fun src => { source := src, target := modInfo.path }
  { nodes, edges, unit := "module" }

/-- Drops the modules that take no part in any dependency, so a graph is not padded with isolated
boxes. Returns the reduced graph and how many nodes were dropped. -/
private def connectedOnly (graph : GraphData) : GraphData × Nat :=
  let connected : Std.HashSet String :=
    graph.edges.foldl (fun acc e => (acc.insert e.source).insert e.target) {}
  let kept := graph.nodes.filter (connected.contains ·.id)
  ({ graph with nodes := kept }, graph.nodes.size - kept.size)

/-- Builds a chapter page that contains regular module pages. -/
private def mkGroupPart (group : GroupInfo) (ctx : SiteContext) : Part Manual :=
  let title := humanizeWord group.key
  {
    title := #[.text title]
    titleString := title
    metadata := some {
      file := some s!"chapter-{slugify group.key}"
      shortTitle := some title
      tag := some (.provided group.key)
    }
    -- Lists its modules itself rather than leaving that to Verso's automatic sub-page table of
    -- contents, which is switched off (see `renderConfig`) because on every other page it merely
    -- repeated a listing the page had already made.
    content := Id.run do
      let mut blocks : Array (Block Manual) := #[
        .para #[.text s!"Modules in the {title} slice are grouped from the first path component after the project root."],
        .ul <| group.modules.map fun moduleInfo =>
          Verso.Doc.ListItem.mk #[.para #[
            .link #[.code moduleInfo.path] s!"{groupHrefOf group.key}{moduleHrefOf moduleInfo.path}",
            .text s!"  {moduleInfo.decls.size} declarations"
          ]]
      ]
      -- Only worth drawing when the modules actually depend on one another; a chapter whose
      -- modules are independent would render as a single row of disconnected boxes.
      -- Only the modules that take part. `Auxiliary` has 33 modules and 5 dependencies among
      -- them, so drawing every node would bury the structure in 28 isolated boxes. The full list
      -- is directly above; this is the part of it that has an order.
      let (graph, omitted) :=
        connectedOnly (transitiveReduce
          (mkModuleGraphData group.modules ctx))
      if !graph.edges.isEmpty then
        blocks := blocks.push (.other (Block.sectionHeading "Module dependencies") #[])
        if omitted > 0 then
          blocks := blocks.push (.para #[.text s!"Showing the {graph.nodes.size} modules that \
            depend on one another. The other {omitted} are independent of the rest of the chapter."])
        blocks := blocks.push (.other (Block.graph graph) #[])
      return blocks
    subParts := group.modules.map fun moduleInfo => mkModulePart moduleInfo ctx
  }

/-! There is deliberately no whole-repository graph page.

A single picture of 1677 declarations is unreadable at any zoom and answers no question a reader
actually has — it was decoration. What replaced it is the per-declaration graph on each declaration
page, which is small enough to read and scoped to a question worth asking ("what does *this* rest
on"), plus the claims and trust pages for whole-library questions. -/

/-! ## Claims, assumptions, and trust

The three views a referee actually needs, none of which the chapter/module hierarchy provides:
what the library asserts, what it takes for granted, and where it is incomplete. -/

/-- The library's claims: everything written with the `theorem` keyword.

This reads the author's own signal. Mathlib-style convention distinguishes `theorem` — a result
worth stating for its own sake — from `lemma`, which marks a step towards one; `LMLExposition`
takes that distinction at face value, so what a project puts on this page is decided by how it
writes its declarations.

An earlier version instead derived claims from the dependency graph, treating "nothing else in the
library uses it" as the mark of a result rather than of machinery. That premise is wrong in both
directions: a headline theorem reused by one corollary silently stops being a claim, while a lemma
proved during some general API build-out and never used again becomes one.

`LeanMachineLearning`, which is careful about the two keywords, shows what each rule produces. It
states 11 of its 698 declarations as theorems, and they are precisely the point of the library —
the Thompson-sampling, explore-then-commit and UCB regret bounds at the top. The dependency-graph
rule dropped 6 of those 11 for the sole reason that something else used them once.

The corollary for a *reader*: this page inherits the project's discipline. A library that writes
`theorem` everywhere gets a page that says "all results", which is still true, just less useful. -/
private def claimsOf (decls : Array DeclInfo) : Array DeclInfo :=
  decls.filter fun d => d.kind == .theorem && !d.isLemma && !d.isInstanceDecl

/-- Builds the page listing every claim, grouped by chapter. -/
private def mkClaimsPart (decls : Array DeclInfo) (ctx : SiteContext) : Part Manual :=
  Id.run do
  let claims := claimsOf decls
  let byGroup := claims.foldl (init := ({} : Std.HashMap String (Array DeclInfo)))
    fun acc decl => acc.insert decl.groupKey ((acc.getD decl.groupKey #[]).push decl)
  let mut blocks : Array (Block Manual) := #[
    .para #[
      .text "These are the declarations written with the ", .code "theorem", .text " keyword, as \
        opposed to ", .code "lemma", .text ". The distinction is the author's own: by the usual \
        convention a ", .code "theorem", .text " is a result worth stating for its own sake, \
        while a ", .code "lemma", .text " is a step towards one. This page takes that convention \
        at face value."
    ],
    .para #[
      .bold #[.text "So this list is only as good as the library's discipline about the two \
        keywords."], .text " Where a project uses them interchangeably, read this as \"all \
        results\" rather than as a statement of intent."
    ],
    .para #[.text s!"{claims.size} of {decls.size} declarations are stated as theorems, \
      ranked within each chapter by how much machinery they rest on."]
  ]
  for (key, groupClaims) in byGroup.toArray.qsort (fun a b => a.1 < b.1) do
    let sorted := groupClaims.qsort fun a b => closureSize a ctx > closureSize b ctx
    blocks := blocks.push <| .para #[.bold #[.text (humanizeWord key)]]
    if let some list := declIndexList sorted ctx then
      blocks := blocks.push list
  return {
    title := #[.text "What This Library Claims"]
    titleString := "What This Library Claims"
    metadata := some {
      file := some "claims"
      shortTitle := some "Claims"
      tag := some (.provided "claims")
      number := false
    }
    content := blocks
    subParts := #[]
  }

/-- Builds the Browse page: every declaration in one sortable, filterable table.

The uncurated entry point. Claims and Trust are curated views for readers who know what they are
after; this is for the reader who does not, and it is the only page that answers questions cutting
across the module hierarchy — which theorems rest on the least machinery, what is in a chapter that
is not a lemma, what is `sorry`-free below some closure size. -/
private def mkBrowsePart (decls : Array DeclInfo) (ctx : SiteContext) : Part Manual :=
  let ordinary : Array Name := #[``Classical.choice, ``propext, ``Quot.sound]
  let rows := decls.filterMap fun decl => do
    let href ← ctx.declPageHrefs.get? decl.name
    pure {
      name := decl.name.toString
      href := href
      kind := decl.displayKind
      group := declGroupOfFields decl.kind.label decl.isLemma decl.isInstanceDecl
      module := decl.modulePath
      chapter := humanizeWord decl.groupKey
      deps := closureSize decl ctx
      ext := (externalConstants decl ctx).size
      dependsOnSorry := decl.dependsOnSorry
      extraAxioms := decl.axioms.any fun a => !ordinary.contains a && a != ``sorryAx
      : BrowseRow
    }
  {
    title := #[.text "Browse"]
    titleString := "Browse"
    metadata := some {
      file := some "browse"
      shortTitle := some "Browse"
      tag := some (.provided "browse")
      number := false
    }
    content := #[
      .para #[.text s!"Every one of the {decls.size} exposed declarations. Sort by any column, \
        and filter by kind, chapter, trust, or name."],
      .para #[
        .text "“Deps” counts the project declarations in a declaration's closure and “External” \
          the distinct constants outside the project it bottoms out in — together, how much a \
          reader must accept in order to believe it. Sorting by them ascending finds the results \
          that are cheapest to audit."
      ],
      .other (Block.browseTable { rows }) #[]
    ]
    subParts := #[]
  }

/-- Builds the Modules page: the whole project's module dependency graph.

The one aggregate view that survives at library scale. A graph over every declaration is a
hairball — that page was removed — but a project has tens of modules, not thousands, and this is
the only view that shows structure *across* chapters, where the interesting dependencies are: in
`LeanMachineLearning` half the module dependencies cross a chapter boundary, and the per-chapter
graphs cannot show any of them. -/
private def mkModulesPart (groups : Array GroupInfo) (ctx : SiteContext) : Part Manual :=
  let modules := groups.flatMap (·.modules)
  let (graph, omitted) := connectedOnly (transitiveReduce (mkModuleGraphData modules ctx))
  let intro : Array (Block Manual) := #[
    .para #[.text s!"How the project's {modules.size} modules depend on one another. Colour marks \
      the chapter, so the blocks of colour are the chapter structure and the edges between them \
      are where it is crossed."],
    .para #[.text "An edge means some declaration in the lower module uses something declared in \
      the upper one. Edges implied by a longer path are not drawn."]
  ]
  let note : Array (Block Manual) :=
    if omitted == 0 then #[]
    else #[.para #[.text s!"Showing the {graph.nodes.size} modules that depend on one another; \
      the other {omitted} are independent of the rest of the project."]]
  {
    title := #[.text "Modules"]
    titleString := "Modules"
    metadata := some {
      file := some "modules"
      shortTitle := some "Modules"
      tag := some (.provided "modules")
      number := false
    }
    content := intro ++ note ++ #[.other (Block.graph graph) #[]]
    subParts := #[]
  }

/-- Builds the trust page: everything incomplete or resting on an unusual assumption. -/
private def mkTrustPart (decls : Array DeclInfo) (ctx : SiteContext) : Part Manual :=
  Id.run do
  let ordinary : Array Name := #[``Classical.choice, ``propext, ``Quot.sound]
  let sorried := decls.filter (·.dependsOnSorry)
  let ownSorry := sorried.filter (·.hasOwnSorry)
  let inherited := sorried.filter (!·.hasOwnSorry)
  let extraAxiom := decls.filter fun d =>
    d.axioms.any fun a => !ordinary.contains a && a != ``sorryAx
  let mut blocks : Array (Block Manual) := #[
    .para #[.text (String.join [
      "Everything in the library that is incomplete or rests on an assumption beyond the three ",
      "axioms every classical Lean development uses (",
    ]), .code "Classical.choice", .text ", ", .code "propext", .text ", ", .code "Quot.sound",
      .text "). This is the referee's checklist."],
    .para #[
      .bold #[.text s!"{decls.size - sorried.size} of {decls.size} declarations "],
      .text s!"are fully proved. {sorried.size} depend on a ", .code "sorry",
      .text s!" ({ownSorry.size} directly, {inherited.size} inherited from something they use)."
    ]
  ]
  if let some list := declIndexList (ownSorry.qsort fun a b => a.name.lt b.name) ctx then
    blocks := blocks.push <| .para #[.bold #[.text s!"Contains a `sorry` directly ({ownSorry.size})"]]
    blocks := blocks.push list
  if let some list := declIndexList (inherited.qsort fun a b => a.name.lt b.name) ctx then
    blocks := blocks.push <| .para #[
      .bold #[.text s!"Inherits a `sorry` ({inherited.size})"],
      .text "  — each declaration's own page names the chain that reaches the gap."
    ]
    blocks := blocks.push list
  if let some list := declIndexList (extraAxiom.qsort fun a b => a.name.lt b.name) ctx then
    blocks := blocks.push <| .para #[.bold #[.text s!"Rests on extra axioms ({extraAxiom.size})"]]
    blocks := blocks.push list
  else
    blocks := blocks.push <| .para #[.text "No declaration rests on an axiom beyond the ordinary three."]
  return {
    title := #[.text "Trust"]
    titleString := "Trust"
    metadata := some {
      file := some "trust"
      shortTitle := some "Trust"
      tag := some (.provided "trust")
      number := false
    }
    content := blocks
    subParts := #[]
  }

/-- The landing summary: what the library claims, how much of it is proved, and what it assumes.

Replaces a declaration-count dashboard. A reader arriving cold cannot act on "1677 declarations,
12 chapters"; they can act on "these are the results, this many are complete, here is what they
rest on". -/
private def mkLandingBlocks (decls : Array DeclInfo) (ctx : SiteContext) : Array (Block Manual) :=
  Id.run do
  let claims := claimsOf decls
  let sorried := decls.filter (·.dependsOnSorry)
  let topClaims := (claims.qsort fun a b => closureSize a ctx > closureSize b ctx).take 10
  let mut blocks : Array (Block Manual) := #[]
  let gap : Array (Inline Manual) :=
    if sorried.isEmpty then
      #[.text ", with nothing resting on a ", .code "sorry", .text "."]
    else
      #[.text s!"; {sorried.size} depend on a ", .code "sorry", .text ". See ",
        .link #[.text "Trust"] "trust/", .text " for the breakdown."]
  blocks := blocks.push <| .para <| #[
    .bold #[.text "Status. "],
    .text s!"{decls.size - sorried.size} of {decls.size} declarations are fully proved"
  ] ++ gap
  blocks := blocks.push <| .para <| #[
    .bold #[.text "What it claims. "],
    .text s!"{claims.size} declarations are stated as ", .code "theorem",
    .text s!" rather than {(if claims.size == 1 then "a lemma" else "lemmas")}"
  ] ++ #[
    .text " — the author's own mark of a result worth stating for its own sake. The largest by \
      dependency footprint:"
  ]
  if let some list := declIndexList topClaims ctx then
    blocks := blocks.push list
  blocks := blocks.push <| .para #[
    .link #[.text "See all claims"] "claims/",
    .text ". Each declaration's page carries its minimal self-contained Lean file, the ",
    .text "definitions its statement rests on, and what it would cost to accept it."
  ]
  return blocks

/-- Builds the root site part with chapter pages and utility sections. -/
private def mkRootPart (cfg : Cli) (rootPrefix : Name) (groups : Array GroupInfo)
    (decls : Array DeclInfo) (ctx : SiteContext)
    (overviewBlocks : Array (Block Manual)) : Part Manual :=
  let title := cfg.siteTitle.getD s!"{rootPrefix} exposition"
  {
    title := #[.text title]
    titleString := title
    metadata := some {
      file := some "index"
      shortTitle := some title
      number := false
    }
    content := #[
        .para #[.text "Auto-generated exposition for ", .code rootPrefix.toString, .text "."]
      ]
      ++ mkLandingBlocks decls ctx
      ++ mkDashboardBlocks groups
      ++ overviewBlocks
    subParts := #[mkClaimsPart decls ctx, mkBrowsePart decls ctx, mkModulesPart groups ctx,
        mkTrustPart decls ctx]
      ++ (groups.map fun group => mkGroupPart group ctx)
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
  -- `loadExts := true` initializes the environment extensions from the imported modules. Without it
  -- every extension keeps its empty initial state, so the pretty printer has no notation/unexpander
  -- data and renders raw constants (e.g. `LE.le`/`Eq` instead of `≤`/`=`).
  withCurrentDir projectDir <| Lean.importModules imports {} (loadExts := true)

/-- Imports the target project (the current working directory, since the exposition tool
always runs inside the target project's own Lake environment via `lake env …/exposition`)
and resolves the root module prefix. Shared by `collect`/`all` (`extract` re-imports
separately, since it only needs `env`, not a fresh root-prefix resolution: it trusts
`CollectedData.rootPrefix` instead). -/
private unsafe def loadProject (cfg : Cli) :
    IO (System.FilePath × Lake.Workspace × Name × Environment) := do
  let projectDir : System.FilePath := "."
  let ws ← loadWorkspaceAt projectDir
  let some rootPrefix := cfg.rootPrefix <|> firstRootPrefix ws cfg.excludeLibs
    | throw <| IO.userError "Could not determine a root module prefix. Pass --root PREFIX."
  let imports := importRoots ws cfg.excludeLibs
  let env ← loadEnv projectDir ws imports
  return (projectDir, ws, rootPrefix, env)

/-- Runs the data-gathering analysis against an already-imported project (see `loadProject`):
collects exposed declarations and their dependency/doc metadata, and reads the ancillary
project-level data (module import order, module-level doc comments, README text) needed to
build pages later without re-importing the project. Also prints the diagnostics `collect`/`all`
show today, and writes `excluded-declarations.txt` under `cfg.outputDir` when given. -/
private def collectData (cfg : Cli) (projectDir : System.FilePath) (ws : Lake.Workspace)
    (rootPrefix : Name) (env : Environment) : IO CollectedData := do
  let decls ← collectDecls projectDir rootPrefix ws.root env
  let decls := decls |> dropUnsafeDeps |> attachReverseDeps |> attachTransitiveDeps
  let excludedNames :=
    (projectConstants env rootPrefix).filterMap fun (name, _, info) =>
      if shouldExpose env rootPrefix name info then none else some name
  if let some out := cfg.outputDir then
    let logPath := System.FilePath.mk out / "excluded-declarations.txt"
    IO.FS.createDirAll out
    IO.FS.writeFile logPath <|
      String.intercalate "\n" (excludedNames.toList.map toString) ++ "\n"
  IO.println s!"Hidden (auto-generated/internal) declarations: {excludedNames.size}"
  if decls.isEmpty then
    let namedCount :=
      env.constants.toList.foldl (fun n entry =>
        let name := entry.1
        n + if hasPrefixName name rootPrefix then 1 else 0) 0
    IO.eprintln s!"No declarations exposed under module filtering. Declarations with matching name prefix: {namedCount}"
  else
    IO.println s!"Collected {decls.size} declarations under {rootPrefix}"
  let order ← moduleOrderMap projectDir rootPrefix
  let moduleNames := moduleIndexMap decls |>.toArray.map Prod.fst
  let moduleDocs := moduleNames.map fun name => (name, moduleDocBlocks env name)
  let readmeText ← readFileIfExists (projectDir / "README.md")
  return {
    rootPrefix
    decls
    moduleOrder := order.toArray
    moduleDocs
    readmeText
  }

/-- Reads and decodes a `CollectedData` JSON file written by `collect`. -/
private def loadCollectedData (path : String) : IO CollectedData := do
  let text ← IO.FS.readFile path
  let .ok json := Json.parse text
    | throw <| IO.userError s!"Failed to parse JSON from {path}"
  -- Check the format version before decoding, so a stale file produced by an older `collect`
  -- reports what to do rather than surfacing whichever field happened to be added last.
  let fileVersion := (json.getObjValAs? Nat "version").toOption.getD 0
  if fileVersion != collectedDataVersion then
    throw <| IO.userError s!"{path} is collected-data version {fileVersion}, but this build \
      expects version {collectedDataVersion}. Re-run the `collect` subcommand to regenerate it."
  match FromJson.fromJson? json with
  | .ok (data : CollectedData) => pure data
  | .error err => throw <| IO.userError s!"Failed to decode collected data from {path}: {err}"

/-- Builds and renders the Verso site from already-collected data. Needs no Lean environment
and no access to the target project's source tree: `data` and `cfg`'s render-time flags
(`--repo-url`/`--site-url`/`--title`/`--output`) are all it consults. -/
private def buildSiteFrom (cfg : Cli) (data : CollectedData) : IO UInt32 := do
  let order : Std.HashMap Name Nat := data.moduleOrder.foldl (fun m (n, r) => m.insert n r) {}
  let moduleDocs : Std.HashMap Name (Array (Block Manual)) :=
    data.moduleDocs.foldl (fun m (n, bs) => m.insert n bs) {}
  let modules := buildModules data.rootPrefix order moduleDocs data.decls
  let groups := buildGroups order modules
  let highlightingDir : System.FilePath :=
    match cfg.highlightingDir with
    | some dir => System.FilePath.mk dir
    | none => System.FilePath.mk (cfg.outputDir.getD ".") / "highlighting"
  let declHighlights ← loadHighlighting highlightingDir
  let minimalFiles ← loadMinimalFiles
    (System.FilePath.mk (cfg.outputDir.getD ".") / "extracted-highlighting")
  if !minimalFiles.isEmpty then
    let broken := minimalFiles.fold (fun n _ f => if f.errors.isEmpty then n else n + 1) 0
    IO.println s!"Loaded {minimalFiles.size} minimal files ({broken} do not compile)"
  if declHighlights.isEmpty then
    IO.println s!"No highlighting found at {highlightingDir}; rendering plain code. \
      Run the `highlight` subcommand for interactive Lean."
  else
    IO.println s!"Loaded highlighting for {declHighlights.size} declarations"
  let ctx : SiteContext := {
    repoUrl? := cfg.repoUrl
    siteUrl? := cfg.siteUrl
    declByName := declByNameMap data.decls
    declHrefs := declHrefMap data.decls
    declPageHrefs := declPageHrefMap data.decls
    declHighlights := declHighlights
    minimalFiles := minimalFiles
  }
  let overviewBlocks := mkProjectOverviewBlocks data.readmeText cfg.repoUrl
  let root := mkRootPart cfg data.rootPrefix groups data.decls ctx overviewBlocks
  let versoArgs :=
    match cfg.outputDir with
    | some out => ["--output", out]
    | none => []
  manualMain root (options := versoArgs) (config := renderConfig)

/-- `collect`: imports the target project, runs the analysis, and writes the result as JSON
to `cfg.dataPath`. -/
private unsafe def runCollect (cfg : Cli) : IO UInt32 := do
  let some dataPath := cfg.dataPath
    | IO.eprintln "collect requires --data PATH"
      return 1
  let (projectDir, ws, rootPrefix, env) ← loadProject cfg
  let data ← collectData cfg projectDir ws rootPrefix env
  IO.FS.writeFile dataPath (ToJson.toJson data).compress
  IO.println s!"Wrote collected data for {data.decls.size} declarations to {dataPath}"
  return 0

/-- `extract`: reads collected data from `cfg.dataPath` and writes the standalone
per-declaration `.lean` files. Still re-imports the target project (cheap: the project's
`.olean`s are already built), since extraction needs the live environment to parse source
files notation-aware, but skips redoing the `collect` analysis. -/
private unsafe def runExtract (cfg : Cli) : IO UInt32 := do
  let some dataPath := cfg.dataPath
    | IO.eprintln "extract requires --data PATH"
      return 1
  let some out := cfg.outputDir
    | IO.eprintln "extract requires --output DIR"
      return 1
  let data ← loadCollectedData dataPath
  let projectDir : System.FilePath := "."
  let ws ← loadWorkspaceAt projectDir
  let imports := importRoots ws cfg.excludeLibs
  let env ← loadEnv projectDir ws imports
  let startMs ← IO.monoMsNow
  let n ← writeAllExtractions env data.rootPrefix data.decls projectDir
    (System.FilePath.mk out / "html-multi" / "extracted")
  IO.println s!"Wrote {n} standalone extraction files in {(← IO.monoMsNow) - startMs}ms"
  return 0

/-- `extract-flat`: the tier-2 fallback extraction (see `LMLExposition.Flat`). Same inputs as
`extract`, but the standalone files are rendered from the compiled environment rather than from
source text, and land in `extracted-flat/` so both tiers can be produced and compared in one run. -/
private unsafe def runExtractFlat (cfg : Cli) : IO UInt32 := do
  let some dataPath := cfg.dataPath
    | IO.eprintln "extract-flat requires --data PATH"
      return 1
  let some out := cfg.outputDir
    | IO.eprintln "extract-flat requires --output DIR"
      return 1
  let data ← loadCollectedData dataPath
  let projectDir : System.FilePath := "."
  let ws ← loadWorkspaceAt projectDir
  let imports := importRoots ws cfg.excludeLibs
  let env ← loadEnv projectDir ws imports
  let startMs ← IO.monoMsNow
  let n ← Flat.writeAllFlatExtractions env data.rootPrefix data.decls
    (System.FilePath.mk out / "html-multi" / "extracted-flat")
  IO.println s!"Wrote {n} flat extraction files in {(← IO.monoMsNow) - startMs}ms"
  return 0

/-- `highlight-module`: the worker behind `highlight`. Re-elaborates one module from source and
writes its highlighted commands as JSON. Runs one module per process because highlighting needs
a freshly imported environment, so it is not usable directly — call `highlight` instead. -/
private unsafe def runHighlightModule (cfg : Cli) : IO UInt32 := do
  let some modName := cfg.moduleName
    | IO.eprintln "highlight-module requires --module NAME"
      return 1
  let some out := cfg.outputDir
    | IO.eprintln "highlight-module requires --output FILE"
      return 1
  Highlight.writeModuleHighlighting modName (System.FilePath.mk out)
  return 0

/-- `highlight-file`: the worker behind `highlight-extracted`. Elaborates one standalone `.lean`
file and writes its highlighting together with any errors it produced. -/
private unsafe def runHighlightFile (cfg : Cli) : IO UInt32 := do
  let some input := cfg.inputPath
    | IO.eprintln "highlight-file requires --input FILE"
      return 1
  let some out := cfg.outputDir
    | IO.eprintln "highlight-file requires --output FILE"
      return 1
  Highlight.writeFileHighlighting (System.FilePath.mk input) (System.FilePath.mk out)
  return 0

/-- Number of worker processes to use by default. Falls back to a modest fixed value when the
CPU count cannot be read. -/
private def defaultJobs : IO Nat := do
  try
    let out ← IO.Process.output { cmd := "nproc" }
    if out.exitCode == 0 then
      if let some n := out.stdout.trimAscii.toString.toNat? then
        return max 1 n
    return 8
  catch _ =>
    return 8

/-- `highlight`: reads the module list from collected data and fans out one `highlight-module`
worker per module, writing `<output>/highlighting/<Module>.json`.

Must run inside the target project's `lake env`, like `collect` and `extract`: the workers
re-elaborate project source and so need its `.olean`s on the search path. -/
private def runHighlight (cfg : Cli) : IO UInt32 := do
  let some dataPath := cfg.dataPath
    | IO.eprintln "highlight requires --data PATH"
      return 1
  let some out := cfg.outputDir
    | IO.eprintln "highlight requires --output DIR"
      return 1
  let data ← loadCollectedData dataPath
  let modules := moduleIndexMap data.decls |>.toArray.map Prod.fst
  let jobs ← match cfg.jobs with
    | some n => pure n
    | none => defaultJobs
  let exe ← IO.appPath
  let dir := System.FilePath.mk out / "highlighting"
  IO.FS.createDirAll dir
  let startMs ← IO.monoMsNow
  let results ← Highlight.runFanOut exe (Highlight.moduleWorkItems modules dir) jobs
  let failures := results.filter (!·.ok)
  IO.println s!"Highlighted {results.size - failures.size}/{results.size} modules \
    ({jobs} at a time) in {(← IO.monoMsNow) - startMs}ms"
  for failure in failures do
    IO.eprintln s!"  {failure.label}: {failure.message}"
  return if failures.isEmpty then 0 else 1

/-- `highlight-extracted`: highlights each standalone minimal `.lean` file produced by `extract`,
writing `<output>/extracted-highlighting/<id>.json`.

This is what makes the minimal file — the artifact a reader actually audits — readable as
interactive Lean rather than as a wall of text. Because producing the highlighting elaborates the
file, the same pass establishes whether it compiles, which the site reports per declaration
instead of presenting unverified output as verified.

Must run inside the target project's `lake env`: the extracted files import Mathlib. -/
private def runHighlightExtracted (cfg : Cli) : IO UInt32 := do
  let some out := cfg.outputDir
    | IO.eprintln "highlight-extracted requires --output DIR"
      return 1
  let extractedDir := System.FilePath.mk out / "html-multi" / "extracted"
  if !(← extractedDir.pathExists) then
    IO.eprintln s!"No extracted files at {extractedDir}. Run the `extract` subcommand first."
    return 1
  let files := (← extractedDir.readDir).filterMap fun entry =>
    if entry.path.extension == some "lean" then some entry.path else none
  let jobs ← match cfg.jobs with
    | some n => pure n
    | none => defaultJobs
  let exe ← IO.appPath
  let dir := System.FilePath.mk out / "extracted-highlighting"
  IO.FS.createDirAll dir
  let startMs ← IO.monoMsNow
  let results ← Highlight.runFanOut exe (Highlight.extractedWorkItems files dir) jobs
  let failures := results.filter (!·.ok)
  IO.println s!"Highlighted {results.size - failures.size}/{results.size} extracted files \
    ({jobs} at a time) in {(← IO.monoMsNow) - startMs}ms"
  for failure in failures.extract 0 10 do
    IO.eprintln s!"  {failure.label}: {failure.message}"
  -- A file that fails to elaborate is reported on its own page rather than failing the run: the
  -- known-broken extractions are exactly what P11 asks the site to be honest about.
  return 0

/-- `build-site`: reads collected data from `cfg.dataPath` and renders the Verso site. No Lean
environment or project access at all. -/
private def runBuildSite (cfg : Cli) : IO UInt32 := do
  let some dataPath := cfg.dataPath
    | IO.eprintln "build-site requires --data PATH"
      return 1
  let data ← loadCollectedData dataPath
  buildSiteFrom cfg data

/-- `all` (also the default when no subcommand is given): runs the full pipeline in one
process, without a JSON round-trip, matching the tool's original one-shot behavior. -/
private unsafe def runAll (cfg : Cli) : IO UInt32 := do
  let (projectDir, ws, rootPrefix, env) ← loadProject cfg
  let data ← collectData cfg projectDir ws rootPrefix env
  if let some out := cfg.outputDir then
    let startMs ← IO.monoMsNow
    let n ← writeAllExtractions env data.rootPrefix data.decls projectDir
      (System.FilePath.mk out / "html-multi" / "extracted")
    IO.println s!"Wrote {n} standalone extraction files in {(← IO.monoMsNow) - startMs}ms"
  buildSiteFrom cfg data

/-- Main entry point: dispatches to the `collect`/`extract`/`build-site`/`all` subcommands. A
missing or unrecognized leading token defaults to `all`, so invocations from before this
split (bare flags, no subcommand) keep working unchanged. -/
@[no_expose] unsafe def mainImpl (args : List String) : IO UInt32 := do
  let (subcommand, rest) :=
    match args with
    | "collect" :: rest => ("collect", rest)
    | "extract" :: rest => ("extract", rest)
    | "extract-flat" :: rest => ("extract-flat", rest)
    | "highlight" :: rest => ("highlight", rest)
    | "highlight-module" :: rest => ("highlight-module", rest)
    | "highlight-extracted" :: rest => ("highlight-extracted", rest)
    | "highlight-file" :: rest => ("highlight-file", rest)
    | "build-site" :: rest => ("build-site", rest)
    | "all" :: rest => ("all", rest)
    | rest => ("all", rest)
  let cfg ←
    match parseArgs rest with
    | .ok cfg => pure cfg
    | .error err =>
        IO.eprintln err
        return 1
  match subcommand with
  | "collect" => runCollect cfg
  | "extract" => runExtract cfg
  | "extract-flat" => runExtractFlat cfg
  | "highlight" => runHighlight cfg
  | "highlight-module" => runHighlightModule cfg
  | "highlight-extracted" => runHighlightExtracted cfg
  | "highlight-file" => runHighlightFile cfg
  | "build-site" => runBuildSite cfg
  | _ => runAll cfg

end

end LMLExposition
