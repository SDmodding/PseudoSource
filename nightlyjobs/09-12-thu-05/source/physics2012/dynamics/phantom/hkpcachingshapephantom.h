// File Line: 114
// RVA: 0xD502C0
void __fastcall hkpCachingShapePhantom::hkpCachingShapePhantom(hkpCachingShapePhantom *this, hkFinishLoadedObjectFlag flag)
{
  hkpCachingShapePhantom *v2; // rbx

  v2 = this;
  hkpWorldObject::hkpWorldObject((hkpWorldObject *)&this->vfptr, flag);
  v2->m_overlapListeners.m_capacityAndFlags = 2147483648;
  v2->m_overlapListeners.m_data = 0i64;
  v2->m_overlapListeners.m_size = 0;
  v2->m_phantomListeners.m_data = 0i64;
  v2->m_phantomListeners.m_size = 0;
  v2->m_phantomListeners.m_capacityAndFlags = 2147483648;
  v2->vfptr = (hkBaseObjectVtbl *)&hkpCachingShapePhantom::`vftable;
  v2->m_collisionDetails.m_data = 0i64;
  v2->m_collisionDetails.m_size = 0;
  v2->m_collisionDetails.m_capacityAndFlags = 2147483648;
}

