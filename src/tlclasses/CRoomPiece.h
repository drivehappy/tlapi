#pragma once

#include "CPositionableObject.h"

namespace TLAPI {

#pragma pack(1)

  struct CRoomPiece : CPositionableObject
  {
    PVOID     vtable_iSnap;
    PVOID     vtable_iHighlight;
    PVOID     vtable_iCollision;

    CCollisionModel     *pCCollisionModel;
    CGenericModel       *pCGenericModel;

    u32 unk11;
    CString             MeshFilename;

    u32 unk12;
    CString             UnkString;

    u32 unk13;

    u64 GUID;

    CRoomPieceData      *pCRoomPieceData;
  };

#pragma pack()

};

