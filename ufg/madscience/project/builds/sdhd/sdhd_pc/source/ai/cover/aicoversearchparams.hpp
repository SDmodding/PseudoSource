// File Line: 26
// RVA: 0x3341A0
void __fastcall UFG::AICoverSearchParams::~AICoverSearchParams(UFG::AICoverSearchParams *this)
{
  UFG::AICoverSearchParams::HostileTarget *p; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax

  p = this->m_aHostileTargets.p;
  if ( p )
    operator delete[](p);
  this->m_aHostileTargets.p = 0i64;
  *(_QWORD *)&this->m_aHostileTargets.size = 0i64;
  if ( this->m_pInitiator.m_pPointer )
  {
    mPrev = this->m_pInitiator.mPrev;
    mNext = this->m_pInitiator.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->m_pInitiator.mPrev = &this->m_pInitiator;
    this->m_pInitiator.mNext = &this->m_pInitiator;
  }
  this->m_pInitiator.m_pPointer = 0i64;
  v5 = this->m_pInitiator.mPrev;
  v6 = this->m_pInitiator.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  this->m_pInitiator.mPrev = &this->m_pInitiator;
  this->m_pInitiator.mNext = &this->m_pInitiator;
}

