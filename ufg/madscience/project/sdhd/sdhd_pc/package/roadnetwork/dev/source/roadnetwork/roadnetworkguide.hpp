// File Line: 88
// RVA: 0xD0CC0
void __fastcall UFG::RoadNetworkGuide::~RoadNetworkGuide(UFG::RoadNetworkGuide *this)
{
  UFG::qSafePointerNode<UFG::ParkourHandle> *v1; // rdi
  UFG::qSafePointer<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qSafePointerNode<UFG::ParkourHandle> *v9; // rdx
  UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v11; // rax

  v1 = (UFG::qSafePointerNode<UFG::ParkourHandle> *)this;
  this->vfptr = (UFG::qSafePointerNode<UFG::RoadNetworkGuide>Vtbl *)&UFG::RoadNetworkGuide::`vftable;
  v2 = &this->m_NextGuide;
  if ( this->m_NextGuide.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v2->m_pPointer = 0i64;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v1->vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)&UFG::qSafePointerNode<UFG::RoadNetworkGuide>::`vftable;
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull(v1);
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes(&v1->m_SafePointerList);
  v7 = v1->m_SafePointerList.mNode.mPrev;
  v8 = v1->m_SafePointerList.mNode.mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v1->m_SafePointerList.mNode.mPrev = &v1->m_SafePointerList.mNode;
  v1->m_SafePointerList.mNode.mNext = &v1->m_SafePointerList.mNode;
  v9 = v1 + 1;
  v10 = v1[1].vfptr;
  v11 = v1[1].m_SafePointerList.mNode.mPrev;
  v10[1].__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::ParkourHandle> *, unsigned int))v11;
  v11->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)v10;
  v9->vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)v9;
  v9->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)v9;
}

