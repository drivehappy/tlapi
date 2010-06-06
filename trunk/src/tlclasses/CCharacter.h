#pragma once

#include "_CString.h"
#include "CBaseUnit.h"

// Size?: 160h
// Inheritance: CBaseUnit
struct CCharacter : CBaseUnit
{
  PVOID vtableIInventoryListener;
  PVOID vtableIMissle;

  float unk0[3];      // -1.0, 0.0, -100.78487

  u32 unk1;           // 343C0001h
  u32 unk2;           // 0

  PVOID pCGenericModel;

  float unk3[8];      // 0, -25.59, 0.0727, 33.62, -25.59, 0.81, 33.62, 0

  u32 unk4[2];        // 7,8

  float unk5[7];      // 4.0, 0, 0.9842, 0,0,0,0

  u32 unk6;           // 80000000h

  float unk7[5];      // 0, 1, 1, 1, 0

  PVOID pCAstarPathfiner;
  PVOID pCPath;

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

  float unk13[4];     // 2.0, 0, 0, 1

  u32 unk14[6];       // Last one ptr to CItemGold??

  // hmm getting into some weird values that appear to be garbage... is this size correct?

};
