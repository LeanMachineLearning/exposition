// Lean compiler output
// Module: JunkValues.Frontend
// Imports: public import Init public meta import Init public import JunkValues.Scan public import Lean.Elab.Command
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
uint8_t lean_string_dec_eq(lean_object*, lean_object*);
uint8_t lean_usize_dec_lt(size_t, size_t);
lean_object* lean_array_uget_borrowed(lean_object*, size_t);
size_t lean_array_size(lean_object*);
lean_object* l_Lean_Name_mkStr1(lean_object*);
uint8_t lean_name_eq(lean_object*, lean_object*);
lean_object* lean_array_get(lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_Syntax_getKind(lean_object*);
lean_object* l_Lean_Name_mkStr4(lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_Syntax_getArg(lean_object*, lean_object*);
uint8_t l_Lean_Syntax_isIdent(lean_object*);
lean_object* l_Lean_Syntax_getId(lean_object*);
lean_object* l_Lean_Name_append(lean_object*, lean_object*);
lean_object* lean_mk_empty_array_with_capacity(lean_object*);
lean_object* lean_array_push(lean_object*, lean_object*);
size_t lean_usize_add(size_t, size_t);
uint8_t l_Lean_Environment_contains(lean_object*, lean_object*, uint8_t);
lean_object* lean_array_get_size(lean_object*);
uint8_t lean_nat_dec_lt(lean_object*, lean_object*);
size_t lean_usize_of_nat(lean_object*);
uint8_t lean_usize_dec_eq(size_t, size_t);
lean_object* l_Std_DTreeMap_Internal_Impl_Const_get_x3f___at___00Lean_NameMap_find_x3f_spec__0___redArg(lean_object*, lean_object*);
lean_object* l_Lean_stringToMessageData(lean_object*);
lean_object* lean_register_option(lean_object*, lean_object*);
lean_object* lean_array_fget_borrowed(lean_object*, lean_object*);
lean_object* lean_nat_add(lean_object*, lean_object*);
lean_object* lp_JunkValues_JunkValues_scanDecl(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_Name_mkStr2(lean_object*, lean_object*);
lean_object* l_Lean_Name_mkStr3(lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_MessageData_ofName(lean_object*);
lean_object* lp_JunkValues_JunkValues_Finding_message(lean_object*);
lean_object* l_Lean_MessageData_note(lean_object*);
extern lean_object* l_Lean_Linter_linterMessageTag;
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
uint8_t l_Lean_instBEqMessageSeverity_beq(uint8_t, uint8_t);
extern lean_object* l_Lean_warningAsError;
uint8_t l_Lean_MessageData_hasSyntheticSorry(lean_object*);
extern lean_object* l_Lean_Elab_Command_instInhabitedScope_default;
lean_object* l_List_head_x21___redArg(lean_object*, lean_object*);
uint8_t l_Lean_MessageLog_hasErrors(lean_object*);
lean_object* l_Lean_Elab_Command_getScope___redArg(lean_object*);
lean_object* l_Lean_Syntax_topDown(lean_object*, uint8_t);
lean_object* l_Lean_Environment_constants(lean_object*);
uint8_t lp_JunkValues_JunkValues_isCompilerGenerated(lean_object*);
uint8_t l_Lean_Name_isPrefixOf(lean_object*, lean_object*);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
uint8_t lean_nat_dec_eq(lean_object*, lean_object*);
lean_object* l_String_splitOnAux(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_List_reverse___redArg(lean_object*);
lean_object* lean_string_utf8_byte_size(lean_object*);
lean_object* l_String_Slice_trimAscii(lean_object*);
lean_object* l_String_Slice_toString(lean_object*);
extern lean_object* lp_JunkValues_JunkValues_assumptionDischarger;
lean_object* lp_JunkValues_JunkValues_tacticDischarger_x3f___redArg(lean_object*, lean_object*);
lean_object* lp_JunkValues_JunkValues_firstDischarger(lean_object*);
lean_object* lp_JunkValues_JunkValues_RuleSet_ofEnv(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_Array_append___redArg(lean_object*, lean_object*);
lean_object* l_Lean_Elab_Command_liftTermElabM___redArg(lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_Elab_Command_addLinter(lean_object*);
extern lean_object* l_Lean_instInhabitedEffectiveImport_default;
lean_object* lean_array_get_borrowed(lean_object*, lean_object*, lean_object*);
extern lean_object* l_Lean_instInhabitedModuleData_default;
uint8_t l_Lean_Name_isInternal(lean_object*);
uint8_t l_Lean_Name_isImplementationDetail(lean_object*);
uint8_t l_Lean_isPrivateName(lean_object*);
lean_object* l_Lean_Environment_header(lean_object*);
lean_object* lp_JunkValues_JunkValues_scanDecls(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Option_register___at___00__private_JunkValues_Frontend_0__JunkValues_initFn_00___x40_JunkValues_Frontend_3713897505____hygCtx___hyg_4__spec__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Option_register___at___00__private_JunkValues_Frontend_0__JunkValues_initFn_00___x40_JunkValues_Frontend_3713897505____hygCtx___hyg_4__spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__0_00___x40_JunkValues_Frontend_3713897505____hygCtx___hyg_4__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "linter"};
static const lean_object* lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__0_00___x40_JunkValues_Frontend_3713897505____hygCtx___hyg_4_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__0_00___x40_JunkValues_Frontend_3713897505____hygCtx___hyg_4__value;
static const lean_string_object lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__1_00___x40_JunkValues_Frontend_3713897505____hygCtx___hyg_4__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "junkValues"};
static const lean_object* lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__1_00___x40_JunkValues_Frontend_3713897505____hygCtx___hyg_4_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__1_00___x40_JunkValues_Frontend_3713897505____hygCtx___hyg_4__value;
static const lean_ctor_object lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__2_00___x40_JunkValues_Frontend_3713897505____hygCtx___hyg_4__value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__0_00___x40_JunkValues_Frontend_3713897505____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(186, 218, 113, 226, 101, 176, 32, 79)}};
static const lean_ctor_object lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__2_00___x40_JunkValues_Frontend_3713897505____hygCtx___hyg_4__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__2_00___x40_JunkValues_Frontend_3713897505____hygCtx___hyg_4__value_aux_0),((lean_object*)&lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__1_00___x40_JunkValues_Frontend_3713897505____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(91, 223, 164, 59, 32, 198, 166, 116)}};
static const lean_object* lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__2_00___x40_JunkValues_Frontend_3713897505____hygCtx___hyg_4_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__2_00___x40_JunkValues_Frontend_3713897505____hygCtx___hyg_4__value;
static const lean_string_object lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__3_00___x40_JunkValues_Frontend_3713897505____hygCtx___hyg_4__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 132, .m_capacity = 132, .m_length = 131, .m_data = "warn when a declaration uses an operation that collapses to a default value without the condition for that collapse being ruled out"};
static const lean_object* lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__3_00___x40_JunkValues_Frontend_3713897505____hygCtx___hyg_4_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__3_00___x40_JunkValues_Frontend_3713897505____hygCtx___hyg_4__value;
static const lean_ctor_object lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__4_00___x40_JunkValues_Frontend_3713897505____hygCtx___hyg_4__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*3 + 0, .m_other = 3, .m_tag = 0}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__3_00___x40_JunkValues_Frontend_3713897505____hygCtx___hyg_4__value),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__4_00___x40_JunkValues_Frontend_3713897505____hygCtx___hyg_4_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__4_00___x40_JunkValues_Frontend_3713897505____hygCtx___hyg_4__value;
static const lean_string_object lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__5_00___x40_JunkValues_Frontend_3713897505____hygCtx___hyg_4__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "JunkValues"};
static const lean_object* lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__5_00___x40_JunkValues_Frontend_3713897505____hygCtx___hyg_4_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__5_00___x40_JunkValues_Frontend_3713897505____hygCtx___hyg_4__value;
static const lean_ctor_object lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__6_00___x40_JunkValues_Frontend_3713897505____hygCtx___hyg_4__value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__5_00___x40_JunkValues_Frontend_3713897505____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(102, 249, 254, 203, 87, 211, 22, 147)}};
static const lean_ctor_object lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__6_00___x40_JunkValues_Frontend_3713897505____hygCtx___hyg_4__value_aux_1 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__6_00___x40_JunkValues_Frontend_3713897505____hygCtx___hyg_4__value_aux_0),((lean_object*)&lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__0_00___x40_JunkValues_Frontend_3713897505____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(59, 220, 141, 25, 53, 36, 15, 141)}};
static const lean_ctor_object lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__6_00___x40_JunkValues_Frontend_3713897505____hygCtx___hyg_4__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__6_00___x40_JunkValues_Frontend_3713897505____hygCtx___hyg_4__value_aux_1),((lean_object*)&lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__1_00___x40_JunkValues_Frontend_3713897505____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(70, 62, 173, 21, 98, 150, 200, 98)}};
static const lean_object* lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__6_00___x40_JunkValues_Frontend_3713897505____hygCtx___hyg_4_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__6_00___x40_JunkValues_Frontend_3713897505____hygCtx___hyg_4__value;
LEAN_EXPORT lean_object* lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn_00___x40_JunkValues_Frontend_3713897505____hygCtx___hyg_4_();
LEAN_EXPORT lean_object* lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn_00___x40_JunkValues_Frontend_3713897505____hygCtx___hyg_4____boxed(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_linter_junkValues;
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Option_register___at___00__private_JunkValues_Frontend_0__JunkValues_initFn_00___x40_JunkValues_Frontend_1659515862____hygCtx___hyg_4__spec__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Option_register___at___00__private_JunkValues_Frontend_0__JunkValues_initFn_00___x40_JunkValues_Frontend_1659515862____hygCtx___hyg_4__spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__0_00___x40_JunkValues_Frontend_1659515862____hygCtx___hyg_4__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "discharger"};
static const lean_object* lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__0_00___x40_JunkValues_Frontend_1659515862____hygCtx___hyg_4_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__0_00___x40_JunkValues_Frontend_1659515862____hygCtx___hyg_4__value;
static const lean_ctor_object lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__1_00___x40_JunkValues_Frontend_1659515862____hygCtx___hyg_4__value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__0_00___x40_JunkValues_Frontend_3713897505____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(186, 218, 113, 226, 101, 176, 32, 79)}};
static const lean_ctor_object lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__1_00___x40_JunkValues_Frontend_1659515862____hygCtx___hyg_4__value_aux_1 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__1_00___x40_JunkValues_Frontend_1659515862____hygCtx___hyg_4__value_aux_0),((lean_object*)&lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__1_00___x40_JunkValues_Frontend_3713897505____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(91, 223, 164, 59, 32, 198, 166, 116)}};
static const lean_ctor_object lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__1_00___x40_JunkValues_Frontend_1659515862____hygCtx___hyg_4__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__1_00___x40_JunkValues_Frontend_1659515862____hygCtx___hyg_4__value_aux_1),((lean_object*)&lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__0_00___x40_JunkValues_Frontend_1659515862____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(88, 170, 171, 251, 246, 237, 207, 19)}};
static const lean_object* lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__1_00___x40_JunkValues_Frontend_1659515862____hygCtx___hyg_4_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__1_00___x40_JunkValues_Frontend_1659515862____hygCtx___hyg_4__value;
static const lean_string_object lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__2_00___x40_JunkValues_Frontend_1659515862____hygCtx___hyg_4__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 1, .m_capacity = 1, .m_length = 0, .m_data = ""};
static const lean_object* lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__2_00___x40_JunkValues_Frontend_1659515862____hygCtx___hyg_4_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__2_00___x40_JunkValues_Frontend_1659515862____hygCtx___hyg_4__value;
static const lean_string_object lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__3_00___x40_JunkValues_Frontend_1659515862____hygCtx___hyg_4__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 338, .m_capacity = 338, .m_length = 331, .m_data = "alternative tactics for ruling out a junk value's condition, separated by `;;` and tried in order, each of which must close the goal by itself — e.g. `fun_prop ;; norm_num`. Empty means hypothesis lookup only. Tactics must exist in the file being checked; see `Frontend.lean` for why this is a list rather than one `first | … | …`."};
static const lean_object* lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__3_00___x40_JunkValues_Frontend_1659515862____hygCtx___hyg_4_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__3_00___x40_JunkValues_Frontend_1659515862____hygCtx___hyg_4__value;
static const lean_ctor_object lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__4_00___x40_JunkValues_Frontend_1659515862____hygCtx___hyg_4__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*3 + 0, .m_other = 3, .m_tag = 0}, .m_objs = {((lean_object*)&lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__2_00___x40_JunkValues_Frontend_1659515862____hygCtx___hyg_4__value),((lean_object*)&lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__3_00___x40_JunkValues_Frontend_1659515862____hygCtx___hyg_4__value),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__4_00___x40_JunkValues_Frontend_1659515862____hygCtx___hyg_4_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__4_00___x40_JunkValues_Frontend_1659515862____hygCtx___hyg_4__value;
static const lean_ctor_object lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__5_00___x40_JunkValues_Frontend_1659515862____hygCtx___hyg_4__value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__5_00___x40_JunkValues_Frontend_3713897505____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(102, 249, 254, 203, 87, 211, 22, 147)}};
static const lean_ctor_object lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__5_00___x40_JunkValues_Frontend_1659515862____hygCtx___hyg_4__value_aux_1 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__5_00___x40_JunkValues_Frontend_1659515862____hygCtx___hyg_4__value_aux_0),((lean_object*)&lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__0_00___x40_JunkValues_Frontend_3713897505____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(59, 220, 141, 25, 53, 36, 15, 141)}};
static const lean_ctor_object lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__5_00___x40_JunkValues_Frontend_1659515862____hygCtx___hyg_4__value_aux_2 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__5_00___x40_JunkValues_Frontend_1659515862____hygCtx___hyg_4__value_aux_1),((lean_object*)&lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__1_00___x40_JunkValues_Frontend_3713897505____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(70, 62, 173, 21, 98, 150, 200, 98)}};
static const lean_ctor_object lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__5_00___x40_JunkValues_Frontend_1659515862____hygCtx___hyg_4__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__5_00___x40_JunkValues_Frontend_1659515862____hygCtx___hyg_4__value_aux_2),((lean_object*)&lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__0_00___x40_JunkValues_Frontend_1659515862____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(73, 201, 171, 165, 166, 46, 244, 153)}};
static const lean_object* lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__5_00___x40_JunkValues_Frontend_1659515862____hygCtx___hyg_4_ = (const lean_object*)&lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__5_00___x40_JunkValues_Frontend_1659515862____hygCtx___hyg_4__value;
LEAN_EXPORT lean_object* lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn_00___x40_JunkValues_Frontend_1659515862____hygCtx___hyg_4_();
LEAN_EXPORT lean_object* lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn_00___x40_JunkValues_Frontend_1659515862____hygCtx___hyg_4____boxed(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_linter_junkValues_discharger;
static const lean_string_object lp_JunkValues_JunkValues_dischargerSeparator___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = ";;"};
static const lean_object* lp_JunkValues_JunkValues_dischargerSeparator___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_dischargerSeparator___closed__0_value;
LEAN_EXPORT const lean_object* lp_JunkValues_JunkValues_dischargerSeparator = (const lean_object*)&lp_JunkValues_JunkValues_dischargerSeparator___closed__0_value;
LEAN_EXPORT lean_object* lp_JunkValues_List_forIn_x27_loop___at___00JunkValues_dischargerOf_spec__2___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_List_forIn_x27_loop___at___00JunkValues_dischargerOf_spec__2___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_List_filterTR_loop___at___00JunkValues_dischargerOf_spec__1(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_List_mapTR_loop___at___00JunkValues_dischargerOf_spec__0(lean_object*, lean_object*);
static lean_once_cell_t lp_JunkValues_JunkValues_dischargerOf___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_dischargerOf___closed__0;
static const lean_array_object lp_JunkValues_JunkValues_dischargerOf___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* lp_JunkValues_JunkValues_dischargerOf___closed__1 = (const lean_object*)&lp_JunkValues_JunkValues_dischargerOf___closed__1_value;
static lean_once_cell_t lp_JunkValues_JunkValues_dischargerOf___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_dischargerOf___closed__2;
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_dischargerOf(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_dischargerOf___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_List_forIn_x27_loop___at___00JunkValues_dischargerOf_spec__2(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_List_forIn_x27_loop___at___00JunkValues_dischargerOf_spec__2___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Option_get___at___00JunkValues_setupOf_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Option_get___at___00JunkValues_setupOf_spec__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_setupOf(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_setupOf___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_JunkValues___private_Init_Data_Array_Basic_0__Array_anyMUnsafe_any___at___00Array_contains___at___00JunkValues_declIdsOf_spec__0_spec__0(lean_object*, lean_object*, size_t, size_t);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_anyMUnsafe_any___at___00Array_contains___at___00JunkValues_declIdsOf_spec__0_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_JunkValues_Array_contains___at___00JunkValues_declIdsOf_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Array_contains___at___00JunkValues_declIdsOf_spec__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_JunkValues___private_Init_Data_Array_Basic_0__Array_anyMUnsafe_any___at___00JunkValues_declIdsOf_spec__1(lean_object*, lean_object*, size_t, size_t);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_anyMUnsafe_any___at___00JunkValues_declIdsOf_spec__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_declIdsOf___lam__0(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_declIdsOf___lam__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Lean_Data_PersistentHashMap_0__Lean_PersistentHashMap_foldlMAux_traverse___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2_spec__3_spec__4_spec__8___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Lean_Data_PersistentHashMap_0__Lean_PersistentHashMap_foldlMAux_traverse___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2_spec__3_spec__4_spec__8___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2_spec__3_spec__4___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2_spec__3_spec__4_spec__7___redArg(lean_object*, lean_object*, size_t, size_t, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2_spec__3_spec__4_spec__7___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2_spec__3_spec__4___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2___redArg___lam__0(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2___redArg___lam__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_declIdsOf_spec__3___redArg(lean_object*, uint8_t, lean_object*, size_t, size_t, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_declIdsOf_spec__3___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object lp_JunkValues_Lean_Syntax_instForInTopDownOfMonad_loop___at___00Lean_Syntax_instForInTopDownOfMonad_loop___at___00JunkValues_declIdsOf_spec__4_spec__6___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "choice"};
static const lean_object* lp_JunkValues_Lean_Syntax_instForInTopDownOfMonad_loop___at___00Lean_Syntax_instForInTopDownOfMonad_loop___at___00JunkValues_declIdsOf_spec__4_spec__6___closed__0 = (const lean_object*)&lp_JunkValues_Lean_Syntax_instForInTopDownOfMonad_loop___at___00Lean_Syntax_instForInTopDownOfMonad_loop___at___00JunkValues_declIdsOf_spec__4_spec__6___closed__0_value;
static const lean_ctor_object lp_JunkValues_Lean_Syntax_instForInTopDownOfMonad_loop___at___00Lean_Syntax_instForInTopDownOfMonad_loop___at___00JunkValues_declIdsOf_spec__4_spec__6___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_Lean_Syntax_instForInTopDownOfMonad_loop___at___00Lean_Syntax_instForInTopDownOfMonad_loop___at___00JunkValues_declIdsOf_spec__4_spec__6___closed__0_value),LEAN_SCALAR_PTR_LITERAL(59, 66, 148, 42, 181, 100, 85, 166)}};
static const lean_object* lp_JunkValues_Lean_Syntax_instForInTopDownOfMonad_loop___at___00Lean_Syntax_instForInTopDownOfMonad_loop___at___00JunkValues_declIdsOf_spec__4_spec__6___closed__1 = (const lean_object*)&lp_JunkValues_Lean_Syntax_instForInTopDownOfMonad_loop___at___00Lean_Syntax_instForInTopDownOfMonad_loop___at___00JunkValues_declIdsOf_spec__4_spec__6___closed__1_value;
static const lean_string_object lp_JunkValues_Lean_Syntax_instForInTopDownOfMonad_loop___at___00Lean_Syntax_instForInTopDownOfMonad_loop___at___00JunkValues_declIdsOf_spec__4_spec__6___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "declId"};
static const lean_object* lp_JunkValues_Lean_Syntax_instForInTopDownOfMonad_loop___at___00Lean_Syntax_instForInTopDownOfMonad_loop___at___00JunkValues_declIdsOf_spec__4_spec__6___closed__5 = (const lean_object*)&lp_JunkValues_Lean_Syntax_instForInTopDownOfMonad_loop___at___00Lean_Syntax_instForInTopDownOfMonad_loop___at___00JunkValues_declIdsOf_spec__4_spec__6___closed__5_value;
static const lean_string_object lp_JunkValues_Lean_Syntax_instForInTopDownOfMonad_loop___at___00Lean_Syntax_instForInTopDownOfMonad_loop___at___00JunkValues_declIdsOf_spec__4_spec__6___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "Command"};
static const lean_object* lp_JunkValues_Lean_Syntax_instForInTopDownOfMonad_loop___at___00Lean_Syntax_instForInTopDownOfMonad_loop___at___00JunkValues_declIdsOf_spec__4_spec__6___closed__4 = (const lean_object*)&lp_JunkValues_Lean_Syntax_instForInTopDownOfMonad_loop___at___00Lean_Syntax_instForInTopDownOfMonad_loop___at___00JunkValues_declIdsOf_spec__4_spec__6___closed__4_value;
static const lean_string_object lp_JunkValues_Lean_Syntax_instForInTopDownOfMonad_loop___at___00Lean_Syntax_instForInTopDownOfMonad_loop___at___00JunkValues_declIdsOf_spec__4_spec__6___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "Parser"};
static const lean_object* lp_JunkValues_Lean_Syntax_instForInTopDownOfMonad_loop___at___00Lean_Syntax_instForInTopDownOfMonad_loop___at___00JunkValues_declIdsOf_spec__4_spec__6___closed__3 = (const lean_object*)&lp_JunkValues_Lean_Syntax_instForInTopDownOfMonad_loop___at___00Lean_Syntax_instForInTopDownOfMonad_loop___at___00JunkValues_declIdsOf_spec__4_spec__6___closed__3_value;
static const lean_string_object lp_JunkValues_Lean_Syntax_instForInTopDownOfMonad_loop___at___00Lean_Syntax_instForInTopDownOfMonad_loop___at___00JunkValues_declIdsOf_spec__4_spec__6___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "Lean"};
static const lean_object* lp_JunkValues_Lean_Syntax_instForInTopDownOfMonad_loop___at___00Lean_Syntax_instForInTopDownOfMonad_loop___at___00JunkValues_declIdsOf_spec__4_spec__6___closed__2 = (const lean_object*)&lp_JunkValues_Lean_Syntax_instForInTopDownOfMonad_loop___at___00Lean_Syntax_instForInTopDownOfMonad_loop___at___00JunkValues_declIdsOf_spec__4_spec__6___closed__2_value;
static const lean_ctor_object lp_JunkValues_Lean_Syntax_instForInTopDownOfMonad_loop___at___00Lean_Syntax_instForInTopDownOfMonad_loop___at___00JunkValues_declIdsOf_spec__4_spec__6___closed__6_value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues_Lean_Syntax_instForInTopDownOfMonad_loop___at___00Lean_Syntax_instForInTopDownOfMonad_loop___at___00JunkValues_declIdsOf_spec__4_spec__6___closed__2_value),LEAN_SCALAR_PTR_LITERAL(70, 193, 83, 126, 233, 67, 208, 165)}};
static const lean_ctor_object lp_JunkValues_Lean_Syntax_instForInTopDownOfMonad_loop___at___00Lean_Syntax_instForInTopDownOfMonad_loop___at___00JunkValues_declIdsOf_spec__4_spec__6___closed__6_value_aux_1 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues_Lean_Syntax_instForInTopDownOfMonad_loop___at___00Lean_Syntax_instForInTopDownOfMonad_loop___at___00JunkValues_declIdsOf_spec__4_spec__6___closed__6_value_aux_0),((lean_object*)&lp_JunkValues_Lean_Syntax_instForInTopDownOfMonad_loop___at___00Lean_Syntax_instForInTopDownOfMonad_loop___at___00JunkValues_declIdsOf_spec__4_spec__6___closed__3_value),LEAN_SCALAR_PTR_LITERAL(103, 136, 125, 166, 167, 98, 71, 111)}};
static const lean_ctor_object lp_JunkValues_Lean_Syntax_instForInTopDownOfMonad_loop___at___00Lean_Syntax_instForInTopDownOfMonad_loop___at___00JunkValues_declIdsOf_spec__4_spec__6___closed__6_value_aux_2 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues_Lean_Syntax_instForInTopDownOfMonad_loop___at___00Lean_Syntax_instForInTopDownOfMonad_loop___at___00JunkValues_declIdsOf_spec__4_spec__6___closed__6_value_aux_1),((lean_object*)&lp_JunkValues_Lean_Syntax_instForInTopDownOfMonad_loop___at___00Lean_Syntax_instForInTopDownOfMonad_loop___at___00JunkValues_declIdsOf_spec__4_spec__6___closed__4_value),LEAN_SCALAR_PTR_LITERAL(214, 208, 105, 11, 221, 56, 173, 240)}};
static const lean_ctor_object lp_JunkValues_Lean_Syntax_instForInTopDownOfMonad_loop___at___00Lean_Syntax_instForInTopDownOfMonad_loop___at___00JunkValues_declIdsOf_spec__4_spec__6___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues_Lean_Syntax_instForInTopDownOfMonad_loop___at___00Lean_Syntax_instForInTopDownOfMonad_loop___at___00JunkValues_declIdsOf_spec__4_spec__6___closed__6_value_aux_2),((lean_object*)&lp_JunkValues_Lean_Syntax_instForInTopDownOfMonad_loop___at___00Lean_Syntax_instForInTopDownOfMonad_loop___at___00JunkValues_declIdsOf_spec__4_spec__6___closed__5_value),LEAN_SCALAR_PTR_LITERAL(243, 92, 136, 33, 216, 98, 92, 25)}};
static const lean_object* lp_JunkValues_Lean_Syntax_instForInTopDownOfMonad_loop___at___00Lean_Syntax_instForInTopDownOfMonad_loop___at___00JunkValues_declIdsOf_spec__4_spec__6___closed__6 = (const lean_object*)&lp_JunkValues_Lean_Syntax_instForInTopDownOfMonad_loop___at___00Lean_Syntax_instForInTopDownOfMonad_loop___at___00JunkValues_declIdsOf_spec__4_spec__6___closed__6_value;
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Syntax_instForInTopDownOfMonad_loop___at___00Lean_Syntax_instForInTopDownOfMonad_loop___at___00JunkValues_declIdsOf_spec__4_spec__6(lean_object*, lean_object*, uint8_t, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Syntax_instForInTopDownOfMonad_loop___at___00JunkValues_declIdsOf_spec__4_spec__7(lean_object*, lean_object*, uint8_t, lean_object*, size_t, size_t, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Syntax_instForInTopDownOfMonad_loop___at___00JunkValues_declIdsOf_spec__4_spec__7___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Syntax_instForInTopDownOfMonad_loop___at___00Lean_Syntax_instForInTopDownOfMonad_loop___at___00JunkValues_declIdsOf_spec__4_spec__6___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Syntax_instForInTopDownOfMonad_loop___at___00JunkValues_declIdsOf_spec__4(lean_object*, lean_object*, uint8_t, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Syntax_instForInTopDownOfMonad_loop___at___00JunkValues_declIdsOf_spec__4___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_array_object lp_JunkValues_JunkValues_declIdsOf___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* lp_JunkValues_JunkValues_declIdsOf___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_declIdsOf___closed__0_value;
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_declIdsOf(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_declIdsOf___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_declIdsOf_spec__3(lean_object*, uint8_t, lean_object*, size_t, size_t, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_declIdsOf_spec__3___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2_spec__3___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2_spec__3___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2_spec__3(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2_spec__3___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2_spec__3_spec__4(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2_spec__3_spec__4___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2_spec__3_spec__4_spec__7(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, size_t, size_t, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2_spec__3_spec__4_spec__7___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Lean_Data_PersistentHashMap_0__Lean_PersistentHashMap_foldlMAux_traverse___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2_spec__3_spec__4_spec__8(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Lean_Data_PersistentHashMap_0__Lean_PersistentHashMap_foldlMAux_traverse___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2_spec__3_spec__4_spec__8___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object lp_JunkValues_JunkValues_warningOf___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 12, .m_capacity = 12, .m_length = 11, .m_data = "junk value "};
static const lean_object* lp_JunkValues_JunkValues_warningOf___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_warningOf___closed__0_value;
static lean_once_cell_t lp_JunkValues_JunkValues_warningOf___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_warningOf___closed__1;
static const lean_string_object lp_JunkValues_JunkValues_warningOf___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = " `"};
static const lean_object* lp_JunkValues_JunkValues_warningOf___closed__2 = (const lean_object*)&lp_JunkValues_JunkValues_warningOf___closed__2_value;
static lean_once_cell_t lp_JunkValues_JunkValues_warningOf___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_warningOf___closed__3;
static const lean_string_object lp_JunkValues_JunkValues_warningOf___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "`: "};
static const lean_object* lp_JunkValues_JunkValues_warningOf___closed__4 = (const lean_object*)&lp_JunkValues_JunkValues_warningOf___closed__4_value;
static lean_once_cell_t lp_JunkValues_JunkValues_warningOf___closed__5_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_warningOf___closed__5;
static const lean_string_object lp_JunkValues_JunkValues_warningOf___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 20, .m_capacity = 20, .m_length = 19, .m_data = "in the statement of"};
static const lean_object* lp_JunkValues_JunkValues_warningOf___closed__6 = (const lean_object*)&lp_JunkValues_JunkValues_warningOf___closed__6_value;
static const lean_string_object lp_JunkValues_JunkValues_warningOf___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 21, .m_capacity = 21, .m_length = 20, .m_data = "in the definition of"};
static const lean_object* lp_JunkValues_JunkValues_warningOf___closed__7 = (const lean_object*)&lp_JunkValues_JunkValues_warningOf___closed__7_value;
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_warningOf(lean_object*);
LEAN_EXPORT uint8_t lp_JunkValues_Lean_Option_get___at___00JunkValues_junkValuesLinter_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Option_get___at___00JunkValues_junkValuesLinter_spec__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_addMessageContextFull___at___00Lean_logAt___at___00Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1_spec__2_spec__6(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_addMessageContextFull___at___00Lean_logAt___at___00Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1_spec__2_spec__6___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object lp_JunkValues_Lean_logAt___at___00Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1_spec__2___redArg___lam__0___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "Elab"};
static const lean_object* lp_JunkValues_Lean_logAt___at___00Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1_spec__2___redArg___lam__0___closed__0 = (const lean_object*)&lp_JunkValues_Lean_logAt___at___00Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1_spec__2___redArg___lam__0___closed__0_value;
static const lean_string_object lp_JunkValues_Lean_logAt___at___00Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1_spec__2___redArg___lam__0___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "Tactic"};
static const lean_object* lp_JunkValues_Lean_logAt___at___00Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1_spec__2___redArg___lam__0___closed__1 = (const lean_object*)&lp_JunkValues_Lean_logAt___at___00Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1_spec__2___redArg___lam__0___closed__1_value;
static const lean_string_object lp_JunkValues_Lean_logAt___at___00Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1_spec__2___redArg___lam__0___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 14, .m_capacity = 14, .m_length = 13, .m_data = "unsolvedGoals"};
static const lean_object* lp_JunkValues_Lean_logAt___at___00Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1_spec__2___redArg___lam__0___closed__2 = (const lean_object*)&lp_JunkValues_Lean_logAt___at___00Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1_spec__2___redArg___lam__0___closed__2_value;
static const lean_string_object lp_JunkValues_Lean_logAt___at___00Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1_spec__2___redArg___lam__0___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 17, .m_capacity = 17, .m_length = 16, .m_data = "synthPlaceholder"};
static const lean_object* lp_JunkValues_Lean_logAt___at___00Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1_spec__2___redArg___lam__0___closed__3 = (const lean_object*)&lp_JunkValues_Lean_logAt___at___00Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1_spec__2___redArg___lam__0___closed__3_value;
static const lean_string_object lp_JunkValues_Lean_logAt___at___00Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1_spec__2___redArg___lam__0___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "lean"};
static const lean_object* lp_JunkValues_Lean_logAt___at___00Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1_spec__2___redArg___lam__0___closed__4 = (const lean_object*)&lp_JunkValues_Lean_logAt___at___00Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1_spec__2___redArg___lam__0___closed__4_value;
static const lean_string_object lp_JunkValues_Lean_logAt___at___00Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1_spec__2___redArg___lam__0___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 20, .m_capacity = 20, .m_length = 19, .m_data = "inductionWithNoAlts"};
static const lean_object* lp_JunkValues_Lean_logAt___at___00Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1_spec__2___redArg___lam__0___closed__5 = (const lean_object*)&lp_JunkValues_Lean_logAt___at___00Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1_spec__2___redArg___lam__0___closed__5_value;
static const lean_string_object lp_JunkValues_Lean_logAt___at___00Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1_spec__2___redArg___lam__0___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 12, .m_capacity = 12, .m_length = 11, .m_data = "_namedError"};
static const lean_object* lp_JunkValues_Lean_logAt___at___00Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1_spec__2___redArg___lam__0___closed__6 = (const lean_object*)&lp_JunkValues_Lean_logAt___at___00Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1_spec__2___redArg___lam__0___closed__6_value;
static const lean_string_object lp_JunkValues_Lean_logAt___at___00Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1_spec__2___redArg___lam__0___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "trace"};
static const lean_object* lp_JunkValues_Lean_logAt___at___00Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1_spec__2___redArg___lam__0___closed__7 = (const lean_object*)&lp_JunkValues_Lean_logAt___at___00Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1_spec__2___redArg___lam__0___closed__7_value;
LEAN_EXPORT uint8_t lp_JunkValues_Lean_logAt___at___00Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1_spec__2___redArg___lam__0(uint8_t, uint8_t, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_logAt___at___00Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1_spec__2___redArg___lam__0___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_logAt___at___00Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1_spec__2___redArg(lean_object*, lean_object*, uint8_t, uint8_t, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_logAt___at___00Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1_spec__2___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object lp_JunkValues_Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 46, .m_capacity = 46, .m_length = 45, .m_data = "This linter can be disabled with `set_option "};
static const lean_object* lp_JunkValues_Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1___closed__0 = (const lean_object*)&lp_JunkValues_Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1___closed__0_value;
static lean_once_cell_t lp_JunkValues_Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1___closed__1;
static const lean_string_object lp_JunkValues_Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = " false`"};
static const lean_object* lp_JunkValues_Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1___closed__2 = (const lean_object*)&lp_JunkValues_Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1___closed__2_value;
static lean_once_cell_t lp_JunkValues_Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1___closed__3;
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_junkValuesLinter_spec__3(lean_object*, lean_object*, size_t, size_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_junkValuesLinter_spec__3___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_junkValuesLinter_spec__2(lean_object*, lean_object*, size_t, size_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_junkValuesLinter_spec__2___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_junkValuesLinter_spec__4___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 2, .m_capacity = 2, .m_length = 1, .m_data = "`"};
static const lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_junkValuesLinter_spec__4___closed__0 = (const lean_object*)&lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_junkValuesLinter_spec__4___closed__0_value;
static lean_once_cell_t lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_junkValuesLinter_spec__4___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_junkValuesLinter_spec__4___closed__1;
static const lean_string_object lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_junkValuesLinter_spec__4___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 86, .m_capacity = 86, .m_length = 85, .m_data = "` has more junk-value occurrences than the scan's limit; the list above is incomplete"};
static const lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_junkValuesLinter_spec__4___closed__2 = (const lean_object*)&lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_junkValuesLinter_spec__4___closed__2_value;
static lean_once_cell_t lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_junkValuesLinter_spec__4___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_junkValuesLinter_spec__4___closed__3;
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_junkValuesLinter_spec__4(lean_object*, lean_object*, lean_object*, lean_object*, size_t, size_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_junkValuesLinter_spec__4___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_junkValuesLinter___lam__0(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_junkValuesLinter___lam__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_junkValuesLinter___lam__1(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_junkValuesLinter___lam__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_closure_object lp_JunkValues_JunkValues_junkValuesLinter___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_JunkValues_JunkValues_junkValuesLinter___lam__1___boxed, .m_arity = 4, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_JunkValues_JunkValues_junkValuesLinter___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_junkValuesLinter___closed__0_value;
static const lean_string_object lp_JunkValues_JunkValues_junkValuesLinter___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 17, .m_capacity = 17, .m_length = 16, .m_data = "junkValuesLinter"};
static const lean_object* lp_JunkValues_JunkValues_junkValuesLinter___closed__1 = (const lean_object*)&lp_JunkValues_JunkValues_junkValuesLinter___closed__1_value;
static const lean_ctor_object lp_JunkValues_JunkValues_junkValuesLinter___closed__2_value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__5_00___x40_JunkValues_Frontend_3713897505____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(102, 249, 254, 203, 87, 211, 22, 147)}};
static const lean_ctor_object lp_JunkValues_JunkValues_junkValuesLinter___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_junkValuesLinter___closed__2_value_aux_0),((lean_object*)&lp_JunkValues_JunkValues_junkValuesLinter___closed__1_value),LEAN_SCALAR_PTR_LITERAL(90, 188, 79, 229, 103, 100, 77, 24)}};
static const lean_object* lp_JunkValues_JunkValues_junkValuesLinter___closed__2 = (const lean_object*)&lp_JunkValues_JunkValues_junkValuesLinter___closed__2_value;
static const lean_ctor_object lp_JunkValues_JunkValues_junkValuesLinter___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_junkValuesLinter___closed__0_value),((lean_object*)&lp_JunkValues_JunkValues_junkValuesLinter___closed__2_value)}};
static const lean_object* lp_JunkValues_JunkValues_junkValuesLinter___closed__3 = (const lean_object*)&lp_JunkValues_JunkValues_junkValuesLinter___closed__3_value;
LEAN_EXPORT const lean_object* lp_JunkValues_JunkValues_junkValuesLinter = (const lean_object*)&lp_JunkValues_JunkValues_junkValuesLinter___closed__3_value;
LEAN_EXPORT lean_object* lp_JunkValues_Lean_logAt___at___00Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1_spec__2(lean_object*, lean_object*, uint8_t, uint8_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_logAt___at___00Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1_spec__2___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn_00___x40_JunkValues_Frontend_3445918356____hygCtx___hyg_2_();
LEAN_EXPORT lean_object* lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn_00___x40_JunkValues_Frontend_3445918356____hygCtx___hyg_2____boxed(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_projectDecls_spec__0(lean_object*, size_t, size_t, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_projectDecls_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00JunkValues_projectDecls_spec__1___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00JunkValues_projectDecls_spec__1___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_projectDecls(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_projectDecls___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00JunkValues_projectDecls_spec__1(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00JunkValues_projectDecls_spec__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_scanProject(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_scanProject___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Option_register___at___00__private_JunkValues_Frontend_0__JunkValues_initFn_00___x40_JunkValues_Frontend_3713897505____hygCtx___hyg_4__spec__0(lean_object* v_name_1_, lean_object* v_decl_2_, lean_object* v_ref_3_){
_start:
{
lean_object* v_defValue_5_; lean_object* v_descr_6_; lean_object* v_deprecation_x3f_7_; lean_object* v___x_8_; uint8_t v___x_9_; lean_object* v___x_10_; lean_object* v___x_11_; 
v_defValue_5_ = lean_ctor_get(v_decl_2_, 0);
v_descr_6_ = lean_ctor_get(v_decl_2_, 1);
v_deprecation_x3f_7_ = lean_ctor_get(v_decl_2_, 2);
v___x_8_ = lean_alloc_ctor(1, 0, 1);
v___x_9_ = lean_unbox(v_defValue_5_);
lean_ctor_set_uint8(v___x_8_, 0, v___x_9_);
lean_inc(v_deprecation_x3f_7_);
lean_inc_ref(v_descr_6_);
lean_inc_n(v_name_1_, 2);
v___x_10_ = lean_alloc_ctor(0, 5, 0);
lean_ctor_set(v___x_10_, 0, v_name_1_);
lean_ctor_set(v___x_10_, 1, v_ref_3_);
lean_ctor_set(v___x_10_, 2, v___x_8_);
lean_ctor_set(v___x_10_, 3, v_descr_6_);
lean_ctor_set(v___x_10_, 4, v_deprecation_x3f_7_);
v___x_11_ = lean_register_option(v_name_1_, v___x_10_);
if (lean_obj_tag(v___x_11_) == 0)
{
lean_object* v___x_13_; uint8_t v_isShared_14_; uint8_t v_isSharedCheck_19_; 
v_isSharedCheck_19_ = !lean_is_exclusive(v___x_11_);
if (v_isSharedCheck_19_ == 0)
{
lean_object* v_unused_20_; 
v_unused_20_ = lean_ctor_get(v___x_11_, 0);
lean_dec(v_unused_20_);
v___x_13_ = v___x_11_;
v_isShared_14_ = v_isSharedCheck_19_;
goto v_resetjp_12_;
}
else
{
lean_dec(v___x_11_);
v___x_13_ = lean_box(0);
v_isShared_14_ = v_isSharedCheck_19_;
goto v_resetjp_12_;
}
v_resetjp_12_:
{
lean_object* v___x_15_; lean_object* v___x_17_; 
lean_inc(v_defValue_5_);
v___x_15_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_15_, 0, v_name_1_);
lean_ctor_set(v___x_15_, 1, v_defValue_5_);
if (v_isShared_14_ == 0)
{
lean_ctor_set(v___x_13_, 0, v___x_15_);
v___x_17_ = v___x_13_;
goto v_reusejp_16_;
}
else
{
lean_object* v_reuseFailAlloc_18_; 
v_reuseFailAlloc_18_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_18_, 0, v___x_15_);
v___x_17_ = v_reuseFailAlloc_18_;
goto v_reusejp_16_;
}
v_reusejp_16_:
{
return v___x_17_;
}
}
}
else
{
lean_object* v_a_21_; lean_object* v___x_23_; uint8_t v_isShared_24_; uint8_t v_isSharedCheck_28_; 
lean_dec(v_name_1_);
v_a_21_ = lean_ctor_get(v___x_11_, 0);
v_isSharedCheck_28_ = !lean_is_exclusive(v___x_11_);
if (v_isSharedCheck_28_ == 0)
{
v___x_23_ = v___x_11_;
v_isShared_24_ = v_isSharedCheck_28_;
goto v_resetjp_22_;
}
else
{
lean_inc(v_a_21_);
lean_dec(v___x_11_);
v___x_23_ = lean_box(0);
v_isShared_24_ = v_isSharedCheck_28_;
goto v_resetjp_22_;
}
v_resetjp_22_:
{
lean_object* v___x_26_; 
if (v_isShared_24_ == 0)
{
v___x_26_ = v___x_23_;
goto v_reusejp_25_;
}
else
{
lean_object* v_reuseFailAlloc_27_; 
v_reuseFailAlloc_27_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_27_, 0, v_a_21_);
v___x_26_ = v_reuseFailAlloc_27_;
goto v_reusejp_25_;
}
v_reusejp_25_:
{
return v___x_26_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Option_register___at___00__private_JunkValues_Frontend_0__JunkValues_initFn_00___x40_JunkValues_Frontend_3713897505____hygCtx___hyg_4__spec__0___boxed(lean_object* v_name_29_, lean_object* v_decl_30_, lean_object* v_ref_31_, lean_object* v_a_32_){
_start:
{
lean_object* v_res_33_; 
v_res_33_ = lp_JunkValues_Lean_Option_register___at___00__private_JunkValues_Frontend_0__JunkValues_initFn_00___x40_JunkValues_Frontend_3713897505____hygCtx___hyg_4__spec__0(v_name_29_, v_decl_30_, v_ref_31_);
lean_dec_ref(v_decl_30_);
return v_res_33_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn_00___x40_JunkValues_Frontend_3713897505____hygCtx___hyg_4_(){
_start:
{
lean_object* v___x_51_; lean_object* v___x_52_; lean_object* v___x_53_; lean_object* v___x_54_; 
v___x_51_ = ((lean_object*)(lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__2_00___x40_JunkValues_Frontend_3713897505____hygCtx___hyg_4_));
v___x_52_ = ((lean_object*)(lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__4_00___x40_JunkValues_Frontend_3713897505____hygCtx___hyg_4_));
v___x_53_ = ((lean_object*)(lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__6_00___x40_JunkValues_Frontend_3713897505____hygCtx___hyg_4_));
v___x_54_ = lp_JunkValues_Lean_Option_register___at___00__private_JunkValues_Frontend_0__JunkValues_initFn_00___x40_JunkValues_Frontend_3713897505____hygCtx___hyg_4__spec__0(v___x_51_, v___x_52_, v___x_53_);
return v___x_54_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn_00___x40_JunkValues_Frontend_3713897505____hygCtx___hyg_4____boxed(lean_object* v_a_55_){
_start:
{
lean_object* v_res_56_; 
v_res_56_ = lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn_00___x40_JunkValues_Frontend_3713897505____hygCtx___hyg_4_();
return v_res_56_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Option_register___at___00__private_JunkValues_Frontend_0__JunkValues_initFn_00___x40_JunkValues_Frontend_1659515862____hygCtx___hyg_4__spec__0(lean_object* v_name_57_, lean_object* v_decl_58_, lean_object* v_ref_59_){
_start:
{
lean_object* v_defValue_61_; lean_object* v_descr_62_; lean_object* v_deprecation_x3f_63_; lean_object* v___x_64_; lean_object* v___x_65_; lean_object* v___x_66_; 
v_defValue_61_ = lean_ctor_get(v_decl_58_, 0);
v_descr_62_ = lean_ctor_get(v_decl_58_, 1);
v_deprecation_x3f_63_ = lean_ctor_get(v_decl_58_, 2);
lean_inc(v_defValue_61_);
v___x_64_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_64_, 0, v_defValue_61_);
lean_inc(v_deprecation_x3f_63_);
lean_inc_ref(v_descr_62_);
lean_inc_n(v_name_57_, 2);
v___x_65_ = lean_alloc_ctor(0, 5, 0);
lean_ctor_set(v___x_65_, 0, v_name_57_);
lean_ctor_set(v___x_65_, 1, v_ref_59_);
lean_ctor_set(v___x_65_, 2, v___x_64_);
lean_ctor_set(v___x_65_, 3, v_descr_62_);
lean_ctor_set(v___x_65_, 4, v_deprecation_x3f_63_);
v___x_66_ = lean_register_option(v_name_57_, v___x_65_);
if (lean_obj_tag(v___x_66_) == 0)
{
lean_object* v___x_68_; uint8_t v_isShared_69_; uint8_t v_isSharedCheck_74_; 
v_isSharedCheck_74_ = !lean_is_exclusive(v___x_66_);
if (v_isSharedCheck_74_ == 0)
{
lean_object* v_unused_75_; 
v_unused_75_ = lean_ctor_get(v___x_66_, 0);
lean_dec(v_unused_75_);
v___x_68_ = v___x_66_;
v_isShared_69_ = v_isSharedCheck_74_;
goto v_resetjp_67_;
}
else
{
lean_dec(v___x_66_);
v___x_68_ = lean_box(0);
v_isShared_69_ = v_isSharedCheck_74_;
goto v_resetjp_67_;
}
v_resetjp_67_:
{
lean_object* v___x_70_; lean_object* v___x_72_; 
lean_inc(v_defValue_61_);
v___x_70_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_70_, 0, v_name_57_);
lean_ctor_set(v___x_70_, 1, v_defValue_61_);
if (v_isShared_69_ == 0)
{
lean_ctor_set(v___x_68_, 0, v___x_70_);
v___x_72_ = v___x_68_;
goto v_reusejp_71_;
}
else
{
lean_object* v_reuseFailAlloc_73_; 
v_reuseFailAlloc_73_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_73_, 0, v___x_70_);
v___x_72_ = v_reuseFailAlloc_73_;
goto v_reusejp_71_;
}
v_reusejp_71_:
{
return v___x_72_;
}
}
}
else
{
lean_object* v_a_76_; lean_object* v___x_78_; uint8_t v_isShared_79_; uint8_t v_isSharedCheck_83_; 
lean_dec(v_name_57_);
v_a_76_ = lean_ctor_get(v___x_66_, 0);
v_isSharedCheck_83_ = !lean_is_exclusive(v___x_66_);
if (v_isSharedCheck_83_ == 0)
{
v___x_78_ = v___x_66_;
v_isShared_79_ = v_isSharedCheck_83_;
goto v_resetjp_77_;
}
else
{
lean_inc(v_a_76_);
lean_dec(v___x_66_);
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
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Option_register___at___00__private_JunkValues_Frontend_0__JunkValues_initFn_00___x40_JunkValues_Frontend_1659515862____hygCtx___hyg_4__spec__0___boxed(lean_object* v_name_84_, lean_object* v_decl_85_, lean_object* v_ref_86_, lean_object* v_a_87_){
_start:
{
lean_object* v_res_88_; 
v_res_88_ = lp_JunkValues_Lean_Option_register___at___00__private_JunkValues_Frontend_0__JunkValues_initFn_00___x40_JunkValues_Frontend_1659515862____hygCtx___hyg_4__spec__0(v_name_84_, v_decl_85_, v_ref_86_);
lean_dec_ref(v_decl_85_);
return v_res_88_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn_00___x40_JunkValues_Frontend_1659515862____hygCtx___hyg_4_(){
_start:
{
lean_object* v___x_106_; lean_object* v___x_107_; lean_object* v___x_108_; lean_object* v___x_109_; 
v___x_106_ = ((lean_object*)(lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__1_00___x40_JunkValues_Frontend_1659515862____hygCtx___hyg_4_));
v___x_107_ = ((lean_object*)(lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__4_00___x40_JunkValues_Frontend_1659515862____hygCtx___hyg_4_));
v___x_108_ = ((lean_object*)(lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__5_00___x40_JunkValues_Frontend_1659515862____hygCtx___hyg_4_));
v___x_109_ = lp_JunkValues_Lean_Option_register___at___00__private_JunkValues_Frontend_0__JunkValues_initFn_00___x40_JunkValues_Frontend_1659515862____hygCtx___hyg_4__spec__0(v___x_106_, v___x_107_, v___x_108_);
return v___x_109_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn_00___x40_JunkValues_Frontend_1659515862____hygCtx___hyg_4____boxed(lean_object* v_a_110_){
_start:
{
lean_object* v_res_111_; 
v_res_111_ = lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn_00___x40_JunkValues_Frontend_1659515862____hygCtx___hyg_4_();
return v_res_111_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_List_forIn_x27_loop___at___00JunkValues_dischargerOf_spec__2___redArg(lean_object* v_as_x27_114_, lean_object* v_b_115_, lean_object* v___y_116_){
_start:
{
if (lean_obj_tag(v_as_x27_114_) == 0)
{
lean_object* v___x_118_; 
v___x_118_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_118_, 0, v_b_115_);
return v___x_118_;
}
else
{
lean_object* v_head_119_; lean_object* v_tail_120_; lean_object* v___x_121_; 
v_head_119_ = lean_ctor_get(v_as_x27_114_, 0);
v_tail_120_ = lean_ctor_get(v_as_x27_114_, 1);
lean_inc(v_head_119_);
v___x_121_ = lp_JunkValues_JunkValues_tacticDischarger_x3f___redArg(v_head_119_, v___y_116_);
if (lean_obj_tag(v___x_121_) == 0)
{
lean_object* v_a_122_; 
v_a_122_ = lean_ctor_get(v___x_121_, 0);
lean_inc(v_a_122_);
lean_dec_ref_known(v___x_121_, 1);
if (lean_obj_tag(v_a_122_) == 0)
{
lean_object* v_fst_123_; lean_object* v_snd_124_; lean_object* v___x_126_; uint8_t v_isShared_127_; uint8_t v_isSharedCheck_134_; 
v_fst_123_ = lean_ctor_get(v_b_115_, 0);
v_snd_124_ = lean_ctor_get(v_b_115_, 1);
v_isSharedCheck_134_ = !lean_is_exclusive(v_b_115_);
if (v_isSharedCheck_134_ == 0)
{
v___x_126_ = v_b_115_;
v_isShared_127_ = v_isSharedCheck_134_;
goto v_resetjp_125_;
}
else
{
lean_inc(v_snd_124_);
lean_inc(v_fst_123_);
lean_dec(v_b_115_);
v___x_126_ = lean_box(0);
v_isShared_127_ = v_isSharedCheck_134_;
goto v_resetjp_125_;
}
v_resetjp_125_:
{
lean_object* v_a_128_; lean_object* v___x_129_; lean_object* v___x_131_; 
v_a_128_ = lean_ctor_get(v_a_122_, 0);
lean_inc(v_a_128_);
lean_dec_ref_known(v_a_122_, 1);
v___x_129_ = lean_array_push(v_snd_124_, v_a_128_);
if (v_isShared_127_ == 0)
{
lean_ctor_set(v___x_126_, 1, v___x_129_);
v___x_131_ = v___x_126_;
goto v_reusejp_130_;
}
else
{
lean_object* v_reuseFailAlloc_133_; 
v_reuseFailAlloc_133_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_133_, 0, v_fst_123_);
lean_ctor_set(v_reuseFailAlloc_133_, 1, v___x_129_);
v___x_131_ = v_reuseFailAlloc_133_;
goto v_reusejp_130_;
}
v_reusejp_130_:
{
v_as_x27_114_ = v_tail_120_;
v_b_115_ = v___x_131_;
goto _start;
}
}
}
else
{
lean_object* v_fst_135_; lean_object* v_snd_136_; lean_object* v___x_138_; uint8_t v_isShared_139_; uint8_t v_isSharedCheck_146_; 
v_fst_135_ = lean_ctor_get(v_b_115_, 0);
v_snd_136_ = lean_ctor_get(v_b_115_, 1);
v_isSharedCheck_146_ = !lean_is_exclusive(v_b_115_);
if (v_isSharedCheck_146_ == 0)
{
v___x_138_ = v_b_115_;
v_isShared_139_ = v_isSharedCheck_146_;
goto v_resetjp_137_;
}
else
{
lean_inc(v_snd_136_);
lean_inc(v_fst_135_);
lean_dec(v_b_115_);
v___x_138_ = lean_box(0);
v_isShared_139_ = v_isSharedCheck_146_;
goto v_resetjp_137_;
}
v_resetjp_137_:
{
lean_object* v_a_140_; lean_object* v___x_141_; lean_object* v___x_143_; 
v_a_140_ = lean_ctor_get(v_a_122_, 0);
lean_inc(v_a_140_);
lean_dec_ref_known(v_a_122_, 1);
v___x_141_ = lean_array_push(v_fst_135_, v_a_140_);
if (v_isShared_139_ == 0)
{
lean_ctor_set(v___x_138_, 0, v___x_141_);
v___x_143_ = v___x_138_;
goto v_reusejp_142_;
}
else
{
lean_object* v_reuseFailAlloc_145_; 
v_reuseFailAlloc_145_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_145_, 0, v___x_141_);
lean_ctor_set(v_reuseFailAlloc_145_, 1, v_snd_136_);
v___x_143_ = v_reuseFailAlloc_145_;
goto v_reusejp_142_;
}
v_reusejp_142_:
{
v_as_x27_114_ = v_tail_120_;
v_b_115_ = v___x_143_;
goto _start;
}
}
}
}
else
{
lean_object* v_a_147_; lean_object* v___x_149_; uint8_t v_isShared_150_; uint8_t v_isSharedCheck_154_; 
lean_dec_ref(v_b_115_);
v_a_147_ = lean_ctor_get(v___x_121_, 0);
v_isSharedCheck_154_ = !lean_is_exclusive(v___x_121_);
if (v_isSharedCheck_154_ == 0)
{
v___x_149_ = v___x_121_;
v_isShared_150_ = v_isSharedCheck_154_;
goto v_resetjp_148_;
}
else
{
lean_inc(v_a_147_);
lean_dec(v___x_121_);
v___x_149_ = lean_box(0);
v_isShared_150_ = v_isSharedCheck_154_;
goto v_resetjp_148_;
}
v_resetjp_148_:
{
lean_object* v___x_152_; 
if (v_isShared_150_ == 0)
{
v___x_152_ = v___x_149_;
goto v_reusejp_151_;
}
else
{
lean_object* v_reuseFailAlloc_153_; 
v_reuseFailAlloc_153_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_153_, 0, v_a_147_);
v___x_152_ = v_reuseFailAlloc_153_;
goto v_reusejp_151_;
}
v_reusejp_151_:
{
return v___x_152_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_List_forIn_x27_loop___at___00JunkValues_dischargerOf_spec__2___redArg___boxed(lean_object* v_as_x27_155_, lean_object* v_b_156_, lean_object* v___y_157_, lean_object* v___y_158_){
_start:
{
lean_object* v_res_159_; 
v_res_159_ = lp_JunkValues_List_forIn_x27_loop___at___00JunkValues_dischargerOf_spec__2___redArg(v_as_x27_155_, v_b_156_, v___y_157_);
lean_dec(v___y_157_);
lean_dec(v_as_x27_155_);
return v_res_159_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_List_filterTR_loop___at___00JunkValues_dischargerOf_spec__1(lean_object* v_a_160_, lean_object* v_a_161_){
_start:
{
if (lean_obj_tag(v_a_160_) == 0)
{
lean_object* v___x_162_; 
v___x_162_ = l_List_reverse___redArg(v_a_161_);
return v___x_162_;
}
else
{
lean_object* v_head_163_; lean_object* v_tail_164_; lean_object* v___x_166_; uint8_t v_isShared_167_; uint8_t v_isSharedCheck_176_; 
v_head_163_ = lean_ctor_get(v_a_160_, 0);
v_tail_164_ = lean_ctor_get(v_a_160_, 1);
v_isSharedCheck_176_ = !lean_is_exclusive(v_a_160_);
if (v_isSharedCheck_176_ == 0)
{
v___x_166_ = v_a_160_;
v_isShared_167_ = v_isSharedCheck_176_;
goto v_resetjp_165_;
}
else
{
lean_inc(v_tail_164_);
lean_inc(v_head_163_);
lean_dec(v_a_160_);
v___x_166_ = lean_box(0);
v_isShared_167_ = v_isSharedCheck_176_;
goto v_resetjp_165_;
}
v_resetjp_165_:
{
lean_object* v___x_168_; lean_object* v___x_169_; uint8_t v___x_170_; 
v___x_168_ = lean_string_utf8_byte_size(v_head_163_);
v___x_169_ = lean_unsigned_to_nat(0u);
v___x_170_ = lean_nat_dec_eq(v___x_168_, v___x_169_);
if (v___x_170_ == 0)
{
lean_object* v___x_172_; 
if (v_isShared_167_ == 0)
{
lean_ctor_set(v___x_166_, 1, v_a_161_);
v___x_172_ = v___x_166_;
goto v_reusejp_171_;
}
else
{
lean_object* v_reuseFailAlloc_174_; 
v_reuseFailAlloc_174_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_174_, 0, v_head_163_);
lean_ctor_set(v_reuseFailAlloc_174_, 1, v_a_161_);
v___x_172_ = v_reuseFailAlloc_174_;
goto v_reusejp_171_;
}
v_reusejp_171_:
{
v_a_160_ = v_tail_164_;
v_a_161_ = v___x_172_;
goto _start;
}
}
else
{
lean_del_object(v___x_166_);
lean_dec(v_head_163_);
v_a_160_ = v_tail_164_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_List_mapTR_loop___at___00JunkValues_dischargerOf_spec__0(lean_object* v_a_177_, lean_object* v_a_178_){
_start:
{
if (lean_obj_tag(v_a_177_) == 0)
{
lean_object* v___x_179_; 
v___x_179_ = l_List_reverse___redArg(v_a_178_);
return v___x_179_;
}
else
{
lean_object* v_head_180_; lean_object* v_tail_181_; lean_object* v___x_183_; uint8_t v_isShared_184_; uint8_t v_isSharedCheck_194_; 
v_head_180_ = lean_ctor_get(v_a_177_, 0);
v_tail_181_ = lean_ctor_get(v_a_177_, 1);
v_isSharedCheck_194_ = !lean_is_exclusive(v_a_177_);
if (v_isSharedCheck_194_ == 0)
{
v___x_183_ = v_a_177_;
v_isShared_184_ = v_isSharedCheck_194_;
goto v_resetjp_182_;
}
else
{
lean_inc(v_tail_181_);
lean_inc(v_head_180_);
lean_dec(v_a_177_);
v___x_183_ = lean_box(0);
v_isShared_184_ = v_isSharedCheck_194_;
goto v_resetjp_182_;
}
v_resetjp_182_:
{
lean_object* v___x_185_; lean_object* v___x_186_; lean_object* v___x_187_; lean_object* v___x_188_; lean_object* v___x_189_; lean_object* v___x_191_; 
v___x_185_ = lean_unsigned_to_nat(0u);
v___x_186_ = lean_string_utf8_byte_size(v_head_180_);
v___x_187_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_187_, 0, v_head_180_);
lean_ctor_set(v___x_187_, 1, v___x_185_);
lean_ctor_set(v___x_187_, 2, v___x_186_);
v___x_188_ = l_String_Slice_trimAscii(v___x_187_);
v___x_189_ = l_String_Slice_toString(v___x_188_);
lean_dec_ref(v___x_188_);
if (v_isShared_184_ == 0)
{
lean_ctor_set(v___x_183_, 1, v_a_178_);
lean_ctor_set(v___x_183_, 0, v___x_189_);
v___x_191_ = v___x_183_;
goto v_reusejp_190_;
}
else
{
lean_object* v_reuseFailAlloc_193_; 
v_reuseFailAlloc_193_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_193_, 0, v___x_189_);
lean_ctor_set(v_reuseFailAlloc_193_, 1, v_a_178_);
v___x_191_ = v_reuseFailAlloc_193_;
goto v_reusejp_190_;
}
v_reusejp_190_:
{
v_a_177_ = v_tail_181_;
v_a_178_ = v___x_191_;
goto _start;
}
}
}
}
}
static lean_object* _init_lp_JunkValues_JunkValues_dischargerOf___closed__0(void){
_start:
{
lean_object* v___x_195_; lean_object* v___x_196_; lean_object* v___x_197_; lean_object* v_dischargers_198_; 
v___x_195_ = lp_JunkValues_JunkValues_assumptionDischarger;
v___x_196_ = lean_unsigned_to_nat(1u);
v___x_197_ = lean_mk_empty_array_with_capacity(v___x_196_);
v_dischargers_198_ = lean_array_push(v___x_197_, v___x_195_);
return v_dischargers_198_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_dischargerOf___closed__2(void){
_start:
{
lean_object* v_problems_201_; lean_object* v_dischargers_202_; lean_object* v___x_203_; 
v_problems_201_ = ((lean_object*)(lp_JunkValues_JunkValues_dischargerOf___closed__1));
v_dischargers_202_ = lean_obj_once(&lp_JunkValues_JunkValues_dischargerOf___closed__0, &lp_JunkValues_JunkValues_dischargerOf___closed__0_once, _init_lp_JunkValues_JunkValues_dischargerOf___closed__0);
v___x_203_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_203_, 0, v_dischargers_202_);
lean_ctor_set(v___x_203_, 1, v_problems_201_);
return v___x_203_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_dischargerOf(lean_object* v_script_204_, lean_object* v_a_205_, lean_object* v_a_206_, lean_object* v_a_207_, lean_object* v_a_208_){
_start:
{
lean_object* v___x_210_; lean_object* v___x_211_; lean_object* v___x_212_; lean_object* v___x_213_; lean_object* v___x_214_; lean_object* v_scripts_215_; lean_object* v___x_216_; lean_object* v___x_217_; 
v___x_210_ = ((lean_object*)(lp_JunkValues_JunkValues_dischargerSeparator___closed__0));
v___x_211_ = lean_unsigned_to_nat(0u);
v___x_212_ = lean_box(0);
v___x_213_ = l_String_splitOnAux(v_script_204_, v___x_210_, v___x_211_, v___x_211_, v___x_211_, v___x_212_);
v___x_214_ = lp_JunkValues_List_mapTR_loop___at___00JunkValues_dischargerOf_spec__0(v___x_213_, v___x_212_);
v_scripts_215_ = lp_JunkValues_List_filterTR_loop___at___00JunkValues_dischargerOf_spec__1(v___x_214_, v___x_212_);
v___x_216_ = lean_obj_once(&lp_JunkValues_JunkValues_dischargerOf___closed__2, &lp_JunkValues_JunkValues_dischargerOf___closed__2_once, _init_lp_JunkValues_JunkValues_dischargerOf___closed__2);
v___x_217_ = lp_JunkValues_List_forIn_x27_loop___at___00JunkValues_dischargerOf_spec__2___redArg(v_scripts_215_, v___x_216_, v_a_208_);
lean_dec(v_scripts_215_);
if (lean_obj_tag(v___x_217_) == 0)
{
lean_object* v_a_218_; lean_object* v___x_220_; uint8_t v_isShared_221_; uint8_t v_isSharedCheck_235_; 
v_a_218_ = lean_ctor_get(v___x_217_, 0);
v_isSharedCheck_235_ = !lean_is_exclusive(v___x_217_);
if (v_isSharedCheck_235_ == 0)
{
v___x_220_ = v___x_217_;
v_isShared_221_ = v_isSharedCheck_235_;
goto v_resetjp_219_;
}
else
{
lean_inc(v_a_218_);
lean_dec(v___x_217_);
v___x_220_ = lean_box(0);
v_isShared_221_ = v_isSharedCheck_235_;
goto v_resetjp_219_;
}
v_resetjp_219_:
{
lean_object* v_fst_222_; lean_object* v_snd_223_; lean_object* v___x_225_; uint8_t v_isShared_226_; uint8_t v_isSharedCheck_234_; 
v_fst_222_ = lean_ctor_get(v_a_218_, 0);
v_snd_223_ = lean_ctor_get(v_a_218_, 1);
v_isSharedCheck_234_ = !lean_is_exclusive(v_a_218_);
if (v_isSharedCheck_234_ == 0)
{
v___x_225_ = v_a_218_;
v_isShared_226_ = v_isSharedCheck_234_;
goto v_resetjp_224_;
}
else
{
lean_inc(v_snd_223_);
lean_inc(v_fst_222_);
lean_dec(v_a_218_);
v___x_225_ = lean_box(0);
v_isShared_226_ = v_isSharedCheck_234_;
goto v_resetjp_224_;
}
v_resetjp_224_:
{
lean_object* v___x_227_; lean_object* v___x_229_; 
v___x_227_ = lp_JunkValues_JunkValues_firstDischarger(v_fst_222_);
if (v_isShared_226_ == 0)
{
lean_ctor_set(v___x_225_, 0, v___x_227_);
v___x_229_ = v___x_225_;
goto v_reusejp_228_;
}
else
{
lean_object* v_reuseFailAlloc_233_; 
v_reuseFailAlloc_233_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_233_, 0, v___x_227_);
lean_ctor_set(v_reuseFailAlloc_233_, 1, v_snd_223_);
v___x_229_ = v_reuseFailAlloc_233_;
goto v_reusejp_228_;
}
v_reusejp_228_:
{
lean_object* v___x_231_; 
if (v_isShared_221_ == 0)
{
lean_ctor_set(v___x_220_, 0, v___x_229_);
v___x_231_ = v___x_220_;
goto v_reusejp_230_;
}
else
{
lean_object* v_reuseFailAlloc_232_; 
v_reuseFailAlloc_232_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_232_, 0, v___x_229_);
v___x_231_ = v_reuseFailAlloc_232_;
goto v_reusejp_230_;
}
v_reusejp_230_:
{
return v___x_231_;
}
}
}
}
}
else
{
lean_object* v_a_236_; lean_object* v___x_238_; uint8_t v_isShared_239_; uint8_t v_isSharedCheck_243_; 
v_a_236_ = lean_ctor_get(v___x_217_, 0);
v_isSharedCheck_243_ = !lean_is_exclusive(v___x_217_);
if (v_isSharedCheck_243_ == 0)
{
v___x_238_ = v___x_217_;
v_isShared_239_ = v_isSharedCheck_243_;
goto v_resetjp_237_;
}
else
{
lean_inc(v_a_236_);
lean_dec(v___x_217_);
v___x_238_ = lean_box(0);
v_isShared_239_ = v_isSharedCheck_243_;
goto v_resetjp_237_;
}
v_resetjp_237_:
{
lean_object* v___x_241_; 
if (v_isShared_239_ == 0)
{
v___x_241_ = v___x_238_;
goto v_reusejp_240_;
}
else
{
lean_object* v_reuseFailAlloc_242_; 
v_reuseFailAlloc_242_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_242_, 0, v_a_236_);
v___x_241_ = v_reuseFailAlloc_242_;
goto v_reusejp_240_;
}
v_reusejp_240_:
{
return v___x_241_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_dischargerOf___boxed(lean_object* v_script_244_, lean_object* v_a_245_, lean_object* v_a_246_, lean_object* v_a_247_, lean_object* v_a_248_, lean_object* v_a_249_){
_start:
{
lean_object* v_res_250_; 
v_res_250_ = lp_JunkValues_JunkValues_dischargerOf(v_script_244_, v_a_245_, v_a_246_, v_a_247_, v_a_248_);
lean_dec(v_a_248_);
lean_dec_ref(v_a_247_);
lean_dec(v_a_246_);
lean_dec_ref(v_a_245_);
lean_dec_ref(v_script_244_);
return v_res_250_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_List_forIn_x27_loop___at___00JunkValues_dischargerOf_spec__2(lean_object* v_as_251_, lean_object* v_as_x27_252_, lean_object* v_b_253_, lean_object* v_a_254_, lean_object* v___y_255_, lean_object* v___y_256_, lean_object* v___y_257_, lean_object* v___y_258_){
_start:
{
lean_object* v___x_260_; 
v___x_260_ = lp_JunkValues_List_forIn_x27_loop___at___00JunkValues_dischargerOf_spec__2___redArg(v_as_x27_252_, v_b_253_, v___y_258_);
return v___x_260_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_List_forIn_x27_loop___at___00JunkValues_dischargerOf_spec__2___boxed(lean_object* v_as_261_, lean_object* v_as_x27_262_, lean_object* v_b_263_, lean_object* v_a_264_, lean_object* v___y_265_, lean_object* v___y_266_, lean_object* v___y_267_, lean_object* v___y_268_, lean_object* v___y_269_){
_start:
{
lean_object* v_res_270_; 
v_res_270_ = lp_JunkValues_List_forIn_x27_loop___at___00JunkValues_dischargerOf_spec__2(v_as_261_, v_as_x27_262_, v_b_263_, v_a_264_, v___y_265_, v___y_266_, v___y_267_, v___y_268_);
lean_dec(v___y_268_);
lean_dec_ref(v___y_267_);
lean_dec(v___y_266_);
lean_dec_ref(v___y_265_);
lean_dec(v_as_x27_262_);
lean_dec(v_as_261_);
return v_res_270_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Option_get___at___00JunkValues_setupOf_spec__0(lean_object* v_opts_271_, lean_object* v_opt_272_){
_start:
{
lean_object* v_name_273_; lean_object* v_defValue_274_; lean_object* v_map_275_; lean_object* v___x_276_; 
v_name_273_ = lean_ctor_get(v_opt_272_, 0);
v_defValue_274_ = lean_ctor_get(v_opt_272_, 1);
v_map_275_ = lean_ctor_get(v_opts_271_, 0);
v___x_276_ = l_Std_DTreeMap_Internal_Impl_Const_get_x3f___at___00Lean_NameMap_find_x3f_spec__0___redArg(v_map_275_, v_name_273_);
if (lean_obj_tag(v___x_276_) == 0)
{
lean_inc(v_defValue_274_);
return v_defValue_274_;
}
else
{
lean_object* v_val_277_; 
v_val_277_ = lean_ctor_get(v___x_276_, 0);
lean_inc(v_val_277_);
lean_dec_ref_known(v___x_276_, 1);
if (lean_obj_tag(v_val_277_) == 0)
{
lean_object* v_v_278_; 
v_v_278_ = lean_ctor_get(v_val_277_, 0);
lean_inc_ref(v_v_278_);
lean_dec_ref_known(v_val_277_, 1);
return v_v_278_;
}
else
{
lean_dec(v_val_277_);
lean_inc(v_defValue_274_);
return v_defValue_274_;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Option_get___at___00JunkValues_setupOf_spec__0___boxed(lean_object* v_opts_279_, lean_object* v_opt_280_){
_start:
{
lean_object* v_res_281_; 
v_res_281_ = lp_JunkValues_Lean_Option_get___at___00JunkValues_setupOf_spec__0(v_opts_279_, v_opt_280_);
lean_dec_ref(v_opt_280_);
lean_dec_ref(v_opts_279_);
return v_res_281_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_setupOf(lean_object* v_opts_282_, lean_object* v_a_283_, lean_object* v_a_284_, lean_object* v_a_285_, lean_object* v_a_286_){
_start:
{
lean_object* v___x_288_; lean_object* v___x_289_; lean_object* v___x_290_; 
v___x_288_ = lp_JunkValues_JunkValues_linter_junkValues_discharger;
v___x_289_ = lp_JunkValues_Lean_Option_get___at___00JunkValues_setupOf_spec__0(v_opts_282_, v___x_288_);
v___x_290_ = lp_JunkValues_JunkValues_dischargerOf(v___x_289_, v_a_283_, v_a_284_, v_a_285_, v_a_286_);
lean_dec_ref(v___x_289_);
if (lean_obj_tag(v___x_290_) == 0)
{
lean_object* v_a_291_; lean_object* v_fst_292_; lean_object* v_snd_293_; lean_object* v___x_295_; uint8_t v_isShared_296_; uint8_t v_isSharedCheck_325_; 
v_a_291_ = lean_ctor_get(v___x_290_, 0);
lean_inc(v_a_291_);
lean_dec_ref_known(v___x_290_, 1);
v_fst_292_ = lean_ctor_get(v_a_291_, 0);
v_snd_293_ = lean_ctor_get(v_a_291_, 1);
v_isSharedCheck_325_ = !lean_is_exclusive(v_a_291_);
if (v_isSharedCheck_325_ == 0)
{
v___x_295_ = v_a_291_;
v_isShared_296_ = v_isSharedCheck_325_;
goto v_resetjp_294_;
}
else
{
lean_inc(v_snd_293_);
lean_inc(v_fst_292_);
lean_dec(v_a_291_);
v___x_295_ = lean_box(0);
v_isShared_296_ = v_isSharedCheck_325_;
goto v_resetjp_294_;
}
v_resetjp_294_:
{
lean_object* v___x_297_; 
v___x_297_ = lp_JunkValues_JunkValues_RuleSet_ofEnv(v_opts_282_, v_a_283_, v_a_284_, v_a_285_, v_a_286_);
if (lean_obj_tag(v___x_297_) == 0)
{
lean_object* v_a_298_; lean_object* v___x_300_; uint8_t v_isShared_301_; uint8_t v_isSharedCheck_316_; 
v_a_298_ = lean_ctor_get(v___x_297_, 0);
v_isSharedCheck_316_ = !lean_is_exclusive(v___x_297_);
if (v_isSharedCheck_316_ == 0)
{
v___x_300_ = v___x_297_;
v_isShared_301_ = v_isSharedCheck_316_;
goto v_resetjp_299_;
}
else
{
lean_inc(v_a_298_);
lean_dec(v___x_297_);
v___x_300_ = lean_box(0);
v_isShared_301_ = v_isSharedCheck_316_;
goto v_resetjp_299_;
}
v_resetjp_299_:
{
uint8_t v___x_302_; lean_object* v___x_303_; uint8_t v___x_304_; lean_object* v___x_305_; lean_object* v___x_306_; lean_object* v_problems_307_; lean_object* v___x_308_; lean_object* v___x_310_; 
v___x_302_ = 1;
v___x_303_ = lean_alloc_ctor(0, 1, 1);
lean_ctor_set(v___x_303_, 0, v_fst_292_);
lean_ctor_set_uint8(v___x_303_, sizeof(void*)*1, v___x_302_);
v___x_304_ = 0;
v___x_305_ = lean_unsigned_to_nat(64u);
v___x_306_ = lean_alloc_ctor(0, 2, 3);
lean_ctor_set(v___x_306_, 0, v___x_303_);
lean_ctor_set(v___x_306_, 1, v___x_305_);
lean_ctor_set_uint8(v___x_306_, sizeof(void*)*2, v___x_304_);
lean_ctor_set_uint8(v___x_306_, sizeof(void*)*2 + 1, v___x_302_);
lean_ctor_set_uint8(v___x_306_, sizeof(void*)*2 + 2, v___x_304_);
v_problems_307_ = lean_ctor_get(v_a_298_, 2);
lean_inc_ref(v_problems_307_);
v___x_308_ = l_Array_append___redArg(v_problems_307_, v_snd_293_);
lean_dec(v_snd_293_);
if (v_isShared_296_ == 0)
{
lean_ctor_set(v___x_295_, 1, v___x_308_);
lean_ctor_set(v___x_295_, 0, v___x_306_);
v___x_310_ = v___x_295_;
goto v_reusejp_309_;
}
else
{
lean_object* v_reuseFailAlloc_315_; 
v_reuseFailAlloc_315_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_315_, 0, v___x_306_);
lean_ctor_set(v_reuseFailAlloc_315_, 1, v___x_308_);
v___x_310_ = v_reuseFailAlloc_315_;
goto v_reusejp_309_;
}
v_reusejp_309_:
{
lean_object* v___x_311_; lean_object* v___x_313_; 
v___x_311_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_311_, 0, v_a_298_);
lean_ctor_set(v___x_311_, 1, v___x_310_);
if (v_isShared_301_ == 0)
{
lean_ctor_set(v___x_300_, 0, v___x_311_);
v___x_313_ = v___x_300_;
goto v_reusejp_312_;
}
else
{
lean_object* v_reuseFailAlloc_314_; 
v_reuseFailAlloc_314_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_314_, 0, v___x_311_);
v___x_313_ = v_reuseFailAlloc_314_;
goto v_reusejp_312_;
}
v_reusejp_312_:
{
return v___x_313_;
}
}
}
}
else
{
lean_object* v_a_317_; lean_object* v___x_319_; uint8_t v_isShared_320_; uint8_t v_isSharedCheck_324_; 
lean_del_object(v___x_295_);
lean_dec(v_snd_293_);
lean_dec(v_fst_292_);
v_a_317_ = lean_ctor_get(v___x_297_, 0);
v_isSharedCheck_324_ = !lean_is_exclusive(v___x_297_);
if (v_isSharedCheck_324_ == 0)
{
v___x_319_ = v___x_297_;
v_isShared_320_ = v_isSharedCheck_324_;
goto v_resetjp_318_;
}
else
{
lean_inc(v_a_317_);
lean_dec(v___x_297_);
v___x_319_ = lean_box(0);
v_isShared_320_ = v_isSharedCheck_324_;
goto v_resetjp_318_;
}
v_resetjp_318_:
{
lean_object* v___x_322_; 
if (v_isShared_320_ == 0)
{
v___x_322_ = v___x_319_;
goto v_reusejp_321_;
}
else
{
lean_object* v_reuseFailAlloc_323_; 
v_reuseFailAlloc_323_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_323_, 0, v_a_317_);
v___x_322_ = v_reuseFailAlloc_323_;
goto v_reusejp_321_;
}
v_reusejp_321_:
{
return v___x_322_;
}
}
}
}
}
else
{
lean_object* v_a_326_; lean_object* v___x_328_; uint8_t v_isShared_329_; uint8_t v_isSharedCheck_333_; 
lean_dec_ref(v_opts_282_);
v_a_326_ = lean_ctor_get(v___x_290_, 0);
v_isSharedCheck_333_ = !lean_is_exclusive(v___x_290_);
if (v_isSharedCheck_333_ == 0)
{
v___x_328_ = v___x_290_;
v_isShared_329_ = v_isSharedCheck_333_;
goto v_resetjp_327_;
}
else
{
lean_inc(v_a_326_);
lean_dec(v___x_290_);
v___x_328_ = lean_box(0);
v_isShared_329_ = v_isSharedCheck_333_;
goto v_resetjp_327_;
}
v_resetjp_327_:
{
lean_object* v___x_331_; 
if (v_isShared_329_ == 0)
{
v___x_331_ = v___x_328_;
goto v_reusejp_330_;
}
else
{
lean_object* v_reuseFailAlloc_332_; 
v_reuseFailAlloc_332_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_332_, 0, v_a_326_);
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
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_setupOf___boxed(lean_object* v_opts_334_, lean_object* v_a_335_, lean_object* v_a_336_, lean_object* v_a_337_, lean_object* v_a_338_, lean_object* v_a_339_){
_start:
{
lean_object* v_res_340_; 
v_res_340_ = lp_JunkValues_JunkValues_setupOf(v_opts_334_, v_a_335_, v_a_336_, v_a_337_, v_a_338_);
lean_dec(v_a_338_);
lean_dec_ref(v_a_337_);
lean_dec(v_a_336_);
lean_dec_ref(v_a_335_);
return v_res_340_;
}
}
LEAN_EXPORT uint8_t lp_JunkValues___private_Init_Data_Array_Basic_0__Array_anyMUnsafe_any___at___00Array_contains___at___00JunkValues_declIdsOf_spec__0_spec__0(lean_object* v_a_341_, lean_object* v_as_342_, size_t v_i_343_, size_t v_stop_344_){
_start:
{
uint8_t v___x_345_; 
v___x_345_ = lean_usize_dec_eq(v_i_343_, v_stop_344_);
if (v___x_345_ == 0)
{
lean_object* v___x_346_; uint8_t v___x_347_; 
v___x_346_ = lean_array_uget_borrowed(v_as_342_, v_i_343_);
v___x_347_ = lean_name_eq(v_a_341_, v___x_346_);
if (v___x_347_ == 0)
{
size_t v___x_348_; size_t v___x_349_; 
v___x_348_ = ((size_t)1ULL);
v___x_349_ = lean_usize_add(v_i_343_, v___x_348_);
v_i_343_ = v___x_349_;
goto _start;
}
else
{
return v___x_347_;
}
}
else
{
uint8_t v___x_351_; 
v___x_351_ = 0;
return v___x_351_;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_anyMUnsafe_any___at___00Array_contains___at___00JunkValues_declIdsOf_spec__0_spec__0___boxed(lean_object* v_a_352_, lean_object* v_as_353_, lean_object* v_i_354_, lean_object* v_stop_355_){
_start:
{
size_t v_i_boxed_356_; size_t v_stop_boxed_357_; uint8_t v_res_358_; lean_object* v_r_359_; 
v_i_boxed_356_ = lean_unbox_usize(v_i_354_);
lean_dec(v_i_354_);
v_stop_boxed_357_ = lean_unbox_usize(v_stop_355_);
lean_dec(v_stop_355_);
v_res_358_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_anyMUnsafe_any___at___00Array_contains___at___00JunkValues_declIdsOf_spec__0_spec__0(v_a_352_, v_as_353_, v_i_boxed_356_, v_stop_boxed_357_);
lean_dec_ref(v_as_353_);
lean_dec(v_a_352_);
v_r_359_ = lean_box(v_res_358_);
return v_r_359_;
}
}
LEAN_EXPORT uint8_t lp_JunkValues_Array_contains___at___00JunkValues_declIdsOf_spec__0(lean_object* v_as_360_, lean_object* v_a_361_){
_start:
{
lean_object* v___x_362_; lean_object* v___x_363_; uint8_t v___x_364_; 
v___x_362_ = lean_unsigned_to_nat(0u);
v___x_363_ = lean_array_get_size(v_as_360_);
v___x_364_ = lean_nat_dec_lt(v___x_362_, v___x_363_);
if (v___x_364_ == 0)
{
return v___x_364_;
}
else
{
if (v___x_364_ == 0)
{
return v___x_364_;
}
else
{
size_t v___x_365_; size_t v___x_366_; uint8_t v___x_367_; 
v___x_365_ = ((size_t)0ULL);
v___x_366_ = lean_usize_of_nat(v___x_363_);
v___x_367_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_anyMUnsafe_any___at___00Array_contains___at___00JunkValues_declIdsOf_spec__0_spec__0(v_a_361_, v_as_360_, v___x_365_, v___x_366_);
return v___x_367_;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Array_contains___at___00JunkValues_declIdsOf_spec__0___boxed(lean_object* v_as_368_, lean_object* v_a_369_){
_start:
{
uint8_t v_res_370_; lean_object* v_r_371_; 
v_res_370_ = lp_JunkValues_Array_contains___at___00JunkValues_declIdsOf_spec__0(v_as_368_, v_a_369_);
lean_dec(v_a_369_);
lean_dec_ref(v_as_368_);
v_r_371_ = lean_box(v_res_370_);
return v_r_371_;
}
}
LEAN_EXPORT uint8_t lp_JunkValues___private_Init_Data_Array_Basic_0__Array_anyMUnsafe_any___at___00JunkValues_declIdsOf_spec__1(lean_object* v_fst_372_, lean_object* v_as_373_, size_t v_i_374_, size_t v_stop_375_){
_start:
{
uint8_t v___x_376_; 
v___x_376_ = lean_usize_dec_eq(v_i_374_, v_stop_375_);
if (v___x_376_ == 0)
{
lean_object* v___x_377_; uint8_t v___x_378_; 
v___x_377_ = lean_array_uget_borrowed(v_as_373_, v_i_374_);
v___x_378_ = l_Lean_Name_isPrefixOf(v___x_377_, v_fst_372_);
if (v___x_378_ == 0)
{
size_t v___x_379_; size_t v___x_380_; 
v___x_379_ = ((size_t)1ULL);
v___x_380_ = lean_usize_add(v_i_374_, v___x_379_);
v_i_374_ = v___x_380_;
goto _start;
}
else
{
return v___x_378_;
}
}
else
{
uint8_t v___x_382_; 
v___x_382_ = 0;
return v___x_382_;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_anyMUnsafe_any___at___00JunkValues_declIdsOf_spec__1___boxed(lean_object* v_fst_383_, lean_object* v_as_384_, lean_object* v_i_385_, lean_object* v_stop_386_){
_start:
{
size_t v_i_boxed_387_; size_t v_stop_boxed_388_; uint8_t v_res_389_; lean_object* v_r_390_; 
v_i_boxed_387_ = lean_unbox_usize(v_i_385_);
lean_dec(v_i_385_);
v_stop_boxed_388_ = lean_unbox_usize(v_stop_386_);
lean_dec(v_stop_386_);
v_res_389_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_anyMUnsafe_any___at___00JunkValues_declIdsOf_spec__1(v_fst_383_, v_as_384_, v_i_boxed_387_, v_stop_boxed_388_);
lean_dec_ref(v_as_384_);
lean_dec(v_fst_383_);
v_r_390_ = lean_box(v_res_389_);
return v_r_390_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_declIdsOf___lam__0(lean_object* v_a_391_, lean_object* v___x_392_, lean_object* v_x_393_, lean_object* v_____s_394_, lean_object* v___y_395_, lean_object* v___y_396_){
_start:
{
lean_object* v_fst_398_; uint8_t v___y_400_; uint8_t v___x_406_; 
v_fst_398_ = lean_ctor_get(v_x_393_, 0);
lean_inc(v_fst_398_);
lean_dec_ref(v_x_393_);
v___x_406_ = lp_JunkValues_JunkValues_isCompilerGenerated(v_fst_398_);
if (v___x_406_ == 0)
{
uint8_t v___x_407_; 
v___x_407_ = lp_JunkValues_Array_contains___at___00JunkValues_declIdsOf_spec__0(v_____s_394_, v_fst_398_);
if (v___x_407_ == 0)
{
lean_object* v___x_408_; uint8_t v___x_409_; 
v___x_408_ = lean_array_get_size(v_a_391_);
v___x_409_ = lean_nat_dec_lt(v___x_392_, v___x_408_);
if (v___x_409_ == 0)
{
v___y_400_ = v___x_407_;
goto v___jp_399_;
}
else
{
if (v___x_409_ == 0)
{
v___y_400_ = v___x_407_;
goto v___jp_399_;
}
else
{
size_t v___x_410_; size_t v___x_411_; uint8_t v___x_412_; 
v___x_410_ = ((size_t)0ULL);
v___x_411_ = lean_usize_of_nat(v___x_408_);
v___x_412_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_anyMUnsafe_any___at___00JunkValues_declIdsOf_spec__1(v_fst_398_, v_a_391_, v___x_410_, v___x_411_);
v___y_400_ = v___x_412_;
goto v___jp_399_;
}
}
}
else
{
lean_object* v___x_413_; lean_object* v___x_414_; 
lean_dec(v_fst_398_);
v___x_413_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_413_, 0, v_____s_394_);
v___x_414_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_414_, 0, v___x_413_);
return v___x_414_;
}
}
else
{
lean_object* v___x_415_; lean_object* v___x_416_; 
lean_dec(v_fst_398_);
v___x_415_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_415_, 0, v_____s_394_);
v___x_416_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_416_, 0, v___x_415_);
return v___x_416_;
}
v___jp_399_:
{
if (v___y_400_ == 0)
{
lean_object* v___x_401_; lean_object* v___x_402_; 
lean_dec(v_fst_398_);
v___x_401_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_401_, 0, v_____s_394_);
v___x_402_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_402_, 0, v___x_401_);
return v___x_402_;
}
else
{
lean_object* v___x_403_; lean_object* v___x_404_; lean_object* v___x_405_; 
v___x_403_ = lean_array_push(v_____s_394_, v_fst_398_);
v___x_404_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_404_, 0, v___x_403_);
v___x_405_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_405_, 0, v___x_404_);
return v___x_405_;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_declIdsOf___lam__0___boxed(lean_object* v_a_417_, lean_object* v___x_418_, lean_object* v_x_419_, lean_object* v_____s_420_, lean_object* v___y_421_, lean_object* v___y_422_, lean_object* v___y_423_){
_start:
{
lean_object* v_res_424_; 
v_res_424_ = lp_JunkValues_JunkValues_declIdsOf___lam__0(v_a_417_, v___x_418_, v_x_419_, v_____s_420_, v___y_421_, v___y_422_);
lean_dec(v___y_422_);
lean_dec_ref(v___y_421_);
lean_dec(v___x_418_);
lean_dec_ref(v_a_417_);
return v_res_424_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Lean_Data_PersistentHashMap_0__Lean_PersistentHashMap_foldlMAux_traverse___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2_spec__3_spec__4_spec__8___redArg(lean_object* v_f_425_, lean_object* v_keys_426_, lean_object* v_vals_427_, lean_object* v_i_428_, lean_object* v_acc_429_, lean_object* v___y_430_, lean_object* v___y_431_){
_start:
{
lean_object* v___x_433_; uint8_t v___x_434_; 
v___x_433_ = lean_array_get_size(v_keys_426_);
v___x_434_ = lean_nat_dec_lt(v_i_428_, v___x_433_);
if (v___x_434_ == 0)
{
lean_object* v___x_435_; lean_object* v___x_436_; 
lean_dec(v_i_428_);
lean_dec_ref(v_f_425_);
v___x_435_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_435_, 0, v_acc_429_);
v___x_436_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_436_, 0, v___x_435_);
return v___x_436_;
}
else
{
lean_object* v_k_437_; lean_object* v_v_438_; lean_object* v___x_439_; 
v_k_437_ = lean_array_fget_borrowed(v_keys_426_, v_i_428_);
v_v_438_ = lean_array_fget_borrowed(v_vals_427_, v_i_428_);
lean_inc_ref(v_f_425_);
lean_inc(v___y_431_);
lean_inc_ref(v___y_430_);
lean_inc(v_v_438_);
lean_inc(v_k_437_);
v___x_439_ = lean_apply_6(v_f_425_, v_acc_429_, v_k_437_, v_v_438_, v___y_430_, v___y_431_, lean_box(0));
if (lean_obj_tag(v___x_439_) == 0)
{
lean_object* v_a_440_; 
v_a_440_ = lean_ctor_get(v___x_439_, 0);
lean_inc(v_a_440_);
if (lean_obj_tag(v_a_440_) == 0)
{
lean_dec_ref_known(v_a_440_, 1);
lean_dec(v_i_428_);
lean_dec_ref(v_f_425_);
return v___x_439_;
}
else
{
lean_object* v_a_441_; lean_object* v___x_442_; lean_object* v___x_443_; 
lean_dec_ref_known(v___x_439_, 1);
v_a_441_ = lean_ctor_get(v_a_440_, 0);
lean_inc(v_a_441_);
lean_dec_ref_known(v_a_440_, 1);
v___x_442_ = lean_unsigned_to_nat(1u);
v___x_443_ = lean_nat_add(v_i_428_, v___x_442_);
lean_dec(v_i_428_);
v_i_428_ = v___x_443_;
v_acc_429_ = v_a_441_;
goto _start;
}
}
else
{
lean_dec(v_i_428_);
lean_dec_ref(v_f_425_);
return v___x_439_;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Lean_Data_PersistentHashMap_0__Lean_PersistentHashMap_foldlMAux_traverse___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2_spec__3_spec__4_spec__8___redArg___boxed(lean_object* v_f_445_, lean_object* v_keys_446_, lean_object* v_vals_447_, lean_object* v_i_448_, lean_object* v_acc_449_, lean_object* v___y_450_, lean_object* v___y_451_, lean_object* v___y_452_){
_start:
{
lean_object* v_res_453_; 
v_res_453_ = lp_JunkValues___private_Lean_Data_PersistentHashMap_0__Lean_PersistentHashMap_foldlMAux_traverse___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2_spec__3_spec__4_spec__8___redArg(v_f_445_, v_keys_446_, v_vals_447_, v_i_448_, v_acc_449_, v___y_450_, v___y_451_);
lean_dec(v___y_451_);
lean_dec_ref(v___y_450_);
lean_dec_ref(v_vals_447_);
lean_dec_ref(v_keys_446_);
return v_res_453_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2_spec__3_spec__4___redArg(lean_object* v_f_454_, lean_object* v_x_455_, lean_object* v_x_456_, lean_object* v___y_457_, lean_object* v___y_458_){
_start:
{
if (lean_obj_tag(v_x_455_) == 0)
{
lean_object* v_es_460_; lean_object* v___x_462_; uint8_t v_isShared_463_; uint8_t v_isSharedCheck_482_; 
v_es_460_ = lean_ctor_get(v_x_455_, 0);
v_isSharedCheck_482_ = !lean_is_exclusive(v_x_455_);
if (v_isSharedCheck_482_ == 0)
{
v___x_462_ = v_x_455_;
v_isShared_463_ = v_isSharedCheck_482_;
goto v_resetjp_461_;
}
else
{
lean_inc(v_es_460_);
lean_dec(v_x_455_);
v___x_462_ = lean_box(0);
v_isShared_463_ = v_isSharedCheck_482_;
goto v_resetjp_461_;
}
v_resetjp_461_:
{
lean_object* v___x_464_; lean_object* v___x_465_; uint8_t v___x_466_; 
v___x_464_ = lean_unsigned_to_nat(0u);
v___x_465_ = lean_array_get_size(v_es_460_);
v___x_466_ = lean_nat_dec_lt(v___x_464_, v___x_465_);
if (v___x_466_ == 0)
{
lean_object* v___x_468_; 
lean_dec_ref(v_es_460_);
lean_dec_ref(v_f_454_);
if (v_isShared_463_ == 0)
{
lean_ctor_set_tag(v___x_462_, 1);
lean_ctor_set(v___x_462_, 0, v_x_456_);
v___x_468_ = v___x_462_;
goto v_reusejp_467_;
}
else
{
lean_object* v_reuseFailAlloc_470_; 
v_reuseFailAlloc_470_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_470_, 0, v_x_456_);
v___x_468_ = v_reuseFailAlloc_470_;
goto v_reusejp_467_;
}
v_reusejp_467_:
{
lean_object* v___x_469_; 
v___x_469_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_469_, 0, v___x_468_);
return v___x_469_;
}
}
else
{
uint8_t v___x_471_; 
v___x_471_ = lean_nat_dec_le(v___x_465_, v___x_465_);
if (v___x_471_ == 0)
{
if (v___x_466_ == 0)
{
lean_object* v___x_473_; 
lean_dec_ref(v_es_460_);
lean_dec_ref(v_f_454_);
if (v_isShared_463_ == 0)
{
lean_ctor_set_tag(v___x_462_, 1);
lean_ctor_set(v___x_462_, 0, v_x_456_);
v___x_473_ = v___x_462_;
goto v_reusejp_472_;
}
else
{
lean_object* v_reuseFailAlloc_475_; 
v_reuseFailAlloc_475_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_475_, 0, v_x_456_);
v___x_473_ = v_reuseFailAlloc_475_;
goto v_reusejp_472_;
}
v_reusejp_472_:
{
lean_object* v___x_474_; 
v___x_474_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_474_, 0, v___x_473_);
return v___x_474_;
}
}
else
{
size_t v___x_476_; size_t v___x_477_; lean_object* v___x_478_; 
lean_del_object(v___x_462_);
v___x_476_ = ((size_t)0ULL);
v___x_477_ = lean_usize_of_nat(v___x_465_);
v___x_478_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2_spec__3_spec__4_spec__7___redArg(v_f_454_, v_es_460_, v___x_476_, v___x_477_, v_x_456_, v___y_457_, v___y_458_);
lean_dec_ref(v_es_460_);
return v___x_478_;
}
}
else
{
size_t v___x_479_; size_t v___x_480_; lean_object* v___x_481_; 
lean_del_object(v___x_462_);
v___x_479_ = ((size_t)0ULL);
v___x_480_ = lean_usize_of_nat(v___x_465_);
v___x_481_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2_spec__3_spec__4_spec__7___redArg(v_f_454_, v_es_460_, v___x_479_, v___x_480_, v_x_456_, v___y_457_, v___y_458_);
lean_dec_ref(v_es_460_);
return v___x_481_;
}
}
}
}
else
{
lean_object* v_ks_483_; lean_object* v_vs_484_; lean_object* v___x_485_; lean_object* v___x_486_; 
v_ks_483_ = lean_ctor_get(v_x_455_, 0);
lean_inc_ref(v_ks_483_);
v_vs_484_ = lean_ctor_get(v_x_455_, 1);
lean_inc_ref(v_vs_484_);
lean_dec_ref_known(v_x_455_, 2);
v___x_485_ = lean_unsigned_to_nat(0u);
v___x_486_ = lp_JunkValues___private_Lean_Data_PersistentHashMap_0__Lean_PersistentHashMap_foldlMAux_traverse___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2_spec__3_spec__4_spec__8___redArg(v_f_454_, v_ks_483_, v_vs_484_, v___x_485_, v_x_456_, v___y_457_, v___y_458_);
lean_dec_ref(v_vs_484_);
lean_dec_ref(v_ks_483_);
return v___x_486_;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2_spec__3_spec__4_spec__7___redArg(lean_object* v_f_487_, lean_object* v_as_488_, size_t v_i_489_, size_t v_stop_490_, lean_object* v_b_491_, lean_object* v___y_492_, lean_object* v___y_493_){
_start:
{
lean_object* v_a_496_; lean_object* v___y_501_; uint8_t v___x_504_; 
v___x_504_ = lean_usize_dec_eq(v_i_489_, v_stop_490_);
if (v___x_504_ == 0)
{
lean_object* v___x_505_; 
v___x_505_ = lean_array_uget_borrowed(v_as_488_, v_i_489_);
switch(lean_obj_tag(v___x_505_))
{
case 0:
{
lean_object* v_key_506_; lean_object* v_val_507_; lean_object* v___x_508_; 
v_key_506_ = lean_ctor_get(v___x_505_, 0);
v_val_507_ = lean_ctor_get(v___x_505_, 1);
lean_inc_ref(v_f_487_);
lean_inc(v___y_493_);
lean_inc_ref(v___y_492_);
lean_inc(v_val_507_);
lean_inc(v_key_506_);
v___x_508_ = lean_apply_6(v_f_487_, v_b_491_, v_key_506_, v_val_507_, v___y_492_, v___y_493_, lean_box(0));
v___y_501_ = v___x_508_;
goto v___jp_500_;
}
case 1:
{
lean_object* v_node_509_; lean_object* v___x_510_; 
v_node_509_ = lean_ctor_get(v___x_505_, 0);
lean_inc(v_node_509_);
lean_inc_ref(v_f_487_);
v___x_510_ = lp_JunkValues_Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2_spec__3_spec__4___redArg(v_f_487_, v_node_509_, v_b_491_, v___y_492_, v___y_493_);
v___y_501_ = v___x_510_;
goto v___jp_500_;
}
default: 
{
v_a_496_ = v_b_491_;
goto v___jp_495_;
}
}
}
else
{
lean_object* v___x_511_; lean_object* v___x_512_; 
lean_dec_ref(v_f_487_);
v___x_511_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_511_, 0, v_b_491_);
v___x_512_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_512_, 0, v___x_511_);
return v___x_512_;
}
v___jp_495_:
{
size_t v___x_497_; size_t v___x_498_; 
v___x_497_ = ((size_t)1ULL);
v___x_498_ = lean_usize_add(v_i_489_, v___x_497_);
v_i_489_ = v___x_498_;
v_b_491_ = v_a_496_;
goto _start;
}
v___jp_500_:
{
if (lean_obj_tag(v___y_501_) == 0)
{
lean_object* v_a_502_; 
v_a_502_ = lean_ctor_get(v___y_501_, 0);
if (lean_obj_tag(v_a_502_) == 0)
{
lean_dec_ref(v_f_487_);
return v___y_501_;
}
else
{
lean_object* v_a_503_; 
lean_inc_ref(v_a_502_);
lean_dec_ref_known(v___y_501_, 1);
v_a_503_ = lean_ctor_get(v_a_502_, 0);
lean_inc(v_a_503_);
lean_dec_ref_known(v_a_502_, 1);
v_a_496_ = v_a_503_;
goto v___jp_495_;
}
}
else
{
lean_dec_ref(v_f_487_);
return v___y_501_;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2_spec__3_spec__4_spec__7___redArg___boxed(lean_object* v_f_513_, lean_object* v_as_514_, lean_object* v_i_515_, lean_object* v_stop_516_, lean_object* v_b_517_, lean_object* v___y_518_, lean_object* v___y_519_, lean_object* v___y_520_){
_start:
{
size_t v_i_boxed_521_; size_t v_stop_boxed_522_; lean_object* v_res_523_; 
v_i_boxed_521_ = lean_unbox_usize(v_i_515_);
lean_dec(v_i_515_);
v_stop_boxed_522_ = lean_unbox_usize(v_stop_516_);
lean_dec(v_stop_516_);
v_res_523_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2_spec__3_spec__4_spec__7___redArg(v_f_513_, v_as_514_, v_i_boxed_521_, v_stop_boxed_522_, v_b_517_, v___y_518_, v___y_519_);
lean_dec(v___y_519_);
lean_dec_ref(v___y_518_);
lean_dec_ref(v_as_514_);
return v_res_523_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2_spec__3_spec__4___redArg___boxed(lean_object* v_f_524_, lean_object* v_x_525_, lean_object* v_x_526_, lean_object* v___y_527_, lean_object* v___y_528_, lean_object* v___y_529_){
_start:
{
lean_object* v_res_530_; 
v_res_530_ = lp_JunkValues_Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2_spec__3_spec__4___redArg(v_f_524_, v_x_525_, v_x_526_, v___y_527_, v___y_528_);
lean_dec(v___y_528_);
lean_dec_ref(v___y_527_);
return v_res_530_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2___redArg___lam__0(lean_object* v_f_531_, lean_object* v_s_532_, lean_object* v_a_533_, lean_object* v_b_534_, lean_object* v___y_535_, lean_object* v___y_536_){
_start:
{
lean_object* v___x_538_; lean_object* v___x_539_; 
v___x_538_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_538_, 0, v_a_533_);
lean_ctor_set(v___x_538_, 1, v_b_534_);
lean_inc(v___y_536_);
lean_inc_ref(v___y_535_);
v___x_539_ = lean_apply_5(v_f_531_, v___x_538_, v_s_532_, v___y_535_, v___y_536_, lean_box(0));
if (lean_obj_tag(v___x_539_) == 0)
{
lean_object* v_a_540_; lean_object* v___x_542_; uint8_t v_isShared_543_; uint8_t v_isSharedCheck_566_; 
v_a_540_ = lean_ctor_get(v___x_539_, 0);
v_isSharedCheck_566_ = !lean_is_exclusive(v___x_539_);
if (v_isSharedCheck_566_ == 0)
{
v___x_542_ = v___x_539_;
v_isShared_543_ = v_isSharedCheck_566_;
goto v_resetjp_541_;
}
else
{
lean_inc(v_a_540_);
lean_dec(v___x_539_);
v___x_542_ = lean_box(0);
v_isShared_543_ = v_isSharedCheck_566_;
goto v_resetjp_541_;
}
v_resetjp_541_:
{
if (lean_obj_tag(v_a_540_) == 0)
{
lean_object* v_a_544_; lean_object* v___x_546_; uint8_t v_isShared_547_; uint8_t v_isSharedCheck_554_; 
v_a_544_ = lean_ctor_get(v_a_540_, 0);
v_isSharedCheck_554_ = !lean_is_exclusive(v_a_540_);
if (v_isSharedCheck_554_ == 0)
{
v___x_546_ = v_a_540_;
v_isShared_547_ = v_isSharedCheck_554_;
goto v_resetjp_545_;
}
else
{
lean_inc(v_a_544_);
lean_dec(v_a_540_);
v___x_546_ = lean_box(0);
v_isShared_547_ = v_isSharedCheck_554_;
goto v_resetjp_545_;
}
v_resetjp_545_:
{
lean_object* v___x_549_; 
if (v_isShared_547_ == 0)
{
v___x_549_ = v___x_546_;
goto v_reusejp_548_;
}
else
{
lean_object* v_reuseFailAlloc_553_; 
v_reuseFailAlloc_553_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_553_, 0, v_a_544_);
v___x_549_ = v_reuseFailAlloc_553_;
goto v_reusejp_548_;
}
v_reusejp_548_:
{
lean_object* v___x_551_; 
if (v_isShared_543_ == 0)
{
lean_ctor_set(v___x_542_, 0, v___x_549_);
v___x_551_ = v___x_542_;
goto v_reusejp_550_;
}
else
{
lean_object* v_reuseFailAlloc_552_; 
v_reuseFailAlloc_552_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_552_, 0, v___x_549_);
v___x_551_ = v_reuseFailAlloc_552_;
goto v_reusejp_550_;
}
v_reusejp_550_:
{
return v___x_551_;
}
}
}
}
else
{
lean_object* v_a_555_; lean_object* v___x_557_; uint8_t v_isShared_558_; uint8_t v_isSharedCheck_565_; 
v_a_555_ = lean_ctor_get(v_a_540_, 0);
v_isSharedCheck_565_ = !lean_is_exclusive(v_a_540_);
if (v_isSharedCheck_565_ == 0)
{
v___x_557_ = v_a_540_;
v_isShared_558_ = v_isSharedCheck_565_;
goto v_resetjp_556_;
}
else
{
lean_inc(v_a_555_);
lean_dec(v_a_540_);
v___x_557_ = lean_box(0);
v_isShared_558_ = v_isSharedCheck_565_;
goto v_resetjp_556_;
}
v_resetjp_556_:
{
lean_object* v___x_560_; 
if (v_isShared_558_ == 0)
{
v___x_560_ = v___x_557_;
goto v_reusejp_559_;
}
else
{
lean_object* v_reuseFailAlloc_564_; 
v_reuseFailAlloc_564_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_564_, 0, v_a_555_);
v___x_560_ = v_reuseFailAlloc_564_;
goto v_reusejp_559_;
}
v_reusejp_559_:
{
lean_object* v___x_562_; 
if (v_isShared_543_ == 0)
{
lean_ctor_set(v___x_542_, 0, v___x_560_);
v___x_562_ = v___x_542_;
goto v_reusejp_561_;
}
else
{
lean_object* v_reuseFailAlloc_563_; 
v_reuseFailAlloc_563_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_563_, 0, v___x_560_);
v___x_562_ = v_reuseFailAlloc_563_;
goto v_reusejp_561_;
}
v_reusejp_561_:
{
return v___x_562_;
}
}
}
}
}
}
else
{
lean_object* v_a_567_; lean_object* v___x_569_; uint8_t v_isShared_570_; uint8_t v_isSharedCheck_574_; 
v_a_567_ = lean_ctor_get(v___x_539_, 0);
v_isSharedCheck_574_ = !lean_is_exclusive(v___x_539_);
if (v_isSharedCheck_574_ == 0)
{
v___x_569_ = v___x_539_;
v_isShared_570_ = v_isSharedCheck_574_;
goto v_resetjp_568_;
}
else
{
lean_inc(v_a_567_);
lean_dec(v___x_539_);
v___x_569_ = lean_box(0);
v_isShared_570_ = v_isSharedCheck_574_;
goto v_resetjp_568_;
}
v_resetjp_568_:
{
lean_object* v___x_572_; 
if (v_isShared_570_ == 0)
{
v___x_572_ = v___x_569_;
goto v_reusejp_571_;
}
else
{
lean_object* v_reuseFailAlloc_573_; 
v_reuseFailAlloc_573_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_573_, 0, v_a_567_);
v___x_572_ = v_reuseFailAlloc_573_;
goto v_reusejp_571_;
}
v_reusejp_571_:
{
return v___x_572_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2___redArg___lam__0___boxed(lean_object* v_f_575_, lean_object* v_s_576_, lean_object* v_a_577_, lean_object* v_b_578_, lean_object* v___y_579_, lean_object* v___y_580_, lean_object* v___y_581_){
_start:
{
lean_object* v_res_582_; 
v_res_582_ = lp_JunkValues_Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2___redArg___lam__0(v_f_575_, v_s_576_, v_a_577_, v_b_578_, v___y_579_, v___y_580_);
lean_dec(v___y_580_);
lean_dec_ref(v___y_579_);
return v_res_582_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2___redArg(lean_object* v_map_583_, lean_object* v_init_584_, lean_object* v_f_585_, lean_object* v___y_586_, lean_object* v___y_587_){
_start:
{
lean_object* v___f_589_; lean_object* v___x_590_; 
v___f_589_ = lean_alloc_closure((void*)(lp_JunkValues_Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2___redArg___lam__0___boxed), 7, 1);
lean_closure_set(v___f_589_, 0, v_f_585_);
lean_inc_ref(v_map_583_);
v___x_590_ = lp_JunkValues_Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2_spec__3_spec__4___redArg(v___f_589_, v_map_583_, v_init_584_, v___y_586_, v___y_587_);
if (lean_obj_tag(v___x_590_) == 0)
{
lean_object* v_a_591_; lean_object* v___x_593_; uint8_t v_isShared_594_; uint8_t v_isSharedCheck_599_; 
v_a_591_ = lean_ctor_get(v___x_590_, 0);
v_isSharedCheck_599_ = !lean_is_exclusive(v___x_590_);
if (v_isSharedCheck_599_ == 0)
{
v___x_593_ = v___x_590_;
v_isShared_594_ = v_isSharedCheck_599_;
goto v_resetjp_592_;
}
else
{
lean_inc(v_a_591_);
lean_dec(v___x_590_);
v___x_593_ = lean_box(0);
v_isShared_594_ = v_isSharedCheck_599_;
goto v_resetjp_592_;
}
v_resetjp_592_:
{
lean_object* v_a_595_; lean_object* v___x_597_; 
v_a_595_ = lean_ctor_get(v_a_591_, 0);
lean_inc(v_a_595_);
lean_dec(v_a_591_);
if (v_isShared_594_ == 0)
{
lean_ctor_set(v___x_593_, 0, v_a_595_);
v___x_597_ = v___x_593_;
goto v_reusejp_596_;
}
else
{
lean_object* v_reuseFailAlloc_598_; 
v_reuseFailAlloc_598_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_598_, 0, v_a_595_);
v___x_597_ = v_reuseFailAlloc_598_;
goto v_reusejp_596_;
}
v_reusejp_596_:
{
return v___x_597_;
}
}
}
else
{
lean_object* v_a_600_; lean_object* v___x_602_; uint8_t v_isShared_603_; uint8_t v_isSharedCheck_607_; 
v_a_600_ = lean_ctor_get(v___x_590_, 0);
v_isSharedCheck_607_ = !lean_is_exclusive(v___x_590_);
if (v_isSharedCheck_607_ == 0)
{
v___x_602_ = v___x_590_;
v_isShared_603_ = v_isSharedCheck_607_;
goto v_resetjp_601_;
}
else
{
lean_inc(v_a_600_);
lean_dec(v___x_590_);
v___x_602_ = lean_box(0);
v_isShared_603_ = v_isSharedCheck_607_;
goto v_resetjp_601_;
}
v_resetjp_601_:
{
lean_object* v___x_605_; 
if (v_isShared_603_ == 0)
{
v___x_605_ = v___x_602_;
goto v_reusejp_604_;
}
else
{
lean_object* v_reuseFailAlloc_606_; 
v_reuseFailAlloc_606_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_606_, 0, v_a_600_);
v___x_605_ = v_reuseFailAlloc_606_;
goto v_reusejp_604_;
}
v_reusejp_604_:
{
return v___x_605_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2___redArg___boxed(lean_object* v_map_608_, lean_object* v_init_609_, lean_object* v_f_610_, lean_object* v___y_611_, lean_object* v___y_612_, lean_object* v___y_613_){
_start:
{
lean_object* v_res_614_; 
v_res_614_ = lp_JunkValues_Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2___redArg(v_map_608_, v_init_609_, v_f_610_, v___y_611_, v___y_612_);
lean_dec(v___y_612_);
lean_dec_ref(v___y_611_);
lean_dec_ref(v_map_608_);
return v_res_614_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_declIdsOf_spec__3___redArg(lean_object* v___x_615_, uint8_t v___x_616_, lean_object* v_as_617_, size_t v_sz_618_, size_t v_i_619_, lean_object* v_b_620_){
_start:
{
lean_object* v_a_623_; uint8_t v___x_627_; 
v___x_627_ = lean_usize_dec_lt(v_i_619_, v_sz_618_);
if (v___x_627_ == 0)
{
lean_object* v___x_628_; 
lean_dec_ref(v___x_615_);
v___x_628_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_628_, 0, v_b_620_);
return v___x_628_;
}
else
{
lean_object* v_a_629_; uint8_t v___x_630_; 
v_a_629_ = lean_array_uget_borrowed(v_as_617_, v_i_619_);
lean_inc(v_a_629_);
lean_inc_ref(v___x_615_);
v___x_630_ = l_Lean_Environment_contains(v___x_615_, v_a_629_, v___x_616_);
if (v___x_630_ == 0)
{
v_a_623_ = v_b_620_;
goto v___jp_622_;
}
else
{
uint8_t v___x_631_; 
v___x_631_ = lp_JunkValues_Array_contains___at___00JunkValues_declIdsOf_spec__0(v_b_620_, v_a_629_);
if (v___x_631_ == 0)
{
if (v___x_630_ == 0)
{
v_a_623_ = v_b_620_;
goto v___jp_622_;
}
else
{
lean_object* v___x_632_; lean_object* v___x_633_; 
lean_dec_ref(v___x_615_);
lean_inc(v_a_629_);
v___x_632_ = lean_array_push(v_b_620_, v_a_629_);
v___x_633_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_633_, 0, v___x_632_);
return v___x_633_;
}
}
else
{
v_a_623_ = v_b_620_;
goto v___jp_622_;
}
}
}
v___jp_622_:
{
size_t v___x_624_; size_t v___x_625_; 
v___x_624_ = ((size_t)1ULL);
v___x_625_ = lean_usize_add(v_i_619_, v___x_624_);
v_i_619_ = v___x_625_;
v_b_620_ = v_a_623_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_declIdsOf_spec__3___redArg___boxed(lean_object* v___x_634_, lean_object* v___x_635_, lean_object* v_as_636_, lean_object* v_sz_637_, lean_object* v_i_638_, lean_object* v_b_639_, lean_object* v___y_640_){
_start:
{
uint8_t v___x_7575__boxed_641_; size_t v_sz_boxed_642_; size_t v_i_boxed_643_; lean_object* v_res_644_; 
v___x_7575__boxed_641_ = lean_unbox(v___x_635_);
v_sz_boxed_642_ = lean_unbox_usize(v_sz_637_);
lean_dec(v_sz_637_);
v_i_boxed_643_ = lean_unbox_usize(v_i_638_);
lean_dec(v_i_638_);
v_res_644_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_declIdsOf_spec__3___redArg(v___x_634_, v___x_7575__boxed_641_, v_as_636_, v_sz_boxed_642_, v_i_boxed_643_, v_b_639_);
lean_dec_ref(v_as_636_);
return v_res_644_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Syntax_instForInTopDownOfMonad_loop___at___00Lean_Syntax_instForInTopDownOfMonad_loop___at___00JunkValues_declIdsOf_spec__4_spec__6(lean_object* v___x_657_, lean_object* v___x_658_, uint8_t v_firstChoiceOnly_659_, lean_object* v_stx_660_, lean_object* v_b_661_, lean_object* v___y_662_, lean_object* v___y_663_){
_start:
{
lean_object* v_b_666_; lean_object* v___y_670_; lean_object* v___y_671_; lean_object* v_a_697_; lean_object* v___x_707_; lean_object* v___x_708_; uint8_t v___x_709_; 
lean_inc(v_stx_660_);
v___x_707_ = l_Lean_Syntax_getKind(v_stx_660_);
v___x_708_ = ((lean_object*)(lp_JunkValues_Lean_Syntax_instForInTopDownOfMonad_loop___at___00Lean_Syntax_instForInTopDownOfMonad_loop___at___00JunkValues_declIdsOf_spec__4_spec__6___closed__6));
v___x_709_ = lean_name_eq(v___x_707_, v___x_708_);
lean_dec(v___x_707_);
if (v___x_709_ == 0)
{
v_a_697_ = v_b_661_;
goto v___jp_696_;
}
else
{
lean_object* v___x_710_; lean_object* v___x_711_; uint8_t v___x_712_; 
v___x_710_ = lean_unsigned_to_nat(0u);
v___x_711_ = l_Lean_Syntax_getArg(v_stx_660_, v___x_710_);
v___x_712_ = l_Lean_Syntax_isIdent(v___x_711_);
if (v___x_712_ == 0)
{
lean_dec(v___x_711_);
v_a_697_ = v_b_661_;
goto v___jp_696_;
}
else
{
lean_object* v___x_713_; lean_object* v___x_714_; lean_object* v___x_715_; lean_object* v___x_716_; lean_object* v___x_717_; lean_object* v___x_718_; size_t v_sz_719_; size_t v___x_720_; lean_object* v___x_721_; 
v___x_713_ = l_Lean_Syntax_getId(v___x_711_);
lean_dec(v___x_711_);
lean_inc(v___x_713_);
lean_inc(v___x_657_);
v___x_714_ = l_Lean_Name_append(v___x_657_, v___x_713_);
v___x_715_ = lean_unsigned_to_nat(2u);
v___x_716_ = lean_mk_empty_array_with_capacity(v___x_715_);
v___x_717_ = lean_array_push(v___x_716_, v___x_714_);
v___x_718_ = lean_array_push(v___x_717_, v___x_713_);
v_sz_719_ = lean_array_size(v___x_718_);
v___x_720_ = ((size_t)0ULL);
lean_inc_ref(v___x_658_);
v___x_721_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_declIdsOf_spec__3___redArg(v___x_658_, v___x_712_, v___x_718_, v_sz_719_, v___x_720_, v_b_661_);
lean_dec_ref(v___x_718_);
if (lean_obj_tag(v___x_721_) == 0)
{
lean_object* v_a_722_; 
v_a_722_ = lean_ctor_get(v___x_721_, 0);
lean_inc(v_a_722_);
lean_dec_ref_known(v___x_721_, 1);
v_a_697_ = v_a_722_;
goto v___jp_696_;
}
else
{
lean_object* v_a_723_; lean_object* v___x_725_; uint8_t v_isShared_726_; uint8_t v_isSharedCheck_730_; 
lean_dec(v_stx_660_);
lean_dec_ref(v___x_658_);
lean_dec(v___x_657_);
v_a_723_ = lean_ctor_get(v___x_721_, 0);
v_isSharedCheck_730_ = !lean_is_exclusive(v___x_721_);
if (v_isSharedCheck_730_ == 0)
{
v___x_725_ = v___x_721_;
v_isShared_726_ = v_isSharedCheck_730_;
goto v_resetjp_724_;
}
else
{
lean_inc(v_a_723_);
lean_dec(v___x_721_);
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
v___jp_665_:
{
lean_object* v___x_667_; lean_object* v___x_668_; 
v___x_667_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_667_, 0, v_b_666_);
v___x_668_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_668_, 0, v___x_667_);
return v___x_668_;
}
v___jp_669_:
{
lean_object* v___x_672_; lean_object* v___x_673_; size_t v_sz_674_; size_t v___x_675_; lean_object* v___x_676_; 
v___x_672_ = lean_box(0);
v___x_673_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_673_, 0, v___x_672_);
lean_ctor_set(v___x_673_, 1, v___y_671_);
v_sz_674_ = lean_array_size(v___y_670_);
v___x_675_ = ((size_t)0ULL);
v___x_676_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Syntax_instForInTopDownOfMonad_loop___at___00JunkValues_declIdsOf_spec__4_spec__7(v___x_657_, v___x_658_, v_firstChoiceOnly_659_, v___y_670_, v_sz_674_, v___x_675_, v___x_673_, v___y_662_, v___y_663_);
lean_dec_ref(v___y_670_);
if (lean_obj_tag(v___x_676_) == 0)
{
lean_object* v_a_677_; lean_object* v___x_679_; uint8_t v_isShared_680_; uint8_t v_isSharedCheck_687_; 
v_a_677_ = lean_ctor_get(v___x_676_, 0);
v_isSharedCheck_687_ = !lean_is_exclusive(v___x_676_);
if (v_isSharedCheck_687_ == 0)
{
v___x_679_ = v___x_676_;
v_isShared_680_ = v_isSharedCheck_687_;
goto v_resetjp_678_;
}
else
{
lean_inc(v_a_677_);
lean_dec(v___x_676_);
v___x_679_ = lean_box(0);
v_isShared_680_ = v_isSharedCheck_687_;
goto v_resetjp_678_;
}
v_resetjp_678_:
{
lean_object* v_fst_681_; 
v_fst_681_ = lean_ctor_get(v_a_677_, 0);
if (lean_obj_tag(v_fst_681_) == 0)
{
lean_object* v_snd_682_; 
lean_del_object(v___x_679_);
v_snd_682_ = lean_ctor_get(v_a_677_, 1);
lean_inc(v_snd_682_);
lean_dec(v_a_677_);
v_b_666_ = v_snd_682_;
goto v___jp_665_;
}
else
{
lean_object* v_val_683_; lean_object* v___x_685_; 
lean_inc_ref(v_fst_681_);
lean_dec(v_a_677_);
v_val_683_ = lean_ctor_get(v_fst_681_, 0);
lean_inc(v_val_683_);
lean_dec_ref_known(v_fst_681_, 1);
if (v_isShared_680_ == 0)
{
lean_ctor_set(v___x_679_, 0, v_val_683_);
v___x_685_ = v___x_679_;
goto v_reusejp_684_;
}
else
{
lean_object* v_reuseFailAlloc_686_; 
v_reuseFailAlloc_686_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_686_, 0, v_val_683_);
v___x_685_ = v_reuseFailAlloc_686_;
goto v_reusejp_684_;
}
v_reusejp_684_:
{
return v___x_685_;
}
}
}
}
else
{
lean_object* v_a_688_; lean_object* v___x_690_; uint8_t v_isShared_691_; uint8_t v_isSharedCheck_695_; 
v_a_688_ = lean_ctor_get(v___x_676_, 0);
v_isSharedCheck_695_ = !lean_is_exclusive(v___x_676_);
if (v_isSharedCheck_695_ == 0)
{
v___x_690_ = v___x_676_;
v_isShared_691_ = v_isSharedCheck_695_;
goto v_resetjp_689_;
}
else
{
lean_inc(v_a_688_);
lean_dec(v___x_676_);
v___x_690_ = lean_box(0);
v_isShared_691_ = v_isSharedCheck_695_;
goto v_resetjp_689_;
}
v_resetjp_689_:
{
lean_object* v___x_693_; 
if (v_isShared_691_ == 0)
{
v___x_693_ = v___x_690_;
goto v_reusejp_692_;
}
else
{
lean_object* v_reuseFailAlloc_694_; 
v_reuseFailAlloc_694_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_694_, 0, v_a_688_);
v___x_693_ = v_reuseFailAlloc_694_;
goto v_reusejp_692_;
}
v_reusejp_692_:
{
return v___x_693_;
}
}
}
}
v___jp_696_:
{
if (lean_obj_tag(v_stx_660_) == 1)
{
if (v_firstChoiceOnly_659_ == 0)
{
lean_object* v_args_698_; 
v_args_698_ = lean_ctor_get(v_stx_660_, 2);
lean_inc_ref(v_args_698_);
lean_dec_ref_known(v_stx_660_, 3);
v___y_670_ = v_args_698_;
v___y_671_ = v_a_697_;
goto v___jp_669_;
}
else
{
lean_object* v_kind_699_; lean_object* v_args_700_; lean_object* v___x_701_; uint8_t v___x_702_; 
v_kind_699_ = lean_ctor_get(v_stx_660_, 1);
lean_inc(v_kind_699_);
v_args_700_ = lean_ctor_get(v_stx_660_, 2);
lean_inc_ref(v_args_700_);
lean_dec_ref_known(v_stx_660_, 3);
v___x_701_ = ((lean_object*)(lp_JunkValues_Lean_Syntax_instForInTopDownOfMonad_loop___at___00Lean_Syntax_instForInTopDownOfMonad_loop___at___00JunkValues_declIdsOf_spec__4_spec__6___closed__1));
v___x_702_ = lean_name_eq(v_kind_699_, v___x_701_);
lean_dec(v_kind_699_);
if (v___x_702_ == 0)
{
v___y_670_ = v_args_700_;
v___y_671_ = v_a_697_;
goto v___jp_669_;
}
else
{
lean_object* v___x_703_; lean_object* v___x_704_; lean_object* v___x_705_; 
v___x_703_ = lean_box(0);
v___x_704_ = lean_unsigned_to_nat(0u);
v___x_705_ = lean_array_get(v___x_703_, v_args_700_, v___x_704_);
lean_dec_ref(v_args_700_);
v_stx_660_ = v___x_705_;
v_b_661_ = v_a_697_;
goto _start;
}
}
}
else
{
lean_dec(v_stx_660_);
lean_dec_ref(v___x_658_);
lean_dec(v___x_657_);
v_b_666_ = v_a_697_;
goto v___jp_665_;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Syntax_instForInTopDownOfMonad_loop___at___00JunkValues_declIdsOf_spec__4_spec__7(lean_object* v___x_731_, lean_object* v___x_732_, uint8_t v_firstChoiceOnly_733_, lean_object* v_as_734_, size_t v_sz_735_, size_t v_i_736_, lean_object* v_b_737_, lean_object* v___y_738_, lean_object* v___y_739_){
_start:
{
uint8_t v___x_741_; 
v___x_741_ = lean_usize_dec_lt(v_i_736_, v_sz_735_);
if (v___x_741_ == 0)
{
lean_object* v___x_742_; 
lean_dec_ref(v___x_732_);
lean_dec(v___x_731_);
v___x_742_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_742_, 0, v_b_737_);
return v___x_742_;
}
else
{
lean_object* v_snd_743_; lean_object* v___x_745_; uint8_t v_isShared_746_; uint8_t v_isSharedCheck_777_; 
v_snd_743_ = lean_ctor_get(v_b_737_, 1);
v_isSharedCheck_777_ = !lean_is_exclusive(v_b_737_);
if (v_isSharedCheck_777_ == 0)
{
lean_object* v_unused_778_; 
v_unused_778_ = lean_ctor_get(v_b_737_, 0);
lean_dec(v_unused_778_);
v___x_745_ = v_b_737_;
v_isShared_746_ = v_isSharedCheck_777_;
goto v_resetjp_744_;
}
else
{
lean_inc(v_snd_743_);
lean_dec(v_b_737_);
v___x_745_ = lean_box(0);
v_isShared_746_ = v_isSharedCheck_777_;
goto v_resetjp_744_;
}
v_resetjp_744_:
{
lean_object* v_a_747_; lean_object* v___x_748_; 
v_a_747_ = lean_array_uget_borrowed(v_as_734_, v_i_736_);
lean_inc(v_snd_743_);
lean_inc(v_a_747_);
lean_inc_ref(v___x_732_);
lean_inc(v___x_731_);
v___x_748_ = lp_JunkValues_Lean_Syntax_instForInTopDownOfMonad_loop___at___00Lean_Syntax_instForInTopDownOfMonad_loop___at___00JunkValues_declIdsOf_spec__4_spec__6(v___x_731_, v___x_732_, v_firstChoiceOnly_733_, v_a_747_, v_snd_743_, v___y_738_, v___y_739_);
if (lean_obj_tag(v___x_748_) == 0)
{
lean_object* v_a_749_; lean_object* v___x_751_; uint8_t v_isShared_752_; uint8_t v_isSharedCheck_768_; 
v_a_749_ = lean_ctor_get(v___x_748_, 0);
v_isSharedCheck_768_ = !lean_is_exclusive(v___x_748_);
if (v_isSharedCheck_768_ == 0)
{
v___x_751_ = v___x_748_;
v_isShared_752_ = v_isSharedCheck_768_;
goto v_resetjp_750_;
}
else
{
lean_inc(v_a_749_);
lean_dec(v___x_748_);
v___x_751_ = lean_box(0);
v_isShared_752_ = v_isSharedCheck_768_;
goto v_resetjp_750_;
}
v_resetjp_750_:
{
if (lean_obj_tag(v_a_749_) == 0)
{
lean_object* v___x_753_; lean_object* v___x_755_; 
lean_dec_ref(v___x_732_);
lean_dec(v___x_731_);
v___x_753_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_753_, 0, v_a_749_);
if (v_isShared_746_ == 0)
{
lean_ctor_set(v___x_745_, 0, v___x_753_);
v___x_755_ = v___x_745_;
goto v_reusejp_754_;
}
else
{
lean_object* v_reuseFailAlloc_759_; 
v_reuseFailAlloc_759_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_759_, 0, v___x_753_);
lean_ctor_set(v_reuseFailAlloc_759_, 1, v_snd_743_);
v___x_755_ = v_reuseFailAlloc_759_;
goto v_reusejp_754_;
}
v_reusejp_754_:
{
lean_object* v___x_757_; 
if (v_isShared_752_ == 0)
{
lean_ctor_set(v___x_751_, 0, v___x_755_);
v___x_757_ = v___x_751_;
goto v_reusejp_756_;
}
else
{
lean_object* v_reuseFailAlloc_758_; 
v_reuseFailAlloc_758_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_758_, 0, v___x_755_);
v___x_757_ = v_reuseFailAlloc_758_;
goto v_reusejp_756_;
}
v_reusejp_756_:
{
return v___x_757_;
}
}
}
else
{
lean_object* v_a_760_; lean_object* v___x_761_; lean_object* v___x_763_; 
lean_del_object(v___x_751_);
lean_dec(v_snd_743_);
v_a_760_ = lean_ctor_get(v_a_749_, 0);
lean_inc(v_a_760_);
lean_dec_ref_known(v_a_749_, 1);
v___x_761_ = lean_box(0);
if (v_isShared_746_ == 0)
{
lean_ctor_set(v___x_745_, 1, v_a_760_);
lean_ctor_set(v___x_745_, 0, v___x_761_);
v___x_763_ = v___x_745_;
goto v_reusejp_762_;
}
else
{
lean_object* v_reuseFailAlloc_767_; 
v_reuseFailAlloc_767_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_767_, 0, v___x_761_);
lean_ctor_set(v_reuseFailAlloc_767_, 1, v_a_760_);
v___x_763_ = v_reuseFailAlloc_767_;
goto v_reusejp_762_;
}
v_reusejp_762_:
{
size_t v___x_764_; size_t v___x_765_; 
v___x_764_ = ((size_t)1ULL);
v___x_765_ = lean_usize_add(v_i_736_, v___x_764_);
v_i_736_ = v___x_765_;
v_b_737_ = v___x_763_;
goto _start;
}
}
}
}
else
{
lean_object* v_a_769_; lean_object* v___x_771_; uint8_t v_isShared_772_; uint8_t v_isSharedCheck_776_; 
lean_del_object(v___x_745_);
lean_dec(v_snd_743_);
lean_dec_ref(v___x_732_);
lean_dec(v___x_731_);
v_a_769_ = lean_ctor_get(v___x_748_, 0);
v_isSharedCheck_776_ = !lean_is_exclusive(v___x_748_);
if (v_isSharedCheck_776_ == 0)
{
v___x_771_ = v___x_748_;
v_isShared_772_ = v_isSharedCheck_776_;
goto v_resetjp_770_;
}
else
{
lean_inc(v_a_769_);
lean_dec(v___x_748_);
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
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Syntax_instForInTopDownOfMonad_loop___at___00JunkValues_declIdsOf_spec__4_spec__7___boxed(lean_object* v___x_779_, lean_object* v___x_780_, lean_object* v_firstChoiceOnly_781_, lean_object* v_as_782_, lean_object* v_sz_783_, lean_object* v_i_784_, lean_object* v_b_785_, lean_object* v___y_786_, lean_object* v___y_787_, lean_object* v___y_788_){
_start:
{
uint8_t v_firstChoiceOnly_boxed_789_; size_t v_sz_boxed_790_; size_t v_i_boxed_791_; lean_object* v_res_792_; 
v_firstChoiceOnly_boxed_789_ = lean_unbox(v_firstChoiceOnly_781_);
v_sz_boxed_790_ = lean_unbox_usize(v_sz_783_);
lean_dec(v_sz_783_);
v_i_boxed_791_ = lean_unbox_usize(v_i_784_);
lean_dec(v_i_784_);
v_res_792_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Syntax_instForInTopDownOfMonad_loop___at___00JunkValues_declIdsOf_spec__4_spec__7(v___x_779_, v___x_780_, v_firstChoiceOnly_boxed_789_, v_as_782_, v_sz_boxed_790_, v_i_boxed_791_, v_b_785_, v___y_786_, v___y_787_);
lean_dec(v___y_787_);
lean_dec_ref(v___y_786_);
lean_dec_ref(v_as_782_);
return v_res_792_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Syntax_instForInTopDownOfMonad_loop___at___00Lean_Syntax_instForInTopDownOfMonad_loop___at___00JunkValues_declIdsOf_spec__4_spec__6___boxed(lean_object* v___x_793_, lean_object* v___x_794_, lean_object* v_firstChoiceOnly_795_, lean_object* v_stx_796_, lean_object* v_b_797_, lean_object* v___y_798_, lean_object* v___y_799_, lean_object* v___y_800_){
_start:
{
uint8_t v_firstChoiceOnly_boxed_801_; lean_object* v_res_802_; 
v_firstChoiceOnly_boxed_801_ = lean_unbox(v_firstChoiceOnly_795_);
v_res_802_ = lp_JunkValues_Lean_Syntax_instForInTopDownOfMonad_loop___at___00Lean_Syntax_instForInTopDownOfMonad_loop___at___00JunkValues_declIdsOf_spec__4_spec__6(v___x_793_, v___x_794_, v_firstChoiceOnly_boxed_801_, v_stx_796_, v_b_797_, v___y_798_, v___y_799_);
lean_dec(v___y_799_);
lean_dec_ref(v___y_798_);
return v_res_802_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Syntax_instForInTopDownOfMonad_loop___at___00JunkValues_declIdsOf_spec__4(lean_object* v___x_803_, lean_object* v___x_804_, uint8_t v_firstChoiceOnly_805_, lean_object* v_stx_806_, lean_object* v_b_807_, lean_object* v___y_808_, lean_object* v___y_809_){
_start:
{
lean_object* v_b_812_; lean_object* v___y_816_; lean_object* v___y_817_; lean_object* v_a_843_; lean_object* v___x_853_; lean_object* v___x_854_; uint8_t v___x_855_; 
lean_inc(v_stx_806_);
v___x_853_ = l_Lean_Syntax_getKind(v_stx_806_);
v___x_854_ = ((lean_object*)(lp_JunkValues_Lean_Syntax_instForInTopDownOfMonad_loop___at___00Lean_Syntax_instForInTopDownOfMonad_loop___at___00JunkValues_declIdsOf_spec__4_spec__6___closed__6));
v___x_855_ = lean_name_eq(v___x_853_, v___x_854_);
lean_dec(v___x_853_);
if (v___x_855_ == 0)
{
v_a_843_ = v_b_807_;
goto v___jp_842_;
}
else
{
lean_object* v___x_856_; lean_object* v___x_857_; uint8_t v___x_858_; 
v___x_856_ = lean_unsigned_to_nat(0u);
v___x_857_ = l_Lean_Syntax_getArg(v_stx_806_, v___x_856_);
v___x_858_ = l_Lean_Syntax_isIdent(v___x_857_);
if (v___x_858_ == 0)
{
lean_dec(v___x_857_);
v_a_843_ = v_b_807_;
goto v___jp_842_;
}
else
{
lean_object* v___x_859_; lean_object* v___x_860_; lean_object* v___x_861_; lean_object* v___x_862_; lean_object* v___x_863_; lean_object* v___x_864_; size_t v_sz_865_; size_t v___x_866_; lean_object* v___x_867_; 
v___x_859_ = l_Lean_Syntax_getId(v___x_857_);
lean_dec(v___x_857_);
lean_inc(v___x_859_);
lean_inc(v___x_804_);
v___x_860_ = l_Lean_Name_append(v___x_804_, v___x_859_);
v___x_861_ = lean_unsigned_to_nat(2u);
v___x_862_ = lean_mk_empty_array_with_capacity(v___x_861_);
v___x_863_ = lean_array_push(v___x_862_, v___x_860_);
v___x_864_ = lean_array_push(v___x_863_, v___x_859_);
v_sz_865_ = lean_array_size(v___x_864_);
v___x_866_ = ((size_t)0ULL);
lean_inc_ref(v___x_803_);
v___x_867_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_declIdsOf_spec__3___redArg(v___x_803_, v___x_858_, v___x_864_, v_sz_865_, v___x_866_, v_b_807_);
lean_dec_ref(v___x_864_);
if (lean_obj_tag(v___x_867_) == 0)
{
lean_object* v_a_868_; 
v_a_868_ = lean_ctor_get(v___x_867_, 0);
lean_inc(v_a_868_);
lean_dec_ref_known(v___x_867_, 1);
v_a_843_ = v_a_868_;
goto v___jp_842_;
}
else
{
lean_object* v_a_869_; lean_object* v___x_871_; uint8_t v_isShared_872_; uint8_t v_isSharedCheck_876_; 
lean_dec(v_stx_806_);
lean_dec(v___x_804_);
lean_dec_ref(v___x_803_);
v_a_869_ = lean_ctor_get(v___x_867_, 0);
v_isSharedCheck_876_ = !lean_is_exclusive(v___x_867_);
if (v_isSharedCheck_876_ == 0)
{
v___x_871_ = v___x_867_;
v_isShared_872_ = v_isSharedCheck_876_;
goto v_resetjp_870_;
}
else
{
lean_inc(v_a_869_);
lean_dec(v___x_867_);
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
v_reuseFailAlloc_875_ = lean_alloc_ctor(1, 1, 0);
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
}
}
v___jp_811_:
{
lean_object* v___x_813_; lean_object* v___x_814_; 
v___x_813_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_813_, 0, v_b_812_);
v___x_814_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_814_, 0, v___x_813_);
return v___x_814_;
}
v___jp_815_:
{
lean_object* v___x_818_; lean_object* v___x_819_; size_t v_sz_820_; size_t v___x_821_; lean_object* v___x_822_; 
v___x_818_ = lean_box(0);
v___x_819_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_819_, 0, v___x_818_);
lean_ctor_set(v___x_819_, 1, v___y_817_);
v_sz_820_ = lean_array_size(v___y_816_);
v___x_821_ = ((size_t)0ULL);
v___x_822_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Syntax_instForInTopDownOfMonad_loop___at___00JunkValues_declIdsOf_spec__4_spec__7(v___x_804_, v___x_803_, v_firstChoiceOnly_805_, v___y_816_, v_sz_820_, v___x_821_, v___x_819_, v___y_808_, v___y_809_);
lean_dec_ref(v___y_816_);
if (lean_obj_tag(v___x_822_) == 0)
{
lean_object* v_a_823_; lean_object* v___x_825_; uint8_t v_isShared_826_; uint8_t v_isSharedCheck_833_; 
v_a_823_ = lean_ctor_get(v___x_822_, 0);
v_isSharedCheck_833_ = !lean_is_exclusive(v___x_822_);
if (v_isSharedCheck_833_ == 0)
{
v___x_825_ = v___x_822_;
v_isShared_826_ = v_isSharedCheck_833_;
goto v_resetjp_824_;
}
else
{
lean_inc(v_a_823_);
lean_dec(v___x_822_);
v___x_825_ = lean_box(0);
v_isShared_826_ = v_isSharedCheck_833_;
goto v_resetjp_824_;
}
v_resetjp_824_:
{
lean_object* v_fst_827_; 
v_fst_827_ = lean_ctor_get(v_a_823_, 0);
if (lean_obj_tag(v_fst_827_) == 0)
{
lean_object* v_snd_828_; 
lean_del_object(v___x_825_);
v_snd_828_ = lean_ctor_get(v_a_823_, 1);
lean_inc(v_snd_828_);
lean_dec(v_a_823_);
v_b_812_ = v_snd_828_;
goto v___jp_811_;
}
else
{
lean_object* v_val_829_; lean_object* v___x_831_; 
lean_inc_ref(v_fst_827_);
lean_dec(v_a_823_);
v_val_829_ = lean_ctor_get(v_fst_827_, 0);
lean_inc(v_val_829_);
lean_dec_ref_known(v_fst_827_, 1);
if (v_isShared_826_ == 0)
{
lean_ctor_set(v___x_825_, 0, v_val_829_);
v___x_831_ = v___x_825_;
goto v_reusejp_830_;
}
else
{
lean_object* v_reuseFailAlloc_832_; 
v_reuseFailAlloc_832_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_832_, 0, v_val_829_);
v___x_831_ = v_reuseFailAlloc_832_;
goto v_reusejp_830_;
}
v_reusejp_830_:
{
return v___x_831_;
}
}
}
}
else
{
lean_object* v_a_834_; lean_object* v___x_836_; uint8_t v_isShared_837_; uint8_t v_isSharedCheck_841_; 
v_a_834_ = lean_ctor_get(v___x_822_, 0);
v_isSharedCheck_841_ = !lean_is_exclusive(v___x_822_);
if (v_isSharedCheck_841_ == 0)
{
v___x_836_ = v___x_822_;
v_isShared_837_ = v_isSharedCheck_841_;
goto v_resetjp_835_;
}
else
{
lean_inc(v_a_834_);
lean_dec(v___x_822_);
v___x_836_ = lean_box(0);
v_isShared_837_ = v_isSharedCheck_841_;
goto v_resetjp_835_;
}
v_resetjp_835_:
{
lean_object* v___x_839_; 
if (v_isShared_837_ == 0)
{
v___x_839_ = v___x_836_;
goto v_reusejp_838_;
}
else
{
lean_object* v_reuseFailAlloc_840_; 
v_reuseFailAlloc_840_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_840_, 0, v_a_834_);
v___x_839_ = v_reuseFailAlloc_840_;
goto v_reusejp_838_;
}
v_reusejp_838_:
{
return v___x_839_;
}
}
}
}
v___jp_842_:
{
if (lean_obj_tag(v_stx_806_) == 1)
{
if (v_firstChoiceOnly_805_ == 0)
{
lean_object* v_args_844_; 
v_args_844_ = lean_ctor_get(v_stx_806_, 2);
lean_inc_ref(v_args_844_);
lean_dec_ref_known(v_stx_806_, 3);
v___y_816_ = v_args_844_;
v___y_817_ = v_a_843_;
goto v___jp_815_;
}
else
{
lean_object* v_kind_845_; lean_object* v_args_846_; lean_object* v___x_847_; uint8_t v___x_848_; 
v_kind_845_ = lean_ctor_get(v_stx_806_, 1);
lean_inc(v_kind_845_);
v_args_846_ = lean_ctor_get(v_stx_806_, 2);
lean_inc_ref(v_args_846_);
lean_dec_ref_known(v_stx_806_, 3);
v___x_847_ = ((lean_object*)(lp_JunkValues_Lean_Syntax_instForInTopDownOfMonad_loop___at___00Lean_Syntax_instForInTopDownOfMonad_loop___at___00JunkValues_declIdsOf_spec__4_spec__6___closed__1));
v___x_848_ = lean_name_eq(v_kind_845_, v___x_847_);
lean_dec(v_kind_845_);
if (v___x_848_ == 0)
{
v___y_816_ = v_args_846_;
v___y_817_ = v_a_843_;
goto v___jp_815_;
}
else
{
lean_object* v___x_849_; lean_object* v___x_850_; lean_object* v___x_851_; lean_object* v___x_852_; 
v___x_849_ = lean_box(0);
v___x_850_ = lean_unsigned_to_nat(0u);
v___x_851_ = lean_array_get(v___x_849_, v_args_846_, v___x_850_);
lean_dec_ref(v_args_846_);
v___x_852_ = lp_JunkValues_Lean_Syntax_instForInTopDownOfMonad_loop___at___00Lean_Syntax_instForInTopDownOfMonad_loop___at___00JunkValues_declIdsOf_spec__4_spec__6(v___x_804_, v___x_803_, v_firstChoiceOnly_805_, v___x_851_, v_a_843_, v___y_808_, v___y_809_);
return v___x_852_;
}
}
}
else
{
lean_dec(v_stx_806_);
lean_dec(v___x_804_);
lean_dec_ref(v___x_803_);
v_b_812_ = v_a_843_;
goto v___jp_811_;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Syntax_instForInTopDownOfMonad_loop___at___00JunkValues_declIdsOf_spec__4___boxed(lean_object* v___x_877_, lean_object* v___x_878_, lean_object* v_firstChoiceOnly_879_, lean_object* v_stx_880_, lean_object* v_b_881_, lean_object* v___y_882_, lean_object* v___y_883_, lean_object* v___y_884_){
_start:
{
uint8_t v_firstChoiceOnly_boxed_885_; lean_object* v_res_886_; 
v_firstChoiceOnly_boxed_885_ = lean_unbox(v_firstChoiceOnly_879_);
v_res_886_ = lp_JunkValues_Lean_Syntax_instForInTopDownOfMonad_loop___at___00JunkValues_declIdsOf_spec__4(v___x_877_, v___x_878_, v_firstChoiceOnly_boxed_885_, v_stx_880_, v_b_881_, v___y_882_, v___y_883_);
lean_dec(v___y_883_);
lean_dec_ref(v___y_882_);
return v_res_886_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_declIdsOf(lean_object* v_stx_889_, lean_object* v_a_890_, lean_object* v_a_891_){
_start:
{
lean_object* v___x_893_; 
v___x_893_ = l_Lean_Elab_Command_getScope___redArg(v_a_891_);
if (lean_obj_tag(v___x_893_) == 0)
{
lean_object* v_a_894_; lean_object* v___x_895_; uint8_t v___x_896_; lean_object* v___x_897_; uint8_t v_firstChoiceOnly_898_; lean_object* v_stx_899_; lean_object* v_currNamespace_900_; lean_object* v_env_901_; lean_object* v___x_902_; lean_object* v___x_903_; lean_object* v___x_904_; 
v_a_894_ = lean_ctor_get(v___x_893_, 0);
lean_inc(v_a_894_);
lean_dec_ref_known(v___x_893_, 1);
v___x_895_ = lean_st_ref_get(v_a_891_);
v___x_896_ = 0;
v___x_897_ = l_Lean_Syntax_topDown(v_stx_889_, v___x_896_);
v_firstChoiceOnly_898_ = lean_ctor_get_uint8(v___x_897_, sizeof(void*)*1);
v_stx_899_ = lean_ctor_get(v___x_897_, 0);
lean_inc(v_stx_899_);
lean_dec_ref(v___x_897_);
v_currNamespace_900_ = lean_ctor_get(v_a_894_, 2);
lean_inc(v_currNamespace_900_);
lean_dec(v_a_894_);
v_env_901_ = lean_ctor_get(v___x_895_, 0);
lean_inc_ref_n(v_env_901_, 2);
lean_dec(v___x_895_);
v___x_902_ = lean_unsigned_to_nat(0u);
v___x_903_ = ((lean_object*)(lp_JunkValues_JunkValues_declIdsOf___closed__0));
v___x_904_ = lp_JunkValues_Lean_Syntax_instForInTopDownOfMonad_loop___at___00JunkValues_declIdsOf_spec__4(v_env_901_, v_currNamespace_900_, v_firstChoiceOnly_898_, v_stx_899_, v___x_903_, v_a_890_, v_a_891_);
if (lean_obj_tag(v___x_904_) == 0)
{
lean_object* v_a_905_; lean_object* v_a_907_; lean_object* v_a_912_; 
v_a_905_ = lean_ctor_get(v___x_904_, 0);
lean_inc(v_a_905_);
lean_dec_ref_known(v___x_904_, 1);
v_a_912_ = lean_ctor_get(v_a_905_, 0);
lean_inc(v_a_912_);
lean_dec(v_a_905_);
v_a_907_ = v_a_912_;
goto v___jp_906_;
v___jp_906_:
{
lean_object* v___x_908_; lean_object* v_map_u2082_909_; lean_object* v___f_910_; lean_object* v___x_911_; 
v___x_908_ = l_Lean_Environment_constants(v_env_901_);
v_map_u2082_909_ = lean_ctor_get(v___x_908_, 1);
lean_inc_ref(v_map_u2082_909_);
lean_dec_ref(v___x_908_);
lean_inc_ref(v_a_907_);
v___f_910_ = lean_alloc_closure((void*)(lp_JunkValues_JunkValues_declIdsOf___lam__0___boxed), 7, 2);
lean_closure_set(v___f_910_, 0, v_a_907_);
lean_closure_set(v___f_910_, 1, v___x_902_);
v___x_911_ = lp_JunkValues_Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2___redArg(v_map_u2082_909_, v_a_907_, v___f_910_, v_a_890_, v_a_891_);
lean_dec_ref(v_map_u2082_909_);
return v___x_911_;
}
}
else
{
lean_object* v_a_913_; lean_object* v___x_915_; uint8_t v_isShared_916_; uint8_t v_isSharedCheck_920_; 
lean_dec_ref(v_env_901_);
v_a_913_ = lean_ctor_get(v___x_904_, 0);
v_isSharedCheck_920_ = !lean_is_exclusive(v___x_904_);
if (v_isSharedCheck_920_ == 0)
{
v___x_915_ = v___x_904_;
v_isShared_916_ = v_isSharedCheck_920_;
goto v_resetjp_914_;
}
else
{
lean_inc(v_a_913_);
lean_dec(v___x_904_);
v___x_915_ = lean_box(0);
v_isShared_916_ = v_isSharedCheck_920_;
goto v_resetjp_914_;
}
v_resetjp_914_:
{
lean_object* v___x_918_; 
if (v_isShared_916_ == 0)
{
v___x_918_ = v___x_915_;
goto v_reusejp_917_;
}
else
{
lean_object* v_reuseFailAlloc_919_; 
v_reuseFailAlloc_919_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_919_, 0, v_a_913_);
v___x_918_ = v_reuseFailAlloc_919_;
goto v_reusejp_917_;
}
v_reusejp_917_:
{
return v___x_918_;
}
}
}
}
else
{
lean_object* v_a_921_; lean_object* v___x_923_; uint8_t v_isShared_924_; uint8_t v_isSharedCheck_928_; 
lean_dec(v_stx_889_);
v_a_921_ = lean_ctor_get(v___x_893_, 0);
v_isSharedCheck_928_ = !lean_is_exclusive(v___x_893_);
if (v_isSharedCheck_928_ == 0)
{
v___x_923_ = v___x_893_;
v_isShared_924_ = v_isSharedCheck_928_;
goto v_resetjp_922_;
}
else
{
lean_inc(v_a_921_);
lean_dec(v___x_893_);
v___x_923_ = lean_box(0);
v_isShared_924_ = v_isSharedCheck_928_;
goto v_resetjp_922_;
}
v_resetjp_922_:
{
lean_object* v___x_926_; 
if (v_isShared_924_ == 0)
{
v___x_926_ = v___x_923_;
goto v_reusejp_925_;
}
else
{
lean_object* v_reuseFailAlloc_927_; 
v_reuseFailAlloc_927_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_927_, 0, v_a_921_);
v___x_926_ = v_reuseFailAlloc_927_;
goto v_reusejp_925_;
}
v_reusejp_925_:
{
return v___x_926_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_declIdsOf___boxed(lean_object* v_stx_929_, lean_object* v_a_930_, lean_object* v_a_931_, lean_object* v_a_932_){
_start:
{
lean_object* v_res_933_; 
v_res_933_ = lp_JunkValues_JunkValues_declIdsOf(v_stx_929_, v_a_930_, v_a_931_);
lean_dec(v_a_931_);
lean_dec_ref(v_a_930_);
return v_res_933_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2(lean_object* v_00_u03c3_934_, lean_object* v_00_u03b2_935_, lean_object* v_map_936_, lean_object* v_init_937_, lean_object* v_f_938_, lean_object* v___y_939_, lean_object* v___y_940_){
_start:
{
lean_object* v___x_942_; 
v___x_942_ = lp_JunkValues_Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2___redArg(v_map_936_, v_init_937_, v_f_938_, v___y_939_, v___y_940_);
return v___x_942_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2___boxed(lean_object* v_00_u03c3_943_, lean_object* v_00_u03b2_944_, lean_object* v_map_945_, lean_object* v_init_946_, lean_object* v_f_947_, lean_object* v___y_948_, lean_object* v___y_949_, lean_object* v___y_950_){
_start:
{
lean_object* v_res_951_; 
v_res_951_ = lp_JunkValues_Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2(v_00_u03c3_943_, v_00_u03b2_944_, v_map_945_, v_init_946_, v_f_947_, v___y_948_, v___y_949_);
lean_dec(v___y_949_);
lean_dec_ref(v___y_948_);
lean_dec_ref(v_map_945_);
return v_res_951_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_declIdsOf_spec__3(lean_object* v___x_952_, uint8_t v___x_953_, lean_object* v_as_954_, size_t v_sz_955_, size_t v_i_956_, lean_object* v_b_957_, lean_object* v___y_958_, lean_object* v___y_959_){
_start:
{
lean_object* v___x_961_; 
v___x_961_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_declIdsOf_spec__3___redArg(v___x_952_, v___x_953_, v_as_954_, v_sz_955_, v_i_956_, v_b_957_);
return v___x_961_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_declIdsOf_spec__3___boxed(lean_object* v___x_962_, lean_object* v___x_963_, lean_object* v_as_964_, lean_object* v_sz_965_, lean_object* v_i_966_, lean_object* v_b_967_, lean_object* v___y_968_, lean_object* v___y_969_, lean_object* v___y_970_){
_start:
{
uint8_t v___x_8108__boxed_971_; size_t v_sz_boxed_972_; size_t v_i_boxed_973_; lean_object* v_res_974_; 
v___x_8108__boxed_971_ = lean_unbox(v___x_963_);
v_sz_boxed_972_ = lean_unbox_usize(v_sz_965_);
lean_dec(v_sz_965_);
v_i_boxed_973_ = lean_unbox_usize(v_i_966_);
lean_dec(v_i_966_);
v_res_974_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_declIdsOf_spec__3(v___x_962_, v___x_8108__boxed_971_, v_as_964_, v_sz_boxed_972_, v_i_boxed_973_, v_b_967_, v___y_968_, v___y_969_);
lean_dec(v___y_969_);
lean_dec_ref(v___y_968_);
lean_dec_ref(v_as_964_);
return v_res_974_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2_spec__3___redArg(lean_object* v_map_975_, lean_object* v_f_976_, lean_object* v_init_977_, lean_object* v___y_978_, lean_object* v___y_979_){
_start:
{
lean_object* v___x_981_; 
v___x_981_ = lp_JunkValues_Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2_spec__3_spec__4___redArg(v_f_976_, v_map_975_, v_init_977_, v___y_978_, v___y_979_);
return v___x_981_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2_spec__3___redArg___boxed(lean_object* v_map_982_, lean_object* v_f_983_, lean_object* v_init_984_, lean_object* v___y_985_, lean_object* v___y_986_, lean_object* v___y_987_){
_start:
{
lean_object* v_res_988_; 
v_res_988_ = lp_JunkValues_Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2_spec__3___redArg(v_map_982_, v_f_983_, v_init_984_, v___y_985_, v___y_986_);
lean_dec(v___y_986_);
lean_dec_ref(v___y_985_);
return v_res_988_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2_spec__3(lean_object* v_00_u03c3_989_, lean_object* v_00_u03c3_990_, lean_object* v_00_u03b2_991_, lean_object* v_map_992_, lean_object* v_f_993_, lean_object* v_init_994_, lean_object* v___y_995_, lean_object* v___y_996_){
_start:
{
lean_object* v___x_998_; 
v___x_998_ = lp_JunkValues_Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2_spec__3_spec__4___redArg(v_f_993_, v_map_992_, v_init_994_, v___y_995_, v___y_996_);
return v___x_998_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2_spec__3___boxed(lean_object* v_00_u03c3_999_, lean_object* v_00_u03c3_1000_, lean_object* v_00_u03b2_1001_, lean_object* v_map_1002_, lean_object* v_f_1003_, lean_object* v_init_1004_, lean_object* v___y_1005_, lean_object* v___y_1006_, lean_object* v___y_1007_){
_start:
{
lean_object* v_res_1008_; 
v_res_1008_ = lp_JunkValues_Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2_spec__3(v_00_u03c3_999_, v_00_u03c3_1000_, v_00_u03b2_1001_, v_map_1002_, v_f_1003_, v_init_1004_, v___y_1005_, v___y_1006_);
lean_dec(v___y_1006_);
lean_dec_ref(v___y_1005_);
return v_res_1008_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2_spec__3_spec__4(lean_object* v_00_u03c3_1009_, lean_object* v_00_u03c3_1010_, lean_object* v_00_u03b1_1011_, lean_object* v_00_u03b2_1012_, lean_object* v_f_1013_, lean_object* v_x_1014_, lean_object* v_x_1015_, lean_object* v___y_1016_, lean_object* v___y_1017_){
_start:
{
lean_object* v___x_1019_; 
v___x_1019_ = lp_JunkValues_Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2_spec__3_spec__4___redArg(v_f_1013_, v_x_1014_, v_x_1015_, v___y_1016_, v___y_1017_);
return v___x_1019_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2_spec__3_spec__4___boxed(lean_object* v_00_u03c3_1020_, lean_object* v_00_u03c3_1021_, lean_object* v_00_u03b1_1022_, lean_object* v_00_u03b2_1023_, lean_object* v_f_1024_, lean_object* v_x_1025_, lean_object* v_x_1026_, lean_object* v___y_1027_, lean_object* v___y_1028_, lean_object* v___y_1029_){
_start:
{
lean_object* v_res_1030_; 
v_res_1030_ = lp_JunkValues_Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2_spec__3_spec__4(v_00_u03c3_1020_, v_00_u03c3_1021_, v_00_u03b1_1022_, v_00_u03b2_1023_, v_f_1024_, v_x_1025_, v_x_1026_, v___y_1027_, v___y_1028_);
lean_dec(v___y_1028_);
lean_dec_ref(v___y_1027_);
return v_res_1030_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2_spec__3_spec__4_spec__7(lean_object* v_00_u03b1_1031_, lean_object* v_00_u03b2_1032_, lean_object* v_00_u03c3_1033_, lean_object* v_00_u03c3_1034_, lean_object* v_f_1035_, lean_object* v_as_1036_, size_t v_i_1037_, size_t v_stop_1038_, lean_object* v_b_1039_, lean_object* v___y_1040_, lean_object* v___y_1041_){
_start:
{
lean_object* v___x_1043_; 
v___x_1043_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2_spec__3_spec__4_spec__7___redArg(v_f_1035_, v_as_1036_, v_i_1037_, v_stop_1038_, v_b_1039_, v___y_1040_, v___y_1041_);
return v___x_1043_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2_spec__3_spec__4_spec__7___boxed(lean_object* v_00_u03b1_1044_, lean_object* v_00_u03b2_1045_, lean_object* v_00_u03c3_1046_, lean_object* v_00_u03c3_1047_, lean_object* v_f_1048_, lean_object* v_as_1049_, lean_object* v_i_1050_, lean_object* v_stop_1051_, lean_object* v_b_1052_, lean_object* v___y_1053_, lean_object* v___y_1054_, lean_object* v___y_1055_){
_start:
{
size_t v_i_boxed_1056_; size_t v_stop_boxed_1057_; lean_object* v_res_1058_; 
v_i_boxed_1056_ = lean_unbox_usize(v_i_1050_);
lean_dec(v_i_1050_);
v_stop_boxed_1057_ = lean_unbox_usize(v_stop_1051_);
lean_dec(v_stop_1051_);
v_res_1058_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2_spec__3_spec__4_spec__7(v_00_u03b1_1044_, v_00_u03b2_1045_, v_00_u03c3_1046_, v_00_u03c3_1047_, v_f_1048_, v_as_1049_, v_i_boxed_1056_, v_stop_boxed_1057_, v_b_1052_, v___y_1053_, v___y_1054_);
lean_dec(v___y_1054_);
lean_dec_ref(v___y_1053_);
lean_dec_ref(v_as_1049_);
return v_res_1058_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Lean_Data_PersistentHashMap_0__Lean_PersistentHashMap_foldlMAux_traverse___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2_spec__3_spec__4_spec__8(lean_object* v_00_u03c3_1059_, lean_object* v_00_u03c3_1060_, lean_object* v_00_u03b1_1061_, lean_object* v_00_u03b2_1062_, lean_object* v_f_1063_, lean_object* v_keys_1064_, lean_object* v_vals_1065_, lean_object* v_heq_1066_, lean_object* v_i_1067_, lean_object* v_acc_1068_, lean_object* v___y_1069_, lean_object* v___y_1070_){
_start:
{
lean_object* v___x_1072_; 
v___x_1072_ = lp_JunkValues___private_Lean_Data_PersistentHashMap_0__Lean_PersistentHashMap_foldlMAux_traverse___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2_spec__3_spec__4_spec__8___redArg(v_f_1063_, v_keys_1064_, v_vals_1065_, v_i_1067_, v_acc_1068_, v___y_1069_, v___y_1070_);
return v___x_1072_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Lean_Data_PersistentHashMap_0__Lean_PersistentHashMap_foldlMAux_traverse___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2_spec__3_spec__4_spec__8___boxed(lean_object* v_00_u03c3_1073_, lean_object* v_00_u03c3_1074_, lean_object* v_00_u03b1_1075_, lean_object* v_00_u03b2_1076_, lean_object* v_f_1077_, lean_object* v_keys_1078_, lean_object* v_vals_1079_, lean_object* v_heq_1080_, lean_object* v_i_1081_, lean_object* v_acc_1082_, lean_object* v___y_1083_, lean_object* v___y_1084_, lean_object* v___y_1085_){
_start:
{
lean_object* v_res_1086_; 
v_res_1086_ = lp_JunkValues___private_Lean_Data_PersistentHashMap_0__Lean_PersistentHashMap_foldlMAux_traverse___at___00Lean_PersistentHashMap_foldlMAux___at___00Lean_PersistentHashMap_foldlM___at___00Lean_PersistentHashMap_forIn___at___00JunkValues_declIdsOf_spec__2_spec__3_spec__4_spec__8(v_00_u03c3_1073_, v_00_u03c3_1074_, v_00_u03b1_1075_, v_00_u03b2_1076_, v_f_1077_, v_keys_1078_, v_vals_1079_, v_heq_1080_, v_i_1081_, v_acc_1082_, v___y_1083_, v___y_1084_);
lean_dec(v___y_1084_);
lean_dec_ref(v___y_1083_);
lean_dec_ref(v_vals_1079_);
lean_dec_ref(v_keys_1078_);
return v_res_1086_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_warningOf___closed__1(void){
_start:
{
lean_object* v___x_1088_; lean_object* v___x_1089_; 
v___x_1088_ = ((lean_object*)(lp_JunkValues_JunkValues_warningOf___closed__0));
v___x_1089_ = l_Lean_stringToMessageData(v___x_1088_);
return v___x_1089_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_warningOf___closed__3(void){
_start:
{
lean_object* v___x_1091_; lean_object* v___x_1092_; 
v___x_1091_ = ((lean_object*)(lp_JunkValues_JunkValues_warningOf___closed__2));
v___x_1092_ = l_Lean_stringToMessageData(v___x_1091_);
return v___x_1092_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_warningOf___closed__5(void){
_start:
{
lean_object* v___x_1094_; lean_object* v___x_1095_; 
v___x_1094_ = ((lean_object*)(lp_JunkValues_JunkValues_warningOf___closed__4));
v___x_1095_ = l_Lean_stringToMessageData(v___x_1094_);
return v___x_1095_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_warningOf(lean_object* v_f_1098_){
_start:
{
lean_object* v_decl_1099_; uint8_t v_site_1100_; lean_object* v___y_1102_; 
v_decl_1099_ = lean_ctor_get(v_f_1098_, 0);
v_site_1100_ = lean_ctor_get_uint8(v_f_1098_, sizeof(void*)*8);
if (v_site_1100_ == 0)
{
lean_object* v___x_1115_; 
v___x_1115_ = ((lean_object*)(lp_JunkValues_JunkValues_warningOf___closed__6));
v___y_1102_ = v___x_1115_;
goto v___jp_1101_;
}
else
{
lean_object* v___x_1116_; 
v___x_1116_ = ((lean_object*)(lp_JunkValues_JunkValues_warningOf___closed__7));
v___y_1102_ = v___x_1116_;
goto v___jp_1101_;
}
v___jp_1101_:
{
lean_object* v___x_1103_; lean_object* v___x_1104_; lean_object* v___x_1105_; lean_object* v___x_1106_; lean_object* v___x_1107_; lean_object* v___x_1108_; lean_object* v___x_1109_; lean_object* v___x_1110_; lean_object* v___x_1111_; lean_object* v___x_1112_; lean_object* v___x_1113_; lean_object* v___x_1114_; 
v___x_1103_ = lean_obj_once(&lp_JunkValues_JunkValues_warningOf___closed__1, &lp_JunkValues_JunkValues_warningOf___closed__1_once, _init_lp_JunkValues_JunkValues_warningOf___closed__1);
lean_inc_ref(v___y_1102_);
v___x_1104_ = l_Lean_stringToMessageData(v___y_1102_);
v___x_1105_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1105_, 0, v___x_1103_);
lean_ctor_set(v___x_1105_, 1, v___x_1104_);
v___x_1106_ = lean_obj_once(&lp_JunkValues_JunkValues_warningOf___closed__3, &lp_JunkValues_JunkValues_warningOf___closed__3_once, _init_lp_JunkValues_JunkValues_warningOf___closed__3);
v___x_1107_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1107_, 0, v___x_1105_);
lean_ctor_set(v___x_1107_, 1, v___x_1106_);
lean_inc(v_decl_1099_);
v___x_1108_ = l_Lean_MessageData_ofName(v_decl_1099_);
v___x_1109_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1109_, 0, v___x_1107_);
lean_ctor_set(v___x_1109_, 1, v___x_1108_);
v___x_1110_ = lean_obj_once(&lp_JunkValues_JunkValues_warningOf___closed__5, &lp_JunkValues_JunkValues_warningOf___closed__5_once, _init_lp_JunkValues_JunkValues_warningOf___closed__5);
v___x_1111_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1111_, 0, v___x_1109_);
lean_ctor_set(v___x_1111_, 1, v___x_1110_);
v___x_1112_ = lp_JunkValues_JunkValues_Finding_message(v_f_1098_);
v___x_1113_ = l_Lean_stringToMessageData(v___x_1112_);
v___x_1114_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1114_, 0, v___x_1111_);
lean_ctor_set(v___x_1114_, 1, v___x_1113_);
return v___x_1114_;
}
}
}
LEAN_EXPORT uint8_t lp_JunkValues_Lean_Option_get___at___00JunkValues_junkValuesLinter_spec__0(lean_object* v_opts_1117_, lean_object* v_opt_1118_){
_start:
{
lean_object* v_name_1119_; lean_object* v_defValue_1120_; lean_object* v_map_1121_; lean_object* v___x_1122_; 
v_name_1119_ = lean_ctor_get(v_opt_1118_, 0);
v_defValue_1120_ = lean_ctor_get(v_opt_1118_, 1);
v_map_1121_ = lean_ctor_get(v_opts_1117_, 0);
v___x_1122_ = l_Std_DTreeMap_Internal_Impl_Const_get_x3f___at___00Lean_NameMap_find_x3f_spec__0___redArg(v_map_1121_, v_name_1119_);
if (lean_obj_tag(v___x_1122_) == 0)
{
uint8_t v___x_1123_; 
v___x_1123_ = lean_unbox(v_defValue_1120_);
return v___x_1123_;
}
else
{
lean_object* v_val_1124_; 
v_val_1124_ = lean_ctor_get(v___x_1122_, 0);
lean_inc(v_val_1124_);
lean_dec_ref_known(v___x_1122_, 1);
if (lean_obj_tag(v_val_1124_) == 1)
{
uint8_t v_v_1125_; 
v_v_1125_ = lean_ctor_get_uint8(v_val_1124_, 0);
lean_dec_ref_known(v_val_1124_, 0);
return v_v_1125_;
}
else
{
uint8_t v___x_1126_; 
lean_dec(v_val_1124_);
v___x_1126_ = lean_unbox(v_defValue_1120_);
return v___x_1126_;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Option_get___at___00JunkValues_junkValuesLinter_spec__0___boxed(lean_object* v_opts_1127_, lean_object* v_opt_1128_){
_start:
{
uint8_t v_res_1129_; lean_object* v_r_1130_; 
v_res_1129_ = lp_JunkValues_Lean_Option_get___at___00JunkValues_junkValuesLinter_spec__0(v_opts_1127_, v_opt_1128_);
lean_dec_ref(v_opt_1128_);
lean_dec_ref(v_opts_1127_);
v_r_1130_ = lean_box(v_res_1129_);
return v_r_1130_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_addMessageContextFull___at___00Lean_logAt___at___00Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1_spec__2_spec__6(lean_object* v_msgData_1131_, lean_object* v___y_1132_, lean_object* v___y_1133_, lean_object* v___y_1134_, lean_object* v___y_1135_){
_start:
{
lean_object* v___x_1137_; lean_object* v_env_1138_; lean_object* v___x_1139_; lean_object* v_mctx_1140_; lean_object* v_lctx_1141_; lean_object* v_options_1142_; lean_object* v___x_1143_; lean_object* v___x_1144_; lean_object* v___x_1145_; 
v___x_1137_ = lean_st_ref_get(v___y_1135_);
v_env_1138_ = lean_ctor_get(v___x_1137_, 0);
lean_inc_ref(v_env_1138_);
lean_dec(v___x_1137_);
v___x_1139_ = lean_st_ref_get(v___y_1133_);
v_mctx_1140_ = lean_ctor_get(v___x_1139_, 0);
lean_inc_ref(v_mctx_1140_);
lean_dec(v___x_1139_);
v_lctx_1141_ = lean_ctor_get(v___y_1132_, 2);
v_options_1142_ = lean_ctor_get(v___y_1134_, 2);
lean_inc_ref(v_options_1142_);
lean_inc_ref(v_lctx_1141_);
v___x_1143_ = lean_alloc_ctor(0, 4, 0);
lean_ctor_set(v___x_1143_, 0, v_env_1138_);
lean_ctor_set(v___x_1143_, 1, v_mctx_1140_);
lean_ctor_set(v___x_1143_, 2, v_lctx_1141_);
lean_ctor_set(v___x_1143_, 3, v_options_1142_);
v___x_1144_ = lean_alloc_ctor(3, 2, 0);
lean_ctor_set(v___x_1144_, 0, v___x_1143_);
lean_ctor_set(v___x_1144_, 1, v_msgData_1131_);
v___x_1145_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1145_, 0, v___x_1144_);
return v___x_1145_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_addMessageContextFull___at___00Lean_logAt___at___00Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1_spec__2_spec__6___boxed(lean_object* v_msgData_1146_, lean_object* v___y_1147_, lean_object* v___y_1148_, lean_object* v___y_1149_, lean_object* v___y_1150_, lean_object* v___y_1151_){
_start:
{
lean_object* v_res_1152_; 
v_res_1152_ = lp_JunkValues_Lean_addMessageContextFull___at___00Lean_logAt___at___00Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1_spec__2_spec__6(v_msgData_1146_, v___y_1147_, v___y_1148_, v___y_1149_, v___y_1150_);
lean_dec(v___y_1150_);
lean_dec_ref(v___y_1149_);
lean_dec(v___y_1148_);
lean_dec_ref(v___y_1147_);
return v_res_1152_;
}
}
LEAN_EXPORT uint8_t lp_JunkValues_Lean_logAt___at___00Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1_spec__2___redArg___lam__0(uint8_t v___y_1161_, uint8_t v_suppressElabErrors_1162_, lean_object* v_x_1163_){
_start:
{
if (lean_obj_tag(v_x_1163_) == 1)
{
lean_object* v_pre_1164_; 
v_pre_1164_ = lean_ctor_get(v_x_1163_, 0);
switch(lean_obj_tag(v_pre_1164_))
{
case 1:
{
lean_object* v_pre_1165_; 
v_pre_1165_ = lean_ctor_get(v_pre_1164_, 0);
switch(lean_obj_tag(v_pre_1165_))
{
case 0:
{
lean_object* v_str_1166_; lean_object* v_str_1167_; lean_object* v___x_1168_; uint8_t v___x_1169_; 
v_str_1166_ = lean_ctor_get(v_x_1163_, 1);
v_str_1167_ = lean_ctor_get(v_pre_1164_, 1);
v___x_1168_ = ((lean_object*)(lp_JunkValues_Lean_logAt___at___00Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1_spec__2___redArg___lam__0___closed__0));
v___x_1169_ = lean_string_dec_eq(v_str_1167_, v___x_1168_);
if (v___x_1169_ == 0)
{
lean_object* v___x_1170_; uint8_t v___x_1171_; 
v___x_1170_ = ((lean_object*)(lp_JunkValues_Lean_logAt___at___00Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1_spec__2___redArg___lam__0___closed__1));
v___x_1171_ = lean_string_dec_eq(v_str_1167_, v___x_1170_);
if (v___x_1171_ == 0)
{
return v___y_1161_;
}
else
{
lean_object* v___x_1172_; uint8_t v___x_1173_; 
v___x_1172_ = ((lean_object*)(lp_JunkValues_Lean_logAt___at___00Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1_spec__2___redArg___lam__0___closed__2));
v___x_1173_ = lean_string_dec_eq(v_str_1166_, v___x_1172_);
if (v___x_1173_ == 0)
{
return v___y_1161_;
}
else
{
return v_suppressElabErrors_1162_;
}
}
}
else
{
lean_object* v___x_1174_; uint8_t v___x_1175_; 
v___x_1174_ = ((lean_object*)(lp_JunkValues_Lean_logAt___at___00Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1_spec__2___redArg___lam__0___closed__3));
v___x_1175_ = lean_string_dec_eq(v_str_1166_, v___x_1174_);
if (v___x_1175_ == 0)
{
return v___y_1161_;
}
else
{
return v_suppressElabErrors_1162_;
}
}
}
case 1:
{
lean_object* v_pre_1176_; 
v_pre_1176_ = lean_ctor_get(v_pre_1165_, 0);
if (lean_obj_tag(v_pre_1176_) == 0)
{
lean_object* v_str_1177_; lean_object* v_str_1178_; lean_object* v_str_1179_; lean_object* v___x_1180_; uint8_t v___x_1181_; 
v_str_1177_ = lean_ctor_get(v_x_1163_, 1);
v_str_1178_ = lean_ctor_get(v_pre_1164_, 1);
v_str_1179_ = lean_ctor_get(v_pre_1165_, 1);
v___x_1180_ = ((lean_object*)(lp_JunkValues_Lean_logAt___at___00Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1_spec__2___redArg___lam__0___closed__4));
v___x_1181_ = lean_string_dec_eq(v_str_1179_, v___x_1180_);
if (v___x_1181_ == 0)
{
return v___y_1161_;
}
else
{
lean_object* v___x_1182_; uint8_t v___x_1183_; 
v___x_1182_ = ((lean_object*)(lp_JunkValues_Lean_logAt___at___00Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1_spec__2___redArg___lam__0___closed__5));
v___x_1183_ = lean_string_dec_eq(v_str_1178_, v___x_1182_);
if (v___x_1183_ == 0)
{
return v___y_1161_;
}
else
{
lean_object* v___x_1184_; uint8_t v___x_1185_; 
v___x_1184_ = ((lean_object*)(lp_JunkValues_Lean_logAt___at___00Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1_spec__2___redArg___lam__0___closed__6));
v___x_1185_ = lean_string_dec_eq(v_str_1177_, v___x_1184_);
if (v___x_1185_ == 0)
{
return v___y_1161_;
}
else
{
return v_suppressElabErrors_1162_;
}
}
}
}
else
{
return v___y_1161_;
}
}
default: 
{
return v___y_1161_;
}
}
}
case 0:
{
lean_object* v_str_1186_; lean_object* v___x_1187_; uint8_t v___x_1188_; 
v_str_1186_ = lean_ctor_get(v_x_1163_, 1);
v___x_1187_ = ((lean_object*)(lp_JunkValues_Lean_logAt___at___00Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1_spec__2___redArg___lam__0___closed__7));
v___x_1188_ = lean_string_dec_eq(v_str_1186_, v___x_1187_);
if (v___x_1188_ == 0)
{
return v___y_1161_;
}
else
{
return v_suppressElabErrors_1162_;
}
}
default: 
{
return v___y_1161_;
}
}
}
else
{
return v___y_1161_;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_logAt___at___00Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1_spec__2___redArg___lam__0___boxed(lean_object* v___y_1189_, lean_object* v_suppressElabErrors_1190_, lean_object* v_x_1191_){
_start:
{
uint8_t v___y_9959__boxed_1192_; uint8_t v_suppressElabErrors_boxed_1193_; uint8_t v_res_1194_; lean_object* v_r_1195_; 
v___y_9959__boxed_1192_ = lean_unbox(v___y_1189_);
v_suppressElabErrors_boxed_1193_ = lean_unbox(v_suppressElabErrors_1190_);
v_res_1194_ = lp_JunkValues_Lean_logAt___at___00Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1_spec__2___redArg___lam__0(v___y_9959__boxed_1192_, v_suppressElabErrors_boxed_1193_, v_x_1191_);
lean_dec(v_x_1191_);
v_r_1195_ = lean_box(v_res_1194_);
return v_r_1195_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_logAt___at___00Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1_spec__2___redArg(lean_object* v_ref_1196_, lean_object* v_msgData_1197_, uint8_t v_severity_1198_, uint8_t v_isSilent_1199_, lean_object* v___y_1200_, lean_object* v___y_1201_, lean_object* v___y_1202_, lean_object* v___y_1203_){
_start:
{
lean_object* v___y_1206_; lean_object* v___y_1207_; lean_object* v___y_1208_; lean_object* v___y_1209_; uint8_t v___y_1210_; uint8_t v___y_1211_; lean_object* v___y_1212_; lean_object* v___y_1213_; lean_object* v___y_1214_; lean_object* v___y_1242_; lean_object* v___y_1243_; lean_object* v___y_1244_; uint8_t v___y_1245_; lean_object* v___y_1246_; uint8_t v___y_1247_; uint8_t v___y_1248_; lean_object* v___y_1249_; lean_object* v___y_1267_; lean_object* v___y_1268_; lean_object* v___y_1269_; uint8_t v___y_1270_; uint8_t v___y_1271_; uint8_t v___y_1272_; lean_object* v___y_1273_; lean_object* v___y_1274_; lean_object* v___y_1278_; lean_object* v___y_1279_; lean_object* v___y_1280_; uint8_t v___y_1281_; lean_object* v___y_1282_; uint8_t v___y_1283_; uint8_t v___y_1284_; uint8_t v___x_1289_; lean_object* v___y_1291_; lean_object* v___y_1292_; lean_object* v___y_1293_; uint8_t v___y_1294_; lean_object* v___y_1295_; uint8_t v___y_1296_; uint8_t v___y_1297_; uint8_t v___y_1299_; uint8_t v___x_1314_; 
v___x_1289_ = 2;
v___x_1314_ = l_Lean_instBEqMessageSeverity_beq(v_severity_1198_, v___x_1289_);
if (v___x_1314_ == 0)
{
v___y_1299_ = v___x_1314_;
goto v___jp_1298_;
}
else
{
uint8_t v___x_1315_; 
lean_inc_ref(v_msgData_1197_);
v___x_1315_ = l_Lean_MessageData_hasSyntheticSorry(v_msgData_1197_);
v___y_1299_ = v___x_1315_;
goto v___jp_1298_;
}
v___jp_1205_:
{
lean_object* v___x_1215_; lean_object* v_currNamespace_1216_; lean_object* v_openDecls_1217_; lean_object* v_env_1218_; lean_object* v_nextMacroScope_1219_; lean_object* v_ngen_1220_; lean_object* v_auxDeclNGen_1221_; lean_object* v_traceState_1222_; lean_object* v_cache_1223_; lean_object* v_messages_1224_; lean_object* v_infoState_1225_; lean_object* v_snapshotTasks_1226_; lean_object* v___x_1228_; uint8_t v_isShared_1229_; uint8_t v_isSharedCheck_1240_; 
v___x_1215_ = lean_st_ref_take(v___y_1214_);
v_currNamespace_1216_ = lean_ctor_get(v___y_1213_, 6);
v_openDecls_1217_ = lean_ctor_get(v___y_1213_, 7);
v_env_1218_ = lean_ctor_get(v___x_1215_, 0);
v_nextMacroScope_1219_ = lean_ctor_get(v___x_1215_, 1);
v_ngen_1220_ = lean_ctor_get(v___x_1215_, 2);
v_auxDeclNGen_1221_ = lean_ctor_get(v___x_1215_, 3);
v_traceState_1222_ = lean_ctor_get(v___x_1215_, 4);
v_cache_1223_ = lean_ctor_get(v___x_1215_, 5);
v_messages_1224_ = lean_ctor_get(v___x_1215_, 6);
v_infoState_1225_ = lean_ctor_get(v___x_1215_, 7);
v_snapshotTasks_1226_ = lean_ctor_get(v___x_1215_, 8);
v_isSharedCheck_1240_ = !lean_is_exclusive(v___x_1215_);
if (v_isSharedCheck_1240_ == 0)
{
v___x_1228_ = v___x_1215_;
v_isShared_1229_ = v_isSharedCheck_1240_;
goto v_resetjp_1227_;
}
else
{
lean_inc(v_snapshotTasks_1226_);
lean_inc(v_infoState_1225_);
lean_inc(v_messages_1224_);
lean_inc(v_cache_1223_);
lean_inc(v_traceState_1222_);
lean_inc(v_auxDeclNGen_1221_);
lean_inc(v_ngen_1220_);
lean_inc(v_nextMacroScope_1219_);
lean_inc(v_env_1218_);
lean_dec(v___x_1215_);
v___x_1228_ = lean_box(0);
v_isShared_1229_ = v_isSharedCheck_1240_;
goto v_resetjp_1227_;
}
v_resetjp_1227_:
{
lean_object* v___x_1230_; lean_object* v___x_1231_; lean_object* v___x_1232_; lean_object* v___x_1233_; lean_object* v___x_1235_; 
lean_inc(v_openDecls_1217_);
lean_inc(v_currNamespace_1216_);
v___x_1230_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1230_, 0, v_currNamespace_1216_);
lean_ctor_set(v___x_1230_, 1, v_openDecls_1217_);
v___x_1231_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_1231_, 0, v___x_1230_);
lean_ctor_set(v___x_1231_, 1, v___y_1207_);
lean_inc_ref(v___y_1209_);
lean_inc_ref(v___y_1208_);
v___x_1232_ = lean_alloc_ctor(0, 5, 3);
lean_ctor_set(v___x_1232_, 0, v___y_1208_);
lean_ctor_set(v___x_1232_, 1, v___y_1212_);
lean_ctor_set(v___x_1232_, 2, v___y_1206_);
lean_ctor_set(v___x_1232_, 3, v___y_1209_);
lean_ctor_set(v___x_1232_, 4, v___x_1231_);
lean_ctor_set_uint8(v___x_1232_, sizeof(void*)*5, v___y_1210_);
lean_ctor_set_uint8(v___x_1232_, sizeof(void*)*5 + 1, v___y_1211_);
lean_ctor_set_uint8(v___x_1232_, sizeof(void*)*5 + 2, v_isSilent_1199_);
v___x_1233_ = l_Lean_MessageLog_add(v___x_1232_, v_messages_1224_);
if (v_isShared_1229_ == 0)
{
lean_ctor_set(v___x_1228_, 6, v___x_1233_);
v___x_1235_ = v___x_1228_;
goto v_reusejp_1234_;
}
else
{
lean_object* v_reuseFailAlloc_1239_; 
v_reuseFailAlloc_1239_ = lean_alloc_ctor(0, 9, 0);
lean_ctor_set(v_reuseFailAlloc_1239_, 0, v_env_1218_);
lean_ctor_set(v_reuseFailAlloc_1239_, 1, v_nextMacroScope_1219_);
lean_ctor_set(v_reuseFailAlloc_1239_, 2, v_ngen_1220_);
lean_ctor_set(v_reuseFailAlloc_1239_, 3, v_auxDeclNGen_1221_);
lean_ctor_set(v_reuseFailAlloc_1239_, 4, v_traceState_1222_);
lean_ctor_set(v_reuseFailAlloc_1239_, 5, v_cache_1223_);
lean_ctor_set(v_reuseFailAlloc_1239_, 6, v___x_1233_);
lean_ctor_set(v_reuseFailAlloc_1239_, 7, v_infoState_1225_);
lean_ctor_set(v_reuseFailAlloc_1239_, 8, v_snapshotTasks_1226_);
v___x_1235_ = v_reuseFailAlloc_1239_;
goto v_reusejp_1234_;
}
v_reusejp_1234_:
{
lean_object* v___x_1236_; lean_object* v___x_1237_; lean_object* v___x_1238_; 
v___x_1236_ = lean_st_ref_set(v___y_1214_, v___x_1235_);
v___x_1237_ = lean_box(0);
v___x_1238_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1238_, 0, v___x_1237_);
return v___x_1238_;
}
}
}
v___jp_1241_:
{
lean_object* v___x_1250_; lean_object* v___x_1251_; lean_object* v_a_1252_; lean_object* v___x_1254_; uint8_t v_isShared_1255_; uint8_t v_isSharedCheck_1265_; 
v___x_1250_ = l___private_Lean_Log_0__Lean_MessageData_appendDescriptionWidgetIfNamed(v_msgData_1197_);
v___x_1251_ = lp_JunkValues_Lean_addMessageContextFull___at___00Lean_logAt___at___00Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1_spec__2_spec__6(v___x_1250_, v___y_1200_, v___y_1201_, v___y_1202_, v___y_1203_);
v_a_1252_ = lean_ctor_get(v___x_1251_, 0);
v_isSharedCheck_1265_ = !lean_is_exclusive(v___x_1251_);
if (v_isSharedCheck_1265_ == 0)
{
v___x_1254_ = v___x_1251_;
v_isShared_1255_ = v_isSharedCheck_1265_;
goto v_resetjp_1253_;
}
else
{
lean_inc(v_a_1252_);
lean_dec(v___x_1251_);
v___x_1254_ = lean_box(0);
v_isShared_1255_ = v_isSharedCheck_1265_;
goto v_resetjp_1253_;
}
v_resetjp_1253_:
{
lean_object* v___x_1256_; lean_object* v___x_1257_; lean_object* v___x_1258_; lean_object* v___x_1259_; 
lean_inc_ref_n(v___y_1246_, 2);
v___x_1256_ = l_Lean_FileMap_toPosition(v___y_1246_, v___y_1243_);
lean_dec(v___y_1243_);
v___x_1257_ = l_Lean_FileMap_toPosition(v___y_1246_, v___y_1249_);
lean_dec(v___y_1249_);
v___x_1258_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_1258_, 0, v___x_1257_);
v___x_1259_ = ((lean_object*)(lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn___closed__2_00___x40_JunkValues_Frontend_1659515862____hygCtx___hyg_4_));
if (v___y_1248_ == 0)
{
lean_del_object(v___x_1254_);
lean_dec_ref(v___y_1242_);
v___y_1206_ = v___x_1258_;
v___y_1207_ = v_a_1252_;
v___y_1208_ = v___y_1244_;
v___y_1209_ = v___x_1259_;
v___y_1210_ = v___y_1245_;
v___y_1211_ = v___y_1247_;
v___y_1212_ = v___x_1256_;
v___y_1213_ = v___y_1202_;
v___y_1214_ = v___y_1203_;
goto v___jp_1205_;
}
else
{
uint8_t v___x_1260_; 
lean_inc(v_a_1252_);
v___x_1260_ = l_Lean_MessageData_hasTag(v___y_1242_, v_a_1252_);
if (v___x_1260_ == 0)
{
lean_object* v___x_1261_; lean_object* v___x_1263_; 
lean_dec_ref_known(v___x_1258_, 1);
lean_dec_ref(v___x_1256_);
lean_dec(v_a_1252_);
v___x_1261_ = lean_box(0);
if (v_isShared_1255_ == 0)
{
lean_ctor_set(v___x_1254_, 0, v___x_1261_);
v___x_1263_ = v___x_1254_;
goto v_reusejp_1262_;
}
else
{
lean_object* v_reuseFailAlloc_1264_; 
v_reuseFailAlloc_1264_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1264_, 0, v___x_1261_);
v___x_1263_ = v_reuseFailAlloc_1264_;
goto v_reusejp_1262_;
}
v_reusejp_1262_:
{
return v___x_1263_;
}
}
else
{
lean_del_object(v___x_1254_);
v___y_1206_ = v___x_1258_;
v___y_1207_ = v_a_1252_;
v___y_1208_ = v___y_1244_;
v___y_1209_ = v___x_1259_;
v___y_1210_ = v___y_1245_;
v___y_1211_ = v___y_1247_;
v___y_1212_ = v___x_1256_;
v___y_1213_ = v___y_1202_;
v___y_1214_ = v___y_1203_;
goto v___jp_1205_;
}
}
}
}
v___jp_1266_:
{
lean_object* v___x_1275_; 
v___x_1275_ = l_Lean_Syntax_getTailPos_x3f(v___y_1273_, v___y_1270_);
lean_dec(v___y_1273_);
if (lean_obj_tag(v___x_1275_) == 0)
{
lean_inc(v___y_1274_);
v___y_1242_ = v___y_1267_;
v___y_1243_ = v___y_1274_;
v___y_1244_ = v___y_1268_;
v___y_1245_ = v___y_1270_;
v___y_1246_ = v___y_1269_;
v___y_1247_ = v___y_1271_;
v___y_1248_ = v___y_1272_;
v___y_1249_ = v___y_1274_;
goto v___jp_1241_;
}
else
{
lean_object* v_val_1276_; 
v_val_1276_ = lean_ctor_get(v___x_1275_, 0);
lean_inc(v_val_1276_);
lean_dec_ref_known(v___x_1275_, 1);
v___y_1242_ = v___y_1267_;
v___y_1243_ = v___y_1274_;
v___y_1244_ = v___y_1268_;
v___y_1245_ = v___y_1270_;
v___y_1246_ = v___y_1269_;
v___y_1247_ = v___y_1271_;
v___y_1248_ = v___y_1272_;
v___y_1249_ = v_val_1276_;
goto v___jp_1241_;
}
}
v___jp_1277_:
{
lean_object* v_ref_1285_; lean_object* v___x_1286_; 
v_ref_1285_ = l_Lean_replaceRef(v_ref_1196_, v___y_1279_);
v___x_1286_ = l_Lean_Syntax_getPos_x3f(v_ref_1285_, v___y_1281_);
if (lean_obj_tag(v___x_1286_) == 0)
{
lean_object* v___x_1287_; 
v___x_1287_ = lean_unsigned_to_nat(0u);
v___y_1267_ = v___y_1278_;
v___y_1268_ = v___y_1280_;
v___y_1269_ = v___y_1282_;
v___y_1270_ = v___y_1281_;
v___y_1271_ = v___y_1284_;
v___y_1272_ = v___y_1283_;
v___y_1273_ = v_ref_1285_;
v___y_1274_ = v___x_1287_;
goto v___jp_1266_;
}
else
{
lean_object* v_val_1288_; 
v_val_1288_ = lean_ctor_get(v___x_1286_, 0);
lean_inc(v_val_1288_);
lean_dec_ref_known(v___x_1286_, 1);
v___y_1267_ = v___y_1278_;
v___y_1268_ = v___y_1280_;
v___y_1269_ = v___y_1282_;
v___y_1270_ = v___y_1281_;
v___y_1271_ = v___y_1284_;
v___y_1272_ = v___y_1283_;
v___y_1273_ = v_ref_1285_;
v___y_1274_ = v_val_1288_;
goto v___jp_1266_;
}
}
v___jp_1290_:
{
if (v___y_1297_ == 0)
{
v___y_1278_ = v___y_1295_;
v___y_1279_ = v___y_1291_;
v___y_1280_ = v___y_1292_;
v___y_1281_ = v___y_1296_;
v___y_1282_ = v___y_1293_;
v___y_1283_ = v___y_1294_;
v___y_1284_ = v_severity_1198_;
goto v___jp_1277_;
}
else
{
v___y_1278_ = v___y_1295_;
v___y_1279_ = v___y_1291_;
v___y_1280_ = v___y_1292_;
v___y_1281_ = v___y_1296_;
v___y_1282_ = v___y_1293_;
v___y_1283_ = v___y_1294_;
v___y_1284_ = v___x_1289_;
goto v___jp_1277_;
}
}
v___jp_1298_:
{
if (v___y_1299_ == 0)
{
lean_object* v_fileName_1300_; lean_object* v_fileMap_1301_; lean_object* v_options_1302_; lean_object* v_ref_1303_; uint8_t v_suppressElabErrors_1304_; lean_object* v___x_1305_; lean_object* v___x_1306_; lean_object* v___f_1307_; uint8_t v___x_1308_; uint8_t v___x_1309_; 
v_fileName_1300_ = lean_ctor_get(v___y_1202_, 0);
v_fileMap_1301_ = lean_ctor_get(v___y_1202_, 1);
v_options_1302_ = lean_ctor_get(v___y_1202_, 2);
v_ref_1303_ = lean_ctor_get(v___y_1202_, 5);
v_suppressElabErrors_1304_ = lean_ctor_get_uint8(v___y_1202_, sizeof(void*)*14 + 1);
v___x_1305_ = lean_box(v___y_1299_);
v___x_1306_ = lean_box(v_suppressElabErrors_1304_);
v___f_1307_ = lean_alloc_closure((void*)(lp_JunkValues_Lean_logAt___at___00Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1_spec__2___redArg___lam__0___boxed), 3, 2);
lean_closure_set(v___f_1307_, 0, v___x_1305_);
lean_closure_set(v___f_1307_, 1, v___x_1306_);
v___x_1308_ = 1;
v___x_1309_ = l_Lean_instBEqMessageSeverity_beq(v_severity_1198_, v___x_1308_);
if (v___x_1309_ == 0)
{
v___y_1291_ = v_ref_1303_;
v___y_1292_ = v_fileName_1300_;
v___y_1293_ = v_fileMap_1301_;
v___y_1294_ = v_suppressElabErrors_1304_;
v___y_1295_ = v___f_1307_;
v___y_1296_ = v___y_1299_;
v___y_1297_ = v___x_1309_;
goto v___jp_1290_;
}
else
{
lean_object* v___x_1310_; uint8_t v___x_1311_; 
v___x_1310_ = l_Lean_warningAsError;
v___x_1311_ = lp_JunkValues_Lean_Option_get___at___00JunkValues_junkValuesLinter_spec__0(v_options_1302_, v___x_1310_);
v___y_1291_ = v_ref_1303_;
v___y_1292_ = v_fileName_1300_;
v___y_1293_ = v_fileMap_1301_;
v___y_1294_ = v_suppressElabErrors_1304_;
v___y_1295_ = v___f_1307_;
v___y_1296_ = v___y_1299_;
v___y_1297_ = v___x_1311_;
goto v___jp_1290_;
}
}
else
{
lean_object* v___x_1312_; lean_object* v___x_1313_; 
lean_dec_ref(v_msgData_1197_);
v___x_1312_ = lean_box(0);
v___x_1313_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1313_, 0, v___x_1312_);
return v___x_1313_;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_logAt___at___00Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1_spec__2___redArg___boxed(lean_object* v_ref_1316_, lean_object* v_msgData_1317_, lean_object* v_severity_1318_, lean_object* v_isSilent_1319_, lean_object* v___y_1320_, lean_object* v___y_1321_, lean_object* v___y_1322_, lean_object* v___y_1323_, lean_object* v___y_1324_){
_start:
{
uint8_t v_severity_boxed_1325_; uint8_t v_isSilent_boxed_1326_; lean_object* v_res_1327_; 
v_severity_boxed_1325_ = lean_unbox(v_severity_1318_);
v_isSilent_boxed_1326_ = lean_unbox(v_isSilent_1319_);
v_res_1327_ = lp_JunkValues_Lean_logAt___at___00Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1_spec__2___redArg(v_ref_1316_, v_msgData_1317_, v_severity_boxed_1325_, v_isSilent_boxed_1326_, v___y_1320_, v___y_1321_, v___y_1322_, v___y_1323_);
lean_dec(v___y_1323_);
lean_dec_ref(v___y_1322_);
lean_dec(v___y_1321_);
lean_dec_ref(v___y_1320_);
lean_dec(v_ref_1316_);
return v_res_1327_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1(lean_object* v_ref_1328_, lean_object* v_msgData_1329_, lean_object* v___y_1330_, lean_object* v___y_1331_, lean_object* v___y_1332_, lean_object* v___y_1333_, lean_object* v___y_1334_, lean_object* v___y_1335_){
_start:
{
uint8_t v___x_1337_; uint8_t v___x_1338_; lean_object* v___x_1339_; 
v___x_1337_ = 1;
v___x_1338_ = 0;
v___x_1339_ = lp_JunkValues_Lean_logAt___at___00Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1_spec__2___redArg(v_ref_1328_, v_msgData_1329_, v___x_1337_, v___x_1338_, v___y_1332_, v___y_1333_, v___y_1334_, v___y_1335_);
return v___x_1339_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1___boxed(lean_object* v_ref_1340_, lean_object* v_msgData_1341_, lean_object* v___y_1342_, lean_object* v___y_1343_, lean_object* v___y_1344_, lean_object* v___y_1345_, lean_object* v___y_1346_, lean_object* v___y_1347_, lean_object* v___y_1348_){
_start:
{
lean_object* v_res_1349_; 
v_res_1349_ = lp_JunkValues_Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1(v_ref_1340_, v_msgData_1341_, v___y_1342_, v___y_1343_, v___y_1344_, v___y_1345_, v___y_1346_, v___y_1347_);
lean_dec(v___y_1347_);
lean_dec_ref(v___y_1346_);
lean_dec(v___y_1345_);
lean_dec_ref(v___y_1344_);
lean_dec(v___y_1343_);
lean_dec_ref(v___y_1342_);
lean_dec(v_ref_1340_);
return v_res_1349_;
}
}
static lean_object* _init_lp_JunkValues_Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1___closed__1(void){
_start:
{
lean_object* v___x_1351_; lean_object* v___x_1352_; 
v___x_1351_ = ((lean_object*)(lp_JunkValues_Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1___closed__0));
v___x_1352_ = l_Lean_stringToMessageData(v___x_1351_);
return v___x_1352_;
}
}
static lean_object* _init_lp_JunkValues_Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1___closed__3(void){
_start:
{
lean_object* v___x_1354_; lean_object* v___x_1355_; 
v___x_1354_ = ((lean_object*)(lp_JunkValues_Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1___closed__2));
v___x_1355_ = l_Lean_stringToMessageData(v___x_1354_);
return v___x_1355_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1(lean_object* v_linterOption_1356_, lean_object* v_stx_1357_, lean_object* v_msg_1358_, lean_object* v___y_1359_, lean_object* v___y_1360_, lean_object* v___y_1361_, lean_object* v___y_1362_, lean_object* v___y_1363_, lean_object* v___y_1364_){
_start:
{
lean_object* v_name_1366_; lean_object* v___x_1368_; uint8_t v_isShared_1369_; uint8_t v_isSharedCheck_1384_; 
v_name_1366_ = lean_ctor_get(v_linterOption_1356_, 0);
v_isSharedCheck_1384_ = !lean_is_exclusive(v_linterOption_1356_);
if (v_isSharedCheck_1384_ == 0)
{
lean_object* v_unused_1385_; 
v_unused_1385_ = lean_ctor_get(v_linterOption_1356_, 1);
lean_dec(v_unused_1385_);
v___x_1368_ = v_linterOption_1356_;
v_isShared_1369_ = v_isSharedCheck_1384_;
goto v_resetjp_1367_;
}
else
{
lean_inc(v_name_1366_);
lean_dec(v_linterOption_1356_);
v___x_1368_ = lean_box(0);
v_isShared_1369_ = v_isSharedCheck_1384_;
goto v_resetjp_1367_;
}
v_resetjp_1367_:
{
lean_object* v___x_1370_; lean_object* v___x_1371_; lean_object* v___x_1373_; 
v___x_1370_ = lean_obj_once(&lp_JunkValues_Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1___closed__1, &lp_JunkValues_Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1___closed__1_once, _init_lp_JunkValues_Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1___closed__1);
lean_inc(v_name_1366_);
v___x_1371_ = l_Lean_MessageData_ofName(v_name_1366_);
if (v_isShared_1369_ == 0)
{
lean_ctor_set_tag(v___x_1368_, 7);
lean_ctor_set(v___x_1368_, 1, v___x_1371_);
lean_ctor_set(v___x_1368_, 0, v___x_1370_);
v___x_1373_ = v___x_1368_;
goto v_reusejp_1372_;
}
else
{
lean_object* v_reuseFailAlloc_1383_; 
v_reuseFailAlloc_1383_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1383_, 0, v___x_1370_);
lean_ctor_set(v_reuseFailAlloc_1383_, 1, v___x_1371_);
v___x_1373_ = v_reuseFailAlloc_1383_;
goto v_reusejp_1372_;
}
v_reusejp_1372_:
{
lean_object* v___x_1374_; lean_object* v___x_1375_; lean_object* v_disable_1376_; lean_object* v___x_1377_; lean_object* v___x_1378_; lean_object* v___x_1379_; lean_object* v___x_1380_; lean_object* v___x_1381_; lean_object* v___x_1382_; 
v___x_1374_ = lean_obj_once(&lp_JunkValues_Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1___closed__3, &lp_JunkValues_Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1___closed__3_once, _init_lp_JunkValues_Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1___closed__3);
v___x_1375_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1375_, 0, v___x_1373_);
lean_ctor_set(v___x_1375_, 1, v___x_1374_);
v_disable_1376_ = l_Lean_MessageData_note(v___x_1375_);
v___x_1377_ = l_Lean_Linter_linterMessageTag;
v___x_1378_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1378_, 0, v_msg_1358_);
lean_ctor_set(v___x_1378_, 1, v_disable_1376_);
v___x_1379_ = lean_alloc_ctor(8, 2, 0);
lean_ctor_set(v___x_1379_, 0, v___x_1377_);
lean_ctor_set(v___x_1379_, 1, v___x_1378_);
v___x_1380_ = lean_alloc_ctor(8, 2, 0);
lean_ctor_set(v___x_1380_, 0, v_name_1366_);
lean_ctor_set(v___x_1380_, 1, v___x_1379_);
lean_inc(v_stx_1357_);
v___x_1381_ = lean_alloc_ctor(11, 2, 0);
lean_ctor_set(v___x_1381_, 0, v_stx_1357_);
lean_ctor_set(v___x_1381_, 1, v___x_1380_);
v___x_1382_ = lp_JunkValues_Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1(v_stx_1357_, v___x_1381_, v___y_1359_, v___y_1360_, v___y_1361_, v___y_1362_, v___y_1363_, v___y_1364_);
lean_dec(v_stx_1357_);
return v___x_1382_;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1___boxed(lean_object* v_linterOption_1386_, lean_object* v_stx_1387_, lean_object* v_msg_1388_, lean_object* v___y_1389_, lean_object* v___y_1390_, lean_object* v___y_1391_, lean_object* v___y_1392_, lean_object* v___y_1393_, lean_object* v___y_1394_, lean_object* v___y_1395_){
_start:
{
lean_object* v_res_1396_; 
v_res_1396_ = lp_JunkValues_Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1(v_linterOption_1386_, v_stx_1387_, v_msg_1388_, v___y_1389_, v___y_1390_, v___y_1391_, v___y_1392_, v___y_1393_, v___y_1394_);
lean_dec(v___y_1394_);
lean_dec_ref(v___y_1393_);
lean_dec(v___y_1392_);
lean_dec_ref(v___y_1391_);
lean_dec(v___y_1390_);
lean_dec_ref(v___y_1389_);
return v_res_1396_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_junkValuesLinter_spec__3(lean_object* v_stx_1397_, lean_object* v_as_1398_, size_t v_sz_1399_, size_t v_i_1400_, lean_object* v_b_1401_, lean_object* v___y_1402_, lean_object* v___y_1403_, lean_object* v___y_1404_, lean_object* v___y_1405_, lean_object* v___y_1406_, lean_object* v___y_1407_){
_start:
{
uint8_t v___x_1409_; 
v___x_1409_ = lean_usize_dec_lt(v_i_1400_, v_sz_1399_);
if (v___x_1409_ == 0)
{
lean_object* v___x_1410_; 
lean_dec(v_stx_1397_);
v___x_1410_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1410_, 0, v_b_1401_);
return v___x_1410_;
}
else
{
lean_object* v___x_1411_; lean_object* v_a_1412_; lean_object* v___x_1413_; lean_object* v___x_1414_; 
v___x_1411_ = lp_JunkValues_JunkValues_linter_junkValues;
v_a_1412_ = lean_array_uget_borrowed(v_as_1398_, v_i_1400_);
lean_inc(v_a_1412_);
v___x_1413_ = l_Lean_stringToMessageData(v_a_1412_);
lean_inc(v_stx_1397_);
v___x_1414_ = lp_JunkValues_Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1(v___x_1411_, v_stx_1397_, v___x_1413_, v___y_1402_, v___y_1403_, v___y_1404_, v___y_1405_, v___y_1406_, v___y_1407_);
if (lean_obj_tag(v___x_1414_) == 0)
{
lean_object* v___x_1415_; size_t v___x_1416_; size_t v___x_1417_; 
lean_dec_ref_known(v___x_1414_, 1);
v___x_1415_ = lean_box(0);
v___x_1416_ = ((size_t)1ULL);
v___x_1417_ = lean_usize_add(v_i_1400_, v___x_1416_);
v_i_1400_ = v___x_1417_;
v_b_1401_ = v___x_1415_;
goto _start;
}
else
{
lean_dec(v_stx_1397_);
return v___x_1414_;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_junkValuesLinter_spec__3___boxed(lean_object* v_stx_1419_, lean_object* v_as_1420_, lean_object* v_sz_1421_, lean_object* v_i_1422_, lean_object* v_b_1423_, lean_object* v___y_1424_, lean_object* v___y_1425_, lean_object* v___y_1426_, lean_object* v___y_1427_, lean_object* v___y_1428_, lean_object* v___y_1429_, lean_object* v___y_1430_){
_start:
{
size_t v_sz_boxed_1431_; size_t v_i_boxed_1432_; lean_object* v_res_1433_; 
v_sz_boxed_1431_ = lean_unbox_usize(v_sz_1421_);
lean_dec(v_sz_1421_);
v_i_boxed_1432_ = lean_unbox_usize(v_i_1422_);
lean_dec(v_i_1422_);
v_res_1433_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_junkValuesLinter_spec__3(v_stx_1419_, v_as_1420_, v_sz_boxed_1431_, v_i_boxed_1432_, v_b_1423_, v___y_1424_, v___y_1425_, v___y_1426_, v___y_1427_, v___y_1428_, v___y_1429_);
lean_dec(v___y_1429_);
lean_dec_ref(v___y_1428_);
lean_dec(v___y_1427_);
lean_dec_ref(v___y_1426_);
lean_dec(v___y_1425_);
lean_dec_ref(v___y_1424_);
lean_dec_ref(v_as_1420_);
return v_res_1433_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_junkValuesLinter_spec__2(lean_object* v_stx_1434_, lean_object* v_as_1435_, size_t v_sz_1436_, size_t v_i_1437_, lean_object* v_b_1438_, lean_object* v___y_1439_, lean_object* v___y_1440_, lean_object* v___y_1441_, lean_object* v___y_1442_, lean_object* v___y_1443_, lean_object* v___y_1444_){
_start:
{
uint8_t v___x_1446_; 
v___x_1446_ = lean_usize_dec_lt(v_i_1437_, v_sz_1436_);
if (v___x_1446_ == 0)
{
lean_object* v___x_1447_; 
lean_dec(v_stx_1434_);
v___x_1447_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1447_, 0, v_b_1438_);
return v___x_1447_;
}
else
{
lean_object* v___x_1448_; lean_object* v_a_1449_; lean_object* v___x_1450_; lean_object* v___x_1451_; 
v___x_1448_ = lp_JunkValues_JunkValues_linter_junkValues;
v_a_1449_ = lean_array_uget_borrowed(v_as_1435_, v_i_1437_);
lean_inc(v_a_1449_);
v___x_1450_ = lp_JunkValues_JunkValues_warningOf(v_a_1449_);
lean_inc(v_stx_1434_);
v___x_1451_ = lp_JunkValues_Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1(v___x_1448_, v_stx_1434_, v___x_1450_, v___y_1439_, v___y_1440_, v___y_1441_, v___y_1442_, v___y_1443_, v___y_1444_);
if (lean_obj_tag(v___x_1451_) == 0)
{
lean_object* v___x_1452_; size_t v___x_1453_; size_t v___x_1454_; 
lean_dec_ref_known(v___x_1451_, 1);
v___x_1452_ = lean_box(0);
v___x_1453_ = ((size_t)1ULL);
v___x_1454_ = lean_usize_add(v_i_1437_, v___x_1453_);
v_i_1437_ = v___x_1454_;
v_b_1438_ = v___x_1452_;
goto _start;
}
else
{
lean_dec(v_stx_1434_);
return v___x_1451_;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_junkValuesLinter_spec__2___boxed(lean_object* v_stx_1456_, lean_object* v_as_1457_, lean_object* v_sz_1458_, lean_object* v_i_1459_, lean_object* v_b_1460_, lean_object* v___y_1461_, lean_object* v___y_1462_, lean_object* v___y_1463_, lean_object* v___y_1464_, lean_object* v___y_1465_, lean_object* v___y_1466_, lean_object* v___y_1467_){
_start:
{
size_t v_sz_boxed_1468_; size_t v_i_boxed_1469_; lean_object* v_res_1470_; 
v_sz_boxed_1468_ = lean_unbox_usize(v_sz_1458_);
lean_dec(v_sz_1458_);
v_i_boxed_1469_ = lean_unbox_usize(v_i_1459_);
lean_dec(v_i_1459_);
v_res_1470_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_junkValuesLinter_spec__2(v_stx_1456_, v_as_1457_, v_sz_boxed_1468_, v_i_boxed_1469_, v_b_1460_, v___y_1461_, v___y_1462_, v___y_1463_, v___y_1464_, v___y_1465_, v___y_1466_);
lean_dec(v___y_1466_);
lean_dec_ref(v___y_1465_);
lean_dec(v___y_1464_);
lean_dec_ref(v___y_1463_);
lean_dec(v___y_1462_);
lean_dec_ref(v___y_1461_);
lean_dec_ref(v_as_1457_);
return v_res_1470_;
}
}
static lean_object* _init_lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_junkValuesLinter_spec__4___closed__1(void){
_start:
{
lean_object* v___x_1472_; lean_object* v___x_1473_; 
v___x_1472_ = ((lean_object*)(lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_junkValuesLinter_spec__4___closed__0));
v___x_1473_ = l_Lean_stringToMessageData(v___x_1472_);
return v___x_1473_;
}
}
static lean_object* _init_lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_junkValuesLinter_spec__4___closed__3(void){
_start:
{
lean_object* v___x_1475_; lean_object* v___x_1476_; 
v___x_1475_ = ((lean_object*)(lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_junkValuesLinter_spec__4___closed__2));
v___x_1476_ = l_Lean_stringToMessageData(v___x_1475_);
return v___x_1476_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_junkValuesLinter_spec__4(lean_object* v_fst_1477_, lean_object* v_fst_1478_, lean_object* v_stx_1479_, lean_object* v_as_1480_, size_t v_sz_1481_, size_t v_i_1482_, lean_object* v_b_1483_, lean_object* v___y_1484_, lean_object* v___y_1485_, lean_object* v___y_1486_, lean_object* v___y_1487_, lean_object* v___y_1488_, lean_object* v___y_1489_){
_start:
{
lean_object* v_a_1492_; uint8_t v___x_1496_; 
v___x_1496_ = lean_usize_dec_lt(v_i_1482_, v_sz_1481_);
if (v___x_1496_ == 0)
{
lean_object* v___x_1497_; 
lean_dec(v_stx_1479_);
lean_dec_ref(v_fst_1478_);
lean_dec_ref(v_fst_1477_);
v___x_1497_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1497_, 0, v_b_1483_);
return v___x_1497_;
}
else
{
lean_object* v_ruleSet_1498_; lean_object* v_a_1499_; lean_object* v___x_1500_; 
v_ruleSet_1498_ = lean_ctor_get(v_fst_1477_, 0);
v_a_1499_ = lean_array_uget_borrowed(v_as_1480_, v_i_1482_);
lean_inc(v_a_1499_);
lean_inc_ref(v_fst_1478_);
lean_inc_ref(v_ruleSet_1498_);
v___x_1500_ = lp_JunkValues_JunkValues_scanDecl(v_ruleSet_1498_, v_fst_1478_, v_a_1499_, v___y_1486_, v___y_1487_, v___y_1488_, v___y_1489_);
if (lean_obj_tag(v___x_1500_) == 0)
{
lean_object* v_a_1501_; lean_object* v_findings_1502_; uint8_t v_truncated_1503_; lean_object* v___x_1504_; size_t v_sz_1505_; size_t v___x_1506_; lean_object* v___x_1507_; 
v_a_1501_ = lean_ctor_get(v___x_1500_, 0);
lean_inc(v_a_1501_);
lean_dec_ref_known(v___x_1500_, 1);
v_findings_1502_ = lean_ctor_get(v_a_1501_, 1);
lean_inc_ref(v_findings_1502_);
v_truncated_1503_ = lean_ctor_get_uint8(v_a_1501_, sizeof(void*)*2);
lean_dec(v_a_1501_);
v___x_1504_ = lean_box(0);
v_sz_1505_ = lean_array_size(v_findings_1502_);
v___x_1506_ = ((size_t)0ULL);
lean_inc(v_stx_1479_);
v___x_1507_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_junkValuesLinter_spec__2(v_stx_1479_, v_findings_1502_, v_sz_1505_, v___x_1506_, v___x_1504_, v___y_1484_, v___y_1485_, v___y_1486_, v___y_1487_, v___y_1488_, v___y_1489_);
lean_dec_ref(v_findings_1502_);
if (lean_obj_tag(v___x_1507_) == 0)
{
lean_dec_ref_known(v___x_1507_, 1);
if (v_truncated_1503_ == 0)
{
v_a_1492_ = v___x_1504_;
goto v___jp_1491_;
}
else
{
lean_object* v___x_1508_; lean_object* v___x_1509_; lean_object* v___x_1510_; lean_object* v___x_1511_; lean_object* v___x_1512_; lean_object* v___x_1513_; lean_object* v___x_1514_; 
v___x_1508_ = lp_JunkValues_JunkValues_linter_junkValues;
v___x_1509_ = lean_obj_once(&lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_junkValuesLinter_spec__4___closed__1, &lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_junkValuesLinter_spec__4___closed__1_once, _init_lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_junkValuesLinter_spec__4___closed__1);
lean_inc(v_a_1499_);
v___x_1510_ = l_Lean_MessageData_ofName(v_a_1499_);
v___x_1511_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1511_, 0, v___x_1509_);
lean_ctor_set(v___x_1511_, 1, v___x_1510_);
v___x_1512_ = lean_obj_once(&lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_junkValuesLinter_spec__4___closed__3, &lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_junkValuesLinter_spec__4___closed__3_once, _init_lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_junkValuesLinter_spec__4___closed__3);
v___x_1513_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1513_, 0, v___x_1511_);
lean_ctor_set(v___x_1513_, 1, v___x_1512_);
lean_inc(v_stx_1479_);
v___x_1514_ = lp_JunkValues_Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1(v___x_1508_, v_stx_1479_, v___x_1513_, v___y_1484_, v___y_1485_, v___y_1486_, v___y_1487_, v___y_1488_, v___y_1489_);
if (lean_obj_tag(v___x_1514_) == 0)
{
lean_dec_ref_known(v___x_1514_, 1);
v_a_1492_ = v___x_1504_;
goto v___jp_1491_;
}
else
{
lean_dec(v_stx_1479_);
lean_dec_ref(v_fst_1478_);
lean_dec_ref(v_fst_1477_);
return v___x_1514_;
}
}
}
else
{
lean_dec(v_stx_1479_);
lean_dec_ref(v_fst_1478_);
lean_dec_ref(v_fst_1477_);
return v___x_1507_;
}
}
else
{
lean_object* v_a_1515_; lean_object* v___x_1517_; uint8_t v_isShared_1518_; uint8_t v_isSharedCheck_1522_; 
lean_dec(v_stx_1479_);
lean_dec_ref(v_fst_1478_);
lean_dec_ref(v_fst_1477_);
v_a_1515_ = lean_ctor_get(v___x_1500_, 0);
v_isSharedCheck_1522_ = !lean_is_exclusive(v___x_1500_);
if (v_isSharedCheck_1522_ == 0)
{
v___x_1517_ = v___x_1500_;
v_isShared_1518_ = v_isSharedCheck_1522_;
goto v_resetjp_1516_;
}
else
{
lean_inc(v_a_1515_);
lean_dec(v___x_1500_);
v___x_1517_ = lean_box(0);
v_isShared_1518_ = v_isSharedCheck_1522_;
goto v_resetjp_1516_;
}
v_resetjp_1516_:
{
lean_object* v___x_1520_; 
if (v_isShared_1518_ == 0)
{
v___x_1520_ = v___x_1517_;
goto v_reusejp_1519_;
}
else
{
lean_object* v_reuseFailAlloc_1521_; 
v_reuseFailAlloc_1521_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1521_, 0, v_a_1515_);
v___x_1520_ = v_reuseFailAlloc_1521_;
goto v_reusejp_1519_;
}
v_reusejp_1519_:
{
return v___x_1520_;
}
}
}
}
v___jp_1491_:
{
size_t v___x_1493_; size_t v___x_1494_; 
v___x_1493_ = ((size_t)1ULL);
v___x_1494_ = lean_usize_add(v_i_1482_, v___x_1493_);
v_i_1482_ = v___x_1494_;
v_b_1483_ = v_a_1492_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_junkValuesLinter_spec__4___boxed(lean_object* v_fst_1523_, lean_object* v_fst_1524_, lean_object* v_stx_1525_, lean_object* v_as_1526_, lean_object* v_sz_1527_, lean_object* v_i_1528_, lean_object* v_b_1529_, lean_object* v___y_1530_, lean_object* v___y_1531_, lean_object* v___y_1532_, lean_object* v___y_1533_, lean_object* v___y_1534_, lean_object* v___y_1535_, lean_object* v___y_1536_){
_start:
{
size_t v_sz_boxed_1537_; size_t v_i_boxed_1538_; lean_object* v_res_1539_; 
v_sz_boxed_1537_ = lean_unbox_usize(v_sz_1527_);
lean_dec(v_sz_1527_);
v_i_boxed_1538_ = lean_unbox_usize(v_i_1528_);
lean_dec(v_i_1528_);
v_res_1539_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_junkValuesLinter_spec__4(v_fst_1523_, v_fst_1524_, v_stx_1525_, v_as_1526_, v_sz_boxed_1537_, v_i_boxed_1538_, v_b_1529_, v___y_1530_, v___y_1531_, v___y_1532_, v___y_1533_, v___y_1534_, v___y_1535_);
lean_dec(v___y_1535_);
lean_dec_ref(v___y_1534_);
lean_dec(v___y_1533_);
lean_dec_ref(v___y_1532_);
lean_dec(v___y_1531_);
lean_dec_ref(v___y_1530_);
lean_dec_ref(v_as_1526_);
return v_res_1539_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_junkValuesLinter___lam__0(lean_object* v_opts_1540_, lean_object* v_stx_1541_, lean_object* v_a_1542_, lean_object* v___y_1543_, lean_object* v___y_1544_, lean_object* v___y_1545_, lean_object* v___y_1546_, lean_object* v___y_1547_, lean_object* v___y_1548_){
_start:
{
lean_object* v___x_1550_; 
v___x_1550_ = lp_JunkValues_JunkValues_setupOf(v_opts_1540_, v___y_1545_, v___y_1546_, v___y_1547_, v___y_1548_);
if (lean_obj_tag(v___x_1550_) == 0)
{
lean_object* v_a_1551_; lean_object* v_snd_1552_; lean_object* v_fst_1553_; lean_object* v_fst_1554_; lean_object* v_snd_1555_; lean_object* v___x_1556_; size_t v_sz_1557_; size_t v___x_1558_; lean_object* v___x_1559_; 
v_a_1551_ = lean_ctor_get(v___x_1550_, 0);
lean_inc(v_a_1551_);
lean_dec_ref_known(v___x_1550_, 1);
v_snd_1552_ = lean_ctor_get(v_a_1551_, 1);
lean_inc(v_snd_1552_);
v_fst_1553_ = lean_ctor_get(v_a_1551_, 0);
lean_inc(v_fst_1553_);
lean_dec(v_a_1551_);
v_fst_1554_ = lean_ctor_get(v_snd_1552_, 0);
lean_inc(v_fst_1554_);
v_snd_1555_ = lean_ctor_get(v_snd_1552_, 1);
lean_inc(v_snd_1555_);
lean_dec(v_snd_1552_);
v___x_1556_ = lean_box(0);
v_sz_1557_ = lean_array_size(v_snd_1555_);
v___x_1558_ = ((size_t)0ULL);
lean_inc(v_stx_1541_);
v___x_1559_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_junkValuesLinter_spec__3(v_stx_1541_, v_snd_1555_, v_sz_1557_, v___x_1558_, v___x_1556_, v___y_1543_, v___y_1544_, v___y_1545_, v___y_1546_, v___y_1547_, v___y_1548_);
lean_dec(v_snd_1555_);
if (lean_obj_tag(v___x_1559_) == 0)
{
size_t v_sz_1560_; lean_object* v___x_1561_; 
lean_dec_ref_known(v___x_1559_, 1);
v_sz_1560_ = lean_array_size(v_a_1542_);
v___x_1561_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_junkValuesLinter_spec__4(v_fst_1553_, v_fst_1554_, v_stx_1541_, v_a_1542_, v_sz_1560_, v___x_1558_, v___x_1556_, v___y_1543_, v___y_1544_, v___y_1545_, v___y_1546_, v___y_1547_, v___y_1548_);
if (lean_obj_tag(v___x_1561_) == 0)
{
lean_object* v___x_1563_; uint8_t v_isShared_1564_; uint8_t v_isSharedCheck_1568_; 
v_isSharedCheck_1568_ = !lean_is_exclusive(v___x_1561_);
if (v_isSharedCheck_1568_ == 0)
{
lean_object* v_unused_1569_; 
v_unused_1569_ = lean_ctor_get(v___x_1561_, 0);
lean_dec(v_unused_1569_);
v___x_1563_ = v___x_1561_;
v_isShared_1564_ = v_isSharedCheck_1568_;
goto v_resetjp_1562_;
}
else
{
lean_dec(v___x_1561_);
v___x_1563_ = lean_box(0);
v_isShared_1564_ = v_isSharedCheck_1568_;
goto v_resetjp_1562_;
}
v_resetjp_1562_:
{
lean_object* v___x_1566_; 
if (v_isShared_1564_ == 0)
{
lean_ctor_set(v___x_1563_, 0, v___x_1556_);
v___x_1566_ = v___x_1563_;
goto v_reusejp_1565_;
}
else
{
lean_object* v_reuseFailAlloc_1567_; 
v_reuseFailAlloc_1567_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1567_, 0, v___x_1556_);
v___x_1566_ = v_reuseFailAlloc_1567_;
goto v_reusejp_1565_;
}
v_reusejp_1565_:
{
return v___x_1566_;
}
}
}
else
{
return v___x_1561_;
}
}
else
{
lean_dec(v_fst_1554_);
lean_dec(v_fst_1553_);
lean_dec(v_stx_1541_);
return v___x_1559_;
}
}
else
{
lean_object* v_a_1570_; lean_object* v___x_1572_; uint8_t v_isShared_1573_; uint8_t v_isSharedCheck_1577_; 
lean_dec(v_stx_1541_);
v_a_1570_ = lean_ctor_get(v___x_1550_, 0);
v_isSharedCheck_1577_ = !lean_is_exclusive(v___x_1550_);
if (v_isSharedCheck_1577_ == 0)
{
v___x_1572_ = v___x_1550_;
v_isShared_1573_ = v_isSharedCheck_1577_;
goto v_resetjp_1571_;
}
else
{
lean_inc(v_a_1570_);
lean_dec(v___x_1550_);
v___x_1572_ = lean_box(0);
v_isShared_1573_ = v_isSharedCheck_1577_;
goto v_resetjp_1571_;
}
v_resetjp_1571_:
{
lean_object* v___x_1575_; 
if (v_isShared_1573_ == 0)
{
v___x_1575_ = v___x_1572_;
goto v_reusejp_1574_;
}
else
{
lean_object* v_reuseFailAlloc_1576_; 
v_reuseFailAlloc_1576_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1576_, 0, v_a_1570_);
v___x_1575_ = v_reuseFailAlloc_1576_;
goto v_reusejp_1574_;
}
v_reusejp_1574_:
{
return v___x_1575_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_junkValuesLinter___lam__0___boxed(lean_object* v_opts_1578_, lean_object* v_stx_1579_, lean_object* v_a_1580_, lean_object* v___y_1581_, lean_object* v___y_1582_, lean_object* v___y_1583_, lean_object* v___y_1584_, lean_object* v___y_1585_, lean_object* v___y_1586_, lean_object* v___y_1587_){
_start:
{
lean_object* v_res_1588_; 
v_res_1588_ = lp_JunkValues_JunkValues_junkValuesLinter___lam__0(v_opts_1578_, v_stx_1579_, v_a_1580_, v___y_1581_, v___y_1582_, v___y_1583_, v___y_1584_, v___y_1585_, v___y_1586_);
lean_dec(v___y_1586_);
lean_dec_ref(v___y_1585_);
lean_dec(v___y_1584_);
lean_dec_ref(v___y_1583_);
lean_dec(v___y_1582_);
lean_dec_ref(v___y_1581_);
lean_dec_ref(v_a_1580_);
return v_res_1588_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_junkValuesLinter___lam__1(lean_object* v_stx_1589_, lean_object* v___y_1590_, lean_object* v___y_1591_){
_start:
{
lean_object* v___x_1593_; lean_object* v_scopes_1594_; lean_object* v___x_1595_; lean_object* v___x_1596_; lean_object* v_opts_1597_; lean_object* v___x_1598_; uint8_t v___x_1599_; 
v___x_1593_ = lean_st_ref_get(v___y_1591_);
v_scopes_1594_ = lean_ctor_get(v___x_1593_, 2);
lean_inc(v_scopes_1594_);
lean_dec(v___x_1593_);
v___x_1595_ = l_Lean_Elab_Command_instInhabitedScope_default;
v___x_1596_ = l_List_head_x21___redArg(v___x_1595_, v_scopes_1594_);
lean_dec(v_scopes_1594_);
v_opts_1597_ = lean_ctor_get(v___x_1596_, 1);
lean_inc_ref(v_opts_1597_);
lean_dec(v___x_1596_);
v___x_1598_ = lp_JunkValues_JunkValues_linter_junkValues;
v___x_1599_ = lp_JunkValues_Lean_Option_get___at___00JunkValues_junkValuesLinter_spec__0(v_opts_1597_, v___x_1598_);
if (v___x_1599_ == 0)
{
lean_object* v___x_1600_; lean_object* v___x_1601_; 
lean_dec_ref(v_opts_1597_);
lean_dec(v_stx_1589_);
v___x_1600_ = lean_box(0);
v___x_1601_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1601_, 0, v___x_1600_);
return v___x_1601_;
}
else
{
lean_object* v___x_1602_; lean_object* v_messages_1603_; uint8_t v___x_1604_; 
v___x_1602_ = lean_st_ref_get(v___y_1591_);
v_messages_1603_ = lean_ctor_get(v___x_1602_, 1);
lean_inc_ref(v_messages_1603_);
lean_dec(v___x_1602_);
v___x_1604_ = l_Lean_MessageLog_hasErrors(v_messages_1603_);
lean_dec_ref(v_messages_1603_);
if (v___x_1604_ == 0)
{
lean_object* v___x_1605_; 
lean_inc(v_stx_1589_);
v___x_1605_ = lp_JunkValues_JunkValues_declIdsOf(v_stx_1589_, v___y_1590_, v___y_1591_);
if (lean_obj_tag(v___x_1605_) == 0)
{
lean_object* v_a_1606_; lean_object* v___x_1608_; uint8_t v_isShared_1609_; uint8_t v_isSharedCheck_1619_; 
v_a_1606_ = lean_ctor_get(v___x_1605_, 0);
v_isSharedCheck_1619_ = !lean_is_exclusive(v___x_1605_);
if (v_isSharedCheck_1619_ == 0)
{
v___x_1608_ = v___x_1605_;
v_isShared_1609_ = v_isSharedCheck_1619_;
goto v_resetjp_1607_;
}
else
{
lean_inc(v_a_1606_);
lean_dec(v___x_1605_);
v___x_1608_ = lean_box(0);
v_isShared_1609_ = v_isSharedCheck_1619_;
goto v_resetjp_1607_;
}
v_resetjp_1607_:
{
lean_object* v___x_1610_; lean_object* v___x_1611_; uint8_t v___x_1612_; 
v___x_1610_ = lean_array_get_size(v_a_1606_);
v___x_1611_ = lean_unsigned_to_nat(0u);
v___x_1612_ = lean_nat_dec_eq(v___x_1610_, v___x_1611_);
if (v___x_1612_ == 0)
{
lean_object* v___f_1613_; lean_object* v___x_1614_; 
lean_del_object(v___x_1608_);
v___f_1613_ = lean_alloc_closure((void*)(lp_JunkValues_JunkValues_junkValuesLinter___lam__0___boxed), 10, 3);
lean_closure_set(v___f_1613_, 0, v_opts_1597_);
lean_closure_set(v___f_1613_, 1, v_stx_1589_);
lean_closure_set(v___f_1613_, 2, v_a_1606_);
v___x_1614_ = l_Lean_Elab_Command_liftTermElabM___redArg(v___f_1613_, v___y_1590_, v___y_1591_);
return v___x_1614_;
}
else
{
lean_object* v___x_1615_; lean_object* v___x_1617_; 
lean_dec(v_a_1606_);
lean_dec_ref(v_opts_1597_);
lean_dec(v_stx_1589_);
v___x_1615_ = lean_box(0);
if (v_isShared_1609_ == 0)
{
lean_ctor_set(v___x_1608_, 0, v___x_1615_);
v___x_1617_ = v___x_1608_;
goto v_reusejp_1616_;
}
else
{
lean_object* v_reuseFailAlloc_1618_; 
v_reuseFailAlloc_1618_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1618_, 0, v___x_1615_);
v___x_1617_ = v_reuseFailAlloc_1618_;
goto v_reusejp_1616_;
}
v_reusejp_1616_:
{
return v___x_1617_;
}
}
}
}
else
{
lean_object* v_a_1620_; lean_object* v___x_1622_; uint8_t v_isShared_1623_; uint8_t v_isSharedCheck_1627_; 
lean_dec_ref(v_opts_1597_);
lean_dec(v_stx_1589_);
v_a_1620_ = lean_ctor_get(v___x_1605_, 0);
v_isSharedCheck_1627_ = !lean_is_exclusive(v___x_1605_);
if (v_isSharedCheck_1627_ == 0)
{
v___x_1622_ = v___x_1605_;
v_isShared_1623_ = v_isSharedCheck_1627_;
goto v_resetjp_1621_;
}
else
{
lean_inc(v_a_1620_);
lean_dec(v___x_1605_);
v___x_1622_ = lean_box(0);
v_isShared_1623_ = v_isSharedCheck_1627_;
goto v_resetjp_1621_;
}
v_resetjp_1621_:
{
lean_object* v___x_1625_; 
if (v_isShared_1623_ == 0)
{
v___x_1625_ = v___x_1622_;
goto v_reusejp_1624_;
}
else
{
lean_object* v_reuseFailAlloc_1626_; 
v_reuseFailAlloc_1626_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1626_, 0, v_a_1620_);
v___x_1625_ = v_reuseFailAlloc_1626_;
goto v_reusejp_1624_;
}
v_reusejp_1624_:
{
return v___x_1625_;
}
}
}
}
else
{
lean_object* v___x_1628_; lean_object* v___x_1629_; 
lean_dec_ref(v_opts_1597_);
lean_dec(v_stx_1589_);
v___x_1628_ = lean_box(0);
v___x_1629_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1629_, 0, v___x_1628_);
return v___x_1629_;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_junkValuesLinter___lam__1___boxed(lean_object* v_stx_1630_, lean_object* v___y_1631_, lean_object* v___y_1632_, lean_object* v___y_1633_){
_start:
{
lean_object* v_res_1634_; 
v_res_1634_ = lp_JunkValues_JunkValues_junkValuesLinter___lam__1(v_stx_1630_, v___y_1631_, v___y_1632_);
lean_dec(v___y_1632_);
lean_dec_ref(v___y_1631_);
return v_res_1634_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_logAt___at___00Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1_spec__2(lean_object* v_ref_1644_, lean_object* v_msgData_1645_, uint8_t v_severity_1646_, uint8_t v_isSilent_1647_, lean_object* v___y_1648_, lean_object* v___y_1649_, lean_object* v___y_1650_, lean_object* v___y_1651_, lean_object* v___y_1652_, lean_object* v___y_1653_){
_start:
{
lean_object* v___x_1655_; 
v___x_1655_ = lp_JunkValues_Lean_logAt___at___00Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1_spec__2___redArg(v_ref_1644_, v_msgData_1645_, v_severity_1646_, v_isSilent_1647_, v___y_1650_, v___y_1651_, v___y_1652_, v___y_1653_);
return v___x_1655_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Lean_logAt___at___00Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1_spec__2___boxed(lean_object* v_ref_1656_, lean_object* v_msgData_1657_, lean_object* v_severity_1658_, lean_object* v_isSilent_1659_, lean_object* v___y_1660_, lean_object* v___y_1661_, lean_object* v___y_1662_, lean_object* v___y_1663_, lean_object* v___y_1664_, lean_object* v___y_1665_, lean_object* v___y_1666_){
_start:
{
uint8_t v_severity_boxed_1667_; uint8_t v_isSilent_boxed_1668_; lean_object* v_res_1669_; 
v_severity_boxed_1667_ = lean_unbox(v_severity_1658_);
v_isSilent_boxed_1668_ = lean_unbox(v_isSilent_1659_);
v_res_1669_ = lp_JunkValues_Lean_logAt___at___00Lean_logWarningAt___at___00Lean_Linter_logLint___at___00JunkValues_junkValuesLinter_spec__1_spec__1_spec__2(v_ref_1656_, v_msgData_1657_, v_severity_boxed_1667_, v_isSilent_boxed_1668_, v___y_1660_, v___y_1661_, v___y_1662_, v___y_1663_, v___y_1664_, v___y_1665_);
lean_dec(v___y_1665_);
lean_dec_ref(v___y_1664_);
lean_dec(v___y_1663_);
lean_dec_ref(v___y_1662_);
lean_dec(v___y_1661_);
lean_dec_ref(v___y_1660_);
lean_dec(v_ref_1656_);
return v_res_1669_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn_00___x40_JunkValues_Frontend_3445918356____hygCtx___hyg_2_(){
_start:
{
lean_object* v___x_1671_; lean_object* v___x_1672_; 
v___x_1671_ = ((lean_object*)(lp_JunkValues_JunkValues_junkValuesLinter));
v___x_1672_ = l_Lean_Elab_Command_addLinter(v___x_1671_);
return v___x_1672_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn_00___x40_JunkValues_Frontend_3445918356____hygCtx___hyg_2____boxed(lean_object* v_a_1673_){
_start:
{
lean_object* v_res_1674_; 
v_res_1674_ = lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn_00___x40_JunkValues_Frontend_3445918356____hygCtx___hyg_2_();
return v_res_1674_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_projectDecls_spec__0(lean_object* v_as_1675_, size_t v_sz_1676_, size_t v_i_1677_, lean_object* v_b_1678_){
_start:
{
lean_object* v_a_1680_; uint8_t v___x_1684_; 
v___x_1684_ = lean_usize_dec_lt(v_i_1677_, v_sz_1676_);
if (v___x_1684_ == 0)
{
return v_b_1678_;
}
else
{
lean_object* v_a_1685_; uint8_t v___x_1686_; 
v_a_1685_ = lean_array_uget_borrowed(v_as_1675_, v_i_1677_);
v___x_1686_ = l_Lean_Name_isInternal(v_a_1685_);
if (v___x_1686_ == 0)
{
uint8_t v___x_1687_; 
v___x_1687_ = l_Lean_Name_isImplementationDetail(v_a_1685_);
if (v___x_1687_ == 0)
{
uint8_t v___x_1688_; 
v___x_1688_ = l_Lean_isPrivateName(v_a_1685_);
if (v___x_1688_ == 0)
{
lean_object* v___x_1689_; 
lean_inc(v_a_1685_);
v___x_1689_ = lean_array_push(v_b_1678_, v_a_1685_);
v_a_1680_ = v___x_1689_;
goto v___jp_1679_;
}
else
{
v_a_1680_ = v_b_1678_;
goto v___jp_1679_;
}
}
else
{
v_a_1680_ = v_b_1678_;
goto v___jp_1679_;
}
}
else
{
v_a_1680_ = v_b_1678_;
goto v___jp_1679_;
}
}
v___jp_1679_:
{
size_t v___x_1681_; size_t v___x_1682_; 
v___x_1681_ = ((size_t)1ULL);
v___x_1682_ = lean_usize_add(v_i_1677_, v___x_1681_);
v_i_1677_ = v___x_1682_;
v_b_1678_ = v_a_1680_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_projectDecls_spec__0___boxed(lean_object* v_as_1690_, lean_object* v_sz_1691_, lean_object* v_i_1692_, lean_object* v_b_1693_){
_start:
{
size_t v_sz_boxed_1694_; size_t v_i_boxed_1695_; lean_object* v_res_1696_; 
v_sz_boxed_1694_ = lean_unbox_usize(v_sz_1691_);
lean_dec(v_sz_1691_);
v_i_boxed_1695_ = lean_unbox_usize(v_i_1692_);
lean_dec(v_i_1692_);
v_res_1696_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_projectDecls_spec__0(v_as_1690_, v_sz_boxed_1694_, v_i_boxed_1695_, v_b_1693_);
lean_dec_ref(v_as_1690_);
return v_res_1696_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00JunkValues_projectDecls_spec__1___redArg(lean_object* v___x_1697_, lean_object* v_rootPrefix_1698_, lean_object* v___x_1699_, lean_object* v_range_1700_, lean_object* v_b_1701_, lean_object* v_i_1702_){
_start:
{
lean_object* v_stop_1703_; lean_object* v_step_1704_; lean_object* v_a_1706_; uint8_t v___x_1709_; 
v_stop_1703_ = lean_ctor_get(v_range_1700_, 1);
v_step_1704_ = lean_ctor_get(v_range_1700_, 2);
v___x_1709_ = lean_nat_dec_lt(v_i_1702_, v_stop_1703_);
if (v___x_1709_ == 0)
{
lean_dec(v_i_1702_);
return v_b_1701_;
}
else
{
lean_object* v___x_1710_; lean_object* v___x_1711_; lean_object* v_toImport_1712_; lean_object* v_module_1713_; uint8_t v___x_1714_; 
v___x_1710_ = l_Lean_instInhabitedEffectiveImport_default;
v___x_1711_ = lean_array_get_borrowed(v___x_1710_, v___x_1697_, v_i_1702_);
v_toImport_1712_ = lean_ctor_get(v___x_1711_, 0);
v_module_1713_ = lean_ctor_get(v_toImport_1712_, 0);
v___x_1714_ = l_Lean_Name_isPrefixOf(v_rootPrefix_1698_, v_module_1713_);
if (v___x_1714_ == 0)
{
v_a_1706_ = v_b_1701_;
goto v___jp_1705_;
}
else
{
lean_object* v_moduleData_1715_; lean_object* v___x_1716_; lean_object* v___x_1717_; lean_object* v_constNames_1718_; size_t v_sz_1719_; size_t v___x_1720_; lean_object* v___x_1721_; 
v_moduleData_1715_ = lean_ctor_get(v___x_1699_, 6);
v___x_1716_ = l_Lean_instInhabitedModuleData_default;
v___x_1717_ = lean_array_get_borrowed(v___x_1716_, v_moduleData_1715_, v_i_1702_);
v_constNames_1718_ = lean_ctor_get(v___x_1717_, 1);
v_sz_1719_ = lean_array_size(v_constNames_1718_);
v___x_1720_ = ((size_t)0ULL);
v___x_1721_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_projectDecls_spec__0(v_constNames_1718_, v_sz_1719_, v___x_1720_, v_b_1701_);
v_a_1706_ = v___x_1721_;
goto v___jp_1705_;
}
}
v___jp_1705_:
{
lean_object* v___x_1707_; 
v___x_1707_ = lean_nat_add(v_i_1702_, v_step_1704_);
lean_dec(v_i_1702_);
v_b_1701_ = v_a_1706_;
v_i_1702_ = v___x_1707_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00JunkValues_projectDecls_spec__1___redArg___boxed(lean_object* v___x_1722_, lean_object* v_rootPrefix_1723_, lean_object* v___x_1724_, lean_object* v_range_1725_, lean_object* v_b_1726_, lean_object* v_i_1727_){
_start:
{
lean_object* v_res_1728_; 
v_res_1728_ = lp_JunkValues___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00JunkValues_projectDecls_spec__1___redArg(v___x_1722_, v_rootPrefix_1723_, v___x_1724_, v_range_1725_, v_b_1726_, v_i_1727_);
lean_dec_ref(v_range_1725_);
lean_dec_ref(v___x_1724_);
lean_dec(v_rootPrefix_1723_);
lean_dec_ref(v___x_1722_);
return v_res_1728_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_projectDecls(lean_object* v_env_1729_, lean_object* v_rootPrefix_1730_){
_start:
{
lean_object* v___x_1731_; lean_object* v_modules_1732_; lean_object* v___x_1733_; lean_object* v_out_1734_; lean_object* v___x_1735_; lean_object* v___x_1736_; lean_object* v___x_1737_; lean_object* v___x_1738_; 
v___x_1731_ = l_Lean_Environment_header(v_env_1729_);
v_modules_1732_ = lean_ctor_get(v___x_1731_, 3);
lean_inc_ref(v_modules_1732_);
v___x_1733_ = lean_unsigned_to_nat(0u);
v_out_1734_ = ((lean_object*)(lp_JunkValues_JunkValues_declIdsOf___closed__0));
v___x_1735_ = lean_array_get_size(v_modules_1732_);
v___x_1736_ = lean_unsigned_to_nat(1u);
v___x_1737_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_1737_, 0, v___x_1733_);
lean_ctor_set(v___x_1737_, 1, v___x_1735_);
lean_ctor_set(v___x_1737_, 2, v___x_1736_);
v___x_1738_ = lp_JunkValues___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00JunkValues_projectDecls_spec__1___redArg(v_modules_1732_, v_rootPrefix_1730_, v___x_1731_, v___x_1737_, v_out_1734_, v___x_1733_);
lean_dec_ref_known(v___x_1737_, 3);
lean_dec_ref(v___x_1731_);
lean_dec_ref(v_modules_1732_);
return v___x_1738_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_projectDecls___boxed(lean_object* v_env_1739_, lean_object* v_rootPrefix_1740_){
_start:
{
lean_object* v_res_1741_; 
v_res_1741_ = lp_JunkValues_JunkValues_projectDecls(v_env_1739_, v_rootPrefix_1740_);
lean_dec(v_rootPrefix_1740_);
lean_dec_ref(v_env_1739_);
return v_res_1741_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00JunkValues_projectDecls_spec__1(lean_object* v___x_1742_, lean_object* v_rootPrefix_1743_, lean_object* v___x_1744_, lean_object* v_range_1745_, lean_object* v_b_1746_, lean_object* v_i_1747_, lean_object* v_hs_1748_, lean_object* v_hl_1749_){
_start:
{
lean_object* v___x_1750_; 
v___x_1750_ = lp_JunkValues___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00JunkValues_projectDecls_spec__1___redArg(v___x_1742_, v_rootPrefix_1743_, v___x_1744_, v_range_1745_, v_b_1746_, v_i_1747_);
return v___x_1750_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00JunkValues_projectDecls_spec__1___boxed(lean_object* v___x_1751_, lean_object* v_rootPrefix_1752_, lean_object* v___x_1753_, lean_object* v_range_1754_, lean_object* v_b_1755_, lean_object* v_i_1756_, lean_object* v_hs_1757_, lean_object* v_hl_1758_){
_start:
{
lean_object* v_res_1759_; 
v_res_1759_ = lp_JunkValues___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00JunkValues_projectDecls_spec__1(v___x_1751_, v_rootPrefix_1752_, v___x_1753_, v_range_1754_, v_b_1755_, v_i_1756_, v_hs_1757_, v_hl_1758_);
lean_dec_ref(v_range_1754_);
lean_dec_ref(v___x_1753_);
lean_dec(v_rootPrefix_1752_);
lean_dec_ref(v___x_1751_);
return v_res_1759_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_scanProject(lean_object* v_rootPrefix_1760_, lean_object* v_cfg_1761_, lean_object* v_opts_1762_, lean_object* v_a_1763_, lean_object* v_a_1764_, lean_object* v_a_1765_, lean_object* v_a_1766_){
_start:
{
lean_object* v___x_1768_; 
v___x_1768_ = lp_JunkValues_JunkValues_RuleSet_ofEnv(v_opts_1762_, v_a_1763_, v_a_1764_, v_a_1765_, v_a_1766_);
if (lean_obj_tag(v___x_1768_) == 0)
{
lean_object* v_a_1769_; lean_object* v___x_1770_; lean_object* v_env_1771_; lean_object* v_ruleSet_1772_; lean_object* v___x_1773_; lean_object* v___x_1774_; 
v_a_1769_ = lean_ctor_get(v___x_1768_, 0);
lean_inc(v_a_1769_);
lean_dec_ref_known(v___x_1768_, 1);
v___x_1770_ = lean_st_ref_get(v_a_1766_);
v_env_1771_ = lean_ctor_get(v___x_1770_, 0);
lean_inc_ref(v_env_1771_);
lean_dec(v___x_1770_);
v_ruleSet_1772_ = lean_ctor_get(v_a_1769_, 0);
v___x_1773_ = lp_JunkValues_JunkValues_projectDecls(v_env_1771_, v_rootPrefix_1760_);
lean_dec_ref(v_env_1771_);
lean_inc_ref(v_ruleSet_1772_);
v___x_1774_ = lp_JunkValues_JunkValues_scanDecls(v_ruleSet_1772_, v_cfg_1761_, v___x_1773_, v_a_1763_, v_a_1764_, v_a_1765_, v_a_1766_);
lean_dec_ref(v___x_1773_);
if (lean_obj_tag(v___x_1774_) == 0)
{
lean_object* v_a_1775_; lean_object* v___x_1777_; uint8_t v_isShared_1778_; uint8_t v_isSharedCheck_1783_; 
v_a_1775_ = lean_ctor_get(v___x_1774_, 0);
v_isSharedCheck_1783_ = !lean_is_exclusive(v___x_1774_);
if (v_isSharedCheck_1783_ == 0)
{
v___x_1777_ = v___x_1774_;
v_isShared_1778_ = v_isSharedCheck_1783_;
goto v_resetjp_1776_;
}
else
{
lean_inc(v_a_1775_);
lean_dec(v___x_1774_);
v___x_1777_ = lean_box(0);
v_isShared_1778_ = v_isSharedCheck_1783_;
goto v_resetjp_1776_;
}
v_resetjp_1776_:
{
lean_object* v___x_1779_; lean_object* v___x_1781_; 
v___x_1779_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1779_, 0, v_a_1769_);
lean_ctor_set(v___x_1779_, 1, v_a_1775_);
if (v_isShared_1778_ == 0)
{
lean_ctor_set(v___x_1777_, 0, v___x_1779_);
v___x_1781_ = v___x_1777_;
goto v_reusejp_1780_;
}
else
{
lean_object* v_reuseFailAlloc_1782_; 
v_reuseFailAlloc_1782_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1782_, 0, v___x_1779_);
v___x_1781_ = v_reuseFailAlloc_1782_;
goto v_reusejp_1780_;
}
v_reusejp_1780_:
{
return v___x_1781_;
}
}
}
else
{
lean_object* v_a_1784_; lean_object* v___x_1786_; uint8_t v_isShared_1787_; uint8_t v_isSharedCheck_1791_; 
lean_dec(v_a_1769_);
v_a_1784_ = lean_ctor_get(v___x_1774_, 0);
v_isSharedCheck_1791_ = !lean_is_exclusive(v___x_1774_);
if (v_isSharedCheck_1791_ == 0)
{
v___x_1786_ = v___x_1774_;
v_isShared_1787_ = v_isSharedCheck_1791_;
goto v_resetjp_1785_;
}
else
{
lean_inc(v_a_1784_);
lean_dec(v___x_1774_);
v___x_1786_ = lean_box(0);
v_isShared_1787_ = v_isSharedCheck_1791_;
goto v_resetjp_1785_;
}
v_resetjp_1785_:
{
lean_object* v___x_1789_; 
if (v_isShared_1787_ == 0)
{
v___x_1789_ = v___x_1786_;
goto v_reusejp_1788_;
}
else
{
lean_object* v_reuseFailAlloc_1790_; 
v_reuseFailAlloc_1790_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1790_, 0, v_a_1784_);
v___x_1789_ = v_reuseFailAlloc_1790_;
goto v_reusejp_1788_;
}
v_reusejp_1788_:
{
return v___x_1789_;
}
}
}
}
else
{
lean_object* v_a_1792_; lean_object* v___x_1794_; uint8_t v_isShared_1795_; uint8_t v_isSharedCheck_1799_; 
lean_dec_ref(v_cfg_1761_);
v_a_1792_ = lean_ctor_get(v___x_1768_, 0);
v_isSharedCheck_1799_ = !lean_is_exclusive(v___x_1768_);
if (v_isSharedCheck_1799_ == 0)
{
v___x_1794_ = v___x_1768_;
v_isShared_1795_ = v_isSharedCheck_1799_;
goto v_resetjp_1793_;
}
else
{
lean_inc(v_a_1792_);
lean_dec(v___x_1768_);
v___x_1794_ = lean_box(0);
v_isShared_1795_ = v_isSharedCheck_1799_;
goto v_resetjp_1793_;
}
v_resetjp_1793_:
{
lean_object* v___x_1797_; 
if (v_isShared_1795_ == 0)
{
v___x_1797_ = v___x_1794_;
goto v_reusejp_1796_;
}
else
{
lean_object* v_reuseFailAlloc_1798_; 
v_reuseFailAlloc_1798_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1798_, 0, v_a_1792_);
v___x_1797_ = v_reuseFailAlloc_1798_;
goto v_reusejp_1796_;
}
v_reusejp_1796_:
{
return v___x_1797_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_scanProject___boxed(lean_object* v_rootPrefix_1800_, lean_object* v_cfg_1801_, lean_object* v_opts_1802_, lean_object* v_a_1803_, lean_object* v_a_1804_, lean_object* v_a_1805_, lean_object* v_a_1806_, lean_object* v_a_1807_){
_start:
{
lean_object* v_res_1808_; 
v_res_1808_ = lp_JunkValues_JunkValues_scanProject(v_rootPrefix_1800_, v_cfg_1801_, v_opts_1802_, v_a_1803_, v_a_1804_, v_a_1805_, v_a_1806_);
lean_dec(v_a_1806_);
lean_dec_ref(v_a_1805_);
lean_dec(v_a_1804_);
lean_dec_ref(v_a_1803_);
lean_dec(v_rootPrefix_1800_);
return v_res_1808_;
}
}
lean_object* runtime_initialize_Init(uint8_t builtin);
lean_object* runtime_initialize_JunkValues_JunkValues_Scan(uint8_t builtin);
lean_object* runtime_initialize_Lean_Elab_Command(uint8_t builtin);
static bool _G_runtime_initialized = false;
LEAN_EXPORT lean_object* runtime_initialize_JunkValues_JunkValues_Frontend(uint8_t builtin) {
lean_object * res;
if (_G_runtime_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_runtime_initialized = true;
res = runtime_initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = runtime_initialize_JunkValues_JunkValues_Scan(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = runtime_initialize_Lean_Elab_Command(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn_00___x40_JunkValues_Frontend_3713897505____hygCtx___hyg_4_();
if (lean_io_result_is_error(res)) return res;
lp_JunkValues_JunkValues_linter_junkValues = lean_io_result_get_value(res);
lean_mark_persistent(lp_JunkValues_JunkValues_linter_junkValues);
lean_dec_ref(res);
res = lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn_00___x40_JunkValues_Frontend_1659515862____hygCtx___hyg_4_();
if (lean_io_result_is_error(res)) return res;
lp_JunkValues_JunkValues_linter_junkValues_discharger = lean_io_result_get_value(res);
lean_mark_persistent(lp_JunkValues_JunkValues_linter_junkValues_discharger);
lean_dec_ref(res);
res = lp_JunkValues___private_JunkValues_Frontend_0__JunkValues_initFn_00___x40_JunkValues_Frontend_3445918356____hygCtx___hyg_2_();
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return lean_io_result_mk_ok(lean_box(0));
}
lean_object* runtime_initialize_Init(uint8_t builtin);
static bool _G_meta_initialized = false;
LEAN_EXPORT lean_object* meta_initialize_JunkValues_JunkValues_Frontend(uint8_t builtin) {
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
lean_object* initialize_JunkValues_JunkValues_Scan(uint8_t builtin);
lean_object* initialize_Lean_Elab_Command(uint8_t builtin);
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_JunkValues_JunkValues_Frontend(uint8_t builtin) {
lean_object * res;
if (_G_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_initialized = true;
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_JunkValues_JunkValues_Scan(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Lean_Elab_Command(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = runtime_initialize_JunkValues_JunkValues_Frontend(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = meta_initialize_JunkValues_JunkValues_Frontend(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return initialize_JunkValues_JunkValues_Frontend(builtin);
}
#ifdef __cplusplus
}
#endif
