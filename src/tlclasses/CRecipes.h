#pragma once

#include "_CString.h"
#include "_CList.h"

struct CRecipes : CRunicCore
{
  PVOID unk0;

  PVOID unk1;       // ptr to unknown structure - probably some recipe structure
  CString location; // "media/recipes/"

  CList<PVOID> RecipesList;

  u32 unk2;         // 46CC1340h
  u32 unk3;         // 4Bh      -- noticed this alot, is this a compiler signal for end of class?
};
