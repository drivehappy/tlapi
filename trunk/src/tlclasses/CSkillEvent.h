#pragma once

#include "CRunicCore.h"
#include "CUnitSpawner.h"

namespace TLAPI
{

#pragma pack(1)

  struct CSkillEvent : CRunicCore
  {
    u32 unk0;

    // ---------- Base type cutoff -----

    PVOID vtableIDamageShape;
    PVOID vtableIMissle;
    PVOID vtableIUnitSpawner;

    PVOID pCSkill;
    PVOID pCResourceManager;
    PVOID pCLayout;

    u32 unk1[11];

    PVOID pCSkillProperty;

    u32 unk2[5];

    CList<CUnitSpawner*> listUnitSpawner;

    u32 unk3[13];


    void dumpSkillEvent() {
      logColor(B_GREEN, L"SkillEvent Dump: %p", this);
      logColor(B_GREEN, L"  listUnitSpawner size: %i", listUnitSpawner.size);
      for (u32 i = 0; i < listUnitSpawner.size; i++) {
        logColor(B_GREEN, L"  listUnitSpawner[%i]: %p", i, listUnitSpawner[i]);
      }
    }
  };

#pragma pack()

};
