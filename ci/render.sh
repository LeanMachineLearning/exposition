#!/usr/bin/env bash
# `extract` → (`highlight-extracted`) → `build-site`: everything downstream of the collected data.
#
# `--exclude-lib` goes only to `extract`, the one phase here that imports the project wholesale;
# `build-site` reads the JSON alone and needs no Lean environment, which is what lets it be re-run
# against the same data with different flags, in CI or on a laptop, without re-importing anything.
set -euo pipefail

# shellcheck source=ci/common.sh
. "$(dirname "${BASH_SOURCE[0]}")/common.sh"

bin="$(referee_require REFEREE_BIN)"
data="$(referee_require REFEREE_DATA)"
out="${REFEREE_OUTPUT_DIR:-referee-site}"

exclude=()
trust=()
referee_split_list exclude --exclude-lib "${REFEREE_EXCLUDE_LIB:-}"
referee_split_list trust --trust "${REFEREE_TRUST:-}"

lake env "$bin" extract --data "$data" "${exclude[@]}" --output "$out"

# Off by default, and worth keeping off: it elaborates every extracted file — one Lean process per
# declaration, each importing Mathlib — and costs more than the rest of the job combined. Without it
# the standalone files are still written and linked, just not rendered inline as interactive Lean.
#
# `--jobs` deserves care when it is on. The phase fans out one worker per CPU by default and each
# worker imports Mathlib into its own multi-gigabyte process; size it against available RAM, not
# against cores. A GitHub-hosted runner is usually small enough that the default survives, but that
# is the runner's smallness protecting you, not a bound the tool applies.
if referee_enabled "${REFEREE_WITH_HIGHLIGHT_EXTRACTED:-}"; then
  jobs=()
  [ -z "${REFEREE_JOBS:-}" ] || jobs=(--jobs "$REFEREE_JOBS")
  lake env "$bin" highlight-extracted --data "$data" "${jobs[@]}" --output "$out"
fi

# A baseline written by an older `collect` is rejected outright: the data file carries a format
# version and `build-site` treats a mismatch as fatal rather than as something to degrade around,
# which is right for a hand-run and wrong here, where it would fail a deployment over a stale
# artifact. Dropped instead — one run without a Changes page, and the next has one again.
baseline="${REFEREE_BASELINE:-}"
if [ -n "$baseline" ] &&
   [ "$(jq -r .version "$baseline")" != "$(jq -r .version "$data")" ]; then
  referee_notice "baseline is collected-data version $(jq -r .version "$baseline") but this build \
writes $(jq -r .version "$data"); skipping the revision diff"
  baseline=""
fi

# `--provenance` is read-only here: `build-site` never folds. It adds the "meaning unchanged since"
# line, the Browse column, the revision selector on the Changes page, and pins every source link to
# the commit the ledger was folded at instead of to the default branch.
provenance=()
if referee_enabled "${REFEREE_WITH_PROVENANCE:-}" && [ -f "${REFEREE_PROVENANCE:-}" ]; then
  provenance=(--provenance "$REFEREE_PROVENANCE")
fi

# An array rather than `${baseline:+--baseline "$baseline"}`: the unquoted form relies on word
# splitting and loses a path containing a space.
baseline_flags=()
[ -z "$baseline" ] ||
  baseline_flags=(--baseline "$baseline" --baseline-label "${REFEREE_BASELINE_LABEL:-the previous build}")

per_chapter=()
! referee_enabled "${REFEREE_PER_CHAPTER:-}" || per_chapter=(--per-chapter)
title=()
[ -z "${REFEREE_TITLE:-}" ] || title=(--title "$REFEREE_TITLE")

# `--trust` is an editorial claim, not a derived fact: it says whoever publishes this site vouches
# for the named package and everything under it. Name none and every upstream package counts as
# unaudited.
"$bin" build-site \
  --data "$data" \
  --output "$out" \
  --repo-url "${REFEREE_REPO_URL:-https://github.com/$GITHUB_REPOSITORY}" \
  --site-url "$(referee_require REFEREE_SITE_URL)" \
  "${title[@]}" \
  "${trust[@]}" \
  "${provenance[@]}" \
  "${per_chapter[@]}" \
  "${baseline_flags[@]}"

# The optional copy into a Pages tree. Both known consumers do exactly this and nothing else with
# the output, so it is an input rather than a step every caller writes again.
if [ -n "${REFEREE_SITE_DEST:-}" ]; then
  mkdir -p "$REFEREE_SITE_DEST"
  cp -r "$out/html-multi/." "$REFEREE_SITE_DEST/"
  referee_info "site copied to $REFEREE_SITE_DEST"
fi
