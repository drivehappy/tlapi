#include "Test.h"

void Test_EffectGroupManager_CreateAffix(CEffectGroupManager* effectGroupManager, u32 unk0, u32 unk1, u32 unk2, CList<CAffix*> *listAffixes)
{
  log("EffectGroupManager(%p) CreateAffixList(%x, %x, %x, %p)",
    effectGroupManager, unk0, unk1, unk2, listAffixes);

  log("listAffixes = %p", listAffixes);
  log("listAffixes ptr: %p", (*listAffixes));
  log("listAffixes size: %i", (*listAffixes).size);
  log("listAffixes cap: %i", (*listAffixes).capacity);
  log("listAffixes growth: %i", (*listAffixes).growth);

  for (u32 i = 0; i < (*listAffixes).size; i++) {
    CAffix* currentAffix = (*listAffixes)[i];

    log("currentAffix: %p", currentAffix);

    log("  currentAffix->effectList: %p   size: %i  cap: %i   growth: %i",
      currentAffix->effectList, currentAffix->effectList.size,
      currentAffix->effectList.capacity, currentAffix->effectList.growth);

    for (u32 j = 0; j < currentAffix->effectList.size; j++) {
      CEffect* currentEffect = currentAffix->effectList[j];

      log("    effect: %p   effectType: %x   val: %f",
        currentEffect,
        currentEffect->effectType, currentEffect->effectValue);
    }
  }

}
