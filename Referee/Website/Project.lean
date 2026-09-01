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
  let decls ← collectDecls projectDir rootPrefix ws.root env packages
  -- No `attachTransitiveDeps`/`attachDataTransitiveDeps` here: closures are derived on load by
  -- `CollectedData.withClosures`, never stored. Materializing them at collect time is what made
  -- `collect` unable to fit in memory at whole-Mathlib scale — see that function's docstring.
  let decls := decls |> dropUnsafeDeps |> attachReverseDeps
    |> attachSpecifiedBy |> attachCharacterizes
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
  -- A name declared in several modules is collected once, attributed to the module the environment
  -- itself records for it (see `MeaningGraph.projectConstants`); the other copies are not shown,
  -- which is worth a note here rather than a silent gap on those modules' pages. Restricted to
  -- exposed names: a duplicated declaration duplicates its compiler helpers with it, and those
  -- would repeat the same fact as noise.
  let declNames : Std.HashSet Name := decls.foldl (fun acc d => acc.insert d.name) {}
  for (name, modules) in duplicatedProjectConstants env rootPrefix do
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
  let formalization? ← readFormalization projectDir
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
  }

/-- Reads and decodes a `CollectedData` JSON file written by `collect`. -/
def loadCollectedData (path : String) : IO CollectedData := do
  let text ← IO.FS.readFile path
  let .ok json := Json.parse text
    | throw <| IO.userError s!"Failed to parse JSON from {path}"
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
    -- Closures first, integrity second. The closures are recomputed here by the functions
    -- `MeaningGraph`'s `Proofs.lean` reasons about — never trusted from the file — and the
    -- checks then guard what still crosses the unproved round trip (the direct edges) and the
    -- recomputation's own wiring: see the `Integrity of the collected data` section in
    -- `Collect.lean`.
    let data := data.withClosures
    if let some report := data.integrityReport then
      throw <| IO.userError s!"{path}: {report}"
    pure data
  | .error err => throw <| IO.userError s!"Failed to decode collected data from {path}: {err}"

end

end Referee
