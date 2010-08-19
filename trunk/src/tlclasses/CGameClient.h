#pragma once

#include "Common.h"
#include "Offsets.h"

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
  TLFUNC(GameClient_LoadLevel, void, __thiscall, (CGameClient*));
  TLFUNC(GameClientProcessTitleScreen, void, __thiscall, (CGameClient*, float, PVOID, PVOID));

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

    CLayout            *pCLayout;           //

    //u32                 unkChunk4[10];
    u32                 unkChunk4[3];
    wstring             dungeonName;

    s32                 level;              // Level change parameter, listed below
    s32                 levelUnk;           //

    u32                 unkChunk3[1299];    //

    u32                 inGame;             // @2314  

    CDungeon           *pCDungeon;          // @2308

    

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
    EVENT_DECL(CGameClient, void, GameClientCtor,
      (CGameClient*),
      ((CGameClient*)e->_this));

    EVENT_DECL(CGameClient, void, GameClientLoadMap,
      (PVOID, CGameClient*, u32, bool&),
      ((PVOID)e->retval, (CGameClient *)e->_this, Pz[0], e->calloriginal));

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
      (CGameClient* client, wstring unk0, wstring unk1, u32 unk2, u32 unk3, u32 unk4, wstring unk5, bool&),
      ((CGameClient*)e->_this, *(wstring*)&Pz[0], *(wstring*)&Pz[7], Pz[14], Pz[15], Pz[16], *(wstring*)&Pz[17], e->calloriginal));

    EVENT_DECL(CGameClient, void, GameClient_LoadLevel,
      (CGameClient*, bool&),
      ((CGameClient*)e->_this, e->calloriginal));

    EVENT_DECL(CGameClient, void, GameClientProcessTitleScreen,
      (CGameClient*, float, PVOID, PVOID),
      ((CGameClient*)e->_this, *(float*)&Pz[0], (PVOID)Pz[1], (PVOID)Pz[2]));


    // Change level
    void ChangeLevel(s32 relativeLevel) {
      this->level = relativeLevel;
      GameClient_LoadLevel(this);
    }
    
  public:
    void GameClientLoadMap(u32 unk);
  };

#pragma pack()

};
