#pragma once

#include "CRunicCore.h"

namespace TLAPI {

#pragma pack(1)

  struct CLogicWrapper : CRunicCore
  {
    u32 unk0;
    PVOID pCUnitSpawnerDescriptor;  // ptr to CUnitSpawnerDescriptor
  };

#pragma pack()

};
