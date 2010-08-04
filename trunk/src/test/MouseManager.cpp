#include "Test.h"
#include "UserInterface.h"

bool suppressInGameMouse = false;

void Test_MouseManagerHandleInput(CMouseManager* mouseManager, u32 wParam, u32 mouseButton, bool* callOriginal)
{
  if (suppressInGameMouse) {
    // Suppress only mouse button down
    if (wParam == 0x201 || wParam == 0x204) {
      *callOriginal = false;
    }
  }

  //log("MouseManager HandleInput: %p %x %x %i",
  //  mouseManager, wParam, mouseButton, *callOriginal);
}
