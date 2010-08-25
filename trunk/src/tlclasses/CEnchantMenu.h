#pragma once

#include "CSubMenu.h"

namespace TLAPI {

#pragma pack(1)

  struct CEnchantMenu : CSubMenu
  {
    u32    EnchantType;
    u32    unk11[32];

    
    // Enchant
    EVENT_DECL(CEnchantMenu, void, EnchantMenu_EnchantItem,
      (CEnchantMenu*, bool&),
      ((CEnchantMenu*)e->_this, e->calloriginal));


  };

#pragma pack()

};
