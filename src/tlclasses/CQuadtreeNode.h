#pragma once

#include "CRunicCore.h"

namespace TLAPI {

#pragma pack(1)

  struct CQuadtreeNode : CRunicCore
  {
    float positions[7];   // 0,  69, 11, 111, -57, -10, -16   (missing dec #s)

    u32 unk0;             // 1

    PVOID pCQuadtreeNode; // probably some sort of Linked list struct, next node
  };

#pragma pack()

};
