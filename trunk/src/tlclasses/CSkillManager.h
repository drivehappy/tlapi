#pragma once

#include "CRunicCore.h"

namespace TLAPI
{

#pragma pack(1)

  // Size?: 30h
  struct CSkillManager : CRunicCore
  {
    u32 unk0;

    PVOID pCResourceManager;

    u32 unk1[6];

    PVOID unk2;

    u32 unk3[2];
  };

#pragma pack()

};
