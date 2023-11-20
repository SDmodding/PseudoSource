// File Line: 17
// RVA: 0x13081A0
void __fastcall hkTrackerFlagsLayoutHandler::getReferences(hkTrackerFlagsLayoutHandler *this, hkTrackerLayoutBlock *curBlock, const void *curData, hkTrackerTypeTreeNode *curType)
{
  ;
}

// File Line: 22
// RVA: 0x13081B0
unsigned __int64 __fastcall hkTrackerFlagsLayoutHandler::getSize(hkTrackerFlagsLayoutHandler *this, hkTrackerTypeTreeNode *curType, hkTrackerLayoutCalculator *layoutCalc)
{
  return hkTrackerLayoutCalculator::calcTypeSize(layoutCalc, curType->m_contains->m_next);
}

