module

public import Referee.Website.Pages
public import Referee.Website.PostProcess

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
# Rendering one chapter at a time

Verso builds the whole document tree, traverses it, and only then streams pages out, so a monolithic
render's peak memory tracks the library: measured 14.95 GB at 28,251 declarations, projected past
150 GB at Mathlib's 304,210. `--per-chapter` bounds that peak by the largest chapter instead — one
Verso run per chapter plus one for the whole-library pages, all into the same output directory — and
then stitches back the artifacts Verso derives from whatever tree it was handed.

The stitching is the whole cost of the trade, and it is the bulk of this file: the sidebar, the
prev/next navigation, `xref.json`, the `find` page, the search buckets and the hover-data
numbering all have to be reconstructed from runs that each saw a fraction of the tree.
-/

/-! ### Chapter-wise rendering

Verso builds the whole document tree, traverses it, and only then streams pages out, so a
monolithic render's peak memory tracks the library: measured 14.95 GB at 28,251 declarations,
projected past 150 GB at Mathlib's 304,210. `--per-chapter` bounds the peak by the largest chapter
instead, by running Verso once per chapter and once for the whole-library pages, all into the same
output directory, and then stitching together the artifacts Verso derives from whatever tree it was
handed.

What makes the split sound is that Referee never uses Verso's cross-referencing between pages:
every inter-page link is a raw href computed from the data (`declPageHrefMap` and friends), so a
page rendered in a chapter-scoped run links into other chapters correctly without Verso ever seeing
them. What Verso *does* derive from its tree, and what therefore has to be reconstructed, is exactly
five things:

* **Chapter numbering.** A part's number is its position among numbered siblings, so a run for
  chapter `g` includes *stub* parts — title, tag and file, no content, no children — for chapters
  `0..g-1`. The stubs cost pages that must not survive, which run *order* solves: the global run
  goes first and each chapter run follows in descending order, so every stub page a run writes is
  overwritten by a later run that owns it, and the only casualties — the landing, `find` and
  `search` pages, clobbered by stub landings — are stashed from the global run and restored.
* **The sidebar.** Each run's pages carry a root TOC of that run's tree only. The global run's tree
  (utility pages plus every chapter as a stub) produces the complete TOC, which is lifted off its
  landing page and substituted into every chapter page, with the `current` row mark re-applied per
  chapter — the only per-page variation the pruned root TOC has.
* **`xref.json` and the `find` page.** Per-domain union of every run's file; the `find` page embeds
  the exact text of `xref.json`, so the merged text is spliced over the global run's copy.
* **The search buckets.** Every run emits its own content-hashed bucket files; the union of their
  documents is re-bucketed under one version and the index rebuilt over it. This is why
  `--per-chapter` requires `--search names` or `none`: merging full-text inverted indexes means
  re-indexing the library, and at the scale where this flag matters the full index was never
  viable.
* **Hover data.** Pages reference `-verso-docs.json` by dense per-run ids. The stitch pass walks
  every page in tree order, re-assigns ids by first encounter of each distinct payload — the same
  discipline Verso's own dedup applies — rewrites the `data-verso-hover` attributes, and writes the
  merged table.

Two more seams are patched by the stitch pass: the prev/next navigation at run boundaries (a
chapter run cannot see past its own tree, so its chapter index's prev and its last page's next are
synthesized to point where the monolithic build points), and the feature-derived tail of the global
pages' heads (the global run's tree of stubs never uses the code-rendering features, so its pages
would otherwise lack the styles its own signature excerpts are styled by).

Measured against a monolithic build of the same data, the result is byte-identical except for
three disclosed residuals, all checked structurally instead:

* **Definition links across runs.** When a constant's defining code block is rendered in the same
  Verso run, other occurrences of it in highlighted code link to that definition site; across runs
  the registry is empty and the token degrades to its hover. How much this bites depends entirely
  on how much the chapters lean on one another: 8 pages of 859 on `Mathlib.Dynamics`, but
  **14,663 of 29,086 on `Mathlib.Analysis`** — half the site carries at least one degraded token.
  The reader keeps the token's hover, and the card's own dependency links (raw hrefs, unaffected)
  still reach the definition, so the loss is one click-through, not reachability. Reconstructing
  the links in the stitch would mean rebuilding Verso's definition-site registry from rendered
  HTML — which token of which page *is* a constant's definition — and is the natural follow-up if
  the degradation matters in practice.
* **The search version hash.** The rebuilt index payload is byte-identical to the monolithic
  `--search names` one, but the bucket files carry a version derived from it rather than from
  Verso's full-text index, which does not exist in any per-chapter run. Chapter *entries* in the
  result list also carry the stub page's (empty) excerpt rather than the module listing's text.
* **`xref.json`'s `[anonymous]` entry**, where several targets share one key and the monolithic
  build itself keeps whichever its traversal saw last; the merge may keep a different one. -/

/-- A chapter as the *other* runs see it: same title, tag and file — so numbering, TOC rows and
cross-references come out right — and nothing else. -/
private def stubGroupPart (group : GroupInfo) : Part Manual :=
  let title := humanizeWord group.key
  {
    title := #[.text title]
    titleString := title
    metadata := some {
      file := some s!"chapter-{slugify group.key}"
      shortTitle := some title
      tag := some (.provided (chapterTagOf group.key))
    }
    content := #[]
    subParts := #[]
  }

/-- The root-level files a chapter run's stub landing clobbers, restored from the global run. -/
private def perChapterStashedPages : Array System.FilePath :=
  #["index.html", "find" / "index.html", "search" / "index.html"]

/-- Copies the global run's root-level pages and per-run merge inputs into the stash. -/
private def stashRunArtifacts (htmlDir stashDir : System.FilePath) (label : String)
    (pages : Bool) : IO Unit := do
  IO.FS.createDirAll stashDir
  for (src, dst) in #[("xref.json", s!"xref-{label}.json"),
      ("-verso-docs.json", s!"docs-{label}.json")] do
    let p := htmlDir / src
    if ← p.pathExists then
      IO.FS.writeFile (stashDir / dst) (← IO.FS.readFile p)
  if pages then
    for page in perChapterStashedPages do
      let p := htmlDir / page
      if ← p.pathExists then
        IO.FS.writeFile (stashDir / s!"page-{slugify page.toString}.html") (← IO.FS.readFile p)

/-- Restores what `stashRunArtifacts` saved from the global run. -/
private def restoreGlobalPages (htmlDir stashDir : System.FilePath) : IO Unit := do
  for page in perChapterStashedPages do
    let src := stashDir / s!"page-{slugify page.toString}.html"
    if ← src.pathExists then
      IO.FS.writeFile (htmlDir / page) (← IO.FS.readFile src)

/-- The opening tag of the sidebar's *root* block, the one `pruneSidebarSubTocs` keeps. -/
private def splitTocBookOpenTag : String := "<div class=\"split-toc book\">"

/-- Splits `html` around its root sidebar block: `(before, block, after)`, where `block` includes
the opening tag and its balanced close. `none` when the page has no root block or it is unbalanced,
in which case the caller leaves the page alone — same policy as `pruneSidebarSubTocs`. -/
private def splitAroundRootToc (html : String) : Option (String × String × String) := do
  match html.splitOn splitTocBookOpenTag with
  | [before, rest] =>
    -- Same walk as `afterSplitTocBlock`: depth over `<div`/`</div>`, first return to zero closes.
    let pieces := rest.splitOn "</div>"
    let mut depth : Int := 1
    let mut consumed := 0
    for piece in pieces do
      consumed := consumed + 1
      depth := depth + ((piece.splitOn "<div").length - 1 : Nat) - 1
      if depth == 0 then
        let inside := String.intercalate "</div>" (pieces.take consumed)
        let after := String.intercalate "</div>" (pieces.drop consumed)
        return (before, splitTocBookOpenTag ++ inside ++ "</div>", after)
    none
  -- Zero occurrences is a page without a sidebar; more than one is not a shape this recognizes.
  | _ => none

/-- Marks the sidebar row of `chapterHref`'s chapter as the current one, the way Verso marks the
chapter containing the page being rendered. The row is the last `<tr class="numbered">` opened
before the chapter's link. -/
private def markCurrentChapter (toc : String) (chapterHref : String) : String :=
  let linkKey := s!"<a href=\"{chapterHref}#"
  match toc.splitOn linkKey with
  | [pre, post] =>
    let rowTag := "<tr class=\"numbered\">"
    let pieces := pre.splitOn rowTag
    if h : pieces.length ≥ 2 then
      let last := pieces.getLast (by intro hnil; simp [hnil] at h)
      String.intercalate rowTag (pieces.dropLast)
        ++ "<tr class=\"current numbered\">" ++ last ++ linkKey ++ post
    else toc
  | _ => toc

/-- Reads one run's `-verso-docs.json` as an id → payload table, each payload paired with its
occurrence index among same-payload entries of the run (in local-id order).

The occurrence index is what lets the merge preserve Verso's duplicate structure. The dedup that
assigns these ids keys on `Highlighted` *values*, and distinct values can render to identical
payload text — observed twice on an 859-declaration site — so a merge keyed on payload text alone
would collapse entries the monolithic build keeps apart, and every id after the first collapse
would drift. Keyed on `(payload, occurrence)` the merged numbering reproduces the monolithic one. -/
private def readDocsTable (path : System.FilePath) : IO (Std.HashMap Nat (Json × Nat)) := do
  if !(← path.pathExists) then return {}
  let .ok json := Json.parse (← IO.FS.readFile path) | return {}
  let .obj kvs := json | return {}
  let entries := kvs.foldl (init := #[]) fun (acc : Array (Nat × Json)) k v =>
    match k.toNat? with
    | some n => acc.push (n, v)
    | none => acc
  let sorted := entries.qsort (·.1 < ·.1)
  let mut seen : Std.HashMap String Nat := {}
  let mut out : Std.HashMap Nat (Json × Nat) := {}
  for (n, payload) in sorted do
    let key := payload.compress
    let occ := seen.getD key 0
    seen := seen.insert key (occ + 1)
    out := out.insert n (payload, occ)
  return out

/-- Rewrites every `data-verso-hover="<id>"` on a page from a run-local id to a merged one,
assigning merged ids on first encounter of each distinct payload. Returns the rewritten page. -/
private def remapHoverIds (page : String) (runDocs : Std.HashMap Nat (Json × Nat))
    (assign : Std.HashMap (String × Nat) Nat × Array (Nat × Json)) :
    String × (Std.HashMap (String × Nat) Nat × Array (Nat × Json)) := Id.run do
  let marker := "data-verso-hover=\""
  let pieces := page.splitOn marker
  if pieces.length ≤ 1 then
    return (page, assign)
  let mut byPayload := assign.1
  let mut table := assign.2
  let mut out := pieces.headD ""
  for chunk in pieces.drop 1 do
    -- The binder is ascribed because `String.takeWhile` goes through the slice-pattern typeclass,
    -- and inside a `do` block an unascribed lambda's type is postponed past the instance search,
    -- which reports itself as a stuck universe constraint.
    let digits := (chunk.takeWhile (fun (c : Char) => c.isDigit)).toString
    let remainder := (chunk.drop digits.length).toString
    let payload? : Option (Json × Nat) := match digits.toNat? with
      | some n => runDocs.get? n
      | none => none
    match payload? with
    | none =>
      -- An id the run's table does not know. Leave it untouched rather than guess.
      out := out ++ marker ++ chunk
    | some (payload, occ) =>
      let key := (payload.compress, occ)
      let mut newId := table.size
      match byPayload.get? key with
      | some i => newId := i
      | none =>
        byPayload := byPayload.insert key newId
        table := table.push (newId, payload)
      out := out ++ marker ++ toString newId ++ remainder
  return (out, (byPayload, table))

/-- Every page of the site in tree order — the order Verso encounters them, which is what makes the
hover-id reassignment reproduce a monolithic run's numbering. The `minimal/` subpage of a
declaration, when extraction produced one, sits directly after its declaration. -/
private def orderedPagePaths (groups : Array GroupInfo) (ctx : SiteContext) : Array String := Id.run do
  let mut out := #["index.html"]
  if ctx.diff?.isSome || ctx.provenance?.isSome then
    out := out.push "changes/index.html"
  if (claimedResults? ctx).isSome then
    out := out.push "claims/index.html"
  out := out.push "theorems/index.html"
  if ctx.usesSpecs then
    out := out.push "specifications/index.html"
  out := out ++ #["browse/index.html", "sorries/index.html"]
  for group in groups do
    out := out.push s!"{groupHrefOf group.key}index.html"
    for m in group.modules do
      out := out.push s!"{groupHrefOf group.key}{moduleHrefOf m.path}index.html"
      for decl in m.decls do
        let base := pathForDeclPage group.key m.path decl.name
        out := out.push (base ++ "index.html")
        out := out.push (base ++ "minimal/index.html")
  out := out ++ #["find/index.html", "search/index.html"]
  return out

/-- The chapter a page belongs to, by its path — which decides both which run rendered it (and so
which hover table its ids index) and which sidebar row to mark current. `none` is the global run. -/
private def chapterOfPagePath (groups : Array GroupInfo) (path : String) : Option Nat :=
  groups.findIdx? fun g => path.startsWith (groupHrefOf g.key)

/-- A prev/next nav anchor exactly as Verso writes one. `arrowFirst` distinguishes the two: prev
carries its arrow before the label, next after. -/
private def navAnchor (href label : String) (rel : String) (arrowFirst : Bool) : String :=
  let arrow := if arrowFirst then "←" else "→"
  let spans := if arrowFirst then
      s!"<span class=\"arrow\">{arrow}</span><span class=\"where\">{label}</span>"
    else
      s!"<span class=\"where\">{label}</span><span class=\"arrow\">{arrow}</span>"
  s!"<a class=\"local-button active\" href=\"{href}\" rel=\"{rel}\" title=\"{label}\">{spans}</a>"

/-- The last page of a chapter, as `(href-with-anchor, label)` — what the *next* chapter's index
should point back to, and monolithic Verso does. The deepest last descendant: the last declaration
of the last module with declarations, else the last module page, else the chapter page itself. -/
private def lastPageOfChapter (idx : Nat) (group : GroupInfo) : String × String :=
  let chapterHref := groupHrefOf group.key
  match group.modules.back? with
  | some m =>
    match m.decls.back? with
    | some decl =>
      (pathForDeclPage group.key m.path decl.name ++ "#" ++ declTagOf decl.name,
        decl.name.toString)
    | none =>
      (s!"{chapterHref}{moduleHrefOf m.path}#{moduleTagOf m.name}",
        s!"{idx + 1}.{group.modules.size}. {m.path}")
  | none => (s!"{chapterHref}#{chapterTagOf group.key}", s!"{idx + 1}. {humanizeWord group.key}")

/-- Replaces the prev anchor inside both of a page's prev-next navs. A chapter run gives its
chapter index a prev that points at the run's own tree — the root for the first chapter, the stub
chapter before it otherwise — where the monolithic build points at the page that *precedes* the
chapter: the last utility page for the first chapter, the previous chapter's last page otherwise. -/
private def replacePrevAnchors (page prevAnchor : String) : String := Id.run do
  let navTag := "<nav class=\"prev-next-buttons\">"
  match page.splitOn navTag with
  | [] | [_] => return page
  | first :: rest =>
    let mut out := first
    for piece in rest do
      match piece.splitOn "</a>" with
      | head :: tail =>
        if (head.splitOn " rel=\"prev\"").length == 2 then
          -- `head` is leading whitespace plus the prev anchor (sans its close). Keep the
          -- whitespace, swap the anchor.
          let ws := (head.takeWhile (fun (c : Char) => c == '\n' || c == ' ')).toString
          out := out ++ navTag ++ ws ++ prevAnchor ++ String.intercalate "</a>" tail
        else
          out := out ++ navTag ++ piece
      | [] => out := out ++ navTag ++ piece
    return out

/-- The bytes a chapter run writes where a next button would go on its last page, there being
nothing after that page in the run's own tree. -/
private def missingNextPlaceholder : String := "<div></div>\n            </nav>"

/-- Fills in the next buttons on a chapter's last page, which the monolithic build points at the
following chapter's index. -/
private def fillMissingNext (page nextAnchor : String) : String :=
  match page.splitOn missingNextPlaceholder with
  | [a, b, c] => a ++ nextAnchor ++ "</nav>" ++ b ++ nextAnchor ++ "</nav>" ++ c
  | _ => page

/-- The shared asset references of a page's `<head>`: its `-verso-data` script and stylesheet
lines, verbatim, in order. -/
private def headAssetLines (page : String) : Array String := Id.run do
  let headEnd := (page.splitOn "</head>").headD page
  let mut out := #[]
  for line in headEnd.splitOn "\n" do
    let t := (line.trimAscii).toString
    if t.startsWith "<script src=\"-verso-data/" || t.startsWith "<link rel=\"stylesheet\" href=\"-verso-data/" then
      out := out.push line
  return out

/-- Inserts into `page`'s head the asset lines of `reference` it is missing, each after the same
predecessor line it follows there.

Exists because Verso computes a run's head from the *features* its tree used: the global run's tree
of stubs never renders a hovered signature, so its pages lack the hover feature's scripts (popper,
tippy) that every chapter page loads — and the hover payloads on the global pages need them. -/
private def normalizeHeadAssets (page : String) (reference : Array String) : String := Id.run do
  let mut out := page
  let mut present := headAssetLines page
  for i in [0:reference.size] do
    let some line := reference[i]? | continue
    if present.contains line then continue
    -- Insert after its predecessor in the reference, all of which precede it in `reference`
    -- order and have been inserted already if they were missing.
    let anchor := if i == 0 then none else reference[i-1]?
    match anchor with
    | some prev =>
      match out.splitOn (prev ++ "\n") with
      | [a, b] => out := a ++ prev ++ "\n" ++ line ++ "\n" ++ b
      | _ => continue
    | none => continue
    present := present.push line
  return out

/-- The last line of the head every run emits identically; what follows it is the run's
feature-derived asset tail, which the global run lacks (its tree of stubs never used the code
features) and `completeGlobalHeadTails` copies over from a chapter page. -/
private def headTailMarker : String := "-verso-data/katex/katex.css\">"

/-- The head segment between `headTailMarker` and `</head>`, when the page has that shape. -/
private def headTailOf (page : String) : Option String :=
  match page.splitOn headTailMarker with
  | [_, rest] => (rest.splitOn "</head>").head?
  | _ => none

/-- The closing bytes of the theme script, the one element of the head tail every run emits. -/
private def themeScriptEnd : String := "}catch(e){}</script>"

/-- Completes the feature-derived tail of every global page's head from a chapter page's, after
hoisting has run — the tail is where the hoisted stylesheet and script references live, and the
global run's tree of stubs never used the features that emit them, so its pages would otherwise
lack the styles their own signature excerpts are styled by.

Not a verbatim replacement, because two global pages carry page-specific tail content in mono
order: the `find` page's `window.xref` script sits between the stylesheet references and the
feature script, and the `search` page's preload link follows the theme script. So the uniform
elements are grafted around what is there: everything up to the theme script's end is replaced by
the reference's same span — which preserves anything *after* it — and the `find` page instead gets
the reference's pieces spliced on either side of its own script. -/
def completeGlobalHeadTails (htmlDir : System.FilePath) (groups : Array GroupInfo)
    (ctx : SiteContext) : IO Unit := do
  let some g0 := groups[0]? | return
  let refPath := htmlDir / s!"{groupHrefOf g0.key}index.html"
  if !(← refPath.pathExists) then return
  let some refTail := headTailOf (← IO.FS.readFile refPath) | return
  -- The reference tail dissected: stylesheet references, the feature script, the theme script.
  let some uCore := (refTail.splitOn themeScriptEnd).head?.map (· ++ themeScriptEnd) | return
  let linksPart := (refTail.splitOn "<script").headD ""
  let f116Part := match refTail.splitOn "<script" with
    | _ :: featurePiece :: _ => "<script" ++ ((featurePiece.splitOn "</script>").headD "") ++ "</script>"
    | _ => ""
  for path in orderedPagePaths groups ctx do
    if (chapterOfPagePath groups path).isSome then continue
    let file := htmlDir / path
    if !(← file.pathExists) then continue
    let text ← IO.FS.readFile file
    match text.splitOn headTailMarker with
    | [before, rest] =>
      match rest.splitOn "</head>" with
      | tail :: tailParts =>
        if tail == refTail then continue
        let newTail ← if path == "find/index.html" then
            -- Graft around the page's own `window.xref` script: stylesheet links before it,
            -- the feature script between it and the theme script.
            let withLinks :=
              if tail.startsWith "\n    " then linksPart ++ (tail.drop 5).toString else tail
            match withLinks.splitOn "\n    <script>\n      try{" with
            | [beforeTheme, themeAndRest] =>
              pure (beforeTheme ++ "\n    " ++ f116Part ++ "\n    <script>\n      try{" ++ themeAndRest)
            | _ => pure withLinks
          else
            -- Everything up to the theme script becomes the reference's; what follows it —
            -- the search page's preload link, nothing on the others — is preserved.
            match tail.splitOn themeScriptEnd with
            | [_, post] => pure (uCore ++ post)
            | _ => pure tail
        if newTail != tail then
          IO.FS.writeFile file (before ++ headTailMarker ++ newTail ++ "</head>"
            ++ String.intercalate "</head>" tailParts)
      | [] => pure ()
    | _ => pure ()

/-- The stitch pass: one read-modify-write over every page, in tree order, doing everything that
depends on which run rendered the page — sidebar substitution and current-marking for chapter
pages, hover-id remapping for all. Writes the merged `-verso-docs.json` at the end. -/
private def stitchPages (htmlDir stashDir : System.FilePath) (groups : Array GroupInfo)
    (ctx : SiteContext) : IO Unit := do
  -- The complete sidebar, lifted off the global run's landing page after pruning. The root toggle
  -- arrives `checked` because the landing's is expanded; so is a chapter index's, whose entry is a
  -- top-level row, but not a module or declaration page's — hence the two variants.
  let landing ← IO.FS.readFile (htmlDir / "index.html")
  let tocChecked? := (splitAroundRootToc landing).map (·.2.1)
  let tocPlain? := tocChecked?.map fun block =>
    match block.splitOn " checked=\"checked\"" with
    | [a, b] => a ++ b
    | _ => block
  if tocChecked?.isNone then
    IO.eprintln "warning: could not find the sidebar on the landing page; \
      chapter pages keep their run-local sidebars"
  -- Head assets are per-run (Verso derives them from the features the run's tree used), so the
  -- global run's pages are normalized against a chapter page, which used them all.
  let refHead ← do
    match groups[0]? with
    | some g =>
      let p := htmlDir / s!"{groupHrefOf g.key}index.html"
      if ← p.pathExists then pure (headAssetLines (← IO.FS.readFile p)) else pure #[]
    | none => pure #[]
  -- The two nav seams a chapter run cannot see past: what precedes its chapter index, and what
  -- follows its last page.
  let mut prevFix : Std.HashMap String String := {}
  let mut nextFix : Std.HashMap String String := {}
  for g in [0:groups.size] do
    let some group := groups[g]? | continue
    let indexPath := s!"{groupHrefOf group.key}index.html"
    let (href, label) := if g == 0 then
        ("sorries/#sorries", "Sorries and assumptions")
      else match groups[g-1]? with
        | some prev => lastPageOfChapter (g-1) prev
        | none => ("", "")
    if !href.isEmpty then
      prevFix := prevFix.insert indexPath (navAnchor href label "prev" (arrowFirst := true))
    if let some next := groups[g+1]? then
      let (lastHref, _) := lastPageOfChapter g group
      -- The seam is on the page itself, keyed by its file path (strip the in-page anchor).
      let lastPath := ((lastHref.splitOn "#").headD "") ++ "index.html"
      let label := s!"{g + 2}. {humanizeWord next.key}"
      nextFix := nextFix.insert lastPath
        (navAnchor s!"{groupHrefOf next.key}#{chapterTagOf next.key}" label "next"
          (arrowFirst := false))
  let globalDocs ← readDocsTable (stashDir / "docs-global.json")
  let mut chapterDocs : Array (Std.HashMap Nat (Json × Nat)) := #[]
  for g in [0:groups.size] do
    chapterDocs := chapterDocs.push (← readDocsTable (stashDir / s!"docs-g{g}.json"))
  let mut assign : Std.HashMap (String × Nat) Nat × Array (Nat × Json) := ({}, #[])
  for path in orderedPagePaths groups ctx do
    let file := htmlDir / path
    if !(← file.pathExists) then continue
    let text ← IO.FS.readFile file
    let chapter? := chapterOfPagePath groups path
    -- Sidebar first, so hover ids inside the substituted block (there are none, but the order
    -- makes that a fact rather than an assumption) are remapped like everything else.
    let isChapterIndex := chapter?.bind (groups[·]?)
      |>.any fun g => path == s!"{groupHrefOf g.key}index.html"
    let toc? := if isChapterIndex then tocChecked? else tocPlain?
    let text := match chapter?.bind (groups[·]?), toc? with
      | some group, some fullToc =>
        match splitAroundRootToc text with
        | some (before, _, after) =>
          before ++ markCurrentChapter fullToc (groupHrefOf group.key) ++ after
        | none => text
      | _, _ => text
    let text := match prevFix.get? path with
      | some anchor => replacePrevAnchors text anchor
      | none => text
    let text := match nextFix.get? path with
      | some anchor => fillMissingNext text anchor
      | none => text
    let text := if chapter?.isNone then normalizeHeadAssets text refHead else text
    let runDocs := match chapter?.bind (chapterDocs[·]?) with
      | some docsTable => docsTable
      | none => globalDocs
    let (text, assign') := remapHoverIds text runDocs assign
    assign := assign'
    IO.FS.writeFile file text
  let (_, table) := assign
  let merged := Json.mkObj (table.toList.map fun (i, payload) => (toString i, payload))
  IO.FS.writeFile (htmlDir / "-verso-docs.json") (toString merged)

/-- Per-domain union of every run's `xref.json`. Entry ids collide only where the runs rendered the
same part — a chapter as a stub in one run and real in another — and those entries are equal, so
first-come precedence is a tie-break rather than a choice. -/
private def mergeXrefFiles (files : Array System.FilePath) : IO Json := do
  let mut merged : Json := Json.mkObj []
  for file in files do
    if !(← file.pathExists) then continue
    let .ok (Json.obj domains) := Json.parse (← IO.FS.readFile file) | continue
    for (domain, body) in domains.toArray do
      match merged.getObjVal? domain with
      | .error _ => merged := merged.setObjVal! domain body
      | .ok existing =>
        let existingContents := (existing.getObjVal? "contents").toOption.getD (Json.mkObj [])
        let newContents := (body.getObjVal? "contents").toOption.getD (Json.mkObj [])
        let combined := match existingContents, newContents with
          | .obj a, .obj b => Json.obj (b.foldl (init := a) fun acc k v =>
              if acc.contains k then acc else acc.insert k v)
          | _, _ => existingContents
        merged := merged.setObjVal! domain (existing.setObjVal! "contents" combined)
  return merged

/-- Replaces the `window.xref` payload the global run embedded in the `find` page — which is the
exact text of its `xref.json` — with the merged text. -/
private def spliceFindPage (htmlDir stashDir : System.FilePath) (mergedText : String) : IO Unit := do
  let findPath := htmlDir / "find" / "index.html"
  let oldXrefPath := stashDir / "xref-global.json"
  if !(← findPath.pathExists) || !(← oldXrefPath.pathExists) then return
  let oldText ← IO.FS.readFile oldXrefPath
  let page ← IO.FS.readFile findPath
  match page.splitOn "window.xref = " with
  | [before, rest] =>
    if rest.startsWith oldText then
      IO.FS.writeFile findPath
        (before ++ "window.xref = " ++ mergedText ++ (rest.drop oldText.length).toString)
    else
      IO.eprintln "warning: the find page does not embed the global run's xref.json verbatim; \
        leaving it with global-run data only"
  | _ =>
    IO.eprintln "warning: could not locate the xref payload on the find page"

/-- Verso's bucket function for search documents, reimplemented byte-for-byte (a `UInt8` sum of the
reference's UTF-8 bytes) so merged buckets land where `search-box.js` looks for them. -/
private def searchBucketOf (s : String) : UInt8 := Id.run do
  let mut h : UInt8 := 0
  for b in s.toUTF8 do
    h := h + b
  return h

/-- Rebuilds the search assets from the union of every run's buckets: one bucket set under one
version, and an index over it in the requested mode. The per-run bucket files, each under its own
run's content hash, are removed. -/
private def mergeSearchAssets (htmlDir : System.FilePath) (mode : SearchMode) : IO Unit := do
  let dir := htmlDir / "-verso-search"
  if !(← dir.pathExists) then return
  -- Union of every run's documents, keyed by reference. Duplicates come from parts rendered by
  -- more than one run (chapters as stubs), whose display fields agree where the index uses them.
  let mut docs : Std.HashMap String Json := {}
  let mut bucketFiles : Array System.FilePath := #[]
  for entry in (← dir.readDir) do
    if entry.fileName.startsWith "searchIndex_" && entry.path.extension == some "js" then
      bucketFiles := bucketFiles.push entry.path
      let some payload := bucketPayload (← IO.FS.readFile entry.path) | continue
      let .ok (Json.obj kvs) := Json.parse payload | continue
      docs := kvs.foldl (init := docs) fun acc ref doc =>
        if acc.contains ref then acc else acc.insert ref doc
  for file in bucketFiles do
    IO.FS.removeFile file
  let titles := docs.toArray.filterMap (fun (ref, doc) =>
      (doc.getObjValAs? String "header").toOption.map (ref, ·))
    |>.qsort (·.1 < ·.1)
  let payload := match mode with
    | .names => (titleOnlyIndex titles).compress
    | _ => (titleOnlyIndex #[]).compress
  let version := hex16 (hash payload)
  if mode == .names then
    let mut buckets : Std.HashMap UInt8 (Array (String × Json)) := {}
    for (ref, doc) in docs.toArray.qsort (·.1 < ·.1) do
      let b := searchBucketOf ref
      buckets := buckets.alter b fun v => some ((v.getD #[]).push (ref, doc))
    for (b, entries) in buckets.toArray do
      let json := Json.mkObj (entries.toList.map fun (ref, doc) => (ref, doc))
      IO.FS.writeFile (dir / s!"searchIndex_{b}.{version}.js")
        s!"window.docContents[{b}].resolve({json.compress});"
  let indexJs := "const __verso_searchIndexData = " ++ payload ++ ";\n\n"
    ++ "const __versoSearchIndex = elasticlunr ? elasticlunr.Index.load(__verso_searchIndexData) : null;\n"
    ++ "window.docContents = {};\n"
    ++ "window.searchIndex = elasticlunr ? __versoSearchIndex : null;\n"
    ++ "window.docPriorities = {};\n"
    ++ "window.searchIndexVersion = " ++ toString (Json.str version) ++ ";\n"
  IO.FS.writeFile (dir / "searchIndex.js") indexJs
  IO.println s!"Merged search buckets from the per-chapter runs: \
    {docs.size} documents, index {payload.utf8ByteSize / 1048576} MB"

/-- Renders the site one chapter at a time. See the section comment above for the design; this is
the orchestration. `manualMain` runs once with every chapter stubbed (the global pages), then once
per chapter in descending order (so every stub page is overwritten by the run that owns it), and
the stitch passes reconstruct what Verso would have derived from the whole tree. -/
def buildSitePerChapter (cfg : Cli) (data : CollectedData) (groups : Array GroupInfo)
    (ctx : SiteContext) (overviewBlocks : Array (Block Manual))
    (versoArgs : List String) (config : RenderConfig) : IO UInt32 := do
  let out := cfg.outputDir.getD "."
  let htmlDir := System.FilePath.mk out / "html-multi"
  let stashDir := System.FilePath.mk out / ".per-chapter-stash"
  let n := groups.size
  -- The global run: real landing and utility pages, every chapter a stub.
  let globalRoot := mkRootPart cfg data.rootPrefix groups data.decls ctx overviewBlocks
    (groupParts? := some (groups.map stubGroupPart))
  let code ← manualMain globalRoot (options := versoArgs) (config := config)
  if code != 0 then return code
  stashRunArtifacts htmlDir stashDir "global" (pages := true)
  IO.println s!"Per-chapter: global pages rendered, {n} chapters to go"
  -- Chapter runs, descending: run g renders chapter g in full behind stubs for 0..g-1, so its
  -- numbering is right and every stub it writes belongs to a later run.
  for i in [0:n] do
    let g := n - 1 - i
    let some group := groups[g]? | continue
    let parts := ((groups.extract 0 g).map stubGroupPart).push (mkGroupPart group ctx)
    let root := mkRootPart cfg data.rootPrefix groups data.decls ctx overviewBlocks
      (groupParts? := some parts) (withUtility := false) (withLanding := false)
    let code ← manualMain root (options := versoArgs) (config := config)
    if code != 0 then return code
    stashRunArtifacts htmlDir stashDir s!"g{g}" (pages := false)
    IO.println s!"Per-chapter: {group.key} rendered ({i + 1}/{n})"
  restoreGlobalPages htmlDir stashDir
  -- Stitching, in dependency order: prune first so the sidebar lifted from the landing page is
  -- the pruned one; then the per-page pass; then the global artifacts.
  let (pages, saved) ← pruneSidebarSubTocsIn htmlDir
  if pages > 0 then
    IO.println s!"Pruned the sidebar's inherited sub-tables from {pages} pages, \
      saving {saved / 1048576} MB"
  stitchPages htmlDir stashDir groups ctx
  let xrefFiles := (Array.range n |>.map fun g => stashDir / s!"xref-g{g}.json")
    |>.push (stashDir / "xref-global.json")
  let merged ← mergeXrefFiles xrefFiles
  let mergedText := toString merged
  IO.FS.writeFile (htmlDir / "xref.json") mergedText
  spliceFindPage htmlDir stashDir mergedText
  mergeSearchAssets htmlDir cfg.searchMode
  -- The stash was only ever an implement of this function; a deployment must not ship it.
  IO.FS.removeDirAll stashDir
  return 0

end

end Referee
