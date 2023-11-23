// File Line: 47
// RVA: 0x33BC80
UFG::CoverObjectCorner *__fastcall UFG::CoverObjectCorner::operator=(
        UFG::CoverObjectCorner *this,
        UFG::CoverObjectCorner *other)
{
  (*((void (__fastcall **)(UFG::CoverObjectCorner *))&this->vfptr->__vecDelDtor + 1))(this);
  this->m_fPriority = other->m_fPriority;
  UFG::CoverCornerHandle::operator=(&this->m_CornerHandle, &other->m_CornerHandle);
  return this;
}

// File Line: 56
// RVA: 0x36A3A0
char __fastcall UFG::CoverObjectCorner::IsConnectedTo(UFG::CoverObjectCorner *this, UFG::CoverObjectParkour *coOther)
{
  if ( coOther->vfptr->IsParkour(coOther) )
    return UFG::CoverObjectBase::IsConnected(coOther, this);
  else
    return UFG::CoverObjectBase::IsConnected(this, (UFG::CoverObjectCorner *)coOther);
}

// File Line: 75
// RVA: 0x36B800
bool __fastcall UFG::CoverObjectCorner::IsLeftOf(UFG::CoverObjectCorner *this, UFG::CoverObjectParkour *coOther)
{
  if ( coOther->vfptr->IsParkour(coOther) )
    return !UFG::CoverObjectBase::IsLeft(coOther, this);
  else
    return UFG::CoverObjectBase::IsLeft(this, (UFG::CoverObjectCorner *)coOther);
}

// File Line: 94
// RVA: 0x35BFD0
UFG::CoverPosition *__fastcall UFG::CoverObjectCorner::GetCoverPosition(
        UFG::CoverObjectCorner *this,
        UFG::qVector3 *vCharPos,
        UFG::CoverPosition *pCurrentPosition,
        float fRange)
{
  UFG::DynamicCoverCorner *m_pPointer; // rbx
  __int64 v8; // rsi
  UFG::CoverCorner *v9; // rbx
  UFG::qResourceData *mData; // rax
  UFG::qBaseNodeRB *v11; // rcx
  char *v12; // rcx
  UFG::CoverCornerHandle *p_m_RightCorner; // rcx
  UFG::allocator::free_link *v14; // rax
  __int64 v15; // rax
  UFG::qVector3 result; // [rsp+28h] [rbp-30h] BYREF

  m_pPointer = this->m_CornerHandle.m_pDynamicCoverCorner.m_pPointer;
  v8 = 0i64;
  if ( m_pPointer )
  {
    v9 = &m_pPointer->UFG::CoverCorner;
  }
  else
  {
    mData = this->m_CornerHandle.m_ResourceHandle.mData;
    if ( mData )
    {
      v11 = mData[1].mNode.mChild[0];
      if ( v11 )
        v12 = (char *)&v11[3] + (_QWORD)mData;
      else
        v12 = 0i64;
      v9 = (UFG::CoverCorner *)&v12[48 * this->m_CornerHandle.m_uCoverCornerIndex];
    }
    else
    {
      v9 = 0i64;
    }
  }
  UFG::CoverCorner::GetSyncPos(v9, &result);
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(result.z - vCharPos->z) & _xmm) >= kfMaxHeightDiff_0
    || (float)((float)((float)(result.y - vCharPos->y) * (float)(result.y - vCharPos->y))
             + (float)((float)(result.x - vCharPos->x) * (float)(result.x - vCharPos->x))) >= (float)(fRange * fRange) )
  {
    return pCurrentPosition;
  }
  if ( pCurrentPosition )
  {
    if ( v9->m_eCoverSide.mValue == 1 )
      p_m_RightCorner = &pCurrentPosition->m_RightCorner;
    else
      p_m_RightCorner = &pCurrentPosition->m_LeftCorner;
    UFG::CoverCornerHandle::operator=(p_m_RightCorner, v9);
    return pCurrentPosition;
  }
  v14 = UFG::qMalloc(0x170ui64, "CoverPosition", 0i64);
  if ( v14 )
  {
    UFG::CoverPosition::CoverPosition((UFG::CoverPosition *)v14, v9);
    return (UFG::CoverPosition *)v15;
  }
  return (UFG::CoverPosition *)v8;
}

// File Line: 128
// RVA: 0x35CCC0
char __fastcall UFG::CoverObjectCorner::GetCoverPositions(
        UFG::CoverObjectCorner *this,
        UFG::qArray<UFG::qReflectInventoryBase *,0> *aCoverPositions)
{
  UFG::allocator::free_link *v4; // r8
  UFG::DynamicCoverCorner *m_pPointer; // rbx
  UFG::CoverCorner *v6; // rbx
  UFG::qResourceData *mData; // rax
  UFG::qBaseNodeRB *v8; // rcx
  char *v9; // rcx
  UFG::CoverPosition *v10; // rax
  UFG::CoverPosition *v11; // rbx
  __int64 size; // rbp
  unsigned int v13; // edi
  unsigned int capacity; // edx
  unsigned int v15; // edx

  v4 = UFG::qMalloc(0x170ui64, "CoverPosition", 0i64);
  if ( v4 )
  {
    m_pPointer = this->m_CornerHandle.m_pDynamicCoverCorner.m_pPointer;
    if ( m_pPointer )
    {
      v6 = &m_pPointer->UFG::CoverCorner;
    }
    else
    {
      mData = this->m_CornerHandle.m_ResourceHandle.mData;
      if ( mData )
      {
        v8 = mData[1].mNode.mChild[0];
        if ( v8 )
          v9 = (char *)&v8[3] + (_QWORD)mData;
        else
          v9 = 0i64;
        v6 = (UFG::CoverCorner *)&v9[48 * this->m_CornerHandle.m_uCoverCornerIndex];
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
  size = aCoverPositions->size;
  v13 = size + 1;
  capacity = aCoverPositions->capacity;
  if ( (int)size + 1 > capacity )
  {
    if ( capacity )
      v15 = 2 * capacity;
    else
      v15 = 1;
    for ( ; v15 < v13; v15 *= 2 )
      ;
    if ( v15 <= 2 )
      v15 = 2;
    if ( v15 - v13 > 0x10000 )
      v15 = size + 65537;
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(aCoverPositions, v15, "qArray.Add");
  }
  aCoverPositions->size = v13;
  aCoverPositions->p[size] = (UFG::qReflectInventoryBase *)v11;
  return 1;
}

// File Line: 139
// RVA: 0x34E9A0
void __fastcall UFG::CoverObjectCorner::Clear(UFG::CoverObjectCorner *this)
{
  this->vfptr->RemoveUser(this);
  this->m_fPriority = 0.0;
  this->m_pCoverObjectGroup = 0i64;
  UFG::CoverCornerHandle::Reset(&this->m_CornerHandle);
  this->m_pCoverUser = 0i64;
}

// File Line: 148
// RVA: 0x36BE80
bool __fastcall UFG::CoverObjectCorner::IsValid(UFG::CoverObjectCorner *this)
{
  UFG::CoverCornerHandle *p_m_CornerHandle; // rbx
  UFG::CoverCorner *v4; // rdi
  UFG::DynamicCoverCorner *v5; // rcx
  UFG::DynamicCoverCorner *m_pPointer; // rax
  UFG::CoverCorner *v7; // rax
  UFG::qResourceData *mData; // rax
  UFG::qBaseNodeRB *v9; // rcx
  UFG::qBaseNodeRB **mChild; // rax
  __int64 v11; // rcx
  UFG::qVector3 *Velocity; // rax

  p_m_CornerHandle = &this->m_CornerHandle;
  if ( !UFG::CoverCornerHandle::Get(&this->m_CornerHandle) )
    return 0;
  if ( !this->m_CornerHandle.m_pDynamicCoverCorner.m_pPointer )
    return 1;
  v4 = 0i64;
  if ( p_m_CornerHandle->m_ResourceHandle.mData && p_m_CornerHandle->m_uCoverCornerIndex != 0xFFFF
    || (v5 = p_m_CornerHandle->m_pDynamicCoverCorner.m_pPointer) != 0i64
    && UFG::DynamicCoverComponent::IsEnabled((UFG::DynamicCoverComponent *)v5->m_pParentInstance.m_pPointer) )
  {
    m_pPointer = p_m_CornerHandle->m_pDynamicCoverCorner.m_pPointer;
    if ( m_pPointer )
    {
      v7 = &m_pPointer->UFG::CoverCorner;
    }
    else
    {
      mData = p_m_CornerHandle->m_ResourceHandle.mData;
      v9 = mData[1].mNode.mChild[0];
      mChild = mData[1].mNode.mChild;
      if ( v9 )
        v11 = (__int64)v9 + (_QWORD)mChild;
      else
        v11 = 0i64;
      v7 = (UFG::CoverCorner *)(v11 + 48i64 * p_m_CornerHandle->m_uCoverCornerIndex);
    }
    if ( v7 )
      v4 = (UFG::CoverCorner *)((char *)v7 - 24);
  }
  Velocity = UFG::DynamicCoverComponent::GetVelocity(*(UFG::DynamicCoverComponent **)&v4[1].m_fWallHeight);
  return (float)((float)(Velocity->x * Velocity->x) + (float)(Velocity->y * Velocity->y)) < (float)(UFG::CoverObjectBase::ms_fMaxCoverVelocity
                                                                                                  * UFG::CoverObjectBase::ms_fMaxCoverVelocity);
}

// File Line: 171
// RVA: 0x365000
bool __fastcall UFG::CoverObjectCorner::InRange2(UFG::CoverObjectCorner *this, UFG::qVector3 *vPosition, float fRange2)
{
  UFG::DynamicCoverCorner *m_pPointer; // rax
  float *v5; // rax
  UFG::qResourceData *mData; // rax
  UFG::qBaseNodeRB *v7; // rdx
  char *v8; // r9

  m_pPointer = this->m_CornerHandle.m_pDynamicCoverCorner.m_pPointer;
  if ( m_pPointer )
  {
    v5 = (float *)&m_pPointer->UFG::CoverCorner;
  }
  else
  {
    mData = this->m_CornerHandle.m_ResourceHandle.mData;
    if ( mData )
    {
      v7 = mData[1].mNode.mChild[0];
      if ( v7 )
        v8 = (char *)mData[1].mNode.mChild + (_QWORD)v7;
      else
        v8 = 0i64;
      v5 = (float *)&v8[48 * this->m_CornerHandle.m_uCoverCornerIndex];
    }
    else
    {
      v5 = 0i64;
    }
  }
  return fRange2 > (float)((float)((float)((float)(v5[5] - vPosition->y) * (float)(v5[5] - vPosition->y))
                                 + (float)((float)(v5[4] - vPosition->x) * (float)(v5[4] - vPosition->x)))
                         + (float)((float)(v5[6] - vPosition->z) * (float)(v5[6] - vPosition->z)));
}

// File Line: 182
// RVA: 0x361F30
UFG::qVector3 *__fastcall UFG::CoverObjectCorner::GetPosition(UFG::CoverObjectCorner *this, UFG::qVector3 *result)
{
  *result = UFG::CoverCornerHandle::Get(&this->m_CornerHandle)->m_vCornerPosition;
  return result;
}

// File Line: 189
// RVA: 0x35F640
UFG::qVector3 *__fastcall UFG::CoverObjectCorner::GetFiringPosition(
        UFG::CoverObjectCorner *this,
        UFG::qVector3 *result)
{
  UFG::CoverCorner *v3; // rax

  v3 = UFG::CoverCornerHandle::Get(&this->m_CornerHandle);
  UFG::CoverCorner::GetFiringPos(v3, result);
  return result;
}

// File Line: 196
// RVA: 0x3628C0
UFG::qVector3 *__fastcall UFG::CoverObjectCorner::GetSweetSpotDir(UFG::CoverObjectCorner *this, UFG::qVector3 *result)
{
  UFG::CoverCorner *v3; // rax

  v3 = UFG::CoverCornerHandle::Get(&this->m_CornerHandle);
  UFG::CoverCorner::GetSweetSpotDir(v3, result);
  return result;
}

// File Line: 203
// RVA: 0x3636A0
UFG::qVector3 *__fastcall UFG::CoverObjectCorner::GetWallNormal(UFG::CoverObjectCorner *this, UFG::qVector3 *result)
{
  UFG::CoverCorner *v3; // rax
  float x; // ecx
  UFG::qVector3 *v5; // rax

  v3 = UFG::CoverCornerHandle::Get(&this->m_CornerHandle);
  result->z = 0.0;
  x = v3->m_vWallNormal.x;
  result->y = v3->m_vWallNormal.y;
  v5 = result;
  result->x = x;
  return v5;
}

// File Line: 210
// RVA: 0x362940
UFG::qVector3 *__fastcall UFG::CoverObjectCorner::GetSyncPos(UFG::CoverObjectCorner *this, UFG::qVector3 *result)
{
  UFG::CoverCorner *v3; // rax

  v3 = UFG::CoverCornerHandle::Get(&this->m_CornerHandle);
  UFG::CoverCorner::GetSyncPos(v3, result);
  return result;
}

// File Line: 217
// RVA: 0x360070
bool __fastcall UFG::CoverObjectCorner::GetInUse(UFG::CoverObjectCorner *this)
{
  UFG::DynamicCoverCorner *m_pPointer; // rax
  UFG::qResourceData *mData; // rax
  UFG::qBaseNodeRB *v5; // rcx
  char *v6; // r8

  if ( !(*((unsigned __int8 (__fastcall **)(UFG::CoverObjectCorner *))&this->vfptr->__vecDelDtor + 2))(this) )
    return 0;
  m_pPointer = this->m_CornerHandle.m_pDynamicCoverCorner.m_pPointer;
  if ( m_pPointer )
    return m_pPointer->m_IsInUse != 0;
  mData = this->m_CornerHandle.m_ResourceHandle.mData;
  if ( !mData )
    return MEMORY[0x26] != 0;
  v5 = mData[1].mNode.mChild[0];
  if ( v5 )
    v6 = (char *)mData[1].mNode.mChild + (_QWORD)v5;
  else
    v6 = 0i64;
  return v6[48 * this->m_CornerHandle.m_uCoverCornerIndex + 38] != 0;
}

// File Line: 227
// RVA: 0x386810
void __fastcall UFG::CoverObjectCorner::SetInUse(UFG::CoverObjectCorner *this, char bInUse)
{
  UFG::DynamicCoverCorner *m_pPointer; // rax
  UFG::qResourceData *mData; // rax
  UFG::qBaseNodeRB *v5; // rdx

  m_pPointer = this->m_CornerHandle.m_pDynamicCoverCorner.m_pPointer;
  if ( m_pPointer )
  {
    m_pPointer->m_IsInUse = bInUse;
  }
  else
  {
    mData = this->m_CornerHandle.m_ResourceHandle.mData;
    if ( mData )
    {
      v5 = mData[1].mNode.mChild[0];
      if ( v5 )
        v5 = (UFG::qBaseNodeRB *)((char *)v5 + (_QWORD)mData + 96);
      *((_BYTE *)&v5[1].mParent + 48 * this->m_CornerHandle.m_uCoverCornerIndex + 6) = bInUse;
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
  _BOOL8 v4; // rdx
  UFG::DynamicCoverCorner *m_pPointer; // rbx
  UFG::CoverCorner *v6; // rbx
  UFG::qResourceData *mData; // rax
  UFG::qBaseNodeRB *v8; // rcx
  UFG::CoverObjectBase::CoverUser *v9; // rax
  UFG::CoverObjectBase::CoverUser *m_pCoverUser; // rcx
  UFG::qNode<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser> *mPrev; // rax

  this->vfptr->GetInUse(this);
  LOBYTE(v4) = 1;
  this->vfptr->SetInUse(this, v4);
  m_pPointer = this->m_CornerHandle.m_pDynamicCoverCorner.m_pPointer;
  if ( m_pPointer )
  {
    v6 = &m_pPointer->UFG::CoverCorner;
  }
  else
  {
    mData = this->m_CornerHandle.m_ResourceHandle.mData;
    if ( mData )
    {
      v8 = mData[1].mNode.mChild[0];
      if ( v8 )
        v8 = (UFG::qBaseNodeRB *)((char *)v8 + (_QWORD)mData + 96);
      v6 = (UFG::CoverCorner *)((char *)v8 + 48 * this->m_CornerHandle.m_uCoverCornerIndex);
    }
    else
    {
      v6 = 0i64;
    }
  }
  v9 = (UFG::CoverObjectBase::CoverUser *)UFG::qMalloc(0x20ui64, "CoverUser", 0i64);
  if ( v9 )
  {
    v9->mPrev = v9;
    v9->mNext = v9;
  }
  this->m_pCoverUser = v9;
  v9->pCoverObject = v6;
  this->m_pCoverUser->pUser = pUser;
  m_pCoverUser = this->m_pCoverUser;
  mPrev = UFG::CoverObjectBase::ms_listUsers.mNode.mPrev;
  UFG::CoverObjectBase::ms_listUsers.mNode.mPrev->mNext = m_pCoverUser;
  m_pCoverUser->mPrev = mPrev;
  m_pCoverUser->mNext = (UFG::qNode<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser> *)&UFG::CoverObjectBase::ms_listUsers;
  UFG::CoverObjectBase::ms_listUsers.mNode.mPrev = m_pCoverUser;
}

// File Line: 263
// RVA: 0x3815B0
void __fastcall UFG::CoverObjectCorner::RemoveUser(UFG::CoverObjectCorner *this)
{
  UFG::CoverObjectBase::CoverUser *m_pCoverUser; // rdx
  UFG::qNode<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser> *mPrev; // rcx
  UFG::qNode<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser> *mNext; // rax

  if ( (*((unsigned __int8 (__fastcall **)(UFG::CoverObjectCorner *))&this->vfptr->__vecDelDtor + 2))(this) )
    this->vfptr->GetInUse(this);
  this->vfptr->SetInUse(this, 0);
  m_pCoverUser = this->m_pCoverUser;
  if ( m_pCoverUser )
  {
    mPrev = m_pCoverUser->mPrev;
    mNext = m_pCoverUser->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    m_pCoverUser->mPrev = m_pCoverUser;
    m_pCoverUser->mNext = m_pCoverUser;
    this->m_pCoverUser = 0i64;
  }
}

// File Line: 283
// RVA: 0x34C960
char __fastcall UFG::CoverObjectCorner::CanUse(UFG::CoverObjectCorner *this, UFG::SimObject *pUser)
{
  UFG::DynamicCoverCorner *m_pPointer; // rcx
  UFG::CoverCorner *v6; // rcx
  UFG::qResourceData *mData; // rax
  UFG::qBaseNodeRB *v8; // rcx
  char *v9; // rdx
  UFG::qNode<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser> *mNext; // rax

  if ( (*((unsigned __int8 (__fastcall **)(UFG::CoverObjectCorner *))&this->vfptr->__vecDelDtor + 2))(this) )
  {
    if ( !this->vfptr->GetInUse(this) )
      return 1;
    m_pPointer = this->m_CornerHandle.m_pDynamicCoverCorner.m_pPointer;
    if ( m_pPointer )
    {
      v6 = &m_pPointer->UFG::CoverCorner;
    }
    else
    {
      mData = this->m_CornerHandle.m_ResourceHandle.mData;
      if ( mData )
      {
        v8 = mData[1].mNode.mChild[0];
        if ( v8 )
          v9 = (char *)mData[1].mNode.mChild + (_QWORD)v8;
        else
          v9 = 0i64;
        v6 = (UFG::CoverCorner *)&v9[48 * this->m_CornerHandle.m_uCoverCornerIndex];
      }
      else
      {
        v6 = 0i64;
      }
    }
    mNext = UFG::CoverObjectBase::ms_listUsers.mNode.mNext;
    if ( (UFG::qList<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser,1,0> *)UFG::CoverObjectBase::ms_listUsers.mNode.mNext != &UFG::CoverObjectBase::ms_listUsers )
    {
      while ( (UFG::CoverCorner *)mNext[1].mPrev != v6 || (UFG::SimObject *)mNext[1].mNext != pUser )
      {
        mNext = mNext->mNext;
        if ( mNext == (UFG::qNode<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser> *)&UFG::CoverObjectBase::ms_listUsers )
          return 0;
      }
      return 1;
    }
  }
  return 0;
}

// File Line: 309
// RVA: 0x369A30
bool __fastcall UFG::CoverObjectCorner::IsAnyLineOrCornerShared(
        UFG::CoverObjectCorner *this,
        UFG::CoverObjectBase *pOther)
{
  UFG::CoverCorner *v4; // rbx
  bool result; // al

  result = 0;
  if ( pOther->vfptr->IsCorner(pOther) )
  {
    v4 = UFG::CoverCornerHandle::Get(&this->m_CornerHandle);
    if ( v4 )
    {
      if ( v4 == UFG::CoverCornerHandle::Get((UFG::CoverCornerHandle *)&pOther[1]) )
        return 1;
    }
  }
  return result;
}

