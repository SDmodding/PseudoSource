// File Line: 137
// RVA: 0x386490
void __fastcall UFG::FormationSlot::SetFormationMember(UFG::FormationSlot *this, UFG::GetInFormationNode *member)
{
  UFG::qSafePointer<UFG::GetInFormationNode,UFG::GetInFormationNode> *p_m_pMember; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInFormationNode>,UFG::qSafePointerNodeList> *mPrev; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInFormationNode>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInFormationNode>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::SimObject *m_pPointer; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pMemberSimObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v12; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rax

  p_m_pMember = &this->m_pMember;
  if ( this->m_pMember.m_pPointer )
  {
    mPrev = p_m_pMember->mPrev;
    mNext = this->m_pMember.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pMember->mPrev = p_m_pMember;
    this->m_pMember.mNext = &this->m_pMember;
  }
  this->m_pMember.m_pPointer = member;
  if ( member )
  {
    v6 = member->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::GetInFormationNode>::mPrev;
    v6->mNext = p_m_pMember;
    p_m_pMember->mPrev = v6;
    this->m_pMember.mNext = &member->m_SafePointerList.mNode;
    member->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::GetInFormationNode>::mPrev = p_m_pMember;
  }
  if ( this->m_pMember.m_pPointer )
  {
    m_pPointer = (UFG::SimObject *)member->m_pOwner.m_pPointer;
    if ( m_pPointer )
      m_pPointer = (UFG::SimObject *)m_pPointer->mNode.mParent;
    p_m_pMemberSimObject = &this->m_pMemberSimObject;
    if ( this->m_pMemberSimObject.m_pPointer )
    {
      v9 = p_m_pMemberSimObject->mPrev;
      v10 = this->m_pMemberSimObject.mNext;
      v9->mNext = v10;
      v10->mPrev = v9;
      p_m_pMemberSimObject->mPrev = p_m_pMemberSimObject;
      this->m_pMemberSimObject.mNext = &this->m_pMemberSimObject;
    }
    this->m_pMemberSimObject.m_pPointer = m_pPointer;
    if ( m_pPointer )
    {
      v11 = m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
      v11->mNext = p_m_pMemberSimObject;
      p_m_pMemberSimObject->mPrev = v11;
      this->m_pMemberSimObject.mNext = &m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
      m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_m_pMemberSimObject;
    }
  }
  else
  {
    v12 = &this->m_pMemberSimObject;
    if ( this->m_pMemberSimObject.m_pPointer )
    {
      v13 = v12->mPrev;
      v14 = this->m_pMemberSimObject.mNext;
      v13->mNext = v14;
      v14->mPrev = v13;
      v12->mPrev = v12;
      this->m_pMemberSimObject.mNext = &this->m_pMemberSimObject;
    }
    this->m_pMemberSimObject.m_pPointer = 0i64;
  }
}

// File Line: 192
// RVA: 0x33F2E0
UFG::ComponentIDDesc *__fastcall UFG::FormationManagerComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::FormationManagerComponent::_DescInit )
  {
    UFG::FormationManagerComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::FormationManagerComponent::_DescInit = 1;
    UFG::FormationManagerComponent::_TypeUID = UFG::FormationManagerComponent::_TypeIDesc.mChildBitMask | (UFG::FormationManagerComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::FormationManagerComponent::_FormationManagerComponentTypeUID = UFG::FormationManagerComponent::_TypeIDesc.mChildBitMask | (UFG::FormationManagerComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::FormationManagerComponent::_TypeIDesc;
}

