# Claims: what the project says it proves

Every page of a Referee site is derived from the compiled library, with one exception. If the
project root holds a `formalization.yaml` declaring `status.main_results`, the site gains a **Claims**
page listing those results — the project's own statement of what the work is for.

The file is the metadata document the [Palomar registry](https://palomar-registry.org/) requires of a
submission ([schema](https://github.com/mathlib-initiative/formalization.yaml),
[template](https://github.com/PalomarRegistry/PalomarTemplate)). Nothing here asks a project to
adopt it for Referee's sake: a project that has one gets a page, and a project that does not is never
told about it.

## Why this is a page and not a section of the Theorems page

Because they answer different questions, and only one of them can be got wrong.

[Theorems](audit.md) is derived: everything the library states with the `theorem` keyword rather than
`lemma`. It cannot be wrong about what the library states — at worst it inherits a project's
carelessness about the two keywords, which the page says out loud.

Claims is a sentence the author wrote. It can name a result that does not exist, omit the one that
matters, or put forward as a headline something the library proves in passing. That is not a defect
of the file; it is what a *claim* is, and a referee's first question is whether it holds. Merging the
two lists would have hidden which half was measured and which half was asserted.

Where the two disagree, the disagreement is information. A main result stated as a `lemma` is a
keyword the author should reconsider. A theorem the file passes over is either machinery or an
omission, and only the author knows which.

## What the page shows

The rows are the Theorems page's rows, deliberately unchanged: the same link, the same count of what
the statement rests on, the same `sorry` flag, and the same audit verdict under the same key — a
declaration accepted on one page is accepted on the other, because it is one declaration. What
differs is which declarations appear and in what order. Here the order is the file's, because a
curated list is an argument about what matters and its order is part of the argument.

The audit apparatus — export, import, report, the progress summary — stays on the Theorems page. This
page carries the handful of results the author chose, not a reading queue.

Below the list, three things the compiled library cannot supply:

- **Results the library does not have.** A `main_results` entry naming a declaration that is not
  exposed is listed with the file the metadata claims it lives in. Usually a rename the file did not
  follow. `collect` also warns about it on the console, where the author is the person who can act.
- **Literature dependencies.** `literature_dependencies` records results the project relies on but
  does not prove. A theorem taken from the literature leaves behind no `sorry` and no extra axiom, so
  nothing on the [sorries and assumptions](trust.md) page can report it — the assumption is in the
  author's prose. Neither list bounds the other.
- **Scope.** `status.scope`, verbatim: the weakened hypothesis or the omitted case that no list of
  theorem names can show.

## What it deliberately ignores

`main_results` entries also carry a `sorry_count` and an `axioms` list. The site does not render
them, because it measures both itself and the two measurements are not the same measurement — the
file's counts exclude Comparator challenge modules, this site's do not. Showing them side by side
would invite a comparison that means nothing. The row shows what this build measured.

## The parser

`Referee/Formalization.lean`, and it is a subset of YAML rather than the whole of it: block mappings
and sequences, one-line flow collections, quoted and plain scalars, folded and literal block scalars,
and comments. No anchors, no aliases, no tags, no multi-document streams past the first. Taking on a
YAML dependency for one file at the edge of the build was the worse trade — each package this tool
requires is there to be useful without it, and none of them wants a YAML reader.

The cost is honest and worth stating: an unsupported construct yields a wrong reading, not an error.
The one exception is a tab in a line's indentation, which is refused — it changes structure
invisibly rather than content, which is the failure a reader would never catch. Everything else is
bounded by the fields the site actually reads, each of which has a harmless default, so a misread
field goes missing from the page rather than appearing wrong on it.

A file that will not parse is a warning on the console and no Claims page. It is never a build
failure: the file sits beside the library rather than inside it, and trading the whole report for one
malformed page would be the wrong way round.

`Test/Formalization.lean` pins the cases a subset parser actually gets wrong — `- key: value` sharing
a line with its dash, a `:` inside a URL, a `#` inside quotes, folded versus literal blocks, and
plain scalars continued across a blank line.
