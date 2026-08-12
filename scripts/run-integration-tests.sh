#!/usr/bin/env bash
# Runs the `JunkValues` integration tests against a real Mathlib.
#
# These cannot be a Lake target of the JunkValues package, because that package deliberately depends
# on Lean core alone — which is the point of it, and also the reason the tests exist: everything it
# claims about integrals, division and truncated subtraction is a claim about *Mathlib's*
# definitions, and only a run against Mathlib can check it.
#
# The tests elaborate inside the target project's own `lake env`, with the JunkValues build
# directory appended to LEAN_PATH so that one file can import both Mathlib and JunkValues. Every
# check throws on failure, so a clean elaboration is a pass.
#
# Usage: scripts/run-integration-tests.sh MATHLIB_PROJECT_DIR [TEST_FILE]
#
#   MATHLIB_PROJECT_DIR  A project with Mathlib already built (`lake exe cache get && lake build`)
#                        on the SAME toolchain as this repository. `.olean` files are not portable
#                        across toolchains, so a mismatch fails in ways that look like real errors.
#   TEST_FILE            Defaults to JunkValues/test/RealLife.lean.

set -euo pipefail

if [[ $# -lt 1 || $# -gt 2 ]]; then
  echo "Usage: $0 MATHLIB_PROJECT_DIR [TEST_FILE]" >&2
  exit 1
fi

repo_root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
target_dir="$(cd "$1" && pwd)"
test_file="${2:-$repo_root/JunkValues/test/RealLife.lean}"
build_dir="$repo_root/JunkValues/.lake/build/lib/lean"

if [[ ! -f "$test_file" ]]; then
  echo "No such test file: $test_file" >&2
  exit 1
fi

# The toolchain check is worth doing up front. Without it a mismatch surfaces as a wall of
# unrelated elaboration errors from inside Mathlib, which is a bad way to learn that the answer is
# "these two projects disagree about which Lean they are".
repo_toolchain="$(tr -d '[:space:]' < "$repo_root/lean-toolchain")"
target_toolchain="$(tr -d '[:space:]' < "$target_dir/lean-toolchain")"
if [[ "$repo_toolchain" != "$target_toolchain" ]]; then
  echo "Toolchain mismatch: this repo is on '$repo_toolchain', $target_dir is on '$target_toolchain'." >&2
  echo "Mathlib's .olean files are not portable across toolchains; the run would fail confusingly." >&2
  exit 1
fi

if [[ ! -d "$build_dir" ]]; then
  echo "JunkValues is not built. Run: (cd $repo_root/JunkValues && lake build)" >&2
  exit 1
fi

echo "Running $(basename "$test_file") against Mathlib in $target_dir"
cd "$target_dir"
# `lake env bash -c` rather than `lake env lean`: the former lets us append to the LEAN_PATH that
# lake computed, which is what makes Mathlib and JunkValues importable from the same file.
lake env bash -c "LEAN_PATH=\"\$LEAN_PATH:$build_dir\" lean '$test_file'"
echo "OK: integration tests passed."
