// File Line: 50
// RVA: 0xFB370
void __fastcall UFG::FlowfieldPrint::FlowfieldPrint(UFG::FlowfieldPrint *this, unsigned int type, int iPriority, float fStrength)
{
  int v4; // ebx
  UFG::FlowfieldPrint *v5; // rdi
  UFG::qNode<UFG::FlowfieldPrint,UFG::FlowfieldPrint> *v6; // rax
  UFG::qNode<UFG::FlowfieldPrint,UFG::FFieldPrintCompList> *v7; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::FlowfieldComponent> *v8; // ST28_8
  UFG::qSafePointer<UFG::SimComponent,UFG::FFieldPrintComponent> *v9; // ST28_8
  UFG::qSafePointer<UFG::SimComponent,UFG::AIInterestComponent> *v10; // ST28_8

  v4 = iPriority;
  v5 = this;
  this->mID = type;
  this->mTypeID = type;
  this->mDebugName = 0i64;
  UFG::qSafePointerNode<UFG::FlowfieldPrint>::qSafePointerNode<UFG::FlowfieldPrint>((UFG::qSafePointerNode<UFG::FlowfieldPrint> *)&this->vfptr);
  v6 = (UFG::qNode<UFG::FlowfieldPrint,UFG::FlowfieldPrint> *)&v5->mPrev;
  v6->mPrev = v6;
  v6->mNext = v6;
  v7 = (UFG::qNode<UFG::FlowfieldPrint,UFG::FFieldPrintCompList> *)&v5->mPrev;
  v7->mPrev = v7;
  v7->mNext = v7;
  v5->vfptr = (UFG::qSafePointerNode<UFG::FlowfieldPrint>Vtbl *)&UFG::FlowfieldPrint::`vftable;
  v5->m_iPriority = v4;
  v5->m_fStrength = fStrength;
  *(_WORD *)&v5->m_Enabled = 1;
  v8 = &v5->mpParentField;
  v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
  v8->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
  v5->mpParentField.m_pPointer = 0i64;
  v9 = &v5->mpPrintComponent;
  v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
  v9->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
  v5->mpPrintComponent.m_pPointer = 0i64;
  v10 = &v5->mpInterest;
  v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v10->mPrev;
  v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v10->mPrev;
  v5->mpInterest.m_pPointer = 0i64;
}

// File Line: 106
// RVA: 0xFAEB0
void __fastcall UFG::FFieldAvoidablePrint::FFieldAvoidablePrint(UFG::FFieldAvoidablePrint *this, UFG::AIInterestComponent *pAvoidable, int iPriority, float fStrength)
{
  UFG::AIInterestComponent *v4; // rdi
  UFG::FFieldAvoidablePrint *v5; // rbx
  UFG::qSafePointer<UFG::SimComponent,UFG::AIInterestComponent> *v6; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax

  v4 = pAvoidable;
  v5 = this;
  UFG::FlowfieldPrint::FlowfieldPrint((UFG::FlowfieldPrint *)&this->vfptr, 0, iPriority, fStrength);
  v5->vfptr = (UFG::qSafePointerNode<UFG::FlowfieldPrint>Vtbl *)&UFG::FFieldAvoidablePrint::`vftable;
  v5->mpPathCurve = 0i64;
  v5->mParams.Priority = 3.0;
  v5->mParams.SidestepMaxDP = -1.0;
  v5->mParams.FlashlightScoreMax = 0.89999998;
  v5->mParams.FLMaxAngle = 0.35017776;
  v5->mParams.FLMinAngle = 0.0099999998;
  v5->mParams.FLMaxDist = 40.0;
  v5->mParams.Method = 3.0;
  v5->mParams.SidestepMinDP = 0.25;
  v5->mParams.Strength = 4.0;
  *(_QWORD *)&v5->mParams.FLMinDist = 1092616192i64;
  *(_QWORD *)&v5->mParams.Offset.y = 0i64;
  v5->mParams.MinDistToTrackEdge = 3.0;
  v5->mParams.RadiusAdditive = 0.40000001;
  v6 = &v5->mpInterest;
  if ( v5->mpInterest.m_pPointer )
  {
    v7 = v6->mPrev;
    v8 = v5->mpInterest.mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
    v5->mpInterest.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mpInterest.mPrev;
  }
  v5->mpInterest.m_pPointer = (UFG::SimComponent *)&v4->vfptr;
  if ( v4 )
  {
    v9 = v4->m_SafePointerList.mNode.mPrev;
    v9->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
    v6->mPrev = v9;
    v5->mpInterest.mNext = &v4->m_SafePointerList.mNode;
    v4->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  }
}

// File Line: 205
// RVA: 0xFC6C0
UFG::ComponentIDDesc *__fastcall UFG::FFieldPrintComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::FFieldPrintComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::FFieldPrintComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::FFieldPrintComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::FFieldPrintComponent::_DescInit = 1;
    UFG::FFieldPrintComponent::_TypeUID = UFG::FFieldPrintComponent::_TypeIDesc.mChildBitMask | (UFG::FFieldPrintComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::FFieldPrintComponent::_FFieldPrintComponentTypeUID = UFG::FFieldPrintComponent::_TypeIDesc.mChildBitMask | (UFG::FFieldPrintComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::FFieldPrintComponent::_TypeIDesc;
}

