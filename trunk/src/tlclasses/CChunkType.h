#pragma once

// Size?: 60h
// Inheritance: CRunicCore
struct CChunkType : CRunicCore
{
  u32 unk0[6];                // 0, 10001h, 1, 1, 1, 0
  PVOID pStringMediaLayout;   // ptr string "media/layouts/mainmenus/1X1SINGLE_ROOM_MINE/"
  u32 unk1[10];               // 0, 0, 0, 2Ch, 2Fh, 0, 0,0, 2, 0
  PVOID pStringRoom;          // ptr string "1X1SINGLE_ROOM_MINE"

};
