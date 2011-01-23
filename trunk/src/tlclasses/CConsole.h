#pragma once

#include "CResourceManager.h"

// Size?:
// 
struct CConsole : CRunicCore
{
  u32 unk0;
  PVOID pGUISheet;    // ptr to CEGUI GUISheet

  u32 unk1[8];

  CResourceManager *pCResourceManager;
};
