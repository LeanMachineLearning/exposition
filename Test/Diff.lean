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
* additions, removals, and the rename evidence;
* the **semantic-hash path** — that a hash decides whether the meaning moved and the text only
  where, that a repretty-printed library comes out unchanged, and that the fallback to text is per
  declaration rather than all-or-nothing.

Each check is a `#guard`, so any regression turns into a build error. Run with `lake build Test`.
-/

open Lean Std
open Referee
open ChallengeGen

namespace Referee.Test.Diff

/-! ## Fixtures

`mkDecl` fills a `DeclInfo` with inert defaults so each case names only the fields the diff reads:
the elaborated type (`expandedSignature`), the body (`proofText?`, or `displaySignature` for a
definition), the kind, and the closure. -/

private def mkDecl (name : Name) (statement : String := "True") (body : String := "trivial")
    (kind : DeclKind := .theorem) (transDeps : Array Name := #[])
    (dependsOnSorry : Bool := false) (axioms : Array Name := #[])
    (specifiedBy : Array SpecLink := #[]) (isLemma : Bool := false)
    (semanticHash? : Option String := none) (proofIrrelHash? : Option String := none) : DeclInfo := {
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
  -- Both closures, from the one parameter. These fixtures exercise *propagation*, which walks the
  -- meaning closure (`dataTransDeps`); `transDeps` is set alongside it because nothing here means to
  -- distinguish the two, and leaving it empty would make the fixture describe a declaration whose
  -- extraction closure contradicts its meaning closure.
  transDeps := transDeps
  dataTransDeps := transDeps
  dependsOnSorry := dependsOnSorry
  axioms := axioms
  specifiedBy := specifiedBy
  semanticHash? := semanticHash?
  proofIrrelHash? := proofIrrelHash?
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

/-! ## The semantic-hash path

Everything above compares text. With `collect --hashes`, the same classification is made on
structural hashes of the elaborated term instead, and the text is consulted only to say *where* a
change the hash already found actually happened.

The fixtures below name hashes as short strings; nothing in the diff reads them as anything but
opaque tokens compared for equality, so `"h1"` stands in for a 64-bit hash without loss. -/

/-- A declaration carrying both hashes. `meaning` is the proof-irrelevant hash and `full` the
proof-relevant one; where a case does not care about proofs, both move together. -/
private def mkHashed (name : Name) (meaning : String) (full : String := meaning)
    (statement : String := "True") (body : String := "trivial") (kind : DeclKind := .theorem)
    (transDeps : Array Name := #[]) : DeclInfo :=
  mkDecl name (statement := statement) (body := body) (kind := kind) (transDeps := transDeps)
    (semanticHash? := some full) (proofIrrelHash? := some meaning)

/-! ### The headline: how a statement prints is not what it means

A toolchain upgrade repretty-prints every elaborated type in a library at once. Under the text
comparison that is a page telling the reader to re-audit everything; under hashes it is nothing,
which is the correct answer. -/

#guard kindOf (run #[mkHashed `T "h1" (statement := "∀ (x : α), P x")]
                   #[mkHashed `T "h1" (statement := "∀ {x : α}, P x")]) `T
  == some .unchanged

-- And the inverse, which is the case only an elaborated measure catches at all: a hypothesis moved
-- into a `variable` line changes what a theorem says without touching a character of its own text.
#guard kindOf (run #[mkHashed `T "h1" (statement := "P")]
                   #[mkHashed `T "h2" (statement := "P")]) `T
  != some .unchanged

/-! ### Whether, then where -/

-- The hash says the meaning moved and the text says it moved here.
#guard kindOf (run #[mkHashed `T "h1" (statement := "P")]
                   #[mkHashed `T "h2" (statement := "Q")]) `T
  == some .statementChanged

-- Proof-irrelevant hash unmoved, proof-relevant hash moved: only a proof changed, whatever the
-- source text says about it.
#guard kindOf (run #[mkHashed `T "h1" (full := "f1")] #[mkHashed `T "h1" (full := "f2")]) `T
  == some .proofOnly

-- A definition's body is its meaning, so the same pair of facts lands differently for one.
#guard kindOf
    (run #[mkHashed `D "h1" (kind := .definition) (body := "def D := 1")]
         #[mkHashed `D "h2" (kind := .definition) (body := "def D := 2")]) `D
  == some .bodyChanged

/-! ### What the text comparison over-reports, and what that costs

Whitespace is already normalized away, so the text comparison survives reindentation. What it
cannot survive is any other way of writing the same term: renaming a bound variable in a
definition's body, or adding a comment inside it, reads as a different definition.

And because a body change propagates along the closure, that false positive does not stay put — it
invalidates every theorem stated about the definition. One renamed lambda binder for a page of
re-reading. -/

private def alphaBefore : Array DeclInfo := #[
  mkHashed `D "d1" (kind := .definition) (body := "def D := fun x => x"),
  mkHashed `T "t1" (statement := "P D") (transDeps := #[`D])
]

private def alphaAfter : Array DeclInfo := #[
  mkHashed `D "d1" (kind := .definition) (body := "def D := fun y => y"),
  mkHashed `T "t1" (statement := "P D") (transDeps := #[`D])
]

#guard kindOf (run alphaBefore alphaAfter) `D == some .unchanged
#guard kindOf (run alphaBefore alphaAfter) `T == some .unchanged
#guard (run alphaBefore alphaAfter).needingReaudit.isEmpty

-- The same pair without hashes: the renaming is reported, and it cascades. This is the behaviour
-- hashes exist to remove, pinned here so the improvement cannot silently regress.
#guard kindOf (run #[mkDecl `D (kind := .definition) (body := "def D := fun x => x"),
                     mkDecl `T (statement := "P D") (transDeps := #[`D])]
                  #[mkDecl `D (kind := .definition) (body := "def D := fun y => y"),
                     mkDecl `T (statement := "P D") (transDeps := #[`D])]) `D
  == some .bodyChanged
#guard kindOf (run #[mkDecl `D (kind := .definition) (body := "def D := fun x => x"),
                     mkDecl `T (statement := "P D") (transDeps := #[`D])]
                  #[mkDecl `D (kind := .definition) (body := "def D := fun y => y"),
                     mkDecl `T (statement := "P D") (transDeps := #[`D])]) `T
  == some .indirect

-- Reindentation, by contrast, was never over-reported: whitespace normalization already covered it
-- on both paths.
#guard kindOf (run #[mkDecl `D (kind := .definition) (body := "def D := 1")]
                   #[mkDecl `D (kind := .definition) (body := "def D :=\n  1")]) `D
  == some .unchanged

/-! ### Indirect invalidation, and what is left when nothing accounts for it

A deep hash moves when anything in the closure moves, so it cannot on its own distinguish "this
statement changed" from "something under it did". The closure supplies the attribution, and what it
cannot attribute is reported as coming from outside rather than left unexplained. -/

private def hashedBefore : Array DeclInfo := #[
  mkHashed `D "d1" (kind := .definition) (body := "def D := 1"),
  mkHashed `T "t1" (statement := "P D") (transDeps := #[`D]),
  mkHashed `U "u1" (statement := "P")
]

private def hashedAfter : Array DeclInfo := #[
  mkHashed `D "d2" (kind := .definition) (body := "def D := 2"),
  -- Untouched as text; its hash moved because `D`'s did.
  mkHashed `T "t2" (statement := "P D") (transDeps := #[`D]),
  mkHashed `U "u1" (statement := "P")
]

#guard kindOf (run hashedBefore hashedAfter) `T == some .indirect
#guard ((run hashedBefore hashedAfter).changes.find? (·.name == `T)).map (·.causes) == some #[`D]
#guard kindOf (run hashedBefore hashedAfter) `U == some .unchanged

-- Nothing in the project accounts for `T`'s hash moving, so the cause is upstream — a Mathlib bump
-- under a statement nobody edited. The text comparison cannot see this case at all.
#guard kindOf (run #[mkHashed `T "t1" (statement := "P")]
                   #[mkHashed `T "t2" (statement := "P")]) `T
  == some .upstream

-- And an upstream change is itself a cause: when `D` moved underneath and `T` is stated about `D`,
-- the reader is told about `D` rather than about "something upstream", which is the more useful of
-- the two true answers.
#guard kindOf (run #[mkHashed `D "d1" (kind := .definition) (body := "def D := c"),
                     mkHashed `T "t1" (statement := "P D") (transDeps := #[`D])]
                  #[mkHashed `D "d2" (kind := .definition) (body := "def D := c"),
                     mkHashed `T "t2" (statement := "P D") (transDeps := #[`D])]) `T
  == some .indirect
#guard kindOf (run #[mkHashed `D "d1" (kind := .definition) (body := "def D := c"),
                     mkHashed `T "t1" (statement := "P D") (transDeps := #[`D])]
                  #[mkHashed `D "d2" (kind := .definition) (body := "def D := c"),
                     mkHashed `T "t2" (statement := "P D") (transDeps := #[`D])]) `D
  == some .upstream

/-! ### Falling back

Per declaration, not per report: an old baseline, or a hash file that does not cover everything,
costs a partial upgrade rather than the whole thing. -/

-- One side unhashed: compared as text, and the text says the statement moved.
#guard kindOf (run #[mkDecl `T (statement := "P")] #[mkHashed `T "h1" (statement := "Q")]) `T
  == some .statementChanged

-- The same declaration hashed on both sides would be `unchanged` here; unhashed, the reprinting is
-- reported. Both are the right answer for the evidence available, which is why the page says which
-- one it used.
#guard kindOf (run #[mkDecl `T (statement := "∀ (x : α), P x")]
                   #[mkDecl `T (statement := "∀ {x : α}, P x")]) `T
  == some .statementChanged

private def mixedReport : DiffReport :=
  run #[mkHashed `A "a1", mkDecl `B] #[mkHashed `A "a1", mkDecl `B]

#guard mixedReport.comparisons == 2
#guard mixedReport.hashedComparisons == 1
#guard mixedReport.usedHashes
#guard !mixedReport.fullyHashed
#guard (run #[mkHashed `A "a1"] #[mkHashed `A "a1"]).fullyHashed
#guard !(run #[mkDecl `A] #[mkDecl `A]).usedHashes

/-! ### The churn warning, and why it is switched off under hashes

`looksLikeToolchainChurn` exists to say that the text comparison has stopped meaning anything. With
hashes on both sides the failure it warns about cannot occur, so warning about it would be telling
the reader to distrust a measure that is fine. -/

private def churnOld : Array DeclInfo :=
  (Array.range 60).map fun i => mkDecl (Name.mkSimple s!"D{i}") (statement := "∀ (x : α), P x")

private def churnNew : Array DeclInfo :=
  (Array.range 60).map fun i => mkDecl (Name.mkSimple s!"D{i}") (statement := "∀ {x : α}, P x")

#guard (run churnOld churnNew).looksLikeToolchainChurn

private def churnOldHashed : Array DeclInfo :=
  (Array.range 60).map fun i =>
    mkHashed (Name.mkSimple s!"D{i}") "h1" (statement := "∀ (x : α), P x")

private def churnNewHashed : Array DeclInfo :=
  (Array.range 60).map fun i =>
    mkHashed (Name.mkSimple s!"D{i}") "h1" (statement := "∀ {x : α}, P x")

-- Not merely un-warned: correctly reported as a library that did not change.
#guard !(run churnOldHashed churnNewHashed).looksLikeToolchainChurn
#guard (run churnOldHashed churnNewHashed).isEmpty

/-! ### Rename evidence

A matching hash is stronger evidence than a matching pretty-printing: it survives the renamed
declaration's *dependencies* being renamed too, which is the case a textual match misses. -/

-- Renamed, and its statement mentions something that was renamed with it, so the two statements do
-- not read alike. The hash matches anyway.
#guard (run #[mkHashed `Old "h1" (statement := "P OldDef")]
            #[mkHashed `New "h1" (statement := "P NewDef")]).renamed == #[(`Old, `New)]

-- The two keyspaces do not meet: an unhashed removal is not matched against a hashed addition on
-- the strength of a coinciding statement, because the evidence claimed would not be the evidence
-- held.
#guard (run #[mkDecl `Old (statement := "P")]
            #[mkHashed `New "h1" (statement := "P")]).renamed == (#[] : Array (Name × Name))

end Referee.Test.Diff
