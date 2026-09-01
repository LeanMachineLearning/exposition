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

end

end Referee
