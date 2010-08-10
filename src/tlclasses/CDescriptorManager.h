#pragma once

#include "CRunicCore.h"
#include "CDescriptor.h"
#include "CLayout.h"

namespace TLAPI {

#pragma pack(1)


  struct CDescriptorManager : CRunicCore
  {
    u32 unk0;
    u32 unk1[6];  /*
                  debug239:19A24A48 off_19A24A48 dd offset off_1760C510     ; DATA XREF: debug229:off_1760C510o
                  debug239:19A24A4C dd 2A1F1Ch
                  debug239:19A24A50 dd 2E231Eh
                  debug239:19A24A54 dd 2C211Dh
                  debug239:19A24A58 dd 2A1F1Ch
                  debug239:19A24A5C dd 291F1Bh
                  */
    PVOID unk2;
    u32   unk3[4];

    //PVOID unkDescriptorArray; // Not a CList, but some other container struct

    CDescriptor *pCDescriptorStart;
    CDescriptor *pCDescriptorMid;
    CDescriptor *pCDescriptorEnd;

    CLayout *pCLayout;

  };

#pragma pack()

};

