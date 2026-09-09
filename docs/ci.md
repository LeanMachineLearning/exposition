# Running Referee in CI

Building the site by hand is fine once. Running it on every push is where it starts being useful —
and where three of its features first become possible at all, because a revision diff needs an
earlier build to compare against and a provenance ledger needs a run per revision to accumulate.

## The action

```yaml
permissions:
  contents: write   # push the ledger branch
  actions: read     # read the previous run's data, for the revision diff

steps:
  - uses: actions/checkout@v7
  - uses: leanprover/lean-action@v1     # build the project however you already do
    with: { build: true }

  - uses: LeanMachineLearning/exposition@v4.34.0-rc2-5
    with:
      root: MyLibrary
      site-url: https://owner.github.io/repo
```

That is a complete site with every feature on: semantic hashes, the provenance ledger, and a
revision diff against the previous run. Every input is listed in
[`action.yml`](../action.yml); the ones worth knowing about up front:

| input | |
|---|---|
| `root` | Root module prefix to expose. Required |
| `site-url` | Where the site will be published. Required, and must be the *real* URL — it is what the web-editor links are built from |
| `exclude-lib` | Root libraries to skip when importing. Comma- or newline-separated |
| `trust` | Packages to vouch for, along with everything they depend on. See [upstream trust](trust.md) |
| `output` | Where Referee writes. The site itself lands in `<output>/html-multi` |
| `site-dest` | If set, the built site is copied here — for dropping it into a Pages tree without writing the `cp` |
| `version` | Which referee release to use. Defaults to the ref the action itself was pinned at |

The action ships from `v4.34.0-rc2-5` onward; before that, this pipeline had to be written out by
hand in each consuming workflow.

Pin the action to a tag. The binary follows it by default, so `@v4.34.0-rc2-5` gets the referee
built from that tag without naming the version twice, and the site generator stops moving under a site anyone is
reading. A moving ref like `@main` is not a release, so it resolves to the newest one instead —
and note that "newest" here means the most recently pushed tag of *any* kind, since
[`publish_referee_binary.yml`](../.github/workflows/publish_referee_binary.yml) cuts a release on
`tags: "*"`. That is reason enough to pin.

### What the action cannot do for you

Two things are the caller's, because a composite action runs inside your job and cannot rewrite it:

**`permissions:`.** `contents: write` for the ledger branch, `actions: read` for the revision diff.
Without them those two features fail — loudly for the ledger, quietly for the diff, which is
deliberate in both cases and explained below.

**When to run.** A `push`-only guard is worth having, so pull requests still build and lint the
project without paying for a site nobody will read, and without a PR folding a revision that may
never be merged:

```yaml
  - uses: LeanMachineLearning/exposition@v4.34.0-rc2-5
    if: github.event_name == 'push'
```

`fetch-depth: 0` used to be a third. It no longer is: the action unshallows the checkout itself when
it is going to fold a ledger. That mattered enough to automate — the ledger's edit half is
`git blame`, and at the default depth of 1 blame attributes the entire library to the single fetched
commit, which renders a perfectly good-looking site in which every declaration claims to have been
written in one commit.

### Deploying it

The site is a directory of static HTML; nothing about publishing it is Referee's business. Into a
Pages tree alongside other documentation:

```yaml
  - uses: LeanMachineLearning/exposition@v4.34.0-rc2-5
    if: github.event_name == 'push'
    with:
      root: MyLibrary
      site-url: https://owner.github.io/repo/exposition
      trust: mathlib
      site-dest: home_page/exposition

  - uses: actions/upload-pages-artifact@v5
    with: { path: home_page/ }
  - uses: actions/deploy-pages@v5
```

Or take the path from the action's `site` output and do what you like with it.

## Why it does what it does

Nothing below is required reading to use the action. It is the reasoning the action encodes, which
matters when something goes wrong, when you are turning a feature off, or when you are running the
pipeline somewhere that is not GitHub Actions.

### A release, not a run artifact

Release assets of a public repository need no authentication and never expire. A cross-repository
artifact download needs a PAT with `actions:read` — a workflow's own `GITHUB_TOKEN` is scoped to its
own repository and cannot reach another's, even a public one — and is deleted after 90 days, so a
pinned commit stops resolving. See [prebuilt binaries](releases.md).

The toolchain is checked against the project's before anything else runs. `referee` is a Lean
executable built with `supportInterpreter := true`, so it loads the shared library of the toolchain
it was compiled against and has to match. This cannot be checked by the binary itself: the mismatch
is a dynamic-link failure that happens before `main` runs, which is why it is worth a hard failure
with a cause attached rather than the symbol errors it prevents.

### Generated data lives outside the working tree

`/tmp`, not `./`. `provenance` records whether the tree was clean when it folded, via
`git status --porcelain`, which counts untracked files — so a stray `data.json` in the repository
permanently stamps the ledger as built from a dirty tree and makes the site disclaim its own blame.
The action writes to `$RUNNER_TEMP` for this reason, and the same trap applies twice as hard to the
ledger itself.

### Semantic hashes

[`semantic_hash`](semantic-hashes.md) supplies the rename-invariant hashes the ledger and the
revision diff are keyed on. It cannot be downloaded and cannot be a Lake dependency: it loads your
project's environment and refuses to run unless its own sysroot matches, so it has to be compiled
against *your* toolchain rather than the one it pins. Overwriting the pin is the whole patch, and it
has no dependencies beyond core, so it costs a minute or two on a runner that already has the
toolchain.

Set `semantic-hash-ref` to pin it once the ledger matters: a change in *how* it hashes reads as every
declaration changing meaning at once.

### The provenance ledger

The ledger is the one part of the pipeline that has to *survive* the run that wrote it: it is
append-only and its whole value is remembering years of history, which a 90-day artifact cannot
hold. So it lives in the repository — but **not on the branch you are building**.

**On a branch of its own** (`ledger-branch`, default `referee-ledger`). A protected default branch
is the normal case, not the exception: "changes must be made through a pull request" makes
`GITHUB_TOKEN` unable to push, and under classic branch protection there is no bypass list an app
can be added to. A dedicated unprotected branch sidesteps the question entirely and needs no
repository settings changed, no personal access token, and no reviewer looking at a machine-written
JSON file. It never merges into anything. It holds one file and exists only so the next run can find
it.

It is fetched into a clone of its own rather than into the project's checkout: an orphan branch
fetched at `--depth 1` leaves a shallow boundary behind, and `git blame` over the whole history is
the other half of what `provenance` does.

The fold runs after `collect` and before `extract`, so the cleanliness it records is the
repository's and not the job's leftovers. It hard-fails rather than degrading if the data carries no
hashes, which is deliberate — see [provenance](provenance.md). A failure there means the hash export
missed declarations `collect` exposes, which is worth stopping for.

Publishing distinguishes two failures that one warning used to cover alike. A concurrent run that
got there first is transient: the fold is idempotent per commit, so the next run folds this revision
together with the following one and nothing is lost but resolution. Anything else — a protected
ledger branch, a missing `contents: write` — will never fix itself, and warning about it every run is
how a ledger silently stays one revision long forever. The first is a warning; the second fails the
job.

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

### The revision diff

The previous run's collected data, downloaded from its artifact, so the site can say what changed
since it. Optional in every direction: the first run has nothing to download, a failed lookup is
swallowed, and `build-site` simply omits the Changes page when no baseline reaches it.

That tolerance is enforced inside the action rather than by a `continue-on-error:` on the step,
because composite-action steps do not support it. Losing one Changes page beats failing a
deployment, which is also why a baseline written by an older `collect` is dropped with a notice
rather than passed: `build-site` treats a collected-data version mismatch as fatal by design, and in
CI that would fail the deployment over a stale artifact. One run without a Changes page, and the
next has one again.

Complementary to the ledger rather than replaced by it — the ledger says *when* a declaration last
changed, the baseline shows the two statements side by side.

### Cost, and what to leave out

**`highlight-extracted` is off by default.** It elaborates every extracted file — one Lean process
per declaration, each importing Mathlib — and costs more than the rest of the job combined. Without
it the standalone files are still written and linked, just not rendered inline as interactive Lean.

**Set `jobs` explicitly if you turn it on.** The phase fans out one worker per CPU, and each worker
imports Mathlib into its own multi-gigabyte process. A GitHub-hosted runner is small enough that the
default is usually survivable — but that is the runner's smallness protecting you, not a bound the
tool applies. On a bigger self-hosted runner the same default exhausts memory: on a 32-core
workstation it is enough to take the machine down. Size it against available RAM, not against cores.

## Without the action

The action is a thin wrapper over the scripts in [`ci/`](../ci), which take their configuration from
a `REFEREE_*` environment contract and have no dependency on GitHub Actions beyond `gh` and the
runner's temp directory. On another CI system, or on a laptop, run them directly:

```bash
export REFEREE_ROOT=MyLibrary
export REFEREE_SITE_URL=https://owner.github.io/repo
export REFEREE_DATA=/tmp/referee-data/referee-data.json
export REFEREE_BIN=/path/to/referee
export REFEREE_OUTPUT_DIR=./referee-site
ci/collect.sh && ci/render.sh
```

`ci/tests/run-tests.sh` exercises all of them with `gh`, `lake` and `referee` faked out, and is the
best place to see what each expects. The phase ordering is:

```
checkout (full history) → build → download referee (+ toolchain check)
  → build semantic_hash → export hashes
  → collect → fetch ledger → provenance → publish ledger
  → fetch previous data → extract → [highlight-extracted] → build-site
  → upload data → deploy
```

`collect` and `extract` need `lake env`; `provenance` needs a git tree but no Lean environment;
`build-site` needs neither. That split is what lets the last step be re-run against the same
`data.json` with different flags, in CI or on your laptop, without re-importing the project.
