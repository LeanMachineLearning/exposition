module

public import Referee.Audit
-- The checks below are `#guard`s, which Lean elaborates into compile-time (`meta`) definitions, so
-- the declarations under test have to be imported at that level too.
meta import Referee.Audit

@[expose] public section

/-!
# Tests for `Referee.Audit`

Most of the audit feature is the browser's: verdicts, coverage, the reading queue, import and
export all live in `assets/audit.js`, and none of it can be `#guard`ed here.

What *is* Lean's, and what this covers, is `dataFingerprint` — the stamp an exported audit file
carries so that re-importing it elsewhere can say whether it was made against this build. Its two
properties are both worth pinning, because getting either wrong is silent:

* it must change when a statement changes, or a file made against the old library would claim to
  match the new one;
* it must **not** change when only a proof changes, for the same reason the revision diff collapses
  proof-only changes — re-proving a theorem does not invalidate a reader's acceptance of it, and a
  fingerprint that moved anyway would make every rebuild look like a new library.

Run with `lake build Test`.
-/

open Lean Std
open Referee

namespace Referee.Test.Audit

private def mkDecl (name : Name) (statement : String := "True") (body : String := "trivial")
    (kind : DeclKind := .theorem) : DeclInfo := {
  name := name
  moduleName := `Test.Mod
  modulePath := "Mod"
  groupKey := "Mod"
  kind := kind
  displaySignature := body
  expandedSignature := statement
  docBlocks := #[]
  proofText? := some body
  source? := none
  deps := #[]
}

private def base : Array DeclInfo :=
  #[mkDecl `A (statement := "P") (body := "by simp"),
    mkDecl `B (statement := "Q") (body := "by omega")]

/-! ## The fingerprint -/

-- Deterministic: the same declarations always give the same stamp, or an exported file could never
-- be matched against the build it came from.
#guard dataFingerprint base == dataFingerprint base

-- Fixed width and hexadecimal, so it reads as an identifier rather than as a number.
#guard (dataFingerprint base).length == 16
#guard (dataFingerprint base).all fun c => c.isDigit || ('a' ≤ c && c ≤ 'f')

-- A changed statement is a different library as far as an audit file is concerned.
#guard dataFingerprint base
  != dataFingerprint #[mkDecl `A (statement := "P'") (body := "by simp"),
                       mkDecl `B (statement := "Q") (body := "by omega")]

-- A changed *proof* is not. The kernel rechecked it, and nobody's acceptance of the statement is
-- affected — the same argument the Changes page makes for collapsing proof-only changes.
#guard dataFingerprint base
  == dataFingerprint #[mkDecl `A (statement := "P") (body := "by norm_num"),
                       mkDecl `B (statement := "Q") (body := "by positivity")]

-- Reformatting a statement is not a change either: the fingerprint compares the same
-- whitespace-normalized key the revision diff does.
#guard dataFingerprint #[mkDecl `A (statement := "∀ n,  P n")]
  == dataFingerprint #[mkDecl `A (statement := "∀ n,\n  P n")]

-- Renaming a declaration is, since a verdict is recorded against a name.
#guard dataFingerprint base != dataFingerprint #[mkDecl `A' (statement := "P") (body := "by simp"),
                                                 mkDecl `B (statement := "Q") (body := "by omega")]

-- Adding a declaration changes it, so a file made before an addition is recognizably older.
#guard dataFingerprint base != dataFingerprint (base.push (mkDecl `C))

/-! ## Payload shapes

Only that the defaults are the inert ones — a project that has never been audited must serialize as
"nothing recorded" rather than as an empty claim about something. -/

#guard (default : AuditDecl).closure.isEmpty
#guard (default : AuditDecl).change == ""
#guard (default : AuditData).renamed.isEmpty
#guard (default : AuditData).baselineLabel == ""
-- The default is the whole library with its apparatus, not an excerpt: an excerpt is the special
-- case and has to be asked for, or a payload built without thinking about it would silently
-- suppress the progress summary, the queries and export.
#guard !(default : AuditData).excerpt
#guard (default : AuditControlData).closure.isEmpty

/-! ## Claims listing

A row says how many of the enclosing block's contents are its own docstring, and the renderer walks
rows and contents in step. A default that claimed any would make a row with no docstring eat the
next row's. -/

#guard (default : ClaimRow).docLength == 0
#guard !(default : ClaimRow).dependsOnSorry
#guard (default : ClaimListData).rows.isEmpty
-- A fold is shut unless asked otherwise; the chapters on the claims listing are the exception.
#guard !(default : DetailsData).startsOpen

end Referee.Test.Audit
