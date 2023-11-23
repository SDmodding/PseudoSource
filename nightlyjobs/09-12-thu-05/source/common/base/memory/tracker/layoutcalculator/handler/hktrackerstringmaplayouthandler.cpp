// File Line: 17
// RVA: 0x1307320
void __fastcall hkTrackerStringMapLayoutHandler::getReferences(
        hkTrackerStringMapLayoutHandler *this,
        hkTrackerLayoutBlock *curBlock,
        hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *curData,
        hkTrackerTypeTreeNode *curType,
        hkTrackerLayoutCalculator *layoutCalc,
        hkArray<hkTrackerLayoutBlock const *,hkContainerTempAllocator> *newBlocks)
{
  char v9; // r13
  bool v10; // zf
  hkTrackerTypeTreeCache *m_pntr; // r12
  int Capacity; // eax
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::Elem *m_elem; // rbp
  const char *v14; // rsi
  __int64 v15; // rdi
  hkTrackerTypeTreeNode *v16; // rsi
  _QWORD **Value; // rax
  __int64 v18; // rax
  hkTrackerLayoutBlock *v19; // rbx
  hkArray<hkTrackerLayoutBlock const *,hkContainerTempAllocator> *v20; // rdi
  Dummy *Iterator; // rbp
  const char *Key; // r15
  unsigned __int64 v23; // rsi
  hkTrackerTypeTreeNode *v24; // r13
  _QWORD **v25; // rax
  __int64 v26; // rsi
  int v27; // eax
  hkBool result; // [rsp+80h] [rbp+18h] BYREF
  char v29; // [rsp+88h] [rbp+20h]

  v9 = hkSubString::operator==(&curType->m_name, &result, "hkStorageStringMap")->m_bool != 0;
  v10 = curType->m_contains->m_type == TYPE_BYTE;
  m_pntr = layoutCalc->m_typeCache.m_pntr;
  v29 = v9;
  result.m_bool = v10;
  Capacity = hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getCapacity(curData);
  if ( Capacity > 0 )
  {
    m_elem = curData->m_elem;
    v14 = "buffer_hkStringMap";
    if ( v9 )
      v14 = "buffer_hkStorageStringMap";
    v15 = 24i64 * Capacity;
    if ( curBlock->m_references.m_size == (curBlock->m_references.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&curBlock->m_references.m_data, 8);
    curBlock->m_references.m_data[curBlock->m_references.m_size++] = m_elem;
    v16 = hkTrackerTypeTreeCache::newNamedNode(m_pntr, TYPE_ARRAY, v14, 0);
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v18 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 48i64);
    v19 = (hkTrackerLayoutBlock *)v18;
    if ( v18 )
    {
      *(_QWORD *)v18 = v16;
      *(_QWORD *)(v18 + 8) = m_elem;
      *(_QWORD *)(v18 + 16) = v15;
      *(_DWORD *)(v18 + 24) = -1;
      *(_QWORD *)(v18 + 32) = 0i64;
      *(_DWORD *)(v18 + 40) = 0;
      *(_DWORD *)(v18 + 44) = 0x80000000;
    }
    else
    {
      v19 = 0i64;
    }
    v20 = newBlocks;
    if ( newBlocks->m_size == (newBlocks->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, (const void **)&newBlocks->m_data, 8);
    v20->m_data[v20->m_size++] = v19;
    Iterator = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getIterator((hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)curData);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
      (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)curData,
      (hkBool *)&layoutCalc,
      Iterator);
    while ( (_BYTE)layoutCalc )
    {
      Key = (const char *)hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getKey(curData, Iterator);
      if ( v19->m_references.m_size == (v19->m_references.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v19->m_references.m_data, 8);
      v19->m_references.m_data[v19->m_references.m_size++] = Key;
      if ( result.m_bool )
      {
        v23 = hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getValue(
                (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)curData,
                Iterator);
        if ( v19->m_references.m_size == (v19->m_references.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v19->m_references.m_data, 8);
        v19->m_references.m_data[v19->m_references.m_size++] = (const void *)v23;
      }
      if ( v9 )
      {
        v24 = hkTrackerTypeTreeCache::newNamedNode(m_pntr, TYPE_ARRAY, "buffer_hkStorageStringMap_key", 0);
        v25 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v26 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v25[11] + 8i64))(v25[11], 48i64);
        if ( v26 )
        {
          v27 = hkString::strLen(Key);
          *(_QWORD *)v26 = v24;
          *(_QWORD *)(v26 + 8) = Key;
          *(_DWORD *)(v26 + 24) = -1;
          *(_QWORD *)(v26 + 16) = v27 + 1;
          *(_QWORD *)(v26 + 32) = 0i64;
          *(_DWORD *)(v26 + 40) = 0;
          *(_DWORD *)(v26 + 44) = 0x80000000;
        }
        else
        {
          v26 = 0i64;
        }
        if ( v20->m_size == (v20->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, (const void **)&v20->m_data, 8);
        v9 = v29;
        v20->m_data[v20->m_size++] = (hkTrackerLayoutBlock *)v26;
      }
      Iterator = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getNext(
                   (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)curData,
                   Iterator);
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
        (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)curData,
        (hkBool *)&layoutCalc,
        Iterator);
    }
  }
}

// File Line: 68
// RVA: 0x1307660
unsigned __int64 __fastcall hkTrackerStringMapLayoutHandler::getSize(
        hkTrackerStringMapLayoutHandler *this,
        hkTrackerTypeTreeNode *curType,
        hkTrackerLayoutCalculator *layoutCalc)
{
  return 24i64;
}

