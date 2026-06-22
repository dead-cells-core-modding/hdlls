#define HL_NAME(n) gog_##n
#include <hl.h>

typedef vbyte* vuid;

typedef union {
	vbyte b[8];
	uint64 v;
} vuint64;

vuid hl_of_uint64(uint64 uid) {
	vuint64 data;
	data.v = uid;
	return (vuid)hl_copy_bytes(data.b, 8);
}

#define _UID		_BYTES
#define hlt_uid		hlt_bytes

HL_PRIM void HL_NAME(init)(char* id, char* secret, vclosure* eventHandler) {

}

HL_PRIM void HL_NAME(process_data)() {

}

HL_PRIM bool HL_NAME(signed_in)() {
	return 1;
}

HL_PRIM bool HL_NAME(is_logged_on)() {
	return 1;
}

HL_PRIM vuid HL_NAME(get_galaxy_id)() {
	return hl_of_uint64(0);
}

HL_PRIM vbyte* HL_NAME(get_persona_name)() {
	return (vbyte*)"Dummy";
}

HL_PRIM vbyte* HL_NAME(get_current_game_language)() {
	return NULL;
}

HL_PRIM void HL_NAME(request_encrypted_app_ticket)(vbyte* data, int size) {

}

HL_PRIM int HL_NAME(get_overlay_state)() {

}

HL_PRIM bool HL_NAME(is_overlay_visible)() {
	return 0;
}

HL_PRIM void HL_NAME(show_overlay_with_web_page)(char* url) {

}

HL_PRIM bool HL_NAME(is_dlc_installed)(vbyte* productId) {
	return 1;
}

DEFINE_PRIM(_VOID, init, _BYTES _BYTES _FUN(_VOID, _I32 _DYN));
DEFINE_PRIM(_VOID, process_data, _NO_ARG);
DEFINE_PRIM(_BOOL, signed_in, _NO_ARG);
DEFINE_PRIM(_BOOL, is_logged_on, _NO_ARG);
DEFINE_PRIM(_UID, get_galaxy_id, _NO_ARG);
DEFINE_PRIM(_BYTES, get_persona_name, _NO_ARG);
DEFINE_PRIM(_BYTES, get_current_game_language, _NO_ARG);
DEFINE_PRIM(_VOID, request_encrypted_app_ticket, _BYTES _I32);
DEFINE_PRIM(_BOOL, is_overlay_visible, _NO_ARG);
DEFINE_PRIM(_I32, get_overlay_state, _NO_ARG);
DEFINE_PRIM(_VOID, show_overlay_with_web_page, _BYTES);
DEFINE_PRIM(_BOOL, is_dlc_installed, _BYTES);

// Achievements

HL_PRIM void HL_NAME(set_achievement)(char* name) {
}

HL_PRIM bool HL_NAME(has_achievement)(char* name) {
	return 1;
}

HL_PRIM void HL_NAME(clear_achievement)(char* name) {

}

HL_PRIM void HL_NAME(set_stat_int)(char* name, int v) {

}

HL_PRIM void HL_NAME(set_stat_float)(char* name, float v) {

}

HL_PRIM void HL_NAME(request_stats_and_achievements)() {

}

HL_PRIM void HL_NAME(store_stats_and_achievements)() {

}


DEFINE_PRIM(_VOID, set_achievement, _BYTES);
DEFINE_PRIM(_BOOL, has_achievement, _BYTES);
DEFINE_PRIM(_VOID, clear_achievement, _BYTES);
DEFINE_PRIM(_VOID, set_stat_int, _BYTES _I32);
DEFINE_PRIM(_VOID, set_stat_float, _BYTES _F32);
DEFINE_PRIM(_VOID, store_stats_and_achievements, _NO_ARG);
DEFINE_PRIM(_VOID, request_stats_and_achievements, _NO_ARG);

