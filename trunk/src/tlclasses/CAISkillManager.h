#pragma once

#include "_CString.h"
#include "CCharacter.h"

namespace TLAPI
{

#pragma pack(1)

  struct CAIManager;

  struct CAISkillManager : CRunicCore
  {
    u32         unk0[4];            // values of 0
    u32         unk1;               // value of 2 w/ first pass
    CCharacter* pCCharacter;        // ptr to CCharacter
    CAIManager* pCAIManager;        // ptr to CAIManager
    CString     pMediaModelString;  // ptr string value: MEDIA/MODELS/WEAPONS/HACKER/weapon_hacker
  };

#pragma pack()

};
