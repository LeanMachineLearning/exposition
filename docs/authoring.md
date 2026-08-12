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

**A characterization is the stronger claim, and the attribute checks it.** `@[specifies]` records
that a theorem is *part of* what a definition means; `@[characterization]` records that a property
pins the definition down *uniquely*, up to a stated relation — equality, a.e. equality, the
existence of an isomorphism. It comes in three parts, on three declarations:

```lean
@[characterization property entropy "the Shannon axioms"]
def IsEntropy (p : Distribution α) (h : ℝ) : Prop := …

@[characterization existence]
theorem isEntropy_entropy (p : Distribution α) : IsEntropy p (entropy p) := …

@[characterization uniqueness]
theorem IsEntropy.unique (h₁ : IsEntropy p x) (h₂ : IsEntropy p y) : x = y := …
```

The difference that matters for an auditor is that these shapes are *verified* — the existence
theorem really has to state that the definition satisfies the property, the uniqueness theorem
really has to relate two objects that satisfy it — so a complete bundle is a checked fact rather
than an author's claim. What is still not checked is whether the property says anything worth
saying, which is why the property and the relation are things a reader has to read.

The site renders this as a **Characterization** section on the definition's page, above the
Specification section and for the same reason the two are ordered that way: a characterization
answers the same question and settles it, where a specification only narrows it. Each claim is one
card, and the card leads with the relation — `x = y` and `f =ᵐ[μ] g` are very different statements
about how well a definition is pinned down, so the site prints which one it is rather than reporting
"characterized" and leaving it there. Directly under it comes the relation's own definition, because
naming the conclusion is not stating it: `Indistinguishable μ A ⟨M⟩` reads as reassurance whether it
means "agree almost surely at every time" or something much weaker. A relation declared by the
project gets its source form and a link; one from an upstream package gets the type and body the
graph panels show; one from the toolchain gets nothing, since `=` and `↔` are not what a reader is
stuck on. Underneath are the three declarations with their statements in full, since reading the
property is the only way to tell whether the claim is worth anything, and a note saying exactly
that. An unfinished claim — a property with no uniqueness theorem — is drawn as
a gap rather than dropped, and says which half is missing. Each of the three declarations gets a
*Part of a characterization* back-link on its own page, so a reader landing on `IsEntropy.unique`
learns what it is for.

**The Specification section does not repeat any of it.** Both theorems of a characterization also
register as `@[specifies]` annotations — that is what lets a consumer which only knows about
specifications still see them — so a characterized definition would otherwise list them twice on one
page: once inside the claim that determines it, and again below as loose properties it happens to
satisfy. The second listing is strictly weaker and says nothing the first did not, so whatever the
Characterization section showed is dropped from the Specification section below it, which says so
when its count no longer matches the project's annotations. The same holds in the other direction: a
theorem that is one of a claim's three parts gets the *Part of a characterization* back-link and not
a second *Part of a specification* one. A definition whose only `@[specifies]` theorems are its
characterization's therefore has no Specification section at all — and is *not* told it has no
specification, because it has one, directly above.

**A complete claim also gets its own dependency graph.** The picture a declaration page draws is
what the definition is *built from*, which for a constructed object is an expensive answer to a
question the reader may not be asking: building a stochastic integral is work, and recognising one
is a predicate. So the graph on a characterized definition's page carries a switch — *Construction*
against one *via `IsEntropy`* per complete claim — and the second view draws the property, the
relation the uniqueness theorem stops at, and everything those two mean. The definition and the two
theorems appear in it but are not expanded: that is the claim the view is making, and the note above
the picture gives both node counts so the gap between them is a number rather than an impression.

Only complete bundles get a view. Existence without uniqueness determines nothing, so offering it as
something to read *instead of* the construction would send a reader away thinking they knew what the
object was.

Both theorems also register as `@[specifies]` annotations, so everything above applies to them
unchanged: a characterized definition counts as specified on the Specifications page and the Browse
column with no extra work. Those two pages do not yet separate the characterized from the merely
specified; `LeanSpec.characterizations`, and `DeclInfo.characterizedBy` downstream of it, expose the
distinction for when they do.
