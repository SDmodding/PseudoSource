// File Line: 175
// RVA: 0x3312E0
void __fastcall UFG::PedFormationProfileSlot::PedFormationProfileSlot(UFG::PedFormationProfileSlot *this)
{
  UFG::PedFormationProfileSlot *v1; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::PedFormationProfile::Slot>,UFG::qSafePointerNodeList> *v2; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::PedFormationProfile::Slot>,UFG::qSafePointerNodeList> *v3; // rax
  float v4; // xmm1_4
  float v5; // xmm2_4

  v1 = this;
  this->mProfileSlot.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::PedFormationProfile::Slot>,UFG::qSafePointerNodeList> *)&this->mProfileSlot.mPrev;
  this->mProfileSlot.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::PedFormationProfile::Slot>,UFG::qSafePointerNodeList> *)&this->mProfileSlot.mPrev;
  this->mProfileSlot.m_pPointer = 0i64;
  if ( this->mProfileSlot.m_pPointer )
  {
    v2 = this->mProfileSlot.mPrev;
    v3 = v1->mProfileSlot.mNext;
    v2->mNext = v3;
    v3->mPrev = v2;
    v1->mProfileSlot.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::PedFormationProfile::Slot>,UFG::qSafePointerNodeList> *)&v1->mProfileSlot.mPrev;
    v1->mProfileSlot.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::PedFormationProfile::Slot>,UFG::qSafePointerNodeList> *)&v1->mProfileSlot.mPrev;
  }
  v1->mProfileSlot.m_pPointer = 0i64;
  v1->mMemberSlot = 0i64;
  *(_WORD *)&v1->mIsClear = 0;
  v4 = UFG::qVector3::msZero.y;
  v5 = UFG::qVector3::msZero.z;
  v1->mOffset.x = UFG::qVector3::msZero.x;
  v1->mOffset.y = v4;
  v1->mOffset.z = v5;
  *(_QWORD *)&v1->mForwardClearance = 0i64;
}

// File Line: 204
// RVA: 0x33F580
UFG::ComponentIDDesc *__fastcall UFG::PedFormationManagerComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::PedFormationManagerComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::PedFormationManagerComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::PedFormationManagerComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::PedFormationManagerComponent::_DescInit = 1;
    UFG::PedFormationManagerComponent::_TypeUID = UFG::PedFormationManagerComponent::_TypeIDesc.mChildBitMask | (UFG::PedFormationManagerComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::PedFormationManagerComponent::_PedFormationManagerComponentTypeUID = UFG::PedFormationManagerComponent::_TypeIDesc.mChildBitMask | (UFG::PedFormationManagerComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::PedFormationManagerComponent::_TypeIDesc;
}

