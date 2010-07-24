#pragma once

#include "CRunicCore.h"

namespace TLAPI {

#pragma pack(1)

  struct CSoundBank : CRunicCore
  {
    u32 unk0;
    PVOID pCSoundManager;   // ptr to CSoundManager
  };

#pragma pack()

};

