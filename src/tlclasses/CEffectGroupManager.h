#pragma once

#include "CRunicCore.h"

namespace TLAPI {

#pragma pack(1)
  
  /* Notes:
    1. @5FC0F0 Function call: CEffectGroupManager::CreateAffixList(5F, 0, 2, CList<CAffix*> &)
    2. @5FC124 Function call: CEquipment* CEquipment(CAffix*, u32, CEquipment*, float)

    Func1 creates a list of Affixes.
    Func2 takes each Affix and applies it to the Equipment (including the Effect)
          Affixes here include Effects that handle all Enchant types (e.g. Physical/Ice/ArmorDegraded/etc)

    What is needed:
          Figure out how to manipulate CreateAffixList to return 1 Affix of our choosing
             ... or just modify this list to make just one affix with a modified CEffect
          Pass this Affix list to Func2

  */

  // Redecl
  struct CEffectGroupManager;
  TLFUNC(EffectGroupManager_CreateAffix, void, __thiscall, (CEffectGroupManager*, u32, u32, u32, CList<CAffix*>*));

  // 
  struct CEffectGroupManager : CRunicCore
  { 
    //
    EVENT_DECL(CEffectGroupManager, void, EffectGroupManager_CreateAffix,
      (CEffectGroupManager*, u32, u32, u32, CList<CAffix*> *),
      ((CEffectGroupManager*)e->_this, Pz[0], Pz[1], Pz[2], (CList<CAffix*>*)Pz[3]));

    // Creates an affix list (by-ref)
    void CreateAffix(u32 unk0, u32 unk1, u32 maxAffixes, CList<CAffix*>* listAffixes) {
      EffectGroupManager_CreateAffix(this, unk0, unk1, maxAffixes, listAffixes);
    }
  };

#pragma pack()

};
