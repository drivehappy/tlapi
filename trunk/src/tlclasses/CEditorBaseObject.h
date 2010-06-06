#pragma once

#include "_CUnknownStruct3.h"
#include "_CList.h"

#include "CRunicCore.h"

// Size?: 30h
// Note: Appears to be the base structure for all the GUID stuff
//       and additionally some ptrs
// Inheritance: CRunicCore
#
struct CEditorBaseObject : CRunicCore
{
  CList<CUnknownStruct3>    *pListUnk;

  u64 guid0;
  u64 guid1;
  u64 guid2;
  u64 guid3;


  void dumpEditorBase()
  {
    log("CEditorBaseObject: %p (size: %i)", this, sizeof(CEditorBaseObject));
    log("  pListUnk: %p", pListUnk);
    log("  guid0: %016I64X", guid0);
    log("  guid1: %016I64X", guid1);
    log("  guid2: %016I64X", guid2);
    log("  guid3: %016I64X", guid3);
  }
};
