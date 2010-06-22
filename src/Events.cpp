
// Defined here to keep everything together

#include "CGameClient.h"

using namespace TLAPI;

vector<void (__cdecl *)(CGameClient*, u32)> CGameClient::m_Callback_LoadMap_pre;
vector<void (__cdecl *)(CGameClient*, u32)> CGameClient::m_Callback_LoadMap_post;
