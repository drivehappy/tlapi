#pragma once

struct CGraphManager : CRunicCore
{
  PVOID unk0;
  PVOID unk1;

  CString   location;   // "MEDIA/GRAPHS/"

  PVOID   *ptrtomyself;   // Cyclic ptr to myself

};
