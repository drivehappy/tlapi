#pragma once

#include "CRunicCore.h"

namespace TLAPI {

#pragma pack(1)

  struct CLogicLink : CRunicCore
  {
    PVOID unk0;

    CLayout             *pCLayout;
    CMonsterDescriptor  *pCMonsterDescriptor;
    CLogicObject        *pCLogicObject0;
    CLogicObject        *pCLogicObject1;
    CLogicWrapper       *pCLogicWrapper0;
    CLogicWrapper       *pCLogicWrapper1;

    u32 unk1;
    u32 unk2;
  };

#pragma pack()

};

