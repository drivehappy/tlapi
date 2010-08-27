#pragma once

#include "CRunicCore.h"

namespace TLAPI
{

#pragma pack(1)

  struct CKeyManager : CRunicCore
  {

    //
    // Events
    EVENT_DECL(CKeyManager, void, KeyManager_InjectKey,
      (CKeyManager*, u32, u32, bool&),
      ((CKeyManager*)e->_this, Pz[0], Pz[1], e->calloriginal));
  };

#pragma pack()

};
