// File Line: 175
// RVA: 0x3312E0
void __fastcall UFG::PedFormationProfileSlot::PedFormationProfileSlot(UFG::PedFormationProfileSlot *this)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::PedFormationProfile::Slot>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::PedFormationProfile::Slot>,UFG::qSafePointerNodeList> *mNext; // rax
  float y; // xmm1_4
  float z; // xmm2_4

  this->mProfileSlot.mPrev = &this->mProfileSlot;
  this->mProfileSlot.mNext = &this->mProfileSlot;
  this->mProfileSlot.m_pPointer = 0i64;
  if ( this->mProfileSlot.m_pPointer )
  {
    mPrev = this->mProfileSlot.mPrev;
    mNext = this->mProfileSlot.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mProfileSlot.mPrev = &this->mProfileSlot;
    this->mProfileSlot.mNext = &this->mProfileSlot;
  }
  this->mProfileSlot.m_pPointer = 0i64;
  this->mMemberSlot = 0i64;
  *(_WORD *)&this->mIsClear = 0;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->mOffset.x = UFG::qVector3::msZero.x;
  this->mOffset.y = y;
  this->mOffset.z = z;
  *(_QWORD *)&this->mForwardClearance = 0i64;
}

// File Line: 204
// RVA: 0x33F580
UFG::ComponentIDDesc *__fastcall UFG::PedFormationManagerComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::PedFormationManagerComponent::_DescInit )
  {
    UFG::PedFormationManagerComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::PedFormationManagerComponent::_DescInit = 1;
    UFG::PedFormationManagerComponent::_TypeUID = UFG::PedFormationManagerComponent::_TypeIDesc.mChildBitMask | (UFG::PedFormationManagerComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::PedFormationManagerComponent::_PedFormationManagerComponentTypeUID = UFG::PedFormationManagerComponent::_TypeIDesc.mChildBitMask | (UFG::PedFormationManagerComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::PedFormationManagerComponent::_TypeIDesc;
}

