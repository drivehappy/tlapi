#pragma once

#include "CItem.h"
#include "CLayout.h"

namespace TLAPI {

#pragma pack(1)

  //
  struct CTriggerUnit;
  TLFUNC(TriggerUnitTriggered, PVOID, __thiscall, (CTriggerUnit*, CPlayer*));
  TLFUNC(TriggerUnit_Ctor, CTriggerUnit*, __thiscall, (CLayout*));

  //
  struct CTriggerUnit : CItem
  {
    // TODO


    // TriggerUnit Ctor
    EVENT_DECL(CTriggerUnit, void, TriggerUnit_Ctor,
      (CTriggerUnit*, CLayout*, bool&),
      ((CTriggerUnit*)e->retval, (CLayout*)e->_this, e->calloriginal));

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
