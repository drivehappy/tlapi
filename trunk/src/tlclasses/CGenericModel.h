#pragma once

#include "Common.h"

#include "_CString.h"
#include "_CList.h"
#include "CPositionableObject.h"
#include "CAnimationSet.h"

namespace TLAPI
{

#pragma pack(1)

  // Size: 238h
  // Strict size = 238h - F0h = 148h
  struct CGenericModel : CPositionableObject
  {
    PVOID         vtable_iRandomWeight;
    PVOID         vtable_iHighlight;

    wstring       meshLocation;         // "MEDIA/LEVELSETS/PROPS/MINE_PROPS/MINE_LATERN/MINE_LATERN.MESH"
    wstring       unk0;

    u32           unk1[21];

    Ogre::SkeletonInstance *skeleton;
    //PVOID         pSkeletonInstance;    // Ogre
    
    PVOID         unk7;
    PVOID         pOctreeSM0;           // Ogre
    //CList<PVOID>  AnimationStateList;   // Ogre animation state
    CList<Ogre::AnimationState*>  animationStateList;

    PVOID        *ptrtomyself;          // Cyclic ptr to myself

    u32           unk8[19];

    CAnimationSet *animationSet;        // @1D4h

    u32           unk9[8];

    vector<PVOID> unk10;

    u32           unk11[3];

    Ogre::ShadowCaster* shadowCaster;   // @21Ch



    // 
    // Function hooks

    // Character Initialization
    EVENT_DECL(CGenericModel, void, GenericModelGetPosition,
      (CGenericModel*, Vector3, u32),
      ((CGenericModel*)e->_this, *(Vector3*)&Pz[0], Pz[1]));
  };

#pragma pack()

};
