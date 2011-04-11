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
  TLFUNC(GameClient_LoadLevel,          void,   __thiscall, (CGameClient*));
  TLFUNC(GameClientProcessTitleScreen,  void,   __thiscall, (CGameClient*, float, PVOID, PVOID));
  TLFUNC(GameClient_ChangeLevel,        PVOID,  __thiscall, (CGameClient*, wstring, s32, u32, u32, wstring, u32));
  TLFUNC(GameClient_LoadMap,            void,   __thiscall, (CGameClient*, u32, u32));

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
    s32                 levelAbsolute;           //

    // ^ 1006 *4

    // @23 *4 + 1 = GameClient LoadingLevel flag?
    u32                 unkChunk3[14];    //

    u8                  unkFlag3;
    u8                  flagLevelLoading;      /// Should be @1015h
    u8                  unkFlag1;
    u8                  unkFlag2;

    u32                 unkChunk5[1284];    //

    u32                 inGame;             // @2314  

    CDungeon           *pCDungeon;          // @90Bh - This is correct

    u32                 unk200[10];

    u32                 difficulty;         // 0 - EASY, 1 - MEDIUM, 2 - HARD, 3 - VERY HARD

    u32                 unk201[0x1B11];     // Unknown chunk, haven't looked at this

    u8                  inGame2;            // @2428h - This is correct
    u8                  unk202[3];          //   bool padding
    

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

    EVENT_DECL(CGameClient, void, GameClient_LoadMap,
      (CGameClient*, u32, u32, bool&),
      ((CGameClient *)e->_this, Pz[0], Pz[1], e->calloriginal));

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

    EVENT_DECL(CGameClient, void, GameClientGamePaused,
      (bool&, CGameClient*, bool&),
      ((bool &)e->retval, (CGameClient*)e->_this, e->calloriginal));

    EVENT_DECL(CGameClient, void, GameClient_ChangeLevel,
      (CGameClient*, wstring, s32, u32, u32, wstring, u32, bool&),
      ((CGameClient*)e->_this, *(wstring*)&Pz[0], Pz[7], Pz[8], Pz[9], *(wstring*)&Pz[10], Pz[17], e->calloriginal));




    // Change level
    void LoadGameMap(u32 unk0, u32 unk1) {
      GameClient_LoadMap(this, unk0, unk1);
    }
    void ForceToTown() {
      GameClient_ChangeLevel(this, L"TOWN", 0, 0, 1, L"", 0);
    }
    void ChangeLevel(wstring dungeonName, s32 relativeLevel, u32 unk0, u32 unk1, wstring unkString, u32 unk2) {
      GameClient_ChangeLevel(this, dungeonName, relativeLevel, unk0, unk1, unkString, unk2);
    }
  };

#pragma pack()

};
