#!/usr/bin/env bash
# Resolves the paths the rest of the pipeline works in, and makes the checkout fit to be measured.
#
# Two things here are load-bearing and neither is obvious:
#
#   * The generated data goes *outside* the working tree. `provenance` records whether the tree was
#     clean when it folded, via `git status --porcelain`, which counts untracked files — so a
#     `data.json` left in the repository permanently stamps the ledger as built from a dirty tree
#     and makes the site disclaim its own blame. `$RUNNER_TEMP` rather than `/tmp` because the
#     runner cleans it between jobs and it is on the same filesystem as the workspace.
#
#   * A shallow checkout is unshallowed rather than rejected. The ledger's edit half is `git blame`,
#     and at `fetch-depth: 1` blame attributes the entire library to the single fetched commit.
#     That failure is silent — the site renders, every declaration just claims to have been written
#     in one commit — which makes it far worse than a hard error, and it is the single most common
#     way to misconfigure this pipeline.
set -euo pipefail

# shellcheck source=ci/common.sh
. "$(dirname "${BASH_SOURCE[0]}")/common.sh"

# The action's inputs arrive here as environment variables and are re-exported into the job
# environment, so that every later step inherits the whole contract instead of repeating a dozen
# `env:` blocks. `REFEREE_TOKEN` is pointedly *not* among them: it is passed per-step to the three
# scripts that need it, so that a caller who supplies a personal access token does not have it
# sitting in the environment of every subsequent step of their own job.
for var in REFEREE_ROOT REFEREE_EXCLUDE_LIB REFEREE_SITE_URL REFEREE_REPO_URL REFEREE_TITLE \
           REFEREE_TRUST REFEREE_OUTPUT_DIR REFEREE_SITE_DEST REFEREE_ARTIFACT_NAME \
           REFEREE_LEDGER_BRANCH REFEREE_REVISION_REF REFEREE_BASELINE_LABEL REFEREE_JOBS \
           REFEREE_WITH_HASHES REFEREE_WITH_PROVENANCE REFEREE_WITH_BASELINE \
           REFEREE_WITH_HIGHLIGHT_EXTRACTED REFEREE_PER_CHAPTER \
           REFEREE_SEMANTIC_HASH_REPO REFEREE_SEMANTIC_HASH_REF; do
  referee_export "$var" "${!var-}"
done

data_dir="${RUNNER_TEMP:-/tmp}/referee-data"
mkdir -p "$data_dir"

referee_export REFEREE_DATA_DIR "$data_dir"
referee_export REFEREE_DATA "$data_dir/referee-data.json"
referee_export REFEREE_HASHES "$data_dir/hashes.jsonl"
referee_export REFEREE_PROVENANCE "$data_dir/provenance.json"
referee_export REFEREE_LEDGER_DIR "${RUNNER_TEMP:-/tmp}/referee-ledger"

referee_output data "$data_dir/referee-data.json"
referee_output provenance "$data_dir/provenance.json"
referee_output site "${REFEREE_OUTPUT_DIR:-referee-site}/html-multi"

if referee_enabled "${REFEREE_WITH_PROVENANCE:-}"; then
  if [ "$(git rev-parse --is-shallow-repository 2>/dev/null || echo false)" = true ]; then
    referee_info "checkout is shallow; unshallowing so \`git blame\` can see real history"
    # `--unshallow` errors on a complete repository, hence the guard above. If it fails here the
    # ledger would still be *written*, just wrong in a way nobody would notice for months, so this
    # is worth stopping for rather than warning about.
    git fetch --quiet --unshallow ||
      referee_die "could not unshallow the checkout. Set \`fetch-depth: 0\` on actions/checkout: \
\`git blame\` needs full history, and without it every declaration is attributed to one commit."
  fi
  # Tags are what `git describe --tags --always` names a revision by, and actions/checkout skips
  # them even at fetch-depth: 0. Without this every revision in the ledger is a bare short sha.
  git fetch --quiet --tags --force 2>/dev/null || referee_warn "could not fetch tags; ledger revisions will be named by short sha"
fi
