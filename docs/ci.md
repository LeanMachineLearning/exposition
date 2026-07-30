# Running Referee in CI

Building the site by hand is fine once. Running it on every push is where it starts being useful —
and where three of its features first become possible at all, because a revision diff needs an
earlier build to compare against and a provenance ledger needs a run per revision to accumulate.

This page is the shape of that job and the reasoning behind the parts that are not obvious.
`alpha-rar`'s [`blueprint.yml`](https://github.com/RemyDegenne/alpha-rar/blob/main/.github/workflows/blueprint.yml)
is the worked example every snippet here is taken from; it also builds a blueprint and deploys to
Pages, which this page ignores.

## The minimum

Enough for a complete site, with none of the features that need state carried between runs:

Action versions are written loosely here for readability; pin them to a commit SHA in a real
workflow, as the worked example does.

```yaml
- uses: actions/checkout@v7
- uses: leanprover/lean-action@v1   # build the project however you already do
  with: { build: true }

- name: Download referee
  env: { GH_TOKEN: "${{ secrets.GITHUB_TOKEN }}" }
  run: |
    set -euo pipefail
    gh release download -R LeanMachineLearning/exposition \
      --pattern 'referee-linux-x86_64-*.tar.gz' --dir /tmp/referee
    tar -xzf /tmp/referee/referee-linux-x86_64-*.tar.gz -C /tmp/referee
    bin=$(echo /tmp/referee/referee-linux-x86_64-*/referee)
    chmod +x "$bin"; echo "REFEREE_BIN=$bin" >> "$GITHUB_ENV"

    # A hard failure here beats a link error four steps later that names no cause.
    want=$(tr -d '[:space:]' < lean-toolchain)
    got=$(jq -r .lean_toolchain "$(dirname "$bin")/metadata.json" | tr -d '[:space:]')
    [ "$want" = "$got" ] || { echo "::error::referee built for $got, project uses $want"; exit 1; }

- name: Build the site
  run: |
    set -euo pipefail
    lake env "$REFEREE_BIN" collect --root MyLibrary --data /tmp/referee-data.json
    lake env "$REFEREE_BIN" extract --data /tmp/referee-data.json --output ./referee-site
    "$REFEREE_BIN" build-site --data /tmp/referee-data.json --output ./referee-site \
      --repo-url "https://github.com/$GITHUB_REPOSITORY" \
      --site-url https://owner.github.io/repo
```

Take a **release**, not a run artifact: release assets of a public repository need no authentication
and never expire, while a cross-repository artifact download needs a PAT with `actions:read` and is
deleted after 90 days. See [prebuilt binaries](releases.md). Pin `REFEREE_VERSION` to a tag once
anyone is reading the output, so the site generator stops moving under it.

**Write the generated data outside the working tree.** `/tmp`, not `./`. `provenance` records
whether the tree was clean when it folded, and `git status --porcelain` counts untracked files — so
a stray `data.json` in the repository permanently stamps the ledger as built from a dirty tree and
makes the site disclaim its own blame.

## Adding the interesting parts

Each is independent; add them in any order, or not at all.

### Semantic hashes

Build [`semantic_hash`](semantic-hashes.md) in the job. It cannot be downloaded and cannot be a Lake
dependency: it loads your project's environment and refuses to run unless its own sysroot matches,
so it has to be compiled against *your* toolchain rather than the one it pins. Overwriting the pin
is the whole patch, and it has no dependencies beyond core, so this costs a minute or two on a
runner that already has the toolchain.

```yaml
- name: Build semantic_hash
  run: |
    set -euo pipefail
    git clone --depth 1 https://github.com/mathlib-initiative/semantic_hash /tmp/semantic_hash
    cp lean-toolchain /tmp/semantic_hash/lean-toolchain
    cd /tmp/semantic_hash && lake build semantic_hash

- name: Export hashes
  run: |
    /tmp/semantic_hash/.lake/build/bin/semantic_hash export \
      --dir . --imports MyLibrary --output /tmp/hashes.jsonl
```

then `collect --hashes /tmp/hashes.jsonl`. Pin the clone to a tag once the ledger matters: a change
in *how* it hashes reads as every declaration changing meaning at once.

### The revision diff

`--baseline` needs the previous run's `data.json`, so upload it and fetch it back:

```yaml
- name: Fetch the previous build's data
  continue-on-error: true
  env: { GH_TOKEN: "${{ secrets.GITHUB_TOKEN }}" }
  run: |
    set -euo pipefail
    run_id=$(gh run list -R "$GITHUB_REPOSITORY" --workflow "${{ github.workflow }}" \
      --branch "${{ github.ref_name }}" --status success --limit 1 \
      --json databaseId --jq '.[0].databaseId // empty')
    [ -n "$run_id" ] || { echo "no earlier run; skipping the baseline"; exit 0; }
    gh run download "$run_id" -R "$GITHUB_REPOSITORY" -n referee-data -D /tmp/baseline
    found=$(find /tmp/baseline -name '*.json' | head -1)
    [ -n "$found" ] && echo "REFEREE_BASELINE=$found" >> "$GITHUB_ENV"

# …and at the end of the job:
- uses: actions/upload-artifact@v4
  with: { name: referee-data, path: /tmp/referee-data.json, retention-days: 90 }
```

Optional in every direction — the first run has nothing to fetch, a failed lookup is swallowed, and
`build-site` simply omits the Changes page when no baseline reaches it. Pass it as
`${baseline:+--baseline "$baseline"}` so an empty value drops the flag rather than passing an empty
one.

**Guard the format version.** `build-site` treats a collected-data version mismatch as fatal, by
design: it reports what to do instead of surfacing whichever field happened to change. In CI that
would fail the deployment over a stale artifact, so compare and drop the baseline instead —

```bash
if [ -n "$baseline" ] &&
   [ "$(jq -r .version "$baseline")" != "$(jq -r .version "$REFEREE_DATA")" ]; then
  echo "::notice::baseline is an older collected-data version; skipping the revision diff"
  baseline=""
fi
```

— one run without a Changes page, and the next has one again.

### The provenance ledger

The ledger is the one part of the pipeline that has to *survive* the run that wrote it: it is
append-only and its whole value is remembering years of history, which a 90-day artifact cannot
hold. So it lives in the repository — but **not on the branch you are building**.

**Keep the ledger on a branch of its own.** A protected default branch is the normal case, not the
exception: "changes must be made through a pull request" makes `GITHUB_TOKEN` unable to push, and
under classic branch protection there is no bypass list an app can be added to. A dedicated
unprotected branch — `referee-ledger` below — sidesteps the question entirely and needs no repository
settings changed, no personal access token, and no reviewer looking at a machine-written JSON file.

It never merges into anything. It holds one file and exists only so the next run can find it.

**`fetch-depth: 0` on checkout.** Load-bearing, not a convenience: the ledger's edit half is
`git blame`, and at the default depth of 1 blame attributes the entire library to the single fetched
commit.

```yaml
- uses: actions/checkout@v7
  with: { fetch-depth: 0 }
```

**Fetch the ledger into a clone of its own, outside the working tree**, before `provenance` runs:

```yaml
env:
  LEDGER_BRANCH: referee-ledger
  LEDGER_DIR: /tmp/ledger
  REFEREE_PROVENANCE: /tmp/referee-data/provenance.json

- name: Fetch the provenance ledger
  env: { LEDGER_TOKEN: "${{ secrets.GITHUB_TOKEN }}" }
  run: |
    set -euo pipefail
    # A separate clone, not a fetch into the project's repository: an orphan branch fetched at
    # --depth 1 would leave a shallow boundary behind, and `git blame` over the whole history is
    # the other half of what `provenance` does. A missing branch is the ordinary first run.
    mkdir -p "$(dirname "$REFEREE_PROVENANCE")"; rm -rf "$LEDGER_DIR"
    remote="https://x-access-token:${LEDGER_TOKEN}@github.com/$GITHUB_REPOSITORY"
    if git clone -q --depth 1 --branch "$LEDGER_BRANCH" "$remote" "$LEDGER_DIR" 2>/dev/null &&
       [ -f "$LEDGER_DIR/provenance.json" ]; then
      cp "$LEDGER_DIR/provenance.json" "$REFEREE_PROVENANCE"
    else
      echo "no ledger on $LEDGER_BRANCH yet; this run starts one"
    fi
```

then `provenance --provenance "$REFEREE_PROVENANCE"`, and afterwards:

```yaml
- name: Publish the provenance ledger
  env: { LEDGER_TOKEN: "${{ secrets.GITHUB_TOKEN }}" }
  run: |
    set -euo pipefail
    remote="https://x-access-token:${LEDGER_TOKEN}@github.com/$GITHUB_REPOSITORY"
    if [ ! -d "$LEDGER_DIR/.git" ]; then
      mkdir -p "$LEDGER_DIR"
      git -C "$LEDGER_DIR" init -q -b "$LEDGER_BRANCH"
      git -C "$LEDGER_DIR" remote add origin "$remote"
    fi
    cd "$LEDGER_DIR"
    git config user.name "github-actions[bot]"
    git config user.email "41898282+github-actions[bot]@users.noreply.github.com"
    # The tip as fetched, remembered before committing on top of it: the shallow clone has no
    # parent to ask for afterwards, and this is what tells a lost race from a rejected push below.
    base=$(git rev-parse HEAD 2>/dev/null || echo none)
    cp "$REFEREE_PROVENANCE" provenance.json
    git add provenance.json
    if [ "$base" != none ] && git diff --cached --quiet; then
      echo "already folded at this commit"; exit 0
    fi
    git commit -q -m "fold ${GITHUB_SHA:0:7} into the provenance ledger"
    if git push -q origin "HEAD:$LEDGER_BRANCH"; then exit 0; fi
    # Two very different failures, which the old recipe reported alike. A concurrent run that got
    # there first is transient and costs one revision of resolution; anything else is a
    # misconfiguration that will never fix itself, and warning about it every run for months is how
    # a ledger silently stays one revision long forever.
    if git fetch -q origin "$LEDGER_BRANCH" 2>/dev/null &&
       [ "$base" != "$(git rev-parse FETCH_HEAD)" ]; then
      echo "::warning::the ledger branch moved under this run; the next run folds both revisions"
    else
      echo "::error::could not push the ledger to $LEDGER_BRANCH. Check that the branch is not \
        protected and that the job has contents: write."
      exit 1
    fi
```

Push with `GITHUB_TOKEN`, which by design does not trigger another workflow run, so this cannot
loop. Note `if git push …; then exit 0; fi` rather than `git push … && exit 0`: under `set -e` the
second form takes the whole step down on the failure it was meant to handle.

Run `provenance` **after** `collect` and **before** `extract`/`highlight`, so the cleanliness it
records is the repository's rather than this job's leftovers. It needs `contents: write` in the
job's `permissions`.

**Never let the ledger sit in the working tree.** The same trap as `data.json` above, and worse
here: an untracked `provenance.json` in the repository root makes `git status --porcelain` report
the tree as dirty, which stamps every fold as built from a revision nobody can check out and makes
the site fall back to `blob/main` source links. `/tmp`, always.

#### Migrating a ledger that is already committed

If an earlier setup committed `provenance.json` to the default branch, move it across once — the
file is the history, so nothing is lost:

```bash
git switch --orphan referee-ledger
git add provenance.json
git commit -m "seed the provenance ledger"
git push -u origin referee-ledger
git switch main
git rm provenance.json && git commit -m "move the provenance ledger to its own branch"
```

The last two lines are the only part that touches the protected branch, and they go through the
normal review path like any other change.

It also hard-fails rather than degrading if the data carries no hashes, which is deliberate — see
[provenance](provenance.md). A failure there means the hash export missed declarations `collect`
exposes, which is worth stopping for.

## Cost, and what to leave out

**Skip `highlight-extracted`.** It re-elaborates every extracted file — one Lean process per
declaration, each importing Mathlib — and costs more than the rest of the job combined. Without it
the standalone files are still written and linked, just not rendered inline. `highlight` alone, one
process per module, is the good trade.

**Set `--jobs` explicitly rather than inheriting the default.** Both highlighting phases fan out one
worker per CPU, and each worker imports Mathlib into its own multi-gigabyte process. A GitHub-hosted
runner is small enough that the default is usually survivable — but that is the runner's smallness
protecting you, not a bound the tool applies. On a bigger self-hosted runner the same default
exhausts memory: on a 32-core workstation it is enough to take the machine down. Size it against
available RAM, not against cores.

**A `push`-only guard is worth having** (`if: github.event_name == 'push'`) so pull requests still
build and lint the project without paying for a site nobody will read, and without a PR folding a
revision that may never be merged.

## Ordering

```
checkout (fetch-depth: 0) → build → download referee (+ toolchain check)
  → build semantic_hash → export hashes
  → collect → fetch ledger → provenance → publish ledger
  → fetch previous data → extract → highlight → build-site
  → upload data → deploy
```

`collect` and the two highlighting phases need `lake env`; `provenance` needs a git tree but no Lean
environment; `build-site` needs neither. That split is what lets the last step be re-run against the
same `data.json` with different flags, in CI or on your laptop, without re-importing the project.
