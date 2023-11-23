// File Line: 17
// RVA: 0x1307670
void __fastcall hkTrackerStringPtrLayoutHandler::getReferences(
        hkTrackerStringPtrLayoutHandler *this,
        hkTrackerLayoutBlock *curBlock,
        hkStringPtr *curData,
        hkTrackerTypeTreeNode *__formal,
        hkTrackerLayoutCalculator *layoutCalc,
        hkArray<hkTrackerLayoutBlock const *,hkContainerTempAllocator> *newBlocks)
{
  hkArray<void const *,hkContainerHeapAllocator> *p_m_references; // rbx
  hkTrackerTypeTreeCache *m_pntr; // rbp
  unsigned __int64 v9; // rdi
  hkTrackerTypeTreeNode *v10; // rbp
  _QWORD **Value; // rax
  hkTrackerLayoutBlock *v12; // rdi
  unsigned __int64 v13; // rbx
  int Length; // eax

  if ( curData )
  {
    p_m_references = &curBlock->m_references;
    m_pntr = layoutCalc->m_typeCache.m_pntr;
    v9 = (unsigned __int64)curData->m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64;
    if ( curBlock->m_references.m_size == (curBlock->m_references.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&curBlock->m_references.m_data, 8);
    p_m_references->m_data[p_m_references->m_size++] = (const void *)v9;
    if ( ((__int64)curData->m_stringAndFlag & 1) != 0 )
    {
      v10 = hkTrackerTypeTreeCache::newNamedNode(m_pntr, TYPE_ARRAY, "buffer_hkStringPtr", 0);
      Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v12 = (hkTrackerLayoutBlock *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 48i64);
      if ( v12 )
      {
        v13 = (unsigned __int64)curData->m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64;
        Length = hkStringPtr::getLength(curData);
        v12->m_type = v10;
        v12->m_start = (const void *)v13;
        v12->m_arraySize = -1;
        v12->m_size = Length + 1;
        v12->m_references.m_data = 0i64;
        v12->m_references.m_size = 0;
        v12->m_references.m_capacityAndFlags = 0x80000000;
      }
      else
      {
        v12 = 0i64;
      }
      if ( newBlocks->m_size == (newBlocks->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, (const void **)&newBlocks->m_data, 8);
      newBlocks->m_data[newBlocks->m_size++] = v12;
    }
  }
}

// File Line: 38
// RVA: 0x13077B0
unsigned __int64 __fastcall hkTrackerStringPtrLayoutHandler::getSize(
        hkTrackerStringPtrLayoutHandler *this,
        hkTrackerTypeTreeNode *__formal,
        hkTrackerLayoutCalculator *a3)
{
  return 8i64;
}

