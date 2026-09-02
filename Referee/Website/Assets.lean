module

public import Referee.Website.Blocks

open Lean
open Lean.Meta
open Verso.Doc
open Verso.Genre
open Manual

namespace Referee

open Verso.Output Html
open MeaningGraph
open ChallengeGen
open SubVerso.Highlighting (Highlighted)

public section

/-!
# Stylesheet, scripts, and the Verso render config

The site's CSS and JavaScript are authored as real files under `assets/`, embedded with
`include_str`, and emitted as files rather than inlined per page — see the section note below for
what that bought. `renderConfig` is where they are handed to Verso, together with the one script
that is *not* a file (the theme bootstrap, which has to run before the first paint) and the
per-build script that carries the upstream declarations a reader can hover.

Nothing here knows anything about a declaration. That is deliberate: a change to the site's
appearance should be a change to `assets/referee.css` and a reload, never a rebuild of the
executable.
-/

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

private def refereeCssFile : CssFile where
  filename := "referee.css"
  contents := CSS.mk (include_str "assets/referee.css")

private def graphJsFile : JsFile where
  filename := "graph.js"
  contents := JS.mk (include_str "assets/graph.js")
  sourceMap? := none
  -- `graph.js` reads the `d3` global at load time, so it must come after it — and the
  -- `RefereeAudit` global, which it needs to mark the nodes a reader has accepted. Both are
  -- ordering constraints rather than preferences: handlers run in registration order, so a
  -- `graph.js` registered first would paint its verdict marks before any verdict existed to read.
  after := #["d3.v7.min.js", "audit.js"]

/-- Applies the reader's stored light/dark choice to `<html>` before the page paints. -/
private def themeBootJs : String :=
  "try{var t=localStorage.getItem('referee:theme');\
   if(t==='dark'||t==='light')document.documentElement.setAttribute('data-theme',t);}catch(e){}"

private def tocJsFile : JsFile where
  filename := "toc.js"
  contents := JS.mk (include_str "assets/toc.js")
  sourceMap? := none

private def auditJsFile : JsFile where
  filename := "audit.js"
  contents := JS.mk (include_str "assets/audit.js")
  sourceMap? := none

private def revisionsJsFile : JsFile where
  filename := "revisions.js"
  contents := JS.mk (include_str "assets/revisions.js")
  sourceMap? := none

private def browseJsFile : JsFile where
  filename := "browse.js"
  contents := JS.mk (include_str "assets/browse.js")
  sourceMap? := none
  -- Browse reads verdicts through the `RefereeAudit` global rather than reaching into
  -- localStorage itself, so that the two views cannot disagree about what a verdict is. That means
  -- it has to run second.
  after := #["audit.js"]

/-- The statement-anatomy block's two views and its hovers; see `Block.anatomy`. Waits for the
document like the rest, so it needs no ordering: tippy and `marked`, which it uses when they are
present, are loaded in `<head>` by Verso and are in place by then. -/
private def anatomyJsFile : JsFile where
  filename := "anatomy.js"
  contents := JS.mk (include_str "assets/anatomy.js")
  sourceMap? := none

/-- The upstream constants table, as a script setting one global.

Emitted once as a file rather than inlined into each page's graph JSON, for the reason recorded on
`withUpstreamNodes`: these constants are shared across pages, so inlining a signature and docstring
per occurrence writes the same Mathlib text into hundreds of pages. As a file it is fetched once and
cached, and `sync-assets.sh` cannot help here since the contents depend on the project.

A `<script>` assigning a global, not a `fetch` of a `.json`: the site has to work from `file://`, and
a fetch there is blocked by the same-origin policy while a script tag is not.

Carries only the constants that can actually appear as a node under the current flags, so a build
without `--show-trusted-upstream` does not ship every Mathlib signature the project names for the
sake of nodes it never draws. `collect` records them all, since it cannot know how the site will be
rendered; the filtering belongs here. -/
def upstreamJsFile (externals : Array ExternalDeclInfo) (trusted : Std.HashSet Name)
    (showTrusted : Bool) : JsFile :=
  let shown := externals.filter fun e => showTrusted || !trusted.contains e.package
  let entries := shown.map fun e =>
    (e.name.toString, Json.mkObj [
      ("signature", Json.str e.signature),
      ("value", Json.str e.value),
      ("doc", Json.str e.doc),
      ("module", Json.str e.moduleName.toString),
      ("package", Json.str e.package.toString)])
  { filename := "upstream.js"
    contents := JS.mk s!"window.RefereeUpstream = {(Json.mkObj entries.toList).compress};"
    sourceMap? := none }

/-- Declaration names whose page tags collide.

Cross-*kind* collisions — a chapter, a module and a declaration all claiming one tag, which is what
`Mathlib/Logic/Denumerable.lean` produced — are impossible by construction now that `chapterTagOf`,
`moduleTagOf` and `declTagOf` prefix by kind. What remains is two declarations mapping to the same
`asciiTagOf`, which that escaping is designed to prevent but which nothing checks.

Worth checking rather than assuming, because the symptom is unhelpful: Verso reports a duplicate as
`No external ID for <title>` while rendering, names one of the two pages, and does not say that a
collision is what went wrong. On `Mathlib.Order` that took a bisection to identify. -/
def duplicateDeclTags (decls : Array DeclInfo) : Array (String × Array Name) :=
  let byTag := decls.foldl (init := ({} : Std.HashMap String (Array Name))) fun acc d =>
    let t := declTagOf d.name
    acc.insert t ((acc.getD t #[]).push d.name)
  byTag.toArray.filter (·.2.size > 1) |>.qsort (fun a b => a.1 < b.1)

/-- Rendering configuration for the site output.

Takes the upstream table because `upstreamJsFile` depends on the project, unlike every other asset
here, which is `include_str`-embedded at build time. -/
def renderConfig (externals : Array ExternalDeclInfo) (trusted : Std.HashSet Name)
    (showTrusted : Bool) : RenderConfig :=
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
    extraCssFiles := {refereeCssFile}
    extraJsFiles := {d3JsFile, upstreamJsFile externals trusted showTrusted, graphJsFile,
      tocJsFile, auditJsFile,
      revisionsJsFile, browseJsFile, anatomyJsFile}
    -- Inline and in `<head>`, so the stored theme is applied before the first paint. Loading this
    -- as a file would let the light theme flash before the script ran.
    extraHead := #[Html.tag "script" #[] (.text false themeBootJs)]
  }


end

end Referee
