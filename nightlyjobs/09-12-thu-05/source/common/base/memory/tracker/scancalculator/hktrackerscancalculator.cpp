// File Line: 16
// RVA: 0x1305DA0
hkTrackerScanSnapshot *__fastcall hkTrackerScanCalculator::createSnapshot(hkTrackerScanCalculator *this, hkTrackerSnapshot *snapshot, hkTrackerLayoutCalculator *layoutCalc)
{
  hkTrackerScanCalculator *v3; // rsi
  hkTrackerLayoutCalculator *v4; // rbx
  hkTrackerSnapshot *v5; // rdi
  hkTrackerScanSnapshot *result; // rax
  hkTrackerScanSnapshot *v7; // rbx

  v3 = this;
  v4 = layoutCalc;
  v5 = snapshot;
  hkTrackerTypeInit::registerTypes(hkMemoryTracker::s_singleton);
  result = hkTrackerScanCalculator::_createSnapshot(v3, v5, v4);
  v7 = result;
  if ( hkMemoryTracker::s_singleton )
  {
    ((void (*)(void))hkMemoryTracker::s_singleton->vfptr->clearTypeDefinitions)();
    result = v7;
  }
  return result;
}

// File Line: 29
// RVA: 0x1305E00
hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *__fastcall hkTrackerScanCalculator::_createSnapshot(hkTrackerScanCalculator *this, hkTrackerSnapshot *snapshotIn, hkTrackerLayoutCalculator *layoutCalc)
{
  hkTrackerScanCalculator *v3; // rdi
  hkTrackerLayoutCalculator *v4; // rbx
  hkTrackerSnapshot *v5; // r13
  _QWORD **v6; // rax
  hkTrackerScanSnapshot *v7; // rax
  hkTrackerTypeTreeCache *v8; // r14
  int v9; // er12
  __int64 v10; // r15
  hkDefaultMemoryTracker::ClassAlloc *v11; // rsi
  const char *v12; // rdi
  hkTrackerTypeTreeNode *v13; // rbx
  char *v14; // rdi
  hkLifoAllocator *v15; // rax
  char *v16; // rbx
  unsigned __int64 v17; // rcx
  hkLifoAllocator *v18; // rax
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > **v19; // r12
  hkTrackerScanSnapshot *v20; // rsi
  int v21; // er9
  int v22; // er15
  __int64 v23; // r14
  hkTrackerScanSnapshot::Block *v24; // rdi
  _QWORD **v25; // rax
  hkTrackerLayoutBlock *v26; // rbx
  int v27; // er8
  unsigned __int64 v28; // rdx
  hkTrackerTypeTreeNode *v29; // rax
  int v30; // ecx
  int v31; // edi
  __int64 v32; // rbx
  hkTrackerScanSnapshot *v33; // rbx
  int v34; // er8
  hkArray<hkTrackerScanSnapshot::Block *,hkContainerHeapAllocator> *v35; // rbx
  int v36; // er15
  hkTrackerLayoutCalculator *v37; // r14
  __int64 v38; // rsi
  unsigned __int64 v39; // rax
  int v40; // edi
  unsigned __int64 v41; // r13
  __int64 v42; // r14
  unsigned __int64 v43; // r15
  int v44; // er8
  _QWORD **v45; // rax
  _QWORD *array; // [rsp+20h] [rbp-30h]
  int v48; // [rsp+28h] [rbp-28h]
  int v49; // [rsp+2Ch] [rbp-24h]
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> v50; // [rsp+30h] [rbp-20h]
  hkTrackerScanCalculator *v51; // [rsp+90h] [rbp+40h]
  int v52; // [rsp+90h] [rbp+40h]
  hkTrackerLayoutCalculator *v53; // [rsp+A0h] [rbp+50h]
  hkTrackerLayoutCalculator *v54; // [rsp+A0h] [rbp+50h]

  v53 = layoutCalc;
  v51 = this;
  v3 = this;
  v4 = layoutCalc;
  v5 = snapshotIn;
  v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (hkTrackerScanSnapshot *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v6[11] + 8i64))(v6[11], 344i64);
  if ( v7 )
    hkTrackerScanSnapshot::hkTrackerScanSnapshot(v7, v5, v4);
  v3->m_scanSnapshot = v7;
  v8 = v4->m_typeCache.m_pntr;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &v50,
    0);
  v9 = 0;
  if ( v5->m_classAllocations.m_size > 0 )
  {
    v10 = 0i64;
    do
    {
      v11 = &v5->m_classAllocations.m_data[v10];
      v12 = v11->m_typeName;
      v13 = (hkTrackerTypeTreeNode *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                                       (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v50,
                                       (unsigned __int64)v11->m_typeName,
                                       0i64);
      if ( !v13 )
      {
        if ( *v12 == 33 )
        {
          v14 = hkTrackerTypeTreeCache::newText(v8, v12 + 1);
        }
        else
        {
          v15 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v16 = (char *)v15->m_cur;
          v17 = (unsigned __int64)(v16 + 128);
          if ( v15->m_slabSize < 128 || (void *)v17 > v15->m_end )
            v16 = (char *)hkLifoAllocator::allocateFromNewSlab(v15, 128);
          else
            v15->m_cur = (void *)v17;
          hkCurrentFunctionUtil::getClassName(v12, v16);
          v14 = hkTrackerTypeTreeCache::newText(v8, v16);
          v18 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          if ( v18->m_slabSize < 128 || v16 + 128 != v18->m_cur || v18->m_firstNonLifoEnd == v16 )
            hkLifoAllocator::slowBlockFree(v18, v16, 128);
          else
            v18->m_cur = v16;
        }
        v13 = hkTrackerTypeTreeParser::parseType(v14, v8);
        hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
          &v50,
          (unsigned __int64)v14,
          (unsigned __int64)v13);
      }
      hkTrackerLayoutCalculator::setTypeSize(v53, v13, v11->m_size);
      hkTrackerScanSnapshot::addBlock(v51->m_scanSnapshot, v13, v11->m_ptr, v11->m_size);
      ++v9;
      ++v10;
    }
    while ( v9 < v5->m_classAllocations.m_size );
  }
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(&v50);
  v19 = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > **)v51;
  v20 = v51->m_scanSnapshot;
  v50.m_elem = 0i64;
  v50.m_numElems = 0;
  v50.m_hashMod = 2147483648;
  array = 0i64;
  v48 = 0;
  v49 = 2147483648;
  v21 = 0;
  v22 = 0;
  if ( v20->m_blocks.m_size > 0 )
  {
    v23 = 0i64;
    do
    {
      v24 = v20->m_blocks.m_data[v23];
      v25 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v26 = (hkTrackerLayoutBlock *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v25[11] + 8i64))(
                                      v25[11],
                                      48i64);
      if ( v26 )
      {
        v27 = v24->m_arraySize;
        v28 = v24->m_size;
        v29 = v24->m_type;
        v26->m_start = v24->m_start;
        v26->m_size = v28;
        v26->m_type = v29;
        v26->m_arraySize = v27;
        v26->m_references.m_data = 0i64;
        v26->m_references.m_size = 0;
        v26->m_references.m_capacityAndFlags = 2147483648;
      }
      else
      {
        v26 = 0i64;
      }
      v30 = v48;
      if ( v48 == (v49 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, 8);
        v30 = v48;
      }
      array[v30] = v26;
      ++v48;
      hkTrackerLayoutCalculator::getReferences(
        v53,
        v26,
        (hkArray<hkTrackerLayoutBlock const *,hkContainerTempAllocator> *)&v50);
      ++v22;
      ++v23;
    }
    while ( v22 < v20->m_blocks.m_size );
    v21 = v50.m_numElems;
  }
  v31 = 0;
  if ( v21 > 0 )
  {
    v32 = 0i64;
    do
    {
      hkTrackerScanSnapshot::addBlock(
        v51->m_scanSnapshot,
        **(hkTrackerTypeTreeNode ***)((char *)&v50.m_elem->hash + v32),
        *(const void **)(*(unsigned __int64 *)((char *)&v50.m_elem->hash + v32) + 8),
        *(_QWORD *)(*(unsigned __int64 *)((char *)&v50.m_elem->hash + v32) + 16));
      v21 = v50.m_numElems;
      ++v31;
      v32 += 8i64;
    }
    while ( v31 < v50.m_numElems );
  }
  hkArrayBase<unsigned __int64>::_append(
    (hkArrayBase<char *> *)&array,
    (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
    (char *const *)v50.m_elem,
    v21);
  v50.m_numElems = 0;
  if ( v50.m_hashMod >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v50.m_elem,
      8 * v50.m_hashMod);
  v33 = v51->m_scanSnapshot;
  v34 = 2147483648;
  v50.m_elem = 0i64;
  v35 = &v33->m_references;
  v50.m_hashMod = 2147483648;
  v36 = 0;
  v52 = 0;
  if ( v48 > 0 )
  {
    v37 = 0i64;
    v54 = 0i64;
    do
    {
      v38 = *(_QWORD *)((char *)array + (_QWORD)v37);
      v39 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
              *v19 + 2,
              *(_QWORD *)(v38 + 8),
              0i64);
      v40 = 0;
      *(_DWORD *)(v39 + 28) = v35->m_size;
      v41 = v39;
      if ( *(_DWORD *)(v38 + 40) > 0 )
      {
        v42 = 0i64;
        do
        {
          v43 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                  *v19 + 2,
                  *(_QWORD *)(v42 + *(_QWORD *)(v38 + 32)),
                  0i64);
          if ( v43 )
          {
            if ( v35->m_size == (v35->m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v35, 8);
            v35->m_data[v35->m_size++] = (hkTrackerScanSnapshot::Block *)v43;
          }
          ++v40;
          v42 += 8i64;
        }
        while ( v40 < *(_DWORD *)(v38 + 40) );
        v37 = v54;
        v36 = v52;
      }
      *(_DWORD *)(v41 + 32) = v35->m_size - *(_DWORD *)(v41 + 28);
      v44 = *(_DWORD *)(v38 + 44);
      *(_DWORD *)(v38 + 40) = 0;
      if ( v44 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          *(void **)(v38 + 32),
          8 * v44);
      *(_QWORD *)(v38 + 32) = 0i64;
      *(_DWORD *)(v38 + 44) = 2147483648;
      v45 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, __int64, signed __int64))(*v45[11] + 16i64))(v45[11], v38, 48i64);
      ++v36;
      v37 = (hkTrackerLayoutCalculator *)((char *)v37 + 8);
      v52 = v36;
      v54 = v37;
    }
    while ( v36 < v48 );
    v34 = v50.m_hashMod;
  }
  v48 = 0;
  if ( v49 >= 0 )
  {
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      8 * v49);
    v34 = v50.m_hashMod;
  }
  array = 0i64;
  v49 = 2147483648;
  v50.m_numElems = 0;
  if ( v34 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v50.m_elem,
      8 * v34);
  return *v19;
}

