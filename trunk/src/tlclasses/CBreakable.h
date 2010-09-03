#pragma once

#include "CItem.h"

namespace TLAPI {

#pragma pack(1)

  //
  struct CBreakable;
  TLFUNC(BreakableTriggered, PVOID, __thiscall, (CBreakable*, CPlayer*));

  // 
  struct CBreakable : CItem
  {
    // Breakable
    EVENT_DECL(CBreakable, void, BreakableTriggered,
      (CBreakable*, CPlayer*, bool&),
      ((CBreakable*)e->_this, (CPlayer*)Pz[0], e->calloriginal));



    void Break(CPlayer *player) {
      BreakableTriggered(this, player);
    }
  };

#pragma pack()

};
