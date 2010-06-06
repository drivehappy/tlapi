#pragma once

// Size?: unk
struct CLevelLayout : CRunicCore
{
  u32 unk0;
  PVOID pChunkList;   // Probably: CList<CChunk*>
};
