# LMLExposition

`LMLExposition` is a Lean 4 executable that walks a compiled project's environment and emits a Verso `Manual` site for mathematician-facing exposition. It is a fork of [LeanExposition](https://github.com/mattrobball/lean-exposition/) by Matthew Ballard.

Features:

- programmatic `Part Manual` generation from declarations in a compiled environment
- grouping by the first path component after the root module, with chapter/module order derived from the import graph
- declaration cards with docstrings, source-first Lean statements, collapsible `Uses` / `Used by`, and collapsible proof bodies
- a per-declaration dependency graph, laid out in rows by dependency depth (top row depends on
  nothing) and transitively reduced. There is deliberately no whole-project graph: one picture of
  every declaration is unreadable at any zoom and answers no question a reader has
- a claims page (results nothing else in the library uses) and a trust page (`sorry` chains, axioms)
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
- `LMLExposition/Collect.lean` — walks the environment and builds one `DeclInfo` per exposed
  declaration (signature, docstring, source snippet, kind), delegating all dependency computation to
  `LeanDeps` and deciding only which edges the exposition follows (`graphDeps`: type-only for
  theorems). `sorry` status is a single transitive flag (`dependsOnSorry`) obtained from
  `Lean.collectAxioms`, i.e. the same answer `#print axioms` gives.
- `LMLExposition/Extract.lean` — the standalone `.lean` file extraction (see `KNOWN-ISSUES.md`).
- `LMLExposition/Highlight.lean` — source-text highlighting. Runs the Lean frontend over a file and
  returns SubVerso `Highlighted` per command, tagged with the names each command defines, plus any
  elaboration errors. Depends on Lean and SubVerso only — it knows nothing about the site.
- `LMLExposition/Website/Site.lean` — Verso page construction and the CLI subcommands. The site's
  CSS and JavaScript live in `LMLExposition/Website/assets/` as real files and are embedded with
  `include_str`. D3 is vendored there too rather than fetched from a CDN at page load.

## What The Tool Assumes About Your Library

Almost everything the site shows is derived: dependencies, closures, `sorry` chains, axioms,
compile status. One thing is not, and it is worth knowing before you point the tool at a project.

**The Claims page lists the declarations you wrote with `theorem`, not `lemma`.** It takes the
usual convention at face value — `theorem` for a result worth stating for its own sake, `lemma`
for a step towards one — because Lean records both as the same kind and nothing else in the
environment distinguishes them.

So the choice between the two keywords is the one piece of editorial intent the tool cannot infer,
and the only thing you have to do deliberately to get a useful Claims page. `LeanMachineLearning`
states 11 of its 698 declarations as theorems, and they are exactly the point of the library — the
regret bounds. A project that writes `theorem` everywhere gets a Claims page meaning "all results":
still true, just less useful. Nothing else on the site depends on the distinction.

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
  covers `LeanDeps`, `Test/Collect.lean` and `Test/Extract.lean` cover this tool.

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
