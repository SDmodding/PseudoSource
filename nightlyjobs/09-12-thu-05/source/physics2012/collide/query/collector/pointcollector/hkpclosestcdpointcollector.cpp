// File Line: 20
// RVA: 0xCED460
void __fastcall hkpClosestCdPointCollector::addCdPoint(hkpClosestCdPointCollector *this, hkpCdPoint *event)
{
  hkpClosestCdPointCollector *v2; // r8
  float v3; // xmm2_4
  hkpCdBody *v4; // rcx
  hkpCdBody *i; // rax
  hkpCdBody *v6; // rcx
  hkpCdBody *j; // rax

  v2 = this;
  LODWORD(v3) = (unsigned __int128)_mm_shuffle_ps(
                                     event->m_contact.m_separatingNormal.m_quad,
                                     event->m_contact.m_separatingNormal.m_quad,
                                     255);
  if ( !this->m_hitPoint.m_rootCollidableA
    || v3 < COERCE_FLOAT(
              _mm_shuffle_ps(
                this->m_hitPoint.m_contact.m_separatingNormal.m_quad,
                this->m_hitPoint.m_contact.m_separatingNormal.m_quad,
                255)) )
  {
    this->m_hitPoint.m_contact.m_position = event->m_contact.m_position;
    this->m_hitPoint.m_contact.m_separatingNormal = event->m_contact.m_separatingNormal;
    v4 = event->m_cdBodyA;
    for ( i = v4->m_parent; i; i = i->m_parent )
      v4 = i;
    v2->m_hitPoint.m_rootCollidableA = (hkpCollidable *)v4;
    v2->m_hitPoint.m_shapeKeyA = event->m_cdBodyA->m_shapeKey;
    v6 = event->m_cdBodyB;
    for ( j = v6->m_parent; j; j = j->m_parent )
      v6 = j;
    v2->m_hitPoint.m_rootCollidableB = (hkpCollidable *)v6;
    v2->m_hitPoint.m_shapeKeyB = event->m_cdBodyB->m_shapeKey;
    v2->m_earlyOutDistance = v3;
    v2->m_unweldedNormal = event->m_unweldedNormal;
  }
}

