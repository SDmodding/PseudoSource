// File Line: 14
// RVA: 0xCF38B0
void __fastcall hkpSimpleClosestContactCollector::addCdPoint(hkpSimpleClosestContactCollector *this, hkpCdPoint *event)
{
  float v2; // xmm2_4

  LODWORD(v2) = _mm_shuffle_ps(
                  event->m_contact.m_separatingNormal.m_quad,
                  event->m_contact.m_separatingNormal.m_quad,
                  255).m128_u32[0];
  if ( !this->m_hasHit.m_bool
    || v2 < _mm_shuffle_ps(this->m_hitPoint.m_separatingNormal.m_quad, this->m_hitPoint.m_separatingNormal.m_quad, 255).m128_f32[0] )
  {
    this->m_hasHit.m_bool = 1;
    this->m_hitPoint = event->m_contact;
    this->m_earlyOutDistance = v2;
  }
}

