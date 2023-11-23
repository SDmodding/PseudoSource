// File Line: 24
// RVA: 0xD4FA50
void __fastcall hkpAabbPhantom::hkpAabbPhantom(hkpAabbPhantom *this, hkFinishLoadedObjectFlag flag)
{
  hkpWorldObject::hkpWorldObject(this, flag);
  this->m_overlapListeners.m_capacityAndFlags = 0x80000000;
  this->m_overlapListeners.m_data = 0i64;
  this->m_overlapListeners.m_size = 0;
  this->m_phantomListeners.m_data = 0i64;
  this->m_phantomListeners.m_size = 0;
  this->m_phantomListeners.m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkBaseObjectVtbl *)&hkpAabbPhantom::`vftable;
  this->m_overlappingCollidables.m_data = 0i64;
  this->m_overlappingCollidables.m_size = 0;
  this->m_overlappingCollidables.m_capacityAndFlags = 0x80000000;
}

