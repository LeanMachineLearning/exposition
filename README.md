# LMLExposition

`LMLExposition` is a Lean 4 executable that walks a compiled project's environment and emits a Verso `Manual` site for mathematician-facing exposition. It is a fork of [LeanExposition](https://github.com/mattrobball/lean-exposition/) by Matthew Ballard.

Features:

- programmatic `Part Manual` generation from declarations in a compiled environment
- grouping by the first path component after the root module, with chapter/module order derived from the import graph
- declaration cards with docstrings, source-first Lean statements, collapsible `Uses` / `Used by`, and collapsible proof bodies
- dependency graph page backed by inline JSON + D3, with chapter filtering and neighborhood focus
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

The tool has four subcommands: `collect`, `extract`, `build-site`, and `all`. `collect`
imports the target project and writes its analysis (declarations, dependency graph,
docstrings, ...) to a JSON file; `extract` and `build-site` both read that JSON instead of
redoing the analysis. Only `collect` and `extract` need to run inside the target project's
`lake env` (they need its compiled `.olean`s); `build-site` only ever touches the JSON file
and can be re-run as many times as you like — e.g. while iterating on page layout or CSS —
without re-importing the target project.

```bash
cd /path/to/target-repo
lake exe cache get
lake build MyLibrary

EXPOSITION=/path/to/lml-exposition/.lake/build/bin/exposition

lake env "$EXPOSITION" collect --root MyLibrary --data data.json

lake env "$EXPOSITION" extract --data data.json --output /path/to/site-out

"$EXPOSITION" build-site --data data.json --output /path/to/site-out \
  --repo-url https://github.com/owner/repo \
  --site-url https://owner.github.io/repo
```

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
