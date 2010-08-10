#pragma once

#include "Helper.h"
#include "Logger.h"
#include "UserInterface.h"

#include "Test.h"

#include "CMonsterDescriptor.h"

// Event handlers
bool mouseEventOk(const CEGUI::EventArgs& args);
bool mouseEventInGameOk(const CEGUI::EventArgs& args);

//
void Create_InGameMenu();
void Create_MainMain();

void Test_MainWindow();
