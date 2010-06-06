#pragma once

struct CGameUI : CRunicCore
{
  PVOID unk0;             // TODO -- vtable?? if so remove (defined in CRunicCore)
  PVOID pOctreeSM[4];     // 4 ptrs to Octrees
  PVOID pCSoundManager;   // ptr to CSoundManager
  PVOID pCPlayer;         // ptr to CPlayer
};
