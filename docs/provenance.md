# Provenance

`--baseline` compares this build against one file, chosen when the site was built. Provenance
answers the question a returning referee actually asks, which is narrower: **when did this last
change, and is that after I read it?**

```bash
lake env "$REFEREE" collect --root MyLibrary --hashes hashes.jsonl --data data.json
"$REFEREE" provenance --data data.json --provenance provenance.json --ref v0.3
"$REFEREE" build-site --data data.json --provenance provenance.json --output "$OUT"
```

`provenance` needs a git working tree but no Lean environment, so it is a phase of its own between
`collect` and `build-site`. Commit `provenance.json` and run the subcommand once per release (or
per commit, in CI); each run folds that revision into the ledger and the file accumulates.

**Two facts, never merged.** Every declaration carries when its *file* was last edited (`git blame`
over its source range — textual, and no evidence at all about meaning) and when its *meaning* last
changed (the newest recorded revision at which its semantic hash differs from the one before —
exact). Keeping them apart is the whole point, because the sentence a referee needs is the one that
combines them:

> Meaning unchanged since v0.1, the oldest revision on record (2026-07-28). Its file was edited
> 2026-07-29 (`e2aaa83`, “reformat DiffReport.byName”) without changing what it means.

Shown only where the ledger is a good enough measure to support it. Without a ledger no page
mentions when anything changed, and `provenance` refuses to run on data collected without
`--hashes` rather than falling back to comparing pretty-printed types — the ledger is append-only,
so a text-keyed one would record the mass false change of a toolchain upgrade *permanently*.

**What it adds to the site**, all of it gated on `--provenance`:

- the line above, under every declaration's card;
- a **Meaning moved** column on Browse, sortable — ascending is what has been settled longest;
- a **revision selector** on the Changes page: pick the revision you last worked through and the
  queue is what no longer means what it meant then, ordered by how much rests on each. It works
  client-side because the ledger is one integer per declaration. It gives the queue and its
  breakdown, *not* a diff — the ledger stores hashes, not the text at every revision, so for the
  statements side by side you still want `--baseline` against that revision's `data.json`. The page
  says so where the selector is;
- **source links pinned to the commit** the ledger was folded at, instead of `blob/main`. A
  published site's links otherwise drift: they keep pointing at line 88 of a file that has moved on.
  Folding from a tree with uncommitted changes names a revision nobody can check out, so that case
  falls back to `main` rather than emitting links that would 404.

**Resolution is exactly your build cadence.** Per-commit CI dates changes to commits; per-release
runs date them to releases. The ledger records what was actually folded, so the site states its own
resolution instead of implying a precision it does not have.

Three things to know before trusting the blame half: squash merges collapse provenance to the
squash commit; `actions/checkout` defaults to `fetch-depth: 1`, which makes blame attribute an
entire library to one commit; and lines not yet committed are reported as such rather than
attributed to an invented commit.

Deliberately absent: authors, contribution counts, and commit-message mining. Who wrote something
is not a referee question, and it invites inference about people from data that does not support
it.
