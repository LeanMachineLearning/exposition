# Semantic hashes

[`semantic_hash`](https://github.com/mathlib-initiative/semantic_hash) computes rename-invariant
structural hashes of every constant in a Lean environment. Referee reads its output and stores two
hashes per declaration, which become the key revision comparisons and audit fingerprints are made
on. It is optional: without it everything works as it did, on text.

It is a **separate tool, not a dependency of this one**. It enforces a toolchain match against the
project it reads, exactly as Referee does, and taking it as a Lake dependency would mean a third
toolchain that also has to line up. A file on disk has no such constraint, and it keeps the phase
boundary the pipeline is built on: what needs an environment produces data, and what follows is a
pure function of it.

```bash
git clone https://github.com/mathlib-initiative/semantic_hash
cd semantic_hash
echo "$(tr -d '[:space:]' < /path/to/target-repo/lean-toolchain)" > lean-toolchain
lake build semantic_hash

cd /path/to/target-repo
/path/to/semantic_hash/.lake/build/bin/semantic_hash export \
  --dir . --imports MyLibrary --output hashes.jsonl

lake env "$REFEREE" collect --root MyLibrary --hashes hashes.jsonl --data data.json
```

`--imports` takes the same root modules `collect` exposes. The tool hashes every constant reachable
from them — for a Mathlib-based project that is the whole upstream cone, which is what makes the
hashes deep enough to be worth having; `collect` keeps only the exposed declarations' entries. It
pins its own `lean-toolchain`, so overwrite it with the target project's: as of this writing it
builds unpatched on `v4.33.0-rc1` against a `v4.30.0` pin, and it has no dependencies beyond Lean
and `Std`, so a version bump is cheap when it is needed at all.

Cost is negligible next to `collect`: 237k constants hashed in about 7 seconds on 32 cores.

Both revisions have to carry hashes for a comparison to use them — collecting only the new one
leaves the diff on the text path, and says so.
