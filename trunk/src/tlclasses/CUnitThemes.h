#pragma once

#include "CRunicCore.h"
#include "CUnitTheme.h"
#include "_CString.h"

struct CUnitThemes : CRunicCore
{
  PVOID unk0;   // 0
  
  CUnitTheme   *pUnitTheme0;
  CString       pathLocation;

  CList<CUnitTheme *>  ThemesList;
};
