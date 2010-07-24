#pragma once

#include "CEditorBaseObject.h"

namespace TLAPI {

#pragma pack(1)

  struct CSkipCutscene : CEditorBaseObject
  {
    PVOID unk1;

    CSkipCutsceneDescriptor   *pCSkipCutsceneDescriptor;

    CString *name;      // "skipCutscene"


  };

#pragma pack()

};

