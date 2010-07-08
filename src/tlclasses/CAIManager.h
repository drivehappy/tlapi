#pragma once

#include "CCharacter.h"
#include "CAIFlagManager.h"
#include "CAISkillManager.h"

namespace TLAPI
{

#pragma pack(1)

  // Size?: 0Ch
  struct CAIManager : CRunicCore
  {
    u32               unk0;
    CCharacter*       pCharacterPtr;    // Pointer to character
    CAIFlagManager*   pAIFlagManager;   // Ptr to AIFlagManager
    CAISkillManager*  pAISkillManager;  // Ptr to CAISkillManager
  };

#pragma pack()

};

