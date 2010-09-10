#pragma once

namespace TLAPI {

#pragma pack(1)

  struct LinkedListNode {
    CBaseUnit*      pCBaseUnit;
    LinkedListNode* pNext;
    LinkedListNode* pPrev;
  };

#pragma pack()

};
