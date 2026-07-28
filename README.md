# LMLExposition

`LMLExposition` is a Lean 4 executable that walks a compiled project's environment and emits a Verso `Manual` site for mathematician-facing exposition. It is a fork of [LeanExposition](https://github.com/mattrobball/lean-exposition/) by Matthew Ballard.

Features:

- programmatic `Part Manual` generation from declarations in a compiled environment
- grouping by the first path component after the root module, with chapter/module order derived from the import graph
- declaration cards with docstrings, source-first Lean statements, collapsible `Uses` / `Used by`, and collapsible proof bodies
- a per-declaration dependency graph, laid out in rows by dependency depth (top row depends on
  nothing) and transitively reduced. Declarations from *unaudited upstream packages* are drawn in
  too, dashed and unclickable, so the picture bottoms out where the reader's trust has to start
  rather than at the project boundary. There is deliberately no whole-project graph: one picture of
  every declaration is unreadable at any zoom and answers no question a reader has
- a claims page (everything stated with `theorem`), a browse page (every declaration in one
  sortable, filterable table), and a trust page (`sorry` chains, axioms)
- **upstream trust**: a package dependency graph on the trust page, marking which upstream packages
  you have audited (`--trust PKG`, repeatable, vouching for that package *and everything it depends
  on*) and which you have not, plus a line on every declaration whose *statement* reaches into
  unaudited code — upstream proofs need no trust, having been rechecked by the kernel
- a specifications page, for projects that annotate their theorems with
  [`@[specifies]`](LeanSpec/): which definitions their author said something about, which they
  said nothing about, and — on each definition's own page — the properties themselves
- per-declaration standalone Lean files (under `extracted/`), each self-contained with its transitive
  dependencies inlined and theorem proofs replaced by `sorry`, optionally linked into the
  [live.lean-lang.org](https://live.lean-lang.org) web editor (see `--site-url`)
- multi-page HTML output through Verso's `manualMain`

## Status

Alpha implementation. The validated execution path is:

1. build this repo's executable
2. run that executable inside the target repo's `lake env`

The tool always exposes the project of the surrounding `lake env`, i.e. the current working directory.

## Build

```bash
cd /path/to/lml-exposition
lake update
lake build exposition
```

## Run Against A Target Repo

The target repo must already have current `.olean` files for the modules you want to expose.

The pipeline is a sequence of phases with one hard boundary: everything that needs a Lean
environment produces **data**, and rendering is a pure function of that data.

| phase | needs `lake env`? | produces |
|---|---|---|
| `collect` | yes | `data.json` — declarations, dependencies, docstrings, axioms, `sorry` status |
| `extract` | yes | `extracted/*.lean` — the self-contained minimal file per declaration |
| `highlight` | yes | `highlighting/*.json` — interactive Lean for each project module |
| `highlight-extracted` | yes | `extracted-highlighting/*.json` — interactive Lean for each minimal file, **and whether it compiles** |
| `build-site` | no | the Verso HTML site |

`build-site` touches nothing but those files, so it can be re-run as many times as you like —
e.g. while iterating on page layout or CSS — without re-importing the target project.

```bash
cd /path/to/target-repo
lake exe cache get
lake build MyLibrary

EXPOSITION=/path/to/lml-exposition/.lake/build/bin/exposition
OUT=/path/to/site-out

lake env "$EXPOSITION" collect --root MyLibrary --data data.json

lake env "$EXPOSITION" extract --data data.json --output "$OUT"

# Interactive Lean: hover a symbol for its type, click to jump to its definition.
lake env "$EXPOSITION" highlight --data data.json --output "$OUT"
lake env "$EXPOSITION" highlight-extracted --output "$OUT"

"$EXPOSITION" build-site --data data.json --output "$OUT" \
  --repo-url https://github.com/owner/repo \
  --site-url https://owner.github.io/repo
```

Both highlighting phases fan out one worker process per file (`--jobs N`, defaulting to the CPU
count) because highlighting must elaborate source against a freshly imported environment. They are
optional: without them `build-site` renders plain code blocks and omits the inline minimal files,
and says so.

`highlight-extracted` doubles as the compile check for the extracted files. Producing the
highlighting *is* an elaboration, so the same pass records which minimal files fail — and the site
reports that on the declaration's own page rather than presenting unverified output as verified.
This subsumes what `scripts/check-extracted-compile.sh` does for site-building purposes; the script
remains useful for checking extraction in isolation.

`build-site` is the only one of the three that doesn't need `lake env` (it has no
environment or project dependency at all). `--repo-url`/`--site-url`/`--title` only affect
`build-site`'s output, so the same `data.json` can be rendered with different values for
those without re-running `collect`.

For the previous one-shot behavior (no JSON round-trip, equivalent to running all three back
to back in one process), use `all`, or omit the subcommand entirely — a bare invocation
defaults to `all` for backward compatibility:

```bash
lake env "$EXPOSITION" all \
  --root MyLibrary \
  --repo-url https://github.com/owner/repo \
  --site-url https://owner.github.io/repo \
  --output /path/to/site-out
```

Verso writes the site into the chosen output directory, typically under `html-multi/`.

## Verifying Extracted Files Compile

Each file under `extracted/` is self-contained (it inlines its transitive dependencies and
replaces theorem proofs with `sorry`), but nothing checks that it actually compiles until
something tries to. `scripts/check-extracted-compile.sh` does that check: it runs `lake env
lean` on every extracted `.lean` file from inside the target project (so imports like Mathlib
resolve), in parallel, and reports which files fail with their error output.

```bash
scripts/check-extracted-compile.sh /path/to/target-repo /path/to/site-out/html-multi/extracted
```

The third, optional argument caps how many files are checked in parallel (defaults to the
number of CPUs). The script exits non-zero if any file fails to compile.

A small number of extracted files are known not to compile. [`KNOWN-ISSUES.md`](KNOWN-ISSUES.md)
records the current pass rate across the projects this is tested against, the root cause of each
remaining failure, and — importantly — the approaches that were tried and measured to be worse, so
they are not retried.

## Fallback Extraction (`extract-flat`)

`extract` optimizes for a file a mathematician can read: it copies verbatim source text and
replays the surrounding `namespace`/`open`/`variable`/notation context. That context replay is
also where it fails.

`extract-flat` is a second, independent extraction path that gives up readability to gain
robustness. It never reads a source file: each declaration is rendered from its `ConstantInfo` in
the compiled environment, fully qualified and `@`-explicit, with proofs replaced by `sorry`.
Nothing has to be replayed — no `variable` binders, no namespaces, no notation, no attributes —
and no instance is ever synthesized, so the entire class of context-replay failures disappears.

```bash
lake env "$EXPOSITION" extract-flat --data data.json --output /path/to/site-out
```

It takes the same inputs as `extract` and writes to `html-multi/extracted-flat/`, so both tiers can
be produced from one `collect` and compared:

```bash
scripts/check-extracted-compile.sh /path/to/target-repo /path/to/site-out/html-multi/extracted-flat
```

The intended use is as a fallback: prefer `extract`'s output, and substitute the `extract-flat`
file for the declarations whose readable version does not compile. See
[`KNOWN-ISSUES.md`](KNOWN-ISSUES.md) for its measured pass rate and its own failure modes.

## Options

- `--root PREFIX`: root module prefix to expose (defaults to the first root library)
- `--repo-url URL`: base GitHub URL used for source and issue links
- `--site-url URL`: base URL where the generated site will be deployed. When set, each declaration
  gets an "open in web editor" link pointing at [live.lean-lang.org](https://live.lean-lang.org),
  preloaded (via its `#url=` parameter) with the declaration's standalone extracted file served from
  `<site-url>/extracted/<id>.lean`. Omit it to skip these editor links (the `extracted/` files are
  still written either way). The URL must match where the site is actually published, since the web
  editor fetches the `.lean` file over the network.
- `--trust PKG`: treat the upstream package `PKG`, **and everything it depends on**, as audited.
  Repeatable, and a render-time flag, so the same `data.json` can be rendered under different trust
  assumptions without re-importing the project. Trusting a package necessarily vouches for what it
  is built from — Mathlib's own theorems rest on Batteries, so `--trust mathlib` marks Batteries
  trusted too. The Lean toolchain is always trusted: it is the compiler and kernel that checked
  everything else. Anything left untrusted is listed on the trust page, with how many declarations
  have its definitions in their statements, and named on each of those declarations' pages. With no
  `--trust` at all, every upstream package counts as unaudited and the page says so
- `--title TITLE`: override the site title
- `--output DIR`: output directory passed through to Verso
- `--exclude-lib NAME`: root library to skip when importing the target project
- `--data PATH`: collected-data JSON file; written by `collect`, read by `extract` and
  `build-site`

## Code Layout

- `LeanDeps.lean` — the dependency analysis, as a **standalone library** (`lean_lib LeanDeps`)
  that depends on Lean core only: no Lake, no Verso, no notion of a site or of an output format.
  It answers, for every declaration of a project, which constants its type uses and which its type
  and body use, looking through compiler-generated helpers (`_proof_N`, `match_N`, field defaults)
  and recovering the dependencies an elaborated term drops (`Expr.proj` structures, notation
  expansions, coercion instances). It also holds the graph passes that run on the result: reverse
  edges and transitive closure in topological order. Entry points: `LeanDeps.Context.of` /
  `Context.declDeps` / `declDepsOf`.
- `LeanSpec/` — the `@[specifies]` attribute, as a **separate Lake package** rather than a library
  of this one. It is the only part of this repository a target project depends on, so it must not
  pull Verso along with it: Lean core only, one file, no dependencies. This package depends on it
  too, for the other end of the same wire — reading the annotations back out of a compiled project
  requires the environment extension to be registered in the reading process. See
  [`LeanSpec/README.md`](LeanSpec/README.md).
- `LMLExposition/Collect.lean` — walks the environment and builds one `DeclInfo` per exposed
  declaration (signature, docstring, source snippet, kind), delegating all dependency computation to
  `LeanDeps` and deciding only which edges the exposition follows (`graphDeps`: type-only for
  theorems). `sorry` status is a single transitive flag (`dependsOnSorry`) obtained from
  `Lean.collectAxioms`, i.e. the same answer `#print axioms` gives. `@[specifies]` annotations are
  read here too and reversed by `attachSpecifiedBy`, the one field on `DeclInfo` that is not
  derived from the environment but taken from the author.
- `LMLExposition/Extract.lean` — the standalone `.lean` file extraction (see `KNOWN-ISSUES.md`).
- `LMLExposition/Highlight.lean` — source-text highlighting. Runs the Lean frontend over a file and
  returns SubVerso `Highlighted` per command, tagged with the names each command defines, plus any
  elaboration errors. Depends on Lean and SubVerso only — it knows nothing about the site.
- `LMLExposition/Website/Site.lean` — Verso page construction and the CLI subcommands. The site's
  CSS and JavaScript live in `LMLExposition/Website/assets/` as real files and are embedded with
  `include_str`. D3 is vendored there too rather than fetched from a CDN at page load. Everything
  specification-related is gated on `SiteContext.usesSpecs`, so a project that does not annotate
  gets exactly the site it got before the feature existed.

## Upstream Trust

Every other measure on the site stops at the project boundary and treats what lies beyond it as
given. For a Mathlib-based development that is the larger half of what a reader is asked to accept,
and it is not uniform: `AlphaRAR` rests on `LeanMachineLearning`, which rests on `mathlib`, and a
referee may well have audited one and not the other.

`--trust PKG` says which. The trust page then draws the package dependency graph — toolchain at the
top, project at the bottom — with unaudited packages dashed, lists them with how many declarations
rest on each, and each of those declarations names them on its own page.

The per-declaration dependency graphs carry the same information one level down: the upstream
declarations an unaudited package contributes are drawn as nodes — dashed, greyed, and not links,
since this site exposes no page for them — in the top row, where nothing precedes them. Only
unaudited packages, and only what a statement names: drawing trusted upstream would put several
hundred Mathlib nodes on every page, and drawing proof-only references would add constants the kernel
has already checked. On `AlphaRAR` that comes to at most 9 extra nodes on any page and none on most,
because the entire trust surface into `LeanMachineLearning` turns out to be 15 declarations — the
sort of thing worth knowing before deciding whether to audit a dependency.

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

### What counts as an upstream trust dependency

Not what a proof calls. An upstream *proof* was rechecked by the kernel, and anything left unproved
in one arrives as a `sorry` or an extra axiom — both of which `collectAxioms` already reports
transitively, upstream included, in the sections above. A theorem whose proof calls a
`LeanMachineLearning` lemma has learned nothing from that call that it needs to take on faith.

What counts is an upstream *definition that a statement is about*. If a theorem's statement mentions
`Learning.IsAlgEnvSeq`, then what the theorem *means* depends on that definition being the intended
one, and no proof anywhere settles it — the same gap `@[specifies]` records, one package up.

So the measure follows `graphDeps`, the same edges the rest of the site uses: a theorem contributes
its statement, everything else its body too, since a definition's body is part of its meaning. The
difference is not cosmetic. On `AlphaRAR`, following proofs reported 172 declarations as resting on
`batteries`; following statements reports none, because no statement in the project mentions a
Batteries definition — every one of those 172 was a kernel-checked proof detail needing no audit.

## What The Tool Assumes About Your Library

Almost everything the site shows is derived: dependencies, closures, `sorry` chains, axioms,
compile status. Two things are not, and they are worth knowing before you point the tool at a
project. Both are editorial intent — claims about what matters, which no analysis of the
environment can recover.

**The Claims page lists the declarations you wrote with `theorem`, not `lemma`.** It takes the
usual convention at face value — `theorem` for a result worth stating for its own sake, `lemma`
for a step towards one — because Lean records both as the same kind and nothing else in the
environment distinguishes them.

So the choice between the two keywords is the one piece of editorial intent the tool cannot infer,
and the only thing you have to do deliberately to get a useful Claims page. `LeanMachineLearning`
states 11 of its 698 declarations as theorems, and they are exactly the point of the library — the
regret bounds. A project that writes `theorem` everywhere gets a Claims page meaning "all results":
still true, just less useful. Nothing else on the site depends on the distinction.

**The specification of a definition is whatever you marked with `@[specifies]`.** A proof can be
checked by the kernel; a definition cannot. What settles whether `entropy` means entropy is a
handful of theorems — it agrees with the textbook formula, it is non-negative, it reduces to the
classical notion in the classical case — and nothing in the environment distinguishes those from a
lemma used once on the way to something else.

[`LeanSpec`](LeanSpec/) is a separate, dependency-free Lake package holding one attribute for
recording them at the theorem:

```lean
@[specifies entropy "agrees with the textbook formula on finite supports"]
theorem entropy_eq_sum … := …
```

A target project that depends on it and annotates its theorems gets two things this tool cannot
otherwise derive: for each definition, the properties its author claims pin it down, and — the
more useful half — which definitions carry no such claim at all. `collect` reads the annotations
straight out of the compiled environment and records them on every declaration as `specifies` (on
the theorem) and `specifiedBy` (on the definition), and the site renders them in four places:

- **on a definition's page**, a *Specification* section listing each marked theorem with its
  statement and the author's note — a reader judges whether the properties pin the definition down
  by reading them, so the statements are inline rather than behind links;
- **on a definition's page with none**, a line saying so, which is the finding an auditor is
  after and is invisible otherwise;
- **on a theorem's page**, which definitions it speaks for;
- **a Specifications page**, the counterpart to Trust: what is specified, what is not — the
  unspecified ranked by how many declarations use them, so the biggest gaps come first — and a
  plain statement of what the page cannot tell you, namely whether any given specification is
  *enough*. The Browse table gains a matching `Spec` column and filter.

Every one of those is gated on the project having at least one annotation. A project that does not
use the package is not penalised for it: the fields are empty, the page is not built, the column is
not rendered, and nothing on any page mentions specifications at all.

The attribute is checked, not decorative: the target is an identifier, so a typo or a renamed
definition is a build error rather than a stale line in a metadata file. See
[`LeanSpec/README.md`](LeanSpec/README.md) for how to depend on it, what else it validates, and why
the attribute is not called `spec`.

## Theme

`LMLExposition/Website/assets/exposition.css` is the whole theme, built on a token block that
exists in a light and a dark variant. It loads after Verso's `book.css` and `verso-vars.css`, so it
both restates Verso's own custom properties (fonts, text/code/structure colours, code-highlighting
colours) and overrides the handful of places its stylesheet hardcodes a colour.

Verso ships no dark mode, so the dark variant also themes its chrome — header, table of contents,
and the search box, which reads a `--verso-background-color` that Verso never defines and so
defaulted to white. A control in the sidebar cycles auto → light → dark; the choice is stored in
`localStorage` and applied by a small inline script in `<head>` so the page never flashes the wrong
theme. The dependency graph reads its colours from the same tokens and repaints on a
`exposition:themechange` event rather than requiring a reload.

## Iterating On Style

The site's CSS and JS are emitted as *files* (into `html-multi/-verso-data/`) rather than inlined
into every page, so a style change does not need a rebuild at all:

```bash
# edit LMLExposition/Website/assets/exposition.css or graph.js, then:
scripts/sync-assets.sh /path/to/site-out
```

and reload the browser, bypassing its cache. That takes milliseconds, against roughly a minute for
`lake build` plus `build-site`. A full rebuild is only needed once the Lean-side page structure
changes.

Two things worth knowing:

- The assets are declared as a Lake `input_dir` in `lakefile.lean`, with `needs := #[websiteAssets]`
  on the library. Without that, `include_str` is invisible to Lake's change detection and
  `lake build` reports success while silently keeping the stale `.olean` — the site then builds from
  the *previous* version of the file.
- `sync-assets.sh` patches an already-built site only. The binary still embeds whatever was there at
  build time, so re-run `lake build` before generating a site you intend to publish.
- `Test/` — `#guard`-based unit tests (`lake build Test`), split the same way: `Test/Deps.lean`
  covers `LeanDeps`, `Test/Collect.lean` and `Test/Extract.lean` cover this tool, and
  `Test/Spec.lean` covers the `@[specifies]` attribute — the annotations it records, read back out
  of the environment, and each rejection pinned with `#guard_msgs`, since those messages are the
  attribute's entire user interface.

## CI: Prebuilt Binaries

The `Publish Exposition Binary` workflow runs on pushes to `master`, on tags, and on manual dispatches. It builds the Linux `x86_64` binary, then calls `scripts/package-exposition-binary.sh` to produce a versioned archive under `dist/`:

- `exposition-linux-x86_64-<sha>.tar.gz` — the binary, `lean-toolchain`, and `metadata.json`
- `exposition-linux-x86_64-<sha>.metadata.json` — standalone copy of the metadata
- `SHA256SUMS` — checksums for the two files above

The archive is uploaded as a GitHub Actions artifact named `exposition-linux-x86_64-<sha>` with a 90-day retention. On tag builds, the same files are attached to the corresponding GitHub release (creating it if it doesn't exist).

Downstream CI can download a matching artifact with `gh`:

```bash
SOURCE_SHA=<commit>
REPO=<owner>/lml-exposition
RUN_ID=$(gh run list \
  -R "$REPO" \
  --workflow "Publish Exposition Binary" \
  --event push \
  --commit "$SOURCE_SHA" \
  --status success \
  --json databaseId \
  --jq '.[0].databaseId')
gh run download "$RUN_ID" -R "$REPO" \
  -n "exposition-linux-x86_64-$SOURCE_SHA" \
  -D ./exposition-artifact
tar -xzf "./exposition-artifact/exposition-linux-x86_64-$SOURCE_SHA/exposition-linux-x86_64-$SOURCE_SHA.tar.gz" \
  -C ./exposition-artifact
```
