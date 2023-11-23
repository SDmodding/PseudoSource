// File Line: 11
// RVA: 0xB8CB0
void __fastcall hkpSimpleClosestContactCollector::reset(hkpSimpleClosestContactCollector *this)
{
  this->m_hasHit.m_bool = 0;
  this->m_hitPoint.m_separatingNormal.m_quad = _mm_shuffle_ps(
                                                 this->m_hitPoint.m_separatingNormal.m_quad,
                                                 _mm_unpackhi_ps(
                                                   this->m_hitPoint.m_separatingNormal.m_quad,
                                                   (__m128)xmmword_141A712A0),
                                                 196);
  this->m_earlyOutDistance = 3.40282e38;
}

// File Line: 23
// RVA: 0x9DD80
void __fastcall hkpSimpleClosestContactCollector::~hkpSimpleClosestContactCollector(
        hkpSimpleClosestContactCollector *this)
{
  this->vfptr = (hkpCdPointCollectorVtbl *)&hkpSimpleClosestContactCollector::`vftable;
  this->vfptr = (hkpCdPointCollectorVtbl *)&hkpCdPointCollector::`vftable;
}

