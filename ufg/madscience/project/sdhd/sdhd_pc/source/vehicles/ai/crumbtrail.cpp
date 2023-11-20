// File Line: 19
// RVA: 0x64A900
void __fastcall UFG::CrumbTrail::DebugDraw(UFG::CrumbTrail *this, UFG::qColour *color, int numCrumbsOverride)
{
  int v3; // eax
  UFG::qColour *v4; // rbp
  UFG::CrumbTrail *v5; // rdi
  int v6; // ebx
  int v7; // ecx
  float v8; // xmm6_4
  float v9; // xmm7_4
  float v10; // xmm8_4
  signed int v11; // esi
  float *v12; // rcx
  float v13; // xmm7_4
  float v14; // xmm8_4
  int v15; // eax
  signed int v16; // ecx
  float *v17; // rcx
  unsigned int v18; // xmm1_4
  unsigned int v19; // xmm2_4
  Render::DebugDrawContext *v20; // rax
  UFG::qVector3 p1; // [rsp+40h] [rbp-68h]
  UFG::qVector3 p0; // [rsp+50h] [rbp-58h]

  v3 = this->mTrail.mCount;
  v4 = color;
  v5 = this;
  v6 = this->mTrail.mCount;
  if ( numCrumbsOverride > -1 && numCrumbsOverride < v3 )
    v6 = numCrumbsOverride;
  if ( v6 > 1 )
  {
    v7 = this->mTrail.mLast;
    if ( v3 > 0 )
      v3 = 0;
    v8 = UFG::qVector3::msDirUp.x;
    v9 = UFG::qVector3::msDirUp.z;
    v10 = UFG::qVector3::msDirUp.y;
    v11 = 1;
    v12 = &v5->mTrail.mData[(signed int)UFG::qSignedMod(v7 - v3, v5->mTrail.mCapacity)].vPosition.x;
    v13 = v9 + v12[2];
    v14 = v10 + v12[1];
    p0.x = v8 + *v12;
    p0.y = v14;
    for ( p0.z = v13; v11 < v6; ++v11 )
    {
      v15 = v5->mTrail.mCount;
      v16 = 0;
      if ( v11 > 0 )
        v16 = v11;
      if ( v16 < v15 )
        v15 = v16;
      v17 = &v5->mTrail.mData[(signed int)UFG::qSignedMod(v5->mTrail.mLast - v15, v5->mTrail.mCapacity)].vPosition.x;
      *(float *)&v18 = UFG::qVector3::msDirUp.z + v17[2];
      *(float *)&v19 = UFG::qVector3::msDirUp.y + v17[1];
      p1.x = UFG::qVector3::msDirUp.x + *v17;
      *(_QWORD *)&p1.y = __PAIR__(v18, v19);
      v20 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 2u);
      Render::DebugDrawContext::DrawLine(v20, &p0, &p1, v4, &UFG::qMatrix44::msIdentity, 0i64, 0);
      p0 = p1;
    }
  }
}

// File Line: 60
// RVA: 0x644F80
float __fastcall UFG::ApproximateCurvature(UFG::qVector3 *a, UFG::qVector3 *b, UFG::qVector3 *c)
{
  float v3; // xmm3_4
  float v4; // xmm9_4
  float v5; // xmm11_4
  float v6; // xmm8_4
  float v7; // xmm7_4
  __m128 v8; // xmm5
  float v9; // xmm2_4
  float v10; // xmm13_4
  float v11; // xmm4_4
  float v12; // xmm6_4
  float v13; // xmm12_4
  __m128 v14; // xmm1
  float v15; // xmm3_4
  float v16; // xmm13_4
  float v17; // xmm0_4

  v3 = b->z;
  v4 = a->z;
  v5 = a->y;
  v6 = b->y - v5;
  v7 = b->x - a->x;
  v8 = (__m128)LODWORD(c->x);
  v9 = 0.0;
  v8.m128_f32[0] = v8.m128_f32[0] - b->x;
  v10 = c->y - b->y;
  v14 = v8;
  v11 = c->z - v3;
  v12 = v3 - v4;
  v13 = (float)(v11 * v6) - (float)(v10 * (float)(v3 - v4));
  v14.m128_f32[0] = (float)(v8.m128_f32[0] * (float)(v3 - v4)) - (float)(v11 * v7);
  v15 = (float)(v10 * v7) - (float)(v8.m128_f32[0] * v6);
  v16 = (float)((float)((float)((float)(v10 * v10) + (float)(v8.m128_f32[0] * v8.m128_f32[0])) + (float)(v11 * v11))
              * (float)((float)((float)(v6 * v6) + (float)(v7 * v7)) + (float)(v12 * v12)))
      * (float)((float)((float)((float)(v5 - c->y) * (float)(v5 - c->y))
                      + (float)((float)(a->x - c->x) * (float)(a->x - c->x)))
              + (float)((float)(v4 - c->z) * (float)(v4 - c->z)));
  if ( v15 <= 0.0 )
  {
    if ( v15 < 0.0 )
      v9 = FLOAT_N1_0;
  }
  else
  {
    v9 = *(float *)&FLOAT_1_0;
  }
  v17 = FLOAT_0_000099999997;
  if ( v16 >= 0.000099999997 )
    v17 = v16;
  v14.m128_f32[0] = (float)((float)((float)(v14.m128_f32[0] * v14.m128_f32[0]) + (float)(v13 * v13)) + (float)(v15 * v15))
                  / v17;
  return COERCE_FLOAT(_mm_sqrt_ps(v14)) * (float)(v9 * 2.0);
}

// File Line: 72
// RVA: 0x65F3C0
void __fastcall UFG::CrumbTrail::Update(UFG::CrumbTrail *this, UFG::qVector3 *position)
{
  UFG::qVector3 *v2; // rsi
  int v3; // edx
  float v4; // xmm6_4
  UFG::CrumbTrail *v5; // rdi
  float v6; // xmm9_4
  bool v7; // bp
  float v8; // xmm8_4
  bool v9; // r14
  __m128 v10; // xmm2
  UFG::Crumb *v11; // rax
  float v12; // xmm0_4
  __int64 v13; // rcx
  UFG::qVector3 *v14; // rbx
  int v15; // eax
  float v16; // xmm0_4
  signed int v17; // eax
  float v18; // xmm7_4
  signed __int64 v19; // rcx
  float v20; // xmm1_4
  float v21; // xmm3_4
  float v22; // xmm2_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  float v26; // xmm3_4
  int v27; // edx
  int v28; // eax
  signed __int64 v29; // rax
  signed int v30; // eax
  float *v31; // rcx
  float v32; // xmm2_4
  __m128 v33; // xmm3
  float v34; // xmm4_4
  __m128 v35; // xmm5

  v2 = position;
  v3 = this->mTrail.mCount;
  v4 = 0.0;
  v5 = this;
  v6 = 0.0;
  v7 = v3 == 0;
  v8 = UFG::AiDriverComponent::m_BreadCrumbGap;
  v9 = v3 == 0;
  if ( v3 )
  {
    v10 = (__m128)LODWORD(v2->x);
    v11 = &this->mTrail.mData[this->mTrail.mLast];
    v10.m128_f32[0] = (float)((float)((float)(v10.m128_f32[0] - v11->vPosition.x)
                                    * (float)(v10.m128_f32[0] - v11->vPosition.x))
                            + (float)((float)(v2->y - v11->vPosition.y) * (float)(v2->y - v11->vPosition.y)))
                    + (float)((float)(v2->z - v11->vPosition.z) * (float)(v2->z - v11->vPosition.z));
    LODWORD(v6) = (unsigned __int128)_mm_sqrt_ps(v10);
    v9 = v6 > UFG::AiDriverComponent::m_BreadCrumbGap;
  }
  v12 = 0.0;
  if ( v3 > 1 )
  {
    v13 = this->mTrail.mLast;
    v14 = &v5->mTrail.mData[v13].vPosition;
    if ( v3 > 1 )
      v3 = 1;
    v15 = UFG::qSignedMod((signed int)v13 - v3, v5->mTrail.mCapacity);
    v16 = UFG::ApproximateCurvature(&v5->mTrail.mData[v15].vPosition, v14, v2);
    v17 = v5->mTrail.mCount;
    v18 = v16;
    if ( v17 > 1 )
      v17 = 1;
    v19 = (signed __int64)&v5->mTrail.mData[(signed int)UFG::qSignedMod(v5->mTrail.mLast - v17, v5->mTrail.mCapacity)];
    v20 = *(float *)(v19 + 28);
    if ( v20 >= v16 )
      v21 = v16;
    else
      v21 = *(float *)(v19 + 28);
    if ( v20 <= v16 )
      v22 = v16;
    else
      v22 = *(float *)(v19 + 28);
    v23 = FLOAT_0_000099999997;
    if ( v8 >= 0.000099999997 )
      v23 = v8;
    v12 = (float)(v6 * (float)((float)(v18 - v20) / v23)) + v20;
    if ( v12 <= v21 )
      v12 = v21;
    if ( v12 >= v22 )
      v12 = v22;
  }
  if ( !v7 )
    v5->mTrail.mData[v5->mTrail.mLast].fCurvature = v12;
  if ( v9 )
  {
    v24 = v2->x;
    v25 = v2->y;
    v26 = v2->z;
    v27 = (v5->mTrail.mLast + 1) % v5->mTrail.mCapacity;
    v28 = v5->mTrail.mCount;
    v5->mTrail.mLast = v27;
    if ( v28 < v5->mTrail.mCapacity )
      v5->mTrail.mCount = v28 + 1;
    v29 = (signed __int64)&v5->mTrail.mData[v27];
    *(float *)v29 = v24;
    *(float *)(v29 + 4) = v25;
    *(float *)(v29 + 8) = v26;
    *(_QWORD *)(v29 + 12) = 0i64;
    *(_DWORD *)(v29 + 20) = 0;
    *(_DWORD *)(v29 + 24) = 1065353216;
    *(float *)(v29 + 28) = v12;
    if ( !v7 )
    {
      v30 = v5->mTrail.mCount;
      if ( v30 > 1 )
        v30 = 1;
      v31 = &v5->mTrail.mData[(signed int)UFG::qSignedMod(v5->mTrail.mLast - v30, v5->mTrail.mCapacity)].vPosition.x;
      v33 = (__m128)LODWORD(v2->y);
      v32 = v2->x - *v31;
      v33.m128_f32[0] = v33.m128_f32[0] - v31[1];
      v34 = v2->z - v31[2];
      v35 = v33;
      v35.m128_f32[0] = (float)((float)(v33.m128_f32[0] * v33.m128_f32[0]) + (float)(v32 * v32)) + (float)(v34 * v34);
      if ( v35.m128_f32[0] != 0.0 )
        v4 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v35));
      v31[4] = v32 * v4;
      v31[5] = v33.m128_f32[0] * v4;
      v31[6] = v34 * v4;
      v31[3] = v6;
    }
  }
}

