// File Line: 14
// RVA: 0xCF8740
void __fastcall hkpClosestRayHitCollector::addRayHit(
        hkpClosestRayHitCollector *this,
        hkpCollidable *cdBody,
        hkpShapeRayCastCollectorOutput *hitInfo)
{
  hkpCollidable *v4; // rbx
  unsigned int *m_shapeKeys; // rcx
  hkpCollidable *i; // rax

  v4 = cdBody;
  if ( this->m_rayHit.m_hitFraction > hitInfo->m_hitFraction )
  {
    m_shapeKeys = this->m_rayHit.m_shapeKeys;
    *((hkpShapeRayCastCollectorOutput *)m_shapeKeys - 1) = *hitInfo;
    hkpRayHitCollector::shapeKeysFromCdBody(m_shapeKeys, 8, cdBody);
    for ( i = (hkpCollidable *)v4->m_parent; i; i = (hkpCollidable *)i->m_parent )
      v4 = i;
    this->m_rayHit.m_rootCollidable = v4;
    this->m_earlyOutHitFraction = hitInfo->m_hitFraction;
  }
}

