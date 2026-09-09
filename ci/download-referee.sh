#!/usr/bin/env bash
# Fetches the `referee` binary from a release of this repository and checks it against the target
# project's toolchain.
#
# A *release*, not a run artifact, on purpose: release assets of a public repository need no
# authentication and never expire, while a cross-repository artifact download needs a PAT with
# `actions:read` — a workflow's own GITHUB_TOKEN is scoped to its own repository and cannot reach
# another's, even a public one — and is deleted after 90 days, so a pinned commit stops resolving.
set -euo pipefail

# shellcheck source=ci/common.sh
. "$(dirname "${BASH_SOURCE[0]}")/common.sh"

release_repo="${REFEREE_RELEASE_REPO:-LeanMachineLearning/exposition}"
dest="${RUNNER_TEMP:-/tmp}/referee"
version="${REFEREE_VERSION:-}"

# The version defaults to the ref the action itself was pinned at, so that
# `uses: LeanMachineLearning/exposition@v0.2.0` gets the binary from the v0.2.0 release without the
# caller naming it twice. Only tag-shaped refs qualify: `@main` and a raw commit sha are not
# releases, and resolving those to "latest" is the honest reading — the caller pinned the *action*
# to a moving ref, so the binary moves with it.
if [ -z "$version" ]; then
  case "${REFEREE_ACTION_REF:-}" in
    v[0-9]*) version="$REFEREE_ACTION_REF" ;;
  esac
fi

mkdir -p "$dest"
if [ -n "$version" ]; then
  referee_info "downloading referee $version from $release_repo"
else
  referee_info "downloading the most recent referee release from $release_repo"
fi

# `${version:+"$version"}` rather than passing "$version": an empty positional would be read as a
# tag named "" and fail, where omitting it entirely is what selects the latest release.
gh release download ${version:+"$version"} \
  -R "$release_repo" \
  --pattern 'referee-linux-x86_64-*.tar.gz' \
  --dir "$dest" --clobber ||
  referee_die "could not download a referee release from $release_repo${version:+ at $version}. \
Check that the tag exists and has a linux-x86_64 asset, or set the \`version\` input."

tar -xzf "$dest"/referee-linux-x86_64-*.tar.gz -C "$dest"
bin=$(echo "$dest"/referee-linux-x86_64-*/referee)
[ -f "$bin" ] || referee_die "the release archive from $release_repo contained no referee binary."
chmod +x "$bin"

# `referee` is a Lean executable built with `supportInterpreter := true`, so it loads the shared
# library of the toolchain it was compiled against and has to match this project's. Checked here
# because the alternative is a dynamic-link failure several steps later that names no cause — and
# it cannot be checked by the binary itself, since that failure happens before `main` runs.
want=$(tr -d '[:space:]' < lean-toolchain)
got=$(jq -r .lean_toolchain "$(dirname "$bin")/metadata.json" | tr -d '[:space:]')
if [ "$want" != "$got" ]; then
  referee_die "referee was built for $got but this project uses $want. Publish a referee release \
from a matching toolchain, or set the \`version\` input to one that matches."
fi

referee_info "referee $version ready at $bin (toolchain $got)"
referee_export REFEREE_BIN "$bin"
