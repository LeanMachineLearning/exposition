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

  function setVerdict(name, verdict, note) {
    const prev = entry(name);
    const nextNote = note === undefined ? (prev.note || '') : note;
    if (verdict === 'unread' && !nextNote) delete state.verdicts[name];
    else state.verdicts[name] = { verdict: verdict, note: nextNote, at: new Date().toISOString() };
    dirty = true;
    save();
    document.dispatchEvent(new CustomEvent('referee:auditchange', { detail: { name: name } }));
  }

  // browse.js reads this to fill its Verdict column. Exposed rather than duplicated so that the two
  // views can never disagree about what a verdict is.
  window.RefereeAudit = { verdictOf: verdictOf, noteOf: noteOf, setVerdict: setVerdict };

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

    host.innerHTML = `
      <div class="audit-control">
        <div class="audit-row">
          <div class="audit-verdicts" role="group" aria-label="Your verdict">
            ${VERDICTS.map(v => `<button type="button" class="audit-verdict" data-v="${v}">
              ${v}</button>`).join('')}
          </div>
          <span class="audit-hint">a · q · u</span>
        </div>
        <textarea class="audit-note" rows="2"
          placeholder="Note — what you would ask the author"></textarea>
        <p class="audit-coverage" id="audit-coverage"></p>
        <div class="audit-actions">
          ${closure.length
            ? `<button type="button" id="audit-accept-closure">Accept this and everything its
                 statement rests on (${closure.length})</button>`
            : ''}
          <a class="audit-link" href="audit/">Audit progress →</a>
        </div>
        <p class="audit-queue" id="audit-queue"></p>
      </div>`;

    const noteBox = host.querySelector('.audit-note');
    noteBox.value = noteOf(name);
    noteBox.addEventListener('change', () => setVerdict(name, verdictOf(name), noteBox.value));

    host.querySelectorAll('.audit-verdict').forEach(b => {
      b.addEventListener('click', () => setVerdict(name, b.dataset.v, noteBox.value));
    });

    const acceptAll = host.querySelector('#audit-accept-closure');
    if (acceptAll) {
      // The minimal file for this declaration *is* its closure, inlined. A reader who has read one
      // has legitimately covered everything in it, so the bulk action matches the artifact rather
      // than being a shortcut around it.
      acceptAll.addEventListener('click', () => {
        closure.forEach(d => { if (verdictOf(d.label) !== 'query') setVerdict(d.label, 'accepted'); });
        setVerdict(name, 'accepted', noteBox.value);
      });
    }

    function paint() {
      const v = verdictOf(name);
      host.querySelectorAll('.audit-verdict').forEach(b =>
        b.classList.toggle('audit-verdict--on', b.dataset.v === v));

      const unread = closure.filter(d => verdictOf(d.label) !== 'accepted');
      const cov = document.getElementById('audit-coverage');
      if (!closure.length) {
        cov.innerHTML = v === 'accepted'
          ? '<span class="audit-ok">Covered.</span> Its statement rests on nothing else in this project.'
          : 'Its statement rests on nothing else in this project.';
      } else if (unread.length === 0) {
        cov.innerHTML = v === 'accepted'
          ? `<span class="audit-ok">Covered.</span> You have accepted all ${closure.length}
             declarations its statement rests on.`
          : `All ${closure.length} declarations its statement rests on are accepted; this one is not.`;
      } else {
        const shown = unread.slice(0, 6).map(d =>
          `<a href="${esc(d.href || '')}"><code>${esc(d.label)}</code></a>`).join(', ');
        const more = unread.length > 6 ? `, and ${unread.length - 6} more` : '';
        cov.innerHTML = (v === 'accepted'
          ? '<span class="audit-warn">Accepted, but not covered.</span> '
          : '')
          + `${unread.length} of the ${closure.length} declarations its statement rests on are not
             accepted: ${shown}${more}.`;
      }
      paintQueue();
    }

    function paintQueue() {
      const box = document.getElementById('audit-queue');
      const q = state.queue;
      if (!q || !q.names || q.names.indexOf(name) < 0) { box.innerHTML = ''; return; }
      const pos = q.names.indexOf(name);
      const left = q.names.filter(n => verdictOf(n) === 'unread');
      // The next thing to read, not merely the next in the list: a reader who accepted three in a
      // row should not be walked back through them.
      let nextAt = -1;
      for (let i = pos + 1; i < q.names.length; i++) {
        if (verdictOf(q.names[i]) === 'unread') { nextAt = i; break; }
      }
      if (nextAt < 0) for (let i = 0; i < pos; i++) {
        if (verdictOf(q.names[i]) === 'unread') { nextAt = i; break; }
      }
      const next = nextAt >= 0
        ? `<a id="audit-next" href="${esc(q.hrefs[nextAt])}">next unread →</a> <span
             class="audit-hint">n</span>`
        : '<span class="audit-ok">queue complete</span>';
      box.innerHTML = `Reading for <code>${esc(q.claim)}</code> — ${pos + 1} of ${q.names.length},
        ${left.length} unread. ${next}`;
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

  if (auditData) {
    const host = document.getElementById('audit-root');
    if (host) renderAudit(host);
  }

  function renderAudit(host) {
    const names = auditData.names;
    const decls = auditData.decls;
    const index = {};
    names.forEach((n, i) => index[n] = i);

    const coverage = i => {
      const c = decls[i].closure;
      let accepted = 0;
      for (let k = 0; k < c.length; k++) if (verdictOf(names[c[k]]) === 'accepted') accepted++;
      return { total: c.length, accepted: accepted };
    };
    const isCovered = i =>
      verdictOf(names[i]) === 'accepted' && coverage(i).accepted === decls[i].closure.length;

    host.innerHTML = `
      <div id="audit-summary" class="audit-summary"></div>
      <div class="audit-toolbar">
        <button type="button" id="audit-export">Export audit file</button>
        <button type="button" id="audit-import">Import…</button>
        <button type="button" id="audit-report">Generate report</button>
        <button type="button" id="audit-reset" class="audit-danger">Clear all</button>
        <input type="file" id="audit-file" accept="application/json,.json" hidden />
      </div>
      <div id="audit-import-note" class="audit-import-note"></div>
      <h2 class="site-heading">Claims</h2>
      <p>Each claim with the declarations its statement rests on. “Start reading” walks that closure
         in dependency order, so nothing is read before the definitions it is stated in terms of.</p>
      <div id="audit-claims"></div>
      <h2 class="site-heading">Open queries</h2>
      <div id="audit-queries"></div>
      <h2 class="site-heading">Accepted, but not covered</h2>
      <p>Accepted while something their statements rest on is not. This list is the reason a bare
         checkbox is not enough: every row is a declaration you would otherwise count as done.</p>
      <div id="audit-gaps"></div>`;

    function paint() {
      const claims = [];
      const queries = [];
      const gaps = [];
      let accepted = 0;
      for (let i = 0; i < decls.length; i++) {
        const v = verdictOf(names[i]);
        if (v === 'accepted') accepted++;
        if (v === 'query') queries.push(i);
        if (decls[i].claim) claims.push(i);
        else if (v === 'accepted' && coverage(i).accepted !== decls[i].closure.length) gaps.push(i);
      }
      const coveredClaims = claims.filter(isCovered);
      const openClaims = claims.filter(i => verdictOf(names[i]) === 'accepted' && !isCovered(i));
      const sorried = decls.filter(d => d.sorryDep).length;

      document.getElementById('audit-summary').innerHTML = `
        <p class="audit-headline">${coveredClaims.length} of ${claims.length} claims fully
          covered</p>
        <p>${accepted} of ${decls.length} declarations accepted · ${queries.length}
          ${queries.length === 1 ? 'query' : 'queries'} open</p>
        ${openClaims.length
          ? `<p class="audit-warn">${openClaims.length}
              ${openClaims.length === 1 ? 'claim is' : 'claims are'} accepted while resting on
              something you have not read.</p>`
          : ''}
        ${sorried
          ? `<p class="audit-hint">Separately, ${sorried} declarations rest on a
             <code>sorry</code>. Acceptance is about what a statement means; whether it is proved is
             what <a href="trust/">Trust</a> reports.</p>`
          : ''}
        ${state.exportedAt
          ? `<p class="audit-hint">Last exported ${esc(state.exportedAt.slice(0, 16).replace('T', ' '))}.</p>`
          : '<p class="audit-hint">Not yet exported. This state lives in this browser only.</p>'}`;

      document.getElementById('audit-claims').innerHTML = claims.length
        ? `<ul class="audit-list">${claims.map(i => {
            const c = coverage(i);
            const v = verdictOf(names[i]);
            const status = isCovered(i)
              ? '<span class="audit-ok">covered</span>'
              : v === 'accepted'
                ? `<span class="audit-warn">accepted, ${c.total - c.accepted} unread beneath</span>`
                : v === 'query' ? '<span class="audit-warn">query</span>'
                : '<span class="audit-hint">unread</span>';
            return `<li class="audit-item">
              <a class="audit-name" href="${esc(decls[i].href)}"><code>${esc(names[i])}</code></a>
              <span class="audit-meta">${c.accepted}/${c.total} beneath accepted</span>
              ${status}
              <button type="button" class="audit-start" data-i="${i}">Start reading</button>
            </li>`;
          }).join('')}</ul>`
        : '<p>This library states nothing with the <code>theorem</code> keyword, so there is no ' +
          'claim to start from. Browse is the way in.</p>';

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

      host.querySelectorAll('.audit-start').forEach(b => {
        b.addEventListener('click', () => startQueue(Number(b.dataset.i)));
      });
    }

    function startQueue(i) {
      // Dependency order, bottom first, with the claim itself last: the closure arrives
      // topologically sorted from `transDeps`, which is the order the extractor needs to emit a
      // compilable file, and it is exactly the order a reader needs too.
      const list = decls[i].closure.map(j => names[j]).concat([names[i]]);
      const hrefs = decls[i].closure.map(j => decls[j].href).concat([decls[i].href]);
      state.queue = { claim: names[i], names: list, hrefs: hrefs };
      dirty = true;
      save();
      const firstUnread = list.findIndex(n => verdictOf(n) === 'unread');
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

      let taken = 0, carried = 0;
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
        // A build with a baseline knows which declarations a revision has invalidated. An
        // acceptance of one of those is not carried across silently: it is exactly the reading the
        // revision made void, and importing it back would hide that.
        const change = decls[index[target]].change;
        if (rec.verdict === 'accepted' &&
            (change === 'statement' || change === 'body' || change === 'indirect')) {
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
        messages.push(`${carried} carried across a rename (matched by identical statement).`);
      }
      if (voided.length) {
        messages.push(`<span class="audit-warn">${voided.length} ${voided.length === 1
          ? 'acceptance was' : 'acceptances were'} dropped: those declarations changed meaning
          since ${esc(auditData.baselineLabel || 'the baseline')}.</span>
          <a href="changes/">What changed</a>.`);
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
      for (let i = 0; i < decls.length; i++) {
        if (decls[i].claim) claims.push(i);
        if (verdictOf(names[i]) === 'query') queries.push(i);
        if (decls[i].unspecified) unspecified.push(i);
        if (decls[i].sorryDep) sorried.push(i);
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
          : verdictOf(names[i]) === 'accepted'
            ? `accepted, but ${c.total - c.accepted} of ${c.total} beneath are unread`
            : `${verdictOf(names[i])} (${c.accepted}/${c.total} beneath accepted)`;
        lines.push(`- [${mark}] \`${names[i]}\` — ${why}`);
      });
      lines.push('');

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
