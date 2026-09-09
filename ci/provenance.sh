#!/usr/bin/env bash
# `provenance`: folds this revision into the ledger.
#
# Needs a git working tree and no Lean environment at all, so it is a phase of its own. Runs after
# `collect` and before `extract`, so that the cleanliness it records is the repository's and not
# this job's leftovers.
#
# `--ref` is left off, so each revision is named by `git describe --tags --always` — a tag where
# there is one, else a short sha. Set the `revision-ref` input to fold at release cadence instead
# ("changed between v0.2 and v0.3").
set -euo pipefail

# shellcheck source=ci/common.sh
. "$(dirname "${BASH_SOURCE[0]}")/common.sh"

# Dumped so that the tool's "working tree has uncommitted changes" warning, if it fires, comes with
# the reason attached rather than sending someone hunting for it.
referee_info "working tree at fold time:"
git status --porcelain

ref=()
[ -z "${REFEREE_REVISION_REF:-}" ] || ref=(--ref "$REFEREE_REVISION_REF")

"$(referee_require REFEREE_BIN)" provenance \
  --data "$(referee_require REFEREE_DATA)" \
  "${ref[@]}" \
  --provenance "$(referee_require REFEREE_PROVENANCE)"
