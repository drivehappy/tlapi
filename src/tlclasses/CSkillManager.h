#pragma once

#include "CRunicCore.h"
#include "CBaseUnit.h"
#include "CSkill.h"

namespace TLAPI
{

#pragma pack(1)

  struct CSkill;
  struct CPlayer;
  struct CBaseUnit;

  // Size?: 30h
  struct CSkillManager : CRunicCore
  {
    u32 unk0;

    PVOID pCResourceManager;

    u32 unk1[8];

    CList<CSkill*>   listSkills0;
    CList<CSkill*>   listSkills1;

    u32 unk2[3];

    CBaseUnit *pCBaseUnit;


    //
    // Function Hooks
    // Add Skill
    EVENT_DECL(CSkillManager, void, SkillManagerAddSkill,
      (CSkillManager*, CSkill*, bool, u32, bool&),
      ((CSkillManager*)e->_this, (CSkill*)Pz[0], Pz[1], Pz[2], e->calloriginal));
    



    void dumpSkillManager() {
      logColor(B_GREEN, L"SkillManager Dump (%p) (sizeof = %x)", this, sizeof(CSkillManager));
      logColor(B_GREEN, L"  listSkills0: %i", listSkills0.size);
      for (u32 i = 0; i < listSkills0.size; i++) {
        logColor(B_GREEN, L"    listSkills0[%i]: %p", i, listSkills0[i]);
        listSkills0[i]->dumpSkill();
      }

      logColor(B_GREEN, L"  listSkills1: %i", listSkills1.size);
      for (u32 i = 0; i < listSkills1.size; i++) {
        logColor(B_GREEN, L"    listSkills1[%i]: %p", i, listSkills1[i]);
        listSkills1[i]->dumpSkill();
      }
    };




  };

#pragma pack()

};
