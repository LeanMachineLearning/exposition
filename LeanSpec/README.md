# LeanSpec

Two attributes for recording what a formalization's *definitions* mean.

`@[specifies]` records which theorems are part of the **specification of a definition** — the
properties their author offers as evidence that the definition is the intended one.
`@[characterization]` records the stronger claim that a property pins the definition down
**uniquely**, up to a stated relation, and checks that the theorems supplied really say so.

Depends on Lean core and nothing else. It lives in the
[`exposition`](https://github.com/LeanMachineLearning/exposition) repository but is a separate Lake
package precisely so that annotating a project does not drag in Referee's own
dependencies.

## Why

A proof can be checked by the kernel. A *definition* cannot: nothing verifies that `entropy` means
entropy. What settles that question is a handful of theorems — that it agrees with the textbook
formula, that it is non-negative, that it reduces to the classical notion in the classical case —
and those theorems usually already exist. What is missing is any record of *which ones they are*.
Nothing in the environment distinguishes a characterizing property of a definition from a lemma
used once on the way to something else.

`@[specifies]` is that record, written where it cannot go stale: at the theorem, in a form the
compiler checks.

## Use

Add the dependency:

```toml
# lakefile.toml
[[require]]
name = "LeanSpec"
git = "https://github.com/LeanMachineLearning/exposition"
rev = "main"
subDir = "LeanSpec"
```

```lean
-- lakefile.lean
require LeanSpec from git
  "https://github.com/LeanMachineLearning/exposition" @ "main" / "LeanSpec"
```

Then annotate:

```lean
import LeanSpec

def entropy (p : Distribution α) : ℝ := …

@[specifies entropy "agrees with the textbook formula on finite supports"]
theorem entropy_eq_sum (p : Distribution α) (h : p.support.Finite) :
    entropy p = -∑ x ∈ h.toFinset, p x * Real.log (p x) := …

@[specifies entropy]
theorem entropy_nonneg (p : Distribution α) : 0 ≤ entropy p := …
```

Both arguments are optional:

- `@[specifies]` alone infers the target from the theorem's own name, taking the innermost
  enclosing namespace that names a definition. So `@[specifies] theorem entropy.nonneg`, or the
  same theorem written inside `namespace entropy`, both mean `@[specifies entropy]`.
- The comment is free text. It should say what the property *buys* the reader, which the statement
  alone does not.

Apply it more than once for a theorem that specifies more than one definition:
`@[specifies foo, specifies bar "relates the two"]`.

### What `@[specifies]` checks

The attribute is not a comment. At elaboration time it rejects:

- a target that does not resolve (so a typo, or a renamed definition, is a build error);
- a target that is a theorem or a proof rather than a definition;
- an annotated declaration that is not a proposition;
- the same theorem being registered for the same definition twice;
- `local` or `scoped` application, which would not be recorded in the `.olean`.

It also warns when the annotated theorem's statement never mentions its target — almost always a
copy-pasted annotation. Almost, because the target can be reached through an abbreviation or hidden
inside a structure projection, so it is a warning and not an error, it is skipped for a theorem
living in the target's own namespace, and it can be turned off entirely:

```lean
set_option specifies.checkTargetMentioned false
```

## Characterizations

`@[specifies]` records a claim, and nothing checks it beyond the target resolving. A
*characterization* is the stronger thing, and it is checkable. It has three parts:

```lean
@[characterization property entropy "the Shannon axioms"]
def IsEntropy (p : Distribution α) (h : ℝ) : Prop := …

@[characterization existence]
theorem isEntropy_entropy (p : Distribution α) : IsEntropy p (entropy p) := …

@[characterization uniqueness]
theorem IsEntropy.unique (h₁ : IsEntropy p x) (h₂ : IsEntropy p y) : x = y := …
```

Together those say: `entropy p` is *the* real number with property `IsEntropy p`, up to equality.
The relation is read off the uniqueness theorem's conclusion rather than assumed, because plenty
of objects are only determined up to a.e. equality (`f =ᵐ[μ] g`) or up to isomorphism.

The two theorems name the **predicate**, not the definition, and by default read it off their own
statements — the head of the conclusion for existence, the head of a hypothesis for uniqueness.
Name it explicitly (`@[characterization uniqueness IsEntropy]`) when the guess is wrong. The
predicate is the hub because one definition can have several characterizations, and hanging every
part off the definition would let a tool assemble the pieces of one into another.

Two shapes of uniqueness theorem are accepted: `P x → P y → R x y`, and the `P x → R x definition`
form Mathlib usually writes (`condExp_unique`). With the existence theorem in hand the second is
just as good, and needs no symmetry of `R` to get there.

### What is checked

The shapes, by `isDefEq` rather than by matching syntax — so a theorem stated in unfolded form
still counts, and the price is that the predicate has to be something the elaborator can see
through rather than `opaque`. A tool reading a complete bundle back out can therefore report
"characterized" as a *checked* fact, which is the whole difference from `@[specifies]`. Rejected:

- a property that is not a predicate on the definition's type;
- an existence theorem whose statement is not the property applied to the definition;
- a uniqueness theorem that does not end in a relation between two objects its own hypotheses say
  satisfy the property (or between one of them and the definition);
- a theorem naming something never marked `@[characterization property]`;
- a theorem whose property cannot be read off its statement and was not named;
- the same misuses `@[specifies]` rejects: a proof where a definition belongs, a non-proposition
  where a theorem belongs, a repeated registration, `local` or `scoped` application.

### What is not

That the characterization *says* anything. `P x := (x = definition)` is well-formed and conveys
nothing, and so is a subtly wrong `P`. The checks buy well-formedness; the reader still has to read
the property and the relation, which is why any presentation of a characterization has to show both
in full. The one mechanical defence is a warning when the property mentions the definition it
characterizes, silenced with:

```lean
set_option characterization.checkNotCircular false
```

Two further gaps are deliberate. Nothing requires the property to be invariant under the relation,
so a bundle gives `P x → R x definition` and not the converse — the first is what a reader needs.
And uniqueness is propositional: "unique up to *unique* isomorphism" is a term-level statement, and
a characterization recorded with `R x y := Nonempty (x ≃ y)` loses the canonicity. For universal
properties, Mathlib's bundled `IsColimit`-style formulation is the right tool and this is a weaker
shadow of it.

### Why one attribute name, and none on the relation

Attribute names are global and unqualified, so three of them would be three chances to collide with
another library and make the two mutually un-importable. The roles share one name, distinguished by
a mandatory keyword.

The relation gets no attribute because it could not have one: `Eq` is declared in core and
`Filter.EventuallyEq` in Mathlib, and this library refuses to annotate an imported declaration —
and a relation like `Setoid.r s` is a partial application with no declaration to annotate at all.
It does have to be *applied*, though: the conclusion's last two arguments are the related pair, so
a relation written inline as `Nonempty (x ≃ y)` has to be given a name and stated as `IsoRel x y`.
A presentation wants that anyway, for the same reason it wants a named predicate.

## Importing under the module system

A file using the `module` keyword must import this library at compile time, since applying an
attribute is a compile-time act:

```lean
module
meta import LeanSpec
```

A plain `public import LeanSpec` is not enough on its own — the attributes are registered by the
module's initializer, which a runtime-phase import does not run, and they are then reported as
unknown attributes. Files not using the module system just write `import LeanSpec`.

## Reading the annotations back

```lean
LeanSpec.specEntries (env : Environment) : Array LeanSpec.SpecEntry
```

returns every `@[specifies]` annotation visible in `env` — theorem, target, comment — in
declaration order. `specTargetsOf` and `specTheoremsFor` filter it in either direction.

```lean
LeanSpec.characterizations (env : Environment) : Array LeanSpec.Characterization
```

returns the characterizations, with the parts of each already grouped: the property, the target,
and the existence and uniqueness theorems, each uniqueness entry carrying the relation it was
stated up to. `Characterization.isComplete` is the distinction that matters — a property with an
existence theorem and no uniqueness theorem says no more than a `@[specifies]` annotation does.
`characterizationsOf` and `isCharacterized` answer the same questions per definition, and
`charEntries` exposes the ungrouped entries.

Both theorems of a characterization also write a `SpecEntry`, so a consumer that only knows about
`@[specifies]` — "which definitions has nobody said anything about" — keeps working without
learning about the second extension.

A tool in a *different process* (one that imports a compiled project rather than being compiled
into it) can read them too, but it must link this library and import with
`importModules (loadExts := true)`: imported extension entries are matched to registered extensions
by name, and entries with no matching extension are silently dropped. Referee, in the
parent repository, does exactly this, and renders the result as a Specification section on each
definition's page, a note on each definition that has none, and a Specifications page listing both.

## Why not `@[spec]`

Taken. `Std.Tactic.Do` registers `@[spec]` for the specifications its `mvcgen`
verification-condition generator consumes, and Lean rejects a duplicate attribute registration
outright — a project importing both would be unable to build. `specifies` also reads better at the
use site. The token is declared non-reserved, so a project can still use `specifies` as an ordinary
identifier.

## Compatibility note for maintainers

`SpecEntry`'s and `CharEntry`'s field layouts, and `CharRole`'s constructor list, are part of the
`.olean` format: entries are deserialized as a memory image into whatever type the *reader's* copy
of this library declares, and the reader may be built from a different revision than the project it
reads. Adding or reordering fields, or adding a constructor, is therefore not a backwards-compatible
change. If it has to happen, rename the extension at the same time so that old entries are dropped
rather than misread.
