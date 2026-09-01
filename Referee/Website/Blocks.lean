module

public import Lean
public import Lean.DeclarationRange
public import Lean.Meta.Instances
public import Lean.Util.Sorry
public import MD4Lean
public import VersoManual
public import VersoManual.Markdown
public import VersoManual.ExternalLean
public import SubVerso.Highlighting
public import SubVerso.Module
public import Referee.Audit
public import Referee.Collect
public import Referee.Diff
public import Referee.Highlight
public import Referee.Provenance

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
# The chapter tree, and the site's block extensions

Everything on a page that is not prose is one of the `block_extension`s below: a payload type
declared in `Collect.lean` paired with the HTML it becomes. That pair is the whole seam between the
analysis and the page — a page builder decides *which* declarations a block carries and nothing at
all about how it looks.

They are gathered here rather than beside the pages that emit them because most are emitted from
several: `Block.declIndex` is the listing on module pages, on the sorries page and under every
closure; `Block.claimList` is the Theorems page, the Claims page and the landing page's excerpt of
both. One reading of a block beats three.

Also here, and below them for the same reason, is the chapter/module tree the whole site is ordered
by. `buildModules` and `buildGroups` are the input every page builder takes, so they belong under
all of them.

## One plain `public section`

Not `@[expose]`, and that is load-bearing rather than a preference: `block_extension` expands to a
`public def X.descr := X.descr.inner` whose body mentions the `private` definition the macro
generates alongside it, and that reference only resolves while the body stays unexposed. Every
module of the site is built the same way, so a page builder's body is its own business and its
helpers can stay `private`.
-/

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
def moduleDocBlocks (env : Environment) (name : Name) : Array (Block Manual) :=
  match Lean.getModuleDoc? env name with
  | none => #[]
  | some docs => docs.foldl (fun acc doc => acc ++ markdownToBlocks doc.doc) #[]

/-- Builds module summaries from declarations and applies stable ordering. `moduleDocs` is the
per-module doc-comment blocks computed once (with the live environment) during `collect`. -/
def buildModules (rootPrefix : Name) (order : Std.HashMap Name Nat)
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
def buildGroups (order : Std.HashMap Name Nat) (mods : Array ModuleInfo) : Array GroupInfo :=
  let groupRank (group : GroupInfo) : Nat :=
    group.modules.foldl (fun best modInfo => min best (moduleRank order modInfo.name)) 1000000000
  groupIndexMap mods |>.toArray
    |>.map (fun (key, modules) => { key, modules := sortModules order modules })
    |>.qsort (fun a b =>
      let ra := groupRank a
      let rb := groupRank b
      if ra == rb then a.key < b.key else ra < rb)

/-- Builds a source-link paragraph when a source URL is available. -/
def mkSourceParagraph (label : String) (url? : Option String) : Array (Block Manual) :=
  match url? with
  | some url => #[.para #[.bold #[.text "Source: "], .link #[.text label] url]]
  | none => #[]

/-- The visibility group a declaration belongs to, matching the "Hide Definitions" /
"Hide Lemmas" / "Hide Theorems" toggles and the `data-decl-group` attribute on its card. -/
def declGroupOfFields (kindLabel : String) (isLemma isInstanceDecl : Bool) : String :=
  let isMainTheorem := kindLabel == "Theorem" && !isLemma && !isInstanceDecl
  if isMainTheorem then "theorem"
  else if kindLabel == "Theorem" || kindLabel == "Instance" then "lemma"
  else "definition"


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
    -- No name of its own. The card is the only one on its page and the page's `<h1>` is that name,
    -- so a heading above the card and a name inside it printed it a second and third time — once
    -- abbreviated, once in full — within a few lines of the title. The `id` moves here from the
    -- heading that carried it, so `#anchorId` still lands on the card.
    pure {{
      <section id={{payload.anchorId}} class="decl-section" data-decl-kind={{payload.kindLabel}}
          data-card-group={{declGroup}}>
        <div class={{cardClass}}>
          <div class="decl-card-header">
            <div class="decl-card-title">
              <span class={{labelClass}}>{{displayLabel}}</span>
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
      -- Annotated: without it the `Coe String Html` at the use site below makes `base` an `Html`
      -- and the string interpolation stops elaborating.
      let metaText : String :=
        let base :=
          match entry.deps with
          | some n => s!"{entry.kind} · {n} deps"
          | none => entry.kind
        if entry.note.isEmpty then base else s!"{base} · {entry.note}"
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

/- A specification listing: the theorems an author declared to be part of a definition's
specification, or the definitions a theorem specifies.

Deliberately not a `declIndex`. That renders one link per line, which is right for "everything this
rests on" — a list nobody reads in full — and wrong here: a specification is three or four
properties, and whether they pin the definition down is a question about the *statements*. So each
row carries the statement and the author's note, and the reader decides without leaving the page.

(A plain comment, not a docstring: `block_extension` does not take one.) -/
block_extension Block.specList (_payload : SpecListData) where
  data := ToJson.toJson _payload
  traverse _ _ _ _ := pure none
  toTeX := some fun _goI goB _id _data contents => contents.mapM goB
  toHtml := some fun _goI _goB _id data _ => do
    let .ok (payload : SpecListData) := FromJson.fromJson? data
      | Verso.reportError s!"Could not decode specification data from {data.compress}"
        pure .empty
    let rows := payload.entries.map fun entry =>
      let nameHtml :=
        if entry.href.isEmpty then
          {{<span class="spec-item-name"><code>{{entry.name}}</code></span>}}
        else
          {{<a class="spec-item-name" href={{entry.href}}><code>{{entry.name}}</code></a>}}
      let comment :=
        if entry.comment.isEmpty then .empty
        else {{<p class="spec-item-comment">{{entry.comment}}</p>}}
      let statement :=
        if entry.signature.isEmpty then .empty
        else {{<pre class="spec-item-statement"><code>{{entry.signature}}</code></pre>}}
      {{
        <li class="spec-item">
          <div class="spec-item-head">
            {{nameHtml}}
            <span class="spec-item-kind">{{entry.kind}}</span>
          </div>
          {{comment}}
          {{statement}}
        </li>
      }}
    pure {{<ul class="spec-list">{{rows}}</ul>}}

/- A characterization listing: the claim that a property does not merely hold of a definition but
*determines* it, up to a stated relation (`Block.charList`).

Deliberately not a `specList`, though it shows the same statements. A specification is a flat list
of properties and reads as one; a characterization is a single claim assembled from three
declarations, and the thing a reader most needs is not in any of them individually — it is the
relation the uniqueness theorem stops at. So each bundle is one card, banner first: `x = y` and
`f =ᵐ[μ] g` are very different claims about how well a definition is pinned down, and the site would
be overstating the second if it rendered them alike.

An incomplete bundle is drawn as a gap rather than dropped, in the same spirit as the "No
specification" note: the author began a claim and did not finish it, which is a finding.

(A plain comment, not a docstring: `block_extension` does not take one.) -/
block_extension Block.charList (_payload : CharListData) where
  data := ToJson.toJson _payload
  traverse _ _ _ _ := pure none
  toTeX := some fun _goI goB _id _data contents => contents.mapM goB
  toHtml := some fun _goI _goB _id data _ => do
    let .ok (payload : CharListData) := FromJson.fromJson? data
      | Verso.reportError s!"Could not decode characterization data from {data.compress}"
        pure .empty
    let rows := payload.entries.map fun entry =>
      let complete := entry.hasExistence && entry.hasUniqueness
      -- The banner reports the relation and the banner reports the gap; it never reports both as
      -- if the claim held. An unfinished bundle keeps the warning colour even when it does have a
      -- relation to show, because a relation nothing is known to satisfy is not reassurance.
      let banner :=
        if entry.relations.isEmpty then
          {{
            <div class="char-banner char-banner-gap">
              <span class="char-banner-label">"Not determined"</span>
              <span class="char-banner-rels">
                <span class="char-relation-missing">"no uniqueness theorem"</span>
              </span>
            </div>
          }}
        else
          {{
            <div class={{if complete then "char-banner" else "char-banner char-banner-gap"}}>
              <span class="char-banner-label">"Determined up to"</span>
              <span class="char-banner-rels">
                {{entry.relations.map fun (r : String) =>
                    {{<code class="char-relation">{{r}}</code>}}}}
              </span>
            </div>
          }}
      -- One sentence saying exactly what the bundle establishes. It is the line most likely to be
      -- the only thing read, so it must not claim uniqueness for a bundle that has not shown it.
      let lede :=
        if complete then
          {{
            <p class="char-lede">
              "The unique object satisfying " <code>{{entry.property}}</code> "."
            </p>
          }}
        else if entry.hasExistence then
          {{
            <p class="char-lede char-lede-gap">
              "Satisfies " <code>{{entry.property}}</code>
              ". No theorem here says that nothing else does, so as it stands this is a \
                specification rather than a characterization."
            </p>
          }}
        else if entry.hasUniqueness then
          {{
            <p class="char-lede char-lede-gap">
              <code>{{entry.property}}</code>
              " determines its subject, but no theorem here says that this definition satisfies \
                it — nor, so far as this page knows, that anything does."
            </p>
          }}
        else
          {{
            <p class="char-lede char-lede-gap">
              "Put forward as characterizing this definition, with neither half of the claim \
                supplied."
            </p>
          }}
      -- Directly under the lede, before the parts: the banner has just named the relation, and
      -- "what does that mean" is the question a reader has at that exact point.
      let relationDefs :=
        if entry.relationDefs.isEmpty then .empty
        else
          {{
            <ul class="char-relation-defs">
              {{entry.relationDefs.map fun (r : CharPartRow) =>
                  let nameHtml :=
                    if r.href.isEmpty then
                      {{<span class="spec-item-name"><code>{{r.name}}</code></span>}}
                    else
                      {{<a class="spec-item-name" href={{r.href}}><code>{{r.name}}</code></a>}}
                  {{
                    <li class="spec-item char-relation-def">
                      <div class="spec-item-head">
                        <span class="char-part-role">{{r.role}}</span>
                        {{nameHtml}}
                        <span class="spec-item-kind">{{r.kind}}</span>
                      </div>
                      <pre class="spec-item-statement"><code>{{r.signature}}</code></pre>
                    </li>
                  }}}}
            </ul>
          }}
      let parts := entry.parts.map fun part =>
        let nameHtml :=
          if part.href.isEmpty then
            {{<span class="spec-item-name"><code>{{part.name}}</code></span>}}
          else
            {{<a class="spec-item-name" href={{part.href}}><code>{{part.name}}</code></a>}}
        let comment :=
          if part.comment.isEmpty then .empty
          else {{<p class="spec-item-comment">{{part.comment}}</p>}}
        -- Repeated on the row as well as in the banner: with several uniqueness theorems the
        -- banner cannot say which relation came from which, and that is the one ambiguity a
        -- reader must not be left with here.
        let relation :=
          if part.relation.isEmpty then .empty
          else
            {{
              <p class="char-part-relation">
                "up to " <code>{{part.relation}}</code>
              </p>
            }}
        let statement :=
          if part.signature.isEmpty then .empty
          else {{<pre class="spec-item-statement"><code>{{part.signature}}</code></pre>}}
        {{
          <li class="spec-item char-part">
            <div class="spec-item-head">
              <span class="char-part-role">{{part.role}}</span>
              {{nameHtml}}
              <span class="spec-item-kind">{{part.kind}}</span>
            </div>
            {{comment}}
            {{relation}}
            {{statement}}
          </li>
        }}
      {{
        <li class="char-bundle">
          {{banner}}
          {{lede}}
          {{relationDefs}}
          <ul class="spec-list char-parts">{{parts}}</ul>
        </li>
      }}
    pure {{<ul class="char-list">{{rows}}</ul>}}

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
    let attrs := #[("class", if payload.headingLevel.isSome then "site-fold site-fold-heading"
                             else "site-fold")]
      -- `open` is an HTML boolean attribute: present or absent, never `open="false"`.
      ++ (if payload.startsOpen then #[("open", "")] else #[])
    pure <| Html.tag "details" attrs {{
      <summary>{{payload.summary}}</summary>
      {{← contents.mapM goB}}
    }}

/- The claims listing: one row per claim, with its docstring rendered as markdown.

The only listing on the site that is built here rather than by its JavaScript, and the reason is the
docstring — see `ClaimRow`. Coverage and verdict arrive as empty slots that `audit.js` fills, so a
verdict change rewrites two spans instead of rebuilding several hundred rows.

Rows and contents are walked in step: each row says how many of the flat contents array is its own
docstring. A `docLength` that overruns simply yields a shorter slice, so a mismatch loses a
docstring rather than mis-assigning one to the wrong claim.

(A plain comment, not a docstring: `block_extension` does not take one.) -/
block_extension Block.claimList (_payload : ClaimListData) where
  data := ToJson.toJson _payload
  traverse _ _ _ _ := pure none
  toTeX := some fun _goI goB _id _data contents => contents.mapM goB
  toHtml := some fun _goI goB _id data contents => do
    let .ok (payload : ClaimListData) := FromJson.fromJson? data
      | Verso.reportError s!"Could not decode claim list data from {data.compress}"
        pure .empty
    let mut items : Array Html := #[]
    let mut start := 0
    for row in payload.rows do
      let doc ← (contents.extract start (start + row.docLength)).mapM goB
      start := start + row.docLength
      let flag :=
        if row.dependsOnSorry then {{<span class="audit-flag">"depends on sorry"</span>}}
        else .empty
      -- Filled by `audit.js`. The server-side text is what a reader without JavaScript sees, so it
      -- says the one thing that is true without any audit state: how much is underneath.
      let depsText : String := s!"{row.deps} beneath"
      items := items.push {{
        <li class="audit-item" data-claim={{row.name}}>
          <a class="audit-name" href={{row.href}}><code>{{row.name}}</code></a>
          <span class="audit-meta" data-slot="coverage">{{depsText}}</span>
          <span data-slot="status"></span>
          {{flag}}
          <button type="button" class="audit-start" data-claim={{row.name}}>"Start reading"</button>
          {{if doc.isEmpty then .empty else {{<div class="audit-doc">{{doc}}</div>}}}}
        </li>
      }}
    pure {{<ul class="audit-list">{{items}}</ul>}}

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

/-- The parts of a rendered change shared by the Changes page and the per-declaration banner: the
aligned statements, what moved underneath it, and any trust delta.

Written once because the two renderings differ only in their chrome, and a reader who meets the
same change in both places should not have to reconcile two presentations of it.

(A plain comment, not a docstring: this is a helper for the two `block_extension`s below, which do
not take one.) -/
private def changeBodyHtml (row : ChangeRowData) : Html :=
  let diffHtml :=
    if row.diff.tokens.isEmpty then .empty
    else
      let spans := row.diff.tokens.map fun tok =>
        {{<span class={{s!"stmt-tok stmt-tok--{tok.kind}"}}>{{Html.text true tok.text}}" "</span>}}
      let coarseNote :=
        if row.diff.coarse then
          {{<p class="change-note">"Statement too long to align word by word; the whole changed
            region is marked."</p>}}
        else .empty
      {{<div><pre class="stmt-diff"><code>{{spans}}</code></pre>{{coarseNote}}</div>}}
  let statementHtml :=
    if row.statement.isEmpty then .empty
    else {{<pre class="stmt-plain"><code>{{Html.text true row.statement}}</code></pre>}}
  let causesHtml :=
    if row.causes.isEmpty then .empty
    else
      let links := row.causes.map fun cause =>
        match cause.href? with
        | some href => {{<li><a href={{href}}><code>{{cause.label}}</code></a></li>}}
        | none => {{<li><code>{{cause.label}}</code></li>}}
      {{<div class="change-causes">
          <p class="change-note">"Its statement rests on these, and they changed:"</p>
          <ul class="change-causes-list">{{links}}</ul>
        </div>}}
  -- The one kind with nothing to show: no aligned statement, because its text did not move, and no
  -- causes, because none of them are declarations this site has a page for. Without a sentence
  -- here its banner would be a bare chip, and a reader on a declaration page has not read the
  -- section heading on the Changes page that would otherwise explain it.
  let upstreamHtml :=
    if row.kind != "upstream" then .empty
    else {{<p class="change-note">"Nothing about this declaration was edited, and nothing in this
      project accounts for the change: what moved is upstream code it is stated about, or project
      code this site does not expose. Reading it again means reading it against the new version of
      whatever it rests on."</p>}}
  let trustHtml :=
    if row.trustNotes.isEmpty then .empty
    else
      {{<ul class="change-trust">
          {{row.trustNotes.map fun note => {{<li>{{Html.text true note}}</li>}}}}
        </ul>}}
  {{<div class="change-body">
      {{diffHtml}}{{statementHtml}}{{causesHtml}}{{upstreamHtml}}{{trustHtml}}
    </div>}}

/- A list of changes: one section of the Changes page.

Not a `declIndex`. That renders one link per line, which is right for a closure listing nobody reads
in full and wrong here: whether a statement change matters is a question about the *statements*, so
each row carries the aligned pair and the reader decides without following a link.

(A plain comment, not a docstring: `block_extension` does not take one.) -/
block_extension Block.changeList (_payload : ChangeListData) where
  data := ToJson.toJson _payload
  traverse _ _ _ _ := pure none
  toTeX := some fun _goI goB _id _data contents => contents.mapM goB
  toHtml := some fun _goI _goB _id data _ => do
    let .ok (payload : ChangeListData) := FromJson.fromJson? data
      | Verso.reportError s!"Could not decode change list data from {data.compress}"
        pure .empty
    let rows := payload.entries.map fun row =>
      let nameHtml :=
        if row.href.isEmpty then {{<span class="change-name"><code>{{row.name}}</code></span>}}
        else {{<a class="change-name" href={{row.href}}><code>{{row.name}}</code></a>}}
      let moduleHtml :=
        if row.module.isEmpty then .empty
        else {{<span class="change-module"><code>{{row.module}}</code></span>}}
      -- The count of what rests on the declaration is the whole reason to read the sections in the
      -- order the page puts them in, so it sits in the header rather than under the statements.
      let dependentsHtml :=
        if row.dependents == 0 then .empty
        else
          let rest := if row.dependents == 1 then "1 result rests on it"
            else s!"{row.dependents} results rest on it"
          {{<span class="change-dependents">{{rest}}</span>}}
      {{
        <li class={{s!"change-item change-item--{row.kind}"}}>
          <div class="change-head">
            {{nameHtml}}
            <span class={{s!"change-chip change-chip--{row.kind}"}}>{{row.label}}</span>
            {{moduleHtml}}
            {{dependentsHtml}}
          </div>
          {{changeBodyHtml row}}
        </li>
      }}
    pure {{<ul class="change-list">{{rows}}</ul>}}

/- The verdict control on a declaration page: three buttons, a note, and the line saying what
accepting this would and would not cover.

Only the mount point and this declaration's own statement closure are emitted. The closure is
needed to compute coverage, and it is per-declaration precisely so that a page does not have to
carry the whole library's closures — see `AuditData`, which does, and is emitted on one page only.

(A plain comment, not a docstring: `block_extension` does not take one.) -/
block_extension Block.auditControl (_payload : AuditControlData) where
  data := ToJson.toJson _payload
  traverse _ _ _ _ := pure none
  toTeX := some fun _goI goB _id _data contents => contents.mapM goB
  toHtml := some fun _goI _goB _id data _ => do
    let .ok (payload : AuditControlData) := FromJson.fromJson? data
      | Verso.reportError s!"Could not decode audit control data from {data.compress}"
        pure .empty
    pure {{
      <div id="audit-control-root">
        <noscript>"Recording what you have read needs JavaScript. Everything else on this page
          works without it."</noscript>
      </div>
      {{Html.tag "script" #[("id", "audit-control"), ("type", "application/json")]
          (.text false (ToJson.toJson payload).compress)}}
    }}

/- The claims listing's data: every declaration a row can be about, with the closure its coverage is
computed over.

`audit.js` builds the listing from it, for the same reason `browse.js` builds its table: sorting and
recomputing coverage as verdicts change has to happen in the browser, since a static site has no
server to ask.

On two pages, never both at once, so the fixed ids below are unambiguous: the claims page, which
carries the whole library and the apparatus around it, and the landing page, which carries an
excerpt — the same rows for its ranked top results and nothing else. See `AuditData.excerpt`.

(A plain comment, not a docstring: `block_extension` does not take one.) -/
block_extension Block.auditData (_payload : AuditData) where
  data := ToJson.toJson _payload
  traverse _ _ _ _ := pure none
  toTeX := some fun _goI goB _id _data contents => contents.mapM goB
  toHtml := some fun _goI _goB _id data _ => do
    let .ok (payload : AuditData) := FromJson.fromJson? data
      | Verso.reportError s!"Could not decode audit data from {data.compress}"
        pure .empty
    -- No mount point on an excerpt: the rows are already on the page, rendered in Lean, and there
    -- is no apparatus to build around them. The payload is still emitted, because coverage on those
    -- rows is computed in the browser.
    --
    -- No `noscript` fallback either, on either page, and none is needed any more: the listing is
    -- real HTML now. What JavaScript adds is the state on it.
    pure {{
      {{if payload.excerpt then .empty else {{<div id="audit-root"></div>}}}}
      {{Html.tag "script" #[("id", "audit-data"), ("type", "application/json")]
          (.text false (ToJson.toJson payload).compress)}}
    }}

/- The revision selector: pick what you last read, get what to read again.

Only the mount point and the data are emitted; `revisions.js` builds the control. See the note in
`Referee/Provenance.lean` for why this is possible on a static site and what it deliberately cannot
show.

(A plain comment, not a docstring: `block_extension` does not take one.) -/
block_extension Block.revisionPicker (_payload : RevisionPickerData) where
  data := ToJson.toJson _payload
  traverse _ _ _ _ := pure none
  toTeX := some fun _goI goB _id _data contents => contents.mapM goB
  toHtml := some fun _goI _goB _id data _ => do
    pure {{
      <div>
        <script id="revisions-data" type="application/json">{{data.compress}}</script>
        <div id="revisions-root"></div>
      </div>
    }}

/- When a declaration last meant something else, and when its file was last touched.

Two facts kept apart on purpose. Blame says somebody edited these lines; the ledger says the
meaning moved. A referee who is shown only the first re-reads a declaration that did not change,
which is precisely the work this site exists to save them.

Rendered below the card rather than above it: unlike the change banner, this is context for a
reader who has decided to look, not a warning to one who has not.

(A plain comment, not a docstring: `block_extension` does not take one.) -/
block_extension Block.provenanceLine (_payload : ProvenanceRow) where
  data := ToJson.toJson _payload
  traverse _ _ _ _ := pure none
  toTeX := some fun _goI goB _id _data contents => contents.mapM goB
  toHtml := some fun _goI _goB _id data _ => do
    let .ok (row : ProvenanceRow) := FromJson.fromJson? data
      | Verso.reportError s!"Could not decode provenance data from {data.compress}"
        pure .empty
    let meaningPart :=
      -- Never changed, but not there from the start: it was *added* at this revision. Saying
      -- "unchanged since the oldest revision on record" here would name the newest revision and
      -- call it the oldest, reporting a declaration added yesterday as part of the original
      -- library — the one thing a provenance line must not get backwards.
      if row.sinceFirstSeen && !row.seenFromStart then
        {{<span>"New in "<strong>{{row.changedRef}}</strong>" ("{{row.changedDate}}"), and its
          meaning has not changed since."</span>}}
      else if row.sinceFirstSeen then
        {{<span>"Meaning unchanged since "<strong>{{row.changedRef}}</strong>", the oldest
          revision on record ("{{row.changedDate}}")."</span>}}
      else
        {{<span>"Meaning last changed in "<strong>{{row.changedRef}}</strong>" ("
          {{row.changedDate}}")"
          {{if row.changeCount > 1 then
              {{<span>", the "{{toString row.changeCount}}"th recorded change"</span>}}
            else .empty}}
          "."</span>}}
    -- The reassuring half, and the reason the two facts are collected separately at all.
    let editPart :=
      if row.editedWithoutMeaningChange then
        {{<span>" Its file was edited "{{row.editedDate}}
          {{if row.editedSha.isEmpty then .empty
            else {{<span>" ("<code>{{row.editedSha}}</code>
              {{if row.editedSubject.isEmpty then .empty
                else {{<span>", “"{{row.editedSubject}}"”"</span>}}}}")"</span>}}}}
          " without changing what it means."</span>}}
      else .empty
    let pendingPart :=
      if row.uncommitted then
        {{<span>" Some of its lines are not committed, so this page was built from a working tree
          rather than from a revision anyone can check out."</span>}}
      else .empty
    pure {{
      <p class="provenance-line">{{meaningPart}}{{editPart}}{{pendingPart}}</p>
    }}

/- The banner at the top of a declaration page whose meaning moved.

Above the declaration card rather than below it: a reader who accepted this declaration in the
baseline has to know that before reading it again, not after.

(A plain comment, not a docstring: `block_extension` does not take one.) -/
block_extension Block.changeBanner (_payload : ChangeRowData) where
  data := ToJson.toJson _payload
  traverse _ _ _ _ := pure none
  toTeX := some fun _goI goB _id _data contents => contents.mapM goB
  toHtml := some fun _goI _goB _id data _ => do
    let .ok (row : ChangeRowData) := FromJson.fromJson? data
      | Verso.reportError s!"Could not decode change banner data from {data.compress}"
        pure .empty
    -- The baseline's date rides beside its name where a provenance ledger records one. "since
    -- 78eb329" tells a reader which revision their reading is void against; it does not tell them
    -- whether that was last week or last year, which is what decides how much has piled up behind
    -- it.
    pure {{
      <aside class={{s!"change-banner change-banner--{row.kind}"}}>
        <div class="change-head">
          <span class={{s!"change-chip change-chip--{row.kind}"}}>{{row.label}}</span>
          {{if row.since.isEmpty then .empty
            else {{<span class="change-banner-since">
              {{s!"since {row.since}"}}
              {{if row.sinceDate.isEmpty then .empty
                else {{<span class="change-banner-date">{{s!"· {row.sinceDate}"}}</span>}}}}
            </span>}}}}
        </div>
        {{changeBodyHtml row}}
      </aside>
    }}

end

end Referee
