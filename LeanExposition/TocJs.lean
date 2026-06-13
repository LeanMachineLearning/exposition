namespace LeanExposition

/-- JS for the TOC sidebar. -/
def tocJs : String :=
  "
document.addEventListener('DOMContentLoaded', () => {
  const toc = document.getElementById('toc');
  if (!toc) return;
  const key = 'lean-exposition:toc-collapsed';
  const utilityLinks = [
    { slug: 'context', label: 'Overview', href: 'context/' },
    { slug: 'graph', label: 'Graph', href: 'graph/' }
  ];
  const button = document.createElement('button');
  button.type = 'button';
  button.className = 'site-toc-toggle';

  const isDesktop = () => window.matchMedia('(min-width: 701px)').matches;

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

  const applyState = collapsed => {
    document.body.classList.toggle('site-toc-collapsed', collapsed);
    button.textContent = collapsed ? 'Show Contents' : 'Hide Contents';
    button.setAttribute('aria-expanded', collapsed ? 'false' : 'true');
  };

  let collapsed = false;
  try {
    collapsed = window.localStorage.getItem(key) === 'true';
  } catch (_err) {
    collapsed = false;
  }
  buildUtilityNav();
  pruneUtilityEntries();
  applyState(collapsed);

  button.addEventListener('click', () => {
    collapsed = !document.body.classList.contains('site-toc-collapsed');
    try {
      window.localStorage.setItem(key, String(collapsed));
    } catch (_err) {
    }
    applyState(collapsed);
  });

  const container = toc.querySelector('.first') || toc;
  const beforeNode = container.querySelector('.split-tocs');
  if (beforeNode) {
    container.insertBefore(button, beforeNode);
  } else {
    container.appendChild(button);
  }

  const hideTheoremsKey = 'lean-exposition:hide-theorems';
  const hideTheoremsButton = document.createElement('button');
  hideTheoremsButton.type = 'button';
  hideTheoremsButton.className = 'site-utility-button';

  const applyHideTheorems = hide => {
    document.body.classList.toggle('hide-theorems', hide);
    hideTheoremsButton.textContent = hide ? 'Show Theorems' : 'Hide Theorems';
    hideTheoremsButton.setAttribute('aria-pressed', hide ? 'true' : 'false');
  };

  let hideTheorems = false;
  try {
    hideTheorems = window.localStorage.getItem(hideTheoremsKey) === 'true';
  } catch (_err) {
    hideTheorems = false;
  }
  applyHideTheorems(hideTheorems);

  hideTheoremsButton.addEventListener('click', () => {
    hideTheorems = !document.body.classList.contains('hide-theorems');
    try {
      window.localStorage.setItem(hideTheoremsKey, String(hideTheorems));
    } catch (_err) {
    }
    applyHideTheorems(hideTheorems);
  });

  const utilityNav = toc.querySelector('.site-utility-nav');
  if (utilityNav) {
    utilityNav.appendChild(hideTheoremsButton);
  } else {
    container.insertBefore(hideTheoremsButton, beforeNode || null);
  }
});
"

end LeanExposition
