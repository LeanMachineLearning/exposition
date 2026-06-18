namespace LMLExposition

def graphJs : String := "
document.addEventListener('DOMContentLoaded', () => {
  const root = document.getElementById('graph-root');
  const dataNode = document.getElementById('graph-data');
  if (!root || !dataNode || !window.d3) return;

  const graph = JSON.parse(dataNode.textContent);
  const groups = [...new Set(graph.nodes.map(node => node.groupKey))].sort();
  const groupOptions = groups.map(group => `<option value=\"${group}\">${group}</option>`).join('');
  root.innerHTML = `
    <div class=\"graph-toolbar\">
      <input id=\"graph-filter\" type=\"search\" placeholder=\"Filter declarations by name or module\" />
      <select id=\"graph-group\">
        <option value=\"\">All chapters</option>
        ${groupOptions}
      </select>
      <button id=\"graph-fit\" type=\"button\">Fit view</button>
      <button id=\"graph-clear\" type=\"button\">Clear focus</button>
    </div>
    <p class=\"graph-hint\">Scroll to zoom, drag the background to pan, click a node to focus its neighborhood, and double-click a node to open its page. Arrows point from a declaration to the declarations that depend on it.</p>
    <p class=\"graph-legend\">Node fill colors mark chapters. Green outlines are kernel-checked; rust outlines contain sorry.</p>
    <div class=\"graph-layout\">
      <svg id=\"graph-svg\" width=\"100%\" height=\"720\"></svg>
      <aside id=\"graph-panel\" class=\"graph-panel\">
        <h2>Graph</h2>
        <p>Use search or click a node to focus its local neighborhood.</p>
      </aside>
    </div>
  `;

  const svg = d3.select('#graph-svg');
  const panel = document.getElementById('graph-panel');
  const filterInput = document.getElementById('graph-filter');
  const groupSelect = document.getElementById('graph-group');
  const fitButton = document.getElementById('graph-fit');
  const clearButton = document.getElementById('graph-clear');
  const width = Math.max(960, root.clientWidth - 32);
  const height = 720;
  svg.attr('viewBox', [0, 0, width, height]);
  const canvas = svg.append('g').attr('class', 'graph-canvas');

  let nodes = graph.nodes.map(n => ({...n}));
  let edges = graph.edges.map(e => ({...e}));
  const nodeById = new Map(nodes.map(node => [node.id, node]));
  const outgoing = new Map(nodes.map(node => [node.id, []]));
  const incoming = new Map(nodes.map(node => [node.id, []]));
  const degree = new Map(nodes.map(node => [node.id, 0]));
  for (const edge of edges) {
    degree.set(edge.source, (degree.get(edge.source) || 0) + 1);
    degree.set(edge.target, (degree.get(edge.target) || 0) + 1);
    outgoing.get(edge.source)?.push(edge.target);
    incoming.get(edge.target)?.push(edge.source);
  }

  const palette = ['#3d6b59', '#b96d2d', '#7a4e7a', '#2f5f87', '#8a3b3b', '#5f6f2e', '#9a5b8f', '#6b5041'];
  const color = d3.scaleOrdinal(groups, groups.map((_, index) => palette[index % palette.length]));

  // Size each node's oval to fit its label, so the short declaration name can sit inside it.
  const labelFont = '600 11px sans-serif';
  const measureCtx = document.createElement('canvas').getContext('2d');
  measureCtx.font = labelFont;
  for (const n of nodes) {
    n.rx = Math.max(28, measureCtx.measureText(n.label).width / 2 + 14);
    n.ry = 17;
  }

  // Edges point from a dependency (\"parent\") to the declaration that depends on it (\"child\"),
  // so a node's depth is one more than the deepest of its parents (its incoming neighbors).
  // Nodes with no parents (depth 0) are the most foundational declarations in the graph.
  const depthCache = new Map();
  const computeDepth = (id, stack) => {
    if (depthCache.has(id)) return depthCache.get(id);
    if (stack.has(id)) return 0;
    stack.add(id);
    let depth = 0;
    for (const parent of incoming.get(id) || []) {
      depth = Math.max(depth, computeDepth(parent, stack) + 1);
    }
    stack.delete(id);
    depthCache.set(id, depth);
    return depth;
  };
  for (const n of nodes) n.depth = computeDepth(n.id, new Set());

  const layerSpacing = 110;
  const layerMargin = 70;
  // Depth 0 (parents, the most foundational declarations) sits at the top; deeper nodes
  // (declarations with more dependencies) are placed below.
  const yForDepth = depth => layerMargin + depth * layerSpacing;

  const simulation = d3.forceSimulation(nodes)
    .force('link', d3.forceLink(edges).id(d => d.id).distance(80).strength(0.15))
    .force('charge', d3.forceManyBody().strength(-150))
    .force('x', d3.forceX(width / 2).strength(0.03))
    .force('y', d3.forceY(d => yForDepth(d.depth)).strength(1))
    .force('collision', d3.forceCollide(d => Math.max(d.rx, d.ry) + 6));

  const zoom = d3.zoom()
    .scaleExtent([0.25, 4])
    .on('zoom', event => {
      canvas.attr('transform', event.transform);
    });
  svg.call(zoom);

  const defs = svg.append('defs');
  const arrowMarker = (id, fill) => {
    defs.append('marker')
      .attr('id', id)
      .attr('viewBox', '0 0 10 10')
      .attr('refX', 8)
      .attr('refY', 5)
      .attr('markerWidth', 6)
      .attr('markerHeight', 6)
      .attr('orient', 'auto-start-reverse')
      .append('path')
      .attr('d', 'M0,0 L10,5 L0,10 Z')
      .attr('fill', fill);
  };
  arrowMarker('graph-arrow-default', '#1a1a1a');
  arrowMarker('graph-arrow-highlight', '#a14d2a');

  const link = canvas.append('g')
    .attr('stroke-opacity', 0.8)
    .selectAll('line')
    .data(edges)
    .join('line')
    .attr('stroke', '#1a1a1a')
    .attr('stroke-width', 1.6)
    .attr('marker-end', 'url(#graph-arrow-default)');

  const node = canvas.append('g')
    .selectAll('g')
    .data(nodes)
    .join('g')
    .attr('class', 'graph-node')
    .style('cursor', 'pointer');

  const shapes = node.append('ellipse')
    .attr('rx', d => d.rx)
    .attr('ry', d => d.ry)
    .attr('fill', d => color(d.groupKey))
    .attr('stroke', d => d.status === 'sorry' ? '#a14d2a' : '#1f6b4b')
    .attr('stroke-width', 2.2);

  node.append('title')
    .text(d => `${d.kind}: ${d.id}\\n${d.moduleName}`);

  const labels = node.append('text')
    .attr('class', 'graph-label')
    .text(d => d.label)
    .attr('text-anchor', 'middle')
    .attr('dominant-baseline', 'middle')
    .attr('y', 4)
    .attr('font', labelFont)
    .attr('fill', '#f7f3ea')
    .style('pointer-events', 'none');

  const formatNeighborList = (title, ids) => {
    if (!ids || ids.length === 0) {
      return `<p><strong>${title}:</strong> none in the exposed graph.</p>`;
    }
    const items = ids.slice(0, 10).map(id => {
      const node = nodeById.get(id);
      return `<li><a href=\"${node.href}\"><code>${node.label}</code></a></li>`;
    }).join('');
    const extra = ids.length > 10 ? `<p>Showing 10 of ${ids.length}.</p>` : '';
    return `<p><strong>${title}:</strong></p><ul class=\"graph-neighbor-list\">${items}</ul>${extra}`;
  };

  const setDefaultPanel = visibleCount => {
    panel.innerHTML = `
      <h2>Graph</h2>
      <p>${visibleCount} declarations are visible in the current filter.</p>
      <p>Select a node to inspect its module and immediate dependencies.</p>
    `;
  };

  const zoomToBounds = visibleNodes => {
    const positioned = visibleNodes.filter(node =>
      Number.isFinite(node.x) && Number.isFinite(node.y));
    if (positioned.length === 0) return;
    const minX = d3.min(positioned, node => node.x);
    const maxX = d3.max(positioned, node => node.x);
    const minY = d3.min(positioned, node => node.y);
    const maxY = d3.max(positioned, node => node.y);
    const boxWidth = Math.max(120, maxX - minX + 80);
    const boxHeight = Math.max(120, maxY - minY + 80);
    const scale = Math.max(0.3, Math.min(2.4, 0.9 / Math.max(boxWidth / width, boxHeight / height)));
    const tx = width / 2 - scale * ((minX + maxX) / 2);
    const ty = height / 2 - scale * ((minY + maxY) / 2);
    svg.transition().duration(250).call(zoom.transform, d3.zoomIdentity.translate(tx, ty).scale(scale));
  };

  let activeQuery = '';
  let activeGroup = '';
  let selectedId = null;

  const filteredIds = () => new Set(
    nodes
      .filter(node => {
        const matchesGroup = activeGroup === '' || node.groupKey === activeGroup;
        const haystack = `${node.id} ${node.moduleName}`.toLowerCase();
        const matchesQuery = activeQuery === '' || haystack.includes(activeQuery);
        return matchesGroup && matchesQuery;
      })
      .map(node => node.id)
  );

  const neighborhoodIds = () => {
    if (!selectedId) return null;
    const ids = new Set([selectedId]);
    for (const dep of outgoing.get(selectedId) || []) ids.add(dep);
    for (const user of incoming.get(selectedId) || []) ids.add(user);
    return ids;
  };

  const updatePanel = visible => {
    if (!selectedId) {
      setDefaultPanel(visible.size);
      return;
    }
    const selected = nodeById.get(selectedId);
    const deps = incoming.get(selectedId) || [];
    const usedBy = outgoing.get(selectedId) || [];
    panel.innerHTML = `
      <h2>${selected.label}</h2>
      <p><strong>Kind:</strong> ${selected.kind}</p>
      <p><strong>Status:</strong> ${selected.status}</p>
      <p><strong>Chapter:</strong> <code>${selected.groupKey}</code></p>
      <p><strong>Module:</strong> <code>${selected.moduleName}</code></p>
      <p><a class=\"decl-card-action\" href=\"${selected.href}\">Open declaration</a></p>
      ${formatNeighborList('Uses', deps)}
      ${formatNeighborList('Used by', usedBy)}
    `;
  };

  const updateVisibility = () => {
    const visible = filteredIds();
    if (selectedId && !visible.has(selectedId)) selectedId = null;
    const neighborhood = neighborhoodIds();

    node
      .style('display', d => visible.has(d.id) ? null : 'none')
      .style('opacity', d => {
        if (!visible.has(d.id)) return 0;
        if (!neighborhood) return 1;
        return neighborhood.has(d.id) ? 1 : 0.15;
      });

    labels
      .style('display', d => {
        if (!visible.has(d.id)) return 'none';
        if (neighborhood) return neighborhood.has(d.id) ? null : 'none';
        return null;
      });

    shapes
      .attr('stroke-width', d => d.id === selectedId ? 4 : 2.2);

    link
      .style('display', d => {
        const source = typeof d.source === 'object' ? d.source.id : d.source;
        const target = typeof d.target === 'object' ? d.target.id : d.target;
        return visible.has(source) && visible.has(target) ? null : 'none';
      })
      .style('opacity', d => {
        const source = typeof d.source === 'object' ? d.source.id : d.source;
        const target = typeof d.target === 'object' ? d.target.id : d.target;
        if (!visible.has(source) || !visible.has(target)) return 0;
        if (!neighborhood) return 0.65;
        return neighborhood.has(source) && neighborhood.has(target) ? 0.9 : 0.05;
      })
      .attr('stroke', d => {
        const source = typeof d.source === 'object' ? d.source.id : d.source;
        const target = typeof d.target === 'object' ? d.target.id : d.target;
        return selectedId && (source === selectedId || target === selectedId) ? '#a14d2a' : '#1a1a1a';
      })
      .attr('marker-end', d => {
        const source = typeof d.source === 'object' ? d.source.id : d.source;
        const target = typeof d.target === 'object' ? d.target.id : d.target;
        return selectedId && (source === selectedId || target === selectedId)
          ? 'url(#graph-arrow-highlight)'
          : 'url(#graph-arrow-default)';
      });

    updatePanel(visible);
    return visible;
  };

  const drag = d3.drag()
    .on('start', (event, d) => {
      if (!event.active) simulation.alphaTarget(0.2).restart();
      d.fx = d.x;
      d.fy = d.y;
    })
    .on('drag', (event, d) => {
      d.fx = event.x;
      d.fy = event.y;
    })
    .on('end', (event, d) => {
      if (!event.active) simulation.alphaTarget(0);
      d.fx = null;
      d.fy = null;
    });

  node.call(drag);

  node.on('click', (event, d) => {
    event.preventDefault();
    selectedId = d.id == selectedId ? null : d.id;
    updateVisibility();
    if (selectedId) {
      const neighborhood = neighborhoodIds() || new Set();
      zoomToBounds(nodes.filter(node => neighborhood.has(node.id)));
    }
  });

  node.on('dblclick', (event, d) => {
    event.preventDefault();
    window.location.href = d.href;
  });

  const targetEndpoint = d => {
    const dx = d.target.x - d.source.x;
    const dy = d.target.y - d.source.y;
    const dist = Math.sqrt(dx * dx + dy * dy) || 1;
    const ux = dx / dist, uy = dy / dist;
    // Distance from the target's center to its ellipse boundary along the (ux, uy) direction.
    const boundary = 1 / Math.sqrt((ux / d.target.rx) ** 2 + (uy / d.target.ry) ** 2);
    const gap = boundary + 4;
    return { x: d.target.x - ux * gap, y: d.target.y - uy * gap };
  };

  simulation.on('tick', () => {
    link
      .attr('x1', d => d.source.x)
      .attr('y1', d => d.source.y)
      .attr('x2', d => targetEndpoint(d).x)
      .attr('y2', d => targetEndpoint(d).y);

    node.attr('transform', d => `translate(${d.x},${d.y})`);
  });

  filterInput.addEventListener('input', event => {
    activeQuery = event.target.value.trim().toLowerCase();
    updateVisibility();
  });

  groupSelect.addEventListener('change', event => {
    activeGroup = event.target.value;
    updateVisibility();
  });

  fitButton.addEventListener('click', () => {
    const visible = updateVisibility();
    const neighborhood = neighborhoodIds();
    zoomToBounds(nodes.filter(node => visible.has(node.id) && (!neighborhood || neighborhood.has(node.id))));
  });

  clearButton.addEventListener('click', () => {
    selectedId = null;
    const visible = updateVisibility();
    zoomToBounds(nodes.filter(node => visible.has(node.id)));
  });

  svg.on('dblclick', event => {
    if (event.target === svg.node()) {
      selectedId = null;
      const visible = updateVisibility();
      zoomToBounds(nodes.filter(node => visible.has(node.id)));
    }
  });

  setDefaultPanel(nodes.length);
  setTimeout(() => {
    const visible = updateVisibility();
    zoomToBounds(nodes.filter(node => visible.has(node.id)));
  }, 800);
});
"

end LMLExposition
