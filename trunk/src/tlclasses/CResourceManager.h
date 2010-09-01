#pragma once

#include "Events.h"

#include "CRunicCore.h"

namespace TLAPI
{

#pragma pack(1)

  // Forward decl
  struct CGameClient;
  struct CPlayer;
  struct CLevel;
  struct CCharacter;
  struct CHierarchy;
  struct CMonster;
  struct CResourceManager;
  struct CEquipment;
  TLFUNC(ResourceManagerCreateEquipment, CEquipment*, __thiscall, (CResourceManager*, u64, u32, u32, u32));
  TLFUNC(ResourceManagerCreateMonster,   CMonster*,   __thiscall, (CResourceManager*, u64, u32, bool));
  TLFUNC(ResourceManagerCreatePlayer,    CPlayer*,    __thiscall, (CResourceManager*, wchar_t*, u32));

  // 
  struct CResourceManager : CRunicCore
  {
    u32 unk0;

    PVOID         pOctreeSM;            // ptr to Octree scenemanager
    CLevel       *pCLevel;              // ptr to CLevel
    CHierarchy   *pCHierarchy;          // ptr to CHierarchy
    CList<CGameClient*> *pCGameClient;  // CGameClient list

    u32 unk1[4];

    // 
    // Function hooks

    // Player Initialization
    EVENT_DECL(CResourceManager, void, ResourceManagerInitializePlayer,
      (CPlayer*, CResourceManager*, u32, u32),
      ((CPlayer*)e->retval, (CResourceManager*)e->_this, Pz[0], Pz[1]));

    // Player Creation
    EVENT_DECL(CResourceManager, void, ResourceManagerCreatePlayer,
      (CPlayer*, CResourceManager*, wchar_t*, u32, bool&),
      ((CPlayer*)e->retval, (CResourceManager*)e->_this, (wchar_t*)Pz[0], Pz[1], e->calloriginal));

    // Character Creation
    EVENT_DECL(CResourceManager, void, ResourceManagerCreateMonster,
      (CMonster*, CResourceManager*, u64, u32, bool, bool&),
      ((CMonster*)e->retval, (CResourceManager*)e->_this, *(u64*)&Pz[0], Pz[2], (bool)Pz[3], e->calloriginal));

    // Character Creation by Name
    EVENT_DECL(CResourceManager, void, ResourceManagerCreateCharacterByName,
      (CCharacter*, CResourceManager*, const wchar_t*, const wchar_t*, u32, u32),
      ((CCharacter*)e->retval, (CResourceManager*)e->_this, (const wchar_t*)Pz[0], (const wchar_t*)Pz[1], Pz[2], Pz[3]));

    // Equipment Creation
    EVENT_DECL(CResourceManager, void, ResourceManagerCreateEquipment,
      (CEquipment*, CResourceManager*, u64, u32, u32, u32, bool&),
      ((CEquipment*)e->retval, (CResourceManager*)e->_this, *(u64*)&Pz[0], Pz[2], Pz[3], Pz[4], e->calloriginal));
    
    // Create Base Unit
    EVENT_DECL(CResourceManager, void, ResourceManagerCreateBaseUnit,
      (CBaseUnit*, CResourceManager*, u64, u32, u32, u32, bool&),
      ((CBaseUnit*)e->retval, (CResourceManager*)e->_this, *(u64*)&Pz[0], Pz[2], Pz[3], Pz[4], e->calloriginal));
    

    // Create equipment
    CEquipment* CreateEquipment(u64 guid, u32 level, u32 unk1, u32 unk2) {
      return ResourceManagerCreateEquipment(this, guid, level, unk1, unk2);
    }
    // Create Character
    CMonster* CreateMonster(u64 guid, u32 level, bool removeDefaultInventory) {
      return ResourceManagerCreateMonster(this, guid, level, removeDefaultInventory);
    }
    // Create Player
    CPlayer* CreatePlayer(wchar_t* type, u32 unk1) {
      return ResourceManagerCreatePlayer(this, type, unk1);
    }
  };

#pragma pack()

};
