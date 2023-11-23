// File Line: 391
// RVA: 0x51A5B0
void __fastcall hkInplaceArray<hkpWorldRayCastOutput,8,hkContainerHeapAllocator>::~hkInplaceArray<hkpWorldRayCastOutput,8,hkContainerHeapAllocator>(
        hkInplaceArray<hkpWorldRayCastOutput,8,hkContainerHeapAllocator> *this)
{
  int m_capacityAndFlags; // eax

  this->m_size = 0;
  m_capacityAndFlags = this->m_capacityAndFlags;
  if ( m_capacityAndFlags < 0 )
  {
    this->m_data = 0i64;
    this->m_capacityAndFlags = 0x80000000;
  }
  else
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_data,
      96 * (m_capacityAndFlags & 0x3FFFFFFF));
    this->m_data = 0i64;
    this->m_capacityAndFlags = 0x80000000;
  }
}

