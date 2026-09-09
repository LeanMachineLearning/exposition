#!/usr/bin/env bash
# Downloads the previous successful run's collected data, so the site can say what changed since it.
#
# Optional in every direction, and deliberately incapable of failing the job: the first run has
# nothing to download, a lookup can fail for reasons that have nothing to do with this project, and
# `build-site` simply omits the Changes page when no baseline reaches it. Losing one Changes page
# beats failing a deployment.
#
# That "cannot fail" is enforced here rather than by the caller, because `continue-on-error` is not
# supported on composite-action steps — so this script swallows its own failures and always exits 0.
#
# Complementary to the ledger rather than replaced by it: the ledger says *when* a declaration last
# changed, the baseline shows the two statements side by side.
set -uo pipefail

# shellcheck source=ci/common.sh
. "$(dirname "${BASH_SOURCE[0]}")/common.sh"

artifact="${REFEREE_ARTIFACT_NAME:-referee-data}"
dest="${RUNNER_TEMP:-/tmp}/referee-baseline"

skip() {
  referee_info "$*; skipping the revision diff"
  exit 0
}

run_id=$(gh run list -R "$GITHUB_REPOSITORY" \
  --workflow "$REFEREE_WORKFLOW" --branch "$REFEREE_BRANCH" \
  --status success --limit 1 --json databaseId --jq '.[0].databaseId // empty' 2>/dev/null) ||
  skip "could not list earlier runs"
[ -n "$run_id" ] || skip "no earlier successful run"

rm -rf "$dest"
gh run download "$run_id" -R "$GITHUB_REPOSITORY" -n "$artifact" -D "$dest" 2>/dev/null ||
  skip "run $run_id has no \`$artifact\` artifact"

# Located rather than assumed: the artifact's internal layout follows whatever path was uploaded,
# and a wrong guess here would silently cost the Changes page on every run.
found=$(find "$dest" -name '*.json' | head -1)
[ -n "$found" ] || skip "the \`$artifact\` artifact holds no JSON"

referee_info "revision diff baseline: $found (from run $run_id)"
referee_export REFEREE_BASELINE "$found"
