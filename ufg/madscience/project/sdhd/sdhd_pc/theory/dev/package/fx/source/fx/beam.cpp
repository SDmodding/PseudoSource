// File Line: 17
// RVA: 0x146B040
__int64 Render::_dynamic_initializer_for__gBeamManager__()
{
  hkSeekableStreamReader *v0; // rbx
  signed int v1; // edi

  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&Render::gBeamManager.mBeamMat.mPrev);
  v0 = &stru_142362608;
  v1 = 31;
  do
  {
    Assembly::GetRCX(v0);
    v0 = (hkSeekableStreamReader *)((char *)v0 + 56);
    --v1;
  }
  while ( v1 >= 0 );
  unk_142362600 = 0;
  return atexit(Render::_dynamic_atexit_destructor_for__gBeamManager__);
}

// File Line: 29
// RVA: 0x1CD4D0
void __fastcall Render::BeamManager::Init(Render::BeamManager *this)
{
  Render::BeamManager *v1; // rbp
  _WORD *v2; // rsi
  unsigned int v3; // er14
  Illusion::Material *v4; // rdi
  int v5; // eax
  int v6; // ebx
  int v7; // eax
  int v8; // eax
  unsigned int v9; // eax
  int v10; // eax
  UFG::qResourceWarehouse *v11; // rax
  __int64 v12; // rax
  _WORD *v13; // rax
  __int64 v14; // rax
  UFG::qResourceInventory *v15; // rax
  UFG::qResourceWarehouse *v16; // rax
  signed __int64 v17; // rbx
  signed __int64 v18; // rdi

  v1 = this;
  v2 = 0i64;
  this->mLastUpdateSimFrame = UFG::Metrics::msInstance.mSimFrameCount;
  this->mAnimCounter = 0;
  this->mBeamSettingsStateIndex = (unsigned __int16)Illusion::StateSystem::AddParam(
                                                      &Illusion::gStateSystem,
                                                      "cbBeamSettings",
                                                      0);
  v3 = UFG::qStringHashUpper32("BeamManager.BeamMat", 0xFFFFFFFF);
  v4 = Illusion::Factory::NewMaterial("BeamManager.BeamMat", v3, 4u, 0i64, 0i64, 0i64);
  v5 = UFG::qStringHash32("BEAM", 0xFFFFFFFF);
  LOWORD(v4[1].mNode.mChild[0]) = 0;
  v6 = v5;
  HIDWORD(v4[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v7 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v4[1].mTypeUID = -1957338719;
  LODWORD(v4[1].mResourceHandles.mNode.mNext) = v6;
  LODWORD(v4[1].mNode.mParent) = v7;
  *(_WORD *)&v4[1].mDebugName[12] = 0;
  *(_DWORD *)&v4[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v8 = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v4[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v4[1].mStateBlockMask.mFlags[0]) = 0;
  *(_DWORD *)&v4[1].mDebugName[4] = v8;
  LOWORD(v4[1].mMaterialUser.mOffset) = 0;
  *(&v4[1].mNumParams + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v9 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v4[2].mResourceHandles.mNode.mPrev) = 1002903008;
  v4[2].mNode.mUID = 1099738947;
  v4[1].mNumParams = v9;
  LOWORD(v4[2].mTypeUID) = 0;
  HIDWORD(v4[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v10 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  *((_DWORD *)&v4[2].0 + 22) = 315097330;
  LODWORD(v4[2].mResourceHandles.mNode.mNext) = v10;
  *(_DWORD *)&v4[2].mDebugName[28] = -89056095;
  v11 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v11, (UFG::qResourceData *)&v4->mNode);
  if ( v4[2].mNode.mUID != 0x418CAF43 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v4[2],
      (unsigned int)v4[2].mResourceHandles.mNode.mPrev,
      0x418CAF43u);
    v12 = v4->mMaterialUser.mOffset;
    if ( v12 )
      v13 = (_WORD *)((char *)&v4->mMaterialUser + v12);
    else
      v13 = 0i64;
    *v13 |= 0x20u;
  }
  if ( *(_DWORD *)&v4[2].mDebugName[28] != -89056095 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v4[2].mDebugName[4], *((_DWORD *)&v4[2].0 + 22), 0xFAB11CA1);
    v14 = v4->mMaterialUser.mOffset;
    if ( v14 )
      v2 = (_WORD *)((char *)&v4->mMaterialUser + v14);
    *v2 |= 0x20u;
  }
  v15 = `UFG::qGetResourceInventory<Illusion::Material>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Material>::`2::result )
  {
    v16 = UFG::qResourceWarehouse::Instance();
    v15 = UFG::qResourceWarehouse::GetInventory(v16, 0xB4C26312);
    `UFG::qGetResourceInventory<Illusion::Material>::`2::result = v15;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v1->mBeamMat.mPrev, 0xB4C26312, v3, v15);
  v17 = (signed __int64)&v1->mBeams[0].settings;
  v18 = 32i64;
  do
  {
    v17 += 56i64;
    *(_QWORD *)(v17 - 56) = UFG::qMalloc(0x20ui64, "BeamSettings", 0x1000ui64);
    --v18;
  }
  while ( v18 );
}

// File Line: 84
// RVA: 0x1D2B00
void __fastcall Render::BeamManager::Render(Render::BeamManager *this, Render::View *view, float fTime)
{
  bool v3; // zf
  Render::View *v4; // r15
  Render::BeamManager *v5; // rbx
  unsigned int v6; // er14
  float v7; // xmm0_4
  float v8; // xmm12_4
  signed __int64 v9; // rsi
  float v10; // xmm5_4
  __m128 v11; // xmm13
  __m128 v12; // xmm7
  __m128 v13; // xmm2
  __m128 v14; // xmm8
  float v15; // xmm14_4
  __m128 v16; // xmm9
  float v17; // xmm11_4
  float v18; // xmm15_4
  float v19; // xmm3_4
  float v20; // xmm11_4
  __m128 v21; // xmm12
  float v22; // xmm4_4
  __m128 v23; // xmm2
  float v24; // xmm2_4
  float v25; // xmm11_4
  float v26; // xmm12_4
  float v27; // xmm2_4
  float v28; // xmm11_4
  __m128 v29; // xmm3
  float v30; // xmm1_4
  float v31; // xmm8_4
  __m128 v32; // xmm4
  __m128 v33; // xmm3
  float v34; // xmm5_4
  __m128 v35; // xmm2
  float v36; // xmm1_4
  float v37; // xmm3_4
  float v38; // xmm5_4
  float v39; // xmm11_4
  float v40; // xmm11_4
  float v41; // xmm3_4
  __m128 v42; // xmm12
  __m128 v43; // xmm2
  float v44; // xmm2_4
  UFG::qResourceData *v45; // rdi
  unsigned int v46; // er8
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v47; // rax
  UFG::qResourceData *v48; // rdi
  unsigned int v49; // er8
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v50; // rax
  char *v51; // rax
  _DWORD *v52; // rdx
  char *v53; // rdi
  unsigned int v54; // esi
  Illusion::StateValues *v55; // rax
  unsigned int v56; // eax
  float v57; // [rsp+30h] [rbp-B8h]
  __int64 v58; // [rsp+34h] [rbp-B4h]
  Render::Poly poly; // [rsp+40h] [rbp-A8h]
  UFG::qMatrix44 local_world; // [rsp+50h] [rbp-98h]
  float v61; // [rsp+148h] [rbp+60h]
  float vars0; // [rsp+150h] [rbp+68h]
  float v63; // [rsp+160h] [rbp+78h]

  v3 = this->mBeamMat.mData == 0i64;
  v4 = view;
  v61 = view->mViewWorld.v3.x;
  v5 = this;
  vars0 = view->mViewWorld.v3.y;
  v63 = view->mViewWorld.v3.z;
  if ( !v3 )
  {
    v6 = 0;
    if ( this->mNumBeams )
    {
      v7 = FLOAT_N0_5;
      v8 = FLOAT_0_5;
      do
      {
        Render::Poly::Poly(&poly, v7, v7, 1.0, 1.0, 0.0);
        v9 = v6;
        v10 = v5->mBeams[v9].p0.x;
        v11 = (__m128)LODWORD(v5->mBeams[v9].p0.y);
        v12 = (__m128)LODWORD(v5->mBeams[v9].p1.x);
        v13 = v11;
        v14 = (__m128)LODWORD(v5->mBeams[v9].p1.y);
        v15 = v5->mBeams[v9].p0.z;
        v16 = (__m128)LODWORD(v5->mBeams[v9].p1.z);
        v17 = v5->mBeams[v9].p0.z;
        v18 = (float)(v5->mBeams[v9].p0.x + v12.m128_f32[0]) * v8;
        v13.m128_f32[0] = (float)((float)((float)(v11.m128_f32[0] - v14.m128_f32[0])
                                        * (float)(v11.m128_f32[0] - v14.m128_f32[0]))
                                + (float)((float)(v5->mBeams[v9].p0.x - v12.m128_f32[0])
                                        * (float)(v5->mBeams[v9].p0.x - v12.m128_f32[0])))
                        + (float)((float)(v5->mBeams[v9].p0.z - v16.m128_f32[0])
                                * (float)(v5->mBeams[v9].p0.z - v16.m128_f32[0]));
        v19 = vars0 - (float)((float)(v5->mBeams[v9].p0.y + v14.m128_f32[0]) * v8);
        *(float *)&v58 = (float)(v5->mBeams[v9].p0.y + v14.m128_f32[0]) * v8;
        local_world.v0 = UFG::qMatrix44::msIdentity.v0;
        local_world.v2 = UFG::qMatrix44::msIdentity.v2;
        v20 = (float)(v17 + v16.m128_f32[0]) * v8;
        v21 = (__m128)LODWORD(v61);
        LODWORD(v57) = (unsigned __int128)_mm_sqrt_ps(v13);
        local_world.v1 = UFG::qMatrix44::msIdentity.v1;
        v21.m128_f32[0] = v61 - v18;
        v22 = v63 - v20;
        v23 = v21;
        *(UFG::qVector4 *)&local_world.v1.z = UFG::qMatrix44::msIdentity.v3;
        *((float *)&v58 + 1) = v20;
        v23.m128_f32[0] = (float)((float)(v21.m128_f32[0] * v21.m128_f32[0]) + (float)(v19 * v19)) + (float)(v22 * v22);
        if ( v23.m128_f32[0] == 0.0 )
          v24 = 0.0;
        else
          v24 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v23));
        v12.m128_f32[0] = v12.m128_f32[0] - v10;
        v14.m128_f32[0] = v14.m128_f32[0] - v11.m128_f32[0];
        v25 = v24;
        v26 = v21.m128_f32[0] * v24;
        v27 = v24 * v22;
        v16.m128_f32[0] = v16.m128_f32[0] - v15;
        v28 = v25 * v19;
        v29 = v14;
        v29.m128_f32[0] = (float)((float)(v14.m128_f32[0] * v14.m128_f32[0]) + (float)(v12.m128_f32[0] * v12.m128_f32[0]))
                        + (float)(v16.m128_f32[0] * v16.m128_f32[0]);
        if ( v29.m128_f32[0] == 0.0 )
          v30 = 0.0;
        else
          v30 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v29));
        v31 = v14.m128_f32[0] * v30;
        v16.m128_f32[0] = v16.m128_f32[0] * v30;
        v12.m128_f32[0] = v12.m128_f32[0] * v30;
        v32 = v16;
        v33 = v12;
        v32.m128_f32[0] = (float)(v16.m128_f32[0] * v28) - (float)(v31 * v27);
        v33.m128_f32[0] = (float)(v12.m128_f32[0] * v27) - (float)(v16.m128_f32[0] * v26);
        v35 = v33;
        v34 = (float)(v31 * v26) - (float)(v12.m128_f32[0] * v28);
        v35.m128_f32[0] = (float)((float)(v33.m128_f32[0] * v33.m128_f32[0]) + (float)(v32.m128_f32[0] * v32.m128_f32[0]))
                        + (float)(v34 * v34);
        if ( v35.m128_f32[0] == 0.0 )
          v36 = 0.0;
        else
          v36 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v35));
        v32.m128_f32[0] = v32.m128_f32[0] * v36;
        v37 = v33.m128_f32[0] * v36;
        local_world.v0.w = 0.0;
        local_world.v1.w = 0.0;
        v42 = v32;
        v38 = v34 * v36;
        local_world.v0.z = v16.m128_f32[0] * v57;
        local_world.v0.x = v12.m128_f32[0] * v57;
        v39 = v5->mBeams[v9].width;
        local_world.v0.y = v31 * v57;
        local_world.v1.z = v38 * v39;
        local_world.v1.x = v32.m128_f32[0] * v39;
        local_world.v1.y = v37 * v39;
        v40 = (float)(v38 * v31) - (float)(v37 * v16.m128_f32[0]);
        v41 = (float)(v37 * v12.m128_f32[0]) - (float)(v32.m128_f32[0] * v31);
        v42.m128_f32[0] = (float)(v32.m128_f32[0] * v16.m128_f32[0]) - (float)(v38 * v12.m128_f32[0]);
        v43 = v42;
        v43.m128_f32[0] = (float)((float)(v42.m128_f32[0] * v42.m128_f32[0]) + (float)(v40 * v40)) + (float)(v41 * v41);
        if ( v43.m128_f32[0] == 0.0 )
          v44 = 0.0;
        else
          v44 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v43));
        v45 = v5->mBeamMat.mData;
        v46 = v5->mBeams[v9].texID;
        local_world.v1.z = v18;
        local_world.v2.w = 0.0;
        local_world.v2.z = v44 * v41;
        local_world.v2.y = v44 * v42.m128_f32[0];
        *(_QWORD *)&local_world.v1.w = v58;
        if ( v45[2].mTypeUID != v46 )
        {
          UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v45[2].mNode.mUID, *(_DWORD *)&v45[2].mDebugName[4], v46);
          v47 = v45[1].mResourceHandles.mNode.mPrev;
          if ( v47 )
            v47 = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)((char *)v47 + (_QWORD)v45 + 120);
          LOWORD(v47->mPrev) |= 0x20u;
        }
        v5->mBeams[v9].settings->AnimUVScaleOffset[2] = (float)(v5->mAnimCounter + v5->mBeams[v9].textureAnimStart);
        v48 = v5->mBeamMat.mData;
        v49 = HIDWORD(v48[2].mResourceHandles.mNode.mNext[6].mNext);
        if ( *(_DWORD *)&v48[3].mDebugName[20] != v49 )
        {
          UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v48[3].mTypeUID, *(_DWORD *)&v48[3].mDebugName[28], v49);
          v50 = v48[1].mResourceHandles.mNode.mPrev;
          if ( v50 )
            v50 = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)((char *)v50 + (_QWORD)v48 + 120);
          LOWORD(v50->mPrev) |= 0x20u;
        }
        v5->mBeams[v9].settings->AnimUVScaleOffset[3] = v5->mBeams[v9].age / v5->mBeams[v9].lifeTime;
        v51 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x20u, 0x10u);
        v52 = (_DWORD *)v5->mBeams[v9].settings->Colour;
        v53 = v51;
        *(_DWORD *)v51 = *v52;
        *((_DWORD *)v51 + 1) = v52[1];
        *((_DWORD *)v51 + 2) = v52[2];
        *((_DWORD *)v51 + 3) = v52[3];
        *((_DWORD *)v51 + 4) = v52[4];
        *((_DWORD *)v51 + 5) = v52[5];
        *((_DWORD *)v51 + 6) = v52[6];
        *((_DWORD *)v51 + 7) = v52[7];
        v54 = SLOWORD(v5->mBeamSettingsStateIndex);
        v55 = Render::View::GetStateValues(v4);
        if ( v54 >= 64 )
          v55->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)v54 - 64);
        else
          v55->mSetValueMask.mFlags[0] |= 1i64 << v54;
        v55->mParamValues[(signed __int16)v54] = v53;
        Render::View::Draw(v4, &poly, (Illusion::Material *)v5->mBeamMat.mData, &local_world);
        ++v6;
        v8 = FLOAT_0_5;
        v7 = FLOAT_N0_5;
      }
      while ( v6 < v5->mNumBeams );
    }
    ++v5->mAnimCounter;
    v56 = UFG::Metrics::msInstance.mSimFrameCount;
    if ( !UFG::Metrics::msInstance.mSimPausedInGame && !UFG::Metrics::msInstance.mSimPausedDebug )
      v5->mNumBeams = 0;
    v5->mLastUpdateSimFrame = v56;
  }
}

// File Line: 153
// RVA: 0x1C6A00
void __fastcall Render::BeamManager::AddBeam(Render::BeamManager *this, Render::BeamManager::AddBeamParameters *beamParameters)
{
  Render::BeamManager::AddBeamParameters *v2; // rdi
  Render::BeamManager *v3; // rbx
  unsigned int v4; // eax
  float v5; // xmm0_4
  float v6; // xmm1_4
  signed __int64 v7; // rcx
  float v8; // xmm0_4
  float v9; // xmm1_4
  signed __int64 v10; // rcx

  v2 = beamParameters;
  v3 = this;
  if ( this->mNumBeams != 32 )
  {
    if ( UFG::Metrics::msInstance.mSimPausedInGame || UFG::Metrics::msInstance.mSimPausedDebug )
    {
      v4 = UFG::Metrics::msInstance.mSimFrameCount;
      if ( UFG::Metrics::msInstance.mSimFrameCount > this->mLastUpdateSimFrame )
      {
        this->mNumBeams = 0;
        this->mLastUpdateSimFrame = v4;
      }
    }
    v5 = beamParameters->startPoint.y;
    v6 = beamParameters->startPoint.z;
    v7 = this->mNumBeams;
    v3->mBeams[v7].p0.x = beamParameters->startPoint.x;
    v3->mBeams[v7].p0.y = v5;
    v3->mBeams[v7].p0.z = v6;
    v8 = beamParameters->endPoint.y;
    v9 = beamParameters->endPoint.z;
    v10 = v3->mNumBeams;
    v3->mBeams[v10].p1.x = beamParameters->endPoint.x;
    v3->mBeams[v10].p1.y = v8;
    v3->mBeams[v10].p1.z = v9;
    v3->mBeams[v3->mNumBeams].width = beamParameters->width;
    v3->mBeams[v3->mNumBeams].texID = beamParameters->beamSettings->mTextureUID;
    v3->mBeams[v3->mNumBeams].settings->Colour[0] = beamParameters->beamSettings->minColour.x;
    v3->mBeams[v3->mNumBeams].settings->Colour[1] = beamParameters->beamSettings->minColour.y;
    v3->mBeams[v3->mNumBeams].settings->Colour[2] = beamParameters->beamSettings->minColour.z;
    v3->mBeams[v3->mNumBeams].settings->Colour[3] = beamParameters->beamSettings->minColour.w;
    v3->mBeams[v3->mNumBeams].settings->AnimUVScaleOffset[0] = beamParameters->beamSettings->numAnimPages.x;
    v3->mBeams[v3->mNumBeams].settings->AnimUVScaleOffset[1] = beamParameters->beamSettings->numAnimPages.y;
    v3->mBeams[v3->mNumBeams].textureAnimStart = UFG::qRandom(
                                                   (signed int)(float)(beamParameters->beamSettings->numAnimPages.y
                                                                     * beamParameters->beamSettings->numAnimPages.x),
                                                   &UFG::qDefaultSeed);
    v3->mBeams[v3->mNumBeams].lifeTime = v2->beamSettings->mLifeTime;
    v3->mBeams[v3->mNumBeams++].age = v2->age;
  }
}

