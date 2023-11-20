// File Line: 17
// RVA: 0x1306F90
void __fastcall hkTrackerArrayLayoutHandler::getReferences(hkTrackerArrayLayoutHandler *this, hkTrackerLayoutBlock *curBlock, const void *curData, hkTrackerTypeTreeNode *curType, hkTrackerLayoutCalculator *layoutCalc, hkArray<hkTrackerLayoutBlock const *,hkContainerTempAllocator> *newBlocks)
{
  hkTrackerLayoutCalculator *v6; // r13
  hkTrackerLayoutBlock *v7; // rbp
  hkTrackerTypeTreeNode *v8; // rsi
  _DWORD *v9; // r14
  hkTrackerLayoutBlock *v10; // rbx
  unsigned __int64 v11; // r15
  hkBool *v12; // rax
  hkArray<hkTrackerLayoutBlock const *,hkContainerTempAllocator> *v13; // rdi
  char *v14; // rsi
  unsigned int v15; // er12
  unsigned __int64 v16; // r14
  const char *v17; // r8
  hkBool *v18; // rax
  hkTrackerTypeTreeNode *v19; // rbp
  _QWORD **v20; // rax
  __int64 v21; // rax
  __int64 v22; // rbp
  hkTrackerTypeTreeNode *curTypea; // [rsp+30h] [rbp-38h]
  hkTrackerTypeTreeCache *v24; // [rsp+88h] [rbp+20h]

  v6 = layoutCalc;
  v7 = curBlock;
  v8 = curType;
  v9 = curData;
  v24 = layoutCalc->m_typeCache.m_pntr;
  curTypea = curType->m_contains;
  v10 = 0i64;
  v11 = hkTrackerLayoutCalculator::calcTypeSize(layoutCalc, curType->m_contains);
  v12 = hkSubString::operator==(&v8->m_name, (hkBool *)&layoutCalc, "hkInplaceArray");
  v13 = newBlocks;
  if ( v12->m_bool )
  {
    v14 = *(char **)v9;
    v15 = v9[2];
    if ( (v9[3] & 0x3FFFFFFF) <= 0 )
      goto LABEL_23;
    v10 = v7;
    if ( v14 == (char *)(v9 + 4) )
      goto LABEL_23;
    v16 = v11 * (v9[3] & 0x3FFFFFFF);
    if ( v7->m_references.m_size == (v7->m_references.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v7->m_references, 8);
    v17 = "buffer_hkInplaceArray";
    v7->m_references.m_data[v7->m_references.m_size] = v14;
  }
  else
  {
    v18 = hkSubString::operator==(&v8->m_name, (hkBool *)&layoutCalc, "hkSmallArray");
    v14 = *(char **)v9;
    if ( v18->m_bool )
    {
      v15 = *((unsigned __int16 *)v9 + 4);
      if ( (*((_WORD *)v9 + 5) & 0x3FFF) <= 0 )
        goto LABEL_23;
      v16 = v11 * (*((_WORD *)v9 + 5) & 0x3FFF);
      if ( v7->m_references.m_size == (v7->m_references.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v7->m_references, 8);
      v17 = "buffer_hkSmallArray";
    }
    else
    {
      v15 = v9[2];
      if ( (v9[3] & 0x3FFFFFFF) <= 0 )
        goto LABEL_23;
      v16 = v11 * (v9[3] & 0x3FFFFFFF);
      if ( v7->m_references.m_size == (v7->m_references.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v7->m_references, 8);
      v17 = "buffer_hkArray";
    }
    v7->m_references.m_data[v7->m_references.m_size] = v14;
  }
  ++v7->m_references.m_size;
  v19 = hkTrackerTypeTreeCache::newNamedNode(v24, TYPE_ARRAY, v17, 0);
  v20 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v21 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v20[11] + 8i64))(v20[11], 48i64);
  v10 = (hkTrackerLayoutBlock *)v21;
  if ( v21 )
  {
    *(_QWORD *)v21 = v19;
    *(_QWORD *)(v21 + 8) = v14;
    *(_QWORD *)(v21 + 16) = v16;
    *(_DWORD *)(v21 + 24) = -1;
    *(_QWORD *)(v21 + 32) = 0i64;
    *(_DWORD *)(v21 + 40) = 0;
    *(_DWORD *)(v21 + 44) = 2147483648;
  }
  else
  {
    v10 = 0i64;
  }
  if ( v13->m_size == (v13->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v13, 8);
  v13->m_data[v13->m_size++] = v10;
LABEL_23:
  if ( (signed int)v15 > 0 )
  {
    v22 = v15;
    do
    {
      hkTrackerLayoutCalculator::getReferencesRecursive(v6, v10, v14, curTypea, v13);
      v14 += v11;
      --v22;
    }
    while ( v22 );
  }
}

// File Line: 100
// RVA: 0x1307220
unsigned __int64 __fastcall hkTrackerArrayLayoutHandler::getSize(hkTrackerArrayLayoutHandler *this, hkTrackerTypeTreeNode *curType, hkTrackerLayoutCalculator *layoutCalc)
{
  hkTrackerTypeTreeNode *v3; // rdi
  hkTrackerLayoutCalculator *v4; // rsi
  hkBool result; // [rsp+38h] [rbp+10h]

  v3 = curType;
  v4 = layoutCalc;
  if ( hkSubString::operator==(&curType->m_name, &result, "hkInplaceArray")->m_bool )
    return v3->m_contains->m_next->m_dimension * hkTrackerLayoutCalculator::calcTypeSize(v4, v3->m_contains) + 16;
  hkSubString::operator==(&v3->m_name, &result, "hkSmallArray");
  return 16i64;
}

