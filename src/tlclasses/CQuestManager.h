#pragma once

#include "CRunicCore.h"
#include "CQuest.h"
#include "CCharacter.h"

namespace TLAPI
{

  struct CResourceManager;

#pragma pack(1)

  struct CQuestManager : CRunicCore
  {
    u32                unk0;
    CCharacter        *pCharacter;
    CList<CQuest*>     questList;
    PVOID              pCSoundBank;
    CResourceManager  *pResourceManager;


    // 
    EVENT_DECL(CQuestManager, void, QuestManagerSetQuestCompleted,
      (CQuestManager*, CQuest*, CCharacter*, u32, bool&),
      ((CQuestManager*)e->_this, (CQuest*)Pz[0], (CCharacter*)Pz[1], Pz[2], e->calloriginal));

  };

#pragma pack()

};
