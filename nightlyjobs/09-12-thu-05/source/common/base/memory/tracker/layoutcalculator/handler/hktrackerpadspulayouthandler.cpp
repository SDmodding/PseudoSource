// File Line: 17
// RVA: 0x1307E40
void __fastcall hkTrackerPadSpuLayoutHandler::getReferences(
        hkTrackerPadSpuLayoutHandler *this,
        hkTrackerLayoutBlock *curBlock,
        const void **curData,
        hkTrackerTypeTreeNode *curType,
        hkTrackerLayoutCalculator *layoutCalc,
        hkArrayBase<char *> *newBlocks)
{
  hkTrackerLayoutCalculator::getReferencesRecursive(layoutCalc, curBlock, curData, curType->m_contains, newBlocks);
}

// File Line: 28
// RVA: 0x1307E60
unsigned __int64 __fastcall hkTrackerPadSpuLayoutHandler::getSize(
        hkTrackerPadSpuLayoutHandler *this,
        hkTrackerTypeTreeNode *__formal,
        hkTrackerLayoutCalculator *a3)
{
  return 8i64;
}

