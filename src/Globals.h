#pragma once

#include "Common.h"

namespace TLAPI {

  class _GLOBAL {
    EVENT_DECL(_GLOBAL, void, WndProc, (HWND, UINT, WPARAM, LPARAM), ((HWND)Pz[1], (UINT)Pz[2], (WPARAM)Pz[3], (LPARAM)Pz[4]));
  };

};
