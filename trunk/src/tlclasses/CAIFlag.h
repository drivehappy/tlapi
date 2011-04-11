#pragma once

#include "CRunicCore.h"

namespace TLAPI {

#pragma pack(1)

  struct CAIFlagManager;

  struct CAIFlag : CRunicCore
  {
    u32               unk0;
    float             unk1;
    CAIFlagManager   *pCAIFlagManager;  // Ptr to CAIFlagManager parent
    u32               unk2[4];            
  };

#pragma pack()

};
