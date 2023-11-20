// File Line: 70
// RVA: 0xD79840
void __fastcall hkpPairCollisionFilter::hkpPairCollisionFilter(hkpPairCollisionFilter *this, hkpCollisionFilter *childFilter)
{
  hkpCollisionFilter *v2; // rdi
  hkpPairCollisionFilter *v3; // rbx

  v2 = childFilter;
  v3 = this;
  hkpCollisionFilter::hkpCollisionFilter((hkpCollisionFilter *)&this->vfptr);
  v3->vfptr = (hkBaseObjectVtbl *)&hkpPairCollisionFilter::`vftable'{for `hkReferencedObject'};
  v3->vfptr = (hkpCollidableCollidableFilterVtbl *)&hkpPairCollisionFilter::`vftable'{for `hkpCollidableCollidableFilter'};
  v3->vfptr = (hkpShapeCollectionFilterVtbl *)&hkpPairCollisionFilter::`vftable'{for `hkpShapeCollectionFilter'};
  v3->vfptr = (hkpRayShapeCollectionFilterVtbl *)&hkpPairCollisionFilter::`vftable'{for `hkpRayShapeCollectionFilter'};
  v3->vfptr = (hkpRayCollidableFilterVtbl *)&hkpPairCollisionFilter::`vftable'{for `hkpRayCollidableFilter'};
  v3->m_disabledPairs.m_hashMod = -1;
  v3->m_disabledPairs.m_elem = 0i64;
  v3->m_disabledPairs.m_numElems = 0;
  v3->m_childFilter = v2;
  v3->m_type.m_storage = 5;
  if ( v2 )
    hkReferencedObject::addReference((hkReferencedObject *)&v2->vfptr);
}

