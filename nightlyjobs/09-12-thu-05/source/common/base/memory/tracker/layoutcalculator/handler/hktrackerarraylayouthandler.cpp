// File Line: 17
// RVA: 0x1306F90
void __fastcall hkTrackerArrayLayoutHandler::getReferences(
        hkTrackerArrayLayoutHandler *this,
        hkTrackerLayoutBlock *curBlock,
        _DWORD *curData,
        hkTrackerTypeTreeNode *curType,
        hkTrackerLayoutCalculator *layoutCalc,
        hkArrayBase<char *> *newBlocks)
{
  hkTrackerLayoutCalculator *v6; // r13
  hkTrackerLayoutBlock *v10; // rbx
  unsigned __int64 v11; // r15
  hkBool *v12; // rax
  hkArrayBase<char *> *v13; // rdi
  char *v14; // rsi
  int v15; // r12d
  unsigned __int64 v16; // r14
  const char *v17; // r8
  hkBool *v18; // rax
  hkTrackerTypeTreeNode *v19; // rbp
  _QWORD **Value; // rax
  __int64 v21; // rax
  __int64 v22; // rbp
  hkTrackerTypeTreeNode *curTypea; // [rsp+30h] [rbp-38h]
  hkTrackerTypeTreeCache *m_pntr; // [rsp+88h] [rbp+20h]

  v6 = layoutCalc;
  m_pntr = layoutCalc->m_typeCache.m_pntr;
  curTypea = curType->m_contains;
  v10 = 0i64;
  v11 = hkTrackerLayoutCalculator::calcTypeSize(layoutCalc, curTypea);
  v12 = hkSubString::operator==(&curType->m_name, (hkBool *)&layoutCalc, "hkInplaceArray");
  v13 = newBlocks;
  if ( v12->m_bool )
  {
    v14 = *(char **)curData;
    v15 = curData[2];
    if ( (curData[3] & 0x3FFFFFFF) == 0 )
      goto LABEL_23;
    v10 = curBlock;
    if ( v14 == (char *)(curData + 4) )
      goto LABEL_23;
    v16 = v11 * (curData[3] & 0x3FFFFFFF);
    if ( curBlock->m_references.m_size == (curBlock->m_references.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&curBlock->m_references.m_data, 8);
    v17 = "buffer_hkInplaceArray";
    curBlock->m_references.m_data[curBlock->m_references.m_size] = v14;
  }
  else
  {
    v18 = hkSubString::operator==(&curType->m_name, (hkBool *)&layoutCalc, "hkSmallArray");
    v14 = *(char **)curData;
    if ( v18->m_bool )
    {
      v15 = *((unsigned __int16 *)curData + 4);
      if ( (*((_WORD *)curData + 5) & 0x3FFF) == 0 )
        goto LABEL_23;
      v16 = v11 * (*((_WORD *)curData + 5) & 0x3FFF);
      if ( curBlock->m_references.m_size == (curBlock->m_references.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&curBlock->m_references.m_data, 8);
      v17 = "buffer_hkSmallArray";
    }
    else
    {
      v15 = curData[2];
      if ( (curData[3] & 0x3FFFFFFF) == 0 )
        goto LABEL_23;
      v16 = v11 * (curData[3] & 0x3FFFFFFF);
      if ( curBlock->m_references.m_size == (curBlock->m_references.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&curBlock->m_references.m_data, 8);
      v17 = "buffer_hkArray";
    }
    curBlock->m_references.m_data[curBlock->m_references.m_size] = v14;
  }
  ++curBlock->m_references.m_size;
  v19 = hkTrackerTypeTreeCache::newNamedNode(m_pntr, TYPE_ARRAY, v17, 0);
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v21 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 48i64);
  v10 = (hkTrackerLayoutBlock *)v21;
  if ( v21 )
  {
    *(_QWORD *)v21 = v19;
    *(_QWORD *)(v21 + 8) = v14;
    *(_QWORD *)(v21 + 16) = v16;
    *(_DWORD *)(v21 + 24) = -1;
    *(_QWORD *)(v21 + 32) = 0i64;
    *(_DWORD *)(v21 + 40) = 0;
    *(_DWORD *)(v21 + 44) = 0x80000000;
  }
  else
  {
    v10 = 0i64;
  }
  if ( v13->m_size == (v13->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, (const void **)&v13->m_data, 8);
  v13->m_data[v13->m_size++] = (char *)v10;
LABEL_23:
  if ( v15 > 0 )
  {
    v22 = (unsigned int)v15;
    do
    {
      hkTrackerLayoutCalculator::getReferencesRecursive(v6, v10, (const void **)v14, curTypea, v13);
      v14 += v11;
      --v22;
    }
    while ( v22 );
  }
}

// File Line: 100
// RVA: 0x1307220
unsigned __int64 __fastcall hkTrackerArrayLayoutHandler::getSize(
        hkTrackerArrayLayoutHandler *this,
        hkTrackerTypeTreeNode *curType,
        hkTrackerLayoutCalculator *layoutCalc)
{
  hkBool result; // [rsp+38h] [rbp+10h] BYREF

  if ( hkSubString::operator==(&curType->m_name, &result, "hkInplaceArray")->m_bool )
    return curType->m_contains->m_next->m_dimension
         * hkTrackerLayoutCalculator::calcTypeSize(layoutCalc, curType->m_contains)
         + 16;
  hkSubString::operator==(&curType->m_name, &result, "hkSmallArray");
  return 16i64;
}

