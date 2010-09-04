#pragma once

#include "CItem.h"

namespace TLAPI {

#pragma pack(1)

  //
  struct CTriggerUnit;
  TLFUNC(TriggerUnitTriggered, PVOID, __thiscall, (CTriggerUnit*, CPlayer*));

  //
  struct CTriggerUnit : CItem
  {
    // TODO


    // TriggerUnit Triggered
    EVENT_DECL(CTriggerUnit, void, TriggerUnitTriggered,
      (CTriggerUnit*, CPlayer*, bool&),
      ((CTriggerUnit*)e->_this, (CPlayer*)Pz[0], e->calloriginal));

  
    void Trigger(CPlayer *player) {
      TriggerUnitTriggered(this, player);
    }

  };

#pragma pack()

};
