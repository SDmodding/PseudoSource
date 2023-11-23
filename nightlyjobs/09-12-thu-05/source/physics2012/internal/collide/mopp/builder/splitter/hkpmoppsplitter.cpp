// File Line: 18
// RVA: 0xDB6C20
void __fastcall hkpMoppSplitter::hkpMoppSplitParams::hkpMoppSplitParams(
        hkpMoppSplitter::hkpMoppSplitParams *this,
        hkpMoppMeshType meshType)
{
  this->m_checkAllEveryN = 5;
  this->m_minRangeMaxListCheck = 5;
  this->m_tolerance = 0.1;
  this->m_maxPrimitiveSplits = 1000;
  this->m_maxPrimitiveSplitsPerNode = 10;
  this->m_interleavedBuildingEnabled.m_bool = 1;
  if ( meshType )
  {
    if ( meshType == HK_MOPP_MT_INDOOR )
    {
      this->m_tolerance = 0.050000001;
      this->m_maxPrimitiveSplitsPerNode = 30;
    }
  }
  else
  {
    this->m_tolerance = 0.2;
  }
}

