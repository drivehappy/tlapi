#include "TestUserInterface.h"

using namespace TLAPI;

//
bool mouseEventOk(const CEGUI::EventArgs& args)
{
  CEGUI::Window* settings = UserInterface::getWindowFromName("1000_TestSuite_MainBackground");
  if (settings) {
    settings->setVisible(false);
    settings->moveToBack();
  }

  return true;
}

// Sets up the initial TestSuite screen
void Create_MainButton()
{
  const CEGUI::String stringOk("Ok");
  const CEGUI::String stringTitle("TestSuite");
  const CEGUI::String stringDesc("The TLAPI TestSuite has been successfully loaded.\
    The purpose of the TestSuite is to test for functionality needed for (at this point), Multiplayer.\
    You will find an ingame menu option for running the available tests.\
    This suite of tests does _not_ contain any network functionality and is simply provided to test the \"hard\" stuff\
    to get the underlying code for Multiplayer working.");

  CEGUI::WindowManager* wm = UserInterface::getManager();

  // Create the default window
  CEGUI::Window *windowTestSuite, *windowSheet, *windowFrame, *windowText, *windowButton;
  windowTestSuite = wm->createWindow(CEGUI::String("DefaultWindow"), CEGUI::String("TestSuite_Main"), CEGUI::String("1000_"));
  windowTestSuite->setProperty(CEGUI::String("UnifiedMaxSize"), CEGUI::String("{{1,0},{1,0}}"));
  windowTestSuite->setProperty(CEGUI::String("UnifiedAreaRect"), CEGUI::String("{{0,0},{0,0},{1,0},{1,0}}"));
  windowTestSuite->setVisible(true);

  {
    // Create the Background
    windowFrame = wm->createWindow(CEGUI::String("GuiLook/StaticImage"), CEGUI::String("TestSuite_MainBackground"), CEGUI::String("1000_"));
    windowFrame->setProperty(CEGUI::String("Image"), CEGUI::String("set:GuiLook image:GrayLine"));
    windowFrame->setProperty(CEGUI::String("UnifiedMaxSize"), CEGUI::String("{{1,0},{1,0}}"));
    windowFrame->setProperty(CEGUI::String("UnifiedAreaRect"), CEGUI::String("{{0,0},{0,0},{1,0},{1,0}}"));
    windowFrame->setMousePassThroughEnabled(false);
    windowTestSuite->addChildWindow(windowFrame);

    {
      // Create the title text
      windowText = wm->createWindow(CEGUI::String("GuiLook/StaticText"), CEGUI::String("TestSuite_TextTitle"), CEGUI::String("1000_"));
      windowText->setText(stringTitle);
      windowText->setProperty(CEGUI::String("TextColour"), CEGUI::String("FFFFFF00"));
      windowText->setProperty(CEGUI::String("UnifiedPosition"), CEGUI::String("{{.5,-100},{.5,-250}}"));
      windowText->setProperty(CEGUI::String("UnifiedSize"), CEGUI::String("{{0,300},{0,28}}"));
      windowText->setProperty(CEGUI::String("Font"), CEGUI::String("SerifHuge"));
      windowFrame->addChildWindow(windowText);

      // Create the description text
      windowText = wm->createWindow(CEGUI::String("GuiLook/StaticText"), CEGUI::String("TestSuite_TextDescription"), CEGUI::String("1000_"));
      windowText->setText(stringDesc);
      windowText->setProperty(CEGUI::String("HorzTextFormatting"), CEGUI::String("WordWrapCentreAligned"));
      windowText->setProperty(CEGUI::String("UnifiedPosition"), CEGUI::String("{{.5,-500},{.5,-200}}"));
      windowText->setProperty(CEGUI::String("UnifiedSize"), CEGUI::String("{{0,1000},{0,250}}"));
      windowText->setProperty(CEGUI::String("Font"), CEGUI::String("SerifBig"));
      windowFrame->addChildWindow(windowText);

      // Create the Ok button
      windowButton = wm->createWindow(CEGUI::String("GuiLook/StandardButton"), CEGUI::String("TestSuite_ButtonOk"), CEGUI::String("1000_"));
      windowButton->setText(stringOk);
      windowButton->setProperty(CEGUI::String("UnifiedPosition"), CEGUI::String("{{.5,-70},{.70,0}}"));
      windowButton->setProperty(CEGUI::String("UnifiedSize"), CEGUI::String("{{0,152},{0,28}}"));
      windowButton->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&mouseEventOk));
      windowFrame->addChildWindow(windowButton);
    }
  }

  // Add it all to the main window
  windowSheet = UserInterface::getWindowFromName("Sheet");
  if (windowSheet) {
    windowSheet->addChildWindow(windowTestSuite);  
    windowTestSuite->moveToFront();
    windowTestSuite->setEnabled(true);
  }
}

// 
void Test_MainWindow()
{
  log("Test_MainWindow() Creating...");

  UserInterface UI;

  UI.init();

  Create_MainButton();

  //UI.createWindow();
}
