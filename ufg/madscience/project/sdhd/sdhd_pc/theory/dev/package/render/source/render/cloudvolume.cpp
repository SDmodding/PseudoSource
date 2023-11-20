// File Line: 40
// RVA: 0x1457210
__int64 Render::_dynamic_initializer_for__gCloudVolumeManager__()
{
  UFG::qResourceHandle::qResourceHandle(&stru_142163818);
  UFG::qResourceHandle::qResourceHandle(&stru_142163838);
  return atexit(Render::_dynamic_atexit_destructor_for__gCloudVolumeManager__);
}

// File Line: 445
// RVA: 0x70C30
void __fastcall Render::CloudVolumeManager::Init(Render::CloudVolumeManager *this, UFG::RenderContext *render_context)
{
  Render::CloudVolumeManager *v2; // r14
  UFG::RenderContext *v3; // rdi
  unsigned int v4; // eax
  Illusion::Material *v5; // rax
  Illusion::Material *v6; // rsi
  int v7; // eax
  unsigned int v8; // ebx
  int v9; // eax
  unsigned int v10; // eax
  int v11; // eax
  unsigned int v12; // ebx
  int v13; // eax
  unsigned int v14; // ebx
  unsigned int v15; // eax
  int v16; // eax
  int v17; // ebx
  int v18; // eax
  UFG::qResourceWarehouse *v19; // rax
  UFG::qResourceInventory *v20; // rax
  UFG::qResourceWarehouse *v21; // rax
  UFG::qResourceInventory *v22; // rax
  UFG::qResourceWarehouse *v23; // rax
  _DWORD *v24; // rax
  signed __int64 v25; // rcx
  float v26; // xmm2_4
  float v27; // xmm3_4
  float v28; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm2_4
  float v31; // xmm3_4

  v2 = this;
  v3 = render_context;
  this->mVolumeTextureUID = UFG::qStringHashUpper32("cloudvolumetex", 0xFFFFFFFF);
  v2->mOverrideIntensity = 1.0;
  v4 = UFG::qStringHashUpper32("CloudVolumeFogMat", 0xFFFFFFFF);
  v5 = Illusion::Factory::NewMaterial("CloudVolumeFogMat", v4, 7u, 0i64, 0i64, 0i64);
  LOWORD(v5[1].mNode.mChild[0]) = 0;
  v6 = v5;
  HIDWORD(v5[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v7 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v6[1].mTypeUID = -1957338719;
  LODWORD(v6[1].mResourceHandles.mNode.mNext) = -1777167389;
  LODWORD(v6[1].mNode.mParent) = v7;
  v8 = v3->mQuarterSizeLinearDepthTarget->mTargetTexture[0]->mNode.mUID;
  *(_WORD *)&v6[1].mDebugName[12] = 0;
  *(_DWORD *)&v6[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v9 = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
  LODWORD(v6[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v6[1].mStateBlockMask.mFlags[0]) = v8;
  *(_DWORD *)&v6[1].mDebugName[4] = v9;
  LOWORD(v6[1].mMaterialUser.mOffset) = 0;
  *(&v6[1].mNumParams + 1) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v10 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v6[2].mResourceHandles.mNode.mPrev) = 315097330;
  v6[2].mNode.mUID = -89056095;
  v6[1].mNumParams = v10;
  LOWORD(v6[2].mTypeUID) = 0;
  HIDWORD(v6[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v11 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *((_DWORD *)&v6[2].0 + 22) = 1002903008;
  *(_DWORD *)&v6[2].mDebugName[28] = 1660426324;
  LODWORD(v6[2].mResourceHandles.mNode.mNext) = v11;
  v12 = v2->mVolumeTextureUID;
  LOWORD(v6[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v6[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v13 = UFG::qStringHash32("texVolume0", 0xFFFFFFFF);
  LODWORD(v6[3].mNode.mChild[1]) = -1958479169;
  LODWORD(v6[2].mStateBlockMask.mFlags[0]) = v13;
  LODWORD(v6[3].mNode.mChild[0]) = v12;
  v14 = v3->mQuarterSizeShadowAliasTexture->mNode.mUID;
  LOWORD(v6[3].mResourceHandles.mNode.mPrev) = 0;
  *(&v6[3].mNode.mUID + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v15 = UFG::qStringHash32("texShadowAtlas", 0xFFFFFFFF);
  *(_DWORD *)&v6[3].mDebugName[20] = -1958479169;
  *(_DWORD *)&v6[3].mDebugName[12] = v14;
  v6[3].mNode.mUID = v15;
  v16 = UFG::qStringHashUpper32("SKY_Noise_001", 0xFFFFFFFF);
  *((_WORD *)&v6[3].0 + 44) = 0;
  v17 = v16;
  *(_DWORD *)&v6[3].mDebugName[32] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v18 = UFG::qStringHash32("texNoise", 0xFFFFFFFF);
  LODWORD(v6[4].mNode.mParent) = -1958479169;
  *(_DWORD *)&v6[3].mDebugName[28] = v18;
  LODWORD(v6[3].mMaterialUser.mOffset) = v17;
  v19 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v19, (UFG::qResourceData *)&v6->mNode);
  v2->mMatCloudVolumeFog = v6;
  v20 = `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result )
  {
    v21 = UFG::qResourceWarehouse::Instance();
    v20 = UFG::qResourceWarehouse::GetInventory(v21, 0x4D04C7F2u);
    `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result = v20;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v2->mStateBlockSunny.mPrev, 0x4D04C7F2u, 0xF1D36000, v20);
  v22 = `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result )
  {
    v23 = UFG::qResourceWarehouse::Instance();
    v22 = UFG::qResourceWarehouse::GetInventory(v23, 0x4D04C7F2u);
    `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result = v22;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v2->mStateBlockStormy.mPrev, 0x4D04C7F2u, 0x72CA2FF0u, v22);
  v24 = (_DWORD *)v2->mStormyStateValues;
  v25 = 19i64;
  do
  {
    *(v24 - 19) = 1065353216;
    *v24 = 1065353216;
    ++v24;
    --v25;
  }
  while ( v25 );
  v26 = UFG::qVector4::msOne.z;
  v27 = UFG::qVector4::msOne.w;
  v28 = UFG::qVector4::msOne.x;
  v2->mSunnyOpacityOverDist.y = UFG::qVector4::msOne.y;
  v2->mSunnyOpacityOverDist.z = v26;
  v2->mSunnyOpacityOverDist.x = v28;
  v2->mSunnyOpacityOverDist.w = v27;
  v29 = UFG::qVector4::msOne.y;
  v30 = UFG::qVector4::msOne.z;
  v31 = UFG::qVector4::msOne.w;
  v2->mStormyOpacityOverDist.x = UFG::qVector4::msOne.x;
  v2->mStormyOpacityOverDist.y = v29;
  v2->mStormyOpacityOverDist.z = v30;
  v2->mStormyOpacityOverDist.w = v31;
}

// File Line: 544
// RVA: 0x72490
void __fastcall Render::CloudVolumeManager::Update(Render::CloudVolumeManager *this, float dt, UFG::qVector3 *cam_pos)
{
  unsigned int v3; // ebp
  Render::CloudVolumeManager *v4; // r13
  UFG::qVector3 *v5; // r12
  UFG::TimeOfDayManager *v6; // rax
  unsigned int v7; // eax
  float v8; // xmm6_4
  float v9; // xmm8_4
  UFG::qMatrix44 **v10; // r14
  __int64 v11; // r15
  UFG::qMatrix44 *v12; // rsi
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm5_4
  __m128 v17; // xmm3
  float v18; // xmm9_4
  float v19; // xmm10_4
  float v20; // xmm4_4
  float v21; // xmm11_4
  float v22; // xmm0_4
  float v23; // xmm1_4
  float v24; // xmm1_4
  float v25; // xmm8_4
  UFG::qResourceData *v26; // rbx
  UFG::qResourceData *v27; // rdi
  float v28; // xmm4_4
  unsigned int i; // er9
  __int64 v30; // r11
  char *v31; // rdx
  int v32; // er8
  float *v33; // rcx
  __int64 v34; // r8
  float *v35; // rax
  float v36; // xmm3_4
  unsigned int v37; // edx
  signed __int64 v38; // rcx
  signed __int64 v39; // rdx
  __int64 v40; // r9
  float *v41; // rax
  float v42; // xmm3_4
  unsigned int v43; // er8
  float *v44; // rdx
  __int64 v45; // r9
  float *v46; // rax
  float v47; // xmm3_4
  unsigned int v48; // er8
  float *v49; // rdx
  __int64 v50; // r9
  float *v51; // rax
  float v52; // xmm3_4
  unsigned int v53; // er8
  float *v54; // rdx
  __int64 v55; // r8
  float *v56; // rax
  float v57; // xmm3_4
  unsigned int v58; // ecx
  unsigned int j; // er9
  __int64 v60; // r11
  char *v61; // rdx
  int v62; // er8
  float *v63; // rcx
  __int64 v64; // r8
  float *v65; // rax
  float v66; // xmm3_4
  unsigned int v67; // edx
  signed __int64 v68; // rcx
  signed __int64 v69; // rdx
  __int64 v70; // r9
  float *v71; // rax
  float v72; // xmm3_4
  unsigned int v73; // er8
  float *v74; // rdx
  __int64 v75; // r9
  float *v76; // rax
  float v77; // xmm8_4
  unsigned int v78; // er8
  float *v79; // rdx
  __int64 v80; // r9
  float *v81; // rax
  float v82; // xmm5_4
  unsigned int v83; // er8
  float *v84; // rdx
  __int64 v85; // r8
  float *v86; // rax
  UFG::qVector3 scale; // [rsp+30h] [rbp-10B8h]
  UFG::qVector3 target; // [rsp+40h] [rbp-10A8h]
  UFG::qVector4 dir; // [rsp+50h] [rbp-1098h]
  Render::VolumetricEffect *pBuffer; // [rsp+60h] [rbp-1088h]

  v3 = 0;
  v4 = this;
  v5 = cam_pos;
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
  v6 = UFG::TimeOfDayManager::GetInstance();
  UFG::TimeOfDayManager::GetSunDir(v6, &dir, 0, 0);
  target.x = dir.x;
  *(_QWORD *)&target.y = *(_QWORD *)&dir.y;
  v7 = Render::VolumetricEffectManager::GetVolumetricEffects(&Render::gVolumetricEffectManager, &pBuffer, 0x200u);
  v8 = 0.0;
  v9 = 0.0;
  if ( v7 )
  {
    v10 = (UFG::qMatrix44 **)&pBuffer;
    v11 = v7;
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
      v13 = v12[4].v0.x;
      v14 = v12[4].v0.y;
      v15 = v12[4].v0.z;
      v12->v3.w = 1.0;
      v12->v3.x = v13;
      v12->v3.y = v14;
      v12->v3.z = v15;
      UFG::qInverse(v12 + 1, v12);
      v16 = v5->x;
      v17 = (__m128)LODWORD(v5->y);
      v18 = v5->z;
      v19 = v12->v3.x - v5->x;
      v20 = v12->v3.y - v17.m128_f32[0];
      v21 = v12->v3.z - v18;
      if ( (float)((float)((float)(v20 * v20) + (float)(v19 * v19)) + (float)(v21 * v21)) <= (float)(s_LowQualityDistance * s_LowQualityDistance) )
        LODWORD(v12[5].v1.w) = (float)((float)((float)(v20 * v20) + (float)(v19 * v19)) + (float)(v21 * v21)) > (float)(s_MedQualityDistance * s_MedQualityDistance);
      else
        LODWORD(v12[5].v1.w) = 2;
      if ( !LOBYTE(v12[5].v1.z) )
      {
        v22 = sCameraFogOpacityRange + v12[4].v0.w;
        v17.m128_f32[0] = (float)((float)((float)(v17.m128_f32[0] - v12[4].v0.y) * (float)(v17.m128_f32[0] - v12[4].v0.y))
                                + (float)((float)(v16 - v12[4].v0.x) * (float)(v16 - v12[4].v0.x)))
                        + (float)((float)(v18 - v12[4].v0.z) * (float)(v18 - v12[4].v0.z));
        LODWORD(v23) = (unsigned __int128)_mm_sqrt_ps(v17);
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
  v26 = v4->mStateBlockSunny.mData;
  v27 = v4->mStateBlockStormy.mData;
  sCameraFogCurrentOpacity = (float)((float)((float)(sCameraFogMaxOpacity - sCameraFogMinOpacity) * (float)(1.0 - v25))
                                   + sCameraFogMinOpacity)
                           * (float)(UFG::RenderWorld::msStageEnvMap->mInteriorBlend * v4->mOverrideIntensity);
  v28 = UFG::TimeOfDayManager::GetInstance()->m_SecondsSinceMidnight * 0.000011574074;
  if ( !v26 )
    return;
  for ( i = 0; i < v26[1].mNode.mUID; v4->mSunnyStateValues[v30] = v36 )
  {
    v30 = i;
    v31 = (char *)v26
        + *(unsigned __int16 *)((char *)&v26[1].mResourceHandles.mNode.mNext
                              + 4 * i
                              + ((HIDWORD(v26[1].mNode.mChild[1]) + 15) & 0xFFFFFFF0));
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
  v38 = (signed __int64)&v26[1].mResourceHandles.mNode.mNext
      + *(unsigned __int16 *)((char *)&v26[2].mNode.mChild[1] + ((HIDWORD(v26[1].mNode.mChild[1]) + 15) & 0xFFFFFFF0)
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
  v4->mSunnyOpacityOverDist.x = v42;
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
  if ( *(_DWORD *)v38 != 1 )
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
  else
  {
LABEL_56:
    v47 = 0.0;
  }
LABEL_57:
  v4->mSunnyOpacityOverDist.y = v47;
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
  v4->mSunnyOpacityOverDist.z = v52;
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
  v4->mSunnyOpacityOverDist.w = v57;
  for ( j = 0; j < v27[1].mNode.mUID; v4->mStormyStateValues[v60] = v66 )
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
  v68 = (signed __int64)&v26[1].mResourceHandles.mNode.mNext
      + *(unsigned __int16 *)((char *)&v26[2].mNode.mChild[1] + ((HIDWORD(v26[1].mNode.mChild[1]) + 15) & 0xFFFFFFF0)
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
  v4->mStormyOpacityOverDist.x = v72;
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
  if ( *(_DWORD *)v68 != 1 )
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
  else
  {
LABEL_108:
    v77 = 0.0;
  }
LABEL_109:
  v4->mStormyOpacityOverDist.y = v77;
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
  v4->mStormyOpacityOverDist.z = v82;
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
  v4->mStormyOpacityOverDist.w = v8;
}

// File Line: 706
// RVA: 0x70FF0
char __fastcall Render::CloudVolumeManager::RenderCloudVolumeFog(Render::CloudVolumeManager *this, UFG::RenderContext *render_context, UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list, bool bHalfSize)
{
  bool v4; // r15
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v5; // rbx
  UFG::RenderContext *v6; // r13
  Render::CloudVolumeManager *v7; // rsi
  CB_EnvironmentSettings *v9; // rbx
  Illusion::StateValues *v10; // rax
  Illusion::StateArgs *v11; // rbx
  float v12; // xmm0_4
  float v13; // xmm10_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm6_4
  float v17; // xmm0_4
  float v18; // xmm6_4
  float v19; // xmm11_4
  float v20; // xmm10_4
  UFG::TimeOfDayManager *v21; // rax
  float v22; // xmm1_4
  float v23; // xmm15_4
  float v24; // xmm14_4
  float v25; // xmm13_4
  Illusion::Target *v26; // rax
  unsigned int v27; // eax
  unsigned int v28; // edx
  unsigned int v29; // ecx
  signed __int64 v30; // rax
  Render::VolumetricEffect *v31; // rdi
  signed int v32; // eax
  bool v33; // sf
  unsigned __int8 v34; // of
  BOOL v35; // eax
  float v36; // xmm2_4
  float v37; // xmm12_4
  float v38; // xmm1_4
  float v39; // xmm13_4
  float v40; // xmm3_4
  float v41; // xmm14_4
  float v42; // xmm4_4
  float v43; // xmm15_4
  float v44; // xmm0_4
  bool v45; // r12
  float v46; // xmm3_4
  float v47; // xmm5_4
  float v48; // xmm4_4
  float v49; // xmm7_4
  __m128 v50; // xmm1
  float v51; // xmm6_4
  float v52; // xmm2_4
  float v53; // xmm4_4
  __m128 v54; // xmm5
  float v55; // xmm6_4
  __m128 v56; // xmm3
  float v57; // xmm2_4
  float v58; // xmm2_4
  float v59; // xmm6_4
  float v60; // xmm1_4
  float v61; // xmm2_4
  float v62; // xmm1_4
  float v63; // xmm7_4
  float v64; // xmm10_4
  float v65; // xmm11_4
  float v66; // xmm1_4
  float v67; // xmm12_4
  float v68; // xmm4_4
  float v69; // xmm3_4
  float v70; // xmm2_4
  float v71; // xmm5_4
  signed int v72; // er15
  char v73; // r14
  signed __int64 v74; // rax
  float v75; // xmm0_4
  __int128 v76; // xmm2
  __int128 v77; // xmm1
  __int128 v78; // xmm0
  __int128 v79; // xmm2
  __int128 v80; // xmm1
  __int128 v81; // xmm0
  unsigned __int16 v82; // ax
  float v83; // xmm14_4
  float v84; // xmm6_4
  char *v85; // rax
  float *v86; // rbx
  float v87; // xmm0_4
  UFG::RenderStageEnvMap *v88; // rax
  Illusion::StateValues *v89; // rax
  Illusion::Material *v90; // rbx
  _WORD *v91; // rax
  Render::VolumetricEffect::eVolumeRange v92; // eax
  Illusion::Texture *v93; // rax
  Illusion::Material *v94; // rbx
  _WORD *v95; // rax
  Illusion::Material *v96; // rbx
  _WORD *v97; // rax
  unsigned int v98; // er8
  Illusion::Material *v99; // rbx
  _WORD *v100; // rax
  Illusion::Material *v101; // rbx
  unsigned int v102; // er8
  _WORD *v103; // rax
  Illusion::Material *dest_mip_level; // ST20_8
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v105; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v106; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v107; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v108; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v109; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v110; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v111; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v112; // rax
  unsigned int v113; // [rsp+50h] [rbp-B0h]
  float v114; // [rsp+54h] [rbp-ACh]
  float v115; // [rsp+58h] [rbp-A8h]
  float v116; // [rsp+5Ch] [rbp-A4h]
  unsigned int v117; // [rsp+60h] [rbp-A0h]
  float v118; // [rsp+64h] [rbp-9Ch]
  float v119; // [rsp+68h] [rbp-98h]
  float v120; // [rsp+6Ch] [rbp-94h]
  float v121; // [rsp+70h] [rbp-90h]
  float v122; // [rsp+74h] [rbp-8Ch]
  float v123; // [rsp+78h] [rbp-88h]
  float v124; // [rsp+7Ch] [rbp-84h]
  float v125; // [rsp+7Ch] [rbp-84h]
  float v126; // [rsp+80h] [rbp-80h]
  float v127; // [rsp+84h] [rbp-7Ch]
  float v128; // [rsp+88h] [rbp-78h]
  float v129; // [rsp+8Ch] [rbp-74h]
  float v130; // [rsp+90h] [rbp-70h]
  float v131; // [rsp+94h] [rbp-6Ch]
  float v132; // [rsp+98h] [rbp-68h]
  float v133; // [rsp+9Ch] [rbp-64h]
  float v134; // [rsp+A0h] [rbp-60h]
  float v135; // [rsp+A4h] [rbp-5Ch]
  float v136; // [rsp+A8h] [rbp-58h]
  float v137; // [rsp+ACh] [rbp-54h]
  float v138; // [rsp+B0h] [rbp-50h]
  float v139; // [rsp+B4h] [rbp-4Ch]
  float v140; // [rsp+B8h] [rbp-48h]
  float v141; // [rsp+BCh] [rbp-44h]
  float v142; // [rsp+C0h] [rbp-40h]
  float v143; // [rsp+C4h] [rbp-3Ch]
  float v144; // [rsp+C8h] [rbp-38h]
  float v145; // [rsp+D0h] [rbp-30h]
  float v146; // [rsp+D4h] [rbp-2Ch]
  float v147; // [rsp+D8h] [rbp-28h]
  float v148; // [rsp+DCh] [rbp-24h]
  float v149; // [rsp+E0h] [rbp-20h]
  float v150; // [rsp+E4h] [rbp-1Ch]
  float v151; // [rsp+E8h] [rbp-18h]
  float v152; // [rsp+ECh] [rbp-14h]
  float v153; // [rsp+F0h] [rbp-10h]
  __int64 v154; // [rsp+F8h] [rbp-8h]
  float v155; // [rsp+100h] [rbp+0h]
  float v156; // [rsp+104h] [rbp+4h]
  float v157; // [rsp+108h] [rbp+8h]
  float v158; // [rsp+10Ch] [rbp+Ch]
  float v159; // [rsp+110h] [rbp+10h]
  Illusion::StateArgs *v160; // [rsp+118h] [rbp+18h]
  Render::cbShadowTransformState v161; // [rsp+120h] [rbp+20h]
  UFG::qVector3 v162; // [rsp+180h] [rbp+80h]
  UFG::qVector3 scale; // [rsp+18Ch] [rbp+8Ch]
  float v164; // [rsp+198h] [rbp+98h]
  float v165; // [rsp+19Ch] [rbp+9Ch]
  float v166; // [rsp+1A0h] [rbp+A0h]
  float v167; // [rsp+1A8h] [rbp+A8h]
  float v168; // [rsp+1ACh] [rbp+ACh]
  float v169; // [rsp+1B0h] [rbp+B0h]
  float v170; // [rsp+1B4h] [rbp+B4h]
  __int64 v171; // [rsp+1B8h] [rbp+B8h]
  __int64 v172; // [rsp+1C0h] [rbp+C0h]
  Render::cbExternalViewTransformState arg; // [rsp+1C8h] [rbp+C8h]
  float distance_from_near_plane; // [rsp+200h] [rbp+100h]
  UFG::qVector4 dir; // [rsp+208h] [rbp+108h]
  __int64 v176; // [rsp+218h] [rbp+118h]
  UFG::qMatrix44 d; // [rsp+220h] [rbp+120h]
  UFG::qVector4 v178; // [rsp+260h] [rbp+160h]
  __int128 v179; // [rsp+270h] [rbp+170h]
  __int128 v180; // [rsp+280h] [rbp+180h]
  __int128 v181; // [rsp+290h] [rbp+190h]
  UFG::qVector4 v182; // [rsp+2A0h] [rbp+1A0h]
  __int128 v183; // [rsp+2B0h] [rbp+1B0h]
  __int128 v184; // [rsp+2C0h] [rbp+1C0h]
  __int128 v185; // [rsp+2D0h] [rbp+1D0h]
  UFG::qVector4 v186; // [rsp+2E0h] [rbp+1E0h]
  UFG::qVector4 v187; // [rsp+2F0h] [rbp+1F0h]
  UFG::qVector4 v188; // [rsp+300h] [rbp+200h]
  UFG::qVector4 v189; // [rsp+310h] [rbp+210h]
  UFG::qMatrix44 dest; // [rsp+320h] [rbp+220h]
  UFG::qMatrix44 v191; // [rsp+360h] [rbp+260h]
  UFG::qVector4 v192; // [rsp+3A0h] [rbp+2A0h]
  UFG::qVector4 v193; // [rsp+3B0h] [rbp+2B0h]
  UFG::qVector4 v194; // [rsp+3C0h] [rbp+2C0h]
  UFG::qVector4 v195; // [rsp+3D0h] [rbp+2D0h]
  Render::View v196; // [rsp+3E0h] [rbp+2E0h]
  UFG::RenderStageShadow::LinearCascadeViews views; // [rsp+570h] [rbp+470h]
  RenderQueueLayer v198; // [rsp+770h] [rbp+670h]
  LayerSubmitContext ptr; // [rsp+850h] [rbp+750h]
  Render::VolumetricEffect *pBuffer[512]; // [rsp+14D0h] [rbp+13D0h]
  bool v201; // [rsp+25B8h] [rbp+24B8h]

  v201 = bHalfSize;
  v176 = -2i64;
  v4 = bHalfSize;
  v5 = serialization_list;
  v6 = render_context;
  v7 = this;
  if ( !Render::gEnableCloudVolumes
    || !render_context->mRenderFeatures.mWorld
    || (float)(UFG::RenderWorld::msStageEnvMap->mInteriorBlend * this->mOverrideIntensity) < 0.0000099999997
    || bHalfSize && !sFarLODInHalfsize )
  {
    return 0;
  }
  RenderQueueLayer::RenderQueueLayer(&v198);
  LayerSubmitContext::LayerSubmitContext(&ptr);
  v198.mSerializationList = v5;
  ptr.mRenderQueueProvider = &v198;
  ptr.mQueueMode = 0;
  Render::View::View(&v196, &v6->mMainViewSettings, (Illusion::SubmitContext *)&ptr.vfptr);
  v160 = Render::View::GetStateArgs(&v196);
  if ( v4 )
  {
    Render::View::BeginTarget(&v196, v6->mHalfSizeVolumetricTarget, "VolumetricCloudsFar", 0, 0, 0i64, 1, 0, 0, 0);
    Render::View::Clear(&v196, &UFG::qColour::Zero, 1u, 1.0, 0);
  }
  else
  {
    Render::View::BeginTarget(&v196, v6->mQuarterSizeVolumetricTarget, "VolumetricClouds", 0, 0, 0i64, 1, 0, 0, 0);
  }
  v9 = v6->mEnvState;
  v10 = Render::View::GetStateValues(&v196);
  v10->mSetValueMask.mFlags[0] |= 0x80000000000000ui64;
  v10->mParamValues[55] = v9;
  Render::cbExternalViewTransformState::cbExternalViewTransformState(
    &arg,
    &v196.mSettings->mWorldView,
    &v196.mSettings->mProjection);
  v11 = v160;
  Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(v160, &arg);
  UFG::qInverseAffine(&d, &v6->mMainViewSettings.mWorldView);
  v12 = v6->mMainViewSettings.mProjection.v2.z;
  if ( v12 == 0.0 || v12 == v6->mMainViewSettings.mProjection.v2.w )
    v13 = v124;
  else
    v13 = v6->mMainViewSettings.mProjection.v3.z / v12;
  v14 = v6->mMainViewSettings.mProjection.v0.x;
  if ( v14 == 0.0 )
    v15 = 0.0;
  else
    v15 = atan2f(1.0, v14) * 2.0;
  v16 = tanf(v15 * 0.5);
  v17 = Render::GetDisplayAspectRatio();
  v156 = d.v3.x;
  v129 = d.v3.y;
  v115 = d.v3.z;
  v153 = fsqrt(
           (float)((float)((float)(v16 * v13) * (float)(v16 * v13))
                 + (float)((float)((float)(v16 / v17) * v13) * (float)((float)(v16 / v17) * v13)))
         + (float)(v13 * v13));
  v18 = UFG::TimeOfDayManager::GetInstance()->m_WeatherState * 0.5;
  v19 = (float)(UFG::gNightFogOuterRadius * 1.1)
      / (float)((float)(UFG::gNightFogOuterRadius * 1.1) - (float)(UFG::gNightFogInnerRadius * 1.1));
  v119 = v19;
  v20 = (float)(-1.0 / (float)(UFG::gNightFogOuterRadius * 1.1)) * v19;
  v127 = (float)(-1.0 / (float)(UFG::gNightFogOuterRadius * 1.1)) * v19;
  v21 = UFG::TimeOfDayManager::GetInstance();
  UFG::TimeOfDayManager::GetSunDir(v21, &dir, 0, 0);
  v138 = dir.x;
  v147 = dir.y;
  v140 = dir.z;
  v22 = 1.0 - COERCE_FLOAT(LODWORD(dir.z) & _xmm);
  if ( v22 <= 0.0 )
  {
    v22 = 0.0;
  }
  else if ( v22 >= 1.0 )
  {
    v22 = *(float *)&FLOAT_1_0;
  }
  v146 = (float)((float)(v7->mStormyStateValues[0] - v7->mSunnyStateValues[0]) * v18) + v7->mSunnyStateValues[0];
  v23 = (float)((float)(v7->mStormyStateValues[1] - v7->mSunnyStateValues[1]) * v18) + v7->mSunnyStateValues[1];
  v121 = (float)((float)(v7->mStormyStateValues[1] - v7->mSunnyStateValues[1]) * v18) + v7->mSunnyStateValues[1];
  v24 = (float)((float)(v7->mStormyStateValues[2] - v7->mSunnyStateValues[2]) * v18) + v7->mSunnyStateValues[2];
  v123 = (float)((float)(v7->mStormyStateValues[2] - v7->mSunnyStateValues[2]) * v18) + v7->mSunnyStateValues[2];
  v25 = (float)((float)(v7->mStormyStateValues[3] - v7->mSunnyStateValues[3]) * v18) + v7->mSunnyStateValues[3];
  v126 = (float)((float)(v7->mStormyStateValues[3] - v7->mSunnyStateValues[3]) * v18) + v7->mSunnyStateValues[3];
  v142 = (float)((float)(v7->mStormyStateValues[4] - v7->mSunnyStateValues[4]) * v18) + v7->mSunnyStateValues[4];
  v132 = (float)((float)(v7->mStormyStateValues[5] - v7->mSunnyStateValues[5]) * v18) + v7->mSunnyStateValues[5];
  v141 = (float)((float)(v7->mStormyStateValues[6] - v7->mSunnyStateValues[6]) * v18) + v7->mSunnyStateValues[6];
  v139 = (float)((float)(v7->mStormyStateValues[7] - v7->mSunnyStateValues[7]) * v18) + v7->mSunnyStateValues[7];
  v148 = (float)((float)(v7->mStormyStateValues[8] - v7->mSunnyStateValues[8]) * v18) + v7->mSunnyStateValues[8];
  v134 = (float)((float)(v7->mStormyStateValues[12] - v7->mSunnyStateValues[12]) * v18) + v7->mSunnyStateValues[12];
  v145 = (float)((float)((float)(v7->mStormyStateValues[9] - v7->mSunnyStateValues[9]) * v18) + v7->mSunnyStateValues[9])
       * v134;
  v136 = (float)((float)((float)(v7->mStormyStateValues[10] - v7->mSunnyStateValues[10]) * v18)
               + v7->mSunnyStateValues[10])
       * v134;
  v144 = (float)((float)((float)(v7->mStormyStateValues[11] - v7->mSunnyStateValues[11]) * v18)
               + v7->mSunnyStateValues[11])
       * v134;
  v158 = (float)((float)((float)(v7->mStormyStateValues[13] - v7->mSunnyStateValues[13]) * v18)
               + v7->mSunnyStateValues[13])
       * v22;
  v143 = (float)((float)((float)(v7->mStormyStateValues[14] - v7->mSunnyStateValues[14]) * v18)
               + v7->mSunnyStateValues[14])
       * v22;
  v151 = (float)((float)((float)(v7->mStormyStateValues[15] - v7->mSunnyStateValues[15]) * v18)
               + v7->mSunnyStateValues[15])
       * v22;
  v149 = (float)((float)((float)(v7->mStormyStateValues[16] - v7->mSunnyStateValues[16]) * v18)
               + v7->mSunnyStateValues[16])
       * v22;
  v125 = (float)((float)(v7->mStormyStateValues[18] - v7->mSunnyStateValues[18]) * v18) + v7->mSunnyStateValues[18];
  v137 = (float)((float)(v7->mStormyOpacityOverDist.w - v7->mSunnyOpacityOverDist.w) * v18)
       + v7->mSunnyOpacityOverDist.w;
  v135 = (float)((float)(v7->mStormyOpacityOverDist.z - v7->mSunnyOpacityOverDist.z) * v18)
       + v7->mSunnyOpacityOverDist.z;
  v133 = (float)((float)(v7->mStormyOpacityOverDist.y - v7->mSunnyOpacityOverDist.y) * v18)
       + v7->mSunnyOpacityOverDist.y;
  v131 = (float)((float)(v7->mStormyOpacityOverDist.x - v7->mSunnyOpacityOverDist.x) * v18)
       + v7->mSunnyOpacityOverDist.x;
  if ( v4 )
    v26 = v6->mHalfSizeLinearDepthTarget;
  else
    v26 = v6->mQuarterSizeLinearDepthTarget;
  Illusion::Material::UpdateParam(v7->mMatCloudVolumeFog, 1, 0x8B43FABF, v26->mTargetTexture[0]->mNode.mUID);
  v27 = Render::VolumetricEffectManager::GetVolumetricEffects(&Render::gVolumetricEffectManager, pBuffer, 0x200u);
  v28 = v27;
  v117 = v27;
  v29 = 0;
  v113 = 0;
  v30 = 0i64;
  v154 = 0i64;
  if ( v28 )
  {
    do
    {
      v31 = pBuffer[v30];
      v32 = v31->volumeRange;
      if ( v32 > sMaxLODRange )
        goto LABEL_138;
      if ( sMidLODInHalfsize )
      {
        if ( sFarLODInHalfsize )
        {
          if ( v4 )
          {
            if ( v32 < 1 )
              goto LABEL_138;
            goto LABEL_38;
          }
          v34 = __OFSUB__(v32, 1);
          v33 = v32 - 1 < 0;
LABEL_37:
          if ( !(v33 ^ v34) )
            goto LABEL_138;
          goto LABEL_38;
        }
      }
      else if ( sFarLODInHalfsize )
      {
        if ( v4 )
        {
          if ( v32 < 2 )
            goto LABEL_138;
          goto LABEL_38;
        }
        v34 = __OFSUB__(v32, 2);
        v33 = v32 - 2 < 0;
        goto LABEL_37;
      }
LABEL_38:
      if ( v6->mMainViewSettings.mCullIndex )
      {
        v35 = Render::View::IsInView(&v196, &gDeferredCube, &v31->mTransform, &distance_from_near_plane);
        v29 = v113;
        v28 = v117;
        if ( v35 )
        {
LABEL_42:
          v36 = v31->fLightingContribution;
          v37 = v31->fColour.w;
          v38 = v31->fColour.w * v25;
          v39 = v31->fColour.z;
          v40 = v31->fColour.z * v24;
          v41 = v31->fColour.y;
          v42 = v31->fColour.y * v23;
          v43 = v31->fColour.x;
          v128 = (float)((float)(v38 - v37) * v36) + v37;
          v157 = (float)((float)(v40 - v39) * v36) + v39;
          v150 = (float)((float)(v42 - v41) * v36) + v41;
          v155 = (float)(v31->fLightingContribution * (float)((float)(v31->fColour.x * v146) - v43)) + v43;
          v44 = (float)(v43 * v142) - v43;
          v116 = (float)((float)((float)(v139 * v37) - v37) * v36) + v37;
          v122 = (float)((float)((float)(v39 * v141) - v39) * v36) + v39;
          v118 = (float)((float)((float)(v41 * v132) - v41) * v36) + v41;
          v120 = (float)(v36 * v44) + v43;
          v45 = v31->bCameraAttached;
          if ( v45 )
          {
            v120 = (float)((float)(v36 * v44) + v43) * sCameraFogShadowScale;
            v118 = (float)((float)((float)((float)(v41 * v132) - v41) * v36) + v41) * sCameraFogShadowScale;
            v122 = (float)((float)((float)((float)(v39 * v141) - v39) * v36) + v39) * sCameraFogShadowScale;
            v116 = (float)((float)((float)((float)(v139 * v37) - v37) * v36) + v37) * sCameraFogShadowScale;
          }
          v46 = (float)((float)((float)(v134 * v37) - v37) * v36) + v37;
          v47 = (float)((float)((float)(v39 * v144) - v39) * v36) + v39;
          v48 = (float)((float)((float)(v41 * v136) - v41) * v36) + v41;
          v49 = (float)(v36 * (float)((float)(v43 * v145) - v43)) + v43;
          v50 = (__m128)LODWORD(UFG::gNightFogPosY);
          v51 = v31->mTransform.v3.x;
          v50.m128_f32[0] = (float)((float)(UFG::gNightFogPosY - v31->mTransform.v3.y)
                                  * (float)(UFG::gNightFogPosY - v31->mTransform.v3.y))
                          + (float)((float)(UFG::gNightFogPosX - v51) * (float)(UFG::gNightFogPosX - v51));
          v52 = (float)(COERCE_FLOAT(_mm_sqrt_ps(v50)) * v20) + v19;
          if ( v52 <= 0.0 )
          {
            v52 = 0.0;
          }
          else if ( v52 >= 1.0 )
          {
            v52 = *(float *)&FLOAT_1_0;
          }
          v152 = v49 * v52;
          v159 = v48 * v52;
          v130 = v47 * v52;
          v114 = v46 * v52;
          v53 = v31->mTransform.v3.z - d.v3.z;
          v54 = (__m128)LODWORD(v31->mTransform.v3.y);
          v54.m128_f32[0] = v54.m128_f32[0] - d.v3.y;
          v55 = v51 - d.v3.x;
          v56 = v54;
          v56.m128_f32[0] = (float)((float)(v54.m128_f32[0] * v54.m128_f32[0]) + (float)(v55 * v55))
                          + (float)(v53 * v53);
          if ( v56.m128_f32[0] == 0.0 )
            v57 = 0.0;
          else
            v57 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v56));
          v58 = (float)((float)((float)(v57 * v55) * v138) + (float)((float)(v57 * v54.m128_f32[0]) * v147))
              + (float)((float)(v57 * v53) * v140);
          if ( v58 <= 0.0 )
          {
            v58 = 0.0;
          }
          else if ( v58 >= 1.0 )
          {
            v58 = *(float *)&FLOAT_1_0;
          }
          v59 = v31->fScale;
          v60 = COERCE_FLOAT(_mm_sqrt_ps(v56)) / (float)(v31->fScale + 1.0);
          if ( v60 <= 0.0 )
          {
            v60 = 0.0;
          }
          else if ( v60 >= 1.0 )
          {
            v60 = *(float *)&FLOAT_1_0;
          }
          v61 = v58 * v60;
          v62 = v31->fLightingContribution;
          v63 = (float)((float)((float)((float)(v149 * v37) * v61) - v37) * v62) + v37;
          v64 = (float)((float)((float)((float)(v151 * v39) * v61) - v39) * v62) + v39;
          v65 = (float)((float)((float)((float)(v41 * v143) * v61) - v41) * v62) + v41;
          v66 = (float)(v62 * (float)((float)((float)(v43 * v158) * v61) - v43)) + v43;
          if ( v63 <= 0.0 )
          {
            v63 = 0.0;
          }
          else if ( v63 >= 1.0 )
          {
            v63 = *(float *)&FLOAT_1_0;
          }
          if ( v64 <= 0.0 )
          {
            v64 = 0.0;
          }
          else if ( v64 >= 1.0 )
          {
            v64 = *(float *)&FLOAT_1_0;
          }
          if ( v65 <= 0.0 )
          {
            v65 = 0.0;
          }
          else if ( v65 >= 1.0 )
          {
            v65 = *(float *)&FLOAT_1_0;
          }
          if ( v66 <= 0.0 )
          {
            v67 = 0.0;
          }
          else if ( v66 < 1.0 )
          {
            v67 = v66;
          }
          else
          {
            v67 = *(float *)&FLOAT_1_0;
          }
          if ( v128 > 0.0000099999997 || v116 > 0.0000099999997 || v114 > 0.0000099999997 || v63 > 0.0000099999997 )
          {
            v68 = (float)((float)((float)(v156 * v31->mTransformInv.v0.x) + (float)(v129 * v31->mTransformInv.v1.x))
                        + (float)(v115 * v31->mTransformInv.v2.x))
                + v31->mTransformInv.v3.x;
            v69 = (float)((float)((float)(v129 * v31->mTransformInv.v1.y) + (float)(v156 * v31->mTransformInv.v0.y))
                        + (float)(v115 * v31->mTransformInv.v2.y))
                + v31->mTransformInv.v3.y;
            v70 = (float)((float)((float)(v129 * v31->mTransformInv.v1.z) + (float)(v156 * v31->mTransformInv.v0.z))
                        + (float)(v115 * v31->mTransformInv.v2.z))
                + v31->mTransformInv.v3.z;
            v71 = (float)((float)((float)(v129 * v31->mTransformInv.v1.w) + (float)(v156 * v31->mTransformInv.v0.w))
                        + (float)(v115 * v31->mTransformInv.v2.w))
                + v31->mTransformInv.v3.w;
            if ( v71 < 0.0 )
              LODWORD(v71) ^= _xmm[0];
            if ( v70 < 0.0 )
              LODWORD(v70) ^= _xmm[0];
            if ( v69 < 0.0 )
              LODWORD(v69) ^= _xmm[0];
            if ( v68 < 0.0 )
              LODWORD(v68) ^= _xmm[0];
            v167 = v68;
            v168 = v69;
            v169 = v70;
            v170 = v71;
            v164 = v153 / v59;
            v165 = v153 / v59;
            v166 = v153 / v59;
            v72 = 1;
            v73 = 0;
            v74 = 0i64;
            while ( 1 )
            {
              v75 = *(float *)((char *)&v167 + v74);
              if ( v75 > 1.0 )
                break;
              v74 += 4i64;
              if ( v74 >= 12 )
                goto LABEL_95;
            }
            v73 = 0;
            if ( (float)(*(float *)((char *)&v164 + v74) + 1.0) > v75 )
              v73 = 1;
            v72 = 2;
LABEL_95:
            UFG::RenderStageShadow::GetLinearCascadeViews(UFG::RenderWorld::msStageShadow, &views);
            v76 = (__int128)v31->mTransformInv.v1;
            v77 = (__int128)v31->mTransformInv.v2;
            v78 = (__int128)v31->mTransformInv.v3;
            v178 = v31->mTransformInv.v0;
            v179 = v76;
            v180 = v77;
            v181 = v78;
            v79 = (__int128)v31->mRotationMtxInv.v1;
            v80 = (__int128)v31->mRotationMtxInv.v2;
            v81 = (__int128)v31->mRotationMtxInv.v3;
            v182 = v31->mRotationMtxInv.v0;
            v183 = v79;
            v184 = v80;
            v185 = v81;
            v186 = views.mWorldView[2].v0;
            v187 = views.mWorldView[2].v1;
            v188 = views.mWorldView[2].v2;
            v189 = views.mWorldView[2].v3;
            scale.x = 1.0;
            scale.y = -1.0;
            scale.z = 0.5;
            UFG::qScaleMatrix(&dest, &scale);
            dest.v3.z = 0.5;
            v162.x = FLOAT_2_0;
            v162.y = -2.0;
            v162.z = 1.0;
            UFG::qScaleMatrix(&v191, &v162);
            v191.v3.x = -0.5;
            v191.v3.y = -0.5;
            v192 = views.mProjection[2].v0;
            v193 = views.mProjection[2].v1;
            v194 = views.mProjection[2].v2;
            v195 = views.mProjection[2].v3;
            v171 = 0i64;
            v172 = 0i64;
            v161.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v161;
            v161.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v161;
            v161.mCallback = 0i64;
            v161.mStateParamIndex = Render::cbShadowTransformState::sStateParamIndex;
            *(_WORD *)&v161.mFlags = 1;
            if ( (_WORD)Render::cbShadowTransformState::sStateParamIndex == -1 )
            {
              v82 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbShadowTransform");
              Render::cbShadowTransformState::sStateParamIndex = v82;
              v161.mStateParamIndex = v82;
            }
            v161.mViewWorld = &v196.mViewWorld;
            v161.mWorldView = (UFG::qMatrix44 *)&v178;
            v161.mProjection = &dest;
            v161.mCutplanes = 0i64;
            v161.mBiases = (const float *)&v171;
            v161.mBlurWidths = 0i64;
            v161.mCached_Remote.m_Stream = 0i64;
            Illusion::StateArgs::Set<Render::cbShadowTransformState>(v11, &v161);
            v83 = v31->fLightingContribution;
            v84 = (float)((float)((float)(v31->fIntensity * v148) - v31->fIntensity) * v83) + v31->fIntensity;
            v85 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x80u, 0x10u);
            v86 = (float *)v85;
            *(float *)v85 = v155;
            *((float *)v85 + 1) = v150;
            *((float *)v85 + 2) = v157;
            *((float *)v85 + 3) = v128;
            *((float *)v85 + 4) = v120;
            *((float *)v85 + 5) = v118;
            *((float *)v85 + 6) = v122;
            *((float *)v85 + 7) = v116;
            *((float *)v85 + 8) = v152;
            *((float *)v85 + 9) = v159;
            *((float *)v85 + 10) = v130;
            *((float *)v85 + 11) = v114;
            *((float *)v85 + 12) = v67;
            *((float *)v85 + 13) = v65;
            *((float *)v85 + 14) = v64;
            *((float *)v85 + 15) = v63;
            if ( v45 )
            {
              v87 = sCameraFogCurrentOpacity;
              *((float *)v85 + 16) = sCameraFogCurrentOpacity;
              *((float *)v85 + 17) = v87;
              *((float *)v85 + 18) = v87;
              *((float *)v85 + 19) = v87;
            }
            else
            {
              v88 = UFG::RenderWorld::msStageEnvMap;
              v86[16] = (float)(v131 * UFG::RenderWorld::msStageEnvMap->mInteriorBlend) * v7->mOverrideIntensity;
              v86[17] = (float)(v133 * v88->mInteriorBlend) * v7->mOverrideIntensity;
              v86[18] = (float)(v135 * v88->mInteriorBlend) * v7->mOverrideIntensity;
              v86[19] = (float)(v137 * v88->mInteriorBlend) * v7->mOverrideIntensity;
            }
            v86[20] = v84;
            v86[21] = v31->fBentNormals;
            v86[22] = v83;
            v86[23] = v125;
            v89 = Render::View::GetStateValues(&v196);
            v89->mSetValueMask.mFlags[0] |= 0x8000ui64;
            v89->mParamValues[15] = v86;
            v90 = v7->mMatCloudVolumeFog;
            if ( LODWORD(v90[3].mNode.mChild[0]) != v7->mVolumeTextureUID )
            {
              UFG::qResourceHandle::Init(
                (UFG::qResourceHandle *)&v90[2].mNumParams,
                (unsigned int)v90[3].mNode.mChild[1],
                v7->mVolumeTextureUID);
              v91 = (_WORD *)v90->mMaterialUser.mOffset;
              if ( v91 )
                v91 = (_WORD *)((char *)v91 + (_QWORD)v90 + 120);
              *v91 |= 0x20u;
            }
            v92 = v31->volumeRange;
            if ( v92 != 2 && v6->mRenderRain != 1 && v6->mRenderSun && v6->mRenderSettingsForFrame.mShadowRes )
            {
              if ( v92 == 1 || (float)((float)(v31->fScale * v31->fScale) * v31->fScale) < s_HighQualityMinVolume )
              {
                v94 = v7->mMatCloudVolumeFog;
                if ( LODWORD(v94[1].mResourceHandles.mNode.mNext) != -348589182 )
                {
                  UFG::qResourceHandle::Init(
                    (UFG::qResourceHandle *)&v94[1].mNode.mChild[1],
                    v94[1].mTypeUID,
                    0xEB38F382);
                  v95 = (_WORD *)v94->mMaterialUser.mOffset;
                  if ( v95 )
                    v95 = (_WORD *)((char *)v95 + (_QWORD)v94 + 120);
                  *v95 |= 0x20u;
                }
                v93 = v6->mQuarterSizeShadowAliasTexture;
              }
              else
              {
                Illusion::Material::UpdateParam(v7->mMatCloudVolumeFog, 0, 0x8B5561A1, 0x961293E3);
                v93 = v6->mHalfSizeShadowAliasTexture;
              }
              Illusion::Material::UpdateParam(v7->mMatCloudVolumeFog, 5, 0x8B43FABF, v93->mNode.mUID);
            }
            else
            {
              v96 = v7->mMatCloudVolumeFog;
              if ( LODWORD(v96[1].mResourceHandles.mNode.mNext) != -2130149391 )
              {
                UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v96[1].mNode.mChild[1], v96[1].mTypeUID, 0x81087FF1);
                v97 = (_WORD *)v96->mMaterialUser.mOffset;
                if ( v97 )
                  v97 = (_WORD *)((char *)v97 + (_QWORD)v96 + 120);
                *v97 |= 0x20u;
              }
              v98 = v6->mQuarterSizeShadowAliasTexture->mNode.mUID;
              v99 = v7->mMatCloudVolumeFog;
              if ( *(_DWORD *)&v99[3].mDebugName[12] != v98 )
              {
                UFG::qResourceHandle::Init(
                  (UFG::qResourceHandle *)&v99[3].mResourceHandles.mNode.mNext,
                  *(_DWORD *)&v99[3].mDebugName[20],
                  v98);
                v100 = (_WORD *)v99->mMaterialUser.mOffset;
                if ( v100 )
                  v100 = (_WORD *)((char *)v100 + (_QWORD)v99 + 120);
                *v100 |= 0x20u;
              }
            }
            v101 = v7->mMatCloudVolumeFog;
            if ( v72 == 1 || v73 )
            {
              if ( *(_DWORD *)&v101[2].mDebugName[28] != -652645828 )
              {
                v102 = -652645828;
                goto LABEL_131;
              }
            }
            else if ( *(_DWORD *)&v101[2].mDebugName[28] != -262489691 )
            {
              v102 = -262489691;
LABEL_131:
              UFG::qResourceHandle::Init(
                (UFG::qResourceHandle *)&v101[2].mDebugName[4],
                *((_DWORD *)&v101[2].0 + 22),
                v102);
              v103 = (_WORD *)v101->mMaterialUser.mOffset;
              if ( v103 )
                v103 = (_WORD *)((char *)v103 + (_QWORD)v101 + 120);
              *v103 |= 0x20u;
            }
            dest_mip_level = v7->mMatCloudVolumeFog;
            Render::View::Draw(&v196, &gDeferredCube, &v31->mTransform, 0);
            v105 = v161.mPrev;
            v106 = v161.mNext;
            v161.mPrev->mNext = v161.mNext;
            v106->mPrev = v105;
            v161.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v161;
            v161.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v161;
            v161.mIsSet = 0;
            v11 = v160;
            if ( (Illusion::StateArgs *)v160->mStateArgsCreateMask.mFlags[2 * (v161.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v160 + 16 * (v161.mStateParamIndex + 3i64)) )
              v160->mStateArgsCreateMask.mFlags[(unsigned int)v161.mStateParamIndex >> 6] &= ~(1i64 << (v161.mStateParamIndex & 0x3F));
            v107 = v161.mPrev;
            v108 = v161.mNext;
            v161.mPrev->mNext = v161.mNext;
            v108->mPrev = v107;
            v161.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v161;
            v161.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v161;
            v29 = v113;
            v4 = v201;
            v28 = v117;
          }
          v25 = v126;
          v24 = v123;
          v23 = v121;
          v19 = v119;
          v20 = v127;
          goto LABEL_138;
        }
      }
      else if ( v31->cull_results->mViewResult[0] <= 1u )
      {
        goto LABEL_42;
      }
LABEL_138:
      v113 = ++v29;
      v30 = v154++ + 1;
    }
    while ( v29 < v28 );
  }
  v109 = arg.mPrev;
  v110 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v110->mPrev = v109;
  arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mIsSet = 0;
  if ( (Illusion::StateArgs *)v11->mStateArgsCreateMask.mFlags[2 * (arg.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v11 + 16 * (arg.mStateParamIndex + 3i64)) )
    v11->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
  Render::View::EndTarget(&v196);
  v111 = arg.mPrev;
  v112 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v112->mPrev = v111;
  arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  `eh vector destructor iterator(
    ptr.mStateArgs.mStateArgs,
    0x10ui64,
    128,
    (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
  RenderQueueLayer::~RenderQueueLayer(&v198);
  return 1;
}ender::Decal,Render::Decal,0,0>);
  RenderQueueLayer::~RenderQueueLayer(&v198);
  return 1;
}

