// File Line: 18
// RVA: 0x13080F0
void __fastcall hkTrackerSetLayoutHandler::getReferences(hkTrackerSetLayoutHandler *this, hkTrackerLayoutBlock *curBlock, const void *curData, hkTrackerTypeTreeNode *curType, hkTrackerLayoutCalculator *layoutCalc, hkArray<hkTrackerLayoutBlock const *,hkContainerTempAllocator> *newBlocks)
{
  hkTrackerTypeTreeNode *v6; // rbx
  hkTrackerLayoutBlock *v7; // r15
  hkTrackerTypeTreeCache *v8; // rdi
  const void *v9; // r14
  hkTrackerTypeTreeNode *v10; // rax
  hkTrackerTypeTreeNode *v11; // rsi
  char *v12; // rax

  v6 = curType->m_contains;
  v7 = curBlock;
  v8 = layoutCalc->m_typeCache.m_pntr;
  v9 = curData;
  hkTrackerTypeTreeCache::newNode(layoutCalc->m_typeCache.m_pntr, TYPE_REAL);
  v10->m_contains = v6;
  v11 = v10;
  v12 = hkTrackerTypeTreeCache::newText(v8, "hkArray");
  hkSubString::operator=(&v11->m_name, v12);
  hkTrackerLayoutCalculator::getReferencesRecursive(layoutCalc, v7, v9, v11, newBlocks);
}

// File Line: 37
// RVA: 0x1308190
unsigned __int64 __fastcall hkTrackerSetLayoutHandler::getSize(hkTrackerSetLayoutHandler *this, hkTrackerTypeTreeNode *__formal, hkTrackerLayoutCalculator *a3)
{
  return 24i64;
}

