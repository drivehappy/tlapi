#pragma once

#include "CSubMenu.h"

namespace TLAPI {

#pragma pack(1)

  struct CGameUI;

  //
  struct CInventoryMenu : CSubMenu
  {
    u32               unk100[0x1E9A];

    CEGUI::Checkbox  *checkBox;
    PVOID             pCSkillTooltip;
    
    u8                equipmentTabSelected;     //@7B40h 
    u8                spellTabSelected;         //@7B41h
    u8                fishTabSelected;          //@7B42h
    u8                unk101;


    //
    EVENT_DECL(CInventory, void, InventoryMenu_OpenClose,
      (CInventoryMenu*, bool, bool&),
      ((CInventoryMenu*)e->_this, (bool)Pz[0], e->calloriginal));
  };

#pragma pack()

};
