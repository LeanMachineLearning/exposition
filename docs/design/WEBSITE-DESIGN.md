# Website design principles

Design document for the second-generation Referee site. Written before any code, so the
principles can be argued with cheaply.

## 1. What the site is for

> A reader who did not write the library should be able to decide, for any result it states,
> **what that result says** and **what it rests on** — without opening Lean.

Everything below follows from that sentence. Three readers want it:

| reader | question |
|---|---|
| referee / auditor | "Is this theorem *the* theorem? Is anything `sorry`ed or axiomatized?" |
| prospective user | "What is in here that I can reuse, and what does depending on it cost me?" |
| author / maintainer | "What does my library actually claim, and where is it weak?" |

Explicit non-goals. This is **not** API documentation (doc-gen4 does that, better, for
name-lookup), **not** a textbook, and **not** a proof browser. Every feature that only serves
those uses is out of scope.

## 2. The audit unit is the minimal dependency file — and it must be *live* code

For each declaration we already produce a self-contained `.lean` file: its transitive
dependencies inlined, proofs replaced by `sorry`. That file *is* the audit. Reading it answers
"what does this say"; compiling it answers "is this well-formed"; its size answers "how much do
I have to trust".

Today it is a single link, halfway down a long page, pointing off-site to
`live.lean-lang.org`. The new site inverts that: **the minimal file is the primary content of a
declaration page**, rendered inline as *interactive* Lean — hover any symbol for its type,
click it to jump to its definition.

**Where highlighting stands today.** The site already gets this for one thing: `collect` calls
Verso's `Signature.forName` and emits a `Block.docstring`
([Collect.lean:491](../../Referee/Collect.lean#L491)), and that block descriptor is wrapped in
`withHighlighting`, so the *pretty-printed signature* is real `Highlighted` with tippy tooltips.
That works and stays.

What is **not** highlighted is everything else, and it is the part that matters here:

| shown on a declaration | today |
|---|---|
| pretty-printed signature (`Block.docstring`) | ✅ highlighted, hoverable |
| source-form statement (`displaySignature`) | ❌ plain `<pre>` ([Site.lean:353](../../Referee/Website/Site.lean#L353)) |
| proof body (`proofText?`) | ❌ plain `<pre>` |
| **minimal dependency file** | ❌ not shown at all — an off-site link |

So the gap is narrower than "Verso is unused", and also more awkward: the card currently shows
the pretty-printed signature *and* the raw source text of the same declaration, one highlighted
and one not. That duplication is itself a decision to make rather than inherit — the new card
shows the author's source form, highlighted, and drops the redundant second rendering.

The real work is extending highlighting to **source text**, and above all to the minimal file:
a 400-line pile of inlined definitions the reader did not write is exactly the artifact that
benefits most from "what is this symbol?" on hover. That is a strictly harder problem than the
signature case, because `Signature.forName` needs only the environment while source-text
highlighting needs elaboration — see §3.

## 3. Architecture: three phases, one hard data boundary

The environment-dependent work produces **data**; rendering is a pure function of that data.

```
collect      needs Lean env    ─→  data.json          declarations, deps, docs, trust
extract      needs Lean env    ─→  minimal/*.lean     the audit files
                               ─→  highlighted.json   Highlighted + compile status
build-site   needs nothing     ─→  the Verso site
```

`build-site` already reads `data.json` today; this makes that boundary total and versioned.
It is verified to work in Verso:

- `Highlighted` derives `ToJson, FromJson`
  ([Highlighted.lean:382-390](../../.lake/packages/subverso/src/SubVerso/Highlighting/Highlighted.lean#L382-L390)),
  plus a compact key-shared `Export` format
  ([Export.lean](../../.lake/packages/subverso/src/SubVerso/Highlighting/Export.lean)) built for
  exactly this — serializing highlighted code across a process boundary without quadratic blowup.
- `instance : ExternalCode Manual`
  ([ExternalLean.lean:212](../../.lake/packages/verso/src/verso-manual/VersoManual/ExternalLean.lean#L212))
  gives `leanBlock : Highlighted → CodeConfig → Block Manual`. So `build-site` turns
  deserialized highlighting into a page block **with no environment at all**.
- `withHighlighting` auto-injects the tippy/popper assets and registers a quick-jump mapper
  ([HighlightedCode.lean](../../.lake/packages/verso/src/verso-manual/VersoManual/HighlightedCode.lean)),
  so hover-types and cross-references come for free once the data is there.
- SubVerso ships `subverso-extract-mod`, a whole executable whose job is "elaborate a module,
  emit highlighted JSON" — precedent that this split is the intended use.

**The cost, stated plainly.** `highlight` needs info trees and messages, i.e. real elaboration
([Code.lean:2130](../../.lake/packages/subverso/src/SubVerso/Highlighting/Code.lean#L2130)) — the
environment alone is not enough. Two ways to pay it:

1. **Elaborate each minimal file** (~1700 files for brownian-motion, each importing Mathlib).
   Exact, and it makes compile status a *byproduct* rather than a separate script — but it is
   the cost that `scripts/check-extracted-compile.sh` already shows to be the slow step.
2. **Highlight each declaration once, compose per file.** A minimal file is a concatenation of
   declaration sources, so highlight the *N declarations* once each and assemble the *M files*
   from those pieces. Cost drops from O(decls × closure size) to O(decls).

Recommendation: (2) as the production path, (1) available as the verification path, since it is
also what produces honest compile status (P11). The seam to watch in (2) is that scaffolding
(imports, `namespace`, `variable`, `open`) is per-file, not per-declaration, and hover
information computed in the original module's context can differ from the minimal file's.

## 4. Principles

### P1. The data is the deliverable; the site is one client of it

The three-phase split above, made into a **versioned, documented format**: manifest, per-module
declaration chunks, minimal `.lean` files, highlighting, search index. The Verso site is a
client of it; so is anything else anyone builds. It also makes version-to-version diffing
("what changed in this library") nearly free — which nothing today can do.

Corollary: **no HTML, CSS, or JavaScript authored inside Lean string literals.** When this was
written, `Referee/Website/Theme.lean` was CSS in a string and `Referee/Website/GraphJs.lean` was 489
lines of JavaScript in a string, so changing a margin meant rebuilding a Lean executable against
Verso. (Both files are gone: this proposal was carried out — see
[Working on Referee](../development.md).) The fix is Verso's own asset
system — `CssFile`/`JsFile` whose `contents` come from `include_str` of a real `.css`/`.js`
file, which is precisely how Verso vendors popper and tippy
([WebAssets.lean](../../.lake/packages/verso/src/verso/Verso/Code/Highlighted/WebAssets.lean)). Real
files, editor tooling, no rebuild to restyle.

### P2. Audit-first, not book-first

The current site is a Verso `Manual`: root → chapter → module → declaration, with TOC depth and
page splitting. That hierarchy is fine as **URL structure and table of contents**. It is wrong
as the *only way in*, which is what it is today: three clicks deep before a reader sees a
declaration, in a reading order the library does not actually have.

So the hierarchy stays; the **entry points change**. The spine becomes search, filter, and the
claims view (P3). Verso ships search as a built-in feature (elasticlunr + fuzzysort,
[Features.lean](../../.lake/packages/verso/src/verso-manual/VersoManual/Html/Features.lean)) and it is
on by default — another capability already paid for and currently unexploited.

### P3. Foreground the library's *claims*, not its declaration count

A library's claims are the declarations it states with the `theorem` keyword rather than `lemma`.
That is the single most useful view for a referee, who otherwise has to guess which of 700
declarations is the point.

**The assumption this rests on, stated plainly: `theorem` marks a result worth asserting for its
own sake, and `lemma` marks a step towards one.** That is the ordinary Mathlib-style convention,
but it is a convention, not something the compiler enforces — Lean records both as the same
`DeclKind`. The tool takes it at face value and says so on the page, because the alternative is to
guess. Two consequences worth being explicit about:

- **For a library author.** How you choose between `theorem` and `lemma` *is* how you curate this
  page. It is the one piece of editorial intent the tool cannot derive, and the only thing you
  have to do deliberately to get a good claims page.
- **For a reader.** The page inherits the project's discipline. Where the two keywords are used
  interchangeably it degrades to "all results" — still true, just less informative.

**Amendment (2026-09), for the landing page only.** P3 still decides what the Theorems page is and
what the Claims page reads out of `formalization.yaml`. What it no longer decides is the *landing*
page, which used to open with the ten results resting on the most machinery, the re-reading a
revision had caused, and how many definitions carried a specification. Each of those has a page that
presents it better, and repeating the most-read of them made the landing page the longest on the
site rather than the shortest. It now opens with two sentences of counts — declarations split by
keyword, then the upstream packages — and hands the reader to the pages. The claim in the rejected
list below, that counts on the landing page are the wrong metric, was wrong about one thing: a
reader arriving cold does want to know how big this is before being told what it asserts.

The evidence for preferring this over a derived rule is sharp. An earlier version defined claims as
the leaves of the reverse-dependency graph — "nothing else uses it". That is wrong in both
directions: a headline theorem reused by one corollary stops counting, while a lemma proved during
some API build-out and never used again starts counting. `LeanMachineLearning`, which is careful
about the keywords, states 11 of its 698 declarations as theorems, and they are exactly the point
of the library (the Thompson-sampling, explore-then-commit, and UCB regret bounds). The derived
rule dropped 6 of those 11 for the sole reason that something used them once.

Symmetrically, a library's **assumptions** are the external constants (Mathlib, core) its
closures bottom out in, plus any `axiom` it declares. Both belong on the landing page. Neither
exists today; the landing page currently offers "N definitions, M lemmas, K theorems", which
tells a reader nothing they can act on.

### P4. Progressive disclosure along the meaning/trust boundary

A theorem's audit surface is layered, and the layers are not equally important:

1. **its statement** — what is written;
2. **the definitions its statement mentions**, transitively — this is where *"does this say what
   I think it says"* is actually decided. `Continuous`, `IsBrownianMotion`, `Measurable`: if one
   of these is not what the reader assumes, the theorem is not the theorem;
3. **the rest of the closure** (proof-side dependencies) — affects *trust*, not *meaning*.

The tool already distinguishes these (`typeDeps` vs `deps` vs `dataDeps`, and `meaningDeps` follows
type-only for theorems and data-only for definitions). The current site renders all three as an undifferentiated column of cards. The
new site makes layer 2 prominent and instantaneous, and folds layer 3 behind an explicit
"what does the proof lean on" affordance.

### P5. Trust signals are structural, propagated, and explained

`sorry`, declared axioms, `native_decide`, missing docstrings, and *extraction that does not
compile* are all properties of a **closure**, not of a line. Each is:

- shown as a badge on the declaration, and on every declaration downstream of it;
- **explained by a chain** — "depends on `sorry` via `foo` → `bar` → `baz`", clickable — rather
  than a bare flag, because a bare flag sends the reader hunting;
- a **global filter**, so "show me everything that transitively depends on a `sorry`" is one click.

Today `dependsOnSorry` is a single boolean rendered as a grey tag with no path and no filter.

### P6. Quantify the audit surface

For each result, report **how much a reader must accept to believe it**: number of project
declarations in its statement closure, number of distinct external constants it bottoms out in,
line count of its minimal file. Cheap to compute, sortable, and a direct answer to "what does
depending on this cost me". A theorem with a 40-line minimal file and one with a 4000-line one
are different objects and the site should say so before the reader finds out.

### P7. Everything is addressable

Stable URLs for: a declaration, a filter/search state, a line range of a minimal file, a graph
focus. Verso gives tags and permalinks natively; filter state needs our own handling. A
reviewer's work product is links; a site that cannot be linked into cannot be reviewed with.

### P8. Graphs answer questions; they are never decorative

A force-directed layout of every declaration in a library is a hairball at any realistic size,
and the current global graph page is one. It goes away in its present form. What replaces it:

- a **per-declaration layered DAG** of that declaration's own closure — small, laid out by
  dependency depth, genuinely readable;
- **module- and chapter-level aggregates**, where nodes are units a human named;
- **path queries** — "why does `A` depend on `B`" renders the actual path, which is the graph
  question auditors actually ask.

Any graph that cannot state the question it answers does not ship.

### P9. Fast at library scale, and degrading gracefully

Target: tens of thousands of declarations. This is where the Verso choice costs us: pages are
rendered server-side, and a highlighted 4000-line minimal file is a large page. Mitigations:
the compact `Export` encoding, lazy loading of the deep closure, and no page that renders
hundreds of full declaration cards at once — which the current per-declaration page does, one
card per transitive dependency, unbounded. **This is the principle most at risk and needs a
measurement on brownian-motion before the layout is fixed.**

### P10. Static, self-contained, offline-capable

One directory of files, hostable on GitHub Pages, working after load with no network. That
includes **no CDN**: the site currently fetches D3 from `d3js.org` at runtime
([Site.lean:259-261](../../Referee/Website/Site.lean#L259-L261)), which is both a failure mode
and a third-party dependency in an artifact whose entire pitch is verifiability. Vendor it the
way Verso vendors tippy.

### P11. The site is honest about its own limits

Extraction is known to fail for a small number of declarations
([KNOWN-ISSUES.md](../../KNOWN-ISSUES.md)). Where the minimal file does not compile, the declaration
page **says so, with the error**, and offers the `extract-flat` fallback file instead. A tool
that asks readers to trust it must not present unverified output as verified.

This is nearly free under §3: elaborating a minimal file is what produces its highlighting, so
compile status stops being an out-of-band shell script and becomes a field in the data.

## 5. Information architecture

| page | purpose |
|---|---|
| **Landing** | What the library holds and what it rests on, then the README and the module graph. Two counts, not a table of contents, and no longer a copy of the Theorems page — see the amendment under P3. |
| **Browse** | One filterable, sortable table of every declaration: kind, module, trust badges, audit-surface size (P6). The workhorse. |
| **Declaration** | Statement, docstring, source link; **minimal file inline, highlighted and hoverable** (P2); statement-closure outline (P4); trust chain (P5); local dependency DAG (P8); proof body, folded. |
| **Module / chapter** | Module doc comment plus its declarations, as an index — the current hierarchy, demoted to one view among several. |
| **Trust** | Everything `sorry`-dependent, axiom-dependent, or failing extraction, with chains. The referee's checklist. |

## 6. Data format sketch

```
site-data/
  manifest.json            version, root prefix, repo/site URLs, counts, module & chapter tree
  decls/<shard>.json       signature, docstring, kind, source, typeDeps / deps / usedBy /
                           transDeps, trust flags + chains, audit-surface metrics
  minimal/<id>.lean        the audit file                       (produced today)
  minimal/<id>.hl.json     SubVerso Export-encoded Highlighted  (new)
  minimal/status.json      per-file compile status + errors     (new; from the same pass)
  search.json              index for Verso's built-in search
```

## 7. Status

Measured against `brownian-motion` (1677 declarations, 81 modules, 23k lines of Lean).

### Built

| | |
|---|---|
| `highlight` phase | Elaborates each project module, emits SubVerso `Highlighted` per command tagged with the names it defines. **79/79 modules, 2m20s** at 12 workers. |
| `highlight-extracted` phase | Elaborates each extracted minimal file; yields both its highlighting and whether it compiles. **1677/1677, 10m30s** at 24 workers. |
| Interactive Lean on declarations | Source-form statements render with types on hover and click-to-jump, not as `<pre>`. |
| Minimal file as a page (P2) | One highlighted, hoverable page per declaration, on-site, with a compile-status banner — no longer an off-site link to `live.lean-lang.org`. |
| Compile honesty (P11) | 4 of 1677 minimal files do not compile; each says so on its own page, with the error. |
| Claims page (P3) | Everything stated with `theorem`, ranked by dependency footprint. 307 of brownian-motion's 1677 declarations; 11 of `LeanMachineLearning`'s 698. |
| Browse page (§5) | Every declaration in one table, sortable on name/kind/module/deps/external/status and filterable by kind, chapter, trust and name. Renders at most 600 rows at a time and says so. |
| Trust page + chains (P5) | Per-declaration `sorry` chains (`depends on a → b, which contains a sorry`), axiom reporting, whole-library checklist. |
| Audit surface (P6) | Project-closure size and distinct external constants, per declaration. |
| Compact closure lists (P9) | Replaced a full card per transitive dependency — the corpus rendered 176,288 of them. |
| Assets as real files (P1) | CSS/JS moved out of Lean string literals into `Website/assets/`, included via `include_str`. |
| D3 vendored (P10) | No runtime CDN fetch. |
| Format versioning (P1) | `CollectedData.version`, checked with an actionable error. |

### Measured

| | before | after |
|---|---|---|
| `build-site` wall clock | 20 min | **1 min 12 s** |
| declaration pages, total | 784 MB | **248 MB** |
| declaration page, mean | 454 KB | **151 KB** |
| largest declaration page | 2.23 MB | **228 KB** |
| largest page anywhere | 26 MB | **2.05 MB** (the search index) |
| minimal-file pages | did not exist | 1677 pages, 222 KB mean |
| whole site | 955 MB | 690 MB |
| build errors | 1 (duplicate tag, aborted the run) | none |

The "after" numbers *include* interactive highlighting and 1677 minimal-file pages that the
"before" ones lack.

**Cross-validation.** `highlight-extracted` independently reported 4 non-compiling minimal files
for brownian-motion — the same count `scripts/check-extracted-compile.sh` reports in
[KNOWN-ISSUES.md](../../KNOWN-ISSUES.md). Two different mechanisms agreed.

### Dependency-analysis corrections (found by reading the output)

Reading one minimal file exposed two defects, both since fixed:

- **Coercion instances were keyed too coarsely.** `coercionInstancesByType` indexed each coercion
  instance by the *head constant* of the type it coerces from. For `CoeFun (SquareIntegrable …)`
  that head is `Subtype`, so the instance was handed to all 208 declarations mentioning any
  subtype — none of which mention `SquareIntegrable` — dragging its whole closure along. The key
  now also requires the other project constants in the coerced-from type to be present.
- **Nothing checked that a dependency was reachable.** A declaration can only reference what its
  module imports; `Context.declDeps` now drops project-local dependencies whose module is not
  import-visible. Measured: it removed 188 edges, **100% of them provably impossible**.
- **Extraction never stopped at the target.** Files were emitted in module-import order with no
  truncation, so the declaration the file exists for could sit in the middle. `truncateAfterTarget`
  now drops declarations positioned after it (context commands survive, to keep nesting balanced).

Effect: transitive dependency edges across the corpus **176,288 → 116,519 (−34%)**, mean closure
105 → 69, extracted corpus 9.9 MB → 6.0 MB. The audit-surface numbers, closure listings, and
dependency graph on the site were all inflated by the same artifacts.

One consequence, recorded honestly: brownian-motion's extraction pass rate went **1673/1677 →
1671/1677**. The two newly-failing files were never correctly extracted — they compiled because
spurious edges happened to pull in a declaration `@[to_additive existing]` needs (see
[KNOWN-ISSUES.md](../../KNOWN-ISSUES.md) issue 4). Correcting the analysis removed the accident.

### The one design change forced by measurement

The design said the minimal file should be **inline on the declaration page**. It is not; it is
one click away on its own page. Highlighting carries a pretty-printed type for every token, and
that measured **46× the size of the Lean source it describes** — 10 MB of extracted files became
478 MB of highlighting. Inlining it would have pushed declaration pages back past where they
started. A dedicated on-site page keeps the substance (self-contained, interactive, one click)
and the page budget.

Levers if this needs to shrink further: strip per-token docstrings (kept types) from the minimal
files' highlighting, or render on demand client-side. Also note `build-site` now peaks around
5 GB resident while holding all the highlighting in memory.

### Fixed along the way

Declarations whose names differ only outside ASCII — `induction_on`, `induction_on₂`,
`induction_on₃` — derived the same Verso cross-reference tag, so the site build failed with
`Duplicate tag` and stopped. Declaration pages now carry explicit ASCII-unique tags
(`asciiTagOf`).

### Not yet done

- **Search** — Verso's built-in full-text search is enabled and untouched. It does name lookup;
  it does not know about kinds, closures or trust, which is what Browse is for.
- **P8, partially** — path queries ("why does A depend on B") and module-level aggregate graphs are
  not built. The rest of P8 is done: the force-directed layout is gone, replaced by a deterministic
  layered DAG (rows by longest-path depth, edges routed through waypoints, transitively reduced),
  and the whole-repository graph page has been deleted rather than restyled — a single picture of
  1677 declarations answers no question a reader has.
- **P7** — filter/search state is not addressable in the URL.
- **P4** — the meaning/trust split shapes the page, but the statement closure is listed rather
  than shown as content.
- **P2, partially** — see "the one design change forced by measurement" above.

## 8. What this rejects

Stated plainly, so the decisions are visible rather than implied:

- the chapter→module tree as the site's *only* entry point (P2);
- the whole-repository graph page, in any layout (P8) — deleted, not restyled;
- the minimal file as an off-site link, and as plain `<pre>` text (P2);
- front-end code authored in Lean string literals (P1);
- ~~landing-page metrics that are counts rather than claims (P3)~~ — reversed, for the landing page only; see the amendment under P3;
- runtime CDN dependencies (P10).
