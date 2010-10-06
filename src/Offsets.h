#pragma once

#include "Hook.h"

#include "CGameClient.h"
#include "CResourceManager.h"
#include "CGenericModel.h"
#include "CEquipment.h"
#include "CItemSaveState.h"
#include "CTriggerUnit.h"
#include "CBreakable.h"
#include "CDamageShape.h"
#include "CDieMenu.h"
#include "CPlayer.h"
#include "CMonster.h"
#include "CAstarPathfinder.h"
#include "CGameGlobals.h"
#include "CEffectGroupManager.h"
#include "CMasterResourceManager.h"
#include "CGame.h"
#include "CMouseManager.h"
#include "CCharacterSaveState.h"
#include "CMainMenu.h"
#include "CGameUI.h"
#include "CEnchantMenu.h"
#include "CLayout.h"
#include "CKeyManager.h"
#include "CItemGold.h"

namespace TLAPI {

  static u32 SeedOffset1 = 0xEB4830;
  static u32 SeedOffset2 = 0xEB4834;
  static u32 SeedOffset3 = 0xEB4838;
  static u32 SeedOffset4 = 0xEB483C;

  static u32* Seed1 = NULL;
  static u32* Seed2 = NULL;
  static u32* Seed3 = NULL;
  static u32* Seed4 = NULL;

  TLFUNC(SetSeedValue0,                         void,         __stdcall,  (u32));
  TLFUNC(SetSeedValue2,                         void,         __stdcall,  (u32));

  TLFUNC(ResourceManagerCreatePlayer,           CPlayer*,     __thiscall, (CResourceManager*, wchar_t*, u32));
  TLFUNC(ResourceManagerCreateMonster,          CMonster*,    __thiscall, (CResourceManager*, u64, u32, bool));
  TLFUNC(LevelCharacterInitialize,              CCharacter*,  __thiscall, (CLevel*, CCharacter*, Vector3*, u32));
  TLFUNC(ResourceManagerCreateCharacterByName,  CCharacter*,  __thiscall, (CResourceManager*, const wchar_t*, const wchar_t*, u32, u32));
  TLFUNC(CharacterSetAlignment,                 void,         __thiscall, (CCharacter*, u32));
  TLFUNC(CharacterSetDestination,               void,         __thiscall, (CCharacter*, CLevel*, float, float));
  TLFUNC(GenericModelGetPosition,               PVOID,        __thiscall, (CGenericModel*, Vector3, u32));
  TLFUNC(CharacterSetAction,                    PVOID,        __thiscall, (CCharacter*, u32));
  TLFUNC(CharacterUseSkill,                     PVOID,        __thiscall, (CCharacter*, u64));
  TLFUNC(LayoutSetPosition,                     void,         __thiscall, (CLayout*, const Vector3));
  TLFUNC(CharacterAddMinion,                    void,         __thiscall, (CCharacter*, CCharacter*));
  TLFUNC(ResourceManagerCreateBaseUnit,         CBaseUnit*,   __thiscall, (CResourceManager*, u64, u32, u32, u32));
  TLFUNC(CharacterUpdateHealth,                 PVOID,        __thiscall, (CCharacter*, float));

  TLFUNC(CharacterSetupSkills,                  void,         __thiscall, (CCharacter*, CDataGroup*, u32));
  TLFUNC(CharacterAddSkill,                     void,         __thiscall, (CCharacter*, wstring*, u32));
  TLFUNC(SkillManagerAddSkill,                  void,         __thiscall, (CSkillManager*, CSkill*, u32, u32));

  TLFUNC(GameClientUpdateSkill,                 PVOID,        __thiscall, (CGameClient*, u64, u32, u32));

  TLFUNC(EquipmentAddStackCount,                PVOID,        __thiscall, (CEquipment*, u32));

  TLFUNC(CharacterStrike,                       PVOID,        __thiscall, (CCharacter*, CLevel*, CCharacter*, PVOID, u32, float, float, u32));

  TLFUNC(PlayerSetAnimation,                    PVOID,        __thiscall, (CPlayer*, u32, bool, float, float, u32));

  TLFUNC(CharacterAttack,                       PVOID,        __thiscall, (CCharacter*));

  TLFUNC(EquipmentInitialize,                   PVOID,    __thiscall, (CEquipment*, CItemSaveState*));
  TLFUNC(ResourceManagerCreateEquipmentItem,   CItem*,    __thiscall, (CResourceManager*, u64, u32, u32, u32));
  TLFUNC(CharacterPickupEquipment,              PVOID,    __thiscall, (CCharacter*, CEquipment*, CLevel*));
  TLFUNC(InventoryAddEquipment,                 PVOID,    __thiscall, (CInventory*, CEquipment*, u32, u32));
  TLFUNC(InventoryRemoveEquipment,              PVOID,    __thiscall, (CInventory*, CEquipment*));
  TLFUNC(LevelDropItem,                         PVOID,    __thiscall, (CLevel*, CItem*, Vector3 &, bool));
  TLFUNC(LevelHideEquipment,                    PVOID,    __thiscall, (CLevel*, CEquipment*, u32));

  TLFUNC(GameClient_ChangeLevel,                PVOID,    __thiscall, (CGameClient*, wstring, s32, u32, u32, wstring, u32));

  TLFUNC(PlayerAddGold,                         PVOID,    __thiscall, (CPlayer*, u32));

  TLFUNC(PlayerLevelUp,                         PVOID,    __thiscall, (CPlayer*));
  TLFUNC(PlayerLevelUpSilent,                   PVOID,    __thiscall, (CPlayer*));

  TLFUNC(CharacterPetawayTimer,                 PVOID,    __thiscall, (CCharacter*, float, CLevel*));

  TLFUNC(TriggerUnitTriggered,                  PVOID,    __thiscall, (CTriggerUnit*, CPlayer*));

  // Check what this is
  TLFUNC(ObjectCreate,                          PVOID,    __thiscall, (PVOID, u64));

  TLFUNC(BreakableTriggered,                    PVOID,    __thiscall, (CBreakable*, CPlayer*));
  TLFUNC(DamageShapeTriggered,                  PVOID,    __thiscall, (CDamageShape*));

  TLFUNC(GameClientGamePaused,                  void,     __thiscall, (CGameClient*));

  TLFUNC(ResourceManagerInitializePlayer,       void,     __thiscall, (CResourceManager*, u32, u32));

  TLFUNC(WndProc,                               LRESULT,  __thiscall, (HWND, UINT, WPARAM, LPARAM));

  // Do these still work?
  TLFUNC(GetPlayer,                             PVOID,    __thiscall, (void));
  TLFUNC(PlayerDied,                            void,     __thiscall, (void));
  TLFUNC(PlayerResurrect,                       void,     __thiscall, (CCharacter*));

  // -------------------------------------------------------------------------------- //
  // In-place definitions

  //TLFUNC(GameClientProcessObjects,           void,     __thiscall, (PVOID, PVOID, PVOID, PVOID));
  TLFUNC(GameClientProcessObjects,              void,     __thiscall, (CGameClient*, float, PVOID, PVOID));

  TLFUNC(MonsterProcessAI,                      PVOID,    __thiscall, (CMonster*, float, u32));
  TLFUNC(MonsterProcessAI2,                     void,     __thiscall, (CMonster*, float, u32, u32));
  TLFUNC(MonsterProcessAI3,                     void,     __thiscall, (CMonster*, u32));
  TLFUNC(MonsterIdle,                           void,     __thiscall, (CMonster*, float));
  TLFUNC(MonsterOnHit,                          void,     __thiscall, (CMonster*, CMonster*));

  TLFUNC(MonsterGetCharacterClose,              void,     __thiscall, (CMonster*, float, u32));
    
  TLFUNC(PlayerCtor,                            void,     __thiscall, ());
  TLFUNC(GameClientCtor,                        void,     __thiscall, ());
  TLFUNC(GameCtor,                              void,     __thiscall, ());
  TLFUNC(CharacterDtor,                         void,     __thiscall, ());
  TLFUNC(EquipmentDtor,                         void,     __thiscall, ());

  TLFUNC(PlayerCharacterSetAction,              void,     __thiscall, (CPlayer*));
  
  TLFUNC(GameClientProcessTitleScreen,          void,     __thiscall, (CGameClient*, float, PVOID, PVOID));

  TLFUNC(GameClientLoadMap,                     void,     __thiscall, (CGameClient*, u32));

  TLFUNC(Random,                                void,     __thiscall, ());

  TLFUNC(LevelDestroyMonster,                   void,     __thiscall, (CLevel*, CMonster*));

  TLFUNC(MonsterReadProp,                       void,     __thiscall, (CMonster*));

  TLFUNC(EquipmentUse,                          void,     __thiscall, (CEquipment*, CPlayer*, CPlayer*));
  TLFUNC(EquipmentIdentify,                     void,     __thiscall, (CEquipment*, CPlayer*, CEquipment*));

  TLFUNC(CharacterSetTarget,                    PVOID,    __thiscall, (CCharacter*, CCharacter*));

  TLFUNC(LevelCreateAstarPathfinding,           CAstarPathfinder*,    __stdcall,  (float, float, u32, u32, PVOID, PVOID, float));

  //TLFUNC(EnchantMenu_EnchantItem,               PVOID,    __thiscall, (CEnchantMenu*,));
  TLFUNC(EquipmentGetEnchantPrice,              u32,      __thiscall, (CEquipment*));

  TLFUNC(PlayerRemoveGold,                      void,     __thiscall, (CPlayer*, u32 amount));

  TLFUNC(GetGameGlobals,                        CGameGlobals*, __thiscall, (void));

  TLFUNC(EquipmentEnchant,                      u32,      __thiscall, (CEquipment*, u32, u32, u32));

  TLFUNC(EffectManagerCreateEffect,             CEffect*, __thiscall, (CEffectManager*));

  TLFUNC(EffectManager_AddEffectToEquipment,    void,     __thiscall, (CEffectManager*, CEquipment*, CEffect*));

  TLFUNC(Equipment_AddMagicModifier,            void,     __thiscall, (CEquipment*, u32, u32));

  TLFUNC(EffectGroupManager_CreateAffix,        void,     __thiscall, (CEffectGroupManager*, u32, u32, u32, CList<CAffix*>*));

  TLFUNC(GameClient_SaveGame,                   void,     __thiscall, (CGameClient*, u32, u32, bool*));

  TLFUNC(Equipment_AddAffix,                    void,     __thiscall, (CEquipment*, CAffix*, u32, CEquipment*, float));

  TLFUNC(GetMasterResourceManager, CMasterResourceManager*,__thiscall, (void));

  TLFUNC(GameClient_SetupUI,                    void,     __thiscall, (CGameClient*, u32, u32));
  TLFUNC(Game_CreateUI,                         void,     __thiscall, (CGame*));

  TLFUNC(GameClient_CreateLevel,                void,     __thiscall, (CGameClient*, wstring, wstring, u32, u32, u32, wstring));
  TLFUNC(GameClient_LoadLevel,                  void,     __thiscall, (CGameClient*));

  TLFUNC(MouseManagerInput,                     void,     __thiscall, (CMouseManager*, u32, u32));

  TLFUNC(CharacterSaveState_LoadFromFile,       void,     __thiscall, (CCharacterSaveState*, PVOID, u32));

  TLFUNC(MainMenu_Event,                        void,     __thiscall, (CMainMenu*, u32, wstring));

  TLFUNC(Equipment_UpdateRequirements,          void,     __thiscall, (CEquipment*));
  TLFUNC(Equipment_UpdatePrice,                 void,     __thiscall, (CEquipment*));

  TLFUNC(GameUI_TriggerPause,                   void,     __thiscall, (CGameUI*));

  TLFUNC(Equipment_AddGem,                      void,     __thiscall, (CEquipment*, CEquipment*));

  TLFUNC(EnchantMenu_EnchantItem,               void,     __thiscall, (CEnchantMenu*));

  TLFUNC(GameUI_HandleKeyboardInput,            void,     __thiscall, (CGameUI*, u32, u32, u32));

  TLFUNC(KeyManager_InjectKey,                  void,     __thiscall, (CKeyManager*, u32, u32));

  TLFUNC(GameUI_WindowResized,                  void,     __thiscall, (CGameUI*));

  TLFUNC(Character_Update,                      void,     __thiscall, (CCharacter*));
  TLFUNC(Character_Update_Level,                void,     __thiscall, (CCharacter*, CLevel*, float));
  TLFUNC(Character_Update_Character,            void,     __thiscall, (CCharacter*, CCharacter*));

  TLFUNC(Character_SetOrientation,              void,     __thiscall, (CCharacter*, Vector3*, float));

  TLFUNC(TriggerUnit_Ctor,             CTriggerUnit*,     __thiscall, (CLayout*));

  TLFUNC(ItemGold_Ctor,                   CItemGold*,     __thiscall, (PVOID, CResourceManager*, u32));

  TLFUNC(Level_CharacterKilledCharacter,        void,     __thiscall, (CLevel*, CCharacter*, CCharacter*, Vector3*, u32));

  TLFUNC(Level_Dtor,                            void,     __thiscall, (CLevel*, u32));
  TLFUNC(Level_Ctor,                            void,     __thiscall, (wstring name, CSettings*, CGameClient*, CResourceManager*, PVOID OctreeSM, CSoundManager*, u32, u32));

  TLFUNC(EquipmentRef_Dtor,                     void,     __thiscall, (CEquipmentRef*, u32));

  TLFUNC(Level_Update,	                        void,     __thiscall, (CLevel*, Vector3*, u32, float));

  TLFUNC(Effect_Effect_Something,               void,     __thiscall, (CEffect*, CEffect*));

  TLFUNC(Level_Cleanup,                         void,     __thiscall, (CLevel*, u32, u32));
  
  TLFUNC(Player_KillMonsterExperience,          void,     __thiscall, (CCharacter*, CLevel*, CCharacter*, u32, u32));

  TLFUNC(Character_Killed,                      void,     __thiscall, (CCharacter*, CCharacter*, Ogre::Vector3*, float, u32));

};
