# Referee documentation

Start at the [top-level README](../README.md) for what the tool is and a working invocation. These
pages are the detail behind it.

## Using it

- **[The pipeline](pipeline.md)** — the phases, what each produces, and the boundary the whole
  design turns on: everything needing a Lean environment produces *data*, and rendering is a pure
  function of that data.
- **[CLI reference](cli.md)** — every subcommand and flag, and which phase reads it.
- **[Authoring a library for Referee](authoring.md)** — the two things no analysis of the
  environment can recover, so they are yours to state: `theorem` versus `lemma`, and `@[specifies]`.
- **[Extracted files](extraction.md)** — the self-contained minimal file per declaration, how to
  check it compiles, and the `extract-flat` fallback for when the readable one does not.
- **[Running in CI](ci.md)** — the job shape for another Lean repository, and the two pieces of
  state that have to survive between runs before revisions and provenance work at all.

## What the site reports

- **[Upstream trust](trust.md)** — `--trust`, why a trust dependency is a *definition a statement is
  about* rather than anything a proof calls, and the three things that bound what the analysis
  claims.
- **[Claims and audit state](audit.md)** — the one page carrying both: what the library states with
  `theorem`, and against each one the verdicts, derived coverage, reading queues, export and import.
  Also the three limits, which the page states to the reader rather than burying here.
- **[Comparing revisions](revisions.md)** — `--baseline`: what changed since a revision, classified
  by whether a reader has to look again.
- **[Semantic hashes](semantic-hashes.md)** — `--hashes`: comparing elaborated structure instead of
  pretty-printed text. Optional, and the thing that makes a toolchain upgrade a non-event.
- **[Provenance](provenance.md)** — `--provenance`: when each declaration's meaning last changed,
  kept strictly apart from when its file was last edited.

Those four interlock: hashes are the measure, revisions compare two builds with it, provenance
records it over many, and audit state uses it to tell a reader which of their own acceptances have
gone stale. Any of them can be left out, and then the site says nothing about it at all — that
gating is deliberate and consistent.

## Working on the tool

- **[Working on Referee](development.md)** — code layout, the theme, and patching a built site's CSS
  and JS without rebuilding.
- **[Prebuilt binaries](releases.md)** — what CI publishes and how to consume it downstream.

## Design notes

In [design/](design/), and a different kind of document: they argue about what the tool should be
rather than explain what it does.

- **[PROPOSED-TOOLS.md](design/PROPOSED-TOOLS.md)** — candidate additions, ranked, with what each
  would cost given the architecture. Also what was deliberately rejected, and why.
- **[TRUST-GAPS.md](design/TRUST-GAPS.md)** — auditing this repository does not cover at all,
  organised by how a thing builds trust rather than by feature.
- **[WEBSITE-DESIGN.md](design/WEBSITE-DESIGN.md)** — the site's structure and the principles it is
  built on.

[`KNOWN-ISSUES.md`](../KNOWN-ISSUES.md) stays at the repository root: it is a record of what does
not currently work, not an argument.
