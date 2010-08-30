#pragma once

#include "CEditorBaseObject.h"

namespace TLAPI
{

#pragma pack(1)

  // Size?: 30h
  struct CTimeline : CEditorBaseObject
  {
    u32 unk1;

    PVOID pCTimelineDescriptor;
  };

#pragma pack()

};

