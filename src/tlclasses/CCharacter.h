#pragma once

#include "_CString.h"
#include "CBaseUnit.h"
#include "CLevel.h"
#include "CAstarPathfinder.h"
#include "CPath.h"
#include "CGenericModel.h"
#include "CSkill.h"
//#include "CInventory.h"
#include "CResourceManager.h"
#include "CParticle.h"
#include "CCollisionModel.h"
#include "CWardrobe.h"
#include "CWeaponTrail.h"
#include "CAIManager.h"

namespace TLAPI
{

#pragma pack(1)

  struct CLevel;
  struct CCharacter;
  TLFUNC(CharacterSetAlignment, void,  __thiscall, (CCharacter*, u32));
  TLFUNC(CharacterSetDestination, void, __thiscall, (CCharacter*, CLevel*, float, float));
  TLFUNC(CharacterPickupEquipment, PVOID, __thiscall, (CCharacter*, CEquipment*, CLevel*));
  TLFUNC(CharacterAddMinion, void, __thiscall, (CCharacter*, CCharacter*));
  TLFUNC(CharacterSetAction, PVOID, __thiscall, (CCharacter*, u32));
  TLFUNC(CharacterAttack, PVOID, __thiscall, (CCharacter*));
  TLFUNC(CharacterUseSkill, PVOID, __thiscall, (CCharacter*, u64));
  TLFUNC(Character_SetOrientation, void, __thiscall, (CCharacter*, Vector3*, float));
  TLFUNC(CharacterAddSkill, void, __thiscall, (CCharacter*, wstring*, u32));
  TLFUNC(CharacterUpdateHealth, PVOID, __thiscall, (CCharacter*, float));
  TLFUNC(CharacterSetTarget, PVOID, __thiscall, (CCharacter*, CCharacter*));
  TLFUNC(PlayerResurrect, void, __thiscall, (CCharacter*));
  TLFUNC(Player_KillMonsterExperience, void, __thiscall, (CCharacter*, CLevel*, CCharacter*, u32, u32));
  TLFUNC(Character_Killed, void, __thiscall, (CCharacter*, CCharacter*, Ogre::Vector3*, float, u32));

  // 
  enum CharacterState {
    PLAYER_STATE = 0,
    UNKNOWN = 1,
    IDLE = 2,
    ATTACK1 = 3,
    TARGETTING = 4,
    BOSS_DEAD = 5,
    VISIBLE_DEAD = 6,
    BOSS_ATTACKING = 0x0E,
    BOSS_TARGETTING = 0x0F,
    HIDDEN = 0x23,
    PET_MOVING_TO_TOWN = 0x29,
    PET_IN_TOWN = 0x2A,
  };
  
  // CBaseUnit Size = 0x190
  struct CCharacter : CBaseUnit
  {
    PVOID vtableIInventoryListener;
    PVOID vtableIMissle;

    float unk0[3];      // -1.0, 0.0, -100.78487

    u32 unk1;           // 343C0001h
    u32 unk2;           // 0

    CGenericModel     *pCGenericModel0;
    CGenericModel     *pCGenericModel1;

    float unk3[7];      // -25.59, 0.0727, 33.62, -25.59, 0.81, 33.62, 0

    u32 unk4[2];        // 7,8

    // @ 1D8 = Orientation
    Vector3 orientation;    // Normalized vector
    float unk5[4];      // 4.0, 0, 0.9842, 0,0,0,0

    u32 unk6;           // 80000000h

    float unk7[4];      // 0, 1, 1, 1, 0

    u8 moving;
    u8 unkBool0;
    u8 attacking;
    u8 usingSkill;

    // @ 0x20C

    CAstarPathfinder*   pCAstarPathfiner;
    CPath*              pCPath;

    float unk8[7];      // 100, 100, 95.69, 95.69, 10, 0,0
                        /*
                          debug230:126D04A4 dd 10.0
                          debug230:126D04A8 dd 10.0
                          debug230:126D04AC dd 0.0
                          debug230:126D04B0 dd 100.0
                          debug230:126D04B4 dd 20.0
                          debug230:126D04B8 dd 2.5
                          debug230:126D04BC dd 6.2
                        */

    PVOID pCSoundBank0;
    PVOID pCSoundBank1; // Diff from above

    u32 unk9;           // FFFFFFFFh

    PVOID pBoneOgre0;   // ptr to Ogre Bone
    PVOID pBoneOgre1;   // Same ptr val as above
    PVOID pBoneOgre2;   // Diff
    PVOID pBoneOgre3;   // Diff

    PVOID unk10[2];     // NULL, NULL

    PVOID pBoneOgre4;   // Diff
    PVOID pBoneOgre5;   // Diff

    PVOID unk1111;        // NULL

    PVOID pOctree0;     // ptr Octree Node
    PVOID pOctree1;     // Diff

    PVOID unk12[2];     // NULL, NULL

    PVOID pOctree2;     // Diff

    u8   running1;
    u8   running;
    u8   running2;
    u8   running3;

    float unk13[3];     // 2.0, 0, 0, 1

    u32 state; // @A1 State

    u32 unk14;            

    u32 alignment;
    CCharacter* target;

    u32 unk1500[2];       // 

    float unk20[8];

    u32   unk21[2];
    PVOID unk22;
    u32   unk30;

    CAttackDescription  *pCAttackDescription;
    CSkill              *pCSkill;

    u32     unk15[3];        // 0, 0, 0

    u64     guidMonster[3]; // 6B03517E9E3311DEh, 0FFFFFFFFFFFFFFFFh, 0FFFFFFFFFFFFFFFFh

    wstring  Skill1;    // "Heal All I"
    wstring  Skill2;    // "TOWN PORTAL"
    wstring  Skill3;    // "Summon Zombies III"
    wstring  Skill4;    // "HEAL SELF IV"

    u32      unk23[4];    // 1, 1, 1, 1

    // @378h
    vector<CAttackDescription*>  attackDescriptions;

    u32      unk16[1];
    float    healthCurrent; // @394h
    u32      healthMax;     //
    u32      unk0016;       // 19h
    float    unk016;
    u32      unk00016;      // 0h

    u32      baseDexterity;
    u32      baseStrength;
    u32      baseDefense;
    u32      baseMagic;

    float    manaCurrent; 
    u32      manaMax;
    u32      unk000016[1];  // 0h

    u32      gold;              
    u32      experienceCurrent; // @3C8h
    u32      fameCurrent;       // @3CCh

    u32      unk17[13];

    CInventory  *pCInventory;
    CEquipment  *pCEquipment;   // @: 170. (*4)

    u32      unk18;
    CList<CParticle*>  listParticles;

    wstring characterName;
    CCollisionModel   *pCCollisionModel;

    u32      unk31;
    float    unk32[4];  // 0.5, 0.375, 1.0, 1.25

    CWardrobe         *pCWardrobe;
    wstring           playerTextureBody;
    wstring           playerTextureChest;
    wstring           playerTextureFeet;
    wstring           playerTextureHands;
    wstring           playerTexture0;

    u32     unk33[29];

    PVOID   pOgreShadowCaster;  // @ 254. (*4)

    u32     unk34[9];

    PVOID   unkPtrForType;      // Interesting code @: 4B6165  (esi + 5B4h)

    u32     unk034[16];

    CCharacter      **pCMinionStart;
    CCharacter      **pCMinionEnd;
    CCharacter      **pCMinionEnd2;

    u32     unk36[12];

    CWeaponTrail  *pCWeaponTrail;

    u32     unk35[22];

    // Cutoff here or before for Monster / Player

    void dumpCharacter(u32* & dataCopy, u32& size) {
      u32 org = sizeof(CBaseUnit);
      u32 sizeDiff = sizeof(CCharacter) - sizeof(CBaseUnit);
      u32 *ptr = (u32*)this;

      bool dumpChanges = size != 0;

      if (size == 0) {
        size = sizeDiff / sizeof(u32);
        dataCopy = new u32[size];
      }

      logColor(B_GREEN, L"Character Dump: %p (sizeof: %x - basesizeof: %x)", this, sizeof(CCharacter), sizeof(CBaseUnit));
      logColor(B_GREEN, L"  size = %x", size);

      logColor(B_GREEN, L"  visibility_test2   = %x  Offset: %x", state, (u32*)&state - (u32*)this);
    
      // Dump the raw data, trying to find the visibility flag
      for (u32 i = 0; i < sizeof(CCharacter) / sizeof(u32); i++) {
        // If we're dumping changes, see if the data is different, if so dump it out
        if (dumpChanges) {
          if (dataCopy[i] != *ptr) {
            log("Diff: @OFFSET: %x  Old: %x  New: %x", i * sizeof(u32), dataCopy[i], *ptr);
          }
        } else {
          printf("%08X ", *ptr);
          if ((i+1) % 16 == 0)
            printf("\n");
        }

        dataCopy[i] = *ptr;
        ptr++;
      }

      /*
      logColor(B_GREEN, L"  Strength: %i", baseStrength);
      logColor(B_GREEN, L"  Dexterity: %i", baseDexterity);
      logColor(B_GREEN, L"  Defense: %i", baseDefense);
      logColor(B_GREEN, L"  Magic: %i", baseMagic);
      logColor(B_GREEN, L"  Health: %f / %i", healthCurrent, healthMax);
      logColor(B_GREEN, L"  Mana: %f / %i", manaCurrent, manaMax);
      logColor(B_GREEN, L"  Gold: %i", gold);
      logColor(B_GREEN, L"  XP: %i", experienceCurrent);
      logColor(B_GREEN, L"  Fame: %i", fameCurrent);
      logColor(B_GREEN, L"  unk000016: %i", unk000016[0]);

      logColor(B_GREEN, L"   unk16[1]: %i  (%f)", unk16[0], *(float*)&unk16[0]);
      logColor(B_GREEN, L"   unk016: %i  (%f)", unk016, *(float*)&unk016);
      logColor(B_GREEN, L"   unk0016: %i  (%f)", unk0016, *(float*)&unk0016);
      logColor(B_GREEN, L"   unk00016: %i  (%f)", unk00016, *(float*)&unk00016);

      logColor(B_GREEN, L"   unk17[13]:");
      for (u32 i = 0; i < 13; i++) {
        logColor(B_GREEN, L"    unk17[%i]: %i (%f)", i, unk17[i], *(float*)&unk17[i]);
      }
      */
    }

    // 
    // Function hooks
  
    // Character Resurrect
    EVENT_DECL(CCharacter, void, PlayerResurrect,
      (CCharacter*, bool&),
      ((CCharacter*)e->_this, e->calloriginal));

    // Character Update Health
    EVENT_DECL(CCharacter, void, CharacterUpdateHealth,
      (CCharacter*, float, bool&),
      ((CCharacter*)e->_this, *(float*)&Pz[0], e->calloriginal));

    // Character Add Skill
    EVENT_DECL(CCharacter, void, CharacterAddSkill,
      (CCharacter*, wstring*, u32, bool&),
      ((CCharacter*)e->_this, (wstring*)Pz[0], Pz[1], e->calloriginal));

    // Character Setup Skills
    EVENT_DECL(CCharacter, void, CharacterSetupSkills,
      (CCharacter*, CDataGroup*, u32, bool&),
      ((CCharacter*)e->_this, (CDataGroup*)Pz[0], Pz[1], e->calloriginal));

    // Character Initialization
    EVENT_DECL(CCharacter, void, CharacterDtor,
      (CCharacter*),
      ((CCharacter*)e->_this));

    // Character Set Alignment
    EVENT_DECL(CCharacter, void, CharacterSetAlignment,
      (CCharacter*, u32, bool&),
      ((CCharacter*)e->_this, Pz[0], e->calloriginal));
    
    // Character Use Skill
    EVENT_DECL(CCharacter, void, CharacterUseSkill,
      (CCharacter*, u64, bool&),
      ((CCharacter*)e->_this, *(u64*)&Pz[0], e->calloriginal));

    // Character Set Destination
    EVENT_DECL(CCharacter, void, CharacterSetDestination,
      (CCharacter*, CLevel*, float, float),
      ((CCharacter*)e->_this, (CLevel*)Pz[0], *(float*)&Pz[1], *(float*)&Pz[2]));
    
    // Character Set Action
    EVENT_DECL(CCharacter, void, CharacterSetAction,
      (CCharacter*, u32, bool&),
      ((CCharacter*)e->_this, Pz[0], e->calloriginal));
        
    // Character Set Target
    EVENT_DECL(CCharacter, void, CharacterSetTarget,
      (CCharacter*, CCharacter*, bool&),
      ((CCharacter*)e->_this, (CCharacter*)Pz[0], e->calloriginal));

    // Character Attack
    EVENT_DECL(CCharacter, void, CharacterAttack,
      (CCharacter*, bool&),
      ((CCharacter*)e->_this, e->calloriginal));

    // Character Add Minion
    EVENT_DECL(CCharacter, void, CharacterAddMinion,
      (CCharacter*, CCharacter*),
      ((CCharacter*)e->_this, (CCharacter*)Pz[0]));
    
    // Character Strike
    EVENT_DECL(CCharacter, void, CharacterStrike,
      (CCharacter*, CLevel*, CCharacter*, PVOID, u32, float, float, u32, bool&),
      ((CCharacter*)e->_this, (CLevel*)Pz[0], (CCharacter*)Pz[1], (PVOID)Pz[2], Pz[3], *(float*)&Pz[4], *(float*)&Pz[5], Pz[6], e->calloriginal));

    // Character Pickup Equipment
    EVENT_DECL(CCharacter, void, CharacterPickupEquipment,
      (CCharacter*, CEquipment*, CLevel*, bool&),
      ((CCharacter*)e->_this, (CEquipment*)Pz[0], (CLevel*)Pz[1], e->calloriginal));

    // This isn't a real update function, something odd
    // Character Update
    EVENT_DECL(CCharacter, void, Character_Update,
      (CCharacter*, PVOID, float*, float, bool&),
      ((CCharacter*)e->_this, (PVOID)Pz[0], (float*)Pz[1], *(float*)&Pz[2], e->calloriginal));

    // Doesn't work
    // Character Orientation
    EVENT_DECL(CCharacter, void, Character_SetOrientation,
      (CCharacter*, Vector3*, float, bool&),
      ((CCharacter*)e->_this, (Vector3*)Pz[0], *(float*)&Pz[1], e->calloriginal));

    // Character Update Level
    EVENT_DECL(CCharacter, void, Character_Update_Level,
      (CCharacter*, CLevel*, float, bool&),
      ((CCharacter*)e->_this, (CLevel*)Pz[0], *(float*)&Pz[1], e->calloriginal));

    // Character Update Character
    EVENT_DECL(CCharacter, void, Character_Update_Character,
      (CCharacter*, CCharacter*, bool&),
      ((CCharacter*)e->_this, (CCharacter*)Pz[0], e->calloriginal));

    // Player Kill Monster, with Experience
    EVENT_DECL(CCharacter, void, Player_KillMonsterExperience,
      (CCharacter*, CLevel*, CCharacter*, u32, u32, bool&),
      ((CCharacter*)e->_this, (CLevel*)Pz[0], (CCharacter*)Pz[1], Pz[2], Pz[3], e->calloriginal));

    //
    EVENT_DECL(CCharacter, void, Character_Killed,
      (CCharacter*, CCharacter*, Ogre::Vector3*, float, u32, bool&),
      ((CCharacter*)e->_this, (CCharacter*)Pz[0], (Ogre::Vector3*)Pz[1], *(float*)&Pz[2], Pz[3], e->calloriginal));

    

    
    void KillMonsterExperience(CLevel* level, CCharacter* monster, u32 experience, u32 unk0) {
      Player_KillMonsterExperience(this, level, monster, experience, unk0);
    }
    void Resurrect() {
      PlayerResurrect(this);
    }
    void SetTarget(CCharacter* target) {
      CharacterSetTarget(this, target);
    }
    void UpdateHealth(float amount) {
      CharacterUpdateHealth(this, amount);
    }
    void AddSkill(wstring* name, u32 unk0) {
      CharacterAddSkill(this, name, unk0);
    }
    void SetOrientation(Vector3 direction) {
      Character_SetOrientation(this, &direction, 1.0f);
    }
    void UseSkill(u64 skill) {
      CharacterUseSkill(this, skill);
    }
    void SetAlignment(u32 alignment) {
      CharacterSetAlignment(this, alignment);
    }
    void SetAction(u32 action) {
      CharacterSetAction(this, action);
    }
    void Attack() {
      CharacterAttack(this);
    }
    void SetDestination(CLevel* level, float x, float z) {
      CharacterSetDestination(this, level, x, z);
    }
    void PickupEquipment(CEquipment* equipment, CLevel* level) {
      CharacterPickupEquipment(this, equipment, level);
    }
    void AddMinion(CCharacter *minion) {
      CharacterAddMinion(this, minion);
    }
    vector<CCharacter*>* GetMinions() {
      vector<CCharacter*> *retval = new vector<CCharacter*>;
      CCharacter **itr = pCMinionStart;
      while (itr != pCMinionEnd) {
        retval->push_back((*itr));
        itr++;
      }
      return retval;
    }

  };

#pragma pack()

};
