#pragma once

#include "CRunicCore.h"


namespace TLAPI {

#pragma pack(1)

  struct CTimerStatics : CRunicCore
  {
    u32 unk0;       // 0
    PVOID unk1;
    u32 unk2[5];    // 0,0,2,0,3
  };

#pragma pack()

};

