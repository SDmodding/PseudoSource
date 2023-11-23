// File Line: 88
// RVA: 0xD0CC0
void __fastcall UFG::RoadNetworkGuide::~RoadNetworkGuide(UFG::RoadNetworkGuide *this)
{
  UFG::qSafePointer<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *p_m_NextGuide; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *v9; // rcx
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *v10; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::RoadNetworkGuide>Vtbl *)&UFG::RoadNetworkGuide::`vftable;
  p_m_NextGuide = &this->m_NextGuide;
  if ( this->m_NextGuide.m_pPointer )
  {
    mPrev = p_m_NextGuide->mPrev;
    mNext = p_m_NextGuide->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_NextGuide->mPrev = p_m_NextGuide;
    p_m_NextGuide->mNext = p_m_NextGuide;
  }
  p_m_NextGuide->m_pPointer = 0i64;
  v5 = p_m_NextGuide->mPrev;
  v6 = p_m_NextGuide->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_NextGuide->mPrev = p_m_NextGuide;
  p_m_NextGuide->mNext = p_m_NextGuide;
  this->vfptr = (UFG::qSafePointerNode<UFG::RoadNetworkGuide>Vtbl *)&UFG::qSafePointerNode<UFG::RoadNetworkGuide>::`vftable;
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull((UFG::qSafePointerNode<UFG::ParkourHandle> *)this);
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes((UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *)&this->m_SafePointerList);
  v7 = this->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::RoadNetworkGuide>::mPrev;
  v8 = this->m_SafePointerList.mNode.mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::RoadNetworkGuide>::mPrev = &this->m_SafePointerList.mNode;
  this->m_SafePointerList.mNode.mNext = &this->m_SafePointerList.mNode;
  v9 = this->mPrev;
  v10 = this->mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  this->mPrev = &this->UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide>;
  this->mNext = &this->UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide>;
}

