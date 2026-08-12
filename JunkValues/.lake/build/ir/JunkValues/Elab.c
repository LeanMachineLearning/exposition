// Lean compiler output
// Module: JunkValues.Elab
// Imports: public import Init public meta import Init public import JunkValues.Frontend public import Lean.Elab.Command meta import JunkValues.Frontend meta import Lean.Elab.Command
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
extern lean_object* l_Lean_Elab_pp_macroStack;
lean_object* l_Std_DTreeMap_Internal_Impl_Const_get_x3f___at___00Lean_NameMap_find_x3f_spec__0___redArg(lean_object*, lean_object*);
lean_object* l_Lean_MessageData_ofFormat(lean_object*);
lean_object* l_Lean_MessageData_ofSyntax(lean_object*);
lean_object* l_Lean_indentD(lean_object*);
lean_object* lean_array_get_size(lean_object*);
uint8_t lean_nat_dec_lt(lean_object*, lean_object*);
lean_object* lean_array_fget_borrowed(lean_object*, lean_object*);
lean_object* lean_nat_add(lean_object*, lean_object*);
lean_object* l_Lean_Name_mkStr2(lean_object*, lean_object*);
lean_object* lean_array_fget(lean_object*, lean_object*);
lean_object* lean_array_fswap(lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_Name_toString(lean_object*, uint8_t);
uint8_t lean_string_dec_lt(lean_object*, lean_object*);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
lean_object* lean_nat_shiftr(lean_object*, lean_object*);
lean_object* l_Lean_stringToMessageData(lean_object*);
size_t lean_usize_of_nat(lean_object*);
size_t lean_usize_add(size_t, size_t);
uint8_t lean_usize_dec_eq(size_t, size_t);
lean_object* lean_array_uget_borrowed(lean_object*, size_t);
lean_object* l_Lean_Name_mkStr1(lean_object*);
lean_object* lean_st_ref_take(lean_object*);
lean_object* l_Lean_MessageLog_add(lean_object*, lean_object*);
lean_object* lean_st_ref_set(lean_object*, lean_object*);
lean_object* l___private_Lean_Log_0__Lean_MessageData_appendDescriptionWidgetIfNamed(lean_object*);
lean_object* lean_st_ref_get(lean_object*);
lean_object* l_Lean_FileMap_toPosition(lean_object*, lean_object*);
uint8_t l_Lean_MessageData_hasTag(lean_object*, lean_object*);
lean_object* l_Lean_Syntax_getTailPos_x3f(lean_object*, uint8_t);
lean_object* l_Lean_replaceRef(lean_object*, lean_object*);
lean_object* l_Lean_Syntax_getPos_x3f(lean_object*, uint8_t);
uint8_t lean_string_dec_eq(lean_object*, lean_object*);
uint8_t l_Lean_instBEqMessageSeverity_beq(uint8_t, uint8_t);
extern lean_object* l_Lean_warningAsError;
uint8_t l_Lean_MessageData_hasSyntheticSorry(lean_object*);
uint8_t lean_usize_dec_lt(size_t, size_t);
lean_object* l_Lean_MessageData_ofName(lean_object*);
lean_object* l_Nat_reprFast(lean_object*);
lean_object* lean_array_uget(lean_object*, size_t);
lean_object* lean_array_push(lean_object*, lean_object*);
lean_object* l_Lean_Elab_getBetterRef(lean_object*, lean_object*);
lean_object* lp_JunkValues_JunkValues_RuleSet_ofEnv(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
size_t lean_array_size(lean_object*);
uint8_t lean_nat_dec_eq(lean_object*, lean_object*);
lean_object* lean_array_to_list(lean_object*);
lean_object* l_List_reverse___redArg(lean_object*);
lean_object* lean_string_append(lean_object*, lean_object*);
lean_object* l_String_intercalate(lean_object*, lean_object*);
lean_object* lean_mk_empty_array_with_capacity(lean_object*);
extern lean_object* l_Lean_Elab_Command_instInhabitedScope_default;
lean_object* l_List_head_x21___redArg(lean_object*, lean_object*);
lean_object* l_Lean_Elab_Command_liftTermElabM___redArg(lean_object*, lean_object*, lean_object*);
lean_object* lp_JunkValues_JunkValues_warningOf(lean_object*);
lean_object* lp_JunkValues_JunkValues_setupOf(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* lp_JunkValues_JunkValues_scanDecls(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* lean_nat_sub(lean_object*, lean_object*);
uint8_t l_Lean_Environment_contains(lean_object*, lean_object*, uint8_t);
uint8_t l_Lean_Name_isImplementationDetail(lean_object*);
uint8_t l_Lean_Name_isPrefixOf(lean_object*, lean_object*);
uint8_t l_Lean_Name_isInternal(lean_object*);
lean_object* l_Lean_Environment_constants(lean_object*);
lean_object* l_Lean_Syntax_getArg(lean_object*, lean_object*);
lean_object* l_Lean_Syntax_getOptional_x3f(lean_object*);
lean_object* l_Lean_Syntax_getId(lean_object*);
static const lean_string_object lp_JunkValues_JunkValues_junkCheckCmd___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "JunkValues"};
static const lean_object* lp_JunkValues_JunkValues_junkCheckCmd___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_junkCheckCmd___closed__0_value;
static const lean_string_object lp_JunkValues_JunkValues_junkCheckCmd___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 13, .m_capacity = 13, .m_length = 12, .m_data = "junkCheckCmd"};
static const lean_object* lp_JunkValues_JunkValues_junkCheckCmd___closed__1 = (const lean_object*)&lp_JunkValues_JunkValues_junkCheckCmd___closed__1_value;
static const lean_ctor_object lp_JunkValues_JunkValues_junkCheckCmd___closed__2_value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_junkCheckCmd___closed__0_value),LEAN_SCALAR_PTR_LITERAL(102, 249, 254, 203, 87, 211, 22, 147)}};
static const lean_ctor_object lp_JunkValues_JunkValues_junkCheckCmd___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_junkCheckCmd___closed__2_value_aux_0),((lean_object*)&lp_JunkValues_JunkValues_junkCheckCmd___closed__1_value),LEAN_SCALAR_PTR_LITERAL(198, 190, 142, 185, 104, 145, 27, 122)}};
static const lean_object* lp_JunkValues_JunkValues_junkCheckCmd___closed__2 = (const lean_object*)&lp_JunkValues_JunkValues_junkCheckCmd___closed__2_value;
static const lean_string_object lp_JunkValues_JunkValues_junkCheckCmd___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "andthen"};
static const lean_object* lp_JunkValues_JunkValues_junkCheckCmd___closed__3 = (const lean_object*)&lp_JunkValues_JunkValues_junkCheckCmd___closed__3_value;
static const lean_ctor_object lp_JunkValues_JunkValues_junkCheckCmd___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_junkCheckCmd___closed__3_value),LEAN_SCALAR_PTR_LITERAL(40, 255, 78, 30, 143, 119, 117, 174)}};
static const lean_object* lp_JunkValues_JunkValues_junkCheckCmd___closed__4 = (const lean_object*)&lp_JunkValues_JunkValues_junkCheckCmd___closed__4_value;
static const lean_string_object lp_JunkValues_JunkValues_junkCheckCmd___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 12, .m_capacity = 12, .m_length = 11, .m_data = "#junk_check"};
static const lean_object* lp_JunkValues_JunkValues_junkCheckCmd___closed__5 = (const lean_object*)&lp_JunkValues_JunkValues_junkCheckCmd___closed__5_value;
static const lean_ctor_object lp_JunkValues_JunkValues_junkCheckCmd___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 5}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_junkCheckCmd___closed__5_value)}};
static const lean_object* lp_JunkValues_JunkValues_junkCheckCmd___closed__6 = (const lean_object*)&lp_JunkValues_JunkValues_junkCheckCmd___closed__6_value;
static const lean_string_object lp_JunkValues_JunkValues_junkCheckCmd___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "optional"};
static const lean_object* lp_JunkValues_JunkValues_junkCheckCmd___closed__7 = (const lean_object*)&lp_JunkValues_JunkValues_junkCheckCmd___closed__7_value;
static const lean_ctor_object lp_JunkValues_JunkValues_junkCheckCmd___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_junkCheckCmd___closed__7_value),LEAN_SCALAR_PTR_LITERAL(233, 141, 154, 50, 143, 135, 42, 252)}};
static const lean_object* lp_JunkValues_JunkValues_junkCheckCmd___closed__8 = (const lean_object*)&lp_JunkValues_JunkValues_junkCheckCmd___closed__8_value;
static const lean_string_object lp_JunkValues_JunkValues_junkCheckCmd___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "ppSpace"};
static const lean_object* lp_JunkValues_JunkValues_junkCheckCmd___closed__9 = (const lean_object*)&lp_JunkValues_JunkValues_junkCheckCmd___closed__9_value;
static const lean_ctor_object lp_JunkValues_JunkValues_junkCheckCmd___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_junkCheckCmd___closed__9_value),LEAN_SCALAR_PTR_LITERAL(207, 47, 58, 43, 30, 240, 125, 246)}};
static const lean_object* lp_JunkValues_JunkValues_junkCheckCmd___closed__10 = (const lean_object*)&lp_JunkValues_JunkValues_junkCheckCmd___closed__10_value;
static const lean_ctor_object lp_JunkValues_JunkValues_junkCheckCmd___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 0}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_junkCheckCmd___closed__10_value)}};
static const lean_object* lp_JunkValues_JunkValues_junkCheckCmd___closed__11 = (const lean_object*)&lp_JunkValues_JunkValues_junkCheckCmd___closed__11_value;
static const lean_string_object lp_JunkValues_JunkValues_junkCheckCmd___closed__12_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "ident"};
static const lean_object* lp_JunkValues_JunkValues_junkCheckCmd___closed__12 = (const lean_object*)&lp_JunkValues_JunkValues_junkCheckCmd___closed__12_value;
static const lean_ctor_object lp_JunkValues_JunkValues_junkCheckCmd___closed__13_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_junkCheckCmd___closed__12_value),LEAN_SCALAR_PTR_LITERAL(52, 159, 208, 51, 14, 60, 6, 71)}};
static const lean_object* lp_JunkValues_JunkValues_junkCheckCmd___closed__13 = (const lean_object*)&lp_JunkValues_JunkValues_junkCheckCmd___closed__13_value;
static const lean_ctor_object lp_JunkValues_JunkValues_junkCheckCmd___closed__14_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 0}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_junkCheckCmd___closed__13_value)}};
static const lean_object* lp_JunkValues_JunkValues_junkCheckCmd___closed__14 = (const lean_object*)&lp_JunkValues_JunkValues_junkCheckCmd___closed__14_value;
static const lean_ctor_object lp_JunkValues_JunkValues_junkCheckCmd___closed__15_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*3 + 0, .m_other = 3, .m_tag = 2}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_junkCheckCmd___closed__4_value),((lean_object*)&lp_JunkValues_JunkValues_junkCheckCmd___closed__11_value),((lean_object*)&lp_JunkValues_JunkValues_junkCheckCmd___closed__14_value)}};
static const lean_object* lp_JunkValues_JunkValues_junkCheckCmd___closed__15 = (const lean_object*)&lp_JunkValues_JunkValues_junkCheckCmd___closed__15_value;
static const lean_ctor_object lp_JunkValues_JunkValues_junkCheckCmd___closed__16_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_junkCheckCmd___closed__8_value),((lean_object*)&lp_JunkValues_JunkValues_junkCheckCmd___closed__15_value)}};
static const lean_object* lp_JunkValues_JunkValues_junkCheckCmd___closed__16 = (const lean_object*)&lp_JunkValues_JunkValues_junkCheckCmd___closed__16_value;
static const lean_ctor_object lp_JunkValues_JunkValues_junkCheckCmd___closed__17_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*3 + 0, .m_other = 3, .m_tag = 2}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_junkCheckCmd___closed__4_value),((lean_object*)&lp_JunkValues_JunkValues_junkCheckCmd___closed__6_value),((lean_object*)&lp_JunkValues_JunkValues_junkCheckCmd___closed__16_value)}};
static const lean_object* lp_JunkValues_JunkValues_junkCheckCmd___closed__17 = (const lean_object*)&lp_JunkValues_JunkValues_junkCheckCmd___closed__17_value;
static const lean_ctor_object lp_JunkValues_JunkValues_junkCheckCmd___closed__18_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*3 + 0, .m_other = 3, .m_tag = 3}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_junkCheckCmd___closed__2_value),((lean_object*)(((size_t)(1022) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_junkCheckCmd___closed__17_value)}};
static const lean_object* lp_JunkValues_JunkValues_junkCheckCmd___closed__18 = (const lean_object*)&lp_JunkValues_JunkValues_junkCheckCmd___closed__18_value;
LEAN_EXPORT const lean_object* lp_JunkValues_JunkValues_junkCheckCmd = (const lean_object*)&lp_JunkValues_JunkValues_junkCheckCmd___closed__18_value;
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_elabJunkCheck___lam__0(lean_object*, uint8_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_elabJunkCheck___lam__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__0___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 2, .m_capacity = 2, .m_length = 1, .m_data = "\n"};
static const lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__0___redArg___closed__0 = (const lean_object*)&lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__0___redArg___closed__0_value;
static lean_once_cell_t lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__0___redArg___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__0___redArg___closed__1;
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__0___redArg(lean_object*, size_t, size_t, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__0___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__3(lean_object*, size_t, size_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__3___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__12___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__12___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__14___redArg(lean_object*, lean_object*, size_t, size_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__14___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13___redArg___lam__0(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13___redArg___lam__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Lean_Data_PersistentHashMap_0__Lean_PersistentHashMap_foldlMAux_traverse___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13_spec__17_spec__18_spec__21___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Lean_Data_PersistentHashMap_0__Lean_PersistentHashMap_foldlMAux_traverse___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13_spec__17_spec__18_spec__21___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13_spec__17_spec__18___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13_spec__17_spec__18_spec__20___redArg(lean_object*, lean_object*, size_t, size_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13_spec__17_spec__18_spec__20___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13_spec__17_spec__18___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_JunkValues___private_Init_Data_Array_QSort_Basic_0__Array_qsort_sort___at___00JunkValues_elabJunkCheck_spec__7___redArg___lam__0(uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_QSort_Basic_0__Array_qsort_sort___at___00JunkValues_elabJunkCheck_spec__7___redArg___lam__0___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_QSort_Basic_0__Array_qpartition_loop___at___00__private_Init_Data_Array_QSort_Basic_0__Array_qsort_sort___at___00JunkValues_elabJunkCheck_spec__7_spec__10___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_QSort_Basic_0__Array_qpartition_loop___at___00__private_Init_Data_Array_QSort_Basic_0__Array_qsort_sort___at___00JunkValues_elabJunkCheck_spec__7_spec__10___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_QSort_Basic_0__Array_qsort_sort___at___00JunkValues_elabJunkCheck_spec__7___redArg(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_QSort_Basic_0__Array_qsort_sort___at___00JunkValues_elabJunkCheck_spec__7___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_addMessageContextFull___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__7(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_addMessageContextFull___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__7___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static lean_once_cell_t lp_JunkValues_List_foldl___at___00Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8_spec__11___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_List_foldl___at___00Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8_spec__11___closed__0;
static const lean_string_object lp_JunkValues_List_foldl___at___00Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8_spec__11___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 16, .m_capacity = 16, .m_length = 15, .m_data = "while expanding"};
static const lean_object* lp_JunkValues_List_foldl___at___00Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8_spec__11___closed__1 = (const lean_object*)&lp_JunkValues_List_foldl___at___00Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8_spec__11___closed__1_value;
static const lean_ctor_object lp_JunkValues_List_foldl___at___00Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8_spec__11___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_JunkValues_List_foldl___at___00Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8_spec__11___closed__1_value)}};
static const lean_object* lp_JunkValues_List_foldl___at___00Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8_spec__11___closed__2 = (const lean_object*)&lp_JunkValues_List_foldl___at___00Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8_spec__11___closed__2_value;
static lean_once_cell_t lp_JunkValues_List_foldl___at___00Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8_spec__11___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_List_foldl___at___00Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8_spec__11___closed__3;
LEAN_EXPORT lean_object* lp_JunkValues_List_foldl___at___00Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8_spec__11(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_JunkValues_Lean_Option_get___at___00Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8_spec__10(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Option_get___at___00Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8_spec__10___boxed(lean_object*, lean_object*);
static const lean_string_object lp_JunkValues_Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 25, .m_capacity = 25, .m_length = 24, .m_data = "with resulting expansion"};
static const lean_object* lp_JunkValues_Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8___redArg___closed__0 = (const lean_object*)&lp_JunkValues_Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8___redArg___closed__0_value;
static const lean_ctor_object lp_JunkValues_Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_JunkValues_Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8___redArg___closed__0_value)}};
static const lean_object* lp_JunkValues_Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8___redArg___closed__1 = (const lean_object*)&lp_JunkValues_Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8___redArg___closed__1_value;
static lean_once_cell_t lp_JunkValues_Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8___redArg___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8___redArg___closed__2;
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object lp_JunkValues_Lean_logAt___at___00Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1_spec__2___redArg___lam__0___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "Elab"};
static const lean_object* lp_JunkValues_Lean_logAt___at___00Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1_spec__2___redArg___lam__0___closed__0 = (const lean_object*)&lp_JunkValues_Lean_logAt___at___00Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1_spec__2___redArg___lam__0___closed__0_value;
static const lean_string_object lp_JunkValues_Lean_logAt___at___00Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1_spec__2___redArg___lam__0___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "Tactic"};
static const lean_object* lp_JunkValues_Lean_logAt___at___00Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1_spec__2___redArg___lam__0___closed__1 = (const lean_object*)&lp_JunkValues_Lean_logAt___at___00Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1_spec__2___redArg___lam__0___closed__1_value;
static const lean_string_object lp_JunkValues_Lean_logAt___at___00Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1_spec__2___redArg___lam__0___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 14, .m_capacity = 14, .m_length = 13, .m_data = "unsolvedGoals"};
static const lean_object* lp_JunkValues_Lean_logAt___at___00Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1_spec__2___redArg___lam__0___closed__2 = (const lean_object*)&lp_JunkValues_Lean_logAt___at___00Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1_spec__2___redArg___lam__0___closed__2_value;
static const lean_string_object lp_JunkValues_Lean_logAt___at___00Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1_spec__2___redArg___lam__0___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 17, .m_capacity = 17, .m_length = 16, .m_data = "synthPlaceholder"};
static const lean_object* lp_JunkValues_Lean_logAt___at___00Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1_spec__2___redArg___lam__0___closed__3 = (const lean_object*)&lp_JunkValues_Lean_logAt___at___00Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1_spec__2___redArg___lam__0___closed__3_value;
static const lean_string_object lp_JunkValues_Lean_logAt___at___00Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1_spec__2___redArg___lam__0___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "lean"};
static const lean_object* lp_JunkValues_Lean_logAt___at___00Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1_spec__2___redArg___lam__0___closed__4 = (const lean_object*)&lp_JunkValues_Lean_logAt___at___00Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1_spec__2___redArg___lam__0___closed__4_value;
static const lean_string_object lp_JunkValues_Lean_logAt___at___00Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1_spec__2___redArg___lam__0___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 20, .m_capacity = 20, .m_length = 19, .m_data = "inductionWithNoAlts"};
static const lean_object* lp_JunkValues_Lean_logAt___at___00Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1_spec__2___redArg___lam__0___closed__5 = (const lean_object*)&lp_JunkValues_Lean_logAt___at___00Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1_spec__2___redArg___lam__0___closed__5_value;
static const lean_string_object lp_JunkValues_Lean_logAt___at___00Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1_spec__2___redArg___lam__0___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 12, .m_capacity = 12, .m_length = 11, .m_data = "_namedError"};
static const lean_object* lp_JunkValues_Lean_logAt___at___00Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1_spec__2___redArg___lam__0___closed__6 = (const lean_object*)&lp_JunkValues_Lean_logAt___at___00Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1_spec__2___redArg___lam__0___closed__6_value;
static const lean_string_object lp_JunkValues_Lean_logAt___at___00Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1_spec__2___redArg___lam__0___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "trace"};
static const lean_object* lp_JunkValues_Lean_logAt___at___00Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1_spec__2___redArg___lam__0___closed__7 = (const lean_object*)&lp_JunkValues_Lean_logAt___at___00Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1_spec__2___redArg___lam__0___closed__7_value;
LEAN_EXPORT uint8_t lp_JunkValues_Lean_logAt___at___00Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1_spec__2___redArg___lam__0(uint8_t, uint8_t, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_logAt___at___00Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1_spec__2___redArg___lam__0___boxed(lean_object*, lean_object*, lean_object*);
static const lean_string_object lp_JunkValues_Lean_logAt___at___00Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1_spec__2___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 1, .m_capacity = 1, .m_length = 0, .m_data = ""};
static const lean_object* lp_JunkValues_Lean_logAt___at___00Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1_spec__2___redArg___closed__0 = (const lean_object*)&lp_JunkValues_Lean_logAt___at___00Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1_spec__2___redArg___closed__0_value;
LEAN_EXPORT lean_object* lp_JunkValues_Lean_logAt___at___00Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1_spec__2___redArg(lean_object*, lean_object*, uint8_t, uint8_t, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_logAt___at___00Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1_spec__2___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1(lean_object*, uint8_t, uint8_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_logInfo___at___00JunkValues_elabJunkCheck_spec__4(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_logInfo___at___00JunkValues_elabJunkCheck_spec__4___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__2___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 17, .m_capacity = 17, .m_length = 16, .m_data = "could not scan `"};
static const lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__2___closed__0 = (const lean_object*)&lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__2___closed__0_value;
static lean_once_cell_t lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__2___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__2___closed__1;
static const lean_string_object lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__2___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "`: "};
static const lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__2___closed__2 = (const lean_object*)&lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__2___closed__2_value;
static lean_once_cell_t lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__2___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__2___closed__3;
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__2(lean_object*, size_t, size_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__2___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__5(lean_object*, size_t, size_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__5___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static lean_once_cell_t lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__0;
static const lean_string_object lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = " of "};
static const lean_object* lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__1 = (const lean_object*)&lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__1_value;
static lean_once_cell_t lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__2;
static const lean_string_object lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 18, .m_capacity = 18, .m_length = 17, .m_data = " declaration(s), "};
static const lean_object* lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__3 = (const lean_object*)&lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__3_value;
static lean_once_cell_t lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__4_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__4;
static const lean_string_object lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = " rules"};
static const lean_object* lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__5 = (const lean_object*)&lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__5_value;
static lean_once_cell_t lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__6_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__6;
static const lean_string_object lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 25, .m_capacity = 25, .m_length = 24, .m_data = "no junk values found in "};
static const lean_object* lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__7 = (const lean_object*)&lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__7_value;
static lean_once_cell_t lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__8_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__8;
static const lean_string_object lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 23, .m_capacity = 23, .m_length = 22, .m_data = " declaration(s), with "};
static const lean_object* lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__9 = (const lean_object*)&lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__9_value;
static lean_once_cell_t lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__10_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__10;
static const lean_string_object lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 56, .m_capacity = 56, .m_length = 55, .m_data = "`#junk_check` needs a declaration or namespace to check"};
static const lean_object* lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__11 = (const lean_object*)&lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__11_value;
static lean_once_cell_t lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__12_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__12;
static const lean_array_object lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__13_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__13 = (const lean_object*)&lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__13_value;
static const lean_string_object lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__14_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 2, .m_capacity = 2, .m_length = 1, .m_data = "`"};
static const lean_object* lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__14 = (const lean_object*)&lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__14_value;
static lean_once_cell_t lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__15_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__15;
static const lean_string_object lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__16_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 67, .m_capacity = 67, .m_length = 66, .m_data = "` is neither a declaration nor a namespace with declarations in it"};
static const lean_object* lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__16 = (const lean_object*)&lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__16_value;
static lean_once_cell_t lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__17_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__17;
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_elabJunkCheck___lam__1(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_elabJunkCheck___lam__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_elabJunkCheck(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_elabJunkCheck___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__0(lean_object*, size_t, size_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_QSort_Basic_0__Array_qsort_sort___at___00JunkValues_elabJunkCheck_spec__7(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_QSort_Basic_0__Array_qsort_sort___at___00JunkValues_elabJunkCheck_spec__7___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_QSort_Basic_0__Array_qpartition_loop___at___00__private_Init_Data_Array_QSort_Basic_0__Array_qsort_sort___at___00JunkValues_elabJunkCheck_spec__7_spec__10(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_QSort_Basic_0__Array_qpartition_loop___at___00__private_Init_Data_Array_QSort_Basic_0__Array_qsort_sort___at___00JunkValues_elabJunkCheck_spec__7_spec__10___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__12(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__12___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__14(lean_object*, lean_object*, lean_object*, size_t, size_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__14___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_logAt___at___00Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1_spec__2(lean_object*, lean_object*, uint8_t, uint8_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_logAt___at___00Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1_spec__2___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13_spec__17___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13_spec__17___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13_spec__17(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13_spec__17___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13_spec__17_spec__18(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13_spec__17_spec__18___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13_spec__17_spec__18_spec__20(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, size_t, size_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13_spec__17_spec__18_spec__20___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Lean_Data_PersistentHashMap_0__Lean_PersistentHashMap_foldlMAux_traverse___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13_spec__17_spec__18_spec__21(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Lean_Data_PersistentHashMap_0__Lean_PersistentHashMap_foldlMAux_traverse___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13_spec__17_spec__18_spec__21___boxed(lean_object**);
static const lean_string_object lp_JunkValues_JunkValues_junkRulesCmd___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 13, .m_capacity = 13, .m_length = 12, .m_data = "junkRulesCmd"};
static const lean_object* lp_JunkValues_JunkValues_junkRulesCmd___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_junkRulesCmd___closed__0_value;
static const lean_ctor_object lp_JunkValues_JunkValues_junkRulesCmd___closed__1_value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_junkCheckCmd___closed__0_value),LEAN_SCALAR_PTR_LITERAL(102, 249, 254, 203, 87, 211, 22, 147)}};
static const lean_ctor_object lp_JunkValues_JunkValues_junkRulesCmd___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_junkRulesCmd___closed__1_value_aux_0),((lean_object*)&lp_JunkValues_JunkValues_junkRulesCmd___closed__0_value),LEAN_SCALAR_PTR_LITERAL(203, 143, 201, 28, 140, 71, 96, 104)}};
static const lean_object* lp_JunkValues_JunkValues_junkRulesCmd___closed__1 = (const lean_object*)&lp_JunkValues_JunkValues_junkRulesCmd___closed__1_value;
static const lean_string_object lp_JunkValues_JunkValues_junkRulesCmd___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 12, .m_capacity = 12, .m_length = 11, .m_data = "#junk_rules"};
static const lean_object* lp_JunkValues_JunkValues_junkRulesCmd___closed__2 = (const lean_object*)&lp_JunkValues_JunkValues_junkRulesCmd___closed__2_value;
static const lean_ctor_object lp_JunkValues_JunkValues_junkRulesCmd___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 5}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_junkRulesCmd___closed__2_value)}};
static const lean_object* lp_JunkValues_JunkValues_junkRulesCmd___closed__3 = (const lean_object*)&lp_JunkValues_JunkValues_junkRulesCmd___closed__3_value;
static const lean_ctor_object lp_JunkValues_JunkValues_junkRulesCmd___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*3 + 0, .m_other = 3, .m_tag = 3}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_junkRulesCmd___closed__1_value),((lean_object*)(((size_t)(1024) << 1) | 1)),((lean_object*)&lp_JunkValues_JunkValues_junkRulesCmd___closed__3_value)}};
static const lean_object* lp_JunkValues_JunkValues_junkRulesCmd___closed__4 = (const lean_object*)&lp_JunkValues_JunkValues_junkRulesCmd___closed__4_value;
LEAN_EXPORT const lean_object* lp_JunkValues_JunkValues_junkRulesCmd = (const lean_object*)&lp_JunkValues_JunkValues_junkRulesCmd___closed__4_value;
static const lean_string_object lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkRules_spec__1___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "  "};
static const lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkRules_spec__1___redArg___closed__0 = (const lean_object*)&lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkRules_spec__1___redArg___closed__0_value;
static lean_once_cell_t lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkRules_spec__1___redArg___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkRules_spec__1___redArg___closed__1;
static const lean_string_object lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkRules_spec__1___redArg___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = " (arity "};
static const lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkRules_spec__1___redArg___closed__2 = (const lean_object*)&lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkRules_spec__1___redArg___closed__2_value;
static lean_once_cell_t lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkRules_spec__1___redArg___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkRules_spec__1___redArg___closed__3;
static const lean_string_object lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkRules_spec__1___redArg___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 6, .m_data = ")  ←  "};
static const lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkRules_spec__1___redArg___closed__4 = (const lean_object*)&lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkRules_spec__1___redArg___closed__4_value;
static lean_once_cell_t lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkRules_spec__1___redArg___closed__5_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkRules_spec__1___redArg___closed__5;
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkRules_spec__1___redArg(lean_object*, size_t, size_t, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkRules_spec__1___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object lp_JunkValues_List_mapTR_loop___at___00JunkValues_elabJunkRules_spec__0___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = " from "};
static const lean_object* lp_JunkValues_List_mapTR_loop___at___00JunkValues_elabJunkRules_spec__0___closed__0 = (const lean_object*)&lp_JunkValues_List_mapTR_loop___at___00JunkValues_elabJunkRules_spec__0___closed__0_value;
LEAN_EXPORT lean_object* lp_JunkValues_List_mapTR_loop___at___00JunkValues_elabJunkRules_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00JunkValues_elabJunkRules_spec__2(lean_object*, size_t, size_t, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00JunkValues_elabJunkRules_spec__2___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object lp_JunkValues_JunkValues_elabJunkRules___redArg___lam__0___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 27, .m_capacity = 27, .m_length = 26, .m_data = " junk-value rules in scope"};
static const lean_object* lp_JunkValues_JunkValues_elabJunkRules___redArg___lam__0___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_elabJunkRules___redArg___lam__0___closed__0_value;
static lean_once_cell_t lp_JunkValues_JunkValues_elabJunkRules___redArg___lam__0___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_elabJunkRules___redArg___lam__0___closed__1;
static const lean_string_object lp_JunkValues_JunkValues_elabJunkRules___redArg___lam__0___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = ", "};
static const lean_object* lp_JunkValues_JunkValues_elabJunkRules___redArg___lam__0___closed__2 = (const lean_object*)&lp_JunkValues_JunkValues_elabJunkRules___redArg___lam__0___closed__2_value;
static const lean_string_object lp_JunkValues_JunkValues_elabJunkRules___redArg___lam__0___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = " ("};
static const lean_object* lp_JunkValues_JunkValues_elabJunkRules___redArg___lam__0___closed__3 = (const lean_object*)&lp_JunkValues_JunkValues_elabJunkRules___redArg___lam__0___closed__3_value;
static lean_once_cell_t lp_JunkValues_JunkValues_elabJunkRules___redArg___lam__0___closed__4_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_elabJunkRules___redArg___lam__0___closed__4;
static const lean_string_object lp_JunkValues_JunkValues_elabJunkRules___redArg___lam__0___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "):\n"};
static const lean_object* lp_JunkValues_JunkValues_elabJunkRules___redArg___lam__0___closed__5 = (const lean_object*)&lp_JunkValues_JunkValues_elabJunkRules___redArg___lam__0___closed__5_value;
static lean_once_cell_t lp_JunkValues_JunkValues_elabJunkRules___redArg___lam__0___closed__6_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_elabJunkRules___redArg___lam__0___closed__6;
static const lean_string_object lp_JunkValues_JunkValues_elabJunkRules___redArg___lam__0___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 192, .m_capacity = 192, .m_length = 189, .m_data = ".\n\nNothing has annotated a junk value with `@[junk_value]`, and no optional rule source is imported. For Mathlib's junk values, add `import JunkValues.Extra` — see `JunkValues/Extra.lean`.\n"};
static const lean_object* lp_JunkValues_JunkValues_elabJunkRules___redArg___lam__0___closed__7 = (const lean_object*)&lp_JunkValues_JunkValues_elabJunkRules___redArg___lam__0___closed__7_value;
static lean_once_cell_t lp_JunkValues_JunkValues_elabJunkRules___redArg___lam__0___closed__8_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_elabJunkRules___redArg___lam__0___closed__8;
static const lean_array_object lp_JunkValues_JunkValues_elabJunkRules___redArg___lam__0___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* lp_JunkValues_JunkValues_elabJunkRules___redArg___lam__0___closed__9 = (const lean_object*)&lp_JunkValues_JunkValues_elabJunkRules___redArg___lam__0___closed__9_value;
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_elabJunkRules___redArg___lam__0(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_elabJunkRules___redArg___lam__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_elabJunkRules___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_elabJunkRules___redArg___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_elabJunkRules(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_elabJunkRules___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkRules_spec__1(lean_object*, size_t, size_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkRules_spec__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_elabJunkCheck___lam__0(lean_object* v___x_41_, uint8_t v___x_42_, lean_object* v_val_43_, lean_object* v_x_44_, lean_object* v_y_45_, lean_object* v___y_46_, lean_object* v___y_47_, lean_object* v___y_48_, lean_object* v___y_49_, lean_object* v___y_50_, lean_object* v___y_51_, lean_object* v___y_52_){
_start:
{
lean_object* v_a_55_; uint8_t v___y_62_; uint8_t v___y_65_; uint8_t v___x_67_; 
v___x_67_ = l_Lean_Name_isPrefixOf(v_val_43_, v_x_44_);
if (v___x_67_ == 0)
{
v___y_65_ = v___x_67_;
goto v___jp_64_;
}
else
{
uint8_t v___x_68_; 
v___x_68_ = l_Lean_Name_isInternal(v_x_44_);
if (v___x_68_ == 0)
{
v___y_65_ = v___x_67_;
goto v___jp_64_;
}
else
{
v___y_65_ = v___x_42_;
goto v___jp_64_;
}
}
v___jp_54_:
{
lean_object* v___x_56_; lean_object* v___x_57_; lean_object* v___x_58_; 
v___x_56_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_56_, 0, v___x_41_);
lean_ctor_set(v___x_56_, 1, v_a_55_);
v___x_57_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_57_, 0, v___x_56_);
v___x_58_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_58_, 0, v___x_57_);
return v___x_58_;
}
v___jp_59_:
{
lean_object* v___x_60_; 
v___x_60_ = lean_array_push(v___y_46_, v_x_44_);
v_a_55_ = v___x_60_;
goto v___jp_54_;
}
v___jp_61_:
{
if (v___y_62_ == 0)
{
lean_dec(v_x_44_);
v_a_55_ = v___y_46_;
goto v___jp_54_;
}
else
{
goto v___jp_59_;
}
}
v___jp_63_:
{
switch(lean_obj_tag(v_y_45_))
{
case 6:
{
v___y_62_ = v___x_42_;
goto v___jp_61_;
}
case 7:
{
v___y_62_ = v___x_42_;
goto v___jp_61_;
}
default: 
{
goto v___jp_59_;
}
}
}
v___jp_64_:
{
if (v___y_65_ == 0)
{
lean_dec(v_x_44_);
v_a_55_ = v___y_46_;
goto v___jp_54_;
}
else
{
uint8_t v___x_66_; 
v___x_66_ = l_Lean_Name_isImplementationDetail(v_x_44_);
if (v___x_66_ == 0)
{
goto v___jp_63_;
}
else
{
if (v___x_42_ == 0)
{
lean_dec(v_x_44_);
v_a_55_ = v___y_46_;
goto v___jp_54_;
}
else
{
goto v___jp_63_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_elabJunkCheck___lam__0___boxed(lean_object* v___x_69_, lean_object* v___x_70_, lean_object* v_val_71_, lean_object* v_x_72_, lean_object* v_y_73_, lean_object* v___y_74_, lean_object* v___y_75_, lean_object* v___y_76_, lean_object* v___y_77_, lean_object* v___y_78_, lean_object* v___y_79_, lean_object* v___y_80_, lean_object* v___y_81_){
_start:
{
uint8_t v___x_20127__boxed_82_; lean_object* v_res_83_; 
v___x_20127__boxed_82_ = lean_unbox(v___x_70_);
v_res_83_ = lp_JunkValues_JunkValues_elabJunkCheck___lam__0(v___x_69_, v___x_20127__boxed_82_, v_val_71_, v_x_72_, v_y_73_, v___y_74_, v___y_75_, v___y_76_, v___y_77_, v___y_78_, v___y_79_, v___y_80_);
lean_dec(v___y_80_);
lean_dec_ref(v___y_79_);
lean_dec(v___y_78_);
lean_dec_ref(v___y_77_);
lean_dec(v___y_76_);
lean_dec_ref(v___y_75_);
lean_dec_ref(v_y_73_);
lean_dec(v_val_71_);
return v_res_83_;
}
}
static lean_object* _init_lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__0___redArg___closed__1(void){
_start:
{
lean_object* v___x_85_; lean_object* v___x_86_; 
v___x_85_ = ((lean_object*)(lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__0___redArg___closed__0));
v___x_86_ = l_Lean_stringToMessageData(v___x_85_);
return v___x_86_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__0___redArg(lean_object* v_as_87_, size_t v_sz_88_, size_t v_i_89_, lean_object* v_b_90_){
_start:
{
uint8_t v___x_92_; 
v___x_92_ = lean_usize_dec_lt(v_i_89_, v_sz_88_);
if (v___x_92_ == 0)
{
lean_object* v___x_93_; 
v___x_93_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_93_, 0, v_b_90_);
return v___x_93_;
}
else
{
lean_object* v_a_94_; lean_object* v___x_95_; lean_object* v___x_96_; lean_object* v___x_97_; lean_object* v___x_98_; size_t v___x_99_; size_t v___x_100_; 
v_a_94_ = lean_array_uget_borrowed(v_as_87_, v_i_89_);
lean_inc(v_a_94_);
v___x_95_ = lp_JunkValues_JunkValues_warningOf(v_a_94_);
v___x_96_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_96_, 0, v_b_90_);
lean_ctor_set(v___x_96_, 1, v___x_95_);
v___x_97_ = lean_obj_once(&lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__0___redArg___closed__1, &lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__0___redArg___closed__1_once, _init_lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__0___redArg___closed__1);
v___x_98_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_98_, 0, v___x_96_);
lean_ctor_set(v___x_98_, 1, v___x_97_);
v___x_99_ = ((size_t)1ULL);
v___x_100_ = lean_usize_add(v_i_89_, v___x_99_);
v_i_89_ = v___x_100_;
v_b_90_ = v___x_98_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__0___redArg___boxed(lean_object* v_as_102_, lean_object* v_sz_103_, lean_object* v_i_104_, lean_object* v_b_105_, lean_object* v___y_106_){
_start:
{
size_t v_sz_boxed_107_; size_t v_i_boxed_108_; lean_object* v_res_109_; 
v_sz_boxed_107_ = lean_unbox_usize(v_sz_103_);
lean_dec(v_sz_103_);
v_i_boxed_108_ = lean_unbox_usize(v_i_104_);
lean_dec(v_i_104_);
v_res_109_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__0___redArg(v_as_102_, v_sz_boxed_107_, v_i_boxed_108_, v_b_105_);
lean_dec_ref(v_as_102_);
return v_res_109_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__3(lean_object* v_as_110_, size_t v_sz_111_, size_t v_i_112_, lean_object* v_b_113_, lean_object* v___y_114_, lean_object* v___y_115_, lean_object* v___y_116_, lean_object* v___y_117_, lean_object* v___y_118_, lean_object* v___y_119_){
_start:
{
uint8_t v___x_121_; 
v___x_121_ = lean_usize_dec_lt(v_i_112_, v_sz_111_);
if (v___x_121_ == 0)
{
lean_object* v___x_122_; 
v___x_122_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_122_, 0, v_b_113_);
return v___x_122_;
}
else
{
lean_object* v_a_123_; lean_object* v_findings_124_; size_t v_sz_125_; size_t v___x_126_; lean_object* v___x_127_; 
v_a_123_ = lean_array_uget_borrowed(v_as_110_, v_i_112_);
v_findings_124_ = lean_ctor_get(v_a_123_, 1);
v_sz_125_ = lean_array_size(v_findings_124_);
v___x_126_ = ((size_t)0ULL);
v___x_127_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__0___redArg(v_findings_124_, v_sz_125_, v___x_126_, v_b_113_);
if (lean_obj_tag(v___x_127_) == 0)
{
lean_object* v_a_128_; size_t v___x_129_; size_t v___x_130_; 
v_a_128_ = lean_ctor_get(v___x_127_, 0);
lean_inc(v_a_128_);
lean_dec_ref_known(v___x_127_, 1);
v___x_129_ = ((size_t)1ULL);
v___x_130_ = lean_usize_add(v_i_112_, v___x_129_);
v_i_112_ = v___x_130_;
v_b_113_ = v_a_128_;
goto _start;
}
else
{
return v___x_127_;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__3___boxed(lean_object* v_as_132_, lean_object* v_sz_133_, lean_object* v_i_134_, lean_object* v_b_135_, lean_object* v___y_136_, lean_object* v___y_137_, lean_object* v___y_138_, lean_object* v___y_139_, lean_object* v___y_140_, lean_object* v___y_141_, lean_object* v___y_142_){
_start:
{
size_t v_sz_boxed_143_; size_t v_i_boxed_144_; lean_object* v_res_145_; 
v_sz_boxed_143_ = lean_unbox_usize(v_sz_133_);
lean_dec(v_sz_133_);
v_i_boxed_144_ = lean_unbox_usize(v_i_134_);
lean_dec(v_i_134_);
v_res_145_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__3(v_as_132_, v_sz_boxed_143_, v_i_boxed_144_, v_b_135_, v___y_136_, v___y_137_, v___y_138_, v___y_139_, v___y_140_, v___y_141_);
lean_dec(v___y_141_);
lean_dec_ref(v___y_140_);
lean_dec(v___y_139_);
lean_dec_ref(v___y_138_);
lean_dec(v___y_137_);
lean_dec_ref(v___y_136_);
lean_dec_ref(v_as_132_);
return v_res_145_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__12___redArg(lean_object* v_f_146_, lean_object* v_x_147_, lean_object* v_x_148_, lean_object* v___y_149_, lean_object* v___y_150_, lean_object* v___y_151_, lean_object* v___y_152_, lean_object* v___y_153_, lean_object* v___y_154_, lean_object* v___y_155_){
_start:
{
if (lean_obj_tag(v_x_148_) == 0)
{
lean_object* v___x_157_; lean_object* v___x_158_; lean_object* v___x_159_; 
lean_dec_ref(v_f_146_);
v___x_157_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_157_, 0, v_x_147_);
lean_ctor_set(v___x_157_, 1, v___y_149_);
v___x_158_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_158_, 0, v___x_157_);
v___x_159_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_159_, 0, v___x_158_);
return v___x_159_;
}
else
{
lean_object* v_key_160_; lean_object* v_value_161_; lean_object* v_tail_162_; lean_object* v___x_163_; 
v_key_160_ = lean_ctor_get(v_x_148_, 0);
lean_inc(v_key_160_);
v_value_161_ = lean_ctor_get(v_x_148_, 1);
lean_inc(v_value_161_);
v_tail_162_ = lean_ctor_get(v_x_148_, 2);
lean_inc(v_tail_162_);
lean_dec_ref_known(v_x_148_, 3);
lean_inc_ref(v_f_146_);
lean_inc(v___y_155_);
lean_inc_ref(v___y_154_);
lean_inc(v___y_153_);
lean_inc_ref(v___y_152_);
lean_inc(v___y_151_);
lean_inc_ref(v___y_150_);
v___x_163_ = lean_apply_10(v_f_146_, v_key_160_, v_value_161_, v___y_149_, v___y_150_, v___y_151_, v___y_152_, v___y_153_, v___y_154_, v___y_155_, lean_box(0));
if (lean_obj_tag(v___x_163_) == 0)
{
lean_object* v_a_164_; 
v_a_164_ = lean_ctor_get(v___x_163_, 0);
lean_inc(v_a_164_);
if (lean_obj_tag(v_a_164_) == 0)
{
lean_dec_ref_known(v_a_164_, 1);
lean_dec(v_tail_162_);
lean_dec_ref(v_f_146_);
return v___x_163_;
}
else
{
lean_object* v_a_165_; lean_object* v_fst_166_; lean_object* v_snd_167_; 
lean_dec_ref_known(v___x_163_, 1);
v_a_165_ = lean_ctor_get(v_a_164_, 0);
lean_inc(v_a_165_);
lean_dec_ref_known(v_a_164_, 1);
v_fst_166_ = lean_ctor_get(v_a_165_, 0);
lean_inc(v_fst_166_);
v_snd_167_ = lean_ctor_get(v_a_165_, 1);
lean_inc(v_snd_167_);
lean_dec(v_a_165_);
v_x_147_ = v_fst_166_;
v_x_148_ = v_tail_162_;
v___y_149_ = v_snd_167_;
goto _start;
}
}
else
{
lean_dec(v_tail_162_);
lean_dec_ref(v_f_146_);
return v___x_163_;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__12___redArg___boxed(lean_object* v_f_169_, lean_object* v_x_170_, lean_object* v_x_171_, lean_object* v___y_172_, lean_object* v___y_173_, lean_object* v___y_174_, lean_object* v___y_175_, lean_object* v___y_176_, lean_object* v___y_177_, lean_object* v___y_178_, lean_object* v___y_179_){
_start:
{
lean_object* v_res_180_; 
v_res_180_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__12___redArg(v_f_169_, v_x_170_, v_x_171_, v___y_172_, v___y_173_, v___y_174_, v___y_175_, v___y_176_, v___y_177_, v___y_178_);
lean_dec(v___y_178_);
lean_dec_ref(v___y_177_);
lean_dec(v___y_176_);
lean_dec_ref(v___y_175_);
lean_dec(v___y_174_);
lean_dec_ref(v___y_173_);
return v_res_180_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__14___redArg(lean_object* v_f_181_, lean_object* v_as_182_, size_t v_i_183_, size_t v_stop_184_, lean_object* v_b_185_, lean_object* v___y_186_, lean_object* v___y_187_, lean_object* v___y_188_, lean_object* v___y_189_, lean_object* v___y_190_, lean_object* v___y_191_, lean_object* v___y_192_){
_start:
{
uint8_t v___x_194_; 
v___x_194_ = lean_usize_dec_eq(v_i_183_, v_stop_184_);
if (v___x_194_ == 0)
{
lean_object* v___x_195_; lean_object* v___x_196_; lean_object* v___x_197_; 
v___x_195_ = lean_array_uget_borrowed(v_as_182_, v_i_183_);
v___x_196_ = lean_box(0);
lean_inc(v___x_195_);
lean_inc_ref(v_f_181_);
v___x_197_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__12___redArg(v_f_181_, v___x_196_, v___x_195_, v___y_186_, v___y_187_, v___y_188_, v___y_189_, v___y_190_, v___y_191_, v___y_192_);
if (lean_obj_tag(v___x_197_) == 0)
{
lean_object* v_a_198_; 
v_a_198_ = lean_ctor_get(v___x_197_, 0);
lean_inc(v_a_198_);
if (lean_obj_tag(v_a_198_) == 0)
{
lean_dec_ref_known(v_a_198_, 1);
lean_dec_ref(v_f_181_);
return v___x_197_;
}
else
{
lean_object* v_a_199_; lean_object* v_fst_200_; lean_object* v_snd_201_; size_t v___x_202_; size_t v___x_203_; 
lean_dec_ref_known(v___x_197_, 1);
v_a_199_ = lean_ctor_get(v_a_198_, 0);
lean_inc(v_a_199_);
lean_dec_ref_known(v_a_198_, 1);
v_fst_200_ = lean_ctor_get(v_a_199_, 0);
lean_inc(v_fst_200_);
v_snd_201_ = lean_ctor_get(v_a_199_, 1);
lean_inc(v_snd_201_);
lean_dec(v_a_199_);
v___x_202_ = ((size_t)1ULL);
v___x_203_ = lean_usize_add(v_i_183_, v___x_202_);
v_i_183_ = v___x_203_;
v_b_185_ = v_fst_200_;
v___y_186_ = v_snd_201_;
goto _start;
}
}
else
{
lean_dec_ref(v_f_181_);
return v___x_197_;
}
}
else
{
lean_object* v___x_205_; lean_object* v___x_206_; lean_object* v___x_207_; 
lean_dec_ref(v_f_181_);
v___x_205_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_205_, 0, v_b_185_);
lean_ctor_set(v___x_205_, 1, v___y_186_);
v___x_206_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_206_, 0, v___x_205_);
v___x_207_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_207_, 0, v___x_206_);
return v___x_207_;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__14___redArg___boxed(lean_object* v_f_208_, lean_object* v_as_209_, lean_object* v_i_210_, lean_object* v_stop_211_, lean_object* v_b_212_, lean_object* v___y_213_, lean_object* v___y_214_, lean_object* v___y_215_, lean_object* v___y_216_, lean_object* v___y_217_, lean_object* v___y_218_, lean_object* v___y_219_, lean_object* v___y_220_){
_start:
{
size_t v_i_boxed_221_; size_t v_stop_boxed_222_; lean_object* v_res_223_; 
v_i_boxed_221_ = lean_unbox_usize(v_i_210_);
lean_dec(v_i_210_);
v_stop_boxed_222_ = lean_unbox_usize(v_stop_211_);
lean_dec(v_stop_211_);
v_res_223_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__14___redArg(v_f_208_, v_as_209_, v_i_boxed_221_, v_stop_boxed_222_, v_b_212_, v___y_213_, v___y_214_, v___y_215_, v___y_216_, v___y_217_, v___y_218_, v___y_219_);
lean_dec(v___y_219_);
lean_dec_ref(v___y_218_);
lean_dec(v___y_217_);
lean_dec_ref(v___y_216_);
lean_dec(v___y_215_);
lean_dec_ref(v___y_214_);
lean_dec_ref(v_as_209_);
return v_res_223_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13___redArg___lam__0(lean_object* v_f_224_, lean_object* v_x_225_, lean_object* v___y_226_, lean_object* v___y_227_, lean_object* v___y_228_, lean_object* v___y_229_, lean_object* v___y_230_, lean_object* v___y_231_, lean_object* v___y_232_, lean_object* v___y_233_, lean_object* v___y_234_){
_start:
{
lean_object* v___x_236_; 
lean_inc(v___y_234_);
lean_inc_ref(v___y_233_);
lean_inc(v___y_232_);
lean_inc_ref(v___y_231_);
lean_inc(v___y_230_);
lean_inc_ref(v___y_229_);
v___x_236_ = lean_apply_10(v_f_224_, v___y_226_, v___y_227_, v___y_228_, v___y_229_, v___y_230_, v___y_231_, v___y_232_, v___y_233_, v___y_234_, lean_box(0));
return v___x_236_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13___redArg___lam__0___boxed(lean_object* v_f_237_, lean_object* v_x_238_, lean_object* v___y_239_, lean_object* v___y_240_, lean_object* v___y_241_, lean_object* v___y_242_, lean_object* v___y_243_, lean_object* v___y_244_, lean_object* v___y_245_, lean_object* v___y_246_, lean_object* v___y_247_, lean_object* v___y_248_){
_start:
{
lean_object* v_res_249_; 
v_res_249_ = lp_JunkValues_Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13___redArg___lam__0(v_f_237_, v_x_238_, v___y_239_, v___y_240_, v___y_241_, v___y_242_, v___y_243_, v___y_244_, v___y_245_, v___y_246_, v___y_247_);
lean_dec(v___y_247_);
lean_dec_ref(v___y_246_);
lean_dec(v___y_245_);
lean_dec_ref(v___y_244_);
lean_dec(v___y_243_);
lean_dec_ref(v___y_242_);
return v_res_249_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Lean_Data_PersistentHashMap_0__Lean_PersistentHashMap_foldlMAux_traverse___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13_spec__17_spec__18_spec__21___redArg(lean_object* v_f_250_, lean_object* v_keys_251_, lean_object* v_vals_252_, lean_object* v_i_253_, lean_object* v_acc_254_, lean_object* v___y_255_, lean_object* v___y_256_, lean_object* v___y_257_, lean_object* v___y_258_, lean_object* v___y_259_, lean_object* v___y_260_, lean_object* v___y_261_){
_start:
{
lean_object* v___x_263_; uint8_t v___x_264_; 
v___x_263_ = lean_array_get_size(v_keys_251_);
v___x_264_ = lean_nat_dec_lt(v_i_253_, v___x_263_);
if (v___x_264_ == 0)
{
lean_object* v___x_265_; lean_object* v___x_266_; lean_object* v___x_267_; 
lean_dec(v_i_253_);
lean_dec_ref(v_f_250_);
v___x_265_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_265_, 0, v_acc_254_);
lean_ctor_set(v___x_265_, 1, v___y_255_);
v___x_266_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_266_, 0, v___x_265_);
v___x_267_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_267_, 0, v___x_266_);
return v___x_267_;
}
else
{
lean_object* v_k_268_; lean_object* v_v_269_; lean_object* v___x_270_; 
v_k_268_ = lean_array_fget_borrowed(v_keys_251_, v_i_253_);
v_v_269_ = lean_array_fget_borrowed(v_vals_252_, v_i_253_);
lean_inc_ref(v_f_250_);
lean_inc(v___y_261_);
lean_inc_ref(v___y_260_);
lean_inc(v___y_259_);
lean_inc_ref(v___y_258_);
lean_inc(v___y_257_);
lean_inc_ref(v___y_256_);
lean_inc(v_v_269_);
lean_inc(v_k_268_);
v___x_270_ = lean_apply_11(v_f_250_, v_acc_254_, v_k_268_, v_v_269_, v___y_255_, v___y_256_, v___y_257_, v___y_258_, v___y_259_, v___y_260_, v___y_261_, lean_box(0));
if (lean_obj_tag(v___x_270_) == 0)
{
lean_object* v_a_271_; 
v_a_271_ = lean_ctor_get(v___x_270_, 0);
lean_inc(v_a_271_);
if (lean_obj_tag(v_a_271_) == 0)
{
lean_dec_ref_known(v_a_271_, 1);
lean_dec(v_i_253_);
lean_dec_ref(v_f_250_);
return v___x_270_;
}
else
{
lean_object* v_a_272_; lean_object* v_fst_273_; lean_object* v_snd_274_; lean_object* v___x_275_; lean_object* v___x_276_; 
lean_dec_ref_known(v___x_270_, 1);
v_a_272_ = lean_ctor_get(v_a_271_, 0);
lean_inc(v_a_272_);
lean_dec_ref_known(v_a_271_, 1);
v_fst_273_ = lean_ctor_get(v_a_272_, 0);
lean_inc(v_fst_273_);
v_snd_274_ = lean_ctor_get(v_a_272_, 1);
lean_inc(v_snd_274_);
lean_dec(v_a_272_);
v___x_275_ = lean_unsigned_to_nat(1u);
v___x_276_ = lean_nat_add(v_i_253_, v___x_275_);
lean_dec(v_i_253_);
v_i_253_ = v___x_276_;
v_acc_254_ = v_fst_273_;
v___y_255_ = v_snd_274_;
goto _start;
}
}
else
{
lean_dec(v_i_253_);
lean_dec_ref(v_f_250_);
return v___x_270_;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Lean_Data_PersistentHashMap_0__Lean_PersistentHashMap_foldlMAux_traverse___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13_spec__17_spec__18_spec__21___redArg___boxed(lean_object* v_f_278_, lean_object* v_keys_279_, lean_object* v_vals_280_, lean_object* v_i_281_, lean_object* v_acc_282_, lean_object* v___y_283_, lean_object* v___y_284_, lean_object* v___y_285_, lean_object* v___y_286_, lean_object* v___y_287_, lean_object* v___y_288_, lean_object* v___y_289_, lean_object* v___y_290_){
_start:
{
lean_object* v_res_291_; 
v_res_291_ = lp_JunkValues___private_Lean_Data_PersistentHashMap_0__Lean_PersistentHashMap_foldlMAux_traverse___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13_spec__17_spec__18_spec__21___redArg(v_f_278_, v_keys_279_, v_vals_280_, v_i_281_, v_acc_282_, v___y_283_, v___y_284_, v___y_285_, v___y_286_, v___y_287_, v___y_288_, v___y_289_);
lean_dec(v___y_289_);
lean_dec_ref(v___y_288_);
lean_dec(v___y_287_);
lean_dec_ref(v___y_286_);
lean_dec(v___y_285_);
lean_dec_ref(v___y_284_);
lean_dec_ref(v_vals_280_);
lean_dec_ref(v_keys_279_);
return v_res_291_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13_spec__17_spec__18___redArg(lean_object* v_f_292_, lean_object* v_x_293_, lean_object* v_x_294_, lean_object* v___y_295_, lean_object* v___y_296_, lean_object* v___y_297_, lean_object* v___y_298_, lean_object* v___y_299_, lean_object* v___y_300_, lean_object* v___y_301_){
_start:
{
if (lean_obj_tag(v_x_293_) == 0)
{
lean_object* v_es_303_; lean_object* v___x_305_; uint8_t v_isShared_306_; uint8_t v_isSharedCheck_327_; 
v_es_303_ = lean_ctor_get(v_x_293_, 0);
v_isSharedCheck_327_ = !lean_is_exclusive(v_x_293_);
if (v_isSharedCheck_327_ == 0)
{
v___x_305_ = v_x_293_;
v_isShared_306_ = v_isSharedCheck_327_;
goto v_resetjp_304_;
}
else
{
lean_inc(v_es_303_);
lean_dec(v_x_293_);
v___x_305_ = lean_box(0);
v_isShared_306_ = v_isSharedCheck_327_;
goto v_resetjp_304_;
}
v_resetjp_304_:
{
lean_object* v___x_307_; lean_object* v___x_308_; uint8_t v___x_309_; 
v___x_307_ = lean_unsigned_to_nat(0u);
v___x_308_ = lean_array_get_size(v_es_303_);
v___x_309_ = lean_nat_dec_lt(v___x_307_, v___x_308_);
if (v___x_309_ == 0)
{
lean_object* v___x_310_; lean_object* v___x_312_; 
lean_dec_ref(v_es_303_);
lean_dec_ref(v_f_292_);
v___x_310_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_310_, 0, v_x_294_);
lean_ctor_set(v___x_310_, 1, v___y_295_);
if (v_isShared_306_ == 0)
{
lean_ctor_set_tag(v___x_305_, 1);
lean_ctor_set(v___x_305_, 0, v___x_310_);
v___x_312_ = v___x_305_;
goto v_reusejp_311_;
}
else
{
lean_object* v_reuseFailAlloc_314_; 
v_reuseFailAlloc_314_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_314_, 0, v___x_310_);
v___x_312_ = v_reuseFailAlloc_314_;
goto v_reusejp_311_;
}
v_reusejp_311_:
{
lean_object* v___x_313_; 
v___x_313_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_313_, 0, v___x_312_);
return v___x_313_;
}
}
else
{
uint8_t v___x_315_; 
v___x_315_ = lean_nat_dec_le(v___x_308_, v___x_308_);
if (v___x_315_ == 0)
{
if (v___x_309_ == 0)
{
lean_object* v___x_316_; lean_object* v___x_318_; 
lean_dec_ref(v_es_303_);
lean_dec_ref(v_f_292_);
v___x_316_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_316_, 0, v_x_294_);
lean_ctor_set(v___x_316_, 1, v___y_295_);
if (v_isShared_306_ == 0)
{
lean_ctor_set_tag(v___x_305_, 1);
lean_ctor_set(v___x_305_, 0, v___x_316_);
v___x_318_ = v___x_305_;
goto v_reusejp_317_;
}
else
{
lean_object* v_reuseFailAlloc_320_; 
v_reuseFailAlloc_320_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_320_, 0, v___x_316_);
v___x_318_ = v_reuseFailAlloc_320_;
goto v_reusejp_317_;
}
v_reusejp_317_:
{
lean_object* v___x_319_; 
v___x_319_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_319_, 0, v___x_318_);
return v___x_319_;
}
}
else
{
size_t v___x_321_; size_t v___x_322_; lean_object* v___x_323_; 
lean_del_object(v___x_305_);
v___x_321_ = ((size_t)0ULL);
v___x_322_ = lean_usize_of_nat(v___x_308_);
v___x_323_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13_spec__17_spec__18_spec__20___redArg(v_f_292_, v_es_303_, v___x_321_, v___x_322_, v_x_294_, v___y_295_, v___y_296_, v___y_297_, v___y_298_, v___y_299_, v___y_300_, v___y_301_);
lean_dec_ref(v_es_303_);
return v___x_323_;
}
}
else
{
size_t v___x_324_; size_t v___x_325_; lean_object* v___x_326_; 
lean_del_object(v___x_305_);
v___x_324_ = ((size_t)0ULL);
v___x_325_ = lean_usize_of_nat(v___x_308_);
v___x_326_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13_spec__17_spec__18_spec__20___redArg(v_f_292_, v_es_303_, v___x_324_, v___x_325_, v_x_294_, v___y_295_, v___y_296_, v___y_297_, v___y_298_, v___y_299_, v___y_300_, v___y_301_);
lean_dec_ref(v_es_303_);
return v___x_326_;
}
}
}
}
else
{
lean_object* v_ks_328_; lean_object* v_vs_329_; lean_object* v___x_330_; lean_object* v___x_331_; 
v_ks_328_ = lean_ctor_get(v_x_293_, 0);
lean_inc_ref(v_ks_328_);
v_vs_329_ = lean_ctor_get(v_x_293_, 1);
lean_inc_ref(v_vs_329_);
lean_dec_ref_known(v_x_293_, 2);
v___x_330_ = lean_unsigned_to_nat(0u);
v___x_331_ = lp_JunkValues___private_Lean_Data_PersistentHashMap_0__Lean_PersistentHashMap_foldlMAux_traverse___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13_spec__17_spec__18_spec__21___redArg(v_f_292_, v_ks_328_, v_vs_329_, v___x_330_, v_x_294_, v___y_295_, v___y_296_, v___y_297_, v___y_298_, v___y_299_, v___y_300_, v___y_301_);
lean_dec_ref(v_vs_329_);
lean_dec_ref(v_ks_328_);
return v___x_331_;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13_spec__17_spec__18_spec__20___redArg(lean_object* v_f_332_, lean_object* v_as_333_, size_t v_i_334_, size_t v_stop_335_, lean_object* v_b_336_, lean_object* v___y_337_, lean_object* v___y_338_, lean_object* v___y_339_, lean_object* v___y_340_, lean_object* v___y_341_, lean_object* v___y_342_, lean_object* v___y_343_){
_start:
{
lean_object* v_fst_346_; lean_object* v_snd_347_; lean_object* v___y_352_; uint8_t v___x_357_; 
v___x_357_ = lean_usize_dec_eq(v_i_334_, v_stop_335_);
if (v___x_357_ == 0)
{
lean_object* v___x_358_; 
v___x_358_ = lean_array_uget_borrowed(v_as_333_, v_i_334_);
switch(lean_obj_tag(v___x_358_))
{
case 0:
{
lean_object* v_key_359_; lean_object* v_val_360_; lean_object* v___x_361_; 
v_key_359_ = lean_ctor_get(v___x_358_, 0);
v_val_360_ = lean_ctor_get(v___x_358_, 1);
lean_inc_ref(v_f_332_);
lean_inc(v___y_343_);
lean_inc_ref(v___y_342_);
lean_inc(v___y_341_);
lean_inc_ref(v___y_340_);
lean_inc(v___y_339_);
lean_inc_ref(v___y_338_);
lean_inc(v_val_360_);
lean_inc(v_key_359_);
v___x_361_ = lean_apply_11(v_f_332_, v_b_336_, v_key_359_, v_val_360_, v___y_337_, v___y_338_, v___y_339_, v___y_340_, v___y_341_, v___y_342_, v___y_343_, lean_box(0));
v___y_352_ = v___x_361_;
goto v___jp_351_;
}
case 1:
{
lean_object* v_node_362_; lean_object* v___x_363_; 
v_node_362_ = lean_ctor_get(v___x_358_, 0);
lean_inc(v_node_362_);
lean_inc_ref(v_f_332_);
v___x_363_ = lp_JunkValues_Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13_spec__17_spec__18___redArg(v_f_332_, v_node_362_, v_b_336_, v___y_337_, v___y_338_, v___y_339_, v___y_340_, v___y_341_, v___y_342_, v___y_343_);
v___y_352_ = v___x_363_;
goto v___jp_351_;
}
default: 
{
v_fst_346_ = v_b_336_;
v_snd_347_ = v___y_337_;
goto v___jp_345_;
}
}
}
else
{
lean_object* v___x_364_; lean_object* v___x_365_; lean_object* v___x_366_; 
lean_dec_ref(v_f_332_);
v___x_364_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_364_, 0, v_b_336_);
lean_ctor_set(v___x_364_, 1, v___y_337_);
v___x_365_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_365_, 0, v___x_364_);
v___x_366_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_366_, 0, v___x_365_);
return v___x_366_;
}
v___jp_345_:
{
size_t v___x_348_; size_t v___x_349_; 
v___x_348_ = ((size_t)1ULL);
v___x_349_ = lean_usize_add(v_i_334_, v___x_348_);
v_i_334_ = v___x_349_;
v_b_336_ = v_fst_346_;
v___y_337_ = v_snd_347_;
goto _start;
}
v___jp_351_:
{
if (lean_obj_tag(v___y_352_) == 0)
{
lean_object* v_a_353_; 
v_a_353_ = lean_ctor_get(v___y_352_, 0);
if (lean_obj_tag(v_a_353_) == 0)
{
lean_dec_ref(v_f_332_);
return v___y_352_;
}
else
{
lean_object* v_a_354_; lean_object* v_fst_355_; lean_object* v_snd_356_; 
lean_inc_ref(v_a_353_);
lean_dec_ref_known(v___y_352_, 1);
v_a_354_ = lean_ctor_get(v_a_353_, 0);
lean_inc(v_a_354_);
lean_dec_ref_known(v_a_353_, 1);
v_fst_355_ = lean_ctor_get(v_a_354_, 0);
lean_inc(v_fst_355_);
v_snd_356_ = lean_ctor_get(v_a_354_, 1);
lean_inc(v_snd_356_);
lean_dec(v_a_354_);
v_fst_346_ = v_fst_355_;
v_snd_347_ = v_snd_356_;
goto v___jp_345_;
}
}
else
{
lean_dec_ref(v_f_332_);
return v___y_352_;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13_spec__17_spec__18_spec__20___redArg___boxed(lean_object* v_f_367_, lean_object* v_as_368_, lean_object* v_i_369_, lean_object* v_stop_370_, lean_object* v_b_371_, lean_object* v___y_372_, lean_object* v___y_373_, lean_object* v___y_374_, lean_object* v___y_375_, lean_object* v___y_376_, lean_object* v___y_377_, lean_object* v___y_378_, lean_object* v___y_379_){
_start:
{
size_t v_i_boxed_380_; size_t v_stop_boxed_381_; lean_object* v_res_382_; 
v_i_boxed_380_ = lean_unbox_usize(v_i_369_);
lean_dec(v_i_369_);
v_stop_boxed_381_ = lean_unbox_usize(v_stop_370_);
lean_dec(v_stop_370_);
v_res_382_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13_spec__17_spec__18_spec__20___redArg(v_f_367_, v_as_368_, v_i_boxed_380_, v_stop_boxed_381_, v_b_371_, v___y_372_, v___y_373_, v___y_374_, v___y_375_, v___y_376_, v___y_377_, v___y_378_);
lean_dec(v___y_378_);
lean_dec_ref(v___y_377_);
lean_dec(v___y_376_);
lean_dec_ref(v___y_375_);
lean_dec(v___y_374_);
lean_dec_ref(v___y_373_);
lean_dec_ref(v_as_368_);
return v_res_382_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13_spec__17_spec__18___redArg___boxed(lean_object* v_f_383_, lean_object* v_x_384_, lean_object* v_x_385_, lean_object* v___y_386_, lean_object* v___y_387_, lean_object* v___y_388_, lean_object* v___y_389_, lean_object* v___y_390_, lean_object* v___y_391_, lean_object* v___y_392_, lean_object* v___y_393_){
_start:
{
lean_object* v_res_394_; 
v_res_394_ = lp_JunkValues_Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13_spec__17_spec__18___redArg(v_f_383_, v_x_384_, v_x_385_, v___y_386_, v___y_387_, v___y_388_, v___y_389_, v___y_390_, v___y_391_, v___y_392_);
lean_dec(v___y_392_);
lean_dec_ref(v___y_391_);
lean_dec(v___y_390_);
lean_dec_ref(v___y_389_);
lean_dec(v___y_388_);
lean_dec_ref(v___y_387_);
return v_res_394_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13___redArg(lean_object* v_map_395_, lean_object* v_f_396_, lean_object* v___y_397_, lean_object* v___y_398_, lean_object* v___y_399_, lean_object* v___y_400_, lean_object* v___y_401_, lean_object* v___y_402_, lean_object* v___y_403_){
_start:
{
lean_object* v___f_405_; lean_object* v___x_406_; lean_object* v___x_407_; 
v___f_405_ = lean_alloc_closure((void*)(lp_JunkValues_Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13___redArg___lam__0___boxed), 12, 1);
lean_closure_set(v___f_405_, 0, v_f_396_);
v___x_406_ = lean_box(0);
v___x_407_ = lp_JunkValues_Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13_spec__17_spec__18___redArg(v___f_405_, v_map_395_, v___x_406_, v___y_397_, v___y_398_, v___y_399_, v___y_400_, v___y_401_, v___y_402_, v___y_403_);
return v___x_407_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13___redArg___boxed(lean_object* v_map_408_, lean_object* v_f_409_, lean_object* v___y_410_, lean_object* v___y_411_, lean_object* v___y_412_, lean_object* v___y_413_, lean_object* v___y_414_, lean_object* v___y_415_, lean_object* v___y_416_, lean_object* v___y_417_){
_start:
{
lean_object* v_res_418_; 
v_res_418_ = lp_JunkValues_Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13___redArg(v_map_408_, v_f_409_, v___y_410_, v___y_411_, v___y_412_, v___y_413_, v___y_414_, v___y_415_, v___y_416_);
lean_dec(v___y_416_);
lean_dec_ref(v___y_415_);
lean_dec(v___y_414_);
lean_dec_ref(v___y_413_);
lean_dec(v___y_412_);
lean_dec_ref(v___y_411_);
return v_res_418_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8___redArg(lean_object* v_s_419_, lean_object* v_f_420_, lean_object* v___y_421_, lean_object* v___y_422_, lean_object* v___y_423_, lean_object* v___y_424_, lean_object* v___y_425_, lean_object* v___y_426_, lean_object* v___y_427_){
_start:
{
lean_object* v_map_u2081_429_; lean_object* v_map_u2082_430_; lean_object* v_buckets_431_; lean_object* v___x_432_; lean_object* v___x_433_; uint8_t v___x_434_; 
v_map_u2081_429_ = lean_ctor_get(v_s_419_, 0);
lean_inc_ref(v_map_u2081_429_);
v_map_u2082_430_ = lean_ctor_get(v_s_419_, 1);
lean_inc_ref(v_map_u2082_430_);
lean_dec_ref(v_s_419_);
v_buckets_431_ = lean_ctor_get(v_map_u2081_429_, 1);
lean_inc_ref(v_buckets_431_);
lean_dec_ref(v_map_u2081_429_);
v___x_432_ = lean_unsigned_to_nat(0u);
v___x_433_ = lean_array_get_size(v_buckets_431_);
v___x_434_ = lean_nat_dec_lt(v___x_432_, v___x_433_);
if (v___x_434_ == 0)
{
lean_object* v___x_435_; 
lean_dec_ref(v_buckets_431_);
v___x_435_ = lp_JunkValues_Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13___redArg(v_map_u2082_430_, v_f_420_, v___y_421_, v___y_422_, v___y_423_, v___y_424_, v___y_425_, v___y_426_, v___y_427_);
return v___x_435_;
}
else
{
lean_object* v___x_436_; uint8_t v___x_437_; 
v___x_436_ = lean_box(0);
v___x_437_ = lean_nat_dec_le(v___x_433_, v___x_433_);
if (v___x_437_ == 0)
{
if (v___x_434_ == 0)
{
lean_object* v___x_438_; 
lean_dec_ref(v_buckets_431_);
v___x_438_ = lp_JunkValues_Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13___redArg(v_map_u2082_430_, v_f_420_, v___y_421_, v___y_422_, v___y_423_, v___y_424_, v___y_425_, v___y_426_, v___y_427_);
return v___x_438_;
}
else
{
size_t v___x_439_; size_t v___x_440_; lean_object* v___x_441_; 
v___x_439_ = ((size_t)0ULL);
v___x_440_ = lean_usize_of_nat(v___x_433_);
lean_inc_ref(v_f_420_);
v___x_441_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__14___redArg(v_f_420_, v_buckets_431_, v___x_439_, v___x_440_, v___x_436_, v___y_421_, v___y_422_, v___y_423_, v___y_424_, v___y_425_, v___y_426_, v___y_427_);
lean_dec_ref(v_buckets_431_);
if (lean_obj_tag(v___x_441_) == 0)
{
lean_object* v_a_442_; 
v_a_442_ = lean_ctor_get(v___x_441_, 0);
lean_inc(v_a_442_);
if (lean_obj_tag(v_a_442_) == 0)
{
lean_dec_ref_known(v_a_442_, 1);
lean_dec_ref(v_map_u2082_430_);
lean_dec_ref(v_f_420_);
return v___x_441_;
}
else
{
lean_object* v_a_443_; lean_object* v_snd_444_; lean_object* v___x_445_; 
lean_dec_ref_known(v___x_441_, 1);
v_a_443_ = lean_ctor_get(v_a_442_, 0);
lean_inc(v_a_443_);
lean_dec_ref_known(v_a_442_, 1);
v_snd_444_ = lean_ctor_get(v_a_443_, 1);
lean_inc(v_snd_444_);
lean_dec(v_a_443_);
v___x_445_ = lp_JunkValues_Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13___redArg(v_map_u2082_430_, v_f_420_, v_snd_444_, v___y_422_, v___y_423_, v___y_424_, v___y_425_, v___y_426_, v___y_427_);
return v___x_445_;
}
}
else
{
lean_dec_ref(v_map_u2082_430_);
lean_dec_ref(v_f_420_);
return v___x_441_;
}
}
}
else
{
size_t v___x_446_; size_t v___x_447_; lean_object* v___x_448_; 
v___x_446_ = ((size_t)0ULL);
v___x_447_ = lean_usize_of_nat(v___x_433_);
lean_inc_ref(v_f_420_);
v___x_448_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__14___redArg(v_f_420_, v_buckets_431_, v___x_446_, v___x_447_, v___x_436_, v___y_421_, v___y_422_, v___y_423_, v___y_424_, v___y_425_, v___y_426_, v___y_427_);
lean_dec_ref(v_buckets_431_);
if (lean_obj_tag(v___x_448_) == 0)
{
lean_object* v_a_449_; 
v_a_449_ = lean_ctor_get(v___x_448_, 0);
lean_inc(v_a_449_);
if (lean_obj_tag(v_a_449_) == 0)
{
lean_dec_ref_known(v_a_449_, 1);
lean_dec_ref(v_map_u2082_430_);
lean_dec_ref(v_f_420_);
return v___x_448_;
}
else
{
lean_object* v_a_450_; lean_object* v_snd_451_; lean_object* v___x_452_; 
lean_dec_ref_known(v___x_448_, 1);
v_a_450_ = lean_ctor_get(v_a_449_, 0);
lean_inc(v_a_450_);
lean_dec_ref_known(v_a_449_, 1);
v_snd_451_ = lean_ctor_get(v_a_450_, 1);
lean_inc(v_snd_451_);
lean_dec(v_a_450_);
v___x_452_ = lp_JunkValues_Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13___redArg(v_map_u2082_430_, v_f_420_, v_snd_451_, v___y_422_, v___y_423_, v___y_424_, v___y_425_, v___y_426_, v___y_427_);
return v___x_452_;
}
}
else
{
lean_dec_ref(v_map_u2082_430_);
lean_dec_ref(v_f_420_);
return v___x_448_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8___redArg___boxed(lean_object* v_s_453_, lean_object* v_f_454_, lean_object* v___y_455_, lean_object* v___y_456_, lean_object* v___y_457_, lean_object* v___y_458_, lean_object* v___y_459_, lean_object* v___y_460_, lean_object* v___y_461_, lean_object* v___y_462_){
_start:
{
lean_object* v_res_463_; 
v_res_463_ = lp_JunkValues_Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8___redArg(v_s_453_, v_f_454_, v___y_455_, v___y_456_, v___y_457_, v___y_458_, v___y_459_, v___y_460_, v___y_461_);
lean_dec(v___y_461_);
lean_dec_ref(v___y_460_);
lean_dec(v___y_459_);
lean_dec_ref(v___y_458_);
lean_dec(v___y_457_);
lean_dec_ref(v___y_456_);
return v_res_463_;
}
}
LEAN_EXPORT uint8_t lp_JunkValues___private_Init_Data_Array_QSort_Basic_0__Array_qsort_sort___at___00JunkValues_elabJunkCheck_spec__7___redArg___lam__0(uint8_t v___x_464_, lean_object* v_x1_465_, lean_object* v_x2_466_){
_start:
{
lean_object* v___x_467_; lean_object* v___x_468_; uint8_t v___x_469_; 
v___x_467_ = l_Lean_Name_toString(v_x1_465_, v___x_464_);
v___x_468_ = l_Lean_Name_toString(v_x2_466_, v___x_464_);
v___x_469_ = lean_string_dec_lt(v___x_467_, v___x_468_);
lean_dec_ref(v___x_468_);
lean_dec_ref(v___x_467_);
return v___x_469_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_QSort_Basic_0__Array_qsort_sort___at___00JunkValues_elabJunkCheck_spec__7___redArg___lam__0___boxed(lean_object* v___x_470_, lean_object* v_x1_471_, lean_object* v_x2_472_){
_start:
{
uint8_t v___x_20716__boxed_473_; uint8_t v_res_474_; lean_object* v_r_475_; 
v___x_20716__boxed_473_ = lean_unbox(v___x_470_);
v_res_474_ = lp_JunkValues___private_Init_Data_Array_QSort_Basic_0__Array_qsort_sort___at___00JunkValues_elabJunkCheck_spec__7___redArg___lam__0(v___x_20716__boxed_473_, v_x1_471_, v_x2_472_);
v_r_475_ = lean_box(v_res_474_);
return v_r_475_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_QSort_Basic_0__Array_qpartition_loop___at___00__private_Init_Data_Array_QSort_Basic_0__Array_qsort_sort___at___00JunkValues_elabJunkCheck_spec__7_spec__10___redArg(lean_object* v_hi_476_, lean_object* v_pivot_477_, lean_object* v_as_478_, lean_object* v_i_479_, lean_object* v_k_480_){
_start:
{
uint8_t v___x_481_; 
v___x_481_ = lean_nat_dec_lt(v_k_480_, v_hi_476_);
if (v___x_481_ == 0)
{
lean_object* v___x_482_; lean_object* v___x_483_; 
lean_dec(v_k_480_);
lean_dec(v_pivot_477_);
v___x_482_ = lean_array_fswap(v_as_478_, v_i_479_, v_hi_476_);
v___x_483_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_483_, 0, v_i_479_);
lean_ctor_set(v___x_483_, 1, v___x_482_);
return v___x_483_;
}
else
{
lean_object* v___x_484_; lean_object* v___x_485_; lean_object* v___x_486_; uint8_t v___x_487_; 
v___x_484_ = lean_array_fget_borrowed(v_as_478_, v_k_480_);
lean_inc(v___x_484_);
v___x_485_ = l_Lean_Name_toString(v___x_484_, v___x_481_);
lean_inc(v_pivot_477_);
v___x_486_ = l_Lean_Name_toString(v_pivot_477_, v___x_481_);
v___x_487_ = lean_string_dec_lt(v___x_485_, v___x_486_);
lean_dec_ref(v___x_486_);
lean_dec_ref(v___x_485_);
if (v___x_487_ == 0)
{
lean_object* v___x_488_; lean_object* v___x_489_; 
v___x_488_ = lean_unsigned_to_nat(1u);
v___x_489_ = lean_nat_add(v_k_480_, v___x_488_);
lean_dec(v_k_480_);
v_k_480_ = v___x_489_;
goto _start;
}
else
{
lean_object* v___x_491_; lean_object* v___x_492_; lean_object* v___x_493_; lean_object* v___x_494_; 
v___x_491_ = lean_array_fswap(v_as_478_, v_i_479_, v_k_480_);
v___x_492_ = lean_unsigned_to_nat(1u);
v___x_493_ = lean_nat_add(v_i_479_, v___x_492_);
lean_dec(v_i_479_);
v___x_494_ = lean_nat_add(v_k_480_, v___x_492_);
lean_dec(v_k_480_);
v_as_478_ = v___x_491_;
v_i_479_ = v___x_493_;
v_k_480_ = v___x_494_;
goto _start;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_QSort_Basic_0__Array_qpartition_loop___at___00__private_Init_Data_Array_QSort_Basic_0__Array_qsort_sort___at___00JunkValues_elabJunkCheck_spec__7_spec__10___redArg___boxed(lean_object* v_hi_496_, lean_object* v_pivot_497_, lean_object* v_as_498_, lean_object* v_i_499_, lean_object* v_k_500_){
_start:
{
lean_object* v_res_501_; 
v_res_501_ = lp_JunkValues___private_Init_Data_Array_QSort_Basic_0__Array_qpartition_loop___at___00__private_Init_Data_Array_QSort_Basic_0__Array_qsort_sort___at___00JunkValues_elabJunkCheck_spec__7_spec__10___redArg(v_hi_496_, v_pivot_497_, v_as_498_, v_i_499_, v_k_500_);
lean_dec(v_hi_496_);
return v_res_501_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_QSort_Basic_0__Array_qsort_sort___at___00JunkValues_elabJunkCheck_spec__7___redArg(lean_object* v_n_502_, lean_object* v_as_503_, lean_object* v_lo_504_, lean_object* v_hi_505_){
_start:
{
lean_object* v___y_507_; uint8_t v___x_517_; 
v___x_517_ = lean_nat_dec_lt(v_lo_504_, v_hi_505_);
if (v___x_517_ == 0)
{
lean_dec(v_lo_504_);
return v_as_503_;
}
else
{
lean_object* v___x_518_; lean_object* v___x_519_; lean_object* v_mid_520_; lean_object* v___y_522_; lean_object* v___y_528_; lean_object* v___x_533_; lean_object* v___x_534_; uint8_t v___x_535_; 
v___x_518_ = lean_nat_add(v_lo_504_, v_hi_505_);
v___x_519_ = lean_unsigned_to_nat(1u);
v_mid_520_ = lean_nat_shiftr(v___x_518_, v___x_519_);
lean_dec(v___x_518_);
v___x_533_ = lean_array_fget_borrowed(v_as_503_, v_mid_520_);
v___x_534_ = lean_array_fget_borrowed(v_as_503_, v_lo_504_);
lean_inc(v___x_534_);
lean_inc(v___x_533_);
v___x_535_ = lp_JunkValues___private_Init_Data_Array_QSort_Basic_0__Array_qsort_sort___at___00JunkValues_elabJunkCheck_spec__7___redArg___lam__0(v___x_517_, v___x_533_, v___x_534_);
if (v___x_535_ == 0)
{
v___y_528_ = v_as_503_;
goto v___jp_527_;
}
else
{
lean_object* v___x_536_; 
v___x_536_ = lean_array_fswap(v_as_503_, v_lo_504_, v_mid_520_);
v___y_528_ = v___x_536_;
goto v___jp_527_;
}
v___jp_521_:
{
lean_object* v___x_523_; lean_object* v___x_524_; uint8_t v___x_525_; 
v___x_523_ = lean_array_fget_borrowed(v___y_522_, v_mid_520_);
v___x_524_ = lean_array_fget_borrowed(v___y_522_, v_hi_505_);
lean_inc(v___x_524_);
lean_inc(v___x_523_);
v___x_525_ = lp_JunkValues___private_Init_Data_Array_QSort_Basic_0__Array_qsort_sort___at___00JunkValues_elabJunkCheck_spec__7___redArg___lam__0(v___x_517_, v___x_523_, v___x_524_);
if (v___x_525_ == 0)
{
lean_dec(v_mid_520_);
v___y_507_ = v___y_522_;
goto v___jp_506_;
}
else
{
lean_object* v___x_526_; 
v___x_526_ = lean_array_fswap(v___y_522_, v_mid_520_, v_hi_505_);
lean_dec(v_mid_520_);
v___y_507_ = v___x_526_;
goto v___jp_506_;
}
}
v___jp_527_:
{
lean_object* v___x_529_; lean_object* v___x_530_; uint8_t v___x_531_; 
v___x_529_ = lean_array_fget_borrowed(v___y_528_, v_hi_505_);
v___x_530_ = lean_array_fget_borrowed(v___y_528_, v_lo_504_);
lean_inc(v___x_530_);
lean_inc(v___x_529_);
v___x_531_ = lp_JunkValues___private_Init_Data_Array_QSort_Basic_0__Array_qsort_sort___at___00JunkValues_elabJunkCheck_spec__7___redArg___lam__0(v___x_517_, v___x_529_, v___x_530_);
if (v___x_531_ == 0)
{
v___y_522_ = v___y_528_;
goto v___jp_521_;
}
else
{
lean_object* v___x_532_; 
v___x_532_ = lean_array_fswap(v___y_528_, v_lo_504_, v_hi_505_);
v___y_522_ = v___x_532_;
goto v___jp_521_;
}
}
}
v___jp_506_:
{
lean_object* v_pivot_508_; lean_object* v___x_509_; lean_object* v_fst_510_; lean_object* v_snd_511_; uint8_t v___x_512_; 
v_pivot_508_ = lean_array_fget(v___y_507_, v_hi_505_);
lean_inc_n(v_lo_504_, 2);
v___x_509_ = lp_JunkValues___private_Init_Data_Array_QSort_Basic_0__Array_qpartition_loop___at___00__private_Init_Data_Array_QSort_Basic_0__Array_qsort_sort___at___00JunkValues_elabJunkCheck_spec__7_spec__10___redArg(v_hi_505_, v_pivot_508_, v___y_507_, v_lo_504_, v_lo_504_);
v_fst_510_ = lean_ctor_get(v___x_509_, 0);
lean_inc(v_fst_510_);
v_snd_511_ = lean_ctor_get(v___x_509_, 1);
lean_inc(v_snd_511_);
lean_dec_ref(v___x_509_);
v___x_512_ = lean_nat_dec_le(v_hi_505_, v_fst_510_);
if (v___x_512_ == 0)
{
lean_object* v___x_513_; lean_object* v___x_514_; lean_object* v___x_515_; 
v___x_513_ = lp_JunkValues___private_Init_Data_Array_QSort_Basic_0__Array_qsort_sort___at___00JunkValues_elabJunkCheck_spec__7___redArg(v_n_502_, v_snd_511_, v_lo_504_, v_fst_510_);
v___x_514_ = lean_unsigned_to_nat(1u);
v___x_515_ = lean_nat_add(v_fst_510_, v___x_514_);
lean_dec(v_fst_510_);
v_as_503_ = v___x_513_;
v_lo_504_ = v___x_515_;
goto _start;
}
else
{
lean_dec(v_fst_510_);
lean_dec(v_lo_504_);
return v_snd_511_;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_QSort_Basic_0__Array_qsort_sort___at___00JunkValues_elabJunkCheck_spec__7___redArg___boxed(lean_object* v_n_537_, lean_object* v_as_538_, lean_object* v_lo_539_, lean_object* v_hi_540_){
_start:
{
lean_object* v_res_541_; 
v_res_541_ = lp_JunkValues___private_Init_Data_Array_QSort_Basic_0__Array_qsort_sort___at___00JunkValues_elabJunkCheck_spec__7___redArg(v_n_537_, v_as_538_, v_lo_539_, v_hi_540_);
lean_dec(v_hi_540_);
lean_dec(v_n_537_);
return v_res_541_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_addMessageContextFull___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__7(lean_object* v_msgData_542_, lean_object* v___y_543_, lean_object* v___y_544_, lean_object* v___y_545_, lean_object* v___y_546_){
_start:
{
lean_object* v___x_548_; lean_object* v_env_549_; lean_object* v___x_550_; lean_object* v_mctx_551_; lean_object* v_lctx_552_; lean_object* v_options_553_; lean_object* v___x_554_; lean_object* v___x_555_; lean_object* v___x_556_; 
v___x_548_ = lean_st_ref_get(v___y_546_);
v_env_549_ = lean_ctor_get(v___x_548_, 0);
lean_inc_ref(v_env_549_);
lean_dec(v___x_548_);
v___x_550_ = lean_st_ref_get(v___y_544_);
v_mctx_551_ = lean_ctor_get(v___x_550_, 0);
lean_inc_ref(v_mctx_551_);
lean_dec(v___x_550_);
v_lctx_552_ = lean_ctor_get(v___y_543_, 2);
v_options_553_ = lean_ctor_get(v___y_545_, 2);
lean_inc_ref(v_options_553_);
lean_inc_ref(v_lctx_552_);
v___x_554_ = lean_alloc_ctor(0, 4, 0);
lean_ctor_set(v___x_554_, 0, v_env_549_);
lean_ctor_set(v___x_554_, 1, v_mctx_551_);
lean_ctor_set(v___x_554_, 2, v_lctx_552_);
lean_ctor_set(v___x_554_, 3, v_options_553_);
v___x_555_ = lean_alloc_ctor(3, 2, 0);
lean_ctor_set(v___x_555_, 0, v___x_554_);
lean_ctor_set(v___x_555_, 1, v_msgData_542_);
v___x_556_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_556_, 0, v___x_555_);
return v___x_556_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_addMessageContextFull___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__7___boxed(lean_object* v_msgData_557_, lean_object* v___y_558_, lean_object* v___y_559_, lean_object* v___y_560_, lean_object* v___y_561_, lean_object* v___y_562_){
_start:
{
lean_object* v_res_563_; 
v_res_563_ = lp_JunkValues_Lean_addMessageContextFull___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__7(v_msgData_557_, v___y_558_, v___y_559_, v___y_560_, v___y_561_);
lean_dec(v___y_561_);
lean_dec_ref(v___y_560_);
lean_dec(v___y_559_);
lean_dec_ref(v___y_558_);
return v_res_563_;
}
}
static lean_object* _init_lp_JunkValues_List_foldl___at___00Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8_spec__11___closed__0(void){
_start:
{
lean_object* v___x_564_; lean_object* v___x_565_; 
v___x_564_ = lean_box(1);
v___x_565_ = l_Lean_MessageData_ofFormat(v___x_564_);
return v___x_565_;
}
}
static lean_object* _init_lp_JunkValues_List_foldl___at___00Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8_spec__11___closed__3(void){
_start:
{
lean_object* v___x_569_; lean_object* v___x_570_; 
v___x_569_ = ((lean_object*)(lp_JunkValues_List_foldl___at___00Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8_spec__11___closed__2));
v___x_570_ = l_Lean_MessageData_ofFormat(v___x_569_);
return v___x_570_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_List_foldl___at___00Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8_spec__11(lean_object* v_x_571_, lean_object* v_x_572_){
_start:
{
if (lean_obj_tag(v_x_572_) == 0)
{
return v_x_571_;
}
else
{
lean_object* v_head_573_; lean_object* v_tail_574_; lean_object* v___x_576_; uint8_t v_isShared_577_; uint8_t v_isSharedCheck_596_; 
v_head_573_ = lean_ctor_get(v_x_572_, 0);
v_tail_574_ = lean_ctor_get(v_x_572_, 1);
v_isSharedCheck_596_ = !lean_is_exclusive(v_x_572_);
if (v_isSharedCheck_596_ == 0)
{
v___x_576_ = v_x_572_;
v_isShared_577_ = v_isSharedCheck_596_;
goto v_resetjp_575_;
}
else
{
lean_inc(v_tail_574_);
lean_inc(v_head_573_);
lean_dec(v_x_572_);
v___x_576_ = lean_box(0);
v_isShared_577_ = v_isSharedCheck_596_;
goto v_resetjp_575_;
}
v_resetjp_575_:
{
lean_object* v_before_578_; lean_object* v___x_580_; uint8_t v_isShared_581_; uint8_t v_isSharedCheck_594_; 
v_before_578_ = lean_ctor_get(v_head_573_, 0);
v_isSharedCheck_594_ = !lean_is_exclusive(v_head_573_);
if (v_isSharedCheck_594_ == 0)
{
lean_object* v_unused_595_; 
v_unused_595_ = lean_ctor_get(v_head_573_, 1);
lean_dec(v_unused_595_);
v___x_580_ = v_head_573_;
v_isShared_581_ = v_isSharedCheck_594_;
goto v_resetjp_579_;
}
else
{
lean_inc(v_before_578_);
lean_dec(v_head_573_);
v___x_580_ = lean_box(0);
v_isShared_581_ = v_isSharedCheck_594_;
goto v_resetjp_579_;
}
v_resetjp_579_:
{
lean_object* v___x_582_; lean_object* v___x_584_; 
v___x_582_ = lean_obj_once(&lp_JunkValues_List_foldl___at___00Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8_spec__11___closed__0, &lp_JunkValues_List_foldl___at___00Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8_spec__11___closed__0_once, _init_lp_JunkValues_List_foldl___at___00Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8_spec__11___closed__0);
if (v_isShared_581_ == 0)
{
lean_ctor_set_tag(v___x_580_, 7);
lean_ctor_set(v___x_580_, 1, v___x_582_);
lean_ctor_set(v___x_580_, 0, v_x_571_);
v___x_584_ = v___x_580_;
goto v_reusejp_583_;
}
else
{
lean_object* v_reuseFailAlloc_593_; 
v_reuseFailAlloc_593_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v_reuseFailAlloc_593_, 0, v_x_571_);
lean_ctor_set(v_reuseFailAlloc_593_, 1, v___x_582_);
v___x_584_ = v_reuseFailAlloc_593_;
goto v_reusejp_583_;
}
v_reusejp_583_:
{
lean_object* v___x_585_; lean_object* v___x_587_; 
v___x_585_ = lean_obj_once(&lp_JunkValues_List_foldl___at___00Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8_spec__11___closed__3, &lp_JunkValues_List_foldl___at___00Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8_spec__11___closed__3_once, _init_lp_JunkValues_List_foldl___at___00Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8_spec__11___closed__3);
if (v_isShared_577_ == 0)
{
lean_ctor_set_tag(v___x_576_, 7);
lean_ctor_set(v___x_576_, 1, v___x_585_);
lean_ctor_set(v___x_576_, 0, v___x_584_);
v___x_587_ = v___x_576_;
goto v_reusejp_586_;
}
else
{
lean_object* v_reuseFailAlloc_592_; 
v_reuseFailAlloc_592_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v_reuseFailAlloc_592_, 0, v___x_584_);
lean_ctor_set(v_reuseFailAlloc_592_, 1, v___x_585_);
v___x_587_ = v_reuseFailAlloc_592_;
goto v_reusejp_586_;
}
v_reusejp_586_:
{
lean_object* v___x_588_; lean_object* v___x_589_; lean_object* v___x_590_; 
v___x_588_ = l_Lean_MessageData_ofSyntax(v_before_578_);
v___x_589_ = l_Lean_indentD(v___x_588_);
v___x_590_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_590_, 0, v___x_587_);
lean_ctor_set(v___x_590_, 1, v___x_589_);
v_x_571_ = v___x_590_;
v_x_572_ = v_tail_574_;
goto _start;
}
}
}
}
}
}
}
LEAN_EXPORT uint8_t lp_JunkValues_Lean_Option_get___at___00Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8_spec__10(lean_object* v_opts_597_, lean_object* v_opt_598_){
_start:
{
lean_object* v_name_599_; lean_object* v_defValue_600_; lean_object* v_map_601_; lean_object* v___x_602_; 
v_name_599_ = lean_ctor_get(v_opt_598_, 0);
v_defValue_600_ = lean_ctor_get(v_opt_598_, 1);
v_map_601_ = lean_ctor_get(v_opts_597_, 0);
v___x_602_ = l_Std_DTreeMap_Internal_Impl_Const_get_x3f___at___00Lean_NameMap_find_x3f_spec__0___redArg(v_map_601_, v_name_599_);
if (lean_obj_tag(v___x_602_) == 0)
{
uint8_t v___x_603_; 
v___x_603_ = lean_unbox(v_defValue_600_);
return v___x_603_;
}
else
{
lean_object* v_val_604_; 
v_val_604_ = lean_ctor_get(v___x_602_, 0);
lean_inc(v_val_604_);
lean_dec_ref_known(v___x_602_, 1);
if (lean_obj_tag(v_val_604_) == 1)
{
uint8_t v_v_605_; 
v_v_605_ = lean_ctor_get_uint8(v_val_604_, 0);
lean_dec_ref_known(v_val_604_, 0);
return v_v_605_;
}
else
{
uint8_t v___x_606_; 
lean_dec(v_val_604_);
v___x_606_ = lean_unbox(v_defValue_600_);
return v___x_606_;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Option_get___at___00Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8_spec__10___boxed(lean_object* v_opts_607_, lean_object* v_opt_608_){
_start:
{
uint8_t v_res_609_; lean_object* v_r_610_; 
v_res_609_ = lp_JunkValues_Lean_Option_get___at___00Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8_spec__10(v_opts_607_, v_opt_608_);
lean_dec_ref(v_opt_608_);
lean_dec_ref(v_opts_607_);
v_r_610_ = lean_box(v_res_609_);
return v_r_610_;
}
}
static lean_object* _init_lp_JunkValues_Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8___redArg___closed__2(void){
_start:
{
lean_object* v___x_614_; lean_object* v___x_615_; 
v___x_614_ = ((lean_object*)(lp_JunkValues_Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8___redArg___closed__1));
v___x_615_ = l_Lean_MessageData_ofFormat(v___x_614_);
return v___x_615_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8___redArg(lean_object* v_msgData_616_, lean_object* v_macroStack_617_, lean_object* v___y_618_){
_start:
{
lean_object* v_options_620_; lean_object* v___x_621_; uint8_t v___x_622_; 
v_options_620_ = lean_ctor_get(v___y_618_, 2);
v___x_621_ = l_Lean_Elab_pp_macroStack;
v___x_622_ = lp_JunkValues_Lean_Option_get___at___00Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8_spec__10(v_options_620_, v___x_621_);
if (v___x_622_ == 0)
{
lean_object* v___x_623_; 
lean_dec(v_macroStack_617_);
v___x_623_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_623_, 0, v_msgData_616_);
return v___x_623_;
}
else
{
if (lean_obj_tag(v_macroStack_617_) == 0)
{
lean_object* v___x_624_; 
v___x_624_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_624_, 0, v_msgData_616_);
return v___x_624_;
}
else
{
lean_object* v_head_625_; lean_object* v_after_626_; lean_object* v___x_628_; uint8_t v_isShared_629_; uint8_t v_isSharedCheck_641_; 
v_head_625_ = lean_ctor_get(v_macroStack_617_, 0);
lean_inc(v_head_625_);
v_after_626_ = lean_ctor_get(v_head_625_, 1);
v_isSharedCheck_641_ = !lean_is_exclusive(v_head_625_);
if (v_isSharedCheck_641_ == 0)
{
lean_object* v_unused_642_; 
v_unused_642_ = lean_ctor_get(v_head_625_, 0);
lean_dec(v_unused_642_);
v___x_628_ = v_head_625_;
v_isShared_629_ = v_isSharedCheck_641_;
goto v_resetjp_627_;
}
else
{
lean_inc(v_after_626_);
lean_dec(v_head_625_);
v___x_628_ = lean_box(0);
v_isShared_629_ = v_isSharedCheck_641_;
goto v_resetjp_627_;
}
v_resetjp_627_:
{
lean_object* v___x_630_; lean_object* v___x_632_; 
v___x_630_ = lean_obj_once(&lp_JunkValues_List_foldl___at___00Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8_spec__11___closed__0, &lp_JunkValues_List_foldl___at___00Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8_spec__11___closed__0_once, _init_lp_JunkValues_List_foldl___at___00Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8_spec__11___closed__0);
if (v_isShared_629_ == 0)
{
lean_ctor_set_tag(v___x_628_, 7);
lean_ctor_set(v___x_628_, 1, v___x_630_);
lean_ctor_set(v___x_628_, 0, v_msgData_616_);
v___x_632_ = v___x_628_;
goto v_reusejp_631_;
}
else
{
lean_object* v_reuseFailAlloc_640_; 
v_reuseFailAlloc_640_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v_reuseFailAlloc_640_, 0, v_msgData_616_);
lean_ctor_set(v_reuseFailAlloc_640_, 1, v___x_630_);
v___x_632_ = v_reuseFailAlloc_640_;
goto v_reusejp_631_;
}
v_reusejp_631_:
{
lean_object* v___x_633_; lean_object* v___x_634_; lean_object* v___x_635_; lean_object* v___x_636_; lean_object* v_msgData_637_; lean_object* v___x_638_; lean_object* v___x_639_; 
v___x_633_ = lean_obj_once(&lp_JunkValues_Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8___redArg___closed__2, &lp_JunkValues_Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8___redArg___closed__2_once, _init_lp_JunkValues_Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8___redArg___closed__2);
v___x_634_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_634_, 0, v___x_632_);
lean_ctor_set(v___x_634_, 1, v___x_633_);
v___x_635_ = l_Lean_MessageData_ofSyntax(v_after_626_);
v___x_636_ = l_Lean_indentD(v___x_635_);
v_msgData_637_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v_msgData_637_, 0, v___x_634_);
lean_ctor_set(v_msgData_637_, 1, v___x_636_);
v___x_638_ = lp_JunkValues_List_foldl___at___00Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8_spec__11(v_msgData_637_, v_macroStack_617_);
v___x_639_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_639_, 0, v___x_638_);
return v___x_639_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8___redArg___boxed(lean_object* v_msgData_643_, lean_object* v_macroStack_644_, lean_object* v___y_645_, lean_object* v___y_646_){
_start:
{
lean_object* v_res_647_; 
v_res_647_ = lp_JunkValues_Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8___redArg(v_msgData_643_, v_macroStack_644_, v___y_645_);
lean_dec_ref(v___y_645_);
return v_res_647_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6___redArg(lean_object* v_msg_648_, lean_object* v___y_649_, lean_object* v___y_650_, lean_object* v___y_651_, lean_object* v___y_652_, lean_object* v___y_653_, lean_object* v___y_654_){
_start:
{
lean_object* v_ref_656_; lean_object* v___x_657_; lean_object* v_a_658_; lean_object* v_macroStack_659_; lean_object* v___x_660_; lean_object* v___x_661_; lean_object* v_a_662_; lean_object* v___x_664_; uint8_t v_isShared_665_; uint8_t v_isSharedCheck_670_; 
v_ref_656_ = lean_ctor_get(v___y_653_, 5);
v___x_657_ = lp_JunkValues_Lean_addMessageContextFull___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__7(v_msg_648_, v___y_651_, v___y_652_, v___y_653_, v___y_654_);
v_a_658_ = lean_ctor_get(v___x_657_, 0);
lean_inc(v_a_658_);
lean_dec_ref(v___x_657_);
v_macroStack_659_ = lean_ctor_get(v___y_649_, 1);
v___x_660_ = l_Lean_Elab_getBetterRef(v_ref_656_, v_macroStack_659_);
lean_inc(v_macroStack_659_);
v___x_661_ = lp_JunkValues_Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8___redArg(v_a_658_, v_macroStack_659_, v___y_653_);
v_a_662_ = lean_ctor_get(v___x_661_, 0);
v_isSharedCheck_670_ = !lean_is_exclusive(v___x_661_);
if (v_isSharedCheck_670_ == 0)
{
v___x_664_ = v___x_661_;
v_isShared_665_ = v_isSharedCheck_670_;
goto v_resetjp_663_;
}
else
{
lean_inc(v_a_662_);
lean_dec(v___x_661_);
v___x_664_ = lean_box(0);
v_isShared_665_ = v_isSharedCheck_670_;
goto v_resetjp_663_;
}
v_resetjp_663_:
{
lean_object* v___x_666_; lean_object* v___x_668_; 
v___x_666_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_666_, 0, v___x_660_);
lean_ctor_set(v___x_666_, 1, v_a_662_);
if (v_isShared_665_ == 0)
{
lean_ctor_set_tag(v___x_664_, 1);
lean_ctor_set(v___x_664_, 0, v___x_666_);
v___x_668_ = v___x_664_;
goto v_reusejp_667_;
}
else
{
lean_object* v_reuseFailAlloc_669_; 
v_reuseFailAlloc_669_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_669_, 0, v___x_666_);
v___x_668_ = v_reuseFailAlloc_669_;
goto v_reusejp_667_;
}
v_reusejp_667_:
{
return v___x_668_;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6___redArg___boxed(lean_object* v_msg_671_, lean_object* v___y_672_, lean_object* v___y_673_, lean_object* v___y_674_, lean_object* v___y_675_, lean_object* v___y_676_, lean_object* v___y_677_, lean_object* v___y_678_){
_start:
{
lean_object* v_res_679_; 
v_res_679_ = lp_JunkValues_Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6___redArg(v_msg_671_, v___y_672_, v___y_673_, v___y_674_, v___y_675_, v___y_676_, v___y_677_);
lean_dec(v___y_677_);
lean_dec_ref(v___y_676_);
lean_dec(v___y_675_);
lean_dec_ref(v___y_674_);
lean_dec(v___y_673_);
lean_dec_ref(v___y_672_);
return v_res_679_;
}
}
LEAN_EXPORT uint8_t lp_JunkValues_Lean_logAt___at___00Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1_spec__2___redArg___lam__0(uint8_t v___y_688_, uint8_t v_suppressElabErrors_689_, lean_object* v_x_690_){
_start:
{
if (lean_obj_tag(v_x_690_) == 1)
{
lean_object* v_pre_691_; 
v_pre_691_ = lean_ctor_get(v_x_690_, 0);
switch(lean_obj_tag(v_pre_691_))
{
case 1:
{
lean_object* v_pre_692_; 
v_pre_692_ = lean_ctor_get(v_pre_691_, 0);
switch(lean_obj_tag(v_pre_692_))
{
case 0:
{
lean_object* v_str_693_; lean_object* v_str_694_; lean_object* v___x_695_; uint8_t v___x_696_; 
v_str_693_ = lean_ctor_get(v_x_690_, 1);
v_str_694_ = lean_ctor_get(v_pre_691_, 1);
v___x_695_ = ((lean_object*)(lp_JunkValues_Lean_logAt___at___00Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1_spec__2___redArg___lam__0___closed__0));
v___x_696_ = lean_string_dec_eq(v_str_694_, v___x_695_);
if (v___x_696_ == 0)
{
lean_object* v___x_697_; uint8_t v___x_698_; 
v___x_697_ = ((lean_object*)(lp_JunkValues_Lean_logAt___at___00Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1_spec__2___redArg___lam__0___closed__1));
v___x_698_ = lean_string_dec_eq(v_str_694_, v___x_697_);
if (v___x_698_ == 0)
{
return v___y_688_;
}
else
{
lean_object* v___x_699_; uint8_t v___x_700_; 
v___x_699_ = ((lean_object*)(lp_JunkValues_Lean_logAt___at___00Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1_spec__2___redArg___lam__0___closed__2));
v___x_700_ = lean_string_dec_eq(v_str_693_, v___x_699_);
if (v___x_700_ == 0)
{
return v___y_688_;
}
else
{
return v_suppressElabErrors_689_;
}
}
}
else
{
lean_object* v___x_701_; uint8_t v___x_702_; 
v___x_701_ = ((lean_object*)(lp_JunkValues_Lean_logAt___at___00Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1_spec__2___redArg___lam__0___closed__3));
v___x_702_ = lean_string_dec_eq(v_str_693_, v___x_701_);
if (v___x_702_ == 0)
{
return v___y_688_;
}
else
{
return v_suppressElabErrors_689_;
}
}
}
case 1:
{
lean_object* v_pre_703_; 
v_pre_703_ = lean_ctor_get(v_pre_692_, 0);
if (lean_obj_tag(v_pre_703_) == 0)
{
lean_object* v_str_704_; lean_object* v_str_705_; lean_object* v_str_706_; lean_object* v___x_707_; uint8_t v___x_708_; 
v_str_704_ = lean_ctor_get(v_x_690_, 1);
v_str_705_ = lean_ctor_get(v_pre_691_, 1);
v_str_706_ = lean_ctor_get(v_pre_692_, 1);
v___x_707_ = ((lean_object*)(lp_JunkValues_Lean_logAt___at___00Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1_spec__2___redArg___lam__0___closed__4));
v___x_708_ = lean_string_dec_eq(v_str_706_, v___x_707_);
if (v___x_708_ == 0)
{
return v___y_688_;
}
else
{
lean_object* v___x_709_; uint8_t v___x_710_; 
v___x_709_ = ((lean_object*)(lp_JunkValues_Lean_logAt___at___00Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1_spec__2___redArg___lam__0___closed__5));
v___x_710_ = lean_string_dec_eq(v_str_705_, v___x_709_);
if (v___x_710_ == 0)
{
return v___y_688_;
}
else
{
lean_object* v___x_711_; uint8_t v___x_712_; 
v___x_711_ = ((lean_object*)(lp_JunkValues_Lean_logAt___at___00Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1_spec__2___redArg___lam__0___closed__6));
v___x_712_ = lean_string_dec_eq(v_str_704_, v___x_711_);
if (v___x_712_ == 0)
{
return v___y_688_;
}
else
{
return v_suppressElabErrors_689_;
}
}
}
}
else
{
return v___y_688_;
}
}
default: 
{
return v___y_688_;
}
}
}
case 0:
{
lean_object* v_str_713_; lean_object* v___x_714_; uint8_t v___x_715_; 
v_str_713_ = lean_ctor_get(v_x_690_, 1);
v___x_714_ = ((lean_object*)(lp_JunkValues_Lean_logAt___at___00Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1_spec__2___redArg___lam__0___closed__7));
v___x_715_ = lean_string_dec_eq(v_str_713_, v___x_714_);
if (v___x_715_ == 0)
{
return v___y_688_;
}
else
{
return v_suppressElabErrors_689_;
}
}
default: 
{
return v___y_688_;
}
}
}
else
{
return v___y_688_;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_logAt___at___00Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1_spec__2___redArg___lam__0___boxed(lean_object* v___y_716_, lean_object* v_suppressElabErrors_717_, lean_object* v_x_718_){
_start:
{
uint8_t v___y_21053__boxed_719_; uint8_t v_suppressElabErrors_boxed_720_; uint8_t v_res_721_; lean_object* v_r_722_; 
v___y_21053__boxed_719_ = lean_unbox(v___y_716_);
v_suppressElabErrors_boxed_720_ = lean_unbox(v_suppressElabErrors_717_);
v_res_721_ = lp_JunkValues_Lean_logAt___at___00Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1_spec__2___redArg___lam__0(v___y_21053__boxed_719_, v_suppressElabErrors_boxed_720_, v_x_718_);
lean_dec(v_x_718_);
v_r_722_ = lean_box(v_res_721_);
return v_r_722_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_logAt___at___00Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1_spec__2___redArg(lean_object* v_ref_724_, lean_object* v_msgData_725_, uint8_t v_severity_726_, uint8_t v_isSilent_727_, lean_object* v___y_728_, lean_object* v___y_729_, lean_object* v___y_730_, lean_object* v___y_731_){
_start:
{
lean_object* v___y_734_; lean_object* v___y_735_; lean_object* v___y_736_; lean_object* v___y_737_; lean_object* v___y_738_; uint8_t v___y_739_; uint8_t v___y_740_; lean_object* v___y_741_; lean_object* v___y_742_; lean_object* v___y_770_; lean_object* v___y_771_; lean_object* v___y_772_; uint8_t v___y_773_; lean_object* v___y_774_; uint8_t v___y_775_; uint8_t v___y_776_; lean_object* v___y_777_; lean_object* v___y_795_; lean_object* v___y_796_; uint8_t v___y_797_; lean_object* v___y_798_; uint8_t v___y_799_; lean_object* v___y_800_; uint8_t v___y_801_; lean_object* v___y_802_; lean_object* v___y_806_; lean_object* v___y_807_; uint8_t v___y_808_; lean_object* v___y_809_; uint8_t v___y_810_; lean_object* v___y_811_; uint8_t v___y_812_; uint8_t v___x_817_; lean_object* v___y_819_; uint8_t v___y_820_; lean_object* v___y_821_; lean_object* v___y_822_; lean_object* v___y_823_; uint8_t v___y_824_; uint8_t v___y_825_; uint8_t v___y_827_; uint8_t v___x_842_; 
v___x_817_ = 2;
v___x_842_ = l_Lean_instBEqMessageSeverity_beq(v_severity_726_, v___x_817_);
if (v___x_842_ == 0)
{
v___y_827_ = v___x_842_;
goto v___jp_826_;
}
else
{
uint8_t v___x_843_; 
lean_inc_ref(v_msgData_725_);
v___x_843_ = l_Lean_MessageData_hasSyntheticSorry(v_msgData_725_);
v___y_827_ = v___x_843_;
goto v___jp_826_;
}
v___jp_733_:
{
lean_object* v___x_743_; lean_object* v_currNamespace_744_; lean_object* v_openDecls_745_; lean_object* v_env_746_; lean_object* v_nextMacroScope_747_; lean_object* v_ngen_748_; lean_object* v_auxDeclNGen_749_; lean_object* v_traceState_750_; lean_object* v_cache_751_; lean_object* v_messages_752_; lean_object* v_infoState_753_; lean_object* v_snapshotTasks_754_; lean_object* v___x_756_; uint8_t v_isShared_757_; uint8_t v_isSharedCheck_768_; 
v___x_743_ = lean_st_ref_take(v___y_742_);
v_currNamespace_744_ = lean_ctor_get(v___y_741_, 6);
v_openDecls_745_ = lean_ctor_get(v___y_741_, 7);
v_env_746_ = lean_ctor_get(v___x_743_, 0);
v_nextMacroScope_747_ = lean_ctor_get(v___x_743_, 1);
v_ngen_748_ = lean_ctor_get(v___x_743_, 2);
v_auxDeclNGen_749_ = lean_ctor_get(v___x_743_, 3);
v_traceState_750_ = lean_ctor_get(v___x_743_, 4);
v_cache_751_ = lean_ctor_get(v___x_743_, 5);
v_messages_752_ = lean_ctor_get(v___x_743_, 6);
v_infoState_753_ = lean_ctor_get(v___x_743_, 7);
v_snapshotTasks_754_ = lean_ctor_get(v___x_743_, 8);
v_isSharedCheck_768_ = !lean_is_exclusive(v___x_743_);
if (v_isSharedCheck_768_ == 0)
{
v___x_756_ = v___x_743_;
v_isShared_757_ = v_isSharedCheck_768_;
goto v_resetjp_755_;
}
else
{
lean_inc(v_snapshotTasks_754_);
lean_inc(v_infoState_753_);
lean_inc(v_messages_752_);
lean_inc(v_cache_751_);
lean_inc(v_traceState_750_);
lean_inc(v_auxDeclNGen_749_);
lean_inc(v_ngen_748_);
lean_inc(v_nextMacroScope_747_);
lean_inc(v_env_746_);
lean_dec(v___x_743_);
v___x_756_ = lean_box(0);
v_isShared_757_ = v_isSharedCheck_768_;
goto v_resetjp_755_;
}
v_resetjp_755_:
{
lean_object* v___x_758_; lean_object* v___x_759_; lean_object* v___x_760_; lean_object* v___x_761_; lean_object* v___x_763_; 
lean_inc(v_openDecls_745_);
lean_inc(v_currNamespace_744_);
v___x_758_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_758_, 0, v_currNamespace_744_);
lean_ctor_set(v___x_758_, 1, v_openDecls_745_);
v___x_759_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_759_, 0, v___x_758_);
lean_ctor_set(v___x_759_, 1, v___y_734_);
lean_inc_ref(v___y_738_);
lean_inc_ref(v___y_737_);
v___x_760_ = lean_alloc_ctor(0, 5, 3);
lean_ctor_set(v___x_760_, 0, v___y_737_);
lean_ctor_set(v___x_760_, 1, v___y_735_);
lean_ctor_set(v___x_760_, 2, v___y_736_);
lean_ctor_set(v___x_760_, 3, v___y_738_);
lean_ctor_set(v___x_760_, 4, v___x_759_);
lean_ctor_set_uint8(v___x_760_, sizeof(void*)*5, v___y_739_);
lean_ctor_set_uint8(v___x_760_, sizeof(void*)*5 + 1, v___y_740_);
lean_ctor_set_uint8(v___x_760_, sizeof(void*)*5 + 2, v_isSilent_727_);
v___x_761_ = l_Lean_MessageLog_add(v___x_760_, v_messages_752_);
if (v_isShared_757_ == 0)
{
lean_ctor_set(v___x_756_, 6, v___x_761_);
v___x_763_ = v___x_756_;
goto v_reusejp_762_;
}
else
{
lean_object* v_reuseFailAlloc_767_; 
v_reuseFailAlloc_767_ = lean_alloc_ctor(0, 9, 0);
lean_ctor_set(v_reuseFailAlloc_767_, 0, v_env_746_);
lean_ctor_set(v_reuseFailAlloc_767_, 1, v_nextMacroScope_747_);
lean_ctor_set(v_reuseFailAlloc_767_, 2, v_ngen_748_);
lean_ctor_set(v_reuseFailAlloc_767_, 3, v_auxDeclNGen_749_);
lean_ctor_set(v_reuseFailAlloc_767_, 4, v_traceState_750_);
lean_ctor_set(v_reuseFailAlloc_767_, 5, v_cache_751_);
lean_ctor_set(v_reuseFailAlloc_767_, 6, v___x_761_);
lean_ctor_set(v_reuseFailAlloc_767_, 7, v_infoState_753_);
lean_ctor_set(v_reuseFailAlloc_767_, 8, v_snapshotTasks_754_);
v___x_763_ = v_reuseFailAlloc_767_;
goto v_reusejp_762_;
}
v_reusejp_762_:
{
lean_object* v___x_764_; lean_object* v___x_765_; lean_object* v___x_766_; 
v___x_764_ = lean_st_ref_set(v___y_742_, v___x_763_);
v___x_765_ = lean_box(0);
v___x_766_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_766_, 0, v___x_765_);
return v___x_766_;
}
}
}
v___jp_769_:
{
lean_object* v___x_778_; lean_object* v___x_779_; lean_object* v_a_780_; lean_object* v___x_782_; uint8_t v_isShared_783_; uint8_t v_isSharedCheck_793_; 
v___x_778_ = l___private_Lean_Log_0__Lean_MessageData_appendDescriptionWidgetIfNamed(v_msgData_725_);
v___x_779_ = lp_JunkValues_Lean_addMessageContextFull___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__7(v___x_778_, v___y_728_, v___y_729_, v___y_730_, v___y_731_);
v_a_780_ = lean_ctor_get(v___x_779_, 0);
v_isSharedCheck_793_ = !lean_is_exclusive(v___x_779_);
if (v_isSharedCheck_793_ == 0)
{
v___x_782_ = v___x_779_;
v_isShared_783_ = v_isSharedCheck_793_;
goto v_resetjp_781_;
}
else
{
lean_inc(v_a_780_);
lean_dec(v___x_779_);
v___x_782_ = lean_box(0);
v_isShared_783_ = v_isSharedCheck_793_;
goto v_resetjp_781_;
}
v_resetjp_781_:
{
lean_object* v___x_784_; lean_object* v___x_785_; lean_object* v___x_786_; lean_object* v___x_787_; 
lean_inc_ref_n(v___y_771_, 2);
v___x_784_ = l_Lean_FileMap_toPosition(v___y_771_, v___y_772_);
lean_dec(v___y_772_);
v___x_785_ = l_Lean_FileMap_toPosition(v___y_771_, v___y_777_);
lean_dec(v___y_777_);
v___x_786_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_786_, 0, v___x_785_);
v___x_787_ = ((lean_object*)(lp_JunkValues_Lean_logAt___at___00Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1_spec__2___redArg___closed__0));
if (v___y_773_ == 0)
{
lean_del_object(v___x_782_);
lean_dec_ref(v___y_770_);
v___y_734_ = v_a_780_;
v___y_735_ = v___x_784_;
v___y_736_ = v___x_786_;
v___y_737_ = v___y_774_;
v___y_738_ = v___x_787_;
v___y_739_ = v___y_775_;
v___y_740_ = v___y_776_;
v___y_741_ = v___y_730_;
v___y_742_ = v___y_731_;
goto v___jp_733_;
}
else
{
uint8_t v___x_788_; 
lean_inc(v_a_780_);
v___x_788_ = l_Lean_MessageData_hasTag(v___y_770_, v_a_780_);
if (v___x_788_ == 0)
{
lean_object* v___x_789_; lean_object* v___x_791_; 
lean_dec_ref_known(v___x_786_, 1);
lean_dec_ref(v___x_784_);
lean_dec(v_a_780_);
v___x_789_ = lean_box(0);
if (v_isShared_783_ == 0)
{
lean_ctor_set(v___x_782_, 0, v___x_789_);
v___x_791_ = v___x_782_;
goto v_reusejp_790_;
}
else
{
lean_object* v_reuseFailAlloc_792_; 
v_reuseFailAlloc_792_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_792_, 0, v___x_789_);
v___x_791_ = v_reuseFailAlloc_792_;
goto v_reusejp_790_;
}
v_reusejp_790_:
{
return v___x_791_;
}
}
else
{
lean_del_object(v___x_782_);
v___y_734_ = v_a_780_;
v___y_735_ = v___x_784_;
v___y_736_ = v___x_786_;
v___y_737_ = v___y_774_;
v___y_738_ = v___x_787_;
v___y_739_ = v___y_775_;
v___y_740_ = v___y_776_;
v___y_741_ = v___y_730_;
v___y_742_ = v___y_731_;
goto v___jp_733_;
}
}
}
}
v___jp_794_:
{
lean_object* v___x_803_; 
v___x_803_ = l_Lean_Syntax_getTailPos_x3f(v___y_800_, v___y_799_);
lean_dec(v___y_800_);
if (lean_obj_tag(v___x_803_) == 0)
{
lean_inc(v___y_802_);
v___y_770_ = v___y_795_;
v___y_771_ = v___y_796_;
v___y_772_ = v___y_802_;
v___y_773_ = v___y_797_;
v___y_774_ = v___y_798_;
v___y_775_ = v___y_799_;
v___y_776_ = v___y_801_;
v___y_777_ = v___y_802_;
goto v___jp_769_;
}
else
{
lean_object* v_val_804_; 
v_val_804_ = lean_ctor_get(v___x_803_, 0);
lean_inc(v_val_804_);
lean_dec_ref_known(v___x_803_, 1);
v___y_770_ = v___y_795_;
v___y_771_ = v___y_796_;
v___y_772_ = v___y_802_;
v___y_773_ = v___y_797_;
v___y_774_ = v___y_798_;
v___y_775_ = v___y_799_;
v___y_776_ = v___y_801_;
v___y_777_ = v_val_804_;
goto v___jp_769_;
}
}
v___jp_805_:
{
lean_object* v_ref_813_; lean_object* v___x_814_; 
v_ref_813_ = l_Lean_replaceRef(v_ref_724_, v___y_811_);
v___x_814_ = l_Lean_Syntax_getPos_x3f(v_ref_813_, v___y_810_);
if (lean_obj_tag(v___x_814_) == 0)
{
lean_object* v___x_815_; 
v___x_815_ = lean_unsigned_to_nat(0u);
v___y_795_ = v___y_806_;
v___y_796_ = v___y_807_;
v___y_797_ = v___y_808_;
v___y_798_ = v___y_809_;
v___y_799_ = v___y_810_;
v___y_800_ = v_ref_813_;
v___y_801_ = v___y_812_;
v___y_802_ = v___x_815_;
goto v___jp_794_;
}
else
{
lean_object* v_val_816_; 
v_val_816_ = lean_ctor_get(v___x_814_, 0);
lean_inc(v_val_816_);
lean_dec_ref_known(v___x_814_, 1);
v___y_795_ = v___y_806_;
v___y_796_ = v___y_807_;
v___y_797_ = v___y_808_;
v___y_798_ = v___y_809_;
v___y_799_ = v___y_810_;
v___y_800_ = v_ref_813_;
v___y_801_ = v___y_812_;
v___y_802_ = v_val_816_;
goto v___jp_794_;
}
}
v___jp_818_:
{
if (v___y_825_ == 0)
{
v___y_806_ = v___y_821_;
v___y_807_ = v___y_819_;
v___y_808_ = v___y_820_;
v___y_809_ = v___y_822_;
v___y_810_ = v___y_824_;
v___y_811_ = v___y_823_;
v___y_812_ = v_severity_726_;
goto v___jp_805_;
}
else
{
v___y_806_ = v___y_821_;
v___y_807_ = v___y_819_;
v___y_808_ = v___y_820_;
v___y_809_ = v___y_822_;
v___y_810_ = v___y_824_;
v___y_811_ = v___y_823_;
v___y_812_ = v___x_817_;
goto v___jp_805_;
}
}
v___jp_826_:
{
if (v___y_827_ == 0)
{
lean_object* v_fileName_828_; lean_object* v_fileMap_829_; lean_object* v_options_830_; lean_object* v_ref_831_; uint8_t v_suppressElabErrors_832_; lean_object* v___x_833_; lean_object* v___x_834_; lean_object* v___f_835_; uint8_t v___x_836_; uint8_t v___x_837_; 
v_fileName_828_ = lean_ctor_get(v___y_730_, 0);
v_fileMap_829_ = lean_ctor_get(v___y_730_, 1);
v_options_830_ = lean_ctor_get(v___y_730_, 2);
v_ref_831_ = lean_ctor_get(v___y_730_, 5);
v_suppressElabErrors_832_ = lean_ctor_get_uint8(v___y_730_, sizeof(void*)*14 + 1);
v___x_833_ = lean_box(v___y_827_);
v___x_834_ = lean_box(v_suppressElabErrors_832_);
v___f_835_ = lean_alloc_closure((void*)(lp_JunkValues_Lean_logAt___at___00Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1_spec__2___redArg___lam__0___boxed), 3, 2);
lean_closure_set(v___f_835_, 0, v___x_833_);
lean_closure_set(v___f_835_, 1, v___x_834_);
v___x_836_ = 1;
v___x_837_ = l_Lean_instBEqMessageSeverity_beq(v_severity_726_, v___x_836_);
if (v___x_837_ == 0)
{
v___y_819_ = v_fileMap_829_;
v___y_820_ = v_suppressElabErrors_832_;
v___y_821_ = v___f_835_;
v___y_822_ = v_fileName_828_;
v___y_823_ = v_ref_831_;
v___y_824_ = v___y_827_;
v___y_825_ = v___x_837_;
goto v___jp_818_;
}
else
{
lean_object* v___x_838_; uint8_t v___x_839_; 
v___x_838_ = l_Lean_warningAsError;
v___x_839_ = lp_JunkValues_Lean_Option_get___at___00Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8_spec__10(v_options_830_, v___x_838_);
v___y_819_ = v_fileMap_829_;
v___y_820_ = v_suppressElabErrors_832_;
v___y_821_ = v___f_835_;
v___y_822_ = v_fileName_828_;
v___y_823_ = v_ref_831_;
v___y_824_ = v___y_827_;
v___y_825_ = v___x_839_;
goto v___jp_818_;
}
}
else
{
lean_object* v___x_840_; lean_object* v___x_841_; 
lean_dec_ref(v_msgData_725_);
v___x_840_ = lean_box(0);
v___x_841_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_841_, 0, v___x_840_);
return v___x_841_;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_logAt___at___00Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1_spec__2___redArg___boxed(lean_object* v_ref_844_, lean_object* v_msgData_845_, lean_object* v_severity_846_, lean_object* v_isSilent_847_, lean_object* v___y_848_, lean_object* v___y_849_, lean_object* v___y_850_, lean_object* v___y_851_, lean_object* v___y_852_){
_start:
{
uint8_t v_severity_boxed_853_; uint8_t v_isSilent_boxed_854_; lean_object* v_res_855_; 
v_severity_boxed_853_ = lean_unbox(v_severity_846_);
v_isSilent_boxed_854_ = lean_unbox(v_isSilent_847_);
v_res_855_ = lp_JunkValues_Lean_logAt___at___00Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1_spec__2___redArg(v_ref_844_, v_msgData_845_, v_severity_boxed_853_, v_isSilent_boxed_854_, v___y_848_, v___y_849_, v___y_850_, v___y_851_);
lean_dec(v___y_851_);
lean_dec_ref(v___y_850_);
lean_dec(v___y_849_);
lean_dec_ref(v___y_848_);
lean_dec(v_ref_844_);
return v_res_855_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1(lean_object* v_msgData_856_, uint8_t v_severity_857_, uint8_t v_isSilent_858_, lean_object* v___y_859_, lean_object* v___y_860_, lean_object* v___y_861_, lean_object* v___y_862_, lean_object* v___y_863_, lean_object* v___y_864_){
_start:
{
lean_object* v_ref_866_; lean_object* v___x_867_; 
v_ref_866_ = lean_ctor_get(v___y_863_, 5);
v___x_867_ = lp_JunkValues_Lean_logAt___at___00Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1_spec__2___redArg(v_ref_866_, v_msgData_856_, v_severity_857_, v_isSilent_858_, v___y_861_, v___y_862_, v___y_863_, v___y_864_);
return v___x_867_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1___boxed(lean_object* v_msgData_868_, lean_object* v_severity_869_, lean_object* v_isSilent_870_, lean_object* v___y_871_, lean_object* v___y_872_, lean_object* v___y_873_, lean_object* v___y_874_, lean_object* v___y_875_, lean_object* v___y_876_, lean_object* v___y_877_){
_start:
{
uint8_t v_severity_boxed_878_; uint8_t v_isSilent_boxed_879_; lean_object* v_res_880_; 
v_severity_boxed_878_ = lean_unbox(v_severity_869_);
v_isSilent_boxed_879_ = lean_unbox(v_isSilent_870_);
v_res_880_ = lp_JunkValues_Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1(v_msgData_868_, v_severity_boxed_878_, v_isSilent_boxed_879_, v___y_871_, v___y_872_, v___y_873_, v___y_874_, v___y_875_, v___y_876_);
lean_dec(v___y_876_);
lean_dec_ref(v___y_875_);
lean_dec(v___y_874_);
lean_dec_ref(v___y_873_);
lean_dec(v___y_872_);
lean_dec_ref(v___y_871_);
return v_res_880_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_logInfo___at___00JunkValues_elabJunkCheck_spec__4(lean_object* v_msgData_881_, lean_object* v___y_882_, lean_object* v___y_883_, lean_object* v___y_884_, lean_object* v___y_885_, lean_object* v___y_886_, lean_object* v___y_887_){
_start:
{
uint8_t v___x_889_; uint8_t v___x_890_; lean_object* v___x_891_; 
v___x_889_ = 0;
v___x_890_ = 0;
v___x_891_ = lp_JunkValues_Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1(v_msgData_881_, v___x_889_, v___x_890_, v___y_882_, v___y_883_, v___y_884_, v___y_885_, v___y_886_, v___y_887_);
return v___x_891_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_logInfo___at___00JunkValues_elabJunkCheck_spec__4___boxed(lean_object* v_msgData_892_, lean_object* v___y_893_, lean_object* v___y_894_, lean_object* v___y_895_, lean_object* v___y_896_, lean_object* v___y_897_, lean_object* v___y_898_, lean_object* v___y_899_){
_start:
{
lean_object* v_res_900_; 
v_res_900_ = lp_JunkValues_Lean_logInfo___at___00JunkValues_elabJunkCheck_spec__4(v_msgData_892_, v___y_893_, v___y_894_, v___y_895_, v___y_896_, v___y_897_, v___y_898_);
lean_dec(v___y_898_);
lean_dec_ref(v___y_897_);
lean_dec(v___y_896_);
lean_dec_ref(v___y_895_);
lean_dec(v___y_894_);
lean_dec_ref(v___y_893_);
return v_res_900_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1(lean_object* v_msgData_901_, lean_object* v___y_902_, lean_object* v___y_903_, lean_object* v___y_904_, lean_object* v___y_905_, lean_object* v___y_906_, lean_object* v___y_907_){
_start:
{
uint8_t v___x_909_; uint8_t v___x_910_; lean_object* v___x_911_; 
v___x_909_ = 1;
v___x_910_ = 0;
v___x_911_ = lp_JunkValues_Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1(v_msgData_901_, v___x_909_, v___x_910_, v___y_902_, v___y_903_, v___y_904_, v___y_905_, v___y_906_, v___y_907_);
return v___x_911_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1___boxed(lean_object* v_msgData_912_, lean_object* v___y_913_, lean_object* v___y_914_, lean_object* v___y_915_, lean_object* v___y_916_, lean_object* v___y_917_, lean_object* v___y_918_, lean_object* v___y_919_){
_start:
{
lean_object* v_res_920_; 
v_res_920_ = lp_JunkValues_Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1(v_msgData_912_, v___y_913_, v___y_914_, v___y_915_, v___y_916_, v___y_917_, v___y_918_);
lean_dec(v___y_918_);
lean_dec_ref(v___y_917_);
lean_dec(v___y_916_);
lean_dec_ref(v___y_915_);
lean_dec(v___y_914_);
lean_dec_ref(v___y_913_);
return v_res_920_;
}
}
static lean_object* _init_lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__2___closed__1(void){
_start:
{
lean_object* v___x_922_; lean_object* v___x_923_; 
v___x_922_ = ((lean_object*)(lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__2___closed__0));
v___x_923_ = l_Lean_stringToMessageData(v___x_922_);
return v___x_923_;
}
}
static lean_object* _init_lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__2___closed__3(void){
_start:
{
lean_object* v___x_925_; lean_object* v___x_926_; 
v___x_925_ = ((lean_object*)(lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__2___closed__2));
v___x_926_ = l_Lean_stringToMessageData(v___x_925_);
return v___x_926_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__2(lean_object* v_as_927_, size_t v_sz_928_, size_t v_i_929_, lean_object* v_b_930_, lean_object* v___y_931_, lean_object* v___y_932_, lean_object* v___y_933_, lean_object* v___y_934_, lean_object* v___y_935_, lean_object* v___y_936_){
_start:
{
uint8_t v___x_938_; 
v___x_938_ = lean_usize_dec_lt(v_i_929_, v_sz_928_);
if (v___x_938_ == 0)
{
lean_object* v___x_939_; 
v___x_939_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_939_, 0, v_b_930_);
return v___x_939_;
}
else
{
lean_object* v_a_940_; lean_object* v_fst_941_; lean_object* v_snd_942_; lean_object* v___x_944_; uint8_t v_isShared_945_; uint8_t v_isSharedCheck_960_; 
v_a_940_ = lean_array_uget(v_as_927_, v_i_929_);
v_fst_941_ = lean_ctor_get(v_a_940_, 0);
v_snd_942_ = lean_ctor_get(v_a_940_, 1);
v_isSharedCheck_960_ = !lean_is_exclusive(v_a_940_);
if (v_isSharedCheck_960_ == 0)
{
v___x_944_ = v_a_940_;
v_isShared_945_ = v_isSharedCheck_960_;
goto v_resetjp_943_;
}
else
{
lean_inc(v_snd_942_);
lean_inc(v_fst_941_);
lean_dec(v_a_940_);
v___x_944_ = lean_box(0);
v_isShared_945_ = v_isSharedCheck_960_;
goto v_resetjp_943_;
}
v_resetjp_943_:
{
lean_object* v___x_946_; lean_object* v___x_947_; lean_object* v___x_949_; 
v___x_946_ = lean_obj_once(&lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__2___closed__1, &lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__2___closed__1_once, _init_lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__2___closed__1);
v___x_947_ = l_Lean_MessageData_ofName(v_fst_941_);
if (v_isShared_945_ == 0)
{
lean_ctor_set_tag(v___x_944_, 7);
lean_ctor_set(v___x_944_, 1, v___x_947_);
lean_ctor_set(v___x_944_, 0, v___x_946_);
v___x_949_ = v___x_944_;
goto v_reusejp_948_;
}
else
{
lean_object* v_reuseFailAlloc_959_; 
v_reuseFailAlloc_959_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v_reuseFailAlloc_959_, 0, v___x_946_);
lean_ctor_set(v_reuseFailAlloc_959_, 1, v___x_947_);
v___x_949_ = v_reuseFailAlloc_959_;
goto v_reusejp_948_;
}
v_reusejp_948_:
{
lean_object* v___x_950_; lean_object* v___x_951_; lean_object* v___x_952_; lean_object* v___x_953_; lean_object* v___x_954_; 
v___x_950_ = lean_obj_once(&lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__2___closed__3, &lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__2___closed__3_once, _init_lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__2___closed__3);
v___x_951_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_951_, 0, v___x_949_);
lean_ctor_set(v___x_951_, 1, v___x_950_);
v___x_952_ = l_Lean_stringToMessageData(v_snd_942_);
v___x_953_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_953_, 0, v___x_951_);
lean_ctor_set(v___x_953_, 1, v___x_952_);
v___x_954_ = lp_JunkValues_Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1(v___x_953_, v___y_931_, v___y_932_, v___y_933_, v___y_934_, v___y_935_, v___y_936_);
if (lean_obj_tag(v___x_954_) == 0)
{
lean_object* v___x_955_; size_t v___x_956_; size_t v___x_957_; 
lean_dec_ref_known(v___x_954_, 1);
v___x_955_ = lean_box(0);
v___x_956_ = ((size_t)1ULL);
v___x_957_ = lean_usize_add(v_i_929_, v___x_956_);
v_i_929_ = v___x_957_;
v_b_930_ = v___x_955_;
goto _start;
}
else
{
return v___x_954_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__2___boxed(lean_object* v_as_961_, lean_object* v_sz_962_, lean_object* v_i_963_, lean_object* v_b_964_, lean_object* v___y_965_, lean_object* v___y_966_, lean_object* v___y_967_, lean_object* v___y_968_, lean_object* v___y_969_, lean_object* v___y_970_, lean_object* v___y_971_){
_start:
{
size_t v_sz_boxed_972_; size_t v_i_boxed_973_; lean_object* v_res_974_; 
v_sz_boxed_972_ = lean_unbox_usize(v_sz_962_);
lean_dec(v_sz_962_);
v_i_boxed_973_ = lean_unbox_usize(v_i_963_);
lean_dec(v_i_963_);
v_res_974_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__2(v_as_961_, v_sz_boxed_972_, v_i_boxed_973_, v_b_964_, v___y_965_, v___y_966_, v___y_967_, v___y_968_, v___y_969_, v___y_970_);
lean_dec(v___y_970_);
lean_dec_ref(v___y_969_);
lean_dec(v___y_968_);
lean_dec_ref(v___y_967_);
lean_dec(v___y_966_);
lean_dec_ref(v___y_965_);
lean_dec_ref(v_as_961_);
return v_res_974_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__5(lean_object* v_as_975_, size_t v_sz_976_, size_t v_i_977_, lean_object* v_b_978_, lean_object* v___y_979_, lean_object* v___y_980_, lean_object* v___y_981_, lean_object* v___y_982_, lean_object* v___y_983_, lean_object* v___y_984_){
_start:
{
uint8_t v___x_986_; 
v___x_986_ = lean_usize_dec_lt(v_i_977_, v_sz_976_);
if (v___x_986_ == 0)
{
lean_object* v___x_987_; 
v___x_987_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_987_, 0, v_b_978_);
return v___x_987_;
}
else
{
lean_object* v_a_988_; lean_object* v___x_989_; lean_object* v___x_990_; 
v_a_988_ = lean_array_uget_borrowed(v_as_975_, v_i_977_);
lean_inc(v_a_988_);
v___x_989_ = l_Lean_stringToMessageData(v_a_988_);
v___x_990_ = lp_JunkValues_Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1(v___x_989_, v___y_979_, v___y_980_, v___y_981_, v___y_982_, v___y_983_, v___y_984_);
if (lean_obj_tag(v___x_990_) == 0)
{
lean_object* v___x_991_; size_t v___x_992_; size_t v___x_993_; 
lean_dec_ref_known(v___x_990_, 1);
v___x_991_ = lean_box(0);
v___x_992_ = ((size_t)1ULL);
v___x_993_ = lean_usize_add(v_i_977_, v___x_992_);
v_i_977_ = v___x_993_;
v_b_978_ = v___x_991_;
goto _start;
}
else
{
return v___x_990_;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__5___boxed(lean_object* v_as_995_, lean_object* v_sz_996_, lean_object* v_i_997_, lean_object* v_b_998_, lean_object* v___y_999_, lean_object* v___y_1000_, lean_object* v___y_1001_, lean_object* v___y_1002_, lean_object* v___y_1003_, lean_object* v___y_1004_, lean_object* v___y_1005_){
_start:
{
size_t v_sz_boxed_1006_; size_t v_i_boxed_1007_; lean_object* v_res_1008_; 
v_sz_boxed_1006_ = lean_unbox_usize(v_sz_996_);
lean_dec(v_sz_996_);
v_i_boxed_1007_ = lean_unbox_usize(v_i_997_);
lean_dec(v_i_997_);
v_res_1008_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__5(v_as_995_, v_sz_boxed_1006_, v_i_boxed_1007_, v_b_998_, v___y_999_, v___y_1000_, v___y_1001_, v___y_1002_, v___y_1003_, v___y_1004_);
lean_dec(v___y_1004_);
lean_dec_ref(v___y_1003_);
lean_dec(v___y_1002_);
lean_dec_ref(v___y_1001_);
lean_dec(v___y_1000_);
lean_dec_ref(v___y_999_);
lean_dec_ref(v_as_995_);
return v_res_1008_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__0(void){
_start:
{
lean_object* v___x_1009_; lean_object* v___x_1010_; 
v___x_1009_ = ((lean_object*)(lp_JunkValues_Lean_logAt___at___00Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1_spec__2___redArg___closed__0));
v___x_1010_ = l_Lean_stringToMessageData(v___x_1009_);
return v___x_1010_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__2(void){
_start:
{
lean_object* v___x_1012_; lean_object* v___x_1013_; 
v___x_1012_ = ((lean_object*)(lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__1));
v___x_1013_ = l_Lean_stringToMessageData(v___x_1012_);
return v___x_1013_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__4(void){
_start:
{
lean_object* v___x_1015_; lean_object* v___x_1016_; 
v___x_1015_ = ((lean_object*)(lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__3));
v___x_1016_ = l_Lean_stringToMessageData(v___x_1015_);
return v___x_1016_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__6(void){
_start:
{
lean_object* v___x_1018_; lean_object* v___x_1019_; 
v___x_1018_ = ((lean_object*)(lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__5));
v___x_1019_ = l_Lean_stringToMessageData(v___x_1018_);
return v___x_1019_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__8(void){
_start:
{
lean_object* v___x_1021_; lean_object* v___x_1022_; 
v___x_1021_ = ((lean_object*)(lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__7));
v___x_1022_ = l_Lean_stringToMessageData(v___x_1021_);
return v___x_1022_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__10(void){
_start:
{
lean_object* v___x_1024_; lean_object* v___x_1025_; 
v___x_1024_ = ((lean_object*)(lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__9));
v___x_1025_ = l_Lean_stringToMessageData(v___x_1024_);
return v___x_1025_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__12(void){
_start:
{
lean_object* v___x_1027_; lean_object* v___x_1028_; 
v___x_1027_ = ((lean_object*)(lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__11));
v___x_1028_ = l_Lean_stringToMessageData(v___x_1027_);
return v___x_1028_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__15(void){
_start:
{
lean_object* v___x_1032_; lean_object* v___x_1033_; 
v___x_1032_ = ((lean_object*)(lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__14));
v___x_1033_ = l_Lean_stringToMessageData(v___x_1032_);
return v___x_1033_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__17(void){
_start:
{
lean_object* v___x_1035_; lean_object* v___x_1036_; 
v___x_1035_ = ((lean_object*)(lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__16));
v___x_1036_ = l_Lean_stringToMessageData(v___x_1035_);
return v___x_1036_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_elabJunkCheck___lam__1(lean_object* v_opts_1037_, lean_object* v___y_1038_, lean_object* v___x_1039_, lean_object* v___y_1040_, lean_object* v___y_1041_, lean_object* v___y_1042_, lean_object* v___y_1043_, lean_object* v___y_1044_, lean_object* v___y_1045_){
_start:
{
lean_object* v___x_1047_; 
v___x_1047_ = lp_JunkValues_JunkValues_setupOf(v_opts_1037_, v___y_1042_, v___y_1043_, v___y_1044_, v___y_1045_);
if (lean_obj_tag(v___x_1047_) == 0)
{
lean_object* v_a_1048_; lean_object* v_snd_1049_; lean_object* v_fst_1050_; lean_object* v___x_1052_; uint8_t v_isShared_1053_; uint8_t v_isSharedCheck_1265_; 
v_a_1048_ = lean_ctor_get(v___x_1047_, 0);
lean_inc(v_a_1048_);
lean_dec_ref_known(v___x_1047_, 1);
v_snd_1049_ = lean_ctor_get(v_a_1048_, 1);
v_fst_1050_ = lean_ctor_get(v_a_1048_, 0);
v_isSharedCheck_1265_ = !lean_is_exclusive(v_a_1048_);
if (v_isSharedCheck_1265_ == 0)
{
v___x_1052_ = v_a_1048_;
v_isShared_1053_ = v_isSharedCheck_1265_;
goto v_resetjp_1051_;
}
else
{
lean_inc(v_snd_1049_);
lean_inc(v_fst_1050_);
lean_dec(v_a_1048_);
v___x_1052_ = lean_box(0);
v_isShared_1053_ = v_isSharedCheck_1265_;
goto v_resetjp_1051_;
}
v_resetjp_1051_:
{
lean_object* v_fst_1054_; lean_object* v_snd_1055_; lean_object* v___x_1057_; uint8_t v_isShared_1058_; uint8_t v_isSharedCheck_1264_; 
v_fst_1054_ = lean_ctor_get(v_snd_1049_, 0);
v_snd_1055_ = lean_ctor_get(v_snd_1049_, 1);
v_isSharedCheck_1264_ = !lean_is_exclusive(v_snd_1049_);
if (v_isSharedCheck_1264_ == 0)
{
v___x_1057_ = v_snd_1049_;
v_isShared_1058_ = v_isSharedCheck_1264_;
goto v_resetjp_1056_;
}
else
{
lean_inc(v_snd_1055_);
lean_inc(v_fst_1054_);
lean_dec(v_snd_1049_);
v___x_1057_ = lean_box(0);
v_isShared_1058_ = v_isSharedCheck_1264_;
goto v_resetjp_1056_;
}
v_resetjp_1056_:
{
lean_object* v___x_1059_; lean_object* v_names_1061_; lean_object* v___y_1062_; lean_object* v___y_1063_; lean_object* v___y_1064_; lean_object* v___y_1065_; lean_object* v___y_1066_; lean_object* v___y_1067_; lean_object* v___y_1180_; lean_object* v___y_1181_; lean_object* v___y_1182_; lean_object* v___y_1183_; lean_object* v___y_1184_; lean_object* v___y_1185_; lean_object* v___y_1186_; lean_object* v___y_1187_; lean_object* v___y_1188_; lean_object* v___y_1189_; lean_object* v___y_1192_; lean_object* v___y_1193_; lean_object* v___y_1194_; lean_object* v___y_1195_; lean_object* v___y_1196_; lean_object* v___y_1197_; lean_object* v___y_1198_; lean_object* v___y_1199_; lean_object* v___y_1200_; lean_object* v___y_1201_; lean_object* v___y_1204_; lean_object* v___y_1205_; lean_object* v___y_1206_; lean_object* v___y_1207_; lean_object* v___y_1208_; lean_object* v___y_1209_; lean_object* v___y_1210_; size_t v_sz_1216_; size_t v___x_1217_; lean_object* v___x_1218_; 
v___x_1059_ = lean_box(0);
v_sz_1216_ = lean_array_size(v_snd_1055_);
v___x_1217_ = ((size_t)0ULL);
v___x_1218_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__5(v_snd_1055_, v_sz_1216_, v___x_1217_, v___x_1059_, v___y_1040_, v___y_1041_, v___y_1042_, v___y_1043_, v___y_1044_, v___y_1045_);
lean_dec(v_snd_1055_);
if (lean_obj_tag(v___x_1218_) == 0)
{
lean_object* v___x_1219_; 
lean_dec_ref_known(v___x_1218_, 1);
v___x_1219_ = lean_st_ref_get(v___y_1045_);
if (lean_obj_tag(v___y_1038_) == 0)
{
lean_object* v___x_1220_; lean_object* v___x_1221_; lean_object* v_a_1222_; lean_object* v___x_1224_; uint8_t v_isShared_1225_; uint8_t v_isSharedCheck_1229_; 
lean_dec(v___x_1219_);
lean_del_object(v___x_1057_);
lean_dec(v_fst_1054_);
lean_del_object(v___x_1052_);
lean_dec(v_fst_1050_);
v___x_1220_ = lean_obj_once(&lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__12, &lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__12_once, _init_lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__12);
v___x_1221_ = lp_JunkValues_Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6___redArg(v___x_1220_, v___y_1040_, v___y_1041_, v___y_1042_, v___y_1043_, v___y_1044_, v___y_1045_);
v_a_1222_ = lean_ctor_get(v___x_1221_, 0);
v_isSharedCheck_1229_ = !lean_is_exclusive(v___x_1221_);
if (v_isSharedCheck_1229_ == 0)
{
v___x_1224_ = v___x_1221_;
v_isShared_1225_ = v_isSharedCheck_1229_;
goto v_resetjp_1223_;
}
else
{
lean_inc(v_a_1222_);
lean_dec(v___x_1221_);
v___x_1224_ = lean_box(0);
v_isShared_1225_ = v_isSharedCheck_1229_;
goto v_resetjp_1223_;
}
v_resetjp_1223_:
{
lean_object* v___x_1227_; 
if (v_isShared_1225_ == 0)
{
v___x_1227_ = v___x_1224_;
goto v_reusejp_1226_;
}
else
{
lean_object* v_reuseFailAlloc_1228_; 
v_reuseFailAlloc_1228_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1228_, 0, v_a_1222_);
v___x_1227_ = v_reuseFailAlloc_1228_;
goto v_reusejp_1226_;
}
v_reusejp_1226_:
{
return v___x_1227_;
}
}
}
else
{
lean_object* v_val_1230_; lean_object* v_env_1231_; uint8_t v___x_1232_; uint8_t v___x_1233_; 
v_val_1230_ = lean_ctor_get(v___y_1038_, 0);
lean_inc_n(v_val_1230_, 2);
lean_dec_ref_known(v___y_1038_, 1);
v_env_1231_ = lean_ctor_get(v___x_1219_, 0);
lean_inc_ref_n(v_env_1231_, 2);
lean_dec(v___x_1219_);
v___x_1232_ = 1;
v___x_1233_ = l_Lean_Environment_contains(v_env_1231_, v_val_1230_, v___x_1232_);
if (v___x_1233_ == 0)
{
lean_object* v___x_1234_; lean_object* v___f_1235_; lean_object* v___x_1236_; lean_object* v___x_1237_; lean_object* v___x_1238_; lean_object* v___x_1239_; 
v___x_1234_ = lean_box(v___x_1233_);
lean_inc(v_val_1230_);
v___f_1235_ = lean_alloc_closure((void*)(lp_JunkValues_JunkValues_elabJunkCheck___lam__0___boxed), 13, 3);
lean_closure_set(v___f_1235_, 0, v___x_1059_);
lean_closure_set(v___f_1235_, 1, v___x_1234_);
lean_closure_set(v___f_1235_, 2, v_val_1230_);
v___x_1236_ = lean_unsigned_to_nat(0u);
v___x_1237_ = ((lean_object*)(lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__13));
v___x_1238_ = l_Lean_Environment_constants(v_env_1231_);
v___x_1239_ = lp_JunkValues_Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8___redArg(v___x_1238_, v___f_1235_, v___x_1237_, v___y_1040_, v___y_1041_, v___y_1042_, v___y_1043_, v___y_1044_, v___y_1045_);
if (lean_obj_tag(v___x_1239_) == 0)
{
lean_object* v_a_1240_; lean_object* v_a_1242_; 
v_a_1240_ = lean_ctor_get(v___x_1239_, 0);
lean_inc(v_a_1240_);
lean_dec_ref_known(v___x_1239_, 1);
if (lean_obj_tag(v_a_1240_) == 0)
{
lean_object* v_a_1251_; 
v_a_1251_ = lean_ctor_get(v_a_1240_, 0);
lean_inc(v_a_1251_);
lean_dec_ref_known(v_a_1240_, 1);
v_a_1242_ = v_a_1251_;
goto v___jp_1241_;
}
else
{
lean_object* v_a_1252_; lean_object* v_snd_1253_; 
v_a_1252_ = lean_ctor_get(v_a_1240_, 0);
lean_inc(v_a_1252_);
lean_dec_ref_known(v_a_1240_, 1);
v_snd_1253_ = lean_ctor_get(v_a_1252_, 1);
lean_inc(v_snd_1253_);
lean_dec(v_a_1252_);
v_a_1242_ = v_snd_1253_;
goto v___jp_1241_;
}
v___jp_1241_:
{
lean_object* v___x_1243_; uint8_t v___x_1244_; 
v___x_1243_ = lean_array_get_size(v_a_1242_);
v___x_1244_ = lean_nat_dec_eq(v___x_1243_, v___x_1236_);
if (v___x_1244_ == 0)
{
lean_dec(v_val_1230_);
v___y_1204_ = v_a_1242_;
v___y_1205_ = v___y_1040_;
v___y_1206_ = v___y_1041_;
v___y_1207_ = v___y_1042_;
v___y_1208_ = v___y_1043_;
v___y_1209_ = v___y_1044_;
v___y_1210_ = v___y_1045_;
goto v___jp_1203_;
}
else
{
lean_object* v___x_1245_; lean_object* v___x_1246_; lean_object* v___x_1247_; lean_object* v___x_1248_; lean_object* v___x_1249_; lean_object* v___x_1250_; 
lean_dec_ref(v_a_1242_);
lean_del_object(v___x_1057_);
lean_dec(v_fst_1054_);
lean_del_object(v___x_1052_);
lean_dec(v_fst_1050_);
v___x_1245_ = lean_obj_once(&lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__15, &lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__15_once, _init_lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__15);
v___x_1246_ = l_Lean_MessageData_ofName(v_val_1230_);
v___x_1247_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1247_, 0, v___x_1245_);
lean_ctor_set(v___x_1247_, 1, v___x_1246_);
v___x_1248_ = lean_obj_once(&lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__17, &lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__17_once, _init_lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__17);
v___x_1249_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1249_, 0, v___x_1247_);
lean_ctor_set(v___x_1249_, 1, v___x_1248_);
v___x_1250_ = lp_JunkValues_Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6___redArg(v___x_1249_, v___y_1040_, v___y_1041_, v___y_1042_, v___y_1043_, v___y_1044_, v___y_1045_);
return v___x_1250_;
}
}
}
else
{
lean_object* v_a_1254_; lean_object* v___x_1256_; uint8_t v_isShared_1257_; uint8_t v_isSharedCheck_1261_; 
lean_dec(v_val_1230_);
lean_del_object(v___x_1057_);
lean_dec(v_fst_1054_);
lean_del_object(v___x_1052_);
lean_dec(v_fst_1050_);
v_a_1254_ = lean_ctor_get(v___x_1239_, 0);
v_isSharedCheck_1261_ = !lean_is_exclusive(v___x_1239_);
if (v_isSharedCheck_1261_ == 0)
{
v___x_1256_ = v___x_1239_;
v_isShared_1257_ = v_isSharedCheck_1261_;
goto v_resetjp_1255_;
}
else
{
lean_inc(v_a_1254_);
lean_dec(v___x_1239_);
v___x_1256_ = lean_box(0);
v_isShared_1257_ = v_isSharedCheck_1261_;
goto v_resetjp_1255_;
}
v_resetjp_1255_:
{
lean_object* v___x_1259_; 
if (v_isShared_1257_ == 0)
{
v___x_1259_ = v___x_1256_;
goto v_reusejp_1258_;
}
else
{
lean_object* v_reuseFailAlloc_1260_; 
v_reuseFailAlloc_1260_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1260_, 0, v_a_1254_);
v___x_1259_ = v_reuseFailAlloc_1260_;
goto v_reusejp_1258_;
}
v_reusejp_1258_:
{
return v___x_1259_;
}
}
}
}
else
{
lean_object* v___x_1262_; lean_object* v___x_1263_; 
lean_dec_ref(v_env_1231_);
v___x_1262_ = lean_mk_empty_array_with_capacity(v___x_1039_);
v___x_1263_ = lean_array_push(v___x_1262_, v_val_1230_);
v_names_1061_ = v___x_1263_;
v___y_1062_ = v___y_1040_;
v___y_1063_ = v___y_1041_;
v___y_1064_ = v___y_1042_;
v___y_1065_ = v___y_1043_;
v___y_1066_ = v___y_1044_;
v___y_1067_ = v___y_1045_;
goto v___jp_1060_;
}
}
}
else
{
lean_del_object(v___x_1057_);
lean_dec(v_fst_1054_);
lean_del_object(v___x_1052_);
lean_dec(v_fst_1050_);
lean_dec(v___y_1038_);
return v___x_1218_;
}
v___jp_1060_:
{
lean_object* v_ruleSet_1068_; lean_object* v___x_1069_; 
v_ruleSet_1068_ = lean_ctor_get(v_fst_1050_, 0);
lean_inc_ref_n(v_ruleSet_1068_, 2);
lean_dec(v_fst_1050_);
v___x_1069_ = lp_JunkValues_JunkValues_scanDecls(v_ruleSet_1068_, v_fst_1054_, v_names_1061_, v___y_1064_, v___y_1065_, v___y_1066_, v___y_1067_);
if (lean_obj_tag(v___x_1069_) == 0)
{
lean_object* v_a_1070_; lean_object* v_fst_1071_; lean_object* v_snd_1072_; lean_object* v___x_1074_; uint8_t v_isShared_1075_; uint8_t v_isSharedCheck_1170_; 
v_a_1070_ = lean_ctor_get(v___x_1069_, 0);
lean_inc(v_a_1070_);
lean_dec_ref_known(v___x_1069_, 1);
v_fst_1071_ = lean_ctor_get(v_a_1070_, 0);
v_snd_1072_ = lean_ctor_get(v_a_1070_, 1);
v_isSharedCheck_1170_ = !lean_is_exclusive(v_a_1070_);
if (v_isSharedCheck_1170_ == 0)
{
v___x_1074_ = v_a_1070_;
v_isShared_1075_ = v_isSharedCheck_1170_;
goto v_resetjp_1073_;
}
else
{
lean_inc(v_snd_1072_);
lean_inc(v_fst_1071_);
lean_dec(v_a_1070_);
v___x_1074_ = lean_box(0);
v_isShared_1075_ = v_isSharedCheck_1170_;
goto v_resetjp_1073_;
}
v_resetjp_1073_:
{
size_t v_sz_1076_; size_t v___x_1077_; lean_object* v___x_1078_; 
v_sz_1076_ = lean_array_size(v_snd_1072_);
v___x_1077_ = ((size_t)0ULL);
v___x_1078_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__2(v_snd_1072_, v_sz_1076_, v___x_1077_, v___x_1059_, v___y_1062_, v___y_1063_, v___y_1064_, v___y_1065_, v___y_1066_, v___y_1067_);
lean_dec(v_snd_1072_);
if (lean_obj_tag(v___x_1078_) == 0)
{
lean_object* v___x_1080_; uint8_t v_isShared_1081_; uint8_t v_isSharedCheck_1168_; 
v_isSharedCheck_1168_ = !lean_is_exclusive(v___x_1078_);
if (v_isSharedCheck_1168_ == 0)
{
lean_object* v_unused_1169_; 
v_unused_1169_ = lean_ctor_get(v___x_1078_, 0);
lean_dec(v_unused_1169_);
v___x_1080_ = v___x_1078_;
v_isShared_1081_ = v_isSharedCheck_1168_;
goto v_resetjp_1079_;
}
else
{
lean_dec(v___x_1078_);
v___x_1080_ = lean_box(0);
v_isShared_1081_ = v_isSharedCheck_1168_;
goto v_resetjp_1079_;
}
v_resetjp_1079_:
{
lean_object* v___x_1082_; lean_object* v___x_1083_; uint8_t v___x_1084_; 
v___x_1082_ = lean_array_get_size(v_fst_1071_);
v___x_1083_ = lean_unsigned_to_nat(0u);
v___x_1084_ = lean_nat_dec_eq(v___x_1082_, v___x_1083_);
if (v___x_1084_ == 0)
{
lean_object* v___x_1085_; size_t v_sz_1086_; lean_object* v___x_1087_; 
v___x_1085_ = lean_obj_once(&lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__0, &lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__0_once, _init_lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__0);
v_sz_1086_ = lean_array_size(v_fst_1071_);
v___x_1087_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__3(v_fst_1071_, v_sz_1086_, v___x_1077_, v___x_1085_, v___y_1062_, v___y_1063_, v___y_1064_, v___y_1065_, v___y_1066_, v___y_1067_);
lean_dec(v_fst_1071_);
if (lean_obj_tag(v___x_1087_) == 0)
{
lean_object* v_a_1088_; lean_object* v_rules_1089_; lean_object* v___x_1091_; uint8_t v_isShared_1092_; uint8_t v_isSharedCheck_1126_; 
v_a_1088_ = lean_ctor_get(v___x_1087_, 0);
lean_inc(v_a_1088_);
lean_dec_ref_known(v___x_1087_, 1);
v_rules_1089_ = lean_ctor_get(v_ruleSet_1068_, 1);
v_isSharedCheck_1126_ = !lean_is_exclusive(v_ruleSet_1068_);
if (v_isSharedCheck_1126_ == 0)
{
lean_object* v_unused_1127_; 
v_unused_1127_ = lean_ctor_get(v_ruleSet_1068_, 0);
lean_dec(v_unused_1127_);
v___x_1091_ = v_ruleSet_1068_;
v_isShared_1092_ = v_isSharedCheck_1126_;
goto v_resetjp_1090_;
}
else
{
lean_inc(v_rules_1089_);
lean_dec(v_ruleSet_1068_);
v___x_1091_ = lean_box(0);
v_isShared_1092_ = v_isSharedCheck_1126_;
goto v_resetjp_1090_;
}
v_resetjp_1090_:
{
lean_object* v___x_1093_; lean_object* v___x_1094_; lean_object* v___x_1096_; 
v___x_1093_ = lean_obj_once(&lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__0___redArg___closed__1, &lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__0___redArg___closed__1_once, _init_lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__0___redArg___closed__1);
v___x_1094_ = l_Nat_reprFast(v___x_1082_);
if (v_isShared_1081_ == 0)
{
lean_ctor_set_tag(v___x_1080_, 3);
lean_ctor_set(v___x_1080_, 0, v___x_1094_);
v___x_1096_ = v___x_1080_;
goto v_reusejp_1095_;
}
else
{
lean_object* v_reuseFailAlloc_1125_; 
v_reuseFailAlloc_1125_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1125_, 0, v___x_1094_);
v___x_1096_ = v_reuseFailAlloc_1125_;
goto v_reusejp_1095_;
}
v_reusejp_1095_:
{
lean_object* v___x_1097_; lean_object* v___x_1099_; 
v___x_1097_ = l_Lean_MessageData_ofFormat(v___x_1096_);
if (v_isShared_1092_ == 0)
{
lean_ctor_set_tag(v___x_1091_, 7);
lean_ctor_set(v___x_1091_, 1, v___x_1097_);
lean_ctor_set(v___x_1091_, 0, v___x_1093_);
v___x_1099_ = v___x_1091_;
goto v_reusejp_1098_;
}
else
{
lean_object* v_reuseFailAlloc_1124_; 
v_reuseFailAlloc_1124_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1124_, 0, v___x_1093_);
lean_ctor_set(v_reuseFailAlloc_1124_, 1, v___x_1097_);
v___x_1099_ = v_reuseFailAlloc_1124_;
goto v_reusejp_1098_;
}
v_reusejp_1098_:
{
lean_object* v___x_1100_; lean_object* v___x_1102_; 
v___x_1100_ = lean_obj_once(&lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__2, &lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__2_once, _init_lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__2);
if (v_isShared_1075_ == 0)
{
lean_ctor_set_tag(v___x_1074_, 7);
lean_ctor_set(v___x_1074_, 1, v___x_1100_);
lean_ctor_set(v___x_1074_, 0, v___x_1099_);
v___x_1102_ = v___x_1074_;
goto v_reusejp_1101_;
}
else
{
lean_object* v_reuseFailAlloc_1123_; 
v_reuseFailAlloc_1123_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1123_, 0, v___x_1099_);
lean_ctor_set(v_reuseFailAlloc_1123_, 1, v___x_1100_);
v___x_1102_ = v_reuseFailAlloc_1123_;
goto v_reusejp_1101_;
}
v_reusejp_1101_:
{
lean_object* v___x_1103_; lean_object* v___x_1104_; lean_object* v___x_1105_; lean_object* v___x_1106_; lean_object* v___x_1108_; 
v___x_1103_ = lean_array_get_size(v_names_1061_);
lean_dec_ref(v_names_1061_);
v___x_1104_ = l_Nat_reprFast(v___x_1103_);
v___x_1105_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_1105_, 0, v___x_1104_);
v___x_1106_ = l_Lean_MessageData_ofFormat(v___x_1105_);
if (v_isShared_1058_ == 0)
{
lean_ctor_set_tag(v___x_1057_, 7);
lean_ctor_set(v___x_1057_, 1, v___x_1106_);
lean_ctor_set(v___x_1057_, 0, v___x_1102_);
v___x_1108_ = v___x_1057_;
goto v_reusejp_1107_;
}
else
{
lean_object* v_reuseFailAlloc_1122_; 
v_reuseFailAlloc_1122_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1122_, 0, v___x_1102_);
lean_ctor_set(v_reuseFailAlloc_1122_, 1, v___x_1106_);
v___x_1108_ = v_reuseFailAlloc_1122_;
goto v_reusejp_1107_;
}
v_reusejp_1107_:
{
lean_object* v___x_1109_; lean_object* v___x_1111_; 
v___x_1109_ = lean_obj_once(&lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__4, &lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__4_once, _init_lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__4);
if (v_isShared_1053_ == 0)
{
lean_ctor_set_tag(v___x_1052_, 7);
lean_ctor_set(v___x_1052_, 1, v___x_1109_);
lean_ctor_set(v___x_1052_, 0, v___x_1108_);
v___x_1111_ = v___x_1052_;
goto v_reusejp_1110_;
}
else
{
lean_object* v_reuseFailAlloc_1121_; 
v_reuseFailAlloc_1121_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1121_, 0, v___x_1108_);
lean_ctor_set(v_reuseFailAlloc_1121_, 1, v___x_1109_);
v___x_1111_ = v_reuseFailAlloc_1121_;
goto v_reusejp_1110_;
}
v_reusejp_1110_:
{
lean_object* v___x_1112_; lean_object* v___x_1113_; lean_object* v___x_1114_; lean_object* v___x_1115_; lean_object* v___x_1116_; lean_object* v___x_1117_; lean_object* v___x_1118_; lean_object* v___x_1119_; lean_object* v___x_1120_; 
v___x_1112_ = lean_array_get_size(v_rules_1089_);
lean_dec_ref(v_rules_1089_);
v___x_1113_ = l_Nat_reprFast(v___x_1112_);
v___x_1114_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_1114_, 0, v___x_1113_);
v___x_1115_ = l_Lean_MessageData_ofFormat(v___x_1114_);
v___x_1116_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1116_, 0, v___x_1111_);
lean_ctor_set(v___x_1116_, 1, v___x_1115_);
v___x_1117_ = lean_obj_once(&lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__6, &lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__6_once, _init_lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__6);
v___x_1118_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1118_, 0, v___x_1116_);
lean_ctor_set(v___x_1118_, 1, v___x_1117_);
v___x_1119_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1119_, 0, v_a_1088_);
lean_ctor_set(v___x_1119_, 1, v___x_1118_);
v___x_1120_ = lp_JunkValues_Lean_logInfo___at___00JunkValues_elabJunkCheck_spec__4(v___x_1119_, v___y_1062_, v___y_1063_, v___y_1064_, v___y_1065_, v___y_1066_, v___y_1067_);
return v___x_1120_;
}
}
}
}
}
}
}
else
{
lean_object* v_a_1128_; lean_object* v___x_1130_; uint8_t v_isShared_1131_; uint8_t v_isSharedCheck_1135_; 
lean_del_object(v___x_1080_);
lean_del_object(v___x_1074_);
lean_dec_ref(v_ruleSet_1068_);
lean_dec_ref(v_names_1061_);
lean_del_object(v___x_1057_);
lean_del_object(v___x_1052_);
v_a_1128_ = lean_ctor_get(v___x_1087_, 0);
v_isSharedCheck_1135_ = !lean_is_exclusive(v___x_1087_);
if (v_isSharedCheck_1135_ == 0)
{
v___x_1130_ = v___x_1087_;
v_isShared_1131_ = v_isSharedCheck_1135_;
goto v_resetjp_1129_;
}
else
{
lean_inc(v_a_1128_);
lean_dec(v___x_1087_);
v___x_1130_ = lean_box(0);
v_isShared_1131_ = v_isSharedCheck_1135_;
goto v_resetjp_1129_;
}
v_resetjp_1129_:
{
lean_object* v___x_1133_; 
if (v_isShared_1131_ == 0)
{
v___x_1133_ = v___x_1130_;
goto v_reusejp_1132_;
}
else
{
lean_object* v_reuseFailAlloc_1134_; 
v_reuseFailAlloc_1134_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1134_, 0, v_a_1128_);
v___x_1133_ = v_reuseFailAlloc_1134_;
goto v_reusejp_1132_;
}
v_reusejp_1132_:
{
return v___x_1133_;
}
}
}
}
else
{
lean_object* v_rules_1136_; lean_object* v___x_1138_; uint8_t v_isShared_1139_; uint8_t v_isSharedCheck_1166_; 
lean_dec(v_fst_1071_);
v_rules_1136_ = lean_ctor_get(v_ruleSet_1068_, 1);
v_isSharedCheck_1166_ = !lean_is_exclusive(v_ruleSet_1068_);
if (v_isSharedCheck_1166_ == 0)
{
lean_object* v_unused_1167_; 
v_unused_1167_ = lean_ctor_get(v_ruleSet_1068_, 0);
lean_dec(v_unused_1167_);
v___x_1138_ = v_ruleSet_1068_;
v_isShared_1139_ = v_isSharedCheck_1166_;
goto v_resetjp_1137_;
}
else
{
lean_inc(v_rules_1136_);
lean_dec(v_ruleSet_1068_);
v___x_1138_ = lean_box(0);
v_isShared_1139_ = v_isSharedCheck_1166_;
goto v_resetjp_1137_;
}
v_resetjp_1137_:
{
lean_object* v___x_1140_; lean_object* v___x_1141_; lean_object* v___x_1142_; lean_object* v___x_1144_; 
v___x_1140_ = lean_obj_once(&lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__8, &lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__8_once, _init_lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__8);
v___x_1141_ = lean_array_get_size(v_names_1061_);
lean_dec_ref(v_names_1061_);
v___x_1142_ = l_Nat_reprFast(v___x_1141_);
if (v_isShared_1081_ == 0)
{
lean_ctor_set_tag(v___x_1080_, 3);
lean_ctor_set(v___x_1080_, 0, v___x_1142_);
v___x_1144_ = v___x_1080_;
goto v_reusejp_1143_;
}
else
{
lean_object* v_reuseFailAlloc_1165_; 
v_reuseFailAlloc_1165_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1165_, 0, v___x_1142_);
v___x_1144_ = v_reuseFailAlloc_1165_;
goto v_reusejp_1143_;
}
v_reusejp_1143_:
{
lean_object* v___x_1145_; lean_object* v___x_1147_; 
v___x_1145_ = l_Lean_MessageData_ofFormat(v___x_1144_);
if (v_isShared_1139_ == 0)
{
lean_ctor_set_tag(v___x_1138_, 7);
lean_ctor_set(v___x_1138_, 1, v___x_1145_);
lean_ctor_set(v___x_1138_, 0, v___x_1140_);
v___x_1147_ = v___x_1138_;
goto v_reusejp_1146_;
}
else
{
lean_object* v_reuseFailAlloc_1164_; 
v_reuseFailAlloc_1164_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1164_, 0, v___x_1140_);
lean_ctor_set(v_reuseFailAlloc_1164_, 1, v___x_1145_);
v___x_1147_ = v_reuseFailAlloc_1164_;
goto v_reusejp_1146_;
}
v_reusejp_1146_:
{
lean_object* v___x_1148_; lean_object* v___x_1150_; 
v___x_1148_ = lean_obj_once(&lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__10, &lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__10_once, _init_lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__10);
if (v_isShared_1075_ == 0)
{
lean_ctor_set_tag(v___x_1074_, 7);
lean_ctor_set(v___x_1074_, 1, v___x_1148_);
lean_ctor_set(v___x_1074_, 0, v___x_1147_);
v___x_1150_ = v___x_1074_;
goto v_reusejp_1149_;
}
else
{
lean_object* v_reuseFailAlloc_1163_; 
v_reuseFailAlloc_1163_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1163_, 0, v___x_1147_);
lean_ctor_set(v_reuseFailAlloc_1163_, 1, v___x_1148_);
v___x_1150_ = v_reuseFailAlloc_1163_;
goto v_reusejp_1149_;
}
v_reusejp_1149_:
{
lean_object* v___x_1151_; lean_object* v___x_1152_; lean_object* v___x_1153_; lean_object* v___x_1154_; lean_object* v___x_1156_; 
v___x_1151_ = lean_array_get_size(v_rules_1136_);
lean_dec_ref(v_rules_1136_);
v___x_1152_ = l_Nat_reprFast(v___x_1151_);
v___x_1153_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_1153_, 0, v___x_1152_);
v___x_1154_ = l_Lean_MessageData_ofFormat(v___x_1153_);
if (v_isShared_1058_ == 0)
{
lean_ctor_set_tag(v___x_1057_, 7);
lean_ctor_set(v___x_1057_, 1, v___x_1154_);
lean_ctor_set(v___x_1057_, 0, v___x_1150_);
v___x_1156_ = v___x_1057_;
goto v_reusejp_1155_;
}
else
{
lean_object* v_reuseFailAlloc_1162_; 
v_reuseFailAlloc_1162_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1162_, 0, v___x_1150_);
lean_ctor_set(v_reuseFailAlloc_1162_, 1, v___x_1154_);
v___x_1156_ = v_reuseFailAlloc_1162_;
goto v_reusejp_1155_;
}
v_reusejp_1155_:
{
lean_object* v___x_1157_; lean_object* v___x_1159_; 
v___x_1157_ = lean_obj_once(&lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__6, &lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__6_once, _init_lp_JunkValues_JunkValues_elabJunkCheck___lam__1___closed__6);
if (v_isShared_1053_ == 0)
{
lean_ctor_set_tag(v___x_1052_, 7);
lean_ctor_set(v___x_1052_, 1, v___x_1157_);
lean_ctor_set(v___x_1052_, 0, v___x_1156_);
v___x_1159_ = v___x_1052_;
goto v_reusejp_1158_;
}
else
{
lean_object* v_reuseFailAlloc_1161_; 
v_reuseFailAlloc_1161_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1161_, 0, v___x_1156_);
lean_ctor_set(v_reuseFailAlloc_1161_, 1, v___x_1157_);
v___x_1159_ = v_reuseFailAlloc_1161_;
goto v_reusejp_1158_;
}
v_reusejp_1158_:
{
lean_object* v___x_1160_; 
v___x_1160_ = lp_JunkValues_Lean_logInfo___at___00JunkValues_elabJunkCheck_spec__4(v___x_1159_, v___y_1062_, v___y_1063_, v___y_1064_, v___y_1065_, v___y_1066_, v___y_1067_);
return v___x_1160_;
}
}
}
}
}
}
}
}
}
else
{
lean_del_object(v___x_1074_);
lean_dec(v_fst_1071_);
lean_dec_ref(v_ruleSet_1068_);
lean_dec_ref(v_names_1061_);
lean_del_object(v___x_1057_);
lean_del_object(v___x_1052_);
return v___x_1078_;
}
}
}
else
{
lean_object* v_a_1171_; lean_object* v___x_1173_; uint8_t v_isShared_1174_; uint8_t v_isSharedCheck_1178_; 
lean_dec_ref(v_ruleSet_1068_);
lean_dec_ref(v_names_1061_);
lean_del_object(v___x_1057_);
lean_del_object(v___x_1052_);
v_a_1171_ = lean_ctor_get(v___x_1069_, 0);
v_isSharedCheck_1178_ = !lean_is_exclusive(v___x_1069_);
if (v_isSharedCheck_1178_ == 0)
{
v___x_1173_ = v___x_1069_;
v_isShared_1174_ = v_isSharedCheck_1178_;
goto v_resetjp_1172_;
}
else
{
lean_inc(v_a_1171_);
lean_dec(v___x_1069_);
v___x_1173_ = lean_box(0);
v_isShared_1174_ = v_isSharedCheck_1178_;
goto v_resetjp_1172_;
}
v_resetjp_1172_:
{
lean_object* v___x_1176_; 
if (v_isShared_1174_ == 0)
{
v___x_1176_ = v___x_1173_;
goto v_reusejp_1175_;
}
else
{
lean_object* v_reuseFailAlloc_1177_; 
v_reuseFailAlloc_1177_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1177_, 0, v_a_1171_);
v___x_1176_ = v_reuseFailAlloc_1177_;
goto v_reusejp_1175_;
}
v_reusejp_1175_:
{
return v___x_1176_;
}
}
}
}
v___jp_1179_:
{
lean_object* v___x_1190_; 
v___x_1190_ = lp_JunkValues___private_Init_Data_Array_QSort_Basic_0__Array_qsort_sort___at___00JunkValues_elabJunkCheck_spec__7___redArg(v___y_1184_, v___y_1181_, v___y_1187_, v___y_1189_);
lean_dec(v___y_1189_);
lean_dec(v___y_1184_);
v_names_1061_ = v___x_1190_;
v___y_1062_ = v___y_1186_;
v___y_1063_ = v___y_1188_;
v___y_1064_ = v___y_1185_;
v___y_1065_ = v___y_1183_;
v___y_1066_ = v___y_1180_;
v___y_1067_ = v___y_1182_;
goto v___jp_1060_;
}
v___jp_1191_:
{
uint8_t v___x_1202_; 
v___x_1202_ = lean_nat_dec_le(v___y_1201_, v___y_1199_);
if (v___x_1202_ == 0)
{
lean_dec(v___y_1199_);
lean_inc(v___y_1201_);
v___y_1180_ = v___y_1193_;
v___y_1181_ = v___y_1192_;
v___y_1182_ = v___y_1194_;
v___y_1183_ = v___y_1196_;
v___y_1184_ = v___y_1195_;
v___y_1185_ = v___y_1198_;
v___y_1186_ = v___y_1197_;
v___y_1187_ = v___y_1201_;
v___y_1188_ = v___y_1200_;
v___y_1189_ = v___y_1201_;
goto v___jp_1179_;
}
else
{
v___y_1180_ = v___y_1193_;
v___y_1181_ = v___y_1192_;
v___y_1182_ = v___y_1194_;
v___y_1183_ = v___y_1196_;
v___y_1184_ = v___y_1195_;
v___y_1185_ = v___y_1198_;
v___y_1186_ = v___y_1197_;
v___y_1187_ = v___y_1201_;
v___y_1188_ = v___y_1200_;
v___y_1189_ = v___y_1199_;
goto v___jp_1179_;
}
}
v___jp_1203_:
{
lean_object* v___x_1211_; lean_object* v___x_1212_; uint8_t v___x_1213_; 
v___x_1211_ = lean_array_get_size(v___y_1204_);
v___x_1212_ = lean_unsigned_to_nat(0u);
v___x_1213_ = lean_nat_dec_eq(v___x_1211_, v___x_1212_);
if (v___x_1213_ == 0)
{
lean_object* v___x_1214_; uint8_t v___x_1215_; 
v___x_1214_ = lean_nat_sub(v___x_1211_, v___x_1039_);
v___x_1215_ = lean_nat_dec_le(v___x_1212_, v___x_1214_);
if (v___x_1215_ == 0)
{
lean_inc(v___x_1214_);
v___y_1192_ = v___y_1204_;
v___y_1193_ = v___y_1209_;
v___y_1194_ = v___y_1210_;
v___y_1195_ = v___x_1211_;
v___y_1196_ = v___y_1208_;
v___y_1197_ = v___y_1205_;
v___y_1198_ = v___y_1207_;
v___y_1199_ = v___x_1214_;
v___y_1200_ = v___y_1206_;
v___y_1201_ = v___x_1214_;
goto v___jp_1191_;
}
else
{
v___y_1192_ = v___y_1204_;
v___y_1193_ = v___y_1209_;
v___y_1194_ = v___y_1210_;
v___y_1195_ = v___x_1211_;
v___y_1196_ = v___y_1208_;
v___y_1197_ = v___y_1205_;
v___y_1198_ = v___y_1207_;
v___y_1199_ = v___x_1214_;
v___y_1200_ = v___y_1206_;
v___y_1201_ = v___x_1212_;
goto v___jp_1191_;
}
}
else
{
v_names_1061_ = v___y_1204_;
v___y_1062_ = v___y_1205_;
v___y_1063_ = v___y_1206_;
v___y_1064_ = v___y_1207_;
v___y_1065_ = v___y_1208_;
v___y_1066_ = v___y_1209_;
v___y_1067_ = v___y_1210_;
goto v___jp_1060_;
}
}
}
}
}
else
{
lean_object* v_a_1266_; lean_object* v___x_1268_; uint8_t v_isShared_1269_; uint8_t v_isSharedCheck_1273_; 
lean_dec(v___y_1038_);
v_a_1266_ = lean_ctor_get(v___x_1047_, 0);
v_isSharedCheck_1273_ = !lean_is_exclusive(v___x_1047_);
if (v_isSharedCheck_1273_ == 0)
{
v___x_1268_ = v___x_1047_;
v_isShared_1269_ = v_isSharedCheck_1273_;
goto v_resetjp_1267_;
}
else
{
lean_inc(v_a_1266_);
lean_dec(v___x_1047_);
v___x_1268_ = lean_box(0);
v_isShared_1269_ = v_isSharedCheck_1273_;
goto v_resetjp_1267_;
}
v_resetjp_1267_:
{
lean_object* v___x_1271_; 
if (v_isShared_1269_ == 0)
{
v___x_1271_ = v___x_1268_;
goto v_reusejp_1270_;
}
else
{
lean_object* v_reuseFailAlloc_1272_; 
v_reuseFailAlloc_1272_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1272_, 0, v_a_1266_);
v___x_1271_ = v_reuseFailAlloc_1272_;
goto v_reusejp_1270_;
}
v_reusejp_1270_:
{
return v___x_1271_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_elabJunkCheck___lam__1___boxed(lean_object* v_opts_1274_, lean_object* v___y_1275_, lean_object* v___x_1276_, lean_object* v___y_1277_, lean_object* v___y_1278_, lean_object* v___y_1279_, lean_object* v___y_1280_, lean_object* v___y_1281_, lean_object* v___y_1282_, lean_object* v___y_1283_){
_start:
{
lean_object* v_res_1284_; 
v_res_1284_ = lp_JunkValues_JunkValues_elabJunkCheck___lam__1(v_opts_1274_, v___y_1275_, v___x_1276_, v___y_1277_, v___y_1278_, v___y_1279_, v___y_1280_, v___y_1281_, v___y_1282_);
lean_dec(v___y_1282_);
lean_dec_ref(v___y_1281_);
lean_dec(v___y_1280_);
lean_dec_ref(v___y_1279_);
lean_dec(v___y_1278_);
lean_dec_ref(v___y_1277_);
lean_dec(v___x_1276_);
return v_res_1284_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_elabJunkCheck(lean_object* v_stx_1285_, lean_object* v_a_1286_, lean_object* v_a_1287_){
_start:
{
lean_object* v___x_1289_; lean_object* v_scopes_1290_; lean_object* v___x_1291_; lean_object* v___x_1292_; lean_object* v_opts_1293_; lean_object* v___x_1294_; lean_object* v___y_1296_; lean_object* v___x_1299_; lean_object* v___x_1300_; 
v___x_1289_ = lean_st_ref_get(v_a_1287_);
v_scopes_1290_ = lean_ctor_get(v___x_1289_, 2);
lean_inc(v_scopes_1290_);
lean_dec(v___x_1289_);
v___x_1291_ = l_Lean_Elab_Command_instInhabitedScope_default;
v___x_1292_ = l_List_head_x21___redArg(v___x_1291_, v_scopes_1290_);
lean_dec(v_scopes_1290_);
v_opts_1293_ = lean_ctor_get(v___x_1292_, 1);
lean_inc_ref(v_opts_1293_);
lean_dec(v___x_1292_);
v___x_1294_ = lean_unsigned_to_nat(1u);
v___x_1299_ = l_Lean_Syntax_getArg(v_stx_1285_, v___x_1294_);
v___x_1300_ = l_Lean_Syntax_getOptional_x3f(v___x_1299_);
lean_dec(v___x_1299_);
if (lean_obj_tag(v___x_1300_) == 0)
{
lean_object* v___x_1301_; 
v___x_1301_ = lean_box(0);
v___y_1296_ = v___x_1301_;
goto v___jp_1295_;
}
else
{
lean_object* v_val_1302_; lean_object* v___x_1304_; uint8_t v_isShared_1305_; uint8_t v_isSharedCheck_1310_; 
v_val_1302_ = lean_ctor_get(v___x_1300_, 0);
v_isSharedCheck_1310_ = !lean_is_exclusive(v___x_1300_);
if (v_isSharedCheck_1310_ == 0)
{
v___x_1304_ = v___x_1300_;
v_isShared_1305_ = v_isSharedCheck_1310_;
goto v_resetjp_1303_;
}
else
{
lean_inc(v_val_1302_);
lean_dec(v___x_1300_);
v___x_1304_ = lean_box(0);
v_isShared_1305_ = v_isSharedCheck_1310_;
goto v_resetjp_1303_;
}
v_resetjp_1303_:
{
lean_object* v___x_1306_; lean_object* v___x_1308_; 
v___x_1306_ = l_Lean_Syntax_getId(v_val_1302_);
lean_dec(v_val_1302_);
if (v_isShared_1305_ == 0)
{
lean_ctor_set(v___x_1304_, 0, v___x_1306_);
v___x_1308_ = v___x_1304_;
goto v_reusejp_1307_;
}
else
{
lean_object* v_reuseFailAlloc_1309_; 
v_reuseFailAlloc_1309_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1309_, 0, v___x_1306_);
v___x_1308_ = v_reuseFailAlloc_1309_;
goto v_reusejp_1307_;
}
v_reusejp_1307_:
{
v___y_1296_ = v___x_1308_;
goto v___jp_1295_;
}
}
}
v___jp_1295_:
{
lean_object* v___f_1297_; lean_object* v___x_1298_; 
v___f_1297_ = lean_alloc_closure((void*)(lp_JunkValues_JunkValues_elabJunkCheck___lam__1___boxed), 10, 3);
lean_closure_set(v___f_1297_, 0, v_opts_1293_);
lean_closure_set(v___f_1297_, 1, v___y_1296_);
lean_closure_set(v___f_1297_, 2, v___x_1294_);
v___x_1298_ = l_Lean_Elab_Command_liftTermElabM___redArg(v___f_1297_, v_a_1286_, v_a_1287_);
return v___x_1298_;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_elabJunkCheck___boxed(lean_object* v_stx_1311_, lean_object* v_a_1312_, lean_object* v_a_1313_, lean_object* v_a_1314_){
_start:
{
lean_object* v_res_1315_; 
v_res_1315_ = lp_JunkValues_JunkValues_elabJunkCheck(v_stx_1311_, v_a_1312_, v_a_1313_);
lean_dec(v_a_1313_);
lean_dec_ref(v_a_1312_);
lean_dec(v_stx_1311_);
return v_res_1315_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__0(lean_object* v_as_1316_, size_t v_sz_1317_, size_t v_i_1318_, lean_object* v_b_1319_, lean_object* v___y_1320_, lean_object* v___y_1321_, lean_object* v___y_1322_, lean_object* v___y_1323_, lean_object* v___y_1324_, lean_object* v___y_1325_){
_start:
{
lean_object* v___x_1327_; 
v___x_1327_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__0___redArg(v_as_1316_, v_sz_1317_, v_i_1318_, v_b_1319_);
return v___x_1327_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__0___boxed(lean_object* v_as_1328_, lean_object* v_sz_1329_, lean_object* v_i_1330_, lean_object* v_b_1331_, lean_object* v___y_1332_, lean_object* v___y_1333_, lean_object* v___y_1334_, lean_object* v___y_1335_, lean_object* v___y_1336_, lean_object* v___y_1337_, lean_object* v___y_1338_){
_start:
{
size_t v_sz_boxed_1339_; size_t v_i_boxed_1340_; lean_object* v_res_1341_; 
v_sz_boxed_1339_ = lean_unbox_usize(v_sz_1329_);
lean_dec(v_sz_1329_);
v_i_boxed_1340_ = lean_unbox_usize(v_i_1330_);
lean_dec(v_i_1330_);
v_res_1341_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__0(v_as_1328_, v_sz_boxed_1339_, v_i_boxed_1340_, v_b_1331_, v___y_1332_, v___y_1333_, v___y_1334_, v___y_1335_, v___y_1336_, v___y_1337_);
lean_dec(v___y_1337_);
lean_dec_ref(v___y_1336_);
lean_dec(v___y_1335_);
lean_dec_ref(v___y_1334_);
lean_dec(v___y_1333_);
lean_dec_ref(v___y_1332_);
lean_dec_ref(v_as_1328_);
return v_res_1341_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6(lean_object* v_00_u03b1_1342_, lean_object* v_msg_1343_, lean_object* v___y_1344_, lean_object* v___y_1345_, lean_object* v___y_1346_, lean_object* v___y_1347_, lean_object* v___y_1348_, lean_object* v___y_1349_){
_start:
{
lean_object* v___x_1351_; 
v___x_1351_ = lp_JunkValues_Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6___redArg(v_msg_1343_, v___y_1344_, v___y_1345_, v___y_1346_, v___y_1347_, v___y_1348_, v___y_1349_);
return v___x_1351_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6___boxed(lean_object* v_00_u03b1_1352_, lean_object* v_msg_1353_, lean_object* v___y_1354_, lean_object* v___y_1355_, lean_object* v___y_1356_, lean_object* v___y_1357_, lean_object* v___y_1358_, lean_object* v___y_1359_, lean_object* v___y_1360_){
_start:
{
lean_object* v_res_1361_; 
v_res_1361_ = lp_JunkValues_Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6(v_00_u03b1_1352_, v_msg_1353_, v___y_1354_, v___y_1355_, v___y_1356_, v___y_1357_, v___y_1358_, v___y_1359_);
lean_dec(v___y_1359_);
lean_dec_ref(v___y_1358_);
lean_dec(v___y_1357_);
lean_dec_ref(v___y_1356_);
lean_dec(v___y_1355_);
lean_dec_ref(v___y_1354_);
return v_res_1361_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_QSort_Basic_0__Array_qsort_sort___at___00JunkValues_elabJunkCheck_spec__7(lean_object* v_n_1362_, lean_object* v_as_1363_, lean_object* v_lo_1364_, lean_object* v_hi_1365_, lean_object* v_w_1366_, lean_object* v_hlo_1367_, lean_object* v_hhi_1368_){
_start:
{
lean_object* v___x_1369_; 
v___x_1369_ = lp_JunkValues___private_Init_Data_Array_QSort_Basic_0__Array_qsort_sort___at___00JunkValues_elabJunkCheck_spec__7___redArg(v_n_1362_, v_as_1363_, v_lo_1364_, v_hi_1365_);
return v___x_1369_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_QSort_Basic_0__Array_qsort_sort___at___00JunkValues_elabJunkCheck_spec__7___boxed(lean_object* v_n_1370_, lean_object* v_as_1371_, lean_object* v_lo_1372_, lean_object* v_hi_1373_, lean_object* v_w_1374_, lean_object* v_hlo_1375_, lean_object* v_hhi_1376_){
_start:
{
lean_object* v_res_1377_; 
v_res_1377_ = lp_JunkValues___private_Init_Data_Array_QSort_Basic_0__Array_qsort_sort___at___00JunkValues_elabJunkCheck_spec__7(v_n_1370_, v_as_1371_, v_lo_1372_, v_hi_1373_, v_w_1374_, v_hlo_1375_, v_hhi_1376_);
lean_dec(v_hi_1373_);
lean_dec(v_n_1370_);
return v_res_1377_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8(lean_object* v_00_u03b2_1378_, lean_object* v_s_1379_, lean_object* v_f_1380_, lean_object* v___y_1381_, lean_object* v___y_1382_, lean_object* v___y_1383_, lean_object* v___y_1384_, lean_object* v___y_1385_, lean_object* v___y_1386_, lean_object* v___y_1387_){
_start:
{
lean_object* v___x_1389_; 
v___x_1389_ = lp_JunkValues_Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8___redArg(v_s_1379_, v_f_1380_, v___y_1381_, v___y_1382_, v___y_1383_, v___y_1384_, v___y_1385_, v___y_1386_, v___y_1387_);
return v___x_1389_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8___boxed(lean_object* v_00_u03b2_1390_, lean_object* v_s_1391_, lean_object* v_f_1392_, lean_object* v___y_1393_, lean_object* v___y_1394_, lean_object* v___y_1395_, lean_object* v___y_1396_, lean_object* v___y_1397_, lean_object* v___y_1398_, lean_object* v___y_1399_, lean_object* v___y_1400_){
_start:
{
lean_object* v_res_1401_; 
v_res_1401_ = lp_JunkValues_Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8(v_00_u03b2_1390_, v_s_1391_, v_f_1392_, v___y_1393_, v___y_1394_, v___y_1395_, v___y_1396_, v___y_1397_, v___y_1398_, v___y_1399_);
lean_dec(v___y_1399_);
lean_dec_ref(v___y_1398_);
lean_dec(v___y_1397_);
lean_dec_ref(v___y_1396_);
lean_dec(v___y_1395_);
lean_dec_ref(v___y_1394_);
return v_res_1401_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8(lean_object* v_msgData_1402_, lean_object* v_macroStack_1403_, lean_object* v___y_1404_, lean_object* v___y_1405_, lean_object* v___y_1406_, lean_object* v___y_1407_, lean_object* v___y_1408_, lean_object* v___y_1409_){
_start:
{
lean_object* v___x_1411_; 
v___x_1411_ = lp_JunkValues_Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8___redArg(v_msgData_1402_, v_macroStack_1403_, v___y_1408_);
return v___x_1411_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8___boxed(lean_object* v_msgData_1412_, lean_object* v_macroStack_1413_, lean_object* v___y_1414_, lean_object* v___y_1415_, lean_object* v___y_1416_, lean_object* v___y_1417_, lean_object* v___y_1418_, lean_object* v___y_1419_, lean_object* v___y_1420_){
_start:
{
lean_object* v_res_1421_; 
v_res_1421_ = lp_JunkValues_Lean_Elab_addMacroStack___at___00Lean_throwError___at___00JunkValues_elabJunkCheck_spec__6_spec__8(v_msgData_1412_, v_macroStack_1413_, v___y_1414_, v___y_1415_, v___y_1416_, v___y_1417_, v___y_1418_, v___y_1419_);
lean_dec(v___y_1419_);
lean_dec_ref(v___y_1418_);
lean_dec(v___y_1417_);
lean_dec_ref(v___y_1416_);
lean_dec(v___y_1415_);
lean_dec_ref(v___y_1414_);
return v_res_1421_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_QSort_Basic_0__Array_qpartition_loop___at___00__private_Init_Data_Array_QSort_Basic_0__Array_qsort_sort___at___00JunkValues_elabJunkCheck_spec__7_spec__10(lean_object* v_n_1422_, lean_object* v_lo_1423_, lean_object* v_hi_1424_, lean_object* v_hhi_1425_, lean_object* v_pivot_1426_, lean_object* v_as_1427_, lean_object* v_i_1428_, lean_object* v_k_1429_, lean_object* v_ilo_1430_, lean_object* v_ik_1431_, lean_object* v_w_1432_){
_start:
{
lean_object* v___x_1433_; 
v___x_1433_ = lp_JunkValues___private_Init_Data_Array_QSort_Basic_0__Array_qpartition_loop___at___00__private_Init_Data_Array_QSort_Basic_0__Array_qsort_sort___at___00JunkValues_elabJunkCheck_spec__7_spec__10___redArg(v_hi_1424_, v_pivot_1426_, v_as_1427_, v_i_1428_, v_k_1429_);
return v___x_1433_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_QSort_Basic_0__Array_qpartition_loop___at___00__private_Init_Data_Array_QSort_Basic_0__Array_qsort_sort___at___00JunkValues_elabJunkCheck_spec__7_spec__10___boxed(lean_object* v_n_1434_, lean_object* v_lo_1435_, lean_object* v_hi_1436_, lean_object* v_hhi_1437_, lean_object* v_pivot_1438_, lean_object* v_as_1439_, lean_object* v_i_1440_, lean_object* v_k_1441_, lean_object* v_ilo_1442_, lean_object* v_ik_1443_, lean_object* v_w_1444_){
_start:
{
lean_object* v_res_1445_; 
v_res_1445_ = lp_JunkValues___private_Init_Data_Array_QSort_Basic_0__Array_qpartition_loop___at___00__private_Init_Data_Array_QSort_Basic_0__Array_qsort_sort___at___00JunkValues_elabJunkCheck_spec__7_spec__10(v_n_1434_, v_lo_1435_, v_hi_1436_, v_hhi_1437_, v_pivot_1438_, v_as_1439_, v_i_1440_, v_k_1441_, v_ilo_1442_, v_ik_1443_, v_w_1444_);
lean_dec(v_hi_1436_);
lean_dec(v_lo_1435_);
lean_dec(v_n_1434_);
return v_res_1445_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__12(lean_object* v_00_u03b2_1446_, lean_object* v_f_1447_, lean_object* v_x_1448_, lean_object* v_x_1449_, lean_object* v___y_1450_, lean_object* v___y_1451_, lean_object* v___y_1452_, lean_object* v___y_1453_, lean_object* v___y_1454_, lean_object* v___y_1455_, lean_object* v___y_1456_){
_start:
{
lean_object* v___x_1458_; 
v___x_1458_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__12___redArg(v_f_1447_, v_x_1448_, v_x_1449_, v___y_1450_, v___y_1451_, v___y_1452_, v___y_1453_, v___y_1454_, v___y_1455_, v___y_1456_);
return v___x_1458_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__12___boxed(lean_object* v_00_u03b2_1459_, lean_object* v_f_1460_, lean_object* v_x_1461_, lean_object* v_x_1462_, lean_object* v___y_1463_, lean_object* v___y_1464_, lean_object* v___y_1465_, lean_object* v___y_1466_, lean_object* v___y_1467_, lean_object* v___y_1468_, lean_object* v___y_1469_, lean_object* v___y_1470_){
_start:
{
lean_object* v_res_1471_; 
v_res_1471_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__12(v_00_u03b2_1459_, v_f_1460_, v_x_1461_, v_x_1462_, v___y_1463_, v___y_1464_, v___y_1465_, v___y_1466_, v___y_1467_, v___y_1468_, v___y_1469_);
lean_dec(v___y_1469_);
lean_dec_ref(v___y_1468_);
lean_dec(v___y_1467_);
lean_dec_ref(v___y_1466_);
lean_dec(v___y_1465_);
lean_dec_ref(v___y_1464_);
return v_res_1471_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13(lean_object* v_00_u03b2_1472_, lean_object* v_map_1473_, lean_object* v_f_1474_, lean_object* v___y_1475_, lean_object* v___y_1476_, lean_object* v___y_1477_, lean_object* v___y_1478_, lean_object* v___y_1479_, lean_object* v___y_1480_, lean_object* v___y_1481_){
_start:
{
lean_object* v___x_1483_; 
v___x_1483_ = lp_JunkValues_Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13___redArg(v_map_1473_, v_f_1474_, v___y_1475_, v___y_1476_, v___y_1477_, v___y_1478_, v___y_1479_, v___y_1480_, v___y_1481_);
return v___x_1483_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13___boxed(lean_object* v_00_u03b2_1484_, lean_object* v_map_1485_, lean_object* v_f_1486_, lean_object* v___y_1487_, lean_object* v___y_1488_, lean_object* v___y_1489_, lean_object* v___y_1490_, lean_object* v___y_1491_, lean_object* v___y_1492_, lean_object* v___y_1493_, lean_object* v___y_1494_){
_start:
{
lean_object* v_res_1495_; 
v_res_1495_ = lp_JunkValues_Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13(v_00_u03b2_1484_, v_map_1485_, v_f_1486_, v___y_1487_, v___y_1488_, v___y_1489_, v___y_1490_, v___y_1491_, v___y_1492_, v___y_1493_);
lean_dec(v___y_1493_);
lean_dec_ref(v___y_1492_);
lean_dec(v___y_1491_);
lean_dec_ref(v___y_1490_);
lean_dec(v___y_1489_);
lean_dec_ref(v___y_1488_);
return v_res_1495_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__14(lean_object* v_00_u03b2_1496_, lean_object* v_f_1497_, lean_object* v_as_1498_, size_t v_i_1499_, size_t v_stop_1500_, lean_object* v_b_1501_, lean_object* v___y_1502_, lean_object* v___y_1503_, lean_object* v___y_1504_, lean_object* v___y_1505_, lean_object* v___y_1506_, lean_object* v___y_1507_, lean_object* v___y_1508_){
_start:
{
lean_object* v___x_1510_; 
v___x_1510_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__14___redArg(v_f_1497_, v_as_1498_, v_i_1499_, v_stop_1500_, v_b_1501_, v___y_1502_, v___y_1503_, v___y_1504_, v___y_1505_, v___y_1506_, v___y_1507_, v___y_1508_);
return v___x_1510_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__14___boxed(lean_object* v_00_u03b2_1511_, lean_object* v_f_1512_, lean_object* v_as_1513_, lean_object* v_i_1514_, lean_object* v_stop_1515_, lean_object* v_b_1516_, lean_object* v___y_1517_, lean_object* v___y_1518_, lean_object* v___y_1519_, lean_object* v___y_1520_, lean_object* v___y_1521_, lean_object* v___y_1522_, lean_object* v___y_1523_, lean_object* v___y_1524_){
_start:
{
size_t v_i_boxed_1525_; size_t v_stop_boxed_1526_; lean_object* v_res_1527_; 
v_i_boxed_1525_ = lean_unbox_usize(v_i_1514_);
lean_dec(v_i_1514_);
v_stop_boxed_1526_ = lean_unbox_usize(v_stop_1515_);
lean_dec(v_stop_1515_);
v_res_1527_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__14(v_00_u03b2_1511_, v_f_1512_, v_as_1513_, v_i_boxed_1525_, v_stop_boxed_1526_, v_b_1516_, v___y_1517_, v___y_1518_, v___y_1519_, v___y_1520_, v___y_1521_, v___y_1522_, v___y_1523_);
lean_dec(v___y_1523_);
lean_dec_ref(v___y_1522_);
lean_dec(v___y_1521_);
lean_dec_ref(v___y_1520_);
lean_dec(v___y_1519_);
lean_dec_ref(v___y_1518_);
lean_dec_ref(v_as_1513_);
return v_res_1527_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_logAt___at___00Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1_spec__2(lean_object* v_ref_1528_, lean_object* v_msgData_1529_, uint8_t v_severity_1530_, uint8_t v_isSilent_1531_, lean_object* v___y_1532_, lean_object* v___y_1533_, lean_object* v___y_1534_, lean_object* v___y_1535_, lean_object* v___y_1536_, lean_object* v___y_1537_){
_start:
{
lean_object* v___x_1539_; 
v___x_1539_ = lp_JunkValues_Lean_logAt___at___00Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1_spec__2___redArg(v_ref_1528_, v_msgData_1529_, v_severity_1530_, v_isSilent_1531_, v___y_1534_, v___y_1535_, v___y_1536_, v___y_1537_);
return v___x_1539_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_logAt___at___00Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1_spec__2___boxed(lean_object* v_ref_1540_, lean_object* v_msgData_1541_, lean_object* v_severity_1542_, lean_object* v_isSilent_1543_, lean_object* v___y_1544_, lean_object* v___y_1545_, lean_object* v___y_1546_, lean_object* v___y_1547_, lean_object* v___y_1548_, lean_object* v___y_1549_, lean_object* v___y_1550_){
_start:
{
uint8_t v_severity_boxed_1551_; uint8_t v_isSilent_boxed_1552_; lean_object* v_res_1553_; 
v_severity_boxed_1551_ = lean_unbox(v_severity_1542_);
v_isSilent_boxed_1552_ = lean_unbox(v_isSilent_1543_);
v_res_1553_ = lp_JunkValues_Lean_logAt___at___00Lean_log___at___00Lean_logWarning___at___00JunkValues_elabJunkCheck_spec__1_spec__1_spec__2(v_ref_1540_, v_msgData_1541_, v_severity_boxed_1551_, v_isSilent_boxed_1552_, v___y_1544_, v___y_1545_, v___y_1546_, v___y_1547_, v___y_1548_, v___y_1549_);
lean_dec(v___y_1549_);
lean_dec_ref(v___y_1548_);
lean_dec(v___y_1547_);
lean_dec_ref(v___y_1546_);
lean_dec(v___y_1545_);
lean_dec_ref(v___y_1544_);
lean_dec(v_ref_1540_);
return v_res_1553_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13_spec__17___redArg(lean_object* v_map_1554_, lean_object* v_f_1555_, lean_object* v_init_1556_, lean_object* v___y_1557_, lean_object* v___y_1558_, lean_object* v___y_1559_, lean_object* v___y_1560_, lean_object* v___y_1561_, lean_object* v___y_1562_, lean_object* v___y_1563_){
_start:
{
lean_object* v___x_1565_; 
v___x_1565_ = lp_JunkValues_Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13_spec__17_spec__18___redArg(v_f_1555_, v_map_1554_, v_init_1556_, v___y_1557_, v___y_1558_, v___y_1559_, v___y_1560_, v___y_1561_, v___y_1562_, v___y_1563_);
return v___x_1565_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13_spec__17___redArg___boxed(lean_object* v_map_1566_, lean_object* v_f_1567_, lean_object* v_init_1568_, lean_object* v___y_1569_, lean_object* v___y_1570_, lean_object* v___y_1571_, lean_object* v___y_1572_, lean_object* v___y_1573_, lean_object* v___y_1574_, lean_object* v___y_1575_, lean_object* v___y_1576_){
_start:
{
lean_object* v_res_1577_; 
v_res_1577_ = lp_JunkValues_Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13_spec__17___redArg(v_map_1566_, v_f_1567_, v_init_1568_, v___y_1569_, v___y_1570_, v___y_1571_, v___y_1572_, v___y_1573_, v___y_1574_, v___y_1575_);
lean_dec(v___y_1575_);
lean_dec_ref(v___y_1574_);
lean_dec(v___y_1573_);
lean_dec_ref(v___y_1572_);
lean_dec(v___y_1571_);
lean_dec_ref(v___y_1570_);
return v_res_1577_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13_spec__17(lean_object* v_00_u03c3_1578_, lean_object* v_00_u03b2_1579_, lean_object* v_map_1580_, lean_object* v_f_1581_, lean_object* v_init_1582_, lean_object* v___y_1583_, lean_object* v___y_1584_, lean_object* v___y_1585_, lean_object* v___y_1586_, lean_object* v___y_1587_, lean_object* v___y_1588_, lean_object* v___y_1589_){
_start:
{
lean_object* v___x_1591_; 
v___x_1591_ = lp_JunkValues_Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13_spec__17_spec__18___redArg(v_f_1581_, v_map_1580_, v_init_1582_, v___y_1583_, v___y_1584_, v___y_1585_, v___y_1586_, v___y_1587_, v___y_1588_, v___y_1589_);
return v___x_1591_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13_spec__17___boxed(lean_object* v_00_u03c3_1592_, lean_object* v_00_u03b2_1593_, lean_object* v_map_1594_, lean_object* v_f_1595_, lean_object* v_init_1596_, lean_object* v___y_1597_, lean_object* v___y_1598_, lean_object* v___y_1599_, lean_object* v___y_1600_, lean_object* v___y_1601_, lean_object* v___y_1602_, lean_object* v___y_1603_, lean_object* v___y_1604_){
_start:
{
lean_object* v_res_1605_; 
v_res_1605_ = lp_JunkValues_Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13_spec__17(v_00_u03c3_1592_, v_00_u03b2_1593_, v_map_1594_, v_f_1595_, v_init_1596_, v___y_1597_, v___y_1598_, v___y_1599_, v___y_1600_, v___y_1601_, v___y_1602_, v___y_1603_);
lean_dec(v___y_1603_);
lean_dec_ref(v___y_1602_);
lean_dec(v___y_1601_);
lean_dec_ref(v___y_1600_);
lean_dec(v___y_1599_);
lean_dec_ref(v___y_1598_);
return v_res_1605_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13_spec__17_spec__18(lean_object* v_00_u03c3_1606_, lean_object* v_00_u03b1_1607_, lean_object* v_00_u03b2_1608_, lean_object* v_f_1609_, lean_object* v_x_1610_, lean_object* v_x_1611_, lean_object* v___y_1612_, lean_object* v___y_1613_, lean_object* v___y_1614_, lean_object* v___y_1615_, lean_object* v___y_1616_, lean_object* v___y_1617_, lean_object* v___y_1618_){
_start:
{
lean_object* v___x_1620_; 
v___x_1620_ = lp_JunkValues_Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13_spec__17_spec__18___redArg(v_f_1609_, v_x_1610_, v_x_1611_, v___y_1612_, v___y_1613_, v___y_1614_, v___y_1615_, v___y_1616_, v___y_1617_, v___y_1618_);
return v___x_1620_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13_spec__17_spec__18___boxed(lean_object* v_00_u03c3_1621_, lean_object* v_00_u03b1_1622_, lean_object* v_00_u03b2_1623_, lean_object* v_f_1624_, lean_object* v_x_1625_, lean_object* v_x_1626_, lean_object* v___y_1627_, lean_object* v___y_1628_, lean_object* v___y_1629_, lean_object* v___y_1630_, lean_object* v___y_1631_, lean_object* v___y_1632_, lean_object* v___y_1633_, lean_object* v___y_1634_){
_start:
{
lean_object* v_res_1635_; 
v_res_1635_ = lp_JunkValues_Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13_spec__17_spec__18(v_00_u03c3_1621_, v_00_u03b1_1622_, v_00_u03b2_1623_, v_f_1624_, v_x_1625_, v_x_1626_, v___y_1627_, v___y_1628_, v___y_1629_, v___y_1630_, v___y_1631_, v___y_1632_, v___y_1633_);
lean_dec(v___y_1633_);
lean_dec_ref(v___y_1632_);
lean_dec(v___y_1631_);
lean_dec_ref(v___y_1630_);
lean_dec(v___y_1629_);
lean_dec_ref(v___y_1628_);
return v_res_1635_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13_spec__17_spec__18_spec__20(lean_object* v_00_u03b1_1636_, lean_object* v_00_u03b2_1637_, lean_object* v_00_u03c3_1638_, lean_object* v_f_1639_, lean_object* v_as_1640_, size_t v_i_1641_, size_t v_stop_1642_, lean_object* v_b_1643_, lean_object* v___y_1644_, lean_object* v___y_1645_, lean_object* v___y_1646_, lean_object* v___y_1647_, lean_object* v___y_1648_, lean_object* v___y_1649_, lean_object* v___y_1650_){
_start:
{
lean_object* v___x_1652_; 
v___x_1652_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13_spec__17_spec__18_spec__20___redArg(v_f_1639_, v_as_1640_, v_i_1641_, v_stop_1642_, v_b_1643_, v___y_1644_, v___y_1645_, v___y_1646_, v___y_1647_, v___y_1648_, v___y_1649_, v___y_1650_);
return v___x_1652_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13_spec__17_spec__18_spec__20___boxed(lean_object* v_00_u03b1_1653_, lean_object* v_00_u03b2_1654_, lean_object* v_00_u03c3_1655_, lean_object* v_f_1656_, lean_object* v_as_1657_, lean_object* v_i_1658_, lean_object* v_stop_1659_, lean_object* v_b_1660_, lean_object* v___y_1661_, lean_object* v___y_1662_, lean_object* v___y_1663_, lean_object* v___y_1664_, lean_object* v___y_1665_, lean_object* v___y_1666_, lean_object* v___y_1667_, lean_object* v___y_1668_){
_start:
{
size_t v_i_boxed_1669_; size_t v_stop_boxed_1670_; lean_object* v_res_1671_; 
v_i_boxed_1669_ = lean_unbox_usize(v_i_1658_);
lean_dec(v_i_1658_);
v_stop_boxed_1670_ = lean_unbox_usize(v_stop_1659_);
lean_dec(v_stop_1659_);
v_res_1671_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13_spec__17_spec__18_spec__20(v_00_u03b1_1653_, v_00_u03b2_1654_, v_00_u03c3_1655_, v_f_1656_, v_as_1657_, v_i_boxed_1669_, v_stop_boxed_1670_, v_b_1660_, v___y_1661_, v___y_1662_, v___y_1663_, v___y_1664_, v___y_1665_, v___y_1666_, v___y_1667_);
lean_dec(v___y_1667_);
lean_dec_ref(v___y_1666_);
lean_dec(v___y_1665_);
lean_dec_ref(v___y_1664_);
lean_dec(v___y_1663_);
lean_dec_ref(v___y_1662_);
lean_dec_ref(v_as_1657_);
return v_res_1671_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Lean_Data_PersistentHashMap_0__Lean_PersistentHashMap_foldlMAux_traverse___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13_spec__17_spec__18_spec__21(lean_object* v_00_u03c3_1672_, lean_object* v_00_u03b1_1673_, lean_object* v_00_u03b2_1674_, lean_object* v_f_1675_, lean_object* v_keys_1676_, lean_object* v_vals_1677_, lean_object* v_heq_1678_, lean_object* v_i_1679_, lean_object* v_acc_1680_, lean_object* v___y_1681_, lean_object* v___y_1682_, lean_object* v___y_1683_, lean_object* v___y_1684_, lean_object* v___y_1685_, lean_object* v___y_1686_, lean_object* v___y_1687_){
_start:
{
lean_object* v___x_1689_; 
v___x_1689_ = lp_JunkValues___private_Lean_Data_PersistentHashMap_0__Lean_PersistentHashMap_foldlMAux_traverse___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13_spec__17_spec__18_spec__21___redArg(v_f_1675_, v_keys_1676_, v_vals_1677_, v_i_1679_, v_acc_1680_, v___y_1681_, v___y_1682_, v___y_1683_, v___y_1684_, v___y_1685_, v___y_1686_, v___y_1687_);
return v___x_1689_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Lean_Data_PersistentHashMap_0__Lean_PersistentHashMap_foldlMAux_traverse___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13_spec__17_spec__18_spec__21___boxed(lean_object** _args){
lean_object* v_00_u03c3_1690_ = _args[0];
lean_object* v_00_u03b1_1691_ = _args[1];
lean_object* v_00_u03b2_1692_ = _args[2];
lean_object* v_f_1693_ = _args[3];
lean_object* v_keys_1694_ = _args[4];
lean_object* v_vals_1695_ = _args[5];
lean_object* v_heq_1696_ = _args[6];
lean_object* v_i_1697_ = _args[7];
lean_object* v_acc_1698_ = _args[8];
lean_object* v___y_1699_ = _args[9];
lean_object* v___y_1700_ = _args[10];
lean_object* v___y_1701_ = _args[11];
lean_object* v___y_1702_ = _args[12];
lean_object* v___y_1703_ = _args[13];
lean_object* v___y_1704_ = _args[14];
lean_object* v___y_1705_ = _args[15];
lean_object* v___y_1706_ = _args[16];
_start:
{
lean_object* v_res_1707_; 
v_res_1707_ = lp_JunkValues___private_Lean_Data_PersistentHashMap_0__Lean_PersistentHashMap_foldlMAux_traverse___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forM___at___00Lean_SMap_forM___at___00JunkValues_elabJunkCheck_spec__8_spec__13_spec__17_spec__18_spec__21(v_00_u03c3_1690_, v_00_u03b1_1691_, v_00_u03b2_1692_, v_f_1693_, v_keys_1694_, v_vals_1695_, v_heq_1696_, v_i_1697_, v_acc_1698_, v___y_1699_, v___y_1700_, v___y_1701_, v___y_1702_, v___y_1703_, v___y_1704_, v___y_1705_);
lean_dec(v___y_1705_);
lean_dec_ref(v___y_1704_);
lean_dec(v___y_1703_);
lean_dec_ref(v___y_1702_);
lean_dec(v___y_1701_);
lean_dec_ref(v___y_1700_);
lean_dec_ref(v_vals_1695_);
lean_dec_ref(v_keys_1694_);
return v_res_1707_;
}
}
static lean_object* _init_lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkRules_spec__1___redArg___closed__1(void){
_start:
{
lean_object* v___x_1721_; lean_object* v___x_1722_; 
v___x_1721_ = ((lean_object*)(lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkRules_spec__1___redArg___closed__0));
v___x_1722_ = l_Lean_stringToMessageData(v___x_1721_);
return v___x_1722_;
}
}
static lean_object* _init_lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkRules_spec__1___redArg___closed__3(void){
_start:
{
lean_object* v___x_1724_; lean_object* v___x_1725_; 
v___x_1724_ = ((lean_object*)(lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkRules_spec__1___redArg___closed__2));
v___x_1725_ = l_Lean_stringToMessageData(v___x_1724_);
return v___x_1725_;
}
}
static lean_object* _init_lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkRules_spec__1___redArg___closed__5(void){
_start:
{
lean_object* v___x_1727_; lean_object* v___x_1728_; 
v___x_1727_ = ((lean_object*)(lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkRules_spec__1___redArg___closed__4));
v___x_1728_ = l_Lean_stringToMessageData(v___x_1727_);
return v___x_1728_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkRules_spec__1___redArg(lean_object* v_as_1729_, size_t v_sz_1730_, size_t v_i_1731_, lean_object* v_b_1732_){
_start:
{
uint8_t v___x_1734_; 
v___x_1734_ = lean_usize_dec_lt(v_i_1731_, v_sz_1730_);
if (v___x_1734_ == 0)
{
lean_object* v___x_1735_; 
v___x_1735_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1735_, 0, v_b_1732_);
return v___x_1735_;
}
else
{
lean_object* v_a_1736_; lean_object* v_source_1737_; lean_object* v_head_1738_; lean_object* v_arity_1739_; lean_object* v___x_1740_; lean_object* v___x_1741_; lean_object* v___x_1742_; lean_object* v___x_1743_; lean_object* v___x_1744_; lean_object* v___x_1745_; lean_object* v___x_1746_; lean_object* v___x_1747_; lean_object* v___x_1748_; lean_object* v___x_1749_; lean_object* v___x_1750_; lean_object* v___x_1751_; lean_object* v___x_1752_; lean_object* v___x_1753_; lean_object* v___x_1754_; lean_object* v___x_1755_; size_t v___x_1756_; size_t v___x_1757_; 
v_a_1736_ = lean_array_uget_borrowed(v_as_1729_, v_i_1731_);
v_source_1737_ = lean_ctor_get(v_a_1736_, 0);
v_head_1738_ = lean_ctor_get(v_a_1736_, 1);
v_arity_1739_ = lean_ctor_get(v_a_1736_, 2);
v___x_1740_ = lean_obj_once(&lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkRules_spec__1___redArg___closed__1, &lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkRules_spec__1___redArg___closed__1_once, _init_lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkRules_spec__1___redArg___closed__1);
lean_inc(v_head_1738_);
v___x_1741_ = l_Lean_MessageData_ofName(v_head_1738_);
v___x_1742_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1742_, 0, v___x_1740_);
lean_ctor_set(v___x_1742_, 1, v___x_1741_);
v___x_1743_ = lean_obj_once(&lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkRules_spec__1___redArg___closed__3, &lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkRules_spec__1___redArg___closed__3_once, _init_lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkRules_spec__1___redArg___closed__3);
v___x_1744_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1744_, 0, v___x_1742_);
lean_ctor_set(v___x_1744_, 1, v___x_1743_);
lean_inc(v_arity_1739_);
v___x_1745_ = l_Nat_reprFast(v_arity_1739_);
v___x_1746_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_1746_, 0, v___x_1745_);
v___x_1747_ = l_Lean_MessageData_ofFormat(v___x_1746_);
v___x_1748_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1748_, 0, v___x_1744_);
lean_ctor_set(v___x_1748_, 1, v___x_1747_);
v___x_1749_ = lean_obj_once(&lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkRules_spec__1___redArg___closed__5, &lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkRules_spec__1___redArg___closed__5_once, _init_lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkRules_spec__1___redArg___closed__5);
v___x_1750_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1750_, 0, v___x_1748_);
lean_ctor_set(v___x_1750_, 1, v___x_1749_);
lean_inc(v_source_1737_);
v___x_1751_ = l_Lean_MessageData_ofName(v_source_1737_);
v___x_1752_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1752_, 0, v___x_1750_);
lean_ctor_set(v___x_1752_, 1, v___x_1751_);
v___x_1753_ = lean_obj_once(&lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__0___redArg___closed__1, &lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__0___redArg___closed__1_once, _init_lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__0___redArg___closed__1);
v___x_1754_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1754_, 0, v___x_1752_);
lean_ctor_set(v___x_1754_, 1, v___x_1753_);
v___x_1755_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1755_, 0, v_b_1732_);
lean_ctor_set(v___x_1755_, 1, v___x_1754_);
v___x_1756_ = ((size_t)1ULL);
v___x_1757_ = lean_usize_add(v_i_1731_, v___x_1756_);
v_i_1731_ = v___x_1757_;
v_b_1732_ = v___x_1755_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkRules_spec__1___redArg___boxed(lean_object* v_as_1759_, lean_object* v_sz_1760_, lean_object* v_i_1761_, lean_object* v_b_1762_, lean_object* v___y_1763_){
_start:
{
size_t v_sz_boxed_1764_; size_t v_i_boxed_1765_; lean_object* v_res_1766_; 
v_sz_boxed_1764_ = lean_unbox_usize(v_sz_1760_);
lean_dec(v_sz_1760_);
v_i_boxed_1765_ = lean_unbox_usize(v_i_1761_);
lean_dec(v_i_1761_);
v_res_1766_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkRules_spec__1___redArg(v_as_1759_, v_sz_boxed_1764_, v_i_boxed_1765_, v_b_1762_);
lean_dec_ref(v_as_1759_);
return v_res_1766_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_List_mapTR_loop___at___00JunkValues_elabJunkRules_spec__0(lean_object* v_a_1768_, lean_object* v_a_1769_){
_start:
{
if (lean_obj_tag(v_a_1768_) == 0)
{
lean_object* v___x_1770_; 
v___x_1770_ = l_List_reverse___redArg(v_a_1769_);
return v___x_1770_;
}
else
{
lean_object* v_head_1771_; lean_object* v_tail_1772_; lean_object* v___x_1774_; uint8_t v_isShared_1775_; uint8_t v_isSharedCheck_1786_; 
v_head_1771_ = lean_ctor_get(v_a_1768_, 0);
v_tail_1772_ = lean_ctor_get(v_a_1768_, 1);
v_isSharedCheck_1786_ = !lean_is_exclusive(v_a_1768_);
if (v_isSharedCheck_1786_ == 0)
{
v___x_1774_ = v_a_1768_;
v_isShared_1775_ = v_isSharedCheck_1786_;
goto v_resetjp_1773_;
}
else
{
lean_inc(v_tail_1772_);
lean_inc(v_head_1771_);
lean_dec(v_a_1768_);
v___x_1774_ = lean_box(0);
v_isShared_1775_ = v_isSharedCheck_1786_;
goto v_resetjp_1773_;
}
v_resetjp_1773_:
{
lean_object* v_fst_1776_; lean_object* v_snd_1777_; lean_object* v___x_1778_; lean_object* v___x_1779_; lean_object* v___x_1780_; lean_object* v___x_1781_; lean_object* v___x_1783_; 
v_fst_1776_ = lean_ctor_get(v_head_1771_, 0);
lean_inc(v_fst_1776_);
v_snd_1777_ = lean_ctor_get(v_head_1771_, 1);
lean_inc(v_snd_1777_);
lean_dec(v_head_1771_);
v___x_1778_ = l_Nat_reprFast(v_snd_1777_);
v___x_1779_ = ((lean_object*)(lp_JunkValues_List_mapTR_loop___at___00JunkValues_elabJunkRules_spec__0___closed__0));
v___x_1780_ = lean_string_append(v___x_1778_, v___x_1779_);
v___x_1781_ = lean_string_append(v___x_1780_, v_fst_1776_);
lean_dec(v_fst_1776_);
if (v_isShared_1775_ == 0)
{
lean_ctor_set(v___x_1774_, 1, v_a_1769_);
lean_ctor_set(v___x_1774_, 0, v___x_1781_);
v___x_1783_ = v___x_1774_;
goto v_reusejp_1782_;
}
else
{
lean_object* v_reuseFailAlloc_1785_; 
v_reuseFailAlloc_1785_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1785_, 0, v___x_1781_);
lean_ctor_set(v_reuseFailAlloc_1785_, 1, v_a_1769_);
v___x_1783_ = v_reuseFailAlloc_1785_;
goto v_reusejp_1782_;
}
v_reusejp_1782_:
{
v_a_1768_ = v_tail_1772_;
v_a_1769_ = v___x_1783_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00JunkValues_elabJunkRules_spec__2(lean_object* v_as_1787_, size_t v_i_1788_, size_t v_stop_1789_, lean_object* v_b_1790_){
_start:
{
lean_object* v___y_1792_; uint8_t v___x_1796_; 
v___x_1796_ = lean_usize_dec_eq(v_i_1788_, v_stop_1789_);
if (v___x_1796_ == 0)
{
lean_object* v___x_1797_; lean_object* v_snd_1798_; lean_object* v___x_1799_; uint8_t v___x_1800_; 
v___x_1797_ = lean_array_uget_borrowed(v_as_1787_, v_i_1788_);
v_snd_1798_ = lean_ctor_get(v___x_1797_, 1);
v___x_1799_ = lean_unsigned_to_nat(0u);
v___x_1800_ = lean_nat_dec_lt(v___x_1799_, v_snd_1798_);
if (v___x_1800_ == 0)
{
v___y_1792_ = v_b_1790_;
goto v___jp_1791_;
}
else
{
lean_object* v___x_1801_; 
lean_inc(v___x_1797_);
v___x_1801_ = lean_array_push(v_b_1790_, v___x_1797_);
v___y_1792_ = v___x_1801_;
goto v___jp_1791_;
}
}
else
{
return v_b_1790_;
}
v___jp_1791_:
{
size_t v___x_1793_; size_t v___x_1794_; 
v___x_1793_ = ((size_t)1ULL);
v___x_1794_ = lean_usize_add(v_i_1788_, v___x_1793_);
v_i_1788_ = v___x_1794_;
v_b_1790_ = v___y_1792_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00JunkValues_elabJunkRules_spec__2___boxed(lean_object* v_as_1802_, lean_object* v_i_1803_, lean_object* v_stop_1804_, lean_object* v_b_1805_){
_start:
{
size_t v_i_boxed_1806_; size_t v_stop_boxed_1807_; lean_object* v_res_1808_; 
v_i_boxed_1806_ = lean_unbox_usize(v_i_1803_);
lean_dec(v_i_1803_);
v_stop_boxed_1807_ = lean_unbox_usize(v_stop_1804_);
lean_dec(v_stop_1804_);
v_res_1808_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00JunkValues_elabJunkRules_spec__2(v_as_1802_, v_i_boxed_1806_, v_stop_boxed_1807_, v_b_1805_);
lean_dec_ref(v_as_1802_);
return v_res_1808_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_elabJunkRules___redArg___lam__0___closed__1(void){
_start:
{
lean_object* v___x_1810_; lean_object* v___x_1811_; 
v___x_1810_ = ((lean_object*)(lp_JunkValues_JunkValues_elabJunkRules___redArg___lam__0___closed__0));
v___x_1811_ = l_Lean_stringToMessageData(v___x_1810_);
return v___x_1811_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_elabJunkRules___redArg___lam__0___closed__4(void){
_start:
{
lean_object* v___x_1814_; lean_object* v___x_1815_; 
v___x_1814_ = ((lean_object*)(lp_JunkValues_JunkValues_elabJunkRules___redArg___lam__0___closed__3));
v___x_1815_ = l_Lean_stringToMessageData(v___x_1814_);
return v___x_1815_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_elabJunkRules___redArg___lam__0___closed__6(void){
_start:
{
lean_object* v___x_1817_; lean_object* v___x_1818_; 
v___x_1817_ = ((lean_object*)(lp_JunkValues_JunkValues_elabJunkRules___redArg___lam__0___closed__5));
v___x_1818_ = l_Lean_stringToMessageData(v___x_1817_);
return v___x_1818_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_elabJunkRules___redArg___lam__0___closed__8(void){
_start:
{
lean_object* v___x_1820_; lean_object* v___x_1821_; 
v___x_1820_ = ((lean_object*)(lp_JunkValues_JunkValues_elabJunkRules___redArg___lam__0___closed__7));
v___x_1821_ = l_Lean_stringToMessageData(v___x_1820_);
return v___x_1821_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_elabJunkRules___redArg___lam__0(lean_object* v_opts_1824_, lean_object* v___y_1825_, lean_object* v___y_1826_, lean_object* v___y_1827_, lean_object* v___y_1828_, lean_object* v___y_1829_, lean_object* v___y_1830_){
_start:
{
lean_object* v___x_1832_; 
v___x_1832_ = lp_JunkValues_JunkValues_RuleSet_ofEnv(v_opts_1824_, v___y_1827_, v___y_1828_, v___y_1829_, v___y_1830_);
if (lean_obj_tag(v___x_1832_) == 0)
{
lean_object* v_a_1833_; lean_object* v_ruleSet_1834_; lean_object* v_contributions_1835_; lean_object* v_problems_1836_; lean_object* v___x_1837_; size_t v_sz_1838_; size_t v___x_1839_; lean_object* v___x_1840_; 
v_a_1833_ = lean_ctor_get(v___x_1832_, 0);
lean_inc(v_a_1833_);
lean_dec_ref_known(v___x_1832_, 1);
v_ruleSet_1834_ = lean_ctor_get(v_a_1833_, 0);
lean_inc_ref(v_ruleSet_1834_);
v_contributions_1835_ = lean_ctor_get(v_a_1833_, 1);
lean_inc_ref(v_contributions_1835_);
v_problems_1836_ = lean_ctor_get(v_a_1833_, 2);
lean_inc_ref(v_problems_1836_);
lean_dec(v_a_1833_);
v___x_1837_ = lean_box(0);
v_sz_1838_ = lean_array_size(v_problems_1836_);
v___x_1839_ = ((size_t)0ULL);
v___x_1840_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkCheck_spec__5(v_problems_1836_, v_sz_1838_, v___x_1839_, v___x_1837_, v___y_1825_, v___y_1826_, v___y_1827_, v___y_1828_, v___y_1829_, v___y_1830_);
lean_dec_ref(v_problems_1836_);
if (lean_obj_tag(v___x_1840_) == 0)
{
lean_object* v___x_1842_; uint8_t v_isShared_1843_; uint8_t v_isSharedCheck_1900_; 
v_isSharedCheck_1900_ = !lean_is_exclusive(v___x_1840_);
if (v_isSharedCheck_1900_ == 0)
{
lean_object* v_unused_1901_; 
v_unused_1901_ = lean_ctor_get(v___x_1840_, 0);
lean_dec(v_unused_1901_);
v___x_1842_ = v___x_1840_;
v_isShared_1843_ = v_isSharedCheck_1900_;
goto v_resetjp_1841_;
}
else
{
lean_dec(v___x_1840_);
v___x_1842_ = lean_box(0);
v_isShared_1843_ = v_isSharedCheck_1900_;
goto v_resetjp_1841_;
}
v_resetjp_1841_:
{
lean_object* v_rules_1844_; lean_object* v___x_1846_; uint8_t v_isShared_1847_; uint8_t v_isSharedCheck_1898_; 
v_rules_1844_ = lean_ctor_get(v_ruleSet_1834_, 1);
v_isSharedCheck_1898_ = !lean_is_exclusive(v_ruleSet_1834_);
if (v_isSharedCheck_1898_ == 0)
{
lean_object* v_unused_1899_; 
v_unused_1899_ = lean_ctor_get(v_ruleSet_1834_, 0);
lean_dec(v_unused_1899_);
v___x_1846_ = v_ruleSet_1834_;
v_isShared_1847_ = v_isSharedCheck_1898_;
goto v_resetjp_1845_;
}
else
{
lean_inc(v_rules_1844_);
lean_dec(v_ruleSet_1834_);
v___x_1846_ = lean_box(0);
v_isShared_1847_ = v_isSharedCheck_1898_;
goto v_resetjp_1845_;
}
v_resetjp_1845_:
{
lean_object* v___x_1848_; lean_object* v___x_1849_; lean_object* v___x_1851_; 
v___x_1848_ = lean_array_get_size(v_rules_1844_);
v___x_1849_ = l_Nat_reprFast(v___x_1848_);
if (v_isShared_1843_ == 0)
{
lean_ctor_set_tag(v___x_1842_, 3);
lean_ctor_set(v___x_1842_, 0, v___x_1849_);
v___x_1851_ = v___x_1842_;
goto v_reusejp_1850_;
}
else
{
lean_object* v_reuseFailAlloc_1897_; 
v_reuseFailAlloc_1897_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1897_, 0, v___x_1849_);
v___x_1851_ = v_reuseFailAlloc_1897_;
goto v_reusejp_1850_;
}
v_reusejp_1850_:
{
lean_object* v___x_1852_; lean_object* v___x_1853_; lean_object* v___x_1855_; 
v___x_1852_ = l_Lean_MessageData_ofFormat(v___x_1851_);
v___x_1853_ = lean_obj_once(&lp_JunkValues_JunkValues_elabJunkRules___redArg___lam__0___closed__1, &lp_JunkValues_JunkValues_elabJunkRules___redArg___lam__0___closed__1_once, _init_lp_JunkValues_JunkValues_elabJunkRules___redArg___lam__0___closed__1);
if (v_isShared_1847_ == 0)
{
lean_ctor_set_tag(v___x_1846_, 7);
lean_ctor_set(v___x_1846_, 1, v___x_1853_);
lean_ctor_set(v___x_1846_, 0, v___x_1852_);
v___x_1855_ = v___x_1846_;
goto v_reusejp_1854_;
}
else
{
lean_object* v_reuseFailAlloc_1896_; 
v_reuseFailAlloc_1896_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1896_, 0, v___x_1852_);
lean_ctor_set(v_reuseFailAlloc_1896_, 1, v___x_1853_);
v___x_1855_ = v_reuseFailAlloc_1896_;
goto v_reusejp_1854_;
}
v_reusejp_1854_:
{
lean_object* v___y_1857_; lean_object* v___x_1887_; lean_object* v___x_1888_; lean_object* v___x_1889_; uint8_t v___x_1890_; 
v___x_1887_ = lean_unsigned_to_nat(0u);
v___x_1888_ = lean_array_get_size(v_contributions_1835_);
v___x_1889_ = ((lean_object*)(lp_JunkValues_JunkValues_elabJunkRules___redArg___lam__0___closed__9));
v___x_1890_ = lean_nat_dec_lt(v___x_1887_, v___x_1888_);
if (v___x_1890_ == 0)
{
lean_dec_ref(v_contributions_1835_);
v___y_1857_ = v___x_1889_;
goto v___jp_1856_;
}
else
{
uint8_t v___x_1891_; 
v___x_1891_ = lean_nat_dec_le(v___x_1888_, v___x_1888_);
if (v___x_1891_ == 0)
{
if (v___x_1890_ == 0)
{
lean_dec_ref(v_contributions_1835_);
v___y_1857_ = v___x_1889_;
goto v___jp_1856_;
}
else
{
size_t v___x_1892_; lean_object* v___x_1893_; 
v___x_1892_ = lean_usize_of_nat(v___x_1888_);
v___x_1893_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00JunkValues_elabJunkRules_spec__2(v_contributions_1835_, v___x_1839_, v___x_1892_, v___x_1889_);
lean_dec_ref(v_contributions_1835_);
v___y_1857_ = v___x_1893_;
goto v___jp_1856_;
}
}
else
{
size_t v___x_1894_; lean_object* v___x_1895_; 
v___x_1894_ = lean_usize_of_nat(v___x_1888_);
v___x_1895_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00JunkValues_elabJunkRules_spec__2(v_contributions_1835_, v___x_1839_, v___x_1894_, v___x_1889_);
lean_dec_ref(v_contributions_1835_);
v___y_1857_ = v___x_1895_;
goto v___jp_1856_;
}
}
v___jp_1856_:
{
lean_object* v___x_1858_; lean_object* v___x_1859_; uint8_t v___x_1860_; 
v___x_1858_ = lean_array_get_size(v___y_1857_);
v___x_1859_ = lean_unsigned_to_nat(0u);
v___x_1860_ = lean_nat_dec_eq(v___x_1858_, v___x_1859_);
if (v___x_1860_ == 0)
{
lean_object* v___x_1861_; lean_object* v___x_1862_; lean_object* v___x_1863_; lean_object* v___x_1864_; lean_object* v___x_1865_; lean_object* v___x_1866_; lean_object* v___x_1867_; lean_object* v___x_1868_; lean_object* v___x_1869_; lean_object* v___x_1870_; lean_object* v___x_1871_; size_t v_sz_1872_; lean_object* v___x_1873_; 
v___x_1861_ = ((lean_object*)(lp_JunkValues_JunkValues_elabJunkRules___redArg___lam__0___closed__2));
v___x_1862_ = lean_array_to_list(v___y_1857_);
v___x_1863_ = lean_box(0);
v___x_1864_ = lp_JunkValues_List_mapTR_loop___at___00JunkValues_elabJunkRules_spec__0(v___x_1862_, v___x_1863_);
v___x_1865_ = l_String_intercalate(v___x_1861_, v___x_1864_);
v___x_1866_ = lean_obj_once(&lp_JunkValues_JunkValues_elabJunkRules___redArg___lam__0___closed__4, &lp_JunkValues_JunkValues_elabJunkRules___redArg___lam__0___closed__4_once, _init_lp_JunkValues_JunkValues_elabJunkRules___redArg___lam__0___closed__4);
v___x_1867_ = l_Lean_stringToMessageData(v___x_1865_);
v___x_1868_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1868_, 0, v___x_1866_);
lean_ctor_set(v___x_1868_, 1, v___x_1867_);
v___x_1869_ = lean_obj_once(&lp_JunkValues_JunkValues_elabJunkRules___redArg___lam__0___closed__6, &lp_JunkValues_JunkValues_elabJunkRules___redArg___lam__0___closed__6_once, _init_lp_JunkValues_JunkValues_elabJunkRules___redArg___lam__0___closed__6);
v___x_1870_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1870_, 0, v___x_1868_);
lean_ctor_set(v___x_1870_, 1, v___x_1869_);
v___x_1871_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1871_, 0, v___x_1855_);
lean_ctor_set(v___x_1871_, 1, v___x_1870_);
v_sz_1872_ = lean_array_size(v_rules_1844_);
v___x_1873_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkRules_spec__1___redArg(v_rules_1844_, v_sz_1872_, v___x_1839_, v___x_1871_);
lean_dec_ref(v_rules_1844_);
if (lean_obj_tag(v___x_1873_) == 0)
{
lean_object* v_a_1874_; lean_object* v___x_1875_; 
v_a_1874_ = lean_ctor_get(v___x_1873_, 0);
lean_inc(v_a_1874_);
lean_dec_ref_known(v___x_1873_, 1);
v___x_1875_ = lp_JunkValues_Lean_logInfo___at___00JunkValues_elabJunkCheck_spec__4(v_a_1874_, v___y_1825_, v___y_1826_, v___y_1827_, v___y_1828_, v___y_1829_, v___y_1830_);
return v___x_1875_;
}
else
{
lean_object* v_a_1876_; lean_object* v___x_1878_; uint8_t v_isShared_1879_; uint8_t v_isSharedCheck_1883_; 
v_a_1876_ = lean_ctor_get(v___x_1873_, 0);
v_isSharedCheck_1883_ = !lean_is_exclusive(v___x_1873_);
if (v_isSharedCheck_1883_ == 0)
{
v___x_1878_ = v___x_1873_;
v_isShared_1879_ = v_isSharedCheck_1883_;
goto v_resetjp_1877_;
}
else
{
lean_inc(v_a_1876_);
lean_dec(v___x_1873_);
v___x_1878_ = lean_box(0);
v_isShared_1879_ = v_isSharedCheck_1883_;
goto v_resetjp_1877_;
}
v_resetjp_1877_:
{
lean_object* v___x_1881_; 
if (v_isShared_1879_ == 0)
{
v___x_1881_ = v___x_1878_;
goto v_reusejp_1880_;
}
else
{
lean_object* v_reuseFailAlloc_1882_; 
v_reuseFailAlloc_1882_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1882_, 0, v_a_1876_);
v___x_1881_ = v_reuseFailAlloc_1882_;
goto v_reusejp_1880_;
}
v_reusejp_1880_:
{
return v___x_1881_;
}
}
}
}
else
{
lean_object* v___x_1884_; lean_object* v___x_1885_; lean_object* v___x_1886_; 
lean_dec_ref(v___y_1857_);
lean_dec_ref(v_rules_1844_);
v___x_1884_ = lean_obj_once(&lp_JunkValues_JunkValues_elabJunkRules___redArg___lam__0___closed__8, &lp_JunkValues_JunkValues_elabJunkRules___redArg___lam__0___closed__8_once, _init_lp_JunkValues_JunkValues_elabJunkRules___redArg___lam__0___closed__8);
v___x_1885_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1885_, 0, v___x_1855_);
lean_ctor_set(v___x_1885_, 1, v___x_1884_);
v___x_1886_ = lp_JunkValues_Lean_logInfo___at___00JunkValues_elabJunkCheck_spec__4(v___x_1885_, v___y_1825_, v___y_1826_, v___y_1827_, v___y_1828_, v___y_1829_, v___y_1830_);
return v___x_1886_;
}
}
}
}
}
}
}
else
{
lean_dec_ref(v_contributions_1835_);
lean_dec_ref(v_ruleSet_1834_);
return v___x_1840_;
}
}
else
{
lean_object* v_a_1902_; lean_object* v___x_1904_; uint8_t v_isShared_1905_; uint8_t v_isSharedCheck_1909_; 
v_a_1902_ = lean_ctor_get(v___x_1832_, 0);
v_isSharedCheck_1909_ = !lean_is_exclusive(v___x_1832_);
if (v_isSharedCheck_1909_ == 0)
{
v___x_1904_ = v___x_1832_;
v_isShared_1905_ = v_isSharedCheck_1909_;
goto v_resetjp_1903_;
}
else
{
lean_inc(v_a_1902_);
lean_dec(v___x_1832_);
v___x_1904_ = lean_box(0);
v_isShared_1905_ = v_isSharedCheck_1909_;
goto v_resetjp_1903_;
}
v_resetjp_1903_:
{
lean_object* v___x_1907_; 
if (v_isShared_1905_ == 0)
{
v___x_1907_ = v___x_1904_;
goto v_reusejp_1906_;
}
else
{
lean_object* v_reuseFailAlloc_1908_; 
v_reuseFailAlloc_1908_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1908_, 0, v_a_1902_);
v___x_1907_ = v_reuseFailAlloc_1908_;
goto v_reusejp_1906_;
}
v_reusejp_1906_:
{
return v___x_1907_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_elabJunkRules___redArg___lam__0___boxed(lean_object* v_opts_1910_, lean_object* v___y_1911_, lean_object* v___y_1912_, lean_object* v___y_1913_, lean_object* v___y_1914_, lean_object* v___y_1915_, lean_object* v___y_1916_, lean_object* v___y_1917_){
_start:
{
lean_object* v_res_1918_; 
v_res_1918_ = lp_JunkValues_JunkValues_elabJunkRules___redArg___lam__0(v_opts_1910_, v___y_1911_, v___y_1912_, v___y_1913_, v___y_1914_, v___y_1915_, v___y_1916_);
lean_dec(v___y_1916_);
lean_dec_ref(v___y_1915_);
lean_dec(v___y_1914_);
lean_dec_ref(v___y_1913_);
lean_dec(v___y_1912_);
lean_dec_ref(v___y_1911_);
return v_res_1918_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_elabJunkRules___redArg(lean_object* v_a_1919_, lean_object* v_a_1920_){
_start:
{
lean_object* v___x_1922_; lean_object* v_scopes_1923_; lean_object* v___x_1924_; lean_object* v___x_1925_; lean_object* v_opts_1926_; lean_object* v___f_1927_; lean_object* v___x_1928_; 
v___x_1922_ = lean_st_ref_get(v_a_1920_);
v_scopes_1923_ = lean_ctor_get(v___x_1922_, 2);
lean_inc(v_scopes_1923_);
lean_dec(v___x_1922_);
v___x_1924_ = l_Lean_Elab_Command_instInhabitedScope_default;
v___x_1925_ = l_List_head_x21___redArg(v___x_1924_, v_scopes_1923_);
lean_dec(v_scopes_1923_);
v_opts_1926_ = lean_ctor_get(v___x_1925_, 1);
lean_inc_ref(v_opts_1926_);
lean_dec(v___x_1925_);
v___f_1927_ = lean_alloc_closure((void*)(lp_JunkValues_JunkValues_elabJunkRules___redArg___lam__0___boxed), 8, 1);
lean_closure_set(v___f_1927_, 0, v_opts_1926_);
v___x_1928_ = l_Lean_Elab_Command_liftTermElabM___redArg(v___f_1927_, v_a_1919_, v_a_1920_);
return v___x_1928_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_elabJunkRules___redArg___boxed(lean_object* v_a_1929_, lean_object* v_a_1930_, lean_object* v_a_1931_){
_start:
{
lean_object* v_res_1932_; 
v_res_1932_ = lp_JunkValues_JunkValues_elabJunkRules___redArg(v_a_1929_, v_a_1930_);
lean_dec(v_a_1930_);
lean_dec_ref(v_a_1929_);
return v_res_1932_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_elabJunkRules(lean_object* v_x_1933_, lean_object* v_a_1934_, lean_object* v_a_1935_){
_start:
{
lean_object* v___x_1937_; 
v___x_1937_ = lp_JunkValues_JunkValues_elabJunkRules___redArg(v_a_1934_, v_a_1935_);
return v___x_1937_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_elabJunkRules___boxed(lean_object* v_x_1938_, lean_object* v_a_1939_, lean_object* v_a_1940_, lean_object* v_a_1941_){
_start:
{
lean_object* v_res_1942_; 
v_res_1942_ = lp_JunkValues_JunkValues_elabJunkRules(v_x_1938_, v_a_1939_, v_a_1940_);
lean_dec(v_a_1940_);
lean_dec_ref(v_a_1939_);
lean_dec(v_x_1938_);
return v_res_1942_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkRules_spec__1(lean_object* v_as_1943_, size_t v_sz_1944_, size_t v_i_1945_, lean_object* v_b_1946_, lean_object* v___y_1947_, lean_object* v___y_1948_, lean_object* v___y_1949_, lean_object* v___y_1950_, lean_object* v___y_1951_, lean_object* v___y_1952_){
_start:
{
lean_object* v___x_1954_; 
v___x_1954_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkRules_spec__1___redArg(v_as_1943_, v_sz_1944_, v_i_1945_, v_b_1946_);
return v___x_1954_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkRules_spec__1___boxed(lean_object* v_as_1955_, lean_object* v_sz_1956_, lean_object* v_i_1957_, lean_object* v_b_1958_, lean_object* v___y_1959_, lean_object* v___y_1960_, lean_object* v___y_1961_, lean_object* v___y_1962_, lean_object* v___y_1963_, lean_object* v___y_1964_, lean_object* v___y_1965_){
_start:
{
size_t v_sz_boxed_1966_; size_t v_i_boxed_1967_; lean_object* v_res_1968_; 
v_sz_boxed_1966_ = lean_unbox_usize(v_sz_1956_);
lean_dec(v_sz_1956_);
v_i_boxed_1967_ = lean_unbox_usize(v_i_1957_);
lean_dec(v_i_1957_);
v_res_1968_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_elabJunkRules_spec__1(v_as_1955_, v_sz_boxed_1966_, v_i_boxed_1967_, v_b_1958_, v___y_1959_, v___y_1960_, v___y_1961_, v___y_1962_, v___y_1963_, v___y_1964_);
lean_dec(v___y_1964_);
lean_dec_ref(v___y_1963_);
lean_dec(v___y_1962_);
lean_dec_ref(v___y_1961_);
lean_dec(v___y_1960_);
lean_dec_ref(v___y_1959_);
lean_dec_ref(v_as_1955_);
return v_res_1968_;
}
}
lean_object* runtime_initialize_Init(uint8_t builtin);
lean_object* runtime_initialize_JunkValues_JunkValues_Frontend(uint8_t builtin);
lean_object* runtime_initialize_Lean_Elab_Command(uint8_t builtin);
static bool _G_runtime_initialized = false;
LEAN_EXPORT lean_object* runtime_initialize_JunkValues_JunkValues_Elab(uint8_t builtin) {
lean_object * res;
if (_G_runtime_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_runtime_initialized = true;
res = runtime_initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = runtime_initialize_JunkValues_JunkValues_Frontend(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = runtime_initialize_Lean_Elab_Command(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return lean_io_result_mk_ok(lean_box(0));
}
lean_object* runtime_initialize_Init(uint8_t builtin);
lean_object* runtime_initialize_JunkValues_JunkValues_Frontend(uint8_t builtin);
lean_object* runtime_initialize_Lean_Elab_Command(uint8_t builtin);
static bool _G_meta_initialized = false;
LEAN_EXPORT lean_object* meta_initialize_JunkValues_JunkValues_Elab(uint8_t builtin) {
lean_object * res;
if (_G_meta_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_meta_initialized = true;
res = runtime_initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = runtime_initialize_JunkValues_JunkValues_Frontend(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = runtime_initialize_Lean_Elab_Command(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return lean_io_result_mk_ok(lean_box(0));
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_JunkValues_JunkValues_Frontend(uint8_t builtin);
lean_object* initialize_Lean_Elab_Command(uint8_t builtin);
lean_object* initialize_JunkValues_JunkValues_Frontend(uint8_t builtin);
lean_object* initialize_Lean_Elab_Command(uint8_t builtin);
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_JunkValues_JunkValues_Elab(uint8_t builtin) {
lean_object * res;
if (_G_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_initialized = true;
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_JunkValues_JunkValues_Frontend(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Lean_Elab_Command(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_JunkValues_JunkValues_Frontend(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Lean_Elab_Command(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = runtime_initialize_JunkValues_JunkValues_Elab(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = meta_initialize_JunkValues_JunkValues_Elab(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return initialize_JunkValues_JunkValues_Elab(builtin);
}
#ifdef __cplusplus
}
#endif
