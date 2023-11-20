// File Line: 74
// RVA: 0x9DEE0
void __fastcall hkArrayBase<unsigned short>::operator delete(void *p, unsigned __int64 nbytes)
{
  void *v2; // rbx
  _QWORD **v3; // rax

  if ( p )
  {
    v2 = p;
    v3 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, void *, signed __int64))(*v3[11] + 16i64))(v3[11], v2, 16i64);
  }
}

// File Line: 391
// RVA: 0x9AA30
void __fastcall hkInplaceArray<hkpRootCdBodyPair,16,hkContainerHeapAllocator>::~hkInplaceArray<hkpRootCdBodyPair,16,hkContainerHeapAllocator>(hkInplaceArray<hkpRootCdBodyPair,16,hkContainerHeapAllocator> *this)
{
  hkInplaceArray<hkpRootCdBodyPair,16,hkContainerHeapAllocator> *v1; // rbx
  int v2; // er8

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
      32 * v2);
    v1->m_data = 0i64;
    v1->m_capacityAndFlags = 2147483648;
  }
}

