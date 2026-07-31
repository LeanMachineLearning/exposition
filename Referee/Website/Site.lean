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
public import Referee.Audit
public import Referee.Collect
public import Referee.Diff
public import Referee.Extract
public import Referee.ExtractFlat
public import Referee.Highlight
public import Referee.Provenance

open Lake
open Lean
open Lean.Meta
open Verso.Doc
open Verso.Genre
open Manual

namespace Referee

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

/- The audit page's data: every declaration, with the closure its coverage is computed over.

Emitted here and nowhere else. `audit.js` builds the page from it, for the same reason `browse.js`
builds its table: sorting and recomputing coverage as verdicts change has to happen in the browser,
since a static site has no server to ask.

(A plain comment, not a docstring: `block_extension` does not take one.) -/
block_extension Block.auditData (_payload : AuditData) where
  data := ToJson.toJson _payload
  traverse _ _ _ _ := pure none
  toTeX := some fun _goI goB _id _data contents => contents.mapM goB
  toHtml := some fun _goI _goB _id data _ => do
    let .ok (payload : AuditData) := FromJson.fromJson? data
      | Verso.reportError s!"Could not decode audit data from {data.compress}"
        pure .empty
    pure {{
      <div id="audit-root">
        <noscript>"The audit checklist needs JavaScript."</noscript>
      </div>
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
@[expose] public section

/-- The README text up to, but not including, a "Selected References" heading at any level.

A bibliography is the one part of a README that reads as noise on a generated page,
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
private def upstreamJsFile (externals : Array ExternalDeclInfo) (trusted : Std.HashSet Name)
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
private def duplicateDeclTags (decls : Array DeclInfo) : Array (String × Array Name) :=
  let byTag := decls.foldl (init := ({} : Std.HashMap String (Array Name))) fun acc d =>
    let t := declTagOf d.name
    acc.insert t ((acc.getD t #[]).push d.name)
  byTag.toArray.filter (·.2.size > 1) |>.qsort (fun a b => a.1 < b.1)

/-- Rendering configuration for the site output.

Takes the upstream table because `upstreamJsFile` depends on the project, unlike every other asset
here, which is `include_str`-embedded at build time. -/
private def renderConfig (externals : Array ExternalDeclInfo) (trusted : Std.HashSet Name)
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
      revisionsJsFile, browseJsFile}
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

/-- The `anchorIdOf` stems for which `extract` wrote a standalone `.lean` file.

Read from the output directory rather than assumed, because `extract` is a separate phase that a
given run may not have gone through — and because the raw file is what the download and web-editor
links point at, so offering them for a file that is not there would be a dead link. -/
private def loadExtractedStems (dir : System.FilePath) : IO (Std.HashSet String) := do
  if !(← dir.pathExists) then
    return {}
  let mut acc : Std.HashSet String := {}
  for entry in (← dir.readDir) do
    if entry.path.extension == some "lean" then
      if let some stem := entry.path.fileStem then
        acc := acc.insert stem
  return acc

/-- Shared lookup tables and configuration threaded through page-building helpers. -/
private structure SiteContext where
  repoUrl? : Option String
  siteUrl? : Option String
  /-- The exposed root module prefix. Doubles as the audit state's storage key, since GitHub Pages
  serves every project of an account from one origin. -/
  rootPrefix : Name := .anonymous
  declByName : Std.HashMap Name DeclInfo
  declHrefs : Std.HashMap Name String
  declPageHrefs : Std.HashMap Name String
  /-- Declaration name ↦ highlighted source, empty when no `highlight` pass was run. -/
  declHighlights : Std.HashMap Name Highlighted := {}
  /-- `anchorIdOf` stem ↦ the declaration's minimal file, empty without `highlight-extracted`. -/
  minimalFiles : Std.HashMap String MinimalFile := {}
  /-- The workspace's packages and their dependency edges. -/
  packages : Array PackageInfo := #[]
  /-- The packages with code loaded in the environment, which bounds every closure exactly. -/
  loadedPackages : Std.HashSet Name := {}
  /-- Upstream constant ↦ what a reader needs to read it: package, module, signature, docstring.
  Lets a dependency graph show the upstream declarations a statement rests on, not merely count their
  packages, and lets clicking one answer what it says. -/
  externalDecls : Std.HashMap Name ExternalDeclInfo := {}
  /-- The packages the reader is told to take on trust: `--trust`, closed over dependencies, plus
  the toolchain. Everything else the project reaches is unaudited upstream code. -/
  trusted : Std.HashSet Name := {}
  /-- Package ↦ its depth in the workspace dependency graph (`packageRanks`), which is the order the
  graph's upstream band stacks in. -/
  packageRanks : Std.HashMap Name Nat := {}
  /-- Whether audited packages appear in the upstream band (`--show-trusted-upstream`). Unaudited
  ones always do. -/
  showTrustedUpstream : Bool := false
  /-- The upstream packages whose internal structure `collect` was able to walk, and which are
  therefore drawn as layered blocks rather than as a flat surface. -/
  expandedPackages : Std.HashSet Name := {}
  /-- The toolchain pseudo-packages, which the upstream band leaves out entirely. -/
  toolchainPackages : Std.HashSet Name := {}
  /-- `anchorIdOf` stems with a standalone `.lean` file on disk, empty without `extract`.

  Kept separate from `minimalFiles` because the two phases are independent: `extract` writes the
  files, `highlight-extracted` renders them interactively. Conflating them cost the site every
  pointer to the extracted files whenever highlighting was skipped — the files were written,
  published and reachable by URL, with nothing on any page linking to them. -/
  extractedStems : Std.HashSet String := {}
  /-- Whether the project carries any `@[specifies]` annotation at all.

  Every specification rendering is gated on this. A project that has never heard of the attribute
  must not be told on each of its definition pages that it has no specification, nor given a
  Specifications page listing every definition it owns as a gap — that is nagging about a feature,
  not auditing. Once one annotation exists the author has opted in, and silence about the rest
  becomes information. -/
  usesSpecs : Bool := false
  /-- Whether the project carries any `@[characterization]` annotation at all.

  A second gate rather than a reuse of `usesSpecs`, because the two opt-ins are separate: a project
  may specify without characterizing, and the far rarer converse — a property annotated but neither
  theorem written yet — leaves `usesSpecs` false while there is still a claim to show. Nothing about
  characterizations is rendered without this, for the reason given above: a project that has never
  heard of the attribute must not be told about it on every page. -/
  usesChars : Bool := false
  /-- Whether the collected data carries semantic hashes, i.e. whether `collect --hashes` was given.

  Gates everything that compares one *meaning* against another across time: the staleness check on
  the reader's own verdicts, and the prose that explains it. See `meaningKeyOf` for why the textual
  fallback is not good enough to carry that particular feature — a check that reports every
  acceptance as void after a toolchain upgrade is worse than no check. -/
  usesMeanings : Bool := false
  /-- The comparison against an earlier `collect` output, when `--baseline` was given.

  Gated exactly as `usesSpecs` is, and for the same reason: a site built without a baseline must not
  acquire a Changes page, a Browse column, or a badge saying "unchanged" on every declaration. There
  is no revision to speak of, so the site says nothing about revisions. -/
  diff? : Option DiffReport := none
  /-- Declaration ↦ how it changed, empty without a baseline. -/
  changes : Std.HashMap Name DeclChange := {}
  /-- Declaration ↦ how many other declarations' *meaning* rests on it: the reverse of `dataTransDeps`,
  counted once rather than per lookup. Built only when there is a baseline, since nothing else on
  the site asks for it. -/
  dependentCounts : Std.HashMap Name Nat := {}
  /-- The provenance ledger, when `--provenance` was given.

  Gated exactly as `diff?` is: without it no page mentions when anything changed. Half of this
  feature is the ability to say "edited, but its meaning did not move", and a site that could only
  say the first half would be worse than one that says neither. -/
  provenance? : Option Provenance := none
  /-- Declaration ↦ its ledger entry, resolved once rather than per page. -/
  provEntries : Std.HashMap Name ProvenanceEntry := {}
  /-- Declaration ↦ where its source was last touched, resolved once. -/
  provEdits : Std.HashMap Name EditInfo := {}
  /-- The git ref source links should point at: the revision the ledger was last folded at, so a
  published site's links keep showing the code it was built from rather than drifting with the
  branch. `main` without a ledger, which is what the site did before there was anything better. -/
  sourceRef : String := "main"

/-- Renders one declaration card with docs, statement, links, and dependencies.

Rendered on the declaration's own page and nowhere else: module pages, the claims page and the
trust page all list declarations compactly instead. The card therefore carries no "Details" link —
it used to, and once the module pages stopped showing cards it pointed at the page it was already
on. -/
private def mkDeclBlock (decl : DeclInfo) (ctx : SiteContext) : Block Manual :=
  Id.run do
    let issueUrl := issueUrlOf ctx.repoUrl? decl.name decl.moduleName decl.source? decl.dependsOnSorry
    let sourceUrl := sourceUrlOf ctx.repoUrl? decl.source? ctx.sourceRef
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
    --
    -- `Highlight.declCode` is what keeps the whole command from including the docstring: it is part
    -- of the command, and the card has just rendered it above. The text fallback never had the
    -- problem — `displaySignature` is cleaned of docstring and attributes at collection time — which
    -- is why the duplicate showed on definitions and structures and not on theorems.
    let showsBody :=
      match decl.kind with
      | .definition | .structure | .typeclass | .inductive => true
      | _ => false
    blocks := blocks.push <|
      if showsBody then
        leanCodeBlock ((ctx.declHighlights.get? decl.name).map (Highlight.declCode decl.name))
          decl.displaySignature
      else .code decl.displaySignature
    -- The proof, then the links. Nothing about the declaration's dependencies: "Type uses" is the
    -- expanded *Its statement mentions* list further down, "Body uses" is inside *Everything it rests
    -- on*, and both are drawn in the graph as well — three renderings of one fact, the first of them
    -- in the place a reader looks for what the declaration *says*. "Used by" had no second home but
    -- answers a question this page is not for: who else depends on this is a property of the library,
    -- not of the claim.
    if let some proof := decl.proofText? then
      blocks := blocks.push <| .other (Block.details { summary := "Proof" }) #[.code proof]
    if let some block := mkLinkParagraph sourceUrl issueUrl then
      blocks := blocks.push block
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
`meaningDeps` on declaration detail pages, to match their `dataTransDeps` closure, or `(·.deps)`
(always type + body) for the full-repository graph. -/
private def mkGraphData (decls : Array DeclInfo) (declHrefs : Std.HashMap Name String)
    (depsOf : DeclInfo → Array Name) (focus? : Option Name := none)
    (projectName : String := "") : GraphData :=
  let names : Std.HashSet Name := decls.foldl (fun acc d => acc.insert d.name) {}
  let nodes := decls.map fun decl => {
    id := decl.name.toString
    label := decl.name.getString!
    -- `displayKind`, as every other node-like listing on the site uses: `kind.label` is the raw
    -- `theorem` Lean records, so a lemma's own graph node contradicted the card above it.
    kind := decl.displayKind
    status := if decl.dependsOnSorry then "sorry" else "proved"
    groupKey := decl.groupKey
    moduleName := decl.modulePath
    -- Root-relative, with no `../` prefix: Verso emits a `<base href>` on every page pointing at
    -- the site root, so every relative href on the page — including these, which reach the DOM
    -- through JSON rather than through Verso's link handling — resolves from the root already.
    href := declHrefs.getD decl.name (pathForPart decl.groupKey decl.modulePath decl.name)
    focus := focus? == some decl.name
    -- Clipped, because this rides along in every node of every graph and a handful of declarations
    -- carry very long statements. Not at 600, though: that cut 88 of `AlphaRAR`'s 2503 project nodes
    -- mid-statement, and a statement truncated before its conclusion is worse than no preview at all
    -- — it shows a theorem's hypotheses and hides what they imply. A limit has to fall somewhere, but
    -- it should fall past the point where the panel still answers the question it exists for.
    signature := clipText 2400 decl.displaySignature
    doc := clipText 1200 (decl.docText?.getD "")
    meaning := meaningKeyOf decl
  }
  let edges := decls.foldl (fun acc decl =>
    acc ++ (depsOf decl).filterMap (fun dep =>
      if names.contains dep then
        some { source := dep.toString, target := decl.name.toString }
      else
        none)) #[]
  { nodes, edges, projectName }

/-- Adds the upstream declarations that `decls` name in their statements, audited or not.

The picture is otherwise project-internal, which for an audit is the wrong boundary: a graph whose
bottom row is "external constants, not shown" hides both the thing a referee has not checked and the
thing the statement is actually about. These nodes are unclickable (this site exposes no page for
them) and carry no dependencies of their own, so `graph.js` lays them out as a wrapped band above the
dependency rows rather than as a row — see `GraphNode.upstream`.

The two kinds are drawn together but gathered by different rules, because they answer different
questions:

* **unaudited** packages, over the whole page closure. "What unaudited code does this rest on" is a
  question about the closure, and this is the trust surface — the same set the Trust page counts. On
  `AlphaRAR` it comes to at most 9 nodes on any page and 0 on most, the whole surface into
  `LeanMachineLearning` being 15 declarations.
* **audited** packages, for the focus declaration only. Here the question is not trust — the reader
  has already said they accept the package — but *what this statement is about*, which is a property
  of this statement and not of everything below it. Over the whole closure it would be several
  hundred Mathlib nodes; for one statement it is a median of 21.

Proof-only references are excluded from both by `depsOf` being `meaningDeps`. -/
private def withUpstreamNodes (data : GraphData) (decls : Array DeclInfo) (ctx : SiteContext)
    (depsOf : DeclInfo → Array Name) (focus? : Option Name := none) : GraphData :=
  let shown : Std.HashSet String := data.nodes.foldl (fun acc n => acc.insert n.id) {}
  let packageOf (dep : Name) : Option (Name × Bool) := do
    let ext ← ctx.externalDecls.get? dep
    -- The toolchain is left out of the band entirely. It is trusted unconditionally — it is the
    -- compiler and kernel that checked every other package — so it is never a trust finding, and as
    -- context it is `Nat`, `OfNat.ofNat` and `instOfNatNat`, which say nothing about what a theorem
    -- means. On `AlphaRAR` it was 7189 of 29135 band nodes, a quarter of the band spent on nothing.
    if ctx.toolchainPackages.contains ext.package then none
    else some (ext.package, ctx.trusted.contains ext.package)
  -- One entry per constant however many declarations name it, so a definition used throughout the
  -- page is one node with several edges rather than several nodes. A constant that is both named by
  -- the focus statement and reached from elsewhere in the closure appears once, since the key is the
  -- constant.
  let gather (from_ : Array DeclInfo) (keepTrusted : Bool) :=
    from_.foldl (init := ({} : Std.HashMap Name (Name × Bool))) fun acc decl =>
      (depsOf decl).foldl (init := acc) fun acc dep =>
        if ctx.declByName.contains dep then acc
        else match packageOf dep with
          | some (pkg, trusted) => if trusted == keepTrusted then acc.insert dep (pkg, trusted) else acc
          | none => acc
  -- Audited packages only on request: see `Cli.showTrustedUpstream` for why the default is off.
  let focusDecls :=
    if ctx.showTrustedUpstream then decls.filter (fun d => focus? == some d.name) else #[]
  let surface := (gather focusDecls true).fold (init := gather decls false) fun acc k v =>
    acc.insert k v
  /- Close the surface over each expanded package's own edges, so an unaudited package is drawn with
  the structure it actually has rather than as a flat row of the names this project happens to
  mention. Only packages `collect` could walk inside its budget carry edges at all
  (`CollectedData.expandedPackages`), so this terminates on the surface for everything else — Mathlib
  included, which is the point of the budget. -/
  let refs := Id.run do
    let mut acc := surface
    let mut frontier := surface.toArray.map (·.1)
    while !frontier.isEmpty do
      let mut next : Array Name := #[]
      for n in frontier do
        let some ext := ctx.externalDecls.get? n | continue
        if !ctx.expandedPackages.contains ext.package then continue
        for d in ext.deps do
          if acc.contains d || ctx.declByName.contains d then continue
          match packageOf d with
          | some (pkg, trusted) =>
            -- A closure member is drawn on the same terms as the surface it came from: an audited
            -- package expands only when it is being shown at all.
            if trusted && !ctx.showTrustedUpstream then continue
            acc := acc.insert d (pkg, trusted)
            next := next.push d
          | none => pure ()
      frontier := next
    return acc
  let nodes := refs.toArray.qsort (fun a b => Name.lt a.1 b.1)
      |>.filterMap fun (name, pkg, trusted) =>
    if shown.contains name.toString then none
    else some {
      id := name.toString
      label := name.getString!
      kind := if trusted then "Audited upstream" else "Upstream declaration"
      status := if trusted then "trusted" else "untrusted"
      -- The package, which is what the band groups and labels by, and its depth, which is what the
      -- band stacks by.
      upstream := pkg.toString
      upstreamRank := ctx.packageRanks.getD pkg 0
      -- Its own group, so the fill distinguishes it from any chapter of the project.
      groupKey := pkg.toString
      moduleName := (ctx.externalDecls.get? name).map (·.moduleName.toString) |>.getD pkg.toString
      -- No page on this site; `graph.js` renders an hrefless node unclickable.
      href := ""
      -- Deliberately left empty. The signature and docstring live in the shared upstream table
      -- (`upstreamJsFile`) and are looked up by `graph.js` at click time: one upstream constant is
      -- named by many declarations, so inlining them here would write the same Mathlib signature
      -- into hundreds of pages — the duplication that moved the CSS and JS out of the pages in the
      -- first place. On `BrownianMotion` that is ~1.6k constants against ~1.8k pages.
      signature := ""
      doc := ""
    }
  let edges := decls.foldl (init := #[]) fun acc decl =>
    acc ++ (depsOf decl).filterMap fun dep =>
      if refs.contains dep && !shown.contains dep.toString then
        some { source := dep.toString, target := decl.name.toString }
      else none
  -- Edges *within* an expanded package, which are what give its block more than one level.
  let innerEdges := refs.toArray.foldl (init := #[]) fun acc (name, _, _) =>
    match ctx.externalDecls.get? name with
    | none => acc
    | some ext => acc ++ ext.deps.filterMap fun dep =>
        if refs.contains dep then some { source := dep.toString, target := name.toString } else none
  { data with nodes := data.nodes ++ nodes, edges := data.edges ++ edges ++ innerEdges }

/-- Post-order over `adj`, i.e. each node pushed after everything reachable from it. Kosaraju's
first pass. -/
private partial def postOrder (adj : Std.HashMap String (Array String)) (n : String)
    (seen : Std.HashSet String) (out : Array String) : Std.HashSet String × Array String :=
  if seen.contains n then (seen, out)
  else
    let seen := seen.insert n
    let (seen, out) := (adj.getD n #[]).foldl (init := (seen, out)) fun (seen, out) m =>
      postOrder adj m seen out
    (seen, out.push n)

/-- Floods a component id backwards along `rev`. Kosaraju's second pass. -/
private partial def assignComponent (rev : Std.HashMap String (Array String)) (c : Nat)
    (n : String) (comp : Std.HashMap String Nat) : Std.HashMap String Nat :=
  if comp.contains n then comp
  else (rev.getD n #[]).foldl (init := comp.insert n c) fun comp m => assignComponent rev c m comp

/-- Assigns each node the id of its strongly connected component (Kosaraju): two nodes share an id
exactly when each is reachable from the other. Nodes not on any cycle get an id to themselves. -/
private def componentsOf (nodes : Array String) (adj : Std.HashMap String (Array String)) :
    Std.HashMap String Nat :=
  let rev : Std.HashMap String (Array String) :=
    adj.fold (init := {}) fun acc s ts =>
      ts.foldl (fun acc t => acc.insert t ((acc.getD t #[]).push s)) acc
  let (_, order) := nodes.foldl (init := (({} : Std.HashSet String), (#[] : Array String)))
    fun (seen, out) n => postOrder adj n seen out
  (order.reverse.foldl (init := (({} : Std.HashMap String Nat), 0)) fun (comp, c) n =>
    if comp.contains n then (comp, c) else (assignComponent rev c n comp, c + 1)).1

/-- Components reachable from `c`, memoized.

Sound to memoize, unlike the same walk over the raw node graph, because the condensation is acyclic
by construction: a cycle among components would mean their members were one component. -/
private partial def reachableComponents (cadj : Std.HashMap Nat (Array Nat))
    (cache : Std.HashMap Nat (Std.HashSet Nat)) (c : Nat) :
    Std.HashSet Nat × Std.HashMap Nat (Std.HashSet Nat) :=
  match cache.get? c with
  | some reached => (reached, cache)
  | none =>
    let (reached, cache) := (cadj.getD c #[]).foldl
      (init := (({} : Std.HashSet Nat), cache))
      (fun (reached, cache) m =>
        let (sub, cache) := reachableComponents cadj cache m
        (sub.fold (init := reached.insert m) (·.insert ·), cache))
    (reached, cache.insert c reached)

/-- Drops every edge implied by a longer path through other edges: the transitive reduction, taken
over the graph's *condensation* rather than over the graph itself.

Reducing the raw graph is only correct when it is acyclic, and these are not always acyclic —
`AEEqProcess.cast`, `instCoeFun` and `mk` in `brownian-motion` are mutually recursive. Inside a cycle
every node reaches every other, so every edge leaving it appears implied by a path around the cycle,
and the naive rule deleted *all* of them: `AEEqProcess.adapted` was left with no edge to any of its
three project dependencies, drawn as an island in its own dependency graph.

Contracting each cycle to a single node first is what makes the question well posed. Edges inside a
component are always kept — they are the cycle, and it is real — and an edge between components
survives exactly when the condensation edge does. Several parallel edges into one component all
survive, which is why `cast → adapted` and `instCoeFun → adapted` are both drawn while the
genuinely implied `AEEqProcess → adapted` is not. On an acyclic graph every component is a single
node and this is the ordinary reduction. -/
private def transitiveReduce (data : GraphData) : GraphData :=
  let adj : Std.HashMap String (Array String) :=
    data.edges.foldl (fun acc e => acc.insert e.source ((acc.getD e.source #[]).push e.target)) {}
  -- Edge endpoints as well as declared nodes: an edge to a node the graph never listed would
  -- otherwise be silently placed in whichever component the lookup default named.
  let ids := data.edges.foldl (init := data.nodes.map (·.id)) fun acc e =>
    (acc.push e.source).push e.target
  let comp := componentsOf ids adj
  let cadj : Std.HashMap Nat (Array Nat) := data.edges.foldl (init := {}) fun acc e =>
    match comp[e.source]?, comp[e.target]? with
    | some cs, some ct =>
      if cs == ct || (acc.getD cs #[]).contains ct then acc
      else acc.insert cs ((acc.getD cs #[]).push ct)
    | _, _ => acc
  let cache := cadj.fold (init := ({} : Std.HashMap Nat (Std.HashSet Nat)))
    fun cache c _ => (reachableComponents cadj cache c).2
  let edges := data.edges.filter fun e =>
    match comp[e.source]?, comp[e.target]? with
    | some cs, some ct =>
      -- Inside one component the edge is part of the cycle itself, so nothing can imply it away.
      if cs == ct then true
      else
        let siblings := (adj.getD e.source #[]).filterMap (comp[·]?)
        !siblings.any fun w => w != ct && w != cs && (cache.getD w {}).contains ct
    | _, _ => true
  { data with edges := edges }

/-! ## Audit surface and trust

The numbers and chains a reader needs in order to decide how much of a result they are being
asked to take on faith, rather than merely whether it is flagged. -/

/-- The distinct constants outside the project that a declaration's closure bottoms out in: its
imported assumptions, as opposed to the project declarations it builds on. Together with the
closure size this is the "how much must I accept to believe this" measure. -/
private def externalConstants (decl : DeclInfo) (ctx : SiteContext) : Array Name :=
  let closure := #[decl.name] ++ decl.dataTransDeps
  let externals := closure.foldl (init := ({} : Std.HashSet Name)) fun acc name =>
    match ctx.declByName.get? name with
    | none => acc
    | some d => (meaningDeps d).foldl (init := acc) fun acc dep =>
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
        -- `deps`, the raw type-and-body edges: a `sorry` reached only through a proof is still a
        -- real gap, and `dependsOnSorry` — which this chain exists to explain — is `collectAxioms`,
        -- which walks proofs. Neither `meaningDeps` nor `closureDeps` will do: both are `typeDeps`
        -- for a non-alias theorem, so the proof that reaches the `sorry` is exactly what they drop,
        -- and the chain would come back empty for the declarations that most need it.
        for dep in d.deps do
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
  (decl.dataTransDeps.filter ctx.declByName.contains).size

/-- A list of declarations rendered one per line with closure size, module, and trust status. The
workhorse index rendering: used for module contents, claims, and the trust checklist. -/
private def declIndexList (decls : Array DeclInfo) (ctx : SiteContext)
    (noteOf : DeclInfo → String := fun _ => "") : Option (Block Manual) :=
  let entries := decls.filterMap fun decl => do
    let href ← ctx.declPageHrefs.get? decl.name
    pure {
      name := decl.name.toString
      href := href
      kind := decl.displayKind
      group := declGroupOfFields decl.kind.label decl.isLemma decl.isInstanceDecl
      deps := some (closureSize decl ctx)
      note := noteOf decl
      dependsOnSorry := decl.dependsOnSorry
      : DeclIndexEntry
    }
  if entries.isEmpty then none else some (.other (Block.declIndex { entries }) #[])

/-! ## Upstream trust

Everything else on this site measures the project. This measures what the project *rests* on, which
for a Mathlib-based development is the larger half by far — and which no amount of `sorry`-checking
inside the project can speak to. See the note in `Collect.lean` for why the analysis is
package-granular and why closing over the Lake graph is sound. -/

/-- The upstream packages a declaration's *statement* reaches into, closed over the Lake dependency
graph and bounded by what was actually loaded.

"Statement" rather than "closure": see the note in `Collect.lean`. An upstream proof is rechecked by
the kernel and needs no trust; an upstream definition a statement is about does. -/
private def restsOnPackages (decl : DeclInfo) (ctx : SiteContext) : Array Name :=
  (trustClosure ctx.packages decl.upstreamPackages).toArray.filter (fun name =>
    ctx.loadedPackages.contains name &&
      !(ctx.packages.any fun pkg => pkg.name == name && (pkg.isProject || pkg.isToolchain)))
    |>.qsort Name.lt

/-- The unaudited packages whose definitions appear in a declaration's statement: what a reader is
asked to take on faith beyond the project and the toolchain. Empty when everything the statement
reaches has been vouched for. -/
private def untrustedPackagesOf (decl : DeclInfo) (ctx : SiteContext) : Array Name :=
  (restsOnPackages decl ctx).filter (!ctx.trusted.contains ·)

/-- The packages the project actually reaches, closed over the Lake graph, project excluded. -/
private def reachedPackages (decls : Array DeclInfo) (ctx : SiteContext) : Array Name :=
  let direct := decls.foldl (init := #[]) fun acc decl => acc ++ decl.upstreamPackages
  (trustClosure ctx.packages direct).toArray.filter (fun name =>
    ctx.loadedPackages.contains name &&
      !(ctx.packages.any fun pkg => pkg.name == name && pkg.isProject))
    |>.qsort Name.lt

/-- The audit-surface and trust summary shown near the top of a declaration page. -/
private def mkAuditBlocks (decl : DeclInfo) (ctx : SiteContext) : Array (Block Manual) :=
  Id.run do
  let externals := externalConstants decl ctx
  let inProject := decl.dataTransDeps.filter ctx.declByName.contains
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
    -- The caveat hangs under the checkmark and not under the warning above it. A reader who sees
    -- "⚠ Not fully proved" already discounts the line; a checkmark is the one that invites being
    -- read as a verdict, which is the reading this paragraph exists to refuse. It says what the
    -- check *is* — this tool's reading of one build's recorded axioms — because every limitation
    -- below follows from that and from nothing else.
    blocks := blocks.push <| .para #[
      .text "This is the tool's own reading of one build's recorded axioms, and it is not robust \
        against an author who wants it to pass. Checking meant to be relied on should go through ",
      .link #[.text "Comparator"] "https://github.com/leanprover/comparator",
      .text ", which replays the proof through the kernel from an export against an explicit list \
        of permitted axioms."
    ]
  if !unusual.isEmpty then
    blocks := blocks.push <| .para <|
      #[.bold #[.text "Extra axioms: "]] ++
        joinInlines (unusual.toList.map fun a => #[.code a.toString]) #[.text " · "]
  -- Upstream trust. Only reported as a gap, and phrased as one about *meaning*: the proofs upstream
  -- are kernel-checked, so what is left to take on faith is what the statement is about.
  let untrusted := untrustedPackagesOf decl ctx
  if !untrusted.isEmpty then
    blocks := blocks.push <| .para <|
      #[.bold #[.text "Statement rests on unaudited definitions from: "]] ++
        joinInlines (untrusted.toList.map fun p => #[.code p.toString]) #[.text " · "] ++
        #[.text ". See ", .link #[.text "Trust"] "trust/", .text "."]
  return blocks

/-! ## Specifications

The one thing on the site that is not derived. Everything else here — closures, `sorry` chains,
axioms — is computed from the environment and is true whether or not anyone thought about it. A
specification is a *claim*: the author saying "these properties are what this definition means".
The tool can only carry it, check that it points somewhere real, and — the part that does the
auditing work — show where it is absent.

All of it is gated on `SiteContext.usesSpecs`; see the note there. -/

/-- The theorems put forward as `decl`'s specification, with their statements. -/
private def specTheoremRows (decl : DeclInfo) (ctx : SiteContext) : Array SpecRow :=
  decl.specifiedBy.map fun link =>
    match ctx.declByName.get? link.name with
    | some thm => {
        name := link.name.toString
        href := ctx.declPageHrefs.getD link.name ""
        kind := thm.displayKind
        comment := link.comment
        -- The statement is the point: a reader judges whether these properties pin the definition
        -- down by reading them, not by counting them.
        signature := thm.displaySignature
      }
    | none => { name := link.name.toString, kind := "Theorem", comment := link.comment }

/-- The definitions `decl` is declared to specify.

No statements here, unlike the other direction. The reader is on the theorem's page and already has
its statement above; what they are missing is which definition it speaks for — and a definition's
"statement" can be a whole structure body, which would swamp the note it is meant to carry. The
target may also be outside the project (a `Mathlib` definition), in which case there is no page to
link to and the name is shown plain. -/
private def specTargetRows (decl : DeclInfo) (ctx : SiteContext) : Array SpecRow :=
  decl.specifies.map fun link =>
    let target? := ctx.declByName.get? link.name
    { name := link.name.toString
      href := ctx.declPageHrefs.getD link.name ""
      kind := (target?.map (·.displayKind)).getD "Definition"
      comment := link.comment }

/-! ### Characterizations

The stronger claim, and the only one on the site whose *shape* has been machine-checked: that the
property really is a predicate on the definition's type, that the existence theorem really states
the definition satisfies it, that the uniqueness theorem really relates two objects satisfying it.

None of which says the claim is worth anything. `IsEntropy x := (x = entropy p)` passes every one of
those checks and pins nothing down, and a characterization up to a relation coarse enough — parity,
say — is barely a characterization at all. So the rendering shows the property's body and the
relation in full, and says plainly which half is checked and which half is the reader's job. A page
that reported "characterized ✓" and left it there would be worse than one that said nothing. -/

/-- One declaration of a characterization as a row: role, name, statement, and — on a uniqueness
row — the relation it stops at. -/
private def charPartRow (ctx : SiteContext) (role : String) (name : Name)
    (comment : String := "") (relation : String := "") : CharPartRow :=
  let decl? := ctx.declByName.get? name
  { role
    name := name.toString
    href := ctx.declPageHrefs.getD name ""
    kind := (decl?.map (·.displayKind)).getD ""
    comment
    relation
    -- Empty for a part outside the project, which then renders as a bare labelled link. The
    -- property is the one part where that really hurts, and it is also the part least likely to
    -- be elsewhere: a predicate written to characterize a project's own definition lives with it.
    signature := (decl?.map (·.displaySignature)).getD "" }

/-- The definition of the relation a characterization stops at, when there is one worth showing.

Three cases, and the order matters. A relation declared by the project gets its source form and a
link to its page. One from an upstream package has no page here, so it gets the pretty-printed type
and body the graph panels use — which for a relation is the informative half: `Filter.EventuallyEq`
has type `Filter α → (α → β) → (α → β) → Prop`, every argument reading as a hypothesis and nothing
saying it means `∀ᶠ x in l, f x = g x`. One from the toolchain gets nothing: `=` and `↔` are not
what a reader is stuck on, and `{α : Sort u} → α → α → Prop` in a slot meant to explain something
would be worse than an empty slot. -/
private def charRelationRow? (ctx : SiteContext) (head : Name) : Option CharPartRow :=
  if head.isAnonymous then none
  else match ctx.declByName.get? head with
    | some d =>
      some { role := "Relation"
             name := head.toString
             href := ctx.declPageHrefs.getD head ""
             kind := d.displayKind
             signature := d.displaySignature }
    | none =>
      match ctx.externalDecls.get? head with
      | none => none
      | some ext =>
        if ctx.toolchainPackages.contains ext.package then none
        else
          some { role := "Relation"
                 name := head.toString
                 kind := ext.package.toString
                 -- The same `signature := value` shape the upstream graph panels use, so an
                 -- upstream constant reads the same wherever the site shows one.
                 signature :=
                   if ext.value.isEmpty then ext.signature
                   else s!"{ext.signature}\n  :=\n{ext.value}" }

/-- The characterizations claimed for `decl`, as rendered rows.

The author's comment rides on the property row rather than on the bundle, because that is where
they wrote it and what it is about: `"the Shannon axioms"` names the property, not the claim. -/
private def charRows (decl : DeclInfo) (ctx : SiteContext) : Array CharRow :=
  decl.characterizedBy.map fun bundle =>
    { property := bundle.property.toString
      relations := bundle.uniqueness.filterMap fun u =>
        if u.relation.isEmpty then none else some u.relation
      hasExistence := !bundle.existence.isEmpty
      hasUniqueness := !bundle.uniqueness.isEmpty
      -- Deduplicated: several uniqueness theorems normally stop at the same relation, and
      -- repeating its definition once per theorem would bury the parts it is there to explain.
      relationDefs := (bundle.uniqueness.foldl (init := (#[] : Array Name)) fun acc u =>
        if acc.contains u.relationHead then acc else acc.push u.relationHead).filterMap
          (charRelationRow? ctx)
      parts :=
        #[charPartRow ctx "Property" bundle.property (comment := bundle.comment)]
          ++ bundle.existence.map (charPartRow ctx "Existence")
          ++ bundle.uniqueness.map fun u =>
              charPartRow ctx "Uniqueness" u.name (relation := u.relation) }

/-- The claims `decl` is one of the three parts of, for its own page.

The counterpart of `specTargetRows`, and no statements here for the same reason: the reader is on
the part's page with its statement above, and what they are missing is the claim it serves. -/
private def charPartOfRows (decl : DeclInfo) (ctx : SiteContext) : Array SpecRow :=
  decl.characterizes.map fun link =>
    { name := link.target.toString
      href := ctx.declPageHrefs.getD link.target ""
      kind :=
        match link.role with
        | "property" => "Characterizing property"
        | "existence" => "Existence"
        | "uniqueness" => "Uniqueness"
        | other => other
      comment :=
        match link.role with
        | "property" => "The property claimed to determine it."
        | "existence" => s!"States that it satisfies {link.property}."
        | "uniqueness" => s!"States that {link.property} determines its subject."
        | _ => "" }

/-- The characterization section of a declaration page.

Above the specification, not below it, because it answers the same question and answers it better:
a reader who has seen that `entropy` is the unique object with a given property does not need to
weigh a list of properties it happens to satisfy. When there is no characterization the section is
simply absent — unlike a missing specification, which is reported. A definition with no
characterization is the overwhelmingly common case even in a project that uses the attribute, and a
note on every page saying so would be nagging rather than auditing. -/
private def mkCharBlocks (decl : DeclInfo) (ctx : SiteContext) : Array (Block Manual) :=
  Id.run do
  if !ctx.usesChars then
    return #[]
  if decl.characterizedBy.isEmpty then
    -- A part of someone else's claim, which its own statement does not reveal. Rendered without a
    -- section heading of its own: it is a cross-reference, not a section.
    if decl.characterizes.isEmpty then
      return #[]
    return #[
      .para #[.bold #[.text "Part of a characterization"]],
      .other (Block.specList { entries := charPartOfRows decl ctx }) #[]
    ]
  let rows := charRows decl ctx
  let complete := rows.filter fun r => r.hasExistence && r.hasUniqueness
  let mut blocks : Array (Block Manual) := #[]
  blocks := blocks.push <|
    .other (Block.sectionHeading s!"Characterization ({decl.characterizedBy.size})") #[]
  blocks := blocks.push <| .para <|
    (if complete.isEmpty then
      #[.text "A property its author put forward as characterizing ", .code decl.name.toString,
        .text ", with the claim not yet complete — each card below says which half is missing. "]
    else
      #[.text "What the author offers as pinning ", .code decl.name.toString,
        .text " down completely: a property it satisfies, and a theorem that nothing else does. "])
    ++ #[.text "This is a stronger claim than a specification, and unlike a specification its \
      shape is checked — that the property is a predicate on ", .code decl.name.toString,
      .text "'s type, that the existence theorem states this definition satisfies it, and that the \
        uniqueness theorem relates two objects that do."]
  blocks := blocks.push <| .other (Block.charList { entries := rows }) #[]
  -- The caveat is not boilerplate and is not optional. The checked half is easy to mistake for the
  -- whole thing, and a reader who does so has been misled by this page rather than by the author.
  blocks := blocks.push <| .para #[
    .bold #[.text "What this does not settle. "],
    .text "Nothing checks that the property says the right thing: a property that mentions ",
    .code decl.name.toString,
    .text " itself would satisfy every test above and pin nothing down. Nor is the relation \
      anything but reported — a definition determined only up to a coarse relation is determined \
      correspondingly less, and ",
    .code "=", .text " is the strongest case rather than the only one. Both are printed above in \
      full because reading them is the only way to tell."
  ]
  if !decl.characterizes.isEmpty then
    blocks := blocks.push <| .para #[.bold #[.text "Part of a characterization"]]
    blocks := blocks.push <| .other (Block.specList { entries := charPartOfRows decl ctx }) #[]
  return blocks

/-- The specification section of a declaration page: two directions and one absence.

The absence is the reason this is worth rendering at all. A definition with a specification gets a
list a reader can check; a definition without one gets told so, in the same place, because "nobody
has said what this means" is exactly the finding an auditor is looking for and it is invisible
otherwise. -/
private def mkSpecBlocks (decl : DeclInfo) (ctx : SiteContext) : Array (Block Manual) :=
  Id.run do
  if !ctx.usesSpecs then
    return #[]
  let mut blocks : Array (Block Manual) := #[]
  if !decl.specifiedBy.isEmpty then
    blocks := blocks.push <|
      .other (Block.sectionHeading s!"Specification ({decl.specifiedBy.size})") #[]
    blocks := blocks.push <| .para #[
      .text "What the author offers as evidence that ", .code decl.name.toString,
      .text " is the intended definition. Each of these theorems is marked ", .code "@[specifies]",
      .text " in the source, so this list is the author's claim rather than anything derived."
    ]
    blocks := blocks.push <| .other (Block.specList { entries := specTheoremRows decl ctx }) #[]
  else if decl.isDefinitionLike then
    blocks := blocks.push <| .para #[
      .bold #[.text "No specification. "],
      .text "No theorem in this project is marked as part of what ", .code decl.name.toString,
      .text " means, so nothing here settles whether it is the intended definition — that is a \
        judgement the reader has to make from the body."
    ]
  if !decl.specifies.isEmpty then
    blocks := blocks.push <| .para #[.bold #[.text "Part of a specification"]]
    blocks := blocks.push <| .other (Block.specList { entries := specTargetRows decl ctx }) #[]
  return blocks

/-! ## Revisions

Everything below is gated on `SiteContext.diff?`, i.e. on `--baseline` having been given. See
`Referee/Diff.lean` for what is compared and what the comparison costs. -/

/-- How many declarations' *meaning* rests on this one: the size of the re-reading a change to it
forces on someone who has already worked through the library.

The reverse of `dataTransDeps`, which follows `meaningDeps`, so it counts the declarations whose
statements this one is part of and not the ones whose proofs merely call it. -/
private def dependentCount (name : Name) (ctx : SiteContext) : Nat :=
  ctx.dependentCounts.getD name 0

/-- Turns one change into the row both the Changes page and the declaration banner render. -/
private def changeRowOf (change : DeclChange) (ctx : SiteContext) (since : String := "")
    : ChangeRowData :=
  let decl? := ctx.declByName.get? change.name
  let statementDiff? := do
    let old ← change.oldStatement?
    let decl ← decl?
    pure (statementDiff old decl.expandedSignature)
  {
    name := change.name.toString
    href := (ctx.declPageHrefs.get? change.name).getD ""
    module := (decl?.map (·.modulePath)).getD ""
    kind := change.kind.slug
    label := change.kind.label
    diff := statementDiff?.getD {}
    -- An addition has no baseline version to align against, so its statement is shown whole — and
    -- as the author wrote it rather than as elaborated, which for a Mathlib-heavy statement is the
    -- difference between three lines and twenty-five of instance binders. The *comparison* still
    -- runs on the elaborated type; only what is displayed here changes.
    statement := if change.kind == .added then (decl?.map (·.displaySignature)).getD "" else ""
    causes := change.causes.filterMap fun cause =>
      ctx.declPageHrefs.get? cause |>.map fun href =>
        { label := cause.toString, href? := some href }
    sinceDate := (ctx.provenance?.bind (·.dateForRef? since)).getD ""
    trustNotes := change.trustNotes
    dependents := dependentCount change.name ctx
    since := since
  }

/-- The banner at the top of a declaration page whose meaning moved since the baseline.

Nothing is rendered for a declaration that did not change, and nothing at all without a baseline: a
badge reading "unchanged" on 1400 pages is noise, and it is the changed ones a returning reader is
looking for. A proof-only change *is* shown, because it explains why the source no longer matches
the reader's notes — but it says in the same breath that no re-reading follows from it. -/
private def mkChangeBlocks (decl : DeclInfo) (ctx : SiteContext) : Array (Block Manual) :=
  match ctx.diff?, ctx.changes.get? decl.name with
  | some report, some change =>
    if change.isNoteworthy then
      #[.other (Block.changeBanner (changeRowOf change ctx (since := report.baselineLabel))) #[]]
    else #[]
  | _, _ => #[]

/-- The revision selector's payload, or nothing without a ledger. -/
private def mkRevisionPickerBlocks (decls : Array DeclInfo) (ctx : SiteContext)
    : Array (Block Manual) :=
  match ctx.provenance? with
  | none => #[]
  | some p =>
    let rows := decls.filterMap fun decl =>
      (ctx.provEntries.get? decl.name).map fun entry => {
        name := decl.name.toString
        href := (ctx.declPageHrefs.get? decl.name).getD ""
        module := decl.modulePath
        changedAt := entry.changedAt
        firstSeenAt := entry.firstSeenAt
        everChanged := entry.changeCount > 0
        kind := entry.lastKind
        dependents := dependentCount decl.name ctx
        : RevisionPickerDecl
      }
    #[.other (Block.revisionPicker { revisions := p.revisions, decls := rows }) #[]]

/-- The provenance line for one declaration, or nothing at all.

Nothing without `--provenance`, and nothing for a declaration the ledger has never seen — which is
the normal state of anything added since the last fold, and says nothing worth a line. -/
private def mkProvenanceBlocks (decl : DeclInfo) (ctx : SiteContext) : Array (Block Manual) :=
  match ctx.provenance? with
  | none => #[]
  | some p =>
    match p.rowFor decl.name ctx.provEntries ctx.provEdits with
    | none => #[]
    | some row => #[.other (Block.provenanceLine row) #[]]

/-! ## Audit state

What a *reader* has decided, as opposed to what the environment says. See `Referee/Audit.lean` for
what acceptance is taken to mean and why coverage is derived rather than recorded. -/

/-- The statement closure of a declaration, as links, in dependency order.

The order is `dataTransDeps`', which is topological — every dependency precedes what uses it — for
the same reason the extraction closure is: it is a dependency-respecting order. A reading queue wants
exactly that, so it comes for free. The *contents* are the meaning closure, not the extraction one:
a reader asked to accept this declaration is not asked to accept a lemma some proof merely called. -/
private def auditClosureLinks (decl : DeclInfo) (ctx : SiteContext) : Array LinkInfo :=
  decl.dataTransDeps.filterMap fun dep =>
    if !ctx.declByName.contains dep then none
    else some { label := dep.toString, href? := ctx.declPageHrefs.get? dep }

/-- The verdict control at the top of a declaration page. -/
private def mkAuditControlBlocks (decl : DeclInfo) (ctx : SiteContext) : Array (Block Manual) :=
  #[.other (Block.auditControl {
      name := decl.name.toString
      project := ctx.rootPrefix.toString
      closure := auditClosureLinks decl ctx
      meaning := meaningKeyOf decl
      -- Positionally parallel to `closure`, so it is filtered by the same predicate.
      closureMeanings := decl.dataTransDeps.filterMap fun dep =>
        (ctx.declByName.get? dep).map meaningKeyOf
    }) #[]]

/-- The whole library, as the audit page needs it.

Closures are emitted as indices into a shared name table. The same few hundred strings appear tens
of thousands of times across the closures of a library this size — brownian-motion has 116,519
transitive edges — and writing them out would put megabytes of duplicated text on one page. -/
private def mkAuditData (decls : Array DeclInfo) (ctx : SiteContext) : AuditData := Id.run do
  let names := decls.map (·.name)
  let index : Std.HashMap Name Nat :=
    names.zipIdx.foldl (fun acc (n, i) => acc.insert n i) {}
  let entries := decls.map fun decl => {
    kind := decl.displayKind
    group := declGroupOfFields decl.kind.label decl.isLemma decl.isInstanceDecl
    module := decl.modulePath
    href := (ctx.declPageHrefs.get? decl.name).getD ""
    claim := decl.isClaim
    sorryDep := decl.dependsOnSorry
    unspecified := decl.isDefinitionLike && decl.specifiedBy.isEmpty && ctx.usesSpecs
    change := ((ctx.changes.get? decl.name).map (·.kind.slug)).getD ""
    meaning := meaningKeyOf decl
    closure := decl.dataTransDeps.filterMap index.get?
    : AuditDecl
  }
  return {
    project := ctx.rootPrefix.toString
    dataId := dataFingerprint decls
    names := names.map (·.toString)
    decls := entries
    renamed := ((ctx.diff?.map (·.renamed)).getD #[]).map fun (a, b) => (a.toString, b.toString)
    baselineLabel := (ctx.diff?.map (·.baselineLabel)).getD ""
  }

/-- Builds the Audit page: what the reader has read, and what that does and does not cover.

The one page on this site whose content is not derived from the library. It exists because the
reading a referee does is work, and work that cannot be recorded has to be redone — and because the
number that matters is not how many declarations someone has ticked off but how many claims are
covered *including everything their statements rest on*, which no checkbox can say by itself. -/
private def mkAuditPart (decls : Array DeclInfo) (ctx : SiteContext) : Part Manual :=
  {
    title := #[.text "Audit"]
    titleString := "Audit"
    metadata := some {
      file := some "audit"
      shortTitle := some "Audit"
      tag := some (.provided "audit")
      number := false
    }
    content := #[
      .para #[
        .text "What you have read, and what follows from it. A declaration is ",
        .emph #[.text "accepted"],
        .text " when you have read it and judged that it says what its name claims — and ",
        .emph #[.text "covered"], .text " when, in addition, every declaration its statement rests \
          on is accepted too. The gap between those two is the point of this page: accepting a \
          theorem whose definitions you have not read accepts a sentence, not a theorem."
      ],
      .para #[
        .text "Whether something is ", .emph #[.text "proved"], .text " is a separate question and \
          is not tracked here. A ", .code "sorry", .text " never blocks acceptance, because \
          accepting is a judgement about what a statement means; ",
        .link #[.text "Trust"] "trust/", .text " reports the rest."
      ],
      .other (Block.auditData (mkAuditData decls ctx)) #[],
    ] ++ (if !ctx.usesMeanings then #[] else #[
      .para #[
        .bold #[.text "Verdicts remember what they were about. "],
        .text "Each verdict is recorded against the declaration's meaning at the moment you set \
          it — a structural hash of the elaborated term, not of how it prints. So a later build of \
          a revised library can tell you which of your acceptances are of something that has since \
          changed, and it needs neither the old build nor a ",
        .code "--baseline", .text " to do it: the exported file carries its own reference points. \
          Those acceptances are listed above, and they are excluded from every count on this page \
          rather than quietly inflating it."
      ]
    ]) ++ #[
      .para #[
        .bold #[.text "What this is not. "],
        .text "Nothing here is checked or authenticated. The exported file is plain JSON that \
          anyone can edit, and an accepted declaration is one that a human said says what its name \
          claims — no more. It is a work aid for the reader who made it, and it should never be \
          offered to anyone else as evidence that a library was audited."
      ],
      .para #[
        .bold #[.text "Where it is kept. "],
        .text "In this browser, under this project's name. Clearing your browser data deletes it, \
          and a second reader on another machine shares none of it — so export the file, which is \
          the artifact that actually travels."
      ]
    ]
    subParts := #[]
  }

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
        tag := some (.provided (minimalFileTagOf decl.name))
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

/-- The declaration-page pointers to its minimal file: the on-site page, the raw download, and the
web editor.

The on-site page is a subpage rather than inline content. That is a concession to size, not a
change of intent: highlighting carries a pretty-printed type for every token, which measured **46×**
the size of the Lean source it describes (10 MB of extracted files became 478 MB of highlighting).
Inlining that on every declaration page would have undone the page-size work entirely. One click,
on-site, fully interactive is the affordable version of "the minimal file is the point".

Three offers, each with its own condition, because they are three different artifacts:

* the **on-site page** needs `highlight-extracted`, which is what renders it;
* the **raw download** needs only `extract`, which wrote the file;
* the **web editor** needs `--site-url`, since `live.lean-lang.org` fetches the file over the
  network and so has to be told where the site is actually published.

They used to be one paragraph gated on the first condition alone, with the download and the editor
sharing a slot as either/or. Both halves of that were wrong. A run without highlighting published
every extracted file and linked none of them, and a run *with* `--site-url` silently dropped the
download — the editor is not a substitute for it, being a round trip through a third-party site
that cannot open a file the reader has no URL for. -/
private def mkMinimalFileLink (decl : DeclInfo) (ctx : SiteContext) : Array (Block Manual) :=
  Id.run do
  let stem := anchorIdOf decl.name
  let mut offers : Array (Array (Inline Manual)) := #[]
  if let some file := ctx.minimalFiles.get? stem then
    -- Root-relative, because Verso puts a `<base href>` on every page pointing at the site root. A
    -- bare `minimal/` therefore resolved to `<root>/minimal/` — which is why this link led nowhere
    -- — rather than to the subpage of the declaration it is written on.
    let pageUrl := (ctx.declPageHrefs.getD decl.name "") ++ "minimal/"
    let note :=
      if file.errors.isEmpty then
        #[.text " (types on hover; verified to compile)"]
      else
        #[.text " (types on hover; ", .bold #[.text "⚠ does not currently compile"], .text ")"]
    offers := offers.push <|
      #[.link #[.bold #[.text "Read the minimal Lean file"]] pageUrl] ++ note
  if ctx.extractedStems.contains stem then
    offers := offers.push #[.link #[.text "download the raw file"] s!"extracted/{stem}.lean"]
    if let some base := ctx.siteUrl? then
      offers := offers.push
        #[.link #[.text "open it in the Lean web editor"] (leanEditorUrl base decl.name)]
  if offers.isEmpty then
    return #[]
  return #[.para <| #[.text "Self-contained, with its dependencies inlined and proofs replaced by ",
    .code "sorry", .text ": "] ++ joinInlines offers.toList #[.text " · "] ++ #[.text "."]]

/-- Builds a dedicated detail page for one declaration: its own card, its audit surface and trust
summary, its local dependency graph, and compact listings of what it rests on.

Deliberately *not* a card per transitive dependency, which is what the previous version rendered:
see `compactDepList`. -/
private def mkDeclPart (decl : DeclInfo) (ctx : SiteContext) : Part Manual :=
  Id.run do
  -- The graph's node set follows `meaningDeps` (via `dataTransDeps`), as everything the reader is
  -- shown does: a declaration reachable only through a proof embedded in some definition's value is
  -- not part of what this declaration means. The wider `transDeps` is the extraction closure and
  -- appears nowhere on the page.
  let graphDecls := #[decl] ++ (decl.dataTransDeps.filterMap ctx.declByName.get?)
  -- The minimal file is linked once, from `mkMinimalFileLink` below. There used to be a second
  -- link here whose relative path resolved *underneath* the declaration page and 404'd, and the
  -- page ended up advertising the same artifact three times.
  let mut blocks : Array (Block Manual) := #[]
  -- Above the card, not below it: a reader who accepted this declaration in the baseline has to
  -- learn that their reading is void *before* re-reading it, not after.
  blocks := blocks ++ mkChangeBlocks decl ctx
  blocks := blocks.push (mkDeclBlock decl ctx)
  -- Immediately under the card and before the verdict control: "has this changed since I read it"
  -- is the question a returning reader asks before deciding whether to read it again, so it comes
  -- before the control that records the answer.
  blocks := blocks ++ mkProvenanceBlocks decl ctx
  -- Directly under the card: this is the action the page exists to enable, and burying it below
  -- the closure listings would put it past the fold on every page that has one.
  blocks := blocks ++ mkAuditControlBlocks decl ctx
  blocks := blocks ++ mkAuditBlocks decl ctx
  -- Before the dependency machinery, because it answers a different and prior question. The
  -- closures below say what a declaration costs to accept; the specification says what it means.
  -- The characterization comes first of the two: it answers the same question and settles it,
  -- where a specification only narrows it, so a reader who has one has less use for the other.
  blocks := blocks ++ mkCharBlocks decl ctx
  blocks := blocks ++ mkSpecBlocks decl ctx
  blocks := blocks ++ mkMinimalFileLink decl ctx
  -- Transitively reduced: 23 declarations here carry 68 direct edges, most of them implied by a
  -- longer path, and drawing all of them buries the structure in crossings and forces the layout
  -- so wide that it no longer fits the viewport. What survives is the *essential* dependency
  -- structure — every removed edge is still a real dependency, reachable along the path that
  -- remains. That invariant is why the reduction has to go through the condensation: on a graph
  -- with a cycle the naive rule breaks it outright, disconnecting the focus declaration from
  -- everything it rests on.
  let graphData := transitiveReduce
    (withUpstreamNodes
      (mkGraphData graphDecls ctx.declPageHrefs meaningDeps (focus? := decl.name)
        (projectName := ctx.rootPrefix.toString))
      graphDecls ctx meaningDeps (focus? := decl.name))
  blocks := blocks.push (.para #[.bold #[.text "Dependency graph"]])
  -- Drawn even when there is nothing to draw. Gating it on having dependencies made the shape of a
  -- declaration page vary with its content, so a reader could not tell "this rests on nothing" from
  -- "the graph is somewhere further down"; a lone node answers the question at a glance, and the
  -- answer is worth having. It also used to hide a graph that did have something to show: a
  -- declaration with no *project* dependencies can still name constants from an unaudited upstream
  -- package, and `withUpstreamNodes` draws those.
  if graphData.nodes.size <= 1 then
    blocks := blocks.push (.para #[
      .emph #[.text "Nothing to draw. "],
      .text "Its statement rests on no other declaration in this project, and names nothing from a \
        package left unaudited — so the graph is this declaration alone. That is the answer, not a \
        missing picture."
    ])
  blocks := blocks.push (.other (Block.graph graphData) #[])
  -- Layer 2 of the audit: what the *statement* mentions. This is where "does this say what I
  -- think it says" is decided, so it is shown expanded and before the rest of the closure.
  let directTypeDeps := decl.typeDeps.filter ctx.declByName.contains
  if let some block := compactDepList directTypeDeps ctx then
    blocks := blocks.push
      (.para #[.bold #[.text s!"Its statement mentions ({directTypeDeps.size})"]])
    blocks := blocks.push block
  -- Layer 3: everything else it rests on. Affects trust rather than meaning, so it is folded.
  let rest := decl.dataTransDeps.filter fun n =>
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
      tag := some (.provided (declTagOf decl.name))
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
      tag := some (.provided (moduleTagOf moduleInfo.name))
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
    -- `closureDeps`: the module graph is about what a module needs in order to build, which a proof
    -- reference establishes just as much as a statement reference does.
    let sources := modInfo.decls.foldl (init := ({} : Std.HashSet String)) fun acc decl =>
      (closureDeps decl).foldl (init := acc) fun acc dep =>
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
      tag := some (.provided (chapterTagOf group.key))
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
worth stating for its own sake — from `lemma`, which marks a step towards one; `Referee`
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
  decls.filter (·.isClaim)

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

/-- What to call the baseline in prose, with the date the provenance ledger records for it.

Every page that names the baseline goes through this, so the site cannot end up dating the same
revision in one place and leaving a bare sha in another. `CollectedData` carries no timestamp of
its own — two builds of identical source must produce identical data — so the date comes from the
ledger or not at all. -/
private def baselineName (report : DiffReport) (ctx : SiteContext) : String :=
  let label := if report.baselineLabel.isEmpty then "the baseline" else report.baselineLabel
  match ctx.provenance?.bind (·.dateForRef? report.baselineLabel) with
  | some date => s!"{label} ({date})"
  | none => label

/-- Builds the baseline half of the Changes page: what a reader who worked through the baseline has
to read again.

Ordered by what it costs that reader, never alphabetically and never by module. The sections are,
in order: statements that changed, results invalidated indirectly, definitions whose bodies moved,
what was removed, what is new, where the trust surface shifted, and — collapsed, with the reason
given — the proof-only changes that need no re-reading at all.

That last section is half the value of the page. The bulk of any real revision lands in it, and
telling a referee what they may skip is as useful as telling them what they may not. -/
private def mkBaselineBlocks (report : DiffReport) (ctx : SiteContext)
    : Array (Block Manual) := Id.run do
  let rowsOf (changes : Array DeclChange) : Array ChangeRowData :=
    -- Largest blast radius first: a changed statement forty results rest on is a different size of
    -- problem from one nothing uses, and the ordering is the only thing that says so.
    let sorted := changes.qsort fun a b => dependentCount a.name ctx > dependentCount b.name ctx
    sorted.map (changeRowOf · ctx)
  let listOf (changes : Array DeclChange) : Option (Block Manual) :=
    if changes.isEmpty then none
    else some (.other (Block.changeList { entries := rowsOf changes }) #[])
  let statements := report.ofKind .statementChanged
  let bodies := report.ofKind .bodyChanged
  let indirect := report.ofKind .indirect
  let upstream := report.ofKind .upstream
  let added := report.ofKind .added
  let proofs := report.ofKind .proofOnly
  -- Only the declarations no earlier section lists. Every row already carries its own trust notes,
  -- so a theorem whose statement changed *and* which gained a `sorry` says both things where it is
  -- first listed; repeating it here would duplicate the bulkiest rows on the page.
  let trustMoved := report.changes.filter fun c =>
    c.trustMoved && (c.kind == .unchanged || c.kind == .proofOnly)
  let newClaims := added.filter fun c =>
    (ctx.declByName.get? c.name).map (·.isClaim) |>.getD false
  let mut blocks : Array (Block Manual) := #[]
  let against := baselineName report ctx
  blocks := blocks.push <| .para #[
    .text s!"Compared against {against}: {report.oldCount} declarations then, {report.newCount} \
      now. This page is for a reader who has already worked through that revision and needs to know \
      what their reading no longer covers."
  ]
  if report.isEmpty then
    blocks := blocks.push <| .para #[
      .bold #[.text "Nothing changed. "],
      .text "Every declaration in the baseline is still here, with the same statement, the same \
        definitions underneath it, and the same trust surface."
    ]
  -- Stated before anything else on the page, because if it is true then nothing else on the page
  -- means what it appears to mean.
  if report.looksLikeToolchainChurn then
    blocks := blocks.push <| .para #[
      .bold #[.text "This diff looks like a toolchain change, not an edit. "],
      .text s!"{statements.size} of the {(report.changes.filter (·.kind != .added)).size} \
        declarations that survive from the baseline are reported as changed, which no ordinary \
        revision does. Statements are compared as pretty-printed elaborated types, so a \
        Lean or Mathlib upgrade between the two collections can change every one of them at once \
        without any of them meaning anything different. Treat the counts below as unreliable until \
        both sides have been collected on the same toolchain."
    ]
  if let some list := listOf statements then
    blocks := blocks.push <| .other (Block.sectionHeading
      s!"Statements changed ({statements.size})") #[]
    blocks := blocks.push <| .para #[
      .text "These say something different from what they said. Any reading of them is void, \
        including the proofs elsewhere in the library that rest on them. Read in full."
    ]
    blocks := blocks.push list
  if let some list := listOf indirect then
    blocks := blocks.push <| .other (Block.sectionHeading
      s!"Invalidated indirectly ({indirect.size})") #[]
    blocks := blocks.push <| .para #[
      .text "Not one character of these changed. What changed is a definition their statements are \
        about, so they now mean something different while reading identically — the one class of \
        change a textual diff of the repository cannot show. Each row names what moved underneath \
        it."
    ]
    blocks := blocks.push list
  if let some list := listOf upstream then
    blocks := blocks.push <| .other (Block.sectionHeading
      s!"Meaning changed underneath ({upstream.size})") #[]
    blocks := blocks.push <| .para #[
      .text "Also unchanged as text, and also meaning something different — but nothing this site \
        shows accounts for it. What moved is outside the exposed declarations: an upstream package \
        this project was rebuilt against, or project code that is not exposed here. Reading these \
        again means reading them against the new version of whatever they are about, which is what \
        the ", .link #[.text "Trust"] "trust/", .text " page is for."
    ]
    blocks := blocks.push list
  if let some list := listOf bodies then
    blocks := blocks.push <| .other (Block.sectionHeading
      s!"Definitions changed ({bodies.size})") #[]
    blocks := blocks.push <| .para #[
      .text "Their types are unchanged but their bodies are not, and a definition's body is what it \
        means. Everything stated about them is in the section above."
    ]
    blocks := blocks.push list
  if !report.removed.isEmpty then
    let withdrawn := report.removed.filter (·.wasClaim)
    let entries := report.removed.map fun rem =>
      let renamedTo := report.renamed.filterMap fun (from_, to) =>
        if from_ == rem.name then some to else none
      {
        name := rem.name.toString
        module := rem.modulePath
        kind := "removed"
        label := if rem.wasClaim then "claim withdrawn" else "removed"
        statement := rem.statement
        -- Offered as evidence, not as a conclusion: two declarations sharing a meaning is a
        -- fact, and whether it is a rename is the reader's call. What the evidence *is* depends
        -- on the measure — a matching semantic hash also matches through renamed dependencies,
        -- which two identical pretty-printings do not — so the note says which one it saw.
        trustNotes := renamedTo.map fun to =>
          if report.usedHashes then
            s!"a new declaration, {to}, has the same semantic hash"
          else
            s!"a new declaration, {to}, has an identical statement"
        : ChangeRowData
      }
    blocks := blocks.push <| .other (Block.sectionHeading
      s!"Removed ({report.removed.size})") #[]
    blocks := blocks.push <| .para <|
      if withdrawn.isEmpty then
        #[.text "Gone from the library. Nothing in it can rest on these any more, so what needs \
          checking is whether something the reader was relying on has quietly gone away."]
      else
        #[.text "Gone from the library, ",
          .bold #[.text (if withdrawn.size == 1 then "including one stated with the "
            else s!"including {withdrawn.size} stated with the ")],
          .code "theorem", .bold #[.text " keyword"],
          .text ". A withdrawn claim is the removal worth reading first."]
    blocks := blocks.push <| .other (Block.changeList { entries }) #[]
  if let some list := listOf added then
    blocks := blocks.push <| .other (Block.sectionHeading s!"New ({added.size})") #[]
    blocks := blocks.push <| .para <|
      #[.text "Not in the baseline, so not covered by any earlier reading"] ++
        (if newClaims.isEmpty then #[.text "."]
         else if newClaims.size == 1 then
           #[.text ". One of them is stated as a ", .code "theorem",
             .text ": a new claim, not new machinery."]
         else
           #[.text s!". {newClaims.size} of them are stated as ", .code "theorem",
             .text "s: new claims, not new machinery."])
    blocks := blocks.push list
  if let some list := listOf trustMoved then
    blocks := blocks.push <| .other (Block.sectionHeading
      s!"Trust surface moved ({trustMoved.size})") #[]
    blocks := blocks.push <| .para #[
      .text "A ", .code "sorry", .text ", an axiom, or a specification appeared or disappeared \
        beneath these while nothing about the declarations themselves moved — the gap is in \
        something they rest on, so not a character of them had to change for it to open. Where a \
        statement changed as well, that is noted on its row in the sections above rather than \
        repeated here."
    ]
    blocks := blocks.push list
  if let some list := listOf proofs then
    blocks := blocks.push <| .other (Block.sectionHeading
      s!"Proof-only changes ({proofs.size})") #[]
    blocks := blocks.push <| .para #[
      .bold #[.text "No re-reading follows from these. "],
      .text "Their statements are identical and the kernel has rechecked the new proofs. A proof \
        cannot change what a theorem says, so a reader who accepted these in the baseline still \
        accepts them — the same argument the ", .link #[.text "Trust"] "trust/",
      .text " page makes about upstream proofs, applied across revisions instead of across the \
        dependency graph."
    ]
    blocks := blocks.push <| .other (Block.details
      { summary := if proofs.size == 1 then "Show the one proof-only change"
          else s!"Show the {proofs.size} proof-only changes" }) #[list]
  -- Which measure produced the page, said on the page. "Unchanged" is a much stronger claim when
  -- it means *the same term* than when it means *printed the same way*, and a reader deciding how
  -- far to trust the counts above is entitled to know which one they are reading.
  blocks := blocks.push <| .para <|
    if report.fullyHashed then
      #[.bold #[.text "What this comparison can and cannot see. "],
        .text "Declarations are compared by ", .bold #[.text "semantic hash"],
        .text " — a structural hash of the elaborated term, taken from ", .code "semantic_hash",
        .text ". Nothing about how a statement prints reaches it, so reformatting, renamed bound \
          variables and a Lean upgrade all count as no change at all, while an edited ",
        .code "variable", .text " line counts as one. The hash is also computed through \
          dependencies, which is how the two sections above can report a declaration whose own \
          text is untouched: what a hash cannot say is ",
        .emph #[.text "where"], .text " the change was, so the source text is still what \
          separates a statement that moved from one that merely rests on something that did. \
          Two different meanings can in principle collide on a 64-bit hash and be reported as \
          unchanged; for a library this size that is on the order of one chance in a trillion, \
          and it is the only direction in which this page under-reports. Whether an extracted \
          file still compiles is not compared at all, since that lives in the build output rather \
          than in the collected data."]
    else
      #[.bold #[.text "What this comparison can and cannot see. "],
        .text "Statements are compared as elaborated types, so reformatting and renamed bound \
          variables do not count as changes and an edited ", .code "variable", .text " line does. \
          Bodies have no elaborated form here and are compared as source text, which over-reports: \
          reindenting a definition is covered, but renaming a variable inside one, or adding a \
          comment to it, counts as a change to it — and to everything stated about it. That is \
          the deliberate direction — the cost is a page of extra reading rather than a missed \
          invalidation. Collecting both revisions with ",
        .code "--hashes", .text " replaces both comparisons with a structural hash of the \
          elaborated term, which removes that over-reporting and makes a toolchain upgrade a \
          non-event. Whether an extracted file still compiles is not compared at all, since that \
          lives in the build output rather than in the collected data."]
  return blocks

/-- Builds the Changes page.

Exists when there is a baseline, a provenance ledger, or both, because the two answer the same
question from opposite ends. A baseline compares this build against one file chosen when the site
was built and can show the statements side by side; the ledger lets the *reader* choose which
revision they last worked through, over the whole recorded history, and can only say that the
meaning moved.

Neither subsumes the other, so where both exist both are shown, and the selector goes first:
choosing the revision you actually read beats being handed the one whoever built the site picked. -/
private def mkChangesPart (report? : Option DiffReport) (decls : Array DeclInfo)
    (ctx : SiteContext) : Part Manual :=
  let pickerBlocks :=
    if ctx.provenance?.isNone then #[]
    else
      #[.other (Block.sectionHeading "Since a revision you choose") #[],
        .para #[
          .text "Every revision this project has recorded provenance for. Pick the one you last \
            worked through and the queue below is what has appeared since, plus what no longer \
            means what it meant then, heaviest first."
        ]] ++ mkRevisionPickerBlocks decls ctx
  let baselineBlocks := match report? with
    | none => #[]
    | some report =>
      -- Headed only when the selector is above it. Alone on the page it needs no heading, and
      -- adding one would put a section title above what is simply the page.
      let heading :=
        if ctx.provenance?.isNone then #[]
        else
          #[.other (Block.sectionHeading s!"Since {baselineName report ctx}, in detail") #[]]
      heading ++ mkBaselineBlocks report ctx
  {
    title := #[.text "Changes"]
    titleString := "Changes"
    metadata := some {
      file := some "changes"
      shortTitle := some "Changes"
      tag := some (.provided "changes")
      number := false
    }
    content := pickerBlocks ++ baselineBlocks
    subParts := #[]
  }

/-- Builds the Specifications page: which definitions their author said something about, and —
the half that does the auditing work — which they did not.

The counterpart to the Trust page. Trust answers "is this proved"; this answers "is this the right
thing to have proved", to the extent anyone has committed to an answer. Both are lists of gaps, and
both are only useful because the gap is visible without reading the source.

Rendered only for a project that uses `@[specifies]`, see `SiteContext.usesSpecs`. For any other
project the entire page would be one list containing every definition it owns, marked as a gap:
true, and worthless. -/
private def mkSpecificationsPart (decls : Array DeclInfo) (ctx : SiteContext) : Part Manual :=
  Id.run do
  let definitions := decls.filter (·.isDefinitionLike)
  let specified := definitions.filter (!·.specifiedBy.isEmpty)
  let unspecified := definitions.filter (·.specifiedBy.isEmpty)
  let annotations := decls.foldl (fun n decl => n + decl.specifies.size) 0
  let annotated := (decls.filter (!·.specifies.isEmpty)).size
  let properties (n : Nat) : String := if n == 1 then "1 property" else s!"{n} properties"
  let mut blocks : Array (Block Manual) := #[
    .para #[
      .text "The kernel checks proofs, not definitions. Whether a definition says what its name \
        suggests is settled by a handful of theorems about it, and which theorems those are is \
        something only its author can say. This page collects what they said — every theorem \
        marked ", .code "@[specifies]", .text " — and where they said nothing."
    ],
    .para #[
      .bold #[.text s!"{specified.size} of {definitions.size} definitions "],
      .text s!"carry a specification, from {annotations} \
        {if annotations == 1 then "annotation" else "annotations"} on {annotated} \
        {if annotated == 1 then "theorem" else "theorems"}. ",
      .text "Theorems, axioms and instances are not counted: a theorem's meaning is its statement, \
        an axiom is itself an assumption and belongs on ", .link #[.text "Trust"] "trust/",
      .text ", and instances are plumbing."
    ]
  ]
  -- Ranked by how much of the library rests on them, rather than alphabetically: an unspecified
  -- definition that forty other declarations use is a different size of gap from one used once,
  -- and the ordering is the only thing on the page that says so.
  let ranked := unspecified.qsort fun a b => a.usedBy.size > b.usedBy.size
  if let some list := declIndexList ranked ctx (noteOf := fun d => s!"used by {d.usedBy.size}") then
    blocks := blocks.push <| .other (Block.sectionHeading
      s!"Without a specification ({unspecified.size})") #[]
    blocks := blocks.push <| .para #[
      .text "Nothing in the project states what these mean, so a reader has only the name and the \
        body to go on. Ordered by how many declarations use them directly — the ones near the top \
        are the ones the rest of the library rests on."
    ]
    blocks := blocks.push list
  if let some list := declIndexList (specified.qsort fun a b => a.name.lt b.name) ctx
      (noteOf := fun d => properties d.specifiedBy.size) then
    blocks := blocks.push <| .other (Block.sectionHeading
      s!"With a specification ({specified.size})") #[]
    blocks := blocks.push <| .para #[
      .text "Each definition's own page lists the properties, with their statements."
    ]
    blocks := blocks.push list
  blocks := blocks.push <| .para #[
    .bold #[.text "What this page does not tell you. "],
    .text "That a definition has a specification does not mean the specification is ", .emph #[.text "enough"],
    .text ". Nothing checks that the listed properties determine the definition uniquely, or that \
      they are the properties that matter — only that the author put them forward and that they \
      are about the definition they name. Judging whether they pin it down is the reading the page \
      is meant to make possible, not one it can do for you."
  ]
  return {
    title := #[.text "Specifications"]
    titleString := "Specifications"
    metadata := some {
      file := some "specifications"
      shortTitle := some "Specifications"
      tag := some (.provided "specifications")
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
      -- Left `none` for anything a specification cannot be about, so the table can offer "has no
      -- specification" as a filter without sweeping in every theorem in the library.
      specs := if decl.isDefinitionLike then some decl.specifiedBy.size else none
      -- `none` throughout when no baseline was given, which is what makes the column disappear.
      change := if ctx.diff?.isNone then none
        else some ((ctx.changes.get? decl.name).map (·.kind.slug) |>.getD "unchanged")
      meaning := meaningKeyOf decl
      changedRef := (ctx.provenance?.bind fun p =>
        (p.rowFor decl.name ctx.provEntries ctx.provEdits).map (·.changedRef))
      changedDate := (ctx.provenance?.bind fun p =>
        (p.rowFor decl.name ctx.provEntries ctx.provEdits).map (·.changedDate)).getD ""
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
        and filter by kind, chapter, trust, \
        {if ctx.usesSpecs then "specification, " else ""}\
        {if ctx.diff?.isSome then "revision status, " else ""}or name."],
      .para #[
        .text "“Deps” counts the project declarations in a declaration's closure and “External” \
          the distinct constants outside the project it bottoms out in — together, how much a \
          reader must accept in order to believe it. Sorting by them ascending finds the results \
          that are cheapest to audit."
      ]
    ] ++ (if !ctx.usesSpecs then #[] else #[
      .para #[
        .text "“Spec” counts the theorems the author marked as part of a definition's \
          specification. Sorting it ascending, or filtering to “no specification”, lists the \
          definitions nothing in the project says the meaning of; ",
        .link #[.text "Specifications"] "specifications/", .text " does the same with more context."
      ]
    ]) ++ (if ctx.diff?.isNone then #[] else #[
      .para #[
        .text "“Changed” is relative to the baseline this site was built against. Filtering it to \
          “needs re-reading” gives the queue for a reader returning to a revised library, across \
          the whole project rather than one module at a time; ",
        .link #[.text "Changes"] "changes/",
        .text " groups the same declarations by what happened to them, largest consequence first."
      ]
    ]) ++ #[
      .other (Block.browseTable { rows, project := ctx.rootPrefix.toString }) #[]
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

/-- The package dependency graph: one node per package the project reaches, an edge from a
dependency to the package that requires it, and `status` carrying the trust verdict.

Reuses the declaration graph's renderer, so the layering that puts "depends on nothing" at the top
does the right thing here too: the toolchain sits at the top and the project at the bottom, which is
the order a reader builds trust in. Nodes are not links — a package has no page on this site — so
`href` is left empty and `graph.js` renders them unclickable. -/
private def mkPackageGraphData (decls : Array DeclInfo) (ctx : SiteContext) : GraphData :=
  let reached := reachedPackages decls ctx
  let projectNames := ctx.packages.filterMap fun pkg =>
    if pkg.isProject then some pkg.name else none
  let shown := projectNames ++ reached
  let byName : Std.HashMap Name PackageInfo :=
    ctx.packages.foldl (fun acc pkg => acc.insert pkg.name pkg) {}
  let restingCount (name : Name) : Nat :=
    (decls.filter fun decl => (restsOnPackages decl ctx).contains name).size
  let nodes : Array GraphNode := shown.map fun name =>
    let pkg? := byName.get? name
    let isProject := pkg?.any (·.isProject)
    let isToolchain := pkg?.any (·.isToolchain)
    let trusted := ctx.trusted.contains name
    let summary :=
      if isProject then "This project. Everything else on this site is about its contents."
      else if isToolchain then "The Lean toolchain: the compiler and kernel that checked \
        everything else. Trusted by construction."
      else if trusted then s!"Trusted. {restingCount name} project declarations rest on it."
      else s!"Not audited. {restingCount name} project declarations rest on it."
    { id := name.toString
      label := name.toString
      kind := if isProject then "Project" else if isToolchain then "Toolchain" else "Package"
      -- `untrusted` is what `graph.js` styles as the warning case here, in place of the `sorry`
      -- flag it uses on declaration graphs.
      status := if isProject then "project" else if trusted then "trusted" else "untrusted"
      groupKey := if trusted || isProject then "trusted" else "untrusted"
      moduleName := ""
      href := ""
      doc := summary }
  let shownSet : Std.HashSet Name := shown.foldl (·.insert ·) {}
  let edges := shown.foldl (init := #[]) fun acc name =>
    match byName.get? name with
    | none => acc
    | some pkg => acc ++ pkg.deps.filterMap fun dep =>
        if shownSet.contains dep then
          some { source := dep.toString, target := name.toString }
        else none
  { nodes, edges, unit := "package" }

/-- The upstream-trust section of the trust page: the package graph, the verdict, and what to do
about it.

Written to be honest about the default. With no `--trust`, every upstream package is unaudited and
the section says so rather than showing a reassuring green graph; that is the accurate reading of a
site whose author has not said what they vouch for. -/
private def mkUpstreamTrustBlocks (decls : Array DeclInfo) (ctx : SiteContext) :
    Array (Block Manual) :=
  Id.run do
  let reached := reachedPackages decls ctx
  let upstream := reached.filter fun name =>
    !(ctx.packages.any fun pkg => pkg.name == name && pkg.isToolchain)
  if upstream.isEmpty then
    return #[]
  let untrusted := upstream.filter (!ctx.trusted.contains ·)
  let trustedUpstream := upstream.filter (ctx.trusted.contains ·)
  let mut blocks : Array (Block Manual) := #[
    .other (Block.sectionHeading "What it rests on") #[],
    .para #[
      .text "Nothing above this point leaves the project, and most of what lies beyond it needs no \
        trust: upstream ", .emph #[.text "proofs"],
      .text " were rechecked by the kernel, and anything left unproved in one arrives here as a ",
      .code "sorry", .text " or an extra axiom — both already counted above, upstream included."
    ],
    .para #[
      .text "What does not come for free is an upstream ", .emph #[.text "definition"],
      .text " that a statement is about. A theorem mentioning a definition from another package \
        means what it means only if that definition is the intended one, and no proof settles \
        that — it is the gap the ",
      .link #[.text "Specifications"] "specifications/",
      .text " page records, one package up. So what follows counts statements, not proofs."
    ],
    .para #[
      .text "The graph is the dependency order: the toolchain at the top, this project at the \
        bottom, an edge from each package to the one that requires it."
    ]
  ]
  let verdict : Array (Inline Manual) :=
    if untrusted.isEmpty then
      #[.bold #[.text "All "], .text s!"{upstream.size} upstream packages are marked trusted."]
    else if trustedUpstream.isEmpty then
      #[.bold #[.text s!"None of the {upstream.size} upstream packages are marked trusted."],
        .text " The site was built without ", .code "--trust", .text ", so every upstream package \
          below counts as unaudited. That is the honest default rather than a finding: pass ",
        .code "--trust PKG", .text " for each package you have audited, and it will vouch for what \
          that package rests on too."]
    else
      #[.bold #[.text s!"{trustedUpstream.size} of {upstream.size} upstream packages are trusted."],
        .text " The rest are unaudited, and every declaration whose statement reaches into one says \
          so on its own page."]
  blocks := blocks.push (.para verdict)
  blocks := blocks.push (.other (Block.graph (mkPackageGraphData decls ctx)) #[])
  if !untrusted.isEmpty then
    let rows := untrusted.map fun name =>
      let resting := (decls.filter fun decl => (restsOnPackages decl ctx).contains name).size
      Verso.Doc.ListItem.mk #[.para #[
        .code name.toString,
        .text s!" — {resting} of {decls.size} declarations have its definitions in their statements"
      ]]
    blocks := blocks.push <| .para #[.bold #[.text "Unaudited upstream packages"]]
    blocks := blocks.push (.ul rows)
  return blocks

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
  blocks := blocks ++ mkUpstreamTrustBlocks decls ctx
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

/-- The landing summary: the question the whole site exists to answer, then the numbers that answer
it, then what every page carries.

Replaces a declaration-count dashboard. A reader arriving cold cannot act on "1677 declarations,
12 chapters"; they can act on "here is what it claims, here is how much of it is proved, here is
what you would additionally have to accept".

The middle paragraph is one sentence built from four counts, and each clause is dropped when it has
nothing to say — a project with no `sorry`, no upstream dependency or no `@[specifies]` annotation
should read as a shorter sentence rather than a padded one. -/
private def mkLandingBlocks (rootPrefix : Name) (decls : Array DeclInfo) (ctx : SiteContext) :
    Array (Block Manual) :=
  Id.run do
  let claims := claimsOf decls
  let sorried := decls.filter (·.dependsOnSorry)
  let topClaims := (claims.qsort fun a b => closureSize a ctx > closureSize b ctx).take 10
  let mut blocks : Array (Block Manual) := #[]
  blocks := blocks.push <| .para #[
    .bold #[.text "What would it take to believe this library?"]
  ]
  -- Sentence one: what it claims and how much of it is proved.
  let proved : Array (Inline Manual) :=
    if sorried.isEmpty then
      #[.text s!" and proves all {decls.size} of its declarations with no "] ++
        #[.code "sorry", .text " anywhere"]
    else
      #[.text s!" and proves {decls.size - sorried.size} of its {decls.size} declarations; \
        {sorried.size} still {if sorried.size == 1 then "rests" else "rest"} on a "] ++
        #[.code "sorry"]
  let claimed : Array (Inline Manual) := #[
    .code rootPrefix.toString,
    .text s!" states {claims.size} \
      {if claims.size == 1 then "result" else "results"} as \
      {if claims.size == 1 then "a theorem" else "theorems"}"
  ]
  blocks := blocks.push <| .para (claimed ++ proved ++ #[.text "."])
  -- Sentence two: what believing that additionally costs. Both halves are optional.
  let upstream := reachedPackages decls ctx |>.filter fun name =>
    !(ctx.packages.any fun pkg => pkg.name == name && pkg.isToolchain)
  let unaudited := upstream.filter (!ctx.trusted.contains ·)
  let definitions := decls.filter (·.isDefinitionLike)
  let specified := definitions.filter (!·.specifiedBy.isEmpty)
  let mut cost : Array (Array (Inline Manual)) := #[]
  if !upstream.isEmpty then
    cost := cost.push #[
      .link #[.text s!"{upstream.size} upstream \
        {if upstream.size == 1 then "package" else "packages"}"] "trust/",
      .text s!", of which {unaudited.size} \
        {if unaudited.size == 1 then "is unaudited" else "are unaudited"}"
    ]
  if ctx.usesSpecs then
    cost := cost.push #[
      .link #[.text s!"{definitions.size} \
        {if definitions.size == 1 then "definition" else "definitions"}"] "specifications/",
      .text s!", of which {specified.size} \
        {if specified.size == 1 then "says" else "say"} what {if specified.size == 1 then "it means"
          else "they mean"}"
    ]
  if !cost.isEmpty then
    blocks := blocks.push <| .para <|
      #[.text "Believing them means also accepting "] ++
        joinInlines cost.toList #[.text ", and "] ++ #[.text "."]
  blocks := blocks.push <| .para #[
    .text "Every declaration here carries what it claims, what it rests on, and a single \
      self-contained Lean file holding everything you would have to read to check it."
  ]
  -- For a reader coming back to a revised library this is the only sentence on the page they need,
  -- so it goes above the claims listing rather than below it.
  if let some report := ctx.diff? then
    let reaudit := report.needingReaudit
    -- Dated where the ledger knows the date, exactly as the Changes page and the per-declaration
    -- banners are: a reader meeting a bare sha on the landing page cannot tell whether the work
    -- behind it is a day's or a year's.
    let against := baselineName report ctx
    blocks := blocks.push <| .para <|
      if reaudit.isEmpty then
        #[.bold #[.text s!"Nothing needs re-reading since {against}. "],
          .link #[.text "Changes"] "changes/",
          .text " says what did move, including the proofs the kernel has already rechecked."]
      else
        #[.bold #[.text "Read this before you read anything else. "],
          .text s!"{reaudit.size} \
            {if reaudit.size == 1 then "declaration needs" else "declarations need"} reading again \
            since {against} — ",
          .link #[.text "what changed and why"] "changes/", .text "."]
  blocks := blocks.push <| .para #[
    .bold #[.text "The results, largest first by how much machinery they rest on."]
  ]
  if let some list := declIndexList topClaims ctx then
    blocks := blocks.push list
  blocks := blocks.push <| .para #[.link #[.text "See all claims"] "claims/", .text "."]
  return blocks

/-- Builds the root site part with chapter pages and utility sections. -/
private def mkRootPart (cfg : Cli) (rootPrefix : Name) (groups : Array GroupInfo)
    (decls : Array DeclInfo) (ctx : SiteContext)
    (overviewBlocks : Array (Block Manual)) : Part Manual :=
  -- The library's own name, not the tool's: a reader landing here is looking for the project,
  -- and "Referee" belongs in the footer of the site rather than the title of it.
  let title := cfg.siteTitle.getD rootPrefix.toString
  {
    title := #[.text title]
    titleString := title
    metadata := some {
      file := some "index"
      shortTitle := some title
      number := false
    }
    content := mkLandingBlocks rootPrefix decls ctx
      ++ mkDashboardBlocks groups
      ++ overviewBlocks
    -- Changes comes first when there is anything to say: a returning reader's first question is
    -- what their earlier reading no longer covers, and every other page answers a question they
    -- have already asked once. With neither `--baseline` nor `--provenance` the page does not
    -- exist at all.
    subParts := (if ctx.diff?.isNone && ctx.provenance?.isNone then #[]
        else #[mkChangesPart ctx.diff? decls ctx])
      ++ #[mkClaimsPart decls ctx]
      ++ (if ctx.usesSpecs then #[mkSpecificationsPart decls ctx] else #[])
      ++ #[mkBrowsePart decls ctx, mkModulesPart groups ctx, mkTrustPart decls ctx,
           mkAuditPart decls ctx]
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

/-- Imports the target project (the current working directory, since Referee
always runs inside the target project's own Lake environment via `lake env …/referee`)
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
  let packages := packageInfosOf ws rootPrefix
  let decls ← collectDecls projectDir rootPrefix ws.root env packages
  let decls := decls |> dropUnsafeDeps |> attachReverseDeps |> attachTransitiveDeps
    |> attachDataTransitiveDeps |> attachSpecifiedBy |> attachCharacterizes
    |> attachUpstreamPackages
  -- Semantic hashes, when a `semantic_hash export` file was given. Coverage is reported rather
  -- than assumed: a hash file collected against a different revision of the project silently
  -- covers almost nothing, and the count is the only thing that says so before the diff does.
  let decls ← match cfg.hashesPath with
    | none => pure decls
    | some path => do
      let hashes ← readSemanticHashes path
      let decls := attachSemanticHashes hashes decls
      let covered := (decls.filter (·.semanticHash?.isSome)).size
      IO.println s!"Semantic hashes: {hashes.size} in {path}, covering \
        {covered} of {decls.size} exposed declarations"
      if covered == 0 && !decls.isEmpty then
        IO.eprintln s!"warning: no exposed declaration appears in {path}; revision comparisons \
          will fall back to comparing pretty-printed types"
      pure decls
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
  -- Reported only when the project actually uses `@[specifies]`: a project that has never heard of
  -- it should not be told about a count of zero on every run.
  let annotations : Nat := decls.foldl (fun n decl => n + decl.specifies.size) 0
  if annotations > 0 then
    let definitions := decls.filter (·.isDefinitionLike)
    let specified := (definitions.filter fun decl => !decl.specifiedBy.isEmpty).size
    IO.println s!"Specifications: {annotations} `@[specifies]` annotations; \
      {specified} of {definitions.size} definitions have one"
  -- Attribution has to be complete for a trust claim over it to mean anything, so an uncovered
  -- module is reported rather than folded into some package.
  let touched := decls.foldl (init := ({} : Std.HashSet Name)) fun acc decl =>
    decl.upstreamPackages.foldl (init := acc) (·.insert ·)
  let loadedPackages := loadedPackagesOf env packages
  let (externalDecls, expandedPackages) ← externalDeclsOf env packages rootPrefix decls
  IO.println s!"Upstream packages: {touched.size} referenced by name, \
    {loadedPackages.size} with code loaded, {packages.size} in the workspace"
  let unattributed := (moduleIndexMap decls).toArray.filterMap fun (moduleName, _) =>
    if (modulePackageOf packages moduleName).isNone then some moduleName else none
  if !unattributed.isEmpty then
    IO.eprintln s!"warning: {unattributed.size} project modules match no package library root; \
      upstream attribution may be incomplete"
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
    packages
    loadedPackages
    externalDecls
    expandedPackages
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
  match decodeCollectedData json with
  | .ok data =>
    -- The closures are built by functions `Proofs/Deps.lean` proves correct, but what arrives here
    -- has been through `intern`, a file and `resolve`, and that round trip is *not* proved. Checking
    -- the proved properties on the decoded value is what carries them across the gap: see
    -- `CollectedData.integrityViolations`.
    if let some report := data.integrityReport then
      throw <| IO.userError s!"{path}: {report}"
    pure data
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
  -- Under `html-multi/`, unlike the highlighting directories: the extracted files are *published*
  -- (the download link and the web editor both fetch them by URL), not inputs to this phase.
  -- A misspelled `--trust` would otherwise silently vouch for nothing, which reads on the page as
  -- an audited dependency that is in fact unaudited.
  let unknownTrusted := unknownTrustedPackages data.packages cfg.trustedPackages
  if !unknownTrusted.isEmpty then
    IO.eprintln s!"warning: --trust names no package in this workspace: \
      {String.intercalate ", " (unknownTrusted.toList.map toString)}. Known packages: \
      {String.intercalate ", " (data.packages.toList.map (toString ·.name))}"
  let extractedDir := System.FilePath.mk (cfg.outputDir.getD ".") / "html-multi" / "extracted"
  let extractedStems ← loadExtractedStems extractedDir
  if extractedStems.isEmpty then
    IO.println s!"No extracted files found at {extractedDir}; declaration pages will not offer \
      the standalone Lean file. Run the `extract` subcommand to write them."
  else
    IO.println s!"Found {extractedStems.size} extracted files to link"
  if declHighlights.isEmpty then
    IO.println s!"No highlighting found at {highlightingDir}; rendering plain code. \
      Run the `highlight` subcommand for interactive Lean."
  else
    IO.println s!"Loaded highlighting for {declHighlights.size} declarations"
  -- The provenance ledger, if one was given. Read-only here: `build-site` never folds, so
  -- rendering a site can neither extend the record nor corrupt it.
  let provenance? ← match cfg.provenancePath with
    | none => pure none
    | some path => do
      if !(← System.FilePath.pathExists path) then
        IO.eprintln s!"warning: no provenance ledger at {path}; the site will say nothing about \
          when anything changed. Run the `provenance` subcommand to create one."
        pure none
      else
        let raw ← IO.FS.readFile path
        match Json.parse raw >>= FromJson.fromJson? (α := Provenance) with
        | .error e =>
          IO.eprintln s!"warning: could not read the provenance ledger at {path}: {e}"
          pure none
        | .ok (p : Provenance) =>
          if p.version != provenanceVersion then
            IO.eprintln s!"warning: {path} is provenance format version {p.version}, this build \
              expects {provenanceVersion}; ignoring it"
            pure none
          else
            let covered := (data.decls.filter fun d => p.byName.contains d.name).size
            IO.println s!"Provenance {path}: {p.revisions.size} revisions, \
              {(p.latest?.map (·.ref)).getD "?"} newest, covering {covered} of \
              {data.decls.size} declarations"
            if p.dirty then
              IO.eprintln "warning: the ledger was folded from a working tree with uncommitted \
                changes, so its newest revision corresponds to no commit"
            pure (some p)
  -- The baseline comparison. A pure function of the two JSON files, so it belongs here with the
  -- other render-time flags rather than in a phase of its own; see `Referee/Diff.lean`.
  let diff? ← match cfg.baselinePath with
    | none => pure none
    | some path => do
      let baseline ← loadCollectedData path
      let label := cfg.baselineLabel.getD (System.FilePath.mk path).fileName.get!
      let report := diff baseline data label
      IO.println s!"Baseline {path}: {report.needingReaudit.size} of {data.decls.size} \
        declarations need re-reading ({(report.ofKind .statementChanged).size} statement, \
        {(report.ofKind .bodyChanged).size} definition, {(report.ofKind .indirect).size} indirect, \
        {(report.ofKind .upstream).size} underneath, {(report.ofKind .added).size} new); \
        {(report.ofKind .proofOnly).size} proof-only and {report.removed.size} removed"
      IO.println <|
        if report.fullyHashed then
          s!"Compared on semantic hashes ({report.comparisons} declarations)"
        else if report.usedHashes then
          s!"Compared on semantic hashes for {report.hashedComparisons} of {report.comparisons} \
            declarations; the rest on pretty-printed types"
        else
          s!"Compared on pretty-printed types ({report.comparisons} declarations). Collect both \
            revisions with --hashes for a comparison a toolchain upgrade cannot disturb"
      if report.looksLikeToolchainChurn then
        IO.eprintln "warning: almost every statement is reported as changed, which is the shape a \
          toolchain upgrade produces rather than an edit. Statements are compared as \
          pretty-printed elaborated types; collect both revisions on the same toolchain, or with \
          --hashes, for a meaningful diff."
      pure (some report)
  -- Reverse `dataTransDeps`, counted once. Built for a baseline or a ledger, since both order their
  -- queues by it: a changed statement forty results rest on is a different size of problem from
  -- one nothing uses, and that ordering is the only thing on either page that says so.
  let dependentCounts : Std.HashMap Name Nat :=
    if diff?.isNone && provenance?.isNone then {}
    else data.decls.foldl (init := {}) fun acc decl =>
      decl.dataTransDeps.foldl (init := acc) fun acc dep => acc.insert dep (acc.getD dep 0 + 1)
  let ctx : SiteContext := {
    repoUrl? := cfg.repoUrl
    siteUrl? := cfg.siteUrl
    rootPrefix := data.rootPrefix
    declByName := declByNameMap data.decls
    declHrefs := declHrefMap data.decls
    declPageHrefs := declPageHrefMap data.decls
    declHighlights := declHighlights
    minimalFiles := minimalFiles
    extractedStems := extractedStems
    packages := data.packages
    loadedPackages := data.loadedPackages.foldl (·.insert ·) {}
    externalDecls := data.externalDecls.foldl (fun acc e => acc.insert e.name e) {}
    trusted := trustClosure data.packages cfg.trustedPackages
    packageRanks := packageRanks data.packages
    showTrustedUpstream := cfg.showTrustedUpstream
    expandedPackages := data.expandedPackages.foldl (·.insert ·) {}
    toolchainPackages := data.packages.foldl
      (fun acc p => if p.isToolchain then acc.insert p.name else acc) {}
    -- A characterization theorem also registers as a `@[specifies]` annotation, so the first
    -- disjunct covers nearly everything; the second is the project that has annotated a property
    -- and not yet written either theorem, where there is a gap to report and nothing else to
    -- report it.
    usesSpecs := data.decls.any (!·.specifies.isEmpty) || data.decls.any (!·.characterizedBy.isEmpty)
    usesChars := data.decls.any (!·.characterizedBy.isEmpty)
    -- `all`, not `any`: a partially hashed build would check some verdicts and silently skip
    -- others, and a staleness list that is quietly incomplete is worse than one that is absent.
    usesMeanings := !data.decls.isEmpty && data.decls.all (·.proofIrrelHash?.isSome)
    provenance? := provenance?
    provEntries := (provenance?.map (·.byName)).getD {}
    provEdits := (provenance?.map fun p =>
      p.edits.foldl (fun acc (k, v) => acc.insert k v) {}).getD {}
    -- Pinned to the commit the ledger was last folded at, but only when that commit exists: a
    -- ledger folded from a dirty tree names a revision no one can check out, and a link into it
    -- would 404 rather than merely drift.
    sourceRef := (do
      let p ← provenance?
      if p.dirty then none else
      let latest ← p.latest?
      if latest.sha.isEmpty then none else some latest.sha).getD "main"
    diff? := diff?
    changes := (diff?.map (·.byName)).getD {}
    dependentCounts := dependentCounts
  }
  let overviewBlocks := mkProjectOverviewBlocks data.readmeText cfg.repoUrl
  let root := mkRootPart cfg data.rootPrefix groups data.decls ctx overviewBlocks
  -- Fails here rather than mid-render. Verso reports a duplicate tag as `No external ID for
  -- <title>`, which names one of the two pages and does not say that a collision is what went
  -- wrong; on `Mathlib.Order` that took a bisection to identify. `chapterTagOf` and friends make the
  -- cross-kind case impossible, so this is a backstop for whatever the next corpus does.
  let dupes := duplicateDeclTags data.decls
  if !dupes.isEmpty then
    IO.eprintln "Duplicate declaration page tags — these would render as \"No external ID\":"
    for (tagName, names) in dupes.toList.take 10 do
      IO.eprintln s!"  {tagName}: {String.intercalate ", " (names.toList.map toString)}"
    if dupes.size > 10 then
      IO.eprintln s!"  … and {dupes.size - 10} more"
    return 1
  let versoArgs :=
    match cfg.outputDir with
    | some out => ["--output", out]
    | none => []
  manualMain root (options := versoArgs)
    (config := renderConfig data.externalDecls ctx.trusted cfg.showTrustedUpstream)

/-- `collect`: imports the target project, runs the analysis, and writes the result as JSON
to `cfg.dataPath`. -/
private unsafe def runCollect (cfg : Cli) : IO UInt32 := do
  let some dataPath := cfg.dataPath
    | IO.eprintln "collect requires --data PATH"
      return 1
  let (projectDir, ws, rootPrefix, env) ← loadProject cfg
  let data ← collectData cfg projectDir ws rootPrefix env
  IO.FS.writeFile dataPath (encodeCollectedData data).compress
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

/-- `extract-flat`: the tier-2 fallback extraction (see `Referee.Flat`). Same inputs as
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

/-- `provenance`: folds this revision into the ledger and refreshes the blame.

Needs a git working tree and `data.json`, and no Lean environment at all — so it sits between
`collect` and `build-site` as a phase of its own rather than inside either.

Refuses to run without semantic hashes, rather than falling back to comparing text. The ledger is
append-only, so a text-keyed one would record the mass false change of a toolchain upgrade
*permanently*; see the module docstring in `Referee/Provenance.lean`. -/
private def runProvenance (cfg : Cli) : IO UInt32 := do
  let some dataPath := cfg.dataPath
    | IO.eprintln "provenance requires --data PATH"
      return 1
  let some ledgerPath := cfg.provenancePath
    | IO.eprintln "provenance requires --provenance PATH (the ledger to create or extend)"
      return 1
  let data ← loadCollectedData dataPath
  let unhashed := (data.decls.filter (·.proofIrrelHash?.isNone)).size
  if unhashed > 0 then
    IO.eprintln s!"provenance needs semantic hashes: {unhashed} of {data.decls.size} declarations \
      in {dataPath} have none. Re-run `collect --hashes hashes.jsonl` first — there is \
      deliberately no fallback to comparing pretty-printed types, because a ledger is append-only \
      and would record a toolchain upgrade as a permanent library-wide change."
    return 1
  let projectDir : System.FilePath := "."
  let some (head, describedRef) ← headCommit projectDir
    | IO.eprintln "provenance could not read git history from the current directory. It must run \
        inside the target project's working tree, and that tree must be a git repository."
      return 1
  let ref := cfg.revisionRef.getD describedRef
  let dirty ← isDirty projectDir
  if dirty then
    IO.eprintln s!"warning: the working tree has uncommitted changes, so this revision does not \
      correspond to any commit. Recorded as {ref} and flagged in the ledger."
  let existing ← if (← System.FilePath.pathExists ledgerPath) then do
      let raw ← IO.FS.readFile ledgerPath
      match Json.parse raw >>= FromJson.fromJson? (α := Provenance) with
      | .ok (p : Provenance) =>
        if p.version != provenanceVersion then
          IO.eprintln s!"warning: {ledgerPath} was written by format version {p.version}, this is \
            {provenanceVersion}; starting a new ledger rather than folding into it"
          pure ({ project := data.rootPrefix.toString } : Provenance)
        else pure p
      | .error e =>
        IO.eprintln s!"error: could not read the ledger at {ledgerPath}: {e}"
        throw (IO.userError "unreadable ledger")
    else pure ({ project := data.rootPrefix.toString } : Provenance)
  if existing.alreadyAt head.sha then
    IO.println s!"Ledger at {ledgerPath} is already folded at {head.shortSha}; nothing to add"
    return 0
  let startMs ← IO.monoMsNow
  let edits ← blameDeclarations projectDir data.decls
  let folded := foldRevision existing
    { ref := ref, sha := head.sha, date := head.date } data.decls
  let out := { folded with edits := edits, dirty := dirty }
  IO.FS.writeFile ledgerPath (ToJson.toJson out).compress
  let rev := out.revisions.back!
  -- Derived rather than stored: a first sighting is not a change, so `changedCount` alone reports
  -- a revision that only added declarations as having done nothing. Counting the entries whose
  -- first sighting is this revision needs no field in the ledger, and so is exact for every
  -- revision including those folded by an older build.
  let idx := out.revisions.size - 1
  let added := out.entries.foldl (init := 0) fun n e => if e.firstSeenAt == idx then n + 1 else n
  IO.println s!"Folded {ref} ({head.shortSha}, {head.date}) into {ledgerPath}: \
    {out.revisions.size} revisions recorded, {added} of {data.decls.size} declarations new and \
    {rev.changedCount} changed meaning, blame for {edits.size} in \
    {(← IO.monoMsNow) - startMs}ms"
  if out.revisions.size == 1 then
    IO.println "This is the first revision in the ledger, so nothing is reported as changed. \
      Provenance starts accumulating from the next one."
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
    | "provenance" :: rest => ("provenance", rest)
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
  | "provenance" => runProvenance cfg
  | "build-site" => runBuildSite cfg
  | _ => runAll cfg

end

end Referee
