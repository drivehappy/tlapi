#pragma once

#include "_CString.h"
#include "_CList.h"

struct CCinematics : CRunicCore
{
  PVOID unk0;
  PVOID unk1;

  CString location;   // "media/cinematics/"

  CList<PVOID>     CinematicsList;

  // Unk rest
};