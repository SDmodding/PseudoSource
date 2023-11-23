// File Line: 54
// RVA: 0x44ED00
void __fastcall hkLocalArray<hkpRigidBody *>::~hkLocalArray<hkpRigidBody *>(hkLocalArray<hkpShape const *> *this)
{
  hkpShape **m_localMemory; // rsi
  int m_initialCapacity; // ebx
  hkLifoAllocator *Value; // rax
  signed int v5; // ebx
  int v6; // r8d
  int m_capacityAndFlags; // r8d

  m_localMemory = this->m_localMemory;
  if ( m_localMemory == this->m_data )
    this->m_size = 0;
  m_initialCapacity = this->m_initialCapacity;
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (8 * m_initialCapacity + 127) & 0xFFFFFF80;
  v6 = (v5 + 15) & 0xFFFFFFF0;
  if ( v5 > Value->m_slabSize || (char *)m_localMemory + v6 != Value->m_cur || Value->m_firstNonLifoEnd == m_localMemory )
    hkLifoAllocator::slowBlockFree(Value, m_localMemory, v6);
  else
    Value->m_cur = m_localMemory;
  this->m_size = 0;
  m_capacityAndFlags = this->m_capacityAndFlags;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_data,
      8 * m_capacityAndFlags);
  this->m_capacityAndFlags = 0x80000000;
  this->m_data = 0i64;
}

