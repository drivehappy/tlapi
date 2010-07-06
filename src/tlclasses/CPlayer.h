#pragma once

#include "Common.h"
#include "Events.h"

#include "CCharacter.h"
#include "CSkill.h"
#include "CInventory.h"
#include "CResourceManager.h"

namespace TLAPI
{

  //
#pragma pack(1)

  struct CPlayer: CCharacter
  {
    float unk0[8];

    u32   unk1[2];
    PVOID unk2;
    u64   unkGUID;

    CSkill  *pCSkill;

    u32   unk3[3];

    u64   unkGUID2[3];

    float unk4;

    CString  Skill1;        // "Heal All I"
    CString  UnkString0;     // This is actually non-wide string
    u32      unk5;
    CString  Skill2;        // "Summon Zombies III"
    CString  UnkString1;     // This is actually non-wide string

    u32      unk6[40];

    CInventory  *pCInventory;


    // Character Set Action
    EVENT_DECL(CPlayer, void, PlayerUseSkill,
      (u32, CPlayer*, u64),
      (e->retval, (CPlayer*)e->_this, *(u64*)&Pz[0]));

    
    void dumpPlayer()
    {
      log("CPlayer dump: %p (sizeof CPlayer: %i)", this, sizeof(CPlayer));
      log("  CPlayer dump: (sizeof CCharacter: %i)", sizeof(CCharacter));
    }
  };

#pragma pack()

};
