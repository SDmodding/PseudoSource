// File Line: 88
// RVA: 0x3E3D0
Illusion::RenderQueue *__fastcall UFG::HairSkinSubmitContext::OnPreSubmit(
        UFG::HairSkinSubmitContext *this,
        UFG::qMemoryStream<Illusion::Shader,1160> *shader_stream,
        UFG::BitFlags128 *already_called_funcs_mask)
{
  __int32 v6; // ecx
  bool v7; // al

  v6 = this->mStateMode - 1;
  if ( v6 )
  {
    if ( v6 != 1 )
      return 0i64;
    v7 = UFG::RenderStageHairSkin::StateModifier_SSS_Pass2(&this->mStateValues, this->mRenderContext);
  }
  else
  {
    v7 = UFG::RenderStageHairSkin::StateModifier_SSS(&this->mStateValues, this->mRenderContext);
  }
  if ( !v7 )
    return 0i64;
  Illusion::SubmitContext::LoadShader(this, shader_stream);
  return LayerSubmitContext::OnPreSubmit(this, shader_stream, already_called_funcs_mask);
}

// File Line: 127
// RVA: 0x3DE70
void __fastcall UFG::RenderStageHairSkin::Create(UFG::RenderContext *render_context)
{
  UFG::RenderStageHairSkin *v2; // rax

  v2 = (UFG::RenderStageHairSkin *)UFG::qMalloc(0x200ui64, "RenderStageHairSkin", 0i64);
  if ( v2 )
    UFG::RenderStageHairSkin::RenderStageHairSkin(v2, render_context);
}

// File Line: 136
// RVA: 0x3DAD0
void __fastcall UFG::RenderStageHairSkin::RenderStageHairSkin(
        UFG::RenderStageHairSkin *this,
        UFG::RenderContext *render_context)
{
  Illusion::RasterStateHandle *p_mRasterStateHighlightHandle; // rdi
  UFG::qResourceInventory *Inventory; // rax
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

  p_mRasterStateHighlightHandle = &this->mRasterStateHighlightHandle;
  UFG::qResourceHandle::qResourceHandle(&this->mRasterStateHighlightHandle);
  UFG::qResourceHandle::qResourceHandle(&this->mRasterStateHairBlurHandle);
  UFG::qResourceHandle::qResourceHandle(&this->mSkinSSShaderHandle);
  UFG::qResourceHandle::qResourceHandle(&this->mHairShaderHandle);
  UFG::qResourceHandle::qResourceHandle(&this->mSkinSSShaderPass2Handle);
  UFG::qResourceHandle::qResourceHandle(&this->mHairShaderPass2Handle);
  UFG::qResourceHandle::qResourceHandle(&this->mHairBlurShaderHandle);
  UFG::qResourceHandle::qResourceHandle(&this->mHairAlphaStateHandle);
  *(_WORD *)&this->mEnableSSS = 1;
  this->mEnableHairLighting = 1;
  this->mHairIntensity = 0.30000001;
  this->mHairIntensityFromLights = 1.0;
  this->mHairIntensityFromSun = 2.0;
  this->mHairIntensityPower = 0.30000001;
  this->mHairMaxIntensity = 1.0;
  Inventory = `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::RasterState>::`2::result )
  {
    v5 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v5, 0x3BC715E0u);
    `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(p_mRasterStateHighlightHandle, 0x3BC715E0u, 0x455DCC70u, Inventory);
  v6 = `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::RasterState>::`2::result )
  {
    v7 = UFG::qResourceWarehouse::Instance();
    v6 = UFG::qResourceWarehouse::GetInventory(v7, 0x3BC715E0u);
    `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result = v6;
  }
  UFG::qResourceHandle::Init(&this->mRasterStateHairBlurHandle, 0x3BC715E0u, 0x418CAF43u, v6);
  v8 = `UFG::qGetResourceInventory<Illusion::Shader>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Shader>::`2::result )
  {
    v9 = UFG::qResourceWarehouse::Instance();
    v8 = UFG::qResourceWarehouse::GetInventory(v9, 0x8B5561A1);
    `UFG::qGetResourceInventory<Illusion::Shader>::`2::result = v8;
  }
  UFG::qResourceHandle::Init(&this->mSkinSSShaderHandle, 0x8B5561A1, 0x9E96F75B, v8);
  v10 = `UFG::qGetResourceInventory<Illusion::Shader>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Shader>::`2::result )
  {
    v11 = UFG::qResourceWarehouse::Instance();
    v10 = UFG::qResourceWarehouse::GetInventory(v11, 0x8B5561A1);
    `UFG::qGetResourceInventory<Illusion::Shader>::`2::result = v10;
  }
  UFG::qResourceHandle::Init(&this->mSkinSSShaderPass2Handle, 0x8B5561A1, 0x93D5D182, v10);
  v12 = `UFG::qGetResourceInventory<Illusion::Shader>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Shader>::`2::result )
  {
    v13 = UFG::qResourceWarehouse::Instance();
    v12 = UFG::qResourceWarehouse::GetInventory(v13, 0x8B5561A1);
    `UFG::qGetResourceInventory<Illusion::Shader>::`2::result = v12;
  }
  UFG::qResourceHandle::Init(&this->mHairShaderHandle, 0x8B5561A1, 0x6147A81Du, v12);
  v14 = `UFG::qGetResourceInventory<Illusion::Shader>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Shader>::`2::result )
  {
    v15 = UFG::qResourceWarehouse::Instance();
    v14 = UFG::qResourceWarehouse::GetInventory(v15, 0x8B5561A1);
    `UFG::qGetResourceInventory<Illusion::Shader>::`2::result = v14;
  }
  UFG::qResourceHandle::Init(&this->mHairShaderPass2Handle, 0x8B5561A1, 0x6C048EC4u, v14);
  v16 = `UFG::qGetResourceInventory<Illusion::Shader>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Shader>::`2::result )
  {
    v17 = UFG::qResourceWarehouse::Instance();
    v16 = UFG::qResourceWarehouse::GetInventory(v17, 0x8B5561A1);
    `UFG::qGetResourceInventory<Illusion::Shader>::`2::result = v16;
  }
  UFG::qResourceHandle::Init(&this->mHairBlurShaderHandle, 0x8B5561A1, 0x8742ECB1, v16);
  v18 = `UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result )
  {
    v19 = UFG::qResourceWarehouse::Instance();
    v18 = UFG::qResourceWarehouse::GetInventory(v19, 0x12C800F2u);
    `UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result = v18;
  }
  UFG::qResourceHandle::Init(&this->mHairAlphaStateHandle, 0x12C800F2u, 0xC275D439, v18);
}

// File Line: 173
// RVA: 0x3EB70
char __fastcall UFG::RenderStageHairSkin::StateModifier_SSS(
        Illusion::StateValues *state_values,
        char *override_params_Remote)
{
  _DWORD *v2; // rax
  UFG::qResourceData *mData; // r8
  UFG::qResourceData *v6; // rax
  void *v7; // rcx
  void *v8; // rcx
  void *v9; // rcx
  UFG::qResourceData *v10; // rcx
  UFG::TimeOfDayManager *Instance; // rax
  bool IsSunShining; // bl
  char *v13; // r14
  UFG::RenderStageHairSkin *v14; // rax
  UFG::RenderStageHairSkin *v15; // rbx
  UFG::qVector4 *v16; // rax
  float y; // xmm0_4
  float z; // xmm1_4
  float w; // xmm2_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm2_4
  void *v29; // rax
  UFG::qResourceData *v31; // rax
  UFG::qResourceData *v32; // rcx
  void *v33; // rcx
  void *v34; // rcx
  void *v35; // rcx
  UFG::qResourceData *v36; // rax
  UFG::qResourceData *v37; // rcx
  UFG::TimeOfDayManager *v38; // rax
  char *v39; // rbx
  float v40; // xmm0_4
  float v41; // xmm1_4
  float v42; // xmm2_4
  float v43; // xmm0_4
  float v44; // xmm1_4
  float v45; // xmm2_4
  UFG::RenderStageHairSkin *v46; // rbp
  float mHairMaxIntensity; // xmm0_4
  float v48; // xmm6_4
  float v49; // xmm0_4
  float v50; // xmm3_4
  float v51; // xmm2_4
  float v52; // xmm1_4
  void *v53; // rax
  __int64 lightRadiusBoost; // [rsp+20h] [rbp-48h]
  UFG::qVector4 result; // [rsp+40h] [rbp-28h] BYREF

  v2 = state_values->mParamValues[1];
  if ( override_params_Remote[1154] && v2[6] == -824049412 )
  {
    mData = UFG::RenderWorld::msStageHairSkin->mRasterStateHighlightHandle.mData;
    state_values->mSetValueMask.mFlags[0] |= 0x400ui64;
    state_values->mParamValues[10] = mData;
    v6 = AlphaStateNoneHandle.mData;
    state_values->mSetValueMask.mFlags[0] |= 0x200ui64;
    state_values->mParamValues[9] = v6;
    v7 = *(void **)(*((_QWORD *)override_params_Remote + 5) + 24i64);
    state_values->mSetValueMask.mFlags[0] |= 0x20000ui64;
    state_values->mParamValues[17] = v7;
    v8 = *(void **)(*((_QWORD *)override_params_Remote + 1) + 32i64);
    state_values->mSetValueMask.mFlags[0] |= 0x400000000000ui64;
    state_values->mParamValues[46] = v8;
    v9 = *(void **)(*((_QWORD *)override_params_Remote + 1) + 72i64);
    state_values->mSetValueMask.mFlags[0] |= 0x800000000000ui64;
    state_values->mParamValues[47] = v9;
    v10 = UFG::RenderWorld::msStageHairSkin->mSkinSSShaderHandle.mData;
    state_values->mSetValueMask.mFlags[0] |= 2ui64;
    state_values->mParamValues[1] = v10;
    Instance = UFG::TimeOfDayManager::GetInstance();
    IsSunShining = UFG::TimeOfDayManager::IsSunShining(
                     Instance,
                     *((CB_EnvironmentSettings **)override_params_Remote + 145));
    v13 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x80u, 0x10u);
    v14 = UFG::RenderWorld::msStageHairSkin;
    if ( UFG::RenderWorld::msStageHairSkin->mbCalcLightDirSkin )
    {
      *(float *)&lightRadiusBoost = UFG::RenderWorld::msStageHairSkin->mHairIntensityFromLights;
      UFG::RenderStageAO::GetSignificantLightDirection(
        &UFG::RenderWorld::msStageHairSkin->mSkinLocalWorld,
        &UFG::RenderWorld::msStageHairSkin->mSkinLocalWorldInv,
        *((CB_EnvironmentSettings **)override_params_Remote + 145),
        IsSunShining,
        lightRadiusBoost);
      UFG::RenderWorld::msStageHairSkin->mbCalcLightDirSkin = 0;
      v15 = UFG::RenderWorld::msStageHairSkin;
      v16 = UFG::operator*(
              &result,
              &UFG::RenderWorld::msStageHairSkin->mLightDirWorldSkin,
              (UFG::qMatrix44 *)(override_params_Remote + 1008));
      y = v16->y;
      z = v16->z;
      w = v16->w;
      v15->mLightDirViewSkin.x = v16->x;
      v15->mLightDirViewSkin.y = y;
      v15->mLightDirViewSkin.z = z;
      v15->mLightDirViewSkin.w = w;
      v14 = UFG::RenderWorld::msStageHairSkin;
    }
    v20 = v14->mLightDirWorldSkin.y;
    v21 = v14->mLightDirWorldSkin.z;
    v22 = v14->mLightDirWorldSkin.w;
    *(float *)v13 = v14->mLightDirWorldSkin.x;
    *((float *)v13 + 1) = v20;
    *((float *)v13 + 2) = v21;
    *((float *)v13 + 3) = v22;
    v23 = UFG::RenderWorld::msStageHairSkin->mLightDirViewSkin.y;
    v24 = UFG::RenderWorld::msStageHairSkin->mLightDirViewSkin.z;
    v25 = UFG::RenderWorld::msStageHairSkin->mLightDirViewSkin.w;
    *((_DWORD *)v13 + 4) = LODWORD(UFG::RenderWorld::msStageHairSkin->mLightDirViewSkin.x);
    *((float *)v13 + 5) = v23;
    *((float *)v13 + 6) = v24;
    *((float *)v13 + 7) = v25;
    v26 = UFG::RenderWorld::msStageHairSkin->mLightColorSkin.y;
    v27 = UFG::RenderWorld::msStageHairSkin->mLightColorSkin.z;
    v28 = UFG::RenderWorld::msStageHairSkin->mLightColorSkin.w;
    *((_DWORD *)v13 + 8) = LODWORD(UFG::RenderWorld::msStageHairSkin->mLightColorSkin.x);
    *((float *)v13 + 9) = v26;
    *((float *)v13 + 10) = v27;
    *((float *)v13 + 11) = v28;
    state_values->mSetValueMask.mFlags[0] |= 0x8000ui64;
    state_values->mParamValues[15] = v13;
    v29 = (void *)*((_QWORD *)override_params_Remote + 145);
    state_values->mSetValueMask.mFlags[0] |= 0x80000000000000ui64;
    state_values->mParamValues[55] = v29;
    return 1;
  }
  else if ( UFG::RenderWorld::msStageHairSkin->mEnableHairLighting && v2[6] == 114301520 )
  {
    v31 = UFG::RenderWorld::msStageHairSkin->mRasterStateHighlightHandle.mData;
    state_values->mSetValueMask.mFlags[0] |= 0x400ui64;
    state_values->mParamValues[10] = v31;
    v32 = UFG::RenderWorld::msStageHairSkin->mHairAlphaStateHandle.mData;
    state_values->mSetValueMask.mFlags[0] |= 0x200ui64;
    state_values->mParamValues[9] = v32;
    v33 = *(void **)(*((_QWORD *)override_params_Remote + 5) + 24i64);
    state_values->mSetValueMask.mFlags[0] |= 0x800000ui64;
    state_values->mParamValues[23] = v33;
    v34 = *(void **)(*((_QWORD *)override_params_Remote + 1) + 32i64);
    state_values->mSetValueMask.mFlags[0] |= 0x400000000000ui64;
    state_values->mParamValues[46] = v34;
    if ( override_params_Remote[1152] )
    {
      v35 = *(void **)(*((_QWORD *)override_params_Remote + 19) + 24i64);
      state_values->mSetValueMask.mFlags[0] |= 0x2000000000000ui64;
      state_values->mParamValues[49] = v35;
    }
    else
    {
      v36 = gDefaultBlackTexture.mData;
      state_values->mSetValueMask.mFlags[0] |= 0x2000000000000ui64;
      state_values->mParamValues[49] = v36;
    }
    v37 = UFG::RenderWorld::msStageHairSkin->mHairShaderHandle.mData;
    state_values->mSetValueMask.mFlags[0] |= 2ui64;
    state_values->mParamValues[1] = v37;
    v38 = UFG::TimeOfDayManager::GetInstance();
    UFG::TimeOfDayManager::IsSunShining(v38, *((CB_EnvironmentSettings **)override_params_Remote + 145));
    v39 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x80u, 0x10u);
    v40 = UFG::RenderWorld::msStageHairSkin->mLightDirWorldHair.y;
    v41 = UFG::RenderWorld::msStageHairSkin->mLightDirWorldHair.z;
    v42 = UFG::RenderWorld::msStageHairSkin->mLightDirWorldHair.w;
    *(float *)v39 = UFG::RenderWorld::msStageHairSkin->mLightDirWorldHair.x;
    *((float *)v39 + 1) = v40;
    *((float *)v39 + 2) = v41;
    *((float *)v39 + 3) = v42;
    v43 = UFG::RenderWorld::msStageHairSkin->mLightDirViewHair.y;
    v44 = UFG::RenderWorld::msStageHairSkin->mLightDirViewHair.z;
    v45 = UFG::RenderWorld::msStageHairSkin->mLightDirViewHair.w;
    *((_DWORD *)v39 + 4) = LODWORD(UFG::RenderWorld::msStageHairSkin->mLightDirViewHair.x);
    *((float *)v39 + 5) = v43;
    *((float *)v39 + 6) = v44;
    *((float *)v39 + 7) = v45;
    v46 = UFG::RenderWorld::msStageHairSkin;
    mHairMaxIntensity = UFG::RenderWorld::msStageHairSkin->mHairMaxIntensity;
    v48 = (float)((float)((float)((float)(UFG::RenderWorld::msStageHairSkin->mLightColorHair.y * 0.5)
                                + (float)(UFG::RenderWorld::msStageHairSkin->mLightColorHair.x * 0.30000001))
                        + (float)(UFG::RenderWorld::msStageHairSkin->mLightColorHair.z * 0.2))
                + (float)(UFG::RenderWorld::msStageHairSkin->mLightColorHair.w * 0.0))
        + 0.000099999997;
    if ( mHairMaxIntensity >= (float)(v48 * UFG::RenderWorld::msStageHairSkin->mHairIntensity) )
      mHairMaxIntensity = v48 * UFG::RenderWorld::msStageHairSkin->mHairIntensity;
    v49 = powf(mHairMaxIntensity, UFG::RenderWorld::msStageHairSkin->mHairIntensityPower);
    v50 = (float)(v49 / v48) * v46->mLightColorHair.x;
    v51 = (float)(v49 / v48) * v46->mLightColorHair.y;
    v52 = (float)(v49 / v48) * v46->mLightColorHair.z;
    *((float *)v39 + 11) = (float)(v49 / v48) * v46->mLightColorHair.w;
    *((float *)v39 + 8) = v50;
    *((float *)v39 + 9) = v51;
    *((float *)v39 + 10) = v52;
    state_values->mSetValueMask.mFlags[0] |= 0x8000ui64;
    state_values->mParamValues[15] = v39;
    v53 = (void *)*((_QWORD *)override_params_Remote + 145);
    state_values->mSetValueMask.mFlags[0] |= 0x80000000000000ui64;
    state_values->mParamValues[55] = v53;
    return 1;
  }
  else
  {
    return 0;
  }
}

// File Line: 286
// RVA: 0x3F0B0
bool __fastcall UFG::RenderStageHairSkin::StateModifier_SSS_Pass2(
        Illusion::StateValues *state_values,
        _QWORD *override_params_Remote)
{
  _DWORD *v2; // rax
  UFG::qResourceData *mData; // r8
  UFG::qResourceData *v5; // rax
  void *v6; // rcx
  void *v7; // rcx
  UFG::qResourceData *v8; // rcx
  bool result; // al
  UFG::qResourceData *v10; // rax
  UFG::qResourceData *v11; // rcx
  void *v12; // rcx
  UFG::qResourceData *v13; // rcx

  v2 = state_values->mParamValues[1];
  if ( *((_BYTE *)override_params_Remote + 1154) && v2[6] == -824049412 )
  {
    mData = UFG::RenderWorld::msStageHairSkin->mRasterStateHighlightHandle.mData;
    state_values->mSetValueMask.mFlags[0] |= 0x400ui64;
    state_values->mParamValues[10] = mData;
    v5 = AlphaStateNoneHandle.mData;
    state_values->mSetValueMask.mFlags[0] |= 0x200ui64;
    state_values->mParamValues[9] = v5;
    v6 = *(void **)(override_params_Remote[4] + 24i64);
    state_values->mSetValueMask.mFlags[0] |= 0x20000ui64;
    state_values->mParamValues[17] = v6;
    v7 = *(void **)(override_params_Remote[1] + 72i64);
    state_values->mSetValueMask.mFlags[0] |= 0x800000000000ui64;
    state_values->mParamValues[47] = v7;
    v8 = UFG::RenderWorld::msStageHairSkin->mSkinSSShaderPass2Handle.mData;
    state_values->mSetValueMask.mFlags[0] |= 2ui64;
    result = 1;
    state_values->mParamValues[1] = v8;
  }
  else if ( UFG::RenderWorld::msStageHairSkin->mEnableHairLighting && v2[6] == 114301520 )
  {
    v10 = UFG::RenderWorld::msStageHairSkin->mRasterStateHighlightHandle.mData;
    state_values->mSetValueMask.mFlags[0] |= 0x400ui64;
    state_values->mParamValues[10] = v10;
    v11 = UFG::RenderWorld::msStageHairSkin->mHairAlphaStateHandle.mData;
    state_values->mSetValueMask.mFlags[0] |= 0x200ui64;
    state_values->mParamValues[9] = v11;
    v12 = *(void **)(override_params_Remote[4] + 24i64);
    state_values->mSetValueMask.mFlags[0] |= 0x800000ui64;
    state_values->mParamValues[23] = v12;
    v13 = UFG::RenderWorld::msStageHairSkin->mHairShaderPass2Handle.mData;
    state_values->mSetValueMask.mFlags[0] |= 2ui64;
    result = 1;
    state_values->mParamValues[1] = v13;
  }
  else
  {
    return 0;
  }
  return result;
}

// File Line: 339
// RVA: 0x3DEC0
void __fastcall UFG::RenderStageHairSkin::DrawSSSModels(
        UFG::RenderStageHairSkin *this,
        UFG::RenderContext *render_context,
        Render::View *view,
        int pass,
        CullLayer *composite_cull_layer)
{
  Illusion::SubmitContext *mSubmitContext; // r8
  UFG::RenderContext *v7; // rbx
  __int64 mCullIndex; // r9
  UFG::qSNode<CullResultBucket,CullResultBucket> *mHead; // rcx
  UFG::qSNode<CullResultBucket,CullResultBucket> *v12; // rdi
  unsigned int v13; // ebp
  UFG::CompositeDrawableComponent *mNext; // rsi
  unsigned int MainViewLOD; // eax
  float y; // xmm1_4
  float x; // xmm4_4
  float v18; // xmm5_4
  float z; // xmm6_4
  float w; // xmm7_4
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
  UFG::qVector4 *v31; // rax
  float v32; // xmm0_4
  float v33; // xmm1_4
  float v34; // xmm2_4
  UFG::qVector4 v35; // xmm3
  UFG::qVector4 v36; // xmm2
  UFG::qVector4 v37; // xmm1
  float v38; // xmm0_4
  __int64 lightRadiusBoost; // [rsp+20h] [rbp-128h]
  UFG::qMatrix44 m; // [rsp+40h] [rbp-108h] BYREF
  UFG::qVector4 result; // [rsp+80h] [rbp-C8h] BYREF
  UFG::qMatrix44 d; // [rsp+90h] [rbp-B8h] BYREF
  Illusion::SubmitContext *v44; // [rsp+160h] [rbp+18h]
  char composite_cull_layera; // [rsp+170h] [rbp+28h]

  mSubmitContext = view->mSubmitContext;
  v7 = render_context;
  v44 = mSubmitContext;
  if ( pass )
    LODWORD(mSubmitContext[1].mStateValues.mParamValues[2]) = 2;
  else
    LODWORD(mSubmitContext[1].mStateValues.mParamValues[2]) = 1;
  if ( composite_cull_layer )
  {
    mCullIndex = v7->mMainViewSettings.mCullIndex;
    composite_cull_layera = 1;
    if ( (int)mCullIndex >= 0 && (int)mCullIndex <= 16 && composite_cull_layer->mDrawEnabled )
      mHead = composite_cull_layer->mCullResultBuckets[mCullIndex].mHead;
    else
      mHead = 0i64;
    v12 = mHead;
    v13 = 0;
    if ( mHead )
    {
      do
      {
        mNext = (UFG::CompositeDrawableComponent *)v12[v13 + 3].mNext;
        MainViewLOD = (unsigned int)UFG::CompositeDrawableComponent::GetMainViewLOD(mNext);
        if ( mNext->mPose->mRigHandle.mData
          && !MainViewLOD
          && (v7->mMainViewSettings.mCullIndex >= 6
           || mNext->mCullResults->mDistance[v7->mMainViewSettings.mCullIndex] < 10.0) )
        {
          if ( composite_cull_layera && !pass )
          {
            y = view->mViewWorld.v0.y;
            x = view->mViewWorld.v2.x;
            v18 = view->mViewWorld.v2.y;
            z = view->mViewWorld.v2.z;
            w = view->mViewWorld.v2.w;
            v21 = view->mViewWorld.v3.z;
            v22 = view->mViewWorld.v3.w;
            m.v0.x = view->mViewWorld.v0.x;
            v23 = view->mViewWorld.v0.z;
            m.v0.y = y;
            v24 = view->mViewWorld.v0.w;
            m.v0.z = v23;
            v25 = view->mViewWorld.v1.x;
            m.v0.w = v24;
            v26 = view->mViewWorld.v1.y;
            m.v1.x = v25;
            v27 = view->mViewWorld.v1.z;
            m.v1.y = v26;
            v28 = view->mViewWorld.v1.w;
            m.v1.z = v27;
            v29 = view->mViewWorld.v3.x;
            m.v1.w = v28;
            v30 = view->mViewWorld.v3.y;
            m.v2.x = x;
            m.v2.y = v18;
            m.v2.z = z;
            m.v2.w = w;
            m.v3.x = v29 - (float)(x * 1.5);
            m.v3.y = v30 - (float)(v18 * 1.5);
            m.v3.z = v21 - (float)(z * 1.5);
            m.v3.w = v22 - (float)(w * 1.5);
            UFG::qInverseAffine(&d, &m);
            *(float *)&lightRadiusBoost = this->mHairIntensityFromLights;
            UFG::RenderStageAO::GetSignificantLightDirection(&m, &d, render_context->mEnvState, 0, lightRadiusBoost);
            v31 = UFG::operator*(&result, &this->mLightDirWorldHair, &view->mSettings->mWorldView);
            v7 = render_context;
            composite_cull_layera = 0;
            v32 = v31->y;
            v33 = v31->z;
            v34 = v31->w;
            this->mLightDirViewHair.x = v31->x;
            this->mLightDirViewHair.y = v32;
            this->mLightDirViewHair.z = v33;
            this->mLightDirViewHair.w = v34;
          }
          this->mbCalcLightDirSkin = 1;
          v35 = mNext->mPoseRootMatrix.v1;
          v36 = mNext->mPoseRootMatrix.v2;
          v37 = mNext->mPoseRootMatrix.v3;
          this->mSkinLocalWorld.v0 = mNext->mPoseRootMatrix.v0;
          v38 = s_fHeightOffset;
          this->mSkinLocalWorld.v1 = v35;
          this->mSkinLocalWorld.v2 = v36;
          this->mSkinLocalWorld.v3 = v37;
          this->mSkinLocalWorld.v3.z = v38 + this->mSkinLocalWorld.v3.z;
          UFG::qInverseAffine(&this->mSkinLocalWorldInv, &this->mSkinLocalWorld);
          UFG::CompositeDrawableComponent::Draw(mNext, view);
        }
        if ( ++v13 == LODWORD(v12[1].mNext) )
        {
          v12 = v12->mNext;
          v13 = 0;
        }
      }
      while ( v12 );
      LODWORD(v44[1].mStateValues.mParamValues[2]) = 0;
    }
    else
    {
      LODWORD(mSubmitContext[1].mStateValues.mParamValues[2]) = 0;
    }
  }
  else
  {
    LODWORD(mSubmitContext[1].mStateValues.mParamValues[2]) = 0;
  }
}

// File Line: 399
// RVA: 0x3E460
void __fastcall UFG::RenderStageHairSkin::Render(
        UFG::RenderStageHairSkin *this,
        UFG::RenderContext *render_context,
        UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list,
        CullLayer *composite_cull_layer)
{
  UFG::qMatrix44 *v8; // rbx
  UFG::qMatrix44 *v9; // rdi
  unsigned __int16 Param; // ax
  CB_EnvironmentSettings *mEnvState; // rbx
  Illusion::StateValues *StateValues; // rax
  Illusion::StateArgs *StateArgs; // rbx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mPrev; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mNext; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v16; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v17; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v18; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v19; // rax
  Render::cbExternalViewTransformState arg; // [rsp+50h] [rbp-88h] BYREF
  RenderQueueLayer v21; // [rsp+1F8h] [rbp+120h] BYREF
  LayerSubmitContext ptr; // [rsp+2D8h] [rbp+200h] BYREF
  UFG::RenderContext *v23; // [rsp+F58h] [rbp+E80h]
  int v24; // [rsp+F60h] [rbp+E88h]
  Illusion::StateArgs *p_mStateArgs; // [rsp+F98h] [rbp+EC0h]

  RenderQueueLayer::RenderQueueLayer((RenderQueueLayer *)&v21.mTreeLayer0.mTree.mNULL);
  LayerSubmitContext::LayerSubmitContext(&ptr);
  ptr.vfptr = (Illusion::SubmitContextVtbl *)&UFG::HairSkinSubmitContext::`vftable;
  v23 = render_context;
  v21.mSerializationList = serialization_list;
  ptr.mRenderQueueProvider = &v21;
  ptr.mQueueMode = QM_Single;
  v24 = 0;
  Render::View::View((Render::View *)&arg.mStateParamIndex, &render_context->mMainViewSettings, &ptr);
  v8 = *(UFG::qMatrix44 **)&arg.mStateParamIndex;
  v9 = (UFG::qMatrix44 *)(*(_QWORD *)&arg.mStateParamIndex + 64i64);
  arg.mPrev = &arg;
  arg.mNext = &arg;
  arg.mCallback = 0i64;
  arg.mStateParamIndex = Render::cbExternalViewTransformState::sStateParamIndex;
  *(_WORD *)&arg.mFlags = 1;
  if ( (_WORD)Render::cbExternalViewTransformState::sStateParamIndex == 0xFFFF )
  {
    Param = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbExternalViewTransform");
    Render::cbExternalViewTransformState::sStateParamIndex = Param;
    arg.mStateParamIndex = Param;
  }
  arg.mWorldView = v8;
  arg.mProjection = v9;
  arg.mNext = 0i64;
  Render::View::BeginTarget(
    (Render::View *)&arg.mStateParamIndex,
    render_context->mDynamicRangeTarget,
    "SkinAndHairIntoScratchBuffer",
    0,
    0,
    0i64,
    0,
    0,
    0,
    0);
  if ( this->mEnableHairLighting )
    Render::View::Clear((Render::View *)&arg.mStateParamIndex, &UFG::qColour::Zero, 1u, 1.0, 0);
  mEnvState = render_context->mEnvState;
  StateValues = Render::View::GetStateValues((Render::View *)&arg.mStateParamIndex);
  StateValues->mSetValueMask.mFlags[0] |= 0x80000000000000ui64;
  StateValues->mParamValues[55] = mEnvState;
  StateArgs = Render::View::GetStateArgs((Render::View *)&arg.mStateParamIndex);
  Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(StateArgs, &arg);
  UFG::RenderStageHairSkin::DrawSSSModels(
    this,
    render_context,
    (Render::View *)&arg.mStateParamIndex,
    0,
    composite_cull_layer);
  mPrev = arg.mPrev;
  mNext = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  mNext->mPrev = mPrev;
  arg.mPrev = &arg;
  arg.mNext = &arg;
  arg.mIsSet = 0;
  if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[arg.mStateParamIndex].mNode.mNext == &StateArgs->mStateArgs[arg.mStateParamIndex] )
    StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
  Render::View::EndTarget((Render::View *)&arg.mStateParamIndex);
  Render::View::BeginTarget(
    (Render::View *)&arg.mStateParamIndex,
    render_context->mLightBufferTarget,
    "SkinAndHairIntoLightBuffer",
    0,
    0,
    0i64,
    0,
    0,
    0,
    0);
  Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(StateArgs, &arg);
  UFG::RenderStageHairSkin::DrawSSSModels(
    this,
    render_context,
    (Render::View *)&arg.mStateParamIndex,
    1,
    composite_cull_layer);
  v16 = arg.mPrev;
  v17 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v17->mPrev = v16;
  arg.mPrev = &arg;
  arg.mNext = &arg;
  arg.mIsSet = 0;
  if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[arg.mStateParamIndex].mNode.mNext == &StateArgs->mStateArgs[arg.mStateParamIndex] )
    StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
  Render::View::EndTarget((Render::View *)&arg.mStateParamIndex);
  v18 = arg.mPrev;
  v19 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v19->mPrev = v18;
  arg.mPrev = &arg;
  arg.mNext = &arg;
  p_mStateArgs = &ptr.mStateArgs;
  `eh vector destructor iterator(
    ptr.mStateArgs.mStateArgs,
    0x10ui64,
    128,
    (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
  RenderQueueLayer::~RenderQueueLayer(&v21);
}

// File Line: 456
// RVA: 0x3E310
Illusion::RenderQueue *__fastcall UFG::HairBlurSubmitContext::OnPreSubmit(
        UFG::HairBlurSubmitContext *this,
        UFG::qMemoryStream<Illusion::Shader,1160> *shader_stream,
        UFG::BitFlags128 *already_called_funcs_mask)
{
  UFG::qResourceData *mData; // rax
  UFG::qResourceData *v7; // rcx
  UFG::qResourceData *v8; // rax
  Illusion::Texture *mSourceHairBlur; // rax

  if ( !UFG::RenderWorld::msStageHairSkin->mEnableHairLighting
    || *((_DWORD *)this->mStateValues.mParamValues[1] + 6) != 114301520 )
  {
    return 0i64;
  }
  mData = UFG::RenderWorld::msStageHairSkin->mHairBlurShaderHandle.mData;
  this->mStateValues.mSetValueMask.mFlags[0] |= 2ui64;
  this->mStateValues.mParamValues[1] = mData;
  v7 = UFG::RenderWorld::msStageHairSkin->mRasterStateHairBlurHandle.mData;
  this->mStateValues.mSetValueMask.mFlags[0] |= 0x400ui64;
  this->mStateValues.mParamValues[10] = v7;
  v8 = this->mAlphaStateHandle.mData;
  this->mStateValues.mSetValueMask.mFlags[0] |= 0x200ui64;
  this->mStateValues.mParamValues[9] = v8;
  mSourceHairBlur = this->mSourceHairBlur;
  this->mStateValues.mSetValueMask.mFlags[0] |= 0x800000ui64;
  this->mStateValues.mParamValues[23] = mSourceHairBlur;
  Illusion::SubmitContext::LoadShader(this, shader_stream);
  return LayerSubmitContext::OnPreSubmit(this, shader_stream, already_called_funcs_mask);
}

// File Line: 482
// RVA: 0x3E7C0
void __fastcall UFG::RenderStageHairSkin::RenderHairBlur(
        UFG::RenderStageHairSkin *this,
        UFG::RenderContext *render_context,
        Render::View *view,
        Illusion::Texture *source_hair_blur)
{
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v8; // rax
  void *v9; // rcx
  Illusion::SubmitContext *mSubmitContext; // r12
  unsigned __int16 Param; // ax
  Illusion::StateValues *StateValues; // rax
  __int64 mCullIndex; // rdx
  __int64 *v14; // rcx
  __int64 *v15; // rbx
  unsigned int v16; // edi
  UFG::CompositeDrawableComponent *v17; // rsi
  __int64 v18; // rax
  float v19; // xmm6_4
  int LOD; // eax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mPrev; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mNext; // rax
  UFG::qResourceInventory *v23; // rax
  UFG::qResourceWarehouse *v24; // rax
  Render::cbViewTransformState v25; // [rsp+20h] [rbp-B8h] BYREF
  __int64 v26; // [rsp+70h] [rbp-68h]
  UFG::qMatrix44 result; // [rsp+98h] [rbp-40h] BYREF
  RenderQueueLayer v28; // [rsp+D8h] [rbp+0h] BYREF
  LayerSubmitContext ptr; // [rsp+1B8h] [rbp+E0h] BYREF
  UFG::RenderContext *v30; // [rsp+E38h] [rbp+D60h]
  Illusion::Texture *v31; // [rsp+E40h] [rbp+D68h]
  UFG::qResourceHandle v32; // [rsp+E48h] [rbp+D70h] BYREF
  UFG::qResourceHandle *v33; // [rsp+EC0h] [rbp+DE8h]
  _BYTE *retaddr; // [rsp+ED8h] [rbp+E00h]
  void *v35; // [rsp+EE0h] [rbp+E08h]

  v26 = -2i64;
  LayerSubmitContext::LayerSubmitContext((LayerSubmitContext *)&ptr.mStateValues.mParamValues[2]);
  ptr.vfptr = (Illusion::SubmitContextVtbl *)&UFG::HairBlurSubmitContext::`vftable;
  v30 = render_context;
  v31 = source_hair_blur;
  v33 = &v32;
  UFG::qResourceHandle::qResourceHandle(&v32);
  Inventory = `UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result )
  {
    v8 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v8, 0x12C800F2u);
    `UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(&v32, 0x12C800F2u, 0xA3833FDE, Inventory);
  v9 = Render::View::GetStateValues(view)->mParamValues[11];
  ptr.mStateValues.mSetValueMask.mFlags[0] |= 0x800ui64;
  ptr.mStateValues.mParamValues[11] = v9;
  ptr.mStateValues.mSetValueMask.mFlags[0] |= 0x400000ui64;
  ptr.mStateValues.mParamValues[22] = v35;
  RenderQueueLayer::RenderQueueLayer(&v28);
  mSubmitContext = view->mSubmitContext;
  ptr.mRenderQueueProvider = (RenderQueueLayer *)mSubmitContext[1].mStateValues.mParamValues[0];
  ptr.mQueueMode = QM_Single;
  view->mSubmitContext = &ptr;
  UFG::qMatrix44::operator*(
    &render_context->mMainViewSettings.mWorldView,
    &result,
    &render_context->mMainViewSettings.mProjection);
  UFG::qInverseAffine((UFG::qMatrix44 *)&v25.mScreenOffset, &render_context->mMainViewSettings.mWorldView);
  v25.mPrev = &v25;
  v25.mNext = &v25;
  v25.mCallback = 0i64;
  v25.mStateParamIndex = Render::cbViewTransformState::sStateParamIndex;
  *(_WORD *)&v25.mFlags = 1;
  if ( (_WORD)Render::cbViewTransformState::sStateParamIndex == 0xFFFF )
  {
    Param = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbViewTransform");
    Render::cbViewTransformState::sStateParamIndex = Param;
    v25.mStateParamIndex = Param;
  }
  v25.mWorldViewProjection = &result;
  v25.mViewWorld = (UFG::qMatrix44 *)&v25.mScreenOffset;
  v25.mProjection = &render_context->mMainViewSettings.mProjection;
  v25.mScreenOffset = &Render::View::mScreenOffset;
  v25.mCached_Remote.m_Stream = 0i64;
  StateValues = Render::View::GetStateValues(view);
  Render::cbViewTransformState::SetStateBlock(&v25, StateValues);
  if ( retaddr )
  {
    mCullIndex = render_context->mMainViewSettings.mCullIndex;
    v14 = (((int)mCullIndex >= 0 && (int)mCullIndex <= 16) & retaddr[32]) != 0
        ? *(__int64 **)&retaddr[8 * mCullIndex + 80]
        : 0i64;
    v15 = v14;
    v16 = 0;
    while ( v15 )
    {
      v17 = (UFG::CompositeDrawableComponent *)v15[v16 + 3];
      v18 = render_context->mMainViewSettings.mCullIndex;
      if ( (int)v18 >= 6 )
        v19 = *(float *)&FLOAT_1_0;
      else
        v19 = v17->mCullResults->mPixelCoverage[v18];
      LOD = UFG::CompositeDrawableComponent::GetLOD((UFG::CompositeDrawableComponent *)v15[v16 + 3], v19);
      if ( v17->mPose->mRigHandle.mData && !LOD && v19 > 8.0 )
        UFG::CompositeDrawableComponent::Draw(v17, view);
      if ( ++v16 == *((_DWORD *)v15 + 2) )
      {
        v15 = (__int64 *)*v15;
        v16 = 0;
      }
    }
  }
  view->mSubmitContext = mSubmitContext;
  mPrev = v25.mPrev;
  mNext = v25.mNext;
  v25.mPrev->mNext = v25.mNext;
  mNext->mPrev = mPrev;
  v25.mPrev = &v25;
  v25.mNext = &v25;
  RenderQueueLayer::~RenderQueueLayer(&v28);
  v23 = `UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result )
  {
    v24 = UFG::qResourceWarehouse::Instance();
    v23 = UFG::qResourceWarehouse::GetInventory(v24, 0x12C800F2u);
    `UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result = v23;
  }
  UFG::qResourceHandle::Close(&v32, v23);
  UFG::qResourceHandle::~qResourceHandle(&v32);
  `eh vector destructor iterator(
    ptr.mStateArgs.mStateArgs,
    0x10ui64,
    128,
    (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
}

