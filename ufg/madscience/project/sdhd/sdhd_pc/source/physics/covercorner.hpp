// File Line: 109
// RVA: 0x4499B0
void __fastcall UFG::DynamicCoverCorner::DynamicCoverCorner(UFG::DynamicCoverCorner *this)
{
  UFG::DynamicCoverCorner *v1; // rbx
  UFG::CoverCorner *v2; // [rsp+48h] [rbp+10h]
  UFG::qSafePointer<UFG::SimComponent,UFG::DynamicCoverComponent> *v3; // [rsp+48h] [rbp+10h]

  v1 = this;
  v2 = (UFG::CoverCorner *)&this->mPrev;
  v2->mPrev = (UFG::qNode<UFG::CoverCorner,UFG::CoverCorner> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::CoverCorner,UFG::CoverCorner> *)&v2->mPrev;
  *(_DWORD *)&this->m_eCoverSide.mValue = 0;
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::qSafePointerNode<UFG::DynamicCoverCorner>((UFG::qSafePointerNode<UFG::DynamicCoverCorner> *)&this->vfptr);
  v1->vfptr = (UFG::qSafePointerNode<UFG::DynamicCoverCorner>Vtbl *)&UFG::DynamicCoverCorner::`vftable';
  v3 = &v1->m_pParentInstance;
  v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v1->m_pParentInstance.m_pPointer = 0i64;
}

