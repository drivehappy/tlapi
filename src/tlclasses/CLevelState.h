#pragma once

#include "CLevelState.h"

namespace TLAPI
{

#pragma pack(1)

  struct CLevelState : CRunicCore
  {
    u32 unk0[3];    // 0,1,0

    CString name;

    PVOID unk1;
  };

#pragma pack()

};
