# The pipeline

The target repo must already have current `.olean` files for the modules you want to expose.

The pipeline is a sequence of phases with one hard boundary: everything that needs a Lean
environment produces **data**, and rendering is a pure function of that data.

| phase | needs `lake env`? | produces |
|---|---|---|
| `collect` | yes | `data.json` — declarations, *direct* dependencies, docstrings, axioms, `sorry` status, and (given `--hashes`) semantic hashes. Transitive closures are deliberately not stored: every consumer recomputes them from the direct edges on load, because materialized closures dominated both the file and `collect`'s memory at scale |
| `provenance` | no (needs git) | `provenance.json` — when each declaration's meaning last changed, and where its source was last edited |
| `extract` | yes | `extracted/*.lean` — the self-contained minimal file per declaration |
| `highlight` | yes | `highlighting/*.json` — interactive Lean for each project module |
| `highlight-extracted` | yes | `extracted-highlighting/*.json` — interactive Lean for each minimal file, **and whether it compiles** |
| `build-site` | no | the Verso HTML site |

`collect` is also the phase that reads the project root itself: `README.md` for the landing page's
overview, and `formalization.yaml` — when there is one — for the [Claims](claims.md) page. Both go
into `data.json`, because `build-site` runs from that file alone and never sees the project
directory.

`build-site` touches nothing but those files, so it can be re-run as many times as you like —
e.g. while iterating on page layout or CSS — without re-importing the target project.

```bash
cd /path/to/target-repo
lake exe cache get
lake build MyLibrary

REFEREE=/path/to/referee/.lake/build/bin/referee
OUT=/path/to/site-out

lake env "$REFEREE" collect --root MyLibrary --data data.json

lake env "$REFEREE" extract --data data.json --output "$OUT"

# Interactive Lean: hover a symbol for its type, click to jump to its definition.
lake env "$REFEREE" highlight --data data.json --output "$OUT"
lake env "$REFEREE" highlight-extracted --output "$OUT"

"$REFEREE" build-site --data data.json --output "$OUT" \
  --repo-url https://github.com/owner/repo \
  --site-url https://owner.github.io/repo
```

Both highlighting phases fan out one worker process per file, because highlighting must elaborate
source against a freshly imported environment. They are optional: without them `build-site` renders
plain code blocks and omits the inline minimal files, and says so.

**`--jobs N` defaults to the CPU count, and on a Mathlib-based project that is usually too many.**
Each worker imports Mathlib into its own process, several GB apiece, so the default fans out to as
many multi-gigabyte processes as you have cores and can exhaust the memory of a large machine. Size
it against available RAM rather than against cores; `--jobs 2` or `3` is a reasonable ceiling on a
workstation. `highlight-extracted` is much the more expensive of the two, since it elaborates one
file per declaration rather than per module.

`highlight-extracted` doubles as the compile check for the extracted files. Producing the
highlighting *is* an elaboration, so the same pass records which minimal files fail — and the site
reports that on the declaration's own page rather than presenting unverified output as verified.
This subsumes what `scripts/check-extracted-compile.sh` does for site-building purposes; the script
remains useful for checking extraction in isolation.

`build-site` has no environment or project dependency at all, and `provenance` needs only a git
working tree, so those two are the phases that run anywhere. `--repo-url`/`--site-url`/`--title`
only affect `build-site`'s output, so the same `data.json` can be rendered with different values
for those without re-running `collect`.

Two more subcommands are not in the table: [`extract-flat`](extraction.md), the fallback extraction,
and `highlight-module` / `highlight-file`, which are the worker processes the two highlighting
phases fan out to rather than anything to invoke yourself.

For the previous one-shot behavior (no JSON round-trip), use `all`, or omit the subcommand entirely
— a bare invocation defaults to `all` for backward compatibility. It runs `collect`, `extract` and
`build-site` in one process, and **not** the highlighting phases:

```bash
lake env "$REFEREE" all \
  --root MyLibrary \
  --repo-url https://github.com/owner/repo \
  --site-url https://owner.github.io/repo \
  --output /path/to/site-out
```

Verso writes the site into the chosen output directory, typically under `html-multi/`.
