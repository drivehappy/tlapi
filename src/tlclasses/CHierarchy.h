#pragma once

#include "CRunicCore.h"

namespace TLAPI
{

#pragma pack(1)

  struct CHierarchy : CRunicCore
  {
    PVOID unk0;

    PVOID *ptrtomyself;     // Cyclic ptr to point to myself
  };

#pragma pack()

};
