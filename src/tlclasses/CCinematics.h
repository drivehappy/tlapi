#pragma once

#include "_CString.h"
#include "_CList.h"
#include "CRunicCore.h"

namespace TLAPI {

#pragma pack(1)

  struct CCinematics : CRunicCore
  {
    PVOID unk0;
    PVOID unk1;

    CString location;   // "media/cinematics/"

    CList<PVOID>     CinematicsList;

    // Unk rest
  };

#pragma pack()

};
