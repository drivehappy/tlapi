#pragma once

#pragma comment(lib, "../externallibs/cegui/lib/CEGUIBase.lib")

#include "Helper.h"

#include "CGameClient.h"
#include "CPlayer.h"

namespace TLAPI {
  
  void Initialize();
  
  void PatchProcess();
  void HookFunctions();

  CGameClient* GetGameClient();

};
