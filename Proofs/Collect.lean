module

public import Referee.Collect

@[expose] public section

/-!
# Proofs about `Referee.Collect`'s on-disk format

`intern` and `resolve` are the encoder and decoder for `data.json`, the file every phase after
`collect` reads. A bug here is silent and total, and the docstrings state three theorems about them:
that `resolve` inverts `intern`, that every reference inside table entry `i` points below `i`, and
that the `usesInternKey` guard makes decoding unambiguous.

## `partial` is gone

The three walks — `usesInternKey`, `internAux`, `resolveAgainst` — used to be `partial`, and a
`partial def` in Lean is an opaque constant with **no equations**: not even
`resolveAgainst resolved (.str s) = .str s` was provable. They are now total.

What stood in the way was never termination. Every recursive call is on a strict subterm; Lean could
not *see* it. `Json` is a nested inductive whose object case holds a `Std.TreeMap.Raw`, and folding
over that tree hands the termination checker a value with no evidence tying it to the tree. `Array`
and `List` ship `sizeOf_lt_of_mem`; the tree containers do not. That one gap is why every recursion
over `Json` in Lean core — `beq'`, `hash'`, `render`, `compress` — is still `partial`.

`Referee.sizeOf_lt_of_mem_toListModel` and `Referee.objPairs_sizeOf` close it in about twenty lines,
and the walks are ordinary well-founded definitions on `sizeOf j`.

Two things came free with that, both previously impossible:

* the **equations** in the section below — the whole point, since a proof needs them;
* `resolveAgainst.induct` and `usesInternKey.induct`, functional induction principles **over
  `Json`**. The `induction` tactic still refuses `Json` outright ("does not support the type
  `Lean.Json` because it is a nested inductive type"), so this is the only induction over JSON
  available at all.

## Why the round trip is *still* out of reach

Three obstacles remain, and the second is the interesting one.

**1. `internAux.induct` does not exist.** Lean declines to derive it — "Cannot derive functional
induction principle (please report this issue)". The encoder can be reasoned about only by hand.

**2. Structural equality is the wrong specification.** `resolveAgainst` rebuilds every object it
passes through, via `Json.mkObj`, which is `Json.obj ∘ Std.TreeMap.Raw.ofList`. So a round trip
returns a *rebuilt* tree, and `ofList (m.toList) = m` is not available: `Json.obj` holds a `Raw` map
carrying no well-formedness invariant, and core proves no `ofList`/`toList` inverse even for the
well-formed case — two differently shaped balanced trees can hold the same entries. The repo's own
tests have this right without saying so: `internRoundTrips` compares `.compress` output, not values.
Stating the theorem properly means defining equality of JSON *contents* and proving the round trip
up to that, rather than up to `=`.

**3. `LawfulBEq Json` cannot be synthesized**, because core's `beq'` is `partial`. `internAux`'s
reverse index is a `Std.HashMap Json Nat`, so any argument about it needs that as a hypothesis:
a round-trip theorem would have to open "given that `Json`'s `BEq` is lawful, …", which this
toolchain cannot check. (`internAux` also sizes subtrees with the `partial` `Json.compress`, but
that one is harmless — the threshold only decides which subtrees get tabled, and the round trip
holds whichever way it goes.)

## What is proved here

The **forward-pass discipline** of `resolve`, stated for an arbitrary resolver so that
`resolveAgainst` being opaque does not matter:

> `(resolveTable f table)[i]!` is `f` applied to the table built from **exactly the entries below
> `i`**, and the resolved table has the same size as the table.

That is one half of the docstring's soundness argument for the single forward pass — "entries below
`i` are already resolved when it is reached" — and it holds no matter what the resolver does. The
other half, that entry `i` only ever *references* entries below `i`, is `internAux`'s invariant, and
that is the part still out of reach.
-/

open Lean

namespace Referee.Proofs.Collect

open Referee

/-! ## The forward pass

`resolve` resolves the table into `resolved` with a single left fold, each entry against the
entries already resolved before it, and then resolves the document against the finished table. The
results below are about that fold, with the resolver left abstract. -/

/-- The table `resolve` builds, for an arbitrary resolver `f`. -/
def resolveTable (f : Array Json → Json → Json) (table : Array Json) : Array Json :=
  table.foldl (fun acc entry => acc.push (f acc entry)) #[]

/-- `resolve` is exactly `resolveAgainst` against `resolveTable resolveAgainst`. -/
theorem resolve_eq (table : Array Json) (j : Json) :
    resolve table j = resolveAgainst (resolveTable resolveAgainst table) j := rfl

variable {f : Array Json → Json → Json}

private theorem getElem!_push_lt (acc : Array Json) (x : Json) (i : Nat) (h : i < acc.size) :
    (acc.push x)[i]! = acc[i]! := by
  have h2 : i < (acc.push x).size := by simp; omega
  rw [getElem!_pos (acc.push x) i h2, getElem!_pos acc i h, Array.getElem_push_lt]

private theorem getElem!_push_at (acc : Array Json) (x : Json) (i : Nat) (h : i = acc.size) :
    (acc.push x)[i]! = x := by
  subst h
  rw [getElem!_pos (acc.push x) acc.size (by simp)]
  simp

private def rt (f : Array Json → Json → Json) (l : List Json) : Array Json :=
  l.foldl (fun acc entry => acc.push (f acc entry)) #[]

private theorem rt_size (l : List Json) : (rt f l).size = l.length := by
  have aux : ∀ (l : List Json) (acc : Array Json),
      (l.foldl (fun a e => a.push (f a e)) acc).size = acc.size + l.length := by
    intro l
    induction l with
    | nil => simp
    | cons e es ih => intro acc; simp [ih]; omega
  simpa [rt] using aux l #[]

private theorem rt_append (l : List Json) (e : Json) :
    rt f (l ++ [e]) = (rt f l).push (f (rt f l) e) := by
  simp [rt, List.foldl_append]

private theorem foldl_getElem (l : List Json) (acc : Array Json) (i : Nat) (h : i < acc.size) :
    (l.foldl (fun a e => a.push (f a e)) acc)[i]! = acc[i]! := by
  induction l generalizing acc with
  | nil => simp
  | cons e es ih =>
    rw [List.foldl_cons, ih _ (by simp; omega), getElem!_push_lt acc _ i h]

/-- **Entry `i` is resolved against exactly the entries below it.** -/
private theorem rt_getElem (l : List Json) (i : Nat) (h : i < l.length) :
    (rt f l)[i]! = f (rt f (l.take i)) l[i]! := by
  have hsplit : l = l.take (i + 1) ++ l.drop (i + 1) := (List.take_append_drop _ _).symm
  have hsize : (rt f (l.take (i + 1))).size = i + 1 := by
    rw [rt_size]; simp; omega
  have hfold : rt f l = (l.drop (i + 1)).foldl (fun a e => a.push (f a e)) (rt f (l.take (i + 1))) := by
    unfold rt
    rw [← List.foldl_append, ← hsplit]
  rw [hfold, foldl_getElem _ _ i (by omega)]
  have htake : l.take (i + 1) = l.take i ++ [l[i]!] := by
    rw [List.take_add_one]
    congr 1
    rw [List.getElem?_eq_getElem h]
    simp [getElem!_pos l i h]
  rw [htake, rt_append]
  exact getElem!_push_at _ _ i (by rw [rt_size]; simp; omega)

/-- The resolved table has one entry per table entry. -/
theorem resolveTable_size (table : Array Json) : (resolveTable f table).size = table.size := by
  rw [show resolveTable f table = rt f table.toList from by simp [resolveTable, rt, Array.foldl_toList]]
  simp [rt_size]

/-- **Entry `i` is resolved against exactly the entries below it.**

The half of `resolve`'s soundness argument that does not depend on what the resolver does: by the
time the forward pass reaches entry `i`, the table it hands the resolver is the one built from
entries `0` to `i-1`, and no others. Whether that is *enough* — whether entry `i` only ever
references those — is `internAux`'s invariant, and out of reach while it stays `partial`. -/
theorem resolveTable_getElem (table : Array Json) (i : Nat) (h : i < table.size) :
    (resolveTable f table)[i]! = f (resolveTable f (table.take i)) table[i]! := by
  have hrt : ∀ t : Array Json, resolveTable f t = rt f t.toList := by
    intro t; simp [resolveTable, rt, Array.foldl_toList]
  rw [hrt, hrt, show (table.take i).toList = table.toList.take i from by simp]
  rw [rt_getElem table.toList i (by simpa using h)]
  congr 1
  rw [getElem!_pos table i h, getElem!_pos table.toList i (by simpa using h)]
  simp

/-! ## Equations, now that the walks are total

None of this section was expressible before. `usesInternKey`, `internAux` and `resolveAgainst` were
`partial`, and a `partial def` has no equations at all — `resolveAgainst r (.str s) = .str s` was
not provable. Making them total (see the note above `usesInternKey` in `Referee/Collect.lean`) also
made Lean generate `resolveAgainst.induct` and `usesInternKey.induct`, which are induction
principles **over `Json`** — something the `induction` tactic still refuses to produce, because
`Json` is a nested inductive. -/

/-- A leaf resolves to itself. The one-line fact that was previously out of reach. -/
theorem resolveAgainst_str (resolved : Array Json) (s : String) :
    resolveAgainst resolved (.str s) = .str s := by
  simp [resolveAgainst]

theorem resolveAgainst_num (resolved : Array Json) (n : JsonNumber) :
    resolveAgainst resolved (.num n) = .num n := by
  simp [resolveAgainst]

theorem resolveAgainst_null (resolved : Array Json) : resolveAgainst resolved .null = .null := by
  simp [resolveAgainst]

theorem resolveAgainst_bool (resolved : Array Json) (b : Bool) :
    resolveAgainst resolved (.bool b) = .bool b := by
  simp [resolveAgainst]

/-- Resolution distributes over an array's elements. -/
theorem resolveAgainst_arr (resolved : Array Json) (elems : Array Json) :
    resolveAgainst resolved (.arr elems)
      = .arr (elems.attach.map fun e => resolveAgainst resolved e.1) := by
  simp [resolveAgainst]

/-- **With an empty table, nothing is ever substituted.**

Every reference is guarded by `i < resolved.size`, so against an empty table the guard always fails
and an object that looks like a reference is rebuilt as ordinary data rather than resolved. This is
the docstring's claim that an out-of-range index is left alone rather than raising, which is what
lets a document encoded with an empty table decode unchanged. -/
theorem resolveAgainst_empty_obj (fields : Std.TreeMap.Raw String Json) :
    resolveAgainst #[] (.obj fields)
      = Json.mkObj (fields.toList.attach.foldl (init := (#[] : Array (String × Json)))
          (fun acc p => acc.push (p.1.1, resolveAgainst #[] p.1.2))).toList := by
  rw [resolveAgainst]
  simp [guard]
  split
  · rename_i h
    cases hg : fields.get? internKey <;> simp [hg] at h
    rename_i v; cases v <;> simp at h
    rw [show (failure : Option Unit) = none from rfl] at h
    simp at h
  · rfl

/-! ## The unambiguity guard -/

/-- A document that already uses the reserved key is returned untouched, with an empty table.

`intern` is not `partial`, so this much is provable: the guard really does decline rather than
produce something `resolve` would silently misread. What cannot be proved is the other half — that
when the guard *passes*, the encoding is unambiguous — because that is a statement about
`usesInternKey`'s recursion. -/
theorem intern_of_usesInternKey (j : Json) (h : usesInternKey j) : intern j = (#[], j) := by
  simp [intern, h]

/-- And so encoding such a document leaves the payload alone. -/
theorem intern_snd_of_usesInternKey (j : Json) (h : usesInternKey j) : (intern j).2 = j := by
  rw [intern_of_usesInternKey j h]

/-! ## Regressions, pinned

`b099a84` fixed a Verso duplicate-tag failure. Verso keys every part by its `tag`, and two parts
claiming the same one leaves one without an external ID — reported as `No external ID for <title>`,
naming one of the two and giving no hint that a collision is what happened.

The three kinds of page can genuinely want the same tag, because a project may name a file after the
definition it introduces: with `--root Mathlib.Logic`, `Mathlib/Logic/Denumerable.lean` is its own
chapter *and* its own module *and* defines `Denumerable`. The fix prefixes each tag by its kind,
making the collision impossible rather than unlikely.

"Impossible" is a claim about four functions, and it is the claim below — the four tag families are
pairwise disjoint, whatever names they are given. Within a kind the names are already unique, so
together that is the whole argument. -/

private theorem toString_str (s : String) : toString s = s := rfl

theorem chapterTag_ne_moduleTag (k : String) (m : Name) : chapterTagOf k ≠ moduleTagOf m := by
  intro h
  have := congrArg String.toList h
  simp [chapterTagOf, moduleTagOf, String.toList_append, toString_str] at this

theorem chapterTag_ne_declTag (k : String) (n : Name) : chapterTagOf k ≠ declTagOf n := by
  intro h
  have := congrArg String.toList h
  simp [chapterTagOf, declTagOf, String.toList_append, toString_str] at this

theorem chapterTag_ne_minimalTag (k : String) (n : Name) : chapterTagOf k ≠ minimalFileTagOf n := by
  intro h
  have := congrArg String.toList h
  simp [chapterTagOf, minimalFileTagOf, String.toList_append, toString_str] at this

theorem moduleTag_ne_declTag (m : Name) (n : Name) : moduleTagOf m ≠ declTagOf n := by
  intro h
  have := congrArg String.toList h
  simp [moduleTagOf, declTagOf, String.toList_append, toString_str] at this

theorem moduleTag_ne_minimalTag (m : Name) (n : Name) : moduleTagOf m ≠ minimalFileTagOf n := by
  intro h
  have := congrArg String.toList h
  simp [moduleTagOf, minimalFileTagOf, String.toList_append, toString_str] at this

theorem declTag_ne_minimalTag (m : Name) (n : Name) : declTagOf m ≠ minimalFileTagOf n := by
  intro h
  have := congrArg String.toList h
  simp [declTagOf, minimalFileTagOf, String.toList_append, toString_str] at this


end Referee.Proofs.Collect
