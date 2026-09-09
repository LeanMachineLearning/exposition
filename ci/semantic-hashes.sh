#!/usr/bin/env bash
# Builds `semantic_hash` against this project's toolchain and exports the rename-invariant hashes
# that the provenance ledger and the revision diff are keyed on.
#
# Built here rather than downloaded or taken as a Lake dependency, for the same reason referee is
# downloaded rather than built: it loads the target project's environment and refuses to run unless
# its own sysroot matches, so it has to be compiled against *this* toolchain rather than the one it
# pins. Overwriting the pin is the whole patch. It has no dependencies beyond core, so this costs a
# minute or two on a runner that already has the toolchain from the build step.
set -euo pipefail

# shellcheck source=ci/common.sh
. "$(dirname "${BASH_SOURCE[0]}")/common.sh"

repo="${REFEREE_SEMANTIC_HASH_REPO:-https://github.com/mathlib-initiative/semantic_hash}"
ref="${REFEREE_SEMANTIC_HASH_REF:-}"
src="${RUNNER_TEMP:-/tmp}/semantic_hash"
root="$(referee_require REFEREE_ROOT)"

rm -rf "$src"
git clone --quiet --depth 1 ${ref:+--branch "$ref"} "$repo" "$src" ||
  referee_die "could not clone $repo${ref:+ at $ref} to build semantic_hash."
cp lean-toolchain "$src/lean-toolchain"
( cd "$src" && lake build semantic_hash )

# No `lake env`: `semantic_hash` reads the target project's LEAN_PATH itself from `--dir`.
# `--imports` takes the same roots `collect` exposes, which is also how an excluded library stays
# out of the hashed set without an exclusion flag of its own. It hashes the whole upstream cone —
# what makes the hashes deep enough to notice a Mathlib bump changing a statement underneath the
# project — and `collect` keeps only the exposed declarations' entries.
"$src/.lake/build/bin/semantic_hash" export \
  --dir . --imports "$root" --output "$(referee_require REFEREE_HASHES)"

referee_info "exported semantic hashes to $REFEREE_HASHES"
