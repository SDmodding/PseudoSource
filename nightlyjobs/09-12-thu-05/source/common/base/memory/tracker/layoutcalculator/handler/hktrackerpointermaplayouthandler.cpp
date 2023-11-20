// File Line: 31
// RVA: 0x1307E30
unsigned __int64 __fastcall getStorageSize(unsigned __int64 typeSize)
{
  return 8i64;
}

// File Line: 41
// RVA: 0x1307980
void __fastcall hkTrackerPointerMapLayoutHandler::getReferences(hkTrackerPointerMapLayoutHandler *this, hkTrackerLayoutBlock *curBlock, const void *curData, hkTrackerTypeTreeNode *curType, hkTrackerLayoutCalculator *layoutCalc, hkArray<hkTrackerLayoutBlock const *,hkContainerTempAllocator> *newBlocks)
{
  hkTrackerTypeTreeNode *v6; // rbp
  hkTrackerLayoutCalculator *v7; // r13
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v8; // rdi
  hkTrackerTypeTreeNode *v9; // rax
  hkTrackerTypeTreeCache *v10; // r14
  hkTrackerLayoutBlock *v11; // rbx
  bool v12; // r12
  hkBool *v13; // rax
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v14; // r15
  int v15; // eax
  __int64 v16; // rsi
  hkTrackerTypeTreeNode *v17; // rbx
  _QWORD **v18; // rax
  __int64 v19; // rax
  hkTrackerLayoutBlock *v20; // r14
  signed int v21; // ebx
  hkArray<hkTrackerLayoutBlock const *,hkContainerTempAllocator> *v22; // rsi
  char v23; // r15
  __int64 v24; // r8
  __int64 v25; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v26; // rax
  signed int v27; // esi
  unsigned __int64 v28; // rbp
  unsigned __int64 v29; // rbp
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
  signed int v40; // ebx
  hkArray<hkTrackerLayoutBlock const *,hkContainerTempAllocator> *v41; // rsi
  char v42; // r15
  __int64 v43; // r8
  __int64 v44; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v45; // rax
  signed int v46; // esi
  unsigned __int64 v47; // rbp
  unsigned __int64 v48; // rbp
  __int64 v49; // r9
  int v50; // edx
  __int64 v51; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v52; // rax
  hkBool result; // [rsp+68h] [rbp+20h]

  v6 = curType->m_contains;
  v7 = layoutCalc;
  v8 = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)curData;
  v9 = v6->m_next;
  v10 = layoutCalc->m_typeCache.m_pntr;
  LOBYTE(layoutCalc) = v6->m_type == 1;
  v11 = curBlock;
  v12 = v9->m_type == 1;
  v13 = hkSubString::operator==(&curType->m_name, &result, "hkPointerMultiMap");
  v14 = v8->m_elem;
  if ( v13->m_bool )
  {
    v15 = hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::getMemSize(v8);
    v16 = v15;
    if ( v15 )
    {
      if ( v11->m_references.m_size == (v11->m_references.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v11->m_references, 8);
      v11->m_references.m_data[v11->m_references.m_size++] = v14;
      v17 = hkTrackerTypeTreeCache::newNamedNode(v10, TYPE_ARRAY, "buffer_hkPointerMultiMap", 0);
      v18 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v19 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v18[11] + 8i64))(v18[11], 48i64);
      v20 = (hkTrackerLayoutBlock *)v19;
      if ( v19 )
      {
        *(_QWORD *)v19 = v17;
        *(_QWORD *)(v19 + 8) = v14;
        *(_QWORD *)(v19 + 16) = v16;
        *(_DWORD *)(v19 + 24) = -1;
        v21 = 0;
        *(_DWORD *)(v19 + 44) = 2147483648;
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
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, newBlocks, 8);
      v23 = (char)layoutCalc;
      v22->m_data[v22->m_size++] = v20;
      if ( v23 || v12 )
      {
        hkTrackerLayoutCalculator::calcTypeSize(v7, v6);
        v24 = v8->m_hashMod;
        v25 = 0i64;
        if ( (signed int)v24 >= 0 )
        {
          v26 = v8->m_elem;
          do
          {
            if ( v26->key != -1i64 )
              break;
            ++v25;
            ++v21;
            ++v26;
          }
          while ( v25 <= v24 );
        }
        v27 = v21;
        if ( v21 <= (signed int)v24 )
        {
          do
          {
            if ( v23 )
            {
              v28 = v8->m_elem[v27].key;
              if ( v20->m_references.m_size == (v20->m_references.m_capacityAndFlags & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore(
                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                  &v20->m_references,
                  8);
              v20->m_references.m_data[v20->m_references.m_size++] = (const void *)v28;
            }
            if ( v12 )
            {
              v29 = v8->m_elem[v27].val;
              if ( v20->m_references.m_size == (v20->m_references.m_capacityAndFlags & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore(
                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                  &v20->m_references,
                  8);
              v20->m_references.m_data[v20->m_references.m_size++] = (const void *)v29;
            }
            v30 = v8->m_hashMod;
            v31 = v27 + 1;
            v32 = v27 + 1;
            if ( v32 <= v30 )
            {
              v33 = &v8->m_elem[v31];
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
          while ( v31 <= (signed int)v30 );
        }
      }
    }
  }
  else
  {
    v34 = hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::getMemSize(v8);
    v35 = v34;
    if ( v34 )
    {
      if ( v11->m_references.m_size == (v11->m_references.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v11->m_references, 8);
      v11->m_references.m_data[v11->m_references.m_size++] = v14;
      v36 = hkTrackerTypeTreeCache::newNamedNode(v10, TYPE_ARRAY, "buffer_hkPointerMap", 0);
      v37 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v38 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v37[11] + 8i64))(v37[11], 48i64);
      v39 = (hkTrackerLayoutBlock *)v38;
      if ( v38 )
      {
        *(_QWORD *)v38 = v36;
        *(_QWORD *)(v38 + 8) = v14;
        *(_QWORD *)(v38 + 16) = v35;
        *(_DWORD *)(v38 + 24) = -1;
        v40 = 0;
        *(_DWORD *)(v38 + 44) = 2147483648;
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
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, newBlocks, 8);
      v42 = (char)layoutCalc;
      v41->m_data[v41->m_size++] = v39;
      if ( v42 || v12 )
      {
        hkTrackerLayoutCalculator::calcTypeSize(v7, v6);
        v43 = v8->m_hashMod;
        v44 = 0i64;
        if ( (signed int)v43 >= 0 )
        {
          v45 = v8->m_elem;
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
        if ( v40 <= (signed int)v43 )
        {
          do
          {
            if ( v42 )
            {
              v47 = v8->m_elem[v46].key;
              if ( v39->m_references.m_size == (v39->m_references.m_capacityAndFlags & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore(
                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                  &v39->m_references,
                  8);
              v39->m_references.m_data[v39->m_references.m_size++] = (const void *)v47;
            }
            if ( v12 )
            {
              v48 = v8->m_elem[v46].val;
              if ( v39->m_references.m_size == (v39->m_references.m_capacityAndFlags & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore(
                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                  &v39->m_references,
                  8);
              v39->m_references.m_data[v39->m_references.m_size++] = (const void *)v48;
            }
            v49 = v8->m_hashMod;
            v50 = v46 + 1;
            v51 = v46 + 1;
            if ( v51 <= v49 )
            {
              v52 = &v8->m_elem[v50];
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
          while ( v50 <= (signed int)v49 );
        }
      }
    }
  }
}

// File Line: 189
// RVA: 0x1307E00
unsigned __int64 __fastcall hkTrackerPointerMapLayoutHandler::getSize(hkTrackerPointerMapLayoutHandler *this, hkTrackerTypeTreeNode *curType, hkTrackerLayoutCalculator *layoutCalc)
{
  hkBool result; // [rsp+38h] [rbp+10h]

  hkSubString::operator==(&curType->m_name, &result, "hkPointerMultiMap");
  return 16i64;
}

