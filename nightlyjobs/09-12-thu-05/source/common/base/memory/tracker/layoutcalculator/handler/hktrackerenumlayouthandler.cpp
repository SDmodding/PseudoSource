// File Line: 17
// RVA: 0x13081C0
void __fastcall hkTrackerEnumLayoutHandler::getReferences(hkTrackerEnumLayoutHandler *this, hkTrackerLayoutBlock *curBlock, const void *curData, hkTrackerTypeTreeNode *curType)
{
  ;
}

// File Line: 22
// RVA: 0x13081D0
unsigned __int64 __fastcall hkTrackerEnumLayoutHandler::getSize(hkTrackerEnumLayoutHandler *this, hkTrackerTypeTreeNode *curType, hkTrackerLayoutCalculator *layoutCalc)
{
  return hkTrackerLayoutCalculator::calcTypeSize(layoutCalc, curType->m_contains->m_next);
}

