#!/usr/bin/env bash
# Checks that every standalone .lean file written by `exposition extract` (or `exposition all`)
# actually compiles on its own. Each extracted file is self-contained (it inlines its transitive
# dependencies and replaces theorem proofs with `sorry`), so it must be checked from inside the
# target project's own `lake env` to resolve its imports (Mathlib, the project's own libraries,
# ...), not from this repo's environment.
#
# Usage: scripts/check-extracted-compile.sh TARGET_PROJECT_DIR EXTRACTED_DIR [JOBS]
#
#   TARGET_PROJECT_DIR  Directory of the target project (the one passed to `lake env .../exposition`).
#   EXTRACTED_DIR       Directory containing the extracted *.lean files (typically
#                       <output>/html-multi/extracted from `extract`/`all`).
#   JOBS                Number of files to check in parallel (default: number of CPUs).

set -euo pipefail

if [[ $# -lt 2 || $# -gt 3 ]]; then
  echo "Usage: $0 TARGET_PROJECT_DIR EXTRACTED_DIR [JOBS]" >&2
  exit 1
fi

target_dir="$1"
extracted_dir="$2"
jobs="${3:-$(nproc 2>/dev/null || sysctl -n hw.ncpu 2>/dev/null || echo 4)}"

if [[ ! -d "$target_dir" ]]; then
  echo "Target project directory not found: $target_dir" >&2
  exit 1
fi
if [[ ! -d "$extracted_dir" ]]; then
  echo "Extracted-files directory not found: $extracted_dir" >&2
  exit 1
fi

target_dir="$(cd "$target_dir" && pwd)"
extracted_dir="$(cd "$extracted_dir" && pwd)"

report_dir="$(mktemp -d)"
trap 'rm -rf "$report_dir"' EXIT

mapfile -d '' files < <(find "$extracted_dir" -name '*.lean' -print0 | sort -z)
total="${#files[@]}"
if [[ "$total" -eq 0 ]]; then
  echo "No .lean files found under $extracted_dir" >&2
  exit 1
fi

echo "Checking $total extracted file(s) against $target_dir (up to $jobs in parallel)..."

# Writes a failure report to its own uniquely-named file in $report_dir (one per failing input,
# named independently of the source file so basename collisions across directories can't clash).
check_one() {
  local file="$1"
  local output
  if output="$(cd "$target_dir" && lake env lean "$file" 2>&1)"; then
    return 0
  fi
  local report
  report="$(mktemp "$report_dir/failure.XXXXXX")"
  { echo "── $file ──"; echo "$output"; } > "$report"
}
export -f check_one
export target_dir report_dir

printf '%s\0' "${files[@]}" | xargs -0 -P "$jobs" -I{} bash -c 'check_one "$1"' _ {}

shopt -s nullglob
reports=("$report_dir"/failure.*)
failure_count="${#reports[@]}"

if [[ "$failure_count" -gt 0 ]]; then
  echo ""
  echo "FAILED: $failure_count of $total file(s) did not compile:"
  for report in "${reports[@]}"; do
    echo ""
    cat "$report"
  done
fi

echo ""
echo "$((total - failure_count)) of $total file(s) compiled successfully."

if [[ "$failure_count" -gt 0 ]]; then
  exit 1
fi
