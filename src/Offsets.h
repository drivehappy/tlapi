#pragma once

#include "DataTypes.h"

#include "CGameClient.h"
#include "CResourceManager.h"
#include "CGenericModel.h"
#include "CEquipment.h"
#include "CItemSaveState.h"
#include "CTriggerUnit.h"
#include "CBreakable.h"
#include "CDamageShape.h"
#include "CDieMenu.h"

namespace TLMP {

  TLFUNC(SpiderSomeCreate,   CCharacter*, __thiscall, (CResourceManager*, u64, u32, bool));
  TLFUNC(EntityInitialize,   CCharacter*, __thiscall, (CLevel*, CCharacter*, Vector3*, u32));
  TLFUNC(CreateUnitByName,   CCharacter*, __thiscall, (CResourceManager*, const wchar_t*, const wchar_t*, u32, u32));
  TLFUNC(SetAlignment,       PVOID,       __thiscall, (CCharacter*, u32));
  TLFUNC(SetDestination,     PVOID,       __thiscall, (CCharacter*, CLevel*, float, float));
  TLFUNC(GetPosition,        PVOID,       __thiscall, (CGenericModel*, Vector3, u32));
  TLFUNC(SetAction,          PVOID,       __thiscall, (CCharacter*, u32));
  TLFUNC(UseSkill,           PVOID,       __thiscall, (CPlayer*, u64));
  TLFUNC(SetPosition,        PVOID,       __thiscall, (CLayout*, const Vector3));
  TLFUNC(AddMinion,          PVOID,       __thiscall, (CCharacter*, CCharacter*));
  TLFUNC(CreateSomething,    PVOID,       __thiscall, (CResourceManager*, u64, u32, u32, u32));

  TLFUNC(SetAttack,          PVOID,       __thiscall, (CCharacter*, PVOID));

  TLFUNC(OnStrike,           PVOID,       __thiscall, (CCharacter*, CLevel*, CCharacter*, PVOID, u32, float, float, u32));

  TLFUNC(SpiderProcessAI,    PVOID,       __thiscall, (CMonster*, float, PVOID));
  TLFUNC(SetAnimation,       PVOID,       __thiscall, (CPlayer*, u32, bool, float, float, u32));

  TLFUNC(DoAttack,           PVOID,       __thiscall, (CPlayer*));

  TLFUNC(ItemInitialize,     PVOID,    __thiscall, (CEquipment*, CItemSaveState*));
  TLFUNC(ItemDrop,           PVOID,    __thiscall, (CLevel*, CEquipment*, Vector3 &, bool));
  TLFUNC(ItemCreate,         PVOID,    __thiscall, (CResourceManager*, u64, u32, u32, u32));
  TLFUNC(ItemPickup,         PVOID,    __thiscall, (CPlayer*, CEquipment*, CLevel*));
  TLFUNC(ItemEquip,          PVOID,    __thiscall, (CInventory*, CEquipment*, u32, u32));
  TLFUNC(ItemUnequip,        PVOID,    __thiscall, (CInventory*, CEquipment*));
  TLFUNC(ItemHide,           PVOID,    __thiscall, (CLevel*, CEquipment*, u32));

  TLFUNC(ChangeLevel,        PVOID,    __thiscall, (CGameClient*, wstring, u32, u32, u32, wstring, u32));

  TLFUNC(AddGoldToPlayer,    PVOID,    __thiscall, (CPlayer*, u32));

  TLFUNC(LevelUp,            PVOID,    __thiscall, (CPlayer*));
  TLFUNC(LevelUpSilent,      PVOID,    __thiscall, (CPlayer*));

  TLFUNC(PetawayTimer,       PVOID,    __thiscall, (CCharacter*, float, CLevel*));

  TLFUNC(InteractWithObject, PVOID,    __thiscall, (CTriggerUnit*, CPlayer*));
  TLFUNC(ObjectCreate,       PVOID,    __thiscall, (PVOID, u64));

  TLFUNC(BarrelDestroy,      PVOID,    __thiscall, (CBreakable*, CPlayer*));
  TLFUNC(BarrelKnockback,    PVOID,    __thiscall, (CDamageShape*));

  TLFUNC(CheckgamePaused,    void,     __thiscall, (CGameClient*));

  TLFUNC(PlayerInitialize,   void,     __thiscall, (CResourceManager*, u32, u32));

  TLFUNC(WndProc,            LRESULT,  __thiscall, (HWND, UINT, WPARAM, LPARAM));

  TLFUNC(GetPlayer,          PVOID,    __thiscall, (void));
  TLFUNC(PlayerDied,         void,     __thiscall, (void));
  TLFUNC(PlayerResurrect,    void,     __thiscall, (CDieMenu*, u32));

  // -------------------------------------------------------------------------------- //
  // In-place definitions

  //TLFUNC(ProcessObjects,     void,     __thiscall, (PVOID, PVOID, PVOID, PVOID));
  TLFUNC(ProcessObjects,     void,     __thiscall, (CGameClient*, PVOID, PVOID, PVOID));

  TLFUNC(MonsterProcessAI2,  void,     __thiscall, (CMonster*, float));
  TLFUNC(MonsterProcessAI3,  void,     __thiscall, (CMonster*, u32));
  TLFUNC(MonsterIdle,        void,     __thiscall, (CMonster*, float));
  TLFUNC(MonsterOnHit,       void,     __thiscall, (CMonster*, CMonster*));
    
  TLFUNC(PlayerCtor,         void,     __thiscall, (PVOID));

  TLFUNC(PlayerSetAction,    void,     __thiscall, (CPlayer*));
  
  TLFUNC(TitleScreenProcess, void,     __thiscall, (CGameClient*, float, PVOID, float, u32));

  TLFUNC(LoadMap,            void,     __thiscall, (CGameClient*, u32));

  TLFUNC(Random,             void,     __thiscall, ());

  TLFUNC(Destroy,            void,     __thiscall, (CLevel*, CMonster*));

  TLFUNC(EntityReadProp,     void,     __thiscall, (CMonster*));

  TLFUNC(UseEquipment,       void,     __thiscall, (CEquipment*, CPlayer*, CPlayer*));
  TLFUNC(IdentifyEquipment,  void,     __thiscall, (CEquipment*));

  //TLFUNCPTR(LoadArea,           void,     __thiscall, (/* 18 */),                                        0x40CF40);

  // ... and add more later

};
