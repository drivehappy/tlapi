#pragma once

#include "CRunicCore.h"
#include "CLayoutDescriptor.h"

namespace TLAPI {

#pragma pack(1)

  struct CLogicWrapper : CRunicCore
  {
    u32 unk0;
    CLayoutDescriptor *pCLayoutDescriptor;
    u32 unk1;

    wstring name;

    u32 unk2[7];

    CMonster  *pCMonster;
    CMonster **pCMonster2;
    CMonster **pCMonster3;
  };

#pragma pack()

};
