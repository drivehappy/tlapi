#pragma once

#include "CRunicCore.h"

namespace TLAPI {

#pragma pack(1)

  struct CGameUI;

  //
  // Unsure of the breakoff on the derived classes here
  // This is an abstract class
  struct CSubMenu : CRunicCore
  {
    PVOID unk0;
    PVOID vtable_iInventoryListener;

    PVOID CEGUISheetPropertySet[7];
  };

#pragma pack()

};

