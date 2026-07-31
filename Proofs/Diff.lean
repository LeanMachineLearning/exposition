module

public import Referee.Diff

@[expose] public section

/-!
# Proofs about `Referee.Diff`

The revision diff is a pure function of two `collect` outputs, and `Test.Diff` checks it on 64
examples. This module proves the claims those examples sample — the ones the module's own docstrings
already state in prose, and which a reader of a Changes page is being asked to take on faith.

Three groups.

## The classification invariants

`ChangeKind` carries four independent predicates — `needsReaudit`, `movedMeaning`, `attributable`,
`slug` — written as four separate `match`es that nothing forces to agree. The relations between them
*are* the design, and they are argued at length in `Referee.Diff`'s docstrings: that anything whose
meaning moved must be re-read, and that `upstream` is the one kind deliberately in both
`movedMeaning` and `attributable`. Each is a case split away, and having them here means a later
edit to one `match` cannot silently break the others.

## The toolchain-churn gate

`looksLikeToolchainChurn` is documented as unable to fire on a fully hashed comparison. That is a
safety claim — the heuristic exists to say "my measure has stopped meaning anything", and running it
where the measure is sound would warn about a risk the comparison no longer takes. It is one line to
prove and it was previously prose.

## The comparison keys are a canonical form

This is the substantive one. Every claim the Changes page makes rests on `statementKey`/`bodyKey`
being a genuine quotient of the text by whitespace: the module docstring's promise that "a line break
moving is not a change a referee needs to hear about". What is proved here:

* `statementTokens_clean` — every token is non-empty and contains no whitespace. The invariant the
  tokenizer is *for*, and the hypothesis the round trip needs;
* `statementTokens_intercalate` — joining clean tokens with single spaces and re-tokenizing returns
  exactly those tokens. The round trip, and the only real work in the file;
* `normalizeSpace_idem` — `normalizeSpace` is idempotent, i.e. its output is a canonical form and not
  merely a smaller string;
* `normalizeSpace_eq_iff` — two strings share a key exactly when they tokenize alike. Read
  contrapositively, this is the guarantee that matters: a difference the tokenizer cannot see is a
  difference the diff will never report, and *every* difference it can see is reported.

The tokenizer is a `String.foldl`, so the proofs bridge to `List Char` through
`String.foldl_eq_foldl_toList` and work there.
-/

namespace Referee.Proofs.Diff

open Referee

/-! ## The classification invariants -/

/-- Anything whose meaning moved has to be looked at again.

`movedMeaning` decides whether a declaration can be *named* as the cause of an indirect
invalidation, `needsReaudit` decides whether the reader has work to do. Nothing in the two `match`es
ties them together; this does. -/
theorem movedMeaning_needsReaudit (k : ChangeKind) : k.movedMeaning → k.needsReaudit := by
  cases k <;> decide

/-- `upstream` is the *only* kind that is both attributable and a moved meaning.

This is the subtle point `Referee.Diff` argues twice: a declaration can be told by the hash that its
meaning moved, and then have the proximate cause found among the project's own declarations, which
is the strictly better answer and replaces it. Every other attributable kind is one whose meaning did
not move. -/
theorem attributable_movedMeaning (k : ChangeKind) :
    k.attributable → k.movedMeaning → k = .upstream := by
  cases k <;> simp [ChangeKind.attributable, ChangeKind.movedMeaning]

/-- Re-reading is required exactly outside the two kinds the page collapses. -/
theorem needsReaudit_iff (k : ChangeKind) :
    k.needsReaudit ↔ k ≠ .proofOnly ∧ k ≠ .unchanged := by
  cases k <;> simp [ChangeKind.needsReaudit]

/-- The slugs are distinct.

`slug` is a CSS hook *and* the Browse table's filter value, so two kinds sharing one would make them
indistinguishable in the interface while everything else in the tool kept them apart. -/
theorem slug_injective (k l : ChangeKind) : k.slug = l.slug → k = l := by
  cases k <;> cases l <;> simp [ChangeKind.slug]

/-- The reader-facing labels are distinct, for the same reason. -/
theorem label_injective (k l : ChangeKind) : k.label = l.label → k = l := by
  cases k <;> cases l <;> simp [ChangeKind.label]

/-- Pass one never produces `.indirect`.

Which is what makes the propagation pass its sole source, and so what makes `causes` non-empty
wherever the kind is `.indirect`. -/
theorem directKind_ne_indirect (old new : DeclInfo) : directKind old new ≠ .indirect := by
  unfold directKind
  repeat' split
  all_goals exact fun h => ChangeKind.noConfusion h

/-! ## The toolchain-churn gate -/

/-- With semantic hashes on both sides of every comparison, the churn heuristic cannot fire.

Stated in `looksLikeToolchainChurn`'s docstring as the reason for the `fullyHashed` guard: a
repretty-printed statement whose hash is unmoved is classified `unchanged` and never reaches the
page, so warning about the text path's failure mode would be warning about a risk the comparison no
longer takes. -/
theorem fullyHashed_no_churn (r : DiffReport) :
    r.fullyHashed → ¬ r.looksLikeToolchainChurn := by
  intro h
  simp [DiffReport.looksLikeToolchainChurn, h]

/-- A fully hashed report is one that used hashes. -/
theorem fullyHashed_usedHashes (r : DiffReport) : r.fullyHashed → r.usedHashes := by
  simp only [DiffReport.fullyHashed, DiffReport.usedHashes, Bool.and_eq_true, decide_eq_true_eq,
    beq_iff_eq]
  omega

/-! ## The comparison keys are a canonical form

`statementTokens` is a `String.foldl` carrying a pair: the tokens committed so far, and the token
being built. The two definitions below name that fold's step and its final flush so the invariants
can be stated about them. -/

/-- The tokenizer's fold step: whitespace commits the pending token (if any), anything else extends
it. -/
def tokenStep (st : Array String × String) (c : Char) : Array String × String :=
  if c.isWhitespace then (if st.2.isEmpty then (st.1, "") else (st.1.push st.2, ""))
  else (st.1, st.2.push c)

/-- The tokenizer's final flush: commit whatever token was still being built. -/
def tokenFlush (st : Array String × String) : Array String :=
  if st.2.isEmpty then st.1 else st.1.push st.2

/-- `statementTokens`, restated over the character list so the proofs below can induct on it. -/
theorem statementTokens_eq (s : String) :
    statementTokens s = tokenFlush (s.toList.foldl tokenStep (#[], "")) := by
  simp only [statementTokens, String.foldl_eq_foldl_toList]
  rfl

/-- What the tokenizer guarantees about each token it emits: non-empty, and containing no
whitespace. -/
def Clean (t : String) : Prop := t ≠ "" ∧ ∀ c ∈ t.toList, ¬ c.isWhitespace

/-- The fold's invariant: every committed token is `Clean`, and the pending token — which may
legitimately be empty — is at least whitespace-free. -/
private def WF (st : Array String × String) : Prop :=
  (∀ t ∈ st.1, Clean t) ∧ (∀ c ∈ st.2.toList, ¬ c.isWhitespace)

private theorem wf_init : WF (#[], "") := by
  constructor
  · intro t ht; simp at ht
  · intro c hc; simp at hc

private theorem wf_step (st : Array String × String) (c : Char) (h : WF st) :
    WF (tokenStep st c) := by
  obtain ⟨h1, h2⟩ := h
  unfold tokenStep
  split
  · split
    · exact ⟨h1, by intro c hc; simp at hc⟩
    · rename_i hne
      refine ⟨?_, by intro c hc; simp at hc⟩
      intro t ht
      rcases Array.mem_push.mp ht with h' | h'
      · exact h1 t h'
      · subst h'
        exact ⟨fun hc => hne (String.isEmpty_iff.mpr hc), h2⟩
  · rename_i hws
    refine ⟨h1, ?_⟩
    intro d hd
    rw [String.toList_push] at hd
    rcases List.mem_append.mp hd with h' | h'
    · exact h2 d h'
    · simp at h'; subst h'; exact hws

private theorem wf_foldl (cs : List Char) (st : Array String × String) (h : WF st) :
    WF (cs.foldl tokenStep st) := by
  induction cs generalizing st with
  | nil => exact h
  | cons c cs ih => exact ih _ (wf_step st c h)

/-- Every token is non-empty and whitespace-free.

The tokenizer's whole contract, and the hypothesis `statementTokens_intercalate` needs. -/
theorem statementTokens_clean (s : String) : ∀ t ∈ statementTokens s, Clean t := by
  rw [statementTokens_eq]
  have h := wf_foldl s.toList (#[], "") wf_init
  simp only [tokenFlush]
  split
  · exact h.1
  · rename_i hne
    intro t ht
    rcases Array.mem_push.mp ht with h' | h'
    · exact h.1 t h'
    · subst h'; exact ⟨fun hc => hne (String.isEmpty_iff.mpr hc), h.2⟩

/-- No token is empty. -/
theorem statementTokens_ne_empty (s : String) : ∀ t ∈ statementTokens s, t ≠ "" :=
  fun t ht => (statementTokens_clean s t ht).1

/-- No token contains whitespace, which is what makes a single space an unambiguous separator when
`normalizeSpace` joins them back up. -/
theorem statementTokens_no_whitespace (s : String) :
    ∀ t ∈ statementTokens s, ∀ c ∈ t.toList, ¬ c.isWhitespace :=
  fun t ht => (statementTokens_clean s t ht).2

/-- Folding a whitespace-free run just accumulates it into the pending token. -/
private theorem foldl_clean (cs : List Char) (h : ∀ c ∈ cs, ¬ c.isWhitespace)
    (toks : Array String) (cur : String) :
    cs.foldl tokenStep (toks, cur) = (toks, cur ++ String.ofList cs) := by
  induction cs generalizing cur with
  | nil => simp
  | cons c cs ih =>
    have hc : ¬ c.isWhitespace := h c (by simp)
    have hstep : tokenStep (toks, cur) c = (toks, cur.push c) := by simp [tokenStep, hc]
    rw [List.foldl_cons, hstep, ih (fun d hd => h d (by simp [hd]))]
    have : (cur.push c ++ String.ofList cs).toList = (cur ++ String.ofList (c :: cs)).toList := by
      simp [String.toList_append, String.toList_push, String.toList_ofList]
    rw [String.toList_inj.mp this]

/-- A trailing space performs exactly the flush the tokenizer ends with — which is what lets the
induction below stay compositional instead of reasoning about a distinguished last token. -/
private theorem foldl_append_space (s : String) (st : Array String × String) :
    (s ++ " ").toList.foldl tokenStep st = (tokenFlush (s.toList.foldl tokenStep st), "") := by
  have h : (s ++ " ").toList = s.toList ++ [' '] := by simp [String.toList_append]
  rw [h, List.foldl_append, List.foldl_cons, List.foldl_nil]
  generalize List.foldl tokenStep st s.toList = x
  by_cases hc : x.2.isEmpty <;> simp [tokenStep, tokenFlush, hc]

private theorem foldl_intercalate (ts : List String) (h : ∀ t ∈ ts, Clean t)
    (toks : Array String) :
    (String.intercalate " " ts ++ " ").toList.foldl tokenStep (toks, "")
      = (toks ++ ts.toArray, "") := by
  induction ts generalizing toks with
  | nil =>
    have : (String.intercalate " " ([] : List String) ++ " ").toList = [' '] := by
      simp [String.intercalate_nil]
    rw [this]
    simp [tokenStep]
  | cons t ts ih =>
    have ht : Clean t := h t (by simp)
    have htail : ∀ u ∈ ts, Clean u := fun u hu => h u (by simp [hu])
    have hfold : t.toList.foldl tokenStep (toks, "") = (toks, t) := by
      rw [foldl_clean t.toList ht.2 toks ""]
      simp [String.ofList_toList]
    have hspace : tokenStep (toks, t) ' ' = (toks.push t, "") := by
      simp [tokenStep, String.isEmpty_iff, ht.1]
    by_cases hts : ts = []
    · subst hts
      rw [String.intercalate_singleton, foldl_append_space, hfold]
      simp [tokenFlush, String.isEmpty_iff, ht.1]
    · rw [String.intercalate_cons_of_ne_nil hts]
      have hlist : (t ++ " " ++ String.intercalate " " ts ++ " ").toList
          = t.toList ++ [' '] ++ (String.intercalate " " ts ++ " ").toList := by
        simp [String.toList_append]
      rw [hlist, List.foldl_append, List.foldl_append, List.foldl_cons, List.foldl_nil,
        hfold, hspace, ih htail]
      simp

/-- **The round trip.** Joining clean tokens with single spaces and tokenizing again returns exactly
those tokens.

Everything below is a corollary. This is also where the `Clean` hypothesis earns its keep: without
it the statement is false — an empty or whitespace-bearing "token" does not survive the join. -/
theorem statementTokens_intercalate (ts : List String) (h : ∀ t ∈ ts, Clean t) :
    statementTokens (String.intercalate " " ts) = ts.toArray := by
  have h1 := congrArg Prod.fst (foldl_intercalate ts h #[])
  rw [foldl_append_space] at h1
  rw [statementTokens_eq]
  simpa using h1

/-- Normalizing does not change how a string tokenizes. -/
theorem statementTokens_normalizeSpace (s : String) :
    statementTokens (normalizeSpace s) = statementTokens s := by
  rw [normalizeSpace,
    statementTokens_intercalate _ (fun t ht => statementTokens_clean s t (by simpa using ht))]

/-- **Two strings share a key exactly when they tokenize alike.**

Read left to right: reindentation, and any other whitespace-only edit, is invisible to the diff —
the module's stated promise. Read right to left, and contrapositively: *every* difference the
tokenizer can see does reach the page. The comparison is neither coarser nor finer than the
tokenization. -/
theorem normalizeSpace_eq_iff (s t : String) :
    normalizeSpace s = normalizeSpace t ↔ statementTokens s = statementTokens t := by
  constructor
  · intro h
    have := congrArg statementTokens h
    rwa [statementTokens_normalizeSpace, statementTokens_normalizeSpace] at this
  · intro h
    rw [normalizeSpace, normalizeSpace, h]

/-- **`normalizeSpace` is idempotent**: its output is a canonical form, not merely a shorter string.

This is what makes `statementKey` and `bodyKey` keys at all. A comparison against a non-canonical
key would report differences between two spellings of the same normalized text. -/
theorem normalizeSpace_idem (s : String) :
    normalizeSpace (normalizeSpace s) = normalizeSpace s :=
  (normalizeSpace_eq_iff _ _).mpr (statementTokens_normalizeSpace s)

/-- The keys a declaration is compared on are already canonical. -/
theorem statementKey_normalized (d : DeclInfo) :
    normalizeSpace (statementKey d) = statementKey d :=
  normalizeSpace_idem _

theorem bodyKey_normalized (d : DeclInfo) :
    normalizeSpace (bodyKey d) = bodyKey d :=
  normalizeSpace_idem _

/-- Two declarations whose statements differ only in whitespace compare equal, so
`directKind` cannot report a statement change between them. -/
theorem statementKey_of_tokens_eq (d e : DeclInfo)
    (h : statementTokens d.expandedSignature = statementTokens e.expandedSignature) :
    statementKey d = statementKey e :=
  (normalizeSpace_eq_iff _ _).mpr h

end Referee.Proofs.Diff
