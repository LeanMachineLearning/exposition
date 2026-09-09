module

public import Referee.Website.Blocks
public import Lake.CLI.Main
public import Lake.Load.Workspace

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
# Importing the target project, and the data that comes out

The one side of the pipeline that needs a Lean environment. `loadProject` resolves the Lake
workspace and imports the root libraries; `collectData` runs the analysis over the resulting
environment and reads what the project root holds beside it — `README.md`, and `formalization.yaml`
when there is one — because `build-site` runs from `data.json` alone and never sees the project
directory.

`loadCollectedData` is the other end of that boundary: it reads the file back, refuses a version it
cannot read rather than surfacing whichever field happened to change, recomputes every closure from
the direct edges instead of trusting the stored ones, and checks the integrity of what survives the
round trip.
-/

/-- Runs an IO action in a temporary working directory. -/
private def withCurrentDir {α : Type} (dir : System.FilePath) (act : IO α) : IO α := do
  let cwd ← IO.Process.getCurrentDir
  IO.Process.setCurrentDir dir
  try
    act
  finally
    IO.Process.setCurrentDir cwd

/-- Loads the Lake workspace located at `projectDir`. -/
def loadWorkspaceAt (projectDir : System.FilePath) : IO Lake.Workspace := do
  let projectDir := projectDir.normalize
  let (elanInstall?, leanInstall?, lakeInstall?) ← Lake.findInstall?
  let cfg ← Lake.MonadError.runEIO <| Lake.mkLoadConfig { elanInstall?, leanInstall?, lakeInstall? }
  let ws? ← withCurrentDir projectDir <| Lake.loadWorkspace cfg |>.toBaseIO
  match ws? with
  | some ws => pure ws
  | none => throw <| IO.userError s!"failed to load Lake workspace at {projectDir}"

/-- Computes imports for root libraries, excluding configured libraries. -/
def importRoots (ws : Lake.Workspace) (excludeLibs : Array Name) : Array Import := Id.run do
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
unsafe def loadEnv (projectDir : System.FilePath) (ws : Lake.Workspace) (imports : Array Import) : IO Environment := do
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
unsafe def loadProject (cfg : Cli) :
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
def collectData (cfg : Cli) (projectDir : System.FilePath) (ws : Lake.Workspace)
    (rootPrefix : Name) (env : Environment) : IO CollectedData := do
  let packages := packageInfosOf ws rootPrefix
  -- The claim set first, because it decides the scope and the scope decides how much of the
  -- analysis below runs at all. Read even for a full build, where it drives the Claims page and
  -- nothing else.
  let formalizationEarly? ← readFormalization projectDir
  let wantsScope := cfg.claimsOnly || cfg.onlyDecl.isSome
  -- `--only DECL` is `--claims-only` with a claim set of exactly one declaration, and nothing else.
  -- Rendering a single page instead was the first design and it was wrong: the point of a claim's
  -- page is the dependency graph under it, and a graph whose nodes have no pages leaves the reader
  -- at a summary panel when what they need is the card — the statement in parts, the source, the
  -- proof. The closure is a couple of dozen declarations, so giving it pages costs nothing that
  -- matters.
  let explicitClaimNames := match cfg.onlyDecl with
    | some decl => #[decl]
    | none => cfg.claimNames
  -- The shallow scan for Comparator configs runs only when it can change the answer: a scoped
  -- build needs the claim list, and a project whose `formalization.yaml` already ranks its results
  -- has nothing a scan could add. So an ordinary full build of an ordinary project walks no
  -- directories and parses no JSON it did not parse before.
  let hasRankedResults := (formalizationEarly?.map (!·.mainResults.isEmpty)).getD false
  let claims? ← resolveClaimSet projectDir formalizationEarly? explicitClaimNames cfg.comparatorDir
    (allowScan := wantsScope || !hasRankedResults)
  let scopeSeeds? : Option (Array Name) ←
    if !wantsScope then pure none
    else match claims? with
      | some set => pure (some set.declarationNames)
      | none =>
        throw <| IO.userError "--claims-only needs the project to say which results are its main \
          ones, and this one does not: no formalization.yaml with status.main_results, no \
          Comparator config, and no --claim. Name them with --claim NAME (repeatable), or point \
          --comparator at the configs."
  if let some seeds := scopeSeeds? then
    if seeds.isEmpty then
      throw <| IO.userError "the claim set resolved to no declarations, so a scoped build would \
        render an empty site. Check the declaration names in formalization.yaml or the Comparator \
        configs."
  let tCollect ← IO.monoMsNow
  let collected ← collectDecls projectDir rootPrefix ws.root env packages scopeSeeds?
  let decls := collected.decls
  let thinDecls := collected.thin
  let libraryDeclCount := collected.libraryDeclCount
  let tDecls ← collectPhase "collectDecls" tCollect
  -- No `attachTransitiveDeps`/`attachDataTransitiveDeps` here: closures are derived on load by
  -- `CollectedData.withClosures`, never stored. Materializing them at collect time is what made
  -- `collect` unable to fit in memory at whole-Mathlib scale — see that function's docstring.
  let decls := decls |> dropUnsafeDeps |> attachReverseDeps
    |> attachSpecifiedBy |> attachCharacterizes
    |> attachUpstreamPackages
  let tAttach ← collectPhase "graph passes over the collected declarations" tDecls
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
  let tExcluded ← IO.monoMsNow
  -- From the dependency context, which built `exposed` by applying `shouldExpose` to every project
  -- constant. Asking the environment again here was a second full scan of it.
  let excludedNames := collected.excludedNames
  if let some out := cfg.outputDir then
    let logPath := System.FilePath.mk out / "excluded-declarations.txt"
    IO.FS.createDirAll out
    IO.FS.writeFile logPath <|
      String.intercalate "\n" (excludedNames.toList.map toString) ++ "\n"
  IO.println s!"Hidden (auto-generated/internal) declarations: {excludedNames.size}"
  let tHidden ← collectPhase "excluded declarations" tExcluded
  -- A name declared in several modules is collected once, attributed to the module the environment
  -- itself records for it (see `MeaningGraph.projectConstants`); the other copies are not shown,
  -- which is worth a note here rather than a silent gap on those modules' pages. Restricted to
  -- exposed names: a duplicated declaration duplicates its compiler helpers with it, and those
  -- would repeat the same fact as noise.
  let declNames : Std.HashSet Name := decls.foldl (fun acc d => acc.insert d.name) {}
  let dupes := duplicatedProjectConstants env rootPrefix
  let tDupes ← collectPhase "duplicatedProjectConstants (whole environment)" tHidden
  for (name, modules) in dupes do
    if declNames.contains name then
      IO.eprintln s!"note: {name} is declared in {modules.size} modules \
        ({String.intercalate ", " (modules.toList.map toString)}); the site shows only the copy \
        in {(moduleNameOf env name).map toString |>.getD "?"}"
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
  let tLoaded ← collectPhase "loadedPackagesOf (every imported module)" tDupes
  let (externalDecls, expandedPackages) ← externalDeclsOf env packages rootPrefix decls
  let _ ← collectPhase
    s!"upstream constants: {externalDecls.size} in {expandedPackages.size} expanded packages" tLoaded
  IO.println s!"Upstream packages: {touched.size} referenced by name, \
    {loadedPackages.size} with code loaded, {packages.size} in the workspace"
  let unattributed := (moduleIndexMap decls).toArray.filterMap fun (moduleName, _) =>
    if (modulePackageOf packages moduleName).isNone then some moduleName else none
  if !unattributed.isEmpty then
    IO.eprintln s!"warning: {unattributed.size} project modules match no package library root; \
      upstream attribution may be incomplete"
  let tBeforeOrder ← IO.monoMsNow
  let order ← moduleOrderMap projectDir rootPrefix
  let _ ← collectPhase "module import order" tBeforeOrder
  let moduleNames := moduleIndexMap decls |>.toArray.map Prod.fst
  let moduleDocs := moduleNames.map fun name => (name, moduleDocBlocks env name)
  let readmeText ← readFileIfExists (projectDir / "README.md")
  let formalization? := formalizationEarly?
  if let some form := formalization? then
    -- The check worth making here rather than at render time: the author is standing in their own
    -- project, and a main result naming a declaration that does not exist is nearly always a rename
    -- the metadata did not follow. The Claims page reports it too, but a warning reaches the person
    -- who can fix it.
    let known := decls.foldl (init := ({} : Std.HashSet Name)) fun acc decl => acc.insert decl.name
    let missing := form.mainResults.filter fun result => !known.contains result.declaration.toName
    IO.println s!"formalization.yaml: {form.mainResults.size} main results declared, \
      {form.mainResults.size - missing.size} matching an exposed declaration"
    if !missing.isEmpty then
      IO.eprintln s!"warning: formalization.yaml names {missing.size} main \
        {if missing.size == 1 then "result" else "results"} this project does not expose: \
        {String.intercalate ", " (missing.toList.take 5 |>.map (·.declaration))}"
  -- The claim set as a whole, which is wider than `formalization.yaml`: a Comparator config can
  -- name a declaration the metadata does not, and under `--claims-only` a stale name there costs a
  -- whole cone rather than one row.
  if let some set := claims? then
    let known : Std.HashSet Name := decls.foldl (fun acc d => acc.insert d.name) {}
    let thinKnown : Std.HashSet Name := thinDecls.foldl (fun acc d => acc.insert d.name) known
    IO.println s!"Claims: {set.claims.size} from {set.origin}, naming \
      {set.declarationNames.size} {if set.declarationNames.size == 1 then "declaration" else
        "declarations"}"
    let unresolved := set.declarationNames.filter (!thinKnown.contains ·)
    if !unresolved.isEmpty then
      IO.eprintln s!"warning: {unresolved.size} claimed \
        {if unresolved.size == 1 then "declaration is" else "declarations are"} not exposed by \
        this project: {String.intercalate ", " (unresolved.toList.take 5 |>.map toString)}"
  let scope : CollectionScope := match scopeSeeds? with
    | none => {}
    | some seeds =>
      { mode := if cfg.onlyDecl.isSome then "single" else "claims"
        seeds := seeds.map toString }
  if !scope.isFull then
    IO.println s!"Scope: {scope.label} — {decls.size} of {libraryDeclCount} exposed declarations \
      get a page, {thinDecls.size} kept as edges only, \
      {libraryDeclCount - decls.size - thinDecls.size} dropped"
  return {
    rootPrefix
    decls
    moduleOrder := order.toArray
    moduleDocs
    readmeText
    formalization?
    packages
    loadedPackages
    externalDecls
    expandedPackages
    scope
    claims?
    libraryDeclCount
    thinDecls
  }

/-- Current and peak resident set size in MB, read from `/proc/self/status`.

Linux-only and best-effort: anything unreadable yields zeros, because this exists to explain where a
long build spends itself and is never worth failing a build over. -/
def rssMB : IO (Nat × Nat) := do
  try
    let text ← IO.FS.readFile "/proc/self/status"
    let field (key : String) : Nat :=
      text.splitOn "\n" |>.findSome? (fun line =>
        if line.startsWith key then
          (line.dropWhile (!·.isDigit)).takeWhile (·.isDigit) |>.toNat?
        else none) |>.getD 0
    return (field "VmRSS:" / 1024, field "VmHWM:" / 1024)
  catch _ => return (0, 0)

/-- Prints how long a phase took and what memory stood at when it ended.

`build-site` at library scale runs for hours in a handful of phases with very different costs, and
without this the only way to tell which one is expensive is to guess. Peak is carried alongside
current because the phases that matter are the ones that allocate and release — a phase can double
the high-water mark and leave no trace in the resident size by the time it ends. -/
def phase (label : String) (startMs : Nat) : IO Nat := do
  let now ← IO.monoMsNow
  let (rss, peak) ← rssMB
  IO.println s!"  [{label}] {(now - startMs) / 1000}.{((now - startMs) % 1000) / 100}s  \
    rss {rss} MB  peak {peak} MB"
  return now

/-- Reads and decodes a `CollectedData` JSON file written by `collect`. -/
def loadCollectedData (path : String) (verify : Bool := true) : IO CollectedData := do
  let t0 ← IO.monoMsNow
  let text ← IO.FS.readFile path
  let t1 ← phase "read" t0
  let .ok json := Json.parse text
    | throw <| IO.userError s!"Failed to parse JSON from {path}"
  let t2 ← phase "parse json" t1
  -- Check the format version before decoding, so a stale file produced by an older `collect`
  -- reports what to do rather than surfacing whichever field happened to be added last. A range
  -- rather than an equality: version 11 differs from 12 only in storing closures this build
  -- recomputes and ignores anyway, so an old `--baseline` stays readable.
  let fileVersion := (json.getObjValAs? Nat "version").toOption.getD 0
  if fileVersion < minReadableDataVersion || fileVersion > collectedDataVersion then
    throw <| IO.userError s!"{path} is collected-data version {fileVersion}, but this build \
      reads versions {minReadableDataVersion}–{collectedDataVersion}. Re-run the `collect` \
      subcommand to regenerate it."
  match decodeCollectedData json with
  | .ok data =>
    let t3 ← phase "decode (resolve + fromJson)" t2
    -- Closures first, integrity second. The closures are recomputed here by the functions
    -- `MeaningGraph`'s `Proofs.lean` reasons about — never trusted from the file — and the
    -- checks then guard what still crosses the unproved round trip (the direct edges) and the
    -- recomputation's own wiring: see the `Integrity of the collected data` section in
    -- `Collect.lean`.
    let data := data.withClosures
    let t4 ← phase "withClosures" t3
    -- Skippable, because it is the one phase whose cost grows faster than the library: 0.5s at
    -- 16,876 declarations and 36.7s at 93,507, a 73× jump across a 5.5× step. What it guards is
    -- real — the `intern`/`resolve` round trip is the part of the pipeline `MeaningGraph`'s proofs
    -- do not reach — so it stays on by default and `--no-verify` is for re-rendering a file that
    -- has already been checked once.
    if verify then
      if let some report := data.integrityReport then
        throw <| IO.userError s!"{path}: {report}"
      let _ ← phase "integrity check" t4
    pure data
  | .error err => throw <| IO.userError s!"Failed to decode collected data from {path}: {err}"

end

end Referee
