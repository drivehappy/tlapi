#pragma once

#include "CDropdownMenu.h"

namespace TLAPI
{

  // 
#pragma pack(1)

  struct CMainMenu : CDropdownMenu
  {
    
    EVENT_DECL(CMainMenu, void, MainMenu_Event,
      (CMainMenu*, u32, wstring, bool&),
      ((CMainMenu *)e->_this, Pz[0], *(wstring*)&Pz[1], e->calloriginal));

  };

#pragma pack()

};
