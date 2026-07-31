module

public import Referee.Highlight
-- The checks below are `#guard`s, which Lean elaborates into compile-time (`meta`)
-- definitions, so the declarations under test have to be imported at that level too.
meta import Referee.Highlight

@[expose] public section

/-!
# Tests for `Referee.Highlight`

Covers `declCode`, the one part of this module that is a pure function of a `Highlighted` value and
so can be checked without running the Lean frontend: what a declaration card shows of a command's
highlighted source. Everything else here elaborates a file and is exercised end to end.

The inputs are built by hand rather than highlighted from source, since that is what makes them
checkable at compile time; `highlightedString` compares against the rendered text, which is what the
page shows, rather than against the tree.

Each check is a `#guard`, so any regression turns into a build error. Run with `lake build Test`.
-/

open Lean
open SubVerso.Highlighting (Highlighted)
open Referee.Highlight

namespace Referee.Test

/-- A doc comment token, as the highlighter emits one: a single token holding the delimiters and the
text between them. -/
private def doc (text : String) : Highlighted := .token ⟨.docComment, text⟩

/-- The defining occurrence of `name`, which is where `declCode` stops looking for a docstring. -/
private def defOf (name : Name) : Highlighted :=
  .token ⟨.const name "sig" none true none, name.getString!⟩

/-- A keyword token (`def`, `structure`, `set_option`, …). -/
private def kw (text : String) : Highlighted := .token ⟨.keyword none none none, text⟩

/-- A line comment, delimiter and body, as the highlighter emits one. -/
private def lineComment (text : String) : Array Highlighted :=
  #[.token ⟨.commentDelim, "--"⟩, .token ⟨.lineComment, text⟩]

private def render (name : Name) (hls : Array Highlighted) : String :=
  (declCode name (.seq hls)).toString

/-! ## The declaration's own docstring -/

-- The docstring goes, and so does the blank line the command was separated from the previous one by:
-- the card starts at the code.
#guard render `f #[.text "\n\n", doc "/-- Doc. -/", .text "\n", kw "def", .text " ", defOf `f]
  == "def f"

-- An indented declaration: the whitespace the doc comment sat on goes with it, and the code keeps
-- its own indentation.
#guard render `f #[.text "\n  ", doc "/-- Doc. -/", .text "\n  ", kw "def", .text " ", defOf `f]
  == "def f"

-- A comment above the declaration is the author's and stays, with the blank line they left below it.
-- Only the docstring's own line is removed.
#guard render `f (lineComment " why" ++
    #[.text "\n\n", doc "/-- Doc. -/", .text "\n", kw "def", .text " ", defOf `f])
  == "-- why\n\ndef f"

-- A doc comment inside a `... in` wrapper is still the declaration's own.
#guard render `f #[kw "set_option", .text " ", kw "in", .text "\n", doc "/-- Doc. -/", .text "\n",
    kw "def", .text " ", defOf `f]
  == "set_option in\ndef f"

/-! ## What is not the declaration's own docstring -/

-- Field and constructor doc comments are written after the declaration's name, and are part of the
-- code rather than a second rendering of what the card already shows.
#guard render `S #[doc "/-- Doc. -/", .text "\n", kw "structure", .text " ", defOf `S, .text " ",
    kw "where", .text "\n  ", doc "/-- The field. -/", .text "\n  ", .text "x : Nat"]
  == "structure S where\n  /-- The field. -/\n  x : Nat"

-- The same command with no docstring of its own: the field keeps its documentation.
#guard render `S #[.text "\n\n", kw "structure", .text " ", defOf `S, .text " ", kw "where",
    .text "\n  ", doc "/-- The field. -/", .text "\n  ", .text "x : Nat"]
  == "structure S where\n  /-- The field. -/\n  x : Nat"

-- Nothing to drop: an undocumented declaration is left alone but for the gap above it.
#guard render `f #[.text "\n\n", kw "def", .text " ", defOf `f] == "def f"

end Referee.Test
