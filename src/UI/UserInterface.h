#pragma once

#include "CEGUI.h"

#include "Helper.h"


namespace TLAPI {

  class UserInterface {
  private:
    static CEGUI::WindowManager *g_pWm;

  public:
    UserInterface();
    ~UserInterface() {};

    static void init();

    static CEGUI::WindowManager* getManager();

    static CEGUI::Window* getWindowFromName(const char* name);

    static CEGUI::Window* createWindow(const char* name);

    static void updateLatency(const double latency);
    static void updateChatHistory(const char* message);
    static bool isChatFocused();

    static void createWindow();

    static void showChatWindow(bool visible);

    
    static bool mouseEventChat(const CEGUI::EventArgs& args);
    static bool mouseEventMultiplayer(const CEGUI::EventArgs& args);
    static bool mouseEventCancel(const CEGUI::EventArgs& args);
    static bool mouseEventConnect(const CEGUI::EventArgs& args);
    static bool mouseEventHost(const CEGUI::EventArgs& args);
    static bool keyboardEventChat(const CEGUI::EventArgs& args);

    void dumpToFile(const char* filename);
    void dumpToLog(CEGUI::Window* window, int level=0);

  };

};
