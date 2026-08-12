// Lean compiler output
// Module: JunkValues.Rule
// Imports: public import Init public meta import Init public import Lean
#include <lean/lean.h>
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wunused-label"
#elif defined(__GNUC__) && !defined(__CLANG__)
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-label"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif
#ifdef __cplusplus
extern "C" {
#endif
lean_object* l_Lean_Expr_getAppFn(lean_object*);
lean_object* lean_mk_empty_array_with_capacity(lean_object*);
lean_object* lean_nat_to_int(lean_object*);
lean_object* l_Lean_Meta_isProp(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
uint8_t lean_nat_dec_eq(lean_object*, lean_object*);
lean_object* lean_nat_sub(lean_object*, lean_object*);
lean_object* lean_array_fget_borrowed(lean_object*, lean_object*);
lean_object* lean_nat_add(lean_object*, lean_object*);
uint8_t lean_nat_dec_lt(lean_object*, lean_object*);
lean_object* lean_infer_type(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* lean_array_get(lean_object*, lean_object*, lean_object*);
uint8_t lean_string_dec_eq(lean_object*, lean_object*);
lean_object* l_Lean_Name_reprPrec(lean_object*, lean_object*);
lean_object* l_Nat_reprFast(lean_object*);
lean_object* lean_array_get_size(lean_object*);
lean_object* lean_array_to_list(lean_object*);
lean_object* lean_string_length(lean_object*);
lean_object* l_Std_Format_fill(lean_object*);
lean_object* l_String_quote(lean_object*);
lean_object* l_Lean_Expr_sort___override(lean_object*);
lean_object* lean_st_ref_get(lean_object*);
lean_object* l_Lean_Environment_find_x3f(lean_object*, lean_object*, uint8_t);
lean_object* l_Lean_ConstantInfo_levelParams(lean_object*);
lean_object* l_List_reverse___redArg(lean_object*);
lean_object* l_Lean_Meta_mkFreshLevelMVar(lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_ConstantInfo_type(lean_object*);
lean_object* l_Lean_Expr_instantiateLevelParams(lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_Meta_forallMetaTelescope(lean_object*, uint8_t, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_Name_mkStr1(lean_object*);
uint8_t l_Lean_Expr_isAppOfArity(lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_Expr_appFn_x21(lean_object*);
lean_object* l_Lean_Expr_appArg_x21(lean_object*);
lean_object* l_Lean_Expr_getAppNumArgs(lean_object*);
lean_object* lean_mk_array(lean_object*, lean_object*);
lean_object* l___private_Lean_Expr_0__Lean_Expr_getAppArgsAux(lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_Meta_getFunInfoNArgs(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* lean_array_push(lean_object*, lean_object*);
size_t lean_array_size(lean_object*);
uint8_t lean_usize_dec_lt(size_t, size_t);
lean_object* lean_array_uget_borrowed(lean_object*, size_t);
size_t lean_usize_add(size_t, size_t);
lean_object* lean_string_append(lean_object*, lean_object*);
lean_object* l_Lean_Name_toStringWithToken___at___00Lean_Name_toString_spec__0(lean_object*, uint8_t);
uint8_t lean_name_eq(lean_object*, lean_object*);
uint8_t lean_usize_dec_eq(size_t, size_t);
uint64_t lean_uint64_of_nat(lean_object*);
uint64_t lean_uint64_mix_hash(uint64_t, uint64_t);
uint64_t lean_string_hash(lean_object*);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
size_t lean_usize_of_nat(lean_object*);
uint64_t lean_uint64_of_nat(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Nat_cast___at___00JunkValues_instReprJunkRule_repr_spec__1(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_Format_joinSep___at___00Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0_spec__0___lam__0(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_List_foldl___at___00List_foldl___at___00Std_Format_joinSep___at___00Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0_spec__0_spec__2_spec__3(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_List_foldl___at___00Std_Format_joinSep___at___00Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0_spec__0_spec__2(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_Format_joinSep___at___00Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0_spec__0(lean_object*, lean_object*);
static const lean_string_object lp_JunkValues_Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "#["};
static const lean_object* lp_JunkValues_Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0___closed__0 = (const lean_object*)&lp_JunkValues_Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0___closed__0_value;
static const lean_string_object lp_JunkValues_Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 2, .m_capacity = 2, .m_length = 1, .m_data = ","};
static const lean_object* lp_JunkValues_Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0___closed__1 = (const lean_object*)&lp_JunkValues_Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0___closed__1_value;
static const lean_ctor_object lp_JunkValues_Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_JunkValues_Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0___closed__1_value)}};
static const lean_object* lp_JunkValues_Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0___closed__2 = (const lean_object*)&lp_JunkValues_Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0___closed__2_value;
static const lean_ctor_object lp_JunkValues_Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_JunkValues_Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0___closed__2_value),((lean_object*)(((size_t)(1) << 1) | 1))}};
static const lean_object* lp_JunkValues_Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0___closed__3 = (const lean_object*)&lp_JunkValues_Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0___closed__3_value;
static const lean_string_object lp_JunkValues_Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 2, .m_capacity = 2, .m_length = 1, .m_data = "]"};
static const lean_object* lp_JunkValues_Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0___closed__4 = (const lean_object*)&lp_JunkValues_Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0___closed__4_value;
static lean_once_cell_t lp_JunkValues_Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0___closed__5_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0___closed__5;
static lean_once_cell_t lp_JunkValues_Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0___closed__6_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0___closed__6;
static const lean_ctor_object lp_JunkValues_Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_JunkValues_Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0___closed__0_value)}};
static const lean_object* lp_JunkValues_Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0___closed__7 = (const lean_object*)&lp_JunkValues_Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0___closed__7_value;
static const lean_ctor_object lp_JunkValues_Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_JunkValues_Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0___closed__4_value)}};
static const lean_object* lp_JunkValues_Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0___closed__8 = (const lean_object*)&lp_JunkValues_Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0___closed__8_value;
static const lean_string_object lp_JunkValues_Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "#[]"};
static const lean_object* lp_JunkValues_Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0___closed__9 = (const lean_object*)&lp_JunkValues_Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0___closed__9_value;
static const lean_ctor_object lp_JunkValues_Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_JunkValues_Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0___closed__9_value)}};
static const lean_object* lp_JunkValues_Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0___closed__10 = (const lean_object*)&lp_JunkValues_Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0___closed__10_value;
LEAN_EXPORT lean_object* lp_JunkValues_Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0(lean_object*);
static const lean_string_object lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "{ "};
static const lean_object* lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__0_value;
static const lean_string_object lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "source"};
static const lean_object* lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__1 = (const lean_object*)&lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__1_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__1_value)}};
static const lean_object* lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__2 = (const lean_object*)&lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__2_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__2_value)}};
static const lean_object* lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__3 = (const lean_object*)&lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__3_value;
static const lean_string_object lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = " := "};
static const lean_object* lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__4 = (const lean_object*)&lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__4_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__4_value)}};
static const lean_object* lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__5 = (const lean_object*)&lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__5_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__3_value),((lean_object*)&lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__5_value)}};
static const lean_object* lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__6 = (const lean_object*)&lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__6_value;
static lean_once_cell_t lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__7_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__7;
static const lean_string_object lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "head"};
static const lean_object* lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__8 = (const lean_object*)&lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__8_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__8_value)}};
static const lean_object* lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__9 = (const lean_object*)&lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__9_value;
static lean_once_cell_t lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__10_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__10;
static const lean_string_object lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "arity"};
static const lean_object* lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__11 = (const lean_object*)&lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__11_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__12_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__11_value)}};
static const lean_object* lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__12 = (const lean_object*)&lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__12_value;
static lean_once_cell_t lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__13_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__13;
static const lean_string_object lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__14_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 14, .m_capacity = 14, .m_length = 13, .m_data = "negatedGuards"};
static const lean_object* lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__14 = (const lean_object*)&lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__14_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__15_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__14_value)}};
static const lean_object* lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__15 = (const lean_object*)&lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__15_value;
static lean_once_cell_t lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__16_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__16;
static const lean_string_object lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__17_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "generalize"};
static const lean_object* lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__17 = (const lean_object*)&lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__17_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__18_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__17_value)}};
static const lean_object* lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__18 = (const lean_object*)&lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__18_value;
static lean_once_cell_t lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__19_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__19;
static const lean_string_object lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__20_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "note"};
static const lean_object* lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__20 = (const lean_object*)&lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__20_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__21_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__20_value)}};
static const lean_object* lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__21 = (const lean_object*)&lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__21_value;
static const lean_string_object lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__22_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = " }"};
static const lean_object* lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__22 = (const lean_object*)&lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__22_value;
static lean_once_cell_t lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__23_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__23;
static lean_once_cell_t lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__24_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__24;
static const lean_ctor_object lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__25_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__0_value)}};
static const lean_object* lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__25 = (const lean_object*)&lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__25_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__26_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__22_value)}};
static const lean_object* lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__26 = (const lean_object*)&lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__26_value;
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instReprJunkRule_repr(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instReprJunkRule_repr___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_JunkValues_JunkValues_instReprJunkRule___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_JunkValues_JunkValues_instReprJunkRule_repr___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_JunkValues_JunkValues_instReprJunkRule___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_instReprJunkRule___closed__0_value;
LEAN_EXPORT const lean_object* lp_JunkValues_JunkValues_instReprJunkRule = (const lean_object*)&lp_JunkValues_JunkValues_instReprJunkRule___closed__0_value;
static const lean_array_object lp_JunkValues_JunkValues_instInhabitedJunkRule_default___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* lp_JunkValues_JunkValues_instInhabitedJunkRule_default___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_instInhabitedJunkRule_default___closed__0_value;
static const lean_string_object lp_JunkValues_JunkValues_instInhabitedJunkRule_default___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 1, .m_capacity = 1, .m_length = 0, .m_data = ""};
static const lean_object* lp_JunkValues_JunkValues_instInhabitedJunkRule_default___closed__1 = (const lean_object*)&lp_JunkValues_JunkValues_instInhabitedJunkRule_default___closed__1_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instInhabitedJunkRule_default___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*6 + 0, .m_other = 6, .m_tag = 0}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_instInhabitedJunkRule_default___closed__0_value),((lean_object*)&lp_JunkValues_JunkValues_instInhabitedJunkRule_default___closed__1_value)}};
static const lean_object* lp_JunkValues_JunkValues_instInhabitedJunkRule_default___closed__2 = (const lean_object*)&lp_JunkValues_JunkValues_instInhabitedJunkRule_default___closed__2_value;
LEAN_EXPORT const lean_object* lp_JunkValues_JunkValues_instInhabitedJunkRule_default = (const lean_object*)&lp_JunkValues_JunkValues_instInhabitedJunkRule_default___closed__2_value;
LEAN_EXPORT const lean_object* lp_JunkValues_JunkValues_instInhabitedJunkRule = (const lean_object*)&lp_JunkValues_JunkValues_instInhabitedJunkRule_default___closed__2_value;
LEAN_EXPORT uint8_t lp_JunkValues_Array_isEqvAux___at___00JunkValues_instBEqJunkRule_beq_spec__0___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Array_isEqvAux___at___00JunkValues_instBEqJunkRule_beq_spec__0___redArg___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_JunkValues_JunkValues_instBEqJunkRule_beq(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instBEqJunkRule_beq___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_JunkValues_Array_isEqvAux___at___00JunkValues_instBEqJunkRule_beq_spec__0(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Array_isEqvAux___at___00JunkValues_instBEqJunkRule_beq_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_closure_object lp_JunkValues_JunkValues_instBEqJunkRule___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_JunkValues_JunkValues_instBEqJunkRule_beq___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_JunkValues_JunkValues_instBEqJunkRule___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_instBEqJunkRule___closed__0_value;
LEAN_EXPORT const lean_object* lp_JunkValues_JunkValues_instBEqJunkRule = (const lean_object*)&lp_JunkValues_JunkValues_instBEqJunkRule___closed__0_value;
LEAN_EXPORT uint8_t lp_JunkValues_Array_instDecidableEqImpl___at___00JunkValues_instDecidableEqJunkRule_decEq_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Array_instDecidableEqImpl___at___00JunkValues_instDecidableEqJunkRule_decEq_spec__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_JunkValues_JunkValues_instDecidableEqJunkRule_decEq(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instDecidableEqJunkRule_decEq___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_JunkValues_JunkValues_instDecidableEqJunkRule(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instDecidableEqJunkRule___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint64_t lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00JunkValues_instHashableJunkRule_hash_spec__0(lean_object*, size_t, size_t, uint64_t);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00JunkValues_instHashableJunkRule_hash_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
static lean_once_cell_t lp_JunkValues_JunkValues_instHashableJunkRule_hash___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static uint64_t lp_JunkValues_JunkValues_instHashableJunkRule_hash___closed__0;
LEAN_EXPORT uint64_t lp_JunkValues_JunkValues_instHashableJunkRule_hash(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instHashableJunkRule_hash___boxed(lean_object*);
static const lean_closure_object lp_JunkValues_JunkValues_instHashableJunkRule___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_JunkValues_JunkValues_instHashableJunkRule_hash___boxed, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_JunkValues_JunkValues_instHashableJunkRule___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_instHashableJunkRule___closed__0_value;
LEAN_EXPORT const lean_object* lp_JunkValues_JunkValues_instHashableJunkRule = (const lean_object*)&lp_JunkValues_JunkValues_instHashableJunkRule___closed__0_value;
LEAN_EXPORT lean_object* lp_JunkValues_List_mapM_loop___at___00JunkValues_openRule_spec__0(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_List_mapM_loop___at___00JunkValues_openRule_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object lp_JunkValues_JunkValues_openRule___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "Eq"};
static const lean_object* lp_JunkValues_JunkValues_openRule___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_openRule___closed__0_value;
static const lean_ctor_object lp_JunkValues_JunkValues_openRule___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_openRule___closed__0_value),LEAN_SCALAR_PTR_LITERAL(143, 37, 101, 248, 9, 246, 191, 223)}};
static const lean_object* lp_JunkValues_JunkValues_openRule___closed__1 = (const lean_object*)&lp_JunkValues_JunkValues_openRule___closed__1_value;
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_openRule(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_openRule___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_isGuardBinder(uint8_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_isGuardBinder___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_headConst_x3f(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_headConst_x3f___boxed(lean_object*);
static const lean_string_object lp_JunkValues_JunkValues_isNegatedProp___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "Not"};
static const lean_object* lp_JunkValues_JunkValues_isNegatedProp___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_isNegatedProp___closed__0_value;
static const lean_string_object lp_JunkValues_JunkValues_isNegatedProp___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "Ne"};
static const lean_object* lp_JunkValues_JunkValues_isNegatedProp___closed__1 = (const lean_object*)&lp_JunkValues_JunkValues_isNegatedProp___closed__1_value;
LEAN_EXPORT uint8_t lp_JunkValues_JunkValues_isNegatedProp(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_isNegatedProp___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00JunkValues_explicitArgIndices_spec__0___redArg(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00JunkValues_explicitArgIndices_spec__0___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static lean_once_cell_t lp_JunkValues_JunkValues_explicitArgIndices___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_explicitArgIndices___closed__0;
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_explicitArgIndices(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_explicitArgIndices___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00JunkValues_explicitArgIndices_spec__0(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00JunkValues_explicitArgIndices_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00JunkValues_ruleOfTheorem_x3f_spec__0___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00JunkValues_ruleOfTheorem_x3f_spec__0___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_ctor_object lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_ruleOfTheorem_x3f_spec__1___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_ruleOfTheorem_x3f_spec__1___redArg___closed__0 = (const lean_object*)&lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_ruleOfTheorem_x3f_spec__1___redArg___closed__0_value;
static const lean_string_object lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_ruleOfTheorem_x3f_spec__1___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 28, .m_capacity = 28, .m_length = 27, .m_data = "cannot generalize position "};
static const lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_ruleOfTheorem_x3f_spec__1___redArg___closed__1 = (const lean_object*)&lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_ruleOfTheorem_x3f_spec__1___redArg___closed__1_value;
static const lean_string_object lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_ruleOfTheorem_x3f_spec__1___redArg___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 26, .m_capacity = 26, .m_length = 25, .m_data = ": the left-hand side of `"};
static const lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_ruleOfTheorem_x3f_spec__1___redArg___closed__2 = (const lean_object*)&lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_ruleOfTheorem_x3f_spec__1___redArg___closed__2_value;
static const lean_string_object lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_ruleOfTheorem_x3f_spec__1___redArg___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "` has "};
static const lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_ruleOfTheorem_x3f_spec__1___redArg___closed__3 = (const lean_object*)&lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_ruleOfTheorem_x3f_spec__1___redArg___closed__3_value;
static const lean_string_object lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_ruleOfTheorem_x3f_spec__1___redArg___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 56, .m_capacity = 56, .m_length = 55, .m_data = " explicit argument(s), and positions are counted from 1"};
static const lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_ruleOfTheorem_x3f_spec__1___redArg___closed__4 = (const lean_object*)&lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_ruleOfTheorem_x3f_spec__1___redArg___closed__4_value;
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_ruleOfTheorem_x3f_spec__1___redArg(lean_object*, lean_object*, lean_object*, size_t, size_t, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_ruleOfTheorem_x3f_spec__1___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_ctor_object lp_JunkValues_JunkValues_ruleOfTheorem_x3f___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_JunkValues_JunkValues_ruleOfTheorem_x3f___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_ruleOfTheorem_x3f___closed__0_value;
static const lean_string_object lp_JunkValues_JunkValues_ruleOfTheorem_x3f___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 2, .m_capacity = 2, .m_length = 1, .m_data = "`"};
static const lean_object* lp_JunkValues_JunkValues_ruleOfTheorem_x3f___closed__1 = (const lean_object*)&lp_JunkValues_JunkValues_ruleOfTheorem_x3f___closed__1_value;
static const lean_string_object lp_JunkValues_JunkValues_ruleOfTheorem_x3f___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 278, .m_capacity = 278, .m_length = 273, .m_data = "` has no hypothesis, so it states an unconditional identity rather than a condition under which a value collapses to a default. If the condition is hidden in the shape of the left-hand side — as in `a / 0 = 0` — name the argument position to generalize, as `generalizing 2`"};
static const lean_object* lp_JunkValues_JunkValues_ruleOfTheorem_x3f___closed__2 = (const lean_object*)&lp_JunkValues_JunkValues_ruleOfTheorem_x3f___closed__2_value;
static const lean_string_object lp_JunkValues_JunkValues_ruleOfTheorem_x3f___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 24, .m_capacity = 24, .m_length = 23, .m_data = "the left-hand side of `"};
static const lean_object* lp_JunkValues_JunkValues_ruleOfTheorem_x3f___closed__3 = (const lean_object*)&lp_JunkValues_JunkValues_ruleOfTheorem_x3f___closed__3_value;
static const lean_string_object lp_JunkValues_JunkValues_ruleOfTheorem_x3f___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 72, .m_capacity = 72, .m_length = 71, .m_data = "` is not headed by a constant, so there is nothing to index the rule by"};
static const lean_object* lp_JunkValues_JunkValues_ruleOfTheorem_x3f___closed__4 = (const lean_object*)&lp_JunkValues_JunkValues_ruleOfTheorem_x3f___closed__4_value;
static const lean_string_object lp_JunkValues_JunkValues_ruleOfTheorem_x3f___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 54, .m_capacity = 54, .m_length = 53, .m_data = "` does not exist, or its statement is not an equation"};
static const lean_object* lp_JunkValues_JunkValues_ruleOfTheorem_x3f___closed__5 = (const lean_object*)&lp_JunkValues_JunkValues_ruleOfTheorem_x3f___closed__5_value;
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_ruleOfTheorem_x3f(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_ruleOfTheorem_x3f___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00JunkValues_ruleOfTheorem_x3f_spec__0(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00JunkValues_ruleOfTheorem_x3f_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_ruleOfTheorem_x3f_spec__1(lean_object*, lean_object*, lean_object*, size_t, size_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_ruleOfTheorem_x3f_spec__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Nat_cast___at___00JunkValues_instReprJunkRule_repr_spec__1(lean_object* v_a_1_){
_start:
{
lean_object* v___x_2_; 
v___x_2_ = lean_nat_to_int(v_a_1_);
return v___x_2_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_Format_joinSep___at___00Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0_spec__0___lam__0(lean_object* v___y_3_){
_start:
{
lean_object* v___x_4_; lean_object* v___x_5_; 
v___x_4_ = l_Nat_reprFast(v___y_3_);
v___x_5_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_5_, 0, v___x_4_);
return v___x_5_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_List_foldl___at___00List_foldl___at___00Std_Format_joinSep___at___00Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0_spec__0_spec__2_spec__3(lean_object* v_x_6_, lean_object* v_x_7_, lean_object* v_x_8_){
_start:
{
if (lean_obj_tag(v_x_8_) == 0)
{
lean_dec(v_x_6_);
return v_x_7_;
}
else
{
lean_object* v_head_9_; lean_object* v_tail_10_; lean_object* v___x_12_; uint8_t v_isShared_13_; uint8_t v_isSharedCheck_21_; 
v_head_9_ = lean_ctor_get(v_x_8_, 0);
v_tail_10_ = lean_ctor_get(v_x_8_, 1);
v_isSharedCheck_21_ = !lean_is_exclusive(v_x_8_);
if (v_isSharedCheck_21_ == 0)
{
v___x_12_ = v_x_8_;
v_isShared_13_ = v_isSharedCheck_21_;
goto v_resetjp_11_;
}
else
{
lean_inc(v_tail_10_);
lean_inc(v_head_9_);
lean_dec(v_x_8_);
v___x_12_ = lean_box(0);
v_isShared_13_ = v_isSharedCheck_21_;
goto v_resetjp_11_;
}
v_resetjp_11_:
{
lean_object* v___x_15_; 
lean_inc(v_x_6_);
if (v_isShared_13_ == 0)
{
lean_ctor_set_tag(v___x_12_, 5);
lean_ctor_set(v___x_12_, 1, v_x_6_);
lean_ctor_set(v___x_12_, 0, v_x_7_);
v___x_15_ = v___x_12_;
goto v_reusejp_14_;
}
else
{
lean_object* v_reuseFailAlloc_20_; 
v_reuseFailAlloc_20_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v_reuseFailAlloc_20_, 0, v_x_7_);
lean_ctor_set(v_reuseFailAlloc_20_, 1, v_x_6_);
v___x_15_ = v_reuseFailAlloc_20_;
goto v_reusejp_14_;
}
v_reusejp_14_:
{
lean_object* v___x_16_; lean_object* v___x_17_; lean_object* v___x_18_; 
v___x_16_ = l_Nat_reprFast(v_head_9_);
v___x_17_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_17_, 0, v___x_16_);
v___x_18_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_18_, 0, v___x_15_);
lean_ctor_set(v___x_18_, 1, v___x_17_);
v_x_7_ = v___x_18_;
v_x_8_ = v_tail_10_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_List_foldl___at___00Std_Format_joinSep___at___00Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0_spec__0_spec__2(lean_object* v_x_22_, lean_object* v_x_23_, lean_object* v_x_24_){
_start:
{
if (lean_obj_tag(v_x_24_) == 0)
{
lean_dec(v_x_22_);
return v_x_23_;
}
else
{
lean_object* v_head_25_; lean_object* v_tail_26_; lean_object* v___x_28_; uint8_t v_isShared_29_; uint8_t v_isSharedCheck_37_; 
v_head_25_ = lean_ctor_get(v_x_24_, 0);
v_tail_26_ = lean_ctor_get(v_x_24_, 1);
v_isSharedCheck_37_ = !lean_is_exclusive(v_x_24_);
if (v_isSharedCheck_37_ == 0)
{
v___x_28_ = v_x_24_;
v_isShared_29_ = v_isSharedCheck_37_;
goto v_resetjp_27_;
}
else
{
lean_inc(v_tail_26_);
lean_inc(v_head_25_);
lean_dec(v_x_24_);
v___x_28_ = lean_box(0);
v_isShared_29_ = v_isSharedCheck_37_;
goto v_resetjp_27_;
}
v_resetjp_27_:
{
lean_object* v___x_31_; 
lean_inc(v_x_22_);
if (v_isShared_29_ == 0)
{
lean_ctor_set_tag(v___x_28_, 5);
lean_ctor_set(v___x_28_, 1, v_x_22_);
lean_ctor_set(v___x_28_, 0, v_x_23_);
v___x_31_ = v___x_28_;
goto v_reusejp_30_;
}
else
{
lean_object* v_reuseFailAlloc_36_; 
v_reuseFailAlloc_36_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v_reuseFailAlloc_36_, 0, v_x_23_);
lean_ctor_set(v_reuseFailAlloc_36_, 1, v_x_22_);
v___x_31_ = v_reuseFailAlloc_36_;
goto v_reusejp_30_;
}
v_reusejp_30_:
{
lean_object* v___x_32_; lean_object* v___x_33_; lean_object* v___x_34_; lean_object* v___x_35_; 
v___x_32_ = l_Nat_reprFast(v_head_25_);
v___x_33_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_33_, 0, v___x_32_);
v___x_34_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_34_, 0, v___x_31_);
lean_ctor_set(v___x_34_, 1, v___x_33_);
v___x_35_ = lp_JunkValues_List_foldl___at___00List_foldl___at___00Std_Format_joinSep___at___00Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0_spec__0_spec__2_spec__3(v_x_22_, v___x_34_, v_tail_26_);
return v___x_35_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_Format_joinSep___at___00Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0_spec__0(lean_object* v_x_38_, lean_object* v_x_39_){
_start:
{
if (lean_obj_tag(v_x_38_) == 0)
{
lean_object* v___x_40_; 
lean_dec(v_x_39_);
v___x_40_ = lean_box(0);
return v___x_40_;
}
else
{
lean_object* v_tail_41_; 
v_tail_41_ = lean_ctor_get(v_x_38_, 1);
if (lean_obj_tag(v_tail_41_) == 0)
{
lean_object* v_head_42_; lean_object* v___x_43_; 
lean_dec(v_x_39_);
v_head_42_ = lean_ctor_get(v_x_38_, 0);
lean_inc(v_head_42_);
lean_dec_ref_known(v_x_38_, 2);
v___x_43_ = lp_JunkValues_Std_Format_joinSep___at___00Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0_spec__0___lam__0(v_head_42_);
return v___x_43_;
}
else
{
lean_object* v_head_44_; lean_object* v___x_45_; lean_object* v___x_46_; 
lean_inc(v_tail_41_);
v_head_44_ = lean_ctor_get(v_x_38_, 0);
lean_inc(v_head_44_);
lean_dec_ref_known(v_x_38_, 2);
v___x_45_ = lp_JunkValues_Std_Format_joinSep___at___00Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0_spec__0___lam__0(v_head_44_);
v___x_46_ = lp_JunkValues_List_foldl___at___00Std_Format_joinSep___at___00Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0_spec__0_spec__2(v_x_39_, v___x_45_, v_tail_41_);
return v___x_46_;
}
}
}
}
static lean_object* _init_lp_JunkValues_Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0___closed__5(void){
_start:
{
lean_object* v___x_55_; lean_object* v___x_56_; 
v___x_55_ = ((lean_object*)(lp_JunkValues_Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0___closed__0));
v___x_56_ = lean_string_length(v___x_55_);
return v___x_56_;
}
}
static lean_object* _init_lp_JunkValues_Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0___closed__6(void){
_start:
{
lean_object* v___x_57_; lean_object* v___x_58_; 
v___x_57_ = lean_obj_once(&lp_JunkValues_Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0___closed__5, &lp_JunkValues_Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0___closed__5_once, _init_lp_JunkValues_Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0___closed__5);
v___x_58_ = lean_nat_to_int(v___x_57_);
return v___x_58_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0(lean_object* v_xs_66_){
_start:
{
lean_object* v___x_67_; lean_object* v___x_68_; uint8_t v___x_69_; 
v___x_67_ = lean_array_get_size(v_xs_66_);
v___x_68_ = lean_unsigned_to_nat(0u);
v___x_69_ = lean_nat_dec_eq(v___x_67_, v___x_68_);
if (v___x_69_ == 0)
{
lean_object* v___x_70_; lean_object* v___x_71_; lean_object* v___x_72_; lean_object* v___x_73_; lean_object* v___x_74_; lean_object* v___x_75_; lean_object* v___x_76_; lean_object* v___x_77_; lean_object* v___x_78_; lean_object* v___x_79_; 
v___x_70_ = lean_array_to_list(v_xs_66_);
v___x_71_ = ((lean_object*)(lp_JunkValues_Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0___closed__3));
v___x_72_ = lp_JunkValues_Std_Format_joinSep___at___00Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0_spec__0(v___x_70_, v___x_71_);
v___x_73_ = lean_obj_once(&lp_JunkValues_Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0___closed__6, &lp_JunkValues_Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0___closed__6_once, _init_lp_JunkValues_Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0___closed__6);
v___x_74_ = ((lean_object*)(lp_JunkValues_Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0___closed__7));
v___x_75_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_75_, 0, v___x_74_);
lean_ctor_set(v___x_75_, 1, v___x_72_);
v___x_76_ = ((lean_object*)(lp_JunkValues_Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0___closed__8));
v___x_77_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_77_, 0, v___x_75_);
lean_ctor_set(v___x_77_, 1, v___x_76_);
v___x_78_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_78_, 0, v___x_73_);
lean_ctor_set(v___x_78_, 1, v___x_77_);
v___x_79_ = l_Std_Format_fill(v___x_78_);
return v___x_79_;
}
else
{
lean_object* v___x_80_; 
lean_dec_ref(v_xs_66_);
v___x_80_ = ((lean_object*)(lp_JunkValues_Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0___closed__10));
return v___x_80_;
}
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__7(void){
_start:
{
lean_object* v___x_94_; lean_object* v___x_95_; 
v___x_94_ = lean_unsigned_to_nat(10u);
v___x_95_ = lean_nat_to_int(v___x_94_);
return v___x_95_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__10(void){
_start:
{
lean_object* v___x_99_; lean_object* v___x_100_; 
v___x_99_ = lean_unsigned_to_nat(8u);
v___x_100_ = lean_nat_to_int(v___x_99_);
return v___x_100_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__13(void){
_start:
{
lean_object* v___x_104_; lean_object* v___x_105_; 
v___x_104_ = lean_unsigned_to_nat(9u);
v___x_105_ = lean_nat_to_int(v___x_104_);
return v___x_105_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__16(void){
_start:
{
lean_object* v___x_109_; lean_object* v___x_110_; 
v___x_109_ = lean_unsigned_to_nat(17u);
v___x_110_ = lean_nat_to_int(v___x_109_);
return v___x_110_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__19(void){
_start:
{
lean_object* v___x_114_; lean_object* v___x_115_; 
v___x_114_ = lean_unsigned_to_nat(14u);
v___x_115_ = lean_nat_to_int(v___x_114_);
return v___x_115_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__23(void){
_start:
{
lean_object* v___x_120_; lean_object* v___x_121_; 
v___x_120_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__0));
v___x_121_ = lean_string_length(v___x_120_);
return v___x_121_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__24(void){
_start:
{
lean_object* v___x_122_; lean_object* v___x_123_; 
v___x_122_ = lean_obj_once(&lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__23, &lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__23_once, _init_lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__23);
v___x_123_ = lean_nat_to_int(v___x_122_);
return v___x_123_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg(lean_object* v_x_128_){
_start:
{
lean_object* v_source_129_; lean_object* v_head_130_; lean_object* v_arity_131_; lean_object* v_negatedGuards_132_; lean_object* v_generalize_133_; lean_object* v_note_134_; lean_object* v___x_135_; lean_object* v___x_136_; lean_object* v___x_137_; lean_object* v___x_138_; lean_object* v___x_139_; lean_object* v___x_140_; uint8_t v___x_141_; lean_object* v___x_142_; lean_object* v___x_143_; lean_object* v___x_144_; lean_object* v___x_145_; lean_object* v___x_146_; lean_object* v___x_147_; lean_object* v___x_148_; lean_object* v___x_149_; lean_object* v___x_150_; lean_object* v___x_151_; lean_object* v___x_152_; lean_object* v___x_153_; lean_object* v___x_154_; lean_object* v___x_155_; lean_object* v___x_156_; lean_object* v___x_157_; lean_object* v___x_158_; lean_object* v___x_159_; lean_object* v___x_160_; lean_object* v___x_161_; lean_object* v___x_162_; lean_object* v___x_163_; lean_object* v___x_164_; lean_object* v___x_165_; lean_object* v___x_166_; lean_object* v___x_167_; lean_object* v___x_168_; lean_object* v___x_169_; lean_object* v___x_170_; lean_object* v___x_171_; lean_object* v___x_172_; lean_object* v___x_173_; lean_object* v___x_174_; lean_object* v___x_175_; lean_object* v___x_176_; lean_object* v___x_177_; lean_object* v___x_178_; lean_object* v___x_179_; lean_object* v___x_180_; lean_object* v___x_181_; lean_object* v___x_182_; lean_object* v___x_183_; lean_object* v___x_184_; lean_object* v___x_185_; lean_object* v___x_186_; lean_object* v___x_187_; lean_object* v___x_188_; lean_object* v___x_189_; lean_object* v___x_190_; lean_object* v___x_191_; lean_object* v___x_192_; lean_object* v___x_193_; lean_object* v___x_194_; lean_object* v___x_195_; lean_object* v___x_196_; lean_object* v___x_197_; lean_object* v___x_198_; lean_object* v___x_199_; lean_object* v___x_200_; lean_object* v___x_201_; lean_object* v___x_202_; lean_object* v___x_203_; lean_object* v___x_204_; 
v_source_129_ = lean_ctor_get(v_x_128_, 0);
lean_inc(v_source_129_);
v_head_130_ = lean_ctor_get(v_x_128_, 1);
lean_inc(v_head_130_);
v_arity_131_ = lean_ctor_get(v_x_128_, 2);
lean_inc(v_arity_131_);
v_negatedGuards_132_ = lean_ctor_get(v_x_128_, 3);
lean_inc(v_negatedGuards_132_);
v_generalize_133_ = lean_ctor_get(v_x_128_, 4);
lean_inc_ref(v_generalize_133_);
v_note_134_ = lean_ctor_get(v_x_128_, 5);
lean_inc_ref(v_note_134_);
lean_dec_ref(v_x_128_);
v___x_135_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__5));
v___x_136_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__6));
v___x_137_ = lean_obj_once(&lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__7, &lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__7_once, _init_lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__7);
v___x_138_ = lean_unsigned_to_nat(0u);
v___x_139_ = l_Lean_Name_reprPrec(v_source_129_, v___x_138_);
v___x_140_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_140_, 0, v___x_137_);
lean_ctor_set(v___x_140_, 1, v___x_139_);
v___x_141_ = 0;
v___x_142_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_142_, 0, v___x_140_);
lean_ctor_set_uint8(v___x_142_, sizeof(void*)*1, v___x_141_);
v___x_143_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_143_, 0, v___x_136_);
lean_ctor_set(v___x_143_, 1, v___x_142_);
v___x_144_ = ((lean_object*)(lp_JunkValues_Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0___closed__2));
v___x_145_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_145_, 0, v___x_143_);
lean_ctor_set(v___x_145_, 1, v___x_144_);
v___x_146_ = lean_box(1);
v___x_147_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_147_, 0, v___x_145_);
lean_ctor_set(v___x_147_, 1, v___x_146_);
v___x_148_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__9));
v___x_149_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_149_, 0, v___x_147_);
lean_ctor_set(v___x_149_, 1, v___x_148_);
v___x_150_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_150_, 0, v___x_149_);
lean_ctor_set(v___x_150_, 1, v___x_135_);
v___x_151_ = lean_obj_once(&lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__10, &lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__10_once, _init_lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__10);
v___x_152_ = l_Lean_Name_reprPrec(v_head_130_, v___x_138_);
v___x_153_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_153_, 0, v___x_151_);
lean_ctor_set(v___x_153_, 1, v___x_152_);
v___x_154_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_154_, 0, v___x_153_);
lean_ctor_set_uint8(v___x_154_, sizeof(void*)*1, v___x_141_);
v___x_155_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_155_, 0, v___x_150_);
lean_ctor_set(v___x_155_, 1, v___x_154_);
v___x_156_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_156_, 0, v___x_155_);
lean_ctor_set(v___x_156_, 1, v___x_144_);
v___x_157_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_157_, 0, v___x_156_);
lean_ctor_set(v___x_157_, 1, v___x_146_);
v___x_158_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__12));
v___x_159_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_159_, 0, v___x_157_);
lean_ctor_set(v___x_159_, 1, v___x_158_);
v___x_160_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_160_, 0, v___x_159_);
lean_ctor_set(v___x_160_, 1, v___x_135_);
v___x_161_ = lean_obj_once(&lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__13, &lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__13_once, _init_lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__13);
v___x_162_ = l_Nat_reprFast(v_arity_131_);
v___x_163_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_163_, 0, v___x_162_);
v___x_164_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_164_, 0, v___x_161_);
lean_ctor_set(v___x_164_, 1, v___x_163_);
v___x_165_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_165_, 0, v___x_164_);
lean_ctor_set_uint8(v___x_165_, sizeof(void*)*1, v___x_141_);
v___x_166_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_166_, 0, v___x_160_);
lean_ctor_set(v___x_166_, 1, v___x_165_);
v___x_167_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_167_, 0, v___x_166_);
lean_ctor_set(v___x_167_, 1, v___x_144_);
v___x_168_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_168_, 0, v___x_167_);
lean_ctor_set(v___x_168_, 1, v___x_146_);
v___x_169_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__15));
v___x_170_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_170_, 0, v___x_168_);
lean_ctor_set(v___x_170_, 1, v___x_169_);
v___x_171_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_171_, 0, v___x_170_);
lean_ctor_set(v___x_171_, 1, v___x_135_);
v___x_172_ = lean_obj_once(&lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__16, &lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__16_once, _init_lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__16);
v___x_173_ = l_Nat_reprFast(v_negatedGuards_132_);
v___x_174_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_174_, 0, v___x_173_);
v___x_175_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_175_, 0, v___x_172_);
lean_ctor_set(v___x_175_, 1, v___x_174_);
v___x_176_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_176_, 0, v___x_175_);
lean_ctor_set_uint8(v___x_176_, sizeof(void*)*1, v___x_141_);
v___x_177_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_177_, 0, v___x_171_);
lean_ctor_set(v___x_177_, 1, v___x_176_);
v___x_178_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_178_, 0, v___x_177_);
lean_ctor_set(v___x_178_, 1, v___x_144_);
v___x_179_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_179_, 0, v___x_178_);
lean_ctor_set(v___x_179_, 1, v___x_146_);
v___x_180_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__18));
v___x_181_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_181_, 0, v___x_179_);
lean_ctor_set(v___x_181_, 1, v___x_180_);
v___x_182_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_182_, 0, v___x_181_);
lean_ctor_set(v___x_182_, 1, v___x_135_);
v___x_183_ = lean_obj_once(&lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__19, &lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__19_once, _init_lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__19);
v___x_184_ = lp_JunkValues_Array_repr___at___00JunkValues_instReprJunkRule_repr_spec__0(v_generalize_133_);
v___x_185_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_185_, 0, v___x_183_);
lean_ctor_set(v___x_185_, 1, v___x_184_);
v___x_186_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_186_, 0, v___x_185_);
lean_ctor_set_uint8(v___x_186_, sizeof(void*)*1, v___x_141_);
v___x_187_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_187_, 0, v___x_182_);
lean_ctor_set(v___x_187_, 1, v___x_186_);
v___x_188_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_188_, 0, v___x_187_);
lean_ctor_set(v___x_188_, 1, v___x_144_);
v___x_189_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_189_, 0, v___x_188_);
lean_ctor_set(v___x_189_, 1, v___x_146_);
v___x_190_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__21));
v___x_191_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_191_, 0, v___x_189_);
lean_ctor_set(v___x_191_, 1, v___x_190_);
v___x_192_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_192_, 0, v___x_191_);
lean_ctor_set(v___x_192_, 1, v___x_135_);
v___x_193_ = l_String_quote(v_note_134_);
v___x_194_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_194_, 0, v___x_193_);
v___x_195_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_195_, 0, v___x_151_);
lean_ctor_set(v___x_195_, 1, v___x_194_);
v___x_196_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_196_, 0, v___x_195_);
lean_ctor_set_uint8(v___x_196_, sizeof(void*)*1, v___x_141_);
v___x_197_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_197_, 0, v___x_192_);
lean_ctor_set(v___x_197_, 1, v___x_196_);
v___x_198_ = lean_obj_once(&lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__24, &lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__24_once, _init_lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__24);
v___x_199_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__25));
v___x_200_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_200_, 0, v___x_199_);
lean_ctor_set(v___x_200_, 1, v___x_197_);
v___x_201_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg___closed__26));
v___x_202_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_202_, 0, v___x_200_);
lean_ctor_set(v___x_202_, 1, v___x_201_);
v___x_203_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_203_, 0, v___x_198_);
lean_ctor_set(v___x_203_, 1, v___x_202_);
v___x_204_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_204_, 0, v___x_203_);
lean_ctor_set_uint8(v___x_204_, sizeof(void*)*1, v___x_141_);
return v___x_204_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instReprJunkRule_repr(lean_object* v_x_205_, lean_object* v_prec_206_){
_start:
{
lean_object* v___x_207_; 
v___x_207_ = lp_JunkValues_JunkValues_instReprJunkRule_repr___redArg(v_x_205_);
return v___x_207_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instReprJunkRule_repr___boxed(lean_object* v_x_208_, lean_object* v_prec_209_){
_start:
{
lean_object* v_res_210_; 
v_res_210_ = lp_JunkValues_JunkValues_instReprJunkRule_repr(v_x_208_, v_prec_209_);
lean_dec(v_prec_209_);
return v_res_210_;
}
}
LEAN_EXPORT uint8_t lp_JunkValues_Array_isEqvAux___at___00JunkValues_instBEqJunkRule_beq_spec__0___redArg(lean_object* v_xs_223_, lean_object* v_ys_224_, lean_object* v_x_225_){
_start:
{
lean_object* v_zero_226_; uint8_t v_isZero_227_; 
v_zero_226_ = lean_unsigned_to_nat(0u);
v_isZero_227_ = lean_nat_dec_eq(v_x_225_, v_zero_226_);
if (v_isZero_227_ == 1)
{
lean_dec(v_x_225_);
return v_isZero_227_;
}
else
{
lean_object* v_one_228_; lean_object* v_n_229_; lean_object* v___x_230_; lean_object* v___x_231_; uint8_t v___x_232_; 
v_one_228_ = lean_unsigned_to_nat(1u);
v_n_229_ = lean_nat_sub(v_x_225_, v_one_228_);
lean_dec(v_x_225_);
v___x_230_ = lean_array_fget_borrowed(v_xs_223_, v_n_229_);
v___x_231_ = lean_array_fget_borrowed(v_ys_224_, v_n_229_);
v___x_232_ = lean_nat_dec_eq(v___x_230_, v___x_231_);
if (v___x_232_ == 0)
{
lean_dec(v_n_229_);
return v___x_232_;
}
else
{
v_x_225_ = v_n_229_;
goto _start;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Array_isEqvAux___at___00JunkValues_instBEqJunkRule_beq_spec__0___redArg___boxed(lean_object* v_xs_234_, lean_object* v_ys_235_, lean_object* v_x_236_){
_start:
{
uint8_t v_res_237_; lean_object* v_r_238_; 
v_res_237_ = lp_JunkValues_Array_isEqvAux___at___00JunkValues_instBEqJunkRule_beq_spec__0___redArg(v_xs_234_, v_ys_235_, v_x_236_);
lean_dec_ref(v_ys_235_);
lean_dec_ref(v_xs_234_);
v_r_238_ = lean_box(v_res_237_);
return v_r_238_;
}
}
LEAN_EXPORT uint8_t lp_JunkValues_JunkValues_instBEqJunkRule_beq(lean_object* v_x_239_, lean_object* v_x_240_){
_start:
{
lean_object* v_source_241_; lean_object* v_head_242_; lean_object* v_arity_243_; lean_object* v_negatedGuards_244_; lean_object* v_generalize_245_; lean_object* v_note_246_; lean_object* v_source_247_; lean_object* v_head_248_; lean_object* v_arity_249_; lean_object* v_negatedGuards_250_; lean_object* v_generalize_251_; lean_object* v_note_252_; uint8_t v___x_253_; 
v_source_241_ = lean_ctor_get(v_x_239_, 0);
v_head_242_ = lean_ctor_get(v_x_239_, 1);
v_arity_243_ = lean_ctor_get(v_x_239_, 2);
v_negatedGuards_244_ = lean_ctor_get(v_x_239_, 3);
v_generalize_245_ = lean_ctor_get(v_x_239_, 4);
v_note_246_ = lean_ctor_get(v_x_239_, 5);
v_source_247_ = lean_ctor_get(v_x_240_, 0);
v_head_248_ = lean_ctor_get(v_x_240_, 1);
v_arity_249_ = lean_ctor_get(v_x_240_, 2);
v_negatedGuards_250_ = lean_ctor_get(v_x_240_, 3);
v_generalize_251_ = lean_ctor_get(v_x_240_, 4);
v_note_252_ = lean_ctor_get(v_x_240_, 5);
v___x_253_ = lean_name_eq(v_source_241_, v_source_247_);
if (v___x_253_ == 0)
{
return v___x_253_;
}
else
{
uint8_t v___x_254_; 
v___x_254_ = lean_name_eq(v_head_242_, v_head_248_);
if (v___x_254_ == 0)
{
return v___x_254_;
}
else
{
uint8_t v___x_255_; 
v___x_255_ = lean_nat_dec_eq(v_arity_243_, v_arity_249_);
if (v___x_255_ == 0)
{
return v___x_255_;
}
else
{
uint8_t v___x_256_; 
v___x_256_ = lean_nat_dec_eq(v_negatedGuards_244_, v_negatedGuards_250_);
if (v___x_256_ == 0)
{
return v___x_256_;
}
else
{
lean_object* v___x_257_; lean_object* v___x_258_; uint8_t v___x_259_; 
v___x_257_ = lean_array_get_size(v_generalize_245_);
v___x_258_ = lean_array_get_size(v_generalize_251_);
v___x_259_ = lean_nat_dec_eq(v___x_257_, v___x_258_);
if (v___x_259_ == 0)
{
return v___x_259_;
}
else
{
uint8_t v___x_260_; 
v___x_260_ = lp_JunkValues_Array_isEqvAux___at___00JunkValues_instBEqJunkRule_beq_spec__0___redArg(v_generalize_245_, v_generalize_251_, v___x_257_);
if (v___x_260_ == 0)
{
return v___x_260_;
}
else
{
uint8_t v___x_261_; 
v___x_261_ = lean_string_dec_eq(v_note_246_, v_note_252_);
return v___x_261_;
}
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instBEqJunkRule_beq___boxed(lean_object* v_x_262_, lean_object* v_x_263_){
_start:
{
uint8_t v_res_264_; lean_object* v_r_265_; 
v_res_264_ = lp_JunkValues_JunkValues_instBEqJunkRule_beq(v_x_262_, v_x_263_);
lean_dec_ref(v_x_263_);
lean_dec_ref(v_x_262_);
v_r_265_ = lean_box(v_res_264_);
return v_r_265_;
}
}
LEAN_EXPORT uint8_t lp_JunkValues_Array_isEqvAux___at___00JunkValues_instBEqJunkRule_beq_spec__0(lean_object* v_xs_266_, lean_object* v_ys_267_, lean_object* v_hsz_268_, lean_object* v_x_269_, lean_object* v_x_270_){
_start:
{
uint8_t v___x_271_; 
v___x_271_ = lp_JunkValues_Array_isEqvAux___at___00JunkValues_instBEqJunkRule_beq_spec__0___redArg(v_xs_266_, v_ys_267_, v_x_269_);
return v___x_271_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Array_isEqvAux___at___00JunkValues_instBEqJunkRule_beq_spec__0___boxed(lean_object* v_xs_272_, lean_object* v_ys_273_, lean_object* v_hsz_274_, lean_object* v_x_275_, lean_object* v_x_276_){
_start:
{
uint8_t v_res_277_; lean_object* v_r_278_; 
v_res_277_ = lp_JunkValues_Array_isEqvAux___at___00JunkValues_instBEqJunkRule_beq_spec__0(v_xs_272_, v_ys_273_, v_hsz_274_, v_x_275_, v_x_276_);
lean_dec_ref(v_ys_273_);
lean_dec_ref(v_xs_272_);
v_r_278_ = lean_box(v_res_277_);
return v_r_278_;
}
}
LEAN_EXPORT uint8_t lp_JunkValues_Array_instDecidableEqImpl___at___00JunkValues_instDecidableEqJunkRule_decEq_spec__0(lean_object* v_xs_281_, lean_object* v_ys_282_){
_start:
{
lean_object* v___x_283_; lean_object* v___x_284_; uint8_t v___x_285_; 
v___x_283_ = lean_array_get_size(v_xs_281_);
v___x_284_ = lean_array_get_size(v_ys_282_);
v___x_285_ = lean_nat_dec_eq(v___x_283_, v___x_284_);
if (v___x_285_ == 0)
{
return v___x_285_;
}
else
{
uint8_t v___x_286_; 
v___x_286_ = lp_JunkValues_Array_isEqvAux___at___00JunkValues_instBEqJunkRule_beq_spec__0___redArg(v_xs_281_, v_ys_282_, v___x_283_);
return v___x_286_;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Array_instDecidableEqImpl___at___00JunkValues_instDecidableEqJunkRule_decEq_spec__0___boxed(lean_object* v_xs_287_, lean_object* v_ys_288_){
_start:
{
uint8_t v_res_289_; lean_object* v_r_290_; 
v_res_289_ = lp_JunkValues_Array_instDecidableEqImpl___at___00JunkValues_instDecidableEqJunkRule_decEq_spec__0(v_xs_287_, v_ys_288_);
lean_dec_ref(v_ys_288_);
lean_dec_ref(v_xs_287_);
v_r_290_ = lean_box(v_res_289_);
return v_r_290_;
}
}
LEAN_EXPORT uint8_t lp_JunkValues_JunkValues_instDecidableEqJunkRule_decEq(lean_object* v_x_291_, lean_object* v_x_292_){
_start:
{
lean_object* v_source_293_; lean_object* v_head_294_; lean_object* v_arity_295_; lean_object* v_negatedGuards_296_; lean_object* v_generalize_297_; lean_object* v_note_298_; lean_object* v_source_299_; lean_object* v_head_300_; lean_object* v_arity_301_; lean_object* v_negatedGuards_302_; lean_object* v_generalize_303_; lean_object* v_note_304_; uint8_t v___x_305_; 
v_source_293_ = lean_ctor_get(v_x_291_, 0);
v_head_294_ = lean_ctor_get(v_x_291_, 1);
v_arity_295_ = lean_ctor_get(v_x_291_, 2);
v_negatedGuards_296_ = lean_ctor_get(v_x_291_, 3);
v_generalize_297_ = lean_ctor_get(v_x_291_, 4);
v_note_298_ = lean_ctor_get(v_x_291_, 5);
v_source_299_ = lean_ctor_get(v_x_292_, 0);
v_head_300_ = lean_ctor_get(v_x_292_, 1);
v_arity_301_ = lean_ctor_get(v_x_292_, 2);
v_negatedGuards_302_ = lean_ctor_get(v_x_292_, 3);
v_generalize_303_ = lean_ctor_get(v_x_292_, 4);
v_note_304_ = lean_ctor_get(v_x_292_, 5);
v___x_305_ = lean_name_eq(v_source_293_, v_source_299_);
if (v___x_305_ == 0)
{
return v___x_305_;
}
else
{
uint8_t v___x_306_; 
v___x_306_ = lean_name_eq(v_head_294_, v_head_300_);
if (v___x_306_ == 0)
{
return v___x_306_;
}
else
{
uint8_t v___x_307_; 
v___x_307_ = lean_nat_dec_eq(v_arity_295_, v_arity_301_);
if (v___x_307_ == 0)
{
return v___x_307_;
}
else
{
uint8_t v___x_308_; 
v___x_308_ = lean_nat_dec_eq(v_negatedGuards_296_, v_negatedGuards_302_);
if (v___x_308_ == 0)
{
return v___x_308_;
}
else
{
uint8_t v___x_309_; 
v___x_309_ = lp_JunkValues_Array_instDecidableEqImpl___at___00JunkValues_instDecidableEqJunkRule_decEq_spec__0(v_generalize_297_, v_generalize_303_);
if (v___x_309_ == 0)
{
return v___x_309_;
}
else
{
uint8_t v___x_310_; 
v___x_310_ = lean_string_dec_eq(v_note_298_, v_note_304_);
return v___x_310_;
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instDecidableEqJunkRule_decEq___boxed(lean_object* v_x_311_, lean_object* v_x_312_){
_start:
{
uint8_t v_res_313_; lean_object* v_r_314_; 
v_res_313_ = lp_JunkValues_JunkValues_instDecidableEqJunkRule_decEq(v_x_311_, v_x_312_);
lean_dec_ref(v_x_312_);
lean_dec_ref(v_x_311_);
v_r_314_ = lean_box(v_res_313_);
return v_r_314_;
}
}
LEAN_EXPORT uint8_t lp_JunkValues_JunkValues_instDecidableEqJunkRule(lean_object* v_x_315_, lean_object* v_x_316_){
_start:
{
uint8_t v___x_317_; 
v___x_317_ = lp_JunkValues_JunkValues_instDecidableEqJunkRule_decEq(v_x_315_, v_x_316_);
return v___x_317_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instDecidableEqJunkRule___boxed(lean_object* v_x_318_, lean_object* v_x_319_){
_start:
{
uint8_t v_res_320_; lean_object* v_r_321_; 
v_res_320_ = lp_JunkValues_JunkValues_instDecidableEqJunkRule(v_x_318_, v_x_319_);
lean_dec_ref(v_x_319_);
lean_dec_ref(v_x_318_);
v_r_321_ = lean_box(v_res_320_);
return v_r_321_;
}
}
LEAN_EXPORT uint64_t lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00JunkValues_instHashableJunkRule_hash_spec__0(lean_object* v_as_322_, size_t v_i_323_, size_t v_stop_324_, uint64_t v_b_325_){
_start:
{
uint8_t v___x_326_; 
v___x_326_ = lean_usize_dec_eq(v_i_323_, v_stop_324_);
if (v___x_326_ == 0)
{
lean_object* v___x_327_; uint64_t v___x_328_; uint64_t v___x_329_; size_t v___x_330_; size_t v___x_331_; 
v___x_327_ = lean_array_uget_borrowed(v_as_322_, v_i_323_);
v___x_328_ = lean_uint64_of_nat(v___x_327_);
v___x_329_ = lean_uint64_mix_hash(v_b_325_, v___x_328_);
v___x_330_ = ((size_t)1ULL);
v___x_331_ = lean_usize_add(v_i_323_, v___x_330_);
v_i_323_ = v___x_331_;
v_b_325_ = v___x_329_;
goto _start;
}
else
{
return v_b_325_;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00JunkValues_instHashableJunkRule_hash_spec__0___boxed(lean_object* v_as_333_, lean_object* v_i_334_, lean_object* v_stop_335_, lean_object* v_b_336_){
_start:
{
size_t v_i_boxed_337_; size_t v_stop_boxed_338_; uint64_t v_b_boxed_339_; uint64_t v_res_340_; lean_object* v_r_341_; 
v_i_boxed_337_ = lean_unbox_usize(v_i_334_);
lean_dec(v_i_334_);
v_stop_boxed_338_ = lean_unbox_usize(v_stop_335_);
lean_dec(v_stop_335_);
v_b_boxed_339_ = lean_unbox_uint64(v_b_336_);
lean_dec_ref(v_b_336_);
v_res_340_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00JunkValues_instHashableJunkRule_hash_spec__0(v_as_333_, v_i_boxed_337_, v_stop_boxed_338_, v_b_boxed_339_);
lean_dec_ref(v_as_333_);
v_r_341_ = lean_box_uint64(v_res_340_);
return v_r_341_;
}
}
static uint64_t _init_lp_JunkValues_JunkValues_instHashableJunkRule_hash___closed__0(void){
_start:
{
lean_object* v___x_342_; uint64_t v___x_343_; 
v___x_342_ = lean_unsigned_to_nat(1723u);
v___x_343_ = lean_uint64_of_nat(v___x_342_);
return v___x_343_;
}
}
LEAN_EXPORT uint64_t lp_JunkValues_JunkValues_instHashableJunkRule_hash(lean_object* v_x_344_){
_start:
{
lean_object* v_source_345_; lean_object* v_head_346_; lean_object* v_arity_347_; lean_object* v_negatedGuards_348_; lean_object* v_generalize_349_; lean_object* v_note_350_; uint64_t v___y_352_; uint64_t v___y_353_; uint64_t v___y_358_; uint64_t v___y_359_; uint64_t v___x_376_; uint64_t v___y_378_; 
v_source_345_ = lean_ctor_get(v_x_344_, 0);
v_head_346_ = lean_ctor_get(v_x_344_, 1);
v_arity_347_ = lean_ctor_get(v_x_344_, 2);
v_negatedGuards_348_ = lean_ctor_get(v_x_344_, 3);
v_generalize_349_ = lean_ctor_get(v_x_344_, 4);
v_note_350_ = lean_ctor_get(v_x_344_, 5);
v___x_376_ = 0ULL;
if (lean_obj_tag(v_source_345_) == 0)
{
uint64_t v___x_382_; 
v___x_382_ = lean_uint64_once(&lp_JunkValues_JunkValues_instHashableJunkRule_hash___closed__0, &lp_JunkValues_JunkValues_instHashableJunkRule_hash___closed__0_once, _init_lp_JunkValues_JunkValues_instHashableJunkRule_hash___closed__0);
v___y_378_ = v___x_382_;
goto v___jp_377_;
}
else
{
uint64_t v_hash_383_; 
v_hash_383_ = lean_ctor_get_uint64(v_source_345_, sizeof(void*)*2);
v___y_378_ = v_hash_383_;
goto v___jp_377_;
}
v___jp_351_:
{
uint64_t v___x_354_; uint64_t v___x_355_; uint64_t v___x_356_; 
v___x_354_ = lean_uint64_mix_hash(v___y_352_, v___y_353_);
v___x_355_ = lean_string_hash(v_note_350_);
v___x_356_ = lean_uint64_mix_hash(v___x_354_, v___x_355_);
return v___x_356_;
}
v___jp_357_:
{
uint64_t v___x_360_; uint64_t v___x_361_; uint64_t v___x_362_; uint64_t v___x_363_; uint64_t v___x_364_; uint64_t v___x_365_; lean_object* v___x_366_; lean_object* v___x_367_; uint8_t v___x_368_; 
v___x_360_ = lean_uint64_mix_hash(v___y_358_, v___y_359_);
v___x_361_ = lean_uint64_of_nat(v_arity_347_);
v___x_362_ = lean_uint64_mix_hash(v___x_360_, v___x_361_);
v___x_363_ = lean_uint64_of_nat(v_negatedGuards_348_);
v___x_364_ = lean_uint64_mix_hash(v___x_362_, v___x_363_);
v___x_365_ = 7ULL;
v___x_366_ = lean_unsigned_to_nat(0u);
v___x_367_ = lean_array_get_size(v_generalize_349_);
v___x_368_ = lean_nat_dec_lt(v___x_366_, v___x_367_);
if (v___x_368_ == 0)
{
v___y_352_ = v___x_364_;
v___y_353_ = v___x_365_;
goto v___jp_351_;
}
else
{
uint8_t v___x_369_; 
v___x_369_ = lean_nat_dec_le(v___x_367_, v___x_367_);
if (v___x_369_ == 0)
{
if (v___x_368_ == 0)
{
v___y_352_ = v___x_364_;
v___y_353_ = v___x_365_;
goto v___jp_351_;
}
else
{
size_t v___x_370_; size_t v___x_371_; uint64_t v___x_372_; 
v___x_370_ = ((size_t)0ULL);
v___x_371_ = lean_usize_of_nat(v___x_367_);
v___x_372_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00JunkValues_instHashableJunkRule_hash_spec__0(v_generalize_349_, v___x_370_, v___x_371_, v___x_365_);
v___y_352_ = v___x_364_;
v___y_353_ = v___x_372_;
goto v___jp_351_;
}
}
else
{
size_t v___x_373_; size_t v___x_374_; uint64_t v___x_375_; 
v___x_373_ = ((size_t)0ULL);
v___x_374_ = lean_usize_of_nat(v___x_367_);
v___x_375_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00JunkValues_instHashableJunkRule_hash_spec__0(v_generalize_349_, v___x_373_, v___x_374_, v___x_365_);
v___y_352_ = v___x_364_;
v___y_353_ = v___x_375_;
goto v___jp_351_;
}
}
}
v___jp_377_:
{
uint64_t v___x_379_; 
v___x_379_ = lean_uint64_mix_hash(v___x_376_, v___y_378_);
if (lean_obj_tag(v_head_346_) == 0)
{
uint64_t v___x_380_; 
v___x_380_ = lean_uint64_once(&lp_JunkValues_JunkValues_instHashableJunkRule_hash___closed__0, &lp_JunkValues_JunkValues_instHashableJunkRule_hash___closed__0_once, _init_lp_JunkValues_JunkValues_instHashableJunkRule_hash___closed__0);
v___y_358_ = v___x_379_;
v___y_359_ = v___x_380_;
goto v___jp_357_;
}
else
{
uint64_t v_hash_381_; 
v_hash_381_ = lean_ctor_get_uint64(v_head_346_, sizeof(void*)*2);
v___y_358_ = v___x_379_;
v___y_359_ = v_hash_381_;
goto v___jp_357_;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instHashableJunkRule_hash___boxed(lean_object* v_x_384_){
_start:
{
uint64_t v_res_385_; lean_object* v_r_386_; 
v_res_385_ = lp_JunkValues_JunkValues_instHashableJunkRule_hash(v_x_384_);
lean_dec_ref(v_x_384_);
v_r_386_ = lean_box_uint64(v_res_385_);
return v_r_386_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_List_mapM_loop___at___00JunkValues_openRule_spec__0(lean_object* v_x_389_, lean_object* v_x_390_, lean_object* v___y_391_, lean_object* v___y_392_, lean_object* v___y_393_, lean_object* v___y_394_){
_start:
{
if (lean_obj_tag(v_x_389_) == 0)
{
lean_object* v___x_396_; lean_object* v___x_397_; 
v___x_396_ = l_List_reverse___redArg(v_x_390_);
v___x_397_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_397_, 0, v___x_396_);
return v___x_397_;
}
else
{
lean_object* v_tail_398_; lean_object* v___x_400_; uint8_t v_isShared_401_; uint8_t v_isSharedCheck_416_; 
v_tail_398_ = lean_ctor_get(v_x_389_, 1);
v_isSharedCheck_416_ = !lean_is_exclusive(v_x_389_);
if (v_isSharedCheck_416_ == 0)
{
lean_object* v_unused_417_; 
v_unused_417_ = lean_ctor_get(v_x_389_, 0);
lean_dec(v_unused_417_);
v___x_400_ = v_x_389_;
v_isShared_401_ = v_isSharedCheck_416_;
goto v_resetjp_399_;
}
else
{
lean_inc(v_tail_398_);
lean_dec(v_x_389_);
v___x_400_ = lean_box(0);
v_isShared_401_ = v_isSharedCheck_416_;
goto v_resetjp_399_;
}
v_resetjp_399_:
{
lean_object* v___x_402_; 
v___x_402_ = l_Lean_Meta_mkFreshLevelMVar(v___y_391_, v___y_392_, v___y_393_, v___y_394_);
if (lean_obj_tag(v___x_402_) == 0)
{
lean_object* v_a_403_; lean_object* v___x_405_; 
v_a_403_ = lean_ctor_get(v___x_402_, 0);
lean_inc(v_a_403_);
lean_dec_ref_known(v___x_402_, 1);
if (v_isShared_401_ == 0)
{
lean_ctor_set(v___x_400_, 1, v_x_390_);
lean_ctor_set(v___x_400_, 0, v_a_403_);
v___x_405_ = v___x_400_;
goto v_reusejp_404_;
}
else
{
lean_object* v_reuseFailAlloc_407_; 
v_reuseFailAlloc_407_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_407_, 0, v_a_403_);
lean_ctor_set(v_reuseFailAlloc_407_, 1, v_x_390_);
v___x_405_ = v_reuseFailAlloc_407_;
goto v_reusejp_404_;
}
v_reusejp_404_:
{
v_x_389_ = v_tail_398_;
v_x_390_ = v___x_405_;
goto _start;
}
}
else
{
lean_object* v_a_408_; lean_object* v___x_410_; uint8_t v_isShared_411_; uint8_t v_isSharedCheck_415_; 
lean_del_object(v___x_400_);
lean_dec(v_tail_398_);
lean_dec(v_x_390_);
v_a_408_ = lean_ctor_get(v___x_402_, 0);
v_isSharedCheck_415_ = !lean_is_exclusive(v___x_402_);
if (v_isSharedCheck_415_ == 0)
{
v___x_410_ = v___x_402_;
v_isShared_411_ = v_isSharedCheck_415_;
goto v_resetjp_409_;
}
else
{
lean_inc(v_a_408_);
lean_dec(v___x_402_);
v___x_410_ = lean_box(0);
v_isShared_411_ = v_isSharedCheck_415_;
goto v_resetjp_409_;
}
v_resetjp_409_:
{
lean_object* v___x_413_; 
if (v_isShared_411_ == 0)
{
v___x_413_ = v___x_410_;
goto v_reusejp_412_;
}
else
{
lean_object* v_reuseFailAlloc_414_; 
v_reuseFailAlloc_414_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_414_, 0, v_a_408_);
v___x_413_ = v_reuseFailAlloc_414_;
goto v_reusejp_412_;
}
v_reusejp_412_:
{
return v___x_413_;
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_List_mapM_loop___at___00JunkValues_openRule_spec__0___boxed(lean_object* v_x_418_, lean_object* v_x_419_, lean_object* v___y_420_, lean_object* v___y_421_, lean_object* v___y_422_, lean_object* v___y_423_, lean_object* v___y_424_){
_start:
{
lean_object* v_res_425_; 
v_res_425_ = lp_JunkValues_List_mapM_loop___at___00JunkValues_openRule_spec__0(v_x_418_, v_x_419_, v___y_420_, v___y_421_, v___y_422_, v___y_423_);
lean_dec(v___y_423_);
lean_dec_ref(v___y_422_);
lean_dec(v___y_421_);
lean_dec_ref(v___y_420_);
return v_res_425_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_openRule(lean_object* v_thm_429_, lean_object* v_a_430_, lean_object* v_a_431_, lean_object* v_a_432_, lean_object* v_a_433_){
_start:
{
lean_object* v___x_435_; lean_object* v_env_436_; uint8_t v___x_437_; lean_object* v___x_438_; 
v___x_435_ = lean_st_ref_get(v_a_433_);
v_env_436_ = lean_ctor_get(v___x_435_, 0);
lean_inc_ref(v_env_436_);
lean_dec(v___x_435_);
v___x_437_ = 0;
v___x_438_ = l_Lean_Environment_find_x3f(v_env_436_, v_thm_429_, v___x_437_);
if (lean_obj_tag(v___x_438_) == 1)
{
lean_object* v_val_439_; lean_object* v___x_441_; uint8_t v_isShared_442_; uint8_t v_isSharedCheck_493_; 
v_val_439_ = lean_ctor_get(v___x_438_, 0);
v_isSharedCheck_493_ = !lean_is_exclusive(v___x_438_);
if (v_isSharedCheck_493_ == 0)
{
v___x_441_ = v___x_438_;
v_isShared_442_ = v_isSharedCheck_493_;
goto v_resetjp_440_;
}
else
{
lean_inc(v_val_439_);
lean_dec(v___x_438_);
v___x_441_ = lean_box(0);
v_isShared_442_ = v_isSharedCheck_493_;
goto v_resetjp_440_;
}
v_resetjp_440_:
{
lean_object* v___x_443_; lean_object* v___x_444_; lean_object* v___x_445_; 
v___x_443_ = l_Lean_ConstantInfo_levelParams(v_val_439_);
v___x_444_ = lean_box(0);
lean_inc(v___x_443_);
v___x_445_ = lp_JunkValues_List_mapM_loop___at___00JunkValues_openRule_spec__0(v___x_443_, v___x_444_, v_a_430_, v_a_431_, v_a_432_, v_a_433_);
if (lean_obj_tag(v___x_445_) == 0)
{
lean_object* v_a_446_; lean_object* v___x_447_; lean_object* v___x_448_; uint8_t v___x_449_; lean_object* v___x_450_; 
v_a_446_ = lean_ctor_get(v___x_445_, 0);
lean_inc(v_a_446_);
lean_dec_ref_known(v___x_445_, 1);
v___x_447_ = l_Lean_ConstantInfo_type(v_val_439_);
lean_dec(v_val_439_);
v___x_448_ = l_Lean_Expr_instantiateLevelParams(v___x_447_, v___x_443_, v_a_446_);
lean_dec_ref(v___x_447_);
v___x_449_ = 0;
v___x_450_ = l_Lean_Meta_forallMetaTelescope(v___x_448_, v___x_449_, v_a_430_, v_a_431_, v_a_432_, v_a_433_);
if (lean_obj_tag(v___x_450_) == 0)
{
lean_object* v_a_451_; lean_object* v___x_453_; uint8_t v_isShared_454_; uint8_t v_isSharedCheck_476_; 
v_a_451_ = lean_ctor_get(v___x_450_, 0);
v_isSharedCheck_476_ = !lean_is_exclusive(v___x_450_);
if (v_isSharedCheck_476_ == 0)
{
v___x_453_ = v___x_450_;
v_isShared_454_ = v_isSharedCheck_476_;
goto v_resetjp_452_;
}
else
{
lean_inc(v_a_451_);
lean_dec(v___x_450_);
v___x_453_ = lean_box(0);
v_isShared_454_ = v_isSharedCheck_476_;
goto v_resetjp_452_;
}
v_resetjp_452_:
{
lean_object* v_snd_455_; lean_object* v_fst_456_; lean_object* v_fst_457_; lean_object* v_snd_458_; lean_object* v___x_459_; lean_object* v___x_460_; uint8_t v___x_461_; 
v_snd_455_ = lean_ctor_get(v_a_451_, 1);
lean_inc(v_snd_455_);
v_fst_456_ = lean_ctor_get(v_a_451_, 0);
lean_inc(v_fst_456_);
lean_dec(v_a_451_);
v_fst_457_ = lean_ctor_get(v_snd_455_, 0);
lean_inc(v_fst_457_);
v_snd_458_ = lean_ctor_get(v_snd_455_, 1);
lean_inc(v_snd_458_);
lean_dec(v_snd_455_);
v___x_459_ = ((lean_object*)(lp_JunkValues_JunkValues_openRule___closed__1));
v___x_460_ = lean_unsigned_to_nat(3u);
v___x_461_ = l_Lean_Expr_isAppOfArity(v_snd_458_, v___x_459_, v___x_460_);
if (v___x_461_ == 0)
{
lean_object* v___x_462_; lean_object* v___x_464_; 
lean_dec(v_snd_458_);
lean_dec(v_fst_457_);
lean_dec(v_fst_456_);
lean_del_object(v___x_441_);
v___x_462_ = lean_box(0);
if (v_isShared_454_ == 0)
{
lean_ctor_set(v___x_453_, 0, v___x_462_);
v___x_464_ = v___x_453_;
goto v_reusejp_463_;
}
else
{
lean_object* v_reuseFailAlloc_465_; 
v_reuseFailAlloc_465_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_465_, 0, v___x_462_);
v___x_464_ = v_reuseFailAlloc_465_;
goto v_reusejp_463_;
}
v_reusejp_463_:
{
return v___x_464_;
}
}
else
{
lean_object* v___x_466_; lean_object* v___x_467_; lean_object* v___x_468_; lean_object* v___x_469_; lean_object* v___x_471_; 
v___x_466_ = l_Lean_Expr_appFn_x21(v_snd_458_);
v___x_467_ = l_Lean_Expr_appArg_x21(v___x_466_);
lean_dec_ref(v___x_466_);
v___x_468_ = l_Lean_Expr_appArg_x21(v_snd_458_);
lean_dec(v_snd_458_);
v___x_469_ = lean_alloc_ctor(0, 4, 0);
lean_ctor_set(v___x_469_, 0, v_fst_456_);
lean_ctor_set(v___x_469_, 1, v_fst_457_);
lean_ctor_set(v___x_469_, 2, v___x_467_);
lean_ctor_set(v___x_469_, 3, v___x_468_);
if (v_isShared_442_ == 0)
{
lean_ctor_set(v___x_441_, 0, v___x_469_);
v___x_471_ = v___x_441_;
goto v_reusejp_470_;
}
else
{
lean_object* v_reuseFailAlloc_475_; 
v_reuseFailAlloc_475_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_475_, 0, v___x_469_);
v___x_471_ = v_reuseFailAlloc_475_;
goto v_reusejp_470_;
}
v_reusejp_470_:
{
lean_object* v___x_473_; 
if (v_isShared_454_ == 0)
{
lean_ctor_set(v___x_453_, 0, v___x_471_);
v___x_473_ = v___x_453_;
goto v_reusejp_472_;
}
else
{
lean_object* v_reuseFailAlloc_474_; 
v_reuseFailAlloc_474_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_474_, 0, v___x_471_);
v___x_473_ = v_reuseFailAlloc_474_;
goto v_reusejp_472_;
}
v_reusejp_472_:
{
return v___x_473_;
}
}
}
}
}
else
{
lean_object* v_a_477_; lean_object* v___x_479_; uint8_t v_isShared_480_; uint8_t v_isSharedCheck_484_; 
lean_del_object(v___x_441_);
v_a_477_ = lean_ctor_get(v___x_450_, 0);
v_isSharedCheck_484_ = !lean_is_exclusive(v___x_450_);
if (v_isSharedCheck_484_ == 0)
{
v___x_479_ = v___x_450_;
v_isShared_480_ = v_isSharedCheck_484_;
goto v_resetjp_478_;
}
else
{
lean_inc(v_a_477_);
lean_dec(v___x_450_);
v___x_479_ = lean_box(0);
v_isShared_480_ = v_isSharedCheck_484_;
goto v_resetjp_478_;
}
v_resetjp_478_:
{
lean_object* v___x_482_; 
if (v_isShared_480_ == 0)
{
v___x_482_ = v___x_479_;
goto v_reusejp_481_;
}
else
{
lean_object* v_reuseFailAlloc_483_; 
v_reuseFailAlloc_483_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_483_, 0, v_a_477_);
v___x_482_ = v_reuseFailAlloc_483_;
goto v_reusejp_481_;
}
v_reusejp_481_:
{
return v___x_482_;
}
}
}
}
else
{
lean_object* v_a_485_; lean_object* v___x_487_; uint8_t v_isShared_488_; uint8_t v_isSharedCheck_492_; 
lean_dec(v___x_443_);
lean_del_object(v___x_441_);
lean_dec(v_val_439_);
v_a_485_ = lean_ctor_get(v___x_445_, 0);
v_isSharedCheck_492_ = !lean_is_exclusive(v___x_445_);
if (v_isSharedCheck_492_ == 0)
{
v___x_487_ = v___x_445_;
v_isShared_488_ = v_isSharedCheck_492_;
goto v_resetjp_486_;
}
else
{
lean_inc(v_a_485_);
lean_dec(v___x_445_);
v___x_487_ = lean_box(0);
v_isShared_488_ = v_isSharedCheck_492_;
goto v_resetjp_486_;
}
v_resetjp_486_:
{
lean_object* v___x_490_; 
if (v_isShared_488_ == 0)
{
v___x_490_ = v___x_487_;
goto v_reusejp_489_;
}
else
{
lean_object* v_reuseFailAlloc_491_; 
v_reuseFailAlloc_491_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_491_, 0, v_a_485_);
v___x_490_ = v_reuseFailAlloc_491_;
goto v_reusejp_489_;
}
v_reusejp_489_:
{
return v___x_490_;
}
}
}
}
}
else
{
lean_object* v___x_494_; lean_object* v___x_495_; 
lean_dec(v___x_438_);
v___x_494_ = lean_box(0);
v___x_495_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_495_, 0, v___x_494_);
return v___x_495_;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_openRule___boxed(lean_object* v_thm_496_, lean_object* v_a_497_, lean_object* v_a_498_, lean_object* v_a_499_, lean_object* v_a_500_, lean_object* v_a_501_){
_start:
{
lean_object* v_res_502_; 
v_res_502_ = lp_JunkValues_JunkValues_openRule(v_thm_496_, v_a_497_, v_a_498_, v_a_499_, v_a_500_);
lean_dec(v_a_500_);
lean_dec_ref(v_a_499_);
lean_dec(v_a_498_);
lean_dec_ref(v_a_497_);
return v_res_502_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_isGuardBinder(uint8_t v_bi_503_, lean_object* v_binderType_504_, lean_object* v_a_505_, lean_object* v_a_506_, lean_object* v_a_507_, lean_object* v_a_508_){
_start:
{
if (v_bi_503_ == 3)
{
uint8_t v___x_510_; lean_object* v___x_511_; lean_object* v___x_512_; 
lean_dec_ref(v_binderType_504_);
v___x_510_ = 0;
v___x_511_ = lean_box(v___x_510_);
v___x_512_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_512_, 0, v___x_511_);
return v___x_512_;
}
else
{
lean_object* v___x_513_; 
v___x_513_ = l_Lean_Meta_isProp(v_binderType_504_, v_a_505_, v_a_506_, v_a_507_, v_a_508_);
return v___x_513_;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_isGuardBinder___boxed(lean_object* v_bi_514_, lean_object* v_binderType_515_, lean_object* v_a_516_, lean_object* v_a_517_, lean_object* v_a_518_, lean_object* v_a_519_, lean_object* v_a_520_){
_start:
{
uint8_t v_bi_boxed_521_; lean_object* v_res_522_; 
v_bi_boxed_521_ = lean_unbox(v_bi_514_);
v_res_522_ = lp_JunkValues_JunkValues_isGuardBinder(v_bi_boxed_521_, v_binderType_515_, v_a_516_, v_a_517_, v_a_518_, v_a_519_);
lean_dec(v_a_519_);
lean_dec_ref(v_a_518_);
lean_dec(v_a_517_);
lean_dec_ref(v_a_516_);
return v_res_522_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_headConst_x3f(lean_object* v_e_523_){
_start:
{
lean_object* v___x_524_; 
v___x_524_ = l_Lean_Expr_getAppFn(v_e_523_);
if (lean_obj_tag(v___x_524_) == 4)
{
lean_object* v_declName_525_; lean_object* v___x_526_; 
v_declName_525_ = lean_ctor_get(v___x_524_, 0);
lean_inc(v_declName_525_);
lean_dec_ref_known(v___x_524_, 2);
v___x_526_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_526_, 0, v_declName_525_);
return v___x_526_;
}
else
{
lean_object* v___x_527_; 
lean_dec_ref(v___x_524_);
v___x_527_ = lean_box(0);
return v___x_527_;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_headConst_x3f___boxed(lean_object* v_e_528_){
_start:
{
lean_object* v_res_529_; 
v_res_529_ = lp_JunkValues_JunkValues_headConst_x3f(v_e_528_);
lean_dec_ref(v_e_528_);
return v_res_529_;
}
}
LEAN_EXPORT uint8_t lp_JunkValues_JunkValues_isNegatedProp(lean_object* v_p_532_){
_start:
{
if (lean_obj_tag(v_p_532_) == 5)
{
lean_object* v_fn_533_; 
v_fn_533_ = lean_ctor_get(v_p_532_, 0);
switch(lean_obj_tag(v_fn_533_))
{
case 4:
{
lean_object* v_declName_534_; 
v_declName_534_ = lean_ctor_get(v_fn_533_, 0);
if (lean_obj_tag(v_declName_534_) == 1)
{
lean_object* v_pre_535_; 
v_pre_535_ = lean_ctor_get(v_declName_534_, 0);
if (lean_obj_tag(v_pre_535_) == 0)
{
lean_object* v_us_536_; lean_object* v_str_537_; lean_object* v___x_538_; uint8_t v___x_539_; 
v_us_536_ = lean_ctor_get(v_fn_533_, 1);
v_str_537_ = lean_ctor_get(v_declName_534_, 1);
v___x_538_ = ((lean_object*)(lp_JunkValues_JunkValues_isNegatedProp___closed__0));
v___x_539_ = lean_string_dec_eq(v_str_537_, v___x_538_);
if (v___x_539_ == 0)
{
return v___x_539_;
}
else
{
if (lean_obj_tag(v_us_536_) == 0)
{
return v___x_539_;
}
else
{
uint8_t v___x_540_; 
v___x_540_ = 0;
return v___x_540_;
}
}
}
else
{
uint8_t v___x_541_; 
v___x_541_ = 0;
return v___x_541_;
}
}
else
{
uint8_t v___x_542_; 
v___x_542_ = 0;
return v___x_542_;
}
}
case 5:
{
lean_object* v_fn_543_; 
v_fn_543_ = lean_ctor_get(v_fn_533_, 0);
if (lean_obj_tag(v_fn_543_) == 5)
{
lean_object* v_fn_544_; 
v_fn_544_ = lean_ctor_get(v_fn_543_, 0);
if (lean_obj_tag(v_fn_544_) == 4)
{
lean_object* v_declName_545_; 
v_declName_545_ = lean_ctor_get(v_fn_544_, 0);
if (lean_obj_tag(v_declName_545_) == 1)
{
lean_object* v_pre_546_; 
v_pre_546_ = lean_ctor_get(v_declName_545_, 0);
if (lean_obj_tag(v_pre_546_) == 0)
{
lean_object* v_str_547_; lean_object* v___x_548_; uint8_t v___x_549_; 
v_str_547_ = lean_ctor_get(v_declName_545_, 1);
v___x_548_ = ((lean_object*)(lp_JunkValues_JunkValues_isNegatedProp___closed__1));
v___x_549_ = lean_string_dec_eq(v_str_547_, v___x_548_);
return v___x_549_;
}
else
{
uint8_t v___x_550_; 
v___x_550_ = 0;
return v___x_550_;
}
}
else
{
uint8_t v___x_551_; 
v___x_551_ = 0;
return v___x_551_;
}
}
else
{
uint8_t v___x_552_; 
v___x_552_ = 0;
return v___x_552_;
}
}
else
{
uint8_t v___x_553_; 
v___x_553_ = 0;
return v___x_553_;
}
}
default: 
{
uint8_t v___x_554_; 
v___x_554_ = 0;
return v___x_554_;
}
}
}
else
{
uint8_t v___x_555_; 
v___x_555_ = 0;
return v___x_555_;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_isNegatedProp___boxed(lean_object* v_p_556_){
_start:
{
uint8_t v_res_557_; lean_object* v_r_558_; 
v_res_557_ = lp_JunkValues_JunkValues_isNegatedProp(v_p_556_);
lean_dec_ref(v_p_556_);
v_r_558_ = lean_box(v_res_557_);
return v_r_558_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00JunkValues_explicitArgIndices_spec__0___redArg(lean_object* v_a_559_, lean_object* v_range_560_, lean_object* v_b_561_, lean_object* v_i_562_){
_start:
{
lean_object* v_stop_564_; lean_object* v_step_565_; lean_object* v_a_567_; uint8_t v___x_570_; 
v_stop_564_ = lean_ctor_get(v_range_560_, 1);
v_step_565_ = lean_ctor_get(v_range_560_, 2);
v___x_570_ = lean_nat_dec_lt(v_i_562_, v_stop_564_);
if (v___x_570_ == 0)
{
lean_object* v___x_571_; 
lean_dec(v_i_562_);
v___x_571_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_571_, 0, v_b_561_);
return v___x_571_;
}
else
{
lean_object* v_paramInfo_572_; lean_object* v___x_573_; uint8_t v___x_574_; 
v_paramInfo_572_ = lean_ctor_get(v_a_559_, 0);
v___x_573_ = lean_array_get_size(v_paramInfo_572_);
v___x_574_ = lean_nat_dec_lt(v_i_562_, v___x_573_);
if (v___x_574_ == 0)
{
v_a_567_ = v_b_561_;
goto v___jp_566_;
}
else
{
lean_object* v___x_575_; uint8_t v_binderInfo_576_; 
v___x_575_ = lean_array_fget_borrowed(v_paramInfo_572_, v_i_562_);
v_binderInfo_576_ = lean_ctor_get_uint8(v___x_575_, sizeof(void*)*1);
if (v_binderInfo_576_ == 0)
{
lean_object* v___x_577_; 
lean_inc(v_i_562_);
v___x_577_ = lean_array_push(v_b_561_, v_i_562_);
v_a_567_ = v___x_577_;
goto v___jp_566_;
}
else
{
v_a_567_ = v_b_561_;
goto v___jp_566_;
}
}
}
v___jp_566_:
{
lean_object* v___x_568_; 
v___x_568_ = lean_nat_add(v_i_562_, v_step_565_);
lean_dec(v_i_562_);
v_b_561_ = v_a_567_;
v_i_562_ = v___x_568_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00JunkValues_explicitArgIndices_spec__0___redArg___boxed(lean_object* v_a_578_, lean_object* v_range_579_, lean_object* v_b_580_, lean_object* v_i_581_, lean_object* v___y_582_){
_start:
{
lean_object* v_res_583_; 
v_res_583_ = lp_JunkValues___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00JunkValues_explicitArgIndices_spec__0___redArg(v_a_578_, v_range_579_, v_b_580_, v_i_581_);
lean_dec_ref(v_range_579_);
lean_dec_ref(v_a_578_);
return v_res_583_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_explicitArgIndices___closed__0(void){
_start:
{
lean_object* v___x_584_; lean_object* v_dummy_585_; 
v___x_584_ = lean_box(0);
v_dummy_585_ = l_Lean_Expr_sort___override(v___x_584_);
return v_dummy_585_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_explicitArgIndices(lean_object* v_e_586_, lean_object* v_a_587_, lean_object* v_a_588_, lean_object* v_a_589_, lean_object* v_a_590_){
_start:
{
lean_object* v_dummy_592_; lean_object* v_nargs_593_; lean_object* v___x_594_; lean_object* v___x_595_; lean_object* v___x_596_; lean_object* v_args_597_; lean_object* v___x_598_; lean_object* v___x_599_; lean_object* v___x_600_; 
v_dummy_592_ = lean_obj_once(&lp_JunkValues_JunkValues_explicitArgIndices___closed__0, &lp_JunkValues_JunkValues_explicitArgIndices___closed__0_once, _init_lp_JunkValues_JunkValues_explicitArgIndices___closed__0);
v_nargs_593_ = l_Lean_Expr_getAppNumArgs(v_e_586_);
lean_inc(v_nargs_593_);
v___x_594_ = lean_mk_array(v_nargs_593_, v_dummy_592_);
v___x_595_ = lean_unsigned_to_nat(1u);
v___x_596_ = lean_nat_sub(v_nargs_593_, v___x_595_);
lean_dec(v_nargs_593_);
lean_inc_ref(v_e_586_);
v_args_597_ = l___private_Lean_Expr_0__Lean_Expr_getAppArgsAux(v_e_586_, v___x_594_, v___x_596_);
v___x_598_ = l_Lean_Expr_getAppFn(v_e_586_);
lean_dec_ref(v_e_586_);
v___x_599_ = lean_array_get_size(v_args_597_);
lean_dec_ref(v_args_597_);
v___x_600_ = l_Lean_Meta_getFunInfoNArgs(v___x_598_, v___x_599_, v_a_587_, v_a_588_, v_a_589_, v_a_590_);
if (lean_obj_tag(v___x_600_) == 0)
{
lean_object* v_a_601_; lean_object* v___x_602_; lean_object* v___x_603_; lean_object* v___x_604_; lean_object* v___x_605_; 
v_a_601_ = lean_ctor_get(v___x_600_, 0);
lean_inc(v_a_601_);
lean_dec_ref_known(v___x_600_, 1);
v___x_602_ = lean_unsigned_to_nat(0u);
v___x_603_ = ((lean_object*)(lp_JunkValues_JunkValues_instInhabitedJunkRule_default___closed__0));
v___x_604_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_604_, 0, v___x_602_);
lean_ctor_set(v___x_604_, 1, v___x_599_);
lean_ctor_set(v___x_604_, 2, v___x_595_);
v___x_605_ = lp_JunkValues___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00JunkValues_explicitArgIndices_spec__0___redArg(v_a_601_, v___x_604_, v___x_603_, v___x_602_);
lean_dec_ref_known(v___x_604_, 3);
lean_dec(v_a_601_);
return v___x_605_;
}
else
{
lean_object* v_a_606_; lean_object* v___x_608_; uint8_t v_isShared_609_; uint8_t v_isSharedCheck_613_; 
v_a_606_ = lean_ctor_get(v___x_600_, 0);
v_isSharedCheck_613_ = !lean_is_exclusive(v___x_600_);
if (v_isSharedCheck_613_ == 0)
{
v___x_608_ = v___x_600_;
v_isShared_609_ = v_isSharedCheck_613_;
goto v_resetjp_607_;
}
else
{
lean_inc(v_a_606_);
lean_dec(v___x_600_);
v___x_608_ = lean_box(0);
v_isShared_609_ = v_isSharedCheck_613_;
goto v_resetjp_607_;
}
v_resetjp_607_:
{
lean_object* v___x_611_; 
if (v_isShared_609_ == 0)
{
v___x_611_ = v___x_608_;
goto v_reusejp_610_;
}
else
{
lean_object* v_reuseFailAlloc_612_; 
v_reuseFailAlloc_612_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_612_, 0, v_a_606_);
v___x_611_ = v_reuseFailAlloc_612_;
goto v_reusejp_610_;
}
v_reusejp_610_:
{
return v___x_611_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_explicitArgIndices___boxed(lean_object* v_e_614_, lean_object* v_a_615_, lean_object* v_a_616_, lean_object* v_a_617_, lean_object* v_a_618_, lean_object* v_a_619_){
_start:
{
lean_object* v_res_620_; 
v_res_620_ = lp_JunkValues_JunkValues_explicitArgIndices(v_e_614_, v_a_615_, v_a_616_, v_a_617_, v_a_618_);
lean_dec(v_a_618_);
lean_dec_ref(v_a_617_);
lean_dec(v_a_616_);
lean_dec_ref(v_a_615_);
return v_res_620_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00JunkValues_explicitArgIndices_spec__0(lean_object* v_a_621_, lean_object* v_range_622_, lean_object* v_b_623_, lean_object* v_i_624_, lean_object* v_hs_625_, lean_object* v_hl_626_, lean_object* v___y_627_, lean_object* v___y_628_, lean_object* v___y_629_, lean_object* v___y_630_){
_start:
{
lean_object* v___x_632_; 
v___x_632_ = lp_JunkValues___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00JunkValues_explicitArgIndices_spec__0___redArg(v_a_621_, v_range_622_, v_b_623_, v_i_624_);
return v___x_632_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00JunkValues_explicitArgIndices_spec__0___boxed(lean_object* v_a_633_, lean_object* v_range_634_, lean_object* v_b_635_, lean_object* v_i_636_, lean_object* v_hs_637_, lean_object* v_hl_638_, lean_object* v___y_639_, lean_object* v___y_640_, lean_object* v___y_641_, lean_object* v___y_642_, lean_object* v___y_643_){
_start:
{
lean_object* v_res_644_; 
v_res_644_ = lp_JunkValues___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00JunkValues_explicitArgIndices_spec__0(v_a_633_, v_range_634_, v_b_635_, v_i_636_, v_hs_637_, v_hl_638_, v___y_639_, v___y_640_, v___y_641_, v___y_642_);
lean_dec(v___y_642_);
lean_dec_ref(v___y_641_);
lean_dec(v___y_640_);
lean_dec_ref(v___y_639_);
lean_dec_ref(v_range_634_);
lean_dec_ref(v_a_633_);
return v_res_644_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00JunkValues_ruleOfTheorem_x3f_spec__0___redArg(lean_object* v___x_645_, lean_object* v_val_646_, lean_object* v_range_647_, lean_object* v_b_648_, lean_object* v_i_649_, lean_object* v___y_650_, lean_object* v___y_651_, lean_object* v___y_652_, lean_object* v___y_653_){
_start:
{
lean_object* v_stop_655_; lean_object* v_step_656_; lean_object* v_a_658_; uint8_t v___x_661_; 
v_stop_655_ = lean_ctor_get(v_range_647_, 1);
v_step_656_ = lean_ctor_get(v_range_647_, 2);
v___x_661_ = lean_nat_dec_lt(v_i_649_, v_stop_655_);
if (v___x_661_ == 0)
{
lean_object* v___x_662_; 
lean_dec(v_i_649_);
v___x_662_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_662_, 0, v_b_648_);
return v___x_662_;
}
else
{
lean_object* v___x_663_; lean_object* v___x_664_; 
v___x_663_ = lean_array_fget_borrowed(v___x_645_, v_i_649_);
lean_inc(v___y_653_);
lean_inc_ref(v___y_652_);
lean_inc(v___y_651_);
lean_inc_ref(v___y_650_);
lean_inc(v___x_663_);
v___x_664_ = lean_infer_type(v___x_663_, v___y_650_, v___y_651_, v___y_652_, v___y_653_);
if (lean_obj_tag(v___x_664_) == 0)
{
lean_object* v_a_665_; lean_object* v_binderInfos_666_; uint8_t v___x_667_; lean_object* v___x_668_; lean_object* v___x_669_; uint8_t v___x_670_; lean_object* v___x_671_; 
v_a_665_ = lean_ctor_get(v___x_664_, 0);
lean_inc_n(v_a_665_, 2);
lean_dec_ref_known(v___x_664_, 1);
v_binderInfos_666_ = lean_ctor_get(v_val_646_, 1);
v___x_667_ = 0;
v___x_668_ = lean_box(v___x_667_);
v___x_669_ = lean_array_get(v___x_668_, v_binderInfos_666_, v_i_649_);
lean_dec(v___x_668_);
v___x_670_ = lean_unbox(v___x_669_);
lean_dec(v___x_669_);
v___x_671_ = lp_JunkValues_JunkValues_isGuardBinder(v___x_670_, v_a_665_, v___y_650_, v___y_651_, v___y_652_, v___y_653_);
if (lean_obj_tag(v___x_671_) == 0)
{
lean_object* v_a_672_; uint8_t v___x_673_; 
v_a_672_ = lean_ctor_get(v___x_671_, 0);
lean_inc(v_a_672_);
lean_dec_ref_known(v___x_671_, 1);
v___x_673_ = lean_unbox(v_a_672_);
lean_dec(v_a_672_);
if (v___x_673_ == 0)
{
lean_object* v_fst_674_; lean_object* v_snd_675_; lean_object* v___x_677_; uint8_t v_isShared_678_; uint8_t v_isSharedCheck_682_; 
lean_dec(v_a_665_);
v_fst_674_ = lean_ctor_get(v_b_648_, 0);
v_snd_675_ = lean_ctor_get(v_b_648_, 1);
v_isSharedCheck_682_ = !lean_is_exclusive(v_b_648_);
if (v_isSharedCheck_682_ == 0)
{
v___x_677_ = v_b_648_;
v_isShared_678_ = v_isSharedCheck_682_;
goto v_resetjp_676_;
}
else
{
lean_inc(v_snd_675_);
lean_inc(v_fst_674_);
lean_dec(v_b_648_);
v___x_677_ = lean_box(0);
v_isShared_678_ = v_isSharedCheck_682_;
goto v_resetjp_676_;
}
v_resetjp_676_:
{
lean_object* v___x_680_; 
if (v_isShared_678_ == 0)
{
v___x_680_ = v___x_677_;
goto v_reusejp_679_;
}
else
{
lean_object* v_reuseFailAlloc_681_; 
v_reuseFailAlloc_681_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_681_, 0, v_fst_674_);
lean_ctor_set(v_reuseFailAlloc_681_, 1, v_snd_675_);
v___x_680_ = v_reuseFailAlloc_681_;
goto v_reusejp_679_;
}
v_reusejp_679_:
{
v_a_658_ = v___x_680_;
goto v___jp_657_;
}
}
}
else
{
lean_object* v_fst_683_; lean_object* v_snd_684_; lean_object* v___x_686_; uint8_t v_isShared_687_; uint8_t v_isSharedCheck_698_; 
v_fst_683_ = lean_ctor_get(v_b_648_, 0);
v_snd_684_ = lean_ctor_get(v_b_648_, 1);
v_isSharedCheck_698_ = !lean_is_exclusive(v_b_648_);
if (v_isSharedCheck_698_ == 0)
{
v___x_686_ = v_b_648_;
v_isShared_687_ = v_isSharedCheck_698_;
goto v_resetjp_685_;
}
else
{
lean_inc(v_snd_684_);
lean_inc(v_fst_683_);
lean_dec(v_b_648_);
v___x_686_ = lean_box(0);
v_isShared_687_ = v_isSharedCheck_698_;
goto v_resetjp_685_;
}
v_resetjp_685_:
{
lean_object* v___x_688_; lean_object* v___x_689_; uint8_t v___x_690_; 
v___x_688_ = lean_unsigned_to_nat(1u);
v___x_689_ = lean_nat_add(v_fst_683_, v___x_688_);
lean_dec(v_fst_683_);
v___x_690_ = lp_JunkValues_JunkValues_isNegatedProp(v_a_665_);
lean_dec(v_a_665_);
if (v___x_690_ == 0)
{
lean_object* v___x_692_; 
if (v_isShared_687_ == 0)
{
lean_ctor_set(v___x_686_, 0, v___x_689_);
v___x_692_ = v___x_686_;
goto v_reusejp_691_;
}
else
{
lean_object* v_reuseFailAlloc_693_; 
v_reuseFailAlloc_693_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_693_, 0, v___x_689_);
lean_ctor_set(v_reuseFailAlloc_693_, 1, v_snd_684_);
v___x_692_ = v_reuseFailAlloc_693_;
goto v_reusejp_691_;
}
v_reusejp_691_:
{
v_a_658_ = v___x_692_;
goto v___jp_657_;
}
}
else
{
lean_object* v___x_694_; lean_object* v___x_696_; 
v___x_694_ = lean_nat_add(v_snd_684_, v___x_688_);
lean_dec(v_snd_684_);
if (v_isShared_687_ == 0)
{
lean_ctor_set(v___x_686_, 1, v___x_694_);
lean_ctor_set(v___x_686_, 0, v___x_689_);
v___x_696_ = v___x_686_;
goto v_reusejp_695_;
}
else
{
lean_object* v_reuseFailAlloc_697_; 
v_reuseFailAlloc_697_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_697_, 0, v___x_689_);
lean_ctor_set(v_reuseFailAlloc_697_, 1, v___x_694_);
v___x_696_ = v_reuseFailAlloc_697_;
goto v_reusejp_695_;
}
v_reusejp_695_:
{
v_a_658_ = v___x_696_;
goto v___jp_657_;
}
}
}
}
}
else
{
lean_object* v_a_699_; lean_object* v___x_701_; uint8_t v_isShared_702_; uint8_t v_isSharedCheck_706_; 
lean_dec(v_a_665_);
lean_dec(v_i_649_);
lean_dec_ref(v_b_648_);
v_a_699_ = lean_ctor_get(v___x_671_, 0);
v_isSharedCheck_706_ = !lean_is_exclusive(v___x_671_);
if (v_isSharedCheck_706_ == 0)
{
v___x_701_ = v___x_671_;
v_isShared_702_ = v_isSharedCheck_706_;
goto v_resetjp_700_;
}
else
{
lean_inc(v_a_699_);
lean_dec(v___x_671_);
v___x_701_ = lean_box(0);
v_isShared_702_ = v_isSharedCheck_706_;
goto v_resetjp_700_;
}
v_resetjp_700_:
{
lean_object* v___x_704_; 
if (v_isShared_702_ == 0)
{
v___x_704_ = v___x_701_;
goto v_reusejp_703_;
}
else
{
lean_object* v_reuseFailAlloc_705_; 
v_reuseFailAlloc_705_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_705_, 0, v_a_699_);
v___x_704_ = v_reuseFailAlloc_705_;
goto v_reusejp_703_;
}
v_reusejp_703_:
{
return v___x_704_;
}
}
}
}
else
{
lean_object* v_a_707_; lean_object* v___x_709_; uint8_t v_isShared_710_; uint8_t v_isSharedCheck_714_; 
lean_dec(v_i_649_);
lean_dec_ref(v_b_648_);
v_a_707_ = lean_ctor_get(v___x_664_, 0);
v_isSharedCheck_714_ = !lean_is_exclusive(v___x_664_);
if (v_isSharedCheck_714_ == 0)
{
v___x_709_ = v___x_664_;
v_isShared_710_ = v_isSharedCheck_714_;
goto v_resetjp_708_;
}
else
{
lean_inc(v_a_707_);
lean_dec(v___x_664_);
v___x_709_ = lean_box(0);
v_isShared_710_ = v_isSharedCheck_714_;
goto v_resetjp_708_;
}
v_resetjp_708_:
{
lean_object* v___x_712_; 
if (v_isShared_710_ == 0)
{
v___x_712_ = v___x_709_;
goto v_reusejp_711_;
}
else
{
lean_object* v_reuseFailAlloc_713_; 
v_reuseFailAlloc_713_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_713_, 0, v_a_707_);
v___x_712_ = v_reuseFailAlloc_713_;
goto v_reusejp_711_;
}
v_reusejp_711_:
{
return v___x_712_;
}
}
}
}
v___jp_657_:
{
lean_object* v___x_659_; 
v___x_659_ = lean_nat_add(v_i_649_, v_step_656_);
lean_dec(v_i_649_);
v_b_648_ = v_a_658_;
v_i_649_ = v___x_659_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00JunkValues_ruleOfTheorem_x3f_spec__0___redArg___boxed(lean_object* v___x_715_, lean_object* v_val_716_, lean_object* v_range_717_, lean_object* v_b_718_, lean_object* v_i_719_, lean_object* v___y_720_, lean_object* v___y_721_, lean_object* v___y_722_, lean_object* v___y_723_, lean_object* v___y_724_){
_start:
{
lean_object* v_res_725_; 
v_res_725_ = lp_JunkValues___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00JunkValues_ruleOfTheorem_x3f_spec__0___redArg(v___x_715_, v_val_716_, v_range_717_, v_b_718_, v_i_719_, v___y_720_, v___y_721_, v___y_722_, v___y_723_);
lean_dec(v___y_723_);
lean_dec_ref(v___y_722_);
lean_dec(v___y_721_);
lean_dec_ref(v___y_720_);
lean_dec_ref(v_range_717_);
lean_dec_ref(v_val_716_);
lean_dec_ref(v___x_715_);
return v_res_725_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_ruleOfTheorem_x3f_spec__1___redArg(lean_object* v_thm_733_, lean_object* v_a_734_, lean_object* v_as_735_, size_t v_sz_736_, size_t v_i_737_, lean_object* v_b_738_){
_start:
{
uint8_t v___x_740_; 
v___x_740_ = lean_usize_dec_lt(v_i_737_, v_sz_736_);
if (v___x_740_ == 0)
{
lean_object* v___x_741_; 
lean_dec(v_thm_733_);
v___x_741_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_741_, 0, v_b_738_);
return v___x_741_;
}
else
{
lean_object* v___x_742_; lean_object* v___x_743_; lean_object* v___x_744_; lean_object* v_a_745_; uint8_t v___y_747_; uint8_t v___x_769_; 
lean_dec_ref(v_b_738_);
v___x_742_ = lean_box(0);
v___x_743_ = ((lean_object*)(lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_ruleOfTheorem_x3f_spec__1___redArg___closed__0));
v___x_744_ = lean_unsigned_to_nat(0u);
v_a_745_ = lean_array_uget_borrowed(v_as_735_, v_i_737_);
v___x_769_ = lean_nat_dec_eq(v_a_745_, v___x_744_);
if (v___x_769_ == 0)
{
lean_object* v___x_770_; uint8_t v___x_771_; 
v___x_770_ = lean_array_get_size(v_a_734_);
v___x_771_ = lean_nat_dec_lt(v___x_770_, v_a_745_);
v___y_747_ = v___x_771_;
goto v___jp_746_;
}
else
{
v___y_747_ = v___x_769_;
goto v___jp_746_;
}
v___jp_746_:
{
if (v___y_747_ == 0)
{
size_t v___x_748_; size_t v___x_749_; 
v___x_748_ = ((size_t)1ULL);
v___x_749_ = lean_usize_add(v_i_737_, v___x_748_);
v_i_737_ = v___x_749_;
v_b_738_ = v___x_743_;
goto _start;
}
else
{
lean_object* v___x_751_; lean_object* v___x_752_; lean_object* v___x_753_; lean_object* v___x_754_; lean_object* v___x_755_; lean_object* v___x_756_; lean_object* v___x_757_; lean_object* v___x_758_; lean_object* v___x_759_; lean_object* v___x_760_; lean_object* v___x_761_; lean_object* v___x_762_; lean_object* v___x_763_; lean_object* v___x_764_; lean_object* v___x_765_; lean_object* v___x_766_; lean_object* v___x_767_; lean_object* v___x_768_; 
v___x_751_ = ((lean_object*)(lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_ruleOfTheorem_x3f_spec__1___redArg___closed__1));
lean_inc(v_a_745_);
v___x_752_ = l_Nat_reprFast(v_a_745_);
v___x_753_ = lean_string_append(v___x_751_, v___x_752_);
lean_dec_ref(v___x_752_);
v___x_754_ = ((lean_object*)(lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_ruleOfTheorem_x3f_spec__1___redArg___closed__2));
v___x_755_ = lean_string_append(v___x_753_, v___x_754_);
v___x_756_ = l_Lean_Name_toStringWithToken___at___00Lean_Name_toString_spec__0(v_thm_733_, v___y_747_);
v___x_757_ = lean_string_append(v___x_755_, v___x_756_);
lean_dec_ref(v___x_756_);
v___x_758_ = ((lean_object*)(lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_ruleOfTheorem_x3f_spec__1___redArg___closed__3));
v___x_759_ = lean_string_append(v___x_757_, v___x_758_);
v___x_760_ = lean_array_get_size(v_a_734_);
v___x_761_ = l_Nat_reprFast(v___x_760_);
v___x_762_ = lean_string_append(v___x_759_, v___x_761_);
lean_dec_ref(v___x_761_);
v___x_763_ = ((lean_object*)(lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_ruleOfTheorem_x3f_spec__1___redArg___closed__4));
v___x_764_ = lean_string_append(v___x_762_, v___x_763_);
v___x_765_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_765_, 0, v___x_764_);
v___x_766_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_766_, 0, v___x_765_);
v___x_767_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_767_, 0, v___x_766_);
lean_ctor_set(v___x_767_, 1, v___x_742_);
v___x_768_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_768_, 0, v___x_767_);
return v___x_768_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_ruleOfTheorem_x3f_spec__1___redArg___boxed(lean_object* v_thm_772_, lean_object* v_a_773_, lean_object* v_as_774_, lean_object* v_sz_775_, lean_object* v_i_776_, lean_object* v_b_777_, lean_object* v___y_778_){
_start:
{
size_t v_sz_boxed_779_; size_t v_i_boxed_780_; lean_object* v_res_781_; 
v_sz_boxed_779_ = lean_unbox_usize(v_sz_775_);
lean_dec(v_sz_775_);
v_i_boxed_780_ = lean_unbox_usize(v_i_776_);
lean_dec(v_i_776_);
v_res_781_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_ruleOfTheorem_x3f_spec__1___redArg(v_thm_772_, v_a_773_, v_as_774_, v_sz_boxed_779_, v_i_boxed_780_, v_b_777_);
lean_dec_ref(v_as_774_);
lean_dec_ref(v_a_773_);
return v_res_781_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_ruleOfTheorem_x3f(lean_object* v_thm_789_, lean_object* v_note_790_, lean_object* v_generalize_791_, lean_object* v_a_792_, lean_object* v_a_793_, lean_object* v_a_794_, lean_object* v_a_795_){
_start:
{
lean_object* v___x_797_; 
lean_inc(v_thm_789_);
v___x_797_ = lp_JunkValues_JunkValues_openRule(v_thm_789_, v_a_792_, v_a_793_, v_a_794_, v_a_795_);
if (lean_obj_tag(v___x_797_) == 0)
{
lean_object* v_a_798_; lean_object* v___x_800_; uint8_t v_isShared_801_; uint8_t v_isSharedCheck_906_; 
v_a_798_ = lean_ctor_get(v___x_797_, 0);
v_isSharedCheck_906_ = !lean_is_exclusive(v___x_797_);
if (v_isSharedCheck_906_ == 0)
{
v___x_800_ = v___x_797_;
v_isShared_801_ = v_isSharedCheck_906_;
goto v_resetjp_799_;
}
else
{
lean_inc(v_a_798_);
lean_dec(v___x_797_);
v___x_800_ = lean_box(0);
v_isShared_801_ = v_isSharedCheck_906_;
goto v_resetjp_799_;
}
v_resetjp_799_:
{
if (lean_obj_tag(v_a_798_) == 1)
{
lean_object* v_val_802_; lean_object* v___x_804_; uint8_t v_isShared_805_; uint8_t v_isSharedCheck_895_; 
v_val_802_ = lean_ctor_get(v_a_798_, 0);
v_isSharedCheck_895_ = !lean_is_exclusive(v_a_798_);
if (v_isSharedCheck_895_ == 0)
{
v___x_804_ = v_a_798_;
v_isShared_805_ = v_isSharedCheck_895_;
goto v_resetjp_803_;
}
else
{
lean_inc(v_val_802_);
lean_dec(v_a_798_);
v___x_804_ = lean_box(0);
v_isShared_805_ = v_isSharedCheck_895_;
goto v_resetjp_803_;
}
v_resetjp_803_:
{
lean_object* v_vars_806_; lean_object* v_lhs_807_; lean_object* v___x_808_; 
v_vars_806_ = lean_ctor_get(v_val_802_, 0);
lean_inc_ref(v_vars_806_);
v_lhs_807_ = lean_ctor_get(v_val_802_, 2);
lean_inc_ref(v_lhs_807_);
v___x_808_ = l_Lean_Expr_getAppFn(v_lhs_807_);
if (lean_obj_tag(v___x_808_) == 4)
{
lean_object* v_declName_809_; lean_object* v___x_810_; lean_object* v___x_811_; lean_object* v___x_812_; lean_object* v___x_813_; lean_object* v___x_814_; lean_object* v___x_815_; 
lean_del_object(v___x_800_);
v_declName_809_ = lean_ctor_get(v___x_808_, 0);
lean_inc(v_declName_809_);
lean_dec_ref_known(v___x_808_, 2);
v___x_810_ = lean_unsigned_to_nat(0u);
v___x_811_ = lean_array_get_size(v_vars_806_);
v___x_812_ = lean_unsigned_to_nat(1u);
v___x_813_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_813_, 0, v___x_810_);
lean_ctor_set(v___x_813_, 1, v___x_811_);
lean_ctor_set(v___x_813_, 2, v___x_812_);
v___x_814_ = ((lean_object*)(lp_JunkValues_JunkValues_ruleOfTheorem_x3f___closed__0));
v___x_815_ = lp_JunkValues___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00JunkValues_ruleOfTheorem_x3f_spec__0___redArg(v_vars_806_, v_val_802_, v___x_813_, v___x_814_, v___x_810_, v_a_792_, v_a_793_, v_a_794_, v_a_795_);
lean_dec_ref_known(v___x_813_, 3);
lean_dec(v_val_802_);
lean_dec_ref(v_vars_806_);
if (lean_obj_tag(v___x_815_) == 0)
{
lean_object* v_a_816_; lean_object* v___x_817_; 
v_a_816_ = lean_ctor_get(v___x_815_, 0);
lean_inc(v_a_816_);
lean_dec_ref_known(v___x_815_, 1);
lean_inc_ref(v_lhs_807_);
v___x_817_ = lp_JunkValues_JunkValues_explicitArgIndices(v_lhs_807_, v_a_792_, v_a_793_, v_a_794_, v_a_795_);
if (lean_obj_tag(v___x_817_) == 0)
{
lean_object* v_a_818_; lean_object* v___x_819_; size_t v_sz_820_; size_t v___x_821_; lean_object* v___x_822_; 
v_a_818_ = lean_ctor_get(v___x_817_, 0);
lean_inc(v_a_818_);
lean_dec_ref_known(v___x_817_, 1);
v___x_819_ = ((lean_object*)(lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_ruleOfTheorem_x3f_spec__1___redArg___closed__0));
v_sz_820_ = lean_array_size(v_generalize_791_);
v___x_821_ = ((size_t)0ULL);
lean_inc(v_thm_789_);
v___x_822_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_ruleOfTheorem_x3f_spec__1___redArg(v_thm_789_, v_a_818_, v_generalize_791_, v_sz_820_, v___x_821_, v___x_819_);
lean_dec(v_a_818_);
if (lean_obj_tag(v___x_822_) == 0)
{
lean_object* v_a_823_; lean_object* v___x_825_; uint8_t v_isShared_826_; uint8_t v_isSharedCheck_858_; 
v_a_823_ = lean_ctor_get(v___x_822_, 0);
v_isSharedCheck_858_ = !lean_is_exclusive(v___x_822_);
if (v_isSharedCheck_858_ == 0)
{
v___x_825_ = v___x_822_;
v_isShared_826_ = v_isSharedCheck_858_;
goto v_resetjp_824_;
}
else
{
lean_inc(v_a_823_);
lean_dec(v___x_822_);
v___x_825_ = lean_box(0);
v_isShared_826_ = v_isSharedCheck_858_;
goto v_resetjp_824_;
}
v_resetjp_824_:
{
lean_object* v_fst_827_; 
v_fst_827_ = lean_ctor_get(v_a_823_, 0);
lean_inc(v_fst_827_);
lean_dec(v_a_823_);
if (lean_obj_tag(v_fst_827_) == 0)
{
lean_object* v_fst_828_; lean_object* v_snd_829_; uint8_t v___y_831_; uint8_t v___x_851_; 
v_fst_828_ = lean_ctor_get(v_a_816_, 0);
lean_inc(v_fst_828_);
v_snd_829_ = lean_ctor_get(v_a_816_, 1);
lean_inc(v_snd_829_);
lean_dec(v_a_816_);
v___x_851_ = lean_nat_dec_eq(v_fst_828_, v___x_810_);
lean_dec(v_fst_828_);
if (v___x_851_ == 0)
{
v___y_831_ = v___x_851_;
goto v___jp_830_;
}
else
{
lean_object* v___x_852_; uint8_t v___x_853_; 
v___x_852_ = lean_array_get_size(v_generalize_791_);
v___x_853_ = lean_nat_dec_eq(v___x_852_, v___x_810_);
v___y_831_ = v___x_853_;
goto v___jp_830_;
}
v___jp_830_:
{
if (v___y_831_ == 0)
{
lean_object* v___x_832_; lean_object* v___x_833_; lean_object* v___x_835_; 
v___x_832_ = l_Lean_Expr_getAppNumArgs(v_lhs_807_);
lean_dec_ref(v_lhs_807_);
v___x_833_ = lean_alloc_ctor(0, 6, 0);
lean_ctor_set(v___x_833_, 0, v_thm_789_);
lean_ctor_set(v___x_833_, 1, v_declName_809_);
lean_ctor_set(v___x_833_, 2, v___x_832_);
lean_ctor_set(v___x_833_, 3, v_snd_829_);
lean_ctor_set(v___x_833_, 4, v_generalize_791_);
lean_ctor_set(v___x_833_, 5, v_note_790_);
if (v_isShared_805_ == 0)
{
lean_ctor_set(v___x_804_, 0, v___x_833_);
v___x_835_ = v___x_804_;
goto v_reusejp_834_;
}
else
{
lean_object* v_reuseFailAlloc_839_; 
v_reuseFailAlloc_839_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_839_, 0, v___x_833_);
v___x_835_ = v_reuseFailAlloc_839_;
goto v_reusejp_834_;
}
v_reusejp_834_:
{
lean_object* v___x_837_; 
if (v_isShared_826_ == 0)
{
lean_ctor_set(v___x_825_, 0, v___x_835_);
v___x_837_ = v___x_825_;
goto v_reusejp_836_;
}
else
{
lean_object* v_reuseFailAlloc_838_; 
v_reuseFailAlloc_838_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_838_, 0, v___x_835_);
v___x_837_ = v_reuseFailAlloc_838_;
goto v_reusejp_836_;
}
v_reusejp_836_:
{
return v___x_837_;
}
}
}
else
{
lean_object* v___x_840_; lean_object* v___x_841_; lean_object* v___x_842_; lean_object* v___x_843_; lean_object* v___x_844_; lean_object* v___x_846_; 
lean_dec(v_snd_829_);
lean_dec(v_declName_809_);
lean_dec_ref(v_lhs_807_);
lean_dec_ref(v_generalize_791_);
lean_dec_ref(v_note_790_);
v___x_840_ = ((lean_object*)(lp_JunkValues_JunkValues_ruleOfTheorem_x3f___closed__1));
v___x_841_ = l_Lean_Name_toStringWithToken___at___00Lean_Name_toString_spec__0(v_thm_789_, v___y_831_);
v___x_842_ = lean_string_append(v___x_840_, v___x_841_);
lean_dec_ref(v___x_841_);
v___x_843_ = ((lean_object*)(lp_JunkValues_JunkValues_ruleOfTheorem_x3f___closed__2));
v___x_844_ = lean_string_append(v___x_842_, v___x_843_);
if (v_isShared_805_ == 0)
{
lean_ctor_set_tag(v___x_804_, 0);
lean_ctor_set(v___x_804_, 0, v___x_844_);
v___x_846_ = v___x_804_;
goto v_reusejp_845_;
}
else
{
lean_object* v_reuseFailAlloc_850_; 
v_reuseFailAlloc_850_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_850_, 0, v___x_844_);
v___x_846_ = v_reuseFailAlloc_850_;
goto v_reusejp_845_;
}
v_reusejp_845_:
{
lean_object* v___x_848_; 
if (v_isShared_826_ == 0)
{
lean_ctor_set(v___x_825_, 0, v___x_846_);
v___x_848_ = v___x_825_;
goto v_reusejp_847_;
}
else
{
lean_object* v_reuseFailAlloc_849_; 
v_reuseFailAlloc_849_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_849_, 0, v___x_846_);
v___x_848_ = v_reuseFailAlloc_849_;
goto v_reusejp_847_;
}
v_reusejp_847_:
{
return v___x_848_;
}
}
}
}
}
else
{
lean_object* v_val_854_; lean_object* v___x_856_; 
lean_dec(v_a_816_);
lean_dec(v_declName_809_);
lean_dec_ref(v_lhs_807_);
lean_del_object(v___x_804_);
lean_dec_ref(v_generalize_791_);
lean_dec_ref(v_note_790_);
lean_dec(v_thm_789_);
v_val_854_ = lean_ctor_get(v_fst_827_, 0);
lean_inc(v_val_854_);
lean_dec_ref_known(v_fst_827_, 1);
if (v_isShared_826_ == 0)
{
lean_ctor_set(v___x_825_, 0, v_val_854_);
v___x_856_ = v___x_825_;
goto v_reusejp_855_;
}
else
{
lean_object* v_reuseFailAlloc_857_; 
v_reuseFailAlloc_857_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_857_, 0, v_val_854_);
v___x_856_ = v_reuseFailAlloc_857_;
goto v_reusejp_855_;
}
v_reusejp_855_:
{
return v___x_856_;
}
}
}
}
else
{
lean_object* v_a_859_; lean_object* v___x_861_; uint8_t v_isShared_862_; uint8_t v_isSharedCheck_866_; 
lean_dec(v_a_816_);
lean_dec(v_declName_809_);
lean_dec_ref(v_lhs_807_);
lean_del_object(v___x_804_);
lean_dec_ref(v_generalize_791_);
lean_dec_ref(v_note_790_);
lean_dec(v_thm_789_);
v_a_859_ = lean_ctor_get(v___x_822_, 0);
v_isSharedCheck_866_ = !lean_is_exclusive(v___x_822_);
if (v_isSharedCheck_866_ == 0)
{
v___x_861_ = v___x_822_;
v_isShared_862_ = v_isSharedCheck_866_;
goto v_resetjp_860_;
}
else
{
lean_inc(v_a_859_);
lean_dec(v___x_822_);
v___x_861_ = lean_box(0);
v_isShared_862_ = v_isSharedCheck_866_;
goto v_resetjp_860_;
}
v_resetjp_860_:
{
lean_object* v___x_864_; 
if (v_isShared_862_ == 0)
{
v___x_864_ = v___x_861_;
goto v_reusejp_863_;
}
else
{
lean_object* v_reuseFailAlloc_865_; 
v_reuseFailAlloc_865_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_865_, 0, v_a_859_);
v___x_864_ = v_reuseFailAlloc_865_;
goto v_reusejp_863_;
}
v_reusejp_863_:
{
return v___x_864_;
}
}
}
}
else
{
lean_object* v_a_867_; lean_object* v___x_869_; uint8_t v_isShared_870_; uint8_t v_isSharedCheck_874_; 
lean_dec(v_a_816_);
lean_dec(v_declName_809_);
lean_dec_ref(v_lhs_807_);
lean_del_object(v___x_804_);
lean_dec_ref(v_generalize_791_);
lean_dec_ref(v_note_790_);
lean_dec(v_thm_789_);
v_a_867_ = lean_ctor_get(v___x_817_, 0);
v_isSharedCheck_874_ = !lean_is_exclusive(v___x_817_);
if (v_isSharedCheck_874_ == 0)
{
v___x_869_ = v___x_817_;
v_isShared_870_ = v_isSharedCheck_874_;
goto v_resetjp_868_;
}
else
{
lean_inc(v_a_867_);
lean_dec(v___x_817_);
v___x_869_ = lean_box(0);
v_isShared_870_ = v_isSharedCheck_874_;
goto v_resetjp_868_;
}
v_resetjp_868_:
{
lean_object* v___x_872_; 
if (v_isShared_870_ == 0)
{
v___x_872_ = v___x_869_;
goto v_reusejp_871_;
}
else
{
lean_object* v_reuseFailAlloc_873_; 
v_reuseFailAlloc_873_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_873_, 0, v_a_867_);
v___x_872_ = v_reuseFailAlloc_873_;
goto v_reusejp_871_;
}
v_reusejp_871_:
{
return v___x_872_;
}
}
}
}
else
{
lean_object* v_a_875_; lean_object* v___x_877_; uint8_t v_isShared_878_; uint8_t v_isSharedCheck_882_; 
lean_dec(v_declName_809_);
lean_dec_ref(v_lhs_807_);
lean_del_object(v___x_804_);
lean_dec_ref(v_generalize_791_);
lean_dec_ref(v_note_790_);
lean_dec(v_thm_789_);
v_a_875_ = lean_ctor_get(v___x_815_, 0);
v_isSharedCheck_882_ = !lean_is_exclusive(v___x_815_);
if (v_isSharedCheck_882_ == 0)
{
v___x_877_ = v___x_815_;
v_isShared_878_ = v_isSharedCheck_882_;
goto v_resetjp_876_;
}
else
{
lean_inc(v_a_875_);
lean_dec(v___x_815_);
v___x_877_ = lean_box(0);
v_isShared_878_ = v_isSharedCheck_882_;
goto v_resetjp_876_;
}
v_resetjp_876_:
{
lean_object* v___x_880_; 
if (v_isShared_878_ == 0)
{
v___x_880_ = v___x_877_;
goto v_reusejp_879_;
}
else
{
lean_object* v_reuseFailAlloc_881_; 
v_reuseFailAlloc_881_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_881_, 0, v_a_875_);
v___x_880_ = v_reuseFailAlloc_881_;
goto v_reusejp_879_;
}
v_reusejp_879_:
{
return v___x_880_;
}
}
}
}
else
{
lean_object* v___x_883_; uint8_t v___x_884_; lean_object* v___x_885_; lean_object* v___x_886_; lean_object* v___x_887_; lean_object* v___x_888_; lean_object* v___x_890_; 
lean_dec_ref(v___x_808_);
lean_dec_ref(v_lhs_807_);
lean_dec_ref(v_vars_806_);
lean_dec(v_val_802_);
lean_dec_ref(v_generalize_791_);
lean_dec_ref(v_note_790_);
v___x_883_ = ((lean_object*)(lp_JunkValues_JunkValues_ruleOfTheorem_x3f___closed__3));
v___x_884_ = 1;
v___x_885_ = l_Lean_Name_toStringWithToken___at___00Lean_Name_toString_spec__0(v_thm_789_, v___x_884_);
v___x_886_ = lean_string_append(v___x_883_, v___x_885_);
lean_dec_ref(v___x_885_);
v___x_887_ = ((lean_object*)(lp_JunkValues_JunkValues_ruleOfTheorem_x3f___closed__4));
v___x_888_ = lean_string_append(v___x_886_, v___x_887_);
if (v_isShared_805_ == 0)
{
lean_ctor_set_tag(v___x_804_, 0);
lean_ctor_set(v___x_804_, 0, v___x_888_);
v___x_890_ = v___x_804_;
goto v_reusejp_889_;
}
else
{
lean_object* v_reuseFailAlloc_894_; 
v_reuseFailAlloc_894_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_894_, 0, v___x_888_);
v___x_890_ = v_reuseFailAlloc_894_;
goto v_reusejp_889_;
}
v_reusejp_889_:
{
lean_object* v___x_892_; 
if (v_isShared_801_ == 0)
{
lean_ctor_set(v___x_800_, 0, v___x_890_);
v___x_892_ = v___x_800_;
goto v_reusejp_891_;
}
else
{
lean_object* v_reuseFailAlloc_893_; 
v_reuseFailAlloc_893_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_893_, 0, v___x_890_);
v___x_892_ = v_reuseFailAlloc_893_;
goto v_reusejp_891_;
}
v_reusejp_891_:
{
return v___x_892_;
}
}
}
}
}
else
{
lean_object* v___x_896_; uint8_t v___x_897_; lean_object* v___x_898_; lean_object* v___x_899_; lean_object* v___x_900_; lean_object* v___x_901_; lean_object* v___x_902_; lean_object* v___x_904_; 
lean_dec(v_a_798_);
lean_dec_ref(v_generalize_791_);
lean_dec_ref(v_note_790_);
v___x_896_ = ((lean_object*)(lp_JunkValues_JunkValues_ruleOfTheorem_x3f___closed__1));
v___x_897_ = 1;
v___x_898_ = l_Lean_Name_toStringWithToken___at___00Lean_Name_toString_spec__0(v_thm_789_, v___x_897_);
v___x_899_ = lean_string_append(v___x_896_, v___x_898_);
lean_dec_ref(v___x_898_);
v___x_900_ = ((lean_object*)(lp_JunkValues_JunkValues_ruleOfTheorem_x3f___closed__5));
v___x_901_ = lean_string_append(v___x_899_, v___x_900_);
v___x_902_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_902_, 0, v___x_901_);
if (v_isShared_801_ == 0)
{
lean_ctor_set(v___x_800_, 0, v___x_902_);
v___x_904_ = v___x_800_;
goto v_reusejp_903_;
}
else
{
lean_object* v_reuseFailAlloc_905_; 
v_reuseFailAlloc_905_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_905_, 0, v___x_902_);
v___x_904_ = v_reuseFailAlloc_905_;
goto v_reusejp_903_;
}
v_reusejp_903_:
{
return v___x_904_;
}
}
}
}
else
{
lean_object* v_a_907_; lean_object* v___x_909_; uint8_t v_isShared_910_; uint8_t v_isSharedCheck_914_; 
lean_dec_ref(v_generalize_791_);
lean_dec_ref(v_note_790_);
lean_dec(v_thm_789_);
v_a_907_ = lean_ctor_get(v___x_797_, 0);
v_isSharedCheck_914_ = !lean_is_exclusive(v___x_797_);
if (v_isSharedCheck_914_ == 0)
{
v___x_909_ = v___x_797_;
v_isShared_910_ = v_isSharedCheck_914_;
goto v_resetjp_908_;
}
else
{
lean_inc(v_a_907_);
lean_dec(v___x_797_);
v___x_909_ = lean_box(0);
v_isShared_910_ = v_isSharedCheck_914_;
goto v_resetjp_908_;
}
v_resetjp_908_:
{
lean_object* v___x_912_; 
if (v_isShared_910_ == 0)
{
v___x_912_ = v___x_909_;
goto v_reusejp_911_;
}
else
{
lean_object* v_reuseFailAlloc_913_; 
v_reuseFailAlloc_913_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_913_, 0, v_a_907_);
v___x_912_ = v_reuseFailAlloc_913_;
goto v_reusejp_911_;
}
v_reusejp_911_:
{
return v___x_912_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_ruleOfTheorem_x3f___boxed(lean_object* v_thm_915_, lean_object* v_note_916_, lean_object* v_generalize_917_, lean_object* v_a_918_, lean_object* v_a_919_, lean_object* v_a_920_, lean_object* v_a_921_, lean_object* v_a_922_){
_start:
{
lean_object* v_res_923_; 
v_res_923_ = lp_JunkValues_JunkValues_ruleOfTheorem_x3f(v_thm_915_, v_note_916_, v_generalize_917_, v_a_918_, v_a_919_, v_a_920_, v_a_921_);
lean_dec(v_a_921_);
lean_dec_ref(v_a_920_);
lean_dec(v_a_919_);
lean_dec_ref(v_a_918_);
return v_res_923_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00JunkValues_ruleOfTheorem_x3f_spec__0(lean_object* v___x_924_, lean_object* v_val_925_, lean_object* v_range_926_, lean_object* v_b_927_, lean_object* v_i_928_, lean_object* v_hs_929_, lean_object* v_hl_930_, lean_object* v___y_931_, lean_object* v___y_932_, lean_object* v___y_933_, lean_object* v___y_934_){
_start:
{
lean_object* v___x_936_; 
v___x_936_ = lp_JunkValues___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00JunkValues_ruleOfTheorem_x3f_spec__0___redArg(v___x_924_, v_val_925_, v_range_926_, v_b_927_, v_i_928_, v___y_931_, v___y_932_, v___y_933_, v___y_934_);
return v___x_936_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00JunkValues_ruleOfTheorem_x3f_spec__0___boxed(lean_object* v___x_937_, lean_object* v_val_938_, lean_object* v_range_939_, lean_object* v_b_940_, lean_object* v_i_941_, lean_object* v_hs_942_, lean_object* v_hl_943_, lean_object* v___y_944_, lean_object* v___y_945_, lean_object* v___y_946_, lean_object* v___y_947_, lean_object* v___y_948_){
_start:
{
lean_object* v_res_949_; 
v_res_949_ = lp_JunkValues___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00JunkValues_ruleOfTheorem_x3f_spec__0(v___x_937_, v_val_938_, v_range_939_, v_b_940_, v_i_941_, v_hs_942_, v_hl_943_, v___y_944_, v___y_945_, v___y_946_, v___y_947_);
lean_dec(v___y_947_);
lean_dec_ref(v___y_946_);
lean_dec(v___y_945_);
lean_dec_ref(v___y_944_);
lean_dec_ref(v_range_939_);
lean_dec_ref(v_val_938_);
lean_dec_ref(v___x_937_);
return v_res_949_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_ruleOfTheorem_x3f_spec__1(lean_object* v_thm_950_, lean_object* v_a_951_, lean_object* v_as_952_, size_t v_sz_953_, size_t v_i_954_, lean_object* v_b_955_, lean_object* v___y_956_, lean_object* v___y_957_, lean_object* v___y_958_, lean_object* v___y_959_){
_start:
{
lean_object* v___x_961_; 
v___x_961_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_ruleOfTheorem_x3f_spec__1___redArg(v_thm_950_, v_a_951_, v_as_952_, v_sz_953_, v_i_954_, v_b_955_);
return v___x_961_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_ruleOfTheorem_x3f_spec__1___boxed(lean_object* v_thm_962_, lean_object* v_a_963_, lean_object* v_as_964_, lean_object* v_sz_965_, lean_object* v_i_966_, lean_object* v_b_967_, lean_object* v___y_968_, lean_object* v___y_969_, lean_object* v___y_970_, lean_object* v___y_971_, lean_object* v___y_972_){
_start:
{
size_t v_sz_boxed_973_; size_t v_i_boxed_974_; lean_object* v_res_975_; 
v_sz_boxed_973_ = lean_unbox_usize(v_sz_965_);
lean_dec(v_sz_965_);
v_i_boxed_974_ = lean_unbox_usize(v_i_966_);
lean_dec(v_i_966_);
v_res_975_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_ruleOfTheorem_x3f_spec__1(v_thm_962_, v_a_963_, v_as_964_, v_sz_boxed_973_, v_i_boxed_974_, v_b_967_, v___y_968_, v___y_969_, v___y_970_, v___y_971_);
lean_dec(v___y_971_);
lean_dec_ref(v___y_970_);
lean_dec(v___y_969_);
lean_dec_ref(v___y_968_);
lean_dec_ref(v_as_964_);
lean_dec_ref(v_a_963_);
return v_res_975_;
}
}
lean_object* runtime_initialize_Init(uint8_t builtin);
lean_object* runtime_initialize_Lean(uint8_t builtin);
static bool _G_runtime_initialized = false;
LEAN_EXPORT lean_object* runtime_initialize_JunkValues_JunkValues_Rule(uint8_t builtin) {
lean_object * res;
if (_G_runtime_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_runtime_initialized = true;
res = runtime_initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = runtime_initialize_Lean(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return lean_io_result_mk_ok(lean_box(0));
}
lean_object* runtime_initialize_Init(uint8_t builtin);
static bool _G_meta_initialized = false;
LEAN_EXPORT lean_object* meta_initialize_JunkValues_JunkValues_Rule(uint8_t builtin) {
lean_object * res;
if (_G_meta_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_meta_initialized = true;
res = runtime_initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return lean_io_result_mk_ok(lean_box(0));
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Lean(uint8_t builtin);
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_JunkValues_JunkValues_Rule(uint8_t builtin) {
lean_object * res;
if (_G_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_initialized = true;
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Lean(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = runtime_initialize_JunkValues_JunkValues_Rule(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = meta_initialize_JunkValues_JunkValues_Rule(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return initialize_JunkValues_JunkValues_Rule(builtin);
}
#ifdef __cplusplus
}
#endif
