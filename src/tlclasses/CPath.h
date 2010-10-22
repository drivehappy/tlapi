#pragma once

#include "CRunicCore.h"

namespace TLAPI
{

  struct CPath;
  struct CInventory;
  TLFUNC(Path_GetNextNode, void, __thiscall, (CPath*, Vector3*, float));

#pragma pack(1)

  // Size?: B0h
  struct CPath : CRunicCore
  {
    u32 unk00;

    u32 unk0[6];
    float unk1;

    u32 unk2[4];
    vector<Vector3> unk3;
    vector<float>   unk4;
    vector<float>   unk5;
    vector<u32>     unk6;
    vector<float>   unk7;


    // Path get next node - this is used for updating the character orientation
    EVENT_DECL(CPath, void, Path_GetNextNode,
      (CPath*, Vector3*, float),
      ((CPath*)e->_this, (Vector3*)Pz[0], *(float*)&Pz[1]));
  };

#pragma pack()

};
