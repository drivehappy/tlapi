#pragma once

#include "CRunicCore.h"
#include "CResourceManager.h"

namespace TLAPI {

#pragma pack(1)

  // Forward decl
  struct CResourceManager;


  struct CSkill : CRunicCore
  {
    PVOID unk0;

    // ----------- End Base Data members -----

    PVOID vtableIUnitObserver;

    CResourceManager *pCResourceManager;
    CSkillManager    *pCSkillManager;
    CDataGroup       *pCDataGroup;

    u32 unk1[4];

    PVOID unk2;

    u32 unk3[7];

    float unk4;

    u32 unk5[4];

    PVOID pCSkillProperty0;
    PVOID pCSkillProperty1;
    PVOID pCSkillProperty2;
  };

#pragma pack()

};
