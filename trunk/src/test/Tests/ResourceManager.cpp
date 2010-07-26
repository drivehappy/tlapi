#include "Test.h"

CResourceManager *resManager = NULL;


void Test_CreateCharacter(CCharacter* retVal, CResourceManager* resourceManager, u64 guid, u32 unk0, bool unk1)
{
  testLogger.WriteLine(Info,
    L"ResourceManager(%p)::CreateCharacter( %016I64X, %i, %s ) returns Character(%p)",
    resourceManager, guid, unk0, unk1 ? L"true" : L"false", retVal);

  resManager = resourceManager;
}

void Test_CreateCharacterByName(CCharacter* retVal, CResourceManager* resourceManager, const wchar_t* str1, const wchar_t* str2, u32 unk0, u32 unk1)
{
  testLogger.WriteLine(Info,
    L"ResourceManager(%p)::CreateCharacterByName( %s, %s, %x, %x ) returns Character(%p)",
    resourceManager, str1, str2, unk0, unk1, retVal);
}

void Test_InitCharacter(CResourceManager* resourceManager, u32 unk0, u32 unk1)
{
  testLogger.WriteLine(Info,
    L"ResourceManager(%p)::InitCharacter( %i %i ) returns Character(%p)",
    resourceManager, unk0, unk1, NULL);
}

void Test_CreateEquipment(CEquipment* retval, CResourceManager* resourceManager, u64 guid, u32 level, u32 unk1, u32 unk2)
{
  testLogger.WriteLine(Info,
    L"ResourceManager(%p)::Test_CreateEquipment( %016I64X, %x, %x, %x ) returns Equipment(%p)",
    resourceManager, guid, level, unk1, unk2, retval);

  log(L"CreateEquipment: %016I64X  %s  (Level = %i)", guid, retval->nameReal, level);
  resManager = resourceManager;
}

void Test_CreateSomething(PVOID retVal, CResourceManager* resourceManager, u64 guid, u32 unk0, u32 unk1, u32 unk2)
{
  testLogger.WriteLine(Info,
    L"ResourceManager(%p)::CreateSomething( %016I64X, %#x, %#x, %#x ) returns Unk(%p)",
    resourceManager, guid, unk0, unk1, unk2, retVal);
}
