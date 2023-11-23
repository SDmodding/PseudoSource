// File Line: 98
// RVA: 0xE0A2D0
void __fastcall hkpFirstPersonGun::~hkpFirstPersonGun(hkpFirstPersonGun *this)
{
  int v1; // esi
  __int64 v3; // rdi
  int m_capacityAndFlags; // r8d

  v1 = 0;
  this->vfptr = (hkBaseObjectVtbl *)&hkpFirstPersonGun::`vftable;
  if ( this->m_listeners.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      hkReferencedObject::removeReference(this->m_listeners.m_data[v3]);
      ++v1;
      ++v3;
    }
    while ( v1 < this->m_listeners.m_size );
  }
  m_capacityAndFlags = this->m_listeners.m_capacityAndFlags;
  this->m_listeners.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_listeners.m_data,
      8 * m_capacityAndFlags);
  this->m_listeners.m_data = 0i64;
  this->m_listeners.m_capacityAndFlags = 0x80000000;
  hkStringPtr::~hkStringPtr(&this->m_name);
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

