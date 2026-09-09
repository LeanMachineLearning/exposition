#!/usr/bin/env bash
# Shared helpers for the Referee CI scripts. Sourced, never executed.
#
# Every script here is driven by a `REFEREE_*` environment contract rather than by positional
# arguments, because the composite action sets that contract once in its first step (via
# `$GITHUB_ENV`) instead of repeating a dozen `env:` blocks. The contract is documented in
# `action.yml`; `ci/tests/run-tests.sh` exercises these scripts by setting it by hand, which is
# also how to run any single phase outside GitHub Actions.

# Annotations, so a failure inside a composite action still surfaces in the caller's log with a
# cause attached. `::error::` is what makes GitHub render it on the job summary rather than
# burying it in the fold.
referee_error() { echo "::error::$*" >&2; }
referee_warn() { echo "::warning::$*" >&2; }
referee_notice() { echo "::notice::$*"; }
referee_info() { echo "$*"; }

referee_die() {
  referee_error "$*"
  exit 1
}

# Requires a variable to be set and non-empty, naming it in the failure. Under `set -u` an unset
# variable already aborts, but with a bash message that says nothing about which action input the
# caller left out.
referee_require() {
  local name="$1"
  local value="${!name-}"
  [ -n "$value" ] || referee_die "$name is required but empty. See the action's inputs."
  printf '%s' "$value"
}

# Splits a list input into a bash array named by the first argument. Both commas and newlines
# separate, because a YAML input is written either way — `trust: mathlib, batteries` and a `|`
# block both have to work — and surrounding whitespace is trimmed so an indented block list does
# not produce names with leading spaces.
#
# Usage: referee_split_list FLAGS_ARRAY --trust "mathlib, batteries"
referee_split_list() {
  # The nameref is deliberately given an unlikely name: a plain `out` would shadow — and, to
  # anything reading this file with `shellcheck -x`, appear to be — a caller's own `out` variable.
  local -n __referee_out="$1"
  local flag="$2"
  local raw="${3:-}"
  local item
  __referee_out=()
  [ -n "$raw" ] || return 0
  while IFS= read -r item; do
    [ -n "$item" ] || continue
    __referee_out+=("$flag" "$item")
  done < <(printf '%s\n' "$raw" | tr ',' '\n' | sed 's/^[[:space:]]*//; s/[[:space:]]*$//')
}

# Appends `KEY=value` to a GitHub Actions file (`$GITHUB_ENV` or `$GITHUB_OUTPUT`) when one is
# set, and does nothing otherwise. The "otherwise" is what lets these scripts run under the test
# harness and on a laptop without pretending to be inside a workflow.
referee_export() {
  local key="$1" value="$2"
  export "$key=$value"
  [ -n "${GITHUB_ENV:-}" ] || return 0
  printf '%s=%s\n' "$key" "$value" >> "$GITHUB_ENV"
}

referee_output() {
  local key="$1" value="$2"
  [ -n "${GITHUB_OUTPUT:-}" ] || return 0
  printf '%s=%s\n' "$key" "$value" >> "$GITHUB_OUTPUT"
}

# The authenticated remote for this repository. Built here rather than at each call site so the
# token appears in exactly one place; `git` never logs it, but a script that interpolates it into
# several commands eventually echoes one of them.
referee_remote_url() {
  # An explicit override wins, which is what makes this work on GitHub Enterprise Server behind a
  # different host and what lets the tests point the ledger at a local bare repository.
  if [ -n "${REFEREE_REMOTE_URL:-}" ]; then
    printf '%s' "$REFEREE_REMOTE_URL"
    return 0
  fi
  local token="${REFEREE_TOKEN:-}"
  local repo="${GITHUB_REPOSITORY:-}"
  local server="${GITHUB_SERVER_URL:-https://github.com}"
  [ -n "$repo" ] || referee_die "GITHUB_REPOSITORY is unset; this script expects a GitHub Actions runner."
  if [ -n "$token" ]; then
    # The token goes after the scheme, so `${server#*://}` strips the scheme the runner gave us
    # rather than assuming https://github.com.
    printf 'https://x-access-token:%s@%s/%s' "$token" "${server#*://}" "$repo"
  else
    printf '%s/%s' "$server" "$repo"
  fi
}

# A GitHub Actions boolean input arrives as the string "true" or "false" — there is no boolean
# type in the inputs schema — so every toggle in these scripts goes through here rather than
# through `[ "$x" = true ]` written eleven slightly different ways.
referee_enabled() {
  case "${1:-}" in
    true | True | TRUE | 1 | yes | on) return 0 ;;
    *) return 1 ;;
  esac
}
