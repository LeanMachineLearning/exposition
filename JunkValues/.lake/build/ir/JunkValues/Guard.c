// Lean compiler output
// Module: JunkValues.Guard
// Imports: public import Init public meta import Init public import Lean public import Lean.Elab.Tactic.Meta public import JunkValues.Report
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
uint8_t lean_usize_dec_lt(size_t, size_t);
size_t lean_usize_add(size_t, size_t);
lean_object* lean_array_uget(lean_object*, size_t);
uint8_t l_Lean_LocalDecl_isImplementationDetail(lean_object*);
lean_object* l_Lean_LocalDecl_type(lean_object*);
lean_object* l_Lean_Meta_isExprDefEq(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_LocalDecl_userName(lean_object*);
uint8_t l_Lean_Name_hasMacroScopes(lean_object*);
lean_object* l_Lean_Name_toStringWithToken___at___00Lean_Name_toString_spec__0(lean_object*, uint8_t);
lean_object* lean_string_append(lean_object*, lean_object*);
lean_object* l_Lean_Meta_mkFreshExprMVar(lean_object*, uint8_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_Expr_mvarId_x21(lean_object*);
lean_object* lean_mk_empty_array_with_capacity(lean_object*);
lean_object* l_Lean_Elab_runTactic(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
uint8_t l_Lean_Expr_hasMVar(lean_object*);
lean_object* lean_st_ref_get(lean_object*);
lean_object* l_Lean_instantiateMVarsCore(lean_object*, lean_object*);
lean_object* lean_st_ref_take(lean_object*);
lean_object* lean_st_ref_set(lean_object*, lean_object*);
uint8_t l_List_isEmpty___redArg(lean_object*);
uint8_t l_Lean_Expr_hasSorry(lean_object*);
lean_object* lean_array_uget_borrowed(lean_object*, size_t);
lean_object* l_Lean_Name_mkStr1(lean_object*);
lean_object* l_Lean_Expr_const___override(lean_object*, lean_object*);
lean_object* l_Lean_Expr_app___override(lean_object*, lean_object*);
uint8_t lean_string_dec_eq(lean_object*, lean_object*);
lean_object* l_Lean_Name_str___override(lean_object*, lean_object*);
lean_object* lean_array_push(lean_object*, lean_object*);
lean_object* l_Lean_mkAppN(lean_object*, lean_object*);
lean_object* l_Lean_Meta_saveState___redArg(lean_object*, lean_object*);
lean_object* l_Lean_Meta_SavedState_restore___redArg(lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_Parser_runParserCategory(lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l___private_Lean_CoreM_0__Lean_Core_withCurrHeartbeatsImp(lean_object*, lean_object*, lean_object*, lean_object*);
uint8_t l_Lean_Exception_isInterrupt(lean_object*);
uint8_t l_Lean_Exception_isRuntime(lean_object*);
size_t lean_array_size(lean_object*);
lean_object* lean_array_get_size(lean_object*);
uint8_t lean_nat_dec_eq(lean_object*, lean_object*);
lean_object* lean_array_to_list(lean_object*);
lean_object* l_List_reverse___redArg(lean_object*);
lean_object* l_String_intercalate(lean_object*, lean_object*);
static const lean_string_object lp_JunkValues_JunkValues_safetyGoal___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "Not"};
static const lean_object* lp_JunkValues_JunkValues_safetyGoal___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_safetyGoal___closed__0_value;
static const lean_ctor_object lp_JunkValues_JunkValues_safetyGoal___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_safetyGoal___closed__0_value),LEAN_SCALAR_PTR_LITERAL(185, 11, 203, 55, 27, 192, 137, 230)}};
static const lean_object* lp_JunkValues_JunkValues_safetyGoal___closed__1 = (const lean_object*)&lp_JunkValues_JunkValues_safetyGoal___closed__1_value;
static lean_once_cell_t lp_JunkValues_JunkValues_safetyGoal___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_safetyGoal___closed__2;
static const lean_string_object lp_JunkValues_JunkValues_safetyGoal___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "Ne"};
static const lean_object* lp_JunkValues_JunkValues_safetyGoal___closed__3 = (const lean_object*)&lp_JunkValues_JunkValues_safetyGoal___closed__3_value;
static const lean_string_object lp_JunkValues_JunkValues_safetyGoal___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "Eq"};
static const lean_object* lp_JunkValues_JunkValues_safetyGoal___closed__4 = (const lean_object*)&lp_JunkValues_JunkValues_safetyGoal___closed__4_value;
static const lean_ctor_object lp_JunkValues_JunkValues_safetyGoal___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_safetyGoal___closed__4_value),LEAN_SCALAR_PTR_LITERAL(143, 37, 101, 248, 9, 246, 191, 223)}};
static const lean_object* lp_JunkValues_JunkValues_safetyGoal___closed__5 = (const lean_object*)&lp_JunkValues_JunkValues_safetyGoal___closed__5_value;
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_safetyGoal(lean_object*);
static const lean_ctor_object lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forInAux___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__0_spec__2_spec__3___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forInAux___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__0_spec__2_spec__3___closed__0 = (const lean_object*)&lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forInAux___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__0_spec__2_spec__3___closed__0_value;
static const lean_string_object lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forInAux___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__0_spec__2_spec__3___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 13, .m_capacity = 13, .m_length = 12, .m_data = "hypothesis `"};
static const lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forInAux___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__0_spec__2_spec__3___closed__1 = (const lean_object*)&lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forInAux___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__0_spec__2_spec__3___closed__1_value;
static const lean_string_object lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forInAux___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__0_spec__2_spec__3___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 2, .m_capacity = 2, .m_length = 1, .m_data = "`"};
static const lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forInAux___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__0_spec__2_spec__3___closed__2 = (const lean_object*)&lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forInAux___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__0_spec__2_spec__3___closed__2_value;
static const lean_string_object lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forInAux___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__0_spec__2_spec__3___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 24, .m_capacity = 24, .m_length = 23, .m_data = "an anonymous hypothesis"};
static const lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forInAux___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__0_spec__2_spec__3___closed__3 = (const lean_object*)&lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forInAux___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__0_spec__2_spec__3___closed__3_value;
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forInAux___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__0_spec__2_spec__3(lean_object*, lean_object*, size_t, size_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forInAux___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__0_spec__2_spec__3___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forInAux___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__0_spec__2(lean_object*, lean_object*, size_t, size_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forInAux___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__0_spec__2___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentArray_forInAux___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__0(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forInAux___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__0_spec__1(lean_object*, lean_object*, lean_object*, size_t, size_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forInAux___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__0_spec__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentArray_forInAux___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_ctor_object lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__1_spec__4___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__1_spec__4___closed__0 = (const lean_object*)&lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__1_spec__4___closed__0_value;
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__1_spec__4(lean_object*, lean_object*, size_t, size_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__1_spec__4___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__1(lean_object*, lean_object*, size_t, size_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_ctor_object lp_JunkValues_JunkValues_assumptionDischarger___lam__0___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_JunkValues_JunkValues_assumptionDischarger___lam__0___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_assumptionDischarger___lam__0___closed__0_value;
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_assumptionDischarger___lam__0(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_assumptionDischarger___lam__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_closure_object lp_JunkValues_JunkValues_assumptionDischarger___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_JunkValues_JunkValues_assumptionDischarger___lam__0___boxed, .m_arity = 6, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_JunkValues_JunkValues_assumptionDischarger___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_assumptionDischarger___closed__0_value;
static const lean_string_object lp_JunkValues_JunkValues_assumptionDischarger___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "assumption"};
static const lean_object* lp_JunkValues_JunkValues_assumptionDischarger___closed__1 = (const lean_object*)&lp_JunkValues_JunkValues_assumptionDischarger___closed__1_value;
static const lean_ctor_object lp_JunkValues_JunkValues_assumptionDischarger___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_assumptionDischarger___closed__1_value),((lean_object*)&lp_JunkValues_JunkValues_assumptionDischarger___closed__0_value)}};
static const lean_object* lp_JunkValues_JunkValues_assumptionDischarger___closed__2 = (const lean_object*)&lp_JunkValues_JunkValues_assumptionDischarger___closed__2_value;
LEAN_EXPORT const lean_object* lp_JunkValues_JunkValues_assumptionDischarger = (const lean_object*)&lp_JunkValues_JunkValues_assumptionDischarger___closed__2_value;
LEAN_EXPORT lean_object* lp_JunkValues_Lean_instantiateMVars___at___00JunkValues_tacticDischarger_spec__0___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_instantiateMVars___at___00JunkValues_tacticDischarger_spec__0___redArg___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_instantiateMVars___at___00JunkValues_tacticDischarger_spec__0(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_instantiateMVars___at___00JunkValues_tacticDischarger_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Core_withCurrHeartbeats___at___00JunkValues_tacticDischarger_spec__1___redArg___lam__0(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Core_withCurrHeartbeats___at___00JunkValues_tacticDischarger_spec__1___redArg___lam__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Core_withCurrHeartbeats___at___00JunkValues_tacticDischarger_spec__1___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Core_withCurrHeartbeats___at___00JunkValues_tacticDischarger_spec__1___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Core_withCurrHeartbeats___at___00JunkValues_tacticDischarger_spec__1(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Core_withCurrHeartbeats___at___00JunkValues_tacticDischarger_spec__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_withoutModifyingState___at___00JunkValues_tacticDischarger_spec__2___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_withoutModifyingState___at___00JunkValues_tacticDischarger_spec__2___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_withoutModifyingState___at___00JunkValues_tacticDischarger_spec__2(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_withoutModifyingState___at___00JunkValues_tacticDischarger_spec__2___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_JunkValues_JunkValues_tacticDischarger___lam__0(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_tacticDischarger___lam__0___boxed(lean_object*);
static const lean_array_object lp_JunkValues_JunkValues_tacticDischarger___lam__1___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* lp_JunkValues_JunkValues_tacticDischarger___lam__1___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_tacticDischarger___lam__1___closed__0_value;
static const lean_ctor_object lp_JunkValues_JunkValues_tacticDischarger___lam__1___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*7 + 0, .m_other = 7, .m_tag = 0}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)(((size_t)(1) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)(((size_t)(1) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_JunkValues_JunkValues_tacticDischarger___lam__1___closed__1 = (const lean_object*)&lp_JunkValues_JunkValues_tacticDischarger___lam__1___closed__1_value;
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_tacticDischarger___lam__1(lean_object*, uint8_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_tacticDischarger___lam__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_tacticDischarger___lam__2(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_tacticDischarger___lam__2___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_tacticDischarger___lam__3(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_tacticDischarger___lam__3___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_closure_object lp_JunkValues_JunkValues_tacticDischarger___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_JunkValues_JunkValues_tacticDischarger___lam__0___boxed, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_JunkValues_JunkValues_tacticDischarger___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_tacticDischarger___closed__0_value;
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_tacticDischarger(lean_object*, lean_object*);
static const lean_string_object lp_JunkValues_JunkValues_tacticDischarger_x3f___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "tactic"};
static const lean_object* lp_JunkValues_JunkValues_tacticDischarger_x3f___redArg___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_tacticDischarger_x3f___redArg___closed__0_value;
static const lean_ctor_object lp_JunkValues_JunkValues_tacticDischarger_x3f___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_tacticDischarger_x3f___redArg___closed__0_value),LEAN_SCALAR_PTR_LITERAL(99, 76, 33, 121, 85, 143, 17, 224)}};
static const lean_object* lp_JunkValues_JunkValues_tacticDischarger_x3f___redArg___closed__1 = (const lean_object*)&lp_JunkValues_JunkValues_tacticDischarger_x3f___redArg___closed__1_value;
static const lean_string_object lp_JunkValues_JunkValues_tacticDischarger_x3f___redArg___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "<input>"};
static const lean_object* lp_JunkValues_JunkValues_tacticDischarger_x3f___redArg___closed__2 = (const lean_object*)&lp_JunkValues_JunkValues_tacticDischarger_x3f___redArg___closed__2_value;
static const lean_string_object lp_JunkValues_JunkValues_tacticDischarger_x3f___redArg___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 18, .m_capacity = 18, .m_length = 17, .m_data = "could not parse `"};
static const lean_object* lp_JunkValues_JunkValues_tacticDischarger_x3f___redArg___closed__3 = (const lean_object*)&lp_JunkValues_JunkValues_tacticDischarger_x3f___redArg___closed__3_value;
static const lean_string_object lp_JunkValues_JunkValues_tacticDischarger_x3f___redArg___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 16, .m_capacity = 16, .m_length = 15, .m_data = "` as a tactic: "};
static const lean_object* lp_JunkValues_JunkValues_tacticDischarger_x3f___redArg___closed__4 = (const lean_object*)&lp_JunkValues_JunkValues_tacticDischarger_x3f___redArg___closed__4_value;
static const lean_string_object lp_JunkValues_JunkValues_tacticDischarger_x3f___redArg___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 105, .m_capacity = 105, .m_length = 104, .m_data = ". If this is a Mathlib tactic (`fun_prop`, `measurability`), the project being scanned has to import it."};
static const lean_object* lp_JunkValues_JunkValues_tacticDischarger_x3f___redArg___closed__5 = (const lean_object*)&lp_JunkValues_JunkValues_tacticDischarger_x3f___redArg___closed__5_value;
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_tacticDischarger_x3f___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_tacticDischarger_x3f___redArg___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_tacticDischarger_x3f(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_tacticDischarger_x3f___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_firstDischarger_spec__0(lean_object*, lean_object*, size_t, size_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_firstDischarger_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_firstDischarger___lam__0(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_firstDischarger___lam__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_List_mapTR_loop___at___00JunkValues_firstDischarger_spec__1(lean_object*, lean_object*);
static const lean_string_object lp_JunkValues_JunkValues_firstDischarger___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = " / "};
static const lean_object* lp_JunkValues_JunkValues_firstDischarger___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_firstDischarger___closed__0_value;
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_firstDischarger(lean_object*);
static const lean_ctor_object lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_classify_spec__0___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_classify_spec__0___closed__0 = (const lean_object*)&lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_classify_spec__0___closed__0_value;
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_classify_spec__0(lean_object*, lean_object*, size_t, size_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_classify_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_ctor_object lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_classify_spec__1___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(1) << 1) | 1))}};
static const lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_classify_spec__1___closed__0 = (const lean_object*)&lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_classify_spec__1___closed__0_value;
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_classify_spec__1(lean_object*, lean_object*, size_t, size_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_classify_spec__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_ctor_object lp_JunkValues_JunkValues_classify___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_JunkValues_JunkValues_classify___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_classify___closed__0_value;
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_classify(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_classify___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static lean_object* _init_lp_JunkValues_JunkValues_safetyGoal___closed__2(void){
_start:
{
lean_object* v___x_4_; lean_object* v___x_5_; lean_object* v___x_6_; 
v___x_4_ = lean_box(0);
v___x_5_ = ((lean_object*)(lp_JunkValues_JunkValues_safetyGoal___closed__1));
v___x_6_ = l_Lean_Expr_const___override(v___x_5_, v___x_4_);
return v___x_6_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_safetyGoal(lean_object* v_guard_11_){
_start:
{
lean_object* v_g_13_; 
if (lean_obj_tag(v_guard_11_) == 5)
{
lean_object* v_fn_16_; 
v_fn_16_ = lean_ctor_get(v_guard_11_, 0);
switch(lean_obj_tag(v_fn_16_))
{
case 4:
{
lean_object* v_declName_17_; 
v_declName_17_ = lean_ctor_get(v_fn_16_, 0);
if (lean_obj_tag(v_declName_17_) == 1)
{
lean_object* v_pre_18_; 
v_pre_18_ = lean_ctor_get(v_declName_17_, 0);
if (lean_obj_tag(v_pre_18_) == 0)
{
lean_object* v_arg_19_; lean_object* v_us_20_; lean_object* v_str_21_; lean_object* v___x_22_; uint8_t v___x_23_; 
v_arg_19_ = lean_ctor_get(v_guard_11_, 1);
v_us_20_ = lean_ctor_get(v_fn_16_, 1);
v_str_21_ = lean_ctor_get(v_declName_17_, 1);
v___x_22_ = ((lean_object*)(lp_JunkValues_JunkValues_safetyGoal___closed__0));
v___x_23_ = lean_string_dec_eq(v_str_21_, v___x_22_);
if (v___x_23_ == 0)
{
v_g_13_ = v_guard_11_;
goto v___jp_12_;
}
else
{
lean_inc(v_us_20_);
lean_inc(v_pre_18_);
lean_inc_ref(v_arg_19_);
lean_dec_ref_known(v_guard_11_, 2);
if (lean_obj_tag(v_us_20_) == 0)
{
return v_arg_19_;
}
else
{
lean_object* v___x_24_; lean_object* v___x_25_; lean_object* v___x_26_; 
v___x_24_ = l_Lean_Name_str___override(v_pre_18_, v___x_22_);
v___x_25_ = l_Lean_Expr_const___override(v___x_24_, v_us_20_);
v___x_26_ = l_Lean_Expr_app___override(v___x_25_, v_arg_19_);
v_g_13_ = v___x_26_;
goto v___jp_12_;
}
}
}
else
{
v_g_13_ = v_guard_11_;
goto v___jp_12_;
}
}
else
{
v_g_13_ = v_guard_11_;
goto v___jp_12_;
}
}
case 5:
{
lean_object* v_fn_27_; 
v_fn_27_ = lean_ctor_get(v_fn_16_, 0);
if (lean_obj_tag(v_fn_27_) == 5)
{
lean_object* v_fn_28_; 
v_fn_28_ = lean_ctor_get(v_fn_27_, 0);
if (lean_obj_tag(v_fn_28_) == 4)
{
lean_object* v_declName_29_; 
v_declName_29_ = lean_ctor_get(v_fn_28_, 0);
if (lean_obj_tag(v_declName_29_) == 1)
{
lean_object* v_pre_30_; 
v_pre_30_ = lean_ctor_get(v_declName_29_, 0);
if (lean_obj_tag(v_pre_30_) == 0)
{
lean_object* v_arg_31_; lean_object* v_arg_32_; lean_object* v_arg_33_; lean_object* v_us_34_; lean_object* v_str_35_; lean_object* v___x_36_; uint8_t v___x_37_; 
v_arg_31_ = lean_ctor_get(v_guard_11_, 1);
v_arg_32_ = lean_ctor_get(v_fn_16_, 1);
v_arg_33_ = lean_ctor_get(v_fn_27_, 1);
v_us_34_ = lean_ctor_get(v_fn_28_, 1);
v_str_35_ = lean_ctor_get(v_declName_29_, 1);
v___x_36_ = ((lean_object*)(lp_JunkValues_JunkValues_safetyGoal___closed__3));
v___x_37_ = lean_string_dec_eq(v_str_35_, v___x_36_);
if (v___x_37_ == 0)
{
v_g_13_ = v_guard_11_;
goto v___jp_12_;
}
else
{
lean_object* v___x_38_; lean_object* v___x_39_; lean_object* v___x_40_; lean_object* v___x_41_; lean_object* v___x_42_; lean_object* v___x_43_; lean_object* v___x_44_; lean_object* v___x_45_; 
lean_inc(v_us_34_);
lean_inc_ref(v_arg_33_);
lean_inc_ref(v_arg_32_);
lean_inc_ref(v_arg_31_);
lean_dec_ref_known(v_guard_11_, 2);
v___x_38_ = ((lean_object*)(lp_JunkValues_JunkValues_safetyGoal___closed__5));
v___x_39_ = l_Lean_Expr_const___override(v___x_38_, v_us_34_);
v___x_40_ = lean_unsigned_to_nat(3u);
v___x_41_ = lean_mk_empty_array_with_capacity(v___x_40_);
v___x_42_ = lean_array_push(v___x_41_, v_arg_33_);
v___x_43_ = lean_array_push(v___x_42_, v_arg_32_);
v___x_44_ = lean_array_push(v___x_43_, v_arg_31_);
v___x_45_ = l_Lean_mkAppN(v___x_39_, v___x_44_);
lean_dec_ref(v___x_44_);
return v___x_45_;
}
}
else
{
v_g_13_ = v_guard_11_;
goto v___jp_12_;
}
}
else
{
v_g_13_ = v_guard_11_;
goto v___jp_12_;
}
}
else
{
v_g_13_ = v_guard_11_;
goto v___jp_12_;
}
}
else
{
v_g_13_ = v_guard_11_;
goto v___jp_12_;
}
}
default: 
{
v_g_13_ = v_guard_11_;
goto v___jp_12_;
}
}
}
else
{
v_g_13_ = v_guard_11_;
goto v___jp_12_;
}
v___jp_12_:
{
lean_object* v___x_14_; lean_object* v___x_15_; 
v___x_14_ = lean_obj_once(&lp_JunkValues_JunkValues_safetyGoal___closed__2, &lp_JunkValues_JunkValues_safetyGoal___closed__2_once, _init_lp_JunkValues_JunkValues_safetyGoal___closed__2);
v___x_15_ = l_Lean_Expr_app___override(v___x_14_, v_g_13_);
return v___x_15_;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forInAux___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__0_spec__2_spec__3(lean_object* v_goal_52_, lean_object* v_as_53_, size_t v_sz_54_, size_t v_i_55_, lean_object* v_b_56_, lean_object* v___y_57_, lean_object* v___y_58_, lean_object* v___y_59_, lean_object* v___y_60_){
_start:
{
uint8_t v___x_62_; 
v___x_62_ = lean_usize_dec_lt(v_i_55_, v_sz_54_);
if (v___x_62_ == 0)
{
lean_object* v___x_63_; 
lean_dec_ref(v_goal_52_);
v___x_63_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_63_, 0, v_b_56_);
return v___x_63_;
}
else
{
lean_object* v_snd_64_; lean_object* v___x_66_; uint8_t v_isShared_67_; uint8_t v_isSharedCheck_124_; 
v_snd_64_ = lean_ctor_get(v_b_56_, 1);
v_isSharedCheck_124_ = !lean_is_exclusive(v_b_56_);
if (v_isSharedCheck_124_ == 0)
{
lean_object* v_unused_125_; 
v_unused_125_ = lean_ctor_get(v_b_56_, 0);
lean_dec(v_unused_125_);
v___x_66_ = v_b_56_;
v_isShared_67_ = v_isSharedCheck_124_;
goto v_resetjp_65_;
}
else
{
lean_inc(v_snd_64_);
lean_dec(v_b_56_);
v___x_66_ = lean_box(0);
v_isShared_67_ = v_isSharedCheck_124_;
goto v_resetjp_65_;
}
v_resetjp_65_:
{
lean_object* v___x_68_; lean_object* v_a_70_; lean_object* v_a_77_; 
v___x_68_ = lean_box(0);
v_a_77_ = lean_array_uget(v_as_53_, v_i_55_);
if (lean_obj_tag(v_a_77_) == 0)
{
v_a_70_ = v_snd_64_;
goto v___jp_69_;
}
else
{
lean_object* v_val_78_; lean_object* v___x_80_; uint8_t v_isShared_81_; uint8_t v_isSharedCheck_123_; 
v_val_78_ = lean_ctor_get(v_a_77_, 0);
v_isSharedCheck_123_ = !lean_is_exclusive(v_a_77_);
if (v_isSharedCheck_123_ == 0)
{
v___x_80_ = v_a_77_;
v_isShared_81_ = v_isSharedCheck_123_;
goto v_resetjp_79_;
}
else
{
lean_inc(v_val_78_);
lean_dec(v_a_77_);
v___x_80_ = lean_box(0);
v_isShared_81_ = v_isSharedCheck_123_;
goto v_resetjp_79_;
}
v_resetjp_79_:
{
lean_object* v___x_82_; lean_object* v___x_83_; uint8_t v___x_84_; 
v___x_82_ = lean_box(0);
v___x_83_ = ((lean_object*)(lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forInAux___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__0_spec__2_spec__3___closed__0));
v___x_84_ = l_Lean_LocalDecl_isImplementationDetail(v_val_78_);
if (v___x_84_ == 0)
{
lean_object* v___x_85_; lean_object* v___x_86_; 
v___x_85_ = l_Lean_LocalDecl_type(v_val_78_);
lean_inc_ref(v_goal_52_);
v___x_86_ = l_Lean_Meta_isExprDefEq(v___x_85_, v_goal_52_, v___y_57_, v___y_58_, v___y_59_, v___y_60_);
if (lean_obj_tag(v___x_86_) == 0)
{
lean_object* v_a_87_; lean_object* v___x_89_; uint8_t v_isShared_90_; uint8_t v_isSharedCheck_114_; 
v_a_87_ = lean_ctor_get(v___x_86_, 0);
v_isSharedCheck_114_ = !lean_is_exclusive(v___x_86_);
if (v_isSharedCheck_114_ == 0)
{
v___x_89_ = v___x_86_;
v_isShared_90_ = v_isSharedCheck_114_;
goto v_resetjp_88_;
}
else
{
lean_inc(v_a_87_);
lean_dec(v___x_86_);
v___x_89_ = lean_box(0);
v_isShared_90_ = v_isSharedCheck_114_;
goto v_resetjp_88_;
}
v_resetjp_88_:
{
lean_object* v___y_92_; uint8_t v___x_104_; 
v___x_104_ = lean_unbox(v_a_87_);
if (v___x_104_ == 0)
{
lean_del_object(v___x_89_);
lean_dec(v_a_87_);
lean_del_object(v___x_80_);
lean_dec(v_val_78_);
lean_dec(v_snd_64_);
v_a_70_ = v___x_83_;
goto v___jp_69_;
}
else
{
lean_object* v___x_105_; uint8_t v___x_106_; 
lean_del_object(v___x_66_);
lean_dec_ref(v_goal_52_);
v___x_105_ = l_Lean_LocalDecl_userName(v_val_78_);
lean_dec(v_val_78_);
v___x_106_ = l_Lean_Name_hasMacroScopes(v___x_105_);
if (v___x_106_ == 0)
{
lean_object* v___x_107_; uint8_t v___x_108_; lean_object* v___x_109_; lean_object* v___x_110_; lean_object* v___x_111_; lean_object* v___x_112_; 
v___x_107_ = ((lean_object*)(lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forInAux___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__0_spec__2_spec__3___closed__1));
v___x_108_ = lean_unbox(v_a_87_);
lean_dec(v_a_87_);
v___x_109_ = l_Lean_Name_toStringWithToken___at___00Lean_Name_toString_spec__0(v___x_105_, v___x_108_);
v___x_110_ = lean_string_append(v___x_107_, v___x_109_);
lean_dec_ref(v___x_109_);
v___x_111_ = ((lean_object*)(lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forInAux___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__0_spec__2_spec__3___closed__2));
v___x_112_ = lean_string_append(v___x_110_, v___x_111_);
v___y_92_ = v___x_112_;
goto v___jp_91_;
}
else
{
lean_object* v___x_113_; 
lean_dec(v___x_105_);
lean_dec(v_a_87_);
v___x_113_ = ((lean_object*)(lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forInAux___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__0_spec__2_spec__3___closed__3));
v___y_92_ = v___x_113_;
goto v___jp_91_;
}
}
v___jp_91_:
{
lean_object* v___x_94_; 
if (v_isShared_81_ == 0)
{
lean_ctor_set(v___x_80_, 0, v___y_92_);
v___x_94_ = v___x_80_;
goto v_reusejp_93_;
}
else
{
lean_object* v_reuseFailAlloc_103_; 
v_reuseFailAlloc_103_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_103_, 0, v___y_92_);
v___x_94_ = v_reuseFailAlloc_103_;
goto v_reusejp_93_;
}
v_reusejp_93_:
{
lean_object* v___x_95_; lean_object* v___x_96_; lean_object* v___x_97_; lean_object* v___x_98_; lean_object* v___x_99_; lean_object* v___x_101_; 
v___x_95_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_95_, 0, v___x_94_);
v___x_96_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_96_, 0, v___x_95_);
lean_ctor_set(v___x_96_, 1, v___x_82_);
v___x_97_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_97_, 0, v___x_96_);
v___x_98_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_98_, 0, v___x_97_);
v___x_99_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_99_, 0, v___x_98_);
lean_ctor_set(v___x_99_, 1, v_snd_64_);
if (v_isShared_90_ == 0)
{
lean_ctor_set(v___x_89_, 0, v___x_99_);
v___x_101_ = v___x_89_;
goto v_reusejp_100_;
}
else
{
lean_object* v_reuseFailAlloc_102_; 
v_reuseFailAlloc_102_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_102_, 0, v___x_99_);
v___x_101_ = v_reuseFailAlloc_102_;
goto v_reusejp_100_;
}
v_reusejp_100_:
{
return v___x_101_;
}
}
}
}
}
else
{
lean_object* v_a_115_; lean_object* v___x_117_; uint8_t v_isShared_118_; uint8_t v_isSharedCheck_122_; 
lean_del_object(v___x_80_);
lean_dec(v_val_78_);
lean_del_object(v___x_66_);
lean_dec(v_snd_64_);
lean_dec_ref(v_goal_52_);
v_a_115_ = lean_ctor_get(v___x_86_, 0);
v_isSharedCheck_122_ = !lean_is_exclusive(v___x_86_);
if (v_isSharedCheck_122_ == 0)
{
v___x_117_ = v___x_86_;
v_isShared_118_ = v_isSharedCheck_122_;
goto v_resetjp_116_;
}
else
{
lean_inc(v_a_115_);
lean_dec(v___x_86_);
v___x_117_ = lean_box(0);
v_isShared_118_ = v_isSharedCheck_122_;
goto v_resetjp_116_;
}
v_resetjp_116_:
{
lean_object* v___x_120_; 
if (v_isShared_118_ == 0)
{
v___x_120_ = v___x_117_;
goto v_reusejp_119_;
}
else
{
lean_object* v_reuseFailAlloc_121_; 
v_reuseFailAlloc_121_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_121_, 0, v_a_115_);
v___x_120_ = v_reuseFailAlloc_121_;
goto v_reusejp_119_;
}
v_reusejp_119_:
{
return v___x_120_;
}
}
}
}
else
{
lean_del_object(v___x_80_);
lean_dec(v_val_78_);
lean_dec(v_snd_64_);
v_a_70_ = v___x_83_;
goto v___jp_69_;
}
}
}
v___jp_69_:
{
lean_object* v___x_72_; 
if (v_isShared_67_ == 0)
{
lean_ctor_set(v___x_66_, 1, v_a_70_);
lean_ctor_set(v___x_66_, 0, v___x_68_);
v___x_72_ = v___x_66_;
goto v_reusejp_71_;
}
else
{
lean_object* v_reuseFailAlloc_76_; 
v_reuseFailAlloc_76_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_76_, 0, v___x_68_);
lean_ctor_set(v_reuseFailAlloc_76_, 1, v_a_70_);
v___x_72_ = v_reuseFailAlloc_76_;
goto v_reusejp_71_;
}
v_reusejp_71_:
{
size_t v___x_73_; size_t v___x_74_; 
v___x_73_ = ((size_t)1ULL);
v___x_74_ = lean_usize_add(v_i_55_, v___x_73_);
v_i_55_ = v___x_74_;
v_b_56_ = v___x_72_;
goto _start;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forInAux___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__0_spec__2_spec__3___boxed(lean_object* v_goal_126_, lean_object* v_as_127_, lean_object* v_sz_128_, lean_object* v_i_129_, lean_object* v_b_130_, lean_object* v___y_131_, lean_object* v___y_132_, lean_object* v___y_133_, lean_object* v___y_134_, lean_object* v___y_135_){
_start:
{
size_t v_sz_boxed_136_; size_t v_i_boxed_137_; lean_object* v_res_138_; 
v_sz_boxed_136_ = lean_unbox_usize(v_sz_128_);
lean_dec(v_sz_128_);
v_i_boxed_137_ = lean_unbox_usize(v_i_129_);
lean_dec(v_i_129_);
v_res_138_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forInAux___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__0_spec__2_spec__3(v_goal_126_, v_as_127_, v_sz_boxed_136_, v_i_boxed_137_, v_b_130_, v___y_131_, v___y_132_, v___y_133_, v___y_134_);
lean_dec(v___y_134_);
lean_dec_ref(v___y_133_);
lean_dec(v___y_132_);
lean_dec_ref(v___y_131_);
lean_dec_ref(v_as_127_);
return v_res_138_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forInAux___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__0_spec__2(lean_object* v_goal_139_, lean_object* v_as_140_, size_t v_sz_141_, size_t v_i_142_, lean_object* v_b_143_, lean_object* v___y_144_, lean_object* v___y_145_, lean_object* v___y_146_, lean_object* v___y_147_){
_start:
{
uint8_t v___x_149_; 
v___x_149_ = lean_usize_dec_lt(v_i_142_, v_sz_141_);
if (v___x_149_ == 0)
{
lean_object* v___x_150_; 
lean_dec_ref(v_goal_139_);
v___x_150_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_150_, 0, v_b_143_);
return v___x_150_;
}
else
{
lean_object* v_snd_151_; lean_object* v___x_153_; uint8_t v_isShared_154_; uint8_t v_isSharedCheck_211_; 
v_snd_151_ = lean_ctor_get(v_b_143_, 1);
v_isSharedCheck_211_ = !lean_is_exclusive(v_b_143_);
if (v_isSharedCheck_211_ == 0)
{
lean_object* v_unused_212_; 
v_unused_212_ = lean_ctor_get(v_b_143_, 0);
lean_dec(v_unused_212_);
v___x_153_ = v_b_143_;
v_isShared_154_ = v_isSharedCheck_211_;
goto v_resetjp_152_;
}
else
{
lean_inc(v_snd_151_);
lean_dec(v_b_143_);
v___x_153_ = lean_box(0);
v_isShared_154_ = v_isSharedCheck_211_;
goto v_resetjp_152_;
}
v_resetjp_152_:
{
lean_object* v___x_155_; lean_object* v_a_157_; lean_object* v_a_164_; 
v___x_155_ = lean_box(0);
v_a_164_ = lean_array_uget(v_as_140_, v_i_142_);
if (lean_obj_tag(v_a_164_) == 0)
{
v_a_157_ = v_snd_151_;
goto v___jp_156_;
}
else
{
lean_object* v_val_165_; lean_object* v___x_167_; uint8_t v_isShared_168_; uint8_t v_isSharedCheck_210_; 
v_val_165_ = lean_ctor_get(v_a_164_, 0);
v_isSharedCheck_210_ = !lean_is_exclusive(v_a_164_);
if (v_isSharedCheck_210_ == 0)
{
v___x_167_ = v_a_164_;
v_isShared_168_ = v_isSharedCheck_210_;
goto v_resetjp_166_;
}
else
{
lean_inc(v_val_165_);
lean_dec(v_a_164_);
v___x_167_ = lean_box(0);
v_isShared_168_ = v_isSharedCheck_210_;
goto v_resetjp_166_;
}
v_resetjp_166_:
{
lean_object* v___x_169_; lean_object* v___x_170_; uint8_t v___x_171_; 
v___x_169_ = lean_box(0);
v___x_170_ = ((lean_object*)(lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forInAux___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__0_spec__2_spec__3___closed__0));
v___x_171_ = l_Lean_LocalDecl_isImplementationDetail(v_val_165_);
if (v___x_171_ == 0)
{
lean_object* v___x_172_; lean_object* v___x_173_; 
v___x_172_ = l_Lean_LocalDecl_type(v_val_165_);
lean_inc_ref(v_goal_139_);
v___x_173_ = l_Lean_Meta_isExprDefEq(v___x_172_, v_goal_139_, v___y_144_, v___y_145_, v___y_146_, v___y_147_);
if (lean_obj_tag(v___x_173_) == 0)
{
lean_object* v_a_174_; lean_object* v___x_176_; uint8_t v_isShared_177_; uint8_t v_isSharedCheck_201_; 
v_a_174_ = lean_ctor_get(v___x_173_, 0);
v_isSharedCheck_201_ = !lean_is_exclusive(v___x_173_);
if (v_isSharedCheck_201_ == 0)
{
v___x_176_ = v___x_173_;
v_isShared_177_ = v_isSharedCheck_201_;
goto v_resetjp_175_;
}
else
{
lean_inc(v_a_174_);
lean_dec(v___x_173_);
v___x_176_ = lean_box(0);
v_isShared_177_ = v_isSharedCheck_201_;
goto v_resetjp_175_;
}
v_resetjp_175_:
{
lean_object* v___y_179_; uint8_t v___x_191_; 
v___x_191_ = lean_unbox(v_a_174_);
if (v___x_191_ == 0)
{
lean_del_object(v___x_176_);
lean_dec(v_a_174_);
lean_del_object(v___x_167_);
lean_dec(v_val_165_);
lean_dec(v_snd_151_);
v_a_157_ = v___x_170_;
goto v___jp_156_;
}
else
{
lean_object* v___x_192_; uint8_t v___x_193_; 
lean_del_object(v___x_153_);
lean_dec_ref(v_goal_139_);
v___x_192_ = l_Lean_LocalDecl_userName(v_val_165_);
lean_dec(v_val_165_);
v___x_193_ = l_Lean_Name_hasMacroScopes(v___x_192_);
if (v___x_193_ == 0)
{
lean_object* v___x_194_; uint8_t v___x_195_; lean_object* v___x_196_; lean_object* v___x_197_; lean_object* v___x_198_; lean_object* v___x_199_; 
v___x_194_ = ((lean_object*)(lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forInAux___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__0_spec__2_spec__3___closed__1));
v___x_195_ = lean_unbox(v_a_174_);
lean_dec(v_a_174_);
v___x_196_ = l_Lean_Name_toStringWithToken___at___00Lean_Name_toString_spec__0(v___x_192_, v___x_195_);
v___x_197_ = lean_string_append(v___x_194_, v___x_196_);
lean_dec_ref(v___x_196_);
v___x_198_ = ((lean_object*)(lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forInAux___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__0_spec__2_spec__3___closed__2));
v___x_199_ = lean_string_append(v___x_197_, v___x_198_);
v___y_179_ = v___x_199_;
goto v___jp_178_;
}
else
{
lean_object* v___x_200_; 
lean_dec(v___x_192_);
lean_dec(v_a_174_);
v___x_200_ = ((lean_object*)(lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forInAux___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__0_spec__2_spec__3___closed__3));
v___y_179_ = v___x_200_;
goto v___jp_178_;
}
}
v___jp_178_:
{
lean_object* v___x_181_; 
if (v_isShared_168_ == 0)
{
lean_ctor_set(v___x_167_, 0, v___y_179_);
v___x_181_ = v___x_167_;
goto v_reusejp_180_;
}
else
{
lean_object* v_reuseFailAlloc_190_; 
v_reuseFailAlloc_190_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_190_, 0, v___y_179_);
v___x_181_ = v_reuseFailAlloc_190_;
goto v_reusejp_180_;
}
v_reusejp_180_:
{
lean_object* v___x_182_; lean_object* v___x_183_; lean_object* v___x_184_; lean_object* v___x_185_; lean_object* v___x_186_; lean_object* v___x_188_; 
v___x_182_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_182_, 0, v___x_181_);
v___x_183_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_183_, 0, v___x_182_);
lean_ctor_set(v___x_183_, 1, v___x_169_);
v___x_184_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_184_, 0, v___x_183_);
v___x_185_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_185_, 0, v___x_184_);
v___x_186_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_186_, 0, v___x_185_);
lean_ctor_set(v___x_186_, 1, v_snd_151_);
if (v_isShared_177_ == 0)
{
lean_ctor_set(v___x_176_, 0, v___x_186_);
v___x_188_ = v___x_176_;
goto v_reusejp_187_;
}
else
{
lean_object* v_reuseFailAlloc_189_; 
v_reuseFailAlloc_189_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_189_, 0, v___x_186_);
v___x_188_ = v_reuseFailAlloc_189_;
goto v_reusejp_187_;
}
v_reusejp_187_:
{
return v___x_188_;
}
}
}
}
}
else
{
lean_object* v_a_202_; lean_object* v___x_204_; uint8_t v_isShared_205_; uint8_t v_isSharedCheck_209_; 
lean_del_object(v___x_167_);
lean_dec(v_val_165_);
lean_del_object(v___x_153_);
lean_dec(v_snd_151_);
lean_dec_ref(v_goal_139_);
v_a_202_ = lean_ctor_get(v___x_173_, 0);
v_isSharedCheck_209_ = !lean_is_exclusive(v___x_173_);
if (v_isSharedCheck_209_ == 0)
{
v___x_204_ = v___x_173_;
v_isShared_205_ = v_isSharedCheck_209_;
goto v_resetjp_203_;
}
else
{
lean_inc(v_a_202_);
lean_dec(v___x_173_);
v___x_204_ = lean_box(0);
v_isShared_205_ = v_isSharedCheck_209_;
goto v_resetjp_203_;
}
v_resetjp_203_:
{
lean_object* v___x_207_; 
if (v_isShared_205_ == 0)
{
v___x_207_ = v___x_204_;
goto v_reusejp_206_;
}
else
{
lean_object* v_reuseFailAlloc_208_; 
v_reuseFailAlloc_208_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_208_, 0, v_a_202_);
v___x_207_ = v_reuseFailAlloc_208_;
goto v_reusejp_206_;
}
v_reusejp_206_:
{
return v___x_207_;
}
}
}
}
else
{
lean_del_object(v___x_167_);
lean_dec(v_val_165_);
lean_dec(v_snd_151_);
v_a_157_ = v___x_170_;
goto v___jp_156_;
}
}
}
v___jp_156_:
{
lean_object* v___x_159_; 
if (v_isShared_154_ == 0)
{
lean_ctor_set(v___x_153_, 1, v_a_157_);
lean_ctor_set(v___x_153_, 0, v___x_155_);
v___x_159_ = v___x_153_;
goto v_reusejp_158_;
}
else
{
lean_object* v_reuseFailAlloc_163_; 
v_reuseFailAlloc_163_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_163_, 0, v___x_155_);
lean_ctor_set(v_reuseFailAlloc_163_, 1, v_a_157_);
v___x_159_ = v_reuseFailAlloc_163_;
goto v_reusejp_158_;
}
v_reusejp_158_:
{
size_t v___x_160_; size_t v___x_161_; lean_object* v___x_162_; 
v___x_160_ = ((size_t)1ULL);
v___x_161_ = lean_usize_add(v_i_142_, v___x_160_);
v___x_162_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forInAux___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__0_spec__2_spec__3(v_goal_139_, v_as_140_, v_sz_141_, v___x_161_, v___x_159_, v___y_144_, v___y_145_, v___y_146_, v___y_147_);
return v___x_162_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forInAux___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__0_spec__2___boxed(lean_object* v_goal_213_, lean_object* v_as_214_, lean_object* v_sz_215_, lean_object* v_i_216_, lean_object* v_b_217_, lean_object* v___y_218_, lean_object* v___y_219_, lean_object* v___y_220_, lean_object* v___y_221_, lean_object* v___y_222_){
_start:
{
size_t v_sz_boxed_223_; size_t v_i_boxed_224_; lean_object* v_res_225_; 
v_sz_boxed_223_ = lean_unbox_usize(v_sz_215_);
lean_dec(v_sz_215_);
v_i_boxed_224_ = lean_unbox_usize(v_i_216_);
lean_dec(v_i_216_);
v_res_225_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forInAux___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__0_spec__2(v_goal_213_, v_as_214_, v_sz_boxed_223_, v_i_boxed_224_, v_b_217_, v___y_218_, v___y_219_, v___y_220_, v___y_221_);
lean_dec(v___y_221_);
lean_dec_ref(v___y_220_);
lean_dec(v___y_219_);
lean_dec_ref(v___y_218_);
lean_dec_ref(v_as_214_);
return v_res_225_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentArray_forInAux___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__0(lean_object* v_init_226_, lean_object* v_goal_227_, lean_object* v_n_228_, lean_object* v_b_229_, lean_object* v___y_230_, lean_object* v___y_231_, lean_object* v___y_232_, lean_object* v___y_233_){
_start:
{
if (lean_obj_tag(v_n_228_) == 0)
{
lean_object* v_cs_235_; lean_object* v___x_236_; lean_object* v___x_237_; size_t v_sz_238_; size_t v___x_239_; lean_object* v___x_240_; 
v_cs_235_ = lean_ctor_get(v_n_228_, 0);
v___x_236_ = lean_box(0);
v___x_237_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_237_, 0, v___x_236_);
lean_ctor_set(v___x_237_, 1, v_b_229_);
v_sz_238_ = lean_array_size(v_cs_235_);
v___x_239_ = ((size_t)0ULL);
v___x_240_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forInAux___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__0_spec__1(v_init_226_, v_goal_227_, v_cs_235_, v_sz_238_, v___x_239_, v___x_237_, v___y_230_, v___y_231_, v___y_232_, v___y_233_);
if (lean_obj_tag(v___x_240_) == 0)
{
lean_object* v_a_241_; lean_object* v___x_243_; uint8_t v_isShared_244_; uint8_t v_isSharedCheck_255_; 
v_a_241_ = lean_ctor_get(v___x_240_, 0);
v_isSharedCheck_255_ = !lean_is_exclusive(v___x_240_);
if (v_isSharedCheck_255_ == 0)
{
v___x_243_ = v___x_240_;
v_isShared_244_ = v_isSharedCheck_255_;
goto v_resetjp_242_;
}
else
{
lean_inc(v_a_241_);
lean_dec(v___x_240_);
v___x_243_ = lean_box(0);
v_isShared_244_ = v_isSharedCheck_255_;
goto v_resetjp_242_;
}
v_resetjp_242_:
{
lean_object* v_fst_245_; 
v_fst_245_ = lean_ctor_get(v_a_241_, 0);
if (lean_obj_tag(v_fst_245_) == 0)
{
lean_object* v_snd_246_; lean_object* v___x_247_; lean_object* v___x_249_; 
v_snd_246_ = lean_ctor_get(v_a_241_, 1);
lean_inc(v_snd_246_);
lean_dec(v_a_241_);
v___x_247_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_247_, 0, v_snd_246_);
if (v_isShared_244_ == 0)
{
lean_ctor_set(v___x_243_, 0, v___x_247_);
v___x_249_ = v___x_243_;
goto v_reusejp_248_;
}
else
{
lean_object* v_reuseFailAlloc_250_; 
v_reuseFailAlloc_250_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_250_, 0, v___x_247_);
v___x_249_ = v_reuseFailAlloc_250_;
goto v_reusejp_248_;
}
v_reusejp_248_:
{
return v___x_249_;
}
}
else
{
lean_object* v_val_251_; lean_object* v___x_253_; 
lean_inc_ref(v_fst_245_);
lean_dec(v_a_241_);
v_val_251_ = lean_ctor_get(v_fst_245_, 0);
lean_inc(v_val_251_);
lean_dec_ref_known(v_fst_245_, 1);
if (v_isShared_244_ == 0)
{
lean_ctor_set(v___x_243_, 0, v_val_251_);
v___x_253_ = v___x_243_;
goto v_reusejp_252_;
}
else
{
lean_object* v_reuseFailAlloc_254_; 
v_reuseFailAlloc_254_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_254_, 0, v_val_251_);
v___x_253_ = v_reuseFailAlloc_254_;
goto v_reusejp_252_;
}
v_reusejp_252_:
{
return v___x_253_;
}
}
}
}
else
{
lean_object* v_a_256_; lean_object* v___x_258_; uint8_t v_isShared_259_; uint8_t v_isSharedCheck_263_; 
v_a_256_ = lean_ctor_get(v___x_240_, 0);
v_isSharedCheck_263_ = !lean_is_exclusive(v___x_240_);
if (v_isSharedCheck_263_ == 0)
{
v___x_258_ = v___x_240_;
v_isShared_259_ = v_isSharedCheck_263_;
goto v_resetjp_257_;
}
else
{
lean_inc(v_a_256_);
lean_dec(v___x_240_);
v___x_258_ = lean_box(0);
v_isShared_259_ = v_isSharedCheck_263_;
goto v_resetjp_257_;
}
v_resetjp_257_:
{
lean_object* v___x_261_; 
if (v_isShared_259_ == 0)
{
v___x_261_ = v___x_258_;
goto v_reusejp_260_;
}
else
{
lean_object* v_reuseFailAlloc_262_; 
v_reuseFailAlloc_262_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_262_, 0, v_a_256_);
v___x_261_ = v_reuseFailAlloc_262_;
goto v_reusejp_260_;
}
v_reusejp_260_:
{
return v___x_261_;
}
}
}
}
else
{
lean_object* v_vs_264_; lean_object* v___x_265_; lean_object* v___x_266_; size_t v_sz_267_; size_t v___x_268_; lean_object* v___x_269_; 
v_vs_264_ = lean_ctor_get(v_n_228_, 0);
v___x_265_ = lean_box(0);
v___x_266_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_266_, 0, v___x_265_);
lean_ctor_set(v___x_266_, 1, v_b_229_);
v_sz_267_ = lean_array_size(v_vs_264_);
v___x_268_ = ((size_t)0ULL);
v___x_269_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forInAux___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__0_spec__2(v_goal_227_, v_vs_264_, v_sz_267_, v___x_268_, v___x_266_, v___y_230_, v___y_231_, v___y_232_, v___y_233_);
if (lean_obj_tag(v___x_269_) == 0)
{
lean_object* v_a_270_; lean_object* v___x_272_; uint8_t v_isShared_273_; uint8_t v_isSharedCheck_284_; 
v_a_270_ = lean_ctor_get(v___x_269_, 0);
v_isSharedCheck_284_ = !lean_is_exclusive(v___x_269_);
if (v_isSharedCheck_284_ == 0)
{
v___x_272_ = v___x_269_;
v_isShared_273_ = v_isSharedCheck_284_;
goto v_resetjp_271_;
}
else
{
lean_inc(v_a_270_);
lean_dec(v___x_269_);
v___x_272_ = lean_box(0);
v_isShared_273_ = v_isSharedCheck_284_;
goto v_resetjp_271_;
}
v_resetjp_271_:
{
lean_object* v_fst_274_; 
v_fst_274_ = lean_ctor_get(v_a_270_, 0);
if (lean_obj_tag(v_fst_274_) == 0)
{
lean_object* v_snd_275_; lean_object* v___x_276_; lean_object* v___x_278_; 
v_snd_275_ = lean_ctor_get(v_a_270_, 1);
lean_inc(v_snd_275_);
lean_dec(v_a_270_);
v___x_276_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_276_, 0, v_snd_275_);
if (v_isShared_273_ == 0)
{
lean_ctor_set(v___x_272_, 0, v___x_276_);
v___x_278_ = v___x_272_;
goto v_reusejp_277_;
}
else
{
lean_object* v_reuseFailAlloc_279_; 
v_reuseFailAlloc_279_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_279_, 0, v___x_276_);
v___x_278_ = v_reuseFailAlloc_279_;
goto v_reusejp_277_;
}
v_reusejp_277_:
{
return v___x_278_;
}
}
else
{
lean_object* v_val_280_; lean_object* v___x_282_; 
lean_inc_ref(v_fst_274_);
lean_dec(v_a_270_);
v_val_280_ = lean_ctor_get(v_fst_274_, 0);
lean_inc(v_val_280_);
lean_dec_ref_known(v_fst_274_, 1);
if (v_isShared_273_ == 0)
{
lean_ctor_set(v___x_272_, 0, v_val_280_);
v___x_282_ = v___x_272_;
goto v_reusejp_281_;
}
else
{
lean_object* v_reuseFailAlloc_283_; 
v_reuseFailAlloc_283_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_283_, 0, v_val_280_);
v___x_282_ = v_reuseFailAlloc_283_;
goto v_reusejp_281_;
}
v_reusejp_281_:
{
return v___x_282_;
}
}
}
}
else
{
lean_object* v_a_285_; lean_object* v___x_287_; uint8_t v_isShared_288_; uint8_t v_isSharedCheck_292_; 
v_a_285_ = lean_ctor_get(v___x_269_, 0);
v_isSharedCheck_292_ = !lean_is_exclusive(v___x_269_);
if (v_isSharedCheck_292_ == 0)
{
v___x_287_ = v___x_269_;
v_isShared_288_ = v_isSharedCheck_292_;
goto v_resetjp_286_;
}
else
{
lean_inc(v_a_285_);
lean_dec(v___x_269_);
v___x_287_ = lean_box(0);
v_isShared_288_ = v_isSharedCheck_292_;
goto v_resetjp_286_;
}
v_resetjp_286_:
{
lean_object* v___x_290_; 
if (v_isShared_288_ == 0)
{
v___x_290_ = v___x_287_;
goto v_reusejp_289_;
}
else
{
lean_object* v_reuseFailAlloc_291_; 
v_reuseFailAlloc_291_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_291_, 0, v_a_285_);
v___x_290_ = v_reuseFailAlloc_291_;
goto v_reusejp_289_;
}
v_reusejp_289_:
{
return v___x_290_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forInAux___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__0_spec__1(lean_object* v_init_293_, lean_object* v_goal_294_, lean_object* v_as_295_, size_t v_sz_296_, size_t v_i_297_, lean_object* v_b_298_, lean_object* v___y_299_, lean_object* v___y_300_, lean_object* v___y_301_, lean_object* v___y_302_){
_start:
{
uint8_t v___x_304_; 
v___x_304_ = lean_usize_dec_lt(v_i_297_, v_sz_296_);
if (v___x_304_ == 0)
{
lean_object* v___x_305_; 
lean_dec_ref(v_goal_294_);
v___x_305_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_305_, 0, v_b_298_);
return v___x_305_;
}
else
{
lean_object* v_snd_306_; lean_object* v___x_308_; uint8_t v_isShared_309_; uint8_t v_isSharedCheck_340_; 
v_snd_306_ = lean_ctor_get(v_b_298_, 1);
v_isSharedCheck_340_ = !lean_is_exclusive(v_b_298_);
if (v_isSharedCheck_340_ == 0)
{
lean_object* v_unused_341_; 
v_unused_341_ = lean_ctor_get(v_b_298_, 0);
lean_dec(v_unused_341_);
v___x_308_ = v_b_298_;
v_isShared_309_ = v_isSharedCheck_340_;
goto v_resetjp_307_;
}
else
{
lean_inc(v_snd_306_);
lean_dec(v_b_298_);
v___x_308_ = lean_box(0);
v_isShared_309_ = v_isSharedCheck_340_;
goto v_resetjp_307_;
}
v_resetjp_307_:
{
lean_object* v_a_310_; lean_object* v___x_311_; 
v_a_310_ = lean_array_uget_borrowed(v_as_295_, v_i_297_);
lean_inc(v_snd_306_);
lean_inc_ref(v_goal_294_);
v___x_311_ = lp_JunkValues_Lean_PersistentArray_forInAux___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__0(v_init_293_, v_goal_294_, v_a_310_, v_snd_306_, v___y_299_, v___y_300_, v___y_301_, v___y_302_);
if (lean_obj_tag(v___x_311_) == 0)
{
lean_object* v_a_312_; lean_object* v___x_314_; uint8_t v_isShared_315_; uint8_t v_isSharedCheck_331_; 
v_a_312_ = lean_ctor_get(v___x_311_, 0);
v_isSharedCheck_331_ = !lean_is_exclusive(v___x_311_);
if (v_isSharedCheck_331_ == 0)
{
v___x_314_ = v___x_311_;
v_isShared_315_ = v_isSharedCheck_331_;
goto v_resetjp_313_;
}
else
{
lean_inc(v_a_312_);
lean_dec(v___x_311_);
v___x_314_ = lean_box(0);
v_isShared_315_ = v_isSharedCheck_331_;
goto v_resetjp_313_;
}
v_resetjp_313_:
{
if (lean_obj_tag(v_a_312_) == 0)
{
lean_object* v___x_316_; lean_object* v___x_318_; 
lean_dec_ref(v_goal_294_);
v___x_316_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_316_, 0, v_a_312_);
if (v_isShared_309_ == 0)
{
lean_ctor_set(v___x_308_, 0, v___x_316_);
v___x_318_ = v___x_308_;
goto v_reusejp_317_;
}
else
{
lean_object* v_reuseFailAlloc_322_; 
v_reuseFailAlloc_322_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_322_, 0, v___x_316_);
lean_ctor_set(v_reuseFailAlloc_322_, 1, v_snd_306_);
v___x_318_ = v_reuseFailAlloc_322_;
goto v_reusejp_317_;
}
v_reusejp_317_:
{
lean_object* v___x_320_; 
if (v_isShared_315_ == 0)
{
lean_ctor_set(v___x_314_, 0, v___x_318_);
v___x_320_ = v___x_314_;
goto v_reusejp_319_;
}
else
{
lean_object* v_reuseFailAlloc_321_; 
v_reuseFailAlloc_321_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_321_, 0, v___x_318_);
v___x_320_ = v_reuseFailAlloc_321_;
goto v_reusejp_319_;
}
v_reusejp_319_:
{
return v___x_320_;
}
}
}
else
{
lean_object* v_a_323_; lean_object* v___x_324_; lean_object* v___x_326_; 
lean_del_object(v___x_314_);
lean_dec(v_snd_306_);
v_a_323_ = lean_ctor_get(v_a_312_, 0);
lean_inc(v_a_323_);
lean_dec_ref_known(v_a_312_, 1);
v___x_324_ = lean_box(0);
if (v_isShared_309_ == 0)
{
lean_ctor_set(v___x_308_, 1, v_a_323_);
lean_ctor_set(v___x_308_, 0, v___x_324_);
v___x_326_ = v___x_308_;
goto v_reusejp_325_;
}
else
{
lean_object* v_reuseFailAlloc_330_; 
v_reuseFailAlloc_330_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_330_, 0, v___x_324_);
lean_ctor_set(v_reuseFailAlloc_330_, 1, v_a_323_);
v___x_326_ = v_reuseFailAlloc_330_;
goto v_reusejp_325_;
}
v_reusejp_325_:
{
size_t v___x_327_; size_t v___x_328_; 
v___x_327_ = ((size_t)1ULL);
v___x_328_ = lean_usize_add(v_i_297_, v___x_327_);
v_i_297_ = v___x_328_;
v_b_298_ = v___x_326_;
goto _start;
}
}
}
}
else
{
lean_object* v_a_332_; lean_object* v___x_334_; uint8_t v_isShared_335_; uint8_t v_isSharedCheck_339_; 
lean_del_object(v___x_308_);
lean_dec(v_snd_306_);
lean_dec_ref(v_goal_294_);
v_a_332_ = lean_ctor_get(v___x_311_, 0);
v_isSharedCheck_339_ = !lean_is_exclusive(v___x_311_);
if (v_isSharedCheck_339_ == 0)
{
v___x_334_ = v___x_311_;
v_isShared_335_ = v_isSharedCheck_339_;
goto v_resetjp_333_;
}
else
{
lean_inc(v_a_332_);
lean_dec(v___x_311_);
v___x_334_ = lean_box(0);
v_isShared_335_ = v_isSharedCheck_339_;
goto v_resetjp_333_;
}
v_resetjp_333_:
{
lean_object* v___x_337_; 
if (v_isShared_335_ == 0)
{
v___x_337_ = v___x_334_;
goto v_reusejp_336_;
}
else
{
lean_object* v_reuseFailAlloc_338_; 
v_reuseFailAlloc_338_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_338_, 0, v_a_332_);
v___x_337_ = v_reuseFailAlloc_338_;
goto v_reusejp_336_;
}
v_reusejp_336_:
{
return v___x_337_;
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forInAux___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__0_spec__1___boxed(lean_object* v_init_342_, lean_object* v_goal_343_, lean_object* v_as_344_, lean_object* v_sz_345_, lean_object* v_i_346_, lean_object* v_b_347_, lean_object* v___y_348_, lean_object* v___y_349_, lean_object* v___y_350_, lean_object* v___y_351_, lean_object* v___y_352_){
_start:
{
size_t v_sz_boxed_353_; size_t v_i_boxed_354_; lean_object* v_res_355_; 
v_sz_boxed_353_ = lean_unbox_usize(v_sz_345_);
lean_dec(v_sz_345_);
v_i_boxed_354_ = lean_unbox_usize(v_i_346_);
lean_dec(v_i_346_);
v_res_355_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forInAux___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__0_spec__1(v_init_342_, v_goal_343_, v_as_344_, v_sz_boxed_353_, v_i_boxed_354_, v_b_347_, v___y_348_, v___y_349_, v___y_350_, v___y_351_);
lean_dec(v___y_351_);
lean_dec_ref(v___y_350_);
lean_dec(v___y_349_);
lean_dec_ref(v___y_348_);
lean_dec_ref(v_as_344_);
lean_dec_ref(v_init_342_);
return v_res_355_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentArray_forInAux___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__0___boxed(lean_object* v_init_356_, lean_object* v_goal_357_, lean_object* v_n_358_, lean_object* v_b_359_, lean_object* v___y_360_, lean_object* v___y_361_, lean_object* v___y_362_, lean_object* v___y_363_, lean_object* v___y_364_){
_start:
{
lean_object* v_res_365_; 
v_res_365_ = lp_JunkValues_Lean_PersistentArray_forInAux___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__0(v_init_356_, v_goal_357_, v_n_358_, v_b_359_, v___y_360_, v___y_361_, v___y_362_, v___y_363_);
lean_dec(v___y_363_);
lean_dec_ref(v___y_362_);
lean_dec(v___y_361_);
lean_dec_ref(v___y_360_);
lean_dec_ref(v_n_358_);
lean_dec_ref(v_init_356_);
return v_res_365_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__1_spec__4(lean_object* v_goal_369_, lean_object* v_as_370_, size_t v_sz_371_, size_t v_i_372_, lean_object* v_b_373_, lean_object* v___y_374_, lean_object* v___y_375_, lean_object* v___y_376_, lean_object* v___y_377_){
_start:
{
uint8_t v___x_379_; 
v___x_379_ = lean_usize_dec_lt(v_i_372_, v_sz_371_);
if (v___x_379_ == 0)
{
lean_object* v___x_380_; 
lean_dec_ref(v_goal_369_);
v___x_380_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_380_, 0, v_b_373_);
return v___x_380_;
}
else
{
lean_object* v_snd_381_; lean_object* v___x_383_; uint8_t v_isShared_384_; uint8_t v_isSharedCheck_440_; 
v_snd_381_ = lean_ctor_get(v_b_373_, 1);
v_isSharedCheck_440_ = !lean_is_exclusive(v_b_373_);
if (v_isSharedCheck_440_ == 0)
{
lean_object* v_unused_441_; 
v_unused_441_ = lean_ctor_get(v_b_373_, 0);
lean_dec(v_unused_441_);
v___x_383_ = v_b_373_;
v_isShared_384_ = v_isSharedCheck_440_;
goto v_resetjp_382_;
}
else
{
lean_inc(v_snd_381_);
lean_dec(v_b_373_);
v___x_383_ = lean_box(0);
v_isShared_384_ = v_isSharedCheck_440_;
goto v_resetjp_382_;
}
v_resetjp_382_:
{
lean_object* v___x_385_; lean_object* v_a_387_; lean_object* v_a_394_; 
v___x_385_ = lean_box(0);
v_a_394_ = lean_array_uget(v_as_370_, v_i_372_);
if (lean_obj_tag(v_a_394_) == 0)
{
v_a_387_ = v_snd_381_;
goto v___jp_386_;
}
else
{
lean_object* v_val_395_; lean_object* v___x_397_; uint8_t v_isShared_398_; uint8_t v_isSharedCheck_439_; 
v_val_395_ = lean_ctor_get(v_a_394_, 0);
v_isSharedCheck_439_ = !lean_is_exclusive(v_a_394_);
if (v_isSharedCheck_439_ == 0)
{
v___x_397_ = v_a_394_;
v_isShared_398_ = v_isSharedCheck_439_;
goto v_resetjp_396_;
}
else
{
lean_inc(v_val_395_);
lean_dec(v_a_394_);
v___x_397_ = lean_box(0);
v_isShared_398_ = v_isSharedCheck_439_;
goto v_resetjp_396_;
}
v_resetjp_396_:
{
lean_object* v___x_399_; lean_object* v___x_400_; uint8_t v___x_401_; 
v___x_399_ = lean_box(0);
v___x_400_ = ((lean_object*)(lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__1_spec__4___closed__0));
v___x_401_ = l_Lean_LocalDecl_isImplementationDetail(v_val_395_);
if (v___x_401_ == 0)
{
lean_object* v___x_402_; lean_object* v___x_403_; 
v___x_402_ = l_Lean_LocalDecl_type(v_val_395_);
lean_inc_ref(v_goal_369_);
v___x_403_ = l_Lean_Meta_isExprDefEq(v___x_402_, v_goal_369_, v___y_374_, v___y_375_, v___y_376_, v___y_377_);
if (lean_obj_tag(v___x_403_) == 0)
{
lean_object* v_a_404_; lean_object* v___x_406_; uint8_t v_isShared_407_; uint8_t v_isSharedCheck_430_; 
v_a_404_ = lean_ctor_get(v___x_403_, 0);
v_isSharedCheck_430_ = !lean_is_exclusive(v___x_403_);
if (v_isSharedCheck_430_ == 0)
{
v___x_406_ = v___x_403_;
v_isShared_407_ = v_isSharedCheck_430_;
goto v_resetjp_405_;
}
else
{
lean_inc(v_a_404_);
lean_dec(v___x_403_);
v___x_406_ = lean_box(0);
v_isShared_407_ = v_isSharedCheck_430_;
goto v_resetjp_405_;
}
v_resetjp_405_:
{
lean_object* v___y_409_; uint8_t v___x_420_; 
v___x_420_ = lean_unbox(v_a_404_);
if (v___x_420_ == 0)
{
lean_del_object(v___x_406_);
lean_dec(v_a_404_);
lean_del_object(v___x_397_);
lean_dec(v_val_395_);
lean_dec(v_snd_381_);
v_a_387_ = v___x_400_;
goto v___jp_386_;
}
else
{
lean_object* v___x_421_; uint8_t v___x_422_; 
lean_del_object(v___x_383_);
lean_dec_ref(v_goal_369_);
v___x_421_ = l_Lean_LocalDecl_userName(v_val_395_);
lean_dec(v_val_395_);
v___x_422_ = l_Lean_Name_hasMacroScopes(v___x_421_);
if (v___x_422_ == 0)
{
lean_object* v___x_423_; uint8_t v___x_424_; lean_object* v___x_425_; lean_object* v___x_426_; lean_object* v___x_427_; lean_object* v___x_428_; 
v___x_423_ = ((lean_object*)(lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forInAux___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__0_spec__2_spec__3___closed__1));
v___x_424_ = lean_unbox(v_a_404_);
lean_dec(v_a_404_);
v___x_425_ = l_Lean_Name_toStringWithToken___at___00Lean_Name_toString_spec__0(v___x_421_, v___x_424_);
v___x_426_ = lean_string_append(v___x_423_, v___x_425_);
lean_dec_ref(v___x_425_);
v___x_427_ = ((lean_object*)(lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forInAux___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__0_spec__2_spec__3___closed__2));
v___x_428_ = lean_string_append(v___x_426_, v___x_427_);
v___y_409_ = v___x_428_;
goto v___jp_408_;
}
else
{
lean_object* v___x_429_; 
lean_dec(v___x_421_);
lean_dec(v_a_404_);
v___x_429_ = ((lean_object*)(lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forInAux___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__0_spec__2_spec__3___closed__3));
v___y_409_ = v___x_429_;
goto v___jp_408_;
}
}
v___jp_408_:
{
lean_object* v___x_411_; 
if (v_isShared_398_ == 0)
{
lean_ctor_set(v___x_397_, 0, v___y_409_);
v___x_411_ = v___x_397_;
goto v_reusejp_410_;
}
else
{
lean_object* v_reuseFailAlloc_419_; 
v_reuseFailAlloc_419_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_419_, 0, v___y_409_);
v___x_411_ = v_reuseFailAlloc_419_;
goto v_reusejp_410_;
}
v_reusejp_410_:
{
lean_object* v___x_412_; lean_object* v___x_413_; lean_object* v___x_414_; lean_object* v___x_415_; lean_object* v___x_417_; 
v___x_412_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_412_, 0, v___x_411_);
v___x_413_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_413_, 0, v___x_412_);
lean_ctor_set(v___x_413_, 1, v___x_399_);
v___x_414_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_414_, 0, v___x_413_);
v___x_415_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_415_, 0, v___x_414_);
lean_ctor_set(v___x_415_, 1, v_snd_381_);
if (v_isShared_407_ == 0)
{
lean_ctor_set(v___x_406_, 0, v___x_415_);
v___x_417_ = v___x_406_;
goto v_reusejp_416_;
}
else
{
lean_object* v_reuseFailAlloc_418_; 
v_reuseFailAlloc_418_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_418_, 0, v___x_415_);
v___x_417_ = v_reuseFailAlloc_418_;
goto v_reusejp_416_;
}
v_reusejp_416_:
{
return v___x_417_;
}
}
}
}
}
else
{
lean_object* v_a_431_; lean_object* v___x_433_; uint8_t v_isShared_434_; uint8_t v_isSharedCheck_438_; 
lean_del_object(v___x_397_);
lean_dec(v_val_395_);
lean_del_object(v___x_383_);
lean_dec(v_snd_381_);
lean_dec_ref(v_goal_369_);
v_a_431_ = lean_ctor_get(v___x_403_, 0);
v_isSharedCheck_438_ = !lean_is_exclusive(v___x_403_);
if (v_isSharedCheck_438_ == 0)
{
v___x_433_ = v___x_403_;
v_isShared_434_ = v_isSharedCheck_438_;
goto v_resetjp_432_;
}
else
{
lean_inc(v_a_431_);
lean_dec(v___x_403_);
v___x_433_ = lean_box(0);
v_isShared_434_ = v_isSharedCheck_438_;
goto v_resetjp_432_;
}
v_resetjp_432_:
{
lean_object* v___x_436_; 
if (v_isShared_434_ == 0)
{
v___x_436_ = v___x_433_;
goto v_reusejp_435_;
}
else
{
lean_object* v_reuseFailAlloc_437_; 
v_reuseFailAlloc_437_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_437_, 0, v_a_431_);
v___x_436_ = v_reuseFailAlloc_437_;
goto v_reusejp_435_;
}
v_reusejp_435_:
{
return v___x_436_;
}
}
}
}
else
{
lean_del_object(v___x_397_);
lean_dec(v_val_395_);
lean_dec(v_snd_381_);
v_a_387_ = v___x_400_;
goto v___jp_386_;
}
}
}
v___jp_386_:
{
lean_object* v___x_389_; 
if (v_isShared_384_ == 0)
{
lean_ctor_set(v___x_383_, 1, v_a_387_);
lean_ctor_set(v___x_383_, 0, v___x_385_);
v___x_389_ = v___x_383_;
goto v_reusejp_388_;
}
else
{
lean_object* v_reuseFailAlloc_393_; 
v_reuseFailAlloc_393_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_393_, 0, v___x_385_);
lean_ctor_set(v_reuseFailAlloc_393_, 1, v_a_387_);
v___x_389_ = v_reuseFailAlloc_393_;
goto v_reusejp_388_;
}
v_reusejp_388_:
{
size_t v___x_390_; size_t v___x_391_; 
v___x_390_ = ((size_t)1ULL);
v___x_391_ = lean_usize_add(v_i_372_, v___x_390_);
v_i_372_ = v___x_391_;
v_b_373_ = v___x_389_;
goto _start;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__1_spec__4___boxed(lean_object* v_goal_442_, lean_object* v_as_443_, lean_object* v_sz_444_, lean_object* v_i_445_, lean_object* v_b_446_, lean_object* v___y_447_, lean_object* v___y_448_, lean_object* v___y_449_, lean_object* v___y_450_, lean_object* v___y_451_){
_start:
{
size_t v_sz_boxed_452_; size_t v_i_boxed_453_; lean_object* v_res_454_; 
v_sz_boxed_452_ = lean_unbox_usize(v_sz_444_);
lean_dec(v_sz_444_);
v_i_boxed_453_ = lean_unbox_usize(v_i_445_);
lean_dec(v_i_445_);
v_res_454_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__1_spec__4(v_goal_442_, v_as_443_, v_sz_boxed_452_, v_i_boxed_453_, v_b_446_, v___y_447_, v___y_448_, v___y_449_, v___y_450_);
lean_dec(v___y_450_);
lean_dec_ref(v___y_449_);
lean_dec(v___y_448_);
lean_dec_ref(v___y_447_);
lean_dec_ref(v_as_443_);
return v_res_454_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__1(lean_object* v_goal_455_, lean_object* v_as_456_, size_t v_sz_457_, size_t v_i_458_, lean_object* v_b_459_, lean_object* v___y_460_, lean_object* v___y_461_, lean_object* v___y_462_, lean_object* v___y_463_){
_start:
{
uint8_t v___x_465_; 
v___x_465_ = lean_usize_dec_lt(v_i_458_, v_sz_457_);
if (v___x_465_ == 0)
{
lean_object* v___x_466_; 
lean_dec_ref(v_goal_455_);
v___x_466_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_466_, 0, v_b_459_);
return v___x_466_;
}
else
{
lean_object* v_snd_467_; lean_object* v___x_469_; uint8_t v_isShared_470_; uint8_t v_isSharedCheck_526_; 
v_snd_467_ = lean_ctor_get(v_b_459_, 1);
v_isSharedCheck_526_ = !lean_is_exclusive(v_b_459_);
if (v_isSharedCheck_526_ == 0)
{
lean_object* v_unused_527_; 
v_unused_527_ = lean_ctor_get(v_b_459_, 0);
lean_dec(v_unused_527_);
v___x_469_ = v_b_459_;
v_isShared_470_ = v_isSharedCheck_526_;
goto v_resetjp_468_;
}
else
{
lean_inc(v_snd_467_);
lean_dec(v_b_459_);
v___x_469_ = lean_box(0);
v_isShared_470_ = v_isSharedCheck_526_;
goto v_resetjp_468_;
}
v_resetjp_468_:
{
lean_object* v___x_471_; lean_object* v_a_473_; lean_object* v_a_480_; 
v___x_471_ = lean_box(0);
v_a_480_ = lean_array_uget(v_as_456_, v_i_458_);
if (lean_obj_tag(v_a_480_) == 0)
{
v_a_473_ = v_snd_467_;
goto v___jp_472_;
}
else
{
lean_object* v_val_481_; lean_object* v___x_483_; uint8_t v_isShared_484_; uint8_t v_isSharedCheck_525_; 
v_val_481_ = lean_ctor_get(v_a_480_, 0);
v_isSharedCheck_525_ = !lean_is_exclusive(v_a_480_);
if (v_isSharedCheck_525_ == 0)
{
v___x_483_ = v_a_480_;
v_isShared_484_ = v_isSharedCheck_525_;
goto v_resetjp_482_;
}
else
{
lean_inc(v_val_481_);
lean_dec(v_a_480_);
v___x_483_ = lean_box(0);
v_isShared_484_ = v_isSharedCheck_525_;
goto v_resetjp_482_;
}
v_resetjp_482_:
{
lean_object* v___x_485_; lean_object* v___x_486_; uint8_t v___x_487_; 
v___x_485_ = lean_box(0);
v___x_486_ = ((lean_object*)(lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__1_spec__4___closed__0));
v___x_487_ = l_Lean_LocalDecl_isImplementationDetail(v_val_481_);
if (v___x_487_ == 0)
{
lean_object* v___x_488_; lean_object* v___x_489_; 
v___x_488_ = l_Lean_LocalDecl_type(v_val_481_);
lean_inc_ref(v_goal_455_);
v___x_489_ = l_Lean_Meta_isExprDefEq(v___x_488_, v_goal_455_, v___y_460_, v___y_461_, v___y_462_, v___y_463_);
if (lean_obj_tag(v___x_489_) == 0)
{
lean_object* v_a_490_; lean_object* v___x_492_; uint8_t v_isShared_493_; uint8_t v_isSharedCheck_516_; 
v_a_490_ = lean_ctor_get(v___x_489_, 0);
v_isSharedCheck_516_ = !lean_is_exclusive(v___x_489_);
if (v_isSharedCheck_516_ == 0)
{
v___x_492_ = v___x_489_;
v_isShared_493_ = v_isSharedCheck_516_;
goto v_resetjp_491_;
}
else
{
lean_inc(v_a_490_);
lean_dec(v___x_489_);
v___x_492_ = lean_box(0);
v_isShared_493_ = v_isSharedCheck_516_;
goto v_resetjp_491_;
}
v_resetjp_491_:
{
lean_object* v___y_495_; uint8_t v___x_506_; 
v___x_506_ = lean_unbox(v_a_490_);
if (v___x_506_ == 0)
{
lean_del_object(v___x_492_);
lean_dec(v_a_490_);
lean_del_object(v___x_483_);
lean_dec(v_val_481_);
lean_dec(v_snd_467_);
v_a_473_ = v___x_486_;
goto v___jp_472_;
}
else
{
lean_object* v___x_507_; uint8_t v___x_508_; 
lean_del_object(v___x_469_);
lean_dec_ref(v_goal_455_);
v___x_507_ = l_Lean_LocalDecl_userName(v_val_481_);
lean_dec(v_val_481_);
v___x_508_ = l_Lean_Name_hasMacroScopes(v___x_507_);
if (v___x_508_ == 0)
{
lean_object* v___x_509_; uint8_t v___x_510_; lean_object* v___x_511_; lean_object* v___x_512_; lean_object* v___x_513_; lean_object* v___x_514_; 
v___x_509_ = ((lean_object*)(lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forInAux___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__0_spec__2_spec__3___closed__1));
v___x_510_ = lean_unbox(v_a_490_);
lean_dec(v_a_490_);
v___x_511_ = l_Lean_Name_toStringWithToken___at___00Lean_Name_toString_spec__0(v___x_507_, v___x_510_);
v___x_512_ = lean_string_append(v___x_509_, v___x_511_);
lean_dec_ref(v___x_511_);
v___x_513_ = ((lean_object*)(lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forInAux___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__0_spec__2_spec__3___closed__2));
v___x_514_ = lean_string_append(v___x_512_, v___x_513_);
v___y_495_ = v___x_514_;
goto v___jp_494_;
}
else
{
lean_object* v___x_515_; 
lean_dec(v___x_507_);
lean_dec(v_a_490_);
v___x_515_ = ((lean_object*)(lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forInAux___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__0_spec__2_spec__3___closed__3));
v___y_495_ = v___x_515_;
goto v___jp_494_;
}
}
v___jp_494_:
{
lean_object* v___x_497_; 
if (v_isShared_484_ == 0)
{
lean_ctor_set(v___x_483_, 0, v___y_495_);
v___x_497_ = v___x_483_;
goto v_reusejp_496_;
}
else
{
lean_object* v_reuseFailAlloc_505_; 
v_reuseFailAlloc_505_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_505_, 0, v___y_495_);
v___x_497_ = v_reuseFailAlloc_505_;
goto v_reusejp_496_;
}
v_reusejp_496_:
{
lean_object* v___x_498_; lean_object* v___x_499_; lean_object* v___x_500_; lean_object* v___x_501_; lean_object* v___x_503_; 
v___x_498_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_498_, 0, v___x_497_);
v___x_499_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_499_, 0, v___x_498_);
lean_ctor_set(v___x_499_, 1, v___x_485_);
v___x_500_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_500_, 0, v___x_499_);
v___x_501_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_501_, 0, v___x_500_);
lean_ctor_set(v___x_501_, 1, v_snd_467_);
if (v_isShared_493_ == 0)
{
lean_ctor_set(v___x_492_, 0, v___x_501_);
v___x_503_ = v___x_492_;
goto v_reusejp_502_;
}
else
{
lean_object* v_reuseFailAlloc_504_; 
v_reuseFailAlloc_504_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_504_, 0, v___x_501_);
v___x_503_ = v_reuseFailAlloc_504_;
goto v_reusejp_502_;
}
v_reusejp_502_:
{
return v___x_503_;
}
}
}
}
}
else
{
lean_object* v_a_517_; lean_object* v___x_519_; uint8_t v_isShared_520_; uint8_t v_isSharedCheck_524_; 
lean_del_object(v___x_483_);
lean_dec(v_val_481_);
lean_del_object(v___x_469_);
lean_dec(v_snd_467_);
lean_dec_ref(v_goal_455_);
v_a_517_ = lean_ctor_get(v___x_489_, 0);
v_isSharedCheck_524_ = !lean_is_exclusive(v___x_489_);
if (v_isSharedCheck_524_ == 0)
{
v___x_519_ = v___x_489_;
v_isShared_520_ = v_isSharedCheck_524_;
goto v_resetjp_518_;
}
else
{
lean_inc(v_a_517_);
lean_dec(v___x_489_);
v___x_519_ = lean_box(0);
v_isShared_520_ = v_isSharedCheck_524_;
goto v_resetjp_518_;
}
v_resetjp_518_:
{
lean_object* v___x_522_; 
if (v_isShared_520_ == 0)
{
v___x_522_ = v___x_519_;
goto v_reusejp_521_;
}
else
{
lean_object* v_reuseFailAlloc_523_; 
v_reuseFailAlloc_523_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_523_, 0, v_a_517_);
v___x_522_ = v_reuseFailAlloc_523_;
goto v_reusejp_521_;
}
v_reusejp_521_:
{
return v___x_522_;
}
}
}
}
else
{
lean_del_object(v___x_483_);
lean_dec(v_val_481_);
lean_dec(v_snd_467_);
v_a_473_ = v___x_486_;
goto v___jp_472_;
}
}
}
v___jp_472_:
{
lean_object* v___x_475_; 
if (v_isShared_470_ == 0)
{
lean_ctor_set(v___x_469_, 1, v_a_473_);
lean_ctor_set(v___x_469_, 0, v___x_471_);
v___x_475_ = v___x_469_;
goto v_reusejp_474_;
}
else
{
lean_object* v_reuseFailAlloc_479_; 
v_reuseFailAlloc_479_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_479_, 0, v___x_471_);
lean_ctor_set(v_reuseFailAlloc_479_, 1, v_a_473_);
v___x_475_ = v_reuseFailAlloc_479_;
goto v_reusejp_474_;
}
v_reusejp_474_:
{
size_t v___x_476_; size_t v___x_477_; lean_object* v___x_478_; 
v___x_476_ = ((size_t)1ULL);
v___x_477_ = lean_usize_add(v_i_458_, v___x_476_);
v___x_478_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__1_spec__4(v_goal_455_, v_as_456_, v_sz_457_, v___x_477_, v___x_475_, v___y_460_, v___y_461_, v___y_462_, v___y_463_);
return v___x_478_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__1___boxed(lean_object* v_goal_528_, lean_object* v_as_529_, lean_object* v_sz_530_, lean_object* v_i_531_, lean_object* v_b_532_, lean_object* v___y_533_, lean_object* v___y_534_, lean_object* v___y_535_, lean_object* v___y_536_, lean_object* v___y_537_){
_start:
{
size_t v_sz_boxed_538_; size_t v_i_boxed_539_; lean_object* v_res_540_; 
v_sz_boxed_538_ = lean_unbox_usize(v_sz_530_);
lean_dec(v_sz_530_);
v_i_boxed_539_ = lean_unbox_usize(v_i_531_);
lean_dec(v_i_531_);
v_res_540_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__1(v_goal_528_, v_as_529_, v_sz_boxed_538_, v_i_boxed_539_, v_b_532_, v___y_533_, v___y_534_, v___y_535_, v___y_536_);
lean_dec(v___y_536_);
lean_dec_ref(v___y_535_);
lean_dec(v___y_534_);
lean_dec_ref(v___y_533_);
lean_dec_ref(v_as_529_);
return v_res_540_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0(lean_object* v_goal_541_, lean_object* v_t_542_, lean_object* v_init_543_, lean_object* v___y_544_, lean_object* v___y_545_, lean_object* v___y_546_, lean_object* v___y_547_){
_start:
{
lean_object* v_root_549_; lean_object* v_tail_550_; lean_object* v___x_551_; 
v_root_549_ = lean_ctor_get(v_t_542_, 0);
v_tail_550_ = lean_ctor_get(v_t_542_, 1);
lean_inc_ref(v_goal_541_);
lean_inc_ref(v_init_543_);
v___x_551_ = lp_JunkValues_Lean_PersistentArray_forInAux___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__0(v_init_543_, v_goal_541_, v_root_549_, v_init_543_, v___y_544_, v___y_545_, v___y_546_, v___y_547_);
lean_dec_ref(v_init_543_);
if (lean_obj_tag(v___x_551_) == 0)
{
lean_object* v_a_552_; lean_object* v___x_554_; uint8_t v_isShared_555_; uint8_t v_isSharedCheck_588_; 
v_a_552_ = lean_ctor_get(v___x_551_, 0);
v_isSharedCheck_588_ = !lean_is_exclusive(v___x_551_);
if (v_isSharedCheck_588_ == 0)
{
v___x_554_ = v___x_551_;
v_isShared_555_ = v_isSharedCheck_588_;
goto v_resetjp_553_;
}
else
{
lean_inc(v_a_552_);
lean_dec(v___x_551_);
v___x_554_ = lean_box(0);
v_isShared_555_ = v_isSharedCheck_588_;
goto v_resetjp_553_;
}
v_resetjp_553_:
{
if (lean_obj_tag(v_a_552_) == 0)
{
lean_object* v_a_556_; lean_object* v___x_558_; 
lean_dec_ref(v_goal_541_);
v_a_556_ = lean_ctor_get(v_a_552_, 0);
lean_inc(v_a_556_);
lean_dec_ref_known(v_a_552_, 1);
if (v_isShared_555_ == 0)
{
lean_ctor_set(v___x_554_, 0, v_a_556_);
v___x_558_ = v___x_554_;
goto v_reusejp_557_;
}
else
{
lean_object* v_reuseFailAlloc_559_; 
v_reuseFailAlloc_559_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_559_, 0, v_a_556_);
v___x_558_ = v_reuseFailAlloc_559_;
goto v_reusejp_557_;
}
v_reusejp_557_:
{
return v___x_558_;
}
}
else
{
lean_object* v_a_560_; lean_object* v___x_561_; lean_object* v___x_562_; size_t v_sz_563_; size_t v___x_564_; lean_object* v___x_565_; 
lean_del_object(v___x_554_);
v_a_560_ = lean_ctor_get(v_a_552_, 0);
lean_inc(v_a_560_);
lean_dec_ref_known(v_a_552_, 1);
v___x_561_ = lean_box(0);
v___x_562_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_562_, 0, v___x_561_);
lean_ctor_set(v___x_562_, 1, v_a_560_);
v_sz_563_ = lean_array_size(v_tail_550_);
v___x_564_ = ((size_t)0ULL);
v___x_565_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0_spec__1(v_goal_541_, v_tail_550_, v_sz_563_, v___x_564_, v___x_562_, v___y_544_, v___y_545_, v___y_546_, v___y_547_);
if (lean_obj_tag(v___x_565_) == 0)
{
lean_object* v_a_566_; lean_object* v___x_568_; uint8_t v_isShared_569_; uint8_t v_isSharedCheck_579_; 
v_a_566_ = lean_ctor_get(v___x_565_, 0);
v_isSharedCheck_579_ = !lean_is_exclusive(v___x_565_);
if (v_isSharedCheck_579_ == 0)
{
v___x_568_ = v___x_565_;
v_isShared_569_ = v_isSharedCheck_579_;
goto v_resetjp_567_;
}
else
{
lean_inc(v_a_566_);
lean_dec(v___x_565_);
v___x_568_ = lean_box(0);
v_isShared_569_ = v_isSharedCheck_579_;
goto v_resetjp_567_;
}
v_resetjp_567_:
{
lean_object* v_fst_570_; 
v_fst_570_ = lean_ctor_get(v_a_566_, 0);
if (lean_obj_tag(v_fst_570_) == 0)
{
lean_object* v_snd_571_; lean_object* v___x_573_; 
v_snd_571_ = lean_ctor_get(v_a_566_, 1);
lean_inc(v_snd_571_);
lean_dec(v_a_566_);
if (v_isShared_569_ == 0)
{
lean_ctor_set(v___x_568_, 0, v_snd_571_);
v___x_573_ = v___x_568_;
goto v_reusejp_572_;
}
else
{
lean_object* v_reuseFailAlloc_574_; 
v_reuseFailAlloc_574_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_574_, 0, v_snd_571_);
v___x_573_ = v_reuseFailAlloc_574_;
goto v_reusejp_572_;
}
v_reusejp_572_:
{
return v___x_573_;
}
}
else
{
lean_object* v_val_575_; lean_object* v___x_577_; 
lean_inc_ref(v_fst_570_);
lean_dec(v_a_566_);
v_val_575_ = lean_ctor_get(v_fst_570_, 0);
lean_inc(v_val_575_);
lean_dec_ref_known(v_fst_570_, 1);
if (v_isShared_569_ == 0)
{
lean_ctor_set(v___x_568_, 0, v_val_575_);
v___x_577_ = v___x_568_;
goto v_reusejp_576_;
}
else
{
lean_object* v_reuseFailAlloc_578_; 
v_reuseFailAlloc_578_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_578_, 0, v_val_575_);
v___x_577_ = v_reuseFailAlloc_578_;
goto v_reusejp_576_;
}
v_reusejp_576_:
{
return v___x_577_;
}
}
}
}
else
{
lean_object* v_a_580_; lean_object* v___x_582_; uint8_t v_isShared_583_; uint8_t v_isSharedCheck_587_; 
v_a_580_ = lean_ctor_get(v___x_565_, 0);
v_isSharedCheck_587_ = !lean_is_exclusive(v___x_565_);
if (v_isSharedCheck_587_ == 0)
{
v___x_582_ = v___x_565_;
v_isShared_583_ = v_isSharedCheck_587_;
goto v_resetjp_581_;
}
else
{
lean_inc(v_a_580_);
lean_dec(v___x_565_);
v___x_582_ = lean_box(0);
v_isShared_583_ = v_isSharedCheck_587_;
goto v_resetjp_581_;
}
v_resetjp_581_:
{
lean_object* v___x_585_; 
if (v_isShared_583_ == 0)
{
v___x_585_ = v___x_582_;
goto v_reusejp_584_;
}
else
{
lean_object* v_reuseFailAlloc_586_; 
v_reuseFailAlloc_586_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_586_, 0, v_a_580_);
v___x_585_ = v_reuseFailAlloc_586_;
goto v_reusejp_584_;
}
v_reusejp_584_:
{
return v___x_585_;
}
}
}
}
}
}
else
{
lean_object* v_a_589_; lean_object* v___x_591_; uint8_t v_isShared_592_; uint8_t v_isSharedCheck_596_; 
lean_dec_ref(v_goal_541_);
v_a_589_ = lean_ctor_get(v___x_551_, 0);
v_isSharedCheck_596_ = !lean_is_exclusive(v___x_551_);
if (v_isSharedCheck_596_ == 0)
{
v___x_591_ = v___x_551_;
v_isShared_592_ = v_isSharedCheck_596_;
goto v_resetjp_590_;
}
else
{
lean_inc(v_a_589_);
lean_dec(v___x_551_);
v___x_591_ = lean_box(0);
v_isShared_592_ = v_isSharedCheck_596_;
goto v_resetjp_590_;
}
v_resetjp_590_:
{
lean_object* v___x_594_; 
if (v_isShared_592_ == 0)
{
v___x_594_ = v___x_591_;
goto v_reusejp_593_;
}
else
{
lean_object* v_reuseFailAlloc_595_; 
v_reuseFailAlloc_595_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_595_, 0, v_a_589_);
v___x_594_ = v_reuseFailAlloc_595_;
goto v_reusejp_593_;
}
v_reusejp_593_:
{
return v___x_594_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0___boxed(lean_object* v_goal_597_, lean_object* v_t_598_, lean_object* v_init_599_, lean_object* v___y_600_, lean_object* v___y_601_, lean_object* v___y_602_, lean_object* v___y_603_, lean_object* v___y_604_){
_start:
{
lean_object* v_res_605_; 
v_res_605_ = lp_JunkValues_Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0(v_goal_597_, v_t_598_, v_init_599_, v___y_600_, v___y_601_, v___y_602_, v___y_603_);
lean_dec(v___y_603_);
lean_dec_ref(v___y_602_);
lean_dec(v___y_601_);
lean_dec_ref(v___y_600_);
lean_dec_ref(v_t_598_);
return v_res_605_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_assumptionDischarger___lam__0(lean_object* v_goal_609_, lean_object* v___y_610_, lean_object* v___y_611_, lean_object* v___y_612_, lean_object* v___y_613_){
_start:
{
lean_object* v_lctx_615_; lean_object* v_decls_616_; lean_object* v___x_617_; lean_object* v___x_618_; lean_object* v___x_619_; 
v_lctx_615_ = lean_ctor_get(v___y_610_, 2);
v_decls_616_ = lean_ctor_get(v_lctx_615_, 1);
v___x_617_ = lean_box(0);
v___x_618_ = ((lean_object*)(lp_JunkValues_JunkValues_assumptionDischarger___lam__0___closed__0));
v___x_619_ = lp_JunkValues_Lean_PersistentArray_forIn___at___00JunkValues_assumptionDischarger_spec__0(v_goal_609_, v_decls_616_, v___x_618_, v___y_610_, v___y_611_, v___y_612_, v___y_613_);
if (lean_obj_tag(v___x_619_) == 0)
{
lean_object* v_a_620_; lean_object* v___x_622_; uint8_t v_isShared_623_; uint8_t v_isSharedCheck_632_; 
v_a_620_ = lean_ctor_get(v___x_619_, 0);
v_isSharedCheck_632_ = !lean_is_exclusive(v___x_619_);
if (v_isSharedCheck_632_ == 0)
{
v___x_622_ = v___x_619_;
v_isShared_623_ = v_isSharedCheck_632_;
goto v_resetjp_621_;
}
else
{
lean_inc(v_a_620_);
lean_dec(v___x_619_);
v___x_622_ = lean_box(0);
v_isShared_623_ = v_isSharedCheck_632_;
goto v_resetjp_621_;
}
v_resetjp_621_:
{
lean_object* v_fst_624_; 
v_fst_624_ = lean_ctor_get(v_a_620_, 0);
lean_inc(v_fst_624_);
lean_dec(v_a_620_);
if (lean_obj_tag(v_fst_624_) == 0)
{
lean_object* v___x_626_; 
if (v_isShared_623_ == 0)
{
lean_ctor_set(v___x_622_, 0, v___x_617_);
v___x_626_ = v___x_622_;
goto v_reusejp_625_;
}
else
{
lean_object* v_reuseFailAlloc_627_; 
v_reuseFailAlloc_627_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_627_, 0, v___x_617_);
v___x_626_ = v_reuseFailAlloc_627_;
goto v_reusejp_625_;
}
v_reusejp_625_:
{
return v___x_626_;
}
}
else
{
lean_object* v_val_628_; lean_object* v___x_630_; 
v_val_628_ = lean_ctor_get(v_fst_624_, 0);
lean_inc(v_val_628_);
lean_dec_ref_known(v_fst_624_, 1);
if (v_isShared_623_ == 0)
{
lean_ctor_set(v___x_622_, 0, v_val_628_);
v___x_630_ = v___x_622_;
goto v_reusejp_629_;
}
else
{
lean_object* v_reuseFailAlloc_631_; 
v_reuseFailAlloc_631_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_631_, 0, v_val_628_);
v___x_630_ = v_reuseFailAlloc_631_;
goto v_reusejp_629_;
}
v_reusejp_629_:
{
return v___x_630_;
}
}
}
}
else
{
lean_object* v_a_633_; lean_object* v___x_635_; uint8_t v_isShared_636_; uint8_t v_isSharedCheck_640_; 
v_a_633_ = lean_ctor_get(v___x_619_, 0);
v_isSharedCheck_640_ = !lean_is_exclusive(v___x_619_);
if (v_isSharedCheck_640_ == 0)
{
v___x_635_ = v___x_619_;
v_isShared_636_ = v_isSharedCheck_640_;
goto v_resetjp_634_;
}
else
{
lean_inc(v_a_633_);
lean_dec(v___x_619_);
v___x_635_ = lean_box(0);
v_isShared_636_ = v_isSharedCheck_640_;
goto v_resetjp_634_;
}
v_resetjp_634_:
{
lean_object* v___x_638_; 
if (v_isShared_636_ == 0)
{
v___x_638_ = v___x_635_;
goto v_reusejp_637_;
}
else
{
lean_object* v_reuseFailAlloc_639_; 
v_reuseFailAlloc_639_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_639_, 0, v_a_633_);
v___x_638_ = v_reuseFailAlloc_639_;
goto v_reusejp_637_;
}
v_reusejp_637_:
{
return v___x_638_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_assumptionDischarger___lam__0___boxed(lean_object* v_goal_641_, lean_object* v___y_642_, lean_object* v___y_643_, lean_object* v___y_644_, lean_object* v___y_645_, lean_object* v___y_646_){
_start:
{
lean_object* v_res_647_; 
v_res_647_ = lp_JunkValues_JunkValues_assumptionDischarger___lam__0(v_goal_641_, v___y_642_, v___y_643_, v___y_644_, v___y_645_);
lean_dec(v___y_645_);
lean_dec_ref(v___y_644_);
lean_dec(v___y_643_);
lean_dec_ref(v___y_642_);
return v_res_647_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_instantiateMVars___at___00JunkValues_tacticDischarger_spec__0___redArg(lean_object* v_e_654_, lean_object* v___y_655_){
_start:
{
uint8_t v___x_657_; 
v___x_657_ = l_Lean_Expr_hasMVar(v_e_654_);
if (v___x_657_ == 0)
{
lean_object* v___x_658_; 
v___x_658_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_658_, 0, v_e_654_);
return v___x_658_;
}
else
{
lean_object* v___x_659_; lean_object* v_mctx_660_; lean_object* v___x_661_; lean_object* v_fst_662_; lean_object* v_snd_663_; lean_object* v___x_664_; lean_object* v_cache_665_; lean_object* v_zetaDeltaFVarIds_666_; lean_object* v_postponed_667_; lean_object* v_diag_668_; lean_object* v___x_670_; uint8_t v_isShared_671_; uint8_t v_isSharedCheck_677_; 
v___x_659_ = lean_st_ref_get(v___y_655_);
v_mctx_660_ = lean_ctor_get(v___x_659_, 0);
lean_inc_ref(v_mctx_660_);
lean_dec(v___x_659_);
v___x_661_ = l_Lean_instantiateMVarsCore(v_mctx_660_, v_e_654_);
v_fst_662_ = lean_ctor_get(v___x_661_, 0);
lean_inc(v_fst_662_);
v_snd_663_ = lean_ctor_get(v___x_661_, 1);
lean_inc(v_snd_663_);
lean_dec_ref(v___x_661_);
v___x_664_ = lean_st_ref_take(v___y_655_);
v_cache_665_ = lean_ctor_get(v___x_664_, 1);
v_zetaDeltaFVarIds_666_ = lean_ctor_get(v___x_664_, 2);
v_postponed_667_ = lean_ctor_get(v___x_664_, 3);
v_diag_668_ = lean_ctor_get(v___x_664_, 4);
v_isSharedCheck_677_ = !lean_is_exclusive(v___x_664_);
if (v_isSharedCheck_677_ == 0)
{
lean_object* v_unused_678_; 
v_unused_678_ = lean_ctor_get(v___x_664_, 0);
lean_dec(v_unused_678_);
v___x_670_ = v___x_664_;
v_isShared_671_ = v_isSharedCheck_677_;
goto v_resetjp_669_;
}
else
{
lean_inc(v_diag_668_);
lean_inc(v_postponed_667_);
lean_inc(v_zetaDeltaFVarIds_666_);
lean_inc(v_cache_665_);
lean_dec(v___x_664_);
v___x_670_ = lean_box(0);
v_isShared_671_ = v_isSharedCheck_677_;
goto v_resetjp_669_;
}
v_resetjp_669_:
{
lean_object* v___x_673_; 
if (v_isShared_671_ == 0)
{
lean_ctor_set(v___x_670_, 0, v_snd_663_);
v___x_673_ = v___x_670_;
goto v_reusejp_672_;
}
else
{
lean_object* v_reuseFailAlloc_676_; 
v_reuseFailAlloc_676_ = lean_alloc_ctor(0, 5, 0);
lean_ctor_set(v_reuseFailAlloc_676_, 0, v_snd_663_);
lean_ctor_set(v_reuseFailAlloc_676_, 1, v_cache_665_);
lean_ctor_set(v_reuseFailAlloc_676_, 2, v_zetaDeltaFVarIds_666_);
lean_ctor_set(v_reuseFailAlloc_676_, 3, v_postponed_667_);
lean_ctor_set(v_reuseFailAlloc_676_, 4, v_diag_668_);
v___x_673_ = v_reuseFailAlloc_676_;
goto v_reusejp_672_;
}
v_reusejp_672_:
{
lean_object* v___x_674_; lean_object* v___x_675_; 
v___x_674_ = lean_st_ref_set(v___y_655_, v___x_673_);
v___x_675_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_675_, 0, v_fst_662_);
return v___x_675_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_instantiateMVars___at___00JunkValues_tacticDischarger_spec__0___redArg___boxed(lean_object* v_e_679_, lean_object* v___y_680_, lean_object* v___y_681_){
_start:
{
lean_object* v_res_682_; 
v_res_682_ = lp_JunkValues_Lean_instantiateMVars___at___00JunkValues_tacticDischarger_spec__0___redArg(v_e_679_, v___y_680_);
lean_dec(v___y_680_);
return v_res_682_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_instantiateMVars___at___00JunkValues_tacticDischarger_spec__0(lean_object* v_e_683_, lean_object* v___y_684_, lean_object* v___y_685_, lean_object* v___y_686_, lean_object* v___y_687_){
_start:
{
lean_object* v___x_689_; 
v___x_689_ = lp_JunkValues_Lean_instantiateMVars___at___00JunkValues_tacticDischarger_spec__0___redArg(v_e_683_, v___y_685_);
return v___x_689_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_instantiateMVars___at___00JunkValues_tacticDischarger_spec__0___boxed(lean_object* v_e_690_, lean_object* v___y_691_, lean_object* v___y_692_, lean_object* v___y_693_, lean_object* v___y_694_, lean_object* v___y_695_){
_start:
{
lean_object* v_res_696_; 
v_res_696_ = lp_JunkValues_Lean_instantiateMVars___at___00JunkValues_tacticDischarger_spec__0(v_e_690_, v___y_691_, v___y_692_, v___y_693_, v___y_694_);
lean_dec(v___y_694_);
lean_dec_ref(v___y_693_);
lean_dec(v___y_692_);
lean_dec_ref(v___y_691_);
return v_res_696_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Core_withCurrHeartbeats___at___00JunkValues_tacticDischarger_spec__1___redArg___lam__0(lean_object* v_x_697_, lean_object* v___y_698_, lean_object* v___y_699_, lean_object* v___y_700_, lean_object* v___y_701_){
_start:
{
lean_object* v___x_703_; 
lean_inc(v___y_699_);
lean_inc_ref(v___y_698_);
v___x_703_ = lean_apply_5(v_x_697_, v___y_698_, v___y_699_, v___y_700_, v___y_701_, lean_box(0));
return v___x_703_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Core_withCurrHeartbeats___at___00JunkValues_tacticDischarger_spec__1___redArg___lam__0___boxed(lean_object* v_x_704_, lean_object* v___y_705_, lean_object* v___y_706_, lean_object* v___y_707_, lean_object* v___y_708_, lean_object* v___y_709_){
_start:
{
lean_object* v_res_710_; 
v_res_710_ = lp_JunkValues_Lean_Core_withCurrHeartbeats___at___00JunkValues_tacticDischarger_spec__1___redArg___lam__0(v_x_704_, v___y_705_, v___y_706_, v___y_707_, v___y_708_);
lean_dec(v___y_706_);
lean_dec_ref(v___y_705_);
return v_res_710_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Core_withCurrHeartbeats___at___00JunkValues_tacticDischarger_spec__1___redArg(lean_object* v_x_711_, lean_object* v___y_712_, lean_object* v___y_713_, lean_object* v___y_714_, lean_object* v___y_715_){
_start:
{
lean_object* v___f_717_; lean_object* v___x_718_; 
lean_inc(v___y_713_);
lean_inc_ref(v___y_712_);
v___f_717_ = lean_alloc_closure((void*)(lp_JunkValues_Lean_Core_withCurrHeartbeats___at___00JunkValues_tacticDischarger_spec__1___redArg___lam__0___boxed), 6, 3);
lean_closure_set(v___f_717_, 0, v_x_711_);
lean_closure_set(v___f_717_, 1, v___y_712_);
lean_closure_set(v___f_717_, 2, v___y_713_);
v___x_718_ = l___private_Lean_CoreM_0__Lean_Core_withCurrHeartbeatsImp(lean_box(0), v___f_717_, v___y_714_, v___y_715_);
if (lean_obj_tag(v___x_718_) == 0)
{
return v___x_718_;
}
else
{
lean_object* v_a_719_; lean_object* v___x_721_; uint8_t v_isShared_722_; uint8_t v_isSharedCheck_726_; 
v_a_719_ = lean_ctor_get(v___x_718_, 0);
v_isSharedCheck_726_ = !lean_is_exclusive(v___x_718_);
if (v_isSharedCheck_726_ == 0)
{
v___x_721_ = v___x_718_;
v_isShared_722_ = v_isSharedCheck_726_;
goto v_resetjp_720_;
}
else
{
lean_inc(v_a_719_);
lean_dec(v___x_718_);
v___x_721_ = lean_box(0);
v_isShared_722_ = v_isSharedCheck_726_;
goto v_resetjp_720_;
}
v_resetjp_720_:
{
lean_object* v___x_724_; 
if (v_isShared_722_ == 0)
{
v___x_724_ = v___x_721_;
goto v_reusejp_723_;
}
else
{
lean_object* v_reuseFailAlloc_725_; 
v_reuseFailAlloc_725_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_725_, 0, v_a_719_);
v___x_724_ = v_reuseFailAlloc_725_;
goto v_reusejp_723_;
}
v_reusejp_723_:
{
return v___x_724_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Core_withCurrHeartbeats___at___00JunkValues_tacticDischarger_spec__1___redArg___boxed(lean_object* v_x_727_, lean_object* v___y_728_, lean_object* v___y_729_, lean_object* v___y_730_, lean_object* v___y_731_, lean_object* v___y_732_){
_start:
{
lean_object* v_res_733_; 
v_res_733_ = lp_JunkValues_Lean_Core_withCurrHeartbeats___at___00JunkValues_tacticDischarger_spec__1___redArg(v_x_727_, v___y_728_, v___y_729_, v___y_730_, v___y_731_);
lean_dec(v___y_731_);
lean_dec_ref(v___y_730_);
lean_dec(v___y_729_);
lean_dec_ref(v___y_728_);
return v_res_733_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Core_withCurrHeartbeats___at___00JunkValues_tacticDischarger_spec__1(lean_object* v_00_u03b1_734_, lean_object* v_x_735_, lean_object* v___y_736_, lean_object* v___y_737_, lean_object* v___y_738_, lean_object* v___y_739_){
_start:
{
lean_object* v___x_741_; 
v___x_741_ = lp_JunkValues_Lean_Core_withCurrHeartbeats___at___00JunkValues_tacticDischarger_spec__1___redArg(v_x_735_, v___y_736_, v___y_737_, v___y_738_, v___y_739_);
return v___x_741_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Core_withCurrHeartbeats___at___00JunkValues_tacticDischarger_spec__1___boxed(lean_object* v_00_u03b1_742_, lean_object* v_x_743_, lean_object* v___y_744_, lean_object* v___y_745_, lean_object* v___y_746_, lean_object* v___y_747_, lean_object* v___y_748_){
_start:
{
lean_object* v_res_749_; 
v_res_749_ = lp_JunkValues_Lean_Core_withCurrHeartbeats___at___00JunkValues_tacticDischarger_spec__1(v_00_u03b1_742_, v_x_743_, v___y_744_, v___y_745_, v___y_746_, v___y_747_);
lean_dec(v___y_747_);
lean_dec_ref(v___y_746_);
lean_dec(v___y_745_);
lean_dec_ref(v___y_744_);
return v_res_749_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_withoutModifyingState___at___00JunkValues_tacticDischarger_spec__2___redArg(lean_object* v_x_750_, lean_object* v___y_751_, lean_object* v___y_752_, lean_object* v___y_753_, lean_object* v___y_754_){
_start:
{
lean_object* v___x_756_; 
v___x_756_ = l_Lean_Meta_saveState___redArg(v___y_752_, v___y_754_);
if (lean_obj_tag(v___x_756_) == 0)
{
lean_object* v_a_757_; lean_object* v_r_758_; 
v_a_757_ = lean_ctor_get(v___x_756_, 0);
lean_inc(v_a_757_);
lean_dec_ref_known(v___x_756_, 1);
lean_inc(v___y_754_);
lean_inc_ref(v___y_753_);
lean_inc(v___y_752_);
lean_inc_ref(v___y_751_);
v_r_758_ = lean_apply_5(v_x_750_, v___y_751_, v___y_752_, v___y_753_, v___y_754_, lean_box(0));
if (lean_obj_tag(v_r_758_) == 0)
{
lean_object* v_a_759_; lean_object* v___x_760_; 
v_a_759_ = lean_ctor_get(v_r_758_, 0);
lean_inc(v_a_759_);
lean_dec_ref_known(v_r_758_, 1);
v___x_760_ = l_Lean_Meta_SavedState_restore___redArg(v_a_757_, v___y_752_, v___y_754_);
lean_dec(v_a_757_);
if (lean_obj_tag(v___x_760_) == 0)
{
lean_object* v___x_762_; uint8_t v_isShared_763_; uint8_t v_isSharedCheck_767_; 
v_isSharedCheck_767_ = !lean_is_exclusive(v___x_760_);
if (v_isSharedCheck_767_ == 0)
{
lean_object* v_unused_768_; 
v_unused_768_ = lean_ctor_get(v___x_760_, 0);
lean_dec(v_unused_768_);
v___x_762_ = v___x_760_;
v_isShared_763_ = v_isSharedCheck_767_;
goto v_resetjp_761_;
}
else
{
lean_dec(v___x_760_);
v___x_762_ = lean_box(0);
v_isShared_763_ = v_isSharedCheck_767_;
goto v_resetjp_761_;
}
v_resetjp_761_:
{
lean_object* v___x_765_; 
if (v_isShared_763_ == 0)
{
lean_ctor_set(v___x_762_, 0, v_a_759_);
v___x_765_ = v___x_762_;
goto v_reusejp_764_;
}
else
{
lean_object* v_reuseFailAlloc_766_; 
v_reuseFailAlloc_766_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_766_, 0, v_a_759_);
v___x_765_ = v_reuseFailAlloc_766_;
goto v_reusejp_764_;
}
v_reusejp_764_:
{
return v___x_765_;
}
}
}
else
{
lean_object* v_a_769_; lean_object* v___x_771_; uint8_t v_isShared_772_; uint8_t v_isSharedCheck_776_; 
lean_dec(v_a_759_);
v_a_769_ = lean_ctor_get(v___x_760_, 0);
v_isSharedCheck_776_ = !lean_is_exclusive(v___x_760_);
if (v_isSharedCheck_776_ == 0)
{
v___x_771_ = v___x_760_;
v_isShared_772_ = v_isSharedCheck_776_;
goto v_resetjp_770_;
}
else
{
lean_inc(v_a_769_);
lean_dec(v___x_760_);
v___x_771_ = lean_box(0);
v_isShared_772_ = v_isSharedCheck_776_;
goto v_resetjp_770_;
}
v_resetjp_770_:
{
lean_object* v___x_774_; 
if (v_isShared_772_ == 0)
{
v___x_774_ = v___x_771_;
goto v_reusejp_773_;
}
else
{
lean_object* v_reuseFailAlloc_775_; 
v_reuseFailAlloc_775_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_775_, 0, v_a_769_);
v___x_774_ = v_reuseFailAlloc_775_;
goto v_reusejp_773_;
}
v_reusejp_773_:
{
return v___x_774_;
}
}
}
}
else
{
lean_object* v_a_777_; lean_object* v___x_778_; 
v_a_777_ = lean_ctor_get(v_r_758_, 0);
lean_inc(v_a_777_);
lean_dec_ref_known(v_r_758_, 1);
v___x_778_ = l_Lean_Meta_SavedState_restore___redArg(v_a_757_, v___y_752_, v___y_754_);
lean_dec(v_a_757_);
if (lean_obj_tag(v___x_778_) == 0)
{
lean_object* v___x_780_; uint8_t v_isShared_781_; uint8_t v_isSharedCheck_785_; 
v_isSharedCheck_785_ = !lean_is_exclusive(v___x_778_);
if (v_isSharedCheck_785_ == 0)
{
lean_object* v_unused_786_; 
v_unused_786_ = lean_ctor_get(v___x_778_, 0);
lean_dec(v_unused_786_);
v___x_780_ = v___x_778_;
v_isShared_781_ = v_isSharedCheck_785_;
goto v_resetjp_779_;
}
else
{
lean_dec(v___x_778_);
v___x_780_ = lean_box(0);
v_isShared_781_ = v_isSharedCheck_785_;
goto v_resetjp_779_;
}
v_resetjp_779_:
{
lean_object* v___x_783_; 
if (v_isShared_781_ == 0)
{
lean_ctor_set_tag(v___x_780_, 1);
lean_ctor_set(v___x_780_, 0, v_a_777_);
v___x_783_ = v___x_780_;
goto v_reusejp_782_;
}
else
{
lean_object* v_reuseFailAlloc_784_; 
v_reuseFailAlloc_784_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_784_, 0, v_a_777_);
v___x_783_ = v_reuseFailAlloc_784_;
goto v_reusejp_782_;
}
v_reusejp_782_:
{
return v___x_783_;
}
}
}
else
{
lean_object* v_a_787_; lean_object* v___x_789_; uint8_t v_isShared_790_; uint8_t v_isSharedCheck_794_; 
lean_dec(v_a_777_);
v_a_787_ = lean_ctor_get(v___x_778_, 0);
v_isSharedCheck_794_ = !lean_is_exclusive(v___x_778_);
if (v_isSharedCheck_794_ == 0)
{
v___x_789_ = v___x_778_;
v_isShared_790_ = v_isSharedCheck_794_;
goto v_resetjp_788_;
}
else
{
lean_inc(v_a_787_);
lean_dec(v___x_778_);
v___x_789_ = lean_box(0);
v_isShared_790_ = v_isSharedCheck_794_;
goto v_resetjp_788_;
}
v_resetjp_788_:
{
lean_object* v___x_792_; 
if (v_isShared_790_ == 0)
{
v___x_792_ = v___x_789_;
goto v_reusejp_791_;
}
else
{
lean_object* v_reuseFailAlloc_793_; 
v_reuseFailAlloc_793_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_793_, 0, v_a_787_);
v___x_792_ = v_reuseFailAlloc_793_;
goto v_reusejp_791_;
}
v_reusejp_791_:
{
return v___x_792_;
}
}
}
}
}
else
{
lean_object* v_a_795_; lean_object* v___x_797_; uint8_t v_isShared_798_; uint8_t v_isSharedCheck_802_; 
lean_dec_ref(v_x_750_);
v_a_795_ = lean_ctor_get(v___x_756_, 0);
v_isSharedCheck_802_ = !lean_is_exclusive(v___x_756_);
if (v_isSharedCheck_802_ == 0)
{
v___x_797_ = v___x_756_;
v_isShared_798_ = v_isSharedCheck_802_;
goto v_resetjp_796_;
}
else
{
lean_inc(v_a_795_);
lean_dec(v___x_756_);
v___x_797_ = lean_box(0);
v_isShared_798_ = v_isSharedCheck_802_;
goto v_resetjp_796_;
}
v_resetjp_796_:
{
lean_object* v___x_800_; 
if (v_isShared_798_ == 0)
{
v___x_800_ = v___x_797_;
goto v_reusejp_799_;
}
else
{
lean_object* v_reuseFailAlloc_801_; 
v_reuseFailAlloc_801_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_801_, 0, v_a_795_);
v___x_800_ = v_reuseFailAlloc_801_;
goto v_reusejp_799_;
}
v_reusejp_799_:
{
return v___x_800_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_withoutModifyingState___at___00JunkValues_tacticDischarger_spec__2___redArg___boxed(lean_object* v_x_803_, lean_object* v___y_804_, lean_object* v___y_805_, lean_object* v___y_806_, lean_object* v___y_807_, lean_object* v___y_808_){
_start:
{
lean_object* v_res_809_; 
v_res_809_ = lp_JunkValues_Lean_withoutModifyingState___at___00JunkValues_tacticDischarger_spec__2___redArg(v_x_803_, v___y_804_, v___y_805_, v___y_806_, v___y_807_);
lean_dec(v___y_807_);
lean_dec_ref(v___y_806_);
lean_dec(v___y_805_);
lean_dec_ref(v___y_804_);
return v_res_809_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_withoutModifyingState___at___00JunkValues_tacticDischarger_spec__2(lean_object* v_00_u03b1_810_, lean_object* v_x_811_, lean_object* v___y_812_, lean_object* v___y_813_, lean_object* v___y_814_, lean_object* v___y_815_){
_start:
{
lean_object* v___x_817_; 
v___x_817_ = lp_JunkValues_Lean_withoutModifyingState___at___00JunkValues_tacticDischarger_spec__2___redArg(v_x_811_, v___y_812_, v___y_813_, v___y_814_, v___y_815_);
return v___x_817_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_withoutModifyingState___at___00JunkValues_tacticDischarger_spec__2___boxed(lean_object* v_00_u03b1_818_, lean_object* v_x_819_, lean_object* v___y_820_, lean_object* v___y_821_, lean_object* v___y_822_, lean_object* v___y_823_, lean_object* v___y_824_){
_start:
{
lean_object* v_res_825_; 
v_res_825_ = lp_JunkValues_Lean_withoutModifyingState___at___00JunkValues_tacticDischarger_spec__2(v_00_u03b1_818_, v_x_819_, v___y_820_, v___y_821_, v___y_822_, v___y_823_);
lean_dec(v___y_823_);
lean_dec_ref(v___y_822_);
lean_dec(v___y_821_);
lean_dec_ref(v___y_820_);
return v_res_825_;
}
}
LEAN_EXPORT uint8_t lp_JunkValues_JunkValues_tacticDischarger___lam__0(lean_object* v_x_826_){
_start:
{
uint8_t v___x_827_; 
v___x_827_ = 0;
return v___x_827_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_tacticDischarger___lam__0___boxed(lean_object* v_x_828_){
_start:
{
uint8_t v_res_829_; lean_object* v_r_830_; 
v_res_829_ = lp_JunkValues_JunkValues_tacticDischarger___lam__0(v_x_828_);
lean_dec(v_x_828_);
v_r_830_ = lean_box(v_res_829_);
return v_r_830_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_tacticDischarger___lam__1(lean_object* v___x_836_, uint8_t v___x_837_, lean_object* v___x_838_, lean_object* v___f_839_, lean_object* v_tac_840_, lean_object* v_label_841_, lean_object* v___y_842_, lean_object* v___y_843_, lean_object* v___y_844_, lean_object* v___y_845_){
_start:
{
lean_object* v___x_847_; 
v___x_847_ = l_Lean_Meta_mkFreshExprMVar(v___x_836_, v___x_837_, v___x_838_, v___y_842_, v___y_843_, v___y_844_, v___y_845_);
if (lean_obj_tag(v___x_847_) == 0)
{
lean_object* v_a_848_; lean_object* v___x_849_; lean_object* v___x_850_; lean_object* v___x_851_; uint8_t v___x_852_; lean_object* v___x_853_; uint8_t v___x_854_; lean_object* v___x_855_; lean_object* v___x_856_; lean_object* v___x_857_; lean_object* v___x_858_; 
v_a_848_ = lean_ctor_get(v___x_847_, 0);
lean_inc(v_a_848_);
lean_dec_ref_known(v___x_847_, 1);
v___x_849_ = l_Lean_Expr_mvarId_x21(v_a_848_);
v___x_850_ = lean_box(0);
v___x_851_ = lean_box(0);
v___x_852_ = 1;
v___x_853_ = lean_box(1);
v___x_854_ = 0;
v___x_855_ = ((lean_object*)(lp_JunkValues_JunkValues_tacticDischarger___lam__1___closed__0));
v___x_856_ = lean_alloc_ctor(0, 8, 11);
lean_ctor_set(v___x_856_, 0, v___x_850_);
lean_ctor_set(v___x_856_, 1, v___x_851_);
lean_ctor_set(v___x_856_, 2, v___x_850_);
lean_ctor_set(v___x_856_, 3, v___f_839_);
lean_ctor_set(v___x_856_, 4, v___x_853_);
lean_ctor_set(v___x_856_, 5, v___x_853_);
lean_ctor_set(v___x_856_, 6, v___x_850_);
lean_ctor_set(v___x_856_, 7, v___x_855_);
lean_ctor_set_uint8(v___x_856_, sizeof(void*)*8, v___x_852_);
lean_ctor_set_uint8(v___x_856_, sizeof(void*)*8 + 1, v___x_852_);
lean_ctor_set_uint8(v___x_856_, sizeof(void*)*8 + 2, v___x_852_);
lean_ctor_set_uint8(v___x_856_, sizeof(void*)*8 + 3, v___x_852_);
lean_ctor_set_uint8(v___x_856_, sizeof(void*)*8 + 4, v___x_854_);
lean_ctor_set_uint8(v___x_856_, sizeof(void*)*8 + 5, v___x_854_);
lean_ctor_set_uint8(v___x_856_, sizeof(void*)*8 + 6, v___x_854_);
lean_ctor_set_uint8(v___x_856_, sizeof(void*)*8 + 7, v___x_854_);
lean_ctor_set_uint8(v___x_856_, sizeof(void*)*8 + 8, v___x_852_);
lean_ctor_set_uint8(v___x_856_, sizeof(void*)*8 + 9, v___x_854_);
lean_ctor_set_uint8(v___x_856_, sizeof(void*)*8 + 10, v___x_852_);
v___x_857_ = ((lean_object*)(lp_JunkValues_JunkValues_tacticDischarger___lam__1___closed__1));
v___x_858_ = l_Lean_Elab_runTactic(v___x_849_, v_tac_840_, v___x_856_, v___x_857_, v___y_842_, v___y_843_, v___y_844_, v___y_845_);
if (lean_obj_tag(v___x_858_) == 0)
{
lean_object* v_a_859_; lean_object* v___x_861_; uint8_t v_isShared_862_; uint8_t v_isSharedCheck_880_; 
v_a_859_ = lean_ctor_get(v___x_858_, 0);
v_isSharedCheck_880_ = !lean_is_exclusive(v___x_858_);
if (v_isSharedCheck_880_ == 0)
{
v___x_861_ = v___x_858_;
v_isShared_862_ = v_isSharedCheck_880_;
goto v_resetjp_860_;
}
else
{
lean_inc(v_a_859_);
lean_dec(v___x_858_);
v___x_861_ = lean_box(0);
v_isShared_862_ = v_isSharedCheck_880_;
goto v_resetjp_860_;
}
v_resetjp_860_:
{
lean_object* v_fst_863_; lean_object* v___x_864_; lean_object* v_a_865_; lean_object* v___x_867_; uint8_t v_isShared_868_; uint8_t v_isSharedCheck_879_; 
v_fst_863_ = lean_ctor_get(v_a_859_, 0);
lean_inc(v_fst_863_);
lean_dec(v_a_859_);
v___x_864_ = lp_JunkValues_Lean_instantiateMVars___at___00JunkValues_tacticDischarger_spec__0___redArg(v_a_848_, v___y_843_);
v_a_865_ = lean_ctor_get(v___x_864_, 0);
v_isSharedCheck_879_ = !lean_is_exclusive(v___x_864_);
if (v_isSharedCheck_879_ == 0)
{
v___x_867_ = v___x_864_;
v_isShared_868_ = v_isSharedCheck_879_;
goto v_resetjp_866_;
}
else
{
lean_inc(v_a_865_);
lean_dec(v___x_864_);
v___x_867_ = lean_box(0);
v_isShared_868_ = v_isSharedCheck_879_;
goto v_resetjp_866_;
}
v_resetjp_866_:
{
uint8_t v___x_873_; 
v___x_873_ = l_List_isEmpty___redArg(v_fst_863_);
lean_dec(v_fst_863_);
if (v___x_873_ == 0)
{
lean_dec(v_a_865_);
lean_del_object(v___x_861_);
lean_dec_ref(v_label_841_);
goto v___jp_869_;
}
else
{
uint8_t v___x_874_; 
v___x_874_ = l_Lean_Expr_hasSorry(v_a_865_);
lean_dec(v_a_865_);
if (v___x_874_ == 0)
{
if (v___x_873_ == 0)
{
lean_del_object(v___x_861_);
lean_dec_ref(v_label_841_);
goto v___jp_869_;
}
else
{
lean_object* v___x_875_; lean_object* v___x_877_; 
lean_del_object(v___x_867_);
v___x_875_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_875_, 0, v_label_841_);
if (v_isShared_862_ == 0)
{
lean_ctor_set(v___x_861_, 0, v___x_875_);
v___x_877_ = v___x_861_;
goto v_reusejp_876_;
}
else
{
lean_object* v_reuseFailAlloc_878_; 
v_reuseFailAlloc_878_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_878_, 0, v___x_875_);
v___x_877_ = v_reuseFailAlloc_878_;
goto v_reusejp_876_;
}
v_reusejp_876_:
{
return v___x_877_;
}
}
}
else
{
lean_del_object(v___x_861_);
lean_dec_ref(v_label_841_);
goto v___jp_869_;
}
}
v___jp_869_:
{
lean_object* v___x_871_; 
if (v_isShared_868_ == 0)
{
lean_ctor_set(v___x_867_, 0, v___x_850_);
v___x_871_ = v___x_867_;
goto v_reusejp_870_;
}
else
{
lean_object* v_reuseFailAlloc_872_; 
v_reuseFailAlloc_872_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_872_, 0, v___x_850_);
v___x_871_ = v_reuseFailAlloc_872_;
goto v_reusejp_870_;
}
v_reusejp_870_:
{
return v___x_871_;
}
}
}
}
}
else
{
lean_object* v_a_881_; lean_object* v___x_883_; uint8_t v_isShared_884_; uint8_t v_isSharedCheck_888_; 
lean_dec(v_a_848_);
lean_dec_ref(v_label_841_);
v_a_881_ = lean_ctor_get(v___x_858_, 0);
v_isSharedCheck_888_ = !lean_is_exclusive(v___x_858_);
if (v_isSharedCheck_888_ == 0)
{
v___x_883_ = v___x_858_;
v_isShared_884_ = v_isSharedCheck_888_;
goto v_resetjp_882_;
}
else
{
lean_inc(v_a_881_);
lean_dec(v___x_858_);
v___x_883_ = lean_box(0);
v_isShared_884_ = v_isSharedCheck_888_;
goto v_resetjp_882_;
}
v_resetjp_882_:
{
lean_object* v___x_886_; 
if (v_isShared_884_ == 0)
{
v___x_886_ = v___x_883_;
goto v_reusejp_885_;
}
else
{
lean_object* v_reuseFailAlloc_887_; 
v_reuseFailAlloc_887_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_887_, 0, v_a_881_);
v___x_886_ = v_reuseFailAlloc_887_;
goto v_reusejp_885_;
}
v_reusejp_885_:
{
return v___x_886_;
}
}
}
}
else
{
lean_object* v_a_889_; lean_object* v___x_891_; uint8_t v_isShared_892_; uint8_t v_isSharedCheck_896_; 
lean_dec_ref(v_label_841_);
lean_dec(v_tac_840_);
lean_dec_ref(v___f_839_);
v_a_889_ = lean_ctor_get(v___x_847_, 0);
v_isSharedCheck_896_ = !lean_is_exclusive(v___x_847_);
if (v_isSharedCheck_896_ == 0)
{
v___x_891_ = v___x_847_;
v_isShared_892_ = v_isSharedCheck_896_;
goto v_resetjp_890_;
}
else
{
lean_inc(v_a_889_);
lean_dec(v___x_847_);
v___x_891_ = lean_box(0);
v_isShared_892_ = v_isSharedCheck_896_;
goto v_resetjp_890_;
}
v_resetjp_890_:
{
lean_object* v___x_894_; 
if (v_isShared_892_ == 0)
{
v___x_894_ = v___x_891_;
goto v_reusejp_893_;
}
else
{
lean_object* v_reuseFailAlloc_895_; 
v_reuseFailAlloc_895_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_895_, 0, v_a_889_);
v___x_894_ = v_reuseFailAlloc_895_;
goto v_reusejp_893_;
}
v_reusejp_893_:
{
return v___x_894_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_tacticDischarger___lam__1___boxed(lean_object* v___x_897_, lean_object* v___x_898_, lean_object* v___x_899_, lean_object* v___f_900_, lean_object* v_tac_901_, lean_object* v_label_902_, lean_object* v___y_903_, lean_object* v___y_904_, lean_object* v___y_905_, lean_object* v___y_906_, lean_object* v___y_907_){
_start:
{
uint8_t v___x_3755__boxed_908_; lean_object* v_res_909_; 
v___x_3755__boxed_908_ = lean_unbox(v___x_898_);
v_res_909_ = lp_JunkValues_JunkValues_tacticDischarger___lam__1(v___x_897_, v___x_3755__boxed_908_, v___x_899_, v___f_900_, v_tac_901_, v_label_902_, v___y_903_, v___y_904_, v___y_905_, v___y_906_);
lean_dec(v___y_906_);
lean_dec_ref(v___y_905_);
lean_dec(v___y_904_);
lean_dec_ref(v___y_903_);
return v_res_909_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_tacticDischarger___lam__2(lean_object* v___f_910_, lean_object* v___y_911_, lean_object* v___y_912_, lean_object* v___y_913_, lean_object* v___y_914_){
_start:
{
lean_object* v___x_916_; 
v___x_916_ = lp_JunkValues_Lean_Core_withCurrHeartbeats___at___00JunkValues_tacticDischarger_spec__1___redArg(v___f_910_, v___y_911_, v___y_912_, v___y_913_, v___y_914_);
if (lean_obj_tag(v___x_916_) == 0)
{
return v___x_916_;
}
else
{
lean_object* v_a_917_; uint8_t v___y_919_; uint8_t v___x_929_; 
v_a_917_ = lean_ctor_get(v___x_916_, 0);
lean_inc(v_a_917_);
v___x_929_ = l_Lean_Exception_isInterrupt(v_a_917_);
if (v___x_929_ == 0)
{
uint8_t v___x_930_; 
v___x_930_ = l_Lean_Exception_isRuntime(v_a_917_);
v___y_919_ = v___x_930_;
goto v___jp_918_;
}
else
{
lean_dec(v_a_917_);
v___y_919_ = v___x_929_;
goto v___jp_918_;
}
v___jp_918_:
{
if (v___y_919_ == 0)
{
lean_object* v___x_921_; uint8_t v_isShared_922_; uint8_t v_isSharedCheck_927_; 
v_isSharedCheck_927_ = !lean_is_exclusive(v___x_916_);
if (v_isSharedCheck_927_ == 0)
{
lean_object* v_unused_928_; 
v_unused_928_ = lean_ctor_get(v___x_916_, 0);
lean_dec(v_unused_928_);
v___x_921_ = v___x_916_;
v_isShared_922_ = v_isSharedCheck_927_;
goto v_resetjp_920_;
}
else
{
lean_dec(v___x_916_);
v___x_921_ = lean_box(0);
v_isShared_922_ = v_isSharedCheck_927_;
goto v_resetjp_920_;
}
v_resetjp_920_:
{
lean_object* v___x_923_; lean_object* v___x_925_; 
v___x_923_ = lean_box(0);
if (v_isShared_922_ == 0)
{
lean_ctor_set_tag(v___x_921_, 0);
lean_ctor_set(v___x_921_, 0, v___x_923_);
v___x_925_ = v___x_921_;
goto v_reusejp_924_;
}
else
{
lean_object* v_reuseFailAlloc_926_; 
v_reuseFailAlloc_926_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_926_, 0, v___x_923_);
v___x_925_ = v_reuseFailAlloc_926_;
goto v_reusejp_924_;
}
v_reusejp_924_:
{
return v___x_925_;
}
}
}
else
{
return v___x_916_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_tacticDischarger___lam__2___boxed(lean_object* v___f_931_, lean_object* v___y_932_, lean_object* v___y_933_, lean_object* v___y_934_, lean_object* v___y_935_, lean_object* v___y_936_){
_start:
{
lean_object* v_res_937_; 
v_res_937_ = lp_JunkValues_JunkValues_tacticDischarger___lam__2(v___f_931_, v___y_932_, v___y_933_, v___y_934_, v___y_935_);
lean_dec(v___y_935_);
lean_dec_ref(v___y_934_);
lean_dec(v___y_933_);
lean_dec_ref(v___y_932_);
return v_res_937_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_tacticDischarger___lam__3(lean_object* v___f_938_, lean_object* v_tac_939_, lean_object* v_label_940_, lean_object* v_goal_941_, lean_object* v___y_942_, lean_object* v___y_943_, lean_object* v___y_944_, lean_object* v___y_945_){
_start:
{
lean_object* v___x_947_; uint8_t v___x_948_; lean_object* v___x_949_; lean_object* v___x_950_; lean_object* v___f_951_; lean_object* v___f_952_; lean_object* v___x_953_; 
v___x_947_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_947_, 0, v_goal_941_);
v___x_948_ = 0;
v___x_949_ = lean_box(0);
v___x_950_ = lean_box(v___x_948_);
v___f_951_ = lean_alloc_closure((void*)(lp_JunkValues_JunkValues_tacticDischarger___lam__1___boxed), 11, 6);
lean_closure_set(v___f_951_, 0, v___x_947_);
lean_closure_set(v___f_951_, 1, v___x_950_);
lean_closure_set(v___f_951_, 2, v___x_949_);
lean_closure_set(v___f_951_, 3, v___f_938_);
lean_closure_set(v___f_951_, 4, v_tac_939_);
lean_closure_set(v___f_951_, 5, v_label_940_);
v___f_952_ = lean_alloc_closure((void*)(lp_JunkValues_JunkValues_tacticDischarger___lam__2___boxed), 6, 1);
lean_closure_set(v___f_952_, 0, v___f_951_);
v___x_953_ = lp_JunkValues_Lean_withoutModifyingState___at___00JunkValues_tacticDischarger_spec__2___redArg(v___f_952_, v___y_942_, v___y_943_, v___y_944_, v___y_945_);
return v___x_953_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_tacticDischarger___lam__3___boxed(lean_object* v___f_954_, lean_object* v_tac_955_, lean_object* v_label_956_, lean_object* v_goal_957_, lean_object* v___y_958_, lean_object* v___y_959_, lean_object* v___y_960_, lean_object* v___y_961_, lean_object* v___y_962_){
_start:
{
lean_object* v_res_963_; 
v_res_963_ = lp_JunkValues_JunkValues_tacticDischarger___lam__3(v___f_954_, v_tac_955_, v_label_956_, v_goal_957_, v___y_958_, v___y_959_, v___y_960_, v___y_961_);
lean_dec(v___y_961_);
lean_dec_ref(v___y_960_);
lean_dec(v___y_959_);
lean_dec_ref(v___y_958_);
return v_res_963_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_tacticDischarger(lean_object* v_label_965_, lean_object* v_tac_966_){
_start:
{
lean_object* v___f_967_; lean_object* v___f_968_; lean_object* v___x_969_; 
v___f_967_ = ((lean_object*)(lp_JunkValues_JunkValues_tacticDischarger___closed__0));
lean_inc_ref(v_label_965_);
v___f_968_ = lean_alloc_closure((void*)(lp_JunkValues_JunkValues_tacticDischarger___lam__3___boxed), 9, 3);
lean_closure_set(v___f_968_, 0, v___f_967_);
lean_closure_set(v___f_968_, 1, v_tac_966_);
lean_closure_set(v___f_968_, 2, v_label_965_);
v___x_969_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_969_, 0, v_label_965_);
lean_ctor_set(v___x_969_, 1, v___f_968_);
return v___x_969_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_tacticDischarger_x3f___redArg(lean_object* v_script_977_, lean_object* v_a_978_){
_start:
{
lean_object* v___x_980_; lean_object* v_env_981_; lean_object* v___x_982_; lean_object* v___x_983_; lean_object* v___x_984_; 
v___x_980_ = lean_st_ref_get(v_a_978_);
v_env_981_ = lean_ctor_get(v___x_980_, 0);
lean_inc_ref(v_env_981_);
lean_dec(v___x_980_);
v___x_982_ = ((lean_object*)(lp_JunkValues_JunkValues_tacticDischarger_x3f___redArg___closed__1));
v___x_983_ = ((lean_object*)(lp_JunkValues_JunkValues_tacticDischarger_x3f___redArg___closed__2));
lean_inc_ref(v_script_977_);
v___x_984_ = l_Lean_Parser_runParserCategory(v_env_981_, v___x_982_, v_script_977_, v___x_983_);
if (lean_obj_tag(v___x_984_) == 0)
{
lean_object* v_a_985_; lean_object* v___x_987_; uint8_t v_isShared_988_; uint8_t v_isSharedCheck_1000_; 
v_a_985_ = lean_ctor_get(v___x_984_, 0);
v_isSharedCheck_1000_ = !lean_is_exclusive(v___x_984_);
if (v_isSharedCheck_1000_ == 0)
{
v___x_987_ = v___x_984_;
v_isShared_988_ = v_isSharedCheck_1000_;
goto v_resetjp_986_;
}
else
{
lean_inc(v_a_985_);
lean_dec(v___x_984_);
v___x_987_ = lean_box(0);
v_isShared_988_ = v_isSharedCheck_1000_;
goto v_resetjp_986_;
}
v_resetjp_986_:
{
lean_object* v___x_989_; lean_object* v___x_990_; lean_object* v___x_991_; lean_object* v___x_992_; lean_object* v___x_993_; lean_object* v___x_994_; lean_object* v___x_995_; lean_object* v___x_997_; 
v___x_989_ = ((lean_object*)(lp_JunkValues_JunkValues_tacticDischarger_x3f___redArg___closed__3));
v___x_990_ = lean_string_append(v___x_989_, v_script_977_);
lean_dec_ref(v_script_977_);
v___x_991_ = ((lean_object*)(lp_JunkValues_JunkValues_tacticDischarger_x3f___redArg___closed__4));
v___x_992_ = lean_string_append(v___x_990_, v___x_991_);
v___x_993_ = lean_string_append(v___x_992_, v_a_985_);
lean_dec(v_a_985_);
v___x_994_ = ((lean_object*)(lp_JunkValues_JunkValues_tacticDischarger_x3f___redArg___closed__5));
v___x_995_ = lean_string_append(v___x_993_, v___x_994_);
if (v_isShared_988_ == 0)
{
lean_ctor_set(v___x_987_, 0, v___x_995_);
v___x_997_ = v___x_987_;
goto v_reusejp_996_;
}
else
{
lean_object* v_reuseFailAlloc_999_; 
v_reuseFailAlloc_999_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_999_, 0, v___x_995_);
v___x_997_ = v_reuseFailAlloc_999_;
goto v_reusejp_996_;
}
v_reusejp_996_:
{
lean_object* v___x_998_; 
v___x_998_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_998_, 0, v___x_997_);
return v___x_998_;
}
}
}
else
{
lean_object* v_a_1001_; lean_object* v___x_1003_; uint8_t v_isShared_1004_; uint8_t v_isSharedCheck_1010_; 
v_a_1001_ = lean_ctor_get(v___x_984_, 0);
v_isSharedCheck_1010_ = !lean_is_exclusive(v___x_984_);
if (v_isSharedCheck_1010_ == 0)
{
v___x_1003_ = v___x_984_;
v_isShared_1004_ = v_isSharedCheck_1010_;
goto v_resetjp_1002_;
}
else
{
lean_inc(v_a_1001_);
lean_dec(v___x_984_);
v___x_1003_ = lean_box(0);
v_isShared_1004_ = v_isSharedCheck_1010_;
goto v_resetjp_1002_;
}
v_resetjp_1002_:
{
lean_object* v___x_1005_; lean_object* v___x_1007_; 
v___x_1005_ = lp_JunkValues_JunkValues_tacticDischarger(v_script_977_, v_a_1001_);
if (v_isShared_1004_ == 0)
{
lean_ctor_set(v___x_1003_, 0, v___x_1005_);
v___x_1007_ = v___x_1003_;
goto v_reusejp_1006_;
}
else
{
lean_object* v_reuseFailAlloc_1009_; 
v_reuseFailAlloc_1009_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1009_, 0, v___x_1005_);
v___x_1007_ = v_reuseFailAlloc_1009_;
goto v_reusejp_1006_;
}
v_reusejp_1006_:
{
lean_object* v___x_1008_; 
v___x_1008_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1008_, 0, v___x_1007_);
return v___x_1008_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_tacticDischarger_x3f___redArg___boxed(lean_object* v_script_1011_, lean_object* v_a_1012_, lean_object* v_a_1013_){
_start:
{
lean_object* v_res_1014_; 
v_res_1014_ = lp_JunkValues_JunkValues_tacticDischarger_x3f___redArg(v_script_1011_, v_a_1012_);
lean_dec(v_a_1012_);
return v_res_1014_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_tacticDischarger_x3f(lean_object* v_script_1015_, lean_object* v_a_1016_, lean_object* v_a_1017_, lean_object* v_a_1018_, lean_object* v_a_1019_){
_start:
{
lean_object* v___x_1021_; 
v___x_1021_ = lp_JunkValues_JunkValues_tacticDischarger_x3f___redArg(v_script_1015_, v_a_1019_);
return v___x_1021_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_tacticDischarger_x3f___boxed(lean_object* v_script_1022_, lean_object* v_a_1023_, lean_object* v_a_1024_, lean_object* v_a_1025_, lean_object* v_a_1026_, lean_object* v_a_1027_){
_start:
{
lean_object* v_res_1028_; 
v_res_1028_ = lp_JunkValues_JunkValues_tacticDischarger_x3f(v_script_1022_, v_a_1023_, v_a_1024_, v_a_1025_, v_a_1026_);
lean_dec(v_a_1026_);
lean_dec_ref(v_a_1025_);
lean_dec(v_a_1024_);
lean_dec_ref(v_a_1023_);
return v_res_1028_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_firstDischarger_spec__0(lean_object* v_goal_1029_, lean_object* v_as_1030_, size_t v_sz_1031_, size_t v_i_1032_, lean_object* v_b_1033_, lean_object* v___y_1034_, lean_object* v___y_1035_, lean_object* v___y_1036_, lean_object* v___y_1037_){
_start:
{
uint8_t v___x_1039_; 
v___x_1039_ = lean_usize_dec_lt(v_i_1032_, v_sz_1031_);
if (v___x_1039_ == 0)
{
lean_object* v___x_1040_; 
lean_dec_ref(v_goal_1029_);
v___x_1040_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1040_, 0, v_b_1033_);
return v___x_1040_;
}
else
{
lean_object* v_a_1041_; lean_object* v_prove_1042_; lean_object* v___x_1044_; uint8_t v_isShared_1045_; uint8_t v_isSharedCheck_1072_; 
lean_dec_ref(v_b_1033_);
v_a_1041_ = lean_array_uget(v_as_1030_, v_i_1032_);
v_prove_1042_ = lean_ctor_get(v_a_1041_, 1);
v_isSharedCheck_1072_ = !lean_is_exclusive(v_a_1041_);
if (v_isSharedCheck_1072_ == 0)
{
lean_object* v_unused_1073_; 
v_unused_1073_ = lean_ctor_get(v_a_1041_, 0);
lean_dec(v_unused_1073_);
v___x_1044_ = v_a_1041_;
v_isShared_1045_ = v_isSharedCheck_1072_;
goto v_resetjp_1043_;
}
else
{
lean_inc(v_prove_1042_);
lean_dec(v_a_1041_);
v___x_1044_ = lean_box(0);
v_isShared_1045_ = v_isSharedCheck_1072_;
goto v_resetjp_1043_;
}
v_resetjp_1043_:
{
lean_object* v___x_1046_; 
lean_inc(v___y_1037_);
lean_inc_ref(v___y_1036_);
lean_inc(v___y_1035_);
lean_inc_ref(v___y_1034_);
lean_inc_ref(v_goal_1029_);
v___x_1046_ = lean_apply_6(v_prove_1042_, v_goal_1029_, v___y_1034_, v___y_1035_, v___y_1036_, v___y_1037_, lean_box(0));
if (lean_obj_tag(v___x_1046_) == 0)
{
lean_object* v_a_1047_; lean_object* v___x_1049_; uint8_t v_isShared_1050_; uint8_t v_isSharedCheck_1063_; 
v_a_1047_ = lean_ctor_get(v___x_1046_, 0);
v_isSharedCheck_1063_ = !lean_is_exclusive(v___x_1046_);
if (v_isSharedCheck_1063_ == 0)
{
v___x_1049_ = v___x_1046_;
v_isShared_1050_ = v_isSharedCheck_1063_;
goto v_resetjp_1048_;
}
else
{
lean_inc(v_a_1047_);
lean_dec(v___x_1046_);
v___x_1049_ = lean_box(0);
v_isShared_1050_ = v_isSharedCheck_1063_;
goto v_resetjp_1048_;
}
v_resetjp_1048_:
{
lean_object* v___x_1051_; 
v___x_1051_ = lean_box(0);
if (lean_obj_tag(v_a_1047_) == 1)
{
lean_object* v___x_1052_; lean_object* v___x_1054_; 
lean_dec_ref(v_goal_1029_);
v___x_1052_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_1052_, 0, v_a_1047_);
if (v_isShared_1045_ == 0)
{
lean_ctor_set(v___x_1044_, 1, v___x_1051_);
lean_ctor_set(v___x_1044_, 0, v___x_1052_);
v___x_1054_ = v___x_1044_;
goto v_reusejp_1053_;
}
else
{
lean_object* v_reuseFailAlloc_1058_; 
v_reuseFailAlloc_1058_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1058_, 0, v___x_1052_);
lean_ctor_set(v_reuseFailAlloc_1058_, 1, v___x_1051_);
v___x_1054_ = v_reuseFailAlloc_1058_;
goto v_reusejp_1053_;
}
v_reusejp_1053_:
{
lean_object* v___x_1056_; 
if (v_isShared_1050_ == 0)
{
lean_ctor_set(v___x_1049_, 0, v___x_1054_);
v___x_1056_ = v___x_1049_;
goto v_reusejp_1055_;
}
else
{
lean_object* v_reuseFailAlloc_1057_; 
v_reuseFailAlloc_1057_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1057_, 0, v___x_1054_);
v___x_1056_ = v_reuseFailAlloc_1057_;
goto v_reusejp_1055_;
}
v_reusejp_1055_:
{
return v___x_1056_;
}
}
}
else
{
lean_object* v___x_1059_; size_t v___x_1060_; size_t v___x_1061_; 
lean_del_object(v___x_1049_);
lean_dec(v_a_1047_);
lean_del_object(v___x_1044_);
v___x_1059_ = ((lean_object*)(lp_JunkValues_JunkValues_assumptionDischarger___lam__0___closed__0));
v___x_1060_ = ((size_t)1ULL);
v___x_1061_ = lean_usize_add(v_i_1032_, v___x_1060_);
v_i_1032_ = v___x_1061_;
v_b_1033_ = v___x_1059_;
goto _start;
}
}
}
else
{
lean_object* v_a_1064_; lean_object* v___x_1066_; uint8_t v_isShared_1067_; uint8_t v_isSharedCheck_1071_; 
lean_del_object(v___x_1044_);
lean_dec_ref(v_goal_1029_);
v_a_1064_ = lean_ctor_get(v___x_1046_, 0);
v_isSharedCheck_1071_ = !lean_is_exclusive(v___x_1046_);
if (v_isSharedCheck_1071_ == 0)
{
v___x_1066_ = v___x_1046_;
v_isShared_1067_ = v_isSharedCheck_1071_;
goto v_resetjp_1065_;
}
else
{
lean_inc(v_a_1064_);
lean_dec(v___x_1046_);
v___x_1066_ = lean_box(0);
v_isShared_1067_ = v_isSharedCheck_1071_;
goto v_resetjp_1065_;
}
v_resetjp_1065_:
{
lean_object* v___x_1069_; 
if (v_isShared_1067_ == 0)
{
v___x_1069_ = v___x_1066_;
goto v_reusejp_1068_;
}
else
{
lean_object* v_reuseFailAlloc_1070_; 
v_reuseFailAlloc_1070_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1070_, 0, v_a_1064_);
v___x_1069_ = v_reuseFailAlloc_1070_;
goto v_reusejp_1068_;
}
v_reusejp_1068_:
{
return v___x_1069_;
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_firstDischarger_spec__0___boxed(lean_object* v_goal_1074_, lean_object* v_as_1075_, lean_object* v_sz_1076_, lean_object* v_i_1077_, lean_object* v_b_1078_, lean_object* v___y_1079_, lean_object* v___y_1080_, lean_object* v___y_1081_, lean_object* v___y_1082_, lean_object* v___y_1083_){
_start:
{
size_t v_sz_boxed_1084_; size_t v_i_boxed_1085_; lean_object* v_res_1086_; 
v_sz_boxed_1084_ = lean_unbox_usize(v_sz_1076_);
lean_dec(v_sz_1076_);
v_i_boxed_1085_ = lean_unbox_usize(v_i_1077_);
lean_dec(v_i_1077_);
v_res_1086_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_firstDischarger_spec__0(v_goal_1074_, v_as_1075_, v_sz_boxed_1084_, v_i_boxed_1085_, v_b_1078_, v___y_1079_, v___y_1080_, v___y_1081_, v___y_1082_);
lean_dec(v___y_1082_);
lean_dec_ref(v___y_1081_);
lean_dec(v___y_1080_);
lean_dec_ref(v___y_1079_);
lean_dec_ref(v_as_1075_);
return v_res_1086_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_firstDischarger___lam__0(lean_object* v_ds_1087_, lean_object* v_goal_1088_, lean_object* v___y_1089_, lean_object* v___y_1090_, lean_object* v___y_1091_, lean_object* v___y_1092_){
_start:
{
lean_object* v___x_1094_; lean_object* v___x_1095_; size_t v_sz_1096_; size_t v___x_1097_; lean_object* v___x_1098_; 
v___x_1094_ = lean_box(0);
v___x_1095_ = ((lean_object*)(lp_JunkValues_JunkValues_assumptionDischarger___lam__0___closed__0));
v_sz_1096_ = lean_array_size(v_ds_1087_);
v___x_1097_ = ((size_t)0ULL);
v___x_1098_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_firstDischarger_spec__0(v_goal_1088_, v_ds_1087_, v_sz_1096_, v___x_1097_, v___x_1095_, v___y_1089_, v___y_1090_, v___y_1091_, v___y_1092_);
if (lean_obj_tag(v___x_1098_) == 0)
{
lean_object* v_a_1099_; lean_object* v___x_1101_; uint8_t v_isShared_1102_; uint8_t v_isSharedCheck_1111_; 
v_a_1099_ = lean_ctor_get(v___x_1098_, 0);
v_isSharedCheck_1111_ = !lean_is_exclusive(v___x_1098_);
if (v_isSharedCheck_1111_ == 0)
{
v___x_1101_ = v___x_1098_;
v_isShared_1102_ = v_isSharedCheck_1111_;
goto v_resetjp_1100_;
}
else
{
lean_inc(v_a_1099_);
lean_dec(v___x_1098_);
v___x_1101_ = lean_box(0);
v_isShared_1102_ = v_isSharedCheck_1111_;
goto v_resetjp_1100_;
}
v_resetjp_1100_:
{
lean_object* v_fst_1103_; 
v_fst_1103_ = lean_ctor_get(v_a_1099_, 0);
lean_inc(v_fst_1103_);
lean_dec(v_a_1099_);
if (lean_obj_tag(v_fst_1103_) == 0)
{
lean_object* v___x_1105_; 
if (v_isShared_1102_ == 0)
{
lean_ctor_set(v___x_1101_, 0, v___x_1094_);
v___x_1105_ = v___x_1101_;
goto v_reusejp_1104_;
}
else
{
lean_object* v_reuseFailAlloc_1106_; 
v_reuseFailAlloc_1106_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1106_, 0, v___x_1094_);
v___x_1105_ = v_reuseFailAlloc_1106_;
goto v_reusejp_1104_;
}
v_reusejp_1104_:
{
return v___x_1105_;
}
}
else
{
lean_object* v_val_1107_; lean_object* v___x_1109_; 
v_val_1107_ = lean_ctor_get(v_fst_1103_, 0);
lean_inc(v_val_1107_);
lean_dec_ref_known(v_fst_1103_, 1);
if (v_isShared_1102_ == 0)
{
lean_ctor_set(v___x_1101_, 0, v_val_1107_);
v___x_1109_ = v___x_1101_;
goto v_reusejp_1108_;
}
else
{
lean_object* v_reuseFailAlloc_1110_; 
v_reuseFailAlloc_1110_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1110_, 0, v_val_1107_);
v___x_1109_ = v_reuseFailAlloc_1110_;
goto v_reusejp_1108_;
}
v_reusejp_1108_:
{
return v___x_1109_;
}
}
}
}
else
{
lean_object* v_a_1112_; lean_object* v___x_1114_; uint8_t v_isShared_1115_; uint8_t v_isSharedCheck_1119_; 
v_a_1112_ = lean_ctor_get(v___x_1098_, 0);
v_isSharedCheck_1119_ = !lean_is_exclusive(v___x_1098_);
if (v_isSharedCheck_1119_ == 0)
{
v___x_1114_ = v___x_1098_;
v_isShared_1115_ = v_isSharedCheck_1119_;
goto v_resetjp_1113_;
}
else
{
lean_inc(v_a_1112_);
lean_dec(v___x_1098_);
v___x_1114_ = lean_box(0);
v_isShared_1115_ = v_isSharedCheck_1119_;
goto v_resetjp_1113_;
}
v_resetjp_1113_:
{
lean_object* v___x_1117_; 
if (v_isShared_1115_ == 0)
{
v___x_1117_ = v___x_1114_;
goto v_reusejp_1116_;
}
else
{
lean_object* v_reuseFailAlloc_1118_; 
v_reuseFailAlloc_1118_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1118_, 0, v_a_1112_);
v___x_1117_ = v_reuseFailAlloc_1118_;
goto v_reusejp_1116_;
}
v_reusejp_1116_:
{
return v___x_1117_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_firstDischarger___lam__0___boxed(lean_object* v_ds_1120_, lean_object* v_goal_1121_, lean_object* v___y_1122_, lean_object* v___y_1123_, lean_object* v___y_1124_, lean_object* v___y_1125_, lean_object* v___y_1126_){
_start:
{
lean_object* v_res_1127_; 
v_res_1127_ = lp_JunkValues_JunkValues_firstDischarger___lam__0(v_ds_1120_, v_goal_1121_, v___y_1122_, v___y_1123_, v___y_1124_, v___y_1125_);
lean_dec(v___y_1125_);
lean_dec_ref(v___y_1124_);
lean_dec(v___y_1123_);
lean_dec_ref(v___y_1122_);
lean_dec_ref(v_ds_1120_);
return v_res_1127_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_List_mapTR_loop___at___00JunkValues_firstDischarger_spec__1(lean_object* v_a_1128_, lean_object* v_a_1129_){
_start:
{
if (lean_obj_tag(v_a_1128_) == 0)
{
lean_object* v___x_1130_; 
v___x_1130_ = l_List_reverse___redArg(v_a_1129_);
return v___x_1130_;
}
else
{
lean_object* v_head_1131_; lean_object* v_tail_1132_; lean_object* v___x_1134_; uint8_t v_isShared_1135_; uint8_t v_isSharedCheck_1141_; 
v_head_1131_ = lean_ctor_get(v_a_1128_, 0);
v_tail_1132_ = lean_ctor_get(v_a_1128_, 1);
v_isSharedCheck_1141_ = !lean_is_exclusive(v_a_1128_);
if (v_isSharedCheck_1141_ == 0)
{
v___x_1134_ = v_a_1128_;
v_isShared_1135_ = v_isSharedCheck_1141_;
goto v_resetjp_1133_;
}
else
{
lean_inc(v_tail_1132_);
lean_inc(v_head_1131_);
lean_dec(v_a_1128_);
v___x_1134_ = lean_box(0);
v_isShared_1135_ = v_isSharedCheck_1141_;
goto v_resetjp_1133_;
}
v_resetjp_1133_:
{
lean_object* v_name_1136_; lean_object* v___x_1138_; 
v_name_1136_ = lean_ctor_get(v_head_1131_, 0);
lean_inc_ref(v_name_1136_);
lean_dec(v_head_1131_);
if (v_isShared_1135_ == 0)
{
lean_ctor_set(v___x_1134_, 1, v_a_1129_);
lean_ctor_set(v___x_1134_, 0, v_name_1136_);
v___x_1138_ = v___x_1134_;
goto v_reusejp_1137_;
}
else
{
lean_object* v_reuseFailAlloc_1140_; 
v_reuseFailAlloc_1140_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1140_, 0, v_name_1136_);
lean_ctor_set(v_reuseFailAlloc_1140_, 1, v_a_1129_);
v___x_1138_ = v_reuseFailAlloc_1140_;
goto v_reusejp_1137_;
}
v_reusejp_1137_:
{
v_a_1128_ = v_tail_1132_;
v_a_1129_ = v___x_1138_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_firstDischarger(lean_object* v_ds_1143_){
_start:
{
lean_object* v___f_1144_; lean_object* v___x_1145_; lean_object* v___x_1146_; lean_object* v___x_1147_; lean_object* v___x_1148_; lean_object* v___x_1149_; lean_object* v___x_1150_; 
lean_inc_ref(v_ds_1143_);
v___f_1144_ = lean_alloc_closure((void*)(lp_JunkValues_JunkValues_firstDischarger___lam__0___boxed), 7, 1);
lean_closure_set(v___f_1144_, 0, v_ds_1143_);
v___x_1145_ = ((lean_object*)(lp_JunkValues_JunkValues_firstDischarger___closed__0));
v___x_1146_ = lean_array_to_list(v_ds_1143_);
v___x_1147_ = lean_box(0);
v___x_1148_ = lp_JunkValues_List_mapTR_loop___at___00JunkValues_firstDischarger_spec__1(v___x_1146_, v___x_1147_);
v___x_1149_ = l_String_intercalate(v___x_1145_, v___x_1148_);
v___x_1150_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1150_, 0, v___x_1149_);
lean_ctor_set(v___x_1150_, 1, v___f_1144_);
return v___x_1150_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_classify_spec__0(lean_object* v_cfg_1154_, lean_object* v_as_1155_, size_t v_sz_1156_, size_t v_i_1157_, lean_object* v_b_1158_, lean_object* v___y_1159_, lean_object* v___y_1160_, lean_object* v___y_1161_, lean_object* v___y_1162_){
_start:
{
uint8_t v___x_1164_; 
v___x_1164_ = lean_usize_dec_lt(v_i_1157_, v_sz_1156_);
if (v___x_1164_ == 0)
{
lean_object* v___x_1165_; 
lean_dec_ref(v_cfg_1154_);
v___x_1165_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1165_, 0, v_b_1158_);
return v___x_1165_;
}
else
{
lean_object* v_discharger_1166_; lean_object* v_prove_1167_; lean_object* v___x_1169_; uint8_t v_isShared_1170_; uint8_t v_isSharedCheck_1207_; 
lean_dec_ref(v_b_1158_);
v_discharger_1166_ = lean_ctor_get(v_cfg_1154_, 0);
lean_inc_ref(v_discharger_1166_);
v_prove_1167_ = lean_ctor_get(v_discharger_1166_, 1);
v_isSharedCheck_1207_ = !lean_is_exclusive(v_discharger_1166_);
if (v_isSharedCheck_1207_ == 0)
{
lean_object* v_unused_1208_; 
v_unused_1208_ = lean_ctor_get(v_discharger_1166_, 0);
lean_dec(v_unused_1208_);
v___x_1169_ = v_discharger_1166_;
v_isShared_1170_ = v_isSharedCheck_1207_;
goto v_resetjp_1168_;
}
else
{
lean_inc(v_prove_1167_);
lean_dec(v_discharger_1166_);
v___x_1169_ = lean_box(0);
v_isShared_1170_ = v_isSharedCheck_1207_;
goto v_resetjp_1168_;
}
v_resetjp_1168_:
{
lean_object* v_a_1171_; lean_object* v___x_1172_; lean_object* v___x_1173_; 
v_a_1171_ = lean_array_uget_borrowed(v_as_1155_, v_i_1157_);
lean_inc(v_a_1171_);
v___x_1172_ = lp_JunkValues_JunkValues_safetyGoal(v_a_1171_);
lean_inc(v___y_1162_);
lean_inc_ref(v___y_1161_);
lean_inc(v___y_1160_);
lean_inc_ref(v___y_1159_);
v___x_1173_ = lean_apply_6(v_prove_1167_, v___x_1172_, v___y_1159_, v___y_1160_, v___y_1161_, v___y_1162_, lean_box(0));
if (lean_obj_tag(v___x_1173_) == 0)
{
lean_object* v_a_1174_; lean_object* v___x_1176_; uint8_t v_isShared_1177_; uint8_t v_isSharedCheck_1198_; 
v_a_1174_ = lean_ctor_get(v___x_1173_, 0);
v_isSharedCheck_1198_ = !lean_is_exclusive(v___x_1173_);
if (v_isSharedCheck_1198_ == 0)
{
v___x_1176_ = v___x_1173_;
v_isShared_1177_ = v_isSharedCheck_1198_;
goto v_resetjp_1175_;
}
else
{
lean_inc(v_a_1174_);
lean_dec(v___x_1173_);
v___x_1176_ = lean_box(0);
v_isShared_1177_ = v_isSharedCheck_1198_;
goto v_resetjp_1175_;
}
v_resetjp_1175_:
{
lean_object* v___x_1178_; 
v___x_1178_ = lean_box(0);
if (lean_obj_tag(v_a_1174_) == 1)
{
lean_object* v_val_1179_; lean_object* v___x_1181_; uint8_t v_isShared_1182_; uint8_t v_isSharedCheck_1193_; 
lean_dec_ref(v_cfg_1154_);
v_val_1179_ = lean_ctor_get(v_a_1174_, 0);
v_isSharedCheck_1193_ = !lean_is_exclusive(v_a_1174_);
if (v_isSharedCheck_1193_ == 0)
{
v___x_1181_ = v_a_1174_;
v_isShared_1182_ = v_isSharedCheck_1193_;
goto v_resetjp_1180_;
}
else
{
lean_inc(v_val_1179_);
lean_dec(v_a_1174_);
v___x_1181_ = lean_box(0);
v_isShared_1182_ = v_isSharedCheck_1193_;
goto v_resetjp_1180_;
}
v_resetjp_1180_:
{
lean_object* v___x_1183_; lean_object* v___x_1185_; 
v___x_1183_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1183_, 0, v_val_1179_);
if (v_isShared_1182_ == 0)
{
lean_ctor_set(v___x_1181_, 0, v___x_1183_);
v___x_1185_ = v___x_1181_;
goto v_reusejp_1184_;
}
else
{
lean_object* v_reuseFailAlloc_1192_; 
v_reuseFailAlloc_1192_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1192_, 0, v___x_1183_);
v___x_1185_ = v_reuseFailAlloc_1192_;
goto v_reusejp_1184_;
}
v_reusejp_1184_:
{
lean_object* v___x_1187_; 
if (v_isShared_1170_ == 0)
{
lean_ctor_set(v___x_1169_, 1, v___x_1178_);
lean_ctor_set(v___x_1169_, 0, v___x_1185_);
v___x_1187_ = v___x_1169_;
goto v_reusejp_1186_;
}
else
{
lean_object* v_reuseFailAlloc_1191_; 
v_reuseFailAlloc_1191_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1191_, 0, v___x_1185_);
lean_ctor_set(v_reuseFailAlloc_1191_, 1, v___x_1178_);
v___x_1187_ = v_reuseFailAlloc_1191_;
goto v_reusejp_1186_;
}
v_reusejp_1186_:
{
lean_object* v___x_1189_; 
if (v_isShared_1177_ == 0)
{
lean_ctor_set(v___x_1176_, 0, v___x_1187_);
v___x_1189_ = v___x_1176_;
goto v_reusejp_1188_;
}
else
{
lean_object* v_reuseFailAlloc_1190_; 
v_reuseFailAlloc_1190_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1190_, 0, v___x_1187_);
v___x_1189_ = v_reuseFailAlloc_1190_;
goto v_reusejp_1188_;
}
v_reusejp_1188_:
{
return v___x_1189_;
}
}
}
}
}
else
{
lean_object* v___x_1194_; size_t v___x_1195_; size_t v___x_1196_; 
lean_del_object(v___x_1176_);
lean_dec(v_a_1174_);
lean_del_object(v___x_1169_);
v___x_1194_ = ((lean_object*)(lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_classify_spec__0___closed__0));
v___x_1195_ = ((size_t)1ULL);
v___x_1196_ = lean_usize_add(v_i_1157_, v___x_1195_);
v_i_1157_ = v___x_1196_;
v_b_1158_ = v___x_1194_;
goto _start;
}
}
}
else
{
lean_object* v_a_1199_; lean_object* v___x_1201_; uint8_t v_isShared_1202_; uint8_t v_isSharedCheck_1206_; 
lean_del_object(v___x_1169_);
lean_dec_ref(v_cfg_1154_);
v_a_1199_ = lean_ctor_get(v___x_1173_, 0);
v_isSharedCheck_1206_ = !lean_is_exclusive(v___x_1173_);
if (v_isSharedCheck_1206_ == 0)
{
v___x_1201_ = v___x_1173_;
v_isShared_1202_ = v_isSharedCheck_1206_;
goto v_resetjp_1200_;
}
else
{
lean_inc(v_a_1199_);
lean_dec(v___x_1173_);
v___x_1201_ = lean_box(0);
v_isShared_1202_ = v_isSharedCheck_1206_;
goto v_resetjp_1200_;
}
v_resetjp_1200_:
{
lean_object* v___x_1204_; 
if (v_isShared_1202_ == 0)
{
v___x_1204_ = v___x_1201_;
goto v_reusejp_1203_;
}
else
{
lean_object* v_reuseFailAlloc_1205_; 
v_reuseFailAlloc_1205_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1205_, 0, v_a_1199_);
v___x_1204_ = v_reuseFailAlloc_1205_;
goto v_reusejp_1203_;
}
v_reusejp_1203_:
{
return v___x_1204_;
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_classify_spec__0___boxed(lean_object* v_cfg_1209_, lean_object* v_as_1210_, lean_object* v_sz_1211_, lean_object* v_i_1212_, lean_object* v_b_1213_, lean_object* v___y_1214_, lean_object* v___y_1215_, lean_object* v___y_1216_, lean_object* v___y_1217_, lean_object* v___y_1218_){
_start:
{
size_t v_sz_boxed_1219_; size_t v_i_boxed_1220_; lean_object* v_res_1221_; 
v_sz_boxed_1219_ = lean_unbox_usize(v_sz_1211_);
lean_dec(v_sz_1211_);
v_i_boxed_1220_ = lean_unbox_usize(v_i_1212_);
lean_dec(v_i_1212_);
v_res_1221_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_classify_spec__0(v_cfg_1209_, v_as_1210_, v_sz_boxed_1219_, v_i_boxed_1220_, v_b_1213_, v___y_1214_, v___y_1215_, v___y_1216_, v___y_1217_);
lean_dec(v___y_1217_);
lean_dec_ref(v___y_1216_);
lean_dec(v___y_1215_);
lean_dec_ref(v___y_1214_);
lean_dec_ref(v_as_1210_);
return v_res_1221_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_classify_spec__1(lean_object* v_cfg_1224_, lean_object* v_as_1225_, size_t v_sz_1226_, size_t v_i_1227_, lean_object* v_b_1228_, lean_object* v___y_1229_, lean_object* v___y_1230_, lean_object* v___y_1231_, lean_object* v___y_1232_){
_start:
{
uint8_t v___x_1234_; 
v___x_1234_ = lean_usize_dec_lt(v_i_1227_, v_sz_1226_);
if (v___x_1234_ == 0)
{
lean_object* v___x_1235_; 
lean_dec_ref(v_cfg_1224_);
v___x_1235_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1235_, 0, v_b_1228_);
return v___x_1235_;
}
else
{
lean_object* v_discharger_1236_; lean_object* v_prove_1237_; lean_object* v_a_1238_; lean_object* v___x_1239_; 
v_discharger_1236_ = lean_ctor_get(v_cfg_1224_, 0);
v_prove_1237_ = lean_ctor_get(v_discharger_1236_, 1);
v_a_1238_ = lean_array_uget_borrowed(v_as_1225_, v_i_1227_);
lean_inc_ref(v_prove_1237_);
lean_inc(v___y_1232_);
lean_inc_ref(v___y_1231_);
lean_inc(v___y_1230_);
lean_inc_ref(v___y_1229_);
lean_inc(v_a_1238_);
v___x_1239_ = lean_apply_6(v_prove_1237_, v_a_1238_, v___y_1229_, v___y_1230_, v___y_1231_, v___y_1232_, lean_box(0));
if (lean_obj_tag(v___x_1239_) == 0)
{
lean_object* v_a_1240_; lean_object* v___x_1242_; uint8_t v_isShared_1243_; uint8_t v_isSharedCheck_1272_; 
v_a_1240_ = lean_ctor_get(v___x_1239_, 0);
v_isSharedCheck_1272_ = !lean_is_exclusive(v___x_1239_);
if (v_isSharedCheck_1272_ == 0)
{
v___x_1242_ = v___x_1239_;
v_isShared_1243_ = v_isSharedCheck_1272_;
goto v_resetjp_1241_;
}
else
{
lean_inc(v_a_1240_);
lean_dec(v___x_1239_);
v___x_1242_ = lean_box(0);
v_isShared_1243_ = v_isSharedCheck_1272_;
goto v_resetjp_1241_;
}
v_resetjp_1241_:
{
if (lean_obj_tag(v_a_1240_) == 0)
{
lean_object* v_snd_1244_; lean_object* v___x_1246_; uint8_t v_isShared_1247_; uint8_t v_isSharedCheck_1255_; 
lean_dec_ref(v_cfg_1224_);
v_snd_1244_ = lean_ctor_get(v_b_1228_, 1);
v_isSharedCheck_1255_ = !lean_is_exclusive(v_b_1228_);
if (v_isSharedCheck_1255_ == 0)
{
lean_object* v_unused_1256_; 
v_unused_1256_ = lean_ctor_get(v_b_1228_, 0);
lean_dec(v_unused_1256_);
v___x_1246_ = v_b_1228_;
v_isShared_1247_ = v_isSharedCheck_1255_;
goto v_resetjp_1245_;
}
else
{
lean_inc(v_snd_1244_);
lean_dec(v_b_1228_);
v___x_1246_ = lean_box(0);
v_isShared_1247_ = v_isSharedCheck_1255_;
goto v_resetjp_1245_;
}
v_resetjp_1245_:
{
lean_object* v___x_1248_; lean_object* v___x_1250_; 
v___x_1248_ = ((lean_object*)(lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_classify_spec__1___closed__0));
if (v_isShared_1247_ == 0)
{
lean_ctor_set(v___x_1246_, 0, v___x_1248_);
v___x_1250_ = v___x_1246_;
goto v_reusejp_1249_;
}
else
{
lean_object* v_reuseFailAlloc_1254_; 
v_reuseFailAlloc_1254_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1254_, 0, v___x_1248_);
lean_ctor_set(v_reuseFailAlloc_1254_, 1, v_snd_1244_);
v___x_1250_ = v_reuseFailAlloc_1254_;
goto v_reusejp_1249_;
}
v_reusejp_1249_:
{
lean_object* v___x_1252_; 
if (v_isShared_1243_ == 0)
{
lean_ctor_set(v___x_1242_, 0, v___x_1250_);
v___x_1252_ = v___x_1242_;
goto v_reusejp_1251_;
}
else
{
lean_object* v_reuseFailAlloc_1253_; 
v_reuseFailAlloc_1253_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1253_, 0, v___x_1250_);
v___x_1252_ = v_reuseFailAlloc_1253_;
goto v_reusejp_1251_;
}
v_reusejp_1251_:
{
return v___x_1252_;
}
}
}
}
else
{
lean_object* v_snd_1257_; lean_object* v___x_1259_; uint8_t v_isShared_1260_; uint8_t v_isSharedCheck_1270_; 
lean_del_object(v___x_1242_);
v_snd_1257_ = lean_ctor_get(v_b_1228_, 1);
v_isSharedCheck_1270_ = !lean_is_exclusive(v_b_1228_);
if (v_isSharedCheck_1270_ == 0)
{
lean_object* v_unused_1271_; 
v_unused_1271_ = lean_ctor_get(v_b_1228_, 0);
lean_dec(v_unused_1271_);
v___x_1259_ = v_b_1228_;
v_isShared_1260_ = v_isSharedCheck_1270_;
goto v_resetjp_1258_;
}
else
{
lean_inc(v_snd_1257_);
lean_dec(v_b_1228_);
v___x_1259_ = lean_box(0);
v_isShared_1260_ = v_isSharedCheck_1270_;
goto v_resetjp_1258_;
}
v_resetjp_1258_:
{
lean_object* v___x_1261_; lean_object* v___y_1263_; 
v___x_1261_ = lean_box(0);
if (lean_obj_tag(v_snd_1257_) == 0)
{
v___y_1263_ = v_a_1240_;
goto v___jp_1262_;
}
else
{
lean_dec_ref_known(v_a_1240_, 1);
v___y_1263_ = v_snd_1257_;
goto v___jp_1262_;
}
v___jp_1262_:
{
lean_object* v___x_1265_; 
if (v_isShared_1260_ == 0)
{
lean_ctor_set(v___x_1259_, 1, v___y_1263_);
lean_ctor_set(v___x_1259_, 0, v___x_1261_);
v___x_1265_ = v___x_1259_;
goto v_reusejp_1264_;
}
else
{
lean_object* v_reuseFailAlloc_1269_; 
v_reuseFailAlloc_1269_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1269_, 0, v___x_1261_);
lean_ctor_set(v_reuseFailAlloc_1269_, 1, v___y_1263_);
v___x_1265_ = v_reuseFailAlloc_1269_;
goto v_reusejp_1264_;
}
v_reusejp_1264_:
{
size_t v___x_1266_; size_t v___x_1267_; 
v___x_1266_ = ((size_t)1ULL);
v___x_1267_ = lean_usize_add(v_i_1227_, v___x_1266_);
v_i_1227_ = v___x_1267_;
v_b_1228_ = v___x_1265_;
goto _start;
}
}
}
}
}
}
else
{
lean_object* v_a_1273_; lean_object* v___x_1275_; uint8_t v_isShared_1276_; uint8_t v_isSharedCheck_1280_; 
lean_dec_ref(v_b_1228_);
lean_dec_ref(v_cfg_1224_);
v_a_1273_ = lean_ctor_get(v___x_1239_, 0);
v_isSharedCheck_1280_ = !lean_is_exclusive(v___x_1239_);
if (v_isSharedCheck_1280_ == 0)
{
v___x_1275_ = v___x_1239_;
v_isShared_1276_ = v_isSharedCheck_1280_;
goto v_resetjp_1274_;
}
else
{
lean_inc(v_a_1273_);
lean_dec(v___x_1239_);
v___x_1275_ = lean_box(0);
v_isShared_1276_ = v_isSharedCheck_1280_;
goto v_resetjp_1274_;
}
v_resetjp_1274_:
{
lean_object* v___x_1278_; 
if (v_isShared_1276_ == 0)
{
v___x_1278_ = v___x_1275_;
goto v_reusejp_1277_;
}
else
{
lean_object* v_reuseFailAlloc_1279_; 
v_reuseFailAlloc_1279_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1279_, 0, v_a_1273_);
v___x_1278_ = v_reuseFailAlloc_1279_;
goto v_reusejp_1277_;
}
v_reusejp_1277_:
{
return v___x_1278_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_classify_spec__1___boxed(lean_object* v_cfg_1281_, lean_object* v_as_1282_, lean_object* v_sz_1283_, lean_object* v_i_1284_, lean_object* v_b_1285_, lean_object* v___y_1286_, lean_object* v___y_1287_, lean_object* v___y_1288_, lean_object* v___y_1289_, lean_object* v___y_1290_){
_start:
{
size_t v_sz_boxed_1291_; size_t v_i_boxed_1292_; lean_object* v_res_1293_; 
v_sz_boxed_1291_ = lean_unbox_usize(v_sz_1283_);
lean_dec(v_sz_1283_);
v_i_boxed_1292_ = lean_unbox_usize(v_i_1284_);
lean_dec(v_i_1284_);
v_res_1293_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_classify_spec__1(v_cfg_1281_, v_as_1282_, v_sz_boxed_1291_, v_i_boxed_1292_, v_b_1285_, v___y_1286_, v___y_1287_, v___y_1288_, v___y_1289_);
lean_dec(v___y_1289_);
lean_dec_ref(v___y_1288_);
lean_dec(v___y_1287_);
lean_dec_ref(v___y_1286_);
lean_dec_ref(v_as_1282_);
return v_res_1293_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_classify(lean_object* v_guards_1296_, lean_object* v_cfg_1297_, lean_object* v_a_1298_, lean_object* v_a_1299_, lean_object* v_a_1300_, lean_object* v_a_1301_){
_start:
{
lean_object* v___x_1303_; size_t v_sz_1304_; size_t v___x_1305_; lean_object* v___x_1306_; 
v___x_1303_ = ((lean_object*)(lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_classify_spec__0___closed__0));
v_sz_1304_ = lean_array_size(v_guards_1296_);
v___x_1305_ = ((size_t)0ULL);
lean_inc_ref(v_cfg_1297_);
v___x_1306_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_classify_spec__0(v_cfg_1297_, v_guards_1296_, v_sz_1304_, v___x_1305_, v___x_1303_, v_a_1298_, v_a_1299_, v_a_1300_, v_a_1301_);
if (lean_obj_tag(v___x_1306_) == 0)
{
lean_object* v_a_1307_; lean_object* v___x_1309_; uint8_t v_isShared_1310_; uint8_t v_isSharedCheck_1363_; 
v_a_1307_ = lean_ctor_get(v___x_1306_, 0);
v_isSharedCheck_1363_ = !lean_is_exclusive(v___x_1306_);
if (v_isSharedCheck_1363_ == 0)
{
v___x_1309_ = v___x_1306_;
v_isShared_1310_ = v_isSharedCheck_1363_;
goto v_resetjp_1308_;
}
else
{
lean_inc(v_a_1307_);
lean_dec(v___x_1306_);
v___x_1309_ = lean_box(0);
v_isShared_1310_ = v_isSharedCheck_1363_;
goto v_resetjp_1308_;
}
v_resetjp_1308_:
{
lean_object* v_fst_1316_; 
v_fst_1316_ = lean_ctor_get(v_a_1307_, 0);
lean_inc(v_fst_1316_);
lean_dec(v_a_1307_);
if (lean_obj_tag(v_fst_1316_) == 0)
{
uint8_t v_checkTriggered_1317_; 
v_checkTriggered_1317_ = lean_ctor_get_uint8(v_cfg_1297_, sizeof(void*)*1);
if (v_checkTriggered_1317_ == 0)
{
lean_dec_ref(v_cfg_1297_);
goto v___jp_1311_;
}
else
{
lean_object* v_discharger_1318_; lean_object* v___x_1319_; lean_object* v___x_1320_; uint8_t v___x_1321_; 
v_discharger_1318_ = lean_ctor_get(v_cfg_1297_, 0);
lean_inc_ref(v_discharger_1318_);
v___x_1319_ = lean_array_get_size(v_guards_1296_);
v___x_1320_ = lean_unsigned_to_nat(0u);
v___x_1321_ = lean_nat_dec_eq(v___x_1319_, v___x_1320_);
if (v___x_1321_ == 0)
{
lean_object* v___x_1322_; lean_object* v___x_1323_; 
lean_del_object(v___x_1309_);
v___x_1322_ = ((lean_object*)(lp_JunkValues_JunkValues_classify___closed__0));
v___x_1323_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_classify_spec__1(v_cfg_1297_, v_guards_1296_, v_sz_1304_, v___x_1305_, v___x_1322_, v_a_1298_, v_a_1299_, v_a_1300_, v_a_1301_);
if (lean_obj_tag(v___x_1323_) == 0)
{
lean_object* v_a_1324_; lean_object* v___x_1326_; uint8_t v_isShared_1327_; uint8_t v_isSharedCheck_1346_; 
v_a_1324_ = lean_ctor_get(v___x_1323_, 0);
v_isSharedCheck_1346_ = !lean_is_exclusive(v___x_1323_);
if (v_isSharedCheck_1346_ == 0)
{
v___x_1326_ = v___x_1323_;
v_isShared_1327_ = v_isSharedCheck_1346_;
goto v_resetjp_1325_;
}
else
{
lean_inc(v_a_1324_);
lean_dec(v___x_1323_);
v___x_1326_ = lean_box(0);
v_isShared_1327_ = v_isSharedCheck_1346_;
goto v_resetjp_1325_;
}
v_resetjp_1325_:
{
lean_object* v___y_1329_; lean_object* v_fst_1334_; 
v_fst_1334_ = lean_ctor_get(v_a_1324_, 0);
lean_inc(v_fst_1334_);
if (lean_obj_tag(v_fst_1334_) == 0)
{
lean_object* v_snd_1335_; 
v_snd_1335_ = lean_ctor_get(v_a_1324_, 1);
lean_inc(v_snd_1335_);
lean_dec(v_a_1324_);
if (lean_obj_tag(v_snd_1335_) == 0)
{
lean_object* v_name_1336_; 
v_name_1336_ = lean_ctor_get(v_discharger_1318_, 0);
lean_inc_ref(v_name_1336_);
lean_dec_ref(v_discharger_1318_);
v___y_1329_ = v_name_1336_;
goto v___jp_1328_;
}
else
{
lean_object* v_val_1337_; 
lean_dec_ref(v_discharger_1318_);
v_val_1337_ = lean_ctor_get(v_snd_1335_, 0);
lean_inc(v_val_1337_);
lean_dec_ref_known(v_snd_1335_, 1);
v___y_1329_ = v_val_1337_;
goto v___jp_1328_;
}
}
else
{
lean_object* v_val_1338_; lean_object* v___x_1340_; uint8_t v_isShared_1341_; uint8_t v_isSharedCheck_1345_; 
lean_del_object(v___x_1326_);
lean_dec(v_a_1324_);
lean_dec_ref(v_discharger_1318_);
v_val_1338_ = lean_ctor_get(v_fst_1334_, 0);
v_isSharedCheck_1345_ = !lean_is_exclusive(v_fst_1334_);
if (v_isSharedCheck_1345_ == 0)
{
v___x_1340_ = v_fst_1334_;
v_isShared_1341_ = v_isSharedCheck_1345_;
goto v_resetjp_1339_;
}
else
{
lean_inc(v_val_1338_);
lean_dec(v_fst_1334_);
v___x_1340_ = lean_box(0);
v_isShared_1341_ = v_isSharedCheck_1345_;
goto v_resetjp_1339_;
}
v_resetjp_1339_:
{
lean_object* v___x_1343_; 
if (v_isShared_1341_ == 0)
{
lean_ctor_set_tag(v___x_1340_, 0);
v___x_1343_ = v___x_1340_;
goto v_reusejp_1342_;
}
else
{
lean_object* v_reuseFailAlloc_1344_; 
v_reuseFailAlloc_1344_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1344_, 0, v_val_1338_);
v___x_1343_ = v_reuseFailAlloc_1344_;
goto v_reusejp_1342_;
}
v_reusejp_1342_:
{
return v___x_1343_;
}
}
}
v___jp_1328_:
{
lean_object* v___x_1330_; lean_object* v___x_1332_; 
v___x_1330_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1330_, 0, v___y_1329_);
if (v_isShared_1327_ == 0)
{
lean_ctor_set(v___x_1326_, 0, v___x_1330_);
v___x_1332_ = v___x_1326_;
goto v_reusejp_1331_;
}
else
{
lean_object* v_reuseFailAlloc_1333_; 
v_reuseFailAlloc_1333_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1333_, 0, v___x_1330_);
v___x_1332_ = v_reuseFailAlloc_1333_;
goto v_reusejp_1331_;
}
v_reusejp_1331_:
{
return v___x_1332_;
}
}
}
}
else
{
lean_object* v_a_1347_; lean_object* v___x_1349_; uint8_t v_isShared_1350_; uint8_t v_isSharedCheck_1354_; 
lean_dec_ref(v_discharger_1318_);
v_a_1347_ = lean_ctor_get(v___x_1323_, 0);
v_isSharedCheck_1354_ = !lean_is_exclusive(v___x_1323_);
if (v_isSharedCheck_1354_ == 0)
{
v___x_1349_ = v___x_1323_;
v_isShared_1350_ = v_isSharedCheck_1354_;
goto v_resetjp_1348_;
}
else
{
lean_inc(v_a_1347_);
lean_dec(v___x_1323_);
v___x_1349_ = lean_box(0);
v_isShared_1350_ = v_isSharedCheck_1354_;
goto v_resetjp_1348_;
}
v_resetjp_1348_:
{
lean_object* v___x_1352_; 
if (v_isShared_1350_ == 0)
{
v___x_1352_ = v___x_1349_;
goto v_reusejp_1351_;
}
else
{
lean_object* v_reuseFailAlloc_1353_; 
v_reuseFailAlloc_1353_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1353_, 0, v_a_1347_);
v___x_1352_ = v_reuseFailAlloc_1353_;
goto v_reusejp_1351_;
}
v_reusejp_1351_:
{
return v___x_1352_;
}
}
}
}
else
{
lean_dec_ref(v_discharger_1318_);
lean_dec_ref(v_cfg_1297_);
goto v___jp_1311_;
}
}
}
else
{
lean_object* v_val_1355_; lean_object* v___x_1357_; uint8_t v_isShared_1358_; uint8_t v_isSharedCheck_1362_; 
lean_del_object(v___x_1309_);
lean_dec_ref(v_cfg_1297_);
v_val_1355_ = lean_ctor_get(v_fst_1316_, 0);
v_isSharedCheck_1362_ = !lean_is_exclusive(v_fst_1316_);
if (v_isSharedCheck_1362_ == 0)
{
v___x_1357_ = v_fst_1316_;
v_isShared_1358_ = v_isSharedCheck_1362_;
goto v_resetjp_1356_;
}
else
{
lean_inc(v_val_1355_);
lean_dec(v_fst_1316_);
v___x_1357_ = lean_box(0);
v_isShared_1358_ = v_isSharedCheck_1362_;
goto v_resetjp_1356_;
}
v_resetjp_1356_:
{
lean_object* v___x_1360_; 
if (v_isShared_1358_ == 0)
{
lean_ctor_set_tag(v___x_1357_, 0);
v___x_1360_ = v___x_1357_;
goto v_reusejp_1359_;
}
else
{
lean_object* v_reuseFailAlloc_1361_; 
v_reuseFailAlloc_1361_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1361_, 0, v_val_1355_);
v___x_1360_ = v_reuseFailAlloc_1361_;
goto v_reusejp_1359_;
}
v_reusejp_1359_:
{
return v___x_1360_;
}
}
}
v___jp_1311_:
{
lean_object* v___x_1312_; lean_object* v___x_1314_; 
v___x_1312_ = lean_box(1);
if (v_isShared_1310_ == 0)
{
lean_ctor_set(v___x_1309_, 0, v___x_1312_);
v___x_1314_ = v___x_1309_;
goto v_reusejp_1313_;
}
else
{
lean_object* v_reuseFailAlloc_1315_; 
v_reuseFailAlloc_1315_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1315_, 0, v___x_1312_);
v___x_1314_ = v_reuseFailAlloc_1315_;
goto v_reusejp_1313_;
}
v_reusejp_1313_:
{
return v___x_1314_;
}
}
}
}
else
{
lean_object* v_a_1364_; lean_object* v___x_1366_; uint8_t v_isShared_1367_; uint8_t v_isSharedCheck_1371_; 
lean_dec_ref(v_cfg_1297_);
v_a_1364_ = lean_ctor_get(v___x_1306_, 0);
v_isSharedCheck_1371_ = !lean_is_exclusive(v___x_1306_);
if (v_isSharedCheck_1371_ == 0)
{
v___x_1366_ = v___x_1306_;
v_isShared_1367_ = v_isSharedCheck_1371_;
goto v_resetjp_1365_;
}
else
{
lean_inc(v_a_1364_);
lean_dec(v___x_1306_);
v___x_1366_ = lean_box(0);
v_isShared_1367_ = v_isSharedCheck_1371_;
goto v_resetjp_1365_;
}
v_resetjp_1365_:
{
lean_object* v___x_1369_; 
if (v_isShared_1367_ == 0)
{
v___x_1369_ = v___x_1366_;
goto v_reusejp_1368_;
}
else
{
lean_object* v_reuseFailAlloc_1370_; 
v_reuseFailAlloc_1370_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1370_, 0, v_a_1364_);
v___x_1369_ = v_reuseFailAlloc_1370_;
goto v_reusejp_1368_;
}
v_reusejp_1368_:
{
return v___x_1369_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_classify___boxed(lean_object* v_guards_1372_, lean_object* v_cfg_1373_, lean_object* v_a_1374_, lean_object* v_a_1375_, lean_object* v_a_1376_, lean_object* v_a_1377_, lean_object* v_a_1378_){
_start:
{
lean_object* v_res_1379_; 
v_res_1379_ = lp_JunkValues_JunkValues_classify(v_guards_1372_, v_cfg_1373_, v_a_1374_, v_a_1375_, v_a_1376_, v_a_1377_);
lean_dec(v_a_1377_);
lean_dec_ref(v_a_1376_);
lean_dec(v_a_1375_);
lean_dec_ref(v_a_1374_);
lean_dec_ref(v_guards_1372_);
return v_res_1379_;
}
}
lean_object* runtime_initialize_Init(uint8_t builtin);
lean_object* runtime_initialize_Lean(uint8_t builtin);
lean_object* runtime_initialize_Lean_Elab_Tactic_Meta(uint8_t builtin);
lean_object* runtime_initialize_JunkValues_JunkValues_Report(uint8_t builtin);
static bool _G_runtime_initialized = false;
LEAN_EXPORT lean_object* runtime_initialize_JunkValues_JunkValues_Guard(uint8_t builtin) {
lean_object * res;
if (_G_runtime_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_runtime_initialized = true;
res = runtime_initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = runtime_initialize_Lean(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = runtime_initialize_Lean_Elab_Tactic_Meta(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = runtime_initialize_JunkValues_JunkValues_Report(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return lean_io_result_mk_ok(lean_box(0));
}
lean_object* runtime_initialize_Init(uint8_t builtin);
static bool _G_meta_initialized = false;
LEAN_EXPORT lean_object* meta_initialize_JunkValues_JunkValues_Guard(uint8_t builtin) {
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
lean_object* initialize_Lean_Elab_Tactic_Meta(uint8_t builtin);
lean_object* initialize_JunkValues_JunkValues_Report(uint8_t builtin);
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_JunkValues_JunkValues_Guard(uint8_t builtin) {
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
res = initialize_Lean_Elab_Tactic_Meta(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_JunkValues_JunkValues_Report(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = runtime_initialize_JunkValues_JunkValues_Guard(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = meta_initialize_JunkValues_JunkValues_Guard(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return initialize_JunkValues_JunkValues_Guard(builtin);
}
#ifdef __cplusplus
}
#endif
