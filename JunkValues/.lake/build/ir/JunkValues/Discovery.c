// Lean compiler output
// Module: JunkValues.Discovery
// Imports: public import Init public meta import Init public import JunkValues.Rule public import Std.Data.HashSet
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
lean_object* lean_array_get_size(lean_object*);
lean_object* lean_nat_mul(lean_object*, lean_object*);
lean_object* lean_mk_array(lean_object*, lean_object*);
uint8_t lean_nat_dec_lt(lean_object*, lean_object*);
lean_object* lean_array_fget(lean_object*, lean_object*);
lean_object* lean_array_fset(lean_object*, lean_object*, lean_object*);
uint64_t lean_uint64_shift_right(uint64_t, uint64_t);
uint64_t lean_uint64_xor(uint64_t, uint64_t);
size_t lean_uint64_to_usize(uint64_t);
size_t lean_usize_of_nat(lean_object*);
size_t lean_usize_sub(size_t, size_t);
size_t lean_usize_land(size_t, size_t);
lean_object* lean_array_uget_borrowed(lean_object*, size_t);
lean_object* lean_array_uset(lean_object*, size_t, lean_object*);
uint64_t lean_uint64_of_nat(lean_object*);
lean_object* lean_nat_add(lean_object*, lean_object*);
lean_object* l_Lean_Name_mkStr2(lean_object*, lean_object*);
lean_object* l_Lean_Environment_getModuleIdxFor_x3f(lean_object*, lean_object*);
lean_object* l_Lean_Environment_header(lean_object*);
lean_object* l_Lean_EnvironmentHeader_moduleNames(lean_object*);
uint8_t l_Lean_Name_isPrefixOf(lean_object*, lean_object*);
uint8_t l_Lean_isPrivateName(lean_object*);
uint8_t l_Lean_Name_isInternal(lean_object*);
uint8_t l_Lean_Name_isImplementationDetail(lean_object*);
lean_object* l_Lean_Name_mkStr1(lean_object*);
uint8_t l_Lean_Expr_isAppOfArity(lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_Expr_appFn_x21(lean_object*);
lean_object* l_Lean_Expr_appArg_x21(lean_object*);
uint8_t lean_name_eq(lean_object*, lean_object*);
uint8_t lean_usize_dec_eq(size_t, size_t);
lean_object* lean_nat_div(lean_object*, lean_object*);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
size_t lean_usize_add(size_t, size_t);
lean_object* lean_st_ref_get(lean_object*);
lean_object* lean_mk_empty_array_with_capacity(lean_object*);
size_t lean_array_size(lean_object*);
uint8_t lean_usize_dec_lt(size_t, size_t);
lean_object* lp_JunkValues_JunkValues_ruleOfTheorem_x3f(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* lean_array_push(lean_object*, lean_object*);
lean_object* l_Lean_ConstantInfo_type(lean_object*);
lean_object* l_Lean_Environment_constants(lean_object*);
lean_object* lean_array_fget_borrowed(lean_object*, lean_object*);
static const lean_string_object lp_JunkValues_JunkValues_defaultValueHeads___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "OfNat"};
static const lean_object* lp_JunkValues_JunkValues_defaultValueHeads___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__0_value;
static const lean_string_object lp_JunkValues_JunkValues_defaultValueHeads___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "ofNat"};
static const lean_object* lp_JunkValues_JunkValues_defaultValueHeads___closed__1 = (const lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__1_value;
static const lean_ctor_object lp_JunkValues_JunkValues_defaultValueHeads___closed__2_value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__0_value),LEAN_SCALAR_PTR_LITERAL(135, 241, 166, 108, 243, 216, 193, 244)}};
static const lean_ctor_object lp_JunkValues_JunkValues_defaultValueHeads___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__2_value_aux_0),((lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__1_value),LEAN_SCALAR_PTR_LITERAL(2, 108, 58, 34, 100, 49, 50, 216)}};
static const lean_object* lp_JunkValues_JunkValues_defaultValueHeads___closed__2 = (const lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__2_value;
static const lean_string_object lp_JunkValues_JunkValues_defaultValueHeads___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "Zero"};
static const lean_object* lp_JunkValues_JunkValues_defaultValueHeads___closed__3 = (const lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__3_value;
static const lean_string_object lp_JunkValues_JunkValues_defaultValueHeads___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "zero"};
static const lean_object* lp_JunkValues_JunkValues_defaultValueHeads___closed__4 = (const lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__4_value;
static const lean_ctor_object lp_JunkValues_JunkValues_defaultValueHeads___closed__5_value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__3_value),LEAN_SCALAR_PTR_LITERAL(192, 171, 244, 106, 217, 72, 118, 253)}};
static const lean_ctor_object lp_JunkValues_JunkValues_defaultValueHeads___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__5_value_aux_0),((lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__4_value),LEAN_SCALAR_PTR_LITERAL(172, 37, 33, 120, 251, 36, 203, 36)}};
static const lean_object* lp_JunkValues_JunkValues_defaultValueHeads___closed__5 = (const lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__5_value;
static const lean_string_object lp_JunkValues_JunkValues_defaultValueHeads___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "One"};
static const lean_object* lp_JunkValues_JunkValues_defaultValueHeads___closed__6 = (const lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__6_value;
static const lean_string_object lp_JunkValues_JunkValues_defaultValueHeads___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "one"};
static const lean_object* lp_JunkValues_JunkValues_defaultValueHeads___closed__7 = (const lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__7_value;
static const lean_ctor_object lp_JunkValues_JunkValues_defaultValueHeads___closed__8_value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__6_value),LEAN_SCALAR_PTR_LITERAL(19, 85, 184, 168, 121, 55, 74, 19)}};
static const lean_ctor_object lp_JunkValues_JunkValues_defaultValueHeads___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__8_value_aux_0),((lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__7_value),LEAN_SCALAR_PTR_LITERAL(31, 134, 200, 93, 163, 253, 252, 128)}};
static const lean_object* lp_JunkValues_JunkValues_defaultValueHeads___closed__8 = (const lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__8_value;
static const lean_string_object lp_JunkValues_JunkValues_defaultValueHeads___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 16, .m_capacity = 16, .m_length = 15, .m_data = "EmptyCollection"};
static const lean_object* lp_JunkValues_JunkValues_defaultValueHeads___closed__9 = (const lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__9_value;
static const lean_string_object lp_JunkValues_JunkValues_defaultValueHeads___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 16, .m_capacity = 16, .m_length = 15, .m_data = "emptyCollection"};
static const lean_object* lp_JunkValues_JunkValues_defaultValueHeads___closed__10 = (const lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__10_value;
static const lean_ctor_object lp_JunkValues_JunkValues_defaultValueHeads___closed__11_value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__9_value),LEAN_SCALAR_PTR_LITERAL(236, 209, 69, 209, 212, 29, 83, 196)}};
static const lean_ctor_object lp_JunkValues_JunkValues_defaultValueHeads___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__11_value_aux_0),((lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__10_value),LEAN_SCALAR_PTR_LITERAL(3, 53, 136, 5, 91, 228, 156, 207)}};
static const lean_object* lp_JunkValues_JunkValues_defaultValueHeads___closed__11 = (const lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__11_value;
static const lean_string_object lp_JunkValues_JunkValues_defaultValueHeads___closed__12_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "Bot"};
static const lean_object* lp_JunkValues_JunkValues_defaultValueHeads___closed__12 = (const lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__12_value;
static const lean_string_object lp_JunkValues_JunkValues_defaultValueHeads___closed__13_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "bot"};
static const lean_object* lp_JunkValues_JunkValues_defaultValueHeads___closed__13 = (const lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__13_value;
static const lean_ctor_object lp_JunkValues_JunkValues_defaultValueHeads___closed__14_value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__12_value),LEAN_SCALAR_PTR_LITERAL(192, 138, 190, 95, 247, 78, 16, 101)}};
static const lean_ctor_object lp_JunkValues_JunkValues_defaultValueHeads___closed__14_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__14_value_aux_0),((lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__13_value),LEAN_SCALAR_PTR_LITERAL(98, 132, 46, 181, 27, 87, 250, 96)}};
static const lean_object* lp_JunkValues_JunkValues_defaultValueHeads___closed__14 = (const lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__14_value;
static const lean_string_object lp_JunkValues_JunkValues_defaultValueHeads___closed__15_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "Top"};
static const lean_object* lp_JunkValues_JunkValues_defaultValueHeads___closed__15 = (const lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__15_value;
static const lean_string_object lp_JunkValues_JunkValues_defaultValueHeads___closed__16_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "top"};
static const lean_object* lp_JunkValues_JunkValues_defaultValueHeads___closed__16 = (const lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__16_value;
static const lean_ctor_object lp_JunkValues_JunkValues_defaultValueHeads___closed__17_value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__15_value),LEAN_SCALAR_PTR_LITERAL(17, 209, 230, 57, 51, 197, 162, 233)}};
static const lean_ctor_object lp_JunkValues_JunkValues_defaultValueHeads___closed__17_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__17_value_aux_0),((lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__16_value),LEAN_SCALAR_PTR_LITERAL(101, 62, 44, 17, 165, 201, 212, 212)}};
static const lean_object* lp_JunkValues_JunkValues_defaultValueHeads___closed__17 = (const lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__17_value;
static const lean_string_object lp_JunkValues_JunkValues_defaultValueHeads___closed__18_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "Option"};
static const lean_object* lp_JunkValues_JunkValues_defaultValueHeads___closed__18 = (const lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__18_value;
static const lean_string_object lp_JunkValues_JunkValues_defaultValueHeads___closed__19_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "none"};
static const lean_object* lp_JunkValues_JunkValues_defaultValueHeads___closed__19 = (const lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__19_value;
static const lean_ctor_object lp_JunkValues_JunkValues_defaultValueHeads___closed__20_value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__18_value),LEAN_SCALAR_PTR_LITERAL(95, 234, 177, 188, 3, 226, 91, 252)}};
static const lean_ctor_object lp_JunkValues_JunkValues_defaultValueHeads___closed__20_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__20_value_aux_0),((lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__19_value),LEAN_SCALAR_PTR_LITERAL(149, 114, 34, 228, 75, 195, 143, 131)}};
static const lean_object* lp_JunkValues_JunkValues_defaultValueHeads___closed__20 = (const lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__20_value;
static const lean_string_object lp_JunkValues_JunkValues_defaultValueHeads___closed__21_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 10, .m_capacity = 10, .m_length = 9, .m_data = "Inhabited"};
static const lean_object* lp_JunkValues_JunkValues_defaultValueHeads___closed__21 = (const lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__21_value;
static const lean_string_object lp_JunkValues_JunkValues_defaultValueHeads___closed__22_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "default"};
static const lean_object* lp_JunkValues_JunkValues_defaultValueHeads___closed__22 = (const lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__22_value;
static const lean_ctor_object lp_JunkValues_JunkValues_defaultValueHeads___closed__23_value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__21_value),LEAN_SCALAR_PTR_LITERAL(164, 88, 86, 106, 191, 136, 33, 185)}};
static const lean_ctor_object lp_JunkValues_JunkValues_defaultValueHeads___closed__23_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__23_value_aux_0),((lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__22_value),LEAN_SCALAR_PTR_LITERAL(174, 152, 115, 107, 166, 56, 116, 8)}};
static const lean_object* lp_JunkValues_JunkValues_defaultValueHeads___closed__23 = (const lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__23_value;
static const lean_string_object lp_JunkValues_JunkValues_defaultValueHeads___closed__24_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "List"};
static const lean_object* lp_JunkValues_JunkValues_defaultValueHeads___closed__24 = (const lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__24_value;
static const lean_string_object lp_JunkValues_JunkValues_defaultValueHeads___closed__25_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "nil"};
static const lean_object* lp_JunkValues_JunkValues_defaultValueHeads___closed__25 = (const lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__25_value;
static const lean_ctor_object lp_JunkValues_JunkValues_defaultValueHeads___closed__26_value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__24_value),LEAN_SCALAR_PTR_LITERAL(245, 188, 225, 225, 165, 5, 251, 132)}};
static const lean_ctor_object lp_JunkValues_JunkValues_defaultValueHeads___closed__26_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__26_value_aux_0),((lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__25_value),LEAN_SCALAR_PTR_LITERAL(90, 150, 134, 113, 145, 38, 173, 251)}};
static const lean_object* lp_JunkValues_JunkValues_defaultValueHeads___closed__26 = (const lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__26_value;
static const lean_string_object lp_JunkValues_JunkValues_defaultValueHeads___closed__27_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 14, .m_capacity = 14, .m_length = 13, .m_data = "EmptyRelation"};
static const lean_object* lp_JunkValues_JunkValues_defaultValueHeads___closed__27 = (const lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__27_value;
static const lean_ctor_object lp_JunkValues_JunkValues_defaultValueHeads___closed__28_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__27_value),LEAN_SCALAR_PTR_LITERAL(222, 58, 198, 81, 67, 242, 218, 69)}};
static const lean_object* lp_JunkValues_JunkValues_defaultValueHeads___closed__28 = (const lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__28_value;
static const lean_array_object lp_JunkValues_JunkValues_defaultValueHeads___closed__29_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*10, .m_other = 0, .m_tag = 246}, .m_size = 10, .m_capacity = 10, .m_data = {((lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__2_value),((lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__5_value),((lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__8_value),((lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__11_value),((lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__14_value),((lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__17_value),((lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__20_value),((lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__23_value),((lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__26_value),((lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__28_value)}};
static const lean_object* lp_JunkValues_JunkValues_defaultValueHeads___closed__29 = (const lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__29_value;
LEAN_EXPORT const lean_object* lp_JunkValues_JunkValues_defaultValueHeads = (const lean_object*)&lp_JunkValues_JunkValues_defaultValueHeads___closed__29_value;
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_conclusionOf(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_conclusionOf___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_headConst_x3f(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_headConst_x3f___boxed(lean_object*);
LEAN_EXPORT uint8_t lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0_spec__0___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0_spec__0___redArg___boxed(lean_object*, lean_object*);
static lean_once_cell_t lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0___redArg___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static uint64_t lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0___redArg___closed__0;
LEAN_EXPORT uint8_t lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0___redArg___boxed(lean_object*, lean_object*);
static const lean_string_object lp_JunkValues_JunkValues_looksLikeRule___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "Eq"};
static const lean_object* lp_JunkValues_JunkValues_looksLikeRule___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_looksLikeRule___closed__0_value;
static const lean_ctor_object lp_JunkValues_JunkValues_looksLikeRule___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_looksLikeRule___closed__0_value),LEAN_SCALAR_PTR_LITERAL(143, 37, 101, 248, 9, 246, 191, 223)}};
static const lean_object* lp_JunkValues_JunkValues_looksLikeRule___closed__1 = (const lean_object*)&lp_JunkValues_JunkValues_looksLikeRule___closed__1_value;
LEAN_EXPORT uint8_t lp_JunkValues_JunkValues_looksLikeRule(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_looksLikeRule___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0_spec__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0_spec__0___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_JunkValues_JunkValues_DiscoveryScope_admits(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_DiscoveryScope_admits___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_discoverRules___lam__0(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_discoverRules___lam__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00__private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_discoverRules_spec__0_spec__0_spec__1_spec__5___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_discoverRules_spec__0_spec__0_spec__1___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_discoverRules_spec__0_spec__0___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_discoverRules_spec__0___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00JunkValues_discoverRules_spec__3(lean_object*, size_t, size_t, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00JunkValues_discoverRules_spec__3___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4___redArg___lam__0(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4___redArg___lam__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Lean_Data_PersistentHashMap_0__Lean_PersistentHashMap_foldlMAux_traverse___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9_spec__12___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Lean_Data_PersistentHashMap_0__Lean_PersistentHashMap_foldlMAux_traverse___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9_spec__12___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9_spec__11___redArg(lean_object*, lean_object*, size_t, size_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9_spec__11___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__3___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__3___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__5___redArg(lean_object*, lean_object*, size_t, size_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__5___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_discoverRules_spec__1___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 1, .m_capacity = 1, .m_length = 0, .m_data = ""};
static const lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_discoverRules_spec__1___closed__0 = (const lean_object*)&lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_discoverRules_spec__1___closed__0_value;
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_discoverRules_spec__1(lean_object*, lean_object*, size_t, size_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_discoverRules_spec__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_array_object lp_JunkValues_JunkValues_discoverRules___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* lp_JunkValues_JunkValues_discoverRules___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_discoverRules___closed__0_value;
static const lean_array_object lp_JunkValues_JunkValues_discoverRules___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* lp_JunkValues_JunkValues_discoverRules___closed__1 = (const lean_object*)&lp_JunkValues_JunkValues_discoverRules___closed__1_value;
static lean_once_cell_t lp_JunkValues_JunkValues_discoverRules___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_discoverRules___closed__2;
static lean_once_cell_t lp_JunkValues_JunkValues_discoverRules___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_discoverRules___closed__3;
static lean_once_cell_t lp_JunkValues_JunkValues_discoverRules___closed__4_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_discoverRules___closed__4;
static lean_once_cell_t lp_JunkValues_JunkValues_discoverRules___closed__5_once = LEAN_ONCE_CELL_INITIALIZER;
static uint8_t lp_JunkValues_JunkValues_discoverRules___closed__5;
static lean_once_cell_t lp_JunkValues_JunkValues_discoverRules___closed__6_once = LEAN_ONCE_CELL_INITIALIZER;
static uint8_t lp_JunkValues_JunkValues_discoverRules___closed__6;
static lean_once_cell_t lp_JunkValues_JunkValues_discoverRules___closed__7_once = LEAN_ONCE_CELL_INITIALIZER;
static size_t lp_JunkValues_JunkValues_discoverRules___closed__7;
static lean_once_cell_t lp_JunkValues_JunkValues_discoverRules___closed__8_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_discoverRules___closed__8;
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_discoverRules(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_discoverRules___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_discoverRules_spec__0(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_discoverRules_spec__0_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__3(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__3___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__5(lean_object*, lean_object*, lean_object*, size_t, size_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__5___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_discoverRules_spec__0_spec__0_spec__1(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00__private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_discoverRules_spec__0_spec__0_spec__1_spec__5(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9_spec__11(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, size_t, size_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9_spec__11___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Lean_Data_PersistentHashMap_0__Lean_PersistentHashMap_foldlMAux_traverse___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9_spec__12(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Lean_Data_PersistentHashMap_0__Lean_PersistentHashMap_foldlMAux_traverse___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9_spec__12___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_conclusionOf(lean_object* v_x_72_){
_start:
{
switch(lean_obj_tag(v_x_72_))
{
case 7:
{
lean_object* v_body_73_; 
v_body_73_ = lean_ctor_get(v_x_72_, 2);
v_x_72_ = v_body_73_;
goto _start;
}
case 10:
{
lean_object* v_expr_75_; 
v_expr_75_ = lean_ctor_get(v_x_72_, 1);
v_x_72_ = v_expr_75_;
goto _start;
}
default: 
{
lean_inc_ref(v_x_72_);
return v_x_72_;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_conclusionOf___boxed(lean_object* v_x_77_){
_start:
{
lean_object* v_res_78_; 
v_res_78_ = lp_JunkValues_JunkValues_conclusionOf(v_x_77_);
lean_dec_ref(v_x_77_);
return v_res_78_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_headConst_x3f(lean_object* v_e_79_){
_start:
{
lean_object* v___x_80_; 
v___x_80_ = l_Lean_Expr_getAppFn(v_e_79_);
if (lean_obj_tag(v___x_80_) == 4)
{
lean_object* v_declName_81_; lean_object* v___x_82_; 
v_declName_81_ = lean_ctor_get(v___x_80_, 0);
lean_inc(v_declName_81_);
lean_dec_ref_known(v___x_80_, 2);
v___x_82_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_82_, 0, v_declName_81_);
return v___x_82_;
}
else
{
lean_object* v___x_83_; 
lean_dec_ref(v___x_80_);
v___x_83_ = lean_box(0);
return v___x_83_;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_headConst_x3f___boxed(lean_object* v_e_84_){
_start:
{
lean_object* v_res_85_; 
v_res_85_ = lp_JunkValues_JunkValues_headConst_x3f(v_e_84_);
lean_dec_ref(v_e_84_);
return v_res_85_;
}
}
LEAN_EXPORT uint8_t lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0_spec__0___redArg(lean_object* v_a_86_, lean_object* v_x_87_){
_start:
{
if (lean_obj_tag(v_x_87_) == 0)
{
uint8_t v___x_88_; 
v___x_88_ = 0;
return v___x_88_;
}
else
{
lean_object* v_key_89_; lean_object* v_tail_90_; uint8_t v___x_91_; 
v_key_89_ = lean_ctor_get(v_x_87_, 0);
v_tail_90_ = lean_ctor_get(v_x_87_, 2);
v___x_91_ = lean_name_eq(v_key_89_, v_a_86_);
if (v___x_91_ == 0)
{
v_x_87_ = v_tail_90_;
goto _start;
}
else
{
return v___x_91_;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0_spec__0___redArg___boxed(lean_object* v_a_93_, lean_object* v_x_94_){
_start:
{
uint8_t v_res_95_; lean_object* v_r_96_; 
v_res_95_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0_spec__0___redArg(v_a_93_, v_x_94_);
lean_dec(v_x_94_);
lean_dec(v_a_93_);
v_r_96_ = lean_box(v_res_95_);
return v_r_96_;
}
}
static uint64_t _init_lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0___redArg___closed__0(void){
_start:
{
lean_object* v___x_97_; uint64_t v___x_98_; 
v___x_97_ = lean_unsigned_to_nat(1723u);
v___x_98_ = lean_uint64_of_nat(v___x_97_);
return v___x_98_;
}
}
LEAN_EXPORT uint8_t lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0___redArg(lean_object* v_m_99_, lean_object* v_a_100_){
_start:
{
lean_object* v_buckets_101_; lean_object* v___x_102_; uint64_t v___y_104_; 
v_buckets_101_ = lean_ctor_get(v_m_99_, 1);
v___x_102_ = lean_array_get_size(v_buckets_101_);
if (lean_obj_tag(v_a_100_) == 0)
{
uint64_t v___x_118_; 
v___x_118_ = lean_uint64_once(&lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0___redArg___closed__0, &lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0___redArg___closed__0_once, _init_lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0___redArg___closed__0);
v___y_104_ = v___x_118_;
goto v___jp_103_;
}
else
{
uint64_t v_hash_119_; 
v_hash_119_ = lean_ctor_get_uint64(v_a_100_, sizeof(void*)*2);
v___y_104_ = v_hash_119_;
goto v___jp_103_;
}
v___jp_103_:
{
uint64_t v___x_105_; uint64_t v___x_106_; uint64_t v_fold_107_; uint64_t v___x_108_; uint64_t v___x_109_; uint64_t v___x_110_; size_t v___x_111_; size_t v___x_112_; size_t v___x_113_; size_t v___x_114_; size_t v___x_115_; lean_object* v___x_116_; uint8_t v___x_117_; 
v___x_105_ = 32ULL;
v___x_106_ = lean_uint64_shift_right(v___y_104_, v___x_105_);
v_fold_107_ = lean_uint64_xor(v___y_104_, v___x_106_);
v___x_108_ = 16ULL;
v___x_109_ = lean_uint64_shift_right(v_fold_107_, v___x_108_);
v___x_110_ = lean_uint64_xor(v_fold_107_, v___x_109_);
v___x_111_ = lean_uint64_to_usize(v___x_110_);
v___x_112_ = lean_usize_of_nat(v___x_102_);
v___x_113_ = ((size_t)1ULL);
v___x_114_ = lean_usize_sub(v___x_112_, v___x_113_);
v___x_115_ = lean_usize_land(v___x_111_, v___x_114_);
v___x_116_ = lean_array_uget_borrowed(v_buckets_101_, v___x_115_);
v___x_117_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0_spec__0___redArg(v_a_100_, v___x_116_);
return v___x_117_;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0___redArg___boxed(lean_object* v_m_120_, lean_object* v_a_121_){
_start:
{
uint8_t v_res_122_; lean_object* v_r_123_; 
v_res_122_ = lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0___redArg(v_m_120_, v_a_121_);
lean_dec(v_a_121_);
lean_dec_ref(v_m_120_);
v_r_123_ = lean_box(v_res_122_);
return v_r_123_;
}
}
LEAN_EXPORT uint8_t lp_JunkValues_JunkValues_looksLikeRule(lean_object* v_defaults_127_, lean_object* v_type_128_){
_start:
{
lean_object* v___x_129_; lean_object* v___x_130_; lean_object* v___x_131_; uint8_t v___x_132_; 
v___x_129_ = lp_JunkValues_JunkValues_conclusionOf(v_type_128_);
v___x_130_ = ((lean_object*)(lp_JunkValues_JunkValues_looksLikeRule___closed__1));
v___x_131_ = lean_unsigned_to_nat(3u);
v___x_132_ = l_Lean_Expr_isAppOfArity(v___x_129_, v___x_130_, v___x_131_);
if (v___x_132_ == 0)
{
lean_dec_ref(v___x_129_);
return v___x_132_;
}
else
{
lean_object* v___x_133_; lean_object* v___x_134_; lean_object* v___x_135_; 
v___x_133_ = l_Lean_Expr_appFn_x21(v___x_129_);
v___x_134_ = l_Lean_Expr_appArg_x21(v___x_133_);
lean_dec_ref(v___x_133_);
v___x_135_ = lp_JunkValues_JunkValues_headConst_x3f(v___x_134_);
lean_dec_ref(v___x_134_);
if (lean_obj_tag(v___x_135_) == 0)
{
uint8_t v___x_136_; 
lean_dec_ref(v___x_129_);
v___x_136_ = 0;
return v___x_136_;
}
else
{
lean_object* v___x_137_; lean_object* v___x_138_; 
lean_dec_ref_known(v___x_135_, 1);
v___x_137_ = l_Lean_Expr_appArg_x21(v___x_129_);
lean_dec_ref(v___x_129_);
v___x_138_ = lp_JunkValues_JunkValues_headConst_x3f(v___x_137_);
lean_dec_ref(v___x_137_);
if (lean_obj_tag(v___x_138_) == 0)
{
uint8_t v___x_139_; 
v___x_139_ = 0;
return v___x_139_;
}
else
{
lean_object* v_val_140_; uint8_t v___x_141_; 
v_val_140_ = lean_ctor_get(v___x_138_, 0);
lean_inc(v_val_140_);
lean_dec_ref_known(v___x_138_, 1);
v___x_141_ = lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0___redArg(v_defaults_127_, v_val_140_);
lean_dec(v_val_140_);
return v___x_141_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_looksLikeRule___boxed(lean_object* v_defaults_142_, lean_object* v_type_143_){
_start:
{
uint8_t v_res_144_; lean_object* v_r_145_; 
v_res_144_ = lp_JunkValues_JunkValues_looksLikeRule(v_defaults_142_, v_type_143_);
lean_dec_ref(v_type_143_);
lean_dec_ref(v_defaults_142_);
v_r_145_ = lean_box(v_res_144_);
return v_r_145_;
}
}
LEAN_EXPORT uint8_t lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0(lean_object* v_00_u03b2_146_, lean_object* v_m_147_, lean_object* v_a_148_){
_start:
{
uint8_t v___x_149_; 
v___x_149_ = lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0___redArg(v_m_147_, v_a_148_);
return v___x_149_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0___boxed(lean_object* v_00_u03b2_150_, lean_object* v_m_151_, lean_object* v_a_152_){
_start:
{
uint8_t v_res_153_; lean_object* v_r_154_; 
v_res_153_ = lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0(v_00_u03b2_150_, v_m_151_, v_a_152_);
lean_dec(v_a_152_);
lean_dec_ref(v_m_151_);
v_r_154_ = lean_box(v_res_153_);
return v_r_154_;
}
}
LEAN_EXPORT uint8_t lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0_spec__0(lean_object* v_00_u03b2_155_, lean_object* v_a_156_, lean_object* v_x_157_){
_start:
{
uint8_t v___x_158_; 
v___x_158_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0_spec__0___redArg(v_a_156_, v_x_157_);
return v___x_158_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0_spec__0___boxed(lean_object* v_00_u03b2_159_, lean_object* v_a_160_, lean_object* v_x_161_){
_start:
{
uint8_t v_res_162_; lean_object* v_r_163_; 
v_res_162_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0_spec__0(v_00_u03b2_159_, v_a_160_, v_x_161_);
lean_dec(v_x_161_);
lean_dec(v_a_160_);
v_r_163_ = lean_box(v_res_162_);
return v_r_163_;
}
}
LEAN_EXPORT uint8_t lp_JunkValues_JunkValues_DiscoveryScope_admits(lean_object* v_scope_164_, lean_object* v_env_165_, lean_object* v_name_166_){
_start:
{
lean_object* v_moduleprefix_x3f_167_; uint8_t v_skipInternal_168_; uint8_t v___y_170_; uint8_t v___y_182_; 
v_moduleprefix_x3f_167_ = lean_ctor_get(v_scope_164_, 0);
v_skipInternal_168_ = lean_ctor_get_uint8(v_scope_164_, sizeof(void*)*1);
if (v_skipInternal_168_ == 0)
{
v___y_170_ = v_skipInternal_168_;
goto v___jp_169_;
}
else
{
uint8_t v___x_185_; 
v___x_185_ = l_Lean_Name_isInternal(v_name_166_);
if (v___x_185_ == 0)
{
uint8_t v___x_186_; 
v___x_186_ = l_Lean_Name_isImplementationDetail(v_name_166_);
v___y_182_ = v___x_186_;
goto v___jp_181_;
}
else
{
v___y_182_ = v___x_185_;
goto v___jp_181_;
}
}
v___jp_169_:
{
uint8_t v___x_171_; 
v___x_171_ = 1;
if (lean_obj_tag(v_moduleprefix_x3f_167_) == 0)
{
return v___x_171_;
}
else
{
lean_object* v_val_172_; lean_object* v___x_173_; 
v_val_172_ = lean_ctor_get(v_moduleprefix_x3f_167_, 0);
v___x_173_ = l_Lean_Environment_getModuleIdxFor_x3f(v_env_165_, v_name_166_);
if (lean_obj_tag(v___x_173_) == 0)
{
return v___x_171_;
}
else
{
lean_object* v_val_174_; lean_object* v___x_175_; lean_object* v___x_176_; lean_object* v___x_177_; uint8_t v___x_178_; 
v_val_174_ = lean_ctor_get(v___x_173_, 0);
lean_inc(v_val_174_);
lean_dec_ref_known(v___x_173_, 1);
v___x_175_ = l_Lean_Environment_header(v_env_165_);
v___x_176_ = l_Lean_EnvironmentHeader_moduleNames(v___x_175_);
v___x_177_ = lean_array_get_size(v___x_176_);
v___x_178_ = lean_nat_dec_lt(v_val_174_, v___x_177_);
if (v___x_178_ == 0)
{
lean_dec_ref(v___x_176_);
lean_dec(v_val_174_);
return v___y_170_;
}
else
{
lean_object* v___x_179_; uint8_t v___x_180_; 
v___x_179_ = lean_array_fget(v___x_176_, v_val_174_);
lean_dec(v_val_174_);
lean_dec_ref(v___x_176_);
v___x_180_ = l_Lean_Name_isPrefixOf(v_val_172_, v___x_179_);
lean_dec(v___x_179_);
return v___x_180_;
}
}
}
}
v___jp_181_:
{
if (v___y_182_ == 0)
{
uint8_t v___x_183_; 
v___x_183_ = l_Lean_isPrivateName(v_name_166_);
if (v___x_183_ == 0)
{
v___y_170_ = v___x_183_;
goto v___jp_169_;
}
else
{
return v___y_182_;
}
}
else
{
uint8_t v___x_184_; 
v___x_184_ = 0;
return v___x_184_;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_DiscoveryScope_admits___boxed(lean_object* v_scope_187_, lean_object* v_env_188_, lean_object* v_name_189_){
_start:
{
uint8_t v_res_190_; lean_object* v_r_191_; 
v_res_190_ = lp_JunkValues_JunkValues_DiscoveryScope_admits(v_scope_187_, v_env_188_, v_name_189_);
lean_dec(v_name_189_);
lean_dec_ref(v_env_188_);
lean_dec_ref(v_scope_187_);
v_r_191_ = lean_box(v_res_190_);
return v_r_191_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_discoverRules___lam__0(lean_object* v_scope_192_, lean_object* v_env_193_, lean_object* v___y_194_, lean_object* v_x_195_, lean_object* v_y_196_, lean_object* v___y_197_, lean_object* v___y_198_, lean_object* v___y_199_, lean_object* v___y_200_, lean_object* v___y_201_){
_start:
{
lean_object* v_a_204_; 
switch(lean_obj_tag(v_y_196_))
{
case 2:
{
goto v___jp_209_;
}
case 0:
{
goto v___jp_209_;
}
default: 
{
lean_dec(v_x_195_);
v_a_204_ = v___y_197_;
goto v___jp_203_;
}
}
v___jp_203_:
{
lean_object* v___x_205_; lean_object* v___x_206_; lean_object* v___x_207_; lean_object* v___x_208_; 
v___x_205_ = lean_box(0);
v___x_206_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_206_, 0, v___x_205_);
lean_ctor_set(v___x_206_, 1, v_a_204_);
v___x_207_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_207_, 0, v___x_206_);
v___x_208_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_208_, 0, v___x_207_);
return v___x_208_;
}
v___jp_209_:
{
uint8_t v___x_210_; 
v___x_210_ = lp_JunkValues_JunkValues_DiscoveryScope_admits(v_scope_192_, v_env_193_, v_x_195_);
if (v___x_210_ == 0)
{
lean_dec(v_x_195_);
v_a_204_ = v___y_197_;
goto v___jp_203_;
}
else
{
lean_object* v___x_211_; uint8_t v___x_212_; 
v___x_211_ = l_Lean_ConstantInfo_type(v_y_196_);
v___x_212_ = lp_JunkValues_JunkValues_looksLikeRule(v___y_194_, v___x_211_);
lean_dec_ref(v___x_211_);
if (v___x_212_ == 0)
{
lean_dec(v_x_195_);
v_a_204_ = v___y_197_;
goto v___jp_203_;
}
else
{
lean_object* v___x_213_; 
v___x_213_ = lean_array_push(v___y_197_, v_x_195_);
v_a_204_ = v___x_213_;
goto v___jp_203_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_discoverRules___lam__0___boxed(lean_object* v_scope_214_, lean_object* v_env_215_, lean_object* v___y_216_, lean_object* v_x_217_, lean_object* v_y_218_, lean_object* v___y_219_, lean_object* v___y_220_, lean_object* v___y_221_, lean_object* v___y_222_, lean_object* v___y_223_, lean_object* v___y_224_){
_start:
{
lean_object* v_res_225_; 
v_res_225_ = lp_JunkValues_JunkValues_discoverRules___lam__0(v_scope_214_, v_env_215_, v___y_216_, v_x_217_, v_y_218_, v___y_219_, v___y_220_, v___y_221_, v___y_222_, v___y_223_);
lean_dec(v___y_223_);
lean_dec_ref(v___y_222_);
lean_dec(v___y_221_);
lean_dec_ref(v___y_220_);
lean_dec_ref(v_y_218_);
lean_dec_ref(v___y_216_);
lean_dec_ref(v_env_215_);
lean_dec_ref(v_scope_214_);
return v_res_225_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00__private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_discoverRules_spec__0_spec__0_spec__1_spec__5___redArg(lean_object* v_x_226_, lean_object* v_x_227_){
_start:
{
if (lean_obj_tag(v_x_227_) == 0)
{
return v_x_226_;
}
else
{
lean_object* v_key_228_; lean_object* v_value_229_; lean_object* v_tail_230_; lean_object* v___x_232_; uint8_t v_isShared_233_; uint8_t v_isSharedCheck_256_; 
v_key_228_ = lean_ctor_get(v_x_227_, 0);
v_value_229_ = lean_ctor_get(v_x_227_, 1);
v_tail_230_ = lean_ctor_get(v_x_227_, 2);
v_isSharedCheck_256_ = !lean_is_exclusive(v_x_227_);
if (v_isSharedCheck_256_ == 0)
{
v___x_232_ = v_x_227_;
v_isShared_233_ = v_isSharedCheck_256_;
goto v_resetjp_231_;
}
else
{
lean_inc(v_tail_230_);
lean_inc(v_value_229_);
lean_inc(v_key_228_);
lean_dec(v_x_227_);
v___x_232_ = lean_box(0);
v_isShared_233_ = v_isSharedCheck_256_;
goto v_resetjp_231_;
}
v_resetjp_231_:
{
lean_object* v___x_234_; uint64_t v___y_236_; 
v___x_234_ = lean_array_get_size(v_x_226_);
if (lean_obj_tag(v_key_228_) == 0)
{
uint64_t v___x_254_; 
v___x_254_ = lean_uint64_once(&lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0___redArg___closed__0, &lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0___redArg___closed__0_once, _init_lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0___redArg___closed__0);
v___y_236_ = v___x_254_;
goto v___jp_235_;
}
else
{
uint64_t v_hash_255_; 
v_hash_255_ = lean_ctor_get_uint64(v_key_228_, sizeof(void*)*2);
v___y_236_ = v_hash_255_;
goto v___jp_235_;
}
v___jp_235_:
{
uint64_t v___x_237_; uint64_t v___x_238_; uint64_t v_fold_239_; uint64_t v___x_240_; uint64_t v___x_241_; uint64_t v___x_242_; size_t v___x_243_; size_t v___x_244_; size_t v___x_245_; size_t v___x_246_; size_t v___x_247_; lean_object* v___x_248_; lean_object* v___x_250_; 
v___x_237_ = 32ULL;
v___x_238_ = lean_uint64_shift_right(v___y_236_, v___x_237_);
v_fold_239_ = lean_uint64_xor(v___y_236_, v___x_238_);
v___x_240_ = 16ULL;
v___x_241_ = lean_uint64_shift_right(v_fold_239_, v___x_240_);
v___x_242_ = lean_uint64_xor(v_fold_239_, v___x_241_);
v___x_243_ = lean_uint64_to_usize(v___x_242_);
v___x_244_ = lean_usize_of_nat(v___x_234_);
v___x_245_ = ((size_t)1ULL);
v___x_246_ = lean_usize_sub(v___x_244_, v___x_245_);
v___x_247_ = lean_usize_land(v___x_243_, v___x_246_);
v___x_248_ = lean_array_uget_borrowed(v_x_226_, v___x_247_);
lean_inc(v___x_248_);
if (v_isShared_233_ == 0)
{
lean_ctor_set(v___x_232_, 2, v___x_248_);
v___x_250_ = v___x_232_;
goto v_reusejp_249_;
}
else
{
lean_object* v_reuseFailAlloc_253_; 
v_reuseFailAlloc_253_ = lean_alloc_ctor(1, 3, 0);
lean_ctor_set(v_reuseFailAlloc_253_, 0, v_key_228_);
lean_ctor_set(v_reuseFailAlloc_253_, 1, v_value_229_);
lean_ctor_set(v_reuseFailAlloc_253_, 2, v___x_248_);
v___x_250_ = v_reuseFailAlloc_253_;
goto v_reusejp_249_;
}
v_reusejp_249_:
{
lean_object* v___x_251_; 
v___x_251_ = lean_array_uset(v_x_226_, v___x_247_, v___x_250_);
v_x_226_ = v___x_251_;
v_x_227_ = v_tail_230_;
goto _start;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_discoverRules_spec__0_spec__0_spec__1___redArg(lean_object* v_i_257_, lean_object* v_source_258_, lean_object* v_target_259_){
_start:
{
lean_object* v___x_260_; uint8_t v___x_261_; 
v___x_260_ = lean_array_get_size(v_source_258_);
v___x_261_ = lean_nat_dec_lt(v_i_257_, v___x_260_);
if (v___x_261_ == 0)
{
lean_dec_ref(v_source_258_);
lean_dec(v_i_257_);
return v_target_259_;
}
else
{
lean_object* v_es_262_; lean_object* v___x_263_; lean_object* v_source_264_; lean_object* v_target_265_; lean_object* v___x_266_; lean_object* v___x_267_; 
v_es_262_ = lean_array_fget(v_source_258_, v_i_257_);
v___x_263_ = lean_box(0);
v_source_264_ = lean_array_fset(v_source_258_, v_i_257_, v___x_263_);
v_target_265_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00__private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_discoverRules_spec__0_spec__0_spec__1_spec__5___redArg(v_target_259_, v_es_262_);
v___x_266_ = lean_unsigned_to_nat(1u);
v___x_267_ = lean_nat_add(v_i_257_, v___x_266_);
lean_dec(v_i_257_);
v_i_257_ = v___x_267_;
v_source_258_ = v_source_264_;
v_target_259_ = v_target_265_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_discoverRules_spec__0_spec__0___redArg(lean_object* v_data_269_){
_start:
{
lean_object* v___x_270_; lean_object* v___x_271_; lean_object* v_nbuckets_272_; lean_object* v___x_273_; lean_object* v___x_274_; lean_object* v___x_275_; lean_object* v___x_276_; 
v___x_270_ = lean_array_get_size(v_data_269_);
v___x_271_ = lean_unsigned_to_nat(2u);
v_nbuckets_272_ = lean_nat_mul(v___x_270_, v___x_271_);
v___x_273_ = lean_unsigned_to_nat(0u);
v___x_274_ = lean_box(0);
v___x_275_ = lean_mk_array(v_nbuckets_272_, v___x_274_);
v___x_276_ = lp_JunkValues___private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_discoverRules_spec__0_spec__0_spec__1___redArg(v___x_273_, v_data_269_, v___x_275_);
return v___x_276_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_discoverRules_spec__0___redArg(lean_object* v_m_277_, lean_object* v_a_278_, lean_object* v_b_279_){
_start:
{
lean_object* v_size_280_; lean_object* v_buckets_281_; lean_object* v___x_282_; uint64_t v___y_284_; 
v_size_280_ = lean_ctor_get(v_m_277_, 0);
v_buckets_281_ = lean_ctor_get(v_m_277_, 1);
v___x_282_ = lean_array_get_size(v_buckets_281_);
if (lean_obj_tag(v_a_278_) == 0)
{
uint64_t v___x_321_; 
v___x_321_ = lean_uint64_once(&lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0___redArg___closed__0, &lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0___redArg___closed__0_once, _init_lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0___redArg___closed__0);
v___y_284_ = v___x_321_;
goto v___jp_283_;
}
else
{
uint64_t v_hash_322_; 
v_hash_322_ = lean_ctor_get_uint64(v_a_278_, sizeof(void*)*2);
v___y_284_ = v_hash_322_;
goto v___jp_283_;
}
v___jp_283_:
{
uint64_t v___x_285_; uint64_t v___x_286_; uint64_t v_fold_287_; uint64_t v___x_288_; uint64_t v___x_289_; uint64_t v___x_290_; size_t v___x_291_; size_t v___x_292_; size_t v___x_293_; size_t v___x_294_; size_t v___x_295_; lean_object* v_bkt_296_; uint8_t v___x_297_; 
v___x_285_ = 32ULL;
v___x_286_ = lean_uint64_shift_right(v___y_284_, v___x_285_);
v_fold_287_ = lean_uint64_xor(v___y_284_, v___x_286_);
v___x_288_ = 16ULL;
v___x_289_ = lean_uint64_shift_right(v_fold_287_, v___x_288_);
v___x_290_ = lean_uint64_xor(v_fold_287_, v___x_289_);
v___x_291_ = lean_uint64_to_usize(v___x_290_);
v___x_292_ = lean_usize_of_nat(v___x_282_);
v___x_293_ = ((size_t)1ULL);
v___x_294_ = lean_usize_sub(v___x_292_, v___x_293_);
v___x_295_ = lean_usize_land(v___x_291_, v___x_294_);
v_bkt_296_ = lean_array_uget_borrowed(v_buckets_281_, v___x_295_);
v___x_297_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0_spec__0___redArg(v_a_278_, v_bkt_296_);
if (v___x_297_ == 0)
{
lean_object* v___x_299_; uint8_t v_isShared_300_; uint8_t v_isSharedCheck_318_; 
lean_inc_ref(v_buckets_281_);
lean_inc(v_size_280_);
v_isSharedCheck_318_ = !lean_is_exclusive(v_m_277_);
if (v_isSharedCheck_318_ == 0)
{
lean_object* v_unused_319_; lean_object* v_unused_320_; 
v_unused_319_ = lean_ctor_get(v_m_277_, 1);
lean_dec(v_unused_319_);
v_unused_320_ = lean_ctor_get(v_m_277_, 0);
lean_dec(v_unused_320_);
v___x_299_ = v_m_277_;
v_isShared_300_ = v_isSharedCheck_318_;
goto v_resetjp_298_;
}
else
{
lean_dec(v_m_277_);
v___x_299_ = lean_box(0);
v_isShared_300_ = v_isSharedCheck_318_;
goto v_resetjp_298_;
}
v_resetjp_298_:
{
lean_object* v___x_301_; lean_object* v_size_x27_302_; lean_object* v___x_303_; lean_object* v_buckets_x27_304_; lean_object* v___x_305_; lean_object* v___x_306_; lean_object* v___x_307_; lean_object* v___x_308_; lean_object* v___x_309_; uint8_t v___x_310_; 
v___x_301_ = lean_unsigned_to_nat(1u);
v_size_x27_302_ = lean_nat_add(v_size_280_, v___x_301_);
lean_dec(v_size_280_);
lean_inc(v_bkt_296_);
v___x_303_ = lean_alloc_ctor(1, 3, 0);
lean_ctor_set(v___x_303_, 0, v_a_278_);
lean_ctor_set(v___x_303_, 1, v_b_279_);
lean_ctor_set(v___x_303_, 2, v_bkt_296_);
v_buckets_x27_304_ = lean_array_uset(v_buckets_281_, v___x_295_, v___x_303_);
v___x_305_ = lean_unsigned_to_nat(4u);
v___x_306_ = lean_nat_mul(v_size_x27_302_, v___x_305_);
v___x_307_ = lean_unsigned_to_nat(3u);
v___x_308_ = lean_nat_div(v___x_306_, v___x_307_);
lean_dec(v___x_306_);
v___x_309_ = lean_array_get_size(v_buckets_x27_304_);
v___x_310_ = lean_nat_dec_le(v___x_308_, v___x_309_);
lean_dec(v___x_308_);
if (v___x_310_ == 0)
{
lean_object* v_val_311_; lean_object* v___x_313_; 
v_val_311_ = lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_discoverRules_spec__0_spec__0___redArg(v_buckets_x27_304_);
if (v_isShared_300_ == 0)
{
lean_ctor_set(v___x_299_, 1, v_val_311_);
lean_ctor_set(v___x_299_, 0, v_size_x27_302_);
v___x_313_ = v___x_299_;
goto v_reusejp_312_;
}
else
{
lean_object* v_reuseFailAlloc_314_; 
v_reuseFailAlloc_314_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_314_, 0, v_size_x27_302_);
lean_ctor_set(v_reuseFailAlloc_314_, 1, v_val_311_);
v___x_313_ = v_reuseFailAlloc_314_;
goto v_reusejp_312_;
}
v_reusejp_312_:
{
return v___x_313_;
}
}
else
{
lean_object* v___x_316_; 
if (v_isShared_300_ == 0)
{
lean_ctor_set(v___x_299_, 1, v_buckets_x27_304_);
lean_ctor_set(v___x_299_, 0, v_size_x27_302_);
v___x_316_ = v___x_299_;
goto v_reusejp_315_;
}
else
{
lean_object* v_reuseFailAlloc_317_; 
v_reuseFailAlloc_317_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_317_, 0, v_size_x27_302_);
lean_ctor_set(v_reuseFailAlloc_317_, 1, v_buckets_x27_304_);
v___x_316_ = v_reuseFailAlloc_317_;
goto v_reusejp_315_;
}
v_reusejp_315_:
{
return v___x_316_;
}
}
}
}
else
{
lean_dec(v_b_279_);
lean_dec(v_a_278_);
return v_m_277_;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00JunkValues_discoverRules_spec__3(lean_object* v_as_323_, size_t v_i_324_, size_t v_stop_325_, lean_object* v_b_326_){
_start:
{
uint8_t v___x_327_; 
v___x_327_ = lean_usize_dec_eq(v_i_324_, v_stop_325_);
if (v___x_327_ == 0)
{
lean_object* v___x_328_; lean_object* v___x_329_; lean_object* v___x_330_; size_t v___x_331_; size_t v___x_332_; 
v___x_328_ = lean_array_uget_borrowed(v_as_323_, v_i_324_);
v___x_329_ = lean_box(0);
lean_inc(v___x_328_);
v___x_330_ = lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_discoverRules_spec__0___redArg(v_b_326_, v___x_328_, v___x_329_);
v___x_331_ = ((size_t)1ULL);
v___x_332_ = lean_usize_add(v_i_324_, v___x_331_);
v_i_324_ = v___x_332_;
v_b_326_ = v___x_330_;
goto _start;
}
else
{
return v_b_326_;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00JunkValues_discoverRules_spec__3___boxed(lean_object* v_as_334_, lean_object* v_i_335_, lean_object* v_stop_336_, lean_object* v_b_337_){
_start:
{
size_t v_i_boxed_338_; size_t v_stop_boxed_339_; lean_object* v_res_340_; 
v_i_boxed_338_ = lean_unbox_usize(v_i_335_);
lean_dec(v_i_335_);
v_stop_boxed_339_ = lean_unbox_usize(v_stop_336_);
lean_dec(v_stop_336_);
v_res_340_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00JunkValues_discoverRules_spec__3(v_as_334_, v_i_boxed_338_, v_stop_boxed_339_, v_b_337_);
lean_dec_ref(v_as_334_);
return v_res_340_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4___redArg___lam__0(lean_object* v_f_341_, lean_object* v_x_342_, lean_object* v___y_343_, lean_object* v___y_344_, lean_object* v___y_345_, lean_object* v___y_346_, lean_object* v___y_347_, lean_object* v___y_348_, lean_object* v___y_349_){
_start:
{
lean_object* v___x_351_; 
lean_inc(v___y_349_);
lean_inc_ref(v___y_348_);
lean_inc(v___y_347_);
lean_inc_ref(v___y_346_);
v___x_351_ = lean_apply_8(v_f_341_, v___y_343_, v___y_344_, v___y_345_, v___y_346_, v___y_347_, v___y_348_, v___y_349_, lean_box(0));
return v___x_351_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4___redArg___lam__0___boxed(lean_object* v_f_352_, lean_object* v_x_353_, lean_object* v___y_354_, lean_object* v___y_355_, lean_object* v___y_356_, lean_object* v___y_357_, lean_object* v___y_358_, lean_object* v___y_359_, lean_object* v___y_360_, lean_object* v___y_361_){
_start:
{
lean_object* v_res_362_; 
v_res_362_ = lp_JunkValues_Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4___redArg___lam__0(v_f_352_, v_x_353_, v___y_354_, v___y_355_, v___y_356_, v___y_357_, v___y_358_, v___y_359_, v___y_360_);
lean_dec(v___y_360_);
lean_dec_ref(v___y_359_);
lean_dec(v___y_358_);
lean_dec_ref(v___y_357_);
return v_res_362_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Lean_Data_PersistentHashMap_0__Lean_PersistentHashMap_foldlMAux_traverse___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9_spec__12___redArg(lean_object* v_f_363_, lean_object* v_keys_364_, lean_object* v_vals_365_, lean_object* v_i_366_, lean_object* v_acc_367_, lean_object* v___y_368_, lean_object* v___y_369_, lean_object* v___y_370_, lean_object* v___y_371_, lean_object* v___y_372_){
_start:
{
lean_object* v___x_374_; uint8_t v___x_375_; 
v___x_374_ = lean_array_get_size(v_keys_364_);
v___x_375_ = lean_nat_dec_lt(v_i_366_, v___x_374_);
if (v___x_375_ == 0)
{
lean_object* v___x_376_; lean_object* v___x_377_; lean_object* v___x_378_; 
lean_dec(v_i_366_);
lean_dec_ref(v_f_363_);
v___x_376_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_376_, 0, v_acc_367_);
lean_ctor_set(v___x_376_, 1, v___y_368_);
v___x_377_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_377_, 0, v___x_376_);
v___x_378_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_378_, 0, v___x_377_);
return v___x_378_;
}
else
{
lean_object* v_k_379_; lean_object* v_v_380_; lean_object* v___x_381_; 
v_k_379_ = lean_array_fget_borrowed(v_keys_364_, v_i_366_);
v_v_380_ = lean_array_fget_borrowed(v_vals_365_, v_i_366_);
lean_inc_ref(v_f_363_);
lean_inc(v___y_372_);
lean_inc_ref(v___y_371_);
lean_inc(v___y_370_);
lean_inc_ref(v___y_369_);
lean_inc(v_v_380_);
lean_inc(v_k_379_);
v___x_381_ = lean_apply_9(v_f_363_, v_acc_367_, v_k_379_, v_v_380_, v___y_368_, v___y_369_, v___y_370_, v___y_371_, v___y_372_, lean_box(0));
if (lean_obj_tag(v___x_381_) == 0)
{
lean_object* v_a_382_; 
v_a_382_ = lean_ctor_get(v___x_381_, 0);
lean_inc(v_a_382_);
if (lean_obj_tag(v_a_382_) == 0)
{
lean_dec_ref_known(v_a_382_, 1);
lean_dec(v_i_366_);
lean_dec_ref(v_f_363_);
return v___x_381_;
}
else
{
lean_object* v_a_383_; lean_object* v_fst_384_; lean_object* v_snd_385_; lean_object* v___x_386_; lean_object* v___x_387_; 
lean_dec_ref_known(v___x_381_, 1);
v_a_383_ = lean_ctor_get(v_a_382_, 0);
lean_inc(v_a_383_);
lean_dec_ref_known(v_a_382_, 1);
v_fst_384_ = lean_ctor_get(v_a_383_, 0);
lean_inc(v_fst_384_);
v_snd_385_ = lean_ctor_get(v_a_383_, 1);
lean_inc(v_snd_385_);
lean_dec(v_a_383_);
v___x_386_ = lean_unsigned_to_nat(1u);
v___x_387_ = lean_nat_add(v_i_366_, v___x_386_);
lean_dec(v_i_366_);
v_i_366_ = v___x_387_;
v_acc_367_ = v_fst_384_;
v___y_368_ = v_snd_385_;
goto _start;
}
}
else
{
lean_dec(v_i_366_);
lean_dec_ref(v_f_363_);
return v___x_381_;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Lean_Data_PersistentHashMap_0__Lean_PersistentHashMap_foldlMAux_traverse___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9_spec__12___redArg___boxed(lean_object* v_f_389_, lean_object* v_keys_390_, lean_object* v_vals_391_, lean_object* v_i_392_, lean_object* v_acc_393_, lean_object* v___y_394_, lean_object* v___y_395_, lean_object* v___y_396_, lean_object* v___y_397_, lean_object* v___y_398_, lean_object* v___y_399_){
_start:
{
lean_object* v_res_400_; 
v_res_400_ = lp_JunkValues___private_Lean_Data_PersistentHashMap_0__Lean_PersistentHashMap_foldlMAux_traverse___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9_spec__12___redArg(v_f_389_, v_keys_390_, v_vals_391_, v_i_392_, v_acc_393_, v___y_394_, v___y_395_, v___y_396_, v___y_397_, v___y_398_);
lean_dec(v___y_398_);
lean_dec_ref(v___y_397_);
lean_dec(v___y_396_);
lean_dec_ref(v___y_395_);
lean_dec_ref(v_vals_391_);
lean_dec_ref(v_keys_390_);
return v_res_400_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9___redArg(lean_object* v_f_401_, lean_object* v_x_402_, lean_object* v_x_403_, lean_object* v___y_404_, lean_object* v___y_405_, lean_object* v___y_406_, lean_object* v___y_407_, lean_object* v___y_408_){
_start:
{
if (lean_obj_tag(v_x_402_) == 0)
{
lean_object* v_es_410_; lean_object* v___x_412_; uint8_t v_isShared_413_; uint8_t v_isSharedCheck_434_; 
v_es_410_ = lean_ctor_get(v_x_402_, 0);
v_isSharedCheck_434_ = !lean_is_exclusive(v_x_402_);
if (v_isSharedCheck_434_ == 0)
{
v___x_412_ = v_x_402_;
v_isShared_413_ = v_isSharedCheck_434_;
goto v_resetjp_411_;
}
else
{
lean_inc(v_es_410_);
lean_dec(v_x_402_);
v___x_412_ = lean_box(0);
v_isShared_413_ = v_isSharedCheck_434_;
goto v_resetjp_411_;
}
v_resetjp_411_:
{
lean_object* v___x_414_; lean_object* v___x_415_; uint8_t v___x_416_; 
v___x_414_ = lean_unsigned_to_nat(0u);
v___x_415_ = lean_array_get_size(v_es_410_);
v___x_416_ = lean_nat_dec_lt(v___x_414_, v___x_415_);
if (v___x_416_ == 0)
{
lean_object* v___x_417_; lean_object* v___x_419_; 
lean_dec_ref(v_es_410_);
lean_dec_ref(v_f_401_);
v___x_417_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_417_, 0, v_x_403_);
lean_ctor_set(v___x_417_, 1, v___y_404_);
if (v_isShared_413_ == 0)
{
lean_ctor_set_tag(v___x_412_, 1);
lean_ctor_set(v___x_412_, 0, v___x_417_);
v___x_419_ = v___x_412_;
goto v_reusejp_418_;
}
else
{
lean_object* v_reuseFailAlloc_421_; 
v_reuseFailAlloc_421_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_421_, 0, v___x_417_);
v___x_419_ = v_reuseFailAlloc_421_;
goto v_reusejp_418_;
}
v_reusejp_418_:
{
lean_object* v___x_420_; 
v___x_420_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_420_, 0, v___x_419_);
return v___x_420_;
}
}
else
{
uint8_t v___x_422_; 
v___x_422_ = lean_nat_dec_le(v___x_415_, v___x_415_);
if (v___x_422_ == 0)
{
if (v___x_416_ == 0)
{
lean_object* v___x_423_; lean_object* v___x_425_; 
lean_dec_ref(v_es_410_);
lean_dec_ref(v_f_401_);
v___x_423_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_423_, 0, v_x_403_);
lean_ctor_set(v___x_423_, 1, v___y_404_);
if (v_isShared_413_ == 0)
{
lean_ctor_set_tag(v___x_412_, 1);
lean_ctor_set(v___x_412_, 0, v___x_423_);
v___x_425_ = v___x_412_;
goto v_reusejp_424_;
}
else
{
lean_object* v_reuseFailAlloc_427_; 
v_reuseFailAlloc_427_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_427_, 0, v___x_423_);
v___x_425_ = v_reuseFailAlloc_427_;
goto v_reusejp_424_;
}
v_reusejp_424_:
{
lean_object* v___x_426_; 
v___x_426_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_426_, 0, v___x_425_);
return v___x_426_;
}
}
else
{
size_t v___x_428_; size_t v___x_429_; lean_object* v___x_430_; 
lean_del_object(v___x_412_);
v___x_428_ = ((size_t)0ULL);
v___x_429_ = lean_usize_of_nat(v___x_415_);
v___x_430_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9_spec__11___redArg(v_f_401_, v_es_410_, v___x_428_, v___x_429_, v_x_403_, v___y_404_, v___y_405_, v___y_406_, v___y_407_, v___y_408_);
lean_dec_ref(v_es_410_);
return v___x_430_;
}
}
else
{
size_t v___x_431_; size_t v___x_432_; lean_object* v___x_433_; 
lean_del_object(v___x_412_);
v___x_431_ = ((size_t)0ULL);
v___x_432_ = lean_usize_of_nat(v___x_415_);
v___x_433_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9_spec__11___redArg(v_f_401_, v_es_410_, v___x_431_, v___x_432_, v_x_403_, v___y_404_, v___y_405_, v___y_406_, v___y_407_, v___y_408_);
lean_dec_ref(v_es_410_);
return v___x_433_;
}
}
}
}
else
{
lean_object* v_ks_435_; lean_object* v_vs_436_; lean_object* v___x_437_; lean_object* v___x_438_; 
v_ks_435_ = lean_ctor_get(v_x_402_, 0);
lean_inc_ref(v_ks_435_);
v_vs_436_ = lean_ctor_get(v_x_402_, 1);
lean_inc_ref(v_vs_436_);
lean_dec_ref_known(v_x_402_, 2);
v___x_437_ = lean_unsigned_to_nat(0u);
v___x_438_ = lp_JunkValues___private_Lean_Data_PersistentHashMap_0__Lean_PersistentHashMap_foldlMAux_traverse___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9_spec__12___redArg(v_f_401_, v_ks_435_, v_vs_436_, v___x_437_, v_x_403_, v___y_404_, v___y_405_, v___y_406_, v___y_407_, v___y_408_);
lean_dec_ref(v_vs_436_);
lean_dec_ref(v_ks_435_);
return v___x_438_;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9_spec__11___redArg(lean_object* v_f_439_, lean_object* v_as_440_, size_t v_i_441_, size_t v_stop_442_, lean_object* v_b_443_, lean_object* v___y_444_, lean_object* v___y_445_, lean_object* v___y_446_, lean_object* v___y_447_, lean_object* v___y_448_){
_start:
{
lean_object* v_fst_451_; lean_object* v_snd_452_; lean_object* v___y_457_; uint8_t v___x_462_; 
v___x_462_ = lean_usize_dec_eq(v_i_441_, v_stop_442_);
if (v___x_462_ == 0)
{
lean_object* v___x_463_; 
v___x_463_ = lean_array_uget_borrowed(v_as_440_, v_i_441_);
switch(lean_obj_tag(v___x_463_))
{
case 0:
{
lean_object* v_key_464_; lean_object* v_val_465_; lean_object* v___x_466_; 
v_key_464_ = lean_ctor_get(v___x_463_, 0);
v_val_465_ = lean_ctor_get(v___x_463_, 1);
lean_inc_ref(v_f_439_);
lean_inc(v___y_448_);
lean_inc_ref(v___y_447_);
lean_inc(v___y_446_);
lean_inc_ref(v___y_445_);
lean_inc(v_val_465_);
lean_inc(v_key_464_);
v___x_466_ = lean_apply_9(v_f_439_, v_b_443_, v_key_464_, v_val_465_, v___y_444_, v___y_445_, v___y_446_, v___y_447_, v___y_448_, lean_box(0));
v___y_457_ = v___x_466_;
goto v___jp_456_;
}
case 1:
{
lean_object* v_node_467_; lean_object* v___x_468_; 
v_node_467_ = lean_ctor_get(v___x_463_, 0);
lean_inc(v_node_467_);
lean_inc_ref(v_f_439_);
v___x_468_ = lp_JunkValues_Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9___redArg(v_f_439_, v_node_467_, v_b_443_, v___y_444_, v___y_445_, v___y_446_, v___y_447_, v___y_448_);
v___y_457_ = v___x_468_;
goto v___jp_456_;
}
default: 
{
v_fst_451_ = v_b_443_;
v_snd_452_ = v___y_444_;
goto v___jp_450_;
}
}
}
else
{
lean_object* v___x_469_; lean_object* v___x_470_; lean_object* v___x_471_; 
lean_dec_ref(v_f_439_);
v___x_469_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_469_, 0, v_b_443_);
lean_ctor_set(v___x_469_, 1, v___y_444_);
v___x_470_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_470_, 0, v___x_469_);
v___x_471_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_471_, 0, v___x_470_);
return v___x_471_;
}
v___jp_450_:
{
size_t v___x_453_; size_t v___x_454_; 
v___x_453_ = ((size_t)1ULL);
v___x_454_ = lean_usize_add(v_i_441_, v___x_453_);
v_i_441_ = v___x_454_;
v_b_443_ = v_fst_451_;
v___y_444_ = v_snd_452_;
goto _start;
}
v___jp_456_:
{
if (lean_obj_tag(v___y_457_) == 0)
{
lean_object* v_a_458_; 
v_a_458_ = lean_ctor_get(v___y_457_, 0);
if (lean_obj_tag(v_a_458_) == 0)
{
lean_dec_ref(v_f_439_);
return v___y_457_;
}
else
{
lean_object* v_a_459_; lean_object* v_fst_460_; lean_object* v_snd_461_; 
lean_inc_ref(v_a_458_);
lean_dec_ref_known(v___y_457_, 1);
v_a_459_ = lean_ctor_get(v_a_458_, 0);
lean_inc(v_a_459_);
lean_dec_ref_known(v_a_458_, 1);
v_fst_460_ = lean_ctor_get(v_a_459_, 0);
lean_inc(v_fst_460_);
v_snd_461_ = lean_ctor_get(v_a_459_, 1);
lean_inc(v_snd_461_);
lean_dec(v_a_459_);
v_fst_451_ = v_fst_460_;
v_snd_452_ = v_snd_461_;
goto v___jp_450_;
}
}
else
{
lean_dec_ref(v_f_439_);
return v___y_457_;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9_spec__11___redArg___boxed(lean_object* v_f_472_, lean_object* v_as_473_, lean_object* v_i_474_, lean_object* v_stop_475_, lean_object* v_b_476_, lean_object* v___y_477_, lean_object* v___y_478_, lean_object* v___y_479_, lean_object* v___y_480_, lean_object* v___y_481_, lean_object* v___y_482_){
_start:
{
size_t v_i_boxed_483_; size_t v_stop_boxed_484_; lean_object* v_res_485_; 
v_i_boxed_483_ = lean_unbox_usize(v_i_474_);
lean_dec(v_i_474_);
v_stop_boxed_484_ = lean_unbox_usize(v_stop_475_);
lean_dec(v_stop_475_);
v_res_485_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9_spec__11___redArg(v_f_472_, v_as_473_, v_i_boxed_483_, v_stop_boxed_484_, v_b_476_, v___y_477_, v___y_478_, v___y_479_, v___y_480_, v___y_481_);
lean_dec(v___y_481_);
lean_dec_ref(v___y_480_);
lean_dec(v___y_479_);
lean_dec_ref(v___y_478_);
lean_dec_ref(v_as_473_);
return v_res_485_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9___redArg___boxed(lean_object* v_f_486_, lean_object* v_x_487_, lean_object* v_x_488_, lean_object* v___y_489_, lean_object* v___y_490_, lean_object* v___y_491_, lean_object* v___y_492_, lean_object* v___y_493_, lean_object* v___y_494_){
_start:
{
lean_object* v_res_495_; 
v_res_495_ = lp_JunkValues_Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9___redArg(v_f_486_, v_x_487_, v_x_488_, v___y_489_, v___y_490_, v___y_491_, v___y_492_, v___y_493_);
lean_dec(v___y_493_);
lean_dec_ref(v___y_492_);
lean_dec(v___y_491_);
lean_dec_ref(v___y_490_);
return v_res_495_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4___redArg(lean_object* v_map_496_, lean_object* v_f_497_, lean_object* v___y_498_, lean_object* v___y_499_, lean_object* v___y_500_, lean_object* v___y_501_, lean_object* v___y_502_){
_start:
{
lean_object* v___f_504_; lean_object* v___x_505_; lean_object* v___x_506_; 
v___f_504_ = lean_alloc_closure((void*)(lp_JunkValues_Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4___redArg___lam__0___boxed), 10, 1);
lean_closure_set(v___f_504_, 0, v_f_497_);
v___x_505_ = lean_box(0);
v___x_506_ = lp_JunkValues_Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9___redArg(v___f_504_, v_map_496_, v___x_505_, v___y_498_, v___y_499_, v___y_500_, v___y_501_, v___y_502_);
return v___x_506_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4___redArg___boxed(lean_object* v_map_507_, lean_object* v_f_508_, lean_object* v___y_509_, lean_object* v___y_510_, lean_object* v___y_511_, lean_object* v___y_512_, lean_object* v___y_513_, lean_object* v___y_514_){
_start:
{
lean_object* v_res_515_; 
v_res_515_ = lp_JunkValues_Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4___redArg(v_map_507_, v_f_508_, v___y_509_, v___y_510_, v___y_511_, v___y_512_, v___y_513_);
lean_dec(v___y_513_);
lean_dec_ref(v___y_512_);
lean_dec(v___y_511_);
lean_dec_ref(v___y_510_);
return v_res_515_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__3___redArg(lean_object* v_f_516_, lean_object* v_x_517_, lean_object* v_x_518_, lean_object* v___y_519_, lean_object* v___y_520_, lean_object* v___y_521_, lean_object* v___y_522_, lean_object* v___y_523_){
_start:
{
if (lean_obj_tag(v_x_518_) == 0)
{
lean_object* v___x_525_; lean_object* v___x_526_; lean_object* v___x_527_; 
lean_dec_ref(v_f_516_);
v___x_525_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_525_, 0, v_x_517_);
lean_ctor_set(v___x_525_, 1, v___y_519_);
v___x_526_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_526_, 0, v___x_525_);
v___x_527_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_527_, 0, v___x_526_);
return v___x_527_;
}
else
{
lean_object* v_key_528_; lean_object* v_value_529_; lean_object* v_tail_530_; lean_object* v___x_531_; 
v_key_528_ = lean_ctor_get(v_x_518_, 0);
lean_inc(v_key_528_);
v_value_529_ = lean_ctor_get(v_x_518_, 1);
lean_inc(v_value_529_);
v_tail_530_ = lean_ctor_get(v_x_518_, 2);
lean_inc(v_tail_530_);
lean_dec_ref_known(v_x_518_, 3);
lean_inc_ref(v_f_516_);
lean_inc(v___y_523_);
lean_inc_ref(v___y_522_);
lean_inc(v___y_521_);
lean_inc_ref(v___y_520_);
v___x_531_ = lean_apply_8(v_f_516_, v_key_528_, v_value_529_, v___y_519_, v___y_520_, v___y_521_, v___y_522_, v___y_523_, lean_box(0));
if (lean_obj_tag(v___x_531_) == 0)
{
lean_object* v_a_532_; 
v_a_532_ = lean_ctor_get(v___x_531_, 0);
lean_inc(v_a_532_);
if (lean_obj_tag(v_a_532_) == 0)
{
lean_dec_ref_known(v_a_532_, 1);
lean_dec(v_tail_530_);
lean_dec_ref(v_f_516_);
return v___x_531_;
}
else
{
lean_object* v_a_533_; lean_object* v_fst_534_; lean_object* v_snd_535_; 
lean_dec_ref_known(v___x_531_, 1);
v_a_533_ = lean_ctor_get(v_a_532_, 0);
lean_inc(v_a_533_);
lean_dec_ref_known(v_a_532_, 1);
v_fst_534_ = lean_ctor_get(v_a_533_, 0);
lean_inc(v_fst_534_);
v_snd_535_ = lean_ctor_get(v_a_533_, 1);
lean_inc(v_snd_535_);
lean_dec(v_a_533_);
v_x_517_ = v_fst_534_;
v_x_518_ = v_tail_530_;
v___y_519_ = v_snd_535_;
goto _start;
}
}
else
{
lean_dec(v_tail_530_);
lean_dec_ref(v_f_516_);
return v___x_531_;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__3___redArg___boxed(lean_object* v_f_537_, lean_object* v_x_538_, lean_object* v_x_539_, lean_object* v___y_540_, lean_object* v___y_541_, lean_object* v___y_542_, lean_object* v___y_543_, lean_object* v___y_544_, lean_object* v___y_545_){
_start:
{
lean_object* v_res_546_; 
v_res_546_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__3___redArg(v_f_537_, v_x_538_, v_x_539_, v___y_540_, v___y_541_, v___y_542_, v___y_543_, v___y_544_);
lean_dec(v___y_544_);
lean_dec_ref(v___y_543_);
lean_dec(v___y_542_);
lean_dec_ref(v___y_541_);
return v_res_546_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__5___redArg(lean_object* v_f_547_, lean_object* v_as_548_, size_t v_i_549_, size_t v_stop_550_, lean_object* v_b_551_, lean_object* v___y_552_, lean_object* v___y_553_, lean_object* v___y_554_, lean_object* v___y_555_, lean_object* v___y_556_){
_start:
{
uint8_t v___x_558_; 
v___x_558_ = lean_usize_dec_eq(v_i_549_, v_stop_550_);
if (v___x_558_ == 0)
{
lean_object* v___x_559_; lean_object* v___x_560_; lean_object* v___x_561_; 
v___x_559_ = lean_array_uget_borrowed(v_as_548_, v_i_549_);
v___x_560_ = lean_box(0);
lean_inc(v___x_559_);
lean_inc_ref(v_f_547_);
v___x_561_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__3___redArg(v_f_547_, v___x_560_, v___x_559_, v___y_552_, v___y_553_, v___y_554_, v___y_555_, v___y_556_);
if (lean_obj_tag(v___x_561_) == 0)
{
lean_object* v_a_562_; 
v_a_562_ = lean_ctor_get(v___x_561_, 0);
lean_inc(v_a_562_);
if (lean_obj_tag(v_a_562_) == 0)
{
lean_dec_ref_known(v_a_562_, 1);
lean_dec_ref(v_f_547_);
return v___x_561_;
}
else
{
lean_object* v_a_563_; lean_object* v_fst_564_; lean_object* v_snd_565_; size_t v___x_566_; size_t v___x_567_; 
lean_dec_ref_known(v___x_561_, 1);
v_a_563_ = lean_ctor_get(v_a_562_, 0);
lean_inc(v_a_563_);
lean_dec_ref_known(v_a_562_, 1);
v_fst_564_ = lean_ctor_get(v_a_563_, 0);
lean_inc(v_fst_564_);
v_snd_565_ = lean_ctor_get(v_a_563_, 1);
lean_inc(v_snd_565_);
lean_dec(v_a_563_);
v___x_566_ = ((size_t)1ULL);
v___x_567_ = lean_usize_add(v_i_549_, v___x_566_);
v_i_549_ = v___x_567_;
v_b_551_ = v_fst_564_;
v___y_552_ = v_snd_565_;
goto _start;
}
}
else
{
lean_dec_ref(v_f_547_);
return v___x_561_;
}
}
else
{
lean_object* v___x_569_; lean_object* v___x_570_; lean_object* v___x_571_; 
lean_dec_ref(v_f_547_);
v___x_569_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_569_, 0, v_b_551_);
lean_ctor_set(v___x_569_, 1, v___y_552_);
v___x_570_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_570_, 0, v___x_569_);
v___x_571_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_571_, 0, v___x_570_);
return v___x_571_;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__5___redArg___boxed(lean_object* v_f_572_, lean_object* v_as_573_, lean_object* v_i_574_, lean_object* v_stop_575_, lean_object* v_b_576_, lean_object* v___y_577_, lean_object* v___y_578_, lean_object* v___y_579_, lean_object* v___y_580_, lean_object* v___y_581_, lean_object* v___y_582_){
_start:
{
size_t v_i_boxed_583_; size_t v_stop_boxed_584_; lean_object* v_res_585_; 
v_i_boxed_583_ = lean_unbox_usize(v_i_574_);
lean_dec(v_i_574_);
v_stop_boxed_584_ = lean_unbox_usize(v_stop_575_);
lean_dec(v_stop_575_);
v_res_585_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__5___redArg(v_f_572_, v_as_573_, v_i_boxed_583_, v_stop_boxed_584_, v_b_576_, v___y_577_, v___y_578_, v___y_579_, v___y_580_, v___y_581_);
lean_dec(v___y_581_);
lean_dec_ref(v___y_580_);
lean_dec(v___y_579_);
lean_dec_ref(v___y_578_);
lean_dec_ref(v_as_573_);
return v_res_585_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2___redArg(lean_object* v_s_586_, lean_object* v_f_587_, lean_object* v___y_588_, lean_object* v___y_589_, lean_object* v___y_590_, lean_object* v___y_591_, lean_object* v___y_592_){
_start:
{
lean_object* v_map_u2081_594_; lean_object* v_map_u2082_595_; lean_object* v_buckets_596_; lean_object* v___x_597_; lean_object* v___x_598_; uint8_t v___x_599_; 
v_map_u2081_594_ = lean_ctor_get(v_s_586_, 0);
lean_inc_ref(v_map_u2081_594_);
v_map_u2082_595_ = lean_ctor_get(v_s_586_, 1);
lean_inc_ref(v_map_u2082_595_);
lean_dec_ref(v_s_586_);
v_buckets_596_ = lean_ctor_get(v_map_u2081_594_, 1);
lean_inc_ref(v_buckets_596_);
lean_dec_ref(v_map_u2081_594_);
v___x_597_ = lean_unsigned_to_nat(0u);
v___x_598_ = lean_array_get_size(v_buckets_596_);
v___x_599_ = lean_nat_dec_lt(v___x_597_, v___x_598_);
if (v___x_599_ == 0)
{
lean_object* v___x_600_; 
lean_dec_ref(v_buckets_596_);
v___x_600_ = lp_JunkValues_Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4___redArg(v_map_u2082_595_, v_f_587_, v___y_588_, v___y_589_, v___y_590_, v___y_591_, v___y_592_);
return v___x_600_;
}
else
{
lean_object* v___x_601_; uint8_t v___x_602_; 
v___x_601_ = lean_box(0);
v___x_602_ = lean_nat_dec_le(v___x_598_, v___x_598_);
if (v___x_602_ == 0)
{
if (v___x_599_ == 0)
{
lean_object* v___x_603_; 
lean_dec_ref(v_buckets_596_);
v___x_603_ = lp_JunkValues_Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4___redArg(v_map_u2082_595_, v_f_587_, v___y_588_, v___y_589_, v___y_590_, v___y_591_, v___y_592_);
return v___x_603_;
}
else
{
size_t v___x_604_; size_t v___x_605_; lean_object* v___x_606_; 
v___x_604_ = ((size_t)0ULL);
v___x_605_ = lean_usize_of_nat(v___x_598_);
lean_inc_ref(v_f_587_);
v___x_606_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__5___redArg(v_f_587_, v_buckets_596_, v___x_604_, v___x_605_, v___x_601_, v___y_588_, v___y_589_, v___y_590_, v___y_591_, v___y_592_);
lean_dec_ref(v_buckets_596_);
if (lean_obj_tag(v___x_606_) == 0)
{
lean_object* v_a_607_; 
v_a_607_ = lean_ctor_get(v___x_606_, 0);
lean_inc(v_a_607_);
if (lean_obj_tag(v_a_607_) == 0)
{
lean_dec_ref_known(v_a_607_, 1);
lean_dec_ref(v_map_u2082_595_);
lean_dec_ref(v_f_587_);
return v___x_606_;
}
else
{
lean_object* v_a_608_; lean_object* v_snd_609_; lean_object* v___x_610_; 
lean_dec_ref_known(v___x_606_, 1);
v_a_608_ = lean_ctor_get(v_a_607_, 0);
lean_inc(v_a_608_);
lean_dec_ref_known(v_a_607_, 1);
v_snd_609_ = lean_ctor_get(v_a_608_, 1);
lean_inc(v_snd_609_);
lean_dec(v_a_608_);
v___x_610_ = lp_JunkValues_Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4___redArg(v_map_u2082_595_, v_f_587_, v_snd_609_, v___y_589_, v___y_590_, v___y_591_, v___y_592_);
return v___x_610_;
}
}
else
{
lean_dec_ref(v_map_u2082_595_);
lean_dec_ref(v_f_587_);
return v___x_606_;
}
}
}
else
{
size_t v___x_611_; size_t v___x_612_; lean_object* v___x_613_; 
v___x_611_ = ((size_t)0ULL);
v___x_612_ = lean_usize_of_nat(v___x_598_);
lean_inc_ref(v_f_587_);
v___x_613_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__5___redArg(v_f_587_, v_buckets_596_, v___x_611_, v___x_612_, v___x_601_, v___y_588_, v___y_589_, v___y_590_, v___y_591_, v___y_592_);
lean_dec_ref(v_buckets_596_);
if (lean_obj_tag(v___x_613_) == 0)
{
lean_object* v_a_614_; 
v_a_614_ = lean_ctor_get(v___x_613_, 0);
lean_inc(v_a_614_);
if (lean_obj_tag(v_a_614_) == 0)
{
lean_dec_ref_known(v_a_614_, 1);
lean_dec_ref(v_map_u2082_595_);
lean_dec_ref(v_f_587_);
return v___x_613_;
}
else
{
lean_object* v_a_615_; lean_object* v_snd_616_; lean_object* v___x_617_; 
lean_dec_ref_known(v___x_613_, 1);
v_a_615_ = lean_ctor_get(v_a_614_, 0);
lean_inc(v_a_615_);
lean_dec_ref_known(v_a_614_, 1);
v_snd_616_ = lean_ctor_get(v_a_615_, 1);
lean_inc(v_snd_616_);
lean_dec(v_a_615_);
v___x_617_ = lp_JunkValues_Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4___redArg(v_map_u2082_595_, v_f_587_, v_snd_616_, v___y_589_, v___y_590_, v___y_591_, v___y_592_);
return v___x_617_;
}
}
else
{
lean_dec_ref(v_map_u2082_595_);
lean_dec_ref(v_f_587_);
return v___x_613_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2___redArg___boxed(lean_object* v_s_618_, lean_object* v_f_619_, lean_object* v___y_620_, lean_object* v___y_621_, lean_object* v___y_622_, lean_object* v___y_623_, lean_object* v___y_624_, lean_object* v___y_625_){
_start:
{
lean_object* v_res_626_; 
v_res_626_ = lp_JunkValues_Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2___redArg(v_s_618_, v_f_619_, v___y_620_, v___y_621_, v___y_622_, v___y_623_, v___y_624_);
lean_dec(v___y_624_);
lean_dec_ref(v___y_623_);
lean_dec(v___y_622_);
lean_dec_ref(v___y_621_);
return v_res_626_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_discoverRules_spec__1(lean_object* v_scope_628_, lean_object* v_as_629_, size_t v_sz_630_, size_t v_i_631_, lean_object* v_b_632_, lean_object* v___y_633_, lean_object* v___y_634_, lean_object* v___y_635_, lean_object* v___y_636_){
_start:
{
uint8_t v___x_638_; 
v___x_638_ = lean_usize_dec_lt(v_i_631_, v_sz_630_);
if (v___x_638_ == 0)
{
lean_object* v___x_639_; 
v___x_639_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_639_, 0, v_b_632_);
return v___x_639_;
}
else
{
lean_object* v_a_640_; lean_object* v___x_641_; lean_object* v___x_642_; 
v_a_640_ = lean_array_uget_borrowed(v_as_629_, v_i_631_);
v___x_641_ = ((lean_object*)(lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_discoverRules_spec__1___closed__0));
lean_inc(v_a_640_);
v___x_642_ = lp_JunkValues_JunkValues_ruleOfTheorem_x3f(v_a_640_, v___x_641_, v___y_633_, v___y_634_, v___y_635_, v___y_636_);
if (lean_obj_tag(v___x_642_) == 0)
{
lean_object* v_a_643_; lean_object* v_a_645_; 
v_a_643_ = lean_ctor_get(v___x_642_, 0);
lean_inc(v_a_643_);
lean_dec_ref_known(v___x_642_, 1);
if (lean_obj_tag(v_a_643_) == 1)
{
lean_object* v_a_649_; uint8_t v_requireNegatedGuard_652_; 
v_a_649_ = lean_ctor_get(v_a_643_, 0);
lean_inc(v_a_649_);
lean_dec_ref_known(v_a_643_, 1);
v_requireNegatedGuard_652_ = lean_ctor_get_uint8(v_scope_628_, sizeof(void*)*1 + 1);
if (v_requireNegatedGuard_652_ == 0)
{
goto v___jp_650_;
}
else
{
lean_object* v_negatedGuards_653_; lean_object* v___x_654_; uint8_t v___x_655_; 
v_negatedGuards_653_ = lean_ctor_get(v_a_649_, 3);
v___x_654_ = lean_unsigned_to_nat(0u);
v___x_655_ = lean_nat_dec_lt(v___x_654_, v_negatedGuards_653_);
if (v___x_655_ == 0)
{
lean_dec(v_a_649_);
v_a_645_ = v_b_632_;
goto v___jp_644_;
}
else
{
goto v___jp_650_;
}
}
v___jp_650_:
{
lean_object* v___x_651_; 
v___x_651_ = lean_array_push(v_b_632_, v_a_649_);
v_a_645_ = v___x_651_;
goto v___jp_644_;
}
}
else
{
lean_dec(v_a_643_);
v_a_645_ = v_b_632_;
goto v___jp_644_;
}
v___jp_644_:
{
size_t v___x_646_; size_t v___x_647_; 
v___x_646_ = ((size_t)1ULL);
v___x_647_ = lean_usize_add(v_i_631_, v___x_646_);
v_i_631_ = v___x_647_;
v_b_632_ = v_a_645_;
goto _start;
}
}
else
{
lean_object* v_a_656_; lean_object* v___x_658_; uint8_t v_isShared_659_; uint8_t v_isSharedCheck_663_; 
lean_dec_ref(v_b_632_);
v_a_656_ = lean_ctor_get(v___x_642_, 0);
v_isSharedCheck_663_ = !lean_is_exclusive(v___x_642_);
if (v_isSharedCheck_663_ == 0)
{
v___x_658_ = v___x_642_;
v_isShared_659_ = v_isSharedCheck_663_;
goto v_resetjp_657_;
}
else
{
lean_inc(v_a_656_);
lean_dec(v___x_642_);
v___x_658_ = lean_box(0);
v_isShared_659_ = v_isSharedCheck_663_;
goto v_resetjp_657_;
}
v_resetjp_657_:
{
lean_object* v___x_661_; 
if (v_isShared_659_ == 0)
{
v___x_661_ = v___x_658_;
goto v_reusejp_660_;
}
else
{
lean_object* v_reuseFailAlloc_662_; 
v_reuseFailAlloc_662_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_662_, 0, v_a_656_);
v___x_661_ = v_reuseFailAlloc_662_;
goto v_reusejp_660_;
}
v_reusejp_660_:
{
return v___x_661_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_discoverRules_spec__1___boxed(lean_object* v_scope_664_, lean_object* v_as_665_, lean_object* v_sz_666_, lean_object* v_i_667_, lean_object* v_b_668_, lean_object* v___y_669_, lean_object* v___y_670_, lean_object* v___y_671_, lean_object* v___y_672_, lean_object* v___y_673_){
_start:
{
size_t v_sz_boxed_674_; size_t v_i_boxed_675_; lean_object* v_res_676_; 
v_sz_boxed_674_ = lean_unbox_usize(v_sz_666_);
lean_dec(v_sz_666_);
v_i_boxed_675_ = lean_unbox_usize(v_i_667_);
lean_dec(v_i_667_);
v_res_676_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_discoverRules_spec__1(v_scope_664_, v_as_665_, v_sz_boxed_674_, v_i_boxed_675_, v_b_668_, v___y_669_, v___y_670_, v___y_671_, v___y_672_);
lean_dec(v___y_672_);
lean_dec_ref(v___y_671_);
lean_dec(v___y_670_);
lean_dec_ref(v___y_669_);
lean_dec_ref(v_as_665_);
lean_dec_ref(v_scope_664_);
return v_res_676_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_discoverRules___closed__2(void){
_start:
{
lean_object* v___x_681_; lean_object* v___x_682_; lean_object* v___x_683_; 
v___x_681_ = lean_box(0);
v___x_682_ = lean_unsigned_to_nat(16u);
v___x_683_ = lean_mk_array(v___x_682_, v___x_681_);
return v___x_683_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_discoverRules___closed__3(void){
_start:
{
lean_object* v___x_684_; lean_object* v___x_685_; lean_object* v___x_686_; 
v___x_684_ = lean_obj_once(&lp_JunkValues_JunkValues_discoverRules___closed__2, &lp_JunkValues_JunkValues_discoverRules___closed__2_once, _init_lp_JunkValues_JunkValues_discoverRules___closed__2);
v___x_685_ = lean_unsigned_to_nat(0u);
v___x_686_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_686_, 0, v___x_685_);
lean_ctor_set(v___x_686_, 1, v___x_684_);
return v___x_686_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_discoverRules___closed__4(void){
_start:
{
lean_object* v___x_687_; lean_object* v___x_688_; 
v___x_687_ = ((lean_object*)(lp_JunkValues_JunkValues_defaultValueHeads));
v___x_688_ = lean_array_get_size(v___x_687_);
return v___x_688_;
}
}
static uint8_t _init_lp_JunkValues_JunkValues_discoverRules___closed__5(void){
_start:
{
lean_object* v___x_689_; lean_object* v___x_690_; uint8_t v___x_691_; 
v___x_689_ = lean_obj_once(&lp_JunkValues_JunkValues_discoverRules___closed__4, &lp_JunkValues_JunkValues_discoverRules___closed__4_once, _init_lp_JunkValues_JunkValues_discoverRules___closed__4);
v___x_690_ = lean_unsigned_to_nat(0u);
v___x_691_ = lean_nat_dec_lt(v___x_690_, v___x_689_);
return v___x_691_;
}
}
static uint8_t _init_lp_JunkValues_JunkValues_discoverRules___closed__6(void){
_start:
{
lean_object* v___x_692_; uint8_t v___x_693_; 
v___x_692_ = lean_obj_once(&lp_JunkValues_JunkValues_discoverRules___closed__4, &lp_JunkValues_JunkValues_discoverRules___closed__4_once, _init_lp_JunkValues_JunkValues_discoverRules___closed__4);
v___x_693_ = lean_nat_dec_le(v___x_692_, v___x_692_);
return v___x_693_;
}
}
static size_t _init_lp_JunkValues_JunkValues_discoverRules___closed__7(void){
_start:
{
lean_object* v___x_694_; size_t v___x_695_; 
v___x_694_ = lean_obj_once(&lp_JunkValues_JunkValues_discoverRules___closed__4, &lp_JunkValues_JunkValues_discoverRules___closed__4_once, _init_lp_JunkValues_JunkValues_discoverRules___closed__4);
v___x_695_ = lean_usize_of_nat(v___x_694_);
return v___x_695_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_discoverRules___closed__8(void){
_start:
{
lean_object* v___x_696_; size_t v___x_697_; size_t v___x_698_; lean_object* v___x_699_; lean_object* v___x_700_; 
v___x_696_ = lean_obj_once(&lp_JunkValues_JunkValues_discoverRules___closed__3, &lp_JunkValues_JunkValues_discoverRules___closed__3_once, _init_lp_JunkValues_JunkValues_discoverRules___closed__3);
v___x_697_ = lean_usize_once(&lp_JunkValues_JunkValues_discoverRules___closed__7, &lp_JunkValues_JunkValues_discoverRules___closed__7_once, _init_lp_JunkValues_JunkValues_discoverRules___closed__7);
v___x_698_ = ((size_t)0ULL);
v___x_699_ = ((lean_object*)(lp_JunkValues_JunkValues_defaultValueHeads));
v___x_700_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00JunkValues_discoverRules_spec__3(v___x_699_, v___x_698_, v___x_697_, v___x_696_);
return v___x_700_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_discoverRules(lean_object* v_scope_701_, lean_object* v_a_702_, lean_object* v_a_703_, lean_object* v_a_704_, lean_object* v_a_705_){
_start:
{
lean_object* v___x_707_; lean_object* v_env_708_; lean_object* v_a_710_; lean_object* v___y_716_; lean_object* v___x_733_; uint8_t v___x_734_; 
v___x_707_ = lean_st_ref_get(v_a_705_);
v_env_708_ = lean_ctor_get(v___x_707_, 0);
lean_inc_ref(v_env_708_);
lean_dec(v___x_707_);
v___x_733_ = lean_obj_once(&lp_JunkValues_JunkValues_discoverRules___closed__3, &lp_JunkValues_JunkValues_discoverRules___closed__3_once, _init_lp_JunkValues_JunkValues_discoverRules___closed__3);
v___x_734_ = lean_uint8_once(&lp_JunkValues_JunkValues_discoverRules___closed__5, &lp_JunkValues_JunkValues_discoverRules___closed__5_once, _init_lp_JunkValues_JunkValues_discoverRules___closed__5);
if (v___x_734_ == 0)
{
v___y_716_ = v___x_733_;
goto v___jp_715_;
}
else
{
uint8_t v___x_735_; 
v___x_735_ = lean_uint8_once(&lp_JunkValues_JunkValues_discoverRules___closed__6, &lp_JunkValues_JunkValues_discoverRules___closed__6_once, _init_lp_JunkValues_JunkValues_discoverRules___closed__6);
if (v___x_735_ == 0)
{
if (v___x_734_ == 0)
{
v___y_716_ = v___x_733_;
goto v___jp_715_;
}
else
{
lean_object* v___x_736_; 
v___x_736_ = lean_obj_once(&lp_JunkValues_JunkValues_discoverRules___closed__8, &lp_JunkValues_JunkValues_discoverRules___closed__8_once, _init_lp_JunkValues_JunkValues_discoverRules___closed__8);
v___y_716_ = v___x_736_;
goto v___jp_715_;
}
}
else
{
lean_object* v___x_737_; 
v___x_737_ = lean_obj_once(&lp_JunkValues_JunkValues_discoverRules___closed__8, &lp_JunkValues_JunkValues_discoverRules___closed__8_once, _init_lp_JunkValues_JunkValues_discoverRules___closed__8);
v___y_716_ = v___x_737_;
goto v___jp_715_;
}
}
v___jp_709_:
{
lean_object* v___x_711_; size_t v_sz_712_; size_t v___x_713_; lean_object* v___x_714_; 
v___x_711_ = ((lean_object*)(lp_JunkValues_JunkValues_discoverRules___closed__0));
v_sz_712_ = lean_array_size(v_a_710_);
v___x_713_ = ((size_t)0ULL);
v___x_714_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_discoverRules_spec__1(v_scope_701_, v_a_710_, v_sz_712_, v___x_713_, v___x_711_, v_a_702_, v_a_703_, v_a_704_, v_a_705_);
lean_dec_ref(v_a_710_);
lean_dec_ref(v_scope_701_);
return v___x_714_;
}
v___jp_715_:
{
lean_object* v___f_717_; lean_object* v___x_718_; lean_object* v___x_719_; lean_object* v___x_720_; 
lean_inc_ref(v___y_716_);
lean_inc_ref(v_env_708_);
lean_inc_ref(v_scope_701_);
v___f_717_ = lean_alloc_closure((void*)(lp_JunkValues_JunkValues_discoverRules___lam__0___boxed), 11, 3);
lean_closure_set(v___f_717_, 0, v_scope_701_);
lean_closure_set(v___f_717_, 1, v_env_708_);
lean_closure_set(v___f_717_, 2, v___y_716_);
v___x_718_ = ((lean_object*)(lp_JunkValues_JunkValues_discoverRules___closed__1));
v___x_719_ = l_Lean_Environment_constants(v_env_708_);
v___x_720_ = lp_JunkValues_Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2___redArg(v___x_719_, v___f_717_, v___x_718_, v_a_702_, v_a_703_, v_a_704_, v_a_705_);
if (lean_obj_tag(v___x_720_) == 0)
{
lean_object* v_a_721_; 
v_a_721_ = lean_ctor_get(v___x_720_, 0);
lean_inc(v_a_721_);
lean_dec_ref_known(v___x_720_, 1);
if (lean_obj_tag(v_a_721_) == 0)
{
lean_object* v_a_722_; 
v_a_722_ = lean_ctor_get(v_a_721_, 0);
lean_inc(v_a_722_);
lean_dec_ref_known(v_a_721_, 1);
v_a_710_ = v_a_722_;
goto v___jp_709_;
}
else
{
lean_object* v_a_723_; lean_object* v_snd_724_; 
v_a_723_ = lean_ctor_get(v_a_721_, 0);
lean_inc(v_a_723_);
lean_dec_ref_known(v_a_721_, 1);
v_snd_724_ = lean_ctor_get(v_a_723_, 1);
lean_inc(v_snd_724_);
lean_dec(v_a_723_);
v_a_710_ = v_snd_724_;
goto v___jp_709_;
}
}
else
{
lean_object* v_a_725_; lean_object* v___x_727_; uint8_t v_isShared_728_; uint8_t v_isSharedCheck_732_; 
lean_dec_ref(v_scope_701_);
v_a_725_ = lean_ctor_get(v___x_720_, 0);
v_isSharedCheck_732_ = !lean_is_exclusive(v___x_720_);
if (v_isSharedCheck_732_ == 0)
{
v___x_727_ = v___x_720_;
v_isShared_728_ = v_isSharedCheck_732_;
goto v_resetjp_726_;
}
else
{
lean_inc(v_a_725_);
lean_dec(v___x_720_);
v___x_727_ = lean_box(0);
v_isShared_728_ = v_isSharedCheck_732_;
goto v_resetjp_726_;
}
v_resetjp_726_:
{
lean_object* v___x_730_; 
if (v_isShared_728_ == 0)
{
v___x_730_ = v___x_727_;
goto v_reusejp_729_;
}
else
{
lean_object* v_reuseFailAlloc_731_; 
v_reuseFailAlloc_731_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_731_, 0, v_a_725_);
v___x_730_ = v_reuseFailAlloc_731_;
goto v_reusejp_729_;
}
v_reusejp_729_:
{
return v___x_730_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_discoverRules___boxed(lean_object* v_scope_738_, lean_object* v_a_739_, lean_object* v_a_740_, lean_object* v_a_741_, lean_object* v_a_742_, lean_object* v_a_743_){
_start:
{
lean_object* v_res_744_; 
v_res_744_ = lp_JunkValues_JunkValues_discoverRules(v_scope_738_, v_a_739_, v_a_740_, v_a_741_, v_a_742_);
lean_dec(v_a_742_);
lean_dec_ref(v_a_741_);
lean_dec(v_a_740_);
lean_dec_ref(v_a_739_);
return v_res_744_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_discoverRules_spec__0(lean_object* v_00_u03b2_745_, lean_object* v_m_746_, lean_object* v_a_747_, lean_object* v_b_748_){
_start:
{
lean_object* v___x_749_; 
v___x_749_ = lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_discoverRules_spec__0___redArg(v_m_746_, v_a_747_, v_b_748_);
return v___x_749_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2(lean_object* v_00_u03b2_750_, lean_object* v_s_751_, lean_object* v_f_752_, lean_object* v___y_753_, lean_object* v___y_754_, lean_object* v___y_755_, lean_object* v___y_756_, lean_object* v___y_757_){
_start:
{
lean_object* v___x_759_; 
v___x_759_ = lp_JunkValues_Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2___redArg(v_s_751_, v_f_752_, v___y_753_, v___y_754_, v___y_755_, v___y_756_, v___y_757_);
return v___x_759_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2___boxed(lean_object* v_00_u03b2_760_, lean_object* v_s_761_, lean_object* v_f_762_, lean_object* v___y_763_, lean_object* v___y_764_, lean_object* v___y_765_, lean_object* v___y_766_, lean_object* v___y_767_, lean_object* v___y_768_){
_start:
{
lean_object* v_res_769_; 
v_res_769_ = lp_JunkValues_Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2(v_00_u03b2_760_, v_s_761_, v_f_762_, v___y_763_, v___y_764_, v___y_765_, v___y_766_, v___y_767_);
lean_dec(v___y_767_);
lean_dec_ref(v___y_766_);
lean_dec(v___y_765_);
lean_dec_ref(v___y_764_);
return v_res_769_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_discoverRules_spec__0_spec__0(lean_object* v_00_u03b2_770_, lean_object* v_data_771_){
_start:
{
lean_object* v___x_772_; 
v___x_772_ = lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_discoverRules_spec__0_spec__0___redArg(v_data_771_);
return v___x_772_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__3(lean_object* v_00_u03b2_773_, lean_object* v_f_774_, lean_object* v_x_775_, lean_object* v_x_776_, lean_object* v___y_777_, lean_object* v___y_778_, lean_object* v___y_779_, lean_object* v___y_780_, lean_object* v___y_781_){
_start:
{
lean_object* v___x_783_; 
v___x_783_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__3___redArg(v_f_774_, v_x_775_, v_x_776_, v___y_777_, v___y_778_, v___y_779_, v___y_780_, v___y_781_);
return v___x_783_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__3___boxed(lean_object* v_00_u03b2_784_, lean_object* v_f_785_, lean_object* v_x_786_, lean_object* v_x_787_, lean_object* v___y_788_, lean_object* v___y_789_, lean_object* v___y_790_, lean_object* v___y_791_, lean_object* v___y_792_, lean_object* v___y_793_){
_start:
{
lean_object* v_res_794_; 
v_res_794_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__3(v_00_u03b2_784_, v_f_785_, v_x_786_, v_x_787_, v___y_788_, v___y_789_, v___y_790_, v___y_791_, v___y_792_);
lean_dec(v___y_792_);
lean_dec_ref(v___y_791_);
lean_dec(v___y_790_);
lean_dec_ref(v___y_789_);
return v_res_794_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4(lean_object* v_00_u03b2_795_, lean_object* v_map_796_, lean_object* v_f_797_, lean_object* v___y_798_, lean_object* v___y_799_, lean_object* v___y_800_, lean_object* v___y_801_, lean_object* v___y_802_){
_start:
{
lean_object* v___x_804_; 
v___x_804_ = lp_JunkValues_Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4___redArg(v_map_796_, v_f_797_, v___y_798_, v___y_799_, v___y_800_, v___y_801_, v___y_802_);
return v___x_804_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4___boxed(lean_object* v_00_u03b2_805_, lean_object* v_map_806_, lean_object* v_f_807_, lean_object* v___y_808_, lean_object* v___y_809_, lean_object* v___y_810_, lean_object* v___y_811_, lean_object* v___y_812_, lean_object* v___y_813_){
_start:
{
lean_object* v_res_814_; 
v_res_814_ = lp_JunkValues_Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4(v_00_u03b2_805_, v_map_806_, v_f_807_, v___y_808_, v___y_809_, v___y_810_, v___y_811_, v___y_812_);
lean_dec(v___y_812_);
lean_dec_ref(v___y_811_);
lean_dec(v___y_810_);
lean_dec_ref(v___y_809_);
return v_res_814_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__5(lean_object* v_00_u03b2_815_, lean_object* v_f_816_, lean_object* v_as_817_, size_t v_i_818_, size_t v_stop_819_, lean_object* v_b_820_, lean_object* v___y_821_, lean_object* v___y_822_, lean_object* v___y_823_, lean_object* v___y_824_, lean_object* v___y_825_){
_start:
{
lean_object* v___x_827_; 
v___x_827_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__5___redArg(v_f_816_, v_as_817_, v_i_818_, v_stop_819_, v_b_820_, v___y_821_, v___y_822_, v___y_823_, v___y_824_, v___y_825_);
return v___x_827_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__5___boxed(lean_object* v_00_u03b2_828_, lean_object* v_f_829_, lean_object* v_as_830_, lean_object* v_i_831_, lean_object* v_stop_832_, lean_object* v_b_833_, lean_object* v___y_834_, lean_object* v___y_835_, lean_object* v___y_836_, lean_object* v___y_837_, lean_object* v___y_838_, lean_object* v___y_839_){
_start:
{
size_t v_i_boxed_840_; size_t v_stop_boxed_841_; lean_object* v_res_842_; 
v_i_boxed_840_ = lean_unbox_usize(v_i_831_);
lean_dec(v_i_831_);
v_stop_boxed_841_ = lean_unbox_usize(v_stop_832_);
lean_dec(v_stop_832_);
v_res_842_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__5(v_00_u03b2_828_, v_f_829_, v_as_830_, v_i_boxed_840_, v_stop_boxed_841_, v_b_833_, v___y_834_, v___y_835_, v___y_836_, v___y_837_, v___y_838_);
lean_dec(v___y_838_);
lean_dec_ref(v___y_837_);
lean_dec(v___y_836_);
lean_dec_ref(v___y_835_);
lean_dec_ref(v_as_830_);
return v_res_842_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_discoverRules_spec__0_spec__0_spec__1(lean_object* v_00_u03b2_843_, lean_object* v_i_844_, lean_object* v_source_845_, lean_object* v_target_846_){
_start:
{
lean_object* v___x_847_; 
v___x_847_ = lp_JunkValues___private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_discoverRules_spec__0_spec__0_spec__1___redArg(v_i_844_, v_source_845_, v_target_846_);
return v___x_847_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6___redArg(lean_object* v_map_848_, lean_object* v_f_849_, lean_object* v_init_850_, lean_object* v___y_851_, lean_object* v___y_852_, lean_object* v___y_853_, lean_object* v___y_854_, lean_object* v___y_855_){
_start:
{
lean_object* v___x_857_; 
v___x_857_ = lp_JunkValues_Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9___redArg(v_f_849_, v_map_848_, v_init_850_, v___y_851_, v___y_852_, v___y_853_, v___y_854_, v___y_855_);
return v___x_857_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6___redArg___boxed(lean_object* v_map_858_, lean_object* v_f_859_, lean_object* v_init_860_, lean_object* v___y_861_, lean_object* v___y_862_, lean_object* v___y_863_, lean_object* v___y_864_, lean_object* v___y_865_, lean_object* v___y_866_){
_start:
{
lean_object* v_res_867_; 
v_res_867_ = lp_JunkValues_Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6___redArg(v_map_858_, v_f_859_, v_init_860_, v___y_861_, v___y_862_, v___y_863_, v___y_864_, v___y_865_);
lean_dec(v___y_865_);
lean_dec_ref(v___y_864_);
lean_dec(v___y_863_);
lean_dec_ref(v___y_862_);
return v_res_867_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6(lean_object* v_00_u03c3_868_, lean_object* v_00_u03b2_869_, lean_object* v_map_870_, lean_object* v_f_871_, lean_object* v_init_872_, lean_object* v___y_873_, lean_object* v___y_874_, lean_object* v___y_875_, lean_object* v___y_876_, lean_object* v___y_877_){
_start:
{
lean_object* v___x_879_; 
v___x_879_ = lp_JunkValues_Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9___redArg(v_f_871_, v_map_870_, v_init_872_, v___y_873_, v___y_874_, v___y_875_, v___y_876_, v___y_877_);
return v___x_879_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6___boxed(lean_object* v_00_u03c3_880_, lean_object* v_00_u03b2_881_, lean_object* v_map_882_, lean_object* v_f_883_, lean_object* v_init_884_, lean_object* v___y_885_, lean_object* v___y_886_, lean_object* v___y_887_, lean_object* v___y_888_, lean_object* v___y_889_, lean_object* v___y_890_){
_start:
{
lean_object* v_res_891_; 
v_res_891_ = lp_JunkValues_Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6(v_00_u03c3_880_, v_00_u03b2_881_, v_map_882_, v_f_883_, v_init_884_, v___y_885_, v___y_886_, v___y_887_, v___y_888_, v___y_889_);
lean_dec(v___y_889_);
lean_dec_ref(v___y_888_);
lean_dec(v___y_887_);
lean_dec_ref(v___y_886_);
return v_res_891_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00__private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_discoverRules_spec__0_spec__0_spec__1_spec__5(lean_object* v_00_u03b2_892_, lean_object* v_x_893_, lean_object* v_x_894_){
_start:
{
lean_object* v___x_895_; 
v___x_895_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00__private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_discoverRules_spec__0_spec__0_spec__1_spec__5___redArg(v_x_893_, v_x_894_);
return v___x_895_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9(lean_object* v_00_u03c3_896_, lean_object* v_00_u03b1_897_, lean_object* v_00_u03b2_898_, lean_object* v_f_899_, lean_object* v_x_900_, lean_object* v_x_901_, lean_object* v___y_902_, lean_object* v___y_903_, lean_object* v___y_904_, lean_object* v___y_905_, lean_object* v___y_906_){
_start:
{
lean_object* v___x_908_; 
v___x_908_ = lp_JunkValues_Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9___redArg(v_f_899_, v_x_900_, v_x_901_, v___y_902_, v___y_903_, v___y_904_, v___y_905_, v___y_906_);
return v___x_908_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9___boxed(lean_object* v_00_u03c3_909_, lean_object* v_00_u03b1_910_, lean_object* v_00_u03b2_911_, lean_object* v_f_912_, lean_object* v_x_913_, lean_object* v_x_914_, lean_object* v___y_915_, lean_object* v___y_916_, lean_object* v___y_917_, lean_object* v___y_918_, lean_object* v___y_919_, lean_object* v___y_920_){
_start:
{
lean_object* v_res_921_; 
v_res_921_ = lp_JunkValues_Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9(v_00_u03c3_909_, v_00_u03b1_910_, v_00_u03b2_911_, v_f_912_, v_x_913_, v_x_914_, v___y_915_, v___y_916_, v___y_917_, v___y_918_, v___y_919_);
lean_dec(v___y_919_);
lean_dec_ref(v___y_918_);
lean_dec(v___y_917_);
lean_dec_ref(v___y_916_);
return v_res_921_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9_spec__11(lean_object* v_00_u03b1_922_, lean_object* v_00_u03b2_923_, lean_object* v_00_u03c3_924_, lean_object* v_f_925_, lean_object* v_as_926_, size_t v_i_927_, size_t v_stop_928_, lean_object* v_b_929_, lean_object* v___y_930_, lean_object* v___y_931_, lean_object* v___y_932_, lean_object* v___y_933_, lean_object* v___y_934_){
_start:
{
lean_object* v___x_936_; 
v___x_936_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9_spec__11___redArg(v_f_925_, v_as_926_, v_i_927_, v_stop_928_, v_b_929_, v___y_930_, v___y_931_, v___y_932_, v___y_933_, v___y_934_);
return v___x_936_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9_spec__11___boxed(lean_object* v_00_u03b1_937_, lean_object* v_00_u03b2_938_, lean_object* v_00_u03c3_939_, lean_object* v_f_940_, lean_object* v_as_941_, lean_object* v_i_942_, lean_object* v_stop_943_, lean_object* v_b_944_, lean_object* v___y_945_, lean_object* v___y_946_, lean_object* v___y_947_, lean_object* v___y_948_, lean_object* v___y_949_, lean_object* v___y_950_){
_start:
{
size_t v_i_boxed_951_; size_t v_stop_boxed_952_; lean_object* v_res_953_; 
v_i_boxed_951_ = lean_unbox_usize(v_i_942_);
lean_dec(v_i_942_);
v_stop_boxed_952_ = lean_unbox_usize(v_stop_943_);
lean_dec(v_stop_943_);
v_res_953_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9_spec__11(v_00_u03b1_937_, v_00_u03b2_938_, v_00_u03c3_939_, v_f_940_, v_as_941_, v_i_boxed_951_, v_stop_boxed_952_, v_b_944_, v___y_945_, v___y_946_, v___y_947_, v___y_948_, v___y_949_);
lean_dec(v___y_949_);
lean_dec_ref(v___y_948_);
lean_dec(v___y_947_);
lean_dec_ref(v___y_946_);
lean_dec_ref(v_as_941_);
return v_res_953_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Lean_Data_PersistentHashMap_0__Lean_PersistentHashMap_foldlMAux_traverse___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9_spec__12(lean_object* v_00_u03c3_954_, lean_object* v_00_u03b1_955_, lean_object* v_00_u03b2_956_, lean_object* v_f_957_, lean_object* v_keys_958_, lean_object* v_vals_959_, lean_object* v_heq_960_, lean_object* v_i_961_, lean_object* v_acc_962_, lean_object* v___y_963_, lean_object* v___y_964_, lean_object* v___y_965_, lean_object* v___y_966_, lean_object* v___y_967_){
_start:
{
lean_object* v___x_969_; 
v___x_969_ = lp_JunkValues___private_Lean_Data_PersistentHashMap_0__Lean_PersistentHashMap_foldlMAux_traverse___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9_spec__12___redArg(v_f_957_, v_keys_958_, v_vals_959_, v_i_961_, v_acc_962_, v___y_963_, v___y_964_, v___y_965_, v___y_966_, v___y_967_);
return v___x_969_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Lean_Data_PersistentHashMap_0__Lean_PersistentHashMap_foldlMAux_traverse___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9_spec__12___boxed(lean_object* v_00_u03c3_970_, lean_object* v_00_u03b1_971_, lean_object* v_00_u03b2_972_, lean_object* v_f_973_, lean_object* v_keys_974_, lean_object* v_vals_975_, lean_object* v_heq_976_, lean_object* v_i_977_, lean_object* v_acc_978_, lean_object* v___y_979_, lean_object* v___y_980_, lean_object* v___y_981_, lean_object* v___y_982_, lean_object* v___y_983_, lean_object* v___y_984_){
_start:
{
lean_object* v_res_985_; 
v_res_985_ = lp_JunkValues___private_Lean_Data_PersistentHashMap_0__Lean_PersistentHashMap_foldlMAux_traverse___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9_spec__12(v_00_u03c3_970_, v_00_u03b1_971_, v_00_u03b2_972_, v_f_973_, v_keys_974_, v_vals_975_, v_heq_976_, v_i_977_, v_acc_978_, v___y_979_, v___y_980_, v___y_981_, v___y_982_, v___y_983_);
lean_dec(v___y_983_);
lean_dec_ref(v___y_982_);
lean_dec(v___y_981_);
lean_dec_ref(v___y_980_);
lean_dec_ref(v_vals_975_);
lean_dec_ref(v_keys_974_);
return v_res_985_;
}
}
lean_object* runtime_initialize_Init(uint8_t builtin);
lean_object* runtime_initialize_JunkValues_JunkValues_Rule(uint8_t builtin);
lean_object* runtime_initialize_Std_Data_HashSet(uint8_t builtin);
static bool _G_runtime_initialized = false;
LEAN_EXPORT lean_object* runtime_initialize_JunkValues_JunkValues_Discovery(uint8_t builtin) {
lean_object * res;
if (_G_runtime_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_runtime_initialized = true;
res = runtime_initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = runtime_initialize_JunkValues_JunkValues_Rule(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = runtime_initialize_Std_Data_HashSet(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return lean_io_result_mk_ok(lean_box(0));
}
lean_object* runtime_initialize_Init(uint8_t builtin);
static bool _G_meta_initialized = false;
LEAN_EXPORT lean_object* meta_initialize_JunkValues_JunkValues_Discovery(uint8_t builtin) {
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
lean_object* initialize_JunkValues_JunkValues_Rule(uint8_t builtin);
lean_object* initialize_Std_Data_HashSet(uint8_t builtin);
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_JunkValues_JunkValues_Discovery(uint8_t builtin) {
lean_object * res;
if (_G_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_initialized = true;
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_JunkValues_JunkValues_Rule(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Std_Data_HashSet(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = runtime_initialize_JunkValues_JunkValues_Discovery(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = meta_initialize_JunkValues_JunkValues_Discovery(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return initialize_JunkValues_JunkValues_Discovery(builtin);
}
#ifdef __cplusplus
}
#endif
