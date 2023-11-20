// File Line: 25
// RVA: 0x643220
void __fastcall UFG::TrueDirectionManager::TrueDirectionManager(UFG::TrueDirectionManager *this)
{
  float v1; // xmm1_4
  float v2; // xmm2_4
  UFG::SimComponent *v3; // rdi
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v4; // rbx
  UFG::qMemoryPool *v5; // rax
  UFG::allocator::free_link *v6; // rax
  UFG::SimComponent *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax

  v1 = UFG::qVector3::msDirFront.y;
  v2 = UFG::qVector3::msDirFront.z;
  this->mPathForward.x = UFG::qVector3::msDirFront.x;
  this->mPathForward.y = v1;
  this->mPathForward.z = v2;
  v3 = 0i64;
  this->mEffectHash = 0;
  this->mEffectId = -1;
  this->mEffectOverride.m_pPointer = 0i64;
  v4 = &this->mEffectTransform;
  v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  this->mEffectTransform.m_pPointer = 0i64;
  this->mCurrentLane = 0i64;
  v5 = UFG::GetSimulationMemoryPool();
  v6 = UFG::qMemoryPool::Allocate(v5, 0x110ui64, "TrueDirectionManager.mEffectTransform", 0i64, 1u);
  if ( v6 )
  {
    UFG::TransformNodeComponent::TransformNodeComponent((UFG::TransformNodeComponent *)v6, 0x17u, 0i64, 0);
    v3 = v7;
  }
  if ( v4->m_pPointer )
  {
    v8 = v4->mPrev;
    v9 = v4->mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
    v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  }
  v4->m_pPointer = v3;
  if ( v3 )
  {
    v10 = v3->m_SafePointerList.mNode.mPrev;
    v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
    v4->mPrev = v10;
    v4->mNext = &v3->m_SafePointerList.mNode;
    v3->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  }
}

// File Line: 87
// RVA: 0x65F9C0
void __fastcall UFG::TrueDirectionManager::Update(UFG::TrueDirectionManager *this)
{
  UFG::TrueDirectionManager *v1; // rbx
  UFG::RoadNetworkLane *v2; // rdi
  const char *v3; // rax

  v1 = this;
  v2 = 0i64;
  if ( UFG::UIHKScreenHud::getInstance() && (v2 = UFG::UIHKScreenHud::GPS->mTrueDirectionIntersectionLane) != 0i64 )
  {
    if ( v1->mEffectId != -1 )
    {
      v3 = UFG::TrueDirectionManager::GetEffectName(v1);
      if ( v1->mEffectHash != (unsigned int)UFG::qStringHashUpper32(v3, 0xFFFFFFFF) || v1->mCurrentLane != v2 )
        UFG::TrueDirectionManager::KillEffects(v1);
    }
    UFG::TrueDirectionManager::UpdateEffectLocation(v1, v2);
    if ( v1->mEffectId == -1 )
      UFG::TrueDirectionManager::StartEffects(v1);
    UFG::TrueDirectionManager::UpdateEffectFade(v1);
  }
  else if ( v1->mEffectId != -1 )
  {
    UFG::TrueDirectionManager::KillEffects(v1);
  }
  if ( v1->mCurrentLane != v2 )
    v1->mCurrentLane = v2;
}

// File Line: 125
// RVA: 0x652490
void __fastcall UFG::TrueDirectionManager::KillEffects(UFG::TrueDirectionManager *this)
{
  UFG::TrueDirectionManager *v1; // rbx
  Render::FXOverride *v2; // rax
  Render::FXOverride *v3; // rdi

  v1 = this;
  Render::FXManager::KillEffect(&Render::gFXManager, this->mEffectId, FXKILLOPTION_ERASE_EMITTED_OBJECTS);
  v1->mEffectId = -1;
  v2 = v1->mEffectOverride.m_pPointer;
  if ( v2 )
  {
    --v2->mReferenceCount;
    v3 = v1->mEffectOverride.m_pPointer;
    if ( v3->mReferenceCount <= 0 )
    {
      if ( v3 )
      {
        Render::FXOverride::~FXOverride(v1->mEffectOverride.m_pPointer);
        operator delete[](v3);
      }
      v1->mEffectOverride.m_pPointer = 0i64;
    }
    v1->mEffectOverride.m_pPointer = 0i64;
  }
}

// File Line: 132
// RVA: 0x65AE10
void __fastcall UFG::TrueDirectionManager::StartEffects(UFG::TrueDirectionManager *this)
{
  UFG::TrueDirectionManager *v1; // rdi
  const char *v2; // rax
  UFG::allocator::free_link *v3; // rax

  v1 = this;
  v2 = UFG::TrueDirectionManager::GetEffectName(this);
  v1->mEffectHash = UFG::qStringHashUpper32(v2, 0xFFFFFFFF);
  v3 = Render::FXOverride::CreateOverride("TrueDirectionManager Override", 0i64);
  FX::SharedPointer<Render::FXOverride>::Set(&v1->mEffectOverride, (Render::FXOverride *)v3);
  v1->mEffectId = Render::FXManager::CreateEffect(
                    &Render::gFXManager,
                    v1->mEffectHash,
                    (UFG::TransformNodeComponent *)v1->mEffectTransform.m_pPointer,
                    0xFFFFFFFF,
                    v1->mEffectOverride.m_pPointer);
}

// File Line: 140
// RVA: 0x661500
void __fastcall UFG::TrueDirectionManager::UpdateEffectLocation(UFG::TrueDirectionManager *this, UFG::RoadNetworkLane *roadLane)
{
  UFG::RoadNetworkLane *v2; // rbx
  UFG::TrueDirectionManager *v3; // rsi
  bool v4; // r14
  int *v5; // rdi
  UFG::RoadNetworkNode *v6; // rcx
  __m128 v7; // xmm6
  __m128 v8; // xmm7
  float v9; // xmm14_4
  __m128 v10; // xmm15
  __m128 v11; // xmm2
  float v12; // xmm1_4
  __int64 v13; // rax
  float v14; // xmm6_4
  float v15; // xmm8_4
  UFG::qVector3 *v16; // rax
  float v17; // xmm4_4
  float v18; // xmm5_4
  __m128 v19; // xmm9
  float v20; // xmm10_4
  float v21; // xmm12_4
  __m128 v22; // xmm2
  float v23; // xmm1_4
  float v24; // xmm6_4
  float v25; // xmm7_4
  float v26; // xmm8_4
  __m128 v27; // xmm2
  float v28; // xmm0_4
  __m128 v29; // xmm2
  __m128 v30; // xmm1
  float v31; // xmm3_4
  float v32; // xmm3_4
  __m128 v33; // xmm4
  float v34; // xmm3_4
  __m128 v35; // xmm5
  float v36; // xmm1_4
  float v37; // xmm3_4
  float v38; // xmm2_4
  float v39; // xmm5_4
  __m128 v40; // xmm9
  float v41; // xmm2_4
  __m128 v42; // xmm3
  float v43; // xmm1_4
  __m128 v44; // xmm7
  __m128 v45; // xmm6
  __m128 v46; // xmm5
  float v47; // xmm9_4
  float v48; // xmm10_4
  unsigned int v49; // xmm8_4
  __m128 v50; // xmm0
  float v51; // xmm4_4
  __m128 v52; // xmm3
  float v53; // xmm5_4
  __m128 v54; // xmm2
  float v55; // xmm15_4
  float v56; // xmm11_4
  UFG::qMatrix44 *v57; // rax
  UFG::qVector4 v58; // xmm1
  UFG::qVector4 v59; // xmm0
  UFG::qVector4 v60; // xmm1
  UFG::qMatrix44 *v61; // rax
  UFG::qVector4 v62; // xmm1
  UFG::qVector4 v63; // xmm0
  UFG::qVector4 v64; // xmm1
  UFG::qMatrix44 *v65; // rax
  UFG::qVector4 v66; // xmm2
  UFG::qVector4 v67; // xmm1
  UFG::qVector4 v68; // xmm0
  float v69; // xmm0_4
  float v70; // xmm1_4
  UFG::TransformNodeComponent *v71; // rcx
  char b[72]; // [rsp+20h] [rbp-B8h]
  char v73[24]; // [rsp+68h] [rbp-70h]
  __int64 v74; // [rsp+80h] [rbp-58h]
  float v75; // [rsp+88h] [rbp-50h]
  unsigned int v76; // [rsp+90h] [rbp-48h]
  float v77; // [rsp+94h] [rbp-44h]
  float v78; // [rsp+98h] [rbp-40h]
  UFG::qVector3 axis; // [rsp+A0h] [rbp-38h]
  UFG::qVector3 result; // [rsp+B0h] [rbp-28h]
  UFG::qMatrix44 dest; // [rsp+C8h] [rbp-10h]
  UFG::qMatrix44 v82; // [rsp+108h] [rbp+30h]
  float v83; // [rsp+218h] [rbp+140h]
  float v84; // [rsp+220h] [rbp+148h]
  float v85; // [rsp+228h] [rbp+150h]
  unsigned int vars0; // [rsp+230h] [rbp+158h]

  v2 = roadLane;
  v3 = this;
  v4 = 0;
  if ( UFG::UIHKScreenHud::getInstance() )
    v4 = UFG::UIHKScreenHud::GPS->mTrueDirectionHighwayRamp;
  v5 = 0i64;
  v6 = (UFG::RoadNetworkNode *)((char *)v2 + v2->mNode.mOffset);
  if ( !v2->mNode.mOffset )
    v6 = 0i64;
  UFG::RoadNetworkNode::GetTangent(v6, &result, v2->mLaneIndex, 1.0);
  v7 = (__m128)LODWORD(result.x);
  v8 = (__m128)LODWORD(result.y);
  v9 = 0.0;
  v11 = v7;
  v10 = (__m128)(unsigned int)FLOAT_1_0;
  v11.m128_f32[0] = (float)((float)(v7.m128_f32[0] * v7.m128_f32[0]) + (float)(v8.m128_f32[0] * v8.m128_f32[0]))
                  + (float)(result.z * result.z);
  if ( v11.m128_f32[0] == 0.0 )
    v12 = 0.0;
  else
    v12 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v11));
  v13 = v2->mNode.mOffset;
  v14 = result.x * v12;
  v8.m128_f32[0] = result.y * v12;
  *(float *)&vars0 = result.x * v12;
  *(float *)&v73[16] = result.y * v12;
  v15 = result.z * v12;
  *(float *)&v73[20] = result.z * v12;
  if ( v13 )
    v5 = (int *)((char *)v2 + v13);
  v83 = *((float *)v5 + 3);
  v84 = *((float *)v5 + 4);
  v85 = *((float *)v5 + 5);
  if ( v4 )
  {
    v16 = UFG::RoadNetworkLane::GetPos(v2, (UFG::qVector3 *)&v74, 1.0);
    v17 = UFG::qVector3::msDirUp.y;
    v18 = UFG::qVector3::msDirUp.z;
    v19 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
    v20 = v16->z;
    v10 = (__m128)(unsigned int)FLOAT_1_0;
    v21 = v16->y + (float)((float)(v14 * UFG::qVector3::msDirUp.z) - (float)(v15 * UFG::qVector3::msDirUp.x));
    v83 = v16->x + (float)((float)(v15 * UFG::qVector3::msDirUp.y) - (float)(v8.m128_f32[0] * UFG::qVector3::msDirUp.z));
    v84 = v21;
    v85 = (float)(v20 + 3.5)
        + (float)((float)(v8.m128_f32[0] * UFG::qVector3::msDirUp.x) - (float)(v14 * UFG::qVector3::msDirUp.y));
  }
  else
  {
    v17 = UFG::qVector3::msDirUp.y;
    v18 = UFG::qVector3::msDirUp.z;
    v19 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
  }
  v22 = v8;
  *(UFG::qVector4 *)&v73[8] = UFG::qMatrix44::msIdentity.v1;
  *(UFG::qVector4 *)&b[56] = UFG::qMatrix44::msIdentity.v2;
  *(UFG::qVector4 *)v73 = UFG::qMatrix44::msIdentity.v3;
  v22.m128_f32[0] = (float)((float)(v8.m128_f32[0] * v8.m128_f32[0]) + (float)(v14 * v14)) + (float)(v15 * v15);
  if ( v22.m128_f32[0] == 0.0 )
    v23 = 0.0;
  else
    v23 = v10.m128_f32[0] / COERCE_FLOAT(_mm_sqrt_ps(v22));
  v24 = v14 * v23;
  v25 = v8.m128_f32[0] * v23;
  v26 = v15 * v23;
  v27 = v19;
  *(_DWORD *)&b[12] = 0;
  *(float *)b = v24;
  *(float *)&b[4] = v25;
  *(float *)&b[8] = v26;
  v27.m128_f32[0] = (float)((float)(v19.m128_f32[0] * v19.m128_f32[0]) + (float)(v17 * v17)) + (float)(v18 * v18);
  if ( v27.m128_f32[0] == 0.0 )
  {
    v29 = 0i64;
  }
  else
  {
    LODWORD(v28) = (unsigned __int128)_mm_sqrt_ps(v27);
    v29 = v10;
    v29.m128_f32[0] = v10.m128_f32[0] / v28;
  }
  v30 = v29;
  v31 = v29.m128_f32[0];
  v29.m128_f32[0] = v29.m128_f32[0] * v18;
  v30.m128_f32[0] = v30.m128_f32[0] * v17;
  v32 = v31 * v19.m128_f32[0];
  v33 = v30;
  v33.m128_f32[0] = (float)(v30.m128_f32[0] * v26) - (float)(v29.m128_f32[0] * v25);
  v29.m128_f32[0] = (float)(v29.m128_f32[0] * v24) - (float)(v32 * v26);
  v34 = (float)(v32 * v25) - (float)(v30.m128_f32[0] * v24);
  v35 = v29;
  v35.m128_f32[0] = (float)((float)(v29.m128_f32[0] * v29.m128_f32[0]) + (float)(v33.m128_f32[0] * v33.m128_f32[0]))
                  + (float)(v34 * v34);
  if ( v35.m128_f32[0] == 0.0 )
    v36 = 0.0;
  else
    v36 = v10.m128_f32[0] / COERCE_FLOAT(_mm_sqrt_ps(v35));
  v37 = v34 * v36;
  v38 = v29.m128_f32[0] * v36;
  v33.m128_f32[0] = v33.m128_f32[0] * v36;
  *(_DWORD *)&b[28] = 0;
  *(float *)&b[24] = v37;
  *(float *)&b[20] = v38;
  *(_DWORD *)&b[16] = v33.m128_i32[0];
  v40 = v33;
  v39 = (float)(v37 * v25) - (float)(v38 * v26);
  v40.m128_f32[0] = (float)(v33.m128_f32[0] * v26) - (float)(v37 * v24);
  v41 = (float)(v38 * v24) - (float)(v33.m128_f32[0] * v25);
  v42 = v40;
  v42.m128_f32[0] = (float)((float)(v40.m128_f32[0] * v40.m128_f32[0]) + (float)(v39 * v39)) + (float)(v41 * v41);
  if ( v42.m128_f32[0] == 0.0 )
    v43 = 0.0;
  else
    v43 = v10.m128_f32[0] / COERCE_FLOAT(_mm_sqrt_ps(v42));
  v44 = *(__m128 *)&b[56];
  *(_DWORD *)&b[44] = 0;
  *(_DWORD *)&b[60] = 1065353216;
  *(UFG::qVector3 *)&b[48] = UFG::qVector3::msZero;
  *(float *)&b[32] = v39 * v43;
  *(float *)&b[36] = v40.m128_f32[0] * v43;
  *(float *)&b[40] = v41 * v43;
  v45 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&b[64], *(__m128 *)&b[64], 0), *(__m128 *)b),
                (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&b[64], *(__m128 *)&b[64], 85), *(__m128 *)&b[16])),
            _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&b[64], *(__m128 *)&b[64], 170), *(__m128 *)&b[32])),
          _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&b[64], *(__m128 *)&b[64], 255), *(__m128 *)&b[48]));
  v46 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v73[8], *(__m128 *)&v73[8], 0), *(__m128 *)b),
                (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v73[8], *(__m128 *)&v73[8], 85), *(__m128 *)&b[16])),
            _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v73[8], *(__m128 *)&v73[8], 170), *(__m128 *)&b[32])),
          _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v73[8], *(__m128 *)&v73[8], 255), *(__m128 *)&b[48]));
  v47 = *(float *)&v73[16];
  v48 = *(float *)&v73[20];
  v49 = vars0;
  v52 = (__m128)vars0;
  v50 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)v73, *(__m128 *)v73, 85), *(__m128 *)&b[16]),
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(*(__m128 *)v73, *(__m128 *)v73, 0), *(__m128 *)b), (__m128)0i64)),
            _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)v73, *(__m128 *)v73, 170), *(__m128 *)&b[32])),
          _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)v73, *(__m128 *)v73, 255), *(__m128 *)&b[48]));
  *(__m128 *)&b[56] = _mm_add_ps(
                        _mm_add_ps(
                          _mm_add_ps(
                            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v44, v44, 0), *(__m128 *)b), (__m128)0i64),
                            _mm_mul_ps(_mm_shuffle_ps(v44, v44, 85), *(__m128 *)&b[16])),
                          _mm_mul_ps(_mm_shuffle_ps(v44, v44, 170), *(__m128 *)&b[32])),
                        _mm_mul_ps(_mm_shuffle_ps(v44, v44, 255), *(__m128 *)&b[48]));
  *(__m128 *)&v73[8] = v46;
  *(__m128 *)v73 = v50;
  *(__m128 *)&b[64] = v45;
  v76 = vars0;
  v51 = (float)(v48 * UFG::qVector3::msDirUp.y) - (float)(v47 * UFG::qVector3::msDirUp.z);
  v77 = v47;
  v78 = v48;
  v52.m128_f32[0] = (float)(*(float *)&vars0 * UFG::qVector3::msDirUp.z) - (float)(v48 * UFG::qVector3::msDirUp.x);
  v54 = v52;
  v53 = (float)(v47 * UFG::qVector3::msDirUp.x) - (float)(*(float *)&vars0 * UFG::qVector3::msDirUp.y);
  v54.m128_f32[0] = (float)((float)(v52.m128_f32[0] * v52.m128_f32[0]) + (float)(v51 * v51)) + (float)(v53 * v53);
  if ( v54.m128_f32[0] >= 0.001 )
  {
    if ( v54.m128_f32[0] == 0.0 )
      v55 = 0.0;
    else
      v55 = v10.m128_f32[0] / COERCE_FLOAT(_mm_sqrt_ps(v54));
    v56 = FLOAT_90_0;
    *((float *)&v74 + 1) = v52.m128_f32[0] * v55;
    *(float *)&v74 = v51 * v55;
    v75 = v53 * v55;
    axis.y = (float)((float)(v51 * v55) * v48) - (float)((float)(v53 * v55) * *(float *)&vars0);
    axis.x = (float)((float)(v53 * v55) * v47) - (float)((float)(v52.m128_f32[0] * v55) * v48);
    axis.z = (float)((float)(v52.m128_f32[0] * v55) * *(float *)&vars0) - (float)((float)(v51 * v55) * v47);
    if ( v4 )
    {
      v56 = 0.0;
      v9 = FLOAT_N90_0;
    }
    UFG::qRotationMatrixAxis(&dest, &axis, 1.5707964);
    *(UFG::qMatrix44 *)b = dest;
    UFG::qRotationMatrixAxis(&dest, (UFG::qVector3 *)&v76, (float)(v56 * 3.1415927) * 0.0055555557);
    v57 = UFG::qMatrix44::operator*((UFG::qMatrix44 *)b, &v82, &dest);
    v58 = v57->v1;
    *(UFG::qVector4 *)b = v57->v0;
    v59 = v57->v2;
    *(UFG::qVector4 *)&b[16] = v58;
    v60 = v57->v3;
    *(UFG::qVector4 *)&b[32] = v59;
    *(UFG::qVector4 *)&b[48] = v60;
    UFG::qRotationMatrixAxis(&dest, (UFG::qVector3 *)&v74, (float)(v9 * 3.1415927) * 0.0055555557);
    v61 = UFG::qMatrix44::operator*((UFG::qMatrix44 *)b, &v82, &dest);
    v62 = v61->v1;
    *(UFG::qVector4 *)b = v61->v0;
    v63 = v61->v2;
    *(UFG::qVector4 *)&b[16] = v62;
    v64 = v61->v3;
    *(UFG::qVector4 *)&b[32] = v63;
    *(UFG::qVector4 *)&b[48] = v64;
    v65 = UFG::qMatrix44::operator*((UFG::qMatrix44 *)&b[64], &v82, (UFG::qMatrix44 *)b);
    v66 = v65->v2;
    v67 = v65->v3;
    v68 = v65->v0;
    *(UFG::qVector4 *)&v73[8] = v65->v1;
    *(UFG::qVector4 *)&b[56] = v66;
    *(UFG::qVector4 *)&b[64] = v68;
    *(UFG::qVector4 *)v73 = v67;
  }
  v69 = v83;
  v70 = v84;
  LODWORD(v3->mPathForward.x) = v49;
  *(_DWORD *)&v73[12] = 1065353216;
  v3->mPathForward.y = v47;
  v3->mPathForward.z = v48;
  *(float *)v73 = v69;
  v71 = (UFG::TransformNodeComponent *)v3->mEffectTransform.m_pPointer;
  *(float *)&v73[4] = v70;
  *(float *)&v73[8] = v85;
  if ( v71 )
    UFG::TransformNodeComponent::SetWorldTransform(v71, (UFG::qMatrix44 *)&b[64]);
}

// File Line: 241
// RVA: 0x661190
void __fastcall UFG::TrueDirectionManager::UpdateEffectFade(UFG::TrueDirectionManager *this)
{
  UFG::TrueDirectionManager *v1; // rdi
  bool v2; // si
  float *v3; // rbx
  float v4; // xmm8_4
  float v5; // xmm14_4
  float v6; // xmm15_4
  signed __int64 v7; // rbx
  UFG::BaseCameraComponent *v8; // rax
  signed __int64 v9; // rax
  float v10; // xmm10_4
  __m128 v11; // xmm7
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
  UFG::TransformNodeComponent *v27; // rbx
  float v28; // xmm3_4
  float v29; // xmm0_4
  float v30; // xmm0_4
  Render::FXOverride *v31; // rax
  float v32; // [rsp+D0h] [rbp+8h]

  v1 = this;
  v2 = 0;
  if ( UFG::UIHKScreenHud::getInstance() )
    v2 = UFG::UIHKScreenHud::GPS->mTrueDirectionHighwayRamp;
  v3 = (float *)v1->mEffectTransform.m_pPointer;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v1->mEffectTransform.m_pPointer);
  v4 = v3[46];
  v5 = v3[44];
  v6 = v3[45];
  v32 = v3[46];
  v7 = 0i64;
  v8 = UFG::Director::Get()->mCurrentCamera;
  if ( v8 )
    v9 = (signed __int64)&v8->mCamera;
  else
    v9 = 0i64;
  v10 = *(float *)(v9 + 176);
  v11 = (__m128)*(unsigned int *)(v9 + 180);
  v12 = *(float *)(v9 + 184);
  if ( v1->mEffectId != -1 )
  {
    v13 = *(float *)&FLOAT_1_0;
    v14 = *(float *)&FLOAT_1_0;
    if ( !v2 )
    {
      v15 = UFG::Director::Get()->mCurrentCamera;
      if ( v15 )
        v7 = (signed __int64)&v15->mCamera;
      v16 = *(_DWORD *)(v7 + 160) ^ _xmm[0];
      v17 = *(_DWORD *)(v7 + 164) ^ _xmm[0];
      v18 = v1->mPathForward.x;
      v19 = v1->mPathForward.y;
      v20 = (float)(*(float *)&v17 * *(float *)&v17) + (float)(*(float *)&v16 * *(float *)&v16);
      if ( v20 >= 0.0000010000001 )
      {
        v21 = (__m128)LODWORD(v1->mPathForward.y);
        v21.m128_f32[0] = (float)(v19 * v19) + (float)(v18 * v18);
        v13 = *(float *)&FLOAT_1_0;
        if ( v21.m128_f32[0] >= 0.0000010000001 )
        {
          if ( v21.m128_f32[0] == 0.0 )
            v22 = 0.0;
          else
            v22 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v21));
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
            v4 = v32;
            v14 = *(float *)&FLOAT_1_0;
            goto LABEL_25;
          }
          v4 = v32;
          goto LABEL_25;
        }
      }
      else
      {
        v13 = *(float *)&FLOAT_1_0;
        v14 = 0.0;
      }
      v4 = v32;
    }
LABEL_25:
    if ( LocalPlayer )
    {
      v27 = LocalPlayer->m_pTransformNodeComponent;
      if ( v27 )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform(v27);
        v10 = v27->mWorldTransform.v3.x;
        v11 = (__m128)LODWORD(v27->mWorldTransform.v3.y);
        v12 = v27->mWorldTransform.v3.z;
        v13 = *(float *)&FLOAT_1_0;
      }
    }
    v11.m128_f32[0] = (float)((float)((float)(v11.m128_f32[0] - v6) * (float)(v11.m128_f32[0] - v6))
                            + (float)((float)(v10 - v5) * (float)(v10 - v5)))
                    + (float)((float)(v12 - v4) * (float)(v12 - v4));
    LODWORD(v28) = (unsigned __int128)_mm_sqrt_ps(v11);
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
    v31 = v1->mEffectOverride.m_pPointer;
    if ( v31 )
      v31->stateBlock.ColorTint[3] = v14;
  }
}

// File Line: 304
// RVA: 0x64DDA0
const char *__fastcall UFG::TrueDirectionManager::GetEffectName(UFG::TrueDirectionManager *this)
{
  bool v1; // bl
  const char *v2; // r8
  unsigned int v3; // er9
  int v4; // ecx
  const char *v6; // rax

  v1 = 0;
  if ( UFG::UIHKScreenHud::getInstance() )
    v1 = UFG::UIHKScreenHud::GPS->mTrueDirectionHighwayRamp;
  v2 = "GPS_Generic_Effect";
  v3 = (signed int)(float)(UFG::UITiledMapWidget::GPSLineColor.r * 255.0) | (((signed int)(float)(UFG::UITiledMapWidget::GPSLineColor.g
                                                                                                * 255.0) | (((signed int)(float)(UFG::UITiledMapWidget::GPSLineColor.b * 255.0) | 0xFFFFFF00) << 8)) << 8);
  v4 = (signed int)(float)(UFG::UITiledMapWidget::DefaultGPSLineColor.r * 255.0) | (((signed int)(float)(UFG::UITiledMapWidget::DefaultGPSLineColor.g * 255.0) | (((signed int)(float)(UFG::UITiledMapWidget::DefaultGPSLineColor.b * 255.0) | ((signed int)(float)(UFG::UITiledMapWidget::DefaultGPSLineColor.a * 255.0) << 8)) << 8)) << 8);
  if ( v1 )
  {
    v2 = "GPS_Generic_Vertical_Effect";
    if ( v3 != v4 )
    {
      if ( v3 == ((signed int)(float)(UFG::ObjectiveGreen.r * 255.0) | (((signed int)(float)(UFG::ObjectiveGreen.g
                                                                                           * 255.0) | (((signed int)(float)(UFG::ObjectiveGreen.b * 255.0) | ((signed int)(float)(UFG::ObjectiveGreen.a * 255.0) << 8)) << 8)) << 8)) )
        return "GPS_Mission_Vertical_Effect";
      if ( v3 == ((signed int)(float)(UFG::ObjectiveBlue.r * 255.0) | (((signed int)(float)(UFG::ObjectiveBlue.g * 255.0) | (((signed int)(float)(UFG::ObjectiveBlue.b * 255.0) | ((signed int)(float)(UFG::ObjectiveBlue.a * 255.0) << 8)) << 8)) << 8)) )
        return "GPS_Case_Vertical_Effect";
      if ( v3 == ((signed int)(float)(UFG::ObjectiveOrange.r * 255.0) | (((signed int)(float)(UFG::ObjectiveOrange.g
                                                                                            * 255.0) | (((signed int)(float)(UFG::ObjectiveOrange.b * 255.0) | ((signed int)(float)(UFG::ObjectiveOrange.a * 255.0) << 8)) << 8)) << 8)) )
        return "GPS_Race_Vertical_Effect";
      if ( v3 == ((signed int)(float)(UFG::ObjectiveYellow.r * 255.0) | (((signed int)(float)(UFG::ObjectiveYellow.g
                                                                                            * 255.0) | (((signed int)(float)(UFG::ObjectiveYellow.b * 255.0) | ((signed int)(float)(UFG::ObjectiveYellow.a * 255.0) << 8)) << 8)) << 8)) )
        return "GPS_Event_Vertical_Effect";
      if ( v3 == ((signed int)(float)(UFG::ObjectiveRed.r * 255.0) | (((signed int)(float)(UFG::ObjectiveRed.g * 255.0) | (((signed int)(float)(UFG::ObjectiveRed.b * 255.0) | ((signed int)(float)(UFG::ObjectiveRed.a * 255.0) << 8)) << 8)) << 8)) )
        return "GPS_Enemy_Vertical_Effect";
      if ( v3 == ((signed int)(float)(UFG::CharacterGold.r * 255.0) | (((signed int)(float)(UFG::CharacterGold.g * 255.0) | (((signed int)(float)(UFG::CharacterGold.b * 255.0) | ((signed int)(float)(UFG::CharacterGold.a * 255.0) << 8)) << 8)) << 8)) )
        return "GPS_Event_Vertical_Effect";
      if ( v3 == ((signed int)(float)(UFG::AmbientBlue.r * 255.0) | (((signed int)(float)(UFG::AmbientBlue.g * 255.0) | (((signed int)(float)(UFG::AmbientBlue.b * 255.0) | ((signed int)(float)(UFG::AmbientBlue.a * 255.0) << 8)) << 8)) << 8)) )
        return "GPS_Drug_Vertical_Effect";
      if ( v3 == ((signed int)(float)(UFG::CharacterPink.r * 255.0) | (((signed int)(float)(UFG::CharacterPink.g * 255.0) | (((signed int)(float)(UFG::CharacterPink.b * 255.0) | ((signed int)(float)(UFG::CharacterPink.a * 255.0) << 8)) << 8)) << 8)) )
        return "GPS_Date_Vertical_Effect";
      if ( v3 == ((signed int)(float)(UFG::TransTerrorOrange.r * 255.0) | (((signed int)(float)(UFG::TransTerrorOrange.g
                                                                                              * 255.0) | (((signed int)(float)(UFG::TransTerrorOrange.b * 255.0) | ((signed int)(float)(UFG::TransTerrorOrange.a * 255.0) << 8)) << 8)) << 8))
        || v3 == ((signed int)(float)(UFG::ZodiacOrange.r * 255.0) | (((signed int)(float)(UFG::ZodiacOrange.g * 255.0) | (((signed int)(float)(UFG::ZodiacOrange.b * 255.0) | ((signed int)(float)(UFG::ZodiacOrange.a * 255.0) << 8)) << 8)) << 8)) )
      {
        return "GPS_Race_Vertical_Effect";
      }
      if ( v3 == ((signed int)(float)(UFG::ExoticVendorGold.r * 255.0) | (((signed int)(float)(UFG::ExoticVendorGold.g
                                                                                             * 255.0) | (((signed int)(float)(UFG::ExoticVendorGold.b * 255.0) | ((signed int)(float)(UFG::ExoticVendorGold.a * 255.0) << 8)) << 8)) << 8)) )
        return "GPS_Event_Vertical_Effect";
    }
  }
  else if ( v3 != v4 )
  {
    if ( v3 == ((signed int)(float)(UFG::ObjectiveGreen.r * 255.0) | (((signed int)(float)(UFG::ObjectiveGreen.g * 255.0) | (((signed int)(float)(UFG::ObjectiveGreen.b * 255.0) | ((signed int)(float)(UFG::ObjectiveGreen.a * 255.0) << 8)) << 8)) << 8)) )
      return "GPS_Mission_Effect";
    if ( v3 == ((signed int)(float)(UFG::ObjectiveBlue.r * 255.0) | (((signed int)(float)(UFG::ObjectiveBlue.g * 255.0) | (((signed int)(float)(UFG::ObjectiveBlue.b * 255.0) | ((signed int)(float)(UFG::ObjectiveBlue.a * 255.0) << 8)) << 8)) << 8)) )
      return "GPS_Case_Effect";
    if ( v3 == ((signed int)(float)(UFG::ObjectiveOrange.r * 255.0) | (((signed int)(float)(UFG::ObjectiveOrange.g
                                                                                          * 255.0) | (((signed int)(float)(UFG::ObjectiveOrange.b * 255.0) | ((signed int)(float)(UFG::ObjectiveOrange.a * 255.0) << 8)) << 8)) << 8)) )
      return "GPS_Race_Effect";
    if ( v3 == ((signed int)(float)(UFG::ObjectiveYellow.r * 255.0) | (((signed int)(float)(UFG::ObjectiveYellow.g
                                                                                          * 255.0) | (((signed int)(float)(UFG::ObjectiveYellow.b * 255.0) | ((signed int)(float)(UFG::ObjectiveYellow.a * 255.0) << 8)) << 8)) << 8)) )
      return "GPS_Event_Effect";
    if ( v3 == ((signed int)(float)(UFG::ObjectiveRed.r * 255.0) | (((signed int)(float)(UFG::ObjectiveRed.g * 255.0) | (((signed int)(float)(UFG::ObjectiveRed.b * 255.0) | ((signed int)(float)(UFG::ObjectiveRed.a * 255.0) << 8)) << 8)) << 8)) )
      return "GPS_Enemy_Effect";
    if ( v3 == ((signed int)(float)(UFG::CharacterGold.r * 255.0) | (((signed int)(float)(UFG::CharacterGold.g * 255.0) | (((signed int)(float)(UFG::CharacterGold.b * 255.0) | ((signed int)(float)(UFG::CharacterGold.a * 255.0) << 8)) << 8)) << 8)) )
      return "GPS_Event_Effect";
    if ( v3 == ((signed int)(float)(UFG::AmbientBlue.r * 255.0) | (((signed int)(float)(UFG::AmbientBlue.g * 255.0) | (((signed int)(float)(UFG::AmbientBlue.b * 255.0) | ((signed int)(float)(UFG::AmbientBlue.a * 255.0) << 8)) << 8)) << 8)) )
      return "GPS_Drug_Effect";
    if ( v3 == ((signed int)(float)(UFG::CharacterPink.r * 255.0) | (((signed int)(float)(UFG::CharacterPink.g * 255.0) | (((signed int)(float)(UFG::CharacterPink.b * 255.0) | ((signed int)(float)(UFG::CharacterPink.a * 255.0) << 8)) << 8)) << 8)) )
      return "GPS_Date_Effect";
    if ( v3 == ((signed int)(float)(UFG::TransTerrorOrange.r * 255.0) | (((signed int)(float)(UFG::TransTerrorOrange.g
                                                                                            * 255.0) | (((signed int)(float)(UFG::TransTerrorOrange.b * 255.0) | ((signed int)(float)(UFG::TransTerrorOrange.a * 255.0) << 8)) << 8)) << 8))
      || v3 == ((signed int)(float)(UFG::ZodiacOrange.r * 255.0) | (((signed int)(float)(UFG::ZodiacOrange.g * 255.0) | (((signed int)(float)(UFG::ZodiacOrange.b * 255.0) | ((signed int)(float)(UFG::ZodiacOrange.a * 255.0) << 8)) << 8)) << 8)) )
    {
      return "GPS_Race_Effect";
    }
    v6 = "GPS_Event_Effect";
    if ( v3 != ((signed int)(float)(UFG::ExoticVendorGold.r * 255.0) | (((signed int)(float)(UFG::ExoticVendorGold.g
                                                                                           * 255.0) | (((signed int)(float)(UFG::ExoticVendorGold.b * 255.0) | ((signed int)(float)(UFG::ExoticVendorGold.a * 255.0) << 8)) << 8)) << 8)) )
      v6 = "GPS_Generic_Effect";
    v2 = v6;
  }
  return v2;
}

