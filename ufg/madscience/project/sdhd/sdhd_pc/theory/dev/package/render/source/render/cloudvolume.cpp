// File Line: 40
// RVA: 0x1457210
__int64 Render::_dynamic_initializer_for__gCloudVolumeManager__()
{
  UFG::qResourceHandle::qResourceHandle(&stru_142163818);
  UFG::qResourceHandle::qResourceHandle(&stru_142163838);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gCloudVolumeManager__);
}

// File Line: 445
// RVA: 0x70C30
void __fastcall Render::CloudVolumeManager::Init(Render::CloudVolumeManager *this, UFG::RenderContext *render_context)
{
  unsigned int v4; // eax
  Illusion::Material *v5; // rax
  Illusion::Material *v6; // rsi
  int v7; // eax
  unsigned int mUID; // ebx
  int v9; // eax
  unsigned int v10; // eax
  int v11; // eax
  unsigned int mVolumeTextureUID; // ebx
  int v13; // eax
  unsigned int v14; // ebx
  unsigned int v15; // eax
  int v16; // eax
  int v17; // ebx
  int v18; // eax
  UFG::qResourceWarehouse *v19; // rax
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v21; // rax
  UFG::qResourceInventory *v22; // rax
  UFG::qResourceWarehouse *v23; // rax
  float *mStormyStateValues; // rax
  __int64 v25; // rcx
  float z; // xmm2_4
  float w; // xmm3_4
  float x; // xmm0_4
  float y; // xmm1_4
  float v30; // xmm2_4
  float v31; // xmm3_4

  this->mVolumeTextureUID = UFG::qStringHashUpper32("cloudvolumetex", 0xFFFFFFFF);
  this->mOverrideIntensity = 1.0;
  v4 = UFG::qStringHashUpper32("CloudVolumeFogMat", 0xFFFFFFFF);
  v5 = Illusion::Factory::NewMaterial("CloudVolumeFogMat", v4, 7u, 0i64, 0i64, 0i64);
  LOWORD(v5[1].mNode.mChild[0]) = 0;
  v6 = v5;
  HIDWORD(v5[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v7 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v6[1].mTypeUID = -1957338719;
  LODWORD(v6[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = -1777167389;
  LODWORD(v6[1].mNode.mParent) = v7;
  mUID = render_context->mQuarterSizeLinearDepthTarget->mTargetTexture[0]->mNode.mUID;
  *(_WORD *)&v6[1].mDebugName[12] = 0;
  *(_DWORD *)&v6[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v9 = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
  LODWORD(v6[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v6[1].mStateBlockMask.mFlags[0]) = mUID;
  *(_DWORD *)&v6[1].mDebugName[4] = v9;
  LOWORD(v6[1].mMaterialUser.mOffset) = 0;
  *(&v6[1].mNumParams + 1) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v10 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v6[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 315097330;
  v6[2].mNode.mUID = -89056095;
  v6[1].mNumParams = v10;
  LOWORD(v6[2].mTypeUID) = 0;
  HIDWORD(v6[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v11 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *((_DWORD *)&v6[2].UFG::qResourceData + 22) = 1002903008;
  *(_DWORD *)&v6[2].mDebugName[28] = 1660426324;
  LODWORD(v6[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = v11;
  mVolumeTextureUID = this->mVolumeTextureUID;
  LOWORD(v6[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v6[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v13 = UFG::qStringHash32("texVolume0", 0xFFFFFFFF);
  LODWORD(v6[3].mNode.mChild[1]) = -1958479169;
  LODWORD(v6[2].mStateBlockMask.mFlags[0]) = v13;
  LODWORD(v6[3].mNode.mChild[0]) = mVolumeTextureUID;
  v14 = render_context->mQuarterSizeShadowAliasTexture->mNode.mUID;
  LOWORD(v6[3].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 0;
  *(&v6[3].mNode.mUID + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v15 = UFG::qStringHash32("texShadowAtlas", 0xFFFFFFFF);
  *(_DWORD *)&v6[3].mDebugName[20] = -1958479169;
  *(_DWORD *)&v6[3].mDebugName[12] = v14;
  v6[3].mNode.mUID = v15;
  v16 = UFG::qStringHashUpper32("SKY_Noise_001", 0xFFFFFFFF);
  *((_WORD *)&v6[3].UFG::qResourceData + 44) = 0;
  v17 = v16;
  *(_DWORD *)&v6[3].mDebugName[32] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v18 = UFG::qStringHash32("texNoise", 0xFFFFFFFF);
  LODWORD(v6[4].mNode.mParent) = -1958479169;
  *(_DWORD *)&v6[3].mDebugName[28] = v18;
  LODWORD(v6[3].mMaterialUser.mOffset) = v17;
  v19 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v19, v6);
  this->mMatCloudVolumeFog = v6;
  Inventory = `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result )
  {
    v21 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v21, 0x4D04C7F2u);
    `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(&this->mStateBlockSunny, 0x4D04C7F2u, 0xF1D36000, Inventory);
  v22 = `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result )
  {
    v23 = UFG::qResourceWarehouse::Instance();
    v22 = UFG::qResourceWarehouse::GetInventory(v23, 0x4D04C7F2u);
    `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result = v22;
  }
  UFG::qResourceHandle::Init(&this->mStateBlockStormy, 0x4D04C7F2u, 0x72CA2FF0u, v22);
  mStormyStateValues = this->mStormyStateValues;
  v25 = 19i64;
  do
  {
    *(mStormyStateValues - 19) = 1.0;
    *mStormyStateValues++ = 1.0;
    --v25;
  }
  while ( v25 );
  z = UFG::qVector4::msOne.z;
  w = UFG::qVector4::msOne.w;
  x = UFG::qVector4::msOne.x;
  this->mSunnyOpacityOverDist.y = UFG::qVector4::msOne.y;
  this->mSunnyOpacityOverDist.z = z;
  this->mSunnyOpacityOverDist.x = x;
  this->mSunnyOpacityOverDist.w = w;
  y = UFG::qVector4::msOne.y;
  v30 = UFG::qVector4::msOne.z;
  v31 = UFG::qVector4::msOne.w;
  this->mStormyOpacityOverDist.x = UFG::qVector4::msOne.x;
  this->mStormyOpacityOverDist.y = y;
  this->mStormyOpacityOverDist.z = v30;
  this->mStormyOpacityOverDist.w = v31;
}

// File Line: 544
// RVA: 0x72490
void __fastcall Render::CloudVolumeManager::Update(Render::CloudVolumeManager *this, float dt, UFG::qVector3 *cam_pos)
{
  unsigned int v3; // ebp
  UFG::TimeOfDayManager *Instance; // rax
  unsigned int VolumetricEffects; // eax
  float v8; // xmm6_4
  float v9; // xmm8_4
  UFG::qMatrix44 **v10; // r14
  __int64 v11; // r15
  UFG::qMatrix44 *v12; // rsi
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  float v16; // xmm5_4
  __m128 y_low; // xmm3
  float v18; // xmm9_4
  float v19; // xmm10_4
  float v20; // xmm4_4
  float v21; // xmm11_4
  float v22; // xmm0_4
  float v23; // xmm1_4
  float v24; // xmm1_4
  float v25; // xmm8_4
  UFG::qResourceData *mData; // rbx
  UFG::qResourceData *v27; // rdi
  float v28; // xmm4_4
  unsigned int i; // r9d
  __int64 v30; // r11
  char *v31; // rdx
  int v32; // r8d
  float *v33; // rcx
  __int64 v34; // r8
  float *v35; // rax
  float v36; // xmm3_4
  unsigned int v37; // edx
  __int64 v38; // rcx
  __int64 v39; // rdx
  __int64 v40; // r9
  float *v41; // rax
  float v42; // xmm3_4
  unsigned int v43; // r8d
  float *v44; // rdx
  __int64 v45; // r9
  float *v46; // rax
  float v47; // xmm3_4
  unsigned int v48; // r8d
  float *v49; // rdx
  __int64 v50; // r9
  float *v51; // rax
  float v52; // xmm3_4
  unsigned int v53; // r8d
  float *v54; // rdx
  __int64 v55; // r8
  float *v56; // rax
  float v57; // xmm3_4
  unsigned int v58; // ecx
  unsigned int j; // r9d
  __int64 v60; // r11
  char *v61; // rdx
  int v62; // r8d
  float *v63; // rcx
  __int64 v64; // r8
  float *v65; // rax
  float v66; // xmm3_4
  unsigned int v67; // edx
  __int64 v68; // rcx
  __int64 v69; // rdx
  __int64 v70; // r9
  float *v71; // rax
  float v72; // xmm3_4
  unsigned int v73; // r8d
  float *v74; // rdx
  __int64 v75; // r9
  float *v76; // rax
  float v77; // xmm8_4
  unsigned int v78; // r8d
  float *v79; // rdx
  __int64 v80; // r9
  float *v81; // rax
  float v82; // xmm5_4
  unsigned int v83; // r8d
  float *v84; // rdx
  __int64 v85; // r8
  float *v86; // rax
  UFG::qVector3 scale; // [rsp+30h] [rbp-10B8h] BYREF
  UFG::qVector3 target; // [rsp+40h] [rbp-10A8h] BYREF
  UFG::qVector4 dir; // [rsp+50h] [rbp-1098h] BYREF
  Render::VolumetricEffect *pBuffer[512]; // [rsp+60h] [rbp-1088h] BYREF

  v3 = 0;
  if ( s_globalCloudsEffectId == -1 || !Render::FXManager::FindEffect(&Render::gFXManager, s_globalCloudsEffectId) )
    s_globalCloudsEffectId = Render::FXManager::CreateEffect(
                               &Render::gFXManager,
                               0x3B46C728u,
                               &UFG::qMatrix44::msIdentity,
                               0xFFFFFFFF);
  if ( s_cameraAttachedAtmosphereEffectId == -1
    || !Render::FXManager::FindEffect(&Render::gFXManager, s_cameraAttachedAtmosphereEffectId) )
  {
    s_cameraAttachedAtmosphereEffectId = Render::FXManager::CreateEffect(
                                           &Render::gFXManager,
                                           0x9576C20F,
                                           &UFG::qMatrix44::msIdentity,
                                           0xFFFFFFFF);
  }
  Instance = UFG::TimeOfDayManager::GetInstance();
  UFG::TimeOfDayManager::GetSunDir(Instance, &dir, 0, 0);
  target.x = dir.x;
  *(_QWORD *)&target.y = *(_QWORD *)&dir.y;
  VolumetricEffects = Render::VolumetricEffectManager::GetVolumetricEffects(
                        &Render::gVolumetricEffectManager,
                        pBuffer,
                        0x200u);
  v8 = 0.0;
  v9 = 0.0;
  if ( VolumetricEffects )
  {
    v10 = (UFG::qMatrix44 **)pBuffer;
    v11 = VolumetricEffects;
    do
    {
      v12 = *v10;
      UFG::qLookAtMatrix(*v10 + 3, &UFG::qVector3::msZero, &target, &UFG::qVector3::msAxisZ);
      UFG::qInverseAffine(v12 + 2, v12 + 3);
      scale.x = v12[4].v0.w;
      scale.y = scale.x;
      scale.z = scale.x;
      UFG::qScaleMatrix(v12, &scale);
      UFG::qMatrix44::operator*=(v12, v12 + 2);
      x = v12[4].v0.x;
      y = v12[4].v0.y;
      z = v12[4].v0.z;
      v12->v3.w = 1.0;
      v12->v3.x = x;
      v12->v3.y = y;
      v12->v3.z = z;
      UFG::qInverse(v12 + 1, v12);
      v16 = cam_pos->x;
      y_low = (__m128)LODWORD(cam_pos->y);
      v18 = cam_pos->z;
      v19 = v12->v3.x - cam_pos->x;
      v20 = v12->v3.y - y_low.m128_f32[0];
      v21 = v12->v3.z - v18;
      if ( (float)((float)((float)(v20 * v20) + (float)(v19 * v19)) + (float)(v21 * v21)) <= (float)(s_LowQualityDistance * s_LowQualityDistance) )
        LODWORD(v12[5].v1.w) = (float)((float)((float)(v20 * v20) + (float)(v19 * v19)) + (float)(v21 * v21)) > (float)(s_MedQualityDistance * s_MedQualityDistance);
      else
        LODWORD(v12[5].v1.w) = 2;
      if ( !LOBYTE(v12[5].v1.z) )
      {
        v22 = sCameraFogOpacityRange + v12[4].v0.w;
        y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - v12[4].v0.y)
                                          * (float)(y_low.m128_f32[0] - v12[4].v0.y))
                                  + (float)((float)(v16 - v12[4].v0.x) * (float)(v16 - v12[4].v0.x)))
                          + (float)((float)(v18 - v12[4].v0.z) * (float)(v18 - v12[4].v0.z));
        LODWORD(v23) = _mm_sqrt_ps(y_low).m128_u32[0];
        if ( v22 <= 1.0 )
          v22 = *(float *)&FLOAT_1_0;
        v24 = v23 / v22;
        if ( v24 <= 0.0 )
        {
          v24 = 0.0;
        }
        else if ( v24 >= 1.0 )
        {
          v24 = *(float *)&FLOAT_1_0;
        }
        v9 = v9 + (float)(1.0 - v24);
      }
      ++v10;
      --v11;
    }
    while ( v11 );
  }
  v25 = v9 / sCameraFogDensityThreshold;
  if ( v25 <= 0.0 )
  {
    v25 = 0.0;
  }
  else if ( v25 >= 1.0 )
  {
    v25 = *(float *)&FLOAT_1_0;
  }
  mData = this->mStateBlockSunny.mData;
  v27 = this->mStateBlockStormy.mData;
  sCameraFogCurrentOpacity = (float)((float)((float)(sCameraFogMaxOpacity - sCameraFogMinOpacity) * (float)(1.0 - v25))
                                   + sCameraFogMinOpacity)
                           * (float)(UFG::RenderWorld::msStageEnvMap->mInteriorBlend * this->mOverrideIntensity);
  v28 = UFG::TimeOfDayManager::GetInstance()->m_SecondsSinceMidnight * 0.000011574074;
  if ( !mData )
    return;
  for ( i = 0; i < mData[1].mNode.mUID; this->mSunnyStateValues[v30] = v36 )
  {
    v30 = i;
    v31 = (char *)mData
        + *(unsigned __int16 *)((char *)&mData[1].mResourceHandles.mNode.mNext
                              + 4 * i
                              + ((HIDWORD(mData[1].mNode.mChild[1]) + 15) & 0xFFFFFFF0));
    v32 = *((_DWORD *)v31 + 32);
    if ( !v32 )
      goto LABEL_35;
    v33 = (float *)(v31 + 132);
    v34 = (unsigned int)(v32 - 1);
    v35 = (float *)(v31 + 140);
    if ( v28 > *((float *)v31 + 33) )
    {
      if ( v28 < *(float *)&v31[8 * v34 + 132] )
      {
        v37 = 0;
        if ( (_DWORD)v34 )
        {
          while ( v28 > *v35 )
          {
            ++v37;
            v33 += 2;
            v35 += 2;
            if ( v37 >= (unsigned int)v34 )
              goto LABEL_35;
          }
          v36 = (float)((float)((float)(v28 - *v33) / (float)(*v35 - *v33)) * (float)(v35[1] - v33[1])) + v33[1];
          goto LABEL_36;
        }
LABEL_35:
        v36 = 0.0;
        goto LABEL_36;
      }
      v36 = *(float *)&v31[8 * v34 + 136];
    }
    else
    {
      v36 = *((float *)v31 + 34);
    }
LABEL_36:
    ++i;
  }
  v38 = (__int64)&mData[1].mResourceHandles.mNode.mNext
      + *(unsigned __int16 *)((char *)&mData[2].mNode.mChild[1]
                            + ((HIDWORD(mData[1].mNode.mChild[1]) + 15) & 0xFFFFFFF0)
                            + 4);
  if ( !*(_DWORD *)v38 )
    goto LABEL_46;
  v39 = v38 + 4;
  v40 = (unsigned int)(*(_DWORD *)v38 - 1);
  v41 = (float *)(v38 + 12);
  if ( *(float *)(v38 + 4) < 0.0 )
  {
    if ( *(float *)(v38 + 8 * v40 + 4) <= 0.0 )
    {
      v42 = *(float *)(v38 + 8 * v40 + 8);
      goto LABEL_47;
    }
    v43 = 0;
    if ( *(_DWORD *)v38 != 1 )
    {
      while ( *v41 < 0.0 )
      {
        ++v43;
        v39 += 8i64;
        v41 += 2;
        if ( v43 >= (unsigned int)v40 )
          goto LABEL_46;
      }
      v42 = (float)((float)(COERCE_FLOAT(*(_DWORD *)v39 ^ _xmm[0]) / (float)(*v41 - *(float *)v39))
                  * (float)(v41[1] - *(float *)(v39 + 4)))
          + *(float *)(v39 + 4);
      goto LABEL_47;
    }
LABEL_46:
    v42 = 0.0;
    goto LABEL_47;
  }
  v42 = *(float *)(v38 + 8);
LABEL_47:
  this->mSunnyOpacityOverDist.x = v42;
  if ( !*(_DWORD *)v38 )
    goto LABEL_56;
  v44 = (float *)(v38 + 4);
  v45 = (unsigned int)(*(_DWORD *)v38 - 1);
  v46 = (float *)(v38 + 12);
  if ( *(float *)(v38 + 4) >= 0.33000001 )
  {
    v47 = *(float *)(v38 + 8);
    goto LABEL_57;
  }
  if ( *(float *)(v38 + 8 * v45 + 4) <= 0.33000001 )
  {
    v47 = *(float *)(v38 + 8 * v45 + 8);
    goto LABEL_57;
  }
  v48 = 0;
  if ( *(_DWORD *)v38 == 1 )
  {
LABEL_56:
    v47 = 0.0;
  }
  else
  {
    while ( *v46 < 0.33000001 )
    {
      ++v48;
      v44 += 2;
      v46 += 2;
      if ( v48 >= (unsigned int)v45 )
        goto LABEL_56;
    }
    v47 = (float)((float)((float)(0.33000001 - *v44) / (float)(*v46 - *v44)) * (float)(v46[1] - v44[1])) + v44[1];
  }
LABEL_57:
  this->mSunnyOpacityOverDist.y = v47;
  if ( !*(_DWORD *)v38 )
    goto LABEL_66;
  v49 = (float *)(v38 + 4);
  v50 = (unsigned int)(*(_DWORD *)v38 - 1);
  v51 = (float *)(v38 + 12);
  if ( *(float *)(v38 + 4) < 0.66000003 )
  {
    if ( *(float *)(v38 + 8 * v50 + 4) <= 0.66000003 )
    {
      v52 = *(float *)(v38 + 8 * v50 + 8);
      goto LABEL_67;
    }
    v53 = 0;
    if ( *(_DWORD *)v38 != 1 )
    {
      while ( *v51 < 0.66000003 )
      {
        ++v53;
        v49 += 2;
        v51 += 2;
        if ( v53 >= (unsigned int)v50 )
          goto LABEL_66;
      }
      v52 = (float)((float)((float)(0.66000003 - *v49) / (float)(*v51 - *v49)) * (float)(v51[1] - v49[1])) + v49[1];
      goto LABEL_67;
    }
LABEL_66:
    v52 = 0.0;
    goto LABEL_67;
  }
  v52 = *(float *)(v38 + 8);
LABEL_67:
  this->mSunnyOpacityOverDist.z = v52;
  if ( !*(_DWORD *)v38 )
    goto LABEL_76;
  v54 = (float *)(v38 + 4);
  v55 = (unsigned int)(*(_DWORD *)v38 - 1);
  v56 = (float *)(v38 + 12);
  if ( *(float *)(v38 + 4) >= 1.0 )
  {
    v57 = *(float *)(v38 + 8);
    goto LABEL_77;
  }
  if ( *(float *)(v38 + 8 * v55 + 4) <= 1.0 )
  {
    v57 = *(float *)(v38 + 8 * v55 + 8);
    goto LABEL_77;
  }
  v58 = 0;
  if ( (_DWORD)v55 )
  {
    while ( *v56 < 1.0 )
    {
      ++v58;
      v54 += 2;
      v56 += 2;
      if ( v58 >= (unsigned int)v55 )
        goto LABEL_76;
    }
    v57 = (float)((float)((float)(1.0 - *v54) / (float)(*v56 - *v54)) * (float)(v56[1] - v54[1])) + v54[1];
  }
  else
  {
LABEL_76:
    v57 = 0.0;
  }
LABEL_77:
  this->mSunnyOpacityOverDist.w = v57;
  for ( j = 0; j < v27[1].mNode.mUID; this->mStormyStateValues[v60] = v66 )
  {
    v60 = j;
    v61 = (char *)v27
        + *(unsigned __int16 *)((char *)&v27[1].mResourceHandles.mNode.mNext
                              + 4 * j
                              + ((HIDWORD(v27[1].mNode.mChild[1]) + 15) & 0xFFFFFFF0));
    v62 = *((_DWORD *)v61 + 32);
    if ( !v62 )
      goto LABEL_87;
    v63 = (float *)(v61 + 132);
    v64 = (unsigned int)(v62 - 1);
    v65 = (float *)(v61 + 140);
    if ( v28 > *((float *)v61 + 33) )
    {
      if ( v28 < *(float *)&v61[8 * v64 + 132] )
      {
        v67 = 0;
        if ( (_DWORD)v64 )
        {
          while ( v28 > *v65 )
          {
            ++v67;
            v63 += 2;
            v65 += 2;
            if ( v67 >= (unsigned int)v64 )
              goto LABEL_87;
          }
          v66 = (float)((float)((float)(v28 - *v63) / (float)(*v65 - *v63)) * (float)(v65[1] - v63[1])) + v63[1];
          goto LABEL_88;
        }
LABEL_87:
        v66 = 0.0;
        goto LABEL_88;
      }
      v66 = *(float *)&v61[8 * v64 + 136];
    }
    else
    {
      v66 = *((float *)v61 + 34);
    }
LABEL_88:
    ++j;
  }
  v68 = (__int64)&mData[1].mResourceHandles.mNode.mNext
      + *(unsigned __int16 *)((char *)&mData[2].mNode.mChild[1]
                            + ((HIDWORD(mData[1].mNode.mChild[1]) + 15) & 0xFFFFFFF0)
                            + 4);
  if ( !*(_DWORD *)v68 )
    goto LABEL_98;
  v69 = v68 + 4;
  v70 = (unsigned int)(*(_DWORD *)v68 - 1);
  v71 = (float *)(v68 + 12);
  if ( *(float *)(v68 + 4) < 0.0 )
  {
    if ( *(float *)(v68 + 8 * v70 + 4) <= 0.0 )
    {
      v72 = *(float *)(v68 + 8 * v70 + 8);
      goto LABEL_99;
    }
    v73 = 0;
    if ( *(_DWORD *)v68 != 1 )
    {
      while ( *v71 < 0.0 )
      {
        ++v73;
        v69 += 8i64;
        v71 += 2;
        if ( v73 >= (unsigned int)v70 )
          goto LABEL_98;
      }
      v72 = (float)((float)(COERCE_FLOAT(*(_DWORD *)v69 ^ _xmm[0]) / (float)(*v71 - *(float *)v69))
                  * (float)(v71[1] - *(float *)(v69 + 4)))
          + *(float *)(v69 + 4);
      goto LABEL_99;
    }
LABEL_98:
    v72 = 0.0;
    goto LABEL_99;
  }
  v72 = *(float *)(v68 + 8);
LABEL_99:
  this->mStormyOpacityOverDist.x = v72;
  if ( !*(_DWORD *)v68 )
    goto LABEL_108;
  v74 = (float *)(v68 + 4);
  v75 = (unsigned int)(*(_DWORD *)v68 - 1);
  v76 = (float *)(v68 + 12);
  if ( *(float *)(v68 + 4) >= 0.33000001 )
  {
    v77 = *(float *)(v68 + 8);
    goto LABEL_109;
  }
  if ( *(float *)(v68 + 8 * v75 + 4) <= 0.33000001 )
  {
    v77 = *(float *)(v68 + 8 * v75 + 8);
    goto LABEL_109;
  }
  v78 = 0;
  if ( *(_DWORD *)v68 == 1 )
  {
LABEL_108:
    v77 = 0.0;
  }
  else
  {
    while ( *v76 < 0.33000001 )
    {
      ++v78;
      v74 += 2;
      v76 += 2;
      if ( v78 >= (unsigned int)v75 )
        goto LABEL_108;
    }
    v77 = (float)((float)((float)(0.33000001 - *v74) / (float)(*v76 - *v74)) * (float)(v76[1] - v74[1])) + v74[1];
  }
LABEL_109:
  this->mStormyOpacityOverDist.y = v77;
  if ( !*(_DWORD *)v68 )
    goto LABEL_118;
  v79 = (float *)(v68 + 4);
  v80 = (unsigned int)(*(_DWORD *)v68 - 1);
  v81 = (float *)(v68 + 12);
  if ( *(float *)(v68 + 4) < 0.66000003 )
  {
    if ( *(float *)(v68 + 8 * v80 + 4) <= 0.66000003 )
    {
      v82 = *(float *)(v68 + 8 * v80 + 8);
      goto LABEL_119;
    }
    v83 = 0;
    if ( *(_DWORD *)v68 != 1 )
    {
      while ( *v81 < 0.66000003 )
      {
        ++v83;
        v79 += 2;
        v81 += 2;
        if ( v83 >= (unsigned int)v80 )
          goto LABEL_118;
      }
      v82 = (float)((float)((float)(0.66000003 - *v79) / (float)(*v81 - *v79)) * (float)(v81[1] - v79[1])) + v79[1];
      goto LABEL_119;
    }
LABEL_118:
    v82 = 0.0;
    goto LABEL_119;
  }
  v82 = *(float *)(v68 + 8);
LABEL_119:
  this->mStormyOpacityOverDist.z = v82;
  if ( *(_DWORD *)v68 )
  {
    v84 = (float *)(v68 + 4);
    v85 = (unsigned int)(*(_DWORD *)v68 - 1);
    v86 = (float *)(v68 + 12);
    if ( *(float *)(v68 + 4) < 1.0 )
    {
      if ( *(float *)(v68 + 8 * v85 + 4) > 1.0 )
      {
        if ( *(_DWORD *)v68 != 1 )
        {
          while ( *v86 < 1.0 )
          {
            ++v3;
            v84 += 2;
            v86 += 2;
            if ( v3 >= (unsigned int)v85 )
              goto LABEL_130;
          }
          v8 = (float)((float)((float)(1.0 - *v84) / (float)(*v86 - *v84)) * (float)(v86[1] - v84[1])) + v84[1];
        }
      }
      else
      {
        v8 = *(float *)(v68 + 8 * v85 + 8);
      }
    }
    else
    {
      v8 = *(float *)(v68 + 8);
    }
  }
LABEL_130:
  this->mStormyOpacityOverDist.w = v8;
}8 + 8 * v85 + 8);
      }
    }
    else
    {
      v8 = *(float *)(v68 + 8);
    }
  }
LABEL_130:
  this->mStormyOpacityOverDist.w = v8;
}

// File Line: 706
// RVA: 0x70FF0
char __fastcall Render::CloudVolumeManager::RenderCloudVolumeFog(
        Render::CloudVolumeManager *this,
        UFG::RenderContext *render_context,
        UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list,
        bool bHalfSize)
{
  bool v4; // r15
  CB_EnvironmentSettings *mEnvState; // rbx
  Illusion::StateValues *StateValues; // rax
  Illusion::StateArgs *v11; // rbx
  float z; // xmm0_4
  float v13; // xmm10_4
  float x; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm6_4
  float DisplayAspectRatio; // xmm0_4
  float v18; // xmm6_4
  float v19; // xmm11_4
  float v20; // xmm10_4
  UFG::TimeOfDayManager *Instance; // rax
  float v22; // xmm1_4
  float v23; // xmm15_4
  float v24; // xmm14_4
  float v25; // xmm13_4
  Illusion::Target *mHalfSizeLinearDepthTarget; // rax
  unsigned int VolumetricEffects; // edx
  unsigned int v28; // ecx
  __int64 v29; // rax
  Render::VolumetricEffect *v30; // rdi
  int volumeRange; // eax
  bool v32; // cc
  BOOL v33; // eax
  float fLightingContribution; // xmm2_4
  float w; // xmm12_4
  float v36; // xmm1_4
  float v37; // xmm13_4
  float v38; // xmm3_4
  float v39; // xmm14_4
  float v40; // xmm4_4
  float v41; // xmm15_4
  bool bCameraAttached; // r12
  float v43; // xmm3_4
  float v44; // xmm5_4
  float v45; // xmm4_4
  float v46; // xmm7_4
  __m128 v47; // xmm1
  float v48; // xmm6_4
  float v49; // xmm2_4
  float v50; // xmm4_4
  __m128 y_low; // xmm5
  float v52; // xmm6_4
  __m128 v53; // xmm3
  float v54; // xmm2_4
  float v55; // xmm2_4
  float fScale; // xmm6_4
  float v57; // xmm1_4
  float v58; // xmm2_4
  float v59; // xmm1_4
  float v60; // xmm7_4
  float v61; // xmm10_4
  float v62; // xmm11_4
  float v63; // xmm1_4
  float v64; // xmm12_4
  float v65; // xmm4_4
  float v66; // xmm3_4
  float v67; // xmm2_4
  float v68; // xmm5_4
  int v69; // r15d
  bool v70; // r14
  __int64 v71; // rax
  float v72; // xmm0_4
  __int128 v73; // xmm2
  __int128 v74; // xmm1
  __int128 v75; // xmm0
  __int128 v76; // xmm2
  __int128 v77; // xmm1
  __int128 v78; // xmm0
  unsigned __int16 Param; // ax
  float v80; // xmm14_4
  float v81; // xmm6_4
  char *v82; // rax
  float *v83; // rbx
  float v84; // xmm0_4
  UFG::RenderStageEnvMap *v85; // rax
  Illusion::StateValues *v86; // rax
  Illusion::Material *mMatCloudVolumeFog; // rbx
  _WORD *mOffset; // rax
  Render::VolumetricEffect::eVolumeRange v89; // eax
  Illusion::Texture *mQuarterSizeShadowAliasTexture; // rax
  Illusion::Material *v91; // rbx
  _WORD *v92; // rax
  Illusion::Material *v93; // rbx
  _WORD *v94; // rax
  unsigned int mUID; // r8d
  Illusion::Material *v96; // rbx
  _WORD *v97; // rax
  Illusion::Material *v98; // rbx
  unsigned int v99; // r8d
  _WORD *v100; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mPrev; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mNext; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v103; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v104; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v105; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v106; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v107; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v108; // rax
  unsigned int v109; // [rsp+50h] [rbp-B0h]
  float v110; // [rsp+54h] [rbp-ACh]
  float v111; // [rsp+58h] [rbp-A8h]
  float v112; // [rsp+5Ch] [rbp-A4h]
  unsigned int v113; // [rsp+60h] [rbp-A0h]
  float v114; // [rsp+64h] [rbp-9Ch]
  float v115; // [rsp+68h] [rbp-98h]
  float v116; // [rsp+6Ch] [rbp-94h]
  float v117; // [rsp+70h] [rbp-90h]
  float v118; // [rsp+74h] [rbp-8Ch]
  float v119; // [rsp+78h] [rbp-88h]
  float v120; // [rsp+7Ch] [rbp-84h]
  float v121; // [rsp+7Ch] [rbp-84h]
  float v122; // [rsp+80h] [rbp-80h]
  float v123; // [rsp+84h] [rbp-7Ch]
  float v124; // [rsp+88h] [rbp-78h]
  float y; // [rsp+8Ch] [rbp-74h]
  float v126; // [rsp+90h] [rbp-70h]
  float v127; // [rsp+94h] [rbp-6Ch]
  float v128; // [rsp+98h] [rbp-68h]
  float v129; // [rsp+9Ch] [rbp-64h]
  float v130; // [rsp+A0h] [rbp-60h]
  float v131; // [rsp+A4h] [rbp-5Ch]
  float v132; // [rsp+A8h] [rbp-58h]
  float v133; // [rsp+ACh] [rbp-54h]
  float v134; // [rsp+B0h] [rbp-50h]
  float v135; // [rsp+B4h] [rbp-4Ch]
  float v136; // [rsp+B8h] [rbp-48h]
  float v137; // [rsp+BCh] [rbp-44h]
  float v138; // [rsp+C0h] [rbp-40h]
  float v139; // [rsp+C4h] [rbp-3Ch]
  float v140; // [rsp+C8h] [rbp-38h]
  float v141; // [rsp+D0h] [rbp-30h]
  float v142; // [rsp+D4h] [rbp-2Ch]
  float v143; // [rsp+D8h] [rbp-28h]
  float v144; // [rsp+DCh] [rbp-24h]
  float v145; // [rsp+E0h] [rbp-20h]
  float v146; // [rsp+E4h] [rbp-1Ch]
  float v147; // [rsp+E8h] [rbp-18h]
  float v148; // [rsp+ECh] [rbp-14h]
  float v149; // [rsp+F0h] [rbp-10h]
  __int64 v150; // [rsp+F8h] [rbp-8h]
  float v151; // [rsp+100h] [rbp+0h]
  float v152; // [rsp+104h] [rbp+4h]
  float v153; // [rsp+108h] [rbp+8h]
  float v154; // [rsp+10Ch] [rbp+Ch]
  float v155; // [rsp+110h] [rbp+10h]
  Illusion::StateArgs *StateArgs; // [rsp+118h] [rbp+18h]
  Render::cbShadowTransformState v157; // [rsp+120h] [rbp+20h] BYREF
  UFG::qVector3 v158; // [rsp+180h] [rbp+80h] BYREF
  UFG::qVector3 scale; // [rsp+18Ch] [rbp+8Ch] BYREF
  int v160[4]; // [rsp+198h] [rbp+98h]
  int v161[4]; // [rsp+1A8h] [rbp+A8h]
  __int64 v162[2]; // [rsp+1B8h] [rbp+B8h] BYREF
  Render::cbExternalViewTransformState arg; // [rsp+1C8h] [rbp+C8h] BYREF
  float distance_from_near_plane; // [rsp+200h] [rbp+100h] BYREF
  UFG::qVector4 dir; // [rsp+208h] [rbp+108h] BYREF
  __int64 v166; // [rsp+218h] [rbp+118h]
  UFG::qMatrix44 d; // [rsp+220h] [rbp+120h] BYREF
  __int128 v168[8]; // [rsp+260h] [rbp+160h] BYREF
  UFG::qMatrix44 v169; // [rsp+2E0h] [rbp+1E0h]
  UFG::qMatrix44 dest; // [rsp+320h] [rbp+220h] BYREF
  UFG::qMatrix44 v171; // [rsp+360h] [rbp+260h] BYREF
  UFG::qMatrix44 v172; // [rsp+3A0h] [rbp+2A0h]
  Render::View v173; // [rsp+3E0h] [rbp+2E0h] BYREF
  UFG::RenderStageShadow::LinearCascadeViews views; // [rsp+570h] [rbp+470h] BYREF
  RenderQueueLayer v175; // [rsp+770h] [rbp+670h] BYREF
  LayerSubmitContext ptr; // [rsp+850h] [rbp+750h] BYREF
  Render::VolumetricEffect *pBuffer[512]; // [rsp+14D0h] [rbp+13D0h] BYREF

  v166 = -2i64;
  v4 = bHalfSize;
  if ( !Render::gEnableCloudVolumes
    || !render_context->mRenderFeatures.mWorld
    || (float)(UFG::RenderWorld::msStageEnvMap->mInteriorBlend * this->mOverrideIntensity) < 0.0000099999997
    || bHalfSize && !sFarLODInHalfsize )
  {
    return 0;
  }
  RenderQueueLayer::RenderQueueLayer(&v175);
  LayerSubmitContext::LayerSubmitContext(&ptr);
  v175.mSerializationList = serialization_list;
  ptr.mRenderQueueProvider = &v175;
  ptr.mQueueMode = QM_Single;
  Render::View::View(&v173, &render_context->mMainViewSettings, &ptr);
  StateArgs = Render::View::GetStateArgs(&v173);
  if ( v4 )
  {
    Render::View::BeginTarget(
      &v173,
      render_context->mHalfSizeVolumetricTarget,
      "VolumetricCloudsFar",
      0,
      0,
      0i64,
      1,
      0,
      0,
      0);
    Render::View::Clear(&v173, &UFG::qColour::Zero, 1u, 1.0, 0);
  }
  else
  {
    Render::View::BeginTarget(
      &v173,
      render_context->mQuarterSizeVolumetricTarget,
      "VolumetricClouds",
      0,
      0,
      0i64,
      1,
      0,
      0,
      0);
  }
  mEnvState = render_context->mEnvState;
  StateValues = Render::View::GetStateValues(&v173);
  StateValues->mSetValueMask.mFlags[0] |= 0x80000000000000ui64;
  StateValues->mParamValues[55] = mEnvState;
  Render::cbExternalViewTransformState::cbExternalViewTransformState(
    &arg,
    &v173.mSettings->mWorldView,
    &v173.mSettings->mProjection);
  v11 = StateArgs;
  Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(StateArgs, &arg);
  UFG::qInverseAffine(&d, &render_context->mMainViewSettings.mWorldView);
  z = render_context->mMainViewSettings.mProjection.v2.z;
  if ( z == 0.0 || z == render_context->mMainViewSettings.mProjection.v2.w )
    v13 = v120;
  else
    v13 = render_context->mMainViewSettings.mProjection.v3.z / z;
  x = render_context->mMainViewSettings.mProjection.v0.x;
  if ( x == 0.0 )
    v15 = 0.0;
  else
    v15 = atan2f(1.0, x) * 2.0;
  v16 = tanf(v15 * 0.5);
  DisplayAspectRatio = Render::GetDisplayAspectRatio();
  v152 = d.v3.x;
  y = d.v3.y;
  v111 = d.v3.z;
  v149 = fsqrt(
           (float)((float)((float)(v16 * v13) * (float)(v16 * v13))
                 + (float)((float)((float)(v16 / DisplayAspectRatio) * v13)
                         * (float)((float)(v16 / DisplayAspectRatio) * v13)))
         + (float)(v13 * v13));
  v18 = UFG::TimeOfDayManager::GetInstance()->m_WeatherState * 0.5;
  v19 = (float)(UFG::gNightFogOuterRadius * 1.1)
      / (float)((float)(UFG::gNightFogOuterRadius * 1.1) - (float)(UFG::gNightFogInnerRadius * 1.1));
  v115 = v19;
  v20 = (float)(-1.0 / (float)(UFG::gNightFogOuterRadius * 1.1)) * v19;
  v123 = v20;
  Instance = UFG::TimeOfDayManager::GetInstance();
  UFG::TimeOfDayManager::GetSunDir(Instance, &dir, 0, 0);
  v134 = dir.x;
  v143 = dir.y;
  v136 = dir.z;
  v22 = 1.0 - COERCE_FLOAT(LODWORD(dir.z) & _xmm);
  if ( v22 <= 0.0 )
  {
    v22 = 0.0;
  }
  else if ( v22 >= 1.0 )
  {
    v22 = *(float *)&FLOAT_1_0;
  }
  v142 = (float)((float)(this->mStormyStateValues[0] - this->mSunnyStateValues[0]) * v18) + this->mSunnyStateValues[0];
  v23 = (float)((float)(this->mStormyStateValues[1] - this->mSunnyStateValues[1]) * v18) + this->mSunnyStateValues[1];
  v117 = v23;
  v24 = (float)((float)(this->mStormyStateValues[2] - this->mSunnyStateValues[2]) * v18) + this->mSunnyStateValues[2];
  v119 = v24;
  v25 = (float)((float)(this->mStormyStateValues[3] - this->mSunnyStateValues[3]) * v18) + this->mSunnyStateValues[3];
  v122 = v25;
  v138 = (float)((float)(this->mStormyStateValues[4] - this->mSunnyStateValues[4]) * v18) + this->mSunnyStateValues[4];
  v128 = (float)((float)(this->mStormyStateValues[5] - this->mSunnyStateValues[5]) * v18) + this->mSunnyStateValues[5];
  v137 = (float)((float)(this->mStormyStateValues[6] - this->mSunnyStateValues[6]) * v18) + this->mSunnyStateValues[6];
  v135 = (float)((float)(this->mStormyStateValues[7] - this->mSunnyStateValues[7]) * v18) + this->mSunnyStateValues[7];
  v144 = (float)((float)(this->mStormyStateValues[8] - this->mSunnyStateValues[8]) * v18) + this->mSunnyStateValues[8];
  v130 = (float)((float)(this->mStormyStateValues[12] - this->mSunnyStateValues[12]) * v18)
       + this->mSunnyStateValues[12];
  v141 = (float)((float)((float)(this->mStormyStateValues[9] - this->mSunnyStateValues[9]) * v18)
               + this->mSunnyStateValues[9])
       * v130;
  v132 = (float)((float)((float)(this->mStormyStateValues[10] - this->mSunnyStateValues[10]) * v18)
               + this->mSunnyStateValues[10])
       * v130;
  v140 = (float)((float)((float)(this->mStormyStateValues[11] - this->mSunnyStateValues[11]) * v18)
               + this->mSunnyStateValues[11])
       * v130;
  v154 = (float)((float)((float)(this->mStormyStateValues[13] - this->mSunnyStateValues[13]) * v18)
               + this->mSunnyStateValues[13])
       * v22;
  v139 = (float)((float)((float)(this->mStormyStateValues[14] - this->mSunnyStateValues[14]) * v18)
               + this->mSunnyStateValues[14])
       * v22;
  v147 = (float)((float)((float)(this->mStormyStateValues[15] - this->mSunnyStateValues[15]) * v18)
               + this->mSunnyStateValues[15])
       * v22;
  v145 = (float)((float)((float)(this->mStormyStateValues[16] - this->mSunnyStateValues[16]) * v18)
               + this->mSunnyStateValues[16])
       * v22;
  v121 = (float)((float)(this->mStormyStateValues[18] - this->mSunnyStateValues[18]) * v18)
       + this->mSunnyStateValues[18];
  v133 = (float)((float)(this->mStormyOpacityOverDist.w - this->mSunnyOpacityOverDist.w) * v18)
       + this->mSunnyOpacityOverDist.w;
  v131 = (float)((float)(this->mStormyOpacityOverDist.z - this->mSunnyOpacityOverDist.z) * v18)
       + this->mSunnyOpacityOverDist.z;
  v129 = (float)((float)(this->mStormyOpacityOverDist.y - this->mSunnyOpacityOverDist.y) * v18)
       + this->mSunnyOpacityOverDist.y;
  v127 = (float)((float)(this->mStormyOpacityOverDist.x - this->mSunnyOpacityOverDist.x) * v18)
       + this->mSunnyOpacityOverDist.x;
  if ( v4 )
    mHalfSizeLinearDepthTarget = render_context->mHalfSizeLinearDepthTarget;
  else
    mHalfSizeLinearDepthTarget = render_context->mQuarterSizeLinearDepthTarget;
  Illusion::Material::UpdateParam(
    this->mMatCloudVolumeFog,
    1,
    0x8B43FABF,
    mHalfSizeLinearDepthTarget->mTargetTexture[0]->mNode.mUID);
  VolumetricEffects = Render::VolumetricEffectManager::GetVolumetricEffects(
                        &Render::gVolumetricEffectManager,
                        pBuffer,
                        0x200u);
  v113 = VolumetricEffects;
  v28 = 0;
  v109 = 0;
  v29 = 0i64;
  v150 = 0i64;
  while ( v28 < VolumetricEffects )
  {
    v30 = pBuffer[v29];
    volumeRange = v30->volumeRange;
    if ( volumeRange > sMaxLODRange )
      goto LABEL_136;
    if ( sMidLODInHalfsize )
    {
      if ( sFarLODInHalfsize )
      {
        if ( v4 )
        {
          if ( volumeRange < 1 )
            goto LABEL_136;
          goto LABEL_38;
        }
        v32 = volumeRange < 1;
LABEL_37:
        if ( !v32 )
          goto LABEL_136;
      }
    }
    else if ( sFarLODInHalfsize )
    {
      if ( v4 )
      {
        if ( volumeRange < 2 )
          goto LABEL_136;
        goto LABEL_38;
      }
      v32 = volumeRange < 2;
      goto LABEL_37;
    }
LABEL_38:
    if ( render_context->mMainViewSettings.mCullIndex )
    {
      v33 = Render::View::IsInView(&v173, &gDeferredCube, &v30->mTransform, &distance_from_near_plane);
      v28 = v109;
      VolumetricEffects = v113;
      if ( v33 )
      {
LABEL_42:
        fLightingContribution = v30->fLightingContribution;
        w = v30->fColour.w;
        v36 = w * v25;
        v37 = v30->fColour.z;
        v38 = v37 * v24;
        v39 = v30->fColour.y;
        v40 = v39 * v23;
        v41 = v30->fColour.x;
        v124 = (float)((float)(v36 - w) * fLightingContribution) + w;
        v153 = (float)((float)(v38 - v37) * fLightingContribution) + v37;
        v146 = (float)((float)(v40 - v39) * fLightingContribution) + v39;
        v151 = (float)(fLightingContribution * (float)((float)(v41 * v142) - v41)) + v41;
        v112 = (float)((float)((float)(v135 * w) - w) * fLightingContribution) + w;
        v118 = (float)((float)((float)(v37 * v137) - v37) * fLightingContribution) + v37;
        v114 = (float)((float)((float)(v39 * v128) - v39) * fLightingContribution) + v39;
        v116 = (float)(fLightingContribution * (float)((float)(v41 * v138) - v41)) + v41;
        bCameraAttached = v30->bCameraAttached;
        if ( bCameraAttached )
        {
          v116 = (float)((float)(fLightingContribution * (float)((float)(v41 * v138) - v41)) + v41)
               * sCameraFogShadowScale;
          v114 = (float)((float)((float)((float)(v39 * v128) - v39) * fLightingContribution) + v39)
               * sCameraFogShadowScale;
          v118 = (float)((float)((float)((float)(v37 * v137) - v37) * fLightingContribution) + v37)
               * sCameraFogShadowScale;
          v112 = (float)((float)((float)((float)(v135 * w) - w) * fLightingContribution) + w) * sCameraFogShadowScale;
        }
        v43 = (float)((float)((float)(v130 * w) - w) * fLightingContribution) + w;
        v44 = (float)((float)((float)(v37 * v140) - v37) * fLightingContribution) + v37;
        v45 = (float)((float)((float)(v39 * v132) - v39) * fLightingContribution) + v39;
        v46 = (float)(fLightingContribution * (float)((float)(v41 * v141) - v41)) + v41;
        v47 = (__m128)LODWORD(UFG::gNightFogPosY);
        v48 = v30->mTransform.v3.x;
        v47.m128_f32[0] = (float)((float)(UFG::gNightFogPosY - v30->mTransform.v3.y)
                                * (float)(UFG::gNightFogPosY - v30->mTransform.v3.y))
                        + (float)((float)(UFG::gNightFogPosX - v48) * (float)(UFG::gNightFogPosX - v48));
        v49 = (float)(_mm_sqrt_ps(v47).m128_f32[0] * v20) + v19;
        if ( v49 <= 0.0 )
        {
          v49 = 0.0;
        }
        else if ( v49 >= 1.0 )
        {
          v49 = *(float *)&FLOAT_1_0;
        }
        v148 = v46 * v49;
        v155 = v45 * v49;
        v126 = v44 * v49;
        v110 = v43 * v49;
        v50 = v30->mTransform.v3.z - d.v3.z;
        y_low = (__m128)LODWORD(v30->mTransform.v3.y);
        y_low.m128_f32[0] = y_low.m128_f32[0] - d.v3.y;
        v52 = v48 - d.v3.x;
        v53 = y_low;
        v53.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v52 * v52))
                        + (float)(v50 * v50);
        if ( v53.m128_f32[0] == 0.0 )
          v54 = 0.0;
        else
          v54 = 1.0 / _mm_sqrt_ps(v53).m128_f32[0];
        v55 = (float)((float)((float)(v54 * v52) * v134) + (float)((float)(v54 * y_low.m128_f32[0]) * v143))
            + (float)((float)(v54 * v50) * v136);
        if ( v55 <= 0.0 )
        {
          v55 = 0.0;
        }
        else if ( v55 >= 1.0 )
        {
          v55 = *(float *)&FLOAT_1_0;
        }
        fScale = v30->fScale;
        v57 = _mm_sqrt_ps(v53).m128_f32[0] / (float)(fScale + 1.0);
        if ( v57 <= 0.0 )
        {
          v57 = 0.0;
        }
        else if ( v57 >= 1.0 )
        {
          v57 = *(float *)&FLOAT_1_0;
        }
        v58 = v55 * v57;
        v59 = v30->fLightingContribution;
        v60 = (float)((float)((float)((float)(v145 * w) * v58) - w) * v59) + w;
        v61 = (float)((float)((float)((float)(v147 * v37) * v58) - v37) * v59) + v37;
        v62 = (float)((float)((float)((float)(v39 * v139) * v58) - v39) * v59) + v39;
        v63 = (float)(v59 * (float)((float)((float)(v41 * v154) * v58) - v41)) + v41;
        if ( v60 <= 0.0 )
        {
          v60 = 0.0;
        }
        else if ( v60 >= 1.0 )
        {
          v60 = *(float *)&FLOAT_1_0;
        }
        if ( v61 <= 0.0 )
        {
          v61 = 0.0;
        }
        else if ( v61 >= 1.0 )
        {
          v61 = *(float *)&FLOAT_1_0;
        }
        if ( v62 <= 0.0 )
        {
          v62 = 0.0;
        }
        else if ( v62 >= 1.0 )
        {
          v62 = *(float *)&FLOAT_1_0;
        }
        if ( v63 <= 0.0 )
        {
          v64 = 0.0;
        }
        else if ( v63 < 1.0 )
        {
          v64 = v63;
        }
        else
        {
          v64 = *(float *)&FLOAT_1_0;
        }
        if ( v124 > 0.0000099999997 || v112 > 0.0000099999997 || v110 > 0.0000099999997 || v60 > 0.0000099999997 )
        {
          v65 = (float)((float)((float)(v152 * v30->mTransformInv.v0.x) + (float)(y * v30->mTransformInv.v1.x))
                      + (float)(v111 * v30->mTransformInv.v2.x))
              + v30->mTransformInv.v3.x;
          v66 = (float)((float)((float)(y * v30->mTransformInv.v1.y) + (float)(v152 * v30->mTransformInv.v0.y))
                      + (float)(v111 * v30->mTransformInv.v2.y))
              + v30->mTransformInv.v3.y;
          v67 = (float)((float)((float)(y * v30->mTransformInv.v1.z) + (float)(v152 * v30->mTransformInv.v0.z))
                      + (float)(v111 * v30->mTransformInv.v2.z))
              + v30->mTransformInv.v3.z;
          v68 = (float)((float)((float)(y * v30->mTransformInv.v1.w) + (float)(v152 * v30->mTransformInv.v0.w))
                      + (float)(v111 * v30->mTransformInv.v2.w))
              + v30->mTransformInv.v3.w;
          if ( v68 < 0.0 )
            LODWORD(v68) ^= _xmm[0];
          if ( v67 < 0.0 )
            LODWORD(v67) ^= _xmm[0];
          if ( v66 < 0.0 )
            LODWORD(v66) ^= _xmm[0];
          if ( v65 < 0.0 )
            LODWORD(v65) ^= _xmm[0];
          *(float *)v161 = v65;
          *(float *)&v161[1] = v66;
          *(float *)&v161[2] = v67;
          *(float *)&v161[3] = v68;
          *(float *)v160 = v149 / fScale;
          *(float *)&v160[1] = v149 / fScale;
          *(float *)&v160[2] = v149 / fScale;
          v69 = 1;
          v70 = 0;
          v71 = 0i64;
          while ( 1 )
          {
            v72 = *(float *)&v161[v71];
            if ( v72 > 1.0 )
              break;
            if ( ++v71 >= 3 )
              goto LABEL_93;
          }
          v70 = (float)(*(float *)&v160[v71] + 1.0) > v72;
          v69 = 2;
LABEL_93:
          UFG::RenderStageShadow::GetLinearCascadeViews(UFG::RenderWorld::msStageShadow, &views);
          v73 = (__int128)v30->mTransformInv.v1;
          v74 = (__int128)v30->mTransformInv.v2;
          v75 = (__int128)v30->mTransformInv.v3;
          v168[0] = (__int128)v30->mTransformInv.v0;
          v168[1] = v73;
          v168[2] = v74;
          v168[3] = v75;
          v76 = (__int128)v30->mRotationMtxInv.v1;
          v77 = (__int128)v30->mRotationMtxInv.v2;
          v78 = (__int128)v30->mRotationMtxInv.v3;
          v168[4] = (__int128)v30->mRotationMtxInv.v0;
          v168[5] = v76;
          v168[6] = v77;
          v168[7] = v78;
          v169 = views.mWorldView[2];
          scale.x = 1.0;
          scale.y = -1.0;
          scale.z = 0.5;
          UFG::qScaleMatrix(&dest, &scale);
          dest.v3.z = 0.5;
          v158.x = FLOAT_2_0;
          v158.y = -2.0;
          v158.z = 1.0;
          UFG::qScaleMatrix(&v171, &v158);
          v171.v3.x = -0.5;
          v171.v3.y = -0.5;
          v172 = views.mProjection[2];
          v162[0] = 0i64;
          v162[1] = 0i64;
          v157.mPrev = &v157;
          v157.mNext = &v157;
          v157.mCallback = 0i64;
          v157.mStateParamIndex = Render::cbShadowTransformState::sStateParamIndex;
          *(_WORD *)&v157.mFlags = 1;
          if ( (_WORD)Render::cbShadowTransformState::sStateParamIndex == 0xFFFF )
          {
            Param = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbShadowTransform");
            Render::cbShadowTransformState::sStateParamIndex = Param;
            v157.mStateParamIndex = Param;
          }
          v157.mViewWorld = &v173.mViewWorld;
          v157.mWorldView = (UFG::qMatrix44 *)v168;
          v157.mProjection = &dest;
          v157.mCutplanes = 0i64;
          v157.mBiases = (const float *)v162;
          v157.mBlurWidths = 0i64;
          v157.mCached_Remote.m_Stream = 0i64;
          Illusion::StateArgs::Set<Render::cbShadowTransformState>(v11, &v157);
          v80 = v30->fLightingContribution;
          v81 = (float)((float)((float)(v30->fIntensity * v144) - v30->fIntensity) * v80) + v30->fIntensity;
          v82 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x80u, 0x10u);
          v83 = (float *)v82;
          *(float *)v82 = v151;
          *((float *)v82 + 1) = v146;
          *((float *)v82 + 2) = v153;
          *((float *)v82 + 3) = v124;
          *((float *)v82 + 4) = v116;
          *((float *)v82 + 5) = v114;
          *((float *)v82 + 6) = v118;
          *((float *)v82 + 7) = v112;
          *((float *)v82 + 8) = v148;
          *((float *)v82 + 9) = v155;
          *((float *)v82 + 10) = v126;
          *((float *)v82 + 11) = v110;
          *((float *)v82 + 12) = v64;
          *((float *)v82 + 13) = v62;
          *((float *)v82 + 14) = v61;
          *((float *)v82 + 15) = v60;
          if ( bCameraAttached )
          {
            v84 = sCameraFogCurrentOpacity;
            *((float *)v82 + 16) = sCameraFogCurrentOpacity;
            *((float *)v82 + 17) = v84;
            *((float *)v82 + 18) = v84;
            *((float *)v82 + 19) = v84;
          }
          else
          {
            v85 = UFG::RenderWorld::msStageEnvMap;
            v83[16] = (float)(v127 * UFG::RenderWorld::msStageEnvMap->mInteriorBlend) * this->mOverrideIntensity;
            v83[17] = (float)(v129 * v85->mInteriorBlend) * this->mOverrideIntensity;
            v83[18] = (float)(v131 * v85->mInteriorBlend) * this->mOverrideIntensity;
            v83[19] = (float)(v133 * v85->mInteriorBlend) * this->mOverrideIntensity;
          }
          v83[20] = v81;
          v83[21] = v30->fBentNormals;
          v83[22] = v80;
          v83[23] = v121;
          v86 = Render::View::GetStateValues(&v173);
          v86->mSetValueMask.mFlags[0] |= 0x8000ui64;
          v86->mParamValues[15] = v83;
          mMatCloudVolumeFog = this->mMatCloudVolumeFog;
          if ( LODWORD(mMatCloudVolumeFog[3].mNode.mChild[0]) != this->mVolumeTextureUID )
          {
            UFG::qResourceHandle::Init(
              (UFG::qResourceHandle *)&mMatCloudVolumeFog[2].mNumParams,
              (unsigned int)mMatCloudVolumeFog[3].mNode.mChild[1],
              this->mVolumeTextureUID);
            mOffset = (_WORD *)mMatCloudVolumeFog->mMaterialUser.mOffset;
            if ( mOffset )
              mOffset = (_WORD *)((char *)mOffset + (_QWORD)mMatCloudVolumeFog + 120);
            *mOffset |= 0x20u;
          }
          v89 = v30->volumeRange;
          if ( v89 == VOLUME_RANGE_FAR
            || render_context->mRenderRain
            || !render_context->mRenderSun
            || render_context->mRenderSettingsForFrame.mShadowRes == SHADOW_RES_OFF )
          {
            v93 = this->mMatCloudVolumeFog;
            if ( LODWORD(v93[1].mResourceHandles.UFG::qResourceData::mNode.mNext) != -2130149391 )
            {
              UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v93[1].mNode.mChild[1], v93[1].mTypeUID, 0x81087FF1);
              v94 = (_WORD *)v93->mMaterialUser.mOffset;
              if ( v94 )
                v94 = (_WORD *)((char *)v94 + (_QWORD)v93 + 120);
              *v94 |= 0x20u;
            }
            mUID = render_context->mQuarterSizeShadowAliasTexture->mNode.mUID;
            v96 = this->mMatCloudVolumeFog;
            if ( *(_DWORD *)&v96[3].mDebugName[12] != mUID )
            {
              UFG::qResourceHandle::Init(
                (UFG::qResourceHandle *)&v96[3].mResourceHandles.UFG::qResourceData::mNode.mNext,
                *(_DWORD *)&v96[3].mDebugName[20],
                mUID);
              v97 = (_WORD *)v96->mMaterialUser.mOffset;
              if ( v97 )
                v97 = (_WORD *)((char *)v97 + (_QWORD)v96 + 120);
              *v97 |= 0x20u;
            }
          }
          else
          {
            if ( v89 == VOLUME_RANGE_MID
              || (float)((float)(v30->fScale * v30->fScale) * v30->fScale) < s_HighQualityMinVolume )
            {
              v91 = this->mMatCloudVolumeFog;
              if ( LODWORD(v91[1].mResourceHandles.UFG::qResourceData::mNode.mNext) != -348589182 )
              {
                UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v91[1].mNode.mChild[1], v91[1].mTypeUID, 0xEB38F382);
                v92 = (_WORD *)v91->mMaterialUser.mOffset;
                if ( v92 )
                  v92 = (_WORD *)((char *)v92 + (_QWORD)v91 + 120);
                *v92 |= 0x20u;
              }
              mQuarterSizeShadowAliasTexture = render_context->mQuarterSizeShadowAliasTexture;
            }
            else
            {
              Illusion::Material::UpdateParam(this->mMatCloudVolumeFog, 0, 0x8B5561A1, 0x961293E3);
              mQuarterSizeShadowAliasTexture = render_context->mHalfSizeShadowAliasTexture;
            }
            Illusion::Material::UpdateParam(
              this->mMatCloudVolumeFog,
              5,
              0x8B43FABF,
              mQuarterSizeShadowAliasTexture->mNode.mUID);
          }
          v98 = this->mMatCloudVolumeFog;
          if ( v69 == 1 || v70 )
          {
            if ( *(_DWORD *)&v98[2].mDebugName[28] != -652645828 )
            {
              v99 = -652645828;
              goto LABEL_129;
            }
          }
          else if ( *(_DWORD *)&v98[2].mDebugName[28] != -262489691 )
          {
            v99 = -262489691;
LABEL_129:
            UFG::qResourceHandle::Init(
              (UFG::qResourceHandle *)&v98[2].mDebugName[4],
              *((_DWORD *)&v98[2].UFG::qResourceData + 22),
              v99);
            v100 = (_WORD *)v98->mMaterialUser.mOffset;
            if ( v100 )
              v100 = (_WORD *)((char *)v100 + (_QWORD)v98 + 120);
            *v100 |= 0x20u;
          }
          Render::View::Draw(&v173, &gDeferredCube, &v30->mTransform, 0, this->mMatCloudVolumeFog);
          mPrev = v157.mPrev;
          mNext = v157.mNext;
          v157.mPrev->mNext = v157.mNext;
          mNext->mPrev = mPrev;
          v157.mPrev = &v157;
          v157.mNext = &v157;
          v157.mIsSet = 0;
          v11 = StateArgs;
          if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[v157.mStateParamIndex].mNode.mNext == &StateArgs->mStateArgs[v157.mStateParamIndex] )
            StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)v157.mStateParamIndex >> 6] &= ~(1i64 << (v157.mStateParamIndex & 0x3F));
          v103 = v157.mPrev;
          v104 = v157.mNext;
          v157.mPrev->mNext = v157.mNext;
          v104->mPrev = v103;
          v157.mPrev = &v157;
          v157.mNext = &v157;
          v28 = v109;
          v4 = bHalfSize;
          VolumetricEffects = v113;
        }
        v25 = v122;
        v24 = v119;
        v23 = v117;
        v19 = v115;
        v20 = v123;
      }
    }
    else if ( v30->cull_results->mViewResult[0] <= 1u )
    {
      goto LABEL_42;
    }
LABEL_136:
    v109 = ++v28;
    v29 = ++v150;
  }
  v105 = arg.mPrev;
  v106 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v106->mPrev = v105;
  arg.mPrev = &arg;
  arg.mNext = &arg;
  arg.mIsSet = 0;
  if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)v11->mStateArgs[arg.mStateParamIndex].mNode.mNext == &v11->mStateArgs[arg.mStateParamIndex] )
    v11->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
  Render::View::EndTarget(&v173);
  v107 = arg.mPrev;
  v108 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v108->mPrev = v107;
  arg.mPrev = &arg;
  arg.mNext = &arg;
  `eh vector destructor iterator(
    ptr.mStateArgs.mStateArgs,
    0x10ui64,
    128,
    (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
  RenderQueueLayer::~RenderQueueLayer(&v175);
  return 1;
}

