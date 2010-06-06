#pragma once

// Size?: 24h
struct CQuadtree : CRunicCore
{
  float positions[8];   // 0,1,   53, 11, 111, -41, -10, -16   (missing dec #s)

  PVOID pCQuadtreeNode; // ptr to CQuadtreeNode
};
