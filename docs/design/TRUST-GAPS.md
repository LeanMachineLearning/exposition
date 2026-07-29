# Trust gaps

Auditing aspects and tools this repository does not cover, organised by *how* they build trust rather
than by feature. Written as a survey to argue with; nothing here is committed to, and nothing here
duplicates [PROPOSED-TOOLS.md](PROPOSED-TOOLS.md) except where it says so.

## The framing

Referee has one epistemic channel: **a human reads statements, statically, from one build of one
project.** Everything in it — the `typeDeps`/`deps` split, the trust page, minimal files, verdicts,
revisions, provenance — is a refinement of *help the right reader read the right things in the right
order, and remember what they read*. It is good at that, and most of PROPOSED-TOOLS extends the same
channel: unfolding, blast radius and path queries are all still "help them read".

The uncovered space is the other channels. Six of them follow.

## 1. Disconfirmation — trust by trying to break the library

Nothing in the repository ever attacks the project. Inhabitation (§4 of PROPOSED-TOOLS) and
triviality (§7) are the two proposed toes in this water; the channel is much wider, and it produces
*findings*, which reading produces only by luck.

- **Unused hypotheses.** A binder in a theorem's statement that its proof term never mentions. Cheap
  — the proof term and the binder structure are both already in hand — and it is a two-sided smell:
  either the theorem is stronger than stated, and the statement is wrong, or the hypothesis is
  decorative and the reader has been misled about what the result needs. The cheapest high-yield
  check missing.
- **Vacuous hypotheses.** Weaker than inhabitation and a different failure: not *is this type ever
  built* but *can these hypotheses hold simultaneously*. `IsAlgEnvSeq X ∧ h : n < 0` is a true
  theorem about nothing. Partly attackable by running `omega` / `simp` against the hypothesis set
  alone; the evidence is asymmetric, like §7, and the page has to say so.
- **Mutation testing of statements.** Flip `≤` → `<`, swap two quantifiers, delete a hypothesis,
  weaken a type class — then recompile the *original* proof. A proof that still closes says the
  statement was not pinned down by its proof. A genuinely different technology from anything here,
  and the Claims page is a small enough target — dozens, not 1677 — to make it affordable. The
  per-declaration Lean fan-out (`--jobs`) already exists.
- **Execution.** The tool is entirely read-based; Lean can *run*. `#eval` on concrete instances,
  `decide` on small cases, property-based falsification (Plausible) against decidable
  specifications. A definition a referee cannot check by reading, they can often check by computing
  one example.

## 2. The trusted computing base below the axiom list

§5 covers the declaration-level half — `native_decide`, `@[implemented_by]`, `@[extern]`, `unsafe`,
`partial`, `opaque`. The **build-level** half is absent from both the code and the proposals, and it
is the half an adversary would use.

- **`set_option` in source.** `debug.skipKernelTC` turns the kernel off for a declaration and
  nothing reads it, though [Referee/Extract.lean](../../Referee/Extract.lean) already parses `set_option`
  for extraction purposes, so the syntax is in hand. `autoImplicit` is the subtler one: a mistyped
  identifier in a statement silently becomes a universally quantified variable, which is exactly how
  a theorem becomes vacuous while reading correctly.
- **The lakefile.** `leanOptions`, `moreLeanArgs`, custom build facets, `precompileModules`.
  `lakefile.lean` is arbitrary code that runs at build time, and Referee reads it only for import
  roots. A referee is entitled to see the build configuration as part of the trust surface.
- **Notation and instances.** A statement that *reads* as standard mathematics because the project
  redefined the notation, or because `≤` elaborated to a project-local `LE` instance, is the attack
  the source-first card is most exposed to. §6's `pp.notation false` view catches half of it. The
  other half is disclosure: **which instances a statement's elaboration actually picked**, flagged
  where they are project-local for a standard class.

## 3. Correspondence to something outside Lean

The Specifications page asks whether a definition has properties stated about it. It cannot ask
whether those are the *right* properties, and nothing here connects to the artifact the referee was
actually handed — a paper.

- **A paper ledger.** Each claim tagged with the paper's numbering, and — the part that matters —
  **the inverse index**: which numbered results in the paper have no Lean counterpart. Referee's
  denominator is always the library, so it structurally cannot report "Theorem 3 is not formalised".
  Blueprint import (§9) is the same idea for projects that have a blueprint; most refereeing
  situations do not.
- **Author-declared agreement with standard definitions.** Mathlib-overlap *detection* was rejected,
  correctly, as a prospective-user question. The referee-facing version is a different thing:
  `@[agrees_with]` pointing at a bridge theorem proving the project's definition coincides with an
  upstream one on the overlap. That converts the hardest reading task into a kernel-checked fact,
  which is the trade the rest of the tool makes everywhere else.
- **Docstring ↔ statement agreement**, and the more general natural-language back-translation
  channel. This is where an LLM would fit and where the repository is deliberately empty. Its
  honesty rule would be §7's: a disagreement is informative, an agreement means nothing.

## 4. Reproduction and supply chain

This channel undercuts a feature that is already built: nothing records **what was built**.

- **`--trust mathlib` does not say which mathlib.** An audit of `mathlib@abc123` is not an audit of
  `mathlib@def456`, and a forked dependency with a patched definition is invisible to the whole
  trust analysis. [lake-manifest.json](../../lake-manifest.json) has the revisions; recording them in
  `data.json` and printing them on the trust page is nearly free, and makes the existing page mean
  what it currently only implies.
- **Was the tree clean?** Provenance pins source links to the folded commit, but nothing states
  whether `collect` ran against uncommitted changes. A site built from a dirty tree describes a
  revision nobody else can obtain.
- **A semantic-hash root.** The per-declaration hashes are already there; a Merkle root over them is
  one short string naming *the meaning of this library at this revision* — citable in a referee
  report, in the audit export, in the paper. It turns "I read the site" into "I read the site of
  *this*", and it is the anchor every other artifact here lacks.
- **Independent rebuild attestation.** With that root, a second party rebuilding from the stated
  revisions and getting the same root is evidence of a kind nothing else in the tool produces: not
  *I read it* but *someone else got the same thing*.

## 5. More than one reader

[docs/audit.md](../audit.md) is explicit that nothing is authenticated, and PROPOSED-TOOLS rejects
server, accounts and signatures for a good reason — an operator makes the artifact stop being a file
the reader owns. Two of those three need no operator.

- **Detached signatures.** `minisign` or GPG over the export, verified client-side against a key the
  reader supplies. No server, no accounts; the file stays a file.
- **Merging audit files.** `referee merge a.json b.json` — and the output worth building it for is
  not agreement but **disagreement**: the declarations where two competent readers reached different
  verdicts. That is the highest-value signal in the whole exercise, and nothing today can produce
  it, because the state is per-browser by construction.

## 6. Trusting Referee

Everything on the site is downstream of the dependency analysis being right, and
[KNOWN-ISSUES.md](../../KNOWN-ISSUES.md) records that it carried 188 impossible edges until recently —
edges that were silently making extractions compile. A reader has no way to check any of it.

- **Differential checking, already sitting in the repository.** `extract` and `extract-flat` are two
  independent implementations of the same closure, one over source text and one over the
  environment. Where they disagree about what a declaration depends on, one of them is wrong. A free
  bug oracle, built without meaning to.
- **Compile status as published evidence.** It currently lives in
  [scripts/check-extracted-compile.sh](../../scripts/check-extracted-compile.sh) and is explicitly out of
  `data.json` (see §1's "what it deliberately does not cover"). A per-declaration *this minimal file
  compiles* is the one claim on the site a reader can verify without trusting the tool at all, which
  is an argument for making it first-class rather than a measurement in a markdown file.
- **A small independent verifier.** "This claim's closure contains a `sorry`" is about twenty lines
  against the `.olean`. Shipping that separately means the most consequential claim on the site does
  not rest on the whole of Referee being correct.

## 7. Trust over time, as policy rather than as a view

[docs/ci.md](../ci.md) builds the site in CI; it gates on toolchain mismatch and on missing hashes,
not on trust regressions. The missing piece is `referee check --policy`: fail the build when a
claim's closure gains a `sorry`, when a covered claim becomes uncovered, when a new axiom appears,
when an extraction stops compiling. The revision machinery computes all of it already; what is
missing is the exit code. Establishing trust once and maintaining it are different products, and
only the first exists.

## 8. An existing tool that fits: Comparator

Most of the above is work to be designed. One piece is off the shelf.
[Comparator](https://github.com/leanprover/comparator) takes a **Challenge** module — theorems
stated with `sorry`, plus *definition holes* — and a **Solution** module, and certifies that each
named theorem in the solution proves **the same statement** as the challenge, uses no axiom outside
a `permitted_axioms` allowlist, and is accepted by the Lean kernel replaying a
[`lean4export`](https://github.com/leanprover/lean4export) dump — optionally cross-checked by
[`nanoda`](https://github.com/ammkrn/nanoda_lib), a second and independently implemented kernel —
with the whole compile-and-export step sandboxed by `landrun`.

`referee extract` already emits a Challenge module. The minimal file *is* the statement with its
closure inlined and its proofs replaced by `sorry`, under fully-qualified names, which is the
property that makes the comparison mean anything: challenge and solution have to agree on constant
names. So **challenge = the extracted minimal file, solution = the real project module.**

**It closes §6 above.** Today the extraction check is
[scripts/check-extracted-compile.sh](../../scripts/check-extracted-compile.sh), and compiling proves the
file is *well-formed*, not that it says the same thing as the declaration it claims to represent.
That gap is not hypothetical here: [KNOWN-ISSUES.md](../../KNOWN-ISSUES.md) records extractions that
compiled *by accident*, because 188 spurious edges dragged in a declaration the file needed; and its
signature-narrowing section records the sharper case, where sorrying a definition's value silently
drops `variable` binders, so the extracted declaration has a **different type** while compiling
perfectly. Both were found by hand. Statement equality catches that whole class mechanically, which
matters more here than in most tools, because [WEBSITE-DESIGN.md](WEBSITE-DESIGN.md) §2 makes the
minimal file the audit unit — and the audit unit's fidelity currently rests on the tool being right.

The cost is roughly what is already paid: a Comparator run is a compile plus an export, and
`check-extracted-compile.sh` over a corpus is already the slow step. A strictly stronger result for
the same order of price is the strongest argument for doing it.

**Its stated limitation is exactly this tool's job.** A definition hole is checked for name, type,
universe level and safety, never for meaning, so Comparator's README says hole-based challenges "can
be gamed without additional oversight" — the same gap [docs/trust.md](../trust.md) draws around
upstream definitions. The two compose: Comparator certifies the type-level correspondence, the audit
page records the human judgement about meaning. Neither can do the other's half, and saying so on
the site would sharpen both claims.

**And it supplies two things named above.** `enable_nanoda` is the independent-kernel half of §4:
the trust page's "the kernel rechecked it" currently means the same binary that elaborated
everything, and two implementations is a different sentence. `permitted_axioms` with a nonzero exit
code is half of §7's `referee check --policy` already written — and better than gating on Referee's
own analysis, since the verdict comes from a kernel replaying an export rather than from the tool
grading its own homework. `landrun` also names a risk [docs/ci.md](../ci.md) does not: building
the site means executing a `lakefile.lean` from the project under review.

**What it does not do, and what it costs.**

- It says nothing about meaning. This strengthens the provability axis and the tool-fidelity axis;
  the reason the rest of the site exists is untouched.
- Scale is the open question. A brownian-motion minimal file inlines a large closure and every
  sorried lemma in it is a hole. Type comparison is cheap, but whether Comparator is content with
  hundreds of holes per challenge is the thing to test on one declaration before designing anything
  around it.
- `extract-flat` is the better challenge for certification — 100% compiling, faithful by
  construction from `ConstantInfo` — while `extract` stays the readable tier. Which suggests
  certifying the readable file *against the flat one* as a cheaper intermediate check, needing no
  external tooling at all.
- Three more version-locked binaries. That is the call `semantic_hash` already forced, and the
  answer is presumably the same: a binary on disk and a hard failure on mismatch, not a Lake
  dependency.

**What the site gains** is a per-declaration badge that cannot exist today — *statement certified
against the library · proof accepted by two kernels · axioms within policy* — and, more valuable,
the honest failure state **"this minimal file compiles but does not prove the same statement"**, a
category the site is blind to and which signature narrowing shows is real.

## If three get built

**Unused hypotheses** — the cheapest real finding here, and it needs no new phase. **Dependency
revisions and a hash root** — small, and it repairs the fact that the trust page vouches for a
package without naming it. **Audit-file merge with disagreement reporting** — the only item that
adds a whole channel, and it needs no server to do it.

Ranked separately because it is not work to be designed: **§8**, one Comparator run against one
extracted file, to find out whether the fit is real before anything is built on it.
