namespace LeanExposition

/-- JS for the TOC sidebar. -/
def tocJs : String :=
  "
document.addEventListener('DOMContentLoaded', () => {
  const toc = document.getElementById('toc');
  if (!toc) return;
  const utilityLinks = [
    { slug: 'context', label: 'Overview', href: 'context/' },
    { slug: 'graph', label: 'Graph', href: 'graph/' }
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

  const buildUtilityNav = () => {
    toc.querySelector('.site-utility-nav')?.remove();
    const nav = document.createElement('nav');
    nav.className = 'site-utility-nav';
    nav.setAttribute('aria-label', 'Reader guides');
    for (const link of utilityLinks) {
      const item = document.createElement('a');
      item.className = 'site-utility-link';
      item.href = link.href;
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

  buildUtilityNav();
  pruneUtilityEntries();

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
});
"

end LeanExposition
