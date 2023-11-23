// File Line: 36
// RVA: 0x519820
void __fastcall UFG::TargetingSimObject::TargetingSimObject(UFG::TargetingSimObject *this)
{
  this->mPrev = this;
  this->mNext = this;
  this->m_pTSBC = 0i64;
  this->m_pTarget.mPrev = &this->m_pTarget;
  this->m_pTarget.mNext = &this->m_pTarget;
  this->m_pTarget.m_pPointer = 0i64;
  *(_WORD *)&this->m_eTargetType.mValue = 0;
}

