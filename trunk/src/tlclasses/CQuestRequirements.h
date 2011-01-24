#pragma once

#include "CRunicCore.h"
#include "CDataGroup.h"

namespace TLAPI
{
  struct CQuest;

#pragma pack(1)

  struct CQuestRequirements : CRunicCore
  {
    PVOID           unk0;

    CDataGroup     *pCDataGroup;
    CQuest         *pCQuest;
  };

#pragma pack()

};
