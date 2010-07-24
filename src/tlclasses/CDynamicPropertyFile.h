#pragma once

#include "CRunicCore.h"


namespace TLAPI {

#pragma pack(1)

  struct CDynamicPropertyFile : CRunicCore
  {
    PVOID unk0;
    PVOID unk1;
    CString pStringUserDirectory;

    // TODO
  };

#pragma pack()

};
