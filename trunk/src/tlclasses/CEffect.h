#pragma once

#include "CRunicCore.h"

namespace TLAPI {

#pragma pack(1)

  // Type of the effect
  enum EffectType {
    KNOCKBACK = 0xc,
    CRITICAL_HIT = 0x37,
    ARMOR_DEGRADED = 0x36,
    FASTER_ATTACK = 0x16,
    CHARM_SPELL_MASTERY = 0x52,
  };

  // Forward decl
  struct CEquipment;

  struct CEffect : CRunicCore
  {
    u32   unk0[4];
    EffectType   effectType;     // Effect Type? 34h, 37h, 0Ah ...
    u32   unk2;
    float unk3;     // -900.0, -1000.0

    u32   unk4[8];  //

    CEquipment *equipment;

    u32   effectIndex;

    u32   unk5[32];

    
    void dumpEffect() {
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
      default:
        logColor(B_RED, "    Effect Type: UNKNOWN: %x", effectType);
        break;
      }
      
      logColor(B_RED, "    Effect Index: %i", effectIndex);
      logColor(B_RED, "    Effect Unk0: %x %x %x %x", unk0[0], unk0[1], unk0[2], unk0[3]);
      logColor(B_RED, "    Effect Unk2: %x", unk2);
      logColor(B_RED, "    Effect Unk3: %f", unk3);
      logColor(B_RED, "    Effect Unk4: %x %x %x %x %x %x %x %x", unk4[0], unk4[1], unk4[2], unk4[3], unk4[4], unk4[5], unk4[6], unk4[7]);
      logColor(B_RED, "    Equipment: %p", equipment);

      /*
      logColor(B_RED, "    Effect Unk5:");
      for (u32 i = 0; i < 32; i++) {
        logColor(B_RED, "      %x", unk5[i]);
      }
      */
    }
  };

#pragma pack()

};
