#pragma once

#include "CRunicCore.h"

namespace TLAPI {

#pragma pack(1)

  struct CStringTranslate : CRunicCore
  {
    PVOID unk0;
    PVOID *ptrtomyself;       // Cyclic ptr that points to myself
  };

#pragma pack()

};
