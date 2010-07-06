#include "Events.h"

// Defined here to keep everything together
#include "CGameClient.h"
#include "CPlayer.h"

using namespace TLAPI;

EVENT_DEF(CGameClient, void, GameClientLoadMap, (CGameClient*, u32));
EVENT_DEF(CResourceManager, void, ResourceManagerInitializePlayer, (CResourceManager*, u32, u32));
EVENT_DEF(CEquipment, void, EquipmentInitialize, (CEquipment*, CItemSaveState*));

// ResourceManager
EVENT_DEF(CResourceManager, void, ResouceManagerCreateCharacter, (CResourceManager*, u64, u32, bool));
EVENT_DEF(CResourceManager, void, ResourceManagerCreateCharacterByName, (CResourceManager*, const wchar_t*, const wchar_t*, u32, u32));

// Level
EVENT_DEF(CLevel, void, LevelCharacterInitialize, (CLevel*, CCharacter*, Vector3*, u32));

// Character
EVENT_DEF(CCharacter, void, CharacterSetAlignment, (CCharacter*, u32));
EVENT_DEF(CCharacter, void, CharacterSetDestination, (CCharacter*, CLevel*, float, float));

