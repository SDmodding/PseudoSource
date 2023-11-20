// File Line: 391
// RVA: 0x51A5B0
void __fastcall hkInplaceArray<hkpWorldRayCastOutput,8,hkContainerHeapAllocator>::~hkInplaceArray<hkpWorldRayCastOutput,8,hkContainerHeapAllocator>(hkInplaceArray<hkpWorldRayCastOutput,8,hkContainerHeapAllocator> *this)
{
  hkInplaceArray<hkpWorldRayCastOutput,8,hkContainerHeapAllocator> *v1; // rbx
  int v2; // eax

  v1 = this;
  this->m_size = 0;
  v2 = this->m_capacityAndFlags;
  if ( v2 < 0 )
  {
    this->m_data = 0i64;
    this->m_capacityAndFlags = 2147483648;
  }
  else
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      this->m_data,
      96 * (v2 & 0x3FFFFFFF));
    v1->m_data = 0i64;
    v1->m_capacityAndFlags = 2147483648;
  }
}

