// Lean compiler output
// Module: JunkValues.Registry
// Imports: public import Init public meta import Init public import JunkValues.Rule
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
lean_object* l_Lean_Name_str___override(lean_object*, lean_object*);
lean_object* l_Lean_Name_num___override(lean_object*, lean_object*);
lean_object* l_Lean_stringToMessageData(lean_object*);
lean_object* l_Lean_Name_mkStr1(lean_object*);
lean_object* l_Lean_MessageData_ofName(lean_object*);
lean_object* lean_st_ref_get(lean_object*);
lean_object* l_Lean_PersistentHashMap_mkEmptyEntriesArray(lean_object*, lean_object*);
lean_object* lean_mk_empty_array_with_capacity(lean_object*);
lean_object* lean_st_ref_take(lean_object*);
lean_object* lean_array_mk(lean_object*);
lean_object* lean_mk_empty_array_with_capacity(lean_object*);
lean_object* lean_array_get_size(lean_object*);
uint8_t lean_nat_dec_lt(lean_object*, lean_object*);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
size_t lean_usize_of_nat(lean_object*);
uint8_t lean_usize_dec_eq(size_t, size_t);
lean_object* lean_array_uget_borrowed(lean_object*, size_t);
lean_object* l_Array_append___redArg(lean_object*, lean_object*);
size_t lean_usize_add(size_t, size_t);
lean_object* l_Array_push___boxed(lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_Name_mkStr2(lean_object*, lean_object*);
lean_object* l_Lean_registerSimplePersistentEnvExtension___redArg(lean_object*);
lean_object* l_Lean_PersistentEnvExtension_addEntry___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* lean_st_ref_set(lean_object*, lean_object*);
uint64_t l___private_Lean_Meta_Basic_0__Lean_Meta_Config_toKey(lean_object*);
lean_object* lean_st_mk_ref(lean_object*);
lean_object* lp_JunkValues_JunkValues_ruleOfTheorem_x3f(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_TSyntax_getString(lean_object*);
lean_object* l_Lean_Environment_getModuleIdxFor_x3f(lean_object*, lean_object*);
size_t lean_array_size(lean_object*);
uint8_t lean_usize_dec_lt(size_t, size_t);
lean_object* lean_array_uget(lean_object*, size_t);
lean_object* lean_array_uset(lean_object*, size_t, lean_object*);
lean_object* l_Lean_TSyntax_getNat(lean_object*);
lean_object* l_Lean_Syntax_getArg(lean_object*, lean_object*);
uint8_t l_Lean_Syntax_isNone(lean_object*);
uint8_t l_Lean_Syntax_matchesNull(lean_object*, lean_object*);
lean_object* l_Lean_Syntax_getKind(lean_object*);
lean_object* l_Lean_Name_mkStr4(lean_object*, lean_object*, lean_object*, lean_object*);
uint8_t lean_name_eq(lean_object*, lean_object*);
uint8_t l_Lean_Syntax_isOfKind(lean_object*, lean_object*);
lean_object* l_Lean_Syntax_getArgs(lean_object*);
uint8_t l_Lean_instBEqAttributeKind_beq(uint8_t, uint8_t);
lean_object* l_Lean_registerBuiltinAttribute(lean_object*);
lean_object* l_Array_instInhabited(lean_object*);
lean_object* l_Lean_SimplePersistentEnvExtension_getState___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2__spec__0(lean_object*, size_t, size_t, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2__spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_array_object lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__0_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__0_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__0_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2__value;
LEAN_EXPORT lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2_(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2____boxed(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__1_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2_(lean_object*);
static const lean_closure_object lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__0_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2____boxed, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__0_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__0_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2__value;
static const lean_closure_object lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__1_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__1_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2_, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__1_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__1_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2__value;
static const lean_string_object lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__2_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "JunkValues"};
static const lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__2_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__2_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2__value;
static const lean_string_object lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__3_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "junkExt"};
static const lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__3_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__3_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2__value;
static const lean_ctor_object lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__4_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2__value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__2_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2__value),LEAN_SCALAR_PTR_LITERAL(102, 249, 254, 203, 87, 211, 22, 147)}};
static const lean_ctor_object lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__4_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__4_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2__value_aux_0),((lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__3_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2__value),LEAN_SCALAR_PTR_LITERAL(169, 44, 222, 227, 160, 245, 169, 214)}};
static const lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__4_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__4_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2__value;
static const lean_closure_object lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__5_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*1, .m_other = 0, .m_tag = 245}, .m_fun = (void*)l_Array_push___boxed, .m_arity = 3, .m_num_fixed = 1, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1))} };
static const lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__5_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__5_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2__value;
static const lean_ctor_object lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__6_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*7 + 0, .m_other = 7, .m_tag = 0}, .m_objs = {((lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__4_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2__value),((lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__5_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2__value),((lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__0_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2__value),((lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__1_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2__value),((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)(((size_t)(2) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__6_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__6_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2__value;
LEAN_EXPORT lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2_();
LEAN_EXPORT lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2____boxed(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_junkExt;
static lean_once_cell_t lp_JunkValues_JunkValues_declaredRules___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_declaredRules___closed__0;
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_declaredRules(lean_object*);
static const lean_string_object lp_JunkValues_JunkValues_junkValue___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 10, .m_capacity = 10, .m_length = 9, .m_data = "junkValue"};
static const lean_object* lp_JunkValues_JunkValues_junkValue___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__0_value;
static const lean_ctor_object lp_JunkValues_JunkValues_junkValue___closed__1_value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__2_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2__value),LEAN_SCALAR_PTR_LITERAL(102, 249, 254, 203, 87, 211, 22, 147)}};
static const lean_ctor_object lp_JunkValues_JunkValues_junkValue___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__1_value_aux_0),((lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__0_value),LEAN_SCALAR_PTR_LITERAL(215, 177, 236, 42, 114, 200, 153, 204)}};
static const lean_object* lp_JunkValues_JunkValues_junkValue___closed__1 = (const lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__1_value;
static const lean_string_object lp_JunkValues_JunkValues_junkValue___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "andthen"};
static const lean_object* lp_JunkValues_JunkValues_junkValue___closed__2 = (const lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__2_value;
static const lean_ctor_object lp_JunkValues_JunkValues_junkValue___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__2_value),LEAN_SCALAR_PTR_LITERAL(40, 255, 78, 30, 143, 119, 117, 174)}};
static const lean_object* lp_JunkValues_JunkValues_junkValue___closed__3 = (const lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__3_value;
static const lean_string_object lp_JunkValues_JunkValues_junkValue___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "junk_value"};
static const lean_object* lp_JunkValues_JunkValues_junkValue___closed__4 = (const lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__4_value;
static const lean_ctor_object lp_JunkValues_JunkValues_junkValue___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 8, .m_other = 1, .m_tag = 6}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__4_value),LEAN_SCALAR_PTR_LITERAL(0, 0, 0, 0, 0, 0, 0, 0)}};
static const lean_object* lp_JunkValues_JunkValues_junkValue___closed__5 = (const lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__5_value;
static const lean_string_object lp_JunkValues_JunkValues_junkValue___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "optional"};
static const lean_object* lp_JunkValues_JunkValues_junkValue___closed__6 = (const lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__6_value;
static const lean_ctor_object lp_JunkValues_JunkValues_junkValue___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__6_value),LEAN_SCALAR_PTR_LITERAL(233, 141, 154, 50, 143, 135, 42, 252)}};
static const lean_object* lp_JunkValues_JunkValues_junkValue___closed__7 = (const lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__7_value;
static const lean_string_object lp_JunkValues_JunkValues_junkValue___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "ppSpace"};
static const lean_object* lp_JunkValues_JunkValues_junkValue___closed__8 = (const lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__8_value;
static const lean_ctor_object lp_JunkValues_JunkValues_junkValue___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__8_value),LEAN_SCALAR_PTR_LITERAL(207, 47, 58, 43, 30, 240, 125, 246)}};
static const lean_object* lp_JunkValues_JunkValues_junkValue___closed__9 = (const lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__9_value;
static const lean_ctor_object lp_JunkValues_JunkValues_junkValue___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 0}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__9_value)}};
static const lean_object* lp_JunkValues_JunkValues_junkValue___closed__10 = (const lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__10_value;
static const lean_string_object lp_JunkValues_JunkValues_junkValue___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 13, .m_capacity = 13, .m_length = 12, .m_data = "generalizing"};
static const lean_object* lp_JunkValues_JunkValues_junkValue___closed__11 = (const lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__11_value;
static const lean_ctor_object lp_JunkValues_JunkValues_junkValue___closed__12_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 8, .m_other = 1, .m_tag = 6}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__11_value),LEAN_SCALAR_PTR_LITERAL(0, 0, 0, 0, 0, 0, 0, 0)}};
static const lean_object* lp_JunkValues_JunkValues_junkValue___closed__12 = (const lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__12_value;
static const lean_ctor_object lp_JunkValues_JunkValues_junkValue___closed__13_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*3 + 0, .m_other = 3, .m_tag = 2}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__3_value),((lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__10_value),((lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__12_value)}};
static const lean_object* lp_JunkValues_JunkValues_junkValue___closed__13 = (const lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__13_value;
static const lean_string_object lp_JunkValues_JunkValues_junkValue___closed__14_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "many1"};
static const lean_object* lp_JunkValues_JunkValues_junkValue___closed__14 = (const lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__14_value;
static const lean_ctor_object lp_JunkValues_JunkValues_junkValue___closed__15_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__14_value),LEAN_SCALAR_PTR_LITERAL(55, 136, 52, 6, 12, 19, 78, 239)}};
static const lean_object* lp_JunkValues_JunkValues_junkValue___closed__15 = (const lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__15_value;
static const lean_string_object lp_JunkValues_JunkValues_junkValue___closed__16_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "num"};
static const lean_object* lp_JunkValues_JunkValues_junkValue___closed__16 = (const lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__16_value;
static const lean_ctor_object lp_JunkValues_JunkValues_junkValue___closed__17_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__16_value),LEAN_SCALAR_PTR_LITERAL(227, 68, 22, 222, 47, 51, 204, 84)}};
static const lean_object* lp_JunkValues_JunkValues_junkValue___closed__17 = (const lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__17_value;
static const lean_ctor_object lp_JunkValues_JunkValues_junkValue___closed__18_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 0}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__17_value)}};
static const lean_object* lp_JunkValues_JunkValues_junkValue___closed__18 = (const lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__18_value;
static const lean_ctor_object lp_JunkValues_JunkValues_junkValue___closed__19_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*3 + 0, .m_other = 3, .m_tag = 2}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__3_value),((lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__10_value),((lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__18_value)}};
static const lean_object* lp_JunkValues_JunkValues_junkValue___closed__19 = (const lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__19_value;
static const lean_ctor_object lp_JunkValues_JunkValues_junkValue___closed__20_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__15_value),((lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__19_value)}};
static const lean_object* lp_JunkValues_JunkValues_junkValue___closed__20 = (const lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__20_value;
static const lean_ctor_object lp_JunkValues_JunkValues_junkValue___closed__21_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*3 + 0, .m_other = 3, .m_tag = 2}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__3_value),((lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__13_value),((lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__20_value)}};
static const lean_object* lp_JunkValues_JunkValues_junkValue___closed__21 = (const lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__21_value;
static const lean_ctor_object lp_JunkValues_JunkValues_junkValue___closed__22_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__7_value),((lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__21_value)}};
static const lean_object* lp_JunkValues_JunkValues_junkValue___closed__22 = (const lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__22_value;
static const lean_ctor_object lp_JunkValues_JunkValues_junkValue___closed__23_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*3 + 0, .m_other = 3, .m_tag = 2}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__3_value),((lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__5_value),((lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__22_value)}};
static const lean_object* lp_JunkValues_JunkValues_junkValue___closed__23 = (const lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__23_value;
static const lean_string_object lp_JunkValues_JunkValues_junkValue___closed__24_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "str"};
static const lean_object* lp_JunkValues_JunkValues_junkValue___closed__24 = (const lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__24_value;
static const lean_ctor_object lp_JunkValues_JunkValues_junkValue___closed__25_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__24_value),LEAN_SCALAR_PTR_LITERAL(255, 188, 142, 1, 190, 33, 34, 128)}};
static const lean_object* lp_JunkValues_JunkValues_junkValue___closed__25 = (const lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__25_value;
static const lean_ctor_object lp_JunkValues_JunkValues_junkValue___closed__26_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 0}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__25_value)}};
static const lean_object* lp_JunkValues_JunkValues_junkValue___closed__26 = (const lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__26_value;
static const lean_ctor_object lp_JunkValues_JunkValues_junkValue___closed__27_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*3 + 0, .m_other = 3, .m_tag = 2}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__3_value),((lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__10_value),((lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__26_value)}};
static const lean_object* lp_JunkValues_JunkValues_junkValue___closed__27 = (const lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__27_value;
static const lean_ctor_object lp_JunkValues_JunkValues_junkValue___closed__28_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__7_value),((lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__27_value)}};
static const lean_object* lp_JunkValues_JunkValues_junkValue___closed__28 = (const lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__28_value;
static const lean_ctor_object lp_JunkValues_JunkValues_junkValue___closed__29_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*3 + 0, .m_other = 3, .m_tag = 2}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__3_value),((lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__23_value),((lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__28_value)}};
static const lean_object* lp_JunkValues_JunkValues_junkValue___closed__29 = (const lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__29_value;
static const lean_ctor_object lp_JunkValues_JunkValues_junkValue___closed__30_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*3 + 0, .m_other = 3, .m_tag = 3}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__1_value),((lean_object*)(((size_t)(1022) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__29_value)}};
static const lean_object* lp_JunkValues_JunkValues_junkValue___closed__30 = (const lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__30_value;
LEAN_EXPORT const lean_object* lp_JunkValues_JunkValues_junkValue = (const lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__30_value;
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__1(size_t, size_t, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__1___boxed(lean_object*, lean_object*, lean_object*);
static lean_once_cell_t lp_JunkValues_Lean_addMessageContextPartial___at___00Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0_spec__0___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_Lean_addMessageContextPartial___at___00Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0_spec__0___closed__0;
static lean_once_cell_t lp_JunkValues_Lean_addMessageContextPartial___at___00Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0_spec__0___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_Lean_addMessageContextPartial___at___00Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0_spec__0___closed__1;
static lean_once_cell_t lp_JunkValues_Lean_addMessageContextPartial___at___00Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0_spec__0___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_Lean_addMessageContextPartial___at___00Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0_spec__0___closed__2;
static lean_once_cell_t lp_JunkValues_Lean_addMessageContextPartial___at___00Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0_spec__0___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_Lean_addMessageContextPartial___at___00Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0_spec__0___closed__3;
static lean_once_cell_t lp_JunkValues_Lean_addMessageContextPartial___at___00Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0_spec__0___closed__4_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_Lean_addMessageContextPartial___at___00Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0_spec__0___closed__4;
static lean_once_cell_t lp_JunkValues_Lean_addMessageContextPartial___at___00Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0_spec__0___closed__5_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_Lean_addMessageContextPartial___at___00Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0_spec__0___closed__5;
LEAN_EXPORT lean_object* lp_JunkValues_Lean_addMessageContextPartial___at___00Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0_spec__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_addMessageContextPartial___at___00Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__2(size_t, size_t, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__2___boxed(lean_object*, lean_object*, lean_object*);
static const lean_string_object lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__0_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 2, .m_capacity = 2, .m_length = 1, .m_data = "`"};
static const lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__0_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__0_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value;
static lean_once_cell_t lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__1_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__1_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_;
static const lean_string_object lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__2_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 32, .m_capacity = 32, .m_length = 31, .m_data = "` cannot be a junk-value rule: "};
static const lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__2_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__2_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value;
static lean_once_cell_t lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__3_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__3_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_;
static lean_once_cell_t lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__4_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__4_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_;
static lean_once_cell_t lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__5_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__5_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_;
static lean_once_cell_t lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__6_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__6_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_;
static const lean_ctor_object lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__7_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*0 + 24, .m_other = 0, .m_tag = 0}, .m_objs = {LEAN_SCALAR_PTR_LITERAL(0, 0, 0, 0, 0, 1, 1, 0),LEAN_SCALAR_PTR_LITERAL(1, 1, 0, 1, 1, 1, 2, 1),LEAN_SCALAR_PTR_LITERAL(1, 1, 1, 0, 0, 0, 0, 0)}};
static const lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__7_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__7_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value;
static lean_once_cell_t lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__8_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__once = LEAN_ONCE_CELL_INITIALIZER;
static uint64_t lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__8_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_;
static lean_once_cell_t lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__9_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__9_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_;
static lean_once_cell_t lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__10_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__10_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_;
static lean_once_cell_t lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__11_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__11_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_;
static lean_once_cell_t lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__12_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__12_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_;
static lean_once_cell_t lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__13_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__13_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_;
static const lean_string_object lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__14_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 1, .m_capacity = 1, .m_length = 0, .m_data = ""};
static const lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__14_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__14_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value;
static const lean_string_object lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__15_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 31, .m_capacity = 31, .m_length = 30, .m_data = "cannot apply `junk_value` to `"};
static const lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__15_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__15_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value;
static lean_once_cell_t lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__16_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__16_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_;
static const lean_string_object lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__17_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 139, .m_capacity = 139, .m_length = 138, .m_data = "`, which is declared in an imported module: the annotation would not be recorded in this module's `.olean`. Name it in a catalogue instead"};
static const lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__17_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__17_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value;
static lean_once_cell_t lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__18_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__18_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_;
static const lean_string_object lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__19_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 104, .m_capacity = 104, .m_length = 103, .m_data = "invalid `junk_value` attribute, expected `@[junk_value generalizing 2 \"why\"]`, with both parts optional"};
static const lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__19_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__19_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value;
static lean_once_cell_t lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__20_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__20_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_;
static const lean_string_object lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__21_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "Lean"};
static const lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__21_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__21_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value;
static const lean_string_object lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__22_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "Parser"};
static const lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__22_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__22_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value;
static const lean_string_object lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__23_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "Attr"};
static const lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__23_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__23_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value;
static const lean_string_object lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__24_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "simple"};
static const lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__24_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__24_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value;
static const lean_ctor_object lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__25_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__21_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value),LEAN_SCALAR_PTR_LITERAL(70, 193, 83, 126, 233, 67, 208, 165)}};
static const lean_ctor_object lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__25_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value_aux_1 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__25_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value_aux_0),((lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__22_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value),LEAN_SCALAR_PTR_LITERAL(103, 136, 125, 166, 167, 98, 71, 111)}};
static const lean_ctor_object lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__25_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value_aux_2 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__25_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value_aux_1),((lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__23_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value),LEAN_SCALAR_PTR_LITERAL(7, 175, 252, 195, 22, 42, 161, 63)}};
static const lean_ctor_object lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__25_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__25_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value_aux_2),((lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__24_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value),LEAN_SCALAR_PTR_LITERAL(107, 67, 254, 234, 65, 174, 209, 53)}};
static const lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__25_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__25_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value;
static const lean_string_object lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__26_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 116, .m_capacity = 116, .m_length = 115, .m_data = "`junk_value` must be a global attribute: it records a fact about the definition, not about a section or a namespace"};
static const lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__26_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__26_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value;
static lean_once_cell_t lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__27_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__27_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_;
LEAN_EXPORT lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2____boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__1___closed__0_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 13, .m_capacity = 13, .m_length = 12, .m_data = "Attribute `["};
static const lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__1___closed__0_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__1___closed__0_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value;
static lean_once_cell_t lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__1___closed__1_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__1___closed__1_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_;
static const lean_string_object lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__1___closed__2_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 20, .m_capacity = 20, .m_length = 19, .m_data = "]` cannot be erased"};
static const lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__1___closed__2_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__1___closed__2_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value;
static lean_once_cell_t lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__1___closed__3_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__1___closed__3_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_;
LEAN_EXPORT lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__1_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__1_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2____boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__0_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "_private"};
static const lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__0_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__0_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value;
static const lean_ctor_object lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__1_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__0_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value),LEAN_SCALAR_PTR_LITERAL(103, 214, 75, 80, 34, 198, 193, 153)}};
static const lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__1_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__1_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value;
static const lean_ctor_object lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__2_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__1_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value),((lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__2_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2__value),LEAN_SCALAR_PTR_LITERAL(250, 116, 176, 33, 27, 39, 144, 172)}};
static const lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__2_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__2_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value;
static const lean_string_object lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__3_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "Registry"};
static const lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__3_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__3_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value;
static const lean_ctor_object lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__4_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__2_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value),((lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__3_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value),LEAN_SCALAR_PTR_LITERAL(105, 25, 186, 3, 201, 50, 190, 32)}};
static const lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__4_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__4_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value;
static const lean_ctor_object lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__5_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 2}, .m_objs = {((lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__4_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value),((lean_object*)(((size_t)(0) << 1) | 1)),LEAN_SCALAR_PTR_LITERAL(172, 158, 228, 6, 141, 123, 56, 165)}};
static const lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__5_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__5_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value;
static const lean_ctor_object lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__6_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__5_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value),((lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__2_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2__value),LEAN_SCALAR_PTR_LITERAL(205, 218, 181, 223, 64, 220, 24, 101)}};
static const lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__6_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__6_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value;
static const lean_string_object lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__7_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "initFn"};
static const lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__7_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__7_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value;
static const lean_ctor_object lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__8_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__6_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value),((lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__7_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value),LEAN_SCALAR_PTR_LITERAL(36, 226, 130, 163, 213, 170, 11, 118)}};
static const lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__8_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__8_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value;
static const lean_string_object lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__9_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "_@"};
static const lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__9_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__9_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value;
static const lean_ctor_object lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__10_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__8_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value),((lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__9_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value),LEAN_SCALAR_PTR_LITERAL(45, 137, 193, 52, 238, 120, 69, 229)}};
static const lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__10_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__10_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value;
static const lean_ctor_object lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__11_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__10_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value),((lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__2_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2__value),LEAN_SCALAR_PTR_LITERAL(184, 34, 89, 117, 228, 189, 165, 70)}};
static const lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__11_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__11_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value;
static const lean_ctor_object lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__12_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__11_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value),((lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__3_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value),LEAN_SCALAR_PTR_LITERAL(211, 11, 93, 30, 131, 116, 60, 14)}};
static const lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__12_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__12_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value;
static const lean_ctor_object lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__13_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 2}, .m_objs = {((lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__12_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value),((lean_object*)(((size_t)(1664979221) << 1) | 1)),LEAN_SCALAR_PTR_LITERAL(29, 196, 148, 209, 180, 92, 89, 85)}};
static const lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__13_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__13_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value;
static const lean_string_object lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__14_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "_hygCtx"};
static const lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__14_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__14_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value;
static const lean_ctor_object lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__15_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__13_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value),((lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__14_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value),LEAN_SCALAR_PTR_LITERAL(158, 104, 18, 24, 130, 50, 152, 252)}};
static const lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__15_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__15_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value;
static const lean_string_object lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__16_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "_hyg"};
static const lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__16_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__16_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value;
static const lean_ctor_object lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__17_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__15_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value),((lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__16_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value),LEAN_SCALAR_PTR_LITERAL(146, 236, 105, 131, 223, 18, 85, 192)}};
static const lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__17_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__17_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value;
static const lean_ctor_object lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__18_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 2}, .m_objs = {((lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__17_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value),((lean_object*)(((size_t)(2) << 1) | 1)),LEAN_SCALAR_PTR_LITERAL(43, 2, 226, 27, 104, 5, 72, 33)}};
static const lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__18_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__18_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value;
static const lean_closure_object lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__19_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*5, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2____boxed, .m_arity = 11, .m_num_fixed = 5, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)(((size_t)(1) << 1) | 1)),((lean_object*)(((size_t)(2) << 1) | 1)),((lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__2_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2__value),((lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__0_value)} };
static const lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__19_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__19_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value;
static const lean_ctor_object lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__20_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_junkValue___closed__0_value),LEAN_SCALAR_PTR_LITERAL(94, 106, 141, 37, 13, 33, 90, 153)}};
static const lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__20_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__20_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value;
static const lean_closure_object lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__21_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*1, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__1_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2____boxed, .m_arity = 5, .m_num_fixed = 1, .m_objs = {((lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__20_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value)} };
static const lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__21_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__21_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value;
static const lean_string_object lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__22_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 106, .m_capacity = 106, .m_length = 105, .m_data = "mark this theorem as exhibiting a junk value: a condition under which an operation collapses to a default"};
static const lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__22_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__22_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value;
static const lean_ctor_object lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__23_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*3 + 8, .m_other = 3, .m_tag = 0}, .m_objs = {((lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__18_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value),((lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__20_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value),((lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__22_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value),LEAN_SCALAR_PTR_LITERAL(0, 0, 0, 0, 0, 0, 0, 0)}};
static const lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__23_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__23_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value;
static const lean_ctor_object lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__24_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*3 + 0, .m_other = 3, .m_tag = 0}, .m_objs = {((lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__23_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value),((lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__19_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value),((lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__21_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value)}};
static const lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__24_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__24_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__value;
LEAN_EXPORT lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_();
LEAN_EXPORT lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2____boxed(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2__spec__0(lean_object* v_as_1_, size_t v_i_2_, size_t v_stop_3_, lean_object* v_b_4_){
_start:
{
uint8_t v___x_5_; 
v___x_5_ = lean_usize_dec_eq(v_i_2_, v_stop_3_);
if (v___x_5_ == 0)
{
lean_object* v___x_6_; lean_object* v___x_7_; size_t v___x_8_; size_t v___x_9_; 
v___x_6_ = lean_array_uget_borrowed(v_as_1_, v_i_2_);
v___x_7_ = l_Array_append___redArg(v_b_4_, v___x_6_);
v___x_8_ = ((size_t)1ULL);
v___x_9_ = lean_usize_add(v_i_2_, v___x_8_);
v_i_2_ = v___x_9_;
v_b_4_ = v___x_7_;
goto _start;
}
else
{
return v_b_4_;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2__spec__0___boxed(lean_object* v_as_11_, lean_object* v_i_12_, lean_object* v_stop_13_, lean_object* v_b_14_){
_start:
{
size_t v_i_boxed_15_; size_t v_stop_boxed_16_; lean_object* v_res_17_; 
v_i_boxed_15_ = lean_unbox_usize(v_i_12_);
lean_dec(v_i_12_);
v_stop_boxed_16_ = lean_unbox_usize(v_stop_13_);
lean_dec(v_stop_13_);
v_res_17_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2__spec__0(v_as_11_, v_i_boxed_15_, v_stop_boxed_16_, v_b_14_);
lean_dec_ref(v_as_11_);
return v_res_17_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2_(lean_object* v_entries_20_){
_start:
{
lean_object* v___x_21_; lean_object* v___x_22_; lean_object* v___x_23_; uint8_t v___x_24_; 
v___x_21_ = lean_unsigned_to_nat(0u);
v___x_22_ = ((lean_object*)(lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__0_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2_));
v___x_23_ = lean_array_get_size(v_entries_20_);
v___x_24_ = lean_nat_dec_lt(v___x_21_, v___x_23_);
if (v___x_24_ == 0)
{
return v___x_22_;
}
else
{
uint8_t v___x_25_; 
v___x_25_ = lean_nat_dec_le(v___x_23_, v___x_23_);
if (v___x_25_ == 0)
{
if (v___x_24_ == 0)
{
return v___x_22_;
}
else
{
size_t v___x_26_; size_t v___x_27_; lean_object* v___x_28_; 
v___x_26_ = ((size_t)0ULL);
v___x_27_ = lean_usize_of_nat(v___x_23_);
v___x_28_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2__spec__0(v_entries_20_, v___x_26_, v___x_27_, v___x_22_);
return v___x_28_;
}
}
else
{
size_t v___x_29_; size_t v___x_30_; lean_object* v___x_31_; 
v___x_29_ = ((size_t)0ULL);
v___x_30_ = lean_usize_of_nat(v___x_23_);
v___x_31_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2__spec__0(v_entries_20_, v___x_29_, v___x_30_, v___x_22_);
return v___x_31_;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2____boxed(lean_object* v_entries_32_){
_start:
{
lean_object* v_res_33_; 
v_res_33_ = lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2_(v_entries_32_);
lean_dec_ref(v_entries_32_);
return v_res_33_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__1_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2_(lean_object* v_es_34_){
_start:
{
lean_object* v___x_35_; 
v___x_35_ = lean_array_mk(v_es_34_);
return v___x_35_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2_(){
_start:
{
lean_object* v___x_52_; lean_object* v___x_53_; 
v___x_52_ = ((lean_object*)(lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__6_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2_));
v___x_53_ = l_Lean_registerSimplePersistentEnvExtension___redArg(v___x_52_);
return v___x_53_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2____boxed(lean_object* v_a_54_){
_start:
{
lean_object* v_res_55_; 
v_res_55_ = lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2_();
return v_res_55_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_declaredRules___closed__0(void){
_start:
{
lean_object* v___x_56_; 
v___x_56_ = l_Array_instInhabited(lean_box(0));
return v___x_56_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_declaredRules(lean_object* v_env_57_){
_start:
{
lean_object* v___x_58_; lean_object* v_toEnvExtension_59_; lean_object* v_asyncMode_60_; lean_object* v___x_61_; lean_object* v___x_62_; lean_object* v___x_63_; 
v___x_58_ = lp_JunkValues_JunkValues_junkExt;
v_toEnvExtension_59_ = lean_ctor_get(v___x_58_, 0);
v_asyncMode_60_ = lean_ctor_get(v_toEnvExtension_59_, 2);
v___x_61_ = lean_obj_once(&lp_JunkValues_JunkValues_declaredRules___closed__0, &lp_JunkValues_JunkValues_declaredRules___closed__0_once, _init_lp_JunkValues_JunkValues_declaredRules___closed__0);
v___x_62_ = lean_box(0);
v___x_63_ = l_Lean_SimplePersistentEnvExtension_getState___redArg(v___x_61_, v___x_58_, v_env_57_, v_asyncMode_60_, v___x_62_);
return v___x_63_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__1(size_t v_sz_138_, size_t v_i_139_, lean_object* v_bs_140_){
_start:
{
uint8_t v___x_141_; 
v___x_141_ = lean_usize_dec_lt(v_i_139_, v_sz_138_);
if (v___x_141_ == 0)
{
return v_bs_140_;
}
else
{
lean_object* v_v_142_; lean_object* v___x_143_; lean_object* v_bs_x27_144_; lean_object* v___x_145_; size_t v___x_146_; size_t v___x_147_; lean_object* v___x_148_; 
v_v_142_ = lean_array_uget(v_bs_140_, v_i_139_);
v___x_143_ = lean_unsigned_to_nat(0u);
v_bs_x27_144_ = lean_array_uset(v_bs_140_, v_i_139_, v___x_143_);
v___x_145_ = l_Lean_TSyntax_getNat(v_v_142_);
lean_dec(v_v_142_);
v___x_146_ = ((size_t)1ULL);
v___x_147_ = lean_usize_add(v_i_139_, v___x_146_);
v___x_148_ = lean_array_uset(v_bs_x27_144_, v_i_139_, v___x_145_);
v_i_139_ = v___x_147_;
v_bs_140_ = v___x_148_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__1___boxed(lean_object* v_sz_150_, lean_object* v_i_151_, lean_object* v_bs_152_){
_start:
{
size_t v_sz_boxed_153_; size_t v_i_boxed_154_; lean_object* v_res_155_; 
v_sz_boxed_153_ = lean_unbox_usize(v_sz_150_);
lean_dec(v_sz_150_);
v_i_boxed_154_ = lean_unbox_usize(v_i_151_);
lean_dec(v_i_151_);
v_res_155_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__1(v_sz_boxed_153_, v_i_boxed_154_, v_bs_152_);
return v_res_155_;
}
}
static lean_object* _init_lp_JunkValues_Lean_addMessageContextPartial___at___00Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0_spec__0___closed__0(void){
_start:
{
lean_object* v___x_156_; 
v___x_156_ = l_Lean_PersistentHashMap_mkEmptyEntriesArray(lean_box(0), lean_box(0));
return v___x_156_;
}
}
static lean_object* _init_lp_JunkValues_Lean_addMessageContextPartial___at___00Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0_spec__0___closed__1(void){
_start:
{
lean_object* v___x_157_; lean_object* v___x_158_; 
v___x_157_ = lean_obj_once(&lp_JunkValues_Lean_addMessageContextPartial___at___00Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0_spec__0___closed__0, &lp_JunkValues_Lean_addMessageContextPartial___at___00Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0_spec__0___closed__0_once, _init_lp_JunkValues_Lean_addMessageContextPartial___at___00Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0_spec__0___closed__0);
v___x_158_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_158_, 0, v___x_157_);
return v___x_158_;
}
}
static lean_object* _init_lp_JunkValues_Lean_addMessageContextPartial___at___00Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0_spec__0___closed__2(void){
_start:
{
lean_object* v___x_159_; lean_object* v___x_160_; lean_object* v___x_161_; 
v___x_159_ = lean_obj_once(&lp_JunkValues_Lean_addMessageContextPartial___at___00Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0_spec__0___closed__1, &lp_JunkValues_Lean_addMessageContextPartial___at___00Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0_spec__0___closed__1_once, _init_lp_JunkValues_Lean_addMessageContextPartial___at___00Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0_spec__0___closed__1);
v___x_160_ = lean_unsigned_to_nat(0u);
v___x_161_ = lean_alloc_ctor(0, 10, 0);
lean_ctor_set(v___x_161_, 0, v___x_160_);
lean_ctor_set(v___x_161_, 1, v___x_160_);
lean_ctor_set(v___x_161_, 2, v___x_160_);
lean_ctor_set(v___x_161_, 3, v___x_160_);
lean_ctor_set(v___x_161_, 4, v___x_159_);
lean_ctor_set(v___x_161_, 5, v___x_159_);
lean_ctor_set(v___x_161_, 6, v___x_159_);
lean_ctor_set(v___x_161_, 7, v___x_159_);
lean_ctor_set(v___x_161_, 8, v___x_159_);
lean_ctor_set(v___x_161_, 9, v___x_159_);
return v___x_161_;
}
}
static lean_object* _init_lp_JunkValues_Lean_addMessageContextPartial___at___00Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0_spec__0___closed__3(void){
_start:
{
lean_object* v___x_162_; lean_object* v___x_163_; lean_object* v___x_164_; 
v___x_162_ = lean_unsigned_to_nat(32u);
v___x_163_ = lean_mk_empty_array_with_capacity(v___x_162_);
v___x_164_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_164_, 0, v___x_163_);
return v___x_164_;
}
}
static lean_object* _init_lp_JunkValues_Lean_addMessageContextPartial___at___00Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0_spec__0___closed__4(void){
_start:
{
size_t v___x_165_; lean_object* v___x_166_; lean_object* v___x_167_; lean_object* v___x_168_; lean_object* v___x_169_; lean_object* v___x_170_; 
v___x_165_ = ((size_t)5ULL);
v___x_166_ = lean_unsigned_to_nat(0u);
v___x_167_ = lean_unsigned_to_nat(32u);
v___x_168_ = lean_mk_empty_array_with_capacity(v___x_167_);
v___x_169_ = lean_obj_once(&lp_JunkValues_Lean_addMessageContextPartial___at___00Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0_spec__0___closed__3, &lp_JunkValues_Lean_addMessageContextPartial___at___00Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0_spec__0___closed__3_once, _init_lp_JunkValues_Lean_addMessageContextPartial___at___00Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0_spec__0___closed__3);
v___x_170_ = lean_alloc_ctor(0, 4, sizeof(size_t)*1);
lean_ctor_set(v___x_170_, 0, v___x_169_);
lean_ctor_set(v___x_170_, 1, v___x_168_);
lean_ctor_set(v___x_170_, 2, v___x_166_);
lean_ctor_set(v___x_170_, 3, v___x_166_);
lean_ctor_set_usize(v___x_170_, 4, v___x_165_);
return v___x_170_;
}
}
static lean_object* _init_lp_JunkValues_Lean_addMessageContextPartial___at___00Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0_spec__0___closed__5(void){
_start:
{
lean_object* v___x_171_; lean_object* v___x_172_; lean_object* v___x_173_; lean_object* v___x_174_; 
v___x_171_ = lean_box(1);
v___x_172_ = lean_obj_once(&lp_JunkValues_Lean_addMessageContextPartial___at___00Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0_spec__0___closed__4, &lp_JunkValues_Lean_addMessageContextPartial___at___00Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0_spec__0___closed__4_once, _init_lp_JunkValues_Lean_addMessageContextPartial___at___00Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0_spec__0___closed__4);
v___x_173_ = lean_obj_once(&lp_JunkValues_Lean_addMessageContextPartial___at___00Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0_spec__0___closed__1, &lp_JunkValues_Lean_addMessageContextPartial___at___00Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0_spec__0___closed__1_once, _init_lp_JunkValues_Lean_addMessageContextPartial___at___00Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0_spec__0___closed__1);
v___x_174_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_174_, 0, v___x_173_);
lean_ctor_set(v___x_174_, 1, v___x_172_);
lean_ctor_set(v___x_174_, 2, v___x_171_);
return v___x_174_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_addMessageContextPartial___at___00Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0_spec__0(lean_object* v_msgData_175_, lean_object* v___y_176_, lean_object* v___y_177_){
_start:
{
lean_object* v___x_179_; lean_object* v_env_180_; lean_object* v_options_181_; lean_object* v___x_182_; lean_object* v___x_183_; lean_object* v___x_184_; lean_object* v___x_185_; lean_object* v___x_186_; 
v___x_179_ = lean_st_ref_get(v___y_177_);
v_env_180_ = lean_ctor_get(v___x_179_, 0);
lean_inc_ref(v_env_180_);
lean_dec(v___x_179_);
v_options_181_ = lean_ctor_get(v___y_176_, 2);
v___x_182_ = lean_obj_once(&lp_JunkValues_Lean_addMessageContextPartial___at___00Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0_spec__0___closed__2, &lp_JunkValues_Lean_addMessageContextPartial___at___00Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0_spec__0___closed__2_once, _init_lp_JunkValues_Lean_addMessageContextPartial___at___00Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0_spec__0___closed__2);
v___x_183_ = lean_obj_once(&lp_JunkValues_Lean_addMessageContextPartial___at___00Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0_spec__0___closed__5, &lp_JunkValues_Lean_addMessageContextPartial___at___00Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0_spec__0___closed__5_once, _init_lp_JunkValues_Lean_addMessageContextPartial___at___00Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0_spec__0___closed__5);
lean_inc_ref(v_options_181_);
v___x_184_ = lean_alloc_ctor(0, 4, 0);
lean_ctor_set(v___x_184_, 0, v_env_180_);
lean_ctor_set(v___x_184_, 1, v___x_182_);
lean_ctor_set(v___x_184_, 2, v___x_183_);
lean_ctor_set(v___x_184_, 3, v_options_181_);
v___x_185_ = lean_alloc_ctor(3, 2, 0);
lean_ctor_set(v___x_185_, 0, v___x_184_);
lean_ctor_set(v___x_185_, 1, v_msgData_175_);
v___x_186_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_186_, 0, v___x_185_);
return v___x_186_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_addMessageContextPartial___at___00Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0_spec__0___boxed(lean_object* v_msgData_187_, lean_object* v___y_188_, lean_object* v___y_189_, lean_object* v___y_190_){
_start:
{
lean_object* v_res_191_; 
v_res_191_ = lp_JunkValues_Lean_addMessageContextPartial___at___00Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0_spec__0(v_msgData_187_, v___y_188_, v___y_189_);
lean_dec(v___y_189_);
lean_dec_ref(v___y_188_);
return v_res_191_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0___redArg(lean_object* v_msg_192_, lean_object* v___y_193_, lean_object* v___y_194_){
_start:
{
lean_object* v_ref_196_; lean_object* v___x_197_; lean_object* v_a_198_; lean_object* v___x_200_; uint8_t v_isShared_201_; uint8_t v_isSharedCheck_206_; 
v_ref_196_ = lean_ctor_get(v___y_193_, 5);
v___x_197_ = lp_JunkValues_Lean_addMessageContextPartial___at___00Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0_spec__0(v_msg_192_, v___y_193_, v___y_194_);
v_a_198_ = lean_ctor_get(v___x_197_, 0);
v_isSharedCheck_206_ = !lean_is_exclusive(v___x_197_);
if (v_isSharedCheck_206_ == 0)
{
v___x_200_ = v___x_197_;
v_isShared_201_ = v_isSharedCheck_206_;
goto v_resetjp_199_;
}
else
{
lean_inc(v_a_198_);
lean_dec(v___x_197_);
v___x_200_ = lean_box(0);
v_isShared_201_ = v_isSharedCheck_206_;
goto v_resetjp_199_;
}
v_resetjp_199_:
{
lean_object* v___x_202_; lean_object* v___x_204_; 
lean_inc(v_ref_196_);
v___x_202_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_202_, 0, v_ref_196_);
lean_ctor_set(v___x_202_, 1, v_a_198_);
if (v_isShared_201_ == 0)
{
lean_ctor_set_tag(v___x_200_, 1);
lean_ctor_set(v___x_200_, 0, v___x_202_);
v___x_204_ = v___x_200_;
goto v_reusejp_203_;
}
else
{
lean_object* v_reuseFailAlloc_205_; 
v_reuseFailAlloc_205_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_205_, 0, v___x_202_);
v___x_204_ = v_reuseFailAlloc_205_;
goto v_reusejp_203_;
}
v_reusejp_203_:
{
return v___x_204_;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0___redArg___boxed(lean_object* v_msg_207_, lean_object* v___y_208_, lean_object* v___y_209_, lean_object* v___y_210_){
_start:
{
lean_object* v_res_211_; 
v_res_211_ = lp_JunkValues_Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0___redArg(v_msg_207_, v___y_208_, v___y_209_);
lean_dec(v___y_209_);
lean_dec_ref(v___y_208_);
return v_res_211_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__2(size_t v_sz_212_, size_t v_i_213_, lean_object* v_bs_214_){
_start:
{
uint8_t v___x_215_; 
v___x_215_ = lean_usize_dec_lt(v_i_213_, v_sz_212_);
if (v___x_215_ == 0)
{
lean_object* v___x_216_; 
v___x_216_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_216_, 0, v_bs_214_);
return v___x_216_;
}
else
{
lean_object* v_v_217_; lean_object* v___x_218_; lean_object* v_bs_x27_219_; size_t v___x_220_; size_t v___x_221_; lean_object* v___x_222_; 
v_v_217_ = lean_array_uget(v_bs_214_, v_i_213_);
v___x_218_ = lean_unsigned_to_nat(0u);
v_bs_x27_219_ = lean_array_uset(v_bs_214_, v_i_213_, v___x_218_);
v___x_220_ = ((size_t)1ULL);
v___x_221_ = lean_usize_add(v_i_213_, v___x_220_);
v___x_222_ = lean_array_uset(v_bs_x27_219_, v_i_213_, v_v_217_);
v_i_213_ = v___x_221_;
v_bs_214_ = v___x_222_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__2___boxed(lean_object* v_sz_224_, lean_object* v_i_225_, lean_object* v_bs_226_){
_start:
{
size_t v_sz_boxed_227_; size_t v_i_boxed_228_; lean_object* v_res_229_; 
v_sz_boxed_227_ = lean_unbox_usize(v_sz_224_);
lean_dec(v_sz_224_);
v_i_boxed_228_ = lean_unbox_usize(v_i_225_);
lean_dec(v_i_225_);
v_res_229_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__2(v_sz_boxed_227_, v_i_boxed_228_, v_bs_226_);
return v_res_229_;
}
}
static lean_object* _init_lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__1_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_(void){
_start:
{
lean_object* v___x_231_; lean_object* v___x_232_; 
v___x_231_ = ((lean_object*)(lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__0_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_));
v___x_232_ = l_Lean_stringToMessageData(v___x_231_);
return v___x_232_;
}
}
static lean_object* _init_lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__3_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_(void){
_start:
{
lean_object* v___x_234_; lean_object* v___x_235_; 
v___x_234_ = ((lean_object*)(lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__2_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_));
v___x_235_ = l_Lean_stringToMessageData(v___x_234_);
return v___x_235_;
}
}
static lean_object* _init_lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__4_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_(void){
_start:
{
lean_object* v___x_236_; 
v___x_236_ = l_Lean_PersistentHashMap_mkEmptyEntriesArray(lean_box(0), lean_box(0));
return v___x_236_;
}
}
static lean_object* _init_lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__5_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_(void){
_start:
{
lean_object* v___x_237_; lean_object* v___x_238_; 
v___x_237_ = lean_obj_once(&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__4_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_, &lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__4_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__once, _init_lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__4_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_);
v___x_238_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_238_, 0, v___x_237_);
return v___x_238_;
}
}
static lean_object* _init_lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__6_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_(void){
_start:
{
lean_object* v___x_239_; lean_object* v___x_240_; 
v___x_239_ = lean_obj_once(&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__5_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_, &lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__5_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__once, _init_lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__5_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_);
v___x_240_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_240_, 0, v___x_239_);
lean_ctor_set(v___x_240_, 1, v___x_239_);
return v___x_240_;
}
}
static uint64_t _init_lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__8_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_(void){
_start:
{
lean_object* v___x_247_; uint64_t v___x_248_; 
v___x_247_ = ((lean_object*)(lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__7_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_));
v___x_248_ = l___private_Lean_Meta_Basic_0__Lean_Meta_Config_toKey(v___x_247_);
return v___x_248_;
}
}
static lean_object* _init_lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__9_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_(void){
_start:
{
uint64_t v___x_249_; lean_object* v___x_250_; lean_object* v___x_251_; 
v___x_249_ = lean_uint64_once(&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__8_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_, &lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__8_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__once, _init_lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__8_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_);
v___x_250_ = ((lean_object*)(lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__7_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_));
v___x_251_ = lean_alloc_ctor(0, 1, 8);
lean_ctor_set(v___x_251_, 0, v___x_250_);
lean_ctor_set_uint64(v___x_251_, sizeof(void*)*1, v___x_249_);
return v___x_251_;
}
}
static lean_object* _init_lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__10_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_(void){
_start:
{
lean_object* v___x_252_; 
v___x_252_ = l_Lean_PersistentHashMap_mkEmptyEntriesArray(lean_box(0), lean_box(0));
return v___x_252_;
}
}
static lean_object* _init_lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__11_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_(void){
_start:
{
lean_object* v___x_253_; lean_object* v___x_254_; 
v___x_253_ = lean_obj_once(&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__10_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_, &lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__10_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__once, _init_lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__10_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_);
v___x_254_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_254_, 0, v___x_253_);
return v___x_254_;
}
}
static lean_object* _init_lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__12_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_(void){
_start:
{
lean_object* v___x_255_; lean_object* v___x_256_; 
v___x_255_ = lean_obj_once(&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__11_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_, &lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__11_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__once, _init_lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__11_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_);
v___x_256_ = lean_alloc_ctor(0, 6, 0);
lean_ctor_set(v___x_256_, 0, v___x_255_);
lean_ctor_set(v___x_256_, 1, v___x_255_);
lean_ctor_set(v___x_256_, 2, v___x_255_);
lean_ctor_set(v___x_256_, 3, v___x_255_);
lean_ctor_set(v___x_256_, 4, v___x_255_);
lean_ctor_set(v___x_256_, 5, v___x_255_);
return v___x_256_;
}
}
static lean_object* _init_lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__13_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_(void){
_start:
{
lean_object* v___x_257_; lean_object* v___x_258_; 
v___x_257_ = lean_obj_once(&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__11_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_, &lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__11_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__once, _init_lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__11_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_);
v___x_258_ = lean_alloc_ctor(0, 5, 0);
lean_ctor_set(v___x_258_, 0, v___x_257_);
lean_ctor_set(v___x_258_, 1, v___x_257_);
lean_ctor_set(v___x_258_, 2, v___x_257_);
lean_ctor_set(v___x_258_, 3, v___x_257_);
lean_ctor_set(v___x_258_, 4, v___x_257_);
return v___x_258_;
}
}
static lean_object* _init_lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__16_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_(void){
_start:
{
lean_object* v___x_261_; lean_object* v___x_262_; 
v___x_261_ = ((lean_object*)(lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__15_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_));
v___x_262_ = l_Lean_stringToMessageData(v___x_261_);
return v___x_262_;
}
}
static lean_object* _init_lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__18_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_(void){
_start:
{
lean_object* v___x_264_; lean_object* v___x_265_; 
v___x_264_ = ((lean_object*)(lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__17_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_));
v___x_265_ = l_Lean_stringToMessageData(v___x_264_);
return v___x_265_;
}
}
static lean_object* _init_lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__20_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_(void){
_start:
{
lean_object* v___x_267_; lean_object* v___x_268_; 
v___x_267_ = ((lean_object*)(lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__19_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_));
v___x_268_ = l_Lean_stringToMessageData(v___x_267_);
return v___x_268_;
}
}
static lean_object* _init_lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__27_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_(void){
_start:
{
lean_object* v___x_279_; lean_object* v___x_280_; 
v___x_279_ = ((lean_object*)(lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__26_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_));
v___x_280_ = l_Lean_stringToMessageData(v___x_279_);
return v___x_280_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_(lean_object* v___x_281_, lean_object* v___x_282_, lean_object* v___x_283_, lean_object* v___x_284_, lean_object* v___x_285_, lean_object* v_declName_286_, lean_object* v_stx_287_, uint8_t v_attrKind_288_, lean_object* v___y_289_, lean_object* v___y_290_){
_start:
{
lean_object* v___y_293_; lean_object* v___y_294_; lean_object* v_a_295_; lean_object* v___y_338_; lean_object* v___y_339_; lean_object* v___y_340_; lean_object* v___y_341_; lean_object* v___y_374_; lean_object* v___y_375_; lean_object* v___y_376_; lean_object* v___y_377_; lean_object* v_fst_382_; lean_object* v_snd_383_; lean_object* v___y_384_; lean_object* v___y_385_; lean_object* v___y_396_; lean_object* v___y_397_; lean_object* v___y_398_; lean_object* v___y_399_; lean_object* v___y_404_; lean_object* v_noteStx_x3f_405_; lean_object* v___y_406_; lean_object* v___y_407_; lean_object* v___y_411_; lean_object* v_posStx_412_; lean_object* v___y_413_; lean_object* v___y_414_; uint8_t v___x_479_; uint8_t v___x_480_; 
v___x_479_ = 0;
v___x_480_ = l_Lean_instBEqAttributeKind_beq(v_attrKind_288_, v___x_479_);
if (v___x_480_ == 0)
{
lean_object* v___x_481_; lean_object* v___x_482_; 
lean_dec(v_stx_287_);
lean_dec(v_declName_286_);
lean_dec_ref(v___x_285_);
lean_dec_ref(v___x_284_);
lean_dec(v___x_282_);
lean_dec(v___x_281_);
v___x_481_ = lean_obj_once(&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__27_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_, &lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__27_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__once, _init_lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__27_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_);
v___x_482_ = lp_JunkValues_Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0___redArg(v___x_481_, v___y_289_, v___y_290_);
return v___x_482_;
}
else
{
goto v___jp_431_;
}
v___jp_292_:
{
if (lean_obj_tag(v_a_295_) == 0)
{
lean_object* v_a_296_; lean_object* v___x_297_; lean_object* v___x_298_; lean_object* v___x_299_; lean_object* v___x_300_; lean_object* v___x_301_; lean_object* v___x_302_; lean_object* v___x_303_; lean_object* v___x_304_; 
v_a_296_ = lean_ctor_get(v_a_295_, 0);
lean_inc(v_a_296_);
lean_dec_ref_known(v_a_295_, 1);
v___x_297_ = lean_obj_once(&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__1_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_, &lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__1_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__once, _init_lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__1_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_);
v___x_298_ = l_Lean_MessageData_ofName(v_declName_286_);
v___x_299_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_299_, 0, v___x_297_);
lean_ctor_set(v___x_299_, 1, v___x_298_);
v___x_300_ = lean_obj_once(&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__3_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_, &lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__3_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__once, _init_lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__3_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_);
v___x_301_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_301_, 0, v___x_299_);
lean_ctor_set(v___x_301_, 1, v___x_300_);
v___x_302_ = l_Lean_stringToMessageData(v_a_296_);
v___x_303_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_303_, 0, v___x_301_);
lean_ctor_set(v___x_303_, 1, v___x_302_);
v___x_304_ = lp_JunkValues_Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0___redArg(v___x_303_, v___y_293_, v___y_294_);
return v___x_304_;
}
else
{
lean_object* v_a_305_; lean_object* v___x_307_; uint8_t v_isShared_308_; uint8_t v_isSharedCheck_336_; 
v_a_305_ = lean_ctor_get(v_a_295_, 0);
v_isSharedCheck_336_ = !lean_is_exclusive(v_a_295_);
if (v_isSharedCheck_336_ == 0)
{
v___x_307_ = v_a_295_;
v_isShared_308_ = v_isSharedCheck_336_;
goto v_resetjp_306_;
}
else
{
lean_inc(v_a_305_);
lean_dec(v_a_295_);
v___x_307_ = lean_box(0);
v_isShared_308_ = v_isSharedCheck_336_;
goto v_resetjp_306_;
}
v_resetjp_306_:
{
lean_object* v___x_309_; lean_object* v_env_310_; lean_object* v_nextMacroScope_311_; lean_object* v_ngen_312_; lean_object* v_auxDeclNGen_313_; lean_object* v_traceState_314_; lean_object* v_messages_315_; lean_object* v_infoState_316_; lean_object* v_snapshotTasks_317_; lean_object* v___x_319_; uint8_t v_isShared_320_; uint8_t v_isSharedCheck_334_; 
v___x_309_ = lean_st_ref_take(v___y_294_);
v_env_310_ = lean_ctor_get(v___x_309_, 0);
v_nextMacroScope_311_ = lean_ctor_get(v___x_309_, 1);
v_ngen_312_ = lean_ctor_get(v___x_309_, 2);
v_auxDeclNGen_313_ = lean_ctor_get(v___x_309_, 3);
v_traceState_314_ = lean_ctor_get(v___x_309_, 4);
v_messages_315_ = lean_ctor_get(v___x_309_, 6);
v_infoState_316_ = lean_ctor_get(v___x_309_, 7);
v_snapshotTasks_317_ = lean_ctor_get(v___x_309_, 8);
v_isSharedCheck_334_ = !lean_is_exclusive(v___x_309_);
if (v_isSharedCheck_334_ == 0)
{
lean_object* v_unused_335_; 
v_unused_335_ = lean_ctor_get(v___x_309_, 5);
lean_dec(v_unused_335_);
v___x_319_ = v___x_309_;
v_isShared_320_ = v_isSharedCheck_334_;
goto v_resetjp_318_;
}
else
{
lean_inc(v_snapshotTasks_317_);
lean_inc(v_infoState_316_);
lean_inc(v_messages_315_);
lean_inc(v_traceState_314_);
lean_inc(v_auxDeclNGen_313_);
lean_inc(v_ngen_312_);
lean_inc(v_nextMacroScope_311_);
lean_inc(v_env_310_);
lean_dec(v___x_309_);
v___x_319_ = lean_box(0);
v_isShared_320_ = v_isSharedCheck_334_;
goto v_resetjp_318_;
}
v_resetjp_318_:
{
lean_object* v___x_321_; lean_object* v_toEnvExtension_322_; lean_object* v_asyncMode_323_; lean_object* v___x_324_; lean_object* v___x_325_; lean_object* v___x_327_; 
v___x_321_ = lp_JunkValues_JunkValues_junkExt;
v_toEnvExtension_322_ = lean_ctor_get(v___x_321_, 0);
v_asyncMode_323_ = lean_ctor_get(v_toEnvExtension_322_, 2);
v___x_324_ = l_Lean_PersistentEnvExtension_addEntry___redArg(v___x_321_, v_env_310_, v_a_305_, v_asyncMode_323_, v_declName_286_);
v___x_325_ = lean_obj_once(&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__6_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_, &lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__6_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__once, _init_lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__6_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_);
if (v_isShared_320_ == 0)
{
lean_ctor_set(v___x_319_, 5, v___x_325_);
lean_ctor_set(v___x_319_, 0, v___x_324_);
v___x_327_ = v___x_319_;
goto v_reusejp_326_;
}
else
{
lean_object* v_reuseFailAlloc_333_; 
v_reuseFailAlloc_333_ = lean_alloc_ctor(0, 9, 0);
lean_ctor_set(v_reuseFailAlloc_333_, 0, v___x_324_);
lean_ctor_set(v_reuseFailAlloc_333_, 1, v_nextMacroScope_311_);
lean_ctor_set(v_reuseFailAlloc_333_, 2, v_ngen_312_);
lean_ctor_set(v_reuseFailAlloc_333_, 3, v_auxDeclNGen_313_);
lean_ctor_set(v_reuseFailAlloc_333_, 4, v_traceState_314_);
lean_ctor_set(v_reuseFailAlloc_333_, 5, v___x_325_);
lean_ctor_set(v_reuseFailAlloc_333_, 6, v_messages_315_);
lean_ctor_set(v_reuseFailAlloc_333_, 7, v_infoState_316_);
lean_ctor_set(v_reuseFailAlloc_333_, 8, v_snapshotTasks_317_);
v___x_327_ = v_reuseFailAlloc_333_;
goto v_reusejp_326_;
}
v_reusejp_326_:
{
lean_object* v___x_328_; lean_object* v___x_329_; lean_object* v___x_331_; 
v___x_328_ = lean_st_ref_set(v___y_294_, v___x_327_);
v___x_329_ = lean_box(0);
if (v_isShared_308_ == 0)
{
lean_ctor_set_tag(v___x_307_, 0);
lean_ctor_set(v___x_307_, 0, v___x_329_);
v___x_331_ = v___x_307_;
goto v_reusejp_330_;
}
else
{
lean_object* v_reuseFailAlloc_332_; 
v_reuseFailAlloc_332_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_332_, 0, v___x_329_);
v___x_331_ = v_reuseFailAlloc_332_;
goto v_reusejp_330_;
}
v_reusejp_330_:
{
return v___x_331_;
}
}
}
}
}
}
v___jp_337_:
{
uint8_t v___x_342_; uint8_t v___x_343_; lean_object* v___x_344_; lean_object* v___x_345_; lean_object* v___x_346_; lean_object* v___x_347_; lean_object* v___x_348_; size_t v___x_349_; lean_object* v___x_350_; lean_object* v___x_351_; lean_object* v___x_352_; lean_object* v___x_353_; lean_object* v___x_354_; lean_object* v___x_355_; lean_object* v___x_356_; lean_object* v___x_357_; lean_object* v___x_358_; lean_object* v___x_359_; lean_object* v___x_360_; lean_object* v___x_361_; 
v___x_342_ = 0;
v___x_343_ = 1;
v___x_344_ = lean_obj_once(&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__9_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_, &lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__9_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__once, _init_lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__9_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_);
v___x_345_ = lean_obj_once(&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__11_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_, &lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__11_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__once, _init_lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__11_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_);
v___x_346_ = lean_unsigned_to_nat(32u);
v___x_347_ = lean_mk_empty_array_with_capacity(v___x_346_);
v___x_348_ = lean_obj_once(&lp_JunkValues_Lean_addMessageContextPartial___at___00Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0_spec__0___closed__3, &lp_JunkValues_Lean_addMessageContextPartial___at___00Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0_spec__0___closed__3_once, _init_lp_JunkValues_Lean_addMessageContextPartial___at___00Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0_spec__0___closed__3);
v___x_349_ = ((size_t)5ULL);
lean_inc_n(v___x_281_, 6);
v___x_350_ = lean_alloc_ctor(0, 4, sizeof(size_t)*1);
lean_ctor_set(v___x_350_, 0, v___x_348_);
lean_ctor_set(v___x_350_, 1, v___x_347_);
lean_ctor_set(v___x_350_, 2, v___x_281_);
lean_ctor_set(v___x_350_, 3, v___x_281_);
lean_ctor_set_usize(v___x_350_, 4, v___x_349_);
v___x_351_ = lean_box(1);
lean_inc_ref(v___x_350_);
v___x_352_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_352_, 0, v___x_345_);
lean_ctor_set(v___x_352_, 1, v___x_350_);
lean_ctor_set(v___x_352_, 2, v___x_351_);
v___x_353_ = lean_mk_empty_array_with_capacity(v___x_281_);
v___x_354_ = lean_box(0);
lean_inc(v___x_282_);
v___x_355_ = lean_alloc_ctor(0, 7, 4);
lean_ctor_set(v___x_355_, 0, v___x_344_);
lean_ctor_set(v___x_355_, 1, v___x_282_);
lean_ctor_set(v___x_355_, 2, v___x_352_);
lean_ctor_set(v___x_355_, 3, v___x_353_);
lean_ctor_set(v___x_355_, 4, v___x_354_);
lean_ctor_set(v___x_355_, 5, v___x_281_);
lean_ctor_set(v___x_355_, 6, v___x_354_);
lean_ctor_set_uint8(v___x_355_, sizeof(void*)*7, v___x_342_);
lean_ctor_set_uint8(v___x_355_, sizeof(void*)*7 + 1, v___x_342_);
lean_ctor_set_uint8(v___x_355_, sizeof(void*)*7 + 2, v___x_342_);
lean_ctor_set_uint8(v___x_355_, sizeof(void*)*7 + 3, v___x_343_);
v___x_356_ = lean_alloc_ctor(0, 10, 0);
lean_ctor_set(v___x_356_, 0, v___x_281_);
lean_ctor_set(v___x_356_, 1, v___x_281_);
lean_ctor_set(v___x_356_, 2, v___x_281_);
lean_ctor_set(v___x_356_, 3, v___x_281_);
lean_ctor_set(v___x_356_, 4, v___x_345_);
lean_ctor_set(v___x_356_, 5, v___x_345_);
lean_ctor_set(v___x_356_, 6, v___x_345_);
lean_ctor_set(v___x_356_, 7, v___x_345_);
lean_ctor_set(v___x_356_, 8, v___x_345_);
lean_ctor_set(v___x_356_, 9, v___x_345_);
v___x_357_ = lean_obj_once(&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__12_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_, &lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__12_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__once, _init_lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__12_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_);
v___x_358_ = lean_obj_once(&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__13_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_, &lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__13_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__once, _init_lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__13_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_);
v___x_359_ = lean_alloc_ctor(0, 5, 0);
lean_ctor_set(v___x_359_, 0, v___x_356_);
lean_ctor_set(v___x_359_, 1, v___x_357_);
lean_ctor_set(v___x_359_, 2, v___x_282_);
lean_ctor_set(v___x_359_, 3, v___x_350_);
lean_ctor_set(v___x_359_, 4, v___x_358_);
v___x_360_ = lean_st_mk_ref(v___x_359_);
lean_inc(v_declName_286_);
v___x_361_ = lp_JunkValues_JunkValues_ruleOfTheorem_x3f(v_declName_286_, v___y_341_, v___y_339_, v___x_355_, v___x_360_, v___y_338_, v___y_340_);
lean_dec_ref_known(v___x_355_, 7);
if (lean_obj_tag(v___x_361_) == 0)
{
lean_object* v_a_362_; lean_object* v___x_363_; 
v_a_362_ = lean_ctor_get(v___x_361_, 0);
lean_inc(v_a_362_);
lean_dec_ref_known(v___x_361_, 1);
v___x_363_ = lean_st_ref_get(v___x_360_);
lean_dec(v___x_360_);
lean_dec(v___x_363_);
v___y_293_ = v___y_338_;
v___y_294_ = v___y_340_;
v_a_295_ = v_a_362_;
goto v___jp_292_;
}
else
{
lean_dec(v___x_360_);
if (lean_obj_tag(v___x_361_) == 0)
{
lean_object* v_a_364_; 
v_a_364_ = lean_ctor_get(v___x_361_, 0);
lean_inc(v_a_364_);
lean_dec_ref_known(v___x_361_, 1);
v___y_293_ = v___y_338_;
v___y_294_ = v___y_340_;
v_a_295_ = v_a_364_;
goto v___jp_292_;
}
else
{
lean_object* v_a_365_; lean_object* v___x_367_; uint8_t v_isShared_368_; uint8_t v_isSharedCheck_372_; 
lean_dec(v_declName_286_);
v_a_365_ = lean_ctor_get(v___x_361_, 0);
v_isSharedCheck_372_ = !lean_is_exclusive(v___x_361_);
if (v_isSharedCheck_372_ == 0)
{
v___x_367_ = v___x_361_;
v_isShared_368_ = v_isSharedCheck_372_;
goto v_resetjp_366_;
}
else
{
lean_inc(v_a_365_);
lean_dec(v___x_361_);
v___x_367_ = lean_box(0);
v_isShared_368_ = v_isSharedCheck_372_;
goto v_resetjp_366_;
}
v_resetjp_366_:
{
lean_object* v___x_370_; 
if (v_isShared_368_ == 0)
{
v___x_370_ = v___x_367_;
goto v_reusejp_369_;
}
else
{
lean_object* v_reuseFailAlloc_371_; 
v_reuseFailAlloc_371_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_371_, 0, v_a_365_);
v___x_370_ = v_reuseFailAlloc_371_;
goto v_reusejp_369_;
}
v_reusejp_369_:
{
return v___x_370_;
}
}
}
}
}
v___jp_373_:
{
if (lean_obj_tag(v___y_374_) == 0)
{
lean_object* v___x_378_; 
v___x_378_ = ((lean_object*)(lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__14_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_));
v___y_338_ = v___y_376_;
v___y_339_ = v___y_375_;
v___y_340_ = v___y_377_;
v___y_341_ = v___x_378_;
goto v___jp_337_;
}
else
{
lean_object* v_val_379_; lean_object* v___x_380_; 
v_val_379_ = lean_ctor_get(v___y_374_, 0);
lean_inc(v_val_379_);
lean_dec_ref_known(v___y_374_, 1);
v___x_380_ = l_Lean_TSyntax_getString(v_val_379_);
lean_dec(v_val_379_);
v___y_338_ = v___y_376_;
v___y_339_ = v___y_375_;
v___y_340_ = v___y_377_;
v___y_341_ = v___x_380_;
goto v___jp_337_;
}
}
v___jp_381_:
{
lean_object* v___x_386_; lean_object* v_env_387_; lean_object* v___x_388_; 
v___x_386_ = lean_st_ref_get(v___y_385_);
v_env_387_ = lean_ctor_get(v___x_386_, 0);
lean_inc_ref(v_env_387_);
lean_dec(v___x_386_);
v___x_388_ = l_Lean_Environment_getModuleIdxFor_x3f(v_env_387_, v_declName_286_);
lean_dec_ref(v_env_387_);
if (lean_obj_tag(v___x_388_) == 0)
{
v___y_374_ = v_snd_383_;
v___y_375_ = v_fst_382_;
v___y_376_ = v___y_384_;
v___y_377_ = v___y_385_;
goto v___jp_373_;
}
else
{
lean_object* v___x_389_; lean_object* v___x_390_; lean_object* v___x_391_; lean_object* v___x_392_; lean_object* v___x_393_; lean_object* v___x_394_; 
lean_dec_ref_known(v___x_388_, 1);
lean_dec(v_snd_383_);
lean_dec_ref(v_fst_382_);
lean_dec(v___x_282_);
lean_dec(v___x_281_);
v___x_389_ = lean_obj_once(&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__16_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_, &lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__16_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__once, _init_lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__16_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_);
v___x_390_ = l_Lean_MessageData_ofName(v_declName_286_);
v___x_391_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_391_, 0, v___x_389_);
lean_ctor_set(v___x_391_, 1, v___x_390_);
v___x_392_ = lean_obj_once(&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__18_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_, &lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__18_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__once, _init_lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__18_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_);
v___x_393_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_393_, 0, v___x_391_);
lean_ctor_set(v___x_393_, 1, v___x_392_);
v___x_394_ = lp_JunkValues_Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0___redArg(v___x_393_, v___y_384_, v___y_385_);
return v___x_394_;
}
}
v___jp_395_:
{
size_t v_sz_400_; size_t v___x_401_; lean_object* v___x_402_; 
v_sz_400_ = lean_array_size(v___y_399_);
v___x_401_ = ((size_t)0ULL);
v___x_402_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__1(v_sz_400_, v___x_401_, v___y_399_);
v_fst_382_ = v___x_402_;
v_snd_383_ = v___y_398_;
v___y_384_ = v___y_396_;
v___y_385_ = v___y_397_;
goto v___jp_381_;
}
v___jp_403_:
{
if (lean_obj_tag(v___y_404_) == 0)
{
lean_object* v___x_408_; 
v___x_408_ = lean_mk_empty_array_with_capacity(v___x_281_);
v___y_396_ = v___y_406_;
v___y_397_ = v___y_407_;
v___y_398_ = v_noteStx_x3f_405_;
v___y_399_ = v___x_408_;
goto v___jp_395_;
}
else
{
lean_object* v_val_409_; 
v_val_409_ = lean_ctor_get(v___y_404_, 0);
lean_inc(v_val_409_);
lean_dec_ref_known(v___y_404_, 1);
v___y_396_ = v___y_406_;
v___y_397_ = v___y_407_;
v___y_398_ = v_noteStx_x3f_405_;
v___y_399_ = v_val_409_;
goto v___jp_395_;
}
}
v___jp_410_:
{
lean_object* v___x_415_; uint8_t v___x_416_; 
v___x_415_ = l_Lean_Syntax_getArg(v_stx_287_, v___x_283_);
lean_dec(v_stx_287_);
v___x_416_ = l_Lean_Syntax_isNone(v___x_415_);
if (v___x_416_ == 0)
{
uint8_t v___x_417_; 
lean_inc(v___x_415_);
v___x_417_ = l_Lean_Syntax_matchesNull(v___x_415_, v___y_411_);
if (v___x_417_ == 0)
{
lean_object* v___x_418_; lean_object* v___x_419_; lean_object* v_a_420_; lean_object* v___x_422_; uint8_t v_isShared_423_; uint8_t v_isSharedCheck_427_; 
lean_dec(v___x_415_);
lean_dec(v_posStx_412_);
lean_dec(v_declName_286_);
lean_dec(v___x_282_);
lean_dec(v___x_281_);
v___x_418_ = lean_obj_once(&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__20_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_, &lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__20_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__once, _init_lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__20_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_);
v___x_419_ = lp_JunkValues_Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0___redArg(v___x_418_, v___y_413_, v___y_414_);
v_a_420_ = lean_ctor_get(v___x_419_, 0);
v_isSharedCheck_427_ = !lean_is_exclusive(v___x_419_);
if (v_isSharedCheck_427_ == 0)
{
v___x_422_ = v___x_419_;
v_isShared_423_ = v_isSharedCheck_427_;
goto v_resetjp_421_;
}
else
{
lean_inc(v_a_420_);
lean_dec(v___x_419_);
v___x_422_ = lean_box(0);
v_isShared_423_ = v_isSharedCheck_427_;
goto v_resetjp_421_;
}
v_resetjp_421_:
{
lean_object* v___x_425_; 
if (v_isShared_423_ == 0)
{
v___x_425_ = v___x_422_;
goto v_reusejp_424_;
}
else
{
lean_object* v_reuseFailAlloc_426_; 
v_reuseFailAlloc_426_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_426_, 0, v_a_420_);
v___x_425_ = v_reuseFailAlloc_426_;
goto v_reusejp_424_;
}
v_reusejp_424_:
{
return v___x_425_;
}
}
}
else
{
lean_object* v_noteStx_x3f_428_; lean_object* v___x_429_; 
v_noteStx_x3f_428_ = l_Lean_Syntax_getArg(v___x_415_, v___x_281_);
lean_dec(v___x_415_);
v___x_429_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_429_, 0, v_noteStx_x3f_428_);
v___y_404_ = v_posStx_412_;
v_noteStx_x3f_405_ = v___x_429_;
v___y_406_ = v___y_413_;
v___y_407_ = v___y_414_;
goto v___jp_403_;
}
}
else
{
lean_object* v___x_430_; 
lean_dec(v___x_415_);
v___x_430_ = lean_box(0);
v___y_404_ = v_posStx_412_;
v_noteStx_x3f_405_ = v___x_430_;
v___y_406_ = v___y_413_;
v___y_407_ = v___y_414_;
goto v___jp_403_;
}
}
v___jp_431_:
{
lean_object* v___x_432_; lean_object* v___x_433_; uint8_t v___x_434_; 
lean_inc(v_stx_287_);
v___x_432_ = l_Lean_Syntax_getKind(v_stx_287_);
v___x_433_ = ((lean_object*)(lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__25_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_));
v___x_434_ = lean_name_eq(v___x_432_, v___x_433_);
lean_dec(v___x_432_);
if (v___x_434_ == 0)
{
lean_object* v___x_435_; uint8_t v___x_436_; 
v___x_435_ = l_Lean_Name_mkStr2(v___x_284_, v___x_285_);
lean_inc(v_stx_287_);
v___x_436_ = l_Lean_Syntax_isOfKind(v_stx_287_, v___x_435_);
lean_dec(v___x_435_);
if (v___x_436_ == 0)
{
lean_object* v___x_437_; lean_object* v___x_438_; lean_object* v_a_439_; lean_object* v___x_441_; uint8_t v_isShared_442_; uint8_t v_isSharedCheck_446_; 
lean_dec(v_stx_287_);
lean_dec(v_declName_286_);
lean_dec(v___x_282_);
lean_dec(v___x_281_);
v___x_437_ = lean_obj_once(&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__20_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_, &lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__20_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__once, _init_lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__20_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_);
v___x_438_ = lp_JunkValues_Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0___redArg(v___x_437_, v___y_289_, v___y_290_);
v_a_439_ = lean_ctor_get(v___x_438_, 0);
v_isSharedCheck_446_ = !lean_is_exclusive(v___x_438_);
if (v_isSharedCheck_446_ == 0)
{
v___x_441_ = v___x_438_;
v_isShared_442_ = v_isSharedCheck_446_;
goto v_resetjp_440_;
}
else
{
lean_inc(v_a_439_);
lean_dec(v___x_438_);
v___x_441_ = lean_box(0);
v_isShared_442_ = v_isSharedCheck_446_;
goto v_resetjp_440_;
}
v_resetjp_440_:
{
lean_object* v___x_444_; 
if (v_isShared_442_ == 0)
{
v___x_444_ = v___x_441_;
goto v_reusejp_443_;
}
else
{
lean_object* v_reuseFailAlloc_445_; 
v_reuseFailAlloc_445_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_445_, 0, v_a_439_);
v___x_444_ = v_reuseFailAlloc_445_;
goto v_reusejp_443_;
}
v_reusejp_443_:
{
return v___x_444_;
}
}
}
else
{
lean_object* v___x_447_; lean_object* v___x_448_; uint8_t v___x_449_; 
v___x_447_ = lean_unsigned_to_nat(1u);
v___x_448_ = l_Lean_Syntax_getArg(v_stx_287_, v___x_447_);
v___x_449_ = l_Lean_Syntax_isNone(v___x_448_);
if (v___x_449_ == 0)
{
uint8_t v___x_450_; 
lean_inc(v___x_448_);
v___x_450_ = l_Lean_Syntax_matchesNull(v___x_448_, v___x_283_);
if (v___x_450_ == 0)
{
lean_object* v___x_451_; lean_object* v___x_452_; lean_object* v_a_453_; lean_object* v___x_455_; uint8_t v_isShared_456_; uint8_t v_isSharedCheck_460_; 
lean_dec(v___x_448_);
lean_dec(v_stx_287_);
lean_dec(v_declName_286_);
lean_dec(v___x_282_);
lean_dec(v___x_281_);
v___x_451_ = lean_obj_once(&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__20_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_, &lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__20_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__once, _init_lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__20_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_);
v___x_452_ = lp_JunkValues_Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0___redArg(v___x_451_, v___y_289_, v___y_290_);
v_a_453_ = lean_ctor_get(v___x_452_, 0);
v_isSharedCheck_460_ = !lean_is_exclusive(v___x_452_);
if (v_isSharedCheck_460_ == 0)
{
v___x_455_ = v___x_452_;
v_isShared_456_ = v_isSharedCheck_460_;
goto v_resetjp_454_;
}
else
{
lean_inc(v_a_453_);
lean_dec(v___x_452_);
v___x_455_ = lean_box(0);
v_isShared_456_ = v_isSharedCheck_460_;
goto v_resetjp_454_;
}
v_resetjp_454_:
{
lean_object* v___x_458_; 
if (v_isShared_456_ == 0)
{
v___x_458_ = v___x_455_;
goto v_reusejp_457_;
}
else
{
lean_object* v_reuseFailAlloc_459_; 
v_reuseFailAlloc_459_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_459_, 0, v_a_453_);
v___x_458_ = v_reuseFailAlloc_459_;
goto v_reusejp_457_;
}
v_reusejp_457_:
{
return v___x_458_;
}
}
}
else
{
lean_object* v___x_461_; lean_object* v___x_462_; size_t v_sz_463_; size_t v___x_464_; lean_object* v___x_465_; 
v___x_461_ = l_Lean_Syntax_getArg(v___x_448_, v___x_447_);
lean_dec(v___x_448_);
v___x_462_ = l_Lean_Syntax_getArgs(v___x_461_);
lean_dec(v___x_461_);
v_sz_463_ = lean_array_size(v___x_462_);
v___x_464_ = ((size_t)0ULL);
v___x_465_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__2(v_sz_463_, v___x_464_, v___x_462_);
if (lean_obj_tag(v___x_465_) == 0)
{
lean_object* v___x_466_; lean_object* v___x_467_; lean_object* v_a_468_; lean_object* v___x_470_; uint8_t v_isShared_471_; uint8_t v_isSharedCheck_475_; 
lean_dec(v_stx_287_);
lean_dec(v_declName_286_);
lean_dec(v___x_282_);
lean_dec(v___x_281_);
v___x_466_ = lean_obj_once(&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__20_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_, &lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__20_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__once, _init_lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0___closed__20_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_);
v___x_467_ = lp_JunkValues_Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0___redArg(v___x_466_, v___y_289_, v___y_290_);
v_a_468_ = lean_ctor_get(v___x_467_, 0);
v_isSharedCheck_475_ = !lean_is_exclusive(v___x_467_);
if (v_isSharedCheck_475_ == 0)
{
v___x_470_ = v___x_467_;
v_isShared_471_ = v_isSharedCheck_475_;
goto v_resetjp_469_;
}
else
{
lean_inc(v_a_468_);
lean_dec(v___x_467_);
v___x_470_ = lean_box(0);
v_isShared_471_ = v_isSharedCheck_475_;
goto v_resetjp_469_;
}
v_resetjp_469_:
{
lean_object* v___x_473_; 
if (v_isShared_471_ == 0)
{
v___x_473_ = v___x_470_;
goto v_reusejp_472_;
}
else
{
lean_object* v_reuseFailAlloc_474_; 
v_reuseFailAlloc_474_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_474_, 0, v_a_468_);
v___x_473_ = v_reuseFailAlloc_474_;
goto v_reusejp_472_;
}
v_reusejp_472_:
{
return v___x_473_;
}
}
}
else
{
v___y_411_ = v___x_447_;
v_posStx_412_ = v___x_465_;
v___y_413_ = v___y_289_;
v___y_414_ = v___y_290_;
goto v___jp_410_;
}
}
}
else
{
lean_object* v___x_476_; 
lean_dec(v___x_448_);
v___x_476_ = lean_box(0);
v___y_411_ = v___x_447_;
v_posStx_412_ = v___x_476_;
v___y_413_ = v___y_289_;
v___y_414_ = v___y_290_;
goto v___jp_410_;
}
}
}
else
{
lean_object* v___x_477_; lean_object* v___x_478_; 
lean_dec(v_stx_287_);
lean_dec_ref(v___x_285_);
lean_dec_ref(v___x_284_);
v___x_477_ = lean_mk_empty_array_with_capacity(v___x_281_);
v___x_478_ = lean_box(0);
v_fst_382_ = v___x_477_;
v_snd_383_ = v___x_478_;
v___y_384_ = v___y_289_;
v___y_385_ = v___y_290_;
goto v___jp_381_;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2____boxed(lean_object* v___x_483_, lean_object* v___x_484_, lean_object* v___x_485_, lean_object* v___x_486_, lean_object* v___x_487_, lean_object* v_declName_488_, lean_object* v_stx_489_, lean_object* v_attrKind_490_, lean_object* v___y_491_, lean_object* v___y_492_, lean_object* v___y_493_){
_start:
{
uint8_t v_attrKind_boxed_494_; lean_object* v_res_495_; 
v_attrKind_boxed_494_ = lean_unbox(v_attrKind_490_);
v_res_495_ = lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__0_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_(v___x_483_, v___x_484_, v___x_485_, v___x_486_, v___x_487_, v_declName_488_, v_stx_489_, v_attrKind_boxed_494_, v___y_491_, v___y_492_);
lean_dec(v___y_492_);
lean_dec_ref(v___y_491_);
lean_dec(v___x_485_);
return v_res_495_;
}
}
static lean_object* _init_lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__1___closed__1_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_(void){
_start:
{
lean_object* v___x_497_; lean_object* v___x_498_; 
v___x_497_ = ((lean_object*)(lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__1___closed__0_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_));
v___x_498_ = l_Lean_stringToMessageData(v___x_497_);
return v___x_498_;
}
}
static lean_object* _init_lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__1___closed__3_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_(void){
_start:
{
lean_object* v___x_500_; lean_object* v___x_501_; 
v___x_500_ = ((lean_object*)(lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__1___closed__2_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_));
v___x_501_ = l_Lean_stringToMessageData(v___x_500_);
return v___x_501_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__1_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_(lean_object* v___x_502_, lean_object* v_decl_503_, lean_object* v___y_504_, lean_object* v___y_505_){
_start:
{
lean_object* v___x_507_; lean_object* v___x_508_; lean_object* v___x_509_; lean_object* v___x_510_; lean_object* v___x_511_; lean_object* v___x_512_; 
v___x_507_ = lean_obj_once(&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__1___closed__1_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_, &lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__1___closed__1_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__once, _init_lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__1___closed__1_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_);
v___x_508_ = l_Lean_MessageData_ofName(v___x_502_);
v___x_509_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_509_, 0, v___x_507_);
lean_ctor_set(v___x_509_, 1, v___x_508_);
v___x_510_ = lean_obj_once(&lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__1___closed__3_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_, &lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__1___closed__3_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__once, _init_lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__1___closed__3_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_);
v___x_511_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_511_, 0, v___x_509_);
lean_ctor_set(v___x_511_, 1, v___x_510_);
v___x_512_ = lp_JunkValues_Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0___redArg(v___x_511_, v___y_504_, v___y_505_);
return v___x_512_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__1_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2____boxed(lean_object* v___x_513_, lean_object* v_decl_514_, lean_object* v___y_515_, lean_object* v___y_516_, lean_object* v___y_517_){
_start:
{
lean_object* v_res_518_; 
v_res_518_ = lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___lam__1_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_(v___x_513_, v_decl_514_, v___y_515_, v___y_516_);
lean_dec(v___y_516_);
lean_dec_ref(v___y_515_);
lean_dec(v_decl_514_);
return v_res_518_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_(){
_start:
{
lean_object* v___x_585_; lean_object* v___x_586_; 
v___x_585_ = ((lean_object*)(lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn___closed__24_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_));
v___x_586_ = l_Lean_registerBuiltinAttribute(v___x_585_);
return v___x_586_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2____boxed(lean_object* v_a_587_){
_start:
{
lean_object* v_res_588_; 
v_res_588_ = lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_();
return v_res_588_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0(lean_object* v_00_u03b1_589_, lean_object* v_msg_590_, lean_object* v___y_591_, lean_object* v___y_592_){
_start:
{
lean_object* v___x_594_; 
v___x_594_ = lp_JunkValues_Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0___redArg(v_msg_590_, v___y_591_, v___y_592_);
return v___x_594_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0___boxed(lean_object* v_00_u03b1_595_, lean_object* v_msg_596_, lean_object* v___y_597_, lean_object* v___y_598_, lean_object* v___y_599_){
_start:
{
lean_object* v_res_600_; 
v_res_600_ = lp_JunkValues_Lean_throwError___at___00__private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2__spec__0(v_00_u03b1_595_, v_msg_596_, v___y_597_, v___y_598_);
lean_dec(v___y_598_);
lean_dec_ref(v___y_597_);
return v_res_600_;
}
}
lean_object* runtime_initialize_Init(uint8_t builtin);
lean_object* runtime_initialize_JunkValues_JunkValues_Rule(uint8_t builtin);
static bool _G_runtime_initialized = false;
LEAN_EXPORT lean_object* runtime_initialize_JunkValues_JunkValues_Registry(uint8_t builtin) {
lean_object * res;
if (_G_runtime_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_runtime_initialized = true;
res = runtime_initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = runtime_initialize_JunkValues_JunkValues_Rule(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_3288487679____hygCtx___hyg_2_();
if (lean_io_result_is_error(res)) return res;
lp_JunkValues_JunkValues_junkExt = lean_io_result_get_value(res);
lean_mark_persistent(lp_JunkValues_JunkValues_junkExt);
lean_dec_ref(res);
res = lp_JunkValues___private_JunkValues_Registry_0__JunkValues_initFn_00___x40_JunkValues_Registry_1664979221____hygCtx___hyg_2_();
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return lean_io_result_mk_ok(lean_box(0));
}
lean_object* runtime_initialize_Init(uint8_t builtin);
static bool _G_meta_initialized = false;
LEAN_EXPORT lean_object* meta_initialize_JunkValues_JunkValues_Registry(uint8_t builtin) {
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
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_JunkValues_JunkValues_Registry(uint8_t builtin) {
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
res = runtime_initialize_JunkValues_JunkValues_Registry(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = meta_initialize_JunkValues_JunkValues_Registry(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return initialize_JunkValues_JunkValues_Registry(builtin);
}
#ifdef __cplusplus
}
#endif
