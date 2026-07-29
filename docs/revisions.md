# Comparing revisions

Refereeing is iterative: a reader works through the library, the author revises it, and the reader
must not start over. `--baseline` is what makes that possible — an earlier `collect` output to
compare the current one against:

```bash
"$REFEREE" build-site --data data.json --baseline v0.2/data.json --baseline-label v0.2 \
  --output "$OUT"
```

It is a render-time flag like `--trust`, because the comparison is a pure function of the two JSON
files: no environment, no source tree, no re-import. Publishing `data.json` beside each released
site is therefore the only thing an author has to do to make the next revision diffable.

The classification is the site's own meaning/trust split (`meaningDeps`) applied across time rather
than across the dependency graph:

- a **statement change** invalidates any reading of the declaration;
- a **body change** invalidates one only where the body *is* the meaning — for a definition, not
  for a theorem, whose proof the kernel has rechecked;
- an **indirect invalidation** is the case the feature exists for. A theorem whose own statement is
  untouched, but whose statement mentions a definition that changed, now means something different
  while reading byte-identically. No textual diff of the repository can show it; closing the changed
  set over `transDeps` finds it exactly.
- **proof-only changes** need no re-reading at all, and the page says so — this is where the bulk of
  any real revision lands, and telling a referee what they may skip is half the value.

## What The Comparison Is Made On

By default, text: statements as `expandedSignature` (the pretty-printed *elaborated* type, which is
right in both directions — reformatting does not count, and an edited `variable` line does) and
bodies as source text, since nothing elaborated is recorded for them.

Given `--hashes`, **semantic hashes** instead, and this is much the better measure. See
[Semantic hashes](semantic-hashes.md) for how to produce the file. Three things change:

- **A toolchain upgrade stops mattering.** It is the failure mode the text comparison cannot
  survive: a Lean bump can change how every type in a library pretty-prints at once, and the page
  then tells the reader to re-audit everything. A structural hash of the elaborated term is
  unaffected. Without hashes, `build-site` warns when a diff has that shape (nearly every statement
  reported as changed); with them, the warning is switched off because the failure cannot occur.
- **Bodies stop being over-reported.** Whitespace normalization always covered reindentation, but
  not renaming a variable inside a definition or adding a comment to it — and because a body change
  propagates along the closure, one renamed binder invalidated every theorem stated about that
  definition. Measured on this repository: an alpha-renamed lambda in one `def` is reported as a
  changed definition by the text comparison and as no change at all by the hash.
- **A fourth category appears.** The hash is *deep* — a referenced constant contributes its own
  hash — so it moves when anything in a declaration's closure moves, including code outside the
  project. Where the meaning changed and no exposed declaration accounts for it, the page reports
  **meaning changed underneath**: an upstream package the project was rebuilt against, or
  unexposed project code. The text comparison cannot detect this case at all.

What a hash cannot say is *where* the change was, so the textual keys stay on for attribution:
they are what separate a statement that moved from one that merely rests on something that did.
The fallback is per declaration, so an old baseline or a partial hash file costs a partial upgrade
rather than the whole thing, and the page names which measure it used.

Two limits, both stated on the page:

- **Hashes are 64-bit**, so two different meanings can in principle collide and be reported as
  unchanged. For a library of a few thousand declarations that is on the order of one chance in a
  trillion, and it is the only direction in which the comparison under-reports.
- **Extraction compile status is not compared**: it lives in the `extracted-highlighting/` output
  rather than in `data.json`, so it is out of range for a diff of two collected-data files.
