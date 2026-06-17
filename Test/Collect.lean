import LMLExposition.Collect

/-!
# Tests for `LMLExposition.Collect`

This module audits the *pure* logic of `Collect.lean`, with an emphasis on the functions that
build and propagate the dependency lists of a declaration:

* name classification feeding `shouldExpose` / dependency expansion
  (`isPrefixWithDigitSuffix`, `isAuxComponent`, `isInternalName`, `hasPrefixName`);
* the dependency-graph passes that run on the collected `DeclInfo` array
  (`topologicalClosure`, `attachReverseDeps`, `attachTransitiveDeps`, `attachDependsOnSorry`);
* the small name/string helpers used to build hrefs and signatures.

Each check is a `#guard`, so any regression turns into a build error. Run with
`lake build Test`.

The functions that need a full `Environment` (`usedConstantsOf`, `expandThroughInternals`,
`collectDecls`) are exercised separately/sparingly against a real project; they are not unit-tested
here because constructing a synthetic `Environment` is impractical.
-/

open Lean Std
open LMLExposition

namespace LMLExposition.Test

/-! ## Name-classification helpers -/

-- `isPrefixWithDigitSuffix pfx s`: `pfx` then a non-empty run of digits.
#guard isPrefixWithDigitSuffix "match_" "match_1"
#guard isPrefixWithDigitSuffix "match_" "match_12"
#guard !isPrefixWithDigitSuffix "match_" "match_"          -- empty suffix
#guard !isPrefixWithDigitSuffix "match_" "match_x"         -- non-digit suffix
#guard !isPrefixWithDigitSuffix "match_" "match_1a"        -- mixed suffix
#guard !isPrefixWithDigitSuffix "match_" "prefix_1"        -- wrong prefix
#guard isPrefixWithDigitSuffix "eq_" "eq_2"
#guard isPrefixWithDigitSuffix "hcongr_" "hcongr_11"

-- `isAuxComponent`: a single name component that the compiler auto-generates.
#guard isAuxComponent "_hyg"           -- underscore-led
#guard isAuxComponent "_proof_3"
#guard isAuxComponent "match_1"
#guard isAuxComponent "eq_4"
#guard isAuxComponent "eq_def"
#guard isAuxComponent "eq_unfold"
#guard isAuxComponent "hcongr_2"
#guard !isAuxComponent "eq"            -- bare `eq` is a legitimate component
#guard !isAuxComponent "matchup"       -- not the `match_<n>` pattern
#guard !isAuxComponent "foo"

-- `isInternalName`: true if *any* component is auxiliary or a known compiler suffix.
#guard isInternalName `Foo.match_1
#guard isInternalName `Foo._proof_2
#guard isInternalName `Foo.bar._hyg        -- internal in a non-leaf position
#guard isInternalName `List.rec
#guard isInternalName `Foo.casesOn
#guard isInternalName `Foo.injEq
-- `mk` is *not* flagged syntactically: the real constructor is excluded via the environment
-- (`ctorInfo`) in `shouldExpose`, while a user `def Foo.mk` must remain exposed.
#guard !isInternalName `Foo.mk
#guard !isInternalName `Nat.add
#guard !isInternalName `Foo.bar
#guard !isInternalName `Foo.barRec        -- `rec` only matches as a whole component

-- `hasPrefixName n p`: `p` is `n` itself or one of its dotted ancestors (component-wise,
-- NOT a string prefix).
#guard hasPrefixName `LML `LML
#guard hasPrefixName `LML.Foo.Bar `LML
#guard hasPrefixName `LML.Foo.Bar `LML.Foo
#guard !hasPrefixName `LMLExtra.Foo `LML   -- must not match on a string prefix
#guard !hasPrefixName `LML `LML.Foo        -- a descendant is not a prefix
#guard !hasPrefixName `Other.LML `LML      -- prefix must be anchored at the root

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

-- `coercionSourceType?`: the type coerced *from* in a coercion-class application, seen through binders.
#guard coercionSourceType? (mkApp2 (mkConst ``CoeFun) (mkConst ``Nat) (mkConst ``Nat)) == some `Nat
#guard coercionSourceType?
  (.forallE `x (mkConst ``Nat) (mkApp2 (mkConst ``CoeOut) (mkConst ``Int) (mkConst ``Int)) .default)
  == some `Int
#guard coercionSourceType? (mkConst ``Nat) == none   -- not a coercion-class application

-- `evalNameExpr?`: reconstruct the `Name` an `Expr` builds via `Name.anonymous`/`mkStr*`/`str`.
#guard evalNameExpr? (mkConst ``Lean.Name.anonymous) == some Name.anonymous
#guard evalNameExpr? (mkApp2 (mkConst ``Lean.Name.mkStr2) (mkStrLit "Foo") (mkStrLit "bar"))
  == some `Foo.bar
#guard evalNameExpr? (mkConst ``Nat.add) == none   -- not a name-building application
-- `collectEmbeddedNames` finds such names anywhere in the expression tree.
#guard (collectEmbeddedNames
  (mkApp (mkConst ``id) (mkApp2 (mkConst ``Lean.Name.mkStr2) (mkStrLit "A") (mkStrLit "b")))).contains
  `A.b

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

These run on an already-collected `Array DeclInfo`. We build small synthetic graphs and check the
derived fields. `mkDecl` fills the structure with inert defaults so each test only specifies the
fields that matter (`name`, `deps`, `typeDeps`, `kind`, `hasSorry`).
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

/-! ### `topologicalClosure` (depth-first post-order: every dependency before its users) -/

private def diamond : HashMap Name (Array Name) :=
  .ofList [(`A, #[`B, `C]), (`B, #[`D]), (`C, #[`D]), (`D, #[`E]), (`E, #[])]

-- Dependencies come out before the declarations that use them: `E` (deepest) first, the start
-- node `A` last. Each node appears exactly once.
#guard topologicalClosure diamond #[`A] == #[`E, `D, `B, `C, `A]
#guard topologicalClosure diamond #[`B, `C] == #[`E, `D, `B, `C]
#guard topologicalClosure diamond #[`E] == #[`E]
#guard topologicalClosure diamond #[] == (#[] : Array Name)

-- A cycle must terminate and visit each node exactly once.
private def cyclic : HashMap Name (Array Name) :=
  .ofList [(`A, #[`B]), (`B, #[`A])]
#guard topologicalClosure cyclic #[`A] == #[`B, `A]

-- Unknown nodes are treated as leaves (no entry ⇒ no further deps).
#guard topologicalClosure diamond #[`Z] == #[`Z]

-- The defining property: for the full ordering, every node precedes all nodes that depend on it.
-- Here `lib → util → core`, with an extra `app → lib`, so the order must be core, util, lib, app.
private def layered : HashMap Name (Array Name) :=
  .ofList [(`app, #[`lib]), (`lib, #[`util]), (`util, #[`core]), (`core, #[])]
#guard topologicalClosure layered #[`app] == #[`core, `util, `lib, `app]

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

end LMLExposition.Test
