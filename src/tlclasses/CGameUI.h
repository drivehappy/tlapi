#pragma once

#include "CRunicCore.h"
#include "CSettings.h"

namespace TLAPI
{

#pragma pack(1)

  struct CGameUI : CRunicCore
  {
    PVOID unk0;             // TODO -- vtable?? if so remove (defined in CRunicCore)
    PVOID pOctreeSM[4];     // 4 ptrs to Octrees
    PVOID pCSoundManager;   // ptr to CSoundManager
    PVOID pCPlayer;         // ptr to CPlayer

    u32   unk1[7];

    CSettings*    pCSettings;

  };

#pragma pack()

};
