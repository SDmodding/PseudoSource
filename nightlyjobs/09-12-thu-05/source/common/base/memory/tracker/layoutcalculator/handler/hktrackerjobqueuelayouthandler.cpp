// File Line: 18
// RVA: 0x1307E70
void __fastcall hkTrackerJobQueueLayoutHandler::getReferences(hkTrackerJobQueueLayoutHandler *this, hkTrackerLayoutBlock *curBlock, const void *curData, hkTrackerTypeTreeNode *curType, hkTrackerLayoutCalculator *layoutCalc, hkArray<hkTrackerLayoutBlock const *,hkContainerTempAllocator> *newBlocks)
{
  hkTrackerLayoutCalculator *v6; // r15
  char *v7; // r13
  hkTrackerTypeTreeCache *v8; // rbx
  hkTrackerLayoutCalculator *v9; // rcx
  int v10; // edi
  hkTrackerTypeLayout *v11; // rbp
  __int64 v12; // r14
  hkTrackerTypeTreeNode *v13; // rax
  hkTrackerTypeTreeNode *v14; // rbx
  hkTrackerTypeLayout::Member *v15; // rsi
  hkTrackerTypeTreeNode *v16; // rcx
  hkTrackerLayoutBlock *block; // [rsp+68h] [rbp+10h]
  hkTrackerTypeTreeCache *layoutCalca; // [rsp+80h] [rbp+28h]

  block = curBlock;
  v6 = layoutCalc;
  v7 = (char *)curData;
  v8 = layoutCalc->m_typeCache.m_pntr;
  v9 = layoutCalc;
  layoutCalca = layoutCalc->m_typeCache.m_pntr;
  v10 = 0;
  v11 = hkTrackerLayoutCalculator::getLayout(v9, curType);
  if ( v11->m_members.m_size > 0 )
  {
    v12 = 0i64;
    do
    {
      hkTrackerTypeTreeCache::newNode(v8, TYPE_ARRAY_REAL);
      v14 = v13;
      v15 = &v11->m_members.m_data[v12];
      v16 = v15->m_type;
      v13->m_type = v15->m_type->m_type;
      v13->m_name.m_start = v16->m_name.m_start;
      v13->m_name.m_end = v16->m_name.m_end;
      v13->m_dimension = v16->m_dimension;
      v13->m_contains = v16->m_contains;
      v13->m_next = v16->m_next;
      if ( (unsigned int)hkString::strCmp(v15->m_name, "m_queueSemaphores") )
      {
        if ( !(unsigned int)hkString::strCmp(v15->m_name, "m_jobFuncs") )
          v14->m_dimension = 20;
      }
      else
      {
        v14->m_dimension = 5;
      }
      hkTrackerLayoutCalculator::getReferencesRecursive(v6, block, &v7[v15->m_offset], v14, newBlocks);
      v8 = layoutCalca;
      ++v10;
      ++v12;
    }
    while ( v10 < v11->m_members.m_size );
  }
}

// File Line: 53
// RVA: 0x1307FB0
unsigned __int64 __fastcall hkTrackerJobQueueLayoutHandler::getSize(hkTrackerJobQueueLayoutHandler *this, hkTrackerTypeTreeNode *__formal, hkTrackerLayoutCalculator *a3)
{
  return 1024i64;
}

// File Line: 63
// RVA: 0x1307FC0
void __fastcall hkTrackerJobQueueDynamicDataLayoutHandler::getReferences(hkTrackerJobQueueDynamicDataLayoutHandler *this, hkTrackerLayoutBlock *curBlock, const void *curData, hkTrackerTypeTreeNode *curType, hkTrackerLayoutCalculator *layoutCalc, hkArray<hkTrackerLayoutBlock const *,hkContainerTempAllocator> *newBlocks)
{
  hkTrackerLayoutCalculator *v6; // r15
  char *v7; // r13
  hkTrackerTypeTreeCache *v8; // rbx
  hkTrackerLayoutCalculator *v9; // rcx
  int v10; // edi
  hkTrackerTypeLayout *v11; // rbp
  __int64 v12; // rsi
  hkTrackerTypeLayout::Member *v13; // r14
  hkTrackerTypeTreeNode *v14; // rcx
  hkTrackerTypeTreeNode *v15; // rax
  hkTrackerTypeTreeNode *v16; // rbx
  hkTrackerLayoutBlock *block; // [rsp+68h] [rbp+10h]
  hkTrackerTypeTreeCache *layoutCalca; // [rsp+80h] [rbp+28h]

  block = curBlock;
  v6 = layoutCalc;
  v7 = (char *)curData;
  v8 = layoutCalc->m_typeCache.m_pntr;
  v9 = layoutCalc;
  layoutCalca = layoutCalc->m_typeCache.m_pntr;
  v10 = 0;
  v11 = hkTrackerLayoutCalculator::getLayout(v9, curType);
  if ( v11->m_members.m_size > 0 )
  {
    v12 = 0i64;
    do
    {
      hkTrackerTypeTreeCache::newNode(v8, TYPE_ARRAY_REAL);
      v13 = v11->m_members.m_data;
      v14 = v13[v12].m_type;
      v16 = v15;
      v15->m_type = v14->m_type;
      v15->m_name.m_start = v14->m_name.m_start;
      v15->m_name.m_end = v14->m_name.m_end;
      v15->m_dimension = v14->m_dimension;
      v15->m_contains = v14->m_contains;
      v15->m_next = v14->m_next;
      if ( !(unsigned int)hkString::strCmp(v13[v12].m_name, "m_jobQueue") )
        v16->m_dimension = 25;
      hkTrackerLayoutCalculator::getReferencesRecursive(v6, block, &v7[v13[v12].m_offset], v16, newBlocks);
      v8 = layoutCalca;
      ++v10;
      ++v12;
    }
    while ( v10 < v11->m_members.m_size );
  }
}

// File Line: 93
// RVA: 0x13080E0
unsigned __int64 __fastcall hkTrackerJobQueueDynamicDataLayoutHandler::getSize(hkTrackerJobQueueDynamicDataLayoutHandler *this, hkTrackerTypeTreeNode *__formal, hkTrackerLayoutCalculator *a3)
{
  return 672i64;
}

