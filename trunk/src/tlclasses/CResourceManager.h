#pragma once

#include "Events.h"

#include "CLevel.h"
#include "CHierarchy.h"

namespace TLAPI
{

  struct CGameClient;
  struct CPlayer;

#pragma pack(1)

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
    EVENT_DECL(CResourceManager, void, __cdecl, ResourceManagerInitializePlayer, (CResourceManager*, u32, u32), ((CResourceManager*)e->_this, Pz[0], Pz[1]));
    EVENT_DECL(CResourceManager, void, __cdecl, ResouceManagerCreateCharacter, (CResourceManager*, u64, u32, bool), ((CResourceManager*)e->_this, Pz[0], Pz[2], (bool)Pz[3]));

  };

#pragma pack()

};
