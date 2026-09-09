#!/usr/bin/env bash
# `collect`: imports the target project and writes the collected-data JSON everything downstream
# reads.
#
# This is the phase split that shapes the whole pipeline — everything needing a Lean environment
# produces data, and everything after it is a pure function of that data. Collection is a step of
# its own because `provenance` has to run between it and the rendering.
set -euo pipefail

# shellcheck source=ci/common.sh
. "$(dirname "${BASH_SOURCE[0]}")/common.sh"

exclude=()
referee_split_list exclude --exclude-lib "${REFEREE_EXCLUDE_LIB:-}"

# `--hashes` only when the hash export ran. `provenance` hard-fails on data collected without them
# rather than degrading, which is deliberate: the ledger is append-only, and a text-keyed one would
# permanently record the mass false change of a toolchain upgrade.
hashes=()
if referee_enabled "${REFEREE_WITH_HASHES:-}"; then
  hashes=(--hashes "$(referee_require REFEREE_HASHES)")
fi

# The scope, which is a collect-time property and not a render-time one: `--claims-only` decides
# what goes *into* the data file, so it cannot be varied downstream the way `--trust` can.
scope=()
claims=()
# `referee_split_list` assigns rather than appends, so it gets an array of its own; writing into
# `scope` here would discard the `--claims-only` already in it.
referee_split_list claims --claim "${REFEREE_CLAIM:-}"
if referee_enabled "${REFEREE_CLAIMS_ONLY:-}"; then
  scope=(--claims-only "${claims[@]}")
fi
# `--only` wins: it names the one declaration to publish, which is a narrower instruction than
# "whatever the metadata calls a main result".
if [ -n "${REFEREE_ONLY:-}" ]; then
  scope=(--only "$REFEREE_ONLY" "${claims[@]}")
fi
if [ -n "${REFEREE_COMPARATOR_DIR:-}" ]; then
  scope+=(--comparator "$REFEREE_COMPARATOR_DIR")
fi

lake env "$(referee_require REFEREE_BIN)" collect \
  --root "$(referee_require REFEREE_ROOT)" \
  "${exclude[@]}" \
  "${hashes[@]}" \
  "${scope[@]}" \
  --data "$(referee_require REFEREE_DATA)"
