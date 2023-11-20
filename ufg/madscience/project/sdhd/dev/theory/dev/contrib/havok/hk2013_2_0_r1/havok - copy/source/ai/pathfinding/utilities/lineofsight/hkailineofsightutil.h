// File Line: 215
// RVA: 0xBDCE30
bool __fastcall hkaiLineOfSightUtil::LineOfSightOutput::canAddEdge(hkaiLineOfSightUtil::LineOfSightOutput *this)
{
  return !this->m_doNotExceedArrayCapacity.m_bool
      || this->m_visitedEdgesOut.m_size < (this->m_visitedEdgesOut.m_capacityAndFlags & 0x3FFFFFFF);
}

// File Line: 220
// RVA: 0xBDCE10
bool __fastcall hkaiLineOfSightUtil::LineOfSightOutput::canAddDistance(hkaiLineOfSightUtil::LineOfSightOutput *this)
{
  return !this->m_doNotExceedArrayCapacity.m_bool
      || this->m_distancesOut.m_size < (this->m_distancesOut.m_capacityAndFlags & 0x3FFFFFFF);
}

// File Line: 225
// RVA: 0xBDCE50
bool __fastcall hkaiLineOfSightUtil::LineOfSightOutput::canAddPoint(hkaiLineOfSightUtil::LineOfSightOutput *this)
{
  return !this->m_doNotExceedArrayCapacity.m_bool
      || this->m_pointsOut.m_size < (this->m_pointsOut.m_capacityAndFlags & 0x3FFFFFFF);
}

