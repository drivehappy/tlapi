#pragma once

#include "CEGUI.h"

#include "CRunicCore.h"
#include "CSettings.h"
#include "CPlayer.h"

namespace TLAPI
{

#pragma pack(1)

  struct CGameUI : CRunicCore
  {
    PVOID unk0;             // TODO -- vtable?? if so remove (defined in CRunicCore)
    PVOID pOctreeSM[4];     // 4 ptrs to Octrees
    PVOID pCSoundManager;   // ptr to CSoundManager
    CPlayer* pCPlayer;         // ptr to CPlayer

    u32   unk1[7];

    CSettings*    pCSettings;

    u32   unk2[1473];       // A lot of stuff I haven't looked at yet

    CEGUI::Rect   rectLeftPaneBlocker;
    CEGUI::Rect   rectRightPaneBlocker;
    CEGUI::Rect   rectPetHudBlocker;
    CEGUI::Rect   rectBottomBlocker;
    CEGUI::Rect   rectBottom2Blocker;

    //
    // Hook
    EVENT_DECL(CGameUI, void, GameUI_TriggerPause,
      (CGameUI*, bool&),
      ((CGameUI*)e->_this, e->calloriginal));


    void dumpGameUI() {
      log("CGameUI(%p) dump:", this);

      log("rectLeftPaneBlocker: %f, %f, %f, %f",
        rectLeftPaneBlocker.d_left,
        rectLeftPaneBlocker.d_top,
        rectLeftPaneBlocker.d_right,
        rectLeftPaneBlocker.d_bottom);

      log("rectRightPaneBlocker: %f, %f, %f, %f",
        rectRightPaneBlocker.d_left,
        rectRightPaneBlocker.d_top,
        rectRightPaneBlocker.d_right,
        rectRightPaneBlocker.d_bottom);
      
      log("rectPetHudBlocker: %f, %f, %f, %f",
        rectPetHudBlocker.d_left,
        rectPetHudBlocker.d_top,
        rectPetHudBlocker.d_right,
        rectPetHudBlocker.d_bottom);
      
      log("rectBottomBlocker: %f, %f, %f, %f",
        rectBottomBlocker.d_left,
        rectBottomBlocker.d_top,
        rectBottomBlocker.d_right,
        rectBottomBlocker.d_bottom);
      
      log("rectBottom2Blocker: %f, %f, %f, %f",
        rectBottom2Blocker.d_left,
        rectBottom2Blocker.d_top,
        rectBottom2Blocker.d_right,
        rectBottom2Blocker.d_bottom);
    }
  };

#pragma pack()

};
