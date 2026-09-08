/*
 * The statement, in parts: two views of one markup, and a tooltip per constant.
 *
 * Compact is the default and is what the HTML shows with no script at all: each object on one line
 * with the structure assumed on it after a "with", nothing explained inline. This file adds the two
 * things a static page cannot: the button that switches to the expanded view (one assumption per
 * line, a sentence about each), remembered per browser; and, on every binder whose head constant
 * the page knows something about, a hover showing that constant's signature, its whole docstring,
 * and a link to its page when the project declares it.
 *
 * The hovers are tippy tooltips when tippy is on the page — Verso loads it for its highlighted
 * code, and the anatomy sits directly under a highlighted signature — with the browser's own title
 * tooltip as the fallback. Docstrings are Markdown and are rendered with `marked` when Verso has
 * loaded it, exactly as Verso renders the docstrings in its own hovers; otherwise they show as text.
 *
 * The tooltip contents live once per head constant per page, in a hidden `.anatomy-tips` block, and
 * rows point at them by name: a class assumed on five objects ships its docstring once.
 *
 * Wiring is exposed as `RefereeAnatomy.init(scope)` and not only run at load, because a declaration
 * card is not always in the page when the page loads: clicking a graph node fetches that
 * declaration's card and drops it in below the picture, and an unwired card is one whose Expand
 * button is invisible and whose terms have no hovers. Every lookup is therefore scoped to what it
 * is given, which also stops one card's tips from being found from inside another.
 */
(function () {
  'use strict';
  const KEY = 'referee:anatomy-expanded';

  /* One choice for the whole page, injected cards included: the reader picked a way to read a
     statement, not a way to read one card. Kept in a variable rather than re-read per init so that
     a card added after a toggle matches what is on screen and not what is in storage. */
  let expanded = false;
  try { expanded = localStorage.getItem(KEY) === '1'; } catch (_) { /* private mode etc. */ }

  /* Every wired root and button, across however many times `init` has run. Pruned of anything no
     longer in the document, since a card replaced by the next node's card is gone for good. */
  const roots = [];
  const buttons = [];
  const prune = (arr) => {
    for (let i = arr.length - 1; i >= 0; i--) if (!arr[i].isConnected) arr.splice(i, 1);
    return arr;
  };

  const apply = () => {
    prune(roots).forEach(r => r.classList.toggle('anatomy--expanded', expanded));
    prune(buttons).forEach(b => {
      b.textContent = expanded ? 'Compact' : 'Expand';
      b.setAttribute('aria-pressed', expanded ? 'true' : 'false');
      b.title = expanded
        ? 'One line per object; hover a name for its docstring'
        : 'One line per assumption, with a sentence about each';
    });
  };

  function render(tip) {
    const box = document.createElement('div');
    box.className = 'anatomy-tipbox';
    const sig = tip.querySelector('.anatomy-tip-sig');
    if (sig) box.appendChild(sig.cloneNode(true));
    const doc = tip.querySelector('.anatomy-tip-doc');
    if (doc) {
      const rendered = document.createElement('div');
      rendered.className = 'anatomy-tip-doc';
      if (typeof marked !== 'undefined' && marked && typeof marked.parse === 'function') {
        rendered.innerHTML = marked.parse(doc.textContent);
      } else {
        doc.textContent.split(/\n\s*\n/).forEach(para => {
          const p = document.createElement('p');
          p.textContent = para.trim();
          rendered.appendChild(p);
        });
      }
      box.appendChild(rendered);
    }
    const link = tip.querySelector('.anatomy-tip-link');
    if (link) box.appendChild(link.cloneNode(true));
    return box;
  }

  /* Wires every anatomy block inside `scope`, which is the document at load and one freshly
     injected card thereafter. */
  function init(scope) {
    if (!scope) return;
    const newRoots = Array.from(scope.querySelectorAll('.anatomy'));
    if (!newRoots.length) return;
    roots.push(...newRoots);

    /* ------------------------------------------------------------ the two views --- */
    Array.from(scope.querySelectorAll('.anatomy-toggle')).forEach(b => {
      buttons.push(b);
      b.hidden = false;
      b.addEventListener('click', () => {
        expanded = !expanded;
        try { localStorage.setItem(KEY, expanded ? '1' : '0'); } catch (_) { /* fine */ }
        apply();
      });
    });
    apply();

    /* ---------------------------------------------------------------- tooltips --- */
    const tips = {};
    scope.querySelectorAll('.anatomy-tips > [data-tip-for]').forEach(t => {
      tips[t.dataset.tipFor] = t;
    });
    const terms = Array.from(scope.querySelectorAll('.anatomy-term[data-tip]'))
      .filter(t => tips[t.dataset.tip]);
    if (!terms.length) return;

    if (typeof tippy === 'function') {
      tippy(terms, {
        content: (ref) => render(tips[ref.dataset.tip]),
        allowHTML: true,
        appendTo: () => document.body,
        interactive: true,
        delay: [120, null],
        maxWidth: 560,
        placement: 'bottom-start',
        theme: 'anatomy',
      });
    } else {
      terms.forEach(t => { t.title = tips[t.dataset.tip].textContent.trim(); });
    }
  }

  window.RefereeAnatomy = { init };
  document.addEventListener('DOMContentLoaded', () => init(document));
})();
