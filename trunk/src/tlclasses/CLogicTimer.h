#pragma once

#include "CEditorBaseObject.h"

namespace TLAPI {

#pragma pack(1)

  struct CLogicTimer : CEditorBaseObject
  {
    PVOID unk0;

    CLogicTimerDescriptor   *pCLogicTimerDescriptor;
  };

#pragma pack()

};
