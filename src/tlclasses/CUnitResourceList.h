#pragma once

#include "CRunicCore.h"
#include "CResourceSettings.h"

namespace TLAPI
{

#pragma pack(1)

  struct CUnitResourceList : CRunicCore
  {
    PVOID unk0;

    CResourceSettings *pCResourceSettings;

  };

#pragma pack()

};
