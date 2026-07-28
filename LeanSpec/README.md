# LeanSpec

A single attribute, `@[specifies]`, for recording which theorems are part of the **specification of
a definition** — the properties their author offers as evidence that the definition is the intended
one.

Depends on Lean core and nothing else. It lives in the
[`exposition`](https://github.com/LeanMachineLearning/exposition) repository but is a separate Lake
package precisely so that annotating a project does not drag in the exposition tool's own
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

### Importing under the module system

A file using the `module` keyword must import this library at compile time, since applying an
attribute is a compile-time act:

```lean
module
meta import LeanSpec
```

A plain `public import LeanSpec` is not enough on its own — the attribute is registered by the
module's initializer, which a runtime-phase import does not run, and `@[specifies]` is then
reported as an unknown attribute. Files not using the module system just write `import LeanSpec`.

## What is checked

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

## Reading the annotations back

```lean
LeanSpec.specEntries (env : Environment) : Array LeanSpec.SpecEntry
```

returns every annotation visible in `env` — theorem, target, comment — in declaration order.
`specTargetsOf` and `specTheoremsFor` filter it in either direction.

A tool in a *different process* (one that imports a compiled project rather than being compiled
into it) can read them too, but it must link this library and import with
`importModules (loadExts := true)`: imported extension entries are matched to registered extensions
by name, and entries with no matching extension are silently dropped. The `exposition` tool in the
parent repository does exactly this, and renders the result as a Specification section on each
definition's page, a note on each definition that has none, and a Specifications page listing both.

## Why not `@[spec]`

Taken. `Std.Tactic.Do` registers `@[spec]` for the specifications its `mvcgen`
verification-condition generator consumes, and Lean rejects a duplicate attribute registration
outright — a project importing both would be unable to build. `specifies` also reads better at the
use site. The token is declared non-reserved, so a project can still use `specifies` as an ordinary
identifier.

## Compatibility note for maintainers

`SpecEntry`'s field layout is part of the `.olean` format: entries are deserialized as a memory
image into whatever type the *reader's* copy of this library declares, and the reader may be built
from a different revision than the project it reads. Adding or reordering fields is therefore not a
backwards-compatible change. If it has to happen, rename the extension at the same time so that old
entries are dropped rather than misread.
