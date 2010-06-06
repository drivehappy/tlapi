#pragma once

#include "CRunicCore.h"

// Size?: 118h
struct CItemSaveState : CRunicCore
{
  u32 unk0;

  CItemSaveState *pCItemSaveState;    // Linked list node? ptr to another CItemSaveState

  CString name;

  // .. more
};
