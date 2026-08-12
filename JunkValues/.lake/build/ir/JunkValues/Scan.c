// Lean compiler output
// Module: JunkValues.Scan
// Imports: public import Init public meta import Init public import JunkValues.RuleSet public import JunkValues.Guard public import JunkValues.Report
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
lean_object* lean_nat_add(lean_object*, lean_object*);
uint8_t lean_nat_dec_lt(lean_object*, lean_object*);
lean_object* lean_array_fget_borrowed(lean_object*, lean_object*);
uint8_t l_Lean_Expr_hasMVar(lean_object*);
lean_object* lean_st_ref_get(lean_object*);
lean_object* l_Lean_instantiateMVarsCore(lean_object*, lean_object*);
lean_object* lean_st_ref_take(lean_object*);
lean_object* lean_st_ref_set(lean_object*, lean_object*);
uint8_t l_Lean_Expr_isMVar(lean_object*);
lean_object* lean_infer_type(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* lean_array_get(lean_object*, lean_object*, lean_object*);
lean_object* lp_JunkValues_JunkValues_isGuardBinder(uint8_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_Meta_trySynthInstance(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_Meta_isExprDefEq(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* lean_array_push(lean_object*, lean_object*);
lean_object* l___private_Lean_Meta_Basic_0__Lean_Meta_withNewMCtxDepthImp(lean_object*, uint8_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* lean_array_get_size(lean_object*);
lean_object* lean_array_fget(lean_object*, lean_object*);
lean_object* lean_array_fset(lean_object*, lean_object*, lean_object*);
uint64_t lp_JunkValues_JunkValues_instHashableSite_hash(uint8_t);
uint64_t lean_string_hash(lean_object*);
uint64_t lean_uint64_mix_hash(uint64_t, uint64_t);
uint64_t lean_uint64_shift_right(uint64_t, uint64_t);
uint64_t lean_uint64_xor(uint64_t, uint64_t);
size_t lean_uint64_to_usize(uint64_t);
size_t lean_usize_of_nat(lean_object*);
size_t lean_usize_sub(size_t, size_t);
size_t lean_usize_land(size_t, size_t);
lean_object* lean_array_uget_borrowed(lean_object*, size_t);
lean_object* lean_array_uset(lean_object*, size_t, lean_object*);
uint64_t lean_uint64_of_nat(lean_object*);
lean_object* lean_nat_mul(lean_object*, lean_object*);
lean_object* lean_mk_array(lean_object*, lean_object*);
lean_object* lean_string_utf8_byte_size(lean_object*);
uint8_t lean_name_eq(lean_object*, lean_object*);
uint8_t lp_JunkValues_JunkValues_instBEqSite_beq(uint8_t, uint8_t);
uint8_t lean_string_dec_eq(lean_object*, lean_object*);
lean_object* lean_nat_div(lean_object*, lean_object*);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
size_t lean_usize_add(size_t, size_t);
uint8_t lean_usize_dec_eq(size_t, size_t);
uint8_t l_Lean_Name_isPrefixOf(lean_object*, lean_object*);
uint8_t lean_string_memcmp(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_String_Slice_Pos_nextn(lean_object*, lean_object*, lean_object*);
lean_object* lean_nat_sub(lean_object*, lean_object*);
uint8_t lean_nat_dec_eq(lean_object*, lean_object*);
lean_object* lean_string_utf8_next_fast(lean_object*, lean_object*);
uint32_t lean_string_utf8_get_fast(lean_object*, lean_object*);
uint8_t lean_uint32_dec_le(uint32_t, uint32_t);
lean_object* l_Lean_Environment_find_x3f(lean_object*, lean_object*, uint8_t);
lean_object* lean_mk_empty_array_with_capacity(lean_object*);
lean_object* l_Lean_Expr_sort___override(lean_object*);
lean_object* l___private_Lean_Meta_Basic_0__Lean_Meta_withLetDeclImp(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, uint8_t, uint8_t, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* lp_JunkValues_JunkValues_headConst_x3f(lean_object*);
lean_object* lp_JunkValues_JunkValues_RuleSet_forHead(lean_object*, lean_object*);
lean_object* l_Lean_Expr_getAppNumArgs(lean_object*);
size_t lean_array_size(lean_object*);
uint8_t lean_usize_dec_lt(size_t, size_t);
lean_object* lp_JunkValues_JunkValues_openRule(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* lp_JunkValues_JunkValues_explicitArgIndices(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l___private_Lean_Expr_0__Lean_Expr_getAppArgsAux(lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_Meta_mkFreshExprMVar(lean_object*, uint8_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* lean_array_set(lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_Meta_mkEq(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_Expr_getAppFn(lean_object*);
lean_object* l_Lean_mkAppN(lean_object*, lean_object*);
uint8_t l_Lean_Expr_hasExprMVar(lean_object*);
lean_object* l_Lean_Meta_saveState___redArg(lean_object*, lean_object*);
lean_object* l_Lean_Meta_SavedState_restore___redArg(lean_object*, lean_object*, lean_object*);
lean_object* lp_JunkValues_JunkValues_classify(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_Meta_ppExpr(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
extern lean_object* l_Std_Format_defWidth;
lean_object* l_Std_Format_pretty(lean_object*, lean_object*, lean_object*, lean_object*);
uint8_t lp_JunkValues_JunkValues_Status_isFinding(lean_object*);
lean_object* l_Array_append___redArg(lean_object*, lean_object*);
lean_object* lean_expr_instantiate1(lean_object*, lean_object*);
lean_object* l___private_Lean_Meta_Basic_0__Lean_Meta_withLocalDeclImp(lean_object*, lean_object*, uint8_t, lean_object*, lean_object*, uint8_t, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_ConstantInfo_type(lean_object*);
lean_object* l_Lean_Meta_isProp(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* lean_array_pop(lean_object*);
lean_object* l_Lean_ConstantInfo_value_x3f(lean_object*, uint8_t);
lean_object* l_Lean_Expr_getUsedConstants(lean_object*);
lean_object* l_Lean_Exception_toMessageData(lean_object*);
lean_object* l_Lean_MessageData_toString(lean_object*);
uint8_t l_Lean_Exception_isInterrupt(lean_object*);
uint8_t l_Lean_Exception_isRuntime(lean_object*);
static const lean_array_object lp_JunkValues_JunkValues_instInhabitedDeclScan_default___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* lp_JunkValues_JunkValues_instInhabitedDeclScan_default___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_instInhabitedDeclScan_default___closed__0_value;
static const lean_ctor_object lp_JunkValues_JunkValues_instInhabitedDeclScan_default___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_instInhabitedDeclScan_default___closed__0_value),LEAN_SCALAR_PTR_LITERAL(0, 0, 0, 0, 0, 0, 0, 0)}};
static const lean_object* lp_JunkValues_JunkValues_instInhabitedDeclScan_default___closed__1 = (const lean_object*)&lp_JunkValues_JunkValues_instInhabitedDeclScan_default___closed__1_value;
LEAN_EXPORT const lean_object* lp_JunkValues_JunkValues_instInhabitedDeclScan_default = (const lean_object*)&lp_JunkValues_JunkValues_instInhabitedDeclScan_default___closed__1_value;
LEAN_EXPORT const lean_object* lp_JunkValues_JunkValues_instInhabitedDeclScan = (const lean_object*)&lp_JunkValues_JunkValues_instInhabitedDeclScan_default___closed__1_value;
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_generalizePattern_spec__0(lean_object*, lean_object*, size_t, size_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_generalizePattern_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static lean_once_cell_t lp_JunkValues_JunkValues_generalizePattern___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_generalizePattern___closed__0;
static const lean_array_object lp_JunkValues_JunkValues_generalizePattern___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* lp_JunkValues_JunkValues_generalizePattern___closed__1 = (const lean_object*)&lp_JunkValues_JunkValues_generalizePattern___closed__1_value;
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_generalizePattern(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_generalizePattern___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_instantiateMVars___at___00JunkValues_matchRule_x3f_spec__0___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_instantiateMVars___at___00JunkValues_matchRule_x3f_spec__0___redArg___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_instantiateMVars___at___00JunkValues_matchRule_x3f_spec__0(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_instantiateMVars___at___00JunkValues_matchRule_x3f_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Meta_withNewMCtxDepth___at___00JunkValues_matchRule_x3f_spec__3___redArg(lean_object*, uint8_t, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Meta_withNewMCtxDepth___at___00JunkValues_matchRule_x3f_spec__3___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Meta_withNewMCtxDepth___at___00JunkValues_matchRule_x3f_spec__3(lean_object*, lean_object*, uint8_t, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Meta_withNewMCtxDepth___at___00JunkValues_matchRule_x3f_spec__3___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_withoutModifyingState___at___00JunkValues_matchRule_x3f_spec__4___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_withoutModifyingState___at___00JunkValues_matchRule_x3f_spec__4___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_withoutModifyingState___at___00JunkValues_matchRule_x3f_spec__4(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_withoutModifyingState___at___00JunkValues_matchRule_x3f_spec__4___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00JunkValues_matchRule_x3f_spec__2(size_t, size_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00JunkValues_matchRule_x3f_spec__2___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_ctor_object lp_JunkValues___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00JunkValues_matchRule_x3f_spec__1___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_JunkValues___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00JunkValues_matchRule_x3f_spec__1___redArg___closed__0 = (const lean_object*)&lp_JunkValues___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00JunkValues_matchRule_x3f_spec__1___redArg___closed__0_value;
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00JunkValues_matchRule_x3f_spec__1___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00JunkValues_matchRule_x3f_spec__1___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_matchRule_x3f___lam__0(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_matchRule_x3f___lam__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_matchRule_x3f(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_matchRule_x3f___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00JunkValues_matchRule_x3f_spec__1(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00JunkValues_matchRule_x3f_spec__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00JunkValues_mkFinding_spec__0(size_t, size_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00JunkValues_mkFinding_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_mkFinding(lean_object*, uint8_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_mkFinding___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_matchAt_spec__0(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, uint8_t, lean_object*, size_t, size_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_matchAt_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_matchAt(lean_object*, lean_object*, lean_object*, uint8_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_matchAt___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Meta_withLocalDecl___at___00JunkValues_visit_spec__0___redArg___lam__0(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Meta_withLocalDecl___at___00JunkValues_visit_spec__0___redArg___lam__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Meta_withLocalDecl___at___00JunkValues_visit_spec__0___redArg(lean_object*, uint8_t, lean_object*, lean_object*, uint8_t, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Meta_withLocalDecl___at___00JunkValues_visit_spec__0___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Meta_withLocalDecl___at___00JunkValues_visit_spec__0(lean_object*, lean_object*, uint8_t, lean_object*, lean_object*, uint8_t, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Meta_withLocalDecl___at___00JunkValues_visit_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Meta_withLetDecl___at___00JunkValues_visit_spec__1___redArg(lean_object*, lean_object*, lean_object*, lean_object*, uint8_t, uint8_t, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Meta_withLetDecl___at___00JunkValues_visit_spec__1___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Meta_withLetDecl___at___00JunkValues_visit_spec__1(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, uint8_t, uint8_t, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Meta_withLetDecl___at___00JunkValues_visit_spec__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_visit___lam__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_visit___lam__1(lean_object*, lean_object*, lean_object*, lean_object*, uint8_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_visit___lam__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_visit(lean_object*, lean_object*, lean_object*, uint8_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_visit___lam__0(lean_object*, lean_object*, lean_object*, lean_object*, uint8_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_visit___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_dedupFindings_spec__0_spec__0___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_dedupFindings_spec__0_spec__0___redArg___boxed(lean_object*, lean_object*);
static lean_once_cell_t lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_dedupFindings_spec__0___redArg___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static uint64_t lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_dedupFindings_spec__0___redArg___closed__0;
LEAN_EXPORT uint8_t lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_dedupFindings_spec__0___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_dedupFindings_spec__0___redArg___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00__private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_dedupFindings_spec__1_spec__2_spec__3_spec__5___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_dedupFindings_spec__1_spec__2_spec__3___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_dedupFindings_spec__1_spec__2___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_dedupFindings_spec__1___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_dedupFindings_spec__2(lean_object*, size_t, size_t, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_dedupFindings_spec__2___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
static lean_once_cell_t lp_JunkValues_JunkValues_dedupFindings___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_dedupFindings___closed__0;
static lean_once_cell_t lp_JunkValues_JunkValues_dedupFindings___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_dedupFindings___closed__1;
static lean_once_cell_t lp_JunkValues_JunkValues_dedupFindings___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_dedupFindings___closed__2;
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_dedupFindings(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_dedupFindings___boxed(lean_object*);
LEAN_EXPORT uint8_t lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_dedupFindings_spec__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_dedupFindings_spec__0___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_dedupFindings_spec__1(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_dedupFindings_spec__0_spec__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_dedupFindings_spec__0_spec__0___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_dedupFindings_spec__1_spec__2(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_dedupFindings_spec__1_spec__2_spec__3(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00__private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_dedupFindings_spec__1_spec__2_spec__3_spec__5(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_String_Slice_Pos_skipWhile___at___00JunkValues_isCompilerGenerated_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_String_Slice_Pos_skipWhile___at___00JunkValues_isCompilerGenerated_spec__0___boxed(lean_object*, lean_object*);
static const lean_string_object lp_JunkValues_JunkValues_isCompilerGenerated___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "eq_def"};
static const lean_object* lp_JunkValues_JunkValues_isCompilerGenerated___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_isCompilerGenerated___closed__0_value;
static const lean_string_object lp_JunkValues_JunkValues_isCompilerGenerated___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 10, .m_capacity = 10, .m_length = 9, .m_data = "eq_unfold"};
static const lean_object* lp_JunkValues_JunkValues_isCompilerGenerated___closed__1 = (const lean_object*)&lp_JunkValues_JunkValues_isCompilerGenerated___closed__1_value;
static const lean_string_object lp_JunkValues_JunkValues_isCompilerGenerated___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "induct"};
static const lean_object* lp_JunkValues_JunkValues_isCompilerGenerated___closed__2 = (const lean_object*)&lp_JunkValues_JunkValues_isCompilerGenerated___closed__2_value;
static const lean_string_object lp_JunkValues_JunkValues_isCompilerGenerated___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 10, .m_capacity = 10, .m_length = 9, .m_data = "fun_cases"};
static const lean_object* lp_JunkValues_JunkValues_isCompilerGenerated___closed__3 = (const lean_object*)&lp_JunkValues_JunkValues_isCompilerGenerated___closed__3_value;
static const lean_string_object lp_JunkValues_JunkValues_isCompilerGenerated___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "eq_"};
static const lean_object* lp_JunkValues_JunkValues_isCompilerGenerated___closed__4 = (const lean_object*)&lp_JunkValues_JunkValues_isCompilerGenerated___closed__4_value;
static lean_once_cell_t lp_JunkValues_JunkValues_isCompilerGenerated___closed__5_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_isCompilerGenerated___closed__5;
static const lean_string_object lp_JunkValues_JunkValues_isCompilerGenerated___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "match_"};
static const lean_object* lp_JunkValues_JunkValues_isCompilerGenerated___closed__6 = (const lean_object*)&lp_JunkValues_JunkValues_isCompilerGenerated___closed__6_value;
static lean_once_cell_t lp_JunkValues_JunkValues_isCompilerGenerated___closed__7_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_isCompilerGenerated___closed__7;
static const lean_string_object lp_JunkValues_JunkValues_isCompilerGenerated___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 2, .m_capacity = 2, .m_length = 1, .m_data = "_"};
static const lean_object* lp_JunkValues_JunkValues_isCompilerGenerated___closed__8 = (const lean_object*)&lp_JunkValues_JunkValues_isCompilerGenerated___closed__8_value;
static lean_once_cell_t lp_JunkValues_JunkValues_isCompilerGenerated___closed__9_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_isCompilerGenerated___closed__9;
LEAN_EXPORT uint8_t lp_JunkValues_JunkValues_isCompilerGenerated(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_isCompilerGenerated___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00JunkValues_compilerAuxOf_spec__0(lean_object*, lean_object*, lean_object*, size_t, size_t, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00JunkValues_compilerAuxOf_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_array_object lp_JunkValues_JunkValues_compilerAuxOf___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* lp_JunkValues_JunkValues_compilerAuxOf___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_compilerAuxOf___closed__0_value;
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_compilerAuxOf(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_compilerAuxOf___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00__private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_scanDecl_spec__1_spec__2_spec__3_spec__5___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_scanDecl_spec__1_spec__2_spec__3___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_scanDecl_spec__1_spec__2___redArg(lean_object*);
LEAN_EXPORT uint8_t lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_scanDecl_spec__0_spec__0___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_scanDecl_spec__0_spec__0___redArg___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_scanDecl_spec__1___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_scanDecl_spec__0___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_scanDecl_spec__0___redArg___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_While_0__repeatM_erased___at___00JunkValues_scanDecl_spec__2___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_While_0__repeatM_erased___at___00JunkValues_scanDecl_spec__2___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static lean_once_cell_t lp_JunkValues_JunkValues_scanDecl___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_scanDecl___closed__0;
static lean_once_cell_t lp_JunkValues_JunkValues_scanDecl___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_scanDecl___closed__1;
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_scanDecl(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_scanDecl___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_scanDecl_spec__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_scanDecl_spec__0___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_scanDecl_spec__1(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_While_0__repeatM_erased___at___00JunkValues_scanDecl_spec__2(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_While_0__repeatM_erased___at___00JunkValues_scanDecl_spec__2___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_scanDecl_spec__0_spec__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_scanDecl_spec__0_spec__0___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_scanDecl_spec__1_spec__2(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_scanDecl_spec__1_spec__2_spec__3(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00__private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_scanDecl_spec__1_spec__2_spec__3_spec__5(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_scanDecls_spec__0(lean_object*, lean_object*, lean_object*, size_t, size_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_scanDecls_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_array_object lp_JunkValues_JunkValues_scanDecls___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* lp_JunkValues_JunkValues_scanDecls___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_scanDecls___closed__0_value;
static const lean_ctor_object lp_JunkValues_JunkValues_scanDecls___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_scanDecls___closed__0_value),((lean_object*)&lp_JunkValues_JunkValues_scanDecls___closed__0_value)}};
static const lean_object* lp_JunkValues_JunkValues_scanDecls___closed__1 = (const lean_object*)&lp_JunkValues_JunkValues_scanDecls___closed__1_value;
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_scanDecls(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_scanDecls___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_generalizePattern_spec__0(lean_object* v_a_9_, lean_object* v_as_10_, size_t v_sz_11_, size_t v_i_12_, lean_object* v_b_13_, lean_object* v___y_14_, lean_object* v___y_15_, lean_object* v___y_16_, lean_object* v___y_17_){
_start:
{
lean_object* v_a_20_; uint8_t v___x_24_; 
v___x_24_ = lean_usize_dec_lt(v_i_12_, v_sz_11_);
if (v___x_24_ == 0)
{
lean_object* v___x_25_; 
v___x_25_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_25_, 0, v_b_13_);
return v___x_25_;
}
else
{
lean_object* v_fst_26_; lean_object* v_snd_27_; lean_object* v___x_29_; uint8_t v_isShared_30_; uint8_t v_isSharedCheck_84_; 
v_fst_26_ = lean_ctor_get(v_b_13_, 0);
v_snd_27_ = lean_ctor_get(v_b_13_, 1);
v_isSharedCheck_84_ = !lean_is_exclusive(v_b_13_);
if (v_isSharedCheck_84_ == 0)
{
v___x_29_ = v_b_13_;
v_isShared_30_ = v_isSharedCheck_84_;
goto v_resetjp_28_;
}
else
{
lean_inc(v_snd_27_);
lean_inc(v_fst_26_);
lean_dec(v_b_13_);
v___x_29_ = lean_box(0);
v_isShared_30_ = v_isSharedCheck_84_;
goto v_resetjp_28_;
}
v_resetjp_28_:
{
lean_object* v_a_31_; lean_object* v___x_32_; lean_object* v___x_33_; lean_object* v___x_34_; uint8_t v___x_35_; 
v_a_31_ = lean_array_uget_borrowed(v_as_10_, v_i_12_);
v___x_32_ = lean_unsigned_to_nat(1u);
v___x_33_ = lean_nat_sub(v_a_31_, v___x_32_);
v___x_34_ = lean_array_get_size(v_a_9_);
v___x_35_ = lean_nat_dec_lt(v___x_33_, v___x_34_);
if (v___x_35_ == 0)
{
lean_object* v___x_37_; 
lean_dec(v___x_33_);
if (v_isShared_30_ == 0)
{
v___x_37_ = v___x_29_;
goto v_reusejp_36_;
}
else
{
lean_object* v_reuseFailAlloc_38_; 
v_reuseFailAlloc_38_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_38_, 0, v_fst_26_);
lean_ctor_set(v_reuseFailAlloc_38_, 1, v_snd_27_);
v___x_37_ = v_reuseFailAlloc_38_;
goto v_reusejp_36_;
}
v_reusejp_36_:
{
v_a_20_ = v___x_37_;
goto v___jp_19_;
}
}
else
{
lean_object* v___x_39_; lean_object* v___x_40_; uint8_t v___x_41_; 
v___x_39_ = lean_array_fget_borrowed(v_a_9_, v___x_33_);
lean_dec(v___x_33_);
v___x_40_ = lean_array_get_size(v_fst_26_);
v___x_41_ = lean_nat_dec_lt(v___x_39_, v___x_40_);
if (v___x_41_ == 0)
{
lean_object* v___x_43_; 
if (v_isShared_30_ == 0)
{
v___x_43_ = v___x_29_;
goto v_reusejp_42_;
}
else
{
lean_object* v_reuseFailAlloc_44_; 
v_reuseFailAlloc_44_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_44_, 0, v_fst_26_);
lean_ctor_set(v_reuseFailAlloc_44_, 1, v_snd_27_);
v___x_43_ = v_reuseFailAlloc_44_;
goto v_reusejp_42_;
}
v_reusejp_42_:
{
v_a_20_ = v___x_43_;
goto v___jp_19_;
}
}
else
{
lean_object* v___x_45_; lean_object* v___x_46_; 
v___x_45_ = lean_array_fget(v_fst_26_, v___x_39_);
lean_inc(v___y_17_);
lean_inc_ref(v___y_16_);
lean_inc(v___y_15_);
lean_inc_ref(v___y_14_);
lean_inc(v___x_45_);
v___x_46_ = lean_infer_type(v___x_45_, v___y_14_, v___y_15_, v___y_16_, v___y_17_);
if (lean_obj_tag(v___x_46_) == 0)
{
lean_object* v_a_47_; lean_object* v___x_48_; uint8_t v___x_49_; lean_object* v___x_50_; lean_object* v___x_51_; 
v_a_47_ = lean_ctor_get(v___x_46_, 0);
lean_inc(v_a_47_);
lean_dec_ref_known(v___x_46_, 1);
v___x_48_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_48_, 0, v_a_47_);
v___x_49_ = 0;
v___x_50_ = lean_box(0);
v___x_51_ = l_Lean_Meta_mkFreshExprMVar(v___x_48_, v___x_49_, v___x_50_, v___y_14_, v___y_15_, v___y_16_, v___y_17_);
if (lean_obj_tag(v___x_51_) == 0)
{
lean_object* v_a_52_; lean_object* v___x_53_; lean_object* v___x_54_; 
v_a_52_ = lean_ctor_get(v___x_51_, 0);
lean_inc_n(v_a_52_, 2);
lean_dec_ref_known(v___x_51_, 1);
v___x_53_ = lean_array_set(v_fst_26_, v___x_39_, v_a_52_);
v___x_54_ = l_Lean_Meta_mkEq(v_a_52_, v___x_45_, v___y_14_, v___y_15_, v___y_16_, v___y_17_);
if (lean_obj_tag(v___x_54_) == 0)
{
lean_object* v_a_55_; lean_object* v___x_56_; lean_object* v___x_58_; 
v_a_55_ = lean_ctor_get(v___x_54_, 0);
lean_inc(v_a_55_);
lean_dec_ref_known(v___x_54_, 1);
v___x_56_ = lean_array_push(v_snd_27_, v_a_55_);
if (v_isShared_30_ == 0)
{
lean_ctor_set(v___x_29_, 1, v___x_56_);
lean_ctor_set(v___x_29_, 0, v___x_53_);
v___x_58_ = v___x_29_;
goto v_reusejp_57_;
}
else
{
lean_object* v_reuseFailAlloc_59_; 
v_reuseFailAlloc_59_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_59_, 0, v___x_53_);
lean_ctor_set(v_reuseFailAlloc_59_, 1, v___x_56_);
v___x_58_ = v_reuseFailAlloc_59_;
goto v_reusejp_57_;
}
v_reusejp_57_:
{
v_a_20_ = v___x_58_;
goto v___jp_19_;
}
}
else
{
lean_object* v_a_60_; lean_object* v___x_62_; uint8_t v_isShared_63_; uint8_t v_isSharedCheck_67_; 
lean_dec_ref(v___x_53_);
lean_del_object(v___x_29_);
lean_dec(v_snd_27_);
v_a_60_ = lean_ctor_get(v___x_54_, 0);
v_isSharedCheck_67_ = !lean_is_exclusive(v___x_54_);
if (v_isSharedCheck_67_ == 0)
{
v___x_62_ = v___x_54_;
v_isShared_63_ = v_isSharedCheck_67_;
goto v_resetjp_61_;
}
else
{
lean_inc(v_a_60_);
lean_dec(v___x_54_);
v___x_62_ = lean_box(0);
v_isShared_63_ = v_isSharedCheck_67_;
goto v_resetjp_61_;
}
v_resetjp_61_:
{
lean_object* v___x_65_; 
if (v_isShared_63_ == 0)
{
v___x_65_ = v___x_62_;
goto v_reusejp_64_;
}
else
{
lean_object* v_reuseFailAlloc_66_; 
v_reuseFailAlloc_66_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_66_, 0, v_a_60_);
v___x_65_ = v_reuseFailAlloc_66_;
goto v_reusejp_64_;
}
v_reusejp_64_:
{
return v___x_65_;
}
}
}
}
else
{
lean_object* v_a_68_; lean_object* v___x_70_; uint8_t v_isShared_71_; uint8_t v_isSharedCheck_75_; 
lean_dec(v___x_45_);
lean_del_object(v___x_29_);
lean_dec(v_snd_27_);
lean_dec(v_fst_26_);
v_a_68_ = lean_ctor_get(v___x_51_, 0);
v_isSharedCheck_75_ = !lean_is_exclusive(v___x_51_);
if (v_isSharedCheck_75_ == 0)
{
v___x_70_ = v___x_51_;
v_isShared_71_ = v_isSharedCheck_75_;
goto v_resetjp_69_;
}
else
{
lean_inc(v_a_68_);
lean_dec(v___x_51_);
v___x_70_ = lean_box(0);
v_isShared_71_ = v_isSharedCheck_75_;
goto v_resetjp_69_;
}
v_resetjp_69_:
{
lean_object* v___x_73_; 
if (v_isShared_71_ == 0)
{
v___x_73_ = v___x_70_;
goto v_reusejp_72_;
}
else
{
lean_object* v_reuseFailAlloc_74_; 
v_reuseFailAlloc_74_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_74_, 0, v_a_68_);
v___x_73_ = v_reuseFailAlloc_74_;
goto v_reusejp_72_;
}
v_reusejp_72_:
{
return v___x_73_;
}
}
}
}
else
{
lean_object* v_a_76_; lean_object* v___x_78_; uint8_t v_isShared_79_; uint8_t v_isSharedCheck_83_; 
lean_dec(v___x_45_);
lean_del_object(v___x_29_);
lean_dec(v_snd_27_);
lean_dec(v_fst_26_);
v_a_76_ = lean_ctor_get(v___x_46_, 0);
v_isSharedCheck_83_ = !lean_is_exclusive(v___x_46_);
if (v_isSharedCheck_83_ == 0)
{
v___x_78_ = v___x_46_;
v_isShared_79_ = v_isSharedCheck_83_;
goto v_resetjp_77_;
}
else
{
lean_inc(v_a_76_);
lean_dec(v___x_46_);
v___x_78_ = lean_box(0);
v_isShared_79_ = v_isSharedCheck_83_;
goto v_resetjp_77_;
}
v_resetjp_77_:
{
lean_object* v___x_81_; 
if (v_isShared_79_ == 0)
{
v___x_81_ = v___x_78_;
goto v_reusejp_80_;
}
else
{
lean_object* v_reuseFailAlloc_82_; 
v_reuseFailAlloc_82_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_82_, 0, v_a_76_);
v___x_81_ = v_reuseFailAlloc_82_;
goto v_reusejp_80_;
}
v_reusejp_80_:
{
return v___x_81_;
}
}
}
}
}
}
}
v___jp_19_:
{
size_t v___x_21_; size_t v___x_22_; 
v___x_21_ = ((size_t)1ULL);
v___x_22_ = lean_usize_add(v_i_12_, v___x_21_);
v_i_12_ = v___x_22_;
v_b_13_ = v_a_20_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_generalizePattern_spec__0___boxed(lean_object* v_a_85_, lean_object* v_as_86_, lean_object* v_sz_87_, lean_object* v_i_88_, lean_object* v_b_89_, lean_object* v___y_90_, lean_object* v___y_91_, lean_object* v___y_92_, lean_object* v___y_93_, lean_object* v___y_94_){
_start:
{
size_t v_sz_boxed_95_; size_t v_i_boxed_96_; lean_object* v_res_97_; 
v_sz_boxed_95_ = lean_unbox_usize(v_sz_87_);
lean_dec(v_sz_87_);
v_i_boxed_96_ = lean_unbox_usize(v_i_88_);
lean_dec(v_i_88_);
v_res_97_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_generalizePattern_spec__0(v_a_85_, v_as_86_, v_sz_boxed_95_, v_i_boxed_96_, v_b_89_, v___y_90_, v___y_91_, v___y_92_, v___y_93_);
lean_dec(v___y_93_);
lean_dec_ref(v___y_92_);
lean_dec(v___y_91_);
lean_dec_ref(v___y_90_);
lean_dec_ref(v_as_86_);
lean_dec_ref(v_a_85_);
return v_res_97_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_generalizePattern___closed__0(void){
_start:
{
lean_object* v___x_98_; lean_object* v_dummy_99_; 
v___x_98_ = lean_box(0);
v_dummy_99_ = l_Lean_Expr_sort___override(v___x_98_);
return v_dummy_99_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_generalizePattern(lean_object* v_positions_102_, lean_object* v_lhs_103_, lean_object* v_a_104_, lean_object* v_a_105_, lean_object* v_a_106_, lean_object* v_a_107_){
_start:
{
lean_object* v___x_109_; lean_object* v___x_110_; uint8_t v___x_111_; 
v___x_109_ = lean_array_get_size(v_positions_102_);
v___x_110_ = lean_unsigned_to_nat(0u);
v___x_111_ = lean_nat_dec_eq(v___x_109_, v___x_110_);
if (v___x_111_ == 0)
{
lean_object* v___x_112_; 
lean_inc_ref(v_lhs_103_);
v___x_112_ = lp_JunkValues_JunkValues_explicitArgIndices(v_lhs_103_, v_a_104_, v_a_105_, v_a_106_, v_a_107_);
if (lean_obj_tag(v___x_112_) == 0)
{
lean_object* v_a_113_; lean_object* v_dummy_114_; lean_object* v_nargs_115_; lean_object* v___x_116_; lean_object* v___x_117_; lean_object* v___x_118_; lean_object* v___x_119_; lean_object* v___x_120_; lean_object* v___x_121_; size_t v_sz_122_; size_t v___x_123_; lean_object* v___x_124_; 
v_a_113_ = lean_ctor_get(v___x_112_, 0);
lean_inc(v_a_113_);
lean_dec_ref_known(v___x_112_, 1);
v_dummy_114_ = lean_obj_once(&lp_JunkValues_JunkValues_generalizePattern___closed__0, &lp_JunkValues_JunkValues_generalizePattern___closed__0_once, _init_lp_JunkValues_JunkValues_generalizePattern___closed__0);
v_nargs_115_ = l_Lean_Expr_getAppNumArgs(v_lhs_103_);
lean_inc(v_nargs_115_);
v___x_116_ = lean_mk_array(v_nargs_115_, v_dummy_114_);
v___x_117_ = lean_unsigned_to_nat(1u);
v___x_118_ = lean_nat_sub(v_nargs_115_, v___x_117_);
lean_dec(v_nargs_115_);
lean_inc_ref(v_lhs_103_);
v___x_119_ = l___private_Lean_Expr_0__Lean_Expr_getAppArgsAux(v_lhs_103_, v___x_116_, v___x_118_);
v___x_120_ = ((lean_object*)(lp_JunkValues_JunkValues_generalizePattern___closed__1));
v___x_121_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_121_, 0, v___x_119_);
lean_ctor_set(v___x_121_, 1, v___x_120_);
v_sz_122_ = lean_array_size(v_positions_102_);
v___x_123_ = ((size_t)0ULL);
v___x_124_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_generalizePattern_spec__0(v_a_113_, v_positions_102_, v_sz_122_, v___x_123_, v___x_121_, v_a_104_, v_a_105_, v_a_106_, v_a_107_);
lean_dec(v_a_113_);
if (lean_obj_tag(v___x_124_) == 0)
{
lean_object* v_a_125_; lean_object* v___x_127_; uint8_t v_isShared_128_; uint8_t v_isSharedCheck_143_; 
v_a_125_ = lean_ctor_get(v___x_124_, 0);
v_isSharedCheck_143_ = !lean_is_exclusive(v___x_124_);
if (v_isSharedCheck_143_ == 0)
{
v___x_127_ = v___x_124_;
v_isShared_128_ = v_isSharedCheck_143_;
goto v_resetjp_126_;
}
else
{
lean_inc(v_a_125_);
lean_dec(v___x_124_);
v___x_127_ = lean_box(0);
v_isShared_128_ = v_isSharedCheck_143_;
goto v_resetjp_126_;
}
v_resetjp_126_:
{
lean_object* v_fst_129_; lean_object* v_snd_130_; lean_object* v___x_132_; uint8_t v_isShared_133_; uint8_t v_isSharedCheck_142_; 
v_fst_129_ = lean_ctor_get(v_a_125_, 0);
v_snd_130_ = lean_ctor_get(v_a_125_, 1);
v_isSharedCheck_142_ = !lean_is_exclusive(v_a_125_);
if (v_isSharedCheck_142_ == 0)
{
v___x_132_ = v_a_125_;
v_isShared_133_ = v_isSharedCheck_142_;
goto v_resetjp_131_;
}
else
{
lean_inc(v_snd_130_);
lean_inc(v_fst_129_);
lean_dec(v_a_125_);
v___x_132_ = lean_box(0);
v_isShared_133_ = v_isSharedCheck_142_;
goto v_resetjp_131_;
}
v_resetjp_131_:
{
lean_object* v___x_134_; lean_object* v___x_135_; lean_object* v___x_137_; 
v___x_134_ = l_Lean_Expr_getAppFn(v_lhs_103_);
lean_dec_ref(v_lhs_103_);
v___x_135_ = l_Lean_mkAppN(v___x_134_, v_fst_129_);
lean_dec(v_fst_129_);
if (v_isShared_133_ == 0)
{
lean_ctor_set(v___x_132_, 0, v___x_135_);
v___x_137_ = v___x_132_;
goto v_reusejp_136_;
}
else
{
lean_object* v_reuseFailAlloc_141_; 
v_reuseFailAlloc_141_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_141_, 0, v___x_135_);
lean_ctor_set(v_reuseFailAlloc_141_, 1, v_snd_130_);
v___x_137_ = v_reuseFailAlloc_141_;
goto v_reusejp_136_;
}
v_reusejp_136_:
{
lean_object* v___x_139_; 
if (v_isShared_128_ == 0)
{
lean_ctor_set(v___x_127_, 0, v___x_137_);
v___x_139_ = v___x_127_;
goto v_reusejp_138_;
}
else
{
lean_object* v_reuseFailAlloc_140_; 
v_reuseFailAlloc_140_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_140_, 0, v___x_137_);
v___x_139_ = v_reuseFailAlloc_140_;
goto v_reusejp_138_;
}
v_reusejp_138_:
{
return v___x_139_;
}
}
}
}
}
else
{
lean_object* v_a_144_; lean_object* v___x_146_; uint8_t v_isShared_147_; uint8_t v_isSharedCheck_151_; 
lean_dec_ref(v_lhs_103_);
v_a_144_ = lean_ctor_get(v___x_124_, 0);
v_isSharedCheck_151_ = !lean_is_exclusive(v___x_124_);
if (v_isSharedCheck_151_ == 0)
{
v___x_146_ = v___x_124_;
v_isShared_147_ = v_isSharedCheck_151_;
goto v_resetjp_145_;
}
else
{
lean_inc(v_a_144_);
lean_dec(v___x_124_);
v___x_146_ = lean_box(0);
v_isShared_147_ = v_isSharedCheck_151_;
goto v_resetjp_145_;
}
v_resetjp_145_:
{
lean_object* v___x_149_; 
if (v_isShared_147_ == 0)
{
v___x_149_ = v___x_146_;
goto v_reusejp_148_;
}
else
{
lean_object* v_reuseFailAlloc_150_; 
v_reuseFailAlloc_150_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_150_, 0, v_a_144_);
v___x_149_ = v_reuseFailAlloc_150_;
goto v_reusejp_148_;
}
v_reusejp_148_:
{
return v___x_149_;
}
}
}
}
else
{
lean_object* v_a_152_; lean_object* v___x_154_; uint8_t v_isShared_155_; uint8_t v_isSharedCheck_159_; 
lean_dec_ref(v_lhs_103_);
v_a_152_ = lean_ctor_get(v___x_112_, 0);
v_isSharedCheck_159_ = !lean_is_exclusive(v___x_112_);
if (v_isSharedCheck_159_ == 0)
{
v___x_154_ = v___x_112_;
v_isShared_155_ = v_isSharedCheck_159_;
goto v_resetjp_153_;
}
else
{
lean_inc(v_a_152_);
lean_dec(v___x_112_);
v___x_154_ = lean_box(0);
v_isShared_155_ = v_isSharedCheck_159_;
goto v_resetjp_153_;
}
v_resetjp_153_:
{
lean_object* v___x_157_; 
if (v_isShared_155_ == 0)
{
v___x_157_ = v___x_154_;
goto v_reusejp_156_;
}
else
{
lean_object* v_reuseFailAlloc_158_; 
v_reuseFailAlloc_158_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_158_, 0, v_a_152_);
v___x_157_ = v_reuseFailAlloc_158_;
goto v_reusejp_156_;
}
v_reusejp_156_:
{
return v___x_157_;
}
}
}
}
else
{
lean_object* v___x_160_; lean_object* v___x_161_; lean_object* v___x_162_; 
v___x_160_ = ((lean_object*)(lp_JunkValues_JunkValues_generalizePattern___closed__1));
v___x_161_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_161_, 0, v_lhs_103_);
lean_ctor_set(v___x_161_, 1, v___x_160_);
v___x_162_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_162_, 0, v___x_161_);
return v___x_162_;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_generalizePattern___boxed(lean_object* v_positions_163_, lean_object* v_lhs_164_, lean_object* v_a_165_, lean_object* v_a_166_, lean_object* v_a_167_, lean_object* v_a_168_, lean_object* v_a_169_){
_start:
{
lean_object* v_res_170_; 
v_res_170_ = lp_JunkValues_JunkValues_generalizePattern(v_positions_163_, v_lhs_164_, v_a_165_, v_a_166_, v_a_167_, v_a_168_);
lean_dec(v_a_168_);
lean_dec_ref(v_a_167_);
lean_dec(v_a_166_);
lean_dec_ref(v_a_165_);
lean_dec_ref(v_positions_163_);
return v_res_170_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_instantiateMVars___at___00JunkValues_matchRule_x3f_spec__0___redArg(lean_object* v_e_171_, lean_object* v___y_172_){
_start:
{
uint8_t v___x_174_; 
v___x_174_ = l_Lean_Expr_hasMVar(v_e_171_);
if (v___x_174_ == 0)
{
lean_object* v___x_175_; 
v___x_175_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_175_, 0, v_e_171_);
return v___x_175_;
}
else
{
lean_object* v___x_176_; lean_object* v_mctx_177_; lean_object* v___x_178_; lean_object* v_fst_179_; lean_object* v_snd_180_; lean_object* v___x_181_; lean_object* v_cache_182_; lean_object* v_zetaDeltaFVarIds_183_; lean_object* v_postponed_184_; lean_object* v_diag_185_; lean_object* v___x_187_; uint8_t v_isShared_188_; uint8_t v_isSharedCheck_194_; 
v___x_176_ = lean_st_ref_get(v___y_172_);
v_mctx_177_ = lean_ctor_get(v___x_176_, 0);
lean_inc_ref(v_mctx_177_);
lean_dec(v___x_176_);
v___x_178_ = l_Lean_instantiateMVarsCore(v_mctx_177_, v_e_171_);
v_fst_179_ = lean_ctor_get(v___x_178_, 0);
lean_inc(v_fst_179_);
v_snd_180_ = lean_ctor_get(v___x_178_, 1);
lean_inc(v_snd_180_);
lean_dec_ref(v___x_178_);
v___x_181_ = lean_st_ref_take(v___y_172_);
v_cache_182_ = lean_ctor_get(v___x_181_, 1);
v_zetaDeltaFVarIds_183_ = lean_ctor_get(v___x_181_, 2);
v_postponed_184_ = lean_ctor_get(v___x_181_, 3);
v_diag_185_ = lean_ctor_get(v___x_181_, 4);
v_isSharedCheck_194_ = !lean_is_exclusive(v___x_181_);
if (v_isSharedCheck_194_ == 0)
{
lean_object* v_unused_195_; 
v_unused_195_ = lean_ctor_get(v___x_181_, 0);
lean_dec(v_unused_195_);
v___x_187_ = v___x_181_;
v_isShared_188_ = v_isSharedCheck_194_;
goto v_resetjp_186_;
}
else
{
lean_inc(v_diag_185_);
lean_inc(v_postponed_184_);
lean_inc(v_zetaDeltaFVarIds_183_);
lean_inc(v_cache_182_);
lean_dec(v___x_181_);
v___x_187_ = lean_box(0);
v_isShared_188_ = v_isSharedCheck_194_;
goto v_resetjp_186_;
}
v_resetjp_186_:
{
lean_object* v___x_190_; 
if (v_isShared_188_ == 0)
{
lean_ctor_set(v___x_187_, 0, v_snd_180_);
v___x_190_ = v___x_187_;
goto v_reusejp_189_;
}
else
{
lean_object* v_reuseFailAlloc_193_; 
v_reuseFailAlloc_193_ = lean_alloc_ctor(0, 5, 0);
lean_ctor_set(v_reuseFailAlloc_193_, 0, v_snd_180_);
lean_ctor_set(v_reuseFailAlloc_193_, 1, v_cache_182_);
lean_ctor_set(v_reuseFailAlloc_193_, 2, v_zetaDeltaFVarIds_183_);
lean_ctor_set(v_reuseFailAlloc_193_, 3, v_postponed_184_);
lean_ctor_set(v_reuseFailAlloc_193_, 4, v_diag_185_);
v___x_190_ = v_reuseFailAlloc_193_;
goto v_reusejp_189_;
}
v_reusejp_189_:
{
lean_object* v___x_191_; lean_object* v___x_192_; 
v___x_191_ = lean_st_ref_set(v___y_172_, v___x_190_);
v___x_192_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_192_, 0, v_fst_179_);
return v___x_192_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_instantiateMVars___at___00JunkValues_matchRule_x3f_spec__0___redArg___boxed(lean_object* v_e_196_, lean_object* v___y_197_, lean_object* v___y_198_){
_start:
{
lean_object* v_res_199_; 
v_res_199_ = lp_JunkValues_Lean_instantiateMVars___at___00JunkValues_matchRule_x3f_spec__0___redArg(v_e_196_, v___y_197_);
lean_dec(v___y_197_);
return v_res_199_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_instantiateMVars___at___00JunkValues_matchRule_x3f_spec__0(lean_object* v_e_200_, lean_object* v___y_201_, lean_object* v___y_202_, lean_object* v___y_203_, lean_object* v___y_204_){
_start:
{
lean_object* v___x_206_; 
v___x_206_ = lp_JunkValues_Lean_instantiateMVars___at___00JunkValues_matchRule_x3f_spec__0___redArg(v_e_200_, v___y_202_);
return v___x_206_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_instantiateMVars___at___00JunkValues_matchRule_x3f_spec__0___boxed(lean_object* v_e_207_, lean_object* v___y_208_, lean_object* v___y_209_, lean_object* v___y_210_, lean_object* v___y_211_, lean_object* v___y_212_){
_start:
{
lean_object* v_res_213_; 
v_res_213_ = lp_JunkValues_Lean_instantiateMVars___at___00JunkValues_matchRule_x3f_spec__0(v_e_207_, v___y_208_, v___y_209_, v___y_210_, v___y_211_);
lean_dec(v___y_211_);
lean_dec_ref(v___y_210_);
lean_dec(v___y_209_);
lean_dec_ref(v___y_208_);
return v_res_213_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Meta_withNewMCtxDepth___at___00JunkValues_matchRule_x3f_spec__3___redArg(lean_object* v_k_214_, uint8_t v_allowLevelAssignments_215_, lean_object* v___y_216_, lean_object* v___y_217_, lean_object* v___y_218_, lean_object* v___y_219_){
_start:
{
lean_object* v___x_221_; 
v___x_221_ = l___private_Lean_Meta_Basic_0__Lean_Meta_withNewMCtxDepthImp(lean_box(0), v_allowLevelAssignments_215_, v_k_214_, v___y_216_, v___y_217_, v___y_218_, v___y_219_);
if (lean_obj_tag(v___x_221_) == 0)
{
lean_object* v_a_222_; lean_object* v___x_224_; uint8_t v_isShared_225_; uint8_t v_isSharedCheck_229_; 
v_a_222_ = lean_ctor_get(v___x_221_, 0);
v_isSharedCheck_229_ = !lean_is_exclusive(v___x_221_);
if (v_isSharedCheck_229_ == 0)
{
v___x_224_ = v___x_221_;
v_isShared_225_ = v_isSharedCheck_229_;
goto v_resetjp_223_;
}
else
{
lean_inc(v_a_222_);
lean_dec(v___x_221_);
v___x_224_ = lean_box(0);
v_isShared_225_ = v_isSharedCheck_229_;
goto v_resetjp_223_;
}
v_resetjp_223_:
{
lean_object* v___x_227_; 
if (v_isShared_225_ == 0)
{
v___x_227_ = v___x_224_;
goto v_reusejp_226_;
}
else
{
lean_object* v_reuseFailAlloc_228_; 
v_reuseFailAlloc_228_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_228_, 0, v_a_222_);
v___x_227_ = v_reuseFailAlloc_228_;
goto v_reusejp_226_;
}
v_reusejp_226_:
{
return v___x_227_;
}
}
}
else
{
lean_object* v_a_230_; lean_object* v___x_232_; uint8_t v_isShared_233_; uint8_t v_isSharedCheck_237_; 
v_a_230_ = lean_ctor_get(v___x_221_, 0);
v_isSharedCheck_237_ = !lean_is_exclusive(v___x_221_);
if (v_isSharedCheck_237_ == 0)
{
v___x_232_ = v___x_221_;
v_isShared_233_ = v_isSharedCheck_237_;
goto v_resetjp_231_;
}
else
{
lean_inc(v_a_230_);
lean_dec(v___x_221_);
v___x_232_ = lean_box(0);
v_isShared_233_ = v_isSharedCheck_237_;
goto v_resetjp_231_;
}
v_resetjp_231_:
{
lean_object* v___x_235_; 
if (v_isShared_233_ == 0)
{
v___x_235_ = v___x_232_;
goto v_reusejp_234_;
}
else
{
lean_object* v_reuseFailAlloc_236_; 
v_reuseFailAlloc_236_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_236_, 0, v_a_230_);
v___x_235_ = v_reuseFailAlloc_236_;
goto v_reusejp_234_;
}
v_reusejp_234_:
{
return v___x_235_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Meta_withNewMCtxDepth___at___00JunkValues_matchRule_x3f_spec__3___redArg___boxed(lean_object* v_k_238_, lean_object* v_allowLevelAssignments_239_, lean_object* v___y_240_, lean_object* v___y_241_, lean_object* v___y_242_, lean_object* v___y_243_, lean_object* v___y_244_){
_start:
{
uint8_t v_allowLevelAssignments_boxed_245_; lean_object* v_res_246_; 
v_allowLevelAssignments_boxed_245_ = lean_unbox(v_allowLevelAssignments_239_);
v_res_246_ = lp_JunkValues_Lean_Meta_withNewMCtxDepth___at___00JunkValues_matchRule_x3f_spec__3___redArg(v_k_238_, v_allowLevelAssignments_boxed_245_, v___y_240_, v___y_241_, v___y_242_, v___y_243_);
lean_dec(v___y_243_);
lean_dec_ref(v___y_242_);
lean_dec(v___y_241_);
lean_dec_ref(v___y_240_);
return v_res_246_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Meta_withNewMCtxDepth___at___00JunkValues_matchRule_x3f_spec__3(lean_object* v_00_u03b1_247_, lean_object* v_k_248_, uint8_t v_allowLevelAssignments_249_, lean_object* v___y_250_, lean_object* v___y_251_, lean_object* v___y_252_, lean_object* v___y_253_){
_start:
{
lean_object* v___x_255_; 
v___x_255_ = lp_JunkValues_Lean_Meta_withNewMCtxDepth___at___00JunkValues_matchRule_x3f_spec__3___redArg(v_k_248_, v_allowLevelAssignments_249_, v___y_250_, v___y_251_, v___y_252_, v___y_253_);
return v___x_255_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Meta_withNewMCtxDepth___at___00JunkValues_matchRule_x3f_spec__3___boxed(lean_object* v_00_u03b1_256_, lean_object* v_k_257_, lean_object* v_allowLevelAssignments_258_, lean_object* v___y_259_, lean_object* v___y_260_, lean_object* v___y_261_, lean_object* v___y_262_, lean_object* v___y_263_){
_start:
{
uint8_t v_allowLevelAssignments_boxed_264_; lean_object* v_res_265_; 
v_allowLevelAssignments_boxed_264_ = lean_unbox(v_allowLevelAssignments_258_);
v_res_265_ = lp_JunkValues_Lean_Meta_withNewMCtxDepth___at___00JunkValues_matchRule_x3f_spec__3(v_00_u03b1_256_, v_k_257_, v_allowLevelAssignments_boxed_264_, v___y_259_, v___y_260_, v___y_261_, v___y_262_);
lean_dec(v___y_262_);
lean_dec_ref(v___y_261_);
lean_dec(v___y_260_);
lean_dec_ref(v___y_259_);
return v_res_265_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_withoutModifyingState___at___00JunkValues_matchRule_x3f_spec__4___redArg(lean_object* v_x_266_, lean_object* v___y_267_, lean_object* v___y_268_, lean_object* v___y_269_, lean_object* v___y_270_){
_start:
{
lean_object* v___x_272_; 
v___x_272_ = l_Lean_Meta_saveState___redArg(v___y_268_, v___y_270_);
if (lean_obj_tag(v___x_272_) == 0)
{
lean_object* v_a_273_; lean_object* v_r_274_; 
v_a_273_ = lean_ctor_get(v___x_272_, 0);
lean_inc(v_a_273_);
lean_dec_ref_known(v___x_272_, 1);
lean_inc(v___y_270_);
lean_inc_ref(v___y_269_);
lean_inc(v___y_268_);
lean_inc_ref(v___y_267_);
v_r_274_ = lean_apply_5(v_x_266_, v___y_267_, v___y_268_, v___y_269_, v___y_270_, lean_box(0));
if (lean_obj_tag(v_r_274_) == 0)
{
lean_object* v_a_275_; lean_object* v___x_276_; 
v_a_275_ = lean_ctor_get(v_r_274_, 0);
lean_inc(v_a_275_);
lean_dec_ref_known(v_r_274_, 1);
v___x_276_ = l_Lean_Meta_SavedState_restore___redArg(v_a_273_, v___y_268_, v___y_270_);
lean_dec(v_a_273_);
if (lean_obj_tag(v___x_276_) == 0)
{
lean_object* v___x_278_; uint8_t v_isShared_279_; uint8_t v_isSharedCheck_283_; 
v_isSharedCheck_283_ = !lean_is_exclusive(v___x_276_);
if (v_isSharedCheck_283_ == 0)
{
lean_object* v_unused_284_; 
v_unused_284_ = lean_ctor_get(v___x_276_, 0);
lean_dec(v_unused_284_);
v___x_278_ = v___x_276_;
v_isShared_279_ = v_isSharedCheck_283_;
goto v_resetjp_277_;
}
else
{
lean_dec(v___x_276_);
v___x_278_ = lean_box(0);
v_isShared_279_ = v_isSharedCheck_283_;
goto v_resetjp_277_;
}
v_resetjp_277_:
{
lean_object* v___x_281_; 
if (v_isShared_279_ == 0)
{
lean_ctor_set(v___x_278_, 0, v_a_275_);
v___x_281_ = v___x_278_;
goto v_reusejp_280_;
}
else
{
lean_object* v_reuseFailAlloc_282_; 
v_reuseFailAlloc_282_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_282_, 0, v_a_275_);
v___x_281_ = v_reuseFailAlloc_282_;
goto v_reusejp_280_;
}
v_reusejp_280_:
{
return v___x_281_;
}
}
}
else
{
lean_object* v_a_285_; lean_object* v___x_287_; uint8_t v_isShared_288_; uint8_t v_isSharedCheck_292_; 
lean_dec(v_a_275_);
v_a_285_ = lean_ctor_get(v___x_276_, 0);
v_isSharedCheck_292_ = !lean_is_exclusive(v___x_276_);
if (v_isSharedCheck_292_ == 0)
{
v___x_287_ = v___x_276_;
v_isShared_288_ = v_isSharedCheck_292_;
goto v_resetjp_286_;
}
else
{
lean_inc(v_a_285_);
lean_dec(v___x_276_);
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
else
{
lean_object* v_a_293_; lean_object* v___x_294_; 
v_a_293_ = lean_ctor_get(v_r_274_, 0);
lean_inc(v_a_293_);
lean_dec_ref_known(v_r_274_, 1);
v___x_294_ = l_Lean_Meta_SavedState_restore___redArg(v_a_273_, v___y_268_, v___y_270_);
lean_dec(v_a_273_);
if (lean_obj_tag(v___x_294_) == 0)
{
lean_object* v___x_296_; uint8_t v_isShared_297_; uint8_t v_isSharedCheck_301_; 
v_isSharedCheck_301_ = !lean_is_exclusive(v___x_294_);
if (v_isSharedCheck_301_ == 0)
{
lean_object* v_unused_302_; 
v_unused_302_ = lean_ctor_get(v___x_294_, 0);
lean_dec(v_unused_302_);
v___x_296_ = v___x_294_;
v_isShared_297_ = v_isSharedCheck_301_;
goto v_resetjp_295_;
}
else
{
lean_dec(v___x_294_);
v___x_296_ = lean_box(0);
v_isShared_297_ = v_isSharedCheck_301_;
goto v_resetjp_295_;
}
v_resetjp_295_:
{
lean_object* v___x_299_; 
if (v_isShared_297_ == 0)
{
lean_ctor_set_tag(v___x_296_, 1);
lean_ctor_set(v___x_296_, 0, v_a_293_);
v___x_299_ = v___x_296_;
goto v_reusejp_298_;
}
else
{
lean_object* v_reuseFailAlloc_300_; 
v_reuseFailAlloc_300_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_300_, 0, v_a_293_);
v___x_299_ = v_reuseFailAlloc_300_;
goto v_reusejp_298_;
}
v_reusejp_298_:
{
return v___x_299_;
}
}
}
else
{
lean_object* v_a_303_; lean_object* v___x_305_; uint8_t v_isShared_306_; uint8_t v_isSharedCheck_310_; 
lean_dec(v_a_293_);
v_a_303_ = lean_ctor_get(v___x_294_, 0);
v_isSharedCheck_310_ = !lean_is_exclusive(v___x_294_);
if (v_isSharedCheck_310_ == 0)
{
v___x_305_ = v___x_294_;
v_isShared_306_ = v_isSharedCheck_310_;
goto v_resetjp_304_;
}
else
{
lean_inc(v_a_303_);
lean_dec(v___x_294_);
v___x_305_ = lean_box(0);
v_isShared_306_ = v_isSharedCheck_310_;
goto v_resetjp_304_;
}
v_resetjp_304_:
{
lean_object* v___x_308_; 
if (v_isShared_306_ == 0)
{
v___x_308_ = v___x_305_;
goto v_reusejp_307_;
}
else
{
lean_object* v_reuseFailAlloc_309_; 
v_reuseFailAlloc_309_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_309_, 0, v_a_303_);
v___x_308_ = v_reuseFailAlloc_309_;
goto v_reusejp_307_;
}
v_reusejp_307_:
{
return v___x_308_;
}
}
}
}
}
else
{
lean_object* v_a_311_; lean_object* v___x_313_; uint8_t v_isShared_314_; uint8_t v_isSharedCheck_318_; 
lean_dec_ref(v_x_266_);
v_a_311_ = lean_ctor_get(v___x_272_, 0);
v_isSharedCheck_318_ = !lean_is_exclusive(v___x_272_);
if (v_isSharedCheck_318_ == 0)
{
v___x_313_ = v___x_272_;
v_isShared_314_ = v_isSharedCheck_318_;
goto v_resetjp_312_;
}
else
{
lean_inc(v_a_311_);
lean_dec(v___x_272_);
v___x_313_ = lean_box(0);
v_isShared_314_ = v_isSharedCheck_318_;
goto v_resetjp_312_;
}
v_resetjp_312_:
{
lean_object* v___x_316_; 
if (v_isShared_314_ == 0)
{
v___x_316_ = v___x_313_;
goto v_reusejp_315_;
}
else
{
lean_object* v_reuseFailAlloc_317_; 
v_reuseFailAlloc_317_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_317_, 0, v_a_311_);
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
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_withoutModifyingState___at___00JunkValues_matchRule_x3f_spec__4___redArg___boxed(lean_object* v_x_319_, lean_object* v___y_320_, lean_object* v___y_321_, lean_object* v___y_322_, lean_object* v___y_323_, lean_object* v___y_324_){
_start:
{
lean_object* v_res_325_; 
v_res_325_ = lp_JunkValues_Lean_withoutModifyingState___at___00JunkValues_matchRule_x3f_spec__4___redArg(v_x_319_, v___y_320_, v___y_321_, v___y_322_, v___y_323_);
lean_dec(v___y_323_);
lean_dec_ref(v___y_322_);
lean_dec(v___y_321_);
lean_dec_ref(v___y_320_);
return v_res_325_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_withoutModifyingState___at___00JunkValues_matchRule_x3f_spec__4(lean_object* v_00_u03b1_326_, lean_object* v_x_327_, lean_object* v___y_328_, lean_object* v___y_329_, lean_object* v___y_330_, lean_object* v___y_331_){
_start:
{
lean_object* v___x_333_; 
v___x_333_ = lp_JunkValues_Lean_withoutModifyingState___at___00JunkValues_matchRule_x3f_spec__4___redArg(v_x_327_, v___y_328_, v___y_329_, v___y_330_, v___y_331_);
return v___x_333_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_withoutModifyingState___at___00JunkValues_matchRule_x3f_spec__4___boxed(lean_object* v_00_u03b1_334_, lean_object* v_x_335_, lean_object* v___y_336_, lean_object* v___y_337_, lean_object* v___y_338_, lean_object* v___y_339_, lean_object* v___y_340_){
_start:
{
lean_object* v_res_341_; 
v_res_341_ = lp_JunkValues_Lean_withoutModifyingState___at___00JunkValues_matchRule_x3f_spec__4(v_00_u03b1_334_, v_x_335_, v___y_336_, v___y_337_, v___y_338_, v___y_339_);
lean_dec(v___y_339_);
lean_dec_ref(v___y_338_);
lean_dec(v___y_337_);
lean_dec_ref(v___y_336_);
return v_res_341_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00JunkValues_matchRule_x3f_spec__2(size_t v_sz_342_, size_t v_i_343_, lean_object* v_bs_344_, lean_object* v___y_345_, lean_object* v___y_346_, lean_object* v___y_347_, lean_object* v___y_348_){
_start:
{
uint8_t v___x_350_; 
v___x_350_ = lean_usize_dec_lt(v_i_343_, v_sz_342_);
if (v___x_350_ == 0)
{
lean_object* v___x_351_; 
v___x_351_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_351_, 0, v_bs_344_);
return v___x_351_;
}
else
{
lean_object* v_v_352_; lean_object* v___x_353_; 
v_v_352_ = lean_array_uget_borrowed(v_bs_344_, v_i_343_);
lean_inc(v_v_352_);
v___x_353_ = lp_JunkValues_Lean_instantiateMVars___at___00JunkValues_matchRule_x3f_spec__0___redArg(v_v_352_, v___y_346_);
if (lean_obj_tag(v___x_353_) == 0)
{
lean_object* v_a_354_; lean_object* v___x_355_; lean_object* v_bs_x27_356_; size_t v___x_357_; size_t v___x_358_; lean_object* v___x_359_; 
v_a_354_ = lean_ctor_get(v___x_353_, 0);
lean_inc(v_a_354_);
lean_dec_ref_known(v___x_353_, 1);
v___x_355_ = lean_unsigned_to_nat(0u);
v_bs_x27_356_ = lean_array_uset(v_bs_344_, v_i_343_, v___x_355_);
v___x_357_ = ((size_t)1ULL);
v___x_358_ = lean_usize_add(v_i_343_, v___x_357_);
v___x_359_ = lean_array_uset(v_bs_x27_356_, v_i_343_, v_a_354_);
v_i_343_ = v___x_358_;
v_bs_344_ = v___x_359_;
goto _start;
}
else
{
lean_object* v_a_361_; lean_object* v___x_363_; uint8_t v_isShared_364_; uint8_t v_isSharedCheck_368_; 
lean_dec_ref(v_bs_344_);
v_a_361_ = lean_ctor_get(v___x_353_, 0);
v_isSharedCheck_368_ = !lean_is_exclusive(v___x_353_);
if (v_isSharedCheck_368_ == 0)
{
v___x_363_ = v___x_353_;
v_isShared_364_ = v_isSharedCheck_368_;
goto v_resetjp_362_;
}
else
{
lean_inc(v_a_361_);
lean_dec(v___x_353_);
v___x_363_ = lean_box(0);
v_isShared_364_ = v_isSharedCheck_368_;
goto v_resetjp_362_;
}
v_resetjp_362_:
{
lean_object* v___x_366_; 
if (v_isShared_364_ == 0)
{
v___x_366_ = v___x_363_;
goto v_reusejp_365_;
}
else
{
lean_object* v_reuseFailAlloc_367_; 
v_reuseFailAlloc_367_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_367_, 0, v_a_361_);
v___x_366_ = v_reuseFailAlloc_367_;
goto v_reusejp_365_;
}
v_reusejp_365_:
{
return v___x_366_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00JunkValues_matchRule_x3f_spec__2___boxed(lean_object* v_sz_369_, lean_object* v_i_370_, lean_object* v_bs_371_, lean_object* v___y_372_, lean_object* v___y_373_, lean_object* v___y_374_, lean_object* v___y_375_, lean_object* v___y_376_){
_start:
{
size_t v_sz_boxed_377_; size_t v_i_boxed_378_; lean_object* v_res_379_; 
v_sz_boxed_377_ = lean_unbox_usize(v_sz_369_);
lean_dec(v_sz_369_);
v_i_boxed_378_ = lean_unbox_usize(v_i_370_);
lean_dec(v_i_370_);
v_res_379_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00JunkValues_matchRule_x3f_spec__2(v_sz_boxed_377_, v_i_boxed_378_, v_bs_371_, v___y_372_, v___y_373_, v___y_374_, v___y_375_);
lean_dec(v___y_375_);
lean_dec_ref(v___y_374_);
lean_dec(v___y_373_);
lean_dec_ref(v___y_372_);
return v_res_379_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00JunkValues_matchRule_x3f_spec__1___redArg(lean_object* v___x_382_, lean_object* v_val_383_, lean_object* v_range_384_, lean_object* v_b_385_, lean_object* v_i_386_, lean_object* v___y_387_, lean_object* v___y_388_, lean_object* v___y_389_, lean_object* v___y_390_){
_start:
{
lean_object* v_stop_392_; lean_object* v_step_393_; lean_object* v_a_395_; uint8_t v___x_398_; 
v_stop_392_ = lean_ctor_get(v_range_384_, 1);
v_step_393_ = lean_ctor_get(v_range_384_, 2);
v___x_398_ = lean_nat_dec_lt(v_i_386_, v_stop_392_);
if (v___x_398_ == 0)
{
lean_object* v___x_399_; 
lean_dec(v_i_386_);
v___x_399_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_399_, 0, v_b_385_);
return v___x_399_;
}
else
{
lean_object* v___x_400_; lean_object* v___x_401_; lean_object* v_a_402_; lean_object* v_snd_403_; lean_object* v___x_405_; uint8_t v_isShared_406_; uint8_t v_isSharedCheck_495_; 
v___x_400_ = lean_array_fget_borrowed(v___x_382_, v_i_386_);
lean_inc(v___x_400_);
v___x_401_ = lp_JunkValues_Lean_instantiateMVars___at___00JunkValues_matchRule_x3f_spec__0___redArg(v___x_400_, v___y_388_);
v_a_402_ = lean_ctor_get(v___x_401_, 0);
lean_inc(v_a_402_);
lean_dec_ref(v___x_401_);
v_snd_403_ = lean_ctor_get(v_b_385_, 1);
v_isSharedCheck_495_ = !lean_is_exclusive(v_b_385_);
if (v_isSharedCheck_495_ == 0)
{
lean_object* v_unused_496_; 
v_unused_496_ = lean_ctor_get(v_b_385_, 0);
lean_dec(v_unused_496_);
v___x_405_ = v_b_385_;
v_isShared_406_ = v_isSharedCheck_495_;
goto v_resetjp_404_;
}
else
{
lean_inc(v_snd_403_);
lean_dec(v_b_385_);
v___x_405_ = lean_box(0);
v_isShared_406_ = v_isSharedCheck_495_;
goto v_resetjp_404_;
}
v_resetjp_404_:
{
lean_object* v___x_407_; uint8_t v___x_408_; 
v___x_407_ = lean_box(0);
v___x_408_ = l_Lean_Expr_isMVar(v_a_402_);
lean_dec(v_a_402_);
if (v___x_408_ == 0)
{
lean_object* v___x_410_; 
if (v_isShared_406_ == 0)
{
lean_ctor_set(v___x_405_, 0, v___x_407_);
v___x_410_ = v___x_405_;
goto v_reusejp_409_;
}
else
{
lean_object* v_reuseFailAlloc_411_; 
v_reuseFailAlloc_411_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_411_, 0, v___x_407_);
lean_ctor_set(v_reuseFailAlloc_411_, 1, v_snd_403_);
v___x_410_ = v_reuseFailAlloc_411_;
goto v_reusejp_409_;
}
v_reusejp_409_:
{
v_a_395_ = v___x_410_;
goto v___jp_394_;
}
}
else
{
lean_object* v___x_412_; 
lean_inc(v___y_390_);
lean_inc_ref(v___y_389_);
lean_inc(v___y_388_);
lean_inc_ref(v___y_387_);
lean_inc(v___x_400_);
v___x_412_ = lean_infer_type(v___x_400_, v___y_387_, v___y_388_, v___y_389_, v___y_390_);
if (lean_obj_tag(v___x_412_) == 0)
{
lean_object* v_a_413_; lean_object* v___x_414_; lean_object* v_a_415_; lean_object* v_binderInfos_416_; uint8_t v___x_417_; lean_object* v___x_418_; lean_object* v___x_419_; uint8_t v___x_420_; lean_object* v___x_421_; 
v_a_413_ = lean_ctor_get(v___x_412_, 0);
lean_inc(v_a_413_);
lean_dec_ref_known(v___x_412_, 1);
v___x_414_ = lp_JunkValues_Lean_instantiateMVars___at___00JunkValues_matchRule_x3f_spec__0___redArg(v_a_413_, v___y_388_);
v_a_415_ = lean_ctor_get(v___x_414_, 0);
lean_inc_n(v_a_415_, 2);
lean_dec_ref(v___x_414_);
v_binderInfos_416_ = lean_ctor_get(v_val_383_, 1);
v___x_417_ = 0;
v___x_418_ = lean_box(v___x_417_);
v___x_419_ = lean_array_get(v___x_418_, v_binderInfos_416_, v_i_386_);
lean_dec(v___x_418_);
v___x_420_ = lean_unbox(v___x_419_);
v___x_421_ = lp_JunkValues_JunkValues_isGuardBinder(v___x_420_, v_a_415_, v___y_387_, v___y_388_, v___y_389_, v___y_390_);
if (lean_obj_tag(v___x_421_) == 0)
{
lean_object* v_a_422_; uint8_t v___x_423_; 
v_a_422_ = lean_ctor_get(v___x_421_, 0);
lean_inc(v_a_422_);
lean_dec_ref_known(v___x_421_, 1);
v___x_423_ = lean_unbox(v_a_422_);
lean_dec(v_a_422_);
if (v___x_423_ == 0)
{
uint8_t v___x_424_; 
v___x_424_ = lean_unbox(v___x_419_);
lean_dec(v___x_419_);
if (v___x_424_ == 3)
{
lean_object* v___x_425_; 
v___x_425_ = l_Lean_Meta_trySynthInstance(v_a_415_, v___x_407_, v___y_387_, v___y_388_, v___y_389_, v___y_390_);
if (lean_obj_tag(v___x_425_) == 0)
{
lean_object* v_a_426_; lean_object* v___x_428_; uint8_t v_isShared_429_; uint8_t v_isSharedCheck_463_; 
v_a_426_ = lean_ctor_get(v___x_425_, 0);
v_isSharedCheck_463_ = !lean_is_exclusive(v___x_425_);
if (v_isSharedCheck_463_ == 0)
{
v___x_428_ = v___x_425_;
v_isShared_429_ = v_isSharedCheck_463_;
goto v_resetjp_427_;
}
else
{
lean_inc(v_a_426_);
lean_dec(v___x_425_);
v___x_428_ = lean_box(0);
v_isShared_429_ = v_isSharedCheck_463_;
goto v_resetjp_427_;
}
v_resetjp_427_:
{
if (lean_obj_tag(v_a_426_) == 1)
{
lean_object* v_a_430_; lean_object* v___x_431_; 
lean_del_object(v___x_428_);
v_a_430_ = lean_ctor_get(v_a_426_, 0);
lean_inc(v_a_430_);
lean_dec_ref_known(v_a_426_, 1);
lean_inc(v___x_400_);
v___x_431_ = l_Lean_Meta_isExprDefEq(v___x_400_, v_a_430_, v___y_387_, v___y_388_, v___y_389_, v___y_390_);
if (lean_obj_tag(v___x_431_) == 0)
{
lean_object* v_a_432_; lean_object* v___x_434_; uint8_t v_isShared_435_; uint8_t v_isSharedCheck_447_; 
v_a_432_ = lean_ctor_get(v___x_431_, 0);
v_isSharedCheck_447_ = !lean_is_exclusive(v___x_431_);
if (v_isSharedCheck_447_ == 0)
{
v___x_434_ = v___x_431_;
v_isShared_435_ = v_isSharedCheck_447_;
goto v_resetjp_433_;
}
else
{
lean_inc(v_a_432_);
lean_dec(v___x_431_);
v___x_434_ = lean_box(0);
v_isShared_435_ = v_isSharedCheck_447_;
goto v_resetjp_433_;
}
v_resetjp_433_:
{
uint8_t v___x_436_; 
v___x_436_ = lean_unbox(v_a_432_);
lean_dec(v_a_432_);
if (v___x_436_ == 0)
{
lean_object* v___x_437_; lean_object* v___x_439_; 
lean_dec(v_i_386_);
v___x_437_ = ((lean_object*)(lp_JunkValues___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00JunkValues_matchRule_x3f_spec__1___redArg___closed__0));
if (v_isShared_406_ == 0)
{
lean_ctor_set(v___x_405_, 0, v___x_437_);
v___x_439_ = v___x_405_;
goto v_reusejp_438_;
}
else
{
lean_object* v_reuseFailAlloc_443_; 
v_reuseFailAlloc_443_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_443_, 0, v___x_437_);
lean_ctor_set(v_reuseFailAlloc_443_, 1, v_snd_403_);
v___x_439_ = v_reuseFailAlloc_443_;
goto v_reusejp_438_;
}
v_reusejp_438_:
{
lean_object* v___x_441_; 
if (v_isShared_435_ == 0)
{
lean_ctor_set(v___x_434_, 0, v___x_439_);
v___x_441_ = v___x_434_;
goto v_reusejp_440_;
}
else
{
lean_object* v_reuseFailAlloc_442_; 
v_reuseFailAlloc_442_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_442_, 0, v___x_439_);
v___x_441_ = v_reuseFailAlloc_442_;
goto v_reusejp_440_;
}
v_reusejp_440_:
{
return v___x_441_;
}
}
}
else
{
lean_object* v___x_445_; 
lean_del_object(v___x_434_);
if (v_isShared_406_ == 0)
{
lean_ctor_set(v___x_405_, 0, v___x_407_);
v___x_445_ = v___x_405_;
goto v_reusejp_444_;
}
else
{
lean_object* v_reuseFailAlloc_446_; 
v_reuseFailAlloc_446_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_446_, 0, v___x_407_);
lean_ctor_set(v_reuseFailAlloc_446_, 1, v_snd_403_);
v___x_445_ = v_reuseFailAlloc_446_;
goto v_reusejp_444_;
}
v_reusejp_444_:
{
v_a_395_ = v___x_445_;
goto v___jp_394_;
}
}
}
}
else
{
lean_object* v_a_448_; lean_object* v___x_450_; uint8_t v_isShared_451_; uint8_t v_isSharedCheck_455_; 
lean_del_object(v___x_405_);
lean_dec(v_snd_403_);
lean_dec(v_i_386_);
v_a_448_ = lean_ctor_get(v___x_431_, 0);
v_isSharedCheck_455_ = !lean_is_exclusive(v___x_431_);
if (v_isSharedCheck_455_ == 0)
{
v___x_450_ = v___x_431_;
v_isShared_451_ = v_isSharedCheck_455_;
goto v_resetjp_449_;
}
else
{
lean_inc(v_a_448_);
lean_dec(v___x_431_);
v___x_450_ = lean_box(0);
v_isShared_451_ = v_isSharedCheck_455_;
goto v_resetjp_449_;
}
v_resetjp_449_:
{
lean_object* v___x_453_; 
if (v_isShared_451_ == 0)
{
v___x_453_ = v___x_450_;
goto v_reusejp_452_;
}
else
{
lean_object* v_reuseFailAlloc_454_; 
v_reuseFailAlloc_454_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_454_, 0, v_a_448_);
v___x_453_ = v_reuseFailAlloc_454_;
goto v_reusejp_452_;
}
v_reusejp_452_:
{
return v___x_453_;
}
}
}
}
else
{
lean_object* v___x_456_; lean_object* v___x_458_; 
lean_dec(v_a_426_);
lean_dec(v_i_386_);
v___x_456_ = ((lean_object*)(lp_JunkValues___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00JunkValues_matchRule_x3f_spec__1___redArg___closed__0));
if (v_isShared_406_ == 0)
{
lean_ctor_set(v___x_405_, 0, v___x_456_);
v___x_458_ = v___x_405_;
goto v_reusejp_457_;
}
else
{
lean_object* v_reuseFailAlloc_462_; 
v_reuseFailAlloc_462_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_462_, 0, v___x_456_);
lean_ctor_set(v_reuseFailAlloc_462_, 1, v_snd_403_);
v___x_458_ = v_reuseFailAlloc_462_;
goto v_reusejp_457_;
}
v_reusejp_457_:
{
lean_object* v___x_460_; 
if (v_isShared_429_ == 0)
{
lean_ctor_set(v___x_428_, 0, v___x_458_);
v___x_460_ = v___x_428_;
goto v_reusejp_459_;
}
else
{
lean_object* v_reuseFailAlloc_461_; 
v_reuseFailAlloc_461_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_461_, 0, v___x_458_);
v___x_460_ = v_reuseFailAlloc_461_;
goto v_reusejp_459_;
}
v_reusejp_459_:
{
return v___x_460_;
}
}
}
}
}
else
{
lean_object* v_a_464_; lean_object* v___x_466_; uint8_t v_isShared_467_; uint8_t v_isSharedCheck_471_; 
lean_del_object(v___x_405_);
lean_dec(v_snd_403_);
lean_dec(v_i_386_);
v_a_464_ = lean_ctor_get(v___x_425_, 0);
v_isSharedCheck_471_ = !lean_is_exclusive(v___x_425_);
if (v_isSharedCheck_471_ == 0)
{
v___x_466_ = v___x_425_;
v_isShared_467_ = v_isSharedCheck_471_;
goto v_resetjp_465_;
}
else
{
lean_inc(v_a_464_);
lean_dec(v___x_425_);
v___x_466_ = lean_box(0);
v_isShared_467_ = v_isSharedCheck_471_;
goto v_resetjp_465_;
}
v_resetjp_465_:
{
lean_object* v___x_469_; 
if (v_isShared_467_ == 0)
{
v___x_469_ = v___x_466_;
goto v_reusejp_468_;
}
else
{
lean_object* v_reuseFailAlloc_470_; 
v_reuseFailAlloc_470_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_470_, 0, v_a_464_);
v___x_469_ = v_reuseFailAlloc_470_;
goto v_reusejp_468_;
}
v_reusejp_468_:
{
return v___x_469_;
}
}
}
}
else
{
lean_object* v___x_473_; 
lean_dec(v_a_415_);
if (v_isShared_406_ == 0)
{
lean_ctor_set(v___x_405_, 0, v___x_407_);
v___x_473_ = v___x_405_;
goto v_reusejp_472_;
}
else
{
lean_object* v_reuseFailAlloc_474_; 
v_reuseFailAlloc_474_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_474_, 0, v___x_407_);
lean_ctor_set(v_reuseFailAlloc_474_, 1, v_snd_403_);
v___x_473_ = v_reuseFailAlloc_474_;
goto v_reusejp_472_;
}
v_reusejp_472_:
{
v_a_395_ = v___x_473_;
goto v___jp_394_;
}
}
}
else
{
lean_object* v___x_475_; lean_object* v___x_477_; 
lean_dec(v___x_419_);
v___x_475_ = lean_array_push(v_snd_403_, v_a_415_);
if (v_isShared_406_ == 0)
{
lean_ctor_set(v___x_405_, 1, v___x_475_);
lean_ctor_set(v___x_405_, 0, v___x_407_);
v___x_477_ = v___x_405_;
goto v_reusejp_476_;
}
else
{
lean_object* v_reuseFailAlloc_478_; 
v_reuseFailAlloc_478_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_478_, 0, v___x_407_);
lean_ctor_set(v_reuseFailAlloc_478_, 1, v___x_475_);
v___x_477_ = v_reuseFailAlloc_478_;
goto v_reusejp_476_;
}
v_reusejp_476_:
{
v_a_395_ = v___x_477_;
goto v___jp_394_;
}
}
}
else
{
lean_object* v_a_479_; lean_object* v___x_481_; uint8_t v_isShared_482_; uint8_t v_isSharedCheck_486_; 
lean_dec(v___x_419_);
lean_dec(v_a_415_);
lean_del_object(v___x_405_);
lean_dec(v_snd_403_);
lean_dec(v_i_386_);
v_a_479_ = lean_ctor_get(v___x_421_, 0);
v_isSharedCheck_486_ = !lean_is_exclusive(v___x_421_);
if (v_isSharedCheck_486_ == 0)
{
v___x_481_ = v___x_421_;
v_isShared_482_ = v_isSharedCheck_486_;
goto v_resetjp_480_;
}
else
{
lean_inc(v_a_479_);
lean_dec(v___x_421_);
v___x_481_ = lean_box(0);
v_isShared_482_ = v_isSharedCheck_486_;
goto v_resetjp_480_;
}
v_resetjp_480_:
{
lean_object* v___x_484_; 
if (v_isShared_482_ == 0)
{
v___x_484_ = v___x_481_;
goto v_reusejp_483_;
}
else
{
lean_object* v_reuseFailAlloc_485_; 
v_reuseFailAlloc_485_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_485_, 0, v_a_479_);
v___x_484_ = v_reuseFailAlloc_485_;
goto v_reusejp_483_;
}
v_reusejp_483_:
{
return v___x_484_;
}
}
}
}
else
{
lean_object* v_a_487_; lean_object* v___x_489_; uint8_t v_isShared_490_; uint8_t v_isSharedCheck_494_; 
lean_del_object(v___x_405_);
lean_dec(v_snd_403_);
lean_dec(v_i_386_);
v_a_487_ = lean_ctor_get(v___x_412_, 0);
v_isSharedCheck_494_ = !lean_is_exclusive(v___x_412_);
if (v_isSharedCheck_494_ == 0)
{
v___x_489_ = v___x_412_;
v_isShared_490_ = v_isSharedCheck_494_;
goto v_resetjp_488_;
}
else
{
lean_inc(v_a_487_);
lean_dec(v___x_412_);
v___x_489_ = lean_box(0);
v_isShared_490_ = v_isSharedCheck_494_;
goto v_resetjp_488_;
}
v_resetjp_488_:
{
lean_object* v___x_492_; 
if (v_isShared_490_ == 0)
{
v___x_492_ = v___x_489_;
goto v_reusejp_491_;
}
else
{
lean_object* v_reuseFailAlloc_493_; 
v_reuseFailAlloc_493_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_493_, 0, v_a_487_);
v___x_492_ = v_reuseFailAlloc_493_;
goto v_reusejp_491_;
}
v_reusejp_491_:
{
return v___x_492_;
}
}
}
}
}
}
v___jp_394_:
{
lean_object* v___x_396_; 
v___x_396_ = lean_nat_add(v_i_386_, v_step_393_);
lean_dec(v_i_386_);
v_b_385_ = v_a_395_;
v_i_386_ = v___x_396_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00JunkValues_matchRule_x3f_spec__1___redArg___boxed(lean_object* v___x_497_, lean_object* v_val_498_, lean_object* v_range_499_, lean_object* v_b_500_, lean_object* v_i_501_, lean_object* v___y_502_, lean_object* v___y_503_, lean_object* v___y_504_, lean_object* v___y_505_, lean_object* v___y_506_){
_start:
{
lean_object* v_res_507_; 
v_res_507_ = lp_JunkValues___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00JunkValues_matchRule_x3f_spec__1___redArg(v___x_497_, v_val_498_, v_range_499_, v_b_500_, v_i_501_, v___y_502_, v___y_503_, v___y_504_, v___y_505_);
lean_dec(v___y_505_);
lean_dec_ref(v___y_504_);
lean_dec(v___y_503_);
lean_dec_ref(v___y_502_);
lean_dec_ref(v_range_499_);
lean_dec_ref(v_val_498_);
lean_dec_ref(v___x_497_);
return v_res_507_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_matchRule_x3f___lam__0(lean_object* v_source_508_, lean_object* v_generalize_509_, lean_object* v_e_510_, lean_object* v___y_511_, lean_object* v___y_512_, lean_object* v___y_513_, lean_object* v___y_514_){
_start:
{
lean_object* v___x_516_; 
v___x_516_ = lp_JunkValues_JunkValues_openRule(v_source_508_, v___y_511_, v___y_512_, v___y_513_, v___y_514_);
if (lean_obj_tag(v___x_516_) == 0)
{
lean_object* v_a_517_; lean_object* v___x_519_; uint8_t v_isShared_520_; uint8_t v_isSharedCheck_636_; 
v_a_517_ = lean_ctor_get(v___x_516_, 0);
v_isSharedCheck_636_ = !lean_is_exclusive(v___x_516_);
if (v_isSharedCheck_636_ == 0)
{
v___x_519_ = v___x_516_;
v_isShared_520_ = v_isSharedCheck_636_;
goto v_resetjp_518_;
}
else
{
lean_inc(v_a_517_);
lean_dec(v___x_516_);
v___x_519_ = lean_box(0);
v_isShared_520_ = v_isSharedCheck_636_;
goto v_resetjp_518_;
}
v_resetjp_518_:
{
if (lean_obj_tag(v_a_517_) == 1)
{
lean_object* v_val_521_; lean_object* v___x_523_; uint8_t v_isShared_524_; uint8_t v_isSharedCheck_631_; 
lean_del_object(v___x_519_);
v_val_521_ = lean_ctor_get(v_a_517_, 0);
v_isSharedCheck_631_ = !lean_is_exclusive(v_a_517_);
if (v_isSharedCheck_631_ == 0)
{
v___x_523_ = v_a_517_;
v_isShared_524_ = v_isSharedCheck_631_;
goto v_resetjp_522_;
}
else
{
lean_inc(v_val_521_);
lean_dec(v_a_517_);
v___x_523_ = lean_box(0);
v_isShared_524_ = v_isSharedCheck_631_;
goto v_resetjp_522_;
}
v_resetjp_522_:
{
lean_object* v_vars_525_; lean_object* v_lhs_526_; lean_object* v_rhs_527_; lean_object* v___x_528_; 
v_vars_525_ = lean_ctor_get(v_val_521_, 0);
lean_inc_ref(v_vars_525_);
v_lhs_526_ = lean_ctor_get(v_val_521_, 2);
v_rhs_527_ = lean_ctor_get(v_val_521_, 3);
lean_inc_ref(v_rhs_527_);
lean_inc_ref(v_lhs_526_);
v___x_528_ = lp_JunkValues_JunkValues_generalizePattern(v_generalize_509_, v_lhs_526_, v___y_511_, v___y_512_, v___y_513_, v___y_514_);
if (lean_obj_tag(v___x_528_) == 0)
{
lean_object* v_a_529_; lean_object* v_fst_530_; lean_object* v_snd_531_; lean_object* v___x_533_; uint8_t v_isShared_534_; uint8_t v_isSharedCheck_622_; 
v_a_529_ = lean_ctor_get(v___x_528_, 0);
lean_inc(v_a_529_);
lean_dec_ref_known(v___x_528_, 1);
v_fst_530_ = lean_ctor_get(v_a_529_, 0);
v_snd_531_ = lean_ctor_get(v_a_529_, 1);
v_isSharedCheck_622_ = !lean_is_exclusive(v_a_529_);
if (v_isSharedCheck_622_ == 0)
{
v___x_533_ = v_a_529_;
v_isShared_534_ = v_isSharedCheck_622_;
goto v_resetjp_532_;
}
else
{
lean_inc(v_snd_531_);
lean_inc(v_fst_530_);
lean_dec(v_a_529_);
v___x_533_ = lean_box(0);
v_isShared_534_ = v_isSharedCheck_622_;
goto v_resetjp_532_;
}
v_resetjp_532_:
{
lean_object* v___x_535_; 
v___x_535_ = l_Lean_Meta_isExprDefEq(v_fst_530_, v_e_510_, v___y_511_, v___y_512_, v___y_513_, v___y_514_);
if (lean_obj_tag(v___x_535_) == 0)
{
lean_object* v_a_536_; lean_object* v___x_538_; uint8_t v_isShared_539_; uint8_t v_isSharedCheck_613_; 
v_a_536_ = lean_ctor_get(v___x_535_, 0);
v_isSharedCheck_613_ = !lean_is_exclusive(v___x_535_);
if (v_isSharedCheck_613_ == 0)
{
v___x_538_ = v___x_535_;
v_isShared_539_ = v_isSharedCheck_613_;
goto v_resetjp_537_;
}
else
{
lean_inc(v_a_536_);
lean_dec(v___x_535_);
v___x_538_ = lean_box(0);
v_isShared_539_ = v_isSharedCheck_613_;
goto v_resetjp_537_;
}
v_resetjp_537_:
{
uint8_t v___x_540_; 
v___x_540_ = lean_unbox(v_a_536_);
lean_dec(v_a_536_);
if (v___x_540_ == 0)
{
lean_object* v___x_541_; lean_object* v___x_543_; 
lean_del_object(v___x_533_);
lean_dec(v_snd_531_);
lean_dec_ref(v_rhs_527_);
lean_dec_ref(v_vars_525_);
lean_del_object(v___x_523_);
lean_dec(v_val_521_);
v___x_541_ = lean_box(0);
if (v_isShared_539_ == 0)
{
lean_ctor_set(v___x_538_, 0, v___x_541_);
v___x_543_ = v___x_538_;
goto v_reusejp_542_;
}
else
{
lean_object* v_reuseFailAlloc_544_; 
v_reuseFailAlloc_544_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_544_, 0, v___x_541_);
v___x_543_ = v_reuseFailAlloc_544_;
goto v_reusejp_542_;
}
v_reusejp_542_:
{
return v___x_543_;
}
}
else
{
lean_object* v___x_545_; lean_object* v___x_546_; lean_object* v___x_547_; lean_object* v___x_548_; lean_object* v___x_549_; lean_object* v___x_551_; 
lean_del_object(v___x_538_);
v___x_545_ = lean_unsigned_to_nat(0u);
v___x_546_ = lean_array_get_size(v_vars_525_);
v___x_547_ = lean_unsigned_to_nat(1u);
v___x_548_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_548_, 0, v___x_545_);
lean_ctor_set(v___x_548_, 1, v___x_546_);
lean_ctor_set(v___x_548_, 2, v___x_547_);
v___x_549_ = lean_box(0);
if (v_isShared_534_ == 0)
{
lean_ctor_set(v___x_533_, 0, v___x_549_);
v___x_551_ = v___x_533_;
goto v_reusejp_550_;
}
else
{
lean_object* v_reuseFailAlloc_612_; 
v_reuseFailAlloc_612_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_612_, 0, v___x_549_);
lean_ctor_set(v_reuseFailAlloc_612_, 1, v_snd_531_);
v___x_551_ = v_reuseFailAlloc_612_;
goto v_reusejp_550_;
}
v_reusejp_550_:
{
lean_object* v___x_552_; 
v___x_552_ = lp_JunkValues___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00JunkValues_matchRule_x3f_spec__1___redArg(v_vars_525_, v_val_521_, v___x_548_, v___x_551_, v___x_545_, v___y_511_, v___y_512_, v___y_513_, v___y_514_);
lean_dec_ref_known(v___x_548_, 3);
lean_dec(v_val_521_);
lean_dec_ref(v_vars_525_);
if (lean_obj_tag(v___x_552_) == 0)
{
lean_object* v_a_553_; lean_object* v___x_555_; uint8_t v_isShared_556_; uint8_t v_isSharedCheck_603_; 
v_a_553_ = lean_ctor_get(v___x_552_, 0);
v_isSharedCheck_603_ = !lean_is_exclusive(v___x_552_);
if (v_isSharedCheck_603_ == 0)
{
v___x_555_ = v___x_552_;
v_isShared_556_ = v_isSharedCheck_603_;
goto v_resetjp_554_;
}
else
{
lean_inc(v_a_553_);
lean_dec(v___x_552_);
v___x_555_ = lean_box(0);
v_isShared_556_ = v_isSharedCheck_603_;
goto v_resetjp_554_;
}
v_resetjp_554_:
{
lean_object* v_fst_557_; 
v_fst_557_ = lean_ctor_get(v_a_553_, 0);
if (lean_obj_tag(v_fst_557_) == 0)
{
lean_object* v_snd_558_; lean_object* v___x_560_; uint8_t v_isShared_561_; uint8_t v_isSharedCheck_597_; 
lean_del_object(v___x_555_);
v_snd_558_ = lean_ctor_get(v_a_553_, 1);
v_isSharedCheck_597_ = !lean_is_exclusive(v_a_553_);
if (v_isSharedCheck_597_ == 0)
{
lean_object* v_unused_598_; 
v_unused_598_ = lean_ctor_get(v_a_553_, 0);
lean_dec(v_unused_598_);
v___x_560_ = v_a_553_;
v_isShared_561_ = v_isSharedCheck_597_;
goto v_resetjp_559_;
}
else
{
lean_inc(v_snd_558_);
lean_dec(v_a_553_);
v___x_560_ = lean_box(0);
v_isShared_561_ = v_isSharedCheck_597_;
goto v_resetjp_559_;
}
v_resetjp_559_:
{
lean_object* v___x_562_; lean_object* v_a_563_; lean_object* v___x_565_; uint8_t v_isShared_566_; uint8_t v_isSharedCheck_596_; 
v___x_562_ = lp_JunkValues_Lean_instantiateMVars___at___00JunkValues_matchRule_x3f_spec__0___redArg(v_rhs_527_, v___y_512_);
v_a_563_ = lean_ctor_get(v___x_562_, 0);
v_isSharedCheck_596_ = !lean_is_exclusive(v___x_562_);
if (v_isSharedCheck_596_ == 0)
{
v___x_565_ = v___x_562_;
v_isShared_566_ = v_isSharedCheck_596_;
goto v_resetjp_564_;
}
else
{
lean_inc(v_a_563_);
lean_dec(v___x_562_);
v___x_565_ = lean_box(0);
v_isShared_566_ = v_isSharedCheck_596_;
goto v_resetjp_564_;
}
v_resetjp_564_:
{
uint8_t v___x_567_; 
v___x_567_ = l_Lean_Expr_hasExprMVar(v_a_563_);
if (v___x_567_ == 0)
{
size_t v_sz_568_; size_t v___x_569_; lean_object* v___x_570_; 
lean_del_object(v___x_565_);
v_sz_568_ = lean_array_size(v_snd_558_);
v___x_569_ = ((size_t)0ULL);
v___x_570_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00JunkValues_matchRule_x3f_spec__2(v_sz_568_, v___x_569_, v_snd_558_, v___y_511_, v___y_512_, v___y_513_, v___y_514_);
if (lean_obj_tag(v___x_570_) == 0)
{
lean_object* v_a_571_; lean_object* v___x_573_; uint8_t v_isShared_574_; uint8_t v_isSharedCheck_584_; 
v_a_571_ = lean_ctor_get(v___x_570_, 0);
v_isSharedCheck_584_ = !lean_is_exclusive(v___x_570_);
if (v_isSharedCheck_584_ == 0)
{
v___x_573_ = v___x_570_;
v_isShared_574_ = v_isSharedCheck_584_;
goto v_resetjp_572_;
}
else
{
lean_inc(v_a_571_);
lean_dec(v___x_570_);
v___x_573_ = lean_box(0);
v_isShared_574_ = v_isSharedCheck_584_;
goto v_resetjp_572_;
}
v_resetjp_572_:
{
lean_object* v___x_576_; 
if (v_isShared_561_ == 0)
{
lean_ctor_set(v___x_560_, 1, v_a_563_);
lean_ctor_set(v___x_560_, 0, v_a_571_);
v___x_576_ = v___x_560_;
goto v_reusejp_575_;
}
else
{
lean_object* v_reuseFailAlloc_583_; 
v_reuseFailAlloc_583_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_583_, 0, v_a_571_);
lean_ctor_set(v_reuseFailAlloc_583_, 1, v_a_563_);
v___x_576_ = v_reuseFailAlloc_583_;
goto v_reusejp_575_;
}
v_reusejp_575_:
{
lean_object* v___x_578_; 
if (v_isShared_524_ == 0)
{
lean_ctor_set(v___x_523_, 0, v___x_576_);
v___x_578_ = v___x_523_;
goto v_reusejp_577_;
}
else
{
lean_object* v_reuseFailAlloc_582_; 
v_reuseFailAlloc_582_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_582_, 0, v___x_576_);
v___x_578_ = v_reuseFailAlloc_582_;
goto v_reusejp_577_;
}
v_reusejp_577_:
{
lean_object* v___x_580_; 
if (v_isShared_574_ == 0)
{
lean_ctor_set(v___x_573_, 0, v___x_578_);
v___x_580_ = v___x_573_;
goto v_reusejp_579_;
}
else
{
lean_object* v_reuseFailAlloc_581_; 
v_reuseFailAlloc_581_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_581_, 0, v___x_578_);
v___x_580_ = v_reuseFailAlloc_581_;
goto v_reusejp_579_;
}
v_reusejp_579_:
{
return v___x_580_;
}
}
}
}
}
else
{
lean_object* v_a_585_; lean_object* v___x_587_; uint8_t v_isShared_588_; uint8_t v_isSharedCheck_592_; 
lean_dec(v_a_563_);
lean_del_object(v___x_560_);
lean_del_object(v___x_523_);
v_a_585_ = lean_ctor_get(v___x_570_, 0);
v_isSharedCheck_592_ = !lean_is_exclusive(v___x_570_);
if (v_isSharedCheck_592_ == 0)
{
v___x_587_ = v___x_570_;
v_isShared_588_ = v_isSharedCheck_592_;
goto v_resetjp_586_;
}
else
{
lean_inc(v_a_585_);
lean_dec(v___x_570_);
v___x_587_ = lean_box(0);
v_isShared_588_ = v_isSharedCheck_592_;
goto v_resetjp_586_;
}
v_resetjp_586_:
{
lean_object* v___x_590_; 
if (v_isShared_588_ == 0)
{
v___x_590_ = v___x_587_;
goto v_reusejp_589_;
}
else
{
lean_object* v_reuseFailAlloc_591_; 
v_reuseFailAlloc_591_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_591_, 0, v_a_585_);
v___x_590_ = v_reuseFailAlloc_591_;
goto v_reusejp_589_;
}
v_reusejp_589_:
{
return v___x_590_;
}
}
}
}
else
{
lean_object* v___x_594_; 
lean_dec(v_a_563_);
lean_del_object(v___x_560_);
lean_dec(v_snd_558_);
lean_del_object(v___x_523_);
if (v_isShared_566_ == 0)
{
lean_ctor_set(v___x_565_, 0, v___x_549_);
v___x_594_ = v___x_565_;
goto v_reusejp_593_;
}
else
{
lean_object* v_reuseFailAlloc_595_; 
v_reuseFailAlloc_595_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_595_, 0, v___x_549_);
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
else
{
lean_object* v_val_599_; lean_object* v___x_601_; 
lean_inc_ref(v_fst_557_);
lean_dec(v_a_553_);
lean_dec_ref(v_rhs_527_);
lean_del_object(v___x_523_);
v_val_599_ = lean_ctor_get(v_fst_557_, 0);
lean_inc(v_val_599_);
lean_dec_ref_known(v_fst_557_, 1);
if (v_isShared_556_ == 0)
{
lean_ctor_set(v___x_555_, 0, v_val_599_);
v___x_601_ = v___x_555_;
goto v_reusejp_600_;
}
else
{
lean_object* v_reuseFailAlloc_602_; 
v_reuseFailAlloc_602_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_602_, 0, v_val_599_);
v___x_601_ = v_reuseFailAlloc_602_;
goto v_reusejp_600_;
}
v_reusejp_600_:
{
return v___x_601_;
}
}
}
}
else
{
lean_object* v_a_604_; lean_object* v___x_606_; uint8_t v_isShared_607_; uint8_t v_isSharedCheck_611_; 
lean_dec_ref(v_rhs_527_);
lean_del_object(v___x_523_);
v_a_604_ = lean_ctor_get(v___x_552_, 0);
v_isSharedCheck_611_ = !lean_is_exclusive(v___x_552_);
if (v_isSharedCheck_611_ == 0)
{
v___x_606_ = v___x_552_;
v_isShared_607_ = v_isSharedCheck_611_;
goto v_resetjp_605_;
}
else
{
lean_inc(v_a_604_);
lean_dec(v___x_552_);
v___x_606_ = lean_box(0);
v_isShared_607_ = v_isSharedCheck_611_;
goto v_resetjp_605_;
}
v_resetjp_605_:
{
lean_object* v___x_609_; 
if (v_isShared_607_ == 0)
{
v___x_609_ = v___x_606_;
goto v_reusejp_608_;
}
else
{
lean_object* v_reuseFailAlloc_610_; 
v_reuseFailAlloc_610_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_610_, 0, v_a_604_);
v___x_609_ = v_reuseFailAlloc_610_;
goto v_reusejp_608_;
}
v_reusejp_608_:
{
return v___x_609_;
}
}
}
}
}
}
}
else
{
lean_object* v_a_614_; lean_object* v___x_616_; uint8_t v_isShared_617_; uint8_t v_isSharedCheck_621_; 
lean_del_object(v___x_533_);
lean_dec(v_snd_531_);
lean_dec_ref(v_rhs_527_);
lean_dec_ref(v_vars_525_);
lean_del_object(v___x_523_);
lean_dec(v_val_521_);
v_a_614_ = lean_ctor_get(v___x_535_, 0);
v_isSharedCheck_621_ = !lean_is_exclusive(v___x_535_);
if (v_isSharedCheck_621_ == 0)
{
v___x_616_ = v___x_535_;
v_isShared_617_ = v_isSharedCheck_621_;
goto v_resetjp_615_;
}
else
{
lean_inc(v_a_614_);
lean_dec(v___x_535_);
v___x_616_ = lean_box(0);
v_isShared_617_ = v_isSharedCheck_621_;
goto v_resetjp_615_;
}
v_resetjp_615_:
{
lean_object* v___x_619_; 
if (v_isShared_617_ == 0)
{
v___x_619_ = v___x_616_;
goto v_reusejp_618_;
}
else
{
lean_object* v_reuseFailAlloc_620_; 
v_reuseFailAlloc_620_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_620_, 0, v_a_614_);
v___x_619_ = v_reuseFailAlloc_620_;
goto v_reusejp_618_;
}
v_reusejp_618_:
{
return v___x_619_;
}
}
}
}
}
else
{
lean_object* v_a_623_; lean_object* v___x_625_; uint8_t v_isShared_626_; uint8_t v_isSharedCheck_630_; 
lean_dec_ref(v_rhs_527_);
lean_dec_ref(v_vars_525_);
lean_del_object(v___x_523_);
lean_dec(v_val_521_);
lean_dec_ref(v_e_510_);
v_a_623_ = lean_ctor_get(v___x_528_, 0);
v_isSharedCheck_630_ = !lean_is_exclusive(v___x_528_);
if (v_isSharedCheck_630_ == 0)
{
v___x_625_ = v___x_528_;
v_isShared_626_ = v_isSharedCheck_630_;
goto v_resetjp_624_;
}
else
{
lean_inc(v_a_623_);
lean_dec(v___x_528_);
v___x_625_ = lean_box(0);
v_isShared_626_ = v_isSharedCheck_630_;
goto v_resetjp_624_;
}
v_resetjp_624_:
{
lean_object* v___x_628_; 
if (v_isShared_626_ == 0)
{
v___x_628_ = v___x_625_;
goto v_reusejp_627_;
}
else
{
lean_object* v_reuseFailAlloc_629_; 
v_reuseFailAlloc_629_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_629_, 0, v_a_623_);
v___x_628_ = v_reuseFailAlloc_629_;
goto v_reusejp_627_;
}
v_reusejp_627_:
{
return v___x_628_;
}
}
}
}
}
else
{
lean_object* v___x_632_; lean_object* v___x_634_; 
lean_dec(v_a_517_);
lean_dec_ref(v_e_510_);
v___x_632_ = lean_box(0);
if (v_isShared_520_ == 0)
{
lean_ctor_set(v___x_519_, 0, v___x_632_);
v___x_634_ = v___x_519_;
goto v_reusejp_633_;
}
else
{
lean_object* v_reuseFailAlloc_635_; 
v_reuseFailAlloc_635_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_635_, 0, v___x_632_);
v___x_634_ = v_reuseFailAlloc_635_;
goto v_reusejp_633_;
}
v_reusejp_633_:
{
return v___x_634_;
}
}
}
}
else
{
lean_object* v_a_637_; lean_object* v___x_639_; uint8_t v_isShared_640_; uint8_t v_isSharedCheck_644_; 
lean_dec_ref(v_e_510_);
v_a_637_ = lean_ctor_get(v___x_516_, 0);
v_isSharedCheck_644_ = !lean_is_exclusive(v___x_516_);
if (v_isSharedCheck_644_ == 0)
{
v___x_639_ = v___x_516_;
v_isShared_640_ = v_isSharedCheck_644_;
goto v_resetjp_638_;
}
else
{
lean_inc(v_a_637_);
lean_dec(v___x_516_);
v___x_639_ = lean_box(0);
v_isShared_640_ = v_isSharedCheck_644_;
goto v_resetjp_638_;
}
v_resetjp_638_:
{
lean_object* v___x_642_; 
if (v_isShared_640_ == 0)
{
v___x_642_ = v___x_639_;
goto v_reusejp_641_;
}
else
{
lean_object* v_reuseFailAlloc_643_; 
v_reuseFailAlloc_643_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_643_, 0, v_a_637_);
v___x_642_ = v_reuseFailAlloc_643_;
goto v_reusejp_641_;
}
v_reusejp_641_:
{
return v___x_642_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_matchRule_x3f___lam__0___boxed(lean_object* v_source_645_, lean_object* v_generalize_646_, lean_object* v_e_647_, lean_object* v___y_648_, lean_object* v___y_649_, lean_object* v___y_650_, lean_object* v___y_651_, lean_object* v___y_652_){
_start:
{
lean_object* v_res_653_; 
v_res_653_ = lp_JunkValues_JunkValues_matchRule_x3f___lam__0(v_source_645_, v_generalize_646_, v_e_647_, v___y_648_, v___y_649_, v___y_650_, v___y_651_);
lean_dec(v___y_651_);
lean_dec_ref(v___y_650_);
lean_dec(v___y_649_);
lean_dec_ref(v___y_648_);
lean_dec_ref(v_generalize_646_);
return v_res_653_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_matchRule_x3f(lean_object* v_rule_654_, lean_object* v_e_655_, lean_object* v_a_656_, lean_object* v_a_657_, lean_object* v_a_658_, lean_object* v_a_659_){
_start:
{
lean_object* v_source_661_; lean_object* v_generalize_662_; lean_object* v___f_663_; uint8_t v___x_664_; lean_object* v___x_665_; lean_object* v___x_666_; lean_object* v___x_667_; 
v_source_661_ = lean_ctor_get(v_rule_654_, 0);
lean_inc(v_source_661_);
v_generalize_662_ = lean_ctor_get(v_rule_654_, 4);
lean_inc_ref(v_generalize_662_);
lean_dec_ref(v_rule_654_);
v___f_663_ = lean_alloc_closure((void*)(lp_JunkValues_JunkValues_matchRule_x3f___lam__0___boxed), 8, 3);
lean_closure_set(v___f_663_, 0, v_source_661_);
lean_closure_set(v___f_663_, 1, v_generalize_662_);
lean_closure_set(v___f_663_, 2, v_e_655_);
v___x_664_ = 0;
v___x_665_ = lean_box(v___x_664_);
v___x_666_ = lean_alloc_closure((void*)(lp_JunkValues_Lean_Meta_withNewMCtxDepth___at___00JunkValues_matchRule_x3f_spec__3___boxed), 8, 3);
lean_closure_set(v___x_666_, 0, lean_box(0));
lean_closure_set(v___x_666_, 1, v___f_663_);
lean_closure_set(v___x_666_, 2, v___x_665_);
v___x_667_ = lp_JunkValues_Lean_withoutModifyingState___at___00JunkValues_matchRule_x3f_spec__4___redArg(v___x_666_, v_a_656_, v_a_657_, v_a_658_, v_a_659_);
return v___x_667_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_matchRule_x3f___boxed(lean_object* v_rule_668_, lean_object* v_e_669_, lean_object* v_a_670_, lean_object* v_a_671_, lean_object* v_a_672_, lean_object* v_a_673_, lean_object* v_a_674_){
_start:
{
lean_object* v_res_675_; 
v_res_675_ = lp_JunkValues_JunkValues_matchRule_x3f(v_rule_668_, v_e_669_, v_a_670_, v_a_671_, v_a_672_, v_a_673_);
lean_dec(v_a_673_);
lean_dec_ref(v_a_672_);
lean_dec(v_a_671_);
lean_dec_ref(v_a_670_);
return v_res_675_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00JunkValues_matchRule_x3f_spec__1(lean_object* v___x_676_, lean_object* v_val_677_, lean_object* v_range_678_, lean_object* v_b_679_, lean_object* v_i_680_, lean_object* v_hs_681_, lean_object* v_hl_682_, lean_object* v___y_683_, lean_object* v___y_684_, lean_object* v___y_685_, lean_object* v___y_686_){
_start:
{
lean_object* v___x_688_; 
v___x_688_ = lp_JunkValues___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00JunkValues_matchRule_x3f_spec__1___redArg(v___x_676_, v_val_677_, v_range_678_, v_b_679_, v_i_680_, v___y_683_, v___y_684_, v___y_685_, v___y_686_);
return v___x_688_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00JunkValues_matchRule_x3f_spec__1___boxed(lean_object* v___x_689_, lean_object* v_val_690_, lean_object* v_range_691_, lean_object* v_b_692_, lean_object* v_i_693_, lean_object* v_hs_694_, lean_object* v_hl_695_, lean_object* v___y_696_, lean_object* v___y_697_, lean_object* v___y_698_, lean_object* v___y_699_, lean_object* v___y_700_){
_start:
{
lean_object* v_res_701_; 
v_res_701_ = lp_JunkValues___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00JunkValues_matchRule_x3f_spec__1(v___x_689_, v_val_690_, v_range_691_, v_b_692_, v_i_693_, v_hs_694_, v_hl_695_, v___y_696_, v___y_697_, v___y_698_, v___y_699_);
lean_dec(v___y_699_);
lean_dec_ref(v___y_698_);
lean_dec(v___y_697_);
lean_dec_ref(v___y_696_);
lean_dec_ref(v_range_691_);
lean_dec_ref(v_val_690_);
lean_dec_ref(v___x_689_);
return v_res_701_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00JunkValues_mkFinding_spec__0(size_t v_sz_702_, size_t v_i_703_, lean_object* v_bs_704_, lean_object* v___y_705_, lean_object* v___y_706_, lean_object* v___y_707_, lean_object* v___y_708_){
_start:
{
uint8_t v___x_710_; 
v___x_710_ = lean_usize_dec_lt(v_i_703_, v_sz_702_);
if (v___x_710_ == 0)
{
lean_object* v___x_711_; 
v___x_711_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_711_, 0, v_bs_704_);
return v___x_711_;
}
else
{
lean_object* v_v_712_; lean_object* v___x_713_; 
v_v_712_ = lean_array_uget_borrowed(v_bs_704_, v_i_703_);
lean_inc(v_v_712_);
v___x_713_ = l_Lean_Meta_ppExpr(v_v_712_, v___y_705_, v___y_706_, v___y_707_, v___y_708_);
if (lean_obj_tag(v___x_713_) == 0)
{
lean_object* v_a_714_; lean_object* v___x_715_; lean_object* v_bs_x27_716_; lean_object* v___x_717_; lean_object* v___x_718_; size_t v___x_719_; size_t v___x_720_; lean_object* v___x_721_; 
v_a_714_ = lean_ctor_get(v___x_713_, 0);
lean_inc(v_a_714_);
lean_dec_ref_known(v___x_713_, 1);
v___x_715_ = lean_unsigned_to_nat(0u);
v_bs_x27_716_ = lean_array_uset(v_bs_704_, v_i_703_, v___x_715_);
v___x_717_ = l_Std_Format_defWidth;
v___x_718_ = l_Std_Format_pretty(v_a_714_, v___x_717_, v___x_715_, v___x_715_);
v___x_719_ = ((size_t)1ULL);
v___x_720_ = lean_usize_add(v_i_703_, v___x_719_);
v___x_721_ = lean_array_uset(v_bs_x27_716_, v_i_703_, v___x_718_);
v_i_703_ = v___x_720_;
v_bs_704_ = v___x_721_;
goto _start;
}
else
{
lean_object* v_a_723_; lean_object* v___x_725_; uint8_t v_isShared_726_; uint8_t v_isSharedCheck_730_; 
lean_dec_ref(v_bs_704_);
v_a_723_ = lean_ctor_get(v___x_713_, 0);
v_isSharedCheck_730_ = !lean_is_exclusive(v___x_713_);
if (v_isSharedCheck_730_ == 0)
{
v___x_725_ = v___x_713_;
v_isShared_726_ = v_isSharedCheck_730_;
goto v_resetjp_724_;
}
else
{
lean_inc(v_a_723_);
lean_dec(v___x_713_);
v___x_725_ = lean_box(0);
v_isShared_726_ = v_isSharedCheck_730_;
goto v_resetjp_724_;
}
v_resetjp_724_:
{
lean_object* v___x_728_; 
if (v_isShared_726_ == 0)
{
v___x_728_ = v___x_725_;
goto v_reusejp_727_;
}
else
{
lean_object* v_reuseFailAlloc_729_; 
v_reuseFailAlloc_729_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_729_, 0, v_a_723_);
v___x_728_ = v_reuseFailAlloc_729_;
goto v_reusejp_727_;
}
v_reusejp_727_:
{
return v___x_728_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00JunkValues_mkFinding_spec__0___boxed(lean_object* v_sz_731_, lean_object* v_i_732_, lean_object* v_bs_733_, lean_object* v___y_734_, lean_object* v___y_735_, lean_object* v___y_736_, lean_object* v___y_737_, lean_object* v___y_738_){
_start:
{
size_t v_sz_boxed_739_; size_t v_i_boxed_740_; lean_object* v_res_741_; 
v_sz_boxed_739_ = lean_unbox_usize(v_sz_731_);
lean_dec(v_sz_731_);
v_i_boxed_740_ = lean_unbox_usize(v_i_732_);
lean_dec(v_i_732_);
v_res_741_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00JunkValues_mkFinding_spec__0(v_sz_boxed_739_, v_i_boxed_740_, v_bs_733_, v___y_734_, v___y_735_, v___y_736_, v___y_737_);
lean_dec(v___y_737_);
lean_dec_ref(v___y_736_);
lean_dec(v___y_735_);
lean_dec_ref(v___y_734_);
return v_res_741_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_mkFinding(lean_object* v_decl_742_, uint8_t v_site_743_, lean_object* v_rule_744_, lean_object* v_term_745_, lean_object* v_guards_746_, lean_object* v_value_747_, lean_object* v_status_748_, lean_object* v_a_749_, lean_object* v_a_750_, lean_object* v_a_751_, lean_object* v_a_752_){
_start:
{
lean_object* v___x_754_; 
v___x_754_ = l_Lean_Meta_ppExpr(v_term_745_, v_a_749_, v_a_750_, v_a_751_, v_a_752_);
if (lean_obj_tag(v___x_754_) == 0)
{
lean_object* v_a_755_; size_t v_sz_756_; size_t v___x_757_; lean_object* v___x_758_; 
v_a_755_ = lean_ctor_get(v___x_754_, 0);
lean_inc(v_a_755_);
lean_dec_ref_known(v___x_754_, 1);
v_sz_756_ = lean_array_size(v_guards_746_);
v___x_757_ = ((size_t)0ULL);
v___x_758_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00JunkValues_mkFinding_spec__0(v_sz_756_, v___x_757_, v_guards_746_, v_a_749_, v_a_750_, v_a_751_, v_a_752_);
if (lean_obj_tag(v___x_758_) == 0)
{
lean_object* v_a_759_; lean_object* v___x_760_; 
v_a_759_ = lean_ctor_get(v___x_758_, 0);
lean_inc(v_a_759_);
lean_dec_ref_known(v___x_758_, 1);
v___x_760_ = l_Lean_Meta_ppExpr(v_value_747_, v_a_749_, v_a_750_, v_a_751_, v_a_752_);
if (lean_obj_tag(v___x_760_) == 0)
{
lean_object* v_a_761_; lean_object* v___x_763_; uint8_t v_isShared_764_; uint8_t v_isSharedCheck_776_; 
v_a_761_ = lean_ctor_get(v___x_760_, 0);
v_isSharedCheck_776_ = !lean_is_exclusive(v___x_760_);
if (v_isSharedCheck_776_ == 0)
{
v___x_763_ = v___x_760_;
v_isShared_764_ = v_isSharedCheck_776_;
goto v_resetjp_762_;
}
else
{
lean_inc(v_a_761_);
lean_dec(v___x_760_);
v___x_763_ = lean_box(0);
v_isShared_764_ = v_isSharedCheck_776_;
goto v_resetjp_762_;
}
v_resetjp_762_:
{
lean_object* v_source_765_; lean_object* v_head_766_; lean_object* v_note_767_; lean_object* v___x_768_; lean_object* v___x_769_; lean_object* v___x_770_; lean_object* v___x_771_; lean_object* v___x_772_; lean_object* v___x_774_; 
v_source_765_ = lean_ctor_get(v_rule_744_, 0);
v_head_766_ = lean_ctor_get(v_rule_744_, 1);
v_note_767_ = lean_ctor_get(v_rule_744_, 5);
v___x_768_ = l_Std_Format_defWidth;
v___x_769_ = lean_unsigned_to_nat(0u);
v___x_770_ = l_Std_Format_pretty(v_a_755_, v___x_768_, v___x_769_, v___x_769_);
v___x_771_ = l_Std_Format_pretty(v_a_761_, v___x_768_, v___x_769_, v___x_769_);
lean_inc_ref(v_note_767_);
lean_inc(v_head_766_);
lean_inc(v_source_765_);
v___x_772_ = lean_alloc_ctor(0, 8, 1);
lean_ctor_set(v___x_772_, 0, v_decl_742_);
lean_ctor_set(v___x_772_, 1, v_source_765_);
lean_ctor_set(v___x_772_, 2, v_head_766_);
lean_ctor_set(v___x_772_, 3, v___x_770_);
lean_ctor_set(v___x_772_, 4, v_a_759_);
lean_ctor_set(v___x_772_, 5, v___x_771_);
lean_ctor_set(v___x_772_, 6, v_status_748_);
lean_ctor_set(v___x_772_, 7, v_note_767_);
lean_ctor_set_uint8(v___x_772_, sizeof(void*)*8, v_site_743_);
if (v_isShared_764_ == 0)
{
lean_ctor_set(v___x_763_, 0, v___x_772_);
v___x_774_ = v___x_763_;
goto v_reusejp_773_;
}
else
{
lean_object* v_reuseFailAlloc_775_; 
v_reuseFailAlloc_775_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_775_, 0, v___x_772_);
v___x_774_ = v_reuseFailAlloc_775_;
goto v_reusejp_773_;
}
v_reusejp_773_:
{
return v___x_774_;
}
}
}
else
{
lean_object* v_a_777_; lean_object* v___x_779_; uint8_t v_isShared_780_; uint8_t v_isSharedCheck_784_; 
lean_dec(v_a_759_);
lean_dec(v_a_755_);
lean_dec(v_status_748_);
lean_dec(v_decl_742_);
v_a_777_ = lean_ctor_get(v___x_760_, 0);
v_isSharedCheck_784_ = !lean_is_exclusive(v___x_760_);
if (v_isSharedCheck_784_ == 0)
{
v___x_779_ = v___x_760_;
v_isShared_780_ = v_isSharedCheck_784_;
goto v_resetjp_778_;
}
else
{
lean_inc(v_a_777_);
lean_dec(v___x_760_);
v___x_779_ = lean_box(0);
v_isShared_780_ = v_isSharedCheck_784_;
goto v_resetjp_778_;
}
v_resetjp_778_:
{
lean_object* v___x_782_; 
if (v_isShared_780_ == 0)
{
v___x_782_ = v___x_779_;
goto v_reusejp_781_;
}
else
{
lean_object* v_reuseFailAlloc_783_; 
v_reuseFailAlloc_783_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_783_, 0, v_a_777_);
v___x_782_ = v_reuseFailAlloc_783_;
goto v_reusejp_781_;
}
v_reusejp_781_:
{
return v___x_782_;
}
}
}
}
else
{
lean_object* v_a_785_; lean_object* v___x_787_; uint8_t v_isShared_788_; uint8_t v_isSharedCheck_792_; 
lean_dec(v_a_755_);
lean_dec(v_status_748_);
lean_dec_ref(v_value_747_);
lean_dec(v_decl_742_);
v_a_785_ = lean_ctor_get(v___x_758_, 0);
v_isSharedCheck_792_ = !lean_is_exclusive(v___x_758_);
if (v_isSharedCheck_792_ == 0)
{
v___x_787_ = v___x_758_;
v_isShared_788_ = v_isSharedCheck_792_;
goto v_resetjp_786_;
}
else
{
lean_inc(v_a_785_);
lean_dec(v___x_758_);
v___x_787_ = lean_box(0);
v_isShared_788_ = v_isSharedCheck_792_;
goto v_resetjp_786_;
}
v_resetjp_786_:
{
lean_object* v___x_790_; 
if (v_isShared_788_ == 0)
{
v___x_790_ = v___x_787_;
goto v_reusejp_789_;
}
else
{
lean_object* v_reuseFailAlloc_791_; 
v_reuseFailAlloc_791_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_791_, 0, v_a_785_);
v___x_790_ = v_reuseFailAlloc_791_;
goto v_reusejp_789_;
}
v_reusejp_789_:
{
return v___x_790_;
}
}
}
}
else
{
lean_object* v_a_793_; lean_object* v___x_795_; uint8_t v_isShared_796_; uint8_t v_isSharedCheck_800_; 
lean_dec(v_status_748_);
lean_dec_ref(v_value_747_);
lean_dec_ref(v_guards_746_);
lean_dec(v_decl_742_);
v_a_793_ = lean_ctor_get(v___x_754_, 0);
v_isSharedCheck_800_ = !lean_is_exclusive(v___x_754_);
if (v_isSharedCheck_800_ == 0)
{
v___x_795_ = v___x_754_;
v_isShared_796_ = v_isSharedCheck_800_;
goto v_resetjp_794_;
}
else
{
lean_inc(v_a_793_);
lean_dec(v___x_754_);
v___x_795_ = lean_box(0);
v_isShared_796_ = v_isSharedCheck_800_;
goto v_resetjp_794_;
}
v_resetjp_794_:
{
lean_object* v___x_798_; 
if (v_isShared_796_ == 0)
{
v___x_798_ = v___x_795_;
goto v_reusejp_797_;
}
else
{
lean_object* v_reuseFailAlloc_799_; 
v_reuseFailAlloc_799_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_799_, 0, v_a_793_);
v___x_798_ = v_reuseFailAlloc_799_;
goto v_reusejp_797_;
}
v_reusejp_797_:
{
return v___x_798_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_mkFinding___boxed(lean_object* v_decl_801_, lean_object* v_site_802_, lean_object* v_rule_803_, lean_object* v_term_804_, lean_object* v_guards_805_, lean_object* v_value_806_, lean_object* v_status_807_, lean_object* v_a_808_, lean_object* v_a_809_, lean_object* v_a_810_, lean_object* v_a_811_, lean_object* v_a_812_){
_start:
{
uint8_t v_site_boxed_813_; lean_object* v_res_814_; 
v_site_boxed_813_ = lean_unbox(v_site_802_);
v_res_814_ = lp_JunkValues_JunkValues_mkFinding(v_decl_801_, v_site_boxed_813_, v_rule_803_, v_term_804_, v_guards_805_, v_value_806_, v_status_807_, v_a_808_, v_a_809_, v_a_810_, v_a_811_);
lean_dec(v_a_811_);
lean_dec_ref(v_a_810_);
lean_dec(v_a_809_);
lean_dec_ref(v_a_808_);
lean_dec_ref(v_rule_803_);
return v_res_814_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_matchAt_spec__0(lean_object* v_numArgs_815_, lean_object* v___x_816_, lean_object* v_e_817_, lean_object* v_cfg_818_, lean_object* v_decl_819_, uint8_t v_site_820_, lean_object* v_as_821_, size_t v_sz_822_, size_t v_i_823_, lean_object* v_b_824_, lean_object* v___y_825_, lean_object* v___y_826_, lean_object* v___y_827_, lean_object* v___y_828_){
_start:
{
lean_object* v_a_831_; uint8_t v___x_835_; 
v___x_835_ = lean_usize_dec_lt(v_i_823_, v_sz_822_);
if (v___x_835_ == 0)
{
lean_object* v___x_836_; 
lean_dec(v_decl_819_);
lean_dec_ref(v_cfg_818_);
lean_dec_ref(v_e_817_);
v___x_836_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_836_, 0, v_b_824_);
return v___x_836_;
}
else
{
lean_object* v_a_837_; lean_object* v_arity_838_; uint8_t v___x_839_; 
v_a_837_ = lean_array_uget_borrowed(v_as_821_, v_i_823_);
v_arity_838_ = lean_ctor_get(v_a_837_, 2);
v___x_839_ = lean_nat_dec_eq(v_arity_838_, v_numArgs_815_);
if (v___x_839_ == 0)
{
v_a_831_ = v_b_824_;
goto v___jp_830_;
}
else
{
lean_object* v___x_840_; uint8_t v___x_841_; 
v___x_840_ = lean_unsigned_to_nat(0u);
v___x_841_ = lean_nat_dec_eq(v___x_816_, v___x_840_);
if (v___x_841_ == 0)
{
lean_object* v___x_842_; 
lean_inc_ref(v_e_817_);
lean_inc(v_a_837_);
v___x_842_ = lp_JunkValues_JunkValues_matchRule_x3f(v_a_837_, v_e_817_, v___y_825_, v___y_826_, v___y_827_, v___y_828_);
if (lean_obj_tag(v___x_842_) == 0)
{
lean_object* v_a_843_; 
v_a_843_ = lean_ctor_get(v___x_842_, 0);
lean_inc(v_a_843_);
lean_dec_ref_known(v___x_842_, 1);
if (lean_obj_tag(v_a_843_) == 1)
{
lean_object* v_val_844_; lean_object* v_fst_845_; lean_object* v_snd_846_; lean_object* v_guard_847_; uint8_t v_includeGuarded_848_; lean_object* v___x_849_; 
v_val_844_ = lean_ctor_get(v_a_843_, 0);
lean_inc(v_val_844_);
lean_dec_ref_known(v_a_843_, 1);
v_fst_845_ = lean_ctor_get(v_val_844_, 0);
lean_inc(v_fst_845_);
v_snd_846_ = lean_ctor_get(v_val_844_, 1);
lean_inc(v_snd_846_);
lean_dec(v_val_844_);
v_guard_847_ = lean_ctor_get(v_cfg_818_, 0);
v_includeGuarded_848_ = lean_ctor_get_uint8(v_cfg_818_, sizeof(void*)*2);
lean_inc_ref(v_guard_847_);
v___x_849_ = lp_JunkValues_JunkValues_classify(v_fst_845_, v_guard_847_, v___y_825_, v___y_826_, v___y_827_, v___y_828_);
if (lean_obj_tag(v___x_849_) == 0)
{
lean_object* v_a_850_; 
v_a_850_ = lean_ctor_get(v___x_849_, 0);
lean_inc(v_a_850_);
lean_dec_ref_known(v___x_849_, 1);
if (v_includeGuarded_848_ == 0)
{
uint8_t v___x_863_; 
v___x_863_ = lp_JunkValues_JunkValues_Status_isFinding(v_a_850_);
if (v___x_863_ == 0)
{
lean_dec(v_a_850_);
lean_dec(v_snd_846_);
lean_dec(v_fst_845_);
v_a_831_ = v_b_824_;
goto v___jp_830_;
}
else
{
goto v___jp_851_;
}
}
else
{
goto v___jp_851_;
}
v___jp_851_:
{
lean_object* v___x_852_; 
lean_inc_ref(v_e_817_);
lean_inc(v_decl_819_);
v___x_852_ = lp_JunkValues_JunkValues_mkFinding(v_decl_819_, v_site_820_, v_a_837_, v_e_817_, v_fst_845_, v_snd_846_, v_a_850_, v___y_825_, v___y_826_, v___y_827_, v___y_828_);
if (lean_obj_tag(v___x_852_) == 0)
{
lean_object* v_a_853_; lean_object* v___x_854_; 
v_a_853_ = lean_ctor_get(v___x_852_, 0);
lean_inc(v_a_853_);
lean_dec_ref_known(v___x_852_, 1);
v___x_854_ = lean_array_push(v_b_824_, v_a_853_);
v_a_831_ = v___x_854_;
goto v___jp_830_;
}
else
{
lean_object* v_a_855_; lean_object* v___x_857_; uint8_t v_isShared_858_; uint8_t v_isSharedCheck_862_; 
lean_dec_ref(v_b_824_);
lean_dec(v_decl_819_);
lean_dec_ref(v_cfg_818_);
lean_dec_ref(v_e_817_);
v_a_855_ = lean_ctor_get(v___x_852_, 0);
v_isSharedCheck_862_ = !lean_is_exclusive(v___x_852_);
if (v_isSharedCheck_862_ == 0)
{
v___x_857_ = v___x_852_;
v_isShared_858_ = v_isSharedCheck_862_;
goto v_resetjp_856_;
}
else
{
lean_inc(v_a_855_);
lean_dec(v___x_852_);
v___x_857_ = lean_box(0);
v_isShared_858_ = v_isSharedCheck_862_;
goto v_resetjp_856_;
}
v_resetjp_856_:
{
lean_object* v___x_860_; 
if (v_isShared_858_ == 0)
{
v___x_860_ = v___x_857_;
goto v_reusejp_859_;
}
else
{
lean_object* v_reuseFailAlloc_861_; 
v_reuseFailAlloc_861_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_861_, 0, v_a_855_);
v___x_860_ = v_reuseFailAlloc_861_;
goto v_reusejp_859_;
}
v_reusejp_859_:
{
return v___x_860_;
}
}
}
}
}
else
{
lean_object* v_a_864_; lean_object* v___x_866_; uint8_t v_isShared_867_; uint8_t v_isSharedCheck_871_; 
lean_dec(v_snd_846_);
lean_dec(v_fst_845_);
lean_dec_ref(v_b_824_);
lean_dec(v_decl_819_);
lean_dec_ref(v_cfg_818_);
lean_dec_ref(v_e_817_);
v_a_864_ = lean_ctor_get(v___x_849_, 0);
v_isSharedCheck_871_ = !lean_is_exclusive(v___x_849_);
if (v_isSharedCheck_871_ == 0)
{
v___x_866_ = v___x_849_;
v_isShared_867_ = v_isSharedCheck_871_;
goto v_resetjp_865_;
}
else
{
lean_inc(v_a_864_);
lean_dec(v___x_849_);
v___x_866_ = lean_box(0);
v_isShared_867_ = v_isSharedCheck_871_;
goto v_resetjp_865_;
}
v_resetjp_865_:
{
lean_object* v___x_869_; 
if (v_isShared_867_ == 0)
{
v___x_869_ = v___x_866_;
goto v_reusejp_868_;
}
else
{
lean_object* v_reuseFailAlloc_870_; 
v_reuseFailAlloc_870_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_870_, 0, v_a_864_);
v___x_869_ = v_reuseFailAlloc_870_;
goto v_reusejp_868_;
}
v_reusejp_868_:
{
return v___x_869_;
}
}
}
}
else
{
lean_dec(v_a_843_);
v_a_831_ = v_b_824_;
goto v___jp_830_;
}
}
else
{
lean_object* v_a_872_; lean_object* v___x_874_; uint8_t v_isShared_875_; uint8_t v_isSharedCheck_879_; 
lean_dec_ref(v_b_824_);
lean_dec(v_decl_819_);
lean_dec_ref(v_cfg_818_);
lean_dec_ref(v_e_817_);
v_a_872_ = lean_ctor_get(v___x_842_, 0);
v_isSharedCheck_879_ = !lean_is_exclusive(v___x_842_);
if (v_isSharedCheck_879_ == 0)
{
v___x_874_ = v___x_842_;
v_isShared_875_ = v_isSharedCheck_879_;
goto v_resetjp_873_;
}
else
{
lean_inc(v_a_872_);
lean_dec(v___x_842_);
v___x_874_ = lean_box(0);
v_isShared_875_ = v_isSharedCheck_879_;
goto v_resetjp_873_;
}
v_resetjp_873_:
{
lean_object* v___x_877_; 
if (v_isShared_875_ == 0)
{
v___x_877_ = v___x_874_;
goto v_reusejp_876_;
}
else
{
lean_object* v_reuseFailAlloc_878_; 
v_reuseFailAlloc_878_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_878_, 0, v_a_872_);
v___x_877_ = v_reuseFailAlloc_878_;
goto v_reusejp_876_;
}
v_reusejp_876_:
{
return v___x_877_;
}
}
}
}
else
{
v_a_831_ = v_b_824_;
goto v___jp_830_;
}
}
}
v___jp_830_:
{
size_t v___x_832_; size_t v___x_833_; 
v___x_832_ = ((size_t)1ULL);
v___x_833_ = lean_usize_add(v_i_823_, v___x_832_);
v_i_823_ = v___x_833_;
v_b_824_ = v_a_831_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_matchAt_spec__0___boxed(lean_object* v_numArgs_880_, lean_object* v___x_881_, lean_object* v_e_882_, lean_object* v_cfg_883_, lean_object* v_decl_884_, lean_object* v_site_885_, lean_object* v_as_886_, lean_object* v_sz_887_, lean_object* v_i_888_, lean_object* v_b_889_, lean_object* v___y_890_, lean_object* v___y_891_, lean_object* v___y_892_, lean_object* v___y_893_, lean_object* v___y_894_){
_start:
{
uint8_t v_site_boxed_895_; size_t v_sz_boxed_896_; size_t v_i_boxed_897_; lean_object* v_res_898_; 
v_site_boxed_895_ = lean_unbox(v_site_885_);
v_sz_boxed_896_ = lean_unbox_usize(v_sz_887_);
lean_dec(v_sz_887_);
v_i_boxed_897_ = lean_unbox_usize(v_i_888_);
lean_dec(v_i_888_);
v_res_898_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_matchAt_spec__0(v_numArgs_880_, v___x_881_, v_e_882_, v_cfg_883_, v_decl_884_, v_site_boxed_895_, v_as_886_, v_sz_boxed_896_, v_i_boxed_897_, v_b_889_, v___y_890_, v___y_891_, v___y_892_, v___y_893_);
lean_dec(v___y_893_);
lean_dec_ref(v___y_892_);
lean_dec(v___y_891_);
lean_dec_ref(v___y_890_);
lean_dec_ref(v_as_886_);
lean_dec(v___x_881_);
lean_dec(v_numArgs_880_);
return v_res_898_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_matchAt(lean_object* v_rs_899_, lean_object* v_cfg_900_, lean_object* v_decl_901_, uint8_t v_site_902_, lean_object* v_e_903_, lean_object* v_a_904_, lean_object* v_a_905_, lean_object* v_a_906_, lean_object* v_a_907_){
_start:
{
lean_object* v___x_909_; 
v___x_909_ = lp_JunkValues_JunkValues_headConst_x3f(v_e_903_);
if (lean_obj_tag(v___x_909_) == 1)
{
lean_object* v_val_910_; lean_object* v___x_912_; uint8_t v_isShared_913_; uint8_t v_isSharedCheck_927_; 
v_val_910_ = lean_ctor_get(v___x_909_, 0);
v_isSharedCheck_927_ = !lean_is_exclusive(v___x_909_);
if (v_isSharedCheck_927_ == 0)
{
v___x_912_ = v___x_909_;
v_isShared_913_ = v_isSharedCheck_927_;
goto v_resetjp_911_;
}
else
{
lean_inc(v_val_910_);
lean_dec(v___x_909_);
v___x_912_ = lean_box(0);
v_isShared_913_ = v_isSharedCheck_927_;
goto v_resetjp_911_;
}
v_resetjp_911_:
{
lean_object* v_candidates_914_; lean_object* v___x_915_; lean_object* v___x_916_; uint8_t v___x_917_; 
v_candidates_914_ = lp_JunkValues_JunkValues_RuleSet_forHead(v_rs_899_, v_val_910_);
lean_dec(v_val_910_);
v___x_915_ = lean_array_get_size(v_candidates_914_);
v___x_916_ = lean_unsigned_to_nat(0u);
v___x_917_ = lean_nat_dec_eq(v___x_915_, v___x_916_);
if (v___x_917_ == 0)
{
lean_object* v_numArgs_918_; lean_object* v_out_919_; size_t v_sz_920_; size_t v___x_921_; lean_object* v___x_922_; 
lean_del_object(v___x_912_);
v_numArgs_918_ = l_Lean_Expr_getAppNumArgs(v_e_903_);
v_out_919_ = ((lean_object*)(lp_JunkValues_JunkValues_instInhabitedDeclScan_default___closed__0));
v_sz_920_ = lean_array_size(v_candidates_914_);
v___x_921_ = ((size_t)0ULL);
v___x_922_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_matchAt_spec__0(v_numArgs_918_, v___x_915_, v_e_903_, v_cfg_900_, v_decl_901_, v_site_902_, v_candidates_914_, v_sz_920_, v___x_921_, v_out_919_, v_a_904_, v_a_905_, v_a_906_, v_a_907_);
lean_dec_ref(v_candidates_914_);
lean_dec(v_numArgs_918_);
return v___x_922_;
}
else
{
lean_object* v___x_923_; lean_object* v___x_925_; 
lean_dec_ref(v_candidates_914_);
lean_dec_ref(v_e_903_);
lean_dec(v_decl_901_);
lean_dec_ref(v_cfg_900_);
v___x_923_ = ((lean_object*)(lp_JunkValues_JunkValues_instInhabitedDeclScan_default___closed__0));
if (v_isShared_913_ == 0)
{
lean_ctor_set_tag(v___x_912_, 0);
lean_ctor_set(v___x_912_, 0, v___x_923_);
v___x_925_ = v___x_912_;
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
}
else
{
lean_object* v___x_928_; lean_object* v___x_929_; 
lean_dec(v___x_909_);
lean_dec_ref(v_e_903_);
lean_dec(v_decl_901_);
lean_dec_ref(v_cfg_900_);
v___x_928_ = ((lean_object*)(lp_JunkValues_JunkValues_instInhabitedDeclScan_default___closed__0));
v___x_929_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_929_, 0, v___x_928_);
return v___x_929_;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_matchAt___boxed(lean_object* v_rs_930_, lean_object* v_cfg_931_, lean_object* v_decl_932_, lean_object* v_site_933_, lean_object* v_e_934_, lean_object* v_a_935_, lean_object* v_a_936_, lean_object* v_a_937_, lean_object* v_a_938_, lean_object* v_a_939_){
_start:
{
uint8_t v_site_boxed_940_; lean_object* v_res_941_; 
v_site_boxed_940_ = lean_unbox(v_site_933_);
v_res_941_ = lp_JunkValues_JunkValues_matchAt(v_rs_930_, v_cfg_931_, v_decl_932_, v_site_boxed_940_, v_e_934_, v_a_935_, v_a_936_, v_a_937_, v_a_938_);
lean_dec(v_a_938_);
lean_dec_ref(v_a_937_);
lean_dec(v_a_936_);
lean_dec_ref(v_a_935_);
lean_dec_ref(v_rs_930_);
return v_res_941_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Meta_withLocalDecl___at___00JunkValues_visit_spec__0___redArg___lam__0(lean_object* v_k_942_, lean_object* v_b_943_, lean_object* v___y_944_, lean_object* v___y_945_, lean_object* v___y_946_, lean_object* v___y_947_){
_start:
{
lean_object* v___x_949_; 
lean_inc(v___y_947_);
lean_inc_ref(v___y_946_);
lean_inc(v___y_945_);
lean_inc_ref(v___y_944_);
v___x_949_ = lean_apply_6(v_k_942_, v_b_943_, v___y_944_, v___y_945_, v___y_946_, v___y_947_, lean_box(0));
return v___x_949_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Meta_withLocalDecl___at___00JunkValues_visit_spec__0___redArg___lam__0___boxed(lean_object* v_k_950_, lean_object* v_b_951_, lean_object* v___y_952_, lean_object* v___y_953_, lean_object* v___y_954_, lean_object* v___y_955_, lean_object* v___y_956_){
_start:
{
lean_object* v_res_957_; 
v_res_957_ = lp_JunkValues_Lean_Meta_withLocalDecl___at___00JunkValues_visit_spec__0___redArg___lam__0(v_k_950_, v_b_951_, v___y_952_, v___y_953_, v___y_954_, v___y_955_);
lean_dec(v___y_955_);
lean_dec_ref(v___y_954_);
lean_dec(v___y_953_);
lean_dec_ref(v___y_952_);
return v_res_957_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Meta_withLocalDecl___at___00JunkValues_visit_spec__0___redArg(lean_object* v_name_958_, uint8_t v_bi_959_, lean_object* v_type_960_, lean_object* v_k_961_, uint8_t v_kind_962_, lean_object* v___y_963_, lean_object* v___y_964_, lean_object* v___y_965_, lean_object* v___y_966_){
_start:
{
lean_object* v___f_968_; lean_object* v___x_969_; 
v___f_968_ = lean_alloc_closure((void*)(lp_JunkValues_Lean_Meta_withLocalDecl___at___00JunkValues_visit_spec__0___redArg___lam__0___boxed), 7, 1);
lean_closure_set(v___f_968_, 0, v_k_961_);
v___x_969_ = l___private_Lean_Meta_Basic_0__Lean_Meta_withLocalDeclImp(lean_box(0), v_name_958_, v_bi_959_, v_type_960_, v___f_968_, v_kind_962_, v___y_963_, v___y_964_, v___y_965_, v___y_966_);
if (lean_obj_tag(v___x_969_) == 0)
{
lean_object* v_a_970_; lean_object* v___x_972_; uint8_t v_isShared_973_; uint8_t v_isSharedCheck_977_; 
v_a_970_ = lean_ctor_get(v___x_969_, 0);
v_isSharedCheck_977_ = !lean_is_exclusive(v___x_969_);
if (v_isSharedCheck_977_ == 0)
{
v___x_972_ = v___x_969_;
v_isShared_973_ = v_isSharedCheck_977_;
goto v_resetjp_971_;
}
else
{
lean_inc(v_a_970_);
lean_dec(v___x_969_);
v___x_972_ = lean_box(0);
v_isShared_973_ = v_isSharedCheck_977_;
goto v_resetjp_971_;
}
v_resetjp_971_:
{
lean_object* v___x_975_; 
if (v_isShared_973_ == 0)
{
v___x_975_ = v___x_972_;
goto v_reusejp_974_;
}
else
{
lean_object* v_reuseFailAlloc_976_; 
v_reuseFailAlloc_976_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_976_, 0, v_a_970_);
v___x_975_ = v_reuseFailAlloc_976_;
goto v_reusejp_974_;
}
v_reusejp_974_:
{
return v___x_975_;
}
}
}
else
{
lean_object* v_a_978_; lean_object* v___x_980_; uint8_t v_isShared_981_; uint8_t v_isSharedCheck_985_; 
v_a_978_ = lean_ctor_get(v___x_969_, 0);
v_isSharedCheck_985_ = !lean_is_exclusive(v___x_969_);
if (v_isSharedCheck_985_ == 0)
{
v___x_980_ = v___x_969_;
v_isShared_981_ = v_isSharedCheck_985_;
goto v_resetjp_979_;
}
else
{
lean_inc(v_a_978_);
lean_dec(v___x_969_);
v___x_980_ = lean_box(0);
v_isShared_981_ = v_isSharedCheck_985_;
goto v_resetjp_979_;
}
v_resetjp_979_:
{
lean_object* v___x_983_; 
if (v_isShared_981_ == 0)
{
v___x_983_ = v___x_980_;
goto v_reusejp_982_;
}
else
{
lean_object* v_reuseFailAlloc_984_; 
v_reuseFailAlloc_984_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_984_, 0, v_a_978_);
v___x_983_ = v_reuseFailAlloc_984_;
goto v_reusejp_982_;
}
v_reusejp_982_:
{
return v___x_983_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Meta_withLocalDecl___at___00JunkValues_visit_spec__0___redArg___boxed(lean_object* v_name_986_, lean_object* v_bi_987_, lean_object* v_type_988_, lean_object* v_k_989_, lean_object* v_kind_990_, lean_object* v___y_991_, lean_object* v___y_992_, lean_object* v___y_993_, lean_object* v___y_994_, lean_object* v___y_995_){
_start:
{
uint8_t v_bi_boxed_996_; uint8_t v_kind_boxed_997_; lean_object* v_res_998_; 
v_bi_boxed_996_ = lean_unbox(v_bi_987_);
v_kind_boxed_997_ = lean_unbox(v_kind_990_);
v_res_998_ = lp_JunkValues_Lean_Meta_withLocalDecl___at___00JunkValues_visit_spec__0___redArg(v_name_986_, v_bi_boxed_996_, v_type_988_, v_k_989_, v_kind_boxed_997_, v___y_991_, v___y_992_, v___y_993_, v___y_994_);
lean_dec(v___y_994_);
lean_dec_ref(v___y_993_);
lean_dec(v___y_992_);
lean_dec_ref(v___y_991_);
return v_res_998_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Meta_withLocalDecl___at___00JunkValues_visit_spec__0(lean_object* v_00_u03b1_999_, lean_object* v_name_1000_, uint8_t v_bi_1001_, lean_object* v_type_1002_, lean_object* v_k_1003_, uint8_t v_kind_1004_, lean_object* v___y_1005_, lean_object* v___y_1006_, lean_object* v___y_1007_, lean_object* v___y_1008_){
_start:
{
lean_object* v___x_1010_; 
v___x_1010_ = lp_JunkValues_Lean_Meta_withLocalDecl___at___00JunkValues_visit_spec__0___redArg(v_name_1000_, v_bi_1001_, v_type_1002_, v_k_1003_, v_kind_1004_, v___y_1005_, v___y_1006_, v___y_1007_, v___y_1008_);
return v___x_1010_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Meta_withLocalDecl___at___00JunkValues_visit_spec__0___boxed(lean_object* v_00_u03b1_1011_, lean_object* v_name_1012_, lean_object* v_bi_1013_, lean_object* v_type_1014_, lean_object* v_k_1015_, lean_object* v_kind_1016_, lean_object* v___y_1017_, lean_object* v___y_1018_, lean_object* v___y_1019_, lean_object* v___y_1020_, lean_object* v___y_1021_){
_start:
{
uint8_t v_bi_boxed_1022_; uint8_t v_kind_boxed_1023_; lean_object* v_res_1024_; 
v_bi_boxed_1022_ = lean_unbox(v_bi_1013_);
v_kind_boxed_1023_ = lean_unbox(v_kind_1016_);
v_res_1024_ = lp_JunkValues_Lean_Meta_withLocalDecl___at___00JunkValues_visit_spec__0(v_00_u03b1_1011_, v_name_1012_, v_bi_boxed_1022_, v_type_1014_, v_k_1015_, v_kind_boxed_1023_, v___y_1017_, v___y_1018_, v___y_1019_, v___y_1020_);
lean_dec(v___y_1020_);
lean_dec_ref(v___y_1019_);
lean_dec(v___y_1018_);
lean_dec_ref(v___y_1017_);
return v_res_1024_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Meta_withLetDecl___at___00JunkValues_visit_spec__1___redArg(lean_object* v_name_1025_, lean_object* v_type_1026_, lean_object* v_val_1027_, lean_object* v_k_1028_, uint8_t v_nondep_1029_, uint8_t v_kind_1030_, lean_object* v___y_1031_, lean_object* v___y_1032_, lean_object* v___y_1033_, lean_object* v___y_1034_){
_start:
{
lean_object* v___f_1036_; lean_object* v___x_1037_; 
v___f_1036_ = lean_alloc_closure((void*)(lp_JunkValues_Lean_Meta_withLocalDecl___at___00JunkValues_visit_spec__0___redArg___lam__0___boxed), 7, 1);
lean_closure_set(v___f_1036_, 0, v_k_1028_);
v___x_1037_ = l___private_Lean_Meta_Basic_0__Lean_Meta_withLetDeclImp(lean_box(0), v_name_1025_, v_type_1026_, v_val_1027_, v___f_1036_, v_nondep_1029_, v_kind_1030_, v___y_1031_, v___y_1032_, v___y_1033_, v___y_1034_);
if (lean_obj_tag(v___x_1037_) == 0)
{
lean_object* v_a_1038_; lean_object* v___x_1040_; uint8_t v_isShared_1041_; uint8_t v_isSharedCheck_1045_; 
v_a_1038_ = lean_ctor_get(v___x_1037_, 0);
v_isSharedCheck_1045_ = !lean_is_exclusive(v___x_1037_);
if (v_isSharedCheck_1045_ == 0)
{
v___x_1040_ = v___x_1037_;
v_isShared_1041_ = v_isSharedCheck_1045_;
goto v_resetjp_1039_;
}
else
{
lean_inc(v_a_1038_);
lean_dec(v___x_1037_);
v___x_1040_ = lean_box(0);
v_isShared_1041_ = v_isSharedCheck_1045_;
goto v_resetjp_1039_;
}
v_resetjp_1039_:
{
lean_object* v___x_1043_; 
if (v_isShared_1041_ == 0)
{
v___x_1043_ = v___x_1040_;
goto v_reusejp_1042_;
}
else
{
lean_object* v_reuseFailAlloc_1044_; 
v_reuseFailAlloc_1044_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1044_, 0, v_a_1038_);
v___x_1043_ = v_reuseFailAlloc_1044_;
goto v_reusejp_1042_;
}
v_reusejp_1042_:
{
return v___x_1043_;
}
}
}
else
{
lean_object* v_a_1046_; lean_object* v___x_1048_; uint8_t v_isShared_1049_; uint8_t v_isSharedCheck_1053_; 
v_a_1046_ = lean_ctor_get(v___x_1037_, 0);
v_isSharedCheck_1053_ = !lean_is_exclusive(v___x_1037_);
if (v_isSharedCheck_1053_ == 0)
{
v___x_1048_ = v___x_1037_;
v_isShared_1049_ = v_isSharedCheck_1053_;
goto v_resetjp_1047_;
}
else
{
lean_inc(v_a_1046_);
lean_dec(v___x_1037_);
v___x_1048_ = lean_box(0);
v_isShared_1049_ = v_isSharedCheck_1053_;
goto v_resetjp_1047_;
}
v_resetjp_1047_:
{
lean_object* v___x_1051_; 
if (v_isShared_1049_ == 0)
{
v___x_1051_ = v___x_1048_;
goto v_reusejp_1050_;
}
else
{
lean_object* v_reuseFailAlloc_1052_; 
v_reuseFailAlloc_1052_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1052_, 0, v_a_1046_);
v___x_1051_ = v_reuseFailAlloc_1052_;
goto v_reusejp_1050_;
}
v_reusejp_1050_:
{
return v___x_1051_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Meta_withLetDecl___at___00JunkValues_visit_spec__1___redArg___boxed(lean_object* v_name_1054_, lean_object* v_type_1055_, lean_object* v_val_1056_, lean_object* v_k_1057_, lean_object* v_nondep_1058_, lean_object* v_kind_1059_, lean_object* v___y_1060_, lean_object* v___y_1061_, lean_object* v___y_1062_, lean_object* v___y_1063_, lean_object* v___y_1064_){
_start:
{
uint8_t v_nondep_boxed_1065_; uint8_t v_kind_boxed_1066_; lean_object* v_res_1067_; 
v_nondep_boxed_1065_ = lean_unbox(v_nondep_1058_);
v_kind_boxed_1066_ = lean_unbox(v_kind_1059_);
v_res_1067_ = lp_JunkValues_Lean_Meta_withLetDecl___at___00JunkValues_visit_spec__1___redArg(v_name_1054_, v_type_1055_, v_val_1056_, v_k_1057_, v_nondep_boxed_1065_, v_kind_boxed_1066_, v___y_1060_, v___y_1061_, v___y_1062_, v___y_1063_);
lean_dec(v___y_1063_);
lean_dec_ref(v___y_1062_);
lean_dec(v___y_1061_);
lean_dec_ref(v___y_1060_);
return v_res_1067_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Meta_withLetDecl___at___00JunkValues_visit_spec__1(lean_object* v_00_u03b1_1068_, lean_object* v_name_1069_, lean_object* v_type_1070_, lean_object* v_val_1071_, lean_object* v_k_1072_, uint8_t v_nondep_1073_, uint8_t v_kind_1074_, lean_object* v___y_1075_, lean_object* v___y_1076_, lean_object* v___y_1077_, lean_object* v___y_1078_){
_start:
{
lean_object* v___x_1080_; 
v___x_1080_ = lp_JunkValues_Lean_Meta_withLetDecl___at___00JunkValues_visit_spec__1___redArg(v_name_1069_, v_type_1070_, v_val_1071_, v_k_1072_, v_nondep_1073_, v_kind_1074_, v___y_1075_, v___y_1076_, v___y_1077_, v___y_1078_);
return v___x_1080_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Meta_withLetDecl___at___00JunkValues_visit_spec__1___boxed(lean_object* v_00_u03b1_1081_, lean_object* v_name_1082_, lean_object* v_type_1083_, lean_object* v_val_1084_, lean_object* v_k_1085_, lean_object* v_nondep_1086_, lean_object* v_kind_1087_, lean_object* v___y_1088_, lean_object* v___y_1089_, lean_object* v___y_1090_, lean_object* v___y_1091_, lean_object* v___y_1092_){
_start:
{
uint8_t v_nondep_boxed_1093_; uint8_t v_kind_boxed_1094_; lean_object* v_res_1095_; 
v_nondep_boxed_1093_ = lean_unbox(v_nondep_1086_);
v_kind_boxed_1094_ = lean_unbox(v_kind_1087_);
v_res_1095_ = lp_JunkValues_Lean_Meta_withLetDecl___at___00JunkValues_visit_spec__1(v_00_u03b1_1081_, v_name_1082_, v_type_1083_, v_val_1084_, v_k_1085_, v_nondep_boxed_1093_, v_kind_boxed_1094_, v___y_1088_, v___y_1089_, v___y_1090_, v___y_1091_);
lean_dec(v___y_1091_);
lean_dec_ref(v___y_1090_);
lean_dec(v___y_1089_);
lean_dec_ref(v___y_1088_);
return v_res_1095_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_visit___lam__0___boxed(lean_object* v_b_1096_, lean_object* v_rs_1097_, lean_object* v_cfg_1098_, lean_object* v_decl_1099_, lean_object* v_site_1100_, lean_object* v_a_1101_, lean_object* v_x_1102_, lean_object* v___y_1103_, lean_object* v___y_1104_, lean_object* v___y_1105_, lean_object* v___y_1106_, lean_object* v___y_1107_){
_start:
{
uint8_t v_site_boxed_1108_; lean_object* v_res_1109_; 
v_site_boxed_1108_ = lean_unbox(v_site_1100_);
v_res_1109_ = lp_JunkValues_JunkValues_visit___lam__0(v_b_1096_, v_rs_1097_, v_cfg_1098_, v_decl_1099_, v_site_boxed_1108_, v_a_1101_, v_x_1102_, v___y_1103_, v___y_1104_, v___y_1105_, v___y_1106_);
lean_dec(v___y_1106_);
lean_dec_ref(v___y_1105_);
lean_dec(v___y_1104_);
lean_dec_ref(v___y_1103_);
lean_dec_ref(v_x_1102_);
lean_dec_ref(v_b_1096_);
return v_res_1109_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_visit___lam__1(lean_object* v_body_1110_, lean_object* v_rs_1111_, lean_object* v_cfg_1112_, lean_object* v_decl_1113_, uint8_t v_site_1114_, lean_object* v_a_1115_, lean_object* v_x_1116_, lean_object* v___y_1117_, lean_object* v___y_1118_, lean_object* v___y_1119_, lean_object* v___y_1120_){
_start:
{
lean_object* v___x_1122_; lean_object* v___x_1123_; 
v___x_1122_ = lean_expr_instantiate1(v_body_1110_, v_x_1116_);
v___x_1123_ = lp_JunkValues_JunkValues_visit(v_rs_1111_, v_cfg_1112_, v_decl_1113_, v_site_1114_, v___x_1122_, v_a_1115_, v___y_1117_, v___y_1118_, v___y_1119_, v___y_1120_);
return v___x_1123_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_visit___lam__1___boxed(lean_object* v_body_1124_, lean_object* v_rs_1125_, lean_object* v_cfg_1126_, lean_object* v_decl_1127_, lean_object* v_site_1128_, lean_object* v_a_1129_, lean_object* v_x_1130_, lean_object* v___y_1131_, lean_object* v___y_1132_, lean_object* v___y_1133_, lean_object* v___y_1134_, lean_object* v___y_1135_){
_start:
{
uint8_t v_site_boxed_1136_; lean_object* v_res_1137_; 
v_site_boxed_1136_ = lean_unbox(v_site_1128_);
v_res_1137_ = lp_JunkValues_JunkValues_visit___lam__1(v_body_1124_, v_rs_1125_, v_cfg_1126_, v_decl_1127_, v_site_boxed_1136_, v_a_1129_, v_x_1130_, v___y_1131_, v___y_1132_, v___y_1133_, v___y_1134_);
lean_dec(v___y_1134_);
lean_dec_ref(v___y_1133_);
lean_dec(v___y_1132_);
lean_dec_ref(v___y_1131_);
lean_dec_ref(v_x_1130_);
lean_dec_ref(v_body_1124_);
return v_res_1137_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_visit(lean_object* v_rs_1138_, lean_object* v_cfg_1139_, lean_object* v_decl_1140_, uint8_t v_site_1141_, lean_object* v_e_1142_, lean_object* v_acc_1143_, lean_object* v_a_1144_, lean_object* v_a_1145_, lean_object* v_a_1146_, lean_object* v_a_1147_){
_start:
{
lean_object* v_maxPerDecl_1149_; lean_object* v___x_1150_; uint8_t v___x_1151_; 
v_maxPerDecl_1149_ = lean_ctor_get(v_cfg_1139_, 1);
v___x_1150_ = lean_array_get_size(v_acc_1143_);
v___x_1151_ = lean_nat_dec_le(v_maxPerDecl_1149_, v___x_1150_);
if (v___x_1151_ == 0)
{
lean_object* v___x_1152_; 
lean_inc_ref(v_e_1142_);
lean_inc(v_decl_1140_);
lean_inc_ref(v_cfg_1139_);
v___x_1152_ = lp_JunkValues_JunkValues_matchAt(v_rs_1138_, v_cfg_1139_, v_decl_1140_, v_site_1141_, v_e_1142_, v_a_1144_, v_a_1145_, v_a_1146_, v_a_1147_);
if (lean_obj_tag(v___x_1152_) == 0)
{
lean_object* v_a_1153_; lean_object* v___x_1155_; uint8_t v_isShared_1156_; uint8_t v_isSharedCheck_1205_; 
v_a_1153_ = lean_ctor_get(v___x_1152_, 0);
v_isSharedCheck_1205_ = !lean_is_exclusive(v___x_1152_);
if (v_isSharedCheck_1205_ == 0)
{
v___x_1155_ = v___x_1152_;
v_isShared_1156_ = v_isSharedCheck_1205_;
goto v_resetjp_1154_;
}
else
{
lean_inc(v_a_1153_);
lean_dec(v___x_1152_);
v___x_1155_ = lean_box(0);
v_isShared_1156_ = v_isSharedCheck_1205_;
goto v_resetjp_1154_;
}
v_resetjp_1154_:
{
lean_object* v___x_1157_; lean_object* v_n_1159_; lean_object* v_t_1160_; lean_object* v_b_1161_; uint8_t v_bi_1162_; lean_object* v___y_1163_; lean_object* v___y_1164_; lean_object* v___y_1165_; lean_object* v___y_1166_; 
v___x_1157_ = l_Array_append___redArg(v_acc_1143_, v_a_1153_);
lean_dec(v_a_1153_);
switch(lean_obj_tag(v_e_1142_))
{
case 5:
{
lean_object* v_fn_1173_; lean_object* v_arg_1174_; lean_object* v___x_1175_; 
lean_del_object(v___x_1155_);
v_fn_1173_ = lean_ctor_get(v_e_1142_, 0);
lean_inc_ref(v_fn_1173_);
v_arg_1174_ = lean_ctor_get(v_e_1142_, 1);
lean_inc_ref(v_arg_1174_);
lean_dec_ref_known(v_e_1142_, 2);
lean_inc(v_decl_1140_);
lean_inc_ref(v_cfg_1139_);
lean_inc_ref(v_rs_1138_);
v___x_1175_ = lp_JunkValues_JunkValues_visit(v_rs_1138_, v_cfg_1139_, v_decl_1140_, v_site_1141_, v_fn_1173_, v___x_1157_, v_a_1144_, v_a_1145_, v_a_1146_, v_a_1147_);
if (lean_obj_tag(v___x_1175_) == 0)
{
lean_object* v_a_1176_; 
v_a_1176_ = lean_ctor_get(v___x_1175_, 0);
lean_inc(v_a_1176_);
lean_dec_ref_known(v___x_1175_, 1);
v_e_1142_ = v_arg_1174_;
v_acc_1143_ = v_a_1176_;
goto _start;
}
else
{
lean_dec_ref(v_arg_1174_);
lean_dec(v_decl_1140_);
lean_dec_ref(v_cfg_1139_);
lean_dec_ref(v_rs_1138_);
return v___x_1175_;
}
}
case 6:
{
lean_object* v_binderName_1178_; lean_object* v_binderType_1179_; lean_object* v_body_1180_; uint8_t v_binderInfo_1181_; 
lean_del_object(v___x_1155_);
v_binderName_1178_ = lean_ctor_get(v_e_1142_, 0);
lean_inc(v_binderName_1178_);
v_binderType_1179_ = lean_ctor_get(v_e_1142_, 1);
lean_inc_ref(v_binderType_1179_);
v_body_1180_ = lean_ctor_get(v_e_1142_, 2);
lean_inc_ref(v_body_1180_);
v_binderInfo_1181_ = lean_ctor_get_uint8(v_e_1142_, sizeof(void*)*3 + 8);
lean_dec_ref_known(v_e_1142_, 3);
v_n_1159_ = v_binderName_1178_;
v_t_1160_ = v_binderType_1179_;
v_b_1161_ = v_body_1180_;
v_bi_1162_ = v_binderInfo_1181_;
v___y_1163_ = v_a_1144_;
v___y_1164_ = v_a_1145_;
v___y_1165_ = v_a_1146_;
v___y_1166_ = v_a_1147_;
goto v___jp_1158_;
}
case 7:
{
lean_object* v_binderName_1182_; lean_object* v_binderType_1183_; lean_object* v_body_1184_; uint8_t v_binderInfo_1185_; 
lean_del_object(v___x_1155_);
v_binderName_1182_ = lean_ctor_get(v_e_1142_, 0);
lean_inc(v_binderName_1182_);
v_binderType_1183_ = lean_ctor_get(v_e_1142_, 1);
lean_inc_ref(v_binderType_1183_);
v_body_1184_ = lean_ctor_get(v_e_1142_, 2);
lean_inc_ref(v_body_1184_);
v_binderInfo_1185_ = lean_ctor_get_uint8(v_e_1142_, sizeof(void*)*3 + 8);
lean_dec_ref_known(v_e_1142_, 3);
v_n_1159_ = v_binderName_1182_;
v_t_1160_ = v_binderType_1183_;
v_b_1161_ = v_body_1184_;
v_bi_1162_ = v_binderInfo_1185_;
v___y_1163_ = v_a_1144_;
v___y_1164_ = v_a_1145_;
v___y_1165_ = v_a_1146_;
v___y_1166_ = v_a_1147_;
goto v___jp_1158_;
}
case 8:
{
lean_object* v_declName_1186_; lean_object* v_type_1187_; lean_object* v_value_1188_; lean_object* v_body_1189_; lean_object* v___x_1190_; 
lean_del_object(v___x_1155_);
v_declName_1186_ = lean_ctor_get(v_e_1142_, 0);
lean_inc(v_declName_1186_);
v_type_1187_ = lean_ctor_get(v_e_1142_, 1);
lean_inc_ref_n(v_type_1187_, 2);
v_value_1188_ = lean_ctor_get(v_e_1142_, 2);
lean_inc_ref(v_value_1188_);
v_body_1189_ = lean_ctor_get(v_e_1142_, 3);
lean_inc_ref(v_body_1189_);
lean_dec_ref_known(v_e_1142_, 4);
lean_inc(v_decl_1140_);
lean_inc_ref(v_cfg_1139_);
lean_inc_ref(v_rs_1138_);
v___x_1190_ = lp_JunkValues_JunkValues_visit(v_rs_1138_, v_cfg_1139_, v_decl_1140_, v_site_1141_, v_type_1187_, v___x_1157_, v_a_1144_, v_a_1145_, v_a_1146_, v_a_1147_);
if (lean_obj_tag(v___x_1190_) == 0)
{
lean_object* v_a_1191_; lean_object* v___x_1192_; 
v_a_1191_ = lean_ctor_get(v___x_1190_, 0);
lean_inc(v_a_1191_);
lean_dec_ref_known(v___x_1190_, 1);
lean_inc_ref(v_value_1188_);
lean_inc(v_decl_1140_);
lean_inc_ref(v_cfg_1139_);
lean_inc_ref(v_rs_1138_);
v___x_1192_ = lp_JunkValues_JunkValues_visit(v_rs_1138_, v_cfg_1139_, v_decl_1140_, v_site_1141_, v_value_1188_, v_a_1191_, v_a_1144_, v_a_1145_, v_a_1146_, v_a_1147_);
if (lean_obj_tag(v___x_1192_) == 0)
{
lean_object* v_a_1193_; lean_object* v___x_1194_; lean_object* v___f_1195_; uint8_t v___x_1196_; lean_object* v___x_1197_; 
v_a_1193_ = lean_ctor_get(v___x_1192_, 0);
lean_inc(v_a_1193_);
lean_dec_ref_known(v___x_1192_, 1);
v___x_1194_ = lean_box(v_site_1141_);
v___f_1195_ = lean_alloc_closure((void*)(lp_JunkValues_JunkValues_visit___lam__1___boxed), 12, 6);
lean_closure_set(v___f_1195_, 0, v_body_1189_);
lean_closure_set(v___f_1195_, 1, v_rs_1138_);
lean_closure_set(v___f_1195_, 2, v_cfg_1139_);
lean_closure_set(v___f_1195_, 3, v_decl_1140_);
lean_closure_set(v___f_1195_, 4, v___x_1194_);
lean_closure_set(v___f_1195_, 5, v_a_1193_);
v___x_1196_ = 0;
v___x_1197_ = lp_JunkValues_Lean_Meta_withLetDecl___at___00JunkValues_visit_spec__1___redArg(v_declName_1186_, v_type_1187_, v_value_1188_, v___f_1195_, v___x_1151_, v___x_1196_, v_a_1144_, v_a_1145_, v_a_1146_, v_a_1147_);
return v___x_1197_;
}
else
{
lean_dec_ref(v_body_1189_);
lean_dec_ref(v_value_1188_);
lean_dec_ref(v_type_1187_);
lean_dec(v_declName_1186_);
lean_dec(v_decl_1140_);
lean_dec_ref(v_cfg_1139_);
lean_dec_ref(v_rs_1138_);
return v___x_1192_;
}
}
else
{
lean_dec_ref(v_body_1189_);
lean_dec_ref(v_value_1188_);
lean_dec_ref(v_type_1187_);
lean_dec(v_declName_1186_);
lean_dec(v_decl_1140_);
lean_dec_ref(v_cfg_1139_);
lean_dec_ref(v_rs_1138_);
return v___x_1190_;
}
}
case 10:
{
lean_object* v_expr_1198_; 
lean_del_object(v___x_1155_);
v_expr_1198_ = lean_ctor_get(v_e_1142_, 1);
lean_inc_ref(v_expr_1198_);
lean_dec_ref_known(v_e_1142_, 2);
v_e_1142_ = v_expr_1198_;
v_acc_1143_ = v___x_1157_;
goto _start;
}
case 11:
{
lean_object* v_struct_1200_; 
lean_del_object(v___x_1155_);
v_struct_1200_ = lean_ctor_get(v_e_1142_, 2);
lean_inc_ref(v_struct_1200_);
lean_dec_ref_known(v_e_1142_, 3);
v_e_1142_ = v_struct_1200_;
v_acc_1143_ = v___x_1157_;
goto _start;
}
default: 
{
lean_object* v___x_1203_; 
lean_dec_ref(v_e_1142_);
lean_dec(v_decl_1140_);
lean_dec_ref(v_cfg_1139_);
lean_dec_ref(v_rs_1138_);
if (v_isShared_1156_ == 0)
{
lean_ctor_set(v___x_1155_, 0, v___x_1157_);
v___x_1203_ = v___x_1155_;
goto v_reusejp_1202_;
}
else
{
lean_object* v_reuseFailAlloc_1204_; 
v_reuseFailAlloc_1204_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1204_, 0, v___x_1157_);
v___x_1203_ = v_reuseFailAlloc_1204_;
goto v_reusejp_1202_;
}
v_reusejp_1202_:
{
return v___x_1203_;
}
}
}
v___jp_1158_:
{
lean_object* v___x_1167_; 
lean_inc_ref(v_t_1160_);
lean_inc(v_decl_1140_);
lean_inc_ref(v_cfg_1139_);
lean_inc_ref(v_rs_1138_);
v___x_1167_ = lp_JunkValues_JunkValues_visit(v_rs_1138_, v_cfg_1139_, v_decl_1140_, v_site_1141_, v_t_1160_, v___x_1157_, v___y_1163_, v___y_1164_, v___y_1165_, v___y_1166_);
if (lean_obj_tag(v___x_1167_) == 0)
{
lean_object* v_a_1168_; lean_object* v___x_1169_; lean_object* v___f_1170_; uint8_t v___x_1171_; lean_object* v___x_1172_; 
v_a_1168_ = lean_ctor_get(v___x_1167_, 0);
lean_inc(v_a_1168_);
lean_dec_ref_known(v___x_1167_, 1);
v___x_1169_ = lean_box(v_site_1141_);
v___f_1170_ = lean_alloc_closure((void*)(lp_JunkValues_JunkValues_visit___lam__0___boxed), 12, 6);
lean_closure_set(v___f_1170_, 0, v_b_1161_);
lean_closure_set(v___f_1170_, 1, v_rs_1138_);
lean_closure_set(v___f_1170_, 2, v_cfg_1139_);
lean_closure_set(v___f_1170_, 3, v_decl_1140_);
lean_closure_set(v___f_1170_, 4, v___x_1169_);
lean_closure_set(v___f_1170_, 5, v_a_1168_);
v___x_1171_ = 0;
v___x_1172_ = lp_JunkValues_Lean_Meta_withLocalDecl___at___00JunkValues_visit_spec__0___redArg(v_n_1159_, v_bi_1162_, v_t_1160_, v___f_1170_, v___x_1171_, v___y_1163_, v___y_1164_, v___y_1165_, v___y_1166_);
return v___x_1172_;
}
else
{
lean_dec_ref(v_b_1161_);
lean_dec_ref(v_t_1160_);
lean_dec(v_n_1159_);
lean_dec(v_decl_1140_);
lean_dec_ref(v_cfg_1139_);
lean_dec_ref(v_rs_1138_);
return v___x_1167_;
}
}
}
}
else
{
lean_dec_ref(v_acc_1143_);
lean_dec_ref(v_e_1142_);
lean_dec(v_decl_1140_);
lean_dec_ref(v_cfg_1139_);
lean_dec_ref(v_rs_1138_);
return v___x_1152_;
}
}
else
{
lean_object* v___x_1206_; 
lean_dec_ref(v_e_1142_);
lean_dec(v_decl_1140_);
lean_dec_ref(v_cfg_1139_);
lean_dec_ref(v_rs_1138_);
v___x_1206_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1206_, 0, v_acc_1143_);
return v___x_1206_;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_visit___lam__0(lean_object* v_b_1207_, lean_object* v_rs_1208_, lean_object* v_cfg_1209_, lean_object* v_decl_1210_, uint8_t v_site_1211_, lean_object* v_a_1212_, lean_object* v_x_1213_, lean_object* v___y_1214_, lean_object* v___y_1215_, lean_object* v___y_1216_, lean_object* v___y_1217_){
_start:
{
lean_object* v___x_1219_; lean_object* v___x_1220_; 
v___x_1219_ = lean_expr_instantiate1(v_b_1207_, v_x_1213_);
v___x_1220_ = lp_JunkValues_JunkValues_visit(v_rs_1208_, v_cfg_1209_, v_decl_1210_, v_site_1211_, v___x_1219_, v_a_1212_, v___y_1214_, v___y_1215_, v___y_1216_, v___y_1217_);
return v___x_1220_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_visit___boxed(lean_object* v_rs_1221_, lean_object* v_cfg_1222_, lean_object* v_decl_1223_, lean_object* v_site_1224_, lean_object* v_e_1225_, lean_object* v_acc_1226_, lean_object* v_a_1227_, lean_object* v_a_1228_, lean_object* v_a_1229_, lean_object* v_a_1230_, lean_object* v_a_1231_){
_start:
{
uint8_t v_site_boxed_1232_; lean_object* v_res_1233_; 
v_site_boxed_1232_ = lean_unbox(v_site_1224_);
v_res_1233_ = lp_JunkValues_JunkValues_visit(v_rs_1221_, v_cfg_1222_, v_decl_1223_, v_site_boxed_1232_, v_e_1225_, v_acc_1226_, v_a_1227_, v_a_1228_, v_a_1229_, v_a_1230_);
lean_dec(v_a_1230_);
lean_dec_ref(v_a_1229_);
lean_dec(v_a_1228_);
lean_dec_ref(v_a_1227_);
return v_res_1233_;
}
}
LEAN_EXPORT uint8_t lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_dedupFindings_spec__0_spec__0___redArg(lean_object* v_a_1234_, lean_object* v_x_1235_){
_start:
{
if (lean_obj_tag(v_x_1235_) == 0)
{
uint8_t v___x_1236_; 
v___x_1236_ = 0;
return v___x_1236_;
}
else
{
lean_object* v_key_1237_; lean_object* v_tail_1238_; uint8_t v___y_1240_; lean_object* v_fst_1242_; lean_object* v_snd_1243_; lean_object* v_fst_1244_; lean_object* v_snd_1245_; uint8_t v___x_1246_; 
v_key_1237_ = lean_ctor_get(v_x_1235_, 0);
v_tail_1238_ = lean_ctor_get(v_x_1235_, 2);
v_fst_1242_ = lean_ctor_get(v_key_1237_, 0);
v_snd_1243_ = lean_ctor_get(v_key_1237_, 1);
v_fst_1244_ = lean_ctor_get(v_a_1234_, 0);
v_snd_1245_ = lean_ctor_get(v_a_1234_, 1);
v___x_1246_ = lean_name_eq(v_fst_1242_, v_fst_1244_);
if (v___x_1246_ == 0)
{
v___y_1240_ = v___x_1246_;
goto v___jp_1239_;
}
else
{
lean_object* v_fst_1247_; lean_object* v_snd_1248_; lean_object* v_fst_1249_; lean_object* v_snd_1250_; uint8_t v___x_1251_; uint8_t v___x_1252_; uint8_t v___x_1253_; 
v_fst_1247_ = lean_ctor_get(v_snd_1243_, 0);
v_snd_1248_ = lean_ctor_get(v_snd_1243_, 1);
v_fst_1249_ = lean_ctor_get(v_snd_1245_, 0);
v_snd_1250_ = lean_ctor_get(v_snd_1245_, 1);
v___x_1251_ = lean_unbox(v_fst_1247_);
v___x_1252_ = lean_unbox(v_fst_1249_);
v___x_1253_ = lp_JunkValues_JunkValues_instBEqSite_beq(v___x_1251_, v___x_1252_);
if (v___x_1253_ == 0)
{
v___y_1240_ = v___x_1253_;
goto v___jp_1239_;
}
else
{
uint8_t v___x_1254_; 
v___x_1254_ = lean_string_dec_eq(v_snd_1248_, v_snd_1250_);
v___y_1240_ = v___x_1254_;
goto v___jp_1239_;
}
}
v___jp_1239_:
{
if (v___y_1240_ == 0)
{
v_x_1235_ = v_tail_1238_;
goto _start;
}
else
{
return v___y_1240_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_dedupFindings_spec__0_spec__0___redArg___boxed(lean_object* v_a_1255_, lean_object* v_x_1256_){
_start:
{
uint8_t v_res_1257_; lean_object* v_r_1258_; 
v_res_1257_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_dedupFindings_spec__0_spec__0___redArg(v_a_1255_, v_x_1256_);
lean_dec(v_x_1256_);
lean_dec_ref(v_a_1255_);
v_r_1258_ = lean_box(v_res_1257_);
return v_r_1258_;
}
}
static uint64_t _init_lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_dedupFindings_spec__0___redArg___closed__0(void){
_start:
{
lean_object* v___x_1259_; uint64_t v___x_1260_; 
v___x_1259_ = lean_unsigned_to_nat(1723u);
v___x_1260_ = lean_uint64_of_nat(v___x_1259_);
return v___x_1260_;
}
}
LEAN_EXPORT uint8_t lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_dedupFindings_spec__0___redArg(lean_object* v_m_1261_, lean_object* v_a_1262_){
_start:
{
lean_object* v_buckets_1263_; lean_object* v_fst_1264_; lean_object* v_snd_1265_; lean_object* v___x_1266_; uint64_t v___y_1268_; 
v_buckets_1263_ = lean_ctor_get(v_m_1261_, 1);
v_fst_1264_ = lean_ctor_get(v_a_1262_, 0);
v_snd_1265_ = lean_ctor_get(v_a_1262_, 1);
v___x_1266_ = lean_array_get_size(v_buckets_1263_);
if (lean_obj_tag(v_fst_1264_) == 0)
{
uint64_t v___x_1289_; 
v___x_1289_ = lean_uint64_once(&lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_dedupFindings_spec__0___redArg___closed__0, &lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_dedupFindings_spec__0___redArg___closed__0_once, _init_lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_dedupFindings_spec__0___redArg___closed__0);
v___y_1268_ = v___x_1289_;
goto v___jp_1267_;
}
else
{
uint64_t v_hash_1290_; 
v_hash_1290_ = lean_ctor_get_uint64(v_fst_1264_, sizeof(void*)*2);
v___y_1268_ = v_hash_1290_;
goto v___jp_1267_;
}
v___jp_1267_:
{
lean_object* v_fst_1269_; lean_object* v_snd_1270_; uint8_t v___x_1271_; uint64_t v___x_1272_; uint64_t v___x_1273_; uint64_t v___x_1274_; uint64_t v___x_1275_; uint64_t v___x_1276_; uint64_t v___x_1277_; uint64_t v_fold_1278_; uint64_t v___x_1279_; uint64_t v___x_1280_; uint64_t v___x_1281_; size_t v___x_1282_; size_t v___x_1283_; size_t v___x_1284_; size_t v___x_1285_; size_t v___x_1286_; lean_object* v___x_1287_; uint8_t v___x_1288_; 
v_fst_1269_ = lean_ctor_get(v_snd_1265_, 0);
v_snd_1270_ = lean_ctor_get(v_snd_1265_, 1);
v___x_1271_ = lean_unbox(v_fst_1269_);
v___x_1272_ = lp_JunkValues_JunkValues_instHashableSite_hash(v___x_1271_);
v___x_1273_ = lean_string_hash(v_snd_1270_);
v___x_1274_ = lean_uint64_mix_hash(v___x_1272_, v___x_1273_);
v___x_1275_ = lean_uint64_mix_hash(v___y_1268_, v___x_1274_);
v___x_1276_ = 32ULL;
v___x_1277_ = lean_uint64_shift_right(v___x_1275_, v___x_1276_);
v_fold_1278_ = lean_uint64_xor(v___x_1275_, v___x_1277_);
v___x_1279_ = 16ULL;
v___x_1280_ = lean_uint64_shift_right(v_fold_1278_, v___x_1279_);
v___x_1281_ = lean_uint64_xor(v_fold_1278_, v___x_1280_);
v___x_1282_ = lean_uint64_to_usize(v___x_1281_);
v___x_1283_ = lean_usize_of_nat(v___x_1266_);
v___x_1284_ = ((size_t)1ULL);
v___x_1285_ = lean_usize_sub(v___x_1283_, v___x_1284_);
v___x_1286_ = lean_usize_land(v___x_1282_, v___x_1285_);
v___x_1287_ = lean_array_uget_borrowed(v_buckets_1263_, v___x_1286_);
v___x_1288_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_dedupFindings_spec__0_spec__0___redArg(v_a_1262_, v___x_1287_);
return v___x_1288_;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_dedupFindings_spec__0___redArg___boxed(lean_object* v_m_1291_, lean_object* v_a_1292_){
_start:
{
uint8_t v_res_1293_; lean_object* v_r_1294_; 
v_res_1293_ = lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_dedupFindings_spec__0___redArg(v_m_1291_, v_a_1292_);
lean_dec_ref(v_a_1292_);
lean_dec_ref(v_m_1291_);
v_r_1294_ = lean_box(v_res_1293_);
return v_r_1294_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00__private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_dedupFindings_spec__1_spec__2_spec__3_spec__5___redArg(lean_object* v_x_1295_, lean_object* v_x_1296_){
_start:
{
if (lean_obj_tag(v_x_1296_) == 0)
{
return v_x_1295_;
}
else
{
lean_object* v_key_1297_; lean_object* v_value_1298_; lean_object* v_tail_1299_; lean_object* v___x_1301_; uint8_t v_isShared_1302_; uint8_t v_isSharedCheck_1334_; 
v_key_1297_ = lean_ctor_get(v_x_1296_, 0);
v_value_1298_ = lean_ctor_get(v_x_1296_, 1);
v_tail_1299_ = lean_ctor_get(v_x_1296_, 2);
v_isSharedCheck_1334_ = !lean_is_exclusive(v_x_1296_);
if (v_isSharedCheck_1334_ == 0)
{
v___x_1301_ = v_x_1296_;
v_isShared_1302_ = v_isSharedCheck_1334_;
goto v_resetjp_1300_;
}
else
{
lean_inc(v_tail_1299_);
lean_inc(v_value_1298_);
lean_inc(v_key_1297_);
lean_dec(v_x_1296_);
v___x_1301_ = lean_box(0);
v_isShared_1302_ = v_isSharedCheck_1334_;
goto v_resetjp_1300_;
}
v_resetjp_1300_:
{
lean_object* v_fst_1303_; lean_object* v_snd_1304_; lean_object* v___x_1305_; uint64_t v___y_1307_; 
v_fst_1303_ = lean_ctor_get(v_key_1297_, 0);
v_snd_1304_ = lean_ctor_get(v_key_1297_, 1);
v___x_1305_ = lean_array_get_size(v_x_1295_);
if (lean_obj_tag(v_fst_1303_) == 0)
{
uint64_t v___x_1332_; 
v___x_1332_ = lean_uint64_once(&lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_dedupFindings_spec__0___redArg___closed__0, &lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_dedupFindings_spec__0___redArg___closed__0_once, _init_lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_dedupFindings_spec__0___redArg___closed__0);
v___y_1307_ = v___x_1332_;
goto v___jp_1306_;
}
else
{
uint64_t v_hash_1333_; 
v_hash_1333_ = lean_ctor_get_uint64(v_fst_1303_, sizeof(void*)*2);
v___y_1307_ = v_hash_1333_;
goto v___jp_1306_;
}
v___jp_1306_:
{
lean_object* v_fst_1308_; lean_object* v_snd_1309_; uint8_t v___x_1310_; uint64_t v___x_1311_; uint64_t v___x_1312_; uint64_t v___x_1313_; uint64_t v___x_1314_; uint64_t v___x_1315_; uint64_t v___x_1316_; uint64_t v_fold_1317_; uint64_t v___x_1318_; uint64_t v___x_1319_; uint64_t v___x_1320_; size_t v___x_1321_; size_t v___x_1322_; size_t v___x_1323_; size_t v___x_1324_; size_t v___x_1325_; lean_object* v___x_1326_; lean_object* v___x_1328_; 
v_fst_1308_ = lean_ctor_get(v_snd_1304_, 0);
v_snd_1309_ = lean_ctor_get(v_snd_1304_, 1);
v___x_1310_ = lean_unbox(v_fst_1308_);
v___x_1311_ = lp_JunkValues_JunkValues_instHashableSite_hash(v___x_1310_);
v___x_1312_ = lean_string_hash(v_snd_1309_);
v___x_1313_ = lean_uint64_mix_hash(v___x_1311_, v___x_1312_);
v___x_1314_ = lean_uint64_mix_hash(v___y_1307_, v___x_1313_);
v___x_1315_ = 32ULL;
v___x_1316_ = lean_uint64_shift_right(v___x_1314_, v___x_1315_);
v_fold_1317_ = lean_uint64_xor(v___x_1314_, v___x_1316_);
v___x_1318_ = 16ULL;
v___x_1319_ = lean_uint64_shift_right(v_fold_1317_, v___x_1318_);
v___x_1320_ = lean_uint64_xor(v_fold_1317_, v___x_1319_);
v___x_1321_ = lean_uint64_to_usize(v___x_1320_);
v___x_1322_ = lean_usize_of_nat(v___x_1305_);
v___x_1323_ = ((size_t)1ULL);
v___x_1324_ = lean_usize_sub(v___x_1322_, v___x_1323_);
v___x_1325_ = lean_usize_land(v___x_1321_, v___x_1324_);
v___x_1326_ = lean_array_uget_borrowed(v_x_1295_, v___x_1325_);
lean_inc(v___x_1326_);
if (v_isShared_1302_ == 0)
{
lean_ctor_set(v___x_1301_, 2, v___x_1326_);
v___x_1328_ = v___x_1301_;
goto v_reusejp_1327_;
}
else
{
lean_object* v_reuseFailAlloc_1331_; 
v_reuseFailAlloc_1331_ = lean_alloc_ctor(1, 3, 0);
lean_ctor_set(v_reuseFailAlloc_1331_, 0, v_key_1297_);
lean_ctor_set(v_reuseFailAlloc_1331_, 1, v_value_1298_);
lean_ctor_set(v_reuseFailAlloc_1331_, 2, v___x_1326_);
v___x_1328_ = v_reuseFailAlloc_1331_;
goto v_reusejp_1327_;
}
v_reusejp_1327_:
{
lean_object* v___x_1329_; 
v___x_1329_ = lean_array_uset(v_x_1295_, v___x_1325_, v___x_1328_);
v_x_1295_ = v___x_1329_;
v_x_1296_ = v_tail_1299_;
goto _start;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_dedupFindings_spec__1_spec__2_spec__3___redArg(lean_object* v_i_1335_, lean_object* v_source_1336_, lean_object* v_target_1337_){
_start:
{
lean_object* v___x_1338_; uint8_t v___x_1339_; 
v___x_1338_ = lean_array_get_size(v_source_1336_);
v___x_1339_ = lean_nat_dec_lt(v_i_1335_, v___x_1338_);
if (v___x_1339_ == 0)
{
lean_dec_ref(v_source_1336_);
lean_dec(v_i_1335_);
return v_target_1337_;
}
else
{
lean_object* v_es_1340_; lean_object* v___x_1341_; lean_object* v_source_1342_; lean_object* v_target_1343_; lean_object* v___x_1344_; lean_object* v___x_1345_; 
v_es_1340_ = lean_array_fget(v_source_1336_, v_i_1335_);
v___x_1341_ = lean_box(0);
v_source_1342_ = lean_array_fset(v_source_1336_, v_i_1335_, v___x_1341_);
v_target_1343_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00__private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_dedupFindings_spec__1_spec__2_spec__3_spec__5___redArg(v_target_1337_, v_es_1340_);
v___x_1344_ = lean_unsigned_to_nat(1u);
v___x_1345_ = lean_nat_add(v_i_1335_, v___x_1344_);
lean_dec(v_i_1335_);
v_i_1335_ = v___x_1345_;
v_source_1336_ = v_source_1342_;
v_target_1337_ = v_target_1343_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_dedupFindings_spec__1_spec__2___redArg(lean_object* v_data_1347_){
_start:
{
lean_object* v___x_1348_; lean_object* v___x_1349_; lean_object* v_nbuckets_1350_; lean_object* v___x_1351_; lean_object* v___x_1352_; lean_object* v___x_1353_; lean_object* v___x_1354_; 
v___x_1348_ = lean_array_get_size(v_data_1347_);
v___x_1349_ = lean_unsigned_to_nat(2u);
v_nbuckets_1350_ = lean_nat_mul(v___x_1348_, v___x_1349_);
v___x_1351_ = lean_unsigned_to_nat(0u);
v___x_1352_ = lean_box(0);
v___x_1353_ = lean_mk_array(v_nbuckets_1350_, v___x_1352_);
v___x_1354_ = lp_JunkValues___private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_dedupFindings_spec__1_spec__2_spec__3___redArg(v___x_1351_, v_data_1347_, v___x_1353_);
return v___x_1354_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_dedupFindings_spec__1___redArg(lean_object* v_m_1355_, lean_object* v_a_1356_, lean_object* v_b_1357_){
_start:
{
lean_object* v_size_1358_; lean_object* v_buckets_1359_; lean_object* v_fst_1360_; lean_object* v_snd_1361_; lean_object* v___x_1362_; uint64_t v___y_1364_; 
v_size_1358_ = lean_ctor_get(v_m_1355_, 0);
v_buckets_1359_ = lean_ctor_get(v_m_1355_, 1);
v_fst_1360_ = lean_ctor_get(v_a_1356_, 0);
v_snd_1361_ = lean_ctor_get(v_a_1356_, 1);
v___x_1362_ = lean_array_get_size(v_buckets_1359_);
if (lean_obj_tag(v_fst_1360_) == 0)
{
uint64_t v___x_1408_; 
v___x_1408_ = lean_uint64_once(&lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_dedupFindings_spec__0___redArg___closed__0, &lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_dedupFindings_spec__0___redArg___closed__0_once, _init_lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_dedupFindings_spec__0___redArg___closed__0);
v___y_1364_ = v___x_1408_;
goto v___jp_1363_;
}
else
{
uint64_t v_hash_1409_; 
v_hash_1409_ = lean_ctor_get_uint64(v_fst_1360_, sizeof(void*)*2);
v___y_1364_ = v_hash_1409_;
goto v___jp_1363_;
}
v___jp_1363_:
{
lean_object* v_fst_1365_; lean_object* v_snd_1366_; uint8_t v___x_1367_; uint64_t v___x_1368_; uint64_t v___x_1369_; uint64_t v___x_1370_; uint64_t v___x_1371_; uint64_t v___x_1372_; uint64_t v___x_1373_; uint64_t v_fold_1374_; uint64_t v___x_1375_; uint64_t v___x_1376_; uint64_t v___x_1377_; size_t v___x_1378_; size_t v___x_1379_; size_t v___x_1380_; size_t v___x_1381_; size_t v___x_1382_; lean_object* v_bkt_1383_; uint8_t v___x_1384_; 
v_fst_1365_ = lean_ctor_get(v_snd_1361_, 0);
v_snd_1366_ = lean_ctor_get(v_snd_1361_, 1);
v___x_1367_ = lean_unbox(v_fst_1365_);
v___x_1368_ = lp_JunkValues_JunkValues_instHashableSite_hash(v___x_1367_);
v___x_1369_ = lean_string_hash(v_snd_1366_);
v___x_1370_ = lean_uint64_mix_hash(v___x_1368_, v___x_1369_);
v___x_1371_ = lean_uint64_mix_hash(v___y_1364_, v___x_1370_);
v___x_1372_ = 32ULL;
v___x_1373_ = lean_uint64_shift_right(v___x_1371_, v___x_1372_);
v_fold_1374_ = lean_uint64_xor(v___x_1371_, v___x_1373_);
v___x_1375_ = 16ULL;
v___x_1376_ = lean_uint64_shift_right(v_fold_1374_, v___x_1375_);
v___x_1377_ = lean_uint64_xor(v_fold_1374_, v___x_1376_);
v___x_1378_ = lean_uint64_to_usize(v___x_1377_);
v___x_1379_ = lean_usize_of_nat(v___x_1362_);
v___x_1380_ = ((size_t)1ULL);
v___x_1381_ = lean_usize_sub(v___x_1379_, v___x_1380_);
v___x_1382_ = lean_usize_land(v___x_1378_, v___x_1381_);
v_bkt_1383_ = lean_array_uget_borrowed(v_buckets_1359_, v___x_1382_);
v___x_1384_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_dedupFindings_spec__0_spec__0___redArg(v_a_1356_, v_bkt_1383_);
if (v___x_1384_ == 0)
{
lean_object* v___x_1386_; uint8_t v_isShared_1387_; uint8_t v_isSharedCheck_1405_; 
lean_inc_ref(v_buckets_1359_);
lean_inc(v_size_1358_);
v_isSharedCheck_1405_ = !lean_is_exclusive(v_m_1355_);
if (v_isSharedCheck_1405_ == 0)
{
lean_object* v_unused_1406_; lean_object* v_unused_1407_; 
v_unused_1406_ = lean_ctor_get(v_m_1355_, 1);
lean_dec(v_unused_1406_);
v_unused_1407_ = lean_ctor_get(v_m_1355_, 0);
lean_dec(v_unused_1407_);
v___x_1386_ = v_m_1355_;
v_isShared_1387_ = v_isSharedCheck_1405_;
goto v_resetjp_1385_;
}
else
{
lean_dec(v_m_1355_);
v___x_1386_ = lean_box(0);
v_isShared_1387_ = v_isSharedCheck_1405_;
goto v_resetjp_1385_;
}
v_resetjp_1385_:
{
lean_object* v___x_1388_; lean_object* v_size_x27_1389_; lean_object* v___x_1390_; lean_object* v_buckets_x27_1391_; lean_object* v___x_1392_; lean_object* v___x_1393_; lean_object* v___x_1394_; lean_object* v___x_1395_; lean_object* v___x_1396_; uint8_t v___x_1397_; 
v___x_1388_ = lean_unsigned_to_nat(1u);
v_size_x27_1389_ = lean_nat_add(v_size_1358_, v___x_1388_);
lean_dec(v_size_1358_);
lean_inc(v_bkt_1383_);
v___x_1390_ = lean_alloc_ctor(1, 3, 0);
lean_ctor_set(v___x_1390_, 0, v_a_1356_);
lean_ctor_set(v___x_1390_, 1, v_b_1357_);
lean_ctor_set(v___x_1390_, 2, v_bkt_1383_);
v_buckets_x27_1391_ = lean_array_uset(v_buckets_1359_, v___x_1382_, v___x_1390_);
v___x_1392_ = lean_unsigned_to_nat(4u);
v___x_1393_ = lean_nat_mul(v_size_x27_1389_, v___x_1392_);
v___x_1394_ = lean_unsigned_to_nat(3u);
v___x_1395_ = lean_nat_div(v___x_1393_, v___x_1394_);
lean_dec(v___x_1393_);
v___x_1396_ = lean_array_get_size(v_buckets_x27_1391_);
v___x_1397_ = lean_nat_dec_le(v___x_1395_, v___x_1396_);
lean_dec(v___x_1395_);
if (v___x_1397_ == 0)
{
lean_object* v_val_1398_; lean_object* v___x_1400_; 
v_val_1398_ = lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_dedupFindings_spec__1_spec__2___redArg(v_buckets_x27_1391_);
if (v_isShared_1387_ == 0)
{
lean_ctor_set(v___x_1386_, 1, v_val_1398_);
lean_ctor_set(v___x_1386_, 0, v_size_x27_1389_);
v___x_1400_ = v___x_1386_;
goto v_reusejp_1399_;
}
else
{
lean_object* v_reuseFailAlloc_1401_; 
v_reuseFailAlloc_1401_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1401_, 0, v_size_x27_1389_);
lean_ctor_set(v_reuseFailAlloc_1401_, 1, v_val_1398_);
v___x_1400_ = v_reuseFailAlloc_1401_;
goto v_reusejp_1399_;
}
v_reusejp_1399_:
{
return v___x_1400_;
}
}
else
{
lean_object* v___x_1403_; 
if (v_isShared_1387_ == 0)
{
lean_ctor_set(v___x_1386_, 1, v_buckets_x27_1391_);
lean_ctor_set(v___x_1386_, 0, v_size_x27_1389_);
v___x_1403_ = v___x_1386_;
goto v_reusejp_1402_;
}
else
{
lean_object* v_reuseFailAlloc_1404_; 
v_reuseFailAlloc_1404_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1404_, 0, v_size_x27_1389_);
lean_ctor_set(v_reuseFailAlloc_1404_, 1, v_buckets_x27_1391_);
v___x_1403_ = v_reuseFailAlloc_1404_;
goto v_reusejp_1402_;
}
v_reusejp_1402_:
{
return v___x_1403_;
}
}
}
}
else
{
lean_dec(v_b_1357_);
lean_dec_ref(v_a_1356_);
return v_m_1355_;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_dedupFindings_spec__2(lean_object* v_as_1410_, size_t v_sz_1411_, size_t v_i_1412_, lean_object* v_b_1413_){
_start:
{
lean_object* v_a_1415_; uint8_t v___x_1419_; 
v___x_1419_ = lean_usize_dec_lt(v_i_1412_, v_sz_1411_);
if (v___x_1419_ == 0)
{
return v_b_1413_;
}
else
{
lean_object* v_fst_1420_; lean_object* v_snd_1421_; lean_object* v___x_1423_; uint8_t v_isShared_1424_; uint8_t v_isSharedCheck_1440_; 
v_fst_1420_ = lean_ctor_get(v_b_1413_, 0);
v_snd_1421_ = lean_ctor_get(v_b_1413_, 1);
v_isSharedCheck_1440_ = !lean_is_exclusive(v_b_1413_);
if (v_isSharedCheck_1440_ == 0)
{
v___x_1423_ = v_b_1413_;
v_isShared_1424_ = v_isSharedCheck_1440_;
goto v_resetjp_1422_;
}
else
{
lean_inc(v_snd_1421_);
lean_inc(v_fst_1420_);
lean_dec(v_b_1413_);
v___x_1423_ = lean_box(0);
v_isShared_1424_ = v_isSharedCheck_1440_;
goto v_resetjp_1422_;
}
v_resetjp_1422_:
{
lean_object* v_a_1425_; uint8_t v_site_1426_; lean_object* v_rule_1427_; lean_object* v_term_1428_; lean_object* v___x_1429_; lean_object* v___x_1431_; 
v_a_1425_ = lean_array_uget_borrowed(v_as_1410_, v_i_1412_);
v_site_1426_ = lean_ctor_get_uint8(v_a_1425_, sizeof(void*)*8);
v_rule_1427_ = lean_ctor_get(v_a_1425_, 1);
v_term_1428_ = lean_ctor_get(v_a_1425_, 3);
v___x_1429_ = lean_box(v_site_1426_);
lean_inc_ref(v_term_1428_);
if (v_isShared_1424_ == 0)
{
lean_ctor_set(v___x_1423_, 1, v_term_1428_);
lean_ctor_set(v___x_1423_, 0, v___x_1429_);
v___x_1431_ = v___x_1423_;
goto v_reusejp_1430_;
}
else
{
lean_object* v_reuseFailAlloc_1439_; 
v_reuseFailAlloc_1439_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1439_, 0, v___x_1429_);
lean_ctor_set(v_reuseFailAlloc_1439_, 1, v_term_1428_);
v___x_1431_ = v_reuseFailAlloc_1439_;
goto v_reusejp_1430_;
}
v_reusejp_1430_:
{
lean_object* v___x_1432_; uint8_t v___x_1433_; 
lean_inc(v_rule_1427_);
v___x_1432_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1432_, 0, v_rule_1427_);
lean_ctor_set(v___x_1432_, 1, v___x_1431_);
v___x_1433_ = lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_dedupFindings_spec__0___redArg(v_fst_1420_, v___x_1432_);
if (v___x_1433_ == 0)
{
lean_object* v___x_1434_; lean_object* v___x_1435_; lean_object* v___x_1436_; lean_object* v___x_1437_; 
v___x_1434_ = lean_box(0);
v___x_1435_ = lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_dedupFindings_spec__1___redArg(v_fst_1420_, v___x_1432_, v___x_1434_);
lean_inc(v_a_1425_);
v___x_1436_ = lean_array_push(v_snd_1421_, v_a_1425_);
v___x_1437_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1437_, 0, v___x_1435_);
lean_ctor_set(v___x_1437_, 1, v___x_1436_);
v_a_1415_ = v___x_1437_;
goto v___jp_1414_;
}
else
{
lean_object* v___x_1438_; 
lean_dec_ref_known(v___x_1432_, 2);
v___x_1438_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1438_, 0, v_fst_1420_);
lean_ctor_set(v___x_1438_, 1, v_snd_1421_);
v_a_1415_ = v___x_1438_;
goto v___jp_1414_;
}
}
}
}
v___jp_1414_:
{
size_t v___x_1416_; size_t v___x_1417_; 
v___x_1416_ = ((size_t)1ULL);
v___x_1417_ = lean_usize_add(v_i_1412_, v___x_1416_);
v_i_1412_ = v___x_1417_;
v_b_1413_ = v_a_1415_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_dedupFindings_spec__2___boxed(lean_object* v_as_1441_, lean_object* v_sz_1442_, lean_object* v_i_1443_, lean_object* v_b_1444_){
_start:
{
size_t v_sz_boxed_1445_; size_t v_i_boxed_1446_; lean_object* v_res_1447_; 
v_sz_boxed_1445_ = lean_unbox_usize(v_sz_1442_);
lean_dec(v_sz_1442_);
v_i_boxed_1446_ = lean_unbox_usize(v_i_1443_);
lean_dec(v_i_1443_);
v_res_1447_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_dedupFindings_spec__2(v_as_1441_, v_sz_boxed_1445_, v_i_boxed_1446_, v_b_1444_);
lean_dec_ref(v_as_1441_);
return v_res_1447_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_dedupFindings___closed__0(void){
_start:
{
lean_object* v___x_1448_; lean_object* v___x_1449_; lean_object* v___x_1450_; 
v___x_1448_ = lean_box(0);
v___x_1449_ = lean_unsigned_to_nat(16u);
v___x_1450_ = lean_mk_array(v___x_1449_, v___x_1448_);
return v___x_1450_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_dedupFindings___closed__1(void){
_start:
{
lean_object* v___x_1451_; lean_object* v___x_1452_; lean_object* v_seen_1453_; 
v___x_1451_ = lean_obj_once(&lp_JunkValues_JunkValues_dedupFindings___closed__0, &lp_JunkValues_JunkValues_dedupFindings___closed__0_once, _init_lp_JunkValues_JunkValues_dedupFindings___closed__0);
v___x_1452_ = lean_unsigned_to_nat(0u);
v_seen_1453_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_seen_1453_, 0, v___x_1452_);
lean_ctor_set(v_seen_1453_, 1, v___x_1451_);
return v_seen_1453_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_dedupFindings___closed__2(void){
_start:
{
lean_object* v_out_1454_; lean_object* v_seen_1455_; lean_object* v___x_1456_; 
v_out_1454_ = ((lean_object*)(lp_JunkValues_JunkValues_instInhabitedDeclScan_default___closed__0));
v_seen_1455_ = lean_obj_once(&lp_JunkValues_JunkValues_dedupFindings___closed__1, &lp_JunkValues_JunkValues_dedupFindings___closed__1_once, _init_lp_JunkValues_JunkValues_dedupFindings___closed__1);
v___x_1456_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1456_, 0, v_seen_1455_);
lean_ctor_set(v___x_1456_, 1, v_out_1454_);
return v___x_1456_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_dedupFindings(lean_object* v_findings_1457_){
_start:
{
lean_object* v___x_1458_; size_t v_sz_1459_; size_t v___x_1460_; lean_object* v___x_1461_; lean_object* v_snd_1462_; 
v___x_1458_ = lean_obj_once(&lp_JunkValues_JunkValues_dedupFindings___closed__2, &lp_JunkValues_JunkValues_dedupFindings___closed__2_once, _init_lp_JunkValues_JunkValues_dedupFindings___closed__2);
v_sz_1459_ = lean_array_size(v_findings_1457_);
v___x_1460_ = ((size_t)0ULL);
v___x_1461_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_dedupFindings_spec__2(v_findings_1457_, v_sz_1459_, v___x_1460_, v___x_1458_);
v_snd_1462_ = lean_ctor_get(v___x_1461_, 1);
lean_inc(v_snd_1462_);
lean_dec_ref(v___x_1461_);
return v_snd_1462_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_dedupFindings___boxed(lean_object* v_findings_1463_){
_start:
{
lean_object* v_res_1464_; 
v_res_1464_ = lp_JunkValues_JunkValues_dedupFindings(v_findings_1463_);
lean_dec_ref(v_findings_1463_);
return v_res_1464_;
}
}
LEAN_EXPORT uint8_t lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_dedupFindings_spec__0(lean_object* v_00_u03b2_1465_, lean_object* v_m_1466_, lean_object* v_a_1467_){
_start:
{
uint8_t v___x_1468_; 
v___x_1468_ = lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_dedupFindings_spec__0___redArg(v_m_1466_, v_a_1467_);
return v___x_1468_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_dedupFindings_spec__0___boxed(lean_object* v_00_u03b2_1469_, lean_object* v_m_1470_, lean_object* v_a_1471_){
_start:
{
uint8_t v_res_1472_; lean_object* v_r_1473_; 
v_res_1472_ = lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_dedupFindings_spec__0(v_00_u03b2_1469_, v_m_1470_, v_a_1471_);
lean_dec_ref(v_a_1471_);
lean_dec_ref(v_m_1470_);
v_r_1473_ = lean_box(v_res_1472_);
return v_r_1473_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_dedupFindings_spec__1(lean_object* v_00_u03b2_1474_, lean_object* v_m_1475_, lean_object* v_a_1476_, lean_object* v_b_1477_){
_start:
{
lean_object* v___x_1478_; 
v___x_1478_ = lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_dedupFindings_spec__1___redArg(v_m_1475_, v_a_1476_, v_b_1477_);
return v___x_1478_;
}
}
LEAN_EXPORT uint8_t lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_dedupFindings_spec__0_spec__0(lean_object* v_00_u03b2_1479_, lean_object* v_a_1480_, lean_object* v_x_1481_){
_start:
{
uint8_t v___x_1482_; 
v___x_1482_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_dedupFindings_spec__0_spec__0___redArg(v_a_1480_, v_x_1481_);
return v___x_1482_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_dedupFindings_spec__0_spec__0___boxed(lean_object* v_00_u03b2_1483_, lean_object* v_a_1484_, lean_object* v_x_1485_){
_start:
{
uint8_t v_res_1486_; lean_object* v_r_1487_; 
v_res_1486_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_dedupFindings_spec__0_spec__0(v_00_u03b2_1483_, v_a_1484_, v_x_1485_);
lean_dec(v_x_1485_);
lean_dec_ref(v_a_1484_);
v_r_1487_ = lean_box(v_res_1486_);
return v_r_1487_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_dedupFindings_spec__1_spec__2(lean_object* v_00_u03b2_1488_, lean_object* v_data_1489_){
_start:
{
lean_object* v___x_1490_; 
v___x_1490_ = lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_dedupFindings_spec__1_spec__2___redArg(v_data_1489_);
return v___x_1490_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_dedupFindings_spec__1_spec__2_spec__3(lean_object* v_00_u03b2_1491_, lean_object* v_i_1492_, lean_object* v_source_1493_, lean_object* v_target_1494_){
_start:
{
lean_object* v___x_1495_; 
v___x_1495_ = lp_JunkValues___private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_dedupFindings_spec__1_spec__2_spec__3___redArg(v_i_1492_, v_source_1493_, v_target_1494_);
return v___x_1495_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00__private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_dedupFindings_spec__1_spec__2_spec__3_spec__5(lean_object* v_00_u03b2_1496_, lean_object* v_x_1497_, lean_object* v_x_1498_){
_start:
{
lean_object* v___x_1499_; 
v___x_1499_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00__private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_dedupFindings_spec__1_spec__2_spec__3_spec__5___redArg(v_x_1497_, v_x_1498_);
return v___x_1499_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_String_Slice_Pos_skipWhile___at___00JunkValues_isCompilerGenerated_spec__0(lean_object* v_s_1500_, lean_object* v_pos_1501_){
_start:
{
lean_object* v_str_1502_; lean_object* v_startInclusive_1503_; lean_object* v_endExclusive_1504_; lean_object* v___x_1505_; uint8_t v___y_1507_; lean_object* v___x_1513_; lean_object* v___x_1514_; uint8_t v___x_1515_; 
v_str_1502_ = lean_ctor_get(v_s_1500_, 0);
v_startInclusive_1503_ = lean_ctor_get(v_s_1500_, 1);
v_endExclusive_1504_ = lean_ctor_get(v_s_1500_, 2);
v___x_1505_ = lean_nat_add(v_startInclusive_1503_, v_pos_1501_);
v___x_1513_ = lean_unsigned_to_nat(0u);
v___x_1514_ = lean_nat_sub(v_endExclusive_1504_, v___x_1505_);
v___x_1515_ = lean_nat_dec_eq(v___x_1513_, v___x_1514_);
lean_dec(v___x_1514_);
if (v___x_1515_ == 0)
{
uint32_t v___x_1516_; uint32_t v___x_1517_; uint8_t v___x_1518_; 
v___x_1516_ = lean_string_utf8_get_fast(v_str_1502_, v___x_1505_);
v___x_1517_ = 48;
v___x_1518_ = lean_uint32_dec_le(v___x_1517_, v___x_1516_);
if (v___x_1518_ == 0)
{
v___y_1507_ = v___x_1518_;
goto v___jp_1506_;
}
else
{
uint32_t v___x_1519_; uint8_t v___x_1520_; 
v___x_1519_ = 57;
v___x_1520_ = lean_uint32_dec_le(v___x_1516_, v___x_1519_);
v___y_1507_ = v___x_1520_;
goto v___jp_1506_;
}
}
else
{
lean_dec(v___x_1505_);
return v_pos_1501_;
}
v___jp_1506_:
{
if (v___y_1507_ == 0)
{
lean_dec(v___x_1505_);
return v_pos_1501_;
}
else
{
lean_object* v___x_1508_; lean_object* v___x_1509_; lean_object* v___x_1510_; uint8_t v___x_1511_; 
v___x_1508_ = lean_string_utf8_next_fast(v_str_1502_, v___x_1505_);
v___x_1509_ = lean_nat_sub(v___x_1508_, v___x_1505_);
lean_dec(v___x_1505_);
v___x_1510_ = lean_nat_add(v_pos_1501_, v___x_1509_);
lean_dec(v___x_1509_);
v___x_1511_ = lean_nat_dec_lt(v_pos_1501_, v___x_1510_);
if (v___x_1511_ == 0)
{
lean_dec(v___x_1510_);
return v_pos_1501_;
}
else
{
lean_dec(v_pos_1501_);
v_pos_1501_ = v___x_1510_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_String_Slice_Pos_skipWhile___at___00JunkValues_isCompilerGenerated_spec__0___boxed(lean_object* v_s_1521_, lean_object* v_pos_1522_){
_start:
{
lean_object* v_res_1523_; 
v_res_1523_ = lp_JunkValues_String_Slice_Pos_skipWhile___at___00JunkValues_isCompilerGenerated_spec__0(v_s_1521_, v_pos_1522_);
lean_dec_ref(v_s_1521_);
return v_res_1523_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_isCompilerGenerated___closed__5(void){
_start:
{
lean_object* v___x_1529_; lean_object* v___x_1530_; 
v___x_1529_ = ((lean_object*)(lp_JunkValues_JunkValues_isCompilerGenerated___closed__4));
v___x_1530_ = lean_string_utf8_byte_size(v___x_1529_);
return v___x_1530_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_isCompilerGenerated___closed__7(void){
_start:
{
lean_object* v___x_1532_; lean_object* v___x_1533_; 
v___x_1532_ = ((lean_object*)(lp_JunkValues_JunkValues_isCompilerGenerated___closed__6));
v___x_1533_ = lean_string_utf8_byte_size(v___x_1532_);
return v___x_1533_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_isCompilerGenerated___closed__9(void){
_start:
{
lean_object* v___x_1535_; lean_object* v___x_1536_; 
v___x_1535_ = ((lean_object*)(lp_JunkValues_JunkValues_isCompilerGenerated___closed__8));
v___x_1536_ = lean_string_utf8_byte_size(v___x_1535_);
return v___x_1536_;
}
}
LEAN_EXPORT uint8_t lp_JunkValues_JunkValues_isCompilerGenerated(lean_object* v_x_1537_){
_start:
{
switch(lean_obj_tag(v_x_1537_))
{
case 0:
{
uint8_t v___x_1538_; 
v___x_1538_ = 0;
return v___x_1538_;
}
case 1:
{
lean_object* v_pre_1539_; lean_object* v_str_1540_; uint8_t v___y_1552_; uint8_t v___y_1569_; lean_object* v___x_1585_; lean_object* v___x_1586_; lean_object* v___x_1587_; uint8_t v___x_1588_; 
v_pre_1539_ = lean_ctor_get(v_x_1537_, 0);
v_str_1540_ = lean_ctor_get(v_x_1537_, 1);
v___x_1585_ = ((lean_object*)(lp_JunkValues_JunkValues_isCompilerGenerated___closed__8));
v___x_1586_ = lean_string_utf8_byte_size(v_str_1540_);
v___x_1587_ = lean_obj_once(&lp_JunkValues_JunkValues_isCompilerGenerated___closed__9, &lp_JunkValues_JunkValues_isCompilerGenerated___closed__9_once, _init_lp_JunkValues_JunkValues_isCompilerGenerated___closed__9);
v___x_1588_ = lean_nat_dec_le(v___x_1587_, v___x_1586_);
if (v___x_1588_ == 0)
{
goto v___jp_1570_;
}
else
{
lean_object* v___x_1589_; uint8_t v___x_1590_; 
v___x_1589_ = lean_unsigned_to_nat(0u);
v___x_1590_ = lean_string_memcmp(v_str_1540_, v___x_1585_, v___x_1589_, v___x_1589_, v___x_1587_);
if (v___x_1590_ == 0)
{
goto v___jp_1570_;
}
else
{
return v___x_1590_;
}
}
v___jp_1541_:
{
lean_object* v___x_1542_; uint8_t v___x_1543_; 
v___x_1542_ = ((lean_object*)(lp_JunkValues_JunkValues_isCompilerGenerated___closed__0));
v___x_1543_ = lean_string_dec_eq(v_str_1540_, v___x_1542_);
if (v___x_1543_ == 0)
{
lean_object* v___x_1544_; uint8_t v___x_1545_; 
v___x_1544_ = ((lean_object*)(lp_JunkValues_JunkValues_isCompilerGenerated___closed__1));
v___x_1545_ = lean_string_dec_eq(v_str_1540_, v___x_1544_);
if (v___x_1545_ == 0)
{
lean_object* v___x_1546_; uint8_t v___x_1547_; 
v___x_1546_ = ((lean_object*)(lp_JunkValues_JunkValues_isCompilerGenerated___closed__2));
v___x_1547_ = lean_string_dec_eq(v_str_1540_, v___x_1546_);
if (v___x_1547_ == 0)
{
lean_object* v___x_1548_; uint8_t v___x_1549_; 
v___x_1548_ = ((lean_object*)(lp_JunkValues_JunkValues_isCompilerGenerated___closed__3));
v___x_1549_ = lean_string_dec_eq(v_str_1540_, v___x_1548_);
if (v___x_1549_ == 0)
{
v_x_1537_ = v_pre_1539_;
goto _start;
}
else
{
return v___x_1549_;
}
}
else
{
return v___x_1547_;
}
}
else
{
return v___x_1545_;
}
}
else
{
return v___x_1543_;
}
}
v___jp_1551_:
{
if (v___y_1552_ == 0)
{
goto v___jp_1541_;
}
else
{
return v___y_1552_;
}
}
v___jp_1553_:
{
lean_object* v___x_1554_; lean_object* v___x_1555_; lean_object* v___x_1556_; uint8_t v___x_1557_; 
v___x_1554_ = ((lean_object*)(lp_JunkValues_JunkValues_isCompilerGenerated___closed__4));
v___x_1555_ = lean_string_utf8_byte_size(v_str_1540_);
v___x_1556_ = lean_obj_once(&lp_JunkValues_JunkValues_isCompilerGenerated___closed__5, &lp_JunkValues_JunkValues_isCompilerGenerated___closed__5_once, _init_lp_JunkValues_JunkValues_isCompilerGenerated___closed__5);
v___x_1557_ = lean_nat_dec_le(v___x_1556_, v___x_1555_);
if (v___x_1557_ == 0)
{
goto v___jp_1541_;
}
else
{
lean_object* v___x_1558_; uint8_t v___x_1559_; 
v___x_1558_ = lean_unsigned_to_nat(0u);
v___x_1559_ = lean_string_memcmp(v_str_1540_, v___x_1554_, v___x_1558_, v___x_1558_, v___x_1556_);
if (v___x_1559_ == 0)
{
v___y_1552_ = v___x_1559_;
goto v___jp_1551_;
}
else
{
lean_object* v___x_1560_; lean_object* v___x_1561_; lean_object* v___x_1562_; lean_object* v___x_1563_; uint8_t v___x_1564_; 
v___x_1560_ = lean_unsigned_to_nat(3u);
lean_inc_ref(v_str_1540_);
v___x_1561_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_1561_, 0, v_str_1540_);
lean_ctor_set(v___x_1561_, 1, v___x_1558_);
lean_ctor_set(v___x_1561_, 2, v___x_1555_);
v___x_1562_ = l_String_Slice_Pos_nextn(v___x_1561_, v___x_1558_, v___x_1560_);
lean_dec_ref_known(v___x_1561_, 3);
v___x_1563_ = lean_nat_sub(v___x_1555_, v___x_1562_);
v___x_1564_ = lean_nat_dec_eq(v___x_1563_, v___x_1558_);
if (v___x_1564_ == 0)
{
lean_object* v___x_1565_; lean_object* v___x_1566_; uint8_t v___x_1567_; 
lean_inc_ref(v_str_1540_);
v___x_1565_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_1565_, 0, v_str_1540_);
lean_ctor_set(v___x_1565_, 1, v___x_1562_);
lean_ctor_set(v___x_1565_, 2, v___x_1555_);
v___x_1566_ = lp_JunkValues_String_Slice_Pos_skipWhile___at___00JunkValues_isCompilerGenerated_spec__0(v___x_1565_, v___x_1558_);
lean_dec_ref_known(v___x_1565_, 3);
v___x_1567_ = lean_nat_dec_eq(v___x_1566_, v___x_1563_);
lean_dec(v___x_1563_);
lean_dec(v___x_1566_);
v___y_1552_ = v___x_1567_;
goto v___jp_1551_;
}
else
{
lean_dec(v___x_1563_);
lean_dec(v___x_1562_);
goto v___jp_1541_;
}
}
}
}
v___jp_1568_:
{
if (v___y_1569_ == 0)
{
goto v___jp_1553_;
}
else
{
return v___y_1569_;
}
}
v___jp_1570_:
{
lean_object* v___x_1571_; lean_object* v___x_1572_; lean_object* v___x_1573_; uint8_t v___x_1574_; 
v___x_1571_ = ((lean_object*)(lp_JunkValues_JunkValues_isCompilerGenerated___closed__6));
v___x_1572_ = lean_string_utf8_byte_size(v_str_1540_);
v___x_1573_ = lean_obj_once(&lp_JunkValues_JunkValues_isCompilerGenerated___closed__7, &lp_JunkValues_JunkValues_isCompilerGenerated___closed__7_once, _init_lp_JunkValues_JunkValues_isCompilerGenerated___closed__7);
v___x_1574_ = lean_nat_dec_le(v___x_1573_, v___x_1572_);
if (v___x_1574_ == 0)
{
goto v___jp_1553_;
}
else
{
lean_object* v___x_1575_; uint8_t v___x_1576_; 
v___x_1575_ = lean_unsigned_to_nat(0u);
v___x_1576_ = lean_string_memcmp(v_str_1540_, v___x_1571_, v___x_1575_, v___x_1575_, v___x_1573_);
if (v___x_1576_ == 0)
{
v___y_1569_ = v___x_1576_;
goto v___jp_1568_;
}
else
{
lean_object* v___x_1577_; lean_object* v___x_1578_; lean_object* v___x_1579_; lean_object* v___x_1580_; uint8_t v___x_1581_; 
v___x_1577_ = lean_unsigned_to_nat(6u);
lean_inc_ref(v_str_1540_);
v___x_1578_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_1578_, 0, v_str_1540_);
lean_ctor_set(v___x_1578_, 1, v___x_1575_);
lean_ctor_set(v___x_1578_, 2, v___x_1572_);
v___x_1579_ = l_String_Slice_Pos_nextn(v___x_1578_, v___x_1575_, v___x_1577_);
lean_dec_ref_known(v___x_1578_, 3);
v___x_1580_ = lean_nat_sub(v___x_1572_, v___x_1579_);
v___x_1581_ = lean_nat_dec_eq(v___x_1580_, v___x_1575_);
if (v___x_1581_ == 0)
{
lean_object* v___x_1582_; lean_object* v___x_1583_; uint8_t v___x_1584_; 
lean_inc_ref(v_str_1540_);
v___x_1582_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_1582_, 0, v_str_1540_);
lean_ctor_set(v___x_1582_, 1, v___x_1579_);
lean_ctor_set(v___x_1582_, 2, v___x_1572_);
v___x_1583_ = lp_JunkValues_String_Slice_Pos_skipWhile___at___00JunkValues_isCompilerGenerated_spec__0(v___x_1582_, v___x_1575_);
lean_dec_ref_known(v___x_1582_, 3);
v___x_1584_ = lean_nat_dec_eq(v___x_1583_, v___x_1580_);
lean_dec(v___x_1580_);
lean_dec(v___x_1583_);
v___y_1569_ = v___x_1584_;
goto v___jp_1568_;
}
else
{
lean_dec(v___x_1580_);
lean_dec(v___x_1579_);
goto v___jp_1553_;
}
}
}
}
}
default: 
{
lean_object* v_pre_1591_; 
v_pre_1591_ = lean_ctor_get(v_x_1537_, 0);
v_x_1537_ = v_pre_1591_;
goto _start;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_isCompilerGenerated___boxed(lean_object* v_x_1593_){
_start:
{
uint8_t v_res_1594_; lean_object* v_r_1595_; 
v_res_1594_ = lp_JunkValues_JunkValues_isCompilerGenerated(v_x_1593_);
lean_dec(v_x_1593_);
v_r_1595_ = lean_box(v_res_1594_);
return v_r_1595_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00JunkValues_compilerAuxOf_spec__0(lean_object* v_decl_1596_, lean_object* v_env_1597_, lean_object* v_as_1598_, size_t v_i_1599_, size_t v_stop_1600_, lean_object* v_b_1601_){
_start:
{
lean_object* v___y_1603_; uint8_t v___x_1607_; 
v___x_1607_ = lean_usize_dec_eq(v_i_1599_, v_stop_1600_);
if (v___x_1607_ == 0)
{
lean_object* v___x_1608_; uint8_t v___y_1610_; uint8_t v___x_1612_; 
v___x_1608_ = lean_array_uget_borrowed(v_as_1598_, v_i_1599_);
v___x_1612_ = lean_name_eq(v___x_1608_, v_decl_1596_);
if (v___x_1612_ == 0)
{
uint8_t v___x_1613_; 
v___x_1613_ = l_Lean_Name_isPrefixOf(v_decl_1596_, v___x_1608_);
if (v___x_1613_ == 0)
{
v___y_1603_ = v_b_1601_;
goto v___jp_1602_;
}
else
{
uint8_t v___x_1614_; 
v___x_1614_ = lp_JunkValues_JunkValues_isCompilerGenerated(v___x_1608_);
if (v___x_1614_ == 0)
{
v___y_1610_ = v___x_1614_;
goto v___jp_1609_;
}
else
{
lean_object* v___x_1615_; 
lean_inc(v___x_1608_);
lean_inc_ref(v_env_1597_);
v___x_1615_ = l_Lean_Environment_find_x3f(v_env_1597_, v___x_1608_, v___x_1612_);
if (lean_obj_tag(v___x_1615_) == 0)
{
v___y_1610_ = v___x_1612_;
goto v___jp_1609_;
}
else
{
lean_dec_ref_known(v___x_1615_, 1);
v___y_1610_ = v___x_1614_;
goto v___jp_1609_;
}
}
}
}
else
{
v___y_1603_ = v_b_1601_;
goto v___jp_1602_;
}
v___jp_1609_:
{
if (v___y_1610_ == 0)
{
v___y_1603_ = v_b_1601_;
goto v___jp_1602_;
}
else
{
lean_object* v___x_1611_; 
lean_inc(v___x_1608_);
v___x_1611_ = lean_array_push(v_b_1601_, v___x_1608_);
v___y_1603_ = v___x_1611_;
goto v___jp_1602_;
}
}
}
else
{
lean_dec_ref(v_env_1597_);
return v_b_1601_;
}
v___jp_1602_:
{
size_t v___x_1604_; size_t v___x_1605_; 
v___x_1604_ = ((size_t)1ULL);
v___x_1605_ = lean_usize_add(v_i_1599_, v___x_1604_);
v_i_1599_ = v___x_1605_;
v_b_1601_ = v___y_1603_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00JunkValues_compilerAuxOf_spec__0___boxed(lean_object* v_decl_1616_, lean_object* v_env_1617_, lean_object* v_as_1618_, lean_object* v_i_1619_, lean_object* v_stop_1620_, lean_object* v_b_1621_){
_start:
{
size_t v_i_boxed_1622_; size_t v_stop_boxed_1623_; lean_object* v_res_1624_; 
v_i_boxed_1622_ = lean_unbox_usize(v_i_1619_);
lean_dec(v_i_1619_);
v_stop_boxed_1623_ = lean_unbox_usize(v_stop_1620_);
lean_dec(v_stop_1620_);
v_res_1624_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00JunkValues_compilerAuxOf_spec__0(v_decl_1616_, v_env_1617_, v_as_1618_, v_i_boxed_1622_, v_stop_boxed_1623_, v_b_1621_);
lean_dec_ref(v_as_1618_);
lean_dec(v_decl_1616_);
return v_res_1624_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_compilerAuxOf(lean_object* v_env_1627_, lean_object* v_decl_1628_, lean_object* v_value_1629_){
_start:
{
lean_object* v___x_1630_; lean_object* v___x_1631_; lean_object* v___x_1632_; lean_object* v___x_1633_; uint8_t v___x_1634_; 
v___x_1630_ = l_Lean_Expr_getUsedConstants(v_value_1629_);
v___x_1631_ = lean_unsigned_to_nat(0u);
v___x_1632_ = lean_array_get_size(v___x_1630_);
v___x_1633_ = ((lean_object*)(lp_JunkValues_JunkValues_compilerAuxOf___closed__0));
v___x_1634_ = lean_nat_dec_lt(v___x_1631_, v___x_1632_);
if (v___x_1634_ == 0)
{
lean_dec_ref(v___x_1630_);
lean_dec_ref(v_env_1627_);
return v___x_1633_;
}
else
{
uint8_t v___x_1635_; 
v___x_1635_ = lean_nat_dec_le(v___x_1632_, v___x_1632_);
if (v___x_1635_ == 0)
{
if (v___x_1634_ == 0)
{
lean_dec_ref(v___x_1630_);
lean_dec_ref(v_env_1627_);
return v___x_1633_;
}
else
{
size_t v___x_1636_; size_t v___x_1637_; lean_object* v___x_1638_; 
v___x_1636_ = ((size_t)0ULL);
v___x_1637_ = lean_usize_of_nat(v___x_1632_);
v___x_1638_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00JunkValues_compilerAuxOf_spec__0(v_decl_1628_, v_env_1627_, v___x_1630_, v___x_1636_, v___x_1637_, v___x_1633_);
lean_dec_ref(v___x_1630_);
return v___x_1638_;
}
}
else
{
size_t v___x_1639_; size_t v___x_1640_; lean_object* v___x_1641_; 
v___x_1639_ = ((size_t)0ULL);
v___x_1640_ = lean_usize_of_nat(v___x_1632_);
v___x_1641_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00JunkValues_compilerAuxOf_spec__0(v_decl_1628_, v_env_1627_, v___x_1630_, v___x_1639_, v___x_1640_, v___x_1633_);
lean_dec_ref(v___x_1630_);
return v___x_1641_;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_compilerAuxOf___boxed(lean_object* v_env_1642_, lean_object* v_decl_1643_, lean_object* v_value_1644_){
_start:
{
lean_object* v_res_1645_; 
v_res_1645_ = lp_JunkValues_JunkValues_compilerAuxOf(v_env_1642_, v_decl_1643_, v_value_1644_);
lean_dec(v_decl_1643_);
return v_res_1645_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00__private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_scanDecl_spec__1_spec__2_spec__3_spec__5___redArg(lean_object* v_x_1646_, lean_object* v_x_1647_){
_start:
{
if (lean_obj_tag(v_x_1647_) == 0)
{
return v_x_1646_;
}
else
{
lean_object* v_key_1648_; lean_object* v_value_1649_; lean_object* v_tail_1650_; lean_object* v___x_1652_; uint8_t v_isShared_1653_; uint8_t v_isSharedCheck_1676_; 
v_key_1648_ = lean_ctor_get(v_x_1647_, 0);
v_value_1649_ = lean_ctor_get(v_x_1647_, 1);
v_tail_1650_ = lean_ctor_get(v_x_1647_, 2);
v_isSharedCheck_1676_ = !lean_is_exclusive(v_x_1647_);
if (v_isSharedCheck_1676_ == 0)
{
v___x_1652_ = v_x_1647_;
v_isShared_1653_ = v_isSharedCheck_1676_;
goto v_resetjp_1651_;
}
else
{
lean_inc(v_tail_1650_);
lean_inc(v_value_1649_);
lean_inc(v_key_1648_);
lean_dec(v_x_1647_);
v___x_1652_ = lean_box(0);
v_isShared_1653_ = v_isSharedCheck_1676_;
goto v_resetjp_1651_;
}
v_resetjp_1651_:
{
lean_object* v___x_1654_; uint64_t v___y_1656_; 
v___x_1654_ = lean_array_get_size(v_x_1646_);
if (lean_obj_tag(v_key_1648_) == 0)
{
uint64_t v___x_1674_; 
v___x_1674_ = lean_uint64_once(&lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_dedupFindings_spec__0___redArg___closed__0, &lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_dedupFindings_spec__0___redArg___closed__0_once, _init_lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_dedupFindings_spec__0___redArg___closed__0);
v___y_1656_ = v___x_1674_;
goto v___jp_1655_;
}
else
{
uint64_t v_hash_1675_; 
v_hash_1675_ = lean_ctor_get_uint64(v_key_1648_, sizeof(void*)*2);
v___y_1656_ = v_hash_1675_;
goto v___jp_1655_;
}
v___jp_1655_:
{
uint64_t v___x_1657_; uint64_t v___x_1658_; uint64_t v_fold_1659_; uint64_t v___x_1660_; uint64_t v___x_1661_; uint64_t v___x_1662_; size_t v___x_1663_; size_t v___x_1664_; size_t v___x_1665_; size_t v___x_1666_; size_t v___x_1667_; lean_object* v___x_1668_; lean_object* v___x_1670_; 
v___x_1657_ = 32ULL;
v___x_1658_ = lean_uint64_shift_right(v___y_1656_, v___x_1657_);
v_fold_1659_ = lean_uint64_xor(v___y_1656_, v___x_1658_);
v___x_1660_ = 16ULL;
v___x_1661_ = lean_uint64_shift_right(v_fold_1659_, v___x_1660_);
v___x_1662_ = lean_uint64_xor(v_fold_1659_, v___x_1661_);
v___x_1663_ = lean_uint64_to_usize(v___x_1662_);
v___x_1664_ = lean_usize_of_nat(v___x_1654_);
v___x_1665_ = ((size_t)1ULL);
v___x_1666_ = lean_usize_sub(v___x_1664_, v___x_1665_);
v___x_1667_ = lean_usize_land(v___x_1663_, v___x_1666_);
v___x_1668_ = lean_array_uget_borrowed(v_x_1646_, v___x_1667_);
lean_inc(v___x_1668_);
if (v_isShared_1653_ == 0)
{
lean_ctor_set(v___x_1652_, 2, v___x_1668_);
v___x_1670_ = v___x_1652_;
goto v_reusejp_1669_;
}
else
{
lean_object* v_reuseFailAlloc_1673_; 
v_reuseFailAlloc_1673_ = lean_alloc_ctor(1, 3, 0);
lean_ctor_set(v_reuseFailAlloc_1673_, 0, v_key_1648_);
lean_ctor_set(v_reuseFailAlloc_1673_, 1, v_value_1649_);
lean_ctor_set(v_reuseFailAlloc_1673_, 2, v___x_1668_);
v___x_1670_ = v_reuseFailAlloc_1673_;
goto v_reusejp_1669_;
}
v_reusejp_1669_:
{
lean_object* v___x_1671_; 
v___x_1671_ = lean_array_uset(v_x_1646_, v___x_1667_, v___x_1670_);
v_x_1646_ = v___x_1671_;
v_x_1647_ = v_tail_1650_;
goto _start;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_scanDecl_spec__1_spec__2_spec__3___redArg(lean_object* v_i_1677_, lean_object* v_source_1678_, lean_object* v_target_1679_){
_start:
{
lean_object* v___x_1680_; uint8_t v___x_1681_; 
v___x_1680_ = lean_array_get_size(v_source_1678_);
v___x_1681_ = lean_nat_dec_lt(v_i_1677_, v___x_1680_);
if (v___x_1681_ == 0)
{
lean_dec_ref(v_source_1678_);
lean_dec(v_i_1677_);
return v_target_1679_;
}
else
{
lean_object* v_es_1682_; lean_object* v___x_1683_; lean_object* v_source_1684_; lean_object* v_target_1685_; lean_object* v___x_1686_; lean_object* v___x_1687_; 
v_es_1682_ = lean_array_fget(v_source_1678_, v_i_1677_);
v___x_1683_ = lean_box(0);
v_source_1684_ = lean_array_fset(v_source_1678_, v_i_1677_, v___x_1683_);
v_target_1685_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00__private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_scanDecl_spec__1_spec__2_spec__3_spec__5___redArg(v_target_1679_, v_es_1682_);
v___x_1686_ = lean_unsigned_to_nat(1u);
v___x_1687_ = lean_nat_add(v_i_1677_, v___x_1686_);
lean_dec(v_i_1677_);
v_i_1677_ = v___x_1687_;
v_source_1678_ = v_source_1684_;
v_target_1679_ = v_target_1685_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_scanDecl_spec__1_spec__2___redArg(lean_object* v_data_1689_){
_start:
{
lean_object* v___x_1690_; lean_object* v___x_1691_; lean_object* v_nbuckets_1692_; lean_object* v___x_1693_; lean_object* v___x_1694_; lean_object* v___x_1695_; lean_object* v___x_1696_; 
v___x_1690_ = lean_array_get_size(v_data_1689_);
v___x_1691_ = lean_unsigned_to_nat(2u);
v_nbuckets_1692_ = lean_nat_mul(v___x_1690_, v___x_1691_);
v___x_1693_ = lean_unsigned_to_nat(0u);
v___x_1694_ = lean_box(0);
v___x_1695_ = lean_mk_array(v_nbuckets_1692_, v___x_1694_);
v___x_1696_ = lp_JunkValues___private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_scanDecl_spec__1_spec__2_spec__3___redArg(v___x_1693_, v_data_1689_, v___x_1695_);
return v___x_1696_;
}
}
LEAN_EXPORT uint8_t lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_scanDecl_spec__0_spec__0___redArg(lean_object* v_a_1697_, lean_object* v_x_1698_){
_start:
{
if (lean_obj_tag(v_x_1698_) == 0)
{
uint8_t v___x_1699_; 
v___x_1699_ = 0;
return v___x_1699_;
}
else
{
lean_object* v_key_1700_; lean_object* v_tail_1701_; uint8_t v___x_1702_; 
v_key_1700_ = lean_ctor_get(v_x_1698_, 0);
v_tail_1701_ = lean_ctor_get(v_x_1698_, 2);
v___x_1702_ = lean_name_eq(v_key_1700_, v_a_1697_);
if (v___x_1702_ == 0)
{
v_x_1698_ = v_tail_1701_;
goto _start;
}
else
{
return v___x_1702_;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_scanDecl_spec__0_spec__0___redArg___boxed(lean_object* v_a_1704_, lean_object* v_x_1705_){
_start:
{
uint8_t v_res_1706_; lean_object* v_r_1707_; 
v_res_1706_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_scanDecl_spec__0_spec__0___redArg(v_a_1704_, v_x_1705_);
lean_dec(v_x_1705_);
lean_dec(v_a_1704_);
v_r_1707_ = lean_box(v_res_1706_);
return v_r_1707_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_scanDecl_spec__1___redArg(lean_object* v_m_1708_, lean_object* v_a_1709_, lean_object* v_b_1710_){
_start:
{
lean_object* v_size_1711_; lean_object* v_buckets_1712_; lean_object* v___x_1713_; uint64_t v___y_1715_; 
v_size_1711_ = lean_ctor_get(v_m_1708_, 0);
v_buckets_1712_ = lean_ctor_get(v_m_1708_, 1);
v___x_1713_ = lean_array_get_size(v_buckets_1712_);
if (lean_obj_tag(v_a_1709_) == 0)
{
uint64_t v___x_1752_; 
v___x_1752_ = lean_uint64_once(&lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_dedupFindings_spec__0___redArg___closed__0, &lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_dedupFindings_spec__0___redArg___closed__0_once, _init_lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_dedupFindings_spec__0___redArg___closed__0);
v___y_1715_ = v___x_1752_;
goto v___jp_1714_;
}
else
{
uint64_t v_hash_1753_; 
v_hash_1753_ = lean_ctor_get_uint64(v_a_1709_, sizeof(void*)*2);
v___y_1715_ = v_hash_1753_;
goto v___jp_1714_;
}
v___jp_1714_:
{
uint64_t v___x_1716_; uint64_t v___x_1717_; uint64_t v_fold_1718_; uint64_t v___x_1719_; uint64_t v___x_1720_; uint64_t v___x_1721_; size_t v___x_1722_; size_t v___x_1723_; size_t v___x_1724_; size_t v___x_1725_; size_t v___x_1726_; lean_object* v_bkt_1727_; uint8_t v___x_1728_; 
v___x_1716_ = 32ULL;
v___x_1717_ = lean_uint64_shift_right(v___y_1715_, v___x_1716_);
v_fold_1718_ = lean_uint64_xor(v___y_1715_, v___x_1717_);
v___x_1719_ = 16ULL;
v___x_1720_ = lean_uint64_shift_right(v_fold_1718_, v___x_1719_);
v___x_1721_ = lean_uint64_xor(v_fold_1718_, v___x_1720_);
v___x_1722_ = lean_uint64_to_usize(v___x_1721_);
v___x_1723_ = lean_usize_of_nat(v___x_1713_);
v___x_1724_ = ((size_t)1ULL);
v___x_1725_ = lean_usize_sub(v___x_1723_, v___x_1724_);
v___x_1726_ = lean_usize_land(v___x_1722_, v___x_1725_);
v_bkt_1727_ = lean_array_uget_borrowed(v_buckets_1712_, v___x_1726_);
v___x_1728_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_scanDecl_spec__0_spec__0___redArg(v_a_1709_, v_bkt_1727_);
if (v___x_1728_ == 0)
{
lean_object* v___x_1730_; uint8_t v_isShared_1731_; uint8_t v_isSharedCheck_1749_; 
lean_inc_ref(v_buckets_1712_);
lean_inc(v_size_1711_);
v_isSharedCheck_1749_ = !lean_is_exclusive(v_m_1708_);
if (v_isSharedCheck_1749_ == 0)
{
lean_object* v_unused_1750_; lean_object* v_unused_1751_; 
v_unused_1750_ = lean_ctor_get(v_m_1708_, 1);
lean_dec(v_unused_1750_);
v_unused_1751_ = lean_ctor_get(v_m_1708_, 0);
lean_dec(v_unused_1751_);
v___x_1730_ = v_m_1708_;
v_isShared_1731_ = v_isSharedCheck_1749_;
goto v_resetjp_1729_;
}
else
{
lean_dec(v_m_1708_);
v___x_1730_ = lean_box(0);
v_isShared_1731_ = v_isSharedCheck_1749_;
goto v_resetjp_1729_;
}
v_resetjp_1729_:
{
lean_object* v___x_1732_; lean_object* v_size_x27_1733_; lean_object* v___x_1734_; lean_object* v_buckets_x27_1735_; lean_object* v___x_1736_; lean_object* v___x_1737_; lean_object* v___x_1738_; lean_object* v___x_1739_; lean_object* v___x_1740_; uint8_t v___x_1741_; 
v___x_1732_ = lean_unsigned_to_nat(1u);
v_size_x27_1733_ = lean_nat_add(v_size_1711_, v___x_1732_);
lean_dec(v_size_1711_);
lean_inc(v_bkt_1727_);
v___x_1734_ = lean_alloc_ctor(1, 3, 0);
lean_ctor_set(v___x_1734_, 0, v_a_1709_);
lean_ctor_set(v___x_1734_, 1, v_b_1710_);
lean_ctor_set(v___x_1734_, 2, v_bkt_1727_);
v_buckets_x27_1735_ = lean_array_uset(v_buckets_1712_, v___x_1726_, v___x_1734_);
v___x_1736_ = lean_unsigned_to_nat(4u);
v___x_1737_ = lean_nat_mul(v_size_x27_1733_, v___x_1736_);
v___x_1738_ = lean_unsigned_to_nat(3u);
v___x_1739_ = lean_nat_div(v___x_1737_, v___x_1738_);
lean_dec(v___x_1737_);
v___x_1740_ = lean_array_get_size(v_buckets_x27_1735_);
v___x_1741_ = lean_nat_dec_le(v___x_1739_, v___x_1740_);
lean_dec(v___x_1739_);
if (v___x_1741_ == 0)
{
lean_object* v_val_1742_; lean_object* v___x_1744_; 
v_val_1742_ = lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_scanDecl_spec__1_spec__2___redArg(v_buckets_x27_1735_);
if (v_isShared_1731_ == 0)
{
lean_ctor_set(v___x_1730_, 1, v_val_1742_);
lean_ctor_set(v___x_1730_, 0, v_size_x27_1733_);
v___x_1744_ = v___x_1730_;
goto v_reusejp_1743_;
}
else
{
lean_object* v_reuseFailAlloc_1745_; 
v_reuseFailAlloc_1745_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1745_, 0, v_size_x27_1733_);
lean_ctor_set(v_reuseFailAlloc_1745_, 1, v_val_1742_);
v___x_1744_ = v_reuseFailAlloc_1745_;
goto v_reusejp_1743_;
}
v_reusejp_1743_:
{
return v___x_1744_;
}
}
else
{
lean_object* v___x_1747_; 
if (v_isShared_1731_ == 0)
{
lean_ctor_set(v___x_1730_, 1, v_buckets_x27_1735_);
lean_ctor_set(v___x_1730_, 0, v_size_x27_1733_);
v___x_1747_ = v___x_1730_;
goto v_reusejp_1746_;
}
else
{
lean_object* v_reuseFailAlloc_1748_; 
v_reuseFailAlloc_1748_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1748_, 0, v_size_x27_1733_);
lean_ctor_set(v_reuseFailAlloc_1748_, 1, v_buckets_x27_1735_);
v___x_1747_ = v_reuseFailAlloc_1748_;
goto v_reusejp_1746_;
}
v_reusejp_1746_:
{
return v___x_1747_;
}
}
}
}
else
{
lean_dec(v_b_1710_);
lean_dec(v_a_1709_);
return v_m_1708_;
}
}
}
}
LEAN_EXPORT uint8_t lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_scanDecl_spec__0___redArg(lean_object* v_m_1754_, lean_object* v_a_1755_){
_start:
{
lean_object* v_buckets_1756_; lean_object* v___x_1757_; uint64_t v___y_1759_; 
v_buckets_1756_ = lean_ctor_get(v_m_1754_, 1);
v___x_1757_ = lean_array_get_size(v_buckets_1756_);
if (lean_obj_tag(v_a_1755_) == 0)
{
uint64_t v___x_1773_; 
v___x_1773_ = lean_uint64_once(&lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_dedupFindings_spec__0___redArg___closed__0, &lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_dedupFindings_spec__0___redArg___closed__0_once, _init_lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_dedupFindings_spec__0___redArg___closed__0);
v___y_1759_ = v___x_1773_;
goto v___jp_1758_;
}
else
{
uint64_t v_hash_1774_; 
v_hash_1774_ = lean_ctor_get_uint64(v_a_1755_, sizeof(void*)*2);
v___y_1759_ = v_hash_1774_;
goto v___jp_1758_;
}
v___jp_1758_:
{
uint64_t v___x_1760_; uint64_t v___x_1761_; uint64_t v_fold_1762_; uint64_t v___x_1763_; uint64_t v___x_1764_; uint64_t v___x_1765_; size_t v___x_1766_; size_t v___x_1767_; size_t v___x_1768_; size_t v___x_1769_; size_t v___x_1770_; lean_object* v___x_1771_; uint8_t v___x_1772_; 
v___x_1760_ = 32ULL;
v___x_1761_ = lean_uint64_shift_right(v___y_1759_, v___x_1760_);
v_fold_1762_ = lean_uint64_xor(v___y_1759_, v___x_1761_);
v___x_1763_ = 16ULL;
v___x_1764_ = lean_uint64_shift_right(v_fold_1762_, v___x_1763_);
v___x_1765_ = lean_uint64_xor(v_fold_1762_, v___x_1764_);
v___x_1766_ = lean_uint64_to_usize(v___x_1765_);
v___x_1767_ = lean_usize_of_nat(v___x_1757_);
v___x_1768_ = ((size_t)1ULL);
v___x_1769_ = lean_usize_sub(v___x_1767_, v___x_1768_);
v___x_1770_ = lean_usize_land(v___x_1766_, v___x_1769_);
v___x_1771_ = lean_array_uget_borrowed(v_buckets_1756_, v___x_1770_);
v___x_1772_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_scanDecl_spec__0_spec__0___redArg(v_a_1755_, v___x_1771_);
return v___x_1772_;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_scanDecl_spec__0___redArg___boxed(lean_object* v_m_1775_, lean_object* v_a_1776_){
_start:
{
uint8_t v_res_1777_; lean_object* v_r_1778_; 
v_res_1777_ = lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_scanDecl_spec__0___redArg(v_m_1775_, v_a_1776_);
lean_dec(v_a_1776_);
lean_dec_ref(v_m_1775_);
v_r_1778_ = lean_box(v_res_1777_);
return v_r_1778_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_While_0__repeatM_erased___at___00JunkValues_scanDecl_spec__2___redArg(lean_object* v_cfg_1779_, lean_object* v_rs_1780_, lean_object* v_name_1781_, lean_object* v_a_1782_, lean_object* v___y_1783_, lean_object* v___y_1784_, lean_object* v___y_1785_, lean_object* v___y_1786_){
_start:
{
lean_object* v_snd_1788_; lean_object* v_fst_1789_; lean_object* v___x_1791_; uint8_t v_isShared_1792_; uint8_t v_isSharedCheck_1875_; 
v_snd_1788_ = lean_ctor_get(v_a_1782_, 1);
v_fst_1789_ = lean_ctor_get(v_a_1782_, 0);
v_isSharedCheck_1875_ = !lean_is_exclusive(v_a_1782_);
if (v_isSharedCheck_1875_ == 0)
{
v___x_1791_ = v_a_1782_;
v_isShared_1792_ = v_isSharedCheck_1875_;
goto v_resetjp_1790_;
}
else
{
lean_inc(v_snd_1788_);
lean_inc(v_fst_1789_);
lean_dec(v_a_1782_);
v___x_1791_ = lean_box(0);
v_isShared_1792_ = v_isSharedCheck_1875_;
goto v_resetjp_1790_;
}
v_resetjp_1790_:
{
lean_object* v_fst_1793_; lean_object* v_snd_1794_; lean_object* v___x_1796_; uint8_t v_isShared_1797_; uint8_t v_isSharedCheck_1874_; 
v_fst_1793_ = lean_ctor_get(v_snd_1788_, 0);
v_snd_1794_ = lean_ctor_get(v_snd_1788_, 1);
v_isSharedCheck_1874_ = !lean_is_exclusive(v_snd_1788_);
if (v_isSharedCheck_1874_ == 0)
{
v___x_1796_ = v_snd_1788_;
v_isShared_1797_ = v_isSharedCheck_1874_;
goto v_resetjp_1795_;
}
else
{
lean_inc(v_snd_1794_);
lean_inc(v_fst_1793_);
lean_dec(v_snd_1788_);
v___x_1796_ = lean_box(0);
v_isShared_1797_ = v_isSharedCheck_1874_;
goto v_resetjp_1795_;
}
v_resetjp_1795_:
{
lean_object* v___x_1798_; lean_object* v___x_1799_; uint8_t v___x_1800_; 
v___x_1798_ = lean_unsigned_to_nat(0u);
v___x_1799_ = lean_array_get_size(v_fst_1793_);
v___x_1800_ = lean_nat_dec_lt(v___x_1798_, v___x_1799_);
if (v___x_1800_ == 0)
{
lean_object* v___x_1802_; 
lean_dec(v_name_1781_);
lean_dec_ref(v_rs_1780_);
lean_dec_ref(v_cfg_1779_);
if (v_isShared_1797_ == 0)
{
v___x_1802_ = v___x_1796_;
goto v_reusejp_1801_;
}
else
{
lean_object* v_reuseFailAlloc_1807_; 
v_reuseFailAlloc_1807_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1807_, 0, v_fst_1793_);
lean_ctor_set(v_reuseFailAlloc_1807_, 1, v_snd_1794_);
v___x_1802_ = v_reuseFailAlloc_1807_;
goto v_reusejp_1801_;
}
v_reusejp_1801_:
{
lean_object* v___x_1804_; 
if (v_isShared_1792_ == 0)
{
lean_ctor_set(v___x_1791_, 1, v___x_1802_);
v___x_1804_ = v___x_1791_;
goto v_reusejp_1803_;
}
else
{
lean_object* v_reuseFailAlloc_1806_; 
v_reuseFailAlloc_1806_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1806_, 0, v_fst_1789_);
lean_ctor_set(v_reuseFailAlloc_1806_, 1, v___x_1802_);
v___x_1804_ = v_reuseFailAlloc_1806_;
goto v_reusejp_1803_;
}
v_reusejp_1803_:
{
lean_object* v___x_1805_; 
v___x_1805_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1805_, 0, v___x_1804_);
return v___x_1805_;
}
}
}
else
{
lean_object* v___x_1808_; lean_object* v___x_1809_; lean_object* v___x_1810_; lean_object* v___x_1811_; uint8_t v___x_1812_; 
v___x_1808_ = lean_unsigned_to_nat(1u);
v___x_1809_ = lean_nat_sub(v___x_1799_, v___x_1808_);
v___x_1810_ = lean_array_fget(v_fst_1793_, v___x_1809_);
lean_dec(v___x_1809_);
v___x_1811_ = lean_array_pop(v_fst_1793_);
v___x_1812_ = lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_scanDecl_spec__0___redArg(v_snd_1794_, v___x_1810_);
if (v___x_1812_ == 0)
{
lean_object* v_maxPerDecl_1813_; lean_object* v___x_1814_; lean_object* v___x_1815_; lean_object* v___x_1816_; uint8_t v___x_1817_; 
v_maxPerDecl_1813_ = lean_ctor_get(v_cfg_1779_, 1);
v___x_1814_ = lean_box(0);
lean_inc(v___x_1810_);
v___x_1815_ = lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_scanDecl_spec__1___redArg(v_snd_1794_, v___x_1810_, v___x_1814_);
v___x_1816_ = lean_array_get_size(v_fst_1789_);
v___x_1817_ = lean_nat_dec_le(v_maxPerDecl_1813_, v___x_1816_);
if (v___x_1817_ == 0)
{
lean_object* v___x_1818_; lean_object* v_env_1819_; lean_object* v___x_1820_; 
v___x_1818_ = lean_st_ref_get(v___y_1786_);
v_env_1819_ = lean_ctor_get(v___x_1818_, 0);
lean_inc_ref(v_env_1819_);
lean_dec(v___x_1818_);
v___x_1820_ = l_Lean_Environment_find_x3f(v_env_1819_, v___x_1810_, v___x_1812_);
if (lean_obj_tag(v___x_1820_) == 1)
{
lean_object* v_val_1821_; lean_object* v___x_1822_; 
v_val_1821_ = lean_ctor_get(v___x_1820_, 0);
lean_inc(v_val_1821_);
lean_dec_ref_known(v___x_1820_, 1);
v___x_1822_ = l_Lean_ConstantInfo_value_x3f(v_val_1821_, v___x_1812_);
if (lean_obj_tag(v___x_1822_) == 1)
{
lean_object* v_val_1823_; uint8_t v___x_1824_; lean_object* v___x_1825_; 
v_val_1823_ = lean_ctor_get(v___x_1822_, 0);
lean_inc_n(v_val_1823_, 2);
lean_dec_ref_known(v___x_1822_, 1);
v___x_1824_ = 1;
lean_inc(v_name_1781_);
lean_inc_ref(v_cfg_1779_);
lean_inc_ref(v_rs_1780_);
v___x_1825_ = lp_JunkValues_JunkValues_visit(v_rs_1780_, v_cfg_1779_, v_name_1781_, v___x_1824_, v_val_1823_, v_fst_1789_, v___y_1783_, v___y_1784_, v___y_1785_, v___y_1786_);
if (lean_obj_tag(v___x_1825_) == 0)
{
lean_object* v_a_1826_; lean_object* v___x_1827_; lean_object* v_env_1828_; lean_object* v___x_1829_; lean_object* v___x_1830_; lean_object* v___x_1832_; 
v_a_1826_ = lean_ctor_get(v___x_1825_, 0);
lean_inc(v_a_1826_);
lean_dec_ref_known(v___x_1825_, 1);
v___x_1827_ = lean_st_ref_get(v___y_1786_);
v_env_1828_ = lean_ctor_get(v___x_1827_, 0);
lean_inc_ref(v_env_1828_);
lean_dec(v___x_1827_);
v___x_1829_ = lp_JunkValues_JunkValues_compilerAuxOf(v_env_1828_, v_name_1781_, v_val_1823_);
v___x_1830_ = l_Array_append___redArg(v___x_1811_, v___x_1829_);
lean_dec_ref(v___x_1829_);
if (v_isShared_1797_ == 0)
{
lean_ctor_set(v___x_1796_, 1, v___x_1815_);
lean_ctor_set(v___x_1796_, 0, v___x_1830_);
v___x_1832_ = v___x_1796_;
goto v_reusejp_1831_;
}
else
{
lean_object* v_reuseFailAlloc_1837_; 
v_reuseFailAlloc_1837_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1837_, 0, v___x_1830_);
lean_ctor_set(v_reuseFailAlloc_1837_, 1, v___x_1815_);
v___x_1832_ = v_reuseFailAlloc_1837_;
goto v_reusejp_1831_;
}
v_reusejp_1831_:
{
lean_object* v___x_1834_; 
if (v_isShared_1792_ == 0)
{
lean_ctor_set(v___x_1791_, 1, v___x_1832_);
lean_ctor_set(v___x_1791_, 0, v_a_1826_);
v___x_1834_ = v___x_1791_;
goto v_reusejp_1833_;
}
else
{
lean_object* v_reuseFailAlloc_1836_; 
v_reuseFailAlloc_1836_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1836_, 0, v_a_1826_);
lean_ctor_set(v_reuseFailAlloc_1836_, 1, v___x_1832_);
v___x_1834_ = v_reuseFailAlloc_1836_;
goto v_reusejp_1833_;
}
v_reusejp_1833_:
{
v_a_1782_ = v___x_1834_;
goto _start;
}
}
}
else
{
lean_object* v_a_1838_; lean_object* v___x_1840_; uint8_t v_isShared_1841_; uint8_t v_isSharedCheck_1845_; 
lean_dec(v_val_1823_);
lean_dec_ref(v___x_1815_);
lean_dec_ref(v___x_1811_);
lean_del_object(v___x_1796_);
lean_del_object(v___x_1791_);
lean_dec(v_name_1781_);
lean_dec_ref(v_rs_1780_);
lean_dec_ref(v_cfg_1779_);
v_a_1838_ = lean_ctor_get(v___x_1825_, 0);
v_isSharedCheck_1845_ = !lean_is_exclusive(v___x_1825_);
if (v_isSharedCheck_1845_ == 0)
{
v___x_1840_ = v___x_1825_;
v_isShared_1841_ = v_isSharedCheck_1845_;
goto v_resetjp_1839_;
}
else
{
lean_inc(v_a_1838_);
lean_dec(v___x_1825_);
v___x_1840_ = lean_box(0);
v_isShared_1841_ = v_isSharedCheck_1845_;
goto v_resetjp_1839_;
}
v_resetjp_1839_:
{
lean_object* v___x_1843_; 
if (v_isShared_1841_ == 0)
{
v___x_1843_ = v___x_1840_;
goto v_reusejp_1842_;
}
else
{
lean_object* v_reuseFailAlloc_1844_; 
v_reuseFailAlloc_1844_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1844_, 0, v_a_1838_);
v___x_1843_ = v_reuseFailAlloc_1844_;
goto v_reusejp_1842_;
}
v_reusejp_1842_:
{
return v___x_1843_;
}
}
}
}
else
{
lean_object* v___x_1847_; 
lean_dec(v___x_1822_);
if (v_isShared_1797_ == 0)
{
lean_ctor_set(v___x_1796_, 1, v___x_1815_);
lean_ctor_set(v___x_1796_, 0, v___x_1811_);
v___x_1847_ = v___x_1796_;
goto v_reusejp_1846_;
}
else
{
lean_object* v_reuseFailAlloc_1852_; 
v_reuseFailAlloc_1852_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1852_, 0, v___x_1811_);
lean_ctor_set(v_reuseFailAlloc_1852_, 1, v___x_1815_);
v___x_1847_ = v_reuseFailAlloc_1852_;
goto v_reusejp_1846_;
}
v_reusejp_1846_:
{
lean_object* v___x_1849_; 
if (v_isShared_1792_ == 0)
{
lean_ctor_set(v___x_1791_, 1, v___x_1847_);
v___x_1849_ = v___x_1791_;
goto v_reusejp_1848_;
}
else
{
lean_object* v_reuseFailAlloc_1851_; 
v_reuseFailAlloc_1851_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1851_, 0, v_fst_1789_);
lean_ctor_set(v_reuseFailAlloc_1851_, 1, v___x_1847_);
v___x_1849_ = v_reuseFailAlloc_1851_;
goto v_reusejp_1848_;
}
v_reusejp_1848_:
{
v_a_1782_ = v___x_1849_;
goto _start;
}
}
}
}
else
{
lean_object* v___x_1854_; 
lean_dec(v___x_1820_);
if (v_isShared_1797_ == 0)
{
lean_ctor_set(v___x_1796_, 1, v___x_1815_);
lean_ctor_set(v___x_1796_, 0, v___x_1811_);
v___x_1854_ = v___x_1796_;
goto v_reusejp_1853_;
}
else
{
lean_object* v_reuseFailAlloc_1859_; 
v_reuseFailAlloc_1859_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1859_, 0, v___x_1811_);
lean_ctor_set(v_reuseFailAlloc_1859_, 1, v___x_1815_);
v___x_1854_ = v_reuseFailAlloc_1859_;
goto v_reusejp_1853_;
}
v_reusejp_1853_:
{
lean_object* v___x_1856_; 
if (v_isShared_1792_ == 0)
{
lean_ctor_set(v___x_1791_, 1, v___x_1854_);
v___x_1856_ = v___x_1791_;
goto v_reusejp_1855_;
}
else
{
lean_object* v_reuseFailAlloc_1858_; 
v_reuseFailAlloc_1858_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1858_, 0, v_fst_1789_);
lean_ctor_set(v_reuseFailAlloc_1858_, 1, v___x_1854_);
v___x_1856_ = v_reuseFailAlloc_1858_;
goto v_reusejp_1855_;
}
v_reusejp_1855_:
{
v_a_1782_ = v___x_1856_;
goto _start;
}
}
}
}
else
{
lean_object* v___x_1861_; 
lean_dec(v___x_1810_);
lean_dec(v_name_1781_);
lean_dec_ref(v_rs_1780_);
lean_dec_ref(v_cfg_1779_);
if (v_isShared_1797_ == 0)
{
lean_ctor_set(v___x_1796_, 1, v___x_1815_);
lean_ctor_set(v___x_1796_, 0, v___x_1811_);
v___x_1861_ = v___x_1796_;
goto v_reusejp_1860_;
}
else
{
lean_object* v_reuseFailAlloc_1866_; 
v_reuseFailAlloc_1866_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1866_, 0, v___x_1811_);
lean_ctor_set(v_reuseFailAlloc_1866_, 1, v___x_1815_);
v___x_1861_ = v_reuseFailAlloc_1866_;
goto v_reusejp_1860_;
}
v_reusejp_1860_:
{
lean_object* v___x_1863_; 
if (v_isShared_1792_ == 0)
{
lean_ctor_set(v___x_1791_, 1, v___x_1861_);
v___x_1863_ = v___x_1791_;
goto v_reusejp_1862_;
}
else
{
lean_object* v_reuseFailAlloc_1865_; 
v_reuseFailAlloc_1865_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1865_, 0, v_fst_1789_);
lean_ctor_set(v_reuseFailAlloc_1865_, 1, v___x_1861_);
v___x_1863_ = v_reuseFailAlloc_1865_;
goto v_reusejp_1862_;
}
v_reusejp_1862_:
{
lean_object* v___x_1864_; 
v___x_1864_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1864_, 0, v___x_1863_);
return v___x_1864_;
}
}
}
}
else
{
lean_object* v___x_1868_; 
lean_dec(v___x_1810_);
if (v_isShared_1797_ == 0)
{
lean_ctor_set(v___x_1796_, 0, v___x_1811_);
v___x_1868_ = v___x_1796_;
goto v_reusejp_1867_;
}
else
{
lean_object* v_reuseFailAlloc_1873_; 
v_reuseFailAlloc_1873_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1873_, 0, v___x_1811_);
lean_ctor_set(v_reuseFailAlloc_1873_, 1, v_snd_1794_);
v___x_1868_ = v_reuseFailAlloc_1873_;
goto v_reusejp_1867_;
}
v_reusejp_1867_:
{
lean_object* v___x_1870_; 
if (v_isShared_1792_ == 0)
{
lean_ctor_set(v___x_1791_, 1, v___x_1868_);
v___x_1870_ = v___x_1791_;
goto v_reusejp_1869_;
}
else
{
lean_object* v_reuseFailAlloc_1872_; 
v_reuseFailAlloc_1872_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1872_, 0, v_fst_1789_);
lean_ctor_set(v_reuseFailAlloc_1872_, 1, v___x_1868_);
v___x_1870_ = v_reuseFailAlloc_1872_;
goto v_reusejp_1869_;
}
v_reusejp_1869_:
{
v_a_1782_ = v___x_1870_;
goto _start;
}
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_While_0__repeatM_erased___at___00JunkValues_scanDecl_spec__2___redArg___boxed(lean_object* v_cfg_1876_, lean_object* v_rs_1877_, lean_object* v_name_1878_, lean_object* v_a_1879_, lean_object* v___y_1880_, lean_object* v___y_1881_, lean_object* v___y_1882_, lean_object* v___y_1883_, lean_object* v___y_1884_){
_start:
{
lean_object* v_res_1885_; 
v_res_1885_ = lp_JunkValues___private_Init_While_0__repeatM_erased___at___00JunkValues_scanDecl_spec__2___redArg(v_cfg_1876_, v_rs_1877_, v_name_1878_, v_a_1879_, v___y_1880_, v___y_1881_, v___y_1882_, v___y_1883_);
lean_dec(v___y_1883_);
lean_dec_ref(v___y_1882_);
lean_dec(v___y_1881_);
lean_dec_ref(v___y_1880_);
return v_res_1885_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_scanDecl___closed__0(void){
_start:
{
lean_object* v___x_1886_; lean_object* v___x_1887_; lean_object* v___x_1888_; 
v___x_1886_ = lean_box(0);
v___x_1887_ = lean_unsigned_to_nat(16u);
v___x_1888_ = lean_mk_array(v___x_1887_, v___x_1886_);
return v___x_1888_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_scanDecl___closed__1(void){
_start:
{
lean_object* v___x_1889_; lean_object* v___x_1890_; lean_object* v___x_1891_; 
v___x_1889_ = lean_obj_once(&lp_JunkValues_JunkValues_scanDecl___closed__0, &lp_JunkValues_JunkValues_scanDecl___closed__0_once, _init_lp_JunkValues_JunkValues_scanDecl___closed__0);
v___x_1890_ = lean_unsigned_to_nat(0u);
v___x_1891_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1891_, 0, v___x_1890_);
lean_ctor_set(v___x_1891_, 1, v___x_1889_);
return v___x_1891_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_scanDecl(lean_object* v_rs_1892_, lean_object* v_cfg_1893_, lean_object* v_name_1894_, lean_object* v_a_1895_, lean_object* v_a_1896_, lean_object* v_a_1897_, lean_object* v_a_1898_){
_start:
{
lean_object* v___x_1900_; lean_object* v_env_1901_; uint8_t v___x_1902_; lean_object* v___x_1903_; 
v___x_1900_ = lean_st_ref_get(v_a_1898_);
v_env_1901_ = lean_ctor_get(v___x_1900_, 0);
lean_inc_ref(v_env_1901_);
lean_dec(v___x_1900_);
v___x_1902_ = 0;
lean_inc(v_name_1894_);
v___x_1903_ = l_Lean_Environment_find_x3f(v_env_1901_, v_name_1894_, v___x_1902_);
if (lean_obj_tag(v___x_1903_) == 1)
{
lean_object* v_val_1904_; lean_object* v___x_1905_; lean_object* v___x_1906_; 
v_val_1904_ = lean_ctor_get(v___x_1903_, 0);
lean_inc(v_val_1904_);
lean_dec_ref_known(v___x_1903_, 1);
v___x_1905_ = l_Lean_ConstantInfo_type(v_val_1904_);
lean_dec(v_val_1904_);
lean_inc_ref(v___x_1905_);
v___x_1906_ = l_Lean_Meta_isProp(v___x_1905_, v_a_1895_, v_a_1896_, v_a_1897_, v_a_1898_);
if (lean_obj_tag(v___x_1906_) == 0)
{
lean_object* v_a_1907_; uint8_t v___x_1908_; lean_object* v___x_1909_; lean_object* v___x_1910_; 
v_a_1907_ = lean_ctor_get(v___x_1906_, 0);
lean_inc(v_a_1907_);
lean_dec_ref_known(v___x_1906_, 1);
v___x_1908_ = 0;
v___x_1909_ = ((lean_object*)(lp_JunkValues_JunkValues_instInhabitedDeclScan_default___closed__0));
lean_inc(v_name_1894_);
lean_inc_ref(v_cfg_1893_);
lean_inc_ref(v_rs_1892_);
v___x_1910_ = lp_JunkValues_JunkValues_visit(v_rs_1892_, v_cfg_1893_, v_name_1894_, v___x_1908_, v___x_1905_, v___x_1909_, v_a_1895_, v_a_1896_, v_a_1897_, v_a_1898_);
if (lean_obj_tag(v___x_1910_) == 0)
{
lean_object* v_a_1911_; lean_object* v___x_1913_; uint8_t v_isShared_1914_; uint8_t v_isSharedCheck_1946_; 
v_a_1911_ = lean_ctor_get(v___x_1910_, 0);
v_isSharedCheck_1946_ = !lean_is_exclusive(v___x_1910_);
if (v_isSharedCheck_1946_ == 0)
{
v___x_1913_ = v___x_1910_;
v_isShared_1914_ = v_isSharedCheck_1946_;
goto v_resetjp_1912_;
}
else
{
lean_inc(v_a_1911_);
lean_dec(v___x_1910_);
v___x_1913_ = lean_box(0);
v_isShared_1914_ = v_isSharedCheck_1946_;
goto v_resetjp_1912_;
}
v_resetjp_1912_:
{
uint8_t v_scanBodies_1915_; uint8_t v_scanProofs_1916_; lean_object* v_maxPerDecl_1917_; lean_object* v_found_1919_; 
v_scanBodies_1915_ = lean_ctor_get_uint8(v_cfg_1893_, sizeof(void*)*2 + 1);
v_scanProofs_1916_ = lean_ctor_get_uint8(v_cfg_1893_, sizeof(void*)*2 + 2);
v_maxPerDecl_1917_ = lean_ctor_get(v_cfg_1893_, 1);
lean_inc(v_maxPerDecl_1917_);
if (v_scanBodies_1915_ == 0)
{
lean_dec(v_a_1907_);
lean_dec_ref(v_cfg_1893_);
lean_dec_ref(v_rs_1892_);
v_found_1919_ = v_a_1911_;
goto v___jp_1918_;
}
else
{
if (v_scanProofs_1916_ == 0)
{
uint8_t v___x_1945_; 
v___x_1945_ = lean_unbox(v_a_1907_);
lean_dec(v_a_1907_);
if (v___x_1945_ == 0)
{
goto v___jp_1927_;
}
else
{
lean_dec_ref(v_cfg_1893_);
lean_dec_ref(v_rs_1892_);
v_found_1919_ = v_a_1911_;
goto v___jp_1918_;
}
}
else
{
lean_dec(v_a_1907_);
goto v___jp_1927_;
}
}
v___jp_1918_:
{
lean_object* v___x_1920_; lean_object* v___x_1921_; uint8_t v___x_1922_; lean_object* v___x_1923_; lean_object* v___x_1925_; 
v___x_1920_ = lp_JunkValues_JunkValues_dedupFindings(v_found_1919_);
v___x_1921_ = lean_array_get_size(v_found_1919_);
lean_dec_ref(v_found_1919_);
v___x_1922_ = lean_nat_dec_le(v_maxPerDecl_1917_, v___x_1921_);
lean_dec(v_maxPerDecl_1917_);
v___x_1923_ = lean_alloc_ctor(0, 2, 1);
lean_ctor_set(v___x_1923_, 0, v_name_1894_);
lean_ctor_set(v___x_1923_, 1, v___x_1920_);
lean_ctor_set_uint8(v___x_1923_, sizeof(void*)*2, v___x_1922_);
if (v_isShared_1914_ == 0)
{
lean_ctor_set(v___x_1913_, 0, v___x_1923_);
v___x_1925_ = v___x_1913_;
goto v_reusejp_1924_;
}
else
{
lean_object* v_reuseFailAlloc_1926_; 
v_reuseFailAlloc_1926_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1926_, 0, v___x_1923_);
v___x_1925_ = v_reuseFailAlloc_1926_;
goto v_reusejp_1924_;
}
v_reusejp_1924_:
{
return v___x_1925_;
}
}
v___jp_1927_:
{
lean_object* v___x_1928_; lean_object* v___x_1929_; lean_object* v___x_1930_; lean_object* v___x_1931_; lean_object* v___x_1932_; lean_object* v___x_1933_; lean_object* v___x_1934_; 
v___x_1928_ = lean_unsigned_to_nat(1u);
v___x_1929_ = lean_mk_empty_array_with_capacity(v___x_1928_);
lean_inc_n(v_name_1894_, 2);
v___x_1930_ = lean_array_push(v___x_1929_, v_name_1894_);
v___x_1931_ = lean_obj_once(&lp_JunkValues_JunkValues_scanDecl___closed__1, &lp_JunkValues_JunkValues_scanDecl___closed__1_once, _init_lp_JunkValues_JunkValues_scanDecl___closed__1);
v___x_1932_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1932_, 0, v___x_1930_);
lean_ctor_set(v___x_1932_, 1, v___x_1931_);
v___x_1933_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1933_, 0, v_a_1911_);
lean_ctor_set(v___x_1933_, 1, v___x_1932_);
v___x_1934_ = lp_JunkValues___private_Init_While_0__repeatM_erased___at___00JunkValues_scanDecl_spec__2___redArg(v_cfg_1893_, v_rs_1892_, v_name_1894_, v___x_1933_, v_a_1895_, v_a_1896_, v_a_1897_, v_a_1898_);
if (lean_obj_tag(v___x_1934_) == 0)
{
lean_object* v_a_1935_; lean_object* v_fst_1936_; 
v_a_1935_ = lean_ctor_get(v___x_1934_, 0);
lean_inc(v_a_1935_);
lean_dec_ref_known(v___x_1934_, 1);
v_fst_1936_ = lean_ctor_get(v_a_1935_, 0);
lean_inc(v_fst_1936_);
lean_dec(v_a_1935_);
v_found_1919_ = v_fst_1936_;
goto v___jp_1918_;
}
else
{
lean_object* v_a_1937_; lean_object* v___x_1939_; uint8_t v_isShared_1940_; uint8_t v_isSharedCheck_1944_; 
lean_dec(v_maxPerDecl_1917_);
lean_del_object(v___x_1913_);
lean_dec(v_name_1894_);
v_a_1937_ = lean_ctor_get(v___x_1934_, 0);
v_isSharedCheck_1944_ = !lean_is_exclusive(v___x_1934_);
if (v_isSharedCheck_1944_ == 0)
{
v___x_1939_ = v___x_1934_;
v_isShared_1940_ = v_isSharedCheck_1944_;
goto v_resetjp_1938_;
}
else
{
lean_inc(v_a_1937_);
lean_dec(v___x_1934_);
v___x_1939_ = lean_box(0);
v_isShared_1940_ = v_isSharedCheck_1944_;
goto v_resetjp_1938_;
}
v_resetjp_1938_:
{
lean_object* v___x_1942_; 
if (v_isShared_1940_ == 0)
{
v___x_1942_ = v___x_1939_;
goto v_reusejp_1941_;
}
else
{
lean_object* v_reuseFailAlloc_1943_; 
v_reuseFailAlloc_1943_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1943_, 0, v_a_1937_);
v___x_1942_ = v_reuseFailAlloc_1943_;
goto v_reusejp_1941_;
}
v_reusejp_1941_:
{
return v___x_1942_;
}
}
}
}
}
}
else
{
lean_object* v_a_1947_; lean_object* v___x_1949_; uint8_t v_isShared_1950_; uint8_t v_isSharedCheck_1954_; 
lean_dec(v_a_1907_);
lean_dec(v_name_1894_);
lean_dec_ref(v_cfg_1893_);
lean_dec_ref(v_rs_1892_);
v_a_1947_ = lean_ctor_get(v___x_1910_, 0);
v_isSharedCheck_1954_ = !lean_is_exclusive(v___x_1910_);
if (v_isSharedCheck_1954_ == 0)
{
v___x_1949_ = v___x_1910_;
v_isShared_1950_ = v_isSharedCheck_1954_;
goto v_resetjp_1948_;
}
else
{
lean_inc(v_a_1947_);
lean_dec(v___x_1910_);
v___x_1949_ = lean_box(0);
v_isShared_1950_ = v_isSharedCheck_1954_;
goto v_resetjp_1948_;
}
v_resetjp_1948_:
{
lean_object* v___x_1952_; 
if (v_isShared_1950_ == 0)
{
v___x_1952_ = v___x_1949_;
goto v_reusejp_1951_;
}
else
{
lean_object* v_reuseFailAlloc_1953_; 
v_reuseFailAlloc_1953_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1953_, 0, v_a_1947_);
v___x_1952_ = v_reuseFailAlloc_1953_;
goto v_reusejp_1951_;
}
v_reusejp_1951_:
{
return v___x_1952_;
}
}
}
}
else
{
lean_object* v_a_1955_; lean_object* v___x_1957_; uint8_t v_isShared_1958_; uint8_t v_isSharedCheck_1962_; 
lean_dec_ref(v___x_1905_);
lean_dec(v_name_1894_);
lean_dec_ref(v_cfg_1893_);
lean_dec_ref(v_rs_1892_);
v_a_1955_ = lean_ctor_get(v___x_1906_, 0);
v_isSharedCheck_1962_ = !lean_is_exclusive(v___x_1906_);
if (v_isSharedCheck_1962_ == 0)
{
v___x_1957_ = v___x_1906_;
v_isShared_1958_ = v_isSharedCheck_1962_;
goto v_resetjp_1956_;
}
else
{
lean_inc(v_a_1955_);
lean_dec(v___x_1906_);
v___x_1957_ = lean_box(0);
v_isShared_1958_ = v_isSharedCheck_1962_;
goto v_resetjp_1956_;
}
v_resetjp_1956_:
{
lean_object* v___x_1960_; 
if (v_isShared_1958_ == 0)
{
v___x_1960_ = v___x_1957_;
goto v_reusejp_1959_;
}
else
{
lean_object* v_reuseFailAlloc_1961_; 
v_reuseFailAlloc_1961_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1961_, 0, v_a_1955_);
v___x_1960_ = v_reuseFailAlloc_1961_;
goto v_reusejp_1959_;
}
v_reusejp_1959_:
{
return v___x_1960_;
}
}
}
}
else
{
lean_object* v___x_1963_; lean_object* v___x_1964_; lean_object* v___x_1965_; 
lean_dec(v___x_1903_);
lean_dec_ref(v_cfg_1893_);
lean_dec_ref(v_rs_1892_);
v___x_1963_ = ((lean_object*)(lp_JunkValues_JunkValues_instInhabitedDeclScan_default___closed__0));
v___x_1964_ = lean_alloc_ctor(0, 2, 1);
lean_ctor_set(v___x_1964_, 0, v_name_1894_);
lean_ctor_set(v___x_1964_, 1, v___x_1963_);
lean_ctor_set_uint8(v___x_1964_, sizeof(void*)*2, v___x_1902_);
v___x_1965_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1965_, 0, v___x_1964_);
return v___x_1965_;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_scanDecl___boxed(lean_object* v_rs_1966_, lean_object* v_cfg_1967_, lean_object* v_name_1968_, lean_object* v_a_1969_, lean_object* v_a_1970_, lean_object* v_a_1971_, lean_object* v_a_1972_, lean_object* v_a_1973_){
_start:
{
lean_object* v_res_1974_; 
v_res_1974_ = lp_JunkValues_JunkValues_scanDecl(v_rs_1966_, v_cfg_1967_, v_name_1968_, v_a_1969_, v_a_1970_, v_a_1971_, v_a_1972_);
lean_dec(v_a_1972_);
lean_dec_ref(v_a_1971_);
lean_dec(v_a_1970_);
lean_dec_ref(v_a_1969_);
return v_res_1974_;
}
}
LEAN_EXPORT uint8_t lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_scanDecl_spec__0(lean_object* v_00_u03b2_1975_, lean_object* v_m_1976_, lean_object* v_a_1977_){
_start:
{
uint8_t v___x_1978_; 
v___x_1978_ = lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_scanDecl_spec__0___redArg(v_m_1976_, v_a_1977_);
return v___x_1978_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_scanDecl_spec__0___boxed(lean_object* v_00_u03b2_1979_, lean_object* v_m_1980_, lean_object* v_a_1981_){
_start:
{
uint8_t v_res_1982_; lean_object* v_r_1983_; 
v_res_1982_ = lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_scanDecl_spec__0(v_00_u03b2_1979_, v_m_1980_, v_a_1981_);
lean_dec(v_a_1981_);
lean_dec_ref(v_m_1980_);
v_r_1983_ = lean_box(v_res_1982_);
return v_r_1983_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_scanDecl_spec__1(lean_object* v_00_u03b2_1984_, lean_object* v_m_1985_, lean_object* v_a_1986_, lean_object* v_b_1987_){
_start:
{
lean_object* v___x_1988_; 
v___x_1988_ = lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_scanDecl_spec__1___redArg(v_m_1985_, v_a_1986_, v_b_1987_);
return v___x_1988_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_While_0__repeatM_erased___at___00JunkValues_scanDecl_spec__2(lean_object* v_cfg_1989_, lean_object* v_rs_1990_, lean_object* v_name_1991_, lean_object* v_inst_1992_, lean_object* v_a_1993_, lean_object* v___y_1994_, lean_object* v___y_1995_, lean_object* v___y_1996_, lean_object* v___y_1997_){
_start:
{
lean_object* v___x_1999_; 
v___x_1999_ = lp_JunkValues___private_Init_While_0__repeatM_erased___at___00JunkValues_scanDecl_spec__2___redArg(v_cfg_1989_, v_rs_1990_, v_name_1991_, v_a_1993_, v___y_1994_, v___y_1995_, v___y_1996_, v___y_1997_);
return v___x_1999_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_While_0__repeatM_erased___at___00JunkValues_scanDecl_spec__2___boxed(lean_object* v_cfg_2000_, lean_object* v_rs_2001_, lean_object* v_name_2002_, lean_object* v_inst_2003_, lean_object* v_a_2004_, lean_object* v___y_2005_, lean_object* v___y_2006_, lean_object* v___y_2007_, lean_object* v___y_2008_, lean_object* v___y_2009_){
_start:
{
lean_object* v_res_2010_; 
v_res_2010_ = lp_JunkValues___private_Init_While_0__repeatM_erased___at___00JunkValues_scanDecl_spec__2(v_cfg_2000_, v_rs_2001_, v_name_2002_, v_inst_2003_, v_a_2004_, v___y_2005_, v___y_2006_, v___y_2007_, v___y_2008_);
lean_dec(v___y_2008_);
lean_dec_ref(v___y_2007_);
lean_dec(v___y_2006_);
lean_dec_ref(v___y_2005_);
return v_res_2010_;
}
}
LEAN_EXPORT uint8_t lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_scanDecl_spec__0_spec__0(lean_object* v_00_u03b2_2011_, lean_object* v_a_2012_, lean_object* v_x_2013_){
_start:
{
uint8_t v___x_2014_; 
v___x_2014_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_scanDecl_spec__0_spec__0___redArg(v_a_2012_, v_x_2013_);
return v___x_2014_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_scanDecl_spec__0_spec__0___boxed(lean_object* v_00_u03b2_2015_, lean_object* v_a_2016_, lean_object* v_x_2017_){
_start:
{
uint8_t v_res_2018_; lean_object* v_r_2019_; 
v_res_2018_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00JunkValues_scanDecl_spec__0_spec__0(v_00_u03b2_2015_, v_a_2016_, v_x_2017_);
lean_dec(v_x_2017_);
lean_dec(v_a_2016_);
v_r_2019_ = lean_box(v_res_2018_);
return v_r_2019_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_scanDecl_spec__1_spec__2(lean_object* v_00_u03b2_2020_, lean_object* v_data_2021_){
_start:
{
lean_object* v___x_2022_; 
v___x_2022_ = lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_scanDecl_spec__1_spec__2___redArg(v_data_2021_);
return v___x_2022_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_scanDecl_spec__1_spec__2_spec__3(lean_object* v_00_u03b2_2023_, lean_object* v_i_2024_, lean_object* v_source_2025_, lean_object* v_target_2026_){
_start:
{
lean_object* v___x_2027_; 
v___x_2027_ = lp_JunkValues___private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_scanDecl_spec__1_spec__2_spec__3___redArg(v_i_2024_, v_source_2025_, v_target_2026_);
return v___x_2027_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00__private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_scanDecl_spec__1_spec__2_spec__3_spec__5(lean_object* v_00_u03b2_2028_, lean_object* v_x_2029_, lean_object* v_x_2030_){
_start:
{
lean_object* v___x_2031_; 
v___x_2031_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00__private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insertIfNew___at___00JunkValues_scanDecl_spec__1_spec__2_spec__3_spec__5___redArg(v_x_2029_, v_x_2030_);
return v___x_2031_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_scanDecls_spec__0(lean_object* v_rs_2032_, lean_object* v_cfg_2033_, lean_object* v_as_2034_, size_t v_sz_2035_, size_t v_i_2036_, lean_object* v_b_2037_, lean_object* v___y_2038_, lean_object* v___y_2039_, lean_object* v___y_2040_, lean_object* v___y_2041_){
_start:
{
lean_object* v_fst_2044_; lean_object* v_snd_2045_; uint8_t v___x_2050_; 
v___x_2050_ = lean_usize_dec_lt(v_i_2036_, v_sz_2035_);
if (v___x_2050_ == 0)
{
lean_object* v___x_2051_; 
lean_dec_ref(v_cfg_2033_);
lean_dec_ref(v_rs_2032_);
v___x_2051_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_2051_, 0, v_b_2037_);
return v___x_2051_;
}
else
{
lean_object* v_fst_2052_; lean_object* v_snd_2053_; lean_object* v___x_2055_; uint8_t v_isShared_2056_; uint8_t v_isSharedCheck_2083_; 
v_fst_2052_ = lean_ctor_get(v_b_2037_, 0);
v_snd_2053_ = lean_ctor_get(v_b_2037_, 1);
v_isSharedCheck_2083_ = !lean_is_exclusive(v_b_2037_);
if (v_isSharedCheck_2083_ == 0)
{
v___x_2055_ = v_b_2037_;
v_isShared_2056_ = v_isSharedCheck_2083_;
goto v_resetjp_2054_;
}
else
{
lean_inc(v_snd_2053_);
lean_inc(v_fst_2052_);
lean_dec(v_b_2037_);
v___x_2055_ = lean_box(0);
v_isShared_2056_ = v_isSharedCheck_2083_;
goto v_resetjp_2054_;
}
v_resetjp_2054_:
{
lean_object* v_a_2057_; lean_object* v___x_2058_; 
v_a_2057_ = lean_array_uget_borrowed(v_as_2034_, v_i_2036_);
lean_inc(v_a_2057_);
lean_inc_ref(v_cfg_2033_);
lean_inc_ref(v_rs_2032_);
v___x_2058_ = lp_JunkValues_JunkValues_scanDecl(v_rs_2032_, v_cfg_2033_, v_a_2057_, v___y_2038_, v___y_2039_, v___y_2040_, v___y_2041_);
if (lean_obj_tag(v___x_2058_) == 0)
{
lean_object* v_a_2059_; lean_object* v_findings_2060_; lean_object* v___x_2061_; lean_object* v___x_2062_; uint8_t v___x_2063_; 
lean_del_object(v___x_2055_);
v_a_2059_ = lean_ctor_get(v___x_2058_, 0);
lean_inc(v_a_2059_);
lean_dec_ref_known(v___x_2058_, 1);
v_findings_2060_ = lean_ctor_get(v_a_2059_, 1);
v___x_2061_ = lean_array_get_size(v_findings_2060_);
v___x_2062_ = lean_unsigned_to_nat(0u);
v___x_2063_ = lean_nat_dec_eq(v___x_2061_, v___x_2062_);
if (v___x_2063_ == 0)
{
lean_object* v___x_2064_; 
v___x_2064_ = lean_array_push(v_fst_2052_, v_a_2059_);
v_fst_2044_ = v___x_2064_;
v_snd_2045_ = v_snd_2053_;
goto v___jp_2043_;
}
else
{
lean_dec(v_a_2059_);
v_fst_2044_ = v_fst_2052_;
v_snd_2045_ = v_snd_2053_;
goto v___jp_2043_;
}
}
else
{
lean_object* v_a_2065_; lean_object* v___x_2067_; uint8_t v_isShared_2068_; uint8_t v_isSharedCheck_2082_; 
v_a_2065_ = lean_ctor_get(v___x_2058_, 0);
v_isSharedCheck_2082_ = !lean_is_exclusive(v___x_2058_);
if (v_isSharedCheck_2082_ == 0)
{
v___x_2067_ = v___x_2058_;
v_isShared_2068_ = v_isSharedCheck_2082_;
goto v_resetjp_2066_;
}
else
{
lean_inc(v_a_2065_);
lean_dec(v___x_2058_);
v___x_2067_ = lean_box(0);
v_isShared_2068_ = v_isSharedCheck_2082_;
goto v_resetjp_2066_;
}
v_resetjp_2066_:
{
uint8_t v___y_2070_; uint8_t v___x_2080_; 
v___x_2080_ = l_Lean_Exception_isInterrupt(v_a_2065_);
if (v___x_2080_ == 0)
{
uint8_t v___x_2081_; 
lean_inc(v_a_2065_);
v___x_2081_ = l_Lean_Exception_isRuntime(v_a_2065_);
v___y_2070_ = v___x_2081_;
goto v___jp_2069_;
}
else
{
v___y_2070_ = v___x_2080_;
goto v___jp_2069_;
}
v___jp_2069_:
{
if (v___y_2070_ == 0)
{
lean_object* v___x_2071_; lean_object* v___x_2072_; lean_object* v___x_2074_; 
lean_del_object(v___x_2067_);
v___x_2071_ = l_Lean_Exception_toMessageData(v_a_2065_);
v___x_2072_ = l_Lean_MessageData_toString(v___x_2071_);
lean_inc(v_a_2057_);
if (v_isShared_2056_ == 0)
{
lean_ctor_set(v___x_2055_, 1, v___x_2072_);
lean_ctor_set(v___x_2055_, 0, v_a_2057_);
v___x_2074_ = v___x_2055_;
goto v_reusejp_2073_;
}
else
{
lean_object* v_reuseFailAlloc_2076_; 
v_reuseFailAlloc_2076_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_2076_, 0, v_a_2057_);
lean_ctor_set(v_reuseFailAlloc_2076_, 1, v___x_2072_);
v___x_2074_ = v_reuseFailAlloc_2076_;
goto v_reusejp_2073_;
}
v_reusejp_2073_:
{
lean_object* v___x_2075_; 
v___x_2075_ = lean_array_push(v_snd_2053_, v___x_2074_);
v_fst_2044_ = v_fst_2052_;
v_snd_2045_ = v___x_2075_;
goto v___jp_2043_;
}
}
else
{
lean_object* v___x_2078_; 
lean_del_object(v___x_2055_);
lean_dec(v_snd_2053_);
lean_dec(v_fst_2052_);
lean_dec_ref(v_cfg_2033_);
lean_dec_ref(v_rs_2032_);
if (v_isShared_2068_ == 0)
{
v___x_2078_ = v___x_2067_;
goto v_reusejp_2077_;
}
else
{
lean_object* v_reuseFailAlloc_2079_; 
v_reuseFailAlloc_2079_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2079_, 0, v_a_2065_);
v___x_2078_ = v_reuseFailAlloc_2079_;
goto v_reusejp_2077_;
}
v_reusejp_2077_:
{
return v___x_2078_;
}
}
}
}
}
}
}
v___jp_2043_:
{
lean_object* v___x_2046_; size_t v___x_2047_; size_t v___x_2048_; 
v___x_2046_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2046_, 0, v_fst_2044_);
lean_ctor_set(v___x_2046_, 1, v_snd_2045_);
v___x_2047_ = ((size_t)1ULL);
v___x_2048_ = lean_usize_add(v_i_2036_, v___x_2047_);
v_i_2036_ = v___x_2048_;
v_b_2037_ = v___x_2046_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_scanDecls_spec__0___boxed(lean_object* v_rs_2084_, lean_object* v_cfg_2085_, lean_object* v_as_2086_, lean_object* v_sz_2087_, lean_object* v_i_2088_, lean_object* v_b_2089_, lean_object* v___y_2090_, lean_object* v___y_2091_, lean_object* v___y_2092_, lean_object* v___y_2093_, lean_object* v___y_2094_){
_start:
{
size_t v_sz_boxed_2095_; size_t v_i_boxed_2096_; lean_object* v_res_2097_; 
v_sz_boxed_2095_ = lean_unbox_usize(v_sz_2087_);
lean_dec(v_sz_2087_);
v_i_boxed_2096_ = lean_unbox_usize(v_i_2088_);
lean_dec(v_i_2088_);
v_res_2097_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_scanDecls_spec__0(v_rs_2084_, v_cfg_2085_, v_as_2086_, v_sz_boxed_2095_, v_i_boxed_2096_, v_b_2089_, v___y_2090_, v___y_2091_, v___y_2092_, v___y_2093_);
lean_dec(v___y_2093_);
lean_dec_ref(v___y_2092_);
lean_dec(v___y_2091_);
lean_dec_ref(v___y_2090_);
lean_dec_ref(v_as_2086_);
return v_res_2097_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_scanDecls(lean_object* v_rs_2102_, lean_object* v_cfg_2103_, lean_object* v_names_2104_, lean_object* v_a_2105_, lean_object* v_a_2106_, lean_object* v_a_2107_, lean_object* v_a_2108_){
_start:
{
lean_object* v___x_2110_; size_t v_sz_2111_; size_t v___x_2112_; lean_object* v___x_2113_; 
v___x_2110_ = ((lean_object*)(lp_JunkValues_JunkValues_scanDecls___closed__1));
v_sz_2111_ = lean_array_size(v_names_2104_);
v___x_2112_ = ((size_t)0ULL);
v___x_2113_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_scanDecls_spec__0(v_rs_2102_, v_cfg_2103_, v_names_2104_, v_sz_2111_, v___x_2112_, v___x_2110_, v_a_2105_, v_a_2106_, v_a_2107_, v_a_2108_);
if (lean_obj_tag(v___x_2113_) == 0)
{
lean_object* v_a_2114_; lean_object* v___x_2116_; uint8_t v_isShared_2117_; uint8_t v_isSharedCheck_2130_; 
v_a_2114_ = lean_ctor_get(v___x_2113_, 0);
v_isSharedCheck_2130_ = !lean_is_exclusive(v___x_2113_);
if (v_isSharedCheck_2130_ == 0)
{
v___x_2116_ = v___x_2113_;
v_isShared_2117_ = v_isSharedCheck_2130_;
goto v_resetjp_2115_;
}
else
{
lean_inc(v_a_2114_);
lean_dec(v___x_2113_);
v___x_2116_ = lean_box(0);
v_isShared_2117_ = v_isSharedCheck_2130_;
goto v_resetjp_2115_;
}
v_resetjp_2115_:
{
lean_object* v_fst_2118_; lean_object* v_snd_2119_; lean_object* v___x_2121_; uint8_t v_isShared_2122_; uint8_t v_isSharedCheck_2129_; 
v_fst_2118_ = lean_ctor_get(v_a_2114_, 0);
v_snd_2119_ = lean_ctor_get(v_a_2114_, 1);
v_isSharedCheck_2129_ = !lean_is_exclusive(v_a_2114_);
if (v_isSharedCheck_2129_ == 0)
{
v___x_2121_ = v_a_2114_;
v_isShared_2122_ = v_isSharedCheck_2129_;
goto v_resetjp_2120_;
}
else
{
lean_inc(v_snd_2119_);
lean_inc(v_fst_2118_);
lean_dec(v_a_2114_);
v___x_2121_ = lean_box(0);
v_isShared_2122_ = v_isSharedCheck_2129_;
goto v_resetjp_2120_;
}
v_resetjp_2120_:
{
lean_object* v___x_2124_; 
if (v_isShared_2122_ == 0)
{
v___x_2124_ = v___x_2121_;
goto v_reusejp_2123_;
}
else
{
lean_object* v_reuseFailAlloc_2128_; 
v_reuseFailAlloc_2128_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_2128_, 0, v_fst_2118_);
lean_ctor_set(v_reuseFailAlloc_2128_, 1, v_snd_2119_);
v___x_2124_ = v_reuseFailAlloc_2128_;
goto v_reusejp_2123_;
}
v_reusejp_2123_:
{
lean_object* v___x_2126_; 
if (v_isShared_2117_ == 0)
{
lean_ctor_set(v___x_2116_, 0, v___x_2124_);
v___x_2126_ = v___x_2116_;
goto v_reusejp_2125_;
}
else
{
lean_object* v_reuseFailAlloc_2127_; 
v_reuseFailAlloc_2127_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2127_, 0, v___x_2124_);
v___x_2126_ = v_reuseFailAlloc_2127_;
goto v_reusejp_2125_;
}
v_reusejp_2125_:
{
return v___x_2126_;
}
}
}
}
}
else
{
return v___x_2113_;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_scanDecls___boxed(lean_object* v_rs_2131_, lean_object* v_cfg_2132_, lean_object* v_names_2133_, lean_object* v_a_2134_, lean_object* v_a_2135_, lean_object* v_a_2136_, lean_object* v_a_2137_, lean_object* v_a_2138_){
_start:
{
lean_object* v_res_2139_; 
v_res_2139_ = lp_JunkValues_JunkValues_scanDecls(v_rs_2131_, v_cfg_2132_, v_names_2133_, v_a_2134_, v_a_2135_, v_a_2136_, v_a_2137_);
lean_dec(v_a_2137_);
lean_dec_ref(v_a_2136_);
lean_dec(v_a_2135_);
lean_dec_ref(v_a_2134_);
lean_dec_ref(v_names_2133_);
return v_res_2139_;
}
}
lean_object* runtime_initialize_Init(uint8_t builtin);
lean_object* runtime_initialize_JunkValues_JunkValues_RuleSet(uint8_t builtin);
lean_object* runtime_initialize_JunkValues_JunkValues_Guard(uint8_t builtin);
lean_object* runtime_initialize_JunkValues_JunkValues_Report(uint8_t builtin);
static bool _G_runtime_initialized = false;
LEAN_EXPORT lean_object* runtime_initialize_JunkValues_JunkValues_Scan(uint8_t builtin) {
lean_object * res;
if (_G_runtime_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_runtime_initialized = true;
res = runtime_initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = runtime_initialize_JunkValues_JunkValues_RuleSet(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = runtime_initialize_JunkValues_JunkValues_Guard(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = runtime_initialize_JunkValues_JunkValues_Report(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return lean_io_result_mk_ok(lean_box(0));
}
lean_object* runtime_initialize_Init(uint8_t builtin);
static bool _G_meta_initialized = false;
LEAN_EXPORT lean_object* meta_initialize_JunkValues_JunkValues_Scan(uint8_t builtin) {
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
lean_object* initialize_JunkValues_JunkValues_Guard(uint8_t builtin);
lean_object* initialize_JunkValues_JunkValues_Report(uint8_t builtin);
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_JunkValues_JunkValues_Scan(uint8_t builtin) {
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
res = initialize_JunkValues_JunkValues_Guard(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_JunkValues_JunkValues_Report(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = runtime_initialize_JunkValues_JunkValues_Scan(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = meta_initialize_JunkValues_JunkValues_Scan(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return initialize_JunkValues_JunkValues_Scan(builtin);
}
#ifdef __cplusplus
}
#endif
