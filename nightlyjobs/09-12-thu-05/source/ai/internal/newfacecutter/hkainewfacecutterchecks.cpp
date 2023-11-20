// File Line: 20
// RVA: 0x12F71D0
void __fastcall hkaiNewFaceCutterUtil::checkStateLinks(hkaiNewFaceCutterUtil::State *state)
{
  ;
}

// File Line: 55
// RVA: 0x12F71E0
void __fastcall hkaiNewFaceCutterUtil::checkStateMembership(hkaiNewFaceCutterUtil::State *state)
{
  ;
}

// File Line: 74
// RVA: 0x12F71F0
void __fastcall hkaiNewFaceCutterUtil::checkStateIntersection(hkaiNewFaceCutterUtil::State *state, hkaiNewFaceCutterUtil::Vec2 sweepLine)
{
  ;
}

// File Line: 91
// RVA: 0x12F7200
void __fastcall hkaiNewFaceCutterUtil::checkStateOrdering(hkaiNewFaceCutterUtil::State *state, hkaiNewFaceCutterUtil::Vec2 sweepLine)
{
  ;
}

// File Line: 123
// RVA: 0x12F7210
void __fastcall hkaiNewFaceCutterUtil::checkRegionEdgeConnectity(hkaiNewFaceCutterUtil::State *state)
{
  ;
}

// File Line: 152
// RVA: 0x12F7220
void __fastcall hkaiNewFaceCutterUtil::checkRegionEdgesNotDegenerate(hkaiNewFaceCutterUtil::State *state)
{
  ;
}

// File Line: 176
// RVA: 0x12F7230
void __fastcall hkaiNewFaceCutterUtil::checkRegionPointsUnique(hkaiNewFaceCutterUtil::State *state)
{
  ;
}

// File Line: 205
// RVA: 0x12F7160
void __fastcall hkaiNewFaceCutterUtil::checkState(hkaiNewFaceCutterUtil::State *state, hkaiNewFaceCutterUtil::Vec2 sweepLine)
{
  ;
}

// File Line: 217
// RVA: 0x12F7240
void __fastcall hkaiNewFaceCutterUtil::checkRegionClosure(hkaiNewFaceCutterUtil::State *state)
{
  ;
}

// File Line: 229
// RVA: 0x12F7250
void __fastcall hkaiNewFaceCutterUtil::checkRegionNearlyConvex(hkaiNewFaceCutterUtil::State *state, hkaiNewFaceCutterUtil::Region *region)
{
  ;
}

// File Line: 275
// RVA: 0x12F7260
void __fastcall hkaiNewFaceCutterUtil::checkRegionsNearlyConvex(hkaiNewFaceCutterUtil::State *state)
{
  ;
}

// File Line: 287
// RVA: 0x12F7170
void __fastcall hkaiNewFaceCutterUtil::checkRegions(hkaiNewFaceCutterUtil::State *state)
{
  ;
}

// File Line: 298
// RVA: 0x12F7180
char __fastcall hkaiNewFaceCutterUtil::isSegmentInState(hkaiNewFaceCutterUtil::State *state, __int16 segmentIndex)
{
  __int16 v2; // ax

  v2 = state->m_sweepState.m_firstSegment;
  if ( v2 == -1 )
    return 0;
  while ( v2 != segmentIndex )
  {
    v2 = state->m_segments.m_data[v2].m_nextSegment;
    if ( v2 == -1 )
      return 0;
  }
  return 1;
}

// File Line: 310
// RVA: 0x12F71C0
void __fastcall hkaiNewFaceCutterUtil::checkOutputVertices(hkaiNewFaceCutterUtil::State *state)
{
  ;
}

