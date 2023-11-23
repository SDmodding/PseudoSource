// File Line: 18
// RVA: 0x13080F0
void __fastcall hkTrackerSetLayoutHandler::getReferences(
        hkTrackerSetLayoutHandler *this,
        hkTrackerLayoutBlock *curBlock,
        const void **curData,
        hkTrackerTypeTreeNode *curType,
        hkTrackerLayoutCalculator *layoutCalc,
        hkArrayBase<char *> *newBlocks)
{
  hkTrackerTypeTreeNode *m_contains; // rbx
  hkTrackerTypeTreeCache *m_pntr; // rdi
  hkTrackerTypeTreeNode *v10; // rax
  hkTrackerTypeTreeNode *v11; // rsi
  char *v12; // rax

  m_contains = curType->m_contains;
  m_pntr = layoutCalc->m_typeCache.m_pntr;
  hkTrackerTypeTreeCache::newNode(m_pntr, TYPE_REAL);
  v10->m_contains = m_contains;
  v11 = v10;
  v12 = hkTrackerTypeTreeCache::newText(m_pntr, "hkArray");
  hkSubString::operator=(&v11->m_name, v12);
  hkTrackerLayoutCalculator::getReferencesRecursive(layoutCalc, curBlock, curData, v11, newBlocks);
}

// File Line: 37
// RVA: 0x1308190
unsigned __int64 __fastcall hkTrackerSetLayoutHandler::getSize(
        hkTrackerSetLayoutHandler *this,
        hkTrackerTypeTreeNode *__formal,
        hkTrackerLayoutCalculator *a3)
{
  return 24i64;
}

