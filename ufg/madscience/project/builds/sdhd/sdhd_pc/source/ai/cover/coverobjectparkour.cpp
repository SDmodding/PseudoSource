// File Line: 47
// RVA: 0x32D5A0
void __fastcall UFG::CoverObjectParkour::CoverObjectParkour(UFG::CoverObjectParkour *this, UFG::ParkourHandle *pParkourHandle)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v2; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v3; // rax

  this->vfptr = (UFG::CoverObjectBaseVtbl *)&UFG::CoverObjectBase::`vftable';
  this->m_iRefCount = 0;
  this->m_pCoverObjectGroup = 0i64;
  this->m_fPriority = 0.0;
  this->vfptr = (UFG::CoverObjectBaseVtbl *)&UFG::CoverObjectParkour::`vftable';
  v2 = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&this->m_pParkourHandle.mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->m_pParkourHandle.m_pPointer = pParkourHandle;
  if ( pParkourHandle )
  {
    v3 = pParkourHandle->m_SafePointerList.mNode.mPrev;
    v3->mNext = v2;
    v2->mPrev = v3;
    this->m_pParkourHandle.mNext = &pParkourHandle->m_SafePointerList.mNode;
    pParkourHandle->m_SafePointerList.mNode.mPrev = v2;
  }
  this->m_bFoundParkourSync = 0;
  this->m_pCoverUser = 0i64;
}

// File Line: 52
// RVA: 0x33BCC0
UFG::CoverObjectParkour *__fastcall UFG::CoverObjectParkour::operator=(UFG::CoverObjectParkour *this, UFG::CoverObjectParkour *other)
{
  UFG::CoverObjectParkour *v2; // rdi
  UFG::CoverObjectParkour *v3; // rbx
  UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle> *v4; // r8
  UFG::ParkourHandle *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v6; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v9; // rcx

  v2 = other;
  v3 = this;
  (*((void (**)(void))&this->vfptr->__vecDelDtor + 1))();
  v4 = &v3->m_pParkourHandle;
  v3->m_fPriority = v2->m_fPriority;
  v5 = v2->m_pParkourHandle.m_pPointer;
  if ( v3->m_pParkourHandle.m_pPointer )
  {
    v6 = v4->mPrev;
    v7 = v3->m_pParkourHandle.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v4->mPrev;
    v3->m_pParkourHandle.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v3->m_pParkourHandle.mPrev;
  }
  v3->m_pParkourHandle.m_pPointer = v5;
  if ( v5 )
  {
    v8 = v5->m_SafePointerList.mNode.mPrev;
    v9 = &v5->m_SafePointerList.mNode;
    v8->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v4->mPrev;
    v4->mPrev = v8;
    v3->m_pParkourHandle.mNext = v9;
    v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  }
  v3->m_bFoundParkourSync = v2->m_bFoundParkourSync;
  v3->m_fParkourSyncZOffset = v2->m_fParkourSyncZOffset;
  return v3;
}

// File Line: 64
// RVA: 0x36BFD0
bool __fastcall UFG::CoverObjectParkour::IsValid(UFG::CoverObjectParkour *this)
{
  UFG::CoverObjectParkour *v1; // rbx
  UFG::ParkourHandle *v2; // rcx
  UFG::SimObject *v3; // rbx
  UFG::TransformNodeComponent *v4; // rbx
  bool result; // al

  v1 = this;
  v2 = this->m_pParkourHandle.m_pPointer;
  result = 0;
  if ( v2 )
  {
    if ( UFG::ParkourHandle::IsEnabled(v2) )
    {
      v3 = v1->m_pParkourHandle.m_pPointer->mSimObject.m_pPointer;
      if ( !v3
        || (v4 = v3->m_pTransformNodeComponent) == 0i64
        || (UFG::TransformNodeComponent::UpdateWorldTransform(v4),
            (float)((float)(v4->mWorldVelocity.x * v4->mWorldVelocity.x)
                  + (float)(v4->mWorldVelocity.y * v4->mWorldVelocity.y)) < (float)(UFG::CoverObjectBase::ms_fMaxCoverVelocity
                                                                                  * UFG::CoverObjectBase::ms_fMaxCoverVelocity)) )
      {
        result = 1;
      }
    }
  }
  return result;
}

// File Line: 88
// RVA: 0x36A3F0
char __fastcall UFG::CoverObjectParkour::IsConnectedTo(UFG::CoverObjectParkour *this, UFG::CoverObjectBase *other)
{
  UFG::CoverObjectParkour *v2; // rdi
  UFG::CoverObjectParkour *v3; // rbx
  char result; // al

  v2 = this;
  v3 = (UFG::CoverObjectParkour *)other;
  if ( other->vfptr->IsParkour(other) )
    result = UFG::CoverObjectBase::IsConnected(v2, v3);
  else
    result = UFG::CoverObjectBase::IsConnected(v2, (UFG::CoverObjectCorner *)v3);
  return result;
}

// File Line: 107
// RVA: 0x36B850
bool __fastcall UFG::CoverObjectParkour::IsLeftOf(UFG::CoverObjectParkour *this, UFG::CoverObjectBase *other)
{
  UFG::CoverObjectParkour *v2; // rdi
  UFG::CoverObjectParkour *v3; // rbx
  bool result; // al

  v2 = this;
  v3 = (UFG::CoverObjectParkour *)other;
  if ( other->vfptr->IsParkour(other) )
    result = UFG::CoverObjectBase::IsLeft(v2, v3);
  else
    result = UFG::CoverObjectBase::IsLeft(v2, (UFG::CoverObjectCorner *)v3);
  return result;
}

// File Line: 127
// RVA: 0x35C270
UFG::CoverPosition *__fastcall UFG::CoverObjectParkour::GetCoverPosition(UFG::CoverObjectParkour *this, UFG::qVector3 *vCharPos, UFG::CoverPosition *pCurrentPosition, float fRange)
{
  UFG::CoverPosition *v4; // rbx
  UFG::qVector3 *v5; // rsi
  UFG::CoverObjectParkour *v6; // rdi
  float v7; // xmm8_4
  float v8; // xmm9_4
  float v9; // xmm7_4
  float v10; // xmm6_4
  __m128 v11; // xmm2
  __m128 v12; // xmm1
  float v13; // xmm8_4
  float v14; // xmm7_4
  UFG::allocator::free_link *v15; // rax
  UFG::CoverPosition *v16; // rax
  float v17; // xmm0_4
  float v18; // xmm0_4
  UFG::qVector3 result; // [rsp+28h] [rbp-70h]
  UFG::qVector3 p0; // [rsp+38h] [rbp-60h]
  UFG::qVector3 p1; // [rsp+44h] [rbp-54h]

  v4 = pCurrentPosition;
  v5 = vCharPos;
  v6 = this;
  if ( !(_S57 & 1) )
  {
    _S57 |= 1u;
    kfRangeSquared = FLOAT_0_25;
  }
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(
                      (float)(UFG::ParkourHandle::GetPosition(this->m_pParkourHandle.m_pPointer, &result)->z
                            + this->m_fParkourSyncZOffset)
                    - vCharPos->z) & _xmm) < kfMaxHeightDiff_2 )
  {
    UFG::ParkourHandle::GetEndpoints(v6->m_pParkourHandle.m_pPointer, &p0, &p1);
    v7 = v5->z - p0.z;
    v8 = v5->y - p0.y;
    v9 = v5->x - p0.x;
    if ( UFG::ParkourHandle::GetNormal(v6->m_pParkourHandle.m_pPointer, &result) )
    {
      v10 = (float)((float)(result.x * v9) + (float)(result.y * v8)) + (float)(result.z * v7);
      if ( v10 > 0.0 && v10 < 1.0 )
      {
        v11 = (__m128)LODWORD(p1.x);
        v11.m128_f32[0] = p1.x - p0.x;
        v12 = v11;
        v12.m128_f32[0] = (float)(v11.m128_f32[0] * v11.m128_f32[0])
                        + (float)((float)(p1.y - p0.y) * (float)(p1.y - p0.y));
        LODWORD(v13) = (unsigned __int128)_mm_sqrt_ps(v12);
        v14 = (float)(v9 * (float)((float)(1.0 / v13) * (float)(p1.x - p0.x)))
            + (float)((float)((float)(1.0 / v13) * (float)(p1.y - p0.y)) * v8);
        if ( v14 > 0.0 && v14 < v13 )
        {
          if ( v4 )
          {
            UFG::CoverPosition::SetParkourHandle(v4, v6->m_pParkourHandle.m_pPointer);
          }
          else
          {
            v15 = UFG::qMalloc(0x170ui64, "CoverPosition", 0i64);
            if ( v15 )
            {
              UFG::CoverPosition::CoverPosition((UFG::CoverPosition *)v15, v6->m_pParkourHandle.m_pPointer);
              v4 = v16;
            }
            else
            {
              v4 = 0i64;
            }
          }
          v17 = UFG::ParkourHandle::GetHalfLength(v6->m_pParkourHandle.m_pPointer);
          v4->m_bFoundParkourSync = v6->m_bFoundParkourSync;
          v4->m_fParkourSyncZOffset = v6->m_fParkourSyncZOffset;
          v4->m_fParkourTVal = v14 - v17;
          v4->m_fDistanceInFront = v10;
          if ( v4->m_fDistToLeft < 0.001 && v4->m_fDistToRight < 0.001 )
          {
            v18 = UFG::CoverObjectBase::GetSideOffset((UFG::CoverObjectBase *)&v4->vfptr);
            v4->m_fDistToLeft = v14 - v18;
            v4->m_fDistToRight = (float)(v13 - v14) - v18;
          }
        }
      }
    }
  }
  return v4;
}

// File Line: 193
// RVA: 0x35D3A0
char __fastcall UFG::CoverObjectParkour::GetCoverPositions(UFG::CoverObjectParkour *this, UFG::qArray<UFG::CoverPosition *,0> *aCoverPositions)
{
  UFG::qArray<UFG::CoverPosition *,0> *v2; // rdi
  UFG::CoverObjectParkour *v3; // r12
  float v4; // xmm8_4
  float v5; // xmm2_4
  float v6; // xmm8_4
  signed int i; // er15
  UFG::allocator::free_link *v8; // rax
  UFG::CoverPosition *v9; // rax
  UFG::CoverPosition *v10; // rbp
  float v11; // xmm7_4
  float v12; // xmm6_4
  float v13; // xmm0_4
  __int64 v14; // r13
  unsigned int v15; // esi
  unsigned int v16; // ebx
  unsigned int v17; // ebx
  unsigned __int64 v18; // rax
  UFG::allocator::free_link *v19; // rax
  UFG::CoverPosition **v20; // r14
  __int64 v21; // r9

  v2 = aCoverPositions;
  v3 = this;
  v4 = UFG::ParkourHandle::GetHalfLength(this->m_pParkourHandle.m_pPointer) * 2.0;
  if ( v4 <= 0.5 )
    return 0;
  v5 = *(float *)&FLOAT_1_0;
  if ( (float)(signed int)v4 >= 1.0 )
    v5 = (float)(signed int)v4;
  v6 = v4 / (float)(signed int)v5;
  for ( i = 0; i < (signed int)v5; ++i )
  {
    v8 = UFG::qMalloc(0x170ui64, "CoverPosition", 0i64);
    if ( v8 )
    {
      UFG::CoverPosition::CoverPosition((UFG::CoverPosition *)v8, v3->m_pParkourHandle.m_pPointer);
      v10 = v9;
    }
    else
    {
      v10 = 0i64;
    }
    v11 = (float)((float)((float)i * v6) + (float)(v6 * 0.5))
        - UFG::ParkourHandle::GetHalfLength(v3->m_pParkourHandle.m_pPointer);
    v10->m_fParkourTVal = v11;
    v10->m_fParkourSyncZOffset = v3->m_fParkourSyncZOffset;
    v10->m_bFoundParkourSync = v3->m_bFoundParkourSync;
    v12 = UFG::ParkourHandle::GetHalfLength(v3->m_pParkourHandle.m_pPointer) + v11;
    v13 = UFG::ParkourHandle::GetHalfLength(v3->m_pParkourHandle.m_pPointer);
    v10->m_fDistToLeft = v12;
    v10->m_fDistToRight = v13 - v11;
    v14 = v2->size;
    v15 = v14 + 1;
    v16 = v2->capacity;
    if ( (signed int)v14 + 1 > v16 )
    {
      if ( v16 )
        v17 = 2 * v16;
      else
        v17 = 1;
      for ( ; v17 < v15; v17 *= 2 )
        ;
      if ( v17 <= 2 )
        v17 = 2;
      if ( v17 - v15 > 0x10000 )
        v17 = v14 + 65537;
      if ( v17 != (_DWORD)v14 )
      {
        v18 = 8i64 * v17;
        if ( !is_mul_ok(v17, 8ui64) )
          v18 = -1i64;
        v19 = UFG::qMalloc(v18, "qArray.Add", 0i64);
        v20 = (UFG::CoverPosition **)v19;
        if ( v2->p )
        {
          v21 = 0i64;
          if ( v2->size )
          {
            do
            {
              v19[v21] = (UFG::allocator::free_link)v2->p[v21];
              v21 = (unsigned int)(v21 + 1);
            }
            while ( (unsigned int)v21 < v2->size );
          }
          operator delete[](v2->p);
        }
        v2->p = v20;
        v2->capacity = v17;
      }
    }
    v2->size = v15;
    v2->p[v14] = v10;
  }
  return 1;
}

// File Line: 230
// RVA: 0x34E9E0
void __fastcall UFG::CoverObjectParkour::Clear(UFG::CoverObjectParkour *this)
{
  UFG::CoverObjectParkour *v1; // rbx
  UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle> *v2; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v3; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v4; // rax

  v1 = this;
  ((void (*)(void))this->vfptr->RemoveUser)();
  v2 = &v1->m_pParkourHandle;
  v1->m_fPriority = 0.0;
  v1->m_pCoverObjectGroup = 0i64;
  if ( v1->m_pParkourHandle.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v1->m_pParkourHandle.mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v1->m_pParkourHandle.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v1->m_pParkourHandle.mPrev;
  }
  v1->m_pParkourHandle.m_pPointer = 0i64;
  v1->m_bFoundParkourSync = 0;
  v1->m_pCoverUser = 0i64;
}

// File Line: 241
// RVA: 0x365090
bool __fastcall UFG::CoverObjectParkour::InRange2(UFG::CoverObjectParkour *this, UFG::qVector3 *vPosition, float fRange2)
{
  UFG::qVector3 *v3; // rbx
  float v5; // [rsp+20h] [rbp-28h]
  float v6; // [rsp+24h] [rbp-24h]
  float v7; // [rsp+28h] [rbp-20h]

  v3 = vPosition;
  this->vfptr->GetPosition((UFG::CoverObjectBase *)this, (UFG::qVector3 *)&v5);
  return fRange2 > (float)((float)((float)((float)(v6 - v3->y) * (float)(v6 - v3->y))
                                 + (float)((float)(v5 - v3->x) * (float)(v5 - v3->x)))
                         + (float)((float)(v7 - v3->z) * (float)(v7 - v3->z)));
}

// File Line: 252
// RVA: 0x361F60
UFG::qVector3 *__fastcall UFG::CoverObjectParkour::GetPosition(UFG::CoverObjectParkour *this, UFG::qVector3 *result)
{
  UFG::qVector3 *v2; // rbx

  v2 = result;
  UFG::ParkourHandle::GetPosition(this->m_pParkourHandle.m_pPointer, result);
  return v2;
}

// File Line: 259
// RVA: 0x35F670
UFG::qVector3 *__fastcall UFG::CoverObjectParkour::GetFiringPosition(UFG::CoverObjectParkour *this, UFG::qVector3 *result)
{
  UFG::qVector3 *v2; // rbx

  v2 = result;
  UFG::CoverObjectParkour::GetParkourFiringPosition(this, result, this->m_pParkourHandle.m_pPointer, 0.0);
  return v2;
}

// File Line: 266
// RVA: 0x361B00
UFG::qVector3 *__fastcall UFG::CoverObjectParkour::GetParkourFiringPosition(UFG::CoverObjectParkour *this, UFG::qVector3 *result, UFG::ParkourHandle *pParkourHandle, float fTValue)
{
  UFG::qVector3 *v4; // rdi
  UFG::ParkourHandle *v5; // rbx
  float v6; // xmm8_4
  float v7; // xmm6_4
  float v8; // xmm7_4
  UFG::qVector3 *v9; // rax
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm2_4
  UFG::qVector3 *v13; // rax
  float v14; // xmm3_4
  UFG::qVector3 resulta; // [rsp+20h] [rbp-68h]
  UFG::qVector3 v16; // [rsp+30h] [rbp-58h]

  v4 = result;
  v5 = pParkourHandle;
  UFG::ParkourHandle::GetPosition(pParkourHandle, &resulta);
  v6 = UFG::qVector3::msAxisZ.x * 0.2;
  v7 = UFG::qVector3::msAxisZ.y * 0.2;
  v8 = UFG::qVector3::msAxisZ.z * 0.2;
  v9 = UFG::ParkourHandle::GetAxis(v5, &v16);
  v10 = fTValue * v9->y;
  v11 = resulta.z + (float)(fTValue * v9->z);
  v12 = (float)(resulta.x + (float)(fTValue * v9->x)) + v6;
  v13 = v4;
  v14 = (float)(resulta.y + v10) + v7;
  v4->z = v11 + v8;
  v4->x = v12;
  v4->y = v14;
  return v13;
}

// File Line: 274
// RVA: 0x35B180
UFG::qVector3 *__fastcall UFG::CoverObjectParkour::GetClosestParkourSync(UFG::CoverObjectParkour *this, UFG::qVector3 *result, UFG::qVector3 *vPosition)
{
  UFG::CoverObjectParkour *v3; // rbx
  UFG::qVector3 *v4; // rsi
  UFG::qVector3 *v5; // rdi
  float v6; // xmm6_4
  float v7; // xmm7_4
  float v8; // xmm8_4
  UFG::qVector3 *v9; // rax
  float v10; // xmm10_4
  float v11; // xmm9_4
  float v12; // xmm7_4
  float v13; // xmm6_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm5_4
  UFG::qVector3 end; // [rsp+18h] [rbp-39h]
  UFG::qVector3 p0; // [rsp+28h] [rbp-29h]
  UFG::qVector3 p1; // [rsp+34h] [rbp-1Dh]
  UFG::qVector3 resulta; // [rsp+40h] [rbp-11h]

  v3 = this;
  v4 = vPosition;
  v5 = result;
  UFG::ParkourHandle::GetEndpoints(
    this->m_pParkourHandle.m_pPointer,
    (UFG::qVector3 *)((char *)&p0 + 8),
    (UFG::qVector3 *)((char *)&p1 + 8));
  v6 = (float)(p1.x + p0.x) * 0.5;
  v7 = (float)(p0.y + p1.y) * 0.5;
  v8 = (float)(p0.z + p1.z) * 0.5;
  v9 = UFG::CoverObjectParkour::GetParkourSync(v3, &resulta);
  v10 = v9->y - v7;
  v11 = v9->x - v6;
  v12 = v9->z - v8;
  v13 = UFG::ParkourHandle::GetHalfLength(v3->m_pParkourHandle.m_pPointer);
  UFG::ParkourHandle::GetAxis(v3->m_pParkourHandle.m_pPointer, &end);
  if ( v13 >= 0.5 )
  {
    v16 = end.z * 0.5;
    end.z = (float)(p1.z + v12) - (float)(end.z * 0.5);
    p0.x = (float)(p0.x + v11) + (float)(end.x * 0.5);
    p0.y = (float)(p0.y + v10) + (float)(end.y * 0.5);
    p0.z = (float)(p0.z + v12) + v16;
    UFG::qNearestSegPoint(&resulta, &p0, &end, v4);
    v14 = resulta.y;
    v5->x = resulta.x;
    v15 = resulta.z;
  }
  else
  {
    v14 = (float)(p0.y + v10) + (float)(end.y * v13);
    v15 = (float)(p0.z + v12) + (float)(end.z * v13);
    v5->x = (float)(p0.x + v11) + (float)(end.x * v13);
  }
  v5->z = v15;
  v5->y = v14;
  return v5;
}

// File Line: 305
// RVA: 0x35B390
UFG::qVector3 *__fastcall UFG::CoverObjectParkour::GetClosestParkourSyncInDirection(UFG::CoverObjectParkour *this, UFG::qVector3 *result, UFG::qVector3 *vPosition, UFG::qVector3 *vDirection, float fDirectionLength)
{
  UFG::CoverObjectParkour *v5; // rbx
  UFG::qVector3 *v6; // rbp
  UFG::qVector3 *v7; // rsi
  UFG::qVector3 *v8; // rdi
  float v9; // xmm6_4
  float v10; // xmm7_4
  UFG::qVector3 *v11; // rax
  float v12; // xmm8_4
  float v13; // xmm6_4
  float v14; // xmm9_4
  float v15; // xmm5_4
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
  float v27; // eax
  UFG::qVector3 v29; // [rsp+20h] [rbp-E8h]
  UFG::qVector3 resulta; // [rsp+30h] [rbp-D8h]
  char v31; // [rsp+40h] [rbp-C8h]
  UFG::qVector3 p0; // [rsp+50h] [rbp-B8h]
  UFG::qVector3 p1; // [rsp+5Ch] [rbp-ACh]

  v5 = this;
  v6 = vPosition;
  v7 = result;
  v8 = vDirection;
  UFG::ParkourHandle::GetEndpoints(this->m_pParkourHandle.m_pPointer, &p0, &p1);
  v9 = (float)(p0.x + p1.x) * 0.5;
  v10 = (float)(p0.y + p1.y) * 0.5;
  v11 = UFG::CoverObjectParkour::GetParkourSync(v5, &resulta);
  v12 = v11->x - v9;
  v13 = v11->y - v10;
  UFG::ParkourHandle::GetAxis(v5->m_pParkourHandle.m_pPointer, &v29);
  v5->vfptr->GetWallNormal((UFG::CoverObjectBase *)&v5->vfptr, (UFG::qVector3 *)&v31);
  v14 = v6->y;
  v15 = UFG::qVector2::msZero.x;
  v16 = UFG::qVector2::msZero.y;
  v17 = v6->x + (float)(fDirectionLength * v8->x);
  v18 = (float)(p0.x + v12) + (float)(v29.x * 0.5);
  v19 = (float)(p1.x + v12) - (float)(v29.x * 0.5);
  v20 = v6->y + (float)(fDirectionLength * v8->y);
  v21 = (float)(p0.y + v13) + (float)(v29.y * 0.5);
  v22 = (float)((float)(v18 - v17) * (float)((float)((float)(p1.y + v13) - (float)(v29.y * 0.5)) - v20))
      - (float)((float)(v21 - v20) * (float)(v19 - v17));
  v23 = (float)((float)(v18 - v6->x) * (float)((float)((float)(p1.y + v13) - (float)(v29.y * 0.5)) - v14))
      - (float)((float)(v21 - v14) * (float)(v19 - v6->x));
  if ( (float)(v23 * v22) < 0.0 )
  {
    v24 = (float)((float)(v20 - v21) * (float)(v6->x - v18)) - (float)((float)(v14 - v21) * (float)(v17 - v18));
    v25 = (float)(v24 + v23) - v22;
    if ( (float)(v25 * v24) < 0.0 )
    {
      v26 = v24 / (float)(v24 - v25);
      v15 = (float)((float)(v19 - v18) * v26) + v18;
      v16 = (float)((float)((float)((float)(p1.y + v13) - (float)(v29.y * 0.5)) - v21) * v26) + v21;
    }
  }
  v27 = v6->z;
  v7->y = v16;
  v7->x = v15;
  v7->z = v27;
  return v7;
}

// File Line: 338
// RVA: 0x3628F0
UFG::qVector3 *__fastcall UFG::CoverObjectParkour::GetSweetSpotDir(UFG::CoverObjectParkour *this, UFG::qVector3 *result)
{
  UFG::qVector3 *v2; // rbx
  UFG::qVector3 *v3; // rax
  float v4; // xmm1_4
  int v5; // xmm0_4
  UFG::qVector3 *v6; // rax
  char v7; // [rsp+20h] [rbp-18h]

  v2 = result;
  v3 = this->vfptr->GetWallNormal((UFG::CoverObjectBase *)this, (UFG::qVector3 *)&v7);
  v4 = v3->z;
  LODWORD(v2->x) = LODWORD(v3->x) ^ _xmm[0];
  v5 = LODWORD(v3->y) ^ _xmm[0];
  v6 = v2;
  LODWORD(v2->z) = LODWORD(v4) ^ _xmm[0];
  LODWORD(v2->y) = v5;
  return v6;
}

// File Line: 345
// RVA: 0x3636D0
UFG::qVector3 *__fastcall UFG::CoverObjectParkour::GetWallNormal(UFG::CoverObjectParkour *this, UFG::qVector3 *result)
{
  UFG::qVector3 *v2; // rbx

  v2 = result;
  UFG::ParkourHandle::GetNormal(this->m_pParkourHandle.m_pPointer, result);
  return v2;
}

// File Line: 375
// RVA: 0x357BD0
char __fastcall UFG::CoverObjectParkour::FindParkourSyncPos(UFG::CoverObjectParkour *this)
{
  UFG::CoverObjectParkour *v1; // rdi
  float v2; // xmm7_4
  float *v3; // rax
  float v4; // xmm5_4
  float v5; // xmm6_4
  float v6; // xmm4_4
  float v7; // xmm7_4
  unsigned __int64 v8; // rbx
  int v9; // edx
  UFG::CoverObjectParkour_RayCastCache *v10; // rcx
  char v11; // dl
  float v12; // xmm0_4
  __int64 v13; // rcx
  char v14; // al
  __int64 v15; // rax
  float v16; // xmm6_4
  float v17; // xmm0_4
  char result; // al
  float data; // [rsp+20h] [rbp-D8h]
  float v20; // [rsp+24h] [rbp-D4h]
  float v21; // [rsp+28h] [rbp-D0h]
  UFG::qVector3 rayEnd; // [rsp+30h] [rbp-C8h]
  float v23; // [rsp+40h] [rbp-B8h]
  float v24; // [rsp+44h] [rbp-B4h]
  float v25; // [rsp+48h] [rbp-B0h]
  char v26; // [rsp+50h] [rbp-A8h]
  UFG::RayCastData v27; // [rsp+60h] [rbp-98h]

  v1 = this;
  this->vfptr->GetPosition((UFG::CoverObjectBase *)this, (UFG::qVector3 *)&v23);
  v2 = (float)(UFG::CoverObjectBase::ms_fLowFrontOffset + UFG::CoverObjectBase::ms_fHighFrontOffset) * 0.5;
  v3 = (float *)v1->vfptr->GetWallNormal((UFG::CoverObjectBase *)&v1->vfptr, (UFG::qVector3 *)&v26);
  v4 = v24 + (float)(v2 * v3[1]);
  v5 = v23 + (float)(v2 * *v3);
  v6 = v25 + (float)(v2 * v3[2]);
  v7 = FLOAT_N1_0;
  data = v5;
  v20 = v4;
  v21 = v6;
  rayEnd.x = v5 - (float)(UFG::qVector3::msAxisZ.x * 3.0999999);
  rayEnd.y = v4 - (float)(UFG::qVector3::msAxisZ.y * 3.0999999);
  rayEnd.z = v6 - (float)(UFG::qVector3::msAxisZ.z * 3.0999999);
  v8 = UFG::qDataHash64(&data, 0xCui64, 0xFFFFFFFFFFFFFFFFui64);
  v9 = 0;
  v10 = UFG::coverObjectParkour_RayCastCache;
  do
  {
    if ( v8 == v10->pos_hash )
    {
      v15 = v9;
      v7 = UFG::coverObjectParkour_RayCastCache[v15].t;
      v11 = UFG::coverObjectParkour_RayCastCache[v15].hit;
      goto LABEL_8;
    }
    ++v10;
    ++v9;
  }
  while ( (signed __int64)v10 < (signed __int64)&UFG::coverObjectParkour_RayCastCacheIndex );
  v27.mInput.m_to.m_quad.m128_i8[8] = 0;
  v27.mInput.m_to.m_quad.m128_i32[3] = 0;
  *(_QWORD *)&v27.mInput.m_enableShapeCollectionFilter.m_bool = 0i64;
  v27.mOutput.m_shapeKeys[6] = 0;
  *((_QWORD *)&v27.mOutput.m_shapeKeyIndex + 1) = 0i64;
  v27.mOutput.m_normal.m_quad.m128_u64[1] = __PAIR__(-1, (unsigned int)FLOAT_1_0);
  *((_QWORD *)&v27.mOutput.m_rootCollidable + 1) = "FindParkourSyncPos";
  v27.mOutput.m_pad[0] = -1;
  LODWORD(v27.mDebugName) = -1;
  UFG::RayCastData::Init(&v27, (UFG::qVector3 *)&data, &rayEnd, 0xDu);
  v11 = UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, &v27);
  v12 = v27.normal.y;
  if ( v11 )
    v7 = v27.normal.y;
  v13 = UFG::coverObjectParkour_RayCastCacheIndex;
  v14 = UFG::coverObjectParkour_RayCastCacheIndex + 1;
  UFG::coverObjectParkour_RayCastCache[v13].pos_hash = v8;
  UFG::coverObjectParkour_RayCastCache[v13].hit = v11;
  UFG::coverObjectParkour_RayCastCache[v13].t = v12;
  UFG::coverObjectParkour_RayCastCacheIndex = v14 & 0x1F;
LABEL_8:
  if ( v11
    && ((v16 = v21 - (float)((float)((float)(rayEnd.z - v21) * v7) + v21),
         !UFG::ParkourHandle::IsAttachedToVehicle(v1->m_pParkourHandle.m_pPointer)) ? (v17 = FLOAT_0_89999998) : (v17 = FLOAT_0_69999999),
        v16 > v17) )
  {
    v1->m_bFoundParkourSync = 1;
    result = 1;
    LODWORD(v1->m_fParkourSyncZOffset) = LODWORD(v16) ^ _xmm[0];
  }
  else
  {
    v1->m_bFoundParkourSync = 0;
    result = 0;
  }
  return result;
}

// File Line: 443
// RVA: 0x362970
UFG::qVector3 *__usercall UFG::CoverObjectParkour::GetSyncPos@<rax>(UFG::CoverObjectParkour *this@<rcx>, UFG::qVector3 *result@<rdx>, float a3@<xmm0>)
{
  UFG::qVector3 *v3; // rbx

  v3 = result;
  UFG::CoverObjectParkour::GetParkourSync(this, result, a3);
  return v3;
}

// File Line: 451
// RVA: 0x3600F0
bool __fastcall UFG::CoverObjectParkour::GetInUse(UFG::CoverObjectParkour *this)
{
  UFG::ParkourHandle *v1; // rax

  v1 = this->m_pParkourHandle.m_pPointer;
  if ( v1 )
    LOBYTE(v1) = (*((_BYTE *)v1 + 152) & 0x1C) != 0;
  return (char)v1;
}

// File Line: 461
// RVA: 0x386860
void __fastcall UFG::CoverObjectParkour::SetInUse(UFG::CoverObjectParkour *this, bool bInUse)
{
  UFG::ParkourHandle *v2; // r8

  v2 = this->m_pParkourHandle.m_pPointer;
  if ( v2 )
  {
    if ( bInUse )
      *((_DWORD *)v2 + 38) ^= ((unsigned __int8)*((_DWORD *)v2 + 38) ^ (unsigned __int8)((*((_DWORD *)v2 + 38) & 0xFC)
                                                                                       + 4)) & 0x1C;
    else
      *((_DWORD *)v2 + 38) ^= ((unsigned __int8)*((_DWORD *)v2 + 38) ^ (unsigned __int8)(4 * (*((_DWORD *)v2 + 38) >> 2)
                                                                                       - 4)) & 0x1C;
  }
}

// File Line: 476
// RVA: 0x341630
void __fastcall UFG::CoverObjectParkour::AddUser(UFG::CoverObjectParkour *this, UFG::SimObject *pUser)
{
  UFG::SimObject *v2; // rdi
  UFG::CoverObjectParkour *v3; // rbx
  _BOOL8 v4; // rdx
  UFG::allocator::free_link *v5; // rsi
  UFG::allocator::free_link *v6; // rax
  UFG::qNode<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser> *v7; // rcx
  UFG::qNode<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser> *v8; // rax

  v2 = pUser;
  v3 = this;
  ((void (__cdecl *)(UFG::CoverObjectParkour *))this->vfptr->GetInUse)(this);
  LOBYTE(v4) = 1;
  v3->vfptr->SetInUse((UFG::CoverObjectBase *)&v3->vfptr, v4);
  v5 = (UFG::allocator::free_link *)v3->m_pParkourHandle.m_pPointer;
  v6 = UFG::qMalloc(0x20ui64, "CoverUser", 0i64);
  if ( v6 )
  {
    v6->mNext = v6;
    v6[1].mNext = v6;
  }
  v3->m_pCoverUser = (UFG::CoverObjectBase::CoverUser *)v6;
  v6[2].mNext = v5;
  v3->m_pCoverUser->pUser = v2;
  v7 = (UFG::qNode<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser> *)&v3->m_pCoverUser->mPrev;
  v8 = UFG::CoverObjectBase::ms_listUsers.mNode.mPrev;
  UFG::CoverObjectBase::ms_listUsers.mNode.mPrev->mNext = v7;
  v7->mPrev = v8;
  v7->mNext = (UFG::qNode<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser> *)&UFG::CoverObjectBase::ms_listUsers;
  UFG::CoverObjectBase::ms_listUsers.mNode.mPrev = v7;
}

// File Line: 496
// RVA: 0x381610
void __fastcall UFG::CoverObjectParkour::RemoveUser(UFG::CoverObjectParkour *this)
{
  UFG::CoverObjectParkour *v1; // rbx
  UFG::CoverObjectBase::CoverUser *v2; // rdx
  UFG::qNode<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser> *v3; // rcx
  UFG::qNode<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser> *v4; // rax
  UFG::CoverObjectBase::CoverUser *v5; // rcx
  UFG::qNode<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser> *v6; // rdx
  UFG::qNode<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser> *v7; // rax

  v1 = this;
  if ( (*((unsigned __int8 (__cdecl **)(UFG::CoverObjectParkour *))&this->vfptr->__vecDelDtor + 2))(this) )
    v1->vfptr->GetInUse((UFG::CoverObjectBase *)&v1->vfptr);
  v1->vfptr->SetInUse((UFG::CoverObjectBase *)&v1->vfptr, 0);
  v2 = v1->m_pCoverUser;
  v3 = v2->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = (UFG::qNode<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser> *)&v2->mPrev;
  v5 = v1->m_pCoverUser;
  if ( v5 )
  {
    v6 = v5->mPrev;
    v7 = v5->mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v5->mPrev = (UFG::qNode<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser> *)&v5->mPrev;
    v5->mNext = (UFG::qNode<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser> *)&v5->mPrev;
    operator delete[](v5);
  }
  v1->m_pCoverUser = 0i64;
}

// File Line: 513
// RVA: 0x34CA20
char __fastcall UFG::CoverObjectParkour::CanUse(UFG::CoverObjectParkour *this, UFG::SimObject *pUser)
{
  UFG::SimObject *v2; // rdi
  UFG::CoverObjectParkour *v3; // rbx
  UFG::qList<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser,1,0> *v5; // rax

  v2 = pUser;
  v3 = this;
  if ( (*((unsigned __int8 (**)(void))&this->vfptr->__vecDelDtor + 2))()
    && UFG::ParkourHandle::GetHalfLength(v3->m_pParkourHandle.m_pPointer) >= 0.55000001 )
  {
    if ( !v3->vfptr->GetInUse((UFG::CoverObjectBase *)&v3->vfptr) )
      return 1;
    v5 = (UFG::qList<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser,1,0> *)UFG::CoverObjectBase::ms_listUsers.mNode.mNext;
    if ( (UFG::qList<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser,1,0> *)UFG::CoverObjectBase::ms_listUsers.mNode.mNext != &UFG::CoverObjectBase::ms_listUsers )
    {
      while ( v5[1].mNode.mPrev != (UFG::qNode<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser> *)v3->m_pParkourHandle.m_pPointer
           || (UFG::SimObject *)v5[1].mNode.mNext != v2 )
      {
        v5 = (UFG::qList<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser,1,0> *)v5->mNode.mNext;
        if ( v5 == &UFG::CoverObjectBase::ms_listUsers )
          return 0;
      }
      return 1;
    }
  }
  return 0;
}

// File Line: 545
// RVA: 0x369A90
bool __fastcall UFG::CoverObjectParkour::IsAnyLineOrCornerShared(UFG::CoverObjectParkour *this, UFG::CoverObjectBase *pOther)
{
  UFG::CoverObjectParkour *v2; // rdi
  UFG::CoverObjectBase *v3; // rbx
  UFG::ParkourHandle *v4; // rax
  bool result; // al

  v2 = this;
  v3 = pOther;
  result = 0;
  if ( pOther->vfptr->IsParkour(pOther) )
  {
    v4 = v2->m_pParkourHandle.m_pPointer;
    if ( v4 )
    {
      if ( (UFG::ParkourHandle *)v3[1].m_pCoverObjectGroup == v4 )
        result = 1;
    }
  }
  return result;
}

// File Line: 562
// RVA: 0x361BF0
UFG::qVector3 *__usercall UFG::CoverObjectParkour::GetParkourSync@<rax>(UFG::CoverObjectParkour *this@<rcx>, UFG::qVector3 *result@<rdx>, float a3@<xmm0>)
{
  UFG::CoverObjectParkour *v3; // rbx
  UFG::qVector3 *v4; // rdi
  float v5; // xmm11_4
  float v6; // xmm0_4
  float v7; // xmm6_4
  float v8; // xmm7_4
  float v9; // xmm11_4
  float v10; // xmm6_4
  float v11; // xmm7_4
  float v12; // xmm8_4
  float v13; // xmm9_4
  float v14; // xmm10_4
  UFG::qVector3 *v15; // rax
  float v16; // xmm6_4
  float v17; // xmm7_4
  float v18; // xmm11_4
  UFG::qVector3 *v19; // rax
  UFG::qVector3 out; // [rsp+20h] [rbp-88h]
  UFG::qVector3 resulta; // [rsp+30h] [rbp-78h]

  v3 = this;
  v4 = result;
  UFG::ParkourHandle::GetNormal(this->m_pParkourHandle.m_pPointer, &out);
  v3->vfptr->GetHeight((UFG::CoverObjectBase *)&v3->vfptr);
  if ( a3 <= 0.5 || a3 >= 1.6 )
    v5 = UFG::CoverObjectBase::ms_fHighFrontOffset;
  else
    v5 = UFG::CoverObjectBase::ms_fLowFrontOffset;
  v6 = v3->m_fParkourSyncZOffset;
  v7 = v5;
  v8 = v5;
  v9 = v5 * out.z;
  v10 = v7 * out.x;
  v11 = v8 * out.y;
  v12 = UFG::qVector3::msAxisZ.x * v6;
  v13 = UFG::qVector3::msAxisZ.y * v6;
  v14 = UFG::qVector3::msAxisZ.z * v6;
  v15 = UFG::ParkourHandle::GetPosition(v3->m_pParkourHandle.m_pPointer, &resulta);
  v16 = v10 + v15->x;
  v17 = v11 + v15->y;
  v18 = v9 + v15->z;
  v19 = v4;
  v4->x = v16 + v12;
  v4->y = v17 + v13;
  v4->z = v18 + v14;
  return v19;
}

