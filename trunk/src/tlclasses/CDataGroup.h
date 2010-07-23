#pragma once

#include "CRunicCore.h"
#include "CDataValue.h"

namespace TLAPI
{

#pragma pack(1)

  struct CDataGroup : CRunicCore
  {
    u32     unk0;
    u32     unk1;         // 3211h
    PVOID   unk2;

    CList<CDataValue*>    listDataValues;
    CList<CDataGroup*>    listDataGroups;

    //CDataGroup*           unk3;


    void dumpDataGroup() {
      logColor(B_RED, "  DataGroup Dump: %p (basesize: %i)", this, sizeof(CDataGroup));
      logColor(B_RED, "    unk0: %x", unk0);
      logColor(B_RED, "    unk1: %x", unk1);
      logColor(B_RED, "    unk2: %p", unk2);
      logColor(B_RED, "    DataValues: Size = %i", listDataValues.size);

      for (u32 i = 0; i < listDataValues.size; i++) {
        listDataValues[i]->dumpValues();
      }

      logColor(B_RED, "    DataGroup: Size = %i", listDataGroups.size);

      for (u32 i = 0; i < listDataGroups.size; i++) {
        logColor(B_GREEN, "    subDataGroup [%i]:", i);
        listDataGroups[i]->dumpDataGroup();
      }
    }
  };

#pragma pack()

};
