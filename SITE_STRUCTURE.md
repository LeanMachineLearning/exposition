# Site module structure

The exposition site logic is split across five files:

| File | Lines | Purpose |
|---|---|---|
| `LeanExposition/Theme.lean` | 352 | Site CSS (`customCss`) |
| `LeanExposition/GraphJs.lean` | 326 | Graph page JavaScript (`graphJs`) |
| `LeanExposition/TocJs.lean` | 111 | TOC/utility-nav JavaScript (`tocJs`) |
| `LeanExposition/Collect.lean` | 929 | Declaration collection and analysis pipeline |
| `LeanExposition/Site.lean` | 576 | Rendering, page assembly, and CLI entrypoint wiring |

---

## `LeanExposition/Theme.lean`

### 1 · CSS (lines 1–352)

`customCss` — the full site stylesheet as a Lean string literal. Covers CSS
custom properties, layout, `.decl-card` variants, `.graph-*` components, TOC
collapse, and responsive breakpoints.

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

### 1 · TOC behavior script (lines 1–111)

`tocJs` — table-of-contents and utility-nav behavior:

- injects the Overview / TFB / Graph utility links
- removes duplicate utility entries from the generated TOC
- adds a persistent TOC collapse/expand button via `localStorage`

---

## `LeanExposition/Collect.lean`

### 1 · Data model and CLI config (lines 18–153)

Defines core structures and enums used by the exposition pipeline:
`Cli`, `DeclKind`, `SourceInfo`, `LinkInfo`, `DeclCardData`, `DetailsData`,
`GraphNode`, `GraphEdge`, `GraphData`, `DeclInfo`, `ModuleInfo`, `GroupInfo`,
`MarkdownSection`, `ComparatorConfigInfo`, `TrustedBaseInfo`,
`TargetStatementInfo`.

### 2 · CLI parsing and naming helpers (lines 154–364)

`usage`, `parseArgs`, name/path helpers, slugging, inline/doc helpers, and
README markdown section parsing.

### 3 · Trusted-base and config loading (lines 365–523)

Filesystem/config readers, comparator config parsing, trusted-base target block
loading, and trusted closure computation via `lake exe extractDeps`.

### 4 · Declaration introspection pipeline (lines 524–894)

Signature extraction, source-range resolution, exposure filtering, module import
traversal, and declaration collection into `DeclInfo` records.

### 5 · Post-processing passes (lines 895–925)

`attachReverseDeps`, `attachDependsOnSorry`, and `attachTrustedBaseFlags`.

---

## `LeanExposition/Site.lean`

### 1 · Module/group assembly helpers (lines 27–64)

`moduleRank`, `sortModules`, `sortDeclsInModules`, `buildModules`, `buildGroups`.

### 2 · Project context page helpers (lines 66–119)

`mkSourceParagraph`, `mkMarkdownPart`, `loadProjectContextParts`.

### 3 · Verso block extensions and render config (lines 121–201)

`Block.declCard`, `Block.details`, `Block.graph`, and `renderConfig`.

### 4 · Page/document assembly (lines 203–494)

Dashboard blocks, reader guides, declaration cards, chapter/module pages,
trusted-base pages, graph page, and root part construction.

### 5 · Workspace loading and entrypoint (lines 496–576)

`withCurrentDir`, `loadWorkspaceAt`, `importRoots`, `firstRootPrefix`,
`loadEnv`, and `mainImpl`.

---
