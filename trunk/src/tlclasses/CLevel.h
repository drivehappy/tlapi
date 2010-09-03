#pragma once

#include "_CList.h"

#include "CQuadTree.h"
#include "CCollisionList.h"
#include "CCharacter.h"
#include "CResourceManager.h"
#include "CAstarPathFinder.h"
#include "CEquipment.h"
#include "CLevelTemplateData.h"
#include "CAutomap.h"
#include "CChunk.h"
#include "CLevelLayout.h"
#include "CGameClient.h"
#include "CParticle.h"

namespace TLAPI
{

#pragma pack(1)

  // Forward decl
  struct CLayout;
  struct CResourceManager;
  struct CLevel;
  TLFUNC(LevelDropItem, PVOID, __thiscall, (CLevel*, CItem*, Vector3 &, bool));
  TLFUNC(LevelCharacterInitialize, CCharacter*, __thiscall, (CLevel*, CCharacter*, Vector3*, u32));

  //
  struct CLevel : CRunicCore
  {
    u32 unk0;
    
    CList<CLayout*>    CLayoutsList;

    u32 unk1;           // 3
    u32 unk2;           // 0Ah
    u32 unk3;           // 0Ah
    PVOID unk4;         // ptr to unk struct

    u32 unk5;           // 3
    u32 unk6;           // 0Ah
    u32 unk7;           // 0Ah
    PVOID unk8;         // ptr to unk struct
    PVOID unk9;         // ptr to unk struct

    u32 unk10[3];       // 195h, 186h, 3C81h

    CQuadtree          *pCQuadTree;       // ptr to CQuadTree
    CCollisionList     *pCCollisionList;  // ptr to CCollisionList

    vector<u32>        vecUnk0;
    /* Old replaced by vector
    u32 unk11;          // Cylic ptr to itself
    float unk12[2];     // 1, 1
    PVOID unk13[3];     // Odd structure
    */

    PVOID unk14[4];     // Another odd structure

    CList<CParticle*>   particleList;

    PVOID unk18[3];

    vector<u32>        vecUnk1;

    u32   unk19[8];     // 3 dup(   0), 0Ah,3 dup(   0), 0Ah

    vector<u32>        vecUnk2;


    float unk20[22];

                      /*
                                           -31.981001
                      debug293:1E0DE1C8 dd 0.79000199
                      debug293:1E0DE1CC dd 17.153
                      debug293:1E0DE1D0 dd 9.1789999
                      debug293:1E0DE1D4 dd 0.0299982
                      debug293:1E0DE1D8 dd 67.275902
                      debug293:1E0DE1DC dd 27.368999
                      debug293:1E0DE1E0 dd -4.4899998
                      debug293:1E0DE1E4 dd 36.7458
                      debug293:1E0DE1E8 dd 0.54463887
                      debug293:1E0DE1EC dd 0.0
                      debug293:1E0DE1F0 dd 0.83867079
                      debug293:1E0DE1F4 dd 0.0
                      debug293:1E0DE1F8 dd 0.0
                      debug293:1E0DE1FC dd 0.0
                      debug293:1E0DE200 dd 0.0
                      debug293:1E0DE204 dd 0.0
                      debug293:1E0DE208 dd 1.0
                      debug293:1E0DE20C dd 0.0
                      debug293:1E0DE210 dd 0.0
                      debug293:1E0DE214 dd 0.0
                      debug293:1E0DE218 dd 0.0

                      */

    // ...

    u32  unk21[5];

                      /*
                                           7
                      debug293:1E0DE220 dd 0
                      debug293:1E0DE224 dd offset unk_1D000001
                      debug293:1E0DE228 dd 0
                      debug293:1E0DE22C dd 1

                      */

    PVOID   pOctreeSM;
    PVOID   pOgreStaticGeom[4];

    CLevelTemplateData* pCLevelTemplateData;
    CAutomap*           pCAutomap;

    u32     unk22[3];

    CChunk**  ppCChunk;

    u32     unk23[6];

    CLevelLayout*       pCLevelLayout;
    CGameClient*        pCGameClient;

    u32     unk24[2];

    float   unk25[4];

    u32     unk26[12];

    CList<CLayout*>     layoutList;

    float   unk27;      // 40.0

    wstring levelName;




    // 
    // Function hooks

    // Player Initialization
    EVENT_DECL(CLevel, void, LevelCharacterInitialize,
      (CCharacter*, CLevel*, CCharacter*, Vector3*, u32, bool&),
      ((CCharacter*)e->retval, (CLevel*)e->_this, (CCharacter*)Pz[0], (Vector3*)Pz[1], Pz[2], e->calloriginal));
    
    // Create AstarPathFinder - This appears to be a static member function
    EVENT_DECL(CLevel, void, LevelCreateAstarPathfinding,
      (CAstarPathfinder*, float, float, u32, u32, PVOID, PVOID, float),
      ((CAstarPathfinder*)e->retval, *(float*)&Pz[0], *(float*)&Pz[1], Pz[2], Pz[3], (PVOID)Pz[4], (PVOID)Pz[5], *(float*)&Pz[6]));

    // Drop Equipment
    EVENT_DECL(CLevel, void, LevelDropItem,
      (CLevel*, CItem*, Vector3 &, bool, bool&),
      ((CLevel*)e->_this, (CItem*)Pz[0], *(Vector3*)Pz[1], (bool)Pz[2], e->calloriginal));


    // Item drop
    void ItemDrop(CItem* item, Vector3 & position, bool unk) {
      LevelDropItem(this, item, position, unk0);
    }
    // Equipment drop ^^ Same call, just diff name
    void EquipmentDrop(CItem* item, Vector3 & position, bool unk) {
      LevelDropItem(this, item, position, unk0);
    }
    void CharacterInitialize(CCharacter* character, Vector3* position, u32 unk0) {
      LevelCharacterInitialize(this, character, position, unk0);
    }
  };

#pragma pack()

};
