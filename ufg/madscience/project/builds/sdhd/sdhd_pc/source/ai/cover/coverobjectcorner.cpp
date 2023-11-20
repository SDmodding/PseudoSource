// File Line: 47
// RVA: 0x33BC80
UFG::CoverObjectCorner *__fastcall UFG::CoverObjectCorner::operator=(UFG::CoverObjectCorner *this, UFG::CoverObjectCorner *other)
{
  UFG::CoverObjectCorner *v2; // rbx
  UFG::CoverObjectCorner *v3; // rdi

  v2 = other;
  v3 = this;
  (*((void (**)(void))&this->vfptr->__vecDelDtor + 1))();
  v3->m_fPriority = v2->m_fPriority;
  UFG::CoverCornerHandle::operator=(&v3->m_CornerHandle, &v2->m_CornerHandle);
  return v3;
}

// File Line: 56
// RVA: 0x36A3A0
char __fastcall UFG::CoverObjectCorner::IsConnectedTo(UFG::CoverObjectCorner *this, UFG::CoverObjectBase *coOther)
{
  UFG::CoverObjectCorner *v2; // rdi
  UFG::CoverObjectParkour *v3; // rbx
  char result; // al

  v2 = this;
  v3 = (UFG::CoverObjectParkour *)coOther;
  if ( coOther->vfptr->IsParkour(coOther) )
    result = UFG::CoverObjectBase::IsConnected(v3, v2);
  else
    result = UFG::CoverObjectBase::IsConnected(v2, (UFG::CoverObjectCorner *)v3);
  return result;
}

// File Line: 75
// RVA: 0x36B800
bool __fastcall UFG::CoverObjectCorner::IsLeftOf(UFG::CoverObjectCorner *this, UFG::CoverObjectBase *coOther)
{
  UFG::CoverObjectCorner *v2; // rdi
  UFG::CoverObjectParkour *v3; // rbx
  bool result; // al

  v2 = this;
  v3 = (UFG::CoverObjectParkour *)coOther;
  if ( coOther->vfptr->IsParkour(coOther) )
    result = UFG::CoverObjectBase::IsLeft(v3, v2) == 0;
  else
    result = UFG::CoverObjectBase::IsLeft(v2, (UFG::CoverObjectCorner *)v3);
  return result;
}

// File Line: 94
// RVA: 0x35BFD0
UFG::CoverPosition *__fastcall UFG::CoverObjectCorner::GetCoverPosition(UFG::CoverObjectCorner *this, UFG::qVector3 *vCharPos, UFG::CoverPosition *pCurrentPosition, float fRange)
{
  UFG::CoverPosition *v4; // rdi
  UFG::qVector3 *v5; // rbp
  UFG::CoverObjectCorner *v6; // r8
  UFG::DynamicCoverCorner *v7; // rbx
  __int64 v8; // rsi
  UFG::CoverCorner *v9; // rbx
  UFG::qResourceData *v10; // rax
  UFG::qBaseNodeRB *v11; // rcx
  signed __int64 v12; // rcx
  UFG::CoverCornerHandle *v13; // rcx
  UFG::allocator::free_link *v14; // rax
  __int64 v15; // rax
  UFG::qVector3 result; // [rsp+28h] [rbp-30h]

  v4 = pCurrentPosition;
  v5 = vCharPos;
  v6 = this;
  v7 = this->m_CornerHandle.m_pDynamicCoverCorner.m_pPointer;
  v8 = 0i64;
  if ( v7 )
  {
    v9 = (UFG::CoverCorner *)&v7->mPrev;
  }
  else
  {
    v10 = this->m_CornerHandle.m_ResourceHandle.mData;
    if ( v10 )
    {
      v11 = v10[1].mNode.mChild[0];
      if ( v11 )
        v12 = (signed __int64)&v11[3] + (_QWORD)v10;
      else
        v12 = 0i64;
      v9 = (UFG::CoverCorner *)(v12 + 48i64 * v6->m_CornerHandle.m_uCoverCornerIndex);
    }
    else
    {
      v9 = 0i64;
    }
  }
  UFG::CoverCorner::GetSyncPos(v9, &result);
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(result.z - v5->z) & _xmm) >= kfMaxHeightDiff_0
    || (float)((float)((float)(result.y - v5->y) * (float)(result.y - v5->y))
             + (float)((float)(result.x - v5->x) * (float)(result.x - v5->x))) >= (float)(fRange * fRange) )
  {
    return v4;
  }
  if ( v4 )
  {
    if ( v9->m_eCoverSide.mValue == 1 )
      v13 = &v4->m_RightCorner;
    else
      v13 = &v4->m_LeftCorner;
    UFG::CoverCornerHandle::operator=(v13, v9);
    return v4;
  }
  v14 = UFG::qMalloc(0x170ui64, "CoverPosition", 0i64);
  if ( v14 )
  {
    UFG::CoverPosition::CoverPosition((UFG::CoverPosition *)v14, v9);
    v8 = v15;
  }
  return (UFG::CoverPosition *)v8;
}

// File Line: 128
// RVA: 0x35CCC0
char __fastcall UFG::CoverObjectCorner::GetCoverPositions(UFG::CoverObjectCorner *this, UFG::qArray<UFG::CoverPosition *,0> *aCoverPositions)
{
  UFG::qArray<UFG::qReflectInventoryBase *,0> *v2; // rsi
  UFG::CoverObjectCorner *v3; // rdi
  UFG::allocator::free_link *v4; // r8
  UFG::DynamicCoverCorner *v5; // rbx
  UFG::CoverCorner *v6; // rbx
  UFG::qResourceData *v7; // rax
  UFG::qBaseNodeRB *v8; // rcx
  signed __int64 v9; // rcx
  UFG::qReflectInventoryBase *v10; // rax
  UFG::qReflectInventoryBase *v11; // rbx
  __int64 v12; // rbp
  unsigned int v13; // edi
  unsigned int v14; // edx
  unsigned int v15; // edx

  v2 = (UFG::qArray<UFG::qReflectInventoryBase *,0> *)aCoverPositions;
  v3 = this;
  v4 = UFG::qMalloc(0x170ui64, "CoverPosition", 0i64);
  if ( v4 )
  {
    v5 = v3->m_CornerHandle.m_pDynamicCoverCorner.m_pPointer;
    if ( v5 )
    {
      v6 = (UFG::CoverCorner *)&v5->mPrev;
    }
    else
    {
      v7 = v3->m_CornerHandle.m_ResourceHandle.mData;
      if ( v7 )
      {
        v8 = v7[1].mNode.mChild[0];
        if ( v8 )
          v9 = (signed __int64)&v8[3] + (_QWORD)v7;
        else
          v9 = 0i64;
        v6 = (UFG::CoverCorner *)(v9 + 48i64 * v3->m_CornerHandle.m_uCoverCornerIndex);
      }
      else
      {
        v6 = 0i64;
      }
    }
    UFG::CoverPosition::CoverPosition((UFG::CoverPosition *)v4, v6);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  v12 = v2->size;
  v13 = v12 + 1;
  v14 = v2->capacity;
  if ( (signed int)v12 + 1 > v14 )
  {
    if ( v14 )
      v15 = 2 * v14;
    else
      v15 = 1;
    for ( ; v15 < v13; v15 *= 2 )
      ;
    if ( v15 <= 2 )
      v15 = 2;
    if ( v15 - v13 > 0x10000 )
      v15 = v12 + 65537;
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(v2, v15, "qArray.Add");
  }
  v2->size = v13;
  v2->p[v12] = v11;
  return 1;
}

// File Line: 139
// RVA: 0x34E9A0
void __fastcall UFG::CoverObjectCorner::Clear(UFG::CoverObjectCorner *this)
{
  UFG::CoverObjectCorner *v1; // rbx

  v1 = this;
  ((void (*)(void))this->vfptr->RemoveUser)();
  v1->m_fPriority = 0.0;
  v1->m_pCoverObjectGroup = 0i64;
  UFG::CoverCornerHandle::Reset(&v1->m_CornerHandle);
  v1->m_pCoverUser = 0i64;
}

// File Line: 148
// RVA: 0x36BE80
char __fastcall UFG::CoverObjectCorner::IsValid(UFG::CoverObjectCorner *this)
{
  UFG::CoverCornerHandle *v1; // rbx
  UFG::CoverObjectCorner *v2; // rdi
  char result; // al
  signed __int64 v4; // rdi
  UFG::DynamicCoverCorner *v5; // rcx
  UFG::DynamicCoverCorner *v6; // rax
  signed __int64 v7; // rax
  UFG::qResourceData *v8; // rax
  UFG::qBaseNodeRB *v9; // rcx
  signed __int64 v10; // rax
  signed __int64 v11; // rcx
  UFG::qVector3 *v12; // rax

  v1 = &this->m_CornerHandle;
  v2 = this;
  if ( !UFG::CoverCornerHandle::Get(&this->m_CornerHandle) )
    goto LABEL_20;
  if ( !v2->m_CornerHandle.m_pDynamicCoverCorner.m_pPointer )
    goto LABEL_21;
  v4 = 0i64;
  if ( v1->m_ResourceHandle.mData && v1->m_uCoverCornerIndex != -1
    || (v5 = v1->m_pDynamicCoverCorner.m_pPointer) != 0i64
    && UFG::DynamicCoverComponent::IsEnabled((UFG::DynamicCoverComponent *)v5->m_pParentInstance.m_pPointer) )
  {
    v6 = v1->m_pDynamicCoverCorner.m_pPointer;
    if ( v6 )
    {
      v7 = (signed __int64)&v6->mPrev;
    }
    else
    {
      v8 = v1->m_ResourceHandle.mData;
      v9 = v8[1].mNode.mChild[0];
      v10 = (signed __int64)v8[1].mNode.mChild;
      if ( v9 )
        v11 = (signed __int64)v9 + v10;
      else
        v11 = 0i64;
      v7 = v11 + 48i64 * v1->m_uCoverCornerIndex;
    }
    if ( v7 )
      v4 = v7 - 24;
  }
  v12 = UFG::DynamicCoverComponent::GetVelocity(*(UFG::DynamicCoverComponent **)(v4 + 88));
  if ( (float)((float)(v12->x * v12->x) + (float)(v12->y * v12->y)) >= (float)(UFG::CoverObjectBase::ms_fMaxCoverVelocity
                                                                             * UFG::CoverObjectBase::ms_fMaxCoverVelocity) )
LABEL_20:
    result = 0;
  else
LABEL_21:
    result = 1;
  return result;
}

// File Line: 171
// RVA: 0x365000
bool __fastcall UFG::CoverObjectCorner::InRange2(UFG::CoverObjectCorner *this, UFG::qVector3 *vPosition, float fRange2)
{
  UFG::DynamicCoverCorner *v3; // rax
  UFG::qVector3 *v4; // r10
  float *v5; // rax
  UFG::qResourceData *v6; // rax
  UFG::qBaseNodeRB *v7; // rdx
  signed __int64 v8; // r9

  v3 = this->m_CornerHandle.m_pDynamicCoverCorner.m_pPointer;
  v4 = vPosition;
  if ( v3 )
  {
    v5 = (float *)&v3->mPrev;
  }
  else
  {
    v6 = this->m_CornerHandle.m_ResourceHandle.mData;
    if ( v6 )
    {
      v7 = v6[1].mNode.mChild[0];
      if ( v7 )
        v8 = (signed __int64)v6[1].mNode.mChild + (_QWORD)v7;
      else
        v8 = 0i64;
      v5 = (float *)(v8 + 48i64 * this->m_CornerHandle.m_uCoverCornerIndex);
    }
    else
    {
      v5 = 0i64;
    }
  }
  return fRange2 > (float)((float)((float)((float)(v5[5] - v4->y) * (float)(v5[5] - v4->y))
                                 + (float)((float)(v5[4] - v4->x) * (float)(v5[4] - v4->x)))
                         + (float)((float)(v5[6] - v4->z) * (float)(v5[6] - v4->z)));
}

// File Line: 182
// RVA: 0x361F30
UFG::qVector3 *__fastcall UFG::CoverObjectCorner::GetPosition(UFG::CoverObjectCorner *this, UFG::qVector3 *result)
{
  UFG::qVector3 *v2; // rbx
  float *v3; // rax
  float v4; // ecx

  v2 = result;
  v3 = (float *)UFG::CoverCornerHandle::Get(&this->m_CornerHandle);
  v2->x = v3[4];
  v4 = v3[5];
  v2->z = v3[6];
  v2->y = v4;
  return v2;
}

// File Line: 189
// RVA: 0x35F640
UFG::qVector3 *__fastcall UFG::CoverObjectCorner::GetFiringPosition(UFG::CoverObjectCorner *this, UFG::qVector3 *result)
{
  UFG::qVector3 *v2; // rbx
  UFG::CoverCorner *v3; // rax

  v2 = result;
  v3 = (UFG::CoverCorner *)UFG::CoverCornerHandle::Get(&this->m_CornerHandle);
  UFG::CoverCorner::GetFiringPos(v3, v2);
  return v2;
}

// File Line: 196
// RVA: 0x3628C0
UFG::qVector3 *__fastcall UFG::CoverObjectCorner::GetSweetSpotDir(UFG::CoverObjectCorner *this, UFG::qVector3 *result)
{
  UFG::qVector3 *v2; // rbx
  UFG::CoverCorner *v3; // rax

  v2 = result;
  v3 = (UFG::CoverCorner *)UFG::CoverCornerHandle::Get(&this->m_CornerHandle);
  UFG::CoverCorner::GetSweetSpotDir(v3, v2);
  return v2;
}

// File Line: 203
// RVA: 0x3636A0
UFG::qVector3 *__fastcall UFG::CoverObjectCorner::GetWallNormal(UFG::CoverObjectCorner *this, UFG::qVector3 *result)
{
  UFG::qVector3 *v2; // rbx
  signed __int64 v3; // rax
  float v4; // ecx
  UFG::qVector3 *v5; // rax

  v2 = result;
  v3 = UFG::CoverCornerHandle::Get(&this->m_CornerHandle);
  v2->z = 0.0;
  v4 = *(float *)(v3 + 28);
  v2->y = *(float *)(v3 + 32);
  v5 = v2;
  v2->x = v4;
  return v5;
}

// File Line: 210
// RVA: 0x362940
UFG::qVector3 *__fastcall UFG::CoverObjectCorner::GetSyncPos(UFG::CoverObjectCorner *this, UFG::qVector3 *result)
{
  UFG::qVector3 *v2; // rbx
  UFG::CoverCorner *v3; // rax

  v2 = result;
  v3 = (UFG::CoverCorner *)UFG::CoverCornerHandle::Get(&this->m_CornerHandle);
  UFG::CoverCorner::GetSyncPos(v3, v2);
  return v2;
}

// File Line: 217
// RVA: 0x360070
bool __fastcall UFG::CoverObjectCorner::GetInUse(UFG::CoverObjectCorner *this)
{
  UFG::CoverObjectCorner *v1; // rbx
  UFG::DynamicCoverCorner *v2; // rax
  UFG::qResourceData *v4; // rax
  UFG::qBaseNodeRB *v5; // rcx
  signed __int64 v6; // r8

  v1 = this;
  if ( !(*((unsigned __int8 (**)(void))&this->vfptr->__vecDelDtor + 2))() )
    return 0;
  v2 = v1->m_CornerHandle.m_pDynamicCoverCorner.m_pPointer;
  if ( v2 )
    return v2->m_IsInUse != 0;
  v4 = v1->m_CornerHandle.m_ResourceHandle.mData;
  if ( !v4 )
    return MEMORY[0x26] != 0;
  v5 = v4[1].mNode.mChild[0];
  if ( v5 )
    v6 = (signed __int64)v4[1].mNode.mChild + (_QWORD)v5;
  else
    v6 = 0i64;
  return *(_BYTE *)(v6 + 48i64 * v1->m_CornerHandle.m_uCoverCornerIndex + 38) != 0;
}

// File Line: 227
// RVA: 0x386810
void __fastcall UFG::CoverObjectCorner::SetInUse(UFG::CoverObjectCorner *this, bool bInUse)
{
  UFG::DynamicCoverCorner *v2; // rax
  bool v3; // r8
  UFG::qResourceData *v4; // rax
  UFG::qBaseNodeRB *v5; // rdx

  v2 = this->m_CornerHandle.m_pDynamicCoverCorner.m_pPointer;
  v3 = bInUse;
  if ( v2 )
  {
    v2->m_IsInUse = bInUse;
  }
  else
  {
    v4 = this->m_CornerHandle.m_ResourceHandle.mData;
    if ( v4 )
    {
      v5 = v4[1].mNode.mChild[0];
      if ( v5 )
        v5 = (UFG::qBaseNodeRB *)((char *)v5 + (_QWORD)v4 + 96);
      *((_BYTE *)&v5[1].mParent + 48 * this->m_CornerHandle.m_uCoverCornerIndex + 6) = v3;
    }
    else
    {
      MEMORY[0x26] = bInUse;
    }
  }
}

// File Line: 243
// RVA: 0x341550
void __fastcall UFG::CoverObjectCorner::AddUser(UFG::CoverObjectCorner *this, UFG::SimObject *pUser)
{
  UFG::SimObject *v2; // rsi
  UFG::CoverObjectCorner *v3; // rdi
  _BOOL8 v4; // rdx
  UFG::DynamicCoverCorner *v5; // rbx
  signed __int64 v6; // rbx
  UFG::qResourceData *v7; // rax
  UFG::qBaseNodeRB *v8; // rcx
  UFG::allocator::free_link *v9; // rax
  UFG::qNode<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser> *v10; // rcx
  UFG::qNode<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser> *v11; // rax

  v2 = pUser;
  v3 = this;
  ((void (__cdecl *)(UFG::CoverObjectCorner *))this->vfptr->GetInUse)(this);
  LOBYTE(v4) = 1;
  v3->vfptr->SetInUse((UFG::CoverObjectBase *)&v3->vfptr, v4);
  v5 = v3->m_CornerHandle.m_pDynamicCoverCorner.m_pPointer;
  if ( v5 )
  {
    v6 = (signed __int64)&v5->mPrev;
  }
  else
  {
    v7 = v3->m_CornerHandle.m_ResourceHandle.mData;
    if ( v7 )
    {
      v8 = v7[1].mNode.mChild[0];
      if ( v8 )
        v8 = (UFG::qBaseNodeRB *)((char *)v8 + (_QWORD)v7 + 96);
      v6 = (signed __int64)v8 + 48 * v3->m_CornerHandle.m_uCoverCornerIndex;
    }
    else
    {
      v6 = 0i64;
    }
  }
  v9 = UFG::qMalloc(0x20ui64, "CoverUser", 0i64);
  if ( v9 )
  {
    v9->mNext = v9;
    v9[1].mNext = v9;
  }
  v3->m_pCoverUser = (UFG::CoverObjectBase::CoverUser *)v9;
  v9[2].mNext = (UFG::allocator::free_link *)v6;
  v3->m_pCoverUser->pUser = v2;
  v10 = (UFG::qNode<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser> *)&v3->m_pCoverUser->mPrev;
  v11 = UFG::CoverObjectBase::ms_listUsers.mNode.mPrev;
  UFG::CoverObjectBase::ms_listUsers.mNode.mPrev->mNext = v10;
  v10->mPrev = v11;
  v10->mNext = (UFG::qNode<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser> *)&UFG::CoverObjectBase::ms_listUsers;
  UFG::CoverObjectBase::ms_listUsers.mNode.mPrev = v10;
}

// File Line: 263
// RVA: 0x3815B0
void __fastcall UFG::CoverObjectCorner::RemoveUser(UFG::CoverObjectCorner *this)
{
  UFG::CoverObjectCorner *v1; // rbx
  UFG::CoverObjectBase::CoverUser *v2; // rdx
  UFG::qNode<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser> *v3; // rcx
  UFG::qNode<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser> *v4; // rax

  v1 = this;
  if ( (*((unsigned __int8 (**)(void))&this->vfptr->__vecDelDtor + 2))() )
    v1->vfptr->GetInUse((UFG::CoverObjectBase *)&v1->vfptr);
  v1->vfptr->SetInUse((UFG::CoverObjectBase *)&v1->vfptr, 0);
  v2 = v1->m_pCoverUser;
  if ( v2 )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser> *)&v2->mPrev;
    v1->m_pCoverUser = 0i64;
  }
}

// File Line: 283
// RVA: 0x34C960
char __fastcall UFG::CoverObjectCorner::CanUse(UFG::CoverObjectCorner *this, UFG::SimObject *pUser)
{
  UFG::SimObject *v2; // rdi
  UFG::CoverObjectCorner *v3; // rbx
  UFG::DynamicCoverCorner *v5; // rcx
  signed __int64 v6; // rcx
  UFG::qResourceData *v7; // rax
  UFG::qBaseNodeRB *v8; // rcx
  signed __int64 v9; // rdx
  UFG::qList<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser,1,0> *v10; // rax

  v2 = pUser;
  v3 = this;
  if ( (*((unsigned __int8 (**)(void))&this->vfptr->__vecDelDtor + 2))() )
  {
    if ( !v3->vfptr->GetInUse((UFG::CoverObjectBase *)&v3->vfptr) )
      return 1;
    v5 = v3->m_CornerHandle.m_pDynamicCoverCorner.m_pPointer;
    if ( v5 )
    {
      v6 = (signed __int64)&v5->mPrev;
    }
    else
    {
      v7 = v3->m_CornerHandle.m_ResourceHandle.mData;
      if ( v7 )
      {
        v8 = v7[1].mNode.mChild[0];
        if ( v8 )
          v9 = (signed __int64)v7[1].mNode.mChild + (_QWORD)v8;
        else
          v9 = 0i64;
        v6 = v9 + 48i64 * v3->m_CornerHandle.m_uCoverCornerIndex;
      }
      else
      {
        v6 = 0i64;
      }
    }
    v10 = (UFG::qList<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser,1,0> *)UFG::CoverObjectBase::ms_listUsers.mNode.mNext;
    if ( (UFG::qList<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser,1,0> *)UFG::CoverObjectBase::ms_listUsers.mNode.mNext != &UFG::CoverObjectBase::ms_listUsers )
    {
      while ( v10[1].mNode.mPrev != (UFG::qNode<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser> *)v6
           || (UFG::SimObject *)v10[1].mNode.mNext != v2 )
      {
        v10 = (UFG::qList<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser,1,0> *)v10->mNode.mNext;
        if ( v10 == &UFG::CoverObjectBase::ms_listUsers )
          return 0;
      }
      return 1;
    }
  }
  return 0;
}

// File Line: 309
// RVA: 0x369A30
bool __fastcall UFG::CoverObjectCorner::IsAnyLineOrCornerShared(UFG::CoverObjectCorner *this, UFG::CoverObjectBase *pOther)
{
  UFG::CoverObjectCorner *v2; // rbx
  UFG::CoverObjectBase *v3; // rdi
  signed __int64 v4; // rbx
  bool result; // al

  v2 = this;
  v3 = pOther;
  result = 0;
  if ( pOther->vfptr->IsCorner(pOther) )
  {
    v4 = UFG::CoverCornerHandle::Get(&v2->m_CornerHandle);
    if ( v4 )
    {
      if ( v4 == UFG::CoverCornerHandle::Get((UFG::CoverCornerHandle *)&v3[1]) )
        result = 1;
    }
  }
  return result;
}

