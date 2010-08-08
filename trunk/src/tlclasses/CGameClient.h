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
#include "CDungeon.h"

#include <vector>
using std::vector;


namespace TLAPI
{

  // 
#pragma pack(1)

  struct CGameClient;
  TLFUNC(GameClient_LoadLevel, void,  __thiscall, (CGameClient*));


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
    u32                 unkChunk2[14];

    CLayout            *pCLayout;           // @FA8

    u32                 unkChunk4[10];

    s32                 level;              // Level change parameter, listed below
    s32                 levelUnk;              //

    u32                 unkChunk3[1300];

    CDungeon           *pCDungeon;

    /*
      here's what I've found for Level Loads: 
      [CGameClient + 0xFD4] is the relative level int set before LoadLevel (0x4197E0) is called From a Dungeon:
        0   - Returns player to same dungeon
        -1  - Ascends a level
        1   - Descends a level
        -99 - Places player in town, just as a TP would've been taken 

      From Town:
        0   - Drops player into First Level (this is the same for the Quest dungeons and random Mines, I don't know what differentiates these yet)
        -99 - Returns player to last dungeon (just as a TP would've been taken) 

      The -99 from town is special, it's not the last dungeon per se, but the last dungeon flagged with the TP in it So if I drop a TP in Level1,
      goto Level 2, pop into Town with -99 and pop back with -99 it sets me to Level1, not Level2 
    */

    // 
    // Function hooks
    EVENT_DECL(CGameClient, void, GameClientLoadMap,
      (PVOID, CGameClient*, u32),
      ((PVOID)e->retval, (CGameClient *)e->_this, Pz[0]));

    EVENT_DECL(CGameClient, void, GameClientProcessObjects,
      (CGameClient*, float, PVOID, PVOID),
      ((CGameClient *)e->_this, *(float*)&Pz[0], (PVOID)Pz[1], (PVOID)Pz[2]));

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

    EVENT_DECL(CGameClient, void, GameClient_LoadLevel,
      (CGameClient*),
      ((CGameClient*)e->_this));


    // Change level
    void ChangeLevel(u32 relativeLevel) {
      this->level = relativeLevel;
      GameClient_LoadLevel(this);
    }
    
  public:
    void GameClientLoadMap(u32 unk);
  };

#pragma pack()

};
