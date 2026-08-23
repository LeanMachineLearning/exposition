# Referee at Mathlib scale

What breaks when the target is Mathlib itself rather than a project built on it, ranked by leverage
per unit of work, with every cost measured rather than guessed. Written as a menu to argue with:
nothing here is committed to, and the recommendation near the end argues that for a browsing site
the cheapest answer may be to build no single site at all.

The framing observation, in its corrected form — an earlier draft had it wrong, and the correction
is recorded under *What is not a problem*. There are two independent walls, and they break different
phases. The **site** is broken by costs that scale with the page count and have nothing to do with
dependency analysis: three quarters of every declaration page was byte-identical boilerplate, and
the search index was full-text prose. Both are fixed (Tier A), and building the later rounds
exposed a third site cost neither had touched — pages carrying their own closures — which is the
second round's item 9. The **data phase** is broken by
exactly the thing the architecture was already being careful about: closure size. `AuditData`
interns closure names, `extract` caps oversized definition values, the trust analysis refuses to
expand Mathlib — and none of that reaches the root cause, which is that `collect` materializes
every declaration's transitive closure and stores all of them. Measured with `LeanDeps` semantics,
closures are **69.9% of `data.json`** at 28,251 declarations and their share still grows with
scope: an estimated one **billion** closure entries for the whole library, roughly 300 times the
direct edges they are derived from. That is Tier C item 5, and it is the precondition for the rest.

What memory each phase wants for the whole library, with items 5 and 8 built and their projections
anchored on measured runs: `collect` about **60–70 GB** (was ~370 GB), `build-site` about
**45–55 GB** (was ~161 GB). Both now fit the same class of large workstation. **A whole-Mathlib
audit site has stopped being impossible and become an overnight job on one big machine.** What that
job produces is another matter: modeled by mechanism rather than curve-fitted, the site itself
comes out at **~120–180 GB** — see item 9, which exists to fix exactly that — so the remaining work
has moved from the build to what it builds.

Where the whole thing stands, scaled from the measured 28,251-declaration `Mathlib.Analysis` runs:

| | before | built (Tier A, items 5 and 8) | after the second round (items 9–14) |
|---|---|---|---|
| `searchIndex.js` | ~5.0 GB | **~230 MB** | tens of MB eager, or none (item 10) |
| total site | ~130–190 GB | **~120–180 GB** † | ~10–15 GB (item 9) |
| average declaration page | ~650 kB | **~600 kB** † | ~30–50 kB (item 9) |
| `find` / `browse` / `claims` | 350 / 142 / ~400 MB | unchanged | < 5 MB each (items 3, 9) |
| hover data fetched per page view | ~120 MB | unchanged | 2–5 MB (item 10) |
| `data.json` | ~19–21 GB | **~2.9 GB** | largest chapter at a time (item 12) |
| `collect` peak RSS | ~370 GB | **~60–70 GB** | ~10–20 GB (item 12) |
| `collect` wall time | superlinear, 11 h+ | **~6 h** | ~1–1.5 h (item 13) |
| `build-site` peak RSS | ~161 GB | **~45–55 GB** (`--per-chapter`) | ~10–25 GB (items 11, 12) |
| `highlight` | ~4 days | unchanged | ~4–8 h (item 6) |

† An earlier draft printed ~43 GB and ~148 kB in this column, extrapolated through the two measured
runs. Item 9 explains why that fit under-projects: once closures dominate a page, page size tracks
closure size — which grows at ~n^0.67 — rather than the fitted n^0.33, and the mechanistic estimate
is three to four times the fit. The measured 28k numbers are untouched; only the 304,210 projection
moves.

**Tier A solved exactly one of these, and solved it completely.** The search index is now the only
artifact on the site whose cost per declaration does *not* grow with the size of the library: it
measured 0.87 kB per declaration on an 859-declaration subtree and 0.76 kB on a 28,251-declaration
one, because names do not get longer when there are more of them. Everything else on this list gets
*worse* per declaration as scope grows, because closures widen — page bytes went from 47.7 kB to
148.5 kB per declaration between the same two runs. That growth is why the site total in the middle
column dwarfs the ~14 GB the first draft projected from the small run alone — and why item 9, which
takes the closure payload out of the pages, is the second round's first move.

## What was measured

Workstation: 32 cores, 62 GB RAM. Mathlib at `leanprover/lean4:v4.34.0-rc1`, 6.0 GB of `.olean`,
8,325 modules, 2.29 M lines.

| | |
|---|---|
| Total constants | 571,117 |
| **Exposed by `shouldExpose`** | **304,210** — 245,927 theorems, 58,283 defs/instances/etc. |
| Direct edges, `Expr.getUsedConstants` proxy | 3,225,186 (mean out-degree 10.6) |
| Closure names per declaration, `LeanDeps` semantics | **668** at 28,251 decls, and growing with scope |
| Projected total closure entries at 304,210 | **~1.0 billion** |

A caution that governs every closure number in this document. An early sample computed closures
with `Expr.getUsedConstants` and got a mean of 119 per declaration, which looked like the same
regime as `brownian-motion`'s 70 and led this document to declare closures a non-problem. The
real closures — read back out of what `collect` itself wrote — have mean **668** at 28,251
declarations, and their per-declaration count grows with the size of the exposed set (63.7 at 859
declarations, 668 at 28,251; log-log slope ≈ 0.67, hence ~3,300 projected at 304,210). The proxy
was off by an order of magnitude *and* blind to the growth, because `LeanDeps` deliberately
recovers what an elaborated term drops — compiler helpers, `Expr.proj` structures, notation
expansions, coercion instances — and at Mathlib scope those dominate the closure. Measure with the
tool's own semantics or not at all.

The pipeline is therefore superlinear in declaration count, though far from quadratic: per-artifact
exponents measured between the two runs sit around n^1.3 for the site and n^1.7 for closure data.

### Two `collect`s, and the slope between them

| `--root` | declarations | wall time | peak RSS | `data.json` |
|---|---|---|---|---|
| `Mathlib.Dynamics` | 859 | 3 m 25 s | 4.03 GB | 5.84 MB (6.6 KB/decl) |
| `Mathlib.Analysis` | 28,251 | **1 h 02 m 26 s** | **12.8 GB** | **574 MB** (19.8 KB/decl) |

A bare `importModules` plus a full constant walk costs 3 m 45 s on its own. On the small run that is
essentially the entire cost, which makes it a trap: a single subtree of a thousand declarations says
nothing about the slope, because the fixed import hides it. The second run is what exposes it.

| | extrapolated to 304,210 | fit |
|---|---|---|
| Wall time | **~11 h** | linear in declarations; treat as a floor |
| Peak RSS | **~370 GB** | closure growth × the measured 19× in-memory amplification |
| `data.json` | **~19 GB** | closure growth at 18.5 B per stored closure name |

A straight line through the two runs gives ~97 GB and ~5.9 GB, and an earlier draft printed those
numbers. They are wrong, because per-declaration cost is not constant: closures per declaration
grow with the exposed set (63.7 → 668 between the runs), so the curve bends upward and the linear
fit reads far below it. The projections above follow the measured growth instead. They are still
extrapolations from two points — but the direction of the error in the linear fit is not in doubt.

**`collect` is the phase that does not fit, by a factor of six against even a large workstation.**
Item 5 below — not materializing the closures — is therefore not a nicety but the precondition for
a whole-Mathlib run existing at all.

The import is at least a fixed cost: `--root Mathlib.Dynamics` still imports all of Mathlib, so a
subtree pays it in full and then scales from there.

The closures each run actually wrote — the growth between these two columns is the central fact of
this document:

| | 859 decls (mean) | 28,251 decls (mean) | 28,251 p90 / max |
|---|---|---|---|
| `transDeps` | 34.0 | **396.2** | 798 / 2,358 |
| `dataTransDeps` | 29.7 | **271.9** | 542 / 1,318 |
| stored closure entries total | 54,719 | **18.9 M** | |

And where `data.json`'s bytes go, measured with shared (interned) subtrees counted once:

| | at 859 decls | at 28,251 decls |
|---|---|---|
| **closures** (`transDeps` + `dataTransDeps`) | 16.1% | **69.9%** (12.3 kB/decl) |
| direct edges (`deps`, `typeDeps`, `dataDeps`) | 20.0% | 12.6% |
| docstrings | 31.6% | 7.2% |
| source and proof text | 16.5% | 4.6% |
| everything else | 15.8% | 5.6% |

Everything except the closures is flat per declaration; the closures grow. At the small scale where
measuring is comfortable they are a sixth of the file, which is precisely why they looked ignorable
— the share itself is what scope changes.

Worth recording separately: `collect` on Mathlib **fails outright** without
`--exclude-lib Cache --exclude-lib MathlibTest --exclude-lib Archive --exclude-lib Counterexamples
--exclude-lib Wanted --exclude-lib docs`, with `object file '.../Cache.olean' of module Cache does
not exist`. Mathlib declares seven libraries and a normal checkout builds one of them.

### One `build-site`, end to end

The same data through `build-site`, with neither `highlight` nor `extract`:

| | |
|---|---|
| Wall time | **5.86 s** |
| Peak RSS | **231 MB** |
| Site | **96 MB** over 911 pages |

And where those bytes go — 859 declaration pages, 65.6 MB, averaging 78.2 KB each:

| | per page | share |
|---|---|---|
| Inline CSS | 37.8 KB | **48.3%** |
| Inline JS | 20.2 KB | **25.9%** |
| `<nav>` | 3.7 KB | 4.8% |
| **Actual content** | **16.4 KB** | **21.0%** |

Plus the whole-library artifacts:

| | measured | per declaration |
|---|---|---|
| `-verso-search/searchIndex.js` | 14.05 MB | 16.7 KB |
| `find/index.html` | 0.99 MB | 1.18 KB |
| `xref.json` | 0.93 MB | 1.11 KB |
| `claims/index.html` | 0.60 MB | 0.71 KB |
| `browse/index.html` | 0.40 MB | 0.48 KB |

One thing already works and should not be lost in a rewrite: Verso reported *"Pruned the sidebar's
inherited sub-tables from 908 pages, saving 14 MB"*. The sidebar was the obvious candidate for
quadratic growth and it is already handled.

### The same at 33× the size

`build-site` on the 28,251-declaration `Mathlib.Analysis` data, with Tier A applied:

| | |
|---|---|
| Wall time | **14 m 08 s** |
| Peak RSS | **14.95 GB** |
| Site | **4.0 GB** over 29,086 pages |
| Sidebar prune | 1,128 MB saved |
| Asset hoisting | 1,366 MB saved, 4 shared blocks |
| Search index | **421 MB → 21 MB** |

Without Tier A the same site would have been 5.7 GB, so hoisting and the name index take 30% off it
— a smaller *fraction* than the 58% they take off the small site, because the boilerplate they
remove is a fixed 48 kB per page while the content around it grows.

This is the run that makes the per-declaration trend legible, and the trend is the whole story:

| | 859 decls | 28,251 decls | direction |
|---|---|---|---|
| site per declaration | 47.7 kB | **148.5 kB** | grows with scope |
| `data.json` per declaration | 6.6 kB | **19.8 kB** | grows with scope |
| search index per declaration | 0.87 kB | **0.76 kB** | flat |

Everything keyed to closures gets worse per declaration as the library grows, because closures
widen. The name index is the exception, and it is the exception *by construction*: a declaration's
name does not get longer when the library gets bigger. Fitting the middle column through to 304,210
gives a **43 GB** site — but the fit under-projects, because the growth's *mechanism* (item 9) puts
page size near-linear in closure size once closures dominate, for **~120–180 GB**. The search
index's **226 MB** stands on firmer ground: flat per declaration leaves no curve to misjudge. The
~161 GB of peak RSS this paragraph once projected has since been measured away by item 8.

## Tier A — the two changes that decide whether this is possible

**Both are built.** `--search` and `--no-hoist-assets` are documented in the
[CLI reference](../cli.md). On the 859-declaration site the two together took **96 MB to 40 MB**,
and the search index from **14.05 MB to 0.73 MB**; on the 28,251-declaration site, 5.7 GB to 4.0 GB
and 421 MB to 21 MB. Scaled to Mathlib that is roughly 60 GB → 43 GB and 5.0 GB → 230 MB. The
sections below keep the argument that motivated them; what each turned out to cost and to buy is
recorded at the end of each.

### 1. Stop inlining CSS and JS into every page

**74.2% of every declaration page is byte-identical boilerplate** — 58 KB of it, against 16.4 KB of
content. At 304,210 pages that is **17.6 GB of pure duplication**, and every navigation makes the
browser re-parse 58 KB it already has.

Emit them once and reference them. Verso is what inlines these, but this needs no fork: a pass over
`html-multi/` that lifts identical `<style>` and `<script>` blocks into shared files and substitutes
`<link>` and `<script src>` is a pure text transform, and it can assert the blocks really are
identical before hoisting. It belongs either behind a `build-site` flag or as a phase after it.

The reason this ranks first is that it is not a Mathlib change at all: every Referee site gets
smaller and faster, and `brownian-motion` pages are 74% boilerplate too.

**Built**, on by default, with `--no-hoist-assets` to opt out. Four blocks were shared across the
859-declaration site — two stylesheets of 23.5 kB and 14.3 kB, two scripts of 9.5 kB and 1.1 kB —
and lifting them took it from **96 MB to 54 MB**, a 44% cut, for 2.4 s of extra build time.

The transform is lossless, and that is checked rather than asserted: re-inlining the referenced
assets into 40 sampled pages reproduced each of them byte-for-byte, and the per-page `graph-data`
and `audit-control` payloads were untouched in every one.

### 2. Replace the full-text search index with a name index

`searchIndex.js` is 16.7 KB per declaration — Verso's elasticlunr index over full page prose,
**~5.0 GB** at Mathlib scale, `defer`-loaded by every page on the site. This is the binding
usability constraint and nothing else is close to it.

It is also answering the wrong question. Someone searching a library site is looking for a *name*,
not for a sentence.

**Built**, as `--search {full,names,none}`, defaulting to `full` so that no existing site changes
under anyone. On the 859-declaration site `names` took the index from **14.05 MB to 0.73 MB**, 19×,
or 16.7 kB per declaration down to 0.84 kB. On the 28,251-declaration site it was 421 MB down to
21 MB, at 0.76 kB per declaration — so the rate is flat, and Mathlib is about **230 MB** rather than
5 GB.

It turned out to need no new index format and no fork. Verso already splits its search output into
an eagerly-loaded `searchIndex.js` and lazily-fetched per-bucket files, so only the first is
rewritten and results keep their real titles, breadcrumbs, excerpts and links. Verso's own
`IndexBuilder` builds the replacement, so the on-disk shape is right by construction rather than by
imitation.

Two thirds of the 19× came from somewhere unexpected, and it is worth recording because it is a
cost every Verso search index carries. `Index.addDoc` accumulates its token-frequency map across
fields without resetting it between them, and it indexes the `id` field as well, because the guard
meant to skip the reference compares a field *name* against the reference *value* and so never
fires. Every page's 144-character URL is therefore tokenized into all three fields. Nothing queries
`id`, so passing it the empty string drops those postings from all three at once — 3.8 MB of index
became 0.76 MB.

That is also where the remaining floor is. Elasticlunr repeats the full document reference in every
posting, and these references are long, so the index cannot go far below ~0.8 kB per declaration
while the format and the URLs are what they are. Getting to the tens of megabytes would mean short
numeric document ids and a matcher of our own — a replacement of the search *implementation*, not of
its data, and a different change from this one.

**Together, items 1 and 2 take a fixed ~50 kB of duplication off every page and the search index
from 5 GB to ~230 MB.** The second is a complete fix; the first is a discount that shrinks with
scale, because the closure content it sits beside keeps growing — 58% of the small site, 30% at
28k, a sixth or less at the whole library. What neither touches is that growing closure content
itself, which is item 9's subject; nor the memory the phases needed, since brought down by items 5
and 8. See [the recommendation](#the-recommendation-after-measuring).

## Tier B — pages that build but that no browser will open

*Not built, and demoted by measurement.* At 28,251 declarations these pages came out at 29 MB
(`find`), 23 MB (`claims`) and 10 MB (`browse`) — heavy, but a browser will open them. They are
flat per declaration, so they only become fatal at monolith scale, which nothing else reaches
either. Do this after the memory work, not before it — and read both items as special cases of
item 9, which generalizes item 4's shared-table idea to every page and supplies the fetch-and-render
delivery item 3 needs.

### 3. Make `find`, `browse` and `claims` fetch their rows

Each puts every declaration into one HTML document: 350 MB, 142 MB and 400–600 MB projected. They
will build. They will not open.

Emit the rows as a JSON asset and ship a table shell that fetches and renders incrementally. Most of
the work exists — `browse.js` already filters and sorts client-side — so what changes is delivery,
not rendering. Partitioning by chapter is the cheaper half-measure and needs no client change at all.

### 4. Stop putting the whole library's closures on the claims page

`mkAuditData` emits every declaration's closure on one page. The code says so plainly, and interns
against a shared name table precisely because the payload is large — the docstring cites
`brownian-motion`'s 116,519 transitive edges as the reason. Against the hundreds of millions of
meaning-closure edges the whole library implies, that mitigation is not enough.

The fix is half-built already: `featured?` produces an excerpt cut to a set of declarations and
their closures, which is exactly the operation needed per chapter. The alternative is a shared
`closures.json` that `audit.js` fetches for the rows actually in view. The *encoding* is fine; only
the delivery is wrong.

## Tier C — the phases behind the site

*Items 5 and 8 are built; see their sections for the measured results. They were the two binding
constraints on a whole-Mathlib run — `collect` projected at ~370 GB without item 5 and ~60–70 GB
with it, `build-site` at ~161 GB without item 8 and ~45–55 GB with it.* What remains here (items 6
and 7) is cost, not feasibility.

### 5. Do not materialize transitive closures in `data.json`

`transDeps` and `dataTransDeps` are stored per declaration, fully expanded. Measured at 28,251
declarations that is **18.9 M closure entries against 4.7 M direct-edge entries — 69.9% of the file
against 12.6%** — and the closure side grows superlinearly while the edge side is flat, reaching an
estimated billion entries and ~19 GB of the file's ~21 GB at the whole library. `collect` holds all
of it while serializing, which is where its ~370 GB goes.

The closures are a pure function of the direct edges, computed today by `LeanDeps.transitiveDeps` —
a function `Proofs/Deps.lean` proves properties of. Store the edges, run the same function at load
time, and the closures never touch disk or `collect`'s serializer: `data.json` drops to roughly a
seventh at Mathlib scale (~2.9 GB), and `collect`'s peak to ~60–70 GB, which a workstation has.

Two costs ride along with the current shape and fall with it. `Json.parse` on a multi-gigabyte file
builds a tree many times the file size — the `intern` pass exists because that tree is already the
expensive part at small scale. And `CollectedData.integrityViolations` builds a fresh `HashSet` per
closure per declaration on every load, O(n·C) on data just read from disk; once closures are
computed in-process by the proved functions, those checks guard the wiring rather than the round
trip, and the round-trip risk moves to the much smaller edge arrays.

What it costs. `build-site` and `extract` recompute the closures on every load, so "re-render for
free" becomes "re-render for the price of a closure pass". And `data.json` becomes a weaker
interchange format: a downstream consumer that wanted closures now needs
`closureDeps`/`meaningDeps` semantics — theorem versus definition, aliases — rather than a
ready-made array.

**Built.** `collect` no longer computes or stores either closure; `CollectedData.withClosures`
recomputes both from the direct edges at the one load choke point (and on the in-process `all`
path), using the same `LeanDeps.transitiveDeps` as before. Format version 11 → 12 with
`minReadableDataVersion = 11`: an old file or `--baseline` stays readable — its stored closures are
ignored in favor of the recomputation — while an older binary handed a version-12 file refuses it
rather than silently rendering the empty closures it carries.

Measured on `Mathlib.Analysis` (28,251 declarations), against the same-scope run before the change:

| | stored closures | derived on load |
|---|---|---|
| `collect` wall time | 1 h 02 m 26 s | **33 m 58 s** |
| `data.json` | 574 MB | **225 MB** |
| `build-site` wall time | 14 m 08 s | **13 m 52 s** |
| `build-site` peak RSS | 14.95 GB | **12.86 GB** |
| site output | 4.0 GB, 29,086 pages | **byte-identical** (recursive diff: empty) |

The feared load-time cost did not materialize: recomputing 19 M closure entries is cheaper than
decoding the 349 MB of JSON that used to carry them, so `build-site` got slightly *faster* and
lighter. The equivalence is checked, not assumed — the site built from a closure-free file is
byte-identical to the reference, at both 859 and 28,251 declarations, and a version-11 file read by
the new binary produces the same bytes again.

At the whole library the projection is now anchored rather than extrapolated through a bend:
`data.json` per declaration is 6.1 kB at 859 and 8.0 kB at 28,251 (slope ≈ n^0.08, versus the
closure term's n^0.67), giving **~2.9 GB** instead of ~19–21 GB, and `collect` lands at
**~60–70 GB** peak — ~7 GB of environment plus a ~20× JSON-tree amplification of the now-linear
payload — instead of ~370 GB. Tight on 64 GB, comfortable above it, versus impossible. If the
remaining linear term ever matters, the next lever is streaming the encode instead of building one
JSON tree; nothing in the format now requires the tree.

### 6. Amortize the Mathlib import across `highlight` workers

`highlight` spawns one worker per module and each imports Mathlib from scratch. 8,325 modules at
roughly three minutes of import apiece is the four-day figure, and the measurement above says the
import is about 95% of a worker's life.

Batch modules per worker so each imports once and elaborates many, grouping modules that share an
import closure. That turns 8,325 imports into `--jobs` imports: **days into hours**, and it makes
the `--jobs 3` memory ceiling far less painful, since the ceiling exists because each worker holds
its own multi-gigabyte environment.

`highlight-extracted` has no fix at this scale — one process per declaration is 304,210 Mathlib
imports, some thousands of CPU-hours. It should stay documented as never-at-Mathlib-scale rather
than tuned.

### 7. Scope extraction

304,210 standalone files, 6–12 GB, for something a reader opens one at a time. An
`--extract-scope {all,claims,none}`, or generating a file on demand from closure data `data.json`
already carries, avoids paying for 300k files to serve a handful.

### 8. Render chapter by chapter, so `build-site` holds one chapter and not the library

Added after the phase was measured at 28,251 declarations: **14.95 GB of peak RSS**, extrapolating
to ~161 GB for Mathlib. The bytes were never the problem — the site was 4.0 GB and took 14 minutes.
The problem is that Verso builds the entire document tree before streaming any page out, so peak
memory tracks the library rather than the page being written. That is why RSS sat flat at 14.95 GB
while pages streamed out at ~90 per second: the tree was already built.

This is the difference between sharding as a *deployment* (twenty-five separate sites, closures
truncated at chapter boundaries) and sharding as an *implementation detail* (one site, closures
computed over the whole library, built in bounded memory). Only the second gives the audit
instrument; it is item 5 that makes the whole-library data available to it.

**Built**, as `--per-chapter` on `build-site` — one Verso run per chapter plus a global run, all
into one output directory, and a stitch pass reconstructing what Verso derives from whatever tree
it is handed: chapter numbering (stub parts), the sidebar, the prev/next seams, `xref.json` and the
`find` page that embeds it, the search buckets, and the hover-data table with its page references
renumbered. The design rests on one fact about Referee specifically: every inter-page link is a raw
href computed from the data, never a Verso cross-reference, so a page rendered without the rest of
the library still links into it correctly.

Measured on the 28,251-declaration site, against the monolithic build of the same data:

| | monolithic | `--per-chapter` |
|---|---|---|
| peak RSS | 14.95 GB | **4.47 GB** |
| wall time | 13 m 52 s | **12 m 28 s** |
| site | 4.0 GB, 29,086 pages | 4.0 GB, byte-identical but for the residuals below |

The peak is bounded by the largest chapter plus the shared data rather than by the library — the
memory the monolithic build spends holding every chapter's tree at once buys nothing, and dropping
it even runs slightly faster. Scaling by the same ratio puts a whole-Mathlib `build-site` around
**45–55 GB** rather than ~161 GB — the same class of machine item 5 already brought `collect` to.

Equivalence was checked the same way item 5's was, by recursive diff against the monolithic build,
and it converged to three residuals, disclosed in the section comment in `Site.lean`:

* **Cross-run definition links.** A constant occurrence in highlighted code links to its defining
  code block when that block was rendered in the same Verso run; across runs it degrades to its
  hover. 8 of 859 pages on `Mathlib.Dynamics`; **14,663 of 29,086 on `Mathlib.Analysis`**, whose
  chapters lean on one another heavily. The hover survives, and the card's dependency links (raw
  hrefs) still reach the definition — the loss is a click-through, not reachability. Rebuilding
  Verso's definition-site registry from the rendered pages is the natural follow-up.
* **The search version hash** — the rebuilt index payload is byte-identical; only the
  content-addressed bucket filenames differ, since Verso's full-text hash exists in no run.
* **`xref.json`'s `[anonymous]` entry**, one degenerate key whose winner the monolithic build
  itself picks arbitrarily.

## The second round — what building the first exposed

*None of this is built.* Items 1–8 came from measuring the phases from outside; these came from
implementing them. Each names the evidence the code path itself produced. They are ranked, and
item 9 is unlike the rest: it carries the correction to this document's own site projection, and
with it possibly the difference between a site that can be hosted and one that cannot.

### 9. Bound and externalize the per-page closure payload

A declaration page averaged 47.7 kB at 859 declarations and 148.5 kB at 28,251. The difference is
the closure, rendered **twice**: once as the "rests on" listing — one anchor per member, some
200 B each — and once again as the dependency graph's node payload in the page's `graph-data`
JSON, another ~250 B per member. At the measured mean of 668 members that is ~100 kB of the page;
at the ~3,300 projected for the whole library, ~600 kB.

Which is the correction. The ~43 GB whole-library site earlier drafts printed was fitted through
the two measured runs, page size growing as n^0.33. But the mechanism says a page is a constant
plus ~0.2 kB per closure member, and closure size grows as ~n^0.67 — so once closures dominate,
pages track them near-linearly and the fit falls behind, for a mechanistic estimate of
**~120–180 GB**, three to four times the fit. A two-point fit has misled this document once
already (see *What is not a problem*); this is the same failure at the next scale, caught by
mechanism before the measurement this time.

The fix has two halves, in order of certainty:

* **Give the dependency graph a node budget.** The trust analysis already has one, for exactly
  this reason — its documentation argues that a package past the budget is better summarised by
  counts than drawn — and the README makes the same argument against a whole-project graph. A
  3,300-node per-declaration graph is unreadable at any zoom; draw a depth-limited neighborhood
  and state the counts for what was elided. A rendering change, no client work, and roughly half
  the payload on its own.
* **Turn the closure listing into indices into a shared per-chapter name table.** The hrefs are
  derivable client-side from the names — `pathForDeclPage` is deterministic, the same fact that
  made `--per-chapter` possible — so ~200 B of anchor HTML per member becomes ~4 B of index plus
  an amortized table. This is `AuditData`'s interning generalized from the claims page to every
  page, which is why Tier B's items 3 and 4 read as special cases of this one.

Estimated site at the whole library: ~120–180 GB → **~10–15 GB**. The honest cost: closure
listings become client-rendered, so the no-JS story degrades from "everything readable" to
"closure lists need JavaScript". The audit control set that precedent, but it is a choice to make
deliberately, not a detail.

### 10. Shard what every page load fetches

Two assets are fetched per page view and sized by the whole library, so the site would build and
still be miserable to visit. `searchIndex.js` is loaded eagerly by every page — ~230 MB projected —
and its floor is elasticlunr repeating each document's ~144-character reference in every posting;
dense integer ids with a lazily-fetched id → URL table, or per-prefix index shards fetched as the
reader types, bring the eager cost to tens of megabytes or to nothing. And the hover machinery
fetches the *whole* of `-verso-docs.json` — 11 MB at 28k, ~120 MB projected. The per-chapter build
already *has* per-run hover tables and spends stitch work merging them; keeping them per chapter
and pointing each chapter's pages at their own file turns that work into a win of 2–5 MB per fetch.

### 11. Attach closures per chapter in `build-site`

Item 5 stopped closures being *stored*; `CollectedData.withClosures` still materializes all of
them in memory on every load — on the order of a billion array entries at the whole library,
8–16 GB held for the entire build, even under `--per-chapter`, where each run needs only its own
chapter's. Attach chapter `g`'s closures before its run and drop them after; the global run needs
only what the claims page still carries after item 9. Bounds `--per-chapter`'s peak by the largest
chapter's tree: **~15–25 GB** instead of ~45–55.

### 12. Shard `data.json` by chapter

`collect`'s remaining ~60–70 GB is mostly its encoder: building and interning the whole JSON
document in memory amplifies the serialized bytes roughly twentyfold. Streaming the encode removes
the amplification (~15–20 GB); sharding goes further and is the natural end state —
`data-<chapter>.json` plus one light global index of names, paths, kinds and direct edges.
`collect` drops each chapter as it writes it; `--per-chapter` loads one shard per run; item 11
falls out for free. Both phases become largest-chapter-bounded, **~10–20 GB each**. It is the
largest format change left — one more version bump, and better one than three, which is why it
should precede the parallelism below rather than follow it.

### 13. Parallelize what is embarrassingly parallel

Three independent opportunities, none changing what is computed:

* **`collect`'s per-declaration analysis** runs at ~64 ms per declaration, single-threaded,
  against an environment that is read-only once imported. Fanned across cores, ~6 h becomes
  **~1–1.5 h**; the thing to watch is per-task allocation.
* **Chapter runs** are sequential only because stub pages must be overwritten in a fixed order.
  Render each run into a temporary directory and move across only the pages the run owns — the
  stubs are discarded, and the ordering constraint is discarded with them. Four to eight
  concurrent runs are affordable after item 11.
* **The post-passes** — prune, stitch, the hoist scan and the hoist rewrite — are four read passes
  and three write passes over the same tree, all string transforms. One combined read-modify-write
  walk, with the hoist's counting riding the stitch's read, cuts seven traversals to about two.

### 14. Small, independent, worth doing

* **Gate `integrityViolations` behind `--verify-data`.** With closures recomputed in-process the
  checks guard the wiring and the edges, and they build a fresh hash set per closure per
  declaration — on the order of a billion inserts per load at the whole library, minutes of
  startup paid by every consumer.
* **Accept and emit gzipped `data.json`.** 225 MB → ~30–40 MB at 28k. Matters for CI artifacts and
  the long-lived baselines `--baseline` reads, not for RAM.
* **Precompress the published site.** HTML compresses five- to eightfold; an item-9 site of
  ~10–15 GB serves as ~2 GB. A hosting note rather than a code change.
* **Offer per-chapter tars of `extract`'s output** where the files are not being served: 300k
  small files is a filesystem problem before it is a size one. The site's fetch-by-URL keeps plain
  files where links need them.

## The recommendation, after measuring

The three runs changed what this document should advise, so the argument is restated here rather
than left implicit in the tiers.

**What binds is memory, not bytes.** Before measuring, the fear was disk and transfer: a 34 GB site
and a 5 GB search index. Tier A dealt with the search index completely and took a third off the
site, and neither turned out to be what stops a whole-Mathlib run. What stops it is that `collect`
wants ~370 GB and `build-site` at least ~161 GB, because each holds the whole library at once —
every declaration's materialized closure in the first case, the whole document tree in the second.
No amount of byte-shaving touches either.

**Cost per declaration is not constant — it grows with the size of the exposed set.** This is the
finding that should drive the decision, and it is why the earlier projections from a
1,000-declaration subtree were all too kind:

| per declaration | 859 | 28,251 | |
|---|---|---|---|
| site | 47.7 kB | 148.5 kB | grows |
| `data.json` | 6.6 kB | 19.8 kB | grows |
| `find` / `claims` / `xref` | ~1 kB each | ~1 kB each | flat |
| search index | 0.87 kB | 0.76 kB | flat |

The things that grow are exactly the things keyed to closures, and closures widen as the exposed set
widens — `shouldExpose` bounds them by the root prefix, so a bigger root means longer closures for
every declaration in it. The things that stay flat are the ones keyed to *counting* declarations.

The consequence is the useful one: **sharding does not merely divide the work, it shrinks the
total.** Rendering Mathlib as 25 chapter sites is not the monolith split 25 ways; each shard's
closures are bounded by its own chapter, so the sum is far less than the monolith, and each shard's
peak memory is bounded too.

| shape | shards | total site ~ | peak RSS per run ~ |
|---|---|---|---|
| one site | 1 | ~120–180 GB (item 9: ~10–15 GB) | ~45–55 GB with `--per-chapter` |
| by top-level directory | ~25 | ~20 GB | 0.2–26 GB — runs today |
| by second level | ~200 | ~14 GB | < 2 GB |

**But sharding is not free, and the cost is semantic rather than technical.** `shouldExpose` keys on
the root prefix, so with `--root Mathlib.Analysis` every declaration in `Algebra`, `Order` and
`Topology` becomes *upstream* — outside the project boundary, drawn in the upstream band, counted on
the trust page as something a reader is asked to take on faith. The closures bottom out at the
chapter boundary. For a reader browsing Mathlib that is tolerable. For a referee auditing Mathlib it
is close to the opposite of what the tool is for: the dependency structure that matters most is
precisely the one that crosses those boundaries, and sharding is what hides it.

So the recommendation splits on what the site is meant to be.

**If it is a reference people browse** — shard by top-level directory today. Nothing more is needed:
every chapter builds in under 26 GB, the global pages land at 10–30 MB, and Tier A keeps each search
index near 20 MB. What is missing is only the glue: a shared cross-site name index and a top-level
landing page, so twenty-five sites read as one. Tier A made that glue cheap, because a name index is
flat — the whole of Mathlib is 226 MB, and any single chapter about 20 MB.

**If it is an audit instrument for Mathlib as a whole** — sharding will not do, because the closures
it truncates are the evidence. That needed two things, and both are now built:

1. **Tier C item 5**, so `collect` can produce whole-library data at all. Storing direct edges
   instead of the estimated billion materialized closure entries took the measured 28k run from
   574 MB to 225 MB and 62 to 34 minutes, and moves the whole-library projection from ~370 GB to
   ~60–70 GB of peak and from ~19–21 GB to ~2.9 GB of file.
2. **Item 8, `--per-chapter`**, so the same whole-library data becomes one site without holding one
   document tree: 14.95 GB → 4.47 GB at 28k, projecting ~161 GB → ~45–55 GB at Mathlib, with the
   output byte-identical up to three disclosed residuals — of which cross-run definition links in
   highlighted code are the one with real reach (half of `Mathlib.Analysis`'s pages carry a
   degraded token; hovers and the cards' dependency links survive everywhere).

Together those give the thing worth having: closures computed over the whole library, rendered into
a single cross-linked site, on one large workstation. **The audit instrument's pipeline now runs at
Mathlib scale end to end** — `collect` at ~60–70 GB overnight, `build-site --per-chapter` at
~45–55 GB in an afternoon. What it would produce is the catch: a ~120–180 GB site whose pages carry
their own closures twice over, whose every view fetches a library-sized search index and hover
table — buildable, hostable nowhere sensible, heavy to visit. That is the second round's subject.

**The order to do the second round in.** Item 9 first: it is the one with viability attached, and
it shrinks everything downstream — the stitch, the hoisting, the diffs that validate them all get
faster for free. Then item 12, because it makes items 11 and 13's chapter-parallelism nearly
automatic and is the last format change — better one version bump than three. Then item 13 for
wall time, item 10 before anything is actually deployed, item 14 whenever. `highlight` (item 6)
stays the optional cost problem it was, and the definition-link degradation disclosed under item 8
is quality debt to weigh alongside — it would ride the same stitch pass item 13 consolidates.

**Two caveats over all the numbers here.** First, every projection — the second round's included —
stands on the same two measured runs. The first whole-Mathlib `collect`, now actually runnable,
replaces all of them with measurements, and should be run before any of items 9–14 is sized in
earnest. Second, every site measurement was taken without `highlight` and without `extract`.
Interactive Lean roughly triples page size — it is the difference between the 78 kB pages measured
here and the 238 kB pages of the `LeanMachineLearning` site — and `highlight` is itself a multi-day
phase until item 6 amortizes its imports. A deployment that wants hover-types should assume the
site figures above are a lower bound by about 3×.

## Sizes per shard

What a `--root Mathlib.X` run costs, with Tier A applied. The two measured rows anchor the rest;
site size per declaration is interpolated between them, since it grows with scope, and the index is
flat at 0.8 kB per declaration. Declaration counts come from source counts scaled by the measured
1.20 ratio between written and exposed declarations.

The root-prefix machinery already anticipates this shape: `Collect.lean`'s page-tag discussion is
written about `--root Mathlib.Logic` and `--root Mathlib.Order` and the collisions Mathlib's file
naming produces there.

| `--root` | exposed ~ | site ~ | search index ~ | `build-site` RSS ~ |
|---|---|---|---|---|
| `Mathlib.Dynamics` | 859 (measured) | **40 MB** | **0.73 MB** | **0.23 GB** |
| `Mathlib.Probability` | 4,700 | 0.3 GB | 4 MB | 2 GB |
| `Mathlib.MeasureTheory` | 13,400 | 1.4 GB | 11 MB | 7 GB |
| `Mathlib.Analysis` | 28,251 (measured) | **4.0 GB** | **21 MB** | **14.95 GB** |
| `Mathlib.Algebra` | 49,300 | 7 GB | 39 MB | 26 GB |
| `Mathlib` | 304,210 | ~120–180 GB (see item 9) | 226 MB | 161 GB |

The shard rows sit within or near the measured range and their interpolation is trustworthy; the
`Mathlib` row is where the fit breaks, and its site figure is the mechanistic estimate from item 9
rather than the fitted 43 GB earlier drafts carried. The RSS column is the *monolithic* build;
`--per-chapter` (item 8) divides it — measured 14.95 → 4.47 GB on the `Mathlib.Analysis` row — so
the column now bounds nothing except the old default. Tier A is what makes the search column
ordinary: before it `Mathlib.Analysis` alone carried a 421 MB index, and it now carries 21 MB.

Note also that no shard escapes the fixed import: `collect` imports all of Mathlib whatever `--root`
says, so every shard pays ~4 GB and ~4 minutes before it scales from there. Twenty-five shards means
paying that twenty-five times, which is the one place where sharding is *more* expensive than the
monolith — about 100 GB-minutes of import, against a single run that cannot happen at all.

## What is not a problem

Recorded because each was assumed to be one, and ruling them out is what left the list above short:

* **The sidebar.** Already pruned, 14 MB saved on 908 pages.
* **`build-site` time.** 14 m 08 s for 28,251 declarations extrapolates to about 2.5 hours for
  Mathlib. The problem with `build-site` was never how long it runs — it is the 161 GB it wants
  while it runs, since Verso holds the whole document tree before streaming any page out.

Two entries were on this list and turned out to be the two biggest problems in the document, and
the manner of each mistake is worth more than the corrected numbers.

**`collect`** looked free on the strength of the `Mathlib.Dynamics` run alone — 3 m 25 s and
4.03 GB, a phase dominated by a fixed import. The `Mathlib.Analysis` run said 1 h and 12.8 GB.
A subtree small enough to measure quickly is small enough for the fixed import cost to hide the
slope entirely: two points, far apart, or none.

**Closure sizes** were declared fine — "mean 119 per declaration, the same regime as
`brownian-motion`" — on the strength of a sample computed with `Expr.getUsedConstants` as a proxy
for `LeanDeps`. The real mean at 28,251 declarations is 668 and still growing with scope; the proxy
was off by an order of magnitude precisely because `LeanDeps` exists to recover what
`Expr.getUsedConstants` drops. A proxy that differs from the measured thing in exactly the
dimension under study is not a floor, it is a different quantity: measure with the tool's own
semantics or not at all.
