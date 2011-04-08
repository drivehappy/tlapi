#pragma once

#include "CSubMenu.h"

namespace TLAPI {

#pragma pack(1)

  struct CGameUI;

  // Size: 7ED8h
  //   From: 55E0E4h
  struct CInventoryMenu : CSubMenu
  {
    CPlayer    *player;
    CLevel     *level;

    u8          isMenuVisible;
    u8          unk01[3];

    CSettings  *settings;
    CGameUI    *gameUI;

    u32                slotSelected;      // Mouse event for selected slot when picking up/dropping
    PVOID              unk1;
    u32                unk2;
    CGenericModel     *pCGenericModel;
    CResourceManager  *pCResourceManager;

    u32 unk3;

    PVOID  pCSoundBank;
    u32 unk4[2];      // Eh, 0
    
    PVOID  pCEGUISheet[4];

    u32 unk5[3];

    PVOID  unk6;

    PVOID  pCEGUISheet2;

    u32    unk7;

    u32               unk100[0x1EAC];

    CEGUI::Checkbox  *weaponSwapCheckBox;       //@7B38h 
    PVOID             pCSkillTooltip;
    
    u8                equipmentTabSelected;     //@7B40h 
    u8                spellTabSelected;         //@7B41h
    u8                fishTabSelected;          //@7B42h
    u8                unk101;


    //
    EVENT_DECL(CInventoryMenu, void, InventoryMenu_OpenClose,
      (CInventoryMenu*, bool, bool&),
      ((CInventoryMenu*)e->_this, (bool)Pz[0], e->calloriginal));

    EVENT_DECL(CInventoryMenu, void, InventoryMenu_MouseEvent,
      (CInventoryMenu*, const CEGUI::MouseEventArgs*, bool&),
      ((CInventoryMenu*)e->_this, (const CEGUI::MouseEventArgs*)Pz[0], e->calloriginal));
  };

#pragma pack()

};
