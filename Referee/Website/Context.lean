module

public import Referee.Website.Assets

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
# `SiteContext`: everything a page builder is allowed to ask

One record, threaded through every page builder on the site. It carries the collected declarations
indexed the three ways pages actually look them up, the optional inputs (`highlight`,
`highlight-extracted`, `extract`, `--baseline`, `--provenance`, `formalization.yaml`), and the
render-time flags.

The gates are the interesting half. `usesSpecs`, `usesChars`, `usesMeanings`, `diff?`,
`provenance?` and `formalization?` each answer "does this project have the thing at all", and every
rendering of the corresponding feature is conditioned on one of them. A project that has never
heard of `@[specifies]` must not be told on each of its definition pages that it has no
specification — that is nagging about a feature, not auditing a library — and the same argument
applies to every other gate here.

Also in this file: the three loaders that read what the optional phases wrote, and the small
formatting helpers the loaders and the pages share.
-/

/-- Counts declarations in each visibility group, as `(definitions, lemmas, theorems)`. -/
def countGroups (decls : Array DeclInfo) : Nat × Nat × Nat :=
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
def mkDashboardBlocks (groups : Array GroupInfo) : Array (Block Manual) :=
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
def clipText (n : Nat) (s : String) : String :=
  let s := (String.trimAscii s).toString
  if s.length ≤ n then s else (s.take n).trimAscii.toString ++ "…"

/-- Reads the per-module highlighting JSON written by `highlight` and indexes it by the names
each command defines, so a declaration can be rendered as interactive Lean rather than as inert
text.

Missing or unreadable files are not an error: `build-site` must keep working without a
`highlight` pass, falling back to plain code blocks. Each module's JSON is decoded and reduced to
the entries we keep before moving to the next, since the whole corpus is far larger than the part
that is actually referenced. -/
def loadHighlighting (dir : System.FilePath) : IO (Std.HashMap Name Highlighted) := do
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
def leanCodeBlock (hl? : Option Highlighted) (fallback : String) : Block Manual :=
  match hl? with
  | some hl => .other (Block.lean hl { showProofStates := false, defSite := some false }) #[]
  | none => .code fallback

/-- A minimal file's highlighted rendering plus whether it compiled. -/
structure MinimalFile where
  code : Highlighted
  errors : Array String

/-- Reads the highlighting of the extracted minimal files written by `highlight-extracted`,
keyed by the `anchorIdOf` stem the extraction used.

The whole file is rendered as one `Highlighted` — the concatenation of its commands, which
reproduces the source including comments and blank lines, because `FrontendResult.updateLeading`
attaches the surrounding trivia to the commands. -/
def loadMinimalFiles (dir : System.FilePath) :
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
def loadExtractedStems (dir : System.FilePath) : IO (Std.HashSet String) := do
  if !(← dir.pathExists) then
    return {}
  let mut acc : Std.HashSet String := {}
  for entry in (← dir.readDir) do
    if entry.path.extension == some "lean" then
      if let some stem := entry.path.fileStem then
        acc := acc.insert stem
  return acc

/-- Shared lookup tables and configuration threaded through page-building helpers. -/
structure SiteContext where
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
  /-- The project's `formalization.yaml`, when it has one.

  Gated exactly as `usesSpecs` and `diff?` are: a project without the file acquires no Claims page,
  no nav entry and no mention of the registry anywhere. Unlike every other field here it is not
  derived from the environment at all — see `claimedResults?`, which is the gate the pages actually
  consult, and `Referee.Formalization` for what is read out of the file. -/
  formalization? : Option Formalization := none
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

end

end Referee
