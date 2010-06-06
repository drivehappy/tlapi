#pragma once

#include "_CList.h"

#include "CLayout.h"
#include "CQuadTree.h"
#include "CCollisionList.h"

// Size?: 17Ch
struct CLevel : CRunicCore
{
  u32 unk0;
  
  CList<CLayout*>    CLayoutsList;

  u32 unk1;           // 3
  u32 unk2;           // 0Ah
  u32 unk3;           // 0Ah
  PVOID unk4;         // ptr to unk struct

  u32 unk5;           // 3
  u32 unk6;           // 0Ah
  u32 unk7;           // 0Ah
  PVOID unk8;         // ptr to unk struct
  PVOID unk9;         // ptr to unk struct

  u32 unk10[3];       // 195h, 186h, 3C81h

  CQuadtree          *pCQuadTree;       // ptr to CQuadTree
  CCollisionList     *pCCollisionList;  // ptr to CCollisionList
  u32 unk11;          // Cylic ptr to itself

  float unk12[2];     // 1, 1

  PVOID unk13[3];     // Odd structure

  PVOID unk14[5];     // Another odd structure

  u32 unk15;          // 7
  u32 unk16;          // 46h
  u32 unk17;          // 0Ah

  PVOID unk18[4];

  float unk19[2];     // 1, 1

  PVOID* ppCPropertyNode;   // ptr ptr to CPropertyNode

  PVOID unk20;
  PVOID unk21;

  // ...
};
