// File Line: 33
// RVA: 0x644080
void __fastcall UFG::VehicleFormations::~VehicleFormations(UFG::VehicleFormations *this)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mpClosestToSecondaryTarget; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mpSecondaryTarget; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rax

  `eh vector destructor iterator(
    this->mSlots,
    0x18ui64,
    14,
    (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
  p_mpClosestToSecondaryTarget = &this->mpClosestToSecondaryTarget;
  if ( this->mpClosestToSecondaryTarget.m_pPointer )
  {
    mPrev = p_mpClosestToSecondaryTarget->mPrev;
    mNext = this->mpClosestToSecondaryTarget.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mpClosestToSecondaryTarget->mPrev = p_mpClosestToSecondaryTarget;
    this->mpClosestToSecondaryTarget.mNext = &this->mpClosestToSecondaryTarget;
  }
  this->mpClosestToSecondaryTarget.m_pPointer = 0i64;
  v5 = p_mpClosestToSecondaryTarget->mPrev;
  v6 = this->mpClosestToSecondaryTarget.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_mpClosestToSecondaryTarget->mPrev = p_mpClosestToSecondaryTarget;
  this->mpClosestToSecondaryTarget.mNext = &this->mpClosestToSecondaryTarget;
  p_mpSecondaryTarget = &this->mpSecondaryTarget;
  if ( this->mpSecondaryTarget.m_pPointer )
  {
    v8 = p_mpSecondaryTarget->mPrev;
    v9 = this->mpSecondaryTarget.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_mpSecondaryTarget->mPrev = p_mpSecondaryTarget;
    this->mpSecondaryTarget.mNext = &this->mpSecondaryTarget;
  }
  this->mpSecondaryTarget.m_pPointer = 0i64;
  v10 = p_mpSecondaryTarget->mPrev;
  v11 = this->mpSecondaryTarget.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  p_mpSecondaryTarget->mPrev = p_mpSecondaryTarget;
  this->mpSecondaryTarget.mNext = &this->mpSecondaryTarget;
}

// File Line: 41
// RVA: 0x3F97D0
void __fastcall UFG::VehicleFormations::SetSecondaryTarget(
        UFG::VehicleFormations *this,
        UFG::SimObject *pSecondaryTarget)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mpSecondaryTarget; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rax

  p_mpSecondaryTarget = &this->mpSecondaryTarget;
  if ( this->mpSecondaryTarget.m_pPointer )
  {
    mPrev = p_mpSecondaryTarget->mPrev;
    mNext = p_mpSecondaryTarget->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mpSecondaryTarget->mPrev = p_mpSecondaryTarget;
    p_mpSecondaryTarget->mNext = p_mpSecondaryTarget;
  }
  p_mpSecondaryTarget->m_pPointer = pSecondaryTarget;
  if ( pSecondaryTarget )
  {
    v5 = pSecondaryTarget->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    v5->mNext = p_mpSecondaryTarget;
    p_mpSecondaryTarget->mPrev = v5;
    p_mpSecondaryTarget->mNext = &pSecondaryTarget->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    pSecondaryTarget->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_mpSecondaryTarget;
  }
}

