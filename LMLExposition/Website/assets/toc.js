
document.addEventListener('DOMContentLoaded', () => {
  const toc = document.getElementById('toc');
  if (!toc) return;
  /* Pages promoted out of the table of contents into a small nav at the top of the sidebar.
     Each link's href is taken from the table-of-contents entry it replaces rather than hardcoded:
     the sidebar renders on pages at every depth, so a fixed relative path like 'claims/' resolves
     *underneath* whatever page the reader is on. Deriving it also means a slug with no entry is
     simply not shown — removing a page can no longer leave a dead link here, which is exactly how
     a "Graph" link outlived the graph page. */
  const utilityLinks = [
    { slug: 'claims', label: 'Claims' },
    { slug: 'trust', label: 'Trust' }
  ];

  const normalizeHref = href => {
    if (!href) return '';
    try {
      const url = new URL(href, document.baseURI);
      let path = url.pathname;
      if (path.endsWith('index.html')) path = path.slice(0, -'index.html'.length);
      return path.endsWith('/') ? path : `${path}/`;
    } catch (_err) {
      return href;
    }
  };

  const matchesUtility = (href, slug) => {
    const normalized = normalizeHref(href);
    return normalized === `/${slug}/` || normalized.endsWith(`/${slug}/`);
  };

  // The real href of each promoted page, as the table of contents spells it from this page.
  const findUtilityHrefs = () => {
    const found = new Map();
    const consider = anchor => {
      const href = anchor?.getAttribute('href') || '';
      for (const link of utilityLinks) {
        if (!found.has(link.slug) && matchesUtility(href, link.slug)) found.set(link.slug, href);
      }
    };
    toc.querySelectorAll('.split-toc .title a').forEach(consider);
    toc.querySelectorAll('tr a').forEach(consider);
    return found;
  };

  const buildUtilityNav = hrefs => {
    toc.querySelector('.site-utility-nav')?.remove();
    const nav = document.createElement('nav');
    nav.className = 'site-utility-nav';
    nav.setAttribute('aria-label', 'Reader guides');
    for (const link of utilityLinks) {
      const href = hrefs.get(link.slug);
      if (!href) continue;
      const item = document.createElement('a');
      item.className = 'site-utility-link';
      item.href = href;
      item.textContent = link.label;
      nav.appendChild(item);
    }
    const container = toc.querySelector('.first') || toc;
    const beforeNode = container.querySelector('.split-tocs');
    if (beforeNode) {
      container.insertBefore(nav, beforeNode);
    } else {
      container.appendChild(nav);
    }
  };

  const pruneUtilityEntries = () => {
    toc.querySelectorAll('.split-toc:not(.book)').forEach(block => {
      block.remove();
    });
    toc.querySelectorAll('.split-toc').forEach(block => {
      const titleLink = block.querySelector('.title a');
      const href = titleLink?.getAttribute('href') || '';
      if (utilityLinks.some(link => matchesUtility(href, link.slug))) {
        block.remove();
      }
    });
    toc.querySelectorAll('tr').forEach(row => {
      const href = row.querySelector('a')?.getAttribute('href') || '';
      if (utilityLinks.some(link => matchesUtility(href, link.slug))) {
        row.remove();
      }
    });
  };

  // Collect the hrefs before pruning removes the entries they come from.
  buildUtilityNav(findUtilityHrefs());
  pruneUtilityEntries();

  /* Verso emits its automatic sub-page list even when configured to show no entries, leaving an
     empty `<ol class="section-toc">` — and on the landing page a wrapping `<section>` whose only
     other child is a "Contents" heading. Both are removed outright. CSS alone could not do it:
     hiding the `<ol>` leaves the heading, and selecting its parent needs `:has`, which does not
     reliably match here. */
  for (const list of document.querySelectorAll('ol.section-toc')) {
    if (list.querySelector('li')) continue;
    const parent = list.parentElement;
    const siblings = parent ? Array.from(parent.children) : [];
    const isHeadingWrapper =
      parent && parent.tagName === 'SECTION' &&
      siblings.length === 2 && siblings[0].tagName === 'H2' && siblings[1] === list;
    if (isHeadingWrapper) parent.remove();
    else list.remove();
  }

  /* Start the table of contents expanded. Verso renders it collapsed — its disclosure is an
     unchecked checkbox that CSS keys off — which makes sense for a book you read front to back,
     but this site exists to be browsed, and the chapter list is the main way in. A reader who
     collapses it gets that remembered. */
  const tocOpenKey = 'lean-exposition:toc-open';
  for (const box of toc.querySelectorAll('.split-toc .toggle-split-toc input[type="checkbox"]')) {
    let open = true;
    try {
      const stored = window.localStorage.getItem(tocOpenKey);
      if (stored !== null) open = stored === 'true';
    } catch (_err) {
    }
    box.checked = open;
    box.addEventListener('change', () => {
      try {
        window.localStorage.setItem(tocOpenKey, String(box.checked));
      } catch (_err) {
      }
    });
  }

  const container = toc.querySelector('.first') || toc;
  const beforeNode = container.querySelector('.split-tocs');

  const visibilityToggles = [
    { group: 'definitions', cssClass: 'hide-definitions', label: 'Definitions' },
    { group: 'lemmas', cssClass: 'hide-lemmas', label: 'Lemmas' },
    { group: 'theorems', cssClass: 'hide-theorems', label: 'Theorems' }
  ];

  const utilityNav = toc.querySelector('.site-utility-nav');

  for (const toggle of visibilityToggles) {
    const key = `lean-exposition:${toggle.cssClass}`;
    const button = document.createElement('button');
    button.type = 'button';
    button.className = 'site-utility-button';

    const applyHide = hide => {
      document.body.classList.toggle(toggle.cssClass, hide);
      button.textContent = hide ? `Show ${toggle.label}` : `Hide ${toggle.label}`;
      button.setAttribute('aria-pressed', hide ? 'true' : 'false');
    };

    let hide = false;
    try {
      hide = window.localStorage.getItem(key) === 'true';
    } catch (_err) {
      hide = false;
    }
    applyHide(hide);

    button.addEventListener('click', () => {
      hide = !document.body.classList.contains(toggle.cssClass);
      try {
        window.localStorage.setItem(key, String(hide));
      } catch (_err) {
      }
      applyHide(hide);
    });

    if (utilityNav) {
      utilityNav.appendChild(button);
    } else {
      container.insertBefore(button, beforeNode || null);
    }
  }

  /* Light/dark control. "Auto" follows the operating system; an explicit choice overrides it in
     both directions, which matters because a reader on a dark desktop may still want the light
     theme for a page they are going to print or screenshot. The stored value is applied before
     first paint by a small script in <head>, so there is no flash of the wrong theme. */
  const themeKey = 'lean-exposition:theme';
  const themeOrder = { auto: 'light', light: 'dark', dark: 'auto' };
  const themeLabel = { auto: 'Theme: auto', light: 'Theme: light', dark: 'Theme: dark' };

  const readTheme = () => {
    try {
      const stored = window.localStorage.getItem(themeKey);
      return stored === 'light' || stored === 'dark' ? stored : 'auto';
    } catch (_err) {
      return 'auto';
    }
  };

  const themeButton = document.createElement('button');
  themeButton.type = 'button';
  themeButton.className = 'site-utility-button site-theme-toggle';

  const applyTheme = mode => {
    if (mode === 'auto') document.documentElement.removeAttribute('data-theme');
    else document.documentElement.setAttribute('data-theme', mode);
    themeButton.textContent = themeLabel[mode];
    // Anything that paints its own colours (the dependency graph) re-reads them on this.
    document.dispatchEvent(new CustomEvent('exposition:themechange', { detail: { mode } }));
  };

  themeButton.addEventListener('click', () => {
    const next = themeOrder[readTheme()] || 'auto';
    try {
      if (next === 'auto') window.localStorage.removeItem(themeKey);
      else window.localStorage.setItem(themeKey, next);
    } catch (_err) {
    }
    applyTheme(next);
  });

  themeButton.textContent = themeLabel[readTheme()];
  if (utilityNav) {
    utilityNav.appendChild(themeButton);
  } else {
    container.insertBefore(themeButton, beforeNode || null);
  }
});
