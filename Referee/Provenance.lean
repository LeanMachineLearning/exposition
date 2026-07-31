module

public import Referee.Diff

@[expose] public section

/-!
# Provenance: when a declaration last meant something else

`--baseline` answers "what changed between these two files". This module answers the question a
returning referee actually asks, which is narrower and harder: **when did this last change, and is
that after I read it?**

## Two facts, never merged

A declaration carries two independent timestamps here, and keeping them apart is the whole point:

- **when its file was last edited** — `git blame` over its source range. Textual. It says somebody
  touched these lines, and nothing whatever about whether the meaning moved;
- **when its meaning last changed** — the newest recorded revision at which its proof-irrelevant
  semantic hash differs from the one before. Exact.

A referee who sees only the first panics and re-reads. *Edited four days ago, meaning unchanged
since March* is the sentence that stops that, and it is the temporal form of the argument the
Changes page already makes about proof-only changes: something moved, and it was not the meaning.

## Why a ledger rather than a walk of history

Getting the second fact exactly would mean re-elaborating the library at every commit. Instead it
is **folded forward**: each build compares the current hashes against the ones the ledger already
holds and stamps the revisions where they differ. That is `O(decls)` string comparisons per build,
no history walk, and a file whose size does not grow with the length of the history — one entry per
declaration, not one per declaration per commit.

The cost is that **resolution is exactly your build cadence**. A ledger fed by per-commit CI dates
changes to commits; one fed per release dates them to releases and says "changed between v0.2 and
v0.3", which is arguably what a referee wanted anyway. `Provenance.revisions` records what was
actually folded, so the site can state its own resolution rather than implying a precision it does
not have.

## Semantic hashes are a hard requirement

`collect --hashes` must have been run. There is no fallback to comparing pretty-printed types, and
that is deliberate: a toolchain upgrade repretty-prints every statement in a library at once, so a
text-keyed ledger would record a mass false change — and, being append-only, would record it
*permanently*. A ledger's only value is that it can be trusted about years of history; one that
corrupts itself at every toolchain bump has none.

Blame alone is not offered for the same reason in reverse. "Edited four days ago", with no way to
say whether that mattered, is the half of the feature that misleads.
-/

open Lean

namespace Referee

/-- Format version of `Provenance`. Bump whenever the structures below gain or change a field, so a
stale ledger fails with an actionable message rather than a field-level decode error.

- 1: initial -/
def provenanceVersion : Nat := 1

/-- A commit, as much of one as a reader needs. -/
structure CommitInfo where
  sha : String := ""
  shortSha : String := ""
  /-- Author date, `YYYY-MM-DD`.

  A date and not a relative interval. A published site is read long after it is built, and "4 months
  ago" silently becomes a lie the moment the site stops being rebuilt; the build date is stated once
  on the page instead. -/
  date : String := ""
  subject : String := ""
deriving Repr, Inhabited, BEq, ToJson, FromJson

/-- Where a declaration's source text was last touched.

Textual throughout — this is `git blame` over a line range — so nothing here is ever presented as a
statement about meaning. -/
structure EditInfo where
  commit : CommitInfo
  /-- The same, restricted to the declaration's signature lines: the range `collect` already splits
  out as `displaySignature`, before the body starts.

  Closer to a statement change than whole-declaration blame, and still not one — a `variable` line
  edited elsewhere in the file changes what a theorem says while touching none of these lines. That
  gap is exactly why the ledger exists and why this is never labelled as a meaning change. -/
  signature? : Option CommitInfo := none
  /-- Some of its lines are not in any commit.

  `git blame` attributes uncommitted work to the all-zero sha with a placeholder summary, and
  passing that through would put an invented commit on the page. So it is recorded as what it is,
  and `commit` continues to hold the newest *committed* change — which is the more useful pair of
  facts anyway. -/
  uncommitted : Bool := false
deriving Repr, Inhabited, ToJson, FromJson

/-- One revision the ledger has been folded over. -/
structure RevisionInfo where
  /-- What to call it on the page: a tag where the revision had one, else a short sha. -/
  ref : String := ""
  sha : String := ""
  date : String := ""
  /-- Declarations exposed at that revision. -/
  declCount : Nat := 0
  /-- How many of them changed meaning relative to the revision before. Zero for the first, which
  has nothing to be compared against — reported rather than hidden, so the page never presents the
  oldest recorded revision as one where nothing happened. -/
  changedCount : Nat := 0
deriving Repr, Inhabited, ToJson, FromJson

/-- What the ledger knows about one declaration. -/
structure ProvenanceEntry where
  name : Name
  /-- Its proof-irrelevant semantic hash as of the newest folded revision. -/
  meaning : String := ""
  /-- Its whitespace-normalized elaborated statement, as of the newest folded revision.

  Kept only so the *next* fold can tell a direct statement change from one inherited from a
  dependency — the hash is deep and conflates the two. Never compared for detection. -/
  statement : String := ""
  /-- Index into `Provenance.revisions` of the revision at which the current meaning first
  appeared. -/
  changedAt : Nat := 0
  /-- Index of the revision at which this declaration was first recorded. Equal to `changedAt`
  until something changes it, which is what lets the page distinguish "unchanged since it was
  written" from "unchanged since the ledger started". -/
  firstSeenAt : Nat := 0
  /-- How many folded revisions changed its meaning. Evidence about how settled a declaration is,
  reported as a count and never as a judgement — see the note on `Provenance` about that. -/
  changeCount : Nat := 0
  /-- `ChangeKind.slug` for the most recent change, so a revision selector can break its queue down
  by what happened rather than only counting it. Empty for a declaration that has never changed. -/
  lastKind : String := ""
deriving Repr, Inhabited, ToJson, FromJson

/-- The ledger, plus the blame for the revision it was last folded at.

Append-only in the revisions and monotone in the entries: a fold adds a revision and updates
entries, and never rewrites recorded history. That is what makes it safe to commit alongside
`data.json` and keep for the life of a project.

**Nothing here ranks or judges.** `changeCount` is a count, not a risk score. That a statement has
moved five times in a quarter is evidence a reader may weigh; calling it unstable would be the tool
drawing the conclusion, which is the same rule that governs the trust page's axiom list. -/
structure Provenance where
  version : Nat := provenanceVersion
  project : String := ""
  /-- Oldest first. Entry indices point into this. -/
  revisions : Array RevisionInfo := #[]
  entries : Array ProvenanceEntry := #[]
  /-- Declaration ↦ where its source was last touched, for the newest revision only.

  Deliberately not historical: blame describes a working tree, and re-running it is cheap, so
  keeping past answers would grow the file to say something that can always be recomputed. -/
  edits : Array (Name × EditInfo) := #[]
  /-- The working tree had uncommitted changes when this was folded, so the blame below describes
  something no commit contains. Recorded because the alternative is a file that looks authoritative
  and is not. -/
  dirty : Bool := false
deriving Repr, Inhabited, ToJson, FromJson

/-! ## The fold

Pure, so all of it is unit-testable: given the ledger so far, a revision, and the declarations as
collected at that revision, produce the ledger including it. -/

/-- Declaration ↦ its entry. -/
def Provenance.byName (p : Provenance) : Std.HashMap Name ProvenanceEntry :=
  p.entries.foldl (fun acc e => acc.insert e.name e) {}

/-- The revision an entry's current meaning dates from, if it is on record. -/
def Provenance.revisionAt? (p : Provenance) (i : Nat) : Option RevisionInfo :=
  p.revisions[i]?

/-- The newest recorded revision. -/
def Provenance.latest? (p : Provenance) : Option RevisionInfo :=
  p.revisions.back?

/-- The date of a revision named by `label`, if the ledger has folded one.

Exists so that a name appearing elsewhere on the site — a `--baseline-label`, most usefully — can
be given the date the ledger already knows for it, rather than leaving the reader with a bare sha
and no sense of how old it is. A `data.json` carries no timestamp of its own, deliberately: adding
one would make two builds of identical source differ.

Matched on the ref first, then on the sha, so a label written as a short sha finds a revision
recorded under its full one and the other way round. Abbreviations shorter than seven characters
are not matched at all: below that a prefix stops identifying a commit, and a confidently wrong
date is worse than none. -/
def Provenance.dateForRef? (p : Provenance) (label : String) : Option String := do
  if label.isEmpty then none else
  let exact := p.revisions.find? fun r => r.ref == label
  let byPrefix := if label.length < 7 then none else p.revisions.find? fun r =>
    (r.sha.startsWith label) || (!r.sha.isEmpty && label.startsWith r.sha)
  let rev ← exact <|> byPrefix
  if rev.date.isEmpty then none else some rev.date

/-- Whether this revision is already the newest one on record, compared by sha.

Folding the same commit twice would append a duplicate revision and reset nothing, leaving a ledger
that reports a change count higher than the number of revisions that actually happened. Re-running
`provenance` on an unchanged tree is a normal thing to do — a re-run of a CI job, a rebuild after a
failed publish — so it is made idempotent rather than merely discouraged. -/
def Provenance.alreadyAt (p : Provenance) (sha : String) : Bool :=
  !sha.isEmpty && (p.latest?.map (·.sha == sha)).getD false

/-- How a declaration's meaning changed at this revision, given what the ledger held before.

The same meaning/text split `Referee.Diff` makes, with the ledger's stored statement standing in
for the baseline's: the hash says the meaning moved, the statement says whether it moved *here*.
`upstream` is what is left when the hash moved and the statement did not — the cause is outside the
exposed declarations, and unlike `Diff` this has no closure to hand to narrow it further, so it is
reported as it is found. -/
def provenanceKind (prev : ProvenanceEntry) (decl : DeclInfo) : ChangeKind :=
  if statementKey decl != prev.statement then .statementChanged
  else if decl.bodyIsMeaning then .bodyChanged
  else .upstream

/-- The fold's running state: how many declarations changed meaning at this revision, which names
the revision exposed, and the entries built so far. -/
structure FoldState where
  changed : Nat := 0
  seen : Std.HashSet Name := {}
  entries : Array ProvenanceEntry := #[]

/-- One declaration's contribution to the fold, against `previous` (the ledger as it stood) at
revision index `idx`.

Named rather than written inline in `foldRevision`'s loop so that the ledger's invariants can be
stated about it and proved by induction — the append-only guarantee is only worth as much as the
step that maintains it. See `Proofs/Provenance.lean`. -/
def foldDecl (previous : Std.HashMap Name ProvenanceEntry) (idx : Nat)
    (st : FoldState) (decl : DeclInfo) : FoldState :=
  let meaning := decl.proofIrrelHash?.getD ""
  let statement := statementKey decl
  let seen := st.seen.insert decl.name
  match previous.get? decl.name with
  | none =>
    -- First sighting. Not a change: there is nothing it changed *from*, and counting it as one
    -- would report a fresh ledger as a revision in which the entire library moved.
    { st with seen, entries := st.entries.push {
        name := decl.name, meaning, statement,
        changedAt := idx, firstSeenAt := idx, changeCount := 0, lastKind := "" } }
  | some old =>
    if old.meaning == meaning then
      -- The statement is still refreshed: it is the baseline the *next* fold compares against,
      -- and letting it go stale would make a later direct change look inherited.
      { st with seen, entries := st.entries.push { old with statement } }
    else
      { changed := st.changed + 1
        seen := seen
        entries := st.entries.push {
          old with
          meaning, statement,
          changedAt := idx,
          changeCount := old.changeCount + 1,
          lastKind := (provenanceKind old decl).slug } }

/-- Folds one revision into the ledger.

`decls` are the declarations as collected at `rev`; every one of them must carry a semantic hash,
which the caller checks. A declaration that has vanished keeps its entry untouched: the ledger
records what it saw, and forgetting a removed declaration would lose the provenance a reader needs
if it comes back. -/
def foldRevision (prev : Provenance) (rev : RevisionInfo) (decls : Array DeclInfo) : Provenance :=
  let idx := prev.revisions.size
  let st := decls.foldl (foldDecl prev.byName idx) {}
  -- Entries for declarations this revision does not expose, kept as they were.
  let entries := prev.entries.foldl
    (fun acc old => if st.seen.contains old.name then acc else acc.push old) st.entries
  { prev with
    version := provenanceVersion
    revisions := prev.revisions.push { rev with declCount := decls.size, changedCount := st.changed }
    entries := entries.qsort fun a b => Name.lt a.name b.name }

/-! ## Render payloads

What the site needs per declaration, resolved from indices into text once rather than in each of
the several places that show it. -/

/-- One declaration's provenance, ready to render. -/
structure ProvenanceRow where
  /-- Ref and date at which the meaning last changed. -/
  changedRef : String := ""
  changedDate : String := ""
  /-- True when the meaning has never changed within the ledger, so the right phrasing is "since
  the ledger began" rather than "unchanged since v0.2" — which would imply it was seen to change
  then. -/
  sinceFirstSeen : Bool := true
  /-- True when the declaration was already there at the ledger's *oldest* revision.

  With `sinceFirstSeen` this is what separates the two ways a declaration can have a change count of
  zero: one that has been there all along and never moved, and one that was added at some later
  revision and has not moved since. Both have never changed, and only the first can be described as
  unchanged since the beginning — saying that of the second reports a declaration added yesterday as
  part of the original library, which is the opposite of what a reader needs to know. -/
  seenFromStart : Bool := true
  changeCount : Nat := 0
  /-- `ChangeKind.slug` of the last change, empty if it never changed. -/
  lastKind : String := ""
  /-- Where the source text was last touched, which is a different claim; empty when there is no
  blame for it. -/
  editedDate : String := ""
  editedSha : String := ""
  editedSubject : String := ""
  /-- The file was touched more recently than the meaning changed: the reassuring case, and the one
  the line exists to be able to state. -/
  editedWithoutMeaningChange : Bool := false
  /-- Some of its lines are not in any commit, so what is on this page was built from a working
  tree rather than from anything a reader could check out. -/
  uncommitted : Bool := false
deriving Repr, Inhabited, ToJson, FromJson

/-- Resolves a declaration's ledger entry and blame into a row.

`none` when the ledger has never seen the declaration — a build newer than the ledger, which is
normal and says nothing interesting, so it shows nothing at all. -/
def Provenance.rowFor (p : Provenance) (name : Name)
    (entries : Std.HashMap Name ProvenanceEntry) (edits : Std.HashMap Name EditInfo)
    : Option ProvenanceRow := do
  let entry ← entries.get? name
  let rev ← p.revisionAt? entry.changedAt
  let edit? := edits.get? name
  let editedDate := (edit?.map (·.commit.date)).getD ""
  return {
    changedRef := rev.ref
    changedDate := rev.date
    sinceFirstSeen := entry.changeCount == 0
    -- `changedAt` equals `firstSeenAt` whenever the count is zero, so `changedRef` above already
    -- names the revision this one appeared at; only the wording has to change.
    seenFromStart := entry.firstSeenAt == 0
    changeCount := entry.changeCount
    lastKind := entry.lastKind
    editedDate := editedDate
    editedSha := (edit?.map (·.commit.shortSha)).getD ""
    editedSubject := (edit?.map (·.commit.subject)).getD ""
    -- String comparison, which is why the dates are `YYYY-MM-DD`: it orders correctly and needs no
    -- date arithmetic in a module that has no business doing any.
    editedWithoutMeaningChange := !editedDate.isEmpty && editedDate > rev.date
    uncommitted := (edit?.map (·.uncommitted)).getD false
  }

/-! ## The revision selector

The upgrade the ledger makes possible: instead of "compared against the one file passed at build
time", *pick the revision you last read and be told what to read again*.

It works on a static site because the ledger is small. Each declaration carries one index into the
revision list, so "changed since v0.2" is an integer comparison the browser can do over the whole
library, with no server and no second `data.json`.

What it cannot do is show the statements side by side. The ledger stores hashes, not the text as it
stood at every revision, and keeping that would grow the file without bound. So the picker gives
the *queue* and its breakdown; the token-level diff still needs `--baseline` and a real earlier
build. The page says so where the picker is, rather than leaving a reader to notice. -/

/-- One declaration, as the revision selector needs it. -/
structure RevisionPickerDecl where
  name : String
  href : String := ""
  module : String := ""
  /-- Index into `RevisionPickerData.revisions` of the revision at which its meaning last changed. -/
  changedAt : Nat := 0
  /-- Index into `RevisionPickerData.revisions` of the revision at which it first appeared.

  A declaration that did not exist at the revision a reader worked through is something they have to
  read, and `everChanged` alone cannot say so: a first sighting is deliberately not counted as a
  change (see `foldRevision`), so without this the selector filters every newly added declaration
  out of its own queue and reports a revision that added a hundred of them as changing nothing. -/
  firstSeenAt : Nat := 0
  /-- Whether it has ever been seen to change within the ledger. One that has not is reported as
  such rather than as having changed at the oldest recorded revision, which would be an artefact of
  when the ledger started rather than a fact about the library. -/
  everChanged : Bool := false
  /-- `ChangeKind.slug` of that change. -/
  kind : String := ""
  /-- How many declarations' meanings rest on it, so the queue can be ordered by what re-reading
  costs rather than alphabetically. -/
  dependents : Nat := 0
deriving Repr, Inhabited, ToJson, FromJson

/-- Everything the revision selector runs on. -/
structure RevisionPickerData where
  revisions : Array RevisionInfo := #[]
  decls : Array RevisionPickerDecl := #[]
deriving Repr, Inhabited, ToJson, FromJson

/-! ## Reading git

Everything below shells out to `git`. It needs a working tree and no Lean environment at all, which
is why `provenance` is a phase of its own rather than part of `collect`. -/

/-- Runs `git` in `dir`, returning stdout on success and `none` on any failure.

Failure is never fatal here. A target that is not a git repository, a `git` that is not installed, a
shallow clone with no history to blame — each costs the provenance file some content, and none is a
reason to fail a build that would otherwise succeed. What each does cost is reported by the caller,
since a silently empty ledger looks exactly like a library that never changed. -/
def gitOutput? (dir : System.FilePath) (args : Array String) : IO (Option String) := do
  try
    let out ← IO.Process.output { cmd := "git", args := args, cwd := dir }
    if out.exitCode == 0 then return some out.stdout else return none
  catch _ => return none

/-- Splits on `\n`, dropping a trailing empty line. -/
def gitLines (s : String) : Array String :=
  let ls := (s.splitOn "\n").toArray
  if ls.back? == some "" then ls.pop else ls

/-- The commit `HEAD` currently points at, with the name a reader would recognize.

`git describe --tags --always` prefers a tag, which is what a released site should say; it falls
back to a short sha, which is what a site built from a working branch should say. Both are better
than a branch name, which moves. -/
def headCommit (dir : System.FilePath) : IO (Option (CommitInfo × String)) := do
  let some raw ← gitOutput? dir #["log", "-1", "--format=%H%n%h%n%ad%n%s", "--date=short"]
    | return none
  let ls := gitLines raw
  if ls.size < 3 then return none
  let subject := if ls.size > 3 then ls[3]! else ""
  let commit : CommitInfo :=
    { sha := ls[0]!, shortSha := ls[1]!, date := ls[2]!, subject := subject }
  let ref := match ← gitOutput? dir #["describe", "--tags", "--always", "--dirty="] with
    | some d => match gitLines d with
      | #[] => commit.shortSha
      | ds => let r := ds[0]!
              if r.isEmpty then commit.shortSha else r
    | none => commit.shortSha
  return some (commit, ref)

/-- Whether the working tree has uncommitted changes. -/
def isDirty (dir : System.FilePath) : IO Bool := do
  match ← gitOutput? dir #["status", "--porcelain"] with
  | some out => return !(gitLines out).isEmpty
  | none => return false

/-- The sha `git blame` uses for lines that are not in any commit. -/
def uncommittedSha : String := String.ofList (List.replicate 40 '0')

/-- Line number (1-based) ↦ the commit that last touched it, `none` for a line not yet committed.

Parses `git blame --porcelain`, which prints a commit's headers only the first time that commit
appears and thereafter just its sha — so the header table is built once and shared, rather than
re-parsed per line as `--line-porcelain` would force.

Dates are left empty here and filled in by `datesFor`. Porcelain gives `author-time` as a raw
epoch, and converting epochs to calendar dates is not something this module should be doing by
hand when `git` will do it correctly, timezones included. -/
def blameFile (dir : System.FilePath) (relPath : String)
    : IO (Std.HashMap Nat (Option CommitInfo)) := do
  let some raw ← gitOutput? dir #["blame", "--porcelain", "--", relPath] | return {}
  let mut commits : Std.HashMap String CommitInfo := {}
  let mut byLine : Std.HashMap Nat (Option CommitInfo) := {}
  let mut sha := ""
  let mut lineNo := 0
  let mut subject := ""
  for line in gitLines raw do
    if line.startsWith "\t" then
      -- The content line closes a group: whatever headers were seen belong to `sha`.
      if sha == uncommittedSha then
        byLine := byLine.insert lineNo none
      else if !sha.isEmpty then
        let info := match commits.get? sha with
          | some known => known
          | none => { sha := sha, shortSha := (sha.take 7).toString, subject := subject }
        commits := commits.insert sha info
        byLine := byLine.insert lineNo (some info)
      sha := ""; subject := ""
    else if line.startsWith "summary " then
      subject := (line.drop "summary ".length).toString
    else
      -- Either a `<sha> <orig> <final> [<count>]` header or a header this does not read.
      let parts := (line.splitOn " ").toArray
      if parts.size >= 3 && parts[0]!.length == 40 && (parts[0]!.all fun c =>
          c.isDigit || ('a' ≤ c && c ≤ 'f')) then
        sha := parts[0]!
        lineNo := (parts[2]!.toNat?).getD 0
  return byLine

/-- Fills in author dates, as `YYYY-MM-DD`, for the commits a blame produced.

Asked of `git` in batches rather than one process per commit. A batch that fails is retried one sha
at a time instead of being abandoned: `git show` fails the *whole* invocation on a single
unresolvable argument, so without the retry one odd sha would silently cost the dates of the two
hundred commits it was batched with — and a missing date renders as no date at all, which looks
like a library nobody has touched. -/
def datesFor (dir : System.FilePath) (shas : Array String) : IO (Std.HashMap String String) := do
  let shas := shas.filter fun s => !s.isEmpty && s != uncommittedSha
  if shas.isEmpty then return {}
  let readInto (acc : Std.HashMap String String) (args : Array String)
      : IO (Option (Std.HashMap String String)) := do
    match ← gitOutput? dir (#["show", "--no-patch", "--format=%H %ad", "--date=short"] ++ args) with
    | none => return none
    | some raw =>
      let mut acc := acc
      for line in gitLines raw do
        let parts := (line.splitOn " ").toArray
        if parts.size >= 2 then acc := acc.insert parts[0]! parts[1]!
      return some acc
  let mut out : Std.HashMap String String := {}
  let batchSize := 200
  let mut i := 0
  while i < shas.size do
    let batch := shas.extract i (min shas.size (i + batchSize))
    i := i + batchSize
    match ← readInto out batch with
    | some acc => out := acc
    | none =>
      for sha in batch do
        if let some acc ← readInto out #[sha] then out := acc
  return out

/-- Blame for every declaration with a recorded source range.

One `git blame` per *file*, not per declaration: the ranges are bucketed afterwards. A library of
1677 declarations lives in tens of files, and the difference is tens of subprocesses against
thousands.

The commit reported for a declaration is the newest one touching any of its lines, by date. The
signature commit is the newest touching only the lines `collect` recorded as its signature — closer
to a statement change, and still not one; see `EditInfo.signature?`. -/
def blameDeclarations (dir : System.FilePath) (decls : Array DeclInfo)
    : IO (Array (Name × EditInfo)) := do
  let mut byFile : Std.HashMap String (Array DeclInfo) := {}
  for decl in decls do
    if let some src := decl.source? then
      byFile := byFile.insert src.relPath ((byFile.getD src.relPath #[]).push decl)
  let mut blames : Std.HashMap String (Std.HashMap Nat (Option CommitInfo)) := {}
  let mut shas : Std.HashSet String := {}
  for (path, _) in byFile do
    let b ← blameFile dir path
    for (_, info?) in b do
      if let some info := info? then shas := shas.insert info.sha
    blames := blames.insert path b
  let dates ← datesFor dir shas.toArray
  let dateOf (info : CommitInfo) : CommitInfo :=
    { info with date := (dates.get? info.sha).getD info.date }
  let mut out : Array (Name × EditInfo) := #[]
  for (path, fileDecls) in byFile do
    let blame := blames.getD path {}
    for decl in fileDecls do
      let some src := decl.source? | continue
      -- Newest by date over the range, plus whether any line of it is uncommitted. `YYYY-MM-DD`
      -- compares correctly as a string, which is the reason the dates are normalized to it before
      -- they get here.
      let newestIn (from_ to_ : Nat) : Option CommitInfo × Bool := Id.run do
        let mut best : Option CommitInfo := none
        let mut pending := false
        for ln in [from_:to_ + 1] do
          match blame.get? ln with
          | some (some info) =>
            let info := dateOf info
            match best with
            | some b => if info.date > b.date then best := some info
            | none => best := some info
          | some none => pending := true
          | none => pure ()
        return (best, pending)
      let (commit?, uncommitted) := newestIn src.line src.endLine
      -- `displaySignature` is the source text down to where the body starts, so its line count is
      -- the signature's extent. One line at minimum, for a declaration written on one.
      let sigLines := max 1 (decl.displaySignature.splitOn "\n").length
      let sigEnd := min src.endLine (src.line + sigLines - 1)
      -- A declaration every line of which is uncommitted still gets an entry: "not yet committed"
      -- is exactly what a reader wants to be told, and dropping it would say nothing at all.
      if commit?.isNone && !uncommitted then continue
      out := out.push (decl.name, {
        commit := commit?.getD {}
        signature? := (newestIn src.line sigEnd).1
        uncommitted := uncommitted
      })
  return out

end Referee
