#pragma once

#include "CBaseObjectDescriptor.h"

namespace TLAPI
{

#pragma pack(1)

  struct CLogicTimerDescriptor : CBaseObjectDescriptor
  {
    u32       unk3[4];
    CList<CLogicTimer*>     timerList;

    u32       unk4[4];
    CList<CLogicWrapper*>   wrapperList;
    CList<CLogicWrapper*>   wrapperList2;
  };

#pragma pack()

};
