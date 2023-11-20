// File Line: 39
// RVA: 0x466080
UFG::qVector3 *__fastcall UFG::CoverCorner::GetAlongWall(UFG::CoverCorner *this, UFG::qVector3 *result)
{
  bool v2; // zf
  float v3; // xmm0_4
  UFG::qVector3 *v4; // rax
  float v5; // xmm0_4

  v2 = this->m_eCoverSide.mValue == 0;
  result->z = 0.0;
  if ( v2 )
  {
    v3 = this->m_vWallNormal.y;
    result->y = this->m_vWallNormal.x;
    v4 = result;
    LODWORD(result->x) = LODWORD(v3) ^ _xmm[0];
  }
  else
  {
    v5 = this->m_vWallNormal.x;
    result->x = this->m_vWallNormal.y;
    v4 = result;
    LODWORD(result->y) = LODWORD(v5) ^ _xmm[0];
  }
  return v4;
}

// File Line: 54
// RVA: 0x467E40
UFG::qVector3 *__fastcall UFG::CoverCorner::GetSyncPos(UFG::CoverCorner *this, UFG::qVector3 *result)
{
  float v2; // xmm5_4
  float v3; // xmm6_4
  float v4; // xmm3_4
  float v5; // xmm1_4
  UFG::qVector3 *v6; // rax
  float v7; // xmm2_4
  float v8; // xmm1_4

  v2 = this->m_vWallNormal.y;
  v3 = this->m_vWallNormal.x;
  if ( this->m_fWallHeight >= 1.5 )
  {
    if ( this->m_eCoverSide.mValue )
      LODWORD(v3) ^= _xmm[0];
    else
      LODWORD(v2) ^= _xmm[0];
    v4 = UFG::CoverCorner::ms_fHighSideOffset;
    v5 = UFG::CoverCorner::ms_fHighFrontOffset;
  }
  else
  {
    if ( this->m_eCoverSide.mValue )
      LODWORD(v3) ^= _xmm[0];
    else
      LODWORD(v2) ^= _xmm[0];
    v4 = UFG::CoverCorner::ms_fLowSideOffset;
    v5 = UFG::CoverCorner::ms_fLowFrontOffset;
  }
  v6 = result;
  v7 = (float)((float)(this->m_vWallNormal.y * v5) + this->m_vCornerPosition.y) + (float)(v3 * v4);
  result->x = (float)((float)(this->m_vWallNormal.x * v5) + this->m_vCornerPosition.x) + (float)(v2 * v4);
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
  float v3; // xmm3_4
  float v4; // xmm5_4
  float v5; // xmm6_4
  float v6; // xmm4_4
  UFG::qVector3 *v7; // rax
  float v8; // xmm0_4
  float v9; // xmm1_4

  if ( this->m_fWallHeight >= 1.5 )
    v2 = FLOAT_1_3;
  else
    v2 = FLOAT_0_89999998;
  v3 = this->m_vWallNormal.y;
  v4 = UFG::qVector3::msAxisZ.x * v2;
  v5 = UFG::qVector3::msAxisZ.y * v2;
  v6 = this->m_vWallNormal.x;
  if ( this->m_eCoverSide.mValue )
    LODWORD(v6) ^= _xmm[0];
  else
    LODWORD(v3) ^= _xmm[0];
  v7 = result;
  v8 = this->m_vCornerPosition.z + (float)(UFG::qVector3::msAxisZ.z * v2);
  v9 = (float)((float)((float)(this->m_vWallNormal.y * 0.5) + this->m_vCornerPosition.y) - (float)(v6 * 0.5)) + v5;
  result->x = (float)((float)((float)(this->m_vWallNormal.x * 0.5) + this->m_vCornerPosition.x) - (float)(v3 * 0.5))
            + v4;
  result->z = v8;
  result->y = v9;
  return v7;
}

// File Line: 80
// RVA: 0x467B60
UFG::qVector3 *__fastcall UFG::CoverCorner::GetSweetSpotDir(UFG::CoverCorner *this, UFG::qVector3 *result)
{
  bool v2; // zf
  UFG::qVector3 *v3; // rbx
  int v4; // xmm2_4
  float v5; // xmm2_4
  UFG::qVector3 source; // [rsp+20h] [rbp-18h]

  v2 = this->m_eCoverSide.mValue == 1;
  v3 = result;
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
  return v3;
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
  __m128 v8; // xmm8
  __m128 v9; // xmm2
  float v10; // xmm9_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  float v13; // xmm9_4
  float v14; // xmm2_4
  float v15; // xmm1_4
  __int128 v16; // xmm10
  float v17; // xmm8_4
  float v18; // xmm5_4
  float v19; // xmm2_4
  float v20; // xmm1_4
  float v21; // xmm8_4
  float v22; // xmm5_4
  float v23; // xmm7_4
  __m128 v24; // xmm9
  float v25; // xmm8_4
  __m128 v26; // xmm2
  float v27; // xmm4_4
  float v28; // xmm0_4
  float v29; // xmm1_4
  float v30; // eax

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
  v8 = (__m128)LODWORD(UFG::qVector3::msAxisZ.x);
  v9 = v8;
  v9.m128_f32[0] = (float)((float)(v8.m128_f32[0] * v8.m128_f32[0])
                         + (float)(UFG::qVector3::msAxisZ.y * UFG::qVector3::msAxisZ.y))
                 + (float)(UFG::qVector3::msAxisZ.z * UFG::qVector3::msAxisZ.z);
  if ( v9.m128_f32[0] == 0.0 )
    v10 = 0.0;
  else
    v10 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v9));
  v11 = v10;
  v12 = v10;
  v13 = v10 * UFG::qVector3::msAxisZ.z;
  v14 = v11 * UFG::qVector3::msAxisZ.x;
  v15 = v12 * UFG::qVector3::msAxisZ.y;
  v16 = v5;
  *(float *)&v16 = (float)(*(float *)&v5 * v15) - (float)(v7 * v13);
  v17 = (float)(v6 * v13) - (float)(*(float *)&v5 * v14);
  v18 = (float)(v7 * v14) - (float)(v6 * v15);
  v19 = (float)((float)(v17 * v17) + (float)(*(float *)&v16 * *(float *)&v16)) + (float)(v18 * v18);
  if ( v19 == 0.0 )
    v20 = 0.0;
  else
    v20 = 1.0 / fsqrt(v19);
  v21 = v17 * v20;
  outMatrix->v1.w = 0.0;
  *(float *)&v16 = *(float *)&v16 * v20;
  outMatrix->v1.y = v21;
  LODWORD(outMatrix->v1.x) = v16;
  v22 = v18 * v20;
  v24 = (__m128)v16;
  outMatrix->v1.z = v22;
  v23 = (float)(v22 * outMatrix->v0.y) - (float)(v21 * outMatrix->v0.z);
  v24.m128_f32[0] = (float)(*(float *)&v16 * outMatrix->v0.z) - (float)(v22 * outMatrix->v0.x);
  v26 = v24;
  v25 = (float)(v21 * outMatrix->v0.x) - (float)(*(float *)&v16 * outMatrix->v0.y);
  v26.m128_f32[0] = (float)((float)(v24.m128_f32[0] * v24.m128_f32[0]) + (float)(v23 * v23)) + (float)(v25 * v25);
  if ( v26.m128_f32[0] == 0.0 )
    v27 = 0.0;
  else
    v27 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v26));
  outMatrix->v2.w = 0.0;
  outMatrix->v2.x = v23 * v27;
  outMatrix->v2.y = v24.m128_f32[0] * v27;
  outMatrix->v2.z = v25 * v27;
  v28 = this->m_vCornerPosition.y;
  v29 = this->m_vCornerPosition.z;
  v30 = this->m_vCornerPosition.x;
  outMatrix->v3.w = 1.0;
  outMatrix->v3.x = v30;
  outMatrix->v3.y = v28;
  outMatrix->v3.z = v29;
}

// File Line: 125
// RVA: 0x44FDA0
void __fastcall UFG::DynamicCoverCorner::~DynamicCoverCorner(UFG::DynamicCoverCorner *this)
{
  UFG::qSafePointerNode<UFG::ParkourHandle> *v1; // rbx
  UFG::CoverCorner *v2; // rdi
  UFG::qNode<UFG::CoverCorner,UFG::CoverCorner> *v3; // rdx
  UFG::qNode<UFG::CoverCorner,UFG::CoverCorner> *v4; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::DynamicCoverComponent> *v5; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<UFG::CoverCorner,UFG::CoverCorner> *v12; // rcx
  UFG::qNode<UFG::CoverCorner,UFG::CoverCorner> *v13; // rax
  UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *v14; // [rsp+48h] [rbp+10h]

  v1 = (UFG::qSafePointerNode<UFG::ParkourHandle> *)this;
  this->vfptr = (UFG::qSafePointerNode<UFG::DynamicCoverCorner>Vtbl *)&UFG::DynamicCoverCorner::`vftable';
  v2 = (UFG::CoverCorner *)&this->mPrev;
  v3 = this->mPrev;
  v4 = this->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = (UFG::qNode<UFG::CoverCorner,UFG::CoverCorner> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::CoverCorner,UFG::CoverCorner> *)&v2->mPrev;
  v5 = &this->m_pParentInstance;
  if ( this->m_pParentInstance.m_pPointer )
  {
    v6 = v5->mPrev;
    v7 = v5->mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
    v5->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  }
  v5->m_pPointer = 0i64;
  v8 = v5->mPrev;
  v9 = v5->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v5->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v1->vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)&UFG::qSafePointerNode<UFG::DynamicCoverCorner>::`vftable';
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull(v1);
  v14 = &v1->m_SafePointerList;
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes(&v1->m_SafePointerList);
  v10 = v1->m_SafePointerList.mNode.mPrev;
  v11 = v1->m_SafePointerList.mNode.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v14->mNode.mPrev = &v14->mNode;
  v14->mNode.mNext = &v14->mNode;
  v12 = v2->mPrev;
  v13 = v2->mNext;
  v12->mNext = v13;
  v13->mPrev = v12;
  v2->mPrev = (UFG::qNode<UFG::CoverCorner,UFG::CoverCorner> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::CoverCorner,UFG::CoverCorner> *)&v2->mPrev;
}

// File Line: 130
// RVA: 0x468D20
void __fastcall UFG::DynamicCoverCorner::Init(UFG::DynamicCoverCorner *this, UFG::DynamicCoverComponent *pParentInstance, unsigned int uGroupIndex)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // r10
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::SimComponent *v7; // rdx
  signed __int64 v8; // rdx
  float v9; // xmm1_4
  float v10; // eax
  float v11; // xmm1_4

  v3 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&this->m_pParentInstance.mPrev;
  if ( this->m_pParentInstance.m_pPointer )
  {
    v4 = v3->mPrev;
    v5 = this->m_pParentInstance.mNext;
    v4->mNext = v5;
    v5->mPrev = v4;
    v3->mPrev = v3;
    this->m_pParentInstance.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&this->m_pParentInstance.mPrev;
  }
  this->m_pParentInstance.m_pPointer = (UFG::SimComponent *)&pParentInstance->vfptr;
  if ( pParentInstance )
  {
    v6 = pParentInstance->m_SafePointerList.mNode.mPrev;
    v6->mNext = v3;
    v3->mPrev = v6;
    this->m_pParentInstance.mNext = &pParentInstance->m_SafePointerList.mNode;
    pParentInstance->m_SafePointerList.mNode.mPrev = v3;
  }
  v7 = this->m_pParentInstance.m_pPointer;
  this->m_uGroupIndex = uGroupIndex;
  if ( v7 )
  {
    v8 = *(_QWORD *)(*(_QWORD *)&v7[1].m_Flags + 104i64) + 36i64 * uGroupIndex;
    if ( v8 )
    {
      this->m_eCoverSide.mValue = *(_BYTE *)(v8 + 24);
      this->m_fWallHeight = *(float *)(v8 + 28);
      v9 = *(float *)(v8 + 16);
      this->m_vWallNormal.x = *(float *)(v8 + 12);
      this->m_vWallNormal.y = v9;
      v10 = *(float *)v8;
      v11 = *(float *)(v8 + 8);
      this->m_vCornerPosition.y = *(float *)(v8 + 4);
      this->m_vCornerPosition.x = v10;
      this->m_vCornerPosition.z = v11;
    }
  }
  this->m_IsDynamic = 1;
}

