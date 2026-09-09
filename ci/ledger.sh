#!/usr/bin/env bash
# The provenance ledger's round trip: `ledger.sh fetch` before the fold, `ledger.sh publish` after.
#
# The ledger is the one part of the pipeline that has to *survive* the run that wrote it. It is
# append-only and its whole value is remembering years of history, which a 90-day artifact cannot
# hold — so it lives in the repository, but on a branch of its own and never in the working tree.
#
# Both halves of that matter:
#
#   * A branch of its own, because a protected default branch is the normal case. "Changes must be
#     made through a pull request" leaves GITHUB_TOKEN unable to push at all, and classic branch
#     protection has no bypass list an app can be added to. A dedicated unprotected branch needs no
#     repository settings changed, no personal access token, and no reviewer looking at a
#     machine-written JSON file. It never merges into anything.
#
#   * Not in the working tree, because `git status --porcelain` counts untracked files: a
#     `provenance.json` sitting in the repository root stamps every fold as built from a revision
#     nobody can check out, and makes the site fall back to `blob/main` source links.
#
# The clone is separate from the project's checkout rather than a fetch into it: an orphan branch
# fetched at `--depth 1` leaves a shallow boundary behind, and `git blame` over the whole history is
# the other half of what `provenance` does.
set -euo pipefail

# shellcheck source=ci/common.sh
. "$(dirname "${BASH_SOURCE[0]}")/common.sh"

branch="${REFEREE_LEDGER_BRANCH:-referee-ledger}"
dir="$(referee_require REFEREE_LEDGER_DIR)"
ledger="$(referee_require REFEREE_PROVENANCE)"

case "${1:-}" in
  fetch)
    mkdir -p "$(dirname "$ledger")"
    rm -rf "$dir"
    # A missing branch is the ordinary first run, not an error: the publish half starts one.
    if git clone --quiet --depth 1 --branch "$branch" "$(referee_remote_url)" "$dir" 2>/dev/null &&
       [ -f "$dir/provenance.json" ]; then
      cp "$dir/provenance.json" "$ledger"
      referee_info "ledger fetched from $branch"
    else
      referee_info "no ledger on $branch yet; this run starts one"
    fi
    ;;

  publish)
    [ -f "$ledger" ] || referee_die "no ledger at $ledger to publish; did the fold step run?"
    # Read before `cd`, while the working directory is still the project: afterwards `git rev-parse`
    # would answer for the ledger's own repository. Outside GitHub Actions there is no GITHUB_SHA.
    sha="${GITHUB_SHA:-$(git rev-parse HEAD 2>/dev/null || echo unknown)}"
    if [ ! -d "$dir/.git" ]; then
      mkdir -p "$dir"
      git -C "$dir" init --quiet -b "$branch"
      git -C "$dir" remote add origin "$(referee_remote_url)"
    fi
    cd "$dir"
    git config user.name "github-actions[bot]"
    git config user.email "41898282+github-actions[bot]@users.noreply.github.com"
    # The tip as fetched, remembered before committing on top of it: a shallow clone has no parent
    # to ask for afterwards, and this is what tells a lost race apart from a rejected push below.
    base=$(git rev-parse HEAD 2>/dev/null || echo none)
    cp "$ledger" provenance.json
    git add provenance.json
    if [ "$base" != none ] && git diff --cached --quiet; then
      referee_info "ledger unchanged (already folded at this commit); nothing to push"
      exit 0
    fi
    git commit --quiet -m "fold ${sha:0:7} into the provenance ledger"
    # `if git push; then` rather than `git push && exit 0`: under `set -e` the second form takes the
    # whole step down on exactly the failure this is here to handle.
    if git push --quiet origin "HEAD:$branch"; then
      referee_info "ledger published to $branch"
      exit 0
    fi
    # Two very different failures, which one warning used to cover alike. A concurrent run that got
    # there first is transient: the fold is idempotent per commit, so the next run folds this
    # revision together with the following one and nothing is lost but resolution. Anything else —
    # a protected ledger branch, a missing `contents: write` — will never fix itself, and warning
    # about it every run is how a ledger silently stays one revision long forever.
    if git fetch --quiet origin "$branch" 2>/dev/null &&
       [ "$base" != "$(git rev-parse FETCH_HEAD)" ]; then
      referee_warn "the ledger branch moved under this run; the next run folds this revision together with the following one"
    else
      referee_die "could not push the provenance ledger to $branch. Check that the branch is not \
protected and that the job grants \`permissions: contents: write\`."
    fi
    ;;

  *)
    referee_die "usage: ledger.sh fetch|publish"
    ;;
esac
