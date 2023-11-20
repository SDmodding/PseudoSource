// File Line: 17
// RVA: 0x13072B0
void __fastcall hkTrackerRefPtrLayoutHandler::getReferences(hkTrackerRefPtrLayoutHandler *this, hkTrackerLayoutBlock *curBlock, const void *curData, hkTrackerTypeTreeNode *__formal, hkTrackerLayoutCalculator *__formala, hkArray<hkTrackerLayoutBlock const *,hkContainerTempAllocator> *a6)
{
  hkArray<void const *,hkContainerHeapAllocator> *v6; // rbx
  const void *v7; // rdi

  if ( curData )
  {
    v6 = &curBlock->m_references;
    v7 = *(const void **)curData;
    if ( curBlock->m_references.m_size == (curBlock->m_references.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &curBlock->m_references,
        8);
    v6->m_data[v6->m_size++] = v7;
  }
}

// File Line: 29
// RVA: 0x1307310
unsigned __int64 __fastcall hkTrackerRefPtrLayoutHandler::getSize(hkTrackerRefPtrLayoutHandler *this, hkTrackerTypeTreeNode *__formal, hkTrackerLayoutCalculator *a3)
{
  return 8i64;
}

