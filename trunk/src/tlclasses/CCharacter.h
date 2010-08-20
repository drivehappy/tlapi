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

    float unk5[7];      // 4.0, 0, 0.9842, 0,0,0,0

    u32 unk6;           // 80000000h

    float unk7[4];      // 0, 1, 1, 1, 0

    u8 moving;
    u8 unkBool0;
    u8 attacking;
    u8 unkBool1;

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

    PVOID unk11;        // NULL

    PVOID pOctree0;     // ptr Octree Node
    PVOID pOctree1;     // Diff

    PVOID unk12[2];     // NULL, NULL

    PVOID pOctree2;     // Diff

    u8   running1;
    u8   running;
    u8   running2;
    u8   running3;

    float unk13[3];     // 2.0, 0, 0, 1

    u32 unk14[3];       // 
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

    u32      unk23[3];    // 1, 1, 1, 1
    u32      unk24[3];

    CAttackDescription **pCAttackDescription2;

    CAttackDescription *pCAttackDescriptionEnd0;
    CAttackDescription *pCAttackDescriptionEnd1;   // Same value as above

    u32      unk16[3];
    u32      health;
    u32      unk016[8];
    u32      mana;
    u32      unk0016[1];

    u32      gold;

    u32      unk17[15];

    CInventory  *pCInventory;
    CEquipment  *pCEquipment;

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

    PVOID   pOgreShadowCaster;

    u32     unk34[26];

    CCharacter      **pCMinionStart;
    CCharacter      **pCMinionEnd;
    CCharacter      **pCMinionEnd2;

    u32     unk36[12];

    CWeaponTrail  *pCWeaponTrail;

    u32     unk35[22];

    CAIManager    *pCAIManager;

    // 
    // Function hooks

    // Character Initialization
    EVENT_DECL(CCharacter, void, CharacterCtor,
      (CCharacter*),
      ((CCharacter*)e->_this));

    // Character Set Alignment
    EVENT_DECL(CCharacter, void, CharacterSetAlignment,
      (CCharacter*, u32),
      ((CCharacter*)e->_this, Pz[0]));
    
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
      (CCharacter*, CLevel*, CCharacter*, PVOID, u32, float, float, u32),
      ((CCharacter*)e->_this, (CLevel*)Pz[0], (CCharacter*)Pz[1], (PVOID)Pz[2], Pz[3], *(float*)&Pz[4], *(float*)&Pz[5], Pz[6]));

    // Character Pickup Equipment
    EVENT_DECL(CCharacter, void, CharacterPickupEquipment,
      (CCharacter*, CEquipment*, CLevel*, bool&),
      ((CCharacter*)e->_this, (CEquipment*)Pz[0], (CLevel*)Pz[1], e->calloriginal));




    // Set Alignment
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
