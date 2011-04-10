#include "tlapi.h"
#include "Hook.h"
#include "Offsets.h"
#include "Events.h"
#include "Globals.h"

using namespace TLAPI;

u32 exeBaseReal = (u32)GetModuleHandle("Torchlight.exe");

TLFUNCPTR(SetSeedValue0,                          void,         __stdcall,  (u32),                                                          0x5BA710);
TLFUNCPTR(SetSeedValue2,                          void,         __stdcall,  (u32),                                                          0x5BA740);

// Define the offset locations
TLFUNCPTR(ResourceManagerCreatePlayer,            CPlayer*,     __thiscall, (CResourceManager*, wchar_t*, u32),                             0x5FB7B0);     // CResourceManager, u32 unk0, u32 unk1
TLFUNCPTR(ResourceManagerCreateMonster,           CMonster*,    __thiscall, (CResourceManager*, u64, u32, bool),                            0x5FBB70);     // CResourceManager, u64 guid, u32 level, bool noitems?
TLFUNCPTR(LevelCharacterInitialize,               CCharacter*,  __thiscall, (CLevel*, CCharacter*, Vector3*, u32),                          0x4F2EF0);     // CLevel, CMonster, vector3*, u32 unk
TLFUNCPTR(ResourceManagerCreateCharacterByName,   CCharacter*,  __thiscall, (CResourceManager*, const wchar_t*, const wchar_t*, u32, u32),  0x5FC600);     // CResourceManager, ...
TLFUNCPTR(CharacterSetAlignment,                  void,         __thiscall, (CCharacter*, u32),                                             0x4839E0);     // CMonster, u32 alignment (2 = badguy, 0 = goodguy)
TLFUNCPTR(CharacterSetDestination,                void,         __thiscall, (CCharacter*, CLevel*, float, float),                           0x492AD0);     // CPlayer, CLevel, u32 x, u32 y
TLFUNCPTR(CharacterSetAction,                     PVOID,        __thiscall, (CCharacter*, u32),                                             0x489E50);     // CCharacter, u32 action
TLFUNCPTR(CharacterUseSkill,                      PVOID,        __thiscall, (CCharacter*, u64),                                             0x494E50);     // CCharacter, u64 skill
TLFUNCPTR(CharacterUpdateHealth,                  PVOID,        __thiscall, (CCharacter*, float),                                           0x490880);     //

TLFUNCPTR(CharacterSetupSkills,                   void,         __thiscall, (CCharacter*, CDataGroup*, u32),                                0x480F00);     //
TLFUNCPTR(CharacterAddSkill,                      void,         __thiscall, (CCharacter*, wstring*, u32),                                   0x47E930);     // Called before AddSkill2 from 0x567EB0 (CConsole_AddSkill)
TLFUNCPTR(CharacterAddSkill2,                     void,         __thiscall, (CCharacter*, wstring),                                         0x486910);     // 
TLFUNCPTR(CharacterGetAvailableSkillPoints,       u32,          __thiscall, (CCharacter*),                                                  0x4865C0);     // 
TLFUNCPTR(CharacterIsEffectPresent,               bool,         __thiscall, (CCharacter*, wstring*),                                        0x47F9D0);     // 

TLFUNCPTR(SkillManagerAddSkill,                   void,         __thiscall, (CSkillManager*, CSkill*, bool, u32),                           0x5D7420);
TLFUNCPTR(SkillManagerSetSkillLevel,           CSkillProperty*, __thiscall, (CSkillManager*, CSkill*, u32),                                 0x5D8000);     //
TLFUNCPTR(SkillManagerGetSkillFromGUID,           CSkill*,      __thiscall, (CSkillManager*, u64),                                          0x5D5E80);     //

TLFUNCPTR(QuestManagerSetQuestCompleted,          void,         __thiscall, (CQuestManager*, CQuest*, CCharacter*, u32),                    0x5EBF40);     //


TLFUNCPTR(GameClientUpdateSkill,                  PVOID,        __thiscall, (CGameClient*, u64, u32, u32),                                  0x4145D0);     // CGameClient, u64 skill, u32 notFirstUse, u32

TLFUNCPTR(PositionableObjectSetPosition,          void,         __thiscall, (CPositionableObject*, const Vector3*),                         0x50E450);     // 
TLFUNCPTR(PositionableObjectGetPosition,          void,         __thiscall, (CPositionableObject*, Vector3&, bool),                          0x50E3F0);     // 

TLFUNCPTR(CharacterAddMinion,                     void,         __thiscall, (CCharacter*, CCharacter*),                                     0x4A9B20);     // CMonster, CMonster

TLFUNCPTR(ResourceManagerCreateBaseUnit,          CBaseUnit*,   __thiscall, (CResourceManager*, u64, u32, u32, u32),                        0x5FC170);     // CResourceManager

TLFUNCPTR(CharacterSetTarget,                     PVOID,        __thiscall, (CCharacter*, CCharacter*),                                     0x492970);     // CMonster, NULL

TLFUNCPTR(CharacterStrike,                        PVOID,    __thiscall, (CCharacter*, CLevel*, CCharacter*, PVOID, u32, float, float, u32), 0x4A0190);  // 1.15  CMonster src, CLevel, CMonster dst, NULL, 0, 1.0, 1.0, 7

TLFUNCPTR(EquipmentAddStackCount,                 PVOID,    __thiscall, (CEquipment*, u32),                                                 0x4B0930);  // 1.15

TLFUNCPTR(CharacterSetAnimation,                  PVOID,    __thiscall, (CPlayer*, wstring*, float, float, float, CLevel*),                 0x4841F0);     // 1.15  CPlayer, u32 unk, bool unk, float unk (0.2), float unk (1), u32(

TLFUNCPTR(CharacterAttack,                        PVOID,    __thiscall, (CCharacter*),                                                      0x48FBD0);     // 1.15  CPlayer

TLFUNCPTR(LevelDropItem,                          PVOID,    __thiscall, (CLevel*, CItem*, Vector3 &, bool),                                 0x4F3070);     // 1.15  CLevel, CItem, vector3 pos, bool unk
TLFUNCPTR(ResourceManagerCreateItem,             CItem*,    __thiscall, (CResourceManager*, u64, u32, u32, u32),                            0x5FB6D0);     // 1.15  CResourceManager, u64 guid, u32 level, u32 unk, u32 unk
TLFUNCPTR(CharacterPickupEquipment,               PVOID,    __thiscall, (CCharacter*, CEquipment*, CLevel*),                                0x4969B0);     // 1.15  CPlayer, CEquipment, CLevel
TLFUNCPTR(InventoryAddEquipment,                  PVOID,    __thiscall, (CInventory*, CEquipment*, u32, u32),                               0x4E6CE0);     // 1.15  CInventory, CEquipment, int slot, int unk
TLFUNCPTR(InventoryRemoveEquipment,               PVOID,    __thiscall, (CInventory*, CEquipment*),                                         0x4E7610);     // 1.15  CInventory, CEquipment
TLFUNCPTR(InventoryGetEquipmentFromSlot,          void,     __thiscall, (CEquipment*, CInventory*, u32),                                    0x4E4DD0);
TLFUNCPTR(InventoryGetEquipmentRefFromSlot,       void,     __thiscall, (CEquipmentRef*, CInventory*, u32),                                 0x4E4E10);
TLFUNCPTR(InventoryAddTabSize,                    void,     __thiscall, (CInventory*, u32, u32),                                            0x4E7370);     // 1.15   CInventory, TabIndex, AdditionalSize


TLFUNCPTR(LevelHideEquipment,                     PVOID,    __thiscall, (CLevel*, CEquipment*, u32),                                        0x4F48C0);     // 1.15  CLevel, CEquipment, int unk

TLFUNCPTR(GameClient_ChangeLevel,                 PVOID,    __thiscall, (CGameClient*, wstring, s32, u32, u32, wstring, u32),               0x40CF60);     // 1.15  CGameClient, 

TLFUNCPTR(PlayerAddGold,                          PVOID,    __thiscall, (CPlayer*, u32),                                                    0x4860B0);     // 1.15  CPlayer, u32 amount

TLFUNCPTR(PlayerLevelUp,                          PVOID,    __thiscall, (CPlayer*),                                                         0x4DB840);     // 1.15  CPlayer
TLFUNCPTR(PlayerLevelUpSilent,                    PVOID,    __thiscall, (CPlayer*),                                                         0x48E730);     // 1.15  CPlayer

TLFUNCPTR(CharacterPetawayTimer,                  PVOID,    __thiscall, (CCharacter*, float, CLevel*),                                      0x4924E0);     // 1.15  CMonster, float(0.0181999), CLevel

// !!! THIS COULD BE WRONG, THERE'S A BUNCH MATCHING -- I NEED TO DOUBLE CHECK THIS FUNC ANYWAYS - drivehappy
TLFUNCPTR(ObjectCreate,                           PVOID,    __thiscall, (PVOID, u64),                                                       0x446390);     // 1.15

TLFUNCPTR(BreakableTriggered,                     PVOID,    __thiscall, (CBreakable*, CPlayer*),                                            0x482600);     // 1.15  CBreakable, CPlayer
TLFUNCPTR(DamageShapeTriggered,                   PVOID,    __thiscall, (CDamageShape*),                                                    0x50ACF0);     // 1.15  CDamageShape, 

TLFUNCPTR(GameClientGamePaused,                   void,     __thiscall, (CGameClient*),                                                     0x40DD70);     // 1.15  CGameClient

TLFUNCPTR(ResourceManagerInitializePlayer,        void,     __thiscall, (CResourceManager*, u32, u32),                                      0x5FB5F0);     // 1.15  CResourceManager, 

TLFUNCPTR(WndProc,                                LRESULT,  __thiscall, (HWND, UINT, WPARAM, LPARAM),                                       0x4016B0);     // 1.15

TLFUNCPTR(GetPlayer,                              PVOID,    __thiscall, (void),                                                             0x5FB330);     // 1.15  Name misnomer - returns a ptr to CUnitResourceList
TLFUNCPTR(PlayerDied,                             void,     __thiscall, (void),                                                             0x548270);     // 1.15
TLFUNCPTR(PlayerResurrect,                        void,     __thiscall, (CCharacter*),                                                      0x4D6810);     // 1.15  CPlayer

// -------------------------------------------------------------------------------- //
// In-place definitions

TLFUNCPTR(GameClientProcessObjects,               void,     __thiscall, (CGameClient*, float, PVOID, PVOID),               0x41A790);     // 1.15  CGameClient

TLFUNCPTR(MonsterProcessAI,                       PVOID,    __thiscall, (CMonster*, float, u32),                           0x4D36F0);     // 1.15  CMonster, float unk (0.005), CLevel
TLFUNCPTR(MonsterProcessAI2,                      void,     __thiscall, (CMonster*, float, u32, u32),                      0x4D4450);     // 1.15  CMonster, float (0.002)
TLFUNCPTR(MonsterProcessAI3,                      void,     __thiscall, (CMonster*, u32),                                  0x498670);     // 1.15  CMonster, u32 unk (0)
TLFUNCPTR(MonsterIdle,                            void,     __thiscall, (CMonster*, float),                                0x4D4950);     // 1.15  CMonster, float dtime (0.02)
TLFUNCPTR(MonsterOnHit,                           void,     __thiscall, (CMonster*, CMonster*),                            0x4D29E0);     // 1.15  CMonster, CMonster

TLFUNCPTR(MonsterGetCharacterClose,               void,     __thiscall, (CMonster*, float, u32),                           0x486FB0);
  
TLFUNCPTR(PlayerCtor,                             void,     __thiscall, (),                                                0x4DA160);     // 1.15
TLFUNCPTR(GameClientCtor,                         void,     __thiscall, (),                                                0x40F7B0);     // 1.15
TLFUNCPTR(GameCtor,                               void,     __thiscall, (),                                                0x4095A0);     // 1.15
TLFUNCPTR(CharacterDtor,                          void,     __thiscall, (),                                                0x4A70A0);     // 1.15




TLFUNCPTR(PlayerCharacterSetAction,               void,     __thiscall, (CPlayer*),                                        0x4D5D00);     // 1.15  CPlayer

TLFUNCPTR(GameClientProcessTitleScreen,           void,     __thiscall, (CGameClient*, float, PVOID, PVOID),               0x40DF70);     // 1.15  CGameClient, float (0.005) / (0.1), u32 unk, float (0), u32 unk(0)

TLFUNCPTR(GameClient_LoadMap,                     void,     __thiscall, (CGameClient*, u32, u32),                          0x4188E0);     // 1.15  CGameClient, u32 unk (0)

TLFUNCPTR(Random,                                 void,     __thiscall, (),                                                0x5BA660);     // 1.15

TLFUNCPTR(LevelDestroyMonster,                    void,     __thiscall, (CLevel*, CMonster*),                              0x4F5AA0);     // 1.15  CLevel, CMonster
TLFUNCPTR(LevelCreateAstarPathfinding,            CAstarPathfinder*,    __stdcall,  (float, float, u32, u32, PVOID, PVOID, float),  0x421700);

TLFUNCPTR(MonsterReadProp,                        void,     __thiscall, (CMonster*),                                       0x47EAF0);     // 1.15  CMonster

TLFUNCPTR(GetGameGlobals,                         CGameGlobals*, __thiscall, (),                                           0x5219B0);

TLFUNCPTR(EffectManagerCreateEffect,              CEffect*, __thiscall, (CEffectManager*),                                 0x47D300);
TLFUNCPTR(EffectManager_UpdateEffects,            void,     __thiscall, (CEffectManager*),                                 0x47CD90);
TLFUNCPTR(EffectManager_AddEffectToEquipment,     void,     __thiscall, (CEffectManager*, CEquipment*, CEffect*),          0x47E3A0);

TLFUNCPTR(EffectGroupManager_CreateAffix,         void,     __thiscall, (CEffectGroupManager*, u32, u32, u32, CList<CAffix*>*),   0x47BB50);

TLFUNCPTR(EquipmentInitialize,                    PVOID,    __thiscall, (CEquipment*, CItemSaveState*),                    0x4BE250);     // 1.15  CEquipment, CItemSaveState
TLFUNCPTR(EquipmentDtor,                          void,     __thiscall, (),                                                0x4BA250);     // 1.15
TLFUNCPTR(EquipmentUse,                           void,     __thiscall, (CEquipment*, CPlayer*, CPlayer*),                 0x4B4FB0);     // 1.15  CEquipment, CPlayer, CPlayer
TLFUNCPTR(EquipmentIdentify,                      void,     __thiscall, (CEquipment*, CPlayer*, CEquipment*),              0x4B4FB0);     // 1.15  CEquipment
TLFUNCPTR(Equipment_AddMagicModifier,             void,     __thiscall, (CEquipment*, u32, u32),                           0x4BC7C0);
TLFUNCPTR(Equipment_AddAffix,                     void,     __thiscall, (CEquipment*, CAffix*, u32, CEquipment*, float),   0x47F940);
TLFUNCPTR(Equipment_UpdateRequirements,           void,     __thiscall, (CEquipment*),                                     0x4B3EA0);
TLFUNCPTR(Equipment_UpdatePrice,                  void,     __thiscall, (CEquipment*),                                     0x4B3A10);
TLFUNCPTR(Equipment_UpdateTooltip,                void,     __thiscall, (CEquipment*),                                     0x4CF410);
TLFUNCPTR(EquipmentEnchant,                       u32,      __thiscall, (CEquipment*, u32, u32, u32),                      0x4BF560);
TLFUNCPTR(EquipmentGetEnchantPrice,               u32,      __thiscall, (CEquipment*),                                     0x4B0230);
TLFUNCPTR(Equipment_AddGem,                       void,     __thiscall, (CEquipment*, CEquipment*),                        0x4B6F80);

TLFUNCPTR(Effect_CopyCtor,                        void,     __thiscall, (CEffect*),                                        0x47A2F0);
//TLFUNCPTR(Effect_DataGroupCtor,                   void,     __thiscall, (CDataGroup*, u32),                                0x5D5276);
TLFUNCPTR(Effect_ParamCtor,                       void,     __thiscall, (CEffect*, u32, bool, bool, float, float, float, bool),     0x479710);  // CEffect, EffectType, unk..
TLFUNCPTR(Effect_Effect_Something,                void,     __thiscall, (CEffect*, CEffect*),           	                 0x47A060);
TLFUNCPTR(Effect_Something0,                      void,     __thiscall, (CEffect*, u32),                                   0x477CF0);
TLFUNCPTR(Effect_Character_Unk0,                  void,     __thiscall, (CEffect*, CCharacter*, bool),                     0x4798A0);


TLFUNCPTR(GetMasterResourceManager, CMasterResourceManager*,__thiscall, (void),                                            0x524EC0);

TLFUNCPTR(GameClient_SaveGame,                    void,     __thiscall, (CGameClient*, u32, u32, bool*),                   0x417110);
TLFUNCPTR(GameClient_SetupUI,                     void,     __thiscall, (CGameClient*, u32, u32),                          0x40C9A0);
TLFUNCPTR(GameClient_CreateLevel,                 void,     __thiscall, (CGameClient*, wstring, wstring, u32, u32, u32, wstring), 0x415820);
TLFUNCPTR(GameClient_LoadLevel,                   void,     __thiscall, (CGameClient*),                                    0x4197E0);

TLFUNCPTR(Game_CreateUI,                          void,     __thiscall, (CGame*),                                          0x402070);

TLFUNCPTR(MouseManagerInput,                      void,     __thiscall, (CMouseManager*, u32, u32),                        0x4E47F0);

TLFUNCPTR(CharacterSaveState_LoadFromFile,        void,     __thiscall, (CCharacterSaveState*, PVOID, u32),                0x4AE370); 

TLFUNCPTR(MainMenu_Event,                         void,     __thiscall, (CMainMenu*, u32, wstring),                        0x5B6800);


TLFUNCPTR(GameUI_TriggerPause,                    void,     __thiscall, (CGameUI*),                                        0x53D6E0);
TLFUNCPTR(GameUI_WindowResized,                   void,     __thiscall, (CGameUI*),                                        0x55A950);


TLFUNCPTR(EnchantMenu_EnchantItem,                void,     __thiscall, (CEnchantMenu*),                                   0x575740);

TLFUNCPTR(GameUI_HandleKeyboardInput,             void,     __thiscall, (CGameUI*, u32, u32, u32),                         0x53B8F0);

TLFUNCPTR(KeyManager_InjectKey,                   void,     __thiscall, (CKeyManager*, u32, u32),                          0x4E45A0);



TLFUNCPTR(Character_Update,                       void,     __thiscall, (CCharacter*),                                     0x4AC630);
TLFUNCPTR(Character_Update_Level,                 void,     __thiscall, (CCharacter*, CLevel*, float),                     0x490CB0);
TLFUNCPTR(Character_Update_Character,             void,     __thiscall, (CCharacter*, CCharacter*),                        0x4A33C0);
TLFUNCPTR(Character_SetOrientation,               void,     __thiscall, (CCharacter*, Vector3*, float),                    0x48B450);
TLFUNCPTR(Character_UpdateOrientation,            void,     __thiscall, (CCharacter*, float, float),                       0x484390);
TLFUNCPTR(Character_Killed,                       void,     __thiscall, (CCharacter*, CCharacter*, Ogre::Vector3*, float, u32), 0x4A7570);

TLFUNCPTR(Path_GetNextNode,                       void,     __thiscall, (CPath*, Vector3*, float),                         0x5B8670);

TLFUNCPTR(TriggerUnit_Ctor,              CTriggerUnit*,     __thiscall, (CLayout*),                                        0x4DDD70);
TLFUNCPTR(TriggerUnitTriggered,                   PVOID,    __thiscall, (CTriggerUnit*, CPlayer*),                         0x4DE6C0);     // 1.15  CTriggerUnit, CPlayer
//TLFUNCPTR(TriggerUnit_Triggered2,                 void,     __thiscall, (CTriggerUnit*, CCharacter*),                      0x4DF190);


TLFUNCPTR(ItemGold_Ctor,                    CItemGold*,     __thiscall, (PVOID, CResourceManager*, u32),                   0x4CFFC0);

TLFUNCPTR(Level_CharacterKilledCharacter,         void,     __thiscall, (CLevel*, CCharacter*, CCharacter*, Vector3*, u32),0x4F4DE0);
TLFUNCPTR(Level_Dtor,                             void,     __thiscall, (CLevel*, u32),                                    0x4F94C0);
TLFUNCPTR(Level_Ctor,                             void,     __thiscall, (wstring name, CSettings*, CGameClient*, CResourceManager*, PVOID OctreeSM, CSoundManager*, u32, u32), 0x4F8FB0);
TLFUNCPTR(Level_Update,	                          void,     __thiscall, (CLevel*, Vector3*, u32, float),	                 0x4F5C60);
TLFUNCPTR(Level_Cleanup,                          void,     __thiscall, (CLevel*, u32, u32),           	                   0x4ECC00);
//TLFUNCPTR(Level_LoadLevel,                        void,     __thiscall, (CLevel*, CLevelTemplateData*, u32, u32, PVOID, ), 0x4FC9F0);


TLFUNCPTR(EquipmentRef_Dtor,                      void,     __thiscall, (CEquipmentRef*, u32),                             0x4E4A20);

TLFUNCPTR(Player_KillMonsterExperience,           void,     __thiscall, (CCharacter*, CLevel*, CCharacter*, u32, u32),     0x48E4A0);
TLFUNCPTR(Player_SwapWeapons,                     void,     __thiscall, (CCharacter*),                                     0x4838E0);

// Same as Character_AddSkill
TLFUNCPTR(BaseUnit_AddSkill,                      void,     __thiscall, (CBaseUnit*, wstring*, u32),                       0x47E930);

TLFUNCPTR(Level_RemoveEquipment,                  void,     __thiscall, (CLevel*, CEquipment*),        	                   0x4F5350);

TLFUNCPTR(EffectManager_RemoveAffix,              bool,     __thiscall, (CEffectManager*, CAffix*),                        0x47DA40);

TLFUNCPTR(InventoryMenu_OpenClose,                void,     __thiscall, (CInventoryMenu*, bool),                           0x5788B0);
TLFUNCPTR(InventoryMenu_MouseEvent,               void,     __thiscall, (CInventoryMenu*, const CEGUI::MouseEventArgs&),   0x578EF0);


void TLAPI::Initialize()
{
  log("Initializing tlapi...");

  PatchProcess();
  HookFunctions();
}

void TLAPI::PatchProcess()
{
  // 
  PatchJMP(EXEOFFSET(0x489F8D), EXEOFFSET(0x48A08B));   // v1.15
}

void TLAPI::HookFunctions()
{
  log("Hooking functions...");

  // InventoryMenu
  EVENT_INIT(CInventoryMenu, InventoryMenu_OpenClose, 1);
  EVENT_INIT(CInventoryMenu, InventoryMenu_MouseEvent, 1);

  // Hook EffectGroupManager
  EVENT_INIT(CEffectGroupManager, EffectGroupManager_CreateAffix, 4);

  // Hook EffectManager
  EVENT_INIT(CEffectManager, EffectManagerCreateEffect, 0);
  EVENT_INIT(CEffectManager, EffectManager_AddEffectToEquipment, 2);
  EVENT_INIT(CEffectManager, EffectManager_RemoveAffix, 1);
  
  // BaseUnit
  EVENT_INIT(CBaseUnit, BaseUnit_AddSkill, 2);

  // Path
  EVENT_INIT(CPath, Path_GetNextNode, 2);

  // Effect
  EVENT_INIT(CEffect, Effect_Effect_Something, 1);
  EVENT_INIT(CEffect, Effect_ParamCtor, 7);
  //EVENT_INIT(CEffect, Effect_CopyCtor, 1);
  //EVENT_INIT(CEffect, Effect_Character_Unk0, 2);

  // Hook WndProc
  EVENT_INIT(_GLOBAL, WndProc, 5);
  EVENT_INIT(_GLOBAL, SetSeedValue0, 0);
  EVENT_INIT(_GLOBAL, SetSeedValue2, 0);

  // Hook Game
  EVENT_INIT(CGame, GameCtor, 0);
  EVENT_INIT(CGame, Game_CreateUI, 0);

  // KeyManager
  EVENT_INIT(CKeyManager, KeyManager_InjectKey, 2);

  // QuestManager
  EVENT_INIT(CQuestManager, QuestManagerSetQuestCompleted, 3);

  // SkillManager
  EVENT_INIT(CSkillManager, SkillManagerAddSkill, 3);
  EVENT_INIT(CSkillManager, SkillManagerSetSkillLevel, 2);

  // Hook Monster
  EVENT_INIT(CMonster, MonsterProcessAI, 2);
  EVENT_INIT(CMonster, MonsterProcessAI2, 3);
  EVENT_INIT(CMonster, MonsterProcessAI3, 1);
  EVENT_INIT(CMonster, MonsterIdle, 3);
  EVENT_INIT(CMonster, MonsterGetCharacterClose, 2);

  // Hook GameClient
  EVENT_INIT(CGameClient, GameClientCtor, 8);
  EVENT_INIT(CGameClient, GameClient_LoadMap, 2);
  EVENT_INIT(CGameClient, GameClientProcessObjects, 4);
  EVENT_INIT(CGameClient, GameClient_SaveGame, 2);
  EVENT_INIT(CGameClient, GameClient_SetupUI, 2);
  EVENT_INIT(CGameClient, GameClient_CreateLevel, 24);
  EVENT_INIT(CGameClient, GameClient_LoadLevel, 0);
  EVENT_INIT(CGameClient, GameClientProcessTitleScreen, 4);
  EVENT_INIT(CGameClient, GameClientGamePaused, 0);
  EVENT_INIT(CGameClient, GameClient_ChangeLevel, 18);

  // Hook EnchantMenu
  EVENT_INIT(CEnchantMenu, EnchantMenu_EnchantItem, 0);

  // Hook Equipment
  EVENT_INIT(CEquipment, EquipmentDtor, 0);
  EVENT_INIT(CEquipment, EquipmentInitialize, 1);
  EVENT_INIT(CEquipment, EquipmentEnchant, 3);
  EVENT_INIT(CEquipment, Equipment_AddMagicModifier, 2);
  EVENT_INIT(CEquipment, Equipment_AddAffix, 4);
  EVENT_INIT(CEquipment, EquipmentAddStackCount, 1);
  EVENT_INIT(CEquipment, Equipment_AddGem, 1);
  EVENT_INIT(CEquipment, EquipmentIdentify, 2);

  // EquipmentRef
  EVENT_INIT(CEquipmentRef, EquipmentRef_Dtor, 1);

  // ItemGold
  EVENT_INIT(CItemGold, ItemGold_Ctor, 2);

  // TriggerUnit
  EVENT_INIT(CTriggerUnit, TriggerUnitTriggered, 1);
  EVENT_INIT(CTriggerUnit, TriggerUnit_Ctor, 1);
  //EVENT_INIT(CTriggerUnit, TriggerUnit_Triggered2, 1);

  // Breakable
  EVENT_INIT(CBreakable, BreakableTriggered, 1);

  // MainMenu
  EVENT_INIT(CMainMenu, MainMenu_Event, 8);
  
  // CharacterSaveState
  EVENT_INIT(CCharacterSaveState, CharacterSaveState_LoadFromFile, 2);

  // GameUI
  EVENT_INIT(CGameUI, GameUI_TriggerPause, 0);
  EVENT_INIT(CGameUI, GameUI_HandleKeyboardInput, 3);
  EVENT_INIT(CGameUI, GameUI_WindowResized, 0);

  /*
  // Hook ResourceManager
  EVENT_INIT(CResourceManager, ResourceManagerInitializePlayer, 3);
  EVENT_INIT(CResourceManager, ResourceManagerCreateCharacterByName, 5);
  */

  EVENT_INIT(CResourceManager, ResourceManagerCreatePlayer, 2);
  EVENT_INIT(CResourceManager, ResourceManagerCreateBaseUnit, 5);
  EVENT_INIT(CResourceManager, ResourceManagerCreateMonster, 4);
  EVENT_INIT(CResourceManager, ResourceManagerCreateItem, 5);
  
  // Hook Level
  EVENT_INIT(CLevel, LevelCharacterInitialize, 3);
  EVENT_INIT(CLevel, LevelCreateAstarPathfinding, 7);
  EVENT_INIT(CLevel, LevelDropItem, 3);
  EVENT_INIT(CLevel, Level_CharacterKilledCharacter, 4);
  EVENT_INIT(CLevel, Level_Dtor, 1);
  EVENT_INIT(CLevel, Level_Ctor, 14);
  EVENT_INIT(CLevel, Level_Update, 4);
  EVENT_INIT(CLevel, Level_Cleanup, 2);
  EVENT_INIT(CLevel, Level_RemoveEquipment, 1);

  // Hook 
  EVENT_INIT(CInventory, InventoryAddEquipment, 3);
  EVENT_INIT(CInventory, InventoryRemoveEquipment, 1);
  EVENT_INIT(CInventory, InventoryGetEquipmentFromSlot, 1);
  EVENT_INIT(CInventory, InventoryGetEquipmentRefFromSlot, 1);
  EVENT_INIT(CInventory, InventoryAddTabSize, 2);
  
  // Hook MouseManager
  EVENT_INIT(CMouseManager, MouseManagerInput, 2);

  // Hook Character
  EVENT_INIT(CCharacter, CharacterDtor, 0);
  EVENT_INIT(CCharacter, CharacterSetAlignment, 1);
  EVENT_INIT(CCharacter, CharacterSetDestination, 3);
  EVENT_INIT(CCharacter, CharacterSetAction, 1);
  EVENT_INIT(CCharacter, CharacterSetTarget, 1);
  EVENT_INIT(CCharacter, CharacterAddMinion, 1);
  EVENT_INIT(CCharacter, CharacterStrike, 7);
  EVENT_INIT(CCharacter, CharacterPickupEquipment, 2);
  EVENT_INIT(CCharacter, CharacterAttack, 0);
  EVENT_INIT(CCharacter, CharacterUseSkill, 2);
  EVENT_INIT(CCharacter, Character_Update, 3);
  EVENT_INIT(CCharacter, Character_SetOrientation, 2);
  EVENT_INIT(CCharacter, Character_UpdateOrientation, 2);
  EVENT_INIT(CCharacter, CharacterSetupSkills, 2);
  EVENT_INIT(CCharacter, CharacterAddSkill, 2);
  EVENT_INIT(CCharacter, CharacterAddSkill2, 7);
  EVENT_INIT(CCharacter, CharacterUpdateHealth, 1);
  EVENT_INIT(CCharacter, PlayerResurrect, 0);
  EVENT_INIT(CCharacter, Character_Update_Level, 2);
  EVENT_INIT(CCharacter, Character_Update_Character, 1);
  EVENT_INIT(CCharacter, Player_KillMonsterExperience, 4);
  EVENT_INIT(CCharacter, Character_Killed, 4);
  EVENT_INIT(CCharacter, Player_SwapWeapons, 0);

  // Player
  EVENT_INIT(CPlayer, PlayerLevelUp, 0);

  // Hook Layout
  EVENT_INIT(CPositionableObject, PositionableObjectSetPosition, 1);

  log("Done hooking.");
}

// 
CGameClient* TLAPI::GetGameClient()
{
  return NULL;
}
