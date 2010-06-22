#include "Events.h"

// Defined here to keep everything together
#include "CGameClient.h"

using namespace TLAPI;

EVENT_DEF(CGameClient, void, __cdecl, LoadMap, (CGameClient*, u32));
