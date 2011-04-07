#pragma once

#include "CSubMenu.h"

namespace TLAPI {

#pragma pack(1)

  struct CGameUI;

  //
  struct CInventoryMenu : CSubMenu
  { 
    EVENT_DECL(CInventory, void, InventoryMenu_OpenClose,
      (CInventoryMenu*, bool, bool&),
      ((CInventoryMenu*)e->_this, (bool)Pz[0], e->calloriginal));
  };

#pragma pack()

};
