// File Line: 137
// RVA: 0x386490
void __fastcall UFG::FormationSlot::SetFormationMember(UFG::FormationSlot *this, UFG::GetInFormationNode *member)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInFormationNode>,UFG::qSafePointerNodeList> *v2; // r9
  UFG::FormationSlot *v3; // r10
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInFormationNode>,UFG::qSafePointerNodeList> *v4; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInFormationNode>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInFormationNode>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::SimComponent *v7; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v8; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v12; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rax

  v2 = (UFG::qNode<UFG::qSafePointerBase<UFG::GetInFormationNode>,UFG::qSafePointerNodeList> *)&this->m_pMember.mPrev;
  v3 = this;
  if ( this->m_pMember.m_pPointer )
  {
    v4 = v2->mPrev;
    v5 = this->m_pMember.mNext;
    v4->mNext = v5;
    v5->mPrev = v4;
    v2->mPrev = v2;
    this->m_pMember.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::GetInFormationNode>,UFG::qSafePointerNodeList> *)&this->m_pMember.mPrev;
  }
  this->m_pMember.m_pPointer = member;
  if ( member )
  {
    v6 = member->m_SafePointerList.mNode.mPrev;
    v6->mNext = v2;
    v2->mPrev = v6;
    this->m_pMember.mNext = &member->m_SafePointerList.mNode;
    member->m_SafePointerList.mNode.mPrev = v2;
  }
  if ( this->m_pMember.m_pPointer )
  {
    v7 = member->m_pOwner.m_pPointer;
    if ( v7 )
      v7 = (UFG::SimComponent *)v7->m_pSimObject;
    v8 = &this->m_pMemberSimObject;
    if ( this->m_pMemberSimObject.m_pPointer )
    {
      v9 = v8->mPrev;
      v10 = v3->m_pMemberSimObject.mNext;
      v9->mNext = v10;
      v10->mPrev = v9;
      v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v8->mPrev;
      v3->m_pMemberSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->m_pMemberSimObject.mPrev;
    }
    v3->m_pMemberSimObject.m_pPointer = (UFG::SimObject *)v7;
    if ( v7 )
    {
      v11 = v7->m_SafePointerList.mNode.mPrev;
      v11->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v8;
      v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v11;
      v3->m_pMemberSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7->m_SafePointerList;
      v7->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v8;
    }
  }
  else
  {
    v12 = &this->m_pMemberSimObject;
    if ( this->m_pMemberSimObject.m_pPointer )
    {
      v13 = v12->mPrev;
      v14 = v3->m_pMemberSimObject.mNext;
      v13->mNext = v14;
      v14->mPrev = v13;
      v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v12->mPrev;
      v3->m_pMemberSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->m_pMemberSimObject.mPrev;
    }
    v3->m_pMemberSimObject.m_pPointer = 0i64;
  }
}

// File Line: 192
// RVA: 0x33F2E0
UFG::ComponentIDDesc *__fastcall UFG::FormationManagerComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::FormationManagerComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::FormationManagerComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::FormationManagerComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::FormationManagerComponent::_DescInit = 1;
    UFG::FormationManagerComponent::_TypeUID = UFG::FormationManagerComponent::_TypeIDesc.mChildBitMask | (UFG::FormationManagerComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::FormationManagerComponent::_FormationManagerComponentTypeUID = UFG::FormationManagerComponent::_TypeIDesc.mChildBitMask | (UFG::FormationManagerComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::FormationManagerComponent::_TypeIDesc;
}

