// File Line: 31
// RVA: 0x32CE10
void __fastcall UFG::Behaviour::Behaviour(UFG::Behaviour *this, UFG::InvokeBehaviourParams *params)
{
  this->mPrev = &this->UFG::qNode<UFG::Behaviour,UFG::Behaviour>;
  this->mNext = &this->UFG::qNode<UFG::Behaviour,UFG::Behaviour>;
  UFG::qSafePointerNode<UFG::Behaviour>::qSafePointerNode<UFG::Behaviour>(this);
  this->vfptr = (UFG::qSafePointerNode<UFG::Behaviour>Vtbl *)&UFG::Behaviour::`vftable;
  *(_QWORD *)&this->mAge = 0i64;
  this->mParams = *params;
  this->mActionContext = 0i64;
  this->mActionController = 0i64;
}

// File Line: 35
// RVA: 0x335640
void __fastcall UFG::Behaviour::~Behaviour(UFG::Behaviour *this)
{
  ActionController *mActionController; // rcx
  ActionContext *mActionContext; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::Behaviour>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::Behaviour>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> *v10; // rcx
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> *v11; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::Behaviour>Vtbl *)&UFG::Behaviour::`vftable;
  if ( !this->mParams.mInvokeTask || this->mParams.mControlType )
  {
    mActionController = this->mActionController;
    if ( mActionController )
      mActionController->vfptr->__vecDelDtor(mActionController, 1u);
    mActionContext = this->mActionContext;
    if ( mActionContext )
    {
      if ( mActionContext->mSimObject.m_pPointer )
      {
        mPrev = mActionContext->mSimObject.mPrev;
        mNext = mActionContext->mSimObject.mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        mActionContext->mSimObject.mPrev = &mActionContext->mSimObject;
        mActionContext->mSimObject.mNext = &mActionContext->mSimObject;
      }
      mActionContext->mSimObject.m_pPointer = 0i64;
      v6 = mActionContext->mSimObject.mPrev;
      v7 = mActionContext->mSimObject.mNext;
      v6->mNext = v7;
      v7->mPrev = v6;
      mActionContext->mSimObject.mPrev = &mActionContext->mSimObject;
      mActionContext->mSimObject.mNext = &mActionContext->mSimObject;
      operator delete[](mActionContext);
    }
  }
  this->vfptr = (UFG::qSafePointerNode<UFG::Behaviour>Vtbl *)&UFG::qSafePointerNode<UFG::Behaviour>::`vftable;
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull((UFG::qSafePointerNode<UFG::ParkourHandle> *)this);
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes((UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *)&this->m_SafePointerList);
  v8 = this->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::Behaviour>::mPrev;
  v9 = this->m_SafePointerList.mNode.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  this->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::Behaviour>::mPrev = &this->m_SafePointerList.mNode;
  this->m_SafePointerList.mNode.mNext = &this->m_SafePointerList.mNode;
  v10 = this->mPrev;
  v11 = this->mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  this->mPrev = &this->UFG::qNode<UFG::Behaviour,UFG::Behaviour>;
  this->mNext = &this->UFG::qNode<UFG::Behaviour,UFG::Behaviour>;
}

// File Line: 75
// RVA: 0x33F1E0
UFG::ComponentIDDesc *__fastcall UFG::BehaviourControllerComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  int v3; // [rsp+20h] [rbp-18h]

  if ( !UFG::BehaviourControllerComponent::_DescInit )
  {
    v0 = UFG::AIActionTreeComponent::AccessComponentDesc();
    ++UFG::AIActionTreeComponent::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::AIActionTreeComponent::_TypeIDesc.mChildren));
    LOWORD(v3) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::BehaviourControllerComponent::_TypeIDesc.mBaseTypeIndex = v3;
    UFG::BehaviourControllerComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::BehaviourControllerComponent::_TypeIDesc.mChildren = 0;
    UFG::BehaviourControllerComponent::_DescInit = 1;
    UFG::BehaviourControllerComponent::_TypeUID = v1 | ((unsigned __int16)v3 << 25);
    UFG::BehaviourControllerComponent::_BehaviourControllerComponentTypeUID = v1 | ((unsigned __int16)v3 << 25);
  }
  return &UFG::BehaviourControllerComponent::_TypeIDesc;
}

