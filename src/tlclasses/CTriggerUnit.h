#pragma once

#include "CItem.h"

namespace TLAPI {

#pragma pack(1)

  //
  struct CTriggerUnit : CItem
  {
    // TODO


    // TriggerUnit Triggered
    EVENT_DECL(CTriggerUnit, void, TriggerUnitTriggered,
      (CTriggerUnit*, CPlayer*, bool&),
      ((CTriggerUnit*)e->_this, (CPlayer*)Pz[0], e->calloriginal));

  };

#pragma pack()

};
