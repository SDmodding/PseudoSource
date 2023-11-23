// File Line: 47
// RVA: 0x32D5A0
void __fastcall UFG::CoverObjectParkour::CoverObjectParkour(
        UFG::CoverObjectParkour *this,
        UFG::ParkourHandle *pParkourHandle)
{
  UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle> *p_m_pParkourHandle; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *mPrev; // rax

  this->vfptr = (UFG::CoverObjectBaseVtbl *)&UFG::CoverObjectBase::`vftable;
  this->m_iRefCount = 0;
  this->m_pCoverObjectGroup = 0i64;
  this->m_fPriority = 0.0;
  this->vfptr = (UFG::CoverObjectBaseVtbl *)&UFG::CoverObjectParkour::`vftable;
  p_m_pParkourHandle = &this->m_pParkourHandle;
  this->m_pParkourHandle.mPrev = &this->m_pParkourHandle;
  this->m_pParkourHandle.mNext = &this->m_pParkourHandle;
  this->m_pParkourHandle.m_pPointer = pParkourHandle;
  if ( pParkourHandle )
  {
    mPrev = pParkourHandle->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::ParkourHandle>::mPrev;
    mPrev->mNext = p_m_pParkourHandle;
    p_m_pParkourHandle->mPrev = mPrev;
    this->m_pParkourHandle.mNext = &pParkourHandle->m_SafePointerList.mNode;
    pParkourHandle->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::ParkourHandle>::mPrev = p_m_pParkourHandle;
  }
  this->m_bFoundParkourSync = 0;
  this->m_pCoverUser = 0i64;
}

// File Line: 52
// RVA: 0x33BCC0
UFG::CoverObjectParkour *__fastcall UFG::CoverObjectParkour::operator=(
        UFG::CoverObjectParkour *this,
        UFG::CoverObjectParkour *other)
{
  UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle> *p_m_pParkourHandle; // r8
  UFG::ParkourHandle *m_pPointer; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *p_mNode; // rcx

  (*((void (__fastcall **)(UFG::CoverObjectParkour *))&this->vfptr->__vecDelDtor + 1))(this);
  p_m_pParkourHandle = &this->m_pParkourHandle;
  this->m_fPriority = other->m_fPriority;
  m_pPointer = other->m_pParkourHandle.m_pPointer;
  if ( this->m_pParkourHandle.m_pPointer )
  {
    mPrev = p_m_pParkourHandle->mPrev;
    mNext = this->m_pParkourHandle.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pParkourHandle->mPrev = p_m_pParkourHandle;
    this->m_pParkourHandle.mNext = &this->m_pParkourHandle;
  }
  this->m_pParkourHandle.m_pPointer = m_pPointer;
  if ( m_pPointer )
  {
    v8 = m_pPointer->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::ParkourHandle>::mPrev;
    p_mNode = &m_pPointer->m_SafePointerList.mNode;
    v8->mNext = p_m_pParkourHandle;
    p_m_pParkourHandle->mPrev = v8;
    this->m_pParkourHandle.mNext = p_mNode;
    p_mNode->mPrev = p_m_pParkourHandle;
  }
  this->m_bFoundParkourSync = other->m_bFoundParkourSync;
  this->m_fParkourSyncZOffset = other->m_fParkourSyncZOffset;
  return this;
}

// File Line: 64
// RVA: 0x36BFD0
bool __fastcall UFG::CoverObjectParkour::IsValid(UFG::CoverObjectParkour *this)
{
  UFG::ParkourHandle *m_pPointer; // rcx
  UFG::SimObject *v3; // rbx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  bool result; // al

  m_pPointer = this->m_pParkourHandle.m_pPointer;
  result = 0;
  if ( m_pPointer )
  {
    if ( UFG::ParkourHandle::IsEnabled(m_pPointer) )
    {
      v3 = this->m_pParkourHandle.m_pPointer->mSimObject.m_pPointer;
      if ( !v3 )
        return 1;
      m_pTransformNodeComponent = v3->m_pTransformNodeComponent;
      if ( !m_pTransformNodeComponent )
        return 1;
      UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
      if ( (float)((float)(m_pTransformNodeComponent->mWorldVelocity.x * m_pTransformNodeComponent->mWorldVelocity.x)
                 + (float)(m_pTransformNodeComponent->mWorldVelocity.y * m_pTransformNodeComponent->mWorldVelocity.y)) < (float)(UFG::CoverObjectBase::ms_fMaxCoverVelocity * UFG::CoverObjectBase::ms_fMaxCoverVelocity) )
        return 1;
    }
  }
  return result;
}

// File Line: 88
// RVA: 0x36A3F0
char __fastcall UFG::CoverObjectParkour::IsConnectedTo(UFG::CoverObjectParkour *this, UFG::CoverObjectParkour *other)
{
  if ( other->vfptr->IsParkour(other) )
    return UFG::CoverObjectBase::IsConnected(this, other);
  else
    return UFG::CoverObjectBase::IsConnected(this, (UFG::CoverObjectCorner *)other);
}

// File Line: 107
// RVA: 0x36B850
bool __fastcall UFG::CoverObjectParkour::IsLeftOf(UFG::CoverObjectParkour *this, UFG::CoverObjectParkour *other)
{
  if ( other->vfptr->IsParkour(other) )
    return UFG::CoverObjectBase::IsLeft(this, other);
  else
    return UFG::CoverObjectBase::IsLeft(this, (UFG::CoverObjectCorner *)other);
}

// File Line: 127
// RVA: 0x35C270
UFG::CoverPosition *__fastcall UFG::CoverObjectParkour::GetCoverPosition(
        UFG::CoverObjectParkour *this,
        UFG::qVector3 *vCharPos,
        UFG::CoverPosition *pCurrentPosition,
        float fRange)
{
  float v7; // xmm8_4
  float v8; // xmm9_4
  float v9; // xmm7_4
  float v10; // xmm6_4
  __m128 x_low; // xmm2
  __m128 v12; // xmm1
  float v13; // xmm8_4
  float v14; // xmm7_4
  UFG::allocator::free_link *v15; // rax
  UFG::CoverPosition *v16; // rax
  float HalfLength; // xmm0_4
  float SideOffset; // xmm0_4
  UFG::qVector3 result; // [rsp+28h] [rbp-70h] BYREF
  UFG::qVector3 p0; // [rsp+38h] [rbp-60h] BYREF
  UFG::qVector3 p1; // [rsp+44h] [rbp-54h] BYREF

  if ( (_S57 & 1) == 0 )
  {
    _S57 |= 1u;
    kfRangeSquared = FLOAT_0_25;
  }
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(
                      (float)(UFG::ParkourHandle::GetPosition(this->m_pParkourHandle.m_pPointer, &result)->z
                            + this->m_fParkourSyncZOffset)
                    - vCharPos->z) & _xmm) < kfMaxHeightDiff_2 )
  {
    UFG::ParkourHandle::GetEndpoints(this->m_pParkourHandle.m_pPointer, &p0, &p1);
    v7 = vCharPos->z - p0.z;
    v8 = vCharPos->y - p0.y;
    v9 = vCharPos->x - p0.x;
    if ( UFG::ParkourHandle::GetNormal(this->m_pParkourHandle.m_pPointer, &result) )
    {
      v10 = (float)((float)(result.x * v9) + (float)(result.y * v8)) + (float)(result.z * v7);
      if ( v10 > 0.0 && v10 < 1.0 )
      {
        x_low = (__m128)LODWORD(p1.x);
        x_low.m128_f32[0] = p1.x - p0.x;
        v12 = x_low;
        v12.m128_f32[0] = (float)(x_low.m128_f32[0] * x_low.m128_f32[0])
                        + (float)((float)(p1.y - p0.y) * (float)(p1.y - p0.y));
        v13 = _mm_sqrt_ps(v12).m128_f32[0];
        v14 = (float)(v9 * (float)((float)(1.0 / v13) * (float)(p1.x - p0.x)))
            + (float)((float)((float)(1.0 / v13) * (float)(p1.y - p0.y)) * v8);
        if ( v14 > 0.0 && v14 < v13 )
        {
          if ( pCurrentPosition )
          {
            UFG::CoverPosition::SetParkourHandle(pCurrentPosition, this->m_pParkourHandle.m_pPointer);
          }
          else
          {
            v15 = UFG::qMalloc(0x170ui64, "CoverPosition", 0i64);
            if ( v15 )
            {
              UFG::CoverPosition::CoverPosition((UFG::CoverPosition *)v15, this->m_pParkourHandle.m_pPointer);
              pCurrentPosition = v16;
            }
            else
            {
              pCurrentPosition = 0i64;
            }
          }
          HalfLength = UFG::ParkourHandle::GetHalfLength(this->m_pParkourHandle.m_pPointer);
          pCurrentPosition->m_bFoundParkourSync = this->m_bFoundParkourSync;
          pCurrentPosition->m_fParkourSyncZOffset = this->m_fParkourSyncZOffset;
          pCurrentPosition->m_fParkourTVal = v14 - HalfLength;
          pCurrentPosition->m_fDistanceInFront = v10;
          if ( pCurrentPosition->m_fDistToLeft < 0.001 && pCurrentPosition->m_fDistToRight < 0.001 )
          {
            SideOffset = UFG::CoverObjectBase::GetSideOffset(pCurrentPosition);
            pCurrentPosition->m_fDistToLeft = v14 - SideOffset;
            pCurrentPosition->m_fDistToRight = (float)(v13 - v14) - SideOffset;
          }
        }
      }
    }
  }
  return pCurrentPosition;
}

// File Line: 193
// RVA: 0x35D3A0
char __fastcall UFG::CoverObjectParkour::GetCoverPositions(
        UFG::CoverObjectParkour *this,
        UFG::qArray<UFG::CoverPosition *,0> *aCoverPositions)
{
  float v4; // xmm8_4
  float v5; // xmm2_4
  float v6; // xmm8_4
  int i; // r15d
  UFG::allocator::free_link *v8; // rax
  UFG::CoverPosition *v9; // rax
  UFG::CoverPosition *v10; // rbp
  float v11; // xmm7_4
  float v12; // xmm6_4
  float HalfLength; // xmm0_4
  __int64 size; // r13
  unsigned int v15; // esi
  unsigned int capacity; // ebx
  unsigned int v17; // ebx
  unsigned __int64 v18; // rax
  UFG::allocator::free_link *v19; // rax
  UFG::CoverPosition **v20; // r14
  __int64 j; // r9

  v4 = UFG::ParkourHandle::GetHalfLength(this->m_pParkourHandle.m_pPointer) * 2.0;
  if ( v4 <= 0.5 )
    return 0;
  v5 = *(float *)&FLOAT_1_0;
  if ( (float)(int)v4 >= 1.0 )
    v5 = (float)(int)v4;
  v6 = v4 / (float)(int)v5;
  for ( i = 0; i < (int)v5; ++i )
  {
    v8 = UFG::qMalloc(0x170ui64, "CoverPosition", 0i64);
    if ( v8 )
    {
      UFG::CoverPosition::CoverPosition((UFG::CoverPosition *)v8, this->m_pParkourHandle.m_pPointer);
      v10 = v9;
    }
    else
    {
      v10 = 0i64;
    }
    v11 = (float)((float)((float)i * v6) + (float)(v6 * 0.5))
        - UFG::ParkourHandle::GetHalfLength(this->m_pParkourHandle.m_pPointer);
    v10->m_fParkourTVal = v11;
    v10->m_fParkourSyncZOffset = this->m_fParkourSyncZOffset;
    v10->m_bFoundParkourSync = this->m_bFoundParkourSync;
    v12 = UFG::ParkourHandle::GetHalfLength(this->m_pParkourHandle.m_pPointer) + v11;
    HalfLength = UFG::ParkourHandle::GetHalfLength(this->m_pParkourHandle.m_pPointer);
    v10->m_fDistToLeft = v12;
    v10->m_fDistToRight = HalfLength - v11;
    size = aCoverPositions->size;
    v15 = size + 1;
    capacity = aCoverPositions->capacity;
    if ( (int)size + 1 > capacity )
    {
      if ( capacity )
        v17 = 2 * capacity;
      else
        v17 = 1;
      for ( ; v17 < v15; v17 *= 2 )
        ;
      if ( v17 <= 2 )
        v17 = 2;
      if ( v17 - v15 > 0x10000 )
        v17 = size + 65537;
      if ( v17 != (_DWORD)size )
      {
        v18 = 8i64 * v17;
        if ( !is_mul_ok(v17, 8ui64) )
          v18 = -1i64;
        v19 = UFG::qMalloc(v18, "qArray.Add", 0i64);
        v20 = (UFG::CoverPosition **)v19;
        if ( aCoverPositions->p )
        {
          for ( j = 0i64; (unsigned int)j < aCoverPositions->size; j = (unsigned int)(j + 1) )
            v19[j] = (UFG::allocator::free_link)aCoverPositions->p[j];
          operator delete[](aCoverPositions->p);
        }
        aCoverPositions->p = v20;
        aCoverPositions->capacity = v17;
      }
    }
    aCoverPositions->size = v15;
    aCoverPositions->p[size] = v10;
  }
  return 1;
}

// File Line: 230
// RVA: 0x34E9E0
void __fastcall UFG::CoverObjectParkour::Clear(UFG::CoverObjectParkour *this)
{
  UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle> *p_m_pParkourHandle; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *mNext; // rax

  this->vfptr->RemoveUser(this);
  p_m_pParkourHandle = &this->m_pParkourHandle;
  this->m_fPriority = 0.0;
  this->m_pCoverObjectGroup = 0i64;
  if ( this->m_pParkourHandle.m_pPointer )
  {
    mPrev = p_m_pParkourHandle->mPrev;
    mNext = this->m_pParkourHandle.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pParkourHandle->mPrev = p_m_pParkourHandle;
    this->m_pParkourHandle.mNext = &this->m_pParkourHandle;
  }
  this->m_pParkourHandle.m_pPointer = 0i64;
  this->m_bFoundParkourSync = 0;
  this->m_pCoverUser = 0i64;
}

// File Line: 241
// RVA: 0x365090
bool __fastcall UFG::CoverObjectParkour::InRange2(
        UFG::CoverObjectParkour *this,
        UFG::qVector3 *vPosition,
        float fRange2)
{
  float v5; // [rsp+20h] [rbp-28h] BYREF
  float v6; // [rsp+24h] [rbp-24h]
  float v7; // [rsp+28h] [rbp-20h]

  this->vfptr->GetPosition(this, (UFG::qVector3 *)&v5);
  return fRange2 > (float)((float)((float)((float)(v6 - vPosition->y) * (float)(v6 - vPosition->y))
                                 + (float)((float)(v5 - vPosition->x) * (float)(v5 - vPosition->x)))
                         + (float)((float)(v7 - vPosition->z) * (float)(v7 - vPosition->z)));
}

// File Line: 252
// RVA: 0x361F60
UFG::qVector3 *__fastcall UFG::CoverObjectParkour::GetPosition(UFG::CoverObjectParkour *this, UFG::qVector3 *result)
{
  UFG::ParkourHandle::GetPosition(this->m_pParkourHandle.m_pPointer, result);
  return result;
}

// File Line: 259
// RVA: 0x35F670
UFG::qVector3 *__fastcall UFG::CoverObjectParkour::GetFiringPosition(
        UFG::CoverObjectParkour *this,
        UFG::qVector3 *result)
{
  UFG::CoverObjectParkour::GetParkourFiringPosition(this, result, this->m_pParkourHandle.m_pPointer, 0.0);
  return result;
}

// File Line: 266
// RVA: 0x361B00
UFG::qVector3 *__fastcall UFG::CoverObjectParkour::GetParkourFiringPosition(
        UFG::CoverObjectParkour *this,
        UFG::qVector3 *result,
        UFG::ParkourHandle *pParkourHandle,
        float fTValue)
{
  float v6; // xmm8_4
  float v7; // xmm6_4
  float v8; // xmm7_4
  UFG::qVector3 *Axis; // rax
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm2_4
  UFG::qVector3 *v13; // rax
  float v14; // xmm3_4
  UFG::qVector3 resulta; // [rsp+20h] [rbp-68h] BYREF
  UFG::qVector3 v16; // [rsp+30h] [rbp-58h] BYREF

  UFG::ParkourHandle::GetPosition(pParkourHandle, &resulta);
  v6 = UFG::qVector3::msAxisZ.x * 0.2;
  v7 = UFG::qVector3::msAxisZ.y * 0.2;
  v8 = UFG::qVector3::msAxisZ.z * 0.2;
  Axis = UFG::ParkourHandle::GetAxis(pParkourHandle, &v16);
  v10 = fTValue * Axis->y;
  v11 = resulta.z + (float)(fTValue * Axis->z);
  v12 = (float)(resulta.x + (float)(fTValue * Axis->x)) + v6;
  v13 = result;
  v14 = (float)(resulta.y + v10) + v7;
  result->z = v11 + v8;
  result->x = v12;
  result->y = v14;
  return v13;
}

// File Line: 274
// RVA: 0x35B180
UFG::qVector3 *__fastcall UFG::CoverObjectParkour::GetClosestParkourSync(
        UFG::CoverObjectParkour *this,
        UFG::qVector3 *result,
        UFG::qVector3 *vPosition)
{
  float v6; // xmm6_4
  float v7; // xmm7_4
  float v8; // xmm8_4
  UFG::qVector3 *ParkourSync; // rax
  float v10; // xmm10_4
  float v11; // xmm9_4
  float v12; // xmm7_4
  float HalfLength; // xmm6_4
  float y; // xmm1_4
  float z; // xmm0_4
  float v16; // xmm5_4
  UFG::qVector3 end; // [rsp+18h] [rbp-39h] BYREF
  UFG::qVector3 p0; // [rsp+28h] [rbp-29h] BYREF
  UFG::qVector3 p1; // [rsp+34h] [rbp-1Dh] BYREF
  UFG::qVector3 resulta; // [rsp+40h] [rbp-11h] BYREF

  UFG::ParkourHandle::GetEndpoints(this->m_pParkourHandle.m_pPointer, (UFG::qVector3 *)&p0.z, (UFG::qVector3 *)&p1.z);
  v6 = (float)(p1.x + p0.x) * 0.5;
  v7 = (float)(p0.y + p1.y) * 0.5;
  v8 = (float)(p0.z + p1.z) * 0.5;
  ParkourSync = UFG::CoverObjectParkour::GetParkourSync(this, &resulta);
  v10 = ParkourSync->y - v7;
  v11 = ParkourSync->x - v6;
  v12 = ParkourSync->z - v8;
  HalfLength = UFG::ParkourHandle::GetHalfLength(this->m_pParkourHandle.m_pPointer);
  UFG::ParkourHandle::GetAxis(this->m_pParkourHandle.m_pPointer, &end);
  if ( HalfLength >= 0.5 )
  {
    v16 = end.z * 0.5;
    end.z = (float)(p1.z + v12) - (float)(end.z * 0.5);
    p0.x = (float)(p0.x + v11) + (float)(end.x * 0.5);
    p0.y = (float)(p0.y + v10) + (float)(end.y * 0.5);
    p0.z = (float)(p0.z + v12) + v16;
    UFG::qNearestSegPoint(&resulta, &p0, &end, vPosition);
    y = resulta.y;
    result->x = resulta.x;
    z = resulta.z;
  }
  else
  {
    y = (float)(p0.y + v10) + (float)(end.y * HalfLength);
    z = (float)(p0.z + v12) + (float)(end.z * HalfLength);
    result->x = (float)(p0.x + v11) + (float)(end.x * HalfLength);
  }
  result->z = z;
  result->y = y;
  return result;
}

// File Line: 305
// RVA: 0x35B390
UFG::qVector3 *__fastcall UFG::CoverObjectParkour::GetClosestParkourSyncInDirection(
        UFG::CoverObjectParkour *this,
        UFG::qVector3 *result,
        UFG::qVector3 *vPosition,
        UFG::qVector3 *vDirection,
        float fDirectionLength)
{
  float v9; // xmm6_4
  float v10; // xmm7_4
  UFG::qVector3 *ParkourSync; // rax
  float v12; // xmm8_4
  float v13; // xmm6_4
  float y; // xmm9_4
  float x; // xmm5_4
  float v16; // xmm7_4
  float v17; // xmm11_4
  float v18; // xmm10_4
  float v19; // xmm13_4
  float v20; // xmm4_4
  float v21; // xmm8_4
  float v22; // xmm3_4
  float v23; // xmm2_4
  float v24; // xmm4_4
  float v25; // xmm1_4
  float v26; // xmm4_4
  float z; // eax
  UFG::qVector3 v29; // [rsp+20h] [rbp-E8h] BYREF
  UFG::qVector3 resulta; // [rsp+30h] [rbp-D8h] BYREF
  char v31[16]; // [rsp+40h] [rbp-C8h] BYREF
  UFG::qVector3 p0; // [rsp+50h] [rbp-B8h] BYREF
  UFG::qVector3 p1; // [rsp+5Ch] [rbp-ACh] BYREF

  UFG::ParkourHandle::GetEndpoints(this->m_pParkourHandle.m_pPointer, &p0, &p1);
  v9 = (float)(p0.x + p1.x) * 0.5;
  v10 = (float)(p0.y + p1.y) * 0.5;
  ParkourSync = UFG::CoverObjectParkour::GetParkourSync(this, &resulta);
  v12 = ParkourSync->x - v9;
  v13 = ParkourSync->y - v10;
  UFG::ParkourHandle::GetAxis(this->m_pParkourHandle.m_pPointer, &v29);
  this->vfptr->GetWallNormal(this, (UFG::qVector3 *)v31);
  y = vPosition->y;
  x = UFG::qVector2::msZero.x;
  v16 = UFG::qVector2::msZero.y;
  v17 = vPosition->x + (float)(fDirectionLength * vDirection->x);
  v18 = (float)(p0.x + v12) + (float)(v29.x * 0.5);
  v19 = (float)(p1.x + v12) - (float)(v29.x * 0.5);
  v20 = y + (float)(fDirectionLength * vDirection->y);
  v21 = (float)(p0.y + v13) + (float)(v29.y * 0.5);
  v22 = (float)((float)(v18 - v17) * (float)((float)((float)(p1.y + v13) - (float)(v29.y * 0.5)) - v20))
      - (float)((float)(v21 - v20) * (float)(v19 - v17));
  v23 = (float)((float)(v18 - vPosition->x) * (float)((float)((float)(p1.y + v13) - (float)(v29.y * 0.5)) - y))
      - (float)((float)(v21 - y) * (float)(v19 - vPosition->x));
  if ( (float)(v23 * v22) < 0.0 )
  {
    v24 = (float)((float)(v20 - v21) * (float)(vPosition->x - v18)) - (float)((float)(y - v21) * (float)(v17 - v18));
    v25 = (float)(v24 + v23) - v22;
    if ( (float)(v25 * v24) < 0.0 )
    {
      v26 = v24 / (float)(v24 - v25);
      x = (float)((float)(v19 - v18) * v26) + v18;
      v16 = (float)((float)((float)((float)(p1.y + v13) - (float)(v29.y * 0.5)) - v21) * v26) + v21;
    }
  }
  z = vPosition->z;
  result->y = v16;
  result->x = x;
  result->z = z;
  return result;
}

// File Line: 338
// RVA: 0x3628F0
UFG::qVector3 *__fastcall UFG::CoverObjectParkour::GetSweetSpotDir(
        UFG::CoverObjectParkour *this,
        UFG::qVector3 *result)
{
  UFG::qVector3 *v3; // rax
  float z; // xmm1_4
  int v5; // xmm0_4
  UFG::qVector3 *v6; // rax
  char v7[24]; // [rsp+20h] [rbp-18h] BYREF

  v3 = this->vfptr->GetWallNormal(this, v7);
  z = v3->z;
  LODWORD(result->x) = LODWORD(v3->x) ^ _xmm[0];
  v5 = LODWORD(v3->y) ^ _xmm[0];
  v6 = result;
  LODWORD(result->z) = LODWORD(z) ^ _xmm[0];
  LODWORD(result->y) = v5;
  return v6;
}

// File Line: 345
// RVA: 0x3636D0
UFG::qVector3 *__fastcall UFG::CoverObjectParkour::GetWallNormal(UFG::CoverObjectParkour *this, UFG::qVector3 *result)
{
  UFG::ParkourHandle::GetNormal(this->m_pParkourHandle.m_pPointer, result);
  return result;
}

// File Line: 375
// RVA: 0x357BD0
bool __fastcall UFG::CoverObjectParkour::FindParkourSyncPos(UFG::CoverObjectParkour *this)
{
  float v2; // xmm7_4
  UFG::qVector3 *v3; // rax
  float v4; // xmm5_4
  float v5; // xmm6_4
  float v6; // xmm4_4
  float t; // xmm7_4
  unsigned __int64 v8; // rbx
  int v9; // edx
  UFG::CoverObjectParkour_RayCastCache *v10; // rcx
  char hit; // dl
  float y; // xmm0_4
  __int64 v13; // rcx
  char v14; // al
  __int64 v15; // rax
  float v16; // xmm6_4
  float v17; // xmm0_4
  bool result; // al
  UFG::qVector3 data; // [rsp+20h] [rbp-D8h] BYREF
  UFG::qVector3 rayEnd; // [rsp+30h] [rbp-C8h] BYREF
  int v21[4]; // [rsp+40h] [rbp-B8h] BYREF
  char v22[16]; // [rsp+50h] [rbp-A8h] BYREF
  UFG::RayCastData v23; // [rsp+60h] [rbp-98h] BYREF

  this->vfptr->GetPosition(this, (UFG::qVector3 *)v21);
  v2 = (float)(UFG::CoverObjectBase::ms_fLowFrontOffset + UFG::CoverObjectBase::ms_fHighFrontOffset) * 0.5;
  v3 = this->vfptr->GetWallNormal(this, v22);
  v4 = *(float *)&v21[1] + (float)(v2 * v3->y);
  v5 = *(float *)v21 + (float)(v2 * v3->x);
  v6 = *(float *)&v21[2] + (float)(v2 * v3->z);
  t = FLOAT_N1_0;
  data.x = v5;
  data.y = v4;
  data.z = v6;
  rayEnd.x = v5 - (float)(UFG::qVector3::msAxisZ.x * 3.0999999);
  rayEnd.y = v4 - (float)(UFG::qVector3::msAxisZ.y * 3.0999999);
  rayEnd.z = v6 - (float)(UFG::qVector3::msAxisZ.z * 3.0999999);
  v8 = UFG::qDataHash64((char *)&data, 0xCui64, 0xFFFFFFFFFFFFFFFFui64);
  v9 = 0;
  v10 = UFG::coverObjectParkour_RayCastCache;
  do
  {
    if ( v8 == v10->pos_hash )
    {
      v15 = v9;
      t = UFG::coverObjectParkour_RayCastCache[v15].t;
      hit = UFG::coverObjectParkour_RayCastCache[v15].hit;
      goto LABEL_8;
    }
    ++v10;
    ++v9;
  }
  while ( (__int64)v10 < (__int64)&UFG::coverObjectParkour_RayCastCacheIndex );
  v23.mInput.m_to.m_quad.m128_i8[8] = 0;
  v23.mInput.m_to.m_quad.m128_i32[3] = 0;
  *(_QWORD *)&v23.mInput.m_enableShapeCollectionFilter.m_bool = 0i64;
  v23.mOutput.m_shapeKeys[6] = 0;
  *((_QWORD *)&v23.mOutput.m_shapeKeyIndex + 1) = 0i64;
  v23.mOutput.m_normal.m_quad.m128_u64[1] = (unsigned int)FLOAT_1_0 | 0xFFFFFFFF00000000ui64;
  *((_QWORD *)&v23.mOutput.m_rootCollidable + 1) = "FindParkourSyncPos";
  v23.mOutput.m_pad[0] = -1;
  LODWORD(v23.mDebugName) = -1;
  UFG::RayCastData::Init(&v23, &data, &rayEnd, 0xDu);
  hit = UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, &v23);
  y = v23.normal.y;
  if ( hit )
    t = v23.normal.y;
  v13 = UFG::coverObjectParkour_RayCastCacheIndex;
  v14 = UFG::coverObjectParkour_RayCastCacheIndex + 1;
  UFG::coverObjectParkour_RayCastCache[v13].pos_hash = v8;
  UFG::coverObjectParkour_RayCastCache[v13].hit = hit;
  UFG::coverObjectParkour_RayCastCache[v13].t = y;
  UFG::coverObjectParkour_RayCastCacheIndex = v14 & 0x1F;
LABEL_8:
  if ( hit
    && ((v16 = data.z - (float)((float)((float)(rayEnd.z - data.z) * t) + data.z),
         !UFG::ParkourHandle::IsAttachedToVehicle(this->m_pParkourHandle.m_pPointer))
      ? (v17 = FLOAT_0_89999998)
      : (v17 = FLOAT_0_69999999),
        v16 > v17) )
  {
    this->m_bFoundParkourSync = 1;
    result = 1;
    LODWORD(this->m_fParkourSyncZOffset) = LODWORD(v16) ^ _xmm[0];
  }
  else
  {
    this->m_bFoundParkourSync = 0;
    return 0;
  }
  return result;
}

// File Line: 443
// RVA: 0x362970
UFG::qVector3 *__fastcall UFG::CoverObjectParkour::GetSyncPos(UFG::CoverObjectParkour *this, UFG::qVector3 *result)
{
  UFG::CoverObjectParkour::GetParkourSync(this, result);
  return result;
}

// File Line: 451
// RVA: 0x3600F0
UFG::ParkourHandle *__fastcall UFG::CoverObjectParkour::GetInUse(UFG::CoverObjectParkour *this)
{
  UFG::ParkourHandle *result; // rax

  result = this->m_pParkourHandle.m_pPointer;
  if ( result )
    return (UFG::ParkourHandle *)((*((_BYTE *)result + 152) & 0x1C) != 0);
  return result;
}

// File Line: 461
// RVA: 0x386860
void __fastcall UFG::CoverObjectParkour::SetInUse(UFG::CoverObjectParkour *this, bool bInUse)
{
  UFG::ParkourHandle *m_pPointer; // r8

  m_pPointer = this->m_pParkourHandle.m_pPointer;
  if ( m_pPointer )
  {
    if ( bInUse )
      *((_DWORD *)m_pPointer + 38) ^= ((unsigned __int8)*((_DWORD *)m_pPointer + 38) ^ (unsigned __int8)((*((_DWORD *)m_pPointer + 38) & 0xFC) + 4)) & 0x1C;
    else
      *((_DWORD *)m_pPointer + 38) ^= ((unsigned __int8)*((_DWORD *)m_pPointer + 38) ^ (unsigned __int8)(4 * (*((_DWORD *)m_pPointer + 38) >> 2) - 4)) & 0x1C;
  }
}

// File Line: 476
// RVA: 0x341630
void __fastcall UFG::CoverObjectParkour::AddUser(UFG::CoverObjectParkour *this, UFG::SimObject *pUser)
{
  _BOOL8 v4; // rdx
  UFG::ParkourHandle *m_pPointer; // rsi
  UFG::CoverObjectBase::CoverUser *v6; // rax
  UFG::CoverObjectBase::CoverUser *m_pCoverUser; // rcx
  UFG::qNode<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser> *mPrev; // rax

  this->vfptr->GetInUse(this);
  LOBYTE(v4) = 1;
  this->vfptr->SetInUse(this, v4);
  m_pPointer = this->m_pParkourHandle.m_pPointer;
  v6 = (UFG::CoverObjectBase::CoverUser *)UFG::qMalloc(0x20ui64, "CoverUser", 0i64);
  if ( v6 )
  {
    v6->mPrev = v6;
    v6->mNext = v6;
  }
  this->m_pCoverUser = v6;
  v6->pCoverObject = m_pPointer;
  this->m_pCoverUser->pUser = pUser;
  m_pCoverUser = this->m_pCoverUser;
  mPrev = UFG::CoverObjectBase::ms_listUsers.mNode.mPrev;
  UFG::CoverObjectBase::ms_listUsers.mNode.mPrev->mNext = m_pCoverUser;
  m_pCoverUser->mPrev = mPrev;
  m_pCoverUser->mNext = (UFG::qNode<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser> *)&UFG::CoverObjectBase::ms_listUsers;
  UFG::CoverObjectBase::ms_listUsers.mNode.mPrev = m_pCoverUser;
}

// File Line: 496
// RVA: 0x381610
void __fastcall UFG::CoverObjectParkour::RemoveUser(UFG::CoverObjectParkour *this)
{
  UFG::CoverObjectBase::CoverUser *m_pCoverUser; // rdx
  UFG::qNode<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser> *mPrev; // rcx
  UFG::qNode<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser> *mNext; // rax
  UFG::CoverObjectBase::CoverUser *v5; // rcx
  UFG::qNode<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser> *v6; // rdx
  UFG::qNode<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser> *v7; // rax

  if ( (*((unsigned __int8 (__fastcall **)(UFG::CoverObjectParkour *))&this->vfptr->__vecDelDtor + 2))(this) )
    this->vfptr->GetInUse(this);
  this->vfptr->SetInUse(this, 0);
  m_pCoverUser = this->m_pCoverUser;
  mPrev = m_pCoverUser->mPrev;
  mNext = m_pCoverUser->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  m_pCoverUser->mPrev = m_pCoverUser;
  m_pCoverUser->mNext = m_pCoverUser;
  v5 = this->m_pCoverUser;
  if ( v5 )
  {
    v6 = v5->mPrev;
    v7 = v5->mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v5->mPrev = v5;
    v5->mNext = v5;
    operator delete[](v5);
  }
  this->m_pCoverUser = 0i64;
}

// File Line: 513
// RVA: 0x34CA20
char __fastcall UFG::CoverObjectParkour::CanUse(UFG::CoverObjectParkour *this, UFG::SimObject *pUser)
{
  UFG::qNode<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser> *mNext; // rax

  if ( (*((unsigned __int8 (__fastcall **)(UFG::CoverObjectParkour *))&this->vfptr->__vecDelDtor + 2))(this)
    && UFG::ParkourHandle::GetHalfLength(this->m_pParkourHandle.m_pPointer) >= 0.55000001 )
  {
    if ( !this->vfptr->GetInUse(this) )
      return 1;
    mNext = UFG::CoverObjectBase::ms_listUsers.mNode.mNext;
    if ( (UFG::qList<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser,1,0> *)UFG::CoverObjectBase::ms_listUsers.mNode.mNext != &UFG::CoverObjectBase::ms_listUsers )
    {
      while ( mNext[1].mPrev != (UFG::qNode<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser> *)this->m_pParkourHandle.m_pPointer
           || (UFG::SimObject *)mNext[1].mNext != pUser )
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

// File Line: 545
// RVA: 0x369A90
bool __fastcall UFG::CoverObjectParkour::IsAnyLineOrCornerShared(
        UFG::CoverObjectParkour *this,
        UFG::CoverObjectBase *pOther)
{
  UFG::ParkourHandle *m_pPointer; // rax
  bool result; // al

  result = 0;
  if ( pOther->vfptr->IsParkour(pOther) )
  {
    m_pPointer = this->m_pParkourHandle.m_pPointer;
    if ( m_pPointer )
    {
      if ( (UFG::ParkourHandle *)pOther[1].m_pCoverObjectGroup == m_pPointer )
        return 1;
    }
  }
  return result;
}

// File Line: 562
// RVA: 0x361BF0
UFG::qVector3 *__fastcall UFG::CoverObjectParkour::GetParkourSync(UFG::CoverObjectParkour *this, UFG::qVector3 *result)
{
  float v4; // xmm0_4
  float v5; // xmm11_4
  float m_fParkourSyncZOffset; // xmm0_4
  float v7; // xmm6_4
  float v8; // xmm7_4
  float v9; // xmm11_4
  float v10; // xmm6_4
  float v11; // xmm7_4
  float v12; // xmm8_4
  float v13; // xmm9_4
  float v14; // xmm10_4
  UFG::qVector3 *Position; // rax
  float v16; // xmm6_4
  float v17; // xmm7_4
  float v18; // xmm11_4
  UFG::qVector3 *v19; // rax
  UFG::qVector3 out; // [rsp+20h] [rbp-88h] BYREF
  UFG::qVector3 resulta; // [rsp+30h] [rbp-78h] BYREF

  UFG::ParkourHandle::GetNormal(this->m_pParkourHandle.m_pPointer, &out);
  v4 = this->vfptr->GetHeight(this);
  if ( v4 <= 0.5 || v4 >= 1.6 )
    v5 = UFG::CoverObjectBase::ms_fHighFrontOffset;
  else
    v5 = UFG::CoverObjectBase::ms_fLowFrontOffset;
  m_fParkourSyncZOffset = this->m_fParkourSyncZOffset;
  v7 = v5;
  v8 = v5;
  v9 = v5 * out.z;
  v10 = v7 * out.x;
  v11 = v8 * out.y;
  v12 = UFG::qVector3::msAxisZ.x * m_fParkourSyncZOffset;
  v13 = UFG::qVector3::msAxisZ.y * m_fParkourSyncZOffset;
  v14 = UFG::qVector3::msAxisZ.z * m_fParkourSyncZOffset;
  Position = UFG::ParkourHandle::GetPosition(this->m_pParkourHandle.m_pPointer, &resulta);
  v16 = v10 + Position->x;
  v17 = v11 + Position->y;
  v18 = v9 + Position->z;
  v19 = result;
  result->x = v16 + v12;
  result->y = v17 + v13;
  result->z = v18 + v14;
  return v19;
}

