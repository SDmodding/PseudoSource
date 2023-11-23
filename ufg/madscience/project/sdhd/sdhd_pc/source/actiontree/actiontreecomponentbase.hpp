// File Line: 145
// RVA: 0x297D30
char __fastcall UFG::ActionTreeComponentBase::ActionTreeMemoryData::SetValue(
        UFG::ActionTreeComponentBase::ActionTreeMemoryData *this,
        unsigned int value_uid,
        UFG::SimObject *value)
{
  __int64 v3; // rdx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v4; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rax

  v3 = value_uid - 700000;
  if ( (unsigned int)v3 >= this->m_pSimObjectPointerArray.size )
    return 0;
  v4 = &this->m_pSimObjectPointerArray.p[v3];
  if ( v4->m_pPointer )
  {
    mPrev = v4->mPrev;
    mNext = v4->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    v4->mPrev = v4;
    v4->mNext = v4;
  }
  v4->m_pPointer = value;
  if ( value )
  {
    v7 = value->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    v7->mNext = v4;
    v4->mPrev = v7;
    v4->mNext = &value->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    value->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = v4;
  }
  return 1;
}

// File Line: 151
// RVA: 0x297C10
char __fastcall UFG::ActionTreeComponentBase::ActionTreeMemoryData::SetValue(
        UFG::ActionTreeComponentBase::ActionTreeMemoryData *this,
        unsigned int value_uid,
        UFG::GetInFormationNode *value)
{
  __int64 v3; // rdx
  UFG::qSafePointer<UFG::GetInFormationNode,UFG::GetInFormationNode> *v4; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInFormationNode>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInFormationNode>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInFormationNode>,UFG::qSafePointerNodeList> *v7; // rax

  v3 = value_uid - 900000;
  if ( (unsigned int)v3 >= this->m_pGetInFormationNodePointerArray.size )
    return 0;
  v4 = &this->m_pGetInFormationNodePointerArray.p[v3];
  if ( v4->m_pPointer )
  {
    mPrev = v4->mPrev;
    mNext = v4->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    v4->mPrev = v4;
    v4->mNext = v4;
  }
  v4->m_pPointer = value;
  if ( value )
  {
    v7 = value->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::GetInFormationNode>::mPrev;
    v7->mNext = v4;
    v4->mPrev = v7;
    v4->mNext = &value->m_SafePointerList.mNode;
    value->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::GetInFormationNode>::mPrev = v4;
  }
  return 1;
}

// File Line: 154
// RVA: 0x297C70
char __fastcall UFG::ActionTreeComponentBase::ActionTreeMemoryData::SetValue(
        UFG::ActionTreeComponentBase::ActionTreeMemoryData *this,
        unsigned int value_uid,
        UFG::GetInPedFormationNode *value)
{
  __int64 v3; // rdx
  UFG::qSafePointer<UFG::GetInPedFormationNode,UFG::GetInPedFormationNode> *v4; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInPedFormationNode>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInPedFormationNode>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInPedFormationNode>,UFG::qSafePointerNodeList> *v7; // rax

  v3 = value_uid - 1000000;
  if ( (unsigned int)v3 >= this->m_pGetInPedFormationNodePointerArray.size )
    return 0;
  v4 = &this->m_pGetInPedFormationNodePointerArray.p[v3];
  if ( v4->m_pPointer )
  {
    mPrev = v4->mPrev;
    mNext = v4->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    v4->mPrev = v4;
    v4->mNext = v4;
  }
  v4->m_pPointer = value;
  if ( value )
  {
    v7 = value->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::GetInPedFormationNode>::mPrev;
    v7->mNext = v4;
    v4->mPrev = v7;
    v4->mNext = &value->m_SafePointerList.mNode;
    value->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::GetInPedFormationNode>::mPrev = v4;
  }
  return 1;
}

// File Line: 157
// RVA: 0x297CD0
char __fastcall UFG::ActionTreeComponentBase::ActionTreeMemoryData::SetValue(
        UFG::ActionTreeComponentBase::ActionTreeMemoryData *this,
        unsigned int value_uid,
        UFG::HasAttackRequestNode *value)
{
  __int64 v3; // rdx
  UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *v4; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v7; // rax

  v3 = value_uid - 1100000;
  if ( (unsigned int)v3 >= this->m_pHasAttackRequestNodePointerArray.size )
    return 0;
  v4 = &this->m_pHasAttackRequestNodePointerArray.p[v3];
  if ( v4->m_pPointer )
  {
    mPrev = v4->mPrev;
    mNext = v4->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    v4->mPrev = v4;
    v4->mNext = v4;
  }
  v4->m_pPointer = value;
  if ( value )
  {
    v7 = value->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::HasAttackRequestNode>::mPrev;
    v7->mNext = v4;
    v4->mPrev = v7;
    v4->mNext = &value->m_SafePointerList.mNode;
    value->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::HasAttackRequestNode>::mPrev = v4;
  }
  return 1;
}

