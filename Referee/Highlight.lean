module

public import Lean
public import SubVerso.Compat
public import SubVerso.Highlighting
public import SubVerso.Module

/-!
# Source-text highlighting for project modules

Produces `SubVerso.Highlighting.Highlighted` for every command of a project module, by running the
Lean frontend over the module's source and highlighting the resulting syntax against its info
trees.

This is the expensive tier of highlighting. The cheap tier — a declaration's *pretty-printed*
signature — needs only the environment and already runs during `collect` (see
`Referee.mkDocstringBlock?`). Highlighting *source text* is different: `highlight` needs
info trees and messages, which only real elaboration produces. So this module re-elaborates each
module from source.

Each command comes back tagged with the names it defines, which is what lets later phases map a
declaration to its highlighted source, and assemble a minimal file's rendering out of the
highlighted forms of the declarations it inlines.

Because `importModules` must run against a fresh environment, one module is processed per
process; `Referee.Website.Site` drives the fan-out by re-invoking this executable.
-/

open Lean Elab Frontend
open Lean.Elab.Command hiding Context
open SubVerso Module
open SubVerso.Highlighting (Highlighted highlightFrontendResult)

namespace Referee.Highlight

@[expose] public section

/-- The node kind of a command, looking through outer `in` combinators (`set_option … in def …`
reports the `def`'s kind, not `in`'s). -/
partial def commandKind (cmd : Syntax) : SyntaxNodeKind :=
  match cmd with
  | `(command|$_cmd1 in $cmd2) => commandKind cmd2
  | _ => cmd.getKind

/-- Where `declCode`'s left-to-right pass over one command's highlighting has got to. -/
structure DeclCodeState where
  /-- Whether anything that is not whitespace has been emitted yet. While this is false, whitespace
  is dropped rather than emitted: it is the gap `FrontendResult.updateLeading` scooped up from
  between this command and the one before it, not part of the code. -/
  started : Bool := false
  /-- Whether the pass is past the point where the declaration's own docstring could still appear:
  either it was found and dropped, or the scan reached the declaration's name, after which a doc
  comment documents a field or a constructor and stays. -/
  finished : Bool := false
  /-- Whether the doc comment was dropped by the node just processed, so the newline it ended on can
  go with it. -/
  dropped : Bool := false
deriving Inhabited

/-- Drops the indentation a dropped doc comment sat on off the end of the output built so far.

Together with the newline `declCodeGo` drops after the doc comment, this is what makes removing a
docstring remove *its lines* rather than leave the blank line its text used to fill. Only spaces and
tabs go: the newline before them ends the previous line, and any blank line the author left above the
docstring is theirs to keep. -/
def popIndent (out : Array Highlighted) : Array Highlighted :=
  match out.back? with
  | some (.text s) =>
    let s := String.ofList (s.toList.reverse.dropWhile (fun c => c == ' ' || c == '\t')).reverse
    out.pop.push (.text s)
  | _ => out

/-- One node of `declCode`'s pass, threading `DeclCodeState` through the tree in document order.
Nodes it drops become `.empty` rather than disappearing, so the shape of the tree is preserved. -/
partial def declCodeGo (name : Name) (st : DeclCodeState) :
    Highlighted → DeclCodeState × Highlighted
  | hl@(.token tok) =>
    if st.finished then ({ st with started := true, dropped := false }, hl)
    else match tok.kind with
      -- The declaration's own docstring: the only doc comment that can precede the name, since the
      -- ones that document fields and constructors are written inside the declaration.
      | .docComment => ({ st with finished := true, dropped := true }, .empty)
      -- The defining occurrence of the name. Reaching it without having seen a doc comment means
      -- there was none to drop, and everything past it must be left alone.
      | .const n _ _ true _ =>
        ({ st with started := true, finished := st.finished || n == name, dropped := false }, hl)
      | _ => ({ st with started := true, dropped := false }, hl)
  | .text s =>
    if !st.started then
      let s := s.trimAsciiStart.toString
      ({ st with started := !s.isEmpty, dropped := false }, .text s)
    else if st.dropped then
      ({ st with dropped := false }, .text (if s.startsWith "\n" then (s.drop 1).toString else s))
    else (st, .text s)
  | .seq hls => Id.run do
    let mut st := st
    let mut out : Array Highlighted := #[]
    for hl in hls do
      let (st', hl') := declCodeGo name st hl
      -- The doc comment was dropped by this node, so the line it sat on goes with it.
      if st'.dropped && !st.dropped then
        out := popIndent out
      st := st'
      out := out.push hl'
    return (st, .seq out)
  | .span info content =>
    let (st, content) := declCodeGo name st content
    (st, .span info content)
  | .tactics info startPos endPos content =>
    let (st, content) := declCodeGo name st content
    (st, .tactics info startPos endPos content)
  | hl@(.point ..) => (st, hl)
  | hl@(.unparsed s) =>
    if !st.started && s.all Char.isWhitespace then (st, .empty)
    else ({ st with started := true }, hl)

/-- The highlighted source of the command defining `name`, as a page showing that one declaration
wants it: without the docstring, and starting at the code rather than at the gap above it.

Two things are dropped, both of which the declaration page would otherwise show twice or show as
part of a declaration they do not belong to:

* **the declaration's own docstring**, which the page renders above the code from the environment's
  copy of it. Only the doc comment written before the declaration's name goes; the ones documenting
  a structure's fields or an inductive type's constructors are part of the code and stay.
* **the leading whitespace**, which is the blank line or two between this command and the one before
  it. `FrontendResult.updateLeading` attaches it to this command so that rendering a whole file
  reproduces the file; rendering one declaration on its own does not want it. A comment written
  above the declaration is kept — it is the author's, not a rendering artefact.

Used only for the declaration card. A whole extracted file is rendered from the same highlighting
untouched, docstrings and all: there the docstring is not shown anywhere else, and the point of the
file is to be the source. -/
def declCode (name : Name) (hl : Highlighted) : Highlighted :=
  (declCodeGo name {} hl).2

/-- One source file's highlighting, together with whatever elaboration complained about.

Carrying the errors is the point of highlighting the *extracted* minimal files rather than only
project modules: producing the highlighting elaborates the file, so whether it compiles falls out
of the same pass that makes it readable. The site can then say which minimal files are verified
and which are not, instead of presenting all of them as if they were. -/
structure FileHighlighting where
  items : Array ModuleItem
  errors : Array String
deriving Inhabited

/-- Serializes via `Module`'s shared-token encoding, which is dramatically more compact than
encoding each command's highlighting independently. -/
def FileHighlighting.toJson (f : FileHighlighting) : Json :=
  Json.mkObj [
    ("module", (Module.mk f.items).toJson),
    ("errors", ToJson.toJson f.errors)
  ]

def FileHighlighting.fromJson? (json : Json) : Except String FileHighlighting := do
  let mod ← Module.fromJson? (← json.getObjVal? "module")
  let errors ← json.getObjValAs? (Array String) "errors"
  return { items := mod.items, errors }

instance : ToJson FileHighlighting := ⟨FileHighlighting.toJson⟩
instance : FromJson FileHighlighting := ⟨FileHighlighting.fromJson?⟩

/-! ## Driving the frontend with asynchronous elaboration

`Elab.async` defaults to `false`, and is turned on only by `runFrontend` and the language server —
so a tool that drives `Command.elabCommandTopLevel` itself, as this one does, elaborates every
command on a single thread no matter how many cores it was given. On a monolithic module that is
the dominant cost: on a 3 000-line file, elaboration measured 17.5 s sequentially against 1.7 s
with the option set, and the whole `highlight-module` run went from 41.9 s to 12.7 s.

Turning it on has a price the option's own documentation names — the caller becomes "responsible
for processing messages and other data not only in the resulting command state but also from async
tasks". Two things move out of the command state, and reading it the obvious way loses both
*silently*:

* **Info trees.** A command's tree keeps `hole`s whose contents arrive later, recorded in
  `InfoState.lazyAssignment`. Taking `infoState.trees` directly yields the holes unfilled, and
  highlighting quietly drops everything inside them. Measured on the same file: 96 of 146
  declarations lost their `definedNames`, which is the key `build-site` maps a declaration to its
  highlighting by — so they would have rendered as plain code, with `errors` still reporting none.
  `InfoState.substituteLazy` fills the holes in.
* **Messages.** Diagnostics raised inside an asynchronous task are reported through
  `Command.State.snapshotTasks` rather than accumulating in `State.messages`.

Both are gathered *after* the command loop rather than inside it, and that is what preserves the
win: a proof body elaborates while the frontend moves on to the next command, so forcing each one
where it is produced would serialize precisely what the option parallelizes. -/

/-- One command's output, captured before its asynchronous parts have been waited for.

`infoState` is kept whole rather than reduced to its trees, because `lazyAssignment` — the part that
says what is still missing — lives on it and must survive until `finishItems`. -/
structure PendingItem where
  commandSyntax : Syntax
  infoState : InfoState
  /-- Messages already in the command state when the command returned. -/
  messages : MessageLog
  /-- Tasks this command spawned; their diagnostics are the other half of its messages. -/
  snaps : Array (Language.SnapshotTask Language.SnapshotTree)

/-- Parses and elaborates one command, returning whether it was the last.

Mirrors SubVerso's `Compat.Frontend.processCommand`, except that it defers the two pieces that
asynchronous elaboration makes expensive to read eagerly. -/
def processPendingCommand : FrontendM (Bool × PendingItem) := do
  updateCmdPos
  let cmdState ← getCommandState
  let ictx ← getInputContext
  let pstate ← getParserState
  let scope := cmdState.scopes.head!
  let pmctx := { env := cmdState.env, options := scope.opts,
                 currNamespace := scope.currNamespace, openDecls := scope.openDecls }
  let (cmd, ps, messages) :=
    profileit "parsing" scope.opts fun _ =>
      Parser.parseCommand ictx pmctx pstate cmdState.messages
  modify fun s => { s with commands := s.commands.push cmd }
  setParserState ps
  setMessages {}
  runCommandElabM <| setInfoState { enabled := true }
  elabCommandAtFrontend cmd
  let st ← getCommandState
  let item : PendingItem := {
    commandSyntax := cmd
    infoState := st.infoState
    messages := messages ++ st.messages
    snaps := st.snapshotTasks
  }
  -- Taken, not copied: leaving them would make the next command collect this one's tasks again,
  -- and every later command's messages would grow by everything before it.
  modify fun s => { s with commandState := { s.commandState with snapshotTasks := #[] } }
  pure (Parser.isTerminalCommand cmd, item)

/-- Waits for every command's asynchronous work and assembles the frontend result.

The only blocking point in the pipeline. By the time it runs, every command has been dispatched, so
the tasks it waits on have been running concurrently rather than one after another. -/
def finishItems (headerSyntax : Syntax) (pending : Array PendingItem) :
    Compat.Frontend.FrontendResult :=
  { headerSyntax
    items := pending.map fun p => {
      commandSyntax := p.commandSyntax
      info := p.infoState.substituteLazy.get.trees
      messages := p.snaps.foldl (init := p.messages) fun msgs task =>
        task.get.getAll.foldl (init := msgs) (· ++ ·.diagnostics.msgLog) } }

/-- Runs the frontend over every command of the file, elaborating asynchronously where Lean can. -/
partial def processCommandsAsync (headerSyntax : Syntax) :
    FrontendM Compat.Frontend.FrontendResult := do
  let mut done := false
  let mut pending := #[]
  while !done do
    let (done', item) ← processPendingCommand
    done := done'
    pending := pending.push item
  return finishItems headerSyntax pending

/-- Runs the Lean frontend over a source file and returns one `ModuleItem` per command — its
source range, syntax kind, the names it defines, and its highlighted code — plus any elaboration
errors.

Mirrors SubVerso's `subverso-extract-mod` executable, but returns the items rather than writing
JSON, so callers can filter and re-assemble them. `asServer := true` matches the language
server's view (imports include private parts), which is what makes hover information available
for everything a reader can see in the source. -/
unsafe def highlightSource (fname : System.FilePath) : IO FileHighlighting := do
  initSearchPath (← findSysroot)
  let contents ← IO.FS.readFile fname
  let fm := FileMap.ofString contents
  let ictx := Parser.mkInputContext contents fname.toString
  let (headerStx, parserState, msgs) ← Parser.parseHeader ictx
  let imports := headerToImports headerStx
  enableInitializersExecution
  let isModule := Compat.isModule headerStx
  let env ← Compat.importModules imports {} (isModule := isModule) (asServer := true)
  let pctx : Context := { inputCtx := ictx }
  let commandState : Command.State := { env, maxRecDepth := defaultMaxRecDepth, messages := msgs }
  -- `pp.tagAppFns` makes the delaborator tag applied functions, so that function positions in
  -- rendered terms carry hover information instead of being inert text.
  --
  -- `Elab.async` opts into multi-threaded elaboration, which `runFrontend` and the language server
  -- set for themselves but a caller driving the frontend directly does not get. See the section
  -- above for what `processCommandsAsync` has to do to earn it.
  let scopes :=
    let sc := commandState.scopes[0]!
    { sc with opts := (sc.opts.setBool `pp.tagAppFns true).setBool `Elab.async true }
      :: commandState.scopes.tail!
  let commandState := { commandState with scopes }
  let cmdSt ← IO.mkRef { commandState, parserState, cmdPos := parserState.pos }
  let res ← processCommandsAsync headerStx pctx cmdSt
  let res := res.updateLeading contents
  let hls ← (Frontend.runCommandElabM <| liftTermElabM <| highlightFrontendResult res) pctx cmdSt
  let items : Array ModuleItem := hls.zip res.syntax |>.map fun (hl, stx) => {
    defines := hl.definedNames.toArray
    kind := commandKind stx
    range := stx.getRange?.map fun ⟨s, e⟩ => (fm.toPosition s, fm.toPosition e)
    code := hl
  }
  let errorMessages := res.items.flatMap fun item =>
    (Compat.messageLogArray item.messages).filter fun m => m.severity == .error
  let errors ← errorMessages.mapM fun m => m.toString
  return { items, errors }

/-- Resolves a module name to its source file and highlights it. -/
unsafe def highlightModule (modName : Name) : IO FileHighlighting := do
  initSearchPath (← findSysroot)
  let sp ← Compat.initSrcSearchPath
  let sp : SearchPath := (sp : List System.FilePath) ++ [("." : System.FilePath)]
  let some fname ← sp.findModuleWithExt "lean" modName
    | throw <| IO.userError s!"Failed to find source for module {modName} in {sp}"
  highlightSource fname

/-- Where a module's highlighting lands inside the highlighting directory. -/
def moduleFile (dir : System.FilePath) (modName : Name) : System.FilePath :=
  dir / s!"{modName}.json"

/-- Worker entry point: highlight one module and write its JSON. -/
unsafe def writeModuleHighlighting (modName : Name) (outPath : System.FilePath) : IO Unit := do
  let result ← highlightModule modName
  if let some parent := outPath.parent then
    IO.FS.createDirAll parent
  -- `compress`, not `toString`: `ToString Json` pretty-prints, which on a single module cost
  -- 651 ms against 91 ms and wrote 11.3 MB where 9.2 MB says the same thing. These files are
  -- an intermediate that only `build-site` reads back, so the indentation buys nothing and is
  -- paid for twice — once writing it, once parsing it again. `collect` already writes its data
  -- this way.
  IO.FS.writeFile outPath (ToJson.toJson result).compress

/-- Worker entry point for a standalone file (an extracted minimal file rather than a project
module): highlight it and write its JSON, including whether it compiled. -/
unsafe def writeFileHighlighting (leanPath outPath : System.FilePath) : IO Unit := do
  let result ← highlightSource leanPath
  if let some parent := outPath.parent then
    IO.FS.createDirAll parent
  -- `compress`, not `toString`: `ToString Json` pretty-prints, which on a single module cost
  -- 651 ms against 91 ms and wrote 11.3 MB where 9.2 MB says the same thing. These files are
  -- an intermediate that only `build-site` reads back, so the indentation buys nothing and is
  -- paid for twice — once writing it, once parsing it again. `collect` already writes its data
  -- this way.
  IO.FS.writeFile outPath (ToJson.toJson result).compress

/-- One unit of work in a fan-out run: a display label and the arguments to pass the worker. -/
structure WorkItem where
  label : String
  args : Array String
deriving Inhabited

/-- One unit's outcome. -/
structure WorkerResult where
  label : String
  ok : Bool
  message : String
deriving Inhabited

/-- Runs `exe` once per work item, at most `jobs` at a time.

Highlighting has to re-import the file's dependencies, which can only happen against a fresh
environment, so each file gets its own process. Workers inherit this process's environment and
working directory, which is what keeps them inside the target project's `lake env`. -/
def runFanOut (exe : System.FilePath) (items : Array WorkItem) (jobs : Nat) :
    IO (Array WorkerResult) := do
  let jobs := max 1 jobs
  let mut results : Array WorkerResult := #[]
  let batchCount := (items.size + jobs - 1) / jobs
  for b in [0:batchCount] do
    let i := b * jobs
    let batch := items.extract i (min (i + jobs) items.size)
    -- `.dedicated` because each task blocks on a child process; the default task pool would
    -- otherwise be starved by workers that are only waiting.
    let tasks ← batch.mapM fun item =>
      (·, item) <$> IO.asTask (prio := .dedicated)
        (IO.Process.output { cmd := exe.toString, args := item.args })
    for (task, item) in tasks do
      match task.get with
      | .error e => results := results.push ⟨item.label, false, toString e⟩
      | .ok out =>
        if out.exitCode == 0 then
          results := results.push ⟨item.label, true, ""⟩
        else
          let msg := if out.stderr.isEmpty then out.stdout else out.stderr
          results := results.push ⟨item.label, false, msg⟩
  return results

/-- Work items highlighting each project module into `dir`. -/
def moduleWorkItems (modules : Array Name) (dir : System.FilePath) : Array WorkItem :=
  modules.map fun modName => {
    label := modName.toString
    args := #["highlight-module", "--module", modName.toString,
              "--output", (moduleFile dir modName).toString]
  }

/-- Work items highlighting each extracted minimal `.lean` file into `dir`. -/
def extractedWorkItems (files : Array System.FilePath) (dir : System.FilePath) : Array WorkItem :=
  files.map fun path =>
    let stem := path.fileStem.getD "unknown"
    { label := stem
      args := #["highlight-file", "--input", path.toString,
                "--output", (dir / s!"{stem}.json").toString] }

end

end Referee.Highlight
