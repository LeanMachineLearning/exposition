module

public import Referee.Formalization
-- The checks below are `#guard`s, which Lean elaborates into compile-time (`meta`) definitions, so
-- the declarations under test have to be imported at that level too.
meta import Referee.Formalization

@[expose] public section

/-!
# Tests for `Referee.Formalization`

The YAML reader behind the Claims page. This is the file in the tool that most deserves unit tests
and least tolerates end-to-end ones: it is pure, it is a hand-written parser for a subset of a
format with a large specification, and every one of its failure modes is *silent*. A misread
`main_results` does not throw — it yields a shorter list, or a claim attached to the wrong file, and
the page renders it without complaint.

So the cases below are chosen for where a subset parser actually goes wrong, rather than for
coverage of the happy path:

* the separator rules, where a `:` or a `#` inside quotes or inside a URL must not be taken for
  structure — `id: https://example.org/a#b` is one value, not a key, a scalar and a comment;
* `- key: value`, a mapping whose first entry shares the sequence dash's line, which is how every
  `main_results` entry in the wild is written and the one construct where the left margin of a node
  is not the indentation of any line;
* block scalars, since `>` and `|` differ in exactly the way that makes a scope statement readable
  or a run-on;
* plain multi-line scalars, where stopping too early would not lose a word but would hand the
  enclosing mapping a line it cannot place — and it would answer by ending, silently truncating the
  document from there;
* a tab in the indentation, the one malformation the parser refuses rather than misreads.

The `formalization.yaml` fixture at the bottom is the shape the Palomar template produces, exercised
end to end into `Formalization`.

Run with `lake build Test`.
-/

open Lean
open Referee

namespace Referee.Test.Formalization

/-! ## Comments

A `#` opens a comment at the start of the text or after whitespace, and nowhere else. -/

#guard Yaml.stripComment "a: b # c" == "a: b "
#guard Yaml.stripComment "#whole line" == ""
-- Inside quotes it is content, and a fragment identifier has no space in front of it.
#guard Yaml.stripComment "note: \"a # b\"" == "note: \"a # b\""
#guard Yaml.stripComment "id: https://example.org/a#b" == "id: https://example.org/a#b"
#guard Yaml.stripComment "a#b" == "a#b"

/-! ## The key separator

A `:` separates a key from its value only when a space or the end of the line follows it, it is
outside quotes, and it is outside any flow bracket. Each of the three has a real document behind
it. -/

#guard Yaml.splitKey "name: value" == some ("name", " value")
#guard Yaml.splitKey "empty:" == some ("empty", "")
#guard Yaml.splitKey "\"quoted key\": v" == some ("quoted key", " v")
-- `https:` is not a key: no space follows the colon.
#guard Yaml.splitKey "id: https://example.org" == some ("id", " https://example.org")
#guard Yaml.splitKey "note: \"see a: b\"" == some ("note", " \"see a: b\"")
#guard Yaml.splitKey "msc2020: [a: 1, b]" == some ("msc2020", " [a: 1, b]")
-- A sequence item that is a quoted scalar containing a colon is not a mapping.
#guard Yaml.splitKey "\"TEMPLATE: formalizer name\"" == none
#guard Yaml.splitKey "just a scalar" == none

/-! ## Quoting -/

#guard Yaml.unquote "\"a b\"" == "a b"
#guard Yaml.unquote "'it''s'" == "it's"
#guard Yaml.unquote "plain" == "plain"
#guard Yaml.unquote "\"line\\nbreak\"" == "line\nbreak"
-- An unterminated quote is text. There is nothing better to do with it, and refusing the whole
-- document over one would trade the report for the typo.
#guard Yaml.unquote "\"unterminated" == "\"unterminated"

/-! ## Block structure -/

/-- The first document of `s`, or `.null` if it would not parse. -/
private def doc (s : String) : Yaml := (Yaml.parse s).toOption.getD .null

/-- The value at `key`, or `.null`. -/
private def child (value : Yaml) (key : String) : Yaml := (value.get? key).getD .null

private def nested : String := r#"
# A leading comment, and a blank line under it.

project:
  name: Referee
  authors:
    - Alice
    - Bob
status:
  sorry_count: 0
  axioms: []
"#

#guard (child (doc nested) "project").getStr "name" == "Referee"
#guard (child (doc nested) "project").getStrs "authors" == #["Alice", "Bob"]
#guard (child (doc nested) "status").getNat? "sorry_count" == some 0
#guard (child (doc nested) "status").getStrs "axioms" == #[]
-- A key that is not there and a document that is not a mapping both read as absent, never as "".
#guard (child (doc nested) "status").getNat? "missing" == none
#guard (doc "- a\n- b").getStr "anything" == ""

/-! ### A mapping whose first entry rides the sequence dash

`- declaration: X` is how every `main_results` entry is written, and it is the one place where a
node's left margin is a column no line begins at. Getting it wrong loses either the first field or
all the rest. -/

private def seqOfMaps : String := r#"
main_results:
  - declaration: Foo.bar
    file: Foo.lean
    axioms: [propext]
  - declaration: Baz.qux
    literature_dependencies:
      - statement: Kolmogorov extension
        source: Kallenberg
"#

#guard ((doc seqOfMaps).getItems "main_results").size == 2
#guard (((doc seqOfMaps).getItems "main_results")[0]!).getStr "declaration" == "Foo.bar"
#guard (((doc seqOfMaps).getItems "main_results")[0]!).getStr "file" == "Foo.lean"
#guard (((doc seqOfMaps).getItems "main_results")[0]!).getStrs "axioms" == #["propext"]
#guard (((doc seqOfMaps).getItems "main_results")[1]!).getStr "declaration" == "Baz.qux"
-- Two levels of sequence-under-mapping-under-sequence, which is the deepest nesting the schema has.
#guard ((((doc seqOfMaps).getItems "main_results")[1]!).getItems "literature_dependencies").size == 1
#guard (((((doc seqOfMaps).getItems "main_results")[1]!).getItems
  "literature_dependencies")[0]!).getStr "source" == "Kallenberg"

/-! ### Flow collections -/

#guard (doc "axioms: [propext, Classical.choice]").getStrs "axioms"
  == #["propext", "Classical.choice"]
#guard (doc "axioms: []").getStrs "axioms" == #[]
#guard (child (doc "entry: {a: 1, b: two}") "entry").getStr "b" == "two"
#guard (doc "arxiv: [\"math.LO\", \"math.PR\"]").getStrs "arxiv" == #["math.LO", "math.PR"]

/-! ### Block scalars

`>` folds its lines into one; `|` keeps them apart. A scope statement written with the wrong one is
either a run-on or a list, so this is a difference a reader sees. -/

private def blockScalars : String := r#"
folded: >-
  one
  two
literal: |
  one
  two
kept: |+
  one

indented: >
  outer
    inner
"#

#guard (doc blockScalars).getStr "folded" == "one two"
#guard (doc blockScalars).getStr "literal" == "one\ntwo"
-- `+` keeps the trailing blank line; the other two indicators right-trim, since every consumer
-- renders the value as prose.
#guard (doc blockScalars).getStr "kept" == "one\n"
-- A line indented further than the block keeps its extra indentation; the fold does not (see the
-- module docstring in `Referee.Formalization` — real YAML would break the line here).
#guard (doc blockScalars).getStr "indented" == "outer   inner"

/-! ### Plain multi-line scalars

Everything indented past the key belongs to the value. The failure to avoid is not losing a word: it
is leaving a line the enclosing mapping cannot place, which ends the mapping and truncates the rest
of the document. -/

#guard (doc "a: one\n   two\nb: 3").getStr "a" == "one two"
#guard (doc "a: one\n   two\nb: 3").getStr "b" == "3"
-- Across a blank line too, which is where a parser that stopped at blanks would drop `b`.
#guard (doc "a: one\n\n   two\nb: 3").getStr "b" == "3"

/-! ### Nothing, spelled four ways -/

#guard (doc "a: ~\nb: null\nc:\nd: \"\"").getStr "a" == ""
#guard (doc "a: ~\nb: null\nc:\nd: \"\"").getStr "b" == ""
#guard (doc "a: ~\nb: null\nc:\nd: \"\"").getStr "c" == ""
-- A *quoted* null is the four-letter string, which is why the check runs before unquoting.
#guard (doc "a: \"null\"").getStr "a" == "null"

/-! ### Document markers

The first document only: `---` ends the directives, `...` ends the document. -/

#guard (doc "---\na: 1\n...\nb: 2").getStr "a" == "1"
#guard (doc "---\na: 1\n...\nb: 2").getStr "b" == ""

/-! ### The one refusal

A tab in the indentation changes the structure invisibly rather than the content, so it is reported
instead of misread. -/

#guard (Yaml.parse "a:\n\tb: 1").toOption.isNone
#guard (Yaml.parse "a:\n  b: 1").toOption.isSome
-- A tab *inside* a value is ordinary text.
#guard (Yaml.parse "a: b\tc").toOption.isSome

/-! ## End to end

The shape the Palomar template produces, cut down to the fields the site reads. -/

private def sample : String := r#"
# yaml-language-server: $schema=https://example.org/formalization.schema.json
version: "v0.4"

project:
  name: "Brownian motion"
  description: >-
    Construction of Brownian motion
    and its basic properties.
  authors:
    - "A. Formalizer"
  license: "Apache-2.0"

classification:
  arxiv: ["math.PR"]

status:
  scope: |
    Constructs Brownian motion on the reals.
    Does not cover the Levy modulus of continuity.
  sorry_count: 0
  axioms: []
  main_results:
    - declaration: "P.isBrownianMotion"
      file: B/Construction.lean
      sorry_count: 0
      axioms: ["propext", "Classical.choice"]
      comparator_config: comparator/b.json
      literature_dependencies:
        - statement: "Kolmogorov's extension theorem"
          source: "Kallenberg 2021, Thm 8.23"
        - statement: "Chentsov's criterion"
          source: "Kallenberg 2021, Thm 4.23"
    - declaration: P.hasLaw    # an unquoted name, with a comment after it
      file: B/Law.lean
    - {declaration: "P.flowStyle", file: "B/Flow.lean"}
    - file: "B/Nameless.lean"

acknowledgements: "Mathlib"
"#

/-- The fixture, read as the site reads it. -/
private def form : Formalization := (Formalization.parse sample).toOption.getD {}

#guard form.version == "v0.4"
#guard form.projectName == "Brownian motion"
#guard form.projectDescription == "Construction of Brownian motion and its basic properties."
#guard form.scope
  == "Constructs Brownian motion on the reals.\nDoes not cover the Levy modulus of continuity."

-- Four entries are written; the one with no `declaration` names nothing the page could show, and is
-- dropped at the reading end rather than carried and skipped at the rendering end.
#guard form.mainResults.size == 3
#guard form.mainResults.map (·.declaration)
  == #["P.isBrownianMotion", "P.hasLaw", "P.flowStyle"]
#guard (form.mainResults[0]!).file == "B/Construction.lean"
#guard (form.mainResults[0]!).sorryCount? == some 0
#guard (form.mainResults[0]!).axioms == #["propext", "Classical.choice"]
#guard (form.mainResults[0]!).comparatorConfig == "comparator/b.json"
#guard ((form.mainResults[0]!).literatureDependencies.map (·.statement))
  == #["Kolmogorov's extension theorem", "Chentsov's criterion"]
#guard ((form.mainResults[0]!).literatureDependencies[1]!).source == "Kallenberg 2021, Thm 4.23"
-- A comment after a plain scalar is not part of the name; a declaration linked against
-- `P.hasLaw    # an unquoted name` would resolve to nothing at all.
#guard (form.mainResults[1]!).file == "B/Law.lean"
#guard (form.mainResults[1]!).sorryCount? == none
#guard (form.mainResults[1]!).literatureDependencies.isEmpty
#guard (form.mainResults[2]!).file == "B/Flow.lean"

-- The template's own `status`, which declares no `main_results` at all: the schema calls the field
-- optional, and a project that leaves it out must read as "no claims declared" rather than as a
-- parse failure. It is the difference between the Claims page not applying and the file being
-- unreadable.
#guard (Formalization.parse "status:\n  sorry_count: 0\n").toOption.map (·.mainResults.size)
  == some 0

-- A file that is not YAML at all still yields something, because the parser only refuses tabs.
-- Worth pinning: the guarantee the rest of the tool relies on is that a bad file produces an empty
-- `Formalization`, never a wrong one.
#guard (Formalization.parse "not yaml, just a sentence").toOption.map (·.mainResults.size)
  == some 0

end Referee.Test.Formalization
