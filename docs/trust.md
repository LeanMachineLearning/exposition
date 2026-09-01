# Upstream trust

Every other measure on the site stops at the project boundary and treats what lies beyond it as
given. For a Mathlib-based development that is the larger half of what a reader is asked to accept,
and it is not uniform: `AlphaRAR` rests on `LeanMachineLearning`, which rests on `mathlib`, and a
referee may well have audited one and not the other.

`--trust PKG` says which. The **Sorries and assumptions** page then draws the package dependency
graph — toolchain at the top, project at the bottom — with unaudited packages dashed, lists them
with how many declarations rest on each, and each of those declarations names them on its own page.

Three things the flag means, which are easy to get wrong in either direction:

- **It is transitive.** Trusting a package necessarily vouches for what it is built from — Mathlib's
  own theorems rest on Batteries — so `--trust mathlib` marks Batteries trusted too. Anything else
  would be incoherent: you cannot believe a theorem while doubting what proves it.
- **The Lean toolchain is always trusted**, with no flag. It is the compiler and kernel that checked
  everything else, this tool included; a site premised on doubting it could report nothing at all.
- **The default is to trust nothing.** With no `--trust` at all, every upstream package counts as
  unaudited and the page says so, rather than quietly assuming that whatever is popular is fine.

It is repeatable, and a render-time flag: the same `data.json` can be rendered under different trust
assumptions without re-importing the project, so "what would this look like if I had not audited
LML?" costs one flag and a rebuild of the HTML.

## In the dependency graphs

The per-declaration dependency graphs carry the same information one level down. Declarations from
**unaudited** packages are drawn as nodes — dashed, greyed, and never links, since this site exposes
no page for them — gathered over the whole page closure, because "what unaudited code does this rest
on" is a question about the closure. This is the trust surface, the same set this page counts. On
`AlphaRAR` the whole surface into `LeanMachineLearning` is 15 declarations, which close to 22 once
the package's own edges are followed: 223 of 796 pages draw any of it at all, a median page draws
none, and the widest draws 16.

### One block per package

The picture is a stack of **blocks**, one per upstream package and one for the project, each layered
by depth internally. The margin names each block on its first row and numbers the levels from there,
so a page reads:

```
LeanMachineLearning · 1 · 2 · 3 · AlphaRAR · 1 · 2 · 3 · 4 · 5
```

Depth is therefore counted *within* a block. That is the only reading under which the numbers mean
the same thing in every block — "how far below the things this block depends on nothing for".

Blocks stack in **dependency order**, taken from the workspace's Lake graph: Mathlib above a package
built on Mathlib, above the project. The whole picture then reads one way, everything below what it
depends on. Ordering by trust instead would sort by a property of the *reader* rather than of the
code, and would put a package above its own dependency whenever the reader had audited one and not
the other.

An unaudited package is drawn with the structure it actually has, not as a flat list of the names
this project happens to mention: `collect` walks each upstream package's own internal edges, so
`Learning.stationaryEnv → Learning.obliviousEnv → Learning.Environment` appears as three levels
inside the `LeanMachineLearning` block. See [what gets expanded](#what-gets-expanded).

A package with no collected internal edges has everything at depth 0, so its block is a **single
level that wraps** to the viewport — the flat band this drew before blocks existed, kept as the
degenerate case rather than as a second code path. That is the shape Mathlib always takes. Wrapping
is what keeps a level from growing sideways with its fan-out: on `AlphaRAR` the widest page put 244
boxes in one row, several thousand pixels against a viewport around twelve hundred. It spends
vertical space, which the picture has, rather than horizontal space, which it does not.

The toolchain is left out entirely. It is trusted unconditionally, so it is never a finding, and as
context it is `Nat`, `OfNat.ofNat` and `instOfNatNat` — on `AlphaRAR` a quarter of the upstream nodes
spent on constants that say nothing about what a theorem means.

Proof-only references are excluded too, since the graph follows `meaningDeps`: they would add
constants the kernel has already checked.

Clicking a node shows what it says, read out of the compiled environment at `collect` time — for a
theorem its statement, for a definition its value, for a structure or class its fields — with its
docstring. These are the nodes where a reader's trust has to start, and "is this the definition I
think it is" is a question they should not have to leave the site to answer. The type alone does not
answer it: `Filter.Tendsto`'s type is `(α → β) → Filter α → Filter β → Prop`, whose arguments all
read as hypotheses and which never says that it means `map f l₁ ≤ l₂`. These live in a single
`upstream.js` table rather than in each page, because one upstream constant is named by many
declarations.

### What gets expanded

Drawing a package's internal levels needs its own dependency edges, which `collect` has to gather —
and `collect` cannot know which packages will matter, because `--trust` is a render-time flag by
design. So it walks **every** upstream package, starting from the constants this project's statements
name and following meaning edges that stay inside that package, and abandons any package whose
closure exceeds 500 constants.

That budget is what makes the automatic version work. Mathlib overruns within a few steps and is
recorded as the flat surface it always was; `LeanMachineLearning` finishes at 22 constants and is
recorded with its edges. `CollectedData.expandedPackages` says which. A package that overruns loses
nothing it had before — it is drawn as a single wrapped level, exactly as it was — so the failure
mode is a less structured picture rather than a missing one.

The cutoff is a legibility bound as much as a cost one. A block of 500 nodes is not a picture anyone
reads, so a package that large is better summarised by the counts on this page than drawn.

Two details worth knowing:

- **Only edges that stay inside the package are followed.** One leaving it points either at the
  project, which depends on the package rather than the reverse, or at a further package, whose
  expansion is decided on its own terms.
- **Compiler-generated helpers are expanded through, not shown**, the same treatment
  `MeaningGraph.expandThroughInternals` gives the project's own declarations. Without it an
  `_autoParam` — the tactic behind a structure field's default — becomes a node in the picture, and
  nobody wrote it.

### Audited packages: `--show-trusted-upstream`

Declarations from packages you *have* audited are not drawn by default. `--show-trusted-upstream`
adds them, solid rather than dashed, and gathered for the focus declaration only — the reader has
already vouched for the package, so the question is no longer trust but what this statement is
*about*, which is a property of that statement and not of everything beneath it.

An audited package is never expanded — the budget rules Mathlib out long before trust is consulted —
so it always arrives as a single wrapped level, however many constants it contributes.

The default is off, and the reason is worth stating because the flag looks like it should be on. On a
Mathlib-backed project it adds a median of 22 nodes per page against a project structure that is
typically three: the upstream part stops being an annotation on the graph and becomes the graph. What it shows
is also not new — the declaration's own code block at the top of the page already gives the same
constants, in the statement's own syntax, with types on hover. On `AlphaRAR`:

| | default | `--show-trusted-upstream` |
|---|---|---|
| upstream nodes per page | median 0, p90 13, max 16 | median 22, p90 57, max 223 |
| total nodes per page | median 3, p90 18, max 29 | median 25, p90 61, max 237 |

It stays available because the judgement could go the other way on a project whose upstream is small,
or one where the audited packages are the interesting part. Like `--trust`, it is render-time: the
data is collected either way, so turning it on costs a rebuild of the HTML and no re-import.

Three things are worth knowing about how the analysis is computed, because they bound what it
claims:

- **It is package-granular, not constant-granular.** A full constant-closure walk into Mathlib, once
  per declaration, is not affordable (`Lean.collectAxioms` only gets away with it because axioms for
  imported constants are precomputed in an environment extension, so its walk stops at the project
  boundary). What is recorded instead is the packages a declaration's project-level closure
  references directly, closed over the Lake dependency graph at render time.
- **That closure is sound.** A constant can only reference what its own package imports, so if a
  declaration's closure reaches a package, that package is reachable in the Lake graph from one it
  references directly. The analysis therefore cannot miss an upstream dependency — the direction that
  matters, since under-reporting would tell a reader they do not rest on code they do.
- **It is bounded by what was actually loaded.** Closing the Lake graph alone over-reports badly:
  `LeanMachineLearning` declares a dependency on Verso for building its own site, which would make
  every declaration using LML appear to rest on Verso, SubVerso, MD4Lean and Illuminate. None of that
  code is in the imported environment, so no closure can reach it, and it is excluded. On `AlphaRAR`
  this is the difference between reporting 5 unaudited packages and reporting the 1 that is real.

## What counts as an upstream trust dependency

Not what a proof calls. An upstream *proof* was rechecked by the kernel, and anything left unproved
in one arrives as a `sorry` or an extra axiom — both of which `collectAxioms` already reports
transitively, upstream included, on the sorries page. A theorem whose proof calls a
`LeanMachineLearning` lemma has learned nothing from that call that it needs to take on faith.

What counts is an upstream *definition that a statement is about*. If a theorem's statement mentions
`Learning.IsAlgEnvSeq`, then what the theorem *means* depends on that definition being the intended
one, and no proof anywhere settles it — the same gap `@[specifies]` records, one package up.

So the measure follows `meaningDeps`, the same edges the rest of the site uses: a theorem contributes
its statement, and a definition the *data* in its body — its body is part of its meaning, but the
proof obligations bundled into it (`left_inv`, `map_add'`, …) are kernel-checked like any other
proof and are dropped for the same reason a theorem's proof is. The
difference is not cosmetic. On `AlphaRAR`, following proofs reported 172 declarations as resting on
`batteries`; following statements reports none, because no statement in the project mentions a
Batteries definition — every one of those 172 was a kernel-checked proof detail needing no audit.
