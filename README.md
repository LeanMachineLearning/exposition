# LeanExposition modification for LML

This is a modification of the LeanExposition project (https://github.com/mattrobball/lean-exposition/) by Matthew Ballard.

The original README is included below for reference.

# LeanExposition

`LeanExposition` is an alpha Lean 4 executable that walks a compiled project's
environment and emits a Verso `Manual` site for mathematician-facing exposition.

Current v1 behavior matches the design spec:

- programmatic `Part Manual` generation from declarations in a compiled environment
- grouping by the first path component after the root module, with chapter/module order derived from the import graph
- declaration cards with docstrings, source-first Lean statements, collapsible `Uses` / `Used by`, and collapsible proof bodies
- dependency graph page backed by inline JSON + D3, with chapter filtering and neighborhood focus
- multi-page HTML output through Verso's `manualMain`

## Status

This is an alpha implementation. The validated execution path is:

1. build this repo's executable
2. run that executable inside the target repo's `lake env`

The exposition tool always exposes the project of the surrounding `lake env`, i.e. the current
working directory.

## Build

```bash
cd /path/to/lean-exposition
lake update
lake build exposition
```

## Prebuilt CI Binaries

The `Publish Exposition Binary` workflow runs on pushes to `master`, on tags,
and on manual dispatches. It builds the Linux `x86_64` binary on
`ubuntu-latest`, then publishes an artifact named
`exposition-linux-x86_64-$SOURCE_SHA`.

Each published artifact contains:

- `exposition-linux-x86_64-$SOURCE_SHA.tar.gz`
- `exposition-linux-x86_64-$SOURCE_SHA.metadata.json`
- `SHA256SUMS`

The tarball expands to a directory containing the `exposition` binary,
`lean-toolchain`, and the same `metadata.json` file. On tag builds, the same
files are also attached to the corresponding GitHub release.

Downstream CI can resolve the publishing run for a particular
`lean-exposition` commit and download the matching artifact with `gh`:

```bash
SOURCE_SHA=<lean-exposition commit>
REPO=mattrobball/lean-exposition
RUN_ID=$(gh run list \
  -R "$REPO" \
  --workflow "Publish Exposition Binary" \
  --event push \
  --commit "$SOURCE_SHA" \
  --status success \
  --json databaseId \
  --jq '.[0].databaseId')
gh run download "$RUN_ID" \
  -R "$REPO" \
  -n "exposition-linux-x86_64-$SOURCE_SHA" \
  -D ./exposition-artifact
tar -xzf \
  "./exposition-artifact/exposition-linux-x86_64-$SOURCE_SHA/exposition-linux-x86_64-$SOURCE_SHA.tar.gz" \
  -C ./exposition-artifact
```

## Run Against A Target Repo

The target repo must already have current `.olean` files for the modules you
want to expose.

Example:

```bash
cd /path/to/target-repo
lake exe cache get
lake build MyLibrary
lake env /path/to/lean-exposition/.lake/build/bin/exposition \
  --root MyLibrary \
  --repo-url https://github.com/owner/repo \
  --output /path/to/site-out
```

Verso writes the site into the chosen output directory, typically under
`html-multi/`.

Optional target-specific flags:

```bash
lake env /path/to/lean-exposition/.lake/build/bin/exposition \
  --root MyLibrary \
  --exclude-lib MySpec \
  --output /path/to/site-out
```

## Options

- `--root PREFIX`: root module prefix to expose
- `--repo-url URL`: base GitHub URL used for source and issue links
- `--title TITLE`: override the site title
- `--output DIR`: output directory passed through to Verso
- `--exclude-lib NAME`: root library to skip when importing the target project

## Current Limitations

- v1 still relies on plain text code blocks and source-file snippets, not SubVerso highlighting
- undocumented declarations render without prose
- dependency links and graph edges are only emitted for exposed declarations
- issue URLs are generated from `--repo-url` and assume a standard `main` branch layout
