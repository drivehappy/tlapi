#include "Test.h"

void Test_CreateCharacter(CCharacter* retVal, CResourceManager* resourceManager, u64 guid, u32 unk0, bool unk1)
{
  testLogger.WriteLine(Info,
    L"ResourceManager(%p)::CreateCharacter( %I016X64, %i, %s ) returns Character(%p)",
    resourceManager, guid, unk0, unk1 ? L"true" : L"false", retVal);
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
