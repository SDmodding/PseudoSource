// File Line: 15
// RVA: 0xDB6B60
void __fastcall hkpMoppCostFunction::hkpMoppSplitCostParams::hkpMoppSplitCostParams(
        hkpMoppCostFunction::hkpMoppSplitCostParams *this,
        hkpMoppMeshType __formal)
{
  this->m_weightPrimitiveSplit = 1.0;
  this->m_weightPlaneDistance = 1.0;
  this->m_weightNumUnbalancedTriangles = 1.0;
  this->m_weightPlanePosition = 1.0;
  this->m_weightPrimitiveIdSpread = 1.0;
  this->m_queryErrorTolerance = 0.5;
}

// File Line: 25
// RVA: 0xDB6BF0
void __fastcall hkpMoppCostFunction::updateParams(
        hkpMoppCostFunction *this,
        hkpMoppCostFunction::hkpMoppSplitCostParams *bp)
{
  this->m_userScaling = *bp;
}

// File Line: 31
// RVA: 0xDB6BA0
void __fastcall hkpMoppCostFunction::hkpMoppCostFunction(
        hkpMoppCostFunction *this,
        hkpMoppCostFunction::hkpMoppSplitCostParams *bp)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpMoppCostFunction::`vftable;
  hkpMoppCostFunction::hkpMoppSplitCostParams::hkpMoppSplitCostParams(&this->m_userScaling, HK_MOPP_MT_LANDSCAPE);
  hkpMoppCostFunction::updateParams(this, bp);
}

