#pragma once

//#include "CEquipment.h"

// Size: Unknown
// Note: Tied to CEditorBaseObject, first member contains a ptr to a list of these
struct CUnknownStruct3
{
  PVOID          *pCEquipment;
  u32             index;        // ? each element increments this

  // Unk rest, varies between floats and CPlayer* 's...
};
