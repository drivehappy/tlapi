#include "Events.h"

// Defined here to keep everything together
#include "CGameClient.h"
#include "CPlayer.h"

using namespace TLAPI;

EVENT_DEF(CGameClient, void, __cdecl, GameClientLoadMap, (CGameClient*, u32));
EVENT_DEF(CResourceManager, void, __cdecl, ResourceManagerInitializePlayer, (CResourceManager*, u32, u32));
EVENT_DEF(CEquipment, void, __cdecl, EquipmentInitialize, (CEquipment*, CItemSaveState*));
EVENT_DEF(CResourceManager, void, __cdecl, ResouceManagerCreateCharacter, (CResourceManager*, u64, u32, bool));
