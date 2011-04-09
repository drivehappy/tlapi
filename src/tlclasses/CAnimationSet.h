#pragma once

#include "CRunicCore.h"

namespace TLAPI
{

#pragma pack(1)

  // Size: 74h
  struct CAnimationSet : CRunicCore
  {
    u32       unk0[2];  // 0, 2
    wstring   animationFile;
  };

#pragma pack()

};
