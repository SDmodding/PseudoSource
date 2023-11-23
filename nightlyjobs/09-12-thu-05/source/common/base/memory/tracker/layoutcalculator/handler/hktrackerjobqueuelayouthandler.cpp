// File Line: 18
// RVA: 0x1307E70
void __fastcall hkTrackerJobQueueLayoutHandler::getReferences(
        hkTrackerJobQueueLayoutHandler *this,
        hkTrackerLayoutBlock *curBlock,
        char *curData,
        hkTrackerTypeTreeNode *curType,
        hkTrackerLayoutCalculator *layoutCalc,
        hkArrayBase<char *> *newBlocks)
{
  hkTrackerTypeTreeCache *m_pntr; // rbx
  int v10; // edi
  hkTrackerTypeLayout *Layout; // rbp
  __int64 v12; // r14
  hkTrackerTypeTreeNode *v13; // rax
  hkTrackerTypeTreeNode *v14; // rbx
  hkTrackerTypeLayout::Member *v15; // rsi
  hkTrackerTypeTreeNode *m_type; // rcx
  hkTrackerLayoutCalculator *layoutCalca; // [rsp+80h] [rbp+28h]

  m_pntr = layoutCalc->m_typeCache.m_pntr;
  layoutCalca = (hkTrackerLayoutCalculator *)m_pntr;
  v10 = 0;
  Layout = hkTrackerLayoutCalculator::getLayout(layoutCalc, curType);
  if ( Layout->m_members.m_size > 0 )
  {
    v12 = 0i64;
    do
    {
      hkTrackerTypeTreeCache::newNode(m_pntr, TYPE_ARRAY_REAL);
      v14 = v13;
      v15 = &Layout->m_members.m_data[v12];
      m_type = v15->m_type;
      v13->m_type = v15->m_type->m_type;
      v13->m_name.m_start = m_type->m_name.m_start;
      v13->m_name.m_end = m_type->m_name.m_end;
      v13->m_dimension = m_type->m_dimension;
      v13->m_contains = m_type->m_contains;
      v13->m_next = m_type->m_next;
      if ( (unsigned int)hkString::strCmp(v15->m_name, "m_queueSemaphores") )
      {
        if ( !(unsigned int)hkString::strCmp(v15->m_name, "m_jobFuncs") )
          v14->m_dimension = 20;
      }
      else
      {
        v14->m_dimension = 5;
      }
      hkTrackerLayoutCalculator::getReferencesRecursive(
        layoutCalc,
        curBlock,
        (const void **)&curData[v15->m_offset],
        v14,
        newBlocks);
      m_pntr = (hkTrackerTypeTreeCache *)layoutCalca;
      ++v10;
      ++v12;
    }
    while ( v10 < Layout->m_members.m_size );
  }
}

// File Line: 53
// RVA: 0x1307FB0
unsigned __int64 __fastcall hkTrackerJobQueueLayoutHandler::getSize(
        hkTrackerJobQueueLayoutHandler *this,
        hkTrackerTypeTreeNode *__formal,
        hkTrackerLayoutCalculator *a3)
{
  return 1024i64;
}

// File Line: 63
// RVA: 0x1307FC0
void __fastcall hkTrackerJobQueueDynamicDataLayoutHandler::getReferences(
        hkTrackerJobQueueDynamicDataLayoutHandler *this,
        hkTrackerLayoutBlock *curBlock,
        char *curData,
        hkTrackerTypeTreeNode *curType,
        hkTrackerLayoutCalculator *layoutCalc,
        hkArrayBase<char *> *newBlocks)
{
  hkTrackerTypeTreeCache *m_pntr; // rbx
  int v10; // edi
  hkTrackerTypeLayout *Layout; // rbp
  __int64 v12; // rsi
  hkTrackerTypeLayout::Member *m_data; // r14
  hkTrackerTypeTreeNode *m_type; // rcx
  hkTrackerTypeTreeNode *v15; // rax
  hkTrackerTypeTreeNode *v16; // rbx
  hkTrackerLayoutCalculator *layoutCalca; // [rsp+80h] [rbp+28h]

  m_pntr = layoutCalc->m_typeCache.m_pntr;
  layoutCalca = (hkTrackerLayoutCalculator *)m_pntr;
  v10 = 0;
  Layout = hkTrackerLayoutCalculator::getLayout(layoutCalc, curType);
  if ( Layout->m_members.m_size > 0 )
  {
    v12 = 0i64;
    do
    {
      hkTrackerTypeTreeCache::newNode(m_pntr, TYPE_ARRAY_REAL);
      m_data = Layout->m_members.m_data;
      m_type = m_data[v12].m_type;
      v16 = v15;
      v15->m_type = m_type->m_type;
      v15->m_name.m_start = m_type->m_name.m_start;
      v15->m_name.m_end = m_type->m_name.m_end;
      v15->m_dimension = m_type->m_dimension;
      v15->m_contains = m_type->m_contains;
      v15->m_next = m_type->m_next;
      if ( !(unsigned int)hkString::strCmp(m_data[v12].m_name, "m_jobQueue") )
        v16->m_dimension = 25;
      hkTrackerLayoutCalculator::getReferencesRecursive(
        layoutCalc,
        curBlock,
        (const void **)&curData[m_data[v12].m_offset],
        v16,
        newBlocks);
      m_pntr = (hkTrackerTypeTreeCache *)layoutCalca;
      ++v10;
      ++v12;
    }
    while ( v10 < Layout->m_members.m_size );
  }
}

// File Line: 93
// RVA: 0x13080E0
unsigned __int64 __fastcall hkTrackerJobQueueDynamicDataLayoutHandler::getSize(
        hkTrackerJobQueueDynamicDataLayoutHandler *this,
        hkTrackerTypeTreeNode *__formal,
        hkTrackerLayoutCalculator *a3)
{
  return 672i64;
}

