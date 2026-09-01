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

- **Start reading** from a claim walks its statement closure in dependency order, so nothing is read
  before the definitions it is stated in terms of. That order is free — `transDeps` is already
  topologically sorted, because the extractor needs it that way to emit a compilable minimal file.
- On each declaration, `a` / `q` / `u` set the verdict and `n` moves to the next unread one in the
  queue. There is also *accept this and everything its statement rests on*, which matches the
  minimal file: that file **is** the closure inlined, so a reader who has read one has covered
  everything in it.
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
detour to Browse. The marks update as you set verdicts, including the bulk *accept everything its
statement rests on*, so the effect of that action lands where you can see it.

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
