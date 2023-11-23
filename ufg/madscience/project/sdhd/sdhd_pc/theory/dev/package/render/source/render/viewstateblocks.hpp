// File Line: 64
// RVA: 0x7A30
void __fastcall Render::cbLocalTransformState::cbLocalTransformState(
        Render::cbLocalTransformState *this,
        UFG::qMatrix44 *world_view,
        UFG::qMatrix44 *world_view_proj,
        UFG::qMatrix44 *local_world)
{
  __int16 v8; // ax
  unsigned __int16 Param; // ax
  char *v10; // rax
  char *v11; // rbx
  UFG::qVector4 v12; // xmm2
  UFG::qVector4 v13; // xmm1
  UFG::qVector4 v14; // xmm0
  UFG::qMatrix44 *v15; // rax
  UFG::qVector4 v16; // xmm2
  UFG::qVector4 v17; // xmm1
  UFG::qVector4 v18; // xmm0
  UFG::qMatrix44 *v19; // rax
  UFG::qVector4 v20; // xmm2
  UFG::qVector4 v21; // xmm1
  UFG::qVector4 v22; // xmm0
  UFG::qMatrix44 result; // [rsp+28h] [rbp-60h] BYREF

  this->mPrev = this;
  this->mNext = this;
  this->mCallback = 0i64;
  v8 = Render::cbLocalTransformState::sStateParamIndex;
  this->mStateParamIndex = Render::cbLocalTransformState::sStateParamIndex;
  *(_WORD *)&this->mFlags = 1;
  if ( v8 == -1 )
  {
    Param = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbLocalTransform");
    Render::cbLocalTransformState::sStateParamIndex = Param;
    this->mStateParamIndex = Param;
  }
  this->mCached_Remote.m_Stream = 0i64;
  v10 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0xC0u, 0x10u);
  this->mCached_Remote.m_Stream = v10;
  if ( v10 )
  {
    v11 = v10;
    v12 = local_world->v1;
    v13 = local_world->v2;
    v14 = local_world->v3;
    *(UFG::qVector4 *)v10 = local_world->v0;
    *((UFG::qVector4 *)v10 + 1) = v12;
    *((UFG::qVector4 *)v10 + 2) = v13;
    *((UFG::qVector4 *)v10 + 3) = v14;
    v15 = UFG::qMatrix44::operator*(local_world, &result, world_view);
    v16 = v15->v1;
    v17 = v15->v2;
    v18 = v15->v3;
    *((_OWORD *)v11 + 4) = v15->v0;
    *((UFG::qVector4 *)v11 + 5) = v16;
    *((UFG::qVector4 *)v11 + 6) = v17;
    *((UFG::qVector4 *)v11 + 7) = v18;
    v19 = UFG::qMatrix44::operator*(local_world, &result, world_view_proj);
    v20 = v19->v1;
    v21 = v19->v2;
    v22 = v19->v3;
    *((_OWORD *)v11 + 8) = v19->v0;
    *((UFG::qVector4 *)v11 + 9) = v20;
    *((UFG::qVector4 *)v11 + 10) = v21;
    *((UFG::qVector4 *)v11 + 11) = v22;
  }
}

// File Line: 170
// RVA: 0x7BA0
void __fastcall Render::cbLocalProjectionState::SetStateBlock(
        Render::cbLocalProjectionState *this,
        Illusion::StateValues *state_values)
{
  char *v4; // rsi
  __int16 v5; // dx
  void *m_Stream; // r8
  UFG::qMatrix44 result; // [rsp+20h] [rbp-48h] BYREF

  if ( !this->mCached_Remote.m_Stream )
  {
    v4 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x40u, 0x10u);
    this->mCached_Remote.m_Stream = v4;
    if ( v4 )
      *(UFG::qMatrix44 *)v4 = *UFG::qMatrix44::operator*(this->mLocalWorld, &result, this->mWorldViewProjection);
  }
  v5 = Render::cbLocalProjectionState::sStateParamIndex;
  m_Stream = this->mCached_Remote.m_Stream;
  if ( (unsigned int)(__int16)Render::cbLocalProjectionState::sStateParamIndex >= 0x40 )
    state_values->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)Render::cbLocalProjectionState::sStateParamIndex
                                                    - 64);
  else
    state_values->mSetValueMask.mFlags[0] |= 1i64 << Render::cbLocalProjectionState::sStateParamIndex;
  state_values->mParamValues[v5] = m_Stream;
}

// File Line: 207
// RVA: 0x16650
void __fastcall Render::cbScreenProjectionState::SetStateBlock(
        Render::cbScreenProjectionState *this,
        Illusion::StateValues *state_values)
{
  char *v3; // rax
  CB_LocalTransform *v4; // rdx
  char *v5; // rsi
  char *v6; // r8
  __int64 v7; // rcx
  __int128 v8; // xmm0
  __int16 v9; // ax

  v3 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0xC0u, 0x10u);
  v4 = &Render::cbScreenProjectionState::sScreenLocalTransform;
  v5 = v3;
  v6 = v3;
  if ( (((unsigned __int8)v3 | (unsigned __int8)&Render::cbScreenProjectionState::sScreenLocalTransform) & 0xF) != 0 )
  {
    memmove(v3, &Render::cbScreenProjectionState::sScreenLocalTransform, 0xC0ui64);
  }
  else
  {
    v7 = 1i64;
    do
    {
      v8 = *(_OWORD *)v4->LocalWorld;
      v6 += 128;
      v4 = (CB_LocalTransform *)((char *)v4 + 128);
      *((_OWORD *)v6 - 8) = v8;
      *((_OWORD *)v6 - 7) = *(_OWORD *)&v4[-1].LocalView[4];
      *((_OWORD *)v6 - 6) = *(_OWORD *)&v4[-1].LocalView[8];
      *((_OWORD *)v6 - 5) = *(_OWORD *)&v4[-1].LocalView[12];
      *((_OWORD *)v6 - 4) = *(_OWORD *)v4[-1].LocalProjection;
      *((_OWORD *)v6 - 3) = *(_OWORD *)&v4[-1].LocalProjection[4];
      *((_OWORD *)v6 - 2) = *(_OWORD *)&v4[-1].LocalProjection[8];
      *((_OWORD *)v6 - 1) = *(_OWORD *)&v4[-1].LocalProjection[12];
      --v7;
    }
    while ( v7 );
    *(_OWORD *)v6 = *(_OWORD *)v4->LocalWorld;
    *((_OWORD *)v6 + 1) = *(_OWORD *)&v4->LocalWorld[4];
    *((_OWORD *)v6 + 2) = *(_OWORD *)&v4->LocalWorld[8];
    *((_OWORD *)v6 + 3) = *(_OWORD *)&v4->LocalWorld[12];
  }
  v9 = Render::cbScreenProjectionState::sStateParamIndex;
  if ( (unsigned int)(__int16)Render::cbScreenProjectionState::sStateParamIndex >= 0x40 )
    state_values->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)Render::cbScreenProjectionState::sStateParamIndex
                                                    - 64);
  else
    state_values->mSetValueMask.mFlags[0] |= 1i64 << Render::cbScreenProjectionState::sStateParamIndex;
  state_values->mParamValues[v9] = v5;
}

// File Line: 245
// RVA: 0x2CC30
void __fastcall Render::cbShadowTransformState::SetStateBlock(
        Render::cbShadowTransformState *this,
        Illusion::StateValues *state_values)
{
  char *v4; // rax
  char *m_Stream; // r15
  int v6; // r14d
  __int64 v7; // rsi
  __int64 v8; // rdi
  UFG::qMatrix44 *v9; // rbx
  UFG::qMatrix44 *v10; // rax
  UFG::qMatrix44 *v11; // rax
  UFG::qMatrix44 *v12; // rax
  UFG::qVector4 v13; // xmm3
  UFG::qVector4 v14; // xmm2
  UFG::qVector4 v15; // xmm1
  const float *mCutplanes; // rax
  const float *mBlurWidths; // rax
  const float *mBiases; // rax
  void *v19; // r8
  __int16 v20; // dx
  UFG::qMatrix44 result; // [rsp+28h] [rbp-E0h] BYREF
  UFG::qMatrix44 v22; // [rsp+68h] [rbp-A0h] BYREF
  UFG::qMatrix44 v23; // [rsp+A8h] [rbp-60h] BYREF

  if ( !this->mCached_Remote.m_Stream || Render::gDisableBlockCaching )
  {
    v4 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x120u, 0x10u);
    this->mCached_Remote.m_Stream = v4;
    if ( v4 )
    {
      if ( (`Render::cbShadowTransformState::SetStateBlock::`8::`local static guard & 1) == 0 )
      {
        `Render::cbShadowTransformState::SetStateBlock::`8::`local static guard |= 1u;
        `Render::cbShadowTransformState::SetStateBlock::`8::viewCorrector.v0 = (UFG::qVector4)_xmm;
        `Render::cbShadowTransformState::SetStateBlock::`8::viewCorrector.v1 = (UFG::qVector4)_xmm;
        `Render::cbShadowTransformState::SetStateBlock::`8::viewCorrector.v2 = (UFG::qVector4)_xmm;
        `Render::cbShadowTransformState::SetStateBlock::`8::viewCorrector.v3 = (UFG::qVector4)_xmm;
      }
      m_Stream = (char *)this->mCached_Remote.m_Stream;
      v6 = 0;
      v7 = 0i64;
      do
      {
        v8 = (__int64)v6 << 6;
        v9 = (UFG::qMatrix44 *)((char *)this->mProjection + v8);
        v10 = UFG::qMatrix44::operator*(this->mViewWorld, &result, (UFG::qMatrix44 *)((char *)this->mWorldView + v8));
        v11 = UFG::qMatrix44::operator*(v10, &v22, v9);
        v12 = UFG::qMatrix44::operator*(v11, &v23, &`Render::cbShadowTransformState::SetStateBlock::`8::viewCorrector);
        v13 = v12->v1;
        v14 = v12->v2;
        v15 = v12->v3;
        *(UFG::qVector4 *)&m_Stream[v8] = v12->v0;
        *(UFG::qVector4 *)&m_Stream[v8 + 16] = v13;
        *(UFG::qVector4 *)&m_Stream[v8 + 32] = v14;
        *(UFG::qVector4 *)&m_Stream[v8 + 48] = v15;
        if ( !v6 )
        {
          mCutplanes = this->mCutplanes;
          if ( mCutplanes )
            *(float *)&m_Stream[v7 * 4 + 256] = mCutplanes[v7];
        }
        mBlurWidths = this->mBlurWidths;
        if ( mBlurWidths && v6 < 3 )
          *(float *)&m_Stream[v7 * 4 + 260] = mBlurWidths[v7];
        mBiases = this->mBiases;
        if ( mBiases )
          *(float *)&m_Stream[v7 * 4 + 272] = mBiases[v7];
        ++v6;
        ++v7;
      }
      while ( v6 < 4 );
    }
  }
  v19 = this->mCached_Remote.m_Stream;
  v20 = Render::cbShadowTransformState::sStateParamIndex;
  if ( (unsigned int)(__int16)Render::cbShadowTransformState::sStateParamIndex >= 0x40 )
    state_values->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)Render::cbShadowTransformState::sStateParamIndex
                                                    - 64);
  else
    state_values->mSetValueMask.mFlags[0] |= 1i64 << Render::cbShadowTransformState::sStateParamIndex;
  state_values->mParamValues[v20] = v19;
}

// File Line: 475
// RVA: 0x7C60
void __fastcall Render::cbLocalTransformInverseState::SetStateBlock(
        Render::cbLocalTransformInverseState *this,
        Illusion::StateValues *state_values)
{
  UFG::qMatrix44 *v4; // rax
  UFG::qMatrix44 *v5; // rbx
  UFG::qMatrix44 *v6; // rax
  __int16 v7; // dx
  void *m_Stream; // r8
  UFG::qMatrix44 result; // [rsp+20h] [rbp-48h] BYREF

  if ( !this->mCached_Remote.m_Stream )
  {
    v4 = (UFG::qMatrix44 *)UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x80u, 0x10u);
    this->mCached_Remote.m_Stream = v4;
    if ( v4 )
    {
      v5 = v4 + 1;
      UFG::qInverseAffine(v4, this->mLocalWorld);
      v6 = UFG::qMatrix44::operator*(this->mLocalWorld, &result, this->mWorldView);
      UFG::qInverseAffine(v5, v6);
    }
  }
  v7 = Render::cbLocalTransformInverseState::sStateParamIndex;
  m_Stream = this->mCached_Remote.m_Stream;
  if ( (unsigned int)(__int16)Render::cbLocalTransformInverseState::sStateParamIndex >= 0x40 )
    state_values->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)Render::cbLocalTransformInverseState::sStateParamIndex
                                                    - 64);
  else
    state_values->mSetValueMask.mFlags[0] |= 1i64 << Render::cbLocalTransformInverseState::sStateParamIndex;
  state_values->mParamValues[v7] = m_Stream;
}

// File Line: 593
// RVA: 0x16770
void __fastcall Render::cbViewTransformState::SetStateBlock(
        Render::cbViewTransformState *this,
        Illusion::StateValues *state_values)
{
  char *v4; // rax
  char *v5; // rbx
  UFG::qMatrix44 *mWorldViewProjection; // rcx
  UFG::qVector4 v7; // xmm3
  UFG::qVector4 v8; // xmm2
  UFG::qVector4 v9; // xmm1
  UFG::qMatrix44 *v10; // rcx
  UFG::qMatrix44 *mViewWorld; // rax
  UFG::qVector4 v12; // xmm3
  UFG::qVector4 v13; // xmm2
  UFG::qVector4 v14; // xmm1
  UFG::qMatrix44 *mProjection; // rcx
  UFG::qMatrix44 *v16; // rax
  float v17; // xmm0_4
  void *v18; // rax
  UFG::qVector2 *mScreenOffset; // rcx
  __int16 v20; // dx
  void *m_Stream; // r8

  if ( !this->mCached_Remote.m_Stream || Render::gDisableBlockCaching )
  {
    v4 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0xF0u, 0x10u);
    v5 = v4;
    this->mCached_Remote.m_Stream = v4;
    if ( v4 )
    {
      mWorldViewProjection = this->mWorldViewProjection;
      v7 = mWorldViewProjection->v1;
      v8 = mWorldViewProjection->v2;
      v9 = mWorldViewProjection->v3;
      *((_OWORD *)v4 + 4) = mWorldViewProjection->v0;
      *((UFG::qVector4 *)v4 + 5) = v7;
      v10 = (UFG::qMatrix44 *)(v4 + 128);
      *((UFG::qVector4 *)v4 + 6) = v8;
      *((UFG::qVector4 *)v4 + 7) = v9;
      mViewWorld = this->mViewWorld;
      v12 = mViewWorld->v1;
      v13 = mViewWorld->v2;
      v14 = mViewWorld->v3;
      *(UFG::qVector4 *)v5 = mViewWorld->v0;
      *((UFG::qVector4 *)v5 + 1) = v12;
      *((UFG::qVector4 *)v5 + 2) = v13;
      *((UFG::qVector4 *)v5 + 3) = v14;
      UFG::qInverseAffine(v10, this->mViewWorld);
      mProjection = this->mProjection;
      *((_DWORD *)v5 + 48) = LODWORD(mProjection->v3.x);
      *((_DWORD *)v5 + 49) = LODWORD(mProjection->v3.y);
      v16 = this->mViewWorld;
      *((_QWORD *)v5 + 25) = 0i64;
      v12.x = (float)((float)((float)(v16->v1.x + v16->v0.x) + v16->v2.x) * 0.0) + v16->v3.x;
      v14.x = (float)((float)((float)(v16->v1.y + v16->v0.y) + v16->v2.y) * 0.0) + v16->v3.y;
      v17 = (float)((float)((float)(v16->v1.z + v16->v0.z) + v16->v2.z) * 0.0) + v16->v3.z;
      v18 = state_values->mParamValues[11];
      *((_DWORD *)v5 + 52) = LODWORD(v12.x);
      *((_DWORD *)v5 + 53) = LODWORD(v14.x);
      *((float *)v5 + 54) = v17;
      *((_DWORD *)v5 + 55) = 1065353216;
      if ( v18 )
      {
        *((float *)v5 + 56) = 1.0 / (float)**(int **)v18;
        *((float *)v5 + 57) = 1.0 / (float)*(int *)(*(_QWORD *)v18 + 4i64);
      }
      else
      {
        *((_QWORD *)v5 + 28) = 0i64;
      }
      mScreenOffset = this->mScreenOffset;
      *((_DWORD *)v5 + 58) = LODWORD(mScreenOffset->x);
      *((_DWORD *)v5 + 59) = LODWORD(mScreenOffset->y);
    }
  }
  v20 = Render::cbViewTransformState::sStateParamIndex;
  m_Stream = this->mCached_Remote.m_Stream;
  if ( (unsigned int)(__int16)Render::cbViewTransformState::sStateParamIndex >= 0x40 )
    state_values->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)Render::cbViewTransformState::sStateParamIndex
                                                    - 64);
  else
    state_values->mSetValueMask.mFlags[0] |= 1i64 << Render::cbViewTransformState::sStateParamIndex;
  state_values->mParamValues[v20] = m_Stream;
}

// File Line: 662
// RVA: 0x2ABA0
void __fastcall Render::cbExternalViewTransformState::cbExternalViewTransformState(
        Render::cbExternalViewTransformState *this,
        UFG::qMatrix44 *world_view,
        UFG::qMatrix44 *projection)
{
  __int16 v6; // ax
  unsigned __int16 Param; // ax

  this->mPrev = this;
  this->mNext = this;
  this->mCallback = 0i64;
  v6 = Render::cbExternalViewTransformState::sStateParamIndex;
  this->mStateParamIndex = Render::cbExternalViewTransformState::sStateParamIndex;
  *(_WORD *)&this->mFlags = 1;
  if ( v6 == -1 )
  {
    Param = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbExternalViewTransform");
    Render::cbExternalViewTransformState::sStateParamIndex = Param;
    this->mStateParamIndex = Param;
  }
  this->mWorldView = world_view;
  this->mProjection = projection;
  this->mCached_Remote.m_Stream = 0i64;
}

// File Line: 667
// RVA: 0x2C9F0
void __fastcall Render::cbExternalViewTransformState::SetStateBlock(
        Render::cbExternalViewTransformState *this,
        Illusion::StateValues *state_values)
{
  char *v4; // rax
  float *v5; // rdx
  UFG::qMatrix44 *mWorldView; // rcx
  __m128 v7; // xmm7
  __m128 v8; // xmm9
  __m128 v9; // xmm10
  __m128 v10; // xmm11
  __m128 v11; // xmm2
  __m128 v12; // xmm5
  UFG::qMatrix44 *mProjection; // rax
  __int16 v14; // dx
  void *m_Stream; // r8

  if ( !this->mCached_Remote.m_Stream || Render::gDisableBlockCaching )
  {
    v4 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x80u, 0x10u);
    v5 = (float *)v4;
    this->mCached_Remote.m_Stream = v4;
    if ( v4 )
    {
      mWorldView = this->mWorldView;
      v7 = (__m128)mWorldView->v3;
      v8 = (__m128)mWorldView->v2;
      v9 = (__m128)mWorldView->v1;
      v10 = (__m128)mWorldView->v0;
      v11 = _mm_mul_ps(_mm_shuffle_ps(_xmm, _xmm, 0), (__m128)mWorldView->v0);
      v12 = _mm_mul_ps(_mm_shuffle_ps(_xmm, _xmm, 0), (__m128)mWorldView->v0);
      *(UFG::qVector4 *)v4 = mWorldView->v0;
      *((__m128 *)v4 + 1) = v9;
      *((__m128 *)v4 + 2) = v8;
      *((__m128 *)v4 + 3) = v7;
      *((__m128 *)v4 + 5) = _mm_add_ps(
                              _mm_mul_ps(_mm_shuffle_ps(_xmm, _xmm, 255), v7),
                              _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(_xmm, _xmm, 0), v10), _xmm),
                                  _mm_mul_ps(_mm_shuffle_ps(_xmm, _xmm, 85), v9)),
                                _mm_mul_ps(_mm_shuffle_ps(_xmm, _xmm, 170), v8)));
      *((__m128 *)v4 + 6) = _mm_add_ps(
                              _mm_mul_ps(_mm_shuffle_ps(_xmm, _xmm, 255), v7),
                              _mm_add_ps(
                                _mm_add_ps(_mm_add_ps(v12, _xmm), _mm_mul_ps(_mm_shuffle_ps(_xmm, _xmm, 85), v9)),
                                _mm_mul_ps(_mm_shuffle_ps(_xmm, _xmm, 170), v8)));
      *((__m128 *)v4 + 7) = _mm_add_ps(
                              _mm_mul_ps(_mm_shuffle_ps(_xmm, _xmm, 255), v7),
                              _mm_add_ps(
                                _mm_add_ps(_mm_add_ps(v11, _xmm), _mm_mul_ps(_mm_shuffle_ps(_xmm, _xmm, 85), v9)),
                                _mm_mul_ps(_mm_shuffle_ps(_xmm, _xmm, 170), v8)));
      mProjection = this->mProjection;
      v5[16] = 1.0 / mProjection->v0.x;
      v5[17] = 1.0 / mProjection->v1.y;
      v5[18] = mProjection->v3.z / mProjection->v2.z;
      v5[19] = mProjection->v3.z / (float)(mProjection->v2.z + 1.0);
    }
  }
  v14 = Render::cbExternalViewTransformState::sStateParamIndex;
  m_Stream = this->mCached_Remote.m_Stream;
  if ( (unsigned int)(__int16)Render::cbExternalViewTransformState::sStateParamIndex >= 0x40 )
    state_values->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)Render::cbExternalViewTransformState::sStateParamIndex
                                                    - 64);
  else
    state_values->mSetValueMask.mFlags[0] |= 1i64 << Render::cbExternalViewTransformState::sStateParamIndex;
  state_values->mParamValues[v14] = m_Stream;
}

