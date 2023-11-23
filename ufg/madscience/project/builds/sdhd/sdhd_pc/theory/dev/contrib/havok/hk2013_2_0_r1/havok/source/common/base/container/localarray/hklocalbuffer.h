// File Line: 76
// RVA: 0x9ABE0
void __fastcall hkLocalBuffer<hkaKeyFrameHierarchyUtility::Output>::~hkLocalBuffer<hkaKeyFrameHierarchyUtility::Output>(
        hkLocalBuffer<hkaKeyFrameHierarchyUtility::Output> *this)
{
  hkaKeyFrameHierarchyUtility::Output *m_storage; // rdi
  signed int v2; // ebx
  hkLifoAllocator *Value; // rax
  int v4; // r8d

  m_storage = this->m_data.m_storage;
  v2 = (4 * this->m_size.m_storage + 127) & 0xFFFFFF80;
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v4 = (v2 + 15) & 0xFFFFFFF0;
  if ( v2 > Value->m_slabSize || (char *)m_storage + v4 != Value->m_cur || Value->m_firstNonLifoEnd == m_storage )
    hkLifoAllocator::slowBlockFree(Value, m_storage, v4);
  else
    Value->m_cur = m_storage;
}

