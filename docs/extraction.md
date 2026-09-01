# Extracted files

## Verifying Extracted Files Compile

Each file under `extracted/` is self-contained (it inlines its transitive dependencies and
replaces theorem proofs with `sorry`), and its header imports the project's external dependency
frontier — less `Characterization`, whose `@[specifies]` annotations the extraction strips, so
nothing in the file needs it and the web editor (which has Mathlib and nothing else) is not asked
for a package it cannot resolve.

## Opening one in the web editor

`--site-url` puts an "open in web editor" link on every declaration, pointing at
[live.lean-lang.org](https://live.lean-lang.org) and preloaded — via that editor's `#url=`
parameter — with the declaration's extracted file, fetched from
`<site-url>/extracted/<id>.lean`.

So the URL has to be **where the site is actually published**, not where it is being built: the
editor fetches the `.lean` file over the network from a reader's browser, and a value that is merely
plausible produces links that load an empty editor. Omit the flag to skip the links; the
`extracted/` files are written either way.

## Checking they compile

Nothing checks that a file actually compiles until something tries to.
`scripts/check-extracted-compile.sh` does that check: it runs `lake env lean` on every extracted
`.lean` file from inside the target project (so imports like Mathlib resolve), in parallel, and
reports which files fail with their error output.

```bash
scripts/check-extracted-compile.sh /path/to/target-repo /path/to/site-out/html-multi/extracted
```

The third, optional argument caps how many files are checked in parallel (defaults to the
number of CPUs). The script exits non-zero if any file fails to compile.

A small number of extracted files are known not to compile. [`KNOWN-ISSUES.md`](../KNOWN-ISSUES.md)
records the current pass rate across the projects this is tested against, the root cause of each
remaining failure, and — importantly — the approaches that were tried and measured to be worse, so
they are not retried.

## Fallback Extraction (`extract-flat`)

`extract` optimizes for a file a mathematician can read: it copies verbatim source text and
replays the surrounding `namespace`/`open`/`variable`/notation context. That context replay is
also where it fails.

`extract-flat` is a second, independent extraction path that gives up readability to gain
robustness. It never reads a source file: each declaration is rendered from its `ConstantInfo` in
the compiled environment, fully qualified and `@`-explicit, with proofs replaced by `sorry`.
Nothing has to be replayed — no `variable` binders, no namespaces, no notation, no attributes —
and no instance is ever synthesized, so the entire class of context-replay failures disappears.

```bash
lake env "$REFEREE" extract-flat --data data.json --output /path/to/site-out
```

It takes the same inputs as `extract` and writes to `html-multi/extracted-flat/`, so both tiers can
be produced from one `collect` and compared:

```bash
scripts/check-extracted-compile.sh /path/to/target-repo /path/to/site-out/html-multi/extracted-flat
```

The intended use is as a fallback: prefer `extract`'s output, and substitute the `extract-flat`
file for the declarations whose readable version does not compile. See
[`KNOWN-ISSUES.md`](../KNOWN-ISSUES.md) for its measured pass rate and its own failure modes.
