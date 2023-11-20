// File Line: 15
// RVA: 0xDB6B60
void __fastcall hkpMoppCostFunction::hkpMoppSplitCostParams::hkpMoppSplitCostParams(hkpMoppCostFunction::hkpMoppSplitCostParams *this, hkpMoppMeshType __formal)
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
void __fastcall hkpMoppCostFunction::updateParams(hkpMoppCostFunction *this, hkpMoppCostFunction::hkpMoppSplitCostParams *bp)
{
  this->m_userScaling.m_weightPrimitiveSplit = bp->m_weightPrimitiveSplit;
  this->m_userScaling.m_weightPlaneDistance = bp->m_weightPlaneDistance;
  this->m_userScaling.m_weightNumUnbalancedTriangles = bp->m_weightNumUnbalancedTriangles;
  this->m_userScaling.m_weightPlanePosition = bp->m_weightPlanePosition;
  this->m_userScaling.m_weightPrimitiveIdSpread = bp->m_weightPrimitiveIdSpread;
  this->m_userScaling.m_queryErrorTolerance = bp->m_queryErrorTolerance;
}

// File Line: 31
// RVA: 0xDB6BA0
void __fastcall hkpMoppCostFunction::hkpMoppCostFunction(hkpMoppCostFunction *this, hkpMoppCostFunction::hkpMoppSplitCostParams *bp)
{
  hkpMoppCostFunction::hkpMoppSplitCostParams *v2; // rbx
  hkpMoppCostFunction *v3; // rdi

  v2 = bp;
  v3 = this;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpMoppCostFunction::`vftable';
  hkpMoppCostFunction::hkpMoppSplitCostParams::hkpMoppSplitCostParams(&this->m_userScaling, 0);
  hkpMoppCostFunction::updateParams(v3, v2);
}

