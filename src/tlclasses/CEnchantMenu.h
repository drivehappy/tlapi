#pragma once

#include "CSubMenu.h"

namespace TLAPI {

#pragma pack(1)

  struct CEnchantMenu : CSubMenu
  {
    CEGUI::PushButton* window;

    CCharacter *character;
    CPlayer    *player;

    u8          isMenuVisible;
    u8          unk01[3];

    CSettings  *settings;
    CGameUI    *gameUI;

    PVOID              pOctreeSM;
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

    u32    EnchantType;
    u32    unk11[32];

    
    // Enchant
    EVENT_DECL(CEnchantMenu, void, EnchantMenu_EnchantItem,
      (CEnchantMenu*, bool&),
      ((CEnchantMenu*)e->_this, e->calloriginal));


  };

#pragma pack()

};

