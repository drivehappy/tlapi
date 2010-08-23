#pragma once

#include "CSubMenu.h"

namespace TLAPI {

#pragma pack(1)

  struct CEnchantMenu : CSubMenu
  {
    u32    unk10[2];
    u32    EnchantType;

    
    // Enchant
    EVENT_DECL(CEnchantMenu, void, EnchantMenu_EnchantItem,
      (CEnchantMenu*),
      ((CEnchantMenu*)e->_this));


  };

#pragma pack()

};

