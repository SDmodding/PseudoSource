// File Line: 17
// RVA: 0x146B040
__int64 Render::_dynamic_initializer_for__gBeamManager__()
{
  hkSeekableStreamReader *v0; // rbx
  int i; // edi

  UFG::qResourceHandle::qResourceHandle(&Render::gBeamManager.mBeamMat);
  v0 = &stru_142362608;
  for ( i = 31; i >= 0; --i )
  {
    Assembly::GetRCX(v0);
    v0 = (hkSeekableStreamReader *)((char *)v0 + 56);
  }
  unk_142362600 = 0;
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gBeamManager__);
}

// File Line: 29
// RVA: 0x1CD4D0
void __fastcall Render::BeamManager::Init(Render::BeamManager *this)
{
  _WORD *v2; // rsi
  unsigned int v3; // r14d
  Illusion::Material *v4; // rdi
  int v5; // eax
  int v6; // ebx
  int v7; // eax
  int v8; // eax
  unsigned int v9; // eax
  int v10; // eax
  UFG::qResourceWarehouse *v11; // rax
  __int64 mOffset; // rax
  _WORD *v13; // rax
  __int64 v14; // rax
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v16; // rax
  CB_BeamSettings **p_settings; // rbx
  __int64 v18; // rdi

  v2 = 0i64;
  this->mLastUpdateSimFrame = UFG::Metrics::msInstance.mSimFrameCount;
  this->mAnimCounter = 0;
  this->mBeamSettingsStateIndex = (unsigned __int16)Illusion::StateSystem::AddParam(
                                                      &Illusion::gStateSystem,
                                                      "cbBeamSettings",
                                                      0);
  v3 = UFG::qStringHashUpper32("BeamManager.BeamMat", -1);
  v4 = Illusion::Factory::NewMaterial("BeamManager.BeamMat", v3, 4u, 0i64, 0i64, 0i64);
  v5 = UFG::qStringHash32("BEAM", 0xFFFFFFFF);
  LOWORD(v4[1].mNode.mChild[0]) = 0;
  v6 = v5;
  HIDWORD(v4[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v7 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v4[1].mTypeUID = -1957338719;
  LODWORD(v4[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = v6;
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
  LODWORD(v4[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 1002903008;
  v4[2].mNode.mUID = 1099738947;
  v4[1].mNumParams = v9;
  LOWORD(v4[2].mTypeUID) = 0;
  HIDWORD(v4[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v10 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  *((_DWORD *)&v4[2].UFG::qResourceData + 22) = 315097330;
  LODWORD(v4[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = v10;
  *(_DWORD *)&v4[2].mDebugName[28] = -89056095;
  v11 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v11, v4);
  if ( v4[2].mNode.mUID != 0x418CAF43 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v4[2],
      (unsigned int)v4[2].mResourceHandles.UFG::qResourceData::mNode.mPrev,
      0x418CAF43u);
    mOffset = v4->mMaterialUser.mOffset;
    if ( mOffset )
      v13 = (_WORD *)((char *)&v4->mMaterialUser + mOffset);
    else
      v13 = 0i64;
    *v13 |= 0x20u;
  }
  if ( *(_DWORD *)&v4[2].mDebugName[28] != -89056095 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v4[2].mDebugName[4],
      *((_DWORD *)&v4[2].UFG::qResourceData + 22),
      0xFAB11CA1);
    v14 = v4->mMaterialUser.mOffset;
    if ( v14 )
      v2 = (_WORD *)((char *)&v4->mMaterialUser + v14);
    *v2 |= 0x20u;
  }
  Inventory = `UFG::qGetResourceInventory<Illusion::Material>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Material>::`2::result )
  {
    v16 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v16, 0xB4C26312);
    `UFG::qGetResourceInventory<Illusion::Material>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(&this->mBeamMat, 0xB4C26312, v3, Inventory);
  p_settings = &this->mBeams[0].settings;
  v18 = 32i64;
  do
  {
    p_settings += 7;
    *(p_settings - 7) = (CB_BeamSettings *)UFG::qMalloc(0x20ui64, "BeamSettings", 0x1000ui64);
    --v18;
  }
  while ( v18 );
}

// File Line: 84
// RVA: 0x1D2B00
void __fastcall Render::BeamManager::Render(Render::BeamManager *this, Render::View *view, float fTime)
{
  bool v3; // zf
  unsigned int v6; // r14d
  float v7; // xmm0_4
  float v8; // xmm12_4
  __int64 v9; // rsi
  float v10; // xmm5_4
  __m128 y_low; // xmm13
  __m128 x_low; // xmm7
  __m128 v13; // xmm2
  __m128 v14; // xmm8
  float v15; // xmm14_4
  __m128 z_low; // xmm9
  float v17; // xmm15_4
  float v18; // xmm3_4
  float v19; // xmm11_4
  __m128 v20; // xmm12
  float v21; // xmm4_4
  __m128 v22; // xmm2
  float v23; // xmm2_4
  float v24; // xmm11_4
  float v25; // xmm12_4
  float v26; // xmm2_4
  float v27; // xmm11_4
  __m128 v28; // xmm3
  float v29; // xmm1_4
  float v30; // xmm8_4
  __m128 v31; // xmm4
  __m128 v32; // xmm3
  float v33; // xmm5_4
  __m128 v34; // xmm2
  float v35; // xmm1_4
  float v36; // xmm3_4
  float v37; // xmm5_4
  float width; // xmm11_4
  float v39; // xmm11_4
  float v40; // xmm3_4
  __m128 v41; // xmm12
  __m128 v42; // xmm2
  float v43; // xmm2_4
  UFG::qResourceData *mData; // rdi
  unsigned int texID; // r8d
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rax
  UFG::qResourceData *v47; // rdi
  unsigned int mNext_high; // r8d
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v49; // rax
  char *v50; // rax
  CB_BeamSettings *settings; // rdx
  char *v52; // rdi
  unsigned int mBeamSettingsStateIndex_low; // esi
  Illusion::StateValues *StateValues; // rax
  unsigned int mSimFrameCount; // eax
  float v56; // [rsp+30h] [rbp-B8h]
  __int64 v57; // [rsp+34h] [rbp-B4h]
  Render::Poly poly; // [rsp+40h] [rbp-A8h] BYREF
  UFG::qMatrix44 local_world; // [rsp+50h] [rbp-98h] BYREF
  float x; // [rsp+148h] [rbp+60h]
  float y; // [rsp+150h] [rbp+68h]
  float z; // [rsp+160h] [rbp+78h]

  v3 = this->mBeamMat.mData == 0i64;
  x = view->mViewWorld.v3.x;
  y = view->mViewWorld.v3.y;
  z = view->mViewWorld.v3.z;
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
        v10 = this->mBeams[v9].p0.x;
        y_low = (__m128)LODWORD(this->mBeams[v9].p0.y);
        x_low = (__m128)LODWORD(this->mBeams[v9].p1.x);
        v13 = y_low;
        v14 = (__m128)LODWORD(this->mBeams[v9].p1.y);
        v15 = this->mBeams[v9].p0.z;
        z_low = (__m128)LODWORD(this->mBeams[v9].p1.z);
        v17 = (float)(v10 + x_low.m128_f32[0]) * v8;
        v13.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - v14.m128_f32[0])
                                        * (float)(y_low.m128_f32[0] - v14.m128_f32[0]))
                                + (float)((float)(v10 - x_low.m128_f32[0]) * (float)(v10 - x_low.m128_f32[0])))
                        + (float)((float)(v15 - z_low.m128_f32[0]) * (float)(v15 - z_low.m128_f32[0]));
        v18 = y - (float)((float)(this->mBeams[v9].p0.y + v14.m128_f32[0]) * v8);
        *(float *)&v57 = (float)(this->mBeams[v9].p0.y + v14.m128_f32[0]) * v8;
        local_world.v0 = UFG::qMatrix44::msIdentity.v0;
        *(_QWORD *)&local_world.v2.z = *(_QWORD *)&UFG::qMatrix44::msIdentity.v2.z;
        v19 = (float)(v15 + z_low.m128_f32[0]) * v8;
        v20 = (__m128)LODWORD(x);
        LODWORD(v56) = _mm_sqrt_ps(v13).m128_u32[0];
        *(_QWORD *)&local_world.v1.x = *(_QWORD *)&UFG::qMatrix44::msIdentity.v1.x;
        v20.m128_f32[0] = x - v17;
        v21 = z - v19;
        v22 = v20;
        *(UFG::qVector4 *)&local_world.v1.z = UFG::qMatrix44::msIdentity.v3;
        *((float *)&v57 + 1) = v19;
        v22.m128_f32[0] = (float)((float)(v20.m128_f32[0] * v20.m128_f32[0]) + (float)(v18 * v18)) + (float)(v21 * v21);
        if ( v22.m128_f32[0] == 0.0 )
          v23 = 0.0;
        else
          v23 = 1.0 / _mm_sqrt_ps(v22).m128_f32[0];
        x_low.m128_f32[0] = x_low.m128_f32[0] - v10;
        v14.m128_f32[0] = v14.m128_f32[0] - y_low.m128_f32[0];
        v24 = v23;
        v25 = v20.m128_f32[0] * v23;
        v26 = v23 * v21;
        z_low.m128_f32[0] = z_low.m128_f32[0] - v15;
        v27 = v24 * v18;
        v28 = v14;
        v28.m128_f32[0] = (float)((float)(v14.m128_f32[0] * v14.m128_f32[0])
                                + (float)(x_low.m128_f32[0] * x_low.m128_f32[0]))
                        + (float)(z_low.m128_f32[0] * z_low.m128_f32[0]);
        if ( v28.m128_f32[0] == 0.0 )
          v29 = 0.0;
        else
          v29 = 1.0 / _mm_sqrt_ps(v28).m128_f32[0];
        v30 = v14.m128_f32[0] * v29;
        z_low.m128_f32[0] = z_low.m128_f32[0] * v29;
        x_low.m128_f32[0] = x_low.m128_f32[0] * v29;
        v31 = z_low;
        v32 = x_low;
        v31.m128_f32[0] = (float)(z_low.m128_f32[0] * v27) - (float)(v30 * v26);
        v32.m128_f32[0] = (float)(x_low.m128_f32[0] * v26) - (float)(z_low.m128_f32[0] * v25);
        v34 = v32;
        v33 = (float)(v30 * v25) - (float)(x_low.m128_f32[0] * v27);
        v34.m128_f32[0] = (float)((float)(v32.m128_f32[0] * v32.m128_f32[0]) + (float)(v31.m128_f32[0] * v31.m128_f32[0]))
                        + (float)(v33 * v33);
        if ( v34.m128_f32[0] == 0.0 )
          v35 = 0.0;
        else
          v35 = 1.0 / _mm_sqrt_ps(v34).m128_f32[0];
        v31.m128_f32[0] = v31.m128_f32[0] * v35;
        v36 = v32.m128_f32[0] * v35;
        local_world.v0.w = 0.0;
        local_world.v1.w = 0.0;
        v41 = v31;
        v37 = v33 * v35;
        local_world.v0.z = z_low.m128_f32[0] * v56;
        local_world.v0.x = x_low.m128_f32[0] * v56;
        width = this->mBeams[v9].width;
        local_world.v0.y = v30 * v56;
        local_world.v1.z = v37 * width;
        local_world.v1.x = v31.m128_f32[0] * width;
        local_world.v1.y = v36 * width;
        v39 = (float)(v37 * v30) - (float)(v36 * z_low.m128_f32[0]);
        v40 = (float)(v36 * x_low.m128_f32[0]) - (float)(v31.m128_f32[0] * v30);
        v41.m128_f32[0] = (float)(v31.m128_f32[0] * z_low.m128_f32[0]) - (float)(v37 * x_low.m128_f32[0]);
        v42 = v41;
        v42.m128_f32[0] = (float)((float)(v41.m128_f32[0] * v41.m128_f32[0]) + (float)(v39 * v39)) + (float)(v40 * v40);
        if ( v42.m128_f32[0] == 0.0 )
          v43 = 0.0;
        else
          v43 = 1.0 / _mm_sqrt_ps(v42).m128_f32[0];
        mData = this->mBeamMat.mData;
        texID = this->mBeams[v9].texID;
        local_world.v1.z = v17;
        local_world.v2.w = 0.0;
        local_world.v2.z = v43 * v40;
        local_world.v2.y = v43 * v41.m128_f32[0];
        *(_QWORD *)&local_world.v1.w = v57;
        if ( mData[2].mTypeUID != texID )
        {
          UFG::qResourceHandle::Init(
            (UFG::qResourceHandle *)&mData[2].mNode.mUID,
            *(_DWORD *)&mData[2].mDebugName[4],
            texID);
          mPrev = mData[1].mResourceHandles.mNode.mPrev;
          if ( mPrev )
            mPrev = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)((char *)mPrev + (_QWORD)mData + 120);
          LOWORD(mPrev->mPrev) |= 0x20u;
        }
        this->mBeams[v9].settings->AnimUVScaleOffset[2] = (float)(this->mAnimCounter + this->mBeams[v9].textureAnimStart);
        v47 = this->mBeamMat.mData;
        mNext_high = HIDWORD(v47[2].mResourceHandles.mNode.mNext[6].mNext);
        if ( *(_DWORD *)&v47[3].mDebugName[20] != mNext_high )
        {
          UFG::qResourceHandle::Init(
            (UFG::qResourceHandle *)&v47[3].mTypeUID,
            *(_DWORD *)&v47[3].mDebugName[28],
            mNext_high);
          v49 = v47[1].mResourceHandles.mNode.mPrev;
          if ( v49 )
            v49 = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)((char *)v49 + (_QWORD)v47 + 120);
          LOWORD(v49->mPrev) |= 0x20u;
        }
        this->mBeams[v9].settings->AnimUVScaleOffset[3] = this->mBeams[v9].age / this->mBeams[v9].lifeTime;
        v50 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x20u, 0x10u);
        settings = this->mBeams[v9].settings;
        v52 = v50;
        *(float *)v50 = settings->Colour[0];
        *((_DWORD *)v50 + 1) = LODWORD(settings->Colour[1]);
        *((_DWORD *)v50 + 2) = LODWORD(settings->Colour[2]);
        *((_DWORD *)v50 + 3) = LODWORD(settings->Colour[3]);
        *((_DWORD *)v50 + 4) = LODWORD(settings->AnimUVScaleOffset[0]);
        *((_DWORD *)v50 + 5) = LODWORD(settings->AnimUVScaleOffset[1]);
        *((_DWORD *)v50 + 6) = LODWORD(settings->AnimUVScaleOffset[2]);
        *((_DWORD *)v50 + 7) = LODWORD(settings->AnimUVScaleOffset[3]);
        mBeamSettingsStateIndex_low = SLOWORD(this->mBeamSettingsStateIndex);
        StateValues = Render::View::GetStateValues(view);
        if ( mBeamSettingsStateIndex_low >= 64 )
          StateValues->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)mBeamSettingsStateIndex_low - 64);
        else
          StateValues->mSetValueMask.mFlags[0] |= 1i64 << mBeamSettingsStateIndex_low;
        StateValues->mParamValues[(__int16)mBeamSettingsStateIndex_low] = v52;
        Render::View::Draw(view, &poly, (Illusion::Material *)this->mBeamMat.mData, &local_world);
        ++v6;
        v8 = FLOAT_0_5;
        v7 = FLOAT_N0_5;
      }
      while ( v6 < this->mNumBeams );
    }
    ++this->mAnimCounter;
    mSimFrameCount = UFG::Metrics::msInstance.mSimFrameCount;
    if ( !UFG::Metrics::msInstance.mSimPausedInGame && !UFG::Metrics::msInstance.mSimPausedDebug )
      this->mNumBeams = 0;
    this->mLastUpdateSimFrame = mSimFrameCount;
  }
}

// File Line: 153
// RVA: 0x1C6A00
void __fastcall Render::BeamManager::AddBeam(
        Render::BeamManager *this,
        Render::BeamManager::AddBeamParameters *beamParameters)
{
  unsigned int mSimFrameCount; // eax
  float y; // xmm0_4
  float z; // xmm1_4
  __int64 mNumBeams; // rcx
  float v8; // xmm0_4
  float v9; // xmm1_4
  __int64 v10; // rcx

  if ( this->mNumBeams != 32 )
  {
    if ( UFG::Metrics::msInstance.mSimPausedInGame || UFG::Metrics::msInstance.mSimPausedDebug )
    {
      mSimFrameCount = UFG::Metrics::msInstance.mSimFrameCount;
      if ( UFG::Metrics::msInstance.mSimFrameCount > this->mLastUpdateSimFrame )
      {
        this->mNumBeams = 0;
        this->mLastUpdateSimFrame = mSimFrameCount;
      }
    }
    y = beamParameters->startPoint.y;
    z = beamParameters->startPoint.z;
    mNumBeams = this->mNumBeams;
    this->mBeams[mNumBeams].p0.x = beamParameters->startPoint.x;
    this->mBeams[mNumBeams].p0.y = y;
    this->mBeams[mNumBeams].p0.z = z;
    v8 = beamParameters->endPoint.y;
    v9 = beamParameters->endPoint.z;
    v10 = this->mNumBeams;
    this->mBeams[v10].p1.x = beamParameters->endPoint.x;
    this->mBeams[v10].p1.y = v8;
    this->mBeams[v10].p1.z = v9;
    this->mBeams[this->mNumBeams].width = beamParameters->width;
    this->mBeams[this->mNumBeams].texID = beamParameters->beamSettings->mTextureUID;
    *(UFG::qVector4 *)this->mBeams[this->mNumBeams].settings->Colour = beamParameters->beamSettings->minColour;
    *(UFG::qVector2 *)this->mBeams[this->mNumBeams].settings->AnimUVScaleOffset = beamParameters->beamSettings->numAnimPages;
    this->mBeams[this->mNumBeams].textureAnimStart = UFG::qRandom(
                                                       (int)(float)(beamParameters->beamSettings->numAnimPages.y
                                                                  * beamParameters->beamSettings->numAnimPages.x),
                                                       (unsigned int *)&UFG::qDefaultSeed);
    this->mBeams[this->mNumBeams].lifeTime = beamParameters->beamSettings->mLifeTime;
    this->mBeams[this->mNumBeams++].age = beamParameters->age;
  }
}

