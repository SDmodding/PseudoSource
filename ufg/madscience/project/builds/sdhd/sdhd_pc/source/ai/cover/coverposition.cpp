// File Line: 63
// RVA: 0x32D950
void __fastcall UFG::CoverPosition::CoverPosition(UFG::CoverPosition *this)
{
  UFG::CoverPosition *v1; // rbx
  float v2; // xmm1_4
  float v3; // xmm2_4
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle> *v10; // [rsp+48h] [rbp+10h]

  v1 = this;
  this->vfptr = (UFG::CoverObjectBaseVtbl *)&UFG::CoverObjectBase::`vftable';
  this->m_iRefCount = 0;
  this->m_pCoverObjectGroup = 0i64;
  this->m_fPriority = 0.0;
  this->vfptr = (UFG::CoverObjectBaseVtbl *)&UFG::CoverObjectParkour::`vftable';
  v10 = &this->m_pParkourHandle;
  v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v10->mPrev;
  v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v10->mPrev;
  this->m_pParkourHandle.m_pPointer = 0i64;
  this->m_bFoundParkourSync = 0;
  this->m_pCoverUser = 0i64;
  this->vfptr = (UFG::CoverObjectBaseVtbl *)&UFG::CoverPosition::`vftable';
  UFG::CoverCornerHandle::CoverCornerHandle(&this->m_LeftCorner);
  UFG::CoverCornerHandle::CoverCornerHandle(&v1->m_RightCorner);
  *(_QWORD *)&v1->m_fDistToLeft = 0i64;
  v2 = UFG::qVector3::msAxisZ.y;
  v3 = UFG::qVector3::msAxisZ.z;
  v1->m_vInbetweenParkourPosition.x = UFG::qVector3::msAxisZ.x;
  v1->m_vInbetweenParkourPosition.y = v2;
  v1->m_vInbetweenParkourPosition.z = v3;
  v4 = UFG::qVector3::msAxisX.y;
  v5 = UFG::qVector3::msAxisX.z;
  v1->m_vInbetweenParkourNormal.x = UFG::qVector3::msAxisX.x;
  v1->m_vInbetweenParkourNormal.y = v4;
  v1->m_vInbetweenParkourNormal.z = v5;
  v6 = UFG::qVector3::msAxisY.y;
  v7 = UFG::qVector3::msAxisY.z;
  v1->m_vInbetweenParkourAxis.x = UFG::qVector3::msAxisY.x;
  v1->m_vInbetweenParkourAxis.y = v6;
  v1->m_vInbetweenParkourAxis.z = v7;
  v1->m_bInbetweenParkourLine = 0;
  v1->m_NavPosition.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::NavPositionBase::`vftable';
  v8 = UFG::qVector3::msZero.y;
  v9 = UFG::qVector3::msZero.z;
  v1->m_NavPosition.m_vPosition.x = UFG::qVector3::msZero.x;
  v1->m_NavPosition.m_vPosition.y = v8;
  v1->m_NavPosition.m_vPosition.z = v9;
  v1->m_NavPosition.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable';
  v1->m_NavPosition.m_bValid = 0;
  v1->m_NavPosition.m_hkvMeshPosition = (hkVector4f)hkvZero_13.m_quad;
  *(_QWORD *)&v1->m_NavPosition.m_packedKey = -1i64;
  v1->m_bfFiringPositionClear.mBits[0] = 0i64;
  v1->m_aCoverUsers.size = 0;
}

// File Line: 77
// RVA: 0x32D620
void __fastcall UFG::CoverPosition::CoverPosition(UFG::CoverPosition *this, UFG::CoverCorner *pCorner)
{
  UFG::CoverCorner *v2; // rdi
  UFG::CoverPosition *v3; // rbx
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  UFG::CoverCornerHandle *v12; // rcx
  UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle> *v13; // [rsp+58h] [rbp+10h]

  v2 = pCorner;
  v3 = this;
  this->vfptr = (UFG::CoverObjectBaseVtbl *)&UFG::CoverObjectBase::`vftable';
  this->m_iRefCount = 0;
  this->m_pCoverObjectGroup = 0i64;
  this->m_fPriority = 0.0;
  this->vfptr = (UFG::CoverObjectBaseVtbl *)&UFG::CoverObjectParkour::`vftable';
  v13 = &this->m_pParkourHandle;
  v13->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v13->mPrev;
  v13->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v13->mPrev;
  this->m_pParkourHandle.m_pPointer = 0i64;
  this->m_bFoundParkourSync = 0;
  this->m_pCoverUser = 0i64;
  this->vfptr = (UFG::CoverObjectBaseVtbl *)&UFG::CoverPosition::`vftable';
  UFG::CoverCornerHandle::CoverCornerHandle(&this->m_LeftCorner);
  UFG::CoverCornerHandle::CoverCornerHandle(&v3->m_RightCorner);
  *(_QWORD *)&v3->m_fDistToLeft = 0i64;
  v4 = UFG::qVector3::msAxisZ.y;
  v5 = UFG::qVector3::msAxisZ.z;
  v3->m_vInbetweenParkourPosition.x = UFG::qVector3::msAxisZ.x;
  v3->m_vInbetweenParkourPosition.y = v4;
  v3->m_vInbetweenParkourPosition.z = v5;
  v6 = UFG::qVector3::msAxisX.y;
  v7 = UFG::qVector3::msAxisX.z;
  v3->m_vInbetweenParkourNormal.x = UFG::qVector3::msAxisX.x;
  v3->m_vInbetweenParkourNormal.y = v6;
  v3->m_vInbetweenParkourNormal.z = v7;
  v8 = UFG::qVector3::msAxisY.y;
  v9 = UFG::qVector3::msAxisY.z;
  v3->m_vInbetweenParkourAxis.x = UFG::qVector3::msAxisY.x;
  v3->m_vInbetweenParkourAxis.y = v8;
  v3->m_vInbetweenParkourAxis.z = v9;
  v3->m_bInbetweenParkourLine = 0;
  v3->m_NavPosition.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::NavPositionBase::`vftable';
  v10 = UFG::qVector3::msZero.y;
  v11 = UFG::qVector3::msZero.z;
  v3->m_NavPosition.m_vPosition.x = UFG::qVector3::msZero.x;
  v3->m_NavPosition.m_vPosition.y = v10;
  v3->m_NavPosition.m_vPosition.z = v11;
  v3->m_NavPosition.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable';
  v3->m_NavPosition.m_bValid = 0;
  v3->m_NavPosition.m_hkvMeshPosition = (hkVector4f)hkvZero_13.m_quad;
  *(_QWORD *)&v3->m_NavPosition.m_packedKey = -1i64;
  v3->m_bfFiringPositionClear.mBits[0] = 0i64;
  v3->m_aCoverUsers.size = 0;
  v12 = &v3->m_RightCorner;
  if ( v2->m_eCoverSide.mValue != 1 )
    v12 = &v3->m_LeftCorner;
  UFG::CoverCornerHandle::operator=(v12, v2);
}

// File Line: 93
// RVA: 0x32D7F0
void __fastcall UFG::CoverPosition::CoverPosition(UFG::CoverPosition *this, UFG::ParkourHandle *pParkourHandle)
{
  UFG::CoverPosition *v2; // rbx
  float v3; // xmm1_4
  float v4; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm2_4

  v2 = this;
  UFG::CoverObjectParkour::CoverObjectParkour((UFG::CoverObjectParkour *)&this->vfptr, pParkourHandle);
  v2->vfptr = (UFG::CoverObjectBaseVtbl *)&UFG::CoverPosition::`vftable';
  UFG::CoverCornerHandle::CoverCornerHandle(&v2->m_LeftCorner);
  UFG::CoverCornerHandle::CoverCornerHandle(&v2->m_RightCorner);
  *(_QWORD *)&v2->m_fDistToLeft = 0i64;
  v3 = UFG::qVector3::msAxisZ.y;
  v4 = UFG::qVector3::msAxisZ.z;
  v2->m_vInbetweenParkourPosition.x = UFG::qVector3::msAxisZ.x;
  v2->m_vInbetweenParkourPosition.y = v3;
  v2->m_vInbetweenParkourPosition.z = v4;
  v5 = UFG::qVector3::msAxisX.y;
  v6 = UFG::qVector3::msAxisX.z;
  v2->m_vInbetweenParkourNormal.x = UFG::qVector3::msAxisX.x;
  v2->m_vInbetweenParkourNormal.y = v5;
  v2->m_vInbetweenParkourNormal.z = v6;
  v7 = UFG::qVector3::msAxisY.y;
  v8 = UFG::qVector3::msAxisY.z;
  v2->m_vInbetweenParkourAxis.x = UFG::qVector3::msAxisY.x;
  v2->m_vInbetweenParkourAxis.y = v7;
  v2->m_vInbetweenParkourAxis.z = v8;
  v2->m_bInbetweenParkourLine = 0;
  v2->m_NavPosition.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::NavPositionBase::`vftable';
  v9 = UFG::qVector3::msZero.y;
  v10 = UFG::qVector3::msZero.z;
  v2->m_NavPosition.m_vPosition.x = UFG::qVector3::msZero.x;
  v2->m_NavPosition.m_vPosition.y = v9;
  v2->m_NavPosition.m_vPosition.z = v10;
  v2->m_NavPosition.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable';
  v2->m_NavPosition.m_bValid = 0;
  v2->m_NavPosition.m_hkvMeshPosition = (hkVector4f)hkvZero_13.m_quad;
  *(_QWORD *)&v2->m_NavPosition.m_packedKey = -1i64;
  v2->m_bfFiringPositionClear.mBits[0] = 0i64;
  v2->m_aCoverUsers.size = 0;
}

// File Line: 124
// RVA: 0x35C4D0
UFG::CoverPosition *__fastcall UFG::CoverPosition::GetCoverPosition(UFG::CoverPosition *this, UFG::qVector3 *vCharPos, UFG::CoverPosition *pCurrentPosition, float fRange)
{
  UFG::CoverPosition *v4; // rbx
  UFG::qVector3 *v5; // rbp
  UFG::CoverPosition *v6; // rdi
  UFG::DynamicCoverCorner *v7; // rsi
  UFG::CoverCorner *v8; // rsi
  UFG::qResourceData *v9; // rax
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
  __m128 v24; // xmm3
  __m128 v25; // xmm1
  float v26; // xmm2_4
  float v27; // xmm6_4
  UFG::ParkourHandle *v28; // r8
  UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle> *v29; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v30; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v31; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v32; // rax
  UFG::allocator::free_link *v33; // rax
  UFG::CoverPosition *v34; // rax
  float v35; // xmm6_4
  float v36; // xmm6_4
  float v37; // xmm0_4
  UFG::qVector3 out; // [rsp+28h] [rbp-80h]
  UFG::qVector3 result; // [rsp+38h] [rbp-70h]
  UFG::qVector3 p0; // [rsp+48h] [rbp-60h]
  UFG::qVector3 p1; // [rsp+54h] [rbp-54h]

  v4 = pCurrentPosition;
  v5 = vCharPos;
  v6 = this;
  if ( !(_S62 & 1) )
  {
    _S62 |= 1u;
    kfRangeSquared_0 = FLOAT_0_25;
  }
  v7 = this->m_LeftCorner.m_pDynamicCoverCorner.m_pPointer;
  if ( v7 )
  {
    v8 = (UFG::CoverCorner *)&v7->mPrev;
  }
  else
  {
    v9 = this->m_LeftCorner.m_ResourceHandle.mData;
    if ( !v9 )
      goto LABEL_17;
    v10 = v9[1].mNode.mChild[0];
    if ( v10 )
      v10 = (UFG::qBaseNodeRB *)((char *)v10 + (_QWORD)v9 + 96);
    v8 = (UFG::CoverCorner *)((char *)v10 + 48 * v6->m_LeftCorner.m_uCoverCornerIndex);
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
  v13 = v6->m_RightCorner.m_pDynamicCoverCorner.m_pPointer;
  if ( v13 )
  {
    v14 = (UFG::CoverCorner *)&v13->mPrev;
  }
  else
  {
    v15 = v6->m_RightCorner.m_ResourceHandle.mData;
    if ( !v15 )
      goto LABEL_31;
    v16 = v15[1].mNode.mChild[0];
    if ( v16 )
      v16 = (UFG::qBaseNodeRB *)((char *)v16 + (_QWORD)v15 + 96);
    v14 = (UFG::CoverCorner *)((char *)v16 + 48 * v6->m_RightCorner.m_uCoverCornerIndex);
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
  v19 = v6->m_pParkourHandle.m_pPointer;
  if ( v19 )
  {
    UFG::ParkourHandle::GetPosition(v19, &result);
    UFG::ParkourHandle::GetEndpoints(v6->m_pParkourHandle.m_pPointer, &p0, &p1);
    v20 = v5->z - p0.z;
    v21 = v5->y - p0.y;
    v22 = v5->x - p0.x;
    if ( UFG::ParkourHandle::GetNormal(v6->m_pParkourHandle.m_pPointer, &out) )
    {
      v23 = (float)((float)(out.x * v22) + (float)(out.y * v21)) + (float)(out.z * v20);
      v24 = (__m128)LODWORD(p1.x);
      v24.m128_f32[0] = p1.x - p0.x;
      v25 = v24;
      v25.m128_f32[0] = (float)(v24.m128_f32[0] * v24.m128_f32[0])
                      + (float)((float)(p1.y - p0.y) * (float)(p1.y - p0.y));
      v26 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v25));
      v27 = (float)(v22 * (float)((float)(p1.x - p0.x) * v26)) + (float)((float)((float)(p1.y - p0.y) * v26) * v21);
      if ( v4 )
      {
        v28 = v6->m_pParkourHandle.m_pPointer;
        v29 = &v4->m_pParkourHandle;
        if ( v4->m_pParkourHandle.m_pPointer )
        {
          v30 = v29->mPrev;
          v31 = v4->m_pParkourHandle.mNext;
          v30->mNext = v31;
          v31->mPrev = v30;
          v29->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v29->mPrev;
          v4->m_pParkourHandle.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v4->m_pParkourHandle.mPrev;
        }
        v4->m_pParkourHandle.m_pPointer = v28;
        if ( v28 )
        {
          v32 = v28->m_SafePointerList.mNode.mPrev;
          v32->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v29->mPrev;
          v29->mPrev = v32;
          v4->m_pParkourHandle.mNext = &v28->m_SafePointerList.mNode;
          v28->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v29->mPrev;
        }
      }
      else
      {
        v33 = UFG::qMalloc(0x170ui64, "CoverPosition", 0i64);
        if ( v33 )
        {
          UFG::CoverPosition::CoverPosition((UFG::CoverPosition *)v33, v6->m_pParkourHandle.m_pPointer);
          v4 = v34;
        }
        else
        {
          v4 = 0i64;
        }
      }
      v35 = v27 - UFG::ParkourHandle::GetHalfLength(v6->m_pParkourHandle.m_pPointer);
      v4->m_bFoundParkourSync = v6->m_bFoundParkourSync;
      v4->m_fParkourSyncZOffset = v6->m_fParkourSyncZOffset;
      v4->m_fParkourTVal = v35;
      v4->m_fDistanceInFront = v23;
      v36 = v35 - v6->m_fParkourTVal;
      v37 = v6->m_fDistToRight - v36;
      v4->m_fDistToLeft = v36 + v6->m_fDistToLeft;
      v4->m_fDistToRight = v37;
    }
  }
  return v4;
}

// File Line: 211
// RVA: 0x36C050
bool __fastcall UFG::CoverPosition::IsValid(UFG::CoverPosition *this)
{
  UFG::CoverPosition *v1; // rbx
  signed __int64 v2; // rsi
  UFG::DynamicCoverCorner *v3; // rcx
  signed __int64 v4; // rax
  signed __int64 v5; // rcx
  UFG::qVector3 *v6; // rax
  UFG::DynamicCoverCorner *v7; // rcx
  signed __int64 v8; // rax
  UFG::qVector3 *v9; // rax
  bool result; // al

  v1 = this;
  if ( UFG::CoverObjectParkour::IsValid((UFG::CoverObjectParkour *)&this->vfptr) || v1->m_bInbetweenParkourLine )
    return 1;
  v2 = 0i64;
  if ( v1->m_LeftCorner.m_ResourceHandle.mData && v1->m_LeftCorner.m_uCoverCornerIndex != -1
    || (v3 = v1->m_LeftCorner.m_pDynamicCoverCorner.m_pPointer) != 0i64
    && UFG::DynamicCoverComponent::IsEnabled((UFG::DynamicCoverComponent *)v3->m_pParentInstance.m_pPointer) )
  {
    if ( !v1->m_LeftCorner.m_pDynamicCoverCorner.m_pPointer )
      goto LABEL_25;
    v4 = UFG::CoverCornerHandle::Get(&v1->m_LeftCorner);
    v5 = v4 - 24;
    if ( !v4 )
      v5 = 0i64;
    v6 = UFG::DynamicCoverComponent::GetVelocity(*(UFG::DynamicCoverComponent **)(v5 + 88));
    if ( (float)((float)(v6->x * v6->x) + (float)(v6->y * v6->y)) < (float)(UFG::CoverObjectBase::ms_fMaxCoverVelocity
                                                                          * UFG::CoverObjectBase::ms_fMaxCoverVelocity) )
      goto LABEL_25;
  }
  if ( !v1->m_RightCorner.m_ResourceHandle.mData || v1->m_RightCorner.m_uCoverCornerIndex == -1 )
  {
    v7 = v1->m_RightCorner.m_pDynamicCoverCorner.m_pPointer;
    if ( !v7 || !UFG::DynamicCoverComponent::IsEnabled((UFG::DynamicCoverComponent *)v7->m_pParentInstance.m_pPointer) )
      goto LABEL_26;
  }
  if ( !v1->m_RightCorner.m_pDynamicCoverCorner.m_pPointer )
    goto LABEL_25;
  v8 = UFG::CoverCornerHandle::Get(&v1->m_RightCorner);
  if ( v8 )
    v2 = v8 - 24;
  v9 = UFG::DynamicCoverComponent::GetVelocity(*(UFG::DynamicCoverComponent **)(v2 + 88));
  if ( (float)((float)(v9->y * v9->y) + (float)(v9->x * v9->x)) < (float)(UFG::CoverObjectBase::ms_fMaxCoverVelocity
                                                                        * UFG::CoverObjectBase::ms_fMaxCoverVelocity) )
LABEL_25:
    result = 1;
  else
LABEL_26:
    result = 0;
  return result;
}

// File Line: 257
// RVA: 0x361F80
UFG::qVector3 *__fastcall UFG::CoverPosition::GetPosition(UFG::CoverPosition *this, UFG::qVector3 *result)
{
  UFG::CoverPosition *v2; // rdi
  UFG::qVector3 *v3; // rbx
  float *v4; // rsi
  _DWORD *v5; // rax
  float v6; // eax
  float v7; // ecx
  UFG::ParkourHandle *v8; // rcx
  float v9; // xmm8_4
  UFG::qVector3 *v10; // rax
  float v11; // xmm6_4
  float v12; // xmm7_4
  float v13; // xmm8_4
  float v14; // xmm6_4
  float v15; // xmm7_4
  UFG::qVector3 *v16; // rax
  float v17; // xmm7_4
  float v18; // xmm8_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  UFG::qVector3 resulta; // [rsp+20h] [rbp-58h]
  UFG::qVector3 v23; // [rsp+2Ch] [rbp-4Ch]

  v2 = this;
  v3 = result;
  v4 = (float *)UFG::CoverCornerHandle::Get(&this->m_LeftCorner);
  v5 = (_DWORD *)UFG::CoverCornerHandle::Get(&v2->m_RightCorner);
  if ( v4 )
  {
    v6 = v4[6];
    v3->x = v4[4];
    v7 = v4[5];
    v3->z = v6;
    v3->y = v7;
  }
  else if ( v5 )
  {
    v3->x = (float)v5[4];
    v3->y = (float)v5[5];
    v3->z = (float)v5[6];
  }
  else
  {
    v8 = v2->m_pParkourHandle.m_pPointer;
    if ( v8 )
    {
      v9 = v2->m_fParkourTVal;
      v10 = UFG::ParkourHandle::GetAxis(v8, &resulta);
      v11 = v9;
      v12 = v9;
      v13 = v9 * v10->z;
      v14 = v11 * v10->x;
      v15 = v12 * v10->y;
      v16 = UFG::ParkourHandle::GetPosition(v2->m_pParkourHandle.m_pPointer, &v23);
      v17 = v15 + v16->y;
      v18 = v13 + v16->z;
      v3->x = v14 + v16->x;
      v3->y = v17;
      v3->z = v18;
    }
    else
    {
      v19 = (float)(v2->m_fParkourTVal * v2->m_vInbetweenParkourAxis.x) + v2->m_vInbetweenParkourPosition.x;
      v20 = (float)(v2->m_fParkourTVal * v2->m_vInbetweenParkourAxis.y) + v2->m_vInbetweenParkourPosition.y;
      v3->z = (float)(v2->m_fParkourTVal * v2->m_vInbetweenParkourAxis.z) + v2->m_vInbetweenParkourPosition.z;
      v3->x = v19;
      v3->y = v20;
    }
  }
  return v3;
}

// File Line: 282
// RVA: 0x359870
float __fastcall UFG::CoverPosition::GetAngleFromSweetSpot(UFG::CoverPosition *this, UFG::qVector3 *vPosition)
{
  UFG::CoverPosition *v2; // rdi
  UFG::qVector3 *v3; // rbx
  UFG::CoverCorner *v4; // rsi
  UFG::CoverCorner *v5; // r14
  float v6; // xmm7_4
  float v7; // xmm6_4
  float v8; // xmm8_4
  float v9; // xmm5_4
  __m128 v10; // xmm3
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
  UFG::ParkourHandle *v23; // r8
  float v24; // xmm3_4
  __m128 v25; // xmm2
  float v26; // xmm4_4
  __m128 v27; // xmm5
  float v28; // xmm2_4
  float v29; // xmm0_4
  UFG::qVector3 result; // [rsp+18h] [rbp-39h]
  UFG::qVector3 out; // [rsp+28h] [rbp-29h]

  v2 = this;
  v3 = vPosition;
  v4 = (UFG::CoverCorner *)UFG::CoverCornerHandle::Get(&this->m_LeftCorner);
  v5 = (UFG::CoverCorner *)UFG::CoverCornerHandle::Get(&v2->m_RightCorner);
  v6 = FLOAT_3_4028235e38;
  v7 = *(float *)&FLOAT_1_0;
  v8 = 0.0;
  if ( v4 )
  {
    UFG::CoverCorner::GetFiringPos(v4, &result);
    UFG::CoverCorner::GetSweetSpotDir(v4, &out);
    v10 = (__m128)LODWORD(v3->y);
    v9 = v3->x - result.x;
    v10.m128_f32[0] = v10.m128_f32[0] - result.y;
    v11 = v3->z - result.z;
    v12 = v10;
    v12.m128_f32[0] = (float)((float)(v10.m128_f32[0] * v10.m128_f32[0]) + (float)(v9 * v9)) + (float)(v11 * v11);
    if ( v12.m128_f32[0] == 0.0 )
      v13 = 0.0;
    else
      v13 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v12));
    v14 = (float)((float)(out.y * (float)(v10.m128_f32[0] * v13)) + (float)(out.x * (float)(v13 * v9)))
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
    v17 = (__m128)LODWORD(v3->y);
    v16 = v3->x - out.x;
    v17.m128_f32[0] = v17.m128_f32[0] - out.y;
    v18 = v3->z - out.z;
    v19 = v17;
    v19.m128_f32[0] = (float)((float)(v17.m128_f32[0] * v17.m128_f32[0]) + (float)(v16 * v16)) + (float)(v18 * v18);
    if ( v19.m128_f32[0] == 0.0 )
      v20 = 0.0;
    else
      v20 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v19));
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
  v23 = v2->m_pParkourHandle.m_pPointer;
  if ( v23 )
  {
    UFG::CoverObjectParkour::GetParkourFiringPosition(
      (UFG::CoverObjectParkour *)&v2->vfptr,
      &result,
      v23,
      v2->m_fParkourTVal);
    UFG::ParkourHandle::GetNormal(v2->m_pParkourHandle.m_pPointer, &out);
    v25 = (__m128)LODWORD(v3->y);
    v24 = v3->x - result.x;
    v25.m128_f32[0] = v25.m128_f32[0] - result.y;
    v27 = v25;
    v26 = v3->z - result.z;
    v27.m128_f32[0] = (float)((float)(v25.m128_f32[0] * v25.m128_f32[0]) + (float)(v24 * v24)) + (float)(v26 * v26);
    if ( v27.m128_f32[0] != 0.0 )
      v8 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v27));
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
}(v7);
      if ( v6 >= v29 )
        return v29;
      return v6;
    }
    v7 = v28;
    goto LABEL_29;
  }
  return 

// File Line: 318
// RVA: 0x35F8B0
UFG::qVector3 *__fastcall UFG::CoverPosition::GetFiringPosition(UFG::CoverPosition *this, UFG::qVector3 *result)
{
  UFG::qVector3 *v2; // rbx
  UFG::CoverPosition *v3; // rdi
  UFG::DynamicCoverCorner *v4; // rcx
  UFG::CoverCornerHandle *v5; // rcx
  UFG::CoverCorner *v6; // rax
  UFG::DynamicCoverCorner *v7; // rcx
  UFG::ParkourHandle *v8; // r8
  float v9; // xmm3_4
  float v10; // xmm2_4
  float v11; // xmm0_4
  float v12; // xmm5_4

  v2 = result;
  v3 = this;
  if ( this->m_LeftCorner.m_ResourceHandle.mData && this->m_LeftCorner.m_uCoverCornerIndex != -1
    || (v4 = this->m_LeftCorner.m_pDynamicCoverCorner.m_pPointer) != 0i64
    && UFG::DynamicCoverComponent::IsEnabled((UFG::DynamicCoverComponent *)v4->m_pParentInstance.m_pPointer) )
  {
    v5 = &v3->m_LeftCorner;
LABEL_6:
    v6 = (UFG::CoverCorner *)UFG::CoverCornerHandle::Get(v5);
    UFG::CoverCorner::GetFiringPos(v6, v2);
    return v2;
  }
  if ( v3->m_RightCorner.m_ResourceHandle.mData && v3->m_RightCorner.m_uCoverCornerIndex != -1
    || (v7 = v3->m_RightCorner.m_pDynamicCoverCorner.m_pPointer) != 0i64
    && UFG::DynamicCoverComponent::IsEnabled((UFG::DynamicCoverComponent *)v7->m_pParentInstance.m_pPointer) )
  {
    v5 = &v3->m_RightCorner;
    goto LABEL_6;
  }
  v8 = v3->m_pParkourHandle.m_pPointer;
  if ( v8 )
  {
    UFG::CoverObjectParkour::GetParkourFiringPosition((UFG::CoverObjectParkour *)&v3->vfptr, v2, v8, v3->m_fParkourTVal);
  }
  else
  {
    v9 = UFG::qVector3::msAxisZ.z * 0.2;
    v10 = UFG::qVector3::msAxisZ.y * 0.2;
    v11 = (float)(v3->m_fParkourTVal * v3->m_vInbetweenParkourAxis.y) + v3->m_vInbetweenParkourPosition.y;
    v12 = (float)(v3->m_fParkourTVal * v3->m_vInbetweenParkourAxis.z) + v3->m_vInbetweenParkourPosition.z;
    v2->x = (float)((float)(v3->m_fParkourTVal * v3->m_vInbetweenParkourAxis.x) + v3->m_vInbetweenParkourPosition.x)
          + (float)(UFG::qVector3::msAxisZ.x * 0.2);
    v2->y = v11 + v10;
    v2->z = v12 + v9;
  }
  return v2;
}

// File Line: 345
// RVA: 0x3618A0
__int64 __fastcall UFG::CoverPosition::GetNumFiringPositions(UFG::CoverPosition *this)
{
  unsigned int v1; // ebx
  UFG::CoverPosition *v2; // rdi
  UFG::DynamicCoverCorner *v3; // rcx
  UFG::DynamicCoverCorner *v4; // rcx
  __int64 result; // rax

  v1 = 0;
  v2 = this;
  if ( this->m_LeftCorner.m_ResourceHandle.mData && this->m_LeftCorner.m_uCoverCornerIndex != -1
    || (v3 = this->m_LeftCorner.m_pDynamicCoverCorner.m_pPointer) != 0i64
    && UFG::DynamicCoverComponent::IsEnabled((UFG::DynamicCoverComponent *)v3->m_pParentInstance.m_pPointer) )
  {
    v1 = 1;
  }
  if ( v2->m_RightCorner.m_ResourceHandle.mData && v2->m_RightCorner.m_uCoverCornerIndex != -1
    || (v4 = v2->m_RightCorner.m_pDynamicCoverCorner.m_pPointer) != 0i64
    && UFG::DynamicCoverComponent::IsEnabled((UFG::DynamicCoverComponent *)v4->m_pParentInstance.m_pPointer) )
  {
    ++v1;
  }
  result = v1 + 1;
  if ( !v2->m_pParkourHandle.m_pPointer )
    result = v1;
  return result;
}

// File Line: 366
// RVA: 0x35F790
UFG::qVector3 *__fastcall UFG::CoverPosition::GetFiringPosition(UFG::CoverPosition *this, UFG::qVector3 *result, unsigned int index)
{
  signed int v3; // esi
  unsigned int v4; // er14
  UFG::qVector3 *v5; // rbx
  UFG::CoverPosition *v6; // rbp
  UFG::DynamicCoverCorner *v7; // rcx
  UFG::CoverCornerHandle *v8; // rcx
  UFG::CoverCorner *v9; // rax
  UFG::DynamicCoverCorner *v10; // rcx
  signed int v11; // eax
  UFG::ParkourHandle *v12; // r8
  float v13; // xmm1_4
  float v14; // xmm2_4

  v3 = 0;
  v4 = index;
  v5 = result;
  v6 = this;
  if ( this->m_LeftCorner.m_ResourceHandle.mData && this->m_LeftCorner.m_uCoverCornerIndex != -1
    || (v7 = this->m_LeftCorner.m_pDynamicCoverCorner.m_pPointer) != 0i64
    && UFG::DynamicCoverComponent::IsEnabled((UFG::DynamicCoverComponent *)v7->m_pParentInstance.m_pPointer) )
  {
    v3 = 1;
    if ( !v4 )
    {
      v8 = &v6->m_LeftCorner;
LABEL_7:
      v9 = (UFG::CoverCorner *)UFG::CoverCornerHandle::Get(v8);
      UFG::CoverCorner::GetFiringPos(v9, v5);
      return v5;
    }
  }
  if ( v6->m_RightCorner.m_ResourceHandle.mData && v6->m_RightCorner.m_uCoverCornerIndex != -1
    || (v10 = v6->m_RightCorner.m_pDynamicCoverCorner.m_pPointer) != 0i64
    && UFG::DynamicCoverComponent::IsEnabled((UFG::DynamicCoverComponent *)v10->m_pParentInstance.m_pPointer) )
  {
    v11 = v3++;
    if ( v11 == v4 )
    {
      v8 = &v6->m_RightCorner;
      goto LABEL_7;
    }
  }
  v12 = v6->m_pParkourHandle.m_pPointer;
  if ( v12 && v3 == v4 )
  {
    UFG::CoverObjectParkour::GetParkourFiringPosition(
      (UFG::CoverObjectParkour *)&v6->vfptr,
      v5,
      v12,
      v6->m_fParkourTVal);
  }
  else
  {
    v13 = UFG::qVector3::msZero.y;
    v14 = UFG::qVector3::msZero.z;
    v5->x = UFG::qVector3::msZero.x;
    v5->y = v13;
    v5->z = v14;
  }
  return v5;
}

// File Line: 401
// RVA: 0x35F690
char __fastcall UFG::CoverPosition::GetFiringPosition(UFG::CoverPosition *this, UFG::CoverPosition::FiringPositionEnum eFiringPosition, UFG::qVector3 *vResultPosition)
{
  UFG::qVector3 *v3; // rdi
  __int32 v4; // edx
  UFG::ParkourHandle *v5; // r8
  UFG::qVector3 *v6; // rax
  UFG::CoverCornerHandle *v7; // rbx
  UFG::DynamicCoverCorner *v8; // rcx
  UFG::CoverCorner *v9; // rax
  UFG::qVector3 *v10; // rdx
  UFG::CoverCornerHandle *v11; // rbx
  UFG::DynamicCoverCorner *v12; // rcx
  float v13; // xmm0_4
  float v14; // xmm1_4
  char v15; // al
  UFG::qVector3 result; // [rsp+20h] [rbp-38h]
  char v17; // [rsp+2Ch] [rbp-2Ch]
  UFG::qVector3 v18; // [rsp+38h] [rbp-20h]

  v3 = vResultPosition;
  if ( eFiringPosition == FP_Left )
  {
    v11 = &this->m_LeftCorner;
    if ( !this->m_LeftCorner.m_ResourceHandle.mData || v11->m_uCoverCornerIndex == -1 )
    {
      v12 = this->m_LeftCorner.m_pDynamicCoverCorner.m_pPointer;
      if ( !v12
        || !UFG::DynamicCoverComponent::IsEnabled((UFG::DynamicCoverComponent *)v12->m_pParentInstance.m_pPointer) )
      {
        return 0;
      }
    }
    v9 = (UFG::CoverCorner *)UFG::CoverCornerHandle::Get(v11);
    v10 = &v18;
    goto LABEL_16;
  }
  v4 = eFiringPosition - 1;
  if ( !v4 )
  {
    v7 = &this->m_RightCorner;
    if ( !this->m_RightCorner.m_ResourceHandle.mData || v7->m_uCoverCornerIndex == -1 )
    {
      v8 = this->m_RightCorner.m_pDynamicCoverCorner.m_pPointer;
      if ( !v8 || !UFG::DynamicCoverComponent::IsEnabled((UFG::DynamicCoverComponent *)v8->m_pParentInstance.m_pPointer) )
        return 0;
    }
    v9 = (UFG::CoverCorner *)UFG::CoverCornerHandle::Get(v7);
    v10 = (UFG::qVector3 *)&v17;
LABEL_16:
    v6 = UFG::CoverCorner::GetFiringPos(v9, v10);
    goto LABEL_17;
  }
  if ( v4 == 1 )
  {
    v5 = this->m_pParkourHandle.m_pPointer;
    if ( v5 )
    {
      v6 = UFG::CoverObjectParkour::GetParkourFiringPosition(
             (UFG::CoverObjectParkour *)&this->vfptr,
             &result,
             v5,
             this->m_fParkourTVal);
LABEL_17:
      v13 = v6->y;
      v14 = v6->z;
      v3->x = v6->x;
      v15 = 1;
      v3->y = v13;
      v3->z = v14;
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
  UFG::qVector3 *v3; // rbx
  UFG::CoverPosition *v4; // rdi
  UFG::DynamicCoverCorner *v5; // rcx
  UFG::CoverCornerHandle *v6; // rcx
  signed __int64 v7; // rax
  float v8; // ecx
  UFG::DynamicCoverCorner *v9; // rcx
  UFG::ParkourHandle *v10; // rcx
  float v11; // xmm1_4
  float v12; // xmm0_4
  UFG::qVector3 out; // [rsp+20h] [rbp-18h]

  v2 = this->m_LeftCorner.m_ResourceHandle.mData == 0i64;
  v3 = result;
  v4 = this;
  out = UFG::qVector3::msAxisX;
  if ( !v2 && this->m_LeftCorner.m_uCoverCornerIndex != -1
    || (v5 = this->m_LeftCorner.m_pDynamicCoverCorner.m_pPointer) != 0i64
    && UFG::DynamicCoverComponent::IsEnabled((UFG::DynamicCoverComponent *)v5->m_pParentInstance.m_pPointer) )
  {
    v6 = &v4->m_LeftCorner;
LABEL_6:
    v7 = UFG::CoverCornerHandle::Get(v6);
    v3->z = 0.0;
    v8 = *(float *)(v7 + 28);
    v3->y = *(float *)(v7 + 32);
    v3->x = v8;
    return v3;
  }
  if ( v4->m_RightCorner.m_ResourceHandle.mData && v4->m_RightCorner.m_uCoverCornerIndex != -1
    || (v9 = v4->m_RightCorner.m_pDynamicCoverCorner.m_pPointer) != 0i64
    && UFG::DynamicCoverComponent::IsEnabled((UFG::DynamicCoverComponent *)v9->m_pParentInstance.m_pPointer) )
  {
    v6 = &v4->m_RightCorner;
    goto LABEL_6;
  }
  v10 = v4->m_pParkourHandle.m_pPointer;
  if ( v10 )
  {
    UFG::ParkourHandle::GetNormal(v10, &out);
  }
  else if ( v4->m_bInbetweenParkourLine )
  {
    v3->x = v4->m_vInbetweenParkourNormal.x;
    v3->y = v4->m_vInbetweenParkourNormal.y;
    v3->z = v4->m_vInbetweenParkourNormal.z;
    return v3;
  }
  v11 = out.y;
  v3->x = out.x;
  v12 = out.z;
  v3->y = v11;
  v3->z = v12;
  return v3;
}

// File Line: 465
// RVA: 0x362990
UFG::qVector3 *__usercall UFG::CoverPosition::GetSyncPos@<rax>(UFG::CoverPosition *this@<rcx>, UFG::qVector3 *result@<rdx>, float a3@<xmm0>)
{
  UFG::qVector3 *v3; // rbx
  UFG::CoverPosition *v4; // rdi
  float v5; // xmm5_4
  float v6; // xmm0_4
  UFG::qVector3 *v7; // rax
  float v8; // xmm2_4
  float v9; // xmm4_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm5_4
  UFG::DynamicCoverCorner *v13; // rcx
  UFG::CoverCornerHandle *v14; // rcx
  UFG::CoverCorner *v15; // rax
  UFG::DynamicCoverCorner *v16; // rcx
  UFG::ParkourHandle *v17; // rcx
  float v18; // xmm8_4
  UFG::qVector3 *v19; // rax
  float v20; // xmm6_4
  float v21; // xmm7_4
  float v22; // xmm8_4
  float v23; // xmm6_4
  UFG::qVector3 *v24; // rax
  float v25; // xmm8_4
  float v26; // xmm6_4
  float v27; // xmm1_4
  float v28; // xmm2_4
  UFG::qVector3 resulta; // [rsp+20h] [rbp-58h]
  UFG::qVector3 v30; // [rsp+2Ch] [rbp-4Ch]

  v3 = result;
  v4 = this;
  if ( !this->m_bInbetweenParkourLine )
  {
    if ( this->m_LeftCorner.m_ResourceHandle.mData && this->m_LeftCorner.m_uCoverCornerIndex != -1
      || (v13 = this->m_LeftCorner.m_pDynamicCoverCorner.m_pPointer) != 0i64
      && UFG::DynamicCoverComponent::IsEnabled((UFG::DynamicCoverComponent *)v13->m_pParentInstance.m_pPointer) )
    {
      v14 = &v4->m_LeftCorner;
    }
    else
    {
      if ( !v4->m_RightCorner.m_ResourceHandle.mData || v4->m_RightCorner.m_uCoverCornerIndex == -1 )
      {
        v16 = v4->m_RightCorner.m_pDynamicCoverCorner.m_pPointer;
        if ( !v16
          || !UFG::DynamicCoverComponent::IsEnabled((UFG::DynamicCoverComponent *)v16->m_pParentInstance.m_pPointer) )
        {
          v17 = v4->m_pParkourHandle.m_pPointer;
          if ( v17 )
          {
            v18 = v4->m_fParkourTVal;
            v19 = UFG::ParkourHandle::GetAxis(v17, &resulta);
            v20 = v18;
            v21 = v18 * v19->x;
            v22 = v18 * v19->z;
            v23 = v20 * v19->y;
            v24 = UFG::CoverObjectParkour::GetParkourSync((UFG::CoverObjectParkour *)&v4->vfptr, &v30, a3);
            v25 = v22 + v24->z;
            v26 = v23 + v24->y;
            v3->x = v21 + v24->x;
            v3->y = v26;
            v3->z = v25;
          }
          else
          {
            v27 = UFG::qVector3::msZero.y;
            v28 = UFG::qVector3::msZero.z;
            v3->x = UFG::qVector3::msZero.x;
            v3->y = v27;
            v3->z = v28;
          }
          return v3;
        }
      }
      v14 = &v4->m_RightCorner;
    }
    v15 = (UFG::CoverCorner *)UFG::CoverCornerHandle::Get(v14);
    UFG::CoverCorner::GetSyncPos(v15, v3);
    return v3;
  }
  ((void (*)(void))this->vfptr->GetHeight)();
  if ( a3 <= 0.5 || a3 >= 1.6 )
    v5 = UFG::CoverObjectBase::ms_fHighFrontOffset;
  else
    v5 = UFG::CoverObjectBase::ms_fLowFrontOffset;
  v6 = v4->m_fParkourSyncZOffset;
  v7 = v3;
  v8 = UFG::qVector3::msDirUp.x * v6;
  v9 = UFG::qVector3::msDirUp.z * v6;
  v10 = (float)((float)(v5 * v4->m_vInbetweenParkourNormal.y) + v4->m_vInbetweenParkourPosition.y)
      + (float)(UFG::qVector3::msDirUp.y * v6);
  v11 = (float)(v5 * v4->m_vInbetweenParkourNormal.x) + v4->m_vInbetweenParkourPosition.x;
  v12 = (float)(v5 * v4->m_vInbetweenParkourNormal.z) + v4->m_vInbetweenParkourPosition.z;
  v3->y = v10;
  v3->x = v11 + v8;
  v3->z = v12 + v9;
  return v7;
}

// File Line: 493
// RVA: 0x33C150
bool __fastcall UFG::CoverPosition::operator==(UFG::CoverPosition *this, UFG::CoverObjectBase *other)
{
  UFG::CoverPosition *v2; // rsi
  UFG::CoverObjectBase *v3; // rdi
  bool result; // al
  signed __int64 v5; // rbx
  signed __int64 v6; // rbx

  v2 = this;
  v3 = other;
  result = other->vfptr->IsPosition(other);
  if ( result )
  {
    v5 = UFG::CoverCornerHandle::Get((UFG::CoverCornerHandle *)&v3[2].m_iRefCount);
    if ( UFG::CoverCornerHandle::Get(&v2->m_LeftCorner) == v5
      && (v6 = UFG::CoverCornerHandle::Get((UFG::CoverCornerHandle *)&v3[4].m_iRefCount),
          UFG::CoverCornerHandle::Get(&v2->m_RightCorner) == v6) )
    {
      result = v3[1].m_pCoverObjectGroup == (UFG::CoverObjectGroup *)v2->m_pParkourHandle.m_pPointer;
    }
    else
    {
      result = 0;
    }
  }
  return result;
}

// File Line: 520
// RVA: 0x33C240
UFG::CoverPosition *__fastcall UFG::CoverPosition::operator+=(UFG::CoverPosition *this, UFG::CoverPosition *other)
{
  UFG::CoverPosition *v2; // rdi
  UFG::CoverCornerHandle *v3; // rdx
  signed __int64 v4; // rsi
  UFG::DynamicCoverCorner *v5; // rax
  UFG::CoverPosition *v6; // rbx
  signed __int64 v7; // rax
  UFG::qResourceData *v8; // rax
  UFG::qBaseNodeRB *v9; // rcx
  signed __int64 v10; // r8
  UFG::CoverCornerHandle *v11; // rdx
  UFG::DynamicCoverCorner *v12; // rax
  signed __int64 v13; // rax
  UFG::qResourceData *v14; // rax
  UFG::qBaseNodeRB *v15; // rcx
  UFG::ParkourHandle *v16; // r8
  UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle> *v17; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v20; // rax
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // eax
  float v26; // xmm1_4

  v2 = other;
  v3 = &other->m_LeftCorner;
  v4 = 0i64;
  v5 = v3->m_pDynamicCoverCorner.m_pPointer;
  v6 = this;
  if ( v5 )
  {
    v7 = (signed __int64)&v5->mPrev;
  }
  else
  {
    v8 = v3->m_ResourceHandle.mData;
    if ( !v8 )
      goto LABEL_10;
    v9 = v8[1].mNode.mChild[0];
    if ( v9 )
      v10 = (signed __int64)v8[1].mNode.mChild + (_QWORD)v9;
    else
      v10 = 0i64;
    v7 = v10 + 48i64 * v3->m_uCoverCornerIndex;
  }
  if ( v7 )
    UFG::CoverCornerHandle::operator=(&v6->m_LeftCorner, v3);
LABEL_10:
  v11 = &v2->m_RightCorner;
  v12 = v2->m_RightCorner.m_pDynamicCoverCorner.m_pPointer;
  if ( v12 )
  {
    v13 = (signed __int64)&v12->mPrev;
  }
  else
  {
    v14 = v2->m_RightCorner.m_ResourceHandle.mData;
    if ( !v14 )
      goto LABEL_18;
    v15 = v14[1].mNode.mChild[0];
    if ( v15 )
      v4 = (signed __int64)v14[1].mNode.mChild + (_QWORD)v15;
    v13 = v4 + 48i64 * v11->m_uCoverCornerIndex;
  }
  if ( v13 )
    UFG::CoverCornerHandle::operator=(&v6->m_RightCorner, v11);
LABEL_18:
  v16 = v2->m_pParkourHandle.m_pPointer;
  if ( v16 && (!v6->m_pParkourHandle.m_pPointer || v6->m_fDistanceInFront > v2->m_fDistanceInFront) )
  {
    v17 = &v6->m_pParkourHandle;
    if ( v6->m_pParkourHandle.m_pPointer )
    {
      v18 = v17->mPrev;
      v19 = v6->m_pParkourHandle.mNext;
      v18->mNext = v19;
      v19->mPrev = v18;
      v17->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v17->mPrev;
      v6->m_pParkourHandle.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v6->m_pParkourHandle.mPrev;
    }
    v6->m_pParkourHandle.m_pPointer = v16;
    if ( v16 )
    {
      v20 = v16->m_SafePointerList.mNode.mPrev;
      v20->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v17->mPrev;
      v17->mPrev = v20;
      v6->m_pParkourHandle.mNext = &v16->m_SafePointerList.mNode;
      v16->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v17->mPrev;
    }
    v6->m_fParkourTVal = v2->m_fParkourTVal;
    v6->m_fDistanceInFront = v2->m_fDistanceInFront;
    v6->m_fDistToLeft = v2->m_fDistToLeft;
    v6->m_fDistToRight = v2->m_fDistToRight;
    v6->m_bFoundParkourSync = v2->m_bFoundParkourSync;
    v6->m_fParkourSyncZOffset = v2->m_fParkourSyncZOffset;
  }
  if ( v2->m_bInbetweenParkourLine )
  {
    v21 = v2->m_vInbetweenParkourPosition.y;
    v22 = v2->m_vInbetweenParkourPosition.z;
    v6->m_vInbetweenParkourPosition.x = v2->m_vInbetweenParkourPosition.x;
    v6->m_vInbetweenParkourPosition.y = v21;
    v6->m_vInbetweenParkourPosition.z = v22;
    v23 = v2->m_vInbetweenParkourNormal.y;
    v24 = v2->m_vInbetweenParkourNormal.z;
    v6->m_vInbetweenParkourNormal.x = v2->m_vInbetweenParkourNormal.x;
    v6->m_vInbetweenParkourNormal.y = v23;
    v6->m_vInbetweenParkourNormal.z = v24;
    v25 = v2->m_vInbetweenParkourAxis.x;
    v26 = v2->m_vInbetweenParkourAxis.z;
    v6->m_vInbetweenParkourAxis.y = v2->m_vInbetweenParkourAxis.y;
    v6->m_vInbetweenParkourAxis.x = v25;
    v6->m_vInbetweenParkourAxis.z = v26;
    v6->m_bInbetweenParkourLine = v2->m_bInbetweenParkourLine;
    v6->m_bFoundParkourSync = v2->m_bFoundParkourSync;
    v6->m_fParkourSyncZOffset = v2->m_fParkourSyncZOffset;
  }
  return v6;
}

// File Line: 568
// RVA: 0x3416E0
void __fastcall UFG::CoverPosition::AddUser(UFG::CoverPosition *this, UFG::SimObject *pUser)
{
  UFG::SimObject *v2; // rbp
  UFG::CoverPosition *v3; // rsi
  UFG::DynamicCoverCorner *v4; // rax
  signed __int64 v5; // rax
  __int64 v6; // rcx
  UFG::DynamicCoverCorner *v7; // rax
  signed __int64 v8; // rax
  __int64 v9; // rcx
  signed __int64 v10; // rbx
  UFG::qNode<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser> *v11; // rdi
  UFG::qNode<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser> *v12; // rax
  UFG::qNode<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser> *v13; // rcx
  __int64 v14; // [rsp+28h] [rbp-30h]
  __int64 v15; // [rsp+30h] [rbp-28h]
  UFG::ParkourHandle *v16; // [rsp+38h] [rbp-20h]

  v2 = pUser;
  v3 = this;
  LOBYTE(pUser) = 1;
  this->vfptr->SetInUse((UFG::CoverObjectBase *)this, (bool)pUser);
  v4 = v3->m_LeftCorner.m_pDynamicCoverCorner.m_pPointer;
  if ( v4 )
  {
    v5 = (signed __int64)&v4->mPrev;
  }
  else
  {
    v5 = (signed __int64)v3->m_LeftCorner.m_ResourceHandle.mData;
    if ( v5 )
    {
      v6 = *(_QWORD *)(v5 + 96);
      if ( v6 )
        v6 += v5 + 96;
      v5 = v6 + 48i64 * v3->m_LeftCorner.m_uCoverCornerIndex;
    }
  }
  v14 = v5;
  v7 = v3->m_RightCorner.m_pDynamicCoverCorner.m_pPointer;
  if ( v7 )
  {
    v8 = (signed __int64)&v7->mPrev;
  }
  else
  {
    v8 = (signed __int64)v3->m_RightCorner.m_ResourceHandle.mData;
    if ( v8 )
    {
      v9 = *(_QWORD *)(v8 + 96);
      if ( v9 )
        v9 += v8 + 96;
      v8 = v9 + 48i64 * v3->m_RightCorner.m_uCoverCornerIndex;
    }
  }
  v15 = v8;
  v16 = v3->m_pParkourHandle.m_pPointer;
  v10 = 0i64;
  do
  {
    v11 = (UFG::qNode<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser> *)*(&v14 + v10);
    if ( v11 )
    {
      v12 = (UFG::qNode<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser> *)UFG::qMalloc(
                                                                                             0x20ui64,
                                                                                             "CoverUser",
                                                                                             0i64);
      if ( v12 )
      {
        v12->mPrev = v12;
        v12->mNext = v12;
      }
      v12[1].mPrev = v11;
      v12[1].mNext = (UFG::qNode<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser> *)v2;
      v13 = UFG::CoverObjectBase::ms_listUsers.mNode.mPrev;
      UFG::CoverObjectBase::ms_listUsers.mNode.mPrev->mNext = v12;
      v12->mPrev = v13;
      v12->mNext = (UFG::qNode<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser> *)&UFG::CoverObjectBase::ms_listUsers;
      UFG::CoverObjectBase::ms_listUsers.mNode.mPrev = v12;
      v3->m_aCoverUsers.p[v3->m_aCoverUsers.size++] = (UFG::CoverObjectBase::CoverUser *)v12;
    }
    ++v10;
  }
  while ( v10 < 3 );
}

// File Line: 597
// RVA: 0x3816A0
void __fastcall UFG::CoverPosition::RemoveUser(UFG::CoverPosition *this)
{
  UFG::CoverPosition *v1; // rbx
  UFG::CoverObjectBase::CoverUser *v2; // r8
  UFG::qNode<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser> *v3; // rcx
  UFG::qNode<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser> *v4; // rax
  UFG::qNode<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser> *v5; // rdx
  UFG::qNode<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser> *v6; // rax

  v1 = this;
  if ( (*((unsigned __int8 (__cdecl **)(UFG::CoverPosition *))&this->vfptr->__vecDelDtor + 2))(this) )
    v1->vfptr->GetInUse((UFG::CoverObjectBase *)&v1->vfptr);
  v1->vfptr->SetInUse((UFG::CoverObjectBase *)&v1->vfptr, 0);
  while ( v1->m_aCoverUsers.size )
  {
    v2 = v1->m_aCoverUsers.p[0];
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser> *)&v2->mPrev;
    v1->m_aCoverUsers.p[0] = v1->m_aCoverUsers.p[--v1->m_aCoverUsers.size];
    v5 = v2->mPrev;
    v6 = v2->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v2->mPrev = (UFG::qNode<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser> *)&v2->mPrev;
    operator delete[](v2);
  }
}

// File Line: 620
// RVA: 0x34CAB0
char __fastcall UFG::CoverPosition::CanUse(UFG::CoverPosition *this, UFG::SimObject *pUser)
{
  UFG::SimObject *v2; // rbp
  UFG::CoverPosition *v3; // rsi
  UFG::DynamicCoverCorner *v5; // rax
  __int64 v6; // rdi
  signed __int64 v7; // rax
  UFG::qResourceData *v8; // rax
  UFG::qBaseNodeRB *v9; // rcx
  signed __int64 v10; // rdx
  UFG::DynamicCoverCorner *v11; // rax
  signed __int64 v12; // rax
  UFG::qResourceData *v13; // rax
  UFG::qBaseNodeRB *v14; // rcx
  signed __int64 v15; // rdx
  UFG::qList<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser,1,0> *v16; // rbx
  UFG::SimObject *v17; // rdx
  __int64 v18; // [rsp+20h] [rbp-28h]
  __int64 v19; // [rsp+28h] [rbp-20h]
  UFG::ParkourHandle *v20; // [rsp+30h] [rbp-18h]

  v2 = pUser;
  v3 = this;
  if ( !((unsigned __int8 (*)(void))this->vfptr->GetInUse)() )
    return 1;
  v5 = v3->m_LeftCorner.m_pDynamicCoverCorner.m_pPointer;
  v6 = 0i64;
  if ( v5 )
  {
    v7 = (signed __int64)&v5->mPrev;
  }
  else
  {
    v8 = v3->m_LeftCorner.m_ResourceHandle.mData;
    if ( v8 )
    {
      v9 = v8[1].mNode.mChild[0];
      if ( v9 )
        v10 = (signed __int64)v8[1].mNode.mChild + (_QWORD)v9;
      else
        v10 = 0i64;
      v7 = v10 + 48i64 * v3->m_LeftCorner.m_uCoverCornerIndex;
    }
    else
    {
      v7 = 0i64;
    }
  }
  v18 = v7;
  v11 = v3->m_RightCorner.m_pDynamicCoverCorner.m_pPointer;
  if ( v11 )
  {
    v12 = (signed __int64)&v11->mPrev;
  }
  else
  {
    v13 = v3->m_RightCorner.m_ResourceHandle.mData;
    if ( v13 )
    {
      v14 = v13[1].mNode.mChild[0];
      if ( v14 )
        v15 = (signed __int64)v13[1].mNode.mChild + (_QWORD)v14;
      else
        v15 = 0i64;
      v12 = v15 + 48i64 * v3->m_RightCorner.m_uCoverCornerIndex;
    }
    else
    {
      v12 = 0i64;
    }
  }
  v19 = v12;
  v20 = v3->m_pParkourHandle.m_pPointer;
  while ( 1 )
  {
    if ( *(&v18 + v6) )
    {
      v16 = (UFG::qList<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser,1,0> *)UFG::CoverObjectBase::ms_listUsers.mNode.mNext;
      if ( (UFG::qList<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser,1,0> *)UFG::CoverObjectBase::ms_listUsers.mNode.mNext != &UFG::CoverObjectBase::ms_listUsers )
        break;
    }
LABEL_25:
    if ( ++v6 >= 3 )
      return 1;
  }
  while ( 1 )
  {
    v17 = (UFG::SimObject *)v16[1].mNode.mNext;
    if ( v17 != v2 && UFG::CoverPosition::IsUserTooClose(v3, v17) )
      return 0;
    v16 = (UFG::qList<UFG::CoverObjectBase::CoverUser,UFG::CoverObjectBase::CoverUser,1,0> *)v16->mNode.mNext;
    if ( v16 == &UFG::CoverObjectBase::ms_listUsers )
      goto LABEL_25;
  }
}

// File Line: 656
// RVA: 0x36BD60
bool __fastcall UFG::CoverPosition::IsUserTooClose(UFG::CoverPosition *this, UFG::SimObject *pUser)
{
  UFG::SimObject *v2; // r8
  UFG::CoverPosition *v3; // rdi
  UFG::SimComponent *v4; // rax
  unsigned __int16 v5; // cx
  __int64 v6; // rbx
  float *v7; // rbx
  float *v8; // rax
  float v9; // xmm1_4
  float v10; // xmm0_4
  bool result; // al
  char v12; // [rsp+28h] [rbp-20h]
  char v13; // [rsp+34h] [rbp-14h]

  v2 = pUser;
  v3 = this;
  if ( pUser )
  {
    v5 = pUser->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v4 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)pUser, UFG::AICoverComponent::_TypeUID);
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v4 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)pUser, UFG::AICoverComponent::_TypeUID);
      }
      else if ( (v5 >> 12) & 1 )
      {
        v4 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)pUser, UFG::AICoverComponent::_TypeUID);
      }
      else
      {
        v4 = UFG::SimObject::GetComponentOfType(pUser, UFG::AICoverComponent::_TypeUID);
      }
    }
    else
    {
      v4 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)pUser, UFG::AICoverComponent::_TypeUID);
    }
  }
  else
  {
    v4 = 0i64;
  }
  v6 = *(_QWORD *)&v4[1].m_Flags;
  result = 0;
  if ( v6
    && (*(unsigned __int8 (__fastcall **)(__int64, UFG::SimObject *, UFG::SimObject *))(*(_QWORD *)v6 + 16i64))(
         v6,
         pUser,
         v2) )
  {
    v7 = (float *)(*(__int64 (__fastcall **)(__int64, char *))(*(_QWORD *)v6 + 120i64))(v6, &v12);
    v8 = (float *)v3->vfptr->GetSyncPos((UFG::CoverObjectBase *)&v3->vfptr, (UFG::qVector3 *)&v13);
    v9 = (float)((float)(*v8 - *v7) * (float)(*v8 - *v7)) + (float)((float)(v8[1] - v7[1]) * (float)(v8[1] - v7[1]));
    if ( _S63 & 1 )
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
      result = 1;
  }
  return result;
}

// File Line: 680
// RVA: 0x360110
char __fastcall UFG::CoverPosition::GetInUse(UFG::CoverPosition *this)
{
  signed __int64 v1; // rdi
  UFG::CoverPosition *v2; // rbx
  UFG::DynamicCoverCorner *v3; // rcx
  UFG::DynamicCoverCorner *v4; // rax
  signed __int64 v5; // rax
  UFG::qResourceData *v6; // rax
  UFG::qBaseNodeRB *v7; // rcx
  signed __int64 v8; // rdx
  char result; // al
  UFG::DynamicCoverCorner *v10; // rcx
  UFG::DynamicCoverCorner *v11; // rax
  UFG::qResourceData *v12; // rax
  UFG::qBaseNodeRB *v13; // rcx
  signed __int64 v14; // rcx
  UFG::ParkourHandle *v15; // rax

  v1 = 0i64;
  v2 = this;
  if ( this->m_LeftCorner.m_ResourceHandle.mData && this->m_LeftCorner.m_uCoverCornerIndex != -1
    || (v3 = this->m_LeftCorner.m_pDynamicCoverCorner.m_pPointer) != 0i64
    && UFG::DynamicCoverComponent::IsEnabled((UFG::DynamicCoverComponent *)v3->m_pParentInstance.m_pPointer) )
  {
    v4 = v2->m_LeftCorner.m_pDynamicCoverCorner.m_pPointer;
    if ( v4 )
    {
      v5 = (signed __int64)&v4->mPrev;
    }
    else
    {
      v6 = v2->m_LeftCorner.m_ResourceHandle.mData;
      if ( v6 )
      {
        v7 = v6[1].mNode.mChild[0];
        v8 = (signed __int64)(v7 ? (UFG::qBaseNodeRB **)((char *)v6[1].mNode.mChild + (_QWORD)v7) : 0i64);
        v5 = v8 + 48i64 * v2->m_LeftCorner.m_uCoverCornerIndex;
      }
      else
      {
        v5 = 0i64;
      }
    }
    if ( *(_BYTE *)(v5 + 38) )
      goto LABEL_32;
  }
  if ( v2->m_RightCorner.m_ResourceHandle.mData && v2->m_RightCorner.m_uCoverCornerIndex != -1
    || (v10 = v2->m_RightCorner.m_pDynamicCoverCorner.m_pPointer) != 0i64
    && UFG::DynamicCoverComponent::IsEnabled((UFG::DynamicCoverComponent *)v10->m_pParentInstance.m_pPointer) )
  {
    v11 = v2->m_RightCorner.m_pDynamicCoverCorner.m_pPointer;
    if ( v11 )
    {
      v1 = (signed __int64)&v11->mPrev;
    }
    else
    {
      v12 = v2->m_RightCorner.m_ResourceHandle.mData;
      if ( v12 )
      {
        v13 = v12[1].mNode.mChild[0];
        if ( v13 )
          v14 = (signed __int64)&v13[3] + (_QWORD)v12;
        else
          v14 = 0i64;
        v1 = v14 + 48i64 * v2->m_RightCorner.m_uCoverCornerIndex;
      }
    }
    if ( *(_BYTE *)(v1 + 38) )
      goto LABEL_32;
  }
  v15 = v2->m_pParkourHandle.m_pPointer;
  if ( v15 && *((_BYTE *)v15 + 152) & 0x1C )
LABEL_32:
    result = 1;
  else
    result = 0;
  return result;
}

// File Line: 709
// RVA: 0x3868B0
void __fastcall UFG::CoverPosition::SetInUse(UFG::CoverPosition *this, bool bInUse)
{
  signed __int64 v2; // rdi
  bool v3; // bp
  UFG::CoverPosition *v4; // rbx
  const char *v5; // r14
  UFG::DynamicCoverCorner *v6; // rcx
  UFG::DynamicCoverCorner *v7; // rsi
  signed __int64 v8; // rsi
  UFG::qResourceData *v9; // rax
  UFG::qBaseNodeRB *v10; // rcx
  signed __int64 v11; // rdx
  const char *v12; // rdx
  UFG::DynamicCoverCorner *v13; // rcx
  UFG::DynamicCoverCorner *v14; // rax
  UFG::qResourceData *v15; // rax
  UFG::qBaseNodeRB *v16; // rcx
  signed __int64 v17; // rcx
  UFG::ParkourHandle *v18; // rdx

  v2 = 0i64;
  v3 = bInUse;
  v4 = this;
  v5 = "false";
  if ( this->m_LeftCorner.m_ResourceHandle.mData && this->m_LeftCorner.m_uCoverCornerIndex != -1
    || (v6 = this->m_LeftCorner.m_pDynamicCoverCorner.m_pPointer) != 0i64
    && UFG::DynamicCoverComponent::IsEnabled((UFG::DynamicCoverComponent *)v6->m_pParentInstance.m_pPointer) )
  {
    v7 = v4->m_LeftCorner.m_pDynamicCoverCorner.m_pPointer;
    if ( v7 )
    {
      v8 = (signed __int64)&v7->mPrev;
    }
    else
    {
      v9 = v4->m_LeftCorner.m_ResourceHandle.mData;
      if ( v9 )
      {
        v10 = v9[1].mNode.mChild[0];
        if ( v10 )
          v11 = (signed __int64)v9[1].mNode.mChild + (_QWORD)v10;
        else
          v11 = 0i64;
        v8 = v11 + 48i64 * v4->m_LeftCorner.m_uCoverCornerIndex;
      }
      else
      {
        v8 = 0i64;
      }
    }
    if ( v3 == (*(_BYTE *)(v8 + 38) != 0) )
    {
      v12 = "false";
      if ( v3 )
        v12 = "true";
      UFG::qPrintf("CoverPosition::SetInUse() invalid call.  bInUse = %s\n", v12);
    }
    *(_BYTE *)(v8 + 38) = v3;
  }
  if ( v4->m_RightCorner.m_ResourceHandle.mData && v4->m_RightCorner.m_uCoverCornerIndex != -1
    || (v13 = v4->m_RightCorner.m_pDynamicCoverCorner.m_pPointer) != 0i64
    && UFG::DynamicCoverComponent::IsEnabled((UFG::DynamicCoverComponent *)v13->m_pParentInstance.m_pPointer) )
  {
    v14 = v4->m_RightCorner.m_pDynamicCoverCorner.m_pPointer;
    if ( v14 )
    {
      v2 = (signed __int64)&v14->mPrev;
    }
    else
    {
      v15 = v4->m_RightCorner.m_ResourceHandle.mData;
      if ( v15 )
      {
        v16 = v15[1].mNode.mChild[0];
        if ( v16 )
          v17 = (signed __int64)&v16[3] + (_QWORD)v15;
        else
          v17 = 0i64;
        v2 = v17 + 48i64 * v4->m_RightCorner.m_uCoverCornerIndex;
      }
    }
    if ( v3 == (*(_BYTE *)(v2 + 38) != 0) )
    {
      if ( v3 )
        v5 = "true";
      UFG::qPrintf("CoverPosition::SetInUse() invalid call.  bInUse = %s\n", v5);
    }
    *(_BYTE *)(v2 + 38) = v3;
  }
  v18 = v4->m_pParkourHandle.m_pPointer;
  if ( v18 )
  {
    if ( v3 )
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
  UFG::CoverPosition *v1; // rbx
  float v2; // xmm6_4
  signed __int64 v3; // rax
  signed __int64 v4; // rax
  float result; // xmm0_4

  v1 = this;
  v2 = FLOAT_3_4028235e38;
  v3 = UFG::CoverCornerHandle::Get(&this->m_LeftCorner);
  if ( v3 && *(float *)(v3 + 40) <= 3.4028235e38 )
    v2 = *(float *)(v3 + 40);
  v4 = UFG::CoverCornerHandle::Get(&v1->m_RightCorner);
  if ( v4 && v2 >= *(float *)(v4 + 40) )
    v2 = *(float *)(v4 + 40);
  if ( v1->m_pParkourHandle.m_pPointer && v2 >= COERCE_FLOAT(LODWORD(v1->m_fParkourSyncZOffset) ^ _xmm[0]) )
    LODWORD(v2) = LODWORD(v1->m_fParkourSyncZOffset) ^ _xmm[0];
  if ( !v1->m_bInbetweenParkourLine || (LODWORD(result) = LODWORD(v1->m_fParkourSyncZOffset) ^ _xmm[0], v2 < result) )
    result = v2;
  return result;
}

// File Line: 777
// RVA: 0x369AE0
char __fastcall UFG::CoverPosition::IsAnyLineOrCornerShared(UFG::CoverPosition *this, UFG::CoverObjectBase *pOther)
{
  UFG::CoverObjectBase *v2; // r14
  UFG::CoverPosition *v3; // rsi
  unsigned int v5; // er15
  unsigned __int64 v6; // rax
  UFG::allocator::free_link *v7; // rax
  _QWORD *v8; // r13
  unsigned int v9; // ebx
  unsigned __int64 v10; // rax
  UFG::allocator::free_link *v11; // rdi
  UFG::DynamicCoverCorner *v12; // rcx
  signed __int64 v13; // rcx
  UFG::qResourceData *v14; // rax
  UFG::qBaseNodeRB *v15; // rcx
  signed __int64 v16; // rdx
  UFG::DynamicCoverCorner *v17; // r12
  signed __int64 v18; // r12
  UFG::qResourceData *v19; // rax
  UFG::qBaseNodeRB *v20; // rdx
  unsigned int v21; // esi
  unsigned int v22; // ecx
  unsigned int v23; // er13
  unsigned int v24; // er14
  unsigned __int64 v25; // rax
  UFG::allocator::free_link *v26; // rax
  UFG::allocator::free_link *v27; // rcx
  __int64 v28; // rdx
  signed __int64 v29; // rax
  UFG::allocator::free_link *v30; // rdx
  __int64 v31; // r8
  signed __int64 v32; // r12
  signed __int64 v33; // rax
  __int64 v34; // rax
  unsigned int v35; // er14
  unsigned __int64 v36; // rax
  UFG::allocator::free_link *v37; // rax
  UFG::allocator::free_link *v38; // r12
  UFG::allocator::free_link *v39; // rcx
  __int64 v40; // rdx
  int v41; // eax
  UFG::ParkourHandle *v42; // rax
  char v43; // bl
  UFG::allocator::free_link *mem; // [rsp+30h] [rbp-28h]
  UFG::CoverPosition *v45; // [rsp+A0h] [rbp+48h]
  UFG::CoverObjectBase *v46; // [rsp+A8h] [rbp+50h]
  UFG::allocator::free_link *v47; // [rsp+B8h] [rbp+60h]
  UFG::allocator::free_link *v48; // [rsp+B8h] [rbp+60h]

  v46 = pOther;
  v45 = this;
  v2 = pOther;
  v3 = this;
  if ( !pOther )
    return 0;
  v5 = 0;
  v6 = 16i64;
  if ( !is_mul_ok(2ui64, 8ui64) )
    v6 = -1i64;
  v7 = UFG::qMalloc(v6, "qArray.Reallocate(Constructor)", 0i64);
  v8 = &v7->mNext;
  mem = v7;
  v9 = 0;
  v10 = 16i64;
  if ( !is_mul_ok(2ui64, 8ui64) )
    v10 = -1i64;
  v11 = UFG::qMalloc(v10, "qArray.Reallocate(Constructor)", 0i64);
  v12 = v3->m_LeftCorner.m_pDynamicCoverCorner.m_pPointer;
  if ( v12 )
  {
    v13 = (signed __int64)&v12->mPrev;
  }
  else
  {
    v14 = v3->m_LeftCorner.m_ResourceHandle.mData;
    if ( v14 )
    {
      v15 = v14[1].mNode.mChild[0];
      if ( v15 )
        v16 = (signed __int64)v14[1].mNode.mChild + (_QWORD)v15;
      else
        v16 = 0i64;
      v13 = v16 + 48i64 * v3->m_LeftCorner.m_uCoverCornerIndex;
    }
    else
    {
      v13 = 0i64;
    }
  }
  v17 = v3->m_RightCorner.m_pDynamicCoverCorner.m_pPointer;
  if ( v17 )
  {
    v18 = (signed __int64)&v17->mPrev;
  }
  else
  {
    v19 = v3->m_RightCorner.m_ResourceHandle.mData;
    if ( v19 )
    {
      v20 = v19[1].mNode.mChild[0];
      if ( v20 )
        v20 = (UFG::qBaseNodeRB *)((char *)v20 + (_QWORD)v19 + 96);
      v18 = (signed __int64)v20 + 48 * v3->m_RightCorner.m_uCoverCornerIndex;
    }
    else
    {
      v18 = 0i64;
    }
  }
  if ( v13 )
  {
    v5 = 1;
    *v8 = v13;
  }
  v21 = 4;
  if ( v18 )
  {
    v22 = v5;
    v23 = v5 + 1;
    if ( v5 + 1 > 2 )
    {
      v24 = 4;
      if ( v23 > 4 )
      {
        do
          v24 *= 2;
        while ( v24 < v23 );
        if ( v24 <= 2 )
          v24 = 2;
      }
      if ( v24 - v23 > 0x10000 )
        v24 = v5 + 65537;
      if ( v24 != v5 )
      {
        v25 = 8i64 * v24;
        if ( !is_mul_ok(v24, 8ui64) )
          v25 = -1i64;
        v26 = UFG::qMalloc(v25, "qArray.Add", 0i64);
        v47 = v26;
        if ( mem )
        {
          if ( v5 )
          {
            v27 = v26;
            v28 = v5;
            do
            {
              v27->mNext = *(UFG::allocator::free_link **)((char *)v27 + (char *)mem - (char *)v26);
              ++v27;
              --v28;
            }
            while ( v28 );
          }
          operator delete[](mem);
          v26 = v47;
        }
        mem = v26;
        v22 = v5;
      }
      v2 = v46;
    }
    ++v5;
    v8 = &mem->mNext;
    mem[v22].mNext = (UFG::allocator::free_link *)v18;
  }
  if ( v2->vfptr->IsCorner(v2) )
  {
    v29 = UFG::CoverCornerHandle::Get((UFG::CoverCornerHandle *)&v2[1]);
    if ( v29 )
    {
      v9 = 1;
      v11->mNext = (UFG::allocator::free_link *)v29;
    }
  }
  else if ( v2->vfptr->IsPosition(v2) )
  {
    v32 = UFG::CoverCornerHandle::Get((UFG::CoverCornerHandle *)&v2[2].m_iRefCount);
    v33 = UFG::CoverCornerHandle::Get((UFG::CoverCornerHandle *)&v2[4].m_iRefCount);
    v48 = (UFG::allocator::free_link *)v33;
    if ( v32 )
    {
      v9 = 1;
      v11->mNext = (UFG::allocator::free_link *)v32;
    }
    if ( v33 )
    {
      v34 = v9;
      v35 = v9 + 1;
      if ( v9 + 1 > 2 )
      {
        if ( v35 > 4 )
        {
          do
            v21 *= 2;
          while ( v21 < v35 );
          if ( v21 <= 2 )
            v21 = 2;
        }
        if ( v21 - v35 > 0x10000 )
          v21 = v9 + 65537;
        if ( v21 != v9 )
        {
          v36 = 8i64 * v21;
          if ( !is_mul_ok(v21, 8ui64) )
            v36 = -1i64;
          v37 = UFG::qMalloc(v36, "qArray.Add", 0i64);
          v38 = v37;
          if ( v11 )
          {
            if ( v9 )
            {
              v39 = v37;
              v40 = v9;
              do
              {
                v39->mNext = *(UFG::allocator::free_link **)((char *)v39 + (char *)v11 - (char *)v37);
                ++v39;
                --v40;
              }
              while ( v40 );
            }
            operator delete[](v11);
          }
          v11 = v38;
          v34 = v9;
        }
      }
      ++v9;
      v11[v34].mNext = v48;
      v2 = v46;
    }
  }
  if ( v5 && v9 && (v31 = 0i64, v5) )
  {
    while ( 1 )
    {
      v41 = 0;
      if ( v9 )
        break;
LABEL_74:
      v31 = (unsigned int)(v31 + 1);
      if ( (unsigned int)v31 >= v5 )
        goto LABEL_75;
    }
    v30 = (UFG::allocator::free_link *)v8[(unsigned int)v31];
    while ( v30 != v11[v41].mNext )
    {
      if ( ++v41 >= v9 )
        goto LABEL_74;
    }
  }
  else
  {
LABEL_75:
    if ( !((unsigned __int8 (__fastcall *)(UFG::CoverObjectBase *, UFG::allocator::free_link *, __int64))v2->vfptr->IsParkour)(
            v2,
            v30,
            v31)
      || (v42 = v45->m_pParkourHandle.m_pPointer) == 0i64
      || v42 != (UFG::ParkourHandle *)v2[1].m_pCoverObjectGroup )
    {
      v43 = 0;
      goto LABEL_80;
    }
  }
  v43 = 1;
LABEL_80:
  if ( v11 )
    operator delete[](v11);
  if ( v8 )
    operator delete[](v8);
  return v43;
}

