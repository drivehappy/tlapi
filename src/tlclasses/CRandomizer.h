#pragma once

#include "CRunicCore.h"
#include "_CList.h"

namespace TLAPI {

#pragma pack(1)

  struct CRandomizer : CRunicCore
  {
    PVOID unk0;

    CList<u32>      UnkList2;   // 0.0
    CList<float>    UnkList3;   // 1.0
    CList<float>    UnkList4;   // 1.0

    u32 unk4[3];

    // Below this appears to be holding the Color values from globals.dat
    // i.e. the value of RANDOMENCHANT_COLOR
    //
  };

#pragma pack()

};
