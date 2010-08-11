#include "TestUserInterface.h"
#include <typeinfo>

using namespace TLAPI;

//
bool mouseEventOk(const CEGUI::EventArgs& args)
{
  CEGUI::Window* mainWindow = UserInterface::getWindowFromName("1000_TestSuite_Main");
  if (mainWindow) {
    mainWindow->setVisible(false);
    mainWindow->setEnabled(false);
    mainWindow->moveToBack();
  }

  return true;
}

//
bool mouseEventInGameOk(const CEGUI::EventArgs& args)
{
  CEGUI::Window* settings = UserInterface::getWindowFromName("1002_Frame");
  if (settings) {
    settings->setVisible(true);
    settings->moveToFront();

    suppressInGameMouse = true;
  }

  return true;
}

bool mouseEventInGameClose(const CEGUI::EventArgs& args)
{
  CEGUI::Window* settings = UserInterface::getWindowFromName("1002_Frame");
  if (settings) {
    settings->setVisible(false);
    settings->moveToBack();

    suppressInGameMouse = false;
  }

  return true;
}

// Test 1 - Create a deterministic socketed 
// and enchanted item with a gem placed inside.  
bool mouseEventTest1(const CEGUI::EventArgs& args)
{
  log("Creating Chaos Gem...");
  u64 chaosGem = 0xEF8CFF367B0711DE;
  Vector3 position = gameClient->pCPlayer->position;
  CEquipment *equipmentGem0 = resManager->CreateEquipment(chaosGem, 1, 0, 0);
  CEquipment *equipmentGem1 = resManager->CreateEquipment(chaosGem, 1, 0, 0);
  equipmentGem0->AddEnchant(FASTER_ATTACK, NONE, 1000);
  equipmentGem1->AddEnchant(REGULAR, PHYSICAL, 1337);

  log("Creating Bishop Axe...");
  u64 bishopAxe = 0x764ECFC83F3D11De;
  CEquipment *equipmentBishopAxe = resManager->CreateEquipment(bishopAxe, 1, 0, 0);
  equipmentBishopAxe->socketCount = 2;
  equipmentBishopAxe->gemList.push(equipmentGem0);
  equipmentBishopAxe->gemList.push(equipmentGem1);

  equipmentBishopAxe->pCAttackDescriptor0->damageMaximumPhysical0 = 300;
  equipmentBishopAxe->pCAttackDescriptor0->damageMaximumPhysical1 = 300;
  equipmentBishopAxe->pCAttackDescriptor1->damageMaximumPhysical0 = 600;
  equipmentBishopAxe->pCAttackDescriptor1->damageMaximumPhysical1 = 600;

  equipmentBishopAxe->pCAttackDescriptor0->attackSpeed = 1.2f;
  equipmentBishopAxe->pCAttackDescriptor1->attackSpeed = 1.2f;
  
  resManager->pCLevel->EquipmentDrop(equipmentBishopAxe, position, 0);
  log("Done: %p (Gems = %i)", equipmentBishopAxe, equipmentBishopAxe->gemList.size);

  return true;
}

// Test 2 - Creates characters
bool mouseEventTest2(const CEGUI::EventArgs& args)
{
  wchar_t* names[] = {
    L"Badguy Destroyer",
    L"Goodguy Destroyer",
    L"Badguy Vanquisher",
    L"Goodguy Vanquisher",
    L"Badguy Alchemist",
    L"Goodguy Alchemist",
  };

  CCharacter* characters[6];

  u64 guids[] = {
    0xD3A8F9982FA111DE,
    0xD3A8F9982FA111DE,
    0xAA472CC2629611DE,
    0xAA472CC2629611DE,
    0x8D3EE5363F7611DE,
    0x8D3EE5363F7611DE,
  };

  Vector3* position = &gameClient->pCPlayer->position;

  // Create Destroyer
  log("Creating Characters level 1 @(%f, %f, %f)",
    position->x, position->y, position->z);

  log("  resManager = %p", resManager);
  log("  level = %p", gameClient->pCLevel);

  for (int i = 0; i < 6; i++) {
    log(" Attempting to create character %016I64X", guids[i]);
    characters[i] = resManager->CreateMonster(guids[i], 1, false);
    log(" Attempting to assign character name...");
    characters[i]->characterName.assign(names[i]);
    characters[i]->SetAlignment(i % 2 ? 0 : 2);
    gameClient->pCLevel->CharacterInitialize(characters[i], position, 0);
  }

  log("Completed.");

  return true;
}

// Test3 - Drop all player equipment to the ground
bool mouseEventTest3(const CEGUI::EventArgs& args)
{
  // Test 3
  CInventory *playerInventory = gameClient->pCPlayer->pCInventory;
  CEquipment *equipment;
  Vector3* position = &gameClient->pCPlayer->position;

  log("Dropping all player equipment... size: %i", playerInventory->equipmentList.size);
  u32 index = 0;
  while (playerInventory->equipmentList.size > 0) {
    equipment = playerInventory->equipmentList[index]->pCEquipment;
    
    log(L"  Dropping equipment: %s", equipment->nameReal.c_str());
    playerInventory->RemoveEquipment(equipment);
    gameClient->pCLevel->EquipmentDrop(equipment, *position, false);

    index++;
  }

  return true;
}

// Test 4 - Force player load into town.
bool mouseEventTest4(const CEGUI::EventArgs& args)
{
  log("Forcing player load into town...");
  log("  gameClient = %p", gameClient);
  log("  dungeon = %p", gameClient->pCDungeon);

  wstring Town(L"TOWN");
  if (gameClient->pCDungeon->name0 == Town) {
    log(" Already in Town!");
  } else {
    gameClient->ChangeLevel(-99);
  }

  return true;
}

// Test 5 - Dump vendor inventories
bool mouseEventTest5(const CEGUI::EventArgs& args)
{
  log("Searching for Vendors...");

  CLevel* level = gameClient->pCLevel;

  log("Level Layouts: %i", level->CLayoutsList.size);
  
  // Iterate through the layouts in our level
  for (u32 i = 0; i < level->CLayoutsList.size; i++) {
    CDescriptorManager *descMgr = level->CLayoutsList[i]->pCDescriptorManager;
    CBaseObjectDescriptor** itr = (CBaseObjectDescriptor**)descMgr->pCDescriptorStart;
    CBaseObjectDescriptor** itrEnd = (CBaseObjectDescriptor**)descMgr->pCDescriptorMid;

    log(" DecriptorManager: %p", descMgr);
    log("  Start CBaseObjectDescriptor: %p", descMgr->pCDescriptorStart);
    log("  End CBaseObjectDescriptor: %p", descMgr->pCDescriptorMid);
    log("  Start CDescriptorProp: %p", descMgr->pCDescriptorMid);
    log("  Emd CDescriptorProp: %p", descMgr->pCDescriptorEnd);

    // Iterate through the descriptors in our descriptorManager
    while (itr != itrEnd) {
      log("   itr = %p", itr);
      log(L"     CBaseObjectDescriptor type: %s", (*itr)->stringType.c_str());
      log(L"     CBaseObjectDescriptor description: %s", (*itr)->stringDescription.c_str());
      log(L"     CBaseObjectDescriptor type2: %s", (*itr)->stringType2.c_str());
      log(L"     CBaseObjectDescriptor type3: %s", (*itr)->stringType3.c_str());

      if ((*itr)->stringType == wstring(L"Monster")) {
        CMonsterDescriptor *monsterDesc = (CMonsterDescriptor*)(*itr);
        log(L"       MonsterDescriptor:");
        log(L"         Monsters size: %i", monsterDesc->CMonsterList.size);
        
        for (u32 j = 0; j < monsterDesc->CMonsterList.size; j++) {
          CMonster *monster = monsterDesc->CMonsterList[j];
          CInventory *inventory = monster->pCInventory;
          log(L"           Monster: %s", monster->characterName.c_str());
          log(L"             Inventory: %i", inventory->equipmentList.size);

          for (u32 k = 0; k < inventory->equipmentList.size; k++) {
            CEquipmentRef *equipment = inventory->equipmentList[k];
            log(L"               Equipment: %s", equipment->pCEquipment->nameReal.c_str());
          }
        }
      }

      itr++;
    }
  }

  return true;
}

// Test 6 - Create item on ground and have (Tarn the Merchant) place it into inventory
bool mouseEventTest6(const CEGUI::EventArgs& args)
{
  log("Creating Chaos Gem...");
  u64 chaosGem = 0xEF8CFF367B0711DE;
  Vector3 position = gameClient->pCPlayer->position;
  CEquipment *equipmentGem0 = resManager->CreateEquipment(chaosGem, 1, 0, 0);
  CEquipment *equipmentGem1 = resManager->CreateEquipment(chaosGem, 1, 0, 0);
  equipmentGem0->AddEnchant(FASTER_ATTACK, NONE, 1000);
  equipmentGem1->AddEnchant(REGULAR, PHYSICAL, 1337);

  log("Creating Bishop Axe...");
  u64 bishopAxe = 0x764ECFC83F3D11De;
  CEquipment *equipmentBishopAxe = resManager->CreateEquipment(bishopAxe, 1, 0, 0);
  equipmentBishopAxe->socketCount = 2;
  equipmentBishopAxe->gemList.push(equipmentGem0);
  equipmentBishopAxe->gemList.push(equipmentGem1);

  equipmentBishopAxe->pCAttackDescriptor0->damageMaximumPhysical0 = 300;
  equipmentBishopAxe->pCAttackDescriptor0->damageMaximumPhysical1 = 300;
  equipmentBishopAxe->pCAttackDescriptor1->damageMaximumPhysical0 = 600;
  equipmentBishopAxe->pCAttackDescriptor1->damageMaximumPhysical1 = 600;

  equipmentBishopAxe->pCAttackDescriptor0->attackSpeed = 1.2f;
  equipmentBishopAxe->pCAttackDescriptor1->attackSpeed = 1.2f;
  
  resManager->pCLevel->EquipmentDrop(equipmentBishopAxe, position, 0);
  log("Done: %p (Gems = %i)", equipmentBishopAxe, equipmentBishopAxe->gemList.size);


  // --
  log("Having NPC Tarn place axe into inventory...");
  CLevel* level = gameClient->pCLevel;

  // Iterate through the layouts in our level
  for (u32 i = 0; i < level->CLayoutsList.size; i++) {
    CDescriptorManager *descMgr = level->CLayoutsList[i]->pCDescriptorManager;
    CBaseObjectDescriptor** itr = (CBaseObjectDescriptor**)descMgr->pCDescriptorStart;
    CBaseObjectDescriptor** itrEnd = (CBaseObjectDescriptor**)descMgr->pCDescriptorMid;

    // Iterate through the descriptors in our descriptorManager
    while (itr != itrEnd) {
      if ((*itr)->stringType == wstring(L"Monster")) {
        CMonsterDescriptor *monsterDesc = (CMonsterDescriptor*)(*itr);

        for (u32 j = 0; j < monsterDesc->CMonsterList.size; j++) {
          CMonster *monster = monsterDesc->CMonsterList[j];
          CInventory *inventory = monster->pCInventory;

          if (monster->characterName == wstring(L"Tarn the Merchant")) {
            monster->PickupEquipment(equipmentBishopAxe, level);
          }
        }
      }

      itr++;
    }
  }

  return true;
}

//
void Create_InGameMenu()
{
  const CEGUI::String stringOk("Open Tests");
  const CEGUI::String stringTitle("TLAPI TestSuite");

  // Added the main game GUI elements
  CEGUI::WindowManager* wm = UserInterface::getManager();
  CEGUI::Window *pRoot;
  CEGUI::Window *windowTestSuite, *windowButton;

  if (wm->isWindowPresent(CEGUI::String("1_PlayerHealthRoot"))) {
    pRoot = wm->getWindow(CEGUI::String("1_PlayerHealthRoot"));
  } else {
    return;
  }

  try {
    windowButton = wm->loadWindowLayout(CEGUI::String("IngameTest0.layout"), CEGUI::String("1001_"));
    windowTestSuite = wm->loadWindowLayout(CEGUI::String("IngameTest.layout"), CEGUI::String("1002_"));
  } catch (CEGUI::FileIOException e) {
    log("Error loading file (FileIOException)");
  } catch (CEGUI::InvalidRequestException e) {
    log("Error loading file (InvalidRequestException)");
  } catch (std::exception e) {
    log("Error loading file (%s)", e.what());
  }

  
  if (windowTestSuite) {
    windowTestSuite->setVisible(false);
    pRoot->addChildWindow(windowTestSuite);

    // Setup the button events
    windowButton = windowButton->recursiveChildSearch("OpenTests");
    windowButton->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&mouseEventInGameOk));
    windowButton->setVisible(true);
    pRoot->addChildWindow(windowButton);

    // Setup the button test events
    /// Close
    windowButton = windowTestSuite->recursiveChildSearch("CloseTests");
    windowButton->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&mouseEventInGameClose));

    windowButton = windowTestSuite->recursiveChildSearch("Test1");
    windowButton->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&mouseEventTest1));
    windowButton = windowTestSuite->recursiveChildSearch("Test2");
    windowButton->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&mouseEventTest2));
    windowButton = windowTestSuite->recursiveChildSearch("Test3");
    windowButton->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&mouseEventTest3));
    windowButton = windowTestSuite->recursiveChildSearch("Test4");
    windowButton->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&mouseEventTest4));
    windowButton = windowTestSuite->recursiveChildSearch("Test5");
    windowButton->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&mouseEventTest5));
    windowButton = windowTestSuite->recursiveChildSearch("Test6");
    windowButton->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&mouseEventTest6));
  }
}

// Sets up the initial TestSuite screen
void Create_MainMain()
{
  const CEGUI::String stringOk("Ok");
  const CEGUI::String stringTitle("TestSuite");
  const CEGUI::String stringDesc("The TLAPI TestSuite has been successfully loaded. \
The purpose of the TestSuite is to regression test for bugs within the underlying functionality needed for Multiplayer. \
You will find an ingame menu option for running the available tests after you load your character. \
This suite of tests does not contain any network functionality yet. \
\
Game saves with this test have been suppressed (nothing should be saved). However, there is a chance that your character or other entities in your saved game may be altered or destroyed, PLEASE BACKUP YOUR SAVED GAMES BEFORE CONTINUING.");

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
      windowText->setProperty(CEGUI::String("HorzTextFormatting"), CEGUI::String("WordWrapLeftAligned"));
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
  /*
  // Problem: Ogre::Root contains this, but also ResouceGroupManager, and it does initialize afterwards,
  // is this best left in the resource.cfg file?
  //
  // Add the TLAPI folder to the Ogre resource location
  // 
  testLogger.WriteLine(Info, L"Adding TLAPI Resource Location...");

  typedef PVOID(* OgreRootGetSingleton)(void);
  typedef PVOID(* OgreAddResourceLocation)(PVOID _this, string name, string type, string groupName, bool recursive);

  OgreRootGetSingleton ogreRootFunc = (OgreRootGetSingleton)GetProcAddress(GetModuleHandle("OgreMain.dll"), "?getSingleton@Root@Ogre@@SAAAV12@XZ");
  OgreAddResourceLocation addResourceLocation = (OgreAddResourceLocation)GetProcAddress(GetModuleHandle("OgreMain.dll"), "?addResourceLocation@ResourceGroupManager@Ogre@@QAEXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@00_N@Z");

  log("RootFunc = %p", ogreRootFunc);
  log("ResourceFunc = %p", addResourceLocation);

  PVOID ogreRoot = ogreRootFunc();
  log("ogreRoot = %p", ogreRoot);

  addResourceLocation(ogreRoot, string("TLAPI"), string("FILESYSTEM"), string(""), false);
  */

  // Add the Interface elements
  log("Test_MainWindow() Creating...");

  UserInterface UI;

  UI.init();

  Create_MainMain();
  Create_InGameMenu();

  //UI.createWindow();
}
