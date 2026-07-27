import LMLExposition.Collect

/-!
# Tests for `LMLExposition.Collect`

This module audits the *pure* logic of `Collect.lean`:

* the small name/string helpers used to build hrefs and signatures;
* the dependency-graph passes as they apply to a collected `DeclInfo` array
  (`attachReverseDeps`, `attachTransitiveDeps`, `attachDependsOnSorry`), i.e. the field plumbing
  and the `graphDeps` edge choice — the passes themselves live in `LeanDeps` and are checked in
  `Test/Deps.lean`, together with the rest of the dependency analysis;
* the JSON round-trip of the collected data.

Each check is a `#guard`, so any regression turns into a build error. Run with
`lake build Test`.

`collectDecls` needs a full `Environment` and is exercised separately/sparingly against a real
project; it is not unit-tested here because constructing a synthetic `Environment` is impractical.
-/

open Lean Std
open LMLExposition

namespace LMLExposition.Test

/-! ## Name / string helpers used for hrefs and signatures -/

#guard nameComponents `Foo.bar.baz == ["Foo", "bar", "baz"]
#guard nameComponents Name.anonymous == ([] : List String)

#guard moduleTailComponents `LML `LML.Foo.Bar == ["Foo", "Bar"]
#guard moduleTailComponents `LML `LML == ([] : List String)

#guard groupKeyOfModule `LML `LML.Foo.Bar == "Foo"
#guard modulePathOf `LML `LML.Foo.Bar == "Foo.Bar"

#guard anchorIdOf `Foo.bar.baz == "Foo___bar___baz"
#guard anchorIdOf `Foo == "Foo"
-- Characters forbidden in filenames on some operating systems (Windows: `< > : " / \ | ? *`) are
-- replaced by fullwidth lookalikes, so notation declarations like `«term𝓛[_|_;_]»` yield portable
-- filenames. The component is `«…»`-escaped by `Name.toString`; we check the `|` is gone and the
-- fullwidth `｜` is present, without pinning the exact escaping.
#guard !(anchorIdOf (.str (.str .anonymous "N") "a|b")).any (· == '|')
#guard (anchorIdOf (.str (.str .anonymous "N") "a|b")).any (· == '｜')
#guard !(anchorIdOf (.str (.str .anonymous "N") "a?*b")).any (fun c => c == '?' || c == '*')

-- `percentEncode`: RFC 3986 unreserved bytes pass through; everything else becomes `%XX` (uppercase,
-- UTF-8). Used to make the extracted filename safe inside the editor `#url=` link.
#guard percentEncode "abc" == "abc"
#guard percentEncode "-_.~" == "-_.~"             -- unreserved set is preserved
#guard percentEncode "a b" == "a%20b"
#guard percentEncode "a/b?c" == "a%2Fb%3Fc"
#guard percentEncode "é" == "%C3%A9"              -- multi-byte UTF-8

-- `leanEditorUrl`: a live.lean-lang.org `#url=` link to the extracted file under the deploy base.
#guard leanEditorUrl "https://x.io/LML" `Foo.bar
  == "https://live.lean-lang.org/#url=https://x.io/LML/extracted/Foo___bar.lean"
#guard leanEditorUrl "https://x.io/LML/" `Foo.bar   -- trailing slash on the base is not doubled
  == "https://live.lean-lang.org/#url=https://x.io/LML/extracted/Foo___bar.lean"

#guard slugify "Foo Bar" == "foo-bar"
#guard slugify "Hello, World" == "hello-world"
#guard slugify "  leading" == "leading"   -- leading separators are dropped
#guard slugify "!!!" == "item"            -- nothing alphanumeric → fallback
-- Leading, consecutive AND trailing separators are all collapsed/stripped.
#guard slugify "Hello, World!" == "hello-world"
#guard slugify "trailing!" == "trailing"
#guard slugify "a -- b ." == "a-b"

#guard underscoreSplits "a_b_c" == [("a", "b_c"), ("a_b", "c")]
#guard underscoreSplits "_ab" == ([] : List (String × String))   -- leading underscore ignored
#guard underscoreSplits "ab_" == ([] : List (String × String))   -- trailing underscore ignored
#guard underscoreSplits "abc" == ([] : List (String × String))

-- `splitTopLevelColon?`: split on the first `:` that is not inside (), {}, [] or ⦃⦄.
#guard splitTopLevelColon? "x : Nat" == some ("x", "Nat")
#guard splitTopLevelColon? "(a : b) : c" == some ("(a : b)", "c")
#guard splitTopLevelColon? "{a : b} → c" == none            -- the only colon is bracketed
#guard splitTopLevelColon? "no colon here" == none

/-! ## Dependency-graph passes

These run on an already-collected `Array DeclInfo`, wrapping the graph passes of `LeanDeps`. What
is checked here is the `DeclInfo` side: which field each pass writes, and which edges it follows
(`graphDeps`: type-only for theorems). We build small synthetic graphs and check the derived
fields. `mkDecl` fills the structure with inert defaults so each test only specifies the fields
that matter (`name`, `deps`, `typeDeps`, `kind`, `hasSorry`).
-/

private def mkDecl (name : Name) (deps : Array Name := #[]) (typeDeps : Array Name := #[])
    (kind : DeclKind := .definition) (hasSorry : Bool := false) : DeclInfo := {
  name := name
  moduleName := `Test.Mod
  modulePath := "Mod"
  groupKey := "Mod"
  kind := kind
  displaySignature := ""
  expandedSignature := ""
  docBlocks := #[]
  proofText? := none
  source? := none
  hasSorry := hasSorry
  deps := deps
  typeDeps := typeDeps
}

/-- Look up one declaration's field after running a pass, for compact assertions. -/
private def field {α : Type} (decls : Array DeclInfo) (name : Name) (f : DeclInfo → α) : Option α :=
  (decls.find? (·.name == name)).map f

/-! ### `attachReverseDeps` (`usedBy` = reverse of `deps`, restricted to exposed decls, sorted) -/

private def revGraph : Array DeclInfo := #[
  mkDecl `A (deps := #[`B, `C]),
  mkDecl `B (deps := #[`C]),
  mkDecl `C (deps := #[]),
  -- `D` depends on `C` and on `External`, which is not an exposed declaration.
  mkDecl `D (deps := #[`C, `External])
]

#guard field (attachReverseDeps revGraph) `C (·.usedBy) == some #[`A, `B, `D]
#guard field (attachReverseDeps revGraph) `B (·.usedBy) == some #[`A]
#guard field (attachReverseDeps revGraph) `A (·.usedBy) == some (#[] : Array Name)
-- `External` is not an exposed decl, so nothing records it and no spurious node appears.
#guard (attachReverseDeps revGraph).all (·.name != `External)

/-! ### `attachTransitiveDeps`

`transDeps` follows `typeDeps` for theorems and `deps` for everything else, *per visited node*,
is topologically ordered (every dependency before its users), and never contains the declaration
itself.
-/

-- Plain chain of definitions: full transitive closure of `deps`, leaf (`C`) first.
private def chain : Array DeclInfo := #[
  mkDecl `A (deps := #[`B]),
  mkDecl `B (deps := #[`C]),
  mkDecl `C (deps := #[])
]
#guard field (attachTransitiveDeps chain) `A (·.transDeps) == some #[`C, `B]

-- A theorem expands only its `typeDeps`, dropping body-only dependencies from the closure.
-- Here theorem `T` has `B` in its statement and `Hidden` only in its proof body.
private def thmGraph : Array DeclInfo := #[
  mkDecl `T (deps := #[`B, `Hidden]) (typeDeps := #[`B]) (kind := .theorem),
  mkDecl `B (deps := #[`C]) (typeDeps := #[`C]),
  mkDecl `C,
  mkDecl `Hidden (deps := #[`Leak])
]
-- `Hidden` (and therefore `Leak`) must NOT be part of the theorem's transitive deps; `C` precedes `B`.
#guard field (attachTransitiveDeps thmGraph) `T (·.transDeps) == some #[`C, `B]

-- When a *definition* depends on a theorem, traversal into the theorem switches to the theorem's
-- `typeDeps`, so the theorem's proof-body deps stay out of the definition's closure too.
private def defUsesThm : Array DeclInfo := #[
  mkDecl `D (deps := #[`T]) (typeDeps := #[`T]),
  mkDecl `T (deps := #[`B, `Hidden]) (typeDeps := #[`B]) (kind := .theorem),
  mkDecl `B,
  mkDecl `Hidden
]
-- `B` (the theorem's type dep) precedes `T`.
#guard field (attachTransitiveDeps defUsesThm) `D (·.transDeps) == some #[`B, `T]

-- Self-reference (e.g. mutual/recursive) is filtered out of `transDeps`.
private def mutualGraph : Array DeclInfo := #[
  mkDecl `A (deps := #[`B]),
  mkDecl `B (deps := #[`A])
]
#guard field (attachTransitiveDeps mutualGraph) `A (·.transDeps) == some #[`B]
#guard field (attachTransitiveDeps mutualGraph) `B (·.transDeps) == some #[`A]

/-! ### `attachDependsOnSorry` (transitive closure of "uses a `sorry`", over `deps`) -/

-- `A → B → C`, where `C` has a `sorry`; the flag must propagate up the whole chain, and a decl
-- with its own `sorry` is itself flagged.
private def sorryChain : Array DeclInfo := #[
  mkDecl `A (deps := #[`B]),
  mkDecl `B (deps := #[`C]),
  mkDecl `C (hasSorry := true)
]
#guard field (attachDependsOnSorry sorryChain) `A (·.dependsOnSorry) == some true
#guard field (attachDependsOnSorry sorryChain) `B (·.dependsOnSorry) == some true
#guard field (attachDependsOnSorry sorryChain) `C (·.dependsOnSorry) == some true

-- A declaration on a sorry-free branch stays clean.
private def sorryBranch : Array DeclInfo := #[
  mkDecl `Root (deps := #[`Tainted, `Clean]),
  mkDecl `Tainted (deps := #[`Bad]),
  mkDecl `Bad (hasSorry := true),
  mkDecl `Clean (deps := #[`Leaf]),
  mkDecl `Leaf
]
#guard field (attachDependsOnSorry sorryBranch) `Root (·.dependsOnSorry) == some true
#guard field (attachDependsOnSorry sorryBranch) `Tainted (·.dependsOnSorry) == some true
#guard field (attachDependsOnSorry sorryBranch) `Clean (·.dependsOnSorry) == some false
#guard field (attachDependsOnSorry sorryBranch) `Leaf (·.dependsOnSorry) == some false

-- `attachDependsOnSorry` only propagates across *exposed* declarations. A sorry hidden behind a
-- non-exposed compiler helper is instead caught upstream, when `collectDecls` sets `hasSorry` via
-- `usesSorryThroughInternals` (which needs an `Environment`, so it is exercised end-to-end, not
-- here). For this isolated pass, an unexposed dep that is not itself marked stays clean.
private def sorryViaExternal : Array DeclInfo := #[
  mkDecl `A (deps := #[`NotExposed])
]
#guard field (attachDependsOnSorry sorryViaExternal) `A (·.dependsOnSorry) == some false

/-! ## JSON round-trip for collected data

`DeclInfo`/`ModuleInfo`/`GroupInfo`/`MarkdownSection`/`CollectedData` derive `ToJson`/`FromJson`
so `collect` can persist them and `extract`/`build-site` can read them back without
re-importing the target project. The main risk is the `Block Manual` fields (Verso's
docstring/markdown AST, populated via `docBlocks`/`docstringBlock?`): these checks exercise
that round-trip, plus the `Array (Name × Nat)`/`Array (Name × Array (Block Manual))` flattened
maps `CollectedData` uses in place of `Std.HashMap`. Compared via `Json.compress` rather than
`BEq DeclInfo` (no such instance exists, and isn't needed for anything else). -/

private def roundTrips {α : Type} [ToJson α] [FromJson α] (a : α) : Bool :=
  match FromJson.fromJson? (ToJson.toJson a) with
  | .ok (b : α) => (ToJson.toJson b).compress == (ToJson.toJson a).compress
  | .error _ => false

private def sampleDeclForJson : DeclInfo := {
  name := `Foo.bar
  moduleName := `Foo
  modulePath := "Foo.lean"
  groupKey := "Foo"
  kind := .theorem
  displaySignature := "theorem bar : True"
  expandedSignature := "theorem bar : True"
  docBlocks := #[.para #[.text "docs"]]
  proofText? := some "trivial"
  source? := some { relPath := "Foo.lean", absPath := "/tmp/Foo.lean", line := 1, endLine := 2 }
  hasSorry := false
  isLemma := true
  deps := #[`Nat.add]
  typeDeps := #[`Nat.add]
  usedBy := #[`Foo.baz]
  transDeps := #[`Nat.add]
  docstringBlock? := some (.para #[.code "bar"])
}

#guard roundTrips sampleDeclForJson
#guard roundTrips ({ title := "Section", body := "Some *markdown* body." } : MarkdownSection)
#guard roundTrips ({
  rootPrefix := `Foo
  decls := #[sampleDeclForJson]
  moduleOrder := #[(`Foo, 0), (`Foo.Bar, 1)]
  moduleDocs := #[(`Foo, #[.para #[.text "module doc"]])]
  readmeText := some "# Title\n\nBody"
} : CollectedData)

end LMLExposition.Test
