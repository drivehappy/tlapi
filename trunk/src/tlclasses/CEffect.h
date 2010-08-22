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
    MAGIC_FIND = 0x1b,
    POTION_EFFECTIVENESS = 0x5a,
    FIRE_RESIST = 0x25,
    POISON_RESIST = 0x28,
    ARMOR = 0x8,
    FASTER_MOVEMENT_SPEED = 0x15,
    MANA = 4,
    HEALTH = 5,
    ELECTRICAL_RESIST = 0x27,
    ICE_RESIST = 0x26,
    STRENGTH = 0x45,
    MAGIC = 0x3,
    EXPERIENCE_GAIN = 0x44,
    ALL_DAMAGE = 0x19,
    DAMAGE_REFLECTED = 0x30,
  };

  static const u32 EffectLookup[] = {
    0xa,
    0xc,
    0x37,
    0x36,
    0x16,
    0x52,
    0x31,
    0x32,
    0x1d,
    0x1b,
    0x5a,
    0x25,
    0x28,
    0x8,
    0x15,
    4,
    5,
    0x27,
    0x26,
    0x45,
    0x3,
    0x44,
    0x19,
    0x30,
  };

  static const char* EffectTypeName[] = {
    "REGULAR",
    "KNOCKBACK",
    "CRITICAL_HIT",
    "ARMOR_DEGRADED",
    "FASTER_ATTACK",
    "CHARM_SPELL_MASTERY",
    "HEALTH_STOLEN",
    "MANA_STOLEN",
    "FASTER_CAST_SPEED",
    "MAGIC_FIND",
    "POTION_EFFECTIVENESS",
    "FIRE_RESIST",
    "POISON_RESIST",
    "ARMOR",
    "FASTER_MOVEMENT_SPEED",
    "MANA",
    "HEALTH",
    "ELECTRICAL_RESIST",
    "ICE_RESIST",
    "STRENGTH",
    "MAGIC",
    "EXPERIENCE_GAIN",
    "ALL_DAMAGE",
    "DAMAGE_REFLECTED",
  };

  static const char* searchForEffectName(u32 index) {
    u32 count = sizeof(EffectLookup) / sizeof(u32);
    for (u32 i = 0; i < count; i++) {
      if (EffectLookup[i] == index) {
        return EffectTypeName[i];
      }
    }
    return "";
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
      logColor(B_RED, "    Effect Type: %s", searchForEffectName(effectType));
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
      for (u32 i = 0; i < 43; i+=4) {
        logColor(B_RED, "      %#x %#x %#x %#x", unk5[i+0], unk5[i+1], unk5[i+2], unk5[i+3]);
      }
      */
    }
  };

#pragma pack()

};
