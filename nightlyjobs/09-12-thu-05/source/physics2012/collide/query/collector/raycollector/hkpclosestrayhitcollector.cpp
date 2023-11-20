// File Line: 14
// RVA: 0xCF8740
void __fastcall hkpClosestRayHitCollector::addRayHit(hkpClosestRayHitCollector *this, hkpCdBody *cdBody, hkpShapeRayCastCollectorOutput *hitInfo)
{
  hkpShapeRayCastCollectorOutput *v3; // rsi
  hkpCdBody *v4; // rbx
  hkpClosestRayHitCollector *v5; // rdi
  unsigned int *v6; // rcx
  hkpCdBody *i; // rax

  v3 = hitInfo;
  v4 = cdBody;
  v5 = this;
  if ( this->m_rayHit.m_hitFraction > hitInfo->m_hitFraction )
  {
    v6 = this->m_rayHit.m_shapeKeys;
    *((_OWORD *)v6 - 2) = hitInfo->m_normal;
    *(v6 - 4) = LODWORD(hitInfo->m_hitFraction);
    *(v6 - 3) = hitInfo->m_extraInfo;
    *(v6 - 2) = hitInfo->m_pad[0];
    *(v6 - 1) = hitInfo->m_pad[1];
    hkpRayHitCollector::shapeKeysFromCdBody(v6, 8, cdBody);
    for ( i = v4->m_parent; i; i = i->m_parent )
      v4 = i;
    v5->m_rayHit.m_rootCollidable = (hkpCollidable *)v4;
    v5->m_earlyOutHitFraction = v3->m_hitFraction;
  }
}

