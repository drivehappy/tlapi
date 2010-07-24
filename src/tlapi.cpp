#include "tlapi.h"
#include "Hook.h"
#include "Offsets.h"
#include "Events.h"
#include "Globals.h"

using namespace TLAPI;

u32 exeBaseReal = (u32)GetModuleHandle("Torchlight.exe");

// Define the offset locations
TLFUNCPTR(ResouceManagerCreateCharacter,          CCharacter*,  __thiscall, (CResourceManager*, u64, u32, bool),                            0x5FBB70);     // CResourceManager, u64 guid, u32 level, bool noitems?
TLFUNCPTR(LevelCharacterInitialize,               CCharacter*,  __thiscall, (CLevel*, CCharacter*, Vector3*, u32),                          0x4F2EF0);     // CLevel, CMonster, vector3*, u32 unk
TLFUNCPTR(ResourceManagerCreateCharacterByName,   CCharacter*,  __thiscall, (CResourceManager*, const wchar_t*, const wchar_t*, u32, u32),  0x5FC600);     // CResourceManager, ...
TLFUNCPTR(CharacterSetAlignment,                  void,         __thiscall, (CCharacter*, u32),                                             0x4839E0);     // CMonster, u32 alignment (2 = badguy, 0 = goodguy)
TLFUNCPTR(CharacterSetDestination,                void,         __thiscall, (CCharacter*, CLevel*, float, float),                           0x492AD0);     // CPlayer, CLevel, u32 x, u32 y
TLFUNCPTR(GenericModelGetPosition,                PVOID,        __thiscall, (CGenericModel*, Vector3, u32),                                 0x50E3F0);     // CGenericModel, vector3 &, unk
TLFUNCPTR(CharacterSetAction,                     PVOID,        __thiscall, (CCharacter*, u32),                                             0x489E50);     // CMonster, u32 action
TLFUNCPTR(PlayerUseSkill,                         PVOID,        __thiscall, (CPlayer*, u64),                                                0x494E50);     // CPlayer, u64 skill
TLFUNCPTR(LayoutSetPosition,                      void,         __thiscall, (CLayout*, const Vector3),                                      0x50E450);     // CLayout, 
TLFUNCPTR(CharacterAddMinion,                     void,         __thiscall, (CCharacter*, CCharacter*),                                     0x4A9B20);     // CMonster, CMonster

TLFUNCPTR(ResourceManagerCreateSomething,         PVOID,        __thiscall, (CResourceManager*, u64, u32, u32, u32),                        0x5FC170);     // CResourceManager

TLFUNCPTR(CharacterSetAttack,                     PVOID,        __thiscall, (CCharacter*, PVOID),                                           0x492970);     // CMonster, NULL


// !!! CHECK MY ARG COUNT, MAYBE +1/-1
TLFUNCPTR(CharacterStrike,                        PVOID,    __thiscall, (CCharacter*, CLevel*, CCharacter*, PVOID, u32, float, float, u32), 0x4A0190);  // 1.15  CMonster src, CLevel, CMonster dst, NULL, 0, 1.0, 1.0, 7

TLFUNCPTR(MonsterProcessAI,                       PVOID,    __thiscall, (CMonster*, float, PVOID),                                          0x4D36F0);     // 1.15  CMonster, float unk (0.005), CLevel
TLFUNCPTR(PlayerSetAnimation,                     PVOID,    __thiscall, (CPlayer*, u32, bool, float, float, u32),                           0x4841F0);     // 1.15  CPlayer, u32 unk, bool unk, float unk (0.2), float unk (1), u32(

TLFUNCPTR(PlayerDoAttack,                         PVOID,    __thiscall, (CPlayer*),                                                         0x48FBD0);     // 1.15  CPlayer

TLFUNCPTR(EquipmentInitialize,                    PVOID,    __thiscall, (CEquipment*, CItemSaveState*),                                     0x4BE250);     // 1.15  CEquipment, CItemSaveState
TLFUNCPTR(LevelDropEquipment,                     PVOID,    __thiscall, (CLevel*, CEquipment*, Vector3 &, bool),                            0x4F3070);     // 1.15  CLevel, CEquipment, vector3 pos, bool unk
TLFUNCPTR(ResourceManagerCreateEquipment,         PVOID,    __thiscall, (CResourceManager*, u64, u32, u32, u32),                            0x5FB6D0);     // 1.15  CResourceManager, u64 guid, u32 level, u32 unk, u32 unk
TLFUNCPTR(PlayerPickupEquipment,                  PVOID,    __thiscall, (CPlayer*, CEquipment*, CLevel*),                                   0x4969B0);     // 1.15  CPlayer, CEquipment, CLevel
TLFUNCPTR(InventoryAddEquipment,                  PVOID,    __thiscall, (CInventory*, CEquipment*, u32, u32),                               0x4E6CE0);     // 1.15  CInventory, CEquipment, int slot, int unk
TLFUNCPTR(InventoryRemoveEquipment,               PVOID,    __thiscall, (CInventory*, CEquipment*),                                         0x4E7610);     // 1.15  CInventory, CEquipment
TLFUNCPTR(LevelHideEquipment,                     PVOID,    __thiscall, (CLevel*, CEquipment*, u32),                                        0x4F48C0);     // 1.15  CLevel, CEquipment, int unk

TLFUNCPTR(ChangeLevel,                            PVOID,    __thiscall, (CGameClient*, wstring, u32, u32, u32, wstring, u32),               0x40CF60);     // 1.15  CGameClient, 

TLFUNCPTR(PlayerAddGold,                          PVOID,    __thiscall, (CPlayer*, u32),                                                    0x4860B0);     // 1.15  CPlayer, u32 amount

TLFUNCPTR(PlayerLevelUp,                          PVOID,    __thiscall, (CPlayer*),                                                         0x4DB840);     // 1.15  CPlayer
TLFUNCPTR(PlayerLevelUpSilent,                    PVOID,    __thiscall, (CPlayer*),                                                         0x48E730);     // 1.15  CPlayer

TLFUNCPTR(CharacterPetawayTimer,                  PVOID,    __thiscall, (CCharacter*, float, CLevel*),                                      0x4924E0);     // 1.15  CMonster, float(0.0181999), CLevel

TLFUNCPTR(TriggerUnitTriggered,                   PVOID,    __thiscall, (CTriggerUnit*, CPlayer*),                                          0x4DE6C0);     // 1.15  CTriggerUnit, CPlayer

// !!! THIS COULD BE WRONG, THERE'S A BUNCH MATCHING -- I NEED TO DOUBLE CHECK THIS FUNC ANYWAYS - drivehappy
TLFUNCPTR(ObjectCreate,                           PVOID,    __thiscall, (PVOID, u64),                                                       0x446390);     // 1.15

TLFUNCPTR(BreakableTriggered,                     PVOID,    __thiscall, (CBreakable*, CPlayer*),                                            0x482600);     // 1.15  CBreakable, CPlayer
TLFUNCPTR(DamageShapeTriggered,                   PVOID,    __thiscall, (CDamageShape*),                                                    0x50ACF0);     // 1.15  CDamageShape, 

TLFUNCPTR(GameClientGamePaused,                   void,     __thiscall, (CGameClient*),                                                     0x40DD70);     // 1.15  CGameClient

TLFUNCPTR(ResourceManagerInitializePlayer,        void,     __thiscall, (CResourceManager*, u32, u32),                                      0x5FB5F0);     // 1.15  CResourceManager, 

TLFUNCPTR(WndProc,                                LRESULT,  __thiscall, (HWND, UINT, WPARAM, LPARAM),                                       0x4016B0);     // 1.15

TLFUNCPTR(GetPlayer,                              PVOID,    __thiscall, (void),                                                             0x5FB330);     // 1.15  Name misnomer - returns a ptr to CUnitResourceList
TLFUNCPTR(PlayerDied,                             void,     __thiscall, (void),                                                             0x548270);     // 1.15
TLFUNCPTR(PlayerResurrect,                        void,     __thiscall, (CDieMenu*, u32),                                                   0x56E000);     // 1.15  CDieMenu, u32 (0xF = @level, 0x10 = @town, 0xe = @body)

// -------------------------------------------------------------------------------- //
// In-place definitions

//TLFUNCPTR(GameClientProcessObjects,     void,     __thiscall, (PVOID, PVOID, PVOID, PVOID),                      0x41A790);     // 1.15  CGameClient
TLFUNCPTR(GameClientProcessObjects,               void,     __thiscall, (CGameClient*, PVOID, PVOID, PVOID),               0x41A790);     // 1.15  CGameClient

TLFUNCPTR(MonsterProcessAI2,                      void,     __thiscall, (CMonster*, float),                                0x4D4450);     // 1.15  CMonster, float (0.002)
TLFUNCPTR(MonsterProcessAI3,                      void,     __thiscall, (CMonster*, u32),                                  0x498670);     // 1.15  CMonster, u32 unk (0)
TLFUNCPTR(MonsterIdle,                            void,     __thiscall, (CMonster*, float),                                0x4D4950);     // 1.15  CMonster, float dtime (0.02)
TLFUNCPTR(MonsterOnHit,                           void,     __thiscall, (CMonster*, CMonster*),                            0x4D29E0);     // 1.15  CMonster, CMonster
  
TLFUNCPTR(PlayerCtor,                             void,     __thiscall, (PVOID),                                           0x4DA160);     // 1.15

TLFUNCPTR(PlayerCharacterSetAction,               void,     __thiscall, (CPlayer*),                                        0x4D5D00);     // 1.15  CPlayer

TLFUNCPTR(GameClientProcessTitleScreen,           void,     __thiscall, (CGameClient*, float, PVOID, float, u32),          0x40DF70);     // 1.15  CGameClient, float (0.005) / (0.1), u32 unk, float (0), u32 unk(0)

TLFUNCPTR(GameClientLoadMap,                      void,     __thiscall, (CGameClient*, u32),                               0x4188E0);     // 1.15  CGameClient, u32 unk (0)

TLFUNCPTR(Random,                                 void,     __thiscall, (),                                                0x5BA660);     // 1.15

TLFUNCPTR(LevelDestroyMonster,                    void,     __thiscall, (CLevel*, CMonster*),                              0x4F5AA0);     // 1.15  CLevel, CMonster

TLFUNCPTR(MonsterReadProp,                        void,     __thiscall, (CMonster*),                                       0x47EAF0);     // 1.15  CMonster

TLFUNCPTR(EquipmentUse,                           void,     __thiscall, (CEquipment*, CPlayer*, CPlayer*),                 0x4B4FB0);     // 1.15  CEquipment, CPlayer, CPlayer
TLFUNCPTR(EquipmentIdentify,                      void,     __thiscall, (CEquipment*),                                     0x4B0200);     // 1.15  CEquipment

TLFUNCPTR(LevelCreateAstarPathfinding,            CAstarPathfinder*,    __stdcall,  (float, float, u32, u32, PVOID, PVOID, float),  0x421700);

TLFUNCPTR(EquipmentGetEnchantPrice,               u32,      __thiscall, (CEquipment*),                                     0x4B0230);

TLFUNCPTR(PlayerRemoveGold,                       void,     __thiscall, (CPlayer*, u32 amount),                            0x4860B0);

TLFUNCPTR(GetGameGlobals,                         CGameGlobals*, __thiscall, (),                                           0x5219B0);

TLFUNCPTR(EquipmentEnchant,                       u32,      __thiscall, (CEquipment*, u32, u32, u32),                      0x4BF560);

//TLFUNCPTR(LoadArea,           void,     __thiscall, (/* 18 */),                                        0x40CF20);
// ... and add more later

void TLAPI::Initialize()
{
  log("Initializing tlapi...");

  PatchProcess();
  HookFunctions();
}

void TLAPI::PatchProcess()
{
  // always generate new uhm.. monsters? when zoning
  PatchJMP(EXEOFFSET(0x4169D1), EXEOFFSET(0x416A21));   // v1.15

  // What is this patch for?
  PatchJMP(EXEOFFSET(0x489F8D), EXEOFFSET(0x48A08B));   // v1.15
}

void TLAPI::HookFunctions()
{
  log("Hooking functions...");

  // Hook WndProc
  EVENT_INIT(_GLOBAL, WndProc, 5);

  // Hook GameClient
  EVENT_INIT(CGameClient, GameClientLoadMap, 2);
  EVENT_INIT(CGameClient, GameClientProcessObjects, 4);

  // Hook Equipment
  EVENT_INIT(CEquipment, EquipmentInitialize, 1);
  EVENT_INIT(CEquipment, EquipmentEnchant, 3);

  /*
  // Hook ResourceManager
  EVENT_INIT(CResourceManager, ResourceManagerInitializePlayer, 3);
  EVENT_INIT(CResourceManager, ResouceManagerCreateCharacter, 4);
  EVENT_INIT(CResourceManager, ResourceManagerCreateCharacterByName, 5);
  EVENT_INIT(CResourceManager, ResourceManagerCreateSomething, 5);
  */
  
  // Hook Level
  EVENT_INIT(CLevel, LevelCharacterInitialize, 3);
  EVENT_INIT(CLevel, LevelCreateAstarPathfinding, 7);

  // Hook Character
  EVENT_INIT(CCharacter, CharacterSetAlignment, 1);
  EVENT_INIT(CCharacter, CharacterSetDestination, 3);
  EVENT_INIT(CCharacter, CharacterSetAction, 1);
  EVENT_INIT(CCharacter, CharacterAddMinion, 1);
  EVENT_INIT(CCharacter, CharacterStrike, 7);

  // Hook Player
  EVENT_INIT(CPlayer, PlayerUseSkill, 2);

  // Hook Layout
  EVENT_INIT(CLayout, LayoutSetPosition, 1);

  // Hook GenericModel
  //EVENT_INIT(CGenericModel, GenericModelGetPosition, 2);

  log("Done hooking.");

  // Map
  //Hook(GameClientLoadMap, _load_map_pre, _load_map_post, HOOK_THISCALL, 2);

  /*
  Hook(ChangeLevel, _change_level_pre, _change_level_post, HOOK_THISCALL, 18);
  //Hook((PVOID)EXEOFFSET(0x4197E0), _on_load_area_pre, _on_load_area_post, HOOK_THISCALL, 0);    // v1.15

  log("Map Done");

  // Various
  Hook(CharacterSetDestination, _set_destination_pre, 0, HOOK_THISCALL, 3);
  Hook(CharacterStrike, _on_strike_pre, _on_strike_post, HOOK_THISCALL, 7);
  Hook(Random, 0, _random_post, HOOK_THISCALL, 0);
  Hook(LevelDestroyMonster, _LevelDestroyMonster_pre, 0, HOOK_THISCALL, 1);
  Hook(GameClientProcessObjects, _process_objects_pre, _process_objects_pre, HOOK_THISCALL, 4);
  Hook(WndProc, _wnd_proc_pre, NULL, HOOK_STDCALL, 5);

  log("Various Done");

  // Monster
  Hook(ResouceManagerCreateCharacter, _spider_some_create_pre, _spider_some_create_post, HOOK_THISCALL, 4);
  Hook(MonsterProcessAI, _spider_process_ai_pre, 0, HOOK_THISCALL, 2);
  Hook(MonsterProcessAI2, _spider_process_ai2_pre, 0, HOOK_THISCALL, 3);
  Hook(MonsterProcessAI3, _spider_process_ai3_pre, _spider_process_ai3_post, HOOK_THISCALL, 1);
  Hook(MonsterIdle, _spider_idle_pre, 0, HOOK_THISCALL, 3);
  Hook(MonsterOnHit, _spider_on_hit_pre, 0, HOOK_THISCALL, 2);
  Hook(CharacterSetAlignment, _set_alignment_pre, 0, HOOK_THISCALL, 1);

  log("Monster Done");

  // Entity
  Hook(LevelCharacterInitialize, _entity_initialize_pre, _entity_initialize_post, HOOK_THISCALL, 3);

  // Player
  Hook(PlayerCtor, 0, _player_ctor_post, HOOK_THISCALL, 1);
  Hook(PlayerCharacterSetAction, _player_set_action_pre, 0, HOOK_THISCALL, 1);
  Hook(PlayerAddGold, _add_goldtoplayer, 0, HOOK_THISCALL, 1);
  
  // Broken in v1.15 -- Look into this
  // Updated arg count from 2 to 3... check what was added
  Hook(ResourceManagerInitializePlayer, _initialize_player_pre, _initialize_player_post, HOOK_THISCALL, 3);
  
  Hook(PlayerDied, _player_died_pre, NULL, HOOK_THISCALL, 0);
  Hook(PlayerResurrect, _player_resurrect_pre, NULL, HOOK_THISCALL, 8);
  Hook(PlayerLevelUp, _PlayerLevelUp_pre, 0, HOOK_THISCALL, 0);
  Hook(PlayerLevelUpSilent, _PlayerLevelUp_silent_pre, NULL, HOOK_THISCALL, 0);
  Hook(CharacterAddMinion, _add_minion_pre, 0, HOOK_THISCALL, 1);

  log("Player Done");

  // Item
  Hook(EquipmentInitialize, _item_initialize_pre, 0, HOOK_THISCALL, 1);
  Hook(ResourceManagerCreateEquipment, _item_create_pre, _item_create_post, HOOK_THISCALL, 5);
  Hook(LevelDropEquipment, _item_drop_pre, 0, HOOK_THISCALL, 3);
  Hook(PlayerPickupEquipment, _item_pick_up_pre, _item_pick_up_post ,HOOK_THISCALL, 2);
  Hook(InventoryAddEquipment, _item_equip_pre, _item_equip_post, HOOK_THISCALL, 3);
  Hook(InventoryRemoveEquipment, _item_unequip_pre, 0, HOOK_THISCALL, 1);

  log("Item Done");

  // Object
  Hook(TriggerUnitTriggered, _interact_with_object, 0, HOOK_THISCALL, 1);
  Hook(ObjectCreate, _object_create_pre, _object_create_post, HOOK_THISCALL, 1);
  log("Object Done");

  // Ogre
  Hook(GetProcAddress(GetModuleHandle("OgreMain.dll"), "?isActive@RenderWindow@Ogre@@UBE_NXZ"), _ogre_is_active, 0, HOOK_THISCALL, 0);
  log("OGRE Done");

  log("Hooking complete");

  // Unknowns, Testings
  // This one handles bypassing monster creation as well (I think this is some sort of initial
  // monster load from file, while the rest are generated at runtime).
  // This calls the spider_create, but doesn't handle when it returns null.
  Hook((PVOID)EXEOFFSET(0x4F3960), test0_pre, test0_post, HOOK_THISCALL, 5);    // v1.15

  // Doesn't work, don't use
  //Hook(ResourceManagerCreateCharacterByName, test1_pre, test1_post, HOOK_THISCALL, 5);

  log("Unknowns/Tests");

  // Handles item loading and positioning of objects (if we don't call org then:
  //   player appears to start at (0,0), no items are loaded, but it does load the level the player is at
  Hook((PVOID)EXEOFFSET(0x4AA580), test2_pre, test2_post, HOOK_THISCALL, 1);

  // True level load?
  Hook((PVOID)EXEOFFSET(0x4FC9F0), test3_pre, test3_post, HOOK_THISCALL, 11);

  // More level loading tests -- appears to be saving items on the previous level
  Hook((PVOID)EXEOFFSET(0x4E1210), test4_pre, test4_post, HOOK_THISCALL, 3);

  // dengus' unknown/weird function
  // I'm seeing this getting called 7 times per frame on the main menu,
  // although it doesn't do it's memmove processing
  Hook((PVOID)EXEOFFSET(0x5B1DA0), test5_pre, test5_post, HOOK_THISCALL, 5);

  // delete(void*)
  //Hook((PVOID)EXEOFFSET(0x6059B8), test6_pre, test6_post, HOOK_CDECL, 1);

  // new(void*)
  //Hook((PVOID)EXEOFFSET(0x605B54), test7_pre, test7_post, HOOK_CDECL, 1);
  
  // Player ctor?
  Hook((PVOID)EXEOFFSET(0x4DB820), test8_pre, test8_post, HOOK_THISCALL, 1);
  
  // CCharacterSaveSlot ctor
  Hook((PVOID)EXEOFFSET(0x4AE350), test9_pre, NULL, HOOK_THISCALL, 1);
  
  // CCharacter ctor
  Hook((PVOID)EXEOFFSET(0x4A8CE0), test10_pre, NULL, HOOK_THISCALL, 1);
  
  // CItemGold ctor
  Hook((PVOID)EXEOFFSET(0x4D0730), testItemGold_pre, NULL, HOOK_THISCALL, 1);
  
  // CItem ctor
  Hook((PVOID)EXEOFFSET(0x4CFC20), testItem_pre, NULL, HOOK_THISCALL, 1);

  // FireMessage
  Hook((PVOID)EXEOFFSET(0x5BF870), testFireMessage_pre, NULL, HOOK_THISCALL, 1);

  // Save Game
  Hook((PVOID)EXEOFFSET(0x417110), testSaveGame_pre, testSaveGame_post, HOOK_THISCALL, 2);

  // Save Shared Stash
  Hook((PVOID)EXEOFFSET(0x52A8C0), testSaveSharedStash_pre, testSaveSharedStash_post, HOOK_THISCALL, 0);
  // Load Shared Stash
  Hook((PVOID)EXEOFFSET(0x52A5D0), NULL, NULL, HOOK_THISCALL, 2);

  // CGame Initialize
  Hook((PVOID)EXEOFFSET(0x407320), testCGameLoad_pre, testCGameLoad_post, HOOK_THISCALL, 1);

  // CGameClient LoadGame
  Hook((PVOID)EXEOFFSET(0x417E00), testCGameClient_LoadGame_pre, testCGameClient_LoadGame_post, HOOK_THISCALL, 4);

  // CGameClient CreateLevel
  Hook((PVOID)EXEOFFSET(0x415820), testCGameClient_CreateLevel_pre, testCGameClient_CreateLevel_post, HOOK_THISCALL, 24);

  // CGameClient LoadLevel
  Hook((PVOID)EXEOFFSET(0x4197E0), testCGameClient_LoadLevel_pre, testCGameClient_LoadLevel_post, HOOK_THISCALL, 0);
  */
}

// 
CGameClient* TLAPI::GetGameClient()
{
  return NULL;
}
