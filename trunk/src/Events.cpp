#include "Events.h"

// Defined here to keep everything together
#include "tlapi.h"

using namespace TLAPI;

// Global
// Setup a dummy class to setup the WndProc event
EVENT_DEF(_GLOBAL, LRESULT, WndProc, (HWND, UINT, WPARAM, LPARAM));

// EffectGroupManager
EVENT_DEF(CEffectGroupManager, void, EffectGroupManager_CreateAffix, (CEffectGroupManager*, u32, u32, u32, CList<CAffix*>&));

// MainMenu
EVENT_DEF(CMainMenu, void, MainMenu_Event, (CMainMenu*, u32, wstring, bool&));

// EffectManager
EVENT_DEF(CEffectManager, void, EffectManagerCreateEffect, (CEffect*, CEffectManager*));
EVENT_DEF(CEffectManager, void, EffectManager_AddEffectToEquipment, (CEffectManager*, CEquipment*, CEffect*));

// CharacterSaveState
EVENT_DEF(CCharacterSaveState, void, CharacterSaveState_LoadFromFile, (CCharacterSaveState*, PVOID, u32));

// Monster
EVENT_DEF(CMonster, void, MonsterProcessAI2, (CMonster*, float, bool&));
EVENT_DEF(CMonster, void, MonsterIdle, (CMonster*, float, bool&));

// Game
EVENT_DEF(CGame, void, GameCtor, (CGame*));
EVENT_DEF(CGame, void, Game_CreateUI, (CGame*));

// MouseManager
EVENT_DEF(CMouseManager, void, MouseManagerInput, (CMouseManager*, u32, u32, bool*));

// GameClient
EVENT_DEF(CGameClient, void, GameClientCtor, (CGameClient*));
EVENT_DEF(CGameClient, void, GameClientLoadMap, (CGameClient*, u32));
EVENT_DEF(CGameClient, void, GameClientProcessObjects, (CGameClient*, float, PVOID, PVOID));
EVENT_DEF(CGameClient, void, GameClient_SaveGame, (CGameClient*, u32, u32, bool*));
EVENT_DEF(CGameClient, void, GameClient_SetupUI, (CGameClient*, u32, u32));
EVENT_DEF(CGameClient, void, GameClient_CreateLevel, (CGameClient*, u32, u32, u32,
          CGameClient*, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32));
EVENT_DEF(CGameClient, void, GameClient_LoadLevel, (CGameClient*));
EVENT_DEF(CGameClient, void, GameClientProcessTitleScreen, (CGameClient*, float, PVOID, float, u32));

// Equipment
EVENT_DEF(CEquipment, void, EquipmentCtor, (CEquipment*));
EVENT_DEF(CEquipment, void, EquipmentInitialize, (CEquipment*, CItemSaveState*));
EVENT_DEF(CEquipment, void, EquipmentEnchant, (u32, CEquipment*, u32, u32, u32));
EVENT_DEF(CEquipment, void, Equipment_AddMagicModifier, (CEquipment*, u32, u32));
EVENT_DEF(CEquipment, void, Equipment_AddAffix, (CEquipment*, CAffix*, u32, CEquipment*, float));

// ResourceManager
EVENT_DEF(CResourceManager, void, ResourceManagerInitializePlayer,      (CResourceManager*, u32, u32));
EVENT_DEF(CResourceManager, void, ResourceManagerCreatePlayer,          (CResourceManager*, u32, u32));
EVENT_DEF(CResourceManager, void, ResourceManagerCreateMonster,         (CMonster*, CResourceManager*, u64, u32, bool, bool&));
EVENT_DEF(CResourceManager, void, ResourceManagerCreateCharacterByName, (CCharacter*, CResourceManager*, const wchar_t*, const wchar_t*, u32, u32));
EVENT_DEF(CResourceManager, void, ResourceManagerCreateBaseUnit,        (CResourceManager*, u64, u32, u32, u32));
EVENT_DEF(CResourceManager, void, ResourceManagerCreateEquipment,       (CEquipment*, CResourceManager*, u64, u32, u32, u32));

// Level
EVENT_DEF(CLevel, void, LevelCharacterInitialize, (CLevel*, CCharacter*, Vector3*, u32, bool&));
EVENT_DEF(CLevel, void, LevelCreateAstarPathfinding, (CAstarPathfinder*, float unk0, float unk1, u32 unk2, u32 unk3, PVOID unk4, PVOID unk5, float unk6));
EVENT_DEF(CLevel, void, LevelDropEquipment, (CLevel*, CEquipment*, Vector3 &, bool));

// Inventory
EVENT_DEF(CInventory, void, InventoryAddEquipment, (CInventory*, CEquipment*, u32, u32));
EVENT_DEF(CInventory, void, InventoryRemoveEquipment, (CInventory*, CEquipment*));

// Character
EVENT_DEF(CCharacter, void, CharacterCtor, (CCharacter*));
EVENT_DEF(CCharacter, void, CharacterSetAlignment, (CCharacter*, u32));
EVENT_DEF(CCharacter, void, CharacterSetDestination, (CCharacter*, CLevel*, float, float));
EVENT_DEF(CCharacter, void, CharacterSetAction, (CCharacter*, u32, bool&));
EVENT_DEF(CCharacter, void, CharacterSetTarget, (CCharacter*, u32, bool&));
EVENT_DEF(CCharacter, void, CharacterUseSkill, (CCharacter*, u64, bool&));
EVENT_DEF(CCharacter, void, CharacterAddMinion, (CCharacter*, CCharacter*));
EVENT_DEF(CCharacter, void, CharacterStrike, (CCharacter*, CLevel*, CCharacter*, PVOID, u32, float, float, u32));
EVENT_DEF(CCharacter, void, CharacterPickupEquipment, (CCharacter*, CEquipment*, CLevel*, bool&));
EVENT_DEF(CCharacter, void, CharacterAttack, (CCharacter*, bool&));

// Player
EVENT_DEF(CPlayer, void, PlayerUseSkill, (u32 retVal, CPlayer* player, u64 skill));

// GenericModel
EVENT_DEF(CGenericModel, void, GenericModelGetPosition, (CGenericModel*, Vector3, u32));

// Layout
EVENT_DEF(CLayout, void, LayoutSetPosition, (CLayout*, const Vector3));
