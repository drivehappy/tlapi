#pragma once

#include "CRunicCore.h"

namespace TLAPI {

#pragma pack(1)

  struct CSoundManager : CRunicCore
  {
    u32 unk1;   // 1
    u32 unk2;   // 1
    PVOID pUnkStruct;   // ptr to unknown structure
    float x;
    float y;
    float z;
  };

#pragma pack()

};
