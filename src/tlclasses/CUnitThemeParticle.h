#pragma once

#include "CRunicCore.h"
#include "_CString.h"

namespace TLAPI {

#pragma pack(1)

  struct CUnitThemeParticle : CRunicCore
  {
    PVOID unk0;
    PVOID unk1;

    CString location;      // "media/particles/playerskills/armordebuffeffect.layout"

    // Unk rest if any
  };

#pragma pack()

};
