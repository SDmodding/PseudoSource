// File Line: 70
// RVA: 0xD79840
void __fastcall hkpPairCollisionFilter::hkpPairCollisionFilter(
        hkpPairCollisionFilter *this,
        hkpCollisionFilter *childFilter)
{
  hkpCollisionFilter::hkpCollisionFilter(this);
  this->hkpCollisionFilter::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpPairCollisionFilter::`vftable{for `hkReferencedObject};
  this->hkpCollisionFilter::hkpCollidableCollidableFilter::vfptr = (hkpCollidableCollidableFilterVtbl *)&hkpPairCollisionFilter::`vftable{for `hkpCollidableCollidableFilter};
  this->hkpCollisionFilter::hkpShapeCollectionFilter::vfptr = (hkpShapeCollectionFilterVtbl *)&hkpPairCollisionFilter::`vftable{for `hkpShapeCollectionFilter};
  this->hkpCollisionFilter::hkpRayShapeCollectionFilter::vfptr = (hkpRayShapeCollectionFilterVtbl *)&hkpPairCollisionFilter::`vftable{for `hkpRayShapeCollectionFilter};
  this->hkpCollisionFilter::hkpRayCollidableFilter::vfptr = (hkpRayCollidableFilterVtbl *)&hkpPairCollisionFilter::`vftable{for `hkpRayCollidableFilter};
  this->m_disabledPairs.m_hashMod = -1;
  this->m_disabledPairs.m_elem = 0i64;
  this->m_disabledPairs.m_numElems = 0;
  this->m_childFilter = childFilter;
  this->m_type.m_storage = 5;
  if ( childFilter )
    hkReferencedObject::addReference(childFilter);
}

