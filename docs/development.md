# Working on Referee

## Code Layout

- `LeanDeps.lean` — the dependency analysis, as a **standalone library** (`lean_lib LeanDeps`)
  that depends on Lean core only: no Lake, no Verso, no notion of a site or of an output format.
  It answers, for every declaration of a project, which constants its type uses and which its type
  and body use, looking through compiler-generated helpers (`_proof_N`, `match_N`, field defaults)
  and recovering the dependencies an elaborated term drops (`Expr.proj` structures, notation
  expansions, coercion instances). It also holds the graph passes that run on the result: reverse
  edges and transitive closure in topological order. Entry points: `LeanDeps.Context.of` /
  `Context.declDeps` / `declDepsOf`.
- `LeanSpec/` — the `@[specifies]` attribute, as a **separate Lake package** rather than a library
  of this one. It is the only part of this repository a target project depends on, so it must not
  pull Verso along with it: Lean core only, one file, no dependencies. This package depends on it
  too, for the other end of the same wire — reading the annotations back out of a compiled project
  requires the environment extension to be registered in the reading process. See
  [`LeanSpec/README.md`](../LeanSpec/README.md).
- `Referee/Collect.lean` — walks the environment and builds one `DeclInfo` per exposed
  declaration (signature, docstring, source snippet, kind), delegating all dependency computation to
  `LeanDeps` and deciding only which edges Referee follows (`graphDeps`: type-only for
  theorems). `sorry` status is a single transitive flag (`dependsOnSorry`) obtained from
  `Lean.collectAxioms`, i.e. the same answer `#print axioms` gives. `@[specifies]` annotations are
  read here too and reversed by `attachSpecifiedBy`, the one field on `DeclInfo` that is not
  derived from the environment but taken from the author.
- `Referee/Provenance.lean` — the provenance ledger (`--provenance`). The fold is pure — ledger,
  revision, declarations in; ledger out — and unit-tested in `Test/Provenance.lean`, which matters
  more here than elsewhere because the file is append-only: a fold that records a change where none
  happened writes that into the record for good. The git reading (`blame`, `log`, `describe`) is
  the only part that shells out, and it is one `git blame` per *file* rather than per declaration.
- `Referee/Audit.lean` — the payloads the audit page and the per-declaration control hand to
  `assets/audit.js`, plus `dataFingerprint`, the stamp an exported audit file carries so it can be
  matched against the build it was made against. The verdicts, coverage, queue, import and export
  are all the browser's; this is only the data they run on.
- `Referee/Diff.lean` — the revision comparison (`--baseline`): a pure function of two
  `CollectedData` values, with no environment and no notion of a page. Classifies each declaration
  as statement-changed, body-changed, indirectly invalidated, changed-underneath, proof-only, added
  or unchanged. Prefers semantic hashes where both revisions carry them — the hash decides *whether*
  the meaning moved, the text decides *where* — and falls back to comparing text per declaration
  where they do not. Fully unit-tested in `Test/Diff.lean`, which is affordable precisely because it
  is pure.
- `Referee/Extract.lean` — the standalone `.lean` file extraction (see `KNOWN-ISSUES.md`).
- `Referee/Highlight.lean` — source-text highlighting. Runs the Lean frontend over a file and
  returns SubVerso `Highlighted` per command, tagged with the names each command defines, plus any
  elaboration errors. Depends on Lean and SubVerso only — it knows nothing about the site.
- `Referee/Website/Site.lean` — Verso page construction and the CLI subcommands. The site's
  CSS and JavaScript live in `Referee/Website/assets/` as real files and are embedded with
  `include_str`. D3 is vendored there too rather than fetched from a CDN at page load. Everything
  specification-related is gated on `SiteContext.usesSpecs`, so a project that does not annotate
  gets exactly the site it got before the feature existed — and the same gating, on its own flag,
  covers trust, revisions, semantic hashes and provenance.
- `Test/` — `#guard`-based unit tests (`lake build Test`), split the same way as the code they
  cover: `Test/Deps.lean` for `LeanDeps`, `Test/Collect.lean` and `Test/Extract.lean` for this tool,
  `Test/Diff.lean` and `Test/Provenance.lean` for the two pure comparison passes, `Test/Audit.lean`
  for the audit payloads, and `Test/Spec.lean` for the `@[specifies]` attribute — the annotations it
  records, read back out of the environment, with each rejection pinned by `#guard_msgs`, since
  those messages are the attribute's entire user interface.

  The pure passes are where the tests earn the most. `Referee/Diff.lean` and
  `Referee/Provenance.lean` are functions from data to data with no environment and no notion of a
  page, so exhaustive testing is cheap — and for provenance it is close to required, because the
  ledger is append-only and a fold that records a change where none happened writes that into the
  record for good.


## Theme

`Referee/Website/assets/referee.css` is the whole theme, built on a token block that
exists in a light and a dark variant. It loads after Verso's `book.css` and `verso-vars.css`, so it
both restates Verso's own custom properties (fonts, text/code/structure colours, code-highlighting
colours) and overrides the handful of places its stylesheet hardcodes a colour.

Verso ships no dark mode, so the dark variant also themes its chrome — header, table of contents,
and the search box, which reads a `--verso-background-color` that Verso never defines and so
defaulted to white. A control in the sidebar cycles auto → light → dark; the choice is stored in
`localStorage` and applied by a small inline script in `<head>` so the page never flashes the wrong
theme. The dependency graph reads its colours from the same tokens and repaints on a
`referee:themechange` event rather than requiring a reload.

## Iterating On Style

The site's CSS and JS are emitted as *files* (into `html-multi/-verso-data/`) rather than inlined
into every page, so a style change does not need a rebuild at all:

```bash
# edit Referee/Website/assets/referee.css or graph.js, then:
scripts/sync-assets.sh /path/to/site-out
```

and reload the browser, bypassing its cache. That takes milliseconds, against roughly a minute for
`lake build` plus `build-site`. A full rebuild is only needed once the Lean-side page structure
changes.

Two things worth knowing:

- The assets are declared as a Lake `input_dir` in `lakefile.lean`, with `needs := #[websiteAssets]`
  on the library. Without that, `include_str` is invisible to Lake's change detection and
  `lake build` reports success while silently keeping the stale `.olean` — the site then builds from
  the *previous* version of the file.
- `sync-assets.sh` patches an already-built site only. The binary still embeds whatever was there at
  build time, so re-run `lake build` before generating a site you intend to publish.
