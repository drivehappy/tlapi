#pragma once

#include "Events.h"

#include "CLevel.h"
#include "CHierarchy.h"
#include "CCharacter.h"

namespace TLAPI
{

  struct CGameClient;
  struct CPlayer;
  struct CLevel;
  struct CCharacter;

#pragma pack(1)

  // Forward decl
  struct CResourceManager;
  TLFUNC(ResourceManagerCreateEquipment, CEquipment*, __thiscall, (CResourceManager*, u64, u32, u32, u32));
  TLFUNC(ResourceManagerCreateCharacter, CCharacter*,  __thiscall, (CResourceManager*, u64, u32, bool));

  // 
  struct CResourceManager : CRunicCore
  {
    u32 unk0;

    PVOID         pOctreeSM;      // ptr to Octree scenemanager
    CLevel       *pCLevel;        // ptr to CLevel
    CHierarchy   *pCHierarchy;    // ptr to CHierarchy
    CGameClient **ppCGameClient; // ptr ptr to CGameClient

    u32 unk1[4];

    // 
    // Function hooks

    // Player Initialization
    EVENT_DECL(CResourceManager, void, ResourceManagerInitializePlayer,
      (CResourceManager*, u32, u32),
      ((CResourceManager*)e->_this, Pz[0], Pz[1]));

    // Character Creation
    EVENT_DECL(CResourceManager, void, ResourceManagerCreateCharacter,
      (CResourceManager*, u64, u32, bool),
      ((CResourceManager*)e->_this, *(u64*)&Pz[0], Pz[2], (bool)Pz[3]));

    // Character Creation by Name
    EVENT_DECL(CResourceManager, void, ResourceManagerCreateCharacterByName,
      (CCharacter*, CResourceManager*, const wchar_t*, const wchar_t*, u32, u32),
      ((CCharacter*)e->retval, (CResourceManager*)e->_this, (const wchar_t*)Pz[0], (const wchar_t*)Pz[1], Pz[2], Pz[3]));

    // Equipment Creation
    EVENT_DECL(CResourceManager, void, ResourceManagerCreateEquipment,
      (CEquipment*, CResourceManager*, u64, u32, u32, u32),
      ((CEquipment*)e->retval, (CResourceManager*)e->_this, *(u64*)&Pz[0], Pz[2], Pz[3], Pz[4]));
    
    // Create Something
    EVENT_DECL(CResourceManager, void, ResourceManagerCreateSomething,
      (PVOID, CResourceManager*, u64, u32, u32, u32),
      ((PVOID)e->retval, (CResourceManager*)e->_this, *(u64*)&Pz[0], Pz[2], Pz[3], Pz[4]));
    

    // Create equipment
    CEquipment* CreateEquipment(u64 guid, u32 unk0, u32 unk1, u32 unk2) {
      return ResourceManagerCreateEquipment(this, guid, unk0, unk1, unk2);
    }
    // Create Character
    CCharacter* CreateCharacter(u64 guid, u32 level, bool unk) {
      return ResourceManagerCreateCharacter(this, guid, level, unk);
    }
  };

#pragma pack()

};
