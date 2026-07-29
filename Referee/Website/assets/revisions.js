/*
 * The revision selector on the Changes page.
 *
 * `--baseline` compares this build against one other file, chosen when the site was built. This
 * asks the reader instead: which revision did you last work through? Everything whose meaning has
 * moved since then is what they have to read again.
 *
 * It runs entirely in the browser because the provenance ledger is small enough to ship. Each
 * declaration carries a single integer — the index of the revision at which its meaning last
 * changed — so the whole query is a comparison over that array.
 *
 * What it deliberately cannot do is show the old statement beside the new one. The ledger stores
 * hashes, not the text of every declaration at every revision, and keeping that would grow without
 * bound. The queue and its breakdown are what a reader needs to plan; the side-by-side needs
 * `--baseline` and a real earlier build, and the page says so rather than letting the absence be
 * discovered.
 */
document.addEventListener('DOMContentLoaded', () => {
  const root = document.getElementById('revisions-root');
  const dataNode = document.getElementById('revisions-data');
  if (!root || !dataNode) return;

  let data;
  try { data = JSON.parse(dataNode.textContent); } catch (e) { return; }
  const revisions = data.revisions || [];
  const decls = data.decls || [];
  if (revisions.length < 2) {
    // One revision is a ledger that has recorded nothing yet: there is no "since" to pick, and a
    // selector with a single entry would imply otherwise.
    root.innerHTML = `<p class="rev-caveat">The provenance ledger holds
      ${revisions.length === 1 ? 'one revision' : 'no revisions'} so far, so there is nothing to
      compare against yet. Each run of <code>referee provenance</code> adds one.</p>`;
    return;
  }

  const esc = s => String(s).replace(/[&<>"]/g,
    c => ({ '&': '&amp;', '<': '&lt;', '>': '&gt;', '"': '&quot;' }[c]));

  const KIND_LABEL = {
    statement: 'statement changed',
    body: 'definition changed',
    indirect: 'meaning changed indirectly',
    upstream: 'meaning changed underneath',
  };

  // Newest first in the dropdown: the revision a reader last read is far more often a recent one,
  // and the oldest is the least useful default.
  const choices = revisions.slice(0, revisions.length - 1).map((r, i) => ({ i, r })).reverse();

  root.innerHTML = `
    <div class="rev-picker">
      <label for="rev-since">Show what has changed since</label>
      <select id="rev-since">
        ${choices.map(({ i, r }) =>
          `<option value="${i}">${esc(r.ref)}${r.date ? ` — ${esc(r.date)}` : ''}</option>`).join('')}
      </select>
    </div>
    <div class="rev-result" id="rev-result"></div>`;

  const select = document.getElementById('rev-since');
  const result = document.getElementById('rev-result');

  function render() {
    const since = Number(select.value);
    const chosen = revisions[since];
    // Strictly after: a declaration that changed *at* the chosen revision changed as part of it,
    // and a reader who worked through that revision read the result.
    const moved = decls.filter(d => d.everChanged && d.changedAt > since);
    moved.sort((a, b) => (b.dependents - a.dependents) || a.name.localeCompare(b.name));

    const counts = {};
    moved.forEach(d => { counts[d.kind] = (counts[d.kind] || 0) + 1; });
    const breakdown = Object.keys(counts).sort((a, b) => counts[b] - counts[a])
      .map(k => `${counts[k]} ${esc(KIND_LABEL[k] || k)}`).join(' · ');

    const spanned = revisions.length - 1 - since;
    if (!moved.length) {
      result.innerHTML = `<p><strong>Nothing has changed meaning since
        ${esc(chosen.ref)}.</strong> ${spanned} later
        ${spanned === 1 ? 'revision was' : 'revisions were'} recorded, and no declaration means
        anything different from what it meant then.</p>`;
      return;
    }

    result.innerHTML = `
      <p><strong>${moved.length} ${moved.length === 1 ? 'declaration means' : 'declarations mean'}
         something different from ${esc(chosen.ref)}</strong>${breakdown ? ` — ${breakdown}` : ''}.
         Ordered by how much rests on each, so the expensive re-reading comes first.</p>
      <p class="rev-caveat">This is the queue, not a diff: the ledger records that the meaning moved
         and at which revision, not what the statement used to say. For the statements side by side,
         build with <code>--baseline</code> against that revision's <code>data.json</code>.</p>
      <ul class="audit-list">
        ${moved.slice(0, 400).map(d => `<li class="audit-item">
          <a class="audit-name" href="${esc(d.href)}"><code>${esc(d.name)}</code></a>
          <span class="audit-meta">${d.dependents} rest on it · ${esc(d.module)}</span>
          <span class="audit-meta">${esc(revisions[d.changedAt] ? revisions[d.changedAt].ref : '')}
            ${esc(KIND_LABEL[d.kind] || d.kind || '')}</span>
        </li>`).join('')}
      </ul>
      ${moved.length > 400
        ? `<p class="rev-caveat">Showing the first 400 of ${moved.length}.</p>`
        : ''}`;
  }

  select.addEventListener('change', render);
  render();
});
