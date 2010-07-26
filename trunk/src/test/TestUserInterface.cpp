#include "TestUserInterface.h"

using namespace TLAPI;

void Test_MainWindow()
{
  log("Test_MainWindow() Creating...");

  UserInterface UI;

  UI.init();
  UI.createWindow();
}
