module

public import Referee.Website.Project
public import Referee.Website.PerChapter

open Lake
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
# The site build, and the command line

What is left once the pages, the block extensions and the post-processing passes have their own
files: `buildSiteFrom`, which assembles a `SiteContext` from collected data and hands the root part
to Verso, and the subcommand dispatch that `Main.lean` calls.

The boundary the whole design turns on is visible here. Everything that needs a Lean environment
(`collect`, `extract`, `highlight`) produces *data*; `build-site` is a pure function of that data
and the render-time flags, which is why it can be re-run as often as you like while iterating on a
page without re-importing the target project.
-/

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
    formalization? := data.formalization?
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
  let config := renderConfig data.externalDecls ctx.trusted cfg.showTrustedUpstream
  if cfg.perChapter then
    if cfg.searchMode == .full then
      IO.eprintln "--per-chapter requires --search names (or none): merging the full-text \
        inverted indexes of separate runs would mean re-indexing the whole library."
      return 1
    let code ← buildSitePerChapter cfg data groups ctx overviewBlocks versoArgs config
    if code != 0 then
      return code
  else
    -- Built here rather than above the branch: this is the whole document tree, the very
    -- allocation `--per-chapter` exists to avoid holding.
    let root := mkRootPart cfg data.rootPrefix groups data.decls ctx overviewBlocks
    let code ← manualMain root (options := versoArgs) (config := config)
    if code != 0 then
      return code
    -- After Verso has written the pages, and only on success: a half-rendered site is not one to
    -- rewrite in place.
    let (pages, saved) ← pruneSidebarSubTocsIn ((cfg.outputDir.getD ".") / "html-multi")
    if pages > 0 then
      IO.println s!"Pruned the sidebar's inherited sub-tables from {pages} pages, \
        saving {saved / 1048576} MB"
    -- Before hoisting, so that a rebuilt `searchIndex.js` is never one of the blocks hoisted out of
    -- the pages: it is referenced by `<script src>` and so was never inline to begin with, but the
    -- ordering makes that independent of how Verso chooses to emit it.
    applySearchMode cfg.searchMode (cfg.outputDir.getD ".")
  if cfg.hoistAssets then
    let (hoisted, freed, files) ←
      hoistInlineAssetsIn ((cfg.outputDir.getD ".") / "html-multi")
    if hoisted > 0 then
      IO.println s!"Hoisted {files} shared inline assets out of {hoisted} pages, \
        saving {freed / 1048576} MB"
  -- After hoisting, which is what decides whether the run-uniform head tail carries references or
  -- inline blocks; either way the global pages take a chapter page's verbatim.
  if cfg.perChapter then
    completeGlobalHeadTails ((cfg.outputDir.getD ".") / "html-multi") groups ctx
  return 0

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
  let n ← writeAllExtractions env data.rootPrefix (data.decls.map (·.toChallengeDecl)) projectDir
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
  let n ← Flat.writeAllFlatExtractions env data.rootPrefix (data.decls.map (·.toChallengeDecl))
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
  -- The one consumer that does not go through `loadCollectedData`, so it attaches the closures
  -- itself — same function, same single-call-site discipline (see `withClosures`).
  let data := (← collectData cfg projectDir ws rootPrefix env).withClosures
  if let some out := cfg.outputDir then
    let startMs ← IO.monoMsNow
    let n ← writeAllExtractions env data.rootPrefix (data.decls.map (·.toChallengeDecl)) projectDir
      (System.FilePath.mk out / "html-multi" / "extracted")
    IO.println s!"Wrote {n} standalone extraction files in {(← IO.monoMsNow) - startMs}ms"
  buildSiteFrom cfg data

/-- Main entry point: dispatches to the `collect`/`extract`/`build-site`/`all` subcommands. A
missing or unrecognized leading token defaults to `all`, so invocations from before this
split (bare flags, no subcommand) keep working unchanged.

The `@[no_expose]` this used to carry is gone with the module split: every module of the site now
sits in a plain `public section`, so nothing here is exposed by default and the attribute had no
effect left to have. -/
unsafe def mainImpl (args : List String) : IO UInt32 := do
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
