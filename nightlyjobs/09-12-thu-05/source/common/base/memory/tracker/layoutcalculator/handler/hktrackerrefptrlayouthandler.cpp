// File Line: 17
// RVA: 0x13072B0
void __fastcall hkTrackerRefPtrLayoutHandler::getReferences(
        hkTrackerRefPtrLayoutHandler *this,
        hkTrackerLayoutBlock *curBlock,
        const void **curData,
        hkTrackerTypeTreeNode *__formal,
        hkTrackerLayoutCalculator *__formala,
        hkArray<hkTrackerLayoutBlock const *,hkContainerTempAllocator> *a6)
{
  hkArray<void const *,hkContainerHeapAllocator> *p_m_references; // rbx
  const void *v7; // rdi

  if ( curData )
  {
    p_m_references = &curBlock->m_references;
    v7 = *curData;
    if ( curBlock->m_references.m_size == (curBlock->m_references.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&curBlock->m_references.m_data, 8);
    p_m_references->m_data[p_m_references->m_size++] = v7;
  }
}

// File Line: 29
// RVA: 0x1307310
unsigned __int64 __fastcall hkTrackerRefPtrLayoutHandler::getSize(
        hkTrackerRefPtrLayoutHandler *this,
        hkTrackerTypeTreeNode *__formal,
        hkTrackerLayoutCalculator *a3)
{
  return 8i64;
}

