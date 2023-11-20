// File Line: 17
// RVA: 0x1307320
void __fastcall hkTrackerStringMapLayoutHandler::getReferences(hkTrackerStringMapLayoutHandler *this, hkTrackerLayoutBlock *curBlock, const void *curData, hkTrackerTypeTreeNode *curType, hkTrackerLayoutCalculator *layoutCalc, hkArray<hkTrackerLayoutBlock const *,hkContainerTempAllocator> *newBlocks)
{
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *v6; // r14
  hkTrackerLayoutBlock *v7; // r15
  hkTrackerTypeTreeNode *v8; // rbx
  hkBool *v9; // rax
  char v10; // r13
  bool v11; // zf
  hkTrackerTypeTreeCache *v12; // r12
  int v13; // eax
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::Elem *v14; // rbp
  const char *v15; // rsi
  signed __int64 v16; // rdi
  hkTrackerTypeTreeNode *v17; // rsi
  _QWORD **v18; // rax
  __int64 v19; // rax
  hkTrackerLayoutBlock *v20; // rbx
  hkArray<hkTrackerLayoutBlock const *,hkContainerTempAllocator> *v21; // rdi
  Dummy *v22; // rbp
  const char *v23; // r15
  unsigned __int64 v24; // rsi
  hkTrackerTypeTreeNode *v25; // r13
  _QWORD **v26; // rax
  __int64 v27; // rsi
  int v28; // eax
  hkBool result; // [rsp+80h] [rbp+18h]
  bool v30; // [rsp+88h] [rbp+20h]

  v6 = (hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *)curData;
  v7 = curBlock;
  v8 = curType;
  v9 = hkSubString::operator==(&curType->m_name, &result, "hkStorageStringMap");
  v10 = v9->m_bool != 0;
  v11 = v8->m_contains->m_type == 1;
  v12 = layoutCalc->m_typeCache.m_pntr;
  v30 = v9->m_bool != 0;
  result.m_bool = v11;
  v13 = hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getCapacity(v6);
  if ( v13 > 0 )
  {
    v14 = v6->m_elem;
    v15 = "buffer_hkStringMap";
    if ( v10 )
      v15 = "buffer_hkStorageStringMap";
    v16 = 24i64 * v13;
    if ( v7->m_references.m_size == (v7->m_references.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v7->m_references, 8);
    v7->m_references.m_data[v7->m_references.m_size++] = v14;
    v17 = hkTrackerTypeTreeCache::newNamedNode(v12, TYPE_ARRAY, v15, 0);
    v18 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v19 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v18[11] + 8i64))(v18[11], 48i64);
    v20 = (hkTrackerLayoutBlock *)v19;
    if ( v19 )
    {
      *(_QWORD *)v19 = v17;
      *(_QWORD *)(v19 + 8) = v14;
      *(_QWORD *)(v19 + 16) = v16;
      *(_DWORD *)(v19 + 24) = -1;
      *(_QWORD *)(v19 + 32) = 0i64;
      *(_DWORD *)(v19 + 40) = 0;
      *(_DWORD *)(v19 + 44) = 2147483648;
    }
    else
    {
      v20 = 0i64;
    }
    v21 = newBlocks;
    if ( newBlocks->m_size == (newBlocks->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, newBlocks, 8);
    v21->m_data[v21->m_size++] = v20;
    v22 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getIterator((hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)v6);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
      (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)v6,
      (hkBool *)&layoutCalc,
      v22);
    while ( (_BYTE)layoutCalc )
    {
      v23 = (const char *)hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getKey(v6, v22);
      if ( v20->m_references.m_size == (v20->m_references.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v20->m_references, 8);
      v20->m_references.m_data[v20->m_references.m_size++] = v23;
      if ( result.m_bool )
      {
        v24 = hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getValue(
                (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)v6,
                v22);
        if ( v20->m_references.m_size == (v20->m_references.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            &v20->m_references,
            8);
        v20->m_references.m_data[v20->m_references.m_size++] = (const void *)v24;
      }
      if ( v10 )
      {
        v25 = hkTrackerTypeTreeCache::newNamedNode(v12, TYPE_ARRAY, "buffer_hkStorageStringMap_key", 0);
        v26 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v27 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v26[11] + 8i64))(v26[11], 48i64);
        if ( v27 )
        {
          v28 = hkString::strLen(v23);
          *(_QWORD *)v27 = v25;
          *(_QWORD *)(v27 + 8) = v23;
          *(_DWORD *)(v27 + 24) = -1;
          *(_QWORD *)(v27 + 16) = v28 + 1;
          *(_QWORD *)(v27 + 32) = 0i64;
          *(_DWORD *)(v27 + 40) = 0;
          *(_DWORD *)(v27 + 44) = 2147483648;
        }
        else
        {
          v27 = 0i64;
        }
        if ( v21->m_size == (v21->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v21, 8);
        v10 = v30;
        v21->m_data[v21->m_size++] = (hkTrackerLayoutBlock *)v27;
      }
      v22 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getNext(
              (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)v6,
              v22);
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
        (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)v6,
        (hkBool *)&layoutCalc,
        v22);
    }
  }
}

// File Line: 68
// RVA: 0x1307660
unsigned __int64 __fastcall hkTrackerStringMapLayoutHandler::getSize(hkTrackerStringMapLayoutHandler *this, hkTrackerTypeTreeNode *curType, hkTrackerLayoutCalculator *layoutCalc)
{
  return 24i64;
}

