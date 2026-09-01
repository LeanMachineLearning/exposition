module

public import Referee.Website.Blocks
-- For `--search`, which rebuilds the index Verso emitted using the same builder Verso builds it
-- with, rather than hand-writing elasticlunr's on-disk shape.
public import VersoSearch

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
# Rewriting what Verso wrote

Three passes over the rendered HTML, each removing bytes that were never read. They run after
`manualMain` rather than inside the render because each is a property of the whole output directory
rather than of any one page, and because all three are measured in the same unit: what a reader
downloads.

Together they are the difference between a site that opens and one that does not — on
brownian-motion, 1.34 GB of a 1.5 GB site was sidebar tables no browser displayed, and 47 MB of the
alpha-rar site was the same stylesheet written into every page.
-/

/-! ## Pruning the sidebar's inherited sub-tables

Verso's split table of contents emits, on every page, the children of *every* level on the path to
that page. That suits a manual, where a level has a handful of siblings. It does not suit this site:
the tree is chapter → module → declaration, so every declaration page carries a table listing all of
its module's declarations. The cost is quadratic in a module's size, and monolithic Lean files are
where it bites — one 2223-declaration module produced a 600 kB table on each of 2223 pages, 1.34 GB
of that site's 1.5 GB.

Those bytes were never read. `assets/toc.js` has always removed the non-root blocks on load
(`.split-toc:not(.book)`), because the navigation they duplicate is better served by the module
page's declaration list, by Browse and by search. This removes them before they are written rather
than after they are parsed: the same site a reader has always seen, minus the transfer, the parse
and the storage.

The root block stays. It is what the sidebar actually shows, and `toc.js` reads the utility pages'
real hrefs out of it (`findUtilityHrefs`) before building the top nav, so dropping it would break
those links rather than merely shrink them. -/

/-- The opening tag of a sub-table block. Matched exactly, so that `class="split-toc book"` — the
root block, which is kept — does not match it. -/
private def splitTocOpenTag : String := "<div class=\"split-toc\">"

/-- Given the text immediately following a `splitTocOpenTag`, the text immediately following the
`</div>` that closes it, or `none` if the tags are unbalanced.

Splitting on `</div>` rather than walking characters keeps this linear and free of `String.Pos`
arithmetic: each piece is the text between two closing tags, and the number of `<div` occurrences in
it is how far the nesting went in between. Verso never nests these blocks inside one another, so the
first return to depth zero is this block's end. -/
def afterSplitTocBlock (s : String) : Option String := Id.run do
  let pieces := s.splitOn "</div>"
  let mut depth : Int := 1
  let mut consumed := 0
  for piece in pieces do
    consumed := consumed + 1
    -- The opening tags inside this piece, then the `</div>` that terminated it.
    depth := depth + ((piece.splitOn "<div").length - 1 : Nat) - 1
    if depth == 0 then
      return some (String.intercalate "</div>" (pieces.drop consumed))
  -- Nothing closes the final piece, so reaching here means the block never closed.
  return none

/-- Removes every sub-table block from one rendered page, keeping the root block.

Conservative by construction: if any block turns out to be unbalanced, the page is returned exactly
as Verso wrote it. A sidebar larger than it needs to be is a size problem; truncated HTML is a
broken page. -/
def pruneSidebarSubTocs (html : String) : String := Id.run do
  match html.splitOn splitTocOpenTag with
  | [] | [_] => return html
  | first :: rest =>
    let mut out := first
    for chunk in rest do
      let some tail := afterSplitTocBlock chunk
        | return html
      out := out ++ tail
    return out

/-- Rewrites every `.html` file under `dir`, returning how many were shortened and by how much.

Recursive rather than a single `readDir`: the pages sit one directory deeper per level of the tree,
which is where all but a handful of them live. -/
partial def pruneSidebarSubTocsIn (dir : System.FilePath) : IO (Nat × Nat) := do
  if !(← dir.pathExists) then
    return (0, 0)
  let mut pages := 0
  let mut saved := 0
  for entry in (← dir.readDir) do
    if (← entry.path.isDir) then
      let (p, s) ← pruneSidebarSubTocsIn entry.path
      pages := pages + p
      saved := saved + s
    else if entry.path.extension == some "html" then
      let text ← IO.FS.readFile entry.path
      let pruned := pruneSidebarSubTocs text
      if pruned.utf8ByteSize < text.utf8ByteSize then
        IO.FS.writeFile entry.path pruned
        pages := pages + 1
        saved := saved + (text.utf8ByteSize - pruned.utf8ByteSize)
  return (pages, saved)

/-! ### Hoisting shared inline assets

Verso inlines the theme's stylesheet and the genre's scripts into the `<head>` of every page it
writes. For a manual that is the right trade — a few dozen pages, and one fewer request each. For a
library site it is the dominant cost, and it grows with the page count rather than with anything a
reader asked for.

Measured on an 859-declaration `Mathlib.Dynamics` site: **74.2% of every declaration page** was
byte-identical boilerplate — 37.8 kB of CSS and 20.2 kB of script against 16.4 kB of actual content.
Mathlib exposes 304,210 declarations, which puts the same duplication at roughly 17.6 GB, and makes
every navigation re-parse 58 kB the browser already holds.

Hoisting works here because every page Verso writes carries a `<base href>`, so a single
site-root-relative path resolves correctly from every depth of the tree. The files land in
`-verso-data/`, beside the assets this site already ships, and are named by a hash of their contents
so that a build which changes them changes the URL.

The transform is deliberately narrow, and its narrowness is the whole safety argument:

* **Only attribute-less blocks.** `<style>` and `<script>` are matched as exactly those strings, so
  `<script id="graph-data" type="application/json">` and `<script id="audit-control" …>` — the two
  per-page payloads that the graph and the audit control read back out of the DOM — are literal text
  to this pass and are never touched. Hoisting one would break the page rather than shrink it.
* **Only blocks that repeat.** A block occurring once is per-page data by definition, and a file
  plus a request is a worse trade than the bytes it would save.
* **Only blocks worth a request**, hence `minInlineAssetSize`.
* **Position is preserved.** A `<link>` replaces a `<style>` where it stood, so the cascade order is
  unchanged, and a `<script src>` without `defer` executes in document order exactly as the inline
  block did.

A page that does not have the expected shape is written back exactly as Verso wrote it, for the same
reason `pruneSidebarSubTocs` is conservative: a page larger than it needs to be is a size problem,
truncated HTML is a broken page. -/

/-- The two kinds of inline block worth hoisting, which differ only in the tag they arrive as and
in the reference that replaces them. -/
private inductive InlineAssetKind where
  /-- An attribute-less `<style>` block, replaced by a stylesheet `<link>`. -/
  | css
  /-- An attribute-less `<script>` block, replaced by a `<script src>`. -/
  | js
deriving BEq, Repr

/-- The tag this kind arrives as. -/
private def InlineAssetKind.tag : InlineAssetKind → String
  | .css => "style"
  | .js => "script"

/-- The file extension this kind is written out as. -/
private def InlineAssetKind.ext : InlineAssetKind → String
  | .css => "css"
  | .js => "js"

/-- The kind a tag denotes. -/
private def InlineAssetKind.ofTag (tag : String) : InlineAssetKind :=
  if tag == "style" then .css else .js

/-- The markup that replaces a hoisted block, referring to `file` under `-verso-data/`.

Site-root-relative, which is what every page's `<base href>` makes correct at every depth. -/
private def InlineAssetKind.reference (kind : InlineAssetKind) (file : String) : String :=
  match kind with
  | .css => "<link rel=\"stylesheet\" href=\"-verso-data/" ++ file ++ "\"/>"
  | .js => "<script src=\"-verso-data/" ++ file ++ "\"></script>"

/-- Below this many bytes a block stays inline: a separate file costs a request and a cache entry,
and the transfer saved would not pay for either. Verso's small per-page scripts sit well under it
and the theme's stylesheets well over, so this separates them without naming either. -/
private def minInlineAssetSize : Nat := 512

/-- Both hoistable kinds, in the order the passes below visit them. -/
private def inlineAssetKinds : Array InlineAssetKind := #[.css, .js]

/-- What a hoisted block is called on disk: its kind, and a hash of its contents. Content-addressed
so the URL changes exactly when the bytes do, which is what lets these be served immutable.

Shares `hex16` with the semantic-hash rendering for the same reason it exists there: the result is
compared for equality and for nothing else, so a fixed-width identifier is what is wanted. -/
private def inlineAssetFileName (kind : InlineAssetKind) (body : String) : String :=
  "referee-inline-" ++ hex16 (hash body) ++ "." ++ kind.ext

/-- Splits `html` into the literal text surrounding attribute-less `<tag>`…`</tag>` blocks and the
bodies of those blocks, in order, or `none` if any block is left unterminated.

`literals` is always one longer than `bodies`, so the two rejoin by interleaving.

The opening tag is matched as exactly `<tag>`, which is what confines this to blocks carrying no
attributes — see the note above for why that is the safety property that matters. -/
private def splitInlineBlocks (html : String) (tag : String) :
    Option (Array String × Array String) := Id.run do
  let closing := "</" ++ tag ++ ">"
  match html.splitOn ("<" ++ tag ++ ">") with
  | [] => return none
  | first :: rest =>
    let mut literals := #[first]
    let mut bodies : Array String := #[]
    for chunk in rest do
      match chunk.splitOn closing with
      -- An opening tag with no closing one after it: not the shape this expects.
      | [] | [_] => return none
      | body :: tail =>
        bodies := bodies.push body
        literals := literals.push (String.intercalate closing tail)
    return some (literals, bodies)

/-- Rebuilds a page split by `splitInlineBlocks`, replacing each body for which `replace` gives a
reference and restoring the block verbatim for every other. -/
private def rejoinInlineBlocks (tag : String) (literals bodies : Array String)
    (replace : String → Option String) : String := Id.run do
  let opening := "<" ++ tag ++ ">"
  let closing := "</" ++ tag ++ ">"
  let mut out := literals[0]!
  for i in [0:bodies.size] do
    let body := bodies[i]!
    out := out ++ (match replace body with
      | some ref => ref
      | none => opening ++ body ++ closing)
    out := out ++ literals[i + 1]!
  return out

/-- Counts how many times each attribute-less inline block occurs across every page under `dir`.

Keyed by tag as well as body, because the same text under two tags is two different assets.
Recursive for the same reason `pruneSidebarSubTocsIn` is: the pages sit one directory deeper per
level of the tree. -/
private partial def scanInlineAssetsIn (dir : System.FilePath)
    (counts : Std.HashMap (String × String) Nat) : IO (Std.HashMap (String × String) Nat) := do
  let mut counts := counts
  for entry in (← dir.readDir) do
    if (← entry.path.isDir) then
      counts ← scanInlineAssetsIn entry.path counts
    else if entry.path.extension == some "html" then
      let text ← IO.FS.readFile entry.path
      for kind in inlineAssetKinds do
        if let some (_, bodies) := splitInlineBlocks text kind.tag then
          for body in bodies do
            counts := counts.alter (kind.tag, body) fun n => some (n.getD 0 + 1)
  return counts

/-- Rewrites every page under `dir`, replacing the blocks named in `names` with references to their
files. Returns how many pages were shortened and by how much. -/
private partial def rewriteInlineAssetsIn (dir : System.FilePath)
    (names : Std.HashMap (String × String) String) : IO (Nat × Nat) := do
  let mut pages := 0
  let mut saved := 0
  for entry in (← dir.readDir) do
    if (← entry.path.isDir) then
      let (p, s) ← rewriteInlineAssetsIn entry.path names
      pages := pages + p
      saved := saved + s
    else if entry.path.extension == some "html" then
      let text ← IO.FS.readFile entry.path
      let mut out := text
      for kind in inlineAssetKinds do
        if let some (literals, bodies) := splitInlineBlocks out kind.tag then
          out := rejoinInlineBlocks kind.tag literals bodies fun body =>
            (names[(kind.tag, body)]?).map kind.reference
      if out.utf8ByteSize < text.utf8ByteSize then
        IO.FS.writeFile entry.path out
        pages := pages + 1
        saved := saved + (text.utf8ByteSize - out.utf8ByteSize)
  return (pages, saved)

/-- Hoists every shared attribute-less inline block out of the pages under `dir` into the
`-verso-data` directory beneath it, returning how many pages were shortened, by how much, and how
many files were written.

Two passes over the tree rather than one: which blocks are shared is not known until every page has
been read, and holding the pages in memory to avoid the second read is exactly the cost this exists
to remove. The table between the passes holds only the distinct blocks — a handful, tens of
kilobytes — never the pages. -/
def hoistInlineAssetsIn (dir : System.FilePath) : IO (Nat × Nat × Nat) := do
  if !(← dir.pathExists) then
    return (0, 0, 0)
  let counts ← scanInlineAssetsIn dir {}
  -- `blockTag`, not `tag`: in pattern position the latter resolves to `Html.tag`.
  let shared := counts.fold (init := #[]) fun acc (blockTag, body) n =>
    if n ≥ 2 && body.utf8ByteSize ≥ minInlineAssetSize then acc.push (blockTag, body) else acc
  if shared.isEmpty then
    return (0, 0, 0)
  let assetDir := dir / "-verso-data"
  IO.FS.createDirAll assetDir
  let mut names : Std.HashMap (String × String) String := {}
  for (blockTag, body) in shared do
    let kind := InlineAssetKind.ofTag blockTag
    let file := inlineAssetFileName kind body
    IO.FS.writeFile (assetDir / file) body
    names := names.insert (blockTag, body) file
  let (pages, saved) ← rewriteInlineAssetsIn dir names
  return (pages, saved, shared.size)

/-! ### Narrowing the search index

Verso indexes the full text of every page. For a manual that is right — its pages are prose, and a
reader half-remembers a phrase. For a library it is the single largest artifact on the site and it
answers a question nobody asked: measured at **16.7 kB per declaration**, which is about 5 GB across
Mathlib's 304,210, in a file `defer`-loaded by *every* page. Someone searching a library site is
looking for a name, not a sentence.

`--search names` keeps Verso's search box, its ranking, its result rendering and its links, and
changes only what the inverted index is built over: each document's title instead of its text. On
this site a declaration page's title is the declaration's name and a module page's is the module's,
which is exactly the thing worth finding.

The rewrite is deliberately the smallest one that works. Verso splits its search output in two: an
eagerly-loaded `searchIndex.js` holding the inverted index, and per-bucket `searchIndex_<n>.js`
files holding each document's stored fields, fetched only when a result is shown. **Only the
inverted index is replaced.** The buckets are left exactly as Verso wrote them, so every result
still renders its real title, breadcrumb and excerpt, and `window.searchIndexVersion` — which is how
the loader reconstructs bucket URLs — is preserved untouched along with the rest of the file.

`--search none` writes the same file with an index over no documents and deletes the buckets. The
box stays and finds nothing, which is the honest behaviour for a site published somewhere the index
cannot be hosted; it is not a way to make search better. -/

/-- Where Verso writes the search assets, relative to the output directory. -/
private def searchAssetDir (out : System.FilePath) : System.FilePath :=
  out / "html-multi" / "-verso-search"

/-- The JSON a bucket file wraps, i.e. the argument of its `resolve(…)` call.

Verso writes these as `window.docContents[<n>].resolve(<json>);`, so this recovers `<json>` without
needing to know `<n>`. -/
def bucketPayload (text : String) : Option String :=
  match text.splitOn ".resolve(" with
  | [] | [_] => none
  | _ :: rest =>
    let body := (String.intercalate ".resolve(" rest).trimAscii.toString
    if body.endsWith ");" then some (body.dropEnd 2).toString else none

/-- Reads the id → title map back out of the bucket files, which is everything needed to rebuild the
inverted index over titles alone.

Read from Verso's own output rather than rebuilt from `data.decls` so that the ids are by
construction the ones the pages were written with: an index whose refs did not match would produce
results that lead nowhere, and would do it silently. -/
private def readSearchTitles (dir : System.FilePath) : IO (Array (String × String)) := do
  let mut out := #[]
  for entry in (← dir.readDir) do
    if entry.fileName.startsWith "searchIndex_" && entry.path.extension == some "js" then
      let text ← IO.FS.readFile entry.path
      let some payload := bucketPayload text | continue
      let .ok json := Json.parse payload | continue
      match json with
      | .obj kvs =>
        out := kvs.foldl (init := out) fun acc ref doc =>
          match doc.getObjValAs? String "header" with
          | .ok header => acc.push (ref, header)
          | .error _ => acc
      | _ => continue
  return out

/-- The bucket files, which `--search none` removes and `--search names` leaves alone. -/
private def searchBucketFiles (dir : System.FilePath) : IO (Array System.FilePath) := do
  let mut out := #[]
  for entry in (← dir.readDir) do
    if entry.fileName.startsWith "searchIndex_" && entry.path.extension == some "js" then
      out := out.push entry.path
  return out

/-- An elasticlunr index over `docs`, each indexed by its title alone.

The field layout matches `Verso.Search.IndexM.finalize` exactly — `id`, `header`, `contents`, with
`id` as the reference — because the browser-side loader is Verso's and expects that shape. Two
values differ from what Verso would pass:

* `contents` gets the title rather than the page's text, which is the point of the mode. It gets the
  title rather than the empty string because `search-box.js` queries `contents` with a boost of 1,
  so the field has to carry tokens for a match to score.
* `id` gets the empty string rather than the reference. Verso passes the reference and then indexes
  it, since the guard in `Index.addDoc` compares a *field name* against the *reference value* and so
  never fires. Nothing queries `id` — `search-box.js` boosts `header` and `contents` and no other
  field — so those postings are dead weight, and on a name index they were 29% of it. -/
def titleOnlyIndex (docs : Array (String × String)) : Json :=
  let builder : Verso.Search.IndexBuilder := { refField := "id" }
  let empty := builder.addField "id" |>.addField "header" |>.addField "contents" |>.build
  let index := docs.foldl (init := empty) fun idx (ref, title) =>
    idx.addDoc ref #["", title, title]
  -- Verso stores the documents in the buckets, not in the index, and the loader expects the same.
  (index.extractDocs.fst).toJson

/-- Replaces the inverted index inside `searchIndex.js`, keeping the rest of the file — the priority
map and the bucket version — exactly as Verso wrote it. Returns the old and new payload sizes, or
`none` if the file was not the expected shape. -/
private def replaceSearchPayload (file : System.FilePath) (payload : String) :
    IO (Option (Nat × Nat)) := do
  let text ← IO.FS.readFile file
  let marker := "const __verso_searchIndexData = "
  if !text.startsWith marker then
    return none
  -- `compress` emits no newlines, so the first blank-line-terminated `;` is the one Verso wrote to
  -- close the assignment and cannot occur inside the payload.
  match (text.drop marker.length).toString.splitOn ";\n\n" with
  | [] | [_] => return none
  | old :: tail =>
    IO.FS.writeFile file (marker ++ payload ++ ";\n\n" ++ String.intercalate ";\n\n" tail)
    return some (old.utf8ByteSize, payload.utf8ByteSize)

/-- Applies `--search` to the site Verso has just written. A no-op for `full`, which is Verso's own
output. -/
def applySearchMode (mode : SearchMode) (out : System.FilePath) : IO Unit := do
  if mode == .full then
    return
  let dir := searchAssetDir out
  if !(← dir.pathExists) then
    return
  let titles ← if mode == .names then readSearchTitles dir else pure #[]
  let payload := (titleOnlyIndex titles).compress
  match ← replaceSearchPayload (dir / "searchIndex.js") payload with
  | none =>
    IO.eprintln "warning: could not recognise the search index Verso wrote; leaving it alone"
  | some (old, new) =>
    if mode == .none then
      for bucket in ← searchBucketFiles dir do
        IO.FS.removeFile bucket
      IO.println s!"Emptied the search index ({old / 1048576} MB), and removed its buckets"
    else
      IO.println s!"Rebuilt the search index over {titles.size} titles: \
        {old / 1048576} MB to {new / 1048576} MB"

end

end Referee
