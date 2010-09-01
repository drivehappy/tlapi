#pragma once

#include "CPositionableObject.h"

namespace TLAPI
{

#pragma pack(1)

  struct CWarper : CPositionableObject
  {
    u32 unk1000[2];

    u8  unkFlag0;
    u8  flag;
    u8  unkFlag1;
    u8  unkFlag2;
    
    wstring dungeonName;    // "Main"

    wstring unk;

    CResourceManager *pCResourceManager;

    u32 unk1001[2];   // 7, FFFFFFFFh

    u64 GUID;


  };

#pragma pack()

};
