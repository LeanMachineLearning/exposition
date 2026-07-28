module

public import Referee.Collect

@[expose] public section

/-!
# Revision diff: what changed since the reader last looked

Refereeing is iterative. A reader works through a library, the author revises it, and the reader
must not start over. This module answers, for a pair of `collect` outputs, which declarations that
reader has to look at again — and, just as usefully, which they may skip.

The whole computation is a pure function of two `CollectedData` values: no environment, no source
tree, no re-import. It runs at render time, which is why the baseline is a `build-site` flag
alongside `--trust` rather than a phase of its own.

## What counts as a change

The classification is the site's existing meaning/trust split (`graphDeps`) applied across time
instead of across the dependency graph:

- a **statement change** — the declaration's elaborated type differs — invalidates any reading of
  it;
- a **body change** invalidates a reading only where the body *is* the meaning, i.e. for everything
  that is not a theorem (`DeclInfo.bodyIsMeaning`). A definition's body is what it means; a
  theorem's proof was rechecked by the kernel and tells a reader nothing new;
- an **indirect invalidation** is the case this module exists for. A theorem whose own statement is
  untouched, but whose statement mentions a definition that changed, now *means* something
  different while looking byte-identical. No textual diff of the repository can show that. Closing
  the changed set over `transDeps` — which already follows `graphDeps` — finds it exactly;
- a **proof-only change** needs no re-reading at all, and saying so is half the point: it is where
  the bulk of any real revision lands.

Changes propagate only from meaning changes. An *added* declaration cannot invalidate an unchanged
one — if some statement mentions it, that statement changed too — and the same argument covers
removals, so neither needs closing over.

## What it compares on

Preferably, **semantic hashes** — `DeclInfo.proofIrrelHash?` and `DeclInfo.semanticHash?`, collected
from `semantic_hash export` when `collect --hashes` was given. They are structural hashes of the
elaborated `Expr`, and they have three properties nothing derived from text has:

- they are unaffected by how anything *prints*, so a toolchain upgrade cannot make the diff report
  a library it did not touch;
- they are *deep* — a referenced constant contributes its own hash — so a declaration's hash moves
  when the meaning of anything in its closure moves, upstream included;
- the proof-irrelevant variant hides theorem bodies, which is `graphDeps` arrived at independently:
  a theorem's proof-irrelevant hash rests on its statement's closure and on nothing its proof
  merely calls.

So `proofIrrelHash` differing *is* "this needs re-reading", and `semanticHash` differing while
`proofIrrelHash` does not *is* "only a proof changed" — the two questions this module exists to
answer, decided at the level of terms instead of inferred from strings.

What a hash cannot do is say *why*. It reports that the meaning moved, never where, so the textual
keys below stay on, demoted from deciding whether something changed to explaining what did:

- `expandedSignature`, the pretty-printed elaborated type, splits a *direct* statement change from
  one inherited from a dependency — the hash cannot tell them apart, because it deliberately
  conflates a declaration with its closure;
- `proofText?` / `displaySignature` do the same for a definition's body.

When the hash moved and neither text did, the cause is outside the exposed declarations: an
upstream package, or project code this site does not show. That is `ChangeKind.upstream`, and it
is a finding the previous text-only comparison could not make at all.

## Without hashes

Everything still works, per declaration: a pair where either side lacks a hash falls back to
comparing `expandedSignature` and body text, exactly as this module did before hashes existed, so
an old baseline or a project that never ran `semantic_hash` degrades rather than breaks. Both
comparisons normalize whitespace first, because neither pretty-printed output nor source text is
stable enough to compare raw.

The text path's residual risk is stated rather than hidden: a toolchain upgrade can change how
*every* type pretty-prints, and the diff would then report the whole library as changed.
`DiffReport.looksLikeToolchainChurn` recognizes that shape so the page can say so instead of
presenting it as the author's doing. It is checked only where text was actually used — with hashes
on both sides the failure cannot occur, since a repretty-printed statement whose hash is unmoved is
classified `unchanged` and never reaches the page.

The text path also over-reports on bodies. Whitespace normalization covers reindentation, but not
any other way of writing the same term: renaming a bound variable inside a definition, or adding a
comment to it, reads as a different definition. Because a body change propagates along the closure,
that false positive does not stay put — one renamed lambda binder can invalidate every theorem
stated about the definition. It is the safe direction, a page of extra reading against a missed
invalidation, and it is the single largest thing hashes remove.

## Collisions

A semantic hash is 64 bits, so two different meanings can in principle collide, and the
consequence is a *missed* invalidation: the one direction every other approximation here avoids.
For a library of a few thousand declarations the probability is on the order of `10⁻¹³`. It is
reported on the page rather than left implicit, because a reader is entitled to know which way the
tool fails.
-/

open Lean

namespace Referee

/-- How one declaration changed relative to the baseline.

Removals are not here: a removed declaration has no `DeclInfo` in the current data to hang a change
off, so they are carried separately as `RemovedDecl`. -/
inductive ChangeKind where
  /-- Not present in the baseline. -/
  | added
  /-- Its elaborated type differs from the baseline's. -/
  | statementChanged
  /-- Its type is unchanged, but its body differs and its body is part of its meaning. -/
  | bodyChanged
  /-- Unchanged itself, but a *project* declaration its statement rests on changed meaning. -/
  | indirect
  /-- Its meaning moved and nothing this site shows accounts for it: the cause is an upstream
  package, or project code that is not exposed.

  Only reachable when both revisions carry semantic hashes, because only a deep hash sees past the
  project boundary. The text comparison cannot produce this and cannot detect what it reports. -/
  | upstream
  /-- Only a proof changed, which the kernel has already rechecked. -/
  | proofOnly
  | unchanged
deriving Repr, BEq, Inhabited, ToJson, FromJson

/-- Machine-readable tag, used as a CSS hook and as the Browse table's filter value. -/
def ChangeKind.slug : ChangeKind → String
  | .added => "added"
  | .statementChanged => "statement"
  | .bodyChanged => "body"
  | .indirect => "indirect"
  | .upstream => "upstream"
  | .proofOnly => "proof"
  | .unchanged => "unchanged"

/-- Reader-facing label. Phrased as what happened, not as a severity, so that the ordering of the
page is what conveys urgency. -/
def ChangeKind.label : ChangeKind → String
  | .added => "new"
  | .statementChanged => "statement changed"
  | .bodyChanged => "definition changed"
  | .indirect => "meaning changed indirectly"
  | .upstream => "meaning changed underneath"
  | .proofOnly => "proof changed"
  | .unchanged => "unchanged"

/-- Whether a reader who accepted this declaration in the baseline has to look at it again.

`proofOnly` is false, and that is the useful half: the kernel rechecked the proof, and a proof
cannot change what a theorem says. -/
def ChangeKind.needsReaudit : ChangeKind → Bool
  | .added | .statementChanged | .bodyChanged | .indirect | .upstream => true
  | .proofOnly | .unchanged => false

/-- Whether this declaration's meaning moved, and so whether it can be named as the cause of an
indirect invalidation further up.

`upstream` counts. Its own cause lies outside the exposed declarations, but its meaning moved all
the same, so a theorem whose statement is about it has moved too — and naming *it* as the cause is
far more use to a reader than repeating "something upstream". -/
def ChangeKind.movedMeaning : ChangeKind → Bool
  | .statementChanged | .bodyChanged | .upstream => true
  | .added | .indirect | .proofOnly | .unchanged => false

/-- Whether the propagation pass may reclassify this as an indirect invalidation, on finding a
project declaration in its statement closure whose meaning moved.

`upstream` is here as well as in `movedMeaning`: a declaration can be told that its meaning moved
by the hash and then have the proximate cause found among the project's own declarations, which is
the strictly better answer and so replaces it. -/
def ChangeKind.attributable : ChangeKind → Bool
  | .unchanged | .proofOnly | .upstream => true
  | .added | .statementChanged | .bodyChanged | .indirect => false

/-! ## Comparison keys -/

/-- Splits on whitespace, dropping empty runs.

Deliberately not a Lean tokenizer: this drives both the comparison keys and a visual diff, and a
whitespace split is what lines up with how a reader scans a signature. -/
def statementTokens (s : String) : Array String :=
  let (toks, cur) := s.foldl (init := ((#[] : Array String), "")) fun (toks, cur) c =>
    if c.isWhitespace then (if cur.isEmpty then (toks, "") else (toks.push cur, ""))
    else (toks, cur.push c)
  if cur.isEmpty then toks else toks.push cur

/-- Collapses every run of whitespace to a single space and trims the ends.

Applied before any comparison, because neither pretty-printed output nor source text is stable
enough at that level of detail to compare raw: a line break moving is not a change a referee needs
to hear about. -/
def normalizeSpace (s : String) : String :=
  String.intercalate " " (statementTokens s).toList

/-- The key a statement is compared on: the elaborated type, whitespace-normalized. -/
def statementKey (decl : DeclInfo) : String :=
  normalizeSpace decl.expandedSignature

/-- The key a body is compared on.

`proofText?` holds the value for the kinds that have one recorded separately (theorems, opaques,
instances); for a definition or a structure the body lives inside `displaySignature`, which is the
whole command as written. Source text, for want of anything better — see the note on over-reporting
in the module docstring. -/
def bodyKey (decl : DeclInfo) : String :=
  normalizeSpace (decl.proofText?.getD decl.displaySignature)

/-- Whether both revisions of a declaration carry semantic hashes, and so can be compared on
meaning rather than on how they print.

Both hashes are required on both sides. `semantic_hash export` always emits the pair, so a
declaration carrying one and not the other is pathological rather than partial, and comparing it on
text is the answer that cannot be quietly wrong. -/
def comparableByHash (old new : DeclInfo) : Bool :=
  old.semanticHash?.isSome && new.semanticHash?.isSome &&
    old.proofIrrelHash?.isSome && new.proofIrrelHash?.isSome

/-- The key an added declaration is matched against a removed one on, to offer a rename as evidence.

Tagged with which measure produced it so the two keyspaces cannot meet: a semantic hash matches
across a rename *and* across renames of everything the statement mentions, which is a materially
stronger piece of evidence than two statements happening to pretty-print alike, and the two should
never be silently interchanged. Where one side has hashes and the other does not, the lookup simply
misses and no rename is claimed — the safe direction, since the claim is the risky part. -/
def renameKey (decl : DeclInfo) : String :=
  match decl.proofIrrelHash? with
  | some h => "h:" ++ h
  | none => "s:" ++ statementKey decl

/-! ## Token-level statement diff

A statement change is read, not skimmed, and a reader should not have to spot the difference
between two nearly identical lines of Lean by eye. So the two statements are aligned token by token
and the page marks what went and what arrived. -/

/-- One token of an aligned statement diff. -/
structure DiffToken where
  text : String
  /-- `"same"`, `"del"` (baseline only) or `"ins"` (current only). -/
  kind : String
deriving Repr, Inhabited, ToJson, FromJson

/-- An aligned pair of statements. -/
structure StatementDiff where
  tokens : Array DiffToken := #[]
  /-- True when the statements were too long to align token by token and the common prefix and
  suffix were used instead. Reported rather than hidden: the coarse rendering marks a whole region
  as changed where the exact one would have marked a word. -/
  coarse : Bool := false
deriving Repr, Inhabited, ToJson, FromJson

/-- Above this many tokens on either side, alignment falls back to prefix/suffix trimming.

The alignment is quadratic. Statements are tens of tokens, so the bound is never reached in
practice; it exists so that one pathological signature cannot stall a site build. -/
def maxAlignTokens : Nat := 256

/-- Longest-common-subsequence alignment of two token arrays. -/
def alignTokens (xs ys : Array String) : Array DiffToken := Id.run do
  let n := xs.size
  let m := ys.size
  let width := m + 1
  -- `table[i * width + j]` is the LCS length of `xs[i:]` and `ys[j:]`, filled from the end so the
  -- forward walk below can pick the branch that keeps the most tokens aligned.
  let mut table : Array Nat := Array.replicate ((n + 1) * width) 0
  for di in [0:n] do
    let i := n - 1 - di
    for dj in [0:m] do
      let j := m - 1 - dj
      let v :=
        if xs[i]! == ys[j]! then table[(i + 1) * width + (j + 1)]! + 1
        else max table[(i + 1) * width + j]! table[i * width + (j + 1)]!
      table := table.set! (i * width + j) v
  let mut out : Array DiffToken := #[]
  let mut i := 0
  let mut j := 0
  while i < n && j < m do
    if xs[i]! == ys[j]! then
      out := out.push { text := xs[i]!, kind := "same" }
      i := i + 1
      j := j + 1
    else if table[(i + 1) * width + j]! >= table[i * width + (j + 1)]! then
      out := out.push { text := xs[i]!, kind := "del" }
      i := i + 1
    else
      out := out.push { text := ys[j]!, kind := "ins" }
      j := j + 1
  while i < n do
    out := out.push { text := xs[i]!, kind := "del" }
    i := i + 1
  while j < m do
    out := out.push { text := ys[j]!, kind := "ins" }
    j := j + 1
  return out

/-- The fallback for statements too long to align: keep the common prefix and suffix, mark
everything between them as removed and then added. -/
def trimTokens (xs ys : Array String) : Array DiffToken := Id.run do
  let mut pre := 0
  while pre < xs.size && pre < ys.size && xs[pre]! == ys[pre]! do
    pre := pre + 1
  let mut suf := 0
  while suf < xs.size - pre && suf < ys.size - pre
      && xs[xs.size - 1 - suf]! == ys[ys.size - 1 - suf]! do
    suf := suf + 1
  let mut out : Array DiffToken := #[]
  for k in [0:pre] do
    out := out.push { text := xs[k]!, kind := "same" }
  for k in [pre:xs.size - suf] do
    out := out.push { text := xs[k]!, kind := "del" }
  for k in [pre:ys.size - suf] do
    out := out.push { text := ys[k]!, kind := "ins" }
  for k in [xs.size - suf:xs.size] do
    out := out.push { text := xs[k]!, kind := "same" }
  return out

/-- Aligns two statements for display. -/
def statementDiff (old new : String) : StatementDiff :=
  let xs := statementTokens old
  let ys := statementTokens new
  if xs.size > maxAlignTokens || ys.size > maxAlignTokens then
    { tokens := trimTokens xs ys, coarse := true }
  else
    { tokens := alignTokens xs ys }

/-! ## The report -/

/-- What changed about one declaration that exists in the current data.

The trust deltas are carried alongside the change kind rather than folded into it, because they are
independent: a declaration can gain a `sorry` without its statement moving, and a statement can
change without any trust consequence at all. -/
structure DeclChange where
  name : Name
  kind : ChangeKind
  /-- The baseline's statement, kept only when it differs. -/
  oldStatement? : Option String := none
  /-- For `indirect`: the declarations in this one's statement closure whose meaning changed.
  Empty for every other kind. -/
  causes : Array Name := #[]
  /-- Its closure did not rest on a `sorry` in the baseline and does now. -/
  gainedSorry : Bool := false
  /-- It rested on a `sorry` in the baseline and no longer does. -/
  lostSorry : Bool := false
  /-- Axioms its closure has acquired, `sorryAx` excluded (that is `gainedSorry`). -/
  gainedAxioms : Array Name := #[]
  /-- Axioms its closure no longer rests on. -/
  lostAxioms : Array Name := #[]
  /-- A definition that had no `@[specifies]` theorem in the baseline and has one now. -/
  gainedSpec : Bool := false
  /-- A definition whose specification was removed: the gap is new, and invisible otherwise. -/
  lostSpec : Bool := false
deriving Repr, Inhabited, ToJson, FromJson

/-- Whether anything about this declaration's trust surface moved, in either direction. -/
def DeclChange.trustMoved (c : DeclChange) : Bool :=
  c.gainedSorry || c.lostSorry || !c.gainedAxioms.isEmpty || !c.lostAxioms.isEmpty
    || c.gainedSpec || c.lostSpec

/-- Whether this change is worth showing on the declaration's own page. -/
def DeclChange.isNoteworthy (c : DeclChange) : Bool :=
  c.kind != .unchanged || c.trustMoved

/-- A declaration the baseline had and the current data does not.

Carries its own copy of what the reader needs, since there is no `DeclInfo` left to look it up
in. -/
structure RemovedDecl where
  name : Name
  modulePath : String
  /-- Its statement in the baseline, source form: nothing is being aligned against it, so what a
  reader wants is what the author wrote rather than the elaborated type. -/
  statement : String
  /-- It was written with the `theorem` keyword, so what was withdrawn is a *claim* rather than
  machinery — the one removal a referee always wants to see. -/
  wasClaim : Bool := false
deriving Repr, Inhabited, ToJson, FromJson

/-- Everything that changed between two `collect` outputs. -/
structure DiffReport where
  /-- What to call the baseline on the page. -/
  baselineLabel : String := ""
  oldCount : Nat := 0
  newCount : Nat := 0
  /-- One entry per declaration in the current data, `unchanged` ones included, so that the site can
  look any declaration up without deciding in advance which it will need. -/
  changes : Array DeclChange := #[]
  removed : Array RemovedDecl := #[]
  /-- Removed/added pairs that compare equal under `renameKey`, offered as evidence that a
  declaration was renamed. Not merged into a single "renamed" entry: the tool cannot see intent, and
  two declarations sharing a meaning is a fact, not a conclusion. -/
  renamed : Array (Name × Name) := #[]
  /-- Declarations present in both revisions, i.e. how many comparisons were made at all. -/
  comparisons : Nat := 0
  /-- How many of those were made on semantic hashes rather than on text.

  Kept so the page can name the measure it used. A reader deciding how much of a Changes page to
  believe needs to know whether "unchanged" means *the term is the same term* or *it printed the
  same way*, and those are not equally strong claims. -/
  hashedComparisons : Nat := 0
deriving Repr, Inhabited, ToJson, FromJson

/-- Whether any comparison in this report was made on semantic hashes. -/
def DiffReport.usedHashes (report : DiffReport) : Bool :=
  report.hashedComparisons > 0

/-- Whether *every* comparison was made on semantic hashes.

The condition under which the page's claims are the strong ones, and under which
`looksLikeToolchainChurn` cannot fire. -/
def DiffReport.fullyHashed (report : DiffReport) : Bool :=
  report.comparisons > 0 && report.hashedComparisons == report.comparisons

/-- Declaration name ↦ its change, for the site's per-declaration lookups. -/
def DiffReport.byName (report : DiffReport) : Std.HashMap Name DeclChange :=
  report.changes.foldl (fun acc c => acc.insert c.name c) {}

/-- The changes of one kind, in the order the declarations were collected. -/
def DiffReport.ofKind (report : DiffReport) (kind : ChangeKind) : Array DeclChange :=
  report.changes.filter (·.kind == kind)

/-- Declarations a reader who worked through the baseline has to return to. -/
def DiffReport.needingReaudit (report : DiffReport) : Array DeclChange :=
  report.changes.filter (·.kind.needsReaudit)

/-- Whether anything at all is different. -/
def DiffReport.isEmpty (report : DiffReport) : Bool :=
  report.removed.isEmpty && !report.changes.any (·.isNoteworthy)

/-- Whether the diff has the shape a *toolchain* change produces rather than an author's edit:
nearly every surviving declaration's statement reported as changed at once.

Worth recognizing because the failure is otherwise silent and total. Where statements are compared
as pretty-printed elaborated types, a Lean upgrade can change how every type prints; the page then
tells the reader to re-audit the entire library, which is both useless and wrong. A tool that asks
to be trusted has to say when its own measure has stopped meaning anything.

Gated on `fullyHashed`, because with semantic hashes on both sides the failure cannot happen: a
repretty-printed statement whose hash is unmoved is classified `unchanged` and never reaches the
page. Running the heuristic anyway would mean warning about a risk the comparison no longer takes.

The threshold is deliberately high. Real revisions do not touch four-fifths of the statements in a
library, and a project small enough for that to happen by hand (under 50 declarations) is one where
the reader can see the whole diff anyway. -/
def DiffReport.looksLikeToolchainChurn (report : DiffReport) : Bool :=
  let survivors := report.changes.filter (·.kind != .added)
  !report.fullyHashed &&
    survivors.size >= 50 &&
    (report.ofKind .statementChanged).size * 5 >= survivors.size * 4

/-! ## Render payloads

The site renders a change in two places — one row of the Changes page, and a banner at the top of
the declaration's own page — and both want the same fields, so both take a `ChangeRowData`. -/

/-- One rendered change: everything the page shows about a single declaration. -/
structure ChangeRowData where
  name : String
  /-- Empty for a removed declaration, which has no page left to link to. -/
  href : String := ""
  module : String := ""
  /-- `ChangeKind.slug`, used as a CSS hook. -/
  kind : String
  /-- `ChangeKind.label`. -/
  label : String
  /-- The aligned statements. Empty unless the statement changed. -/
  diff : StatementDiff := {}
  /-- The statement, shown whole where there is no baseline version to align against (an added or
  a removed declaration). -/
  statement : String := ""
  /-- What its meaning now rests on that moved. Non-empty only for an indirect invalidation. -/
  causes : Array LinkInfo := #[]
  /-- Trust deltas, phrased for a reader: "now rests on a sorry", "gained axiom `foo`". -/
  trustNotes : Array String := #[]
  /-- How many declarations rest on this one — the size of the re-reading it forces. -/
  dependents : Nat := 0
  /-- What the comparison is against, for the banner on a declaration page, which is read on its own
  and so has to name the baseline itself. Empty on the Changes page, which says it once at the top. -/
  since : String := ""
deriving Repr, Inhabited, ToJson, FromJson

/-- Data container for a list of rendered changes. -/
structure ChangeListData where
  entries : Array ChangeRowData
deriving Repr, Inhabited, ToJson, FromJson

/-- Trust deltas phrased for a reader, in the order they should be read. -/
def DeclChange.trustNotes (c : DeclChange) : Array String := Id.run do
  let mut notes : Array String := #[]
  if c.gainedSorry then notes := notes.push "now rests on a sorry"
  if c.lostSorry then notes := notes.push "no longer rests on a sorry"
  for a in c.gainedAxioms do notes := notes.push s!"new axiom: {a}"
  for a in c.lostAxioms do notes := notes.push s!"no longer rests on axiom: {a}"
  if c.lostSpec then notes := notes.push "its specification was removed"
  if c.gainedSpec then notes := notes.push "it gained a specification"
  return notes

/-! ## Computing the diff -/

/-- The axioms a declaration rests on beyond `sorryAx`, which `dependsOnSorry` already reports. -/
def axiomSet (decl : DeclInfo) : Std.HashSet Name :=
  decl.axioms.foldl (init := {}) fun acc a => if a == ``sorryAx then acc else acc.insert a

/-- The change to one declaration that exists in both revisions, before the propagation pass.

Two paths, chosen per declaration by `comparableByHash`.

**With hashes**, the hash decides *whether* the meaning moved and the text decides *where*. The
order matters: because the hash is deep, a declaration whose dependency moved has a different hash
while being character-for-character identical, so the text is consulted only after the hash has
already said there is something to explain. This is what makes a toolchain upgrade a non-event —
every statement prints differently, no hash moves, and every declaration comes out `unchanged`.

**Without hashes**, the original text comparison, unchanged: `expandedSignature` for the statement
and source text for the body, with indirect invalidation left entirely to the propagation pass. -/
def directKind (old new : DeclInfo) : ChangeKind :=
  if comparableByHash old new then
    if old.proofIrrelHash? == new.proofIrrelHash? then
      -- The proposition is the same term it was. Anything left is a proof, which the kernel has
      -- already rechecked.
      if old.semanticHash? == new.semanticHash? then .unchanged else .proofOnly
    else if statementKey old != statementKey new then .statementChanged
    else if new.bodyIsMeaning && bodyKey old != bodyKey new then .bodyChanged
    -- The meaning moved and this declaration's own text did not, so the cause is elsewhere.
    -- Provisional: the propagation pass replaces this with `indirect` if the cause turns out to be
    -- a project declaration, and only what is left over is genuinely from outside.
    else .upstream
  else if statementKey old != statementKey new then .statementChanged
  else if bodyKey old == bodyKey new then .unchanged
  else if new.bodyIsMeaning then .bodyChanged
  else .proofOnly

/-- Diffs two `collect` outputs.

`baselineLabel` is what the site calls the baseline; the caller passes something a reader
recognizes, such as the file name or a version. -/
def diff (old new : CollectedData) (baselineLabel : String := "") : DiffReport := Id.run do
  let oldByName : Std.HashMap Name DeclInfo :=
    old.decls.foldl (fun acc d => acc.insert d.name d) {}
  let newNames : Std.HashSet Name :=
    new.decls.foldl (fun acc d => acc.insert d.name) {}
  -- Pass one: the changes each declaration shows on its own.
  let mut changes : Array DeclChange := #[]
  let mut meaningChanged : Std.HashSet Name := {}
  let mut comparisons := 0
  let mut hashedComparisons := 0
  for decl in new.decls do
    match oldByName.get? decl.name with
    | none =>
      changes := changes.push { name := decl.name, kind := .added }
    | some prev =>
      comparisons := comparisons + 1
      if comparableByHash prev decl then
        hashedComparisons := hashedComparisons + 1
      let kind := directKind prev decl
      if kind.movedMeaning then
        meaningChanged := meaningChanged.insert decl.name
      let prevAxioms := axiomSet prev
      let currAxioms := axiomSet decl
      changes := changes.push {
        name := decl.name
        kind := kind
        oldStatement? := if kind == .statementChanged then some prev.expandedSignature else none
        gainedSorry := decl.dependsOnSorry && !prev.dependsOnSorry
        lostSorry := prev.dependsOnSorry && !decl.dependsOnSorry
        gainedAxioms := (currAxioms.toArray.filter (!prevAxioms.contains ·)).qsort Name.lt
        lostAxioms := (prevAxioms.toArray.filter (!currAxioms.contains ·)).qsort Name.lt
        -- Only for the declarations a specification can be about, so that a theorem losing its
        -- own `@[specifies]` annotation is not reported as a definition losing its specification.
        gainedSpec := decl.isDefinitionLike && prev.specifiedBy.isEmpty && !decl.specifiedBy.isEmpty
        lostSpec := decl.isDefinitionLike && !prev.specifiedBy.isEmpty && decl.specifiedBy.isEmpty
      }
  -- Pass two: propagate meaning changes along the statement closure. `transDeps` already follows
  -- `graphDeps`, so this reaches exactly what a declaration's meaning rests on and stops before
  -- everything its proofs merely call.
  let declByName : Std.HashMap Name DeclInfo :=
    new.decls.foldl (fun acc d => acc.insert d.name d) {}
  if !meaningChanged.isEmpty then
    changes := changes.map fun change =>
      if !change.kind.attributable then change
      else
        match declByName.get? change.name with
        | none => change
        | some decl =>
          let causes := decl.transDeps.filter meaningChanged.contains
          if causes.isEmpty then change
          else { change with kind := .indirect, causes := causes }
  -- Removals, and the added declarations that match one.
  let addedByStatement : Std.HashMap String Name :=
    new.decls.foldl (init := {}) fun acc d =>
      if oldByName.contains d.name then acc else acc.insert (renameKey d) d.name
  let mut removed : Array RemovedDecl := #[]
  let mut renamed : Array (Name × Name) := #[]
  for decl in old.decls do
    if newNames.contains decl.name then continue
    removed := removed.push {
      name := decl.name
      modulePath := decl.modulePath
      statement := if decl.displaySignature.isEmpty then decl.expandedSignature
        else decl.displaySignature
      wasClaim := decl.isClaim
    }
    if let some newName := addedByStatement.get? (renameKey decl) then
      renamed := renamed.push (decl.name, newName)
  return {
    baselineLabel := baselineLabel
    oldCount := old.decls.size
    newCount := new.decls.size
    changes := changes
    removed := removed
    renamed := renamed
    comparisons := comparisons
    hashedComparisons := hashedComparisons
  }

end Referee
