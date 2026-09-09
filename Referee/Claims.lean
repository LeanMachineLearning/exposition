module

public import Lean
public import Referee.Formalization

@[expose] public section

/-!
# What a project puts forward as its main results

Two documents name them, and a project may ship either, both, or neither.

`formalization.yaml` names them in prose the author wrote (`Referee.Formalization`). A
[Comparator](https://github.com/leanprover/comparator) setup names them by *challenging* them: one
config per result, pairing a challenge module that restates the theorem with the solution module
that proves it, which a separate tool then certifies. The two overlap — the registry's schema has a
`comparator_config` field precisely so an entry can point at its own certification — and neither
subsumes the other: a repository can carry challenges without the metadata file, and the metadata
file can name a result nobody has challenged.

This module reads both into one list, which is what the Claims page renders and what
`--claims-only` scopes the build to.

## Why a config is a claim, and not each theorem in it

A Comparator config's `theorem_names` is not a list of headline results. It is the list of
statements that must be certified *together* for this one challenge to mean anything: the headline
plus, routinely, an auxiliary target a definition in the statement's closure needs. The corpus
settles it. In `colt-2026-83`, thirteen of seventeen configs pair a headline with
`measurable_sigma_of_measurable_comp_mk`. In `ten-proofs`, `A_SpherePacking.json` names four
theorems and the one its own `formalization.yaml` calls the main result is the **fourth**.

So "the first name" picks the wrong result on a real project, and "every name, flattened" promotes
plumbing to a headline. One claim per config, carrying every theorem it names, is the reading that
needs no guess — and it is also the true one, because the config is the unit that gets certified.

Where `formalization.yaml` *does* rank them, its ranking wins: the entry's `declaration` becomes the
headline and the config's other names become additional targets under it.

## Detection by shape

A Comparator config is recognized by having `challenge_module`, `solution_module` and
`theorem_names`, not by living in a directory with a particular name. The corpus writes them to
`comparator/` (`alpha-rar`, `colt-2026-83`) and to `ComparatorChallenges/` (`ten-proofs`); a
convention that covers two of two is not a convention. Reading the shape costs one `Json.parse` per
candidate file and cannot be wrong about a file that is not one.

Unlike `Referee.Formalization`, this reader takes on no risk worth arguing about: `Lean.Json` is
already in the environment, and a malformed config is an error rather than a silent misreading.
-/

open Lean

namespace Referee

/-! ## A Comparator config -/

/-- One [Comparator](https://github.com/leanprover/comparator) config: a challenge module restating
some theorems, the solution module that proves them, and the axioms the comparison permits. -/
structure ComparatorConfig where
  /-- The config's path as the project writes it, relative to the project root. Shown on the Claims
  page, and the key `formalization.yaml`'s `comparator_config` is matched against. -/
  path : String := ""
  challengeModule : String := ""
  solutionModule : String := ""
  /-- Every theorem this challenge certifies, in the config's order. The first is *not* privileged;
  see the module docstring. -/
  theoremNames : Array String := #[]
  permittedAxioms : Array String := #[]
  /-- Whether the config asks for the second, independently implemented kernel. Rendered because it
  is the one field that strengthens what the certification claims. -/
  enableNanoda : Bool := false
deriving Repr, ToJson, FromJson, Inhabited, BEq

/-- The strings of a JSON array field, dropping any element that is not a string. -/
def jsonStrs (j : Json) (key : String) : Array String :=
  match j.getObjVal? key with
  | .ok (.arr items) => items.filterMap fun item => item.getStr?.toOption
  | _ => #[]

/-- The string at `key`, or `""`. -/
def jsonStr (j : Json) (key : String) : String :=
  (j.getObjValAs? String key).toOption.getD ""

/-- Reads a Comparator config, or `none` when this JSON document is not one.

The three required fields are the detection rule, so this doubles as the test applied to every
candidate file: a `lake-manifest.json` sitting in a scanned directory returns `none` rather than an
empty config. `theorem_names` must be non-empty as well — a config naming nothing certifies nothing
and would contribute a claim with no declarations. -/
def ComparatorConfig.ofJson? (path : String) (j : Json) : Option ComparatorConfig := do
  let challengeModule := jsonStr j "challenge_module"
  let solutionModule := jsonStr j "solution_module"
  let theoremNames := jsonStrs j "theorem_names"
  guard (!challengeModule.isEmpty && !solutionModule.isEmpty && !theoremNames.isEmpty)
  pure {
    path
    challengeModule
    solutionModule
    theoremNames
    permittedAxioms := jsonStrs j "permitted_axioms"
    enableNanoda := (j.getObjValAs? Bool "enable_nanoda").toOption.getD false
  }

/-- Reads a config from disk, `none` for a file that is missing, unparseable, or not a config.

`path` is relative to `projectDir` and is kept verbatim on the result, because it is what
`formalization.yaml` writes and what the page shows. -/
def readComparatorConfig? (projectDir : System.FilePath) (path : String) :
    IO (Option ComparatorConfig) := do
  let full := projectDir / path
  if !(← full.pathExists) then
    return none
  let raw ← try IO.FS.readFile full catch _ => pure ""
  if raw.isEmpty then
    return none
  match Json.parse raw with
  | .error _ => return none
  | .ok j => return ComparatorConfig.ofJson? path j

/-! ## Finding the configs

Three sources, tried in order and unioned by path: what `formalization.yaml` points at, what
`--comparator` names, and — only when neither produced anything — a shallow scan.

The scan is deliberately shallow. It looks at the project root's immediate subdirectories and at the
root itself, and at no depth below that, because a Comparator setup is a top-level fixture of a
repository and a deep walk would spend the build wandering `.lake`. -/

/-- Directories the scan never descends into. -/
def skippedScanDirs : Array String :=
  #[".lake", ".git", ".github", "build", "node_modules", ".venv", "_out", "blueprint"]

/-- Every `*.json` in `dir` that reads as a Comparator config, by name. -/
def configsInDir (projectDir dir : System.FilePath) (relPrefix : String) :
    IO (Array ComparatorConfig) := do
  if !(← dir.pathExists) || !(← dir.isDir) then
    return #[]
  let mut out := #[]
  let entries ← try dir.readDir catch _ => pure #[]
  for entry in entries.qsort (fun a b => a.fileName < b.fileName) do
    if entry.path.extension != some "json" then
      continue
    let rel := if relPrefix.isEmpty then entry.fileName else s!"{relPrefix}/{entry.fileName}"
    if let some cfg ← readComparatorConfig? projectDir rel then
      out := out.push cfg
  return out

/-- The Comparator configs a project ships.

`fromMetadata` are the paths `formalization.yaml` entries point at, which are authoritative when
present: a project that names its configs has said which ones count, and scanning for more could
only add ones it deliberately left out. `explicitDir?` is `--comparator`. The scan runs only when
both come up empty, so a project with metadata never pays for it. -/
def discoverComparatorConfigs (projectDir : System.FilePath) (fromMetadata : Array String)
    (explicitDir? : Option String) (allowScan : Bool := true) : IO (Array ComparatorConfig) := do
  let mut byPath : Std.HashMap String ComparatorConfig := {}
  let mut order : Array String := #[]
  let add (byPath : Std.HashMap String ComparatorConfig) (order : Array String)
      (cfg : ComparatorConfig) : Std.HashMap String ComparatorConfig × Array String :=
    if byPath.contains cfg.path then (byPath, order)
    else (byPath.insert cfg.path cfg, order.push cfg.path)
  for path in fromMetadata do
    if let some cfg ← readComparatorConfig? projectDir path then
      (byPath, order) := add byPath order cfg
  if let some dir := explicitDir? then
    for cfg in ← configsInDir projectDir (projectDir / dir) dir do
      (byPath, order) := add byPath order cfg
  if byPath.isEmpty && allowScan then
    -- The shallow scan, and only now. Root first, then each subdirectory in name order, so the
    -- result does not depend on the order the filesystem happens to enumerate.
    for cfg in ← configsInDir projectDir projectDir "" do
      (byPath, order) := add byPath order cfg
    let entries ← try projectDir.readDir catch _ => pure #[]
    for entry in entries.qsort (fun a b => a.fileName < b.fileName) do
      if skippedScanDirs.contains entry.fileName || entry.fileName.startsWith "." then
        continue
      if !(← entry.path.isDir) then
        continue
      for cfg in ← configsInDir projectDir entry.path entry.fileName do
        (byPath, order) := add byPath order cfg
  return order.filterMap byPath.get?

/-! ## The claim set -/

/-- Where a claim came from, as a word the page can print.

A `String` rather than an inductive for the reason `CharPartLink.role` is one: it is written into
`data.json`, read back, and rendered, and it never gets matched on for control flow. -/
def ClaimSource.formalization : String := "formalization.yaml"
def ClaimSource.comparator : String := "comparator"
def ClaimSource.explicit : String := "command line"

/-- One result the project puts forward.

`headline` is the declaration the claim is *about*, and is empty exactly when nothing ranked the
config's theorems — see the module docstring. `additional` is everything else the claim covers:
a config's other targets, which are certified with the headline and belong under it rather than
beside it. -/
structure Claim where
  /-- What to call the claim on the page. The headline's declaration name where there is one, the
  config's file stem otherwise. -/
  label : String := ""
  /-- The declaration this claim is about, or `""` when the sources gave no ranking. -/
  headline : String := ""
  /-- The other declarations this claim covers, in source order. -/
  additional : Array String := #[]
  /-- One of the `ClaimSource` words. -/
  source : String := ""
  /-- The Comparator config certifying this claim, when there is one. -/
  comparator? : Option ComparatorConfig := none
  /-- The `formalization.yaml` entry this came from, when it came from there. Carries the scope
  note, the literature dependencies, and the file the metadata claims the result lives in. -/
  mainResult? : Option MainResult := none
deriving Repr, ToJson, FromJson, Inhabited

/-- Every declaration this claim covers, headline first. -/
def Claim.declarations (claim : Claim) : Array String :=
  (if claim.headline.isEmpty then #[] else #[claim.headline]) ++ claim.additional

/-- Whether a Comparator config certifies this claim. -/
def Claim.isCertified (claim : Claim) : Bool := claim.comparator?.isSome

/-- The results a project puts forward, in the order its sources give them. -/
structure ClaimSet where
  claims : Array Claim := #[]
  /-- Which documents the list was read from, for the console line and the page's provenance
  sentence. Empty when there are no claims. -/
  origin : String := ""
deriving Repr, ToJson, FromJson, Inhabited

/-- Every declaration named by any claim, deduplicated, in claim order. -/
def ClaimSet.declarationNames (set : ClaimSet) : Array Name := Id.run do
  let mut seen : Std.HashSet Name := {}
  let mut out : Array Name := #[]
  for claim in set.claims do
    for decl in claim.declarations do
      let name := decl.toName
      unless seen.contains name do
        seen := seen.insert name
        out := out.push name
  return out

/-- Whether the set has anything to scope a build to. -/
def ClaimSet.isEmpty (set : ClaimSet) : Bool := set.claims.isEmpty

/-! ## Resolution

Three sources, and the order between them is the whole of the policy: an explicit list is an
instruction and wins; `formalization.yaml` is the author's own ranking and wins over an unranked
config; a config on its own is the last thing that can name a result, and it names all of them. -/

/-- Builds the claim set from an explicit list of declarations.

Each gets a claim of its own, in the order given, with no additional targets — the caller named
exactly what it wanted. Configs are still attached where one certifies the named declaration, since
that is a fact about the project rather than about the request. -/
def explicitClaims (names : Array Name) (configs : Array ComparatorConfig) : Array Claim :=
  names.map fun name =>
    let str := name.toString
    { label := str
      headline := str
      source := ClaimSource.explicit
      comparator? := configs.find? (·.theoremNames.contains str) }

/-- Builds the claim set from `status.main_results`, attaching each entry's Comparator config.

The config's other `theorem_names` become the claim's additional targets. They are genuinely part of
the claim — the certification covers them together, and dropping them would leave the scope short of
declarations the challenge depends on — but they are not headlines, because the file already said
which declaration is. -/
def formalizationClaims (form : Formalization) (configs : Array ComparatorConfig) :
    Array Claim :=
  form.mainResults.map fun result =>
    let config? :=
      if result.comparatorConfig.isEmpty then
        configs.find? (·.theoremNames.contains result.declaration)
      else
        configs.find? (·.path == result.comparatorConfig)
    let additional := match config? with
      | none => #[]
      | some cfg => cfg.theoremNames.filter (· != result.declaration)
    { label := result.declaration
      headline := result.declaration
      additional
      source := ClaimSource.formalization
      comparator? := config?
      mainResult? := some result }

/-- Builds the claim set from Comparator configs alone: one claim per config, every theorem it
names, no headline. See the module docstring for why there is no headline to pick. -/
def comparatorClaims (configs : Array ComparatorConfig) : Array Claim :=
  configs.map fun cfg =>
    -- The file stem, which is what the project's own README tabulates its challenges by.
    let stem := ((System.FilePath.mk cfg.path).fileStem).getD cfg.path
    { label := stem
      additional := cfg.theoremNames
      source := ClaimSource.comparator
      comparator? := some cfg }

/-- Resolves what the project puts forward, from whichever of the three sources it has.

Returns `none` when nothing names a main result, which is the gate both modes are built behind: a
project that has said nothing about which of its results matter has not made the claim these modes
report, and inventing one for it would be worse than declining.

`allowScan := false` suppresses the directory scan, leaving only the configs the metadata points at
and `--comparator`. A full build of a project that already has `formalization.yaml` passes it, so
that adding these modes costs an ordinary build no directory walk and no speculative `Json.parse` it
did not do before. -/
def resolveClaimSet (projectDir : System.FilePath) (form? : Option Formalization)
    (explicit : Array Name) (comparatorDir? : Option String) (allowScan : Bool := true) :
    IO (Option ClaimSet) := do
  let fromMetadata := match form? with
    | none => #[]
    | some form => (form.mainResults.map (·.comparatorConfig)).filter (!·.isEmpty)
  let configs ← discoverComparatorConfigs projectDir fromMetadata comparatorDir? allowScan
  let describe (what : String) : String :=
    if configs.isEmpty then what
    else s!"{what} and {configs.size} Comparator \
      {if configs.size == 1 then "config" else "configs"}"
  if !explicit.isEmpty then
    return some { claims := explicitClaims explicit configs, origin := describe "the command line" }
  if let some form := form? then
    if !form.mainResults.isEmpty then
      return some {
        claims := formalizationClaims form configs
        origin := describe "formalization.yaml"
      }
  if !configs.isEmpty then
    return some {
      claims := comparatorClaims configs
      origin := s!"{configs.size} Comparator \
        {if configs.size == 1 then "config" else "configs"}"
    }
  return none

end Referee
