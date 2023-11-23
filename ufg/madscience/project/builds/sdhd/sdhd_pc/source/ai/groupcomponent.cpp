// File Line: 43
// RVA: 0x337F20
void __fastcall UFG::GroupFollower::~GroupFollower(UFG::GroupFollower *this)
{
  UFG::qSafePointer<UFG::GroupComponent,UFG::GroupComponent> *p_mLeader; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v5; // rax

  this->vfptr = (UFG::GroupFollowerVtbl *)&UFG::GroupFollower::`vftable;
  p_mLeader = &this->mLeader;
  if ( this->mLeader.m_pPointer )
  {
    mPrev = p_mLeader->mPrev;
    mNext = p_mLeader->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mLeader->mPrev = p_mLeader;
    p_mLeader->mNext = p_mLeader;
  }
  p_mLeader->m_pPointer = 0i64;
  v4 = p_mLeader->mPrev;
  v5 = p_mLeader->mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  p_mLeader->mPrev = p_mLeader;
  p_mLeader->mNext = p_mLeader;
}

// File Line: 52
// RVA: 0x3583B0
void __fastcall UFG::GroupFollower::FollowLeader(
        UFG::GroupFollower *this,
        UFG::GroupComponent *pFollower,
        UFG::GroupComponent *pLeader)
{
  UFG::GroupComponent *m_pPointer; // rcx
  UFG::qSafePointer<UFG::GroupComponent,UFG::GroupComponent> *p_mLeader; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qSafePointer<UFG::GroupComponent,UFG::GroupComponent> *v10; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v13; // rax

  m_pPointer = this->mLeader.m_pPointer;
  if ( m_pPointer != pLeader )
  {
    if ( m_pPointer )
    {
      UFG::GroupLeader::Unregister(&m_pPointer->mGroupLeader, pFollower);
      p_mLeader = &this->mLeader;
      if ( this->mLeader.m_pPointer )
      {
        mPrev = p_mLeader->mPrev;
        mNext = this->mLeader.mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        p_mLeader->mPrev = p_mLeader;
        this->mLeader.mNext = &this->mLeader;
      }
      this->mLeader.m_pPointer = 0i64;
    }
    if ( pLeader && UFG::GroupLeader::Register(&pLeader->mGroupLeader, pFollower) )
    {
      v10 = &this->mLeader;
      if ( this->mLeader.m_pPointer )
      {
        v11 = v10->mPrev;
        v12 = this->mLeader.mNext;
        v11->mNext = v12;
        v12->mPrev = v11;
        v10->mPrev = v10;
        this->mLeader.mNext = &this->mLeader;
      }
      this->mLeader.m_pPointer = pLeader;
      v13 = pLeader->UFG::qSafePointerNode<UFG::GroupComponent>::m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::GroupComponent>::mPrev;
      v13->mNext = v10;
      v10->mPrev = v13;
      this->mLeader.mNext = &pLeader->UFG::qSafePointerNode<UFG::GroupComponent>::m_SafePointerList.mNode;
      pLeader->UFG::qSafePointerNode<UFG::GroupComponent>::m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::GroupComponent>::mPrev = v10;
    }
  }
}

// File Line: 74
// RVA: 0x32F470
void __fastcall UFG::GroupLeader::GroupLeader(UFG::GroupLeader *this)
{
  UFG::qFixedArray<UFG::qSafePointer<UFG::GroupComponent,UFG::GroupComponent>,4> *p_mFollowers; // rbx

  this->vfptr = (UFG::GroupLeaderVtbl *)&UFG::GroupLeader::`vftable;
  p_mFollowers = &this->mFollowers;
  `eh vector constructor iterator(
    this->mFollowers.p,
    0x18ui64,
    4,
    (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>);
  p_mFollowers->size = 0;
  this->mFormationProfile = 0i64;
}

// File Line: 78
// RVA: 0x337F90
void __fastcall UFG::GroupLeader::~GroupLeader(UFG::GroupLeader *this)
{
  UFG::qFixedArray<UFG::qSafePointer<UFG::GroupComponent,UFG::GroupComponent>,4> *p_mFollowers; // rcx

  this->vfptr = (UFG::GroupLeaderVtbl *)&UFG::GroupLeader::`vftable;
  p_mFollowers = &this->mFollowers;
  p_mFollowers->size = 0;
  `eh vector destructor iterator(
    p_mFollowers->p,
    0x18ui64,
    4,
    (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
}

// File Line: 82
// RVA: 0x382A80
void __fastcall UFG::GroupLeader::Reset(UFG::GroupLeader *this)
{
  unsigned int v2; // edx
  unsigned int v3; // r8d
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v4; // rdx
  UFG::GroupComponent *m_pPointer; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v8; // rax
  unsigned int i; // ebx
  UFG::GroupComponent *v10; // rcx
  unsigned int v11; // eax
  unsigned int size; // [rsp+40h] [rbp-78h]
  _QWORD ptr[13]; // [rsp+48h] [rbp-70h] BYREF

  if ( this->mFollowers.size )
  {
    `eh vector constructor iterator(
      ptr,
      0x18ui64,
      4,
      (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>);
    v2 = 0;
    size = 0;
    if ( this->mFollowers.size )
    {
      size = this->mFollowers.size;
      v3 = 0;
      do
      {
        v4 = (UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *)&ptr[3 * v3];
        m_pPointer = this->mFollowers.p[v3].m_pPointer;
        if ( v4[1].mPrev )
        {
          mPrev = v4->mPrev;
          mNext = v4->mNext;
          mPrev->mNext = mNext;
          mNext->mPrev = mPrev;
          v4->mPrev = v4;
          v4->mNext = v4;
        }
        v4[1].mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *)m_pPointer;
        if ( m_pPointer )
        {
          v8 = m_pPointer->UFG::qSafePointerNode<UFG::GroupComponent>::m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::GroupComponent>::mPrev;
          v8->mNext = v4;
          v4->mPrev = v8;
          v4->mNext = &m_pPointer->UFG::qSafePointerNode<UFG::GroupComponent>::m_SafePointerList.mNode;
          m_pPointer->UFG::qSafePointerNode<UFG::GroupComponent>::m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::GroupComponent>::mPrev = v4;
        }
        ++v3;
      }
      while ( v3 < this->mFollowers.size );
      v2 = size;
    }
    for ( i = 0; i < v2; ++i )
    {
      v10 = (UFG::GroupComponent *)ptr[3 * i + 2];
      if ( v10 )
      {
        UFG::GroupComponent::MakeSingle(v10, 1);
        v2 = size;
      }
    }
    `eh vector destructor iterator(
      ptr,
      0x18ui64,
      4,
      (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
  }
  this->mFollowers.size = 0;
  if ( this->mFormationProfile )
  {
    v11 = UFG::gpGroupManager->mGroupTotals.p[0];
    if ( v11 )
      UFG::gpGroupManager->mGroupTotals.p[0] = v11 - 1;
  }
  this->mFormationProfile = 0i64;
}

// File Line: 111
// RVA: 0x38A690
void __fastcall UFG::GroupLeader::UnregisterFarFollowers(
        UFG::GroupLeader *this,
        UFG::qVector3 *leaderPos,
        float distanceSqr)
{
  unsigned int v5; // r8d
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v6; // rdx
  UFG::GroupComponent *m_pPointer; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v10; // rax
  unsigned int v11; // esi
  float y; // xmm6_4
  float x; // xmm7_4
  __int64 v14; // rcx
  UFG::TransformNodeComponent *v15; // rbx
  __int64 v16; // rbx
  __int64 v17; // rcx
  __int64 *v18; // rdx
  __int64 v19; // rcx
  _QWORD *v20; // rax
  float v21; // [rsp+30h] [rbp-D8h]
  float v22; // [rsp+34h] [rbp-D4h]
  unsigned int size; // [rsp+50h] [rbp-B8h]
  _QWORD ptr[19]; // [rsp+58h] [rbp-B0h] BYREF

  if ( this->mFollowers.size )
  {
    `eh vector constructor iterator(
      ptr,
      0x18ui64,
      4,
      (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>);
    size = 0;
    if ( this->mFollowers.size )
    {
      size = this->mFollowers.size;
      v5 = 0;
      do
      {
        v6 = (UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *)&ptr[3 * v5];
        m_pPointer = this->mFollowers.p[v5].m_pPointer;
        if ( v6[1].mPrev )
        {
          mPrev = v6->mPrev;
          mNext = v6->mNext;
          mPrev->mNext = mNext;
          mNext->mPrev = mPrev;
          v6->mPrev = v6;
          v6->mNext = v6;
        }
        v6[1].mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *)m_pPointer;
        if ( m_pPointer )
        {
          v10 = m_pPointer->UFG::qSafePointerNode<UFG::GroupComponent>::m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::GroupComponent>::mPrev;
          v10->mNext = v6;
          v6->mPrev = v10;
          v6->mNext = &m_pPointer->UFG::qSafePointerNode<UFG::GroupComponent>::m_SafePointerList.mNode;
          m_pPointer->UFG::qSafePointerNode<UFG::GroupComponent>::m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::GroupComponent>::mPrev = v6;
        }
        ++v5;
      }
      while ( v5 < this->mFollowers.size );
    }
    v11 = 0;
    if ( size )
    {
      y = v22;
      x = v21;
      do
      {
        v14 = *(_QWORD *)(ptr[3 * v11 + 2] + 264i64);
        if ( v14 )
        {
          v15 = *(UFG::TransformNodeComponent **)(v14 + 240);
          if ( !v15 || *(_DWORD *)(v14 + 168) == 2 )
            v15 = *(UFG::TransformNodeComponent **)(v14 + 120);
          if ( v15 || (v15 = *(UFG::TransformNodeComponent **)(v14 + 120)) != 0i64 )
          {
            UFG::TransformNodeComponent::UpdateWorldTransform(v15);
            x = v15->mWorldTransform.v3.x;
            y = v15->mWorldTransform.v3.y;
          }
        }
        if ( (float)((float)((float)(leaderPos->x - x) * (float)(leaderPos->x - x))
                   + (float)((float)(leaderPos->y - y) * (float)(leaderPos->y - y))) > distanceSqr )
        {
          v16 = ptr[3 * v11 + 2];
          v17 = *(_QWORD *)(v16 + 256);
          if ( v17 )
          {
            UFG::GroupLeader::Unregister((UFG::GroupLeader *)(v17 + 112), (UFG::GroupComponent *)ptr[3 * v11 + 2]);
            v18 = (__int64 *)(v16 + 240);
            if ( *(_QWORD *)(v16 + 256) )
            {
              v19 = *v18;
              v20 = *(_QWORD **)(v16 + 248);
              *(_QWORD *)(v19 + 8) = v20;
              *v20 = v19;
              *v18 = (__int64)v18;
              *(_QWORD *)(v16 + 248) = v16 + 240;
            }
            *(_QWORD *)(v16 + 256) = 0i64;
          }
          UFG::GroupLeader::Reset((UFG::GroupLeader *)(v16 + 112));
          *(_DWORD *)(v16 + 272) = 1;
          if ( *(UFG::PedFormationProfile **)(v16 + 224) != &::ptr )
          {
            UFG::GroupLeader::Reset((UFG::GroupLeader *)(v16 + 112));
            *(_QWORD *)(v16 + 224) = &::ptr;
            ++UFG::gpGroupManager->mGroupTotals.p[0];
          }
          *(_DWORD *)(v16 + 272) |= 1u;
        }
        ++v11;
      }
      while ( v11 < size );
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
char __fastcall UFG::GroupLeader::Register(
        UFG::GroupLeader *this,
        UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *pFollower)
{
  UFG::PedFormationProfile *mFormationProfile; // rax
  unsigned int *v5; // rdx
  unsigned int v6; // eax
  __int64 v7; // rdx
  bool v8; // zf
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v9; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v12; // rax

  if ( !pFollower )
    return 0;
  mFormationProfile = this->mFormationProfile;
  if ( mFormationProfile )
  {
    if ( this->mFollowers.size >= mFormationProfile->mMaxFollowers )
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
    mPrev = v9->mPrev;
    mNext = v9->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    v9->mPrev = v9;
    v9->mNext = v9;
  }
  v9[1].mPrev = pFollower;
  v12 = pFollower[5].mPrev;
  v12->mNext = v9;
  v9->mPrev = v12;
  v9->mNext = pFollower + 5;
  pFollower[5].mPrev = v9;
  ++UFG::gpGroupManager->mGroupTotals.p[this->mFollowers.size];
  return 1;
}

// File Line: 148
// RVA: 0x38A3B0
char __fastcall UFG::GroupLeader::Unregister(UFG::GroupLeader *this, UFG::GroupComponent *pFollower)
{
  __int64 size; // r9
  __int64 v4; // r8
  UFG::GroupComponent **i; // rax
  unsigned int *v7; // rdx
  unsigned int v8; // eax
  __int64 v9; // r8
  UFG::qSafePointer<UFG::GroupComponent,UFG::GroupComponent> *v10; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qSafePointer<UFG::GroupComponent,UFG::GroupComponent> *v13; // rdx
  UFG::GroupComponent *v14; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v17; // rax

  if ( !pFollower )
    return 0;
  size = this->mFollowers.size;
  v4 = 0i64;
  if ( !(_DWORD)size )
    return 0;
  for ( i = &this->mFollowers.p[0].m_pPointer; pFollower != *i; i += 3 )
  {
    v4 = (unsigned int)(v4 + 1);
    if ( (unsigned int)v4 >= (unsigned int)size )
      return 0;
  }
  v7 = &UFG::gpGroupManager->mProfiles.size + size;
  v8 = v7[203];
  if ( v8 )
    v7[203] = v8 - 1;
  v9 = v4;
  v10 = &this->mFollowers.p[v9];
  if ( v10->m_pPointer )
  {
    mPrev = v10->mPrev;
    mNext = v10->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    v10->mPrev = v10;
    v10->mNext = v10;
  }
  v10->m_pPointer = 0i64;
  --this->mFollowers.size;
  v13 = &this->mFollowers.p[v9];
  v14 = (UFG::GroupComponent *)*((_QWORD *)&this->mFollowers.p[this->mFollowers.size].mNext + 1);
  if ( v13->m_pPointer )
  {
    v15 = v13->mPrev;
    v16 = v13->mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    v13->mPrev = v13;
    v13->mNext = v13;
  }
  v13->m_pPointer = v14;
  if ( v14 )
  {
    v17 = v14->UFG::qSafePointerNode<UFG::GroupComponent>::m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::GroupComponent>::mPrev;
    v17->mNext = v13;
    v13->mPrev = v17;
    v13->mNext = &v14->UFG::qSafePointerNode<UFG::GroupComponent>::m_SafePointerList.mNode;
    v14->UFG::qSafePointerNode<UFG::GroupComponent>::m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::GroupComponent>::mPrev = v13;
  }
  ++UFG::gpGroupManager->mGroupTotals.p[this->mFollowers.size];
  return 1;
}

// File Line: 247
// RVA: 0x36C920
bool __fastcall UFG::GroupComponent::JoinGroup(
        UFG::SimObjectGame *pLeaderSim,
        UFG::SimObjectGame *pFollowerSim,
        UFG::PedFormationProfile *pFormation)
{
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *GroupComponent; // rsi
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v6; // rax
  UFG::GroupComponent *v7; // rdi

  if ( !pLeaderSim || !pFollowerSim || !pFormation )
    return 0;
  GroupComponent = UFG::GroupComponent::GetGroupComponent(pLeaderSim);
  v6 = UFG::GroupComponent::GetGroupComponent(pFollowerSim);
  v7 = (UFG::GroupComponent *)v6;
  if ( !GroupComponent || !v6 )
    return 0;
  if ( UFG::GroupComponent::JoinExistingGroup(
         (UFG::GroupComponent *)v6,
         (UFG::GroupComponent *)GroupComponent,
         pFormation) )
  {
    return 1;
  }
  UFG::GroupComponent::Reset((UFG::GroupComponent *)GroupComponent);
  return UFG::GroupComponent::JoinNewGroup(v7, (UFG::GroupComponent *)GroupComponent, pFormation);
}

// File Line: 277
// RVA: 0x14AEB40
__int64 dynamic_initializer_for__UFG::GroupComponent::s_GroupComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::GroupComponent::s_GroupComponentList__);
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
  UFG::qNode<UFG::GroupComponent,UFG::GroupComponent> *mPrev; // rax

  UFG::SimComponent::SimComponent(this, name_uid);
  this->UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::UpdateInterface::`vftable;
  this->mPrev = &this->UFG::qNode<UFG::GroupComponent,UFG::GroupComponent>;
  this->mNext = &this->UFG::qNode<UFG::GroupComponent,UFG::GroupComponent>;
  UFG::qSafePointerNode<UFG::GroupComponent>::qSafePointerNode<UFG::GroupComponent>(&this->UFG::qSafePointerNode<UFG::GroupComponent>);
  this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::GroupComponent::`vftable{for `UFG::SimComponent};
  this->UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::GroupComponent::`vftable{for `UFG::UpdateInterface};
  this->UFG::qSafePointerNode<UFG::GroupComponent>::vfptr = (UFG::qSafePointerNode<UFG::GroupComponent>Vtbl *)&UFG::GroupComponent::`vftable{for `UFG::qSafePointerNode<UFG::GroupComponent>};
  UFG::GroupLeader::GroupLeader(&this->mGroupLeader);
  this->mGroupFollower.vfptr = (UFG::GroupFollowerVtbl *)&UFG::GroupFollower::`vftable;
  this->mGroupFollower.mLeader.mPrev = &this->mGroupFollower.mLeader;
  this->mGroupFollower.mLeader.mNext = &this->mGroupFollower.mLeader;
  this->mGroupFollower.mLeader.m_pPointer = 0i64;
  this->mOwner = 0i64;
  this->mFlags = 1;
  mPrev = UFG::GroupComponent::s_GroupComponentList.mNode.mPrev;
  UFG::GroupComponent::s_GroupComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::GroupComponent,UFG::GroupComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::GroupComponent,UFG::GroupComponent> *)&UFG::GroupComponent::s_GroupComponentList;
  UFG::GroupComponent::s_GroupComponentList.mNode.mPrev = &this->UFG::qNode<UFG::GroupComponent,UFG::GroupComponent>;
  UFG::SimComponent::AddType(this, UFG::GroupComponent::_GroupComponentTypeUID, "GroupComponent");
}

// File Line: 290
// RVA: 0x337DA0
void __fastcall UFG::GroupComponent::~GroupComponent(UFG::GroupComponent *this)
{
  UFG::qSafePointerNode<UFG::ParkourHandle> *v2; // rbx
  UFG::qNode<UFG::GroupComponent,UFG::GroupComponent> *v3; // rsi
  UFG::qNode<UFG::GroupComponent,UFG::GroupComponent> *mPrev; // rcx
  UFG::qNode<UFG::GroupComponent,UFG::GroupComponent> *mNext; // rax
  UFG::qSafePointer<UFG::GroupComponent,UFG::GroupComponent> *p_mLeader; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *p_m_SafePointerList; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qNode<UFG::GroupComponent,UFG::GroupComponent> *v14; // rcx
  UFG::qNode<UFG::GroupComponent,UFG::GroupComponent> *v15; // rax

  this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::GroupComponent::`vftable{for `UFG::SimComponent};
  this->UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::GroupComponent::`vftable{for `UFG::UpdateInterface};
  v2 = (UFG::qSafePointerNode<UFG::ParkourHandle> *)&this->UFG::qSafePointerNode<UFG::GroupComponent>;
  this->UFG::qSafePointerNode<UFG::GroupComponent>::vfptr = (UFG::qSafePointerNode<UFG::GroupComponent>Vtbl *)&UFG::GroupComponent::`vftable{for `UFG::qSafePointerNode<UFG::GroupComponent>};
  UFG::GroupComponent::Reset(this);
  if ( this == UFG::GroupComponent::s_GroupComponentpCurrentIterator )
    UFG::GroupComponent::s_GroupComponentpCurrentIterator = (UFG::GroupComponent *)&this->mPrev[-6];
  v3 = &this->UFG::qNode<UFG::GroupComponent,UFG::GroupComponent>;
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = &this->UFG::qNode<UFG::GroupComponent,UFG::GroupComponent>;
  this->mNext = &this->UFG::qNode<UFG::GroupComponent,UFG::GroupComponent>;
  this->mGroupFollower.vfptr = (UFG::GroupFollowerVtbl *)&UFG::GroupFollower::`vftable;
  p_mLeader = &this->mGroupFollower.mLeader;
  if ( this->mGroupFollower.mLeader.m_pPointer )
  {
    v7 = p_mLeader->mPrev;
    v8 = this->mGroupFollower.mLeader.mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    p_mLeader->mPrev = p_mLeader;
    this->mGroupFollower.mLeader.mNext = &this->mGroupFollower.mLeader;
  }
  this->mGroupFollower.mLeader.m_pPointer = 0i64;
  v9 = p_mLeader->mPrev;
  v10 = this->mGroupFollower.mLeader.mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  p_mLeader->mPrev = p_mLeader;
  this->mGroupFollower.mLeader.mNext = &this->mGroupFollower.mLeader;
  this->mGroupLeader.vfptr = (UFG::GroupLeaderVtbl *)&UFG::GroupLeader::`vftable;
  this->mGroupLeader.mFollowers.size = 0;
  `eh vector destructor iterator(
    this->mGroupLeader.mFollowers.p,
    0x18ui64,
    4,
    (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
  v2->vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)&UFG::qSafePointerNode<UFG::GroupComponent>::`vftable;
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull(v2);
  p_m_SafePointerList = &v2->m_SafePointerList;
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes(p_m_SafePointerList);
  v12 = p_m_SafePointerList->mNode.mPrev;
  v13 = p_m_SafePointerList->mNode.mNext;
  v12->mNext = v13;
  v13->mPrev = v12;
  p_m_SafePointerList->mNode.mPrev = &p_m_SafePointerList->mNode;
  p_m_SafePointerList->mNode.mNext = &p_m_SafePointerList->mNode;
  v14 = v3->mPrev;
  v15 = this->mNext;
  v14->mNext = v15;
  v15->mPrev = v14;
  v3->mPrev = v3;
  this->mNext = &this->UFG::qNode<UFG::GroupComponent,UFG::GroupComponent>;
  UFG::SimComponent::~SimComponent(this);
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
  UFG::PedFormationProfile *mFormationProfile; // rax
  bool result; // al

  result = 0;
  if ( this->mGroupLeader.mFormationProfile )
  {
    mFormationProfile = this->mGroupLeader.mFormationProfile;
    if ( mFormationProfile )
    {
      if ( this->mGroupLeader.mFollowers.size >= mFormationProfile->mMaxFollowers )
        return 1;
    }
  }
  return result;
}

// File Line: 387
// RVA: 0x36D900
void __fastcall UFG::GroupComponent::MakeSingle(UFG::GroupComponent *this, const bool isAllowedToJoinGroups)
{
  UFG::GroupComponent::Reset(this);
  if ( this->mGroupLeader.mFormationProfile != &ptr )
  {
    UFG::GroupLeader::Reset(&this->mGroupLeader);
    this->mGroupLeader.mFormationProfile = &ptr;
    ++UFG::gpGroupManager->mGroupTotals.p[0];
  }
  if ( isAllowedToJoinGroups )
    this->mFlags |= 1u;
  else
    this->mFlags &= ~1u;
}

// File Line: 393
// RVA: 0x386550
void __fastcall UFG::GroupComponent::SetFormationProfile(UFG::GroupComponent *this, UFG::PedFormationProfile *pProfile)
{
  UFG::GroupComponent::Reset(this);
  if ( this->mGroupLeader.mFormationProfile != pProfile )
  {
    UFG::GroupLeader::Reset(&this->mGroupLeader);
    this->mGroupLeader.mFormationProfile = pProfile;
    if ( pProfile )
      ++UFG::gpGroupManager->mGroupTotals.p[0];
  }
}

// File Line: 409
// RVA: 0x38A5F0
void __fastcall UFG::GroupComponent::UnregisterFarFollowers(UFG::GroupComponent *this, float distanceSqr)
{
  UFG::PedSpawningInfo *mOwner; // rax
  UFG::TransformNodeComponent *mTransformNodePtr; // rbx
  float y; // xmm1_4
  float z; // xmm0_4
  UFG::qVector3 leaderPos; // [rsp+20h] [rbp-28h] BYREF

  mOwner = this->mOwner;
  if ( mOwner )
  {
    mTransformNodePtr = mOwner->mTransformNodePtr;
    if ( !mTransformNodePtr || mOwner->mActiveStatus == ExtraLowPower )
      mTransformNodePtr = mOwner->mProxyTransformNode;
    if ( mTransformNodePtr || (mTransformNodePtr = mOwner->mProxyTransformNode) != 0i64 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(mTransformNodePtr);
      y = mTransformNodePtr->mWorldTransform.v3.y;
      leaderPos.x = mTransformNodePtr->mWorldTransform.v3.x;
      z = mTransformNodePtr->mWorldTransform.v3.z;
      leaderPos.y = y;
      leaderPos.z = z;
    }
  }
  UFG::GroupLeader::UnregisterFarFollowers(&this->mGroupLeader, &leaderPos, distanceSqr);
}

// File Line: 419
// RVA: 0x36AD80
char __fastcall UFG::GroupComponent::IsInGroup(UFG::GroupComponent *this, UFG::GroupComponent *pGroupComponent)
{
  unsigned int size; // r8d
  int v4; // eax
  UFG::GroupComponent **i; // rcx
  UFG::GroupComponent *m_pPointer; // rcx
  unsigned int v7; // r8d
  int v8; // eax
  UFG::GroupComponent **j; // rcx

  if ( pGroupComponent == this )
    return 1;
  if ( this->mGroupLeader.mFormationProfile && this->mGroupLeader.mFollowers.size )
  {
    if ( pGroupComponent )
    {
      size = this->mGroupLeader.mFollowers.size;
      v4 = 0;
      if ( size )
      {
        for ( i = &this->mGroupLeader.mFollowers.p[0].m_pPointer; pGroupComponent != *i; i += 3 )
        {
          if ( ++v4 >= size )
            return 0;
        }
        return 1;
      }
    }
  }
  else
  {
    m_pPointer = this->mGroupFollower.mLeader.m_pPointer;
    if ( m_pPointer )
    {
      if ( pGroupComponent == m_pPointer )
        return 1;
      if ( pGroupComponent )
      {
        v7 = m_pPointer->mGroupLeader.mFollowers.size;
        v8 = 0;
        if ( v7 )
        {
          for ( j = &m_pPointer->mGroupLeader.mFollowers.p[0].m_pPointer; pGroupComponent != *j; j += 3 )
          {
            if ( ++v8 >= v7 )
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
char __fastcall UFG::GroupComponent::JoinExistingGroup(
        UFG::GroupComponent *this,
        UFG::GroupComponent *leader,
        UFG::PedFormationProfile *pFormation)
{
  UFG::PedFormationProfile *mFormationProfile; // rax
  UFG::PedFormationProfile *v6; // rax

  mFormationProfile = this->mGroupLeader.mFormationProfile;
  if ( mFormationProfile && mFormationProfile->mMaxFollowers )
    return 0;
  v6 = leader->mGroupLeader.mFormationProfile;
  if ( !v6 || v6 != pFormation || leader->mGroupLeader.mFollowers.size >= v6->mMaxFollowers )
    return 0;
  UFG::GroupLeader::Reset(&this->mGroupLeader);
  UFG::GroupFollower::FollowLeader(&this->mGroupFollower, this, leader);
  return 1;
}

// File Line: 461
// RVA: 0x36D150
char __fastcall UFG::GroupComponent::JoinNewGroup(
        UFG::GroupComponent *this,
        UFG::GroupComponent *leader,
        UFG::PedFormationProfile *pFormation)
{
  UFG::PedFormationProfile *mFormationProfile; // rax
  UFG::PedFormationProfile *v7; // rax

  mFormationProfile = this->mGroupLeader.mFormationProfile;
  if ( mFormationProfile && mFormationProfile->mMaxFollowers )
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
  if ( leader->mGroupLeader.mFormationProfile != pFormation )
  {
    UFG::GroupLeader::Reset(&leader->mGroupLeader);
    leader->mGroupLeader.mFormationProfile = pFormation;
    if ( pFormation )
      ++UFG::gpGroupManager->mGroupTotals.p[0];
  }
  UFG::GroupFollower::FollowLeader(&this->mGroupFollower, this, leader);
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
  UFG::PedSpawningInfo *mOwner; // rax
  UFG::TransformNodeComponent *mTransformNodePtr; // rbx

  mOwner = this->mOwner;
  if ( !mOwner )
    return result;
  mTransformNodePtr = mOwner->mTransformNodePtr;
  if ( !mTransformNodePtr || mOwner->mActiveStatus == ExtraLowPower )
    mTransformNodePtr = mOwner->mProxyTransformNode;
  if ( mTransformNodePtr || (mTransformNodePtr = mOwner->mProxyTransformNode) != 0i64 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(mTransformNodePtr);
    result->x = mTransformNodePtr->mWorldTransform.v3.x;
    result->y = mTransformNodePtr->mWorldTransform.v3.y;
    result->z = mTransformNodePtr->mWorldTransform.v3.z;
  }
  return result;
}

// File Line: 511
// RVA: 0x35D680
bool __fastcall UFG::GroupComponent::GetDefaultFollowerPosition(
        UFG::GroupComponent *this,
        UFG::qVector3 *followerPosition)
{
  UFG::GroupComponent *m_pPointer; // r9
  UFG::PedFormationProfile *mFormationProfile; // r8
  unsigned int size; // r11d
  __int64 v7; // rax
  UFG::GroupComponent **p_m_pPointer; // rcx
  __int64 v9; // rdi
  UFG::PedSpawningInfo *mOwner; // rax
  UFG::TransformNodeComponent *mTransformNodePtr; // rbx
  float x; // xmm6_4
  float y; // xmm7_4
  float z; // xmm8_4
  float v15; // xmm6_4
  float v16; // xmm7_4
  float v17; // xmm0_4
  float v18; // xmm4_4
  float v19; // xmm6_4
  float v20; // xmm7_4
  float v21; // xmm8_4
  float v22; // xmm7_4
  float v23; // xmm8_4

  m_pPointer = this->mGroupFollower.mLeader.m_pPointer;
  if ( m_pPointer && (mFormationProfile = m_pPointer->mGroupLeader.mFormationProfile) != 0i64 )
  {
    size = m_pPointer->mGroupLeader.mFollowers.size;
    v7 = 0i64;
    if ( size )
    {
      p_m_pPointer = &m_pPointer->mGroupLeader.mFollowers.p[0].m_pPointer;
      while ( this != *p_m_pPointer || (unsigned int)v7 >= mFormationProfile->mSlots.size )
      {
        v7 = (unsigned int)(v7 + 1);
        p_m_pPointer += 3;
        if ( (unsigned int)v7 >= size )
          goto LABEL_8;
      }
      v9 = (__int64)&mFormationProfile->mSlots.p[v7];
      if ( v9 && (mOwner = m_pPointer->mOwner) != 0i64 )
      {
        mTransformNodePtr = mOwner->mTransformNodePtr;
        if ( !mTransformNodePtr || mOwner->mActiveStatus == ExtraLowPower )
          mTransformNodePtr = mOwner->mProxyTransformNode;
        if ( mTransformNodePtr || (mTransformNodePtr = mOwner->mProxyTransformNode) != 0i64 )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform(mTransformNodePtr);
          x = mTransformNodePtr->mWorldTransform.v0.x;
          y = mTransformNodePtr->mWorldTransform.v0.y;
          UFG::TransformNodeComponent::UpdateWorldTransform(mTransformNodePtr);
          z = UFG::qVector3::msZero.z;
          v15 = (float)((float)(unsigned __int16)(*(_WORD *)(v9 + 28)
                                                + (int)(float)((float)(atan2f(y, x) * 32768.0) * 0.31830987))
                      * 3.1415927)
              * 0.000030517578;
          v16 = sinf(v15);
          v17 = cosf(v15);
          v18 = *(float *)(v9 + 44) / fsqrt((float)((float)(v17 * v17) + (float)(v16 * v16)) + (float)(z * z));
          v19 = v17 * v18;
          v20 = v16 * v18;
          v21 = z * v18;
          UFG::TransformNodeComponent::UpdateWorldTransform(mTransformNodePtr);
          v22 = v20 + mTransformNodePtr->mWorldTransform.v3.y;
          LOBYTE(v7) = 1;
          v23 = v21 + mTransformNodePtr->mWorldTransform.v3.z;
          followerPosition->x = v19 + mTransformNodePtr->mWorldTransform.v3.x;
          followerPosition->y = v22;
          followerPosition->z = v23;
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
UFG::GroupComponent *__fastcall UFG::GroupComponent::GetFollower(UFG::GroupComponent *this, unsigned int index)
{
  return this->mGroupLeader.mFollowers.p[index].m_pPointer;
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
    return (UFG::PedSpawningInfo *)result->mSimObjectPtr.m_pPointer;
  return result;
}

// File Line: 561
// RVA: 0x382A10
void __fastcall UFG::GroupComponent::Reset(UFG::GroupComponent *this)
{
  UFG::GroupComponent *m_pPointer; // rcx
  UFG::qSafePointer<UFG::GroupComponent,UFG::GroupComponent> *p_mLeader; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *mNext; // rax

  m_pPointer = this->mGroupFollower.mLeader.m_pPointer;
  if ( m_pPointer )
  {
    UFG::GroupLeader::Unregister(&m_pPointer->mGroupLeader, this);
    p_mLeader = &this->mGroupFollower.mLeader;
    if ( this->mGroupFollower.mLeader.m_pPointer )
    {
      mPrev = p_mLeader->mPrev;
      mNext = this->mGroupFollower.mLeader.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_mLeader->mPrev = p_mLeader;
      this->mGroupFollower.mLeader.mNext = &this->mGroupFollower.mLeader;
    }
    this->mGroupFollower.mLeader.m_pPointer = 0i64;
  }
  UFG::GroupLeader::Reset(&this->mGroupLeader);
  this->mFlags = 1;
}

// File Line: 588
// RVA: 0x3625A0
UFG::GroupComponent *__fastcall UFG::GroupComponent::GetSharedGroupComponent(UFG::GroupComponent *this)
{
  if ( this->mGroupFollower.mLeader.m_pPointer )
    return this->mGroupFollower.mLeader.m_pPointer;
  return this;
}

// File Line: 600
// RVA: 0x35FDA0
__int64 __fastcall UFG::GroupComponent::GetGroupSize(UFG::GroupComponent *this)
{
  if ( this->mGroupFollower.mLeader.m_pPointer )
    this = this->mGroupFollower.mLeader.m_pPointer;
  if ( this )
    return this->mGroupLeader.mFollowers.size + 1;
  else
    return 1i64;
}

// File Line: 613
// RVA: 0x35FD10
UFG::qSafePointerNode<UFG::SimComponent>Vtbl *__fastcall UFG::GroupComponent::GetGroupComponent(
        UFG::SimObjectGame *pSimObject)
{
  signed __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  if ( pSimObject
    && ((m_Flags = pSimObject->m_Flags, (m_Flags & 0x4000) == 0)
      ? (m_Flags >= 0
       ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
        ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(pSimObject, UFG::AIEntityComponent::_TypeUID))
        : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(pSimObject, UFG::AIEntityComponent::_TypeUID)))
       : (ComponentOfTypeHK = pSimObject->m_Components.p[22].m_pComponent))
      : (ComponentOfTypeHK = pSimObject->m_Components.p[22].m_pComponent),
        ComponentOfTypeHK) )
  {
    return ComponentOfTypeHK[15].vfptr;
  }
  else
  {
    return 0i64;
  }
}

// File Line: 640
// RVA: 0x36B4F0
bool __fastcall UFG::GroupComponent::IsLeader(UFG::SimObjectGame *pSimObject)
{
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *GroupComponent; // rax

  if ( !pSimObject )
    return 0;
  GroupComponent = UFG::GroupComponent::GetGroupComponent(pSimObject);
  if ( !GroupComponent )
    return 0;
  return GroupComponent[28].__vecDelDtor && LODWORD(GroupComponent[15].__vecDelDtor);
}

// File Line: 654
// RVA: 0x36A9F0
bool __fastcall UFG::GroupComponent::IsFollower(UFG::SimObjectGame *pSimObject)
{
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *GroupComponent; // rax

  return pSimObject
      && (GroupComponent = UFG::GroupComponent::GetGroupComponent(pSimObject)) != 0i64
      && GroupComponent[32].__vecDelDtor != 0i64;
}

// File Line: 668
// RVA: 0x36AA50
bool __fastcall UFG::GroupComponent::IsGroupMember(UFG::SimObjectGame *pSimObject)
{
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *GroupComponent; // rax

  if ( !pSimObject )
    return 0;
  GroupComponent = UFG::GroupComponent::GetGroupComponent(pSimObject);
  if ( !GroupComponent )
    return 0;
  return GroupComponent[28].__vecDelDtor && LODWORD(GroupComponent[15].__vecDelDtor) || GroupComponent[32].__vecDelDtor;
}

// File Line: 682
// RVA: 0x36D2B0
void __fastcall UFG::GroupComponent::LeaveGroup(UFG::SimObjectGame *pSimObject)
{
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *GroupComponent; // rax
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v2; // rbx

  GroupComponent = UFG::GroupComponent::GetGroupComponent(pSimObject);
  v2 = GroupComponent;
  if ( GroupComponent )
  {
    UFG::GroupComponent::Reset((UFG::GroupComponent *)GroupComponent);
    if ( (UFG::PedFormationProfile *)v2[28].__vecDelDtor != &ptr )
    {
      UFG::GroupLeader::Reset((UFG::GroupLeader *)&v2[14]);
      v2[28].__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))&ptr;
      ++UFG::gpGroupManager->mGroupTotals.p[0];
    }
    LODWORD(v2[34].__vecDelDtor) |= 1u;
  }
}

