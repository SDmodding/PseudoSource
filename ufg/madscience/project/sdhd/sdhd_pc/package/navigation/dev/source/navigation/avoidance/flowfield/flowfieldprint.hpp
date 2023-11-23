// File Line: 50
// RVA: 0xFB370
void __fastcall UFG::FlowfieldPrint::FlowfieldPrint(
        UFG::FlowfieldPrint *this,
        unsigned int type,
        int iPriority,
        float fStrength)
{
  this->mID = type;
  this->mTypeID = type;
  this->mDebugName = 0i64;
  UFG::qSafePointerNode<UFG::FlowfieldPrint>::qSafePointerNode<UFG::FlowfieldPrint>(this);
  this->UFG::qNode<UFG::FlowfieldPrint,UFG::FlowfieldPrint>::mPrev = &this->UFG::qNode<UFG::FlowfieldPrint,UFG::FlowfieldPrint>;
  this->UFG::qNode<UFG::FlowfieldPrint,UFG::FlowfieldPrint>::mNext = &this->UFG::qNode<UFG::FlowfieldPrint,UFG::FlowfieldPrint>;
  this->UFG::qNode<UFG::FlowfieldPrint,UFG::FFieldPrintCompList>::mPrev = &this->UFG::qNode<UFG::FlowfieldPrint,UFG::FFieldPrintCompList>;
  this->UFG::qNode<UFG::FlowfieldPrint,UFG::FFieldPrintCompList>::mNext = &this->UFG::qNode<UFG::FlowfieldPrint,UFG::FFieldPrintCompList>;
  this->vfptr = (UFG::qSafePointerNode<UFG::FlowfieldPrint>Vtbl *)&UFG::FlowfieldPrint::`vftable;
  this->m_iPriority = iPriority;
  this->m_fStrength = fStrength;
  *(_WORD *)&this->m_Enabled = 1;
  this->mpParentField.mPrev = &this->mpParentField;
  this->mpParentField.mNext = &this->mpParentField;
  this->mpParentField.m_pPointer = 0i64;
  this->mpPrintComponent.mPrev = &this->mpPrintComponent;
  this->mpPrintComponent.mNext = &this->mpPrintComponent;
  this->mpPrintComponent.m_pPointer = 0i64;
  this->mpInterest.mPrev = &this->mpInterest;
  this->mpInterest.mNext = &this->mpInterest;
  this->mpInterest.m_pPointer = 0i64;
}

// File Line: 106
// RVA: 0xFAEB0
void __fastcall UFG::FFieldAvoidablePrint::FFieldAvoidablePrint(
        UFG::FFieldAvoidablePrint *this,
        UFG::AIInterestComponent *pAvoidable,
        int iPriority,
        float fStrength)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::AIInterestComponent> *p_mpInterest; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax

  UFG::FlowfieldPrint::FlowfieldPrint(this, 0, iPriority, fStrength);
  this->vfptr = (UFG::qSafePointerNode<UFG::FlowfieldPrint>Vtbl *)&UFG::FFieldAvoidablePrint::`vftable;
  this->mpPathCurve = 0i64;
  this->mParams.Priority = 3.0;
  this->mParams.SidestepMaxDP = -1.0;
  this->mParams.FlashlightScoreMax = 0.89999998;
  this->mParams.FLMaxAngle = 0.35017776;
  this->mParams.FLMinAngle = 0.0099999998;
  this->mParams.FLMaxDist = 40.0;
  this->mParams.Method = 3.0;
  this->mParams.SidestepMinDP = 0.25;
  this->mParams.Strength = 4.0;
  *(_QWORD *)&this->mParams.FLMinDist = 1092616192i64;
  *(_QWORD *)&this->mParams.Offset.y = 0i64;
  this->mParams.MinDistToTrackEdge = 3.0;
  this->mParams.RadiusAdditive = 0.40000001;
  p_mpInterest = &this->mpInterest;
  if ( this->mpInterest.m_pPointer )
  {
    mPrev = p_mpInterest->mPrev;
    mNext = this->mpInterest.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mpInterest->mPrev = p_mpInterest;
    this->mpInterest.mNext = &this->mpInterest;
  }
  this->mpInterest.m_pPointer = pAvoidable;
  if ( pAvoidable )
  {
    v9 = pAvoidable->m_SafePointerList.mNode.UFG::StateComponentI<UFG::SimComponent>::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
    v9->mNext = p_mpInterest;
    p_mpInterest->mPrev = v9;
    this->mpInterest.mNext = &pAvoidable->m_SafePointerList.mNode;
    pAvoidable->m_SafePointerList.mNode.UFG::StateComponentI<UFG::SimComponent>::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = p_mpInterest;
  }
}

// File Line: 205
// RVA: 0xFC6C0
UFG::ComponentIDDesc *__fastcall UFG::FFieldPrintComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::FFieldPrintComponent::_DescInit )
  {
    UFG::FFieldPrintComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::FFieldPrintComponent::_DescInit = 1;
    UFG::FFieldPrintComponent::_TypeUID = UFG::FFieldPrintComponent::_TypeIDesc.mChildBitMask | (UFG::FFieldPrintComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::FFieldPrintComponent::_FFieldPrintComponentTypeUID = UFG::FFieldPrintComponent::_TypeIDesc.mChildBitMask | (UFG::FFieldPrintComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::FFieldPrintComponent::_TypeIDesc;
}

