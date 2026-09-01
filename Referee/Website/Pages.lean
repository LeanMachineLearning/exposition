module

public import Referee.Website.Declaration

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
# The pages

Every page of the site that is not a declaration's own: the chapter and module pages that follow the
import graph, the five utility pages that cut across it, and the landing page and root part that
carry them.

The utility pages are the ones a referee needs and ordinary documentation does not have, and each
answers a question the chapter hierarchy cannot: what does the project claim
(`formalization.yaml`'s main results, when there is such a file), what does the library state
(`theorem` against `lemma`), what changed since a revision, what is specified, what is in here at
all, and what is incomplete or assumed. Each is gated on the project having the input it reports
on, so a project that ships none of them gets a site with none of them rather than a site full of
empty pages.
-/

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
def mkProjectOverviewBlocks (readmeText : Option String) (repoUrl? : Option String) :
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
def mkGroupPart (group : GroupInfo) (ctx : SiteContext) : Part Manual :=
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
on"), plus the claims and sorries pages for whole-library questions. -/

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

/-- Builds the page listing every claim, grouped by chapter, with the reader's audit state on it.

Claims and audit were two pages, and the split was wrong. Both had the same list down the middle —
one rendered it as links, the other as links with a verdict attached — and neither was readable
alone: the claims page could not say which of them you had been through, and the audit page
repeated the list without ever saying what makes a declaration a claim in the first place. So this
is one page, and it reads in the order the questions arrive: what does this library claim, what
does accepting one of them mean, which are they, and how far have you got.

The listing is built here, chapter by chapter, each chapter a fold that starts open — shut one and
the chapters you have not got to yet come back into view. Only the *state* on a row comes from the
browser, into slots `audit.js` fills; see `Block.claimList` for why the rows themselves cannot.

The one page on this site whose content is not derived from the library alone. The reading a
referee does is work, and work that cannot be recorded has to be redone — and the number that
matters is not how many declarations someone has ticked off but how many claims are covered
*including everything their statements rest on*, which no checkbox can say by itself. -/
private def mkTheoremsPart (decls : Array DeclInfo) (groups : Array GroupInfo) (ctx : SiteContext)
    : Part Manual :=
  let claims := claimsOf decls
  -- Chapters in the site's own order, which is the import graph's, and within one the claims that
  -- rest on the most machinery first: among results nothing else builds on, that is usually the
  -- substantial one. A chapter with no claims gets no fold rather than an empty one.
  let chapterBlocks : Array (Block Manual) := groups.filterMap fun group =>
    let inChapter := claims.filter (·.groupKey == group.key)
    let ranked := inChapter.qsort fun a b => closureSize a ctx > closureSize b ctx
    (mkClaimListBlock ranked ctx).map fun list =>
      .other (Block.details {
        summary := humanizeWord group.key
        startsOpen := true
        headingLevel := some 3
      }) #[list]
  {
    title := #[.text "The Theorems This Library States"]
    titleString := "The Theorems This Library States"
    metadata := some {
      file := some "theorems"
      shortTitle := some "Theorems"
      tag := some (.provided "theorems")
      number := false
    }
    content := #[
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
        ranked within each chapter by how much machinery they rest on."],
      .para #[
        .text "Against each one is what you have made of it. A declaration is ",
        .emph #[.text "accepted"],
        .text " when you have read it and judged that it says what its name claims — and ",
        .emph #[.text "covered"], .text " when, in addition, every declaration its statement rests \
          on is accepted too. The gap between those two is the point: accepting a theorem whose \
          definitions you have not read accepts a sentence, not a theorem."
      ],
      .para #[
        .text "Whether something is ", .emph #[.text "proved"], .text " is a separate question. A ",
        .code "sorry", .text " is flagged below but never blocks acceptance, because accepting is \
          a judgement about what a statement means; ",
        .link #[.text "Sorries and assumptions"] "sorries/", .text " reports the rest."
      ],
    ] ++ chapterBlocks ++ #[
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

/-! ## The project's own claims

Everything above this point is derived from the compiled library. `formalization.yaml` is not: it is
a document the author wrote, and the Claims page reads it for the one thing no analysis of the
environment can supply — which of the library's results the project puts forward as the point of it.
See `Referee.Formalization` for the parser and for what it does not implement. -/

/-- The `formalization.yaml`, when it declares at least one main result.

The gate on every part of the Claims page, and it is two conditions rather than one. A project with
no such file has not made the claim this page reports, so there is nothing to show; a project whose
file declares no `status.main_results` — the schema calls the field optional — has made the rest of
the declaration and not that one, and a page reading "this project names no main results" would be
nagging about a field rather than reporting on a library. Both cases get no page, which is how
`usesSpecs` gates the Specifications page and for the same reason. -/
def claimedResults? (ctx : SiteContext) : Option Formalization :=
  match ctx.formalization? with
  | some form => if form.mainResults.isEmpty then none else some form
  | none => none

/-- Each declared main result paired with the declaration it names, where the library has one.

Entries that match nothing are kept rather than dropped. A `formalization.yaml` naming a result the
library does not export is exactly the discrepancy a referee is here to find — most often a rename
the metadata did not follow — and a page that listed one fewer claim than the file declares would
hide it behind a number that looked fine. -/
private def resolvedMainResults (form : Formalization) (ctx : SiteContext) :
    Array (MainResult × Option DeclInfo) :=
  form.mainResults.map fun result => (result, ctx.declByName.get? result.declaration.toName)

/-- Builds the Claims page: what the project's own `formalization.yaml` puts forward as its main
results.

The rows are the ones the Theorems page uses, deliberately and exactly: the same link, the same
closure count, the same `sorry` flag, the same audit state under the same key. A claim is one
declaration whether it is reached from the file's curated list or from the library's own, and a
reader who has recorded work on it must see that work in both places. What differs is only which
declarations are on the page and in what order — here, the file's order, because a curated list is
an argument about what matters and its order is part of the argument.

What it does *not* take from the file is anything the library already answers. `main_results` also
carries a `sorry_count` and an `axioms` list per result; those are the project's account of facts
this site computes from the environment, and rendering the account beside the measurement would
invite a reader to compare two numbers that are not measured the same way — the file's counts
exclude Comparator challenge modules, this site's do not. The row shows the measurement. The two
fields the environment genuinely cannot supply, `literature_dependencies` and the file's own
statement of scope, are below the list.

Deliberately no audit apparatus: the excerpt payload turns off the export/import/report block (see
`AuditData.excerpt`), which belongs to the page carrying every claim rather than to a page carrying
the handful the author chose. -/
private def mkClaimsPart (form : Formalization) (decls : Array DeclInfo) (ctx : SiteContext)
    : Part Manual := Id.run do
  let resolved := resolvedMainResults form ctx
  let matched := resolved.filterMap (·.2)
  let listed := matched.filter (ctx.declPageHrefs.contains ·.name)
  let missing := resolved.filterMap fun (result, decl?) =>
    if decl?.isSome then none else some result
  let mut blocks : Array (Block Manual) := #[
    .para #[
      .text "These are the results the project puts forward as its own, read from the ",
      .code "status.main_results", .text " list of its ", .code "formalization.yaml", .text " — \
        the metadata document the ",
      .link #[.text "Palomar registry"] "https://palomar-registry.org/",
      .text " requires of a submission."
    ],
    .para #[
      .bold #[.text "The one list here the library cannot check. "],
      .text "Every other page is derived from the compiled environment. This one is a sentence the \
        author wrote, and the site takes it at face value. What each result ",
      .emph #[.text "rests on"],
      .text " is still measured the way it is measured everywhere — the count beneath each row and \
        the ", .code "sorry", .text " flag on it are this site's numbers, not the file's — but \
        whether these are the results that matter is the project's claim and nobody else's."
    ],
    .para #[
      .text "The derived list is next door. ",
      .link #[.text "The theorems this library states"] "theorems/",
      .text " is everything written with the ", .code "theorem", .text " keyword, ranked by how \
        much machinery it rests on. Where the two lists disagree — a headline result stated as a ",
      .code "lemma", .text ", or a theorem the file passes over — the disagreement is information \
        about the project rather than a fault in either page."
    ]
  ]
  blocks := blocks.push <| .para #[
    .text s!"{form.mainResults.size} \
      {if form.mainResults.size == 1 then "result is" else "results are"} declared, in the order \
      the file gives them rather than in any order derived here."
  ]
  if let some list := mkClaimListBlock listed ctx then
    blocks := blocks.push list
    blocks := blocks.push <|
      .other (Block.auditData (mkAuditData decls ctx (featured? := some (listed.map (·.name))))) #[]
  if !missing.isEmpty then
    blocks := blocks.push <| .para #[
      .bold #[.text s!"{missing.size} of them {if missing.size == 1 then "names a declaration this \
        library does not have" else "name declarations this library does not have"}. "],
      .text "A rename the metadata did not follow, a result not written yet, or a declaration this \
        site does not expose — under all three the file and the library disagree about what exists, \
        which is worth knowing before trusting either. The file's own account of where each lives \
        is the only clue the site can offer."
    ]
    blocks := blocks.push <| .ul <| missing.map fun result =>
      Verso.Doc.ListItem.mk #[.para (#[.code result.declaration] ++
        (if result.file.isEmpty then #[.text " — no file given"]
         else #[.text " — declared in ", .code result.file]))]
  let assumed := resolved.filter fun (result, _) => !result.literatureDependencies.isEmpty
  if !assumed.isEmpty then
    blocks := blocks.push <| .para #[
      .bold #[.text "Assumed, not proved. "],
      .text "A result that takes a theorem from the literature is proved ",
      .emph #[.text "modulo"],
      .text " that theorem, and no analysis of the compiled library can say so: the assumption \
        lives in the author's prose rather than in the term, so it leaves behind no ",
      .code "sorry",
      .text " and no extra axiom. These are the ones the file declares. Everything the ",
      .link #[.text "sorries and assumptions"] "sorries/",
      .text " page reports is separate from them, and neither list bounds the other."
    ]
    blocks := blocks.push <| .ul <| assumed.map fun (result, _) =>
      Verso.Doc.ListItem.mk #[
        .para #[.code result.declaration],
        .ul <| result.literatureDependencies.map fun dep =>
          Verso.Doc.ListItem.mk #[.para (#[.text dep.statement] ++
            (if dep.source.isEmpty then #[] else #[.text " — ", .emph #[.text dep.source]]))]
      ]
  if !form.scope.isEmpty then
    blocks := blocks.push <| .para #[
      .bold #[.text "What the project says it does and does not cover. "],
      .text "Its ", .code "status.scope", .text ", verbatim — the place a formalization declares \
        the weakened hypothesis or the omitted case that a list of theorem names cannot show."
    ]
    -- One paragraph per line rather than one for the whole thing. An author who wrote the field as
    -- a `|` block chose those line breaks, and a project that states its omissions one per line is
    -- the common case; a `>-` block arrives here as a single line and is unaffected either way.
    blocks := blocks.push <| .blockquote <|
      (form.scope.splitOn "\n").toArray.filterMap fun line =>
        let line := (String.trimAscii line).toString
        if line.isEmpty then none else some (.para #[.text line])
  return {
    title := #[.text "What This Project Claims"]
    titleString := "What This Project Claims"
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
        the ", .link #[.text "Sorries and assumptions"] "sorries/", .text " page is for."
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
        accepts them — the same argument the ", .link #[.text "Sorries and assumptions"] "sorries/",
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

The counterpart to the sorries page. That one answers "is this proved"; this answers "is this the right
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
        an axiom is itself an assumption and belongs on ",
      .link #[.text "Sorries and assumptions"] "sorries/",
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

The uncurated entry point. Theorems and Trust are curated views for readers who know what they are
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

/-- The whole project's module dependency graph, and the heading it sits under.

The one aggregate view that survives at library scale. A graph over every declaration is a
hairball — that page was removed — but a project has tens of modules, not thousands, and this is
the only view that shows structure *across* chapters, where the interesting dependencies are: in
`LeanMachineLearning` half the module dependencies cross a chapter boundary, and the per-chapter
graphs cannot show any of them.

Was a page of its own, and did not earn one: it is a picture with two sentences of caption, and the
listing of every module — the thing a reader goes looking for the moment the graph raises a
question — was on the landing page all along. So the graph moved to sit directly above that listing
instead, and the two now read as one section. -/
private def mkModuleGraphBlocks (groups : Array GroupInfo) (ctx : SiteContext) :
    Array (Block Manual) :=
  let modules := groups.flatMap (·.modules)
  let (graph, omitted) := connectedOnly (transitiveReduce (mkModuleGraphData modules ctx))
  let intro : Array (Block Manual) := #[
    .other (Block.sectionHeading "Modules") #[],
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
  intro ++ note ++ #[.other (Block.graph graph) #[]]

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

/-- The upstream-trust section of the sorries page: the package graph, the finding, and what to do
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
    -- Names no other page. Specifications is built only for a project that uses `@[specifies]`, and
    -- this paragraph used to link to it unconditionally, so on every project without an annotation
    -- the sentence pointed at nothing.
    .para #[
      .text "What does not come for free is an upstream ", .emph #[.text "definition"],
      .text " that a statement is about. A theorem mentioning a definition from another package \
        means what it means only if that definition is the intended one, and no proof settles \
        that — nothing below the statement can, because it is the statement that names it. So what \
        follows counts statements, not proofs."
    ],
    .para #[
      .text "The graph is the dependency order: the toolchain at the top, this project at the \
        bottom, an edge from each package to the one that requires it."
    ]
  ]
  -- Stated as what is unaudited, never as what is trusted, for the same reason the sorry count is:
  -- a package the reader passed to `--trust` is not a finding, and leading with how many of them
  -- there are turns their own input back into a score.
  let verdict : Array (Inline Manual) :=
    if untrusted.isEmpty then
      #[.text s!"No upstream package is unaudited: every one of the {upstream.size} was passed to ",
        .code "--trust", .text "."]
    else if trustedUpstream.isEmpty then
      #[.bold #[.text s!"All {upstream.size} upstream packages are unaudited."],
        .text " The site was built without ", .code "--trust", .text ", so every upstream package \
          below counts as unaudited. That is the honest default rather than a finding: pass ",
        .code "--trust PKG", .text " for each package you have audited, and it will vouch for what \
          that package rests on too."]
    else
      #[.bold #[.text s!"{untrusted.size} of {upstream.size} upstream packages are unaudited."],
        .text " Every declaration whose statement reaches into one says so on its own page."]
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

/-- Builds the page listing what is incomplete or assumed: sorries, extra axioms, upstream packages.

**Findings only.** This page was called "Trust", and said things like "1572 of 1808 declarations are
fully proved". Both were wrong in the same way. "Trust" names a verdict the site is in no position
to reach — the kernel checking a proof is not a reason to trust what the theorem says, which is the
whole argument the rest of this tool makes — and a count of what is proved reads as a score, on a
measure where the number that matters is the one that is not zero. A reader who wants "how much of
this is done" has the project's own progress tracking for it. What is reported here is what would
make a referee stop, and nothing else; where there is nothing, the page says so in one line and
moves on.

The listings fold shut. Each is a few hundred names on a library with real gaps, and the reader
arriving here needs the counts first — which sections have anything in them at all — and the names
only for whichever one they decide to open. -/
private def mkAssumptionsPart (decls : Array DeclInfo) (ctx : SiteContext) : Part Manual :=
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
      .text "). This is the referee's checklist, and it reports only what is missing: nothing here \
        is a measure of how far the library has got."]
  ]
  blocks := blocks.push <| .para <|
    if sorried.isEmpty then
      #[.text "No declaration depends on a ", .code "sorry", .text "."]
    else
      #[.bold #[.text s!"{sorried.size} of {decls.size} declarations depend on a "],
        .code "sorry",
        .text s!" — {ownSorry.size} directly, {inherited.size} inherited from something they use."]
  if let some list := declIndexList (ownSorry.qsort fun a b => a.name.lt b.name) ctx then
    blocks := blocks.push <| .other
      (Block.details { summary := s!"Contains a `sorry` directly ({ownSorry.size})" }) #[list]
  if let some list := declIndexList (inherited.qsort fun a b => a.name.lt b.name) ctx then
    blocks := blocks.push <| .other
      (Block.details { summary := s!"Inherits a `sorry` ({inherited.size})" })
      #[.para #[.text "Each declaration's own page names the chain that reaches the gap."], list]
  if let some list := declIndexList (extraAxiom.qsort fun a b => a.name.lt b.name) ctx then
    blocks := blocks.push <| .other
      (Block.details { summary := s!"Rests on extra axioms ({extraAxiom.size})" }) #[list]
  else
    blocks := blocks.push <| .para #[.text "No declaration rests on an axiom beyond the ordinary three."]
  blocks := blocks ++ mkUpstreamTrustBlocks decls ctx
  return {
    title := #[.text "Sorries and assumptions"]
    titleString := "Sorries and assumptions"
    metadata := some {
      file := some "sorries"
      shortTitle := some "Sorries"
      tag := some (.provided "sorries")
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
        {if upstream.size == 1 then "package" else "packages"}"] "sorries/",
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
  -- The same rows as the claims page, live: docstring, coverage, verdict and the button that starts
  -- a reading queue. A static list here would have been a second way of presenting the one thing
  -- this site is most often used to look at, and a reader arriving with work already recorded would
  -- have had to go somewhere else to see any of it.
  --
  -- No chapter folds: this is a ranking across all of them. The payload is an excerpt, so what ships
  -- is these ten claims and their closures rather than the library — see `mkAuditData`.
  if let some list := mkClaimListBlock topClaims ctx then
    blocks := blocks.push list
    blocks := blocks.push <|
      .other (Block.auditData (mkAuditData decls ctx (featured? := some (topClaims.map (·.name)))))
        #[]
  blocks := blocks.push <| .para #[.link #[.text "See all theorems"] "theorems/", .text "."]
  return blocks

/-- Builds the root site part with chapter pages and utility sections. -/
def mkRootPart (cfg : Cli) (rootPrefix : Name) (groups : Array GroupInfo)
    (decls : Array DeclInfo) (ctx : SiteContext)
    (overviewBlocks : Array (Block Manual))
    (groupParts? : Option (Array (Part Manual)) := none)
    (withUtility : Bool := true) (withLanding : Bool := true) : Part Manual :=
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
    -- Theorems, then what the project says it is, then how it is built: the three questions in the
    -- order a reader asks them. The README used to sit *below* the module listing, which put a
    -- page of chapter contents between "here is what this proves" and the author's own account of
    -- it. The module graph then leads the listing it is a picture of, rather than standing on a
    -- page of its own — see `mkModuleGraphBlocks`.
    --
    -- `withLanding`/`withUtility` exist for per-chapter rendering (see *Chapter-wise rendering*):
    -- a chapter-scoped run wants the same root part — same title, tag and numbering — with none of
    -- the whole-library content, which is rendered once by the global run instead.
    content := if withLanding then
        mkLandingBlocks rootPrefix decls ctx
          ++ overviewBlocks
          ++ mkModuleGraphBlocks groups ctx
          ++ mkDashboardBlocks groups
      else #[]
    -- Changes comes first when there is anything to say: a returning reader's first question is
    -- what their earlier reading no longer covers, and every other page answers a question they
    -- have already asked once. With neither `--baseline` nor `--provenance` the page does not
    -- exist at all.
    subParts := (if !withUtility then #[]
        else (if ctx.diff?.isNone && ctx.provenance?.isNone then #[]
          else #[mkChangesPart ctx.diff? decls ctx])
        ++ (match claimedResults? ctx with
            | some form => #[mkClaimsPart form decls ctx]
            | none => #[])
        ++ #[mkTheoremsPart decls groups ctx]
        ++ (if ctx.usesSpecs then #[mkSpecificationsPart decls ctx] else #[])
        ++ #[mkBrowsePart decls ctx, mkAssumptionsPart decls ctx])
      ++ (groupParts?.getD (groups.map fun group => mkGroupPart group ctx))
  }

end

end Referee
