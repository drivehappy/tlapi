#pragma once

struct CDungeonManager : CRunicCore
{
  PVOID unk0;
  PVOID unk1;

  CString location;   // "MEDIA/DUNGEONS/"

  CList<Dungeon *>   CDungeonList;

};
