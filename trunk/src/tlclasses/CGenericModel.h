#pragma once

// Size: Unknown
// 
struct CGenericModel : CPositionableObject
{
  PVOID     vtable_iRandomWeight;
  PVOID     vtable_iHighlight;
  PVOID     unk0;

  CString   meshLocation; // "MEDIA/LEVELSETS/PROPS/MINE_PROPS/MINE_LATERN/MINE_LATERN.MESH"

  float unk1[6];    // 0.0,3 dup( 1.0),2 dup( 0.0)
  u32 unk2;         // 7
  float unk3;       // 1.0
  u32 unk4[3];      // 345F6D67h  343534h   0h
  float unk5;       // 1.0
  u32 unk6[9];      //   7, 0Fh,0E8E8E0E0h,410000h,202020Ah,   0,0AAAAAAAAh,   0, 0Fh

  PVOID         pSkeletonInstance;    // Ogre
  PVOID         unk7;
  PVOID         pOctreeSM0;           // Ogre
  CList<PVOID>  AnimationStateList;   // Ogre animation state

  PVOID         *ptrtomyself;         // Cyclic ptr to myself

};
