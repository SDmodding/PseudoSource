// File Line: 88
// RVA: 0x3E3D0
Illusion::RenderQueue *__fastcall UFG::HairSkinSubmitContext::OnPreSubmit(UFG::HairSkinSubmitContext *this, UFG::qMemoryStream<Illusion::Shader,1160> *shader_stream, UFG::BitFlags128 *already_called_funcs_mask)
{
  UFG::HairSkinSubmitContext *v3; // rbx
  UFG::BitFlags128 *v4; // rsi
  UFG::qMemoryStream<Illusion::Shader,1160> *v5; // rdi
  __int32 v6; // ecx
  bool v7; // al

  v3 = this;
  v4 = already_called_funcs_mask;
  v5 = shader_stream;
  v6 = this->mStateMode - 1;
  if ( v6 )
  {
    if ( v6 != 1 )
      return 0i64;
    v7 = UFG::RenderStageHairSkin::StateModifier_SSS_Pass2(&v3->mStateValues, v3->mRenderContext);
  }
  else
  {
    v7 = UFG::RenderStageHairSkin::StateModifier_SSS(&v3->mStateValues, v3->mRenderContext);
  }
  if ( !v7 )
    return 0i64;
  Illusion::SubmitContext::LoadShader((Illusion::SubmitContext *)&v3->vfptr, v5);
  return LayerSubmitContext::OnPreSubmit((LayerSubmitContext *)&v3->vfptr, v5, v4);
}

// File Line: 127
// RVA: 0x3DE70
void __fastcall UFG::RenderStageHairSkin::Create(UFG::RenderContext *render_context)
{
  UFG::RenderContext *v1; // rbx
  UFG::RenderStageHairSkin *v2; // rax

  v1 = render_context;
  v2 = (UFG::RenderStageHairSkin *)UFG::qMalloc(0x200ui64, "RenderStageHairSkin", 0i64);
  if ( v2 )
    UFG::RenderStageHairSkin::RenderStageHairSkin(v2, v1);
}

// File Line: 136
// RVA: 0x3DAD0
void __fastcall UFG::RenderStageHairSkin::RenderStageHairSkin(UFG::RenderStageHairSkin *this, UFG::RenderContext *render_context)
{
  UFG::RenderStageHairSkin *v2; // rbx
  UFG::qResourceHandle *v3; // rdi
  UFG::qResourceInventory *v4; // rax
  UFG::qResourceWarehouse *v5; // rax
  UFG::qResourceInventory *v6; // rax
  UFG::qResourceWarehouse *v7; // rax
  UFG::qResourceInventory *v8; // rax
  UFG::qResourceWarehouse *v9; // rax
  UFG::qResourceInventory *v10; // rax
  UFG::qResourceWarehouse *v11; // rax
  UFG::qResourceInventory *v12; // rax
  UFG::qResourceWarehouse *v13; // rax
  UFG::qResourceInventory *v14; // rax
  UFG::qResourceWarehouse *v15; // rax
  UFG::qResourceInventory *v16; // rax
  UFG::qResourceWarehouse *v17; // rax
  UFG::qResourceInventory *v18; // rax
  UFG::qResourceWarehouse *v19; // rax

  v2 = this;
  v3 = (UFG::qResourceHandle *)&this->mRasterStateHighlightHandle.mPrev;
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&this->mRasterStateHighlightHandle.mPrev);
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v2->mRasterStateHairBlurHandle.mPrev);
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v2->mSkinSSShaderHandle.mPrev);
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v2->mHairShaderHandle.mPrev);
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v2->mSkinSSShaderPass2Handle.mPrev);
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v2->mHairShaderPass2Handle.mPrev);
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v2->mHairBlurShaderHandle.mPrev);
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v2->mHairAlphaStateHandle.mPrev);
  *(_WORD *)&v2->mEnableSSS = 1;
  v2->mEnableHairLighting = 1;
  v2->mHairIntensity = 0.30000001;
  v2->mHairIntensityFromLights = 1.0;
  v2->mHairIntensityFromSun = 2.0;
  v2->mHairIntensityPower = 0.30000001;
  v2->mHairMaxIntensity = 1.0;
  v4 = `UFG::qGetResourceInventory<Illusion::RasterState>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::RasterState>'::`2'::result )
  {
    v5 = UFG::qResourceWarehouse::Instance();
    v4 = UFG::qResourceWarehouse::GetInventory(v5, 0x3BC715E0u);
    `UFG::qGetResourceInventory<Illusion::RasterState>'::`2'::result = v4;
  }
  UFG::qResourceHandle::Init(v3, 0x3BC715E0u, 0x455DCC70u, v4);
  v6 = `UFG::qGetResourceInventory<Illusion::RasterState>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::RasterState>'::`2'::result )
  {
    v7 = UFG::qResourceWarehouse::Instance();
    v6 = UFG::qResourceWarehouse::GetInventory(v7, 0x3BC715E0u);
    `UFG::qGetResourceInventory<Illusion::RasterState>'::`2'::result = v6;
  }
  UFG::qResourceHandle::Init(
    (UFG::qResourceHandle *)&v2->mRasterStateHairBlurHandle.mPrev,
    0x3BC715E0u,
    0x418CAF43u,
    v6);
  v8 = `UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result )
  {
    v9 = UFG::qResourceWarehouse::Instance();
    v8 = UFG::qResourceWarehouse::GetInventory(v9, 0x8B5561A1);
    `UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result = v8;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v2->mSkinSSShaderHandle.mPrev, 0x8B5561A1, 0x9E96F75B, v8);
  v10 = `UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result )
  {
    v11 = UFG::qResourceWarehouse::Instance();
    v10 = UFG::qResourceWarehouse::GetInventory(v11, 0x8B5561A1);
    `UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result = v10;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v2->mSkinSSShaderPass2Handle.mPrev, 0x8B5561A1, 0x93D5D182, v10);
  v12 = `UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result )
  {
    v13 = UFG::qResourceWarehouse::Instance();
    v12 = UFG::qResourceWarehouse::GetInventory(v13, 0x8B5561A1);
    `UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result = v12;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v2->mHairShaderHandle.mPrev, 0x8B5561A1, 0x6147A81Du, v12);
  v14 = `UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result )
  {
    v15 = UFG::qResourceWarehouse::Instance();
    v14 = UFG::qResourceWarehouse::GetInventory(v15, 0x8B5561A1);
    `UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result = v14;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v2->mHairShaderPass2Handle.mPrev, 0x8B5561A1, 0x6C048EC4u, v14);
  v16 = `UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result )
  {
    v17 = UFG::qResourceWarehouse::Instance();
    v16 = UFG::qResourceWarehouse::GetInventory(v17, 0x8B5561A1);
    `UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result = v16;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v2->mHairBlurShaderHandle.mPrev, 0x8B5561A1, 0x8742ECB1, v16);
  v18 = `UFG::qGetResourceInventory<Illusion::AlphaState>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::AlphaState>'::`2'::result )
  {
    v19 = UFG::qResourceWarehouse::Instance();
    v18 = UFG::qResourceWarehouse::GetInventory(v19, 0x12C800F2u);
    `UFG::qGetResourceInventory<Illusion::AlphaState>'::`2'::result = v18;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v2->mHairAlphaStateHandle.mPrev, 0x12C800F2u, 0xC275D439, v18);
}

// File Line: 173
// RVA: 0x3EB70
char __fastcall UFG::RenderStageHairSkin::StateModifier_SSS(Illusion::StateValues *state_values, void *override_params_Remote)
{
  _DWORD *v2; // rax
  char *v3; // rsi
  Illusion::StateValues *v4; // rdi
  UFG::qResourceData *v5; // r8
  UFG::qResourceData *v6; // rax
  void *v7; // rcx
  void *v8; // rcx
  void *v9; // rcx
  UFG::qResourceData *v10; // rcx
  UFG::TimeOfDayManager *v11; // rax
  bool v12; // bl
  char *v13; // r14
  UFG::RenderStageHairSkin *v14; // rax
  float sunBoost; // ST28_4
  UFG::RenderStageHairSkin *v16; // rbx
  UFG::qVector4 *v17; // rax
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm2_4
  float v27; // xmm0_4
  float v28; // xmm1_4
  float v29; // xmm2_4
  void *v30; // rax
  char v31; // al
  UFG::qResourceData *v32; // rax
  UFG::qResourceData *v33; // rcx
  void *v34; // rcx
  void *v35; // rcx
  void *v36; // rcx
  UFG::qResourceData *v37; // rax
  UFG::qResourceData *v38; // rcx
  UFG::TimeOfDayManager *v39; // rax
  char *v40; // rbx
  float v41; // xmm0_4
  float v42; // xmm1_4
  float v43; // xmm2_4
  float v44; // xmm0_4
  float v45; // xmm1_4
  float v46; // xmm2_4
  UFG::RenderStageHairSkin *v47; // rbp
  float v48; // xmm0_4
  float v49; // xmm6_4
  float v50; // xmm0_4
  float v51; // xmm3_4
  float v52; // xmm2_4
  float v53; // xmm1_4
  void *v54; // rax
  __int64 lightRadiusBoost; // [rsp+20h] [rbp-48h]
  UFG::qVector4 result; // [rsp+40h] [rbp-28h]

  v2 = state_values->mParamValues[1];
  v3 = (char *)override_params_Remote;
  v4 = state_values;
  if ( *((_BYTE *)override_params_Remote + 1154) && v2[6] == -824049412 )
  {
    v5 = UFG::RenderWorld::msStageHairSkin->mRasterStateHighlightHandle.mData;
    state_values->mSetValueMask.mFlags[0] |= 0x400ui64;
    state_values->mParamValues[10] = v5;
    v6 = AlphaStateNoneHandle.mData;
    state_values->mSetValueMask.mFlags[0] |= 0x200ui64;
    state_values->mParamValues[9] = v6;
    v7 = *(void **)(*((_QWORD *)override_params_Remote + 5) + 24i64);
    v4->mSetValueMask.mFlags[0] |= 0x20000ui64;
    v4->mParamValues[17] = v7;
    v8 = *(void **)(*((_QWORD *)override_params_Remote + 1) + 32i64);
    v4->mSetValueMask.mFlags[0] |= 0x400000000000ui64;
    v4->mParamValues[46] = v8;
    v9 = *(void **)(*((_QWORD *)override_params_Remote + 1) + 72i64);
    v4->mSetValueMask.mFlags[0] |= 0x800000000000ui64;
    v4->mParamValues[47] = v9;
    v10 = UFG::RenderWorld::msStageHairSkin->mSkinSSShaderHandle.mData;
    v4->mSetValueMask.mFlags[0] |= 2ui64;
    v4->mParamValues[1] = v10;
    v11 = UFG::TimeOfDayManager::GetInstance();
    v12 = 1;
    if ( !UFG::TimeOfDayManager::IsSunShining(v11, *((CB_EnvironmentSettings **)v3 + 145)) )
      v12 = 0;
    v13 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x80u, 0x10u);
    v14 = UFG::RenderWorld::msStageHairSkin;
    if ( UFG::RenderWorld::msStageHairSkin->mbCalcLightDirSkin )
    {
      sunBoost = UFG::RenderWorld::msStageHairSkin->mHairIntensityFromSun;
      *(float *)&lightRadiusBoost = UFG::RenderWorld::msStageHairSkin->mHairIntensityFromLights;
      UFG::RenderStageAO::GetSignificantLightDirection(
        &UFG::RenderWorld::msStageHairSkin->mSkinLocalWorld,
        &UFG::RenderWorld::msStageHairSkin->mSkinLocalWorldInv,
        *((CB_EnvironmentSettings **)v3 + 145),
        v12,
        lightRadiusBoost);
      UFG::RenderWorld::msStageHairSkin->mbCalcLightDirSkin = 0;
      v16 = UFG::RenderWorld::msStageHairSkin;
      v17 = UFG::operator*(
              &result,
              &UFG::RenderWorld::msStageHairSkin->mLightDirWorldSkin,
              (UFG::qMatrix44 *)(v3 + 1008));
      v18 = v17->y;
      v19 = v17->z;
      v20 = v17->w;
      v16->mLightDirViewSkin.x = v17->x;
      v16->mLightDirViewSkin.y = v18;
      v16->mLightDirViewSkin.z = v19;
      v16->mLightDirViewSkin.w = v20;
      v14 = UFG::RenderWorld::msStageHairSkin;
    }
    v21 = v14->mLightDirWorldSkin.y;
    v22 = v14->mLightDirWorldSkin.z;
    v23 = v14->mLightDirWorldSkin.w;
    *(float *)v13 = v14->mLightDirWorldSkin.x;
    *((float *)v13 + 1) = v21;
    *((float *)v13 + 2) = v22;
    *((float *)v13 + 3) = v23;
    v24 = UFG::RenderWorld::msStageHairSkin->mLightDirViewSkin.y;
    v25 = UFG::RenderWorld::msStageHairSkin->mLightDirViewSkin.z;
    v26 = UFG::RenderWorld::msStageHairSkin->mLightDirViewSkin.w;
    *((_DWORD *)v13 + 4) = LODWORD(UFG::RenderWorld::msStageHairSkin->mLightDirViewSkin.x);
    *((float *)v13 + 5) = v24;
    *((float *)v13 + 6) = v25;
    *((float *)v13 + 7) = v26;
    v27 = UFG::RenderWorld::msStageHairSkin->mLightColorSkin.y;
    v28 = UFG::RenderWorld::msStageHairSkin->mLightColorSkin.z;
    v29 = UFG::RenderWorld::msStageHairSkin->mLightColorSkin.w;
    *((_DWORD *)v13 + 8) = LODWORD(UFG::RenderWorld::msStageHairSkin->mLightColorSkin.x);
    *((float *)v13 + 9) = v27;
    *((float *)v13 + 10) = v28;
    *((float *)v13 + 11) = v29;
    v4->mSetValueMask.mFlags[0] |= 0x8000ui64;
    v4->mParamValues[15] = v13;
    v30 = (void *)*((_QWORD *)v3 + 145);
    v4->mSetValueMask.mFlags[0] |= 0x80000000000000ui64;
    v4->mParamValues[55] = v30;
    v31 = 1;
  }
  else if ( UFG::RenderWorld::msStageHairSkin->mEnableHairLighting && v2[6] == 114301520 )
  {
    v32 = UFG::RenderWorld::msStageHairSkin->mRasterStateHighlightHandle.mData;
    state_values->mSetValueMask.mFlags[0] |= 0x400ui64;
    state_values->mParamValues[10] = v32;
    v33 = UFG::RenderWorld::msStageHairSkin->mHairAlphaStateHandle.mData;
    v4->mSetValueMask.mFlags[0] |= 0x200ui64;
    v4->mParamValues[9] = v33;
    v34 = *(void **)(*((_QWORD *)override_params_Remote + 5) + 24i64);
    v4->mSetValueMask.mFlags[0] |= 0x800000ui64;
    v4->mParamValues[23] = v34;
    v35 = *(void **)(*((_QWORD *)override_params_Remote + 1) + 32i64);
    v4->mSetValueMask.mFlags[0] |= 0x400000000000ui64;
    v4->mParamValues[46] = v35;
    if ( *((_BYTE *)override_params_Remote + 1152) )
    {
      v36 = *(void **)(*((_QWORD *)override_params_Remote + 19) + 24i64);
      v4->mSetValueMask.mFlags[0] |= 0x2000000000000ui64;
      v4->mParamValues[49] = v36;
    }
    else
    {
      v37 = gDefaultBlackTexture.mData;
      v4->mSetValueMask.mFlags[0] |= 0x2000000000000ui64;
      v4->mParamValues[49] = v37;
    }
    v38 = UFG::RenderWorld::msStageHairSkin->mHairShaderHandle.mData;
    v4->mSetValueMask.mFlags[0] |= 2ui64;
    v4->mParamValues[1] = v38;
    v39 = UFG::TimeOfDayManager::GetInstance();
    UFG::TimeOfDayManager::IsSunShining(v39, *((CB_EnvironmentSettings **)v3 + 145));
    v40 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x80u, 0x10u);
    v41 = UFG::RenderWorld::msStageHairSkin->mLightDirWorldHair.y;
    v42 = UFG::RenderWorld::msStageHairSkin->mLightDirWorldHair.z;
    v43 = UFG::RenderWorld::msStageHairSkin->mLightDirWorldHair.w;
    *(float *)v40 = UFG::RenderWorld::msStageHairSkin->mLightDirWorldHair.x;
    *((float *)v40 + 1) = v41;
    *((float *)v40 + 2) = v42;
    *((float *)v40 + 3) = v43;
    v44 = UFG::RenderWorld::msStageHairSkin->mLightDirViewHair.y;
    v45 = UFG::RenderWorld::msStageHairSkin->mLightDirViewHair.z;
    v46 = UFG::RenderWorld::msStageHairSkin->mLightDirViewHair.w;
    *((_DWORD *)v40 + 4) = LODWORD(UFG::RenderWorld::msStageHairSkin->mLightDirViewHair.x);
    *((float *)v40 + 5) = v44;
    *((float *)v40 + 6) = v45;
    *((float *)v40 + 7) = v46;
    v47 = UFG::RenderWorld::msStageHairSkin;
    v48 = UFG::RenderWorld::msStageHairSkin->mHairMaxIntensity;
    v49 = (float)((float)((float)((float)(UFG::RenderWorld::msStageHairSkin->mLightColorHair.y * 0.5)
                                + (float)(UFG::RenderWorld::msStageHairSkin->mLightColorHair.x * 0.30000001))
                        + (float)(UFG::RenderWorld::msStageHairSkin->mLightColorHair.z * 0.2))
                + (float)(UFG::RenderWorld::msStageHairSkin->mLightColorHair.w * 0.0))
        + 0.000099999997;
    if ( v48 >= (float)(v49 * UFG::RenderWorld::msStageHairSkin->mHairIntensity) )
      v48 = v49 * UFG::RenderWorld::msStageHairSkin->mHairIntensity;
    v50 = powf(v48, UFG::RenderWorld::msStageHairSkin->mHairIntensityPower);
    v51 = (float)(v50 / v49) * v47->mLightColorHair.x;
    v52 = (float)(v50 / v49) * v47->mLightColorHair.y;
    v53 = (float)(v50 / v49) * v47->mLightColorHair.z;
    *((float *)v40 + 11) = (float)(v50 / v49) * v47->mLightColorHair.w;
    *((float *)v40 + 8) = v51;
    *((float *)v40 + 9) = v52;
    *((float *)v40 + 10) = v53;
    v4->mSetValueMask.mFlags[0] |= 0x8000ui64;
    v4->mParamValues[15] = v40;
    v54 = (void *)*((_QWORD *)v3 + 145);
    v4->mSetValueMask.mFlags[0] |= 0x80000000000000ui64;
    v4->mParamValues[55] = v54;
    v31 = 1;
  }
  else
  {
    v31 = 0;
  }
  return v31;
}

// File Line: 286
// RVA: 0x3F0B0
char __fastcall UFG::RenderStageHairSkin::StateModifier_SSS_Pass2(Illusion::StateValues *state_values, void *override_params_Remote)
{
  _DWORD *v2; // rax
  Illusion::StateValues *v3; // r9
  UFG::qResourceData *v4; // r8
  UFG::qResourceData *v5; // rax
  void *v6; // rcx
  void *v7; // rcx
  UFG::qResourceData *v8; // rcx
  char result; // al
  UFG::qResourceData *v10; // rax
  UFG::qResourceData *v11; // rcx
  void *v12; // rcx
  UFG::qResourceData *v13; // rcx

  v2 = state_values->mParamValues[1];
  v3 = state_values;
  if ( *((_BYTE *)override_params_Remote + 1154) && v2[6] == -824049412 )
  {
    v4 = UFG::RenderWorld::msStageHairSkin->mRasterStateHighlightHandle.mData;
    state_values->mSetValueMask.mFlags[0] |= 0x400ui64;
    state_values->mParamValues[10] = v4;
    v5 = AlphaStateNoneHandle.mData;
    state_values->mSetValueMask.mFlags[0] |= 0x200ui64;
    state_values->mParamValues[9] = v5;
    v6 = *(void **)(*((_QWORD *)override_params_Remote + 4) + 24i64);
    v3->mSetValueMask.mFlags[0] |= 0x20000ui64;
    v3->mParamValues[17] = v6;
    v7 = *(void **)(*((_QWORD *)override_params_Remote + 1) + 72i64);
    v3->mSetValueMask.mFlags[0] |= 0x800000000000ui64;
    v3->mParamValues[47] = v7;
    v8 = UFG::RenderWorld::msStageHairSkin->mSkinSSShaderPass2Handle.mData;
    v3->mSetValueMask.mFlags[0] |= 2ui64;
    result = 1;
    v3->mParamValues[1] = v8;
  }
  else if ( UFG::RenderWorld::msStageHairSkin->mEnableHairLighting && v2[6] == 114301520 )
  {
    v10 = UFG::RenderWorld::msStageHairSkin->mRasterStateHighlightHandle.mData;
    state_values->mSetValueMask.mFlags[0] |= 0x400ui64;
    state_values->mParamValues[10] = v10;
    v11 = UFG::RenderWorld::msStageHairSkin->mHairAlphaStateHandle.mData;
    v3->mSetValueMask.mFlags[0] |= 0x200ui64;
    v3->mParamValues[9] = v11;
    v12 = *(void **)(*((_QWORD *)override_params_Remote + 4) + 24i64);
    v3->mSetValueMask.mFlags[0] |= 0x800000ui64;
    v3->mParamValues[23] = v12;
    v13 = UFG::RenderWorld::msStageHairSkin->mHairShaderPass2Handle.mData;
    v3->mSetValueMask.mFlags[0] |= 2ui64;
    result = 1;
    v3->mParamValues[1] = v13;
  }
  else
  {
    result = 0;
  }
  return result;
}

// File Line: 339
// RVA: 0x3DEC0
void __fastcall UFG::RenderStageHairSkin::DrawSSSModels(UFG::RenderStageHairSkin *this, UFG::RenderContext *render_context, Render::View *view, int pass, CullLayer *composite_cull_layer)
{
  Render::View *v5; // r12
  Illusion::SubmitContext *v6; // r8
  UFG::RenderContext *v7; // rbx
  UFG::RenderStageHairSkin *v8; // r15
  CullLayer *v9; // rdx
  __int64 v10; // r9
  UFG::qSNode<CullResultBucket,CullResultBucket> *v11; // rcx
  UFG::qSNode<CullResultBucket,CullResultBucket> *v12; // rdi
  unsigned int v13; // ebp
  UFG::qSNode<CullResultBucket,CullResultBucket> *v14; // rsi
  int v15; // eax
  float v16; // xmm1_4
  float v17; // xmm4_4
  float v18; // xmm5_4
  float v19; // xmm6_4
  float v20; // xmm7_4
  float v21; // xmm2_4
  float v22; // xmm3_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm0_4
  float v28; // xmm1_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  float sunBoost; // ST28_4
  UFG::qVector4 *v32; // rax
  float v33; // xmm0_4
  float v34; // xmm1_4
  float v35; // xmm2_4
  __int128 v36; // xmm3
  _OWORD *v37; // rdx
  __int128 v38; // xmm2
  __int128 v39; // xmm1
  float v40; // xmm0_4
  __int64 lightRadiusBoost; // [rsp+20h] [rbp-128h]
  UFG::qMatrix44 m; // [rsp+40h] [rbp-108h]
  UFG::qVector4 result; // [rsp+80h] [rbp-C8h]
  UFG::qMatrix44 d; // [rsp+90h] [rbp-B8h]
  UFG::RenderContext *v45; // [rsp+158h] [rbp+10h]
  Illusion::SubmitContext *v46; // [rsp+160h] [rbp+18h]
  int v47; // [rsp+168h] [rbp+20h]
  char composite_cull_layera; // [rsp+170h] [rbp+28h]

  v47 = pass;
  v45 = render_context;
  v5 = view;
  v6 = view->mSubmitContext;
  v7 = render_context;
  v8 = this;
  v46 = v6;
  if ( pass )
    LODWORD(v6[1].mStateValues.mParamValues[2]) = 2;
  else
    LODWORD(v6[1].mStateValues.mParamValues[2]) = 1;
  v9 = composite_cull_layer;
  if ( composite_cull_layer )
  {
    v10 = v7->mMainViewSettings.mCullIndex;
    composite_cull_layera = 1;
    if ( (signed int)v10 >= 0 && (signed int)v10 <= 16 && v9->mDrawEnabled )
      v11 = v9->mCullResultBuckets[v10].mHead;
    else
      v11 = 0i64;
    v12 = v11;
    v13 = 0;
    if ( v11 )
    {
      do
      {
        v14 = v12[v13 + 3].mNext;
        v15 = UFG::CompositeDrawableComponent::GetMainViewLOD((UFG::CompositeDrawableComponent *)v12[v13 + 3].mNext);
        if ( v14[168].mNext[25].mNext
          && !v15
          && (v7->mMainViewSettings.mCullIndex >= 6
           || *((float *)&v14[157].mNext[2].mNext + v7->mMainViewSettings.mCullIndex) < 10.0) )
        {
          if ( composite_cull_layera && !v47 )
          {
            v16 = v5->mViewWorld.v0.y;
            v17 = v5->mViewWorld.v2.x;
            v18 = v5->mViewWorld.v2.y;
            v19 = v5->mViewWorld.v2.z;
            v20 = v5->mViewWorld.v2.w;
            v21 = v5->mViewWorld.v3.z;
            v22 = v5->mViewWorld.v3.w;
            m.v0.x = v5->mViewWorld.v0.x;
            v23 = v5->mViewWorld.v0.z;
            m.v0.y = v16;
            v24 = v5->mViewWorld.v0.w;
            m.v0.z = v23;
            v25 = v5->mViewWorld.v1.x;
            m.v0.w = v24;
            v26 = v5->mViewWorld.v1.y;
            m.v1.x = v25;
            v27 = v5->mViewWorld.v1.z;
            m.v1.y = v26;
            v28 = v5->mViewWorld.v1.w;
            m.v1.z = v27;
            v29 = v5->mViewWorld.v3.x;
            m.v1.w = v28;
            v30 = v5->mViewWorld.v3.y;
            m.v2.x = v17;
            m.v2.y = v18;
            m.v2.z = v19;
            m.v2.w = v20;
            m.v3.x = v29 - (float)(v17 * 1.5);
            m.v3.y = v30 - (float)(v18 * 1.5);
            m.v3.z = v21 - (float)(v19 * 1.5);
            m.v3.w = v22 - (float)(v20 * 1.5);
            UFG::qInverseAffine(&d, &m);
            sunBoost = v8->mHairIntensityFromSun;
            *(float *)&lightRadiusBoost = v8->mHairIntensityFromLights;
            UFG::RenderStageAO::GetSignificantLightDirection(&m, &d, v45->mEnvState, 0, lightRadiusBoost);
            v32 = UFG::operator*(&result, &v8->mLightDirWorldHair, &v5->mSettings->mWorldView);
            v7 = v45;
            composite_cull_layera = 0;
            v33 = v32->y;
            v34 = v32->z;
            v35 = v32->w;
            v8->mLightDirViewHair.x = v32->x;
            v8->mLightDirViewHair.y = v33;
            v8->mLightDirViewHair.z = v34;
            v8->mLightDirViewHair.w = v35;
          }
          v8->mbCalcLightDirSkin = 1;
          v36 = *(_OWORD *)&v14[162].mNext;
          v37 = (_OWORD *)&v8->mSkinLocalWorld.v0.x;
          v38 = *(_OWORD *)&v14[164].mNext;
          v39 = *(_OWORD *)&v14[166].mNext;
          *v37 = *(_OWORD *)&v14[160].mNext;
          v40 = s_fHeightOffset;
          v37[1] = v36;
          v37[2] = v38;
          v37[3] = v39;
          v8->mSkinLocalWorld.v3.z = v40 + v8->mSkinLocalWorld.v3.z;
          UFG::qInverseAffine(&v8->mSkinLocalWorldInv, &v8->mSkinLocalWorld);
          UFG::CompositeDrawableComponent::Draw((UFG::CompositeDrawableComponent *)v14, v5);
        }
        if ( ++v13 == LODWORD(v12[1].mNext) )
        {
          v12 = v12->mNext;
          v13 = 0;
        }
      }
      while ( v12 );
      LODWORD(v46[1].mStateValues.mParamValues[2]) = 0;
    }
    else
    {
      LODWORD(v6[1].mStateValues.mParamValues[2]) = 0;
    }
  }
  else
  {
    LODWORD(v6[1].mStateValues.mParamValues[2]) = 0;
  }
}

// File Line: 399
// RVA: 0x3E460
void __fastcall UFG::RenderStageHairSkin::Render(UFG::RenderStageHairSkin *this, UFG::RenderContext *render_context, UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list, CullLayer *composite_cull_layer)
{
  CullLayer *v4; // r15
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v5; // rbx
  UFG::RenderContext *v6; // rsi
  UFG::RenderStageHairSkin *v7; // r14
  UFG::qMatrix44 *v8; // rbx
  UFG::qMatrix44 *v9; // rdi
  unsigned __int16 v10; // ax
  CB_EnvironmentSettings *v11; // rbx
  Illusion::StateValues *v12; // rax
  Illusion::StateArgs *v13; // rbx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v14; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v15; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v16; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v17; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v18; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v19; // rax
  Render::cbExternalViewTransformState arg; // [rsp+50h] [rbp-88h]
  RenderQueueLayer v21; // [rsp+1F8h] [rbp+120h]
  LayerSubmitContext ptr; // [rsp+2D8h] [rbp+200h]
  UFG::RenderContext *v23; // [rsp+F58h] [rbp+E80h]
  int v24; // [rsp+F60h] [rbp+E88h]
  Illusion::StateArgs *v25; // [rsp+F98h] [rbp+EC0h]

  v4 = composite_cull_layer;
  v5 = serialization_list;
  v6 = render_context;
  v7 = this;
  RenderQueueLayer::RenderQueueLayer((RenderQueueLayer *)((char *)&v21 + 40));
  LayerSubmitContext::LayerSubmitContext(&ptr);
  ptr.vfptr = (Illusion::SubmitContextVtbl *)&UFG::HairSkinSubmitContext::`vftable';
  v23 = v6;
  v21.mSerializationList = v5;
  ptr.mRenderQueueProvider = &v21;
  ptr.mQueueMode = 0;
  v24 = 0;
  Render::View::View(
    (Render::View *)&arg.mStateParamIndex,
    &v6->mMainViewSettings,
    (Illusion::SubmitContext *)&ptr.vfptr);
  v8 = *(UFG::qMatrix44 **)&arg.mStateParamIndex;
  v9 = (UFG::qMatrix44 *)(*(_QWORD *)&arg.mStateParamIndex + 64i64);
  arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mCallback = 0i64;
  arg.mStateParamIndex = Render::cbExternalViewTransformState::sStateParamIndex;
  *(_WORD *)&arg.mFlags = 1;
  if ( (_WORD)Render::cbExternalViewTransformState::sStateParamIndex == -1 )
  {
    v10 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbExternalViewTransform");
    Render::cbExternalViewTransformState::sStateParamIndex = v10;
    arg.mStateParamIndex = v10;
  }
  arg.mWorldView = v8;
  arg.mProjection = v9;
  arg.mNext = 0i64;
  Render::View::BeginTarget(
    (Render::View *)&arg.mStateParamIndex,
    v6->mDynamicRangeTarget,
    "SkinAndHairIntoScratchBuffer",
    0,
    0,
    0i64,
    0,
    0,
    0,
    0);
  if ( v7->mEnableHairLighting )
    Render::View::Clear((Render::View *)&arg.mStateParamIndex, &UFG::qColour::Zero, 1u, 1.0, 0);
  v11 = v6->mEnvState;
  v12 = Render::View::GetStateValues((Render::View *)&arg.mStateParamIndex);
  v12->mSetValueMask.mFlags[0] |= 0x80000000000000ui64;
  v12->mParamValues[55] = v11;
  v13 = Render::View::GetStateArgs((Render::View *)&arg.mStateParamIndex);
  Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(v13, &arg);
  UFG::RenderStageHairSkin::DrawSSSModels(v7, v6, (Render::View *)&arg.mStateParamIndex, 0, v4);
  v14 = arg.mPrev;
  v15 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v15->mPrev = v14;
  arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mIsSet = 0;
  if ( (Illusion::StateArgs *)v13->mStateArgsCreateMask.mFlags[2 * (arg.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v13 + 16 * (arg.mStateParamIndex + 3i64)) )
    v13->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
  Render::View::EndTarget((Render::View *)&arg.mStateParamIndex);
  Render::View::BeginTarget(
    (Render::View *)&arg.mStateParamIndex,
    v6->mLightBufferTarget,
    "SkinAndHairIntoLightBuffer",
    0,
    0,
    0i64,
    0,
    0,
    0,
    0);
  Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(v13, &arg);
  UFG::RenderStageHairSkin::DrawSSSModels(v7, v6, (Render::View *)&arg.mStateParamIndex, 1, v4);
  v16 = arg.mPrev;
  v17 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v17->mPrev = v16;
  arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mIsSet = 0;
  if ( (Illusion::StateArgs *)v13->mStateArgsCreateMask.mFlags[2 * (arg.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v13 + 16 * (arg.mStateParamIndex + 3i64)) )
    v13->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
  Render::View::EndTarget((Render::View *)&arg.mStateParamIndex);
  v18 = arg.mPrev;
  v19 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v19->mPrev = v18;
  arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  v25 = &ptr.mStateArgs;
  `eh vector destructor iterator'(
    ptr.mStateArgs.mStateArgs,
    0x10ui64,
    128,
    (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
  RenderQueueLayer::~RenderQueueLayer(&v21);
}

// File Line: 456
// RVA: 0x3E310
Illusion::RenderQueue *__fastcall UFG::HairBlurSubmitContext::OnPreSubmit(UFG::HairBlurSubmitContext *this, UFG::qMemoryStream<Illusion::Shader,1160> *shader_stream, UFG::BitFlags128 *already_called_funcs_mask)
{
  UFG::HairBlurSubmitContext *v3; // rbx
  UFG::BitFlags128 *v4; // rsi
  UFG::qMemoryStream<Illusion::Shader,1160> *v5; // rdi
  UFG::qResourceData *v6; // rax
  UFG::qResourceData *v7; // rcx
  UFG::qResourceData *v8; // rax
  Illusion::Texture *v9; // rax

  v3 = this;
  v4 = already_called_funcs_mask;
  v5 = shader_stream;
  if ( !UFG::RenderWorld::msStageHairSkin->mEnableHairLighting
    || *((_DWORD *)this->mStateValues.mParamValues[1] + 6) != 114301520 )
  {
    return 0i64;
  }
  v6 = UFG::RenderWorld::msStageHairSkin->mHairBlurShaderHandle.mData;
  this->mStateValues.mSetValueMask.mFlags[0] |= 2ui64;
  this->mStateValues.mParamValues[1] = v6;
  v7 = UFG::RenderWorld::msStageHairSkin->mRasterStateHairBlurHandle.mData;
  v3->mStateValues.mSetValueMask.mFlags[0] |= 0x400ui64;
  v3->mStateValues.mParamValues[10] = v7;
  v8 = v3->mAlphaStateHandle.mData;
  v3->mStateValues.mSetValueMask.mFlags[0] |= 0x200ui64;
  v3->mStateValues.mParamValues[9] = v8;
  v9 = v3->mSourceHairBlur;
  v3->mStateValues.mSetValueMask.mFlags[0] |= 0x800000ui64;
  v3->mStateValues.mParamValues[23] = v9;
  Illusion::SubmitContext::LoadShader((Illusion::SubmitContext *)&v3->vfptr, shader_stream);
  return LayerSubmitContext::OnPreSubmit((LayerSubmitContext *)&v3->vfptr, v5, v4);
}

// File Line: 482
// RVA: 0x3E7C0
void __fastcall UFG::RenderStageHairSkin::RenderHairBlur(UFG::RenderStageHairSkin *this, UFG::RenderContext *render_context, Render::View *view, Illusion::Texture *source_hair_blur)
{
  Illusion::Texture *v4; // rbx
  Render::View *v5; // r15
  UFG::RenderContext *v6; // r13
  UFG::qResourceInventory *v7; // rax
  UFG::qResourceWarehouse *v8; // rax
  void *v9; // rcx
  Illusion::SubmitContext *v10; // r12
  unsigned __int16 v11; // ax
  Illusion::StateValues *v12; // rax
  __int64 v13; // rdx
  __int64 *v14; // rcx
  __int64 *v15; // rbx
  unsigned int v16; // edi
  UFG::CompositeDrawableComponent *v17; // rsi
  __int64 v18; // rax
  float v19; // xmm6_4
  int v20; // eax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v21; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v22; // rax
  UFG::qResourceInventory *v23; // rax
  UFG::qResourceWarehouse *v24; // rax
  Render::cbViewTransformState v25; // [rsp+20h] [rbp-B8h]
  __int64 v26; // [rsp+70h] [rbp-68h]
  UFG::qMatrix44 result; // [rsp+98h] [rbp-40h]
  RenderQueueLayer v28; // [rsp+D8h] [rbp+0h]
  LayerSubmitContext ptr; // [rsp+1B8h] [rbp+E0h]
  UFG::RenderContext *v30; // [rsp+E38h] [rbp+D60h]
  Illusion::Texture *v31; // [rsp+E40h] [rbp+D68h]
  UFG::qResourceHandle v32; // [rsp+E48h] [rbp+D70h]
  UFG::qResourceHandle *v33; // [rsp+EC0h] [rbp+DE8h]
  _BYTE *retaddr; // [rsp+ED8h] [rbp+E00h]
  void *v35; // [rsp+EE0h] [rbp+E08h]
  Illusion::SubmitContext *v36; // [rsp+EE0h] [rbp+E08h]
  UFG::qResourceHandle *v37; // [rsp+EE0h] [rbp+E08h]

  v26 = -2i64;
  v4 = source_hair_blur;
  v5 = view;
  v6 = render_context;
  LayerSubmitContext::LayerSubmitContext((LayerSubmitContext *)((char *)&ptr + 40));
  ptr.vfptr = (Illusion::SubmitContextVtbl *)&UFG::HairBlurSubmitContext::`vftable';
  v30 = v6;
  v31 = v4;
  v33 = &v32;
  UFG::qResourceHandle::qResourceHandle(&v32);
  v7 = `UFG::qGetResourceInventory<Illusion::AlphaState>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::AlphaState>'::`2'::result )
  {
    v8 = UFG::qResourceWarehouse::Instance();
    v7 = UFG::qResourceWarehouse::GetInventory(v8, 0x12C800F2u);
    `UFG::qGetResourceInventory<Illusion::AlphaState>'::`2'::result = v7;
  }
  UFG::qResourceHandle::Init(&v32, 0x12C800F2u, 0xA3833FDE, v7);
  v9 = Render::View::GetStateValues(v5)->mParamValues[11];
  ptr.mStateValues.mSetValueMask.mFlags[0] |= 0x800ui64;
  ptr.mStateValues.mParamValues[11] = v9;
  ptr.mStateValues.mSetValueMask.mFlags[0] |= 0x400000ui64;
  ptr.mStateValues.mParamValues[22] = v35;
  RenderQueueLayer::RenderQueueLayer(&v28);
  v10 = v5->mSubmitContext;
  v36 = v10;
  ptr.mRenderQueueProvider = (RenderQueueLayer *)v10[1].mStateValues.mParamValues[0];
  ptr.mQueueMode = 0;
  v5->mSubmitContext = (Illusion::SubmitContext *)&ptr;
  UFG::qMatrix44::operator*(&v6->mMainViewSettings.mWorldView, &result, &v6->mMainViewSettings.mProjection);
  UFG::qInverseAffine((UFG::qMatrix44 *)&v25.mScreenOffset, &v6->mMainViewSettings.mWorldView);
  v25.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v25;
  v25.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v25;
  v25.mCallback = 0i64;
  v25.mStateParamIndex = Render::cbViewTransformState::sStateParamIndex;
  *(_WORD *)&v25.mFlags = 1;
  if ( (_WORD)Render::cbViewTransformState::sStateParamIndex == -1 )
  {
    v11 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbViewTransform");
    Render::cbViewTransformState::sStateParamIndex = v11;
    v25.mStateParamIndex = v11;
  }
  v25.mWorldViewProjection = &result;
  v25.mViewWorld = (UFG::qMatrix44 *)&v25.mScreenOffset;
  v25.mProjection = &v6->mMainViewSettings.mProjection;
  v25.mScreenOffset = &Render::View::mScreenOffset;
  v25.mCached_Remote.m_Stream = 0i64;
  v12 = Render::View::GetStateValues(v5);
  Render::cbViewTransformState::SetStateBlock(&v25, v12);
  if ( retaddr )
  {
    v13 = v6->mMainViewSettings.mCullIndex;
    v14 = (__int64 *)((unsigned __int8)((signed int)v13 >= 0 && (signed int)v13 <= 16) & retaddr[32] ? *(_QWORD *)&retaddr[8 * v13 + 80] : 0i64);
    v15 = v14;
    v16 = 0;
    while ( v15 )
    {
      v17 = (UFG::CompositeDrawableComponent *)v15[v16 + 3];
      v18 = v6->mMainViewSettings.mCullIndex;
      if ( (signed int)v18 >= 6 )
        v19 = *(float *)&FLOAT_1_0;
      else
        v19 = v17->mCullResults->mPixelCoverage[v18];
      v20 = UFG::CompositeDrawableComponent::GetLOD((UFG::CompositeDrawableComponent *)v15[v16 + 3], v19);
      if ( v17->mPose->mRigHandle.mData && !v20 && v19 > 8.0 )
        UFG::CompositeDrawableComponent::Draw(v17, v5);
      if ( ++v16 == *((_DWORD *)v15 + 2) )
      {
        v15 = (__int64 *)*v15;
        v16 = 0;
      }
    }
  }
  v5->mSubmitContext = v10;
  v21 = v25.mPrev;
  v22 = v25.mNext;
  v25.mPrev->mNext = v25.mNext;
  v22->mPrev = v21;
  v25.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v25;
  v25.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v25;
  RenderQueueLayer::~RenderQueueLayer(&v28);
  v37 = &v32;
  v23 = `UFG::qGetResourceInventory<Illusion::AlphaState>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::AlphaState>'::`2'::result )
  {
    v24 = UFG::qResourceWarehouse::Instance();
    v23 = UFG::qResourceWarehouse::GetInventory(v24, 0x12C800F2u);
    `UFG::qGetResourceInventory<Illusion::AlphaState>'::`2'::result = v23;
  }
  UFG::qResourceHandle::Close(&v32, v23);
  UFG::qResourceHandle::~qResourceHandle(&v32);
  `eh vector destructor iterator'(
    ptr.mStateArgs.mStateArgs,
    0x10ui64,
    128,
    (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
}

