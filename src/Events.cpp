#include "Events.h"

// Defined here to keep everything together
#include "tlapi.h"

using namespace TLAPI;

// Global
// Setup a dummy class to setup the WndProc event
EVENT_DEF(_GLOBAL, LRESULT, WndProc, (HWND, UINT, WPARAM, LPARAM));
EVENT_DEF(_GLOBAL, void, SetSeedValue0, (u32));
EVENT_DEF(_GLOBAL, void, SetSeedValue2, (u32));

// EffectGroupManager
EVENT_DEF(CEffectGroupManager, void, EffectGroupManager_CreateAffix, (CEffectGroupManager*, u32, u32, u32, CList<CAffix*>&));

// MainMenu
EVENT_DEF(CMainMenu, void, MainMenu_Event, (CMainMenu*, u32, wstring, bool&));

// SkillManager
EVENT_DEF(CSkillManager, void, SkillManagerAddSkill, (CSkillManager*, CSkill*, u32, u32, bool&));

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

// GameUI
EVENT_DEF(CGameUI, void, GameUI_WindowResized, (CGameUI*, bool&));
EVENT_DEF(CGameUI, void, GameUI_TriggerPause, (CGameUI*, bool&));
EVENT_DEF(CGameUI, void, GameUI_HandleKeyboardInput, (CGameUI*, u32, u32, u32, bool&));

// KeyManager
EVENT_DEF(CKeyManager, void, KeyManager_InjectKey, (CKeyManager*, u32, u32, bool&));

// MouseManager
EVENT_DEF(CMouseManager, void, MouseManagerInput, (CMouseManager*, u32, u32, bool&));

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
EVENT_DEF(CGameClient, void, GameClientGamePaused, (bool, CGameClient*, bool&));
EVENT_DEF(CGameClient, void, GameClient_ChangeLevel, (CGameClient*, wstring, u32, u32, u32, wstring, u32, bool&));

// Equipment
EVENT_DEF(CEquipment, void, EquipmentDtor, (CEquipment*));
EVENT_DEF(CEquipment, void, EquipmentInitialize, (CEquipment*, CItemSaveState*));
EVENT_DEF(CEquipment, void, EquipmentEnchant, (u32, CEquipment*, u32, u32, u32));
EVENT_DEF(CEquipment, void, Equipment_AddMagicModifier, (CEquipment*, u32, u32));
EVENT_DEF(CEquipment, void, Equipment_AddAffix, (CEquipment*, CAffix*, u32, CEquipment*, float));
EVENT_DEF(CEquipment, void, EquipmentAddStackCount, (CEquipment*, u32));
EVENT_DEF(CEquipment, void, Equipment_AddGem, (CEquipment*, CEquipment*, bool&));
EVENT_DEF(CEquipment, void, EquipmentIdentify, (CEquipment*, CPlayer*, CEquipment*, bool&));

// Enchant Menu
EVENT_DEF(CEnchantMenu, void, EnchantMenu_EnchantItem, (CEnchantMenu*));

// ResourceManager
EVENT_DEF(CResourceManager, void, ResourceManagerInitializePlayer,      (CResourceManager*, u32, u32));
EVENT_DEF(CResourceManager, void, ResourceManagerCreatePlayer,          (CPlayer*, CResourceManager*, wchar_t*, u32, bool&));
EVENT_DEF(CResourceManager, void, ResourceManagerCreateMonster,         (CMonster*, CResourceManager*, u64, u32, bool, bool&));
EVENT_DEF(CResourceManager, void, ResourceManagerCreateCharacterByName, (CCharacter*, CResourceManager*, const wchar_t*, const wchar_t*, u32, u32));
EVENT_DEF(CResourceManager, void, ResourceManagerCreateBaseUnit,        (CResourceManager*, u64, u32, u32, u32));
EVENT_DEF(CResourceManager, void, ResourceManagerCreateItem,            (CItem*, CResourceManager*, u64, u32, u32, u32));

// Level
EVENT_DEF(CLevel, void, LevelCharacterInitialize, (CLevel*, CCharacter*, Vector3*, u32, bool&));
EVENT_DEF(CLevel, void, LevelCreateAstarPathfinding, (CAstarPathfinder*, float unk0, float unk1, u32 unk2, u32 unk3, PVOID unk4, PVOID unk5, float unk6));
EVENT_DEF(CLevel, void, LevelDropItem, (CLevel*, CItem*, Vector3 &, bool));
EVENT_DEF(CLevel, void, Level_CharacterKilledCharacter, (CLevel*, CCharacter*, CCharacter*, Vector3*, u32, bool&));
EVENT_DEF(CLevel, void, Level_Dtor, (CLevel*, u32, bool&));
EVENT_DEF(CLevel, void, Level_Ctor, (wstring name, CSettings*, CGameClient*, CResourceManager*, PVOID OctreeSM, CSoundManager*, u32, u32, bool&));

// Inventory
EVENT_DEF(CInventory, void, InventoryAddEquipment, (CInventory*, CEquipment*, u32, u32));
EVENT_DEF(CInventory, void, InventoryRemoveEquipment, (CInventory*, CEquipment*));

// Character
EVENT_DEF(CCharacter, void, CharacterDtor, (CCharacter*));
EVENT_DEF(CCharacter, void, CharacterSetAlignment, (CCharacter*, u32, bool& calloriginal));
EVENT_DEF(CCharacter, void, CharacterSetDestination, (CCharacter*, CLevel*, float, float));
EVENT_DEF(CCharacter, void, CharacterSetAction, (CCharacter*, u32, bool&));
EVENT_DEF(CCharacter, void, CharacterSetTarget, (CCharacter*, u32, bool&));
EVENT_DEF(CCharacter, void, CharacterUseSkill, (CCharacter*, u64, bool&));
EVENT_DEF(CCharacter, void, CharacterAddMinion, (CCharacter*, CCharacter*));
EVENT_DEF(CCharacter, void, CharacterStrike, (CCharacter*, CLevel*, CCharacter*, PVOID, u32, float, float, u32));
EVENT_DEF(CCharacter, void, CharacterPickupEquipment, (CCharacter*, CEquipment*, CLevel*, bool&));
EVENT_DEF(CCharacter, void, CharacterAttack, (CCharacter*, bool&));
EVENT_DEF(CCharacter, void, Character_Update, (CCharacter*, PVOID, float*, float, bool&));
EVENT_DEF(CCharacter, void, Character_SetOrientation, (CCharacter*, Vector3*, float, bool&));
EVENT_DEF(CCharacter, void, CharacterSetupSkills, (CCharacter*, CDataGroup*, u32, bool&));
EVENT_DEF(CCharacter, void, CharacterAddSkill, (CCharacter*, wstring*, u32, bool&));
EVENT_DEF(CCharacter, void, CharacterUpdateHealth, (CCharacter*, float));
EVENT_DEF(CCharacter, void, PlayerResurrect, (CCharacter*, bool&));

// ItemGold
EVENT_DEF(CItemGold, void, ItemGold_Ctor, (CItemGold*, PVOID, CResourceManager*, u32, bool&));

// TriggerUnit
EVENT_DEF(CTriggerUnit, void, TriggerUnitTriggered, (CTriggerUnit*, CPlayer*, bool&));
EVENT_DEF(CTriggerUnit, void, TriggerUnit_Ctor, (CTriggerUnit*, CLayout*, bool&));

// Breakable
EVENT_DEF(CBreakable, void, BreakableTriggered, (CBreakable*, CPlayer*, bool&));

// GenericModel
EVENT_DEF(CGenericModel, void, GenericModelGetPosition, (CGenericModel*, Vector3, u32));

// Layout
EVENT_DEF(CLayout, void, LayoutSetPosition, (CLayout*, const Vector3));
