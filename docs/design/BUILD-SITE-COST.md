# Where `build-site` spends time and memory, and what to do about it

**Measured 2026-09-09**, `leanprover/lean4:v4.34.0-rc2`, 32 cores / 62 GB / no swap. Companion to
[MATHLIB-SCALE.md](MATHLIB-SCALE.md), which asks whether a whole-Mathlib site can be built at all;
this one asks where the cost is once you have decided to build one.

`build-site` logs elapsed time and RSS at each phase boundary (`Referee.phase`), which is how every
number below was obtained. Two monolith-regime corpora, both `--root Mathlib`, both with search
off (then the `--search none` mode, now the only behaviour): 16,876 declarations and 93,507.

---

## The profile

At **93,507 declarations** — 43 min, 10.9 GB peak:

| phase | time | share | RSS after |
|---|---|---|---|
| read `data.json` | 0.8s | — | 0.6 GB |
| parse json | 3.0s | — | 1.9 GB |
| decode (resolve + `fromJson`) | 6.1s | — | 2.9 GB |
| `withClosures` | **0.0s** | — | 2.9 GB |
| integrity check | 36.7s | 1.4% | 2.9 GB |
| build document tree | 180.9s | 7% | **7.2 GB** |
| **verso render + write** | **2093.1s** | **81%** | peak **10.9 GB** |
| prune sidebars | 157.7s | 6% | 3.5 GB |
| search mode | 36.7s | 1.4% | |
| chapter tables | 1.5s | — | |
| hoist assets | 70.3s | 2.7% | |

Two facts govern everything else:

* **Time is Verso.** The render is four fifths of it. Everything this project controls — decoding,
  the integrity check, the three rewrite passes — is 11% between them.
* **Memory is the document tree.** It is 7% of the time but 4.3 GB of the 10.9 GB peak, and it
  scales worse than anything else measured.

### Scaling, 16,876 → 93,507 declarations (5.5×)

| | growth |
|---|---|
| decode | 5.6× — linear |
| render's own overhead above the tree | 4.1× — sub-linear |
| **document tree, memory** | **14.4×** |
| **document tree, time** | **33×** |
| **integrity check, time** | **73×** |

The tree grows badly because it holds every page's `GraphData` — node and edge arrays sized by that
page's closure — for the whole library at once. Pages grow with the library and closures grow with
the library, and the tree pays both. The *rendered page* stays flat (21.5 → 25.6 kB) because
interning shrinks it on the way out; the structure before serialization is untouched by that.

---

## Two suspects ruled out

**`withClosures` costs nothing.** 0.0s at both scales. An earlier draft named it the prime suspect,
reasoning that `build-site` barely improved when `data.json` halved. That was an elimination dressed
up as an accusation: the arithmetic — a page's meaning closure averages 78.9 members, so both closure
sets together are ~30M pointer entries, ~250 MB against a 10.9 GB peak — never supported it.

**Traversal converges in four passes.** Verso re-walks the document to a fixed point, capped at
`maxTraversals := 20`, and each pass ends in a deep structural comparison of the whole tree and
state. In practice it always ran **exactly 4 passes**, and the cost is flat in the render:

| corpus | passes | total | share of render |
|---|---|---|---|
| 4,395 | 4 | 171 ms | < 1% |
| 16,876 | 4 | 713 ms | 0.6% |

So the render's 81% is page *emission* — turning blocks into HTML and writing files — not redundant
re-walking. There is no obviously wasted work inside it to remove.

### One piece of waste that was found

`emitSearchIndex` is guarded on `.search ∈ config.features`, which defaults to every feature and
which nothing set. Under what was then `--search none` Verso therefore built the full-text index,
wrote it, and a post-pass emptied it afterwards. `renderConfig` now clears the feature outright:
**peak RSS at 16,876 declarations fell 1,670 MB → 974 MB, −42%**, repeatably. Wall time did not
measurably move; two runs of one configuration differed by 18%, so any time effect is under the
noise of a machine in use.

Note that Verso emits the search `<script>` tags from its page template rather than from the feature
set, so the tags outlive the feature being off and `stripSearchAssets` is still required. Suppressing
the index without stripping them leaves every page requesting five files that were never written.

*The 93,507 profile above predates this fix, so its render figure still includes building an index it
discarded.*

---

## What to do

Ordered by return, not by size.

### Speed

**1. Run chapters as concurrent processes.** The render is 81% of the time, single-threaded, on a
32-core machine — and after traversal converges, every page is independent. `--per-chapter` already
splits the work and already stitches the results (sidebar, xrefs, search buckets, hover data); what
it does not do is run the chapters *at once*. A scheduler around the existing mode needs no Verso
changes.

The ceiling is the largest chapter, not the core count: chapters are wildly uneven, and if one holds
40% of the library the speedup is bounded near 2.5× however many cores are free. **Measure the
chapter size distribution before promising a number.**

**2. Merge the three rewrite passes.** *Done, and it did not buy what this document first claimed.*

Sidebar pruning, search-asset stripping and asset hoisting each read every page, transformed it and
wrote it back; hoisting reads twice, since it must count repeats before deciding what earns a file.
That is four reads and three writes per page, and the first version of this item projected
265s → 90s from merging them into one walk.

**The projection rested on "these passes are I/O-bound", which is false.** The pages sit in the page
cache and the cost is string splitting — `stripSearchAssets` divides a 25 kB page at every `<`. The
first merged implementation applied the transforms in *both* walks to make the scan see pruned text,
and came out **slower than the three passes it replaced** (50.9s against ~38s at 16,876
declarations). The fix is that the scan can read raw text at all: `splitInlineBlocks` matches
`<script>`/`<style>` exactly, attribute-less only, so pruning (which removes `<div
class="split-toc">` lists) and stripping (which removes tags carrying `src=`/`href=`) cannot change
what it counts.

With that, the merged pass runs at **43.3s ± 0.05** over four runs at 16,876 declarations. Whether
that beats the old chain is *not established*: the historical separate-pass figures (44.6, 32.5,
39.0, 36.4s) were all taken on a machine doing other work, so there is no clean baseline to compare
against. On mechanism the saving should be two reads and two writes over ~350 MB — seconds, not
minutes.

Keep it for the code, not the clock: one walk instead of three, four helpers deleted
(`hoistInlineAssetsIn`, `scanInlineAssetsIn`, `rewriteInlineAssetsIn`, `stripSearchAssetsIn`), and
output verified identical. If someone wants the real number, revert the merge and measure the old
path on a quiet machine.

**3. Make the integrity check optional.** *Done: `--no-verify`.* 37s today, but it grew **73×**
across a 5.5× step — the worst scaling of any phase. On by default, because what it guards is the
`intern`/`resolve` round trip, the one part of the pipeline `MeaningGraph`'s proofs do not reach; the
flag is for re-rendering a file already checked once. Deliberately *not* applied to the `--baseline`
load: that is a different file from a different run, and a corrupt round trip there would not crash,
it would quietly produce a wrong diff.

### Memory

**4. `--per-chapter`.** Bounds the document tree and the render by the largest chapter rather than
the library, leaving the decode (~2.9 GB at 93,507) as the floor. Already built; nothing to write.

**5. Do not hold the graph payload as a `Json` tree.** *The only fix here that addresses the scaling
rather than the level.* Each page's `Block.graph` carries its `GraphData` as boxed `Json` that is
only ever `.compress`ed into a string at render time. Building that string when the tree is built —
flat bytes instead of boxed nodes — should reclaim most of the tree.

Arithmetic: 1.63 kB serialized × 93,507 pages is 152 MB of real content, which as a boxed tree at
the usual 10–20× amplification is 1.5–3 GB of the observed 4.3 GB. **This is the strongest
hypothesis in this document, and it is not a measurement.** The cheap test is to null out the graph
block on one build and see how much of the 4.3 GB disappears — twenty minutes, and it settles
whether the real change is worth making.

**6. Decode without the second tree.** `resolve` materializes a fully-resolved `Json` tree before
`fromJson?` walks it into structures — 2.9 GB for a 246 MB file. Decoding directly against the intern
table skips a whole representation, perhaps 1 GB. The fiddliest item here and the smallest; leave it
until 4 and 5 prove insufficient.

---

## Suggested order

**2** and **3** are done. **3** removes a phase whose growth was the worst measured; **2** turned
out to be a code simplification rather than a speedup, and the lesson — that these passes are
CPU-bound on string splitting, not I/O-bound — is worth more than the change.

Then **1**, because it attacks the 81% and needs a scheduler rather than new machinery — after
measuring how uneven the chapters are.

**5** in parallel with those, starting with the twenty-minute test that tells you whether the
hypothesis holds.

**6** only if needed.

---

## Reproducing the profile

The phase logging is unconditional and cheap (one `/proc/self/status` read per boundary), so any
build prints it:

```bash
referee build-site --root Mathlib --data data.json --output site
```

For Verso's own traversal accounting, set `verbose := true` in `renderConfig` — but note it also
prints one line per page, which is 305,428 lines on a whole-library build.
