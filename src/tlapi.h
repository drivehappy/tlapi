#pragma once

#include "Helper.h"

#include "CGameClient.h"

namespace TLAPI {
  
  void Initialize();
  
  void PatchProcess();
  void HookFunctions();

  CGameClient* GetGameClient();

};
