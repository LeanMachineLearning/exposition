#!/usr/bin/env bash
# Tests for the Referee CI scripts.
#
# These exist because the shell they replace could not be tested at all. Two copies of it lived in
# consumer workflows, and when the `highlight` subcommand was removed from referee both copies kept
# calling it and their site builds failed on every push — for exactly as long as it took someone to
# read a log. The first test below is that regression, generalised.
#
# No network and no Lean: `gh`, `lake` and `referee` are replaced by fakes on PATH, so this runs in
# about a second and can gate every pull request.
#
# Usage: ci/tests/run-tests.sh [name-filter]
set -uo pipefail

repo_root="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
ci_dir="$repo_root/ci"

# shellcheck source=ci/common.sh
. "$ci_dir/common.sh"
filter="${1:-}"
passed=0
failed=0

pass() { printf '  \033[32mok\033[0m %s\n' "$1"; passed=$((passed + 1)); }
fail() { printf '  \033[31mFAIL\033[0m %s\n     %s\n' "$1" "$2"; failed=$((failed + 1)); }

# Each test runs in a scratch directory of its own with a scratch HOME, so nothing it does can
# reach the developer's checkout or git config.
run_test() {
  local name="$1"
  [ -z "$filter" ] || [[ "$name" == *"$filter"* ]] || return 0
  local tmp
  tmp="$(mktemp -d)"
  # A subshell rather than a fresh `bash -c`, so the test functions and the sourced helpers are
  # already in scope; the scratch cwd and HOME still keep each test from reaching anything real.
  local out status
  out="$(
    cd "$tmp" || exit 1
    export HOME="$tmp" RUNNER_TEMP="$tmp/runner" GITHUB_ENV="" GITHUB_OUTPUT=""
    "test_$name" 2>&1
  )"
  status=$?
  rm -rf "$tmp"
  if [ "$status" -eq 0 ]; then pass "$name"; else fail "$name" "${out:-exit $status}"; fi
}

assert_eq() {
  [ "$1" = "$2" ] || { echo "expected: $2"; echo "     got: $1"; return 1; }
}
assert_contains() {
  case "$1" in *"$2"*) return 0 ;; esac
  echo "expected to contain: $2"; echo "                 got: $1"; return 1
}

# ---------------------------------------------------------------------------------------------
# Fakes. Each writes a real executable into $tmp/bin and puts it first on PATH.
# ---------------------------------------------------------------------------------------------

# A `referee` that records its argv to $tmp/referee-args and succeeds, plus a `lake` whose `env`
# subcommand just execs the rest. Together they let the render phase be checked for the flags it
# assembles without a Lean toolchain anywhere.
fake_referee() {
  mkdir -p bin
  cat > bin/referee <<'EOF'
#!/usr/bin/env bash
printf '%s\n' "$*" >> "$FAKE_ARGS"
EOF
  cat > bin/lake <<'EOF'
#!/usr/bin/env bash
[ "${1:-}" = env ] && shift
exec "$@"
EOF
  chmod +x bin/referee bin/lake
  export PATH="$PWD/bin:$PATH"
  export FAKE_ARGS="$PWD/referee-args"
  : > "$FAKE_ARGS"
}

# A `gh` driven by two files: $tmp/gh-exit for the status to return, $tmp/gh-out for stdout. Enough
# for both the release download and the baseline lookup.
fake_gh() {
  mkdir -p bin
  cat > bin/gh <<'EOF'
#!/usr/bin/env bash
printf '%s\n' "$*" >> "${FAKE_GH_ARGS:-/dev/null}"
[ -f "$FAKE_GH_OUT" ] && cat "$FAKE_GH_OUT"
exit "$(cat "$FAKE_GH_EXIT" 2>/dev/null || echo 0)"
EOF
  chmod +x bin/gh
  export PATH="$PWD/bin:$PATH"
  export FAKE_GH_ARGS="$PWD/gh-args" FAKE_GH_OUT="$PWD/gh-out" FAKE_GH_EXIT="$PWD/gh-exit"
  : > "$FAKE_GH_ARGS"; : > "$FAKE_GH_OUT"; echo 0 > "$FAKE_GH_EXIT"
}

# Builds the release archive `download-referee.sh` expects, for a given toolchain string.
fake_release_tarball() {
  local toolchain="$1" dir="referee-linux-x86_64-deadbeef"
  mkdir -p "$dir"
  echo '#!/usr/bin/env bash' > "$dir/referee"
  chmod +x "$dir/referee"
  printf '{"lean_toolchain": "%s"}\n' "$toolchain" > "$dir/metadata.json"
  tar -czf "$dir.tar.gz" "$dir"
  rm -rf "$dir"
  printf '%s' "$PWD/$dir.tar.gz"
}

# A bare repository standing in for GitHub, and the environment the ledger scripts read.
fake_ledger_remote() {
  git init --quiet --bare remote.git
  export GITHUB_REPOSITORY="owner/repo" GITHUB_SHA="0123456789abcdef"
  export REFEREE_LEDGER_BRANCH="referee-ledger"
  export REFEREE_LEDGER_DIR="$PWD/ledger"
  export REFEREE_PROVENANCE="$PWD/data/provenance.json"
  mkdir -p data
  # `ledger.sh` runs as a subprocess and sources its own copy of common.sh, so the seam has to be
  # an environment variable rather than a redefined function.
  export REFEREE_REMOTE_URL="$PWD/remote.git"
}

# ---------------------------------------------------------------------------------------------
# The regression that motivated all of this.
# ---------------------------------------------------------------------------------------------

# Every referee subcommand these scripts invoke must exist in the binary's dispatch table. When
# `highlight` was deleted in 9566a68, two consumer workflows kept calling it; referee exits 1 on an
# unknown subcommand, so `set -e` took the whole step down on every push to main.
#
# Checked against the dispatch in Site.lean rather than by running the binary, so it needs no build
# and can gate a pull request in milliseconds.
test_subcommands_exist() {
  local dispatch used sub
  dispatch="$(grep -oE '\| "[a-z-]+" :: rest' "$repo_root/Referee/Website/Site.lean" |
              grep -oE '"[a-z-]+"' | tr -d '"' | sort -u)"
  [ -n "$dispatch" ] || { echo "found no dispatch table in Site.lean"; return 1; }
  # shellcheck disable=SC2016  # the `$bin` here is matched literally in the scripts, not expanded
  used="$(grep -hoE '(REFEREE_BIN\)"|\$bin")[[:space:]]+[a-z][a-z-]*' "$ci_dir"/*.sh |
          awk '{print $NF}' | sort -u)"
  [ -n "$used" ] || { echo "found no referee invocations in ci/*.sh"; return 1; }
  for sub in $used; do
    grep -qx "$sub" <<< "$dispatch" ||
      { echo "ci/*.sh invokes \`referee $sub\`, which is not in Site.lean's dispatch table."
        echo "dispatch table: $(tr '\n' ' ' <<< "$dispatch")"; return 1; }
  done
}

# The other half of the same class of bug: a variable a script reads but nothing ever sets. The
# scripts take their configuration from a `REFEREE_*` environment contract, which is exactly the
# kind of coupling that rots silently — renaming an input in `action.yml` leaves the script reading
# a name that is now never set, and under a `:-` default that failure is a wrong site rather than an
# error. Every name a script reads must therefore be set by `action.yml`, exported by another
# script, or given an explicit default at the point of use.
test_every_variable_is_wired() {
  local used provided var
  # shellcheck disable=SC2016  # these patterns match `$REFEREE_*` literally in the scripts
  used="$( { grep -hoE '\$\{?REFEREE_[A-Z_]+' "$ci_dir"/*.sh | tr -d '${'
             grep -hoE 'referee_require REFEREE_[A-Z_]+' "$ci_dir"/*.sh | awk '{print $2}'
           } | sort -u )"
  provided="$( { grep -hoE 'REFEREE_[A-Z_]+' "$repo_root/action.yml" "$ci_dir/prepare.sh"
                 grep -hoE 'referee_export REFEREE_[A-Z_]+' "$ci_dir"/*.sh | awk '{print $2}'
               } | sort -u )"
  for var in $used; do
    grep -qx "$var" <<< "$provided" && continue
    # Not wired anywhere — acceptable only if every use site supplies a default.
    grep -qE "\\\$\{$var:-" "$ci_dir"/*.sh && continue
    echo "$var is read by ci/*.sh but never set by action.yml and has no \`:-\` default"
    return 1
  done

  # And the precise coupling: every name `prepare.sh` re-exports into the job environment must
  # actually be set by an `env:` block in `action.yml`. Renaming an input on one side alone leaves
  # `prepare.sh` exporting an empty string, which is a silently wrong site for anything optional.
  local loop_vars action_env
  loop_vars="$(sed -n '/^for var in /,/done$/p' "$ci_dir/prepare.sh" | grep -oE 'REFEREE_[A-Z_]+' | sort -u)"
  action_env="$(grep -oE '^ +REFEREE_[A-Z_]+:' "$repo_root/action.yml" | tr -d ' :' | sort -u)"
  [ -n "$loop_vars" ] || { echo "could not find prepare.sh's re-export list"; return 1; }
  for var in $loop_vars; do
    grep -qx "$var" <<< "$action_env" ||
      { echo "prepare.sh re-exports $var, but action.yml never sets it"; return 1; }
  done
}

# ---------------------------------------------------------------------------------------------
# common.sh
# ---------------------------------------------------------------------------------------------

test_split_list_commas_and_newlines() {
  local flags
  referee_split_list flags --trust "mathlib, batteries"
  assert_eq "${flags[*]}" "--trust mathlib --trust batteries" || return 1
  referee_split_list flags --trust "$(printf 'mathlib\n  batteries  \n')"
  assert_eq "${flags[*]}" "--trust mathlib --trust batteries" || return 1
}

test_split_list_empty_yields_no_flags() {
  local flags
  referee_split_list flags --trust ""
  assert_eq "${#flags[@]}" 0
}

test_enabled_accepts_actions_booleans() {
  referee_enabled true || return 1
  referee_enabled false && { echo '"false" was treated as enabled'; return 1; }
  referee_enabled "" && { echo 'empty was treated as enabled'; return 1; }
  return 0
}

test_require_names_the_missing_input() {
  local out
  out="$(REFEREE_ROOT="" referee_require REFEREE_ROOT 2>&1)" && { echo "empty value accepted"; return 1; }
  assert_contains "$out" "REFEREE_ROOT is required"
}

# ---------------------------------------------------------------------------------------------
# download-referee.sh
# ---------------------------------------------------------------------------------------------

test_download_checks_the_toolchain() {
  fake_gh
  echo "leanprover/lean4:v4.99.0" > lean-toolchain
  local tarball; tarball="$(fake_release_tarball "leanprover/lean4:v4.0.0")"
  mkdir -p runner/referee && cp "$tarball" runner/referee/
  local out
  out="$("$ci_dir/download-referee.sh" 2>&1)" && { echo "mismatched toolchain was accepted"; return 1; }
  assert_contains "$out" "built for leanprover/lean4:v4.0.0 but this project uses leanprover/lean4:v4.99.0"
}

test_download_accepts_a_matching_toolchain() {
  fake_gh
  echo "leanprover/lean4:v4.99.0" > lean-toolchain
  local tarball; tarball="$(fake_release_tarball "leanprover/lean4:v4.99.0")"
  mkdir -p runner/referee && cp "$tarball" runner/referee/
  local out
  out="$("$ci_dir/download-referee.sh" 2>&1)" || { echo "$out"; return 1; }
  assert_contains "$out" "toolchain leanprover/lean4:v4.99.0"
}

# A tag-shaped action ref selects that release; anything else falls back to the newest one, which is
# what makes `uses: …@v0.2.0` pin the binary without the caller naming the version twice.
test_download_defaults_version_to_the_action_ref() {
  fake_gh
  echo "leanprover/lean4:v4.99.0" > lean-toolchain
  local tarball; tarball="$(fake_release_tarball "leanprover/lean4:v4.99.0")"
  mkdir -p runner/referee && cp "$tarball" runner/referee/
  REFEREE_ACTION_REF="v0.2.0" "$ci_dir/download-referee.sh" >/dev/null 2>&1 || return 1
  assert_contains "$(cat "$FAKE_GH_ARGS")" "release download v0.2.0" || return 1
  : > "$FAKE_GH_ARGS"
  REFEREE_ACTION_REF="main" "$ci_dir/download-referee.sh" >/dev/null 2>&1 || return 1
  local args; args="$(cat "$FAKE_GH_ARGS")"
  case "$args" in *"release download main"*) echo "a branch ref was used as a release tag"; return 1 ;; esac
  assert_contains "$args" "release download -R"
}

# ---------------------------------------------------------------------------------------------
# ledger.sh — the round trip that carries years of history
# ---------------------------------------------------------------------------------------------

test_ledger_fetch_tolerates_a_missing_branch() {
  fake_ledger_remote
  local out
  out="$("$ci_dir/ledger.sh" fetch 2>&1)" || { echo "$out"; return 1; }
  assert_contains "$out" "this run starts one"
}

test_ledger_publish_then_fetch_round_trips() {
  fake_ledger_remote
  echo '{"revisions": ["r1"]}' > "$REFEREE_PROVENANCE"
  "$ci_dir/ledger.sh" fetch >/dev/null 2>&1 || return 1
  local out
  out="$("$ci_dir/ledger.sh" publish 2>&1)" || { echo "$out"; return 1; }
  assert_contains "$out" "ledger published" || return 1
  # A second run must find what the first pushed — the whole point of the branch.
  rm -f "$REFEREE_PROVENANCE"
  out="$("$ci_dir/ledger.sh" fetch 2>&1)" || { echo "$out"; return 1; }
  assert_contains "$out" "ledger fetched" || return 1
  assert_eq "$(cat "$REFEREE_PROVENANCE")" '{"revisions": ["r1"]}'
}

test_ledger_publish_is_idempotent_at_one_commit() {
  fake_ledger_remote
  echo '{"revisions": ["r1"]}' > "$REFEREE_PROVENANCE"
  "$ci_dir/ledger.sh" fetch >/dev/null 2>&1
  "$ci_dir/ledger.sh" publish >/dev/null 2>&1 || return 1
  rm -rf "$REFEREE_LEDGER_DIR"
  "$ci_dir/ledger.sh" fetch >/dev/null 2>&1
  local out
  out="$("$ci_dir/ledger.sh" publish 2>&1)" || { echo "$out"; return 1; }
  assert_contains "$out" "nothing to push"
}

# A push that fails for a reason that will never fix itself has to fail the job. Warning about it
# every run is how a ledger silently stays one revision long forever.
test_ledger_publish_fails_loudly_on_a_rejected_push() {
  fake_ledger_remote
  echo '{"revisions": ["r1"]}' > "$REFEREE_PROVENANCE"
  "$ci_dir/ledger.sh" fetch >/dev/null 2>&1
  rm -rf remote.git   # stands in for a protected branch or a missing contents: write
  local out
  out="$("$ci_dir/ledger.sh" publish 2>&1)" && { echo "a rejected push was not reported"; return 1; }
  assert_contains "$out" "::error::" || return 1
  assert_contains "$out" "contents: write"
}

# ---------------------------------------------------------------------------------------------
# baseline.sh — must never be able to fail the job
# ---------------------------------------------------------------------------------------------

# `continue-on-error` is not supported on composite-action steps, so the "optional in every
# direction" promise has to be kept by the script itself.
test_baseline_never_fails_the_job() {
  fake_gh
  echo 1 > "$FAKE_GH_EXIT"
  export GITHUB_REPOSITORY="owner/repo" REFEREE_WORKFLOW="Build" REFEREE_BRANCH="main"
  local out
  out="$("$ci_dir/baseline.sh" 2>&1)" || { echo "baseline.sh exited nonzero: $out"; return 1; }
  assert_contains "$out" "skipping the revision diff"
}

test_baseline_skips_when_there_is_no_earlier_run() {
  fake_gh   # exits 0 with empty stdout: a successful lookup that found nothing
  export GITHUB_REPOSITORY="owner/repo" REFEREE_WORKFLOW="Build" REFEREE_BRANCH="main"
  local out
  out="$("$ci_dir/baseline.sh" 2>&1)" || { echo "$out"; return 1; }
  assert_contains "$out" "no earlier successful run"
}

# ---------------------------------------------------------------------------------------------
# render.sh — the flags it assembles
# ---------------------------------------------------------------------------------------------

render_env() {
  export REFEREE_BIN="referee" REFEREE_SITE_URL="https://example.org/site"
  export REFEREE_DATA="$PWD/data.json" REFEREE_OUTPUT_DIR="$PWD/out"
  export GITHUB_REPOSITORY="owner/repo"
  echo '{"version": 3}' > "$REFEREE_DATA"
}

test_render_passes_trust_and_exclude_lists() {
  fake_referee; render_env
  REFEREE_TRUST="mathlib, batteries" REFEREE_EXCLUDE_LIB="Tutorial" \
    "$ci_dir/render.sh" >/dev/null 2>&1 || return 1
  local args; args="$(cat "$FAKE_ARGS")"
  assert_contains "$args" "--trust mathlib --trust batteries" || return 1
  assert_contains "$args" "extract --data $REFEREE_DATA --exclude-lib Tutorial"
}

# The guard that keeps a stale artifact from failing a deployment: `build-site` treats a
# collected-data version mismatch as fatal, so a mismatched baseline is dropped rather than passed.
test_render_drops_an_incompatible_baseline() {
  fake_referee; render_env
  echo '{"version": 2}' > baseline.json
  local out
  out="$(REFEREE_BASELINE="$PWD/baseline.json" "$ci_dir/render.sh" 2>&1)" || { echo "$out"; return 1; }
  assert_contains "$out" "skipping the revision diff" || return 1
  case "$(cat "$FAKE_ARGS")" in *--baseline*) echo "an incompatible baseline was still passed"; return 1 ;; esac
  return 0
}

test_render_passes_a_compatible_baseline() {
  fake_referee; render_env
  echo '{"version": 3}' > baseline.json
  REFEREE_BASELINE="$PWD/baseline.json" REFEREE_BASELINE_LABEL="the previous build" \
    "$ci_dir/render.sh" >/dev/null 2>&1 || return 1
  assert_contains "$(cat "$FAKE_ARGS")" "--baseline $PWD/baseline.json --baseline-label the previous build"
}

test_render_omits_provenance_when_disabled() {
  fake_referee; render_env
  REFEREE_WITH_PROVENANCE=false "$ci_dir/render.sh" >/dev/null 2>&1 || return 1
  case "$(cat "$FAKE_ARGS")" in *--provenance*) echo "--provenance passed while disabled"; return 1 ;; esac
  return 0
}

test_render_skips_highlight_extracted_by_default() {
  fake_referee; render_env
  "$ci_dir/render.sh" >/dev/null 2>&1 || return 1
  case "$(cat "$FAKE_ARGS")" in *highlight-extracted*) echo "highlight-extracted ran by default"; return 1 ;; esac
  return 0
}

test_render_copies_to_site_dest() {
  fake_referee; render_env
  mkdir -p out/html-multi && echo hi > out/html-multi/index.html
  REFEREE_SITE_DEST="$PWD/pages/exposition" "$ci_dir/render.sh" >/dev/null 2>&1 || return 1
  [ -f pages/exposition/index.html ] || { echo "site was not copied to site-dest"; return 1; }
}

# ---------------------------------------------------------------------------------------------

echo "Referee CI script tests"
for t in $(declare -F | awk '{print $3}' | grep '^test_' | sed 's/^test_//'); do
  run_test "$t"
done
echo
if [ "$failed" -eq 0 ]; then
  echo "$passed passed"
else
  echo "$passed passed, $failed failed"
  exit 1
fi
