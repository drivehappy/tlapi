#pragma once

#include "CRunicCore.h"
#include "CSkillProperty.h"
#include "CSkillEffectAndAffixes.h"

namespace TLAPI {

#pragma pack(1)

  // Forward decl
  struct CResourceManager;
  struct CSkillManager;
  struct CDataGroup;
  struct CPlayer;
  struct CSkillProperty;

  // Size: 190h
  struct CSkill : CRunicCore
  {
    PVOID unk0;

    // ----------- End Base Data members -----

    PVOID vtableIUnitObserver;

    CResourceManager *pCResourceManager;
    CSkillManager    *pCSkillManager;
    CDataGroup       *pCDataGroup;
    CPlayer          *pCPlayer;

    u32   unk1[3];

    Vector3 position;

    // byte ptr [this + 44h] = Skill in-flight?

    u32   unk3[5];

    float unk4;

    u32 unk5[4];

    CSkillProperty *pCSkillProperty0;
    CSkillProperty *pCSkillProperty1;
    
    CList<CSkillProperty*>   skillPropertyList;

    u32 unk6[31];

    CSkillEffectAndAffixes *pCSkillEffectAndAffixes;

    float  unk7[13];

    CList<PVOID>  unkList;

    u32    unk8[12];

    PVOID   vtable__iRandomWeight;
    PVOID   vtable__iHighlight;

    u32    unk9[4];

    u64    GUID;

    u32    unk10[3];




    void dumpSkill() {
      /*
      logColor(B_RED, L"      unk1: %x %x %x",
        unk1[0], unk1[1], unk1[2]);
      logColor(B_RED, L"      position: %f %f %f",
        position.x, position.y, position.z);
      logColor(B_RED, L"      unk3: %x %x %x %x %x",
        unk3[0], unk3[1], unk3[2], unk3[3], unk3[4]);
      logColor(B_RED, L"      unk5: %x",
        unk5[0]);
      //logColor(B_RED, L"      listSkillProperties size: %i", 
      //  listSkillProperties.size());

      for (u32 i = 0; i < 35; i+=5) {
        logColor(B_RED, L"      %x %x %x %x %x",
           unk6[i+0], unk6[i+1], unk6[i+2], unk6[i+3], unk6[i+4]);
      }
      */

      logColor(B_RED, L"      Position: %f %f %f", position.x, position.y, position.z);
      logColor(B_RED, L"      pCSkillProperty0: %p", pCSkillProperty0);
      logColor(B_RED, L"      pCSkillProperty1: %p", pCSkillProperty1);
      logColor(B_RED, L"      skillPropertyList Size: %p", skillPropertyList.size);

      pCSkillProperty0->dumpSkillProperty();
      pCSkillProperty1->dumpSkillProperty();
      for (u32 i = 0; i < skillPropertyList.size; i++) {
        skillPropertyList[i]->dumpSkillProperty();
      }
      
    }
  };

#pragma pack()

};
