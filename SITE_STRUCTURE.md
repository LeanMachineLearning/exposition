# Site module structure

The exposition site logic is split across five files:

| File | Lines | Purpose |
|---|---|---|
| `LeanExposition/Theme.lean` | 368 | Site CSS (`customCss`) |
| `LeanExposition/GraphJs.lean` | 326 | Graph page JavaScript (`graphJs`) |
| `LeanExposition/TocJs.lean` | 147 | TOC/utility-nav JavaScript (`tocJs`) |
| `LeanExposition/Collect.lean` | 926 | Declaration collection and analysis pipeline |
| `LeanExposition/Site.lean` | 525 | Rendering, page assembly, and CLI entrypoint wiring |

---

## `LeanExposition/Theme.lean`

### 1 · CSS (lines 1–368)

`customCss` — the full site stylesheet as a Lean string literal. Covers CSS
custom properties, layout, `.decl-card` variants, utility nav/buttons
(including the "Hide Theorems" toggle), `.graph-*` components, TOC collapse,
and responsive breakpoints.

---

## `LeanExposition/GraphJs.lean`

### 1 · Dependency graph script (lines 1–326)

`graphJs` — D3-based interactive dependency graph behavior:

- reads graph JSON emitted by `Block.graph`
- renders force-layout nodes/edges with chapter coloring and status styling
- supports search, chapter filter, focus mode, zoom/pan, and fit/reset controls
- shows side-panel details and neighbor lists
- supports declaration navigation on double-click

---

## `LeanExposition/TocJs.lean`

### 1 · TOC behavior script (lines 1–147)

`tocJs` — table-of-contents and utility-nav behavior:

- injects the Overview / Graph utility links
- removes duplicate utility entries from the generated TOC
- adds a persistent TOC collapse/expand button via `localStorage`
- adds a persistent "Hide Theorems" / "Show Theorems" toggle via `localStorage`

---

## `LeanExposition/Collect.lean`

### 1 · Data model and CLI config (lines 18–~140)

Defines core structures and enums used by the exposition pipeline:
`Cli`, `DeclKind`, `SourceInfo`, `LinkInfo`, `DeclCardData`, `DetailsData`,
`GraphNode`, `GraphEdge`, `GraphData`, `DeclInfo`, `ModuleInfo`, `GroupInfo`,
`MarkdownSection`.

`DeclInfo` carries, among other fields, `deps` (all type+body dependencies),
`typeDeps` (type-only dependencies), `usedBy` (reverse dependencies),
`transDeps` (full transitive closure of `deps`), and `docstringBlock?` (a
Verso `Block.docstring` rendered for the declaration).

### 2 · CLI parsing and naming helpers (lines ~140–~350)

`usage`, `parseArgs`, name/path helpers, slugging, inline/doc helpers, and
README markdown section parsing.

### 3 · Declaration introspection pipeline (lines ~350–~790)

Signature extraction, source-range resolution, exposure filtering, module import
traversal, `mkDocstringBlock?` (builds the `{docstring ...}`-equivalent block
via `MetaM`), href-map builders (`declHrefMap`, `declPageHrefMap`), and
declaration collection into `DeclInfo` records (including type/body dependency
splitting for defs, theorems, structures, and classes).

### 4 · Post-processing passes (lines ~870–926)

`attachReverseDeps` (computes `usedBy`), `attachTransitiveDeps` (computes
`transDeps` via `transitiveClosure`), and `attachDependsOnSorry`.

---

## `LeanExposition/Site.lean`

### 1 · Module/group assembly helpers (lines 27–64)

`moduleRank`, `sortModules`, `sortDeclsInModules`, `buildModules`, `buildGroups`.

### 2 · Project context page helpers (lines 66–119)

`mkSourceParagraph`, `mkMarkdownPart`, `loadProjectContextParts`.

### 3 · Verso block extensions and render config (lines 121–212)

`Block.declCard`, `Block.details`, `Block.graph`, and `renderConfig`
(`htmlDepth := 3`, so each declaration gets its own split page).

### 4 · Page/document assembly (lines 213–~440)

Dashboard blocks, reader guides, declaration cards (`mkDeclBlock`, including a
"Details" link to the declaration's dedicated page), `mkGraphData` (shared
graph-payload builder), dedicated per-declaration pages (`mkDeclPart`, with
its own dependency graph followed by "Type dependencies" and "All
dependencies, transitively" cards), chapter/module pages, the global graph
page, and root part construction.

### 5 · Workspace loading and entrypoint (lines ~440–525)

`withCurrentDir`, `loadWorkspaceAt`, `importRoots`, `firstRootPrefix`,
`loadEnv`, and `mainImpl`.

---
