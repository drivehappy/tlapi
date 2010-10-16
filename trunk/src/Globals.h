#pragma once

#include "Common.h"

namespace TLAPI {

  class _GLOBAL {
    // WndProc
    EVENT_DECL(_GLOBAL, void, WndProc,
      (HWND, UINT, WPARAM, LPARAM),
      ((HWND)Pz[1], (UINT)Pz[2], (WPARAM)Pz[3], (LPARAM)Pz[4]));

    // SetSeedValue0
    EVENT_DECL(_GLOBAL, void, SetSeedValue0,
      (u32, bool&),
      (Pz[0], e->calloriginal));

    // SetSeedValue2
    EVENT_DECL(_GLOBAL, void, SetSeedValue2,
      (u32, bool&),
      (Pz[0], e->calloriginal));


    /*
    static void SetSeed0(u32 seed)
    {
      SetSeedValue0(seed);
    }
    */
  };

};
