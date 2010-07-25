#pragma once

#include "CRunicCore.h"
#include "CUnitTheme.h"
#include "_CString.h"

namespace TLAPI {

#pragma pack(1)

  struct CUnitThemes : CRunicCore
  {
    PVOID unk0;   // 0
    
    CUnitTheme   *pUnitTheme0;
    CString       pathLocation;

    CList<CUnitTheme *>  ThemesList;
  };

#pragma pack()

};
