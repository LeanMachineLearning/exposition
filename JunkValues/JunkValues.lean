module

public import JunkValues.Rule
public import JunkValues.Registry
public import JunkValues.RuleSet
public import JunkValues.Report
public import JunkValues.Guard
public import JunkValues.Scan
public import JunkValues.Frontend
public import JunkValues.Elab

@[expose] public section

/-!
# JunkValues — where a definition silently means something else

Lean has no partial functions, so every operation with a domain condition needs a value outside it.
`∫ x, f x ∂μ` is `0` when `f` is not integrable, `deriv f x` is `0` where `f` is not differentiable,
`∑' i, f i` is `0` when the family is not summable. The convention is necessary and almost always
harmless. It stops being harmless the moment a definition is built on one:

```lean
def B (f g : α → ℝ) (μ : Measure α) : ℝ := ∫ x, (f x + g x) ∂μ
```

`B` does not mean what it says. On any `f, g` whose sum is not integrable it means `0`, and every
theorem about `B` inherits that — including, in the worst case, the theorem that makes the
development look finished. Nothing in Lean warns about this, because nothing is wrong: the
definition elaborates, the proofs go through, and the statement is true.

This library finds those places and says what condition each one rests on.

> `if ¬Integrable (fun x => f x + g x) μ then ∫ (x : α), (f x + g x) ∂μ = 0`

## What the package is

Two things, and the rest is optional:

1. **`@[junk_value]`** — the annotation that says one of your definitions has a junk value, and what
   condition produces it. `Registry.lean`.
2. **the linter** — which reports, on every declaration you write, the junk values it uses that
   nothing in scope rules out. `Frontend.lean` and `Elab.lean`.

Everything else serves those two. `JunkValues/Extra/` is not part of them at all: it answers the
separate question of what to do about junk values in libraries you do not own and cannot annotate,
and a project that annotates its own definitions never needs it.

## The idea it rests on

**Rules are theorems.** The way to know that an integral collapses to `0` is not a table of
constants maintained by hand — that table is unchecked and goes stale — but the theorem that already
exists and says so:

```lean
theorem MeasureTheory.integral_undef {f : α → G} (h : ¬Integrable f μ) : ∫ a, f a ∂μ = 0
```

Read as a rule, that statement gives all three parts at once: the left-hand side is the pattern to
look for, the hypothesis is the condition under which the value collapses, and the right-hand side is
what it collapses to. Every part has been checked by the kernel. The library cannot claim a default
value that does not exist; the worst it can do is not know about one.

That is why `@[junk_value]` goes on a *theorem* rather than on the definition: annotating the
definition would be an unchecked assertion, and annotating the theorem that proves the collapse is
not. The attribute checks the shape where it is written, so a theorem that cannot be a rule is an
error somebody can fix rather than a rule that silently never fires.

The same reading applies to a theorem nobody annotated, which is what makes `Extra/` possible at
all — but that is an addition, and it reaches a scan through the provider registry in `RuleSet.lean`
rather than through anything core knows about.

## The idea that makes it usable

**Finding the occurrences is easy; the tool lives or dies on dismissing them.** Reporting every
integral in a measure theory development reports nothing. Almost every occurrence is fine, and it is
fine for a reason that is one lemma away rather than literally present: a theorem assuming
`Integrable f μ` and `Integrable g μ` and integrating `f + g` needs `Integrable.add` before anything
can tell it is safe.

So each occurrence's condition is instantiated at the point it was found — in the real local context,
with the declaration's own hypotheses in scope — and handed to a discharger. Mathlib's `fun_prop`
is exactly the tactic for this class of goal, and `Guard.lean` explains why it is named as a *string*
rather than depended on.

## What it reports, and what it refuses to

Three statuses, and only two of them are findings:

| | |
|---|---|
| `guarded` | the condition was ruled out. Not a finding; kept as evidence that the scan looked. |
| `unguarded` | nothing in scope rules the collapse out. **This is the finding** — not a claim that anything is wrong. |
| `triggered` | the condition was *proved*. The term provably is the default. Rare, and much stronger. |

A finding is evidence, never a verdict, which is the same rule the rest of this repository's
analyses follow. Whether `f + g` is integrable is mathematics; a linter that claimed to have settled
it would be lying most of the time. What the tool can honestly do is make the list finite, ordered,
and annotated with the exact condition each entry rests on.

Findings are also split by where they were found, because the risk differs. In a **statement** a
junk value is a *vacuity* risk — the theorem may hold for no reason, both sides having collapsed. In
a **body** it is a *meaning* risk — the definition denotes something other than its name says, and
everything downstream inherits it. `Report.inheritRisk` is that inheritance.

## Usable without the rest of this repository

Lean core only: no Lake, no Verso, no document format — and, deliberately, no Mathlib, even though
Mathlib is where nearly every rule comes from. See `Catalogue.lean` for how that is arranged. The
`referee` tool in this repository is a consumer, not the owner.

## Where to read next

The core, in the order it builds up:

| | |
|---|---|
| `Rule.lean` | what a rule is, read off a theorem, and the second rule form that is not implemented |
| `Registry.lean` | `@[junk_value]`, and why the annotation goes on the theorem |
| `RuleSet.lean` | indexing, and the provider registry that keeps optional sources out of core |
| `Report.lean` | findings, the three statuses, and inherited risk |
| `Guard.lean` | discharging, and why the tactic is a string |
| `Scan.lean` | the traversal, and why it opens every binder |
| `Frontend.lean` | options, the linter, and the batch scan |
| `Elab.lean` | `#junk_check` and `#junk_rules` |

Optional, and separate on purpose:

| | |
|---|---|
| `Extra.lean` | why these are not core, and which to import |
| `Extra/Catalogue.lean` | Mathlib's junk values, hand-verified against a stated revision |
| `Extra/Discovery.lean` | finding rules by shape — a catalogue-building aid, with the measurements that say why it is not more than that |
-/
