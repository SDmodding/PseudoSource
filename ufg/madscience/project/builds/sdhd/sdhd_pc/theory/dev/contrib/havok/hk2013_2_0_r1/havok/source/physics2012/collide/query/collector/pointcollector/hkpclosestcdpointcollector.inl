// File Line: 10
// RVA: 0xB8C80
void __fastcall hkpClosestCdPointCollector::reset(hkpClosestCdPointCollector *this)
{
  this->m_hitPoint.m_rootCollidableA = 0i64;
  this->m_hitPoint.m_contact.m_separatingNormal.m_quad = _mm_shuffle_ps(
                                                           this->m_hitPoint.m_contact.m_separatingNormal.m_quad,
                                                           _mm_unpackhi_ps(
                                                             this->m_hitPoint.m_contact.m_separatingNormal.m_quad,
                                                             (__m128)xmmword_141A712A0),
                                                           196);
  this->m_earlyOutDistance = 3.40282e38;
}

// File Line: 22
// RVA: 0x9DC60
void __fastcall hkpClosestCdPointCollector::~hkpClosestCdPointCollector(hkpClosestCdPointCollector *this)
{
  this->vfptr = (hkpCdPointCollectorVtbl *)&hkpClosestCdPointCollector::`vftable;
  this->vfptr = (hkpCdPointCollectorVtbl *)&hkpCdPointCollector::`vftable;
}

