// File Line: 20
// RVA: 0xCED460
void __fastcall hkpClosestCdPointCollector::addCdPoint(hkpClosestCdPointCollector *this, hkpCdPoint *event)
{
  float v3; // xmm2_4
  hkpCollidable *m_cdBodyA; // rcx
  hkpCollidable *i; // rax
  hkpCollidable *m_cdBodyB; // rcx
  hkpCollidable *j; // rax

  LODWORD(v3) = _mm_shuffle_ps(
                  event->m_contact.m_separatingNormal.m_quad,
                  event->m_contact.m_separatingNormal.m_quad,
                  255).m128_u32[0];
  if ( !this->m_hitPoint.m_rootCollidableA
    || v3 < _mm_shuffle_ps(
              this->m_hitPoint.m_contact.m_separatingNormal.m_quad,
              this->m_hitPoint.m_contact.m_separatingNormal.m_quad,
              255).m128_f32[0] )
  {
    this->m_hitPoint.m_contact.m_position = event->m_contact.m_position;
    this->m_hitPoint.m_contact.m_separatingNormal = event->m_contact.m_separatingNormal;
    m_cdBodyA = (hkpCollidable *)event->m_cdBodyA;
    for ( i = (hkpCollidable *)m_cdBodyA->m_parent; i; i = (hkpCollidable *)i->m_parent )
      m_cdBodyA = i;
    this->m_hitPoint.m_rootCollidableA = m_cdBodyA;
    this->m_hitPoint.m_shapeKeyA = event->m_cdBodyA->m_shapeKey;
    m_cdBodyB = (hkpCollidable *)event->m_cdBodyB;
    for ( j = (hkpCollidable *)m_cdBodyB->m_parent; j; j = (hkpCollidable *)j->m_parent )
      m_cdBodyB = j;
    this->m_hitPoint.m_rootCollidableB = m_cdBodyB;
    this->m_hitPoint.m_shapeKeyB = event->m_cdBodyB->m_shapeKey;
    this->m_earlyOutDistance = v3;
    this->m_unweldedNormal = event->m_unweldedNormal;
  }
}

