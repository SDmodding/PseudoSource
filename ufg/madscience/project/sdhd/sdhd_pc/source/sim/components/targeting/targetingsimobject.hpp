// File Line: 36
// RVA: 0x519820
void __fastcall UFG::TargetingSimObject::TargetingSimObject(UFG::TargetingSimObject *this)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v1; // [rsp+28h] [rbp+10h]

  this->mPrev = (UFG::qNode<UFG::TargetingSimObject,UFG::TargetingSimObject> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::TargetingSimObject,UFG::TargetingSimObject> *)&this->mPrev;
  this->m_pTSBC = 0i64;
  v1 = &this->m_pTarget;
  v1->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mPrev;
  this->m_pTarget.m_pPointer = 0i64;
  *(_WORD *)&this->m_eTargetType.mValue = 0;
}

