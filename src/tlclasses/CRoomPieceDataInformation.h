#pragma once

#include "CResourceSettings.h"

struct CRoomPieceDataInformation : CRunicCore
{
  PVOID unk0;

  typedef struct CRoomPieceCoreData {
    u32 unk0;
    u32 unk1;

    CString roomPieceName;    // "MINE_WOOD_ARM"

    u32 unk2;

    u64 GUID;

    u32 unk3;

    CList<PVOID>        UnkList0;
    CList<PVOID>        UnkList1;
    CList<PVOID>        UnkList2;
    CList<PVOID>        UnkList3;

    CList<PVOID>        UnkList4;   // list of unknown struct
    CList<PVOID>        UnkList5;   // list of unknown struct
  } *pRoomPieceCoredData;

  CResourceSettings   *pResourceSettings;

  PVOID *ptrtomyself;       // cyclic ptr to myself
};
