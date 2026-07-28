module

public import Referee.Diff
-- The checks below are `#guard`s, which Lean elaborates into compile-time (`meta`) definitions, so
-- the declarations under test have to be imported at that level too.
meta import Referee.Diff

@[expose] public section

/-!
# Tests for `Referee.Diff`

The diff is a pure function of two `collect` outputs, which makes all of it unit-testable, and it
is worth testing in full because a wrong answer here is invisible on the site: a missed
invalidation reads exactly like a library that did not change.

What is checked:

* the classification of a single declaration — statement, body, proof-only, unchanged — and in
  particular that the theorem/definition asymmetry runs the right way round;
* **indirect invalidation**, the case the whole feature exists for: an untouched theorem whose
  statement rests on a changed definition;
* that a theorem's *proof* changing propagates to nothing, which is the claim the collapsed
  proof-only section of the page rests on;
* whitespace normalization, since without it every reformatting would be reported as a change;
* the token alignment used to render a changed statement;
* additions, removals, and the rename evidence.

Each check is a `#guard`, so any regression turns into a build error. Run with `lake build Test`.
-/

open Lean Std
open Referee

namespace Referee.Test.Diff

/-! ## Fixtures

`mkDecl` fills a `DeclInfo` with inert defaults so each case names only the fields the diff reads:
the elaborated type (`expandedSignature`), the body (`proofText?`, or `displaySignature` for a
definition), the kind, and the closure. -/

private def mkDecl (name : Name) (statement : String := "True") (body : String := "trivial")
    (kind : DeclKind := .theorem) (transDeps : Array Name := #[])
    (dependsOnSorry : Bool := false) (axioms : Array Name := #[])
    (specifiedBy : Array SpecLink := #[]) (isLemma : Bool := false) : DeclInfo := {
  name := name
  moduleName := `Test.Mod
  modulePath := "Mod"
  groupKey := "Mod"
  kind := kind
  isLemma := isLemma
  displaySignature := body
  expandedSignature := statement
  docBlocks := #[]
  -- Matches `Collect.proofTextFromSource`, which records a separate body only for the kinds that
  -- have one; a definition's body lives inside `displaySignature`.
  proofText? := if kind == .theorem || kind == .instance || kind == .opaque then some body else none
  source? := none
  deps := #[]
  typeDeps := #[]
  transDeps := transDeps
  dependsOnSorry := dependsOnSorry
  axioms := axioms
  specifiedBy := specifiedBy
}

private def mkData (decls : Array DeclInfo) : CollectedData := {
  rootPrefix := `Test
  decls := decls
  moduleOrder := #[]
  moduleDocs := #[]
  readmeText := none
}

/-- The change recorded for one declaration, for compact assertions. -/
private def kindOf (report : DiffReport) (name : Name) : Option ChangeKind :=
  (report.changes.find? (·.name == name)).map (·.kind)

private def run (old new : Array DeclInfo) : DiffReport :=
  Referee.diff (mkData old) (mkData new)

/-! ## Comparison keys -/

-- Reformatting is not a change. Without this every line break the author moves would put a
-- declaration on the re-reading queue.
#guard normalizeSpace "  foo   :\n  Bar  " == "foo : Bar"
#guard normalizeSpace "" == ""
#guard statementTokens "a  b\nc" == #["a", "b", "c"]
#guard statementTokens "   " == (#[] : Array String)

/-! ## One declaration at a time -/

-- A theorem whose elaborated type moved: the reading of it is void.
#guard kindOf (run #[mkDecl `T (statement := "P")] #[mkDecl `T (statement := "Q")]) `T
  == some .statementChanged

-- Same statement, different proof. The kernel rechecked it, so nothing follows.
#guard kindOf (run #[mkDecl `T (body := "by simp")] #[mkDecl `T (body := "by omega")]) `T
  == some .proofOnly

-- The asymmetry that the whole classification turns on: the *same* edit to a definition changes
-- what it means, because a definition's body is its meaning.
#guard kindOf
    (run #[mkDecl `D (kind := .definition) (body := "def D := 1")]
         #[mkDecl `D (kind := .definition) (body := "def D := 2")]) `D
  == some .bodyChanged

-- Reformatting alone is not a change, on either side of that asymmetry.
#guard kindOf (run #[mkDecl `T (body := "by  simp")] #[mkDecl `T (body := "by\n simp")]) `T
  == some .unchanged

#guard kindOf (run #[] #[mkDecl `N]) `N == some .added

/-! ## Indirect invalidation

The case the feature exists for. `T` is untouched — same statement, same proof — but its statement
rests on `D`, and `D` now means something else. A textual diff of the repository shows nothing at
all here. -/

private def before : Array DeclInfo := #[
  mkDecl `D (kind := .definition) (body := "def D := 1"),
  mkDecl `T (statement := "P D") (transDeps := #[`D]),
  mkDecl `U (statement := "P") (transDeps := #[])
]

private def after : Array DeclInfo := #[
  mkDecl `D (kind := .definition) (body := "def D := 2"),
  mkDecl `T (statement := "P D") (transDeps := #[`D]),
  mkDecl `U (statement := "P") (transDeps := #[])
]

#guard kindOf (run before after) `T == some .indirect
-- And nothing spills onto a declaration that does not rest on `D`.
#guard kindOf (run before after) `U == some .unchanged

-- The row says what moved underneath it, since a bare flag sends the reader hunting.
#guard ((run before after).changes.find? (·.name == `T)).map (·.causes) == some #[`D]

/-! ### Proof changes do not propagate

`T`'s proof changed and `V`'s statement rests on `T`. `V` is unaffected: an upstream proof is not
something a reader has to take on faith, which is the same argument the trust page makes about
upstream packages. -/

private def proofBefore : Array DeclInfo := #[
  mkDecl `T (statement := "P") (body := "by simp"),
  mkDecl `V (statement := "Q T") (transDeps := #[`T])
]

private def proofAfter : Array DeclInfo := #[
  mkDecl `T (statement := "P") (body := "by omega"),
  mkDecl `V (statement := "Q T") (transDeps := #[`T])
]

#guard kindOf (run proofBefore proofAfter) `V == some .unchanged
#guard (run proofBefore proofAfter).needingReaudit.isEmpty

/-! ## Trust deltas

Independent of the statement: a declaration can acquire a `sorry` without a character of it moving,
because the gap is in something it rests on. -/

private def sorryReport : DiffReport :=
  run #[mkDecl `T] #[mkDecl `T (dependsOnSorry := true)]

#guard (sorryReport.changes.find? (·.name == `T)).map (·.gainedSorry) == some true
-- The declaration itself is unchanged, and the page still has to report it.
#guard kindOf sorryReport `T == some .unchanged
#guard (sorryReport.changes.find? (·.name == `T)).map (·.isNoteworthy) == some true
#guard !sorryReport.isEmpty

#guard ((run #[mkDecl `T (axioms := #[`propext])]
             #[mkDecl `T (axioms := #[`propext, `Foo.ax])]).changes.find? (·.name == `T)).map
    (·.gainedAxioms) == some #[`Foo.ax]

-- A definition losing its specification is a gap that appears with nothing else moving, and it is
-- invisible anywhere else on the site.
#guard ((run #[mkDecl `D (kind := .definition) (specifiedBy := #[⟨`T, ""⟩])]
             #[mkDecl `D (kind := .definition)]).changes.find? (·.name == `D)).map
    (·.lostSpec) == some true

/-! ## Additions and removals -/

private def removalReport : DiffReport :=
  run #[mkDecl `Gone (statement := "P"), mkDecl `L (isLemma := true) (statement := "Q")]
      #[mkDecl `Fresh (statement := "P")]

#guard removalReport.removed.map (·.name) == #[`Gone, `L]
-- A withdrawn *claim* is the removal a referee reads first, so `theorem` and `lemma` are
-- distinguished here exactly as the Claims page distinguishes them.
#guard removalReport.removed.map (·.wasClaim) == #[true, false]
-- Offered as evidence, not as an inferred rename: the statements coincide, and that is all the
-- tool knows.
#guard removalReport.renamed == #[(`Gone, `Fresh)]

#guard (run #[mkDecl `T] #[mkDecl `T]).isEmpty
#guard (run #[mkDecl `T] #[mkDecl `T]).oldCount == 1

/-! ## Rendering a changed statement

The alignment is what turns two nearly identical lines of Lean into a visible change. -/

private def tokenKinds (old new : String) : Array String :=
  (statementDiff old new).tokens.map (·.kind)

private def tokenTexts (old new : String) (kind : String) : Array String :=
  ((statementDiff old new).tokens.filter (·.kind == kind)).map (·.text)

-- One token replaced in the middle: everything else stays aligned.
#guard tokenKinds "f : A → B" "f : C → B" == #["same", "same", "del", "ins", "same", "same"]
#guard tokenTexts "f : A → B" "f : C → B" "del" == #["A"]
#guard tokenTexts "f : A → B" "f : C → B" "ins" == #["C"]

-- A pure insertion keeps every original token marked `same`, so the reader sees what arrived
-- rather than a wholesale rewrite.
#guard tokenTexts "f : A" "f : A → B" "ins" == #["→", "B"]
#guard tokenTexts "f : A" "f : A → B" "del" == (#[] : Array String)

#guard (statementDiff "a" "a").tokens.map (·.kind) == #["same"]
#guard !(statementDiff "a" "b").coarse

end Referee.Test.Diff
