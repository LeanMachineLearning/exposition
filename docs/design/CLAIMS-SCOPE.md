# Claims scope: building the site for the results a project puts forward

**Status: built.** `--claims-only`, `--only DECL`, `--claim NAME` and `--comparator DIR` exist; see
[docs/claims.md](../claims.md#building-only-the-claims) for how to use them and
[docs/cli.md](../cli.md) for the flags. This document is the design and the measurements behind it.
One item is deliberately left undone and marked below: `ChallengeGen.writeAllExtractions` still takes
one array as both the inlining universe and the target list, so `--only` prunes the extra files
afterwards instead of never writing them.

On a project that exists to prove a handful of results — the shape the
[Palomar registry](https://palomar-registry.org/) collects, and the shape a
[Comparator](https://github.com/leanprover/comparator) setup certifies — a site over the whole
library spends nearly all of its build time, and nearly all of a reader's attention, on machinery
nobody submitted.

Two modes:

* **`--claims-only`** builds the site for the results the project puts forward and the declarations
  their **statements** rest on.
* **`--only DECL`** is the same thing with a claim set of one declaration — the same scope rule and
  the same site. See *The single-page mode that wasn't* below.

## The single-page mode that wasn't

`--only` was specified as, and first built as, a *single page*: one declaration's card, graph,
minimal file and audit control, with no sidebar and no utility pages — the artifact you attach to a
submission. The graph's project nodes would fall back to the summary the chapter tables already
carry, which is the degradation an upstream constant has always had, so it looked like a free
saving.

It was not. A claim's page is mostly the dependency graph beneath it, and the reason to click a node
is to read *that declaration's card* — the statement taken apart, the source, the proof. A summary
panel carrying name, kind, signature and docstring answers a different and much smaller question,
and a page whose every link bottoms out in one strands the reader exactly where the work starts.
Built and looked at, that was obvious; reasoned about beforehand, it was not.

So `--only DECL` is `--claims-only` with a claim set of one. The closure it renders is a couple of
dozen declarations, which costs nothing that matters. What is left of the distinction is which
declarations seed the scope, and `data.json`'s scope record still says which of the two asked for
it.

## The measurement that decides the design

The obvious reading of "the claims and what they rest on" is the closure under `DeclInfo.deps` —
everything a main result touches at all. Measured on two projects that ship both metadata files:

| | colt-2026-83 | alpha-rar |
|---|---|---|
| library (exposed declarations) | 1901 | 816 |
| closure under `deps` (statement **and proof**) | 1324 — **69.6%** | 563 — **69.0%** |
| closure under `meaningDeps` (statement only) | 37 — **1.9%** | 19 — **2.3%** |
| … plus `@[specifies]`/`@[characterization]`, to a fixpoint | 37 | 53 — 6.5% |

Two independent projects, the same ratios. A formalization's *statement surface* is about 2% of it;
the other 98% is proof machinery. Scoping to the `deps` closure would have cut colt-2026-83 from
1901 pages to 1324 and called it a mode. Scoping to the meaning closure cuts it to **37**.

And the 37 are the right 37. They are the nine claims plus the twenty-eight definitions and
structures their statements are about — `IdentAlg`, `IsPAC`, `gw`, `linearGaussianEnv`,
`simpleRegret`, `gaussianWidth`. That is a site a referee can read to the end, which is the only
size at which the audit apparatus means anything.

What it costs elsewhere, on the same two projects:

| | colt-2026-83 | alpha-rar |
|---|---|---|
| `data.json`, uninterned | 21.0 MB → **0.53 MB** | 12.5 MB → **0.77 MB** |
| files `extract` writes, and `highlight-extracted` elaborates | 1901 → **37** | 816 → **53** |

`highlight-extracted` fans out one Lean process per file against a Mathlib-sized environment. It is
the most expensive phase in the pipeline, and this is a 51× and a 15× cut to it.

## Three tiers, and what each is for

**The full tier — the page scope.** The claims, closed under `meaningDeps`, then closed again after
pulling in any theorem carrying `@[specifies]` or `@[characterization]` for a definition already in
scope, to a fixpoint. These get everything a `DeclInfo` has today: pages, extracted minimal files,
highlighting, audit state.

The upward pull is not a technicality. On alpha-rar it takes the scope from 19 to 53, and what it
adds is the theorems that say what those definitions *mean* — exactly what a referee reading a claim
needs, and the thing no dependency edge points at. Without it a scoped site would show a definition
as unspecified when its specification exists and was merely not depended upon, which is the same
class of quiet wrongness the site exists to avoid.

**The thin tier — a correctness backstop.** Two sets, both carrying names, kinds, modules and direct
edges only — no anatomy, no signatures, no source, no docstrings:

* the closure of the page scope under `closureDeps`, which is what `ChallengeGen` inlines into a
  minimal file (a definition's body drags in the lemmas discharging its embedded proof obligations,
  which `meaningDeps` correctly drops from the graph and extraction correctly needs);
* the declarations a `sorry` chain can pass through.

Measured, this tier is **one declaration on colt-2026-83 and zero on alpha-rar**. It exists for
correctness in the general case, not to carry bulk — which is what makes it affordable to be
thorough about.

**Everything else is dropped**: 98.0% of colt-2026-83, 93.5% of alpha-rar.

## Why the thin tier is exactly this, and no larger

Three facts, each checked against the source rather than assumed.

**`transDeps` — the proof closure — is read by extraction and by nothing else.** Its only consumers
are `DeclInfo.toChallengeDecl` and the integrity check. It appears nowhere in `Referee/Website/`. So
the proof closure needs no rendering data at all: four fields per declaration.

**`deps` — the raw edges — is read by exactly one function on the website: `sorryChain`.** Every
other site-side reference to `.deps` is to an `ExternalDeclInfo` or a `PackageInfo`, not to a
declaration. So the entire cost of keeping proof dependencies is one page's explanation of one
finding.

And that cost can be bounded precisely. `sorryChain` walks `deps` from a declaration to the first
one with `hasOwnSorry`. Every declaration on such a path depends on the `sorry` below it, so every
path node has `dependsOnSorry = true` — a node without it cannot reach a `sorry` and cannot be on
any path. **The skeleton is therefore exactly the `dependsOnSorry` declarations in the claims' `deps`
closure**, which prunes only dead ends and cannot lose a chain. On a project with no `sorry`
anywhere it is empty, and both corpora above are.

This matters because the failure it prevents is silent. `dependsOnSorry` comes from `collectAxioms`
against the whole environment and stays correct however we scope — so a scoped site would report the
right `sorry` count with an empty explanation, and tell the reader the gap was inherited from
upstream when it is the project's own.

**The chapter tables already cover the page scope by construction.** `declTableMembers` is the
chapter's declarations *union their `dataTransDeps`* — the same set a page's graph draws. So when the
page scope is a meaning closure, the tables the graph panel falls back to cover it exactly, and no
node can be drawn without one. The property is already stated in that function's docstring; scoping
does not weaken it.

## Where the main results come from

Three sources, in priority order. A project with none of them gets neither mode and is never told
about either, exactly as a project without `formalization.yaml` gets no Claims page today.

**1. The command line.** `--claim NAME`, repeatable, and `--only DECL`. Wins over everything else,
and is the answer for a repository with neither metadata file — or with metadata whose list you
disagree with.

**2. `formalization.yaml`.** `status.main_results[].declaration`, already parsed by
`Referee/Formalization.lean`. One claim per entry, in the file's order, because a curated list is an
argument about what matters and its order is part of the argument. Where an entry carries
`comparator_config`, that config is read too: its `theorem_names` beyond the headline are
*additional certified targets* — listed under the claim, and seeds of the scope, but not claims of
their own.

**3. Comparator configs.** One claim per config file; every entry of its `theorem_names` belongs to
that claim. This is the reading the corpus forces. colt-2026-83 pairs each headline theorem with an
auxiliary target in thirteen of seventeen configs; ten-proofs' `A_SpherePacking.json` names four
theorems and the headline — per its own `formalization.yaml` — is the **fourth**. Neither "the first
name" nor "a flat union" is right in general, and grouping by config needs no guess: the config is
the unit that gets certified, and the page can say so.

Discovery is by shape, not by filename: a JSON file is a Comparator config when it has
`challenge_module`, `solution_module` and `theorem_names`. Candidates are the paths named by
`comparator_config`, anything given to `--comparator DIR`, and failing both the project root's
immediate subdirectories, skipping `.lake`, `.git` and the build output. The corpus writes them to
`comparator/` (alpha-rar, colt-2026-83) and `ComparatorChallenges/` (ten-proofs); a convention that
covers two of two is not worth hard-coding.

The parser is `Lean.Json`, already in the environment. None of the argument
`Referee/Formalization.lean` makes about hand-writing a YAML subset applies: JSON costs nothing.

## What each phase does

**`collect`** gains the scope, and this is where the win is largest because it is the phase that
does the expensive per-declaration work. `collectDecls` computes `declDeps` inside its main loop; the
change is to compute `Context.allDeclDeps` once *before* it, resolve the page scope from the claim
names, and then run the loop's expensive body — `statementAnatomyOf`, `ppExprString`, the source
read, the command-keyword parse — only for the full tier, emitting thin records for the backstop
tiers and nothing for the rest. On colt-2026-83 that is 37 full analyses instead of 1901.

`collectData` resolves the claim set first, records the *unscoped* exposed count so the site can say
what it left out, and warns on the console about a claim naming a declaration the project does not
expose. That warning exists for `formalization.yaml` today; it extends to Comparator configs, where
a stale `theorem_names` entry is the same rename that never got followed.

**`extract`** targets the page scope. `ChallengeGen.writeAllExtractions` takes one declaration array
and uses it as both the inlining universe and the list of files to write; `--only` needs those to
differ, so it wants an optional `targets` parameter in
[`challenge-gen`](https://github.com/RemyDegenne/challenge-gen). Under `--claims-only` they coincide
and nothing needs to change. Writing every file and deleting the rest is a correct interim.

One residual to disclose rather than solve: `assembleTarget` emits whole source *commands*, so a
command defining siblings (`@[to_additive]`, `@[simps]`) can reference a declaration outside the thin
tier, and the closure is then under-computed. `highlight-extracted` already reports a minimal file
that fails to elaborate, and the site already says so on the declaration's page, so the failure mode
is honest rather than silent. The measurement says this tier is one declaration wide, so the tail is
narrow.

**`highlight-extracted`** needs no change at all. It walks the extracted directory, so it inherits
whatever `extract` wrote — which is where the 51× lands, for free.

**`build-site`** renders the full tier. `declPageHrefMap` becomes the single point where "this
declaration has a page" is answered, and everything downstream already degrades correctly *because
it already has to*: upstream constants have never had pages, so `declIndexList` filters rows it
cannot link, `specTheoremRows`, `charPartRow` and `mkChangeBlocks` fall back to `""` and the block
extensions render a bare `<code>`, and `graph.js` refuses to navigate from an hrefless node while
keeping its summary panel. In practice almost none of that fires in either mode, because the page
scope is closed under exactly what the graphs draw — which is the property that made the
single-page variant look affordable, and the same property that made it useless once built.

## What the site says differently

A scoped site that reported "37 declarations, all proved" without saying it had dropped 1864 would
be exactly the quiet half-truth this tool exists not to produce. So:

* **The landing page** leads with the scope, and with the distinction that makes it defensible:
  *N declarations — the M results this project puts forward and the K their **statements** rest on,
  out of L the library exposes. What the proofs call is not here.* The last number is why `collect`
  records the unscoped count.
* **Claims** becomes the site's spine rather than one page among several, and gains the Comparator
  half: which config certifies each claim, and which additional targets it names.
* **Theorems**, **Browse** and **sorries** keep their shape and requalify their counts, once per
  page. On a scoped site Theorems is nearly the claims list, which is itself worth seeing.
* **Sorries** is the page that must be most careful. It can still name every `sorry` a claim rests
  on and still walk the chain to the culprit, because of the skeleton tier — but the culprit itself
  has no page, and the page has to say that the chain leaves the scoped site rather than leave a
  dead name.
* **Upstream trust** needs no wording change and gets sharper for free: the packages the claims'
  statements reach are exactly what the claims are asked to be believed on.
* **`--only`** renders all of these, for its one claim: the Claims page has a single row, and the
  chapters hold that claim's statement closure.

## What has to be guarded

**`--baseline` across scopes.** A scoped `data.json` compared against a full-scope one reports 1864
declarations as removed. The scope goes into `data.json` and the comparison is refused, with a
warning, when the two disagree.

**A claim that names nothing.** Already a console warning and a Claims-page row for
`formalization.yaml`; it now decides *scope*, so a typo that used to cost one row costs a whole cone.
If every claim resolves to nothing, refuse the build rather than emit an empty site.

## The flags

| flag | read by | |
|---|---|---|
| `--claims-only` | `collect`, `build-site` | Restrict to the project's main results and what their statements rest on |
| `--only DECL` | `collect` | The site for one declaration: `--claims-only` with a claim set of one |
| `--claim NAME` | `collect` | Name a main result explicitly; repeatable; overrides discovery |
| `--comparator DIR` | `collect` | Where the Comparator configs are; auto-detected otherwise |

`--claims-only` is read by two phases rather than one, which breaks the rule that a render-time flag
can be varied over one `data.json`. That is unavoidable and worth stating plainly: the scope is a
property of the data, so it is recorded in the file, and `build-site` reads it to frame the site
rather than to decide it. Passing `--claims-only` to `build-site` over unscoped data is a no-op with
a warning, not a second filter.

## Data format

`collectedDataVersion` 15 → 16. New fields, all defaulted, so `minReadableDataVersion` stays at 11
and an old `--baseline` keeps working:

* `scope` — how this file was collected and from which claim set. What the baseline guard compares.
* `claims` — the resolved claim set: label, declarations, source, Comparator config, additional
  targets. Collected rather than re-derived at render time for the same reason `formalization?` is:
  `build-site` never sees the project directory.
* `libraryDeclCount` — exposed declarations before scoping, so the site can say what it left out.
* `thinDecls` — the backstop tier. A record with the fields a `DeclInfo` needs to answer an
  extraction closure and a `sorry` chain, and none of the fields a page needs. Kept as a separate
  array rather than as partially-filled `DeclInfo`s, so that nothing can render one by accident: a
  thin record that reached a page would show an empty card, which is the failure this separation
  makes impossible rather than unlikely.

## Work, in order

1. ✅ `Referee/Claims.lean` — the claim set, the Comparator config reader, discovery, the merge with
   `formalization.yaml`. Pure, testable, no environment. Everything else consumes it.
2. ✅ The data format — `scope`, `claims`, `libraryDeclCount`, `thinDecls`, the version bump to 16,
   the baseline guard.
3. ✅ `collect` scoping — the two-pass split, the page-scope fixpoint with the `@[specifies]` pull,
   the thin tier, the console warnings.
4. ✅ `sorryChain` reading the thin tier, and the sorries page saying when a chain leaves the scope.
5. ✅ `build-site` page scoping — `declPageHrefMap` from the page set, the requalified counts and the
   landing sentence.
6. ✅ `--only` as claims-mode with a claim set of one. (A single-page root part was built,
   looked at, and removed — see *The single-page mode that wasn't*.)
7. ✅ The Claims page's Comparator half.
8. ✅ Scope discovery made lazy — see *Where the time actually goes* below.
9. ⬜ `challenge-gen`'s `targets` parameter, and dropping the write-then-delete interim. Left
   undone on purpose: it is a change to another repository, and the interim is correct — `--only`
   writes every extraction in scope and deletes the ones it does not publish, so the waste is in
   `extract` and never in `highlight-extracted`, which is the phase that costs.
10. ✅ Docs, and `action.yml` gains `claims-only`, `only`, `claim` and `comparator-dir`.

## Where the time actually goes

The first version scoped only the expensive per-declaration analysis, and still computed every
declaration's edges in order to *find* the scope. That is backwards — the scope is a reachability
question from a handful of seeds — and measuring it said so plainly. `collect` had no phase timings
at all, unlike `build-site`; it does now, and they overturned two of three guesses.

On `colt-2026-83` (1901 declarations), a `--claims-only` collect:

| phase | eager scope discovery | lazy |
|---|---|---|
| `MeaningGraph.Context.of` | 0.3s | 0.3s |
| pass 1 — edges and source keywords | **30.7s** (1901 decls, 141 files) | **1.6s** (38 decls, 16 files) |
| `collectAxioms` | 0.0s | 0.0s |
| pass 2 — anatomy, pretty-printing, source | 0.2s | 0.1s |
| **whole `collect`** | **35.6s** | **6.8s** |

The two guesses that were wrong are worth recording, because both looked obvious. `Context.of` is
0.3s, not a bottleneck. And `collectAxioms` over every exposed declaration is **0.0s** — the
environment carries an exported-axioms extension, so it is not the per-declaration closure walk it
appears to be. The entire cost was pass 1: reading and running the Lean parser over every source
file, and expanding every declaration's dependencies.

On `NavierStokesAndEuler` — 32,154 exposed declarations, scoped to 13 — the same change took
`collect` from about 25 minutes to 64s, and removing a *duplicated* whole-environment scan
(`collectData` recomputed `projectConstants` and `shouldExpose`, which `Context.of` had already
done, purely to print the hidden-declaration count) took it to **38s**. That second fix helps full
builds equally.

What remains proportional to the library, at that scale: the import, and `Context.of` at 27.9s —
which is in [`meaning-graph`](https://github.com/RemyDegenne/meaning-graph) and builds the notation
and coercion tables the dependency expansion consults. It is the next thing to attack, and the only
one left that is not in this repository.

## What the full path cost

The two-pass split touches the code path an unscoped build takes, so it was checked against a build
of the same project rather than reasoned about. On `colt-2026-83` (1901 declarations), every field
of `data.json` that existed before is **byte-identical**; the file grows by 4,907 bytes (+0.04%) for
the four new fields, of which `thinDecls` is empty and `scope` is empty on a full build. Peak RSS is
unchanged within noise (4.33–4.40 GB across runs of both binaries).

Two costs the split introduced were found by looking for them and removed rather than accepted:

* `upstreamPackages` was computed from `isAliasFromSource` and not from the `DeclInfo.isAlias` field,
  which prefers the parsed command keyword; the two disagree on a declaration whose range lands in a
  command. The split had quietly switched it to the field. Restored exactly.
* The claim resolver's shallow directory scan would have run on every build. It is now gated on
  `allowScan`, which a full build of a project with ranked `main_results` passes as `false` — so such
  a build walks no directories and parses no JSON it did not parse before.

The retained cost is one `DeclFacts` record per exposed declaration held across the two passes.
Its array fields are the same objects the `DeclInfo` retains anyway, so the new retention is the
record headers: about 230 kB at colt's scale.

## Tests

`Test/Claims.lean`, in the shape `Test/Formalization.lean` already has — the config reader and the
merge are pure, and their failure modes are silent in the same way. The cases the corpus already
supplies: a config whose headline is not first (`A_SpherePacking`), a config with an auxiliary
target (colt-2026-83), a `comparator_config` path resolving to nothing, and a `theorem_names` entry
naming a declaration the project does not expose.

A scoping unit test in `Test/Collect.lean`, on a hand-built declaration array: a `sorry` reachable
only through a proof, scoped, with `sorryChain` still reaching the culprit through the thin tier.
That is the regression the tier exists to prevent, and it is invisible end to end — both corpora
measured here have no `sorry` at all, so a passing run on either proves nothing about it.

End to end, the local corpora cover the three cases: colt-2026-83 (seventeen configs with auxiliary
targets, 1901 → 37), alpha-rar (six configs, and the `@[specifies]` pull that takes 19 to 53), and
ten-proofs (twelve configs over ten independent papers — the case for `--only`, and on a different
toolchain, so it needs a matching binary before it can be measured).
