#pragma once

#include "CRunicCore.h"
#include "_CList.h"

namespace TLAPI
{

#pragma pack(1)

  struct CSpawnClass : CRunicCore
  {
    PVOID           unk0;
    CList<PVOID>    listUnk;
    u32             unk1;
    CString         spawnName;      // "GOBLIN_TREASURE"
    u32             unk2[3];
  };

#pragma pack()

};
