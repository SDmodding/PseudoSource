// File Line: 31
// RVA: 0x1307E30
unsigned __int64 __fastcall getStorageSize(unsigned __int64 typeSize)
{
  return 8i64;
}

// File Line: 41
// RVA: 0x1307980
void __fastcall hkTrackerPointerMapLayoutHandler::getReferences(
        hkTrackerPointerMapLayoutHandler *this,
        hkTrackerLayoutBlock *curBlock,
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *curData,
        hkTrackerTypeTreeNode *curType,
        hkTrackerLayoutCalculator *layoutCalc,
        hkArray<hkTrackerLayoutBlock const *,hkContainerTempAllocator> *newBlocks)
{
  hkTrackerTypeTreeNode *m_contains; // rbp
  hkTrackerLayoutCalculator *v7; // r13
  hkTrackerTypeTreeNode *m_next; // rax
  hkTrackerTypeTreeCache *m_pntr; // r14
  bool v12; // r12
  hkBool *v13; // rax
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *m_elem; // r15
  int MemSize; // eax
  __int64 v16; // rsi
  hkTrackerTypeTreeNode *v17; // rbx
  _QWORD **Value; // rax
  __int64 v19; // rax
  hkTrackerLayoutBlock *v20; // r14
  int v21; // ebx
  hkArray<hkTrackerLayoutBlock const *,hkContainerTempAllocator> *v22; // rsi
  char v23; // r15
  __int64 m_hashMod; // r8
  __int64 v25; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v26; // rax
  int v27; // esi
  unsigned __int64 key; // rbp
  unsigned __int64 val; // rbp
  __int64 v30; // r9
  int v31; // edx
  __int64 v32; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v33; // rax
  int v34; // eax
  __int64 v35; // rsi
  hkTrackerTypeTreeNode *v36; // rbx
  _QWORD **v37; // rax
  __int64 v38; // rax
  hkTrackerLayoutBlock *v39; // r14
  int v40; // ebx
  hkArray<hkTrackerLayoutBlock const *,hkContainerTempAllocator> *v41; // rsi
  char v42; // r15
  __int64 v43; // r8
  __int64 v44; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v45; // rax
  int v46; // esi
  unsigned __int64 v47; // rbp
  unsigned __int64 v48; // rbp
  __int64 v49; // r9
  int v50; // edx
  __int64 v51; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v52; // rax
  hkBool result; // [rsp+68h] [rbp+20h] BYREF

  m_contains = curType->m_contains;
  v7 = layoutCalc;
  m_next = m_contains->m_next;
  m_pntr = layoutCalc->m_typeCache.m_pntr;
  LOBYTE(layoutCalc) = m_contains->m_type == TYPE_BYTE;
  v12 = m_next->m_type == TYPE_BYTE;
  v13 = hkSubString::operator==(&curType->m_name, &result, "hkPointerMultiMap");
  m_elem = curData->m_elem;
  if ( v13->m_bool )
  {
    MemSize = hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::getMemSize(curData);
    v16 = MemSize;
    if ( MemSize )
    {
      if ( curBlock->m_references.m_size == (curBlock->m_references.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&curBlock->m_references.m_data, 8);
      curBlock->m_references.m_data[curBlock->m_references.m_size++] = m_elem;
      v17 = hkTrackerTypeTreeCache::newNamedNode(m_pntr, TYPE_ARRAY, "buffer_hkPointerMultiMap", 0);
      Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v19 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 48i64);
      v20 = (hkTrackerLayoutBlock *)v19;
      if ( v19 )
      {
        *(_QWORD *)v19 = v17;
        *(_QWORD *)(v19 + 8) = m_elem;
        *(_QWORD *)(v19 + 16) = v16;
        *(_DWORD *)(v19 + 24) = -1;
        v21 = 0;
        *(_DWORD *)(v19 + 44) = 0x80000000;
        *(_QWORD *)(v19 + 32) = 0i64;
        *(_DWORD *)(v19 + 40) = 0;
      }
      else
      {
        v21 = 0;
        v20 = 0i64;
      }
      v22 = newBlocks;
      if ( newBlocks->m_size == (newBlocks->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, (const void **)&newBlocks->m_data, 8);
      v23 = (char)layoutCalc;
      v22->m_data[v22->m_size++] = v20;
      if ( v23 || v12 )
      {
        hkTrackerLayoutCalculator::calcTypeSize(v7, m_contains);
        m_hashMod = curData->m_hashMod;
        v25 = 0i64;
        if ( (int)m_hashMod >= 0 )
        {
          v26 = curData->m_elem;
          do
          {
            if ( v26->key != -1i64 )
              break;
            ++v25;
            ++v21;
            ++v26;
          }
          while ( v25 <= m_hashMod );
        }
        v27 = v21;
        if ( v21 <= (int)m_hashMod )
        {
          do
          {
            if ( v23 )
            {
              key = curData->m_elem[v27].key;
              if ( v20->m_references.m_size == (v20->m_references.m_capacityAndFlags & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore(
                  &hkContainerHeapAllocator::s_alloc,
                  (const void **)&v20->m_references.m_data,
                  8);
              v20->m_references.m_data[v20->m_references.m_size++] = (const void *)key;
            }
            if ( v12 )
            {
              val = curData->m_elem[v27].val;
              if ( v20->m_references.m_size == (v20->m_references.m_capacityAndFlags & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore(
                  &hkContainerHeapAllocator::s_alloc,
                  (const void **)&v20->m_references.m_data,
                  8);
              v20->m_references.m_data[v20->m_references.m_size++] = (const void *)val;
            }
            v30 = curData->m_hashMod;
            v31 = v27 + 1;
            v32 = v27 + 1;
            if ( v32 <= v30 )
            {
              v33 = &curData->m_elem[v31];
              do
              {
                if ( v33->key != -1i64 )
                  break;
                ++v32;
                ++v31;
                ++v33;
              }
              while ( v32 <= v30 );
            }
            v27 = v31;
          }
          while ( v31 <= (int)v30 );
        }
      }
    }
  }
  else
  {
    v34 = hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::getMemSize(curData);
    v35 = v34;
    if ( v34 )
    {
      if ( curBlock->m_references.m_size == (curBlock->m_references.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&curBlock->m_references.m_data, 8);
      curBlock->m_references.m_data[curBlock->m_references.m_size++] = m_elem;
      v36 = hkTrackerTypeTreeCache::newNamedNode(m_pntr, TYPE_ARRAY, "buffer_hkPointerMap", 0);
      v37 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v38 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v37[11] + 8i64))(v37[11], 48i64);
      v39 = (hkTrackerLayoutBlock *)v38;
      if ( v38 )
      {
        *(_QWORD *)v38 = v36;
        *(_QWORD *)(v38 + 8) = m_elem;
        *(_QWORD *)(v38 + 16) = v35;
        *(_DWORD *)(v38 + 24) = -1;
        v40 = 0;
        *(_DWORD *)(v38 + 44) = 0x80000000;
        *(_QWORD *)(v38 + 32) = 0i64;
        *(_DWORD *)(v38 + 40) = 0;
      }
      else
      {
        v40 = 0;
        v39 = 0i64;
      }
      v41 = newBlocks;
      if ( newBlocks->m_size == (newBlocks->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, (const void **)&newBlocks->m_data, 8);
      v42 = (char)layoutCalc;
      v41->m_data[v41->m_size++] = v39;
      if ( v42 || v12 )
      {
        hkTrackerLayoutCalculator::calcTypeSize(v7, m_contains);
        v43 = curData->m_hashMod;
        v44 = 0i64;
        if ( (int)v43 >= 0 )
        {
          v45 = curData->m_elem;
          do
          {
            if ( v45->key != -1i64 )
              break;
            ++v44;
            ++v40;
            ++v45;
          }
          while ( v44 <= v43 );
        }
        v46 = v40;
        if ( v40 <= (int)v43 )
        {
          do
          {
            if ( v42 )
            {
              v47 = curData->m_elem[v46].key;
              if ( v39->m_references.m_size == (v39->m_references.m_capacityAndFlags & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore(
                  &hkContainerHeapAllocator::s_alloc,
                  (const void **)&v39->m_references.m_data,
                  8);
              v39->m_references.m_data[v39->m_references.m_size++] = (const void *)v47;
            }
            if ( v12 )
            {
              v48 = curData->m_elem[v46].val;
              if ( v39->m_references.m_size == (v39->m_references.m_capacityAndFlags & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore(
                  &hkContainerHeapAllocator::s_alloc,
                  (const void **)&v39->m_references.m_data,
                  8);
              v39->m_references.m_data[v39->m_references.m_size++] = (const void *)v48;
            }
            v49 = curData->m_hashMod;
            v50 = v46 + 1;
            v51 = v46 + 1;
            if ( v51 <= v49 )
            {
              v52 = &curData->m_elem[v50];
              do
              {
                if ( v52->key != -1i64 )
                  break;
                ++v51;
                ++v50;
                ++v52;
              }
              while ( v51 <= v49 );
            }
            v46 = v50;
          }
          while ( v50 <= (int)v49 );
        }
      }
    }
  }
}

// File Line: 189
// RVA: 0x1307E00
unsigned __int64 __fastcall hkTrackerPointerMapLayoutHandler::getSize(
        hkTrackerPointerMapLayoutHandler *this,
        hkTrackerTypeTreeNode *curType,
        hkTrackerLayoutCalculator *layoutCalc)
{
  hkBool result; // [rsp+38h] [rbp+10h] BYREF

  hkSubString::operator==(&curType->m_name, &result, "hkPointerMultiMap");
  return 16i64;
}

