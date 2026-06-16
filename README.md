# LMLExposition

`LMLExposition` is a Lean 4 executable that walks a compiled project's environment and emits a Verso `Manual` site for mathematician-facing exposition. It is a fork of [LeanExposition](https://github.com/mattrobball/lean-exposition/) by Matthew Ballard.

Features:

- programmatic `Part Manual` generation from declarations in a compiled environment
- grouping by the first path component after the root module, with chapter/module order derived from the import graph
- declaration cards with docstrings, source-first Lean statements, collapsible `Uses` / `Used by`, and collapsible proof bodies
- dependency graph page backed by inline JSON + D3, with chapter filtering and neighborhood focus
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

```bash
cd /path/to/target-repo
lake exe cache get
lake build MyLibrary
lake env /path/to/lml-exposition/.lake/build/bin/exposition \
  --root MyLibrary \
  --repo-url https://github.com/owner/repo \
  --output /path/to/site-out
```

Verso writes the site into the chosen output directory, typically under `html-multi/`.

## Options

- `--root PREFIX`: root module prefix to expose
- `--repo-url URL`: base GitHub URL used for source and issue links
- `--title TITLE`: override the site title
- `--output DIR`: output directory passed through to Verso
- `--exclude-lib NAME`: root library to skip when importing the target project

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

## Current Limitations

- relies on plain text code blocks and source-file snippets, not SubVerso highlighting
- undocumented declarations render without prose
- dependency links and graph edges are only emitted for exposed declarations
- issue URLs are generated from `--repo-url` and assume a standard `main` branch layout
