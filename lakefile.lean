import Lake
open Lake DSL

package Referee where
  version := v!"0.1.0"
  leanOptions := #[⟨`autoImplicit, false⟩]

require verso from git "https://github.com/leanprover/verso" @ "main"

/-- The `@[specifies]` attribute, as a *separate, dependency-free package* rather than a library of
this one. A project that wants to annotate its specifications must depend on it, and must not have
to drag in Verso to do so.

This tool depends on it for the other end of the same wire: reading the annotations back out of a
target project needs the environment extension registered in *this* process, since imported
extension entries are matched to registered extensions by name and silently dropped otherwise. -/
require LeanSpec from "LeanSpec"

/-- Declaration-dependency analysis, as a *separate, dependency-free package* rather than a library
of this one, for the same reason as `LeanSpec`: it is useful on its own to any project that wants to
know what its declarations rest on, and requiring it must not drag in Verso and the rest of this
tool's build.

This tool is one such consumer — `Referee/Collect.lean` delegates every dependency computation to
it — but it is not a privileged one. -/
require LeanDeps from "LeanDeps"

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
  globs := #[`Test, `Test.Audit, `Test.Characterization, `Test.Collect, `Test.Deps, `Test.Diff,
    `Test.Extract, `Test.Provenance, `Test.Spec]

@[default_target]
lean_exe referee where
  root := `Main
  supportInterpreter := true
