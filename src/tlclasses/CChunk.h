#pragma once

#include "CRunicCore.h"

namespace TLAPI
{

#pragma pack(1)

  struct CChunk : CRunicCore
  {
    u32 unk0[5];    // 0,2,1,1,0

    PVOID pStringMediaLayout;   // ptr string = "MEDIA/LAYOUTS/MINE/1X1ENTRANCE_N/1X1_ENTRANCE_N_PB_A.LAYOUT"
  };

#pragma pack()

};

