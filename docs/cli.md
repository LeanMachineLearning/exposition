# Command-line reference

## Subcommands

| | needs `lake env`? | |
|---|---|---|
| `collect` | yes | Import the project and write `data.json`. See [the pipeline](pipeline.md) |
| `provenance` | no (needs git) | Fold this revision into the ledger. See [provenance](provenance.md) |
| `extract` | yes | Write the standalone minimal `.lean` file per declaration |
| `extract-flat` | yes | The [fallback extraction](extraction.md): robust, unreadable |
| `highlight` | yes | Interactive Lean per project module |
| `highlight-extracted` | yes | Interactive Lean per minimal file, and whether it compiles |
| `build-site` | no | Render the site |
| `all` | yes | `collect` + `extract` + `build-site` in one process, no JSON round-trip. The default when no subcommand is given |

`highlight-module` and `highlight-file` also exist; they are the worker processes the two
highlighting phases fan out to, not commands to run yourself.

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
| `--jobs N` | the highlight phases | Worker processes (default: the CPU count) |
| `--search MODE` | `build-site` | What the search index covers: `full` (default), `names`, or `none`. See [below](#--search) |
| `--no-hoist-assets` | `build-site` | Keep Verso's inline CSS and JavaScript in every page instead of lifting the shared blocks into files. See [below](#--no-hoist-assets) |
| `--per-chapter` | `build-site` | Render one chapter at a time, bounding peak memory by the largest chapter instead of the whole library. Requires `--search names` or `none`. See [below](#--per-chapter) |

Each of `--trust`, `--baseline` and `--provenance` is gated: omit it and the site says nothing on
that subject at all — no page, no column, no badge. That is deliberate and uniform, so a site never
implies it has checked something it was not asked about.

## `--search`

Verso indexes the full text of every page, which is right for a manual and wrong for a library: the
index is the largest single artifact on the site, it is loaded eagerly by *every* page, and it
answers a question nobody asks of a library. What a reader wants to find is a name.

| mode | what is indexed | measured on 859 declarations |
|---|---|---|
| `full` (default) | every page's full text | 14.05 MB |
| `names` | page titles — declaration and module names | **0.73 MB** |
| `none` | nothing; the box stays and finds nothing | 3 kB |

`names` changes only what the inverted index is built over. Verso splits its search output in two —
an eagerly-loaded `searchIndex.js` holding the index, and per-bucket files holding each document's
stored fields, fetched only when a result is shown — and only the first is rewritten. Results keep
their real titles, breadcrumbs and excerpts, and every link still resolves.

The 19× is larger than swapping prose for titles alone accounts for. Verso's `Index.addDoc` carries
its running token-frequency map across fields without resetting it, and it indexes the `id` field
even though the guard meant to skip the reference compares a field *name* against the reference
*value*. The upshot is that every page's URL is tokenized into all three fields. Nothing queries
`id` — `search-box.js` boosts `header` and `contents` and nothing else — so `names` passes it the
empty string, and the URL tokens leave all three fields at once.

`none` is for publishing somewhere the index cannot be hosted. It is not a way to make search
better: the box remains and matches nothing.

## `--no-hoist-assets`

Verso inlines the theme's stylesheet and the genre's scripts into every page. Measured on the same
859-declaration site, that is **74.2% of a declaration page** — 37.8 kB of CSS and 20.2 kB of script
against 16.4 kB of content — repeated byte-for-byte on every page.

`build-site` therefore lifts the shared blocks into content-addressed files under `-verso-data/` and
references them, which took that site from 96 MB to 54 MB. It is on by default because it removes
only duplication: re-inlining the assets reproduces each page byte-for-byte.

Only attribute-less `<style>` and `<script>` blocks that occur on more than one page and exceed
512 bytes are hoisted, which is what keeps the per-page `graph-data` and `audit-control` payloads —
read back out of the DOM by the scripts that need them — untouched.

Pass `--no-hoist-assets` when one self-contained file per page matters more than its size, such as
an archive, or a host that cannot serve the assets alongside.

## `--per-chapter`

Verso builds the whole document tree before writing any page, so a monolithic `build-site`'s peak
memory tracks the library: measured 14.95 GB at 28,251 declarations, projected past 150 GB at
Mathlib's 304,210. `--per-chapter` runs Verso once per chapter plus once for the whole-library
pages, all into the same output directory, and stitches together what Verso derives from its tree —
sidebar, chapter numbering, prev/next seams, `xref.json`, the `find` page, search buckets, hover
data. Measured on the same 28,251-declaration site:

| | monolithic | `--per-chapter` |
|---|---|---|
| peak RSS | 14.95 GB | **4.47 GB** |
| wall time | 13 m 52 s | **12 m 28 s** |
| site | 4.0 GB | 4.0 GB |

The output is byte-identical to the monolithic build except for three disclosed residuals: the
search bucket version hash (the index payload itself is byte-identical), `xref.json`'s degenerate
`[anonymous]` entry, and — the one that matters — **definition links in highlighted code that
cross chapters degrade to hover-only tokens**, because Verso's definition-site registry does not
span runs. The token keeps its hover and the declaration card's own dependency links still reach
the definition; how many pages carry a degraded token depends on how much the chapters lean on one
another (1% on `Mathlib.Dynamics`, half the pages on `Mathlib.Analysis`).

Requires `--search names` or `none`: merging the full-text inverted indexes of separate runs would
mean re-indexing the library, and at the scale where this flag matters the full index was never
viable anyway.

**`--jobs` deserves care.** The CPU-count default is usually too many on a Mathlib-based project:
each worker imports Mathlib into its own multi-gigabyte process, so the default fans out to as many
of those as you have cores and can exhaust a large machine's memory. Size it against available RAM,
not cores.
