#pragma once

#include "_CString.h"
#include "CRunicCore.h"
#include "CUnitThemeParticle.h"

namespace TLAPI {

#pragma pack(1)

  struct CUnitTheme : CRunicCore
  {
    PVOID     unk0;

    CList<CUnitThemeParticle *>  ParticlesList;

    CString  name;     // "ARMORDEBUFF"
    u32       unk1;
    u64       guid;     // 5F53DD44942A11DEh defined in: ARMORDEBUFF.dat

    float     unk2;     // 26121.625
    u32       unk3;     // 4Bh
  };

#pragma pack()

};
