// File Line: 54
// RVA: 0x44ED00
void __fastcall hkLocalArray<hkpRigidBody *>::~hkLocalArray<hkpRigidBody *>(hkLocalArray<hkpShape const *> *this)
{
  hkLocalArray<hkpShape const *> *v1; // rdi
  hkpShape **v2; // rsi
  int v3; // ebx
  hkLifoAllocator *v4; // rax
  signed int v5; // ebx
  int v6; // er8
  int v7; // er8

  v1 = this;
  v2 = this->m_localMemory;
  if ( v2 == this->m_data )
    this->m_size = 0;
  v3 = this->m_initialCapacity;
  v4 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (8 * v3 + 127) & 0xFFFFFF80;
  v6 = (v5 + 15) & 0xFFFFFFF0;
  if ( v5 > v4->m_slabSize || (char *)v2 + v6 != v4->m_cur || v4->m_firstNonLifoEnd == v2 )
    hkLifoAllocator::slowBlockFree(v4, v2, v6);
  else
    v4->m_cur = v2;
  v1->m_size = 0;
  v7 = v1->m_capacityAndFlags;
  if ( v7 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_data,
      8 * v7);
  v1->m_capacityAndFlags = 2147483648;
  v1->m_data = 0i64;
}

