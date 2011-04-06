#pragma once

#include "Common.h"

#include "_CList.h"
#include "_CString.h"
#include "CRunicCore.h"
#include "CAffix.h"
#include "CEffect.h"

namespace TLAPI {

#pragma pack(1)
  
  // Forward decl
  struct CEquipment;
  struct CPlayer;

  //
  TLFUNC(EffectManagerCreateEffect,        CEffect*,  __thiscall, (CEffectManager*));
  TLFUNC(EffectManager_UpdateEffects,      void,      __thiscall, (CEffectManager*));
  TLFUNC(EffectManager_RemoveAffix,        bool,      __thiscall, (CEffectManager*, CAffix*));

  //
  struct CEffectManager : CRunicCore
  {
    u32 unk0;

    CList<CAffix*>  affixList;

    // Not a vector<T> structure, first list contained 1 element, 2nd contained 3
    CList<CEffect*> effectList;
    CList<CEffect*> effectList2;

    u32 unk1[4];    // 0, 0, 0, 1

    CPlayer*     player;    // Equipment* too???

    u32   unk101;     // 5

    u32   unk102;     //

    u32   unk2[4];   // 0s
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

    u32   unk8[68];

    wstring stringEffect;

    // EffectManager effect creation
    EVENT_DECL(CEffectManager, void, EffectManagerCreateEffect,
      (CEffect*, CEffectManager*),
      ((CEffect*)e->retval, (CEffectManager*)e->_this));

    EVENT_DECL(CEffectManager, void, EffectManager_AddEffectToEquipment,
      (CEffectManager*, CEquipment*, CEffect*),
      ((CEffectManager*)e->_this, (CEquipment*)Pz[0], (CEffect*)Pz[1]));

    EVENT_DECL(CEffectManager, void, EffectManager_RemoveAffix,
      (bool, CEffectManager*, CAffix*, bool&),
      ((bool)e->retval, (CEffectManager*)e->_this, (CAffix*)Pz[0], e->calloriginal));

    CEffect* CreateEffect()
    {
      return EffectManagerCreateEffect(this);
    }
    void UpdateEffects()
    {
      return EffectManager_UpdateEffects(this);
    }
    bool RemoveAffix(CAffix* affix)
    {
      return EffectManager_RemoveAffix(this, affix);
    }
    
    void dumpEffectManager() {
      logColor(B_GREEN, "EffectManager(%p)  size (%i)", this, sizeof(CEffectManager));
      logColor(B_GREEN, "  Affix List Size: %i", affixList.size);
      logColor(B_GREEN, "  Effect List Size: %i", effectList.size);

      /*
      for (u32 i = 0; i < effectList.size; i++) {
        effectList[i]->dumpEffect();
      }
      */
      for (u32 i = 0; i < affixList.size; i++) {
        affixList[i]->dumpAffix();
      }

      logColor(B_GREEN, "  Player: %p", player);

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
    };
  };

#pragma pack()

};
