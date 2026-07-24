// ARM64 stub for hlsteam — no Steam SDK available on ARM64.
// All query functions return failure values; init/is_user_logged_in return true.

#define HL_NAME(n) steam_##n
#include <hl.h>

typedef vbyte *vuid;

#define _UID     _BYTES
#define _CRESULT _ABSTRACT(steam_call_result)
#define _CALLB(T) _FUN(_VOID, T _BOOL)

//-----------------------------------------------------------------------------------------------------------
// common.cpp
//-----------------------------------------------------------------------------------------------------------

HL_PRIM bool HL_NAME(init)(vclosure *onEvent, vclosure *onGlobalEvent)
{
    (void)onEvent;
    (void)onGlobalEvent;
    return true;
}

HL_PRIM void HL_NAME(shutdown)()
{
}

HL_PRIM void HL_NAME(run_callbacks)()
{
}

HL_PRIM bool HL_NAME(is_user_logged_in)()
{
    return true;
}

HL_PRIM vuid HL_NAME(get_steam_id)()
{
    return NULL;
}

HL_PRIM bool HL_NAME(is_overlay_enabled)()
{
    return false;
}

HL_PRIM bool HL_NAME(is_steam_running)()
{
    return false;
}

HL_PRIM vbyte *HL_NAME(get_current_game_language)()
{
    return NULL;
}

HL_PRIM vbyte *HL_NAME(get_auth_ticket)(int *size, int *authTicket)
{
    *size = 0;
    *authTicket = 0;
    return NULL;
}

HL_PRIM bool HL_NAME(is_dlc_installed)(int appid)
{
    (void)appid;
    return false;
}

HL_PRIM bool HL_NAME(open_overlay)(vbyte *url)
{
    (void)url;
    return false;
}

DEFINE_PRIM(_BOOL, init, _FUN(_VOID, _I32 _BOOL _BYTES) _FUN(_VOID, _I32 _DYN));
DEFINE_PRIM(_VOID, shutdown, _NO_ARG);
DEFINE_PRIM(_VOID, run_callbacks, _NO_ARG);
DEFINE_PRIM(_BOOL, is_user_logged_in, _NO_ARG);
DEFINE_PRIM(_UID, get_steam_id, _NO_ARG);
DEFINE_PRIM(_BOOL, is_overlay_enabled, _NO_ARG);
DEFINE_PRIM(_BOOL, is_steam_running, _NO_ARG);
DEFINE_PRIM(_BYTES, get_current_game_language, _NO_ARG);
DEFINE_PRIM(_BYTES, get_auth_ticket, _REF(_I32) _REF(_I32));
DEFINE_PRIM(_BOOL, is_dlc_installed, _I32);
DEFINE_PRIM(_BOOL, open_overlay, _BYTES);

//-----------------------------------------------------------------------------------------------------------
// cloud.cpp
//-----------------------------------------------------------------------------------------------------------

HL_PRIM vbyte *HL_NAME(file_read)(vbyte *fileName, int *len)
{
    (void)fileName;
    *len = 0;
    return NULL;
}

HL_PRIM bool HL_NAME(file_write)(vbyte *fileName, vbyte *bytes, int length)
{
    (void)fileName;
    (void)bytes;
    (void)length;
    return false;
}

HL_PRIM bool HL_NAME(file_exists)(vbyte *fileName)
{
    (void)fileName;
    return false;
}

HL_PRIM bool HL_NAME(file_delete)(vbyte *fileName)
{
    (void)fileName;
    return false;
}

HL_PRIM bool HL_NAME(is_cloud_enabled_for_app)()
{
    return false;
}

HL_PRIM bool HL_NAME(is_cloud_enabled_for_account)()
{
    return false;
}

HL_PRIM void HL_NAME(set_cloud_enabled_for_app)(bool enabled)
{
    (void)enabled;
}

DEFINE_PRIM(_BYTES, file_read, _BYTES _REF(_I32));
DEFINE_PRIM(_BOOL, file_write, _BYTES _BYTES _I32);
DEFINE_PRIM(_BOOL, file_exists, _BYTES);
DEFINE_PRIM(_BOOL, file_delete, _BYTES);
DEFINE_PRIM(_BOOL, is_cloud_enabled_for_app, _NO_ARG);
DEFINE_PRIM(_BOOL, is_cloud_enabled_for_account, _NO_ARG);
DEFINE_PRIM(_VOID, set_cloud_enabled_for_app, _BOOL);

//-----------------------------------------------------------------------------------------------------------
// stats.cpp
//-----------------------------------------------------------------------------------------------------------

HL_PRIM bool HL_NAME(request_stats)()
{
    return false;
}

HL_PRIM int HL_NAME(get_stat_int)(vbyte *name)
{
    (void)name;
    return 0;
}

HL_PRIM bool HL_NAME(store_stats)()
{
    return false;
}

HL_PRIM bool HL_NAME(set_achievement)(vbyte *name)
{
    (void)name;
    return false;
}

HL_PRIM bool HL_NAME(get_achievement)(vbyte *name)
{
    (void)name;
    return false;
}

HL_PRIM bool HL_NAME(find_leaderboard)(vbyte *name)
{
    (void)name;
    return false;
}

HL_PRIM bool HL_NAME(upload_score)(vbyte *name, int score, int detail)
{
    (void)name;
    (void)score;
    (void)detail;
    return false;
}

HL_PRIM bool HL_NAME(download_scores)(vbyte *name, int numBefore, int numAfter)
{
    (void)name;
    (void)numBefore;
    (void)numAfter;
    return false;
}

HL_PRIM bool HL_NAME(request_global_stats)()
{
    return false;
}

DEFINE_PRIM(_BOOL, request_stats, _NO_ARG);
DEFINE_PRIM(_I32, get_stat_int, _BYTES);
DEFINE_PRIM(_BOOL, store_stats, _NO_ARG);
DEFINE_PRIM(_BOOL, set_achievement, _BYTES);
DEFINE_PRIM(_BOOL, get_achievement, _BYTES);
DEFINE_PRIM(_BOOL, find_leaderboard, _BYTES);
DEFINE_PRIM(_BOOL, upload_score, _BYTES _I32 _I32);
DEFINE_PRIM(_BOOL, download_scores, _BYTES _I32 _I32);
DEFINE_PRIM(_BOOL, request_global_stats, _NO_ARG);

//-----------------------------------------------------------------------------------------------------------
// friends.cpp
//-----------------------------------------------------------------------------------------------------------

HL_PRIM vbyte *HL_NAME(get_user_name)(vuid uid)
{
    (void)uid;
    return NULL;
}

HL_PRIM varray *HL_NAME(get_friends)(int flags)
{
    (void)flags;
    return NULL;
}

HL_PRIM void HL_NAME(activate_overlay_store)(int appid, int flag)
{
    (void)appid;
    (void)flag;
}

DEFINE_PRIM(_BYTES, get_user_name, _UID);
DEFINE_PRIM(_ARR, get_friends, _I32);
DEFINE_PRIM(_VOID, activate_overlay_store, _I32 _I32);

//-----------------------------------------------------------------------------------------------------------
// ugc.cpp
//-----------------------------------------------------------------------------------------------------------

HL_PRIM varray *HL_NAME(get_subscribed_items)()
{
    return NULL;
}

HL_PRIM bool HL_NAME(download_item)(vuid publishedFileID, bool highPriority)
{
    (void)publishedFileID;
    (void)highPriority;
    return false;
}

HL_PRIM vdynamic *HL_NAME(get_item_install_info)(vuid publishedFileID)
{
    (void)publishedFileID;
    return NULL;
}

HL_PRIM void *HL_NAME(subscribe_item)(vuid publishedFileID, vclosure *closure)
{
    (void)publishedFileID;
    (void)closure;
    return NULL;
}

HL_PRIM int HL_NAME(get_item_state)(vuid publishedFileID)
{
    (void)publishedFileID;
    return 0;
}

HL_PRIM vuid HL_NAME(ugc_query_create_details_request)(varray *fileIDs)
{
    (void)fileIDs;
    return NULL;
}

HL_PRIM void *HL_NAME(ugc_query_send_request)(vuid cHandle, vclosure *closure)
{
    (void)cHandle;
    (void)closure;
    return NULL;
}

HL_PRIM bool HL_NAME(ugc_query_release_request)(vuid cHandle)
{
    (void)cHandle;
    return false;
}

HL_PRIM vdynamic *HL_NAME(ugc_query_get_result)(vuid sHandle, int iIndex)
{
    (void)sHandle;
    (void)iIndex;
    return NULL;
}

HL_PRIM varray *HL_NAME(ugc_query_get_children)(vuid cHandle, int iIndex, int maxChildren)
{
    (void)cHandle;
    (void)iIndex;
    (void)maxChildren;
    return NULL;
}

HL_PRIM vbyte *HL_NAME(ugc_query_get_metadata)(vuid sHandle, int iIndex)
{
    (void)sHandle;
    (void)iIndex;
    return NULL;
}

HL_PRIM varray *HL_NAME(ugc_query_get_key_value_tags)(vuid cHandle, int iIndex, int maxValueLength)
{
    (void)cHandle;
    (void)iIndex;
    (void)maxValueLength;
    return NULL;
}

HL_PRIM bool HL_NAME(ugc_query_set_return_key_value_tags)(vuid handle, bool returnKeyValueTags)
{
    (void)handle;
    (void)returnKeyValueTags;
    return false;
}

HL_PRIM bool HL_NAME(ugc_query_set_return_children)(vuid handle, bool returnChildren)
{
    (void)handle;
    (void)returnChildren;
    return false;
}

HL_PRIM void *HL_NAME(ugc_item_create)(int appId, vclosure *closure)
{
    (void)appId;
    (void)closure;
    return NULL;
}

HL_PRIM vuid HL_NAME(ugc_item_start_update)(int id, vuid itemID)
{
    (void)id;
    (void)itemID;
    return NULL;
}

HL_PRIM void *HL_NAME(ugc_item_submit_update)(vuid updateHandle, vbyte *changeNotes, vclosure *closure)
{
    (void)updateHandle;
    (void)changeNotes;
    (void)closure;
    return NULL;
}

HL_PRIM bool HL_NAME(ugc_item_set_title)(vuid updateHandle, vbyte *title)
{
    (void)updateHandle;
    (void)title;
    return false;
}

HL_PRIM bool HL_NAME(ugc_item_set_metadata)(vuid updateHandle, vbyte *metadata)
{
    (void)updateHandle;
    (void)metadata;
    return false;
}

HL_PRIM bool HL_NAME(ugc_item_set_tags)(vuid updateHandle, varray *tags)
{
    (void)updateHandle;
    (void)tags;
    return false;
}

HL_PRIM bool HL_NAME(ugc_item_add_key_value_tag)(vuid updateHandle, vbyte *keyStr, vbyte *valueStr)
{
    (void)updateHandle;
    (void)keyStr;
    (void)valueStr;
    return false;
}

HL_PRIM bool HL_NAME(ugc_item_remove_key_value_tags)(vuid updateHandle, vbyte *keyStr)
{
    (void)updateHandle;
    (void)keyStr;
    return false;
}

HL_PRIM bool HL_NAME(ugc_item_set_visibility)(vuid updateHandle, int visibility)
{
    (void)updateHandle;
    (void)visibility;
    return false;
}

HL_PRIM bool HL_NAME(ugc_item_set_content)(vuid updateHandle, vbyte *path)
{
    (void)updateHandle;
    (void)path;
    return false;
}

HL_PRIM bool HL_NAME(ugc_item_set_preview_image)(vuid updateHandle, vbyte *path)
{
    (void)updateHandle;
    (void)path;
    return false;
}

DEFINE_PRIM(_ARR, get_subscribed_items, _NO_ARG);
DEFINE_PRIM(_BOOL, download_item, _UID _BOOL);
DEFINE_PRIM(_DYN, get_item_install_info, _UID);
DEFINE_PRIM(_CRESULT, subscribe_item, _UID _CALLB(_UID));
DEFINE_PRIM(_I32, get_item_state, _UID);

DEFINE_PRIM(_UID, ugc_query_create_details_request, _ARR);
DEFINE_PRIM(_CRESULT, ugc_query_send_request, _UID _CALLB(_DYN));
DEFINE_PRIM(_BOOL, ugc_query_release_request, _UID);
DEFINE_PRIM(_DYN, ugc_query_get_result, _UID _I32);
DEFINE_PRIM(_ARR, ugc_query_get_children, _UID _I32 _I32);
DEFINE_PRIM(_BYTES, ugc_query_get_metadata, _UID _I32);
DEFINE_PRIM(_ARR, ugc_query_get_key_value_tags, _UID _I32 _I32);
DEFINE_PRIM(_BOOL, ugc_query_set_return_key_value_tags, _UID _BOOL);
DEFINE_PRIM(_BOOL, ugc_query_set_return_children, _UID _BOOL);

DEFINE_PRIM(_CRESULT, ugc_item_create, _I32 _CALLB(_DYN));
DEFINE_PRIM(_UID, ugc_item_start_update, _I32 _UID);
DEFINE_PRIM(_CRESULT, ugc_item_submit_update, _UID _BYTES _CALLB(_BOOL));
DEFINE_PRIM(_BOOL, ugc_item_set_title, _UID _BYTES);
DEFINE_PRIM(_BOOL, ugc_item_set_metadata, _UID _BYTES);
DEFINE_PRIM(_BOOL, ugc_item_set_tags, _UID _ARR);
DEFINE_PRIM(_BOOL, ugc_item_add_key_value_tag, _UID _BYTES _BYTES);
DEFINE_PRIM(_BOOL, ugc_item_remove_key_value_tags, _UID _BYTES);
DEFINE_PRIM(_BOOL, ugc_item_set_visibility, _UID _I32);
DEFINE_PRIM(_BOOL, ugc_item_set_content, _UID _BYTES);
DEFINE_PRIM(_BOOL, ugc_item_set_preview_image, _UID _BYTES);

//-----------------------------------------------------------------------------------------------------------
// controller.cpp
//-----------------------------------------------------------------------------------------------------------

HL_PRIM bool HL_NAME(init_controllers)()
{
    return false;
}

HL_PRIM vbyte *HL_NAME(get_entered_gamepad_text_input)()
{
    return NULL;
}

DEFINE_PRIM(_BOOL, init_controllers, _NO_ARG);
DEFINE_PRIM(_BYTES, get_entered_gamepad_text_input, _NO_ARG);
