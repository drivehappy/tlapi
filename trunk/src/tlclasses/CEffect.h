#pragma once

#include "CRunicCore.h"

namespace TLAPI {

#pragma pack(1)

  // Type of the effect
  enum EffectType {
    REGULAR = 0xa,
    KNOCKBACK = 0xc,
    CRITICAL_HIT = 0x37,
    ARMOR_DEGRADED = 0x36,
    FASTER_ATTACK = 0x16,
    CHARM_SPELL_MASTERY = 0x52,
    HEALTH_STOLEN = 0x31,
    MANA_STOLEN = 0x32,
    FASTER_CAST_SPEED = 0x1d,
  };

  // Forward decl
  struct CAffix;
  struct CEquipment;
  enum EnchantType;

  struct CEffect : CRunicCore
  {
    u32   unk0;
    EnchantType   magicEffectType;
    u32   unk1[2];
    EffectType   effectType;     // Effect Type? 34h, 37h, 0Ah ... (0Ah, 34h special cases for magic effect types)
    u32   unk2;
    float unk3;     // -900.0, -1000.0

    u32   unk4[2];  // 0/1, 0
    u32   setup;    // 10001h
    u32   unk8;     // 1000100
    float unk9;     // -1
    u32   unk6[3];  // 64h, 64h, 0

    CEquipment *equipment;

    u32   effectIndex;

    u32   unk5[43];

    CAffix *unk7;

    float effectValue;

    
    void dumpEffect() {
      if (effectIndex == 0x80000000)
        return;

      logColor(B_RED, "  Effect Dump (%p)  size (%i)", this, sizeof(CEffect));
      switch (effectType) {
      case KNOCKBACK:
        logColor(B_RED, "    Effect Type: KNOCKBACK");
        break;
      case CRITICAL_HIT:
        logColor(B_RED, "    Effect Type: CRITICAL_HIT");
        break;
      case ARMOR_DEGRADED:
        logColor(B_RED, "    Effect Type: ARMOR_DEGRADED");
        break;
      case FASTER_ATTACK:
        logColor(B_RED, "    Effect Type: FASTER_ATTACK");
        break;
      case CHARM_SPELL_MASTERY:
        logColor(B_RED, "    Effect Type: CHARM_SPELL_MASTERY");
        break;
      case MANA_STOLEN:
        logColor(B_RED, "    Effect Type: MANA_STOLEN");
        break;
      case HEALTH_STOLEN:
        logColor(B_RED, "    Effect Type: HEALTH_STOLEN");
        break;
      case FASTER_CAST_SPEED:
        logColor(B_RED, "    Effect Type: FASTER_CAST_SPEED");
        break;
      default:
        logColor(B_RED, "    Effect Type: UNKNOWN: %x", effectType);
        break;
      }
      
      logColor(B_RED, "    Effect Index: %i", effectIndex);
      //logColor(B_RED, "    Effect Unk0: %x %x %x %x", unk0[0], unk0[1], unk0[2], unk0[3]);
      logColor(B_RED, "    Effect Unk2: %x", unk2);
      logColor(B_RED, "    Effect Unk3: %f", unk3);
      logColor(B_RED, "    Effect Unk4: %x %x", unk4[0], unk4[1]);
      logColor(B_RED, "    Effect Setup: %x", setup);
      logColor(B_RED, "    Effect Unk8: %x", unk8);
      logColor(B_RED, "    Effect Unk9: %f", unk9);
      logColor(B_RED, "    Effect Unk6: %x %x %x", unk6[0], unk6[1], unk6[2]);
      logColor(B_RED, "    Equipment: %p", equipment);
      logColor(B_RED, "    Effect Value: %f", effectValue);

      /*
      logColor(B_RED, "    Effect Unk5:");
      for (u32 i = 0; i < 44; i+=4) {
        logColor(B_RED, "      %#8x %#8x %#8x %#8x", unk5[i+0], unk5[i+1], unk5[i+2], unk5[i+3]);
      }
      */
    }
  };

#pragma pack()

};
