// File Line: 109
// RVA: 0x4499B0
void __fastcall UFG::DynamicCoverCorner::DynamicCoverCorner(UFG::DynamicCoverCorner *this)
{
  this->mPrev = &this->UFG::CoverCorner;
  this->mNext = &this->UFG::CoverCorner;
  *(_DWORD *)&this->m_eCoverSide.mValue = 0;
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::qSafePointerNode<UFG::DynamicCoverCorner>(this);
  this->vfptr = (UFG::qSafePointerNode<UFG::DynamicCoverCorner>Vtbl *)&UFG::DynamicCoverCorner::`vftable;
  this->m_pParentInstance.mPrev = &this->m_pParentInstance;
  this->m_pParentInstance.mNext = &this->m_pParentInstance;
  this->m_pParentInstance.m_pPointer = 0i64;
}

