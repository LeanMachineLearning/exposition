# Claims: what the project says it proves

Every page of a Referee site is derived from the compiled library, with one exception. If something
in the project names its main results, the site gains a **Claims** page listing them — the project's
own statement of what the work is for.

Two documents can name them, and a project may ship either, both, or neither:

- **`formalization.yaml`**, declaring `status.main_results`. This is the metadata document the
  [Palomar registry](https://palomar-registry.org/) requires of a submission
  ([schema](https://github.com/mathlib-initiative/formalization.yaml),
  [template](https://github.com/PalomarRegistry/PalomarTemplate)).
- **A [Comparator](https://github.com/leanprover/comparator) setup**: one config per result, pairing
  a challenge module that restates the theorem with the solution module that proves it.

Nothing here asks a project to adopt either for Referee's sake: a project that has one gets a page,
and a project that has neither is never told about it. `--claim NAME` names them on the command line
instead, for a project with no metadata at all.

## Reading a Comparator setup

A config is found by its *shape* — it has `challenge_module`, `solution_module` and `theorem_names` —
rather than by living in a directory with a particular name. Referee looks at the paths
`formalization.yaml`'s `comparator_config` fields point at, at `--comparator DIR`, and, only when
neither of those produced anything, at the project root and its immediate subdirectories.

**One config is one claim, and every theorem it names belongs to that claim.** This is not the
obvious rule, and the obvious ones are both wrong on real projects:

- *"the first `theorem_names` entry is the headline"* — `ten-proofs`' `A_SpherePacking.json` names
  four theorems, and the one its own `formalization.yaml` calls the main result is the **fourth**.
- *"every name is a claim"* — thirteen of `colt-2026-83`'s seventeen configs pair a headline with an
  auxiliary target that a definition in the statement's closure needs. Promoting those to headlines
  would list plumbing beside the results.

A config's `theorem_names` is the list of statements that must be certified *together* for that one
challenge to mean anything, so the config is the unit. Where `formalization.yaml` **does** rank them
— which is what `comparator_config` is for — its ranking wins: the entry's `declaration` becomes the
headline and the config's other names become additional targets listed under it.

The page reports the certification itself, because it is the one thing on the whole site that is not
this tool's own reading: which config certifies each claim, its permitted axioms, whether it asks
for a second independently implemented kernel, and what else it certifies alongside. What it
settles is the *statement*; what the definitions in that statement mean is the gap the rest of the
site exists for, and the page says so rather than showing a bare checkmark.

The config parser is `Lean.Json`. None of the argument below about hand-writing a YAML subset
applies to it: JSON is already in the environment and a malformed config is an error, not a silent
misreading.

## Why this is a page and not a section of the Theorems page

Because they answer different questions, and only one of them can be got wrong.

[Theorems](audit.md) is derived: everything the library states with the `theorem` keyword rather than
`lemma`. It cannot be wrong about what the library states — at worst it inherits a project's
carelessness about the two keywords, which the page says out loud.

Claims is a sentence the author wrote. It can name a result that does not exist, omit the one that
matters, or put forward as a headline something the library proves in passing. That is not a defect
of the file; it is what a *claim* is, and a referee's first question is whether it holds. Merging the
two lists would have hidden which half was measured and which half was asserted.

Where the two disagree, the disagreement is information. A main result stated as a `lemma` is a
keyword the author should reconsider. A theorem the file passes over is either machinery or an
omission, and only the author knows which.

## What the page shows

The rows are the Theorems page's rows, deliberately unchanged: the same link, the same count of what
the statement rests on, the same `sorry` flag, and the same audit verdict under the same key — a
declaration accepted on one page is accepted on the other, because it is one declaration. What
differs is which declarations appear and in what order. Here the order is the file's, because a
curated list is an argument about what matters and its order is part of the argument.

The audit apparatus — export, import, report, the progress summary — stays on the Theorems page. This
page carries the handful of results the author chose, and nothing to work through: a claim is
audited on its own page, in the dependency graph there.

Below the list, three things the compiled library cannot supply:

- **Results the library does not have.** A `main_results` entry naming a declaration that is not
  exposed is listed with the file the metadata claims it lives in. Usually a rename the file did not
  follow. `collect` also warns about it on the console, where the author is the person who can act.
- **Literature dependencies.** `literature_dependencies` records results the project relies on but
  does not prove. A theorem taken from the literature leaves behind no `sorry` and no extra axiom, so
  nothing on the [sorries and assumptions](trust.md) page can report it — the assumption is in the
  author's prose. Neither list bounds the other.
- **Scope.** `status.scope`, verbatim: the weakened hypothesis or the omitted case that no list of
  theorem names can show.

## What it deliberately ignores

`main_results` entries also carry a `sorry_count` and an `axioms` list. The site does not render
them, because it measures both itself and the two measurements are not the same measurement — the
file's counts exclude Comparator challenge modules, this site's do not. Showing them side by side
would invite a comparison that means nothing. The row shows what this build measured.

## Building only the claims

`collect --claims-only` restricts the whole build to the results named above and the declarations
their **statements** rest on. `collect --only DECL` is the same thing with a claim set of one
declaration — the same scope rule and the same site, so everything that declaration's statement
rests on gets a page too.

Rendering *only* the named declaration was the first design of `--only`, and it was wrong. A claim's
page is mostly the dependency graph beneath it, and a graph whose nodes have no pages leaves the
reader at a summary panel — name, kind, signature, docstring — when what they came for is the card:
the statement taken apart, the source, the proof. The closure is a couple of dozen declarations, so
giving it pages costs nothing that matters.

The choice of closure is the whole of it. Under `deps` — everything a result touches at all — the
scope is about 70% of a library and the mode is barely worth having. Under `meaningDeps` — what the
*statement* rests on — it is about 2%:

| | colt-2026-83 | alpha-rar |
|---|---|---|
| library (exposed declarations) | 1901 | 816 |
| closure under `deps` (statement **and proof**) | 1324 — 69.6% | 563 — 69.0% |
| closure under `meaningDeps` (statement only) | 37 — 1.9% | 19 — 2.3% |
| … plus the `@[specifies]` pull, to a fixpoint | 37 | 53 — 6.5% |
| files `extract` writes and `highlight-extracted` elaborates | 1901 → 37 | 816 → 53 |
| `collect`, wall clock | 47.3s → **6.8s** | — |

A formalization's statement surface is a small fraction of it; the rest is proof machinery. On
colt-2026-83 the 37 are the nine claims plus the twenty-eight definitions and structures their
statements are about — a site a referee can read to the end, which is the only size at which the
audit apparatus means anything.

**The `@[specifies]` pull is part of the scope, not a detail.** A theorem carrying `@[specifies]` or
`@[characterization]` for a definition in scope is pulled in even though nothing depends on it, and
the scope is then re-closed. It is what a reader judging a claim needs — the theorems that say what
the definitions *mean* — and no dependency edge points at it. On alpha-rar it takes the scope from
19 declarations to 53.

**Scope discovery does not walk the library.** A scoped `collect` traverses outward from the claims,
computing a declaration's dependency edges and source keywords only when the traversal reaches it —
so source files are read and parsed only when they contain something in scope. On `colt-2026-83`
that pass covers 38 declarations in 16 files rather than 1901 in 141, and takes 1.6s rather than
30.7s. On a 32,154-declaration project scoped to 13, it is 0.8s.

What is left proportional to the library is the import itself and `MeaningGraph.Context.of`, which
builds the notation and coercion tables the dependency expansion needs.

**What a scoped build still keeps.** Two analyses would notice if the dropped declarations vanished
outright, so they are kept as *edges only*, with no signature, docstring or source:

- the closure a minimal file inlines along, which is wider than the graph's because a definition's
  body drags in the lemmas discharging its embedded proof obligations;
- the declarations a `sorry` chain passes through. `dependsOnSorry` comes from `collectAxioms`
  against the whole environment and stays correct however the build is scoped, so without this a
  scoped site would report the right `sorry` and blame it on an upstream package. Only declarations
  that themselves depend on a `sorry` can lie on a chain, so this set is empty on a project that has
  none — as both projects above do.

Every count on a scoped site is over the scope, and the landing page says so before showing any of
them. `--baseline` refuses to compare a scoped file against a differently scoped one: every
declaration the narrower build left out would otherwise read as removed.

## The parser

`Referee/Formalization.lean`, and it is a subset of YAML rather than the whole of it: block mappings
and sequences, one-line flow collections, quoted and plain scalars, folded and literal block scalars,
and comments. No anchors, no aliases, no tags, no multi-document streams past the first. Taking on a
YAML dependency for one file at the edge of the build was the worse trade — each package this tool
requires is there to be useful without it, and none of them wants a YAML reader.

The cost is honest and worth stating: an unsupported construct yields a wrong reading, not an error.
The one exception is a tab in a line's indentation, which is refused — it changes structure
invisibly rather than content, which is the failure a reader would never catch. Everything else is
bounded by the fields the site actually reads, each of which has a harmless default, so a misread
field goes missing from the page rather than appearing wrong on it.

A file that will not parse is a warning on the console and no Claims page. It is never a build
failure: the file sits beside the library rather than inside it, and trading the whole report for one
malformed page would be the wrong way round.

`Test/Formalization.lean` pins the cases a subset parser actually gets wrong — `- key: value` sharing
a line with its dash, a `:` inside a URL, a `#` inside quotes, folded versus literal blocks, and
plain scalars continued across a blank line.
