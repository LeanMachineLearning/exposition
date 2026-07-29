# Upstream trust

Every other measure on the site stops at the project boundary and treats what lies beyond it as
given. For a Mathlib-based development that is the larger half of what a reader is asked to accept,
and it is not uniform: `AlphaRAR` rests on `LeanMachineLearning`, which rests on `mathlib`, and a
referee may well have audited one and not the other.

`--trust PKG` says which. The trust page then draws the package dependency graph — toolchain at the
top, project at the bottom — with unaudited packages dashed, lists them with how many declarations
rest on each, and each of those declarations names them on its own page.

Three things the flag means, which are easy to get wrong in either direction:

- **It is transitive.** Trusting a package necessarily vouches for what it is built from — Mathlib's
  own theorems rest on Batteries — so `--trust mathlib` marks Batteries trusted too. Anything else
  would be incoherent: you cannot believe a theorem while doubting what proves it.
- **The Lean toolchain is always trusted**, with no flag. It is the compiler and kernel that checked
  everything else, this tool included; a site premised on doubting it could report nothing at all.
- **The default is to trust nothing.** With no `--trust` at all, every upstream package counts as
  unaudited and the page says so, rather than quietly assuming that whatever is popular is fine.

It is repeatable, and a render-time flag: the same `data.json` can be rendered under different trust
assumptions without re-importing the project, so "what would this look like if I had not audited
LML?" costs one flag and a rebuild of the HTML.

The per-declaration dependency graphs carry the same information one level down: the upstream
declarations an unaudited package contributes are drawn as nodes — dashed, greyed, and not links,
since this site exposes no page for them — in the top row, where nothing precedes them. Only
unaudited packages, and only what a statement names: drawing trusted upstream would put several
hundred Mathlib nodes on every page, and drawing proof-only references would add constants the kernel
has already checked. On `AlphaRAR` that comes to at most 9 extra nodes on any page and none on most,
because the entire trust surface into `LeanMachineLearning` turns out to be 15 declarations — the
sort of thing worth knowing before deciding whether to audit a dependency.

Three things are worth knowing about how the analysis is computed, because they bound what it
claims:

- **It is package-granular, not constant-granular.** A full constant-closure walk into Mathlib, once
  per declaration, is not affordable (`Lean.collectAxioms` only gets away with it because axioms for
  imported constants are precomputed in an environment extension, so its walk stops at the project
  boundary). What is recorded instead is the packages a declaration's project-level closure
  references directly, closed over the Lake dependency graph at render time.
- **That closure is sound.** A constant can only reference what its own package imports, so if a
  declaration's closure reaches a package, that package is reachable in the Lake graph from one it
  references directly. The analysis therefore cannot miss an upstream dependency — the direction that
  matters, since under-reporting would tell a reader they do not rest on code they do.
- **It is bounded by what was actually loaded.** Closing the Lake graph alone over-reports badly:
  `LeanMachineLearning` declares a dependency on Verso for building its own site, which would make
  every declaration using LML appear to rest on Verso, SubVerso, MD4Lean and Illuminate. None of that
  code is in the imported environment, so no closure can reach it, and it is excluded. On `AlphaRAR`
  this is the difference between reporting 5 unaudited packages and reporting the 1 that is real.

## What counts as an upstream trust dependency

Not what a proof calls. An upstream *proof* was rechecked by the kernel, and anything left unproved
in one arrives as a `sorry` or an extra axiom — both of which `collectAxioms` already reports
transitively, upstream included, on the trust page. A theorem whose proof calls a
`LeanMachineLearning` lemma has learned nothing from that call that it needs to take on faith.

What counts is an upstream *definition that a statement is about*. If a theorem's statement mentions
`Learning.IsAlgEnvSeq`, then what the theorem *means* depends on that definition being the intended
one, and no proof anywhere settles it — the same gap `@[specifies]` records, one package up.

So the measure follows `meaningDeps`, the same edges the rest of the site uses: a theorem contributes
its statement, and a definition the *data* in its body — its body is part of its meaning, but the
proof obligations bundled into it (`left_inv`, `map_add'`, …) are kernel-checked like any other
proof and are dropped for the same reason a theorem's proof is. The
difference is not cosmetic. On `AlphaRAR`, following proofs reported 172 declarations as resting on
`batteries`; following statements reports none, because no statement in the project mentions a
Batteries definition — every one of those 172 was a kernel-checked proof detail needing no audit.
