#pragma once

#include "CRunicCore.h"
#include "_CList.h"
#include "_CString.h"

namespace TLAPI {

#pragma pack(1)

  struct CGameGlobals : CRunicCore
  {
    PVOID unk0;
    PVOID unk1;

    CString filename;   // "media/globals.dat"

    u32 NormalItemWeight;
    u32 MagicItemWeight;
    u32 UniqueItemWeight;

    float RandomEnchantChance;
    float RandomSocketChance;
    float SecondSocketChance;

    u32 RandomEnchantSlotsMin;
    u32 RandomEnchantSlotsMax;
    u32 MagicItemSlotsMin;
    u32 MagicItemSlotsMax;
    u32 UniqueItemSlotsMin;
    u32 UniqueItemSlotsMax;
    u32 RetirementAge;    

    float unk5[3];            // 1.5, 2.0, 1.0

    float HPRechargeRate;
    float PetHPRechargeRate;
    float ManaRechargeRate;
    float EnchanterSocketChance;
    float EnchanterMagicChance;
    float EnchanterPricePerEnchant;
    float EnchanterDisenchantChance;
    float EnchanterMaxDisenchantChance;
    float EnchantShrineSocketChance;
    float EnchantShrineMagicChance;
    float EnchantShrineDisenchantChance;
    float EnchantShrineMaxDisenchantChance;

    u32   EnchanterMaxEnchants;
    float EnchanterDisenchantIncrease;
    u32   EnchantShrineMaxEnchants;
    float EnchantShrineDisenchantIncrease;
    float EasyMonsterAttentionBonus;
    float NormalMonsterAttentionBonus;
    float HardMonsterAttentionBonus;
    float VeryHardMonsterAttentionBonus;
    float UnitShadowRange;
    float UnitNearRange;
    float TriggerNearRange;
    float IndoorUnitActiveRange;
    float OutdoorUnitActiveRange;

    CList<CString2>   PlayerTitles;

    u32   unk8[6];    // Weird ptrs

    CString2      ContextTips[24];

    // Unk rest


    void dumpGlobals() {
      log("GameGlobals(%p) sizeof(%i)", this, sizeof(CGameGlobals));
      log(L"  Filename: %s", filename);

      log("  NormalItemWeight: %i", NormalItemWeight);
      log("  MagicItemWeight: %i", MagicItemWeight);
      log("  UniqueItemWeight: %i", UniqueItemWeight);

      log("  RandomEnchantChance: %f", RandomEnchantChance);
      log("  RandomSocketChance: %f", RandomSocketChance);
      log("  SecondSocketChance: %f", SecondSocketChance);

      log("  RandomEnchantSlotsMin: %i", RandomEnchantSlotsMin);
      log("  RandomEnchantSlotsMax: %i", RandomEnchantSlotsMax);
      log("  MagicItemSlotsMin: %i", MagicItemSlotsMin);
      log("  MagicItemSlotsMax: %i", MagicItemSlotsMax);
      log("  UniqueItemSlotsMin: %i", UniqueItemSlotsMin);
      log("  UniqueItemSlotsMax: %i", UniqueItemSlotsMax);
      log("  RetirementAge: %i", RetirementAge);

      log("  unk5: %f %f %f", unk5[0], unk5[1], unk5[2]);

      log("  HPRechargeRate: %f", HPRechargeRate);
      log("  PetHPRechargeRate: %f", PetHPRechargeRate);
      log("  ManaRechargeRate: %f", ManaRechargeRate);
      log("  EnchanterSocketChance: %f", EnchanterSocketChance);
      log("  EnchanterMagicChance: %f", EnchanterMagicChance);
      log("  EnchanterPricePerEnchant: %f", EnchanterPricePerEnchant);
      log("  EnchanterDisenchantChance: %f", EnchanterDisenchantChance);
      log("  EnchanterMaxDisenchantChance: %f", EnchanterMaxDisenchantChance);
      log("  EnchantShrineSocketChance: %f", EnchantShrineSocketChance);
      log("  EnchantShrineMagicChance: %f", EnchantShrineMagicChance);
      log("  EnchantShrineDisenchantChance: %f", EnchantShrineDisenchantChance);
      log("  EnchantShrineMaxDisenchantChance: %f", EnchantShrineMaxDisenchantChance);

      log("  EnchanterMaxEnchants: %i", EnchanterMaxEnchants);
      log("  EnchanterDisenchantIncrease: %f", EnchanterDisenchantIncrease);
      log("  EnchantShrineMaxEnchants: %i", EnchantShrineMaxEnchants);
      log("  EnchantShrineDisenchantIncrease: %f", EnchantShrineDisenchantIncrease);
      log("  EasyMonsterAttentionBonus: %f", EasyMonsterAttentionBonus);
      log("  NormalMonsterAttentionBonus: %f", NormalMonsterAttentionBonus);
      log("  HardMonsterAttentionBonus: %f", HardMonsterAttentionBonus);
      log("  VeryHardMonsterAttentionBonus: %f", VeryHardMonsterAttentionBonus);
      log("  UnitShadowRange: %f", UnitShadowRange);
      log("  UnitNearRange: %f", UnitNearRange);
      log("  TriggerNearRange: %f", TriggerNearRange);
      log("  IndoorUnitActiveRange: %f", IndoorUnitActiveRange);
      log("  OutdoorUnitActiveRange: %f", OutdoorUnitActiveRange);

      log("  Player Titles:");
      for (u32 i = 0; i < PlayerTitles.size; i++) {
        log(L"    %s", PlayerTitles[i]);
      }
    }
  };

#pragma pack()

};
