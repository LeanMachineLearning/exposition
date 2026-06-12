# Site module structure

The exposition site logic is split across five files:

| File | Lines | Purpose |
|---|---|---|
| `LeanExposition/Theme.lean` | 374 | Site CSS (`customCss`) |
| `LeanExposition/GraphJs.lean` | 326 | Graph page JavaScript (`graphJs`) |
| `LeanExposition/TocJs.lean` | 153 | TOC/utility-nav JavaScript (`tocJs`) |
| `LeanExposition/Collect.lean` | 1109 | Declaration collection and analysis pipeline |
| `LeanExposition/Site.lean` | 647 | Rendering, page assembly, and CLI entrypoint wiring |

---

## `LeanExposition/Theme.lean`

### 1 · CSS (lines 1–374)

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

### 1 · TOC behavior script (lines 1–153)

`tocJs (hasTfb : Bool)` — table-of-contents and utility-nav behavior:

- injects the Overview / TFB (when present) / Graph utility links
- removes duplicate utility entries from the generated TOC
- adds a persistent TOC collapse/expand button via `localStorage`
- adds a persistent "Hide Theorems" / "Show Theorems" toggle via `localStorage`

---

## `LeanExposition/Collect.lean`

### 1 · Data model and CLI config (lines 18–~155)

Defines core structures and enums used by the exposition pipeline:
`Cli`, `DeclKind`, `SourceInfo`, `LinkInfo`, `DeclCardData`, `DetailsData`,
`GraphNode`, `GraphEdge`, `GraphData`, `DeclInfo`, `ModuleInfo`, `GroupInfo`,
`MarkdownSection`, `ComparatorConfigInfo`, `TrustedBaseInfo`,
`TargetStatementInfo`.

`DeclInfo` carries, among other fields, `deps` (all type+body dependencies),
`typeDeps` (type-only dependencies), `usedBy` (reverse dependencies),
`transDeps` (full transitive closure of `deps`), and `docstringBlock?` (a
Verso `Block.docstring` rendered for the declaration).

### 2 · CLI parsing and naming helpers (lines ~155–~365)

`usage`, `parseArgs`, name/path helpers, slugging, inline/doc helpers, and
README markdown section parsing.

### 3 · Trusted-base and config loading (lines ~365–~525)

Filesystem/config readers, comparator config parsing, trusted-base target block
loading, and trusted closure computation via `lake exe extractDeps`.

### 4 · Declaration introspection pipeline (lines ~525–975)

Signature extraction, source-range resolution, exposure filtering, module import
traversal, `mkDocstringBlock?` (builds the `{docstring ...}`-equivalent block
via `MetaM`), href-map builders (`declHrefMap`, `declPageHrefMap`), and
declaration collection into `DeclInfo` records (including type/body dependency
splitting for defs, theorems, structures, and classes).

### 5 · Post-processing passes (lines ~1050–1109)

`attachReverseDeps` (computes `usedBy`), `attachTransitiveDeps` (computes
`transDeps` via `transitiveClosure`), `attachDependsOnSorry`, and
`attachTrustedBaseFlags`.

---

## `LeanExposition/Site.lean`

### 1 · Module/group assembly helpers (lines 27–64)

`moduleRank`, `sortModules`, `sortDeclsInModules`, `buildModules`, `buildGroups`.

### 2 · Project context page helpers (lines 66–119)

`mkSourceParagraph`, `mkMarkdownPart`, `loadProjectContextParts`.

### 3 · Verso block extensions and render config (lines 121–212)

`Block.declCard`, `Block.details`, `Block.graph`, and `renderConfig`
(`htmlDepth := 3`, so each declaration gets its own split page).

### 4 · Page/document assembly (lines 213–559)

Dashboard blocks, reader guides, declaration cards (`mkDeclBlock`, including a
"Details" link to the declaration's dedicated page), dedicated per-declaration
pages (`mkDeclPart`, listing direct "Type uses" / "Body uses" / "Used by" and
the full "All dependencies, transitively" list), chapter/module pages,
trusted-base pages, graph page, and root part construction.

### 5 · Workspace loading and entrypoint (lines 560–647)

`withCurrentDir`, `loadWorkspaceAt`, `importRoots`, `firstRootPrefix`,
`loadEnv`, and `mainImpl`.

---
