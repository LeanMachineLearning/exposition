# Theorems and audit state

The Theorems page carries both, because they were never two questions. It lists what the library
states with `theorem` — see [Authoring](authoring.md) for why that keyword is the signal — and
against each one what the *reader* has made of it. Every other page on the site is derived from the
compiled library; this half of this one is not.

They were two pages, and the split was wrong in both directions: the claims list could not say which
of them you had been through, and the audit checklist repeated the list without ever saying what
makes a declaration a claim. The page now reads in the order the questions arrive — what does this
library claim, what does accepting one mean, which are they, and how far have you got.

Two things are tracked per declaration, and only one of them is the reader's to set:

- a **verdict** — *unread*, *accepted* or *query* — where accepted means "I read this and it says
  what its name claims", and a query carries a note;
- **coverage**, which is derived: accepted, *and* every project declaration in its statement closure
  accepted too.

The state worth having a name for is the third one that falls out: **accepted but not covered**, a
reader who believes they are finished and is not. Accepting a regret bound without reading
`IsAlgEnvSeq` accepts a sentence, not a theorem, and a single checkbox per declaration cannot say
so. The headline number is therefore covered claims, not accepted declarations.

Deliberately orthogonal to trust: a `sorry`, an axiom or an unaudited package never blocks
acceptance. Accepting is a judgement about what a statement *means*; whether it is *proved* is what
the sorries page reports. Conflating them would make the checklist useless on any library still being
written. A claim whose closure reaches a `sorry` is *flagged* on its row all the same — the two
marks answer different questions, and a reader deciding what to read next wants both.

What a reader does with it:

- **A claim is audited from its own page, and does not send you anywhere else.** The control under
  the card records a verdict and a note on the statement itself; the dependency graph below draws
  every project declaration that statement rests on, and clicking any node opens that declaration's
  own card with a control of its own beneath it. So the whole closure is read, and judged, without
  leaving the page — and how far you have got is the picture: a green `✓` on every node is a covered
  claim.

  **Everything it rests on** in the graph's toolbar turns one click into the whole stack: the clicked
  node and every node above it, each with its card and its own verdict control, in the order the rows
  read — what depends on nothing first, the clicked node last. That is a claim's entire closure laid
  out to be worked through in one scroll. Cards load as you reach them rather than all at once, so
  the click is as fast on a closure of four hundred as on one of four. Upstream constants are left
  out of the stack and the line above it says how many: they have no page here, so no card, no
  docstring and no verdict — clicking one in the picture still shows its signature. The setting is
  remembered.

  This replaces a reading queue, which walked the same closure by navigating you through it one page
  at a time. The order it walked was the right one and the walking was the problem: every step lost
  the theorem you were trying to decide about. Nothing is left of it — no *Start reading*, no *next
  unread*, no `n`.
- Each control records a verdict, a note, and the warning that what you accepted has since changed.
  `a` / `q` / `u` set the verdict from the keyboard, on the control showing the `a · q · u` hint —
  whichever one is in the middle of the viewport, since with the stack open there can be forty of
  them down the page and no fixed choice is right for more than a few. Every control is titled with
  the declaration it is about, for the same reason.

  What it does not carry is a coverage line or *accept this and everything its statement rests on*.
  Both were questions about one particular closure, and a control that follows the reader from node
  to node is not always looking at one. Coverage is still counted, on the claims page and on the
  graph's marks.
- **Export** writes a JSON file — the artifact that actually travels. Re-importing it against a
  later build carries verdicts across, ignores declarations that no longer exist, and drops
  acceptances that the revision diff says are void, naming them. Where `--baseline` reports a
  removal and an addition with identical statements, the import offers to carry the verdict across
  the rename.
- **Generate report** writes Markdown: claims and their coverage, the open queries with their notes,
  and what the library rests on. Most of a referee report, already written.

The **landing page** carries the same rows for its ranked top results — the same coverage, the same
verdict, the same button. It is an excerpt rather than a second listing: what ships with it is those
claims and their closures, which is what their coverage is a question about, and not the rest of the
library. So a reader arriving with work already recorded sees it on the first page, and a list that
looked different there would have been a second thing to learn.

Verdicts also show up on the **dependency graphs**: a green `✓` in a node's corner is a declaration
you accepted, an amber `?` one you left a query on. That is where the question "how much of what
this rests on have I already been through?" is actually asked, and the picture answers it without a
detour to Browse.

You can also answer it there. Clicking a node opens that declaration's own card below the graph, and
under the card its own verdict control — so reading through what a theorem rests on, and recording
what you make of each piece, is done in the picture rather than by walking away from it and coming
back. The keys follow the open node and go back to the page's own declaration when you close it; the
control that has them is the one showing the `a · q · u` hint. Nothing in the upstream band gets a
control, for the same reason nothing there gets a mark: there is no page here on which to have read
it.

**Verdicts remember what they were about.** Each one records the declaration's semantic hash at the
moment it was set, which makes an exported file **self-baselining**: any later build can say which
acceptances are of something that has since changed, with no access to the build they were made
against and no `--baseline`. Those appear as *accepted, then changed* — a third state alongside
*accepted but not covered*, and excluded from every count on the page for the same reason, because
the flattering number is the one that misleads. Needs `--hashes`; without semantic hashes the check
is off, since a toolchain upgrade would otherwise report every acceptance in the file as void.

A stale acceptance carries **no graph mark**, for the same reason it is excluded from the counts: a
tick on a node you accepted when it meant something else is the one genuinely misleading thing that
picture could say.

Three limits, stated on the page itself rather than only here:

- **Nothing is authenticated.** The file is plain JSON that anyone can edit, and an accepted
  declaration is one that a human said says what its name claims. It is a work aid for the reader
  who made it and must never be offered to anyone else as evidence that a library was audited.
- **Nothing is verified.** The site records the judgement; it does not check it.
- **The browser is not storage.** State lives in `localStorage` under the project's name — which is
  also why the key is the project rather than the path: GitHub Pages serves every project of an
  account from one origin, so two referee sites would otherwise share one bucket. Clearing browser
  data deletes it, and a second reader on another machine shares none of it.
