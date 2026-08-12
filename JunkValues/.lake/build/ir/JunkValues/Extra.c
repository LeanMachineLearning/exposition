// Lean compiler output
// Module: JunkValues.Extra
// Imports: public import Init public meta import Init public import JunkValues.Extra.Entry public import JunkValues.Extra.Catalogue public import JunkValues.Extra.Arithmetic public import JunkValues.Extra.Discovery
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
lean_object* runtime_initialize_Init(uint8_t builtin);
lean_object* runtime_initialize_JunkValues_JunkValues_Extra_Entry(uint8_t builtin);
lean_object* runtime_initialize_JunkValues_JunkValues_Extra_Catalogue(uint8_t builtin);
lean_object* runtime_initialize_JunkValues_JunkValues_Extra_Arithmetic(uint8_t builtin);
lean_object* runtime_initialize_JunkValues_JunkValues_Extra_Discovery(uint8_t builtin);
static bool _G_runtime_initialized = false;
LEAN_EXPORT lean_object* runtime_initialize_JunkValues_JunkValues_Extra(uint8_t builtin) {
lean_object * res;
if (_G_runtime_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_runtime_initialized = true;
res = runtime_initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = runtime_initialize_JunkValues_JunkValues_Extra_Entry(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = runtime_initialize_JunkValues_JunkValues_Extra_Catalogue(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = runtime_initialize_JunkValues_JunkValues_Extra_Arithmetic(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = runtime_initialize_JunkValues_JunkValues_Extra_Discovery(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return lean_io_result_mk_ok(lean_box(0));
}
lean_object* runtime_initialize_Init(uint8_t builtin);
static bool _G_meta_initialized = false;
LEAN_EXPORT lean_object* meta_initialize_JunkValues_JunkValues_Extra(uint8_t builtin) {
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
lean_object* initialize_JunkValues_JunkValues_Extra_Catalogue(uint8_t builtin);
lean_object* initialize_JunkValues_JunkValues_Extra_Arithmetic(uint8_t builtin);
lean_object* initialize_JunkValues_JunkValues_Extra_Discovery(uint8_t builtin);
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_JunkValues_JunkValues_Extra(uint8_t builtin) {
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
res = initialize_JunkValues_JunkValues_Extra_Catalogue(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_JunkValues_JunkValues_Extra_Arithmetic(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_JunkValues_JunkValues_Extra_Discovery(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = runtime_initialize_JunkValues_JunkValues_Extra(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = meta_initialize_JunkValues_JunkValues_Extra(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return initialize_JunkValues_JunkValues_Extra(builtin);
}
#ifdef __cplusplus
}
#endif
