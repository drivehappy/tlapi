#include "Test.h"

CResourceManager *resManager = NULL;


void Test_CreateMonster(CMonster* retVal, CResourceManager* resourceManager, u64 guid, u32 unk0, bool unk1, bool& calloriginal)
{
  testLogger.WriteLine(Info,
    L"ResourceManager(%p)::CreateMonster( %016I64X, %i, %s ) returns Character(%p)",
    resourceManager, guid, unk0, unk1 ? L"true" : L"false", retVal);

  log(L"CreateMonster: %016I64X  %s",
    guid, retVal->characterName.c_str());

  resManager = resourceManager;
}

void Test_CreatePlayer(CPlayer* retVal, CResourceManager* resourceManager, u32 unk0, u32 unk1)
{
  testLogger.WriteLine(Info,
    L"ResourceManager(%p)::CreatePlayer( %x, %x ) returns Character(%p): %s",
    resourceManager, unk0, unk1, retVal, retVal->characterName.c_str());

  log(L"CreatePlayer: %x %x", unk0, unk1);

  resManager = resourceManager;
}

void Test_CreateCharacterByName(CCharacter* retVal, CResourceManager* resourceManager, const wchar_t* str1, const wchar_t* str2, u32 unk0, u32 unk1)
{
  testLogger.WriteLine(Info,
    L"ResourceManager(%p)::CreateCharacterByName( %s, %s, %x, %x ) returns Character(%p)",
    resourceManager, str1, str2, unk0, unk1, retVal);

  log(L"ResourceManager(%p)::CreateCharacterByName( %s, %s, %x, %x ) returns Character(%p)",
    resourceManager, str1, str2, unk0, unk1, retVal);
}

void Test_InitCharacter(CPlayer* player, CResourceManager* resourceManager, u32 unk0, u32 unk1)
{
  testLogger.WriteLine(Info,
    L"ResourceManager(%p)::InitCharacter( %i %i ) returns Character(%p)",
    resourceManager, unk0, unk1, player);

  log(L"ResourceManager(%p)::InitCharacter( %i %i ) returns Character(%p)",
    resourceManager, unk0, unk1, player);
}

void Test_CreateEquipment(CEquipment* retval, CResourceManager* resourceManager, u64 guid, u32 level, u32 unk1, u32 unk2)
{
  testLogger.WriteLine(Info,
    L"ResourceManager(%p)::Test_CreateEquipment( %016I64X, %x, %x, %x ) returns Equipment(%p)",
    resourceManager, guid, level, unk1, unk2, retval);

  log(L"CreateEquipment: %016I64X  %s  (Level = %i)",
    guid, retval->nameReal.c_str(), level);

  resManager = resourceManager;
}

void Test_CreateBaseUnit(CBaseUnit* retVal, CResourceManager* resourceManager, u64 guid, u32 unk0, u32 unk1, u32 unk2, bool& calloriginal)
{
  testLogger.WriteLine(Info,
    L"ResourceManager(%p)::CreateBaseUnit( %016I64X, %#x, %#x, %#x ) returns BaseUnit(%p)",
    resourceManager, guid, unk0, unk1, unk2, retVal);

  log(L"ResourceManager(%p)::CreateBaseUnit( %016I64X, %#x, %#x, %#x ) returns BaseUnit(%p) : %s",
    resourceManager, guid, unk0, unk1, unk2, retVal, retVal->name.c_str());
}
