// File Line: 64
// RVA: 0x7A30
void __fastcall Render::cbLocalTransformState::cbLocalTransformState(Render::cbLocalTransformState *this, UFG::qMatrix44 *world_view, UFG::qMatrix44 *world_view_proj, UFG::qMatrix44 *local_world)
{
  UFG::qMatrix44 *v4; // rsi
  UFG::qMatrix44 *v5; // rbp
  UFG::qMatrix44 *v6; // r14
  Render::cbLocalTransformState *v7; // rdi
  __int16 v8; // ax
  unsigned __int16 v9; // ax
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
  UFG::qMatrix44 result; // [rsp+28h] [rbp-60h]

  v4 = local_world;
  v5 = world_view_proj;
  v6 = world_view;
  v7 = this;
  this->mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&this->mPrev;
  this->mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&this->mPrev;
  this->mCallback = 0i64;
  v8 = Render::cbLocalTransformState::sStateParamIndex;
  this->mStateParamIndex = Render::cbLocalTransformState::sStateParamIndex;
  *(_WORD *)&this->mFlags = 1;
  if ( v8 == -1 )
  {
    v9 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbLocalTransform");
    Render::cbLocalTransformState::sStateParamIndex = v9;
    v7->mStateParamIndex = v9;
  }
  v7->mCached_Remote.m_Stream = 0i64;
  v10 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0xC0u, 0x10u);
  v7->mCached_Remote.m_Stream = v10;
  if ( v10 )
  {
    v11 = v10;
    v12 = v4->v1;
    v13 = v4->v2;
    v14 = v4->v3;
    *(UFG::qVector4 *)v10 = v4->v0;
    *((UFG::qVector4 *)v10 + 1) = v12;
    *((UFG::qVector4 *)v10 + 2) = v13;
    *((UFG::qVector4 *)v10 + 3) = v14;
    v15 = UFG::qMatrix44::operator*(v4, &result, v6);
    v16 = v15->v1;
    v17 = v15->v2;
    v18 = v15->v3;
    *((_OWORD *)v11 + 4) = v15->v0;
    *((UFG::qVector4 *)v11 + 5) = v16;
    *((UFG::qVector4 *)v11 + 6) = v17;
    *((UFG::qVector4 *)v11 + 7) = v18;
    v19 = UFG::qMatrix44::operator*(v4, &result, v5);
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
void __fastcall Render::cbLocalProjectionState::SetStateBlock(Render::cbLocalProjectionState *this, Illusion::StateValues *state_values)
{
  Illusion::StateValues *v2; // rbx
  Render::cbLocalProjectionState *v3; // rdi
  char *v4; // rsi
  UFG::qMatrix44 *v5; // rax
  __int16 v6; // dx
  void *v7; // r8
  UFG::qMatrix44 result; // [rsp+20h] [rbp-48h]

  v2 = state_values;
  v3 = this;
  if ( !this->mCached_Remote.m_Stream )
  {
    v4 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x40u, 0x10u);
    v3->mCached_Remote.m_Stream = v4;
    if ( v4 )
    {
      v5 = UFG::qMatrix44::operator*(v3->mLocalWorld, &result, v3->mWorldViewProjection);
      *(UFG::qVector4 *)v4 = v5->v0;
      *((_OWORD *)v4 + 1) = v5->v1;
      *((_OWORD *)v4 + 2) = v5->v2;
      *((_OWORD *)v4 + 3) = v5->v3;
    }
  }
  v6 = Render::cbLocalProjectionState::sStateParamIndex;
  v7 = v3->mCached_Remote.m_Stream;
  if ( (unsigned int)(signed __int16)Render::cbLocalProjectionState::sStateParamIndex >= 0x40 )
    v2->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)Render::cbLocalProjectionState::sStateParamIndex - 64);
  else
    v2->mSetValueMask.mFlags[0] |= 1i64 << Render::cbLocalProjectionState::sStateParamIndex;
  v2->mParamValues[v6] = v7;
}

// File Line: 207
// RVA: 0x16650
void __fastcall Render::cbScreenProjectionState::SetStateBlock(Render::cbScreenProjectionState *this, Illusion::StateValues *state_values)
{
  Illusion::StateValues *v2; // rdi
  char *v3; // rax
  CB_LocalTransform *v4; // rdx
  char *v5; // rsi
  char *v6; // r8
  signed __int64 v7; // rcx
  __int128 v8; // xmm0
  __int16 v9; // ax

  v2 = state_values;
  v3 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0xC0u, 0x10u);
  v4 = &Render::cbScreenProjectionState::sScreenLocalTransform;
  v5 = v3;
  v6 = v3;
  if ( ((unsigned __int8)v3 | (unsigned __int8)&Render::cbScreenProjectionState::sScreenLocalTransform) & 0xF )
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
  if ( (unsigned int)(signed __int16)Render::cbScreenProjectionState::sStateParamIndex >= 0x40 )
    v2->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)Render::cbScreenProjectionState::sStateParamIndex - 64);
  else
    v2->mSetValueMask.mFlags[0] |= 1i64 << Render::cbScreenProjectionState::sStateParamIndex;
  v2->mParamValues[v9] = v5;
}

// File Line: 245
// RVA: 0x2CC30
void __fastcall Render::cbShadowTransformState::SetStateBlock(Render::cbShadowTransformState *this, Illusion::StateValues *state_values)
{
  Illusion::StateValues *v2; // r12
  Render::cbShadowTransformState *v3; // rbp
  char *v4; // rax
  char *v5; // r15
  signed int v6; // er14
  __int64 v7; // rsi
  signed __int64 v8; // rdi
  UFG::qMatrix44 *v9; // rbx
  UFG::qMatrix44 *v10; // rax
  UFG::qMatrix44 *v11; // rax
  UFG::qMatrix44 *v12; // rax
  UFG::qVector4 v13; // xmm3
  UFG::qVector4 v14; // xmm2
  UFG::qVector4 v15; // xmm1
  const float *v16; // rax
  const float *v17; // rax
  const float *v18; // rax
  void *v19; // r8
  __int16 v20; // dx
  UFG::qMatrix44 result; // [rsp+28h] [rbp-E0h]
  UFG::qMatrix44 v22; // [rsp+68h] [rbp-A0h]
  UFG::qMatrix44 v23; // [rsp+A8h] [rbp-60h]

  v2 = state_values;
  v3 = this;
  if ( !this->mCached_Remote.m_Stream || Render::gDisableBlockCaching )
  {
    v4 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x120u, 0x10u);
    v3->mCached_Remote.m_Stream = v4;
    if ( v4 )
    {
      if ( !(`Render::cbShadowTransformState::SetStateBlock'::`8'::`local static guard' & 1) )
      {
        `Render::cbShadowTransformState::SetStateBlock'::`8'::`local static guard' |= 1u;
        `Render::cbShadowTransformState::SetStateBlock'::`8'::viewCorrector.v0 = (UFG::qVector4)_xmm;
        `Render::cbShadowTransformState::SetStateBlock'::`8'::viewCorrector.v1 = (UFG::qVector4)_xmm;
        `Render::cbShadowTransformState::SetStateBlock'::`8'::viewCorrector.v2 = (UFG::qVector4)_xmm;
        `Render::cbShadowTransformState::SetStateBlock'::`8'::viewCorrector.v3 = (UFG::qVector4)_xmm;
      }
      v5 = (char *)v3->mCached_Remote.m_Stream;
      v6 = 0;
      v7 = 0i64;
      do
      {
        v8 = (signed __int64)v6 << 6;
        v9 = (UFG::qMatrix44 *)((char *)v3->mProjection + v8);
        v10 = UFG::qMatrix44::operator*(v3->mViewWorld, &result, (UFG::qMatrix44 *)((char *)v3->mWorldView + v8));
        v11 = UFG::qMatrix44::operator*(v10, &v22, v9);
        v12 = UFG::qMatrix44::operator*(v11, &v23, &`Render::cbShadowTransformState::SetStateBlock'::`8'::viewCorrector);
        v13 = v12->v1;
        v14 = v12->v2;
        v15 = v12->v3;
        *(UFG::qVector4 *)&v5[v8] = v12->v0;
        *(UFG::qVector4 *)&v5[v8 + 16] = v13;
        *(UFG::qVector4 *)&v5[v8 + 32] = v14;
        *(UFG::qVector4 *)&v5[v8 + 48] = v15;
        if ( !v6 )
        {
          v16 = v3->mCutplanes;
          if ( v16 )
            *(float *)&v5[v7 * 4 + 256] = v16[v7];
        }
        v17 = v3->mBlurWidths;
        if ( v17 && v6 < 3 )
          *(float *)&v5[v7 * 4 + 260] = v17[v7];
        v18 = v3->mBiases;
        if ( v18 )
          *(float *)&v5[v7 * 4 + 272] = v18[v7];
        ++v6;
        ++v7;
      }
      while ( v6 < 4 );
    }
  }
  v19 = v3->mCached_Remote.m_Stream;
  v20 = Render::cbShadowTransformState::sStateParamIndex;
  if ( (unsigned int)(signed __int16)Render::cbShadowTransformState::sStateParamIndex >= 0x40 )
    v2->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)Render::cbShadowTransformState::sStateParamIndex - 64);
  else
    v2->mSetValueMask.mFlags[0] |= 1i64 << Render::cbShadowTransformState::sStateParamIndex;
  v2->mParamValues[v20] = v19;
}

// File Line: 475
// RVA: 0x7C60
void __fastcall Render::cbLocalTransformInverseState::SetStateBlock(Render::cbLocalTransformInverseState *this, Illusion::StateValues *state_values)
{
  Illusion::StateValues *v2; // rdi
  Render::cbLocalTransformInverseState *v3; // rsi
  char *v4; // rax
  UFG::qMatrix44 *v5; // rbx
  UFG::qMatrix44 *v6; // rax
  __int16 v7; // dx
  void *v8; // r8
  UFG::qMatrix44 result; // [rsp+20h] [rbp-48h]

  v2 = state_values;
  v3 = this;
  if ( !this->mCached_Remote.m_Stream )
  {
    v4 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x80u, 0x10u);
    v3->mCached_Remote.m_Stream = v4;
    if ( v4 )
    {
      v5 = (UFG::qMatrix44 *)(v4 + 64);
      UFG::qInverseAffine((UFG::qMatrix44 *)v4, v3->mLocalWorld);
      v6 = UFG::qMatrix44::operator*(v3->mLocalWorld, &result, v3->mWorldView);
      UFG::qInverseAffine(v5, v6);
    }
  }
  v7 = Render::cbLocalTransformInverseState::sStateParamIndex;
  v8 = v3->mCached_Remote.m_Stream;
  if ( (unsigned int)(signed __int16)Render::cbLocalTransformInverseState::sStateParamIndex >= 0x40 )
    v2->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)Render::cbLocalTransformInverseState::sStateParamIndex - 64);
  else
    v2->mSetValueMask.mFlags[0] |= 1i64 << Render::cbLocalTransformInverseState::sStateParamIndex;
  v2->mParamValues[v7] = v8;
}

// File Line: 593
// RVA: 0x16770
void __fastcall Render::cbViewTransformState::SetStateBlock(Render::cbViewTransformState *this, Illusion::StateValues *state_values)
{
  Illusion::StateValues *v2; // rdi
  Render::cbViewTransformState *v3; // rsi
  char *v4; // rax
  char *v5; // rbx
  _OWORD *v6; // rcx
  __int128 v7; // xmm3
  __int128 v8; // xmm2
  __int128 v9; // xmm1
  UFG::qMatrix44 *v10; // rcx
  _OWORD *v11; // rax
  __int128 v12; // xmm3
  __int128 v13; // xmm2
  __int128 v14; // xmm1
  UFG::qMatrix44 *v15; // rcx
  float *v16; // rax
  float v17; // xmm0_4
  void *v18; // rax
  UFG::qVector2 *v19; // rcx
  __int16 v20; // dx
  void *v21; // r8

  v2 = state_values;
  v3 = this;
  if ( !this->mCached_Remote.m_Stream || Render::gDisableBlockCaching )
  {
    v4 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0xF0u, 0x10u);
    v5 = v4;
    v3->mCached_Remote.m_Stream = v4;
    if ( v4 )
    {
      v6 = (_OWORD *)&v3->mWorldViewProjection->v0.x;
      v7 = v6[1];
      v8 = v6[2];
      v9 = v6[3];
      *((_OWORD *)v4 + 4) = *v6;
      *((_OWORD *)v4 + 5) = v7;
      v10 = (UFG::qMatrix44 *)(v4 + 128);
      *((_OWORD *)v4 + 6) = v8;
      *((_OWORD *)v4 + 7) = v9;
      v11 = (_OWORD *)&v3->mViewWorld->v0.x;
      v12 = v11[1];
      v13 = v11[2];
      v14 = v11[3];
      *(_OWORD *)v5 = *v11;
      *((_OWORD *)v5 + 1) = v12;
      *((_OWORD *)v5 + 2) = v13;
      *((_OWORD *)v5 + 3) = v14;
      UFG::qInverseAffine(v10, v3->mViewWorld);
      v15 = v3->mProjection;
      *((_DWORD *)v5 + 48) = LODWORD(v15->v3.x);
      *((_DWORD *)v5 + 49) = LODWORD(v15->v3.y);
      v16 = &v3->mViewWorld->v0.x;
      *((_QWORD *)v5 + 25) = 0i64;
      *(float *)&v12 = (float)((float)((float)(v16[4] + *v16) + v16[8]) * 0.0) + v16[12];
      *(float *)&v14 = (float)((float)((float)(v16[5] + v16[1]) + v16[9]) * 0.0) + v16[13];
      v17 = (float)((float)((float)(v16[6] + v16[2]) + v16[10]) * 0.0) + v16[14];
      v18 = v2->mParamValues[11];
      *((_DWORD *)v5 + 52) = v12;
      *((_DWORD *)v5 + 53) = v14;
      *((float *)v5 + 54) = v17;
      *((_DWORD *)v5 + 55) = 1065353216;
      if ( v18 )
      {
        *((float *)v5 + 56) = 1.0 / (float)**(signed int **)v18;
        *((float *)v5 + 57) = 1.0 / (float)*(signed int *)(*(_QWORD *)v18 + 4i64);
      }
      else
      {
        *((_QWORD *)v5 + 28) = 0i64;
      }
      v19 = v3->mScreenOffset;
      *((_DWORD *)v5 + 58) = LODWORD(v19->x);
      *((_DWORD *)v5 + 59) = LODWORD(v19->y);
    }
  }
  v20 = Render::cbViewTransformState::sStateParamIndex;
  v21 = v3->mCached_Remote.m_Stream;
  if ( (unsigned int)(signed __int16)Render::cbViewTransformState::sStateParamIndex >= 0x40 )
    v2->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)Render::cbViewTransformState::sStateParamIndex - 64);
  else
    v2->mSetValueMask.mFlags[0] |= 1i64 << Render::cbViewTransformState::sStateParamIndex;
  v2->mParamValues[v20] = v21;
}

// File Line: 662
// RVA: 0x2ABA0
void __fastcall Render::cbExternalViewTransformState::cbExternalViewTransformState(Render::cbExternalViewTransformState *this, UFG::qMatrix44 *world_view, UFG::qMatrix44 *projection)
{
  UFG::qMatrix44 *v3; // rdi
  UFG::qMatrix44 *v4; // rsi
  Render::cbExternalViewTransformState *v5; // rbx
  __int16 v6; // ax
  unsigned __int16 v7; // ax

  v3 = projection;
  v4 = world_view;
  v5 = this;
  this->mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&this->mPrev;
  this->mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&this->mPrev;
  this->mCallback = 0i64;
  v6 = Render::cbExternalViewTransformState::sStateParamIndex;
  this->mStateParamIndex = Render::cbExternalViewTransformState::sStateParamIndex;
  *(_WORD *)&this->mFlags = 1;
  if ( v6 == -1 )
  {
    v7 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbExternalViewTransform");
    Render::cbExternalViewTransformState::sStateParamIndex = v7;
    v5->mStateParamIndex = v7;
  }
  v5->mWorldView = v4;
  v5->mProjection = v3;
  v5->mCached_Remote.m_Stream = 0i64;
}

// File Line: 667
// RVA: 0x2C9F0
void __fastcall Render::cbExternalViewTransformState::SetStateBlock(Render::cbExternalViewTransformState *this, Illusion::StateValues *state_values)
{
  Illusion::StateValues *v2; // rbx
  Render::cbExternalViewTransformState *v3; // rdi
  char *v4; // rax
  float *v5; // rdx
  __m128 *v6; // rcx
  __m128 v7; // xmm7
  __m128 v8; // xmm9
  __m128 v9; // xmm10
  __m128 v10; // xmm11
  __m128 v11; // xmm2
  __m128 v12; // xmm5
  float *v13; // rax
  __int16 v14; // dx
  void *v15; // r8

  v2 = state_values;
  v3 = this;
  if ( !this->mCached_Remote.m_Stream || Render::gDisableBlockCaching )
  {
    v4 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x80u, 0x10u);
    v5 = (float *)v4;
    v3->mCached_Remote.m_Stream = v4;
    if ( v4 )
    {
      v6 = (__m128 *)v3->mWorldView;
      v7 = v6[3];
      v8 = v6[2];
      v9 = v6[1];
      v10 = *v6;
      v11 = _mm_mul_ps(_mm_shuffle_ps(_xmm, _xmm, 0), *v6);
      v12 = _mm_mul_ps(_mm_shuffle_ps(_xmm, _xmm, 0), *v6);
      *(__m128 *)v4 = *v6;
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
      v13 = &v3->mProjection->v0.x;
      v5[16] = 1.0 / *v13;
      v5[17] = 1.0 / v13[5];
      v5[18] = v13[14] / v13[10];
      v5[19] = v13[14] / (float)(v13[10] + 1.0);
    }
  }
  v14 = Render::cbExternalViewTransformState::sStateParamIndex;
  v15 = v3->mCached_Remote.m_Stream;
  if ( (unsigned int)(signed __int16)Render::cbExternalViewTransformState::sStateParamIndex >= 0x40 )
    v2->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)Render::cbExternalViewTransformState::sStateParamIndex - 64);
  else
    v2->mSetValueMask.mFlags[0] |= 1i64 << Render::cbExternalViewTransformState::sStateParamIndex;
  v2->mParamValues[v14] = v15;
}

