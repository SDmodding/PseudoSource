// File Line: 110
// RVA: 0xD4F720
void __fastcall hkpSimpleShapePhantom::hkpSimpleShapePhantom(
        hkpSimpleShapePhantom *this,
        hkFinishLoadedObjectFlag flag)
{
  hkpWorldObject::hkpWorldObject(this, flag);
  this->m_overlapListeners.m_capacityAndFlags = 0x80000000;
  this->m_overlapListeners.m_data = 0i64;
  this->m_overlapListeners.m_size = 0;
  this->m_phantomListeners.m_data = 0i64;
  this->m_phantomListeners.m_size = 0;
  this->m_phantomListeners.m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkBaseObjectVtbl *)&hkpSimpleShapePhantom::`vftable;
  this->m_collisionDetails.m_data = 0i64;
  this->m_collisionDetails.m_size = 0;
  this->m_collisionDetails.m_capacityAndFlags = 0x80000000;
}

