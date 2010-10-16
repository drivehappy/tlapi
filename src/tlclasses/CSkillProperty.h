#pragma once

#include "_CList.h"
#include "CRunicCore.h"
#include "CSkillEvent.h"

namespace TLAPI
{

  struct CResourceManager;
  struct CSkillProperty;
  struct CSkill;
  struct CDataGroup;

#pragma pack(1)

  struct CSkillProperty : CRunicCore
  {
    float unk0[5];

    CResourceManager *pCResourceManager;
    CSkillProperty *pCSkillProperty;
    CSkill *pCSkill;

    u32 unk1[2];

    CDataGroup *pCDataGroup;

    u32 unk2;
    
    CList<CList<CSkillEvent*>*> listOfListOfSkillEvents;

    u32 unk3[2];

    float unk4[18];

    wstring skillIconName;
    wstring skillIconInactive;
    wstring skillName;
    wstring skillName2;

    float unk5[8];

    wstring unkName;
    wstring skillDescription;



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

