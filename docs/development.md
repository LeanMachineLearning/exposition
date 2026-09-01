# Working on Referee

## Code Layout

Several of the libraries Referee rests on are **separate Lake packages**, not libraries of this one,
and for the same reason: each is useful to a project that has no interest in building a site, and
requiring one must not drag Verso and the rest of this tool's build along with it. Lake's dependency
unit is the package, so a `lean_lib` of this package could not be required in isolation. Two of them
went further and are repositories of their own, required from git; `JunkValues` is still here and
required by path (`require … from "JunkValues"`), which is the same package an outside project
requires from git with `/ "JunkValues"`.

- [`MeaningGraph`](https://github.com/RemyDegenne/meaning-graph) — the dependency analysis, in a
  repository of its own. Lean core only: no Lake, no Verso, no notion of a site or of an output
  format. It answers, for every declaration of a project, which constants its type uses and which
  its type and body use, looking through compiler-generated helpers (`_proof_N`, `match_N`, field
  defaults) and recovering the dependencies an elaborated term drops (`Expr.proj` structures,
  notation expansions, coercion instances). It also holds the graph passes that run on the result:
  reverse edges and transitive closure in topological order. Entry points:
  `MeaningGraph.Context.of` / `Context.declDeps` / `declDepsOf`. Its own `#guard`s and proofs live
  with it, so nothing here tests it.
- [`Characterization`](https://github.com/RemyDegenne/characterization) — the `@[specifies]` and
`@[characterization]` attributes, in a
  repository of its own. It is the part of this stack a *target* project depends on, so it must not
  pull Verso along with it: Lean core only, one file, no dependencies. Referee depends on it too,
  for the other end of the same wire — reading the annotations back out of a compiled project
  requires the environment extension to be registered in the reading process. Its own checks live
  with it, so nothing here tests it.
- `Referee/Collect.lean` — walks the environment and builds one `DeclInfo` per exposed
  declaration (signature, docstring, source snippet, kind), delegating all dependency computation to
  `MeaningGraph` and deciding only which edges Referee follows. There are two such choices:
  `closureDeps` (type-only for theorems) drives `transDeps`, which `Referee/Extract.lean` seeds each
  standalone file from and which therefore has to stay closed over proofs; `meaningDeps` additionally
  drops the proofs *inside* a definition's value (`MeaningGraph.dataValueConstants`) and drives
  everything the reader is shown — the dependency graph, the upstream-trust analysis, the audit
  closure and its reading queues, and the revision diff — because a lemma called only by a bundled
  structure's `left_inv` obligation is not part of what the definition means or of what a reader
  must trust. `sorry` status is a single transitive flag (`dependsOnSorry`) obtained from
  `Lean.collectAxioms`, i.e. the same answer `#print axioms` gives. `@[specifies]` annotations are
  read here too and reversed by `attachSpecifiedBy`, the one field on `DeclInfo` that is not derived
  from the environment but taken from the author.

  It also builds `externalDecls`, the upstream constants the project's statements name — with each
  one's signature, its value or fields, and its docstring, so a graph node can be read without
  leaving the site — and walks each upstream package's own internal edges under the
  `maxExpandedPackage` budget, which is what lets an unaudited dependency be drawn with structure
  rather than as a flat list. `collect` cannot consult `--trust` (a render-time flag), so it walks
  every package and abandons the ones that do not fit. See [upstream trust](trust.md).
- `Referee/Provenance.lean` — the provenance ledger (`--provenance`). The fold is pure — ledger,
  revision, declarations in; ledger out — and unit-tested in `Test/Provenance.lean`, which matters
  more here than elsewhere because the file is append-only: a fold that records a change where none
  happened writes that into the record for good. The git reading (`blame`, `log`, `describe`) is
  the only part that shells out, and it is one `git blame` per *file* rather than per declaration.
- `Referee/Audit.lean` — the payloads the claims page, the landing page's excerpt of it and the
  per-declaration control hand to `assets/audit.js`, plus `dataFingerprint`, the stamp an exported
  audit file carries so it can be matched against the build it was made against. The verdicts,
  coverage, queue, import and export are all the browser's; this is only the data they run on.
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
  elaboration errors. Depends on Lean and SubVerso only — it knows nothing about the site. `declCode`
  is the exception to "one command in, one command out": it trims a command down to what a
  declaration *card* shows — no docstring, since the card renders that above the code, and no leading
  blank lines. Pure, and unit-tested in `Test/Highlight.lean`; a whole extracted file is rendered
  from the untrimmed highlighting.
- `Referee/Website/Site.lean` — Verso page construction and the CLI subcommands. The site's
  CSS and JavaScript live in `Referee/Website/assets/` as real files and are embedded with
  `include_str`. D3 is vendored there too rather than fetched from a CDN at page load. Everything
  specification-related is gated on `SiteContext.usesSpecs`, so a project that does not annotate
  gets exactly the site it got before the feature existed — and the same gating, on its own flag,
  covers trust, revisions, semantic hashes and provenance.
- `Test/` — `#guard`-based unit tests (`lake build Test`), split the same way as the code they
  cover: `Test/Collect.lean` and `Test/Extract.lean` for this tool, `Test/Diff.lean` and
  `Test/Provenance.lean` for the two pure comparison passes, `Test/Audit.lean` for the audit
  payloads, and `Test/Spec.lean` for the `@[specifies]` attribute — the annotations it records, read
  back out of the environment, with each rejection pinned by `#guard_msgs`, since those messages are
  the attribute's entire user interface.

  The pure passes are where the tests earn the most. `Referee/Diff.lean` and
  `Referee/Provenance.lean` are functions from data to data with no environment and no notion of a
  page, so exhaustive testing is cheap — and for provenance it is close to required, because the
  ledger is append-only and a fold that records a change where none happened writes that into the
  record for good.
- `Proofs/` — theorems about the library (`lake build Proofs`), where `Test/` has examples. Today it
  covers the two pure comparison passes. `Proofs/Diff.lean`: the relations between `ChangeKind`'s
  four predicates, the `fullyHashed` guard on the churn heuristic, and that `normalizeSpace` is a
  genuine canonical form rather than merely a shorter string. `Proofs/Collect.lean`: the forward-pass
  discipline of the `data.json` decoder — and the two `sizeOf` lemmas that let `intern`/`resolve`
  stop being `partial` at all, which is what makes any of it provable. `Proofs/Provenance.lean`: that the
  ledger's fold records no change where none happened, reports no more changes than declarations,
  forgets nothing, and appends without rewriting — the invariants that matter because the ledger is
  the one artifact here that a later build cannot correct. The two answer different questions and
  fail differently — a
  `#guard` regression says one input now behaves differently, a broken proof says a claim the
  documentation makes has stopped being true. What is proved, what is not, and why, is in
  [What of this could be proved correct](design/VERIFICATION.md).

Both are built by CI (`.github/workflows/lean_action_ci.yml`) as an explicit step, because neither
is a default Lake target and so neither is covered by a plain `lake build`.

Between the two sits `CollectedData.integrityViolations`, which is neither: it restates what
`MeaningGraph`'s `Proofs.lean` proves about the closure-building *functions* as assertions on the
*decoded* `data.json`, and `build-site` fails rather than render data that violates them. The proofs
stop at `toJson`; the file, the interning and the parse are unproved, so the properties have to be
re-checked where the renderer actually holds the value. See [What of this could be proved
correct](design/VERIFICATION.md).


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

Three things worth knowing:

- The assets are declared as a Lake `input_dir` in `lakefile.lean`, with `needs := #[websiteAssets]`
  on the library. Without that, `include_str` is invisible to Lake's change detection and
  `lake build` reports success while silently keeping the stale `.olean` — the site then builds from
  the *previous* version of the file.
- `sync-assets.sh` patches an already-built site only. The binary still embeds whatever was there at
  build time, so re-run `lake build` before generating a site you intend to publish.
- **`upstream.js` is not an asset.** It is generated per project from `CollectedData.externalDecls`,
  so it does not live in `assets/` and `sync-assets.sh` neither copies nor clobbers it. Changing what
  goes into it means a `build-site`, not a sync.
