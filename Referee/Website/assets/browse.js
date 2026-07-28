
/*
 * The Browse table: every declaration in the library, sortable and filterable.
 *
 * Sorting and filtering happen here rather than server-side because the site is static HTML. The
 * rows arrive as JSON and the table is built from them, which keeps the page markedly smaller
 * than emitting a few thousand <tr> elements would.
 *
 * Only a bounded number of rows is put into the DOM at once. A library can have tens of thousands
 * of declarations, and a table that large makes the page unusable; the cap is reported rather than
 * applied silently, so a reader can see that the view is truncated and narrow the filter.
 */
document.addEventListener('DOMContentLoaded', () => {
  const root = document.getElementById('browse-root');
  const dataNode = document.getElementById('browse-data');
  if (!root || !dataNode) return;

  const rows = JSON.parse(dataNode.textContent).rows || [];
  const RENDER_CAP = 600;

  const esc = s => String(s).replace(/[&<>"]/g,
    c => ({ '&': '&amp;', '<': '&lt;', '>': '&gt;', '"': '&quot;' }[c]));

  const uniq = key => [...new Set(rows.map(r => r[key]))].sort((a, b) => a.localeCompare(b));
  const options = (values, all) =>
    [`<option value="">${all}</option>`]
      .concat(values.map(v => `<option value="${esc(v)}">${esc(v)}</option>`)).join('');

  // The specification column exists only for a project that uses `@[specifies]`. `specs` is null
  // (or absent) for anything a specification cannot be about — theorems, axioms, instances — so a
  // project that never annotates produces no non-null counts and gets the table it had before.
  const hasSpecs = rows.some(r => r.specs != null && r.specs > 0);

  // The change column exists only for a site built with --baseline, which is the only case where
  // `change` is non-null. Without one there is no revision to speak of, and a column reading
  // "unchanged" on every row would be noise.
  const hasChanges = rows.some(r => r.change != null);

  // Which change kinds mean "your earlier reading of this no longer covers it". Proof-only changes
  // are deliberately not among them: the kernel rechecked the proof, and a proof cannot change what
  // a theorem says.
  const REAUDIT = new Set(['statement', 'body', 'indirect', 'added']);

  // Verdicts come from audit.js rather than from localStorage directly, so the table and the
  // declaration pages cannot disagree about what a verdict is. Absent if that script failed to
  // load, in which case the column simply does not appear.
  const audit = window.RefereeAudit || null;
  const verdictOf = r => (audit ? audit.verdictOf(r.name) : 'unread');

  const CHANGE_LABEL = {
    statement: 'statement changed',
    body: 'definition changed',
    indirect: 'meaning changed indirectly',
    added: 'new',
    proof: 'proof changed',
    unchanged: 'unchanged',
  };

  root.innerHTML = `
    <div class="browse-controls">
      <input id="browse-q" type="search" placeholder="Filter by name or module" />
      <select id="browse-kind">${options(uniq('kind'), 'Any kind')}</select>
      <select id="browse-chapter">${options(uniq('chapter'), 'Any chapter')}</select>
      <select id="browse-trust">
        <option value="">Any status</option>
        <option value="proved">Fully proved</option>
        <option value="sorry">Depends on sorry</option>
        <option value="axioms">Extra axioms</option>
      </select>
      ${hasSpecs ? `<select id="browse-spec">
        <option value="">Any definition</option>
        <option value="none">No specification</option>
        <option value="some">Has a specification</option>
      </select>` : ''}
      ${hasChanges ? `<select id="browse-change">
        <option value="">Any revision status</option>
        <option value="reaudit">Needs re-reading</option>
        <option value="statement">Statement changed</option>
        <option value="indirect">Invalidated indirectly</option>
        <option value="body">Definition changed</option>
        <option value="added">New</option>
        <option value="proof">Proof only</option>
        <option value="unchanged">Unchanged</option>
      </select>` : ''}
      ${audit ? `<select id="browse-verdict">
        <option value="">Any verdict</option>
        <option value="unread">Unread</option>
        <option value="accepted">Accepted</option>
        <option value="query">Query</option>
      </select>` : ''}
      <button id="browse-reset" type="button">Reset</button>
    </div>
    <p class="browse-count" id="browse-count"></p>
    <div class="browse-scroll">
      <table class="browse-table">
        <thead>
          <tr>
            <th data-sort="name" class="browse-sortable">Declaration</th>
            <th data-sort="kind" class="browse-sortable">Kind</th>
            <th data-sort="module" class="browse-sortable">Module</th>
            <th data-sort="deps" class="browse-sortable browse-num">Deps</th>
            <th data-sort="ext" class="browse-sortable browse-num">External</th>
            ${hasSpecs ? '<th data-sort="specs" class="browse-sortable browse-num">Spec</th>' : ''}
            ${hasChanges ? '<th data-sort="change" class="browse-sortable">Changed</th>' : ''}
            ${audit ? '<th data-sort="verdict" class="browse-sortable">Verdict</th>' : ''}
            <th data-sort="trust" class="browse-sortable">Status</th>
          </tr>
        </thead>
        <tbody id="browse-body"></tbody>
      </table>
    </div>
  `;

  const q = document.getElementById('browse-q');
  const kind = document.getElementById('browse-kind');
  const chapter = document.getElementById('browse-chapter');
  const trust = document.getElementById('browse-trust');
  const spec = document.getElementById('browse-spec');
  const change = document.getElementById('browse-change');
  const verdict = document.getElementById('browse-verdict');
  const body = document.getElementById('browse-body');
  const count = document.getElementById('browse-count');

  let sortKey = 'name';
  let sortAsc = true;

  const trustOf = r => (r.dependsOnSorry ? 'sorry' : r.extraAxioms ? 'axioms' : 'proved');

  // Sorts and filters treat "not the sort of thing that has a specification" as its own value
  // rather than as zero, so that ascending order does not bury the unspecified definitions —
  // the reason to sort this column at all — under every theorem in the library.
  const specOf = r => (r.specs == null ? null : r.specs > 0 ? 'some' : 'none');

  const specCell = r => {
    if (r.specs == null) return '<span class="browse-spec-na">—</span>';
    if (r.specs > 0) return String(r.specs);
    return '<span class="browse-flag browse-flag-gap">none</span>';
  };

  // Sorted by urgency rather than alphabetically: the point of sorting this column is to bring what
  // needs re-reading to the top, and "added" before "indirect" before "statement" is not an order
  // anyone wants.
  const CHANGE_RANK = { statement: 0, indirect: 1, body: 2, added: 3, proof: 4, unchanged: 5 };

  const changeCell = r => {
    if (r.change == null || r.change === 'unchanged') {
      return '<span class="browse-change-na">—</span>';
    }
    const cls = REAUDIT.has(r.change) ? 'browse-flag-warn' : 'browse-flag-ok';
    return `<span class="browse-flag ${cls}">${esc(CHANGE_LABEL[r.change] || r.change)}</span>`;
  };

  // Unread sorts first: the point of sorting this column is to bring what is left to the top.
  const VERDICT_RANK = { unread: 0, query: 1, accepted: 2 };

  const verdictCell = r => {
    const v = verdictOf(r);
    if (v === 'unread') return '<span class="browse-change-na">unread</span>';
    const cls = v === 'accepted' ? 'browse-flag-ok' : 'browse-flag-warn';
    return `<span class="browse-flag ${cls}">${v}</span>`;
  };

  const statusCell = r => {
    if (r.dependsOnSorry) return '<span class="browse-flag browse-flag-warn">depends on sorry</span>';
    if (r.extraAxioms) return '<span class="browse-flag browse-flag-warn">extra axioms</span>';
    return '<span class="browse-flag browse-flag-ok">proved</span>';
  };

  function matching() {
    const needle = q.value.trim().toLowerCase();
    return rows.filter(r => {
      if (kind.value && r.kind !== kind.value) return false;
      if (chapter.value && r.chapter !== chapter.value) return false;
      if (trust.value && trustOf(r) !== trust.value) return false;
      if (spec && spec.value && specOf(r) !== spec.value) return false;
      if (change && change.value) {
        if (change.value === 'reaudit') {
          if (!REAUDIT.has(r.change)) return false;
        } else if (r.change !== change.value) return false;
      }
      if (verdict && verdict.value && verdictOf(r) !== verdict.value) return false;
      if (needle && !(`${r.name} ${r.module}`.toLowerCase().includes(needle))) return false;
      return true;
    });
  }

  function sorted(list) {
    const dir = sortAsc ? 1 : -1;
    const value = r => {
      if (sortKey === 'trust') return trustOf(r);
      if (sortKey === 'change') return CHANGE_RANK[r.change] ?? 9;
      if (sortKey === 'verdict') return VERDICT_RANK[verdictOf(r)] ?? 9;
      return r[sortKey];
    };
    return list.slice().sort((a, b) => {
      // Rows that cannot have a specification sink to the bottom in *both* directions: they are
      // not a value on this scale, and letting them sort along with the rest would bury the
      // definitions the column exists to surface under every theorem in the library.
      if (sortKey === 'specs') {
        const aNone = a.specs == null, bNone = b.specs == null;
        if (aNone !== bNone) return aNone ? 1 : -1;
      }
      const x = value(a), y = value(b);
      const cmp = typeof x === 'number' && typeof y === 'number'
        ? x - y
        : String(x).localeCompare(String(y));
      // Name is the tie-breaker, so the order is total and the table never reshuffles arbitrarily.
      return (cmp || a.name.localeCompare(b.name)) * dir;
    });
  }

  function render() {
    const found = sorted(matching());
    const shown = found.slice(0, RENDER_CAP);
    body.innerHTML = shown.map(r => `
      <tr data-decl-group="${esc(r.group)}">
        <td><a href="${esc(r.href)}"><code>${esc(r.name)}</code></a></td>
        <td class="browse-kind">${esc(r.kind)}</td>
        <td class="browse-module"><code>${esc(r.module)}</code></td>
        <td class="browse-num">${r.deps}</td>
        <td class="browse-num">${r.ext}</td>
        ${hasSpecs ? `<td class="browse-num">${specCell(r)}</td>` : ''}
        ${hasChanges ? `<td>${changeCell(r)}</td>` : ''}
        ${audit ? `<td>${verdictCell(r)}</td>` : ''}
        <td>${statusCell(r)}</td>
      </tr>`).join('');
    count.textContent = found.length === rows.length
      ? `${rows.length} declarations`
      : `${found.length} of ${rows.length} declarations`;
    if (found.length > shown.length) {
      count.textContent += ` — showing the first ${shown.length}, narrow the filter to see the rest`;
    }
    for (const th of root.querySelectorAll('th[data-sort]')) {
      const active = th.dataset.sort === sortKey;
      th.setAttribute('aria-sort', active ? (sortAsc ? 'ascending' : 'descending') : 'none');
      th.classList.toggle('browse-sorted', active);
      th.dataset.dir = active ? (sortAsc ? 'asc' : 'desc') : '';
    }
  }

  for (const th of root.querySelectorAll('th[data-sort]')) {
    th.addEventListener('click', () => {
      const key = th.dataset.sort;
      if (key === sortKey) sortAsc = !sortAsc;
      // Counts are most useful largest-first; names read best A-Z.
      // Counts read best largest-first; names and the change ranking read best in their own order.
      else { sortKey = key; sortAsc = !(key === 'deps' || key === 'ext'); }
      render();
    });
  }

  for (const control of [q, kind, chapter, trust, spec, change, verdict].filter(Boolean)) {
    control.addEventListener('input', render);
    control.addEventListener('change', render);
  }

  document.getElementById('browse-reset').addEventListener('click', () => {
    q.value = ''; kind.value = ''; chapter.value = ''; trust.value = '';
    if (spec) spec.value = '';
    if (change) change.value = '';
    if (verdict) verdict.value = '';
    sortKey = 'name'; sortAsc = true;
    render();
  });

  // A verdict set on a declaration page (or an import on the audit page) has to show up here too.
  document.addEventListener('referee:auditchange', render);

  render();
});
