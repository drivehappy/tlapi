#pragma once

#include "_CList.h"
#include "CRunicCore.h"
#include "CSkillEvent.h"

namespace TLAPI
{

#pragma pack(1)

  struct CSkillProperty : CRunicCore
  {
    float unk0[5];

    PVOID pCResourceManager;
    PVOID pCSkillProperty;
    PVOID pCSkill;

    u32 unk1[2];

    PVOID pCDataGroup;

    u32 unk2;
    
    CList<CList<CSkillEvent*>*> listOfListOfSkillEvents;

    u32 unk3[2];

    float unk4[18];

    wstring skillIconName;
    wstring skillIconInactive;
    wstring skillName;
    wstring skillName2;

    float unk5[8];

    wstring skillDescription;
    string unkName;
          /*
          debug277:1A2E7FC8 db  53h ; S
          debug277:1A2E7FC9 db  50h ; P
          debug277:1A2E7FCA db  45h ; E
          debug277:1A2E7FCB db  43h ; C
          debug277:1A2E7FCC db  49h ; I
          debug277:1A2E7FCD db  41h ; A
          debug277:1A2E7FCE db  4Ch ; L
          debug277:1A2E7FCF db  5Fh ; _
          debug277:1A2E7FD0 db  53h ; S
          debug277:1A2E7FD1 db  54h ; T
          debug277:1A2E7FD2 db  4Fh ; O
          debug277:1A2E7FD3 db  4Dh ; M
          debug277:1A2E7FD4 db  50h ; P
          debug277:1A2E7FD5 db    0
          debug277:1A2E7FD6 db  4Bh ; K
          debug277:1A2E7FD7 db  19h
          debug277:1A2E7FD8 db  0Dh
          debug277:1A2E7FD9 db    0
          debug277:1A2E7FDA db    0
          debug277:1A2E7FDB db    0
          debug277:1A2E7FDC db  0Fh
          debug277:1A2E7FDD db    0
          debug277:1A2E7FDE db    0
          debug277:1A2E7FDF db    0

          */


    void dumpSkillProperty() {
      logColor(B_GREEN, L"        skillName: %s", skillName.c_str());
      logColor(B_GREEN, L"        skillName2: %s", skillName2.c_str());
      logColor(B_GREEN, L"        listOfListOfSkillEvents size: %i", listOfListOfSkillEvents.size);

      /*
      for (u32 i = 0; i < listOfListOfSkillEvents.size; i++) {
        logColor(B_RED, L"      listOfListOfSkillEvents[%i] size: %i", i, listOfListOfSkillEvents[i]->size);
        for (u32 j = 0; j < listOfListOfSkillEvents[i]->size; j++) {
          logColor(B_RED, L"      listOfListOfSkillEvents[%i][%i] SkillEvent Dump", i, j);
          listOfListOfSkillEvents[i]->operator [](j)->dumpSkillEvent();
        }
      }
      */
    }

  };

#pragma pack()

};

