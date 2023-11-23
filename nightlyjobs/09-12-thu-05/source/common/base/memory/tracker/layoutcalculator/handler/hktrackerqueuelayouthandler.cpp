// File Line: 18
// RVA: 0x13077C0
void __fastcall hkTrackerQueueLayoutHandler::getReferences(
        hkTrackerQueueLayoutHandler *this,
        hkTrackerLayoutBlock *curBlock,
        int *curData,
        hkTrackerTypeTreeNode *curType,
        hkTrackerLayoutCalculator *layoutCalc,
        hkArrayBase<char *> *newBlocks)
{
  unsigned __int64 v10; // rax
  __int64 v11; // r14
  unsigned __int64 v12; // r13
  __int64 v13; // rbp
  char *v14; // r12
  unsigned __int64 v15; // rdi
  _QWORD **Value; // rax
  hkTrackerLayoutBlock *v17; // rbx
  int v18; // esi
  hkTrackerTypeTreeNode *curTypea; // [rsp+70h] [rbp+18h]
  hkTrackerTypeTreeCache *layoutCalca; // [rsp+80h] [rbp+28h]
  hkTrackerLayoutCalculator *layoutCalcb; // [rsp+80h] [rbp+28h]

  layoutCalca = layoutCalc->m_typeCache.m_pntr;
  curTypea = curType->m_contains;
  v10 = hkTrackerLayoutCalculator::calcTypeSize(layoutCalc, curTypea);
  v11 = curData[2];
  v12 = v10;
  if ( (int)v11 > 0 )
  {
    v13 = (unsigned int)curData[5];
    v14 = *(char **)curData;
    v15 = v10 * v11;
    if ( curBlock->m_references.m_size == (curBlock->m_references.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&curBlock->m_references.m_data, 8);
    curBlock->m_references.m_data[curBlock->m_references.m_size++] = v14;
    layoutCalcb = (hkTrackerLayoutCalculator *)hkTrackerTypeTreeCache::newNamedNode(
                                                 layoutCalca,
                                                 TYPE_ARRAY,
                                                 "buffer_hkQueue",
                                                 0);
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v17 = (hkTrackerLayoutBlock *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 48i64);
    if ( v17 )
    {
      v17->m_start = v14;
      v17->m_size = v15;
      v17->m_type = (hkTrackerTypeTreeNode *)layoutCalcb;
      v17->m_arraySize = -1;
      v17->m_references.m_data = 0i64;
      v17->m_references.m_size = 0;
      v17->m_references.m_capacityAndFlags = 0x80000000;
    }
    else
    {
      v17 = 0i64;
    }
    if ( newBlocks->m_size == (newBlocks->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, (const void **)&newBlocks->m_data, 8);
    newBlocks->m_data[newBlocks->m_size++] = (char *)v17;
    v18 = curData[3];
    if ( (int)v13 > 0 )
    {
      do
      {
        hkTrackerLayoutCalculator::getReferencesRecursive(
          layoutCalc,
          v17,
          (const void **)&v14[v12 * v18],
          curTypea,
          newBlocks);
        v18 = (v18 + 1) % (int)v11;
        --v13;
      }
      while ( v13 );
    }
  }
}

// File Line: 53
// RVA: 0x1307970
unsigned __int64 __fastcall hkTrackerQueueLayoutHandler::getSize(
        hkTrackerQueueLayoutHandler *this,
        hkTrackerTypeTreeNode *__formal,
        hkTrackerLayoutCalculator *a3)
{
  return 24i64;
}

