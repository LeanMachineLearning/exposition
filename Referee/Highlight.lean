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
  let scopes :=
    let sc := commandState.scopes[0]!
    { sc with opts := sc.opts.setBool `pp.tagAppFns true } :: commandState.scopes.tail!
  let commandState := { commandState with scopes }
  let cmdSt ← IO.mkRef { commandState, parserState, cmdPos := parserState.pos }
  let res ← Compat.Frontend.processCommands headerStx pctx cmdSt
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
  IO.FS.writeFile outPath (toString (ToJson.toJson result))

/-- Worker entry point for a standalone file (an extracted minimal file rather than a project
module): highlight it and write its JSON, including whether it compiled. -/
unsafe def writeFileHighlighting (leanPath outPath : System.FilePath) : IO Unit := do
  let result ← highlightSource leanPath
  if let some parent := outPath.parent then
    IO.FS.createDirAll parent
  IO.FS.writeFile outPath (toString (ToJson.toJson result))

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
