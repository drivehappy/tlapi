#include "Test.h"

//
// This function is used for testing via keyboard inputs
//
void Test_WndProc(HWND handle, UINT msg, WPARAM wParam, LPARAM lParam)
{
  if (!(msg == 0x100 || msg == 0x101 || msg == 0x102))
    return;

  switch (msg) {
  case WM_KEYUP:
    switch (wParam) {
    
    // 1 = Dump Player Equipment (specificially just named "Wobbly Pistol")
    case '1':
      log("Dumping Player Equipment (Wobbly Equipment)");
      
      if (gameClient == NULL) {
        log("gameClient is null, cannot proceed");
        break;
      }

      gameClient->pCPlayer->dumpPlayer();

      // Grab the list and iterate through it
      const wchar_t searchTerm[] = L"Rickety Pistol";
      CList<CEquipmentRef*> *list = &gameClient->pCPlayer->pCInventory->equipmentList;

      for (u32 i = 0; i < list->size; i++) {
        wchar_t *equipmentName = (*list)[i]->pCEquipment->nameReal.getString();
        
        int val = wcscmp(equipmentName, searchTerm);

        if (val == 0) {
          CEquipment *equipment = (*list)[i]->pCEquipment;

          // We found it, dump it
          equipment->dumpEquipment();
          
          testLogger.WriteLine(Info,
            L"  Equipment (%s) Dump of unk1007 (enhancementCount = %i):",
            equipment->name.getString(), equipment->enhancementCount, equipmentName);

          for (int j = 0; j < 32; j++) {
            testLogger.WriteLine(Info,
            L"  %x",
            equipment->unk1007[j]);
          }

          testLogger.WriteLine(Info,
            L"---------------------------",
            "");

          break;
        }
      }
    }
  }

}
