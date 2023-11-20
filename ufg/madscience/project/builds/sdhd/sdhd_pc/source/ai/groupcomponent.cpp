// File Line: 43
// RVA: 0x337F20
void __fastcall UFG::GroupFollower::~GroupFollower(UFG::GroupFollower *this)
{
  UFG::qSafePointer<UFG::GroupComponent,UFG::GroupComponent> *v1; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v2; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v3; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v5; // rax

  this->vfptr = (UFG::GroupFollowerVtbl *)&UFG::GroupFollower::`vftable;
  v1 = &this->mLeader;
  if ( this->mLeader.m_pPointer )
  {
    v2 = v1->mPrev;
    v3 = v1->mNext;
    v2->mNext = v3;
    v3->mPrev = v2;
    v1->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *)&v1->mPrev;
    v1->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *)&v1->mPrev;
  }
  v1->m_pPointer = 0i64;
  v4 = v1->mPrev;
  v5 = v1->mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  v1->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *)&v1->mPrev;
}

// File Line: 52
// RVA: 0x3583B0
void __fastcall UFG::GroupFollower::FollowLeader(UFG::GroupFollower *this, UFG::GroupComponent *pFollower, UFG::GroupComponent *pLeader)
{
  UFG::GroupFollower *v3; // rdi
  UFG::GroupComponent *v4; // rcx
  UFG::GroupComponent *v5; // rbx
  UFG::GroupComponent *v6; // rsi
  UFG::qSafePointer<UFG::GroupComponent,UFG::GroupComponent> *v7; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qSafePointer<UFG::GroupComponent,UFG::GroupComponent> *v10; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v13; // rax

  v3 = this;
  v4 = this->mLeader.m_pPointer;
  v5 = pLeader;
  v6 = pFollower;
  if ( v4 != pLeader )
  {
    if ( v4 )
    {
      UFG::GroupLeader::Unregister(&v4->mGroupLeader, pFollower);
      v7 = &v3->mLeader;
      if ( v3->mLeader.m_pPointer )
      {
        v8 = v7->mPrev;
        v9 = v3->mLeader.mNext;
        v8->mNext = v9;
        v9->mPrev = v8;
        v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
        v3->mLeader.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *)&v3->mLeader.mPrev;
      }
      v3->mLeader.m_pPointer = 0i64;
    }
    if ( v5 && UFG::GroupLeader::Register(&v5->mGroupLeader, v6) )
    {
      v10 = &v3->mLeader;
      if ( v3->mLeader.m_pPointer )
      {
        v11 = v10->mPrev;
        v12 = v3->mLeader.mNext;
        v11->mNext = v12;
        v12->mPrev = v11;
        v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *)&v10->mPrev;
        v3->mLeader.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *)&v3->mLeader.mPrev;
      }
      v3->mLeader.m_pPointer = v5;
      v13 = v5->m_SafePointerList.mNode.mPrev;
      v13->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *)&v10->mPrev;
      v10->mPrev = v13;
      v3->mLeader.mNext = &v5->m_SafePointerList.mNode;
      v5->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *)&v10->mPrev;
    }
  }
}

// File Line: 74
// RVA: 0x32F470
void __fastcall UFG::GroupLeader::GroupLeader(UFG::GroupLeader *this)
{
  UFG::GroupLeader *v1; // rdi
  UFG::qFixedArray<UFG::qSafePointer<UFG::GroupComponent,UFG::GroupComponent>,4> *v2; // rbx

  v1 = this;
  this->vfptr = (UFG::GroupLeaderVtbl *)&UFG::GroupLeader::`vftable;
  v2 = &this->mFollowers;
  `eh vector constructor iterator(
    this->mFollowers.p,
    0x18ui64,
    4,
    (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>);
  v2->size = 0;
  v1->mFormationProfile = 0i64;
}

// File Line: 78
// RVA: 0x337F90
void __fastcall UFG::GroupLeader::~GroupLeader(UFG::GroupLeader *this)
{
  UFG::qFixedArray<UFG::qSafePointer<UFG::GroupComponent,UFG::GroupComponent>,4> *v1; // rcx

  this->vfptr = (UFG::GroupLeaderVtbl *)&UFG::GroupLeader::`vftable;
  v1 = &this->mFollowers;
  v1->size = 0;
  `eh vector destructor iterator(
    v1->p,
    0x18ui64,
    4,
    (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
}

// File Line: 82
// RVA: 0x382A80
void __fastcall UFG::GroupLeader::Reset(UFG::GroupLeader *this)
{
  UFG::GroupLeader *v1; // rdi
  unsigned int v2; // edx
  unsigned int v3; // er8
  char *v4; // rdx
  UFG::GroupComponent *v5; // r9
  __int64 v6; // rcx
  _QWORD *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v8; // rax
  unsigned int v9; // ebx
  UFG::GroupComponent *v10; // rcx
  unsigned int v11; // eax
  unsigned int v12; // [rsp+40h] [rbp-78h]
  char ptr[16]; // [rsp+48h] [rbp-70h]
  UFG::GroupComponent *v14[9]; // [rsp+58h] [rbp-60h]

  v1 = this;
  if ( this->mFollowers.size )
  {
    `eh vector constructor iterator(
      ptr,
      0x18ui64,
      4,
      (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>);
    v2 = 0;
    v12 = 0;
    if ( v1->mFollowers.size )
    {
      v12 = v1->mFollowers.size;
      v3 = 0;
      do
      {
        v4 = &ptr[24 * v3];
        v5 = v1->mFollowers.p[v3].m_pPointer;
        if ( *((_QWORD *)v4 + 2) )
        {
          v6 = *(_QWORD *)v4;
          v7 = (_QWORD *)*((_QWORD *)v4 + 1);
          *(_QWORD *)(v6 + 8) = v7;
          *v7 = v6;
          *(_QWORD *)v4 = v4;
          *((_QWORD *)v4 + 1) = v4;
        }
        *((_QWORD *)v4 + 2) = v5;
        if ( v5 )
        {
          v8 = v5->m_SafePointerList.mNode.mPrev;
          v8->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *)v4;
          *(_QWORD *)v4 = v8;
          *((_QWORD *)v4 + 1) = (char *)v5 + 80;
          v5->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *)v4;
        }
        ++v3;
      }
      while ( v3 < v1->mFollowers.size );
      v2 = v12;
    }
    v9 = 0;
    if ( v2 )
    {
      do
      {
        v10 = v14[3 * v9];
        if ( v10 )
        {
          UFG::GroupComponent::MakeSingle(v10, 1);
          v2 = v12;
        }
        ++v9;
      }
      while ( v9 < v2 );
    }
    `eh vector destructor iterator(
      ptr,
      0x18ui64,
      4,
      (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
  }
  v1->mFollowers.size = 0;
  if ( v1->mFormationProfile )
  {
    v11 = UFG::gpGroupManager->mGroupTotals.p[0];
    if ( v11 )
      UFG::gpGroupManager->mGroupTotals.p[0] = v11 - 1;
  }
  v1->mFormationProfile = 0i64;
}

// File Line: 111
// RVA: 0x38A690
void __fastcall UFG::GroupLeader::UnregisterFarFollowers(UFG::GroupLeader *this, UFG::qVector3 *leaderPos, const float distanceSqr)
{
  UFG::qVector3 *v3; // rbp
  UFG::GroupLeader *v4; // rbx
  unsigned int v5; // er8
  char *v6; // rdx
  UFG::GroupComponent *v7; // r9
  __int64 v8; // rcx
  _QWORD *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v10; // rax
  unsigned int v11; // esi
  float v12; // xmm6_4
  float v13; // xmm7_4
  UFG::PedSpawningInfo *v14; // rcx
  UFG::TransformNodeComponent *v15; // rbx
  UFG::GroupComponent *v16; // rbx
  UFG::GroupComponent *v17; // rcx
  __int64 *v18; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v19; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v20; // rax
  float v21; // [rsp+30h] [rbp-D8h]
  float v22; // [rsp+34h] [rbp-D4h]
  unsigned int v23; // [rsp+50h] [rbp-B8h]
  char ptr[16]; // [rsp+58h] [rbp-B0h]
  UFG::GroupComponent *pFollower[15]; // [rsp+68h] [rbp-A0h]

  v3 = leaderPos;
  v4 = this;
  if ( this->mFollowers.size )
  {
    `eh vector constructor iterator(
      ptr,
      0x18ui64,
      4,
      (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>);
    v23 = 0;
    if ( v4->mFollowers.size )
    {
      v23 = v4->mFollowers.size;
      v5 = 0;
      do
      {
        v6 = &ptr[24 * v5];
        v7 = v4->mFollowers.p[v5].m_pPointer;
        if ( *((_QWORD *)v6 + 2) )
        {
          v8 = *(_QWORD *)v6;
          v9 = (_QWORD *)*((_QWORD *)v6 + 1);
          *(_QWORD *)(v8 + 8) = v9;
          *v9 = v8;
          *(_QWORD *)v6 = v6;
          *((_QWORD *)v6 + 1) = v6;
        }
        *((_QWORD *)v6 + 2) = v7;
        if ( v7 )
        {
          v10 = v7->m_SafePointerList.mNode.mPrev;
          v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *)v6;
          *(_QWORD *)v6 = v10;
          *((_QWORD *)v6 + 1) = (char *)v7 + 80;
          v7->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *)v6;
        }
        ++v5;
      }
      while ( v5 < v4->mFollowers.size );
    }
    v11 = 0;
    if ( v23 > 0 )
    {
      v12 = v22;
      v13 = v21;
      do
      {
        v14 = pFollower[3 * v11]->mOwner;
        if ( v14 )
        {
          v15 = v14->mTransformNodePtr;
          if ( !v15 || v14->mActiveStatus == 2 )
            v15 = v14->mProxyTransformNode;
          if ( v15 || (v15 = v14->mProxyTransformNode) != 0i64 )
          {
            UFG::TransformNodeComponent::UpdateWorldTransform(v15);
            v13 = v15->mWorldTransform.v3.x;
            v12 = v15->mWorldTransform.v3.y;
          }
        }
        if ( (float)((float)((float)(v3->x - v13) * (float)(v3->x - v13))
                   + (float)((float)(v3->y - v12) * (float)(v3->y - v12))) > distanceSqr )
        {
          v16 = pFollower[3 * v11];
          v17 = v16->mGroupFollower.mLeader.m_pPointer;
          if ( v17 )
          {
            UFG::GroupLeader::Unregister(&v17->mGroupLeader, pFollower[3 * v11]);
            v18 = (__int64 *)&v16->mGroupFollower.mLeader;
            if ( v16->mGroupFollower.mLeader.m_pPointer )
            {
              v19 = (UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *)*v18;
              v20 = v16->mGroupFollower.mLeader.mNext;
              v19->mNext = v20;
              v20->mPrev = v19;
              *v18 = (__int64)v18;
              v16->mGroupFollower.mLeader.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *)&v16->mGroupFollower.mLeader.mPrev;
            }
            v16->mGroupFollower.mLeader.m_pPointer = 0i64;
          }
          UFG::GroupLeader::Reset(&v16->mGroupLeader);
          v16->mFlags = 1;
          if ( v16->mGroupLeader.mFormationProfile != &::ptr )
          {
            UFG::GroupLeader::Reset(&v16->mGroupLeader);
            v16->mGroupLeader.mFormationProfile = &::ptr;
            ++UFG::gpGroupManager->mGroupTotals.p[0];
          }
          v16->mFlags |= 1u;
        }
        ++v11;
      }
      while ( v11 < v23 );
    }
    `eh vector destructor iterator(
      ptr,
      0x18ui64,
      4,
      (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
  }
}

// File Line: 130
// RVA: 0x380810
char __fastcall UFG::GroupLeader::Register(UFG::GroupLeader *this, UFG::GroupComponent *pFollower)
{
  UFG::GroupComponent *v2; // r9
  UFG::GroupLeader *v3; // r8
  UFG::PedFormationProfile *v4; // rax
  unsigned int *v5; // rdx
  unsigned int v6; // eax
  signed __int64 v7; // rdx
  bool v8; // zf
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v9; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v12; // rax

  v2 = pFollower;
  v3 = this;
  if ( !pFollower )
    return 0;
  v4 = this->mFormationProfile;
  if ( v4 )
  {
    if ( this->mFollowers.size >= v4->mMaxFollowers )
      return 0;
  }
  v5 = &UFG::gpGroupManager->mProfiles.size + this->mFollowers.size;
  v6 = v5[203];
  if ( v6 )
    v5[203] = v6 - 1;
  ++this->mFollowers.size;
  v7 = this->mFollowers.size - 1 + 2 * (this->mFollowers.size - 1 + 1i64);
  v8 = *((_QWORD *)&this->mFollowers.p[0].mPrev + v7) == 0i64;
  v9 = (UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *)&(&this->vfptr)[v7];
  if ( !v8 )
  {
    v10 = v9->mPrev;
    v11 = v9->mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    v9->mPrev = v9;
    v9->mNext = v9;
  }
  v9[1].mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *)v2;
  v12 = v2->m_SafePointerList.mNode.mPrev;
  v12->mNext = v9;
  v9->mPrev = v12;
  v9->mNext = &v2->m_SafePointerList.mNode;
  v2->m_SafePointerList.mNode.mPrev = v9;
  ++UFG::gpGroupManager->mGroupTotals.p[v3->mFollowers.size];
  return 1;
}

// File Line: 148
// RVA: 0x38A3B0
char __fastcall UFG::GroupLeader::Unregister(UFG::GroupLeader *this, UFG::GroupComponent *pFollower)
{
  UFG::GroupLeader *v2; // r10
  __int64 v3; // r9
  signed __int64 v4; // r8
  UFG::GroupComponent **v5; // rax
  unsigned int *v7; // rdx
  unsigned int v8; // eax
  signed __int64 v9; // r8
  UFG::qSafePointer<UFG::GroupComponent,UFG::GroupComponent> *v10; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qSafePointer<UFG::GroupComponent,UFG::GroupComponent> *v13; // rdx
  UFG::GroupComponent *v14; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v17; // rax

  v2 = this;
  if ( !pFollower )
    return 0;
  v3 = this->mFollowers.size;
  v4 = 0i64;
  if ( !(_DWORD)v3 )
    return 0;
  v5 = &this->mFollowers.p[0].m_pPointer;
  while ( pFollower != *v5 )
  {
    v4 = (unsigned int)(v4 + 1);
    v5 += 3;
    if ( (unsigned int)v4 >= (unsigned int)v3 )
      return 0;
  }
  v7 = &UFG::gpGroupManager->mProfiles.size + v3;
  v8 = v7[203];
  if ( v8 )
    v7[203] = v8 - 1;
  v9 = v4;
  v10 = &this->mFollowers.p[v9];
  if ( v10->m_pPointer )
  {
    v11 = v10->mPrev;
    v12 = v10->mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *)&v10->mPrev;
    v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *)&v10->mPrev;
  }
  v10->m_pPointer = 0i64;
  --v2->mFollowers.size;
  v13 = &v2->mFollowers.p[v9];
  v14 = (UFG::GroupComponent *)*((_QWORD *)&v2->mFollowers.size + 3 * (v2->mFollowers.size + 1i64));
  if ( v13->m_pPointer )
  {
    v15 = v13->mPrev;
    v16 = v13->mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    v13->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *)&v13->mPrev;
    v13->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *)&v13->mPrev;
  }
  v13->m_pPointer = v14;
  if ( v14 )
  {
    v17 = v14->m_SafePointerList.mNode.mPrev;
    v17->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *)&v13->mPrev;
    v13->mPrev = v17;
    v13->mNext = &v14->m_SafePointerList.mNode;
    v14->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *)&v13->mPrev;
  }
  ++UFG::gpGroupManager->mGroupTotals.p[v2->mFollowers.size];
  return 1;
}

// File Line: 247
// RVA: 0x36C920
bool __fastcall UFG::GroupComponent::JoinGroup(UFG::SimObject *pLeaderSim, UFG::SimObject *pFollowerSim, UFG::PedFormationProfile *pFormation)
{
  UFG::PedFormationProfile *v3; // rbx
  UFG::SimObject *v4; // rdi
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v5; // rsi
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v6; // rax
  UFG::GroupComponent *v7; // rdi

  v3 = pFormation;
  v4 = pFollowerSim;
  if ( !pLeaderSim || !pFollowerSim || !pFormation )
    return 0;
  v5 = UFG::GroupComponent::GetGroupComponent(pLeaderSim);
  v6 = UFG::GroupComponent::GetGroupComponent(v4);
  v7 = (UFG::GroupComponent *)v6;
  if ( !v5 || !v6 )
    return 0;
  if ( UFG::GroupComponent::JoinExistingGroup((UFG::GroupComponent *)v6, (UFG::GroupComponent *)v5, v3) )
    return 1;
  UFG::GroupComponent::Reset((UFG::GroupComponent *)v5);
  return UFG::GroupComponent::JoinNewGroup(v7, (UFG::GroupComponent *)v5, v3);
}

// File Line: 277
// RVA: 0x14AEB40
__int64 dynamic_initializer_for__UFG::GroupComponent::s_GroupComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::GroupComponent::s_GroupComponentList__);
}

// File Line: 278
// RVA: 0x14ACF90
__int64 dynamic_initializer_for__UFG::GroupComponent::_TypeIDesc__()
{
  UFG::ComponentIDDesc *v0; // rax
  __int64 result; // rax

  v0 = UFG::GroupComponent::AccessComponentDesc();
  *(_DWORD *)&UFG::GroupComponent::_TypeIDesc.mBaseTypeIndex = *(_DWORD *)&v0->mBaseTypeIndex;
  UFG::GroupComponent::_TypeIDesc.mChildBitMask = v0->mChildBitMask;
  result = v0->mChildren;
  UFG::GroupComponent::_TypeIDesc.mChildren = result;
  return result;
}

// File Line: 284
// RVA: 0x32F380
void __fastcall UFG::GroupComponent::GroupComponent(UFG::GroupComponent *this, unsigned int name_uid)
{
  UFG::GroupComponent *v2; // rsi
  UFG::qNode<UFG::GroupComponent,UFG::GroupComponent> *v3; // rdi
  UFG::qNode<UFG::GroupComponent,UFG::GroupComponent> *v4; // rax
  UFG::qSafePointer<UFG::GroupComponent,UFG::GroupComponent> *v5; // [rsp+68h] [rbp+20h]

  v2 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v2->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::UpdateInterface::`vftable;
  v3 = (UFG::qNode<UFG::GroupComponent,UFG::GroupComponent> *)&v2->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  UFG::qSafePointerNode<UFG::GroupComponent>::qSafePointerNode<UFG::GroupComponent>((UFG::qSafePointerNode<UFG::GroupComponent> *)&v2->vfptr);
  v2->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::GroupComponent::`vftable{for `UFG::SimComponent};
  v2->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::GroupComponent::`vftable{for `UFG::UpdateInterface};
  v2->vfptr = (UFG::qSafePointerNode<UFG::GroupComponent>Vtbl *)&UFG::GroupComponent::`vftable{for `UFG::qSafePointerNode<UFG::GroupComponent>};
  UFG::GroupLeader::GroupLeader(&v2->mGroupLeader);
  v2->mGroupFollower.vfptr = (UFG::GroupFollowerVtbl *)&UFG::GroupFollower::`vftable;
  v5 = &v2->mGroupFollower.mLeader;
  v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v5->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v2->mGroupFollower.mLeader.m_pPointer = 0i64;
  v2->mOwner = 0i64;
  v2->mFlags = 1;
  v4 = UFG::GroupComponent::s_GroupComponentList.mNode.mPrev;
  UFG::GroupComponent::s_GroupComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::GroupComponent,UFG::GroupComponent> *)&v2->mPrev;
  v3->mPrev = v4;
  v2->mNext = (UFG::qNode<UFG::GroupComponent,UFG::GroupComponent> *)&UFG::GroupComponent::s_GroupComponentList;
  UFG::GroupComponent::s_GroupComponentList.mNode.mPrev = (UFG::qNode<UFG::GroupComponent,UFG::GroupComponent> *)&v2->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v2->vfptr,
    UFG::GroupComponent::_GroupComponentTypeUID,
    "GroupComponent");
}

// File Line: 290
// RVA: 0x337DA0
void __fastcall UFG::GroupComponent::~GroupComponent(UFG::GroupComponent *this)
{
  UFG::GroupComponent *v1; // rdi
  UFG::qSafePointerNode<UFG::ParkourHandle> *v2; // rbx
  UFG::qNode<UFG::GroupComponent,UFG::GroupComponent> *v3; // rsi
  UFG::qNode<UFG::GroupComponent,UFG::GroupComponent> *v4; // rcx
  UFG::qNode<UFG::GroupComponent,UFG::GroupComponent> *v5; // rax
  UFG::qSafePointer<UFG::GroupComponent,UFG::GroupComponent> *v6; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *v11; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qNode<UFG::GroupComponent,UFG::GroupComponent> *v14; // rcx
  UFG::qNode<UFG::GroupComponent,UFG::GroupComponent> *v15; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::GroupComponent::`vftable{for `UFG::SimComponent};
  this->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::GroupComponent::`vftable{for `UFG::UpdateInterface};
  v2 = (UFG::qSafePointerNode<UFG::ParkourHandle> *)&this->vfptr;
  this->vfptr = (UFG::qSafePointerNode<UFG::GroupComponent>Vtbl *)&UFG::GroupComponent::`vftable{for `UFG::qSafePointerNode<UFG::GroupComponent>};
  UFG::GroupComponent::Reset(this);
  if ( v1 == UFG::GroupComponent::s_GroupComponentpCurrentIterator )
    UFG::GroupComponent::s_GroupComponentpCurrentIterator = (UFG::GroupComponent *)&v1->mPrev[-6];
  v3 = (UFG::qNode<UFG::GroupComponent,UFG::GroupComponent> *)&v1->mPrev;
  v4 = v1->mPrev;
  v5 = v1->mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  v3->mPrev = v3;
  v3->mNext = v3;
  v1->mGroupFollower.vfptr = (UFG::GroupFollowerVtbl *)&UFG::GroupFollower::`vftable;
  v6 = &v1->mGroupFollower.mLeader;
  if ( v1->mGroupFollower.mLeader.m_pPointer )
  {
    v7 = v6->mPrev;
    v8 = v1->mGroupFollower.mLeader.mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
    v1->mGroupFollower.mLeader.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *)&v1->mGroupFollower.mLeader.mPrev;
  }
  v1->mGroupFollower.mLeader.m_pPointer = 0i64;
  v9 = v6->mPrev;
  v10 = v1->mGroupFollower.mLeader.mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v1->mGroupFollower.mLeader.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *)&v1->mGroupFollower.mLeader.mPrev;
  v1->mGroupLeader.vfptr = (UFG::GroupLeaderVtbl *)&UFG::GroupLeader::`vftable;
  v1->mGroupLeader.mFollowers.size = 0;
  `eh vector destructor iterator(
    v1->mGroupLeader.mFollowers.p,
    0x18ui64,
    4,
    (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
  v2->vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)&UFG::qSafePointerNode<UFG::GroupComponent>::`vftable;
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull(v2);
  v11 = &v2->m_SafePointerList;
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes(v11);
  v12 = v11->mNode.mPrev;
  v13 = v11->mNode.mNext;
  v12->mNext = v13;
  v13->mPrev = v12;
  v11->mNode.mPrev = &v11->mNode;
  v11->mNode.mNext = &v11->mNode;
  v14 = v3->mPrev;
  v15 = v1->mNext;
  v14->mNext = v15;
  v15->mPrev = v14;
  v3->mPrev = v3;
  v1->mNext = (UFG::qNode<UFG::GroupComponent,UFG::GroupComponent> *)&v1->mPrev;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 362
// RVA: 0x36B4D0
bool __fastcall UFG::GroupComponent::IsLeader(UFG::GroupComponent *this)
{
  return this->mGroupLeader.mFormationProfile && this->mGroupLeader.mFollowers.size;
}

// File Line: 367
// RVA: 0x36A9E0
_BOOL8 __fastcall UFG::GroupComponent::IsFollower(UFG::GroupComponent *this)
{
  return this->mGroupFollower.mLeader.m_pPointer != 0i64;
}

// File Line: 377
// RVA: 0x36AA20
bool __fastcall UFG::GroupComponent::IsFormationFull(UFG::GroupComponent *this)
{
  UFG::PedFormationProfile *v1; // rax
  bool result; // al

  result = 0;
  if ( this->mGroupLeader.mFormationProfile )
  {
    v1 = this->mGroupLeader.mFormationProfile;
    if ( v1 )
    {
      if ( this->mGroupLeader.mFollowers.size >= v1->mMaxFollowers )
        result = 1;
    }
  }
  return result;
}

// File Line: 387
// RVA: 0x36D900
void __fastcall UFG::GroupComponent::MakeSingle(UFG::GroupComponent *this, const bool isAllowedToJoinGroups)
{
  bool v2; // si
  UFG::GroupComponent *v3; // rbx

  v2 = isAllowedToJoinGroups;
  v3 = this;
  UFG::GroupComponent::Reset(this);
  if ( v3->mGroupLeader.mFormationProfile != &ptr )
  {
    UFG::GroupLeader::Reset(&v3->mGroupLeader);
    v3->mGroupLeader.mFormationProfile = &ptr;
    ++UFG::gpGroupManager->mGroupTotals.p[0];
  }
  if ( v2 )
    v3->mFlags |= 1u;
  else
    v3->mFlags &= 0xFFFFFFFE;
}

// File Line: 393
// RVA: 0x386550
void __fastcall UFG::GroupComponent::SetFormationProfile(UFG::GroupComponent *this, UFG::PedFormationProfile *pProfile)
{
  UFG::PedFormationProfile *v2; // rdi
  UFG::GroupComponent *v3; // rbx

  v2 = pProfile;
  v3 = this;
  UFG::GroupComponent::Reset(this);
  if ( v3->mGroupLeader.mFormationProfile != v2 )
  {
    UFG::GroupLeader::Reset(&v3->mGroupLeader);
    v3->mGroupLeader.mFormationProfile = v2;
    if ( v2 )
      ++UFG::gpGroupManager->mGroupTotals.p[0];
  }
}

// File Line: 409
// RVA: 0x38A5F0
void __fastcall UFG::GroupComponent::UnregisterFarFollowers(UFG::GroupComponent *this, const float distanceSqr)
{
  UFG::PedSpawningInfo *v2; // rax
  UFG::GroupComponent *v3; // rdi
  float v4; // xmm6_4
  UFG::TransformNodeComponent *v5; // rbx
  float v6; // xmm1_4
  float v7; // xmm0_4
  UFG::qVector3 leaderPos; // [rsp+20h] [rbp-28h]

  v2 = this->mOwner;
  v3 = this;
  v4 = distanceSqr;
  if ( v2 )
  {
    v5 = v2->mTransformNodePtr;
    if ( !v5 || v2->mActiveStatus == 2 )
      v5 = v2->mProxyTransformNode;
    if ( v5 || (v5 = v2->mProxyTransformNode) != 0i64 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(v5);
      v6 = v5->mWorldTransform.v3.y;
      leaderPos.x = v5->mWorldTransform.v3.x;
      v7 = v5->mWorldTransform.v3.z;
      leaderPos.y = v6;
      leaderPos.z = v7;
    }
  }
  UFG::GroupLeader::UnregisterFarFollowers(&v3->mGroupLeader, &leaderPos, v4);
}

// File Line: 419
// RVA: 0x36AD80
char __fastcall UFG::GroupComponent::IsInGroup(UFG::GroupComponent *this, UFG::GroupComponent *pGroupComponent)
{
  unsigned int v3; // er8
  unsigned int v4; // eax
  UFG::GroupComponent **v5; // rcx
  UFG::GroupComponent *v6; // rcx
  unsigned int v7; // er8
  unsigned int v8; // eax
  UFG::GroupComponent **v9; // rcx

  if ( pGroupComponent == this )
    return 1;
  if ( this->mGroupLeader.mFormationProfile && this->mGroupLeader.mFollowers.size )
  {
    if ( pGroupComponent )
    {
      v3 = this->mGroupLeader.mFollowers.size;
      v4 = 0;
      if ( v3 )
      {
        v5 = &this->mGroupLeader.mFollowers.p[0].m_pPointer;
        while ( pGroupComponent != *v5 )
        {
          ++v4;
          v5 += 3;
          if ( v4 >= v3 )
            return 0;
        }
        return 1;
      }
    }
  }
  else
  {
    v6 = this->mGroupFollower.mLeader.m_pPointer;
    if ( v6 )
    {
      if ( pGroupComponent == v6 )
        return 1;
      if ( pGroupComponent )
      {
        v7 = v6->mGroupLeader.mFollowers.size;
        v8 = 0;
        if ( v7 )
        {
          v9 = &v6->mGroupLeader.mFollowers.p[0].m_pPointer;
          while ( pGroupComponent != *v9 )
          {
            ++v8;
            v9 += 3;
            if ( v8 >= v7 )
              return 0;
          }
          return 1;
        }
      }
    }
  }
  return 0;
}

// File Line: 446
// RVA: 0x36C8A0
char __fastcall UFG::GroupComponent::JoinExistingGroup(UFG::GroupComponent *this, UFG::GroupComponent *leader, UFG::PedFormationProfile *pFormation)
{
  UFG::PedFormationProfile *v3; // rax
  UFG::GroupComponent *v4; // rbx
  UFG::GroupComponent *v5; // rdi
  UFG::PedFormationProfile *v6; // rax

  v3 = this->mGroupLeader.mFormationProfile;
  v4 = leader;
  v5 = this;
  if ( v3 && v3->mMaxFollowers )
    return 0;
  v6 = leader->mGroupLeader.mFormationProfile;
  if ( !v6 || v6 != pFormation || v6 && leader->mGroupLeader.mFollowers.size >= v6->mMaxFollowers )
    return 0;
  UFG::GroupLeader::Reset(&this->mGroupLeader);
  UFG::GroupFollower::FollowLeader(&v5->mGroupFollower, v5, v4);
  return 1;
}

// File Line: 461
// RVA: 0x36D150
char __fastcall UFG::GroupComponent::JoinNewGroup(UFG::GroupComponent *this, UFG::GroupComponent *leader, UFG::PedFormationProfile *pFormation)
{
  UFG::PedFormationProfile *v3; // rax
  UFG::PedFormationProfile *v4; // rbp
  UFG::GroupComponent *v5; // rbx
  UFG::GroupComponent *v6; // rdi
  UFG::PedFormationProfile *v7; // rax

  v3 = this->mGroupLeader.mFormationProfile;
  v4 = pFormation;
  v5 = leader;
  v6 = this;
  if ( v3 && v3->mMaxFollowers )
    return 0;
  if ( leader->mGroupFollower.mLeader.m_pPointer )
    return 0;
  v7 = leader->mGroupLeader.mFormationProfile;
  if ( v7 )
  {
    if ( v7->mMaxFollowers )
      return 0;
  }
  UFG::GroupLeader::Reset(&this->mGroupLeader);
  if ( v5->mGroupLeader.mFormationProfile != v4 )
  {
    UFG::GroupLeader::Reset(&v5->mGroupLeader);
    v5->mGroupLeader.mFormationProfile = v4;
    if ( v4 )
      ++UFG::gpGroupManager->mGroupTotals.p[0];
  }
  UFG::GroupFollower::FollowLeader(&v6->mGroupFollower, v6, v5);
  return 1;
}

// File Line: 476
// RVA: 0x3879A0
void __fastcall UFG::GroupComponent::SetOwner(UFG::GroupComponent *this, UFG::PedSpawningInfo *pOwner)
{
  this->mOwner = pOwner;
}

// File Line: 497
// RVA: 0x3620D0
UFG::qVector3 *__fastcall UFG::GroupComponent::GetPosition(UFG::GroupComponent *this, UFG::qVector3 *result)
{
  UFG::PedSpawningInfo *v2; // rax
  UFG::qVector3 *v3; // rdi
  UFG::TransformNodeComponent *v4; // rbx

  v2 = this->mOwner;
  v3 = result;
  if ( !v2 )
    return result;
  v4 = v2->mTransformNodePtr;
  if ( !v4 || v2->mActiveStatus == 2 )
    v4 = v2->mProxyTransformNode;
  if ( v4 || (v4 = v2->mProxyTransformNode) != 0i64 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(v4);
    v3->x = v4->mWorldTransform.v3.x;
    v3->y = v4->mWorldTransform.v3.y;
    v3->z = v4->mWorldTransform.v3.z;
  }
  return v3;
}

// File Line: 511
// RVA: 0x35D680
bool __fastcall UFG::GroupComponent::GetDefaultFollowerPosition(UFG::GroupComponent *this, UFG::qVector3 *followerPosition)
{
  UFG::GroupComponent *v2; // r9
  UFG::qVector3 *v3; // rsi
  UFG::GroupComponent *v4; // r10
  UFG::PedFormationProfile *v5; // r8
  unsigned int v6; // er11
  __int64 v7; // rax
  UFG::GroupComponent **v8; // rcx
  signed __int64 v9; // rdi
  UFG::PedSpawningInfo *v10; // rax
  UFG::TransformNodeComponent *v11; // rbx
  float v12; // xmm6_4
  float v13; // xmm7_4
  float v14; // xmm8_4
  float v15; // xmm6_4
  float v16; // xmm7_4
  float v17; // xmm0_4
  float v18; // xmm4_4
  float v19; // xmm6_4
  float v20; // xmm7_4
  float v21; // xmm8_4
  float v22; // xmm7_4
  float v23; // xmm8_4

  v2 = this->mGroupFollower.mLeader.m_pPointer;
  v3 = followerPosition;
  v4 = this;
  if ( v2 && (v5 = v2->mGroupLeader.mFormationProfile) != 0i64 )
  {
    v6 = v2->mGroupLeader.mFollowers.size;
    v7 = 0i64;
    if ( v6 )
    {
      v8 = &v2->mGroupLeader.mFollowers.p[0].m_pPointer;
      while ( v4 != *v8 || (unsigned int)v7 >= v5->mSlots.size )
      {
        v7 = (unsigned int)(v7 + 1);
        v8 += 3;
        if ( (unsigned int)v7 >= v6 )
          goto LABEL_8;
      }
      v9 = (signed __int64)&v5->mSlots.p[v7];
      if ( v9 && (v10 = v2->mOwner) != 0i64 )
      {
        v11 = v10->mTransformNodePtr;
        if ( !v11 || v10->mActiveStatus == 2 )
          v11 = v10->mProxyTransformNode;
        if ( v11 || (v11 = v10->mProxyTransformNode) != 0i64 )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform(v11);
          v12 = v11->mWorldTransform.v0.x;
          v13 = v11->mWorldTransform.v0.y;
          UFG::TransformNodeComponent::UpdateWorldTransform(v11);
          v14 = UFG::qVector3::msZero.z;
          v15 = (float)((float)(unsigned __int16)(*(_WORD *)(v9 + 28)
                                                + (signed int)(float)((float)(atan2f(v13, v12) * 32768.0) * 0.31830987))
                      * 3.1415927)
              * 0.000030517578;
          v16 = sinf(v15);
          v17 = cosf(v15);
          v18 = *(float *)(v9 + 44) / fsqrt((float)((float)(v17 * v17) + (float)(v16 * v16)) + (float)(v14 * v14));
          v19 = v17 * v18;
          v20 = v16 * v18;
          v21 = v14 * v18;
          UFG::TransformNodeComponent::UpdateWorldTransform(v11);
          v22 = v20 + v11->mWorldTransform.v3.y;
          LOBYTE(v7) = 1;
          v23 = v21 + v11->mWorldTransform.v3.z;
          v3->x = v19 + v11->mWorldTransform.v3.x;
          v3->y = v22;
          v3->z = v23;
        }
        else
        {
          LOBYTE(v7) = 0;
        }
      }
      else
      {
        LOBYTE(v7) = 0;
      }
    }
  }
  else
  {
LABEL_8:
    LOBYTE(v7) = 0;
  }
  return v7;
}

// File Line: 539
// RVA: 0x35FBF0
UFG::qSafePointerNode<UFG::SimComponent>Vtbl *__fastcall UFG::GroupComponent::GetFollower(UFG::GroupComponent *this, unsigned int index)
{
  return (&this->vfptr)[3 * (index + 6i64)];
}

// File Line: 544
// RVA: 0x360960
UFG::GroupComponent *__fastcall UFG::GroupComponent::GetLeader(UFG::GroupComponent *this)
{
  return this->mGroupFollower.mLeader.m_pPointer;
}

// File Line: 549
// RVA: 0x362630
UFG::PedSpawningInfo *__fastcall UFG::GroupComponent::GetSimObjectPtr(UFG::GroupComponent *this)
{
  UFG::PedSpawningInfo *result; // rax

  result = this->mOwner;
  if ( result )
    result = (UFG::PedSpawningInfo *)result->mSimObjectPtr.m_pPointer;
  return result;
}

// File Line: 561
// RVA: 0x382A10
void __fastcall UFG::GroupComponent::Reset(UFG::GroupComponent *this)
{
  UFG::GroupComponent *v1; // rbx
  UFG::GroupComponent *v2; // rcx
  UFG::qSafePointer<UFG::GroupComponent,UFG::GroupComponent> *v3; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v5; // rax

  v1 = this;
  v2 = this->mGroupFollower.mLeader.m_pPointer;
  if ( v2 )
  {
    UFG::GroupLeader::Unregister(&v2->mGroupLeader, v1);
    v3 = &v1->mGroupFollower.mLeader;
    if ( v1->mGroupFollower.mLeader.m_pPointer )
    {
      v4 = v3->mPrev;
      v5 = v1->mGroupFollower.mLeader.mNext;
      v4->mNext = v5;
      v5->mPrev = v4;
      v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
      v1->mGroupFollower.mLeader.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *)&v1->mGroupFollower.mLeader.mPrev;
    }
    v1->mGroupFollower.mLeader.m_pPointer = 0i64;
  }
  UFG::GroupLeader::Reset(&v1->mGroupLeader);
  v1->mFlags = 1;
}

// File Line: 588
// RVA: 0x3625A0
UFG::GroupComponent *__fastcall UFG::GroupComponent::GetSharedGroupComponent(UFG::GroupComponent *this)
{
  if ( this->mGroupFollower.mLeader.m_pPointer )
    this = this->mGroupFollower.mLeader.m_pPointer;
  return this;
}

// File Line: 600
// RVA: 0x35FDA0
signed __int64 __fastcall UFG::GroupComponent::GetGroupSize(UFG::GroupComponent *this)
{
  signed __int64 result; // rax

  if ( this->mGroupFollower.mLeader.m_pPointer )
    this = this->mGroupFollower.mLeader.m_pPointer;
  if ( this )
    result = this->mGroupLeader.mFollowers.size + 1;
  else
    result = 1i64;
  return result;
}

// File Line: 613
// RVA: 0x35FD10
UFG::qSafePointerNode<UFG::SimComponent>Vtbl *__fastcall UFG::GroupComponent::GetGroupComponent(UFG::SimObject *pSimObject)
{
  unsigned __int16 v1; // dx
  UFG::SimComponent *v2; // rax
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *result; // rax

  if ( pSimObject
    && ((v1 = pSimObject->m_Flags, !((v1 >> 14) & 1)) ? ((v1 & 0x8000u) == 0 ? (!((v1 >> 13) & 1) ? (!((v1 >> 12) & 1) ? (v2 = UFG::SimObject::GetComponentOfType(pSimObject, UFG::AIEntityComponent::_TypeUID)) : (v2 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)pSimObject, UFG::AIEntityComponent::_TypeUID))) : (v2 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)pSimObject, UFG::AIEntityComponent::_TypeUID))) : (v2 = pSimObject->m_Components.p[22].m_pComponent)) : (v2 = pSimObject->m_Components.p[22].m_pComponent),
        v2) )
  {
    result = v2[15].vfptr;
  }
  else
  {
    result = 0i64;
  }
  return result;
}

// File Line: 640
// RVA: 0x36B4F0
char __fastcall UFG::GroupComponent::IsLeader(UFG::SimObject *pSimObject)
{
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v1; // rax

  if ( !pSimObject )
    return 0;
  v1 = UFG::GroupComponent::GetGroupComponent(pSimObject);
  if ( !v1 )
    return 0;
  if ( v1[28].__vecDelDtor && LODWORD(v1[15].__vecDelDtor) )
    return 1;
  return 0;
}

// File Line: 654
// RVA: 0x36A9F0
bool __fastcall UFG::GroupComponent::IsFollower(UFG::SimObject *pSimObject)
{
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v1; // rax
  bool result; // al

  if ( pSimObject && (v1 = UFG::GroupComponent::GetGroupComponent(pSimObject)) != 0i64 )
    result = v1[32].__vecDelDtor != 0i64;
  else
    result = 0;
  return result;
}

// File Line: 668
// RVA: 0x36AA50
char __fastcall UFG::GroupComponent::IsGroupMember(UFG::SimObject *pSimObject)
{
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v1; // rax

  if ( !pSimObject )
    return 0;
  v1 = UFG::GroupComponent::GetGroupComponent(pSimObject);
  if ( !v1 )
    return 0;
  if ( v1[28].__vecDelDtor && LODWORD(v1[15].__vecDelDtor) || v1[32].__vecDelDtor )
    return 1;
  return 0;
}

// File Line: 682
// RVA: 0x36D2B0
void __fastcall UFG::GroupComponent::LeaveGroup(UFG::SimObject *pSimObject)
{
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v1; // rax
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v2; // rbx

  v1 = UFG::GroupComponent::GetGroupComponent(pSimObject);
  v2 = v1;
  if ( v1 )
  {
    UFG::GroupComponent::Reset((UFG::GroupComponent *)v1);
    if ( (UFG::PedFormationProfile *)v2[28].__vecDelDtor != &ptr )
    {
      UFG::GroupLeader::Reset((UFG::GroupLeader *)&v2[14]);
      v2[28].__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))&ptr;
      ++UFG::gpGroupManager->mGroupTotals.p[0];
    }
    LODWORD(v2[34].__vecDelDtor) |= 1u;
  }
}

