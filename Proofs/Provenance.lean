module

public import Referee.Provenance
-- For `movedMeaning_needsReaudit`: what the ledger records and what the Changes page reports are
-- the same `ChangeKind`, and the two modules' claims about it should compose.
public import Proofs.Diff

@[expose] public section

/-!
# Proofs about `Referee.Provenance`

The provenance ledger is the one artifact here that is **append-only and kept for the life of a
project**. Everything else the tool writes is regenerated from the environment on the next build, so
a wrong answer is wrong until the bug is fixed; a wrong answer written into the ledger is wrong
forever, and every later fold builds on it. `docs/development.md` puts it as: a fold that records a
change where none happened writes that into the record for good.

That asymmetry is why this module exists. The fold is pure — ledger, revision, declarations in,
ledger out — so its invariants are ordinary theorems.

## What is proved

* **The step is completely characterized.** `foldDecl_new`, `foldDecl_same` and `foldDecl_moved`
  give the fold's three cases as equations, so every claim below is a case split rather than an
  argument about a loop.
* **No spurious change.** `foldDecl_same` is the headline: when a declaration's hash matches what
  the ledger holds, the resulting entry differs from the stored one in the `statement` field alone
  — `changedAt`, `changeCount` and `lastKind` are untouched, and the revision's change counter does
  not move. This is the property the ledger's value rests on.
* **The counter is honest.** `foldRevision_changedCount_le` — the *changed* count a revision reports
  never exceeds the *declaration* count it reports. Both numbers are on the page, and a ledger
  claiming more changes than declarations would be visibly nonsense; now it cannot.
* **Nothing is forgotten.** `mergeUnseen_mem` — an entry for a declaration this revision does not
  expose survives the fold, which is what `foldRevision`'s docstring promises about declarations
  that vanish and come back.
* **The ledger only ever records moved meanings.** `provenanceKind_movedMeaning` — every kind
  `provenanceKind` can return satisfies `ChangeKind.movedMeaning`, so `lastKind` cannot come to hold
  a kind that means nothing happened.
* **Short abbreviations are not matched.** `dateForRef?_short` — `dateForRef?` promises that below
  seven characters a prefix stops identifying a commit and no date is offered, because a confidently
  wrong date is worse than none.

## What is not proved, and why

`foldRevision` ends by sorting its entries with `Array.qsort`, and this toolchain proves *nothing*
about `qsort` — not that it permutes its input, not even that it preserves length. So no property of
`foldRevision.entries` can be stated at all, and the results below are about the fold that produces
those entries rather than about the field.

That is a gap in the standard library rather than in this code, but it does say something about the
shape: the sort is presentational, the fold is the semantics, and burying the first inside the
second is what puts the whole result out of reach. Splitting them would make "every entry the ledger
had is still there" a statement about `foldRevision` itself.
-/

open Lean

namespace Referee.Proofs.Provenance

open Referee

variable (previous : Std.HashMap Name ProvenanceEntry) (idx : Nat)
    (st : FoldState) (decl : DeclInfo)

/-! ## The step, case by case -/

/-- A declaration the ledger has never seen is recorded as of this revision, and is **not** counted
as a change: there is nothing it changed from, and counting it would report a fresh ledger as a
revision in which the entire library moved. -/
theorem foldDecl_new (h : previous[decl.name]? = none) :
    foldDecl previous idx st decl =
      { st with
        seen := st.seen.insert decl.name
        entries := st.entries.push
          { name := decl.name, meaning := decl.proofIrrelHash?.getD "",
            statement := statementKey decl,
            changedAt := idx, firstSeenAt := idx, changeCount := 0, lastKind := "" } } := by
  simp [foldDecl, h]

/-- **No spurious change.** When the hash matches what the ledger holds, the entry that comes out
differs from the stored one in `statement` alone — refreshed by design, because it is the baseline
the *next* fold compares against — and the revision's change counter does not move.

Everything a reader is shown about when a declaration last changed (`changedAt`, `changeCount`,
`lastKind`) is carried over untouched. Since the ledger is append-only, this is the invariant that
cannot be allowed to fail even once. -/
theorem foldDecl_same (old : ProvenanceEntry) (h : previous[decl.name]? = some old)
    (hm : old.meaning = decl.proofIrrelHash?.getD "") :
    foldDecl previous idx st decl =
      { st with
        seen := st.seen.insert decl.name
        entries := st.entries.push { old with statement := statementKey decl } } := by
  simp [foldDecl, h, hm]

/-- A moved hash stamps this revision and increments the count, keeping `firstSeenAt` — which is
what lets the page distinguish "unchanged since it was written" from "unchanged since the ledger
started". -/
theorem foldDecl_moved (old : ProvenanceEntry) (h : previous[decl.name]? = some old)
    (hm : old.meaning ≠ decl.proofIrrelHash?.getD "") :
    foldDecl previous idx st decl =
      { changed := st.changed + 1
        seen := st.seen.insert decl.name
        entries := st.entries.push
          { old with
            meaning := decl.proofIrrelHash?.getD "", statement := statementKey decl,
            changedAt := idx, changeCount := old.changeCount + 1,
            lastKind := (provenanceKind old decl).slug } } := by
  simp [foldDecl, h, hm]

/-- Exactly one entry per declaration folded. -/
theorem foldDecl_entries_size :
    (foldDecl previous idx st decl).entries.size = st.entries.size + 1 := by
  rcases h : previous[decl.name]? with _ | old
  · simp [foldDecl_new _ _ _ _ h]
  · by_cases hm : old.meaning = decl.proofIrrelHash?.getD ""
    · simp [foldDecl_same _ _ _ _ old h hm]
    · simp [foldDecl_moved _ _ _ _ old h hm]

/-- The change counter never decreases. -/
theorem foldDecl_changed_le : st.changed ≤ (foldDecl previous idx st decl).changed := by
  rcases h : previous[decl.name]? with _ | old
  · simp [foldDecl_new _ _ _ _ h]
  · by_cases hm : old.meaning = decl.proofIrrelHash?.getD ""
    · simp [foldDecl_same _ _ _ _ old h hm]
    · simp [foldDecl_moved _ _ _ _ old h hm]

/-- One declaration contributes at most one to the change counter. -/
theorem foldDecl_changed_le_succ :
    (foldDecl previous idx st decl).changed ≤ st.changed + 1 := by
  rcases h : previous[decl.name]? with _ | old
  · simp [foldDecl_new _ _ _ _ h]
  · by_cases hm : old.meaning = decl.proofIrrelHash?.getD ""
    · simp [foldDecl_same _ _ _ _ old h hm]
    · simp [foldDecl_moved _ _ _ _ old h hm]

/-! ## The fold over a revision's declarations -/

private theorem foldl_list_changed_le (l : List DeclInfo) (st : FoldState) :
    (l.foldl (foldDecl previous idx) st).changed ≤ st.changed + l.length := by
  induction l generalizing st with
  | nil => simp
  | cons d ds ih =>
    have h1 := ih (foldDecl previous idx st d)
    have h2 := foldDecl_changed_le_succ previous idx st d
    simp only [List.foldl_cons, List.length_cons]
    omega

theorem foldl_changed_le (ds : Array DeclInfo) (st : FoldState) :
    (ds.foldl (foldDecl previous idx) st).changed ≤ st.changed + ds.size := by
  rw [← Array.foldl_toList, ← Array.length_toList]
  exact foldl_list_changed_le previous idx ds.toList st

private theorem foldl_list_entries_size (l : List DeclInfo) (st : FoldState) :
    (l.foldl (foldDecl previous idx) st).entries.size = st.entries.size + l.length := by
  induction l generalizing st with
  | nil => simp
  | cons d ds ih =>
    have h1 := ih (foldDecl previous idx st d)
    have h2 := foldDecl_entries_size previous idx st d
    simp only [List.foldl_cons, List.length_cons]
    omega

/-- One entry out per declaration in, so the fold neither drops nor duplicates. -/
theorem foldl_entries_size (ds : Array DeclInfo) (st : FoldState) :
    (ds.foldl (foldDecl previous idx) st).entries.size = st.entries.size + ds.size := by
  rw [← Array.foldl_toList, ← Array.length_toList]
  exact foldl_list_entries_size previous idx ds.toList st

/-! ## The recorded revision -/

/-- Each fold appends exactly one revision. -/
theorem foldRevision_revisions_size (p : Provenance) (rev : RevisionInfo) (ds : Array DeclInfo) :
    (foldRevision p rev ds).revisions.size = p.revisions.size + 1 := by
  simp [foldRevision]

/-- **Append-only.** A fold rewrites no revision it already held: dropping the one it appended
returns the ledger's history unchanged. -/
theorem foldRevision_revisions_pop (p : Provenance) (rev : RevisionInfo) (ds : Array DeclInfo) :
    (foldRevision p rev ds).revisions.pop = p.revisions := by
  simp [foldRevision]

/-- **The counter is honest.** A revision never reports more declarations changed than it reports
declarations. Both numbers are shown, so this is a claim a reader can check by eye — and now one the
tool cannot get wrong. -/
theorem foldRevision_changedCount_le (p : Provenance) (rev : RevisionInfo) (ds : Array DeclInfo) :
    ∀ r ∈ (foldRevision p rev ds).revisions.back?, r.changedCount ≤ r.declCount := by
  intro r hr
  simp only [foldRevision, Array.back?_push, Option.mem_def, Option.some.injEq] at hr
  subst hr
  simpa using foldl_changed_le p.byName p.revisions.size ds {}

/-! ## Nothing is forgotten -/

private def mergeStep (seen : Std.HashSet Name) (acc : Array ProvenanceEntry)
    (old : ProvenanceEntry) : Array ProvenanceEntry :=
  if seen.contains old.name then acc else acc.push old

private theorem merge_acc_mono (seen : Std.HashSet Name) (l : List ProvenanceEntry)
    (acc : Array ProvenanceEntry) (e : ProvenanceEntry) (h : e ∈ acc) :
    e ∈ l.foldl (mergeStep seen) acc := by
  induction l generalizing acc with
  | nil => simpa using h
  | cons d ds ih =>
    refine ih _ ?_
    unfold mergeStep
    split
    · exact h
    · exact Array.mem_push.mpr (Or.inl h)

private theorem merge_list_mem (seen : Std.HashSet Name) (l : List ProvenanceEntry)
    (acc : Array ProvenanceEntry) (e : ProvenanceEntry)
    (he : e ∈ l) (hs : ¬ seen.contains e.name) :
    e ∈ l.foldl (mergeStep seen) acc := by
  induction l generalizing acc with
  | nil => simp at he
  | cons d ds ih =>
    rcases List.mem_cons.mp he with rfl | h'
    · refine merge_acc_mono seen ds _ e ?_
      unfold mergeStep
      simp [hs]
    · exact ih _ h'

/-- **Nothing is forgotten.** An entry for a declaration this revision does not expose survives the
merge unchanged.

`foldRevision`'s docstring promises exactly this: the ledger records what it saw, and forgetting a
removed declaration would lose the provenance a reader needs if it comes back. Stated about the
merge rather than about `foldRevision.entries` because of the `qsort` gap described at the top of
this file. -/
theorem mergeUnseen_mem (seen : Std.HashSet Name) (olds init : Array ProvenanceEntry)
    (e : ProvenanceEntry) (he : e ∈ olds) (hs : ¬ seen.contains e.name) :
    e ∈ olds.foldl (fun acc old => if seen.contains old.name then acc else acc.push old) init := by
  rw [← Array.foldl_toList]
  exact merge_list_mem seen olds.toList init e (by simpa using he) hs

/-! ## The kinds the ledger records -/

/-- Every kind `provenanceKind` can return is one whose meaning moved.

So `ProvenanceEntry.lastKind` can never come to hold a kind that means nothing happened — the
ledger stamps a kind only where it has already decided the hash moved, and the kinds it chooses
between all agree with that decision. -/
theorem provenanceKind_movedMeaning (prev : ProvenanceEntry) (d : DeclInfo) :
    (provenanceKind prev d).movedMeaning := by
  unfold provenanceKind
  repeat' split
  all_goals decide

/-- And so anything the ledger records is something a reader has to look at again. -/
theorem provenanceKind_needsReaudit (prev : ProvenanceEntry) (d : DeclInfo) :
    (provenanceKind prev d).needsReaudit :=
  Proofs.Diff.movedMeaning_needsReaudit _ (provenanceKind_movedMeaning prev d)

/-! ## Looking a revision up -/

/-- The empty sha is never "already folded", so a ledger with no revisions cannot be mistaken for
one that already holds this build. -/
theorem alreadyAt_empty (p : Provenance) : ¬ p.alreadyAt "" := by
  simp [Provenance.alreadyAt]

theorem dateForRef?_empty (p : Provenance) : p.dateForRef? "" = none := by
  simp [Provenance.dateForRef?]

/-- **Short abbreviations are not matched.** Below seven characters a prefix stops identifying a
commit, so a label that matches no revision's `ref` exactly gets no date at all — rather than the
date of whichever revision happens to share its first few characters.

The docstring's reason, made checkable: a confidently wrong date is worse than none. -/
theorem dateForRef?_short (p : Provenance) (label : String) (h : label.length < 7)
    (hno : ∀ r ∈ p.revisions, r.ref ≠ label) : p.dateForRef? label = none := by
  have hfind : p.revisions.find? (fun r => r.ref == label) = none := by
    rw [Array.find?_eq_none]
    intro a ha
    simpa using hno a ha
  simp [Provenance.dateForRef?, h, hfind]

/-! ## Regressions, pinned

The two invariants below are not general design properties; they are the specific claims that a
past bug fix rests on, written down so the bug cannot come back.

`6b1da0c` ("changes page fix") added `ProvenanceRow.seenFromStart`, because a change count of zero
arises two ways — a declaration that has been there all along and never moved, and one added at some
later revision that has not moved since — and the page rendered both as "unchanged since the
beginning". Reporting a declaration added yesterday as part of the original library is the opposite
of what a reader needs. The fix carries a comment stating the invariant it relies on:

> `changedAt` equals `firstSeenAt` whenever the count is zero, so `changedRef` above already names
> the revision this one appeared at; only the wording has to change.

That is `NeverMoved`, and nothing checked it. -/

/-- A declaration that has never changed dates its (non-)change from the revision it first appeared
at — so the revision named on the page is the one it appeared at, which is what lets the fixed
wording reuse it. -/
def NeverMoved (e : ProvenanceEntry) : Prop := e.changeCount = 0 → e.changedAt = e.firstSeenAt

/-- The fold maintains it. All three cases: a first sighting sets both fields to the same revision,
an unchanged meaning carries both over, and a moved meaning makes the count non-zero so there is
nothing to claim. -/
theorem foldDecl_pushed_neverMoved (previous : Std.HashMap Name ProvenanceEntry) (idx : Nat)
    (st : FoldState) (decl : DeclInfo)
    (hprev : ∀ old, previous[decl.name]? = some old → NeverMoved old) :
    ∀ e, (foldDecl previous idx st decl).entries.back? = some e → NeverMoved e := by
  intro e he
  rcases h : previous[decl.name]? with _ | old
  · rw [foldDecl_new _ _ _ _ h] at he
    simp [Array.back?_push] at he
    subst he
    intro _; rfl
  · by_cases hm : old.meaning = decl.proofIrrelHash?.getD ""
    · rw [foldDecl_same _ _ _ _ old h hm] at he
      simp [Array.back?_push] at he
      subst he
      exact hprev old h
    · rw [foldDecl_moved _ _ _ _ old h hm] at he
      simp [Array.back?_push] at he
      subst he
      intro hz; simp at hz

/-- And the other half of the same fix: `firstSeenAt` is immutable. A declaration the ledger already
knew keeps the revision it was first seen at, whatever happens to its meaning — without which
`seenFromStart` would drift and the wording would be wrong again in a different way. -/
theorem foldDecl_pushed_firstSeenAt (previous : Std.HashMap Name ProvenanceEntry) (idx : Nat)
    (st : FoldState) (decl : DeclInfo) (old : ProvenanceEntry)
    (h : previous[decl.name]? = some old) :
    ∀ e, (foldDecl previous idx st decl).entries.back? = some e →
      e.firstSeenAt = old.firstSeenAt := by
  intro e he
  by_cases hm : old.meaning = decl.proofIrrelHash?.getD ""
  · rw [foldDecl_same _ _ _ _ old h hm] at he
    simp [Array.back?_push] at he
    subst he; rfl
  · rw [foldDecl_moved _ _ _ _ old h hm] at he
    simp [Array.back?_push] at he
    subst he; rfl

/-- **The re-run guard actually fires.** After folding a revision, `alreadyAt` recognizes it.

`Provenance.alreadyAt` exists because re-running `provenance` on an unchanged tree — a re-run of a
CI job, a rebuild after a failed publish — would otherwise append a duplicate revision and leave the
ledger reporting a change count higher than the number of revisions that happened. `Test/Provenance`
covers the guard on examples; this says it holds for every revision with a sha. -/
theorem alreadyAt_foldRevision (p : Provenance) (rev : RevisionInfo) (ds : Array DeclInfo)
    (h : rev.sha ≠ "") : (foldRevision p rev ds).alreadyAt rev.sha := by
  simp [Provenance.alreadyAt, Provenance.latest?, foldRevision, Array.back?_push, h]


end Referee.Proofs.Provenance
