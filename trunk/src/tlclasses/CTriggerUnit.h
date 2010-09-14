#pragma once

#include "CItem.h"
#include "CLayout.h"
#include "CGenericModel.h"
#include "CCollisionModel.h"

namespace TLAPI {

#pragma pack(1)

  //
  struct CTriggerUnit;
  TLFUNC(TriggerUnitTriggered, PVOID, __thiscall, (CTriggerUnit*, CPlayer*));
  TLFUNC(TriggerUnit_Ctor, CTriggerUnit*, __thiscall, (CLayout*));

  //
  struct CTriggerUnit : CItem
  {
    CGenericModel   *pCGenericModel;
    CCollisionModel *pCCollisionModel;
    u32              unk0[7];

    wstring          name;
    CList<u32>       unkList0;
    CList<PVOID>     unkList1;
    CList<PVOID>     unkList2;
    CList<CLayout*>  layoutList;

    u32              unk1;
    wstring          name2;



    // TriggerUnit Ctor
    EVENT_DECL(CTriggerUnit, void, TriggerUnit_Ctor,
      (CTriggerUnit*, CLayout*, bool&),
      ((CTriggerUnit*)e->retval, (CLayout*)e->_this, e->calloriginal));

    // TriggerUnit Triggered
    EVENT_DECL(CTriggerUnit, void, TriggerUnitTriggered,
      (CTriggerUnit*, CPlayer*, bool&),
      ((CTriggerUnit*)e->_this, (CPlayer*)Pz[0], e->calloriginal));

    
  
    void Trigger(CPlayer *player) {
      TriggerUnitTriggered(this, player);
    }

  };

#pragma pack()

};
