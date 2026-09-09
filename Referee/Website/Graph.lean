module

public import Referee.Website.Context

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
# Dependency graphs

The nodes and edges behind every picture on the site: a declaration's own closure, a chapter's
module graph, the package graph on the sorries page, and the two views a characterized definition
offers. `assets/graph.js` draws whatever this produces; nothing here knows how a graph looks.

Two passes matter and neither is decoration. `withUpstreamNodes` adds the upstream constants a
statement is *about*, which is what turns "this rests on 40 things" into a reader's question about
Mathlib rather than a number. `transitiveReduce` removes the edges implied by others — on a real
closure that is most of them, and the picture is unreadable without it.
-/

/-- One project declaration as a graph node.

Factored out of `mkGraphData` because the chapter tables are built from it too (`declTableEntry`):
what `thinGraphNodes` takes out of a node and what the table puts back have to be the same
fields computed the same way, and the only way to guarantee that is to have one place that
computes them. -/
def declNode (decl : DeclInfo) (declHrefs : Std.HashMap Name String)
    (focus? : Option Name := none) : GraphNode := {
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
  -- The summary `graph.js` shows under a clicked node while it fetches that node's real card, and
  -- keeps when it cannot — from a site opened over `file://`, where a page cannot fetch its
  -- siblings. Clipped, because it rides along in every node of every graph and a handful of
  -- declarations carry very long statements. Not at 600, though: that cut 88 of `AlphaRAR`'s 2503
  -- project nodes mid-statement, and a statement truncated before its conclusion is worse than no
  -- preview at all — it shows a theorem's hypotheses and hides what they imply. A limit has to
  -- fall somewhere, but it should fall past the point where the summary still answers the
  -- question it exists for.
  signature := clipText 2400 decl.displaySignature
  doc := clipText 1200 (decl.docText?.getD "")
  meaning := meaningKeyOf decl
}

/-- Builds graph nodes/edges for `decls`, with edges only between declarations that are
themselves in `decls`. Each edge points from a dependency (the "parent") to the declaration
that depends on it (the "child"), so the arrow direction follows the order in which the
declarations must be established. `depsOf` picks which dependency set each edge follows: pass
`meaningDeps` on declaration detail pages, to match their `dataTransDeps` closure, or `(·.deps)`
(always type + body) for the full-repository graph. -/
def mkGraphData (decls : Array DeclInfo) (declHrefs : Std.HashMap Name String)
    (depsOf : DeclInfo → Array Name) (focus? : Option Name := none)
    (projectName : String := "") : GraphData :=
  let names : Std.HashSet Name := decls.foldl (fun acc d => acc.insert d.name) {}
  let nodes := decls.map (declNode · declHrefs focus?)
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
  question about the closure, and this is the trust surface — the same set the sorries page counts. On
  `AlphaRAR` it comes to at most 9 nodes on any page and 0 on most, the whole surface into
  `LeanMachineLearning` being 15 declarations.
* **audited** packages, for the `statements` declarations only. Here the question is not trust — the
  reader has already said they accept the package — but *what this statement is about*, which is a
  property of this statement and not of everything below it. Over the whole closure it would be
  several hundred Mathlib nodes; for one statement it is a median of 21. Normally the one declaration
  the page is about; a characterization view passes the property and the relation instead, those
  being the statements that view exists to show.

`pinned` names constants that must be drawn whatever their package's trust and whatever
`showTrustedUpstream` says: a characterization stops at a relation that is very often an upstream
one (`Filter.EventuallyEq`), and a view whose whole subject is the relation cannot leave it out
because Mathlib happens to be audited. Toolchain constants are still dropped — `Eq` as a node says
nothing — since `packageOf` refuses them.

Proof-only references are excluded from both by `depsOf` being `meaningDeps`. -/
def withUpstreamNodes (data : GraphData) (decls : Array DeclInfo) (ctx : SiteContext)
    (depsOf : DeclInfo → Array Name) (statements : Array Name := #[])
    (pinned : Array Name := #[]) : GraphData :=
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
    if ctx.showTrustedUpstream then decls.filter (fun d => statements.contains d.name) else #[]
  let surface := (gather focusDecls true).fold (init := gather decls false) fun acc k v =>
    acc.insert k v
  let surface := pinned.foldl (init := surface) fun acc name =>
    if ctx.declByName.contains name then acc
    else match packageOf name with
      | some pkg => acc.insert name pkg
      | none => acc
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
def transitiveReduce (data : GraphData) : GraphData :=
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

/-! ## The chapter tables

What a declaration *is* — its label, kind, module, href, signature, docstring, what it means — is
the same on every page that draws it, and a declaration is drawn on every page whose closure
reaches it. Writing those fields into each node wrote the same text into thousands of pages: on the
`LeanMachineLearning` site the node payload was 21% of every declaration page and 54% of *that* was
the signature and docstring shown under a clicked node.

So a node now carries what is true of it *in this picture* — its id, whether it is the focus,
whether the view stopped at it — and everything else is looked up by id in a table shared by the
chapter. `graph.js` fills the nodes back in before it draws, so nothing downstream of the lookup
knows this happened.

Per chapter rather than per site because the table is fetched, and a reader who opens one
declaration should not pay for the library. Closures are chapter-local enough for that to pay:
measured on `LeanMachineLearning`, a page's project nodes span 1.23 chapters on average, and the
per-chapter tables together hold 1.08 entries per declaration — the overlap between them is small,
so scoping by chapter costs 8% of duplicated table and saves the reader everything else.

This is the mechanism `upstream.js` already uses for upstream constants, for the reason recorded on
`withUpstreamNodes`, generalized to the project's own declarations. -/

/-- What a node needs before it can be drawn: everything `thinGraphNodes` takes out of it except
the signature and the docstring, which `declTextEntry` carries instead.

Keys are one letter because there is one entry per declaration in the chapter and the key text
would otherwise outweigh some of the values. -/
def declDrawEntry (ix : Nat) (node : GraphNode) : Json :=
  Json.mkObj [
    -- The number a thinned node is; see `SiteContext.nodeIndex`. Here rather than in a table of its
    -- own so that a page that loads a chapter's entries also loads the numbering that reaches them.
    ("i", Json.num ix),
    ("l", Json.str node.label),
    ("k", Json.str node.kind),
    ("s", Json.str node.status),
    ("g", Json.str node.groupKey),
    ("m", Json.str node.moduleName),
    ("h", Json.str node.href),
    ("q", Json.str node.meaning)]

/-- What a node needs only once a reader clicks it: the summary shown under the open node while its
real card is fetched, and kept when there is nothing to fetch from. See `declTextPath`. -/
def declTextEntry (node : GraphNode) : Json :=
  Json.mkObj [
    ("sig", Json.str node.signature),
    ("d", Json.str node.doc)]

/-- The draw-time table for one chapter: every declaration any of its pages can draw, keyed by name.

`decls` is the chapter's own declarations *together with everything in their closures*, since a
page draws its closure and a closure crosses chapters.

Also records where this chapter's text table lives, keyed by the chapter as a node reports it in
`groupKey`. That is what lets a click on a node find the one file holding its signature without the
page having to carry a map of its own, or `graph.js` having to reimplement `slugify`. -/
def declDrawTableJs (groupKey : String) (decls : Array DeclInfo)
    (declHrefs : Std.HashMap Name String) (nodeIndex : Std.HashMap Name Nat) : String :=
  let entries := decls.map fun decl =>
    (decl.name.toString, declDrawEntry (nodeIndex.getD decl.name 0) (declNode decl declHrefs))
  -- Merged into whatever is already there, not assigned over it: a page whose closure crosses
  -- chapters loads more than one of these, and the second must not erase the first.
  s!"window.RefereeDecls = Object.assign(window.RefereeDecls || \{}, \
    {(Json.mkObj entries.toList).compress});\n\
    window.RefereeDeclText = Object.assign(window.RefereeDeclText || \{}, \
    {(Json.mkObj [(groupKey, Json.str (declTextPath groupKey))]).compress});"

/-- The click-time table for one chapter, over the same declarations as its draw table. -/
def declTextTableJs (decls : Array DeclInfo) (declHrefs : Std.HashMap Name String) : String :=
  let entries := decls.map fun decl => (decl.name.toString, declTextEntry (declNode decl declHrefs))
  s!"window.RefereeDeclsText = Object.assign(window.RefereeDeclsText || \{}, \
    {(Json.mkObj entries.toList).compress});"

/-- Interns `edges` against `nodes`: the index pairs, and the edges that could not be interned.

Conservative in the same way `transitiveReduce` is about the same case: an edge whose endpoint was
never listed as a node is kept as it was rather than dropped or guessed at, because an edge is a
real dependency and a picture that quietly loses one is worse than a larger picture. -/
def internEdges (nodes : Array GraphNode) (edges : Array GraphEdge) :
    Array Nat × Array GraphEdge :=
  let index : Std.HashMap String Nat :=
    nodes.zipIdx.foldl (init := {}) fun acc (n, i) => acc.insert n.id i
  edges.foldl (init := (#[], #[])) fun (ix, kept) e =>
    match index[e.source]?, index[e.target]? with
    | some s, some t => ((ix.push s).push t, kept)
    | _, _ => (ix, kept.push e)

/-- Strips from every node what a shared table holds, and records which chapter tables the page must
load to put its project nodes back.

Two tables, because there are two kinds of node and they were already shared in different places: a
project node is restored from its chapter's `RefereeDecls` (written by `declTableJs`), an upstream
band node from the `RefereeUpstream` and `RefereePackages` that `upstreamJsFile` has always emitted.
Both end up carrying an id and nothing else.

Module and package graphs never reach this — it is applied on declaration pages only — so their
nodes keep everything they have always had.

`focus` and `unexpanded` stay on every node because they are facts about *this* drawing rather than
about the declaration, and the same declaration is the focus of one page and an ordinary node on a
hundred others. -/
def thinGraphNodes (data : GraphData) (ctx : SiteContext) : GraphData :=
  let isProject (n : GraphNode) : Bool := n.upstream.isEmpty
  -- An upstream node may only be thinned if `upstream.js` will actually carry it, and that file
  -- ships what the current flags can draw rather than everything `collect` recorded. The two sets
  -- are the same but for one case, and it is a real one: `withUpstreamNodes` draws a `pinned`
  -- constant whatever its package's trust, so a characterization view pinning a relation from an
  -- audited package on a site built without `--show-trusted-upstream` draws a node the table does
  -- not hold. Thinning that node would blank it. The condition below is `upstreamJsFile`'s own
  -- filter, asked of this constant.
  let inUpstreamTable (n : GraphNode) : Bool :=
    match ctx.externalDecls.get? n.id.toName with
    | none => false
    | some e => ctx.showTrustedUpstream || !ctx.trusted.contains e.package
  let thin (n : GraphNode) : GraphNode :=
    if isProject n then
      -- Written out rather than left to a `with`: these are exactly the fields the table restores,
      -- and a field added to `GraphNode` later should have to be classified here on purpose rather
      -- than ride along in every node because nobody thought about it.
      { id := n.id, focus := n.focus, unexpanded := n.unexpanded,
        label := "", kind := "", status := "", groupKey := "", moduleName := "", href := "" }
    else if inUpstreamTable n then
      -- A band node keeps nothing but its id. `label` and the module come from `RefereeUpstream`,
      -- the package from the same entry, and rank and trust from `RefereePackages` — every one of
      -- them a fact about the constant or its package rather than about this picture, and every one
      -- of them repeated on each of the thousands of pages that named the constant.
      --
      -- `upstream` goes too, which is what marked a node as belonging to the band at all; the
      -- client recovers that from the id being in the table, and the two node sets are disjoint
      -- because `packageOf` refuses anything the project declares.
      { id := n.id, focus := n.focus, unexpanded := n.unexpanded,
        label := "", kind := "", status := "", groupKey := "", moduleName := "", href := "",
        upstream := "", upstreamRank := 0 }
    else n
  let chaptersOf (ns : Array GraphNode) : Array String :=
    ns.filterMap fun n => if isProject n && !n.groupKey.isEmpty then some n.groupKey else none
  let chapters := (chaptersOf data.nodes ++ data.views.flatMap (chaptersOf ·.nodes)).foldl
    (init := (#[] : Array String)) fun acc g => if acc.contains g then acc else acc.push g
  -- A node can leave its name behind only if a table will give it back. Project nodes always can;
  -- an upstream node can when `inUpstreamTable` says so, which is the same condition that let it be
  -- thinned at all.
  let indexOf (n : GraphNode) : Option Nat :=
    if isProject n || inUpstreamTable n then ctx.nodeIndex[n.id.toName]? else none
  /- All or nothing per view. A view with one unindexable node keeps every node as an object: the
     alternative is a payload that is a flat array *and* an object array with positions tying them
     together, which costs more to describe than the names it saves. The case is rare by
     construction — see `inUpstreamTable` — and this is the conservative branch. -/
  let flatten (ns : Array GraphNode) : Array Nat × Array Nat × Array Nat × Array GraphNode :=
    match ns.mapM indexOf with
    | none => (#[], #[], #[], ns.map thin)
    | some ixs =>
      let focus := ns.zipIdx.filterMap fun (n, i) => if n.focus then some i else none
      let cut := ns.zipIdx.filterMap fun (n, i) => if n.unexpanded then some i else none
      (ixs, focus, cut, #[])
  let (edgeIx, edges) := internEdges data.nodes data.edges
  let (nodeIx, focusIx, unexpandedIx, nodes) := flatten data.nodes
  { data with
    nodes, nodeIx, focusIx, unexpandedIx
    edges, edgeIx
    views := data.views.map fun v =>
      let (vIx, vEdges) := internEdges v.nodes v.edges
      let (vn, vf, vc, vNodes) := flatten v.nodes
      { v with
        nodes := vNodes
        nodeIx := vn
        focusIx := vf
        unexpandedIx := vc
        edges := vEdges
        edgeIx := vIx }
    tables := chapters.map declTablePath }

end

end Referee
