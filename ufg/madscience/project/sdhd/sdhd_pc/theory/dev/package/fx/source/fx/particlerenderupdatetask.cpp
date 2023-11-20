// File Line: 34
// RVA: 0x146BBA0
__int64 Render::_dynamic_initializer_for__gTaskFunctionDecl_ParticleRenderUpdateTask__()
{
  UFG::qTaskFunctionDecl::qTaskFunctionDecl(
    &Render::gTaskFunctionDecl_ParticleRenderUpdateTask,
    &Render::gTaskFunctionDeclData_ParticleRenderUpdateTask);
  return atexit(Render::_dynamic_atexit_destructor_for__gTaskFunctionDecl_ParticleRenderUpdateTask__);
}

// File Line: 48
// RVA: 0x1E24D0
void __fastcall Render::ParticleCreator::SetTaskParams(Render::ParticleCreator *this, Render::ParticleRenderUpdateTaskParam *taskParams)
{
  UFG::qVector4 v2; // xmm3
  Render::ParticleRenderUpdateTaskParam *v3; // r8
  UFG::qVector4 v4; // xmm2
  UFG::qVector4 v5; // xmm1
  float v6; // xmm2_4
  float v7; // xmm6_4
  __m128 v8; // xmm5
  float v9; // xmm7_4
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
  void *v21; // rdx
  Render::ParticleEmitterSettings *v22; // rdx
  __m128 v23; // xmm2
  UFG::qMemoryStreamer *v24; // r9
  Render::FXqTaskMeshReader *v25; // rbx
  void *v26; // rax
  signed int v27; // er10

  this->mTaskParams = taskParams;
  v2 = taskParams->curBasis.v1;
  v3 = taskParams;
  v4 = taskParams->curBasis.v2;
  v5 = taskParams->curBasis.v3;
  this->mCurBasisNormalized.v0 = taskParams->curBasis.v0;
  this->mCurBasisNormalized.v1 = v2;
  this->mCurBasisNormalized.v2 = v4;
  v6 = 0.0;
  this->mCurBasisNormalized.v3 = v5;
  v7 = this->mCurBasisNormalized.v0.y;
  v8 = (__m128)LODWORD(this->mCurBasisNormalized.v0.x);
  v10 = v8;
  v9 = this->mCurBasisNormalized.v0.z;
  v10.m128_f32[0] = (float)((float)(v8.m128_f32[0] * v8.m128_f32[0]) + (float)(v7 * v7)) + (float)(v9 * v9);
  if ( v10.m128_f32[0] == 0.0 )
    v11 = 0.0;
  else
    v11 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v10));
  this->mCurBasisNormalized.v0.x = v8.m128_f32[0] * v11;
  this->mCurBasisNormalized.v0.y = v7 * v11;
  this->mCurBasisNormalized.v0.z = v9 * v11;
  this->mCurBasisNormalized.v0.w = 0.0;
  v12 = this->mCurBasisNormalized.v1.y;
  v13 = (__m128)LODWORD(this->mCurBasisNormalized.v1.x);
  v14 = this->mCurBasisNormalized.v1.z;
  v15 = v13;
  v15.m128_f32[0] = (float)((float)(v13.m128_f32[0] * v13.m128_f32[0]) + (float)(v12 * v12)) + (float)(v14 * v14);
  if ( v15.m128_f32[0] == 0.0 )
    v16 = 0.0;
  else
    v16 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v15));
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
    v6 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v20));
  this->mCurBasisNormalized.v2.x = v18.m128_f32[0] * v6;
  this->mCurBasisNormalized.v2.y = v17 * v6;
  this->mCurBasisNormalized.v2.z = v19 * v6;
  this->mCurBasisNormalized.v2.w = 0.0;
  this->mSeedBuffer = (int *)this->mSeedStream.mMainMemoryAddress;
  v21 = taskParams->fxOverride;
  if ( v21 )
    this->mFxOverrideStream.mMainMemoryAddress = v21;
  v22 = (Render::ParticleEmitterSettings *)v3->pSettings;
  if ( v22 )
  {
    this->mParticleEmitterSettingsStream.mMainMemoryAddress = v22;
    this->mParticleSettings = v22;
  }
  v23 = (__m128)LODWORD(v3->curBasis.v0.x);
  v24 = this->mMemoryStreamer;
  v25 = &this->mMeshEmitter;
  v23.m128_f32[0] = (float)((float)(v23.m128_f32[0] * v23.m128_f32[0]) + (float)(v3->curBasis.v0.y * v3->curBasis.v0.y))
                  + (float)(v3->curBasis.v0.z * v3->curBasis.v0.z);
  this->mTransformScale = (float)((float)(COERCE_FLOAT(_mm_sqrt_ps(v23)) - 1.0)
                                * this->mParticleSettings->mUseTransformScaling)
                        + 1.0;
  this->mSeed = v3->seed;
  v26 = v3->modelToEmitFrom;
  v27 = (signed int)v3->vertexIndexToStartMeshEmissionFrom;
  if ( v26 )
  {
    this->mMeshEmitter.mSeed = &this->mSeed;
    v25->mModelAddrInMainMem = v26;
    this->mMeshEmitter.mMemoryStreamer = v24;
    this->mMeshEmitter.mModelStream.mMainMemoryAddress = v26;
    Render::FXqTaskMeshReader::LoadMesh(&this->mMeshEmitter, 0, (float)v27);
    v25->mIsInitialized = 1;
  }
}er::FXqTaskMeshReader::LoadMesh(&this->mMeshEmitt

// File Line: 67
// RVA: 0x1DFC30
float __fastcall Render::ParticleCreator::AddResumeParticles(Render::ParticleCreator *this, Render::GenerateParticleParameters *generateParticleParams, Render::EmitterParticleAttribute *attributeBuffer, unsigned int *currentBufferCount)
{
  unsigned int v4; // edi
  unsigned int *v5; // rsi
  Render::EmitterParticleAttribute *v6; // r14
  Render::GenerateParticleParameters *v7; // rbp
  Render::ParticleCreator *v8; // rbx
  float v9; // xmm8_4
  float v10; // xmm7_4
  int *seed; // r15
  float v12; // xmm0_4
  Render::ParticleEmitterSettings *v13; // rdx
  float v14; // xmm6_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  Render::EmitterParticleAttribute *v17; // rax
  Render::ParticleEmitterSettings *v18; // rdx
  UFG::qVector3 result; // [rsp+30h] [rbp-78h]

  v4 = 0;
  v5 = currentBufferCount;
  v6 = attributeBuffer;
  v7 = generateParticleParams;
  v8 = this;
  v9 = this->mTaskParams->lastExpiry;
  v10 = this->mTaskParams->creationSimTime;
  if ( this->mTaskParams->currentAddCount )
  {
    seed = &this->mSeed;
    do
    {
      v12 = UFG::qRandom(1.0, &UFG::qDefaultSeed);
      v13 = v8->mParticleSettings;
      v14 = (float)((float)((float)(v13->mLifeMax - v13->mLifeMin) * v12) + v13->mLifeMin) + v10;
      Render::CreateTimeUpdateJitterVector(&result, v13, &v8->mCurBasisNormalized, v8->mTransformScale, seed);
      v15 = result.x;
      v16 = result.y;
      v7->start_time = v10;
      v7->end_time = v14;
      v7->pos.x = v15;
      v7->pos.z = result.z;
      v7->pos.y = v16;
      v17 = Render::ParticleCreator::AddParticle(v8, v7, v6, *v5);
      if ( v17 )
      {
        v18 = v8->mParticleSettings;
        if ( v18->mType != 1 )
          Render::ComputeResumeTimePosAndVel(
            v17,
            v18->mSettings.AnimUVScaleOffset[3],
            v8->mTaskParams->simTime - v10,
            &UFG::qMatrix44::msIdentity,
            &UFG::qMatrix44::msIdentity);
        ++*v5;
        if ( v9 < v14 )
          v9 = v14;
        v10 = v10 + v8->mTaskParams->resumeTimeSkip;
      }
      ++v4;
    }
    while ( v4 < v8->mTaskParams->currentAddCount );
  }
  return v9;
}

// File Line: 108
// RVA: 0x1DFE00
float __fastcall Render::ParticleCreator::AddTimeEmissionParticles(Render::ParticleCreator *this, Render::GenerateParticleParameters *generateParticleParams, Render::EmitterParticleAttribute *attributeBuffer, unsigned int *currentBufferCount)
{
  Render::ParticleRenderUpdateTaskParam *v4; // rax
  unsigned int v5; // ebx
  unsigned int *v6; // rsi
  Render::EmitterParticleAttribute *v7; // r15
  Render::GenerateParticleParameters *v8; // rbp
  Render::ParticleCreator *v9; // rdi
  float v10; // xmm8_4
  int *seed; // r14
  float v12; // xmm6_4
  float v13; // xmm0_4
  Render::ParticleEmitterSettings *v14; // rdx
  float v15; // xmm7_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  UFG::qVector3 result; // [rsp+30h] [rbp-68h]

  v4 = this->mTaskParams;
  v5 = 0;
  v6 = currentBufferCount;
  v7 = attributeBuffer;
  v8 = generateParticleParams;
  v9 = this;
  v10 = this->mTaskParams->lastExpiry;
  if ( this->mTaskParams->currentAddCount )
  {
    seed = &this->mSeed;
    do
    {
      v12 = v4->creationSimTime;
      v13 = UFG::qRandom(1.0, seed);
      v14 = v9->mParticleSettings;
      v15 = (float)((float)((float)(v14->mLifeMax - v14->mLifeMin) * v13) + v14->mLifeMin) + v12;
      Render::CreateTimeUpdateJitterVector(&result, v14, &v9->mCurBasisNormalized, v9->mTransformScale, seed);
      v16 = result.x;
      v17 = result.y;
      v8->start_time = v12;
      v8->end_time = v15;
      v8->pos.x = v16;
      v8->pos.z = result.z;
      v8->pos.y = v17;
      if ( Render::ParticleCreator::AddParticle(v9, v8, v7, *v6) )
      {
        ++*v6;
        if ( v10 < v15 )
          v10 = v15;
      }
      v4 = v9->mTaskParams;
      ++v5;
    }
    while ( v5 < v9->mTaskParams->currentAddCount );
  }
  return v10;
}

// File Line: 138
// RVA: 0x1DF390
float __fastcall Render::ParticleCreator::AddDistanceEmissionParticles(Render::ParticleCreator *this, Render::GenerateParticleParameters *generateParticleParams, Render::EmitterParticleAttribute *attributeBuffer, unsigned int *currentBufferCount)
{
  Render::ParticleRenderUpdateTaskParam *v4; // r14
  __m128 v5; // xmm2
  signed int v6; // edi
  unsigned int *v7; // rsi
  Render::EmitterParticleAttribute *v8; // r13
  Render::GenerateParticleParameters *v9; // r15
  float v10; // xmm1_4
  Render::ParticleCreator *v11; // rbx
  float v12; // xmm0_4
  float v13; // xmm11_4
  float v14; // xmm12_4
  float v15; // xmm13_4
  float v16; // xmm0_4
  float v17; // xmm3_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm0_4
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
  float v33; // xmm9_4
  float v34; // xmm0_4
  Render::ParticleEmitterSettings *v35; // rdx
  float v36; // xmm7_4
  float v37; // xmm8_4
  float v38; // xmm5_4
  float v39; // xmm10_4
  float v40; // xmm1_4
  float v41; // xmm0_4
  float v42; // xmm3_4
  float v43; // xmm10_4
  float v44; // xmm0_4
  float v45; // xmm1_4
  UFG::qVector3 result; // [rsp+30h] [rbp-A8h]
  UFG::qMatrix44 curBasis; // [rsp+40h] [rbp-98h]

  v4 = this->mTaskParams;
  v5 = (__m128)LODWORD(this->mCurBasisNormalized.v3.y);
  v6 = 0;
  v7 = currentBufferCount;
  v8 = attributeBuffer;
  v9 = generateParticleParams;
  v10 = this->mCurBasisNormalized.v3.x - this->mTaskParams->oldBasis.v3.x;
  v11 = this;
  v12 = this->mCurBasisNormalized.v3.z - this->mTaskParams->oldBasis.v3.z;
  v13 = this->mTaskParams->lastExpiry;
  v14 = this->mTaskParams->t;
  v15 = this->mTaskParams->spacing;
  v5.m128_f32[0] = (float)((float)((float)(v5.m128_f32[0] - this->mTaskParams->oldBasis.v3.y)
                                 * (float)(v5.m128_f32[0] - this->mTaskParams->oldBasis.v3.y))
                         + (float)(v10 * v10))
                 + (float)(v12 * v12);
  v16 = this->mCurBasisNormalized.v0.x;
  curBasis.v0.y = this->mCurBasisNormalized.v0.y;
  LODWORD(v17) = (unsigned __int128)_mm_sqrt_ps(v5);
  v18 = this->mCurBasisNormalized.v0.w;
  curBasis.v0.x = v16;
  curBasis.v0.z = this->mCurBasisNormalized.v0.z;
  v19 = this->mCurBasisNormalized.v1.x;
  curBasis.v0.w = v18;
  v20 = this->mCurBasisNormalized.v1.y;
  curBasis.v1.x = v19;
  v21 = this->mCurBasisNormalized.v1.z;
  curBasis.v1.y = v20;
  v22 = this->mCurBasisNormalized.v1.w;
  curBasis.v1.z = v21;
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
  if ( (signed int)v4->currentAddCount > 0 )
  {
    seed = &this->mSeed;
    v32 = 1.0 / v17;
    do
    {
      v33 = v11->mTaskParams->creationSimTime;
      v34 = UFG::qRandom(1.0, seed);
      v35 = v11->mParticleSettings;
      v36 = v4->oldBasis.v3.y;
      v37 = v4->oldBasis.v3.x;
      v38 = v4->oldBasis.v3.z;
      curBasis.v3.w = 1.0;
      v39 = (float)((float)(v35->mLifeMax - v35->mLifeMin) * v34) + v35->mLifeMin;
      v40 = v11->mCurBasisNormalized.v3.y - v36;
      v41 = v11->mCurBasisNormalized.v3.z - v38;
      curBasis.v3.x = (float)((float)(v32 * v14) * (float)(v11->mCurBasisNormalized.v3.x - v37)) + v37;
      curBasis.v3.y = (float)((float)(v32 * v14) * v40) + v36;
      v42 = v11->mTransformScale;
      curBasis.v3.z = (float)((float)(v32 * v14) * v41) + v38;
      v43 = v39 + v33;
      Render::CreateTimeUpdateJitterVector(&result, v35, &curBasis, v42, seed);
      v44 = result.x;
      v45 = result.y;
      v9->start_time = v33;
      v9->end_time = v43;
      v9->pos.x = v44;
      v9->pos.z = result.z;
      v9->pos.y = v45;
      if ( Render::ParticleCreator::AddParticle(v11, v9, v8, *v7) )
      {
        ++*v7;
        v14 = v14 + v15;
        if ( v13 < v43 )
          v13 = v43;
      }
      ++v6;
    }
    while ( v6 < (signed int)v11->mTaskParams->currentAddCount );
  }
  return v13;
}

// File Line: 180
// RVA: 0x1DF700
Render::EmitterParticleAttribute *__fastcall Render::ParticleCreator::AddParticle(Render::ParticleCreator *this, Render::GenerateParticleParameters *generateParticleParams, Render::EmitterParticleAttribute *attribBuffer, unsigned int currentBufferCount)
{
  bool v4; // zf
  float v5; // xmm7_4
  int v6; // edi
  Render::EmitterParticleAttribute *v7; // r14
  Render::GenerateParticleParameters *v8; // r12
  Render::ParticleCreator *v9; // rsi
  float v10; // xmm8_4
  float v11; // xmm9_4
  Render::ParticleEmitterSettings *v12; // rdx
  unsigned __int64 v13; // rcx
  int v14; // eax
  signed int *v15; // r15
  signed __int16 *v16; // rax
  unsigned int cur_index; // ebx
  unsigned int v18; // edi
  float v19; // xmm6_4
  _DWORD *v20; // rcx
  _DWORD *v21; // rbx
  unsigned int v22; // eax
  float *v23; // rax
  Render::ParticleEmitterSettings *v24; // rcx
  float v26; // xmm4_4
  float v27; // xmm6_4
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm6_4
  float v31; // xmm1_4
  float v32; // xmm0_4
  UFG::qVector3 v33; // [rsp+40h] [rbp-98h]
  UFG::qVector3 v34; // [rsp+50h] [rbp-88h]
  UFG::qVector3 triangleVertices; // [rsp+60h] [rbp-78h]
  UFG::qVector3 outPosition; // [rsp+6Ch] [rbp-6Ch]
  UFG::qVector3 outNormal; // [rsp+78h] [rbp-60h]
  Render::ParticleGenerator v38; // [rsp+88h] [rbp-50h]
  Render::ParticleCreator *v39; // [rsp+158h] [rbp+80h]
  Render::EmitterParticleAttribute *v40; // [rsp+168h] [rbp+90h]
  int vars0; // [rsp+170h] [rbp+98h]

  v4 = this->mMeshEmitter.mIsInitialized == 0;
  v5 = UFG::qVector3::msZero.x;
  v6 = currentBufferCount;
  v7 = attribBuffer;
  v8 = generateParticleParams;
  v9 = this;
  v33 = UFG::qVector3::msZero;
  v10 = UFG::qVector3::msZero.y;
  v11 = UFG::qVector3::msZero.z;
  if ( v4 )
    goto LABEL_15;
  v12 = generateParticleParams->pfx;
  v13 = v12->mBitFields[0];
  if ( ((unsigned __int8)v13 >> 1) & 1 )
  {
    v14 = UFG::qRandom(*((_DWORD *)v9->mMeshEmitter.mMeshStream.mMainMemoryAddress + 58), v8->seed);
    v15 = (signed int *)v9->mMeshEmitter.mMeshStream.mMainMemoryAddress;
    v16 = (signed __int16 *)(*((_QWORD *)v15 + 10)
                           + *(_QWORD *)(*((_QWORD *)v15 + 10) + 96i64)
                           + (unsigned int)(6 * v14)
                           + 2 * (v15[57] + 48i64));
    cur_index = v16[1];
    v18 = v16[2];
    Render::FXqTaskMeshReader::DecodeVertexPositionAndNormal(
      &v9->mMeshEmitter,
      v9->mMeshEmitter.mpVertexBuffers,
      v9->mMeshEmitter.mpMainMemoryVertexBuffers,
      v15[14],
      *v16,
      &triangleVertices,
      &triangleVertices);
    Render::FXqTaskMeshReader::DecodeVertexPositionAndNormal(
      &v9->mMeshEmitter,
      v9->mMeshEmitter.mpVertexBuffers,
      v9->mMeshEmitter.mpMainMemoryVertexBuffers,
      v15[14],
      cur_index,
      &outPosition,
      &outPosition);
    Render::FXqTaskMeshReader::DecodeVertexPositionAndNormal(
      &v9->mMeshEmitter,
      v9->mMeshEmitter.mpVertexBuffers,
      v9->mMeshEmitter.mpMainMemoryVertexBuffers,
      v15[14],
      v18,
      &outNormal,
      &outNormal);
    Render::FXqTaskMeshReader::GetRandomPointOnTriangle(&triangleVertices, &triangleVertices, v8->seed, &v34, &v33);
    v9 = v39;
    v7 = v40;
  }
  else
  {
    if ( ((unsigned __int8)v13 >> 6) & 1 )
    {
      v19 = v12->mMeshEmissionVertexSkip;
      v20 = v9->mMeshEmitter.mMeshStream.mMainMemoryAddress;
      if ( (float)(signed int)v9->mMeshEmitter.mNumVerticesInMesh <= v9->mMeshEmitter.mCurVertexForSequentialEmission )
        v9->mMeshEmitter.mCurVertexForSequentialEmission = 0.0;
      Render::FXqTaskMeshReader::DecodeVertexPositionAndNormal(
        &v9->mMeshEmitter,
        v9->mMeshEmitter.mpVertexBuffers,
        v9->mMeshEmitter.mpMainMemoryVertexBuffers,
        v20[14],
        (signed int)v9->mMeshEmitter.mCurVertexForSequentialEmission,
        &v34,
        &v33);
      v9->mMeshEmitter.mCurVertexForSequentialEmission = (float)(signed int)((signed int)(float)(v19
                                                                                               + v9->mMeshEmitter.mCurVertexForSequentialEmission)
                                                                           % v9->mMeshEmitter.mNumVerticesInMesh);
      goto LABEL_10;
    }
    v21 = v9->mMeshEmitter.mMeshStream.mMainMemoryAddress;
    v22 = UFG::qRandom(v9->mMeshEmitter.mNumVerticesInMesh, v9->mMeshEmitter.mSeed);
    Render::FXqTaskMeshReader::DecodeVertexPositionAndNormal(
      &v9->mMeshEmitter,
      v9->mMeshEmitter.mpVertexBuffers,
      v9->mMeshEmitter.mpMainMemoryVertexBuffers,
      v21[14],
      v22,
      &v34,
      &v33);
  }
  v6 = vars0;
LABEL_10:
  v10 = v33.y;
  v5 = v33.x;
  v11 = v33.z;
  v23 = &v9->mTaskParams->renderMatrix.v0.x;
  v24 = v8->pfx;
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
    v31 = v34.y + v8->pos.y;
    v8->pos.x = v34.x + v8->pos.x;
    v32 = v34.z;
    v8->pos.y = v31;
    v8->pos.z = v32 + v8->pos.z;
  }
  else
  {
    v26 = (float)(v34.y * v23[21]) + (float)(v34.x * v23[17]);
    v27 = (float)(v34.y * v23[22]) + (float)(v34.x * v23[18]);
    v28 = v34.z * v23[25];
    v29 = v34.z * v23[26];
    v8->pos.x = (float)((float)((float)(v34.y * v23[20]) + (float)(v34.x * v23[16])) + (float)(v34.z * v23[24]))
              + v8->pos.x;
    v30 = (float)(v27 + v29) + v8->pos.z;
    v8->pos.y = (float)(v26 + v28) + v8->pos.y;
    v8->pos.z = v30;
  }
LABEL_15:
  v8->meshNormal.x = v5;
  v8->meshNormal.y = v10;
  v8->meshNormal.z = v11;
  v38.mParameters = v8;
  UFG::qInverseAffine(&v38.mInvBasis, &v8->curBasisNormalized);
  return Render::ParticleGenerator::Generate(&v38, v7, v6);
}

// File Line: 305
// RVA: 0x1E16B0
UFG::qVector3 *__fastcall Render::ExtrapolatePositionFromOriginalData(UFG::qVector3 *result, Render::EmitterParticleAttribute *attribute, float velocityAlign, float timeElapsed, UFG::qMatrix44 *localWorld, UFG::qMatrix44 *worldLocal)
{
  float v6; // xmm1_4
  UFG::qVector3 *v7; // rdi
  Render::EmitterParticleAttribute *v8; // rbx
  float v9; // xmm9_4
  float v10; // xmm0_4
  float v11; // xmm5_4
  float v12; // xmm13_4
  float v13; // xmm11_4
  float v14; // xmm12_4
  float v15; // xmm10_4
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
  UFG::qVector4 resulta; // [rsp+20h] [rbp-C8h]
  float v32; // [rsp+F0h] [rbp+8h]
  float v33; // [rsp+F8h] [rbp+10h]
  float v34; // [rsp+100h] [rbp+18h]
  float v35; // [rsp+108h] [rbp+20h]
  float worldLocala; // [rsp+118h] [rbp+30h]

  v6 = attribute->vPosAndGrav.w;
  v7 = result;
  v8 = attribute;
  v9 = (float)((float)(worldLocal->v1.x + worldLocal->v0.x) * 0.0) + (float)(v6 * worldLocal->v2.x);
  v33 = (float)((float)(worldLocal->v1.x + worldLocal->v0.x) * 0.0) + (float)(v6 * worldLocal->v2.x);
  v35 = (float)((float)(worldLocal->v1.y + worldLocal->v0.y) * 0.0) + (float)(v6 * worldLocal->v2.y);
  worldLocala = (float)((float)(worldLocal->v1.z + worldLocal->v0.z) * 0.0) + (float)(v6 * worldLocal->v2.z);
  UFG::qHalfVector4::operator UFG::qVector4 const(&attribute->vInitialVel, &resulta);
  LODWORD(v34) = (((((unsigned int)v8->vVelAndDamp.w.mRep >> 10) & 0x1F) + 112) << 23) & 0x7F800000 | ((v8->vVelAndDamp.w.mRep & 0x3FF | 8 * (v8->vVelAndDamp.w.mRep & 0x8000)) << 13);
  v10 = v34 * timeElapsed;
  if ( (float)(v34 * timeElapsed) <= 0.0 )
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
  v12 = 1.0 / (float)(v34 * v34);
  v13 = resulta.y;
  v14 = resulta.x;
  v15 = resulta.z;
  v16 = UFG::qVector3::msZero.x;
  v17 = UFG::qVector3::msZero.y;
  v18 = (float)((float)(1.0 / v34) * resulta.y)
      + (float)((float)(1.0 / (float)(v34 * v34)) * COERCE_FLOAT(LODWORD(v35) ^ _xmm[0]));
  v19 = (float)((float)(1.0 / v34) * resulta.x) + (float)(v12 * COERCE_FLOAT(LODWORD(v9) ^ _xmm[0]));
  v20 = (float)((float)(1.0 / v34) * resulta.z) + (float)(v12 * COERCE_FLOAT(LODWORD(worldLocala) ^ _xmm[0]));
  v21 = expf(v11);
  v22 = (float)((float)(v14 * v34) - (float)(v21 * (float)((float)(v33 * v32) + (float)((float)(v19 * v34) * v34))))
      - v33;
  v23 = (float)((float)(v13 * v34) - (float)(v21 * (float)((float)(v35 * v32) + (float)((float)(v18 * v34) * v34))))
      - v35;
  v24 = (float)((float)(v15 * v34)
              - (float)(v21 * (float)((float)(worldLocala * v32) + (float)((float)(v20 * v34) * v34))))
      - worldLocala;
  v25 = expf(COERCE_FLOAT(LODWORD(v32) ^ _xmm[0]));
  v26 = UFG::qVector3::msZero.z - (float)((float)(v25 * v12) * v24);
  v27 = v17 - (float)((float)(v25 * v12) * v23);
  v28 = v7;
  v29 = v8->vPosAndGrav.x + (float)(v16 - (float)((float)(v25 * v12) * v22));
  v30 = v8->vPosAndGrav.z + v26;
  v7->y = v8->vPosAndGrav.y + v27;
  v7->z = v30;
  v7->x = v29;
  return v28;
}

// File Line: 351
// RVA: 0x1E0F30
void __fastcall Render::ComputeResumeTimePosAndVel(Render::EmitterParticleAttribute *attribute, float velocityAlign, float timeElapsed, UFG::qMatrix44 *localWorld, UFG::qMatrix44 *worldLocal)
{
  float v5; // xmm3_4
  Render::EmitterParticleAttribute *v6; // rbx
  float v7; // xmm11_4
  float v8; // xmm13_4
  float v9; // xmm12_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  int v13; // xmm14_4
  float v14; // xmm7_4
  float v15; // xmm8_4
  float v16; // xmm9_4
  float v17; // xmm0_4
  float v18; // xmm0_4
  UFG::qVector3 result; // [rsp+30h] [rbp-A8h]
  float v20; // [rsp+F0h] [rbp+18h]

  v5 = attribute->vPosAndGrav.w;
  v6 = attribute;
  v7 = (float)((float)(worldLocal->v1.x + worldLocal->v0.x) * 0.0) + (float)(v5 * worldLocal->v2.x);
  v8 = (float)((float)(worldLocal->v1.z + worldLocal->v0.z) * 0.0) + (float)(v5 * worldLocal->v2.z);
  v9 = (float)((float)(worldLocal->v1.y + worldLocal->v0.y) * 0.0) + (float)(v5 * worldLocal->v2.y);
  Render::ExtrapolatePositionFromOriginalData(&result, attribute, velocityAlign, timeElapsed, localWorld, worldLocal);
  v10 = result.y;
  v6->vPosAndGrav.x = result.x;
  v11 = result.z;
  v6->vPosAndGrav.y = v10;
  v6->vPosAndGrav.z = v11;
  UFG::qHalfVector4::operator UFG::qVector4 const(&v6->vVelAndDamp, (UFG::qVector4 *)&result);
  LODWORD(v20) = (((((unsigned int)v6->vVelAndDamp.w.mRep >> 10) & 0x1F) + 112) << 23) & 0x7F800000 | ((v6->vVelAndDamp.w.mRep & 0x3FF | 8 * (v6->vVelAndDamp.w.mRep & 0x8000)) << 13);
  v12 = v20 * timeElapsed;
  v13 = LODWORD(v20) ^ _xmm[0];
  v14 = (float)(COERCE_FLOAT(LODWORD(v20) ^ _xmm[0]) * result.x) + v7;
  v15 = (float)(COERCE_FLOAT(LODWORD(v20) ^ _xmm[0]) * result.y) + v9;
  v16 = (float)(COERCE_FLOAT(LODWORD(v20) ^ _xmm[0]) * result.z) + v8;
  if ( (float)(v20 * timeElapsed) <= 0.0 )
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
  Render::EmitterParticleAttribute::SetVelocity(v6, &result);
}

// File Line: 369
// RVA: 0x1E1160
UFG::qVector3 *__fastcall Render::CreateTimeUpdateJitterVector(UFG::qVector3 *result, Render::ParticleEmitterSettings *pfx, UFG::qMatrix44 *curBasis, float scale, int *seed)
{
  UFG::qMatrix44 *v5; // rbp
  UFG::qVector3 *v6; // rdi
  Render::ParticleEmitterSettings *v7; // rsi
  float v8; // xmm7_4
  float v9; // xmm9_4
  float v10; // xmm8_4
  float v11; // xmm8_4
  float v12; // xmm9_4
  float v13; // xmm0_4
  float v14; // xmm11_4
  float v15; // xmm10_4
  float v16; // xmm9_4
  float v17; // xmm7_4
  float v18; // xmm6_4
  float v19; // xmm0_4
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

  v5 = curBasis;
  v6 = result;
  v7 = pfx;
  if ( pfx->mBitFields[0] & 1 )
  {
    if ( (pfx->mBitFields[0] & 1) == 1 )
    {
      v11 = UFG::qRandom(1.0, seed);
      v12 = UFG::qRandom(1.0, seed);
      v13 = UFG::qRandom(1.0, seed);
      v9 = (float)(v12 - 0.5) * v7->mJitter.y;
      v10 = (float)(v11 - 0.5) * v7->mJitter.z;
      v8 = (float)(v13 - 0.5) * v7->mJitter.x;
    }
    else
    {
      v8 = 0.0;
      v9 = 0.0;
      v10 = 0.0;
    }
  }
  else
  {
    do
    {
      v14 = (float)(UFG::qRandom(1.0, seed) * 2.0) - 1.0;
      v15 = (float)(UFG::qRandom(1.0, seed) * 2.0) - 1.0;
      v16 = (float)(UFG::qRandom(1.0, seed) * 2.0) - 1.0;
    }
    while ( (float)((float)((float)(v15 * v15) + (float)(v16 * v16)) + (float)(v14 * v14)) >= 1.0 );
    v17 = UFG::qRandom(1.0, seed);
    v18 = UFG::qRandom(1.0, seed);
    v19 = UFG::qRandom(1.0, seed);
    v20 = (float)((float)(v7->mJitter.z * v17) * 2.0) - v7->mJitter.z;
    v21 = (float)((float)(v15 * v15) + (float)(v16 * v16)) + (float)(v14 * v14);
    if ( v21 == 0.0 )
      v22 = 0.0;
    else
      v22 = 1.0 / fsqrt(v21);
    v23 = v22 * v16;
    v24 = v22;
    v8 = v23 * (float)((float)((float)(v7->mJitter.x * v19) * 2.0) - v7->mJitter.x);
    v10 = (float)(v22 * v14) * v20;
    v9 = (float)(v24 * v15) * (float)((float)((float)(v7->mJitter.y * v18) * 2.0) - v7->mJitter.y);
  }
  v25 = v6;
  if ( v7->mSpace == 1 )
  {
    v6->x = v8;
    v6->y = v9;
    v6->z = v10;
  }
  else
  {
    v26 = v8;
    v27 = v8;
    v28 = (float)((float)(v8 * v5->v0.z) + v5->v3.z) + (float)(v9 * v5->v1.z);
    v29 = (float)((float)(v27 * v5->v0.y) + v5->v3.y) + (float)(v9 * v5->v1.y);
    v30 = (float)((float)((float)(v26 * v5->v0.x) + v5->v3.x) + (float)(v9 * v5->v1.x)) + (float)(v10 * v5->v2.x);
    v31 = v10 * v5->v2.y;
    v32 = v10 * v5->v2.z;
    v6->x = v30;
    v6->y = v29 + v31;
    v6->z = v28 + v32;
  }
  return v25;
}

// File Line: 437
// RVA: 0x1E1A20
void __fastcall Render::GenerateNewParticles(UFG::qMemoryStream<Render::ParticleRenderUpdateTaskParam,624> *taskParams, Render::ParticleEmitterSettings *pfx, Render::ParticleLighting *particleLighting, UFG::qMatrix44 *curBasisNormalized)
{
  UFG::qMatrix44 *v4; // r14
  Render::ParticleLighting *v5; // r15
  Render::ParticleEmitterSettings *v6; // r12
  UFG::qMemoryStream<Render::ParticleRenderUpdateTaskParam,624> *v7; // rbx
  float *v8; // r10
  signed int v9; // edx
  __int64 v10; // rcx
  signed __int64 v11; // ST58_8
  __int64 v12; // r8
  __int64 v13; // r9
  unsigned int v14; // ecx
  int v15; // esi
  UFG::qVector4 v16; // xmm2
  UFG::qVector4 v17; // xmm1
  UFG::qVector4 v18; // xmm0
  UFG::qVector4 *v19; // rcx
  UFG::qVector4 v20; // xmm2
  UFG::qVector4 v21; // xmm1
  UFG::qVector4 v22; // xmm0
  __int64 v23; // rax
  float v24; // xmm0_4
  char ptr; // [rsp+68h] [rbp-70h]
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
  Render::GenerateParticleParameters generateParticleParams; // [rsp+C8h] [rbp-10h]
  Render::ParticleCreator v37; // [rsp+1A8h] [rbp+D0h]
  int v38; // [rsp+348h] [rbp+270h]
  void *retaddr; // [rsp+368h] [rbp+290h]
  UFG::qMemoryStreamer *v40; // [rsp+370h] [rbp+298h]
  unsigned int *v41; // [rsp+378h] [rbp+2A0h]
  Render::EmitterParticleAttribute *v42; // [rsp+380h] [rbp+2A8h]
  float *v43; // [rsp+388h] [rbp+2B0h]

  v35 = -2i64;
  v4 = curBasisNormalized;
  v5 = particleLighting;
  v6 = pfx;
  v7 = taskParams;
  v38 = *((_DWORD *)taskParams->mMainMemoryAddress + 142);
  `eh vector constructor iterator(
    &ptr,
    0x18ui64,
    2,
    (void (__fastcall *)(void *))UFG::qMemoryStream<UFG::AIInterestComponent,432>::qMemoryStream<UFG::AIInterestComponent,432>);
  v30 = 0i64;
  v31 = 0i64;
  v32 = 0;
  v33 = -1;
  v8 = (float *)v7->mMainMemoryAddress;
  v9 = (signed int)v8[146];
  v10 = *((_QWORD *)v8 + 72);
  if ( v10 )
  {
    v34 = &v38;
    v30 = v40;
    v11 = *(_QWORD *)(v10 + 184) + v10 + 184 + *(unsigned int *)(*(_QWORD *)(v10 + 184) + v10 + 184);
    v33 = 0;
    v12 = *(_QWORD *)(v11 + 112);
    v26 = v12;
    v13 = *(_QWORD *)(v11 + 144);
    v14 = *(_DWORD *)(v12 + 108);
    HIDWORD(v31) = v14;
    if ( v14 )
    {
      *(float *)&v31 = (float)(signed int)((signed int)(float)v9 % v14);
      v26 = v12;
      v28 = *(_QWORD *)(v12 + 96) + v12 + 96;
      v27 = v13;
      v29 = *(_QWORD *)(v13 + 96) + v13 + 96;
    }
    v32 = 1;
  }
  v15 = *((_DWORD *)v8 + 139);
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
  Render::ParticleCreator::SetTaskParams(&v37, (Render::ParticleRenderUpdateTaskParam *)v7->mMainMemoryAddress);
  v16 = v4->v1;
  v17 = v4->v2;
  v18 = v4->v3;
  generateParticleParams.curBasisNormalized.v0 = v4->v0;
  generateParticleParams.curBasisNormalized.v1 = v16;
  generateParticleParams.curBasisNormalized.v2 = v17;
  generateParticleParams.curBasisNormalized.v3 = v18;
  v19 = (UFG::qVector4 *)v7->mMainMemoryAddress;
  v17.x = v19[13].w;
  v16.x = v19[14].x;
  generateParticleParams.emitterVelocity.x = v19[13].z;
  generateParticleParams.emitterVelocity.y = v17.x;
  generateParticleParams.emitterVelocity.z = v16.x;
  generateParticleParams.pfx = v6;
  v17.x = v19[12].y;
  v16.x = v19[12].z;
  generateParticleParams.cameraPos.x = v19[12].x;
  generateParticleParams.cameraPos.y = v17.x;
  generateParticleParams.cameraPos.z = v16.x;
  generateParticleParams.seed = &v38;
  generateParticleParams.sizeScale = 1.0;
  v20 = v19[1];
  v21 = v19[2];
  v22 = v19[3];
  generateParticleParams.renderMatrix.v0 = *v19;
  generateParticleParams.renderMatrix.v1 = v20;
  generateParticleParams.renderMatrix.v2 = v21;
  generateParticleParams.renderMatrix.v3 = v22;
  generateParticleParams.simTime = v19[33].x;
  generateParticleParams.particleLighting = v5;
  generateParticleParams.velocityScale = 1.0;
  LODWORD(generateParticleParams.transformScale) = (_DWORD)retaddr;
  v23 = *(_QWORD *)&v19[37].x;
  if ( v23 )
  {
    generateParticleParams.velocityScale = *(float *)(v23 + 76);
    generateParticleParams.sizeScale = *(float *)(v23 + 84);
  }
  if ( v15 == 1 )
  {
    v24 = Render::ParticleCreator::AddDistanceEmissionParticles(&v37, &generateParticleParams, v42, v41);
  }
  else if ( v19[33].z == 0.0 )
  {
    v24 = Render::ParticleCreator::AddTimeEmissionParticles(&v37, &generateParticleParams, v42, v41);
  }
  else
  {
    v24 = Render::ParticleCreator::AddResumeParticles(&v37, &generateParticleParams, v42, v41);
  }
  *v43 = v24;
  `eh vector destructor iterator(v37.mMeshEmitter.mVertexBuffers, 0x18ui64, 2, (void (__fastcall *)(void *))_);
  `eh vector destructor iterator(&ptr, 0x18ui64, 2, (void (__fastcall *)(void *))_);
}

// File Line: 508
// RVA: 0x1DD430
Render::TargetParticleMoverWithBlend *__fastcall Render::for_each<Render::EmitterParticleAttribute *,Render::TargetParticleMoverWithBlend>(Render::TargetParticleMoverWithBlend *result, Render::EmitterParticleAttribute *first, Render::EmitterParticleAttribute *last, Render::TargetParticleMoverWithBlend *f)
{
  Render::TargetParticleMoverWithBlend *v4; // rdi
  Render::EmitterParticleAttribute *v5; // rsi
  Render::EmitterParticleAttribute *v6; // rbx
  Render::TargetParticleMoverWithBlend *i; // r14
  float v8; // eax
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // eax
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // eax
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // eax
  float v18; // xmm1_4
  float v19; // xmm2_4

  v4 = f;
  v5 = last;
  v6 = first;
  for ( i = result; v6 != v5; ++v6 )
    Render::TargetParticleMoverWithBlend::operator()(v4, v6);
  v8 = v4->mWorldLocal.v0.x;
  v9 = v4->mWorldLocal.v0.z;
  v10 = v4->mWorldLocal.v0.w;
  i->mWorldLocal.v0.y = v4->mWorldLocal.v0.y;
  i->mWorldLocal.v0.z = v9;
  i->mWorldLocal.v0.x = v8;
  i->mWorldLocal.v0.w = v10;
  v11 = v4->mWorldLocal.v1.x;
  v12 = v4->mWorldLocal.v1.z;
  v13 = v4->mWorldLocal.v1.w;
  i->mWorldLocal.v1.y = v4->mWorldLocal.v1.y;
  i->mWorldLocal.v1.x = v11;
  i->mWorldLocal.v1.z = v12;
  i->mWorldLocal.v1.w = v13;
  v14 = v4->mWorldLocal.v2.x;
  v15 = v4->mWorldLocal.v2.z;
  v16 = v4->mWorldLocal.v2.w;
  i->mWorldLocal.v2.y = v4->mWorldLocal.v2.y;
  i->mWorldLocal.v2.x = v14;
  i->mWorldLocal.v2.z = v15;
  i->mWorldLocal.v2.w = v16;
  v17 = v4->mWorldLocal.v3.x;
  v18 = v4->mWorldLocal.v3.z;
  v19 = v4->mWorldLocal.v3.w;
  i->mWorldLocal.v3.y = v4->mWorldLocal.v3.y;
  i->mWorldLocal.v3.x = v17;
  i->mWorldLocal.v3.z = v18;
  i->mWorldLocal.v3.w = v19;
  i->mSettings = v4->mSettings;
  i->mParticleLighting = v4->mParticleLighting;
  i->mTaskParams = v4->mTaskParams;
  i->mTransformScaleFactor = v4->mTransformScaleFactor;
  return i;
}

// File Line: 527
// RVA: 0x1E28C0
void __fastcall Render::UpdateExistingParticles(UFG::qMemoryStream<Render::ParticleRenderUpdateTaskParam,624> *taskParams, Render::ParticleEmitterSettings *pfx, UFG::qMatrix44 *curBasisNormalized, unsigned int currentBufferCount, Render::ParticleLighting *particleLighting, float transformScale, Render::EmitterParticleAttribute *attributeBuffer)
{
  Render::ParticleEmitterSettings *v7; // rsi
  UFG::qMemoryStream<Render::ParticleRenderUpdateTaskParam,624> *v8; // rbx
  __int64 v9; // r15
  UFG::qMatrix44 *v10; // rdi
  void *v11; // r14
  Render::EmitterParticleAttribute *v12; // rdi
  float *v13; // rbx
  unsigned int v14; // eax
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
  Render::BasicParticleMoverWithLocalToWorldBlend *v26; // rax
  Render::BasicParticleMoverWithLocalToWorldBlend *v27; // rdi
  Render::EmitterParticleAttribute *v28; // rsi
  Render::ParticleRenderUpdateTaskParam *v29; // rdx
  Render::EmitterParticleAttribute *v30; // rbx
  Render::TargetParticleMover *v31; // rax
  Render::TargetParticleMoverWithBlend *v32; // rax
  UFG::qMatrix44 d; // [rsp+40h] [rbp-C0h]
  UFG::qColour colour; // [rsp+80h] [rbp-80h]
  Render::BounceParticleMoverWithLocalToWorldBlend v35; // [rsp+90h] [rbp-70h]
  UFG::qMatrix44 invOldBasis; // [rsp+170h] [rbp+70h]
  Render::BounceParticleMoverWithLocalToWorldBlend v37; // [rsp+1B0h] [rbp+B0h]

  v7 = pfx;
  v8 = taskParams;
  v9 = currentBufferCount;
  v10 = curBasisNormalized;
  UFG::qInverseAffine(&d, (UFG::qMatrix44 *)taskParams->mMainMemoryAddress);
  UFG::qInverse(&invOldBasis, (UFG::qMatrix44 *)v8->mMainMemoryAddress + 2);
  v11 = v8->mMainMemoryAddress;
  if ( v7->mType == 1 )
  {
    v12 = &attributeBuffer[(unsigned int)v9];
    if ( attributeBuffer != v12 )
    {
      colour.r = 1.0;
      colour.g = 1.0;
      colour.b = 1.0;
      v13 = &attributeBuffer->fStartTime;
      do
      {
        colour.a = Render::ComputeInterpolatedAlpha(
                     v7->mSettings.ColorAlphaKeys,
                     v7->mSettings.AlphaKeyPositions,
                     (float)(*((float *)v11 + 132) - *v13) / (float)(v13[1] - *v13));
        Render::EmitterParticleAttribute::SetColour((Render::EmitterParticleAttribute *)(v13 - 15), &colour);
        v13 += 21;
      }
      while ( v13 - 15 != (float *)v12 );
    }
  }
  else
  {
    v14 = v7->mPhysicsType;
    switch ( v14 )
    {
      case 0x47B9F312u:
        if ( v7->mLocalSpaceToWorldSpaceBlend == 0.0 )
        {
          v35.mCurBasisNormalized = d;
          *(_QWORD *)&v35.mInverseOldBasis.v0.x = v7;
          *(_QWORD *)&v35.mInverseOldBasis.v0.z = particleLighting;
          *(_QWORD *)&v35.mInverseOldBasis.v1.x = v11;
          v35.mInverseOldBasis.v1.z = transformScale;
          Render::for_each<Render::EmitterParticleAttribute *,Render::BounceParticleMover>(
            (Render::BounceParticleMover *)&v37,
            attributeBuffer,
            &attributeBuffer[v9],
            (Render::BounceParticleMover *)&v35);
        }
        else
        {
          Render::BounceParticleMoverWithLocalToWorldBlend::BounceParticleMoverWithLocalToWorldBlend(
            &v37,
            (Render::ParticleRenderUpdateTaskParam *)v11,
            v7,
            particleLighting,
            transformScale,
            v10,
            &d,
            &invOldBasis);
          v15 = attributeBuffer;
          v17 = v16;
          v18 = &attributeBuffer[v9];
          if ( attributeBuffer != v18 )
          {
            do
            {
              Render::BounceParticleMoverWithLocalToWorldBlend::operator()(v17, v15);
              ++v15;
            }
            while ( v15 != v18 );
          }
          Render::BasicParticleMoverWithLocalToWorldBlend::BasicParticleMoverWithLocalToWorldBlend(&v35, v17);
        }
        break;
      case 0x7067EEBCu:
        Render::FXForceParticleMover::FXForceParticleMover(
          (Render::FXForceParticleMover *)&v37,
          (Render::ParticleRenderUpdateTaskParam *)v11,
          v7,
          particleLighting,
          transformScale,
          &d,
          &invOldBasis,
          *((Render::FXForce **)v11 + 34));
        v19 = attributeBuffer;
        v21 = v20;
        v22 = &attributeBuffer[v9];
        if ( attributeBuffer != v22 )
        {
          do
          {
            Render::FXForceParticleMover::operator()(v21, v19);
            ++v19;
          }
          while ( v19 != v22 );
        }
        Render::FXForceParticleMover::FXForceParticleMover((Render::FXForceParticleMover *)&v35, v21);
        break;
      case 0x1CED17C4u:
      case 0xFB1A9069:
        v29 = (Render::ParticleRenderUpdateTaskParam *)v8->mMainMemoryAddress;
        v30 = &attributeBuffer[v9];
        if ( v7->mLocalSpaceToWorldSpaceBlend == 0.0 )
        {
          Render::TargetParticleMover::TargetParticleMover(
            (Render::TargetParticleMoverWithBlend *)&v37,
            v29,
            v7,
            particleLighting,
            transformScale,
            &d);
          Render::for_each<Render::EmitterParticleAttribute *,Render::TargetParticleMover>(
            (Render::TargetParticleMover *)&v35,
            attributeBuffer,
            v30,
            v31);
        }
        else
        {
          Render::TargetParticleMover::TargetParticleMover(
            (Render::TargetParticleMoverWithBlend *)&v37,
            v29,
            v7,
            particleLighting,
            transformScale,
            &d);
          Render::for_each<Render::EmitterParticleAttribute *,Render::TargetParticleMoverWithBlend>(
            (Render::TargetParticleMoverWithBlend *)&v35,
            attributeBuffer,
            v30,
            v32);
        }
        break;
      default:
        v23 = (Render::ParticleRenderUpdateTaskParam *)v8->mMainMemoryAddress;
        if ( v7->mLocalSpaceToWorldSpaceBlend == 0.0 )
        {
          Render::TargetParticleMover::TargetParticleMover(
            (Render::TargetParticleMoverWithBlend *)&v37,
            v23,
            v7,
            particleLighting,
            transformScale,
            &d);
          Render::for_each<Render::EmitterParticleAttribute *,Render::BasicParticleMover>(
            (Render::BasicParticleMover *)&v35,
            attributeBuffer,
            &attributeBuffer[v9],
            v24);
        }
        else
        {
          Render::BasicParticleMoverWithLocalToWorldBlend::BasicParticleMoverWithLocalToWorldBlend(
            (Render::BasicParticleMoverWithLocalToWorldBlend *)&v37,
            v23,
            v7,
            particleLighting,
            transformScale,
            v10,
            &d,
            &invOldBasis);
          v25 = attributeBuffer;
          v27 = v26;
          v28 = &attributeBuffer[v9];
          if ( attributeBuffer != v28 )
          {
            do
            {
              Render::BasicParticleMoverWithLocalToWorldBlend::operator()(v27, v25);
              ++v25;
            }
            while ( v25 != v28 );
          }
          Render::BasicParticleMoverWithLocalToWorldBlend::BasicParticleMoverWithLocalToWorldBlend(
            &v35,
            (Render::BounceParticleMoverWithLocalToWorldBlend *)v27);
        }
        break;
    }
  }
}

// File Line: 589
// RVA: 0x1DCC80
void __fastcall Render::ParticleRenderUpdateTask(int worker_id, UFG::qMemoryStreamer *memory_streamer, void *param0, void *param1)
{
  _DWORD *v4; // r12
  void *v5; // rbx
  UFG::qMemoryStreamer *v6; // rdi
  Render::ParticleEmitterSettings *v7; // r14
  __m128 v8; // xmm12
  __m128 v9; // xmm1
  float v10; // xmm8_4
  float v11; // xmm4_4
  __m128 v12; // xmm5
  float v13; // xmm15_4
  float v14; // xmm2_4
  float v15; // xmm0_4
  __m128 v16; // xmm2
  float v17; // xmm2_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  __m128 v20; // xmm2
  float v21; // xmm2_4
  float v22; // xmm1_4
  __m128 v23; // xmm2
  float v24; // xmm3_4
  float v25; // xmm1_4
  float v26; // xmm0_4
  unsigned int v27; // er9
  void *v28; // rax
  unsigned int v29; // er15
  unsigned int v30; // ecx
  unsigned __int64 main_num_bytes; // rsi
  void *v32; // rax
  float v33; // [rsp+50h] [rbp-B0h]
  UFG::qMatrix44 curBasisNormalized; // [rsp+60h] [rbp-A0h]
  UFG::qMemoryStream<Render::ParticleRenderUpdateTaskParam,624> taskParams; // [rsp+A0h] [rbp-60h]
  UFG::qVector3 effectPosition; // [rsp+B8h] [rbp-48h]
  __int64 v37; // [rsp+D0h] [rbp-30h]
  char ptr; // [rsp+E0h] [rbp-20h]
  int v39; // [rsp+720h] [rbp+620h]
  char *stream_name; // [rsp+730h] [rbp+630h]
  void *main_mem; // [rsp+738h] [rbp+638h]
  int v42; // [rsp+740h] [rbp+640h]
  Render::EmitterParticleAttribute *v43; // [rsp+748h] [rbp+648h]
  char v44; // [rsp+833h] [rbp+733h]
  unsigned int currentBufferCount; // [rsp+1350h] [rbp+1250h]
  float v46; // [rsp+1358h] [rbp+1258h]

  v37 = -2i64;
  v4 = param1;
  v5 = param0;
  v6 = memory_streamer;
  taskParams.mName = "<unassigned>";
  taskParams.mState = 0;
  taskParams.mMainMemoryAddress = param0;
  v7 = (Render::ParticleEmitterSettings *)*((_QWORD *)param0 + 33);
  v8 = (__m128)*((unsigned int *)param0 + 16);
  v9 = v8;
  v9.m128_f32[0] = (float)((float)(v8.m128_f32[0] * v8.m128_f32[0])
                         + (float)(*((float *)param0 + 17) * *((float *)param0 + 17)))
                 + (float)(*((float *)param0 + 18) * *((float *)param0 + 18));
  v10 = (float)((float)(COERCE_FLOAT(_mm_sqrt_ps(v9)) - 1.0) * v7->mUseTransformScaling) + 1.0;
  v11 = *((float *)param0 + 20);
  v12 = (__m128)*((unsigned int *)param0 + 21);
  v13 = *((float *)param0 + 28);
  v46 = *((float *)param0 + 29);
  v14 = *((float *)param0 + 30);
  v33 = v14;
  v15 = *((float *)param0 + 31);
  curBasisNormalized.v3.x = v13;
  curBasisNormalized.v3.y = v46;
  curBasisNormalized.v3.z = v14;
  curBasisNormalized.v3.w = v15;
  v16 = (__m128)*((unsigned int *)param0 + 17);
  v16.m128_f32[0] = (float)((float)(v16.m128_f32[0] * v16.m128_f32[0]) + (float)(v8.m128_f32[0] * v8.m128_f32[0]))
                  + (float)(*((float *)param0 + 18) * *((float *)param0 + 18));
  if ( v16.m128_f32[0] == 0.0 )
    v17 = 0.0;
  else
    v17 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v16));
  v18 = v17 * *((float *)param0 + 18);
  v19 = v17 * *((float *)param0 + 17);
  curBasisNormalized.v0.x = v17 * v8.m128_f32[0];
  curBasisNormalized.v0.y = v19;
  curBasisNormalized.v0.z = v18;
  curBasisNormalized.v0.w = 0.0;
  v20 = v12;
  v20.m128_f32[0] = (float)((float)(v12.m128_f32[0] * v12.m128_f32[0]) + (float)(v11 * v11))
                  + (float)(*((float *)param0 + 22) * *((float *)param0 + 22));
  if ( v20.m128_f32[0] == 0.0 )
    v21 = 0.0;
  else
    v21 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v20));
  v22 = v21 * *((float *)param0 + 22);
  curBasisNormalized.v1.x = v21 * v11;
  curBasisNormalized.v1.y = v21 * v12.m128_f32[0];
  curBasisNormalized.v1.z = v22;
  curBasisNormalized.v1.w = 0.0;
  v23 = (__m128)*((unsigned int *)param0 + 25);
  v23.m128_f32[0] = (float)((float)(v23.m128_f32[0] * v23.m128_f32[0])
                          + (float)(*((float *)param0 + 24) * *((float *)param0 + 24)))
                  + (float)(*((float *)param0 + 26) * *((float *)param0 + 26));
  if ( v23.m128_f32[0] == 0.0 )
    v24 = 0.0;
  else
    v24 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v23));
  v25 = v24 * *((float *)param0 + 26);
  v26 = v24 * *((float *)param0 + 25);
  curBasisNormalized.v2.x = v24 * *((float *)param0 + 24);
  curBasisNormalized.v2.y = v26;
  curBasisNormalized.v2.z = v25;
  curBasisNormalized.v2.w = 0.0;
  v27 = 84 * *((_DWORD *)param0 + 137);
  v28 = (void *)*((_QWORD *)param0 + 30);
  stream_name = "Input EmitterParticleAttribute";
  main_mem = v28;
  v42 = 0;
  v43 = (Render::EmitterParticleAttribute *)((unsigned __int64)&v44 & 0xFFFFFFFFFFFFFF80ui64);
  main_mem = (void *)*((_QWORD *)param0 + 30);
  UFG::qMemoryStreamer::BeginRawReadPlat(
    memory_streamer,
    "Input EmitterParticleAttribute",
    (void *)((unsigned __int64)&v44 & 0xFFFFFFFFFFFFFF80ui64),
    0xA80ui64,
    main_mem,
    v27);
  *v4 = *((_DWORD *)v5 + 143);
  v29 = *((_DWORD *)v5 + 136);
  currentBufferCount = *((_DWORD *)v5 + 136);
  `eh vector constructor iterator(
    &ptr,
    0x18ui64,
    50,
    (void (__fastcall *)(void *))UFG::qMemoryStream<UFG::AIInterestComponent,432>::qMemoryStream<UFG::AIInterestComponent,432>);
  v39 = 0;
  if ( v7->mSettings.LightInfo[1] > 0.0 )
  {
    effectPosition.x = v13;
    effectPosition.y = v46;
    effectPosition.z = v33;
    Render::ParticleLighting::ReadLightsFromMainMemory(
      (Render::ParticleLighting *)&ptr,
      &effectPosition,
      (Render::FXManagerLights *)v5 + 25,
      v6);
  }
  Render::UpdateExistingParticles(
    &taskParams,
    v7,
    &curBasisNormalized,
    v29,
    (Render::ParticleLighting *)&ptr,
    v10,
    (Render::EmitterParticleAttribute *)((unsigned __int64)&v44 & 0xFFFFFFFFFFFFFF80ui64),
    v6);
  Render::GenerateNewParticles(&taskParams, v7, (Render::ParticleLighting *)&ptr, &curBasisNormalized);
  v30 = currentBufferCount;
  v4[1] = currentBufferCount;
  main_num_bytes = 84 * v30;
  UFG::qMemoryStreamer::BeginRawWritePlat(v6, stream_name, v43, 0xA80ui64, *((void **)v5 + 30), main_num_bytes);
  v32 = (void *)*((_QWORD *)v5 + 31);
  if ( v32 )
    UFG::qMemoryStreamer::BeginRawWritePlat(v6, stream_name, v43, 0xA80ui64, v32, main_num_bytes);
  `eh vector destructor iterator(&ptr, 0x18ui64, 50, (void (__fastcall *)(void *))_);
}

