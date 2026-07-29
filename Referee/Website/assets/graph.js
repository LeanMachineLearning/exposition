
/*
 * Layered dependency graph.
 *
 * Declarations are placed in rows by longest-path depth: a declaration with no dependencies sits
 * in the top row, and every other declaration sits one row below its bottom-most dependency. The
 * layout is computed once and is fully deterministic — there is no physics simulation, so nothing
 * drifts, settles, or moves under the cursor.
 *
 * Edges that span more than one row are routed through invisible waypoints in the intervening
 * rows (the standard Sugiyama trick), which is what keeps long edges from cutting across unrelated
 * nodes. Within a row, order is chosen by repeated median sweeps to reduce crossings.
 */
document.addEventListener('DOMContentLoaded', () => {
  const root = document.getElementById('graph-root');
  const dataNode = document.getElementById('graph-data');
  if (!root || !dataNode || !window.d3) return;

  const graph = JSON.parse(dataNode.textContent);
  const allNodes = graph.nodes.map(n => ({ ...n }));
  const allEdges = graph.edges.map(e => ({ ...e }));
  const groups = [...new Set(allNodes.map(n => n.groupKey))].sort();
  // What a node stands for. The same component draws declaration graphs and module graphs, and
  // the explanatory text has to say which it is looking at.
  const UNIT = graph.unit || 'declaration';
  const UNITS = UNIT + 's';
  const hasFocus = allNodes.some(n => n.focus);

  /* The reader's own verdicts, read through `audit.js` rather than out of localStorage, so the
     graph, the Browse table and the declaration pages cannot disagree about what a verdict is.
     Absent on a package graph, where a node is a package and there is nothing to accept.

     A *stale* acceptance is deliberately not marked. It is an acceptance of a declaration as it
     meant something else, and putting a tick on it here would be the one misleading thing this
     picture could say — the same reason the audit page excludes those from its counts. */
  const audit = (UNIT === 'package') ? null : (window.RefereeAudit || null);
  const verdictMark = n => {
    if (!audit || n.status === 'untrusted') return null;
    const v = audit.verdictOf(n.id);
    if (v === 'query') return { glyph: '?', fill: theme.sorry, title: 'you left a query on this' };
    if (v !== 'accepted') return null;
    if (audit.isStale && audit.isStale(n.id, n.meaning || '')) return null;
    return { glyph: '✓', fill: theme.ok, title: 'you accepted this' };
  };
  // Package graphs carry trust verdicts rather than chapters and `sorry` flags, so the
  // legend has to describe a different picture.
  const hasUntrusted = allNodes.some(n => n.status === 'untrusted');

  // ---------------------------------------------------------------- constants

  const NODE_H = 26;          // node box height
  const ROW_GAP = 60;         // vertical distance between row baselines
  const NODE_GAP = 18;        // minimum horizontal gap between boxes in a row
  const MARGIN = { top: 28, right: 32, bottom: 28, left: 76 };
  const VIEW_H = 720;
  const SWEEPS = 6;           // ordering passes; more is tidier but slower
  const STRAIGHTEN = 12;      // x-refinement passes; long edges need several to pull straight

  /* Colours come from the stylesheet so the graph follows the light/dark theme. Reading them at
     render time (rather than once) is what lets the picture re-colour when the reader flips the
     theme, without a reload. */
  const css = (name, fallback) =>
    getComputedStyle(document.documentElement).getPropertyValue(name).trim() || fallback;
  const isDark = () => css('--site-dark', '0') === '1';

  const PALETTE_LIGHT = ['#3f6fa8', '#4a7c6f', '#7a6096', '#8a6b3d', '#a4658a', '#5f7a3f', '#3f7f8a', '#8a5a4a'];
  const PALETTE_DARK = ['#7fa9d8', '#74b3a2', '#ab93c6', '#c2a06a', '#d094b4', '#9dbd76', '#79b8c4', '#c99a8a'];
  let colorOf = d3.scaleOrdinal(groups, groups.map((_, i) => PALETTE_LIGHT[i % PALETTE_LIGHT.length]));

  const theme = {};
  const readTheme = () => {
    const pal = isDark() ? PALETTE_DARK : PALETTE_LIGHT;
    colorOf = d3.scaleOrdinal(groups, groups.map((_, i) => pal[i % pal.length]));
    theme.edge = css('--site-ink-3', '#7c838e');
    theme.edgeHot = css('--site-accent', '#8a3a3a');
    theme.back = isDark() ? '#a493c9' : '#7c6aa8';
    theme.focusFill = css('--site-accent', '#2f5d8c');
    theme.focusInk = css('--site-surface', '#ffffff');
    theme.ink = css('--site-ink', '#14161a');
    theme.sorry = css('--site-warn', '#8a5a10');
    theme.ok = css('--site-ok', '#2c7a51');
    /* Package graphs mark an unaudited dependency. Deliberately not `theme.sorry`: on this
       site amber-dashed means "depends on sorry", and an unaudited package is a different
       claim — the code may be perfectly correct, nobody has vouched for it. */
    theme.untrusted = css('--site-ink-3', '#7c838e');
    theme.band = isDark() ? 'rgba(255,255,255,.035)' : 'rgba(20,22,26,.028)';
  };
  readTheme();

  // ---------------------------------------------------------------- chrome

  const groupOptions = groups.map(g => `<option value="${g}">${g}</option>`).join('');

  /* The key, as term-and-meaning pairs behind a disclosure rather than two paragraphs of prose.
     It had grown to describe rows, arrows, transitive reduction, chapter colour, two kinds of
     dashed outline, cycles and two verdict marks — accurate, and a wall of text above every graph
     on the site, most of it about things a given picture does not contain.

     So each entry is conditional on the picture actually containing what it describes: a project
     with one chapter is not told that colour marks the chapter, and a graph with nothing unaudited
     in it says nothing about grey dashes. What is left is short enough to read. */
  const KEY_ITEMS = [
    { term: 'Rows',
      text: `Dependency depth. The top row depends on nothing, and each ${UNIT} sits one row below
             its bottom-most dependency.` },
    { term: 'Arrows',
      text: 'Point from a dependency down to what uses it.' },
    { term: 'Missing edges',
      text: `An edge implied by a longer path is not drawn, so what you see is the essential
             structure rather than every direct edge. Every ${UNIT} it connects is still reachable
             along the path that remains.` },
    groups.length > 1 && UNIT !== 'package'
      ? { term: 'Colour', text: 'The chapter.' } : null,
    hasFocus
      ? { term: 'Filled node', text: `The ${UNIT} this page is about.` } : null,
    UNIT === 'package'
      ? { term: 'Grey dashed outline', text: 'A package nobody has vouched for.' }
      : { term: 'Amber dashed outline',
          text: 'Depends on <code>sorry</code>: something in its closure is unproved.' },
    (UNIT !== 'package' && hasUntrusted)
      ? { term: 'Grey dashed outline',
          text: `A declaration from an unaudited upstream package. It has no page here, and
                 trusting this result means trusting it.` } : null,
    { term: 'Violet dashed edge, curving up',
      text: `A dependency <em>cycle</em>: those ${UNITS} refer to each other, so no ordering of rows
             can place both below everything they depend on.` },
    audit ? { term: 'Green ✓',
              text: 'Your verdict: you accepted this declaration.' } : null,
    audit ? { term: 'Amber ?',
              text: 'Your verdict: you left a query on it.' } : null,
    audit ? { term: 'Neither',
              text: `Unread — or accepted when it meant something else, which does not count as
                     having read what is here now.` } : null,
  ].filter(Boolean);

  /* A graph of one node with no edges is drawn anyway — a declaration page keeps the same shape
     whether or not anything is under it, so "this rests on nothing" is legible at a glance instead
     of being indistinguishable from a graph further down the page. What is dropped is the chrome
     that would then describe things the reader cannot see: rows, arrows, cycles, colour-by-chapter,
     and a filter over a single node. */
  const isLone = allNodes.length <= 1 && allEdges.length === 0;

  root.innerHTML = `
    ${isLone ? '' : `<div class="graph-toolbar">
      <input id="graph-filter" type="search" placeholder="Filter ${UNITS} by name" />
      ${groups.length > 1 ? `<select id="graph-group">
        <option value="">All chapters</option>
        ${groupOptions}
      </select>` : ''}
      <button id="graph-fit" type="button">Fit view</button>
      <button id="graph-clear" type="button">Clear focus</button>
    </div>`}
    ${isLone
      ? `<p class="graph-hint">One node, no edges: this ${UNIT} rests on nothing else drawn
         here.</p>`
      : `<p class="graph-hint">Scroll to zoom, drag to pan, click a node to focus it, double-click
         to open its page.</p>
    <details class="graph-key" id="graph-key">
      <summary>What the layout and marks mean</summary>
      <dl class="graph-key-list">${KEY_ITEMS.map(
        it => `<dt>${it.term}</dt><dd>${it.text}</dd>`).join('')}</dl>
    </details>`}
    <div class="graph-layout${isLone ? ' graph-layout--lone' : ''}">
      <svg id="graph-svg" width="100%" height="${VIEW_H}"></svg>
      ${isLone ? '' : '<aside id="graph-panel" class="graph-panel"></aside>'}
    </div>
  `;

  // The drawing area grows and shrinks with the graph. A twelve-node graph stranded in a fixed
  // 720px box is mostly empty space; a large one still gets the full height and zoom/pan.
  let viewH = VIEW_H;
  const svg = d3.select('#graph-svg');
  const panel = document.getElementById('graph-panel');
  const filterInput = document.getElementById('graph-filter');
  const groupSelect = document.getElementById('graph-group');

  /* Collapsed by default, and remembered: a reader who wants the key open on one declaration page
     wants it open on the next, and one who has learnt it should not have to close it again on
     every page. Same storage discipline as the table of contents' open state. */
  const keyBox = document.getElementById('graph-key');
  if (keyBox) {
    try {
      if (localStorage.getItem('referee:graph-key') === 'open') keyBox.open = true;
    } catch (e) { /* private mode */ }
    keyBox.addEventListener('toggle', () => {
      try {
        localStorage.setItem('referee:graph-key', keyBox.open ? 'open' : 'closed');
      } catch (e) { /* quota, private mode */ }
    });
  }
  const width = Math.max(720, root.clientWidth - 32);
  svg.attr('viewBox', [0, 0, width, VIEW_H]);

  const defs = svg.append('defs');
  const addArrow = (id, fill) => defs.append('marker')
    .attr('id', id).attr('viewBox', '0 0 10 10')
    .attr('refX', 9).attr('refY', 5)
    .attr('markerWidth', 6).attr('markerHeight', 6)
    .attr('orient', 'auto')
    .append('path').attr('d', 'M0,0 L10,5 L0,10 Z').attr('fill', fill);
  addArrow('graph-arrow', theme.edge);
  addArrow('graph-arrow-hot', theme.edgeHot);

  const canvas = svg.append('g');
  const bandLayer = canvas.append('g');
  const edgeLayer = canvas.append('g').attr('fill', 'none');
  const nodeLayer = canvas.append('g');

  const zoom = d3.zoom().scaleExtent([0.08, 3])
    .on('zoom', e => canvas.attr('transform', e.transform));
  svg.call(zoom).on('dblclick.zoom', null);

  // Measures label widths so each box is only as wide as it needs to be.
  const measure = document.createElement('canvas').getContext('2d');
  measure.font = '600 12px ' + (getComputedStyle(document.body).fontFamily || 'sans-serif');
  const widthOf = label => Math.max(64, Math.min(240, measure.measureText(label).width + 26));

  // Height the drawing needs, and the scale it will actually be shown at. Both the viewport
  // sizing and `fit` go through these so they cannot disagree.
  const contentHeight = extent => extent.h + MARGIN.top + MARGIN.bottom + NODE_H;
  const viewScale = extent => Math.min(2.2, 0.98 * Math.min(
    width / Math.max(1, extent.w + MARGIN.left + MARGIN.right),
    VIEW_H / Math.max(1, contentHeight(extent))));

  // ---------------------------------------------------------------- layout

  /* Longest-path layering. `parents` are a declaration's dependencies, so a node sits one row
     below the deepest thing it depends on. Written iteratively over a topological-ish order and
     guarded against cycles, which the dependency graph can contain in rare cases. */
  function assignDepths(ids, parentsOf) {
    const depth = new Map();
    const visiting = new Set();
    const walk = id => {
      if (depth.has(id)) return depth.get(id);
      if (visiting.has(id)) return 0;      // cycle: stop descending
      visiting.add(id);
      let d = 0;
      for (const p of parentsOf.get(id) || []) d = Math.max(d, walk(p) + 1);
      visiting.delete(id);
      depth.set(id, d);
      return d;
    };
    for (const id of ids) walk(id);
    return depth;
  }

  /* Builds the layered structure: real nodes plus the waypoints that long edges pass through.
     Returns rows of cells and the routed edges. */
  function buildLayers(nodes, edges) {
    const parentsOf = new Map(nodes.map(n => [n.id, []]));
    const byId = new Map(nodes.map(n => [n.id, n]));
    for (const e of edges) parentsOf.get(e.target)?.push(e.source);

    const depth = assignDepths(nodes.map(n => n.id), parentsOf);
    const rowCount = nodes.length ? Math.max(...nodes.map(n => depth.get(n.id))) + 1 : 0;
    const rows = Array.from({ length: rowCount }, () => []);

    for (const n of nodes) {
      const cell = {
        key: n.id, node: n, row: depth.get(n.id),
        w: widthOf(n.label), up: [], down: [], x: 0,
      };
      n.cell = cell;
      rows[cell.row].push(cell);
    }

    // Route each edge, inserting a waypoint per skipped row.
    const routed = [];
    for (const e of edges) {
      const a = byId.get(e.source)?.cell, b = byId.get(e.target)?.cell;
      if (!a || !b) continue;
      const chain = [a];
      /* A back edge: the dependency ended up at or below what uses it. This is not a layout bug —
         the declaration graph genuinely contains cycles (mutually referential declarations), and
         no assignment of rows can put every declaration below all of its dependencies when a cycle
         exists. Such edges are drawn distinctly rather than hidden. */
      const isBack = b.row <= a.row;
      for (let r = a.row + 1; r < b.row; r++) {
        const way = { key: `${e.source}->${e.target}@${r}`, node: null, row: r, w: 1, up: [], down: [], x: 0 };
        rows[r].push(way);
        chain.push(way);
      }
      chain.push(b);
      for (let i = 0; i < chain.length - 1; i++) {
        chain[i].down.push(chain[i + 1]);
        chain[i + 1].up.push(chain[i]);
      }
      routed.push({ edge: e, chain, source: a, target: b, back: isBack });
    }

    // Stable initial order, then median sweeps to reduce crossings.
    for (const row of rows) {
      row.sort((p, q) => {
        const pn = p.node, qn = q.node;
        if (pn && qn) return d3.ascending(pn.moduleName + pn.label, qn.moduleName + qn.label);
        return pn ? -1 : qn ? 1 : d3.ascending(p.key, q.key);
      });
      row.forEach((c, i) => { c.order = i; });
    }
    const median = (cell, side) => {
      const ns = cell[side];
      if (!ns.length) return null;
      const xs = ns.map(n => n.order).sort((a, b) => a - b);
      const m = xs.length >> 1;
      return xs.length % 2 ? xs[m] : (xs[m - 1] + xs[m]) / 2;
    };
    for (let s = 0; s < SWEEPS; s++) {
      const down = s % 2 === 0;
      const seq = down ? d3.range(1, rows.length) : d3.range(rows.length - 1).reverse();
      for (const r of seq) {
        const side = down ? 'up' : 'down';
        const keyed = rows[r].map(c => ({ c, m: median(c, side) }));
        keyed.sort((p, q) => {
          if (p.m === null && q.m === null) return p.c.order - q.c.order;
          if (p.m === null) return -1;
          if (q.m === null) return 1;
          return p.m - q.m || p.c.order - q.c.order;
        });
        rows[r] = keyed.map(k => k.c);
        rows[r].forEach((c, i) => { c.order = i; });
      }
    }

    // Horizontal placement: pack each row, then nudge toward connected neighbours while keeping
    // the order and minimum separation intact. Purely geometric — it never reorders anything.
    for (const row of rows) {
      let x = 0;
      for (const c of row) { c.x = x + c.w / 2; x += c.w + NODE_GAP; }
    }
    /* Where a cell would like to sit: the median of everything it connects to. Median rather than
       mean, because one far-off neighbour should not drag a node across the row. Waypoints follow
       their two chain neighbours exactly, which is what pulls a long edge into a straight line
       instead of the wandering curve a mean produces. */
    const desired = (cell) => {
      const ns = cell.up.concat(cell.down);
      if (!ns.length) return cell.x;
      const xs = ns.map(n => n.x).sort((a, b) => a - b);
      const m = xs.length >> 1;
      return xs.length % 2 ? xs[m] : (xs[m - 1] + xs[m]) / 2;
    };
    for (let pass = 0; pass < STRAIGHTEN; pass++) {
      // Alternate direction so neither the top nor the bottom of the graph wins every time.
      const order = pass % 2 === 0 ? rows : [...rows].reverse();
      for (const row of order) {
        for (const c of row) c.want = desired(c);
        // left to right, honouring separation
        let limit = -Infinity;
        for (const c of row) {
          c.x = Math.max(c.want, limit + NODE_GAP + c.w / 2);
          limit = c.x + c.w / 2;
        }
        // right to left, so the row is not dragged rightwards over time
        limit = Infinity;
        for (let i = row.length - 1; i >= 0; i--) {
          const c = row[i];
          c.x = Math.min(c.x, limit - NODE_GAP - c.w / 2);
          limit = c.x - c.w / 2;
        }
      }
    }

    /* Cap the slack left by straightening. Each pass moves a node right to meet the median of its
       neighbours and nothing ever pulls the row back, so the gaps compound: brownian-motion's 50
       modules — widest row 19 — laid out 11,400px wide, several times what the boxes need, and the
       drawing became unreadable. Closing any gap wider than this keeps the layout straight where
       it can be and stops it growing where it cannot. */
    const MAX_GAP = NODE_GAP * 4;
    for (const row of rows) {
      for (let i = 1; i < row.length; i++) {
        const gap = (row[i].x - row[i].w / 2) - (row[i - 1].x + row[i - 1].w / 2);
        if (gap > MAX_GAP) {
          const shift = gap - MAX_GAP;
          for (let j = i; j < row.length; j++) row[j].x -= shift;
        }
      }
    }

    // Centre every row on the widest one and lift the whole drawing to the origin.
    let minX = Infinity, maxX = -Infinity;
    for (const row of rows) {
      for (const c of row) { minX = Math.min(minX, c.x - c.w / 2); maxX = Math.max(maxX, c.x + c.w / 2); }
    }
    const span = maxX - minX;
    for (const row of rows) {
      if (!row.length) continue;
      const lo = row[0].x - row[0].w / 2, hi = row[row.length - 1].x + row[row.length - 1].w / 2;
      const shift = (span - (hi - lo)) / 2 - (lo - minX);
      for (const c of row) { c.x += shift - minX; c.y = MARGIN.top + c.row * ROW_GAP + NODE_H / 2; }
    }
    return { rows, routed, extent: { w: span, h: rowCount * ROW_GAP } };
  }

  // ---------------------------------------------------------------- rendering

  const lineThrough = d3.line().x(d => d.x).y(d => d.y);

  function edgePath(r) {
    if (r.back) {
      // Bow a cycle edge out to the side so it reads as an exception to the downward flow rather
      // than as an arrow pointing the wrong way through the middle of the picture.
      const a = r.source, b = r.target;
      const x0 = a.x, y0 = a.y - NODE_H / 2;
      const x1 = b.x, y1 = b.y + NODE_H / 2 + 3;
      const side = (x1 >= x0 ? 1 : -1);
      const bow = 42 + Math.abs(a.row - b.row) * 14;
      return `M${x0},${y0} C${x0 + side * bow},${y0 - 26} ${x1 + side * bow},${y1 + 26} ${x1},${y1}`;
    }
    const pts = r.chain.map((c, i) => ({
      x: c.x,
      // Leave the bottom of the source and stop just above the target's box.
      y: i === 0 ? c.y + NODE_H / 2
        : i === r.chain.length - 1 ? c.y - NODE_H / 2 - 3
        : c.y,
    }));
    return lineThrough.curve(pts.length === 2 ? d3.curveBumpY : d3.curveMonotoneY)(pts);
  }

  let state = { rows: [], routed: [], sel: null, byId: new Map(), up: new Map(), down: new Map() };

  function render(nodes, edges) {
    const { rows, routed, extent } = buildLayers(nodes, edges);
    /* Height the drawing area to whatever the graph actually needs at the scale the width allows,
       between a floor that keeps tiny graphs from looking cramped and the full viewport.

       A lone node is sized without that scale. `viewScale` zooms a small graph up to 2.2x to fill
       the column, which is right when there is structure to see and absurd when there is not: one
       26px box would be given ~336px of canvas and sit alone at the top of it, reading as a picture
       that failed to load rather than as an answer. */
    viewH = isLone
      ? Math.round(contentHeight(extent) + 8)
      : Math.round(Math.max(260, Math.min(VIEW_H, contentHeight(extent) * viewScale(extent) + 24)));
    svg.attr('height', viewH).attr('viewBox', [0, 0, width, viewH]);
    /* A wide graph gets the full column, with the details panel below it rather than beside it.
       A whole-project module graph is several times wider than it is tall, and surrendering a
       fifth of the width to a mostly-empty panel is what pushes it from tight to illegible. */
    const layout = root.querySelector('.graph-layout');
    if (layout) layout.classList.toggle('graph-layout--wide', extent.w > 1600);
    state.rows = rows;
    state.routed = routed;
    state.byId = new Map(nodes.map(n => [n.id, n]));
    state.up = new Map(nodes.map(n => [n.id, []]));
    state.down = new Map(nodes.map(n => [n.id, []]));
    for (const e of edges) {
      state.down.get(e.source)?.push(e.target);
      state.up.get(e.target)?.push(e.source);
    }

    // Row bands and depth labels.
    const bands = bandLayer.selectAll('g.graph-band').data(rows.map((r, i) => i));
    const bandEnter = bands.enter().append('g').attr('class', 'graph-band');
    bandEnter.append('rect');
    bandEnter.append('text');
    bands.exit().remove();
    const allBands = bandEnter.merge(bands);
    allBands.select('rect')
      .attr('x', -MARGIN.left).attr('y', i => MARGIN.top + i * ROW_GAP - NODE_H / 2 - 12)
      .attr('width', extent.w + MARGIN.left + MARGIN.right).attr('height', NODE_H + 24)
      .attr('fill', i => (i % 2 ? theme.band : 'transparent'));
    allBands.select('text')
      .attr('x', -MARGIN.left + 12).attr('y', i => MARGIN.top + i * ROW_GAP + 4)
      .attr('class', 'graph-row-label')
      .text(i => (i === 0 ? 'no deps' : String(i)));

    const edgeSel = edgeLayer.selectAll('path').data(routed, r => r.edge.source + '\0' + r.edge.target);
    edgeSel.exit().remove();
    edgeSel.enter().append('path')
      .attr('stroke-width', 1.5)
      .attr('stroke-linecap', 'round')
      .attr('marker-end', 'url(#graph-arrow)')
      .merge(edgeSel)
      .attr('d', edgePath)
      .attr('stroke', r => (r.back ? theme.back : theme.edge))
      .attr('stroke-dasharray', r => (r.back ? '5 3' : null))
      .attr('stroke-opacity', r => (r.back ? 0.9 : 0.75));

    const nodeSel = nodeLayer.selectAll('g.graph-node').data(nodes, n => n.id);
    nodeSel.exit().remove();
    const enter = nodeSel.enter().append('g').attr('class', 'graph-node').style('cursor', 'pointer');
    enter.append('rect').attr('class', 'graph-box').attr('rx', 8).attr('ry', 8);
    enter.append('text').attr('class', 'graph-label');
    // The verdict badge, in the node's top-right corner rather than inside it: the label is
    // centred and truncated to the box width, so anything placed in the body would either collide
    // with it or cost it characters. Two elements so the glyph reads against any chapter colour.
    enter.append('circle').attr('class', 'graph-verdict-dot');
    enter.append('text').attr('class', 'graph-verdict-mark');
    enter.append('title');
    const all = enter.merge(nodeSel);

    all.attr('transform', n => `translate(${n.cell.x},${n.cell.y})`);
    all.select('rect.graph-box')
      .attr('x', n => -n.cell.w / 2).attr('y', -NODE_H / 2)
      .attr('width', n => n.cell.w).attr('height', NODE_H)
      // The declaration whose page this is gets a solid fill; everything else is a light tint of
      // its chapter colour, so the eye lands on the subject of the page first.
      .attr('fill', n => {
        if (n.focus) return theme.focusFill;
        const c = d3.color(colorOf(n.groupKey)); c.opacity = 0.13; return c.formatRgb();
      })
      .attr('stroke', n => (n.focus ? theme.focusFill
        : n.status === 'sorry' ? theme.sorry
        : n.status === 'untrusted' ? theme.untrusted : colorOf(n.groupKey)))
      .attr('stroke-width', n => (n.focus ? 2 : 1.3))
      .attr('stroke-dasharray', n =>
        ((n.status === 'sorry' || n.status === 'untrusted') && !n.focus ? '4 3' : null));
    all.select('text.graph-label')
      .attr('text-anchor', 'middle').attr('dominant-baseline', 'central')
      .attr('fill', n => (n.focus ? theme.focusInk : theme.ink))
      .text(n => {
        const max = Math.floor((n.cell.w - 16) / 6.6);
        return n.label.length > max ? n.label.slice(0, Math.max(1, max - 1)) + '…' : n.label;
      });
    all.select('title').text(n => {
      const m = verdictMark(n);
      return `${n.kind}: ${n.id}\n${n.moduleName}` + (m ? `\n(${m.title})` : '');
    });
    paintVerdicts();

    all.on('mouseenter', (_, n) => highlight(n.id))
      .on('mouseleave', () => highlight(state.sel))
      .on('click', (event, n) => {
        event.preventDefault();
        state.sel = state.sel === n.id ? null : n.id;
        highlight(state.sel);
        updatePanel();
      })
      // Nodes without an href — upstream declarations, packages — have no page here, so a
      // double-click must do nothing rather than navigate to the site root.
      .on('dblclick', (event, n) => {
        event.preventDefault();
        if (n.href) window.location.href = n.href;
      });

    updatePanel();
    fit();
  }

  /* Dims everything not adjacent to `id`. Only opacity and colour change, so the drawing never
     moves — the reason a static layout is worth having in the first place. */
  function highlight(id) {
    const near = new Set();
    if (id) {
      near.add(id);
      for (const x of state.up.get(id) || []) near.add(x);
      for (const x of state.down.get(id) || []) near.add(x);
    }
    nodeLayer.selectAll('g.graph-node')
      .style('opacity', n => (!id || near.has(n.id) ? 1 : 0.2));
    nodeLayer.selectAll('rect.graph-box')
      .attr('stroke-width', n => (n.id === id ? 2.6 : n.focus ? 2 : 1.3));
    edgeLayer.selectAll('path')
      .attr('stroke', r => (id && (r.edge.source === id || r.edge.target === id) ? theme.edgeHot
        : r.back ? theme.back : theme.edge))
      .attr('marker-end', r => (id && (r.edge.source === id || r.edge.target === id)
        ? 'url(#graph-arrow-hot)' : 'url(#graph-arrow)'))
      .attr('stroke-opacity', r => {
        if (!id) return r.back ? 0.9 : 0.75;
        return (r.edge.source === id || r.edge.target === id) ? 1 : 0.12;
      });
  }

  /* Paints the verdict badges over whatever is currently drawn.

     Separate from `render` so that setting a verdict elsewhere on the page — the control under the
     card, or the keyboard shortcuts — updates the picture without relaying it: the layout has not
     changed, only the reader's opinion of it. */
  function paintVerdicts() {
    const R = 6.5;
    nodeLayer.selectAll('g.graph-node').each(function (n) {
      const g = d3.select(this);
      const m = verdictMark(n);
      const at = n.cell.w / 2 - R + 2;   // the corner, overlapping the rounded edge slightly
      g.select('circle.graph-verdict-dot')
        .attr('cx', at).attr('cy', -NODE_H / 2 + 1).attr('r', R)
        .attr('fill', m ? m.fill : 'none')
        .attr('stroke', m ? theme.focusInk : 'none').attr('stroke-width', 1)
        .style('display', m ? null : 'none');
      g.select('text.graph-verdict-mark')
        .attr('x', at).attr('y', -NODE_H / 2 + 1)
        .attr('text-anchor', 'middle').attr('dominant-baseline', 'central')
        .attr('font-size', 9).attr('font-weight', 700)
        .attr('fill', theme.focusInk)
        .style('display', m ? null : 'none')
        .text(m ? m.glyph : '');
    });
  }

  // A verdict set anywhere on the page repaints the badges here. `audit.js` dispatches this on
  // every change, including the bulk "accept everything its statement rests on", which is exactly
  // the action whose effect a reader wants to see land on this picture.
  document.addEventListener('referee:auditchange', paintVerdicts);

  /* Declaration names are not safe to interpolate raw: Lean names legitimately contain `<` and `&`
     (`«term_<_»`, for one), which would otherwise be swallowed as markup. */
  const esc = s => String(s).replace(/[&<>"]/g,
    c => ({ '&': '&amp;', '<': '&lt;', '>': '&gt;', '"': '&quot;' }[c]));


  function updatePanel() {
    // Absent on a lone-node graph, which has nothing to report about neighbours or rows.
    if (!panel) return;
    const shown = state.byId.size;
    const rows = state.rows.length;
    if (!state.sel || !state.byId.has(state.sel)) {
      panel.innerHTML = `
        <h2>Graph</h2>
        <p>${shown} ${UNITS} across ${rows} dependency ${rows === 1 ? 'row' : 'rows'}.</p>
        <p>The top row depends on nothing. Click a node for its details.</p>`;
      return;
    }
    /* What the reader wants after clicking is what the declaration *says* — its statement and its
       docstring. Nothing here restates the graph: the row it sits in, what it depends on and what
       uses it are all already drawn, and clicking the node highlights exactly those edges. The
       panel is for what the picture cannot show. */
    const n = state.byId.get(state.sel);
    const warn = n.status === 'sorry'
      ? '<p class="graph-panel-warn">⚠ depends on <code>sorry</code></p>'
      : n.status === 'untrusted'
      ? '<p class="graph-panel-warn">⚠ not audited</p>' : '';
    const sig = n.signature ? `<pre class="graph-panel-code">${esc(n.signature)}</pre>` : '';
    const doc = n.doc
      ? `<p class="graph-panel-doc">${esc(n.doc)}</p>`
      : '<p class="graph-panel-doc graph-panel-nodoc">No docstring.</p>';
    panel.innerHTML = `
      <h2>${esc(n.label)}</h2>
      <p class="graph-panel-meta">${esc(n.kind)} · <code>${esc(n.moduleName)}</code></p>
      ${warn}
      ${sig}
      ${doc}
      ${n.href ? `<p><a class="decl-card-action" href="${esc(n.href)}">Open declaration</a></p>` : ''}`;
  }

  function fit() {
    const cells = [];
    for (const row of state.rows) for (const c of row) if (c.node) cells.push(c);
    if (!cells.length) return;
    const minX = d3.min(cells, c => c.x - c.w / 2) - MARGIN.left;
    const maxX = d3.max(cells, c => c.x + c.w / 2) + MARGIN.right;
    const minY = d3.min(cells, c => c.y) - MARGIN.top - NODE_H;
    const maxY = d3.max(cells, c => c.y) + MARGIN.bottom + NODE_H;
    /* Fit the whole graph, and let the reader zoom for detail. Capping how far it may shrink was
       tried and abandoned: it crops a wide graph to a corner, which is worse than a small but
       complete picture of the structure — seeing the shape is the point of the page. */
    const scale = Math.min(2.2, 0.98 * Math.min(width / (maxX - minX), viewH / (maxY - minY)));
    svg.transition().duration(200).call(
      zoom.transform,
      d3.zoomIdentity
        .translate(width / 2 - scale * (minX + maxX) / 2, viewH / 2 - scale * (minY + maxY) / 2)
        .scale(scale));
  }

  // ---------------------------------------------------------------- filtering

  /* Filtering rebuilds the layout from the surviving subgraph rather than hiding nodes in place,
     so rows stay dense and the picture stays readable at every filter setting. */
  let query = '', group = '';
  function apply() {
    const keep = allNodes.filter(n => {
      const okGroup = group === '' || n.groupKey === group;
      const okQuery = query === '' || `${n.id} ${n.moduleName}`.toLowerCase().includes(query);
      return okGroup && okQuery;
    });
    const ids = new Set(keep.map(n => n.id));
    if (state.sel && !ids.has(state.sel)) state.sel = null;
    render(keep, allEdges.filter(e => ids.has(e.source) && ids.has(e.target)));
    highlight(state.sel);
  }

  /* Every control is optional: a lone-node graph renders none of them, because filtering,
     fitting and clearing a focus are all operations on something the reader can already see
     whole. */
  if (filterInput) {
    filterInput.addEventListener('input', e => {
      query = e.target.value.trim().toLowerCase(); apply();
    });
  }
  // The chapter filter is only rendered when there is more than one chapter to choose between.
  if (groupSelect) groupSelect.addEventListener('change', e => { group = e.target.value; apply(); });
  const fitButton = document.getElementById('graph-fit');
  if (fitButton) fitButton.addEventListener('click', fit);
  const clearButton = document.getElementById('graph-clear');
  if (clearButton) {
    clearButton.addEventListener('click', () => {
      state.sel = null; highlight(null); updatePanel();
    });
  }

  document.addEventListener('referee:themechange', () => {
    readTheme();
    d3.selectAll('#graph-svg marker path')
      .attr('fill', function () {
        return this.parentNode.id === 'graph-arrow-hot' ? theme.edgeHot : theme.edge;
      });
    apply();
  });

  apply();
});
