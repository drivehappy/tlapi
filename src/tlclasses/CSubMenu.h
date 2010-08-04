#pragma once

#include "CRunicCore.h"

namespace TLAPI {

#pragma pack(1)

  struct CSubMenu : CRunicCore
  {
    PVOID unk0;
    PVOID vtable_iInventoryListener;
    PVOID CEGUISheetPropertySet[7];

    CPlayer   *player;
    CLevel    *level;
    u32        unk1;
    CSettings *settings;
    CGameUI   *gameUI;
  };

#pragma pack()

};

