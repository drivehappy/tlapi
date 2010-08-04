#pragma once

#include "CPositionableObjectDescriptor.h"
#include "CDescriptorProp.h"
#include "CLogicWrapper.h"

namespace TLAPI
{

#pragma pack(1)

  struct CMonsterDescriptor : CPositionableObjectDescriptor
  {
    u32 unk11[4];       // 0, 0, 0, 0Ah

    CList<CMonster *>           CMonsterList;
    
    u32 unk12[4];       // 0, 0, 0, 0Ah

    CList<CLogicWrapper *>      CLogicWrapper0;
    CList<CLogicWrapper *>      CLogicWrapper1;
  };

#pragma pack()

};
