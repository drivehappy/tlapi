#pragma once

#include "CRunicCore.h"
#include "_CString.h"

namespace TLAPI {

#pragma pack(1)

  struct CWardrobe : CRunicCore
  {
    u32 unk0;

    PVOID pOctree0;

    PVOID pCGenericModel;

    PVOID unk1;

    PVOID pShadowCaster;    // ogre

    PVOID unk2;

    CString name;

    PVOID pTexturePtr;    // ogre
    PVOID unk3;
    PVOID unk4;

    PVOID unk5;           // NULL
  };

#pragma pack()

};

