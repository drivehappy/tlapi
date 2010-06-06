#pragma once

#include "CPositionableObjectDescriptor.h"

struct CWarperDescriptor : CPositionableObjectDescriptor
{
  PVOID unk0;

  PVOID guid0;
  PVOID guid1;
  PVOID guid2;
  PVOID guid3;

  u32 unk1[13];   // 0s

  CString   name;
  PVOID     unk2;

  CString   description;
  PVOID     unk3;

  CString   name2;
  PVOID     unk2;

  u32       unk3[8];
  PVOID     *ptrtomyself;    // Cyclic ptr to myself
};
