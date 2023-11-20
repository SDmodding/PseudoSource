// File Line: 26
// RVA: 0x3341A0
void __fastcall UFG::AICoverSearchParams::~AICoverSearchParams(UFG::AICoverSearchParams *this)
{
  UFG::AICoverSearchParams *v1; // rbx
  UFG::AICoverSearchParams::HostileTarget *v2; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax

  v1 = this;
  v2 = this->m_aHostileTargets.p;
  if ( v2 )
    operator delete[](v2);
  v1->m_aHostileTargets.p = 0i64;
  *(_QWORD *)&v1->m_aHostileTargets.size = 0i64;
  if ( v1->m_pInitiator.m_pPointer )
  {
    v3 = v1->m_pInitiator.mPrev;
    v4 = v1->m_pInitiator.mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v1->m_pInitiator.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_pInitiator.mPrev;
    v1->m_pInitiator.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_pInitiator.mPrev;
  }
  v1->m_pInitiator.m_pPointer = 0i64;
  v5 = v1->m_pInitiator.mPrev;
  v6 = v1->m_pInitiator.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v1->m_pInitiator.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_pInitiator.mPrev;
  v1->m_pInitiator.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_pInitiator.mPrev;
}

