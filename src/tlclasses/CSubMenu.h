#pragma once

#include "CRunicCore.h"

namespace TLAPI {

#pragma pack(1)

  struct CGameUI;

  //
  // Unsure of the breakoff on the derived classes here
  struct CSubMenu : CRunicCore
  {
    PVOID unk0;
    PVOID vtable_iInventoryListener;

    PVOID CEGUISheetPropertySet[7];

    //PVOID CEGUIPushButton;
    //CCharacter *npc;

    CPlayer    *player;
    CLevel     *level;

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
  };

#pragma pack()

};

