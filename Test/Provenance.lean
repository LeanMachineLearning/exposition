module

public import Referee.Provenance
-- The checks below are `#guard`s, which Lean elaborates into compile-time (`meta`) definitions, so
-- the declarations under test have to be imported at that level too.
meta import Referee.Provenance

@[expose] public section

/-!
# Tests for `Referee.Provenance`

The ledger fold is a pure function of (ledger so far, revision, declarations), which makes it
unit-testable — and it needs to be, because it is the one piece of this tool whose mistakes are
*permanent*. The file is append-only and is meant to be kept for the life of a project, so a fold
that records a change where none happened writes that into the record for good; no later build can
correct it.

What is checked:

* the first fold reports nothing as changed — a fresh ledger is not a revision in which the whole
  library moved;
* an unchanged revision leaves `changedAt` where it was, which is the property the whole feature
  reduces to: "unchanged since v0.2" has to survive every build between then and now;
* a changed meaning stamps the new revision and increments the count;
* the direct/inherited split, which is where the stored statement earns its place;
* declarations added, and declarations that disappear and must not lose their history;
* `alreadyAt`, the idempotence guard that stops a re-run from inventing a revision;
* `rowFor`, including the case the declaration-page line exists for — edited more recently than its
  meaning changed.

Each check is a `#guard`, so any regression turns into a build error. Run with `lake build Test`.
-/

open Lean Std
open Referee
open ChallengeGen

namespace Referee.Test.Provenance

/-! ## Fixtures -/

private def mkDecl (name : Name) (meaning : String) (statement : String := "True")
    (kind : DeclKind := .theorem) : DeclInfo := {
  name := name
  moduleName := `Test.Mod
  modulePath := "Mod"
  groupKey := "Mod"
  kind := kind
  displaySignature := statement
  expandedSignature := statement
  docBlocks := #[]
  proofText? := none
  source? := none
  deps := #[]
  typeDeps := #[]
  proofIrrelHash? := some meaning
  semanticHash? := some meaning
}

private def rev (ref : String) (date : String := "2026-01-01") : RevisionInfo :=
  { ref := ref, sha := "sha-" ++ ref, date := date }

private def entryFor (p : Provenance) (n : Name) : Option ProvenanceEntry :=
  p.entries.find? (·.name == n)

private def changedRefOf (p : Provenance) (n : Name) : Option String := do
  let e ← entryFor p n
  let r ← p.revisionAt? e.changedAt
  return r.ref

/-! ## The first fold

A fresh ledger has nothing to compare against. Reporting its declarations as changed would make
every project's first provenance build announce that the entire library had just moved. -/

private def v1 : Provenance :=
  foldRevision {} (rev "v1") #[mkDecl `A "a1", mkDecl `B "b1" (statement := "P")]

#guard v1.revisions.size == 1
#guard (v1.revisions[0]!).changedCount == 0
#guard (v1.revisions[0]!).declCount == 2
#guard (entryFor v1 `A).map (·.changeCount) == some 0
#guard (entryFor v1 `A).map (·.lastKind) == some ""
#guard (entryFor v1 `A).map (·.firstSeenAt) == some 0

/-! ## A revision that changes nothing

The property everything else rests on: `changedAt` must not drift forward just because another
build happened. "Unchanged since v1" has to keep saying v1 no matter how many revisions are folded
after it. -/

private def v2 : Provenance :=
  foldRevision v1 (rev "v2") #[mkDecl `A "a1", mkDecl `B "b1" (statement := "P")]

#guard (v2.revisions[1]!).changedCount == 0
#guard changedRefOf v2 `A == some "v1"
#guard (entryFor v2 `A).map (·.changeCount) == some 0

/-! ## A revision that changes something -/

private def v3 : Provenance :=
  foldRevision v2 (rev "v3" "2026-03-01") #[mkDecl `A "a2", mkDecl `B "b1" (statement := "P")]

#guard (v3.revisions[2]!).changedCount == 1
#guard changedRefOf v3 `A == some "v3"
#guard changedRefOf v3 `B == some "v1"
#guard (entryFor v3 `A).map (·.changeCount) == some 1
-- Its first sighting is still recorded, which is what separates "unchanged since it was written"
-- from "unchanged for as long as anyone has been looking".
#guard (entryFor v3 `A).map (·.firstSeenAt) == some 0

/-! ## Direct or inherited

The hash is deep, so it moves when a dependency moves. The stored statement is the only thing that
can tell the two apart, and it is why the fold keeps one. -/

-- Statement text moved as well: the change is this declaration's own.
#guard (entryFor (foldRevision v1 (rev "v2") #[mkDecl `A "a2" (statement := "Q")]) `A).map
    (·.lastKind) == some "statement"

-- Hash moved, statement text did not, and a theorem's body is not its meaning — so what moved is
-- underneath it. Nothing here has a closure to narrow that down with, unlike `Referee.Diff`.
#guard (entryFor (foldRevision v1 (rev "v2") #[mkDecl `A "a2"]) `A).map
    (·.lastKind) == some "upstream"

-- For a definition, the body *is* the meaning, so the same evidence lands differently.
#guard (entryFor (foldRevision v1 (rev "v2") #[mkDecl `A "a2" (kind := .definition)]) `A).map
    (·.lastKind) == some "body"

/-! ### The statement is refreshed even when nothing changed

Otherwise a declaration whose statement is reformatted in one revision and genuinely changed in the
next would have the second change compared against text two revisions old, and be misreported as
inherited. -/

private def reformatted : Provenance :=
  foldRevision v1 (rev "v2") #[mkDecl `A "a1" (statement := "True  ")]

#guard (entryFor reformatted `A).map (·.statement) == some "True"
#guard (reformatted.revisions[1]!).changedCount == 0

/-! ## Additions and disappearances -/

private def withNew : Provenance :=
  foldRevision v1 (rev "v2") #[mkDecl `A "a1", mkDecl `B "b1" (statement := "P"), mkDecl `C "c1"]

-- An addition is not a change: there is nothing it changed from.
#guard (withNew.revisions[1]!).changedCount == 0
#guard (entryFor withNew `C).map (·.firstSeenAt) == some 1
#guard changedRefOf withNew `C == some "v2"

-- A declaration the revision does not expose keeps its entry untouched. The ledger records what it
-- saw; dropping it would lose the provenance a reader needs if it ever comes back.
private def withoutB : Provenance := foldRevision v1 (rev "v2") #[mkDecl `A "a1"]

#guard (entryFor withoutB `B).isSome
#guard changedRefOf withoutB `B == some "v1"
#guard (withoutB.revisions[1]!).declCount == 1

/-! ## Idempotence

Re-running `provenance` on an unchanged tree is an ordinary thing to do — a retried CI job, a
rebuild after a failed publish. Without this guard each one would append a revision, and the change
counts would climb above the number of revisions that ever happened. -/

#guard v1.alreadyAt "sha-v1"
#guard !v1.alreadyAt "sha-v2"
-- An empty sha never matches, so a ledger folded outside a repository cannot swallow the next fold.
#guard !v1.alreadyAt ""
#guard !({} : Provenance).alreadyAt "sha-v1"

/-! ## Rendering one declaration's row -/

private def rowIn (p : Provenance) (n : Name) (edits : Array (Name × EditInfo) := #[])
    : Option ProvenanceRow :=
  p.rowFor n p.byName (edits.foldl (fun acc (k, v) => acc.insert k v) {})

#guard (rowIn v3 `A).map (·.changedRef) == some "v3"
#guard (rowIn v3 `A).map (·.changeCount) == some 1
#guard (rowIn v3 `A).map (·.sinceFirstSeen) == some false
-- Never changed within the ledger, so the page must say "since the ledger began" rather than imply
-- it was seen to change at v1.
#guard (rowIn v3 `B).map (·.sinceFirstSeen) == some true
#guard (rowIn v3 `B).map (·.seenFromStart) == some true
#guard (rowIn v3 `Absent).isNone

/-! ### Added later, and never moved since

A change count of zero has two causes, and only one of them means "has always been this way". `C`
first appears at `v2`: it has never changed, so `sinceFirstSeen` holds, but it was not there at the
oldest revision. Reporting the two alike printed `v2` — the *newest* revision — as the oldest on
record, and a declaration added in the latest commit as part of the original library. -/

#guard (rowIn withNew `C).map (·.sinceFirstSeen) == some true
#guard (rowIn withNew `C).map (·.seenFromStart) == some false
-- `changedAt` equals `firstSeenAt` when nothing has changed, so the ref is already the right one
-- and only the wording has to differ.
#guard (rowIn withNew `C).map (·.changedRef) == some "v2"
-- The declarations that really were there from the start keep the other phrasing.
#guard (rowIn withNew `A).map (·.seenFromStart) == some true
#guard (rowIn withNew `B).map (·.seenFromStart) == some true

/-! ### The sentence the declaration page exists to print

Edited after its meaning last changed: something moved, and it was not the meaning. -/

private def edited (date : String) : Array (Name × EditInfo) :=
  #[(`A, { commit := { sha := "deadbeef", shortSha := "deadbee", date := date, subject := "tidy" } })]

#guard (rowIn v3 `A (edited "2026-06-01")).map (·.editedWithoutMeaningChange) == some true
#guard (rowIn v3 `A (edited "2026-06-01")).map (·.editedSubject) == some "tidy"
-- Edited in the same revision that changed it: nothing reassuring to say, so it says nothing.
#guard (rowIn v3 `A (edited "2026-03-01")).map (·.editedWithoutMeaningChange) == some false
#guard (rowIn v3 `A (edited "2026-01-15")).map (·.editedWithoutMeaningChange) == some false
-- No blame for it at all: the claim needs a date and does not get made without one.
#guard (rowIn v3 `A).map (·.editedWithoutMeaningChange) == some false
#guard (rowIn v3 `A).map (·.editedDate) == some ""

end Referee.Test.Provenance
