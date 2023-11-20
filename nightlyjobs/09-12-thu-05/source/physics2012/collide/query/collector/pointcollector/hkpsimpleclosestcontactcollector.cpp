// File Line: 14
// RVA: 0xCF38B0
void __fastcall hkpSimpleClosestContactCollector::addCdPoint(hkpSimpleClosestContactCollector *this, hkpCdPoint *event)
{
  float v2; // xmm2_4

  LODWORD(v2) = (unsigned __int128)_mm_shuffle_ps(
                                     event->m_contact.m_separatingNormal.m_quad,
                                     event->m_contact.m_separatingNormal.m_quad,
                                     255);
  if ( !this->m_hasHit.m_bool
    || v2 < COERCE_FLOAT(
              _mm_shuffle_ps(
                this->m_hitPoint.m_separatingNormal.m_quad,
                this->m_hitPoint.m_separatingNormal.m_quad,
                255)) )
  {
    this->m_hasHit.m_bool = 1;
    this->m_hitPoint.m_position = event->m_contact.m_position;
    this->m_hitPoint.m_separatingNormal = event->m_contact.m_separatingNormal;
    this->m_earlyOutDistance = v2;
  }
}

