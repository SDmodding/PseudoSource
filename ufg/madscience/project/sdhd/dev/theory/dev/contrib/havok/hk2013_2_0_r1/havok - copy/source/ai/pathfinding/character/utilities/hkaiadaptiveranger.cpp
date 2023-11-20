// File Line: 22
// RVA: 0xC10B80
void __fastcall hkaiAdaptiveRanger::updateRange(hkaiAdaptiveRanger *this, unsigned int idealTargetCount, unsigned int actualTargetCount)
{
  signed int v3; // er8
  signed int v4; // edx
  float v5; // xmm0_4

  v3 = actualTargetCount - idealTargetCount;
  v4 = idealTargetCount >> 2;
  if ( -v3 <= v4 )
  {
    if ( v3 > v4 )
      this->m_curRange = this->m_curRange * 0.95238101;
  }
  else
  {
    v5 = this->m_curRange * 1.05;
    this->m_curRange = v5;
    if ( v5 > 1.0 )
      this->m_curRange = 1.0;
  }
}

