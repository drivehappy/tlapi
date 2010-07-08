#pragma once

#include "CPositionableObjectDescriptor.h"
#include "CLogicWrapper.h"
#include "CPathController.h"
#include "CDescriptorProp.h"

namespace TLAPI
{

#pragma pack(1)

  struct CPathControllerDescriptor : CPositionableObjectDescriptor
  {
    PVOID   vtable;
    u64     guid[4];
    PVOID   unk0[3];
    CString unk1;           // "\0topped" len = 0
    PVOID   pEditorScene0;

    u32     unk2[3];        // 0, 0F, 4
    CString unk3;           // "Pathing"
    u32     unk4;

    CString unk5;           // "Pathing"
    CString unk6;           // "Pathing"
    CString unk7;           // "Logic"

    u32     unk8[2];        // 4548h, 33h
    PVOID   unk9;
    PVOID   unk10;

    u32     unk11[4];       // 18h, 4Ah, 563D6h, 40h

    PVOID   unk12;
    u32     unk13;          // 0Bh

    CList<CDescriptorProp*> listDescriptorProps;
    u32     unk14[4];       // 0, 0, 0, 0Ah

    CList<CPathController*> listPathControllers;
    u32     unk15[4];       // 0, 0, 0, 0Ah

    CList<CLogicWrapper*>   listLogicWrappers0;
    CList<CLogicWrapper*>   listLogicWrappers1;

    // ... maybe more
  };

#pragma pack()

};
