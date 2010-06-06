#pragma once

#include "CLevel.h"
#include "CHierarchy.h"
#include "CGameClient.h"

// 
struct CResourceManager : CRunicCore
{
  u32 unk0;

  PVOID         pOctreeSM;      // ptr to Octree scenemanager
  CLevel       *pCLevel;        // ptr to CLevel
  CHierarchy   *pCHierarchy;    // ptr to CHierarchy
  CGameClient **ppCGameClient; // ptr ptr to CGameClient

  u32 unk1[4];

};
