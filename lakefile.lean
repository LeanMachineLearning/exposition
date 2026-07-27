import Lake
open Lake DSL

package LMLExposition where
  version := v!"0.1.0"
  leanOptions := #[⟨`autoImplicit, false⟩]

require verso from git "https://github.com/leanprover/verso" @ "main"

/--
The site's CSS and JavaScript, authored as real files and embedded with `include_str`.

Declared as a Lake input so that editing an asset actually rebuilds the module that embeds it.
Without this, `include_str` is invisible to Lake's change detection: `lake build` reports success,
keeps the stale `.olean`, and the site is silently built from the previous version of the file.
Verso declares its own web assets the same way.
-/
input_dir websiteAssets where
  text := true
  path := "LMLExposition/Website/assets"

/-- Standalone declaration-dependency analysis: depends on Lean core only, and on nothing else in
this repo. Kept a separate library so that dependency direction stays enforced by the build. -/
lean_lib LeanDeps

lean_lib LMLExposition where
  needs := #[websiteAssets]

lean_lib Test where
  globs := #[`Test, `Test.Collect, `Test.Deps, `Test.Extract]

@[default_target]
lean_exe exposition where
  root := `Main
  supportInterpreter := true
