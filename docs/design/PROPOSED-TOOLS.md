# Proposed tools

Candidate additions to the site, ranked, with cost grounded in what the architecture already
provides. Written as a menu to argue with, not a plan: nothing here is committed to.

The framing observation. Everything the site does today describes **one snapshot, passively**. The
three biggest gaps were that it could not say what *changed*, could not say what *falls* if
something is wrong, and could not record what the referee has *done*. Two of those three are now
built; their designs live with the documentation rather than here, and the sections below keep their
numbered slots so that what remains in prose is exactly what is not built.

## Tier A — pure functions of `data.json` (no new Lean phase, no re-import)

### 1. `referee diff old.json new.json` — what changed since I last read it

**Built**, as a render-time `--baseline` flag rather than a subcommand. See
[Comparing revisions](../revisions.md) and [Semantic hashes](../semantic-hashes.md).

### 2. Blast radius — "what if I don't believe X?"

Trust is a build flag (`--trust PKG`) and a per-declaration boolean. Make it a counterfactual the
reader can drive: click any declaration, axiom, `sorry`, or upstream package, and the site marks
everything downstream that dies with it. `usedBy` and the reverse closure are already computed, so
this is client-side.

Two numbers, both cheap and genuinely different: the **meaning** blast radius (follow `meaningDeps` —
what stops saying what it seems to say) and the **trust** blast radius (follow full `deps` — what
stops being proved). Inverted, it ranks where audit effort pays: "the 10 declarations with the
largest downstream footprint". That is the scheduling question a referee actually has, and the site
currently answers it with nothing.

### 3. Audit state as a first-class artifact

**Built.** See [Audit state](../audit.md).

## Tier B — needs the environment (a `collect`-time addition)

### 4. Inhabitation: "is anything of this type ever built?"

The classic way a formalization is vacuously true — a beautiful theorem about `IsBrownianMotion X`
in a project that never constructs a Brownian motion, or a hypothesis class no instance satisfies.
It is derivable: for each definition / structure / class the project introduces, does any
declaration have it in its *conclusion* rather than only in its hypotheses? Report the evidence —
"appears in the statement of 34 theorems, constructed 0 times" — not a verdict, under the same
honesty rule as P11.

This is the exact companion to the Specifications page. `@[specifies]` asks *is the definition
right*; this asks *is it non-empty*. Neither subsumes the other, and this one is the
higher-severity finding.

### 5. A real TCB ledger

`axioms` is collected per declaration, but the trust page treats axioms as one uniform list. The
distinctions that matter, and the things `sorry` + axioms genuinely do not catch:

- `native_decide` → `Lean.ofReduceBool` / `ofReduceNat`, which trusts the **compiler**, not the
  kernel. Categorically larger than `Classical.choice`, and should never appear in the same list
  with it.
- `@[implemented_by]`, `@[extern]`, `unsafe`, `partial` — none are handled anywhere in
  [Referee/Collect.lean](../../Referee/Collect.lean) today. Each is a place where what runs is not what
  the kernel checked.
- `opaque` — asserts inhabitation without exhibiting it; the kind is already recorded, it is just
  not called out as a trust event.

One page, ordered by what each costs: kernel and the three standard axioms at the cheap end,
native_decide / in-project axioms / sorries / unaudited packages at the expensive end. Small work;
the axiom data exists and mostly needs classifying.

### 6. Statement unfolding — "what does this actually say?"

P4 names layer 2 as where *does this say what I think it says* is decided, and today the reader
chases definitions across pages to settle it. Precompute per theorem: the statement with project
definitions delta-unfolded one level, two levels, fully — and a `pp.notation false` view, which
catches custom notation hiding a nonstandard definition. Stepping through one unfold is very often
enough to see whether a definition is the intended one.

Storage is the risk, and §7 of [WEBSITE-DESIGN.md](WEBSITE-DESIGN.md) already taught that lesson:
store the *text* per level, highlight on demand.

### 7. Triviality check

Run `simp` / `exact?` / `decide` against each declaration on the Claims page. A headline claim that
`simp` closes alone is a finding worth surfacing. The per-declaration Lean fan-out (`--jobs`)
already exists, and this is far cheaper than `highlight-extracted`. The evidence is asymmetric, so
the page must say so: a hit is informative, a miss means nothing.

### 8. Path queries

Already scoped as unfinished in P8. Worth finishing because "why does A depend on B" is the one
graph question asked in words that no picture of a closure answers.

## Tier C — interop

### 9. Blueprint import

`leanblueprint` (`\lean{}`, `\leanok`, `\uses{}`) is how most large formalization projects record
intent, and it is the natural join: blueprint has the informal claims, Referee has the reality. It
yields which blueprint nodes have no Lean counterpart, and — the lie detector — which are marked
`\leanok` while pointing at a declaration whose closure contains a `sorry`.

### 10. Git provenance per declaration

**Built**, as a `provenance` subcommand folding each revision into an append-only ledger, plus a
`--provenance` flag on `build-site`. See [Provenance](../provenance.md).

## Rejected

- **Mathlib-overlap detection** ("does this project restate something upstream already has"). A
  prospective-user question, not a referee one, and it fights the stated non-goals.

## If two more get built

Blast radius (2) and inhabitation (4). The first is nearly free given the data already computed —
it is the one of the three framing gaps still open, and the reverse closure it needs is in
`data.json` already; the second is the highest-severity finding class the site is currently blind
to.
