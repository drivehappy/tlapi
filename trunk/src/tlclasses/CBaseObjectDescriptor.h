#pragma once

#include "CDescriptor.h"
#include "CDescriptorProp.h"

namespace TLAPI
{

#pragma pack(1)

  struct CBaseObjectDescriptor : CDescriptor
  {
    u32       unk0[2];    // 0 0
    wstring   unkString;  // null
    u32       unk1[3];    // Ptr, 0, 0
    wstring   stringType; // "Timer"
    wstring   stringDescription;  // "Timer ticks down when enabled"
    wstring   stringType2;  // "clock"
    wstring   stringType3;  // "Logic"

    u32       unk2[10];

    CList<CDescriptorProp*>  propList;
  };

#pragma pack()

};

