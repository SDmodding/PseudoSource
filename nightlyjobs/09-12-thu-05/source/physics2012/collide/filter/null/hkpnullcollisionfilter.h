// File Line: 24
// RVA: 0xC30380
void __fastcall hkpNullCollisionFilter::hkpNullCollisionFilter(hkpNullCollisionFilter *this)
{
  hkpCollisionFilter::hkpCollisionFilter(this);
  this->hkpCollisionFilter::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpNullCollisionFilter::`vftable{for `hkReferencedObject};
  this->m_type.m_storage = 1;
  this->hkpCollisionFilter::hkpCollidableCollidableFilter::vfptr = (hkpCollidableCollidableFilterVtbl *)&hkpNullCollisionFilter::`vftable{for `hkpCollidableCollidableFilter};
  this->hkpCollisionFilter::hkpShapeCollectionFilter::vfptr = (hkpShapeCollectionFilterVtbl *)&hkpNullCollisionFilter::`vftable{for `hkpShapeCollectionFilter};
  this->hkpCollisionFilter::hkpRayShapeCollectionFilter::vfptr = (hkpRayShapeCollectionFilterVtbl *)&hkpNullCollisionFilter::`vftable{for `hkpRayShapeCollectionFilter};
  this->hkpCollisionFilter::hkpRayCollidableFilter::vfptr = (hkpRayCollidableFilterVtbl *)&hkpNullCollisionFilter::`vftable{for `hkpRayCollidableFilter};
}

