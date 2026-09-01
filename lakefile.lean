import Lake
open Lake DSL

package Referee where
  version := v!"0.1.0"
  leanOptions := #[⟨`autoImplicit, false⟩]

require verso from git "https://github.com/leanprover/verso" @ "v4.34.0-rc2"

/-- The `@[specifies]` and `@[characterization]` attributes, in a *separate, dependency-free
package* rather than a library of this one. A project that wants to annotate its specifications must
depend on it, and must not have to drag in Verso to do so — which is why it is a repository of its
own, with its own checks.

This tool depends on it for the other end of the same wire: reading the annotations back out of a
target project needs the environment extension registered in *this* process, since imported
extension entries are matched to registered extensions by name and silently dropped otherwise. -/
require Characterization from git "https://github.com/RemyDegenne/characterization" @ "main"

/-- Declaration-dependency analysis, in a *separate, dependency-free package* rather than a library
of this one, for the same reason as `Characterization`: it is useful on its own to any project that
wants to know what its declarations rest on, and requiring it must not drag in Verso and the rest of
this tool's build.

That independence is why it is a repository of its own rather than a subdirectory here, and its own
tests and proofs went with it. This tool is one such consumer — `Referee/Collect.lean` delegates
every dependency computation to it — but it is not a privileged one. -/
require MeaningGraph from git "https://github.com/RemyDegenne/meaning-graph" @ "main"

/-- Standalone-file extraction: one declaration turned into a file that compiles on its own, its
dependencies inlined and its proofs `sorry`ed. A *separate, dependency-free package* for the same
reason as the others, and with a consumer in mind that is not this tool at all — a challenge
generator, which wants the files and none of the site.

The seam is `ChallengeGen.ChallengeDecl`, four fields wide: `DeclInfo.toChallengeDecl` is the whole
of what this tool hands over. Everything the extraction needs beyond that it takes from the
compiled environment itself, which is why it does not need `collect` to have run — only for
something to say which declarations to extract and what each one's closure is.

That independence is why it is a repository of its own rather than a subdirectory here, and its own
checks went with it. -/
require ChallengeGen from git "https://github.com/RemyDegenne/challenge-gen" @ "main"

/-- Junk-value analysis — where a definition rests on the value a total function returns outside the
domain its name suggests — as a *separate, dependency-free package*, for the same reason as
`Characterization` and `MeaningGraph`.

Its independence is load-bearing in one extra way: the analysis is most useful *while writing*, as a
linter in the project being developed, and a project cannot take on a linter that drags Verso in
behind it. It also, deliberately, does not depend on Mathlib, although that is where nearly every
rule it ships comes from. -/
require JunkValues from "JunkValues"

/--
The site's CSS and JavaScript, authored as real files and embedded with `include_str`.

Declared as a Lake input so that editing an asset actually rebuilds the module that embeds it.
Without this, `include_str` is invisible to Lake's change detection: `lake build` reports success,
keeps the stale `.olean`, and the site is silently built from the previous version of the file.
Verso declares its own web assets the same way.
-/
input_dir websiteAssets where
  text := true
  path := "Referee/Website/assets"

lean_lib Referee where
  needs := #[websiteAssets]

lean_lib Test where
  globs := #[`Test, `Test.Audit, `Test.Collect, `Test.Diff, `Test.Highlight, `Test.JunkValues,
    `Test.JunkValuesExtra, `Test.Provenance]

/-- Theorems about the library, as opposed to the `#guard` examples in `Test`.

Kept a separate target because the two answer different questions and fail differently: a `#guard`
regression says one input now behaves differently, a broken proof says a claim the documentation
makes is no longer true. Run with `lake build Proofs`. -/
lean_lib Proofs where
  globs := #[`Proofs, `Proofs.Collect, `Proofs.Diff, `Proofs.Provenance]

@[default_target]
lean_exe referee where
  root := `Main
  supportInterpreter := true
