// File Line: 14
// RVA: 0x12FAF80
bool __fastcall hkaiNewFaceCutterUtil::eventIsValid(
        hkaiNewFaceCutterUtil::State *state,
        hkaiNewFaceCutterUtil::Event *event)
{
  __int16 m_startingSegmentB; // r9
  hkaiNewFaceCutterUtil::Segment *m_data; // r10
  __int64 m_startingSegmentA; // rdx

  if ( (event->m_posAndType & 3) != 0 )
    return 1;
  m_startingSegmentB = event->m_data.m_startSegmentData.m_startingSegmentB;
  m_data = state->m_segments.m_data;
  m_startingSegmentA = event->m_data.m_startSegmentData.m_startingSegmentA;
  return __PAIR32__(m_data[m_startingSegmentB].m_generation, m_data[m_startingSegmentA].m_generation) == *(_DWORD *)&event->m_data.m_intersectionData.m_lowerSegmentGeneration
      && m_data[m_startingSegmentA].m_nextSegment == (unsigned __int16)m_startingSegmentB;
}

