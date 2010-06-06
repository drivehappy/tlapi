#pragma once

// Size?:
// 
struct CHierarchy : CRunicCore
{
  PVOID unk0;

  PVOID *ptrtomyself;     // Cyclic ptr to point to myself
};
