#pragma once

#include "Common.h"

#include "CCameraControl.h"
#include "CSoundManager.h"
#include "CSettings.h"
#include "CPlayer.h"
#include "CMonster.h"
#include "CQuestManager.h"
#include "CLevel.h"
#include "CGameUI.h"
#include "CMouseManager.h"

#include <vector>
using std::vector;


namespace TLAPI
{

  // 
#pragma pack(1)

  struct CGameClient : CRunicCore
  {
    PVOID vtableOgre_RenderTargetListener;
    PVOID vtableOgre_RenderQueue_RenderableListener;

    CCameraControl     *pCCameraControl;

    PVOID               pOctreeSM0;
    PVOID               pOctreeSM1;
    PVOID               pOctreeSM2;
    PVOID               pOctreeSM3;
    PVOID               pOctreeSM4;

    CSoundManager      *pCSoundManager;
    CSettings          *pCSettings;
    CPlayer            *pCPlayer;
    CMonster           *pPet;

    CQuestManager      *pCQuestManager;
    CLevel             *pCLevel;
    CGameUI            *pCGameUI;

    u32                 unkChunk[963];
    CMouseManager       CMouseManager;      // Not a pointer (offset: 979*4)
    u32                 unkChunk2[33];

    s32                 level;              // ??

    // 
    // Function hooks
    EVENT_DECL(CGameClient, void, GameClientLoadMap,
      (PVOID, CGameClient*, u32),
      ((PVOID)e->retval, (CGameClient *)e->_this, Pz[0]));

    EVENT_DECL(CGameClient, void, GameClientProcessObjects,
      (CGameClient*, PVOID, PVOID, PVOID),
      ((CGameClient *)e->_this, (PVOID)Pz[0], (PVOID)Pz[1], (PVOID)Pz[2]));

    EVENT_DECL(CGameClient, void, GameClient_SaveGame,
      (CGameClient*, u32, u32, bool&),
      ((CGameClient*)e->_this, Pz[0], Pz[1], e->calloriginal));

    EVENT_DECL(CGameClient, void, GameClient_SetupUI,
      (CGameClient*, u32, u32),
      ((CGameClient*)e->_this, Pz[0], Pz[1]));
    
    EVENT_DECL(CGameClient, void, GameClient_CreateLevel,
      (CGameClient*,
       u32, u32, u32, CGameClient*, u32, u32,
       u32, u32, u32, u32, u32, u32,
       u32, u32, u32, u32, u32, u32,
       u32, u32, u32, u32, u32, u32),
      ((CGameClient*)e->_this,
       Pz[0], Pz[1], Pz[2], (CGameClient*)Pz[3], Pz[4], Pz[5],
       Pz[6], Pz[7], Pz[8], Pz[9], Pz[10], Pz[11],
       Pz[12], Pz[13], Pz[14], Pz[15], Pz[16], Pz[17],
       Pz[18], Pz[19], Pz[20], Pz[21], Pz[22], Pz[23]));
    
  public:
    void GameClientLoadMap(u32 unk);
  };

#pragma pack()

};
