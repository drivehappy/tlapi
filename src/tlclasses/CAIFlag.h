#pragma once

#include "CRunicCore.h"

namespace TLAPI {

#pragma pack(1)

  struct CAIFlag : CRunicCore
  {
    u32 unk0;
    u32 unk1;
    PVOID pCAIFlagManager;  // Ptr to CAIFlagManager
    u32 unk2[4];            
  };

#pragma pack()

};
