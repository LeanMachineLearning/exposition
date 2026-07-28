#!/usr/bin/env bash
# Copy the site's CSS/JS straight into an already-built site, for iterating on style without
# rebuilding anything.
#
# The assets are emitted as files (not inlined per page), so a built site references them by URL
# and this is all it takes to see a change:
#
#     scripts/sync-assets.sh /path/to/site-out
#
# then reload the browser (shift-reload, or disable the cache, since the filenames do not change).
# A full `lake build && referee build-site` is only needed once the Lean-side page structure
# changes.
set -euo pipefail

if [[ $# -lt 1 ]]; then
  echo "Usage: $0 SITE_OUT_DIR" >&2
  echo "  SITE_OUT_DIR is the --output directory given to 'referee build-site'." >&2
  exit 2
fi

repo_root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
assets="$repo_root/Referee/Website/assets"
out="$1"

# Verso emits declared asset files into html-multi/-verso-data/.
dest="$out/html-multi/-verso-data"
if [[ ! -d "$dest" ]]; then
  # Tolerate being handed html-multi/ itself, or -verso-data/ itself.
  for candidate in "$out/-verso-data" "$out"; do
    if [[ -d "$candidate" && -f "$candidate/referee.css" ]]; then
      dest="$candidate"
      break
    fi
  done
fi
if [[ ! -d "$dest" ]]; then
  echo "No built site assets at $dest (expected an 'referee build-site' --output directory)." >&2
  exit 1
fi

# Every asset that exists on both sides, rather than a hardcoded list. The list drifted: it named
# four files and was never updated when `browse.js` and `audit.js` were added, so editing either and
# running this reported success while copying neither — the failure mode this script exists to
# prevent, one level up.
copied=0
skipped=()
shopt -s nullglob
for path in "$assets"/*.css "$assets"/*.js; do
  f="$(basename "$path")"
  if [[ -f "$dest/$f" ]]; then
    cp "$path" "$dest/$f"
    copied=$((copied + 1))
  else
    skipped+=("$f")
  fi
done
shopt -u nullglob

if [[ ${#skipped[@]} -gt 0 ]]; then
  echo "note: not present in the built site, skipped: ${skipped[*]}" >&2
fi

echo "Synced $copied asset(s) into $dest — reload the page (bypass the browser cache)."
