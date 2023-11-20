// File Line: 18
// RVA: 0x13077C0
void __fastcall hkTrackerQueueLayoutHandler::getReferences(hkTrackerQueueLayoutHandler *this, hkTrackerLayoutBlock *curBlock, const void *curData, hkTrackerTypeTreeNode *curType, hkTrackerLayoutCalculator *layoutCalc, hkArray<hkTrackerLayoutBlock const *,hkContainerTempAllocator> *newBlocks)
{
  hkTrackerLayoutCalculator *v6; // r15
  hkTrackerLayoutBlock *v7; // rbx
  signed int *v8; // rsi
  hkTrackerLayoutCalculator *v9; // rcx
  unsigned __int64 v10; // rax
  __int64 v11; // r14
  unsigned __int64 v12; // r13
  __int64 v13; // rbp
  char *v14; // r12
  unsigned __int64 v15; // rdi
  _QWORD **v16; // rax
  hkTrackerLayoutBlock *v17; // rbx
  int v18; // esi
  hkTrackerTypeTreeNode *curTypea; // [rsp+70h] [rbp+18h]
  hkTrackerTypeTreeCache *layoutCalca; // [rsp+80h] [rbp+28h]
  hkTrackerLayoutCalculator *layoutCalcb; // [rsp+80h] [rbp+28h]

  v6 = layoutCalc;
  v7 = curBlock;
  v8 = (signed int *)curData;
  v9 = layoutCalc;
  layoutCalca = layoutCalc->m_typeCache.m_pntr;
  curTypea = curType->m_contains;
  v10 = hkTrackerLayoutCalculator::calcTypeSize(v9, curType->m_contains);
  v11 = v8[2];
  v12 = v10;
  if ( (signed int)v11 > 0 )
  {
    v13 = (unsigned int)v8[5];
    v14 = *(char **)v8;
    v15 = v10 * v11;
    if ( v7->m_references.m_size == (v7->m_references.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v7->m_references, 8);
    v7->m_references.m_data[v7->m_references.m_size++] = v14;
    layoutCalcb = (hkTrackerLayoutCalculator *)hkTrackerTypeTreeCache::newNamedNode(
                                                 layoutCalca,
                                                 TYPE_ARRAY,
                                                 "buffer_hkQueue",
                                                 0);
    v16 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v17 = (hkTrackerLayoutBlock *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v16[11] + 8i64))(
                                    v16[11],
                                    48i64);
    if ( v17 )
    {
      v17->m_start = v14;
      v17->m_size = v15;
      v17->m_type = (hkTrackerTypeTreeNode *)layoutCalcb;
      v17->m_arraySize = -1;
      v17->m_references.m_data = 0i64;
      v17->m_references.m_size = 0;
      v17->m_references.m_capacityAndFlags = 2147483648;
    }
    else
    {
      v17 = 0i64;
    }
    if ( newBlocks->m_size == (newBlocks->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, newBlocks, 8);
    newBlocks->m_data[newBlocks->m_size++] = v17;
    v18 = v8[3];
    if ( (signed int)v13 > 0 )
    {
      do
      {
        hkTrackerLayoutCalculator::getReferencesRecursive(v6, v17, &v14[v12 * v18], curTypea, newBlocks);
        v18 = (v18 + 1) % (signed int)v11;
        --v13;
      }
      while ( v13 );
    }
  }
}

// File Line: 53
// RVA: 0x1307970
unsigned __int64 __fastcall hkTrackerQueueLayoutHandler::getSize(hkTrackerQueueLayoutHandler *this, hkTrackerTypeTreeNode *__formal, hkTrackerLayoutCalculator *a3)
{
  return 24i64;
}

