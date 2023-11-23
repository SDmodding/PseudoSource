// File Line: 74
// RVA: 0x9DEE0
void __fastcall hkArrayBase<unsigned short>::operator delete(void *p, unsigned __int64 nbytes)
{
  _QWORD **Value; // rax

  if ( p )
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, void *, __int64))(*Value[11] + 16i64))(Value[11], p, 16i64);
  }
}

// File Line: 391
// RVA: 0x9AA30
void __fastcall hkInplaceArray<hkpRootCdBodyPair,16,hkContainerHeapAllocator>::~hkInplaceArray<hkpRootCdBodyPair,16,hkContainerHeapAllocator>(
        hkInplaceArray<hkpRootCdBodyPair,16,hkContainerHeapAllocator> *this)
{
  int m_capacityAndFlags; // r8d

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
      32 * m_capacityAndFlags);
    this->m_data = 0i64;
    this->m_capacityAndFlags = 0x80000000;
  }
}

