import LeanExposition.Collect

/-!
# Standalone Lean file extraction

Given one exposed declaration, build a self-contained Lean file that contains every (project-local)
declaration it transitively depends on, in topological order. **Theorem proofs are replaced by
`sorry`**, and proof subterms inside definitions are replaced by `sorry` too, so the file never
re-runs a proof.

## Strategy: re-render from the elaborated environment

Rather than copying source text (which needs the original file's `open`/`variable`/`namespace`
context to make sense), each declaration is re-rendered from its elaborated `ConstantInfo` with the
pretty-printer set to `pp.fullNames := true` and `pp.notation := false`. The elaborated type already
contains exactly the section `variable`s the declaration uses (as binders), and fully-qualified,
notation-free output resolves against the imports alone — so **no namespaces are opened and no
`variable`/`section` context is replayed**. Every declaration is emitted at top level under its full
name (`theorem A.B.c : … := sorry`).

* theorems → `theorem <fullName> : <type> := sorry`
* definitions / instances → `def`/`instance <fullName> : <type> := <value>` with proof subterms in
  the value replaced by `sorry`
* axioms / opaques → `axiom`/`opaque <fullName> : <type>` (opaque bodies become `sorry`)
* structures / classes / inductives → reconstructed from the environment (`extends`, fields, params,
  constructors)

Only external (non-project) modules are `import`ed (the union of the dependencies' source files'
imports); project declarations are emitted here instead.
-/

open Lean Lean.Meta

namespace LeanExposition

/-! ## Selecting and ordering declarations -/

/-- The selected declarations in topological order: the target's transitive (project-local)
dependencies followed by the target itself. -/
def emitOrder (declByName : Std.HashMap Name DeclInfo) (target : DeclInfo) : Array DeclInfo :=
  (target.transDeps.filterMap declByName.get?).push target

/-- The upstream library modules to `import`: the modules of every external (non-project) constant a
selected declaration depends on. This is precise — it imports exactly what the fully-qualified
rendered output references, including transitively-needed constants like `condDistrib` that the
source file only imports indirectly. Project-local modules are excluded (their declarations are
emitted here) and `Init` (auto-imported) is skipped. -/
def importModules (env : Environment) (rootPrefix : Name)
    (declByName : Std.HashMap Name DeclInfo) (emit : Array DeclInfo) : Array Name := Id.run do
  let mut modules : Std.HashSet Name := {}
  for decl in emit do
    let depset := if decl.kind == .theorem then decl.typeDeps else decl.deps
    for dep in depset do
      if !declByName.contains dep then
        if let some m := moduleNameOf env dep then
          if !hasPrefixName m `Init && !hasPrefixName m rootPrefix then
            modules := modules.insert m
  return modules.toArray.qsort Name.lt

/-! ## Rendering declarations from the elaborated environment -/

/-- Pretty-prints an expression. The ambient `pp.fullNames` / `pp.notation` options (set in the
`Core.Context`) make the result fully qualified and notation-free. -/
def ppFull (e : Expr) : MetaM String := do
  -- Render with a very large width so each declaration stays on one line (wrapped output breaks
  -- `structure … where` field parsing and multi-line binders).
  return (← ppExpr (← instantiateMVars e)).pretty (width := 100000)

/-- Strips `autoParam`/`optParam` wrappers (from `:= by tac` / `:= default` binders and fields)
everywhere in `e`, leaving just the underlying type so it can be re-elaborated. -/
def stripAutoParams (e : Expr) : Expr :=
  e.replace fun node =>
    if node.isAppOfArity ``autoParam 2 || node.isAppOfArity ``optParam 2 then
      some node.appFn!.appArg!
    else
      none

/-- Pretty-prints a *type*: strips auto/optional-parameter wrappers first. -/
def ppType (e : Expr) : MetaM String := ppFull (stripAutoParams e)

/-- Replaces every maximal proof subterm (one whose type is a `Prop`) with `sorry`, so a definition's
computational content is kept while the proofs it embeds are erased. -/
partial def sorryProofs (e : Expr) : MetaM Expr :=
  transform e (pre := fun node => do
    if node.isSort || node.isBVar || node.isMVar || node.isFVar then
      return .continue
    let ok ← (do let t ← inferType node; isProp t) <|> pure false
    if ok then
      return .done (← mkSorry (← inferType node) (synthetic := false))
    else
      return .continue)

/-- Renders a binder for `fvar` (a telescope variable) using its name, binder kind and type,
faithfully preserving the original binder kind. -/
def renderBinder (fvar : Expr) : MetaM String := do
  let decl ← fvar.fvarId!.getDecl
  let ty ← ppType decl.type
  let nm := decl.userName.toString
  match decl.binderInfo with
  | .default => return "(" ++ nm ++ " : " ++ ty ++ ")"
  | .implicit => return "{" ++ nm ++ " : " ++ ty ++ "}"
  | .strictImplicit => return "⦃" ++ nm ++ " : " ++ ty ++ "⦄"
  | .instImplicit => return "[" ++ ty ++ "]"

/-- Reconstructs a `structure`/`class` declaration. The constructor's type is a telescope of the
parameters followed by the fields, where each field binder references the previous fields *by their
own name* — so pretty-printing those binder types yields valid field declarations (`policy n`, not
`Algorithm.policy self n`). Subobject fields become the `extends` clause. -/
def renderStructure (name : Name) (ii : InductiveVal) : MetaM String := do
  let env ← getEnv
  let ctorName := (getStructureCtor env name).name
  let some ctorInfo := env.find? ctorName | return "-- (could not reconstruct " ++ name.toString ++ ")"
  -- Parameters come from the inductive's own type (correct explicitness: `(𝓐 : Type*)`), while the
  -- fields come from the constructor's type with the parameters instantiated, so each field's type
  -- refers to the parameters and earlier fields by name.
  forallBoundedTelescope ii.type ii.numParams fun params _ => do
    let paramStrs ← params.mapM renderBinder
    let fieldTele ← instantiateForall ctorInfo.type params
    forallTelescopeReducing fieldTele fun fields _ => do
      let mut exts : Array String := #[]
      let mut flds : Array String := #[]
      for fv in fields do
        let decl ← fv.fvarId!.getDecl
        let tyStr ← ppType decl.type
        if (isSubobjectField? env name decl.userName).isSome then
          exts := exts.push tyStr
        else
          flds := flds.push ("  " ++ decl.userName.toString ++ " : " ++ tyStr)
      let kw := if isClass env name then "class" else "structure"
      let paramClause := if paramStrs.isEmpty then "" else " " ++ " ".intercalate paramStrs.toList
      let extClause := if exts.isEmpty then "" else " extends " ++ ", ".intercalate exts.toList
      let head := kw ++ " " ++ name.toString ++ paramClause ++ extClause ++ " where"
      return head ++ "\n" ++ "\n".intercalate flds.toList

/-- Reconstructs an `inductive` declaration: parameters and each constructor's (fully qualified)
type. -/
def renderInductive (name : Name) (ii : InductiveVal) : MetaM String := do
  let env ← getEnv
  forallBoundedTelescope ii.type ii.numParams fun params _ => do
    let paramStrs ← params.mapM renderBinder
    let mut ctors : Array String := #[]
    for ctorName in ii.ctors do
      if let some (.ctorInfo ci) := env.find? ctorName then
        let ty ← instantiateForall ci.type params
        ctors := ctors.push ("  | " ++ ctorName.getString! ++ " : " ++ (← ppType ty))
    let paramClause := if paramStrs.isEmpty then "" else " " ++ " ".intercalate paramStrs.toList
    return "inductive " ++ name.toString ++ paramClause ++ " where\n" ++ "\n".intercalate ctors.toList

/-- Renders a single declaration as a self-contained, fully-qualified Lean command, or `none` if its
shape is unsupported. -/
def renderDecl (name : Name) : MetaM (Option String) := do
  let env ← getEnv
  let some info := env.find? name | return none
  match info with
  | .thmInfo ti => return some ("theorem " ++ name.toString ++ " : " ++ (← ppType ti.type) ++ " := sorry")
  | .axiomInfo ai => return some ("axiom " ++ name.toString ++ " : " ++ (← ppType ai.type))
  | .opaqueInfo oi => return some ("opaque " ++ name.toString ++ " : " ++ (← ppType oi.type) ++ " := sorry")
  | .defnInfo di =>
      let safety := match di.safety with
        | .unsafe => "unsafe " | .partial => "partial " | .safe => ""
      let nonComp := if isNoncomputable env name then "noncomputable " else ""
      let kw := nonComp ++ safety ++ (if isInstanceCore env name then "instance" else "def")
      let val ← ppFull (← sorryProofs di.value)
      return some (kw ++ " " ++ name.toString ++ " : " ++ (← ppType di.type) ++ " :=\n  " ++ val)
  | .inductInfo ii =>
      if (getStructureInfo? env name).isSome then
        return some (← renderStructure name ii)
      else
        return some (← renderInductive name ii)
  | _ => return none

/-- Renders every declaration in `decls` once, returning a map from name to its standalone source.
Runs in a single `MetaM` pass with the pretty-printer configured for fully-qualified, notation-free
output (see `mkDocstringBlock?` in `Collect` for the same `CoreM`-to-`IO` pattern). -/
def renderAllDecls (env : Environment) (decls : Array DeclInfo) : IO (Std.HashMap Name String) := do
  let options := (Options.empty.setBool `pp.fullNames true).setBool `pp.notation false
    |>.setBool `pp.fieldNotation false
    -- Insert the annotations (named/explicit args) needed for the output to re-elaborate to the same
    -- term, e.g. `Encodable.encode (α := α)` rather than a bare `Encodable.encode` with an
    -- undetermined implicit.
    |>.setBool `pp.analyze true
    -- Show proofs (our `sorry`s, after `sorryProofs`) instead of eliding them as `⋯`.
    |>.setBool `pp.proofs true
    -- One declaration per line: avoid wrapping that would break `structure … where` field parsing.
    |>.insert `format.width (.ofNat 100000)
  let coreCtx : Core.Context := { fileName := "<exposition>", fileMap := default, options }
  let act : MetaM (Std.HashMap Name String) := do
    let mut m : Std.HashMap Name String := {}
    for decl in decls do
      try
        if let some s ← renderDecl decl.name then
          m := m.insert decl.name s
      catch _ => pure ()
    return m
  (act.run' {}).toIO' coreCtx { env := env }

/-! ## Assembling a file -/

/-- Builds the full standalone Lean file for `target` from the pre-rendered declarations. -/
def extractStandalone (env : Environment) (rootPrefix : Name)
    (declByName : Std.HashMap Name DeclInfo) (rendered : Std.HashMap Name String)
    (target : DeclInfo) : String := Id.run do
  let emit := emitOrder declByName target
  let imports := importModules env rootPrefix declByName emit
  let importBlock := if imports.isEmpty then #["import Mathlib"] else imports.map (s!"import {·}")
  let header := #[
    "",
    s!"/- Standalone extraction for `{target.name}`.",
    "   Definitions are kept in full; all proofs are replaced by `sorry`.",
    "   Auto-generated by LeanExposition. -/",
    ""]
  let body := emit.filterMap (fun d => rendered.get? d.name)
  let parts := importBlock.toList ++ header.toList ++ (body.toList.intersperse "") ++ [""]
  return "\n".intercalate parts

/-- Writes a standalone `<anchorId>.lean` file for every declaration into `dir` (the file name
matches `anchorIdOf` so it can be linked from a declaration's page). Declarations are rendered once
up front and shared across all files. Returns the number of files written. -/
def writeAllExtractions (env : Environment) (rootPrefix : Name)
    (declByName : Std.HashMap Name DeclInfo) (decls : Array DeclInfo) (dir : System.FilePath) :
    IO Nat := do
  let rendered ← renderAllDecls env decls
  IO.FS.createDirAll dir
  for decl in decls do
    let content := extractStandalone env rootPrefix declByName rendered decl
    IO.FS.writeFile (dir / s!"{anchorIdOf decl.name}.lean") content
  return decls.size

end LeanExposition
