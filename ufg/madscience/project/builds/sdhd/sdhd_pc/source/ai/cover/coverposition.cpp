// File Line: 63
// RVA: 0x32D950
void __fastcall UFG::CoverPosition::CoverPosition(UFG::CoverPosition *this)
{
  float y; // xmm1_4
  float z; // xmm2_4
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm2_4

  this->vfptr = (UFG::CoverObjectBaseVtbl *)&UFG::CoverObjectBase::`vftable;
  this->m_iRefCount = 0;
  this->m_pCoverObjectGroup = 0i64;
  this->m_fPriority = 0.0;
  this->vfptr = (UFG::CoverObjectBaseVtbl *)&UFG::CoverObjectParkour::`vftable;
  this->m_pParkourHandle.mPrev = &this->m_pParkourHandle;
  this->m_pParkourHandle.mNext = &this->m_pParkourHandle;
  this->m_pParkourHandle.m_pPointer = 0i64;
  this->m_bFoundParkourSync = 0;
  this->m_pCoverUser = 0i64;
  this->vfptr = (UFG::CoverObjectBaseVtbl *)&UFG::CoverPosition::`vftable;
  UFG::CoverCornerHandle::CoverCornerHandle(&this->m_LeftCorner);
  UFG::CoverCornerHandle::CoverCornerHandle(&this->m_RightCorner);
  *(_QWORD *)&this->m_fDistToLeft = 0i64;
  y = UFG::qVector3::msAxisZ.y;
  z = UFG::qVector3::msAxisZ.z;
  this->m_vInbetweenParkourPosition.x = UFG::qVector3::msAxisZ.x;
  this->m_vInbetweenParkourPosition.y = y;
  this->m_vInbetweenParkourPosition.z = z;
  v4 = UFG::qVector3::msAxisX.y;
  v5 = UFG::qVector3::msAxisX.z;
  this->m_vInbetweenParkourNormal.x = UFG::qVector3::msAxisX.x;
  this->m_vInbetweenParkourNormal.y = v4;
  this->m_vInbetweenParkourNormal.z = v5;
  v6 = UFG::qVector3::msAxisY.y;
  v7 = UFG::qVector3::msAxisY.z;
  this->m_vInbetweenParkourAxis.x = UFG::qVector3::msAxisY.x;
  this->m_vInbetweenParkourAxis.y = v6;
  this->m_vInbetweenParkourAxis.z = v7;
  this->m_bInbetweenParkourLine = 0;
  this->m_NavPosition.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::NavPositionBase::`vftable;
  v8 = UFG::qVector3::msZero.y;
  v9 = UFG::qVector3::msZero.z;
  this->m_NavPosition.m_vPosition.x = UFG::qVector3::msZero.x;
  this->m_NavPosition.m_vPosition.y = v8;
  this->m_NavPosition.m_vPosition.z = v9;
  this->m_NavPosition.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
  this->m_NavPosition.m_bValid = 0;
  this->m_NavPosition.m_hkvMeshPosition = (hkVector4f)hkvZero_13.m_quad;
  *(_QWORD *)&this->m_NavPosition.m_packedKey = -1i64;
  this->m_bfFiringPositionClear.mBits[0] = 0i64;
  this->m_aCoverUsers.size = 0;
}

// File Line: 77
// RVA: 0x32D620
void __fastcall UFG::CoverPosition::CoverPosition(UFG::CoverPosition *this, UFG::CoverCorner *pCorner)
{
  float y; // xmm1_4
  float z; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  UFG::CoverCornerHandle *p_m_RightCorner; // rcx

  this->vfptr = (UFG::CoverObjectBaseVtbl *)&UFG::CoverObjectBase::`vftable;
  this->m_iRefCount = 0;
  this->m_pCoverObjectGroup = 0i64;
  this->m_fPriority = 0.0;
  this->vfptr = (UFG::CoverObjectBaseVtbl *)&UFG::CoverObjectParkour::`vftable;
  this->m_pParkourHandle.mPrev = &this->m_pParkourHandle;
  this->m_pParkourHandle.mNext = &this->m_pParkourHandle;
  this->m_pParkourHandle.m_pPointer = 0i64;
  this->m_bFoundParkourSync = 0;
  this->m_pCoverUser = 0i64;
  this->vfptr = (UFG::CoverObjectBaseVtbl *)&UFG::CoverPosition::`vftable;
  UFG::CoverCornerHandle::CoverCornerHandle(&this->m_LeftCorner);
  UFG::CoverCornerHandle::CoverCornerHandle(&this->m_RightCorner);
  *(_QWORD *)&this->m_fDistToLeft = 0i64;
  y = UFG::qVector3::msAxisZ.y;
  z = UFG::qVector3::msAxisZ.z;
  this->m_vInbetweenParkourPosition.x = UFG::qVector3::msAxisZ.x;
  this->m_vInbetweenParkourPosition.y = y;
  this->m_vInbetweenParkourPosition.z = z;
  v6 = UFG::qVector3::msAxisX.y;
  v7 = UFG::qVector3::msAxisX.z;
  this->m_vInbetweenParkourNormal.x = UFG::qVector3::msAxisX.x;
  this->m_vInbetweenParkourNormal.y = v6;
  this->m_vInbetweenParkourNormal.z = v7;
  v8 = UFG::qVector3::msAxisY.y;
  v9 = UFG::qVector3::msAxisY.z;
  this->m_vInbetweenParkourAxis.x = UFG::qVector3::msAxisY.x;
  this->m_vInbetweenParkourAxis.y = v8;
  this->m_vInbetweenParkourAxis.z = v9;
  this->m_bInbetweenParkourLine = 0;
  this->m_NavPosition.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::NavPositionBase::`vftable;
  v10 = UFG::qVector3::msZero.y;
  v11 = UFG::qVector3::msZero.z;
  this->m_NavPosition.m_vPosition.x = UFG::qVector3::msZero.x;
  this->m_NavPosition.m_vPosition.y = v10;
  this->m_NavPosition.m_vPosition.z = v11;
  this->m_NavPosition.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
  this->m_NavPosition.m_bValid = 0;
  this->m_NavPosition.m_hkvMeshPosition = (hkVector4f)hkvZero_13.m_quad;
  *(_QWORD *)&this->m_NavPosition.m_packedKey = -1i64;
  this->m_bfFiringPositionClear.mBits[0] = 0i64;
  this->m_aCoverUsers.size = 0;
  p_m_RightCorner = &this->m_RightCorner;
  if ( pCorner->m_eCoverSide.mValue != 1 )
    p_m_RightCorner = &this->m_LeftCorner;
  UFG::CoverCornerHandle::operator=(p_m_RightCorner, pCorner);
}

// File Line: 93
// RVA: 0x32D7F0
void __fastcall UFG::CoverPosition::CoverPosition(UFG::CoverPosition *this, UFG::ParkourHandle *pParkourHandle)
{
  float y; // xmm1_4
  float z; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm2_4

  UFG::CoverObjectParkour::CoverObjectParkour(this, pParkourHandle);
  this->vfptr = (UFG::CoverObjectBaseVtbl *)&UFG::CoverPosition::`vftable;
  UFG::CoverCornerHandle::CoverCornerHandle(&this->m_LeftCorner);
  UFG::CoverCornerHandle::CoverCornerHandle(&this->m_RightCorner);
  *(_QWORD *)&this->m_fDistToLeft = 0i64;
  y = UFG::qVector3::msAxisZ.y;
  z = UFG::qVector3::msAxisZ.z;
  this->m_vInbetweenParkourPosition.x = UFG::qVector3::msAxisZ.x;
  this->m_vInbetweenParkourPosition.y = y;
  this->m_vInbetweenParkourPosition.z = z;
  v5 = UFG::qVector3::msAxisX.y;
  v6 = UFG::qVector3::msAxisX.z;
  this->m_vInbetweenParkourNormal.x = UFG::qVector3::msAxisX.x;
  this->m_vInbetweenParkourNormal.y = v5;
  this->m_vInbetweenParkourNormal.z = v6;
  v7 = UFG::qVector3::msAxisY.y;
  v8 = UFG::qVector3::msAxisY.z;
  this->m_vInbetweenParkourAxis.x = UFG::qVector3::msAxisY.x;
  this->m_vInbetweenParkourAxis.y = v7;
  this->m_vInbetweenParkourAxis.z = v8;
  this->m_bInbetweenParkourLine = 0;
  this->m_NavPosition.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::NavPositionBase::`vftable;
  v9 = UFG::qVector3::msZero.y;
  v10 = UFG::qVector3::msZero.z;
  this->m_NavPosition.m_vPosition.x = UFG::qVector3::msZero.x;
  this->m_NavPosition.m_vPosition.y = v9;
  this->m_NavPosition.m_vPosition.z = v10;
  this->m_NavPosition.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
  this->m_NavPosition.m_bValid = 0;
  this->m_NavPosition.m_hkvMeshPosition = (hkVector4f)hkvZero_13.m_quad;
  *(_QWORD *)&this->m_NavPosition.m_packedKey = -1i64;
  this->m_bfFiringPositionClear.mBits[0] = 0i64;
  this->m_aCoverUsers.size = 0;
}

// File Line: 124
// RVA: 0x35C4D0
UFG::CoverPosition *__fastcall UFG::CoverPosition::GetCoverPosition(
        UFG::CoverPosition *this,
        UFG::qVector3 *vCharPos,
        UFG::CoverPosition *pCurrentPosition,
        float fRange)
{
  UFG::CoverPosition *v4; // rbx
  UFG::DynamicCoverCorner *m_pPointer; // rsi
  UFG::CoverCorner *v8; // rsi
  UFG::qResourceData *mData; // rax
  UFG::qBaseNodeRB *v10; // rcx
  UFG::allocator::free_link *v11; // rax
  UFG::CoverPosition *v12; // rax
  UFG::DynamicCoverCorner *v13; // rsi
  UFG::CoverCorner *v14; // rsi
  UFG::qResourceData *v15; // rax
  UFG::qBaseNodeRB *v16; // rcx
  UFG::allocator::free_link *v17; // rax
  UFG::CoverPosition *v18; // rax
  UFG::ParkourHandle *v19; // rcx
  float v20; // xmm8_4
  float v21; // xmm7_4
  float v22; // xmm6_4
  float v23; // xmm9_4
  __m128 x_low; // xmm3
  __m128 v25; // xmm1
  float v26; // xmm2_4
  float v27; // xmm6_4
  UFG::ParkourHandle *v28; // r8
  UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle> *p_m_pParkourHandle; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v32; // rax
  UFG::allocator::free_link *v33; // rax
  UFG::CoverPosition *v34; // rax
  float v35; // xmm6_4
  float v36; // xmm6_4
  float v37; // xmm0_4
  UFG::qVector3 out; // [rsp+28h] [rbp-80h] BYREF
  UFG::qVector3 result; // [rsp+38h] [rbp-70h] BYREF
  UFG::qVector3 p0; // [rsp+48h] [rbp-60h] BYREF
  UFG::qVector3 p1; // [rsp+54h] [rbp-54h] BYREF

  v4 = pCurrentPosition;
  if ( (_S62 & 1) == 0 )
  {
    _S62 |= 1u;
    kfRangeSquared_0 = FLOAT_0_25;
  }
  m_pPointer = this->m_LeftCorner.m_pDynamicCoverCorner.m_pPointer;
  if ( m_pPointer )
  {
    v8 = &m_pPointer->UFG::CoverCorner;
  }
  else
  {
    mData = this->m_LeftCorner.m_ResourceHandle.mData;
    if ( !mData )
      goto LABEL_17;
    v10 = mData[1].mNode.mChild[0];
    if ( v10 )
      v10 = (UFG::qBaseNodeRB *)((char *)v10 + (_QWORD)mData + 96);
    v8 = (UFG::CoverCorner *)((char *)v10 + 48 * this->m_LeftCorner.m_uCoverCornerIndex);
  }
  if ( v8 )
  {
    if ( pCurrentPosition )
    {
      if ( v8->m_eCoverSide.mValue == 1 )
        UFG::CoverCornerHandle::operator=(&pCurrentPosition->m_RightCorner, v8);
      else
        UFG::CoverCornerHandle::operator=(&pCurrentPosition->m_LeftCorner, v8);
    }
    else
    {
      v11 = UFG::qMalloc(0x170ui64, "CoverPosition", 0i64);
      if ( v11 )
      {
        UFG::CoverPosition::CoverPosition((UFG::CoverPosition *)v11, v8);
        v4 = v12;
      }
      else
      {
        v4 = 0i64;
      }
    }
  }
LABEL_17:
  v13 = this->m_RightCorner.m_pDynamicCoverCorner.m_pPointer;
  if ( v13 )
  {
    v14 = &v13->UFG::CoverCorner;
  }
  else
  {
    v15 = this->m_RightCorner.m_ResourceHandle.mData;
    if ( !v15 )
      goto LABEL_31;
    v16 = v15[1].mNode.mChild[0];
    if ( v16 )
      v16 = (UFG::qBaseNodeRB *)((char *)v16 + (_QWORD)v15 + 96);
    v14 = (UFG::CoverCorner *)((char *)v16 + 48 * this->m_RightCorner.m_uCoverCornerIndex);
  }
  if ( v14 )
  {
    if ( v4 )
    {
      if ( v14->m_eCoverSide.mValue == 1 )
        UFG::CoverCornerHandle::operator=(&v4->m_RightCorner, v14);
      else
        UFG::CoverCornerHandle::operator=(&v4->m_LeftCorner, v14);
    }
    else
    {
      v17 = UFG::qMalloc(0x170ui64, "CoverPosition", 0i64);
      if ( v17 )
      {
        UFG::CoverPosition::CoverPosition((UFG::CoverPosition *)v17, v14);
        v4 = v18;
      }
      else
      {
        v4 = 0i64;
      }
    }
  }
LABEL_31:
  v19 = this->m_pParkourHandle.m_pPointer;
  if ( v19 )
  {
    UFG::ParkourHandle::GetPosition(v19, &result);
    UFG::ParkourHandle::GetEndpoints(this->m_pParkourHandle.m_pPointer, &p0, &p1);
    v20 = vCharPos->z - p0.z;
    v21 = vCharPos->y - p0.y;
    v22 = vCharPos->x - p0.x;
    if ( UFG::ParkourHandle::GetNormal(this->m_pParkourHandle.m_pPointer, &out) )
    {
      v23 = (float)((float)(out.x * v22) + (float)(out.y * v21)) + (float)(out.z * v20);
      x_low = (__m128)LODWORD(p1.x);
      x_low.m128_f32[0] = p1.x - p0.x;
      v25 = x_low;
      v25.m128_f32[0] = (float)(x_low.m128_f32[0] * x_low.m128_f32[0])
                      + (float)((float)(p1.y - p0.y) * (float)(p1.y - p0.y));
      v26 = 1.0 / _mm_sqrt_ps(v25).m128_f32[0];
      v27 = (float)(v22 * (float)((float)(p1.x - p0.x) * v26)) + (float)((float)((float)(p1.y - p0.y) * v26) * v21);
      if ( v4 )
      {
        v28 = this->m_pParkourHandle.m_pPointer;
        p_m_pParkourHandle = &v4->m_pParkourHandle;
        if ( v4->m_pParkourHandle.m_pPointer )
        {
          mPrev = p_m_pParkourHandle->mPrev;
          mNext = v4->m_pParkourHandle.mNext;
          mPrev->mNext = mNext;
          mNext->mPrev = mPrev;
          p_m_pParkourHandle->mPrev = p_m_pParkourHandle;
          v4->m_pParkourHandle.mNext = &v4->m_pParkourHandle;
        }
        v4->m_pParkourHandle.m_pPointer = v28;
        if ( v28 )
        {
          v32 = v28->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::ParkourHandle>::mPrev;
          v32->mNext = p_m_pParkourHandle;
          p_m_pParkourHandle->mPrev = v32;
          v4->m_pParkourHandle.mNext = &v28->m_SafePointerList.mNode;
          v28->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::ParkourHandle>::mPrev = p_m_pParkourHandle;
        }
      }
      else
      {
        v33 = UFG::qMalloc(0x170ui64, "CoverPosition", 0i64);
        if ( v33 )
        {
          UFG::CoverPosition::CoverPosition((UFG::CoverPosition *)v33, this->m_pParkourHandle.m_pPointer);
          v4 = v34;
        }
        else
        {
          v4 = 0i64;
        }
      }
      v35 = v27 - UFG::ParkourHandle::GetHalfLength(this->m_pParkourHandle.m_pPointer);
      v4->m_bFoundParkourSync = this->m_bFoundParkourSync;
      v4->m_fParkourSyncZOffset = this->m_fParkourSyncZOffset;
      v4->m_fParkourTVal = v35;
      v4->m_fDistanceInFront = v23;
      v36 = v35 - this->m_fParkourTVal;
      v37 = this->m_fDistToRight - v36;
      v4->m_fDistToLeft = v36 + this->m_fDistToLeft;
      v4->m_fDistToRight = v37;
    }
  }
  return v4;
}

// File Line: 211
// RVA: 0x36C050
bool __fastcall UFG::CoverPosition::IsValid(UFG::CoverPosition *this)
{
  UFG::DynamicCoverComponent **v2; // rsi
  UFG::DynamicCoverCorner *m_pPointer; // rcx
  UFG::CoverCorner *v4; // rax
  UFG::DynamicCoverComponent **p_z; // rcx
  UFG::qVector3 *Velocity; // rax
  UFG::DynamicCoverCorner *v7; // rcx
  UFG::CoverCorner *v8; // rax
  UFG::qVector3 *v9; // rax

  if ( UFG::CoverObjectParkour::IsValid(this) || this->m_bInbetweenParkourLine )
    return 1;
  v2 = 0i64;
  if ( this->m_LeftCorner.m_ResourceHandle.mData && this->m_LeftCorner.m_uCoverCornerIndex != 0xFFFF
    || (m_pPointer = this->m_LeftCorner.m_pDynamicCoverCorner.m_pPointer) != 0i64
    && UFG::DynamicCoverComponent::IsEnabled((UFG::DynamicCoverComponent *)m_pPointer->m_pParentInstance.m_pPointer) )
  {
    if ( !this->m_LeftCorner.m_pDynamicCoverCorner.m_pPointer )
      return 1;
    v4 = UFG::CoverCornerHandle::Get(&this->m_LeftCorner);
    p_z = (UFG::DynamicCoverComponent **)&v4[-1].m_vCornerPosition.z;
    if ( !v4 )
      p_z = 0i64;
    Velocity = UFG::DynamicCoverComponent::GetVelocity(p_z[11]);
    if ( (float)((float)(Velocity->x * Velocity->x) + (float)(Velocity->y * Velocity->y)) < (float)(UFG::CoverObjectBase::ms_fMaxCoverVelocity
                                                                                                  * UFG::CoverObjectBase::ms_fMaxCoverVelocity) )
      return 1;
  }
  if ( !this->m_RightCorner.m_ResourceHandle.mData || this->m_RightCorner.m_uCoverCornerIndex == 0xFFFF )
  {
    v7 = this->m_RightCorner.m_pDynamicCoverCorner.m_pPointer;
    if ( !v7 || !UFG::DynamicCoverComponent::IsEnabled((UFG::DynamicCoverComponent *)v7->m_pParentInstance.m_pPointer) )
      return 0;
  }
  if ( !this->m_RightCorner.m_pDynamicCoverCorner.m_pPointer )
    return 1;
  v8 = UFG::CoverCornerHandle::Get(&this->m_RightCorner);
  if ( v8 )
    v2 = (UFG::DynamicCoverComponent **)&v8[-1].m_vCornerPosition.z;
  v9 = UFG::DynamicCoverComponent::GetVelocity(v2[11]);
  return (float)((float)(v9->y * v9->y) + (float)(v9->x * v9->x)) < (float)(UFG::CoverObjectBase::ms_fMaxCoverVelocity
                                                                          * UFG::CoverObjectBase::ms_fMaxCoverVelocity);
}

// File Line: 257
// RVA: 0x361F80
UFG::qVector3 *__fastcall UFG::CoverPosition::GetPosition(UFG::CoverPosition *this, UFG::qVector3 *result)
{
  UFG::CoverCorner *v4; // rsi
  UFG::CoverCorner *v5; // rax
  float z; // eax
  float y; // ecx
  UFG::ParkourHandle *m_pPointer; // rcx
  float m_fParkourTVal; // xmm8_4
  UFG::qVector3 *Axis; // rax
  float v11; // xmm6_4
  float v12; // xmm7_4
  float v13; // xmm8_4
  float v14; // xmm6_4
  float v15; // xmm7_4
  UFG::qVector3 *Position; // rax
  float v17; // xmm7_4
  float v18; // xmm8_4
  float v19; // xmm0_4
  float v20; // xmm2_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  UFG::qVector3 resulta; // [rsp+20h] [rbp-58h] BYREF
  UFG::qVector3 v25; // [rsp+2Ch] [rbp-4Ch] BYREF

  v4 = UFG::CoverCornerHandle::Get(&this->m_LeftCorner);
  v5 = UFG::CoverCornerHandle::Get(&this->m_RightCorner);
  if ( v4 )
  {
    z = v4->m_vCornerPosition.z;
    result->x = v4->m_vCornerPosition.x;
    y = v4->m_vCornerPosition.y;
    result->z = z;
    result->y = y;
  }
  else if ( v5 )
  {
    result->x = v5->m_vCornerPosition.x;
    result->y = v5->m_vCornerPosition.y;
    result->z = v5->m_vCornerPosition.z;
  }
  else
  {
    m_pPointer = this->m_pParkourHandle.m_pPointer;
    if ( m_pPointer )
    {
      m_fParkourTVal = this->m_fParkourTVal;
      Axis = UFG::ParkourHandle::GetAxis(m_pPointer, &resulta);
      v11 = m_fParkourTVal;
      v12 = m_fParkourTVal;
      v13 = m_fParkourTVal * Axis->z;
      v14 = v11 * Axis->x;
      v15 = v12 * Axis->y;
      Position = UFG::ParkourHandle::GetPosition(this->m_pParkourHandle.m_pPointer, &v25);
      v17 = v15 + Position->y;
      v18 = v13 + Position->z;
      result->x = v14 + Position->x;
      result->y = v17;
      result->z = v18;
    }
    else
    {
      v19 = this->m_fParkourTVal;
      v20 = (float)(v19 * this->m_vInbetweenParkourAxis.z) + this->m_vInbetweenParkourPosition.z;
      v21 = (float)(v19 * this->m_vInbetweenParkourAxis.x) + this->m_vInbetweenParkourPosition.x;
      v22 = (float)(this->m_fParkourTVal * this->m_vInbetweenParkourAxis.y) + this->m_vInbetweenParkourPosition.y;
      result->z = v20;
      result->x = v21;
      result->y = v22;
    }
  }
  return result;
}

// File Line: 282
// RVA: 0x359870
float __fastcall UFG::CoverPosition::GetAngleFromSweetSpot(UFG::CoverPosition *this, UFG::qVector3 *vPosition)
{
  UFG::CoverCorner *v4; // rsi
  UFG::CoverCorner *v5; // r14
  float v6; // xmm7_4
  float v7; // xmm6_4
  float v8; // xmm8_4
  float v9; // xmm5_4
  __m128 y_low; // xmm3
  float v11; // xmm4_4
  __m128 v12; // xmm2
  float v13; // xmm2_4
  float v14; // xmm2_4
  float v15; // xmm0_4
  float v16; // xmm3_4
  __m128 v17; // xmm4
  float v18; // xmm5_4
  __m128 v19; // xmm2
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm0_4
  UFG::ParkourHandle *m_pPointer; // r8
  float v24; // xmm3_4
  __m128 v25; // xmm2
  float v26; // xmm4_4
  __m128 v27; // xmm5
  float v28; // xmm2_4
  float v29; // xmm0_4
  UFG::qVector3 result; // [rsp+18h] [rbp-39h] BYREF
  UFG::qVector3 out; // [rsp+28h] [rbp-29h] BYREF

  v4 = UFG::CoverCornerHandle::Get(&this->m_LeftCorner);
  v5 = UFG::CoverCornerHandle::Get(&this->m_RightCorner);
  v6 = FLOAT_3_4028235e38;
  v7 = *(float *)&FLOAT_1_0;
  v8 = 0.0;
  if ( v4 )
  {
    UFG::CoverCorner::GetFiringPos(v4, &result);
    UFG::CoverCorner::GetSweetSpotDir(v4, &out);
    y_low = (__m128)LODWORD(vPosition->y);
    v9 = vPosition->x - result.x;
    y_low.m128_f32[0] = y_low.m128_f32[0] - result.y;
    v11 = vPosition->z - result.z;
    v12 = y_low;
    v12.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v9 * v9)) + (float)(v11 * v11);
    if ( v12.m128_f32[0] == 0.0 )
      v13 = 0.0;
    else
      v13 = 1.0 / _mm_sqrt_ps(v12).m128_f32[0];
    v14 = (float)((float)(out.y * (float)(y_low.m128_f32[0] * v13)) + (float)(out.x * (float)(v13 * v9)))
        + (float)(out.z * (float)(v11 * v13));
    if ( v14 <= -1.0 )
    {
      v14 = FLOAT_N1_0;
    }
    else if ( v14 >= 1.0 )
    {
      v14 = *(float *)&FLOAT_1_0;
    }
    v15 = acosf(v14);
    if ( v15 <= 3.4028235e38 )
      v6 = v15;
  }
  if ( v5 )
  {
    UFG::CoverCorner::GetFiringPos(v5, &out);
    UFG::CoverCorner::GetSweetSpotDir(v5, &result);
    v17 = (__m128)LODWORD(vPosition->y);
    v16 = vPosition->x - out.x;
    v17.m128_f32[0] = v17.m128_f32[0] - out.y;
    v18 = vPosition->z - out.z;
    v19 = v17;
    v19.m128_f32[0] = (float)((float)(v17.m128_f32[0] * v17.m128_f32[0]) + (float)(v16 * v16)) + (float)(v18 * v18);
    if ( v19.m128_f32[0] == 0.0 )
      v20 = 0.0;
    else
      v20 = 1.0 / _mm_sqrt_ps(v19).m128_f32[0];
    v21 = (float)((float)(result.y * (float)(v17.m128_f32[0] * v20)) + (float)(result.x * (float)(v16 * v20)))
        + (float)(result.z * (float)(v18 * v20));
    if ( v21 <= -1.0 )
    {
      v21 = FLOAT_N1_0;
    }
    else if ( v21 >= 1.0 )
    {
      v21 = *(float *)&FLOAT_1_0;
    }
    v22 = acosf(v21);
    if ( v6 >= v22 )
      v6 = v22;
  }
  m_pPointer = this->m_pParkourHandle.m_pPointer;
  if ( m_pPointer )
  {
    UFG::CoverObjectParkour::GetParkourFiringPosition(this, &result, m_pPointer, this->m_fParkourTVal);
    UFG::ParkourHandle::GetNormal(this->m_pParkourHandle.m_pPointer, &out);
    v25 = (__m128)LODWORD(vPosition->y);
    v24 = vPosition->x - result.x;
    v25.m128_f32[0] = v25.m128_f32[0] - result.y;
    v27 = v25;
    v26 = vPosition->z - result.z;
    v27.m128_f32[0] = (float)((float)(v25.m128_f32[0] * v25.m128_f32[0]) + (float)(v24 * v24)) + (float)(v26 * v26);
    if ( v27.m128_f32[0] != 0.0 )
      v8 = 1.0 / _mm_sqrt_ps(v27).m128_f32[0];
    v28 = (float)((float)((float)(v25.m128_f32[0] * v8) * COERCE_FLOAT(LODWORD(out.y) ^ _xmm[0]))
                + (float)((float)(v24 * v8) * COERCE_FLOAT(LODWORD(out.x) ^ _xmm[0])))
        + (float)((float)(v26 * v8) * COERCE_FLOAT(LODWORD(out.z) ^ _xmm[0]));
    if ( v28 <= -1.0 )
    {
      v28 = FLOAT_N1_0;
    }
    else if ( v28 >= 1.0 )
    {
LABEL_29:
      v29 = acosf(v7);
      if ( v6 >= v29 )
        return v29;
      return v6;
    }
    v7 = v28;
    goto LABEL_29;
  }
  return v6;
}

// File Line: 318
// RVA: 0x35F8B0
UFG::qVector3 *__fastcall UFG::CoverPosition::GetFiringPosition(UFG::CoverPosition *this, UFG::qVector3 *result)
{
  UFG::DynamicCoverCorner *m_pPointer; // rcx
  UFG::CoverCornerHandle *p_m_LeftCorner; // rcx
  UFG::CoverCorner *v6; // rax
  UFG::DynamicCoverCorner *v7; // rcx
  UFG::ParkourHandle *v8; // r8
  float v9; // xmm3_4
  float v10; // xmm2_4
  float v11; // xmm0_4
  float v12; // xmm5_4

  if ( this->m_LeftCorner.m_ResourceHandle.mData && this->m_LeftCorner.m_uCoverCornerIndex != 0xFFFF
    || (m_pPointer = this->m_LeftCorner.m_pDynamicCoverCorner.m_pPointer) != 0i64
    && UFG::DynamicCoverComponent::IsEnabled((UFG::DynamicCoverComponent *)m_pPointer->m_pParentInstance.m_pPointer) )
  {
    p_m_LeftCorner = &this->m_LeftCorner;
LABEL_6:
    v6 = UFG::CoverCornerHandle::Get(p_m_LeftCorner);
    UFG::CoverCorner::GetFiringPos(v6, result);
    return result;
  }
  if ( this->m_RightCorner.m_ResourceHandle.mData && this->m_RightCorner.m_uCoverCornerIndex != 0xFFFF
    || (v7 = this->m_RightCorner.m_pDynamicCoverCorner.m_pPointer) != 0i64
    && UFG::DynamicCoverComponent::IsEnabled((UFG::DynamicCoverComponent *)v7->m_pParentInstance.m_pPointer) )
  {
    p_m_LeftCorner = &this->m_RightCorner;
    goto LABEL_6;
  }
  v8 = this->m_pParkourHandle.m_pPointer;
  if ( v8 )
  {
    UFG::CoverObjectParkour::GetParkourFiringPosition(this, result, v8, this->m_fParkourTVal);
  }
  else
  {
    v9 = UFG::qVector3::msAxisZ.z * 0.2;
    v10 = UFG::qVector3::msAxisZ.y * 0.2;
    v11 = (float)(this->m_fParkourTVal * this->m_vInbetweenParkourAxis.y) + this->m_vInbetweenParkourPosition.y;
    v12 = (float)(this->m_fParkourTVal * this->m_vInbetweenParkourAxis.z) + this->m_vInbetweenParkourPosition.z;
    result->x = (float)((float)(this->m_fParkourTVal * this->m_vInbetweenParkourAxis.x)
                      + this->m_vInbetweenParkourPosition.x)
              + (float)(UFG::qVector3::msAxisZ.x * 0.2);
    result->y = v11 + v10;
    result->z = v12 + v9;
  }
  return result;
}

// File Line: 345
// RVA: 0x3618A0
__int64 __fastcall UFG::CoverPosition::GetNumFiringPositions(UFG::CoverPosition *this)
{
  unsigned int v1; // ebx
  UFG::DynamicCoverCorner *m_pPointer; // rcx
  UFG::DynamicCoverCorner *v4; // rcx
  __int64 result; // rax

  v1 = 0;
  if ( this->m_LeftCorner.m_ResourceHandle.mData && this->m_LeftCorner.m_uCoverCornerIndex != 0xFFFF
    || (m_pPointer = this->m_LeftCorner.m_pDynamicCoverCorner.m_pPointer) != 0i64
    && UFG::DynamicCoverComponent::IsEnabled((UFG::DynamicCoverComponent *)m_pPointer->m_pParentInstance.m_pPointer) )
  {
    v1 = 1;
  }
  if ( this->m_RightCorner.m_ResourceHandle.mData && this->m_RightCorner.m_uCoverCornerIndex != 0xFFFF
    || (v4 = this->m_RightCorner.m_pDynamicCoverCorner.m_pPointer) != 0i64
    && UFG::DynamicCoverComponent::IsEnabled((UFG::DynamicCoverComponent *)v4->m_pParentInstance.m_pPointer) )
  {
    ++v1;
  }
  result = v1 + 1;
  if ( !this->m_pParkourHandle.m_pPointer )
    return v1;
  return result;
}

// File Line: 366
// RVA: 0x35F790
UFG::qVector3 *__fastcall UFG::CoverPosition::GetFiringPosition(
        UFG::CoverPosition *this,
        UFG::qVector3 *result,
        unsigned int index)
{
  int v3; // esi
  UFG::DynamicCoverCorner *m_pPointer; // rcx
  UFG::CoverCornerHandle *p_m_LeftCorner; // rcx
  UFG::CoverCorner *v9; // rax
  UFG::DynamicCoverCorner *v10; // rcx
  int v11; // eax
  UFG::ParkourHandle *v12; // r8
  float y; // xmm1_4
  float z; // xmm2_4

  v3 = 0;
  if ( this->m_LeftCorner.m_ResourceHandle.mData && this->m_LeftCorner.m_uCoverCornerIndex != 0xFFFF
    || (m_pPointer = this->m_LeftCorner.m_pDynamicCoverCorner.m_pPointer) != 0i64
    && UFG::DynamicCoverComponent::IsEnabled((UFG::DynamicCoverComponent *)m_pPointer->m_pParentInstance.m_pPointer) )
  {
    v3 = 1;
    if ( !index )
    {
      p_m_LeftCorner = &this->m_LeftCorner;
LABEL_7:
      v9 = UFG::CoverCornerHandle::Get(p_m_LeftCorner);
      UFG::CoverCorner::GetFiringPos(v9, result);
      return result;
    }
  }
  if ( this->m_RightCorner.m_ResourceHandle.mData && this->m_RightCorner.m_uCoverCornerIndex != 0xFFFF
    || (v10 = this->m_RightCorner.m_pDynamicCoverCorner.m_pPointer) != 0i64
    && UFG::DynamicCoverComponent::IsEnabled((UFG::DynamicCoverComponent *)v10->m_pParentInstance.m_pPointer) )
  {
    v11 = v3++;
    if ( v11 == index )
    {
      p_m_LeftCorner = &this->m_RightCorner;
      goto LABEL_7;
    }
  }
  v12 = this->m_pParkourHandle.m_pPointer;
  if ( v12 && v3 == index )
  {
    UFG::CoverObjectParkour::GetParkourFiringPosition(this, result, v12, this->m_fParkourTVal);
  }
  else
  {
    y = UFG::qVector3::msZero.y;
    z = UFG::qVector3::msZero.z;
    result->x = UFG::qVector3::msZero.x;
    result->y = y;
    result->z = z;
  }
  return result;
}

// File Line: 401
// RVA: 0x35F690
bool __fastcall UFG::CoverPosition::GetFiringPosition(
        UFG::CoverPosition *this,
        UFG::CoverPosition::FiringPositionEnum eFiringPosition,
        UFG::qVector3 *vResultPosition)
{
  int v4; // edx
  UFG::ParkourHandle *v5; // r8
  UFG::qVector3 *FiringPos; // rax
  UFG::CoverCornerHandle *p_m_RightCorner; // rbx
  UFG::DynamicCoverCorner *v8; // rcx
  UFG::CoverCorner *v9; // rax
  UFG::qVector3 *v10; // rdx
  UFG::CoverCornerHandle *p_m_LeftCorner; // rbx
  UFG::DynamicCoverCorner *m_pPointer; // rcx
  float y; // xmm0_4
  float z; // xmm1_4
  bool v15; // al
  UFG::qVector3 result; // [rsp+20h] [rbp-38h] BYREF
  char v17; // [rsp+2Ch] [rbp-2Ch] BYREF
  UFG::qVector3 v18; // [rsp+38h] [rbp-20h] BYREF

  if ( eFiringPosition == FP_Left )
  {
    p_m_LeftCorner = &this->m_LeftCorner;
    if ( !this->m_LeftCorner.m_ResourceHandle.mData || p_m_LeftCorner->m_uCoverCornerIndex == 0xFFFF )
    {
      m_pPointer = this->m_LeftCorner.m_pDynamicCoverCorner.m_pPointer;
      if ( !m_pPointer
        || !UFG::DynamicCoverComponent::IsEnabled((UFG::DynamicCoverComponent *)m_pPointer->m_pParentInstance.m_pPointer) )
      {
        return 0;
      }
    }
    v9 = UFG::CoverCornerHandle::Get(p_m_LeftCorner);
    v10 = &v18;
    goto LABEL_16;
  }
  v4 = eFiringPosition - 1;
  if ( !v4 )
  {
    p_m_RightCorner = &this->m_RightCorner;
    if ( !this->m_RightCorner.m_ResourceHandle.mData || p_m_RightCorner->m_uCoverCornerIndex == 0xFFFF )
    {
      v8 = this->m_RightCorner.m_pDynamicCoverCorner.m_pPointer;
      if ( !v8 || !UFG::DynamicCoverComponent::IsEnabled((UFG::DynamicCoverComponent *)v8->m_pParentInstance.m_pPointer) )
        return 0;
    }
    v9 = UFG::CoverCornerHandle::Get(p_m_RightCorner);
    v10 = (UFG::qVector3 *)&v17;
LABEL_16:
    FiringPos = UFG::CoverCorner::GetFiringPos(v9, v10);
    goto LABEL_17;
  }
  if ( v4 == 1 )
  {
    v5 = this->m_pParkourHandle.m_pPointer;
    if ( v5 )
    {
      FiringPos = UFG::CoverObjectParkour::GetParkourFiringPosition(this, &result, v5, this->m_fParkourTVal);
LABEL_17:
      y = FiringPos->y;
      z = FiringPos->z;
      vResultPosition->x = FiringPos->x;
      v15 = 1;
      vResultPosition->y = y;
      vResultPosition->z = z;
      return v15;
    }
  }
  return 0;
}

// File Line: 437
// RVA: 0x3636F0
UFG::qVector3 *__fastcall UFG::CoverPosition::GetWallNormal(UFG::CoverPosition *this, UFG::qVector3 *result)
{
  bool v2; // zf
  UFG::DynamicCoverCorner *m_pPointer; // rcx
  UFG::CoverCornerHandle *p_m_LeftCorner; // rcx
  UFG::CoverCorner *v7; // rax
  UFG::DynamicCoverCorner *v8; // rcx
  UFG::ParkourHandle *v9; // rcx
  float y; // xmm1_4
  float z; // xmm0_4
  UFG::qVector3 out; // [rsp+20h] [rbp-18h] BYREF

  v2 = this->m_LeftCorner.m_ResourceHandle.mData == 0i64;
  out = UFG::qVector3::msAxisX;
  if ( !v2 && this->m_LeftCorner.m_uCoverCornerIndex != 0xFFFF
    || (m_pPointer = this->m_LeftCorner.m_pDynamicCoverCorner.m_pPointer) != 0i64
    && UFG::DynamicCoverComponent::IsEnabled((UFG::DynamicCoverComponent *)m_pPointer->m_pParentInstance.m_pPointer) )
  {
    p_m_LeftCorner = &this->m_LeftCorner;
LABEL_6:
    v7 = UFG::CoverCornerHandle::Get(p_m_LeftCorner);
    result->z = 0.0;
    *(UFG::qVector2 *)&result->x = v7->m_vWallNormal;
    return result;
  }
  if ( this->m_RightCorner.m_ResourceHandle.mData && this->m_RightCorner.m_uCoverCornerIndex != 0xFFFF
    || (v8 = this->m_RightCorner.m_pDynamicCoverCorner.m_pPointer) != 0i64
    && UFG::DynamicCoverComponent::IsEnabled((UFG::DynamicCoverComponent *)v8->m_pParentInstance.m_pPointer) )
  {
    p_m_LeftCorner = &this->m_RightCorner;
    goto LABEL_6;
  }
  v9 = this->m_pParkourHandle.m_pPointer;
  if ( v9 )
  {
    UFG::ParkourHandle::GetNormal(v9, &out);
  }
  else if ( this->m_bInbetweenParkourLine )
  {
    result->x = this->m_vInbetweenParkourNormal.x;
    result->y = this->m_vInbetweenParkourNormal.y;
    result->z = this->m_vInbetweenParkourNormal.z;
    return result;
  }
  y = out.y;
  result->x = out.x;
  z = out.z;
  result->y = y;
  result->z = z;
  return result;
}

// File Line: 465
// RVA: 0x362990
UFG::qVector3 *__fastcall UFG::CoverPosition::GetSyncPos(UFG::CoverPosition *this, UFG::qVector3 *result)
{
  float v4; // xmm0_4
  float v5; // xmm5_4
  float m_fParkourSyncZOffset; // xmm0_4
  UFG::qVector3 *v7; // rax
  float v8; // xmm2_4
  float v9; // xmm4_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm5_4
  UFG::DynamicCoverCorner *v13; // rcx
  UFG::CoverCornerHandle *p_m_LeftCorner; // rcx
  UFG::CoverCorner *v15; // rax
  UFG::DynamicCoverCorner *m_pPointer; // rcx
  UFG::ParkourHandle *v17; // rcx
  float m_fParkourTVal; // xmm8_4
  UFG::qVector3 *Axis; // rax
  float v20; // xmm6_4
  float v21; // xmm7_4
  float v22; // xmm8_4
  float v23; // xmm6_4
  UFG::qVector3 *ParkourSync; // rax
  float v25; // xmm8_4
  float v26; // xmm6_4
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::qVector3 resulta; // [rsp+20h] [rbp-58h] BYREF
  UFG::qVector3 v30; // [rsp+2Ch] [rbp-4Ch] BYREF

  if ( !this->m_bInbetweenParkourLine )
  {
    if ( this->m_LeftCorner.m_ResourceHandle.mData && this->m_LeftCorner.m_uCoverCornerIndex != 0xFFFF
      || (v13 = this->m_LeftCorner.m_pDynamicCoverCorner.m_pPointer) != 0i64
      && UFG::DynamicCoverComponent::IsEnabled((UFG::DynamicCoverComponent *)v13->m_pParentInstance.m_pPointer) )
    {
      p_m_LeftCorner = &this->m_LeftCorner;
    }
    else
    {
      if ( !this->m_RightCorner.m_ResourceHandle.mData || this->m_RightCorner.m_uCoverCornerIndex == 0xFFFF )
      {
        m_pPointer = this->m_RightCorner.m_pDynamicCoverCorner.m_pPointer;
        if ( !m_pPointer
          || !UFG::DynamicCoverComponent::IsEnabled((UFG::DynamicCoverComponent *)m_pPointer->m_pParentInstance.m_pPointer) )
        {
          v17 = this->m_pParkourHandle.m_pPointer;
          if ( v17 )
          {
            m_fParkourTVal = this->m_fParkourTVal;
            Axis = UFG::ParkourHandle::GetAxis(v17, &resulta);
            v20 = m_fParkourTVal;
            v21 = m_fParkourTVal * Axis->x;
            v22 = m_fParkourTVal * Axis->z;
            v23 = v20 * Axis->y;
            ParkourSync = UFG::CoverObjectParkour::GetParkourSync(this, &v30);
            v25 = v22 + ParkourSync->z;
            v26 = v23 + ParkourSync->y;
            result->x = v21 + ParkourSync->x;
            result->y = v26;
            result->z = v25;
          }
          else
          {
            y = UFG::qVector3::msZero.y;
            z = UFG::qVector3::msZero.z;
            result->x = UFG::qVector3::msZero.x;
            result->y = y;
            result->z = z;
          }
          return result;
        }
      }
      p_m_LeftCorner = &this->m_RightCorner;
    }
    v15 = UFG::CoverCornerHandle::Get(p_m_LeftCorner);
    UFG::CoverCorner::GetSyncPos(v15, result);
    return result;
  }
  v4 = this->vfptr->GetHeight(this);
  if ( v4 <= 0.5 || v4 >= 1.6 )
    v5 = UFG::CoverObjectBase::ms_fHighFrontOffset;
  else
    v5 = UFG::CoverObjectBase::ms_fLowFrontOffset;
  m_fParkourSyncZOffset = this->m_fParkourSyncZOffset;
  v7 = result;
  v8 = UFG::qVector3::msDirUp.x * m_fParkourSyncZOffset;
  v9 = UFG::qVector3::msDirUp.z * m_fParkourSyncZOffset;
  v10 = (float)((float)(v5 * this->m_vInbetweenParkourNormal.y) + this->m_vInbetweenParkourPosition.y)
      + (float)(UFG::qVector3::msDirUp.y * m_fParkourSyncZOffset);
  v11 = (float)(v5 * this->m_vInbetweenParkourNormal.x) + this->m_vInbetweenParkourPosition.x;
  v12 = (float)(v5 * this->m_vInbetweenParkourNormal.z) + this->m_vInbetweenParkourPosition.z;
  result->y = v10;
  result->x = v11 + v8;
  result->z = v12 + v9;
  return v7;
}

// File Line: 493
// RVA: 0x33C150
bool __fastcall UFG::CoverPosition::operator==(UFG::CoverPosition *this, UFG::CoverObjectBase *other)
{
  bool result; // al
  UFG::CoverCorner *v5; // rbx
  UFG::CoverCorner *v6; // rbx

  result = other->vfptr->IsPosition(other);
  if ( result )
  {
    v5 = UFG::CoverCornerHandle::Get((UFG::CoverCornerHandle *)&other[2].m_iRefCount);
    result = UFG::CoverCornerHandle::Get(&this->m_LeftCorner) == v5
          && (v6 = UFG::CoverCornerHandle::Get((UFG::CoverCornerHandle *)&other[4].m_iRefCount),
              UFG::CoverCornerHandle::Get(&this->m_RightCorner) == v6)
          && other[1].m_pCoverObjectGroup == (UFG::CoverObjectGroup *)this->m_pParkourHandle.m_pPointer;
  }
  return result;
}

// File Line: 520
// RVA: 0x33C240
UFG::CoverPosition *__fastcall UFG::CoverPosition::operator+=(UFG::CoverPosition *this, UFG::CoverPosition *other)
{
  UFG::CoverCornerHandle *p_m_LeftCorner; // rdx
  char *v4; // rsi
  UFG::DynamicCoverCorner *m_pPointer; // rax
  UFG::CoverCorner *v7; // rax
  UFG::qResourceData *mData; // rax
  UFG::qBaseNodeRB *v9; // rcx
  char *v10; // r8
  UFG::CoverCornerHandle *p_m_RightCorner; // rdx
  UFG::DynamicCoverCorner *v12; // rax
  UFG::CoverCorner *v13; // rax
  UFG::qResourceData *v14; // rax
  UFG::qBaseNodeRB *v15; // rcx
  UFG::ParkourHandle *v16; // r8
  UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle> *p_m_pParkourHandle; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v20; // rax
  float y; // xmm0_4
  float z; // xmm1_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  float x; // eax
  float v26; // xmm1_4

  p_m_LeftCorner = &other->m_LeftCorner;
  v4 = 0i64;
  m_pPointer = p_m_LeftCorner->m_pDynamicCoverCorner.m_pPointer;
  if ( m_pPointer )
  {
    v7 = &m_pPointer->UFG::CoverCorner;
  }
  else
  {
    mData = p_m_LeftCorner->m_ResourceHandle.mData;
    if ( !mData )
      goto LABEL_10;
    v9 = mData[1].mNode.mChild[0];
    if ( v9 )
      v10 = (char *)mData[1].mNode.mChild + (_QWORD)v9;
    else
      v10 = 0i64;
    v7 = (UFG::CoverCorner *)&v10[48 * p_m_LeftCorner->m_uCoverCornerIndex];
  }
  if ( v7 )
    UFG::CoverCornerHandle::operator=(&this->m_LeftCorner, p_m_LeftCorner);
LABEL_10:
  p_m_RightCorner = &other->m_RightCorner;
  v12 = other->m_RightCorner.m_pDynamicCoverCorner.m_pPointer;
  if ( v12 )
  {
    v13 = &v12->UFG::CoverCorner;
  }
  else
  {
    v14 = other->m_RightCorner.m_ResourceHandle.mData;
    if ( !v14 )
      goto LABEL_18;
    v15 = v14[1].mNode.mChild[0];
    if ( v15 )
      v4 = (char *)v14[1].mNode.mChild + (_QWORD)v15;
    v13 = (UFG::CoverCorner *)&v4[48 * p_m_RightCorner->m_uCoverCornerIndex];
  }
  if ( v13 )
    UFG::CoverCornerHandle::operator=(&this->m_RightCorner, p_m_RightCorner);
LABEL_18:
  v16 = other->m_pParkourHandle.m_pPointer;
  if ( v16 && (!this->m_pParkourHandle.m_pPointer || this->m_fDistanceInFront > other->m_fDistanceInFront) )
  {
    p_m_pParkourHandle = &this->m_pParkourHandle;
    if ( this->m_pParkourHandle.m_pPointer )
    {
      mPrev = p_m_pParkourHandle->mPrev;
      mNext = this->m_pParkourHandle.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_m_pParkourHandle->mPrev = p_m_pParkourHandle;
      this->m_pParkourHandle.mNext = &this->m_pParkourHandle;
    }
    this->m_pParkourHandle.m_pPointer = v16;
    v20 = v16->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::ParkourHandle>::mPrev;
    v20->mNext = p_m_pParkourHandle;
    p_m_pParkourHandle->mPrev = v20;
    this->m_pParkourHandle.mNext = &v16->m_SafePointerList.mNode;
    v16->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::ParkourHandle>::mPrev = p_m_pParkourHandle;
    this->m_fParkourTVal = other->m_fParkourTVal;
    this->m_fDistanceInFront = other->m_fDistanceInFront;
    this->m_fDistToLeft = other->m_fDistToLeft;
    this->m_fDistToRight = other->m_fDistToRight;
    this->m_bFoundParkourSync = other->m_bFoundParkourSync;
    this->m_fParkourSyncZOffset = other->m_fParkourSyncZOffset;
  }
  if ( other->m_bInbetweenParkourLine )
  {
    y = other->m_vInbetweenParkourPosition.y;
    z = other->m_vInbetweenParkourPosition.z;
    this->m_vInbetweenParkourPosition.x = other->m_vInbetweenParkourPosition.x;
    this->m_vInbetweenParkourPosition.y = y;
    this->m_vInbetweenParkourPosition.z = z;
    v23 = other->m_vInbetweenParkourNormal.y;
    v24 = other->m_vInbetweenParkourNormal.z;
    this->m_vInbetweenParkourNormal.x = other->m_vInbetweenParkourNormal.x;
    this->m_vInbetweenParkourNormal.y = v23;
    this->m_vInbetweenParkourNormal.z = v24;
    x = other->m_vInbetweenParkourAxis.x;
    v26 = other->m_vInbetweenParkourAxis.z;
    this->m_vInbetweenParkourAxis.y = other->m_vInbetweenParkourAxis.y;
    this->m_vInbetweenParkourAxis.x = x;
    this->m_vInbetweenParkourAxis.z = v26;
    this->m_bInbetweenParkourLine = other->m_bInbetweenParkourLine;
    this->m_bFoundParkourSync = other->m_bFoundParkourSync;
    this->m_fParkourSyncZOffset = other->m_fParkourSyncZOffset;
  }
  return this;
}

// File Line: 568
// RVA: 0x3416E0
void __fastcall UFG::CoverPosition::AddUser(UFG::CoverPosition *this, UFG::SimObject *pUser)
{
  UFG::SimObject *v2; // rbp
  UFG::DynamicCoverCorner *m_pPointer; // rax
  UFG::qResourceData *mData; // rax
  UFG::qBaseNodeRB *v6; // rcx
  UFG::DynamicCoverCorner *v7; // rax
  UFG::qResourceData *v8; // rax
  UFG::qBaseNodeRB *v9; // rcx
  __int64 i; // rbx
  __int64 v11; // rdi
  UFG::CoverObjectBase::CoverUser *v12; // rax
  UFG::qNode<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser> *mPrev; // rcx
  __int64 v14[6]; // [rsp+28h] [rbp-30h]

  v2 = pUser;
  LOBYTE(pUser) = 1;
  this->vfptr->SetInUse(this, (bool)pUser);
  m_pPointer = this->m_LeftCorner.m_pDynamicCoverCorner.m_pPointer;
  if ( m_pPointer )
  {
    mData = (UFG::qResourceData *)&m_pPointer->UFG::CoverCorner;
  }
  else
  {
    mData = this->m_LeftCorner.m_ResourceHandle.mData;
    if ( mData )
    {
      v6 = mData[1].mNode.mChild[0];
      if ( v6 )
        v6 = (UFG::qBaseNodeRB *)((char *)v6 + (_QWORD)mData + 96);
      mData = (UFG::qResourceData *)((char *)v6 + 48 * this->m_LeftCorner.m_uCoverCornerIndex);
    }
  }
  v14[0] = (__int64)mData;
  v7 = this->m_RightCorner.m_pDynamicCoverCorner.m_pPointer;
  if ( v7 )
  {
    v8 = (UFG::qResourceData *)&v7->UFG::CoverCorner;
  }
  else
  {
    v8 = this->m_RightCorner.m_ResourceHandle.mData;
    if ( v8 )
    {
      v9 = v8[1].mNode.mChild[0];
      if ( v9 )
        v9 = (UFG::qBaseNodeRB *)((char *)v9 + (_QWORD)v8 + 96);
      v8 = (UFG::qResourceData *)((char *)v9 + 48 * this->m_RightCorner.m_uCoverCornerIndex);
    }
  }
  v14[1] = (__int64)v8;
  v14[2] = (__int64)this->m_pParkourHandle.m_pPointer;
  for ( i = 0i64; i < 3; ++i )
  {
    v11 = v14[i];
    if ( v11 )
    {
      v12 = (UFG::CoverObjectBase::CoverUser *)UFG::qMalloc(0x20ui64, "CoverUser", 0i64);
      if ( v12 )
      {
        v12->mPrev = v12;
        v12->mNext = v12;
      }
      v12->pCoverObject = (void *)v11;
      v12->pUser = v2;
      mPrev = UFG::CoverObjectBase::ms_listUsers.mNode.mPrev;
      UFG::CoverObjectBase::ms_listUsers.mNode.mPrev->mNext = v12;
      v12->mPrev = mPrev;
      v12->mNext = (UFG::qNode<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser> *)&UFG::CoverObjectBase::ms_listUsers;
      UFG::CoverObjectBase::ms_listUsers.mNode.mPrev = v12;
      this->m_aCoverUsers.p[this->m_aCoverUsers.size++] = v12;
    }
  }
}

// File Line: 597
// RVA: 0x3816A0
void __fastcall UFG::CoverPosition::RemoveUser(UFG::CoverPosition *this)
{
  UFG::CoverObjectBase::CoverUser *v2; // r8
  UFG::qNode<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser> *mPrev; // rcx
  UFG::qNode<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser> *mNext; // rax
  UFG::qNode<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser> *v5; // rdx
  UFG::qNode<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser> *v6; // rax

  if ( (*((unsigned __int8 (__fastcall **)(UFG::CoverPosition *))&this->vfptr->__vecDelDtor + 2))(this) )
    this->vfptr->GetInUse(this);
  this->vfptr->SetInUse(this, 0);
  while ( this->m_aCoverUsers.size )
  {
    v2 = this->m_aCoverUsers.p[0];
    mPrev = v2->mPrev;
    mNext = v2->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    v2->mPrev = v2;
    v2->mNext = v2;
    this->m_aCoverUsers.p[0] = this->m_aCoverUsers.p[--this->m_aCoverUsers.size];
    v5 = v2->mPrev;
    v6 = v2->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v2->mPrev = v2;
    v2->mNext = v2;
    operator delete[](v2);
  }
}

// File Line: 620
// RVA: 0x34CAB0
char __fastcall UFG::CoverPosition::CanUse(UFG::CoverPosition *this, UFG::SimObject *pUser)
{
  UFG::DynamicCoverCorner *m_pPointer; // rax
  __int64 v6; // rdi
  __int64 v7; // rax
  UFG::qResourceData *mData; // rax
  UFG::qBaseNodeRB *v9; // rcx
  char *v10; // rdx
  UFG::DynamicCoverCorner *v11; // rax
  __int64 v12; // rax
  UFG::qResourceData *v13; // rax
  UFG::qBaseNodeRB *v14; // rcx
  char *v15; // rdx
  UFG::qList<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser,1,0> *mNext; // rbx
  UFG::SimObject *v17; // rdx
  __int64 v18[5]; // [rsp+20h] [rbp-28h]

  if ( !this->vfptr->GetInUse(this) )
    return 1;
  m_pPointer = this->m_LeftCorner.m_pDynamicCoverCorner.m_pPointer;
  v6 = 0i64;
  if ( m_pPointer )
  {
    v7 = (__int64)&m_pPointer->UFG::CoverCorner;
  }
  else
  {
    mData = this->m_LeftCorner.m_ResourceHandle.mData;
    if ( mData )
    {
      v9 = mData[1].mNode.mChild[0];
      if ( v9 )
        v10 = (char *)mData[1].mNode.mChild + (_QWORD)v9;
      else
        v10 = 0i64;
      v7 = (__int64)&v10[48 * this->m_LeftCorner.m_uCoverCornerIndex];
    }
    else
    {
      v7 = 0i64;
    }
  }
  v18[0] = v7;
  v11 = this->m_RightCorner.m_pDynamicCoverCorner.m_pPointer;
  if ( v11 )
  {
    v12 = (__int64)&v11->UFG::CoverCorner;
  }
  else
  {
    v13 = this->m_RightCorner.m_ResourceHandle.mData;
    if ( v13 )
    {
      v14 = v13[1].mNode.mChild[0];
      if ( v14 )
        v15 = (char *)v13[1].mNode.mChild + (_QWORD)v14;
      else
        v15 = 0i64;
      v12 = (__int64)&v15[48 * this->m_RightCorner.m_uCoverCornerIndex];
    }
    else
    {
      v12 = 0i64;
    }
  }
  v18[1] = v12;
  v18[2] = (__int64)this->m_pParkourHandle.m_pPointer;
  while ( 1 )
  {
    if ( v18[v6] )
    {
      mNext = (UFG::qList<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser,1,0> *)UFG::CoverObjectBase::ms_listUsers.mNode.mNext;
      if ( (UFG::qList<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser,1,0> *)UFG::CoverObjectBase::ms_listUsers.mNode.mNext != &UFG::CoverObjectBase::ms_listUsers )
        break;
    }
LABEL_25:
    if ( ++v6 >= 3 )
      return 1;
  }
  while ( 1 )
  {
    v17 = (UFG::SimObject *)mNext[1].mNode.mNext;
    if ( v17 != pUser && UFG::CoverPosition::IsUserTooClose(this, v17) )
      return 0;
    mNext = (UFG::qList<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser,1,0> *)mNext->mNode.mNext;
    if ( mNext == &UFG::CoverObjectBase::ms_listUsers )
      goto LABEL_25;
  }
}

// File Line: 656
// RVA: 0x36BD60
bool __fastcall UFG::CoverPosition::IsUserTooClose(UFG::CoverPosition *this, UFG::SimObjectGame *pUser)
{
  UFG::SimObjectGame *v2; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax
  signed __int16 m_Flags; // cx
  __int64 v6; // rbx
  float *v7; // rbx
  UFG::qVector3 *v8; // rax
  float v9; // xmm1_4
  float v10; // xmm0_4
  bool result; // al
  char v12[12]; // [rsp+28h] [rbp-20h] BYREF
  char v13[20]; // [rsp+34h] [rbp-14h] BYREF

  v2 = pUser;
  if ( pUser )
  {
    m_Flags = pUser->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(pUser, UFG::AICoverComponent::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(pUser, UFG::AICoverComponent::_TypeUID);
  }
  else
  {
    ComponentOfTypeHK = 0i64;
  }
  v6 = *(_QWORD *)&ComponentOfTypeHK[1].m_Flags;
  result = 0;
  if ( v6
    && (*(unsigned __int8 (__fastcall **)(__int64, UFG::SimObjectGame *, UFG::SimObjectGame *))(*(_QWORD *)v6 + 16i64))(
         v6,
         pUser,
         v2) )
  {
    v7 = (float *)(*(__int64 (__fastcall **)(__int64, char *))(*(_QWORD *)v6 + 120i64))(v6, v12);
    v8 = this->vfptr->GetSyncPos(this, v13);
    v9 = (float)((float)(v8->x - *v7) * (float)(v8->x - *v7)) + (float)((float)(v8->y - v7[1]) * (float)(v8->y - v7[1]));
    if ( (_S63 & 1) != 0 )
    {
      v10 = fMinDist2;
    }
    else
    {
      _S63 |= 1u;
      v10 = FLOAT_0_64000005;
      fMinDist2 = FLOAT_0_64000005;
    }
    if ( v9 < v10 )
      return 1;
  }
  return result;
}

// File Line: 680
// RVA: 0x360110
bool __fastcall UFG::CoverPosition::GetInUse(UFG::CoverPosition *this)
{
  UFG::CoverCorner *v1; // rdi
  UFG::DynamicCoverCorner *v3; // rcx
  UFG::DynamicCoverCorner *m_pPointer; // rax
  UFG::CoverCorner *v5; // rax
  UFG::qResourceData *mData; // rax
  UFG::qBaseNodeRB *v7; // rcx
  __int64 v8; // rdx
  UFG::DynamicCoverCorner *v10; // rcx
  UFG::DynamicCoverCorner *v11; // rax
  UFG::qResourceData *v12; // rax
  UFG::qBaseNodeRB *v13; // rcx
  char *v14; // rcx
  UFG::ParkourHandle *v15; // rax

  v1 = 0i64;
  if ( this->m_LeftCorner.m_ResourceHandle.mData && this->m_LeftCorner.m_uCoverCornerIndex != 0xFFFF
    || (v3 = this->m_LeftCorner.m_pDynamicCoverCorner.m_pPointer) != 0i64
    && UFG::DynamicCoverComponent::IsEnabled((UFG::DynamicCoverComponent *)v3->m_pParentInstance.m_pPointer) )
  {
    m_pPointer = this->m_LeftCorner.m_pDynamicCoverCorner.m_pPointer;
    if ( m_pPointer )
    {
      v5 = &m_pPointer->UFG::CoverCorner;
    }
    else
    {
      mData = this->m_LeftCorner.m_ResourceHandle.mData;
      if ( mData )
      {
        v7 = mData[1].mNode.mChild[0];
        v8 = v7 ? (__int64)mData[1].mNode.mChild + (_QWORD)v7 : 0i64;
        v5 = (UFG::CoverCorner *)(v8 + 48i64 * this->m_LeftCorner.m_uCoverCornerIndex);
      }
      else
      {
        v5 = 0i64;
      }
    }
    if ( v5->m_IsInUse )
      return 1;
  }
  if ( this->m_RightCorner.m_ResourceHandle.mData && this->m_RightCorner.m_uCoverCornerIndex != 0xFFFF
    || (v10 = this->m_RightCorner.m_pDynamicCoverCorner.m_pPointer) != 0i64
    && UFG::DynamicCoverComponent::IsEnabled((UFG::DynamicCoverComponent *)v10->m_pParentInstance.m_pPointer) )
  {
    v11 = this->m_RightCorner.m_pDynamicCoverCorner.m_pPointer;
    if ( v11 )
    {
      v1 = &v11->UFG::CoverCorner;
    }
    else
    {
      v12 = this->m_RightCorner.m_ResourceHandle.mData;
      if ( v12 )
      {
        v13 = v12[1].mNode.mChild[0];
        if ( v13 )
          v14 = (char *)&v13[3] + (_QWORD)v12;
        else
          v14 = 0i64;
        v1 = (UFG::CoverCorner *)&v14[48 * this->m_RightCorner.m_uCoverCornerIndex];
      }
    }
    if ( v1->m_IsInUse )
      return 1;
  }
  v15 = this->m_pParkourHandle.m_pPointer;
  return v15 && (*((_BYTE *)v15 + 152) & 0x1C) != 0;
}

// File Line: 709
// RVA: 0x3868B0
void __fastcall UFG::CoverPosition::SetInUse(UFG::CoverPosition *this, char bInUse)
{
  UFG::CoverCorner *v2; // rdi
  const char *v5; // r14
  UFG::DynamicCoverCorner *v6; // rcx
  UFG::DynamicCoverCorner *m_pPointer; // rsi
  UFG::CoverCorner *v8; // rsi
  UFG::qResourceData *mData; // rax
  UFG::qBaseNodeRB *v10; // rcx
  char *v11; // rdx
  const char *v12; // rdx
  UFG::DynamicCoverCorner *v13; // rcx
  UFG::DynamicCoverCorner *v14; // rax
  UFG::qResourceData *v15; // rax
  UFG::qBaseNodeRB *v16; // rcx
  char *v17; // rcx
  UFG::ParkourHandle *v18; // rdx

  v2 = 0i64;
  v5 = "false";
  if ( this->m_LeftCorner.m_ResourceHandle.mData && this->m_LeftCorner.m_uCoverCornerIndex != 0xFFFF
    || (v6 = this->m_LeftCorner.m_pDynamicCoverCorner.m_pPointer) != 0i64
    && UFG::DynamicCoverComponent::IsEnabled((UFG::DynamicCoverComponent *)v6->m_pParentInstance.m_pPointer) )
  {
    m_pPointer = this->m_LeftCorner.m_pDynamicCoverCorner.m_pPointer;
    if ( m_pPointer )
    {
      v8 = &m_pPointer->UFG::CoverCorner;
    }
    else
    {
      mData = this->m_LeftCorner.m_ResourceHandle.mData;
      if ( mData )
      {
        v10 = mData[1].mNode.mChild[0];
        if ( v10 )
          v11 = (char *)mData[1].mNode.mChild + (_QWORD)v10;
        else
          v11 = 0i64;
        v8 = (UFG::CoverCorner *)&v11[48 * this->m_LeftCorner.m_uCoverCornerIndex];
      }
      else
      {
        v8 = 0i64;
      }
    }
    if ( bInUse == (v8->m_IsInUse != 0) )
    {
      v12 = "false";
      if ( bInUse )
        v12 = "true";
      UFG::qPrintf("CoverPosition::SetInUse() invalid call.  bInUse = %s\n", v12);
    }
    v8->m_IsInUse = bInUse;
  }
  if ( this->m_RightCorner.m_ResourceHandle.mData && this->m_RightCorner.m_uCoverCornerIndex != 0xFFFF
    || (v13 = this->m_RightCorner.m_pDynamicCoverCorner.m_pPointer) != 0i64
    && UFG::DynamicCoverComponent::IsEnabled((UFG::DynamicCoverComponent *)v13->m_pParentInstance.m_pPointer) )
  {
    v14 = this->m_RightCorner.m_pDynamicCoverCorner.m_pPointer;
    if ( v14 )
    {
      v2 = &v14->UFG::CoverCorner;
    }
    else
    {
      v15 = this->m_RightCorner.m_ResourceHandle.mData;
      if ( v15 )
      {
        v16 = v15[1].mNode.mChild[0];
        if ( v16 )
          v17 = (char *)&v16[3] + (_QWORD)v15;
        else
          v17 = 0i64;
        v2 = (UFG::CoverCorner *)&v17[48 * this->m_RightCorner.m_uCoverCornerIndex];
      }
    }
    if ( bInUse == (v2->m_IsInUse != 0) )
    {
      if ( bInUse )
        v5 = "true";
      UFG::qPrintf("CoverPosition::SetInUse() invalid call.  bInUse = %s\n", v5);
    }
    v2->m_IsInUse = bInUse;
  }
  v18 = this->m_pParkourHandle.m_pPointer;
  if ( v18 )
  {
    if ( bInUse )
      *((_DWORD *)v18 + 38) ^= ((unsigned __int8)*((_DWORD *)v18 + 38) ^ (unsigned __int8)((*((_DWORD *)v18 + 38) & 0xFC)
                                                                                         + 4)) & 0x1C;
    else
      *((_DWORD *)v18 + 38) ^= ((unsigned __int8)*((_DWORD *)v18 + 38) ^ (unsigned __int8)(4
                                                                                         * (*((_DWORD *)v18 + 38) >> 2)
                                                                                         - 4)) & 0x1C;
  }
}

// File Line: 744
// RVA: 0x35FF30
float __fastcall UFG::CoverPosition::GetHeight(UFG::CoverPosition *this)
{
  float m_fWallHeight; // xmm6_4
  UFG::CoverCorner *v3; // rax
  UFG::CoverCorner *v4; // rax
  float result; // xmm0_4

  m_fWallHeight = FLOAT_3_4028235e38;
  v3 = UFG::CoverCornerHandle::Get(&this->m_LeftCorner);
  if ( v3 && v3->m_fWallHeight <= 3.4028235e38 )
    m_fWallHeight = v3->m_fWallHeight;
  v4 = UFG::CoverCornerHandle::Get(&this->m_RightCorner);
  if ( v4 && m_fWallHeight >= v4->m_fWallHeight )
    m_fWallHeight = v4->m_fWallHeight;
  if ( this->m_pParkourHandle.m_pPointer
    && m_fWallHeight >= COERCE_FLOAT(LODWORD(this->m_fParkourSyncZOffset) ^ _xmm[0]) )
  {
    LODWORD(m_fWallHeight) = LODWORD(this->m_fParkourSyncZOffset) ^ _xmm[0];
  }
  if ( !this->m_bInbetweenParkourLine )
    return m_fWallHeight;
  LODWORD(result) = LODWORD(this->m_fParkourSyncZOffset) ^ _xmm[0];
  if ( m_fWallHeight < result )
    return m_fWallHeight;
  return result;
}

// File Line: 777
// RVA: 0x369AE0
char __fastcall UFG::CoverPosition::IsAnyLineOrCornerShared(UFG::CoverPosition *this, UFG::CoverObjectBase *pOther)
{
  UFG::CoverObjectBase *v2; // r14
  unsigned int v5; // r15d
  unsigned __int64 v6; // rax
  UFG::allocator::free_link *v7; // r13
  unsigned int v8; // ebx
  unsigned __int64 v9; // rax
  UFG::allocator::free_link *v10; // rdi
  UFG::DynamicCoverCorner *m_pPointer; // rcx
  UFG::allocator::free_link *v12; // rcx
  UFG::qResourceData *mData; // rax
  UFG::qBaseNodeRB *v14; // rcx
  char *v15; // rdx
  UFG::DynamicCoverCorner *v16; // r12
  UFG::CoverCorner *v17; // r12
  UFG::qResourceData *v18; // rax
  UFG::qBaseNodeRB *v19; // rdx
  unsigned int v20; // esi
  unsigned int v21; // ecx
  unsigned int v22; // r13d
  unsigned int v23; // r14d
  unsigned __int64 v24; // rax
  UFG::allocator::free_link *v25; // rax
  UFG::allocator::free_link *v26; // rcx
  __int64 v27; // rdx
  UFG::CoverCorner *v28; // rax
  UFG::allocator::free_link *mNext; // rdx
  __int64 v30; // r8
  UFG::CoverCorner *v31; // r12
  UFG::CoverCorner *v32; // rax
  __int64 v33; // rax
  unsigned int v34; // r14d
  unsigned __int64 v35; // rax
  UFG::allocator::free_link *v36; // rax
  UFG::allocator::free_link *v37; // r12
  UFG::allocator::free_link *v38; // rcx
  __int64 v39; // rdx
  int v40; // eax
  UFG::ParkourHandle *v41; // rax
  char v42; // bl
  UFG::allocator::free_link *mem; // [rsp+30h] [rbp-28h]
  UFG::allocator::free_link *v46; // [rsp+B8h] [rbp+60h]
  UFG::allocator::free_link *v47; // [rsp+B8h] [rbp+60h]

  v2 = pOther;
  if ( !pOther )
    return 0;
  v5 = 0;
  v6 = 16i64;
  if ( !is_mul_ok(2ui64, 8ui64) )
    v6 = -1i64;
  v7 = UFG::qMalloc(v6, "qArray.Reallocate(Constructor)", 0i64);
  mem = v7;
  v8 = 0;
  v9 = 16i64;
  if ( !is_mul_ok(2ui64, 8ui64) )
    v9 = -1i64;
  v10 = UFG::qMalloc(v9, "qArray.Reallocate(Constructor)", 0i64);
  m_pPointer = this->m_LeftCorner.m_pDynamicCoverCorner.m_pPointer;
  if ( m_pPointer )
  {
    v12 = (UFG::allocator::free_link *)&m_pPointer->UFG::CoverCorner;
  }
  else
  {
    mData = this->m_LeftCorner.m_ResourceHandle.mData;
    if ( mData )
    {
      v14 = mData[1].mNode.mChild[0];
      if ( v14 )
        v15 = (char *)mData[1].mNode.mChild + (_QWORD)v14;
      else
        v15 = 0i64;
      v12 = (UFG::allocator::free_link *)&v15[48 * this->m_LeftCorner.m_uCoverCornerIndex];
    }
    else
    {
      v12 = 0i64;
    }
  }
  v16 = this->m_RightCorner.m_pDynamicCoverCorner.m_pPointer;
  if ( v16 )
  {
    v17 = &v16->UFG::CoverCorner;
  }
  else
  {
    v18 = this->m_RightCorner.m_ResourceHandle.mData;
    if ( v18 )
    {
      v19 = v18[1].mNode.mChild[0];
      if ( v19 )
        v19 = (UFG::qBaseNodeRB *)((char *)v19 + (_QWORD)v18 + 96);
      v17 = (UFG::CoverCorner *)((char *)v19 + 48 * this->m_RightCorner.m_uCoverCornerIndex);
    }
    else
    {
      v17 = 0i64;
    }
  }
  if ( v12 )
  {
    v5 = 1;
    v7->mNext = v12;
  }
  v20 = 4;
  if ( v17 )
  {
    v21 = v5;
    v22 = v5 + 1;
    if ( v5 + 1 > 2 )
    {
      v23 = 4;
      if ( v22 > 4 )
      {
        do
          v23 *= 2;
        while ( v23 < v22 );
        if ( v23 <= 2 )
          v23 = 2;
      }
      if ( v23 - v22 > 0x10000 )
        v23 = v5 + 65537;
      if ( v23 != v5 )
      {
        v24 = 8i64 * v23;
        if ( !is_mul_ok(v23, 8ui64) )
          v24 = -1i64;
        v25 = UFG::qMalloc(v24, "qArray.Add", 0i64);
        v46 = v25;
        if ( mem )
        {
          if ( v5 )
          {
            v26 = v25;
            v27 = v5;
            do
            {
              v26->mNext = *(UFG::allocator::free_link **)((char *)v26 + (char *)mem - (char *)v25);
              ++v26;
              --v27;
            }
            while ( v27 );
          }
          operator delete[](mem);
          v25 = v46;
        }
        mem = v25;
        v21 = v5;
      }
      v2 = pOther;
    }
    ++v5;
    v7 = mem;
    mem[v21].mNext = (UFG::allocator::free_link *)v17;
  }
  if ( v2->vfptr->IsCorner(v2) )
  {
    v28 = UFG::CoverCornerHandle::Get((UFG::CoverCornerHandle *)&v2[1]);
    if ( v28 )
    {
      v8 = 1;
      v10->mNext = (UFG::allocator::free_link *)v28;
    }
  }
  else if ( v2->vfptr->IsPosition(v2) )
  {
    v31 = UFG::CoverCornerHandle::Get((UFG::CoverCornerHandle *)&v2[2].m_iRefCount);
    v32 = UFG::CoverCornerHandle::Get((UFG::CoverCornerHandle *)&v2[4].m_iRefCount);
    v47 = (UFG::allocator::free_link *)v32;
    if ( v31 )
    {
      v8 = 1;
      v10->mNext = (UFG::allocator::free_link *)v31;
    }
    if ( v32 )
    {
      v33 = v8;
      v34 = v8 + 1;
      if ( v8 + 1 > 2 )
      {
        if ( v34 > 4 )
        {
          do
            v20 *= 2;
          while ( v20 < v34 );
          if ( v20 <= 2 )
            v20 = 2;
        }
        if ( v20 - v34 > 0x10000 )
          v20 = v8 + 65537;
        if ( v20 != v8 )
        {
          v35 = 8i64 * v20;
          if ( !is_mul_ok(v20, 8ui64) )
            v35 = -1i64;
          v36 = UFG::qMalloc(v35, "qArray.Add", 0i64);
          v37 = v36;
          if ( v10 )
          {
            if ( v8 )
            {
              v38 = v36;
              v39 = v8;
              do
              {
                v38->mNext = *(UFG::allocator::free_link **)((char *)v38 + (char *)v10 - (char *)v36);
                ++v38;
                --v39;
              }
              while ( v39 );
            }
            operator delete[](v10);
          }
          v10 = v37;
          v33 = v8;
        }
      }
      ++v8;
      v10[v33].mNext = v47;
      v2 = pOther;
    }
  }
  if ( v5 && v8 )
  {
    LODWORD(v30) = 0;
LABEL_70:
    v40 = 0;
    mNext = v7[(unsigned int)v30].mNext;
    while ( mNext != v10[v40].mNext )
    {
      if ( ++v40 >= v8 )
      {
        v30 = (unsigned int)(v30 + 1);
        if ( (unsigned int)v30 < v5 )
          goto LABEL_70;
        goto LABEL_75;
      }
    }
  }
  else
  {
LABEL_75:
    if ( !((unsigned __int8 (__fastcall *)(UFG::CoverObjectBase *, UFG::allocator::free_link *, __int64))v2->vfptr->IsParkour)(
            v2,
            mNext,
            v30)
      || (v41 = this->m_pParkourHandle.m_pPointer) == 0i64
      || v41 != (UFG::ParkourHandle *)v2[1].m_pCoverObjectGroup )
    {
      v42 = 0;
      goto LABEL_80;
    }
  }
  v42 = 1;
LABEL_80:
  if ( v10 )
    operator delete[](v10);
  if ( v7 )
    operator delete[](v7);
  return v42;
}

