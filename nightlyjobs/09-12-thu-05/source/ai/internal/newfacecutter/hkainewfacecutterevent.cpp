// File Line: 14
// RVA: 0x12FAF80
bool __fastcall hkaiNewFaceCutterUtil::eventIsValid(hkaiNewFaceCutterUtil::State *state, hkaiNewFaceCutterUtil::Event *event)
{
  hkaiNewFaceCutterUtil::Event *v2; // r8
  bool result; // al
  __int16 v4; // r9
  hkaiNewFaceCutterUtil::Segment *v5; // r10
  signed __int64 v6; // rdx

  v2 = event;
  if ( event->m_posAndType & 3 )
    return 1;
  v4 = event->m_data.m_startSegmentData.m_startingSegmentB;
  v5 = state->m_segments.m_data;
  v6 = event->m_data.m_startSegmentData.m_startingSegmentA;
  if ( v5[v6].m_generation != v2->m_data.m_intersectionData.m_lowerSegmentGeneration
    || v5[v4].m_generation != v2->m_data.m_intersectionData.m_upperSegmentGeneration )
  {
    result = 0;
  }
  else
  {
    result = v5[v6].m_nextSegment == v4;
  }
  return result;
}

