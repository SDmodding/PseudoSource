// File Line: 533
// RVA: 0xE51B0
void __fastcall hkArray<unsigned int,hkContainerTempAllocator>::~hkArray<unsigned int,hkContainerTempAllocator>(
        hkArray<unsigned int,hkContainerTempAllocator> *this)
{
  int m_capacityAndFlags; // r8d

  m_capacityAndFlags = this->m_capacityAndFlags;
  this->m_size = 0;
  if ( m_capacityAndFlags < 0 )
  {
    this->m_data = 0i64;
    this->m_capacityAndFlags = 0x80000000;
  }
  else
  {
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      this->m_data,
      4 * m_capacityAndFlags);
    this->m_data = 0i64;
    this->m_capacityAndFlags = 0x80000000;
  }
}

