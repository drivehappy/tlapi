#pragma once

#include "_CList.h"
#include "_CString.h"
#include "CCharacter.h"
#include "CAIFlag.h"

namespace TLAPI
{

#pragma pack(1)

  struct CAIManager;
  struct CCharacter;

  //
  struct CAIFlagManager : CRunicCore
  {
    u32               unk0;
    CList<CAIFlag*>   pAIFlags;
    CCharacter*       pCharacter; // Ptr to CCharacter
    CAIManager*       pAIManager; // Ptr to AI Manager
  };

#pragma pack()

};

