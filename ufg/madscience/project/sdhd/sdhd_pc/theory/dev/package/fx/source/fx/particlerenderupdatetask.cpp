// File Line: 34
// RVA: 0x146BBA0
__int64 Render::_dynamic_initializer_for__gTaskFunctionDecl_ParticleRenderUpdateTask__()
{
  UFG::qTaskFunctionDecl::qTaskFunctionDecl(
    &Render::gTaskFunctionDecl_ParticleRenderUpdateTask,
    &Render::gTaskFunctionDeclData_ParticleRenderUpdateTask);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gTaskFunctionDecl_ParticleRenderUpdateTask__);
}

// File Line: 48
// RVA: 0x1E24D0
void __fastcall Render::ParticleCreator::SetTaskParams(
        Render::ParticleCreator *this,
        Render::ParticleRenderUpdateTaskParam *taskParams)
{
  UFG::qVector4 v2; // xmm3
  UFG::qVector4 v4; // xmm2
  UFG::qVector4 v5; // xmm1
  float v6; // xmm2_4
  float y; // xmm6_4
  __m128 x_low; // xmm5
  float z; // xmm7_4
  __m128 v10; // xmm4
  float v11; // xmm1_4
  float v12; // xmm6_4
  __m128 v13; // xmm5
  float v14; // xmm7_4
  __m128 v15; // xmm4
  float v16; // xmm1_4
  float v17; // xmm6_4
  __m128 v18; // xmm5
  float v19; // xmm7_4
  __m128 v20; // xmm4
  void *fxOverride; // rdx
  Render::ParticleEmitterSettings *pSettings; // rdx
  __m128 v23; // xmm2
  UFG::qMemoryStreamer *mMemoryStreamer; // r9
  Render::FXqTaskMeshReader *p_mMeshEmitter; // rbx
  void *modelToEmitFrom; // rax
  int vertexIndexToStartMeshEmissionFrom; // r10d

  this->mTaskParams = taskParams;
  v2 = taskParams->curBasis.v1;
  v4 = taskParams->curBasis.v2;
  v5 = taskParams->curBasis.v3;
  this->mCurBasisNormalized.v0 = taskParams->curBasis.v0;
  this->mCurBasisNormalized.v1 = v2;
  this->mCurBasisNormalized.v2 = v4;
  v6 = 0.0;
  this->mCurBasisNormalized.v3 = v5;
  y = this->mCurBasisNormalized.v0.y;
  x_low = (__m128)LODWORD(this->mCurBasisNormalized.v0.x);
  v10 = x_low;
  z = this->mCurBasisNormalized.v0.z;
  v10.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(y * y)) + (float)(z * z);
  if ( v10.m128_f32[0] == 0.0 )
    v11 = 0.0;
  else
    v11 = 1.0 / _mm_sqrt_ps(v10).m128_f32[0];
  this->mCurBasisNormalized.v0.x = x_low.m128_f32[0] * v11;
  this->mCurBasisNormalized.v0.y = y * v11;
  this->mCurBasisNormalized.v0.z = z * v11;
  this->mCurBasisNormalized.v0.w = 0.0;
  v12 = this->mCurBasisNormalized.v1.y;
  v13 = (__m128)LODWORD(this->mCurBasisNormalized.v1.x);
  v14 = this->mCurBasisNormalized.v1.z;
  v15 = v13;
  v15.m128_f32[0] = (float)((float)(v13.m128_f32[0] * v13.m128_f32[0]) + (float)(v12 * v12)) + (float)(v14 * v14);
  if ( v15.m128_f32[0] == 0.0 )
    v16 = 0.0;
  else
    v16 = 1.0 / _mm_sqrt_ps(v15).m128_f32[0];
  this->mCurBasisNormalized.v1.x = v13.m128_f32[0] * v16;
  this->mCurBasisNormalized.v1.y = v12 * v16;
  this->mCurBasisNormalized.v1.z = v14 * v16;
  this->mCurBasisNormalized.v1.w = 0.0;
  v17 = this->mCurBasisNormalized.v2.y;
  v18 = (__m128)LODWORD(this->mCurBasisNormalized.v2.x);
  v19 = this->mCurBasisNormalized.v2.z;
  v20 = v18;
  v20.m128_f32[0] = (float)((float)(v18.m128_f32[0] * v18.m128_f32[0]) + (float)(v17 * v17)) + (float)(v19 * v19);
  if ( v20.m128_f32[0] != 0.0 )
    v6 = 1.0 / _mm_sqrt_ps(v20).m128_f32[0];
  this->mCurBasisNormalized.v2.x = v18.m128_f32[0] * v6;
  this->mCurBasisNormalized.v2.y = v17 * v6;
  this->mCurBasisNormalized.v2.z = v19 * v6;
  this->mCurBasisNormalized.v2.w = 0.0;
  this->mSeedBuffer = (int *)this->mSeedStream.mMainMemoryAddress;
  fxOverride = taskParams->fxOverride;
  if ( fxOverride )
    this->mFxOverrideStream.mMainMemoryAddress = fxOverride;
  pSettings = (Render::ParticleEmitterSettings *)taskParams->pSettings;
  if ( pSettings )
  {
    this->mParticleEmitterSettingsStream.mMainMemoryAddress = pSettings;
    this->mParticleSettings = pSettings;
  }
  v23 = (__m128)LODWORD(taskParams->curBasis.v0.x);
  mMemoryStreamer = this->mMemoryStreamer;
  p_mMeshEmitter = &this->mMeshEmitter;
  v23.m128_f32[0] = (float)((float)(v23.m128_f32[0] * v23.m128_f32[0])
                          + (float)(taskParams->curBasis.v0.y * taskParams->curBasis.v0.y))
                  + (float)(taskParams->curBasis.v0.z * taskParams->curBasis.v0.z);
  this->mTransformScale = (float)((float)(_mm_sqrt_ps(v23).m128_f32[0] - 1.0)
                                * this->mParticleSettings->mUseTransformScaling)
                        + 1.0;
  this->mSeed = taskParams->seed;
  modelToEmitFrom = taskParams->modelToEmitFrom;
  vertexIndexToStartMeshEmissionFrom = (int)taskParams->vertexIndexToStartMeshEmissionFrom;
  if ( modelToEmitFrom )
  {
    this->mMeshEmitter.mSeed = &this->mSeed;
    p_mMeshEmitter->mModelAddrInMainMem = modelToEmitFrom;
    this->mMeshEmitter.mMemoryStreamer = mMemoryStreamer;
    this->mMeshEmitter.mModelStream.mMainMemoryAddress = modelToEmitFrom;
    Render::FXqTaskMeshReader::LoadMesh(&this->mMeshEmitter, 0, (float)vertexIndexToStartMeshEmissionFrom);
    p_mMeshEmitter->mIsInitialized = 1;
  }
}

// File Line: 67
// RVA: 0x1DFC30
float __fastcall Render::ParticleCreator::AddResumeParticles(
        Render::ParticleCreator *this,
        Render::GenerateParticleParameters *generateParticleParams,
        Render::EmitterParticleAttribute *attributeBuffer,
        unsigned int *currentBufferCount)
{
  unsigned int v4; // edi
  float lastExpiry; // xmm8_4
  float creationSimTime; // xmm7_4
  int *seed; // r15
  float v12; // xmm0_4
  Render::ParticleEmitterSettings *mParticleSettings; // rdx
  float v14; // xmm6_4
  float x; // xmm0_4
  float y; // xmm1_4
  Render::EmitterParticleAttribute *v17; // rax
  Render::ParticleEmitterSettings *v18; // rdx
  UFG::qVector3 result; // [rsp+30h] [rbp-78h] BYREF

  v4 = 0;
  lastExpiry = this->mTaskParams->lastExpiry;
  creationSimTime = this->mTaskParams->creationSimTime;
  if ( this->mTaskParams->currentAddCount )
  {
    seed = &this->mSeed;
    do
    {
      v12 = UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed);
      mParticleSettings = this->mParticleSettings;
      v14 = (float)((float)((float)(mParticleSettings->mLifeMax - mParticleSettings->mLifeMin) * v12)
                  + mParticleSettings->mLifeMin)
          + creationSimTime;
      Render::CreateTimeUpdateJitterVector(
        &result,
        mParticleSettings,
        &this->mCurBasisNormalized,
        this->mTransformScale,
        seed);
      x = result.x;
      y = result.y;
      generateParticleParams->start_time = creationSimTime;
      generateParticleParams->end_time = v14;
      generateParticleParams->pos.x = x;
      generateParticleParams->pos.z = result.z;
      generateParticleParams->pos.y = y;
      v17 = Render::ParticleCreator::AddParticle(this, generateParticleParams, attributeBuffer, *currentBufferCount);
      if ( v17 )
      {
        v18 = this->mParticleSettings;
        if ( v18->mType != 1 )
          Render::ComputeResumeTimePosAndVel(
            v17,
            v18->mSettings.AnimUVScaleOffset[3],
            this->mTaskParams->simTime - creationSimTime,
            &UFG::qMatrix44::msIdentity,
            &UFG::qMatrix44::msIdentity);
        ++*currentBufferCount;
        if ( lastExpiry < v14 )
          lastExpiry = v14;
        creationSimTime = creationSimTime + this->mTaskParams->resumeTimeSkip;
      }
      ++v4;
    }
    while ( v4 < this->mTaskParams->currentAddCount );
  }
  return lastExpiry;
}

// File Line: 108
// RVA: 0x1DFE00
float __fastcall Render::ParticleCreator::AddTimeEmissionParticles(
        Render::ParticleCreator *this,
        Render::GenerateParticleParameters *generateParticleParams,
        Render::EmitterParticleAttribute *attributeBuffer,
        unsigned int *currentBufferCount)
{
  Render::ParticleRenderUpdateTaskParam *mTaskParams; // rax
  unsigned int v5; // ebx
  float lastExpiry; // xmm8_4
  int *seed; // r14
  float creationSimTime; // xmm6_4
  float v13; // xmm0_4
  Render::ParticleEmitterSettings *mParticleSettings; // rdx
  float v15; // xmm7_4
  float x; // xmm0_4
  float y; // xmm1_4
  UFG::qVector3 result; // [rsp+30h] [rbp-68h] BYREF

  mTaskParams = this->mTaskParams;
  v5 = 0;
  lastExpiry = this->mTaskParams->lastExpiry;
  if ( this->mTaskParams->currentAddCount )
  {
    seed = &this->mSeed;
    do
    {
      creationSimTime = mTaskParams->creationSimTime;
      v13 = UFG::qRandom(1.0, (unsigned int *)seed);
      mParticleSettings = this->mParticleSettings;
      v15 = (float)((float)((float)(mParticleSettings->mLifeMax - mParticleSettings->mLifeMin) * v13)
                  + mParticleSettings->mLifeMin)
          + creationSimTime;
      Render::CreateTimeUpdateJitterVector(
        &result,
        mParticleSettings,
        &this->mCurBasisNormalized,
        this->mTransformScale,
        seed);
      x = result.x;
      y = result.y;
      generateParticleParams->start_time = creationSimTime;
      generateParticleParams->end_time = v15;
      generateParticleParams->pos.x = x;
      generateParticleParams->pos.z = result.z;
      generateParticleParams->pos.y = y;
      if ( Render::ParticleCreator::AddParticle(this, generateParticleParams, attributeBuffer, *currentBufferCount) )
      {
        ++*currentBufferCount;
        if ( lastExpiry < v15 )
          lastExpiry = v15;
      }
      mTaskParams = this->mTaskParams;
      ++v5;
    }
    while ( v5 < this->mTaskParams->currentAddCount );
  }
  return lastExpiry;
}

// File Line: 138
// RVA: 0x1DF390
float __fastcall Render::ParticleCreator::AddDistanceEmissionParticles(
        Render::ParticleCreator *this,
        Render::GenerateParticleParameters *generateParticleParams,
        Render::EmitterParticleAttribute *attributeBuffer,
        unsigned int *currentBufferCount)
{
  Render::ParticleRenderUpdateTaskParam *mTaskParams; // r14
  __m128 y_low; // xmm2
  signed int v6; // edi
  float v10; // xmm1_4
  float v12; // xmm0_4
  float lastExpiry; // xmm11_4
  float t; // xmm12_4
  float spacing; // xmm13_4
  float x; // xmm0_4
  float v17; // xmm3_4
  float w; // xmm1_4
  float v19; // xmm0_4
  float y; // xmm1_4
  float z; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm0_4
  float v28; // xmm1_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  int *seed; // r12
  float v32; // xmm14_4
  float creationSimTime; // xmm9_4
  float v34; // xmm0_4
  Render::ParticleEmitterSettings *mParticleSettings; // rdx
  float v36; // xmm7_4
  float v37; // xmm8_4
  float v38; // xmm5_4
  float v39; // xmm1_4
  float mLifeMin; // xmm0_4
  float v41; // xmm10_4
  float v42; // xmm1_4
  float v43; // xmm6_4
  float mTransformScale; // xmm3_4
  float v45; // xmm10_4
  float v46; // xmm0_4
  float v47; // xmm1_4
  UFG::qVector3 result; // [rsp+30h] [rbp-A8h] BYREF
  UFG::qMatrix44 curBasis; // [rsp+40h] [rbp-98h] BYREF

  mTaskParams = this->mTaskParams;
  y_low = (__m128)LODWORD(this->mCurBasisNormalized.v3.y);
  v6 = 0;
  v10 = this->mCurBasisNormalized.v3.x - this->mTaskParams->oldBasis.v3.x;
  v12 = this->mCurBasisNormalized.v3.z - this->mTaskParams->oldBasis.v3.z;
  lastExpiry = this->mTaskParams->lastExpiry;
  t = this->mTaskParams->t;
  spacing = this->mTaskParams->spacing;
  y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - this->mTaskParams->oldBasis.v3.y)
                                    * (float)(y_low.m128_f32[0] - this->mTaskParams->oldBasis.v3.y))
                            + (float)(v10 * v10))
                    + (float)(v12 * v12);
  x = this->mCurBasisNormalized.v0.x;
  curBasis.v0.y = this->mCurBasisNormalized.v0.y;
  LODWORD(v17) = _mm_sqrt_ps(y_low).m128_u32[0];
  w = this->mCurBasisNormalized.v0.w;
  curBasis.v0.x = x;
  curBasis.v0.z = this->mCurBasisNormalized.v0.z;
  v19 = this->mCurBasisNormalized.v1.x;
  curBasis.v0.w = w;
  y = this->mCurBasisNormalized.v1.y;
  curBasis.v1.x = v19;
  z = this->mCurBasisNormalized.v1.z;
  curBasis.v1.y = y;
  v22 = this->mCurBasisNormalized.v1.w;
  curBasis.v1.z = z;
  v23 = this->mCurBasisNormalized.v2.x;
  curBasis.v1.w = v22;
  v24 = this->mCurBasisNormalized.v2.y;
  curBasis.v2.x = v23;
  v25 = this->mCurBasisNormalized.v2.z;
  curBasis.v2.y = v24;
  v26 = this->mCurBasisNormalized.v2.w;
  curBasis.v2.z = v25;
  v27 = this->mCurBasisNormalized.v3.x;
  curBasis.v2.w = v26;
  v28 = this->mCurBasisNormalized.v3.y;
  curBasis.v3.x = v27;
  v29 = this->mCurBasisNormalized.v3.z;
  curBasis.v3.y = v28;
  v30 = this->mCurBasisNormalized.v3.w;
  curBasis.v3.z = v29;
  curBasis.v3.w = v30;
  if ( (int)mTaskParams->currentAddCount > 0 )
  {
    seed = &this->mSeed;
    v32 = 1.0 / v17;
    do
    {
      creationSimTime = this->mTaskParams->creationSimTime;
      v34 = UFG::qRandom(1.0, (unsigned int *)seed);
      mParticleSettings = this->mParticleSettings;
      v36 = mTaskParams->oldBasis.v3.y;
      v37 = mTaskParams->oldBasis.v3.x;
      v38 = mTaskParams->oldBasis.v3.z;
      v39 = v34;
      curBasis.v3.w = 1.0;
      mLifeMin = mParticleSettings->mLifeMin;
      v41 = (float)(mParticleSettings->mLifeMax - mLifeMin) * v39;
      v42 = this->mCurBasisNormalized.v3.y - v36;
      v43 = (float)((float)(v32 * t) * (float)(this->mCurBasisNormalized.v3.z - v38)) + v38;
      curBasis.v3.x = (float)((float)(v32 * t) * (float)(this->mCurBasisNormalized.v3.x - v37)) + v37;
      curBasis.v3.y = (float)((float)(v32 * t) * v42) + v36;
      mTransformScale = this->mTransformScale;
      curBasis.v3.z = v43;
      v45 = (float)(v41 + mLifeMin) + creationSimTime;
      Render::CreateTimeUpdateJitterVector(&result, mParticleSettings, &curBasis, mTransformScale, seed);
      v46 = result.x;
      v47 = result.y;
      generateParticleParams->start_time = creationSimTime;
      generateParticleParams->end_time = v45;
      generateParticleParams->pos.x = v46;
      generateParticleParams->pos.z = result.z;
      generateParticleParams->pos.y = v47;
      if ( Render::ParticleCreator::AddParticle(this, generateParticleParams, attributeBuffer, *currentBufferCount) )
      {
        ++*currentBufferCount;
        t = t + spacing;
        if ( lastExpiry < v45 )
          lastExpiry = v45;
      }
      ++v6;
    }
    while ( v6 < (signed int)this->mTaskParams->currentAddCount );
  }
  return lastExpiry;
}

// File Line: 180
// RVA: 0x1DF700
Render::EmitterParticleAttribute *__fastcall Render::ParticleCreator::AddParticle(
        Render::ParticleCreator *this,
        Render::GenerateParticleParameters *generateParticleParams,
        Render::EmitterParticleAttribute *attribBuffer,
        unsigned int currentBufferCount)
{
  bool v4; // zf
  float x; // xmm7_4
  Render::ParticleCreator *v9; // rsi
  float y; // xmm8_4
  float z; // xmm9_4
  Render::ParticleEmitterSettings *pfx; // rdx
  unsigned __int64 v13; // rcx
  int v14; // eax
  int *mMainMemoryAddress; // r15
  __int16 *v16; // rax
  unsigned int cur_index; // ebx
  unsigned int v18; // edi
  float mMeshEmissionVertexSkip; // xmm6_4
  _DWORD *v20; // rcx
  _DWORD *v21; // rbx
  unsigned int v22; // eax
  float *p_x; // rax
  Render::ParticleEmitterSettings *v24; // rcx
  float v26; // xmm4_4
  float v27; // xmm6_4
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm6_4
  float v31; // xmm1_4
  float v32; // xmm0_4
  UFG::qVector3 v33; // [rsp+40h] [rbp-98h] BYREF
  UFG::qVector3 v34; // [rsp+50h] [rbp-88h] BYREF
  UFG::qVector3 triangleVertices; // [rsp+60h] [rbp-78h] BYREF
  UFG::qVector3 outPosition; // [rsp+6Ch] [rbp-6Ch] BYREF
  UFG::qVector3 outNormal; // [rsp+78h] [rbp-60h] BYREF
  Render::ParticleGenerator v38; // [rsp+88h] [rbp-50h] BYREF
  Render::ParticleCreator *v39; // [rsp+158h] [rbp+80h]
  Render::EmitterParticleAttribute *v40; // [rsp+168h] [rbp+90h]
  unsigned int vars0; // [rsp+170h] [rbp+98h]

  v4 = !this->mMeshEmitter.mIsInitialized;
  x = UFG::qVector3::msZero.x;
  v9 = this;
  v33 = UFG::qVector3::msZero;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  if ( v4 )
    goto LABEL_15;
  pfx = generateParticleParams->pfx;
  v13 = pfx->mBitFields[0];
  if ( (v13 & 2) != 0 )
  {
    v14 = UFG::qRandom(
            *((_DWORD *)v9->mMeshEmitter.mMeshStream.mMainMemoryAddress + 58),
            (unsigned int *)generateParticleParams->seed);
    mMainMemoryAddress = (int *)v9->mMeshEmitter.mMeshStream.mMainMemoryAddress;
    v16 = (__int16 *)(*((_QWORD *)mMainMemoryAddress + 10)
                    + *(_QWORD *)(*((_QWORD *)mMainMemoryAddress + 10) + 96i64)
                    + (unsigned int)(6 * v14)
                    + 2 * (mMainMemoryAddress[57] + 48i64));
    cur_index = v16[1];
    v18 = v16[2];
    Render::FXqTaskMeshReader::DecodeVertexPositionAndNormal(
      &v9->mMeshEmitter,
      v9->mMeshEmitter.mpVertexBuffers,
      v9->mMeshEmitter.mpMainMemoryVertexBuffers,
      mMainMemoryAddress[14],
      *v16,
      &triangleVertices,
      &triangleVertices);
    Render::FXqTaskMeshReader::DecodeVertexPositionAndNormal(
      &v9->mMeshEmitter,
      v9->mMeshEmitter.mpVertexBuffers,
      v9->mMeshEmitter.mpMainMemoryVertexBuffers,
      mMainMemoryAddress[14],
      cur_index,
      &outPosition,
      &outPosition);
    Render::FXqTaskMeshReader::DecodeVertexPositionAndNormal(
      &v9->mMeshEmitter,
      v9->mMeshEmitter.mpVertexBuffers,
      v9->mMeshEmitter.mpMainMemoryVertexBuffers,
      mMainMemoryAddress[14],
      v18,
      &outNormal,
      &outNormal);
    Render::FXqTaskMeshReader::GetRandomPointOnTriangle(
      &triangleVertices,
      &triangleVertices,
      generateParticleParams->seed,
      &v34,
      &v33);
    v9 = v39;
    attribBuffer = v40;
  }
  else
  {
    if ( (v13 & 0x40) != 0 )
    {
      mMeshEmissionVertexSkip = pfx->mMeshEmissionVertexSkip;
      v20 = v9->mMeshEmitter.mMeshStream.mMainMemoryAddress;
      if ( (float)(int)v9->mMeshEmitter.mNumVerticesInMesh <= v9->mMeshEmitter.mCurVertexForSequentialEmission )
        v9->mMeshEmitter.mCurVertexForSequentialEmission = 0.0;
      Render::FXqTaskMeshReader::DecodeVertexPositionAndNormal(
        &v9->mMeshEmitter,
        v9->mMeshEmitter.mpVertexBuffers,
        v9->mMeshEmitter.mpMainMemoryVertexBuffers,
        v20[14],
        (int)v9->mMeshEmitter.mCurVertexForSequentialEmission,
        &v34,
        &v33);
      v9->mMeshEmitter.mCurVertexForSequentialEmission = (float)(int)((int)(float)(mMeshEmissionVertexSkip
                                                                                 + v9->mMeshEmitter.mCurVertexForSequentialEmission)
                                                                    % v9->mMeshEmitter.mNumVerticesInMesh);
      goto LABEL_10;
    }
    v21 = v9->mMeshEmitter.mMeshStream.mMainMemoryAddress;
    v22 = UFG::qRandom(v9->mMeshEmitter.mNumVerticesInMesh, (unsigned int *)v9->mMeshEmitter.mSeed);
    Render::FXqTaskMeshReader::DecodeVertexPositionAndNormal(
      &v9->mMeshEmitter,
      v9->mMeshEmitter.mpVertexBuffers,
      v9->mMeshEmitter.mpMainMemoryVertexBuffers,
      v21[14],
      v22,
      &v34,
      &v33);
  }
  currentBufferCount = vars0;
LABEL_10:
  y = v33.y;
  x = v33.x;
  z = v33.z;
  p_x = &v9->mTaskParams->renderMatrix.v0.x;
  v24 = generateParticleParams->pfx;
  if ( (float)((float)((float)((float)((float)((float)((float)(v33.x * v9->mCurBasisNormalized.v0.y)
                                                     + (float)(v33.y * v9->mCurBasisNormalized.v1.y))
                                             + (float)(v33.z * v9->mCurBasisNormalized.v2.y))
                                     + (float)(v9->mCurBasisNormalized.v3.y * 0.0))
                             * v9->mTaskParams->cameraDir.y)
                     + (float)((float)((float)((float)((float)(v33.y * v9->mCurBasisNormalized.v1.x)
                                                     + (float)(v33.x * v9->mCurBasisNormalized.v0.x))
                                             + (float)(v33.z * v9->mCurBasisNormalized.v2.x))
                                     + (float)(v9->mCurBasisNormalized.v3.x * 0.0))
                             * v9->mTaskParams->cameraDir.x))
             + (float)((float)((float)((float)((float)(v33.x * v9->mCurBasisNormalized.v0.z)
                                             + (float)(v33.y * v9->mCurBasisNormalized.v1.z))
                                     + (float)(v33.z * v9->mCurBasisNormalized.v2.z))
                             + (float)(v9->mCurBasisNormalized.v3.z * 0.0))
                     * v9->mTaskParams->cameraDir.z)) < (float)(v24->mBackfaceCulling - 1.0) )
    return 0i64;
  if ( v24->mSpace == 1 )
  {
    v31 = v34.y + generateParticleParams->pos.y;
    generateParticleParams->pos.x = v34.x + generateParticleParams->pos.x;
    v32 = v34.z;
    generateParticleParams->pos.y = v31;
    generateParticleParams->pos.z = v32 + generateParticleParams->pos.z;
  }
  else
  {
    v26 = (float)(v34.y * p_x[21]) + (float)(v34.x * p_x[17]);
    v27 = (float)(v34.y * p_x[22]) + (float)(v34.x * p_x[18]);
    v28 = v34.z * p_x[25];
    v29 = v34.z * p_x[26];
    generateParticleParams->pos.x = (float)((float)((float)(v34.y * p_x[20]) + (float)(v34.x * p_x[16]))
                                          + (float)(v34.z * p_x[24]))
                                  + generateParticleParams->pos.x;
    v30 = (float)(v27 + v29) + generateParticleParams->pos.z;
    generateParticleParams->pos.y = (float)(v26 + v28) + generateParticleParams->pos.y;
    generateParticleParams->pos.z = v30;
  }
LABEL_15:
  generateParticleParams->meshNormal.x = x;
  generateParticleParams->meshNormal.y = y;
  generateParticleParams->meshNormal.z = z;
  v38.mParameters = generateParticleParams;
  UFG::qInverseAffine(&v38.mInvBasis, &generateParticleParams->curBasisNormalized);
  return Render::ParticleGenerator::Generate(&v38, attribBuffer, currentBufferCount);
}

// File Line: 305
// RVA: 0x1E16B0
UFG::qVector3 *__fastcall Render::ExtrapolatePositionFromOriginalData(
        UFG::qVector3 *result,
        Render::EmitterParticleAttribute *attribute,
        float velocityAlign,
        float timeElapsed,
        UFG::qMatrix44 *localWorld,
        UFG::qMatrix44 *worldLocal)
{
  float w; // xmm1_4
  float v9; // xmm9_4
  float v10; // xmm0_4
  float v11; // xmm5_4
  float v12; // xmm13_4
  float y; // xmm11_4
  float x; // xmm12_4
  float z; // xmm10_4
  float v16; // xmm14_4
  float v17; // xmm15_4
  float v18; // xmm6_4
  float v19; // xmm7_4
  float v20; // xmm8_4
  float v21; // xmm0_4
  float v22; // xmm12_4
  float v23; // xmm11_4
  float v24; // xmm10_4
  float v25; // xmm0_4
  float v26; // xmm3_4
  float v27; // xmm15_4
  UFG::qVector3 *v28; // rax
  float v29; // xmm0_4
  float v30; // xmm2_4
  UFG::qVector4 resulta; // [rsp+20h] [rbp-C8h] BYREF
  float v32; // [rsp+F0h] [rbp+8h]
  int v33; // [rsp+100h] [rbp+18h]
  float v34; // [rsp+108h] [rbp+20h]
  float worldLocala; // [rsp+118h] [rbp+30h]

  w = attribute->vPosAndGrav.w;
  v9 = (float)((float)(worldLocal->v1.x + worldLocal->v0.x) * 0.0) + (float)(w * worldLocal->v2.x);
  v34 = (float)((float)(worldLocal->v1.y + worldLocal->v0.y) * 0.0) + (float)(w * worldLocal->v2.y);
  worldLocala = (float)((float)(worldLocal->v1.z + worldLocal->v0.z) * 0.0) + (float)(w * worldLocal->v2.z);
  UFG::qHalfVector4::operator UFG::qVector4 const(&attribute->vInitialVel, &resulta);
  v33 = ((((attribute->vVelAndDamp.w.mRep >> 10) & 0x1F) + 112) << 23) & 0x7F800000 | ((attribute->vVelAndDamp.w.mRep & 0x3FF | (8 * (attribute->vVelAndDamp.w.mRep & 0x8000))) << 13);
  v10 = *(float *)&v33 * timeElapsed;
  if ( (float)(*(float *)&v33 * timeElapsed) <= 0.0 )
  {
    v10 = 0.0;
  }
  else
  {
    v11 = FLOAT_12_0;
    v32 = FLOAT_12_0;
    if ( v10 >= 12.0 )
      goto LABEL_6;
  }
  v11 = v10;
  v32 = v10;
LABEL_6:
  v12 = 1.0 / (float)(*(float *)&v33 * *(float *)&v33);
  y = resulta.y;
  x = resulta.x;
  z = resulta.z;
  v16 = UFG::qVector3::msZero.x;
  v17 = UFG::qVector3::msZero.y;
  v18 = (float)((float)(1.0 / *(float *)&v33) * resulta.y) + (float)(v12 * COERCE_FLOAT(LODWORD(v34) ^ _xmm[0]));
  v19 = (float)((float)(1.0 / *(float *)&v33) * resulta.x) + (float)(v12 * COERCE_FLOAT(LODWORD(v9) ^ _xmm[0]));
  v20 = (float)((float)(1.0 / *(float *)&v33) * resulta.z) + (float)(v12 * COERCE_FLOAT(LODWORD(worldLocala) ^ _xmm[0]));
  v21 = expf(v11);
  v22 = (float)((float)(x * *(float *)&v33)
              - (float)(v21 * (float)((float)(v9 * v32) + (float)((float)(v19 * *(float *)&v33) * *(float *)&v33))))
      - v9;
  v23 = (float)((float)(y * *(float *)&v33)
              - (float)(v21 * (float)((float)(v34 * v32) + (float)((float)(v18 * *(float *)&v33) * *(float *)&v33))))
      - v34;
  v24 = (float)((float)(z * *(float *)&v33)
              - (float)(v21
                      * (float)((float)(worldLocala * v32) + (float)((float)(v20 * *(float *)&v33) * *(float *)&v33))))
      - worldLocala;
  v25 = expf(COERCE_FLOAT(LODWORD(v32) ^ _xmm[0]));
  v26 = UFG::qVector3::msZero.z - (float)((float)(v25 * v12) * v24);
  v27 = v17 - (float)((float)(v25 * v12) * v23);
  v28 = result;
  v29 = attribute->vPosAndGrav.x + (float)(v16 - (float)((float)(v25 * v12) * v22));
  v30 = attribute->vPosAndGrav.z + v26;
  result->y = attribute->vPosAndGrav.y + v27;
  result->z = v30;
  result->x = v29;
  return v28;
}

// File Line: 351
// RVA: 0x1E0F30
void __fastcall Render::ComputeResumeTimePosAndVel(
        Render::EmitterParticleAttribute *attribute,
        float velocityAlign,
        float timeElapsed,
        UFG::qMatrix44 *localWorld,
        UFG::qMatrix44 *worldLocal)
{
  float w; // xmm3_4
  float v7; // xmm11_4
  float v8; // xmm13_4
  float v9; // xmm12_4
  float y; // xmm1_4
  float z; // xmm0_4
  float v12; // xmm1_4
  int v13; // xmm14_4
  float v14; // xmm7_4
  float v15; // xmm8_4
  float v16; // xmm9_4
  float v17; // xmm0_4
  float v18; // xmm0_4
  UFG::qVector4 result; // [rsp+30h] [rbp-A8h] BYREF
  int v20; // [rsp+F0h] [rbp+18h]

  w = attribute->vPosAndGrav.w;
  v7 = (float)((float)(worldLocal->v1.x + worldLocal->v0.x) * 0.0) + (float)(w * worldLocal->v2.x);
  v8 = (float)((float)(worldLocal->v1.z + worldLocal->v0.z) * 0.0) + (float)(w * worldLocal->v2.z);
  v9 = (float)((float)(worldLocal->v1.y + worldLocal->v0.y) * 0.0) + (float)(w * worldLocal->v2.y);
  Render::ExtrapolatePositionFromOriginalData(
    (UFG::qVector3 *)&result,
    attribute,
    velocityAlign,
    timeElapsed,
    localWorld,
    worldLocal);
  y = result.y;
  attribute->vPosAndGrav.x = result.x;
  z = result.z;
  attribute->vPosAndGrav.y = y;
  attribute->vPosAndGrav.z = z;
  UFG::qHalfVector4::operator UFG::qVector4 const(&attribute->vVelAndDamp, &result);
  v20 = ((((attribute->vVelAndDamp.w.mRep >> 10) & 0x1F) + 112) << 23) & 0x7F800000 | ((attribute->vVelAndDamp.w.mRep & 0x3FF | (8 * (attribute->vVelAndDamp.w.mRep & 0x8000))) << 13);
  v12 = *(float *)&v20 * timeElapsed;
  v13 = v20 ^ _xmm[0];
  v14 = (float)(COERCE_FLOAT(v20 ^ _xmm[0]) * result.x) + v7;
  v15 = (float)(COERCE_FLOAT(v20 ^ _xmm[0]) * result.y) + v9;
  v16 = (float)(COERCE_FLOAT(v20 ^ _xmm[0]) * result.z) + v8;
  if ( (float)(*(float *)&v20 * timeElapsed) <= 0.0 )
  {
    v12 = 0.0;
  }
  else
  {
    v17 = FLOAT_12_0;
    if ( v12 >= 12.0 )
      goto LABEL_6;
  }
  v17 = v12;
LABEL_6:
  v18 = expf(v17);
  result.x = (float)(1.0 / *(float *)&v13) * (float)((float)(v14 / v18) - v7);
  result.y = (float)(1.0 / *(float *)&v13) * (float)((float)(v15 / v18) - v9);
  result.z = (float)(1.0 / *(float *)&v13) * (float)((float)(v16 / v18) - v8);
  Render::EmitterParticleAttribute::SetVelocity(attribute, (UFG::qVector3 *)&result);
}

// File Line: 369
// RVA: 0x1E1160
UFG::qVector3 *__fastcall Render::CreateTimeUpdateJitterVector(
        UFG::qVector3 *result,
        Render::ParticleEmitterSettings *pfx,
        UFG::qMatrix44 *curBasis,
        float scale,
        int *seed)
{
  float v8; // xmm8_4
  float v9; // xmm9_4
  float v10; // xmm0_4
  float v11; // xmm9_4
  float v12; // xmm8_4
  float v13; // xmm7_4
  float v14; // xmm11_4
  float v15; // xmm10_4
  float v16; // xmm9_4
  float v17; // xmm7_4
  float v18; // xmm6_4
  float v19; // xmm3_4
  float v20; // xmm5_4
  float v21; // xmm2_4
  float v22; // xmm8_4
  float v23; // xmm7_4
  float v24; // xmm9_4
  UFG::qVector3 *v25; // rax
  float v26; // xmm3_4
  float v27; // xmm2_4
  float v28; // xmm7_4
  float v29; // xmm2_4
  float v30; // xmm3_4
  float v31; // xmm5_4
  float v32; // xmm8_4

  if ( (pfx->mBitFields[0] & 1) != 0 )
  {
    v8 = UFG::qRandom(1.0, (unsigned int *)seed);
    v9 = UFG::qRandom(1.0, (unsigned int *)seed);
    v10 = UFG::qRandom(1.0, (unsigned int *)seed);
    v11 = (float)(v9 - 0.5) * pfx->mJitter.y;
    v12 = (float)(v8 - 0.5) * pfx->mJitter.z;
    v13 = (float)(v10 - 0.5) * pfx->mJitter.x;
  }
  else
  {
    do
    {
      v14 = (float)(UFG::qRandom(1.0, (unsigned int *)seed) * 2.0) - 1.0;
      v15 = (float)(UFG::qRandom(1.0, (unsigned int *)seed) * 2.0) - 1.0;
      v16 = (float)(UFG::qRandom(1.0, (unsigned int *)seed) * 2.0) - 1.0;
    }
    while ( (float)((float)((float)(v15 * v15) + (float)(v16 * v16)) + (float)(v14 * v14)) >= 1.0 );
    v17 = UFG::qRandom(1.0, (unsigned int *)seed);
    v18 = UFG::qRandom(1.0, (unsigned int *)seed);
    v19 = (float)((float)(pfx->mJitter.x * UFG::qRandom(1.0, (unsigned int *)seed)) * 2.0) - pfx->mJitter.x;
    v20 = (float)((float)(pfx->mJitter.z * v17) * 2.0) - pfx->mJitter.z;
    v21 = (float)((float)(v15 * v15) + (float)(v16 * v16)) + (float)(v14 * v14);
    if ( v21 == 0.0 )
      v22 = 0.0;
    else
      v22 = 1.0 / fsqrt(v21);
    v23 = v22 * v16;
    v24 = v22;
    v13 = v23 * v19;
    v12 = (float)(v22 * v14) * v20;
    v11 = (float)(v24 * v15) * (float)((float)((float)(pfx->mJitter.y * v18) * 2.0) - pfx->mJitter.y);
  }
  v25 = result;
  if ( pfx->mSpace == 1 )
  {
    result->x = v13;
    result->y = v11;
    result->z = v12;
  }
  else
  {
    v26 = v13;
    v27 = v13;
    v28 = (float)((float)(v13 * curBasis->v0.z) + curBasis->v3.z) + (float)(v11 * curBasis->v1.z);
    v29 = (float)((float)(v27 * curBasis->v0.y) + curBasis->v3.y) + (float)(v11 * curBasis->v1.y);
    v30 = (float)((float)((float)(v26 * curBasis->v0.x) + curBasis->v3.x) + (float)(v11 * curBasis->v1.x))
        + (float)(v12 * curBasis->v2.x);
    v31 = v12 * curBasis->v2.y;
    v32 = v12 * curBasis->v2.z;
    result->x = v30;
    result->y = v29 + v31;
    result->z = v28 + v32;
  }
  return v25;
}

// File Line: 437
// RVA: 0x1E1A20
void __fastcall Render::GenerateNewParticles(
        UFG::qMemoryStream<Render::ParticleRenderUpdateTaskParam,624> *taskParams,
        Render::ParticleEmitterSettings *pfx,
        Render::ParticleLighting *particleLighting,
        UFG::qMatrix44 *curBasisNormalized)
{
  float *mMainMemoryAddress; // r10
  int v9; // edx
  __int64 v10; // rcx
  __int64 v11; // r8
  __int64 v12; // r9
  unsigned int v13; // ecx
  int v14; // esi
  UFG::qVector4 v15; // xmm2
  UFG::qVector4 v16; // xmm1
  UFG::qVector4 v17; // xmm0
  UFG::qVector4 *v18; // rcx
  UFG::qVector4 v19; // xmm2
  UFG::qVector4 v20; // xmm1
  UFG::qVector4 v21; // xmm0
  __int64 v22; // rax
  float v23; // xmm0_4
  __int64 v24; // [rsp+58h] [rbp-80h]
  char ptr[8]; // [rsp+68h] [rbp-70h] BYREF
  __int64 v26; // [rsp+70h] [rbp-68h]
  __int64 v27; // [rsp+78h] [rbp-60h]
  __int64 v28; // [rsp+80h] [rbp-58h]
  __int64 v29; // [rsp+88h] [rbp-50h]
  UFG::qMemoryStreamer *v30; // [rsp+90h] [rbp-48h]
  __int64 v31; // [rsp+98h] [rbp-40h]
  char v32; // [rsp+A0h] [rbp-38h]
  int v33; // [rsp+A4h] [rbp-34h]
  int *v34; // [rsp+A8h] [rbp-30h]
  __int64 v35; // [rsp+B8h] [rbp-20h]
  Render::GenerateParticleParameters generateParticleParams; // [rsp+C8h] [rbp-10h] BYREF
  Render::ParticleCreator v37; // [rsp+1A8h] [rbp+D0h] BYREF
  int v38[6]; // [rsp+348h] [rbp+270h] BYREF
  void *retaddr; // [rsp+368h] [rbp+290h]
  UFG::qMemoryStreamer *v40; // [rsp+370h] [rbp+298h]
  unsigned int *v41; // [rsp+378h] [rbp+2A0h]
  Render::EmitterParticleAttribute *v42; // [rsp+380h] [rbp+2A8h]
  float *v43; // [rsp+388h] [rbp+2B0h]

  v35 = -2i64;
  v38[0] = *((_DWORD *)taskParams->mMainMemoryAddress + 142);
  `eh vector constructor iterator(
    ptr,
    0x18ui64,
    2,
    (void (__fastcall *)(void *))UFG::qMemoryStream<UFG::AIInterestComponent,432>::qMemoryStream<UFG::AIInterestComponent,432>);
  v30 = 0i64;
  v31 = 0i64;
  v32 = 0;
  v33 = -1;
  mMainMemoryAddress = (float *)taskParams->mMainMemoryAddress;
  v9 = (int)mMainMemoryAddress[146];
  v10 = *((_QWORD *)mMainMemoryAddress + 72);
  if ( v10 )
  {
    v34 = v38;
    v30 = v40;
    v24 = *(_QWORD *)(v10 + 184) + v10 + 184 + *(unsigned int *)(*(_QWORD *)(v10 + 184) + v10 + 184);
    v33 = 0;
    v11 = *(_QWORD *)(v24 + 112);
    v26 = v11;
    v12 = *(_QWORD *)(v24 + 144);
    v13 = *(_DWORD *)(v11 + 108);
    HIDWORD(v31) = v13;
    if ( v13 )
    {
      *(float *)&v31 = (float)(int)((int)(float)v9 % v13);
      v26 = v11;
      v28 = *(_QWORD *)(v11 + 96) + v11 + 96;
      v27 = v12;
      v29 = *(_QWORD *)(v12 + 96) + v12 + 96;
    }
    v32 = 1;
  }
  v14 = *((_DWORD *)mMainMemoryAddress + 139);
  v37.mTaskParams = 0i64;
  v37.mSeedBuffer = 0i64;
  v37.mFxOverride = 0i64;
  Render::FXqTaskMeshReader::FXqTaskMeshReader(&v37.mMeshEmitter);
  v37.mSeedStream.mName = "<unassigned>";
  v37.mSeedStream.mMainMemoryAddress = 0i64;
  v37.mSeedStream.mState = 0;
  v37.mFxOverrideStream.mName = "<unassigned>";
  v37.mFxOverrideStream.mMainMemoryAddress = 0i64;
  v37.mFxOverrideStream.mState = 0;
  v37.mParticleEmitterSettingsStream.mName = "<unassigned>";
  v37.mParticleEmitterSettingsStream.mMainMemoryAddress = 0i64;
  v37.mParticleEmitterSettingsStream.mState = 0;
  v37.mParticleSettings = 0i64;
  v37.mTransformScale = 0.0;
  v37.mMemoryStreamer = v40;
  Render::ParticleCreator::SetTaskParams(&v37, (Render::ParticleRenderUpdateTaskParam *)taskParams->mMainMemoryAddress);
  v15 = curBasisNormalized->v1;
  v16 = curBasisNormalized->v2;
  v17 = curBasisNormalized->v3;
  generateParticleParams.curBasisNormalized.v0 = curBasisNormalized->v0;
  generateParticleParams.curBasisNormalized.v1 = v15;
  generateParticleParams.curBasisNormalized.v2 = v16;
  generateParticleParams.curBasisNormalized.v3 = v17;
  v18 = (UFG::qVector4 *)taskParams->mMainMemoryAddress;
  v16.x = v18[13].w;
  v15.x = v18[14].x;
  generateParticleParams.emitterVelocity.x = v18[13].z;
  generateParticleParams.emitterVelocity.y = v16.x;
  generateParticleParams.emitterVelocity.z = v15.x;
  generateParticleParams.pfx = pfx;
  v16.x = v18[12].y;
  v15.x = v18[12].z;
  generateParticleParams.cameraPos.x = v18[12].x;
  generateParticleParams.cameraPos.y = v16.x;
  generateParticleParams.cameraPos.z = v15.x;
  generateParticleParams.seed = v38;
  generateParticleParams.sizeScale = 1.0;
  v19 = v18[1];
  v20 = v18[2];
  v21 = v18[3];
  generateParticleParams.renderMatrix.v0 = *v18;
  generateParticleParams.renderMatrix.v1 = v19;
  generateParticleParams.renderMatrix.v2 = v20;
  generateParticleParams.renderMatrix.v3 = v21;
  generateParticleParams.simTime = v18[33].x;
  generateParticleParams.particleLighting = particleLighting;
  generateParticleParams.velocityScale = 1.0;
  LODWORD(generateParticleParams.transformScale) = (_DWORD)retaddr;
  v22 = *(_QWORD *)&v18[37].x;
  if ( v22 )
  {
    generateParticleParams.velocityScale = *(float *)(v22 + 76);
    generateParticleParams.sizeScale = *(float *)(v22 + 84);
  }
  if ( v14 == 1 )
  {
    v23 = Render::ParticleCreator::AddDistanceEmissionParticles(&v37, &generateParticleParams, v42, v41);
  }
  else if ( v18[33].z == 0.0 )
  {
    v23 = Render::ParticleCreator::AddTimeEmissionParticles(&v37, &generateParticleParams, v42, v41);
  }
  else
  {
    v23 = Render::ParticleCreator::AddResumeParticles(&v37, &generateParticleParams, v42, v41);
  }
  *v43 = v23;
  `eh vector destructor iterator(v37.mMeshEmitter.mVertexBuffers, 0x18ui64, 2, (void (__fastcall *)(void *))_);
  `eh vector destructor iterator(ptr, 0x18ui64, 2, (void (__fastcall *)(void *))_);
}

// File Line: 508
// RVA: 0x1DD430
Render::TargetParticleMoverWithBlend *__fastcall Render::for_each<Render::EmitterParticleAttribute *,Render::TargetParticleMoverWithBlend>(
        Render::TargetParticleMoverWithBlend *result,
        Render::EmitterParticleAttribute *first,
        Render::EmitterParticleAttribute *last,
        Render::TargetParticleMoverWithBlend *f)
{
  Render::EmitterParticleAttribute *i; // rbx
  float x; // eax
  float z; // xmm1_4
  float w; // xmm2_4
  float v11; // eax
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // eax
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // eax
  float v18; // xmm1_4
  float v19; // xmm2_4

  for ( i = first; i != last; ++i )
    Render::TargetParticleMoverWithBlend::operator()(f, i);
  x = f->mWorldLocal.v0.x;
  z = f->mWorldLocal.v0.z;
  w = f->mWorldLocal.v0.w;
  result->mWorldLocal.v0.y = f->mWorldLocal.v0.y;
  result->mWorldLocal.v0.z = z;
  result->mWorldLocal.v0.x = x;
  result->mWorldLocal.v0.w = w;
  v11 = f->mWorldLocal.v1.x;
  v12 = f->mWorldLocal.v1.z;
  v13 = f->mWorldLocal.v1.w;
  result->mWorldLocal.v1.y = f->mWorldLocal.v1.y;
  result->mWorldLocal.v1.x = v11;
  result->mWorldLocal.v1.z = v12;
  result->mWorldLocal.v1.w = v13;
  v14 = f->mWorldLocal.v2.x;
  v15 = f->mWorldLocal.v2.z;
  v16 = f->mWorldLocal.v2.w;
  result->mWorldLocal.v2.y = f->mWorldLocal.v2.y;
  result->mWorldLocal.v2.x = v14;
  result->mWorldLocal.v2.z = v15;
  result->mWorldLocal.v2.w = v16;
  v17 = f->mWorldLocal.v3.x;
  v18 = f->mWorldLocal.v3.z;
  v19 = f->mWorldLocal.v3.w;
  result->mWorldLocal.v3.y = f->mWorldLocal.v3.y;
  result->mWorldLocal.v3.x = v17;
  result->mWorldLocal.v3.z = v18;
  result->mWorldLocal.v3.w = v19;
  result->mSettings = f->mSettings;
  result->mParticleLighting = f->mParticleLighting;
  result->mTaskParams = f->mTaskParams;
  result->mTransformScaleFactor = f->mTransformScaleFactor;
  return result;
}

// File Line: 527
// RVA: 0x1E28C0
void __fastcall Render::UpdateExistingParticles(
        UFG::qMemoryStream<Render::ParticleRenderUpdateTaskParam,624> *taskParams,
        Render::ParticleEmitterSettings *pfx,
        UFG::qMatrix44 *curBasisNormalized,
        unsigned int currentBufferCount,
        Render::ParticleLighting *particleLighting,
        float transformScale,
        Render::EmitterParticleAttribute *attributeBuffer)
{
  __int64 v9; // r15
  void *mMainMemoryAddress; // r14
  Render::EmitterParticleAttribute *v12; // rdi
  float *p_fStartTime; // rbx
  unsigned int mPhysicsType; // eax
  Render::EmitterParticleAttribute *v15; // rbx
  Render::BounceParticleMoverWithLocalToWorldBlend *v16; // rax
  Render::BounceParticleMoverWithLocalToWorldBlend *v17; // rdi
  Render::EmitterParticleAttribute *v18; // rsi
  Render::EmitterParticleAttribute *v19; // rbx
  Render::FXForceParticleMover *v20; // rax
  Render::FXForceParticleMover *v21; // rdi
  Render::EmitterParticleAttribute *v22; // rsi
  Render::ParticleRenderUpdateTaskParam *v23; // rdx
  Render::BasicParticleMover *v24; // rax
  Render::EmitterParticleAttribute *v25; // rbx
  Render::BounceParticleMoverWithLocalToWorldBlend *v26; // rax
  Render::EmitterParticleAttribute *v27; // rsi
  Render::ParticleRenderUpdateTaskParam *v28; // rdx
  Render::EmitterParticleAttribute *v29; // rbx
  Render::TargetParticleMover *v30; // rax
  Render::TargetParticleMoverWithBlend *v31; // rax
  UFG::qMatrix44 d; // [rsp+40h] [rbp-C0h] BYREF
  UFG::qColour colour; // [rsp+80h] [rbp-80h] BYREF
  Render::BounceParticleMoverWithLocalToWorldBlend v34; // [rsp+90h] [rbp-70h] BYREF
  UFG::qMatrix44 invOldBasis; // [rsp+170h] [rbp+70h] BYREF
  Render::BounceParticleMoverWithLocalToWorldBlend v36; // [rsp+1B0h] [rbp+B0h] BYREF

  v9 = currentBufferCount;
  UFG::qInverseAffine(&d, (UFG::qMatrix44 *)taskParams->mMainMemoryAddress);
  UFG::qInverse(&invOldBasis, (UFG::qMatrix44 *)taskParams->mMainMemoryAddress + 2);
  mMainMemoryAddress = taskParams->mMainMemoryAddress;
  if ( pfx->mType == 1 )
  {
    v12 = &attributeBuffer[(unsigned int)v9];
    if ( attributeBuffer != v12 )
    {
      colour.r = 1.0;
      colour.g = 1.0;
      colour.b = 1.0;
      p_fStartTime = &attributeBuffer->fStartTime;
      do
      {
        colour.a = Render::ComputeInterpolatedAlpha(
                     pfx->mSettings.ColorAlphaKeys,
                     pfx->mSettings.AlphaKeyPositions,
                     (float)(*((float *)mMainMemoryAddress + 132) - *p_fStartTime)
                   / (float)(p_fStartTime[1] - *p_fStartTime));
        Render::EmitterParticleAttribute::SetColour((Render::EmitterParticleAttribute *)(p_fStartTime - 15), &colour);
        p_fStartTime += 21;
      }
      while ( p_fStartTime - 15 != (float *)v12 );
    }
    return;
  }
  mPhysicsType = pfx->mPhysicsType;
  if ( mPhysicsType == 1203368722 )
  {
    if ( pfx->mLocalSpaceToWorldSpaceBlend == 0.0 )
    {
      v34.mCurBasisNormalized = d;
      *(_QWORD *)&v34.mInverseOldBasis.v0.x = pfx;
      *(_QWORD *)&v34.mInverseOldBasis.v0.z = particleLighting;
      *(_QWORD *)&v34.mInverseOldBasis.v1.x = mMainMemoryAddress;
      v34.mInverseOldBasis.v1.z = transformScale;
      Render::for_each<Render::EmitterParticleAttribute *,Render::BounceParticleMover>(
        (Render::BounceParticleMover *)&v36,
        attributeBuffer,
        &attributeBuffer[v9],
        (Render::BounceParticleMover *)&v34);
      return;
    }
    Render::BounceParticleMoverWithLocalToWorldBlend::BounceParticleMoverWithLocalToWorldBlend(
      &v36,
      (Render::ParticleRenderUpdateTaskParam *)mMainMemoryAddress,
      pfx,
      particleLighting,
      transformScale,
      curBasisNormalized,
      &d,
      &invOldBasis);
    v15 = attributeBuffer;
    v17 = v16;
    v18 = &attributeBuffer[v9];
    if ( attributeBuffer != v18 )
    {
      do
        Render::BounceParticleMoverWithLocalToWorldBlend::operator()(v17, v15++);
      while ( v15 != v18 );
    }
    goto LABEL_11;
  }
  if ( mPhysicsType != 1885859516 )
  {
    if ( mPhysicsType == 485300164 || mPhysicsType == -82145175 )
    {
      v28 = (Render::ParticleRenderUpdateTaskParam *)taskParams->mMainMemoryAddress;
      v29 = &attributeBuffer[v9];
      if ( pfx->mLocalSpaceToWorldSpaceBlend == 0.0 )
      {
        Render::TargetParticleMover::TargetParticleMover(
          (Render::TargetParticleMoverWithBlend *)&v36,
          v28,
          pfx,
          particleLighting,
          transformScale,
          &d);
        Render::for_each<Render::EmitterParticleAttribute *,Render::TargetParticleMover>(
          (Render::TargetParticleMover *)&v34,
          attributeBuffer,
          v29,
          v30);
      }
      else
      {
        Render::TargetParticleMover::TargetParticleMover(
          (Render::TargetParticleMoverWithBlend *)&v36,
          v28,
          pfx,
          particleLighting,
          transformScale,
          &d);
        Render::for_each<Render::EmitterParticleAttribute *,Render::TargetParticleMoverWithBlend>(
          (Render::TargetParticleMoverWithBlend *)&v34,
          attributeBuffer,
          v29,
          v31);
      }
      return;
    }
    v23 = (Render::ParticleRenderUpdateTaskParam *)taskParams->mMainMemoryAddress;
    if ( pfx->mLocalSpaceToWorldSpaceBlend == 0.0 )
    {
      Render::TargetParticleMover::TargetParticleMover(
        (Render::TargetParticleMoverWithBlend *)&v36,
        v23,
        pfx,
        particleLighting,
        transformScale,
        &d);
      Render::for_each<Render::EmitterParticleAttribute *,Render::BasicParticleMover>(
        (Render::BasicParticleMover *)&v34,
        attributeBuffer,
        &attributeBuffer[v9],
        v24);
      return;
    }
    Render::BasicParticleMoverWithLocalToWorldBlend::BasicParticleMoverWithLocalToWorldBlend(
      (Render::BasicParticleMoverWithLocalToWorldBlend *)&v36,
      v23,
      pfx,
      particleLighting,
      transformScale,
      curBasisNormalized,
      &d,
      &invOldBasis);
    v25 = attributeBuffer;
    v17 = v26;
    v27 = &attributeBuffer[v9];
    if ( attributeBuffer != v27 )
    {
      do
        Render::BasicParticleMoverWithLocalToWorldBlend::operator()(
          (Render::BasicParticleMoverWithLocalToWorldBlend *)v17,
          v25++);
      while ( v25 != v27 );
    }
LABEL_11:
    Render::BasicParticleMoverWithLocalToWorldBlend::BasicParticleMoverWithLocalToWorldBlend(&v34, v17);
    return;
  }
  Render::FXForceParticleMover::FXForceParticleMover(
    (Render::FXForceParticleMover *)&v36,
    (Render::ParticleRenderUpdateTaskParam *)mMainMemoryAddress,
    pfx,
    particleLighting,
    transformScale,
    &d,
    &invOldBasis,
    *((Render::FXForce **)mMainMemoryAddress + 34));
  v19 = attributeBuffer;
  v21 = v20;
  v22 = &attributeBuffer[v9];
  if ( attributeBuffer != v22 )
  {
    do
      Render::FXForceParticleMover::operator()(v21, v19++);
    while ( v19 != v22 );
  }
  Render::FXForceParticleMover::FXForceParticleMover((Render::FXForceParticleMover *)&v34, v21);
}

// File Line: 589
// RVA: 0x1DCC80
void __fastcall Render::ParticleRenderUpdateTask(
        int worker_id,
        UFG::qMemoryStreamer *memory_streamer,
        Render::FXManagerLights *param0,
        _DWORD *param1)
{
  Render::ParticleEmitterSettings *culledLightInstances; // r14
  __m128 numLights; // xmm12
  __m128 v9; // xmm1
  float v10; // xmm8_4
  float v11; // xmm4_4
  __m128 lightList_high; // xmm5
  float v13; // xmm15_4
  float v14; // xmm0_4
  __m128 v15; // xmm2
  float v16; // xmm2_4
  float v17; // xmm1_4
  float v18; // xmm0_4
  __m128 v19; // xmm2
  float v20; // xmm2_4
  float v21; // xmm1_4
  __m128 culledLightInstances_high; // xmm2
  float v23; // xmm3_4
  float v24; // xmm1_4
  float v25; // xmm0_4
  unsigned int v26; // r9d
  Render::LightInstance *v27; // rax
  unsigned int v28; // r15d
  unsigned __int64 main_num_bytes; // rsi
  Render::Light **lightList; // rax
  float v31; // [rsp+50h] [rbp-B0h]
  UFG::qMatrix44 curBasisNormalized; // [rsp+60h] [rbp-A0h] BYREF
  UFG::qMemoryStream<Render::ParticleRenderUpdateTaskParam,624> taskParams; // [rsp+A0h] [rbp-60h] BYREF
  UFG::qVector3 effectPosition; // [rsp+B8h] [rbp-48h] BYREF
  __int64 v35; // [rsp+D0h] [rbp-30h]
  Render::ParticleLighting ptr; // [rsp+E0h] [rbp-20h] BYREF
  char *stream_name; // [rsp+730h] [rbp+630h]
  Render::LightInstance *main_mem; // [rsp+738h] [rbp+638h]
  int v39; // [rsp+740h] [rbp+640h]
  Render::EmitterParticleAttribute *v40; // [rsp+748h] [rbp+648h]
  char v41[2701]; // [rsp+833h] [rbp+733h] BYREF
  float v42; // [rsp+1358h] [rbp+1258h]

  v35 = -2i64;
  taskParams.mName = "<unassigned>";
  taskParams.mState = 0;
  taskParams.mMainMemoryAddress = param0;
  culledLightInstances = (Render::ParticleEmitterSettings *)param0[11].culledLightInstances;
  numLights = (__m128)param0[2].numLights;
  v9 = numLights;
  v9.m128_f32[0] = (float)((float)(numLights.m128_f32[0] * numLights.m128_f32[0])
                         + (float)(*((float *)&param0[2].numLights + 1) * *((float *)&param0[2].numLights + 1)))
                 + (float)(*(float *)&param0[3].culledLightInstances * *(float *)&param0[3].culledLightInstances);
  v10 = (float)((float)(_mm_sqrt_ps(v9).m128_f32[0] - 1.0) * culledLightInstances->mUseTransformScaling) + 1.0;
  v11 = *(float *)&param0[3].lightList;
  lightList_high = (__m128)HIDWORD(param0[3].lightList);
  v13 = *(float *)&param0[4].numLights;
  v42 = *((float *)&param0[4].numLights + 1);
  v31 = *(float *)&param0[5].culledLightInstances;
  v14 = *((float *)&param0[5].culledLightInstances + 1);
  curBasisNormalized.v3.x = v13;
  curBasisNormalized.v3.y = v42;
  curBasisNormalized.v3.z = v31;
  curBasisNormalized.v3.w = v14;
  v15 = (__m128)*(&param0[2].numLights + 1);
  v15.m128_f32[0] = (float)((float)(v15.m128_f32[0] * v15.m128_f32[0])
                          + (float)(numLights.m128_f32[0] * numLights.m128_f32[0]))
                  + (float)(*(float *)&param0[3].culledLightInstances * *(float *)&param0[3].culledLightInstances);
  if ( v15.m128_f32[0] == 0.0 )
    v16 = 0.0;
  else
    v16 = 1.0 / _mm_sqrt_ps(v15).m128_f32[0];
  v17 = v16 * *(float *)&param0[3].culledLightInstances;
  v18 = v16 * *((float *)&param0[2].numLights + 1);
  curBasisNormalized.v0.x = v16 * numLights.m128_f32[0];
  curBasisNormalized.v0.y = v18;
  curBasisNormalized.v0.z = v17;
  curBasisNormalized.v0.w = 0.0;
  v19 = lightList_high;
  v19.m128_f32[0] = (float)((float)(lightList_high.m128_f32[0] * lightList_high.m128_f32[0]) + (float)(v11 * v11))
                  + (float)(*(float *)&param0[3].numLights * *(float *)&param0[3].numLights);
  if ( v19.m128_f32[0] == 0.0 )
    v20 = 0.0;
  else
    v20 = 1.0 / _mm_sqrt_ps(v19).m128_f32[0];
  v21 = v20 * *(float *)&param0[3].numLights;
  curBasisNormalized.v1.x = v20 * v11;
  curBasisNormalized.v1.y = v20 * lightList_high.m128_f32[0];
  curBasisNormalized.v1.z = v21;
  curBasisNormalized.v1.w = 0.0;
  culledLightInstances_high = (__m128)HIDWORD(param0[4].culledLightInstances);
  culledLightInstances_high.m128_f32[0] = (float)((float)(culledLightInstances_high.m128_f32[0]
                                                        * culledLightInstances_high.m128_f32[0])
                                                + (float)(*(float *)&param0[4].culledLightInstances
                                                        * *(float *)&param0[4].culledLightInstances))
                                        + (float)(*(float *)&param0[4].lightList * *(float *)&param0[4].lightList);
  if ( culledLightInstances_high.m128_f32[0] == 0.0 )
    v23 = 0.0;
  else
    v23 = 1.0 / _mm_sqrt_ps(culledLightInstances_high).m128_f32[0];
  v24 = v23 * *(float *)&param0[4].lightList;
  v25 = v23 * *((float *)&param0[4].culledLightInstances + 1);
  curBasisNormalized.v2.x = v23 * *(float *)&param0[4].culledLightInstances;
  curBasisNormalized.v2.y = v25;
  curBasisNormalized.v2.z = v24;
  curBasisNormalized.v2.w = 0.0;
  v26 = 84 * *(&param0[22].numLights + 1);
  v27 = param0[10].culledLightInstances;
  stream_name = "Input EmitterParticleAttribute";
  main_mem = v27;
  v39 = 0;
  v40 = (Render::EmitterParticleAttribute *)((unsigned __int64)v41 & 0xFFFFFFFFFFFFFF80ui64);
  main_mem = param0[10].culledLightInstances;
  UFG::qMemoryStreamer::BeginRawReadPlat(
    memory_streamer,
    "Input EmitterParticleAttribute",
    (void *)((unsigned __int64)v41 & 0xFFFFFFFFFFFFFF80ui64),
    0xA80ui64,
    main_mem,
    v26);
  *param1 = *(&param0[23].numLights + 1);
  v28 = param0[22].numLights;
  `eh vector constructor iterator(
    &ptr,
    0x18ui64,
    50,
    (void (__fastcall *)(void *))UFG::qMemoryStream<UFG::AIInterestComponent,432>::qMemoryStream<UFG::AIInterestComponent,432>);
  ptr.mNumLights = 0;
  if ( culledLightInstances->mSettings.LightInfo[1] > 0.0 )
  {
    effectPosition.x = v13;
    effectPosition.y = v42;
    effectPosition.z = v31;
    Render::ParticleLighting::ReadLightsFromMainMemory(&ptr, &effectPosition, param0 + 25, memory_streamer);
  }
  Render::UpdateExistingParticles(
    &taskParams,
    culledLightInstances,
    &curBasisNormalized,
    v28,
    &ptr,
    v10,
    (Render::EmitterParticleAttribute *)((unsigned __int64)v41 & 0xFFFFFFFFFFFFFF80ui64),
    memory_streamer);
  Render::GenerateNewParticles(&taskParams, culledLightInstances, &ptr, &curBasisNormalized);
  param1[1] = v28;
  main_num_bytes = 84 * v28;
  UFG::qMemoryStreamer::BeginRawWritePlat(
    memory_streamer,
    stream_name,
    v40,
    0xA80ui64,
    param0[10].culledLightInstances,
    main_num_bytes);
  lightList = param0[10].lightList;
  if ( lightList )
    UFG::qMemoryStreamer::BeginRawWritePlat(memory_streamer, stream_name, v40, 0xA80ui64, lightList, main_num_bytes);
  `eh vector destructor iterator(&ptr, 0x18ui64, 50, (void (__fastcall *)(void *))_);
}

