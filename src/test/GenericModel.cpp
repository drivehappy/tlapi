#include "Test.h"

void Test_GenericModelGetPosition(CGenericModel* genericModel, Vector3 position, u32 unk)
{
  testLogger.WriteLine(Info,
    L"GenericModel(%p)::GetPosition( %f, %f, %f, unk(%x) ) returns PVOID(%p)",
    genericModel, position.x, position.y, position.z, unk);

  // Dump the GUID for more information
  testLogger.WriteLine(Verbose,
    L"  Mesh Location: %s",
    genericModel->meshLocation.getString());
}
