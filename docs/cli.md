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
| `--baseline PATH` | `build-site` | An earlier `collect` output to compare against. See [comparing revisions](revisions.md) |
| `--baseline-label S` | `build-site` | What to call that baseline on the page (default: its file name) |
| `--provenance PATH` | `provenance`, `build-site` | The ledger: written and extended by the subcommand, read by the site. See [provenance](provenance.md) |
| `--jobs N` | the highlight phases | Worker processes (default: the CPU count) |

Each of `--trust`, `--baseline` and `--provenance` is gated: omit it and the site says nothing on
that subject at all — no page, no column, no badge. That is deliberate and uniform, so a site never
implies it has checked something it was not asked about.

**`--jobs` deserves care.** The CPU-count default is usually too many on a Mathlib-based project:
each worker imports Mathlib into its own multi-gigabyte process, so the default fans out to as many
of those as you have cores and can exhaust a large machine's memory. Size it against available RAM,
not cores.
