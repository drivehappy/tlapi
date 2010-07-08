#pragma once

#include "CCharacter.h"
#include "CSkill.h"
#include "CInventory.h"
#include "CParticle.h"
#include "CCollisionModel.h"
#include "CSpawnClass.h"
#include "CAttackDescription.h"
#include "CAIManager.h"

namespace TLAPI
{

#pragma pack(1)

  // Size?: 6D4h
  //
  struct CMonster: CCharacter
  {
    u32     unk0;       // FFFFFFFFh
    float   unk1[7];    // 8.5, 0, 90.0, 6.5, 18.0, 2.0, 0
    u32     unk2[3];    // 100h, 0, 0
    float   unk3[2];    // 26.761753, 0

    CSkill* pSkill;

    u32     unk4[3];        // 0, 0, 0

    u64     guidMonster[3]; // 6B03517E9E3311DEh, 0FFFFFFFFFFFFFFFFh, 0FFFFFFFFFFFFFFFFh

    u32     unk5[32];   /*
                        6 dup(   0),   7,6 dup(   0),   7,6 dup(   0),   7,6 dup(   0),   7
                        4 dup(   0)
                        */

    PVOID*  unkCyclicPtr0;   // ptr to myself

    u32     unk6[2];

    CAttackDescription**  pCAttackDescription;       // This and below appear to be iterators? ptr to begin and ptr to end?
    PVOID                 pCAttackDescriptionEnd0;
    PVOID                 pCAttackDescriptionEnd1;   // Same value as above

    u32     unk7[2];    // 0, 12.0
    float   unk8[27];   //

    CInventory*         pCInventory;

    CList<CParticle*>   listParticles;

    u32     unk9;       // 0

    CString             monsterName;              // "Shadow Recluse"

    CCollisionModel*    collisionModel;

    float   unk10[12];  // 0.0, 0.5, 0.375, 1.0, 0.75,7 dup( 0.0)

    u32     unk11[41];

    PVOID*  unkCyclicPtr1;    // ptr to myself
    u32     unk12[2];         // 0, 0

    PVOID*  unkCyclicPtr2;    // ptr to myself
    u32     unk13[37];        // 1Fh dup(   0),3 dup(   3),   5,2 dup(   0)

    float   unk14[8];         // 5 dup( 0.0), 1.0, 0.0, 0.6000000

    u32     unk15[14];        // 1,6 dup(   0),2 dup(0FFFFFFFFh),5 dup(   0)

    CSpawnClass*        spawnClass; 

    u32     unk16[7];         // 1,   3, 15h,2 dup(   0),3F800000h,0B5B310CAh

    PVOID*  unkCyclicPtr3;    // ptr to myself

    u32     unk17[10];        // 9 dup(   0),   1

    CAIManager*         aiManager;

    float   unk18[3];

    CList<PVOID>        listParticleAnimationTrigger;   // Type: CCharacter::CParticleAnimationTrigger

    u32     unk19[10];        // 0,0FFFFFFFFh,6 dup(   0),   7, 96h

    float   unk20;            // 60.0



  };

#pragma pack()

};