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
| `build-site` | ~7 h, ~50 GB (range 5–10 h, 45–75 GB) | extrapolated |
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
| 4,395 | 0:13 | 2.12 GB | 10.5 MB | 0:32 | 0.51 GB | 0.09 GB | 21.3 kB |
| 16,876 | 0:57 | 2.91 GB | 36.7 MB | 2:44 | 1.65 GB | 0.35 GB | 21.5 kB |
| 93,507 | 6:16 | 5.95 GB | 246.1 MB | 43:25 | 10.58 GB | 2.29 GB | 25.6 kB |
| **305,428** | **2:06:21** | **19.30 GB** | **1,262 MB** | *not run* | | | |

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
| `build-site` wall | n^1.61 | 4.9 h | — |
| `build-site` peak RSS | n^1.09 | 38 GB | — |
| site on disk | n^1.10 | 8.4 GB | — |
| per declaration page | n^0.10 | 28.9 kB | — |

**The fit underestimates, every time, by 1.4× to 5.5×.** The partial-import scopes have smaller
environment floors and shallower closures than the real thing, and nothing in three points captures
that. This is the same error the previous document made in a worse form, and the only honest
correction is to say so and widen the range.

So for `build-site`, the raw 4.9 h and 38 GB become **~7 h and ~50 GB, with a plausible range of
5–10 h and 45–75 GB**. The most relevant calibration is `data.json`'s 1.4×, since `data.json` is
`build-site`'s entire input and it imports no Lean environment; the 5.5× on `collect` wall time is
driven by importing all of Mathlib, which `build-site` never does.

**On a 62 GB machine that is marginal to hopeless.** It is the reason to keep `--per-chapter`, which
bounds peak by the largest chapter rather than by the library.

### The page is flat, which is the point

Page HTML grows as **n^0.10** — 21.3 kB at 4,395 declarations, 25.6 kB at 93,507. A 21× larger
library costs 20% more page. The closure itself grows (n^1.10, ~260 nodes projected at full scale)
but at ~21 bytes per node-and-its-edges it stays cheap: a mean page draws its whole closure for
about 6 kB.

That is interning doing its job. A project node is a number indexing a per-chapter table
(`thinGraphNodes`, `declTableJs`); band nodes are numbers indexing `upstream.js`; edges are index
pairs. None of the site's growth is in the pages.

---

## Where `build-site` spends itself

Not yet measured phase by phase — this is read off the code, and is the next thing to instrument.

1. **Decoding `data.json`.** `loadCollectedData` does `readFile` (the whole file as one `String`) →
   `Json.parse` (a tree) → `resolve` (a second tree, with interning undone) → `fromJson?` (the
   structures). Four representations at once, and the interning that keeps the file small is
   deliberately undone in memory.
2. **The whole document tree.** `mkRootPart` builds every page's blocks before `manualMain` writes
   anything, so 305,428 pages exist as `Part`/`Block` structures at once. That `--per-chapter` was
   built to bound exactly this is the best evidence available that it is the dominant term.
3. **`withClosures`** rebuilds, on load, the closures `collect` stopped storing at format version 12
   — twice per declaration, `transDeps` (extraction) and `dataTransDeps` (meaning), as independent
   arrays. It reads worse than it measures: at 93,507 declarations a page's meaning closure averages
   78.9 members, so both closure sets together come to roughly 30M pointer entries, **~250 MB against
   a 10.58 GB peak**. Worth trimming — `build-site` appears never to read `transDeps`, which is the
   *extraction* closure — but it is not where the memory is.
4. **Three passes that rewrite every page** — sidebar pruning, search-asset stripping, asset
   hoisting. Cheap in memory, not in time: at 93,507 declarations that is ~95,000 files rewritten
   three times, and the pruning alone moved 7.6 GB.

What is known is only that the *payload* is not the driver: halving `data.json` cut `collect`'s peak
by 59% and `build-site`'s by 8%. Which of (1) and (2) accounts for the rest is unmeasured, and they
have opposite remedies — stream the decode, or render in chunks. Instrument before choosing.

---

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

1. **Instrument `build-site`.** Everything above about where its time and memory go is read off the
   code. Sample RSS through a run and timestamp the phases before optimizing anything.
2. **Find the peak before touching anything.** The decode chain and the document tree are the two
   candidates; closure derivation is not, on the arithmetic above. A first cut: log RSS after
   `loadCollectedData`, after `withClosures`, and after `mkRootPart`.
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
