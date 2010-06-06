#pragma once

struct CMonsterDescriptor : CPositionableObjectDescriptor
{
  // FYI: This Contains base members

  PVOID unk0;

  u64 guid0;
  u64 guid1;
  u64 guid2;
  u64 guid3;

  PVOID pAnimationTrack;  // ogre

  PVOID unk1;
  PVOID unk2;
  PVOID unk3;
  u32 unk4;
  u32 unk5;

  PVOID unk6;
  u32 unk7;
  u32 unk8;

  CLayout  *pCLayout;

  PVOID unk9[3];

  CString   name0;    // Unicode "Monster"
  CString   desc0;    // "Monster in the level"
  CString   name1;    // Unicode "monster"
  CString   desc1;    // "Building Blocks"

  PVOID     *ptrtomyself;   // Cyclic ptr to myself

  // May have run into garbage data from this down

  u32 unk10;

  CList<CDescriptorProp *>    CDescriptorPropList;

  u32 unk11[4];       // 0, 0, 0, 0Ah

  CList<CMonster *>           CMonsterList;
  
  u32 unk12[4];       // 0, 0, 0, 0Ah

  CList<CLogicWrapper *>      CLogicWrapper0;
  CList<CLogicWrapper *>      CLogicWrapper1;

  PVOID   *ptrtomyself2;   // Cyclic ptr to myself
};
