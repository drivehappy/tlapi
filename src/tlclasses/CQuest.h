#pragma once

#include "CRunicCore.h"
#include "CLevelTemplateData.h"
#include "CQuestDialog.h"
#include "CQuestRewards.h"
#include "CQuestRequirements.h"

namespace TLAPI
{

  struct CQuestManager;

#pragma pack(1)

  struct CQuest : CRunicCore
  {
    PVOID unk0;

    CLevelTemplateData   *pCLevelTemplateData;

    u32 unk1[6];

    wstring            name0;    // "RANDOMDUNGEON"
    wstring            unk2;     // ""
    wstring            unk21;    // ""
    wstring            location; // "MEDIA/QUESTS/VASMANRANDOM/ANOTHERPIECECAVES.DAT"
    wstring            name1;    // "ANOTHERPIECECAVES"
    wstring            name2;    // "|cFFFFBA00Another Piece|u"

    CList<CQuestDialog *>    CQuestDialogList0;
    CList<CQuestDialog *>    CQuestDialogList1;

    u32                 unk4[25];

    CQuestRewards      *pCQuestRewards;

    u32                 unk5[27];

    u64                 guid;

    CQuestManager      *pCQuestManager;
    CResourceManager   *pCResourceManager;
    CQuestRequirements *pCQuestRequirements;

  };

#pragma pack()

};

