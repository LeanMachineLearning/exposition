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

copied=0
for f in referee.css graph.js toc.js d3.v7.min.js; do
  if [[ -f "$assets/$f" && -f "$dest/$f" ]]; then
    cp "$assets/$f" "$dest/$f"
    copied=$((copied + 1))
  elif [[ -f "$assets/$f" ]]; then
    echo "note: $f is not present in the built site; skipping" >&2
  fi
done

echo "Synced $copied asset(s) into $dest — reload the page (bypass the browser cache)."
