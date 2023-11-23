// File Line: 19
// RVA: 0x64A900
void __fastcall UFG::CrumbTrail::DebugDraw(UFG::CrumbTrail *this, UFG::qColour *color, int numCrumbsOverride)
{
  int mCount; // eax
  int v6; // ebx
  int mLast; // ecx
  float x; // xmm6_4
  float z; // xmm7_4
  float y; // xmm8_4
  int v11; // esi
  UFG::Crumb *v12; // rcx
  float v13; // xmm7_4
  float v14; // xmm8_4
  int v15; // eax
  int v16; // ecx
  UFG::Crumb *v17; // rcx
  unsigned int v18; // xmm1_4
  unsigned int v19; // xmm2_4
  Render::DebugDrawContext *Context; // rax
  UFG::qVector3 p1; // [rsp+40h] [rbp-68h] BYREF
  UFG::qVector3 p0; // [rsp+50h] [rbp-58h] BYREF

  mCount = this->mTrail.mCount;
  v6 = mCount;
  if ( numCrumbsOverride > -1 && numCrumbsOverride < mCount )
    v6 = numCrumbsOverride;
  if ( v6 > 1 )
  {
    mLast = this->mTrail.mLast;
    if ( mCount > 0 )
      mCount = 0;
    x = UFG::qVector3::msDirUp.x;
    z = UFG::qVector3::msDirUp.z;
    y = UFG::qVector3::msDirUp.y;
    v11 = 1;
    v12 = &this->mTrail.mData[(int)UFG::qSignedMod(mLast - mCount, this->mTrail.mCapacity)];
    v13 = z + v12->vPosition.z;
    v14 = y + v12->vPosition.y;
    p0.x = x + v12->vPosition.x;
    p0.y = v14;
    p0.z = v13;
    do
    {
      v15 = this->mTrail.mCount;
      v16 = 0;
      if ( v11 > 0 )
        v16 = v11;
      if ( v16 < v15 )
        v15 = v16;
      v17 = &this->mTrail.mData[(int)UFG::qSignedMod(this->mTrail.mLast - v15, this->mTrail.mCapacity)];
      *(float *)&v18 = UFG::qVector3::msDirUp.z + v17->vPosition.z;
      *(float *)&v19 = UFG::qVector3::msDirUp.y + v17->vPosition.y;
      p1.x = UFG::qVector3::msDirUp.x + v17->vPosition.x;
      *(_QWORD *)&p1.y = __PAIR64__(v18, v19);
      Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(
                                              Render::DebugDrawManager::mInstance,
                                              2u);
      Render::DebugDrawContext::DrawLine(Context, &p0, &p1, color, &UFG::qMatrix44::msIdentity, 0i64, 0);
      p0 = p1;
      ++v11;
    }
    while ( v11 < v6 );
  }
}

// File Line: 60
// RVA: 0x644F80
float __fastcall UFG::ApproximateCurvature(UFG::qVector3 *a, UFG::qVector3 *b, UFG::qVector3 *c)
{
  float z; // xmm9_4
  float y; // xmm11_4
  float v5; // xmm8_4
  float v6; // xmm7_4
  __m128 x_low; // xmm5
  float v8; // xmm2_4
  float v9; // xmm6_4
  float v10; // xmm13_4
  float v11; // xmm4_4
  float v12; // xmm6_4
  float v13; // xmm12_4
  __m128 v14; // xmm1
  float v15; // xmm3_4
  float v16; // xmm13_4
  float v17; // xmm0_4

  z = a->z;
  y = a->y;
  v5 = b->y - y;
  v6 = b->x - a->x;
  x_low = (__m128)LODWORD(c->x);
  v8 = 0.0;
  v9 = b->z;
  x_low.m128_f32[0] = x_low.m128_f32[0] - b->x;
  v10 = c->y - b->y;
  v14 = x_low;
  v11 = c->z - v9;
  v12 = v9 - z;
  v13 = (float)(v11 * v5) - (float)(v10 * v12);
  v14.m128_f32[0] = (float)(x_low.m128_f32[0] * v12) - (float)(v11 * v6);
  v15 = (float)(v10 * v6) - (float)(x_low.m128_f32[0] * v5);
  v16 = (float)((float)((float)((float)(v10 * v10) + (float)(x_low.m128_f32[0] * x_low.m128_f32[0])) + (float)(v11 * v11))
              * (float)((float)((float)(v5 * v5) + (float)(v6 * v6)) + (float)(v12 * v12)))
      * (float)((float)((float)((float)(y - c->y) * (float)(y - c->y))
                      + (float)((float)(a->x - c->x) * (float)(a->x - c->x)))
              + (float)((float)(z - c->z) * (float)(z - c->z)));
  if ( v15 <= 0.0 )
  {
    if ( v15 < 0.0 )
      v8 = FLOAT_N1_0;
  }
  else
  {
    v8 = *(float *)&FLOAT_1_0;
  }
  v17 = FLOAT_0_000099999997;
  if ( v16 >= 0.000099999997 )
    v17 = v16;
  v14.m128_f32[0] = (float)((float)((float)(v14.m128_f32[0] * v14.m128_f32[0]) + (float)(v13 * v13)) + (float)(v15 * v15))
                  / v17;
  return _mm_sqrt_ps(v14).m128_f32[0] * (float)(v8 * 2.0);
}

// File Line: 72
// RVA: 0x65F3C0
void __fastcall UFG::CrumbTrail::Update(UFG::CrumbTrail *this, UFG::qVector3 *position)
{
  int mCount; // edx
  float v4; // xmm6_4
  float v6; // xmm9_4
  bool v7; // bp
  float v8; // xmm8_4
  bool v9; // r14
  __m128 x_low; // xmm2
  UFG::Crumb *v11; // rax
  float v12; // xmm0_4
  __int64 mLast; // rcx
  UFG::Crumb *v14; // rbx
  int v15; // eax
  float v16; // xmm0_4
  int v17; // eax
  float v18; // xmm7_4
  UFG::Crumb *v19; // rcx
  float fCurvature; // xmm1_4
  float v21; // xmm3_4
  float v22; // xmm2_4
  float v23; // xmm0_4
  float x; // xmm1_4
  float y; // xmm2_4
  float z; // xmm3_4
  int v27; // edx
  int v28; // eax
  UFG::Crumb *v29; // rax
  int v30; // eax
  UFG::Crumb *v31; // rcx
  float v32; // xmm2_4
  __m128 y_low; // xmm3
  float v34; // xmm4_4
  __m128 v35; // xmm5

  mCount = this->mTrail.mCount;
  v4 = 0.0;
  v6 = 0.0;
  v7 = mCount == 0;
  v8 = UFG::AiDriverComponent::m_BreadCrumbGap;
  v9 = mCount == 0;
  if ( mCount )
  {
    x_low = (__m128)LODWORD(position->x);
    v11 = &this->mTrail.mData[this->mTrail.mLast];
    x_low.m128_f32[0] = (float)((float)((float)(x_low.m128_f32[0] - v11->vPosition.x)
                                      * (float)(x_low.m128_f32[0] - v11->vPosition.x))
                              + (float)((float)(position->y - v11->vPosition.y) * (float)(position->y - v11->vPosition.y)))
                      + (float)((float)(position->z - v11->vPosition.z) * (float)(position->z - v11->vPosition.z));
    v6 = _mm_sqrt_ps(x_low).m128_f32[0];
    v9 = v6 > UFG::AiDriverComponent::m_BreadCrumbGap;
  }
  v12 = 0.0;
  if ( mCount > 1 )
  {
    mLast = this->mTrail.mLast;
    v14 = &this->mTrail.mData[mLast];
    v15 = UFG::qSignedMod((int)mLast - 1, this->mTrail.mCapacity);
    v16 = UFG::ApproximateCurvature(&this->mTrail.mData[v15].vPosition, &v14->vPosition, position);
    v17 = this->mTrail.mCount;
    v18 = v16;
    if ( v17 > 1 )
      v17 = 1;
    v19 = &this->mTrail.mData[(int)UFG::qSignedMod(this->mTrail.mLast - v17, this->mTrail.mCapacity)];
    fCurvature = v19->fCurvature;
    if ( fCurvature >= v16 )
      v21 = v16;
    else
      v21 = v19->fCurvature;
    if ( fCurvature <= v16 )
      v22 = v16;
    else
      v22 = v19->fCurvature;
    v23 = FLOAT_0_000099999997;
    if ( v8 >= 0.000099999997 )
      v23 = v8;
    v12 = (float)(v6 * (float)((float)(v18 - fCurvature) / v23)) + fCurvature;
    if ( v12 <= v21 )
      v12 = v21;
    if ( v12 >= v22 )
      v12 = v22;
  }
  if ( !v7 )
    this->mTrail.mData[this->mTrail.mLast].fCurvature = v12;
  if ( v9 )
  {
    x = position->x;
    y = position->y;
    z = position->z;
    v27 = (this->mTrail.mLast + 1) % this->mTrail.mCapacity;
    v28 = this->mTrail.mCount;
    this->mTrail.mLast = v27;
    if ( v28 < this->mTrail.mCapacity )
      this->mTrail.mCount = v28 + 1;
    v29 = &this->mTrail.mData[v27];
    v29->vPosition.x = x;
    v29->vPosition.y = y;
    v29->vPosition.z = z;
    *(_QWORD *)&v29->fLength = 0i64;
    v29->vDirection.y = 0.0;
    v29->vDirection.z = 1.0;
    v29->fCurvature = v12;
    if ( !v7 )
    {
      v30 = this->mTrail.mCount;
      if ( v30 > 1 )
        v30 = 1;
      v31 = &this->mTrail.mData[(int)UFG::qSignedMod(this->mTrail.mLast - v30, this->mTrail.mCapacity)];
      y_low = (__m128)LODWORD(position->y);
      v32 = position->x - v31->vPosition.x;
      y_low.m128_f32[0] = y_low.m128_f32[0] - v31->vPosition.y;
      v34 = position->z - v31->vPosition.z;
      v35 = y_low;
      v35.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v32 * v32))
                      + (float)(v34 * v34);
      if ( v35.m128_f32[0] != 0.0 )
        v4 = 1.0 / _mm_sqrt_ps(v35).m128_f32[0];
      v31->vDirection.x = v32 * v4;
      v31->vDirection.y = y_low.m128_f32[0] * v4;
      v31->vDirection.z = v34 * v4;
      v31->fLength = v6;
    }
  }
}

