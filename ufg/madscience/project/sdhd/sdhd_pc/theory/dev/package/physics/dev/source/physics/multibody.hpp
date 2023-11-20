// File Line: 53
// RVA: 0x454B40
void __fastcall UFG::MultiBodyComponent::AddBody(UFG::MultiBodyComponent *this, UFG::RigidBody *body)
{
  UFG::MultiBodyComponent *v2; // rdi
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rax
  __int64 v4; // rsi
  unsigned int v5; // ebx
  unsigned int v6; // edx
  unsigned int v7; // edx
  UFG::qSafePointer<UFG::SimComponent,UFG::RigidBody> *v8; // rdx
  __int64 v9; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  __int64 *v13; // rcx
  _QWORD *v14; // rax
  __int64 *v15; // rcx
  _QWORD *v16; // rax
  __int64 *v17; // [rsp+28h] [rbp-18h]
  UFG::qList<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList,1,0> *v18; // [rsp+30h] [rbp-10h]
  UFG::RigidBody *v19; // [rsp+38h] [rbp-8h]

  v2 = this;
  v17 = (__int64 *)&v17;
  v18 = (UFG::qList<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList,1,0> *)&v17;
  v19 = body;
  if ( body )
  {
    v3 = body->m_SafePointerList.mNode.mPrev;
    v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v17;
    v17 = (__int64 *)v3;
    v18 = &body->m_SafePointerList;
    body->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v17;
  }
  v4 = this->mBodies.size;
  v5 = v4 + 1;
  v6 = this->mBodies.capacity;
  if ( (signed int)v4 + 1 > v6 )
  {
    if ( v6 )
      v7 = 2 * v6;
    else
      v7 = 1;
    for ( ; v7 < v5; v7 *= 2 )
      ;
    if ( v7 - v5 > 0x10000 )
      v7 = v4 + 65537;
    UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent>,0>::Reallocate(
      (UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent>,0> *)&this->mBodies,
      v7,
      "qArray.Add");
  }
  v2->mBodies.size = v5;
  v8 = &v2->mBodies.p[v4];
  v9 = (__int64)v19;
  if ( v8->m_pPointer )
  {
    v10 = v8->mPrev;
    v11 = v8->mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
    v8->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
  }
  v8->m_pPointer = (UFG::SimComponent *)v9;
  if ( v9 )
  {
    v12 = *(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **)(v9 + 8);
    v12->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
    v8->mPrev = v12;
    v8->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)(v9 + 8);
    *(_QWORD *)(v9 + 8) = v8;
  }
  if ( v19 )
  {
    v13 = v17;
    v14 = &v18->mNode.mPrev;
    v17[1] = (__int64)v18;
    *v14 = v13;
    v17 = (__int64 *)&v17;
    v18 = (UFG::qList<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList,1,0> *)&v17;
  }
  v15 = v17;
  v16 = &v18->mNode.mPrev;
  v17[1] = (__int64)v18;
  *v16 = v15;
}

// File Line: 57
// RVA: 0x454D30
void __fastcall UFG::MultiBodyComponent::AddConstraint(UFG::MultiBodyComponent *this, UFG::Constraint *constraint)
{
  UFG::MultiBodyComponent *v2; // rdi
  UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *v3; // rax
  __int64 v4; // rsi
  unsigned int v5; // ebx
  unsigned int v6; // edx
  unsigned int v7; // edx
  UFG::qSafePointer<UFG::Constraint,UFG::Constraint> *v8; // rdx
  __int64 v9; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *v12; // rax
  __int64 *v13; // rcx
  _QWORD *v14; // rax
  __int64 *v15; // rcx
  _QWORD *v16; // rax
  __int64 *v17; // [rsp+28h] [rbp-18h]
  UFG::qList<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList,1,0> *v18; // [rsp+30h] [rbp-10h]
  UFG::Constraint *v19; // [rsp+38h] [rbp-8h]

  v2 = this;
  v17 = (__int64 *)&v17;
  v18 = (UFG::qList<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList,1,0> *)&v17;
  v19 = constraint;
  if ( constraint )
  {
    v3 = constraint->m_SafePointerList.mNode.mPrev;
    v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *)&v17;
    v17 = (__int64 *)v3;
    v18 = &constraint->m_SafePointerList;
    constraint->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *)&v17;
  }
  v4 = this->mConstraints.size;
  v5 = v4 + 1;
  v6 = this->mConstraints.capacity;
  if ( (signed int)v4 + 1 > v6 )
  {
    if ( v6 )
      v7 = 2 * v6;
    else
      v7 = 1;
    for ( ; v7 < v5; v7 *= 2 )
      ;
    if ( v7 - v5 > 0x10000 )
      v7 = v4 + 65537;
    UFG::qArray<UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode>,0>::Reallocate(
      &this->mConstraints,
      v7,
      "qArray.Add");
  }
  v2->mConstraints.size = v5;
  v8 = &v2->mConstraints.p[v4];
  v9 = (__int64)v19;
  if ( v8->m_pPointer )
  {
    v10 = v8->mPrev;
    v11 = v8->mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *)&v8->mPrev;
    v8->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *)&v8->mPrev;
  }
  v8->m_pPointer = (UFG::Constraint *)v9;
  if ( v9 )
  {
    v12 = *(UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> **)(v9 + 8);
    v12->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *)&v8->mPrev;
    v8->mPrev = v12;
    v8->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *)(v9 + 8);
    *(_QWORD *)(v9 + 8) = v8;
  }
  if ( v19 )
  {
    v13 = v17;
    v14 = &v18->mNode.mPrev;
    v17[1] = (__int64)v18;
    *v14 = v13;
    v17 = (__int64 *)&v17;
    v18 = (UFG::qList<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList,1,0> *)&v17;
  }
  v15 = v17;
  v16 = &v18->mNode.mPrev;
  v17[1] = (__int64)v18;
  *v16 = v15;
}

