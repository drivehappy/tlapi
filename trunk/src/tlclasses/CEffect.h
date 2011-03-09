#pragma once

#include "CRunicCore.h"
#include "CBaseUnit.h"

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
    DEFENSE = 0x2,
    CHANCE_REFLECT_MISSILE_DAMAGE,
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
    2,
    0x3c,
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
    "DEFENSE",
    "CHANCE_REFLECT_MISSILE_DAMAGE",
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
  struct CResourceManager;
  struct CEffect;
  struct CCharacter;
  enum EnchantType;

  //
  TLFUNC(Effect_Something0,     void, __thiscall, (CEffect*, u32));
  TLFUNC(Effect_CopyCtor,       void, __thiscall, (CEffect*));
  TLFUNC(Effect_ParamCtor,      void, __thiscall, (CEffect*, u32, bool, float, float, float, float, bool));
  TLFUNC(Effect_Character_Unk0, void, __thiscall, (CEffect*, CCharacter*, bool));

  // Size: 144h
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

    CBaseUnit *pCBaseUnit;

    u32   effectIndex;

    u32   unk5[11];

    wstring name;

    u32   unk10[25];

    CAffix *unk7;

    float effectValue;
    float effectValue2;   //@(63. * 4)

    u32 unk11[7];
    CList<u32>        listUnknown;
    CList<float>      listUnknown2;
    //u32 unk11[15];

    CResourceManager *pCResourceManager;

    u32 unk12;

    //PVOID unkEquipment;

    
    // Parameterized Ctor
    EVENT_DECL(CEffect, void, Effect_ParamCtor,
      (CEffect*, u32, bool, float, float, float, float, bool, bool&),
      ((CEffect*)e->_this, Pz[0], (bool)Pz[1], *(float*)&Pz[2], *(float*)&Pz[3], *(float*)&Pz[4], *(float*)&Pz[5], (bool)Pz[6], e->calloriginal));

    //
    EVENT_DECL(CEffect, void, Effect_CopyCtor,
      (CEffect*),
      ((CEffect*)e->_this));

    //
    EVENT_DECL(CEffect, void, Effect_Character_Unk0,
      (CEffect*, CCharacter*, bool),
      ((CEffect*)e->_this, (CCharacter*)Pz[0], (bool)Pz[1]));
    

    // Effect - Function is crashing the client, seeing what it is
    EVENT_DECL(CEffect, void, Effect_Effect_Something,
      (CEffect*, CEffect*, bool&),
      ((CEffect*)e->_this, (CEffect*)Pz[0], e->calloriginal));

    // Effect = Function is crashing client when player levels up
    EVENT_DECL(CEffect, void, Effect_Something0,
      (CEffect*, u32, bool&),
      ((CEffect*)e->_this, Pz[0], e->calloriginal));

    /*
    CEffect()
    {
      Effect_Ctor(this);
    }
    */

    void EffectCtor(CEffect *other)
    {
      Effect_CopyCtor(other);
    }

    //
    void EffectParamCtor(u32 unk1, bool unk2, float unk3, float unk4, float unk5, float unk6, bool unk7)
    {
      Effect_ParamCtor(this, unk1, unk2, unk3, unk4, unk5, unk6, unk7);
    }

    /*
    //
    void EffectCtor()
    {
      Effect_Ctor(this);
    }
    */

    //
    void dumpEffect() {
      if (effectIndex == 0x80000000)
        return;

      logColor(B_RED, "  Effect Dump (%p)  size (%i)", this, sizeof(CEffect));
      logColor(B_RED, "    Effect Type: %s (%x)", searchForEffectName(effectType), effectType);
      logColor(B_RED, "    Effect Index: %i", effectIndex);
      //logColor(B_RED, "    Effect Unk2: %x", unk2);
      //logColor(B_RED, "    Effect Unk3: %f", unk3);
      //logColor(B_RED, "    Effect Unk4: %x %x", unk4[0], unk4[1]);
      logColor(B_RED, "    Effect Setup: %x", setup);
      //logColor(B_RED, "    Effect Unk8: %x", unk8);
      //logColor(B_RED, "    Effect Unk9: %f", unk9);
      //logColor(B_RED, "    Effect Unk6: %x %x %x", unk6[0], unk6[1], unk6[2]);
      logColor(B_RED, "    BaseUnit: %p", pCBaseUnit);
      logColor(B_RED, "    Effect Value: %f", effectValue);

      // Dump the unknown lists
      {
        logColor(B_RED, "    Effect List Unknown (u32): %p", &listUnknown);
        logColor(B_RED, "      size: %i, capacity: %i", listUnknown.size, listUnknown.capacity);
        logColor(B_RED, "      elements: ");
        for (u32 i = 0; i < listUnknown.size; ++i) {
          logColor(B_RED, "        [%i]: %i", i, listUnknown[i]);
        }
      }

      {
        logColor(B_RED, "    Effect List Unknown2 (u32): %p", &listUnknown2);
        logColor(B_RED, "      size: %i, capacity: %i", listUnknown2.size, listUnknown2.capacity);
        logColor(B_RED, "      elements: ");
        for (u32 i = 0; i < listUnknown2.size; ++i) {
          logColor(B_RED, "        [%i]: %f", i, listUnknown2[i]);
        }
      }
    }
  };

#pragma pack()

};
