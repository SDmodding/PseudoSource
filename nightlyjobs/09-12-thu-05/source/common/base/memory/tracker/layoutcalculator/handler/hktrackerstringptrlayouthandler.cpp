// File Line: 17
// RVA: 0x1307670
void __fastcall hkTrackerStringPtrLayoutHandler::getReferences(hkTrackerStringPtrLayoutHandler *this, hkTrackerLayoutBlock *curBlock, const void *curData, hkTrackerTypeTreeNode *__formal, hkTrackerLayoutCalculator *layoutCalc, hkArray<hkTrackerLayoutBlock const *,hkContainerTempAllocator> *newBlocks)
{
  hkArray<void const *,hkContainerHeapAllocator> *v6; // rbx
  hkTrackerTypeTreeCache *v7; // rbp
  hkStringPtr *v8; // rsi
  unsigned __int64 v9; // rdi
  hkTrackerTypeTreeNode *v10; // rbp
  _QWORD **v11; // rax
  hkTrackerLayoutBlock *v12; // rdi
  unsigned __int64 v13; // rbx
  int v14; // eax

  if ( curData )
  {
    v6 = &curBlock->m_references;
    v7 = layoutCalc->m_typeCache.m_pntr;
    v8 = (hkStringPtr *)curData;
    v9 = *(_QWORD *)curData & 0xFFFFFFFFFFFFFFFEui64;
    if ( curBlock->m_references.m_size == (curBlock->m_references.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &curBlock->m_references,
        8);
    v6->m_data[v6->m_size++] = (const void *)v9;
    if ( (_QWORD)v8->m_stringAndFlag & 1 )
    {
      v10 = hkTrackerTypeTreeCache::newNamedNode(v7, TYPE_ARRAY, "buffer_hkStringPtr", 0);
      v11 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v12 = (hkTrackerLayoutBlock *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v11[11] + 8i64))(
                                      v11[11],
                                      48i64);
      if ( v12 )
      {
        v13 = (_QWORD)v8->m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64;
        v14 = hkStringPtr::getLength(v8);
        v12->m_type = v10;
        v12->m_start = (const void *)v13;
        v12->m_arraySize = -1;
        v12->m_size = v14 + 1;
        v12->m_references.m_data = 0i64;
        v12->m_references.m_size = 0;
        v12->m_references.m_capacityAndFlags = 2147483648;
      }
      else
      {
        v12 = 0i64;
      }
      if ( newBlocks->m_size == (newBlocks->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, newBlocks, 8);
      newBlocks->m_data[newBlocks->m_size++] = v12;
    }
  }
}

// File Line: 38
// RVA: 0x13077B0
unsigned __int64 __fastcall hkTrackerStringPtrLayoutHandler::getSize(hkTrackerStringPtrLayoutHandler *this, hkTrackerTypeTreeNode *__formal, hkTrackerLayoutCalculator *a3)
{
  return 8i64;
}

