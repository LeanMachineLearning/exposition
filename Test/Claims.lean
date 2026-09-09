module

public import Referee.Claims
-- The checks below are `#guard`s, which Lean elaborates into compile-time (`meta`) definitions, so
-- the declarations under test have to be imported at that level too.
meta import Referee.Claims

@[expose] public section

/-!
# Tests for `Referee.Claims`

Reading a Comparator setup, and merging it with `formalization.yaml`. The failure modes here are the
same silent kind `Test/Formalization.lean` exists for: a claim set that resolves to the wrong
declarations does not throw, it scopes the whole build to the wrong cone and renders a site that
looks fine.

The cases are taken from the three projects that actually ship this metadata, because the shapes
that break the obvious rules are all in them and none of them is hypothetical:

* `ten-proofs`' `A_SpherePacking.json` names four theorems and the one its own `formalization.yaml`
  calls the main result is the **fourth** — which is what rules out "the headline is the first
  `theorem_names` entry";
* thirteen of `colt-2026-83`'s seventeen configs pair a headline with an auxiliary target, which is
  what rules out promoting every name to a claim of its own;
* `alpha-rar`'s `aRTSFE_sparse_rate.json` names a theorem whose short name does not match the
  config's file stem, which rules out deriving the declaration from the filename;
* a config whose `comparator_config` path resolves to nothing, which must leave the claim standing
  rather than drop it.

Run with `lake build Test`.
-/

open Lean
open Referee

namespace Referee.Test.Claims

/-! ## Detection by shape

A JSON document is a Comparator config exactly when it carries the three fields the tool needs. That
is the whole test applied to every candidate file, so the negative cases matter as much as the
positive one: a `lake-manifest.json` in a scanned directory must not read as a config with empty
fields. -/

/-- The parse of `s` as a config, ignoring the path. -/
def cfg? (s : String) : Option ComparatorConfig :=
  (Json.parse s).toOption.bind (ComparatorConfig.ofJson? "c.json")

/-- `colt-2026-83/comparator/gw_le_card.json`, verbatim. -/
def gwLeCardJson : String :=
  "{\"challenge_module\": \"Challenge_gw_le_card\", \"solution_module\": \"Solution\", \"theorem_names\": [\"Maiti2026Power.gw_le_card\"], \"permitted_axioms\": [\"propext\", \"Classical.choice\", \"Quot.sound\"]}"

#guard (cfg? gwLeCardJson).map (·.theoremNames) == some #["Maiti2026Power.gw_le_card"]
#guard (cfg? gwLeCardJson).map (·.challengeModule) == some "Challenge_gw_le_card"
#guard (cfg? gwLeCardJson).map (·.permittedAxioms.size) == some 3
-- The path is the caller's, not the document's: it is what `formalization.yaml` writes and what the
-- page shows, and nothing inside a config says where the config lives.
#guard (cfg? gwLeCardJson).map (·.path) == some "c.json"

#guard (cfg? "{\"challenge_module\": \"C\", \"solution_module\": \"S\", \"theorem_names\": [\"A.b\"], \"enable_nanoda\": true}").map (·.enableNanoda) == some true

-- Absent `enable_nanoda` is `false`, not an error: it is the stronger claim, so its default has to
-- be the weaker reading.
#guard (cfg? "{\"challenge_module\": \"C\", \"solution_module\": \"S\", \"theorem_names\": [\"A.b\"]}").map (·.enableNanoda) == some false

-- Not configs. The first is a `lake-manifest.json`-shaped document, the second a config that
-- certifies nothing — which would contribute a claim naming no declaration at all.
#guard cfg? "{\"version\": \"1.1.0\", \"packages\": []}" == none
#guard cfg? "{\"challenge_module\": \"C\", \"solution_module\": \"S\", \"theorem_names\": []}" == none
#guard cfg? "{\"challenge_module\": \"C\", \"theorem_names\": [\"A.b\"]}" == none
#guard cfg? "not json at all" == none

-- A non-string in `theorem_names` is dropped rather than failing the file: the rest of the list is
-- still the author's statement of what is certified.
#guard (cfg? "{\"challenge_module\": \"C\", \"solution_module\": \"S\", \"theorem_names\": [\"A.b\", 7, \"A.c\"]}").map (·.theoremNames) == some #["A.b", "A.c"]

/-! ## One claim per config, every theorem under it

The rule the corpus forces. `A_SpherePacking` is the case that decides it. -/

def spherePacking : ComparatorConfig where
  path := "ComparatorChallenges/A_SpherePacking.json"
  challengeModule := "ComparatorChallenges.A_SpherePacking"
  solutionModule := "SpherePacking"
  theoremNames := #["PackingBounds.FullMain.exact_limit",
    "PackingBounds.FullMain.exact_binary_exponent",
    "PackingBounds.PackingBridge.sphere_packing_sharp_asymptotic_upper",
    "PackingBounds.sharpFullCohnElkiesManuscriptConclusions"]

def coltGw : ComparatorConfig where
  path := "comparator/blockBallSet_le_budget_of_isPAC.json"
  challengeModule := "Challenge_blockBallSet_le_budget_of_isPAC"
  solutionModule := "Solution"
  theoremNames := #["Maiti2026Power.blockBallSet_le_budget_of_isPAC",
    "measurable_sigma_of_measurable_comp_mk"]

/-- The claim set a Comparator-only project resolves to, without touching the filesystem. -/
def fromConfigs (configs : Array ComparatorConfig) : ClaimSet :=
  { claims := comparatorClaims configs, origin := "test" }

-- One claim per config, not one per theorem: four names, one claim.
#guard (fromConfigs #[spherePacking]).claims.size == 1
#guard (fromConfigs #[spherePacking]).declarationNames.size == 4
-- No headline, because nothing here ranked them. Guessing "the first" would name
-- `exact_limit`, and this project's own metadata says the result is the fourth.
#guard ((fromConfigs #[spherePacking]).claims[0]!).headline == ""
-- The label is the file stem, which is what the project's README tabulates its challenges by.
#guard ((fromConfigs #[spherePacking]).claims[0]!).label == "A_SpherePacking"
#guard ((fromConfigs #[spherePacking]).claims[0]!).isCertified

-- Two configs sharing an auxiliary target contribute it once to the scope, not twice.
#guard (fromConfigs #[coltGw, { coltGw with
  path := "comparator/blockBallSet_le_budget_of_isFixedDesign_of_isPAC.json"
  theoremNames := #["Maiti2026Power.blockBallSet_le_budget_of_isFixedDesign_of_isPAC",
    "measurable_sigma_of_measurable_comp_mk"] }]).declarationNames.size == 3

/-! ## `formalization.yaml` ranks them, and its ranking wins

The whole point of reading both documents: the file says which of the config's theorems is the
result, and the others become additional targets under it rather than claims beside it. -/

def tenProofsForm : Formalization where
  mainResults := #[{
    declaration := "PackingBounds.sharpFullCohnElkiesManuscriptConclusions"
    file := "SpherePacking.lean"
    comparatorConfig := "ComparatorChallenges/A_SpherePacking.json"
  }]

def tenProofsClaims : Array Claim := formalizationClaims tenProofsForm #[spherePacking]

#guard tenProofsClaims.size == 1
-- The fourth name, because the file said so.
#guard (tenProofsClaims[0]!).headline == "PackingBounds.sharpFullCohnElkiesManuscriptConclusions"
#guard (tenProofsClaims[0]!).source == ClaimSource.formalization
-- The other three are still covered — the certification is joint, and a scope short of them would
-- be short of declarations the challenge rests on — but they are not headlines.
#guard (tenProofsClaims[0]!).additional.size == 3
#guard !((tenProofsClaims[0]!).additional.contains
  "PackingBounds.sharpFullCohnElkiesManuscriptConclusions")
#guard (tenProofsClaims[0]!).declarations.size == 4
#guard ((tenProofsClaims[0]!).comparator?.map (·.path))
  == some "ComparatorChallenges/A_SpherePacking.json"

-- A `comparator_config` naming a file that is not there leaves the claim standing with no
-- certification. The metadata is still the author's statement of what the result is; only the
-- machine-checked half is missing, and dropping the claim would hide the result rather than the gap.
#guard ((formalizationClaims { tenProofsForm with
  mainResults := #[{ tenProofsForm.mainResults[0]! with
    comparatorConfig := "ComparatorChallenges/gone.json" }] } #[spherePacking])[0]!).isCertified
  == false

-- With no `comparator_config` field, the config is still matched by the declaration it names —
-- which is how a project that ships challenges but has not linked them keeps the certification.
#guard ((formalizationClaims { tenProofsForm with
  mainResults := #[{ tenProofsForm.mainResults[0]! with comparatorConfig := "" }] }
  #[spherePacking])[0]!).isCertified

/-! ## An explicit list

`--claim` and `--only` are instructions, so they name exactly what was asked for and nothing else —
but a config certifying one of them is a fact about the project, not about the request, and is still
attached. -/

#guard (explicitClaims #[`Maiti2026Power.blockBallSet_le_budget_of_isPAC] #[coltGw])[0]!.headline
  == "Maiti2026Power.blockBallSet_le_budget_of_isPAC"
-- No additional targets: the caller named one declaration and gets one.
#guard (explicitClaims #[`Maiti2026Power.blockBallSet_le_budget_of_isPAC] #[coltGw])[0]!.additional
  == #[]
#guard (explicitClaims #[`Maiti2026Power.blockBallSet_le_budget_of_isPAC] #[coltGw])[0]!.isCertified
#guard (explicitClaims #[`Nothing.challenged] #[coltGw])[0]!.isCertified == false
#guard (explicitClaims #[`A.b, `A.c] #[]).size == 2

/-! ## The declaration list the scope is seeded from -/

-- Headline first within a claim, claims in order, deduplicated across them.
#guard (fromConfigs #[coltGw]).declarationNames
  == #[`Maiti2026Power.blockBallSet_le_budget_of_isPAC, `measurable_sigma_of_measurable_comp_mk]
#guard ({ claims := tenProofsClaims, origin := "test" } : ClaimSet).declarationNames[0]!
  == `PackingBounds.sharpFullCohnElkiesManuscriptConclusions
#guard ({} : ClaimSet).isEmpty
#guard (fromConfigs #[]).isEmpty

end Referee.Test.Claims
