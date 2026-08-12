// Lean compiler output
// Module: JunkValues.Extra.Discovery
// Imports: public import Init public meta import Init public import JunkValues.RuleSet public import Std.Data.HashSet
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
lean_object* lean_register_option(lean_object*, lean_object*);
lean_object* l_Lean_Name_mkStr1(lean_object*);
uint8_t l_Lean_Expr_isAppOfArity(lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_Expr_appFn_x21(lean_object*);
lean_object* l_Lean_Expr_appArg_x21(lean_object*);
lean_object* lp_JunkValues_JunkValues_headConst_x3f(lean_object*);
uint8_t lean_name_eq(lean_object*, lean_object*);
uint8_t lean_usize_dec_eq(size_t, size_t);
lean_object* lean_nat_div(lean_object*, lean_object*);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
size_t lean_usize_add(size_t, size_t);
lean_object* lean_st_ref_get(lean_object*);
lean_object* lean_mk_empty_array_with_capacity(lean_object*);
size_t lean_array_size(lean_object*);
uint8_t lean_usize_dec_lt(size_t, size_t);
lean_object* lp_JunkValues_JunkValues_ruleOfTheorem_x3f(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* lean_array_push(lean_object*, lean_object*);
lean_object* l_Lean_ConstantInfo_type(lean_object*);
lean_object* l_Lean_Environment_constants(lean_object*);
lean_object* lean_array_fget_borrowed(lean_object*, lean_object*);
lean_object* l_Lean_Name_mkStr3(lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_Name_mkStr4(lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_Std_DTreeMap_Internal_Impl_Const_get_x3f___at___00Lean_NameMap_find_x3f_spec__0___redArg(lean_object*, lean_object*);
lean_object* l_Nat_reprFast(lean_object*);
lean_object* lean_string_append(lean_object*, lean_object*);
lean_object* lp_JunkValues_JunkValues_registerRuleProvider(lean_object*);
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
static const lean_array_object lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_discoverRules_spec__1___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_discoverRules_spec__1___closed__1 = (const lean_object*)&lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_discoverRules_spec__1___closed__1_value;
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
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Option_register___at___00__private_JunkValues_Extra_Discovery_0__JunkValues_initFn_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4__spec__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Option_register___at___00__private_JunkValues_Extra_Discovery_0__JunkValues_initFn_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4__spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn___closed__0_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "linter"};
static const lean_object* lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn___closed__0_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn___closed__0_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4__value;
static const lean_string_object lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn___closed__1_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "junkValues"};
static const lean_object* lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn___closed__1_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn___closed__1_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4__value;
static const lean_string_object lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn___closed__2_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 10, .m_capacity = 10, .m_length = 9, .m_data = "discovery"};
static const lean_object* lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn___closed__2_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn___closed__2_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4__value;
static const lean_ctor_object lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn___closed__3_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4__value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn___closed__0_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(186, 218, 113, 226, 101, 176, 32, 79)}};
static const lean_ctor_object lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn___closed__3_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4__value_aux_1 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn___closed__3_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4__value_aux_0),((lean_object*)&lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn___closed__1_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(91, 223, 164, 59, 32, 198, 166, 116)}};
static const lean_ctor_object lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn___closed__3_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn___closed__3_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4__value_aux_1),((lean_object*)&lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn___closed__2_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(231, 166, 179, 13, 97, 28, 135, 40)}};
static const lean_object* lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn___closed__3_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn___closed__3_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4__value;
static const lean_string_object lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn___closed__4_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 221, .m_capacity = 221, .m_length = 218, .m_data = "also use junk-value rules discovered by shape, rather than only the ones the project annotated and the catalogue names. Slow, imprecise, and nobody has vouched for what it finds — see `JunkValues/Extra/Discovery.lean`."};
static const lean_object* lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn___closed__4_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn___closed__4_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4__value;
static const lean_ctor_object lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn___closed__5_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*3 + 0, .m_other = 3, .m_tag = 0}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn___closed__4_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4__value),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn___closed__5_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn___closed__5_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4__value;
static const lean_string_object lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn___closed__6_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "JunkValues"};
static const lean_object* lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn___closed__6_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn___closed__6_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4__value;
static const lean_ctor_object lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn___closed__7_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4__value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn___closed__6_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(102, 249, 254, 203, 87, 211, 22, 147)}};
static const lean_ctor_object lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn___closed__7_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4__value_aux_1 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn___closed__7_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4__value_aux_0),((lean_object*)&lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn___closed__0_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(59, 220, 141, 25, 53, 36, 15, 141)}};
static const lean_ctor_object lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn___closed__7_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4__value_aux_2 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn___closed__7_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4__value_aux_1),((lean_object*)&lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn___closed__1_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(70, 62, 173, 21, 98, 150, 200, 98)}};
static const lean_ctor_object lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn___closed__7_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn___closed__7_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4__value_aux_2),((lean_object*)&lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn___closed__2_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(78, 251, 148, 59, 223, 223, 231, 176)}};
static const lean_object* lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn___closed__7_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn___closed__7_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4__value;
LEAN_EXPORT lean_object* lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4_();
LEAN_EXPORT lean_object* lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4____boxed(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_linter_junkValues_discovery;
LEAN_EXPORT uint8_t lp_JunkValues_Lean_Option_get___at___00JunkValues_discoveryProvider_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Option_get___at___00JunkValues_discoveryProvider_spec__0___boxed(lean_object*, lean_object*);
static const lean_ctor_object lp_JunkValues_JunkValues_discoveryProvider___lam__0___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_discoverRules___closed__0_value),((lean_object*)&lp_JunkValues_JunkValues_discoverRules___closed__0_value)}};
static const lean_object* lp_JunkValues_JunkValues_discoveryProvider___lam__0___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_discoveryProvider___lam__0___closed__0_value;
static const lean_string_object lp_JunkValues_JunkValues_discoveryProvider___lam__0___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 23, .m_capacity = 23, .m_length = 22, .m_data = "discovery contributed "};
static const lean_object* lp_JunkValues_JunkValues_discoveryProvider___lam__0___closed__1 = (const lean_object*)&lp_JunkValues_JunkValues_discoveryProvider___lam__0___closed__1_value;
static const lean_string_object lp_JunkValues_JunkValues_discoveryProvider___lam__0___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 202, .m_capacity = 202, .m_length = 201, .m_data = " rules found by shape alone. Nobody has vouched for these: no syntactic criterion separates a junk value from a genuine default, so treat them as candidates for `@[junk_value]` rather than as findings."};
static const lean_object* lp_JunkValues_JunkValues_discoveryProvider___lam__0___closed__2 = (const lean_object*)&lp_JunkValues_JunkValues_discoveryProvider___lam__0___closed__2_value;
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_discoveryProvider___lam__0(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_discoveryProvider___lam__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_closure_object lp_JunkValues_JunkValues_discoveryProvider___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_JunkValues_JunkValues_discoveryProvider___lam__0___boxed, .m_arity = 6, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_JunkValues_JunkValues_discoveryProvider___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_discoveryProvider___closed__0_value;
static const lean_ctor_object lp_JunkValues_JunkValues_discoveryProvider___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn___closed__2_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4__value),((lean_object*)&lp_JunkValues_JunkValues_discoveryProvider___closed__0_value)}};
static const lean_object* lp_JunkValues_JunkValues_discoveryProvider___closed__1 = (const lean_object*)&lp_JunkValues_JunkValues_discoveryProvider___closed__1_value;
LEAN_EXPORT const lean_object* lp_JunkValues_JunkValues_discoveryProvider = (const lean_object*)&lp_JunkValues_JunkValues_discoveryProvider___closed__1_value;
LEAN_EXPORT lean_object* lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn_00___x40_JunkValues_Extra_Discovery_231217443____hygCtx___hyg_2_();
LEAN_EXPORT lean_object* lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn_00___x40_JunkValues_Extra_Discovery_231217443____hygCtx___hyg_2____boxed(lean_object*);
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
LEAN_EXPORT uint8_t lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0_spec__0___redArg(lean_object* v_a_79_, lean_object* v_x_80_){
_start:
{
if (lean_obj_tag(v_x_80_) == 0)
{
uint8_t v___x_81_; 
v___x_81_ = 0;
return v___x_81_;
}
else
{
lean_object* v_key_82_; lean_object* v_tail_83_; uint8_t v___x_84_; 
v_key_82_ = lean_ctor_get(v_x_80_, 0);
v_tail_83_ = lean_ctor_get(v_x_80_, 2);
v___x_84_ = lean_name_eq(v_key_82_, v_a_79_);
if (v___x_84_ == 0)
{
v_x_80_ = v_tail_83_;
goto _start;
}
else
{
return v___x_84_;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0_spec__0___redArg___boxed(lean_object* v_a_86_, lean_object* v_x_87_){
_start:
{
uint8_t v_res_88_; lean_object* v_r_89_; 
v_res_88_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0_spec__0___redArg(v_a_86_, v_x_87_);
lean_dec(v_x_87_);
lean_dec(v_a_86_);
v_r_89_ = lean_box(v_res_88_);
return v_r_89_;
}
}
static uint64_t _init_lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0___redArg___closed__0(void){
_start:
{
lean_object* v___x_90_; uint64_t v___x_91_; 
v___x_90_ = lean_unsigned_to_nat(1723u);
v___x_91_ = lean_uint64_of_nat(v___x_90_);
return v___x_91_;
}
}
LEAN_EXPORT uint8_t lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0___redArg(lean_object* v_m_92_, lean_object* v_a_93_){
_start:
{
lean_object* v_buckets_94_; lean_object* v___x_95_; uint64_t v___y_97_; 
v_buckets_94_ = lean_ctor_get(v_m_92_, 1);
v___x_95_ = lean_array_get_size(v_buckets_94_);
if (lean_obj_tag(v_a_93_) == 0)
{
uint64_t v___x_111_; 
v___x_111_ = lean_uint64_once(&lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0___redArg___closed__0, &lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0___redArg___closed__0_once, _init_lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0___redArg___closed__0);
v___y_97_ = v___x_111_;
goto v___jp_96_;
}
else
{
uint64_t v_hash_112_; 
v_hash_112_ = lean_ctor_get_uint64(v_a_93_, sizeof(void*)*2);
v___y_97_ = v_hash_112_;
goto v___jp_96_;
}
v___jp_96_:
{
uint64_t v___x_98_; uint64_t v___x_99_; uint64_t v_fold_100_; uint64_t v___x_101_; uint64_t v___x_102_; uint64_t v___x_103_; size_t v___x_104_; size_t v___x_105_; size_t v___x_106_; size_t v___x_107_; size_t v___x_108_; lean_object* v___x_109_; uint8_t v___x_110_; 
v___x_98_ = 32ULL;
v___x_99_ = lean_uint64_shift_right(v___y_97_, v___x_98_);
v_fold_100_ = lean_uint64_xor(v___y_97_, v___x_99_);
v___x_101_ = 16ULL;
v___x_102_ = lean_uint64_shift_right(v_fold_100_, v___x_101_);
v___x_103_ = lean_uint64_xor(v_fold_100_, v___x_102_);
v___x_104_ = lean_uint64_to_usize(v___x_103_);
v___x_105_ = lean_usize_of_nat(v___x_95_);
v___x_106_ = ((size_t)1ULL);
v___x_107_ = lean_usize_sub(v___x_105_, v___x_106_);
v___x_108_ = lean_usize_land(v___x_104_, v___x_107_);
v___x_109_ = lean_array_uget_borrowed(v_buckets_94_, v___x_108_);
v___x_110_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0_spec__0___redArg(v_a_93_, v___x_109_);
return v___x_110_;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0___redArg___boxed(lean_object* v_m_113_, lean_object* v_a_114_){
_start:
{
uint8_t v_res_115_; lean_object* v_r_116_; 
v_res_115_ = lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0___redArg(v_m_113_, v_a_114_);
lean_dec(v_a_114_);
lean_dec_ref(v_m_113_);
v_r_116_ = lean_box(v_res_115_);
return v_r_116_;
}
}
LEAN_EXPORT uint8_t lp_JunkValues_JunkValues_looksLikeRule(lean_object* v_defaults_120_, lean_object* v_type_121_){
_start:
{
lean_object* v___x_122_; lean_object* v___x_123_; lean_object* v___x_124_; uint8_t v___x_125_; 
v___x_122_ = lp_JunkValues_JunkValues_conclusionOf(v_type_121_);
v___x_123_ = ((lean_object*)(lp_JunkValues_JunkValues_looksLikeRule___closed__1));
v___x_124_ = lean_unsigned_to_nat(3u);
v___x_125_ = l_Lean_Expr_isAppOfArity(v___x_122_, v___x_123_, v___x_124_);
if (v___x_125_ == 0)
{
lean_dec_ref(v___x_122_);
return v___x_125_;
}
else
{
lean_object* v___x_126_; lean_object* v___x_127_; lean_object* v___x_128_; 
v___x_126_ = l_Lean_Expr_appFn_x21(v___x_122_);
v___x_127_ = l_Lean_Expr_appArg_x21(v___x_126_);
lean_dec_ref(v___x_126_);
v___x_128_ = lp_JunkValues_JunkValues_headConst_x3f(v___x_127_);
lean_dec_ref(v___x_127_);
if (lean_obj_tag(v___x_128_) == 0)
{
uint8_t v___x_129_; 
lean_dec_ref(v___x_122_);
v___x_129_ = 0;
return v___x_129_;
}
else
{
lean_object* v___x_130_; lean_object* v___x_131_; 
lean_dec_ref_known(v___x_128_, 1);
v___x_130_ = l_Lean_Expr_appArg_x21(v___x_122_);
lean_dec_ref(v___x_122_);
v___x_131_ = lp_JunkValues_JunkValues_headConst_x3f(v___x_130_);
lean_dec_ref(v___x_130_);
if (lean_obj_tag(v___x_131_) == 0)
{
uint8_t v___x_132_; 
v___x_132_ = 0;
return v___x_132_;
}
else
{
lean_object* v_val_133_; uint8_t v___x_134_; 
v_val_133_ = lean_ctor_get(v___x_131_, 0);
lean_inc(v_val_133_);
lean_dec_ref_known(v___x_131_, 1);
v___x_134_ = lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0___redArg(v_defaults_120_, v_val_133_);
lean_dec(v_val_133_);
return v___x_134_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_looksLikeRule___boxed(lean_object* v_defaults_135_, lean_object* v_type_136_){
_start:
{
uint8_t v_res_137_; lean_object* v_r_138_; 
v_res_137_ = lp_JunkValues_JunkValues_looksLikeRule(v_defaults_135_, v_type_136_);
lean_dec_ref(v_type_136_);
lean_dec_ref(v_defaults_135_);
v_r_138_ = lean_box(v_res_137_);
return v_r_138_;
}
}
LEAN_EXPORT uint8_t lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0(lean_object* v_00_u03b2_139_, lean_object* v_m_140_, lean_object* v_a_141_){
_start:
{
uint8_t v___x_142_; 
v___x_142_ = lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0___redArg(v_m_140_, v_a_141_);
return v___x_142_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0___boxed(lean_object* v_00_u03b2_143_, lean_object* v_m_144_, lean_object* v_a_145_){
_start:
{
uint8_t v_res_146_; lean_object* v_r_147_; 
v_res_146_ = lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0(v_00_u03b2_143_, v_m_144_, v_a_145_);
lean_dec(v_a_145_);
lean_dec_ref(v_m_144_);
v_r_147_ = lean_box(v_res_146_);
return v_r_147_;
}
}
LEAN_EXPORT uint8_t lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0_spec__0(lean_object* v_00_u03b2_148_, lean_object* v_a_149_, lean_object* v_x_150_){
_start:
{
uint8_t v___x_151_; 
v___x_151_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0_spec__0___redArg(v_a_149_, v_x_150_);
return v___x_151_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0_spec__0___boxed(lean_object* v_00_u03b2_152_, lean_object* v_a_153_, lean_object* v_x_154_){
_start:
{
uint8_t v_res_155_; lean_object* v_r_156_; 
v_res_155_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0_spec__0(v_00_u03b2_152_, v_a_153_, v_x_154_);
lean_dec(v_x_154_);
lean_dec(v_a_153_);
v_r_156_ = lean_box(v_res_155_);
return v_r_156_;
}
}
LEAN_EXPORT uint8_t lp_JunkValues_JunkValues_DiscoveryScope_admits(lean_object* v_scope_157_, lean_object* v_env_158_, lean_object* v_name_159_){
_start:
{
lean_object* v_moduleprefix_x3f_160_; uint8_t v_skipInternal_161_; uint8_t v___y_163_; uint8_t v___y_175_; 
v_moduleprefix_x3f_160_ = lean_ctor_get(v_scope_157_, 0);
v_skipInternal_161_ = lean_ctor_get_uint8(v_scope_157_, sizeof(void*)*1);
if (v_skipInternal_161_ == 0)
{
v___y_163_ = v_skipInternal_161_;
goto v___jp_162_;
}
else
{
uint8_t v___x_178_; 
v___x_178_ = l_Lean_Name_isInternal(v_name_159_);
if (v___x_178_ == 0)
{
uint8_t v___x_179_; 
v___x_179_ = l_Lean_Name_isImplementationDetail(v_name_159_);
v___y_175_ = v___x_179_;
goto v___jp_174_;
}
else
{
v___y_175_ = v___x_178_;
goto v___jp_174_;
}
}
v___jp_162_:
{
uint8_t v___x_164_; 
v___x_164_ = 1;
if (lean_obj_tag(v_moduleprefix_x3f_160_) == 0)
{
return v___x_164_;
}
else
{
lean_object* v_val_165_; lean_object* v___x_166_; 
v_val_165_ = lean_ctor_get(v_moduleprefix_x3f_160_, 0);
v___x_166_ = l_Lean_Environment_getModuleIdxFor_x3f(v_env_158_, v_name_159_);
if (lean_obj_tag(v___x_166_) == 0)
{
return v___x_164_;
}
else
{
lean_object* v_val_167_; lean_object* v___x_168_; lean_object* v___x_169_; lean_object* v___x_170_; uint8_t v___x_171_; 
v_val_167_ = lean_ctor_get(v___x_166_, 0);
lean_inc(v_val_167_);
lean_dec_ref_known(v___x_166_, 1);
v___x_168_ = l_Lean_Environment_header(v_env_158_);
v___x_169_ = l_Lean_EnvironmentHeader_moduleNames(v___x_168_);
v___x_170_ = lean_array_get_size(v___x_169_);
v___x_171_ = lean_nat_dec_lt(v_val_167_, v___x_170_);
if (v___x_171_ == 0)
{
lean_dec_ref(v___x_169_);
lean_dec(v_val_167_);
return v___y_163_;
}
else
{
lean_object* v___x_172_; uint8_t v___x_173_; 
v___x_172_ = lean_array_fget(v___x_169_, v_val_167_);
lean_dec(v_val_167_);
lean_dec_ref(v___x_169_);
v___x_173_ = l_Lean_Name_isPrefixOf(v_val_165_, v___x_172_);
lean_dec(v___x_172_);
return v___x_173_;
}
}
}
}
v___jp_174_:
{
if (v___y_175_ == 0)
{
uint8_t v___x_176_; 
v___x_176_ = l_Lean_isPrivateName(v_name_159_);
if (v___x_176_ == 0)
{
v___y_163_ = v___x_176_;
goto v___jp_162_;
}
else
{
return v___y_175_;
}
}
else
{
uint8_t v___x_177_; 
v___x_177_ = 0;
return v___x_177_;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_DiscoveryScope_admits___boxed(lean_object* v_scope_180_, lean_object* v_env_181_, lean_object* v_name_182_){
_start:
{
uint8_t v_res_183_; lean_object* v_r_184_; 
v_res_183_ = lp_JunkValues_JunkValues_DiscoveryScope_admits(v_scope_180_, v_env_181_, v_name_182_);
lean_dec(v_name_182_);
lean_dec_ref(v_env_181_);
lean_dec_ref(v_scope_180_);
v_r_184_ = lean_box(v_res_183_);
return v_r_184_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_discoverRules___lam__0(lean_object* v_scope_185_, lean_object* v_env_186_, lean_object* v___y_187_, lean_object* v_x_188_, lean_object* v_y_189_, lean_object* v___y_190_, lean_object* v___y_191_, lean_object* v___y_192_, lean_object* v___y_193_, lean_object* v___y_194_){
_start:
{
lean_object* v_a_197_; 
switch(lean_obj_tag(v_y_189_))
{
case 2:
{
goto v___jp_202_;
}
case 0:
{
goto v___jp_202_;
}
default: 
{
lean_dec(v_x_188_);
v_a_197_ = v___y_190_;
goto v___jp_196_;
}
}
v___jp_196_:
{
lean_object* v___x_198_; lean_object* v___x_199_; lean_object* v___x_200_; lean_object* v___x_201_; 
v___x_198_ = lean_box(0);
v___x_199_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_199_, 0, v___x_198_);
lean_ctor_set(v___x_199_, 1, v_a_197_);
v___x_200_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_200_, 0, v___x_199_);
v___x_201_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_201_, 0, v___x_200_);
return v___x_201_;
}
v___jp_202_:
{
uint8_t v___x_203_; 
v___x_203_ = lp_JunkValues_JunkValues_DiscoveryScope_admits(v_scope_185_, v_env_186_, v_x_188_);
if (v___x_203_ == 0)
{
lean_dec(v_x_188_);
v_a_197_ = v___y_190_;
goto v___jp_196_;
}
else
{
lean_object* v___x_204_; uint8_t v___x_205_; 
v___x_204_ = l_Lean_ConstantInfo_type(v_y_189_);
v___x_205_ = lp_JunkValues_JunkValues_looksLikeRule(v___y_187_, v___x_204_);
lean_dec_ref(v___x_204_);
if (v___x_205_ == 0)
{
lean_dec(v_x_188_);
v_a_197_ = v___y_190_;
goto v___jp_196_;
}
else
{
lean_object* v___x_206_; 
v___x_206_ = lean_array_push(v___y_190_, v_x_188_);
v_a_197_ = v___x_206_;
goto v___jp_196_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_discoverRules___lam__0___boxed(lean_object* v_scope_207_, lean_object* v_env_208_, lean_object* v___y_209_, lean_object* v_x_210_, lean_object* v_y_211_, lean_object* v___y_212_, lean_object* v___y_213_, lean_object* v___y_214_, lean_object* v___y_215_, lean_object* v___y_216_, lean_object* v___y_217_){
_start:
{
lean_object* v_res_218_; 
v_res_218_ = lp_JunkValues_JunkValues_discoverRules___lam__0(v_scope_207_, v_env_208_, v___y_209_, v_x_210_, v_y_211_, v___y_212_, v___y_213_, v___y_214_, v___y_215_, v___y_216_);
lean_dec(v___y_216_);
lean_dec_ref(v___y_215_);
lean_dec(v___y_214_);
lean_dec_ref(v___y_213_);
lean_dec_ref(v_y_211_);
lean_dec_ref(v___y_209_);
lean_dec_ref(v_env_208_);
lean_dec_ref(v_scope_207_);
return v_res_218_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00__private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_discoverRules_spec__0_spec__0_spec__1_spec__5___redArg(lean_object* v_x_219_, lean_object* v_x_220_){
_start:
{
if (lean_obj_tag(v_x_220_) == 0)
{
return v_x_219_;
}
else
{
lean_object* v_key_221_; lean_object* v_value_222_; lean_object* v_tail_223_; lean_object* v___x_225_; uint8_t v_isShared_226_; uint8_t v_isSharedCheck_249_; 
v_key_221_ = lean_ctor_get(v_x_220_, 0);
v_value_222_ = lean_ctor_get(v_x_220_, 1);
v_tail_223_ = lean_ctor_get(v_x_220_, 2);
v_isSharedCheck_249_ = !lean_is_exclusive(v_x_220_);
if (v_isSharedCheck_249_ == 0)
{
v___x_225_ = v_x_220_;
v_isShared_226_ = v_isSharedCheck_249_;
goto v_resetjp_224_;
}
else
{
lean_inc(v_tail_223_);
lean_inc(v_value_222_);
lean_inc(v_key_221_);
lean_dec(v_x_220_);
v___x_225_ = lean_box(0);
v_isShared_226_ = v_isSharedCheck_249_;
goto v_resetjp_224_;
}
v_resetjp_224_:
{
lean_object* v___x_227_; uint64_t v___y_229_; 
v___x_227_ = lean_array_get_size(v_x_219_);
if (lean_obj_tag(v_key_221_) == 0)
{
uint64_t v___x_247_; 
v___x_247_ = lean_uint64_once(&lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0___redArg___closed__0, &lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0___redArg___closed__0_once, _init_lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0___redArg___closed__0);
v___y_229_ = v___x_247_;
goto v___jp_228_;
}
else
{
uint64_t v_hash_248_; 
v_hash_248_ = lean_ctor_get_uint64(v_key_221_, sizeof(void*)*2);
v___y_229_ = v_hash_248_;
goto v___jp_228_;
}
v___jp_228_:
{
uint64_t v___x_230_; uint64_t v___x_231_; uint64_t v_fold_232_; uint64_t v___x_233_; uint64_t v___x_234_; uint64_t v___x_235_; size_t v___x_236_; size_t v___x_237_; size_t v___x_238_; size_t v___x_239_; size_t v___x_240_; lean_object* v___x_241_; lean_object* v___x_243_; 
v___x_230_ = 32ULL;
v___x_231_ = lean_uint64_shift_right(v___y_229_, v___x_230_);
v_fold_232_ = lean_uint64_xor(v___y_229_, v___x_231_);
v___x_233_ = 16ULL;
v___x_234_ = lean_uint64_shift_right(v_fold_232_, v___x_233_);
v___x_235_ = lean_uint64_xor(v_fold_232_, v___x_234_);
v___x_236_ = lean_uint64_to_usize(v___x_235_);
v___x_237_ = lean_usize_of_nat(v___x_227_);
v___x_238_ = ((size_t)1ULL);
v___x_239_ = lean_usize_sub(v___x_237_, v___x_238_);
v___x_240_ = lean_usize_land(v___x_236_, v___x_239_);
v___x_241_ = lean_array_uget_borrowed(v_x_219_, v___x_240_);
lean_inc(v___x_241_);
if (v_isShared_226_ == 0)
{
lean_ctor_set(v___x_225_, 2, v___x_241_);
v___x_243_ = v___x_225_;
goto v_reusejp_242_;
}
else
{
lean_object* v_reuseFailAlloc_246_; 
v_reuseFailAlloc_246_ = lean_alloc_ctor(1, 3, 0);
lean_ctor_set(v_reuseFailAlloc_246_, 0, v_key_221_);
lean_ctor_set(v_reuseFailAlloc_246_, 1, v_value_222_);
lean_ctor_set(v_reuseFailAlloc_246_, 2, v___x_241_);
v___x_243_ = v_reuseFailAlloc_246_;
goto v_reusejp_242_;
}
v_reusejp_242_:
{
lean_object* v___x_244_; 
v___x_244_ = lean_array_uset(v_x_219_, v___x_240_, v___x_243_);
v_x_219_ = v___x_244_;
v_x_220_ = v_tail_223_;
goto _start;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_discoverRules_spec__0_spec__0_spec__1___redArg(lean_object* v_i_250_, lean_object* v_source_251_, lean_object* v_target_252_){
_start:
{
lean_object* v___x_253_; uint8_t v___x_254_; 
v___x_253_ = lean_array_get_size(v_source_251_);
v___x_254_ = lean_nat_dec_lt(v_i_250_, v___x_253_);
if (v___x_254_ == 0)
{
lean_dec_ref(v_source_251_);
lean_dec(v_i_250_);
return v_target_252_;
}
else
{
lean_object* v_es_255_; lean_object* v___x_256_; lean_object* v_source_257_; lean_object* v_target_258_; lean_object* v___x_259_; lean_object* v___x_260_; 
v_es_255_ = lean_array_fget(v_source_251_, v_i_250_);
v___x_256_ = lean_box(0);
v_source_257_ = lean_array_fset(v_source_251_, v_i_250_, v___x_256_);
v_target_258_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00__private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_discoverRules_spec__0_spec__0_spec__1_spec__5___redArg(v_target_252_, v_es_255_);
v___x_259_ = lean_unsigned_to_nat(1u);
v___x_260_ = lean_nat_add(v_i_250_, v___x_259_);
lean_dec(v_i_250_);
v_i_250_ = v___x_260_;
v_source_251_ = v_source_257_;
v_target_252_ = v_target_258_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_discoverRules_spec__0_spec__0___redArg(lean_object* v_data_262_){
_start:
{
lean_object* v___x_263_; lean_object* v___x_264_; lean_object* v_nbuckets_265_; lean_object* v___x_266_; lean_object* v___x_267_; lean_object* v___x_268_; lean_object* v___x_269_; 
v___x_263_ = lean_array_get_size(v_data_262_);
v___x_264_ = lean_unsigned_to_nat(2u);
v_nbuckets_265_ = lean_nat_mul(v___x_263_, v___x_264_);
v___x_266_ = lean_unsigned_to_nat(0u);
v___x_267_ = lean_box(0);
v___x_268_ = lean_mk_array(v_nbuckets_265_, v___x_267_);
v___x_269_ = lp_JunkValues___private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_discoverRules_spec__0_spec__0_spec__1___redArg(v___x_266_, v_data_262_, v___x_268_);
return v___x_269_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_discoverRules_spec__0___redArg(lean_object* v_m_270_, lean_object* v_a_271_, lean_object* v_b_272_){
_start:
{
lean_object* v_size_273_; lean_object* v_buckets_274_; lean_object* v___x_275_; uint64_t v___y_277_; 
v_size_273_ = lean_ctor_get(v_m_270_, 0);
v_buckets_274_ = lean_ctor_get(v_m_270_, 1);
v___x_275_ = lean_array_get_size(v_buckets_274_);
if (lean_obj_tag(v_a_271_) == 0)
{
uint64_t v___x_314_; 
v___x_314_ = lean_uint64_once(&lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0___redArg___closed__0, &lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0___redArg___closed__0_once, _init_lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0___redArg___closed__0);
v___y_277_ = v___x_314_;
goto v___jp_276_;
}
else
{
uint64_t v_hash_315_; 
v_hash_315_ = lean_ctor_get_uint64(v_a_271_, sizeof(void*)*2);
v___y_277_ = v_hash_315_;
goto v___jp_276_;
}
v___jp_276_:
{
uint64_t v___x_278_; uint64_t v___x_279_; uint64_t v_fold_280_; uint64_t v___x_281_; uint64_t v___x_282_; uint64_t v___x_283_; size_t v___x_284_; size_t v___x_285_; size_t v___x_286_; size_t v___x_287_; size_t v___x_288_; lean_object* v_bkt_289_; uint8_t v___x_290_; 
v___x_278_ = 32ULL;
v___x_279_ = lean_uint64_shift_right(v___y_277_, v___x_278_);
v_fold_280_ = lean_uint64_xor(v___y_277_, v___x_279_);
v___x_281_ = 16ULL;
v___x_282_ = lean_uint64_shift_right(v_fold_280_, v___x_281_);
v___x_283_ = lean_uint64_xor(v_fold_280_, v___x_282_);
v___x_284_ = lean_uint64_to_usize(v___x_283_);
v___x_285_ = lean_usize_of_nat(v___x_275_);
v___x_286_ = ((size_t)1ULL);
v___x_287_ = lean_usize_sub(v___x_285_, v___x_286_);
v___x_288_ = lean_usize_land(v___x_284_, v___x_287_);
v_bkt_289_ = lean_array_uget_borrowed(v_buckets_274_, v___x_288_);
v___x_290_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_looksLikeRule_spec__0_spec__0___redArg(v_a_271_, v_bkt_289_);
if (v___x_290_ == 0)
{
lean_object* v___x_292_; uint8_t v_isShared_293_; uint8_t v_isSharedCheck_311_; 
lean_inc_ref(v_buckets_274_);
lean_inc(v_size_273_);
v_isSharedCheck_311_ = !lean_is_exclusive(v_m_270_);
if (v_isSharedCheck_311_ == 0)
{
lean_object* v_unused_312_; lean_object* v_unused_313_; 
v_unused_312_ = lean_ctor_get(v_m_270_, 1);
lean_dec(v_unused_312_);
v_unused_313_ = lean_ctor_get(v_m_270_, 0);
lean_dec(v_unused_313_);
v___x_292_ = v_m_270_;
v_isShared_293_ = v_isSharedCheck_311_;
goto v_resetjp_291_;
}
else
{
lean_dec(v_m_270_);
v___x_292_ = lean_box(0);
v_isShared_293_ = v_isSharedCheck_311_;
goto v_resetjp_291_;
}
v_resetjp_291_:
{
lean_object* v___x_294_; lean_object* v_size_x27_295_; lean_object* v___x_296_; lean_object* v_buckets_x27_297_; lean_object* v___x_298_; lean_object* v___x_299_; lean_object* v___x_300_; lean_object* v___x_301_; lean_object* v___x_302_; uint8_t v___x_303_; 
v___x_294_ = lean_unsigned_to_nat(1u);
v_size_x27_295_ = lean_nat_add(v_size_273_, v___x_294_);
lean_dec(v_size_273_);
lean_inc(v_bkt_289_);
v___x_296_ = lean_alloc_ctor(1, 3, 0);
lean_ctor_set(v___x_296_, 0, v_a_271_);
lean_ctor_set(v___x_296_, 1, v_b_272_);
lean_ctor_set(v___x_296_, 2, v_bkt_289_);
v_buckets_x27_297_ = lean_array_uset(v_buckets_274_, v___x_288_, v___x_296_);
v___x_298_ = lean_unsigned_to_nat(4u);
v___x_299_ = lean_nat_mul(v_size_x27_295_, v___x_298_);
v___x_300_ = lean_unsigned_to_nat(3u);
v___x_301_ = lean_nat_div(v___x_299_, v___x_300_);
lean_dec(v___x_299_);
v___x_302_ = lean_array_get_size(v_buckets_x27_297_);
v___x_303_ = lean_nat_dec_le(v___x_301_, v___x_302_);
lean_dec(v___x_301_);
if (v___x_303_ == 0)
{
lean_object* v_val_304_; lean_object* v___x_306_; 
v_val_304_ = lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_discoverRules_spec__0_spec__0___redArg(v_buckets_x27_297_);
if (v_isShared_293_ == 0)
{
lean_ctor_set(v___x_292_, 1, v_val_304_);
lean_ctor_set(v___x_292_, 0, v_size_x27_295_);
v___x_306_ = v___x_292_;
goto v_reusejp_305_;
}
else
{
lean_object* v_reuseFailAlloc_307_; 
v_reuseFailAlloc_307_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_307_, 0, v_size_x27_295_);
lean_ctor_set(v_reuseFailAlloc_307_, 1, v_val_304_);
v___x_306_ = v_reuseFailAlloc_307_;
goto v_reusejp_305_;
}
v_reusejp_305_:
{
return v___x_306_;
}
}
else
{
lean_object* v___x_309_; 
if (v_isShared_293_ == 0)
{
lean_ctor_set(v___x_292_, 1, v_buckets_x27_297_);
lean_ctor_set(v___x_292_, 0, v_size_x27_295_);
v___x_309_ = v___x_292_;
goto v_reusejp_308_;
}
else
{
lean_object* v_reuseFailAlloc_310_; 
v_reuseFailAlloc_310_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_310_, 0, v_size_x27_295_);
lean_ctor_set(v_reuseFailAlloc_310_, 1, v_buckets_x27_297_);
v___x_309_ = v_reuseFailAlloc_310_;
goto v_reusejp_308_;
}
v_reusejp_308_:
{
return v___x_309_;
}
}
}
}
else
{
lean_dec(v_b_272_);
lean_dec(v_a_271_);
return v_m_270_;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00JunkValues_discoverRules_spec__3(lean_object* v_as_316_, size_t v_i_317_, size_t v_stop_318_, lean_object* v_b_319_){
_start:
{
uint8_t v___x_320_; 
v___x_320_ = lean_usize_dec_eq(v_i_317_, v_stop_318_);
if (v___x_320_ == 0)
{
lean_object* v___x_321_; lean_object* v___x_322_; lean_object* v___x_323_; size_t v___x_324_; size_t v___x_325_; 
v___x_321_ = lean_array_uget_borrowed(v_as_316_, v_i_317_);
v___x_322_ = lean_box(0);
lean_inc(v___x_321_);
v___x_323_ = lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_discoverRules_spec__0___redArg(v_b_319_, v___x_321_, v___x_322_);
v___x_324_ = ((size_t)1ULL);
v___x_325_ = lean_usize_add(v_i_317_, v___x_324_);
v_i_317_ = v___x_325_;
v_b_319_ = v___x_323_;
goto _start;
}
else
{
return v_b_319_;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00JunkValues_discoverRules_spec__3___boxed(lean_object* v_as_327_, lean_object* v_i_328_, lean_object* v_stop_329_, lean_object* v_b_330_){
_start:
{
size_t v_i_boxed_331_; size_t v_stop_boxed_332_; lean_object* v_res_333_; 
v_i_boxed_331_ = lean_unbox_usize(v_i_328_);
lean_dec(v_i_328_);
v_stop_boxed_332_ = lean_unbox_usize(v_stop_329_);
lean_dec(v_stop_329_);
v_res_333_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00JunkValues_discoverRules_spec__3(v_as_327_, v_i_boxed_331_, v_stop_boxed_332_, v_b_330_);
lean_dec_ref(v_as_327_);
return v_res_333_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4___redArg___lam__0(lean_object* v_f_334_, lean_object* v_x_335_, lean_object* v___y_336_, lean_object* v___y_337_, lean_object* v___y_338_, lean_object* v___y_339_, lean_object* v___y_340_, lean_object* v___y_341_, lean_object* v___y_342_){
_start:
{
lean_object* v___x_344_; 
lean_inc(v___y_342_);
lean_inc_ref(v___y_341_);
lean_inc(v___y_340_);
lean_inc_ref(v___y_339_);
v___x_344_ = lean_apply_8(v_f_334_, v___y_336_, v___y_337_, v___y_338_, v___y_339_, v___y_340_, v___y_341_, v___y_342_, lean_box(0));
return v___x_344_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4___redArg___lam__0___boxed(lean_object* v_f_345_, lean_object* v_x_346_, lean_object* v___y_347_, lean_object* v___y_348_, lean_object* v___y_349_, lean_object* v___y_350_, lean_object* v___y_351_, lean_object* v___y_352_, lean_object* v___y_353_, lean_object* v___y_354_){
_start:
{
lean_object* v_res_355_; 
v_res_355_ = lp_JunkValues_Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4___redArg___lam__0(v_f_345_, v_x_346_, v___y_347_, v___y_348_, v___y_349_, v___y_350_, v___y_351_, v___y_352_, v___y_353_);
lean_dec(v___y_353_);
lean_dec_ref(v___y_352_);
lean_dec(v___y_351_);
lean_dec_ref(v___y_350_);
return v_res_355_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Lean_Data_PersistentHashMap_0__Lean_PersistentHashMap_foldlMAux_traverse___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9_spec__12___redArg(lean_object* v_f_356_, lean_object* v_keys_357_, lean_object* v_vals_358_, lean_object* v_i_359_, lean_object* v_acc_360_, lean_object* v___y_361_, lean_object* v___y_362_, lean_object* v___y_363_, lean_object* v___y_364_, lean_object* v___y_365_){
_start:
{
lean_object* v___x_367_; uint8_t v___x_368_; 
v___x_367_ = lean_array_get_size(v_keys_357_);
v___x_368_ = lean_nat_dec_lt(v_i_359_, v___x_367_);
if (v___x_368_ == 0)
{
lean_object* v___x_369_; lean_object* v___x_370_; lean_object* v___x_371_; 
lean_dec(v_i_359_);
lean_dec_ref(v_f_356_);
v___x_369_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_369_, 0, v_acc_360_);
lean_ctor_set(v___x_369_, 1, v___y_361_);
v___x_370_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_370_, 0, v___x_369_);
v___x_371_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_371_, 0, v___x_370_);
return v___x_371_;
}
else
{
lean_object* v_k_372_; lean_object* v_v_373_; lean_object* v___x_374_; 
v_k_372_ = lean_array_fget_borrowed(v_keys_357_, v_i_359_);
v_v_373_ = lean_array_fget_borrowed(v_vals_358_, v_i_359_);
lean_inc_ref(v_f_356_);
lean_inc(v___y_365_);
lean_inc_ref(v___y_364_);
lean_inc(v___y_363_);
lean_inc_ref(v___y_362_);
lean_inc(v_v_373_);
lean_inc(v_k_372_);
v___x_374_ = lean_apply_9(v_f_356_, v_acc_360_, v_k_372_, v_v_373_, v___y_361_, v___y_362_, v___y_363_, v___y_364_, v___y_365_, lean_box(0));
if (lean_obj_tag(v___x_374_) == 0)
{
lean_object* v_a_375_; 
v_a_375_ = lean_ctor_get(v___x_374_, 0);
lean_inc(v_a_375_);
if (lean_obj_tag(v_a_375_) == 0)
{
lean_dec_ref_known(v_a_375_, 1);
lean_dec(v_i_359_);
lean_dec_ref(v_f_356_);
return v___x_374_;
}
else
{
lean_object* v_a_376_; lean_object* v_fst_377_; lean_object* v_snd_378_; lean_object* v___x_379_; lean_object* v___x_380_; 
lean_dec_ref_known(v___x_374_, 1);
v_a_376_ = lean_ctor_get(v_a_375_, 0);
lean_inc(v_a_376_);
lean_dec_ref_known(v_a_375_, 1);
v_fst_377_ = lean_ctor_get(v_a_376_, 0);
lean_inc(v_fst_377_);
v_snd_378_ = lean_ctor_get(v_a_376_, 1);
lean_inc(v_snd_378_);
lean_dec(v_a_376_);
v___x_379_ = lean_unsigned_to_nat(1u);
v___x_380_ = lean_nat_add(v_i_359_, v___x_379_);
lean_dec(v_i_359_);
v_i_359_ = v___x_380_;
v_acc_360_ = v_fst_377_;
v___y_361_ = v_snd_378_;
goto _start;
}
}
else
{
lean_dec(v_i_359_);
lean_dec_ref(v_f_356_);
return v___x_374_;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Lean_Data_PersistentHashMap_0__Lean_PersistentHashMap_foldlMAux_traverse___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9_spec__12___redArg___boxed(lean_object* v_f_382_, lean_object* v_keys_383_, lean_object* v_vals_384_, lean_object* v_i_385_, lean_object* v_acc_386_, lean_object* v___y_387_, lean_object* v___y_388_, lean_object* v___y_389_, lean_object* v___y_390_, lean_object* v___y_391_, lean_object* v___y_392_){
_start:
{
lean_object* v_res_393_; 
v_res_393_ = lp_JunkValues___private_Lean_Data_PersistentHashMap_0__Lean_PersistentHashMap_foldlMAux_traverse___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9_spec__12___redArg(v_f_382_, v_keys_383_, v_vals_384_, v_i_385_, v_acc_386_, v___y_387_, v___y_388_, v___y_389_, v___y_390_, v___y_391_);
lean_dec(v___y_391_);
lean_dec_ref(v___y_390_);
lean_dec(v___y_389_);
lean_dec_ref(v___y_388_);
lean_dec_ref(v_vals_384_);
lean_dec_ref(v_keys_383_);
return v_res_393_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9___redArg(lean_object* v_f_394_, lean_object* v_x_395_, lean_object* v_x_396_, lean_object* v___y_397_, lean_object* v___y_398_, lean_object* v___y_399_, lean_object* v___y_400_, lean_object* v___y_401_){
_start:
{
if (lean_obj_tag(v_x_395_) == 0)
{
lean_object* v_es_403_; lean_object* v___x_405_; uint8_t v_isShared_406_; uint8_t v_isSharedCheck_427_; 
v_es_403_ = lean_ctor_get(v_x_395_, 0);
v_isSharedCheck_427_ = !lean_is_exclusive(v_x_395_);
if (v_isSharedCheck_427_ == 0)
{
v___x_405_ = v_x_395_;
v_isShared_406_ = v_isSharedCheck_427_;
goto v_resetjp_404_;
}
else
{
lean_inc(v_es_403_);
lean_dec(v_x_395_);
v___x_405_ = lean_box(0);
v_isShared_406_ = v_isSharedCheck_427_;
goto v_resetjp_404_;
}
v_resetjp_404_:
{
lean_object* v___x_407_; lean_object* v___x_408_; uint8_t v___x_409_; 
v___x_407_ = lean_unsigned_to_nat(0u);
v___x_408_ = lean_array_get_size(v_es_403_);
v___x_409_ = lean_nat_dec_lt(v___x_407_, v___x_408_);
if (v___x_409_ == 0)
{
lean_object* v___x_410_; lean_object* v___x_412_; 
lean_dec_ref(v_es_403_);
lean_dec_ref(v_f_394_);
v___x_410_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_410_, 0, v_x_396_);
lean_ctor_set(v___x_410_, 1, v___y_397_);
if (v_isShared_406_ == 0)
{
lean_ctor_set_tag(v___x_405_, 1);
lean_ctor_set(v___x_405_, 0, v___x_410_);
v___x_412_ = v___x_405_;
goto v_reusejp_411_;
}
else
{
lean_object* v_reuseFailAlloc_414_; 
v_reuseFailAlloc_414_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_414_, 0, v___x_410_);
v___x_412_ = v_reuseFailAlloc_414_;
goto v_reusejp_411_;
}
v_reusejp_411_:
{
lean_object* v___x_413_; 
v___x_413_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_413_, 0, v___x_412_);
return v___x_413_;
}
}
else
{
uint8_t v___x_415_; 
v___x_415_ = lean_nat_dec_le(v___x_408_, v___x_408_);
if (v___x_415_ == 0)
{
if (v___x_409_ == 0)
{
lean_object* v___x_416_; lean_object* v___x_418_; 
lean_dec_ref(v_es_403_);
lean_dec_ref(v_f_394_);
v___x_416_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_416_, 0, v_x_396_);
lean_ctor_set(v___x_416_, 1, v___y_397_);
if (v_isShared_406_ == 0)
{
lean_ctor_set_tag(v___x_405_, 1);
lean_ctor_set(v___x_405_, 0, v___x_416_);
v___x_418_ = v___x_405_;
goto v_reusejp_417_;
}
else
{
lean_object* v_reuseFailAlloc_420_; 
v_reuseFailAlloc_420_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_420_, 0, v___x_416_);
v___x_418_ = v_reuseFailAlloc_420_;
goto v_reusejp_417_;
}
v_reusejp_417_:
{
lean_object* v___x_419_; 
v___x_419_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_419_, 0, v___x_418_);
return v___x_419_;
}
}
else
{
size_t v___x_421_; size_t v___x_422_; lean_object* v___x_423_; 
lean_del_object(v___x_405_);
v___x_421_ = ((size_t)0ULL);
v___x_422_ = lean_usize_of_nat(v___x_408_);
v___x_423_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9_spec__11___redArg(v_f_394_, v_es_403_, v___x_421_, v___x_422_, v_x_396_, v___y_397_, v___y_398_, v___y_399_, v___y_400_, v___y_401_);
lean_dec_ref(v_es_403_);
return v___x_423_;
}
}
else
{
size_t v___x_424_; size_t v___x_425_; lean_object* v___x_426_; 
lean_del_object(v___x_405_);
v___x_424_ = ((size_t)0ULL);
v___x_425_ = lean_usize_of_nat(v___x_408_);
v___x_426_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9_spec__11___redArg(v_f_394_, v_es_403_, v___x_424_, v___x_425_, v_x_396_, v___y_397_, v___y_398_, v___y_399_, v___y_400_, v___y_401_);
lean_dec_ref(v_es_403_);
return v___x_426_;
}
}
}
}
else
{
lean_object* v_ks_428_; lean_object* v_vs_429_; lean_object* v___x_430_; lean_object* v___x_431_; 
v_ks_428_ = lean_ctor_get(v_x_395_, 0);
lean_inc_ref(v_ks_428_);
v_vs_429_ = lean_ctor_get(v_x_395_, 1);
lean_inc_ref(v_vs_429_);
lean_dec_ref_known(v_x_395_, 2);
v___x_430_ = lean_unsigned_to_nat(0u);
v___x_431_ = lp_JunkValues___private_Lean_Data_PersistentHashMap_0__Lean_PersistentHashMap_foldlMAux_traverse___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9_spec__12___redArg(v_f_394_, v_ks_428_, v_vs_429_, v___x_430_, v_x_396_, v___y_397_, v___y_398_, v___y_399_, v___y_400_, v___y_401_);
lean_dec_ref(v_vs_429_);
lean_dec_ref(v_ks_428_);
return v___x_431_;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9_spec__11___redArg(lean_object* v_f_432_, lean_object* v_as_433_, size_t v_i_434_, size_t v_stop_435_, lean_object* v_b_436_, lean_object* v___y_437_, lean_object* v___y_438_, lean_object* v___y_439_, lean_object* v___y_440_, lean_object* v___y_441_){
_start:
{
lean_object* v_fst_444_; lean_object* v_snd_445_; lean_object* v___y_450_; uint8_t v___x_455_; 
v___x_455_ = lean_usize_dec_eq(v_i_434_, v_stop_435_);
if (v___x_455_ == 0)
{
lean_object* v___x_456_; 
v___x_456_ = lean_array_uget_borrowed(v_as_433_, v_i_434_);
switch(lean_obj_tag(v___x_456_))
{
case 0:
{
lean_object* v_key_457_; lean_object* v_val_458_; lean_object* v___x_459_; 
v_key_457_ = lean_ctor_get(v___x_456_, 0);
v_val_458_ = lean_ctor_get(v___x_456_, 1);
lean_inc_ref(v_f_432_);
lean_inc(v___y_441_);
lean_inc_ref(v___y_440_);
lean_inc(v___y_439_);
lean_inc_ref(v___y_438_);
lean_inc(v_val_458_);
lean_inc(v_key_457_);
v___x_459_ = lean_apply_9(v_f_432_, v_b_436_, v_key_457_, v_val_458_, v___y_437_, v___y_438_, v___y_439_, v___y_440_, v___y_441_, lean_box(0));
v___y_450_ = v___x_459_;
goto v___jp_449_;
}
case 1:
{
lean_object* v_node_460_; lean_object* v___x_461_; 
v_node_460_ = lean_ctor_get(v___x_456_, 0);
lean_inc(v_node_460_);
lean_inc_ref(v_f_432_);
v___x_461_ = lp_JunkValues_Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9___redArg(v_f_432_, v_node_460_, v_b_436_, v___y_437_, v___y_438_, v___y_439_, v___y_440_, v___y_441_);
v___y_450_ = v___x_461_;
goto v___jp_449_;
}
default: 
{
v_fst_444_ = v_b_436_;
v_snd_445_ = v___y_437_;
goto v___jp_443_;
}
}
}
else
{
lean_object* v___x_462_; lean_object* v___x_463_; lean_object* v___x_464_; 
lean_dec_ref(v_f_432_);
v___x_462_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_462_, 0, v_b_436_);
lean_ctor_set(v___x_462_, 1, v___y_437_);
v___x_463_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_463_, 0, v___x_462_);
v___x_464_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_464_, 0, v___x_463_);
return v___x_464_;
}
v___jp_443_:
{
size_t v___x_446_; size_t v___x_447_; 
v___x_446_ = ((size_t)1ULL);
v___x_447_ = lean_usize_add(v_i_434_, v___x_446_);
v_i_434_ = v___x_447_;
v_b_436_ = v_fst_444_;
v___y_437_ = v_snd_445_;
goto _start;
}
v___jp_449_:
{
if (lean_obj_tag(v___y_450_) == 0)
{
lean_object* v_a_451_; 
v_a_451_ = lean_ctor_get(v___y_450_, 0);
if (lean_obj_tag(v_a_451_) == 0)
{
lean_dec_ref(v_f_432_);
return v___y_450_;
}
else
{
lean_object* v_a_452_; lean_object* v_fst_453_; lean_object* v_snd_454_; 
lean_inc_ref(v_a_451_);
lean_dec_ref_known(v___y_450_, 1);
v_a_452_ = lean_ctor_get(v_a_451_, 0);
lean_inc(v_a_452_);
lean_dec_ref_known(v_a_451_, 1);
v_fst_453_ = lean_ctor_get(v_a_452_, 0);
lean_inc(v_fst_453_);
v_snd_454_ = lean_ctor_get(v_a_452_, 1);
lean_inc(v_snd_454_);
lean_dec(v_a_452_);
v_fst_444_ = v_fst_453_;
v_snd_445_ = v_snd_454_;
goto v___jp_443_;
}
}
else
{
lean_dec_ref(v_f_432_);
return v___y_450_;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9_spec__11___redArg___boxed(lean_object* v_f_465_, lean_object* v_as_466_, lean_object* v_i_467_, lean_object* v_stop_468_, lean_object* v_b_469_, lean_object* v___y_470_, lean_object* v___y_471_, lean_object* v___y_472_, lean_object* v___y_473_, lean_object* v___y_474_, lean_object* v___y_475_){
_start:
{
size_t v_i_boxed_476_; size_t v_stop_boxed_477_; lean_object* v_res_478_; 
v_i_boxed_476_ = lean_unbox_usize(v_i_467_);
lean_dec(v_i_467_);
v_stop_boxed_477_ = lean_unbox_usize(v_stop_468_);
lean_dec(v_stop_468_);
v_res_478_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9_spec__11___redArg(v_f_465_, v_as_466_, v_i_boxed_476_, v_stop_boxed_477_, v_b_469_, v___y_470_, v___y_471_, v___y_472_, v___y_473_, v___y_474_);
lean_dec(v___y_474_);
lean_dec_ref(v___y_473_);
lean_dec(v___y_472_);
lean_dec_ref(v___y_471_);
lean_dec_ref(v_as_466_);
return v_res_478_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9___redArg___boxed(lean_object* v_f_479_, lean_object* v_x_480_, lean_object* v_x_481_, lean_object* v___y_482_, lean_object* v___y_483_, lean_object* v___y_484_, lean_object* v___y_485_, lean_object* v___y_486_, lean_object* v___y_487_){
_start:
{
lean_object* v_res_488_; 
v_res_488_ = lp_JunkValues_Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9___redArg(v_f_479_, v_x_480_, v_x_481_, v___y_482_, v___y_483_, v___y_484_, v___y_485_, v___y_486_);
lean_dec(v___y_486_);
lean_dec_ref(v___y_485_);
lean_dec(v___y_484_);
lean_dec_ref(v___y_483_);
return v_res_488_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4___redArg(lean_object* v_map_489_, lean_object* v_f_490_, lean_object* v___y_491_, lean_object* v___y_492_, lean_object* v___y_493_, lean_object* v___y_494_, lean_object* v___y_495_){
_start:
{
lean_object* v___f_497_; lean_object* v___x_498_; lean_object* v___x_499_; 
v___f_497_ = lean_alloc_closure((void*)(lp_JunkValues_Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4___redArg___lam__0___boxed), 10, 1);
lean_closure_set(v___f_497_, 0, v_f_490_);
v___x_498_ = lean_box(0);
v___x_499_ = lp_JunkValues_Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9___redArg(v___f_497_, v_map_489_, v___x_498_, v___y_491_, v___y_492_, v___y_493_, v___y_494_, v___y_495_);
return v___x_499_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4___redArg___boxed(lean_object* v_map_500_, lean_object* v_f_501_, lean_object* v___y_502_, lean_object* v___y_503_, lean_object* v___y_504_, lean_object* v___y_505_, lean_object* v___y_506_, lean_object* v___y_507_){
_start:
{
lean_object* v_res_508_; 
v_res_508_ = lp_JunkValues_Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4___redArg(v_map_500_, v_f_501_, v___y_502_, v___y_503_, v___y_504_, v___y_505_, v___y_506_);
lean_dec(v___y_506_);
lean_dec_ref(v___y_505_);
lean_dec(v___y_504_);
lean_dec_ref(v___y_503_);
return v_res_508_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__3___redArg(lean_object* v_f_509_, lean_object* v_x_510_, lean_object* v_x_511_, lean_object* v___y_512_, lean_object* v___y_513_, lean_object* v___y_514_, lean_object* v___y_515_, lean_object* v___y_516_){
_start:
{
if (lean_obj_tag(v_x_511_) == 0)
{
lean_object* v___x_518_; lean_object* v___x_519_; lean_object* v___x_520_; 
lean_dec_ref(v_f_509_);
v___x_518_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_518_, 0, v_x_510_);
lean_ctor_set(v___x_518_, 1, v___y_512_);
v___x_519_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_519_, 0, v___x_518_);
v___x_520_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_520_, 0, v___x_519_);
return v___x_520_;
}
else
{
lean_object* v_key_521_; lean_object* v_value_522_; lean_object* v_tail_523_; lean_object* v___x_524_; 
v_key_521_ = lean_ctor_get(v_x_511_, 0);
lean_inc(v_key_521_);
v_value_522_ = lean_ctor_get(v_x_511_, 1);
lean_inc(v_value_522_);
v_tail_523_ = lean_ctor_get(v_x_511_, 2);
lean_inc(v_tail_523_);
lean_dec_ref_known(v_x_511_, 3);
lean_inc_ref(v_f_509_);
lean_inc(v___y_516_);
lean_inc_ref(v___y_515_);
lean_inc(v___y_514_);
lean_inc_ref(v___y_513_);
v___x_524_ = lean_apply_8(v_f_509_, v_key_521_, v_value_522_, v___y_512_, v___y_513_, v___y_514_, v___y_515_, v___y_516_, lean_box(0));
if (lean_obj_tag(v___x_524_) == 0)
{
lean_object* v_a_525_; 
v_a_525_ = lean_ctor_get(v___x_524_, 0);
lean_inc(v_a_525_);
if (lean_obj_tag(v_a_525_) == 0)
{
lean_dec_ref_known(v_a_525_, 1);
lean_dec(v_tail_523_);
lean_dec_ref(v_f_509_);
return v___x_524_;
}
else
{
lean_object* v_a_526_; lean_object* v_fst_527_; lean_object* v_snd_528_; 
lean_dec_ref_known(v___x_524_, 1);
v_a_526_ = lean_ctor_get(v_a_525_, 0);
lean_inc(v_a_526_);
lean_dec_ref_known(v_a_525_, 1);
v_fst_527_ = lean_ctor_get(v_a_526_, 0);
lean_inc(v_fst_527_);
v_snd_528_ = lean_ctor_get(v_a_526_, 1);
lean_inc(v_snd_528_);
lean_dec(v_a_526_);
v_x_510_ = v_fst_527_;
v_x_511_ = v_tail_523_;
v___y_512_ = v_snd_528_;
goto _start;
}
}
else
{
lean_dec(v_tail_523_);
lean_dec_ref(v_f_509_);
return v___x_524_;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__3___redArg___boxed(lean_object* v_f_530_, lean_object* v_x_531_, lean_object* v_x_532_, lean_object* v___y_533_, lean_object* v___y_534_, lean_object* v___y_535_, lean_object* v___y_536_, lean_object* v___y_537_, lean_object* v___y_538_){
_start:
{
lean_object* v_res_539_; 
v_res_539_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__3___redArg(v_f_530_, v_x_531_, v_x_532_, v___y_533_, v___y_534_, v___y_535_, v___y_536_, v___y_537_);
lean_dec(v___y_537_);
lean_dec_ref(v___y_536_);
lean_dec(v___y_535_);
lean_dec_ref(v___y_534_);
return v_res_539_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__5___redArg(lean_object* v_f_540_, lean_object* v_as_541_, size_t v_i_542_, size_t v_stop_543_, lean_object* v_b_544_, lean_object* v___y_545_, lean_object* v___y_546_, lean_object* v___y_547_, lean_object* v___y_548_, lean_object* v___y_549_){
_start:
{
uint8_t v___x_551_; 
v___x_551_ = lean_usize_dec_eq(v_i_542_, v_stop_543_);
if (v___x_551_ == 0)
{
lean_object* v___x_552_; lean_object* v___x_553_; lean_object* v___x_554_; 
v___x_552_ = lean_array_uget_borrowed(v_as_541_, v_i_542_);
v___x_553_ = lean_box(0);
lean_inc(v___x_552_);
lean_inc_ref(v_f_540_);
v___x_554_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__3___redArg(v_f_540_, v___x_553_, v___x_552_, v___y_545_, v___y_546_, v___y_547_, v___y_548_, v___y_549_);
if (lean_obj_tag(v___x_554_) == 0)
{
lean_object* v_a_555_; 
v_a_555_ = lean_ctor_get(v___x_554_, 0);
lean_inc(v_a_555_);
if (lean_obj_tag(v_a_555_) == 0)
{
lean_dec_ref_known(v_a_555_, 1);
lean_dec_ref(v_f_540_);
return v___x_554_;
}
else
{
lean_object* v_a_556_; lean_object* v_fst_557_; lean_object* v_snd_558_; size_t v___x_559_; size_t v___x_560_; 
lean_dec_ref_known(v___x_554_, 1);
v_a_556_ = lean_ctor_get(v_a_555_, 0);
lean_inc(v_a_556_);
lean_dec_ref_known(v_a_555_, 1);
v_fst_557_ = lean_ctor_get(v_a_556_, 0);
lean_inc(v_fst_557_);
v_snd_558_ = lean_ctor_get(v_a_556_, 1);
lean_inc(v_snd_558_);
lean_dec(v_a_556_);
v___x_559_ = ((size_t)1ULL);
v___x_560_ = lean_usize_add(v_i_542_, v___x_559_);
v_i_542_ = v___x_560_;
v_b_544_ = v_fst_557_;
v___y_545_ = v_snd_558_;
goto _start;
}
}
else
{
lean_dec_ref(v_f_540_);
return v___x_554_;
}
}
else
{
lean_object* v___x_562_; lean_object* v___x_563_; lean_object* v___x_564_; 
lean_dec_ref(v_f_540_);
v___x_562_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_562_, 0, v_b_544_);
lean_ctor_set(v___x_562_, 1, v___y_545_);
v___x_563_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_563_, 0, v___x_562_);
v___x_564_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_564_, 0, v___x_563_);
return v___x_564_;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__5___redArg___boxed(lean_object* v_f_565_, lean_object* v_as_566_, lean_object* v_i_567_, lean_object* v_stop_568_, lean_object* v_b_569_, lean_object* v___y_570_, lean_object* v___y_571_, lean_object* v___y_572_, lean_object* v___y_573_, lean_object* v___y_574_, lean_object* v___y_575_){
_start:
{
size_t v_i_boxed_576_; size_t v_stop_boxed_577_; lean_object* v_res_578_; 
v_i_boxed_576_ = lean_unbox_usize(v_i_567_);
lean_dec(v_i_567_);
v_stop_boxed_577_ = lean_unbox_usize(v_stop_568_);
lean_dec(v_stop_568_);
v_res_578_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__5___redArg(v_f_565_, v_as_566_, v_i_boxed_576_, v_stop_boxed_577_, v_b_569_, v___y_570_, v___y_571_, v___y_572_, v___y_573_, v___y_574_);
lean_dec(v___y_574_);
lean_dec_ref(v___y_573_);
lean_dec(v___y_572_);
lean_dec_ref(v___y_571_);
lean_dec_ref(v_as_566_);
return v_res_578_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2___redArg(lean_object* v_s_579_, lean_object* v_f_580_, lean_object* v___y_581_, lean_object* v___y_582_, lean_object* v___y_583_, lean_object* v___y_584_, lean_object* v___y_585_){
_start:
{
lean_object* v_map_u2081_587_; lean_object* v_map_u2082_588_; lean_object* v_buckets_589_; lean_object* v___x_590_; lean_object* v___x_591_; uint8_t v___x_592_; 
v_map_u2081_587_ = lean_ctor_get(v_s_579_, 0);
lean_inc_ref(v_map_u2081_587_);
v_map_u2082_588_ = lean_ctor_get(v_s_579_, 1);
lean_inc_ref(v_map_u2082_588_);
lean_dec_ref(v_s_579_);
v_buckets_589_ = lean_ctor_get(v_map_u2081_587_, 1);
lean_inc_ref(v_buckets_589_);
lean_dec_ref(v_map_u2081_587_);
v___x_590_ = lean_unsigned_to_nat(0u);
v___x_591_ = lean_array_get_size(v_buckets_589_);
v___x_592_ = lean_nat_dec_lt(v___x_590_, v___x_591_);
if (v___x_592_ == 0)
{
lean_object* v___x_593_; 
lean_dec_ref(v_buckets_589_);
v___x_593_ = lp_JunkValues_Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4___redArg(v_map_u2082_588_, v_f_580_, v___y_581_, v___y_582_, v___y_583_, v___y_584_, v___y_585_);
return v___x_593_;
}
else
{
lean_object* v___x_594_; uint8_t v___x_595_; 
v___x_594_ = lean_box(0);
v___x_595_ = lean_nat_dec_le(v___x_591_, v___x_591_);
if (v___x_595_ == 0)
{
if (v___x_592_ == 0)
{
lean_object* v___x_596_; 
lean_dec_ref(v_buckets_589_);
v___x_596_ = lp_JunkValues_Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4___redArg(v_map_u2082_588_, v_f_580_, v___y_581_, v___y_582_, v___y_583_, v___y_584_, v___y_585_);
return v___x_596_;
}
else
{
size_t v___x_597_; size_t v___x_598_; lean_object* v___x_599_; 
v___x_597_ = ((size_t)0ULL);
v___x_598_ = lean_usize_of_nat(v___x_591_);
lean_inc_ref(v_f_580_);
v___x_599_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__5___redArg(v_f_580_, v_buckets_589_, v___x_597_, v___x_598_, v___x_594_, v___y_581_, v___y_582_, v___y_583_, v___y_584_, v___y_585_);
lean_dec_ref(v_buckets_589_);
if (lean_obj_tag(v___x_599_) == 0)
{
lean_object* v_a_600_; 
v_a_600_ = lean_ctor_get(v___x_599_, 0);
lean_inc(v_a_600_);
if (lean_obj_tag(v_a_600_) == 0)
{
lean_dec_ref_known(v_a_600_, 1);
lean_dec_ref(v_map_u2082_588_);
lean_dec_ref(v_f_580_);
return v___x_599_;
}
else
{
lean_object* v_a_601_; lean_object* v_snd_602_; lean_object* v___x_603_; 
lean_dec_ref_known(v___x_599_, 1);
v_a_601_ = lean_ctor_get(v_a_600_, 0);
lean_inc(v_a_601_);
lean_dec_ref_known(v_a_600_, 1);
v_snd_602_ = lean_ctor_get(v_a_601_, 1);
lean_inc(v_snd_602_);
lean_dec(v_a_601_);
v___x_603_ = lp_JunkValues_Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4___redArg(v_map_u2082_588_, v_f_580_, v_snd_602_, v___y_582_, v___y_583_, v___y_584_, v___y_585_);
return v___x_603_;
}
}
else
{
lean_dec_ref(v_map_u2082_588_);
lean_dec_ref(v_f_580_);
return v___x_599_;
}
}
}
else
{
size_t v___x_604_; size_t v___x_605_; lean_object* v___x_606_; 
v___x_604_ = ((size_t)0ULL);
v___x_605_ = lean_usize_of_nat(v___x_591_);
lean_inc_ref(v_f_580_);
v___x_606_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__5___redArg(v_f_580_, v_buckets_589_, v___x_604_, v___x_605_, v___x_594_, v___y_581_, v___y_582_, v___y_583_, v___y_584_, v___y_585_);
lean_dec_ref(v_buckets_589_);
if (lean_obj_tag(v___x_606_) == 0)
{
lean_object* v_a_607_; 
v_a_607_ = lean_ctor_get(v___x_606_, 0);
lean_inc(v_a_607_);
if (lean_obj_tag(v_a_607_) == 0)
{
lean_dec_ref_known(v_a_607_, 1);
lean_dec_ref(v_map_u2082_588_);
lean_dec_ref(v_f_580_);
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
v___x_610_ = lp_JunkValues_Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4___redArg(v_map_u2082_588_, v_f_580_, v_snd_609_, v___y_582_, v___y_583_, v___y_584_, v___y_585_);
return v___x_610_;
}
}
else
{
lean_dec_ref(v_map_u2082_588_);
lean_dec_ref(v_f_580_);
return v___x_606_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2___redArg___boxed(lean_object* v_s_611_, lean_object* v_f_612_, lean_object* v___y_613_, lean_object* v___y_614_, lean_object* v___y_615_, lean_object* v___y_616_, lean_object* v___y_617_, lean_object* v___y_618_){
_start:
{
lean_object* v_res_619_; 
v_res_619_ = lp_JunkValues_Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2___redArg(v_s_611_, v_f_612_, v___y_613_, v___y_614_, v___y_615_, v___y_616_, v___y_617_);
lean_dec(v___y_617_);
lean_dec_ref(v___y_616_);
lean_dec(v___y_615_);
lean_dec_ref(v___y_614_);
return v_res_619_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_discoverRules_spec__1(lean_object* v_scope_623_, lean_object* v_as_624_, size_t v_sz_625_, size_t v_i_626_, lean_object* v_b_627_, lean_object* v___y_628_, lean_object* v___y_629_, lean_object* v___y_630_, lean_object* v___y_631_){
_start:
{
uint8_t v___x_633_; 
v___x_633_ = lean_usize_dec_lt(v_i_626_, v_sz_625_);
if (v___x_633_ == 0)
{
lean_object* v___x_634_; 
v___x_634_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_634_, 0, v_b_627_);
return v___x_634_;
}
else
{
lean_object* v___x_635_; lean_object* v_a_636_; lean_object* v___x_637_; lean_object* v___x_638_; lean_object* v___x_639_; 
v___x_635_ = lean_unsigned_to_nat(0u);
v_a_636_ = lean_array_uget_borrowed(v_as_624_, v_i_626_);
v___x_637_ = ((lean_object*)(lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_discoverRules_spec__1___closed__0));
v___x_638_ = ((lean_object*)(lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_discoverRules_spec__1___closed__1));
lean_inc(v_a_636_);
v___x_639_ = lp_JunkValues_JunkValues_ruleOfTheorem_x3f(v_a_636_, v___x_637_, v___x_638_, v___y_628_, v___y_629_, v___y_630_, v___y_631_);
if (lean_obj_tag(v___x_639_) == 0)
{
lean_object* v_a_640_; lean_object* v_a_642_; 
v_a_640_ = lean_ctor_get(v___x_639_, 0);
lean_inc(v_a_640_);
lean_dec_ref_known(v___x_639_, 1);
if (lean_obj_tag(v_a_640_) == 1)
{
lean_object* v_a_646_; uint8_t v_requireNegatedGuard_649_; 
v_a_646_ = lean_ctor_get(v_a_640_, 0);
lean_inc(v_a_646_);
lean_dec_ref_known(v_a_640_, 1);
v_requireNegatedGuard_649_ = lean_ctor_get_uint8(v_scope_623_, sizeof(void*)*1 + 1);
if (v_requireNegatedGuard_649_ == 0)
{
goto v___jp_647_;
}
else
{
lean_object* v_negatedGuards_650_; uint8_t v___x_651_; 
v_negatedGuards_650_ = lean_ctor_get(v_a_646_, 3);
v___x_651_ = lean_nat_dec_lt(v___x_635_, v_negatedGuards_650_);
if (v___x_651_ == 0)
{
lean_dec(v_a_646_);
v_a_642_ = v_b_627_;
goto v___jp_641_;
}
else
{
goto v___jp_647_;
}
}
v___jp_647_:
{
lean_object* v___x_648_; 
v___x_648_ = lean_array_push(v_b_627_, v_a_646_);
v_a_642_ = v___x_648_;
goto v___jp_641_;
}
}
else
{
lean_dec(v_a_640_);
v_a_642_ = v_b_627_;
goto v___jp_641_;
}
v___jp_641_:
{
size_t v___x_643_; size_t v___x_644_; 
v___x_643_ = ((size_t)1ULL);
v___x_644_ = lean_usize_add(v_i_626_, v___x_643_);
v_i_626_ = v___x_644_;
v_b_627_ = v_a_642_;
goto _start;
}
}
else
{
lean_object* v_a_652_; lean_object* v___x_654_; uint8_t v_isShared_655_; uint8_t v_isSharedCheck_659_; 
lean_dec_ref(v_b_627_);
v_a_652_ = lean_ctor_get(v___x_639_, 0);
v_isSharedCheck_659_ = !lean_is_exclusive(v___x_639_);
if (v_isSharedCheck_659_ == 0)
{
v___x_654_ = v___x_639_;
v_isShared_655_ = v_isSharedCheck_659_;
goto v_resetjp_653_;
}
else
{
lean_inc(v_a_652_);
lean_dec(v___x_639_);
v___x_654_ = lean_box(0);
v_isShared_655_ = v_isSharedCheck_659_;
goto v_resetjp_653_;
}
v_resetjp_653_:
{
lean_object* v___x_657_; 
if (v_isShared_655_ == 0)
{
v___x_657_ = v___x_654_;
goto v_reusejp_656_;
}
else
{
lean_object* v_reuseFailAlloc_658_; 
v_reuseFailAlloc_658_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_658_, 0, v_a_652_);
v___x_657_ = v_reuseFailAlloc_658_;
goto v_reusejp_656_;
}
v_reusejp_656_:
{
return v___x_657_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_discoverRules_spec__1___boxed(lean_object* v_scope_660_, lean_object* v_as_661_, lean_object* v_sz_662_, lean_object* v_i_663_, lean_object* v_b_664_, lean_object* v___y_665_, lean_object* v___y_666_, lean_object* v___y_667_, lean_object* v___y_668_, lean_object* v___y_669_){
_start:
{
size_t v_sz_boxed_670_; size_t v_i_boxed_671_; lean_object* v_res_672_; 
v_sz_boxed_670_ = lean_unbox_usize(v_sz_662_);
lean_dec(v_sz_662_);
v_i_boxed_671_ = lean_unbox_usize(v_i_663_);
lean_dec(v_i_663_);
v_res_672_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_discoverRules_spec__1(v_scope_660_, v_as_661_, v_sz_boxed_670_, v_i_boxed_671_, v_b_664_, v___y_665_, v___y_666_, v___y_667_, v___y_668_);
lean_dec(v___y_668_);
lean_dec_ref(v___y_667_);
lean_dec(v___y_666_);
lean_dec_ref(v___y_665_);
lean_dec_ref(v_as_661_);
lean_dec_ref(v_scope_660_);
return v_res_672_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_discoverRules___closed__2(void){
_start:
{
lean_object* v___x_677_; lean_object* v___x_678_; lean_object* v___x_679_; 
v___x_677_ = lean_box(0);
v___x_678_ = lean_unsigned_to_nat(16u);
v___x_679_ = lean_mk_array(v___x_678_, v___x_677_);
return v___x_679_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_discoverRules___closed__3(void){
_start:
{
lean_object* v___x_680_; lean_object* v___x_681_; lean_object* v___x_682_; 
v___x_680_ = lean_obj_once(&lp_JunkValues_JunkValues_discoverRules___closed__2, &lp_JunkValues_JunkValues_discoverRules___closed__2_once, _init_lp_JunkValues_JunkValues_discoverRules___closed__2);
v___x_681_ = lean_unsigned_to_nat(0u);
v___x_682_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_682_, 0, v___x_681_);
lean_ctor_set(v___x_682_, 1, v___x_680_);
return v___x_682_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_discoverRules___closed__4(void){
_start:
{
lean_object* v___x_683_; lean_object* v___x_684_; 
v___x_683_ = ((lean_object*)(lp_JunkValues_JunkValues_defaultValueHeads));
v___x_684_ = lean_array_get_size(v___x_683_);
return v___x_684_;
}
}
static uint8_t _init_lp_JunkValues_JunkValues_discoverRules___closed__5(void){
_start:
{
lean_object* v___x_685_; lean_object* v___x_686_; uint8_t v___x_687_; 
v___x_685_ = lean_obj_once(&lp_JunkValues_JunkValues_discoverRules___closed__4, &lp_JunkValues_JunkValues_discoverRules___closed__4_once, _init_lp_JunkValues_JunkValues_discoverRules___closed__4);
v___x_686_ = lean_unsigned_to_nat(0u);
v___x_687_ = lean_nat_dec_lt(v___x_686_, v___x_685_);
return v___x_687_;
}
}
static uint8_t _init_lp_JunkValues_JunkValues_discoverRules___closed__6(void){
_start:
{
lean_object* v___x_688_; uint8_t v___x_689_; 
v___x_688_ = lean_obj_once(&lp_JunkValues_JunkValues_discoverRules___closed__4, &lp_JunkValues_JunkValues_discoverRules___closed__4_once, _init_lp_JunkValues_JunkValues_discoverRules___closed__4);
v___x_689_ = lean_nat_dec_le(v___x_688_, v___x_688_);
return v___x_689_;
}
}
static size_t _init_lp_JunkValues_JunkValues_discoverRules___closed__7(void){
_start:
{
lean_object* v___x_690_; size_t v___x_691_; 
v___x_690_ = lean_obj_once(&lp_JunkValues_JunkValues_discoverRules___closed__4, &lp_JunkValues_JunkValues_discoverRules___closed__4_once, _init_lp_JunkValues_JunkValues_discoverRules___closed__4);
v___x_691_ = lean_usize_of_nat(v___x_690_);
return v___x_691_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_discoverRules___closed__8(void){
_start:
{
lean_object* v___x_692_; size_t v___x_693_; size_t v___x_694_; lean_object* v___x_695_; lean_object* v___x_696_; 
v___x_692_ = lean_obj_once(&lp_JunkValues_JunkValues_discoverRules___closed__3, &lp_JunkValues_JunkValues_discoverRules___closed__3_once, _init_lp_JunkValues_JunkValues_discoverRules___closed__3);
v___x_693_ = lean_usize_once(&lp_JunkValues_JunkValues_discoverRules___closed__7, &lp_JunkValues_JunkValues_discoverRules___closed__7_once, _init_lp_JunkValues_JunkValues_discoverRules___closed__7);
v___x_694_ = ((size_t)0ULL);
v___x_695_ = ((lean_object*)(lp_JunkValues_JunkValues_defaultValueHeads));
v___x_696_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00JunkValues_discoverRules_spec__3(v___x_695_, v___x_694_, v___x_693_, v___x_692_);
return v___x_696_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_discoverRules(lean_object* v_scope_697_, lean_object* v_a_698_, lean_object* v_a_699_, lean_object* v_a_700_, lean_object* v_a_701_){
_start:
{
lean_object* v___x_703_; lean_object* v_env_704_; lean_object* v_a_706_; lean_object* v___y_712_; lean_object* v___x_729_; uint8_t v___x_730_; 
v___x_703_ = lean_st_ref_get(v_a_701_);
v_env_704_ = lean_ctor_get(v___x_703_, 0);
lean_inc_ref(v_env_704_);
lean_dec(v___x_703_);
v___x_729_ = lean_obj_once(&lp_JunkValues_JunkValues_discoverRules___closed__3, &lp_JunkValues_JunkValues_discoverRules___closed__3_once, _init_lp_JunkValues_JunkValues_discoverRules___closed__3);
v___x_730_ = lean_uint8_once(&lp_JunkValues_JunkValues_discoverRules___closed__5, &lp_JunkValues_JunkValues_discoverRules___closed__5_once, _init_lp_JunkValues_JunkValues_discoverRules___closed__5);
if (v___x_730_ == 0)
{
v___y_712_ = v___x_729_;
goto v___jp_711_;
}
else
{
uint8_t v___x_731_; 
v___x_731_ = lean_uint8_once(&lp_JunkValues_JunkValues_discoverRules___closed__6, &lp_JunkValues_JunkValues_discoverRules___closed__6_once, _init_lp_JunkValues_JunkValues_discoverRules___closed__6);
if (v___x_731_ == 0)
{
if (v___x_730_ == 0)
{
v___y_712_ = v___x_729_;
goto v___jp_711_;
}
else
{
lean_object* v___x_732_; 
v___x_732_ = lean_obj_once(&lp_JunkValues_JunkValues_discoverRules___closed__8, &lp_JunkValues_JunkValues_discoverRules___closed__8_once, _init_lp_JunkValues_JunkValues_discoverRules___closed__8);
v___y_712_ = v___x_732_;
goto v___jp_711_;
}
}
else
{
lean_object* v___x_733_; 
v___x_733_ = lean_obj_once(&lp_JunkValues_JunkValues_discoverRules___closed__8, &lp_JunkValues_JunkValues_discoverRules___closed__8_once, _init_lp_JunkValues_JunkValues_discoverRules___closed__8);
v___y_712_ = v___x_733_;
goto v___jp_711_;
}
}
v___jp_705_:
{
lean_object* v___x_707_; size_t v_sz_708_; size_t v___x_709_; lean_object* v___x_710_; 
v___x_707_ = ((lean_object*)(lp_JunkValues_JunkValues_discoverRules___closed__0));
v_sz_708_ = lean_array_size(v_a_706_);
v___x_709_ = ((size_t)0ULL);
v___x_710_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_discoverRules_spec__1(v_scope_697_, v_a_706_, v_sz_708_, v___x_709_, v___x_707_, v_a_698_, v_a_699_, v_a_700_, v_a_701_);
lean_dec_ref(v_a_706_);
lean_dec_ref(v_scope_697_);
return v___x_710_;
}
v___jp_711_:
{
lean_object* v___f_713_; lean_object* v___x_714_; lean_object* v___x_715_; lean_object* v___x_716_; 
lean_inc_ref(v___y_712_);
lean_inc_ref(v_env_704_);
lean_inc_ref(v_scope_697_);
v___f_713_ = lean_alloc_closure((void*)(lp_JunkValues_JunkValues_discoverRules___lam__0___boxed), 11, 3);
lean_closure_set(v___f_713_, 0, v_scope_697_);
lean_closure_set(v___f_713_, 1, v_env_704_);
lean_closure_set(v___f_713_, 2, v___y_712_);
v___x_714_ = ((lean_object*)(lp_JunkValues_JunkValues_discoverRules___closed__1));
v___x_715_ = l_Lean_Environment_constants(v_env_704_);
v___x_716_ = lp_JunkValues_Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2___redArg(v___x_715_, v___f_713_, v___x_714_, v_a_698_, v_a_699_, v_a_700_, v_a_701_);
if (lean_obj_tag(v___x_716_) == 0)
{
lean_object* v_a_717_; 
v_a_717_ = lean_ctor_get(v___x_716_, 0);
lean_inc(v_a_717_);
lean_dec_ref_known(v___x_716_, 1);
if (lean_obj_tag(v_a_717_) == 0)
{
lean_object* v_a_718_; 
v_a_718_ = lean_ctor_get(v_a_717_, 0);
lean_inc(v_a_718_);
lean_dec_ref_known(v_a_717_, 1);
v_a_706_ = v_a_718_;
goto v___jp_705_;
}
else
{
lean_object* v_a_719_; lean_object* v_snd_720_; 
v_a_719_ = lean_ctor_get(v_a_717_, 0);
lean_inc(v_a_719_);
lean_dec_ref_known(v_a_717_, 1);
v_snd_720_ = lean_ctor_get(v_a_719_, 1);
lean_inc(v_snd_720_);
lean_dec(v_a_719_);
v_a_706_ = v_snd_720_;
goto v___jp_705_;
}
}
else
{
lean_object* v_a_721_; lean_object* v___x_723_; uint8_t v_isShared_724_; uint8_t v_isSharedCheck_728_; 
lean_dec_ref(v_scope_697_);
v_a_721_ = lean_ctor_get(v___x_716_, 0);
v_isSharedCheck_728_ = !lean_is_exclusive(v___x_716_);
if (v_isSharedCheck_728_ == 0)
{
v___x_723_ = v___x_716_;
v_isShared_724_ = v_isSharedCheck_728_;
goto v_resetjp_722_;
}
else
{
lean_inc(v_a_721_);
lean_dec(v___x_716_);
v___x_723_ = lean_box(0);
v_isShared_724_ = v_isSharedCheck_728_;
goto v_resetjp_722_;
}
v_resetjp_722_:
{
lean_object* v___x_726_; 
if (v_isShared_724_ == 0)
{
v___x_726_ = v___x_723_;
goto v_reusejp_725_;
}
else
{
lean_object* v_reuseFailAlloc_727_; 
v_reuseFailAlloc_727_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_727_, 0, v_a_721_);
v___x_726_ = v_reuseFailAlloc_727_;
goto v_reusejp_725_;
}
v_reusejp_725_:
{
return v___x_726_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_discoverRules___boxed(lean_object* v_scope_734_, lean_object* v_a_735_, lean_object* v_a_736_, lean_object* v_a_737_, lean_object* v_a_738_, lean_object* v_a_739_){
_start:
{
lean_object* v_res_740_; 
v_res_740_ = lp_JunkValues_JunkValues_discoverRules(v_scope_734_, v_a_735_, v_a_736_, v_a_737_, v_a_738_);
lean_dec(v_a_738_);
lean_dec_ref(v_a_737_);
lean_dec(v_a_736_);
lean_dec_ref(v_a_735_);
return v_res_740_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_discoverRules_spec__0(lean_object* v_00_u03b2_741_, lean_object* v_m_742_, lean_object* v_a_743_, lean_object* v_b_744_){
_start:
{
lean_object* v___x_745_; 
v___x_745_ = lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_discoverRules_spec__0___redArg(v_m_742_, v_a_743_, v_b_744_);
return v___x_745_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2(lean_object* v_00_u03b2_746_, lean_object* v_s_747_, lean_object* v_f_748_, lean_object* v___y_749_, lean_object* v___y_750_, lean_object* v___y_751_, lean_object* v___y_752_, lean_object* v___y_753_){
_start:
{
lean_object* v___x_755_; 
v___x_755_ = lp_JunkValues_Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2___redArg(v_s_747_, v_f_748_, v___y_749_, v___y_750_, v___y_751_, v___y_752_, v___y_753_);
return v___x_755_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2___boxed(lean_object* v_00_u03b2_756_, lean_object* v_s_757_, lean_object* v_f_758_, lean_object* v___y_759_, lean_object* v___y_760_, lean_object* v___y_761_, lean_object* v___y_762_, lean_object* v___y_763_, lean_object* v___y_764_){
_start:
{
lean_object* v_res_765_; 
v_res_765_ = lp_JunkValues_Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2(v_00_u03b2_756_, v_s_757_, v_f_758_, v___y_759_, v___y_760_, v___y_761_, v___y_762_, v___y_763_);
lean_dec(v___y_763_);
lean_dec_ref(v___y_762_);
lean_dec(v___y_761_);
lean_dec_ref(v___y_760_);
return v_res_765_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_discoverRules_spec__0_spec__0(lean_object* v_00_u03b2_766_, lean_object* v_data_767_){
_start:
{
lean_object* v___x_768_; 
v___x_768_ = lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_discoverRules_spec__0_spec__0___redArg(v_data_767_);
return v___x_768_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__3(lean_object* v_00_u03b2_769_, lean_object* v_f_770_, lean_object* v_x_771_, lean_object* v_x_772_, lean_object* v___y_773_, lean_object* v___y_774_, lean_object* v___y_775_, lean_object* v___y_776_, lean_object* v___y_777_){
_start:
{
lean_object* v___x_779_; 
v___x_779_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__3___redArg(v_f_770_, v_x_771_, v_x_772_, v___y_773_, v___y_774_, v___y_775_, v___y_776_, v___y_777_);
return v___x_779_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__3___boxed(lean_object* v_00_u03b2_780_, lean_object* v_f_781_, lean_object* v_x_782_, lean_object* v_x_783_, lean_object* v___y_784_, lean_object* v___y_785_, lean_object* v___y_786_, lean_object* v___y_787_, lean_object* v___y_788_, lean_object* v___y_789_){
_start:
{
lean_object* v_res_790_; 
v_res_790_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__3(v_00_u03b2_780_, v_f_781_, v_x_782_, v_x_783_, v___y_784_, v___y_785_, v___y_786_, v___y_787_, v___y_788_);
lean_dec(v___y_788_);
lean_dec_ref(v___y_787_);
lean_dec(v___y_786_);
lean_dec_ref(v___y_785_);
return v_res_790_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4(lean_object* v_00_u03b2_791_, lean_object* v_map_792_, lean_object* v_f_793_, lean_object* v___y_794_, lean_object* v___y_795_, lean_object* v___y_796_, lean_object* v___y_797_, lean_object* v___y_798_){
_start:
{
lean_object* v___x_800_; 
v___x_800_ = lp_JunkValues_Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4___redArg(v_map_792_, v_f_793_, v___y_794_, v___y_795_, v___y_796_, v___y_797_, v___y_798_);
return v___x_800_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4___boxed(lean_object* v_00_u03b2_801_, lean_object* v_map_802_, lean_object* v_f_803_, lean_object* v___y_804_, lean_object* v___y_805_, lean_object* v___y_806_, lean_object* v___y_807_, lean_object* v___y_808_, lean_object* v___y_809_){
_start:
{
lean_object* v_res_810_; 
v_res_810_ = lp_JunkValues_Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4(v_00_u03b2_801_, v_map_802_, v_f_803_, v___y_804_, v___y_805_, v___y_806_, v___y_807_, v___y_808_);
lean_dec(v___y_808_);
lean_dec_ref(v___y_807_);
lean_dec(v___y_806_);
lean_dec_ref(v___y_805_);
return v_res_810_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__5(lean_object* v_00_u03b2_811_, lean_object* v_f_812_, lean_object* v_as_813_, size_t v_i_814_, size_t v_stop_815_, lean_object* v_b_816_, lean_object* v___y_817_, lean_object* v___y_818_, lean_object* v___y_819_, lean_object* v___y_820_, lean_object* v___y_821_){
_start:
{
lean_object* v___x_823_; 
v___x_823_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__5___redArg(v_f_812_, v_as_813_, v_i_814_, v_stop_815_, v_b_816_, v___y_817_, v___y_818_, v___y_819_, v___y_820_, v___y_821_);
return v___x_823_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__5___boxed(lean_object* v_00_u03b2_824_, lean_object* v_f_825_, lean_object* v_as_826_, lean_object* v_i_827_, lean_object* v_stop_828_, lean_object* v_b_829_, lean_object* v___y_830_, lean_object* v___y_831_, lean_object* v___y_832_, lean_object* v___y_833_, lean_object* v___y_834_, lean_object* v___y_835_){
_start:
{
size_t v_i_boxed_836_; size_t v_stop_boxed_837_; lean_object* v_res_838_; 
v_i_boxed_836_ = lean_unbox_usize(v_i_827_);
lean_dec(v_i_827_);
v_stop_boxed_837_ = lean_unbox_usize(v_stop_828_);
lean_dec(v_stop_828_);
v_res_838_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__5(v_00_u03b2_824_, v_f_825_, v_as_826_, v_i_boxed_836_, v_stop_boxed_837_, v_b_829_, v___y_830_, v___y_831_, v___y_832_, v___y_833_, v___y_834_);
lean_dec(v___y_834_);
lean_dec_ref(v___y_833_);
lean_dec(v___y_832_);
lean_dec_ref(v___y_831_);
lean_dec_ref(v_as_826_);
return v_res_838_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_discoverRules_spec__0_spec__0_spec__1(lean_object* v_00_u03b2_839_, lean_object* v_i_840_, lean_object* v_source_841_, lean_object* v_target_842_){
_start:
{
lean_object* v___x_843_; 
v___x_843_ = lp_JunkValues___private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_discoverRules_spec__0_spec__0_spec__1___redArg(v_i_840_, v_source_841_, v_target_842_);
return v___x_843_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6___redArg(lean_object* v_map_844_, lean_object* v_f_845_, lean_object* v_init_846_, lean_object* v___y_847_, lean_object* v___y_848_, lean_object* v___y_849_, lean_object* v___y_850_, lean_object* v___y_851_){
_start:
{
lean_object* v___x_853_; 
v___x_853_ = lp_JunkValues_Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9___redArg(v_f_845_, v_map_844_, v_init_846_, v___y_847_, v___y_848_, v___y_849_, v___y_850_, v___y_851_);
return v___x_853_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6___redArg___boxed(lean_object* v_map_854_, lean_object* v_f_855_, lean_object* v_init_856_, lean_object* v___y_857_, lean_object* v___y_858_, lean_object* v___y_859_, lean_object* v___y_860_, lean_object* v___y_861_, lean_object* v___y_862_){
_start:
{
lean_object* v_res_863_; 
v_res_863_ = lp_JunkValues_Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6___redArg(v_map_854_, v_f_855_, v_init_856_, v___y_857_, v___y_858_, v___y_859_, v___y_860_, v___y_861_);
lean_dec(v___y_861_);
lean_dec_ref(v___y_860_);
lean_dec(v___y_859_);
lean_dec_ref(v___y_858_);
return v_res_863_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6(lean_object* v_00_u03c3_864_, lean_object* v_00_u03b2_865_, lean_object* v_map_866_, lean_object* v_f_867_, lean_object* v_init_868_, lean_object* v___y_869_, lean_object* v___y_870_, lean_object* v___y_871_, lean_object* v___y_872_, lean_object* v___y_873_){
_start:
{
lean_object* v___x_875_; 
v___x_875_ = lp_JunkValues_Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9___redArg(v_f_867_, v_map_866_, v_init_868_, v___y_869_, v___y_870_, v___y_871_, v___y_872_, v___y_873_);
return v___x_875_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6___boxed(lean_object* v_00_u03c3_876_, lean_object* v_00_u03b2_877_, lean_object* v_map_878_, lean_object* v_f_879_, lean_object* v_init_880_, lean_object* v___y_881_, lean_object* v___y_882_, lean_object* v___y_883_, lean_object* v___y_884_, lean_object* v___y_885_, lean_object* v___y_886_){
_start:
{
lean_object* v_res_887_; 
v_res_887_ = lp_JunkValues_Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6(v_00_u03c3_876_, v_00_u03b2_877_, v_map_878_, v_f_879_, v_init_880_, v___y_881_, v___y_882_, v___y_883_, v___y_884_, v___y_885_);
lean_dec(v___y_885_);
lean_dec_ref(v___y_884_);
lean_dec(v___y_883_);
lean_dec_ref(v___y_882_);
return v_res_887_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00__private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_discoverRules_spec__0_spec__0_spec__1_spec__5(lean_object* v_00_u03b2_888_, lean_object* v_x_889_, lean_object* v_x_890_){
_start:
{
lean_object* v___x_891_; 
v___x_891_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00__private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_discoverRules_spec__0_spec__0_spec__1_spec__5___redArg(v_x_889_, v_x_890_);
return v___x_891_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9(lean_object* v_00_u03c3_892_, lean_object* v_00_u03b1_893_, lean_object* v_00_u03b2_894_, lean_object* v_f_895_, lean_object* v_x_896_, lean_object* v_x_897_, lean_object* v___y_898_, lean_object* v___y_899_, lean_object* v___y_900_, lean_object* v___y_901_, lean_object* v___y_902_){
_start:
{
lean_object* v___x_904_; 
v___x_904_ = lp_JunkValues_Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9___redArg(v_f_895_, v_x_896_, v_x_897_, v___y_898_, v___y_899_, v___y_900_, v___y_901_, v___y_902_);
return v___x_904_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9___boxed(lean_object* v_00_u03c3_905_, lean_object* v_00_u03b1_906_, lean_object* v_00_u03b2_907_, lean_object* v_f_908_, lean_object* v_x_909_, lean_object* v_x_910_, lean_object* v___y_911_, lean_object* v___y_912_, lean_object* v___y_913_, lean_object* v___y_914_, lean_object* v___y_915_, lean_object* v___y_916_){
_start:
{
lean_object* v_res_917_; 
v_res_917_ = lp_JunkValues_Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9(v_00_u03c3_905_, v_00_u03b1_906_, v_00_u03b2_907_, v_f_908_, v_x_909_, v_x_910_, v___y_911_, v___y_912_, v___y_913_, v___y_914_, v___y_915_);
lean_dec(v___y_915_);
lean_dec_ref(v___y_914_);
lean_dec(v___y_913_);
lean_dec_ref(v___y_912_);
return v_res_917_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9_spec__11(lean_object* v_00_u03b1_918_, lean_object* v_00_u03b2_919_, lean_object* v_00_u03c3_920_, lean_object* v_f_921_, lean_object* v_as_922_, size_t v_i_923_, size_t v_stop_924_, lean_object* v_b_925_, lean_object* v___y_926_, lean_object* v___y_927_, lean_object* v___y_928_, lean_object* v___y_929_, lean_object* v___y_930_){
_start:
{
lean_object* v___x_932_; 
v___x_932_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9_spec__11___redArg(v_f_921_, v_as_922_, v_i_923_, v_stop_924_, v_b_925_, v___y_926_, v___y_927_, v___y_928_, v___y_929_, v___y_930_);
return v___x_932_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9_spec__11___boxed(lean_object* v_00_u03b1_933_, lean_object* v_00_u03b2_934_, lean_object* v_00_u03c3_935_, lean_object* v_f_936_, lean_object* v_as_937_, lean_object* v_i_938_, lean_object* v_stop_939_, lean_object* v_b_940_, lean_object* v___y_941_, lean_object* v___y_942_, lean_object* v___y_943_, lean_object* v___y_944_, lean_object* v___y_945_, lean_object* v___y_946_){
_start:
{
size_t v_i_boxed_947_; size_t v_stop_boxed_948_; lean_object* v_res_949_; 
v_i_boxed_947_ = lean_unbox_usize(v_i_938_);
lean_dec(v_i_938_);
v_stop_boxed_948_ = lean_unbox_usize(v_stop_939_);
lean_dec(v_stop_939_);
v_res_949_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9_spec__11(v_00_u03b1_933_, v_00_u03b2_934_, v_00_u03c3_935_, v_f_936_, v_as_937_, v_i_boxed_947_, v_stop_boxed_948_, v_b_940_, v___y_941_, v___y_942_, v___y_943_, v___y_944_, v___y_945_);
lean_dec(v___y_945_);
lean_dec_ref(v___y_944_);
lean_dec(v___y_943_);
lean_dec_ref(v___y_942_);
lean_dec_ref(v_as_937_);
return v_res_949_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Lean_Data_PersistentHashMap_0__Lean_PersistentHashMap_foldlMAux_traverse___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9_spec__12(lean_object* v_00_u03c3_950_, lean_object* v_00_u03b1_951_, lean_object* v_00_u03b2_952_, lean_object* v_f_953_, lean_object* v_keys_954_, lean_object* v_vals_955_, lean_object* v_heq_956_, lean_object* v_i_957_, lean_object* v_acc_958_, lean_object* v___y_959_, lean_object* v___y_960_, lean_object* v___y_961_, lean_object* v___y_962_, lean_object* v___y_963_){
_start:
{
lean_object* v___x_965_; 
v___x_965_ = lp_JunkValues___private_Lean_Data_PersistentHashMap_0__Lean_PersistentHashMap_foldlMAux_traverse___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9_spec__12___redArg(v_f_953_, v_keys_954_, v_vals_955_, v_i_957_, v_acc_958_, v___y_959_, v___y_960_, v___y_961_, v___y_962_, v___y_963_);
return v___x_965_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Lean_Data_PersistentHashMap_0__Lean_PersistentHashMap_foldlMAux_traverse___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9_spec__12___boxed(lean_object* v_00_u03c3_966_, lean_object* v_00_u03b1_967_, lean_object* v_00_u03b2_968_, lean_object* v_f_969_, lean_object* v_keys_970_, lean_object* v_vals_971_, lean_object* v_heq_972_, lean_object* v_i_973_, lean_object* v_acc_974_, lean_object* v___y_975_, lean_object* v___y_976_, lean_object* v___y_977_, lean_object* v___y_978_, lean_object* v___y_979_, lean_object* v___y_980_){
_start:
{
lean_object* v_res_981_; 
v_res_981_ = lp_JunkValues___private_Lean_Data_PersistentHashMap_0__Lean_PersistentHashMap_foldlMAux_traverse___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_discoverRules_spec__2_spec__4_spec__6_spec__9_spec__12(v_00_u03c3_966_, v_00_u03b1_967_, v_00_u03b2_968_, v_f_969_, v_keys_970_, v_vals_971_, v_heq_972_, v_i_973_, v_acc_974_, v___y_975_, v___y_976_, v___y_977_, v___y_978_, v___y_979_);
lean_dec(v___y_979_);
lean_dec_ref(v___y_978_);
lean_dec(v___y_977_);
lean_dec_ref(v___y_976_);
lean_dec_ref(v_vals_971_);
lean_dec_ref(v_keys_970_);
return v_res_981_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Option_register___at___00__private_JunkValues_Extra_Discovery_0__JunkValues_initFn_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4__spec__0(lean_object* v_name_982_, lean_object* v_decl_983_, lean_object* v_ref_984_){
_start:
{
lean_object* v_defValue_986_; lean_object* v_descr_987_; lean_object* v_deprecation_x3f_988_; lean_object* v___x_989_; uint8_t v___x_990_; lean_object* v___x_991_; lean_object* v___x_992_; 
v_defValue_986_ = lean_ctor_get(v_decl_983_, 0);
v_descr_987_ = lean_ctor_get(v_decl_983_, 1);
v_deprecation_x3f_988_ = lean_ctor_get(v_decl_983_, 2);
v___x_989_ = lean_alloc_ctor(1, 0, 1);
v___x_990_ = lean_unbox(v_defValue_986_);
lean_ctor_set_uint8(v___x_989_, 0, v___x_990_);
lean_inc(v_deprecation_x3f_988_);
lean_inc_ref(v_descr_987_);
lean_inc_n(v_name_982_, 2);
v___x_991_ = lean_alloc_ctor(0, 5, 0);
lean_ctor_set(v___x_991_, 0, v_name_982_);
lean_ctor_set(v___x_991_, 1, v_ref_984_);
lean_ctor_set(v___x_991_, 2, v___x_989_);
lean_ctor_set(v___x_991_, 3, v_descr_987_);
lean_ctor_set(v___x_991_, 4, v_deprecation_x3f_988_);
v___x_992_ = lean_register_option(v_name_982_, v___x_991_);
if (lean_obj_tag(v___x_992_) == 0)
{
lean_object* v___x_994_; uint8_t v_isShared_995_; uint8_t v_isSharedCheck_1000_; 
v_isSharedCheck_1000_ = !lean_is_exclusive(v___x_992_);
if (v_isSharedCheck_1000_ == 0)
{
lean_object* v_unused_1001_; 
v_unused_1001_ = lean_ctor_get(v___x_992_, 0);
lean_dec(v_unused_1001_);
v___x_994_ = v___x_992_;
v_isShared_995_ = v_isSharedCheck_1000_;
goto v_resetjp_993_;
}
else
{
lean_dec(v___x_992_);
v___x_994_ = lean_box(0);
v_isShared_995_ = v_isSharedCheck_1000_;
goto v_resetjp_993_;
}
v_resetjp_993_:
{
lean_object* v___x_996_; lean_object* v___x_998_; 
lean_inc(v_defValue_986_);
v___x_996_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_996_, 0, v_name_982_);
lean_ctor_set(v___x_996_, 1, v_defValue_986_);
if (v_isShared_995_ == 0)
{
lean_ctor_set(v___x_994_, 0, v___x_996_);
v___x_998_ = v___x_994_;
goto v_reusejp_997_;
}
else
{
lean_object* v_reuseFailAlloc_999_; 
v_reuseFailAlloc_999_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_999_, 0, v___x_996_);
v___x_998_ = v_reuseFailAlloc_999_;
goto v_reusejp_997_;
}
v_reusejp_997_:
{
return v___x_998_;
}
}
}
else
{
lean_object* v_a_1002_; lean_object* v___x_1004_; uint8_t v_isShared_1005_; uint8_t v_isSharedCheck_1009_; 
lean_dec(v_name_982_);
v_a_1002_ = lean_ctor_get(v___x_992_, 0);
v_isSharedCheck_1009_ = !lean_is_exclusive(v___x_992_);
if (v_isSharedCheck_1009_ == 0)
{
v___x_1004_ = v___x_992_;
v_isShared_1005_ = v_isSharedCheck_1009_;
goto v_resetjp_1003_;
}
else
{
lean_inc(v_a_1002_);
lean_dec(v___x_992_);
v___x_1004_ = lean_box(0);
v_isShared_1005_ = v_isSharedCheck_1009_;
goto v_resetjp_1003_;
}
v_resetjp_1003_:
{
lean_object* v___x_1007_; 
if (v_isShared_1005_ == 0)
{
v___x_1007_ = v___x_1004_;
goto v_reusejp_1006_;
}
else
{
lean_object* v_reuseFailAlloc_1008_; 
v_reuseFailAlloc_1008_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1008_, 0, v_a_1002_);
v___x_1007_ = v_reuseFailAlloc_1008_;
goto v_reusejp_1006_;
}
v_reusejp_1006_:
{
return v___x_1007_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Option_register___at___00__private_JunkValues_Extra_Discovery_0__JunkValues_initFn_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4__spec__0___boxed(lean_object* v_name_1010_, lean_object* v_decl_1011_, lean_object* v_ref_1012_, lean_object* v_a_1013_){
_start:
{
lean_object* v_res_1014_; 
v_res_1014_ = lp_JunkValues_Lean_Option_register___at___00__private_JunkValues_Extra_Discovery_0__JunkValues_initFn_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4__spec__0(v_name_1010_, v_decl_1011_, v_ref_1012_);
lean_dec_ref(v_decl_1011_);
return v_res_1014_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4_(){
_start:
{
lean_object* v___x_1035_; lean_object* v___x_1036_; lean_object* v___x_1037_; lean_object* v___x_1038_; 
v___x_1035_ = ((lean_object*)(lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn___closed__3_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4_));
v___x_1036_ = ((lean_object*)(lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn___closed__5_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4_));
v___x_1037_ = ((lean_object*)(lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn___closed__7_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4_));
v___x_1038_ = lp_JunkValues_Lean_Option_register___at___00__private_JunkValues_Extra_Discovery_0__JunkValues_initFn_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4__spec__0(v___x_1035_, v___x_1036_, v___x_1037_);
return v___x_1038_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4____boxed(lean_object* v_a_1039_){
_start:
{
lean_object* v_res_1040_; 
v_res_1040_ = lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4_();
return v_res_1040_;
}
}
LEAN_EXPORT uint8_t lp_JunkValues_Lean_Option_get___at___00JunkValues_discoveryProvider_spec__0(lean_object* v_opts_1041_, lean_object* v_opt_1042_){
_start:
{
lean_object* v_name_1043_; lean_object* v_defValue_1044_; lean_object* v_map_1045_; lean_object* v___x_1046_; 
v_name_1043_ = lean_ctor_get(v_opt_1042_, 0);
v_defValue_1044_ = lean_ctor_get(v_opt_1042_, 1);
v_map_1045_ = lean_ctor_get(v_opts_1041_, 0);
v___x_1046_ = l_Std_DTreeMap_Internal_Impl_Const_get_x3f___at___00Lean_NameMap_find_x3f_spec__0___redArg(v_map_1045_, v_name_1043_);
if (lean_obj_tag(v___x_1046_) == 0)
{
uint8_t v___x_1047_; 
v___x_1047_ = lean_unbox(v_defValue_1044_);
return v___x_1047_;
}
else
{
lean_object* v_val_1048_; 
v_val_1048_ = lean_ctor_get(v___x_1046_, 0);
lean_inc(v_val_1048_);
lean_dec_ref_known(v___x_1046_, 1);
if (lean_obj_tag(v_val_1048_) == 1)
{
uint8_t v_v_1049_; 
v_v_1049_ = lean_ctor_get_uint8(v_val_1048_, 0);
lean_dec_ref_known(v_val_1048_, 0);
return v_v_1049_;
}
else
{
uint8_t v___x_1050_; 
lean_dec(v_val_1048_);
v___x_1050_ = lean_unbox(v_defValue_1044_);
return v___x_1050_;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Option_get___at___00JunkValues_discoveryProvider_spec__0___boxed(lean_object* v_opts_1051_, lean_object* v_opt_1052_){
_start:
{
uint8_t v_res_1053_; lean_object* v_r_1054_; 
v_res_1053_ = lp_JunkValues_Lean_Option_get___at___00JunkValues_discoveryProvider_spec__0(v_opts_1051_, v_opt_1052_);
lean_dec_ref(v_opt_1052_);
lean_dec_ref(v_opts_1051_);
v_r_1054_ = lean_box(v_res_1053_);
return v_r_1054_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_discoveryProvider___lam__0(lean_object* v_opts_1059_, lean_object* v___y_1060_, lean_object* v___y_1061_, lean_object* v___y_1062_, lean_object* v___y_1063_){
_start:
{
lean_object* v___x_1065_; uint8_t v___x_1066_; 
v___x_1065_ = lp_JunkValues_JunkValues_linter_junkValues_discovery;
v___x_1066_ = lp_JunkValues_Lean_Option_get___at___00JunkValues_discoveryProvider_spec__0(v_opts_1059_, v___x_1065_);
if (v___x_1066_ == 0)
{
lean_object* v___x_1067_; lean_object* v___x_1068_; 
v___x_1067_ = ((lean_object*)(lp_JunkValues_JunkValues_discoveryProvider___lam__0___closed__0));
v___x_1068_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1068_, 0, v___x_1067_);
return v___x_1068_;
}
else
{
lean_object* v___x_1069_; lean_object* v___x_1070_; lean_object* v___x_1071_; 
v___x_1069_ = lean_box(0);
v___x_1070_ = lean_alloc_ctor(0, 1, 2);
lean_ctor_set(v___x_1070_, 0, v___x_1069_);
lean_ctor_set_uint8(v___x_1070_, sizeof(void*)*1, v___x_1066_);
lean_ctor_set_uint8(v___x_1070_, sizeof(void*)*1 + 1, v___x_1066_);
v___x_1071_ = lp_JunkValues_JunkValues_discoverRules(v___x_1070_, v___y_1060_, v___y_1061_, v___y_1062_, v___y_1063_);
if (lean_obj_tag(v___x_1071_) == 0)
{
lean_object* v_a_1072_; lean_object* v___x_1074_; uint8_t v_isShared_1075_; uint8_t v_isSharedCheck_1089_; 
v_a_1072_ = lean_ctor_get(v___x_1071_, 0);
v_isSharedCheck_1089_ = !lean_is_exclusive(v___x_1071_);
if (v_isSharedCheck_1089_ == 0)
{
v___x_1074_ = v___x_1071_;
v_isShared_1075_ = v_isSharedCheck_1089_;
goto v_resetjp_1073_;
}
else
{
lean_inc(v_a_1072_);
lean_dec(v___x_1071_);
v___x_1074_ = lean_box(0);
v_isShared_1075_ = v_isSharedCheck_1089_;
goto v_resetjp_1073_;
}
v_resetjp_1073_:
{
lean_object* v___x_1076_; lean_object* v___x_1077_; lean_object* v___x_1078_; lean_object* v___x_1079_; lean_object* v___x_1080_; lean_object* v___x_1081_; lean_object* v___x_1082_; lean_object* v___x_1083_; lean_object* v___x_1084_; lean_object* v___x_1085_; lean_object* v___x_1087_; 
v___x_1076_ = ((lean_object*)(lp_JunkValues_JunkValues_discoveryProvider___lam__0___closed__1));
v___x_1077_ = lean_array_get_size(v_a_1072_);
v___x_1078_ = l_Nat_reprFast(v___x_1077_);
v___x_1079_ = lean_string_append(v___x_1076_, v___x_1078_);
lean_dec_ref(v___x_1078_);
v___x_1080_ = ((lean_object*)(lp_JunkValues_JunkValues_discoveryProvider___lam__0___closed__2));
v___x_1081_ = lean_string_append(v___x_1079_, v___x_1080_);
v___x_1082_ = lean_unsigned_to_nat(1u);
v___x_1083_ = lean_mk_empty_array_with_capacity(v___x_1082_);
v___x_1084_ = lean_array_push(v___x_1083_, v___x_1081_);
v___x_1085_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1085_, 0, v_a_1072_);
lean_ctor_set(v___x_1085_, 1, v___x_1084_);
if (v_isShared_1075_ == 0)
{
lean_ctor_set(v___x_1074_, 0, v___x_1085_);
v___x_1087_ = v___x_1074_;
goto v_reusejp_1086_;
}
else
{
lean_object* v_reuseFailAlloc_1088_; 
v_reuseFailAlloc_1088_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1088_, 0, v___x_1085_);
v___x_1087_ = v_reuseFailAlloc_1088_;
goto v_reusejp_1086_;
}
v_reusejp_1086_:
{
return v___x_1087_;
}
}
}
else
{
lean_object* v_a_1090_; lean_object* v___x_1092_; uint8_t v_isShared_1093_; uint8_t v_isSharedCheck_1097_; 
v_a_1090_ = lean_ctor_get(v___x_1071_, 0);
v_isSharedCheck_1097_ = !lean_is_exclusive(v___x_1071_);
if (v_isSharedCheck_1097_ == 0)
{
v___x_1092_ = v___x_1071_;
v_isShared_1093_ = v_isSharedCheck_1097_;
goto v_resetjp_1091_;
}
else
{
lean_inc(v_a_1090_);
lean_dec(v___x_1071_);
v___x_1092_ = lean_box(0);
v_isShared_1093_ = v_isSharedCheck_1097_;
goto v_resetjp_1091_;
}
v_resetjp_1091_:
{
lean_object* v___x_1095_; 
if (v_isShared_1093_ == 0)
{
v___x_1095_ = v___x_1092_;
goto v_reusejp_1094_;
}
else
{
lean_object* v_reuseFailAlloc_1096_; 
v_reuseFailAlloc_1096_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1096_, 0, v_a_1090_);
v___x_1095_ = v_reuseFailAlloc_1096_;
goto v_reusejp_1094_;
}
v_reusejp_1094_:
{
return v___x_1095_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_discoveryProvider___lam__0___boxed(lean_object* v_opts_1098_, lean_object* v___y_1099_, lean_object* v___y_1100_, lean_object* v___y_1101_, lean_object* v___y_1102_, lean_object* v___y_1103_){
_start:
{
lean_object* v_res_1104_; 
v_res_1104_ = lp_JunkValues_JunkValues_discoveryProvider___lam__0(v_opts_1098_, v___y_1099_, v___y_1100_, v___y_1101_, v___y_1102_);
lean_dec(v___y_1102_);
lean_dec_ref(v___y_1101_);
lean_dec(v___y_1100_);
lean_dec_ref(v___y_1099_);
lean_dec_ref(v_opts_1098_);
return v_res_1104_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn_00___x40_JunkValues_Extra_Discovery_231217443____hygCtx___hyg_2_(){
_start:
{
lean_object* v___x_1111_; lean_object* v___x_1112_; 
v___x_1111_ = ((lean_object*)(lp_JunkValues_JunkValues_discoveryProvider));
v___x_1112_ = lp_JunkValues_JunkValues_registerRuleProvider(v___x_1111_);
return v___x_1112_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn_00___x40_JunkValues_Extra_Discovery_231217443____hygCtx___hyg_2____boxed(lean_object* v_a_1113_){
_start:
{
lean_object* v_res_1114_; 
v_res_1114_ = lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn_00___x40_JunkValues_Extra_Discovery_231217443____hygCtx___hyg_2_();
return v_res_1114_;
}
}
lean_object* runtime_initialize_Init(uint8_t builtin);
lean_object* runtime_initialize_JunkValues_JunkValues_RuleSet(uint8_t builtin);
lean_object* runtime_initialize_Std_Data_HashSet(uint8_t builtin);
static bool _G_runtime_initialized = false;
LEAN_EXPORT lean_object* runtime_initialize_JunkValues_JunkValues_Extra_Discovery(uint8_t builtin) {
lean_object * res;
if (_G_runtime_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_runtime_initialized = true;
res = runtime_initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = runtime_initialize_JunkValues_JunkValues_RuleSet(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = runtime_initialize_Std_Data_HashSet(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn_00___x40_JunkValues_Extra_Discovery_23868550____hygCtx___hyg_4_();
if (lean_io_result_is_error(res)) return res;
lp_JunkValues_JunkValues_linter_junkValues_discovery = lean_io_result_get_value(res);
lean_mark_persistent(lp_JunkValues_JunkValues_linter_junkValues_discovery);
lean_dec_ref(res);
res = lp_JunkValues___private_JunkValues_Extra_Discovery_0__JunkValues_initFn_00___x40_JunkValues_Extra_Discovery_231217443____hygCtx___hyg_2_();
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return lean_io_result_mk_ok(lean_box(0));
}
lean_object* runtime_initialize_Init(uint8_t builtin);
static bool _G_meta_initialized = false;
LEAN_EXPORT lean_object* meta_initialize_JunkValues_JunkValues_Extra_Discovery(uint8_t builtin) {
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
lean_object* initialize_Std_Data_HashSet(uint8_t builtin);
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_JunkValues_JunkValues_Extra_Discovery(uint8_t builtin) {
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
res = initialize_Std_Data_HashSet(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = runtime_initialize_JunkValues_JunkValues_Extra_Discovery(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = meta_initialize_JunkValues_JunkValues_Extra_Discovery(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return initialize_JunkValues_JunkValues_Extra_Discovery(builtin);
}
#ifdef __cplusplus
}
#endif
