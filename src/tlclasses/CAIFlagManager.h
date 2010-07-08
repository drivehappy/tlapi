#pragma once

#include "_CList.h"
#include "_CString.h"
#include "CCharacter.h"
#include "CAIFlag.h"

namespace TLAPI
{

#pragma pack(1)

  struct CAIManager;

  // Inheritance: CRunicCore
  struct CAIFlagManager : CRunicCore
  {
    u32               unk0;
    CList<CAIFlag*>   pAIFlags; // This appears to be a CList<CAIFlag*>
    u32               unk1[3];
    CCharacter*       pCharacter; // Ptr to CCharacter
    CAIManager*       pAIManager; // Ptr to AI Manager
    CString           nameMesh;
  };

#pragma pack()

};

