# Command-line reference

## Subcommands

| | needs `lake env`? | |
|---|---|---|
| `collect` | yes | Import the project and write `data.json`, plus what the project root holds: `README.md`, and `formalization.yaml` if present. See [the pipeline](pipeline.md) |
| `provenance` | no (needs git) | Fold this revision into the ledger. See [provenance](provenance.md) |
| `extract` | yes | Write the standalone minimal `.lean` file per declaration |
| `extract-flat` | yes | The [fallback extraction](extraction.md): robust, unreadable |
| `highlight-extracted` | yes | Interactive Lean per minimal file, and whether it compiles |
| `build-site` | no | Render the site |
| `all` | yes | `collect` + `extract` + `build-site` in one process, no JSON round-trip. The default when no subcommand is given |

`highlight-file` also exists; it is the worker process `highlight-extracted` fans out to, not a
command to run yourself.

## Options

Which phase reads a flag is worth knowing, because it decides what a change costs: anything read by
`build-site` alone can be varied over the same `data.json` without re-importing the project.

| flag | read by | |
|---|---|---|
| `--root PREFIX` | the phases that import | Root module prefix to expose (default: the first root library) |
| `--data PATH` | all but `highlight-extracted` | The collected-data file: written by `collect`, read by everything downstream |
| `--output DIR` | the phases that write files | Output directory, passed through to Verso |
| `--exclude-lib NAME` | the phases that import | A root library to skip when importing the project |
| `--hashes PATH` | `collect` | JSONL from `semantic_hash export`. A property of the environment, so it is stored in `data.json` rather than passed at render time. See [semantic hashes](semantic-hashes.md) |
| `--ref NAME` | `provenance` | What to call this revision in the ledger (default: `git describe --tags --always`) |
| `--repo-url URL` | `build-site` | Base GitHub URL for source and issue links |
| `--site-url URL` | `build-site` | Where the site will be published. Adds web-editor links, and must be the real published URL — see [extracted files](extraction.md) |
| `--title TITLE` | `build-site` | Override the site title |
| `--trust PKG` | `build-site` | Treat a package and everything it depends on as audited. Repeatable. See [upstream trust](trust.md) |
| `--show-trusted-upstream` | `build-site` | Also draw audited packages in each graph's upstream band. Off by default; unaudited packages are always drawn. See [upstream trust](trust.md#audited-packages---show-trusted-upstream) |
| `--baseline PATH` | `build-site` | An earlier `collect` output to compare against. See [comparing revisions](revisions.md) |
| `--baseline-label S` | `build-site` | What to call that baseline on the page (default: its file name) |
| `--provenance PATH` | `provenance`, `build-site` | The ledger: written and extended by the subcommand, read by the site. See [provenance](provenance.md) |
| `--jobs N` | `highlight-extracted` | Worker processes (default: the CPU count) |
| `--per-chapter` | `build-site` | Render one chapter at a time, bounding peak memory by the largest chapter instead of the whole library. See [below](#--per-chapter) |

Each of `--trust`, `--baseline` and `--provenance` is gated: omit it and the site says nothing on
that subject at all — no page, no column, no badge. That is deliberate and uniform, so a site never
implies it has checked something it was not asked about.

## No search box

Verso indexes the full text of every page and loads that index eagerly from *every* page. That is
right for a manual and wrong for a library: the index is the largest single artifact on the site,
and it answers a question nobody asks of a library — what a reader wants to find is a name.

The numbers are why this is not a flag. On 859 declarations the full-text index is 14.05 MB against
3 kB with search off. On the 28,381-declaration `Mathlib.Analysis` site `searchIndex.js` is **33.5
MB gzipped**, against about 0.5 MB for everything else that page fetches, and an index over titles
alone — the best a narrowing rewrite ever managed — is still 1.88 MB and projects past 20 MB per
page view at Mathlib's full scope.

So `build-site` clears Verso's `search` feature, which stops the index from ever being built, and
strips the asset tags Verso's page template emits regardless. Verso builds the box in JavaScript
and writes no markup for it, so a page that loads none of `-verso-search/` has none, and Verso's
own search page is never emitted. What a reader keeps is Browse, which lists every declaration and
costs nothing until it is opened.

## Hoisted assets

Verso inlines the theme's stylesheet and the genre's scripts into every page. Measured on an
859-declaration site, that is **74.2% of a declaration page** — 37.8 kB of CSS and 20.2 kB of script
against 16.4 kB of content — repeated byte-for-byte on every page.

`build-site` therefore lifts the shared blocks into content-addressed files under `-verso-data/` and
references them, which took that site from 96 MB to 54 MB. This is unconditional, and it is safe to
be: the transform removes only duplication, and re-inlining the assets reproduces each page
byte-for-byte.

Only attribute-less `<style>` and `<script>` blocks that occur on more than one page and exceed
512 bytes are hoisted, which is what keeps the per-page `graph-data` and `audit-control` payloads —
read back out of the DOM by the scripts that need them — untouched.

## `--per-chapter`

Verso builds the whole document tree before writing any page, so a monolithic `build-site`'s peak
memory tracks the library: measured 14.95 GB at 28,251 declarations, projected past 150 GB at
Mathlib's 304,210. `--per-chapter` runs Verso once per chapter plus once for the whole-library
pages, all into the same output directory, and stitches together what Verso derives from its tree —
sidebar, chapter numbering, prev/next seams, `xref.json`, the `find` page, hover data. Measured on
the same 28,251-declaration site:

| | monolithic | `--per-chapter` |
|---|---|---|
| peak RSS | 14.95 GB | **4.47 GB** |
| wall time | 13 m 52 s | **12 m 28 s** |
| site | 4.0 GB | 4.0 GB |

The output is byte-identical to the monolithic build except for two disclosed residuals:
`xref.json`'s degenerate `[anonymous]` entry, and — the one that matters — **definition links in
highlighted code that cross chapters degrade to hover-only tokens**, because Verso's definition-site registry does not
span runs. The token keeps its hover and the declaration card's own dependency links still reach
the definition; how many pages carry a degraded token depends on how much the chapters lean on one
another (1% on `Mathlib.Dynamics`, half the pages on `Mathlib.Analysis`).

**`--jobs` deserves care.** The CPU-count default is usually too many on a Mathlib-based project:
each worker imports Mathlib into its own multi-gigabyte process, so the default fans out to as many
of those as you have cores and can exhaust a large machine's memory. Size it against available RAM,
not cores.
