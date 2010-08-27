#pragma once

#include "CRunicCore.h"

namespace TLAPI
{

#pragma pack(1)

  struct CMouseManager : CRunicCore
  {
    u32 unk0[3];

    u8  mouse0;
    u8  unk1;
    u8  unk2;
    u8  mouse1;

    u32 unk3[2];

    u32 positionX;
    u32 positionY;

    // MouseManager HandleInput
    EVENT_DECL(CMouseManager, void, MouseManagerInput,
      (CMouseManager*, u32 wParam, u32 mouseButton, bool& calloriginal),
      ((CMouseManager*)e->_this, Pz[0], Pz[1], e->calloriginal));



    void dumpMouse() {
      log("MouseManager(%p) Dump:", this);
      log("  unk0: %x %x %x", unk0[0], unk0[1], unk0[2]);
      log("  unk3: %x %x", unk3[0], unk3[1]);
      log("  mouse0: %i", mouse0);
      log("  unk1: %x", unk1);
      log("  unk2: %x", unk2);
      log("  mouse1: %i", mouse1);
      log("  Position: %i, %i", positionX, positionY);
    }
  };

#pragma pack()

};
