#pragma once

#include "CRunicCore.h"


namespace TLAPI {

#pragma pack(1)

  struct CCollisionList : CRunicCore
  {
    PVOID unk0;

    float unk1[9];    //

    PVOID unk2;       // List of floats?
    PVOID unk3;       // Another list of floats?
  };

#pragma pack()

};
