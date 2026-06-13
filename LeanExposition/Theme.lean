namespace LeanExposition

def customCss : String := "
:root {
  --verso-structure-color: #8a3a3a;
  --verso-toc-background-color: #fdf1f1;
  --verso-selected-color: #f6d6d6;
  --verso-text-font-family: 'Iowan Old Style', 'Palatino Linotype', 'Book Antiqua', serif;
  --verso-structure-font-family: 'Avenir Next Condensed', 'Gill Sans', sans-serif;
  --verso-code-font-family: 'Iosevka Term', 'JetBrains Mono', monospace;
  --site-ink: #3a2424;
  --site-muted: #8a6e6e;
  --site-warm: #fef9f9;
  --site-card: #fffdfd;
  --site-accent: #d65d5d;
  --site-border: #f0d4d4;
  --site-content-min-width: 52rem;
  --site-collapsed-sidebar-width: 9rem;
}

body {
  background:
    radial-gradient(circle at top left, rgba(214, 93, 93, 0.10), transparent 28%),
    linear-gradient(180deg, #fffafa 0%, #fdf1f1 100%);
  color: var(--site-ink);
}

.decl-section {
  scroll-margin-top: 5rem;
}

.decl-heading {
  align-items: center;
  display: flex;
  gap: 0.5rem;
  margin: 1.8rem 0 0.5rem;
}

.decl-heading code {
  font-size: 1.05rem;
}

.decl-permalink {
  color: var(--site-muted);
  font-size: 0.95rem;
  text-decoration: none;
}

.decl-permalink:hover {
  color: var(--site-accent);
}

.decl-card {
  background: var(--site-card);
  border: 1px solid var(--site-border);
  border-left: 6px solid var(--verso-structure-color);
  border-radius: 14px;
  margin: 1.2rem 0 1.8rem;
  padding: 1rem 1.2rem 1.1rem;
  box-shadow: 0 10px 28px rgba(120, 50, 50, 0.06);
}

.decl-card-header {
  align-items: flex-start;
  display: flex;
  gap: 0.8rem;
  justify-content: space-between;
  margin-bottom: 0.8rem;
}

.decl-card-title {
  min-width: 0;
}

.decl-card-label {
  color: var(--site-muted);
  font-family: var(--verso-structure-font-family);
  font-size: 0.92rem;
  font-weight: 700;
  letter-spacing: 0.08em;
  text-transform: uppercase;
}

.decl-card-name {
  display: block;
  font-family: var(--verso-code-font-family);
  font-size: 0.95rem;
  margin-top: 0.1rem;
}

.decl-card-tags {
  display: flex;
  flex-wrap: wrap;
  gap: 0.45rem;
  justify-content: flex-end;
  margin-top: 0;
}

.decl-card-tag {
  border: 1px solid var(--site-border);
  border-radius: 999px;
  font-family: var(--verso-structure-font-family);
  font-size: 0.82rem;
  padding: 0.2rem 0.55rem;
}

.decl-card-tag.sorry {
  background: #fff2ec;
  border-color: #e8b294;
  color: #8b3517;
}

.decl-card-tagbar {
  align-items: flex-start;
  display: flex;
  flex: 0 0 auto;
}

.decl-card-action {
  background: var(--site-ink);
  border-radius: 999px;
  color: white !important;
  font-family: var(--verso-structure-font-family);
  font-size: 0.82rem;
  padding: 0.35rem 0.75rem;
  text-decoration: none !important;
}

.decl-card details {
  border-top: 1px solid rgba(240, 212, 212, 0.9);
  margin-top: 0.9rem;
  padding-top: 0.75rem;
}

.decl-card summary {
  color: var(--site-accent);
  cursor: pointer;
  font-family: var(--verso-structure-font-family);
  font-weight: 700;
}

.decl-card details ul {
  margin: 0.65rem 0 0;
  padding-left: 1.25rem;
}

.decl-card details li + li {
  margin-top: 0.25rem;
}

.decl-card pre,
.decl-card code.hl.lean.block {
  background: #fdf3f3 !important;
  border: 1px solid #f0d4d4;
  border-radius: 10px;
  box-shadow: inset 0 1px 0 rgba(255, 255, 255, 0.7);
}

.decl-card pre {
  overflow-x: auto;
  padding: 0.85rem 1rem;
}

.header-logo-wrapper,
.with-toc #toc,
.with-toc > main {
  transition:
    flex-basis var(--verso-toc-transition-time) ease,
    width var(--verso-toc-transition-time) ease,
    padding-left var(--verso-toc-transition-time) ease,
    transform var(--verso-toc-transition-time) ease;
}

.site-toc-toggle {
  display: none;
}

.site-utility-nav {
  align-items: flex-start;
  border-bottom: 1px solid rgba(240, 212, 212, 0.9);
  display: flex;
  flex-direction: column;
  gap: 0.4rem;
  margin: 0.2rem 0 0.8rem;
  padding: 0 1rem 0.85rem;
}

.site-utility-link {
  color: var(--site-ink);
  font-family: var(--verso-structure-font-family);
  font-size: 0.82rem;
  font-weight: 700;
  letter-spacing: 0.03em;
  text-decoration: none;
}

.site-utility-link:hover {
  color: var(--site-accent);
}

.site-utility-button {
  background: var(--site-card);
  border: 1px solid var(--site-border);
  border-radius: 999px;
  color: var(--site-ink);
  cursor: pointer;
  font-family: var(--verso-structure-font-family);
  font-size: 0.82rem;
  font-weight: 700;
  letter-spacing: 0.03em;
  padding: 0.3rem 0.75rem;
}

.site-utility-button:hover {
  border-color: var(--site-accent);
  color: var(--site-accent);
}

body.hide-theorems [data-decl-kind=\"Theorem\"] {
  display: none;
}

@media screen and (min-width: 701px) {
  .site-toc-toggle {
    background: var(--site-card);
    border: 1px solid var(--site-border);
    border-radius: 999px;
    color: var(--site-ink);
    cursor: pointer;
    display: inline-flex;
    font-family: var(--verso-structure-font-family);
    font-size: 0.85rem;
    margin: 0 1rem 0.85rem;
    padding: 0.45rem 0.8rem;
    width: fit-content;
  }

  body.site-toc-collapsed .with-toc #toc {
    width: var(--site-collapsed-sidebar-width);
  }

  body.site-toc-collapsed .with-toc > main {
    padding-left: var(--site-collapsed-sidebar-width);
  }

  body.site-toc-collapsed .header-logo-wrapper {
    flex-basis: var(--site-collapsed-sidebar-width);
    padding-left: 0;
    width: var(--site-collapsed-sidebar-width);
  }

  body.site-toc-collapsed #toc .split-tocs,
  body.site-toc-collapsed #toc .last {
    display: none;
  }
}

@media screen and (min-width: 900px) {
  .content-wrapper {
    box-sizing: border-box;
    margin: 0;
    max-width: none;
    width: 100%;
  }

  .content-wrapper > section,
  main section {
    box-sizing: border-box;
    max-width: none;
    min-width: min(var(--site-content-min-width), calc(100vw - var(--verso-toc-width) - 4rem));
    width: 100%;
  }
}

#graph-root {
  background: var(--site-card);
  border: 1px solid var(--site-border);
  border-radius: 14px;
  min-height: 720px;
  padding: 1rem;
}

.graph-toolbar {
  align-items: center;
  display: flex;
  flex-wrap: wrap;
  gap: 0.8rem;
  margin-bottom: 0.8rem;
}

.graph-toolbar input,
.graph-toolbar select,
.graph-toolbar button {
  border: 1px solid var(--site-border);
  border-radius: 999px;
  padding: 0.55rem 0.9rem;
}

.graph-toolbar input,
.graph-toolbar select {
  font-family: var(--verso-text-font-family);
}

.graph-toolbar input {
  flex: 1 1 20rem;
}

.graph-toolbar button {
  background: var(--site-card);
  color: var(--site-ink);
  cursor: pointer;
  font-family: var(--verso-structure-font-family);
}

.graph-legend {
  color: var(--site-muted);
  font-size: 0.92rem;
  margin: 0.2rem 0 0.9rem;
}

.graph-layout {
  display: grid;
  gap: 1rem;
  grid-template-columns: minmax(0, 1fr) 18rem;
}

.graph-panel {
  background: rgba(255, 253, 253, 0.92);
  border: 1px solid var(--site-border);
  border-radius: 14px;
  padding: 0.9rem 1rem;
}

.graph-panel h2 {
  margin-top: 0;
}

.graph-hint {
  color: var(--site-muted);
  font-size: 0.92rem;
  margin-bottom: 0.8rem;
}

#graph-svg {
  cursor: grab;
}

.graph-panel code {
  font-size: 0.9rem;
}

.graph-neighbor-list {
  margin: 0.7rem 0 0;
  padding-left: 1.1rem;
}

.graph-neighbor-list li {
  margin-bottom: 0.35rem;
}

@media (max-width: 900px) {
  .graph-layout {
    grid-template-columns: 1fr;
  }
}
"

end LeanExposition
