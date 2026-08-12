module

public import JunkValues.Extra.Entry
public import JunkValues.Extra.Catalogue
public import JunkValues.Extra.Arithmetic
public import JunkValues.Extra.Discovery

@[expose] public section

/-!
# Extra rule sources

Everything that is *not* the core of this package. The core is two things — `@[junk_value]` for
saying that one of your own definitions has a junk value, and the linter that reports where those
values are used unguarded — and a project that annotates its own definitions never needs this
directory.

What is here answers a different question: what about the junk values you did **not** write, in
libraries you do not own and cannot annotate?

| | |
|---|---|
| [`Extra/Catalogue.lean`](Extra/Catalogue.lean) | Mathlib's analytic junk values — integrals, conditional expectations, derivatives, sums — named by hand and verified against a stated revision. The one most projects want. |
| [`Extra/Arithmetic.lean`](Extra/Arithmetic.lean) | Division by zero, truncated subtraction, and the coercions that collapse `⊤` to `0`. Split out because its patterns are `?a / ?b` and `?a - ?b`, so it asks about *every* division and subtraction — the highest-volume rules in the package, and the least visible hazard. |
| [`Extra/Discovery.lean`](Extra/Discovery.lean) | Anything with the shape, found automatically. A catalogue-building aid, not a rule source — read its docstring before switching it on. |

Both are opt-in **by import**: importing this module, or either half of it, is what makes the source
available to a scan. `RuleSet.lean` explains why registration works that way rather than through a
configuration flag — in short, so that core never has to name what is in here.

Importing `JunkValues.Extra` is therefore the sensible default for a project built on Mathlib, and
importing plain `JunkValues` is the right thing for a project that only cares about its own
definitions or does not use Mathlib at all.
-/
