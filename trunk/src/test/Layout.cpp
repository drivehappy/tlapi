#include "Test.h"

void Test_LayoutSetPosition(CLayout* layout, const Vector3 position)
{
  testLogger.WriteLine(Verbose,
    L"Layout(%p)::SetPosition( %f, %f, %f ) returns void",
    layout, position.x, position.y, position.z);
}
