# Prebuilt binaries

The `Publish Referee Binary` workflow runs on pushes to `main`, on tags, and on manual dispatches.
It builds the Linux `x86_64` binary, then calls `scripts/package-referee-binary.sh` to produce a
versioned archive under `dist/`:

- `referee-linux-x86_64-<sha>.tar.gz` — the binary, `lean-toolchain`, and `metadata.json`
- `referee-linux-x86_64-<sha>.metadata.json` — standalone copy of the metadata
- `SHA256SUMS` — checksums for the two files above

The archive is uploaded as a GitHub Actions artifact named `referee-linux-x86_64-<sha>` with a
90-day retention. On tag builds, the same files are attached to the corresponding GitHub release
(creating it if it doesn't exist).

## Consuming the binary downstream

**Prefer a release over a run artifact.** Release assets of a public repository need no
authentication and never expire; run artifacts need both a token and luck:

- a cross-repository artifact download requires a PAT with `actions:read` on *this* repository. A
  workflow's own `GITHUB_TOKEN` is scoped to the repository it runs in, so it cannot reach another
  repository's artifacts even when that repository is public;
- artifacts are deleted after the 90-day retention above, so a pinned commit stops resolving.

So the supported route is a tag:

```bash
gh release download v0.1.0 -R LeanMachineLearning/exposition \
  --pattern 'referee-linux-x86_64-*.tar.gz' --dir ./referee-artifact
tar -xzf ./referee-artifact/referee-linux-x86_64-*.tar.gz -C ./referee-artifact
REFEREE=$(echo ./referee-artifact/referee-linux-x86_64-*/referee)
```

Omitting the tag takes the most recent release.

**Check the toolchain before running it.** `referee` is a Lean executable built with
`supportInterpreter := true`, so it loads the shared library of the toolchain it was compiled
against and must match the target project's. The archive carries `metadata.json` for exactly this
check, and it is worth making a hard failure rather than debugging the symbol errors it prevents:

```bash
want=$(tr -d '[:space:]' < lean-toolchain)
got=$(jq -r .lean_toolchain ./referee-artifact/referee-linux-x86_64-*/metadata.json)
[ "$want" = "$got" ] || { echo "referee built for $got, project uses $want" >&2; exit 1; }
```

If you do reach for a run artifact anyway, note that `gh run download` extracts a *single* named
artifact directly into `-D`, without a directory named after it — so the archive is at
`./referee-artifact/referee-linux-x86_64-<sha>.tar.gz`, one level up from where you might expect.

`alpha-rar`'s [`blueprint.yml`](https://github.com/RemyDegenne/alpha-rar/blob/main/.github/workflows/blueprint.yml)
is a worked example: download, toolchain check, five phases (`collect`, `provenance`, `extract`,
`highlight`, `build-site`), and a `--baseline` taken from the previous run's artifact.
