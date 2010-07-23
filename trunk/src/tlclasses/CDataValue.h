#pragma once

#include "CRunicCore.h"

namespace TLAPI
{

#pragma pack(1)

  struct CDataValue : CRunicCore
  {
    u32   unk0[3];  // 0, 0, 0
    float unk1;     // 350.0
    u32   unk2[2];  // 0, 7D8Dh

    PVOID unk3;     // Unk
    u32   unk4;     // 2


    void dumpValues() {
      logColor(B_RED, "       %x %x %x %f %x %x %p %x", unk0[0], unk0[1], unk0[2], unk1, unk2[0], unk2[1], unk3, unk4);
    }
  };

#pragma pack()

};

