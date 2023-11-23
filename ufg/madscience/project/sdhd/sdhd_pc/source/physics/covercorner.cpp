// File Line: 39
// RVA: 0x466080
UFG::qVector3 *__fastcall UFG::CoverCorner::GetAlongWall(UFG::CoverCorner *this, UFG::qVector3 *result)
{
  bool v2; // zf
  float y; // xmm0_4
  UFG::qVector3 *v4; // rax
  float x; // xmm0_4

  v2 = this->m_eCoverSide.mValue == 0;
  result->z = 0.0;
  if ( v2 )
  {
    y = this->m_vWallNormal.y;
    result->y = this->m_vWallNormal.x;
    v4 = result;
    LODWORD(result->x) = LODWORD(y) ^ _xmm[0];
  }
  else
  {
    x = this->m_vWallNormal.x;
    result->x = this->m_vWallNormal.y;
    v4 = result;
    LODWORD(result->y) = LODWORD(x) ^ _xmm[0];
  }
  return v4;
}

// File Line: 54
// RVA: 0x467E40
UFG::qVector3 *__fastcall UFG::CoverCorner::GetSyncPos(UFG::CoverCorner *this, UFG::qVector3 *result)
{
  float y; // xmm5_4
  float x; // xmm6_4
  float v4; // xmm3_4
  float v5; // xmm1_4
  UFG::qVector3 *v6; // rax
  float v7; // xmm2_4
  float v8; // xmm1_4

  y = this->m_vWallNormal.y;
  x = this->m_vWallNormal.x;
  if ( this->m_fWallHeight >= 1.5 )
  {
    if ( this->m_eCoverSide.mValue )
      LODWORD(x) ^= _xmm[0];
    else
      LODWORD(y) ^= _xmm[0];
    v4 = UFG::CoverCorner::ms_fHighSideOffset;
    v5 = UFG::CoverCorner::ms_fHighFrontOffset;
  }
  else
  {
    if ( this->m_eCoverSide.mValue )
      LODWORD(x) ^= _xmm[0];
    else
      LODWORD(y) ^= _xmm[0];
    v4 = UFG::CoverCorner::ms_fLowSideOffset;
    v5 = UFG::CoverCorner::ms_fLowFrontOffset;
  }
  v6 = result;
  v7 = (float)((float)(this->m_vWallNormal.y * v5) + this->m_vCornerPosition.y) + (float)(x * v4);
  result->x = (float)((float)(this->m_vWallNormal.x * v5) + this->m_vCornerPosition.x) + (float)(y * v4);
  v8 = (float)(v5 * 0.0) + this->m_vCornerPosition.z;
  result->y = v7;
  result->z = v8 + (float)(v4 * 0.0);
  return v6;
}

// File Line: 70
// RVA: 0x466730
UFG::qVector3 *__fastcall UFG::CoverCorner::GetFiringPos(UFG::CoverCorner *this, UFG::qVector3 *result)
{
  float v2; // xmm0_4
  float y; // xmm3_4
  float v4; // xmm5_4
  float v5; // xmm6_4
  float x; // xmm4_4
  UFG::qVector3 *v7; // rax
  float v8; // xmm0_4
  float v9; // xmm1_4

  if ( this->m_fWallHeight >= 1.5 )
    v2 = FLOAT_1_3;
  else
    v2 = FLOAT_0_89999998;
  y = this->m_vWallNormal.y;
  v4 = UFG::qVector3::msAxisZ.x * v2;
  v5 = UFG::qVector3::msAxisZ.y * v2;
  x = this->m_vWallNormal.x;
  if ( this->m_eCoverSide.mValue )
    LODWORD(x) ^= _xmm[0];
  else
    LODWORD(y) ^= _xmm[0];
  v7 = result;
  v8 = this->m_vCornerPosition.z + (float)(UFG::qVector3::msAxisZ.z * v2);
  v9 = (float)((float)((float)(this->m_vWallNormal.y * 0.5) + this->m_vCornerPosition.y) - (float)(x * 0.5)) + v5;
  result->x = (float)((float)((float)(this->m_vWallNormal.x * 0.5) + this->m_vCornerPosition.x) - (float)(y * 0.5)) + v4;
  result->z = v8;
  result->y = v9;
  return v7;
}

// File Line: 80
// RVA: 0x467B60
UFG::qVector3 *__fastcall UFG::CoverCorner::GetSweetSpotDir(UFG::CoverCorner *this, UFG::qVector3 *result)
{
  bool v2; // zf
  int v4; // xmm2_4
  float v5; // xmm2_4
  UFG::qVector3 source; // [rsp+20h] [rbp-18h] BYREF

  v2 = this->m_eCoverSide.mValue == 1;
  v4 = LODWORD(this->m_vWallNormal.y) ^ _xmm[0];
  LODWORD(source.x) = LODWORD(this->m_vWallNormal.x) ^ _xmm[0];
  LODWORD(source.y) = v4;
  source.z = FLOAT_N0_0;
  if ( v2 )
    v5 = FLOAT_0_52359879;
  else
    v5 = FLOAT_N0_52359879;
  *(_QWORD *)&result->x = 0i64;
  result->z = 0.0;
  UFG::qRotateVectorZ(result, &source, v5);
  return result;
}

// File Line: 94
// RVA: 0x467BE0
void __fastcall UFG::CoverCorner::GetSyncMatrix(UFG::CoverCorner *this, UFG::qMatrix44 *outMatrix)
{
  int v2; // xmm5_4
  int v3; // xmm7_4
  float v4; // xmm1_4
  __int128 v5; // xmm3
  float v6; // xmm7_4
  float v7; // xmm5_4
  __m128 x_low; // xmm2
  float v9; // xmm9_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm9_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  __int128 v15; // xmm10
  float v16; // xmm8_4
  float v17; // xmm5_4
  float v18; // xmm2_4
  float v19; // xmm1_4
  float v20; // xmm8_4
  float v21; // xmm5_4
  float v22; // xmm7_4
  __m128 v23; // xmm9
  float v24; // xmm8_4
  __m128 v25; // xmm2
  float v26; // xmm4_4
  float y; // xmm0_4
  float z; // xmm1_4
  float x; // eax

  v2 = LODWORD(this->m_vWallNormal.y) ^ _xmm[0];
  v3 = LODWORD(this->m_vWallNormal.x) ^ _xmm[0];
  v4 = (float)(*(float *)&v2 * *(float *)&v2) + (float)(*(float *)&v3 * *(float *)&v3);
  if ( v4 == 0.0 )
  {
    v5 = 0i64;
  }
  else
  {
    v5 = (unsigned int)FLOAT_1_0;
    *(float *)&v5 = 1.0 / fsqrt(v4);
  }
  v6 = *(float *)&v3 * *(float *)&v5;
  v7 = *(float *)&v2 * *(float *)&v5;
  *(float *)&v5 = *(float *)&v5 * -0.0;
  outMatrix->v0.w = 0.0;
  outMatrix->v0.x = v6;
  outMatrix->v0.y = v7;
  LODWORD(outMatrix->v0.z) = v5;
  x_low = (__m128)LODWORD(UFG::qVector3::msAxisZ.x);
  x_low.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0])
                            + (float)(UFG::qVector3::msAxisZ.y * UFG::qVector3::msAxisZ.y))
                    + (float)(UFG::qVector3::msAxisZ.z * UFG::qVector3::msAxisZ.z);
  if ( x_low.m128_f32[0] == 0.0 )
    v9 = 0.0;
  else
    v9 = 1.0 / _mm_sqrt_ps(x_low).m128_f32[0];
  v10 = v9;
  v11 = v9;
  v12 = v9 * UFG::qVector3::msAxisZ.z;
  v13 = v10 * UFG::qVector3::msAxisZ.x;
  v14 = v11 * UFG::qVector3::msAxisZ.y;
  v15 = v5;
  *(float *)&v15 = (float)(*(float *)&v5 * v14) - (float)(v7 * v12);
  v16 = (float)(v6 * v12) - (float)(*(float *)&v5 * v13);
  v17 = (float)(v7 * v13) - (float)(v6 * v14);
  v18 = (float)((float)(v16 * v16) + (float)(*(float *)&v15 * *(float *)&v15)) + (float)(v17 * v17);
  if ( v18 == 0.0 )
    v19 = 0.0;
  else
    v19 = 1.0 / fsqrt(v18);
  v20 = v16 * v19;
  outMatrix->v1.w = 0.0;
  *(float *)&v15 = *(float *)&v15 * v19;
  outMatrix->v1.y = v20;
  LODWORD(outMatrix->v1.x) = v15;
  v21 = v17 * v19;
  v23 = (__m128)v15;
  outMatrix->v1.z = v21;
  v22 = (float)(v21 * outMatrix->v0.y) - (float)(v20 * outMatrix->v0.z);
  v23.m128_f32[0] = (float)(*(float *)&v15 * outMatrix->v0.z) - (float)(v21 * outMatrix->v0.x);
  v25 = v23;
  v24 = (float)(v20 * outMatrix->v0.x) - (float)(*(float *)&v15 * outMatrix->v0.y);
  v25.m128_f32[0] = (float)((float)(v23.m128_f32[0] * v23.m128_f32[0]) + (float)(v22 * v22)) + (float)(v24 * v24);
  if ( v25.m128_f32[0] == 0.0 )
    v26 = 0.0;
  else
    v26 = 1.0 / _mm_sqrt_ps(v25).m128_f32[0];
  outMatrix->v2.w = 0.0;
  outMatrix->v2.x = v22 * v26;
  outMatrix->v2.y = v23.m128_f32[0] * v26;
  outMatrix->v2.z = v24 * v26;
  y = this->m_vCornerPosition.y;
  z = this->m_vCornerPosition.z;
  x = this->m_vCornerPosition.x;
  outMatrix->v3.w = 1.0;
  outMatrix->v3.x = x;
  outMatrix->v3.y = y;
  outMatrix->v3.z = z;
}

// File Line: 125
// RVA: 0x44FDA0
void __fastcall UFG::DynamicCoverCorner::~DynamicCoverCorner(UFG::DynamicCoverCorner *this)
{
  UFG::CoverCorner *v2; // rdi
  UFG::qNode<UFG::CoverCorner,UFG::CoverCorner> *mPrev; // rdx
  UFG::qNode<UFG::CoverCorner,UFG::CoverCorner> *mNext; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::DynamicCoverComponent> *p_m_pParentInstance; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::DynamicCoverCorner>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::DynamicCoverCorner>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<UFG::CoverCorner,UFG::CoverCorner> *v12; // rcx
  UFG::qNode<UFG::CoverCorner,UFG::CoverCorner> *v13; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::DynamicCoverCorner>Vtbl *)&UFG::DynamicCoverCorner::`vftable;
  v2 = &this->UFG::CoverCorner;
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = &this->UFG::CoverCorner;
  this->mNext = &this->UFG::CoverCorner;
  p_m_pParentInstance = &this->m_pParentInstance;
  if ( this->m_pParentInstance.m_pPointer )
  {
    v6 = p_m_pParentInstance->mPrev;
    v7 = p_m_pParentInstance->mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    p_m_pParentInstance->mPrev = p_m_pParentInstance;
    p_m_pParentInstance->mNext = p_m_pParentInstance;
  }
  p_m_pParentInstance->m_pPointer = 0i64;
  v8 = p_m_pParentInstance->mPrev;
  v9 = p_m_pParentInstance->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  p_m_pParentInstance->mPrev = p_m_pParentInstance;
  p_m_pParentInstance->mNext = p_m_pParentInstance;
  this->vfptr = (UFG::qSafePointerNode<UFG::DynamicCoverCorner>Vtbl *)&UFG::qSafePointerNode<UFG::DynamicCoverCorner>::`vftable;
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull((UFG::qSafePointerNode<UFG::ParkourHandle> *)this);
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes((UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *)&this->m_SafePointerList);
  v10 = this->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::DynamicCoverCorner>::mPrev;
  v11 = this->m_SafePointerList.mNode.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  this->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::DynamicCoverCorner>::mPrev = &this->m_SafePointerList.mNode;
  this->m_SafePointerList.mNode.mNext = &this->m_SafePointerList.mNode;
  v12 = v2->mPrev;
  v13 = v2->mNext;
  v12->mNext = v13;
  v13->mPrev = v12;
  v2->mPrev = v2;
  v2->mNext = v2;
}

// File Line: 130
// RVA: 0x468D20
void __fastcall UFG::DynamicCoverCorner::Init(
        UFG::DynamicCoverCorner *this,
        UFG::DynamicCoverComponent *pParentInstance,
        unsigned int uGroupIndex)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::DynamicCoverComponent> *p_m_pParentInstance; // r10
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::SimComponent *m_pPointer; // rdx
  __int64 v8; // rdx
  float v9; // xmm1_4
  float v10; // xmm1_4

  p_m_pParentInstance = &this->m_pParentInstance;
  if ( this->m_pParentInstance.m_pPointer )
  {
    mPrev = p_m_pParentInstance->mPrev;
    mNext = this->m_pParentInstance.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pParentInstance->mPrev = p_m_pParentInstance;
    this->m_pParentInstance.mNext = &this->m_pParentInstance;
  }
  this->m_pParentInstance.m_pPointer = pParentInstance;
  if ( pParentInstance )
  {
    v6 = pParentInstance->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
    v6->mNext = p_m_pParentInstance;
    p_m_pParentInstance->mPrev = v6;
    this->m_pParentInstance.mNext = &pParentInstance->m_SafePointerList.mNode;
    pParentInstance->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = p_m_pParentInstance;
  }
  m_pPointer = this->m_pParentInstance.m_pPointer;
  this->m_uGroupIndex = uGroupIndex;
  if ( m_pPointer )
  {
    v8 = *(_QWORD *)(*(_QWORD *)&m_pPointer[1].m_Flags + 104i64) + 36i64 * uGroupIndex;
    if ( v8 )
    {
      this->m_eCoverSide.mValue = *(_BYTE *)(v8 + 24);
      this->m_fWallHeight = *(float *)(v8 + 28);
      v9 = *(float *)(v8 + 16);
      this->m_vWallNormal.x = *(float *)(v8 + 12);
      this->m_vWallNormal.y = v9;
      v10 = *(float *)(v8 + 8);
      *(_QWORD *)&this->m_vCornerPosition.x = *(_QWORD *)v8;
      this->m_vCornerPosition.z = v10;
    }
  }
  this->m_IsDynamic = 1;
}

