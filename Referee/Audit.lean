module

public import Referee.Collect
public import Referee.Diff

@[expose] public section

/-!
# Audit state: the referee's own work, as data

Every other measure on the site is derived from the environment. This one is not derived from
anything: it records what a *reader* has decided, declaration by declaration, and computes what
follows from those decisions.

## What "accepted" is taken to mean

The tempting design is one checkbox per declaration meaning "done", and it produces a number that
lies. A reader who accepts a regret bound without reading `IsAlgEnvSeq` has accepted a sentence,
not a theorem.

So a declaration carries two things, and only one of them is the reader's to set:

- a **verdict** — *unread*, *accepted*, or *query* — where accepted means "I read this and it says
  what its name claims", and a query carries the reader's note;
- **coverage**, which is derived: accepted, *and* every project declaration in its statement closure
  accepted too.

The state worth having a name for is the third one this produces, `accepted but not covered`: a
reader who believes they are finished and is not. Nothing else on the site can say it, and it falls
straight out of `transDeps`, which already follows `graphDeps` and is already topologically ordered.

Deliberately orthogonal to trust. A `sorry`, an axiom or an unaudited package never blocks
acceptance: accepting is a judgement about what a statement *means*, and whether it is *proved* is
what the trust page is for. Conflating them would make the checklist useless on any library with a
live `sorry` — which is to say, on any library still being written.

## Where the state lives

In the browser, and in a file the reader owns. The site is static HTML with no server, so there is
nowhere else it *could* live; and since a work aid that evaporates with a cleared browser profile is
not a work aid, export is a first-class action rather than an afterthought. See `assets/audit.js`.

This module is only the Lean half: the data each page hands to that script, plus the fingerprint
that lets an imported file recognize the build it was made against.
-/

open Lean

namespace Referee

/-- What a verdict is recorded *against*: the declaration's proof-irrelevant semantic hash.

A reader accepts a declaration as it stood when they read it. Recording that alongside the verdict
makes an exported audit file **self-baselining**: any later build can compare what the reader
accepted against what the declaration now means, and say so, without needing the old `data.json`
that `--baseline` requires. It is the difference between "this file was made against some other
build" and "these eleven of your acceptances are of something else now".

Empty when the build has no semantic hashes, and that emptiness switches the whole check off. The
fallback used elsewhere — `statementKey`, the pretty-printed elaborated type — is deliberately
*not* used here. A toolchain upgrade repretty-prints every statement in a library at once, which
under this check would mark every acceptance in the file stale; a feature whose failure mode is
telling a reader that all of their work is void is worse than no feature. So it exists only where
the measure can carry it, on the same gating discipline as `usesSpecs` and `--baseline`. -/
def meaningKeyOf (decl : DeclInfo) : String :=
  decl.proofIrrelHash?.getD ""

/-- One declaration, as the audit page needs it.

`closure` holds *indices into `AuditData.names`* rather than names. The closures of a library this
size repeat the same few hundred strings tens of thousands of times — brownian-motion has 116,519
transitive edges — and shipping them as strings put megabytes of duplicated text on one page. -/
structure AuditDecl where
  /-- Reader-facing kind (`displayKindLabel`). -/
  kind : String
  /-- `definition` / `lemma` / `theorem`, matching the sidebar's visibility toggles. -/
  group : String
  module : String
  href : String
  /-- Stated with the `theorem` keyword: one of the library's claims, and so a starting point for a
  reading queue rather than a step in one. -/
  claim : Bool
  /-- Its closure rests on a `sorry`. Reported alongside coverage, never folded into it. -/
  sorryDep : Bool
  /-- A definition with no `@[specifies]` theorem, for the generated report. `false` for anything a
  specification cannot be about. -/
  unspecified : Bool
  /-- How it changed since the baseline (`ChangeKind.slug`), or empty without one. What lets an
  imported file say which of its acceptances a revision has voided. -/
  change : String := ""
  /-- What this declaration means now (`meaningKeyOf`), for comparison against what a verdict was
  recorded against. Empty on a build without semantic hashes, which switches the check off. -/
  meaning : String := ""
  /-- Indices into `AuditData.names`: the project declarations this one's *statement* rests on, in
  dependency order, so a reading queue can be walked from the bottom up. -/
  closure : Array Nat := #[]
deriving Repr, Inhabited, ToJson, FromJson

/-- Everything the audit page needs, in one payload.

Emitted on that page alone. A declaration page gets `AuditControlData` instead, which carries only
its own closure — the whole table is a few hundred kilobytes and there are thousands of declaration
pages. -/
structure AuditData where
  project : String
  /-- Identifies the collected data this was built from; see `dataFingerprint`. -/
  dataId : String
  /-- Declaration names, indexed by `AuditDecl.closure`. Parallel to `decls`. -/
  names : Array String
  decls : Array AuditDecl
  /-- Removed/added pairs with identical statements, from the revision diff. Lets an import offer to
  carry a verdict across what looks like a rename, rather than silently dropping it. -/
  renamed : Array (String × String) := #[]
  /-- What the site was compared against, empty when it was built without `--baseline`. -/
  baselineLabel : String := ""
deriving Repr, Inhabited, ToJson, FromJson

/-- The payload on a single declaration's page: enough to set a verdict and to say what reading it
still leaves uncovered, without shipping the whole library. -/
structure AuditControlData where
  name : String
  /-- Repeated on every declaration page because it is the storage key, and a declaration page is
  reachable without ever loading the audit page. -/
  project : String := ""
  /-- The project declarations its statement rests on, with links. Dependency-ordered. -/
  closure : Array LinkInfo := #[]
  /-- What this declaration means now (`meaningKeyOf`), recorded alongside any verdict set here. -/
  meaning : String := ""
  /-- The same, for each entry of `closure`, positionally.

  A parallel array rather than a field on `LinkInfo`, which is shared with half the site and has no
  business knowing about audit state. It is needed because the bulk action — *accept this and
  everything its statement rests on* — sets verdicts for declarations other than this one, and a
  verdict recorded without a meaning can never be checked for staleness afterwards. -/
  closureMeanings : Array String := #[]
deriving Repr, Inhabited, ToJson, FromJson

/-- A fingerprint of the collected declarations: their names paired with what they meant.

Stamped into an exported audit file so that re-importing it somewhere else can say whether it was
made against this build. Deliberately covers statements and not proofs — re-proving a theorem does
not invalidate a reader's acceptance of it, for the same reason the revision diff collapses
proof-only changes.

Uses each declaration's proof-irrelevant semantic hash where the build has one, and falls back to
`statementKey` where it does not. That is the same preference `Referee.Diff` makes and for the same
reason: without it, a toolchain upgrade repretty-prints every type and an audit file made the day
before stops recognizing the build it was made against, reporting a library nobody touched as
entirely unread. Names are still mixed in, so this identifies a *build* rather than a meaning.

Not a cryptographic hash and not trying to be: it distinguishes builds, it does not authenticate
them. Nothing in the audit file is authenticated — see the note on that in `assets/audit.js`. -/
def dataFingerprint (decls : Array DeclInfo) : String :=
  let h := decls.foldl (init := (0xcbf29ce484222325 : UInt64)) fun acc decl =>
    let meaning := decl.proofIrrelHash?.getD (statementKey decl)
    mixHash acc (hash (decl.name.toString ++ "\x00" ++ meaning))
  hex16 h

end Referee
