#pragma once

#include "CBaseUnit.h"

// Size?: 180h
// Inheritance: CBaseUnit
#pragma pack(1)
struct CItem : CBaseUnit
{
  PVOID pSoundBank;

  u32 unk102[8];

  CString nameReal;

  u32 unk103[5];        //


  // Dump item info
  void dumpItem() {
    log("CItem Dump: %p (size: %i)", this, sizeof(CItem));
    log(L"  nameReal: %s", nameReal.getString());
    log("  SoundBank: %p", pSoundBank);

    for (int i = 0; i < 8; i++) {
      log("  unk102[%i] = %i (%p)", i, unk102[i], unk102[i]);
    }
    for (int i = 0; i < 5; i++) {
      log("  unk103[%i] = %i (%p)", i, unk103[i], unk103[i]);
    }

    dumpBaseUnit();
    dumpPosObj();
    dumpSceneNodeObject();
    dumpEditorBase();
  };
};
#pragma pack()
