// File Line: 76
// RVA: 0x9ABE0
void __fastcall hkLocalBuffer<hkaKeyFrameHierarchyUtility::Output>::~hkLocalBuffer<hkaKeyFrameHierarchyUtility::Output>(hkLocalBuffer<hkaKeyFrameHierarchyUtility::Output> *this)
{
  hkaKeyFrameHierarchyUtility::Output *v1; // rdi
  signed int v2; // ebx
  hkLifoAllocator *v3; // rax
  int v4; // er8

  v1 = this->m_data.m_storage;
  v2 = (4 * this->m_size.m_storage + 127) & 0xFFFFFF80;
  v3 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v4 = (v2 + 15) & 0xFFFFFFF0;
  if ( v2 > v3->m_slabSize || (char *)v1 + v4 != v3->m_cur || v3->m_firstNonLifoEnd == v1 )
    hkLifoAllocator::slowBlockFree(v3, v1, v4);
  else
    v3->m_cur = v1;
}

