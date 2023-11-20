// File Line: 533
// RVA: 0xE51B0
void __fastcall hkArray<unsigned int,hkContainerTempAllocator>::~hkArray<unsigned int,hkContainerTempAllocator>(hkArray<unsigned int,hkContainerTempAllocator> *this)
{
  int v1; // er8
  hkArray<unsigned int,hkContainerTempAllocator> *v2; // rbx

  v1 = this->m_capacityAndFlags;
  v2 = this;
  this->m_size = 0;
  if ( v1 < 0 )
  {
    this->m_data = 0i64;
    this->m_capacityAndFlags = 2147483648;
  }
  else
  {
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      this->m_data,
      4 * v1);
    v2->m_data = 0i64;
    v2->m_capacityAndFlags = 2147483648;
  }
}

