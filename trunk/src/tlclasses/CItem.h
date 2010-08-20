#pragma once

#include "CBaseUnit.h"

namespace TLAPI
{

#pragma pack(1)

  // Size = 0x1E0
  struct CItem : CBaseUnit
  {
    PVOID pSoundBank;

    //u32 unk102[8];
    u32 unk102[7];

    wstring nameReal;
    //CString nameReal;

    u32 unk103[5];        //

    // Dump item info
    void dumpItem() {
      log("CItem Dump: %p (size: %i)", this, sizeof(CItem));
      //log(L"  nameReal: %s", nameReal.getString());
      log(L"  nameReal: %s", nameReal.c_str());
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

};
