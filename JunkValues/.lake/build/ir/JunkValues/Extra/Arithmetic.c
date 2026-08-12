// Lean compiler output
// Module: JunkValues.Extra.Arithmetic
// Imports: public import Init public meta import Init public import JunkValues.Extra.Entry
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
lean_object* l_Lean_Name_mkStr2(lean_object*, lean_object*);
lean_object* l_Lean_Name_mkStr1(lean_object*);
lean_object* lean_mk_empty_array_with_capacity(lean_object*);
lean_object* lean_array_push(lean_object*, lean_object*);
lean_object* lp_JunkValues_JunkValues_catalogueProvider(lean_object*, lean_object*);
lean_object* lp_JunkValues_JunkValues_registerRuleProvider(lean_object*);
static const lean_string_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "div_zero"};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__0_value;
static const lean_ctor_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__0_value),LEAN_SCALAR_PTR_LITERAL(10, 40, 79, 151, 88, 8, 92, 230)}};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__1 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__1_value;
static const lean_string_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 115, .m_capacity = 115, .m_length = 110, .m_data = "division by zero is 0, not undefined — so `a / b = 0` carries no information about `a` unless `b ≠ 0` is known"};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__2 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__2_value;
static const lean_array_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*1, .m_other = 0, .m_tag = 246}, .m_size = 1, .m_capacity = 1, .m_data = {((lean_object*)(((size_t)(2) << 1) | 1))}};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__3 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__3_value;
static const lean_ctor_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*3 + 0, .m_other = 3, .m_tag = 0}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__1_value),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__2_value),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__3_value)}};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__4 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__4_value;
static const lean_string_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "Nat"};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__5 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__5_value;
static const lean_ctor_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__6_value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__5_value),LEAN_SCALAR_PTR_LITERAL(155, 221, 223, 104, 58, 13, 204, 158)}};
static const lean_ctor_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__6_value_aux_0),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__0_value),LEAN_SCALAR_PTR_LITERAL(106, 242, 7, 52, 171, 221, 114, 124)}};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__6 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__6_value;
static const lean_string_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 71, .m_capacity = 71, .m_length = 70, .m_data = "natural division by zero is 0 (and natural division truncates besides)"};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__7 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__7_value;
static const lean_ctor_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*3 + 0, .m_other = 3, .m_tag = 0}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__6_value),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__7_value),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__3_value)}};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__8 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__8_value;
static const lean_string_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "Int"};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__9 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__9_value;
static const lean_string_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 10, .m_capacity = 10, .m_length = 9, .m_data = "ediv_zero"};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__10 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__10_value;
static const lean_ctor_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__11_value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__9_value),LEAN_SCALAR_PTR_LITERAL(61, 25, 98, 154, 117, 127, 69, 97)}};
static const lean_ctor_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__11_value_aux_0),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__10_value),LEAN_SCALAR_PTR_LITERAL(5, 55, 207, 121, 182, 231, 67, 245)}};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__11 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__11_value;
static const lean_string_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__12_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 30, .m_capacity = 30, .m_length = 29, .m_data = "integer division by zero is 0"};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__12 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__12_value;
static const lean_ctor_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__13_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*3 + 0, .m_other = 3, .m_tag = 0}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__11_value),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__12_value),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__3_value)}};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__13 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__13_value;
static const lean_string_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__14_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "EReal"};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__14 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__14_value;
static const lean_ctor_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__15_value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__14_value),LEAN_SCALAR_PTR_LITERAL(123, 65, 115, 221, 204, 230, 105, 61)}};
static const lean_ctor_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__15_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__15_value_aux_0),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__0_value),LEAN_SCALAR_PTR_LITERAL(74, 182, 111, 5, 45, 167, 68, 112)}};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__15 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__15_value;
static const lean_string_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__16_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 33, .m_capacity = 33, .m_length = 32, .m_data = "division by zero in `EReal` is 0"};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__16 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__16_value;
static const lean_ctor_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__17_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*3 + 0, .m_other = 3, .m_tag = 0}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__15_value),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__16_value),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__3_value)}};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__17 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__17_value;
static const lean_string_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__18_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "ENNReal"};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__18 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__18_value;
static const lean_ctor_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__19_value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__18_value),LEAN_SCALAR_PTR_LITERAL(145, 123, 175, 100, 55, 171, 123, 169)}};
static const lean_ctor_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__19_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__19_value_aux_0),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__0_value),LEAN_SCALAR_PTR_LITERAL(232, 181, 19, 118, 243, 205, 229, 145)}};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__19 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__19_value;
static const lean_string_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__20_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 117, .m_capacity = 117, .m_length = 114, .m_data = "division of a nonzero extended non-negative real by zero is ⊤, unlike every other division-by-zero convention here"};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__20 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__20_value;
static const lean_ctor_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__21_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*3 + 0, .m_other = 3, .m_tag = 0}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__19_value),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__20_value),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__3_value)}};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__21 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__21_value;
static const lean_string_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__22_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "inv_zero"};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__22 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__22_value;
static const lean_ctor_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__23_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__22_value),LEAN_SCALAR_PTR_LITERAL(153, 16, 72, 231, 61, 237, 237, 45)}};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__23 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__23_value;
static const lean_string_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__24_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 72, .m_capacity = 72, .m_length = 68, .m_data = "the inverse of zero is zero, so `x⁻¹ = 0` does not mean `x` is large"};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__24 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__24_value;
static const lean_array_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__25_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*1, .m_other = 0, .m_tag = 246}, .m_size = 1, .m_capacity = 1, .m_data = {((lean_object*)(((size_t)(1) << 1) | 1))}};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__25 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__25_value;
static const lean_ctor_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__26_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*3 + 0, .m_other = 3, .m_tag = 0}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__23_value),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__24_value),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__25_value)}};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__26 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__26_value;
static const lean_string_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__27_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 19, .m_capacity = 19, .m_length = 18, .m_data = "tsub_eq_zero_of_le"};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__27 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__27_value;
static const lean_ctor_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__28_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__27_value),LEAN_SCALAR_PTR_LITERAL(194, 61, 223, 186, 0, 67, 134, 26)}};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__28 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__28_value;
static const lean_string_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__29_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 86, .m_capacity = 86, .m_length = 83, .m_data = "truncated subtraction clamps at 0, so `a - b = 0` means `a ≤ b` rather than `a = b`"};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__29 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__29_value;
static const lean_array_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__30_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__30 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__30_value;
static const lean_ctor_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__31_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*3 + 0, .m_other = 3, .m_tag = 0}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__28_value),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__29_value),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__30_value)}};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__31 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__31_value;
static const lean_string_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__32_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "toReal_top"};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__32 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__32_value;
static const lean_ctor_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__33_value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__18_value),LEAN_SCALAR_PTR_LITERAL(145, 123, 175, 100, 55, 171, 123, 169)}};
static const lean_ctor_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__33_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__33_value_aux_0),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__32_value),LEAN_SCALAR_PTR_LITERAL(255, 72, 33, 23, 204, 118, 94, 208)}};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__33 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__33_value;
static const lean_string_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__34_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 113, .m_capacity = 113, .m_length = 104, .m_data = "`(⊤ : ℝ≥0∞).toReal = 0`, so an infinite measure, moment or divergence silently becomes the real number 0"};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__34 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__34_value;
static const lean_ctor_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__35_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*3 + 0, .m_other = 3, .m_tag = 0}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__33_value),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__34_value),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__25_value)}};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__35 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__35_value;
static const lean_string_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__36_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 13, .m_capacity = 13, .m_length = 12, .m_data = "toNNReal_top"};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__36 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__36_value;
static const lean_ctor_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__37_value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__18_value),LEAN_SCALAR_PTR_LITERAL(145, 123, 175, 100, 55, 171, 123, 169)}};
static const lean_ctor_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__37_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__37_value_aux_0),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__36_value),LEAN_SCALAR_PTR_LITERAL(143, 231, 198, 79, 5, 132, 41, 10)}};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__37 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__37_value;
static const lean_string_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__38_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 68, .m_capacity = 68, .m_length = 55, .m_data = "`(⊤ : ℝ≥0∞).toNNReal = 0`, the same collapse into `ℝ≥0`"};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__38 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__38_value;
static const lean_ctor_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__39_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*3 + 0, .m_other = 3, .m_tag = 0}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__37_value),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__38_value),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__25_value)}};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__39 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__39_value;
static const lean_ctor_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__40_value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__14_value),LEAN_SCALAR_PTR_LITERAL(123, 65, 115, 221, 204, 230, 105, 61)}};
static const lean_ctor_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__40_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__40_value_aux_0),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__32_value),LEAN_SCALAR_PTR_LITERAL(93, 120, 140, 8, 149, 60, 148, 113)}};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__40 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__40_value;
static const lean_string_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__41_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 27, .m_capacity = 27, .m_length = 24, .m_data = "`(⊤ : EReal).toReal = 0`"};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__41 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__41_value;
static const lean_ctor_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__42_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*3 + 0, .m_other = 3, .m_tag = 0}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__40_value),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__41_value),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__25_value)}};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__42 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__42_value;
static const lean_string_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__43_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "toReal_bot"};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__43 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__43_value;
static const lean_ctor_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__44_value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__14_value),LEAN_SCALAR_PTR_LITERAL(123, 65, 115, 221, 204, 230, 105, 61)}};
static const lean_ctor_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__44_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__44_value_aux_0),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__43_value),LEAN_SCALAR_PTR_LITERAL(237, 240, 245, 249, 166, 11, 19, 144)}};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__44 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__44_value;
static const lean_string_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__45_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 78, .m_capacity = 78, .m_length = 75, .m_data = "`(⊥ : EReal).toReal = 0`, so both infinities coerce to the same real number"};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__45 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__45_value;
static const lean_ctor_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__46_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*3 + 0, .m_other = 3, .m_tag = 0}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__44_value),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__45_value),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__25_value)}};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__46 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__46_value;
static const lean_string_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__47_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "Real"};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__47 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__47_value;
static const lean_string_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__48_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "log_zero"};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__48 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__48_value;
static const lean_ctor_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__49_value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__47_value),LEAN_SCALAR_PTR_LITERAL(70, 97, 13, 185, 175, 95, 64, 15)}};
static const lean_ctor_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__49_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__49_value_aux_0),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__48_value),LEAN_SCALAR_PTR_LITERAL(17, 4, 97, 62, 93, 156, 58, 224)}};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__49 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__49_value;
static const lean_string_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__50_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 70, .m_capacity = 70, .m_length = 69, .m_data = "`Real.log 0 = 0` by convention, which is also the value of `log` at 1"};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__50 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__50_value;
static const lean_ctor_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__51_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*3 + 0, .m_other = 3, .m_tag = 0}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__49_value),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__50_value),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__25_value)}};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__51 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__51_value;
static const lean_string_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__52_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "Polynomial"};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__52 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__52_value;
static const lean_string_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__53_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 12, .m_capacity = 12, .m_length = 11, .m_data = "degree_zero"};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__53 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__53_value;
static const lean_ctor_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__54_value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__52_value),LEAN_SCALAR_PTR_LITERAL(81, 20, 154, 203, 94, 248, 164, 115)}};
static const lean_ctor_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__54_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__54_value_aux_0),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__53_value),LEAN_SCALAR_PTR_LITERAL(140, 10, 120, 108, 16, 211, 151, 109)}};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__54 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__54_value;
static const lean_string_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__55_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 148, .m_capacity = 148, .m_length = 145, .m_data = "the zero polynomial has degree ⊥ rather than a natural number, so a `degree` comparison can hold for a reason unrelated to the polynomial's shape"};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__55 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__55_value;
static const lean_ctor_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__56_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*3 + 0, .m_other = 3, .m_tag = 0}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__54_value),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__55_value),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__25_value)}};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__56 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__56_value;
static const lean_array_object lp_JunkValues_JunkValues_arithmeticCatalogue___closed__57_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*13, .m_other = 0, .m_tag = 246}, .m_size = 13, .m_capacity = 13, .m_data = {((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__4_value),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__8_value),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__13_value),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__17_value),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__21_value),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__26_value),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__31_value),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__35_value),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__39_value),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__42_value),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__46_value),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__51_value),((lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__56_value)}};
static const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue___closed__57 = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__57_value;
LEAN_EXPORT const lean_object* lp_JunkValues_JunkValues_arithmeticCatalogue = (const lean_object*)&lp_JunkValues_JunkValues_arithmeticCatalogue___closed__57_value;
static const lean_string_object lp_JunkValues___private_JunkValues_Extra_Arithmetic_0__JunkValues_initFn___closed__0_00___x40_JunkValues_Extra_Arithmetic_3884778816____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "arithmetic"};
static const lean_object* lp_JunkValues___private_JunkValues_Extra_Arithmetic_0__JunkValues_initFn___closed__0_00___x40_JunkValues_Extra_Arithmetic_3884778816____hygCtx___hyg_2_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Extra_Arithmetic_0__JunkValues_initFn___closed__0_00___x40_JunkValues_Extra_Arithmetic_3884778816____hygCtx___hyg_2__value;
static lean_once_cell_t lp_JunkValues___private_JunkValues_Extra_Arithmetic_0__JunkValues_initFn___closed__1_00___x40_JunkValues_Extra_Arithmetic_3884778816____hygCtx___hyg_2__once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues___private_JunkValues_Extra_Arithmetic_0__JunkValues_initFn___closed__1_00___x40_JunkValues_Extra_Arithmetic_3884778816____hygCtx___hyg_2_;
LEAN_EXPORT lean_object* lp_JunkValues___private_JunkValues_Extra_Arithmetic_0__JunkValues_initFn_00___x40_JunkValues_Extra_Arithmetic_3884778816____hygCtx___hyg_2_();
LEAN_EXPORT lean_object* lp_JunkValues___private_JunkValues_Extra_Arithmetic_0__JunkValues_initFn_00___x40_JunkValues_Extra_Arithmetic_3884778816____hygCtx___hyg_2____boxed(lean_object*);
static lean_object* _init_lp_JunkValues___private_JunkValues_Extra_Arithmetic_0__JunkValues_initFn___closed__1_00___x40_JunkValues_Extra_Arithmetic_3884778816____hygCtx___hyg_2_(void){
_start:
{
lean_object* v___x_156_; lean_object* v___x_157_; lean_object* v___x_158_; 
v___x_156_ = ((lean_object*)(lp_JunkValues_JunkValues_arithmeticCatalogue));
v___x_157_ = ((lean_object*)(lp_JunkValues___private_JunkValues_Extra_Arithmetic_0__JunkValues_initFn___closed__0_00___x40_JunkValues_Extra_Arithmetic_3884778816____hygCtx___hyg_2_));
v___x_158_ = lp_JunkValues_JunkValues_catalogueProvider(v___x_157_, v___x_156_);
return v___x_158_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_JunkValues_Extra_Arithmetic_0__JunkValues_initFn_00___x40_JunkValues_Extra_Arithmetic_3884778816____hygCtx___hyg_2_(){
_start:
{
lean_object* v___x_160_; lean_object* v___x_161_; 
v___x_160_ = lean_obj_once(&lp_JunkValues___private_JunkValues_Extra_Arithmetic_0__JunkValues_initFn___closed__1_00___x40_JunkValues_Extra_Arithmetic_3884778816____hygCtx___hyg_2_, &lp_JunkValues___private_JunkValues_Extra_Arithmetic_0__JunkValues_initFn___closed__1_00___x40_JunkValues_Extra_Arithmetic_3884778816____hygCtx___hyg_2__once, _init_lp_JunkValues___private_JunkValues_Extra_Arithmetic_0__JunkValues_initFn___closed__1_00___x40_JunkValues_Extra_Arithmetic_3884778816____hygCtx___hyg_2_);
v___x_161_ = lp_JunkValues_JunkValues_registerRuleProvider(v___x_160_);
return v___x_161_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_JunkValues_Extra_Arithmetic_0__JunkValues_initFn_00___x40_JunkValues_Extra_Arithmetic_3884778816____hygCtx___hyg_2____boxed(lean_object* v_a_162_){
_start:
{
lean_object* v_res_163_; 
v_res_163_ = lp_JunkValues___private_JunkValues_Extra_Arithmetic_0__JunkValues_initFn_00___x40_JunkValues_Extra_Arithmetic_3884778816____hygCtx___hyg_2_();
return v_res_163_;
}
}
lean_object* runtime_initialize_Init(uint8_t builtin);
lean_object* runtime_initialize_JunkValues_JunkValues_Extra_Entry(uint8_t builtin);
static bool _G_runtime_initialized = false;
LEAN_EXPORT lean_object* runtime_initialize_JunkValues_JunkValues_Extra_Arithmetic(uint8_t builtin) {
lean_object * res;
if (_G_runtime_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_runtime_initialized = true;
res = runtime_initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = runtime_initialize_JunkValues_JunkValues_Extra_Entry(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = lp_JunkValues___private_JunkValues_Extra_Arithmetic_0__JunkValues_initFn_00___x40_JunkValues_Extra_Arithmetic_3884778816____hygCtx___hyg_2_();
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return lean_io_result_mk_ok(lean_box(0));
}
lean_object* runtime_initialize_Init(uint8_t builtin);
static bool _G_meta_initialized = false;
LEAN_EXPORT lean_object* meta_initialize_JunkValues_JunkValues_Extra_Arithmetic(uint8_t builtin) {
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
lean_object* initialize_JunkValues_JunkValues_Extra_Entry(uint8_t builtin);
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_JunkValues_JunkValues_Extra_Arithmetic(uint8_t builtin) {
lean_object * res;
if (_G_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_initialized = true;
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_JunkValues_JunkValues_Extra_Entry(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = runtime_initialize_JunkValues_JunkValues_Extra_Arithmetic(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = meta_initialize_JunkValues_JunkValues_Extra_Arithmetic(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return initialize_JunkValues_JunkValues_Extra_Arithmetic(builtin);
}
#ifdef __cplusplus
}
#endif
