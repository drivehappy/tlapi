#pragma once

#include "_CList.h"
#include "_CLinkedListNode.h"

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
  TLFUNC(LevelDropItem,                   PVOID,        __thiscall, (CLevel*, CItem*, Vector3 &, bool));
  TLFUNC(LevelCharacterInitialize,        CCharacter*,  __thiscall, (CLevel*, CCharacter*, Vector3*, u32));
  TLFUNC(Level_CharacterKilledCharacter,  void,         __thiscall, (CLevel*, CCharacter*, CCharacter*, Vector3*, u32));
  TLFUNC(Level_RemoveEquipment,           void,         __thiscall, (CLevel*, CEquipment*));

  //
  struct CLevel : CRunicCore
  {
    u32 unk0;
    
    CList<CLayout*>    CLayoutsList;

    CList<float>        unkFloatList;

    u32 unk5[5];

    CQuadtree          *pCQuadTree;       // ptr to CQuadTree
    CCollisionList     *pCCollisionList;  // ptr to CCollisionList

    u32                 unk11[6];

    LinkedListNode    **ppCCharacters1;  // LinkedList of Monsters

    LinkedListNode    **ppCTriggerUnits;  // LinkedList of ??
    
    LinkedListNode    **ppCCharacters2;  // LinkedList of Monsters

    LinkedListNode    **ppCItems;        // LinkedList of CItem

    CList<CParticle*>   particleList;

    PVOID unk18[3];

    vector<u32>         vecUnk1;

    u32                 unk19[8];     // 3 dup(   0), 0Ah,3 dup(   0), 0Ah

    vector<u32>         vecUnk2;

    float unk20[22];
    u32  unk21[6];

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

    // Character Killed
    EVENT_DECL(CLevel, void, Level_CharacterKilledCharacter,
      (CLevel*, CCharacter*, CCharacter*, Vector3*, u32, bool&),
      ((CLevel*)e->_this, (CCharacter*)Pz[0], (CCharacter*)Pz[1], (Vector3*)Pz[2], Pz[3], e->calloriginal));
    
    // Level Dtor
    EVENT_DECL(CLevel, void, Level_Dtor,
      (CLevel*, u32, bool&),
      ((CLevel*)e->_this, Pz[0], e->calloriginal));
    
    // Level Ctor
    EVENT_DECL(CLevel, void, Level_Ctor,
      (wstring name, CSettings*, CGameClient*, CResourceManager*, PVOID OctreeSM, CSoundManager*, u32, u32, bool&),
      (*(wstring*)&Pz[0], (CSettings*)Pz[7], (CGameClient*)Pz[8], (CResourceManager*)Pz[9], (PVOID)Pz[10], (CSoundManager*)Pz[11], Pz[12], Pz[13], e->calloriginal));

    // Level Update
    EVENT_DECL(CLevel, void, Level_Update,
      (CLevel*, Vector3*, u32, float, bool&),
      ((CLevel*)e->_this, (Vector3*)Pz[0], Pz[1], *(float*)&Pz[2], e->calloriginal));

    // Level Cleanup
    EVENT_DECL(CLevel, void, Level_Cleanup,
      (CLevel*, u32, u32, bool&),
      ((CLevel*)e->_this, Pz[0], Pz[1], e->calloriginal));

    // Level Remove Equipment
    EVENT_DECL(CLevel, void, Level_RemoveEquipment,
      (CLevel*, CEquipment*, bool&),
      ((CLevel*)e->_this, (CEquipment*)Pz[0], e->calloriginal));

    // Character Killed
    void CharacterKill(CCharacter* attacker, CCharacter* killed, Vector3* position, u32 unk0) {
      Level_CharacterKilledCharacter(this, attacker, killed, position, unk0);
    }
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



    void DumpCharacters1() {
      /*
      LinkedListNode* itr = *ppCCharacters1;
      while (itr != NULL) {
        CCharacter* character = (CCharacter*)itr->pCBaseUnit;
        logColor(B_GREEN, L"  Level Character1: (itr = %p) %p %s", itr, character, character->characterName.c_str());
        //multiplayerLogger.WriteLine(Info, L"  Level Item: (itr = %p) %p %s", itr, character, character->characterName.c_str());
        itr = itr->pNext;
      }
      */
    }

    void DumpTriggerUnits() {
      LinkedListNode* itr = *ppCTriggerUnits;
      while (itr != NULL) {
        CTriggerUnit* triggerUnit = (CTriggerUnit*)itr->pCBaseUnit;

        log(L"  Level TriggerUnit: (itr = %p) %p %s", itr, triggerUnit, triggerUnit->nameReal.c_str());
        //multiplayerLogger.WriteLine(Info, L"  Level Item: (itr = %p) %p %s", itr, character, character->characterName.c_str());

        itr = itr->pNext;
      }
    }

    void DumpCharacters2() {
      LinkedListNode* itr = *ppCCharacters2;
      while (itr != NULL) {
        CCharacter* character = (CCharacter*)itr->pCBaseUnit;
        logColor(B_GREEN, L"  Level Character2: (itr = %p) %p %s", itr, character, character->characterName.c_str());

        itr = itr->pNext;
      }
    }

    vector<CCharacter*>& GetCharacters() {
      vector<CCharacter*>* retval = new vector<CCharacter*>();

      LinkedListNode* itr = *ppCCharacters2;
      while (itr != NULL) {
        CCharacter* character = (CCharacter*)itr->pCBaseUnit;
        retval->push_back(character);

        itr = itr->pNext;
      }

      return *retval;
    }

    int GetCharacterCount() {
      int count = 0;
      LinkedListNode* itr = *ppCCharacters2;
      while (itr != NULL) {
        count++;
        itr = itr->pNext;
      }
      return count;
    }

    void DumpItems() {
      LinkedListNode* itr = *ppCItems;
      while (itr != NULL) {
        log(L"  Level Item: itr = %p", itr);

        CItem* item = (CItem*)itr->pCBaseUnit;
        
        log(L"   itrNext: %p, Item: %p, Name: %s", itr->pNext, item, item->nameReal.c_str());
        log(L"     vtable: %p dtor: %p", *(u32*)(itr->pCBaseUnit), **(u32**)(itr->pCBaseUnit));
        //multiplayerLogger.WriteLine(Info, L"  Level Item: (itr = %p) %p %s", itr, item, item->nameReal.c_str());

        itr = itr->pNext;
      }
      log(L"Done Dumping.");
    }

    bool containsItem(CItem* itemSearch) {
      LinkedListNode* itr = *ppCItems;
      while (itr != NULL) {
        CItem* item = (CItem*)itr->pCBaseUnit;
        if (item == itemSearch)
          return true;
        itr = itr->pNext;
      }
      return false;
    }
  };

#pragma pack()

};
