#include "UserInterface.h"

using namespace TLAPI;


CEGUI::WindowManager* TLAPI::UserInterface::g_pWm = NULL;

UserInterface::UserInterface()
{
  g_pWm = NULL;
}

void UserInterface::init()
{
  g_pWm = CEGUI::WindowManager::getSingletonPtr();
}

CEGUI::Window* UserInterface::getWindowFromName(const char* name)
{
  if (!g_pWm)
    return NULL;

  if (!g_pWm->isWindowPresent(CEGUI::String(name)))
    return NULL;

  CEGUI::Window* wd = g_pWm->getWindow(CEGUI::String(name));

  return wd;
}

CEGUI::Window* UserInterface::createWindow(const char* name)
{
  if (!g_pWm)
    return NULL;

  return g_pWm->createWindow(CEGUI::String("DefaultWindow"), CEGUI::String(name));
}

void UserInterface::createWindow()
{
  if (!g_pWm)
    return;

  log("Creating window");
  CEGUI::Window *windowHost, *windowConnect, *windowParent;

  windowHost = g_pWm->createWindow(CEGUI::String("GuiLook/StandardButton"), CEGUI::String("Multiplayer_Host"), CEGUI::String("25_"));
  windowConnect = g_pWm->createWindow(CEGUI::String("GuiLook/StandardButton"), CEGUI::String("Multiplayer_Connect"), CEGUI::String("25_"));

  windowParent = getWindowFromName("25_Root");

  if (windowParent) {
    windowParent->addChildWindow(windowHost);
    windowHost->setProperty(CEGUI::String("UnifiedAreaRect"), CEGUI::String("{{0.105,0},{0.815,0},{0.295,0},{0.88,0}}"));
    windowHost->setText("Multiplayer");
    windowHost->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&mouseEventMultiplayer));
    windowHost->moveToFront();
    windowHost->setVisible(true);

  } else {
    log("Couldn't find Journal Window!\n");
  }

  // Create Connection Window
  CEGUI::Window *windowConnection, *windowSheet, *windowFrame;
  CEGUI::Editbox *editBox;
  windowConnection = g_pWm->createWindow(CEGUI::String("DefaultWindow"), CEGUI::String("Multiplayer_ConnectionInfo"), CEGUI::String("666_"));
  windowConnection->setProperty(CEGUI::String("UnifiedMaxSize"), CEGUI::String("{{1,0},{1,0}}"));
  windowConnection->setProperty(CEGUI::String("UnifiedAreaRect"), CEGUI::String("{{0,0},{0,0},{1,0},{1,0}}"));
  windowConnection->setVisible(false);
  
  {
    windowFrame = g_pWm->createWindow(CEGUI::String("GuiLook/StaticImage"), CEGUI::String("Multiplayer_ConnectionBackground"), CEGUI::String("666_"));
    windowFrame->setProperty(CEGUI::String("Image"), CEGUI::String("set:GuiLook image:GrayLine"));
    windowFrame->setProperty(CEGUI::String("UnifiedMaxSize"), CEGUI::String("{{1,0},{1,0}}"));
    windowFrame->setProperty(CEGUI::String("UnifiedAreaRect"), CEGUI::String("{{0,0},{0,0},{1,0},{1,0}}"));
    windowConnection->addChildWindow(windowFrame);

    {
      windowHost = g_pWm->createWindow(CEGUI::String("GuiLook/StaticText"), CEGUI::String("Multiplayer_ConnectionInfo_HostTxt"), CEGUI::String("666_"));
      windowHost->setText("Multiplayer");
      windowHost->setProperty(CEGUI::String("UnifiedPosition"), CEGUI::String("{{.5,-50},{.5,-250}}"));
      windowHost->setProperty(CEGUI::String("UnifiedSize"), CEGUI::String("{{0,160},{0,28}}"));
      windowHost->setProperty(CEGUI::String("Font"), CEGUI::String("SerifBig"));
      windowFrame->addChildWindow(windowHost);

      windowHost = g_pWm->createWindow(CEGUI::String("GuiLook/StaticText"), CEGUI::String("Multiplayer_ConnectionInfo_HostAbout"), CEGUI::String("666_"));
      windowHost->setText("(Created by dengus and drivehappy)");
      windowHost->setProperty(CEGUI::String("TextColour"), CEGUI::String("FF00FFFF"));
      windowHost->setProperty(CEGUI::String("HorzTextFormatting"), CEGUI::String("WordWrapCentreAligned"));
      windowHost->setProperty(CEGUI::String("UnifiedPosition"), CEGUI::String("{{.5,-150},{.5,-200}}"));
      windowHost->setProperty(CEGUI::String("UnifiedSize"), CEGUI::String("{{0,300},{0,28}}"));
      windowHost->setProperty(CEGUI::String("Font"), CEGUI::String("Serif"));
      windowFrame->addChildWindow(windowHost);
    }

    {
      windowHost = g_pWm->createWindow(CEGUI::String("GuiLook/StandardButton"), CEGUI::String("Multiplayer_ConnectionInfo_Cancel"), CEGUI::String("666_"));
      windowHost->setText("Cancel");
      windowHost->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&mouseEventCancel));
      windowHost->setProperty(CEGUI::String("UnifiedPosition"), CEGUI::String("{{.5,-240},{.70,0}}"));
      windowHost->setProperty(CEGUI::String("UnifiedSize"), CEGUI::String("{{0,152},{0,28}}"));
      windowFrame->addChildWindow(windowHost);
    }

    {
      windowHost = g_pWm->createWindow(CEGUI::String("GuiLook/StandardButton"), CEGUI::String("Multiplayer_ConnectionInfo_Host"), CEGUI::String("666_"));
      windowHost->setText("Host");
      windowHost->setProperty(CEGUI::String("UnifiedPosition"), CEGUI::String("{{.5,-70},{.70,0}}"));
      windowHost->setProperty(CEGUI::String("UnifiedSize"), CEGUI::String("{{0,152},{0,28}}"));
      windowHost->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&mouseEventHost));
      windowFrame->addChildWindow(windowHost);
    }

    {
      windowHost = g_pWm->createWindow(CEGUI::String("GuiLook/StandardButton"), CEGUI::String("Multiplayer_ConnectionInfo_Connect"), CEGUI::String("666_"));
      windowHost->setText("Connect");
      windowHost->setProperty(CEGUI::String("UnifiedPosition"), CEGUI::String("{{.5,100},{.70,0}}"));
      windowHost->setProperty(CEGUI::String("UnifiedSize"), CEGUI::String("{{0,152},{0,28}}"));
      windowHost->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&mouseEventConnect));
      windowFrame->addChildWindow(windowHost);
    }

    {
      windowHost = g_pWm->createWindow(CEGUI::String("GuiLook/StaticText"), CEGUI::String("Multiplayer_ConnectionInfo_IPTxt"), CEGUI::String("666_"));
      windowHost->setText("IP Address:");
      windowHost->setProperty(CEGUI::String("UnifiedPosition"), CEGUI::String("{{.5,-220},{.5,-150}}"));
      windowHost->setProperty(CEGUI::String("UnifiedSize"), CEGUI::String("{{0,160},{0,28}}"));
      windowFrame->addChildWindow(windowHost);

      windowHost = g_pWm->createWindow(CEGUI::String("GuiLook/ItemText"), CEGUI::String("Multiplayer_ConnectionInfo_IPBkgd"), CEGUI::String("666_"));
      windowHost->setProperty(CEGUI::String("UnifiedPosition"), CEGUI::String("{{.5,-100},{.5,-150}}"));
      windowHost->setProperty(CEGUI::String("UnifiedSize"), CEGUI::String("{{0,160},{0,28}}"));
      windowHost->setProperty(CEGUI::String("MousePassThroughEnabled"), CEGUI::String("True"));
      windowFrame->addChildWindow(windowHost);

      editBox = static_cast<CEGUI::Editbox*>(g_pWm->createWindow(CEGUI::String("GuiLook/Editbox"), CEGUI::String("Multiplayer_ConnectionInfo_IP"), CEGUI::String("666_")));
      editBox->setText("");
      editBox->setProperty(CEGUI::String("UnifiedPosition"), CEGUI::String("{{.5,-100},{.5,-150}}"));
      editBox->setProperty(CEGUI::String("UnifiedSize"), CEGUI::String("{{0,160},{0,28}}"));
      windowFrame->addChildWindow(editBox);

      // Set Editbox with IP
      FILE *f;
      fopen_s(&f, "ip.txt","r");
      if (!f) log("failed to open ip.txt :(");
      else {
        char buf[0x100];
        fgets(buf,0x100,f);
        fclose(f);
        editBox->setText(CEGUI::String(buf));
      }
    }
    
  }

  // Add it all to the main window
  windowSheet = getWindowFromName("Sheet");
  if (windowSheet) {
    windowSheet->addChildWindow(windowConnection);  
  }

  // Added the main game GUI elements
  CEGUI::Window *pRoot;
  if (g_pWm->isWindowPresent(CEGUI::String("1_PlayerHealthRoot"))) {
    pRoot = g_pWm->getWindow(CEGUI::String("1_PlayerHealthRoot"));
    
    {
      windowHost = g_pWm->createWindow(CEGUI::String("GuiLook/StaticText"), CEGUI::String("Multiplayer_InGame_Latency"), CEGUI::String("666_"));
      windowHost->setText("Latency: 0 ms");
      windowHost->setProperty(CEGUI::String("UnifiedAreaRect"), CEGUI::String("{{0.5,0},{0,0},{0.6,0},{0.05,0}}"));
      pRoot->addChildWindow(windowHost);

      windowFrame = g_pWm->createWindow(CEGUI::String("GuiLook/StaticImage"), CEGUI::String("Multiplayer_InGame_Background"), CEGUI::String("666_"));
      windowFrame->setProperty(CEGUI::String("UnifiedAreaRect"), CEGUI::String("{{0.05,0},{0.55,0},{0.3,0},{0.85,0}}"));
      windowFrame->setVisible(false);
      pRoot->addChildWindow(windowFrame);

      {
        windowHost = g_pWm->createWindow(CEGUI::String("GuiLook/ItemText"), CEGUI::String("Multiplayer_InGame_ChatHistoryBkgd"), CEGUI::String("666_"));
        windowHost->setProperty(CEGUI::String("UnifiedAreaRect"), CEGUI::String("{{0.0,0},{0,0},{1,0},{0.7,0}}"));
        windowHost->setProperty(CEGUI::String("MousePassThroughEnabled"), CEGUI::String("True"));
        windowFrame->addChildWindow(windowHost);

        windowHost = static_cast<CEGUI::MultiLineEditbox*>(g_pWm->createWindow(CEGUI::String("GuiLook/MultiLineEditbox"), CEGUI::String("Multiplayer_InGame_ChatHistory"), CEGUI::String("666_")));
        windowHost->setText("");
        windowHost->setProperty(CEGUI::String("NormalTextColour"), CEGUI::String("FFFFFFFF"));
        windowHost->setProperty(CEGUI::String("UnifiedAreaRect"), CEGUI::String("{{0.0,0},{0,0},{1,0},{0.7,0}}"));
        windowFrame->addChildWindow(windowHost);

        windowHost = g_pWm->createWindow(CEGUI::String("GuiLook/ItemText"), CEGUI::String("Multiplayer_InGame_ChatEditBkgd"), CEGUI::String("666_"));
        windowHost->setProperty(CEGUI::String("UnifiedAreaRect"), CEGUI::String("{{0.0,0},{0.8,0},{1,0},{1,0}}"));
        windowHost->setProperty(CEGUI::String("MousePassThroughEnabled"), CEGUI::String("True"));
        windowFrame->addChildWindow(windowHost);

        windowHost = static_cast<CEGUI::Editbox*>(g_pWm->createWindow(CEGUI::String("GuiLook/Editbox"), CEGUI::String("Multiplayer_InGame_ChatEdit"), CEGUI::String("666_")));
        windowHost->setText("");
        windowHost->setEnabled(true);
        windowHost->setProperty(CEGUI::String("UnifiedAreaRect"), CEGUI::String("{{0.0,0},{0.8,0},{1,0},{1,0}}"));
        windowHost->subscribeEvent(CEGUI::Editbox::EventKeyDown, CEGUI::Event::Subscriber(&keyboardEventChat));
        windowFrame->addChildWindow(windowHost);
      }
    }
  }

  log("Done creating window");
}

void UserInterface::updateChatHistory(const char* message)
{
  if (g_pWm->isWindowPresent(CEGUI::String("666_Multiplayer_InGame_ChatHistory"))) {
    CEGUI::MultiLineEditbox *pChatHistory = static_cast<CEGUI::MultiLineEditbox*>(g_pWm->getWindow(CEGUI::String("666_Multiplayer_InGame_ChatHistory")));

    pChatHistory->appendText(CEGUI::String(message));
  }
}

void UserInterface::updateLatency(const double latency)
{
  if (g_pWm->isWindowPresent(CEGUI::String("666_Multiplayer_InGame_Latency"))) {
    CEGUI::Window *pLatency = g_pWm->getWindow(CEGUI::String("666_Multiplayer_InGame_Latency"));

    char buf[80];
    sprintf_s(buf, 80, "%3i ms", (int)(latency * 1000));
    pLatency->setText(CEGUI::String("Latency: ") + buf);
  }
}

void UserInterface::showChatWindow(bool visible)
{
  if (g_pWm->isWindowPresent(CEGUI::String("666_Multiplayer_InGame_Background"))) {
    CEGUI::Window *pChatWindow = g_pWm->getWindow(CEGUI::String("666_Multiplayer_InGame_Background"));

    pChatWindow->setVisible(visible);
  }
}

bool UserInterface::isChatFocused()
{
  CEGUI::Editbox* chatEdit = static_cast<CEGUI::Editbox*>(getWindowFromName("666_Multiplayer_InGame_ChatEdit"));
  if (chatEdit) {
    return chatEdit->hasInputFocus();
  }

  return false;
}


bool UserInterface::mouseEventChat(const CEGUI::EventArgs& args)
{
  //TODO: Figure out how to consume mouse events before they hit the world

  return true;
}

bool UserInterface::keyboardEventChat(const CEGUI::EventArgs& args)
{
  CEGUI::KeyEventArgs& ke = ((CEGUI::KeyEventArgs&)args);

  log("Key down: %i", ke.scancode);

  // Stop our debug commands
  BYTE tk[0x100];
  memset(tk, 0, 0x100);
  SetKeyboardState(tk);
  
  //
  if (ke.scancode == 0xD) {
    CEGUI::Editbox* chatEdit = static_cast<CEGUI::Editbox*>(getWindowFromName("666_Multiplayer_InGame_ChatEdit"));
    if (chatEdit) {
      const char *message = chatEdit->getText().c_str();
      int strLen = strlen(message) + 1;

      if (strLen < 256) {
        //sendMessage(message, strLen);
        updateChatHistory(message);
      } else {
        log("Error: String too long to send (%i)", strLen);
      }

      chatEdit->setText("");
    }
  }

  return true;
}

bool UserInterface::mouseEventMultiplayer(const CEGUI::EventArgs& args)
{
  CEGUI::Window* settings = getWindowFromName("666_Multiplayer_ConnectionInfo");
  if (settings) {
    settings->setVisible(true);
    settings->moveToFront();
  }

  return true;
}

bool UserInterface::mouseEventCancel(const CEGUI::EventArgs& args)
{
  CEGUI::Window* settings = getWindowFromName("666_Multiplayer_ConnectionInfo");
  if (settings) {
    settings->setVisible(false);
  }

  return true;
}

bool UserInterface::mouseEventConnect(const CEGUI::EventArgs& args)
{
  CEGUI::Window* settings = getWindowFromName("666_Multiplayer_ConnectionInfo");
  if (settings) {
    settings->setVisible(false);
  }

  // Save our settings
  CEGUI::Editbox* box = static_cast<CEGUI::Editbox*>(getWindowFromName("666_Multiplayer_ConnectionInfo_IP"));
  if (box) {
    FILE *f;
    fopen_s(&f, "ip.txt", "w");
    if (!f) log("failed to open ip.txt :(");
    else {
      fputs(box->getText().c_str(),f);
      fclose(f);
    }
  } else {
    log("Couldn't find IP address window to save");
  }

  //Network::JoinGame("localhost", 5445);

  return true;
}

bool UserInterface::mouseEventHost(const CEGUI::EventArgs& args)
{
  CEGUI::Window* settings = getWindowFromName("666_Multiplayer_ConnectionInfo");
  if (settings) {
    settings->setVisible(false);
  }

  //Network::HostGame(5445);
  log("UI: HostGame Complete");

  return true;
}

void UserInterface::dumpToLog(CEGUI::Window* window, int level)
{
  CEGUI::Window* win;
  char buf[80] = {0};
  for (int i = 0; i < level && i < 70; i++)
    sprintf_s(&buf[i*2], 80, "  ");

  if (level == 0) {
    win = window->getParent();
    if (win) {
      log("%sParent: %s (Type: %s) Pos: %3.1f %3.1f, Size: %3.1f %3.1f", 
      buf, win->getName().c_str(), win->getType().c_str(), 
      win->getPosition().d_x.asAbsolute(0), win->getPosition().d_y.asAbsolute(0),
      win->getSize().d_x.asAbsolute(0), win->getSize().d_y.asAbsolute(0));
    }
  }

  log("%sWindow: %s (Type: %s) Pos: %3.1f %3.1f, Size: %3.1f %3.1f", 
    buf, window->getName().c_str(), window->getType().c_str(), 
    window->getPosition().d_x.asAbsolute(0), window->getPosition().d_y.asAbsolute(0),
    window->getSize().d_x.asAbsolute(0), window->getSize().d_y.asAbsolute(0));

  for (size_t i = 0; i < window->getChildCount(); i++) {
    dumpToLog(window->getChildAtIdx(i), level+1);
  }
}

void UserInterface::dumpToFile(const char* filename)
{
  FILE* fp;
  fopen_s(&fp, filename, "w+");

  if (!fp) {
    log("Error couldn't open file: %s\n", filename);
    return;
  }

  fprintf(fp, "Window Dump:\nNOT IMPLEMENTED");

  fclose(fp);
}
