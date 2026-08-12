// Lean compiler output
// Module: JunkValues.Extra.Entry
// Imports: public import Init public meta import Init public import JunkValues.RuleSet
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
lean_object* lean_nat_to_int(lean_object*);
lean_object* lean_mk_empty_array_with_capacity(lean_object*);
uint8_t lean_usize_dec_lt(size_t, size_t);
lean_object* lean_array_uget_borrowed(lean_object*, size_t);
lean_object* lean_string_append(lean_object*, lean_object*);
lean_object* l_Lean_Name_toStringWithToken___at___00Lean_Name_toString_spec__0(lean_object*, uint8_t);
lean_object* lean_array_push(lean_object*, lean_object*);
size_t lean_usize_add(size_t, size_t);
uint8_t lean_name_eq(lean_object*, lean_object*);
uint8_t lean_string_dec_eq(lean_object*, lean_object*);
lean_object* lean_array_get_size(lean_object*);
uint8_t lean_nat_dec_eq(lean_object*, lean_object*);
lean_object* lean_nat_sub(lean_object*, lean_object*);
lean_object* lean_array_fget_borrowed(lean_object*, lean_object*);
size_t lean_array_size(lean_object*);
lean_object* lean_st_ref_get(lean_object*);
lean_object* l_Lean_Environment_find_x3f(lean_object*, lean_object*, uint8_t);
lean_object* lp_JunkValues_JunkValues_ruleOfTheorem_x3f(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* lean_string_length(lean_object*);
lean_object* l_Lean_Name_reprPrec(lean_object*, lean_object*);
lean_object* l_String_quote(lean_object*);
lean_object* lean_array_to_list(lean_object*);
lean_object* l_Nat_reprFast(lean_object*);
lean_object* l_Std_Format_fill(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Nat_cast___at___00JunkValues_instReprCatalogueEntry_repr_spec__1(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_Format_joinSep___at___00Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0_spec__0___lam__0(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_List_foldl___at___00List_foldl___at___00Std_Format_joinSep___at___00Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0_spec__0_spec__2_spec__3(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_List_foldl___at___00Std_Format_joinSep___at___00Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0_spec__0_spec__2(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_Format_joinSep___at___00Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0_spec__0(lean_object*, lean_object*);
static const lean_string_object lp_JunkValues_Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "#["};
static const lean_object* lp_JunkValues_Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0___closed__0 = (const lean_object*)&lp_JunkValues_Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0___closed__0_value;
static const lean_string_object lp_JunkValues_Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 2, .m_capacity = 2, .m_length = 1, .m_data = ","};
static const lean_object* lp_JunkValues_Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0___closed__1 = (const lean_object*)&lp_JunkValues_Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0___closed__1_value;
static const lean_ctor_object lp_JunkValues_Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_JunkValues_Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0___closed__1_value)}};
static const lean_object* lp_JunkValues_Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0___closed__2 = (const lean_object*)&lp_JunkValues_Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0___closed__2_value;
static const lean_ctor_object lp_JunkValues_Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_JunkValues_Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0___closed__2_value),((lean_object*)(((size_t)(1) << 1) | 1))}};
static const lean_object* lp_JunkValues_Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0___closed__3 = (const lean_object*)&lp_JunkValues_Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0___closed__3_value;
static const lean_string_object lp_JunkValues_Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 2, .m_capacity = 2, .m_length = 1, .m_data = "]"};
static const lean_object* lp_JunkValues_Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0___closed__4 = (const lean_object*)&lp_JunkValues_Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0___closed__4_value;
static lean_once_cell_t lp_JunkValues_Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0___closed__5_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0___closed__5;
static lean_once_cell_t lp_JunkValues_Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0___closed__6_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0___closed__6;
static const lean_ctor_object lp_JunkValues_Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_JunkValues_Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0___closed__0_value)}};
static const lean_object* lp_JunkValues_Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0___closed__7 = (const lean_object*)&lp_JunkValues_Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0___closed__7_value;
static const lean_ctor_object lp_JunkValues_Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_JunkValues_Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0___closed__4_value)}};
static const lean_object* lp_JunkValues_Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0___closed__8 = (const lean_object*)&lp_JunkValues_Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0___closed__8_value;
static const lean_string_object lp_JunkValues_Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "#[]"};
static const lean_object* lp_JunkValues_Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0___closed__9 = (const lean_object*)&lp_JunkValues_Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0___closed__9_value;
static const lean_ctor_object lp_JunkValues_Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_JunkValues_Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0___closed__9_value)}};
static const lean_object* lp_JunkValues_Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0___closed__10 = (const lean_object*)&lp_JunkValues_Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0___closed__10_value;
LEAN_EXPORT lean_object* lp_JunkValues_Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0(lean_object*);
static const lean_string_object lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "{ "};
static const lean_object* lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__0_value;
static const lean_string_object lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 12, .m_capacity = 12, .m_length = 11, .m_data = "theoremName"};
static const lean_object* lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__1 = (const lean_object*)&lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__1_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__1_value)}};
static const lean_object* lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__2 = (const lean_object*)&lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__2_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__2_value)}};
static const lean_object* lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__3 = (const lean_object*)&lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__3_value;
static const lean_string_object lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = " := "};
static const lean_object* lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__4 = (const lean_object*)&lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__4_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__4_value)}};
static const lean_object* lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__5 = (const lean_object*)&lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__5_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__3_value),((lean_object*)&lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__5_value)}};
static const lean_object* lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__6 = (const lean_object*)&lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__6_value;
static lean_once_cell_t lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__7_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__7;
static const lean_string_object lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "note"};
static const lean_object* lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__8 = (const lean_object*)&lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__8_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__8_value)}};
static const lean_object* lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__9 = (const lean_object*)&lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__9_value;
static lean_once_cell_t lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__10_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__10;
static const lean_string_object lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "generalize"};
static const lean_object* lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__11 = (const lean_object*)&lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__11_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__12_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__11_value)}};
static const lean_object* lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__12 = (const lean_object*)&lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__12_value;
static lean_once_cell_t lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__13_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__13;
static const lean_string_object lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__14_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = " }"};
static const lean_object* lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__14 = (const lean_object*)&lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__14_value;
static lean_once_cell_t lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__15_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__15;
static lean_once_cell_t lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__16_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__16;
static const lean_ctor_object lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__17_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__0_value)}};
static const lean_object* lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__17 = (const lean_object*)&lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__17_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__18_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__14_value)}};
static const lean_object* lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__18 = (const lean_object*)&lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__18_value;
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instReprCatalogueEntry_repr(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_JunkValues_JunkValues_instReprCatalogueEntry___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_JunkValues_JunkValues_instReprCatalogueEntry___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_instReprCatalogueEntry___closed__0_value;
LEAN_EXPORT const lean_object* lp_JunkValues_JunkValues_instReprCatalogueEntry = (const lean_object*)&lp_JunkValues_JunkValues_instReprCatalogueEntry___closed__0_value;
static const lean_string_object lp_JunkValues_JunkValues_instInhabitedCatalogueEntry_default___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 1, .m_capacity = 1, .m_length = 0, .m_data = ""};
static const lean_object* lp_JunkValues_JunkValues_instInhabitedCatalogueEntry_default___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_instInhabitedCatalogueEntry_default___closed__0_value;
static const lean_array_object lp_JunkValues_JunkValues_instInhabitedCatalogueEntry_default___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* lp_JunkValues_JunkValues_instInhabitedCatalogueEntry_default___closed__1 = (const lean_object*)&lp_JunkValues_JunkValues_instInhabitedCatalogueEntry_default___closed__1_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instInhabitedCatalogueEntry_default___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*3 + 0, .m_other = 3, .m_tag = 0}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_instInhabitedCatalogueEntry_default___closed__0_value),((lean_object*)&lp_JunkValues_JunkValues_instInhabitedCatalogueEntry_default___closed__1_value)}};
static const lean_object* lp_JunkValues_JunkValues_instInhabitedCatalogueEntry_default___closed__2 = (const lean_object*)&lp_JunkValues_JunkValues_instInhabitedCatalogueEntry_default___closed__2_value;
LEAN_EXPORT const lean_object* lp_JunkValues_JunkValues_instInhabitedCatalogueEntry_default = (const lean_object*)&lp_JunkValues_JunkValues_instInhabitedCatalogueEntry_default___closed__2_value;
LEAN_EXPORT const lean_object* lp_JunkValues_JunkValues_instInhabitedCatalogueEntry = (const lean_object*)&lp_JunkValues_JunkValues_instInhabitedCatalogueEntry_default___closed__2_value;
LEAN_EXPORT uint8_t lp_JunkValues_Array_isEqvAux___at___00JunkValues_instBEqCatalogueEntry_beq_spec__0___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Array_isEqvAux___at___00JunkValues_instBEqCatalogueEntry_beq_spec__0___redArg___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_JunkValues_JunkValues_instBEqCatalogueEntry_beq(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instBEqCatalogueEntry_beq___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_JunkValues_Array_isEqvAux___at___00JunkValues_instBEqCatalogueEntry_beq_spec__0(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Array_isEqvAux___at___00JunkValues_instBEqCatalogueEntry_beq_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_closure_object lp_JunkValues_JunkValues_instBEqCatalogueEntry___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_JunkValues_JunkValues_instBEqCatalogueEntry_beq___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_JunkValues_JunkValues_instBEqCatalogueEntry___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_instBEqCatalogueEntry___closed__0_value;
LEAN_EXPORT const lean_object* lp_JunkValues_JunkValues_instBEqCatalogueEntry = (const lean_object*)&lp_JunkValues_JunkValues_instBEqCatalogueEntry___closed__0_value;
static const lean_array_object lp_JunkValues_JunkValues_instInhabitedCatalogueCheck_default___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* lp_JunkValues_JunkValues_instInhabitedCatalogueCheck_default___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_instInhabitedCatalogueCheck_default___closed__0_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instInhabitedCatalogueCheck_default___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*3 + 0, .m_other = 3, .m_tag = 0}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_instInhabitedCatalogueCheck_default___closed__0_value),((lean_object*)&lp_JunkValues_JunkValues_instInhabitedCatalogueCheck_default___closed__0_value),((lean_object*)&lp_JunkValues_JunkValues_instInhabitedCatalogueCheck_default___closed__0_value)}};
static const lean_object* lp_JunkValues_JunkValues_instInhabitedCatalogueCheck_default___closed__1 = (const lean_object*)&lp_JunkValues_JunkValues_instInhabitedCatalogueCheck_default___closed__1_value;
LEAN_EXPORT const lean_object* lp_JunkValues_JunkValues_instInhabitedCatalogueCheck_default = (const lean_object*)&lp_JunkValues_JunkValues_instInhabitedCatalogueCheck_default___closed__1_value;
LEAN_EXPORT const lean_object* lp_JunkValues_JunkValues_instInhabitedCatalogueCheck = (const lean_object*)&lp_JunkValues_JunkValues_instInhabitedCatalogueCheck_default___closed__1_value;
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_checkCatalogue_spec__0(lean_object*, size_t, size_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_checkCatalogue_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_checkCatalogue(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_checkCatalogue___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_catalogueProvider_spec__0___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = " entry `"};
static const lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_catalogueProvider_spec__0___redArg___closed__0 = (const lean_object*)&lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_catalogueProvider_spec__0___redArg___closed__0_value;
static const lean_string_object lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_catalogueProvider_spec__0___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 169, .m_capacity = 169, .m_length = 168, .m_data = "` does not resolve in this environment: it was renamed upstream, or the project does not import the module defining it. The junk values it covers are NOT being checked."};
static const lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_catalogueProvider_spec__0___redArg___closed__1 = (const lean_object*)&lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_catalogueProvider_spec__0___redArg___closed__1_value;
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_catalogueProvider_spec__0___redArg(lean_object*, lean_object*, size_t, size_t, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_catalogueProvider_spec__0___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_catalogueProvider_spec__1___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 46, .m_capacity = 46, .m_length = 45, .m_data = "` exists but is no longer a junk-value rule: "};
static const lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_catalogueProvider_spec__1___redArg___closed__0 = (const lean_object*)&lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_catalogueProvider_spec__1___redArg___closed__0_value;
static const lean_string_object lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_catalogueProvider_spec__1___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 51, .m_capacity = 51, .m_length = 50, .m_data = ". The junk values it covers are NOT being checked."};
static const lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_catalogueProvider_spec__1___redArg___closed__1 = (const lean_object*)&lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_catalogueProvider_spec__1___redArg___closed__1_value;
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_catalogueProvider_spec__1___redArg(lean_object*, lean_object*, size_t, size_t, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_catalogueProvider_spec__1___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_array_object lp_JunkValues_JunkValues_catalogueProvider___lam__0___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* lp_JunkValues_JunkValues_catalogueProvider___lam__0___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_catalogueProvider___lam__0___closed__0_value;
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_catalogueProvider___lam__0(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_catalogueProvider___lam__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_catalogueProvider(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_catalogueProvider_spec__0(lean_object*, lean_object*, size_t, size_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_catalogueProvider_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_catalogueProvider_spec__1(lean_object*, lean_object*, size_t, size_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_catalogueProvider_spec__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Nat_cast___at___00JunkValues_instReprCatalogueEntry_repr_spec__1(lean_object* v_a_1_){
_start:
{
lean_object* v___x_2_; 
v___x_2_ = lean_nat_to_int(v_a_1_);
return v___x_2_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_Format_joinSep___at___00Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0_spec__0___lam__0(lean_object* v___y_3_){
_start:
{
lean_object* v___x_4_; lean_object* v___x_5_; 
v___x_4_ = l_Nat_reprFast(v___y_3_);
v___x_5_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_5_, 0, v___x_4_);
return v___x_5_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_List_foldl___at___00List_foldl___at___00Std_Format_joinSep___at___00Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0_spec__0_spec__2_spec__3(lean_object* v_x_6_, lean_object* v_x_7_, lean_object* v_x_8_){
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
LEAN_EXPORT lean_object* lp_JunkValues_List_foldl___at___00Std_Format_joinSep___at___00Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0_spec__0_spec__2(lean_object* v_x_22_, lean_object* v_x_23_, lean_object* v_x_24_){
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
v___x_35_ = lp_JunkValues_List_foldl___at___00List_foldl___at___00Std_Format_joinSep___at___00Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0_spec__0_spec__2_spec__3(v_x_22_, v___x_34_, v_tail_26_);
return v___x_35_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_Format_joinSep___at___00Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0_spec__0(lean_object* v_x_38_, lean_object* v_x_39_){
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
v___x_43_ = lp_JunkValues_Std_Format_joinSep___at___00Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0_spec__0___lam__0(v_head_42_);
return v___x_43_;
}
else
{
lean_object* v_head_44_; lean_object* v___x_45_; lean_object* v___x_46_; 
lean_inc(v_tail_41_);
v_head_44_ = lean_ctor_get(v_x_38_, 0);
lean_inc(v_head_44_);
lean_dec_ref_known(v_x_38_, 2);
v___x_45_ = lp_JunkValues_Std_Format_joinSep___at___00Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0_spec__0___lam__0(v_head_44_);
v___x_46_ = lp_JunkValues_List_foldl___at___00Std_Format_joinSep___at___00Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0_spec__0_spec__2(v_x_39_, v___x_45_, v_tail_41_);
return v___x_46_;
}
}
}
}
static lean_object* _init_lp_JunkValues_Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0___closed__5(void){
_start:
{
lean_object* v___x_55_; lean_object* v___x_56_; 
v___x_55_ = ((lean_object*)(lp_JunkValues_Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0___closed__0));
v___x_56_ = lean_string_length(v___x_55_);
return v___x_56_;
}
}
static lean_object* _init_lp_JunkValues_Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0___closed__6(void){
_start:
{
lean_object* v___x_57_; lean_object* v___x_58_; 
v___x_57_ = lean_obj_once(&lp_JunkValues_Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0___closed__5, &lp_JunkValues_Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0___closed__5_once, _init_lp_JunkValues_Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0___closed__5);
v___x_58_ = lean_nat_to_int(v___x_57_);
return v___x_58_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0(lean_object* v_xs_66_){
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
v___x_71_ = ((lean_object*)(lp_JunkValues_Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0___closed__3));
v___x_72_ = lp_JunkValues_Std_Format_joinSep___at___00Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0_spec__0(v___x_70_, v___x_71_);
v___x_73_ = lean_obj_once(&lp_JunkValues_Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0___closed__6, &lp_JunkValues_Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0___closed__6_once, _init_lp_JunkValues_Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0___closed__6);
v___x_74_ = ((lean_object*)(lp_JunkValues_Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0___closed__7));
v___x_75_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_75_, 0, v___x_74_);
lean_ctor_set(v___x_75_, 1, v___x_72_);
v___x_76_ = ((lean_object*)(lp_JunkValues_Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0___closed__8));
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
v___x_80_ = ((lean_object*)(lp_JunkValues_Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0___closed__10));
return v___x_80_;
}
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__7(void){
_start:
{
lean_object* v___x_94_; lean_object* v___x_95_; 
v___x_94_ = lean_unsigned_to_nat(15u);
v___x_95_ = lean_nat_to_int(v___x_94_);
return v___x_95_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__10(void){
_start:
{
lean_object* v___x_99_; lean_object* v___x_100_; 
v___x_99_ = lean_unsigned_to_nat(8u);
v___x_100_ = lean_nat_to_int(v___x_99_);
return v___x_100_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__13(void){
_start:
{
lean_object* v___x_104_; lean_object* v___x_105_; 
v___x_104_ = lean_unsigned_to_nat(14u);
v___x_105_ = lean_nat_to_int(v___x_104_);
return v___x_105_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__15(void){
_start:
{
lean_object* v___x_107_; lean_object* v___x_108_; 
v___x_107_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__0));
v___x_108_ = lean_string_length(v___x_107_);
return v___x_108_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__16(void){
_start:
{
lean_object* v___x_109_; lean_object* v___x_110_; 
v___x_109_ = lean_obj_once(&lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__15, &lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__15_once, _init_lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__15);
v___x_110_ = lean_nat_to_int(v___x_109_);
return v___x_110_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg(lean_object* v_x_115_){
_start:
{
lean_object* v_theoremName_116_; lean_object* v_note_117_; lean_object* v_generalize_118_; lean_object* v___x_119_; lean_object* v___x_120_; lean_object* v___x_121_; lean_object* v___x_122_; lean_object* v___x_123_; lean_object* v___x_124_; uint8_t v___x_125_; lean_object* v___x_126_; lean_object* v___x_127_; lean_object* v___x_128_; lean_object* v___x_129_; lean_object* v___x_130_; lean_object* v___x_131_; lean_object* v___x_132_; lean_object* v___x_133_; lean_object* v___x_134_; lean_object* v___x_135_; lean_object* v___x_136_; lean_object* v___x_137_; lean_object* v___x_138_; lean_object* v___x_139_; lean_object* v___x_140_; lean_object* v___x_141_; lean_object* v___x_142_; lean_object* v___x_143_; lean_object* v___x_144_; lean_object* v___x_145_; lean_object* v___x_146_; lean_object* v___x_147_; lean_object* v___x_148_; lean_object* v___x_149_; lean_object* v___x_150_; lean_object* v___x_151_; lean_object* v___x_152_; lean_object* v___x_153_; lean_object* v___x_154_; lean_object* v___x_155_; lean_object* v___x_156_; lean_object* v___x_157_; 
v_theoremName_116_ = lean_ctor_get(v_x_115_, 0);
lean_inc(v_theoremName_116_);
v_note_117_ = lean_ctor_get(v_x_115_, 1);
lean_inc_ref(v_note_117_);
v_generalize_118_ = lean_ctor_get(v_x_115_, 2);
lean_inc_ref(v_generalize_118_);
lean_dec_ref(v_x_115_);
v___x_119_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__5));
v___x_120_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__6));
v___x_121_ = lean_obj_once(&lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__7, &lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__7_once, _init_lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__7);
v___x_122_ = lean_unsigned_to_nat(0u);
v___x_123_ = l_Lean_Name_reprPrec(v_theoremName_116_, v___x_122_);
v___x_124_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_124_, 0, v___x_121_);
lean_ctor_set(v___x_124_, 1, v___x_123_);
v___x_125_ = 0;
v___x_126_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_126_, 0, v___x_124_);
lean_ctor_set_uint8(v___x_126_, sizeof(void*)*1, v___x_125_);
v___x_127_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_127_, 0, v___x_120_);
lean_ctor_set(v___x_127_, 1, v___x_126_);
v___x_128_ = ((lean_object*)(lp_JunkValues_Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0___closed__2));
v___x_129_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_129_, 0, v___x_127_);
lean_ctor_set(v___x_129_, 1, v___x_128_);
v___x_130_ = lean_box(1);
v___x_131_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_131_, 0, v___x_129_);
lean_ctor_set(v___x_131_, 1, v___x_130_);
v___x_132_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__9));
v___x_133_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_133_, 0, v___x_131_);
lean_ctor_set(v___x_133_, 1, v___x_132_);
v___x_134_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_134_, 0, v___x_133_);
lean_ctor_set(v___x_134_, 1, v___x_119_);
v___x_135_ = lean_obj_once(&lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__10, &lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__10_once, _init_lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__10);
v___x_136_ = l_String_quote(v_note_117_);
v___x_137_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_137_, 0, v___x_136_);
v___x_138_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_138_, 0, v___x_135_);
lean_ctor_set(v___x_138_, 1, v___x_137_);
v___x_139_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_139_, 0, v___x_138_);
lean_ctor_set_uint8(v___x_139_, sizeof(void*)*1, v___x_125_);
v___x_140_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_140_, 0, v___x_134_);
lean_ctor_set(v___x_140_, 1, v___x_139_);
v___x_141_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_141_, 0, v___x_140_);
lean_ctor_set(v___x_141_, 1, v___x_128_);
v___x_142_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_142_, 0, v___x_141_);
lean_ctor_set(v___x_142_, 1, v___x_130_);
v___x_143_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__12));
v___x_144_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_144_, 0, v___x_142_);
lean_ctor_set(v___x_144_, 1, v___x_143_);
v___x_145_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_145_, 0, v___x_144_);
lean_ctor_set(v___x_145_, 1, v___x_119_);
v___x_146_ = lean_obj_once(&lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__13, &lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__13_once, _init_lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__13);
v___x_147_ = lp_JunkValues_Array_repr___at___00JunkValues_instReprCatalogueEntry_repr_spec__0(v_generalize_118_);
v___x_148_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_148_, 0, v___x_146_);
lean_ctor_set(v___x_148_, 1, v___x_147_);
v___x_149_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_149_, 0, v___x_148_);
lean_ctor_set_uint8(v___x_149_, sizeof(void*)*1, v___x_125_);
v___x_150_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_150_, 0, v___x_145_);
lean_ctor_set(v___x_150_, 1, v___x_149_);
v___x_151_ = lean_obj_once(&lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__16, &lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__16_once, _init_lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__16);
v___x_152_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__17));
v___x_153_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_153_, 0, v___x_152_);
lean_ctor_set(v___x_153_, 1, v___x_150_);
v___x_154_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__18));
v___x_155_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_155_, 0, v___x_153_);
lean_ctor_set(v___x_155_, 1, v___x_154_);
v___x_156_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_156_, 0, v___x_151_);
lean_ctor_set(v___x_156_, 1, v___x_155_);
v___x_157_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_157_, 0, v___x_156_);
lean_ctor_set_uint8(v___x_157_, sizeof(void*)*1, v___x_125_);
return v___x_157_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instReprCatalogueEntry_repr(lean_object* v_x_158_, lean_object* v_prec_159_){
_start:
{
lean_object* v___x_160_; 
v___x_160_ = lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg(v_x_158_);
return v___x_160_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___boxed(lean_object* v_x_161_, lean_object* v_prec_162_){
_start:
{
lean_object* v_res_163_; 
v_res_163_ = lp_JunkValues_JunkValues_instReprCatalogueEntry_repr(v_x_161_, v_prec_162_);
lean_dec(v_prec_162_);
return v_res_163_;
}
}
LEAN_EXPORT uint8_t lp_JunkValues_Array_isEqvAux___at___00JunkValues_instBEqCatalogueEntry_beq_spec__0___redArg(lean_object* v_xs_175_, lean_object* v_ys_176_, lean_object* v_x_177_){
_start:
{
lean_object* v_zero_178_; uint8_t v_isZero_179_; 
v_zero_178_ = lean_unsigned_to_nat(0u);
v_isZero_179_ = lean_nat_dec_eq(v_x_177_, v_zero_178_);
if (v_isZero_179_ == 1)
{
lean_dec(v_x_177_);
return v_isZero_179_;
}
else
{
lean_object* v_one_180_; lean_object* v_n_181_; lean_object* v___x_182_; lean_object* v___x_183_; uint8_t v___x_184_; 
v_one_180_ = lean_unsigned_to_nat(1u);
v_n_181_ = lean_nat_sub(v_x_177_, v_one_180_);
lean_dec(v_x_177_);
v___x_182_ = lean_array_fget_borrowed(v_xs_175_, v_n_181_);
v___x_183_ = lean_array_fget_borrowed(v_ys_176_, v_n_181_);
v___x_184_ = lean_nat_dec_eq(v___x_182_, v___x_183_);
if (v___x_184_ == 0)
{
lean_dec(v_n_181_);
return v___x_184_;
}
else
{
v_x_177_ = v_n_181_;
goto _start;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Array_isEqvAux___at___00JunkValues_instBEqCatalogueEntry_beq_spec__0___redArg___boxed(lean_object* v_xs_186_, lean_object* v_ys_187_, lean_object* v_x_188_){
_start:
{
uint8_t v_res_189_; lean_object* v_r_190_; 
v_res_189_ = lp_JunkValues_Array_isEqvAux___at___00JunkValues_instBEqCatalogueEntry_beq_spec__0___redArg(v_xs_186_, v_ys_187_, v_x_188_);
lean_dec_ref(v_ys_187_);
lean_dec_ref(v_xs_186_);
v_r_190_ = lean_box(v_res_189_);
return v_r_190_;
}
}
LEAN_EXPORT uint8_t lp_JunkValues_JunkValues_instBEqCatalogueEntry_beq(lean_object* v_x_191_, lean_object* v_x_192_){
_start:
{
lean_object* v_theoremName_193_; lean_object* v_note_194_; lean_object* v_generalize_195_; lean_object* v_theoremName_196_; lean_object* v_note_197_; lean_object* v_generalize_198_; uint8_t v___x_199_; 
v_theoremName_193_ = lean_ctor_get(v_x_191_, 0);
v_note_194_ = lean_ctor_get(v_x_191_, 1);
v_generalize_195_ = lean_ctor_get(v_x_191_, 2);
v_theoremName_196_ = lean_ctor_get(v_x_192_, 0);
v_note_197_ = lean_ctor_get(v_x_192_, 1);
v_generalize_198_ = lean_ctor_get(v_x_192_, 2);
v___x_199_ = lean_name_eq(v_theoremName_193_, v_theoremName_196_);
if (v___x_199_ == 0)
{
return v___x_199_;
}
else
{
uint8_t v___x_200_; 
v___x_200_ = lean_string_dec_eq(v_note_194_, v_note_197_);
if (v___x_200_ == 0)
{
return v___x_200_;
}
else
{
lean_object* v___x_201_; lean_object* v___x_202_; uint8_t v___x_203_; 
v___x_201_ = lean_array_get_size(v_generalize_195_);
v___x_202_ = lean_array_get_size(v_generalize_198_);
v___x_203_ = lean_nat_dec_eq(v___x_201_, v___x_202_);
if (v___x_203_ == 0)
{
return v___x_203_;
}
else
{
uint8_t v___x_204_; 
v___x_204_ = lp_JunkValues_Array_isEqvAux___at___00JunkValues_instBEqCatalogueEntry_beq_spec__0___redArg(v_generalize_195_, v_generalize_198_, v___x_201_);
return v___x_204_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instBEqCatalogueEntry_beq___boxed(lean_object* v_x_205_, lean_object* v_x_206_){
_start:
{
uint8_t v_res_207_; lean_object* v_r_208_; 
v_res_207_ = lp_JunkValues_JunkValues_instBEqCatalogueEntry_beq(v_x_205_, v_x_206_);
lean_dec_ref(v_x_206_);
lean_dec_ref(v_x_205_);
v_r_208_ = lean_box(v_res_207_);
return v_r_208_;
}
}
LEAN_EXPORT uint8_t lp_JunkValues_Array_isEqvAux___at___00JunkValues_instBEqCatalogueEntry_beq_spec__0(lean_object* v_xs_209_, lean_object* v_ys_210_, lean_object* v_hsz_211_, lean_object* v_x_212_, lean_object* v_x_213_){
_start:
{
uint8_t v___x_214_; 
v___x_214_ = lp_JunkValues_Array_isEqvAux___at___00JunkValues_instBEqCatalogueEntry_beq_spec__0___redArg(v_xs_209_, v_ys_210_, v_x_212_);
return v___x_214_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Array_isEqvAux___at___00JunkValues_instBEqCatalogueEntry_beq_spec__0___boxed(lean_object* v_xs_215_, lean_object* v_ys_216_, lean_object* v_hsz_217_, lean_object* v_x_218_, lean_object* v_x_219_){
_start:
{
uint8_t v_res_220_; lean_object* v_r_221_; 
v_res_220_ = lp_JunkValues_Array_isEqvAux___at___00JunkValues_instBEqCatalogueEntry_beq_spec__0(v_xs_215_, v_ys_216_, v_hsz_217_, v_x_218_, v_x_219_);
lean_dec_ref(v_ys_216_);
lean_dec_ref(v_xs_215_);
v_r_221_ = lean_box(v_res_220_);
return v_r_221_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_checkCatalogue_spec__0(lean_object* v_as_230_, size_t v_sz_231_, size_t v_i_232_, lean_object* v_b_233_, lean_object* v___y_234_, lean_object* v___y_235_, lean_object* v___y_236_, lean_object* v___y_237_){
_start:
{
lean_object* v_a_240_; uint8_t v___x_244_; 
v___x_244_ = lean_usize_dec_lt(v_i_232_, v_sz_231_);
if (v___x_244_ == 0)
{
lean_object* v___x_245_; 
v___x_245_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_245_, 0, v_b_233_);
return v___x_245_;
}
else
{
lean_object* v___x_246_; lean_object* v_env_247_; lean_object* v_a_248_; lean_object* v_theoremName_249_; lean_object* v_note_250_; lean_object* v_generalize_251_; uint8_t v___x_252_; lean_object* v___x_253_; 
v___x_246_ = lean_st_ref_get(v___y_237_);
v_env_247_ = lean_ctor_get(v___x_246_, 0);
lean_inc_ref(v_env_247_);
lean_dec(v___x_246_);
v_a_248_ = lean_array_uget_borrowed(v_as_230_, v_i_232_);
v_theoremName_249_ = lean_ctor_get(v_a_248_, 0);
v_note_250_ = lean_ctor_get(v_a_248_, 1);
v_generalize_251_ = lean_ctor_get(v_a_248_, 2);
v___x_252_ = 0;
lean_inc(v_theoremName_249_);
v___x_253_ = l_Lean_Environment_find_x3f(v_env_247_, v_theoremName_249_, v___x_252_);
if (lean_obj_tag(v___x_253_) == 0)
{
lean_object* v_rules_254_; lean_object* v_unresolved_255_; lean_object* v_rejected_256_; lean_object* v___x_258_; uint8_t v_isShared_259_; uint8_t v_isSharedCheck_264_; 
v_rules_254_ = lean_ctor_get(v_b_233_, 0);
v_unresolved_255_ = lean_ctor_get(v_b_233_, 1);
v_rejected_256_ = lean_ctor_get(v_b_233_, 2);
v_isSharedCheck_264_ = !lean_is_exclusive(v_b_233_);
if (v_isSharedCheck_264_ == 0)
{
v___x_258_ = v_b_233_;
v_isShared_259_ = v_isSharedCheck_264_;
goto v_resetjp_257_;
}
else
{
lean_inc(v_rejected_256_);
lean_inc(v_unresolved_255_);
lean_inc(v_rules_254_);
lean_dec(v_b_233_);
v___x_258_ = lean_box(0);
v_isShared_259_ = v_isSharedCheck_264_;
goto v_resetjp_257_;
}
v_resetjp_257_:
{
lean_object* v___x_260_; lean_object* v___x_262_; 
lean_inc(v_theoremName_249_);
v___x_260_ = lean_array_push(v_unresolved_255_, v_theoremName_249_);
if (v_isShared_259_ == 0)
{
lean_ctor_set(v___x_258_, 1, v___x_260_);
v___x_262_ = v___x_258_;
goto v_reusejp_261_;
}
else
{
lean_object* v_reuseFailAlloc_263_; 
v_reuseFailAlloc_263_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v_reuseFailAlloc_263_, 0, v_rules_254_);
lean_ctor_set(v_reuseFailAlloc_263_, 1, v___x_260_);
lean_ctor_set(v_reuseFailAlloc_263_, 2, v_rejected_256_);
v___x_262_ = v_reuseFailAlloc_263_;
goto v_reusejp_261_;
}
v_reusejp_261_:
{
v_a_240_ = v___x_262_;
goto v___jp_239_;
}
}
}
else
{
lean_object* v___x_265_; 
lean_dec_ref_known(v___x_253_, 1);
lean_inc_ref(v_generalize_251_);
lean_inc_ref(v_note_250_);
lean_inc(v_theoremName_249_);
v___x_265_ = lp_JunkValues_JunkValues_ruleOfTheorem_x3f(v_theoremName_249_, v_note_250_, v_generalize_251_, v___y_234_, v___y_235_, v___y_236_, v___y_237_);
if (lean_obj_tag(v___x_265_) == 0)
{
lean_object* v_a_266_; 
v_a_266_ = lean_ctor_get(v___x_265_, 0);
lean_inc(v_a_266_);
lean_dec_ref_known(v___x_265_, 1);
if (lean_obj_tag(v_a_266_) == 0)
{
lean_object* v_a_267_; lean_object* v_rules_268_; lean_object* v_unresolved_269_; lean_object* v_rejected_270_; lean_object* v___x_272_; uint8_t v_isShared_273_; uint8_t v_isSharedCheck_279_; 
v_a_267_ = lean_ctor_get(v_a_266_, 0);
lean_inc(v_a_267_);
lean_dec_ref_known(v_a_266_, 1);
v_rules_268_ = lean_ctor_get(v_b_233_, 0);
v_unresolved_269_ = lean_ctor_get(v_b_233_, 1);
v_rejected_270_ = lean_ctor_get(v_b_233_, 2);
v_isSharedCheck_279_ = !lean_is_exclusive(v_b_233_);
if (v_isSharedCheck_279_ == 0)
{
v___x_272_ = v_b_233_;
v_isShared_273_ = v_isSharedCheck_279_;
goto v_resetjp_271_;
}
else
{
lean_inc(v_rejected_270_);
lean_inc(v_unresolved_269_);
lean_inc(v_rules_268_);
lean_dec(v_b_233_);
v___x_272_ = lean_box(0);
v_isShared_273_ = v_isSharedCheck_279_;
goto v_resetjp_271_;
}
v_resetjp_271_:
{
lean_object* v___x_274_; lean_object* v___x_275_; lean_object* v___x_277_; 
lean_inc(v_theoremName_249_);
v___x_274_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_274_, 0, v_theoremName_249_);
lean_ctor_set(v___x_274_, 1, v_a_267_);
v___x_275_ = lean_array_push(v_rejected_270_, v___x_274_);
if (v_isShared_273_ == 0)
{
lean_ctor_set(v___x_272_, 2, v___x_275_);
v___x_277_ = v___x_272_;
goto v_reusejp_276_;
}
else
{
lean_object* v_reuseFailAlloc_278_; 
v_reuseFailAlloc_278_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v_reuseFailAlloc_278_, 0, v_rules_268_);
lean_ctor_set(v_reuseFailAlloc_278_, 1, v_unresolved_269_);
lean_ctor_set(v_reuseFailAlloc_278_, 2, v___x_275_);
v___x_277_ = v_reuseFailAlloc_278_;
goto v_reusejp_276_;
}
v_reusejp_276_:
{
v_a_240_ = v___x_277_;
goto v___jp_239_;
}
}
}
else
{
lean_object* v_a_280_; lean_object* v_rules_281_; lean_object* v_unresolved_282_; lean_object* v_rejected_283_; lean_object* v___x_285_; uint8_t v_isShared_286_; uint8_t v_isSharedCheck_291_; 
v_a_280_ = lean_ctor_get(v_a_266_, 0);
lean_inc(v_a_280_);
lean_dec_ref_known(v_a_266_, 1);
v_rules_281_ = lean_ctor_get(v_b_233_, 0);
v_unresolved_282_ = lean_ctor_get(v_b_233_, 1);
v_rejected_283_ = lean_ctor_get(v_b_233_, 2);
v_isSharedCheck_291_ = !lean_is_exclusive(v_b_233_);
if (v_isSharedCheck_291_ == 0)
{
v___x_285_ = v_b_233_;
v_isShared_286_ = v_isSharedCheck_291_;
goto v_resetjp_284_;
}
else
{
lean_inc(v_rejected_283_);
lean_inc(v_unresolved_282_);
lean_inc(v_rules_281_);
lean_dec(v_b_233_);
v___x_285_ = lean_box(0);
v_isShared_286_ = v_isSharedCheck_291_;
goto v_resetjp_284_;
}
v_resetjp_284_:
{
lean_object* v___x_287_; lean_object* v___x_289_; 
v___x_287_ = lean_array_push(v_rules_281_, v_a_280_);
if (v_isShared_286_ == 0)
{
lean_ctor_set(v___x_285_, 0, v___x_287_);
v___x_289_ = v___x_285_;
goto v_reusejp_288_;
}
else
{
lean_object* v_reuseFailAlloc_290_; 
v_reuseFailAlloc_290_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v_reuseFailAlloc_290_, 0, v___x_287_);
lean_ctor_set(v_reuseFailAlloc_290_, 1, v_unresolved_282_);
lean_ctor_set(v_reuseFailAlloc_290_, 2, v_rejected_283_);
v___x_289_ = v_reuseFailAlloc_290_;
goto v_reusejp_288_;
}
v_reusejp_288_:
{
v_a_240_ = v___x_289_;
goto v___jp_239_;
}
}
}
}
else
{
lean_object* v_a_292_; lean_object* v___x_294_; uint8_t v_isShared_295_; uint8_t v_isSharedCheck_299_; 
lean_dec_ref(v_b_233_);
v_a_292_ = lean_ctor_get(v___x_265_, 0);
v_isSharedCheck_299_ = !lean_is_exclusive(v___x_265_);
if (v_isSharedCheck_299_ == 0)
{
v___x_294_ = v___x_265_;
v_isShared_295_ = v_isSharedCheck_299_;
goto v_resetjp_293_;
}
else
{
lean_inc(v_a_292_);
lean_dec(v___x_265_);
v___x_294_ = lean_box(0);
v_isShared_295_ = v_isSharedCheck_299_;
goto v_resetjp_293_;
}
v_resetjp_293_:
{
lean_object* v___x_297_; 
if (v_isShared_295_ == 0)
{
v___x_297_ = v___x_294_;
goto v_reusejp_296_;
}
else
{
lean_object* v_reuseFailAlloc_298_; 
v_reuseFailAlloc_298_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_298_, 0, v_a_292_);
v___x_297_ = v_reuseFailAlloc_298_;
goto v_reusejp_296_;
}
v_reusejp_296_:
{
return v___x_297_;
}
}
}
}
}
v___jp_239_:
{
size_t v___x_241_; size_t v___x_242_; 
v___x_241_ = ((size_t)1ULL);
v___x_242_ = lean_usize_add(v_i_232_, v___x_241_);
v_i_232_ = v___x_242_;
v_b_233_ = v_a_240_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_checkCatalogue_spec__0___boxed(lean_object* v_as_300_, lean_object* v_sz_301_, lean_object* v_i_302_, lean_object* v_b_303_, lean_object* v___y_304_, lean_object* v___y_305_, lean_object* v___y_306_, lean_object* v___y_307_, lean_object* v___y_308_){
_start:
{
size_t v_sz_boxed_309_; size_t v_i_boxed_310_; lean_object* v_res_311_; 
v_sz_boxed_309_ = lean_unbox_usize(v_sz_301_);
lean_dec(v_sz_301_);
v_i_boxed_310_ = lean_unbox_usize(v_i_302_);
lean_dec(v_i_302_);
v_res_311_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_checkCatalogue_spec__0(v_as_300_, v_sz_boxed_309_, v_i_boxed_310_, v_b_303_, v___y_304_, v___y_305_, v___y_306_, v___y_307_);
lean_dec(v___y_307_);
lean_dec_ref(v___y_306_);
lean_dec(v___y_305_);
lean_dec_ref(v___y_304_);
lean_dec_ref(v_as_300_);
return v_res_311_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_checkCatalogue(lean_object* v_catalogue_312_, lean_object* v_a_313_, lean_object* v_a_314_, lean_object* v_a_315_, lean_object* v_a_316_){
_start:
{
lean_object* v_result_318_; size_t v_sz_319_; size_t v___x_320_; lean_object* v___x_321_; 
v_result_318_ = ((lean_object*)(lp_JunkValues_JunkValues_instInhabitedCatalogueCheck_default___closed__1));
v_sz_319_ = lean_array_size(v_catalogue_312_);
v___x_320_ = ((size_t)0ULL);
v___x_321_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_checkCatalogue_spec__0(v_catalogue_312_, v_sz_319_, v___x_320_, v_result_318_, v_a_313_, v_a_314_, v_a_315_, v_a_316_);
return v___x_321_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_checkCatalogue___boxed(lean_object* v_catalogue_322_, lean_object* v_a_323_, lean_object* v_a_324_, lean_object* v_a_325_, lean_object* v_a_326_, lean_object* v_a_327_){
_start:
{
lean_object* v_res_328_; 
v_res_328_ = lp_JunkValues_JunkValues_checkCatalogue(v_catalogue_322_, v_a_323_, v_a_324_, v_a_325_, v_a_326_);
lean_dec(v_a_326_);
lean_dec_ref(v_a_325_);
lean_dec(v_a_324_);
lean_dec_ref(v_a_323_);
lean_dec_ref(v_catalogue_322_);
return v_res_328_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_catalogueProvider_spec__0___redArg(lean_object* v_name_331_, lean_object* v_as_332_, size_t v_sz_333_, size_t v_i_334_, lean_object* v_b_335_){
_start:
{
uint8_t v___x_337_; 
v___x_337_ = lean_usize_dec_lt(v_i_334_, v_sz_333_);
if (v___x_337_ == 0)
{
lean_object* v___x_338_; 
lean_dec_ref(v_name_331_);
v___x_338_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_338_, 0, v_b_335_);
return v___x_338_;
}
else
{
lean_object* v_a_339_; lean_object* v___x_340_; lean_object* v___x_341_; lean_object* v___x_342_; lean_object* v___x_343_; lean_object* v___x_344_; lean_object* v___x_345_; lean_object* v___x_346_; size_t v___x_347_; size_t v___x_348_; 
v_a_339_ = lean_array_uget_borrowed(v_as_332_, v_i_334_);
v___x_340_ = ((lean_object*)(lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_catalogueProvider_spec__0___redArg___closed__0));
lean_inc_ref(v_name_331_);
v___x_341_ = lean_string_append(v_name_331_, v___x_340_);
lean_inc(v_a_339_);
v___x_342_ = l_Lean_Name_toStringWithToken___at___00Lean_Name_toString_spec__0(v_a_339_, v___x_337_);
v___x_343_ = lean_string_append(v___x_341_, v___x_342_);
lean_dec_ref(v___x_342_);
v___x_344_ = ((lean_object*)(lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_catalogueProvider_spec__0___redArg___closed__1));
v___x_345_ = lean_string_append(v___x_343_, v___x_344_);
v___x_346_ = lean_array_push(v_b_335_, v___x_345_);
v___x_347_ = ((size_t)1ULL);
v___x_348_ = lean_usize_add(v_i_334_, v___x_347_);
v_i_334_ = v___x_348_;
v_b_335_ = v___x_346_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_catalogueProvider_spec__0___redArg___boxed(lean_object* v_name_350_, lean_object* v_as_351_, lean_object* v_sz_352_, lean_object* v_i_353_, lean_object* v_b_354_, lean_object* v___y_355_){
_start:
{
size_t v_sz_boxed_356_; size_t v_i_boxed_357_; lean_object* v_res_358_; 
v_sz_boxed_356_ = lean_unbox_usize(v_sz_352_);
lean_dec(v_sz_352_);
v_i_boxed_357_ = lean_unbox_usize(v_i_353_);
lean_dec(v_i_353_);
v_res_358_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_catalogueProvider_spec__0___redArg(v_name_350_, v_as_351_, v_sz_boxed_356_, v_i_boxed_357_, v_b_354_);
lean_dec_ref(v_as_351_);
return v_res_358_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_catalogueProvider_spec__1___redArg(lean_object* v_name_361_, lean_object* v_as_362_, size_t v_sz_363_, size_t v_i_364_, lean_object* v_b_365_){
_start:
{
uint8_t v___x_367_; 
v___x_367_ = lean_usize_dec_lt(v_i_364_, v_sz_363_);
if (v___x_367_ == 0)
{
lean_object* v___x_368_; 
lean_dec_ref(v_name_361_);
v___x_368_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_368_, 0, v_b_365_);
return v___x_368_;
}
else
{
lean_object* v_a_369_; lean_object* v_fst_370_; lean_object* v_snd_371_; lean_object* v___x_372_; lean_object* v___x_373_; lean_object* v___x_374_; lean_object* v___x_375_; lean_object* v___x_376_; lean_object* v___x_377_; lean_object* v___x_378_; lean_object* v___x_379_; lean_object* v___x_380_; lean_object* v___x_381_; size_t v___x_382_; size_t v___x_383_; 
v_a_369_ = lean_array_uget_borrowed(v_as_362_, v_i_364_);
v_fst_370_ = lean_ctor_get(v_a_369_, 0);
v_snd_371_ = lean_ctor_get(v_a_369_, 1);
v___x_372_ = ((lean_object*)(lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_catalogueProvider_spec__0___redArg___closed__0));
lean_inc_ref(v_name_361_);
v___x_373_ = lean_string_append(v_name_361_, v___x_372_);
lean_inc(v_fst_370_);
v___x_374_ = l_Lean_Name_toStringWithToken___at___00Lean_Name_toString_spec__0(v_fst_370_, v___x_367_);
v___x_375_ = lean_string_append(v___x_373_, v___x_374_);
lean_dec_ref(v___x_374_);
v___x_376_ = ((lean_object*)(lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_catalogueProvider_spec__1___redArg___closed__0));
v___x_377_ = lean_string_append(v___x_375_, v___x_376_);
v___x_378_ = lean_string_append(v___x_377_, v_snd_371_);
v___x_379_ = ((lean_object*)(lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_catalogueProvider_spec__1___redArg___closed__1));
v___x_380_ = lean_string_append(v___x_378_, v___x_379_);
v___x_381_ = lean_array_push(v_b_365_, v___x_380_);
v___x_382_ = ((size_t)1ULL);
v___x_383_ = lean_usize_add(v_i_364_, v___x_382_);
v_i_364_ = v___x_383_;
v_b_365_ = v___x_381_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_catalogueProvider_spec__1___redArg___boxed(lean_object* v_name_385_, lean_object* v_as_386_, lean_object* v_sz_387_, lean_object* v_i_388_, lean_object* v_b_389_, lean_object* v___y_390_){
_start:
{
size_t v_sz_boxed_391_; size_t v_i_boxed_392_; lean_object* v_res_393_; 
v_sz_boxed_391_ = lean_unbox_usize(v_sz_387_);
lean_dec(v_sz_387_);
v_i_boxed_392_ = lean_unbox_usize(v_i_388_);
lean_dec(v_i_388_);
v_res_393_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_catalogueProvider_spec__1___redArg(v_name_385_, v_as_386_, v_sz_boxed_391_, v_i_boxed_392_, v_b_389_);
lean_dec_ref(v_as_386_);
return v_res_393_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_catalogueProvider___lam__0(lean_object* v_catalogue_396_, lean_object* v_name_397_, lean_object* v_x_398_, lean_object* v___y_399_, lean_object* v___y_400_, lean_object* v___y_401_, lean_object* v___y_402_){
_start:
{
lean_object* v___x_404_; 
v___x_404_ = lp_JunkValues_JunkValues_checkCatalogue(v_catalogue_396_, v___y_399_, v___y_400_, v___y_401_, v___y_402_);
if (lean_obj_tag(v___x_404_) == 0)
{
lean_object* v_a_405_; lean_object* v_rules_406_; lean_object* v_unresolved_407_; lean_object* v_rejected_408_; lean_object* v___x_409_; size_t v_sz_410_; size_t v___x_411_; lean_object* v___x_412_; 
v_a_405_ = lean_ctor_get(v___x_404_, 0);
lean_inc(v_a_405_);
lean_dec_ref_known(v___x_404_, 1);
v_rules_406_ = lean_ctor_get(v_a_405_, 0);
lean_inc_ref(v_rules_406_);
v_unresolved_407_ = lean_ctor_get(v_a_405_, 1);
lean_inc_ref(v_unresolved_407_);
v_rejected_408_ = lean_ctor_get(v_a_405_, 2);
lean_inc_ref(v_rejected_408_);
lean_dec(v_a_405_);
v___x_409_ = ((lean_object*)(lp_JunkValues_JunkValues_catalogueProvider___lam__0___closed__0));
v_sz_410_ = lean_array_size(v_unresolved_407_);
v___x_411_ = ((size_t)0ULL);
lean_inc_ref(v_name_397_);
v___x_412_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_catalogueProvider_spec__0___redArg(v_name_397_, v_unresolved_407_, v_sz_410_, v___x_411_, v___x_409_);
lean_dec_ref(v_unresolved_407_);
if (lean_obj_tag(v___x_412_) == 0)
{
lean_object* v_a_413_; size_t v_sz_414_; lean_object* v___x_415_; 
v_a_413_ = lean_ctor_get(v___x_412_, 0);
lean_inc(v_a_413_);
lean_dec_ref_known(v___x_412_, 1);
v_sz_414_ = lean_array_size(v_rejected_408_);
v___x_415_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_catalogueProvider_spec__1___redArg(v_name_397_, v_rejected_408_, v_sz_414_, v___x_411_, v_a_413_);
lean_dec_ref(v_rejected_408_);
if (lean_obj_tag(v___x_415_) == 0)
{
lean_object* v_a_416_; lean_object* v___x_418_; uint8_t v_isShared_419_; uint8_t v_isSharedCheck_424_; 
v_a_416_ = lean_ctor_get(v___x_415_, 0);
v_isSharedCheck_424_ = !lean_is_exclusive(v___x_415_);
if (v_isSharedCheck_424_ == 0)
{
v___x_418_ = v___x_415_;
v_isShared_419_ = v_isSharedCheck_424_;
goto v_resetjp_417_;
}
else
{
lean_inc(v_a_416_);
lean_dec(v___x_415_);
v___x_418_ = lean_box(0);
v_isShared_419_ = v_isSharedCheck_424_;
goto v_resetjp_417_;
}
v_resetjp_417_:
{
lean_object* v___x_420_; lean_object* v___x_422_; 
v___x_420_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_420_, 0, v_rules_406_);
lean_ctor_set(v___x_420_, 1, v_a_416_);
if (v_isShared_419_ == 0)
{
lean_ctor_set(v___x_418_, 0, v___x_420_);
v___x_422_ = v___x_418_;
goto v_reusejp_421_;
}
else
{
lean_object* v_reuseFailAlloc_423_; 
v_reuseFailAlloc_423_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_423_, 0, v___x_420_);
v___x_422_ = v_reuseFailAlloc_423_;
goto v_reusejp_421_;
}
v_reusejp_421_:
{
return v___x_422_;
}
}
}
else
{
lean_object* v_a_425_; lean_object* v___x_427_; uint8_t v_isShared_428_; uint8_t v_isSharedCheck_432_; 
lean_dec_ref(v_rules_406_);
v_a_425_ = lean_ctor_get(v___x_415_, 0);
v_isSharedCheck_432_ = !lean_is_exclusive(v___x_415_);
if (v_isSharedCheck_432_ == 0)
{
v___x_427_ = v___x_415_;
v_isShared_428_ = v_isSharedCheck_432_;
goto v_resetjp_426_;
}
else
{
lean_inc(v_a_425_);
lean_dec(v___x_415_);
v___x_427_ = lean_box(0);
v_isShared_428_ = v_isSharedCheck_432_;
goto v_resetjp_426_;
}
v_resetjp_426_:
{
lean_object* v___x_430_; 
if (v_isShared_428_ == 0)
{
v___x_430_ = v___x_427_;
goto v_reusejp_429_;
}
else
{
lean_object* v_reuseFailAlloc_431_; 
v_reuseFailAlloc_431_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_431_, 0, v_a_425_);
v___x_430_ = v_reuseFailAlloc_431_;
goto v_reusejp_429_;
}
v_reusejp_429_:
{
return v___x_430_;
}
}
}
}
else
{
lean_object* v_a_433_; lean_object* v___x_435_; uint8_t v_isShared_436_; uint8_t v_isSharedCheck_440_; 
lean_dec_ref(v_rejected_408_);
lean_dec_ref(v_rules_406_);
lean_dec_ref(v_name_397_);
v_a_433_ = lean_ctor_get(v___x_412_, 0);
v_isSharedCheck_440_ = !lean_is_exclusive(v___x_412_);
if (v_isSharedCheck_440_ == 0)
{
v___x_435_ = v___x_412_;
v_isShared_436_ = v_isSharedCheck_440_;
goto v_resetjp_434_;
}
else
{
lean_inc(v_a_433_);
lean_dec(v___x_412_);
v___x_435_ = lean_box(0);
v_isShared_436_ = v_isSharedCheck_440_;
goto v_resetjp_434_;
}
v_resetjp_434_:
{
lean_object* v___x_438_; 
if (v_isShared_436_ == 0)
{
v___x_438_ = v___x_435_;
goto v_reusejp_437_;
}
else
{
lean_object* v_reuseFailAlloc_439_; 
v_reuseFailAlloc_439_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_439_, 0, v_a_433_);
v___x_438_ = v_reuseFailAlloc_439_;
goto v_reusejp_437_;
}
v_reusejp_437_:
{
return v___x_438_;
}
}
}
}
else
{
lean_object* v_a_441_; lean_object* v___x_443_; uint8_t v_isShared_444_; uint8_t v_isSharedCheck_448_; 
lean_dec_ref(v_name_397_);
v_a_441_ = lean_ctor_get(v___x_404_, 0);
v_isSharedCheck_448_ = !lean_is_exclusive(v___x_404_);
if (v_isSharedCheck_448_ == 0)
{
v___x_443_ = v___x_404_;
v_isShared_444_ = v_isSharedCheck_448_;
goto v_resetjp_442_;
}
else
{
lean_inc(v_a_441_);
lean_dec(v___x_404_);
v___x_443_ = lean_box(0);
v_isShared_444_ = v_isSharedCheck_448_;
goto v_resetjp_442_;
}
v_resetjp_442_:
{
lean_object* v___x_446_; 
if (v_isShared_444_ == 0)
{
v___x_446_ = v___x_443_;
goto v_reusejp_445_;
}
else
{
lean_object* v_reuseFailAlloc_447_; 
v_reuseFailAlloc_447_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_447_, 0, v_a_441_);
v___x_446_ = v_reuseFailAlloc_447_;
goto v_reusejp_445_;
}
v_reusejp_445_:
{
return v___x_446_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_catalogueProvider___lam__0___boxed(lean_object* v_catalogue_449_, lean_object* v_name_450_, lean_object* v_x_451_, lean_object* v___y_452_, lean_object* v___y_453_, lean_object* v___y_454_, lean_object* v___y_455_, lean_object* v___y_456_){
_start:
{
lean_object* v_res_457_; 
v_res_457_ = lp_JunkValues_JunkValues_catalogueProvider___lam__0(v_catalogue_449_, v_name_450_, v_x_451_, v___y_452_, v___y_453_, v___y_454_, v___y_455_);
lean_dec(v___y_455_);
lean_dec_ref(v___y_454_);
lean_dec(v___y_453_);
lean_dec_ref(v___y_452_);
lean_dec_ref(v_x_451_);
lean_dec_ref(v_catalogue_449_);
return v_res_457_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_catalogueProvider(lean_object* v_name_458_, lean_object* v_catalogue_459_){
_start:
{
lean_object* v___f_460_; lean_object* v___x_461_; 
lean_inc_ref(v_name_458_);
v___f_460_ = lean_alloc_closure((void*)(lp_JunkValues_JunkValues_catalogueProvider___lam__0___boxed), 8, 2);
lean_closure_set(v___f_460_, 0, v_catalogue_459_);
lean_closure_set(v___f_460_, 1, v_name_458_);
v___x_461_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_461_, 0, v_name_458_);
lean_ctor_set(v___x_461_, 1, v___f_460_);
return v___x_461_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_catalogueProvider_spec__0(lean_object* v_name_462_, lean_object* v_as_463_, size_t v_sz_464_, size_t v_i_465_, lean_object* v_b_466_, lean_object* v___y_467_, lean_object* v___y_468_, lean_object* v___y_469_, lean_object* v___y_470_){
_start:
{
lean_object* v___x_472_; 
v___x_472_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_catalogueProvider_spec__0___redArg(v_name_462_, v_as_463_, v_sz_464_, v_i_465_, v_b_466_);
return v___x_472_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_catalogueProvider_spec__0___boxed(lean_object* v_name_473_, lean_object* v_as_474_, lean_object* v_sz_475_, lean_object* v_i_476_, lean_object* v_b_477_, lean_object* v___y_478_, lean_object* v___y_479_, lean_object* v___y_480_, lean_object* v___y_481_, lean_object* v___y_482_){
_start:
{
size_t v_sz_boxed_483_; size_t v_i_boxed_484_; lean_object* v_res_485_; 
v_sz_boxed_483_ = lean_unbox_usize(v_sz_475_);
lean_dec(v_sz_475_);
v_i_boxed_484_ = lean_unbox_usize(v_i_476_);
lean_dec(v_i_476_);
v_res_485_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_catalogueProvider_spec__0(v_name_473_, v_as_474_, v_sz_boxed_483_, v_i_boxed_484_, v_b_477_, v___y_478_, v___y_479_, v___y_480_, v___y_481_);
lean_dec(v___y_481_);
lean_dec_ref(v___y_480_);
lean_dec(v___y_479_);
lean_dec_ref(v___y_478_);
lean_dec_ref(v_as_474_);
return v_res_485_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_catalogueProvider_spec__1(lean_object* v_name_486_, lean_object* v_as_487_, size_t v_sz_488_, size_t v_i_489_, lean_object* v_b_490_, lean_object* v___y_491_, lean_object* v___y_492_, lean_object* v___y_493_, lean_object* v___y_494_){
_start:
{
lean_object* v___x_496_; 
v___x_496_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_catalogueProvider_spec__1___redArg(v_name_486_, v_as_487_, v_sz_488_, v_i_489_, v_b_490_);
return v___x_496_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_catalogueProvider_spec__1___boxed(lean_object* v_name_497_, lean_object* v_as_498_, lean_object* v_sz_499_, lean_object* v_i_500_, lean_object* v_b_501_, lean_object* v___y_502_, lean_object* v___y_503_, lean_object* v___y_504_, lean_object* v___y_505_, lean_object* v___y_506_){
_start:
{
size_t v_sz_boxed_507_; size_t v_i_boxed_508_; lean_object* v_res_509_; 
v_sz_boxed_507_ = lean_unbox_usize(v_sz_499_);
lean_dec(v_sz_499_);
v_i_boxed_508_ = lean_unbox_usize(v_i_500_);
lean_dec(v_i_500_);
v_res_509_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_catalogueProvider_spec__1(v_name_497_, v_as_498_, v_sz_boxed_507_, v_i_boxed_508_, v_b_501_, v___y_502_, v___y_503_, v___y_504_, v___y_505_);
lean_dec(v___y_505_);
lean_dec_ref(v___y_504_);
lean_dec(v___y_503_);
lean_dec_ref(v___y_502_);
lean_dec_ref(v_as_498_);
return v_res_509_;
}
}
lean_object* runtime_initialize_Init(uint8_t builtin);
lean_object* runtime_initialize_JunkValues_JunkValues_RuleSet(uint8_t builtin);
static bool _G_runtime_initialized = false;
LEAN_EXPORT lean_object* runtime_initialize_JunkValues_JunkValues_Extra_Entry(uint8_t builtin) {
lean_object * res;
if (_G_runtime_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_runtime_initialized = true;
res = runtime_initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = runtime_initialize_JunkValues_JunkValues_RuleSet(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return lean_io_result_mk_ok(lean_box(0));
}
lean_object* runtime_initialize_Init(uint8_t builtin);
static bool _G_meta_initialized = false;
LEAN_EXPORT lean_object* meta_initialize_JunkValues_JunkValues_Extra_Entry(uint8_t builtin) {
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
lean_object* initialize_JunkValues_JunkValues_RuleSet(uint8_t builtin);
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_JunkValues_JunkValues_Extra_Entry(uint8_t builtin) {
lean_object * res;
if (_G_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_initialized = true;
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_JunkValues_JunkValues_RuleSet(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = runtime_initialize_JunkValues_JunkValues_Extra_Entry(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = meta_initialize_JunkValues_JunkValues_Extra_Entry(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return initialize_JunkValues_JunkValues_Extra_Entry(builtin);
}
#ifdef __cplusplus
}
#endif
