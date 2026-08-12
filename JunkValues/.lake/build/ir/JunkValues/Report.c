// Lean compiler output
// Module: JunkValues.Report
// Imports: public import Init public meta import Init public import Lean public import Std.Data.HashMap public import Std.Data.HashSet
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
lean_object* l_Lean_Name_mkStr1(lean_object*);
lean_object* l_Lean_Name_toStringWithToken___at___00Lean_Name_toString_spec__0(lean_object*, uint8_t);
lean_object* l_Lean_Json_getObjValD(lean_object*, lean_object*);
lean_object* l_Lean_Name_fromJson_x3f(lean_object*);
lean_object* lean_nat_to_int(lean_object*);
lean_object* l_Lean_Name_reprPrec(lean_object*, lean_object*);
lean_object* l_Repr_addAppParen(lean_object*, lean_object*);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
lean_object* l_String_quote(lean_object*);
lean_object* lean_array_get_size(lean_object*);
uint8_t lean_nat_dec_eq(lean_object*, lean_object*);
lean_object* lean_array_to_list(lean_object*);
lean_object* lean_string_length(lean_object*);
lean_object* l_Std_Format_fill(lean_object*);
lean_object* l_Lean_Name_mkStr2(lean_object*, lean_object*);
lean_object* lean_string_append(lean_object*, lean_object*);
uint8_t lean_name_eq(lean_object*, lean_object*);
lean_object* l_Lean_Json_getTag_x3f(lean_object*);
uint8_t lean_string_dec_eq(lean_object*, lean_object*);
lean_object* lean_mk_empty_array_with_capacity(lean_object*);
lean_object* lean_array_push(lean_object*, lean_object*);
lean_object* l_Lean_Json_parseCtorFields(lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* lean_array_get(lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_Json_getStr_x3f(lean_object*);
uint8_t lean_usize_dec_lt(size_t, size_t);
lean_object* lean_array_uget_borrowed(lean_object*, size_t);
lean_object* lean_array_uset(lean_object*, size_t, lean_object*);
size_t lean_usize_add(size_t, size_t);
lean_object* l_List_foldl___at___00Array_appendList_spec__0___redArg(lean_object*, lean_object*);
size_t lean_array_size(lean_object*);
lean_object* lean_array_uget(lean_object*, size_t);
lean_object* l_Lean_Json_mkObj(lean_object*);
uint8_t lean_usize_dec_eq(size_t, size_t);
uint64_t lean_uint64_shift_right(uint64_t, uint64_t);
uint64_t lean_uint64_xor(uint64_t, uint64_t);
size_t lean_uint64_to_usize(uint64_t);
size_t lean_usize_of_nat(lean_object*);
size_t lean_usize_sub(size_t, size_t);
size_t lean_usize_land(size_t, size_t);
lean_object* lean_nat_add(lean_object*, lean_object*);
lean_object* lean_nat_mul(lean_object*, lean_object*);
lean_object* lean_nat_div(lean_object*, lean_object*);
lean_object* lean_mk_array(lean_object*, lean_object*);
uint8_t lean_nat_dec_lt(lean_object*, lean_object*);
lean_object* lean_array_fget(lean_object*, lean_object*);
lean_object* lean_array_fset(lean_object*, lean_object*, lean_object*);
uint64_t lean_uint64_of_nat(lean_object*);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
lean_object* lean_mk_empty_array_with_capacity(lean_object*);
lean_object* l_Lean_Json_pretty(lean_object*, lean_object*);
lean_object* l_String_intercalate(lean_object*, lean_object*);
lean_object* lean_string_utf8_byte_size(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Status_ctorIdx(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Status_ctorIdx___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Status_ctorElim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Status_ctorElim(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Status_ctorElim___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Status_guarded_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Status_guarded_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Status_unguarded_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Status_unguarded_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Status_triggered_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Status_triggered_elim(lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object lp_JunkValues_JunkValues_instReprStatus_repr___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 28, .m_capacity = 28, .m_length = 27, .m_data = "JunkValues.Status.unguarded"};
static const lean_object* lp_JunkValues_JunkValues_instReprStatus_repr___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_instReprStatus_repr___closed__0_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instReprStatus_repr___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_instReprStatus_repr___closed__0_value)}};
static const lean_object* lp_JunkValues_JunkValues_instReprStatus_repr___closed__1 = (const lean_object*)&lp_JunkValues_JunkValues_instReprStatus_repr___closed__1_value;
static const lean_string_object lp_JunkValues_JunkValues_instReprStatus_repr___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 26, .m_capacity = 26, .m_length = 25, .m_data = "JunkValues.Status.guarded"};
static const lean_object* lp_JunkValues_JunkValues_instReprStatus_repr___closed__2 = (const lean_object*)&lp_JunkValues_JunkValues_instReprStatus_repr___closed__2_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instReprStatus_repr___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_instReprStatus_repr___closed__2_value)}};
static const lean_object* lp_JunkValues_JunkValues_instReprStatus_repr___closed__3 = (const lean_object*)&lp_JunkValues_JunkValues_instReprStatus_repr___closed__3_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instReprStatus_repr___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_instReprStatus_repr___closed__3_value),((lean_object*)(((size_t)(1) << 1) | 1))}};
static const lean_object* lp_JunkValues_JunkValues_instReprStatus_repr___closed__4 = (const lean_object*)&lp_JunkValues_JunkValues_instReprStatus_repr___closed__4_value;
static lean_once_cell_t lp_JunkValues_JunkValues_instReprStatus_repr___closed__5_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_instReprStatus_repr___closed__5;
static lean_once_cell_t lp_JunkValues_JunkValues_instReprStatus_repr___closed__6_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_instReprStatus_repr___closed__6;
static const lean_string_object lp_JunkValues_JunkValues_instReprStatus_repr___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 28, .m_capacity = 28, .m_length = 27, .m_data = "JunkValues.Status.triggered"};
static const lean_object* lp_JunkValues_JunkValues_instReprStatus_repr___closed__7 = (const lean_object*)&lp_JunkValues_JunkValues_instReprStatus_repr___closed__7_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instReprStatus_repr___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_instReprStatus_repr___closed__7_value)}};
static const lean_object* lp_JunkValues_JunkValues_instReprStatus_repr___closed__8 = (const lean_object*)&lp_JunkValues_JunkValues_instReprStatus_repr___closed__8_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instReprStatus_repr___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_instReprStatus_repr___closed__8_value),((lean_object*)(((size_t)(1) << 1) | 1))}};
static const lean_object* lp_JunkValues_JunkValues_instReprStatus_repr___closed__9 = (const lean_object*)&lp_JunkValues_JunkValues_instReprStatus_repr___closed__9_value;
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instReprStatus_repr(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instReprStatus_repr___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_JunkValues_JunkValues_instReprStatus___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_JunkValues_JunkValues_instReprStatus_repr___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_JunkValues_JunkValues_instReprStatus___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_instReprStatus___closed__0_value;
LEAN_EXPORT const lean_object* lp_JunkValues_JunkValues_instReprStatus = (const lean_object*)&lp_JunkValues_JunkValues_instReprStatus___closed__0_value;
static const lean_string_object lp_JunkValues_JunkValues_instInhabitedStatus_default___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 1, .m_capacity = 1, .m_length = 0, .m_data = ""};
static const lean_object* lp_JunkValues_JunkValues_instInhabitedStatus_default___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_instInhabitedStatus_default___closed__0_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instInhabitedStatus_default___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 0}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_instInhabitedStatus_default___closed__0_value)}};
static const lean_object* lp_JunkValues_JunkValues_instInhabitedStatus_default___closed__1 = (const lean_object*)&lp_JunkValues_JunkValues_instInhabitedStatus_default___closed__1_value;
LEAN_EXPORT const lean_object* lp_JunkValues_JunkValues_instInhabitedStatus_default = (const lean_object*)&lp_JunkValues_JunkValues_instInhabitedStatus_default___closed__1_value;
LEAN_EXPORT const lean_object* lp_JunkValues_JunkValues_instInhabitedStatus = (const lean_object*)&lp_JunkValues_JunkValues_instInhabitedStatus_default___closed__1_value;
LEAN_EXPORT uint8_t lp_JunkValues_JunkValues_instBEqStatus_beq(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instBEqStatus_beq___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_JunkValues_JunkValues_instBEqStatus___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_JunkValues_JunkValues_instBEqStatus_beq___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_JunkValues_JunkValues_instBEqStatus___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_instBEqStatus___closed__0_value;
LEAN_EXPORT const lean_object* lp_JunkValues_JunkValues_instBEqStatus = (const lean_object*)&lp_JunkValues_JunkValues_instBEqStatus___closed__0_value;
static const lean_string_object lp_JunkValues_JunkValues_instToJsonStatus_toJson___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "guarded"};
static const lean_object* lp_JunkValues_JunkValues_instToJsonStatus_toJson___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_instToJsonStatus_toJson___closed__0_value;
static const lean_string_object lp_JunkValues_JunkValues_instToJsonStatus_toJson___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "how"};
static const lean_object* lp_JunkValues_JunkValues_instToJsonStatus_toJson___closed__1 = (const lean_object*)&lp_JunkValues_JunkValues_instToJsonStatus_toJson___closed__1_value;
static const lean_string_object lp_JunkValues_JunkValues_instToJsonStatus_toJson___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 10, .m_capacity = 10, .m_length = 9, .m_data = "unguarded"};
static const lean_object* lp_JunkValues_JunkValues_instToJsonStatus_toJson___closed__2 = (const lean_object*)&lp_JunkValues_JunkValues_instToJsonStatus_toJson___closed__2_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instToJsonStatus_toJson___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_instToJsonStatus_toJson___closed__2_value)}};
static const lean_object* lp_JunkValues_JunkValues_instToJsonStatus_toJson___closed__3 = (const lean_object*)&lp_JunkValues_JunkValues_instToJsonStatus_toJson___closed__3_value;
static const lean_string_object lp_JunkValues_JunkValues_instToJsonStatus_toJson___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 10, .m_capacity = 10, .m_length = 9, .m_data = "triggered"};
static const lean_object* lp_JunkValues_JunkValues_instToJsonStatus_toJson___closed__4 = (const lean_object*)&lp_JunkValues_JunkValues_instToJsonStatus_toJson___closed__4_value;
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instToJsonStatus_toJson(lean_object*);
static const lean_closure_object lp_JunkValues_JunkValues_instToJsonStatus___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_JunkValues_JunkValues_instToJsonStatus_toJson, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_JunkValues_JunkValues_instToJsonStatus___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_instToJsonStatus___closed__0_value;
LEAN_EXPORT const lean_object* lp_JunkValues_JunkValues_instToJsonStatus = (const lean_object*)&lp_JunkValues_JunkValues_instToJsonStatus___closed__0_value;
static const lean_string_object lp_JunkValues_JunkValues_instFromJsonStatus_fromJson___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 23, .m_capacity = 23, .m_length = 22, .m_data = "no inductive tag found"};
static const lean_object* lp_JunkValues_JunkValues_instFromJsonStatus_fromJson___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_instFromJsonStatus_fromJson___closed__0_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instFromJsonStatus_fromJson___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 0}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_instFromJsonStatus_fromJson___closed__0_value)}};
static const lean_object* lp_JunkValues_JunkValues_instFromJsonStatus_fromJson___closed__1 = (const lean_object*)&lp_JunkValues_JunkValues_instFromJsonStatus_fromJson___closed__1_value;
static const lean_string_object lp_JunkValues_JunkValues_instFromJsonStatus_fromJson___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 33, .m_capacity = 33, .m_length = 32, .m_data = "no inductive constructor matched"};
static const lean_object* lp_JunkValues_JunkValues_instFromJsonStatus_fromJson___closed__2 = (const lean_object*)&lp_JunkValues_JunkValues_instFromJsonStatus_fromJson___closed__2_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instFromJsonStatus_fromJson___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 0}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_instFromJsonStatus_fromJson___closed__2_value)}};
static const lean_object* lp_JunkValues_JunkValues_instFromJsonStatus_fromJson___closed__3 = (const lean_object*)&lp_JunkValues_JunkValues_instFromJsonStatus_fromJson___closed__3_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instFromJsonStatus_fromJson___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_instToJsonStatus_toJson___closed__1_value),LEAN_SCALAR_PTR_LITERAL(73, 10, 198, 193, 24, 47, 9, 187)}};
static const lean_object* lp_JunkValues_JunkValues_instFromJsonStatus_fromJson___closed__4 = (const lean_object*)&lp_JunkValues_JunkValues_instFromJsonStatus_fromJson___closed__4_value;
static const lean_array_object lp_JunkValues_JunkValues_instFromJsonStatus_fromJson___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*1, .m_other = 0, .m_tag = 246}, .m_size = 1, .m_capacity = 1, .m_data = {((lean_object*)&lp_JunkValues_JunkValues_instFromJsonStatus_fromJson___closed__4_value)}};
static const lean_object* lp_JunkValues_JunkValues_instFromJsonStatus_fromJson___closed__5 = (const lean_object*)&lp_JunkValues_JunkValues_instFromJsonStatus_fromJson___closed__5_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instFromJsonStatus_fromJson___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_instFromJsonStatus_fromJson___closed__5_value)}};
static const lean_object* lp_JunkValues_JunkValues_instFromJsonStatus_fromJson___closed__6 = (const lean_object*)&lp_JunkValues_JunkValues_instFromJsonStatus_fromJson___closed__6_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instFromJsonStatus_fromJson___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(1) << 1) | 1))}};
static const lean_object* lp_JunkValues_JunkValues_instFromJsonStatus_fromJson___closed__7 = (const lean_object*)&lp_JunkValues_JunkValues_instFromJsonStatus_fromJson___closed__7_value;
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instFromJsonStatus_fromJson(lean_object*);
static const lean_closure_object lp_JunkValues_JunkValues_instFromJsonStatus___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_JunkValues_JunkValues_instFromJsonStatus_fromJson, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_JunkValues_JunkValues_instFromJsonStatus___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_instFromJsonStatus___closed__0_value;
LEAN_EXPORT const lean_object* lp_JunkValues_JunkValues_instFromJsonStatus = (const lean_object*)&lp_JunkValues_JunkValues_instFromJsonStatus___closed__0_value;
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Status_slug(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Status_slug___boxed(lean_object*);
LEAN_EXPORT uint8_t lp_JunkValues_JunkValues_Status_isFinding(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Status_isFinding___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Site_ctorIdx(uint8_t);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Site_ctorIdx___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Site_toCtorIdx(uint8_t);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Site_toCtorIdx___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Site_ctorElim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Site_ctorElim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Site_ctorElim(lean_object*, lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Site_ctorElim___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Site_statement_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Site_statement_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Site_statement_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Site_statement_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Site_body_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Site_body_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Site_body_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Site_body_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object lp_JunkValues_JunkValues_instReprSite_repr___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 26, .m_capacity = 26, .m_length = 25, .m_data = "JunkValues.Site.statement"};
static const lean_object* lp_JunkValues_JunkValues_instReprSite_repr___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_instReprSite_repr___closed__0_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instReprSite_repr___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_instReprSite_repr___closed__0_value)}};
static const lean_object* lp_JunkValues_JunkValues_instReprSite_repr___closed__1 = (const lean_object*)&lp_JunkValues_JunkValues_instReprSite_repr___closed__1_value;
static const lean_string_object lp_JunkValues_JunkValues_instReprSite_repr___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 21, .m_capacity = 21, .m_length = 20, .m_data = "JunkValues.Site.body"};
static const lean_object* lp_JunkValues_JunkValues_instReprSite_repr___closed__2 = (const lean_object*)&lp_JunkValues_JunkValues_instReprSite_repr___closed__2_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instReprSite_repr___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_instReprSite_repr___closed__2_value)}};
static const lean_object* lp_JunkValues_JunkValues_instReprSite_repr___closed__3 = (const lean_object*)&lp_JunkValues_JunkValues_instReprSite_repr___closed__3_value;
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instReprSite_repr(uint8_t, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instReprSite_repr___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_JunkValues_JunkValues_instReprSite___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_JunkValues_JunkValues_instReprSite_repr___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_JunkValues_JunkValues_instReprSite___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_instReprSite___closed__0_value;
LEAN_EXPORT const lean_object* lp_JunkValues_JunkValues_instReprSite = (const lean_object*)&lp_JunkValues_JunkValues_instReprSite___closed__0_value;
LEAN_EXPORT uint8_t lp_JunkValues_JunkValues_instInhabitedSite_default;
LEAN_EXPORT uint8_t lp_JunkValues_JunkValues_instInhabitedSite;
LEAN_EXPORT uint8_t lp_JunkValues_JunkValues_instBEqSite_beq(uint8_t, uint8_t);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instBEqSite_beq___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_JunkValues_JunkValues_instBEqSite___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_JunkValues_JunkValues_instBEqSite_beq___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_JunkValues_JunkValues_instBEqSite___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_instBEqSite___closed__0_value;
LEAN_EXPORT const lean_object* lp_JunkValues_JunkValues_instBEqSite = (const lean_object*)&lp_JunkValues_JunkValues_instBEqSite___closed__0_value;
LEAN_EXPORT uint8_t lp_JunkValues_JunkValues_Site_ofNat(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Site_ofNat___boxed(lean_object*);
LEAN_EXPORT uint8_t lp_JunkValues_JunkValues_instDecidableEqSite(uint8_t, uint8_t);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instDecidableEqSite___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint64_t lp_JunkValues_JunkValues_instHashableSite_hash(uint8_t);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instHashableSite_hash___boxed(lean_object*);
static const lean_closure_object lp_JunkValues_JunkValues_instHashableSite___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_JunkValues_JunkValues_instHashableSite_hash___boxed, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_JunkValues_JunkValues_instHashableSite___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_instHashableSite___closed__0_value;
LEAN_EXPORT const lean_object* lp_JunkValues_JunkValues_instHashableSite = (const lean_object*)&lp_JunkValues_JunkValues_instHashableSite___closed__0_value;
static const lean_string_object lp_JunkValues_JunkValues_instToJsonSite_toJson___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 10, .m_capacity = 10, .m_length = 9, .m_data = "statement"};
static const lean_object* lp_JunkValues_JunkValues_instToJsonSite_toJson___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_instToJsonSite_toJson___closed__0_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instToJsonSite_toJson___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_instToJsonSite_toJson___closed__0_value)}};
static const lean_object* lp_JunkValues_JunkValues_instToJsonSite_toJson___closed__1 = (const lean_object*)&lp_JunkValues_JunkValues_instToJsonSite_toJson___closed__1_value;
static const lean_string_object lp_JunkValues_JunkValues_instToJsonSite_toJson___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "body"};
static const lean_object* lp_JunkValues_JunkValues_instToJsonSite_toJson___closed__2 = (const lean_object*)&lp_JunkValues_JunkValues_instToJsonSite_toJson___closed__2_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instToJsonSite_toJson___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_instToJsonSite_toJson___closed__2_value)}};
static const lean_object* lp_JunkValues_JunkValues_instToJsonSite_toJson___closed__3 = (const lean_object*)&lp_JunkValues_JunkValues_instToJsonSite_toJson___closed__3_value;
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instToJsonSite_toJson(uint8_t);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instToJsonSite_toJson___boxed(lean_object*);
static const lean_closure_object lp_JunkValues_JunkValues_instToJsonSite___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_JunkValues_JunkValues_instToJsonSite_toJson___boxed, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_JunkValues_JunkValues_instToJsonSite___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_instToJsonSite___closed__0_value;
LEAN_EXPORT const lean_object* lp_JunkValues_JunkValues_instToJsonSite = (const lean_object*)&lp_JunkValues_JunkValues_instToJsonSite___closed__0_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instFromJsonSite_fromJson___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 0}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_instFromJsonStatus_fromJson___closed__0_value)}};
static const lean_object* lp_JunkValues_JunkValues_instFromJsonSite_fromJson___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_instFromJsonSite_fromJson___closed__0_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instFromJsonSite_fromJson___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 0}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_instFromJsonStatus_fromJson___closed__2_value)}};
static const lean_object* lp_JunkValues_JunkValues_instFromJsonSite_fromJson___closed__1 = (const lean_object*)&lp_JunkValues_JunkValues_instFromJsonSite_fromJson___closed__1_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instFromJsonSite_fromJson___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_JunkValues_JunkValues_instFromJsonSite_fromJson___closed__2 = (const lean_object*)&lp_JunkValues_JunkValues_instFromJsonSite_fromJson___closed__2_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instFromJsonSite_fromJson___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(1) << 1) | 1))}};
static const lean_object* lp_JunkValues_JunkValues_instFromJsonSite_fromJson___closed__3 = (const lean_object*)&lp_JunkValues_JunkValues_instFromJsonSite_fromJson___closed__3_value;
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instFromJsonSite_fromJson(lean_object*);
static const lean_closure_object lp_JunkValues_JunkValues_instFromJsonSite___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_JunkValues_JunkValues_instFromJsonSite_fromJson, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_JunkValues_JunkValues_instFromJsonSite___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_instFromJsonSite___closed__0_value;
LEAN_EXPORT const lean_object* lp_JunkValues_JunkValues_instFromJsonSite = (const lean_object*)&lp_JunkValues_JunkValues_instFromJsonSite___closed__0_value;
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Site_slug(uint8_t);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Site_slug___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Nat_cast___at___00JunkValues_instReprFinding_repr_spec__1(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_Format_joinSep___at___00Array_repr___at___00JunkValues_instReprFinding_repr_spec__0_spec__0___lam__0(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_List_foldl___at___00List_foldl___at___00Std_Format_joinSep___at___00Array_repr___at___00JunkValues_instReprFinding_repr_spec__0_spec__0_spec__2_spec__3(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_List_foldl___at___00Std_Format_joinSep___at___00Array_repr___at___00JunkValues_instReprFinding_repr_spec__0_spec__0_spec__2(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_Format_joinSep___at___00Array_repr___at___00JunkValues_instReprFinding_repr_spec__0_spec__0(lean_object*, lean_object*);
static const lean_string_object lp_JunkValues_Array_repr___at___00JunkValues_instReprFinding_repr_spec__0___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "#["};
static const lean_object* lp_JunkValues_Array_repr___at___00JunkValues_instReprFinding_repr_spec__0___closed__0 = (const lean_object*)&lp_JunkValues_Array_repr___at___00JunkValues_instReprFinding_repr_spec__0___closed__0_value;
static const lean_string_object lp_JunkValues_Array_repr___at___00JunkValues_instReprFinding_repr_spec__0___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 2, .m_capacity = 2, .m_length = 1, .m_data = ","};
static const lean_object* lp_JunkValues_Array_repr___at___00JunkValues_instReprFinding_repr_spec__0___closed__1 = (const lean_object*)&lp_JunkValues_Array_repr___at___00JunkValues_instReprFinding_repr_spec__0___closed__1_value;
static const lean_ctor_object lp_JunkValues_Array_repr___at___00JunkValues_instReprFinding_repr_spec__0___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_JunkValues_Array_repr___at___00JunkValues_instReprFinding_repr_spec__0___closed__1_value)}};
static const lean_object* lp_JunkValues_Array_repr___at___00JunkValues_instReprFinding_repr_spec__0___closed__2 = (const lean_object*)&lp_JunkValues_Array_repr___at___00JunkValues_instReprFinding_repr_spec__0___closed__2_value;
static const lean_ctor_object lp_JunkValues_Array_repr___at___00JunkValues_instReprFinding_repr_spec__0___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_JunkValues_Array_repr___at___00JunkValues_instReprFinding_repr_spec__0___closed__2_value),((lean_object*)(((size_t)(1) << 1) | 1))}};
static const lean_object* lp_JunkValues_Array_repr___at___00JunkValues_instReprFinding_repr_spec__0___closed__3 = (const lean_object*)&lp_JunkValues_Array_repr___at___00JunkValues_instReprFinding_repr_spec__0___closed__3_value;
static const lean_string_object lp_JunkValues_Array_repr___at___00JunkValues_instReprFinding_repr_spec__0___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 2, .m_capacity = 2, .m_length = 1, .m_data = "]"};
static const lean_object* lp_JunkValues_Array_repr___at___00JunkValues_instReprFinding_repr_spec__0___closed__4 = (const lean_object*)&lp_JunkValues_Array_repr___at___00JunkValues_instReprFinding_repr_spec__0___closed__4_value;
static lean_once_cell_t lp_JunkValues_Array_repr___at___00JunkValues_instReprFinding_repr_spec__0___closed__5_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_Array_repr___at___00JunkValues_instReprFinding_repr_spec__0___closed__5;
static lean_once_cell_t lp_JunkValues_Array_repr___at___00JunkValues_instReprFinding_repr_spec__0___closed__6_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_Array_repr___at___00JunkValues_instReprFinding_repr_spec__0___closed__6;
static const lean_ctor_object lp_JunkValues_Array_repr___at___00JunkValues_instReprFinding_repr_spec__0___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_JunkValues_Array_repr___at___00JunkValues_instReprFinding_repr_spec__0___closed__0_value)}};
static const lean_object* lp_JunkValues_Array_repr___at___00JunkValues_instReprFinding_repr_spec__0___closed__7 = (const lean_object*)&lp_JunkValues_Array_repr___at___00JunkValues_instReprFinding_repr_spec__0___closed__7_value;
static const lean_ctor_object lp_JunkValues_Array_repr___at___00JunkValues_instReprFinding_repr_spec__0___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_JunkValues_Array_repr___at___00JunkValues_instReprFinding_repr_spec__0___closed__4_value)}};
static const lean_object* lp_JunkValues_Array_repr___at___00JunkValues_instReprFinding_repr_spec__0___closed__8 = (const lean_object*)&lp_JunkValues_Array_repr___at___00JunkValues_instReprFinding_repr_spec__0___closed__8_value;
static const lean_string_object lp_JunkValues_Array_repr___at___00JunkValues_instReprFinding_repr_spec__0___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "#[]"};
static const lean_object* lp_JunkValues_Array_repr___at___00JunkValues_instReprFinding_repr_spec__0___closed__9 = (const lean_object*)&lp_JunkValues_Array_repr___at___00JunkValues_instReprFinding_repr_spec__0___closed__9_value;
static const lean_ctor_object lp_JunkValues_Array_repr___at___00JunkValues_instReprFinding_repr_spec__0___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_JunkValues_Array_repr___at___00JunkValues_instReprFinding_repr_spec__0___closed__9_value)}};
static const lean_object* lp_JunkValues_Array_repr___at___00JunkValues_instReprFinding_repr_spec__0___closed__10 = (const lean_object*)&lp_JunkValues_Array_repr___at___00JunkValues_instReprFinding_repr_spec__0___closed__10_value;
LEAN_EXPORT lean_object* lp_JunkValues_Array_repr___at___00JunkValues_instReprFinding_repr_spec__0(lean_object*);
static const lean_string_object lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "{ "};
static const lean_object* lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__0_value;
static const lean_string_object lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "decl"};
static const lean_object* lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__1 = (const lean_object*)&lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__1_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__1_value)}};
static const lean_object* lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__2 = (const lean_object*)&lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__2_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__2_value)}};
static const lean_object* lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__3 = (const lean_object*)&lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__3_value;
static const lean_string_object lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = " := "};
static const lean_object* lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__4 = (const lean_object*)&lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__4_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__4_value)}};
static const lean_object* lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__5 = (const lean_object*)&lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__5_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__3_value),((lean_object*)&lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__5_value)}};
static const lean_object* lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__6 = (const lean_object*)&lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__6_value;
static lean_once_cell_t lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__7_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__7;
static const lean_string_object lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "site"};
static const lean_object* lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__8 = (const lean_object*)&lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__8_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__8_value)}};
static const lean_object* lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__9 = (const lean_object*)&lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__9_value;
static const lean_string_object lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "rule"};
static const lean_object* lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__10 = (const lean_object*)&lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__10_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__10_value)}};
static const lean_object* lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__11 = (const lean_object*)&lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__11_value;
static const lean_string_object lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__12_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "head"};
static const lean_object* lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__12 = (const lean_object*)&lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__12_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__13_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__12_value)}};
static const lean_object* lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__13 = (const lean_object*)&lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__13_value;
static const lean_string_object lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__14_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "term"};
static const lean_object* lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__14 = (const lean_object*)&lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__14_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__15_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__14_value)}};
static const lean_object* lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__15 = (const lean_object*)&lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__15_value;
static const lean_string_object lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__16_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "guards"};
static const lean_object* lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__16 = (const lean_object*)&lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__16_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__17_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__16_value)}};
static const lean_object* lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__17 = (const lean_object*)&lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__17_value;
static lean_once_cell_t lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__18_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__18;
static const lean_string_object lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__19_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "value"};
static const lean_object* lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__19 = (const lean_object*)&lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__19_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__20_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__19_value)}};
static const lean_object* lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__20 = (const lean_object*)&lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__20_value;
static lean_once_cell_t lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__21_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__21;
static const lean_string_object lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__22_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "status"};
static const lean_object* lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__22 = (const lean_object*)&lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__22_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__23_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__22_value)}};
static const lean_object* lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__23 = (const lean_object*)&lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__23_value;
static const lean_string_object lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__24_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "note"};
static const lean_object* lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__24 = (const lean_object*)&lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__24_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__25_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__24_value)}};
static const lean_object* lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__25 = (const lean_object*)&lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__25_value;
static const lean_string_object lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__26_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = " }"};
static const lean_object* lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__26 = (const lean_object*)&lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__26_value;
static lean_once_cell_t lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__27_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__27;
static lean_once_cell_t lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__28_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__28;
static const lean_ctor_object lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__29_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__0_value)}};
static const lean_object* lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__29 = (const lean_object*)&lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__29_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__30_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__26_value)}};
static const lean_object* lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__30 = (const lean_object*)&lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__30_value;
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instReprFinding_repr___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instReprFinding_repr(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instReprFinding_repr___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_JunkValues_JunkValues_instReprFinding___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_JunkValues_JunkValues_instReprFinding_repr___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_JunkValues_JunkValues_instReprFinding___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_instReprFinding___closed__0_value;
LEAN_EXPORT const lean_object* lp_JunkValues_JunkValues_instReprFinding = (const lean_object*)&lp_JunkValues_JunkValues_instReprFinding___closed__0_value;
static const lean_array_object lp_JunkValues_JunkValues_instInhabitedFinding_default___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* lp_JunkValues_JunkValues_instInhabitedFinding_default___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_instInhabitedFinding_default___closed__0_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instInhabitedFinding_default___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*8 + 8, .m_other = 8, .m_tag = 0}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_instInhabitedStatus_default___closed__0_value),((lean_object*)&lp_JunkValues_JunkValues_instInhabitedFinding_default___closed__0_value),((lean_object*)&lp_JunkValues_JunkValues_instInhabitedStatus_default___closed__0_value),((lean_object*)&lp_JunkValues_JunkValues_instInhabitedStatus_default___closed__1_value),((lean_object*)&lp_JunkValues_JunkValues_instInhabitedStatus_default___closed__0_value),LEAN_SCALAR_PTR_LITERAL(0, 0, 0, 0, 0, 0, 0, 0)}};
static const lean_object* lp_JunkValues_JunkValues_instInhabitedFinding_default___closed__1 = (const lean_object*)&lp_JunkValues_JunkValues_instInhabitedFinding_default___closed__1_value;
LEAN_EXPORT const lean_object* lp_JunkValues_JunkValues_instInhabitedFinding_default = (const lean_object*)&lp_JunkValues_JunkValues_instInhabitedFinding_default___closed__1_value;
LEAN_EXPORT const lean_object* lp_JunkValues_JunkValues_instInhabitedFinding = (const lean_object*)&lp_JunkValues_JunkValues_instInhabitedFinding_default___closed__1_value;
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00JunkValues_instToJsonFinding_toJson_spec__1(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00JunkValues_instToJsonFinding_toJson_spec__0_spec__0(size_t, size_t, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00JunkValues_instToJsonFinding_toJson_spec__0_spec__0___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Array_toJson___at___00JunkValues_instToJsonFinding_toJson_spec__0(lean_object*);
static const lean_array_object lp_JunkValues_JunkValues_instToJsonFinding_toJson___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* lp_JunkValues_JunkValues_instToJsonFinding_toJson___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_instToJsonFinding_toJson___closed__0_value;
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instToJsonFinding_toJson(lean_object*);
static const lean_closure_object lp_JunkValues_JunkValues_instToJsonFinding___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_JunkValues_JunkValues_instToJsonFinding_toJson, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_JunkValues_JunkValues_instToJsonFinding___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_instToJsonFinding___closed__0_value;
LEAN_EXPORT const lean_object* lp_JunkValues_JunkValues_instToJsonFinding = (const lean_object*)&lp_JunkValues_JunkValues_instToJsonFinding___closed__0_value;
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Json_getObjValAs_x3f___at___00JunkValues_instFromJsonFinding_fromJson_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Json_getObjValAs_x3f___at___00JunkValues_instFromJsonFinding_fromJson_spec__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Json_getObjValAs_x3f___at___00JunkValues_instFromJsonFinding_fromJson_spec__1(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Json_getObjValAs_x3f___at___00JunkValues_instFromJsonFinding_fromJson_spec__1___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Json_getObjValAs_x3f___at___00JunkValues_instFromJsonFinding_fromJson_spec__2(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Json_getObjValAs_x3f___at___00JunkValues_instFromJsonFinding_fromJson_spec__2___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Json_getObjValAs_x3f___at___00JunkValues_instFromJsonFinding_fromJson_spec__4(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Json_getObjValAs_x3f___at___00JunkValues_instFromJsonFinding_fromJson_spec__4___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00JunkValues_instFromJsonFinding_fromJson_spec__3_spec__3_spec__5(size_t, size_t, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00JunkValues_instFromJsonFinding_fromJson_spec__3_spec__3_spec__5___boxed(lean_object*, lean_object*, lean_object*);
static const lean_string_object lp_JunkValues_Lean_Array_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00JunkValues_instFromJsonFinding_fromJson_spec__3_spec__3___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 27, .m_capacity = 27, .m_length = 26, .m_data = "expected JSON array, got '"};
static const lean_object* lp_JunkValues_Lean_Array_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00JunkValues_instFromJsonFinding_fromJson_spec__3_spec__3___closed__0 = (const lean_object*)&lp_JunkValues_Lean_Array_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00JunkValues_instFromJsonFinding_fromJson_spec__3_spec__3___closed__0_value;
static const lean_string_object lp_JunkValues_Lean_Array_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00JunkValues_instFromJsonFinding_fromJson_spec__3_spec__3___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 2, .m_capacity = 2, .m_length = 1, .m_data = "'"};
static const lean_object* lp_JunkValues_Lean_Array_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00JunkValues_instFromJsonFinding_fromJson_spec__3_spec__3___closed__1 = (const lean_object*)&lp_JunkValues_Lean_Array_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00JunkValues_instFromJsonFinding_fromJson_spec__3_spec__3___closed__1_value;
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Array_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00JunkValues_instFromJsonFinding_fromJson_spec__3_spec__3(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Json_getObjValAs_x3f___at___00JunkValues_instFromJsonFinding_fromJson_spec__3(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Json_getObjValAs_x3f___at___00JunkValues_instFromJsonFinding_fromJson_spec__3___boxed(lean_object*, lean_object*);
static const lean_string_object lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "JunkValues"};
static const lean_object* lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__0_value;
static const lean_string_object lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "Finding"};
static const lean_object* lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__1 = (const lean_object*)&lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__1_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__2_value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__0_value),LEAN_SCALAR_PTR_LITERAL(102, 249, 254, 203, 87, 211, 22, 147)}};
static const lean_ctor_object lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__2_value_aux_0),((lean_object*)&lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__1_value),LEAN_SCALAR_PTR_LITERAL(105, 92, 71, 15, 53, 56, 16, 53)}};
static const lean_object* lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__2 = (const lean_object*)&lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__2_value;
static lean_once_cell_t lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__3;
static const lean_string_object lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 2, .m_capacity = 2, .m_length = 1, .m_data = "."};
static const lean_object* lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__4 = (const lean_object*)&lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__4_value;
static lean_once_cell_t lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__5_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__5;
static const lean_ctor_object lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__1_value),LEAN_SCALAR_PTR_LITERAL(122, 197, 108, 116, 168, 105, 88, 191)}};
static const lean_object* lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__6 = (const lean_object*)&lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__6_value;
static lean_once_cell_t lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__7_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__7;
static lean_once_cell_t lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__8_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__8;
static const lean_string_object lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = ": "};
static const lean_object* lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__9 = (const lean_object*)&lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__9_value;
static lean_once_cell_t lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__10_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__10;
static const lean_ctor_object lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__8_value),LEAN_SCALAR_PTR_LITERAL(200, 59, 132, 184, 204, 79, 115, 34)}};
static const lean_object* lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__11 = (const lean_object*)&lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__11_value;
static lean_once_cell_t lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__12_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__12;
static lean_once_cell_t lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__13_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__13;
static lean_once_cell_t lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__14_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__14;
static const lean_ctor_object lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__15_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__10_value),LEAN_SCALAR_PTR_LITERAL(246, 189, 94, 172, 79, 179, 189, 8)}};
static const lean_object* lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__15 = (const lean_object*)&lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__15_value;
static lean_once_cell_t lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__16_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__16;
static lean_once_cell_t lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__17_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__17;
static lean_once_cell_t lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__18_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__18;
static const lean_ctor_object lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__19_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__12_value),LEAN_SCALAR_PTR_LITERAL(39, 250, 236, 204, 75, 142, 161, 219)}};
static const lean_object* lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__19 = (const lean_object*)&lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__19_value;
static lean_once_cell_t lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__20_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__20;
static lean_once_cell_t lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__21_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__21;
static lean_once_cell_t lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__22_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__22;
static const lean_ctor_object lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__23_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__14_value),LEAN_SCALAR_PTR_LITERAL(187, 230, 181, 162, 253, 146, 122, 119)}};
static const lean_object* lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__23 = (const lean_object*)&lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__23_value;
static lean_once_cell_t lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__24_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__24;
static lean_once_cell_t lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__25_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__25;
static lean_once_cell_t lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__26_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__26;
static const lean_ctor_object lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__27_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__16_value),LEAN_SCALAR_PTR_LITERAL(191, 112, 53, 158, 74, 95, 172, 68)}};
static const lean_object* lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__27 = (const lean_object*)&lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__27_value;
static lean_once_cell_t lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__28_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__28;
static lean_once_cell_t lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__29_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__29;
static lean_once_cell_t lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__30_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__30;
static const lean_ctor_object lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__31_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__19_value),LEAN_SCALAR_PTR_LITERAL(197, 65, 47, 208, 134, 160, 30, 25)}};
static const lean_object* lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__31 = (const lean_object*)&lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__31_value;
static lean_once_cell_t lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__32_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__32;
static lean_once_cell_t lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__33_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__33;
static lean_once_cell_t lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__34_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__34;
static const lean_ctor_object lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__35_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__22_value),LEAN_SCALAR_PTR_LITERAL(125, 93, 200, 160, 206, 0, 199, 210)}};
static const lean_object* lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__35 = (const lean_object*)&lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__35_value;
static lean_once_cell_t lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__36_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__36;
static lean_once_cell_t lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__37_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__37;
static lean_once_cell_t lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__38_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__38;
static const lean_ctor_object lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__39_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__24_value),LEAN_SCALAR_PTR_LITERAL(176, 240, 101, 116, 247, 36, 147, 220)}};
static const lean_object* lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__39 = (const lean_object*)&lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__39_value;
static lean_once_cell_t lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__40_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__40;
static lean_once_cell_t lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__41_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__41;
static lean_once_cell_t lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__42_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__42;
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instFromJsonFinding_fromJson(lean_object*);
static const lean_closure_object lp_JunkValues_JunkValues_instFromJsonFinding___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_JunkValues_JunkValues_instFromJsonFinding_fromJson, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_JunkValues_JunkValues_instFromJsonFinding___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_instFromJsonFinding___closed__0_value;
LEAN_EXPORT const lean_object* lp_JunkValues_JunkValues_instFromJsonFinding = (const lean_object*)&lp_JunkValues_JunkValues_instFromJsonFinding___closed__0_value;
static const lean_string_object lp_JunkValues_JunkValues_Finding_message___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = " and "};
static const lean_object* lp_JunkValues_JunkValues_Finding_message___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_Finding_message___closed__0_value;
static const lean_string_object lp_JunkValues_JunkValues_Finding_message___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "if "};
static const lean_object* lp_JunkValues_JunkValues_Finding_message___closed__1 = (const lean_object*)&lp_JunkValues_JunkValues_Finding_message___closed__1_value;
static const lean_string_object lp_JunkValues_JunkValues_Finding_message___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = " then "};
static const lean_object* lp_JunkValues_JunkValues_Finding_message___closed__2 = (const lean_object*)&lp_JunkValues_JunkValues_Finding_message___closed__2_value;
static const lean_string_object lp_JunkValues_JunkValues_Finding_message___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = " = "};
static const lean_object* lp_JunkValues_JunkValues_Finding_message___closed__3 = (const lean_object*)&lp_JunkValues_JunkValues_Finding_message___closed__3_value;
static const lean_string_object lp_JunkValues_JunkValues_Finding_message___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = " (by "};
static const lean_object* lp_JunkValues_JunkValues_Finding_message___closed__4 = (const lean_object*)&lp_JunkValues_JunkValues_Finding_message___closed__4_value;
static const lean_string_object lp_JunkValues_JunkValues_Finding_message___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 2, .m_capacity = 2, .m_length = 1, .m_data = ")"};
static const lean_object* lp_JunkValues_JunkValues_Finding_message___closed__5 = (const lean_object*)&lp_JunkValues_JunkValues_Finding_message___closed__5_value;
static const lean_string_object lp_JunkValues_JunkValues_Finding_message___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 14, .m_capacity = 14, .m_length = 13, .m_data = "not at risk ("};
static const lean_object* lp_JunkValues_JunkValues_Finding_message___closed__6 = (const lean_object*)&lp_JunkValues_JunkValues_Finding_message___closed__6_value;
static const lean_string_object lp_JunkValues_JunkValues_Finding_message___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "): "};
static const lean_object* lp_JunkValues_JunkValues_Finding_message___closed__7 = (const lean_object*)&lp_JunkValues_JunkValues_Finding_message___closed__7_value;
static const lean_string_object lp_JunkValues_JunkValues_Finding_message___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 24, .m_capacity = 24, .m_length = 23, .m_data = ": the condition holds ("};
static const lean_object* lp_JunkValues_JunkValues_Finding_message___closed__8 = (const lean_object*)&lp_JunkValues_JunkValues_Finding_message___closed__8_value;
static const lean_string_object lp_JunkValues_JunkValues_Finding_message___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 3, .m_data = " — "};
static const lean_object* lp_JunkValues_JunkValues_Finding_message___closed__9 = (const lean_object*)&lp_JunkValues_JunkValues_Finding_message___closed__9_value;
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Finding_message(lean_object*);
LEAN_EXPORT uint8_t lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_inheritRisk_spec__0_spec__0___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_inheritRisk_spec__0_spec__0___redArg___boxed(lean_object*, lean_object*);
static lean_once_cell_t lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_inheritRisk_spec__0___redArg___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static uint64_t lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_inheritRisk_spec__0___redArg___closed__0;
LEAN_EXPORT uint8_t lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_inheritRisk_spec__0___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_inheritRisk_spec__0___redArg___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00JunkValues_inheritRisk_spec__2(lean_object*, lean_object*, size_t, size_t, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00JunkValues_inheritRisk_spec__2___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_getD___at___00Std_DHashMap_Internal_Raw_u2080_Const_getD___at___00JunkValues_inheritRisk_spec__1_spec__2___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_getD___at___00Std_DHashMap_Internal_Raw_u2080_Const_getD___at___00JunkValues_inheritRisk_spec__1_spec__2___redArg___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_Const_getD___at___00JunkValues_inheritRisk_spec__1___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_Const_getD___at___00JunkValues_inheritRisk_spec__1___redArg___boxed(lean_object*, lean_object*, lean_object*);
static const lean_array_object lp_JunkValues_JunkValues_inheritRisk___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* lp_JunkValues_JunkValues_inheritRisk___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_inheritRisk___closed__0_value;
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_inheritRisk(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_inheritRisk___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_inheritRisk_spec__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_inheritRisk_spec__0___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_Const_getD___at___00JunkValues_inheritRisk_spec__1(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_Const_getD___at___00JunkValues_inheritRisk_spec__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_inheritRisk_spec__0_spec__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_inheritRisk_spec__0_spec__0___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_getD___at___00Std_DHashMap_Internal_Raw_u2080_Const_getD___at___00JunkValues_inheritRisk_spec__1_spec__2(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_getD___at___00Std_DHashMap_Internal_Raw_u2080_Const_getD___at___00JunkValues_inheritRisk_spec__1_spec__2___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00__private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_riskySet_spec__0_spec__0_spec__1_spec__3___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_riskySet_spec__0_spec__0_spec__1___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_riskySet_spec__0_spec__0___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_riskySet_spec__0___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00JunkValues_riskySet_spec__1(lean_object*, size_t, size_t, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00JunkValues_riskySet_spec__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
static lean_once_cell_t lp_JunkValues_JunkValues_riskySet___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_riskySet___closed__0;
static lean_once_cell_t lp_JunkValues_JunkValues_riskySet___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_riskySet___closed__1;
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_riskySet(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_riskySet___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_riskySet_spec__0(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_riskySet_spec__0_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_riskySet_spec__0_spec__0_spec__1(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00__private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_riskySet_spec__0_spec__0_spec__1_spec__3(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Status_ctorIdx(lean_object* v_x_1_){
_start:
{
switch(lean_obj_tag(v_x_1_))
{
case 0:
{
lean_object* v___x_2_; 
v___x_2_ = lean_unsigned_to_nat(0u);
return v___x_2_;
}
case 1:
{
lean_object* v___x_3_; 
v___x_3_ = lean_unsigned_to_nat(1u);
return v___x_3_;
}
default: 
{
lean_object* v___x_4_; 
v___x_4_ = lean_unsigned_to_nat(2u);
return v___x_4_;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Status_ctorIdx___boxed(lean_object* v_x_5_){
_start:
{
lean_object* v_res_6_; 
v_res_6_ = lp_JunkValues_JunkValues_Status_ctorIdx(v_x_5_);
lean_dec(v_x_5_);
return v_res_6_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Status_ctorElim___redArg(lean_object* v_t_7_, lean_object* v_k_8_){
_start:
{
if (lean_obj_tag(v_t_7_) == 1)
{
return v_k_8_;
}
else
{
lean_object* v_how_9_; lean_object* v___x_10_; 
v_how_9_ = lean_ctor_get(v_t_7_, 0);
lean_inc_ref(v_how_9_);
lean_dec(v_t_7_);
v___x_10_ = lean_apply_1(v_k_8_, v_how_9_);
return v___x_10_;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Status_ctorElim(lean_object* v_motive_11_, lean_object* v_ctorIdx_12_, lean_object* v_t_13_, lean_object* v_h_14_, lean_object* v_k_15_){
_start:
{
lean_object* v___x_16_; 
v___x_16_ = lp_JunkValues_JunkValues_Status_ctorElim___redArg(v_t_13_, v_k_15_);
return v___x_16_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Status_ctorElim___boxed(lean_object* v_motive_17_, lean_object* v_ctorIdx_18_, lean_object* v_t_19_, lean_object* v_h_20_, lean_object* v_k_21_){
_start:
{
lean_object* v_res_22_; 
v_res_22_ = lp_JunkValues_JunkValues_Status_ctorElim(v_motive_17_, v_ctorIdx_18_, v_t_19_, v_h_20_, v_k_21_);
lean_dec(v_ctorIdx_18_);
return v_res_22_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Status_guarded_elim___redArg(lean_object* v_t_23_, lean_object* v_guarded_24_){
_start:
{
lean_object* v___x_25_; 
v___x_25_ = lp_JunkValues_JunkValues_Status_ctorElim___redArg(v_t_23_, v_guarded_24_);
return v___x_25_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Status_guarded_elim(lean_object* v_motive_26_, lean_object* v_t_27_, lean_object* v_h_28_, lean_object* v_guarded_29_){
_start:
{
lean_object* v___x_30_; 
v___x_30_ = lp_JunkValues_JunkValues_Status_ctorElim___redArg(v_t_27_, v_guarded_29_);
return v___x_30_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Status_unguarded_elim___redArg(lean_object* v_t_31_, lean_object* v_unguarded_32_){
_start:
{
lean_object* v___x_33_; 
v___x_33_ = lp_JunkValues_JunkValues_Status_ctorElim___redArg(v_t_31_, v_unguarded_32_);
return v___x_33_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Status_unguarded_elim(lean_object* v_motive_34_, lean_object* v_t_35_, lean_object* v_h_36_, lean_object* v_unguarded_37_){
_start:
{
lean_object* v___x_38_; 
v___x_38_ = lp_JunkValues_JunkValues_Status_ctorElim___redArg(v_t_35_, v_unguarded_37_);
return v___x_38_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Status_triggered_elim___redArg(lean_object* v_t_39_, lean_object* v_triggered_40_){
_start:
{
lean_object* v___x_41_; 
v___x_41_ = lp_JunkValues_JunkValues_Status_ctorElim___redArg(v_t_39_, v_triggered_40_);
return v___x_41_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Status_triggered_elim(lean_object* v_motive_42_, lean_object* v_t_43_, lean_object* v_h_44_, lean_object* v_triggered_45_){
_start:
{
lean_object* v___x_46_; 
v___x_46_ = lp_JunkValues_JunkValues_Status_ctorElim___redArg(v_t_43_, v_triggered_45_);
return v___x_46_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instReprStatus_repr___closed__5(void){
_start:
{
lean_object* v___x_56_; lean_object* v___x_57_; 
v___x_56_ = lean_unsigned_to_nat(2u);
v___x_57_ = lean_nat_to_int(v___x_56_);
return v___x_57_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instReprStatus_repr___closed__6(void){
_start:
{
lean_object* v___x_58_; lean_object* v___x_59_; 
v___x_58_ = lean_unsigned_to_nat(1u);
v___x_59_ = lean_nat_to_int(v___x_58_);
return v___x_59_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instReprStatus_repr(lean_object* v_x_66_, lean_object* v_prec_67_){
_start:
{
lean_object* v___y_69_; 
switch(lean_obj_tag(v_x_66_))
{
case 0:
{
lean_object* v_how_75_; lean_object* v___x_77_; uint8_t v_isShared_78_; uint8_t v_isSharedCheck_95_; 
v_how_75_ = lean_ctor_get(v_x_66_, 0);
v_isSharedCheck_95_ = !lean_is_exclusive(v_x_66_);
if (v_isSharedCheck_95_ == 0)
{
v___x_77_ = v_x_66_;
v_isShared_78_ = v_isSharedCheck_95_;
goto v_resetjp_76_;
}
else
{
lean_inc(v_how_75_);
lean_dec(v_x_66_);
v___x_77_ = lean_box(0);
v_isShared_78_ = v_isSharedCheck_95_;
goto v_resetjp_76_;
}
v_resetjp_76_:
{
lean_object* v___y_80_; lean_object* v___x_91_; uint8_t v___x_92_; 
v___x_91_ = lean_unsigned_to_nat(1024u);
v___x_92_ = lean_nat_dec_le(v___x_91_, v_prec_67_);
if (v___x_92_ == 0)
{
lean_object* v___x_93_; 
v___x_93_ = lean_obj_once(&lp_JunkValues_JunkValues_instReprStatus_repr___closed__5, &lp_JunkValues_JunkValues_instReprStatus_repr___closed__5_once, _init_lp_JunkValues_JunkValues_instReprStatus_repr___closed__5);
v___y_80_ = v___x_93_;
goto v___jp_79_;
}
else
{
lean_object* v___x_94_; 
v___x_94_ = lean_obj_once(&lp_JunkValues_JunkValues_instReprStatus_repr___closed__6, &lp_JunkValues_JunkValues_instReprStatus_repr___closed__6_once, _init_lp_JunkValues_JunkValues_instReprStatus_repr___closed__6);
v___y_80_ = v___x_94_;
goto v___jp_79_;
}
v___jp_79_:
{
lean_object* v___x_81_; lean_object* v___x_82_; lean_object* v___x_84_; 
v___x_81_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprStatus_repr___closed__4));
v___x_82_ = l_String_quote(v_how_75_);
if (v_isShared_78_ == 0)
{
lean_ctor_set_tag(v___x_77_, 3);
lean_ctor_set(v___x_77_, 0, v___x_82_);
v___x_84_ = v___x_77_;
goto v_reusejp_83_;
}
else
{
lean_object* v_reuseFailAlloc_90_; 
v_reuseFailAlloc_90_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v_reuseFailAlloc_90_, 0, v___x_82_);
v___x_84_ = v_reuseFailAlloc_90_;
goto v_reusejp_83_;
}
v_reusejp_83_:
{
lean_object* v___x_85_; lean_object* v___x_86_; uint8_t v___x_87_; lean_object* v___x_88_; lean_object* v___x_89_; 
v___x_85_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_85_, 0, v___x_81_);
lean_ctor_set(v___x_85_, 1, v___x_84_);
lean_inc(v___y_80_);
v___x_86_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_86_, 0, v___y_80_);
lean_ctor_set(v___x_86_, 1, v___x_85_);
v___x_87_ = 0;
v___x_88_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_88_, 0, v___x_86_);
lean_ctor_set_uint8(v___x_88_, sizeof(void*)*1, v___x_87_);
v___x_89_ = l_Repr_addAppParen(v___x_88_, v_prec_67_);
return v___x_89_;
}
}
}
}
case 1:
{
lean_object* v___x_96_; uint8_t v___x_97_; 
v___x_96_ = lean_unsigned_to_nat(1024u);
v___x_97_ = lean_nat_dec_le(v___x_96_, v_prec_67_);
if (v___x_97_ == 0)
{
lean_object* v___x_98_; 
v___x_98_ = lean_obj_once(&lp_JunkValues_JunkValues_instReprStatus_repr___closed__5, &lp_JunkValues_JunkValues_instReprStatus_repr___closed__5_once, _init_lp_JunkValues_JunkValues_instReprStatus_repr___closed__5);
v___y_69_ = v___x_98_;
goto v___jp_68_;
}
else
{
lean_object* v___x_99_; 
v___x_99_ = lean_obj_once(&lp_JunkValues_JunkValues_instReprStatus_repr___closed__6, &lp_JunkValues_JunkValues_instReprStatus_repr___closed__6_once, _init_lp_JunkValues_JunkValues_instReprStatus_repr___closed__6);
v___y_69_ = v___x_99_;
goto v___jp_68_;
}
}
default: 
{
lean_object* v_how_100_; lean_object* v___x_102_; uint8_t v_isShared_103_; uint8_t v_isSharedCheck_120_; 
v_how_100_ = lean_ctor_get(v_x_66_, 0);
v_isSharedCheck_120_ = !lean_is_exclusive(v_x_66_);
if (v_isSharedCheck_120_ == 0)
{
v___x_102_ = v_x_66_;
v_isShared_103_ = v_isSharedCheck_120_;
goto v_resetjp_101_;
}
else
{
lean_inc(v_how_100_);
lean_dec(v_x_66_);
v___x_102_ = lean_box(0);
v_isShared_103_ = v_isSharedCheck_120_;
goto v_resetjp_101_;
}
v_resetjp_101_:
{
lean_object* v___y_105_; lean_object* v___x_116_; uint8_t v___x_117_; 
v___x_116_ = lean_unsigned_to_nat(1024u);
v___x_117_ = lean_nat_dec_le(v___x_116_, v_prec_67_);
if (v___x_117_ == 0)
{
lean_object* v___x_118_; 
v___x_118_ = lean_obj_once(&lp_JunkValues_JunkValues_instReprStatus_repr___closed__5, &lp_JunkValues_JunkValues_instReprStatus_repr___closed__5_once, _init_lp_JunkValues_JunkValues_instReprStatus_repr___closed__5);
v___y_105_ = v___x_118_;
goto v___jp_104_;
}
else
{
lean_object* v___x_119_; 
v___x_119_ = lean_obj_once(&lp_JunkValues_JunkValues_instReprStatus_repr___closed__6, &lp_JunkValues_JunkValues_instReprStatus_repr___closed__6_once, _init_lp_JunkValues_JunkValues_instReprStatus_repr___closed__6);
v___y_105_ = v___x_119_;
goto v___jp_104_;
}
v___jp_104_:
{
lean_object* v___x_106_; lean_object* v___x_107_; lean_object* v___x_109_; 
v___x_106_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprStatus_repr___closed__9));
v___x_107_ = l_String_quote(v_how_100_);
if (v_isShared_103_ == 0)
{
lean_ctor_set_tag(v___x_102_, 3);
lean_ctor_set(v___x_102_, 0, v___x_107_);
v___x_109_ = v___x_102_;
goto v_reusejp_108_;
}
else
{
lean_object* v_reuseFailAlloc_115_; 
v_reuseFailAlloc_115_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v_reuseFailAlloc_115_, 0, v___x_107_);
v___x_109_ = v_reuseFailAlloc_115_;
goto v_reusejp_108_;
}
v_reusejp_108_:
{
lean_object* v___x_110_; lean_object* v___x_111_; uint8_t v___x_112_; lean_object* v___x_113_; lean_object* v___x_114_; 
v___x_110_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_110_, 0, v___x_106_);
lean_ctor_set(v___x_110_, 1, v___x_109_);
lean_inc(v___y_105_);
v___x_111_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_111_, 0, v___y_105_);
lean_ctor_set(v___x_111_, 1, v___x_110_);
v___x_112_ = 0;
v___x_113_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_113_, 0, v___x_111_);
lean_ctor_set_uint8(v___x_113_, sizeof(void*)*1, v___x_112_);
v___x_114_ = l_Repr_addAppParen(v___x_113_, v_prec_67_);
return v___x_114_;
}
}
}
}
}
v___jp_68_:
{
lean_object* v___x_70_; lean_object* v___x_71_; uint8_t v___x_72_; lean_object* v___x_73_; lean_object* v___x_74_; 
v___x_70_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprStatus_repr___closed__1));
lean_inc(v___y_69_);
v___x_71_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_71_, 0, v___y_69_);
lean_ctor_set(v___x_71_, 1, v___x_70_);
v___x_72_ = 0;
v___x_73_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_73_, 0, v___x_71_);
lean_ctor_set_uint8(v___x_73_, sizeof(void*)*1, v___x_72_);
v___x_74_ = l_Repr_addAppParen(v___x_73_, v_prec_67_);
return v___x_74_;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instReprStatus_repr___boxed(lean_object* v_x_121_, lean_object* v_prec_122_){
_start:
{
lean_object* v_res_123_; 
v_res_123_ = lp_JunkValues_JunkValues_instReprStatus_repr(v_x_121_, v_prec_122_);
lean_dec(v_prec_122_);
return v_res_123_;
}
}
LEAN_EXPORT uint8_t lp_JunkValues_JunkValues_instBEqStatus_beq(lean_object* v_x_131_, lean_object* v_x_132_){
_start:
{
switch(lean_obj_tag(v_x_131_))
{
case 0:
{
if (lean_obj_tag(v_x_132_) == 0)
{
lean_object* v_how_133_; lean_object* v_how_134_; uint8_t v___x_135_; 
v_how_133_ = lean_ctor_get(v_x_131_, 0);
v_how_134_ = lean_ctor_get(v_x_132_, 0);
v___x_135_ = lean_string_dec_eq(v_how_133_, v_how_134_);
return v___x_135_;
}
else
{
uint8_t v___x_136_; 
v___x_136_ = 0;
return v___x_136_;
}
}
case 1:
{
if (lean_obj_tag(v_x_132_) == 1)
{
uint8_t v___x_137_; 
v___x_137_ = 1;
return v___x_137_;
}
else
{
uint8_t v___x_138_; 
v___x_138_ = 0;
return v___x_138_;
}
}
default: 
{
if (lean_obj_tag(v_x_132_) == 2)
{
lean_object* v_how_139_; lean_object* v_how_140_; uint8_t v___x_141_; 
v_how_139_ = lean_ctor_get(v_x_131_, 0);
v_how_140_ = lean_ctor_get(v_x_132_, 0);
v___x_141_ = lean_string_dec_eq(v_how_139_, v_how_140_);
return v___x_141_;
}
else
{
uint8_t v___x_142_; 
v___x_142_ = 0;
return v___x_142_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instBEqStatus_beq___boxed(lean_object* v_x_143_, lean_object* v_x_144_){
_start:
{
uint8_t v_res_145_; lean_object* v_r_146_; 
v_res_145_ = lp_JunkValues_JunkValues_instBEqStatus_beq(v_x_143_, v_x_144_);
lean_dec(v_x_144_);
lean_dec(v_x_143_);
v_r_146_ = lean_box(v_res_145_);
return v_r_146_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instToJsonStatus_toJson(lean_object* v_x_155_){
_start:
{
switch(lean_obj_tag(v_x_155_))
{
case 0:
{
lean_object* v_how_156_; lean_object* v___x_158_; uint8_t v_isShared_159_; uint8_t v_isSharedCheck_172_; 
v_how_156_ = lean_ctor_get(v_x_155_, 0);
v_isSharedCheck_172_ = !lean_is_exclusive(v_x_155_);
if (v_isSharedCheck_172_ == 0)
{
v___x_158_ = v_x_155_;
v_isShared_159_ = v_isSharedCheck_172_;
goto v_resetjp_157_;
}
else
{
lean_inc(v_how_156_);
lean_dec(v_x_155_);
v___x_158_ = lean_box(0);
v_isShared_159_ = v_isSharedCheck_172_;
goto v_resetjp_157_;
}
v_resetjp_157_:
{
lean_object* v___x_160_; lean_object* v___x_161_; lean_object* v___x_163_; 
v___x_160_ = ((lean_object*)(lp_JunkValues_JunkValues_instToJsonStatus_toJson___closed__0));
v___x_161_ = ((lean_object*)(lp_JunkValues_JunkValues_instToJsonStatus_toJson___closed__1));
if (v_isShared_159_ == 0)
{
lean_ctor_set_tag(v___x_158_, 3);
v___x_163_ = v___x_158_;
goto v_reusejp_162_;
}
else
{
lean_object* v_reuseFailAlloc_171_; 
v_reuseFailAlloc_171_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v_reuseFailAlloc_171_, 0, v_how_156_);
v___x_163_ = v_reuseFailAlloc_171_;
goto v_reusejp_162_;
}
v_reusejp_162_:
{
lean_object* v___x_164_; lean_object* v___x_165_; lean_object* v___x_166_; lean_object* v___x_167_; lean_object* v___x_168_; lean_object* v___x_169_; lean_object* v___x_170_; 
v___x_164_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_164_, 0, v___x_161_);
lean_ctor_set(v___x_164_, 1, v___x_163_);
v___x_165_ = lean_box(0);
v___x_166_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_166_, 0, v___x_164_);
lean_ctor_set(v___x_166_, 1, v___x_165_);
v___x_167_ = l_Lean_Json_mkObj(v___x_166_);
lean_dec_ref_known(v___x_166_, 2);
v___x_168_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_168_, 0, v___x_160_);
lean_ctor_set(v___x_168_, 1, v___x_167_);
v___x_169_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_169_, 0, v___x_168_);
lean_ctor_set(v___x_169_, 1, v___x_165_);
v___x_170_ = l_Lean_Json_mkObj(v___x_169_);
lean_dec_ref_known(v___x_169_, 2);
return v___x_170_;
}
}
}
case 1:
{
lean_object* v___x_173_; 
v___x_173_ = ((lean_object*)(lp_JunkValues_JunkValues_instToJsonStatus_toJson___closed__3));
return v___x_173_;
}
default: 
{
lean_object* v_how_174_; lean_object* v___x_176_; uint8_t v_isShared_177_; uint8_t v_isSharedCheck_190_; 
v_how_174_ = lean_ctor_get(v_x_155_, 0);
v_isSharedCheck_190_ = !lean_is_exclusive(v_x_155_);
if (v_isSharedCheck_190_ == 0)
{
v___x_176_ = v_x_155_;
v_isShared_177_ = v_isSharedCheck_190_;
goto v_resetjp_175_;
}
else
{
lean_inc(v_how_174_);
lean_dec(v_x_155_);
v___x_176_ = lean_box(0);
v_isShared_177_ = v_isSharedCheck_190_;
goto v_resetjp_175_;
}
v_resetjp_175_:
{
lean_object* v___x_178_; lean_object* v___x_179_; lean_object* v___x_181_; 
v___x_178_ = ((lean_object*)(lp_JunkValues_JunkValues_instToJsonStatus_toJson___closed__4));
v___x_179_ = ((lean_object*)(lp_JunkValues_JunkValues_instToJsonStatus_toJson___closed__1));
if (v_isShared_177_ == 0)
{
lean_ctor_set_tag(v___x_176_, 3);
v___x_181_ = v___x_176_;
goto v_reusejp_180_;
}
else
{
lean_object* v_reuseFailAlloc_189_; 
v_reuseFailAlloc_189_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v_reuseFailAlloc_189_, 0, v_how_174_);
v___x_181_ = v_reuseFailAlloc_189_;
goto v_reusejp_180_;
}
v_reusejp_180_:
{
lean_object* v___x_182_; lean_object* v___x_183_; lean_object* v___x_184_; lean_object* v___x_185_; lean_object* v___x_186_; lean_object* v___x_187_; lean_object* v___x_188_; 
v___x_182_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_182_, 0, v___x_179_);
lean_ctor_set(v___x_182_, 1, v___x_181_);
v___x_183_ = lean_box(0);
v___x_184_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_184_, 0, v___x_182_);
lean_ctor_set(v___x_184_, 1, v___x_183_);
v___x_185_ = l_Lean_Json_mkObj(v___x_184_);
lean_dec_ref_known(v___x_184_, 2);
v___x_186_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_186_, 0, v___x_178_);
lean_ctor_set(v___x_186_, 1, v___x_185_);
v___x_187_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_187_, 0, v___x_186_);
lean_ctor_set(v___x_187_, 1, v___x_183_);
v___x_188_ = l_Lean_Json_mkObj(v___x_187_);
lean_dec_ref_known(v___x_187_, 2);
return v___x_188_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instFromJsonStatus_fromJson(lean_object* v_json_209_){
_start:
{
lean_object* v___x_210_; 
lean_inc(v_json_209_);
v___x_210_ = l_Lean_Json_getTag_x3f(v_json_209_);
if (lean_obj_tag(v___x_210_) == 0)
{
lean_object* v___x_211_; 
lean_dec(v_json_209_);
v___x_211_ = ((lean_object*)(lp_JunkValues_JunkValues_instFromJsonStatus_fromJson___closed__1));
return v___x_211_;
}
else
{
lean_object* v_val_212_; lean_object* v___x_214_; uint8_t v_isShared_215_; uint8_t v_isSharedCheck_293_; 
v_val_212_ = lean_ctor_get(v___x_210_, 0);
v_isSharedCheck_293_ = !lean_is_exclusive(v___x_210_);
if (v_isSharedCheck_293_ == 0)
{
v___x_214_ = v___x_210_;
v_isShared_215_ = v_isSharedCheck_293_;
goto v_resetjp_213_;
}
else
{
lean_inc(v_val_212_);
lean_dec(v___x_210_);
v___x_214_ = lean_box(0);
v_isShared_215_ = v_isSharedCheck_293_;
goto v_resetjp_213_;
}
v_resetjp_213_:
{
lean_object* v___x_216_; uint8_t v___x_217_; 
v___x_216_ = ((lean_object*)(lp_JunkValues_JunkValues_instToJsonStatus_toJson___closed__2));
v___x_217_ = lean_string_dec_eq(v_val_212_, v___x_216_);
if (v___x_217_ == 0)
{
lean_object* v___x_218_; lean_object* v___x_219_; uint8_t v___x_220_; 
v___x_218_ = lean_box(0);
v___x_219_ = ((lean_object*)(lp_JunkValues_JunkValues_instToJsonStatus_toJson___closed__4));
v___x_220_ = lean_string_dec_eq(v_val_212_, v___x_219_);
if (v___x_220_ == 0)
{
lean_object* v___x_221_; uint8_t v___x_222_; 
v___x_221_ = ((lean_object*)(lp_JunkValues_JunkValues_instToJsonStatus_toJson___closed__0));
v___x_222_ = lean_string_dec_eq(v_val_212_, v___x_221_);
lean_dec(v_val_212_);
if (v___x_222_ == 0)
{
lean_object* v___x_223_; 
lean_del_object(v___x_214_);
lean_dec(v_json_209_);
v___x_223_ = ((lean_object*)(lp_JunkValues_JunkValues_instFromJsonStatus_fromJson___closed__3));
return v___x_223_;
}
else
{
lean_object* v___x_224_; lean_object* v___x_225_; lean_object* v___x_226_; 
v___x_224_ = lean_unsigned_to_nat(1u);
v___x_225_ = ((lean_object*)(lp_JunkValues_JunkValues_instFromJsonStatus_fromJson___closed__6));
v___x_226_ = l_Lean_Json_parseCtorFields(v_json_209_, v___x_221_, v___x_224_, v___x_225_);
if (lean_obj_tag(v___x_226_) == 0)
{
lean_object* v_a_227_; lean_object* v___x_229_; uint8_t v_isShared_230_; uint8_t v_isSharedCheck_234_; 
lean_del_object(v___x_214_);
v_a_227_ = lean_ctor_get(v___x_226_, 0);
v_isSharedCheck_234_ = !lean_is_exclusive(v___x_226_);
if (v_isSharedCheck_234_ == 0)
{
v___x_229_ = v___x_226_;
v_isShared_230_ = v_isSharedCheck_234_;
goto v_resetjp_228_;
}
else
{
lean_inc(v_a_227_);
lean_dec(v___x_226_);
v___x_229_ = lean_box(0);
v_isShared_230_ = v_isSharedCheck_234_;
goto v_resetjp_228_;
}
v_resetjp_228_:
{
lean_object* v___x_232_; 
if (v_isShared_230_ == 0)
{
v___x_232_ = v___x_229_;
goto v_reusejp_231_;
}
else
{
lean_object* v_reuseFailAlloc_233_; 
v_reuseFailAlloc_233_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_233_, 0, v_a_227_);
v___x_232_ = v_reuseFailAlloc_233_;
goto v_reusejp_231_;
}
v_reusejp_231_:
{
return v___x_232_;
}
}
}
else
{
lean_object* v_a_235_; lean_object* v___x_236_; lean_object* v___x_237_; lean_object* v___x_238_; 
v_a_235_ = lean_ctor_get(v___x_226_, 0);
lean_inc(v_a_235_);
lean_dec_ref_known(v___x_226_, 1);
v___x_236_ = lean_unsigned_to_nat(0u);
v___x_237_ = lean_array_get(v___x_218_, v_a_235_, v___x_236_);
lean_dec(v_a_235_);
v___x_238_ = l_Lean_Json_getStr_x3f(v___x_237_);
if (lean_obj_tag(v___x_238_) == 0)
{
lean_object* v_a_239_; lean_object* v___x_241_; uint8_t v_isShared_242_; uint8_t v_isSharedCheck_246_; 
lean_del_object(v___x_214_);
v_a_239_ = lean_ctor_get(v___x_238_, 0);
v_isSharedCheck_246_ = !lean_is_exclusive(v___x_238_);
if (v_isSharedCheck_246_ == 0)
{
v___x_241_ = v___x_238_;
v_isShared_242_ = v_isSharedCheck_246_;
goto v_resetjp_240_;
}
else
{
lean_inc(v_a_239_);
lean_dec(v___x_238_);
v___x_241_ = lean_box(0);
v_isShared_242_ = v_isSharedCheck_246_;
goto v_resetjp_240_;
}
v_resetjp_240_:
{
lean_object* v___x_244_; 
if (v_isShared_242_ == 0)
{
v___x_244_ = v___x_241_;
goto v_reusejp_243_;
}
else
{
lean_object* v_reuseFailAlloc_245_; 
v_reuseFailAlloc_245_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_245_, 0, v_a_239_);
v___x_244_ = v_reuseFailAlloc_245_;
goto v_reusejp_243_;
}
v_reusejp_243_:
{
return v___x_244_;
}
}
}
else
{
lean_object* v_a_247_; lean_object* v___x_249_; uint8_t v_isShared_250_; uint8_t v_isSharedCheck_257_; 
v_a_247_ = lean_ctor_get(v___x_238_, 0);
v_isSharedCheck_257_ = !lean_is_exclusive(v___x_238_);
if (v_isSharedCheck_257_ == 0)
{
v___x_249_ = v___x_238_;
v_isShared_250_ = v_isSharedCheck_257_;
goto v_resetjp_248_;
}
else
{
lean_inc(v_a_247_);
lean_dec(v___x_238_);
v___x_249_ = lean_box(0);
v_isShared_250_ = v_isSharedCheck_257_;
goto v_resetjp_248_;
}
v_resetjp_248_:
{
lean_object* v___x_252_; 
if (v_isShared_215_ == 0)
{
lean_ctor_set_tag(v___x_214_, 0);
lean_ctor_set(v___x_214_, 0, v_a_247_);
v___x_252_ = v___x_214_;
goto v_reusejp_251_;
}
else
{
lean_object* v_reuseFailAlloc_256_; 
v_reuseFailAlloc_256_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_256_, 0, v_a_247_);
v___x_252_ = v_reuseFailAlloc_256_;
goto v_reusejp_251_;
}
v_reusejp_251_:
{
lean_object* v___x_254_; 
if (v_isShared_250_ == 0)
{
lean_ctor_set(v___x_249_, 0, v___x_252_);
v___x_254_ = v___x_249_;
goto v_reusejp_253_;
}
else
{
lean_object* v_reuseFailAlloc_255_; 
v_reuseFailAlloc_255_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_255_, 0, v___x_252_);
v___x_254_ = v_reuseFailAlloc_255_;
goto v_reusejp_253_;
}
v_reusejp_253_:
{
return v___x_254_;
}
}
}
}
}
}
}
else
{
lean_object* v___x_258_; lean_object* v___x_259_; lean_object* v___x_260_; 
lean_dec(v_val_212_);
v___x_258_ = lean_unsigned_to_nat(1u);
v___x_259_ = ((lean_object*)(lp_JunkValues_JunkValues_instFromJsonStatus_fromJson___closed__6));
v___x_260_ = l_Lean_Json_parseCtorFields(v_json_209_, v___x_219_, v___x_258_, v___x_259_);
if (lean_obj_tag(v___x_260_) == 0)
{
lean_object* v_a_261_; lean_object* v___x_263_; uint8_t v_isShared_264_; uint8_t v_isSharedCheck_268_; 
lean_del_object(v___x_214_);
v_a_261_ = lean_ctor_get(v___x_260_, 0);
v_isSharedCheck_268_ = !lean_is_exclusive(v___x_260_);
if (v_isSharedCheck_268_ == 0)
{
v___x_263_ = v___x_260_;
v_isShared_264_ = v_isSharedCheck_268_;
goto v_resetjp_262_;
}
else
{
lean_inc(v_a_261_);
lean_dec(v___x_260_);
v___x_263_ = lean_box(0);
v_isShared_264_ = v_isSharedCheck_268_;
goto v_resetjp_262_;
}
v_resetjp_262_:
{
lean_object* v___x_266_; 
if (v_isShared_264_ == 0)
{
v___x_266_ = v___x_263_;
goto v_reusejp_265_;
}
else
{
lean_object* v_reuseFailAlloc_267_; 
v_reuseFailAlloc_267_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_267_, 0, v_a_261_);
v___x_266_ = v_reuseFailAlloc_267_;
goto v_reusejp_265_;
}
v_reusejp_265_:
{
return v___x_266_;
}
}
}
else
{
lean_object* v_a_269_; lean_object* v___x_270_; lean_object* v___x_271_; lean_object* v___x_272_; 
v_a_269_ = lean_ctor_get(v___x_260_, 0);
lean_inc(v_a_269_);
lean_dec_ref_known(v___x_260_, 1);
v___x_270_ = lean_unsigned_to_nat(0u);
v___x_271_ = lean_array_get(v___x_218_, v_a_269_, v___x_270_);
lean_dec(v_a_269_);
v___x_272_ = l_Lean_Json_getStr_x3f(v___x_271_);
if (lean_obj_tag(v___x_272_) == 0)
{
lean_object* v_a_273_; lean_object* v___x_275_; uint8_t v_isShared_276_; uint8_t v_isSharedCheck_280_; 
lean_del_object(v___x_214_);
v_a_273_ = lean_ctor_get(v___x_272_, 0);
v_isSharedCheck_280_ = !lean_is_exclusive(v___x_272_);
if (v_isSharedCheck_280_ == 0)
{
v___x_275_ = v___x_272_;
v_isShared_276_ = v_isSharedCheck_280_;
goto v_resetjp_274_;
}
else
{
lean_inc(v_a_273_);
lean_dec(v___x_272_);
v___x_275_ = lean_box(0);
v_isShared_276_ = v_isSharedCheck_280_;
goto v_resetjp_274_;
}
v_resetjp_274_:
{
lean_object* v___x_278_; 
if (v_isShared_276_ == 0)
{
v___x_278_ = v___x_275_;
goto v_reusejp_277_;
}
else
{
lean_object* v_reuseFailAlloc_279_; 
v_reuseFailAlloc_279_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_279_, 0, v_a_273_);
v___x_278_ = v_reuseFailAlloc_279_;
goto v_reusejp_277_;
}
v_reusejp_277_:
{
return v___x_278_;
}
}
}
else
{
lean_object* v_a_281_; lean_object* v___x_283_; uint8_t v_isShared_284_; uint8_t v_isSharedCheck_291_; 
v_a_281_ = lean_ctor_get(v___x_272_, 0);
v_isSharedCheck_291_ = !lean_is_exclusive(v___x_272_);
if (v_isSharedCheck_291_ == 0)
{
v___x_283_ = v___x_272_;
v_isShared_284_ = v_isSharedCheck_291_;
goto v_resetjp_282_;
}
else
{
lean_inc(v_a_281_);
lean_dec(v___x_272_);
v___x_283_ = lean_box(0);
v_isShared_284_ = v_isSharedCheck_291_;
goto v_resetjp_282_;
}
v_resetjp_282_:
{
lean_object* v___x_286_; 
if (v_isShared_215_ == 0)
{
lean_ctor_set_tag(v___x_214_, 2);
lean_ctor_set(v___x_214_, 0, v_a_281_);
v___x_286_ = v___x_214_;
goto v_reusejp_285_;
}
else
{
lean_object* v_reuseFailAlloc_290_; 
v_reuseFailAlloc_290_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v_reuseFailAlloc_290_, 0, v_a_281_);
v___x_286_ = v_reuseFailAlloc_290_;
goto v_reusejp_285_;
}
v_reusejp_285_:
{
lean_object* v___x_288_; 
if (v_isShared_284_ == 0)
{
lean_ctor_set(v___x_283_, 0, v___x_286_);
v___x_288_ = v___x_283_;
goto v_reusejp_287_;
}
else
{
lean_object* v_reuseFailAlloc_289_; 
v_reuseFailAlloc_289_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_289_, 0, v___x_286_);
v___x_288_ = v_reuseFailAlloc_289_;
goto v_reusejp_287_;
}
v_reusejp_287_:
{
return v___x_288_;
}
}
}
}
}
}
}
else
{
lean_object* v___x_292_; 
lean_del_object(v___x_214_);
lean_dec(v_val_212_);
lean_dec(v_json_209_);
v___x_292_ = ((lean_object*)(lp_JunkValues_JunkValues_instFromJsonStatus_fromJson___closed__7));
return v___x_292_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Status_slug(lean_object* v_x_296_){
_start:
{
switch(lean_obj_tag(v_x_296_))
{
case 0:
{
lean_object* v___x_297_; 
v___x_297_ = ((lean_object*)(lp_JunkValues_JunkValues_instToJsonStatus_toJson___closed__0));
return v___x_297_;
}
case 1:
{
lean_object* v___x_298_; 
v___x_298_ = ((lean_object*)(lp_JunkValues_JunkValues_instToJsonStatus_toJson___closed__2));
return v___x_298_;
}
default: 
{
lean_object* v___x_299_; 
v___x_299_ = ((lean_object*)(lp_JunkValues_JunkValues_instToJsonStatus_toJson___closed__4));
return v___x_299_;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Status_slug___boxed(lean_object* v_x_300_){
_start:
{
lean_object* v_res_301_; 
v_res_301_ = lp_JunkValues_JunkValues_Status_slug(v_x_300_);
lean_dec(v_x_300_);
return v_res_301_;
}
}
LEAN_EXPORT uint8_t lp_JunkValues_JunkValues_Status_isFinding(lean_object* v_x_302_){
_start:
{
if (lean_obj_tag(v_x_302_) == 0)
{
uint8_t v___x_303_; 
v___x_303_ = 0;
return v___x_303_;
}
else
{
uint8_t v___x_304_; 
v___x_304_ = 1;
return v___x_304_;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Status_isFinding___boxed(lean_object* v_x_305_){
_start:
{
uint8_t v_res_306_; lean_object* v_r_307_; 
v_res_306_ = lp_JunkValues_JunkValues_Status_isFinding(v_x_305_);
lean_dec(v_x_305_);
v_r_307_ = lean_box(v_res_306_);
return v_r_307_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Site_ctorIdx(uint8_t v_x_308_){
_start:
{
if (v_x_308_ == 0)
{
lean_object* v___x_309_; 
v___x_309_ = lean_unsigned_to_nat(0u);
return v___x_309_;
}
else
{
lean_object* v___x_310_; 
v___x_310_ = lean_unsigned_to_nat(1u);
return v___x_310_;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Site_ctorIdx___boxed(lean_object* v_x_311_){
_start:
{
uint8_t v_x_boxed_312_; lean_object* v_res_313_; 
v_x_boxed_312_ = lean_unbox(v_x_311_);
v_res_313_ = lp_JunkValues_JunkValues_Site_ctorIdx(v_x_boxed_312_);
return v_res_313_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Site_toCtorIdx(uint8_t v_x_314_){
_start:
{
lean_object* v___x_315_; 
v___x_315_ = lp_JunkValues_JunkValues_Site_ctorIdx(v_x_314_);
return v___x_315_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Site_toCtorIdx___boxed(lean_object* v_x_316_){
_start:
{
uint8_t v_x_4__boxed_317_; lean_object* v_res_318_; 
v_x_4__boxed_317_ = lean_unbox(v_x_316_);
v_res_318_ = lp_JunkValues_JunkValues_Site_toCtorIdx(v_x_4__boxed_317_);
return v_res_318_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Site_ctorElim___redArg(lean_object* v_k_319_){
_start:
{
lean_inc(v_k_319_);
return v_k_319_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Site_ctorElim___redArg___boxed(lean_object* v_k_320_){
_start:
{
lean_object* v_res_321_; 
v_res_321_ = lp_JunkValues_JunkValues_Site_ctorElim___redArg(v_k_320_);
lean_dec(v_k_320_);
return v_res_321_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Site_ctorElim(lean_object* v_motive_322_, lean_object* v_ctorIdx_323_, uint8_t v_t_324_, lean_object* v_h_325_, lean_object* v_k_326_){
_start:
{
lean_inc(v_k_326_);
return v_k_326_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Site_ctorElim___boxed(lean_object* v_motive_327_, lean_object* v_ctorIdx_328_, lean_object* v_t_329_, lean_object* v_h_330_, lean_object* v_k_331_){
_start:
{
uint8_t v_t_boxed_332_; lean_object* v_res_333_; 
v_t_boxed_332_ = lean_unbox(v_t_329_);
v_res_333_ = lp_JunkValues_JunkValues_Site_ctorElim(v_motive_327_, v_ctorIdx_328_, v_t_boxed_332_, v_h_330_, v_k_331_);
lean_dec(v_k_331_);
lean_dec(v_ctorIdx_328_);
return v_res_333_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Site_statement_elim___redArg(lean_object* v_statement_334_){
_start:
{
lean_inc(v_statement_334_);
return v_statement_334_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Site_statement_elim___redArg___boxed(lean_object* v_statement_335_){
_start:
{
lean_object* v_res_336_; 
v_res_336_ = lp_JunkValues_JunkValues_Site_statement_elim___redArg(v_statement_335_);
lean_dec(v_statement_335_);
return v_res_336_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Site_statement_elim(lean_object* v_motive_337_, uint8_t v_t_338_, lean_object* v_h_339_, lean_object* v_statement_340_){
_start:
{
lean_inc(v_statement_340_);
return v_statement_340_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Site_statement_elim___boxed(lean_object* v_motive_341_, lean_object* v_t_342_, lean_object* v_h_343_, lean_object* v_statement_344_){
_start:
{
uint8_t v_t_boxed_345_; lean_object* v_res_346_; 
v_t_boxed_345_ = lean_unbox(v_t_342_);
v_res_346_ = lp_JunkValues_JunkValues_Site_statement_elim(v_motive_341_, v_t_boxed_345_, v_h_343_, v_statement_344_);
lean_dec(v_statement_344_);
return v_res_346_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Site_body_elim___redArg(lean_object* v_body_347_){
_start:
{
lean_inc(v_body_347_);
return v_body_347_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Site_body_elim___redArg___boxed(lean_object* v_body_348_){
_start:
{
lean_object* v_res_349_; 
v_res_349_ = lp_JunkValues_JunkValues_Site_body_elim___redArg(v_body_348_);
lean_dec(v_body_348_);
return v_res_349_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Site_body_elim(lean_object* v_motive_350_, uint8_t v_t_351_, lean_object* v_h_352_, lean_object* v_body_353_){
_start:
{
lean_inc(v_body_353_);
return v_body_353_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Site_body_elim___boxed(lean_object* v_motive_354_, lean_object* v_t_355_, lean_object* v_h_356_, lean_object* v_body_357_){
_start:
{
uint8_t v_t_boxed_358_; lean_object* v_res_359_; 
v_t_boxed_358_ = lean_unbox(v_t_355_);
v_res_359_ = lp_JunkValues_JunkValues_Site_body_elim(v_motive_354_, v_t_boxed_358_, v_h_356_, v_body_357_);
lean_dec(v_body_357_);
return v_res_359_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instReprSite_repr(uint8_t v_x_366_, lean_object* v_prec_367_){
_start:
{
lean_object* v___y_369_; lean_object* v___y_376_; 
if (v_x_366_ == 0)
{
lean_object* v___x_382_; uint8_t v___x_383_; 
v___x_382_ = lean_unsigned_to_nat(1024u);
v___x_383_ = lean_nat_dec_le(v___x_382_, v_prec_367_);
if (v___x_383_ == 0)
{
lean_object* v___x_384_; 
v___x_384_ = lean_obj_once(&lp_JunkValues_JunkValues_instReprStatus_repr___closed__5, &lp_JunkValues_JunkValues_instReprStatus_repr___closed__5_once, _init_lp_JunkValues_JunkValues_instReprStatus_repr___closed__5);
v___y_369_ = v___x_384_;
goto v___jp_368_;
}
else
{
lean_object* v___x_385_; 
v___x_385_ = lean_obj_once(&lp_JunkValues_JunkValues_instReprStatus_repr___closed__6, &lp_JunkValues_JunkValues_instReprStatus_repr___closed__6_once, _init_lp_JunkValues_JunkValues_instReprStatus_repr___closed__6);
v___y_369_ = v___x_385_;
goto v___jp_368_;
}
}
else
{
lean_object* v___x_386_; uint8_t v___x_387_; 
v___x_386_ = lean_unsigned_to_nat(1024u);
v___x_387_ = lean_nat_dec_le(v___x_386_, v_prec_367_);
if (v___x_387_ == 0)
{
lean_object* v___x_388_; 
v___x_388_ = lean_obj_once(&lp_JunkValues_JunkValues_instReprStatus_repr___closed__5, &lp_JunkValues_JunkValues_instReprStatus_repr___closed__5_once, _init_lp_JunkValues_JunkValues_instReprStatus_repr___closed__5);
v___y_376_ = v___x_388_;
goto v___jp_375_;
}
else
{
lean_object* v___x_389_; 
v___x_389_ = lean_obj_once(&lp_JunkValues_JunkValues_instReprStatus_repr___closed__6, &lp_JunkValues_JunkValues_instReprStatus_repr___closed__6_once, _init_lp_JunkValues_JunkValues_instReprStatus_repr___closed__6);
v___y_376_ = v___x_389_;
goto v___jp_375_;
}
}
v___jp_368_:
{
lean_object* v___x_370_; lean_object* v___x_371_; uint8_t v___x_372_; lean_object* v___x_373_; lean_object* v___x_374_; 
v___x_370_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprSite_repr___closed__1));
lean_inc(v___y_369_);
v___x_371_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_371_, 0, v___y_369_);
lean_ctor_set(v___x_371_, 1, v___x_370_);
v___x_372_ = 0;
v___x_373_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_373_, 0, v___x_371_);
lean_ctor_set_uint8(v___x_373_, sizeof(void*)*1, v___x_372_);
v___x_374_ = l_Repr_addAppParen(v___x_373_, v_prec_367_);
return v___x_374_;
}
v___jp_375_:
{
lean_object* v___x_377_; lean_object* v___x_378_; uint8_t v___x_379_; lean_object* v___x_380_; lean_object* v___x_381_; 
v___x_377_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprSite_repr___closed__3));
lean_inc(v___y_376_);
v___x_378_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_378_, 0, v___y_376_);
lean_ctor_set(v___x_378_, 1, v___x_377_);
v___x_379_ = 0;
v___x_380_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_380_, 0, v___x_378_);
lean_ctor_set_uint8(v___x_380_, sizeof(void*)*1, v___x_379_);
v___x_381_ = l_Repr_addAppParen(v___x_380_, v_prec_367_);
return v___x_381_;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instReprSite_repr___boxed(lean_object* v_x_390_, lean_object* v_prec_391_){
_start:
{
uint8_t v_x_117__boxed_392_; lean_object* v_res_393_; 
v_x_117__boxed_392_ = lean_unbox(v_x_390_);
v_res_393_ = lp_JunkValues_JunkValues_instReprSite_repr(v_x_117__boxed_392_, v_prec_391_);
lean_dec(v_prec_391_);
return v_res_393_;
}
}
static uint8_t _init_lp_JunkValues_JunkValues_instInhabitedSite_default(void){
_start:
{
uint8_t v___x_396_; 
v___x_396_ = 0;
return v___x_396_;
}
}
static uint8_t _init_lp_JunkValues_JunkValues_instInhabitedSite(void){
_start:
{
uint8_t v___x_397_; 
v___x_397_ = 0;
return v___x_397_;
}
}
LEAN_EXPORT uint8_t lp_JunkValues_JunkValues_instBEqSite_beq(uint8_t v_x_398_, uint8_t v_y_399_){
_start:
{
lean_object* v___x_400_; lean_object* v___x_401_; uint8_t v___x_402_; 
v___x_400_ = lp_JunkValues_JunkValues_Site_ctorIdx(v_x_398_);
v___x_401_ = lp_JunkValues_JunkValues_Site_ctorIdx(v_y_399_);
v___x_402_ = lean_nat_dec_eq(v___x_400_, v___x_401_);
lean_dec(v___x_401_);
lean_dec(v___x_400_);
return v___x_402_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instBEqSite_beq___boxed(lean_object* v_x_403_, lean_object* v_y_404_){
_start:
{
uint8_t v_x_17__boxed_405_; uint8_t v_y_18__boxed_406_; uint8_t v_res_407_; lean_object* v_r_408_; 
v_x_17__boxed_405_ = lean_unbox(v_x_403_);
v_y_18__boxed_406_ = lean_unbox(v_y_404_);
v_res_407_ = lp_JunkValues_JunkValues_instBEqSite_beq(v_x_17__boxed_405_, v_y_18__boxed_406_);
v_r_408_ = lean_box(v_res_407_);
return v_r_408_;
}
}
LEAN_EXPORT uint8_t lp_JunkValues_JunkValues_Site_ofNat(lean_object* v_n_411_){
_start:
{
lean_object* v___x_412_; uint8_t v___x_413_; 
v___x_412_ = lean_unsigned_to_nat(0u);
v___x_413_ = lean_nat_dec_le(v_n_411_, v___x_412_);
if (v___x_413_ == 0)
{
uint8_t v___x_414_; 
v___x_414_ = 1;
return v___x_414_;
}
else
{
uint8_t v___x_415_; 
v___x_415_ = 0;
return v___x_415_;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Site_ofNat___boxed(lean_object* v_n_416_){
_start:
{
uint8_t v_res_417_; lean_object* v_r_418_; 
v_res_417_ = lp_JunkValues_JunkValues_Site_ofNat(v_n_416_);
lean_dec(v_n_416_);
v_r_418_ = lean_box(v_res_417_);
return v_r_418_;
}
}
LEAN_EXPORT uint8_t lp_JunkValues_JunkValues_instDecidableEqSite(uint8_t v_x_419_, uint8_t v_y_420_){
_start:
{
lean_object* v___x_421_; lean_object* v___x_422_; uint8_t v___x_423_; 
v___x_421_ = lp_JunkValues_JunkValues_Site_ctorIdx(v_x_419_);
v___x_422_ = lp_JunkValues_JunkValues_Site_ctorIdx(v_y_420_);
v___x_423_ = lean_nat_dec_eq(v___x_421_, v___x_422_);
lean_dec(v___x_422_);
lean_dec(v___x_421_);
return v___x_423_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instDecidableEqSite___boxed(lean_object* v_x_424_, lean_object* v_y_425_){
_start:
{
uint8_t v_x_13__boxed_426_; uint8_t v_y_14__boxed_427_; uint8_t v_res_428_; lean_object* v_r_429_; 
v_x_13__boxed_426_ = lean_unbox(v_x_424_);
v_y_14__boxed_427_ = lean_unbox(v_y_425_);
v_res_428_ = lp_JunkValues_JunkValues_instDecidableEqSite(v_x_13__boxed_426_, v_y_14__boxed_427_);
v_r_429_ = lean_box(v_res_428_);
return v_r_429_;
}
}
LEAN_EXPORT uint64_t lp_JunkValues_JunkValues_instHashableSite_hash(uint8_t v_x_430_){
_start:
{
if (v_x_430_ == 0)
{
uint64_t v___x_431_; 
v___x_431_ = 0ULL;
return v___x_431_;
}
else
{
uint64_t v___x_432_; 
v___x_432_ = 1ULL;
return v___x_432_;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instHashableSite_hash___boxed(lean_object* v_x_433_){
_start:
{
uint8_t v_x_28__boxed_434_; uint64_t v_res_435_; lean_object* v_r_436_; 
v_x_28__boxed_434_ = lean_unbox(v_x_433_);
v_res_435_ = lp_JunkValues_JunkValues_instHashableSite_hash(v_x_28__boxed_434_);
v_r_436_ = lean_box_uint64(v_res_435_);
return v_r_436_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instToJsonSite_toJson(uint8_t v_x_445_){
_start:
{
if (v_x_445_ == 0)
{
lean_object* v___x_446_; 
v___x_446_ = ((lean_object*)(lp_JunkValues_JunkValues_instToJsonSite_toJson___closed__1));
return v___x_446_;
}
else
{
lean_object* v___x_447_; 
v___x_447_ = ((lean_object*)(lp_JunkValues_JunkValues_instToJsonSite_toJson___closed__3));
return v___x_447_;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instToJsonSite_toJson___boxed(lean_object* v_x_448_){
_start:
{
uint8_t v_x_46__boxed_449_; lean_object* v_res_450_; 
v_x_46__boxed_449_ = lean_unbox(v_x_448_);
v_res_450_ = lp_JunkValues_JunkValues_instToJsonSite_toJson(v_x_46__boxed_449_);
return v_res_450_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instFromJsonSite_fromJson(lean_object* v_json_463_){
_start:
{
lean_object* v___x_464_; 
v___x_464_ = l_Lean_Json_getTag_x3f(v_json_463_);
if (lean_obj_tag(v___x_464_) == 0)
{
lean_object* v___x_465_; 
v___x_465_ = ((lean_object*)(lp_JunkValues_JunkValues_instFromJsonSite_fromJson___closed__0));
return v___x_465_;
}
else
{
lean_object* v_val_466_; lean_object* v___x_467_; uint8_t v___x_468_; 
v_val_466_ = lean_ctor_get(v___x_464_, 0);
lean_inc(v_val_466_);
lean_dec_ref_known(v___x_464_, 1);
v___x_467_ = ((lean_object*)(lp_JunkValues_JunkValues_instToJsonSite_toJson___closed__2));
v___x_468_ = lean_string_dec_eq(v_val_466_, v___x_467_);
if (v___x_468_ == 0)
{
lean_object* v___x_469_; uint8_t v___x_470_; 
v___x_469_ = ((lean_object*)(lp_JunkValues_JunkValues_instToJsonSite_toJson___closed__0));
v___x_470_ = lean_string_dec_eq(v_val_466_, v___x_469_);
lean_dec(v_val_466_);
if (v___x_470_ == 0)
{
lean_object* v___x_471_; 
v___x_471_ = ((lean_object*)(lp_JunkValues_JunkValues_instFromJsonSite_fromJson___closed__1));
return v___x_471_;
}
else
{
lean_object* v___x_472_; 
v___x_472_ = ((lean_object*)(lp_JunkValues_JunkValues_instFromJsonSite_fromJson___closed__2));
return v___x_472_;
}
}
else
{
lean_object* v___x_473_; 
lean_dec(v_val_466_);
v___x_473_ = ((lean_object*)(lp_JunkValues_JunkValues_instFromJsonSite_fromJson___closed__3));
return v___x_473_;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Site_slug(uint8_t v_x_476_){
_start:
{
if (v_x_476_ == 0)
{
lean_object* v___x_477_; 
v___x_477_ = ((lean_object*)(lp_JunkValues_JunkValues_instToJsonSite_toJson___closed__0));
return v___x_477_;
}
else
{
lean_object* v___x_478_; 
v___x_478_ = ((lean_object*)(lp_JunkValues_JunkValues_instToJsonSite_toJson___closed__2));
return v___x_478_;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Site_slug___boxed(lean_object* v_x_479_){
_start:
{
uint8_t v_x_20__boxed_480_; lean_object* v_res_481_; 
v_x_20__boxed_480_ = lean_unbox(v_x_479_);
v_res_481_ = lp_JunkValues_JunkValues_Site_slug(v_x_20__boxed_480_);
return v_res_481_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Nat_cast___at___00JunkValues_instReprFinding_repr_spec__1(lean_object* v_a_482_){
_start:
{
lean_object* v___x_483_; 
v___x_483_ = lean_nat_to_int(v_a_482_);
return v___x_483_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_Format_joinSep___at___00Array_repr___at___00JunkValues_instReprFinding_repr_spec__0_spec__0___lam__0(lean_object* v___y_484_){
_start:
{
lean_object* v___x_485_; lean_object* v___x_486_; 
v___x_485_ = l_String_quote(v___y_484_);
v___x_486_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_486_, 0, v___x_485_);
return v___x_486_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_List_foldl___at___00List_foldl___at___00Std_Format_joinSep___at___00Array_repr___at___00JunkValues_instReprFinding_repr_spec__0_spec__0_spec__2_spec__3(lean_object* v_x_487_, lean_object* v_x_488_, lean_object* v_x_489_){
_start:
{
if (lean_obj_tag(v_x_489_) == 0)
{
lean_dec(v_x_487_);
return v_x_488_;
}
else
{
lean_object* v_head_490_; lean_object* v_tail_491_; lean_object* v___x_493_; uint8_t v_isShared_494_; uint8_t v_isSharedCheck_502_; 
v_head_490_ = lean_ctor_get(v_x_489_, 0);
v_tail_491_ = lean_ctor_get(v_x_489_, 1);
v_isSharedCheck_502_ = !lean_is_exclusive(v_x_489_);
if (v_isSharedCheck_502_ == 0)
{
v___x_493_ = v_x_489_;
v_isShared_494_ = v_isSharedCheck_502_;
goto v_resetjp_492_;
}
else
{
lean_inc(v_tail_491_);
lean_inc(v_head_490_);
lean_dec(v_x_489_);
v___x_493_ = lean_box(0);
v_isShared_494_ = v_isSharedCheck_502_;
goto v_resetjp_492_;
}
v_resetjp_492_:
{
lean_object* v___x_496_; 
lean_inc(v_x_487_);
if (v_isShared_494_ == 0)
{
lean_ctor_set_tag(v___x_493_, 5);
lean_ctor_set(v___x_493_, 1, v_x_487_);
lean_ctor_set(v___x_493_, 0, v_x_488_);
v___x_496_ = v___x_493_;
goto v_reusejp_495_;
}
else
{
lean_object* v_reuseFailAlloc_501_; 
v_reuseFailAlloc_501_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v_reuseFailAlloc_501_, 0, v_x_488_);
lean_ctor_set(v_reuseFailAlloc_501_, 1, v_x_487_);
v___x_496_ = v_reuseFailAlloc_501_;
goto v_reusejp_495_;
}
v_reusejp_495_:
{
lean_object* v___x_497_; lean_object* v___x_498_; lean_object* v___x_499_; 
v___x_497_ = l_String_quote(v_head_490_);
v___x_498_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_498_, 0, v___x_497_);
v___x_499_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_499_, 0, v___x_496_);
lean_ctor_set(v___x_499_, 1, v___x_498_);
v_x_488_ = v___x_499_;
v_x_489_ = v_tail_491_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_List_foldl___at___00Std_Format_joinSep___at___00Array_repr___at___00JunkValues_instReprFinding_repr_spec__0_spec__0_spec__2(lean_object* v_x_503_, lean_object* v_x_504_, lean_object* v_x_505_){
_start:
{
if (lean_obj_tag(v_x_505_) == 0)
{
lean_dec(v_x_503_);
return v_x_504_;
}
else
{
lean_object* v_head_506_; lean_object* v_tail_507_; lean_object* v___x_509_; uint8_t v_isShared_510_; uint8_t v_isSharedCheck_518_; 
v_head_506_ = lean_ctor_get(v_x_505_, 0);
v_tail_507_ = lean_ctor_get(v_x_505_, 1);
v_isSharedCheck_518_ = !lean_is_exclusive(v_x_505_);
if (v_isSharedCheck_518_ == 0)
{
v___x_509_ = v_x_505_;
v_isShared_510_ = v_isSharedCheck_518_;
goto v_resetjp_508_;
}
else
{
lean_inc(v_tail_507_);
lean_inc(v_head_506_);
lean_dec(v_x_505_);
v___x_509_ = lean_box(0);
v_isShared_510_ = v_isSharedCheck_518_;
goto v_resetjp_508_;
}
v_resetjp_508_:
{
lean_object* v___x_512_; 
lean_inc(v_x_503_);
if (v_isShared_510_ == 0)
{
lean_ctor_set_tag(v___x_509_, 5);
lean_ctor_set(v___x_509_, 1, v_x_503_);
lean_ctor_set(v___x_509_, 0, v_x_504_);
v___x_512_ = v___x_509_;
goto v_reusejp_511_;
}
else
{
lean_object* v_reuseFailAlloc_517_; 
v_reuseFailAlloc_517_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v_reuseFailAlloc_517_, 0, v_x_504_);
lean_ctor_set(v_reuseFailAlloc_517_, 1, v_x_503_);
v___x_512_ = v_reuseFailAlloc_517_;
goto v_reusejp_511_;
}
v_reusejp_511_:
{
lean_object* v___x_513_; lean_object* v___x_514_; lean_object* v___x_515_; lean_object* v___x_516_; 
v___x_513_ = l_String_quote(v_head_506_);
v___x_514_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_514_, 0, v___x_513_);
v___x_515_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_515_, 0, v___x_512_);
lean_ctor_set(v___x_515_, 1, v___x_514_);
v___x_516_ = lp_JunkValues_List_foldl___at___00List_foldl___at___00Std_Format_joinSep___at___00Array_repr___at___00JunkValues_instReprFinding_repr_spec__0_spec__0_spec__2_spec__3(v_x_503_, v___x_515_, v_tail_507_);
return v___x_516_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_Format_joinSep___at___00Array_repr___at___00JunkValues_instReprFinding_repr_spec__0_spec__0(lean_object* v_x_519_, lean_object* v_x_520_){
_start:
{
if (lean_obj_tag(v_x_519_) == 0)
{
lean_object* v___x_521_; 
lean_dec(v_x_520_);
v___x_521_ = lean_box(0);
return v___x_521_;
}
else
{
lean_object* v_tail_522_; 
v_tail_522_ = lean_ctor_get(v_x_519_, 1);
if (lean_obj_tag(v_tail_522_) == 0)
{
lean_object* v_head_523_; lean_object* v___x_524_; 
lean_dec(v_x_520_);
v_head_523_ = lean_ctor_get(v_x_519_, 0);
lean_inc(v_head_523_);
lean_dec_ref_known(v_x_519_, 2);
v___x_524_ = lp_JunkValues_Std_Format_joinSep___at___00Array_repr___at___00JunkValues_instReprFinding_repr_spec__0_spec__0___lam__0(v_head_523_);
return v___x_524_;
}
else
{
lean_object* v_head_525_; lean_object* v___x_526_; lean_object* v___x_527_; 
lean_inc(v_tail_522_);
v_head_525_ = lean_ctor_get(v_x_519_, 0);
lean_inc(v_head_525_);
lean_dec_ref_known(v_x_519_, 2);
v___x_526_ = lp_JunkValues_Std_Format_joinSep___at___00Array_repr___at___00JunkValues_instReprFinding_repr_spec__0_spec__0___lam__0(v_head_525_);
v___x_527_ = lp_JunkValues_List_foldl___at___00Std_Format_joinSep___at___00Array_repr___at___00JunkValues_instReprFinding_repr_spec__0_spec__0_spec__2(v_x_520_, v___x_526_, v_tail_522_);
return v___x_527_;
}
}
}
}
static lean_object* _init_lp_JunkValues_Array_repr___at___00JunkValues_instReprFinding_repr_spec__0___closed__5(void){
_start:
{
lean_object* v___x_536_; lean_object* v___x_537_; 
v___x_536_ = ((lean_object*)(lp_JunkValues_Array_repr___at___00JunkValues_instReprFinding_repr_spec__0___closed__0));
v___x_537_ = lean_string_length(v___x_536_);
return v___x_537_;
}
}
static lean_object* _init_lp_JunkValues_Array_repr___at___00JunkValues_instReprFinding_repr_spec__0___closed__6(void){
_start:
{
lean_object* v___x_538_; lean_object* v___x_539_; 
v___x_538_ = lean_obj_once(&lp_JunkValues_Array_repr___at___00JunkValues_instReprFinding_repr_spec__0___closed__5, &lp_JunkValues_Array_repr___at___00JunkValues_instReprFinding_repr_spec__0___closed__5_once, _init_lp_JunkValues_Array_repr___at___00JunkValues_instReprFinding_repr_spec__0___closed__5);
v___x_539_ = lean_nat_to_int(v___x_538_);
return v___x_539_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Array_repr___at___00JunkValues_instReprFinding_repr_spec__0(lean_object* v_xs_547_){
_start:
{
lean_object* v___x_548_; lean_object* v___x_549_; uint8_t v___x_550_; 
v___x_548_ = lean_array_get_size(v_xs_547_);
v___x_549_ = lean_unsigned_to_nat(0u);
v___x_550_ = lean_nat_dec_eq(v___x_548_, v___x_549_);
if (v___x_550_ == 0)
{
lean_object* v___x_551_; lean_object* v___x_552_; lean_object* v___x_553_; lean_object* v___x_554_; lean_object* v___x_555_; lean_object* v___x_556_; lean_object* v___x_557_; lean_object* v___x_558_; lean_object* v___x_559_; lean_object* v___x_560_; 
v___x_551_ = lean_array_to_list(v_xs_547_);
v___x_552_ = ((lean_object*)(lp_JunkValues_Array_repr___at___00JunkValues_instReprFinding_repr_spec__0___closed__3));
v___x_553_ = lp_JunkValues_Std_Format_joinSep___at___00Array_repr___at___00JunkValues_instReprFinding_repr_spec__0_spec__0(v___x_551_, v___x_552_);
v___x_554_ = lean_obj_once(&lp_JunkValues_Array_repr___at___00JunkValues_instReprFinding_repr_spec__0___closed__6, &lp_JunkValues_Array_repr___at___00JunkValues_instReprFinding_repr_spec__0___closed__6_once, _init_lp_JunkValues_Array_repr___at___00JunkValues_instReprFinding_repr_spec__0___closed__6);
v___x_555_ = ((lean_object*)(lp_JunkValues_Array_repr___at___00JunkValues_instReprFinding_repr_spec__0___closed__7));
v___x_556_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_556_, 0, v___x_555_);
lean_ctor_set(v___x_556_, 1, v___x_553_);
v___x_557_ = ((lean_object*)(lp_JunkValues_Array_repr___at___00JunkValues_instReprFinding_repr_spec__0___closed__8));
v___x_558_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_558_, 0, v___x_556_);
lean_ctor_set(v___x_558_, 1, v___x_557_);
v___x_559_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_559_, 0, v___x_554_);
lean_ctor_set(v___x_559_, 1, v___x_558_);
v___x_560_ = l_Std_Format_fill(v___x_559_);
return v___x_560_;
}
else
{
lean_object* v___x_561_; 
lean_dec_ref(v_xs_547_);
v___x_561_ = ((lean_object*)(lp_JunkValues_Array_repr___at___00JunkValues_instReprFinding_repr_spec__0___closed__10));
return v___x_561_;
}
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__7(void){
_start:
{
lean_object* v___x_575_; lean_object* v___x_576_; 
v___x_575_ = lean_unsigned_to_nat(8u);
v___x_576_ = lean_nat_to_int(v___x_575_);
return v___x_576_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__18(void){
_start:
{
lean_object* v___x_592_; lean_object* v___x_593_; 
v___x_592_ = lean_unsigned_to_nat(10u);
v___x_593_ = lean_nat_to_int(v___x_592_);
return v___x_593_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__21(void){
_start:
{
lean_object* v___x_597_; lean_object* v___x_598_; 
v___x_597_ = lean_unsigned_to_nat(9u);
v___x_598_ = lean_nat_to_int(v___x_597_);
return v___x_598_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__27(void){
_start:
{
lean_object* v___x_606_; lean_object* v___x_607_; 
v___x_606_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__0));
v___x_607_ = lean_string_length(v___x_606_);
return v___x_607_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__28(void){
_start:
{
lean_object* v___x_608_; lean_object* v___x_609_; 
v___x_608_ = lean_obj_once(&lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__27, &lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__27_once, _init_lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__27);
v___x_609_ = lean_nat_to_int(v___x_608_);
return v___x_609_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instReprFinding_repr___redArg(lean_object* v_x_614_){
_start:
{
lean_object* v_decl_615_; uint8_t v_site_616_; lean_object* v_rule_617_; lean_object* v_head_618_; lean_object* v_term_619_; lean_object* v_guards_620_; lean_object* v_value_621_; lean_object* v_status_622_; lean_object* v_note_623_; lean_object* v___x_624_; lean_object* v___x_625_; lean_object* v___x_626_; lean_object* v___x_627_; lean_object* v___x_628_; lean_object* v___x_629_; uint8_t v___x_630_; lean_object* v___x_631_; lean_object* v___x_632_; lean_object* v___x_633_; lean_object* v___x_634_; lean_object* v___x_635_; lean_object* v___x_636_; lean_object* v___x_637_; lean_object* v___x_638_; lean_object* v___x_639_; lean_object* v___x_640_; lean_object* v___x_641_; lean_object* v___x_642_; lean_object* v___x_643_; lean_object* v___x_644_; lean_object* v___x_645_; lean_object* v___x_646_; lean_object* v___x_647_; lean_object* v___x_648_; lean_object* v___x_649_; lean_object* v___x_650_; lean_object* v___x_651_; lean_object* v___x_652_; lean_object* v___x_653_; lean_object* v___x_654_; lean_object* v___x_655_; lean_object* v___x_656_; lean_object* v___x_657_; lean_object* v___x_658_; lean_object* v___x_659_; lean_object* v___x_660_; lean_object* v___x_661_; lean_object* v___x_662_; lean_object* v___x_663_; lean_object* v___x_664_; lean_object* v___x_665_; lean_object* v___x_666_; lean_object* v___x_667_; lean_object* v___x_668_; lean_object* v___x_669_; lean_object* v___x_670_; lean_object* v___x_671_; lean_object* v___x_672_; lean_object* v___x_673_; lean_object* v___x_674_; lean_object* v___x_675_; lean_object* v___x_676_; lean_object* v___x_677_; lean_object* v___x_678_; lean_object* v___x_679_; lean_object* v___x_680_; lean_object* v___x_681_; lean_object* v___x_682_; lean_object* v___x_683_; lean_object* v___x_684_; lean_object* v___x_685_; lean_object* v___x_686_; lean_object* v___x_687_; lean_object* v___x_688_; lean_object* v___x_689_; lean_object* v___x_690_; lean_object* v___x_691_; lean_object* v___x_692_; lean_object* v___x_693_; lean_object* v___x_694_; lean_object* v___x_695_; lean_object* v___x_696_; lean_object* v___x_697_; lean_object* v___x_698_; lean_object* v___x_699_; lean_object* v___x_700_; lean_object* v___x_701_; lean_object* v___x_702_; lean_object* v___x_703_; lean_object* v___x_704_; lean_object* v___x_705_; lean_object* v___x_706_; lean_object* v___x_707_; lean_object* v___x_708_; lean_object* v___x_709_; lean_object* v___x_710_; lean_object* v___x_711_; lean_object* v___x_712_; lean_object* v___x_713_; lean_object* v___x_714_; lean_object* v___x_715_; lean_object* v___x_716_; lean_object* v___x_717_; lean_object* v___x_718_; 
v_decl_615_ = lean_ctor_get(v_x_614_, 0);
lean_inc(v_decl_615_);
v_site_616_ = lean_ctor_get_uint8(v_x_614_, sizeof(void*)*8);
v_rule_617_ = lean_ctor_get(v_x_614_, 1);
lean_inc(v_rule_617_);
v_head_618_ = lean_ctor_get(v_x_614_, 2);
lean_inc(v_head_618_);
v_term_619_ = lean_ctor_get(v_x_614_, 3);
lean_inc_ref(v_term_619_);
v_guards_620_ = lean_ctor_get(v_x_614_, 4);
lean_inc_ref(v_guards_620_);
v_value_621_ = lean_ctor_get(v_x_614_, 5);
lean_inc_ref(v_value_621_);
v_status_622_ = lean_ctor_get(v_x_614_, 6);
lean_inc(v_status_622_);
v_note_623_ = lean_ctor_get(v_x_614_, 7);
lean_inc_ref(v_note_623_);
lean_dec_ref(v_x_614_);
v___x_624_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__5));
v___x_625_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__6));
v___x_626_ = lean_obj_once(&lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__7, &lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__7_once, _init_lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__7);
v___x_627_ = lean_unsigned_to_nat(0u);
v___x_628_ = l_Lean_Name_reprPrec(v_decl_615_, v___x_627_);
v___x_629_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_629_, 0, v___x_626_);
lean_ctor_set(v___x_629_, 1, v___x_628_);
v___x_630_ = 0;
v___x_631_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_631_, 0, v___x_629_);
lean_ctor_set_uint8(v___x_631_, sizeof(void*)*1, v___x_630_);
v___x_632_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_632_, 0, v___x_625_);
lean_ctor_set(v___x_632_, 1, v___x_631_);
v___x_633_ = ((lean_object*)(lp_JunkValues_Array_repr___at___00JunkValues_instReprFinding_repr_spec__0___closed__2));
v___x_634_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_634_, 0, v___x_632_);
lean_ctor_set(v___x_634_, 1, v___x_633_);
v___x_635_ = lean_box(1);
v___x_636_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_636_, 0, v___x_634_);
lean_ctor_set(v___x_636_, 1, v___x_635_);
v___x_637_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__9));
v___x_638_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_638_, 0, v___x_636_);
lean_ctor_set(v___x_638_, 1, v___x_637_);
v___x_639_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_639_, 0, v___x_638_);
lean_ctor_set(v___x_639_, 1, v___x_624_);
v___x_640_ = lp_JunkValues_JunkValues_instReprSite_repr(v_site_616_, v___x_627_);
v___x_641_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_641_, 0, v___x_626_);
lean_ctor_set(v___x_641_, 1, v___x_640_);
v___x_642_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_642_, 0, v___x_641_);
lean_ctor_set_uint8(v___x_642_, sizeof(void*)*1, v___x_630_);
v___x_643_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_643_, 0, v___x_639_);
lean_ctor_set(v___x_643_, 1, v___x_642_);
v___x_644_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_644_, 0, v___x_643_);
lean_ctor_set(v___x_644_, 1, v___x_633_);
v___x_645_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_645_, 0, v___x_644_);
lean_ctor_set(v___x_645_, 1, v___x_635_);
v___x_646_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__11));
v___x_647_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_647_, 0, v___x_645_);
lean_ctor_set(v___x_647_, 1, v___x_646_);
v___x_648_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_648_, 0, v___x_647_);
lean_ctor_set(v___x_648_, 1, v___x_624_);
v___x_649_ = l_Lean_Name_reprPrec(v_rule_617_, v___x_627_);
v___x_650_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_650_, 0, v___x_626_);
lean_ctor_set(v___x_650_, 1, v___x_649_);
v___x_651_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_651_, 0, v___x_650_);
lean_ctor_set_uint8(v___x_651_, sizeof(void*)*1, v___x_630_);
v___x_652_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_652_, 0, v___x_648_);
lean_ctor_set(v___x_652_, 1, v___x_651_);
v___x_653_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_653_, 0, v___x_652_);
lean_ctor_set(v___x_653_, 1, v___x_633_);
v___x_654_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_654_, 0, v___x_653_);
lean_ctor_set(v___x_654_, 1, v___x_635_);
v___x_655_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__13));
v___x_656_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_656_, 0, v___x_654_);
lean_ctor_set(v___x_656_, 1, v___x_655_);
v___x_657_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_657_, 0, v___x_656_);
lean_ctor_set(v___x_657_, 1, v___x_624_);
v___x_658_ = l_Lean_Name_reprPrec(v_head_618_, v___x_627_);
v___x_659_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_659_, 0, v___x_626_);
lean_ctor_set(v___x_659_, 1, v___x_658_);
v___x_660_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_660_, 0, v___x_659_);
lean_ctor_set_uint8(v___x_660_, sizeof(void*)*1, v___x_630_);
v___x_661_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_661_, 0, v___x_657_);
lean_ctor_set(v___x_661_, 1, v___x_660_);
v___x_662_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_662_, 0, v___x_661_);
lean_ctor_set(v___x_662_, 1, v___x_633_);
v___x_663_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_663_, 0, v___x_662_);
lean_ctor_set(v___x_663_, 1, v___x_635_);
v___x_664_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__15));
v___x_665_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_665_, 0, v___x_663_);
lean_ctor_set(v___x_665_, 1, v___x_664_);
v___x_666_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_666_, 0, v___x_665_);
lean_ctor_set(v___x_666_, 1, v___x_624_);
v___x_667_ = l_String_quote(v_term_619_);
v___x_668_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_668_, 0, v___x_667_);
v___x_669_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_669_, 0, v___x_626_);
lean_ctor_set(v___x_669_, 1, v___x_668_);
v___x_670_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_670_, 0, v___x_669_);
lean_ctor_set_uint8(v___x_670_, sizeof(void*)*1, v___x_630_);
v___x_671_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_671_, 0, v___x_666_);
lean_ctor_set(v___x_671_, 1, v___x_670_);
v___x_672_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_672_, 0, v___x_671_);
lean_ctor_set(v___x_672_, 1, v___x_633_);
v___x_673_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_673_, 0, v___x_672_);
lean_ctor_set(v___x_673_, 1, v___x_635_);
v___x_674_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__17));
v___x_675_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_675_, 0, v___x_673_);
lean_ctor_set(v___x_675_, 1, v___x_674_);
v___x_676_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_676_, 0, v___x_675_);
lean_ctor_set(v___x_676_, 1, v___x_624_);
v___x_677_ = lean_obj_once(&lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__18, &lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__18_once, _init_lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__18);
v___x_678_ = lp_JunkValues_Array_repr___at___00JunkValues_instReprFinding_repr_spec__0(v_guards_620_);
v___x_679_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_679_, 0, v___x_677_);
lean_ctor_set(v___x_679_, 1, v___x_678_);
v___x_680_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_680_, 0, v___x_679_);
lean_ctor_set_uint8(v___x_680_, sizeof(void*)*1, v___x_630_);
v___x_681_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_681_, 0, v___x_676_);
lean_ctor_set(v___x_681_, 1, v___x_680_);
v___x_682_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_682_, 0, v___x_681_);
lean_ctor_set(v___x_682_, 1, v___x_633_);
v___x_683_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_683_, 0, v___x_682_);
lean_ctor_set(v___x_683_, 1, v___x_635_);
v___x_684_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__20));
v___x_685_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_685_, 0, v___x_683_);
lean_ctor_set(v___x_685_, 1, v___x_684_);
v___x_686_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_686_, 0, v___x_685_);
lean_ctor_set(v___x_686_, 1, v___x_624_);
v___x_687_ = lean_obj_once(&lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__21, &lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__21_once, _init_lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__21);
v___x_688_ = l_String_quote(v_value_621_);
v___x_689_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_689_, 0, v___x_688_);
v___x_690_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_690_, 0, v___x_687_);
lean_ctor_set(v___x_690_, 1, v___x_689_);
v___x_691_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_691_, 0, v___x_690_);
lean_ctor_set_uint8(v___x_691_, sizeof(void*)*1, v___x_630_);
v___x_692_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_692_, 0, v___x_686_);
lean_ctor_set(v___x_692_, 1, v___x_691_);
v___x_693_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_693_, 0, v___x_692_);
lean_ctor_set(v___x_693_, 1, v___x_633_);
v___x_694_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_694_, 0, v___x_693_);
lean_ctor_set(v___x_694_, 1, v___x_635_);
v___x_695_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__23));
v___x_696_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_696_, 0, v___x_694_);
lean_ctor_set(v___x_696_, 1, v___x_695_);
v___x_697_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_697_, 0, v___x_696_);
lean_ctor_set(v___x_697_, 1, v___x_624_);
v___x_698_ = lp_JunkValues_JunkValues_instReprStatus_repr(v_status_622_, v___x_627_);
v___x_699_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_699_, 0, v___x_677_);
lean_ctor_set(v___x_699_, 1, v___x_698_);
v___x_700_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_700_, 0, v___x_699_);
lean_ctor_set_uint8(v___x_700_, sizeof(void*)*1, v___x_630_);
v___x_701_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_701_, 0, v___x_697_);
lean_ctor_set(v___x_701_, 1, v___x_700_);
v___x_702_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_702_, 0, v___x_701_);
lean_ctor_set(v___x_702_, 1, v___x_633_);
v___x_703_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_703_, 0, v___x_702_);
lean_ctor_set(v___x_703_, 1, v___x_635_);
v___x_704_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__25));
v___x_705_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_705_, 0, v___x_703_);
lean_ctor_set(v___x_705_, 1, v___x_704_);
v___x_706_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_706_, 0, v___x_705_);
lean_ctor_set(v___x_706_, 1, v___x_624_);
v___x_707_ = l_String_quote(v_note_623_);
v___x_708_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_708_, 0, v___x_707_);
v___x_709_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_709_, 0, v___x_626_);
lean_ctor_set(v___x_709_, 1, v___x_708_);
v___x_710_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_710_, 0, v___x_709_);
lean_ctor_set_uint8(v___x_710_, sizeof(void*)*1, v___x_630_);
v___x_711_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_711_, 0, v___x_706_);
lean_ctor_set(v___x_711_, 1, v___x_710_);
v___x_712_ = lean_obj_once(&lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__28, &lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__28_once, _init_lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__28);
v___x_713_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__29));
v___x_714_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_714_, 0, v___x_713_);
lean_ctor_set(v___x_714_, 1, v___x_711_);
v___x_715_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__30));
v___x_716_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_716_, 0, v___x_714_);
lean_ctor_set(v___x_716_, 1, v___x_715_);
v___x_717_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_717_, 0, v___x_712_);
lean_ctor_set(v___x_717_, 1, v___x_716_);
v___x_718_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_718_, 0, v___x_717_);
lean_ctor_set_uint8(v___x_718_, sizeof(void*)*1, v___x_630_);
return v___x_718_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instReprFinding_repr(lean_object* v_x_719_, lean_object* v_prec_720_){
_start:
{
lean_object* v___x_721_; 
v___x_721_ = lp_JunkValues_JunkValues_instReprFinding_repr___redArg(v_x_719_);
return v___x_721_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instReprFinding_repr___boxed(lean_object* v_x_722_, lean_object* v_prec_723_){
_start:
{
lean_object* v_res_724_; 
v_res_724_ = lp_JunkValues_JunkValues_instReprFinding_repr(v_x_722_, v_prec_723_);
lean_dec(v_prec_723_);
return v_res_724_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00JunkValues_instToJsonFinding_toJson_spec__1(lean_object* v_a_737_, lean_object* v_a_738_){
_start:
{
if (lean_obj_tag(v_a_737_) == 0)
{
lean_object* v___x_739_; 
v___x_739_ = lean_array_to_list(v_a_738_);
return v___x_739_;
}
else
{
lean_object* v_head_740_; lean_object* v_tail_741_; lean_object* v___x_742_; 
v_head_740_ = lean_ctor_get(v_a_737_, 0);
lean_inc(v_head_740_);
v_tail_741_ = lean_ctor_get(v_a_737_, 1);
lean_inc(v_tail_741_);
lean_dec_ref_known(v_a_737_, 2);
v___x_742_ = l_List_foldl___at___00Array_appendList_spec__0___redArg(v_a_738_, v_head_740_);
v_a_737_ = v_tail_741_;
v_a_738_ = v___x_742_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00JunkValues_instToJsonFinding_toJson_spec__0_spec__0(size_t v_sz_744_, size_t v_i_745_, lean_object* v_bs_746_){
_start:
{
uint8_t v___x_747_; 
v___x_747_ = lean_usize_dec_lt(v_i_745_, v_sz_744_);
if (v___x_747_ == 0)
{
return v_bs_746_;
}
else
{
lean_object* v_v_748_; lean_object* v___x_749_; lean_object* v_bs_x27_750_; lean_object* v___x_751_; size_t v___x_752_; size_t v___x_753_; lean_object* v___x_754_; 
v_v_748_ = lean_array_uget(v_bs_746_, v_i_745_);
v___x_749_ = lean_unsigned_to_nat(0u);
v_bs_x27_750_ = lean_array_uset(v_bs_746_, v_i_745_, v___x_749_);
v___x_751_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_751_, 0, v_v_748_);
v___x_752_ = ((size_t)1ULL);
v___x_753_ = lean_usize_add(v_i_745_, v___x_752_);
v___x_754_ = lean_array_uset(v_bs_x27_750_, v_i_745_, v___x_751_);
v_i_745_ = v___x_753_;
v_bs_746_ = v___x_754_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00JunkValues_instToJsonFinding_toJson_spec__0_spec__0___boxed(lean_object* v_sz_756_, lean_object* v_i_757_, lean_object* v_bs_758_){
_start:
{
size_t v_sz_boxed_759_; size_t v_i_boxed_760_; lean_object* v_res_761_; 
v_sz_boxed_759_ = lean_unbox_usize(v_sz_756_);
lean_dec(v_sz_756_);
v_i_boxed_760_ = lean_unbox_usize(v_i_757_);
lean_dec(v_i_757_);
v_res_761_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00JunkValues_instToJsonFinding_toJson_spec__0_spec__0(v_sz_boxed_759_, v_i_boxed_760_, v_bs_758_);
return v_res_761_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Array_toJson___at___00JunkValues_instToJsonFinding_toJson_spec__0(lean_object* v_a_762_){
_start:
{
size_t v_sz_763_; size_t v___x_764_; lean_object* v___x_765_; lean_object* v___x_766_; 
v_sz_763_ = lean_array_size(v_a_762_);
v___x_764_ = ((size_t)0ULL);
v___x_765_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00JunkValues_instToJsonFinding_toJson_spec__0_spec__0(v_sz_763_, v___x_764_, v_a_762_);
v___x_766_ = lean_alloc_ctor(4, 1, 0);
lean_ctor_set(v___x_766_, 0, v___x_765_);
return v___x_766_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instToJsonFinding_toJson(lean_object* v_x_769_){
_start:
{
lean_object* v_decl_770_; uint8_t v_site_771_; lean_object* v_rule_772_; lean_object* v_head_773_; lean_object* v_term_774_; lean_object* v_guards_775_; lean_object* v_value_776_; lean_object* v_status_777_; lean_object* v_note_778_; lean_object* v___x_779_; uint8_t v___x_780_; lean_object* v___x_781_; lean_object* v___x_782_; lean_object* v___x_783_; lean_object* v___x_784_; lean_object* v___x_785_; lean_object* v___x_786_; lean_object* v___x_787_; lean_object* v___x_788_; lean_object* v___x_789_; lean_object* v___x_790_; lean_object* v___x_791_; lean_object* v___x_792_; lean_object* v___x_793_; lean_object* v___x_794_; lean_object* v___x_795_; lean_object* v___x_796_; lean_object* v___x_797_; lean_object* v___x_798_; lean_object* v___x_799_; lean_object* v___x_800_; lean_object* v___x_801_; lean_object* v___x_802_; lean_object* v___x_803_; lean_object* v___x_804_; lean_object* v___x_805_; lean_object* v___x_806_; lean_object* v___x_807_; lean_object* v___x_808_; lean_object* v___x_809_; lean_object* v___x_810_; lean_object* v___x_811_; lean_object* v___x_812_; lean_object* v___x_813_; lean_object* v___x_814_; lean_object* v___x_815_; lean_object* v___x_816_; lean_object* v___x_817_; lean_object* v___x_818_; lean_object* v___x_819_; lean_object* v___x_820_; lean_object* v___x_821_; lean_object* v___x_822_; lean_object* v___x_823_; lean_object* v___x_824_; lean_object* v___x_825_; lean_object* v___x_826_; lean_object* v___x_827_; lean_object* v___x_828_; lean_object* v___x_829_; lean_object* v___x_830_; lean_object* v___x_831_; 
v_decl_770_ = lean_ctor_get(v_x_769_, 0);
lean_inc(v_decl_770_);
v_site_771_ = lean_ctor_get_uint8(v_x_769_, sizeof(void*)*8);
v_rule_772_ = lean_ctor_get(v_x_769_, 1);
lean_inc(v_rule_772_);
v_head_773_ = lean_ctor_get(v_x_769_, 2);
lean_inc(v_head_773_);
v_term_774_ = lean_ctor_get(v_x_769_, 3);
lean_inc_ref(v_term_774_);
v_guards_775_ = lean_ctor_get(v_x_769_, 4);
lean_inc_ref(v_guards_775_);
v_value_776_ = lean_ctor_get(v_x_769_, 5);
lean_inc_ref(v_value_776_);
v_status_777_ = lean_ctor_get(v_x_769_, 6);
lean_inc(v_status_777_);
v_note_778_ = lean_ctor_get(v_x_769_, 7);
lean_inc_ref(v_note_778_);
lean_dec_ref(v_x_769_);
v___x_779_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__1));
v___x_780_ = 1;
v___x_781_ = l_Lean_Name_toStringWithToken___at___00Lean_Name_toString_spec__0(v_decl_770_, v___x_780_);
v___x_782_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_782_, 0, v___x_781_);
v___x_783_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_783_, 0, v___x_779_);
lean_ctor_set(v___x_783_, 1, v___x_782_);
v___x_784_ = lean_box(0);
v___x_785_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_785_, 0, v___x_783_);
lean_ctor_set(v___x_785_, 1, v___x_784_);
v___x_786_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__8));
v___x_787_ = lp_JunkValues_JunkValues_instToJsonSite_toJson(v_site_771_);
v___x_788_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_788_, 0, v___x_786_);
lean_ctor_set(v___x_788_, 1, v___x_787_);
v___x_789_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_789_, 0, v___x_788_);
lean_ctor_set(v___x_789_, 1, v___x_784_);
v___x_790_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__10));
v___x_791_ = l_Lean_Name_toStringWithToken___at___00Lean_Name_toString_spec__0(v_rule_772_, v___x_780_);
v___x_792_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_792_, 0, v___x_791_);
v___x_793_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_793_, 0, v___x_790_);
lean_ctor_set(v___x_793_, 1, v___x_792_);
v___x_794_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_794_, 0, v___x_793_);
lean_ctor_set(v___x_794_, 1, v___x_784_);
v___x_795_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__12));
v___x_796_ = l_Lean_Name_toStringWithToken___at___00Lean_Name_toString_spec__0(v_head_773_, v___x_780_);
v___x_797_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_797_, 0, v___x_796_);
v___x_798_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_798_, 0, v___x_795_);
lean_ctor_set(v___x_798_, 1, v___x_797_);
v___x_799_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_799_, 0, v___x_798_);
lean_ctor_set(v___x_799_, 1, v___x_784_);
v___x_800_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__14));
v___x_801_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_801_, 0, v_term_774_);
v___x_802_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_802_, 0, v___x_800_);
lean_ctor_set(v___x_802_, 1, v___x_801_);
v___x_803_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_803_, 0, v___x_802_);
lean_ctor_set(v___x_803_, 1, v___x_784_);
v___x_804_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__16));
v___x_805_ = lp_JunkValues_Lean_Array_toJson___at___00JunkValues_instToJsonFinding_toJson_spec__0(v_guards_775_);
v___x_806_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_806_, 0, v___x_804_);
lean_ctor_set(v___x_806_, 1, v___x_805_);
v___x_807_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_807_, 0, v___x_806_);
lean_ctor_set(v___x_807_, 1, v___x_784_);
v___x_808_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__19));
v___x_809_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_809_, 0, v_value_776_);
v___x_810_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_810_, 0, v___x_808_);
lean_ctor_set(v___x_810_, 1, v___x_809_);
v___x_811_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_811_, 0, v___x_810_);
lean_ctor_set(v___x_811_, 1, v___x_784_);
v___x_812_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__22));
v___x_813_ = lp_JunkValues_JunkValues_instToJsonStatus_toJson(v_status_777_);
v___x_814_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_814_, 0, v___x_812_);
lean_ctor_set(v___x_814_, 1, v___x_813_);
v___x_815_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_815_, 0, v___x_814_);
lean_ctor_set(v___x_815_, 1, v___x_784_);
v___x_816_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__24));
v___x_817_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_817_, 0, v_note_778_);
v___x_818_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_818_, 0, v___x_816_);
lean_ctor_set(v___x_818_, 1, v___x_817_);
v___x_819_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_819_, 0, v___x_818_);
lean_ctor_set(v___x_819_, 1, v___x_784_);
v___x_820_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_820_, 0, v___x_819_);
lean_ctor_set(v___x_820_, 1, v___x_784_);
v___x_821_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_821_, 0, v___x_815_);
lean_ctor_set(v___x_821_, 1, v___x_820_);
v___x_822_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_822_, 0, v___x_811_);
lean_ctor_set(v___x_822_, 1, v___x_821_);
v___x_823_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_823_, 0, v___x_807_);
lean_ctor_set(v___x_823_, 1, v___x_822_);
v___x_824_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_824_, 0, v___x_803_);
lean_ctor_set(v___x_824_, 1, v___x_823_);
v___x_825_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_825_, 0, v___x_799_);
lean_ctor_set(v___x_825_, 1, v___x_824_);
v___x_826_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_826_, 0, v___x_794_);
lean_ctor_set(v___x_826_, 1, v___x_825_);
v___x_827_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_827_, 0, v___x_789_);
lean_ctor_set(v___x_827_, 1, v___x_826_);
v___x_828_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_828_, 0, v___x_785_);
lean_ctor_set(v___x_828_, 1, v___x_827_);
v___x_829_ = ((lean_object*)(lp_JunkValues_JunkValues_instToJsonFinding_toJson___closed__0));
v___x_830_ = lp_JunkValues___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00JunkValues_instToJsonFinding_toJson_spec__1(v___x_828_, v___x_829_);
v___x_831_ = l_Lean_Json_mkObj(v___x_830_);
lean_dec(v___x_830_);
return v___x_831_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Json_getObjValAs_x3f___at___00JunkValues_instFromJsonFinding_fromJson_spec__0(lean_object* v_j_834_, lean_object* v_k_835_){
_start:
{
lean_object* v___x_836_; lean_object* v___x_837_; 
v___x_836_ = l_Lean_Json_getObjValD(v_j_834_, v_k_835_);
v___x_837_ = l_Lean_Name_fromJson_x3f(v___x_836_);
return v___x_837_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Json_getObjValAs_x3f___at___00JunkValues_instFromJsonFinding_fromJson_spec__0___boxed(lean_object* v_j_838_, lean_object* v_k_839_){
_start:
{
lean_object* v_res_840_; 
v_res_840_ = lp_JunkValues_Lean_Json_getObjValAs_x3f___at___00JunkValues_instFromJsonFinding_fromJson_spec__0(v_j_838_, v_k_839_);
lean_dec_ref(v_k_839_);
return v_res_840_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Json_getObjValAs_x3f___at___00JunkValues_instFromJsonFinding_fromJson_spec__1(lean_object* v_j_841_, lean_object* v_k_842_){
_start:
{
lean_object* v___x_843_; lean_object* v___x_844_; 
v___x_843_ = l_Lean_Json_getObjValD(v_j_841_, v_k_842_);
v___x_844_ = lp_JunkValues_JunkValues_instFromJsonSite_fromJson(v___x_843_);
return v___x_844_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Json_getObjValAs_x3f___at___00JunkValues_instFromJsonFinding_fromJson_spec__1___boxed(lean_object* v_j_845_, lean_object* v_k_846_){
_start:
{
lean_object* v_res_847_; 
v_res_847_ = lp_JunkValues_Lean_Json_getObjValAs_x3f___at___00JunkValues_instFromJsonFinding_fromJson_spec__1(v_j_845_, v_k_846_);
lean_dec_ref(v_k_846_);
return v_res_847_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Json_getObjValAs_x3f___at___00JunkValues_instFromJsonFinding_fromJson_spec__2(lean_object* v_j_848_, lean_object* v_k_849_){
_start:
{
lean_object* v___x_850_; lean_object* v___x_851_; 
v___x_850_ = l_Lean_Json_getObjValD(v_j_848_, v_k_849_);
v___x_851_ = l_Lean_Json_getStr_x3f(v___x_850_);
return v___x_851_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Json_getObjValAs_x3f___at___00JunkValues_instFromJsonFinding_fromJson_spec__2___boxed(lean_object* v_j_852_, lean_object* v_k_853_){
_start:
{
lean_object* v_res_854_; 
v_res_854_ = lp_JunkValues_Lean_Json_getObjValAs_x3f___at___00JunkValues_instFromJsonFinding_fromJson_spec__2(v_j_852_, v_k_853_);
lean_dec_ref(v_k_853_);
return v_res_854_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Json_getObjValAs_x3f___at___00JunkValues_instFromJsonFinding_fromJson_spec__4(lean_object* v_j_855_, lean_object* v_k_856_){
_start:
{
lean_object* v___x_857_; lean_object* v___x_858_; 
v___x_857_ = l_Lean_Json_getObjValD(v_j_855_, v_k_856_);
v___x_858_ = lp_JunkValues_JunkValues_instFromJsonStatus_fromJson(v___x_857_);
return v___x_858_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Json_getObjValAs_x3f___at___00JunkValues_instFromJsonFinding_fromJson_spec__4___boxed(lean_object* v_j_859_, lean_object* v_k_860_){
_start:
{
lean_object* v_res_861_; 
v_res_861_ = lp_JunkValues_Lean_Json_getObjValAs_x3f___at___00JunkValues_instFromJsonFinding_fromJson_spec__4(v_j_859_, v_k_860_);
lean_dec_ref(v_k_860_);
return v_res_861_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00JunkValues_instFromJsonFinding_fromJson_spec__3_spec__3_spec__5(size_t v_sz_862_, size_t v_i_863_, lean_object* v_bs_864_){
_start:
{
uint8_t v___x_865_; 
v___x_865_ = lean_usize_dec_lt(v_i_863_, v_sz_862_);
if (v___x_865_ == 0)
{
lean_object* v___x_866_; 
v___x_866_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_866_, 0, v_bs_864_);
return v___x_866_;
}
else
{
lean_object* v_v_867_; lean_object* v___x_868_; 
v_v_867_ = lean_array_uget_borrowed(v_bs_864_, v_i_863_);
lean_inc(v_v_867_);
v___x_868_ = l_Lean_Json_getStr_x3f(v_v_867_);
if (lean_obj_tag(v___x_868_) == 0)
{
lean_object* v_a_869_; lean_object* v___x_871_; uint8_t v_isShared_872_; uint8_t v_isSharedCheck_876_; 
lean_dec_ref(v_bs_864_);
v_a_869_ = lean_ctor_get(v___x_868_, 0);
v_isSharedCheck_876_ = !lean_is_exclusive(v___x_868_);
if (v_isSharedCheck_876_ == 0)
{
v___x_871_ = v___x_868_;
v_isShared_872_ = v_isSharedCheck_876_;
goto v_resetjp_870_;
}
else
{
lean_inc(v_a_869_);
lean_dec(v___x_868_);
v___x_871_ = lean_box(0);
v_isShared_872_ = v_isSharedCheck_876_;
goto v_resetjp_870_;
}
v_resetjp_870_:
{
lean_object* v___x_874_; 
if (v_isShared_872_ == 0)
{
v___x_874_ = v___x_871_;
goto v_reusejp_873_;
}
else
{
lean_object* v_reuseFailAlloc_875_; 
v_reuseFailAlloc_875_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_875_, 0, v_a_869_);
v___x_874_ = v_reuseFailAlloc_875_;
goto v_reusejp_873_;
}
v_reusejp_873_:
{
return v___x_874_;
}
}
}
else
{
lean_object* v_a_877_; lean_object* v___x_878_; lean_object* v_bs_x27_879_; size_t v___x_880_; size_t v___x_881_; lean_object* v___x_882_; 
v_a_877_ = lean_ctor_get(v___x_868_, 0);
lean_inc(v_a_877_);
lean_dec_ref_known(v___x_868_, 1);
v___x_878_ = lean_unsigned_to_nat(0u);
v_bs_x27_879_ = lean_array_uset(v_bs_864_, v_i_863_, v___x_878_);
v___x_880_ = ((size_t)1ULL);
v___x_881_ = lean_usize_add(v_i_863_, v___x_880_);
v___x_882_ = lean_array_uset(v_bs_x27_879_, v_i_863_, v_a_877_);
v_i_863_ = v___x_881_;
v_bs_864_ = v___x_882_;
goto _start;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00JunkValues_instFromJsonFinding_fromJson_spec__3_spec__3_spec__5___boxed(lean_object* v_sz_884_, lean_object* v_i_885_, lean_object* v_bs_886_){
_start:
{
size_t v_sz_boxed_887_; size_t v_i_boxed_888_; lean_object* v_res_889_; 
v_sz_boxed_887_ = lean_unbox_usize(v_sz_884_);
lean_dec(v_sz_884_);
v_i_boxed_888_ = lean_unbox_usize(v_i_885_);
lean_dec(v_i_885_);
v_res_889_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00JunkValues_instFromJsonFinding_fromJson_spec__3_spec__3_spec__5(v_sz_boxed_887_, v_i_boxed_888_, v_bs_886_);
return v_res_889_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Array_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00JunkValues_instFromJsonFinding_fromJson_spec__3_spec__3(lean_object* v_x_892_){
_start:
{
if (lean_obj_tag(v_x_892_) == 4)
{
lean_object* v_elems_893_; size_t v_sz_894_; size_t v___x_895_; lean_object* v___x_896_; 
v_elems_893_ = lean_ctor_get(v_x_892_, 0);
lean_inc_ref(v_elems_893_);
lean_dec_ref_known(v_x_892_, 1);
v_sz_894_ = lean_array_size(v_elems_893_);
v___x_895_ = ((size_t)0ULL);
v___x_896_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00JunkValues_instFromJsonFinding_fromJson_spec__3_spec__3_spec__5(v_sz_894_, v___x_895_, v_elems_893_);
return v___x_896_;
}
else
{
lean_object* v___x_897_; lean_object* v___x_898_; lean_object* v___x_899_; lean_object* v___x_900_; lean_object* v___x_901_; lean_object* v___x_902_; lean_object* v___x_903_; 
v___x_897_ = ((lean_object*)(lp_JunkValues_Lean_Array_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00JunkValues_instFromJsonFinding_fromJson_spec__3_spec__3___closed__0));
v___x_898_ = lean_unsigned_to_nat(80u);
v___x_899_ = l_Lean_Json_pretty(v_x_892_, v___x_898_);
v___x_900_ = lean_string_append(v___x_897_, v___x_899_);
lean_dec_ref(v___x_899_);
v___x_901_ = ((lean_object*)(lp_JunkValues_Lean_Array_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00JunkValues_instFromJsonFinding_fromJson_spec__3_spec__3___closed__1));
v___x_902_ = lean_string_append(v___x_900_, v___x_901_);
v___x_903_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_903_, 0, v___x_902_);
return v___x_903_;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Json_getObjValAs_x3f___at___00JunkValues_instFromJsonFinding_fromJson_spec__3(lean_object* v_j_904_, lean_object* v_k_905_){
_start:
{
lean_object* v___x_906_; lean_object* v___x_907_; 
v___x_906_ = l_Lean_Json_getObjValD(v_j_904_, v_k_905_);
v___x_907_ = lp_JunkValues_Lean_Array_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00JunkValues_instFromJsonFinding_fromJson_spec__3_spec__3(v___x_906_);
return v___x_907_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Json_getObjValAs_x3f___at___00JunkValues_instFromJsonFinding_fromJson_spec__3___boxed(lean_object* v_j_908_, lean_object* v_k_909_){
_start:
{
lean_object* v_res_910_; 
v_res_910_ = lp_JunkValues_Lean_Json_getObjValAs_x3f___at___00JunkValues_instFromJsonFinding_fromJson_spec__3(v_j_908_, v_k_909_);
lean_dec_ref(v_k_909_);
return v_res_910_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__3(void){
_start:
{
uint8_t v___x_916_; lean_object* v___x_917_; lean_object* v___x_918_; 
v___x_916_ = 1;
v___x_917_ = ((lean_object*)(lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__2));
v___x_918_ = l_Lean_Name_toStringWithToken___at___00Lean_Name_toString_spec__0(v___x_917_, v___x_916_);
return v___x_918_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__5(void){
_start:
{
lean_object* v___x_920_; lean_object* v___x_921_; lean_object* v___x_922_; 
v___x_920_ = ((lean_object*)(lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__4));
v___x_921_ = lean_obj_once(&lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__3, &lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__3_once, _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__3);
v___x_922_ = lean_string_append(v___x_921_, v___x_920_);
return v___x_922_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__7(void){
_start:
{
uint8_t v___x_925_; lean_object* v___x_926_; lean_object* v___x_927_; 
v___x_925_ = 1;
v___x_926_ = ((lean_object*)(lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__6));
v___x_927_ = l_Lean_Name_toStringWithToken___at___00Lean_Name_toString_spec__0(v___x_926_, v___x_925_);
return v___x_927_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__8(void){
_start:
{
lean_object* v___x_928_; lean_object* v___x_929_; lean_object* v___x_930_; 
v___x_928_ = lean_obj_once(&lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__7, &lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__7_once, _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__7);
v___x_929_ = lean_obj_once(&lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__5, &lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__5_once, _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__5);
v___x_930_ = lean_string_append(v___x_929_, v___x_928_);
return v___x_930_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__10(void){
_start:
{
lean_object* v___x_932_; lean_object* v___x_933_; lean_object* v___x_934_; 
v___x_932_ = ((lean_object*)(lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__9));
v___x_933_ = lean_obj_once(&lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__8, &lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__8_once, _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__8);
v___x_934_ = lean_string_append(v___x_933_, v___x_932_);
return v___x_934_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__12(void){
_start:
{
uint8_t v___x_937_; lean_object* v___x_938_; lean_object* v___x_939_; 
v___x_937_ = 1;
v___x_938_ = ((lean_object*)(lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__11));
v___x_939_ = l_Lean_Name_toStringWithToken___at___00Lean_Name_toString_spec__0(v___x_938_, v___x_937_);
return v___x_939_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__13(void){
_start:
{
lean_object* v___x_940_; lean_object* v___x_941_; lean_object* v___x_942_; 
v___x_940_ = lean_obj_once(&lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__12, &lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__12_once, _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__12);
v___x_941_ = lean_obj_once(&lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__5, &lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__5_once, _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__5);
v___x_942_ = lean_string_append(v___x_941_, v___x_940_);
return v___x_942_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__14(void){
_start:
{
lean_object* v___x_943_; lean_object* v___x_944_; lean_object* v___x_945_; 
v___x_943_ = ((lean_object*)(lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__9));
v___x_944_ = lean_obj_once(&lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__13, &lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__13_once, _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__13);
v___x_945_ = lean_string_append(v___x_944_, v___x_943_);
return v___x_945_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__16(void){
_start:
{
uint8_t v___x_948_; lean_object* v___x_949_; lean_object* v___x_950_; 
v___x_948_ = 1;
v___x_949_ = ((lean_object*)(lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__15));
v___x_950_ = l_Lean_Name_toStringWithToken___at___00Lean_Name_toString_spec__0(v___x_949_, v___x_948_);
return v___x_950_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__17(void){
_start:
{
lean_object* v___x_951_; lean_object* v___x_952_; lean_object* v___x_953_; 
v___x_951_ = lean_obj_once(&lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__16, &lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__16_once, _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__16);
v___x_952_ = lean_obj_once(&lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__5, &lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__5_once, _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__5);
v___x_953_ = lean_string_append(v___x_952_, v___x_951_);
return v___x_953_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__18(void){
_start:
{
lean_object* v___x_954_; lean_object* v___x_955_; lean_object* v___x_956_; 
v___x_954_ = ((lean_object*)(lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__9));
v___x_955_ = lean_obj_once(&lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__17, &lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__17_once, _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__17);
v___x_956_ = lean_string_append(v___x_955_, v___x_954_);
return v___x_956_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__20(void){
_start:
{
uint8_t v___x_959_; lean_object* v___x_960_; lean_object* v___x_961_; 
v___x_959_ = 1;
v___x_960_ = ((lean_object*)(lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__19));
v___x_961_ = l_Lean_Name_toStringWithToken___at___00Lean_Name_toString_spec__0(v___x_960_, v___x_959_);
return v___x_961_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__21(void){
_start:
{
lean_object* v___x_962_; lean_object* v___x_963_; lean_object* v___x_964_; 
v___x_962_ = lean_obj_once(&lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__20, &lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__20_once, _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__20);
v___x_963_ = lean_obj_once(&lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__5, &lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__5_once, _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__5);
v___x_964_ = lean_string_append(v___x_963_, v___x_962_);
return v___x_964_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__22(void){
_start:
{
lean_object* v___x_965_; lean_object* v___x_966_; lean_object* v___x_967_; 
v___x_965_ = ((lean_object*)(lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__9));
v___x_966_ = lean_obj_once(&lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__21, &lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__21_once, _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__21);
v___x_967_ = lean_string_append(v___x_966_, v___x_965_);
return v___x_967_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__24(void){
_start:
{
uint8_t v___x_970_; lean_object* v___x_971_; lean_object* v___x_972_; 
v___x_970_ = 1;
v___x_971_ = ((lean_object*)(lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__23));
v___x_972_ = l_Lean_Name_toStringWithToken___at___00Lean_Name_toString_spec__0(v___x_971_, v___x_970_);
return v___x_972_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__25(void){
_start:
{
lean_object* v___x_973_; lean_object* v___x_974_; lean_object* v___x_975_; 
v___x_973_ = lean_obj_once(&lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__24, &lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__24_once, _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__24);
v___x_974_ = lean_obj_once(&lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__5, &lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__5_once, _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__5);
v___x_975_ = lean_string_append(v___x_974_, v___x_973_);
return v___x_975_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__26(void){
_start:
{
lean_object* v___x_976_; lean_object* v___x_977_; lean_object* v___x_978_; 
v___x_976_ = ((lean_object*)(lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__9));
v___x_977_ = lean_obj_once(&lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__25, &lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__25_once, _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__25);
v___x_978_ = lean_string_append(v___x_977_, v___x_976_);
return v___x_978_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__28(void){
_start:
{
uint8_t v___x_981_; lean_object* v___x_982_; lean_object* v___x_983_; 
v___x_981_ = 1;
v___x_982_ = ((lean_object*)(lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__27));
v___x_983_ = l_Lean_Name_toStringWithToken___at___00Lean_Name_toString_spec__0(v___x_982_, v___x_981_);
return v___x_983_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__29(void){
_start:
{
lean_object* v___x_984_; lean_object* v___x_985_; lean_object* v___x_986_; 
v___x_984_ = lean_obj_once(&lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__28, &lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__28_once, _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__28);
v___x_985_ = lean_obj_once(&lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__5, &lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__5_once, _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__5);
v___x_986_ = lean_string_append(v___x_985_, v___x_984_);
return v___x_986_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__30(void){
_start:
{
lean_object* v___x_987_; lean_object* v___x_988_; lean_object* v___x_989_; 
v___x_987_ = ((lean_object*)(lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__9));
v___x_988_ = lean_obj_once(&lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__29, &lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__29_once, _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__29);
v___x_989_ = lean_string_append(v___x_988_, v___x_987_);
return v___x_989_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__32(void){
_start:
{
uint8_t v___x_992_; lean_object* v___x_993_; lean_object* v___x_994_; 
v___x_992_ = 1;
v___x_993_ = ((lean_object*)(lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__31));
v___x_994_ = l_Lean_Name_toStringWithToken___at___00Lean_Name_toString_spec__0(v___x_993_, v___x_992_);
return v___x_994_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__33(void){
_start:
{
lean_object* v___x_995_; lean_object* v___x_996_; lean_object* v___x_997_; 
v___x_995_ = lean_obj_once(&lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__32, &lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__32_once, _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__32);
v___x_996_ = lean_obj_once(&lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__5, &lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__5_once, _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__5);
v___x_997_ = lean_string_append(v___x_996_, v___x_995_);
return v___x_997_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__34(void){
_start:
{
lean_object* v___x_998_; lean_object* v___x_999_; lean_object* v___x_1000_; 
v___x_998_ = ((lean_object*)(lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__9));
v___x_999_ = lean_obj_once(&lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__33, &lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__33_once, _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__33);
v___x_1000_ = lean_string_append(v___x_999_, v___x_998_);
return v___x_1000_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__36(void){
_start:
{
uint8_t v___x_1003_; lean_object* v___x_1004_; lean_object* v___x_1005_; 
v___x_1003_ = 1;
v___x_1004_ = ((lean_object*)(lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__35));
v___x_1005_ = l_Lean_Name_toStringWithToken___at___00Lean_Name_toString_spec__0(v___x_1004_, v___x_1003_);
return v___x_1005_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__37(void){
_start:
{
lean_object* v___x_1006_; lean_object* v___x_1007_; lean_object* v___x_1008_; 
v___x_1006_ = lean_obj_once(&lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__36, &lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__36_once, _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__36);
v___x_1007_ = lean_obj_once(&lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__5, &lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__5_once, _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__5);
v___x_1008_ = lean_string_append(v___x_1007_, v___x_1006_);
return v___x_1008_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__38(void){
_start:
{
lean_object* v___x_1009_; lean_object* v___x_1010_; lean_object* v___x_1011_; 
v___x_1009_ = ((lean_object*)(lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__9));
v___x_1010_ = lean_obj_once(&lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__37, &lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__37_once, _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__37);
v___x_1011_ = lean_string_append(v___x_1010_, v___x_1009_);
return v___x_1011_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__40(void){
_start:
{
uint8_t v___x_1014_; lean_object* v___x_1015_; lean_object* v___x_1016_; 
v___x_1014_ = 1;
v___x_1015_ = ((lean_object*)(lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__39));
v___x_1016_ = l_Lean_Name_toStringWithToken___at___00Lean_Name_toString_spec__0(v___x_1015_, v___x_1014_);
return v___x_1016_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__41(void){
_start:
{
lean_object* v___x_1017_; lean_object* v___x_1018_; lean_object* v___x_1019_; 
v___x_1017_ = lean_obj_once(&lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__40, &lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__40_once, _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__40);
v___x_1018_ = lean_obj_once(&lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__5, &lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__5_once, _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__5);
v___x_1019_ = lean_string_append(v___x_1018_, v___x_1017_);
return v___x_1019_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__42(void){
_start:
{
lean_object* v___x_1020_; lean_object* v___x_1021_; lean_object* v___x_1022_; 
v___x_1020_ = ((lean_object*)(lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__9));
v___x_1021_ = lean_obj_once(&lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__41, &lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__41_once, _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__41);
v___x_1022_ = lean_string_append(v___x_1021_, v___x_1020_);
return v___x_1022_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instFromJsonFinding_fromJson(lean_object* v_json_1023_){
_start:
{
lean_object* v___x_1024_; lean_object* v___x_1025_; 
v___x_1024_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__1));
lean_inc(v_json_1023_);
v___x_1025_ = lp_JunkValues_Lean_Json_getObjValAs_x3f___at___00JunkValues_instFromJsonFinding_fromJson_spec__0(v_json_1023_, v___x_1024_);
if (lean_obj_tag(v___x_1025_) == 0)
{
lean_object* v_a_1026_; lean_object* v___x_1028_; uint8_t v_isShared_1029_; uint8_t v_isSharedCheck_1035_; 
lean_dec(v_json_1023_);
v_a_1026_ = lean_ctor_get(v___x_1025_, 0);
v_isSharedCheck_1035_ = !lean_is_exclusive(v___x_1025_);
if (v_isSharedCheck_1035_ == 0)
{
v___x_1028_ = v___x_1025_;
v_isShared_1029_ = v_isSharedCheck_1035_;
goto v_resetjp_1027_;
}
else
{
lean_inc(v_a_1026_);
lean_dec(v___x_1025_);
v___x_1028_ = lean_box(0);
v_isShared_1029_ = v_isSharedCheck_1035_;
goto v_resetjp_1027_;
}
v_resetjp_1027_:
{
lean_object* v___x_1030_; lean_object* v___x_1031_; lean_object* v___x_1033_; 
v___x_1030_ = lean_obj_once(&lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__10, &lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__10_once, _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__10);
v___x_1031_ = lean_string_append(v___x_1030_, v_a_1026_);
lean_dec(v_a_1026_);
if (v_isShared_1029_ == 0)
{
lean_ctor_set(v___x_1028_, 0, v___x_1031_);
v___x_1033_ = v___x_1028_;
goto v_reusejp_1032_;
}
else
{
lean_object* v_reuseFailAlloc_1034_; 
v_reuseFailAlloc_1034_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1034_, 0, v___x_1031_);
v___x_1033_ = v_reuseFailAlloc_1034_;
goto v_reusejp_1032_;
}
v_reusejp_1032_:
{
return v___x_1033_;
}
}
}
else
{
if (lean_obj_tag(v___x_1025_) == 0)
{
lean_object* v_a_1036_; lean_object* v___x_1038_; uint8_t v_isShared_1039_; uint8_t v_isSharedCheck_1043_; 
lean_dec(v_json_1023_);
v_a_1036_ = lean_ctor_get(v___x_1025_, 0);
v_isSharedCheck_1043_ = !lean_is_exclusive(v___x_1025_);
if (v_isSharedCheck_1043_ == 0)
{
v___x_1038_ = v___x_1025_;
v_isShared_1039_ = v_isSharedCheck_1043_;
goto v_resetjp_1037_;
}
else
{
lean_inc(v_a_1036_);
lean_dec(v___x_1025_);
v___x_1038_ = lean_box(0);
v_isShared_1039_ = v_isSharedCheck_1043_;
goto v_resetjp_1037_;
}
v_resetjp_1037_:
{
lean_object* v___x_1041_; 
if (v_isShared_1039_ == 0)
{
lean_ctor_set_tag(v___x_1038_, 0);
v___x_1041_ = v___x_1038_;
goto v_reusejp_1040_;
}
else
{
lean_object* v_reuseFailAlloc_1042_; 
v_reuseFailAlloc_1042_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1042_, 0, v_a_1036_);
v___x_1041_ = v_reuseFailAlloc_1042_;
goto v_reusejp_1040_;
}
v_reusejp_1040_:
{
return v___x_1041_;
}
}
}
else
{
lean_object* v_a_1044_; lean_object* v___x_1045_; lean_object* v___x_1046_; 
v_a_1044_ = lean_ctor_get(v___x_1025_, 0);
lean_inc(v_a_1044_);
lean_dec_ref_known(v___x_1025_, 1);
v___x_1045_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__8));
lean_inc(v_json_1023_);
v___x_1046_ = lp_JunkValues_Lean_Json_getObjValAs_x3f___at___00JunkValues_instFromJsonFinding_fromJson_spec__1(v_json_1023_, v___x_1045_);
if (lean_obj_tag(v___x_1046_) == 0)
{
lean_object* v_a_1047_; lean_object* v___x_1049_; uint8_t v_isShared_1050_; uint8_t v_isSharedCheck_1056_; 
lean_dec(v_a_1044_);
lean_dec(v_json_1023_);
v_a_1047_ = lean_ctor_get(v___x_1046_, 0);
v_isSharedCheck_1056_ = !lean_is_exclusive(v___x_1046_);
if (v_isSharedCheck_1056_ == 0)
{
v___x_1049_ = v___x_1046_;
v_isShared_1050_ = v_isSharedCheck_1056_;
goto v_resetjp_1048_;
}
else
{
lean_inc(v_a_1047_);
lean_dec(v___x_1046_);
v___x_1049_ = lean_box(0);
v_isShared_1050_ = v_isSharedCheck_1056_;
goto v_resetjp_1048_;
}
v_resetjp_1048_:
{
lean_object* v___x_1051_; lean_object* v___x_1052_; lean_object* v___x_1054_; 
v___x_1051_ = lean_obj_once(&lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__14, &lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__14_once, _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__14);
v___x_1052_ = lean_string_append(v___x_1051_, v_a_1047_);
lean_dec(v_a_1047_);
if (v_isShared_1050_ == 0)
{
lean_ctor_set(v___x_1049_, 0, v___x_1052_);
v___x_1054_ = v___x_1049_;
goto v_reusejp_1053_;
}
else
{
lean_object* v_reuseFailAlloc_1055_; 
v_reuseFailAlloc_1055_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1055_, 0, v___x_1052_);
v___x_1054_ = v_reuseFailAlloc_1055_;
goto v_reusejp_1053_;
}
v_reusejp_1053_:
{
return v___x_1054_;
}
}
}
else
{
if (lean_obj_tag(v___x_1046_) == 0)
{
lean_object* v_a_1057_; lean_object* v___x_1059_; uint8_t v_isShared_1060_; uint8_t v_isSharedCheck_1064_; 
lean_dec(v_a_1044_);
lean_dec(v_json_1023_);
v_a_1057_ = lean_ctor_get(v___x_1046_, 0);
v_isSharedCheck_1064_ = !lean_is_exclusive(v___x_1046_);
if (v_isSharedCheck_1064_ == 0)
{
v___x_1059_ = v___x_1046_;
v_isShared_1060_ = v_isSharedCheck_1064_;
goto v_resetjp_1058_;
}
else
{
lean_inc(v_a_1057_);
lean_dec(v___x_1046_);
v___x_1059_ = lean_box(0);
v_isShared_1060_ = v_isSharedCheck_1064_;
goto v_resetjp_1058_;
}
v_resetjp_1058_:
{
lean_object* v___x_1062_; 
if (v_isShared_1060_ == 0)
{
lean_ctor_set_tag(v___x_1059_, 0);
v___x_1062_ = v___x_1059_;
goto v_reusejp_1061_;
}
else
{
lean_object* v_reuseFailAlloc_1063_; 
v_reuseFailAlloc_1063_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1063_, 0, v_a_1057_);
v___x_1062_ = v_reuseFailAlloc_1063_;
goto v_reusejp_1061_;
}
v_reusejp_1061_:
{
return v___x_1062_;
}
}
}
else
{
lean_object* v_a_1065_; lean_object* v___x_1066_; lean_object* v___x_1067_; 
v_a_1065_ = lean_ctor_get(v___x_1046_, 0);
lean_inc(v_a_1065_);
lean_dec_ref_known(v___x_1046_, 1);
v___x_1066_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__10));
lean_inc(v_json_1023_);
v___x_1067_ = lp_JunkValues_Lean_Json_getObjValAs_x3f___at___00JunkValues_instFromJsonFinding_fromJson_spec__0(v_json_1023_, v___x_1066_);
if (lean_obj_tag(v___x_1067_) == 0)
{
lean_object* v_a_1068_; lean_object* v___x_1070_; uint8_t v_isShared_1071_; uint8_t v_isSharedCheck_1077_; 
lean_dec(v_a_1065_);
lean_dec(v_a_1044_);
lean_dec(v_json_1023_);
v_a_1068_ = lean_ctor_get(v___x_1067_, 0);
v_isSharedCheck_1077_ = !lean_is_exclusive(v___x_1067_);
if (v_isSharedCheck_1077_ == 0)
{
v___x_1070_ = v___x_1067_;
v_isShared_1071_ = v_isSharedCheck_1077_;
goto v_resetjp_1069_;
}
else
{
lean_inc(v_a_1068_);
lean_dec(v___x_1067_);
v___x_1070_ = lean_box(0);
v_isShared_1071_ = v_isSharedCheck_1077_;
goto v_resetjp_1069_;
}
v_resetjp_1069_:
{
lean_object* v___x_1072_; lean_object* v___x_1073_; lean_object* v___x_1075_; 
v___x_1072_ = lean_obj_once(&lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__18, &lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__18_once, _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__18);
v___x_1073_ = lean_string_append(v___x_1072_, v_a_1068_);
lean_dec(v_a_1068_);
if (v_isShared_1071_ == 0)
{
lean_ctor_set(v___x_1070_, 0, v___x_1073_);
v___x_1075_ = v___x_1070_;
goto v_reusejp_1074_;
}
else
{
lean_object* v_reuseFailAlloc_1076_; 
v_reuseFailAlloc_1076_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1076_, 0, v___x_1073_);
v___x_1075_ = v_reuseFailAlloc_1076_;
goto v_reusejp_1074_;
}
v_reusejp_1074_:
{
return v___x_1075_;
}
}
}
else
{
if (lean_obj_tag(v___x_1067_) == 0)
{
lean_object* v_a_1078_; lean_object* v___x_1080_; uint8_t v_isShared_1081_; uint8_t v_isSharedCheck_1085_; 
lean_dec(v_a_1065_);
lean_dec(v_a_1044_);
lean_dec(v_json_1023_);
v_a_1078_ = lean_ctor_get(v___x_1067_, 0);
v_isSharedCheck_1085_ = !lean_is_exclusive(v___x_1067_);
if (v_isSharedCheck_1085_ == 0)
{
v___x_1080_ = v___x_1067_;
v_isShared_1081_ = v_isSharedCheck_1085_;
goto v_resetjp_1079_;
}
else
{
lean_inc(v_a_1078_);
lean_dec(v___x_1067_);
v___x_1080_ = lean_box(0);
v_isShared_1081_ = v_isSharedCheck_1085_;
goto v_resetjp_1079_;
}
v_resetjp_1079_:
{
lean_object* v___x_1083_; 
if (v_isShared_1081_ == 0)
{
lean_ctor_set_tag(v___x_1080_, 0);
v___x_1083_ = v___x_1080_;
goto v_reusejp_1082_;
}
else
{
lean_object* v_reuseFailAlloc_1084_; 
v_reuseFailAlloc_1084_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1084_, 0, v_a_1078_);
v___x_1083_ = v_reuseFailAlloc_1084_;
goto v_reusejp_1082_;
}
v_reusejp_1082_:
{
return v___x_1083_;
}
}
}
else
{
lean_object* v_a_1086_; lean_object* v___x_1087_; lean_object* v___x_1088_; 
v_a_1086_ = lean_ctor_get(v___x_1067_, 0);
lean_inc(v_a_1086_);
lean_dec_ref_known(v___x_1067_, 1);
v___x_1087_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__12));
lean_inc(v_json_1023_);
v___x_1088_ = lp_JunkValues_Lean_Json_getObjValAs_x3f___at___00JunkValues_instFromJsonFinding_fromJson_spec__0(v_json_1023_, v___x_1087_);
if (lean_obj_tag(v___x_1088_) == 0)
{
lean_object* v_a_1089_; lean_object* v___x_1091_; uint8_t v_isShared_1092_; uint8_t v_isSharedCheck_1098_; 
lean_dec(v_a_1086_);
lean_dec(v_a_1065_);
lean_dec(v_a_1044_);
lean_dec(v_json_1023_);
v_a_1089_ = lean_ctor_get(v___x_1088_, 0);
v_isSharedCheck_1098_ = !lean_is_exclusive(v___x_1088_);
if (v_isSharedCheck_1098_ == 0)
{
v___x_1091_ = v___x_1088_;
v_isShared_1092_ = v_isSharedCheck_1098_;
goto v_resetjp_1090_;
}
else
{
lean_inc(v_a_1089_);
lean_dec(v___x_1088_);
v___x_1091_ = lean_box(0);
v_isShared_1092_ = v_isSharedCheck_1098_;
goto v_resetjp_1090_;
}
v_resetjp_1090_:
{
lean_object* v___x_1093_; lean_object* v___x_1094_; lean_object* v___x_1096_; 
v___x_1093_ = lean_obj_once(&lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__22, &lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__22_once, _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__22);
v___x_1094_ = lean_string_append(v___x_1093_, v_a_1089_);
lean_dec(v_a_1089_);
if (v_isShared_1092_ == 0)
{
lean_ctor_set(v___x_1091_, 0, v___x_1094_);
v___x_1096_ = v___x_1091_;
goto v_reusejp_1095_;
}
else
{
lean_object* v_reuseFailAlloc_1097_; 
v_reuseFailAlloc_1097_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1097_, 0, v___x_1094_);
v___x_1096_ = v_reuseFailAlloc_1097_;
goto v_reusejp_1095_;
}
v_reusejp_1095_:
{
return v___x_1096_;
}
}
}
else
{
if (lean_obj_tag(v___x_1088_) == 0)
{
lean_object* v_a_1099_; lean_object* v___x_1101_; uint8_t v_isShared_1102_; uint8_t v_isSharedCheck_1106_; 
lean_dec(v_a_1086_);
lean_dec(v_a_1065_);
lean_dec(v_a_1044_);
lean_dec(v_json_1023_);
v_a_1099_ = lean_ctor_get(v___x_1088_, 0);
v_isSharedCheck_1106_ = !lean_is_exclusive(v___x_1088_);
if (v_isSharedCheck_1106_ == 0)
{
v___x_1101_ = v___x_1088_;
v_isShared_1102_ = v_isSharedCheck_1106_;
goto v_resetjp_1100_;
}
else
{
lean_inc(v_a_1099_);
lean_dec(v___x_1088_);
v___x_1101_ = lean_box(0);
v_isShared_1102_ = v_isSharedCheck_1106_;
goto v_resetjp_1100_;
}
v_resetjp_1100_:
{
lean_object* v___x_1104_; 
if (v_isShared_1102_ == 0)
{
lean_ctor_set_tag(v___x_1101_, 0);
v___x_1104_ = v___x_1101_;
goto v_reusejp_1103_;
}
else
{
lean_object* v_reuseFailAlloc_1105_; 
v_reuseFailAlloc_1105_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1105_, 0, v_a_1099_);
v___x_1104_ = v_reuseFailAlloc_1105_;
goto v_reusejp_1103_;
}
v_reusejp_1103_:
{
return v___x_1104_;
}
}
}
else
{
lean_object* v_a_1107_; lean_object* v___x_1108_; lean_object* v___x_1109_; 
v_a_1107_ = lean_ctor_get(v___x_1088_, 0);
lean_inc(v_a_1107_);
lean_dec_ref_known(v___x_1088_, 1);
v___x_1108_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__14));
lean_inc(v_json_1023_);
v___x_1109_ = lp_JunkValues_Lean_Json_getObjValAs_x3f___at___00JunkValues_instFromJsonFinding_fromJson_spec__2(v_json_1023_, v___x_1108_);
if (lean_obj_tag(v___x_1109_) == 0)
{
lean_object* v_a_1110_; lean_object* v___x_1112_; uint8_t v_isShared_1113_; uint8_t v_isSharedCheck_1119_; 
lean_dec(v_a_1107_);
lean_dec(v_a_1086_);
lean_dec(v_a_1065_);
lean_dec(v_a_1044_);
lean_dec(v_json_1023_);
v_a_1110_ = lean_ctor_get(v___x_1109_, 0);
v_isSharedCheck_1119_ = !lean_is_exclusive(v___x_1109_);
if (v_isSharedCheck_1119_ == 0)
{
v___x_1112_ = v___x_1109_;
v_isShared_1113_ = v_isSharedCheck_1119_;
goto v_resetjp_1111_;
}
else
{
lean_inc(v_a_1110_);
lean_dec(v___x_1109_);
v___x_1112_ = lean_box(0);
v_isShared_1113_ = v_isSharedCheck_1119_;
goto v_resetjp_1111_;
}
v_resetjp_1111_:
{
lean_object* v___x_1114_; lean_object* v___x_1115_; lean_object* v___x_1117_; 
v___x_1114_ = lean_obj_once(&lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__26, &lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__26_once, _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__26);
v___x_1115_ = lean_string_append(v___x_1114_, v_a_1110_);
lean_dec(v_a_1110_);
if (v_isShared_1113_ == 0)
{
lean_ctor_set(v___x_1112_, 0, v___x_1115_);
v___x_1117_ = v___x_1112_;
goto v_reusejp_1116_;
}
else
{
lean_object* v_reuseFailAlloc_1118_; 
v_reuseFailAlloc_1118_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1118_, 0, v___x_1115_);
v___x_1117_ = v_reuseFailAlloc_1118_;
goto v_reusejp_1116_;
}
v_reusejp_1116_:
{
return v___x_1117_;
}
}
}
else
{
if (lean_obj_tag(v___x_1109_) == 0)
{
lean_object* v_a_1120_; lean_object* v___x_1122_; uint8_t v_isShared_1123_; uint8_t v_isSharedCheck_1127_; 
lean_dec(v_a_1107_);
lean_dec(v_a_1086_);
lean_dec(v_a_1065_);
lean_dec(v_a_1044_);
lean_dec(v_json_1023_);
v_a_1120_ = lean_ctor_get(v___x_1109_, 0);
v_isSharedCheck_1127_ = !lean_is_exclusive(v___x_1109_);
if (v_isSharedCheck_1127_ == 0)
{
v___x_1122_ = v___x_1109_;
v_isShared_1123_ = v_isSharedCheck_1127_;
goto v_resetjp_1121_;
}
else
{
lean_inc(v_a_1120_);
lean_dec(v___x_1109_);
v___x_1122_ = lean_box(0);
v_isShared_1123_ = v_isSharedCheck_1127_;
goto v_resetjp_1121_;
}
v_resetjp_1121_:
{
lean_object* v___x_1125_; 
if (v_isShared_1123_ == 0)
{
lean_ctor_set_tag(v___x_1122_, 0);
v___x_1125_ = v___x_1122_;
goto v_reusejp_1124_;
}
else
{
lean_object* v_reuseFailAlloc_1126_; 
v_reuseFailAlloc_1126_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1126_, 0, v_a_1120_);
v___x_1125_ = v_reuseFailAlloc_1126_;
goto v_reusejp_1124_;
}
v_reusejp_1124_:
{
return v___x_1125_;
}
}
}
else
{
lean_object* v_a_1128_; lean_object* v___x_1129_; lean_object* v___x_1130_; 
v_a_1128_ = lean_ctor_get(v___x_1109_, 0);
lean_inc(v_a_1128_);
lean_dec_ref_known(v___x_1109_, 1);
v___x_1129_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__16));
lean_inc(v_json_1023_);
v___x_1130_ = lp_JunkValues_Lean_Json_getObjValAs_x3f___at___00JunkValues_instFromJsonFinding_fromJson_spec__3(v_json_1023_, v___x_1129_);
if (lean_obj_tag(v___x_1130_) == 0)
{
lean_object* v_a_1131_; lean_object* v___x_1133_; uint8_t v_isShared_1134_; uint8_t v_isSharedCheck_1140_; 
lean_dec(v_a_1128_);
lean_dec(v_a_1107_);
lean_dec(v_a_1086_);
lean_dec(v_a_1065_);
lean_dec(v_a_1044_);
lean_dec(v_json_1023_);
v_a_1131_ = lean_ctor_get(v___x_1130_, 0);
v_isSharedCheck_1140_ = !lean_is_exclusive(v___x_1130_);
if (v_isSharedCheck_1140_ == 0)
{
v___x_1133_ = v___x_1130_;
v_isShared_1134_ = v_isSharedCheck_1140_;
goto v_resetjp_1132_;
}
else
{
lean_inc(v_a_1131_);
lean_dec(v___x_1130_);
v___x_1133_ = lean_box(0);
v_isShared_1134_ = v_isSharedCheck_1140_;
goto v_resetjp_1132_;
}
v_resetjp_1132_:
{
lean_object* v___x_1135_; lean_object* v___x_1136_; lean_object* v___x_1138_; 
v___x_1135_ = lean_obj_once(&lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__30, &lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__30_once, _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__30);
v___x_1136_ = lean_string_append(v___x_1135_, v_a_1131_);
lean_dec(v_a_1131_);
if (v_isShared_1134_ == 0)
{
lean_ctor_set(v___x_1133_, 0, v___x_1136_);
v___x_1138_ = v___x_1133_;
goto v_reusejp_1137_;
}
else
{
lean_object* v_reuseFailAlloc_1139_; 
v_reuseFailAlloc_1139_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1139_, 0, v___x_1136_);
v___x_1138_ = v_reuseFailAlloc_1139_;
goto v_reusejp_1137_;
}
v_reusejp_1137_:
{
return v___x_1138_;
}
}
}
else
{
if (lean_obj_tag(v___x_1130_) == 0)
{
lean_object* v_a_1141_; lean_object* v___x_1143_; uint8_t v_isShared_1144_; uint8_t v_isSharedCheck_1148_; 
lean_dec(v_a_1128_);
lean_dec(v_a_1107_);
lean_dec(v_a_1086_);
lean_dec(v_a_1065_);
lean_dec(v_a_1044_);
lean_dec(v_json_1023_);
v_a_1141_ = lean_ctor_get(v___x_1130_, 0);
v_isSharedCheck_1148_ = !lean_is_exclusive(v___x_1130_);
if (v_isSharedCheck_1148_ == 0)
{
v___x_1143_ = v___x_1130_;
v_isShared_1144_ = v_isSharedCheck_1148_;
goto v_resetjp_1142_;
}
else
{
lean_inc(v_a_1141_);
lean_dec(v___x_1130_);
v___x_1143_ = lean_box(0);
v_isShared_1144_ = v_isSharedCheck_1148_;
goto v_resetjp_1142_;
}
v_resetjp_1142_:
{
lean_object* v___x_1146_; 
if (v_isShared_1144_ == 0)
{
lean_ctor_set_tag(v___x_1143_, 0);
v___x_1146_ = v___x_1143_;
goto v_reusejp_1145_;
}
else
{
lean_object* v_reuseFailAlloc_1147_; 
v_reuseFailAlloc_1147_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1147_, 0, v_a_1141_);
v___x_1146_ = v_reuseFailAlloc_1147_;
goto v_reusejp_1145_;
}
v_reusejp_1145_:
{
return v___x_1146_;
}
}
}
else
{
lean_object* v_a_1149_; lean_object* v___x_1150_; lean_object* v___x_1151_; 
v_a_1149_ = lean_ctor_get(v___x_1130_, 0);
lean_inc(v_a_1149_);
lean_dec_ref_known(v___x_1130_, 1);
v___x_1150_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__19));
lean_inc(v_json_1023_);
v___x_1151_ = lp_JunkValues_Lean_Json_getObjValAs_x3f___at___00JunkValues_instFromJsonFinding_fromJson_spec__2(v_json_1023_, v___x_1150_);
if (lean_obj_tag(v___x_1151_) == 0)
{
lean_object* v_a_1152_; lean_object* v___x_1154_; uint8_t v_isShared_1155_; uint8_t v_isSharedCheck_1161_; 
lean_dec(v_a_1149_);
lean_dec(v_a_1128_);
lean_dec(v_a_1107_);
lean_dec(v_a_1086_);
lean_dec(v_a_1065_);
lean_dec(v_a_1044_);
lean_dec(v_json_1023_);
v_a_1152_ = lean_ctor_get(v___x_1151_, 0);
v_isSharedCheck_1161_ = !lean_is_exclusive(v___x_1151_);
if (v_isSharedCheck_1161_ == 0)
{
v___x_1154_ = v___x_1151_;
v_isShared_1155_ = v_isSharedCheck_1161_;
goto v_resetjp_1153_;
}
else
{
lean_inc(v_a_1152_);
lean_dec(v___x_1151_);
v___x_1154_ = lean_box(0);
v_isShared_1155_ = v_isSharedCheck_1161_;
goto v_resetjp_1153_;
}
v_resetjp_1153_:
{
lean_object* v___x_1156_; lean_object* v___x_1157_; lean_object* v___x_1159_; 
v___x_1156_ = lean_obj_once(&lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__34, &lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__34_once, _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__34);
v___x_1157_ = lean_string_append(v___x_1156_, v_a_1152_);
lean_dec(v_a_1152_);
if (v_isShared_1155_ == 0)
{
lean_ctor_set(v___x_1154_, 0, v___x_1157_);
v___x_1159_ = v___x_1154_;
goto v_reusejp_1158_;
}
else
{
lean_object* v_reuseFailAlloc_1160_; 
v_reuseFailAlloc_1160_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1160_, 0, v___x_1157_);
v___x_1159_ = v_reuseFailAlloc_1160_;
goto v_reusejp_1158_;
}
v_reusejp_1158_:
{
return v___x_1159_;
}
}
}
else
{
if (lean_obj_tag(v___x_1151_) == 0)
{
lean_object* v_a_1162_; lean_object* v___x_1164_; uint8_t v_isShared_1165_; uint8_t v_isSharedCheck_1169_; 
lean_dec(v_a_1149_);
lean_dec(v_a_1128_);
lean_dec(v_a_1107_);
lean_dec(v_a_1086_);
lean_dec(v_a_1065_);
lean_dec(v_a_1044_);
lean_dec(v_json_1023_);
v_a_1162_ = lean_ctor_get(v___x_1151_, 0);
v_isSharedCheck_1169_ = !lean_is_exclusive(v___x_1151_);
if (v_isSharedCheck_1169_ == 0)
{
v___x_1164_ = v___x_1151_;
v_isShared_1165_ = v_isSharedCheck_1169_;
goto v_resetjp_1163_;
}
else
{
lean_inc(v_a_1162_);
lean_dec(v___x_1151_);
v___x_1164_ = lean_box(0);
v_isShared_1165_ = v_isSharedCheck_1169_;
goto v_resetjp_1163_;
}
v_resetjp_1163_:
{
lean_object* v___x_1167_; 
if (v_isShared_1165_ == 0)
{
lean_ctor_set_tag(v___x_1164_, 0);
v___x_1167_ = v___x_1164_;
goto v_reusejp_1166_;
}
else
{
lean_object* v_reuseFailAlloc_1168_; 
v_reuseFailAlloc_1168_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1168_, 0, v_a_1162_);
v___x_1167_ = v_reuseFailAlloc_1168_;
goto v_reusejp_1166_;
}
v_reusejp_1166_:
{
return v___x_1167_;
}
}
}
else
{
lean_object* v_a_1170_; lean_object* v___x_1171_; lean_object* v___x_1172_; 
v_a_1170_ = lean_ctor_get(v___x_1151_, 0);
lean_inc(v_a_1170_);
lean_dec_ref_known(v___x_1151_, 1);
v___x_1171_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__22));
lean_inc(v_json_1023_);
v___x_1172_ = lp_JunkValues_Lean_Json_getObjValAs_x3f___at___00JunkValues_instFromJsonFinding_fromJson_spec__4(v_json_1023_, v___x_1171_);
if (lean_obj_tag(v___x_1172_) == 0)
{
lean_object* v_a_1173_; lean_object* v___x_1175_; uint8_t v_isShared_1176_; uint8_t v_isSharedCheck_1182_; 
lean_dec(v_a_1170_);
lean_dec(v_a_1149_);
lean_dec(v_a_1128_);
lean_dec(v_a_1107_);
lean_dec(v_a_1086_);
lean_dec(v_a_1065_);
lean_dec(v_a_1044_);
lean_dec(v_json_1023_);
v_a_1173_ = lean_ctor_get(v___x_1172_, 0);
v_isSharedCheck_1182_ = !lean_is_exclusive(v___x_1172_);
if (v_isSharedCheck_1182_ == 0)
{
v___x_1175_ = v___x_1172_;
v_isShared_1176_ = v_isSharedCheck_1182_;
goto v_resetjp_1174_;
}
else
{
lean_inc(v_a_1173_);
lean_dec(v___x_1172_);
v___x_1175_ = lean_box(0);
v_isShared_1176_ = v_isSharedCheck_1182_;
goto v_resetjp_1174_;
}
v_resetjp_1174_:
{
lean_object* v___x_1177_; lean_object* v___x_1178_; lean_object* v___x_1180_; 
v___x_1177_ = lean_obj_once(&lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__38, &lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__38_once, _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__38);
v___x_1178_ = lean_string_append(v___x_1177_, v_a_1173_);
lean_dec(v_a_1173_);
if (v_isShared_1176_ == 0)
{
lean_ctor_set(v___x_1175_, 0, v___x_1178_);
v___x_1180_ = v___x_1175_;
goto v_reusejp_1179_;
}
else
{
lean_object* v_reuseFailAlloc_1181_; 
v_reuseFailAlloc_1181_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1181_, 0, v___x_1178_);
v___x_1180_ = v_reuseFailAlloc_1181_;
goto v_reusejp_1179_;
}
v_reusejp_1179_:
{
return v___x_1180_;
}
}
}
else
{
if (lean_obj_tag(v___x_1172_) == 0)
{
lean_object* v_a_1183_; lean_object* v___x_1185_; uint8_t v_isShared_1186_; uint8_t v_isSharedCheck_1190_; 
lean_dec(v_a_1170_);
lean_dec(v_a_1149_);
lean_dec(v_a_1128_);
lean_dec(v_a_1107_);
lean_dec(v_a_1086_);
lean_dec(v_a_1065_);
lean_dec(v_a_1044_);
lean_dec(v_json_1023_);
v_a_1183_ = lean_ctor_get(v___x_1172_, 0);
v_isSharedCheck_1190_ = !lean_is_exclusive(v___x_1172_);
if (v_isSharedCheck_1190_ == 0)
{
v___x_1185_ = v___x_1172_;
v_isShared_1186_ = v_isSharedCheck_1190_;
goto v_resetjp_1184_;
}
else
{
lean_inc(v_a_1183_);
lean_dec(v___x_1172_);
v___x_1185_ = lean_box(0);
v_isShared_1186_ = v_isSharedCheck_1190_;
goto v_resetjp_1184_;
}
v_resetjp_1184_:
{
lean_object* v___x_1188_; 
if (v_isShared_1186_ == 0)
{
lean_ctor_set_tag(v___x_1185_, 0);
v___x_1188_ = v___x_1185_;
goto v_reusejp_1187_;
}
else
{
lean_object* v_reuseFailAlloc_1189_; 
v_reuseFailAlloc_1189_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1189_, 0, v_a_1183_);
v___x_1188_ = v_reuseFailAlloc_1189_;
goto v_reusejp_1187_;
}
v_reusejp_1187_:
{
return v___x_1188_;
}
}
}
else
{
lean_object* v_a_1191_; lean_object* v___x_1192_; lean_object* v___x_1193_; 
v_a_1191_ = lean_ctor_get(v___x_1172_, 0);
lean_inc(v_a_1191_);
lean_dec_ref_known(v___x_1172_, 1);
v___x_1192_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprFinding_repr___redArg___closed__24));
v___x_1193_ = lp_JunkValues_Lean_Json_getObjValAs_x3f___at___00JunkValues_instFromJsonFinding_fromJson_spec__2(v_json_1023_, v___x_1192_);
if (lean_obj_tag(v___x_1193_) == 0)
{
lean_object* v_a_1194_; lean_object* v___x_1196_; uint8_t v_isShared_1197_; uint8_t v_isSharedCheck_1203_; 
lean_dec(v_a_1191_);
lean_dec(v_a_1170_);
lean_dec(v_a_1149_);
lean_dec(v_a_1128_);
lean_dec(v_a_1107_);
lean_dec(v_a_1086_);
lean_dec(v_a_1065_);
lean_dec(v_a_1044_);
v_a_1194_ = lean_ctor_get(v___x_1193_, 0);
v_isSharedCheck_1203_ = !lean_is_exclusive(v___x_1193_);
if (v_isSharedCheck_1203_ == 0)
{
v___x_1196_ = v___x_1193_;
v_isShared_1197_ = v_isSharedCheck_1203_;
goto v_resetjp_1195_;
}
else
{
lean_inc(v_a_1194_);
lean_dec(v___x_1193_);
v___x_1196_ = lean_box(0);
v_isShared_1197_ = v_isSharedCheck_1203_;
goto v_resetjp_1195_;
}
v_resetjp_1195_:
{
lean_object* v___x_1198_; lean_object* v___x_1199_; lean_object* v___x_1201_; 
v___x_1198_ = lean_obj_once(&lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__42, &lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__42_once, _init_lp_JunkValues_JunkValues_instFromJsonFinding_fromJson___closed__42);
v___x_1199_ = lean_string_append(v___x_1198_, v_a_1194_);
lean_dec(v_a_1194_);
if (v_isShared_1197_ == 0)
{
lean_ctor_set(v___x_1196_, 0, v___x_1199_);
v___x_1201_ = v___x_1196_;
goto v_reusejp_1200_;
}
else
{
lean_object* v_reuseFailAlloc_1202_; 
v_reuseFailAlloc_1202_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1202_, 0, v___x_1199_);
v___x_1201_ = v_reuseFailAlloc_1202_;
goto v_reusejp_1200_;
}
v_reusejp_1200_:
{
return v___x_1201_;
}
}
}
else
{
if (lean_obj_tag(v___x_1193_) == 0)
{
lean_object* v_a_1204_; lean_object* v___x_1206_; uint8_t v_isShared_1207_; uint8_t v_isSharedCheck_1211_; 
lean_dec(v_a_1191_);
lean_dec(v_a_1170_);
lean_dec(v_a_1149_);
lean_dec(v_a_1128_);
lean_dec(v_a_1107_);
lean_dec(v_a_1086_);
lean_dec(v_a_1065_);
lean_dec(v_a_1044_);
v_a_1204_ = lean_ctor_get(v___x_1193_, 0);
v_isSharedCheck_1211_ = !lean_is_exclusive(v___x_1193_);
if (v_isSharedCheck_1211_ == 0)
{
v___x_1206_ = v___x_1193_;
v_isShared_1207_ = v_isSharedCheck_1211_;
goto v_resetjp_1205_;
}
else
{
lean_inc(v_a_1204_);
lean_dec(v___x_1193_);
v___x_1206_ = lean_box(0);
v_isShared_1207_ = v_isSharedCheck_1211_;
goto v_resetjp_1205_;
}
v_resetjp_1205_:
{
lean_object* v___x_1209_; 
if (v_isShared_1207_ == 0)
{
lean_ctor_set_tag(v___x_1206_, 0);
v___x_1209_ = v___x_1206_;
goto v_reusejp_1208_;
}
else
{
lean_object* v_reuseFailAlloc_1210_; 
v_reuseFailAlloc_1210_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1210_, 0, v_a_1204_);
v___x_1209_ = v_reuseFailAlloc_1210_;
goto v_reusejp_1208_;
}
v_reusejp_1208_:
{
return v___x_1209_;
}
}
}
else
{
lean_object* v_a_1212_; lean_object* v___x_1214_; uint8_t v_isShared_1215_; uint8_t v_isSharedCheck_1221_; 
v_a_1212_ = lean_ctor_get(v___x_1193_, 0);
v_isSharedCheck_1221_ = !lean_is_exclusive(v___x_1193_);
if (v_isSharedCheck_1221_ == 0)
{
v___x_1214_ = v___x_1193_;
v_isShared_1215_ = v_isSharedCheck_1221_;
goto v_resetjp_1213_;
}
else
{
lean_inc(v_a_1212_);
lean_dec(v___x_1193_);
v___x_1214_ = lean_box(0);
v_isShared_1215_ = v_isSharedCheck_1221_;
goto v_resetjp_1213_;
}
v_resetjp_1213_:
{
lean_object* v___x_1216_; uint8_t v___x_1217_; lean_object* v___x_1219_; 
v___x_1216_ = lean_alloc_ctor(0, 8, 1);
lean_ctor_set(v___x_1216_, 0, v_a_1044_);
lean_ctor_set(v___x_1216_, 1, v_a_1086_);
lean_ctor_set(v___x_1216_, 2, v_a_1107_);
lean_ctor_set(v___x_1216_, 3, v_a_1128_);
lean_ctor_set(v___x_1216_, 4, v_a_1149_);
lean_ctor_set(v___x_1216_, 5, v_a_1170_);
lean_ctor_set(v___x_1216_, 6, v_a_1191_);
lean_ctor_set(v___x_1216_, 7, v_a_1212_);
v___x_1217_ = lean_unbox(v_a_1065_);
lean_dec(v_a_1065_);
lean_ctor_set_uint8(v___x_1216_, sizeof(void*)*8, v___x_1217_);
if (v_isShared_1215_ == 0)
{
lean_ctor_set(v___x_1214_, 0, v___x_1216_);
v___x_1219_ = v___x_1214_;
goto v_reusejp_1218_;
}
else
{
lean_object* v_reuseFailAlloc_1220_; 
v_reuseFailAlloc_1220_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1220_, 0, v___x_1216_);
v___x_1219_ = v_reuseFailAlloc_1220_;
goto v_reusejp_1218_;
}
v_reusejp_1218_:
{
return v___x_1219_;
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_Finding_message(lean_object* v_f_1234_){
_start:
{
lean_object* v_rule_1235_; lean_object* v_term_1236_; lean_object* v_guards_1237_; lean_object* v_value_1238_; lean_object* v_status_1239_; lean_object* v_note_1240_; lean_object* v___x_1241_; lean_object* v___x_1242_; lean_object* v_conds_1243_; lean_object* v___x_1244_; lean_object* v___x_1245_; lean_object* v___x_1246_; lean_object* v___x_1247_; lean_object* v___x_1248_; lean_object* v___x_1249_; lean_object* v___x_1250_; lean_object* v_head_1251_; lean_object* v___x_1252_; uint8_t v___x_1253_; lean_object* v___x_1254_; lean_object* v___x_1255_; lean_object* v___x_1256_; lean_object* v_prov_1257_; lean_object* v___y_1259_; lean_object* v___x_1278_; lean_object* v___x_1279_; uint8_t v___x_1280_; 
v_rule_1235_ = lean_ctor_get(v_f_1234_, 1);
lean_inc(v_rule_1235_);
v_term_1236_ = lean_ctor_get(v_f_1234_, 3);
lean_inc_ref(v_term_1236_);
v_guards_1237_ = lean_ctor_get(v_f_1234_, 4);
lean_inc_ref(v_guards_1237_);
v_value_1238_ = lean_ctor_get(v_f_1234_, 5);
lean_inc_ref(v_value_1238_);
v_status_1239_ = lean_ctor_get(v_f_1234_, 6);
lean_inc(v_status_1239_);
v_note_1240_ = lean_ctor_get(v_f_1234_, 7);
lean_inc_ref(v_note_1240_);
lean_dec_ref(v_f_1234_);
v___x_1241_ = ((lean_object*)(lp_JunkValues_JunkValues_Finding_message___closed__0));
v___x_1242_ = lean_array_to_list(v_guards_1237_);
v_conds_1243_ = l_String_intercalate(v___x_1241_, v___x_1242_);
v___x_1244_ = ((lean_object*)(lp_JunkValues_JunkValues_Finding_message___closed__1));
v___x_1245_ = lean_string_append(v___x_1244_, v_conds_1243_);
lean_dec_ref(v_conds_1243_);
v___x_1246_ = ((lean_object*)(lp_JunkValues_JunkValues_Finding_message___closed__2));
v___x_1247_ = lean_string_append(v___x_1245_, v___x_1246_);
v___x_1248_ = lean_string_append(v___x_1247_, v_term_1236_);
v___x_1249_ = ((lean_object*)(lp_JunkValues_JunkValues_Finding_message___closed__3));
v___x_1250_ = lean_string_append(v___x_1248_, v___x_1249_);
v_head_1251_ = lean_string_append(v___x_1250_, v_value_1238_);
v___x_1252_ = ((lean_object*)(lp_JunkValues_JunkValues_Finding_message___closed__4));
v___x_1253_ = 1;
v___x_1254_ = l_Lean_Name_toStringWithToken___at___00Lean_Name_toString_spec__0(v_rule_1235_, v___x_1253_);
v___x_1255_ = lean_string_append(v___x_1252_, v___x_1254_);
lean_dec_ref(v___x_1254_);
v___x_1256_ = ((lean_object*)(lp_JunkValues_JunkValues_Finding_message___closed__5));
v_prov_1257_ = lean_string_append(v___x_1255_, v___x_1256_);
v___x_1278_ = lean_string_utf8_byte_size(v_note_1240_);
v___x_1279_ = lean_unsigned_to_nat(0u);
v___x_1280_ = lean_nat_dec_eq(v___x_1278_, v___x_1279_);
if (v___x_1280_ == 0)
{
lean_object* v___x_1281_; lean_object* v___x_1282_; 
v___x_1281_ = ((lean_object*)(lp_JunkValues_JunkValues_Finding_message___closed__9));
v___x_1282_ = lean_string_append(v___x_1281_, v_note_1240_);
lean_dec_ref(v_note_1240_);
v___y_1259_ = v___x_1282_;
goto v___jp_1258_;
}
else
{
lean_object* v___x_1283_; 
lean_dec_ref(v_note_1240_);
v___x_1283_ = ((lean_object*)(lp_JunkValues_JunkValues_instInhabitedStatus_default___closed__0));
v___y_1259_ = v___x_1283_;
goto v___jp_1258_;
}
v___jp_1258_:
{
switch(lean_obj_tag(v_status_1239_))
{
case 0:
{
lean_object* v_how_1260_; lean_object* v___x_1261_; lean_object* v___x_1262_; lean_object* v___x_1263_; lean_object* v___x_1264_; lean_object* v___x_1265_; lean_object* v___x_1266_; 
lean_dec_ref(v___y_1259_);
lean_dec_ref(v_value_1238_);
lean_dec_ref(v_term_1236_);
v_how_1260_ = lean_ctor_get(v_status_1239_, 0);
lean_inc_ref(v_how_1260_);
lean_dec_ref_known(v_status_1239_, 1);
v___x_1261_ = ((lean_object*)(lp_JunkValues_JunkValues_Finding_message___closed__6));
v___x_1262_ = lean_string_append(v___x_1261_, v_how_1260_);
lean_dec_ref(v_how_1260_);
v___x_1263_ = ((lean_object*)(lp_JunkValues_JunkValues_Finding_message___closed__7));
v___x_1264_ = lean_string_append(v___x_1262_, v___x_1263_);
v___x_1265_ = lean_string_append(v___x_1264_, v_head_1251_);
lean_dec_ref(v_head_1251_);
v___x_1266_ = lean_string_append(v___x_1265_, v_prov_1257_);
lean_dec_ref(v_prov_1257_);
return v___x_1266_;
}
case 1:
{
lean_object* v___x_1267_; lean_object* v___x_1268_; 
lean_dec_ref(v_value_1238_);
lean_dec_ref(v_term_1236_);
v___x_1267_ = lean_string_append(v_head_1251_, v_prov_1257_);
lean_dec_ref(v_prov_1257_);
v___x_1268_ = lean_string_append(v___x_1267_, v___y_1259_);
lean_dec_ref(v___y_1259_);
return v___x_1268_;
}
default: 
{
lean_object* v_how_1269_; lean_object* v___x_1270_; lean_object* v___x_1271_; lean_object* v___x_1272_; lean_object* v___x_1273_; lean_object* v___x_1274_; lean_object* v___x_1275_; lean_object* v___x_1276_; lean_object* v___x_1277_; 
lean_dec_ref(v_head_1251_);
v_how_1269_ = lean_ctor_get(v_status_1239_, 0);
lean_inc_ref(v_how_1269_);
lean_dec_ref_known(v_status_1239_, 1);
v___x_1270_ = lean_string_append(v_term_1236_, v___x_1249_);
v___x_1271_ = lean_string_append(v___x_1270_, v_value_1238_);
lean_dec_ref(v_value_1238_);
v___x_1272_ = ((lean_object*)(lp_JunkValues_JunkValues_Finding_message___closed__8));
v___x_1273_ = lean_string_append(v___x_1271_, v___x_1272_);
v___x_1274_ = lean_string_append(v___x_1273_, v_how_1269_);
lean_dec_ref(v_how_1269_);
v___x_1275_ = lean_string_append(v___x_1274_, v___x_1256_);
v___x_1276_ = lean_string_append(v___x_1275_, v_prov_1257_);
lean_dec_ref(v_prov_1257_);
v___x_1277_ = lean_string_append(v___x_1276_, v___y_1259_);
lean_dec_ref(v___y_1259_);
return v___x_1277_;
}
}
}
}
}
LEAN_EXPORT uint8_t lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_inheritRisk_spec__0_spec__0___redArg(lean_object* v_a_1284_, lean_object* v_x_1285_){
_start:
{
if (lean_obj_tag(v_x_1285_) == 0)
{
uint8_t v___x_1286_; 
v___x_1286_ = 0;
return v___x_1286_;
}
else
{
lean_object* v_key_1287_; lean_object* v_tail_1288_; uint8_t v___x_1289_; 
v_key_1287_ = lean_ctor_get(v_x_1285_, 0);
v_tail_1288_ = lean_ctor_get(v_x_1285_, 2);
v___x_1289_ = lean_name_eq(v_key_1287_, v_a_1284_);
if (v___x_1289_ == 0)
{
v_x_1285_ = v_tail_1288_;
goto _start;
}
else
{
return v___x_1289_;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_inheritRisk_spec__0_spec__0___redArg___boxed(lean_object* v_a_1291_, lean_object* v_x_1292_){
_start:
{
uint8_t v_res_1293_; lean_object* v_r_1294_; 
v_res_1293_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_inheritRisk_spec__0_spec__0___redArg(v_a_1291_, v_x_1292_);
lean_dec(v_x_1292_);
lean_dec(v_a_1291_);
v_r_1294_ = lean_box(v_res_1293_);
return v_r_1294_;
}
}
static uint64_t _init_lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_inheritRisk_spec__0___redArg___closed__0(void){
_start:
{
lean_object* v___x_1295_; uint64_t v___x_1296_; 
v___x_1295_ = lean_unsigned_to_nat(1723u);
v___x_1296_ = lean_uint64_of_nat(v___x_1295_);
return v___x_1296_;
}
}
LEAN_EXPORT uint8_t lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_inheritRisk_spec__0___redArg(lean_object* v_m_1297_, lean_object* v_a_1298_){
_start:
{
lean_object* v_buckets_1299_; lean_object* v___x_1300_; uint64_t v___y_1302_; 
v_buckets_1299_ = lean_ctor_get(v_m_1297_, 1);
v___x_1300_ = lean_array_get_size(v_buckets_1299_);
if (lean_obj_tag(v_a_1298_) == 0)
{
uint64_t v___x_1316_; 
v___x_1316_ = lean_uint64_once(&lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_inheritRisk_spec__0___redArg___closed__0, &lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_inheritRisk_spec__0___redArg___closed__0_once, _init_lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_inheritRisk_spec__0___redArg___closed__0);
v___y_1302_ = v___x_1316_;
goto v___jp_1301_;
}
else
{
uint64_t v_hash_1317_; 
v_hash_1317_ = lean_ctor_get_uint64(v_a_1298_, sizeof(void*)*2);
v___y_1302_ = v_hash_1317_;
goto v___jp_1301_;
}
v___jp_1301_:
{
uint64_t v___x_1303_; uint64_t v___x_1304_; uint64_t v_fold_1305_; uint64_t v___x_1306_; uint64_t v___x_1307_; uint64_t v___x_1308_; size_t v___x_1309_; size_t v___x_1310_; size_t v___x_1311_; size_t v___x_1312_; size_t v___x_1313_; lean_object* v___x_1314_; uint8_t v___x_1315_; 
v___x_1303_ = 32ULL;
v___x_1304_ = lean_uint64_shift_right(v___y_1302_, v___x_1303_);
v_fold_1305_ = lean_uint64_xor(v___y_1302_, v___x_1304_);
v___x_1306_ = 16ULL;
v___x_1307_ = lean_uint64_shift_right(v_fold_1305_, v___x_1306_);
v___x_1308_ = lean_uint64_xor(v_fold_1305_, v___x_1307_);
v___x_1309_ = lean_uint64_to_usize(v___x_1308_);
v___x_1310_ = lean_usize_of_nat(v___x_1300_);
v___x_1311_ = ((size_t)1ULL);
v___x_1312_ = lean_usize_sub(v___x_1310_, v___x_1311_);
v___x_1313_ = lean_usize_land(v___x_1309_, v___x_1312_);
v___x_1314_ = lean_array_uget_borrowed(v_buckets_1299_, v___x_1313_);
v___x_1315_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_inheritRisk_spec__0_spec__0___redArg(v_a_1298_, v___x_1314_);
return v___x_1315_;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_inheritRisk_spec__0___redArg___boxed(lean_object* v_m_1318_, lean_object* v_a_1319_){
_start:
{
uint8_t v_res_1320_; lean_object* v_r_1321_; 
v_res_1320_ = lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_inheritRisk_spec__0___redArg(v_m_1318_, v_a_1319_);
lean_dec(v_a_1319_);
lean_dec_ref(v_m_1318_);
v_r_1321_ = lean_box(v_res_1320_);
return v_r_1321_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00JunkValues_inheritRisk_spec__2(lean_object* v_atRisk_1322_, lean_object* v_as_1323_, size_t v_i_1324_, size_t v_stop_1325_, lean_object* v_b_1326_){
_start:
{
lean_object* v___y_1328_; uint8_t v___x_1332_; 
v___x_1332_ = lean_usize_dec_eq(v_i_1324_, v_stop_1325_);
if (v___x_1332_ == 0)
{
lean_object* v___x_1333_; uint8_t v___x_1334_; 
v___x_1333_ = lean_array_uget_borrowed(v_as_1323_, v_i_1324_);
v___x_1334_ = lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_inheritRisk_spec__0___redArg(v_atRisk_1322_, v___x_1333_);
if (v___x_1334_ == 0)
{
v___y_1328_ = v_b_1326_;
goto v___jp_1327_;
}
else
{
lean_object* v___x_1335_; 
lean_inc(v___x_1333_);
v___x_1335_ = lean_array_push(v_b_1326_, v___x_1333_);
v___y_1328_ = v___x_1335_;
goto v___jp_1327_;
}
}
else
{
return v_b_1326_;
}
v___jp_1327_:
{
size_t v___x_1329_; size_t v___x_1330_; 
v___x_1329_ = ((size_t)1ULL);
v___x_1330_ = lean_usize_add(v_i_1324_, v___x_1329_);
v_i_1324_ = v___x_1330_;
v_b_1326_ = v___y_1328_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00JunkValues_inheritRisk_spec__2___boxed(lean_object* v_atRisk_1336_, lean_object* v_as_1337_, lean_object* v_i_1338_, lean_object* v_stop_1339_, lean_object* v_b_1340_){
_start:
{
size_t v_i_boxed_1341_; size_t v_stop_boxed_1342_; lean_object* v_res_1343_; 
v_i_boxed_1341_ = lean_unbox_usize(v_i_1338_);
lean_dec(v_i_1338_);
v_stop_boxed_1342_ = lean_unbox_usize(v_stop_1339_);
lean_dec(v_stop_1339_);
v_res_1343_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00JunkValues_inheritRisk_spec__2(v_atRisk_1336_, v_as_1337_, v_i_boxed_1341_, v_stop_boxed_1342_, v_b_1340_);
lean_dec_ref(v_as_1337_);
lean_dec_ref(v_atRisk_1336_);
return v_res_1343_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_getD___at___00Std_DHashMap_Internal_Raw_u2080_Const_getD___at___00JunkValues_inheritRisk_spec__1_spec__2___redArg(lean_object* v_a_1344_, lean_object* v_fallback_1345_, lean_object* v_x_1346_){
_start:
{
if (lean_obj_tag(v_x_1346_) == 0)
{
lean_inc(v_fallback_1345_);
return v_fallback_1345_;
}
else
{
lean_object* v_key_1347_; lean_object* v_value_1348_; lean_object* v_tail_1349_; uint8_t v___x_1350_; 
v_key_1347_ = lean_ctor_get(v_x_1346_, 0);
v_value_1348_ = lean_ctor_get(v_x_1346_, 1);
v_tail_1349_ = lean_ctor_get(v_x_1346_, 2);
v___x_1350_ = lean_name_eq(v_key_1347_, v_a_1344_);
if (v___x_1350_ == 0)
{
v_x_1346_ = v_tail_1349_;
goto _start;
}
else
{
lean_inc(v_value_1348_);
return v_value_1348_;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_getD___at___00Std_DHashMap_Internal_Raw_u2080_Const_getD___at___00JunkValues_inheritRisk_spec__1_spec__2___redArg___boxed(lean_object* v_a_1352_, lean_object* v_fallback_1353_, lean_object* v_x_1354_){
_start:
{
lean_object* v_res_1355_; 
v_res_1355_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_getD___at___00Std_DHashMap_Internal_Raw_u2080_Const_getD___at___00JunkValues_inheritRisk_spec__1_spec__2___redArg(v_a_1352_, v_fallback_1353_, v_x_1354_);
lean_dec(v_x_1354_);
lean_dec(v_fallback_1353_);
lean_dec(v_a_1352_);
return v_res_1355_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_Const_getD___at___00JunkValues_inheritRisk_spec__1___redArg(lean_object* v_m_1356_, lean_object* v_a_1357_, lean_object* v_fallback_1358_){
_start:
{
lean_object* v_buckets_1359_; lean_object* v___x_1360_; uint64_t v___y_1362_; 
v_buckets_1359_ = lean_ctor_get(v_m_1356_, 1);
v___x_1360_ = lean_array_get_size(v_buckets_1359_);
if (lean_obj_tag(v_a_1357_) == 0)
{
uint64_t v___x_1376_; 
v___x_1376_ = lean_uint64_once(&lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_inheritRisk_spec__0___redArg___closed__0, &lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_inheritRisk_spec__0___redArg___closed__0_once, _init_lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_inheritRisk_spec__0___redArg___closed__0);
v___y_1362_ = v___x_1376_;
goto v___jp_1361_;
}
else
{
uint64_t v_hash_1377_; 
v_hash_1377_ = lean_ctor_get_uint64(v_a_1357_, sizeof(void*)*2);
v___y_1362_ = v_hash_1377_;
goto v___jp_1361_;
}
v___jp_1361_:
{
uint64_t v___x_1363_; uint64_t v___x_1364_; uint64_t v_fold_1365_; uint64_t v___x_1366_; uint64_t v___x_1367_; uint64_t v___x_1368_; size_t v___x_1369_; size_t v___x_1370_; size_t v___x_1371_; size_t v___x_1372_; size_t v___x_1373_; lean_object* v___x_1374_; lean_object* v___x_1375_; 
v___x_1363_ = 32ULL;
v___x_1364_ = lean_uint64_shift_right(v___y_1362_, v___x_1363_);
v_fold_1365_ = lean_uint64_xor(v___y_1362_, v___x_1364_);
v___x_1366_ = 16ULL;
v___x_1367_ = lean_uint64_shift_right(v_fold_1365_, v___x_1366_);
v___x_1368_ = lean_uint64_xor(v_fold_1365_, v___x_1367_);
v___x_1369_ = lean_uint64_to_usize(v___x_1368_);
v___x_1370_ = lean_usize_of_nat(v___x_1360_);
v___x_1371_ = ((size_t)1ULL);
v___x_1372_ = lean_usize_sub(v___x_1370_, v___x_1371_);
v___x_1373_ = lean_usize_land(v___x_1369_, v___x_1372_);
v___x_1374_ = lean_array_uget_borrowed(v_buckets_1359_, v___x_1373_);
v___x_1375_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_getD___at___00Std_DHashMap_Internal_Raw_u2080_Const_getD___at___00JunkValues_inheritRisk_spec__1_spec__2___redArg(v_a_1357_, v_fallback_1358_, v___x_1374_);
return v___x_1375_;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_Const_getD___at___00JunkValues_inheritRisk_spec__1___redArg___boxed(lean_object* v_m_1378_, lean_object* v_a_1379_, lean_object* v_fallback_1380_){
_start:
{
lean_object* v_res_1381_; 
v_res_1381_ = lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_Const_getD___at___00JunkValues_inheritRisk_spec__1___redArg(v_m_1378_, v_a_1379_, v_fallback_1380_);
lean_dec(v_fallback_1380_);
lean_dec(v_a_1379_);
lean_dec_ref(v_m_1378_);
return v_res_1381_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_inheritRisk(lean_object* v_deps_1384_, lean_object* v_atRisk_1385_, lean_object* v_decl_1386_){
_start:
{
lean_object* v___x_1387_; lean_object* v___x_1388_; lean_object* v___x_1389_; lean_object* v___x_1390_; uint8_t v___x_1391_; 
v___x_1387_ = lean_unsigned_to_nat(0u);
v___x_1388_ = ((lean_object*)(lp_JunkValues_JunkValues_inheritRisk___closed__0));
v___x_1389_ = lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_Const_getD___at___00JunkValues_inheritRisk_spec__1___redArg(v_deps_1384_, v_decl_1386_, v___x_1388_);
v___x_1390_ = lean_array_get_size(v___x_1389_);
v___x_1391_ = lean_nat_dec_lt(v___x_1387_, v___x_1390_);
if (v___x_1391_ == 0)
{
lean_dec(v___x_1389_);
return v___x_1388_;
}
else
{
uint8_t v___x_1392_; 
v___x_1392_ = lean_nat_dec_le(v___x_1390_, v___x_1390_);
if (v___x_1392_ == 0)
{
if (v___x_1391_ == 0)
{
lean_dec(v___x_1389_);
return v___x_1388_;
}
else
{
size_t v___x_1393_; size_t v___x_1394_; lean_object* v___x_1395_; 
v___x_1393_ = ((size_t)0ULL);
v___x_1394_ = lean_usize_of_nat(v___x_1390_);
v___x_1395_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00JunkValues_inheritRisk_spec__2(v_atRisk_1385_, v___x_1389_, v___x_1393_, v___x_1394_, v___x_1388_);
lean_dec(v___x_1389_);
return v___x_1395_;
}
}
else
{
size_t v___x_1396_; size_t v___x_1397_; lean_object* v___x_1398_; 
v___x_1396_ = ((size_t)0ULL);
v___x_1397_ = lean_usize_of_nat(v___x_1390_);
v___x_1398_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00JunkValues_inheritRisk_spec__2(v_atRisk_1385_, v___x_1389_, v___x_1396_, v___x_1397_, v___x_1388_);
lean_dec(v___x_1389_);
return v___x_1398_;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_inheritRisk___boxed(lean_object* v_deps_1399_, lean_object* v_atRisk_1400_, lean_object* v_decl_1401_){
_start:
{
lean_object* v_res_1402_; 
v_res_1402_ = lp_JunkValues_JunkValues_inheritRisk(v_deps_1399_, v_atRisk_1400_, v_decl_1401_);
lean_dec(v_decl_1401_);
lean_dec_ref(v_atRisk_1400_);
lean_dec_ref(v_deps_1399_);
return v_res_1402_;
}
}
LEAN_EXPORT uint8_t lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_inheritRisk_spec__0(lean_object* v_00_u03b2_1403_, lean_object* v_m_1404_, lean_object* v_a_1405_){
_start:
{
uint8_t v___x_1406_; 
v___x_1406_ = lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_inheritRisk_spec__0___redArg(v_m_1404_, v_a_1405_);
return v___x_1406_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_inheritRisk_spec__0___boxed(lean_object* v_00_u03b2_1407_, lean_object* v_m_1408_, lean_object* v_a_1409_){
_start:
{
uint8_t v_res_1410_; lean_object* v_r_1411_; 
v_res_1410_ = lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_inheritRisk_spec__0(v_00_u03b2_1407_, v_m_1408_, v_a_1409_);
lean_dec(v_a_1409_);
lean_dec_ref(v_m_1408_);
v_r_1411_ = lean_box(v_res_1410_);
return v_r_1411_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_Const_getD___at___00JunkValues_inheritRisk_spec__1(lean_object* v_00_u03b2_1412_, lean_object* v_m_1413_, lean_object* v_a_1414_, lean_object* v_fallback_1415_){
_start:
{
lean_object* v___x_1416_; 
v___x_1416_ = lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_Const_getD___at___00JunkValues_inheritRisk_spec__1___redArg(v_m_1413_, v_a_1414_, v_fallback_1415_);
return v___x_1416_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_Const_getD___at___00JunkValues_inheritRisk_spec__1___boxed(lean_object* v_00_u03b2_1417_, lean_object* v_m_1418_, lean_object* v_a_1419_, lean_object* v_fallback_1420_){
_start:
{
lean_object* v_res_1421_; 
v_res_1421_ = lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_Const_getD___at___00JunkValues_inheritRisk_spec__1(v_00_u03b2_1417_, v_m_1418_, v_a_1419_, v_fallback_1420_);
lean_dec(v_fallback_1420_);
lean_dec(v_a_1419_);
lean_dec_ref(v_m_1418_);
return v_res_1421_;
}
}
LEAN_EXPORT uint8_t lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_inheritRisk_spec__0_spec__0(lean_object* v_00_u03b2_1422_, lean_object* v_a_1423_, lean_object* v_x_1424_){
_start:
{
uint8_t v___x_1425_; 
v___x_1425_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_inheritRisk_spec__0_spec__0___redArg(v_a_1423_, v_x_1424_);
return v___x_1425_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_inheritRisk_spec__0_spec__0___boxed(lean_object* v_00_u03b2_1426_, lean_object* v_a_1427_, lean_object* v_x_1428_){
_start:
{
uint8_t v_res_1429_; lean_object* v_r_1430_; 
v_res_1429_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_inheritRisk_spec__0_spec__0(v_00_u03b2_1426_, v_a_1427_, v_x_1428_);
lean_dec(v_x_1428_);
lean_dec(v_a_1427_);
v_r_1430_ = lean_box(v_res_1429_);
return v_r_1430_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_getD___at___00Std_DHashMap_Internal_Raw_u2080_Const_getD___at___00JunkValues_inheritRisk_spec__1_spec__2(lean_object* v_00_u03b2_1431_, lean_object* v_a_1432_, lean_object* v_fallback_1433_, lean_object* v_x_1434_){
_start:
{
lean_object* v___x_1435_; 
v___x_1435_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_getD___at___00Std_DHashMap_Internal_Raw_u2080_Const_getD___at___00JunkValues_inheritRisk_spec__1_spec__2___redArg(v_a_1432_, v_fallback_1433_, v_x_1434_);
return v___x_1435_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_getD___at___00Std_DHashMap_Internal_Raw_u2080_Const_getD___at___00JunkValues_inheritRisk_spec__1_spec__2___boxed(lean_object* v_00_u03b2_1436_, lean_object* v_a_1437_, lean_object* v_fallback_1438_, lean_object* v_x_1439_){
_start:
{
lean_object* v_res_1440_; 
v_res_1440_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_getD___at___00Std_DHashMap_Internal_Raw_u2080_Const_getD___at___00JunkValues_inheritRisk_spec__1_spec__2(v_00_u03b2_1436_, v_a_1437_, v_fallback_1438_, v_x_1439_);
lean_dec(v_x_1439_);
lean_dec(v_fallback_1438_);
lean_dec(v_a_1437_);
return v_res_1440_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00__private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_riskySet_spec__0_spec__0_spec__1_spec__3___redArg(lean_object* v_x_1441_, lean_object* v_x_1442_){
_start:
{
if (lean_obj_tag(v_x_1442_) == 0)
{
return v_x_1441_;
}
else
{
lean_object* v_key_1443_; lean_object* v_value_1444_; lean_object* v_tail_1445_; lean_object* v___x_1447_; uint8_t v_isShared_1448_; uint8_t v_isSharedCheck_1471_; 
v_key_1443_ = lean_ctor_get(v_x_1442_, 0);
v_value_1444_ = lean_ctor_get(v_x_1442_, 1);
v_tail_1445_ = lean_ctor_get(v_x_1442_, 2);
v_isSharedCheck_1471_ = !lean_is_exclusive(v_x_1442_);
if (v_isSharedCheck_1471_ == 0)
{
v___x_1447_ = v_x_1442_;
v_isShared_1448_ = v_isSharedCheck_1471_;
goto v_resetjp_1446_;
}
else
{
lean_inc(v_tail_1445_);
lean_inc(v_value_1444_);
lean_inc(v_key_1443_);
lean_dec(v_x_1442_);
v___x_1447_ = lean_box(0);
v_isShared_1448_ = v_isSharedCheck_1471_;
goto v_resetjp_1446_;
}
v_resetjp_1446_:
{
lean_object* v___x_1449_; uint64_t v___y_1451_; 
v___x_1449_ = lean_array_get_size(v_x_1441_);
if (lean_obj_tag(v_key_1443_) == 0)
{
uint64_t v___x_1469_; 
v___x_1469_ = lean_uint64_once(&lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_inheritRisk_spec__0___redArg___closed__0, &lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_inheritRisk_spec__0___redArg___closed__0_once, _init_lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_inheritRisk_spec__0___redArg___closed__0);
v___y_1451_ = v___x_1469_;
goto v___jp_1450_;
}
else
{
uint64_t v_hash_1470_; 
v_hash_1470_ = lean_ctor_get_uint64(v_key_1443_, sizeof(void*)*2);
v___y_1451_ = v_hash_1470_;
goto v___jp_1450_;
}
v___jp_1450_:
{
uint64_t v___x_1452_; uint64_t v___x_1453_; uint64_t v_fold_1454_; uint64_t v___x_1455_; uint64_t v___x_1456_; uint64_t v___x_1457_; size_t v___x_1458_; size_t v___x_1459_; size_t v___x_1460_; size_t v___x_1461_; size_t v___x_1462_; lean_object* v___x_1463_; lean_object* v___x_1465_; 
v___x_1452_ = 32ULL;
v___x_1453_ = lean_uint64_shift_right(v___y_1451_, v___x_1452_);
v_fold_1454_ = lean_uint64_xor(v___y_1451_, v___x_1453_);
v___x_1455_ = 16ULL;
v___x_1456_ = lean_uint64_shift_right(v_fold_1454_, v___x_1455_);
v___x_1457_ = lean_uint64_xor(v_fold_1454_, v___x_1456_);
v___x_1458_ = lean_uint64_to_usize(v___x_1457_);
v___x_1459_ = lean_usize_of_nat(v___x_1449_);
v___x_1460_ = ((size_t)1ULL);
v___x_1461_ = lean_usize_sub(v___x_1459_, v___x_1460_);
v___x_1462_ = lean_usize_land(v___x_1458_, v___x_1461_);
v___x_1463_ = lean_array_uget_borrowed(v_x_1441_, v___x_1462_);
lean_inc(v___x_1463_);
if (v_isShared_1448_ == 0)
{
lean_ctor_set(v___x_1447_, 2, v___x_1463_);
v___x_1465_ = v___x_1447_;
goto v_reusejp_1464_;
}
else
{
lean_object* v_reuseFailAlloc_1468_; 
v_reuseFailAlloc_1468_ = lean_alloc_ctor(1, 3, 0);
lean_ctor_set(v_reuseFailAlloc_1468_, 0, v_key_1443_);
lean_ctor_set(v_reuseFailAlloc_1468_, 1, v_value_1444_);
lean_ctor_set(v_reuseFailAlloc_1468_, 2, v___x_1463_);
v___x_1465_ = v_reuseFailAlloc_1468_;
goto v_reusejp_1464_;
}
v_reusejp_1464_:
{
lean_object* v___x_1466_; 
v___x_1466_ = lean_array_uset(v_x_1441_, v___x_1462_, v___x_1465_);
v_x_1441_ = v___x_1466_;
v_x_1442_ = v_tail_1445_;
goto _start;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_riskySet_spec__0_spec__0_spec__1___redArg(lean_object* v_i_1472_, lean_object* v_source_1473_, lean_object* v_target_1474_){
_start:
{
lean_object* v___x_1475_; uint8_t v___x_1476_; 
v___x_1475_ = lean_array_get_size(v_source_1473_);
v___x_1476_ = lean_nat_dec_lt(v_i_1472_, v___x_1475_);
if (v___x_1476_ == 0)
{
lean_dec_ref(v_source_1473_);
lean_dec(v_i_1472_);
return v_target_1474_;
}
else
{
lean_object* v_es_1477_; lean_object* v___x_1478_; lean_object* v_source_1479_; lean_object* v_target_1480_; lean_object* v___x_1481_; lean_object* v___x_1482_; 
v_es_1477_ = lean_array_fget(v_source_1473_, v_i_1472_);
v___x_1478_ = lean_box(0);
v_source_1479_ = lean_array_fset(v_source_1473_, v_i_1472_, v___x_1478_);
v_target_1480_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00__private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_riskySet_spec__0_spec__0_spec__1_spec__3___redArg(v_target_1474_, v_es_1477_);
v___x_1481_ = lean_unsigned_to_nat(1u);
v___x_1482_ = lean_nat_add(v_i_1472_, v___x_1481_);
lean_dec(v_i_1472_);
v_i_1472_ = v___x_1482_;
v_source_1473_ = v_source_1479_;
v_target_1474_ = v_target_1480_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_riskySet_spec__0_spec__0___redArg(lean_object* v_data_1484_){
_start:
{
lean_object* v___x_1485_; lean_object* v___x_1486_; lean_object* v_nbuckets_1487_; lean_object* v___x_1488_; lean_object* v___x_1489_; lean_object* v___x_1490_; lean_object* v___x_1491_; 
v___x_1485_ = lean_array_get_size(v_data_1484_);
v___x_1486_ = lean_unsigned_to_nat(2u);
v_nbuckets_1487_ = lean_nat_mul(v___x_1485_, v___x_1486_);
v___x_1488_ = lean_unsigned_to_nat(0u);
v___x_1489_ = lean_box(0);
v___x_1490_ = lean_mk_array(v_nbuckets_1487_, v___x_1489_);
v___x_1491_ = lp_JunkValues___private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_riskySet_spec__0_spec__0_spec__1___redArg(v___x_1488_, v_data_1484_, v___x_1490_);
return v___x_1491_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_riskySet_spec__0___redArg(lean_object* v_m_1492_, lean_object* v_a_1493_, lean_object* v_b_1494_){
_start:
{
lean_object* v_size_1495_; lean_object* v_buckets_1496_; lean_object* v___x_1497_; uint64_t v___y_1499_; 
v_size_1495_ = lean_ctor_get(v_m_1492_, 0);
v_buckets_1496_ = lean_ctor_get(v_m_1492_, 1);
v___x_1497_ = lean_array_get_size(v_buckets_1496_);
if (lean_obj_tag(v_a_1493_) == 0)
{
uint64_t v___x_1536_; 
v___x_1536_ = lean_uint64_once(&lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_inheritRisk_spec__0___redArg___closed__0, &lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_inheritRisk_spec__0___redArg___closed__0_once, _init_lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_inheritRisk_spec__0___redArg___closed__0);
v___y_1499_ = v___x_1536_;
goto v___jp_1498_;
}
else
{
uint64_t v_hash_1537_; 
v_hash_1537_ = lean_ctor_get_uint64(v_a_1493_, sizeof(void*)*2);
v___y_1499_ = v_hash_1537_;
goto v___jp_1498_;
}
v___jp_1498_:
{
uint64_t v___x_1500_; uint64_t v___x_1501_; uint64_t v_fold_1502_; uint64_t v___x_1503_; uint64_t v___x_1504_; uint64_t v___x_1505_; size_t v___x_1506_; size_t v___x_1507_; size_t v___x_1508_; size_t v___x_1509_; size_t v___x_1510_; lean_object* v_bkt_1511_; uint8_t v___x_1512_; 
v___x_1500_ = 32ULL;
v___x_1501_ = lean_uint64_shift_right(v___y_1499_, v___x_1500_);
v_fold_1502_ = lean_uint64_xor(v___y_1499_, v___x_1501_);
v___x_1503_ = 16ULL;
v___x_1504_ = lean_uint64_shift_right(v_fold_1502_, v___x_1503_);
v___x_1505_ = lean_uint64_xor(v_fold_1502_, v___x_1504_);
v___x_1506_ = lean_uint64_to_usize(v___x_1505_);
v___x_1507_ = lean_usize_of_nat(v___x_1497_);
v___x_1508_ = ((size_t)1ULL);
v___x_1509_ = lean_usize_sub(v___x_1507_, v___x_1508_);
v___x_1510_ = lean_usize_land(v___x_1506_, v___x_1509_);
v_bkt_1511_ = lean_array_uget_borrowed(v_buckets_1496_, v___x_1510_);
v___x_1512_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_inheritRisk_spec__0_spec__0___redArg(v_a_1493_, v_bkt_1511_);
if (v___x_1512_ == 0)
{
lean_object* v___x_1514_; uint8_t v_isShared_1515_; uint8_t v_isSharedCheck_1533_; 
lean_inc_ref(v_buckets_1496_);
lean_inc(v_size_1495_);
v_isSharedCheck_1533_ = !lean_is_exclusive(v_m_1492_);
if (v_isSharedCheck_1533_ == 0)
{
lean_object* v_unused_1534_; lean_object* v_unused_1535_; 
v_unused_1534_ = lean_ctor_get(v_m_1492_, 1);
lean_dec(v_unused_1534_);
v_unused_1535_ = lean_ctor_get(v_m_1492_, 0);
lean_dec(v_unused_1535_);
v___x_1514_ = v_m_1492_;
v_isShared_1515_ = v_isSharedCheck_1533_;
goto v_resetjp_1513_;
}
else
{
lean_dec(v_m_1492_);
v___x_1514_ = lean_box(0);
v_isShared_1515_ = v_isSharedCheck_1533_;
goto v_resetjp_1513_;
}
v_resetjp_1513_:
{
lean_object* v___x_1516_; lean_object* v_size_x27_1517_; lean_object* v___x_1518_; lean_object* v_buckets_x27_1519_; lean_object* v___x_1520_; lean_object* v___x_1521_; lean_object* v___x_1522_; lean_object* v___x_1523_; lean_object* v___x_1524_; uint8_t v___x_1525_; 
v___x_1516_ = lean_unsigned_to_nat(1u);
v_size_x27_1517_ = lean_nat_add(v_size_1495_, v___x_1516_);
lean_dec(v_size_1495_);
lean_inc(v_bkt_1511_);
v___x_1518_ = lean_alloc_ctor(1, 3, 0);
lean_ctor_set(v___x_1518_, 0, v_a_1493_);
lean_ctor_set(v___x_1518_, 1, v_b_1494_);
lean_ctor_set(v___x_1518_, 2, v_bkt_1511_);
v_buckets_x27_1519_ = lean_array_uset(v_buckets_1496_, v___x_1510_, v___x_1518_);
v___x_1520_ = lean_unsigned_to_nat(4u);
v___x_1521_ = lean_nat_mul(v_size_x27_1517_, v___x_1520_);
v___x_1522_ = lean_unsigned_to_nat(3u);
v___x_1523_ = lean_nat_div(v___x_1521_, v___x_1522_);
lean_dec(v___x_1521_);
v___x_1524_ = lean_array_get_size(v_buckets_x27_1519_);
v___x_1525_ = lean_nat_dec_le(v___x_1523_, v___x_1524_);
lean_dec(v___x_1523_);
if (v___x_1525_ == 0)
{
lean_object* v_val_1526_; lean_object* v___x_1528_; 
v_val_1526_ = lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_riskySet_spec__0_spec__0___redArg(v_buckets_x27_1519_);
if (v_isShared_1515_ == 0)
{
lean_ctor_set(v___x_1514_, 1, v_val_1526_);
lean_ctor_set(v___x_1514_, 0, v_size_x27_1517_);
v___x_1528_ = v___x_1514_;
goto v_reusejp_1527_;
}
else
{
lean_object* v_reuseFailAlloc_1529_; 
v_reuseFailAlloc_1529_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1529_, 0, v_size_x27_1517_);
lean_ctor_set(v_reuseFailAlloc_1529_, 1, v_val_1526_);
v___x_1528_ = v_reuseFailAlloc_1529_;
goto v_reusejp_1527_;
}
v_reusejp_1527_:
{
return v___x_1528_;
}
}
else
{
lean_object* v___x_1531_; 
if (v_isShared_1515_ == 0)
{
lean_ctor_set(v___x_1514_, 1, v_buckets_x27_1519_);
lean_ctor_set(v___x_1514_, 0, v_size_x27_1517_);
v___x_1531_ = v___x_1514_;
goto v_reusejp_1530_;
}
else
{
lean_object* v_reuseFailAlloc_1532_; 
v_reuseFailAlloc_1532_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1532_, 0, v_size_x27_1517_);
lean_ctor_set(v_reuseFailAlloc_1532_, 1, v_buckets_x27_1519_);
v___x_1531_ = v_reuseFailAlloc_1532_;
goto v_reusejp_1530_;
}
v_reusejp_1530_:
{
return v___x_1531_;
}
}
}
}
else
{
lean_dec(v_b_1494_);
lean_dec(v_a_1493_);
return v_m_1492_;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00JunkValues_riskySet_spec__1(lean_object* v_as_1538_, size_t v_i_1539_, size_t v_stop_1540_, lean_object* v_b_1541_){
_start:
{
lean_object* v___y_1543_; uint8_t v___x_1547_; 
v___x_1547_ = lean_usize_dec_eq(v_i_1539_, v_stop_1540_);
if (v___x_1547_ == 0)
{
lean_object* v___x_1548_; lean_object* v_decl_1549_; lean_object* v_status_1550_; uint8_t v___x_1551_; 
v___x_1548_ = lean_array_uget_borrowed(v_as_1538_, v_i_1539_);
v_decl_1549_ = lean_ctor_get(v___x_1548_, 0);
v_status_1550_ = lean_ctor_get(v___x_1548_, 6);
v___x_1551_ = lp_JunkValues_JunkValues_Status_isFinding(v_status_1550_);
if (v___x_1551_ == 0)
{
v___y_1543_ = v_b_1541_;
goto v___jp_1542_;
}
else
{
lean_object* v___x_1552_; lean_object* v___x_1553_; 
v___x_1552_ = lean_box(0);
lean_inc(v_decl_1549_);
v___x_1553_ = lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_riskySet_spec__0___redArg(v_b_1541_, v_decl_1549_, v___x_1552_);
v___y_1543_ = v___x_1553_;
goto v___jp_1542_;
}
}
else
{
return v_b_1541_;
}
v___jp_1542_:
{
size_t v___x_1544_; size_t v___x_1545_; 
v___x_1544_ = ((size_t)1ULL);
v___x_1545_ = lean_usize_add(v_i_1539_, v___x_1544_);
v_i_1539_ = v___x_1545_;
v_b_1541_ = v___y_1543_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00JunkValues_riskySet_spec__1___boxed(lean_object* v_as_1554_, lean_object* v_i_1555_, lean_object* v_stop_1556_, lean_object* v_b_1557_){
_start:
{
size_t v_i_boxed_1558_; size_t v_stop_boxed_1559_; lean_object* v_res_1560_; 
v_i_boxed_1558_ = lean_unbox_usize(v_i_1555_);
lean_dec(v_i_1555_);
v_stop_boxed_1559_ = lean_unbox_usize(v_stop_1556_);
lean_dec(v_stop_1556_);
v_res_1560_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00JunkValues_riskySet_spec__1(v_as_1554_, v_i_boxed_1558_, v_stop_boxed_1559_, v_b_1557_);
lean_dec_ref(v_as_1554_);
return v_res_1560_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_riskySet___closed__0(void){
_start:
{
lean_object* v___x_1561_; lean_object* v___x_1562_; lean_object* v___x_1563_; 
v___x_1561_ = lean_box(0);
v___x_1562_ = lean_unsigned_to_nat(16u);
v___x_1563_ = lean_mk_array(v___x_1562_, v___x_1561_);
return v___x_1563_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_riskySet___closed__1(void){
_start:
{
lean_object* v___x_1564_; lean_object* v___x_1565_; lean_object* v___x_1566_; 
v___x_1564_ = lean_obj_once(&lp_JunkValues_JunkValues_riskySet___closed__0, &lp_JunkValues_JunkValues_riskySet___closed__0_once, _init_lp_JunkValues_JunkValues_riskySet___closed__0);
v___x_1565_ = lean_unsigned_to_nat(0u);
v___x_1566_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1566_, 0, v___x_1565_);
lean_ctor_set(v___x_1566_, 1, v___x_1564_);
return v___x_1566_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_riskySet(lean_object* v_findings_1567_){
_start:
{
lean_object* v___x_1568_; lean_object* v___x_1569_; lean_object* v___x_1570_; uint8_t v___x_1571_; 
v___x_1568_ = lean_unsigned_to_nat(0u);
v___x_1569_ = lean_obj_once(&lp_JunkValues_JunkValues_riskySet___closed__1, &lp_JunkValues_JunkValues_riskySet___closed__1_once, _init_lp_JunkValues_JunkValues_riskySet___closed__1);
v___x_1570_ = lean_array_get_size(v_findings_1567_);
v___x_1571_ = lean_nat_dec_lt(v___x_1568_, v___x_1570_);
if (v___x_1571_ == 0)
{
return v___x_1569_;
}
else
{
uint8_t v___x_1572_; 
v___x_1572_ = lean_nat_dec_le(v___x_1570_, v___x_1570_);
if (v___x_1572_ == 0)
{
if (v___x_1571_ == 0)
{
return v___x_1569_;
}
else
{
size_t v___x_1573_; size_t v___x_1574_; lean_object* v___x_1575_; 
v___x_1573_ = ((size_t)0ULL);
v___x_1574_ = lean_usize_of_nat(v___x_1570_);
v___x_1575_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00JunkValues_riskySet_spec__1(v_findings_1567_, v___x_1573_, v___x_1574_, v___x_1569_);
return v___x_1575_;
}
}
else
{
size_t v___x_1576_; size_t v___x_1577_; lean_object* v___x_1578_; 
v___x_1576_ = ((size_t)0ULL);
v___x_1577_ = lean_usize_of_nat(v___x_1570_);
v___x_1578_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00JunkValues_riskySet_spec__1(v_findings_1567_, v___x_1576_, v___x_1577_, v___x_1569_);
return v___x_1578_;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_riskySet___boxed(lean_object* v_findings_1579_){
_start:
{
lean_object* v_res_1580_; 
v_res_1580_ = lp_JunkValues_JunkValues_riskySet(v_findings_1579_);
lean_dec_ref(v_findings_1579_);
return v_res_1580_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_riskySet_spec__0(lean_object* v_00_u03b2_1581_, lean_object* v_m_1582_, lean_object* v_a_1583_, lean_object* v_b_1584_){
_start:
{
lean_object* v___x_1585_; 
v___x_1585_ = lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_riskySet_spec__0___redArg(v_m_1582_, v_a_1583_, v_b_1584_);
return v___x_1585_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_riskySet_spec__0_spec__0(lean_object* v_00_u03b2_1586_, lean_object* v_data_1587_){
_start:
{
lean_object* v___x_1588_; 
v___x_1588_ = lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_riskySet_spec__0_spec__0___redArg(v_data_1587_);
return v___x_1588_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_riskySet_spec__0_spec__0_spec__1(lean_object* v_00_u03b2_1589_, lean_object* v_i_1590_, lean_object* v_source_1591_, lean_object* v_target_1592_){
_start:
{
lean_object* v___x_1593_; 
v___x_1593_ = lp_JunkValues___private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_riskySet_spec__0_spec__0_spec__1___redArg(v_i_1590_, v_source_1591_, v_target_1592_);
return v___x_1593_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00__private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_riskySet_spec__0_spec__0_spec__1_spec__3(lean_object* v_00_u03b2_1594_, lean_object* v_x_1595_, lean_object* v_x_1596_){
_start:
{
lean_object* v___x_1597_; 
v___x_1597_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00__private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_riskySet_spec__0_spec__0_spec__1_spec__3___redArg(v_x_1595_, v_x_1596_);
return v___x_1597_;
}
}
lean_object* runtime_initialize_Init(uint8_t builtin);
lean_object* runtime_initialize_Lean(uint8_t builtin);
lean_object* runtime_initialize_Std_Data_HashMap(uint8_t builtin);
lean_object* runtime_initialize_Std_Data_HashSet(uint8_t builtin);
static bool _G_runtime_initialized = false;
LEAN_EXPORT lean_object* runtime_initialize_JunkValues_JunkValues_Report(uint8_t builtin) {
lean_object * res;
if (_G_runtime_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_runtime_initialized = true;
res = runtime_initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = runtime_initialize_Lean(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = runtime_initialize_Std_Data_HashMap(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = runtime_initialize_Std_Data_HashSet(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
lp_JunkValues_JunkValues_instInhabitedSite_default = _init_lp_JunkValues_JunkValues_instInhabitedSite_default();
lp_JunkValues_JunkValues_instInhabitedSite = _init_lp_JunkValues_JunkValues_instInhabitedSite();
return lean_io_result_mk_ok(lean_box(0));
}
lean_object* runtime_initialize_Init(uint8_t builtin);
static bool _G_meta_initialized = false;
LEAN_EXPORT lean_object* meta_initialize_JunkValues_JunkValues_Report(uint8_t builtin) {
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
lean_object* initialize_Std_Data_HashMap(uint8_t builtin);
lean_object* initialize_Std_Data_HashSet(uint8_t builtin);
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_JunkValues_JunkValues_Report(uint8_t builtin) {
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
res = initialize_Std_Data_HashMap(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Std_Data_HashSet(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = runtime_initialize_JunkValues_JunkValues_Report(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = meta_initialize_JunkValues_JunkValues_Report(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return initialize_JunkValues_JunkValues_Report(builtin);
}
#ifdef __cplusplus
}
#endif
