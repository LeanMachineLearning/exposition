import LMLExposition.Collect

/-!
# Standalone Lean file extraction (verbatim-source variant)

This is an adaptation of Matthew Ballard's `EmitStandalone.lean`
(https://github.com/mattrobball/lean-informal/blob/main/Informal/EmitStandalone.lean).

This variant copies the **verbatim source text** of each declaration and replays the surrounding
`namespace`/`open`/`variable`/`section` context commands. Notation is therefore preserved exactly as
written, so the output is readable.

## Strategy

1. Re-elaborate each project source file against the already-loaded environment
   (`IO.processCommands`) to recover, per command, its `Syntax` and byte range.
2. Classify each command as a *declaration* (it defines an exposed declaration), a *context* command
   (`namespace`/`end`/`open`/`variable`/`section`/`set_option`/`universe`), or *skip*.
3. Extract each command's source text by byte position. For theorems, the proof body (`declVal`) is
   replaced by `:= sorry` surgically (the rest of the source is untouched).
4. Per target, keep the context commands plus the declaration commands in the target's transitive
   closure, drop now-empty sections, and assemble: external `import`s followed by the bodies in
   module-dependency order.

Each source file is processed **once** and cached; assembling a target then only filters and
concatenates strings.
-/

open Lean Lean.Elab Lean.Elab.Command Lean.Parser

namespace LMLExposition

/-! ## Classified commands -/

/-- How a source command relates to the set of exposed declarations. -/
inductive CmdClass where
  /-- Defines at least one exposed declaration. -/
  | decl
  /-- A `namespace`/`end`/`open`/`variable`/`section`/`set_option`/`universe` command. -/
  | context
  /-- Anything else (a non-exposed declaration, `#check`, an attribute command, …). -/
  | skip
  deriving Inhabited, BEq

/-- A classified source command: its source text (with proof already `sorry`-injected for theorems),
its `Syntax` kind, and the exposed declarations it defines (if any). -/
structure CommandEntry where
  cls : CmdClass
  src : String
  kind : SyntaxNodeKind
  declNames : Array Name := #[]
  /-- For a `namespace` command, the namespace it opens (used to emit existence stubs). -/
  nsName? : Option Name := none
  /-- For a `variable` command, its binders decomposed as `(source text, identifiers referenced)`,
  so that binders mentioning declarations outside a target's closure can be dropped. -/
  binders : Array (String × Array String) := #[]
  /-- Extra commands to emit right after this one — used for `instance … := sorry` replacements of a
  definition's `deriving` clause (which can't be re-derived in the minimal file). -/
  appended : Array String := #[]
  /-- For a declaration command, the exposed notation parsers whose syntax appears in its source. The
  notation's expansion (not the parser) is what shows up in the elaborated term, so this syntactic
  signal is the only way to know the verbatim source needs that notation command replayed. -/
  usedNotations : Array Name := #[]
  deriving Inhabited

/-! ## Syntax inspection -/

/-- The `declVal` syntax node of a declaration (`:= …`, `| … => …`, or `where …`), if present. -/
partial def findDeclValStx? (root : Syntax) : Option Syntax := Id.run do
  let mut worklist : Array Syntax := #[root]
  while !worklist.isEmpty do
    let stx := worklist.back!
    worklist := worklist.pop
    let k := stx.getKind
    if k == ``Parser.Command.declValSimple || k == ``Parser.Command.declValEqns
        || k == ``Parser.Command.whereStructInst then
      return some stx
    for arg in stx.getArgs do
      worklist := worklist.push arg
  return none

/-- The byte range of the *value*/proof part of a declaration, if present. -/
def findDeclVal? (root : Syntax) : Option (String.Pos.Raw × String.Pos.Raw) := do
  let v ← findDeclValStx? root
  match v.getPos?, v.getTailPos? with
  | some s, some e => some (s, e)
  | _, _ => none

/-- True if `stx` declares a `theorem` or `lemma` (whose proof we replace by `sorry`). `theorem`
parses as `Command.declaration` with the keyword node `Command.theorem`; `lemma` (a Mathlib synonym)
keeps its own `lemma` syntax kind until macro expansion. We search the whole tree so that wrapper
commands like `omit … in <decl>` / `open … in <decl>` are seen through (a `def`'s syntax never
contains a `theorem`/`lemma` *command* node, so this stays specific). -/
partial def isTheoremDecl (stx : Syntax) : Bool := Id.run do
  let mut worklist : Array Syntax := #[stx]
  while !worklist.isEmpty do
    let s := worklist.back!
    worklist := worklist.pop
    let k := s.getKind
    if k == ``Parser.Command.theorem || k == `lemma then return true
    for arg in s.getArgs do
      worklist := worklist.push arg
  return false

/-- The byte ranges of the outermost `by …` tactic blocks inside `root` (not recursing into a block
already collected). Used to replace embedded proofs in a *definition's* value with `sorry`. -/
partial def collectByBlocks (root : Syntax) : Array (String.Pos.Raw × String.Pos.Raw) := Id.run do
  let mut acc : Array (String.Pos.Raw × String.Pos.Raw) := #[]
  let mut worklist : Array Syntax := #[root]
  while !worklist.isEmpty do
    let stx := worklist.back!
    worklist := worklist.pop
    if stx.getKind == ``Lean.Parser.Term.byTactic then
      match stx.getPos?, stx.getTailPos? with
      | some s, some e => acc := acc.push (s, e)   -- don't descend into a block we'll replace
      | _, _ => for arg in stx.getArgs do worklist := worklist.push arg
    else
      for arg in stx.getArgs do
        worklist := worklist.push arg
  return acc

/-- The first descendant of `root` with the given syntax kind (breadth-first). -/
partial def findFirstOfKind? (root : Syntax) (kind : SyntaxNodeKind) : Option Syntax := Id.run do
  let mut worklist : Array Syntax := #[root]
  while !worklist.isEmpty do
    let stx := worklist.back!
    worklist := worklist.pop
    if stx.getKind == kind then return some stx
    for arg in stx.getArgs do
      worklist := worklist.push arg
  return none

/-- Every `SyntaxNodeKind` occurring anywhere in `stx` (including `stx` itself). A notation use shows
up here as a node whose kind is the notation parser's name. -/
partial def collectSyntaxKinds (stx : Syntax) : Std.HashSet Name := Id.run do
  let mut acc : Std.HashSet Name := {}
  let mut worklist : Array Syntax := #[stx]
  while !worklist.isEmpty do
    let s := worklist.back!
    worklist := worklist.pop
    acc := acc.insert s.getKind
    for arg in s.getArgs do
      worklist := worklist.push arg
  return acc

/-- True for the notation/syntax-defining commands (needed to parse declarations that use them). -/
def isNotationCmd (k : SyntaxNodeKind) : Bool :=
  k == ``Parser.Command.«notation» || k == ``Parser.Command.«mixfix»
    || k == ``Parser.Command.«macro» || k == ``Parser.Command.«macro_rules»
    || k == ``Parser.Command.«syntax» || k == ``Parser.Command.«elab»

/-- True for the context-management commands we replay verbatim: scoping commands plus the
notation/syntax-defining commands needed to parse the declarations that use them. -/
def isContextCmd (stx : Syntax) : Bool :=
  let k := stx.getKind
  k == ``Parser.Command.namespace || k == ``Parser.Command.«end» || k == ``Parser.Command.«open»
    || k == ``Parser.Command.«variable» || k == ``Parser.Command.«section»
    || k == ``Parser.Command.«set_option» || k == ``Parser.Command.«universe»
    || isNotationCmd k

/-- The substring of `source` between two byte positions. -/
def slice (source : String) (s e : String.Pos.Raw) : String :=
  ({ str := source, startPos := s, stopPos := e } : Substring.Raw).toString

/-- The source `[cmdStart, cmdEnd)` with each `replace` byte range substituted by `sorry`. -/
def spliceSorry (source : String) (cmdStart cmdEnd : String.Pos.Raw)
    (replace : Array (String.Pos.Raw × String.Pos.Raw)) : String := Id.run do
  if replace.isEmpty then return slice source cmdStart cmdEnd
  let sorted := replace.qsort (fun a b => a.1.byteIdx < b.1.byteIdx)
  let mut out := ""
  let mut cursor := cmdStart
  for (s, e) in sorted do
    out := out ++ slice source cursor s ++ "sorry"
    cursor := e
  return out ++ slice source cursor cmdEnd

/-- Information needed to replace a definition's `deriving …` clause with `sorry` instances:
the byte position where the `deriving` keyword starts (everything from here is dropped), and the
generated `instance … := sorry` commands (one per derived class). Returns `none` if the command has
no `deriving` clause or its shape can't be reconstructed (in which case it is left verbatim). -/
def derivingReplacement? (source : String) (stx : Syntax) (cmdEnd : String.Pos.Raw) :
    Option (String.Pos.Raw × Array String) := Id.run do
  -- Only `def` deriving causes the delta-derivation failures; structures derive fine.
  let some defNode := findFirstOfKind? stx ``Parser.Command.definition | return none
  -- The `deriving` keyword atom inside the definition.
  let some derivingAtom := Id.run (do
    let mut wl : Array Syntax := #[defNode]
    while !wl.isEmpty do
      let s := wl.back!; wl := wl.pop
      match s with
      | .atom _ "deriving" => return some s
      | _ => for a in s.getArgs do wl := wl.push a
    return none) | return none
  let some dpos := derivingAtom.getPos? | return none
  let some dtail := derivingAtom.getTailPos? | return none
  -- Class names: the text after `deriving`, comma-separated.
  let classes := (slice source dtail cmdEnd).splitOn "," |>.filterMap (fun c =>
    let c := c.trimAscii.toString
    if c.isEmpty then none else some c)
  if classes.isEmpty then return none
  -- The declaration name and its binders.
  let some declId := findFirstOfKind? defNode ``Parser.Command.declId | return none
  let some idPos := declId.getPos? | return none
  let some idTail := declId.getTailPos? | return none
  let defName := slice source idPos idTail
  let some sig := findFirstOfKind? defNode ``Parser.Command.optDeclSig | return none
  let binderNodes := if sig.getArgs.size ≥ 1 then sig[0].getArgs else #[]
  let mut bindersText := ""
  let mut applyNames : Array String := #[]
  for b in binderNodes do
    match b.getPos?, b.getTailPos? with
    | some s, some e =>
      let btxt := slice source s e
      bindersText := if bindersText.isEmpty then btxt else bindersText ++ " " ++ btxt
      -- Explicit binders (and bare `binderIdent`s) are applied positionally; the rest are inferred.
      if b.getKind == ``Lean.Parser.Term.explicitBinder then
        let before := ((btxt.splitOn ":").headD btxt).replace "(" " " |>.replace ")" " "
        for nm in before.splitOn " " do
          let nm := nm.trimAscii.toString
          unless nm.isEmpty do applyNames := applyNames.push nm
      else if b.isIdent then
        applyNames := applyNames.push b.getId.toString
    | _, _ => return none
  let app := " ".intercalate (defName :: applyNames.toList)
  let bindersClause := if bindersText.isEmpty then "" else " " ++ bindersText
  let instances := classes.map fun c => s!"instance{bindersClause} : {c} ({app}) := sorry"
  return some (dpos, instances.toArray)

/-- Every identifier appearing anywhere in `stx`, as strings. -/
partial def collectIdents (stx : Syntax) : Array String := Id.run do
  let mut acc : Array String := #[]
  let mut worklist : Array Syntax := #[stx]
  while !worklist.isEmpty do
    let s := worklist.back!
    worklist := worklist.pop
    if s.isIdent then acc := acc.push s.getId.toString
    for a in s.getArgs do
      worklist := worklist.push a
  return acc

/-- Decomposes a `variable` command into its individual binders, each as `(source text, identifiers
referenced)`. The binders are the children of the `many1` node following the `variable` keyword. -/
def decomposeVariable (source : String) (stx : Syntax) : Array (String × Array String) := Id.run do
  let binderNodes := if stx.getArgs.size ≥ 2 then stx[1].getArgs else #[]
  let mut res : Array (String × Array String) := #[]
  for b in binderNodes do
    match b.getPos?, b.getTailPos? with
    | some s, some e => res := res.push (slice source s e, collectIdents b)
    | _, _ => pure ()
  return res

/-- The local names a `variable` binder introduces, parsed from its source text: the identifiers
before the first `:` (so `(a b : T)` / `{a b : T}` / `[inst : T]` give `a b` / `inst`), or — when
there is no `:` and it is not an instance binder — every identifier (so `{a b}` gives `a b`). These
names are locally bound; they must not be mistaken for global declarations that happen to share them
(e.g. a binder `{Ω : Type*}` when the project also defines a top-level `abbrev Ω`). -/
def binderBoundNames (binderSrc : String) : Array String :=
  let s := binderSrc.trimAsciiStart.toString
  let isInst := s.startsWith "["
  let beforeColon :=
    match s.splitOn ":" with
    | [whole] => if isInst then "" else whole   -- no `:` separator
    | head :: _ => head
    | [] => ""
  let isSep (c : Char) : Bool :=
    c == ' ' || c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']'
      || c == '⦃' || c == '⦄' || c == ','
  (beforeColon.split isSep).toArray.filterMap fun w =>
    let w := w.trimAscii.toString
    if w.isEmpty then none else some w

/-! ## Phase 1: process one source file -/

/-- Re-elaborates `source` against `env` and classifies every command. `declPos` maps the byte index
of each exposed declaration's range start to its name (so a command is a declaration command iff some
such position falls inside it).

Elaboration errors (notably "declaration already exists", since `env` already contains everything)
are expected and ignored — we only consume the parsed `Syntax` and source positions, which are
produced regardless. -/
def processFile (env : Environment) (source : String) (filePath : String)
    (declPos : Std.HashMap Nat Name) (notationKinds : Std.HashSet Name) :
    IO (Array CommandEntry) := do
  let inputCtx := Parser.mkInputContext source filePath
  let (_, parserState, messages) ← Parser.parseHeader inputCtx
  let cmdState := Command.mkState env messages {}
  let s ← IO.processCommands inputCtx parserState cmdState
  let mut entries : Array CommandEntry := #[]
  for stx in s.commands do
    if stx.getKind == ``Parser.Module.header then continue
    let some cmdStart := stx.getPos? | continue
    let some cmdEnd := stx.getTailPos? | continue
    -- Which exposed declarations does this command define?
    let mut names : Array Name := #[]
    for (pos, name) in declPos do
      if pos ≥ cmdStart.byteIdx && pos < cmdEnd.byteIdx then
        names := names.push name
    if !names.isEmpty then
      -- Theorems/lemmas: replace the whole proof with `sorry`. Definitions: keep the value verbatim
      -- but replace any embedded `by …` tactic proofs in it with `sorry`, and turn a `deriving`
      -- clause into standalone `instance … := sorry` (it can't be delta-derived in the minimal file).
      let (declEnd, appended) :=
        if isTheoremDecl stx then (cmdEnd, #[])
        else match derivingReplacement? source stx cmdEnd with
          | some (dpos, instances) => (dpos, instances)
          | none => (cmdEnd, #[])
      let src :=
        if isTheoremDecl stx then
          match findDeclVal? stx with
          | some (valStart, _) => slice source cmdStart valStart ++ ":= sorry"
          | none => slice source cmdStart cmdEnd
        else
          let byBlocks := match findDeclValStx? stx with
            | some v => collectByBlocks v
            | none => #[]
          spliceSorry source cmdStart declEnd byBlocks
      let usedNotations := notationKinds.toArray.filter (collectSyntaxKinds stx).contains
      entries := entries.push
        { cls := .decl, src, kind := stx.getKind, declNames := names, appended, usedNotations }
    else if isContextCmd stx then
      let kind := stx.getKind
      let nsName? := if kind == ``Parser.Command.namespace && stx.getArgs.size ≥ 2 then
        some stx[1].getId else none
      let binders := if kind == ``Parser.Command.«variable» then
        decomposeVariable source stx else #[]
      entries := entries.push
        { cls := .context, src := slice source cmdStart cmdEnd, kind, nsName?, binders }
    else
      entries := entries.push { cls := .skip, src := slice source cmdStart cmdEnd, kind := stx.getKind }
  return entries

/-! ## Phase 2: per-target filtering and section stripping -/

/-- Restricts declaration entries to those defining a declaration in `keep`; the rest become `skip`.
Context entries are preserved. -/
def restrictToTarget (entries : Array CommandEntry) (keep : Std.HashSet Name) : Array CommandEntry :=
  entries.map fun e =>
    match e.cls with
    | .decl => if e.declNames.any keep.contains then e else { e with cls := .skip }
    | _ => e

/-! ## Phase 3: assembly -/

/-- The external (non-project) modules to `import` for `modules`. Because project modules are emitted
inline rather than imported, an external (e.g. Mathlib) dependency may only be reachable *through* a
project module. So we walk the import graph transitively through project modules, collecting the
external "frontier" — every external module directly imported by any project module reachable from
`modules`. `public import`ing those covers their transitive dependencies. -/
partial def externalImports (env : Environment) (rootPrefix : Name) (modules : Array Name) :
    Array Name := Id.run do
  let directImports (modName : Name) : Array Name := Id.run do
    let some idx := env.getModuleIdx? modName | return #[]
    if h : idx.toNat < env.header.moduleData.size then
      return env.header.moduleData[idx.toNat].imports.map (·.module)
    return #[]
  let mut visited : Std.HashSet Name := {}     -- project modules already walked
  let mut seenExt : Std.HashSet Name := {}     -- external modules already collected
  let mut result : Array Name := #[]
  let mut stack := modules.toList
  while !stack.isEmpty do
    let modName := stack.head!
    stack := stack.tail!
    if visited.contains modName then continue
    visited := visited.insert modName
    for m in directImports modName do
      if m == `Init then continue
      if hasPrefixName m rootPrefix then
        stack := m :: stack            -- project module: recurse into its imports
      else if !seenExt.contains m then
        seenExt := seenExt.insert m    -- external module: part of the import frontier
        result := result.push m
  return result

/-- Re-renders a `variable` command, dropping only the binders that reference an *excluded* exposed
declaration — one outside the target's closure, hence not emitted here, so a reference to it would be
an undefined name. `excludedNames` holds those declarations' full names.

An identifier is treated as such a reference only if some in-scope namespace prefix (`activePrefixes`,
the open/entered namespaces) turns it into an excluded name, *and* it does not already denote an
external (non-project) constant. The latter guard is essential: otherwise a Mathlib type or class that
merely shares its last name component with a project declaration (e.g. `IndexedPartition`) would be
mistaken for the project one and its binder wrongly dropped, taking the binders it scopes with it.
Returns `none` if no binder survives. -/
def pruneVariable (env : Environment) (rootPrefix : Name) (excludedNames : Std.HashSet Name)
    (activePrefixes : Array Name) (boundVars : Std.HashSet Name) (e : CommandEntry) : Option String :=
  if e.binders.isEmpty then
    some e.src   -- couldn't decompose; keep verbatim
  else
    let refsExcluded (id : String) : Bool :=
      let n := id.toName
      if boundVars.contains n then
        false   -- a locally-bound `variable` name, not a global reference
      else if env.contains n && !isProjectLocalConst env rootPrefix n then
        false   -- an external (e.g. Mathlib) constant, not a project reference
      else
        activePrefixes.any fun pfx => excludedNames.contains (pfx ++ n)
    let kept := e.binders.filter fun (_, idents) => !idents.any refsExcluded
    if kept.isEmpty then none
    else some ("variable " ++ " ".intercalate (kept.map (·.1)).toList)

/-- Role of a pre-rendered output chunk for scope balancing in `stripEmptyScopes`. -/
inductive ScopeTag where
  /-- Opens a strippable scope: `section`. Dropped if it ends up empty / `variable`-only. -/
  | openSection
  /-- Opens an always-kept scope: `namespace X`. Retained even when empty, so the namespace
  reliably exists for later references. -/
  | openNamespace
  /-- Closes a scope: `end` or `end X`. -/
  | close
  /-- A `variable` line: content that does *not*, on its own, justify keeping its scope. -/
  | soft
  /-- A declaration or any other context command: forces the enclosing scope to be kept. -/
  | hard
  deriving BEq, Inhabited

/-- Collapses runs of two or more consecutive blank lines into a single blank line. -/
def collapseBlankRuns (s : String) : String :=
  let isBlank (l : String) : Bool := l.all Char.isWhitespace
  let collapsed := s.splitOn "\n" |>.foldl (init := ([] : List String)) fun acc line =>
    match acc with
    | prev :: _ => if isBlank line && isBlank prev then acc else line :: acc
    | [] => [line]
  "\n".intercalate collapsed.reverse

/-- Drops `section` and `namespace` scopes that contain no declarations and no context beyond
`variable` lines (which are scoped to the dropped block, hence safe to remove with it). An empty or
`variable`-only `namespace … end` block is useless here because the namespace stubs emitted at the
top of the file already declare it for later references. `items` pairs each pre-rendered output chunk
with a `ScopeTag` describing its role. A scope is kept iff it (transitively) contains a `hard` chunk;
otherwise the whole `… end` block — `variable` lines included — is dropped. Because matching
opens/closes are tracked on a stack, nesting stays balanced regardless of how deep an empty block
is. -/
def stripEmptyScopes (items : Array (ScopeTag × String)) : String := Id.run do
  -- Stack of open scopes: (rendered open chunk, accumulated inner chunks, must be kept?).
  let mut stack : Array (String × Array String × Bool) := #[]
  let mut top : Array String := #[]   -- chunks already committed at the current outermost level
  for (tag, s) in items do
    match tag with
    | .openSection => stack := stack.push (s, #[], false)
    -- Namespaces start as "droppable" too: an empty or `variable`-only `namespace … end` later in
    -- the file is useless, since the namespace stubs at the top already declare it for `open`s.
    | .openNamespace => stack := stack.push (s, #[], false)
    | .close =>
      if stack.isEmpty then
        top := top.push s   -- unbalanced (shouldn't happen): emit verbatim
      else
        let (openLine, lines, hasContent) := stack.back!
        stack := stack.pop
        if hasContent then
          let rendered := (#[openLine] ++ lines).push s
          if stack.isEmpty then
            top := top ++ rendered
          else
            let (po, pl, _) := stack.back!
            stack := stack.set! (stack.size - 1) (po, pl ++ rendered, true)
        -- else: drop the scope (open chunk, inner `variable` lines, and close chunk) entirely.
    | .soft =>
      if stack.isEmpty then
        top := top.push s
      else
        let (o, l, h) := stack.back!
        stack := stack.set! (stack.size - 1) (o, l.push s, h)
    | .hard =>
      if stack.isEmpty then
        top := top.push s
      else
        let (o, l, _) := stack.back!
        stack := stack.set! (stack.size - 1) (o, l.push s, true)
  -- Flush any unclosed scopes verbatim (shouldn't happen with well-formed sources).
  for (openLine, lines, _) in stack do
    top := (top.push openLine) ++ lines
  return String.join top.toList

/-- Assembles the standalone file for `target`. `cache` holds the processed entries per module;
`moduleOrder` lists the project modules in dependency-first order; `keep` is the target's transitive
closure (declarations to emit); `exposedNames` is every exposed declaration (to recognise references
to declarations *outside* `keep`). -/
def assembleTarget (env : Environment) (rootPrefix : Name) (cache : Std.HashMap Name (Array CommandEntry))
    (moduleOrder : Array Name) (exposedNames keep projectNamespaces : Std.HashSet Name)
    (target : Name) : String := Id.run do
  -- Modules contributing at least one kept declaration, in dependency order, with their filtered
  -- (and section-stripped) entries.
  let mut involved : Array (Name × Array CommandEntry) := #[]
  for modName in moduleOrder do
    if let some entries := cache.get? modName then
      -- Keep every context command (so `namespace`/`section`/`end` nesting stays balanced) and the
      -- declarations in the closure; other declarations become `skip`.
      let filtered := restrictToTarget entries keep
      if filtered.any (·.cls == .decl) then
        involved := involved.push (modName, filtered)
  -- Exposed declarations *not* emitted in this file: a `variable` binder referencing one of these
  -- would reference an undefined name, so such binders are dropped (see `pruneVariable`).
  let excludedNames : Std.HashSet Name := exposedNames.fold (init := {}) fun s n =>
    if keep.contains n then s else s.insert n
  -- All names bound by `variable` commands in this file: these are local, so an identifier matching
  -- one is not a reference to a same-named global declaration (e.g. the project's top-level `Ω`).
  let boundVars : Std.HashSet Name := Id.run do
    let mut s : Std.HashSet Name := {}
    for (_, entries) in involved do
      for e in entries do
        if e.kind == ``Parser.Command.«variable» then
          for (bsrc, _) in e.binders do
            for nm in binderBoundNames bsrc do
              s := s.insert nm.toName
    return s
  -- Project namespaces entered (`namespace Foo`) or opened (`open … Foo …`) across the involved
  -- modules. We emit existence stubs for them up front, since an `open Foo` may precede the
  -- `namespace Foo` that (re)creates `Foo` here — and may even refer to a namespace no kept
  -- declaration re-enters.
  let nsStubs : Array Name := Id.run do
    let mut seen : Std.HashSet Name := {}
    let mut acc : Array Name := #[]
    let add (ns : Name) (seen : Std.HashSet Name) (acc : Array Name) :=
      if seen.contains ns then (seen, acc) else (seen.insert ns, acc.push ns)
    for (_, entries) in involved do
      for e in entries do
        if let some ns := e.nsName? then
          (seen, acc) := add ns seen acc
        else if e.kind == ``Parser.Command.«open» then
          -- Tokens after `open`/`scoped` that name a project namespace.
          for tok in (e.src.replace "\n" " ").splitOn " " do
            let nm := tok.trimAscii.toString.toName
            if projectNamespaces.contains nm then
              (seen, acc) := add nm seen acc
    return acc
  let imports := externalImports env rootPrefix (involved.map (·.1))
  -- The extracted files are terminal and self-contained (nothing imports them), so the source's
  -- module-system scaffolding (`module` header, `public import`, `@[expose] public section`) is
  -- unnecessary: plain `import`s suffice, and the `@[expose] public section` wrappers are dropped
  -- below.
  let importBlock := if imports.isEmpty then "import Mathlib\n" else
    String.join (imports.toList.map (fun i => s!"import {i}\n"))
  let mut out := importBlock
  out := out ++ s!"\n/-! # Standalone extraction for `{target}`\n"
    ++ "Definitions are copied verbatim; theorem proofs are replaced by `sorry`.\n"
    ++ "Auto-generated by LMLExposition. -/\n"
  -- Replayed `notation`/`macro` commands may mention declarations that appear later in the file;
  -- defer identifier resolution in their right-hand sides to use sites.
  out := out ++ "\nset_option quotPrecheck false\n"
  unless nsStubs.isEmpty do
    out := out ++ "\n-- Namespace stubs (so later `open`s resolve).\n"
    for ns in nsStubs do
      out := out ++ s!"namespace {ns}\nend {ns}\n"
  -- Build the per-module body as tagged chunks, then drop empty/`variable`-only scopes.
  let mut items : Array (ScopeTag × String) := #[]
  -- Namespace prefixes in scope when resolving `variable` binder identifiers: the root plus every
  -- entered (`namespace`) or opened (`open`) namespace. Accumulated (never popped) as an
  -- over-approximation of scope; `pruneVariable` only matches exact excluded names against it.
  let mut activePrefixes : Array Name := #[Name.anonymous]
  for (modName, entries) in involved do
    let shortName :=
      if hasPrefixName modName rootPrefix then
        modName.toString.drop (rootPrefix.toString.length + 1)
      else modName.toString
    items := items.push (.hard, s!"\n-- ═══ {shortName} ═══\n")
    for e in entries do
      match e.cls with
      | .context =>
        let trimmedSrc := e.src.trimAsciiStart.toString
        if trimmedSrc.startsWith "@[expose]" || (trimmedSrc.splitOn "public section").length > 1 then
          pure ()   -- drop the module-system `@[expose] public section` wrapper
        else if e.kind == ``Parser.Command.«variable» then
          if let some v := pruneVariable env rootPrefix excludedNames activePrefixes boundVars e then
            items := items.push (.soft, v ++ "\n")
        else if e.kind == ``Parser.Command.namespace then
          if let some ns := e.nsName? then
            activePrefixes := activePrefixes.push ns
          items := items.push (.openNamespace, e.src ++ "\n")
        else if e.kind == ``Parser.Command.«section» then
          items := items.push (.openSection, e.src ++ "\n")
        else if e.kind == ``Parser.Command.«end» then
          items := items.push (.close, e.src ++ "\n")
        else if e.kind == ``Parser.Command.«open» then
          -- Tokens after `open`/`scoped` name namespaces brought into scope.
          for tok in (e.src.replace "\n" " ").splitOn " " do
            let nm := tok.trimAscii.toString.toName
            unless nm.isAnonymous do activePrefixes := activePrefixes.push nm
          -- Like `variable`: emitted if its scope survives, but doesn't on its own keep an otherwise
          -- empty `section`/`namespace` alive.
          items := items.push (.soft, e.src ++ "\n")
        else
          items := items.push (.hard, e.src ++ "\n")
      | .decl =>
        let mut s := "\n" ++ e.src ++ "\n"
        for extra in e.appended do
          s := s ++ extra ++ "\n"
        s := s ++ "\n"
        items := items.push (.hard, s)
      | .skip => pure ()
  out := out ++ stripEmptyScopes items
  return (collapseBlankRuns out).trimAsciiEnd.toString ++ "\n"

/-! ## Driver -/

/-- Computes the byte index (in `source`) of the start of each exposed declaration's range, for the
declarations in `modDecls`. -/
def declPositions (env : Environment) (source : String) (modDecls : Array DeclInfo) :
    IO (Std.HashMap Nat Name) := do
  let fileMap := FileMap.ofString source
  let mut m : Std.HashMap Nat Name := {}
  for decl in modDecls do
    if let some ranges ← findRanges? env decl.name then
      m := m.insert (fileMap.ofPosition ranges.range.pos).byteIdx decl.name
  return m

/-- Writes a verbatim standalone `<anchorId>.lean` file for every declaration in `decls` into `dir`.
Each project source file is processed once; targets are then assembled by filtering. Returns the
number of files written. -/
def writeAllExtractions (env : Environment) (rootPrefix : Name)
    (decls : Array DeclInfo) (projectDir : System.FilePath)
    (dir : System.FilePath) : IO Nat := do
  let exposedNames : Std.HashSet Name := decls.foldl (·.insert ·.name) {}
  -- Exposed notation parsers; a declaration's source uses one iff its parsed syntax contains a node
  -- of that kind (the notation's name).
  let notationKinds : Std.HashSet Name :=
    decls.foldl (init := {}) fun s d => if isNotationKind env d.name then s.insert d.name else s
  -- Every project namespace, taken as the proper-prefix ancestors of the exposed declaration names.
  let projectNamespaces : Std.HashSet Name := decls.foldl (init := {}) fun s d =>
    (namespaceAncestors d.name.getPrefix).foldl (·.insert ·) s
  -- Group exposed declarations by module.
  let declsByModule : Std.HashMap Name (Array DeclInfo) :=
    decls.foldl (fun m d => m.insert d.moduleName ((m.getD d.moduleName #[]).push d)) {}
  -- Project modules in dependency-first order (the order of `env.header.moduleNames`), restricted to
  -- those that contain an exposed declaration.
  let moduleOrder : Array Name := env.header.moduleNames.filter declsByModule.contains
  -- Phase 1: process each contributing source file once.
  let mut cache : Std.HashMap Name (Array CommandEntry) := {}
  for modName in moduleOrder do
    let modDecls := declsByModule.getD modName #[]
    let path := moduleSourcePath projectDir modName
    let some source ← (do try pure (some (← IO.FS.readFile path)) catch _ => pure none)
      | continue
    let declPos ← declPositions env source modDecls
    let entries ← processFile env source path.toString declPos notationKinds
    cache := cache.insert modName entries
  -- Map each declaration to the notation parsers its source uses (gathered syntactically above).
  let mut declUsedNotations : Std.HashMap Name (Array Name) := {}
  for (_, entries) in cache.toList do
    for e in entries do
      if e.cls == .decl && !e.usedNotations.isEmpty then
        for nm in e.declNames do
          declUsedNotations := declUsedNotations.insert nm e.usedNotations
  -- Phase 3: assemble and write one file per declaration.
  IO.FS.createDirAll dir
  for decl in decls do
    let mut keep : Std.HashSet Name :=
      (decl.transDeps.filter exposedNames.contains).foldl (·.insert ·) ({} : Std.HashSet Name)
        |>.insert decl.name
    -- Close under notation usage: a kept declaration whose source uses a notation needs that
    -- notation's command replayed, and notations may themselves use further notations.
    let mut frontier : Array Name := keep.toArray
    while !frontier.isEmpty do
      let mut next : Array Name := #[]
      for n in frontier do
        for nk in declUsedNotations.getD n #[] do
          unless keep.contains nk do
            keep := keep.insert nk
            next := next.push nk
      frontier := next
    let content := assembleTarget env rootPrefix cache moduleOrder exposedNames keep
      projectNamespaces decl.name
    IO.FS.writeFile (dir / s!"{anchorIdOf decl.name}.lean") content
  return decls.size

end LMLExposition
