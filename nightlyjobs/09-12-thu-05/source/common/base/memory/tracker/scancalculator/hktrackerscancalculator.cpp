// File Line: 16
// RVA: 0x1305DA0
hkTrackerScanSnapshot *__fastcall hkTrackerScanCalculator::createSnapshot(
        hkTrackerScanCalculator *this,
        hkTrackerSnapshot *snapshot,
        hkTrackerLayoutCalculator *layoutCalc)
{
  hkTrackerScanSnapshot *result; // rax
  hkTrackerScanSnapshot *v7; // rbx

  hkTrackerTypeInit::registerTypes(hkMemoryTracker::s_singleton);
  result = hkTrackerScanCalculator::_createSnapshot(this, snapshot, layoutCalc);
  v7 = result;
  if ( hkMemoryTracker::s_singleton )
  {
    hkMemoryTracker::s_singleton->vfptr->clearTypeDefinitions(hkMemoryTracker::s_singleton);
    return v7;
  }
  return result;
}

// File Line: 29
// RVA: 0x1305E00
hkTrackerScanSnapshot *__fastcall hkTrackerScanCalculator::_createSnapshot(
        hkTrackerScanCalculator *this,
        hkTrackerSnapshot *snapshotIn,
        hkTrackerLayoutCalculator *layoutCalc)
{
  _QWORD **Value; // rax
  hkTrackerScanSnapshot *v7; // rax
  hkTrackerTypeTreeCache *m_pntr; // r14
  int v9; // r12d
  __int64 v10; // r15
  hkDefaultMemoryTracker::ClassAlloc *v11; // rsi
  const char *m_typeName; // rdi
  hkTrackerTypeTreeNode *v13; // rbx
  char *v14; // rdi
  hkLifoAllocator *v15; // rax
  char *m_cur; // rbx
  char *v17; // rcx
  hkLifoAllocator *v18; // rax
  hkTrackerScanCalculator *v19; // r12
  hkTrackerScanSnapshot *m_scanSnapshot; // rsi
  int m_numElems; // r9d
  int v22; // r15d
  __int64 v23; // r14
  hkTrackerScanSnapshot::Block *v24; // rdi
  _QWORD **v25; // rax
  __int64 v26; // rbx
  int m_arraySize; // r8d
  unsigned __int64 m_size; // rdx
  hkTrackerTypeTreeNode *m_type; // rax
  int v30; // ecx
  int v31; // edi
  __int64 v32; // rbx
  hkTrackerScanSnapshot *v33; // rbx
  int m_hashMod; // r8d
  hkArray<hkTrackerScanSnapshot::Block *,hkContainerHeapAllocator> *p_m_references; // rbx
  int v36; // r15d
  hkTrackerLayoutCalculator *v37; // r14
  __int64 v38; // rsi
  unsigned __int64 v39; // rax
  int v40; // edi
  unsigned __int64 v41; // r13
  __int64 v42; // r14
  unsigned __int64 v43; // r15
  int v44; // r8d
  _QWORD **v45; // rax
  hkArrayBase<char *> array; // [rsp+20h] [rbp-30h] BYREF
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> v48; // [rsp+30h] [rbp-20h] BYREF
  int v50; // [rsp+90h] [rbp+40h]
  hkTrackerLayoutCalculator *v52; // [rsp+A0h] [rbp+50h]

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (hkTrackerScanSnapshot *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 344i64);
  if ( v7 )
    hkTrackerScanSnapshot::hkTrackerScanSnapshot(v7, snapshotIn, layoutCalc);
  this->m_scanSnapshot = v7;
  m_pntr = layoutCalc->m_typeCache.m_pntr;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &v48,
    0);
  v9 = 0;
  if ( snapshotIn->m_classAllocations.m_size > 0 )
  {
    v10 = 0i64;
    do
    {
      v11 = &snapshotIn->m_classAllocations.m_data[v10];
      m_typeName = v11->m_typeName;
      v13 = (hkTrackerTypeTreeNode *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                                       (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v48,
                                       v11->m_typeName,
                                       0i64);
      if ( !v13 )
      {
        if ( *m_typeName == 33 )
        {
          v14 = hkTrackerTypeTreeCache::newText(m_pntr, (char *)m_typeName + 1);
        }
        else
        {
          v15 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          m_cur = (char *)v15->m_cur;
          v17 = m_cur + 128;
          if ( v15->m_slabSize < 128 || v17 > v15->m_end )
            m_cur = (char *)hkLifoAllocator::allocateFromNewSlab(v15, 128);
          else
            v15->m_cur = v17;
          hkCurrentFunctionUtil::getClassName(m_typeName, m_cur);
          v14 = hkTrackerTypeTreeCache::newText(m_pntr, m_cur);
          v18 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          if ( v18->m_slabSize < 128 || m_cur + 128 != v18->m_cur || v18->m_firstNonLifoEnd == m_cur )
            hkLifoAllocator::slowBlockFree(v18, m_cur, 128);
          else
            v18->m_cur = m_cur;
        }
        v13 = hkTrackerTypeTreeParser::parseType(v14, m_pntr);
        hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(&v48, v14, (unsigned __int64)v13);
      }
      hkTrackerLayoutCalculator::setTypeSize(layoutCalc, v13, v11->m_size);
      hkTrackerScanSnapshot::addBlock(this->m_scanSnapshot, v13, (unsigned __int64)v11->m_ptr, v11->m_size);
      ++v9;
      ++v10;
    }
    while ( v9 < snapshotIn->m_classAllocations.m_size );
  }
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(&v48);
  v19 = this;
  m_scanSnapshot = this->m_scanSnapshot;
  v48.m_elem = 0i64;
  v48.m_numElems = 0;
  v48.m_hashMod = 0x80000000;
  array.m_data = 0i64;
  array.m_size = 0;
  array.m_capacityAndFlags = 0x80000000;
  m_numElems = 0;
  v22 = 0;
  if ( m_scanSnapshot->m_blocks.m_size > 0 )
  {
    v23 = 0i64;
    do
    {
      v24 = m_scanSnapshot->m_blocks.m_data[v23];
      v25 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v26 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v25[11] + 8i64))(v25[11], 48i64);
      if ( v26 )
      {
        m_arraySize = v24->m_arraySize;
        m_size = v24->m_size;
        m_type = v24->m_type;
        *(_QWORD *)(v26 + 8) = v24->m_start;
        *(_QWORD *)(v26 + 16) = m_size;
        *(_QWORD *)v26 = m_type;
        *(_DWORD *)(v26 + 24) = m_arraySize;
        *(_QWORD *)(v26 + 32) = 0i64;
        *(_DWORD *)(v26 + 40) = 0;
        *(_DWORD *)(v26 + 44) = 0x80000000;
      }
      else
      {
        v26 = 0i64;
      }
      v30 = array.m_size;
      if ( array.m_size == (array.m_capacityAndFlags & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, (const void **)&array.m_data, 8);
        v30 = array.m_size;
      }
      array.m_data[v30] = (char *)v26;
      ++array.m_size;
      hkTrackerLayoutCalculator::getReferences(
        layoutCalc,
        (hkTrackerLayoutBlock *)v26,
        (hkArray<hkTrackerLayoutBlock const *,hkContainerTempAllocator> *)&v48);
      ++v22;
      ++v23;
    }
    while ( v22 < m_scanSnapshot->m_blocks.m_size );
    m_numElems = v48.m_numElems;
  }
  v31 = 0;
  if ( m_numElems > 0 )
  {
    v32 = 0i64;
    do
    {
      hkTrackerScanSnapshot::addBlock(
        this->m_scanSnapshot,
        **(hkTrackerTypeTreeNode ***)((char *)&v48.m_elem->hash + v32),
        *(_QWORD *)(*(unsigned __int64 *)((char *)&v48.m_elem->hash + v32) + 8),
        *(_QWORD *)(*(unsigned __int64 *)((char *)&v48.m_elem->hash + v32) + 16));
      m_numElems = v48.m_numElems;
      ++v31;
      v32 += 8i64;
    }
    while ( v31 < v48.m_numElems );
  }
  hkArrayBase<unsigned __int64>::_append(
    &array,
    &hkContainerTempAllocator::s_alloc,
    (char *const *)v48.m_elem,
    m_numElems);
  v48.m_numElems = 0;
  if ( v48.m_hashMod >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v48.m_elem, 8 * v48.m_hashMod);
  v33 = this->m_scanSnapshot;
  m_hashMod = 0x80000000;
  v48.m_elem = 0i64;
  p_m_references = &v33->m_references;
  v48.m_hashMod = 0x80000000;
  v36 = 0;
  v50 = 0;
  if ( array.m_size > 0 )
  {
    v37 = 0i64;
    v52 = 0i64;
    do
    {
      v38 = *(__int64 *)((char *)&v37->vfptr + (unsigned __int64)array.m_data);
      v39 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
              &v19->m_scanSnapshot->m_blockMap.m_map,
              *(_QWORD *)(v38 + 8),
              0i64);
      v40 = 0;
      *(_DWORD *)(v39 + 28) = p_m_references->m_size;
      v41 = v39;
      if ( *(int *)(v38 + 40) > 0 )
      {
        v42 = 0i64;
        do
        {
          v43 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                  &v19->m_scanSnapshot->m_blockMap.m_map,
                  *(_QWORD *)(v42 + *(_QWORD *)(v38 + 32)),
                  0i64);
          if ( v43 )
          {
            if ( p_m_references->m_size == (p_m_references->m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_references->m_data, 8);
            p_m_references->m_data[p_m_references->m_size++] = (hkTrackerScanSnapshot::Block *)v43;
          }
          ++v40;
          v42 += 8i64;
        }
        while ( v40 < *(_DWORD *)(v38 + 40) );
        v37 = v52;
        v36 = v50;
      }
      *(_DWORD *)(v41 + 32) = p_m_references->m_size - *(_DWORD *)(v41 + 28);
      v44 = *(_DWORD *)(v38 + 44);
      *(_DWORD *)(v38 + 40) = 0;
      if ( v44 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          *(void **)(v38 + 32),
          8 * v44);
      *(_QWORD *)(v38 + 32) = 0i64;
      *(_DWORD *)(v38 + 44) = 0x80000000;
      v45 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, __int64, __int64))(*v45[11] + 16i64))(v45[11], v38, 48i64);
      ++v36;
      v37 = (hkTrackerLayoutCalculator *)((char *)v37 + 8);
      v50 = v36;
      v52 = v37;
    }
    while ( v36 < array.m_size );
    m_hashMod = v48.m_hashMod;
  }
  array.m_size = 0;
  if ( array.m_capacityAndFlags >= 0 )
  {
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      array.m_data,
      8 * array.m_capacityAndFlags);
    m_hashMod = v48.m_hashMod;
  }
  array.m_data = 0i64;
  array.m_capacityAndFlags = 0x80000000;
  v48.m_numElems = 0;
  if ( m_hashMod >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v48.m_elem, 8 * m_hashMod);
  return v19->m_scanSnapshot;
}

