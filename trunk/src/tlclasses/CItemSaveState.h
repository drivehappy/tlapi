#pragma once

#include "CRunicCore.h"

namespace TLAPI {

#pragma pack(1)

  // Size?: 118h
  struct CItemSaveState : CRunicCore
  {
    u32 unk0;

    CItemSaveState *pCItemSaveState;    // Linked list node? ptr to another CItemSaveState

    CString name;

    // .. more


    void dumpItemSaveState()
    {
      log("ItemSaveState (%p)", this);
      log(L"  name: %s", name.getString());
      log("  Next: %p", pCItemSaveState);
    };
  };

#pragma pack()

};
