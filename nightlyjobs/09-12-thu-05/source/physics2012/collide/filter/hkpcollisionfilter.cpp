// File Line: 16
// RVA: 0xCED1F0
void __fastcall hkpCollisionFilter::hkpCollisionFilter(hkpCollisionFilter *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpCollisionFilter::`vftable{for `hkReferencedObject};
  this->hkpCollidableCollidableFilter::vfptr = (hkpCollidableCollidableFilterVtbl *)&hkpCollisionFilter::`vftable{for `hkpCollidableCollidableFilter};
  this->hkpShapeCollectionFilter::vfptr = (hkpShapeCollectionFilterVtbl *)&hkpCollisionFilter::`vftable{for `hkpShapeCollectionFilter};
  this->hkpRayShapeCollectionFilter::vfptr = (hkpRayShapeCollectionFilterVtbl *)&hkpCollisionFilter::`vftable{for `hkpRayShapeCollectionFilter};
  this->hkpRayCollidableFilter::vfptr = (hkpRayCollidableFilterVtbl *)&hkpCollisionFilter::`vftable{for `hkpRayCollidableFilter};
  this->m_type.m_storage = 0;
}

// File Line: 24
// RVA: 0xCED240
__int64 __fastcall hkpCollisionFilter::numShapeKeyHitsLimitBreached(
        hkpCollisionFilter *this,
        hkpCollisionInput *input,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpBvTreeShape *bvTreeShapeB,
        hkAabb *aabb,
        unsigned int *shapeKeysInOut,
        unsigned int shapeKeysCapacity)
{
  return shapeKeysCapacity;
}

