// File Line: 24
// RVA: 0xD4FA50
void __fastcall hkpAabbPhantom::hkpAabbPhantom(hkpAabbPhantom *this, hkFinishLoadedObjectFlag flag)
{
  hkpAabbPhantom *v2; // rbx

  v2 = this;
  hkpWorldObject::hkpWorldObject((hkpWorldObject *)&this->vfptr, flag);
  v2->m_overlapListeners.m_capacityAndFlags = 2147483648;
  v2->m_overlapListeners.m_data = 0i64;
  v2->m_overlapListeners.m_size = 0;
  v2->m_phantomListeners.m_data = 0i64;
  v2->m_phantomListeners.m_size = 0;
  v2->m_phantomListeners.m_capacityAndFlags = 2147483648;
  v2->vfptr = (hkBaseObjectVtbl *)&hkpAabbPhantom::`vftable';
  v2->m_overlappingCollidables.m_data = 0i64;
  v2->m_overlappingCollidables.m_size = 0;
  v2->m_overlappingCollidables.m_capacityAndFlags = 2147483648;
}

