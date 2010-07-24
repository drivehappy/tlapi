#pragma once

#include "_CList.h"
#include "CRunicCore.h"
#include "CAffix.h"
#include "CEffect.h"

namespace TLAPI {

#pragma pack(1)
  
  // Forward decl
  struct CEquipment;

  struct CEffectManager : CRunicCore
  {
    u32 unk0;

    CList<CAffix*>  affixList;
    CList<CEffect*> effectList;

    u32 unk1[8];    // 3 dup(   0),   1,3 dup(   0),   1

    CEquipment*     equipment;

    u32   unk2[6];   // 0s
    float valHealth;
    u32   unk10[4];

    float unk3;       // 1.5398136

    u32   unk100;     // 0

    float valKnockback;

    u32   unk4[9];   // 0s

    float valFasterAttack;

    u32   unk5[32];

    float valCriticalHitChance;

    u32   unk6[12];

    float valExperienceGain;

    u32   unk7[21];

    float valPotionEffectiveness;

    u32   unk8[69];

    CString *stringEffect;


    
    void dumpEffectManager() {
      logColor(B_GREEN, "EffectManager(%p)  size (%i)", this, sizeof(CEffectManager));
      logColor(B_GREEN, "  Affix List Size: %i", affixList.size);
      logColor(B_GREEN, "  Effect List Size: %i", effectList.size);

      for (u32 i = 0; i < effectList.size; i++) {
        effectList[i]->dumpEffect();
      }

      logColor(B_GREEN, "  Equipment: %p", equipment);

      /*
      if (effectList.size && stringEffect) {
        logColor(B_GREEN, L"  Effect String: %s", stringEffect);
      }
      */

      logColor(B_GREEN, "  Knockback Value: %f", valKnockback);
      logColor(B_GREEN, "  FasterAttack Value: %f", valFasterAttack);
      logColor(B_GREEN, "  CriticalHitChance Value: %f", valCriticalHitChance);
      logColor(B_GREEN, "  ExperienceGain Value: %f", valExperienceGain);
      logColor(B_GREEN, "  PotionEffectiveness Value: %f", valPotionEffectiveness);

      /* Old, bad sizes
      logColor(B_BLUE, "  Unknowns unk1:");
      for (u32 i = 0; i < 8; i++) {
        logColor(B_BLUE, "     %x", unk1[i]);
      }

      logColor(B_BLUE, "  Unknowns unk2:");
      for (u32 i = 0; i < 6; i++) {
        logColor(B_BLUE, "     %x", unk2[i]);
      }

      logColor(B_BLUE, "  Unknowns unk4:");
      for (u32 i = 0; i < 11; i++) {
        logColor(B_BLUE, "     %x", unk4[i]);
      }

      logColor(B_BLUE, "  Unknowns unk5 partial:");
      for (u32 i = 0; i < 69; i++) {
        logColor(B_BLUE, "     %x", unk5[i]);
      }
      */
    };
  };

#pragma pack()

};
