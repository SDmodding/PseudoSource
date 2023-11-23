// File Line: 53
// RVA: 0x454B40
void __fastcall UFG::MultiBodyComponent::AddBody(UFG::MultiBodyComponent *this, UFG::RigidBody *body)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rax
  __int64 size; // rsi
  unsigned int v5; // ebx
  unsigned int capacity; // edx
  unsigned int v7; // edx
  UFG::qSafePointer<UFG::SimComponent,UFG::RigidBody> *v8; // rdx
  __int64 v9; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  __int64 *v13; // rcx
  _QWORD *p_mPrev; // rax
  __int64 *v15; // rcx
  _QWORD *v16; // rax
  __int64 *v17; // [rsp+28h] [rbp-18h] BYREF
  UFG::qList<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList,1,0> *p_m_SafePointerList; // [rsp+30h] [rbp-10h]
  UFG::RigidBody *v19; // [rsp+38h] [rbp-8h]

  v17 = (__int64 *)&v17;
  p_m_SafePointerList = (UFG::qList<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList,1,0> *)&v17;
  v19 = body;
  if ( body )
  {
    mPrev = body->m_SafePointerList.mNode.mPrev;
    mPrev->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v17;
    v17 = (__int64 *)mPrev;
    p_m_SafePointerList = &body->m_SafePointerList;
    body->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v17;
  }
  size = this->mBodies.size;
  v5 = size + 1;
  capacity = this->mBodies.capacity;
  if ( (int)size + 1 > capacity )
  {
    if ( capacity )
      v7 = 2 * capacity;
    else
      v7 = 1;
    for ( ; v7 < v5; v7 *= 2 )
      ;
    if ( v7 - v5 > 0x10000 )
      v7 = size + 65537;
    UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent>,0>::Reallocate(
      (UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent>,0> *)&this->mBodies,
      v7,
      "qArray.Add");
  }
  this->mBodies.size = v5;
  v8 = &this->mBodies.p[size];
  v9 = (__int64)v19;
  if ( v8->m_pPointer )
  {
    v10 = v8->mPrev;
    mNext = v8->mNext;
    v10->mNext = mNext;
    mNext->mPrev = v10;
    v8->mPrev = v8;
    v8->mNext = v8;
  }
  v8->m_pPointer = (UFG::SimComponent *)v9;
  if ( v9 )
  {
    v12 = *(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **)(v9 + 8);
    v12->mNext = v8;
    v8->mPrev = v12;
    v8->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)(v9 + 8);
    *(_QWORD *)(v9 + 8) = v8;
  }
  if ( v19 )
  {
    v13 = v17;
    p_mPrev = &p_m_SafePointerList->mNode.mPrev;
    v17[1] = (__int64)p_m_SafePointerList;
    *p_mPrev = v13;
    v17 = (__int64 *)&v17;
    p_m_SafePointerList = (UFG::qList<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList,1,0> *)&v17;
  }
  v15 = v17;
  v16 = &p_m_SafePointerList->mNode.mPrev;
  v17[1] = (__int64)p_m_SafePointerList;
  *v16 = v15;
}

// File Line: 57
// RVA: 0x454D30
void __fastcall UFG::MultiBodyComponent::AddConstraint(UFG::MultiBodyComponent *this, UFG::Constraint *constraint)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *mPrev; // rax
  __int64 size; // rsi
  unsigned int v5; // ebx
  unsigned int capacity; // edx
  unsigned int v7; // edx
  UFG::qSafePointer<UFG::Constraint,UFG::Constraint> *v8; // rdx
  __int64 v9; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *v12; // rax
  __int64 *v13; // rcx
  _QWORD *p_mPrev; // rax
  __int64 *v15; // rcx
  _QWORD *v16; // rax
  __int64 *v17; // [rsp+28h] [rbp-18h] BYREF
  UFG::qList<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList,1,0> *p_m_SafePointerList; // [rsp+30h] [rbp-10h]
  UFG::Constraint *v19; // [rsp+38h] [rbp-8h]

  v17 = (__int64 *)&v17;
  p_m_SafePointerList = (UFG::qList<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList,1,0> *)&v17;
  v19 = constraint;
  if ( constraint )
  {
    mPrev = constraint->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::Constraint>::mPrev;
    mPrev->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *)&v17;
    v17 = (__int64 *)mPrev;
    p_m_SafePointerList = &constraint->m_SafePointerList;
    constraint->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::Constraint>::mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *)&v17;
  }
  size = this->mConstraints.size;
  v5 = size + 1;
  capacity = this->mConstraints.capacity;
  if ( (int)size + 1 > capacity )
  {
    if ( capacity )
      v7 = 2 * capacity;
    else
      v7 = 1;
    for ( ; v7 < v5; v7 *= 2 )
      ;
    if ( v7 - v5 > 0x10000 )
      v7 = size + 65537;
    UFG::qArray<UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode>,0>::Reallocate(
      &this->mConstraints,
      v7,
      "qArray.Add");
  }
  this->mConstraints.size = v5;
  v8 = &this->mConstraints.p[size];
  v9 = (__int64)v19;
  if ( v8->m_pPointer )
  {
    v10 = v8->mPrev;
    mNext = v8->mNext;
    v10->mNext = mNext;
    mNext->mPrev = v10;
    v8->mPrev = v8;
    v8->mNext = v8;
  }
  v8->m_pPointer = (UFG::Constraint *)v9;
  if ( v9 )
  {
    v12 = *(UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> **)(v9 + 8);
    v12->mNext = v8;
    v8->mPrev = v12;
    v8->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *)(v9 + 8);
    *(_QWORD *)(v9 + 8) = v8;
  }
  if ( v19 )
  {
    v13 = v17;
    p_mPrev = &p_m_SafePointerList->mNode.mPrev;
    v17[1] = (__int64)p_m_SafePointerList;
    *p_mPrev = v13;
    v17 = (__int64 *)&v17;
    p_m_SafePointerList = (UFG::qList<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList,1,0> *)&v17;
  }
  v15 = v17;
  v16 = &p_m_SafePointerList->mNode.mPrev;
  v17[1] = (__int64)p_m_SafePointerList;
  *v16 = v15;
}

