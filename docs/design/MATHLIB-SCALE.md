# Mathlib scale: can this build one site for the whole library?

**Measured 2026-09-09** on `leanprover/lean4:v4.34.0-rc2`, Mathlib `cf65d43b4f`: 32 cores, 62 GB RAM,
no swap. Every figure is either from that campaign or is marked as an extrapolation from it. It
replaces an earlier document whose numbers came from several campaigns against code that no longer
exists; nothing here is reconciled with it.

The question is the **monolith**: one site for all of Mathlib, in which every declaration is a
project declaration and closures cross the whole library. Sharding appears only as the fallback it
is.

---

## The verdict

**`collect` fits. `build-site` probably does not, on this machine.**

| whole Mathlib, 305,428 declarations | | |
|---|---|---|
| `collect` | **2 h 06 m, 19.3 GB, 1.23 GB `data.json`** | **measured, completed** |
| `build-site` | ~7 h, ~50 GB (range 5–10 h, 45–75 GB) | extrapolated from 3 measured points |
| site on disk | ~8 GB | extrapolated |
| first page load | ~1.5–2 MB gzipped, ~20 kB thereafter | extrapolated |

A whole-Mathlib site would be roughly 8 GB and read like an ordinary web page. `collect` runs
comfortably in a third of this machine. The open question is `build-site`: what its peak is spent on
has not been measured, only narrowed, and `--per-chapter` is the escape hatch if it will not fit.

---

## How this was measured without owning a bigger machine

`shouldExpose` keys on the **root prefix**, and the environment holds only what the scope module
imports. So `--root Mathlib` over a *partial* import puts the tool in the genuine monolith regime —
everything exposed is a project declaration, closures stop at nothing — at whatever scale the import
chooses.

Measuring `--root Mathlib.Analysis` instead is the *shard* regime: most of what a declaration rests
on falls outside the prefix and is drawn as upstream, so closures are small for a reason that
vanishes the moment the boundary widens. A monolith cannot be extrapolated from a shard.

Three scopes, each a one-line `Scope.lean` in a throwaway package requiring Mathlib by path, plus the
real thing:

| scope module | exposes |
|---|---|
| `import Mathlib.Order.Lattice` | 4,395 |
| `import Mathlib.Topology.Basic` | 16,876 |
| `import Mathlib.Analysis.InnerProductSpace.Basic` | 93,507 — 31% of Mathlib |
| `import Mathlib` | **305,428 — the whole library** |

---

## What was measured

`--root Mathlib`, `--search none`, without `extract` or `highlight-extracted`. A 20-second heartbeat
log ran throughout, so a laptop suspend would have shown as a gap and voided the run; there were
none.

| declarations | `collect` | peak RSS | `data.json` | `build-site` | peak RSS | site | per page |
|---|---|---|---|---|---|---|---|
| 4,395 | 0:13 | 2.12 GB | 10.5 MB | 0:32 | 0.32 GB | 0.09 GB | 21.3 kB |
| 16,876 | 0:57 | 2.91 GB | 36.7 MB | 2:48 | 0.96 GB | 0.35 GB | 21.5 kB |
| 93,507 | 6:16 | 5.95 GB | 246.1 MB | 44:58 | 8.17 GB | 2.29 GB | 25.6 kB |
| **305,428** | **2:06:21** | **19.30 GB** | **1,262 MB** | *not run* | | | |

The `build-site` peaks are **37%, 42% and 23%** below what the same corpora cost before Verso was
told not to build a search index it then discarded; wall time did not move. See
[BUILD-SITE-COST.md](BUILD-SITE-COST.md).

At 93,507 declarations a declaration page is **17.3 kB** of HTML, of which 1.63 kB is the dependency
graph, drawing a mean of **78.9 nodes**. Served with gzip: **1.24 MB** on a first visit, **18 kB** for
every page after.

---

## What changed since the last campaign, and why it matters

An earlier attempt at the whole library ran **3 h 12 m**, reached **46.1 GB**, and was killed at 98%
without finishing. The difference between that and the 19.3 GB run above is one field.

`DeclInfo.docstringBlock?` held a `Block Manual` — a Verso AST of the pretty-printed signature —
built for every declaration by elaborating it through `MetaM`, serialized, and re-parsed by
`build-site`. **Nothing read it.** The declaration page stopped rendering it, and the field was left
behind. Measured on a decoded `data.json`, it was **79.9% of a serialized declaration**.

Removing it, at 93,507 declarations:

| | with | without |
|---|---|---|
| `collect` peak RSS | 14.44 GB | **5.95 GB** (−59%) |
| `collect` wall | 18:33 | **6:16** (−66%) |
| `data.json` | 507 MB | **246 MB** (−51%) |

The time saving was the surprise: the cost was not storing the block but *elaborating* one per
declaration.

Every other field was audited at the same time — all 31 on `DeclInfo`, all 11 on `CollectedData`, and
the nested `ExternalDeclInfo`, `StatementAnatomy`, `StatementBinder` and `TypePiece`. Four look dead
and are not (`isAlias`, `typeDeps`, `dataDeps`, `transDeps` are inputs to the closure derivation, and
`StatementBinder.isType`/`mentions` feed `StatementAnatomy.grouped`). There is no more dead payload
to delete.

---

## Extrapolating to 305,428, and how far to trust it

Exponents fitted between the 16,876- and 93,507-declaration points; extrapolation is ×3.27.

| quantity | growth | extrapolated | measured |
|---|---|---|---|
| `collect` wall | n^1.10 | 0.38 h | **2.11 h** — 5.5× |
| `collect` peak RSS | n^0.42 | 9.8 GB | **19.3 GB** — 2.0× |
| `data.json` | n^1.11 | 0.90 GB | **1.23 GB** — 1.4× |
| `build-site` wall | n^1.62 | 5.1 h | — |
| `build-site` peak RSS | n^1.25 | 36 GB | — |
| site on disk | n^1.10 | 8.4 GB | — |
| per declaration page | n^0.10 | 28.9 kB | — |

**The fit underestimates, every time, by 1.4× to 5.5×.** The partial-import scopes have smaller
environment floors and shallower closures than the real thing, and nothing in three points captures
that. This is the same error the previous document made in a worse form, and the only honest
correction is to say so and widen the range.

So for `build-site`, the raw 5.1 h and 36 GB become **~7 h and ~50 GB, with a plausible range of
5–10 h and 45–75 GB**. The search-index fix lowered the base but steepened the memory exponent
(1.09 → 1.25): what it removed is a smaller share of the peak at large scope than at small, so the
calibrated estimate lands where it did before. The most relevant calibration is `data.json`'s 1.4×, since `data.json` is
`build-site`'s entire input and it imports no Lean environment; the 5.5× on `collect` wall time is
driven by importing all of Mathlib, which `build-site` never does.

**On a 62 GB machine that is marginal to hopeless.** It is the reason to keep `--per-chapter`, which
bounds peak by the largest chapter rather than by the library.

### The page is flat, which is the point

Page HTML grows as **n^0.12** — 13.4 kB at 4,395 declarations, 17.3 kB at 93,507. A 21× larger
library costs 29% more page. (The `per page` column in the table above is the *whole site* divided by
its declaration pages, so it also carries the shared tables and assets.) The closure itself grows (n^1.10, ~260 nodes projected at full scale)
but at ~21 bytes per node-and-its-edges it stays cheap: a mean page draws its whole closure for
about 6 kB.

That is interning doing its job. A project node is a number indexing a per-chapter table
(`thinGraphNodes`, `declTableJs`); band nodes are numbers indexing `upstream.js`; edges are index
pairs. None of the site's growth is in the pages.

---

## Where `build-site` spends itself

Summarized here; [BUILD-SITE-COST.md](BUILD-SITE-COST.md) carries the full profile, what was ruled
out, and the options for fixing it.

Measured, not inferred: `build-site` logs elapsed time and RSS at each phase boundary. At 93,507
declarations (43 min, 10.9 GB peak):

| phase | time | share | RSS after |
|---|---|---|---|
| read `data.json` | 0.8s | — | 0.6 GB |
| parse json | 3.0s | — | 1.9 GB |
| decode (resolve + fromJson) | 6.1s | — | 2.9 GB |
| `withClosures` | **0.0s** | — | 2.9 GB |
| integrity check | 36.7s | 1.4% | 2.9 GB |
| build document tree | 180.9s | 7% | **7.2 GB** |
| **verso render + write** | **2093.1s** | **81%** | peak **10.9 GB** |
| prune sidebars | 157.7s | 6% | 3.5 GB |
| search mode | 36.7s | 1.4% | |
| chapter tables | 1.5s | — | |
| hoist assets | 70.3s | 2.7% | |

**Verso's render is four fifths of the time.** The parts this project controls — decoding, the
integrity check, the three rewrite passes — are 11% between them.

**The document tree is the memory.** It is 7% of the time but 4.3 GB of the 10.9 GB peak, and it
scales worse than anything else measured. From 16,876 to 93,507 declarations — 5.5× — it grew
**14.4× in memory and 33× in time**, while the decode grew 5.6× and the render's own overhead 4.1×.
The cause is that the tree holds every page's `GraphData` — node and edge arrays sized by that page's
closure — for the whole library at once. The rendered page stays flat because interning shrinks it on
the way out; the structure before serialization does not.

The integrity check is the other superlinear one: 0.5s → 36.7s across the same step, a 73× jump.

**`withClosures` costs nothing** — 0.0s at both scales. An earlier draft of this document named it as
the prime suspect on the strength of `build-site` not improving when the payload halved. That was an
elimination dressed up as an accusation; the arithmetic (~30M pointer entries, ~250 MB) never
supported it, and the measurement settles it.

### One thing Verso was doing for nothing

`emitSearchIndex` is guarded on `.search ∈ config.features`, which defaults to every feature. Nothing
set it, so under `--search none` Verso built the full-text index, wrote it, and `applySearchMode`
then emptied it. `renderConfig` now clears the feature for that mode, and Verso never builds it:
**peak RSS at 16,876 declarations fell from 1,670 MB to 974 MB, −42%**, consistently across repeated
runs. Wall time did not measurably change — two runs of the same configuration differed by 18%, so
any time effect is below the noise on a machine in use.

Verso emits the search `<script>` tags from its page template rather than from the feature set, so
the tags survive the feature being off and `stripSearchAssets` is still required. Suppressing the
index without stripping them leaves every page requesting five files that were never written.

### Not yet measured

Verso traverses the document to a fixed point — up to `maxTraversals := 20` passes, each ending in a
deep structural comparison of the whole tree and state. Verso reports per-pass timing under
`config.verbose`, which this build does not set. Whether the render's 81% is mostly emission or
mostly re-walking is the obvious next question, and that flag answers it.

## What it costs a reader

Measured at 93,507 declarations, gzipped as any real host serves: **1.24 MB** first visit, **18 kB**
per page after. A page loads the declaration tables of the chapters its closure reaches — a mean of
5.8 of 17 — which is what the first visit mostly is.

Two things had to go, and both are done:

* **The search box.** Verso's `searchIndex.js` is fetched by every page with a `<script defer>`
  before the reader types. At 28,381 declarations it was **33.5 MB gzipped** under the default
  `--search full` and 1.88 MB under `--search names`, against ~0.5 MB for everything else on the
  page. `--search none` now removes the box as well as the index — Verso builds the box in
  JavaScript, so a page loading none of `-verso-search/` has none. Finding a name is Browse's job,
  and Browse costs nothing until opened.
* **Verso's hover data.** `-verso-docs.json` is fetched whole from `window.onload` by every page.
  Declaration pages no longer render highlighted Lean — the statement is taken apart above the fold
  with the site's own hovers, and `Code` and `Proof` are plain text — so nothing on them needs it.
  The minimal-file pages keep their highlighting and are the only pages that fetch it. The
  `highlight` phase, whose output nothing read once that changed, has been deleted.

---

## What remains

1. **Run Verso with `config.verbose`** to see how many traversal passes actually happen and what
   each costs. It is one flag, and it splits the render's 81% into "emitting pages" (irreducible
   here) and "re-walking the document" (possibly not).
2. **Shrink the document tree, or avoid holding all of it.** 4.3 GB of the 10.9 GB peak, growing
   14.4× per 5.5× of library. Either the per-page `GraphData` should be built at render time rather
   than held in the tree, or the tree should be built a chapter at a time — which is what
   `--per-chapter` already does, and is the reason to reach for it.
3. **Stream `collect`'s output.** Its 19.3 GB peak includes a late surge from serialization —
   `toJson` over the whole structure, `intern` building a second tree plus its table, `.compress`
   into one 1.26 GB `String`, all before a byte reaches disk. Writing incrementally would cut the
   peak substantially without touching collection itself.
4. **Then run `build-site` on the full library** and replace the estimate above with a measurement.

Lower priority: a **node budget** for the graph, now purely a legibility question with no size
argument behind it; and the **Browse page**, one page carrying every declaration — 10.1 MB at 28,381,
so ~110 MB at full scale, paid only when opened.

**The sharded alternative**, if the monolith proves not worth it: `--root Mathlib.Analysis` and its
28,381 declarations build in 16 min and 10.1 GB for a 1.0 GB site; twenty-five such shards is an
afternoon. The cost is semantic and severe — `shouldExpose` makes everything outside the shard's
prefix upstream, so exactly the cross-cutting structure a referee cares about is what sharding hides.
It is a reference people browse, not an audit instrument.

---

## Reproducing this

```bash
mkdir -p scope && cd scope
cat > lakefile.toml <<'EOF'
name = "scope"
defaultTargets = ["Scope"]
[[require]]
name = "mathlib"
path = "/path/to/a/project/.lake/packages/mathlib"
[[lean_lib]]
name = "Scope"
EOF
cp /path/to/exposition/lean-toolchain .
echo 'import Mathlib' > Scope.lean          # or a subtree, to choose the scale
lake update && lake build Scope

REFEREE=/path/to/exposition/.lake/build/bin/referee
/usr/bin/time -v lake env $REFEREE collect --root Mathlib --data data.json
/usr/bin/time -v $REFEREE build-site --root Mathlib --data data.json \
  --search none --output site
```

`lake build Scope` first: `collect` imports the workspace root's libraries and fails immediately with
`unknown module prefix 'Scope'` if the olean is absent.

Two things learned the hard way. **Log a heartbeat** during long runs — a laptop suspend inflates
every wall-clock figure and leaves no other trace. And **supervise by PID, never `pkill -f`**: a
pattern matches any command line containing it, including the shells supervising the job, which is
how one watchdog killed its own parent and nearly lost a two-hour run.
