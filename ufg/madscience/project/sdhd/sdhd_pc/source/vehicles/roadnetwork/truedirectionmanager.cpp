// File Line: 25
// RVA: 0x643220
void __fastcall UFG::TrueDirectionManager::TrueDirectionManager(UFG::TrueDirectionManager *this)
{
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::SimComponent *v3; // rdi
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_mEffectTransform; // rbx
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v6; // rax
  UFG::SimComponent *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax

  y = UFG::qVector3::msDirFront.y;
  z = UFG::qVector3::msDirFront.z;
  this->mPathForward.x = UFG::qVector3::msDirFront.x;
  this->mPathForward.y = y;
  this->mPathForward.z = z;
  v3 = 0i64;
  this->mEffectHash = 0;
  this->mEffectId = -1;
  this->mEffectOverride.m_pPointer = 0i64;
  p_mEffectTransform = &this->mEffectTransform;
  this->mEffectTransform.mPrev = &this->mEffectTransform;
  this->mEffectTransform.mNext = &this->mEffectTransform;
  this->mEffectTransform.m_pPointer = 0i64;
  this->mCurrentLane = 0i64;
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v6 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x110ui64, "TrueDirectionManager.mEffectTransform", 0i64, 1u);
  if ( v6 )
  {
    UFG::TransformNodeComponent::TransformNodeComponent((UFG::TransformNodeComponent *)v6, 0x17u, 0i64, 0);
    v3 = v7;
  }
  if ( p_mEffectTransform->m_pPointer )
  {
    mPrev = p_mEffectTransform->mPrev;
    mNext = p_mEffectTransform->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mEffectTransform->mPrev = p_mEffectTransform;
    p_mEffectTransform->mNext = p_mEffectTransform;
  }
  p_mEffectTransform->m_pPointer = v3;
  if ( v3 )
  {
    v10 = v3->m_SafePointerList.mNode.mPrev;
    v10->mNext = p_mEffectTransform;
    p_mEffectTransform->mPrev = v10;
    p_mEffectTransform->mNext = &v3->m_SafePointerList.mNode;
    v3->m_SafePointerList.mNode.mPrev = p_mEffectTransform;
  }
}

// File Line: 87
// RVA: 0x65F9C0
void __fastcall UFG::TrueDirectionManager::Update(UFG::TrueDirectionManager *this)
{
  UFG::RoadNetworkLane *mTrueDirectionIntersectionLane; // rdi
  const char *EffectName; // rax

  mTrueDirectionIntersectionLane = 0i64;
  if ( UFG::UIHKScreenHud::getInstance()
    && (mTrueDirectionIntersectionLane = UFG::UIHKScreenHud::GPS->mTrueDirectionIntersectionLane) != 0i64 )
  {
    if ( this->mEffectId != -1 )
    {
      EffectName = UFG::TrueDirectionManager::GetEffectName(this);
      if ( this->mEffectHash != (unsigned int)UFG::qStringHashUpper32(EffectName, -1)
        || this->mCurrentLane != mTrueDirectionIntersectionLane )
      {
        UFG::TrueDirectionManager::KillEffects(this);
      }
    }
    UFG::TrueDirectionManager::UpdateEffectLocation(this, mTrueDirectionIntersectionLane);
    if ( this->mEffectId == -1 )
      UFG::TrueDirectionManager::StartEffects(this);
    UFG::TrueDirectionManager::UpdateEffectFade(this);
  }
  else if ( this->mEffectId != -1 )
  {
    UFG::TrueDirectionManager::KillEffects(this);
  }
  if ( this->mCurrentLane != mTrueDirectionIntersectionLane )
    this->mCurrentLane = mTrueDirectionIntersectionLane;
}

// File Line: 125
// RVA: 0x652490
void __fastcall UFG::TrueDirectionManager::KillEffects(UFG::TrueDirectionManager *this)
{
  Render::FXOverride *m_pPointer; // rax
  Render::FXOverride *v3; // rdi

  Render::FXManager::KillEffect(&Render::gFXManager, this->mEffectId, FXKILLOPTION_ERASE_EMITTED_OBJECTS);
  this->mEffectId = -1;
  m_pPointer = this->mEffectOverride.m_pPointer;
  if ( m_pPointer )
  {
    --m_pPointer->mReferenceCount;
    v3 = this->mEffectOverride.m_pPointer;
    if ( v3->mReferenceCount <= 0 )
    {
      if ( v3 )
      {
        Render::FXOverride::~FXOverride(this->mEffectOverride.m_pPointer);
        operator delete[](v3);
      }
      this->mEffectOverride.m_pPointer = 0i64;
    }
    this->mEffectOverride.m_pPointer = 0i64;
  }
}

// File Line: 132
// RVA: 0x65AE10
void __fastcall UFG::TrueDirectionManager::StartEffects(UFG::TrueDirectionManager *this)
{
  const char *EffectName; // rax
  UFG::allocator::free_link *Override; // rax

  EffectName = UFG::TrueDirectionManager::GetEffectName(this);
  this->mEffectHash = UFG::qStringHashUpper32(EffectName, -1);
  Override = Render::FXOverride::CreateOverride("TrueDirectionManager Override", 0i64);
  FX::SharedPointer<Render::FXOverride>::Set(&this->mEffectOverride, (Render::FXOverride *)Override);
  this->mEffectId = Render::FXManager::CreateEffect(
                      &Render::gFXManager,
                      this->mEffectHash,
                      (UFG::TransformNodeComponent *)this->mEffectTransform.m_pPointer,
                      0xFFFFFFFF,
                      this->mEffectOverride.m_pPointer);
}

// File Line: 140
// RVA: 0x661500
void __fastcall UFG::TrueDirectionManager::UpdateEffectLocation(
        UFG::TrueDirectionManager *this,
        UFG::RoadNetworkLane *roadLane)
{
  bool mTrueDirectionHighwayRamp; // r14
  int *v5; // rdi
  UFG::RoadNetworkNode *v6; // rcx
  __m128 y_low; // xmm7
  float v8; // xmm14_4
  __m128 v9; // xmm15
  float v10; // xmm1_4
  __int64 mOffset; // rax
  float v12; // xmm6_4
  float v13; // xmm8_4
  UFG::qVector3 *Pos; // rax
  float y; // xmm4_4
  float z; // xmm5_4
  __m128 x_low; // xmm9
  float v18; // xmm10_4
  float v19; // xmm12_4
  float v20; // xmm1_4
  float v21; // xmm6_4
  float v22; // xmm7_4
  float v23; // xmm8_4
  __m128 v24; // xmm2
  __m128 v25; // xmm1
  float v26; // xmm3_4
  float v27; // xmm2_4
  float v28; // xmm3_4
  __m128 v29; // xmm4
  float v30; // xmm3_4
  float v31; // xmm1_4
  float v32; // xmm5_4
  __m128 v33; // xmm9
  float v34; // xmm2_4
  __m128 v35; // xmm3
  float v36; // xmm1_4
  __m128 v37; // xmm7
  __m128 v38; // xmm6
  __m128 v39; // xmm5
  float v40; // xmm9_4
  float v41; // xmm10_4
  float v42; // xmm8_4
  __m128 v43; // xmm0
  float v44; // xmm4_4
  __m128 v45; // xmm3
  float v46; // xmm5_4
  float v47; // xmm2_4
  float v48; // xmm15_4
  float v49; // xmm11_4
  UFG::qMatrix44 *v50; // rax
  __m128 v51; // xmm1
  __m128 v52; // xmm0
  UFG::qVector4 v53; // xmm1
  UFG::qMatrix44 *v54; // rax
  __m128 v55; // xmm1
  __m128 v56; // xmm0
  UFG::qVector4 v57; // xmm1
  UFG::qMatrix44 *v58; // rax
  UFG::qVector4 v59; // xmm2
  UFG::qVector4 v60; // xmm1
  UFG::qVector4 v61; // xmm0
  float v62; // xmm0_4
  float v63; // xmm1_4
  UFG::TransformNodeComponent *m_pPointer; // rcx
  __m128 b; // [rsp+20h] [rbp-B8h] BYREF
  __m128 b_16; // [rsp+30h] [rbp-A8h]
  __m128 b_32; // [rsp+40h] [rbp-98h]
  _BYTE b_48[48]; // [rsp+50h] [rbp-88h] BYREF
  UFG::qVector3 m_32; // [rsp+80h] [rbp-58h] BYREF
  UFG::qVector3 m_48; // [rsp+90h] [rbp-48h] BYREF
  UFG::qVector3 axis; // [rsp+A0h] [rbp-38h] BYREF
  UFG::qVector3 result; // [rsp+B0h] [rbp-28h] BYREF
  UFG::qMatrix44 dest; // [rsp+C8h] [rbp-10h] BYREF
  UFG::qMatrix44 v74; // [rsp+108h] [rbp+30h] BYREF
  float v75; // [rsp+218h] [rbp+140h]
  float v76; // [rsp+220h] [rbp+148h]
  float v77; // [rsp+228h] [rbp+150h]
  float vars0; // [rsp+230h] [rbp+158h]

  mTrueDirectionHighwayRamp = 0;
  if ( UFG::UIHKScreenHud::getInstance() )
    mTrueDirectionHighwayRamp = UFG::UIHKScreenHud::GPS->mTrueDirectionHighwayRamp;
  v5 = 0i64;
  v6 = (UFG::RoadNetworkNode *)((char *)roadLane + roadLane->mNode.mOffset);
  if ( !roadLane->mNode.mOffset )
    v6 = 0i64;
  UFG::RoadNetworkNode::GetTangent(v6, &result, roadLane->mLaneIndex, 1.0);
  y_low = (__m128)LODWORD(result.y);
  v8 = 0.0;
  v9 = (__m128)(unsigned int)FLOAT_1_0;
  if ( (float)((float)((float)(result.x * result.x) + (float)(y_low.m128_f32[0] * y_low.m128_f32[0]))
             + (float)(result.z * result.z)) == 0.0 )
    v10 = 0.0;
  else
    v10 = 1.0 / _mm_sqrt_ps((__m128)LODWORD(result.x)).m128_f32[0];
  mOffset = roadLane->mNode.mOffset;
  v12 = result.x * v10;
  y_low.m128_f32[0] = result.y * v10;
  vars0 = result.x * v10;
  *(float *)&b_48[40] = result.y * v10;
  v13 = result.z * v10;
  *(float *)&b_48[44] = result.z * v10;
  if ( mOffset )
    v5 = (int *)((char *)roadLane + mOffset);
  v75 = *((float *)v5 + 3);
  v76 = *((float *)v5 + 4);
  v77 = *((float *)v5 + 5);
  if ( mTrueDirectionHighwayRamp )
  {
    Pos = UFG::RoadNetworkLane::GetPos(roadLane, &m_32, 1.0);
    y = UFG::qVector3::msDirUp.y;
    z = UFG::qVector3::msDirUp.z;
    x_low = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
    v18 = Pos->z;
    v9 = (__m128)(unsigned int)FLOAT_1_0;
    v19 = Pos->y + (float)((float)(v12 * UFG::qVector3::msDirUp.z) - (float)(v13 * UFG::qVector3::msDirUp.x));
    v75 = Pos->x
        + (float)((float)(v13 * UFG::qVector3::msDirUp.y) - (float)(y_low.m128_f32[0] * UFG::qVector3::msDirUp.z));
    v76 = v19;
    v77 = (float)(v18 + 3.5)
        + (float)((float)(y_low.m128_f32[0] * UFG::qVector3::msDirUp.x) - (float)(v12 * UFG::qVector3::msDirUp.y));
  }
  else
  {
    y = UFG::qVector3::msDirUp.y;
    z = UFG::qVector3::msDirUp.z;
    x_low = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
  }
  *(_QWORD *)&b_48[40] = *(_QWORD *)&UFG::qMatrix44::msIdentity.v1.z;
  *(UFG::qVector4 *)&b_48[8] = UFG::qMatrix44::msIdentity.v2;
  *(UFG::qVector4 *)&b_48[24] = UFG::qMatrix44::msIdentity.v3;
  if ( (float)((float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v12 * v12)) + (float)(v13 * v13)) == 0.0 )
    v20 = 0.0;
  else
    v20 = v9.m128_f32[0] / _mm_sqrt_ps(y_low).m128_f32[0];
  v21 = v12 * v20;
  v22 = y_low.m128_f32[0] * v20;
  v23 = v13 * v20;
  b.m128_u64[0] = __PAIR64__(LODWORD(v22), LODWORD(v21));
  b.m128_u64[1] = LODWORD(v23);
  if ( (float)((float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(y * y)) + (float)(z * z)) == 0.0 )
  {
    v24 = 0i64;
  }
  else
  {
    v24 = v9;
    v24.m128_f32[0] = v9.m128_f32[0] / _mm_sqrt_ps(x_low).m128_f32[0];
  }
  v25 = v24;
  v26 = v24.m128_f32[0];
  v27 = v24.m128_f32[0] * z;
  v25.m128_f32[0] = v25.m128_f32[0] * y;
  v28 = v26 * x_low.m128_f32[0];
  v29 = v25;
  v29.m128_f32[0] = (float)(v25.m128_f32[0] * v23) - (float)(v27 * v22);
  v24.m128_f32[0] = (float)(v27 * v21) - (float)(v28 * v23);
  v30 = (float)(v28 * v22) - (float)(v25.m128_f32[0] * v21);
  if ( (float)((float)((float)(v24.m128_f32[0] * v24.m128_f32[0]) + (float)(v29.m128_f32[0] * v29.m128_f32[0]))
             + (float)(v30 * v30)) == 0.0 )
    v31 = 0.0;
  else
    v31 = v9.m128_f32[0] / _mm_sqrt_ps(v24).m128_f32[0];
  v29.m128_f32[0] = v29.m128_f32[0] * v31;
  b_16.m128_i32[3] = 0;
  b_16.m128_f32[2] = v30 * v31;
  b_16.m128_f32[1] = v24.m128_f32[0] * v31;
  b_16.m128_i32[0] = v29.m128_i32[0];
  v33 = v29;
  v32 = (float)((float)(v30 * v31) * v22) - (float)((float)(v24.m128_f32[0] * v31) * v23);
  v33.m128_f32[0] = (float)(v29.m128_f32[0] * v23) - (float)((float)(v30 * v31) * v21);
  v34 = (float)((float)(v24.m128_f32[0] * v31) * v21) - (float)(v29.m128_f32[0] * v22);
  v35 = v33;
  v35.m128_f32[0] = (float)((float)(v33.m128_f32[0] * v33.m128_f32[0]) + (float)(v32 * v32)) + (float)(v34 * v34);
  if ( v35.m128_f32[0] == 0.0 )
    v36 = 0.0;
  else
    v36 = v9.m128_f32[0] / _mm_sqrt_ps(v35).m128_f32[0];
  v37 = *(__m128 *)&b_48[8];
  b_32.m128_i32[3] = 0;
  *(_DWORD *)&b_48[12] = 1065353216;
  *(UFG::qVector3 *)b_48 = UFG::qVector3::msZero;
  b_32.m128_f32[0] = v32 * v36;
  b_32.m128_f32[1] = v33.m128_f32[0] * v36;
  b_32.m128_f32[2] = v34 * v36;
  v38 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&b_48[16], *(__m128 *)&b_48[16], 0), b), (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&b_48[16], *(__m128 *)&b_48[16], 85), b_16)),
            _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&b_48[16], *(__m128 *)&b_48[16], 170), b_32)),
          _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&b_48[16], *(__m128 *)&b_48[16], 255), *(__m128 *)b_48));
  v39 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&b_48[32], *(__m128 *)&b_48[32], 0), b), (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&b_48[32], *(__m128 *)&b_48[32], 85), b_16)),
            _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&b_48[32], *(__m128 *)&b_48[32], 170), b_32)),
          _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&b_48[32], *(__m128 *)&b_48[32], 255), *(__m128 *)b_48));
  v40 = *(float *)&b_48[40];
  v41 = *(float *)&b_48[44];
  v42 = vars0;
  v45 = (__m128)LODWORD(vars0);
  v43 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&b_48[24], *(__m128 *)&b_48[24], 85), b_16),
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&b_48[24], *(__m128 *)&b_48[24], 0), b), (__m128)0i64)),
            _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&b_48[24], *(__m128 *)&b_48[24], 170), b_32)),
          _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&b_48[24], *(__m128 *)&b_48[24], 255), *(__m128 *)b_48));
  *(_QWORD *)&b_48[8] = _mm_add_ps(
                          _mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v37, v37, 0), b), (__m128)0i64),
                              _mm_mul_ps(_mm_shuffle_ps(v37, v37, 85), b_16)),
                            _mm_mul_ps(_mm_shuffle_ps(v37, v37, 170), b_32)),
                          _mm_mul_ps(_mm_shuffle_ps(v37, v37, 255), *(__m128 *)b_48)).m128_u64[0];
  *(_QWORD *)&b_48[40] = v39.m128_u64[1];
  *(_QWORD *)&b_48[32] = v43.m128_u64[1];
  *(__m128 *)&b_48[16] = v38;
  m_48.x = vars0;
  v44 = (float)(v41 * UFG::qVector3::msDirUp.y) - (float)(v40 * UFG::qVector3::msDirUp.z);
  m_48.y = v40;
  m_48.z = v41;
  v45.m128_f32[0] = (float)(vars0 * UFG::qVector3::msDirUp.z) - (float)(v41 * UFG::qVector3::msDirUp.x);
  v46 = (float)(v40 * UFG::qVector3::msDirUp.x) - (float)(vars0 * UFG::qVector3::msDirUp.y);
  v47 = (float)((float)(v45.m128_f32[0] * v45.m128_f32[0]) + (float)(v44 * v44)) + (float)(v46 * v46);
  if ( v47 >= 0.001 )
  {
    if ( v47 == 0.0 )
      v48 = 0.0;
    else
      v48 = v9.m128_f32[0] / _mm_sqrt_ps(v45).m128_f32[0];
    v49 = FLOAT_90_0;
    m_32.y = v45.m128_f32[0] * v48;
    m_32.x = v44 * v48;
    m_32.z = v46 * v48;
    axis.y = (float)((float)(v44 * v48) * v41) - (float)((float)(v46 * v48) * vars0);
    axis.x = (float)((float)(v46 * v48) * v40) - (float)((float)(v45.m128_f32[0] * v48) * v41);
    axis.z = (float)((float)(v45.m128_f32[0] * v48) * vars0) - (float)((float)(v44 * v48) * v40);
    if ( mTrueDirectionHighwayRamp )
    {
      v49 = 0.0;
      v8 = FLOAT_N90_0;
    }
    UFG::qRotationMatrixAxis(&dest, &axis, 1.5707964);
    b = (__m128)dest.v0;
    b_16 = (__m128)dest.v1;
    b_32 = (__m128)dest.v2;
    *(UFG::qVector4 *)b_48 = dest.v3;
    UFG::qRotationMatrixAxis(&dest, &m_48, (float)(v49 * 3.1415927) * 0.0055555557);
    v50 = UFG::qMatrix44::operator*((UFG::qMatrix44 *)&b, &v74, &dest);
    v51 = (__m128)v50->v1;
    b = (__m128)v50->v0;
    v52 = (__m128)v50->v2;
    b_16 = v51;
    v53 = v50->v3;
    b_32 = v52;
    *(UFG::qVector4 *)b_48 = v53;
    UFG::qRotationMatrixAxis(&dest, &m_32, (float)(v8 * 3.1415927) * 0.0055555557);
    v54 = UFG::qMatrix44::operator*((UFG::qMatrix44 *)&b, &v74, &dest);
    v55 = (__m128)v54->v1;
    b = (__m128)v54->v0;
    v56 = (__m128)v54->v2;
    b_16 = v55;
    v57 = v54->v3;
    b_32 = v56;
    *(UFG::qVector4 *)b_48 = v57;
    v58 = UFG::qMatrix44::operator*((UFG::qMatrix44 *)&b_48[16], &v74, (UFG::qMatrix44 *)&b);
    v59 = v58->v2;
    v60 = v58->v3;
    v61 = v58->v0;
    *(_QWORD *)&b_48[40] = *(_QWORD *)&v58->v1.z;
    *(_QWORD *)&b_48[8] = *(_QWORD *)&v59.x;
    *(_QWORD *)&b_48[16] = *(_QWORD *)&v61.x;
    *(UFG::qVector4 *)&b_48[24] = v60;
  }
  v62 = v75;
  v63 = v76;
  this->mPathForward.x = v42;
  *(_DWORD *)&b_48[36] = 1065353216;
  this->mPathForward.y = v40;
  this->mPathForward.z = v41;
  *(float *)&b_48[24] = v62;
  m_pPointer = (UFG::TransformNodeComponent *)this->mEffectTransform.m_pPointer;
  *(float *)&b_48[28] = v63;
  *(float *)&b_48[32] = v77;
  if ( m_pPointer )
    UFG::TransformNodeComponent::SetWorldTransform(m_pPointer, (UFG::qMatrix44 *)&b_48[16]);
}

// File Line: 241
// RVA: 0x661190
void __fastcall UFG::TrueDirectionManager::UpdateEffectFade(UFG::TrueDirectionManager *this)
{
  bool mTrueDirectionHighwayRamp; // si
  UFG::TransformNodeComponent *m_pPointer; // rbx
  float z; // xmm8_4
  float x; // xmm14_4
  float y; // xmm15_4
  UFG::Camera *v7; // rbx
  UFG::BaseCameraComponent *mCurrentCamera; // rax
  UFG::Camera *p_mCamera; // rax
  float v10; // xmm10_4
  __m128 y_low; // xmm7
  float v12; // xmm11_4
  float v13; // xmm1_4
  float v14; // xmm6_4
  UFG::BaseCameraComponent *v15; // rcx
  int v16; // xmm12_4
  int v17; // xmm13_4
  float v18; // xmm9_4
  float v19; // xmm5_4
  float v20; // xmm8_4
  __m128 v21; // xmm3
  float v22; // xmm4_4
  float v23; // xmm9_4
  float v24; // xmm5_4
  float v25; // xmm4_4
  float v26; // xmm3_4
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  float v28; // xmm3_4
  float v29; // xmm0_4
  float v30; // xmm0_4
  Render::FXOverride *v31; // rax
  float v32; // [rsp+D0h] [rbp+8h]

  mTrueDirectionHighwayRamp = 0;
  if ( UFG::UIHKScreenHud::getInstance() )
    mTrueDirectionHighwayRamp = UFG::UIHKScreenHud::GPS->mTrueDirectionHighwayRamp;
  m_pPointer = (UFG::TransformNodeComponent *)this->mEffectTransform.m_pPointer;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pPointer);
  z = m_pPointer->mWorldTransform.v3.z;
  x = m_pPointer->mWorldTransform.v3.x;
  y = m_pPointer->mWorldTransform.v3.y;
  v32 = z;
  v7 = 0i64;
  mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
  if ( mCurrentCamera )
    p_mCamera = &mCurrentCamera->mCamera;
  else
    p_mCamera = 0i64;
  v10 = p_mCamera->mTransformation.v3.x;
  y_low = (__m128)LODWORD(p_mCamera->mTransformation.v3.y);
  v12 = p_mCamera->mTransformation.v3.z;
  if ( this->mEffectId != -1 )
  {
    v13 = *(float *)&FLOAT_1_0;
    v14 = *(float *)&FLOAT_1_0;
    if ( !mTrueDirectionHighwayRamp )
    {
      v15 = UFG::Director::Get()->mCurrentCamera;
      if ( v15 )
        v7 = &v15->mCamera;
      v16 = LODWORD(v7->mTransformation.v2.x) ^ _xmm[0];
      v17 = LODWORD(v7->mTransformation.v2.y) ^ _xmm[0];
      v18 = this->mPathForward.x;
      v19 = this->mPathForward.y;
      v20 = (float)(*(float *)&v17 * *(float *)&v17) + (float)(*(float *)&v16 * *(float *)&v16);
      if ( v20 >= 0.0000010000001 )
      {
        v21 = (__m128)LODWORD(this->mPathForward.y);
        v21.m128_f32[0] = (float)(v19 * v19) + (float)(v18 * v18);
        v13 = *(float *)&FLOAT_1_0;
        if ( v21.m128_f32[0] >= 0.0000010000001 )
        {
          if ( v21.m128_f32[0] == 0.0 )
            v22 = 0.0;
          else
            v22 = 1.0 / _mm_sqrt_ps(v21).m128_f32[0];
          v23 = v18 * v22;
          v24 = v19 * v22;
          v25 = v22 * 0.0;
          if ( v20 == 0.0 )
            v26 = 0.0;
          else
            v26 = 1.0 / fsqrt(v20);
          v14 = 1.0
              - (float)((float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(
                                               (float)((float)(v24 * (float)(*(float *)&v17 * v26))
                                                     + (float)(v23 * (float)(*(float *)&v16 * v26)))
                                             + (float)((float)(v26 * 0.0) * v25)) & _xmm)
                              - 0.60000002)
                      * 10.000004);
          if ( v14 <= 0.0 )
          {
            v14 = 0.0;
          }
          else if ( v14 >= 1.0 )
          {
            z = v32;
            v14 = *(float *)&FLOAT_1_0;
            goto LABEL_25;
          }
          z = v32;
          goto LABEL_25;
        }
      }
      else
      {
        v13 = *(float *)&FLOAT_1_0;
        v14 = 0.0;
      }
      z = v32;
    }
LABEL_25:
    if ( LocalPlayer )
    {
      m_pTransformNodeComponent = LocalPlayer->m_pTransformNodeComponent;
      if ( m_pTransformNodeComponent )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
        v10 = m_pTransformNodeComponent->mWorldTransform.v3.x;
        y_low = (__m128)LODWORD(m_pTransformNodeComponent->mWorldTransform.v3.y);
        v12 = m_pTransformNodeComponent->mWorldTransform.v3.z;
        v13 = *(float *)&FLOAT_1_0;
      }
    }
    y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - y) * (float)(y_low.m128_f32[0] - y))
                              + (float)((float)(v10 - x) * (float)(v10 - x)))
                      + (float)((float)(v12 - z) * (float)(v12 - z));
    v28 = _mm_sqrt_ps(y_low).m128_f32[0];
    v29 = (float)(v28 - 10.0) * 0.06666667;
    if ( v29 <= 0.0 )
    {
      v29 = 0.0;
    }
    else if ( v29 >= v13 )
    {
      v29 = v13;
    }
    if ( v14 >= v29 )
      v14 = v29;
    v30 = v13 - (float)((float)(v28 - 130.0) * 0.025);
    if ( v30 <= 0.0 )
    {
      v30 = 0.0;
    }
    else if ( v30 >= v13 )
    {
      goto LABEL_39;
    }
    v13 = v30;
LABEL_39:
    if ( v14 >= v13 )
      v14 = v13;
    v31 = this->mEffectOverride.m_pPointer;
    if ( v31 )
      v31->stateBlock.ColorTint[3] = v14;
  }
}

// File Line: 304
// RVA: 0x64DDA0
const char *__fastcall UFG::TrueDirectionManager::GetEffectName(UFG::TrueDirectionManager *this)
{
  bool mTrueDirectionHighwayRamp; // bl
  const char *v2; // r8
  unsigned int v3; // r9d
  int v4; // ecx
  const char *v6; // rax

  mTrueDirectionHighwayRamp = 0;
  if ( UFG::UIHKScreenHud::getInstance() )
    mTrueDirectionHighwayRamp = UFG::UIHKScreenHud::GPS->mTrueDirectionHighwayRamp;
  v2 = "GPS_Generic_Effect";
  v3 = (int)(float)(UFG::UITiledMapWidget::GPSLineColor.r * 255.0) | (((int)(float)(UFG::UITiledMapWidget::GPSLineColor.g
                                                                                  * 255.0) | (((int)(float)(UFG::UITiledMapWidget::GPSLineColor.b * 255.0) | 0xFFFFFF00) << 8)) << 8);
  v4 = (int)(float)(UFG::UITiledMapWidget::DefaultGPSLineColor.r * 255.0) | (((int)(float)(UFG::UITiledMapWidget::DefaultGPSLineColor.g
                                                                                         * 255.0) | (((int)(float)(UFG::UITiledMapWidget::DefaultGPSLineColor.b * 255.0) | ((int)(float)(UFG::UITiledMapWidget::DefaultGPSLineColor.a * 255.0) << 8)) << 8)) << 8);
  if ( mTrueDirectionHighwayRamp )
  {
    v2 = "GPS_Generic_Vertical_Effect";
    if ( v3 != v4 )
    {
      if ( v3 == ((int)(float)(UFG::ObjectiveGreen.r * 255.0) | (((int)(float)(UFG::ObjectiveGreen.g * 255.0) | (((int)(float)(UFG::ObjectiveGreen.b * 255.0) | ((int)(float)(UFG::ObjectiveGreen.a * 255.0) << 8)) << 8)) << 8)) )
        return "GPS_Mission_Vertical_Effect";
      if ( v3 == ((int)(float)(UFG::ObjectiveBlue.r * 255.0) | (((int)(float)(UFG::ObjectiveBlue.g * 255.0) | (((int)(float)(UFG::ObjectiveBlue.b * 255.0) | ((int)(float)(UFG::ObjectiveBlue.a * 255.0) << 8)) << 8)) << 8)) )
        return "GPS_Case_Vertical_Effect";
      if ( v3 == ((int)(float)(UFG::ObjectiveOrange.r * 255.0) | (((int)(float)(UFG::ObjectiveOrange.g * 255.0) | (((int)(float)(UFG::ObjectiveOrange.b * 255.0) | ((int)(float)(UFG::ObjectiveOrange.a * 255.0) << 8)) << 8)) << 8)) )
        return "GPS_Race_Vertical_Effect";
      if ( v3 == ((int)(float)(UFG::ObjectiveYellow.r * 255.0) | (((int)(float)(UFG::ObjectiveYellow.g * 255.0) | (((int)(float)(UFG::ObjectiveYellow.b * 255.0) | ((int)(float)(UFG::ObjectiveYellow.a * 255.0) << 8)) << 8)) << 8)) )
        return "GPS_Event_Vertical_Effect";
      if ( v3 == ((int)(float)(UFG::ObjectiveRed.r * 255.0) | (((int)(float)(UFG::ObjectiveRed.g * 255.0) | (((int)(float)(UFG::ObjectiveRed.b * 255.0) | ((int)(float)(UFG::ObjectiveRed.a * 255.0) << 8)) << 8)) << 8)) )
        return "GPS_Enemy_Vertical_Effect";
      if ( v3 == ((int)(float)(UFG::CharacterGold.r * 255.0) | (((int)(float)(UFG::CharacterGold.g * 255.0) | (((int)(float)(UFG::CharacterGold.b * 255.0) | ((int)(float)(UFG::CharacterGold.a * 255.0) << 8)) << 8)) << 8)) )
        return "GPS_Event_Vertical_Effect";
      if ( v3 == ((int)(float)(UFG::AmbientBlue.r * 255.0) | (((int)(float)(UFG::AmbientBlue.g * 255.0) | (((int)(float)(UFG::AmbientBlue.b * 255.0) | ((int)(float)(UFG::AmbientBlue.a * 255.0) << 8)) << 8)) << 8)) )
        return "GPS_Drug_Vertical_Effect";
      if ( v3 == ((int)(float)(UFG::CharacterPink.r * 255.0) | (((int)(float)(UFG::CharacterPink.g * 255.0) | (((int)(float)(UFG::CharacterPink.b * 255.0) | ((int)(float)(UFG::CharacterPink.a * 255.0) << 8)) << 8)) << 8)) )
        return "GPS_Date_Vertical_Effect";
      if ( v3 == ((int)(float)(UFG::TransTerrorOrange.r * 255.0) | (((int)(float)(UFG::TransTerrorOrange.g * 255.0) | (((int)(float)(UFG::TransTerrorOrange.b * 255.0) | ((int)(float)(UFG::TransTerrorOrange.a * 255.0) << 8)) << 8)) << 8))
        || v3 == ((int)(float)(UFG::ZodiacOrange.r * 255.0) | (((int)(float)(UFG::ZodiacOrange.g * 255.0) | (((int)(float)(UFG::ZodiacOrange.b * 255.0) | ((int)(float)(UFG::ZodiacOrange.a * 255.0) << 8)) << 8)) << 8)) )
      {
        return "GPS_Race_Vertical_Effect";
      }
      if ( v3 == ((int)(float)(UFG::ExoticVendorGold.r * 255.0) | (((int)(float)(UFG::ExoticVendorGold.g * 255.0) | (((int)(float)(UFG::ExoticVendorGold.b * 255.0) | ((int)(float)(UFG::ExoticVendorGold.a * 255.0) << 8)) << 8)) << 8)) )
        return "GPS_Event_Vertical_Effect";
    }
  }
  else if ( v3 != v4 )
  {
    if ( v3 == ((int)(float)(UFG::ObjectiveGreen.r * 255.0) | (((int)(float)(UFG::ObjectiveGreen.g * 255.0) | (((int)(float)(UFG::ObjectiveGreen.b * 255.0) | ((int)(float)(UFG::ObjectiveGreen.a * 255.0) << 8)) << 8)) << 8)) )
      return "GPS_Mission_Effect";
    if ( v3 == ((int)(float)(UFG::ObjectiveBlue.r * 255.0) | (((int)(float)(UFG::ObjectiveBlue.g * 255.0) | (((int)(float)(UFG::ObjectiveBlue.b * 255.0) | ((int)(float)(UFG::ObjectiveBlue.a * 255.0) << 8)) << 8)) << 8)) )
      return "GPS_Case_Effect";
    if ( v3 == ((int)(float)(UFG::ObjectiveOrange.r * 255.0) | (((int)(float)(UFG::ObjectiveOrange.g * 255.0) | (((int)(float)(UFG::ObjectiveOrange.b * 255.0) | ((int)(float)(UFG::ObjectiveOrange.a * 255.0) << 8)) << 8)) << 8)) )
      return "GPS_Race_Effect";
    if ( v3 == ((int)(float)(UFG::ObjectiveYellow.r * 255.0) | (((int)(float)(UFG::ObjectiveYellow.g * 255.0) | (((int)(float)(UFG::ObjectiveYellow.b * 255.0) | ((int)(float)(UFG::ObjectiveYellow.a * 255.0) << 8)) << 8)) << 8)) )
      return "GPS_Event_Effect";
    if ( v3 == ((int)(float)(UFG::ObjectiveRed.r * 255.0) | (((int)(float)(UFG::ObjectiveRed.g * 255.0) | (((int)(float)(UFG::ObjectiveRed.b * 255.0) | ((int)(float)(UFG::ObjectiveRed.a * 255.0) << 8)) << 8)) << 8)) )
      return "GPS_Enemy_Effect";
    if ( v3 == ((int)(float)(UFG::CharacterGold.r * 255.0) | (((int)(float)(UFG::CharacterGold.g * 255.0) | (((int)(float)(UFG::CharacterGold.b * 255.0) | ((int)(float)(UFG::CharacterGold.a * 255.0) << 8)) << 8)) << 8)) )
      return "GPS_Event_Effect";
    if ( v3 == ((int)(float)(UFG::AmbientBlue.r * 255.0) | (((int)(float)(UFG::AmbientBlue.g * 255.0) | (((int)(float)(UFG::AmbientBlue.b * 255.0) | ((int)(float)(UFG::AmbientBlue.a * 255.0) << 8)) << 8)) << 8)) )
      return "GPS_Drug_Effect";
    if ( v3 == ((int)(float)(UFG::CharacterPink.r * 255.0) | (((int)(float)(UFG::CharacterPink.g * 255.0) | (((int)(float)(UFG::CharacterPink.b * 255.0) | ((int)(float)(UFG::CharacterPink.a * 255.0) << 8)) << 8)) << 8)) )
      return "GPS_Date_Effect";
    if ( v3 == ((int)(float)(UFG::TransTerrorOrange.r * 255.0) | (((int)(float)(UFG::TransTerrorOrange.g * 255.0) | (((int)(float)(UFG::TransTerrorOrange.b * 255.0) | ((int)(float)(UFG::TransTerrorOrange.a * 255.0) << 8)) << 8)) << 8))
      || v3 == ((int)(float)(UFG::ZodiacOrange.r * 255.0) | (((int)(float)(UFG::ZodiacOrange.g * 255.0) | (((int)(float)(UFG::ZodiacOrange.b * 255.0) | ((int)(float)(UFG::ZodiacOrange.a * 255.0) << 8)) << 8)) << 8)) )
    {
      return "GPS_Race_Effect";
    }
    v6 = "GPS_Event_Effect";
    if ( v3 != ((int)(float)(UFG::ExoticVendorGold.r * 255.0) | (((int)(float)(UFG::ExoticVendorGold.g * 255.0) | (((int)(float)(UFG::ExoticVendorGold.b * 255.0) | ((int)(float)(UFG::ExoticVendorGold.a * 255.0) << 8)) << 8)) << 8)) )
      return "GPS_Generic_Effect";
    return v6;
  }
  return v2;
}

