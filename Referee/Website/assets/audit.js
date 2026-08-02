/*
 * Audit state: what the reader has decided, and what follows from it.
 *
 * Every other number on this site is derived from the compiled library. These are not derived from
 * anything — they are a reader's own judgements, recorded declaration by declaration.
 *
 * Two things are tracked per declaration and only one of them is the reader's to set:
 *
 *   - a verdict: unread / accepted / query, where accepted means "I read this and it says what its
 *     name claims", and a query carries a note;
 *   - coverage, which is derived: accepted, AND every project declaration in its statement closure
 *     accepted too.
 *
 * The state worth having a name for is the one that falls out of those two: `accepted but not
 * covered`, a reader who believes they are finished and is not. A checkbox alone cannot say it.
 *
 * A verdict also records WHAT IT WAS ABOUT: the declaration's semantic hash at the moment it was
 * set. That makes the file self-baselining — a later build of a revised library can say which
 * acceptances are of something that has since changed, with no access to the build they were made
 * against and no `--baseline`. Those are `stale`, the second thing a checkbox cannot say, and they
 * are excluded from every count rather than left to inflate one.
 *
 * Staleness needs a measure of meaning that survives a toolchain upgrade, so it exists only on
 * builds collected with `--hashes`; without them `meaning` is empty everywhere and every check
 * below short-circuits to false. See `meaningKeyOf` in `Referee/Audit.lean`.
 *
 * Storage is localStorage plus an exported file, because the site is static HTML with no server and
 * there is nowhere else it could live. Two consequences, both of which the page states rather than
 * hides:
 *
 *   - nothing here is authenticated. The file is plain JSON that anyone can edit, and it records
 *     that a human said they read something. It is a work aid, never evidence for a third party;
 *   - localStorage dies with a cleared browser profile, which is why export is a first-class button
 *     and why leaving with unexported changes warns.
 */
/*
 * Verso emits `extraJsFiles` into `<head>` without `defer`, so everything below has to wait for the
 * document: the payloads this reads are `<script type="application/json">` nodes in the body. That
 * also fixes the ordering `browse.js` depends on — handlers run in registration order and this file
 * is loaded first, so `window.RefereeAudit` is set before Browse looks for it.
 */
document.addEventListener('DOMContentLoaded', function () {
  'use strict';

  const STORAGE_PREFIX = 'referee-audit:';
  const FILE_VERSION = 1;
  const VERDICTS = ['unread', 'accepted', 'query'];

  // The change kinds that void an imported acceptance: those where the declaration means something
  // different from what the reader accepted. 'proof' is deliberately absent — the kernel rechecked
  // the proof, and a proof cannot change what a theorem says — and so is 'added', which has no
  // earlier acceptance to void. 'upstream' is here for the same reason 'indirect' is: the meaning
  // moved, only the cause lies outside what this site shows.
  const VOIDING = new Set(['statement', 'body', 'indirect', 'upstream']);

  // Reader-facing wording for a `ChangeKind` slug, used where a stale acceptance can also be
  // explained by the revision diff. Absent without `--baseline`, in which case staleness is
  // reported on its own — which is the point of recording meanings per verdict.
  const CHANGE_WORDS = {
    statement: 'statement changed',
    body: 'definition changed',
    indirect: 'meaning changed indirectly',
    upstream: 'meaning changed underneath',
  };

  const esc = s => String(s).replace(/[&<>"]/g,
    c => ({ '&': '&amp;', '<': '&lt;', '>': '&gt;', '"': '&quot;' }[c]));

  function readJson(id) {
    const node = document.getElementById(id);
    if (!node) return null;
    try { return JSON.parse(node.textContent); } catch (e) { return null; }
  }

  const auditData = readJson('audit-data');    // the audit page only
  const control = readJson('audit-control');   // a declaration page only
  const browseData = readJson('browse-data');  // the browse page: carries the project name only

  // The project name is the whole storage key. GitHub Pages serves every project of an account from
  // a single origin and localStorage is per-origin, so keying by nothing would let two referee sites
  // clobber each other; keying by path would lose the state whenever the site moved.
  const project = (auditData && auditData.project) || (control && control.project)
    || (browseData && browseData.project) || '';
  if (!project) return;
  const key = STORAGE_PREFIX + project;

  // ---------------------------------------------------------------- storage

  function blank() { return { version: FILE_VERSION, project: project, verdicts: {} }; }

  function load() {
    try {
      const raw = localStorage.getItem(key);
      if (!raw) return blank();
      const s = JSON.parse(raw);
      if (!s || typeof s !== 'object') return blank();
      s.verdicts = s.verdicts || {};
      return s;
    } catch (e) { return blank(); }
  }

  let state = load();
  let dirty = false;

  function save() {
    try { localStorage.setItem(key, JSON.stringify(state)); } catch (e) { /* quota, private mode */ }
  }

  const entry = name => state.verdicts[name] || {};
  const verdictOf = name => entry(name).verdict || 'unread';
  const noteOf = name => entry(name).note || '';

  // `meaning` is what the declaration meant when the verdict was set, carried so that a later build
  // can tell that it no longer means that. Every caller has to supply it, because only the caller
  // knows which declaration's payload it is holding — the alternative would be shipping a
  // name-to-meaning map on every page, which is exactly the cost the closure indices avoid.
  function setVerdict(name, verdict, note, meaning) {
    const prev = entry(name);
    const nextNote = note === undefined ? (prev.note || '') : note;
    if (verdict === 'unread' && !nextNote) delete state.verdicts[name];
    else state.verdicts[name] = {
      verdict: verdict,
      note: nextNote,
      at: new Date().toISOString(),
      meaning: meaning || '',
    };
    dirty = true;
    save();
    document.dispatchEvent(new CustomEvent('referee:auditchange', { detail: { name: name } }));
  }

  /*
   * Whether an acceptance is of something this build no longer says.
   *
   * False whenever it cannot be established rather than when it is disproved: no current meaning
   * (a build without `--hashes`), or no recorded one (a verdict set before this existed, or
   * imported from such a file). Guessing in either case would manufacture staleness out of a
   * missing field, and the whole value of the flag is that it is never wrong when it fires.
   */
  function isStale(name, currentMeaning) {
    const rec = entry(name);
    if (rec.verdict !== 'accepted') return false;
    if (!currentMeaning || !rec.meaning) return false;
    return rec.meaning !== currentMeaning;
  }

  // An acceptance of something that has since changed is not an acceptance of what is on the page
  // now, so it does not count as one. Everything derived — coverage, the tallies, the queue — goes
  // through this rather than through `verdictOf`, so that none of them can report a reader as
  // further along than they are.
  const acceptsNow = (name, currentMeaning) =>
    verdictOf(name) === 'accepted' && !isStale(name, currentMeaning);

  // browse.js reads this to fill its Verdict column. Exposed rather than duplicated so that the two
  // views can never disagree about what a verdict is.
  window.RefereeAudit = {
    verdictOf: verdictOf,
    noteOf: noteOf,
    setVerdict: setVerdict,
    isStale: isStale,
  };

  window.addEventListener('beforeunload', e => {
    if (!dirty || !state.exportedAt) return;
    e.preventDefault();
    e.returnValue = '';
  });

  function download(filename, text, mime) {
    const blob = new Blob([text], { type: mime || 'application/json' });
    const url = URL.createObjectURL(blob);
    const a = document.createElement('a');
    a.href = url;
    a.download = filename;
    document.body.appendChild(a);
    a.click();
    a.remove();
    setTimeout(() => URL.revokeObjectURL(url), 0);
  }

  // ------------------------------------------------- the declaration control

  if (control) {
    const host = document.getElementById('audit-control-root');
    if (host) renderControl(host);
  }

  function renderControl(host) {
    const name = control.name;
    const closure = control.closure || [];
    const meaning = control.meaning || '';
    // Positionally parallel to `closure`; see `AuditControlData.closureMeanings` for why it is a
    // separate array. Missing entries degrade to '' and simply go unchecked.
    const closureMeanings = control.closureMeanings || [];
    const meaningAt = i => closureMeanings[i] || '';

    host.innerHTML = `
      <div class="audit-control">
        <!-- Titled because everything else on the page is derived from the library and this is not:
             it is the one box whose contents are the reader's own, and it should not be mistaken
             for something the tool is asserting. The qualifier says where it lives, which is the
             other thing a reader has to know before typing into it. -->
        <div class="audit-control-head">
          <span class="audit-control-title">Your audit</span>
          <span class="audit-hint">private to this browser</span>
        </div>
        <div class="audit-row">
          <div class="audit-verdicts" role="group" aria-label="Your verdict">
            ${VERDICTS.map(v => `<button type="button" class="audit-verdict" data-v="${v}">
              ${v}</button>`).join('')}
          </div>
          <span class="audit-hint">a · q · u</span>
        </div>
        <textarea class="audit-note" rows="2"
          placeholder="Note — what you would ask the author"></textarea>
        <p class="audit-stale" id="audit-stale"></p>
        <p class="audit-coverage" id="audit-coverage"></p>
        <div class="audit-actions">
          ${closure.length
            ? `<button type="button" id="audit-accept-closure">Accept this and everything its
                 statement rests on (${closure.length})</button>`
            : ''}
          <a class="audit-link" href="claims/">Claims and progress →</a>
        </div>
        <p class="audit-queue" id="audit-queue"></p>
      </div>`;

    const noteBox = host.querySelector('.audit-note');
    noteBox.value = noteOf(name);
    noteBox.addEventListener('change', () =>
      setVerdict(name, verdictOf(name), noteBox.value, meaning));

    host.querySelectorAll('.audit-verdict').forEach(b => {
      b.addEventListener('click', () => setVerdict(name, b.dataset.v, noteBox.value, meaning));
    });

    const acceptAll = host.querySelector('#audit-accept-closure');
    if (acceptAll) {
      // The minimal file for this declaration *is* its closure, inlined. A reader who has read one
      // has legitimately covered everything in it, so the bulk action matches the artifact rather
      // than being a shortcut around it.
      acceptAll.addEventListener('click', () => {
        closure.forEach((d, i) => {
          if (verdictOf(d.label) !== 'query') setVerdict(d.label, 'accepted', undefined, meaningAt(i));
        });
        setVerdict(name, 'accepted', noteBox.value, meaning);
      });
    }

    function paint() {
      const v = verdictOf(name);
      host.querySelectorAll('.audit-verdict').forEach(b =>
        b.classList.toggle('audit-verdict--on', b.dataset.v === v));

      // Above the coverage line, because it is the more urgent of the two: coverage says the
      // reading is incomplete, this says part of it was of something else.
      const staleBox = document.getElementById('audit-stale');
      staleBox.innerHTML = isStale(name, meaning)
        ? `<span class="audit-warn">You accepted a different version of this.</span> What you
           recorded was about the declaration as it meant something else; it has changed since.
           Re-read it and set the verdict again — until you do, it counts as unread everywhere on
           this site.`
        : '';

      const unread = closure.filter((d, i) => !acceptsNow(d.label, meaningAt(i)));
      const cov = document.getElementById('audit-coverage');
      const covered = v === 'accepted' && !isStale(name, meaning);
      // Named separately from the rest of the unread, because "you have not read this" and "what
      // you read is no longer what it says" send a reader to different places.
      const staleBeneath = closure.filter((d, i) => isStale(d.label, meaningAt(i))).length;
      const staleNote = staleBeneath
        ? (staleBeneath === 1
            ? ' One of them you accepted an earlier version of.'
            : ` ${staleBeneath} of them you accepted earlier versions of.`)
        : '';
      if (!closure.length) {
        cov.innerHTML = covered
          ? '<span class="audit-ok">Covered.</span> Its statement rests on nothing else in this project.'
          : 'Its statement rests on nothing else in this project.';
      } else if (unread.length === 0) {
        cov.innerHTML = covered
          ? `<span class="audit-ok">Covered.</span> You have accepted all ${closure.length}
             declarations its statement rests on.`
          : `All ${closure.length} declarations its statement rests on are accepted; this one is not.`;
      } else {
        const shown = unread.slice(0, 6).map(d =>
          `<a href="${esc(d.href || '')}"><code>${esc(d.label)}</code></a>`).join(', ');
        const more = unread.length > 6 ? `, and ${unread.length - 6} more` : '';
        cov.innerHTML = (covered
          ? '<span class="audit-warn">Accepted, but not covered.</span> '
          : '')
          + `${unread.length} of the ${closure.length} declarations its statement rests on are not
             accepted: ${shown}${more}.${staleNote}`;
      }
      paintQueue();
    }

    function paintQueue() {
      const box = document.getElementById('audit-queue');
      const q = state.queue;
      if (!q || !q.names || q.names.indexOf(name) < 0) { box.innerHTML = ''; return; }
      const pos = q.names.indexOf(name);
      // A stale acceptance is something still to read, so the queue has to stop at it. `meanings`
      // is absent from queues built before this existed, which leaves those queues behaving
      // exactly as they did.
      const meanings = q.meanings || [];
      const stillToRead = i => !acceptsNow(q.names[i], meanings[i] || '')
        && verdictOf(q.names[i]) !== 'query';
      const left = q.names.filter((n, i) => stillToRead(i));
      // The next thing to read, not merely the next in the list: a reader who accepted three in a
      // row should not be walked back through them.
      let nextAt = -1;
      for (let i = pos + 1; i < q.names.length; i++) {
        if (stillToRead(i)) { nextAt = i; break; }
      }
      if (nextAt < 0) for (let i = 0; i < pos; i++) {
        if (stillToRead(i)) { nextAt = i; break; }
      }
      const next = nextAt >= 0
        ? `<a id="audit-next" href="${esc(q.hrefs[nextAt])}">next unread →</a> <span
             class="audit-hint">n</span>`
        : '<span class="audit-ok">queue complete</span>';
      box.innerHTML = `Reading for <code>${esc(q.claim)}</code> — ${pos + 1} of ${q.names.length},
        ${left.length} still to read. ${next}`;
    }

    document.addEventListener('referee:auditchange', paint);
    paint();

    document.addEventListener('keydown', e => {
      if (e.metaKey || e.ctrlKey || e.altKey) return;
      const t = e.target;
      if (t && (t.tagName === 'INPUT' || t.tagName === 'TEXTAREA' || t.isContentEditable)) return;
      const k = e.key.toLowerCase();
      if (k === 'a') { setVerdict(name, 'accepted', noteBox.value); e.preventDefault(); }
      else if (k === 'q') { setVerdict(name, 'query', noteBox.value); noteBox.focus(); e.preventDefault(); }
      else if (k === 'u') { setVerdict(name, 'unread', noteBox.value); e.preventDefault(); }
      else if (k === 'n') {
        const link = document.getElementById('audit-next');
        if (link) { window.location.href = new URL(link.getAttribute('href'), document.baseURI); }
      }
    });
  }

  // ------------------------------------------------------------- audit page

  // The listing is server-rendered, so it exists whether or not this page has an `audit-root` to
  // build an apparatus in — the landing page has rows and no apparatus. Both need the state painted
  // onto the rows, so that is driven by the payload rather than by the mount point.
  if (auditData) {
    renderAudit(document.getElementById('audit-root'));
  }

  function renderAudit(host) {
    const names = auditData.names;
    const decls = auditData.decls;
    const index = {};
    names.forEach((n, i) => index[n] = i);

    // Everything derived goes through `accepts`, never through `verdictOf`: an acceptance of a
    // declaration that has since changed meaning is not an acceptance of what this build shows, and
    // counting it would make the headline number say the reader is further along than they are —
    // which is the exact failure this page was designed around.
    const meaningOf = i => decls[i].meaning || '';
    const accepts = i => acceptsNow(names[i], meaningOf(i));
    const staleAt = i => isStale(names[i], meaningOf(i));

    const coverage = i => {
      const c = decls[i].closure;
      let accepted = 0;
      for (let k = 0; k < c.length; k++) if (accepts(c[k])) accepted++;
      return { total: c.length, accepted: accepted };
    };
    const isCovered = i => accepts(i) && coverage(i).accepted === decls[i].closure.length;

    // The rows are on the page already, rendered in Lean with their docstrings; what is missing is
    // everything that depends on the reader. `paintRows` writes it into the two slots each row
    // carries, so a verdict change rewrites two spans per row rather than rebuilding the listing —
    // which also means the docstrings, and anything inside them, are never re-created.
    function paintRows() {
      document.querySelectorAll('.audit-item[data-claim]').forEach(item => {
        const i = index[item.dataset.claim];
        const cov = item.querySelector('[data-slot="coverage"]');
        const stat = item.querySelector('[data-slot="status"]');
        // A row for a declaration the payload does not carry: possible on an excerpt only if the
        // two were built from different data. Leave the server-rendered text rather than blank it.
        if (i === undefined) return;
        const c = coverage(i);
        const v = verdictOf(names[i]);
        if (cov) cov.textContent = `${c.accepted}/${c.total} beneath accepted`;
        if (stat) {
          stat.innerHTML = isCovered(i)
            ? '<span class="audit-ok">covered</span>'
            : v === 'accepted'
              ? `<span class="audit-warn">accepted, ${c.total - c.accepted} unread beneath</span>`
              : v === 'query' ? '<span class="audit-warn">query</span>'
              : '<span class="audit-hint">unread</span>';
        }
      });
    }

    // Wired once. The rows outlive every repaint, so re-binding on each one would stack listeners.
    document.querySelectorAll('.audit-start[data-claim]').forEach(b => {
      b.addEventListener('click', () => {
        const i = index[b.dataset.claim];
        if (i !== undefined) startQueue(i);
      });
    });

    // An excerpt — the landing page's ranked top results — is the listing and nothing else. The
    // rows are identical, which is the point: it is the same list, and a reader who has recorded
    // work on a claim should see it wherever the claim appears. What it drops is the apparatus,
    // which belongs to the page that carries every claim rather than to a page carrying ten.
    if (auditData.excerpt || !host) {
      document.addEventListener('referee:auditchange', paintRows);
      paintRows();
      return;
    }

    // This block mounts below the listing, so it is the state of a list the reader has already
    // scrolled past: the counts summarise what they will have done to it, and a summary above the
    // thing summarised reads as a dashboard rather than as a place to work.
    host.innerHTML = `
      <h2 class="site-heading">Your progress</h2>
      <div id="audit-summary" class="audit-summary"></div>
      <div class="audit-toolbar">
        <button type="button" id="audit-export">Export audit file</button>
        <button type="button" id="audit-import">Import…</button>
        <button type="button" id="audit-report">Generate report</button>
        <button type="button" id="audit-reset" class="audit-danger">Clear all</button>
        <input type="file" id="audit-file" accept="application/json,.json" hidden />
      </div>
      <div id="audit-import-note" class="audit-import-note"></div>
      <h2 class="site-heading">Open queries</h2>
      <div id="audit-queries"></div>
      <h2 class="site-heading">Accepted, but not covered</h2>
      <p>Accepted while something their statements rest on is not. This list is the reason a bare
         checkbox is not enough: every row is a declaration you would otherwise count as done.</p>
      <div id="audit-gaps"></div>
      <div id="audit-stale-section"></div>`;

    function paint() {
      const claims = [];
      const queries = [];
      const gaps = [];
      const stale = [];
      let accepted = 0;
      for (let i = 0; i < decls.length; i++) {
        const v = verdictOf(names[i]);
        if (staleAt(i)) stale.push(i);
        else if (v === 'accepted') accepted++;
        if (v === 'query') queries.push(i);
        if (decls[i].claim) claims.push(i);
        else if (accepts(i) && coverage(i).accepted !== decls[i].closure.length) gaps.push(i);
      }
      const coveredClaims = claims.filter(isCovered);
      const openClaims = claims.filter(i => accepts(i) && !isCovered(i));
      const sorried = decls.filter(d => d.sorryDep).length;
      const sorriedClaims = claims.filter(i => decls[i].sorryDep).length;
      // Sorted by what re-reading each one would cost: a stale acceptance under a hundred results
      // is a different size of problem from one under none.
      stale.sort((a, b) => decls[b].closure.length - decls[a].closure.length);

      document.getElementById('audit-summary').innerHTML = `
        <p class="audit-headline">${coveredClaims.length} of ${claims.length} claims fully
          covered</p>
        <p>${accepted} of ${decls.length} declarations accepted · ${queries.length}
          ${queries.length === 1 ? 'query' : 'queries'} open</p>
        ${stale.length
          ? `<p class="audit-warn">${stale.length}
              ${stale.length === 1 ? 'acceptance is' : 'acceptances are'} of a declaration that has
              changed meaning since you recorded it, and ${stale.length === 1 ? 'is' : 'are'} not
              counted above. <a href="#audit-stale-section">What they are</a>.</p>`
          : ''}
        ${openClaims.length
          ? `<p class="audit-warn">${openClaims.length}
              ${openClaims.length === 1 ? 'claim is' : 'claims are'} accepted while resting on
              something you have not read.</p>`
          : ''}
        ${sorried
          ? `<p class="audit-hint">Separately, ${sorried} declarations rest on a
             <code>sorry</code>${sorriedClaims
               ? `, ${sorriedClaims} of them claims, flagged in the list above`
               : ', none of them claims'}. Acceptance is about what a statement means; whether it is
             proved is what <a href="sorries/">Sorries and assumptions</a> reports.</p>`
          : ''}
        ${state.exportedAt
          ? `<p class="audit-hint">Last exported ${esc(state.exportedAt.slice(0, 16).replace('T', ' '))}.</p>`
          : '<p class="audit-hint">Not yet exported. This state lives in this browser only.</p>'}`;

      document.getElementById('audit-queries').innerHTML = queries.length
        ? `<ul class="audit-list">${queries.map(i => `<li class="audit-item">
            <a class="audit-name" href="${esc(decls[i].href)}"><code>${esc(names[i])}</code></a>
            <span class="audit-note-text">${esc(noteOf(names[i])) || '<em>no note</em>'}</span>
          </li>`).join('')}</ul>`
        : '<p>None.</p>';

      document.getElementById('audit-gaps').innerHTML = gaps.length
        ? `<ul class="audit-list">${gaps.map(i => {
            const c = coverage(i);
            return `<li class="audit-item">
              <a class="audit-name" href="${esc(decls[i].href)}"><code>${esc(names[i])}</code></a>
              <span class="audit-meta">${c.total - c.accepted} of ${c.total} unread beneath</span>
            </li>`;
          }).join('')}</ul>`
        : '<p>None.</p>';

      // Rendered only when there is something to say. On a build without semantic hashes nothing
      // can ever be stale, and a permanently empty section headed "Accepted, then changed" would
      // read as a guarantee the site is in no position to give.
      document.getElementById('audit-stale-section').innerHTML = stale.length
        ? `<h2 class="site-heading">Accepted, then changed (${stale.length})</h2>
           <p>You recorded a verdict on these, and they no longer mean what they meant then. Nothing
              here is guesswork: each verdict carries the declaration's meaning at the moment you
              set it, and this build compares against that — which is why it works with no baseline
              and no earlier build to hand. They count as unread everywhere on this site until you
              read them again.</p>
           <ul class="audit-list">${stale.map(i => `<li class="audit-item">
              <a class="audit-name" href="${esc(decls[i].href)}"><code>${esc(names[i])}</code></a>
              <span class="audit-meta">${decls[i].closure.length} beneath${entry(names[i]).at
                ? ` · accepted ${esc(entry(names[i]).at.slice(0, 10))}` : ''}</span>
              ${decls[i].change && decls[i].change !== 'unchanged'
                ? `<span class="audit-warn">${esc(CHANGE_WORDS[decls[i].change]
                    || decls[i].change)}</span>`
                : ''}
            </li>`).join('')}</ul>`
        : '';

      paintRows();
    }

    function startQueue(i) {
      // Dependency order, bottom first, with the claim itself last: the closure arrives
      // topologically sorted from `transDeps`, which is the order the extractor needs to emit a
      // compilable file, and it is exactly the order a reader needs too.
      const list = decls[i].closure.map(j => names[j]).concat([names[i]]);
      const hrefs = decls[i].closure.map(j => decls[j].href).concat([decls[i].href]);
      // Carried with the queue so a declaration page, which holds no table of its own, can tell
      // whether a queue entry is still to read without loading the whole library's payload.
      const meanings = decls[i].closure.map(j => meaningOf(j)).concat([meaningOf(i)]);
      state.queue = { claim: names[i], names: list, hrefs: hrefs, meanings: meanings };
      dirty = true;
      save();
      const firstUnread = list.findIndex((n, k) => !acceptsNow(n, meanings[k]));
      const at = firstUnread < 0 ? 0 : firstUnread;
      window.location.href = new URL(hrefs[at], document.baseURI);
    }

    document.getElementById('audit-export').addEventListener('click', () => {
      state.exportedAt = new Date().toISOString();
      state.dataId = auditData.dataId;
      save();
      dirty = false;
      download(`audit-${project}-${auditData.dataId.slice(0, 8)}.json`,
        JSON.stringify({
          version: FILE_VERSION,
          project: project,
          dataId: auditData.dataId,
          exportedAt: state.exportedAt,
          verdicts: state.verdicts,
        }, null, 2));
      paint();
    });

    document.getElementById('audit-import').addEventListener('click', () =>
      document.getElementById('audit-file').click());

    document.getElementById('audit-file').addEventListener('change', ev => {
      const file = ev.target.files && ev.target.files[0];
      if (!file) return;
      const reader = new FileReader();
      reader.onload = () => {
        let incoming;
        try { incoming = JSON.parse(reader.result); } catch (e) { incoming = null; }
        ev.target.value = '';
        if (!incoming || !incoming.verdicts) {
          note('<span class="audit-warn">That file is not an audit file.</span>');
          return;
        }
        applyImport(incoming);
      };
      reader.readAsText(file);
    });

    function note(html) { document.getElementById('audit-import-note').innerHTML = html; }

    function applyImport(incoming) {
      const messages = [];
      if (incoming.project && incoming.project !== project) {
        messages.push(`<span class="audit-warn">That file is for <code>${esc(incoming.project)}</code>,
          not <code>${esc(project)}</code>.</span> Nothing was imported.`);
        note(messages.join(' '));
        return;
      }

      const renamed = {};
      (auditData.renamed || []).forEach(p => { renamed[p[0]] = p[1]; });

      let taken = 0, carried = 0, staleIn = 0, uncheckable = 0;
      const missing = [];
      const voided = [];
      Object.keys(incoming.verdicts).forEach(name => {
        const rec = incoming.verdicts[name];
        if (!rec || VERDICTS.indexOf(rec.verdict) < 0) return;
        let target = name;
        if (index[target] === undefined) {
          if (renamed[target] !== undefined && index[renamed[target]] !== undefined) {
            target = renamed[target];
            carried++;
          } else { missing.push(name); return; }
        }
        const current = meaningOf(index[target]);
        if (rec.verdict === 'accepted' && current) {
          if (!rec.meaning) uncheckable++;
          else if (rec.meaning !== current) staleIn++;
        }
        // Where the record carries no meaning of its own there is nothing to compare, so the
        // baseline's verdict on the declaration is the only signal available and an acceptance it
        // invalidated is dropped rather than imported as if it still stood. Where the record does
        // carry one, it is imported and shown as stale instead: keeping it says *what* was
        // accepted and when, which dropping it throws away.
        const change = decls[index[target]].change;
        if (rec.verdict === 'accepted' && !rec.meaning && VOIDING.has(change)) {
          voided.push(target);
          return;
        }
        state.verdicts[target] = rec;
        taken++;
      });
      dirty = true;
      save();

      messages.push(`Imported ${taken} ${taken === 1 ? 'verdict' : 'verdicts'}.`);
      if (carried) {
        messages.push(`${carried} carried across a rename (matched by an identical meaning).`);
      }
      if (staleIn) {
        messages.push(`<span class="audit-warn">${staleIn} of them ${staleIn === 1
          ? 'is an acceptance' : 'are acceptances'} of a declaration that has changed meaning
          since.</span> Kept, and listed under “Accepted, then changed”, but not counted as
          accepted.`);
      }
      if (voided.length) {
        messages.push(`<span class="audit-warn">${voided.length} ${voided.length === 1
          ? 'acceptance was' : 'acceptances were'} dropped: those declarations changed meaning
          since ${esc(auditData.baselineLabel || 'the baseline')}.</span>
          <a href="changes/">What changed</a>.`);
      }
      if (uncheckable) {
        messages.push(`<span class="audit-hint">${uncheckable} ${uncheckable === 1
          ? 'acceptance records' : 'acceptances record'} no meaning — exported before this build
          tracked them — so whether ${uncheckable === 1 ? 'it is' : 'they are'} still current
          cannot be established here.</span>`);
      }
      if (missing.length) {
        messages.push(`<span class="audit-hint">${missing.length} named declarations no longer
          exist and were ignored.</span>`);
      }
      note(messages.join(' '));
      paint();
    }

    document.getElementById('audit-reset').addEventListener('click', () => {
      if (!window.confirm('Discard every verdict and note for this project?')) return;
      state = blank();
      save();
      note('Cleared.');
      paint();
    });

    document.getElementById('audit-report').addEventListener('click', () => {
      download(`audit-report-${project}.md`, buildReport(), 'text/markdown');
    });

    function buildReport() {
      const lines = [];
      const claims = [];
      const queries = [];
      const unspecified = [];
      const sorried = [];
      const stale = [];
      for (let i = 0; i < decls.length; i++) {
        if (decls[i].claim) claims.push(i);
        if (verdictOf(names[i]) === 'query') queries.push(i);
        if (decls[i].unspecified) unspecified.push(i);
        if (decls[i].sorryDep) sorried.push(i);
        if (staleAt(i)) stale.push(i);
      }
      lines.push(`# Audit report — ${project}`, '');
      lines.push(`Build \`${auditData.dataId}\`. Generated ${new Date().toISOString().slice(0, 10)}.`, '');
      lines.push('This records one reader\'s judgements. Nothing in it is checked or authenticated:');
      lines.push('an accepted declaration is one a human said says what its name claims.', '');

      lines.push(`## Claims (${claims.length})`, '');
      claims.forEach(i => {
        const c = coverage(i);
        const mark = isCovered(i) ? 'x' : ' ';
        const why = isCovered(i)
          ? `covered (${c.total} beneath, all accepted)`
          : staleAt(i)
            ? `accepted earlier, but its meaning has changed since (${c.accepted}/${c.total} beneath accepted)`
            : accepts(i)
              ? `accepted, but ${c.total - c.accepted} of ${c.total} beneath are unread`
              : `${verdictOf(names[i])} (${c.accepted}/${c.total} beneath accepted)`;
        lines.push(`- [${mark}] \`${names[i]}\` — ${why}`);
      });
      lines.push('');

      if (stale.length) {
        lines.push(`## Accepted, then changed (${stale.length})`, '');
        lines.push('Recorded as accepted against a meaning this build no longer has. Not counted');
        lines.push('as accepted anywhere above.', '');
        stale.forEach(i => {
          const at = entry(names[i]).at;
          lines.push(`- \`${names[i]}\` (${decls[i].module})${at ? ` — accepted ${at.slice(0, 10)}` : ''}`);
        });
        lines.push('');
      }

      lines.push(`## Queries (${queries.length})`, '');
      if (!queries.length) lines.push('None.', '');
      queries.forEach(i => {
        lines.push(`- \`${names[i]}\` (${decls[i].module})`);
        const n = noteOf(names[i]);
        if (n) n.split('\n').forEach(l => lines.push(`  ${l}`));
      });
      lines.push('');

      lines.push('## What the library rests on', '');
      lines.push(`- ${sorried.length} declarations have a \`sorry\` in their closure.`);
      lines.push(`- ${unspecified.length} definitions carry no \`@[specifies]\` theorem, so nothing`);
      lines.push('  in the project states what they mean.');
      if (auditData.baselineLabel) {
        lines.push(`- This build was compared against ${auditData.baselineLabel}; see its Changes page.`);
      }
      lines.push('');
      return lines.join('\n');
    }

    document.addEventListener('referee:auditchange', paint);
    paint();
  }
});
