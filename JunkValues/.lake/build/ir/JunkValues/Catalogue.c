// Lean compiler output
// Module: JunkValues.Catalogue
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
lean_object* l_Lean_Name_mkStr1(lean_object*);
uint8_t lean_name_eq(lean_object*, lean_object*);
uint8_t lean_string_dec_eq(lean_object*, lean_object*);
lean_object* l_Lean_Name_mkStr2(lean_object*, lean_object*);
lean_object* lean_nat_to_int(lean_object*);
lean_object* l_Lean_Name_reprPrec(lean_object*, lean_object*);
lean_object* l_String_quote(lean_object*);
lean_object* lean_string_length(lean_object*);
lean_object* l_Lean_Name_mkStr3(lean_object*, lean_object*, lean_object*);
lean_object* lean_mk_empty_array_with_capacity(lean_object*);
lean_object* lean_array_push(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Nat_cast___at___00JunkValues_instReprCatalogueEntry_repr_spec__0(lean_object*);
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
static const lean_string_object lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 2, .m_capacity = 2, .m_length = 1, .m_data = ","};
static const lean_object* lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__8 = (const lean_object*)&lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__8_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__8_value)}};
static const lean_object* lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__9 = (const lean_object*)&lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__9_value;
static const lean_string_object lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "note"};
static const lean_object* lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__10 = (const lean_object*)&lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__10_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__10_value)}};
static const lean_object* lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__11 = (const lean_object*)&lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__11_value;
static lean_once_cell_t lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__12_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__12;
static const lean_string_object lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__13_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = " }"};
static const lean_object* lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__13 = (const lean_object*)&lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__13_value;
static lean_once_cell_t lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__14_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__14;
static lean_once_cell_t lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__15_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__15;
static const lean_ctor_object lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__16_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__0_value)}};
static const lean_object* lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__16 = (const lean_object*)&lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__16_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__17_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__13_value)}};
static const lean_object* lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__17 = (const lean_object*)&lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__17_value;
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instReprCatalogueEntry_repr(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_JunkValues_JunkValues_instReprCatalogueEntry___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_JunkValues_JunkValues_instReprCatalogueEntry___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_instReprCatalogueEntry___closed__0_value;
LEAN_EXPORT const lean_object* lp_JunkValues_JunkValues_instReprCatalogueEntry = (const lean_object*)&lp_JunkValues_JunkValues_instReprCatalogueEntry___closed__0_value;
static const lean_string_object lp_JunkValues_JunkValues_instInhabitedCatalogueEntry_default___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 1, .m_capacity = 1, .m_length = 0, .m_data = ""};
static const lean_object* lp_JunkValues_JunkValues_instInhabitedCatalogueEntry_default___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_instInhabitedCatalogueEntry_default___closed__0_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instInhabitedCatalogueEntry_default___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_instInhabitedCatalogueEntry_default___closed__0_value)}};
static const lean_object* lp_JunkValues_JunkValues_instInhabitedCatalogueEntry_default___closed__1 = (const lean_object*)&lp_JunkValues_JunkValues_instInhabitedCatalogueEntry_default___closed__1_value;
LEAN_EXPORT const lean_object* lp_JunkValues_JunkValues_instInhabitedCatalogueEntry_default = (const lean_object*)&lp_JunkValues_JunkValues_instInhabitedCatalogueEntry_default___closed__1_value;
LEAN_EXPORT const lean_object* lp_JunkValues_JunkValues_instInhabitedCatalogueEntry = (const lean_object*)&lp_JunkValues_JunkValues_instInhabitedCatalogueEntry_default___closed__1_value;
LEAN_EXPORT uint8_t lp_JunkValues_JunkValues_instBEqCatalogueEntry_beq(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instBEqCatalogueEntry_beq___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_JunkValues_JunkValues_instBEqCatalogueEntry___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_JunkValues_JunkValues_instBEqCatalogueEntry_beq___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_JunkValues_JunkValues_instBEqCatalogueEntry___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_instBEqCatalogueEntry___closed__0_value;
LEAN_EXPORT const lean_object* lp_JunkValues_JunkValues_instBEqCatalogueEntry = (const lean_object*)&lp_JunkValues_JunkValues_instBEqCatalogueEntry___closed__0_value;
static const lean_string_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 14, .m_capacity = 14, .m_length = 13, .m_data = "MeasureTheory"};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__0_value;
static const lean_string_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 15, .m_capacity = 15, .m_length = 14, .m_data = "integral_undef"};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__1 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__1_value;
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__2_value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__0_value),LEAN_SCALAR_PTR_LITERAL(15, 237, 169, 28, 227, 202, 14, 52)}};
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__2_value_aux_0),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__1_value),LEAN_SCALAR_PTR_LITERAL(37, 130, 216, 111, 1, 60, 185, 50)}};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__2 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__2_value;
static const lean_string_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 108, .m_capacity = 108, .m_length = 107, .m_data = "a Bochner integral of a non-integrable function is 0, so an equation between two of them can hold vacuously"};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__3 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__3_value;
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__2_value),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__3_value)}};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__4 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__4_value;
static const lean_string_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 17, .m_capacity = 17, .m_length = 16, .m_data = "intervalIntegral"};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__5 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__5_value;
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__6_value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__5_value),LEAN_SCALAR_PTR_LITERAL(220, 24, 191, 134, 240, 69, 58, 62)}};
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__6_value_aux_0),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__1_value),LEAN_SCALAR_PTR_LITERAL(170, 240, 234, 139, 68, 171, 75, 194)}};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__6 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__6_value;
static const lean_string_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 72, .m_capacity = 72, .m_length = 71, .m_data = "an interval integral of a function that is not interval-integrable is 0"};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__7 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__7_value;
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__6_value),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__7_value)}};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__8 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__8_value;
static const lean_string_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 15, .m_capacity = 15, .m_length = 14, .m_data = "circleIntegral"};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__9 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__9_value;
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__10_value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__9_value),LEAN_SCALAR_PTR_LITERAL(38, 178, 83, 182, 221, 145, 43, 187)}};
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__10_value_aux_0),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__1_value),LEAN_SCALAR_PTR_LITERAL(216, 110, 202, 147, 202, 17, 241, 124)}};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__10 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__10_value;
static const lean_string_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 67, .m_capacity = 67, .m_length = 66, .m_data = "a circle integral of a function that is not circle-integrable is 0"};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__11 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__11_value;
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__12_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__10_value),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__11_value)}};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__12 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__12_value;
static const lean_string_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__13_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 15, .m_capacity = 15, .m_length = 14, .m_data = "setToFun_undef"};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__13 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__13_value;
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__14_value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__0_value),LEAN_SCALAR_PTR_LITERAL(15, 237, 169, 28, 227, 202, 14, 52)}};
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__14_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__14_value_aux_0),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__13_value),LEAN_SCALAR_PTR_LITERAL(166, 75, 38, 93, 86, 25, 101, 28)}};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__14 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__14_value;
static const lean_string_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__15_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 63, .m_capacity = 63, .m_length = 62, .m_data = "the set-to-function integral of a non-integrable function is 0"};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__15 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__15_value;
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__16_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__14_value),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__15_value)}};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__16 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__16_value;
static const lean_string_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__17_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 26, .m_capacity = 26, .m_length = 25, .m_data = "condExp_of_not_integrable"};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__17 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__17_value;
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__18_value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__0_value),LEAN_SCALAR_PTR_LITERAL(15, 237, 169, 28, 227, 202, 14, 52)}};
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__18_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__18_value_aux_0),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__17_value),LEAN_SCALAR_PTR_LITERAL(159, 124, 51, 103, 72, 42, 118, 86)}};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__18 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__18_value;
static const lean_string_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__19_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 98, .m_capacity = 98, .m_length = 97, .m_data = "a conditional expectation of a non-integrable function is the zero function, not an undefined one"};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__19 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__19_value;
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__20_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__18_value),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__19_value)}};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__20 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__20_value;
static const lean_string_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__21_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 16, .m_capacity = 16, .m_length = 15, .m_data = "condExpL1_undef"};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__21 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__21_value;
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__22_value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__0_value),LEAN_SCALAR_PTR_LITERAL(15, 237, 169, 28, 227, 202, 14, 52)}};
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__22_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__22_value_aux_0),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__21_value),LEAN_SCALAR_PTR_LITERAL(21, 239, 157, 125, 168, 8, 228, 81)}};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__22 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__22_value;
static const lean_string_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__23_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 66, .m_capacity = 66, .m_length = 64, .m_data = "the L¹ conditional expectation of a non-integrable function is 0"};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__23 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__23_value;
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__24_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__22_value),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__23_value)}};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__24 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__24_value;
static const lean_string_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__25_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 18, .m_capacity = 18, .m_length = 17, .m_data = "ProbabilityTheory"};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__25 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__25_value;
static const lean_string_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__26_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 26, .m_capacity = 26, .m_length = 25, .m_data = "condVar_of_not_integrable"};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__26 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__26_value;
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__27_value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__25_value),LEAN_SCALAR_PTR_LITERAL(54, 221, 47, 243, 142, 200, 232, 123)}};
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__27_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__27_value_aux_0),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__26_value),LEAN_SCALAR_PTR_LITERAL(182, 183, 61, 18, 121, 170, 23, 207)}};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__27 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__27_value;
static const lean_string_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__28_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 132, .m_capacity = 132, .m_length = 129, .m_data = "a conditional variance is 0 when the squared deviation is not integrable — the same value as for an a.s. constant random variable"};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__28 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__28_value;
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__29_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__27_value),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__28_value)}};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__29 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__29_value;
static const lean_string_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__30_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 29, .m_capacity = 29, .m_length = 28, .m_data = "tsum_eq_zero_of_not_summable"};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__30 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__30_value;
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__31_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__30_value),LEAN_SCALAR_PTR_LITERAL(64, 119, 134, 23, 227, 191, 85, 179)}};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__31 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__31_value;
static const lean_string_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__32_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 93, .m_capacity = 93, .m_length = 92, .m_data = "an unconditional sum of a non-summable family is 0, which is also the sum of the zero family"};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__32 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__32_value;
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__33_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__31_value),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__32_value)}};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__33 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__33_value;
static const lean_string_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__34_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 33, .m_capacity = 33, .m_length = 32, .m_data = "tprod_eq_one_of_not_multipliable"};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__34 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__34_value;
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__35_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__34_value),LEAN_SCALAR_PTR_LITERAL(157, 3, 73, 102, 12, 239, 190, 136)}};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__35 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__35_value;
static const lean_string_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__36_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 59, .m_capacity = 59, .m_length = 58, .m_data = "an unconditional product of a non-multipliable family is 1"};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__36 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__36_value;
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__37_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__35_value),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__36_value)}};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__37 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__37_value;
static const lean_string_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__38_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 35, .m_capacity = 35, .m_length = 34, .m_data = "deriv_zero_of_not_differentiableAt"};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__38 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__38_value;
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__39_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__38_value),LEAN_SCALAR_PTR_LITERAL(1, 180, 190, 237, 96, 61, 245, 33)}};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__39 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__39_value;
static const lean_string_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__40_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 115, .m_capacity = 115, .m_length = 114, .m_data = "the derivative of a function not differentiable at the point is 0, indistinguishable from a genuine critical point"};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__40 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__40_value;
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__41_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__39_value),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__40_value)}};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__41 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__41_value;
static const lean_string_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__42_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 47, .m_capacity = 47, .m_length = 46, .m_data = "derivWithin_zero_of_not_differentiableWithinAt"};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__42 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__42_value;
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__43_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__42_value),LEAN_SCALAR_PTR_LITERAL(36, 225, 59, 220, 139, 125, 224, 187)}};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__43 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__43_value;
static const lean_string_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__44_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 82, .m_capacity = 82, .m_length = 81, .m_data = "a derivative within a set is 0 where the function is not differentiable within it"};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__44 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__44_value;
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__45_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__43_value),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__44_value)}};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__45 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__45_value;
static const lean_string_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__46_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 36, .m_capacity = 36, .m_length = 35, .m_data = "fderiv_zero_of_not_differentiableAt"};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__46 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__46_value;
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__47_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__46_value),LEAN_SCALAR_PTR_LITERAL(190, 66, 105, 126, 17, 151, 14, 142)}};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__47 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__47_value;
static const lean_string_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__48_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 86, .m_capacity = 86, .m_length = 84, .m_data = "the Fréchet derivative of a function not differentiable at the point is the zero map"};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__48 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__48_value;
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__49_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__47_value),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__48_value)}};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__49 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__49_value;
static const lean_string_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__50_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 48, .m_capacity = 48, .m_length = 47, .m_data = "fderivWithin_zero_of_not_differentiableWithinAt"};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__50 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__50_value;
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__51_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__50_value),LEAN_SCALAR_PTR_LITERAL(247, 80, 128, 37, 47, 156, 81, 211)}};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__51 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__51_value;
static const lean_string_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__52_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 102, .m_capacity = 102, .m_length = 100, .m_data = "a Fréchet derivative within a set is the zero map where the function is not differentiable within it"};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__52 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__52_value;
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__53_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__51_value),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__52_value)}};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__53 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__53_value;
static const lean_string_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__54_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 41, .m_capacity = 41, .m_length = 40, .m_data = "gradient_eq_zero_of_not_differentiableAt"};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__54 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__54_value;
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__55_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__54_value),LEAN_SCALAR_PTR_LITERAL(21, 238, 49, 26, 150, 154, 71, 241)}};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__55 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__55_value;
static const lean_string_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__56_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 64, .m_capacity = 64, .m_length = 63, .m_data = "the gradient of a function not differentiable at the point is 0"};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__56 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__56_value;
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__57_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__55_value),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__56_value)}};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__57 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__57_value;
static const lean_string_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__58_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 41, .m_capacity = 41, .m_length = 40, .m_data = "logDeriv_eq_zero_of_not_differentiableAt"};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__58 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__58_value;
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__59_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__58_value),LEAN_SCALAR_PTR_LITERAL(47, 0, 67, 254, 225, 66, 94, 127)}};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__59 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__59_value;
static const lean_string_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__60_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 78, .m_capacity = 78, .m_length = 77, .m_data = "the logarithmic derivative of a function not differentiable at the point is 0"};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__60 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__60_value;
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__61_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__59_value),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__60_value)}};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__61 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__61_value;
static const lean_string_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__62_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 10, .m_capacity = 10, .m_length = 9, .m_data = "mgf_undef"};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__62 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__62_value;
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__63_value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__25_value),LEAN_SCALAR_PTR_LITERAL(54, 221, 47, 243, 142, 200, 232, 123)}};
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__63_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__63_value_aux_0),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__62_value),LEAN_SCALAR_PTR_LITERAL(216, 174, 125, 167, 222, 121, 179, 234)}};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__63 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__63_value;
static const lean_string_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__64_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 124, .m_capacity = 124, .m_length = 123, .m_data = "the moment generating function is 0 where the exponential moment does not exist, and 0 is not a value any genuine mgf takes"};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__64 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__64_value;
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__65_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__63_value),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__64_value)}};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__65 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__65_value;
static const lean_string_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__66_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 10, .m_capacity = 10, .m_length = 9, .m_data = "cgf_undef"};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__66 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__66_value;
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__67_value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__25_value),LEAN_SCALAR_PTR_LITERAL(54, 221, 47, 243, 142, 200, 232, 123)}};
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__67_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__67_value_aux_0),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__66_value),LEAN_SCALAR_PTR_LITERAL(51, 57, 139, 197, 145, 202, 106, 239)}};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__67 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__67_value;
static const lean_string_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__68_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 116, .m_capacity = 116, .m_length = 115, .m_data = "the cumulant generating function is 0 where the exponential moment does not exist, which is also its value at t = 0"};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__68 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__68_value;
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__69_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__67_value),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__68_value)}};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__69 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__69_value;
static const lean_string_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__70_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 17, .m_capacity = 17, .m_length = 16, .m_data = "complexMGF_undef"};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__70 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__70_value;
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__71_value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__25_value),LEAN_SCALAR_PTR_LITERAL(54, 221, 47, 243, 142, 200, 232, 123)}};
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__71_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__71_value_aux_0),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__70_value),LEAN_SCALAR_PTR_LITERAL(15, 247, 89, 78, 65, 51, 46, 197)}};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__71 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__71_value;
static const lean_string_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__72_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 65, .m_capacity = 65, .m_length = 64, .m_data = "the complex mgf is 0 where the exponential moment does not exist"};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__72 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__72_value;
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__73_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__71_value),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__72_value)}};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__73 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__73_value;
static const lean_string_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__74_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 25, .m_capacity = 25, .m_length = 24, .m_data = "tilted_of_not_integrable"};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__74 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__74_value;
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__75_value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__0_value),LEAN_SCALAR_PTR_LITERAL(15, 237, 169, 28, 227, 202, 14, 52)}};
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__75_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__75_value_aux_0),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__74_value),LEAN_SCALAR_PTR_LITERAL(134, 12, 176, 216, 171, 72, 118, 171)}};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__75 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__75_value;
static const lean_string_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__76_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 120, .m_capacity = 120, .m_length = 119, .m_data = "an exponentially tilted measure is the zero measure when the tilt is not integrable, so it is not a probability measure"};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__76 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__76_value;
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__77_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__75_value),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__76_value)}};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__77 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__77_value;
static const lean_string_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__78_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "Measure"};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__78 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__78_value;
static const lean_string_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__79_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 12, .m_capacity = 12, .m_length = 11, .m_data = "comap_undef"};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__79 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__79_value;
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__80_value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__0_value),LEAN_SCALAR_PTR_LITERAL(15, 237, 169, 28, 227, 202, 14, 52)}};
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__80_value_aux_1 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__80_value_aux_0),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__78_value),LEAN_SCALAR_PTR_LITERAL(80, 200, 141, 223, 2, 210, 14, 17)}};
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__80_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__80_value_aux_1),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__79_value),LEAN_SCALAR_PTR_LITERAL(221, 167, 146, 22, 255, 245, 157, 0)}};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__80 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__80_value;
static const lean_string_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__81_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 99, .m_capacity = 99, .m_length = 98, .m_data = "the comap of a measure along a map that is not injective-with-measurable-image is the zero measure"};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__81 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__81_value;
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__82_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__80_value),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__81_value)}};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__82 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__82_value;
static const lean_string_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__83_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 18, .m_capacity = 18, .m_length = 17, .m_data = "InformationTheory"};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__83 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__83_value;
static const lean_string_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__84_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 24, .m_capacity = 24, .m_length = 23, .m_data = "klDiv_of_not_integrable"};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__84 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__84_value;
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__85_value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__83_value),LEAN_SCALAR_PTR_LITERAL(163, 56, 156, 133, 70, 7, 100, 29)}};
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__85_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__85_value_aux_0),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__84_value),LEAN_SCALAR_PTR_LITERAL(29, 148, 150, 28, 248, 109, 201, 129)}};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__85 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__85_value;
static const lean_string_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__86_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 207, .m_capacity = 207, .m_length = 202, .m_data = "the KL divergence is ⊤ when the log-likelihood ratio is not integrable — unlike the other entries here this default is the conservative direction, and a bound proved against it may still be worth having"};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__86 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__86_value;
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__87_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__85_value),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__86_value)}};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__87 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__87_value;
static const lean_string_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__88_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "Real"};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__88 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__88_value;
static const lean_string_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__89_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 23, .m_capacity = 23, .m_length = 22, .m_data = "sqrt_eq_zero_of_nonpos"};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__89 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__89_value;
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__90_value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__88_value),LEAN_SCALAR_PTR_LITERAL(70, 97, 13, 185, 175, 95, 64, 15)}};
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__90_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__90_value_aux_0),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__89_value),LEAN_SCALAR_PTR_LITERAL(192, 201, 162, 9, 112, 59, 243, 72)}};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__90 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__90_value;
static const lean_string_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__91_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 64, .m_capacity = 64, .m_length = 61, .m_data = "the square root of a non-positive real is 0, which is also √0"};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__91 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__91_value;
static const lean_ctor_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__92_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__90_value),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__91_value)}};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__92 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__92_value;
static const lean_array_object lp_JunkValues_JunkValues_mathlibCatalogue___closed__93_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*22, .m_other = 0, .m_tag = 246}, .m_size = 22, .m_capacity = 22, .m_data = {((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__4_value),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__8_value),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__12_value),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__16_value),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__20_value),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__24_value),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__29_value),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__33_value),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__37_value),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__41_value),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__45_value),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__49_value),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__53_value),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__57_value),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__61_value),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__65_value),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__69_value),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__73_value),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__77_value),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__82_value),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__87_value),((lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__92_value)}};
static const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue___closed__93 = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__93_value;
LEAN_EXPORT const lean_object* lp_JunkValues_JunkValues_mathlibCatalogue = (const lean_object*)&lp_JunkValues_JunkValues_mathlibCatalogue___closed__93_value;
LEAN_EXPORT lean_object* lp_JunkValues_Nat_cast___at___00JunkValues_instReprCatalogueEntry_repr_spec__0(lean_object* v_a_1_){
_start:
{
lean_object* v___x_2_; 
v___x_2_ = lean_nat_to_int(v_a_1_);
return v___x_2_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__7(void){
_start:
{
lean_object* v___x_16_; lean_object* v___x_17_; 
v___x_16_ = lean_unsigned_to_nat(15u);
v___x_17_ = lean_nat_to_int(v___x_16_);
return v___x_17_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__12(void){
_start:
{
lean_object* v___x_24_; lean_object* v___x_25_; 
v___x_24_ = lean_unsigned_to_nat(8u);
v___x_25_ = lean_nat_to_int(v___x_24_);
return v___x_25_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__14(void){
_start:
{
lean_object* v___x_27_; lean_object* v___x_28_; 
v___x_27_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__0));
v___x_28_ = lean_string_length(v___x_27_);
return v___x_28_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__15(void){
_start:
{
lean_object* v___x_29_; lean_object* v___x_30_; 
v___x_29_ = lean_obj_once(&lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__14, &lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__14_once, _init_lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__14);
v___x_30_ = lean_nat_to_int(v___x_29_);
return v___x_30_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg(lean_object* v_x_35_){
_start:
{
lean_object* v_theoremName_36_; lean_object* v_note_37_; lean_object* v___x_39_; uint8_t v_isShared_40_; uint8_t v_isSharedCheck_72_; 
v_theoremName_36_ = lean_ctor_get(v_x_35_, 0);
v_note_37_ = lean_ctor_get(v_x_35_, 1);
v_isSharedCheck_72_ = !lean_is_exclusive(v_x_35_);
if (v_isSharedCheck_72_ == 0)
{
v___x_39_ = v_x_35_;
v_isShared_40_ = v_isSharedCheck_72_;
goto v_resetjp_38_;
}
else
{
lean_inc(v_note_37_);
lean_inc(v_theoremName_36_);
lean_dec(v_x_35_);
v___x_39_ = lean_box(0);
v_isShared_40_ = v_isSharedCheck_72_;
goto v_resetjp_38_;
}
v_resetjp_38_:
{
lean_object* v___x_41_; lean_object* v___x_42_; lean_object* v___x_43_; lean_object* v___x_44_; lean_object* v___x_45_; lean_object* v___x_47_; 
v___x_41_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__5));
v___x_42_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__6));
v___x_43_ = lean_obj_once(&lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__7, &lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__7_once, _init_lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__7);
v___x_44_ = lean_unsigned_to_nat(0u);
v___x_45_ = l_Lean_Name_reprPrec(v_theoremName_36_, v___x_44_);
if (v_isShared_40_ == 0)
{
lean_ctor_set_tag(v___x_39_, 4);
lean_ctor_set(v___x_39_, 1, v___x_45_);
lean_ctor_set(v___x_39_, 0, v___x_43_);
v___x_47_ = v___x_39_;
goto v_reusejp_46_;
}
else
{
lean_object* v_reuseFailAlloc_71_; 
v_reuseFailAlloc_71_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v_reuseFailAlloc_71_, 0, v___x_43_);
lean_ctor_set(v_reuseFailAlloc_71_, 1, v___x_45_);
v___x_47_ = v_reuseFailAlloc_71_;
goto v_reusejp_46_;
}
v_reusejp_46_:
{
uint8_t v___x_48_; lean_object* v___x_49_; lean_object* v___x_50_; lean_object* v___x_51_; lean_object* v___x_52_; lean_object* v___x_53_; lean_object* v___x_54_; lean_object* v___x_55_; lean_object* v___x_56_; lean_object* v___x_57_; lean_object* v___x_58_; lean_object* v___x_59_; lean_object* v___x_60_; lean_object* v___x_61_; lean_object* v___x_62_; lean_object* v___x_63_; lean_object* v___x_64_; lean_object* v___x_65_; lean_object* v___x_66_; lean_object* v___x_67_; lean_object* v___x_68_; lean_object* v___x_69_; lean_object* v___x_70_; 
v___x_48_ = 0;
v___x_49_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_49_, 0, v___x_47_);
lean_ctor_set_uint8(v___x_49_, sizeof(void*)*1, v___x_48_);
v___x_50_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_50_, 0, v___x_42_);
lean_ctor_set(v___x_50_, 1, v___x_49_);
v___x_51_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__9));
v___x_52_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_52_, 0, v___x_50_);
lean_ctor_set(v___x_52_, 1, v___x_51_);
v___x_53_ = lean_box(1);
v___x_54_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_54_, 0, v___x_52_);
lean_ctor_set(v___x_54_, 1, v___x_53_);
v___x_55_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__11));
v___x_56_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_56_, 0, v___x_54_);
lean_ctor_set(v___x_56_, 1, v___x_55_);
v___x_57_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_57_, 0, v___x_56_);
lean_ctor_set(v___x_57_, 1, v___x_41_);
v___x_58_ = lean_obj_once(&lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__12, &lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__12_once, _init_lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__12);
v___x_59_ = l_String_quote(v_note_37_);
v___x_60_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_60_, 0, v___x_59_);
v___x_61_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_61_, 0, v___x_58_);
lean_ctor_set(v___x_61_, 1, v___x_60_);
v___x_62_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_62_, 0, v___x_61_);
lean_ctor_set_uint8(v___x_62_, sizeof(void*)*1, v___x_48_);
v___x_63_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_63_, 0, v___x_57_);
lean_ctor_set(v___x_63_, 1, v___x_62_);
v___x_64_ = lean_obj_once(&lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__15, &lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__15_once, _init_lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__15);
v___x_65_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__16));
v___x_66_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_66_, 0, v___x_65_);
lean_ctor_set(v___x_66_, 1, v___x_63_);
v___x_67_ = ((lean_object*)(lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg___closed__17));
v___x_68_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_68_, 0, v___x_66_);
lean_ctor_set(v___x_68_, 1, v___x_67_);
v___x_69_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_69_, 0, v___x_64_);
lean_ctor_set(v___x_69_, 1, v___x_68_);
v___x_70_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_70_, 0, v___x_69_);
lean_ctor_set_uint8(v___x_70_, sizeof(void*)*1, v___x_48_);
return v___x_70_;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instReprCatalogueEntry_repr(lean_object* v_x_73_, lean_object* v_prec_74_){
_start:
{
lean_object* v___x_75_; 
v___x_75_ = lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___redArg(v_x_73_);
return v___x_75_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instReprCatalogueEntry_repr___boxed(lean_object* v_x_76_, lean_object* v_prec_77_){
_start:
{
lean_object* v_res_78_; 
v_res_78_ = lp_JunkValues_JunkValues_instReprCatalogueEntry_repr(v_x_76_, v_prec_77_);
lean_dec(v_prec_77_);
return v_res_78_;
}
}
LEAN_EXPORT uint8_t lp_JunkValues_JunkValues_instBEqCatalogueEntry_beq(lean_object* v_x_87_, lean_object* v_x_88_){
_start:
{
lean_object* v_theoremName_89_; lean_object* v_note_90_; lean_object* v_theoremName_91_; lean_object* v_note_92_; uint8_t v___x_93_; 
v_theoremName_89_ = lean_ctor_get(v_x_87_, 0);
v_note_90_ = lean_ctor_get(v_x_87_, 1);
v_theoremName_91_ = lean_ctor_get(v_x_88_, 0);
v_note_92_ = lean_ctor_get(v_x_88_, 1);
v___x_93_ = lean_name_eq(v_theoremName_89_, v_theoremName_91_);
if (v___x_93_ == 0)
{
return v___x_93_;
}
else
{
uint8_t v___x_94_; 
v___x_94_ = lean_string_dec_eq(v_note_90_, v_note_92_);
return v___x_94_;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instBEqCatalogueEntry_beq___boxed(lean_object* v_x_95_, lean_object* v_x_96_){
_start:
{
uint8_t v_res_97_; lean_object* v_r_98_; 
v_res_97_ = lp_JunkValues_JunkValues_instBEqCatalogueEntry_beq(v_x_95_, v_x_96_);
lean_dec_ref(v_x_96_);
lean_dec_ref(v_x_95_);
v_r_98_ = lean_box(v_res_97_);
return v_r_98_;
}
}
lean_object* runtime_initialize_Init(uint8_t builtin);
lean_object* runtime_initialize_Lean(uint8_t builtin);
static bool _G_runtime_initialized = false;
LEAN_EXPORT lean_object* runtime_initialize_JunkValues_JunkValues_Catalogue(uint8_t builtin) {
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
LEAN_EXPORT lean_object* meta_initialize_JunkValues_JunkValues_Catalogue(uint8_t builtin) {
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
LEAN_EXPORT lean_object* initialize_JunkValues_JunkValues_Catalogue(uint8_t builtin) {
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
res = runtime_initialize_JunkValues_JunkValues_Catalogue(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = meta_initialize_JunkValues_JunkValues_Catalogue(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return initialize_JunkValues_JunkValues_Catalogue(builtin);
}
#ifdef __cplusplus
}
#endif
