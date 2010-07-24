#pragma once

#include "CRunicCore.h"

namespace TLAPI {

#pragma pack(1)

  struct CCollisionModel : CRunicCore
  {
    u32 unk0;
    u32 unk1;
    PVOID pStringMediaLevelsets;    // ptr string "MEDIA/LEVELSETS/PROPS/MINE_PROPS/COLLISION_WOOD_ARM.MESH"
  };

#pragma pack()

};

