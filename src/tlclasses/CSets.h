#pragma once

#include "_CString.h"
#include "CRunicCore.h"


namespace TLAPI {

#pragma pack(1)

  struct CSets : CRunicCore
  {
    PVOID unk0;
    PVOID unk1;

    CString location;   // "media/sets/"

    CList<PVOID>   SetsList;

    // Unk rest
  };

#pragma pack()

};
