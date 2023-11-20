// File Line: 31
// RVA: 0x32CE10
void __fastcall UFG::Behaviour::Behaviour(UFG::Behaviour *this, UFG::InvokeBehaviourParams *params)
{
  UFG::InvokeBehaviourParams *v2; // rbx
  UFG::Behaviour *v3; // rdi
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> *v4; // rax

  v2 = params;
  v3 = this;
  v4 = (UFG::qNode<UFG::Behaviour,UFG::Behaviour> *)&this->mPrev;
  v4->mPrev = v4;
  v4->mNext = v4;
  UFG::qSafePointerNode<UFG::Behaviour>::qSafePointerNode<UFG::Behaviour>((UFG::qSafePointerNode<UFG::Behaviour> *)&this->vfptr);
  v3->vfptr = (UFG::qSafePointerNode<UFG::Behaviour>Vtbl *)&UFG::Behaviour::`vftable;
  *(_QWORD *)&v3->mAge = 0i64;
  v3->mParams.mNode = v2->mNode;
  *(_QWORD *)&v3->mParams.mPriority = *(_QWORD *)&v2->mPriority;
  *(_QWORD *)&v3->mParams.mControlType = *(_QWORD *)&v2->mControlType;
  *(_QWORD *)&v3->mParams.mMaxLifeTime = *(_QWORD *)&v2->mMaxLifeTime;
  v3->mParams.mInvokeTask = v2->mInvokeTask;
  v3->mActionContext = 0i64;
  v3->mActionController = 0i64;
}

// File Line: 35
// RVA: 0x335640
void __fastcall UFG::Behaviour::~Behaviour(UFG::Behaviour *this)
{
  UFG::qSafePointerNode<UFG::ParkourHandle> *v1; // rdi
  ActionController *v2; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v4; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v6; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qSafePointerNode<UFG::ParkourHandle> *v10; // rdx
  UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v12; // rax

  v1 = (UFG::qSafePointerNode<UFG::ParkourHandle> *)this;
  this->vfptr = (UFG::qSafePointerNode<UFG::Behaviour>Vtbl *)&UFG::Behaviour::`vftable;
  if ( !this->mParams.mInvokeTask || this->mParams.mControlType )
  {
    v2 = this->mActionController;
    if ( v2 )
      v2->vfptr->__vecDelDtor((Expression::IMemberMap *)&v2->vfptr, 1u);
    v3 = v1[3].m_SafePointerList.mNode.mNext;
    if ( v3 )
    {
      if ( v3[1].mPrev )
      {
        v4 = v3->mPrev;
        v5 = v3->mNext;
        v4->mNext = v5;
        v5->mPrev = v4;
        v3->mPrev = v3;
        v3->mNext = v3;
      }
      v3[1].mPrev = 0i64;
      v6 = v3->mPrev;
      v7 = v3->mNext;
      v6->mNext = v7;
      v7->mPrev = v6;
      v3->mPrev = v3;
      v3->mNext = v3;
      operator delete[](v3);
    }
  }
  v1->vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)&UFG::qSafePointerNode<UFG::Behaviour>::`vftable;
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull(v1);
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes(&v1->m_SafePointerList);
  v8 = v1->m_SafePointerList.mNode.mPrev;
  v9 = v1->m_SafePointerList.mNode.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v1->m_SafePointerList.mNode.mPrev = &v1->m_SafePointerList.mNode;
  v1->m_SafePointerList.mNode.mNext = &v1->m_SafePointerList.mNode;
  v10 = v1 + 1;
  v11 = v1[1].vfptr;
  v12 = v1[1].m_SafePointerList.mNode.mPrev;
  v11[1].__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::ParkourHandle> *, unsigned int))v12;
  v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)v11;
  v10->vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)v10;
  v10->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)v10;
}

// File Line: 75
// RVA: 0x33F1E0
UFG::ComponentIDDesc *__fastcall UFG::BehaviourControllerComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  _DWORD v3[6]; // [rsp+20h] [rbp-18h]

  if ( !UFG::BehaviourControllerComponent::_DescInit )
  {
    v0 = UFG::AIActionTreeComponent::AccessComponentDesc();
    ++UFG::AIActionTreeComponent::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::AIActionTreeComponent::_TypeIDesc.mChildren));
    LOWORD(v3[0]) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::BehaviourControllerComponent::_TypeIDesc.mBaseTypeIndex = v3[0];
    UFG::BehaviourControllerComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::BehaviourControllerComponent::_TypeIDesc.mChildren = 0;
    UFG::BehaviourControllerComponent::_DescInit = 1;
    UFG::BehaviourControllerComponent::_TypeUID = v1 | (LOWORD(v3[0]) << 25);
    UFG::BehaviourControllerComponent::_BehaviourControllerComponentTypeUID = v1 | (LOWORD(v3[0]) << 25);
  }
  return &UFG::BehaviourControllerComponent::_TypeIDesc;
}

