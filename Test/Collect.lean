module

public import Referee.Collect
-- The checks below are `#guard`s, which Lean elaborates into compile-time (`meta`)
-- definitions, so the declarations under test have to be imported at that level too.
meta import Referee.Collect

@[expose] public section

/-!
# Tests for `Referee.Collect`

This module audits the *pure* logic of `Collect.lean`:

* the small name/string helpers used to build hrefs and signatures;
* the dependency-graph passes as they apply to a collected `DeclInfo` array
  (`attachReverseDeps`, `attachTransitiveDeps`), i.e. the field plumbing and the `closureDeps` edge
  choice — the passes themselves live in `LeanDeps` and are checked in `Test/Deps.lean`, together
  with the rest of the dependency analysis;
* `attachSpecifiedBy`, which reverses the author's `@[specifies]` links, and `isDefinitionLike`,
  the classification every specification count is taken over (reading the annotations out of the
  environment needs a real project and is exercised end to end, not here);
* the decoding of a `semantic_hash export` record, whose encoding is an assumption about *another*
  tool's output and so is the thing here most able to break without anyone noticing;
* the JSON round-trip of the collected data.

Each check is a `#guard`, so any regression turns into a build error. Run with
`lake build Test`.

`collectDecls` needs a full `Environment` and is exercised separately/sparingly against a real
project; it is not unit-tested here because constructing a synthetic `Environment` is impractical.
-/

open Lean Std
open Referee

namespace Referee.Test

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

/-! ## Stripping the decorations before a declaration

`cleanDeclSnippet` has to leave the snippet starting at the declaration keyword, because everything
downstream reads that first word: the signature shown on the page, and the `lemma`/`instance`/
`alias` detection that decides both the label and whether a declaration lands on the Claims page.

The multi-line cases below are the ones that were wrong: a `@[…]` spanning two source lines had
only its first line dropped, so the statement was rendered with the tail of the attribute glued to
its front *and* `lemma` went undetected, promoting the lemma to a claim. -/

#guard cleanDeclSnippet "theorem foo : True := trivial" == "theorem foo : True := trivial"
#guard cleanDeclSnippet "@[simp] lemma foo : True := trivial" == "lemma foo : True := trivial"
#guard cleanDeclSnippet "/-- Doc. -/\nlemma foo : True := trivial" == "lemma foo : True := trivial"
-- An attribute on its own line, and several of them.
#guard cleanDeclSnippet "@[simp]\nlemma foo : True := trivial" == "lemma foo : True := trivial"
#guard cleanDeclSnippet "@[simp]\n@[norm_cast]\nlemma foo : True" == "lemma foo : True"
-- Docstring, then attribute, in the order Lean requires.
#guard cleanDeclSnippet "/-- Doc. -/\n@[simp]\nlemma foo : True" == "lemma foo : True"
-- An attribute spanning two lines, via a string gap and via a plain wrap.
#guard cleanDeclSnippet "@[specifies f \"a long \\\n  note\"]\nlemma foo : True" == "lemma foo : True"
#guard cleanDeclSnippet "@[specifies f,\n  simp]\nlemma foo : True" == "lemma foo : True"
-- A bracket inside the attribute's string argument must not close it early.
#guard cleanDeclSnippet "@[specifies f \"the a[i] case\"]\nlemma foo : True" == "lemma foo : True"
-- An escaped quote does not end the string, so the `]` after it is still inside the attribute.
#guard cleanDeclSnippet "@[specifies f \"say \\\"hi]\\\"\"]\nlemma foo : True" == "lemma foo : True"
-- The declaration may begin on the same line as the closing bracket.
#guard cleanDeclSnippet "@[specifies f,\n  simp] lemma foo : True" == "lemma foo : True"

/-! ### Splitting a snippet into signature and value

The separator is the first `:=` at bracket depth zero. Taking the first one outright truncated the
statement of every theorem containing a named argument — and handed the severed tail to the proof
section, so the same defect showed up twice on the page. -/

#guard splitAtAssignment "theorem foo : True := trivial" == some ("theorem foo : True ", " trivial")
#guard splitAtAssignment "axiom foo : True" == none

-- A named argument. This is the case found on `AlphaRAR.estimatorSqrtNVec_joint_tendsto_…`, whose
-- statement was cut at `Tendsto (β`.
#guard headBeforeAssignment "theorem foo : Tendsto (β := ℝ) f atTop := by simp"
  == "theorem foo : Tendsto (β := ℝ) f atTop"
#guard (splitAtAssignment "theorem foo : Tendsto (β := ℝ) f atTop := by simp").map (·.2)
  == some " by simp"

-- A structure instance, an anonymous constructor, and a binder default: same shape, all bracketed.
#guard headBeforeAssignment "theorem foo : P { x := 1 } := rfl" == "theorem foo : P { x := 1 }"
#guard headBeforeAssignment "theorem foo : P ⟨a := 1⟩ := rfl" == "theorem foo : P ⟨a := 1⟩"
#guard headBeforeAssignment "theorem foo (n : ℕ := 0) : P n := rfl" == "theorem foo (n : ℕ := 0) : P n"

-- Nested brackets: the depth has to come back to zero before a `:=` counts.
#guard headBeforeAssignment "theorem foo : P (f (g := ⟨x := 1⟩)) := rfl"
  == "theorem foo : P (f (g := ⟨x := 1⟩))"

-- A type ascription is a bare `:` and must not be mistaken for the separator.
#guard headBeforeAssignment "theorem foo : (x : ℕ) = x := rfl" == "theorem foo : (x : ℕ) = x"

/-! ### Reading a declaration's keyword, including attribute-generated ones

The keyword decides whether a result is labelled a lemma or a theorem, and therefore whether it
appears on the Claims page as something the library asserts for its own sake. Getting it wrong for
generated declarations put six of LML's eleven "claims" there: `@[to_dual min_le] lemma le_max …`
records, for the generated `min_le`, a range covering only the attribute line, so cleaning it leaves
nothing to read the keyword from. `to_additive` has the same shape. -/

private def dualSource : Array String := #[
  "/-- Doc. -/",
  "@[to_dual min_le]",
  "lemma le_max (x : ι) : f x ≤ max f := le_sup' _ (by simp)"
]

-- The original: its range covers the whole command, so nothing has to be looked up.
#guard (keywordSnippet ⟨"f.lean", "f.lean", 2, 3⟩ dualSource).startsWith "lemma "
-- The generated sibling: the range is the attribute line alone, and the keyword is on the next one.
#guard (keywordSnippet ⟨"f.lean", "f.lean", 2, 2⟩ dualSource).startsWith "lemma "
#guard isLemmaFromSource .theorem (some ⟨"f.lean", "f.lean", 2, 2⟩) dualSource

-- A multi-line attribute block, and a doc comment on the generated declaration itself.
private def multiAttr : Array String := #[
  "@[to_dual (attr := fun_prop)",
  "  measurable_argmin]",
  "lemma measurable_argmax [MeasurableSpace ι] :"
]
#guard (keywordSnippet ⟨"f.lean", "f.lean", 1, 2⟩ multiAttr).startsWith "lemma "

-- A generated declaration whose original is a genuine `theorem` stays a theorem: the keyword is
-- inherited, not overridden.
private def dualTheorem : Array String := #[
  "@[to_additive add_foo]",
  "theorem foo : P := by simp"
]
#guard !isLemmaFromSource .theorem (some ⟨"f.lean", "f.lean", 1, 1⟩) dualTheorem

-- `instance` is read the same way, since a generated instance would otherwise be labelled a theorem
-- and counted among the claims.
private def dualInstance : Array String := #[
  "@[to_dual existing]",
  "instance foo : P := ⟨bar⟩"
]
#guard isInstanceFromSource .theorem (some ⟨"f.lean", "f.lean", 1, 1⟩) dualInstance

-- The lookahead stops rather than running to the end of the file: an attribute that decorates
-- something which is not a declaration must not adopt a keyword from far below.
private def loneAttribute : Array String :=
  #["attribute [to_dual existing] MeasurableInf₂"]
#guard !isLemmaFromSource .theorem (some ⟨"f.lean", "f.lean", 1, 1⟩) loneAttribute

-- The fallback signature is introduced by the keyword the author wrote, so the code block cannot
-- say `theorem` under a card labelled "Lemma".
#guard displaySignatureFallback .theorem `min_le "P" (isLemma := true) == "lemma min_le : P"
#guard displaySignatureFallback .theorem `foo "P" == "theorem foo : P"
#guard displaySignatureFallback .definition `f "ℕ" (isLemma := true) == "def f : ℕ"

/-! ## Dependency-graph passes

These run on an already-collected `Array DeclInfo`, wrapping the graph passes of `LeanDeps`. What
is checked here is the `DeclInfo` side: which field each pass writes, and which edges it follows
(`closureDeps`: type-only for theorems). We build small synthetic graphs and check the derived
fields. `mkDecl` fills the structure with inert defaults so each test only specifies the fields
that matter (`name`, `deps`, `typeDeps`, `kind`).
-/

private def mkDecl (name : Name) (deps : Array Name := #[]) (typeDeps : Array Name := #[])
    (kind : DeclKind := .definition) (specifies : Array SpecLink := #[])
    (upstreamPackages : Array Name := #[])
    (characterizedBy : Array CharBundle := #[]) : DeclInfo := {
  upstreamPackages := upstreamPackages
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
  deps := deps
  typeDeps := typeDeps
  specifies := specifies
  characterizedBy := characterizedBy
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

/-! ### `attachSpecifiedBy` (`specifiedBy` = reverse of the author's `@[specifies]` links)

Unlike the passes above this one carries a payload — the author's comment — and deliberately does
*not* sort: a specification is a short curated list and reads in the order it was written. -/

private def specGraph : Array DeclInfo := #[
  mkDecl `thmB (kind := .theorem) (specifies := #[⟨`Def, "second"⟩]),
  mkDecl `thmA (kind := .theorem) (specifies := #[⟨`Def, ""⟩, ⟨`Other.Upstream, "off-project"⟩]),
  mkDecl `Def,
  mkDecl `Unspecified
]

-- Declaration order, not name order, and the comment travels with the link.
#guard field (attachSpecifiedBy specGraph) `Def (·.specifiedBy) ==
  some #[⟨`thmB, "second"⟩, ⟨`thmA, ""⟩]
-- A definition nobody annotated is the case the site has to be able to point at.
#guard field (attachSpecifiedBy specGraph) `Unspecified (·.specifiedBy) ==
  some (#[] : Array SpecLink)
-- A target outside the exposed set stays visible on the theorem and adds no node of its own.
#guard field (attachSpecifiedBy specGraph) `thmA (·.specifies) ==
  some #[⟨`Def, ""⟩, ⟨`Other.Upstream, "off-project"⟩]
#guard (attachSpecifiedBy specGraph).all (·.name != `Other.Upstream)
-- The pass only writes the reverse direction; the forward links are the collected input.
#guard field (attachSpecifiedBy specGraph) `thmA (·.specifiedBy) == some (#[] : Array SpecLink)

/-! ### `attachCharacterizes` (`characterizes` = reverse of `characterizedBy`)

The same shape as `attachSpecifiedBy`, over a claim with three parts rather than a link with two
ends. What it has to get right is the role: a reader landing on `unique` is told it is the
uniqueness half, and one landing on `IsDef` is told it is the property, and swapping the two would
misdescribe both. -/

private def charBundle : CharBundle := {
  property := `IsDef
  comment := "the defining equation"
  existence := #[`isDef_def]
  uniqueness := #[{ name := `IsDef.unique, relation := "a = b", relationHead := `Eq }]
}

private def charGraph : Array DeclInfo := #[
  mkDecl `Def (characterizedBy := #[charBundle]),
  mkDecl `IsDef,
  mkDecl `isDef_def (kind := .theorem),
  mkDecl `IsDef.unique (kind := .theorem),
  mkDecl `Unrelated
]

#guard field (attachCharacterizes charGraph) `IsDef (·.characterizes) ==
  some #[⟨`Def, `IsDef, "property"⟩]
#guard field (attachCharacterizes charGraph) `isDef_def (·.characterizes) ==
  some #[⟨`Def, `IsDef, "existence"⟩]
#guard field (attachCharacterizes charGraph) `IsDef.unique (·.characterizes) ==
  some #[⟨`Def, `IsDef, "uniqueness"⟩]
-- The definition itself carries the bundle, not a link back to it.
#guard field (attachCharacterizes charGraph) `Def (·.characterizes) ==
  some (#[] : Array CharPartLink)
#guard field (attachCharacterizes charGraph) `Unrelated (·.characterizes) ==
  some (#[] : Array CharPartLink)

-- `isComplete` is the specified/characterized distinction, and the whole reason an unfinished
-- bundle is kept rather than dropped: it renders as a gap, not as a characterization.
#guard charBundle.isComplete
#guard !({ charBundle with uniqueness := #[] } : CharBundle).isComplete
#guard !({ charBundle with existence := #[] } : CharBundle).isComplete

/-! ### `isDefinitionLike`

What a specification can be *about*, and so the denominator of every "N of M definitions have one"
the site reports. Worth pinning down: the exclusions are judgement calls, and silently gaining or
losing a kind here would move every count on the specification page. -/

#guard (mkDecl `D (kind := .definition)).isDefinitionLike
#guard (mkDecl `S (kind := .structure)).isDefinitionLike
#guard (mkDecl `C (kind := .typeclass)).isDefinitionLike
#guard (mkDecl `I (kind := .inductive)).isDefinitionLike
#guard (mkDecl `O (kind := .opaque)).isDefinitionLike
-- A theorem's meaning is its statement, an axiom is itself an assumption (which the trust page
-- reports), and instances are plumbing numerous enough to bury the definitions that matter.
#guard !(mkDecl `T (kind := .theorem)).isDefinitionLike
#guard !(mkDecl `A (kind := .axiom)).isDefinitionLike
#guard !(mkDecl `Inst (kind := .instance)).isDefinitionLike
-- Written with the `instance` keyword, whatever kind it elaborated to.
#guard !({ mkDecl `Inst2 (kind := .definition) with isInstanceDecl := true }).isDefinitionLike

/-! ## Upstream packages and trust

The one part of the audit that reaches outside the project. Three pieces of pure logic, all of which
would fail *silently* if wrong — a trust page that under-reports reads exactly like one with nothing
to report — so each is pinned here.

The fixture is `AlphaRAR`'s real shape, reduced: the project requires `LML`, which requires
`mathlib` (which requires `batteries`) and `verso`. `verso` is the interesting one: `LML` declares it
but none of its code is loaded, which is what `loadedPackages` exists to exclude. -/

private def pkgs : Array PackageInfo := #[
  { name := `Proj, deps := #[`LML], roots := #[`Proj], isProject := true },
  { name := `LML, deps := #[`mathlib, `verso], roots := #[`LeanMachineLearning] },
  { name := `mathlib, deps := #[`batteries], roots := #[`Mathlib] },
  { name := `batteries, deps := #[], roots := #[`Batteries] },
  { name := `verso, deps := #[], roots := #[`Verso] },
  { name := `Lean, deps := #[], roots := #[`Init, `Std, `Lean, `Lake], isToolchain := true }
]

/-! ### `trustClosure` -/

-- Trusting a package vouches for what it is built from: Mathlib's own theorems rest on Batteries.
#guard (trustClosure pkgs #[`mathlib]).contains `batteries
#guard (trustClosure pkgs #[`mathlib]).contains `mathlib
-- But not for what is built *on* it, which is the whole point of the flag.
#guard !(trustClosure pkgs #[`mathlib]).contains `LML
#guard !(trustClosure pkgs #[`mathlib]).contains `verso
-- The toolchain is trusted with no flag at all: it is the kernel that checked everything else.
#guard (trustClosure pkgs #[]).contains `Lean
#guard (trustClosure pkgs #[]).size == 1
-- Trusting LML reaches everything it declares, transitively.
#guard (trustClosure pkgs #[`LML]).contains `batteries
#guard (trustClosure pkgs #[`LML]).contains `verso
-- A cycle in the graph must not hang the closure.
#guard (trustClosure #[{ name := `a, deps := #[`b] }, { name := `b, deps := #[`a] }] #[`a]).size == 2

-- A typo must be reported, not silently vouch for nothing.
#guard unknownTrustedPackages pkgs #[`mathlbi] == #[`mathlbi]
#guard unknownTrustedPackages pkgs #[`mathlib] == (#[] : Array Name)

/-! ### `modulePackageOf` -/

#guard modulePackageOf pkgs `Mathlib.Order.Basic == some `mathlib
#guard modulePackageOf pkgs `LeanMachineLearning.Bandits == some `LML
#guard modulePackageOf pkgs `Init.Prelude == some `Lean
#guard modulePackageOf pkgs `Lake.Build == some `Lean
-- Component-wise, not string prefix: `MathlibExtra` is not `Mathlib`.
#guard modulePackageOf pkgs `MathlibExtra.Foo == none
#guard modulePackageOf pkgs `Something.Else == none
-- Longest matching root wins, so a package nested under another's root claims its own modules.
#guard modulePackageOf #[{ name := `outer, roots := #[`Foo] }, { name := `inner, roots := #[`Foo.Bar] }]
  `Foo.Bar.Baz == some `inner

/-! ### `closureDepsOf` and `meaningDepsOf`

The two rules for "which edges does this follow". `closureDepsOf` is the wider one and has exactly
one consumer, `transDeps`, which `Referee.Extract` seeds standalone files from and which therefore
must stay closed over proofs. `meaningDepsOf` is what everything the reader is shown follows —
the graph, the trust analysis, the audit closure, the revision diff.

They differ in one case, the definition: `closureDepsOf` takes the whole body, `meaningDepsOf` takes
the body's data and drops the proofs bundled into it. Worth pinning directly rather than only through
their callers. -/

-- A theorem contributes its statement under both rules; its proof was checked by the kernel.
#guard closureDepsOf .theorem false #[`body] #[`stated] == #[`stated]
#guard meaningDepsOf .theorem false #[`body] #[`stated] #[`data] == #[`stated]
-- An `alias` is a theorem whose body is kept verbatim, so both follow the body.
#guard closureDepsOf .theorem true #[`body] #[`stated] == #[`body]
#guard meaningDepsOf .theorem true #[`body] #[`stated] #[`data] == #[`body]
-- The case they differ in: a definition's whole body for the closure, its data alone for meaning.
#guard closureDepsOf .definition false #[`body] #[`stated] == #[`body]
#guard meaningDepsOf .definition false #[`body] #[`stated] #[`data] == #[`data]
#guard closureDepsOf .structure false #[`body] #[`stated] == #[`body]
#guard meaningDepsOf .structure false #[`body] #[`stated] #[`data] == #[`data]
-- An empty `dataDeps` means the walk was never run, so meaning falls back to the whole body rather
-- than reporting that the definition rests on nothing.
#guard meaningDepsOf .definition false #[`body] #[`stated] #[] == #[`body]
-- ...but a declaration that genuinely rests on nothing still reports nothing.
#guard meaningDepsOf .definition false #[] #[] #[] == (#[] : Array Name)

/-! ### `attachUpstreamPackages`

Propagation follows `meaningDeps`, and the reason is the whole point of the measure: an upstream
*proof* is not a trust dependency, because the kernel rechecked it and anything left unproved in it
arrives as a `sorry` or an extra axiom, which the trust page counts separately. What a reader must
take on faith is an upstream *definition* their statement is about.

So the two cases below have to come out differently, and getting them the same way round — which an
earlier version did, following `deps` — inflates the report with proof-only dependencies that need no
audit at all. -/

private def pkgGraph : Array DeclInfo := #[
  -- A theorem whose statement touches nothing upstream and whose *proof* reaches Mathlib. Not a
  -- trust dependency: the proof is checked.
  mkDecl `provedThm (deps := #[`helper]) (typeDeps := #[]) (kind := .theorem),
  -- A theorem whose *statement* is about the same upstream definition. This one is.
  mkDecl `statedThm (deps := #[`helper]) (typeDeps := #[`helper]) (kind := .theorem),
  -- A definition's body is part of its meaning, so body edges do count for one.
  mkDecl `defn (deps := #[`helper]) (typeDeps := #[]) (kind := .definition),
  mkDecl `helper (upstreamPackages := #[`mathlib]),
  mkDecl `isolated
]

#guard field (attachUpstreamPackages pkgGraph) `provedThm (·.upstreamPackages) ==
  some (#[] : Array Name)
#guard field (attachUpstreamPackages pkgGraph) `statedThm (·.upstreamPackages) == some #[`mathlib]
#guard field (attachUpstreamPackages pkgGraph) `defn (·.upstreamPackages) == some #[`mathlib]
#guard field (attachUpstreamPackages pkgGraph) `helper (·.upstreamPackages) == some #[`mathlib]
#guard field (attachUpstreamPackages pkgGraph) `isolated (·.upstreamPackages) ==
  some (#[] : Array Name)

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
  isLemma := true
  specifies := #[{ name := `Foo.mk, comment := "characterizes `mk` on the empty case" }]
  specifiedBy := #[{ name := `Foo.qux }]
  upstreamPackages := #[`mathlib]
  deps := #[`Nat.add]
  typeDeps := #[`Nat.add]
  usedBy := #[`Foo.baz]
  transDeps := #[`Nat.add]
  docstringBlock? := some (.para #[.code "bar"])
}

/-! ## Semantic hash records

The one place this tool depends on the *encoding* of another's output. Lean serializes `UInt64` as
a decimal string, since JavaScript cannot hold 64 bits in a number, so that is what
`semantic_hash export` writes today — but reading it is an assumption, and an assumption that fails
silently costs the whole comparison upgrade with no error anywhere. Hence the numeric branch, and
hence these. -/

#guard hex16 0 == "0000000000000000"
#guard hex16 255 == "00000000000000ff"
#guard hex16 0xdeadbeefcafe1234 == "deadbeefcafe1234"

-- What the tool actually writes.
#guard parseHashField? (Json.str "255") == some "00000000000000ff"
-- And the same value written as a JSON number, so a change of convention upstream degrades to
-- nothing rather than to a silently empty hash table.
#guard parseHashField? (Json.num 255) == some "00000000000000ff"
-- Both encodings of one value canonicalize to the same key, which is what makes files written
-- under either convention comparable.
#guard parseHashField? (Json.str "255") == parseHashField? (Json.num 255)
#guard parseHashField? (Json.str "not a number") == none
#guard parseHashField? Json.null == none

#guard roundTrips sampleDeclForJson
#guard roundTrips ({ title := "Section", body := "Some *markdown* body." } : MarkdownSection)
#guard roundTrips ({
  rootPrefix := `Foo
  decls := #[sampleDeclForJson]
  moduleOrder := #[(`Foo, 0), (`Foo.Bar, 1)]
  moduleDocs := #[(`Foo, #[.para #[.text "module doc"]])]
  readmeText := some "# Title\n\nBody"
  packages := pkgs
  loadedPackages := #[`Proj, `LML, `mathlib, `batteries, `Lean]
} : CollectedData)

end Referee.Test
