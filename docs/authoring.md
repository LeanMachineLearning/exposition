# Authoring a library for Referee

Almost everything the site shows is derived: dependencies, closures, `sorry` chains, axioms,
compile status. Two things are not, and they are worth knowing before you point the tool at a
project. Both are editorial intent — claims about what matters, which no analysis of the
environment can recover.

**The Claims page lists the declarations you wrote with `theorem`, not `lemma`.** It takes the
usual convention at face value — `theorem` for a result worth stating for its own sake, `lemma`
for a step towards one — because Lean records both as the same kind and nothing else in the
environment distinguishes them.

So the choice between the two keywords is the one piece of editorial intent the tool cannot infer,
and the only thing you have to do deliberately to get a useful Claims page. `LeanMachineLearning`
states 11 of its 698 declarations as theorems, and they are exactly the point of the library — the
regret bounds. A project that writes `theorem` everywhere gets a Claims page meaning "all results":
still true, just less useful. Nothing else on the site depends on the distinction.

**The specification of a definition is whatever you marked with `@[specifies]`.** A proof can be
checked by the kernel; a definition cannot. What settles whether `entropy` means entropy is a
handful of theorems — it agrees with the textbook formula, it is non-negative, it reduces to the
classical notion in the classical case — and nothing in the environment distinguishes those from a
lemma used once on the way to something else.

[`LeanSpec`](../LeanSpec/) is a separate, dependency-free Lake package holding one attribute for
recording them at the theorem:

```lean
@[specifies entropy "agrees with the textbook formula on finite supports"]
theorem entropy_eq_sum … := …
```

A target project that depends on it and annotates its theorems gets two things this tool cannot
otherwise derive: for each definition, the properties its author claims pin it down, and — the
more useful half — which definitions carry no such claim at all. `collect` reads the annotations
straight out of the compiled environment and records them on every declaration as `specifies` (on
the theorem) and `specifiedBy` (on the definition), and the site renders them in four places:

- **on a definition's page**, a *Specification* section listing each marked theorem with its
  statement and the author's note — a reader judges whether the properties pin the definition down
  by reading them, so the statements are inline rather than behind links;
- **on a definition's page with none**, a line saying so, which is the finding an auditor is
  after and is invisible otherwise;
- **on a theorem's page**, which definitions it speaks for;
- **a Specifications page**, the counterpart to Trust: what is specified, what is not — the
  unspecified ranked by how many declarations use them, so the biggest gaps come first — and a
  plain statement of what the page cannot tell you, namely whether any given specification is
  *enough*. The Browse table gains a matching `Spec` column and filter.

Every one of those is gated on the project having at least one annotation. A project that does not
use the package is not penalised for it: the fields are empty, the page is not built, the column is
not rendered, and nothing on any page mentions specifications at all.

The attribute is checked, not decorative: the target is an identifier, so a typo or a renamed
definition is a build error rather than a stale line in a metadata file. See
[`LeanSpec/README.md`](../LeanSpec/README.md) for how to depend on it, what else it validates, and why
the attribute is not called `spec`.
