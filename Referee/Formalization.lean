module

public import Lean

@[expose] public section

/-!
# `formalization.yaml`: the project's own account of what it claims

Every other input this tool reads is the compiled library. This one is prose the author wrote, and
it is read for exactly one thing the library cannot supply: *which* of its results the project puts
forward as the point of it.

The file is the metadata document the [Palomar registry](https://palomar-registry.org/) requires of
a submission, schema `v0.4`, and the field that matters here is `status.main_results` — a curated
list of `{declaration, file, sorry_count, axioms, comparator_config, literature_dependencies}`. The
schema calls it optional ("add it only when a short curated project-level list is useful"), which is
why the Claims page exists only when it is there and is non-empty.

## Why a parser rather than a dependency

There is no YAML library in this tool's dependency graph, and taking one on for a single file at the
edge of the build would be a poor trade — the four packages this tool requires are each there to be
*useful without it*, and none of them wants a YAML reader. So this is a parser for the subset the
document actually uses: block mappings, block sequences, flow sequences and mappings on one line,
quoted and plain scalars, folded and literal block scalars, and comments.

What it deliberately does not implement: anchors and aliases (`&`/`*`), tags (`!!str`), explicit
keys (`? `), multi-document streams beyond taking the first, and the finer points of folding
(a more-indented line inside a `>` block keeps its newline in real YAML; here it does not).
Encountering any of them yields a wrong reading rather than an error, which is the honest cost of
the subset. A tab in a line's indentation — the one malformation that silently changes structure
rather than content — *is* reported, because that is the case where a wrong reading is most likely
and least visible.

The consequence for a reader of the site: the Claims page is only as good as this parse. That is why
`Referee.Formalization` carries only the fields the page renders, and why every one of them has a
harmless default — a field this parser misreads goes missing, and a missing field shows as absent
rather than as something invented.
-/

open Lean

namespace Referee

/-! ## A YAML value

Scalars stay strings. The document's typed fields are few and their types are known at the point of
use (`sorry_count` is the only number), so carrying an untyped scalar and converting at the reading
end is smaller than a tagged scalar type and loses nothing. -/

/-- A YAML value, in the subset `Yaml.parse` reads. -/
inductive Yaml where
  /-- An absent, empty, `~` or `null` value. -/
  | null
  /-- Any scalar, as text: quoting is resolved, but numbers and booleans are not. -/
  | scalar (value : String)
  | seq (items : Array Yaml)
  /-- A mapping, in document order. Duplicate keys are kept; `Yaml.get?` returns the first. -/
  | map (entries : Array (String × Yaml))
deriving Repr, Inhabited

/-- The value at `key`, or `none` when this is not a mapping or has no such key. -/
def Yaml.get? : Yaml → String → Option Yaml
  | .map entries, key => (entries.find? (·.1 == key)).map (·.2)
  | _, _ => none

/-- The text of a scalar; `none` for every other shape. -/
def Yaml.str? : Yaml → Option String
  | .scalar value => some value
  | _ => none

/-- A value read as a list.

Forgiving in the one direction that costs nothing: a field the schema declares as a list but the
author wrote as a single value reads as a one-element list rather than as nothing. Absence is still
the empty list. -/
def Yaml.items : Yaml → Array Yaml
  | .seq items => items
  | .null => #[]
  | value => #[value]

/-- The scalar at `key`, or `""`. -/
def Yaml.getStr (value : Yaml) (key : String) : String :=
  ((value.get? key).bind (·.str?)).getD ""

/-- The scalar at `key` read as a natural number, or `none` — which is also what a template
placeholder such as `"TEMPLATE: unquoted nonnegative integer"` yields. -/
def Yaml.getNat? (value : Yaml) (key : String) : Option Nat :=
  ((value.get? key).bind (·.str?)).bind (·.toNat?)

/-- The list at `key`. -/
def Yaml.getItems (value : Yaml) (key : String) : Array Yaml :=
  ((value.get? key).map (·.items)).getD #[]

/-- The list of scalars at `key`, dropping any element that is not a scalar. -/
def Yaml.getStrs (value : Yaml) (key : String) : Array String :=
  (value.getItems key).filterMap (·.str?)

namespace Yaml

/-! ## Scanning helpers

All of these work on `List Char` rather than on `String` positions. The documents are a few hundred
lines and read once per build, so the cost is irrelevant beside being able to write the quote and
bracket bookkeeping as ordinary pattern matches. -/

/-- `String.trimAscii`, back as a `String`. -/
def trimStr (s : String) : String := s.trimAscii.toString

/-- Drops trailing newlines, spaces and tabs. -/
def rtrim (s : String) : String :=
  String.ofList (s.toList.reverse.dropWhile (fun c => c == '\n' || c == ' ' || c == '\t' ||
    c == '\r')).reverse

/-- Resolves `\n`-style escapes inside a double-quoted scalar.

The five that appear in hand-written metadata. `\uXXXX` is left as written rather than decoded: a
wrong decode would corrupt a name, and the literal is at least recognizable as what it is. -/
def unescapeDouble : List Char → List Char
  | '\\' :: 'n' :: rest => '\n' :: unescapeDouble rest
  | '\\' :: 't' :: rest => '\t' :: unescapeDouble rest
  | '\\' :: 'r' :: rest => '\r' :: unescapeDouble rest
  | '\\' :: '"' :: rest => '"' :: unescapeDouble rest
  | '\\' :: '\\' :: rest => '\\' :: unescapeDouble rest
  | c :: rest => c :: unescapeDouble rest
  | [] => []

/-- Resolves the one escape a single-quoted scalar has: `''` for a literal quote. -/
def unescapeSingle : List Char → List Char
  | '\'' :: '\'' :: rest => '\'' :: unescapeSingle rest
  | c :: rest => c :: unescapeSingle rest
  | [] => []

/-- Strips the quotes from a quoted scalar and resolves its escapes. Leaves a plain scalar alone,
including one that merely starts with a quote — an unterminated quote is text, not an error. -/
def unquote (s : String) : String :=
  let cs := (trimStr s).toList
  match cs with
  | '"' :: rest =>
    match rest.reverse with
    | '"' :: revInner => String.ofList (unescapeDouble revInner.reverse)
    | _ => String.ofList cs
  | '\'' :: rest =>
    match rest.reverse with
    | '\'' :: revInner => String.ofList (unescapeSingle revInner.reverse)
    | _ => String.ofList cs
  | _ => String.ofList cs

/-- A trimmed scalar as a `Yaml`, mapping YAML's spellings of nothing onto `.null`.

The check runs before `unquote`, so a *quoted* `"null"` stays the four-letter string it is. -/
def scalarOf (s : String) : Yaml :=
  let t := trimStr s
  if t.isEmpty || t == "~" || t == "null" || t == "Null" || t == "NULL" then .null
  else .scalar (unquote t)

/-- Removes a trailing `# …` comment.

A `#` opens a comment only at the start of the text or after whitespace, and never inside quotes —
so `id: https://example.org/a#b` keeps its fragment and `note: "a # b"` keeps its hash. -/
def stripComment (s : String) : String :=
  let rec go (cs : List Char) (acc : List Char) (quote : Option Char) (afterSpace : Bool) :
      List Char :=
    match cs with
    | [] => acc.reverse
    | c :: rest =>
      match quote with
      | some q =>
        if c == q then go rest (c :: acc) none false
        else if q == '"' && c == '\\' then
          match rest with
          | d :: rest' => go rest' (d :: c :: acc) quote false
          | [] => (c :: acc).reverse
        else go rest (c :: acc) quote false
      | none =>
        if c == '#' && afterSpace then acc.reverse
        else if c == '"' || c == '\'' then go rest (c :: acc) (some c) false
        else go rest (c :: acc) none (c == ' ' || c == '\t')
  String.ofList (go s.toList [] none true)

/-- Splits `key: value` at the `:` that separates them, or `none` when the text is not a mapping
entry.

The separator is a `:` followed by a space or the end of the line, outside quotes and outside any
flow bracket. That is what keeps `id: https://example.org` from splitting twice, `msc2020: [a, b]`
from splitting inside the list, and `note: "see x: y"` from splitting inside the quotes. -/
def splitKey (s : String) : Option (String × String) :=
  let rec go (cs : List Char) (acc : List Char) (quote : Option Char) (depth : Nat) :
      Option (String × String) :=
    match cs with
    | [] => none
    | c :: rest =>
      match quote with
      | some q =>
        if c == q then go rest (c :: acc) none depth
        else if q == '"' && c == '\\' then
          match rest with
          | d :: rest' => go rest' (d :: c :: acc) quote depth
          | [] => none
        else go rest (c :: acc) quote depth
      | none =>
        if c == '"' || c == '\'' then go rest (c :: acc) (some c) depth
        else if c == '[' || c == '{' then go rest (c :: acc) none (depth + 1)
        else if c == ']' || c == '}' then go rest (c :: acc) none (depth - 1)
        else if c == ':' && depth == 0 && (match rest with | [] => true | d :: _ => d == ' ') then
          some (String.ofList acc.reverse, String.ofList rest)
        else go rest (c :: acc) none depth
  match go s.toList [] none 0 with
  | some (key, value) =>
    let key := unquote key
    if key.isEmpty then none else some (key, value)
  | none => none

/-! ## Flow collections

`[a, b]` and `{a: b}` on one line, which is how the template writes `arxiv`, `msc2020` and every
list an author is invited to empty. -/

/-- Reads one flow token, stopping at a separator that belongs to the enclosing collection.

Returns the token's characters and the rest of the input, the latter still holding the separator so
the caller can see which one it was. -/
def flowToken (cs : List Char) (acc : List Char) (quote : Option Char) (stopColon : Bool) :
    List Char × List Char :=
  match cs with
  | [] => (acc.reverse, [])
  | c :: rest =>
    match quote with
    | some q =>
      if c == q then flowToken rest (c :: acc) none stopColon
      else if q == '"' && c == '\\' then
        match rest with
        | d :: rest' => flowToken rest' (d :: c :: acc) quote stopColon
        | [] => ((c :: acc).reverse, [])
      else flowToken rest (c :: acc) quote stopColon
    | none =>
      if c == ',' || c == ']' || c == '}' then (acc.reverse, c :: rest)
      else if stopColon && c == ':' then (acc.reverse, c :: rest)
      else if c == '"' || c == '\'' then flowToken rest (c :: acc) (some c) stopColon
      else flowToken rest (c :: acc) none stopColon

mutual

/-- Reads one flow value: a nested collection, or a scalar up to the next separator. -/
partial def flowValue (cs : List Char) : Yaml × List Char :=
  match cs.dropWhile (· == ' ') with
  | '[' :: rest => flowSeq rest #[]
  | '{' :: rest => flowMap rest #[]
  | cs =>
    let (chars, rest) := flowToken cs [] none false
    (scalarOf (String.ofList chars), rest)

/-- Reads the body of `[…]`, having consumed the opening bracket. An unclosed bracket ends at the
end of the input rather than failing: the document is metadata, and half a list beats none. -/
partial def flowSeq (cs : List Char) (acc : Array Yaml) : Yaml × List Char :=
  match cs.dropWhile (· == ' ') with
  | [] => (.seq acc, [])
  | ']' :: rest => (.seq acc, rest)
  | ',' :: rest => flowSeq rest acc
  | cs =>
    let (value, rest) := flowValue cs
    flowSeq rest (acc.push value)

/-- Reads the body of `{…}`, having consumed the opening brace. -/
partial def flowMap (cs : List Char) (acc : Array (String × Yaml)) : Yaml × List Char :=
  match cs.dropWhile (· == ' ') with
  | [] => (.map acc, [])
  | '}' :: rest => (.map acc, rest)
  | ',' :: rest => flowMap rest acc
  | cs =>
    let (keyChars, rest) := flowToken cs [] none true
    let key := unquote (String.ofList keyChars)
    match rest with
    | ':' :: rest =>
      let (value, rest) := flowValue rest
      flowMap rest (acc.push (key, value))
    -- A bare entry in a flow mapping (`{a, b}`) is a key with no value.
    | rest => flowMap rest (acc.push (key, .null))

end

/-- Parses an inline value: a flow collection, or a scalar. -/
def parseInline (s : String) : Yaml :=
  let t := trimStr s
  if t.startsWith "[" || t.startsWith "{" then (flowValue t.toList).1 else scalarOf t

/-! ## Block structure -/

/-- One physical line, with its indentation measured off.

`text` is the line with its leading spaces removed and nothing else done to it: comments survive,
because inside a block scalar a `#` line is content. A line that is empty or all spaces is recorded
with indentation `0` and empty text, so that "blank" is one check rather than two. -/
structure Line where
  indent : Nat
  text : String
  /-- Blank or comment-only: skipped everywhere except inside a block scalar. -/
  blank : Bool
deriving Inhabited

/-- Measures one line. -/
def mkLine (raw : String) : Line :=
  let cs := (rtrim raw).toList
  let indent := (cs.takeWhile (· == ' ')).length
  let text := String.ofList (cs.drop indent)
  if text.isEmpty then { indent := 0, text := "", blank := true }
  else { indent, text, blank := text.startsWith "#" }

/-- Whether the line opens a block-sequence entry. `- ` or a bare `-`, never `-5` or `-Inf`. -/
def isDashLine (text : String) : Bool :=
  text == "-" || text.startsWith "- "

/-- The header of a block scalar: whether it folds (`>`) or is literal (`|`), its chomping
indicator, and any explicit indentation offset.

Returns `none` unless everything after the indicator is a chomping indicator, digits, or a comment —
so a plain scalar that merely begins with `>` is left alone. -/
def blockHeader? (s : String) : Option (Bool × Char × Option Nat) :=
  match (trimStr (stripComment s)).toList with
  | ind :: rest =>
    if ind != '|' && ind != '>' then none
    else
      let rest := rest.filter (· != ' ')
      let chomp := rest.find? (fun c => c == '-' || c == '+')
      let digits := rest.filter Char.isDigit
      let others := rest.filter (fun c => !c.isDigit && c != '-' && c != '+')
      if !others.isEmpty then none
      else some (ind == '>', chomp.getD ' ', (String.ofList digits).toNat?)
  | [] => none

/-- The next line that is not blank or a comment. -/
partial def skipIgnorable (lines : Array Line) (i : Nat) : Nat :=
  if h : i < lines.size then
    if lines[i].blank then skipIgnorable lines (i + 1) else i
  else i

/-- The indentation of the first line with any content at or after `i`. -/
partial def firstContentIndent (lines : Array Line) (i : Nat) : Option Nat :=
  if h : i < lines.size then
    if lines[i].text.isEmpty then firstContentIndent lines (i + 1) else some lines[i].indent
  else none

/-- Collects the lines of a block scalar, re-indented to the block's own left margin.

A truly empty line belongs to the block wherever it appears; any other line belongs to it while it
is indented at least as far as the block. A comment line inside a block scalar is content, which is
why `Line.blank` is not consulted here. -/
partial def blockScalarLines (lines : Array Line) (i : Nat) (blockIndent : Nat)
    (acc : Array String) : Array String × Nat :=
  if h : i < lines.size then
    let line := lines[i]
    if line.text.isEmpty then blockScalarLines lines (i + 1) blockIndent (acc.push "")
    else if line.indent ≥ blockIndent then
      let pad := String.ofList (List.replicate (line.indent - blockIndent) ' ')
      blockScalarLines lines (i + 1) blockIndent (acc.push (pad ++ line.text))
    else (acc, i)
  else (acc, i)

/-- Joins the lines of a folded (`>`) block scalar: runs of non-empty lines become one line, and a
blank line becomes a break. -/
def foldBlockLines (ls : Array String) : String := Id.run do
  let mut out := ""
  let mut atStart := true
  for l in ls do
    if l.isEmpty then
      out := out ++ "\n"
      atStart := true
    else
      out := out ++ (if atStart then l else " " ++ l)
      atStart := false
  return out

/-- Reads a block scalar introduced on the previous line, which was indented to `parentIndent`.

Only `+` chomping is honored literally; the other two both right-trim, because every consumer of
this value renders it as prose and a trailing newline is not something a reader can see. -/
def readBlockScalar (lines : Array Line) (i : Nat) (parentIndent : Nat)
    (header : Bool × Char × Option Nat) : String × Nat :=
  let (folded, chomp, explicit?) := header
  let blockIndent? : Option Nat :=
    match explicit? with
    | some n => some (parentIndent + n)
    | none =>
      match firstContentIndent lines i with
      | some n => if n > parentIndent then some n else none
      | none => none
  match blockIndent? with
  | none => ("", i)
  | some blockIndent =>
    let (raw, j) := blockScalarLines lines i blockIndent #[]
    let text := if folded then foldBlockLines raw else String.intercalate "\n" raw.toList
    (if chomp == '+' then text else rtrim text, j)

mutual

/-- Reads whatever node begins at the next content line, provided it is indented at least
`minIndent`. An empty node — a key with nothing under it — reads as `.null`. -/
partial def parseNode (lines : Array Line) (i : Nat) (minIndent : Nat) : Yaml × Nat :=
  let i := skipIgnorable lines i
  if h : i < lines.size then
    let line := lines[i]
    if line.indent < minIndent then (.null, i)
    else if isDashLine line.text then parseSeq lines i line.indent #[]
    else if (splitKey line.text).isSome then parseMap lines i line.indent none #[]
    else
      let (text, j) := foldContinuation lines (i + 1) line.indent (trimStr (stripComment line.text))
      (parseInline text, j)
  else (.null, i)

/-- Reads a block sequence whose dashes sit at `indent`. -/
partial def parseSeq (lines : Array Line) (i : Nat) (indent : Nat) (acc : Array Yaml) :
    Yaml × Nat :=
  let i := skipIgnorable lines i
  if h : i < lines.size then
    let line := lines[i]
    if line.indent != indent || !isDashLine line.text then (.seq acc, i)
    else
      -- What follows the dash is a node whose left margin is the column it starts in, which is how
      -- `- key: value` can carry the first entry of a mapping on the dash's own line.
      let after := line.text.toList.drop 1
      let gap := (after.takeWhile (· == ' ')).length
      let rest := String.ofList (after.drop gap)
      let column := indent + 1 + gap
      let (value, j) :=
        if (trimStr (stripComment rest)).isEmpty then parseNode lines (i + 1) (indent + 1)
        else if (splitKey rest).isSome then parseMap lines (i + 1) column (some rest) #[]
        else if let some header := blockHeader? rest then
          let (text, j) := readBlockScalar lines (i + 1) indent header
          (.scalar text, j)
        else
          let (text, j) := foldContinuation lines (i + 1) indent (trimStr (stripComment rest))
          (parseInline text, j)
      parseSeq lines j indent (acc.push value)
  else (.seq acc, i)

/-- Reads a block mapping whose keys sit at `indent`.

`first?` carries an entry that is not on a line of its own — the `key: value` that follows a
sequence dash — with `i` already pointing past the line it came from. -/
partial def parseMap (lines : Array Line) (i : Nat) (indent : Nat)
    (first? : Option String) (acc : Array (String × Yaml)) : Yaml × Nat :=
  match first? with
  | some text =>
    match splitKey text with
    | some (key, rest) =>
      let (value, j) := parseEntryValue lines i indent rest
      parseMap lines j indent none (acc.push (key, value))
    | none => (.map acc, i)
  | none =>
    let i := skipIgnorable lines i
    if h : i < lines.size then
      let line := lines[i]
      -- A line at any other indentation ends this mapping: less means the enclosing node resumes,
      -- more means a malformation, and stopping is the reading that loses the least.
      if line.indent != indent then (.map acc, i)
      else
        match splitKey line.text with
        | some (key, rest) =>
          let (value, j) := parseEntryValue lines (i + 1) indent rest
          parseMap lines j indent none (acc.push (key, value))
        | none => (.map acc, i)
    else (.map acc, i)

/-- Reads the value of a mapping entry whose key sits at `column`: a block scalar, a nested block,
or an inline value with any plain continuation lines folded into it. -/
partial def parseEntryValue (lines : Array Line) (i : Nat) (column : Nat)
    (rest : String) : Yaml × Nat :=
  if let some header := blockHeader? rest then
    let (text, j) := readBlockScalar lines i column header
    (.scalar text, j)
  else
    let inline := trimStr (stripComment rest)
    if inline.isEmpty then parseNode lines i (column + 1)
    else
      let (text, j) := foldContinuation lines i column inline
      (parseInline text, j)

/-- Folds the continuation lines of a plain multi-line scalar into `acc`.

Everything more indented than the value's own key belongs to it. Blank lines are stepped over
rather than stopped at: a plain scalar broken by a blank line is rare, but stopping there would hand
the enclosing mapping a line it cannot place, and it would answer by ending — silently truncating
the rest of the document. -/
partial def foldContinuation (lines : Array Line) (i : Nat) (column : Nat)
    (acc : String) : String × Nat :=
  let j := skipIgnorable lines i
  if h : j < lines.size then
    let line := lines[j]
    if line.indent ≤ column then (acc, j)
    else
      let piece := trimStr (stripComment line.text)
      foldContinuation lines (j + 1) column (if piece.isEmpty then acc else acc ++ " " ++ piece)
  else (acc, j)

end

/-- Parses the first document of a YAML stream.

Fails only on a tab in a line's indentation. Every other malformation this subset cannot represent
yields a wrong reading rather than an error — see the module docstring — but a tab changes the
*structure* invisibly, and a document that reads as a differently-shaped one is the failure worth
refusing. -/
def parse (text : String) : Except String Yaml := do
  let raw := text.splitOn "\n" |>.toArray
  for (line, idx) in raw.zipIdx do
    let leading := line.toList.takeWhile fun c => c == ' ' || c == '\t'
    if leading.contains '\t' then
      throw s!"line {idx + 1}: tab in indentation (YAML forbids it; use spaces)"
  let lines := raw.map mkLine
  -- The first document only: everything before a `---` is directives, everything after a `...` is
  -- the next document.
  let start := match lines.findIdx? (fun (l : Line) => l.text == "---") with
    | some i => i + 1
    | none => 0
  let stop := match lines.findIdx? (fun (l : Line) => l.text == "...") with
    | some i => i
    | none => lines.size
  let lines := if start ≤ stop then lines.extract start stop else lines
  return (parseNode lines 0 0).1

end Yaml

/-! ## The fields the Claims page reads

A deliberately small slice of the schema. Everything here is rendered; nothing here is stored
because it might one day be useful. The defaults are all harmless, so a field this parser misreads
goes missing from the page rather than appearing wrong on it. -/

/-- A result the project relies on but does not prove, assumed from the literature.

`status.main_results[].literature_dependencies` in the schema, and the field on this page that most
changes what a claim is worth: a main result standing on an unformalized theorem is proved *modulo*
that theorem, and nothing in the compiled library says so. -/
structure LiteratureDependency where
  /-- The result being relied on. -/
  statement : String := ""
  /-- Where it comes from, naming an entry of the file's `sources`. -/
  source : String := ""
deriving Repr, ToJson, FromJson, Inhabited

/-- One entry of `status.main_results`. -/
structure MainResult where
  /-- The fully qualified Lean declaration proving this result. The only field the page cannot do
  without: an entry with no declaration names nothing to link to. -/
  declaration : String := ""
  /-- The file containing it, as the author writes it. Shown only when the declaration could not be
  matched, where it is the one clue about what was meant. -/
  file : String := ""
  sorryCount? : Option Nat := none
  axioms : Array String := #[]
  /-- Path to the [Comparator](https://github.com/leanprover/comparator) config that verifies this
  result, when the project ships one. -/
  comparatorConfig : String := ""
  literatureDependencies : Array LiteratureDependency := #[]
deriving Repr, ToJson, FromJson, Inhabited

/-- The parts of a `formalization.yaml` the site renders. -/
structure Formalization where
  /-- The schema version the file declares (`v0.3`, `v0.4`, or empty). Recorded rather than checked:
  the fields this reads have the same shape in both, and refusing to read a file because it declares
  a version this tool has not heard of would be worse than reading what is there. -/
  version : String := ""
  projectName : String := ""
  projectDescription : String := ""
  /-- `status.scope`: the project's own statement of what is and is not formalized. -/
  scope : String := ""
  mainResults : Array MainResult := #[]
deriving Repr, ToJson, FromJson, Inhabited

/-- Reads one `status.main_results` entry. -/
def MainResult.ofYaml (value : Yaml) : MainResult where
  declaration := value.getStr "declaration"
  file := value.getStr "file"
  sorryCount? := value.getNat? "sorry_count"
  axioms := value.getStrs "axioms"
  comparatorConfig := value.getStr "comparator_config"
  literatureDependencies := (value.getItems "literature_dependencies").map fun dep =>
    { statement := dep.getStr "statement", source := dep.getStr "source" }

/-- Reads the fields the site renders out of a parsed document. -/
def Formalization.ofYaml (value : Yaml) : Formalization :=
  let project := (value.get? "project").getD .null
  let status := (value.get? "status").getD .null
  {
    version := value.getStr "version"
    projectName := project.getStr "name"
    projectDescription := project.getStr "description"
    scope := status.getStr "scope"
    -- Entries with no `declaration` are dropped here rather than carried and skipped later: there
    -- is nothing the page could show for one, and counting them would inflate every number on it.
    mainResults := ((status.getItems "main_results").map MainResult.ofYaml).filter fun result =>
      !result.declaration.isEmpty
  }

/-- Parses a `formalization.yaml`. -/
def Formalization.parse (text : String) : Except String Formalization :=
  Formalization.ofYaml <$> Yaml.parse text

end Referee
