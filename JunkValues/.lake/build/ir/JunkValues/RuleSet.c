// Lean compiler output
// Module: JunkValues.RuleSet
// Imports: public import Init public meta import Init public import JunkValues.Registry public import Std.Data.HashMap
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
lean_object* lean_array_uget_borrowed(lean_object*, size_t);
lean_object* lean_array_uset(lean_object*, size_t, lean_object*);
lean_object* lean_array_get_size(lean_object*);
uint64_t lean_uint64_shift_right(uint64_t, uint64_t);
uint64_t lean_uint64_xor(uint64_t, uint64_t);
size_t lean_uint64_to_usize(uint64_t);
size_t lean_usize_of_nat(lean_object*);
size_t lean_usize_sub(size_t, size_t);
size_t lean_usize_land(size_t, size_t);
uint8_t lean_name_eq(lean_object*, lean_object*);
lean_object* lean_mk_empty_array_with_capacity(lean_object*);
lean_object* lean_array_push(lean_object*, lean_object*);
lean_object* lean_nat_add(lean_object*, lean_object*);
lean_object* lean_nat_mul(lean_object*, lean_object*);
lean_object* lean_nat_div(lean_object*, lean_object*);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
lean_object* lean_mk_array(lean_object*, lean_object*);
uint8_t lean_nat_dec_lt(lean_object*, lean_object*);
lean_object* lean_array_fget(lean_object*, lean_object*);
lean_object* lean_array_fset(lean_object*, lean_object*, lean_object*);
uint64_t lean_uint64_of_nat(lean_object*);
lean_object* lean_nat_sub(lean_object*, lean_object*);
uint8_t lean_usize_dec_eq(size_t, size_t);
size_t lean_usize_add(size_t, size_t);
size_t lean_array_size(lean_object*);
lean_object* l_Array_append___redArg(lean_object*, lean_object*);
lean_object* lean_st_mk_ref(lean_object*);
lean_object* lean_st_ref_take(lean_object*);
lean_object* lean_st_ref_set(lean_object*, lean_object*);
lean_object* lean_st_ref_get(lean_object*);
lean_object* lp_JunkValues_JunkValues_declaredRules(lean_object*);
static lean_once_cell_t lp_JunkValues_JunkValues_instInhabitedRuleSet_default___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_instInhabitedRuleSet_default___closed__0;
static lean_once_cell_t lp_JunkValues_JunkValues_instInhabitedRuleSet_default___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_instInhabitedRuleSet_default___closed__1;
static const lean_array_object lp_JunkValues_JunkValues_instInhabitedRuleSet_default___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* lp_JunkValues_JunkValues_instInhabitedRuleSet_default___closed__2 = (const lean_object*)&lp_JunkValues_JunkValues_instInhabitedRuleSet_default___closed__2_value;
static lean_once_cell_t lp_JunkValues_JunkValues_instInhabitedRuleSet_default___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_instInhabitedRuleSet_default___closed__3;
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instInhabitedRuleSet_default;
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instInhabitedRuleSet;
LEAN_EXPORT uint8_t lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_Const_alter___at___00JunkValues_RuleSet_insert_spec__0_spec__0___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_Const_alter___at___00JunkValues_RuleSet_insert_spec__0_spec__0___redArg___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_Const_alter___at___00Std_DHashMap_Internal_Raw_u2080_Const_alter___at___00JunkValues_RuleSet_insert_spec__0_spec__2___lam__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_Const_alter___at___00Std_DHashMap_Internal_Raw_u2080_Const_alter___at___00JunkValues_RuleSet_insert_spec__0_spec__2(lean_object*, lean_object*, lean_object*);
static lean_once_cell_t lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00__private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_Const_alter___at___00JunkValues_RuleSet_insert_spec__0_spec__1_spec__2_spec__4___redArg___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static uint64_t lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00__private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_Const_alter___at___00JunkValues_RuleSet_insert_spec__0_spec__1_spec__2_spec__4___redArg___closed__0;
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00__private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_Const_alter___at___00JunkValues_RuleSet_insert_spec__0_spec__1_spec__2_spec__4___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_Const_alter___at___00JunkValues_RuleSet_insert_spec__0_spec__1_spec__2___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_Const_alter___at___00JunkValues_RuleSet_insert_spec__0_spec__1___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_Const_alter___at___00JunkValues_RuleSet_insert_spec__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_JunkValues___private_Init_Data_Array_Basic_0__Array_anyMUnsafe_any___at___00JunkValues_RuleSet_insert_spec__1(lean_object*, lean_object*, size_t, size_t);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_anyMUnsafe_any___at___00JunkValues_RuleSet_insert_spec__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_RuleSet_insert(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_Const_alter___at___00JunkValues_RuleSet_insert_spec__0_spec__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_Const_alter___at___00JunkValues_RuleSet_insert_spec__0_spec__0___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_Const_alter___at___00JunkValues_RuleSet_insert_spec__0_spec__1(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_Const_alter___at___00JunkValues_RuleSet_insert_spec__0_spec__1_spec__2(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00__private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_Const_alter___at___00JunkValues_RuleSet_insert_spec__0_spec__1_spec__2_spec__4(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_getD___at___00Std_DHashMap_Internal_Raw_u2080_Const_getD___at___00JunkValues_RuleSet_forHead_spec__0_spec__0___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_getD___at___00Std_DHashMap_Internal_Raw_u2080_Const_getD___at___00JunkValues_RuleSet_forHead_spec__0_spec__0___redArg___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_Const_getD___at___00JunkValues_RuleSet_forHead_spec__0___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_Const_getD___at___00JunkValues_RuleSet_forHead_spec__0___redArg___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_RuleSet_forHead(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_RuleSet_forHead___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_Const_getD___at___00JunkValues_RuleSet_forHead_spec__0(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_Const_getD___at___00JunkValues_RuleSet_forHead_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_getD___at___00Std_DHashMap_Internal_Raw_u2080_Const_getD___at___00JunkValues_RuleSet_forHead_spec__0_spec__0(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_getD___at___00Std_DHashMap_Internal_Raw_u2080_Const_getD___at___00JunkValues_RuleSet_forHead_spec__0_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_ctor_object lp_JunkValues_JunkValues_instInhabitedProviderResult_default___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&lp_JunkValues_JunkValues_instInhabitedRuleSet_default___closed__2_value),((lean_object*)&lp_JunkValues_JunkValues_instInhabitedRuleSet_default___closed__2_value)}};
static const lean_object* lp_JunkValues_JunkValues_instInhabitedProviderResult_default___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_instInhabitedProviderResult_default___closed__0_value;
LEAN_EXPORT const lean_object* lp_JunkValues_JunkValues_instInhabitedProviderResult_default = (const lean_object*)&lp_JunkValues_JunkValues_instInhabitedProviderResult_default___closed__0_value;
LEAN_EXPORT const lean_object* lp_JunkValues_JunkValues_instInhabitedProviderResult = (const lean_object*)&lp_JunkValues_JunkValues_instInhabitedProviderResult_default___closed__0_value;
static const lean_array_object lp_JunkValues___private_JunkValues_RuleSet_0__JunkValues_initFn___closed__0_00___x40_JunkValues_RuleSet_3177306610____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* lp_JunkValues___private_JunkValues_RuleSet_0__JunkValues_initFn___closed__0_00___x40_JunkValues_RuleSet_3177306610____hygCtx___hyg_2_ = (const lean_object*)&lp_JunkValues___private_JunkValues_RuleSet_0__JunkValues_initFn___closed__0_00___x40_JunkValues_RuleSet_3177306610____hygCtx___hyg_2__value;
LEAN_EXPORT lean_object* lp_JunkValues___private_JunkValues_RuleSet_0__JunkValues_initFn_00___x40_JunkValues_RuleSet_3177306610____hygCtx___hyg_2_();
LEAN_EXPORT lean_object* lp_JunkValues___private_JunkValues_RuleSet_0__JunkValues_initFn_00___x40_JunkValues_RuleSet_3177306610____hygCtx___hyg_2____boxed(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_ruleProviders;
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_registerRuleProvider(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_registerRuleProvider___boxed(lean_object*, lean_object*);
static lean_once_cell_t lp_JunkValues_JunkValues_instInhabitedRuleSetReport_default___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_JunkValues_JunkValues_instInhabitedRuleSetReport_default___closed__0;
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instInhabitedRuleSetReport_default;
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_instInhabitedRuleSetReport;
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_RuleSetReport_warnings(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_RuleSetReport_warnings___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_RuleSet_ofEnv_spec__0___redArg(lean_object*, size_t, size_t, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_RuleSet_ofEnv_spec__0___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_RuleSet_ofEnv_spec__1(lean_object*, lean_object*, size_t, size_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_RuleSet_ofEnv_spec__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object lp_JunkValues_JunkValues_RuleSet_ofEnv___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 14, .m_capacity = 14, .m_length = 13, .m_data = "@[junk_value]"};
static const lean_object* lp_JunkValues_JunkValues_RuleSet_ofEnv___closed__0 = (const lean_object*)&lp_JunkValues_JunkValues_RuleSet_ofEnv___closed__0_value;
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_RuleSet_ofEnv(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_RuleSet_ofEnv___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_RuleSet_ofEnv_spec__0(lean_object*, size_t, size_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_RuleSet_ofEnv_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static lean_object* _init_lp_JunkValues_JunkValues_instInhabitedRuleSet_default___closed__0(void){
_start:
{
lean_object* v___x_1_; lean_object* v___x_2_; lean_object* v___x_3_; 
v___x_1_ = lean_box(0);
v___x_2_ = lean_unsigned_to_nat(16u);
v___x_3_ = lean_mk_array(v___x_2_, v___x_1_);
return v___x_3_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instInhabitedRuleSet_default___closed__1(void){
_start:
{
lean_object* v___x_4_; lean_object* v___x_5_; lean_object* v___x_6_; 
v___x_4_ = lean_obj_once(&lp_JunkValues_JunkValues_instInhabitedRuleSet_default___closed__0, &lp_JunkValues_JunkValues_instInhabitedRuleSet_default___closed__0_once, _init_lp_JunkValues_JunkValues_instInhabitedRuleSet_default___closed__0);
v___x_5_ = lean_unsigned_to_nat(0u);
v___x_6_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_6_, 0, v___x_5_);
lean_ctor_set(v___x_6_, 1, v___x_4_);
return v___x_6_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instInhabitedRuleSet_default___closed__3(void){
_start:
{
lean_object* v___x_9_; lean_object* v___x_10_; lean_object* v___x_11_; 
v___x_9_ = ((lean_object*)(lp_JunkValues_JunkValues_instInhabitedRuleSet_default___closed__2));
v___x_10_ = lean_obj_once(&lp_JunkValues_JunkValues_instInhabitedRuleSet_default___closed__1, &lp_JunkValues_JunkValues_instInhabitedRuleSet_default___closed__1_once, _init_lp_JunkValues_JunkValues_instInhabitedRuleSet_default___closed__1);
v___x_11_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_11_, 0, v___x_10_);
lean_ctor_set(v___x_11_, 1, v___x_9_);
return v___x_11_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instInhabitedRuleSet_default(void){
_start:
{
lean_object* v___x_12_; 
v___x_12_ = lean_obj_once(&lp_JunkValues_JunkValues_instInhabitedRuleSet_default___closed__3, &lp_JunkValues_JunkValues_instInhabitedRuleSet_default___closed__3_once, _init_lp_JunkValues_JunkValues_instInhabitedRuleSet_default___closed__3);
return v___x_12_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instInhabitedRuleSet(void){
_start:
{
lean_object* v___x_13_; 
v___x_13_ = lp_JunkValues_JunkValues_instInhabitedRuleSet_default;
return v___x_13_;
}
}
LEAN_EXPORT uint8_t lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_Const_alter___at___00JunkValues_RuleSet_insert_spec__0_spec__0___redArg(lean_object* v_a_14_, lean_object* v_x_15_){
_start:
{
if (lean_obj_tag(v_x_15_) == 0)
{
uint8_t v___x_16_; 
v___x_16_ = 0;
return v___x_16_;
}
else
{
lean_object* v_key_17_; lean_object* v_tail_18_; uint8_t v___x_19_; 
v_key_17_ = lean_ctor_get(v_x_15_, 0);
v_tail_18_ = lean_ctor_get(v_x_15_, 2);
v___x_19_ = lean_name_eq(v_key_17_, v_a_14_);
if (v___x_19_ == 0)
{
v_x_15_ = v_tail_18_;
goto _start;
}
else
{
return v___x_19_;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_Const_alter___at___00JunkValues_RuleSet_insert_spec__0_spec__0___redArg___boxed(lean_object* v_a_21_, lean_object* v_x_22_){
_start:
{
uint8_t v_res_23_; lean_object* v_r_24_; 
v_res_23_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_Const_alter___at___00JunkValues_RuleSet_insert_spec__0_spec__0___redArg(v_a_21_, v_x_22_);
lean_dec(v_x_22_);
lean_dec(v_a_21_);
v_r_24_ = lean_box(v_res_23_);
return v_r_24_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_Const_alter___at___00Std_DHashMap_Internal_Raw_u2080_Const_alter___at___00JunkValues_RuleSet_insert_spec__0_spec__2___lam__0(lean_object* v_rule_25_, lean_object* v_x_26_){
_start:
{
if (lean_obj_tag(v_x_26_) == 0)
{
lean_object* v___x_27_; lean_object* v___x_28_; lean_object* v___x_29_; lean_object* v___x_30_; 
v___x_27_ = lean_unsigned_to_nat(1u);
v___x_28_ = lean_mk_empty_array_with_capacity(v___x_27_);
v___x_29_ = lean_array_push(v___x_28_, v_rule_25_);
v___x_30_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_30_, 0, v___x_29_);
return v___x_30_;
}
else
{
lean_object* v_val_31_; lean_object* v___x_33_; uint8_t v_isShared_34_; uint8_t v_isSharedCheck_39_; 
v_val_31_ = lean_ctor_get(v_x_26_, 0);
v_isSharedCheck_39_ = !lean_is_exclusive(v_x_26_);
if (v_isSharedCheck_39_ == 0)
{
v___x_33_ = v_x_26_;
v_isShared_34_ = v_isSharedCheck_39_;
goto v_resetjp_32_;
}
else
{
lean_inc(v_val_31_);
lean_dec(v_x_26_);
v___x_33_ = lean_box(0);
v_isShared_34_ = v_isSharedCheck_39_;
goto v_resetjp_32_;
}
v_resetjp_32_:
{
lean_object* v___x_35_; lean_object* v___x_37_; 
v___x_35_ = lean_array_push(v_val_31_, v_rule_25_);
if (v_isShared_34_ == 0)
{
lean_ctor_set(v___x_33_, 0, v___x_35_);
v___x_37_ = v___x_33_;
goto v_reusejp_36_;
}
else
{
lean_object* v_reuseFailAlloc_38_; 
v_reuseFailAlloc_38_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_38_, 0, v___x_35_);
v___x_37_ = v_reuseFailAlloc_38_;
goto v_reusejp_36_;
}
v_reusejp_36_:
{
return v___x_37_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_Const_alter___at___00Std_DHashMap_Internal_Raw_u2080_Const_alter___at___00JunkValues_RuleSet_insert_spec__0_spec__2(lean_object* v_rule_40_, lean_object* v_a_41_, lean_object* v_x_42_){
_start:
{
if (lean_obj_tag(v_x_42_) == 0)
{
lean_object* v___x_43_; lean_object* v___x_44_; lean_object* v_val_45_; lean_object* v___x_46_; 
v___x_43_ = lean_box(0);
v___x_44_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_Const_alter___at___00Std_DHashMap_Internal_Raw_u2080_Const_alter___at___00JunkValues_RuleSet_insert_spec__0_spec__2___lam__0(v_rule_40_, v___x_43_);
v_val_45_ = lean_ctor_get(v___x_44_, 0);
lean_inc(v_val_45_);
lean_dec(v___x_44_);
v___x_46_ = lean_alloc_ctor(1, 3, 0);
lean_ctor_set(v___x_46_, 0, v_a_41_);
lean_ctor_set(v___x_46_, 1, v_val_45_);
lean_ctor_set(v___x_46_, 2, v_x_42_);
return v___x_46_;
}
else
{
lean_object* v_key_47_; lean_object* v_value_48_; lean_object* v_tail_49_; lean_object* v___x_51_; uint8_t v_isShared_52_; uint8_t v_isSharedCheck_64_; 
v_key_47_ = lean_ctor_get(v_x_42_, 0);
v_value_48_ = lean_ctor_get(v_x_42_, 1);
v_tail_49_ = lean_ctor_get(v_x_42_, 2);
v_isSharedCheck_64_ = !lean_is_exclusive(v_x_42_);
if (v_isSharedCheck_64_ == 0)
{
v___x_51_ = v_x_42_;
v_isShared_52_ = v_isSharedCheck_64_;
goto v_resetjp_50_;
}
else
{
lean_inc(v_tail_49_);
lean_inc(v_value_48_);
lean_inc(v_key_47_);
lean_dec(v_x_42_);
v___x_51_ = lean_box(0);
v_isShared_52_ = v_isSharedCheck_64_;
goto v_resetjp_50_;
}
v_resetjp_50_:
{
uint8_t v___x_53_; 
v___x_53_ = lean_name_eq(v_key_47_, v_a_41_);
if (v___x_53_ == 0)
{
lean_object* v_tail_54_; lean_object* v___x_56_; 
v_tail_54_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_Const_alter___at___00Std_DHashMap_Internal_Raw_u2080_Const_alter___at___00JunkValues_RuleSet_insert_spec__0_spec__2(v_rule_40_, v_a_41_, v_tail_49_);
if (v_isShared_52_ == 0)
{
lean_ctor_set(v___x_51_, 2, v_tail_54_);
v___x_56_ = v___x_51_;
goto v_reusejp_55_;
}
else
{
lean_object* v_reuseFailAlloc_57_; 
v_reuseFailAlloc_57_ = lean_alloc_ctor(1, 3, 0);
lean_ctor_set(v_reuseFailAlloc_57_, 0, v_key_47_);
lean_ctor_set(v_reuseFailAlloc_57_, 1, v_value_48_);
lean_ctor_set(v_reuseFailAlloc_57_, 2, v_tail_54_);
v___x_56_ = v_reuseFailAlloc_57_;
goto v_reusejp_55_;
}
v_reusejp_55_:
{
return v___x_56_;
}
}
else
{
lean_object* v___x_58_; lean_object* v___x_59_; lean_object* v_val_60_; lean_object* v___x_62_; 
lean_dec(v_key_47_);
v___x_58_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_58_, 0, v_value_48_);
v___x_59_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_Const_alter___at___00Std_DHashMap_Internal_Raw_u2080_Const_alter___at___00JunkValues_RuleSet_insert_spec__0_spec__2___lam__0(v_rule_40_, v___x_58_);
v_val_60_ = lean_ctor_get(v___x_59_, 0);
lean_inc(v_val_60_);
lean_dec(v___x_59_);
if (v_isShared_52_ == 0)
{
lean_ctor_set(v___x_51_, 1, v_val_60_);
lean_ctor_set(v___x_51_, 0, v_a_41_);
v___x_62_ = v___x_51_;
goto v_reusejp_61_;
}
else
{
lean_object* v_reuseFailAlloc_63_; 
v_reuseFailAlloc_63_ = lean_alloc_ctor(1, 3, 0);
lean_ctor_set(v_reuseFailAlloc_63_, 0, v_a_41_);
lean_ctor_set(v_reuseFailAlloc_63_, 1, v_val_60_);
lean_ctor_set(v_reuseFailAlloc_63_, 2, v_tail_49_);
v___x_62_ = v_reuseFailAlloc_63_;
goto v_reusejp_61_;
}
v_reusejp_61_:
{
return v___x_62_;
}
}
}
}
}
}
static uint64_t _init_lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00__private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_Const_alter___at___00JunkValues_RuleSet_insert_spec__0_spec__1_spec__2_spec__4___redArg___closed__0(void){
_start:
{
lean_object* v___x_65_; uint64_t v___x_66_; 
v___x_65_ = lean_unsigned_to_nat(1723u);
v___x_66_ = lean_uint64_of_nat(v___x_65_);
return v___x_66_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00__private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_Const_alter___at___00JunkValues_RuleSet_insert_spec__0_spec__1_spec__2_spec__4___redArg(lean_object* v_x_67_, lean_object* v_x_68_){
_start:
{
if (lean_obj_tag(v_x_68_) == 0)
{
return v_x_67_;
}
else
{
lean_object* v_key_69_; lean_object* v_value_70_; lean_object* v_tail_71_; lean_object* v___x_73_; uint8_t v_isShared_74_; uint8_t v_isSharedCheck_97_; 
v_key_69_ = lean_ctor_get(v_x_68_, 0);
v_value_70_ = lean_ctor_get(v_x_68_, 1);
v_tail_71_ = lean_ctor_get(v_x_68_, 2);
v_isSharedCheck_97_ = !lean_is_exclusive(v_x_68_);
if (v_isSharedCheck_97_ == 0)
{
v___x_73_ = v_x_68_;
v_isShared_74_ = v_isSharedCheck_97_;
goto v_resetjp_72_;
}
else
{
lean_inc(v_tail_71_);
lean_inc(v_value_70_);
lean_inc(v_key_69_);
lean_dec(v_x_68_);
v___x_73_ = lean_box(0);
v_isShared_74_ = v_isSharedCheck_97_;
goto v_resetjp_72_;
}
v_resetjp_72_:
{
lean_object* v___x_75_; uint64_t v___y_77_; 
v___x_75_ = lean_array_get_size(v_x_67_);
if (lean_obj_tag(v_key_69_) == 0)
{
uint64_t v___x_95_; 
v___x_95_ = lean_uint64_once(&lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00__private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_Const_alter___at___00JunkValues_RuleSet_insert_spec__0_spec__1_spec__2_spec__4___redArg___closed__0, &lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00__private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_Const_alter___at___00JunkValues_RuleSet_insert_spec__0_spec__1_spec__2_spec__4___redArg___closed__0_once, _init_lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00__private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_Const_alter___at___00JunkValues_RuleSet_insert_spec__0_spec__1_spec__2_spec__4___redArg___closed__0);
v___y_77_ = v___x_95_;
goto v___jp_76_;
}
else
{
uint64_t v_hash_96_; 
v_hash_96_ = lean_ctor_get_uint64(v_key_69_, sizeof(void*)*2);
v___y_77_ = v_hash_96_;
goto v___jp_76_;
}
v___jp_76_:
{
uint64_t v___x_78_; uint64_t v___x_79_; uint64_t v_fold_80_; uint64_t v___x_81_; uint64_t v___x_82_; uint64_t v___x_83_; size_t v___x_84_; size_t v___x_85_; size_t v___x_86_; size_t v___x_87_; size_t v___x_88_; lean_object* v___x_89_; lean_object* v___x_91_; 
v___x_78_ = 32ULL;
v___x_79_ = lean_uint64_shift_right(v___y_77_, v___x_78_);
v_fold_80_ = lean_uint64_xor(v___y_77_, v___x_79_);
v___x_81_ = 16ULL;
v___x_82_ = lean_uint64_shift_right(v_fold_80_, v___x_81_);
v___x_83_ = lean_uint64_xor(v_fold_80_, v___x_82_);
v___x_84_ = lean_uint64_to_usize(v___x_83_);
v___x_85_ = lean_usize_of_nat(v___x_75_);
v___x_86_ = ((size_t)1ULL);
v___x_87_ = lean_usize_sub(v___x_85_, v___x_86_);
v___x_88_ = lean_usize_land(v___x_84_, v___x_87_);
v___x_89_ = lean_array_uget_borrowed(v_x_67_, v___x_88_);
lean_inc(v___x_89_);
if (v_isShared_74_ == 0)
{
lean_ctor_set(v___x_73_, 2, v___x_89_);
v___x_91_ = v___x_73_;
goto v_reusejp_90_;
}
else
{
lean_object* v_reuseFailAlloc_94_; 
v_reuseFailAlloc_94_ = lean_alloc_ctor(1, 3, 0);
lean_ctor_set(v_reuseFailAlloc_94_, 0, v_key_69_);
lean_ctor_set(v_reuseFailAlloc_94_, 1, v_value_70_);
lean_ctor_set(v_reuseFailAlloc_94_, 2, v___x_89_);
v___x_91_ = v_reuseFailAlloc_94_;
goto v_reusejp_90_;
}
v_reusejp_90_:
{
lean_object* v___x_92_; 
v___x_92_ = lean_array_uset(v_x_67_, v___x_88_, v___x_91_);
v_x_67_ = v___x_92_;
v_x_68_ = v_tail_71_;
goto _start;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_Const_alter___at___00JunkValues_RuleSet_insert_spec__0_spec__1_spec__2___redArg(lean_object* v_i_98_, lean_object* v_source_99_, lean_object* v_target_100_){
_start:
{
lean_object* v___x_101_; uint8_t v___x_102_; 
v___x_101_ = lean_array_get_size(v_source_99_);
v___x_102_ = lean_nat_dec_lt(v_i_98_, v___x_101_);
if (v___x_102_ == 0)
{
lean_dec_ref(v_source_99_);
lean_dec(v_i_98_);
return v_target_100_;
}
else
{
lean_object* v_es_103_; lean_object* v___x_104_; lean_object* v_source_105_; lean_object* v_target_106_; lean_object* v___x_107_; lean_object* v___x_108_; 
v_es_103_ = lean_array_fget(v_source_99_, v_i_98_);
v___x_104_ = lean_box(0);
v_source_105_ = lean_array_fset(v_source_99_, v_i_98_, v___x_104_);
v_target_106_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00__private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_Const_alter___at___00JunkValues_RuleSet_insert_spec__0_spec__1_spec__2_spec__4___redArg(v_target_100_, v_es_103_);
v___x_107_ = lean_unsigned_to_nat(1u);
v___x_108_ = lean_nat_add(v_i_98_, v___x_107_);
lean_dec(v_i_98_);
v_i_98_ = v___x_108_;
v_source_99_ = v_source_105_;
v_target_100_ = v_target_106_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_Const_alter___at___00JunkValues_RuleSet_insert_spec__0_spec__1___redArg(lean_object* v_data_110_){
_start:
{
lean_object* v___x_111_; lean_object* v___x_112_; lean_object* v_nbuckets_113_; lean_object* v___x_114_; lean_object* v___x_115_; lean_object* v___x_116_; lean_object* v___x_117_; 
v___x_111_ = lean_array_get_size(v_data_110_);
v___x_112_ = lean_unsigned_to_nat(2u);
v_nbuckets_113_ = lean_nat_mul(v___x_111_, v___x_112_);
v___x_114_ = lean_unsigned_to_nat(0u);
v___x_115_ = lean_box(0);
v___x_116_ = lean_mk_array(v_nbuckets_113_, v___x_115_);
v___x_117_ = lp_JunkValues___private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_Const_alter___at___00JunkValues_RuleSet_insert_spec__0_spec__1_spec__2___redArg(v___x_114_, v_data_110_, v___x_116_);
return v___x_117_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_Const_alter___at___00JunkValues_RuleSet_insert_spec__0(lean_object* v_rule_118_, lean_object* v_m_119_, lean_object* v_a_120_){
_start:
{
lean_object* v___y_122_; size_t v___y_123_; lean_object* v___y_124_; lean_object* v___y_125_; lean_object* v_size_128_; lean_object* v_buckets_129_; lean_object* v___x_131_; uint8_t v_isShared_132_; uint8_t v_isSharedCheck_176_; 
v_size_128_ = lean_ctor_get(v_m_119_, 0);
v_buckets_129_ = lean_ctor_get(v_m_119_, 1);
v_isSharedCheck_176_ = !lean_is_exclusive(v_m_119_);
if (v_isSharedCheck_176_ == 0)
{
v___x_131_ = v_m_119_;
v_isShared_132_ = v_isSharedCheck_176_;
goto v_resetjp_130_;
}
else
{
lean_inc(v_buckets_129_);
lean_inc(v_size_128_);
lean_dec(v_m_119_);
v___x_131_ = lean_box(0);
v_isShared_132_ = v_isSharedCheck_176_;
goto v_resetjp_130_;
}
v___jp_121_:
{
lean_object* v___x_126_; lean_object* v___x_127_; 
v___x_126_ = lean_array_uset(v___y_122_, v___y_123_, v___y_124_);
v___x_127_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_127_, 0, v___y_125_);
lean_ctor_set(v___x_127_, 1, v___x_126_);
return v___x_127_;
}
v_resetjp_130_:
{
lean_object* v___x_133_; uint64_t v___y_135_; 
v___x_133_ = lean_array_get_size(v_buckets_129_);
if (lean_obj_tag(v_a_120_) == 0)
{
uint64_t v___x_174_; 
v___x_174_ = lean_uint64_once(&lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00__private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_Const_alter___at___00JunkValues_RuleSet_insert_spec__0_spec__1_spec__2_spec__4___redArg___closed__0, &lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00__private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_Const_alter___at___00JunkValues_RuleSet_insert_spec__0_spec__1_spec__2_spec__4___redArg___closed__0_once, _init_lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00__private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_Const_alter___at___00JunkValues_RuleSet_insert_spec__0_spec__1_spec__2_spec__4___redArg___closed__0);
v___y_135_ = v___x_174_;
goto v___jp_134_;
}
else
{
uint64_t v_hash_175_; 
v_hash_175_ = lean_ctor_get_uint64(v_a_120_, sizeof(void*)*2);
v___y_135_ = v_hash_175_;
goto v___jp_134_;
}
v___jp_134_:
{
uint64_t v___x_136_; uint64_t v___x_137_; uint64_t v_fold_138_; uint64_t v___x_139_; uint64_t v___x_140_; uint64_t v___x_141_; size_t v___x_142_; size_t v___x_143_; size_t v___x_144_; size_t v___x_145_; size_t v___x_146_; lean_object* v_bkt_147_; uint8_t v___x_148_; 
v___x_136_ = 32ULL;
v___x_137_ = lean_uint64_shift_right(v___y_135_, v___x_136_);
v_fold_138_ = lean_uint64_xor(v___y_135_, v___x_137_);
v___x_139_ = 16ULL;
v___x_140_ = lean_uint64_shift_right(v_fold_138_, v___x_139_);
v___x_141_ = lean_uint64_xor(v_fold_138_, v___x_140_);
v___x_142_ = lean_uint64_to_usize(v___x_141_);
v___x_143_ = lean_usize_of_nat(v___x_133_);
v___x_144_ = ((size_t)1ULL);
v___x_145_ = lean_usize_sub(v___x_143_, v___x_144_);
v___x_146_ = lean_usize_land(v___x_142_, v___x_145_);
v_bkt_147_ = lean_array_uget_borrowed(v_buckets_129_, v___x_146_);
v___x_148_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_Const_alter___at___00JunkValues_RuleSet_insert_spec__0_spec__0___redArg(v_a_120_, v_bkt_147_);
if (v___x_148_ == 0)
{
lean_object* v___x_149_; lean_object* v___x_150_; lean_object* v___x_151_; lean_object* v_size_x27_152_; lean_object* v___x_153_; lean_object* v_buckets_x27_154_; lean_object* v___x_155_; lean_object* v___x_156_; lean_object* v___x_157_; lean_object* v___x_158_; lean_object* v___x_159_; uint8_t v___x_160_; 
v___x_149_ = lean_unsigned_to_nat(1u);
v___x_150_ = lean_mk_empty_array_with_capacity(v___x_149_);
v___x_151_ = lean_array_push(v___x_150_, v_rule_118_);
v_size_x27_152_ = lean_nat_add(v_size_128_, v___x_149_);
lean_dec(v_size_128_);
lean_inc(v_bkt_147_);
v___x_153_ = lean_alloc_ctor(1, 3, 0);
lean_ctor_set(v___x_153_, 0, v_a_120_);
lean_ctor_set(v___x_153_, 1, v___x_151_);
lean_ctor_set(v___x_153_, 2, v_bkt_147_);
v_buckets_x27_154_ = lean_array_uset(v_buckets_129_, v___x_146_, v___x_153_);
v___x_155_ = lean_unsigned_to_nat(4u);
v___x_156_ = lean_nat_mul(v_size_x27_152_, v___x_155_);
v___x_157_ = lean_unsigned_to_nat(3u);
v___x_158_ = lean_nat_div(v___x_156_, v___x_157_);
lean_dec(v___x_156_);
v___x_159_ = lean_array_get_size(v_buckets_x27_154_);
v___x_160_ = lean_nat_dec_le(v___x_158_, v___x_159_);
lean_dec(v___x_158_);
if (v___x_160_ == 0)
{
lean_object* v_val_161_; lean_object* v___x_163_; 
v_val_161_ = lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_Const_alter___at___00JunkValues_RuleSet_insert_spec__0_spec__1___redArg(v_buckets_x27_154_);
if (v_isShared_132_ == 0)
{
lean_ctor_set(v___x_131_, 1, v_val_161_);
lean_ctor_set(v___x_131_, 0, v_size_x27_152_);
v___x_163_ = v___x_131_;
goto v_reusejp_162_;
}
else
{
lean_object* v_reuseFailAlloc_164_; 
v_reuseFailAlloc_164_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_164_, 0, v_size_x27_152_);
lean_ctor_set(v_reuseFailAlloc_164_, 1, v_val_161_);
v___x_163_ = v_reuseFailAlloc_164_;
goto v_reusejp_162_;
}
v_reusejp_162_:
{
return v___x_163_;
}
}
else
{
lean_object* v___x_166_; 
if (v_isShared_132_ == 0)
{
lean_ctor_set(v___x_131_, 1, v_buckets_x27_154_);
lean_ctor_set(v___x_131_, 0, v_size_x27_152_);
v___x_166_ = v___x_131_;
goto v_reusejp_165_;
}
else
{
lean_object* v_reuseFailAlloc_167_; 
v_reuseFailAlloc_167_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_167_, 0, v_size_x27_152_);
lean_ctor_set(v_reuseFailAlloc_167_, 1, v_buckets_x27_154_);
v___x_166_ = v_reuseFailAlloc_167_;
goto v_reusejp_165_;
}
v_reusejp_165_:
{
return v___x_166_;
}
}
}
else
{
lean_object* v___x_168_; lean_object* v_buckets_x27_169_; lean_object* v_bkt_x27_170_; uint8_t v___x_171_; 
lean_inc(v_bkt_147_);
lean_del_object(v___x_131_);
v___x_168_ = lean_box(0);
v_buckets_x27_169_ = lean_array_uset(v_buckets_129_, v___x_146_, v___x_168_);
lean_inc(v_a_120_);
v_bkt_x27_170_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_Const_alter___at___00Std_DHashMap_Internal_Raw_u2080_Const_alter___at___00JunkValues_RuleSet_insert_spec__0_spec__2(v_rule_118_, v_a_120_, v_bkt_147_);
v___x_171_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_Const_alter___at___00JunkValues_RuleSet_insert_spec__0_spec__0___redArg(v_a_120_, v_bkt_x27_170_);
lean_dec(v_a_120_);
if (v___x_171_ == 0)
{
lean_object* v___x_172_; lean_object* v___x_173_; 
v___x_172_ = lean_unsigned_to_nat(1u);
v___x_173_ = lean_nat_sub(v_size_128_, v___x_172_);
lean_dec(v_size_128_);
v___y_122_ = v_buckets_x27_169_;
v___y_123_ = v___x_146_;
v___y_124_ = v_bkt_x27_170_;
v___y_125_ = v___x_173_;
goto v___jp_121_;
}
else
{
v___y_122_ = v_buckets_x27_169_;
v___y_123_ = v___x_146_;
v___y_124_ = v_bkt_x27_170_;
v___y_125_ = v_size_128_;
goto v___jp_121_;
}
}
}
}
}
}
LEAN_EXPORT uint8_t lp_JunkValues___private_Init_Data_Array_Basic_0__Array_anyMUnsafe_any___at___00JunkValues_RuleSet_insert_spec__1(lean_object* v_rule_177_, lean_object* v_as_178_, size_t v_i_179_, size_t v_stop_180_){
_start:
{
uint8_t v___x_181_; 
v___x_181_ = lean_usize_dec_eq(v_i_179_, v_stop_180_);
if (v___x_181_ == 0)
{
lean_object* v___x_182_; lean_object* v_source_183_; lean_object* v_source_184_; uint8_t v___x_185_; 
v___x_182_ = lean_array_uget_borrowed(v_as_178_, v_i_179_);
v_source_183_ = lean_ctor_get(v___x_182_, 0);
v_source_184_ = lean_ctor_get(v_rule_177_, 0);
v___x_185_ = lean_name_eq(v_source_183_, v_source_184_);
if (v___x_185_ == 0)
{
size_t v___x_186_; size_t v___x_187_; 
v___x_186_ = ((size_t)1ULL);
v___x_187_ = lean_usize_add(v_i_179_, v___x_186_);
v_i_179_ = v___x_187_;
goto _start;
}
else
{
return v___x_185_;
}
}
else
{
uint8_t v___x_189_; 
v___x_189_ = 0;
return v___x_189_;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_anyMUnsafe_any___at___00JunkValues_RuleSet_insert_spec__1___boxed(lean_object* v_rule_190_, lean_object* v_as_191_, lean_object* v_i_192_, lean_object* v_stop_193_){
_start:
{
size_t v_i_boxed_194_; size_t v_stop_boxed_195_; uint8_t v_res_196_; lean_object* v_r_197_; 
v_i_boxed_194_ = lean_unbox_usize(v_i_192_);
lean_dec(v_i_192_);
v_stop_boxed_195_ = lean_unbox_usize(v_stop_193_);
lean_dec(v_stop_193_);
v_res_196_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_anyMUnsafe_any___at___00JunkValues_RuleSet_insert_spec__1(v_rule_190_, v_as_191_, v_i_boxed_194_, v_stop_boxed_195_);
lean_dec_ref(v_as_191_);
lean_dec_ref(v_rule_190_);
v_r_197_ = lean_box(v_res_196_);
return v_r_197_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_RuleSet_insert(lean_object* v_rs_198_, lean_object* v_rule_199_){
_start:
{
lean_object* v_byHead_200_; lean_object* v_rules_201_; lean_object* v___x_207_; lean_object* v___x_208_; uint8_t v___x_209_; 
v_byHead_200_ = lean_ctor_get(v_rs_198_, 0);
v_rules_201_ = lean_ctor_get(v_rs_198_, 1);
v___x_207_ = lean_unsigned_to_nat(0u);
v___x_208_ = lean_array_get_size(v_rules_201_);
v___x_209_ = lean_nat_dec_lt(v___x_207_, v___x_208_);
if (v___x_209_ == 0)
{
lean_inc_ref(v_rules_201_);
lean_inc_ref(v_byHead_200_);
lean_dec_ref(v_rs_198_);
goto v___jp_202_;
}
else
{
if (v___x_209_ == 0)
{
lean_inc_ref(v_rules_201_);
lean_inc_ref(v_byHead_200_);
lean_dec_ref(v_rs_198_);
goto v___jp_202_;
}
else
{
size_t v___x_210_; size_t v___x_211_; uint8_t v___x_212_; 
v___x_210_ = ((size_t)0ULL);
v___x_211_ = lean_usize_of_nat(v___x_208_);
v___x_212_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_anyMUnsafe_any___at___00JunkValues_RuleSet_insert_spec__1(v_rule_199_, v_rules_201_, v___x_210_, v___x_211_);
if (v___x_212_ == 0)
{
lean_inc_ref(v_rules_201_);
lean_inc_ref(v_byHead_200_);
lean_dec_ref(v_rs_198_);
goto v___jp_202_;
}
else
{
lean_dec_ref(v_rule_199_);
return v_rs_198_;
}
}
}
v___jp_202_:
{
lean_object* v_head_203_; lean_object* v___x_204_; lean_object* v___x_205_; lean_object* v___x_206_; 
v_head_203_ = lean_ctor_get(v_rule_199_, 1);
lean_inc(v_head_203_);
lean_inc_ref(v_rule_199_);
v___x_204_ = lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_Const_alter___at___00JunkValues_RuleSet_insert_spec__0(v_rule_199_, v_byHead_200_, v_head_203_);
v___x_205_ = lean_array_push(v_rules_201_, v_rule_199_);
v___x_206_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_206_, 0, v___x_204_);
lean_ctor_set(v___x_206_, 1, v___x_205_);
return v___x_206_;
}
}
}
LEAN_EXPORT uint8_t lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_Const_alter___at___00JunkValues_RuleSet_insert_spec__0_spec__0(lean_object* v_00_u03b2_213_, lean_object* v_a_214_, lean_object* v_x_215_){
_start:
{
uint8_t v___x_216_; 
v___x_216_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_Const_alter___at___00JunkValues_RuleSet_insert_spec__0_spec__0___redArg(v_a_214_, v_x_215_);
return v___x_216_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_Const_alter___at___00JunkValues_RuleSet_insert_spec__0_spec__0___boxed(lean_object* v_00_u03b2_217_, lean_object* v_a_218_, lean_object* v_x_219_){
_start:
{
uint8_t v_res_220_; lean_object* v_r_221_; 
v_res_220_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_Const_alter___at___00JunkValues_RuleSet_insert_spec__0_spec__0(v_00_u03b2_217_, v_a_218_, v_x_219_);
lean_dec(v_x_219_);
lean_dec(v_a_218_);
v_r_221_ = lean_box(v_res_220_);
return v_r_221_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_Const_alter___at___00JunkValues_RuleSet_insert_spec__0_spec__1(lean_object* v_00_u03b2_222_, lean_object* v_data_223_){
_start:
{
lean_object* v___x_224_; 
v___x_224_ = lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_Const_alter___at___00JunkValues_RuleSet_insert_spec__0_spec__1___redArg(v_data_223_);
return v___x_224_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_Const_alter___at___00JunkValues_RuleSet_insert_spec__0_spec__1_spec__2(lean_object* v_00_u03b2_225_, lean_object* v_i_226_, lean_object* v_source_227_, lean_object* v_target_228_){
_start:
{
lean_object* v___x_229_; 
v___x_229_ = lp_JunkValues___private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_Const_alter___at___00JunkValues_RuleSet_insert_spec__0_spec__1_spec__2___redArg(v_i_226_, v_source_227_, v_target_228_);
return v___x_229_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00__private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_Const_alter___at___00JunkValues_RuleSet_insert_spec__0_spec__1_spec__2_spec__4(lean_object* v_00_u03b2_230_, lean_object* v_x_231_, lean_object* v_x_232_){
_start:
{
lean_object* v___x_233_; 
v___x_233_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00__private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_Const_alter___at___00JunkValues_RuleSet_insert_spec__0_spec__1_spec__2_spec__4___redArg(v_x_231_, v_x_232_);
return v___x_233_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_getD___at___00Std_DHashMap_Internal_Raw_u2080_Const_getD___at___00JunkValues_RuleSet_forHead_spec__0_spec__0___redArg(lean_object* v_a_234_, lean_object* v_fallback_235_, lean_object* v_x_236_){
_start:
{
if (lean_obj_tag(v_x_236_) == 0)
{
lean_inc(v_fallback_235_);
return v_fallback_235_;
}
else
{
lean_object* v_key_237_; lean_object* v_value_238_; lean_object* v_tail_239_; uint8_t v___x_240_; 
v_key_237_ = lean_ctor_get(v_x_236_, 0);
v_value_238_ = lean_ctor_get(v_x_236_, 1);
v_tail_239_ = lean_ctor_get(v_x_236_, 2);
v___x_240_ = lean_name_eq(v_key_237_, v_a_234_);
if (v___x_240_ == 0)
{
v_x_236_ = v_tail_239_;
goto _start;
}
else
{
lean_inc(v_value_238_);
return v_value_238_;
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_getD___at___00Std_DHashMap_Internal_Raw_u2080_Const_getD___at___00JunkValues_RuleSet_forHead_spec__0_spec__0___redArg___boxed(lean_object* v_a_242_, lean_object* v_fallback_243_, lean_object* v_x_244_){
_start:
{
lean_object* v_res_245_; 
v_res_245_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_getD___at___00Std_DHashMap_Internal_Raw_u2080_Const_getD___at___00JunkValues_RuleSet_forHead_spec__0_spec__0___redArg(v_a_242_, v_fallback_243_, v_x_244_);
lean_dec(v_x_244_);
lean_dec(v_fallback_243_);
lean_dec(v_a_242_);
return v_res_245_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_Const_getD___at___00JunkValues_RuleSet_forHead_spec__0___redArg(lean_object* v_m_246_, lean_object* v_a_247_, lean_object* v_fallback_248_){
_start:
{
lean_object* v_buckets_249_; lean_object* v___x_250_; uint64_t v___y_252_; 
v_buckets_249_ = lean_ctor_get(v_m_246_, 1);
v___x_250_ = lean_array_get_size(v_buckets_249_);
if (lean_obj_tag(v_a_247_) == 0)
{
uint64_t v___x_266_; 
v___x_266_ = lean_uint64_once(&lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00__private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_Const_alter___at___00JunkValues_RuleSet_insert_spec__0_spec__1_spec__2_spec__4___redArg___closed__0, &lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00__private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_Const_alter___at___00JunkValues_RuleSet_insert_spec__0_spec__1_spec__2_spec__4___redArg___closed__0_once, _init_lp_JunkValues_Std_DHashMap_Internal_AssocList_foldlM___at___00__private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_Const_alter___at___00JunkValues_RuleSet_insert_spec__0_spec__1_spec__2_spec__4___redArg___closed__0);
v___y_252_ = v___x_266_;
goto v___jp_251_;
}
else
{
uint64_t v_hash_267_; 
v_hash_267_ = lean_ctor_get_uint64(v_a_247_, sizeof(void*)*2);
v___y_252_ = v_hash_267_;
goto v___jp_251_;
}
v___jp_251_:
{
uint64_t v___x_253_; uint64_t v___x_254_; uint64_t v_fold_255_; uint64_t v___x_256_; uint64_t v___x_257_; uint64_t v___x_258_; size_t v___x_259_; size_t v___x_260_; size_t v___x_261_; size_t v___x_262_; size_t v___x_263_; lean_object* v___x_264_; lean_object* v___x_265_; 
v___x_253_ = 32ULL;
v___x_254_ = lean_uint64_shift_right(v___y_252_, v___x_253_);
v_fold_255_ = lean_uint64_xor(v___y_252_, v___x_254_);
v___x_256_ = 16ULL;
v___x_257_ = lean_uint64_shift_right(v_fold_255_, v___x_256_);
v___x_258_ = lean_uint64_xor(v_fold_255_, v___x_257_);
v___x_259_ = lean_uint64_to_usize(v___x_258_);
v___x_260_ = lean_usize_of_nat(v___x_250_);
v___x_261_ = ((size_t)1ULL);
v___x_262_ = lean_usize_sub(v___x_260_, v___x_261_);
v___x_263_ = lean_usize_land(v___x_259_, v___x_262_);
v___x_264_ = lean_array_uget_borrowed(v_buckets_249_, v___x_263_);
v___x_265_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_getD___at___00Std_DHashMap_Internal_Raw_u2080_Const_getD___at___00JunkValues_RuleSet_forHead_spec__0_spec__0___redArg(v_a_247_, v_fallback_248_, v___x_264_);
return v___x_265_;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_Const_getD___at___00JunkValues_RuleSet_forHead_spec__0___redArg___boxed(lean_object* v_m_268_, lean_object* v_a_269_, lean_object* v_fallback_270_){
_start:
{
lean_object* v_res_271_; 
v_res_271_ = lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_Const_getD___at___00JunkValues_RuleSet_forHead_spec__0___redArg(v_m_268_, v_a_269_, v_fallback_270_);
lean_dec(v_fallback_270_);
lean_dec(v_a_269_);
lean_dec_ref(v_m_268_);
return v_res_271_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_RuleSet_forHead(lean_object* v_rs_272_, lean_object* v_head_273_){
_start:
{
lean_object* v_byHead_274_; lean_object* v___x_275_; lean_object* v___x_276_; 
v_byHead_274_ = lean_ctor_get(v_rs_272_, 0);
v___x_275_ = ((lean_object*)(lp_JunkValues_JunkValues_instInhabitedRuleSet_default___closed__2));
v___x_276_ = lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_Const_getD___at___00JunkValues_RuleSet_forHead_spec__0___redArg(v_byHead_274_, v_head_273_, v___x_275_);
return v___x_276_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_RuleSet_forHead___boxed(lean_object* v_rs_277_, lean_object* v_head_278_){
_start:
{
lean_object* v_res_279_; 
v_res_279_ = lp_JunkValues_JunkValues_RuleSet_forHead(v_rs_277_, v_head_278_);
lean_dec(v_head_278_);
lean_dec_ref(v_rs_277_);
return v_res_279_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_Const_getD___at___00JunkValues_RuleSet_forHead_spec__0(lean_object* v_00_u03b2_280_, lean_object* v_m_281_, lean_object* v_a_282_, lean_object* v_fallback_283_){
_start:
{
lean_object* v___x_284_; 
v___x_284_ = lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_Const_getD___at___00JunkValues_RuleSet_forHead_spec__0___redArg(v_m_281_, v_a_282_, v_fallback_283_);
return v___x_284_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_Const_getD___at___00JunkValues_RuleSet_forHead_spec__0___boxed(lean_object* v_00_u03b2_285_, lean_object* v_m_286_, lean_object* v_a_287_, lean_object* v_fallback_288_){
_start:
{
lean_object* v_res_289_; 
v_res_289_ = lp_JunkValues_Std_DHashMap_Internal_Raw_u2080_Const_getD___at___00JunkValues_RuleSet_forHead_spec__0(v_00_u03b2_285_, v_m_286_, v_a_287_, v_fallback_288_);
lean_dec(v_fallback_288_);
lean_dec(v_a_287_);
lean_dec_ref(v_m_286_);
return v_res_289_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_getD___at___00Std_DHashMap_Internal_Raw_u2080_Const_getD___at___00JunkValues_RuleSet_forHead_spec__0_spec__0(lean_object* v_00_u03b2_290_, lean_object* v_a_291_, lean_object* v_fallback_292_, lean_object* v_x_293_){
_start:
{
lean_object* v___x_294_; 
v___x_294_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_getD___at___00Std_DHashMap_Internal_Raw_u2080_Const_getD___at___00JunkValues_RuleSet_forHead_spec__0_spec__0___redArg(v_a_291_, v_fallback_292_, v_x_293_);
return v___x_294_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_Std_DHashMap_Internal_AssocList_getD___at___00Std_DHashMap_Internal_Raw_u2080_Const_getD___at___00JunkValues_RuleSet_forHead_spec__0_spec__0___boxed(lean_object* v_00_u03b2_295_, lean_object* v_a_296_, lean_object* v_fallback_297_, lean_object* v_x_298_){
_start:
{
lean_object* v_res_299_; 
v_res_299_ = lp_JunkValues_Std_DHashMap_Internal_AssocList_getD___at___00Std_DHashMap_Internal_Raw_u2080_Const_getD___at___00JunkValues_RuleSet_forHead_spec__0_spec__0(v_00_u03b2_295_, v_a_296_, v_fallback_297_, v_x_298_);
lean_dec(v_x_298_);
lean_dec(v_fallback_297_);
lean_dec(v_a_296_);
return v_res_299_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_JunkValues_RuleSet_0__JunkValues_initFn_00___x40_JunkValues_RuleSet_3177306610____hygCtx___hyg_2_(){
_start:
{
lean_object* v___x_307_; lean_object* v___x_308_; lean_object* v___x_309_; 
v___x_307_ = ((lean_object*)(lp_JunkValues___private_JunkValues_RuleSet_0__JunkValues_initFn___closed__0_00___x40_JunkValues_RuleSet_3177306610____hygCtx___hyg_2_));
v___x_308_ = lean_st_mk_ref(v___x_307_);
v___x_309_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_309_, 0, v___x_308_);
return v___x_309_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_JunkValues_RuleSet_0__JunkValues_initFn_00___x40_JunkValues_RuleSet_3177306610____hygCtx___hyg_2____boxed(lean_object* v_a_310_){
_start:
{
lean_object* v_res_311_; 
v_res_311_ = lp_JunkValues___private_JunkValues_RuleSet_0__JunkValues_initFn_00___x40_JunkValues_RuleSet_3177306610____hygCtx___hyg_2_();
return v_res_311_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_registerRuleProvider(lean_object* v_provider_312_){
_start:
{
lean_object* v___x_314_; lean_object* v___x_315_; lean_object* v___x_316_; lean_object* v___x_317_; lean_object* v___x_318_; 
v___x_314_ = lp_JunkValues_JunkValues_ruleProviders;
v___x_315_ = lean_st_ref_take(v___x_314_);
v___x_316_ = lean_array_push(v___x_315_, v_provider_312_);
v___x_317_ = lean_st_ref_set(v___x_314_, v___x_316_);
v___x_318_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_318_, 0, v___x_317_);
return v___x_318_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_registerRuleProvider___boxed(lean_object* v_provider_319_, lean_object* v_a_320_){
_start:
{
lean_object* v_res_321_; 
v_res_321_ = lp_JunkValues_JunkValues_registerRuleProvider(v_provider_319_);
return v_res_321_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instInhabitedRuleSetReport_default___closed__0(void){
_start:
{
lean_object* v___x_322_; lean_object* v___x_323_; lean_object* v___x_324_; 
v___x_322_ = ((lean_object*)(lp_JunkValues_JunkValues_instInhabitedRuleSet_default___closed__2));
v___x_323_ = lean_obj_once(&lp_JunkValues_JunkValues_instInhabitedRuleSet_default___closed__3, &lp_JunkValues_JunkValues_instInhabitedRuleSet_default___closed__3_once, _init_lp_JunkValues_JunkValues_instInhabitedRuleSet_default___closed__3);
v___x_324_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_324_, 0, v___x_323_);
lean_ctor_set(v___x_324_, 1, v___x_322_);
lean_ctor_set(v___x_324_, 2, v___x_322_);
return v___x_324_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instInhabitedRuleSetReport_default(void){
_start:
{
lean_object* v___x_325_; 
v___x_325_ = lean_obj_once(&lp_JunkValues_JunkValues_instInhabitedRuleSetReport_default___closed__0, &lp_JunkValues_JunkValues_instInhabitedRuleSetReport_default___closed__0_once, _init_lp_JunkValues_JunkValues_instInhabitedRuleSetReport_default___closed__0);
return v___x_325_;
}
}
static lean_object* _init_lp_JunkValues_JunkValues_instInhabitedRuleSetReport(void){
_start:
{
lean_object* v___x_326_; 
v___x_326_ = lp_JunkValues_JunkValues_instInhabitedRuleSetReport_default;
return v___x_326_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_RuleSetReport_warnings(lean_object* v_r_327_){
_start:
{
lean_object* v_problems_328_; 
v_problems_328_ = lean_ctor_get(v_r_327_, 2);
lean_inc_ref(v_problems_328_);
return v_problems_328_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_RuleSetReport_warnings___boxed(lean_object* v_r_329_){
_start:
{
lean_object* v_res_330_; 
v_res_330_ = lp_JunkValues_JunkValues_RuleSetReport_warnings(v_r_329_);
lean_dec_ref(v_r_329_);
return v_res_330_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_RuleSet_ofEnv_spec__0___redArg(lean_object* v_as_331_, size_t v_sz_332_, size_t v_i_333_, lean_object* v_b_334_){
_start:
{
uint8_t v___x_336_; 
v___x_336_ = lean_usize_dec_lt(v_i_333_, v_sz_332_);
if (v___x_336_ == 0)
{
lean_object* v___x_337_; 
v___x_337_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_337_, 0, v_b_334_);
return v___x_337_;
}
else
{
lean_object* v_a_338_; lean_object* v___x_339_; size_t v___x_340_; size_t v___x_341_; 
v_a_338_ = lean_array_uget_borrowed(v_as_331_, v_i_333_);
lean_inc(v_a_338_);
v___x_339_ = lp_JunkValues_JunkValues_RuleSet_insert(v_b_334_, v_a_338_);
v___x_340_ = ((size_t)1ULL);
v___x_341_ = lean_usize_add(v_i_333_, v___x_340_);
v_i_333_ = v___x_341_;
v_b_334_ = v___x_339_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_RuleSet_ofEnv_spec__0___redArg___boxed(lean_object* v_as_343_, lean_object* v_sz_344_, lean_object* v_i_345_, lean_object* v_b_346_, lean_object* v___y_347_){
_start:
{
size_t v_sz_boxed_348_; size_t v_i_boxed_349_; lean_object* v_res_350_; 
v_sz_boxed_348_ = lean_unbox_usize(v_sz_344_);
lean_dec(v_sz_344_);
v_i_boxed_349_ = lean_unbox_usize(v_i_345_);
lean_dec(v_i_345_);
v_res_350_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_RuleSet_ofEnv_spec__0___redArg(v_as_343_, v_sz_boxed_348_, v_i_boxed_349_, v_b_346_);
lean_dec_ref(v_as_343_);
return v_res_350_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_RuleSet_ofEnv_spec__1(lean_object* v_opts_351_, lean_object* v_as_352_, size_t v_sz_353_, size_t v_i_354_, lean_object* v_b_355_, lean_object* v___y_356_, lean_object* v___y_357_, lean_object* v___y_358_, lean_object* v___y_359_){
_start:
{
uint8_t v___x_361_; 
v___x_361_ = lean_usize_dec_lt(v_i_354_, v_sz_353_);
if (v___x_361_ == 0)
{
lean_object* v___x_362_; 
lean_dec_ref(v_opts_351_);
v___x_362_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_362_, 0, v_b_355_);
return v___x_362_;
}
else
{
lean_object* v_a_363_; lean_object* v_name_364_; lean_object* v_run_365_; lean_object* v___x_366_; 
v_a_363_ = lean_array_uget_borrowed(v_as_352_, v_i_354_);
v_name_364_ = lean_ctor_get(v_a_363_, 0);
v_run_365_ = lean_ctor_get(v_a_363_, 1);
lean_inc_ref(v_run_365_);
lean_inc(v___y_359_);
lean_inc_ref(v___y_358_);
lean_inc(v___y_357_);
lean_inc_ref(v___y_356_);
lean_inc_ref(v_opts_351_);
v___x_366_ = lean_apply_6(v_run_365_, v_opts_351_, v___y_356_, v___y_357_, v___y_358_, v___y_359_, lean_box(0));
if (lean_obj_tag(v___x_366_) == 0)
{
lean_object* v_ruleSet_367_; lean_object* v_a_368_; lean_object* v_contributions_369_; lean_object* v_problems_370_; lean_object* v___x_372_; uint8_t v_isShared_373_; uint8_t v_isSharedCheck_408_; 
v_ruleSet_367_ = lean_ctor_get(v_b_355_, 0);
lean_inc_ref(v_ruleSet_367_);
v_a_368_ = lean_ctor_get(v___x_366_, 0);
lean_inc(v_a_368_);
lean_dec_ref_known(v___x_366_, 1);
v_contributions_369_ = lean_ctor_get(v_b_355_, 1);
v_problems_370_ = lean_ctor_get(v_b_355_, 2);
v_isSharedCheck_408_ = !lean_is_exclusive(v_b_355_);
if (v_isSharedCheck_408_ == 0)
{
lean_object* v_unused_409_; 
v_unused_409_ = lean_ctor_get(v_b_355_, 0);
lean_dec(v_unused_409_);
v___x_372_ = v_b_355_;
v_isShared_373_ = v_isSharedCheck_408_;
goto v_resetjp_371_;
}
else
{
lean_inc(v_problems_370_);
lean_inc(v_contributions_369_);
lean_dec(v_b_355_);
v___x_372_ = lean_box(0);
v_isShared_373_ = v_isSharedCheck_408_;
goto v_resetjp_371_;
}
v_resetjp_371_:
{
lean_object* v_rules_374_; lean_object* v_rules_375_; lean_object* v_problems_376_; lean_object* v___x_378_; uint8_t v_isShared_379_; uint8_t v_isSharedCheck_407_; 
v_rules_374_ = lean_ctor_get(v_ruleSet_367_, 1);
lean_inc_ref(v_rules_374_);
v_rules_375_ = lean_ctor_get(v_a_368_, 0);
v_problems_376_ = lean_ctor_get(v_a_368_, 1);
v_isSharedCheck_407_ = !lean_is_exclusive(v_a_368_);
if (v_isSharedCheck_407_ == 0)
{
v___x_378_ = v_a_368_;
v_isShared_379_ = v_isSharedCheck_407_;
goto v_resetjp_377_;
}
else
{
lean_inc(v_problems_376_);
lean_inc(v_rules_375_);
lean_dec(v_a_368_);
v___x_378_ = lean_box(0);
v_isShared_379_ = v_isSharedCheck_407_;
goto v_resetjp_377_;
}
v_resetjp_377_:
{
size_t v_sz_380_; size_t v___x_381_; lean_object* v___x_382_; 
v_sz_380_ = lean_array_size(v_rules_375_);
v___x_381_ = ((size_t)0ULL);
v___x_382_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_RuleSet_ofEnv_spec__0___redArg(v_rules_375_, v_sz_380_, v___x_381_, v_ruleSet_367_);
lean_dec_ref(v_rules_375_);
if (lean_obj_tag(v___x_382_) == 0)
{
lean_object* v_a_383_; lean_object* v_rules_384_; lean_object* v___x_385_; lean_object* v___x_386_; lean_object* v___x_387_; lean_object* v___x_389_; 
v_a_383_ = lean_ctor_get(v___x_382_, 0);
lean_inc(v_a_383_);
lean_dec_ref_known(v___x_382_, 1);
v_rules_384_ = lean_ctor_get(v_a_383_, 1);
v___x_385_ = lean_array_get_size(v_rules_374_);
lean_dec_ref(v_rules_374_);
v___x_386_ = lean_array_get_size(v_rules_384_);
v___x_387_ = lean_nat_sub(v___x_386_, v___x_385_);
lean_inc_ref(v_name_364_);
if (v_isShared_379_ == 0)
{
lean_ctor_set(v___x_378_, 1, v___x_387_);
lean_ctor_set(v___x_378_, 0, v_name_364_);
v___x_389_ = v___x_378_;
goto v_reusejp_388_;
}
else
{
lean_object* v_reuseFailAlloc_398_; 
v_reuseFailAlloc_398_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_398_, 0, v_name_364_);
lean_ctor_set(v_reuseFailAlloc_398_, 1, v___x_387_);
v___x_389_ = v_reuseFailAlloc_398_;
goto v_reusejp_388_;
}
v_reusejp_388_:
{
lean_object* v___x_390_; lean_object* v___x_391_; lean_object* v___x_393_; 
v___x_390_ = lean_array_push(v_contributions_369_, v___x_389_);
v___x_391_ = l_Array_append___redArg(v_problems_370_, v_problems_376_);
lean_dec_ref(v_problems_376_);
if (v_isShared_373_ == 0)
{
lean_ctor_set(v___x_372_, 2, v___x_391_);
lean_ctor_set(v___x_372_, 1, v___x_390_);
lean_ctor_set(v___x_372_, 0, v_a_383_);
v___x_393_ = v___x_372_;
goto v_reusejp_392_;
}
else
{
lean_object* v_reuseFailAlloc_397_; 
v_reuseFailAlloc_397_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v_reuseFailAlloc_397_, 0, v_a_383_);
lean_ctor_set(v_reuseFailAlloc_397_, 1, v___x_390_);
lean_ctor_set(v_reuseFailAlloc_397_, 2, v___x_391_);
v___x_393_ = v_reuseFailAlloc_397_;
goto v_reusejp_392_;
}
v_reusejp_392_:
{
size_t v___x_394_; size_t v___x_395_; 
v___x_394_ = ((size_t)1ULL);
v___x_395_ = lean_usize_add(v_i_354_, v___x_394_);
v_i_354_ = v___x_395_;
v_b_355_ = v___x_393_;
goto _start;
}
}
}
else
{
lean_object* v_a_399_; lean_object* v___x_401_; uint8_t v_isShared_402_; uint8_t v_isSharedCheck_406_; 
lean_del_object(v___x_378_);
lean_dec_ref(v_problems_376_);
lean_dec_ref(v_rules_374_);
lean_del_object(v___x_372_);
lean_dec_ref(v_problems_370_);
lean_dec_ref(v_contributions_369_);
lean_dec_ref(v_opts_351_);
v_a_399_ = lean_ctor_get(v___x_382_, 0);
v_isSharedCheck_406_ = !lean_is_exclusive(v___x_382_);
if (v_isSharedCheck_406_ == 0)
{
v___x_401_ = v___x_382_;
v_isShared_402_ = v_isSharedCheck_406_;
goto v_resetjp_400_;
}
else
{
lean_inc(v_a_399_);
lean_dec(v___x_382_);
v___x_401_ = lean_box(0);
v_isShared_402_ = v_isSharedCheck_406_;
goto v_resetjp_400_;
}
v_resetjp_400_:
{
lean_object* v___x_404_; 
if (v_isShared_402_ == 0)
{
v___x_404_ = v___x_401_;
goto v_reusejp_403_;
}
else
{
lean_object* v_reuseFailAlloc_405_; 
v_reuseFailAlloc_405_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_405_, 0, v_a_399_);
v___x_404_ = v_reuseFailAlloc_405_;
goto v_reusejp_403_;
}
v_reusejp_403_:
{
return v___x_404_;
}
}
}
}
}
}
else
{
lean_object* v_a_410_; lean_object* v___x_412_; uint8_t v_isShared_413_; uint8_t v_isSharedCheck_417_; 
lean_dec_ref(v_b_355_);
lean_dec_ref(v_opts_351_);
v_a_410_ = lean_ctor_get(v___x_366_, 0);
v_isSharedCheck_417_ = !lean_is_exclusive(v___x_366_);
if (v_isSharedCheck_417_ == 0)
{
v___x_412_ = v___x_366_;
v_isShared_413_ = v_isSharedCheck_417_;
goto v_resetjp_411_;
}
else
{
lean_inc(v_a_410_);
lean_dec(v___x_366_);
v___x_412_ = lean_box(0);
v_isShared_413_ = v_isSharedCheck_417_;
goto v_resetjp_411_;
}
v_resetjp_411_:
{
lean_object* v___x_415_; 
if (v_isShared_413_ == 0)
{
v___x_415_ = v___x_412_;
goto v_reusejp_414_;
}
else
{
lean_object* v_reuseFailAlloc_416_; 
v_reuseFailAlloc_416_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_416_, 0, v_a_410_);
v___x_415_ = v_reuseFailAlloc_416_;
goto v_reusejp_414_;
}
v_reusejp_414_:
{
return v___x_415_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_RuleSet_ofEnv_spec__1___boxed(lean_object* v_opts_418_, lean_object* v_as_419_, lean_object* v_sz_420_, lean_object* v_i_421_, lean_object* v_b_422_, lean_object* v___y_423_, lean_object* v___y_424_, lean_object* v___y_425_, lean_object* v___y_426_, lean_object* v___y_427_){
_start:
{
size_t v_sz_boxed_428_; size_t v_i_boxed_429_; lean_object* v_res_430_; 
v_sz_boxed_428_ = lean_unbox_usize(v_sz_420_);
lean_dec(v_sz_420_);
v_i_boxed_429_ = lean_unbox_usize(v_i_421_);
lean_dec(v_i_421_);
v_res_430_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_RuleSet_ofEnv_spec__1(v_opts_418_, v_as_419_, v_sz_boxed_428_, v_i_boxed_429_, v_b_422_, v___y_423_, v___y_424_, v___y_425_, v___y_426_);
lean_dec(v___y_426_);
lean_dec_ref(v___y_425_);
lean_dec(v___y_424_);
lean_dec_ref(v___y_423_);
lean_dec_ref(v_as_419_);
return v_res_430_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_RuleSet_ofEnv(lean_object* v_opts_432_, lean_object* v_a_433_, lean_object* v_a_434_, lean_object* v_a_435_, lean_object* v_a_436_){
_start:
{
lean_object* v___x_438_; lean_object* v_env_439_; lean_object* v___x_440_; lean_object* v_ruleSet_441_; lean_object* v___x_442_; size_t v_sz_443_; size_t v___x_444_; lean_object* v___x_445_; 
v___x_438_ = lean_st_ref_get(v_a_436_);
v_env_439_ = lean_ctor_get(v___x_438_, 0);
lean_inc_ref(v_env_439_);
lean_dec(v___x_438_);
v___x_440_ = ((lean_object*)(lp_JunkValues_JunkValues_instInhabitedRuleSet_default___closed__2));
v_ruleSet_441_ = lean_obj_once(&lp_JunkValues_JunkValues_instInhabitedRuleSet_default___closed__3, &lp_JunkValues_JunkValues_instInhabitedRuleSet_default___closed__3_once, _init_lp_JunkValues_JunkValues_instInhabitedRuleSet_default___closed__3);
v___x_442_ = lp_JunkValues_JunkValues_declaredRules(v_env_439_);
v_sz_443_ = lean_array_size(v___x_442_);
v___x_444_ = ((size_t)0ULL);
v___x_445_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_RuleSet_ofEnv_spec__0___redArg(v___x_442_, v_sz_443_, v___x_444_, v_ruleSet_441_);
lean_dec_ref(v___x_442_);
if (lean_obj_tag(v___x_445_) == 0)
{
lean_object* v_a_446_; lean_object* v_rules_447_; lean_object* v___x_448_; lean_object* v___x_449_; lean_object* v___x_450_; lean_object* v___x_451_; lean_object* v___x_452_; lean_object* v___x_453_; lean_object* v___x_454_; lean_object* v___x_455_; lean_object* v___x_456_; size_t v_sz_457_; lean_object* v___x_458_; 
v_a_446_ = lean_ctor_get(v___x_445_, 0);
lean_inc(v_a_446_);
lean_dec_ref_known(v___x_445_, 1);
v_rules_447_ = lean_ctor_get(v_a_446_, 1);
v___x_448_ = lp_JunkValues_JunkValues_ruleProviders;
v___x_449_ = lean_st_ref_get(v___x_448_);
v___x_450_ = ((lean_object*)(lp_JunkValues_JunkValues_RuleSet_ofEnv___closed__0));
v___x_451_ = lean_array_get_size(v_rules_447_);
v___x_452_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_452_, 0, v___x_450_);
lean_ctor_set(v___x_452_, 1, v___x_451_);
v___x_453_ = lean_unsigned_to_nat(1u);
v___x_454_ = lean_mk_empty_array_with_capacity(v___x_453_);
v___x_455_ = lean_array_push(v___x_454_, v___x_452_);
v___x_456_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_456_, 0, v_a_446_);
lean_ctor_set(v___x_456_, 1, v___x_455_);
lean_ctor_set(v___x_456_, 2, v___x_440_);
v_sz_457_ = lean_array_size(v___x_449_);
v___x_458_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_RuleSet_ofEnv_spec__1(v_opts_432_, v___x_449_, v_sz_457_, v___x_444_, v___x_456_, v_a_433_, v_a_434_, v_a_435_, v_a_436_);
lean_dec(v___x_449_);
return v___x_458_;
}
else
{
lean_object* v_a_459_; lean_object* v___x_461_; uint8_t v_isShared_462_; uint8_t v_isSharedCheck_466_; 
lean_dec_ref(v_opts_432_);
v_a_459_ = lean_ctor_get(v___x_445_, 0);
v_isSharedCheck_466_ = !lean_is_exclusive(v___x_445_);
if (v_isSharedCheck_466_ == 0)
{
v___x_461_ = v___x_445_;
v_isShared_462_ = v_isSharedCheck_466_;
goto v_resetjp_460_;
}
else
{
lean_inc(v_a_459_);
lean_dec(v___x_445_);
v___x_461_ = lean_box(0);
v_isShared_462_ = v_isSharedCheck_466_;
goto v_resetjp_460_;
}
v_resetjp_460_:
{
lean_object* v___x_464_; 
if (v_isShared_462_ == 0)
{
v___x_464_ = v___x_461_;
goto v_reusejp_463_;
}
else
{
lean_object* v_reuseFailAlloc_465_; 
v_reuseFailAlloc_465_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_465_, 0, v_a_459_);
v___x_464_ = v_reuseFailAlloc_465_;
goto v_reusejp_463_;
}
v_reusejp_463_:
{
return v___x_464_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_JunkValues_JunkValues_RuleSet_ofEnv___boxed(lean_object* v_opts_467_, lean_object* v_a_468_, lean_object* v_a_469_, lean_object* v_a_470_, lean_object* v_a_471_, lean_object* v_a_472_){
_start:
{
lean_object* v_res_473_; 
v_res_473_ = lp_JunkValues_JunkValues_RuleSet_ofEnv(v_opts_467_, v_a_468_, v_a_469_, v_a_470_, v_a_471_);
lean_dec(v_a_471_);
lean_dec_ref(v_a_470_);
lean_dec(v_a_469_);
lean_dec_ref(v_a_468_);
return v_res_473_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_RuleSet_ofEnv_spec__0(lean_object* v_as_474_, size_t v_sz_475_, size_t v_i_476_, lean_object* v_b_477_, lean_object* v___y_478_, lean_object* v___y_479_, lean_object* v___y_480_, lean_object* v___y_481_){
_start:
{
lean_object* v___x_483_; 
v___x_483_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_RuleSet_ofEnv_spec__0___redArg(v_as_474_, v_sz_475_, v_i_476_, v_b_477_);
return v___x_483_;
}
}
LEAN_EXPORT lean_object* lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_RuleSet_ofEnv_spec__0___boxed(lean_object* v_as_484_, lean_object* v_sz_485_, lean_object* v_i_486_, lean_object* v_b_487_, lean_object* v___y_488_, lean_object* v___y_489_, lean_object* v___y_490_, lean_object* v___y_491_, lean_object* v___y_492_){
_start:
{
size_t v_sz_boxed_493_; size_t v_i_boxed_494_; lean_object* v_res_495_; 
v_sz_boxed_493_ = lean_unbox_usize(v_sz_485_);
lean_dec(v_sz_485_);
v_i_boxed_494_ = lean_unbox_usize(v_i_486_);
lean_dec(v_i_486_);
v_res_495_ = lp_JunkValues___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00JunkValues_RuleSet_ofEnv_spec__0(v_as_484_, v_sz_boxed_493_, v_i_boxed_494_, v_b_487_, v___y_488_, v___y_489_, v___y_490_, v___y_491_);
lean_dec(v___y_491_);
lean_dec_ref(v___y_490_);
lean_dec(v___y_489_);
lean_dec_ref(v___y_488_);
lean_dec_ref(v_as_484_);
return v_res_495_;
}
}
lean_object* runtime_initialize_Init(uint8_t builtin);
lean_object* runtime_initialize_JunkValues_JunkValues_Registry(uint8_t builtin);
lean_object* runtime_initialize_Std_Data_HashMap(uint8_t builtin);
static bool _G_runtime_initialized = false;
LEAN_EXPORT lean_object* runtime_initialize_JunkValues_JunkValues_RuleSet(uint8_t builtin) {
lean_object * res;
if (_G_runtime_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_runtime_initialized = true;
res = runtime_initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = runtime_initialize_JunkValues_JunkValues_Registry(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = runtime_initialize_Std_Data_HashMap(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
lp_JunkValues_JunkValues_instInhabitedRuleSet_default = _init_lp_JunkValues_JunkValues_instInhabitedRuleSet_default();
lean_mark_persistent(lp_JunkValues_JunkValues_instInhabitedRuleSet_default);
lp_JunkValues_JunkValues_instInhabitedRuleSet = _init_lp_JunkValues_JunkValues_instInhabitedRuleSet();
lean_mark_persistent(lp_JunkValues_JunkValues_instInhabitedRuleSet);
res = lp_JunkValues___private_JunkValues_RuleSet_0__JunkValues_initFn_00___x40_JunkValues_RuleSet_3177306610____hygCtx___hyg_2_();
if (lean_io_result_is_error(res)) return res;
lp_JunkValues_JunkValues_ruleProviders = lean_io_result_get_value(res);
lean_mark_persistent(lp_JunkValues_JunkValues_ruleProviders);
lean_dec_ref(res);
lp_JunkValues_JunkValues_instInhabitedRuleSetReport_default = _init_lp_JunkValues_JunkValues_instInhabitedRuleSetReport_default();
lean_mark_persistent(lp_JunkValues_JunkValues_instInhabitedRuleSetReport_default);
lp_JunkValues_JunkValues_instInhabitedRuleSetReport = _init_lp_JunkValues_JunkValues_instInhabitedRuleSetReport();
lean_mark_persistent(lp_JunkValues_JunkValues_instInhabitedRuleSetReport);
return lean_io_result_mk_ok(lean_box(0));
}
lean_object* runtime_initialize_Init(uint8_t builtin);
static bool _G_meta_initialized = false;
LEAN_EXPORT lean_object* meta_initialize_JunkValues_JunkValues_RuleSet(uint8_t builtin) {
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
lean_object* initialize_JunkValues_JunkValues_Registry(uint8_t builtin);
lean_object* initialize_Std_Data_HashMap(uint8_t builtin);
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_JunkValues_JunkValues_RuleSet(uint8_t builtin) {
lean_object * res;
if (_G_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_initialized = true;
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_JunkValues_JunkValues_Registry(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Std_Data_HashMap(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = runtime_initialize_JunkValues_JunkValues_RuleSet(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = meta_initialize_JunkValues_JunkValues_RuleSet(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return initialize_JunkValues_JunkValues_RuleSet(builtin);
}
#ifdef __cplusplus
}
#endif
