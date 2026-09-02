# Referee

`Referee` reads a compiled Lean project and builds a site that answers, for every result in it:
what does this claim, what does it rest on, and what would you have to take on faith?

The name is the reader it serves. A referee deciding whether to believe a paper needs the claims
separated from the machinery, the gaps made visible rather than buried, and the smallest
self-contained thing they can read to check a statement. That is what the site is: not documentation
of a library, but the evidence for it.

It is a Lean 4 executable, which took initial inspiration from [LeanExposition](https://github.com/mattrobball/lean-exposition/)
by Matthew Ballard. It renders through [Verso](https://github.com/leanprover/verso).

## What it builds

A multi-page HTML site, grouped by module with chapter order derived from the import graph. Every
declaration gets a card with its docstring, its source-first statement — taken apart into the
objects it is about, the structure and hypotheses it assumes, and what it claims or, for a
definition, its result type and body, each unfamiliar notion explained on hover — and its proof,
then what it rests on: the constants its statement mentions, everything in its closure, and a
dependency graph laid out in rows by depth. There is deliberately no whole-project graph: one picture of every
declaration is unreadable at any zoom and answers no question a reader has.

On top of that are the pages a referee needs and ordinary documentation does not have:

- **Theorems** — everything stated with `theorem`, separated from the machinery, each row carrying
  what you have made of it (see **[audit state](docs/audit.md)** below). **[Claims](docs/claims.md)**
  — the same rows, but only the results the project's own `formalization.yaml` puts forward, for a
  project that ships the [Palomar registry](https://palomar-registry.org/)'s metadata: the one list
  here that is asserted rather than measured. **Browse** — every
  declaration in one sortable, filterable table. **Sorries and assumptions** — `sorry` chains,
  extra axioms and unaudited upstream packages, reported as findings only: the page counts what is
  missing and never how much is done.
- **[Upstream trust](docs/trust.md)** — which upstream packages you have audited (`--trust PKG`) and
  which you have not, with the unaudited ones drawn into each declaration's graph so the picture
  bottoms out where trust has to start rather than at the project boundary. Upstream *proofs* need
  no trust: the kernel rechecked them. Upstream *definitions your statements are about* do.
- **[Specifications](docs/authoring.md)** — for projects that annotate with
  [`@[specifies]`](https://github.com/RemyDegenne/characterization): which definitions their author
  said something about, which they said nothing about, and, on each definition's page, the
  properties themselves. Its stronger sibling
  [`@[characterization]`](https://github.com/RemyDegenne/characterization)
  records the claim that a property pins the definition down
  *uniquely*, up to a stated relation — and, unlike `@[specifies]`, the attribute checks that the
  theorems really say so. Those get a section of their own above the specification, leading with the
  relation, because "the unique such object up to `=`" and "up to a.e. equality" are different
  claims and a page that says only "characterized" has told the reader the less useful half.
- **[Audit state](docs/audit.md)** — what *you* have read, on the Theorems page itself rather than on
  one of its own. A declaration is *accepted* when you judge that it says what its name claims, and
  *covered* when everything its statement rests on is accepted too — so the page can report what a
  checkbox cannot: a claim accepted while resting on definitions nobody has looked at. Reading queues
  in dependency order, and export to a JSON file that outlives the browser.
- **[Revisions](docs/revisions.md)** — given an earlier `collect` output (`--baseline`), what a reader
  who worked through that revision has to read again. Including the case no textual diff can show:
  results *invalidated indirectly*, whose own statements are untouched but whose meaning rests on a
  definition that moved. Proof-only changes are collapsed and stated to need no re-reading.
- **[Provenance](docs/provenance.md)** — when each declaration's meaning last changed, and in which
  revision, kept apart from when its file was last edited. The sentence that saves the most work is
  the one combining them: *edited last week, meaning unchanged since March*.

It also writes **[standalone `.lean` files](docs/extraction.md)**, one per declaration, each
self-contained with its transitive dependencies inlined and proofs replaced by `sorry` — the
smallest thing a reader can check a statement against, optionally linked into the
[web editor](https://live.lean-lang.org).

## Usable without the rest

Four pieces are separate Lake packages, off Referee's own build (Verso, SubVerso, MD4Lean, …), so a
project can take any one of them without taking the rest. Referee is a consumer of all four, not
their owner.
[`MeaningGraph`](https://github.com/RemyDegenne/meaning-graph),
[`Characterization`](https://github.com/RemyDegenne/characterization) and
[`ChallengeGen`](https://github.com/RemyDegenne/challenge-gen) have repositories of their own;
`JunkValues` is required from this one.

| | |
|---|---|
| [`MeaningGraph`](https://github.com/RemyDegenne/meaning-graph) | What every declaration rests on: the constants its statement uses, and the ones its statement and proof use — recovering the four things an elaborated term drops (compiler helpers, `Expr.proj` structures, notation expansions, coercion instances) — plus reverse edges and transitive closure in topological order. |
| [`Characterization`](https://github.com/RemyDegenne/characterization) | `@[specifies]` and `@[characterization]`: which theorems their author offers as the specification of a definition, and which properties pin one down uniquely. |
| [`ChallengeGen`](https://github.com/RemyDegenne/challenge-gen) | One declaration turned into a file that compiles on its own — dependencies inlined, proofs `sorry`ed, imports cut to the external frontier — in two tiers: verbatim source, which is readable, and environment-rendered, which is robust. Shaped for a challenge generator rather than for this tool; depends on Lean core and `MeaningGraph` only. |
| [`JunkValues/`](JunkValues/) | `@[junk_value]` and a linter: where a definition rests on the value a total function returns outside its intended domain — *if `f + g` is not integrable then `∫ (f + g) = 0`*. A rule is not a hand-maintained table entry but the theorem that already proves the collapse, so no rule can claim a default the kernel has not checked. Rules for libraries you cannot annotate live in [`Extra/`](JunkValues/JunkValues/Extra/) and are opt-in by import. |

```lean
require Characterization from git "https://github.com/RemyDegenne/characterization" @ "main"
require MeaningGraph from git "https://github.com/RemyDegenne/meaning-graph" @ "main"
```

## Status

Alpha. The validated execution path is: build this repo's executable, then run it inside the target
repo's `lake env`. The tool always exposes the project of the surrounding `lake env`, i.e. the
current working directory.

## Build

```bash
cd /path/to/referee
lake update
lake build referee
```

Or take a [prebuilt binary](docs/releases.md) from a release — but check its toolchain matches your
project's, because it will not work otherwise.

## Quick start

The target repo must already have current `.olean` files for the modules you want to expose.

```bash
cd /path/to/target-repo
lake exe cache get && lake build MyLibrary

REFEREE=/path/to/referee/.lake/build/bin/referee
OUT=/path/to/site-out

lake env "$REFEREE" collect --root MyLibrary --data data.json
lake env "$REFEREE" extract --data data.json --output "$OUT"
"$REFEREE"          build-site --data data.json --output "$OUT" \
  --repo-url https://github.com/owner/repo
```

That is enough for a complete site. Everything else is optional and adds one flag or one phase at a
time — interactive Lean, trust, revisions, provenance. See **[the pipeline](docs/pipeline.md)** for
the full sequence and why it is split this way, and **[the CLI reference](docs/cli.md)** for every
flag.

## Documentation

| | |
|---|---|
| [The pipeline](docs/pipeline.md) | The phases, what each produces, and the one hard boundary between them |
| [CLI reference](docs/cli.md) | Every subcommand and flag |
| [Running in CI](docs/ci.md) | The job shape, and the state that has to survive between runs |
| [Authoring](docs/authoring.md) | The two things the tool cannot infer: `theorem` vs `lemma`, and `@[specifies]` |
| [Upstream trust](docs/trust.md) | `--trust`, what counts as a trust dependency, and what the analysis does and does not claim |
| [Theorems and audit state](docs/audit.md) | Verdicts, coverage, reading queues, export — and the three limits |
| [Claims](docs/claims.md) | The Claims page: `formalization.yaml`'s main results, and what the site will not take from the file |
| [Comparing revisions](docs/revisions.md) | `--baseline`, the classification, and what the comparison is made on |
| [Semantic hashes](docs/semantic-hashes.md) | `--hashes`: structural hashes instead of pretty-printed text |
| [Provenance](docs/provenance.md) | `--provenance`: when meaning last changed, and the revision selector |
| [Extracted files](docs/extraction.md) | The minimal files, checking they compile, and the `extract-flat` fallback |
| [Prebuilt binaries](docs/releases.md) | CI artifacts, releases, and consuming them downstream |
| [Working on Referee](docs/development.md) | Code layout, theme, and iterating on style without a rebuild |

Design notes live in [docs/design/](docs/design/), kept separate because they argue rather than
instruct: [`PROPOSED-TOOLS.md`](docs/design/PROPOSED-TOOLS.md) (what has not been built, and why it
would be worth it), [`TRUST-GAPS.md`](docs/design/TRUST-GAPS.md) (what auditing this tool does not
cover at all), and [`WEBSITE-DESIGN.md`](docs/design/WEBSITE-DESIGN.md). Alongside them,
[`KNOWN-ISSUES.md`](KNOWN-ISSUES.md) records what does not compile and which fixes were tried and
measured to be worse.
