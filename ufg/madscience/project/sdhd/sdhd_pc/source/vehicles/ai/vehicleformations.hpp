// File Line: 33
// RVA: 0x644080
void __fastcall UFG::VehicleFormations::~VehicleFormations(UFG::VehicleFormations *this)
{
  UFG::VehicleFormations *v1; // rbx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rax

  v1 = this;
  `eh vector destructor iterator'(
    this->mSlots,
    0x18ui64,
    14,
    (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
  v2 = &v1->mpClosestToSecondaryTarget;
  if ( v1->mpClosestToSecondaryTarget.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v1->mpClosestToSecondaryTarget.mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v1->mpClosestToSecondaryTarget.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mpClosestToSecondaryTarget.mPrev;
  }
  v1->mpClosestToSecondaryTarget.m_pPointer = 0i64;
  v5 = v2->mPrev;
  v6 = v1->mpClosestToSecondaryTarget.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v1->mpClosestToSecondaryTarget.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mpClosestToSecondaryTarget.mPrev;
  v7 = &v1->mpSecondaryTarget;
  if ( v1->mpSecondaryTarget.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v1->mpSecondaryTarget.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v1->mpSecondaryTarget.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mpSecondaryTarget.mPrev;
  }
  v1->mpSecondaryTarget.m_pPointer = 0i64;
  v10 = v7->mPrev;
  v11 = v1->mpSecondaryTarget.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v1->mpSecondaryTarget.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mpSecondaryTarget.mPrev;
}

// File Line: 41
// RVA: 0x3F97D0
void __fastcall UFG::VehicleFormations::SetSecondaryTarget(UFG::VehicleFormations *this, UFG::SimObject *pSecondaryTarget)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v2; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rax

  v2 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->mpSecondaryTarget.mPrev;
  if ( this->mpSecondaryTarget.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = v2;
    v2->mNext = v2;
  }
  v2[1].mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)pSecondaryTarget;
  if ( pSecondaryTarget )
  {
    v5 = pSecondaryTarget->m_SafePointerList.mNode.mPrev;
    v5->mNext = v2;
    v2->mPrev = v5;
    v2->mNext = &pSecondaryTarget->m_SafePointerList.mNode;
    pSecondaryTarget->m_SafePointerList.mNode.mPrev = v2;
  }
}

