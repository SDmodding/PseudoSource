// File Line: 17
// RVA: 0x14526D0
__int64 dynamic_initializer_for__UFG::qReflectObjectType_Render::UberMaterial_Illusion::rMaterial_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("Render::UberMaterial", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    &UFG::qReflectObjectType<Render::UberMaterial,Illusion::rMaterial>::sInventory,
    "Render::UberMaterial",
    v0);
  UFG::qReflectObjectType<Render::UberMaterial,Illusion::rMaterial>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<Render::UberMaterial>::`vftable;
  UFG::qReflectInventory<Render::UberMaterial>::OnAddToWarehouse(&UFG::qReflectObjectType<Render::UberMaterial,Illusion::rMaterial>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(v1, &UFG::qReflectObjectType<Render::UberMaterial,Illusion::rMaterial>::sInventory);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::qReflectObjectType_Render::UberMaterial_Illusion::rMaterial_::sInventory__);
}

// File Line: 18
// RVA: 0x1452650
__int64 dynamic_initializer_for__UFG::qReflectObjectType_Render::CharacterMaterial_Render::UberMaterial_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("Render::CharacterMaterial", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    &UFG::qReflectObjectType<Render::CharacterMaterial,Render::UberMaterial>::sInventory,
    "Render::CharacterMaterial",
    v0);
  UFG::qReflectObjectType<Render::CharacterMaterial,Render::UberMaterial>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<Render::CharacterMaterial>::`vftable;
  UFG::qReflectInventory<Render::CharacterMaterial>::OnAddToWarehouse(&UFG::qReflectObjectType<Render::CharacterMaterial,Render::UberMaterial>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(v1, &UFG::qReflectObjectType<Render::CharacterMaterial,Render::UberMaterial>::sInventory);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::qReflectObjectType_Render::CharacterMaterial_Render::UberMaterial_::sInventory__);
}

// File Line: 20
// RVA: 0x14527A0
__int64 dynamic_initializer_for__UberMaterialNotification__()
{
  unsigned __int64 v0; // rax

  v0 = UFG::qStringHash64("Render::UberMaterial", 0xFFFFFFFFFFFFFFFFui64);
  UFG::EditNotification::EditNotification(
    &UberMaterialNotification,
    v0,
    (void (__fastcall *)(char *, UFG::qReflectField *, UFG::qReflectType *, char *, void *))OnPropertyChangedMaterial,
    (void (__fastcall *)(char *, void *))OnPropertyChangedMaterial,
    0i64);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UberMaterialNotification__);
}

// File Line: 21
// RVA: 0x1452750
__int64 dynamic_initializer_for__CharacterMaterialNotification__()
{
  unsigned __int64 v0; // rax

  v0 = UFG::qStringHash64("Render::UberMaterial", 0xFFFFFFFFFFFFFFFFui64);
  UFG::EditNotification::EditNotification(
    &CharacterMaterialNotification,
    v0,
    (void (__fastcall *)(char *, UFG::qReflectField *, UFG::qReflectType *, char *, void *))OnPropertyChangedMaterial,
    (void (__fastcall *)(char *, void *))OnPropertyChangedMaterial,
    0i64);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__CharacterMaterialNotification__);
}

// File Line: 37
// RVA: 0x4A50
void __fastcall Render::UberMaterial::UberMaterial(Render::UberMaterial *this, MemImageLoadFlag f)
{
  Illusion::rMaterial::rMaterial(this, f);
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<Render::UberMaterial,Illusion::rMaterial>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&Render::UberMaterial::`vftable;
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)&this->DiffuseTexture);
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)&this->NormalTexture);
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)&this->GlossinessTexture);
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)&this->BlendMaskTexture);
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)&this->mBlendLayer.DiffuseTexture);
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)&this->mBlendLayer.NormalTexture);
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)&this->mBlendLayer.GlossinessTexture);
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)&this->mGrimeLayer.GrimeTexture);
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)&this->mDetailLayer.DetailNormalTexture);
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)&this->mReflectionLayer.SphericalEnvTexture);
  *(_QWORD *)&this->mDebug.mOutput = 0i64;
  this->mDebug.mIsolateMaterial = 0;
  this->cbUberParams.VertexInput_PositionScale = 1.0;
  this->mRenderPass[3].mIsActive = 1;
  Illusion::rMaterial::OnChange(this);
}

// File Line: 52
// RVA: 0x1452840
__int64 Render::_dynamic_initializer_for__sUberMaterialStaticRenderPass__()
{
  `eh vector constructor iterator(
    (char *)&sUberMaterialStaticRenderPass,
    0x20ui64,
    4,
    (void (__fastcall *)(void *))Illusion::ShaderHandle::ShaderHandle);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__sUberMaterialStaticRenderPass__);
}

// File Line: 54
// RVA: 0x57D0
Illusion::eRenderPass::StaticPassData *__fastcall Render::UberMaterial::InitStaticRenderPass(
        Render::UberMaterial *this)
{
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v2; // rax
  UFG::qResourceInventory *v3; // rax
  UFG::qResourceWarehouse *v4; // rax
  UFG::qResourceInventory *v5; // rax
  UFG::qResourceWarehouse *v6; // rax
  UFG::qResourceInventory *v7; // rax
  UFG::qResourceWarehouse *v8; // rax

  if ( unk_142128D20 )
    return &sUberMaterialStaticRenderPass;
  Inventory = `UFG::qGetResourceInventory<Illusion::Shader>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Shader>::`2::result )
  {
    v2 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v2, 0x8B5561A1);
    `UFG::qGetResourceInventory<Illusion::Shader>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&sUberMaterialStaticRenderPass, 0x8B5561A1, 0xBCF15161, Inventory);
  v3 = `UFG::qGetResourceInventory<Illusion::Shader>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Shader>::`2::result )
  {
    v4 = UFG::qResourceWarehouse::Instance();
    v3 = UFG::qResourceWarehouse::GetInventory(v4, 0x8B5561A1);
    `UFG::qGetResourceInventory<Illusion::Shader>::`2::result = v3;
  }
  UFG::qResourceHandle::Init(&stru_142128D30, 0x8B5561A1, 0xBCF15161, v3);
  v5 = `UFG::qGetResourceInventory<Illusion::Shader>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Shader>::`2::result )
  {
    v6 = UFG::qResourceWarehouse::Instance();
    v5 = UFG::qResourceWarehouse::GetInventory(v6, 0x8B5561A1);
    `UFG::qGetResourceInventory<Illusion::Shader>::`2::result = v5;
  }
  UFG::qResourceHandle::Init(&stru_142128D70, 0x8B5561A1, 0x1F228C2Au, v5);
  v7 = `UFG::qGetResourceInventory<Illusion::Shader>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Shader>::`2::result )
  {
    v8 = UFG::qResourceWarehouse::Instance();
    v7 = UFG::qResourceWarehouse::GetInventory(v8, 0x8B5561A1);
    `UFG::qGetResourceInventory<Illusion::Shader>::`2::result = v7;
  }
  UFG::qResourceHandle::Init(&stru_142128D50, 0x8B5561A1, 0xBA39D8E9, v7);
  return &sUberMaterialStaticRenderPass;
}

// File Line: 69
// RVA: 0x55C0
Illusion::eRenderPass::StaticPassData *__fastcall Render::UberMaterial::GetCustomRenderPass()
{
  return &sUberMaterialStaticRenderPass;
}

// File Line: 75
// RVA: 0x6430
void __fastcall Render::UberMaterial::SetStateValuesImpl(
        Render::UberMaterial *this,
        Illusion::StateValues *state_values,
        Illusion::eRenderPass::Enum render_pass)
{
  char *v6; // rax
  CB_UberParams *p_cbUberParams; // rdx
  char *v8; // rsi
  char *v9; // rcx
  __int64 v10; // r8
  __int128 v11; // xmm0
  Illusion::eAlphaState::Enum AlphaState; // eax
  UFG::qReflectObject *mData; // rax
  UFG::qResourceData *DefaultTexture; // rax
  UFG::qReflectObject *v15; // rax
  UFG::qResourceData *v16; // rax
  UFG::qReflectObject *v17; // rax
  UFG::qResourceData *v18; // rax
  UFG::qReflectObject *v19; // rax
  UFG::qResourceData *v20; // rax
  UFG::qReflectObject *v21; // rax
  UFG::qResourceData *v22; // rax
  UFG::qReflectObject *v23; // rax
  UFG::qResourceData *v24; // rax
  UFG::qReflectObject *v25; // rax
  UFG::qResourceData *v26; // rax
  UFG::qReflectObject *v27; // rax
  UFG::qResourceData *v28; // rax
  UFG::qReflectObject *v29; // rax
  UFG::qResourceData *v30; // rax
  UFG::qReflectObject *v31; // rax
  UFG::qResourceData *v32; // rax
  bool v33; // zf
  UFG::qReflectObject *v34; // rax
  UFG::qResourceData *v35; // rax

  v6 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x1D0u, 0x10u);
  p_cbUberParams = &this->cbUberParams;
  v8 = v6;
  v9 = v6;
  if ( (((unsigned __int8)v6 | (unsigned __int8)((_BYTE)this - 112)) & 0xF) != 0 )
  {
    memmove(v6, p_cbUberParams, 0x1D0ui64);
  }
  else
  {
    v10 = 3i64;
    do
    {
      v11 = *(_OWORD *)p_cbUberParams->DepthBiasSortLayer;
      v9 += 128;
      p_cbUberParams = (CB_UberParams *)((char *)p_cbUberParams + 128);
      *((_OWORD *)v9 - 8) = v11;
      *((_OWORD *)v9 - 7) = *(_OWORD *)&p_cbUberParams[-1].UVChannelAnimSpeedNumPages[12];
      *((_OWORD *)v9 - 6) = *(_OWORD *)p_cbUberParams[-1].DiffuseTint_BlendMask;
      *((_OWORD *)v9 - 5) = *(_OWORD *)p_cbUberParams[-1].BlendLayer_BlendMask;
      *((_OWORD *)v9 - 4) = *(_OWORD *)p_cbUberParams[-1].GrimLayer_BlendMask;
      *((_OWORD *)v9 - 3) = *(_OWORD *)p_cbUberParams[-1].DetailLayer_BlendMask;
      *((_OWORD *)v9 - 2) = *(_OWORD *)p_cbUberParams[-1].SheenLayer_BlendMask;
      *((_OWORD *)v9 - 1) = *(_OWORD *)p_cbUberParams[-1].WindLayer_VertexColourMask;
      --v10;
    }
    while ( v10 );
    *(_OWORD *)v9 = *(_OWORD *)p_cbUberParams->DepthBiasSortLayer;
    *((_OWORD *)v9 + 1) = *(_OWORD *)p_cbUberParams->DiffuseTint;
    *((_OWORD *)v9 + 2) = *(_OWORD *)&p_cbUberParams->Glossiness;
    *((_OWORD *)v9 + 3) = *(_OWORD *)&p_cbUberParams->ForceNormalsUp;
    *((_OWORD *)v9 + 4) = *(_OWORD *)&p_cbUberParams->EmissiveAmount;
  }
  state_values->mSetValueMask.mFlags[0] |= 0x20000000ui64;
  state_values->mParamValues[29] = v8;
  if ( render_pass == Depth )
  {
    AlphaState = this->mRenderState.AlphaState;
    if ( AlphaState == 721849354 || AlphaState == -1145803578 )
    {
      if ( this->DiffuseTexture.mNameUID )
      {
        mData = this->DiffuseTexture.mData;
        if ( mData )
          DefaultTexture = (UFG::qResourceData *)mData[2].mBaseNode.mChildren[1];
        else
          DefaultTexture = Illusion::rMaterial::GetDefaultTexture(this);
        state_values->mSetValueMask.mFlags[0] |= 0x20000ui64;
        state_values->mParamValues[17] = DefaultTexture;
      }
    }
    else
    {
      state_values->mSetValueMask.mFlags[0] |= 0x20000ui64;
      state_values->mParamValues[17] = 0i64;
      state_values->mSetValueMask.mFlags[0] &= ~0x20000ui64;
    }
  }
  else
  {
    if ( this->DiffuseTexture.mNameUID )
    {
      v15 = this->DiffuseTexture.mData;
      if ( v15 )
        v16 = (UFG::qResourceData *)v15[2].mBaseNode.mChildren[1];
      else
        v16 = Illusion::rMaterial::GetDefaultTexture(this);
      state_values->mSetValueMask.mFlags[0] |= 0x20000ui64;
      state_values->mParamValues[17] = v16;
    }
    if ( this->NormalTexture.mNameUID )
    {
      v17 = this->NormalTexture.mData;
      if ( v17 )
        v18 = (UFG::qResourceData *)v17[2].mBaseNode.mChildren[1];
      else
        v18 = Illusion::rMaterial::GetDefaultTexture(this);
      state_values->mSetValueMask.mFlags[0] |= 0x40000ui64;
      state_values->mParamValues[18] = v18;
    }
    if ( this->GlossinessTexture.mNameUID )
    {
      v19 = this->GlossinessTexture.mData;
      if ( v19 )
        v20 = (UFG::qResourceData *)v19[2].mBaseNode.mChildren[1];
      else
        v20 = Illusion::rMaterial::GetDefaultTexture(this);
      state_values->mSetValueMask.mFlags[0] |= 0x80000ui64;
      state_values->mParamValues[19] = v20;
    }
    if ( this->mBlendLayer.mEnable )
    {
      if ( this->mBlendLayer.DiffuseTexture.mNameUID )
      {
        v21 = this->mBlendLayer.DiffuseTexture.mData;
        if ( v21 )
          v22 = (UFG::qResourceData *)v21[2].mBaseNode.mChildren[1];
        else
          v22 = Illusion::rMaterial::GetDefaultTexture(this);
        state_values->mSetValueMask.mFlags[0] |= 0x800000ui64;
        state_values->mParamValues[23] = v22;
      }
      if ( this->mBlendLayer.NormalTexture.mNameUID )
      {
        v23 = this->mBlendLayer.NormalTexture.mData;
        if ( v23 )
          v24 = (UFG::qResourceData *)v23[2].mBaseNode.mChildren[1];
        else
          v24 = Illusion::rMaterial::GetDefaultTexture(this);
        state_values->mSetValueMask.mFlags[0] |= 0x1000000ui64;
        state_values->mParamValues[24] = v24;
      }
      if ( this->mBlendLayer.GlossinessTexture.mNameUID )
      {
        v25 = this->mBlendLayer.GlossinessTexture.mData;
        if ( v25 )
          v26 = (UFG::qResourceData *)v25[2].mBaseNode.mChildren[1];
        else
          v26 = Illusion::rMaterial::GetDefaultTexture(this);
        state_values->mSetValueMask.mFlags[0] |= 0x2000000ui64;
        state_values->mParamValues[25] = v26;
      }
    }
    if ( this->mGrimeLayer.mEnable && this->mGrimeLayer.GrimeTexture.mNameUID )
    {
      v27 = this->mGrimeLayer.GrimeTexture.mData;
      if ( v27 )
        v28 = (UFG::qResourceData *)v27[2].mBaseNode.mChildren[1];
      else
        v28 = Illusion::rMaterial::GetDefaultTexture(this);
      state_values->mSetValueMask.mFlags[0] |= 0x200000ui64;
      state_values->mParamValues[21] = v28;
    }
    if ( this->mDetailLayer.mEnable && this->mDetailLayer.DetailNormalTexture.mNameUID )
    {
      v29 = this->mDetailLayer.DetailNormalTexture.mData;
      if ( v29 )
        v30 = (UFG::qResourceData *)v29[2].mBaseNode.mChildren[1];
      else
        v30 = Illusion::rMaterial::GetDefaultTexture(this);
      state_values->mSetValueMask.mFlags[0] |= 0x4000000ui64;
      state_values->mParamValues[26] = v30;
    }
    if ( this->mReflectionLayer.mEnable && this->mReflectionLayer.SphericalEnvTexture.mNameUID )
    {
      v31 = this->mReflectionLayer.SphericalEnvTexture.mData;
      if ( v31 )
        v32 = (UFG::qResourceData *)v31[2].mBaseNode.mChildren[1];
      else
        v32 = Illusion::rMaterial::GetDefaultTexture(this);
      state_values->mSetValueMask.mFlags[0] |= 0x8000000ui64;
      state_values->mParamValues[27] = v32;
    }
    v33 = this->BlendMaskTexture.mNameUID == 0;
    this->cbUberParams.BlendMask_Enable = 0;
    if ( v33 )
    {
      if ( !this->DiffuseTexture.mNameUID )
        return;
      v34 = this->DiffuseTexture.mData;
    }
    else
    {
      this->cbUberParams.BlendMask_Enable = 1;
      if ( !this->BlendMaskTexture.mNameUID )
        return;
      v34 = this->BlendMaskTexture.mData;
    }
    if ( v34 )
      v35 = (UFG::qResourceData *)v34[2].mBaseNode.mChildren[1];
    else
      v35 = Illusion::rMaterial::GetDefaultTexture(this);
    state_values->mSetValueMask.mFlags[0] |= 0x400000ui64;
    state_values->mParamValues[22] = v35;
  }
}

// File Line: 146
// RVA: 0x5D80
void __fastcall Render::UberMaterial::OnChangeImpl(Render::UberMaterial *this)
{
  Render::eDebugOutput::Enum mOutputAllMaterials; // eax
  float v2; // xmm6_4
  UFG::qVector4 *v4; // rax
  float v5; // xmm2_4
  float v6; // xmm1_4
  float a; // xmm0_4
  float y; // xmm0_4
  float z; // xmm1_4
  float w; // xmm2_4
  bool v11; // zf
  float v12; // xmm1_4
  float mMetallic; // xmm0_4
  float mNormalMapScale; // eax
  Illusion::eAlphaState::Enum AlphaState; // eax
  float mAlphaClip; // xmm0_4
  float v17; // xmm0_4
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v19; // rax
  float v20; // xmm0_4
  int mUVChannel; // eax
  UFG::qVector4 *v22; // rax
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  UFG::qVector4 *v26; // rax
  float v27; // xmm0_4
  float v28; // xmm1_4
  float v29; // xmm2_4
  UFG::qVector4 *v30; // rax
  float v31; // xmm0_4
  float v32; // xmm1_4
  float v33; // xmm2_4
  UFG::qVector4 *v34; // rax
  float v35; // xmm0_4
  float v36; // xmm1_4
  float v37; // xmm2_4
  UFG::qVector4 *v38; // rax
  float v39; // xmm0_4
  float v40; // xmm1_4
  float v41; // xmm2_4

  mOutputAllMaterials = Illusion::rMaterial::mDebugOutputAllMaterials;
  v2 = *(float *)&FLOAT_1_0;
  if ( this->mDebug.mOutputAllMaterials != Illusion::rMaterial::mDebugOutputAllMaterials )
    mOutputAllMaterials = this->mDebug.mOutputAllMaterials;
  Illusion::rMaterial::mDebugOutputAllMaterials = mOutputAllMaterials;
  v4 = &VectorMask[this->mDiffuseProperties.mTintBlendMask];
  v5 = this->mDiffuseProperties.mTint.g * this->mDiffuseProperties.mTint.g;
  v6 = this->mDiffuseProperties.mTint.b * this->mDiffuseProperties.mTint.b;
  a = this->mDiffuseProperties.mTint.a;
  this->cbUberParams.DiffuseTint[0] = this->mDiffuseProperties.mTint.r * this->mDiffuseProperties.mTint.r;
  this->cbUberParams.DiffuseTint[1] = v5;
  this->cbUberParams.DiffuseTint[2] = v6;
  this->cbUberParams.DiffuseTint[3] = a;
  y = v4->y;
  z = v4->z;
  w = v4->w;
  this->cbUberParams.DiffuseTint_BlendMask[0] = v4->x;
  this->cbUberParams.DiffuseTint_BlendMask[1] = y;
  this->cbUberParams.DiffuseTint_BlendMask[2] = z;
  this->cbUberParams.DiffuseTint_BlendMask[3] = w;
  v11 = !this->mGlossinessProperties.mMetallicTint;
  this->cbUberParams.DiffuseTint_Enable = this->mDiffuseProperties.mEnable;
  this->cbUberParams.DiffuseTint_BaseAmount = this->mDiffuseProperties.mTintBaseAmount;
  this->cbUberParams.DiffuseTint_BlendAmount = this->mDiffuseProperties.mTintBlendAmount;
  this->cbUberParams.Glossiness = this->mGlossinessProperties.mGlossiness;
  this->cbUberParams.UseGlossinessTex = this->mGlossinessProperties.mUseGlossinessTex;
  if ( v11 )
  {
    mMetallic = this->mGlossinessProperties.mMetallic;
    if ( mMetallic <= 0.050000001 )
    {
      mMetallic = FLOAT_0_050000001;
    }
    else
    {
      v12 = FLOAT_0_99607843;
      if ( mMetallic >= 0.99607843 )
        goto LABEL_10;
    }
    v12 = mMetallic;
  }
  else
  {
    v12 = *(float *)&FLOAT_1_0;
  }
LABEL_10:
  mNormalMapScale = this->mExtraProperties.mNormalMapScale;
  this->cbUberParams.Metallic = v12;
  this->cbUberParams.NormalMapScale = mNormalMapScale;
  *(Render::EmissiveProperties *)&this->cbUberParams.EmissiveAmount = this->mEmissiveProperties;
  this->cbUberParams.BaseLayer_UVChannel = this->mUVChannel;
  this->cbUberParams.ForceNormalsUp = this->mExtraProperties.mForceNormalsUp;
  AlphaState = this->mRenderState.AlphaState;
  if ( AlphaState == 721849354 || AlphaState == -1145803578 )
    mAlphaClip = this->mRenderState.mAlphaClip;
  else
    mAlphaClip = 0.0;
  this->cbUberParams.AlphaClip = mAlphaClip;
  this->cbUberParams.DepthBiasSortLayer[0] = (float)this->mRenderState.mDepthBias * 0.00050000002;
  this->cbUberParams.DepthBiasSortLayer[1] = (float)this->mRenderState.mDepthBias * 0.000099999997;
  if ( this->mRenderState.mDecalLayer )
  {
    if ( this->mRenderState.AlphaState == 0xEDE83382 )
      v17 = FLOAT_2_0;
    else
      v17 = *(float *)&FLOAT_1_0;
  }
  else
  {
    v17 = 0.0;
  }
  this->cbUberParams.DepthBiasSortLayer[2] = v17;
  this->cbUberParams.DepthBiasSortLayer[3] = this->mRenderState.mAlphaDistanceBias;
  if ( this->mRenderState.mDecalLayer )
  {
    Inventory = `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::RasterState>::`2::result )
    {
      v19 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v19, 0x3BC715E0u);
      `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Init(&this->mRenderPass[0].mRasterStateHandle, 0x3BC715E0u, 0xF05AB9A5, Inventory);
  }
  this->cbUberParams.UVChannelSets[0] = this->mUVChannels[0].mSet;
  this->cbUberParams.UVChannelAnimType[0] = this->mUVChannels[0].mAnimationType;
  this->cbUberParams.UVChannelScaleOffset[0] = this->mUVChannels[0].mScaleU;
  this->cbUberParams.UVChannelScaleOffset[1] = this->mUVChannels[0].mScaleV;
  this->cbUberParams.UVChannelScaleOffset[2] = this->mUVChannels[0].mOffset.x;
  this->cbUberParams.UVChannelScaleOffset[3] = this->mUVChannels[0].mOffset.y;
  this->cbUberParams.UVChannelAnimSpeedNumPages[0] = this->mUVChannels[0].mAnimSpeed.x;
  this->cbUberParams.UVChannelAnimSpeedNumPages[1] = this->mUVChannels[0].mAnimSpeed.y;
  this->cbUberParams.UVChannelAnimSpeedNumPages[2] = this->mUVChannels[0].mAnimNumPages.x;
  this->cbUberParams.UVChannelAnimSpeedNumPages[3] = this->mUVChannels[0].mAnimNumPages.y;
  this->cbUberParams.UVChannelSets[1] = this->mUVChannels[1].mSet;
  this->cbUberParams.UVChannelAnimType[1] = this->mUVChannels[1].mAnimationType;
  this->cbUberParams.UVChannelScaleOffset[4] = this->mUVChannels[1].mScaleU;
  this->cbUberParams.UVChannelScaleOffset[5] = this->mUVChannels[1].mScaleV;
  this->cbUberParams.UVChannelScaleOffset[6] = this->mUVChannels[1].mOffset.x;
  this->cbUberParams.UVChannelScaleOffset[7] = this->mUVChannels[1].mOffset.y;
  this->cbUberParams.UVChannelAnimSpeedNumPages[4] = this->mUVChannels[1].mAnimSpeed.x;
  this->cbUberParams.UVChannelAnimSpeedNumPages[5] = this->mUVChannels[1].mAnimSpeed.y;
  this->cbUberParams.UVChannelAnimSpeedNumPages[6] = this->mUVChannels[1].mAnimNumPages.x;
  this->cbUberParams.UVChannelAnimSpeedNumPages[7] = this->mUVChannels[1].mAnimNumPages.y;
  this->cbUberParams.UVChannelSets[2] = this->mUVChannels[2].mSet;
  this->cbUberParams.UVChannelAnimType[2] = this->mUVChannels[2].mAnimationType;
  this->cbUberParams.UVChannelScaleOffset[8] = this->mUVChannels[2].mScaleU;
  this->cbUberParams.UVChannelScaleOffset[9] = this->mUVChannels[2].mScaleV;
  this->cbUberParams.UVChannelScaleOffset[10] = this->mUVChannels[2].mOffset.x;
  this->cbUberParams.UVChannelScaleOffset[11] = this->mUVChannels[2].mOffset.y;
  this->cbUberParams.UVChannelAnimSpeedNumPages[8] = this->mUVChannels[2].mAnimSpeed.x;
  this->cbUberParams.UVChannelAnimSpeedNumPages[9] = this->mUVChannels[2].mAnimSpeed.y;
  this->cbUberParams.UVChannelAnimSpeedNumPages[10] = this->mUVChannels[2].mAnimNumPages.x;
  this->cbUberParams.UVChannelAnimSpeedNumPages[11] = this->mUVChannels[2].mAnimNumPages.y;
  this->cbUberParams.UVChannelSets[3] = this->mUVChannels[3].mSet;
  this->cbUberParams.UVChannelAnimType[3] = this->mUVChannels[3].mAnimationType;
  this->cbUberParams.UVChannelScaleOffset[12] = this->mUVChannels[3].mScaleU;
  this->cbUberParams.UVChannelScaleOffset[13] = this->mUVChannels[3].mScaleV;
  this->cbUberParams.UVChannelScaleOffset[14] = this->mUVChannels[3].mOffset.x;
  this->cbUberParams.UVChannelScaleOffset[15] = this->mUVChannels[3].mOffset.y;
  this->cbUberParams.UVChannelAnimSpeedNumPages[12] = this->mUVChannels[3].mAnimSpeed.x;
  this->cbUberParams.UVChannelAnimSpeedNumPages[13] = this->mUVChannels[3].mAnimSpeed.y;
  this->cbUberParams.UVChannelAnimSpeedNumPages[14] = this->mUVChannels[3].mAnimNumPages.x;
  this->cbUberParams.UVChannelAnimSpeedNumPages[15] = this->mUVChannels[3].mAnimNumPages.y;
  if ( this->mBlendLayer.mUseVertexAlpha )
    v20 = *(float *)&FLOAT_1_0;
  else
    v20 = 0.0;
  v11 = !this->mBlendLayer.mUseDiffuseAlpha;
  this->cbUberParams.BlendLayer_UseVertexAlpha = v20;
  if ( v11 )
    v2 = 0.0;
  mUVChannel = this->mBlendLayer.mUVChannel;
  this->cbUberParams.BlendLayer_UseDiffuseAlpha = v2;
  this->cbUberParams.BlendLayer_UVChannel = mUVChannel;
  this->cbUberParams.BlendLayer_BlendFalloff = this->mBlendLayer.mBlendFalloff;
  v22 = &VectorMask[this->mBlendLayer.mBlendMask];
  v23 = v22->y;
  v24 = v22->z;
  v25 = v22->w;
  this->cbUberParams.BlendLayer_BlendMask[0] = v22->x;
  this->cbUberParams.BlendLayer_BlendMask[1] = v23;
  this->cbUberParams.BlendLayer_BlendMask[2] = v24;
  this->cbUberParams.BlendLayer_BlendMask[3] = v25;
  this->cbUberParams.GrimLayer_BaseAmount = this->mGrimeLayer.mGrimBaseAmount;
  this->cbUberParams.GrimLayer_BlendAmount = this->mGrimeLayer.mGrimBlendAmount;
  this->cbUberParams.GrimeLayer_UVChannel = this->mGrimeLayer.mUVChannel;
  v26 = &VectorMask[this->mGrimeLayer.mBlendMask];
  v27 = v26->y;
  v28 = v26->z;
  v29 = v26->w;
  this->cbUberParams.GrimLayer_BlendMask[0] = v26->x;
  this->cbUberParams.GrimLayer_BlendMask[1] = v27;
  this->cbUberParams.GrimLayer_BlendMask[2] = v28;
  this->cbUberParams.GrimLayer_BlendMask[3] = v29;
  this->cbUberParams.DetailLayer_BaseAmount = this->mDetailLayer.mDetailBaseAmount;
  this->cbUberParams.DetailLayer_BlendAmount = this->mDetailLayer.mDetailBlendAmount;
  this->cbUberParams.DetailLayer_UVChannel = this->mDetailLayer.mUVChannel;
  v30 = &VectorMask[this->mDetailLayer.mBlendMask];
  v31 = v30->y;
  v32 = v30->z;
  v33 = v30->w;
  this->cbUberParams.DetailLayer_BlendMask[0] = v30->x;
  this->cbUberParams.DetailLayer_BlendMask[1] = v31;
  this->cbUberParams.DetailLayer_BlendMask[2] = v32;
  this->cbUberParams.DetailLayer_BlendMask[3] = v33;
  this->cbUberParams.ReflectionLayer_Strength = this->mReflectionLayer.mReflectionStrength;
  this->cbUberParams.ReflectionLayer_GlossScale = this->mReflectionLayer.mReflectionGlossScale;
  this->cbUberParams.SheenLayer_Enable = this->mSheenLayer.mEnable;
  v34 = &VectorMask[this->mSheenLayer.mBlendMask];
  v35 = v34->y;
  v36 = v34->z;
  v37 = v34->w;
  this->cbUberParams.SheenLayer_BlendMask[0] = v34->x;
  this->cbUberParams.SheenLayer_BlendMask[1] = v35;
  this->cbUberParams.SheenLayer_BlendMask[2] = v36;
  this->cbUberParams.SheenLayer_BlendMask[3] = v37;
  this->cbUberParams.SheenLayer_RimFalloff = this->mSheenLayer.mRimFalloff;
  this->cbUberParams.SheenLayer_RimStrength = this->mSheenLayer.mRimStrength;
  this->cbUberParams.SheenLayer_InnerFalloff = this->mSheenLayer.mInnerFalloff;
  this->cbUberParams.SheenLayer_InnerStrength = this->mSheenLayer.mInnerStrength;
  this->cbUberParams.SheenLayer_DiffuseScale = this->mSheenLayer.mDiffuseScale;
  this->cbUberParams.WindLayer_Enable = this->mWindLayer.mEnable;
  v38 = &VectorMask[this->mWindLayer.mFlutterVertexColourMask];
  v39 = v38->y;
  v40 = v38->z;
  v41 = v38->w;
  this->cbUberParams.WindLayer_VertexColourMask[0] = v38->x;
  this->cbUberParams.WindLayer_VertexColourMask[1] = v39;
  this->cbUberParams.WindLayer_VertexColourMask[2] = v40;
  this->cbUberParams.WindLayer_VertexColourMask[3] = v41;
  this->cbUberParams.WindLayer_SwayScale = this->mWindLayer.mSwayScale;
  this->cbUberParams.WindLayer_SwayFrequency = this->mWindLayer.mSwayFrequency;
  this->cbUberParams.WindLayer_SwayStiffness = this->mWindLayer.mSwayStiffness;
  this->cbUberParams.WindLayer_FlutterScale = this->mWindLayer.mFlutterScale;
  this->cbUberParams.WindLayer_FlutterFrequency = this->mWindLayer.mFlutterFrequency;
  this->cbUberParams.WindLayer_FlutterSpatialFreq = this->mWindLayer.mFlutterSpatialFreq;
}

// File Line: 231
// RVA: 0x14527F0
__int64 Render::_dynamic_initializer_for__sCharacterMaterialStaticRenderPass__()
{
  `eh vector constructor iterator(
    (char *)&sCharacterMaterialStaticRenderPass,
    0x20ui64,
    4,
    (void (__fastcall *)(void *))Illusion::ShaderHandle::ShaderHandle);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__sCharacterMaterialStaticRenderPass__);
}

// File Line: 234
// RVA: 0x56A0
Illusion::eRenderPass::StaticPassData *__fastcall Render::CharacterMaterial::InitStaticRenderPass(
        Render::CharacterMaterial *this)
{
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v2; // rax
  UFG::qResourceInventory *v3; // rax
  UFG::qResourceWarehouse *v4; // rax
  UFG::qResourceInventory *v5; // rax
  UFG::qResourceWarehouse *v6; // rax
  UFG::qResourceInventory *v7; // rax
  UFG::qResourceWarehouse *v8; // rax

  if ( unk_142128DE0 )
    return &sCharacterMaterialStaticRenderPass;
  Inventory = `UFG::qGetResourceInventory<Illusion::Shader>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Shader>::`2::result )
  {
    v2 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v2, 0x8B5561A1);
    `UFG::qGetResourceInventory<Illusion::Shader>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(
    (UFG::qResourceHandle *)&sCharacterMaterialStaticRenderPass,
    0x8B5561A1,
    0x2D2AC914u,
    Inventory);
  v3 = `UFG::qGetResourceInventory<Illusion::Shader>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Shader>::`2::result )
  {
    v4 = UFG::qResourceWarehouse::Instance();
    v3 = UFG::qResourceWarehouse::GetInventory(v4, 0x8B5561A1);
    `UFG::qGetResourceInventory<Illusion::Shader>::`2::result = v3;
  }
  UFG::qResourceHandle::Init(&stru_142128DF0, 0x8B5561A1, 0x2D2AC914u, v3);
  v5 = `UFG::qGetResourceInventory<Illusion::Shader>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Shader>::`2::result )
  {
    v6 = UFG::qResourceWarehouse::Instance();
    v5 = UFG::qResourceWarehouse::GetInventory(v6, 0x8B5561A1);
    `UFG::qGetResourceInventory<Illusion::Shader>::`2::result = v5;
  }
  UFG::qResourceHandle::Init(&stru_142128E30, 0x8B5561A1, 0xC495D9CD, v5);
  v7 = `UFG::qGetResourceInventory<Illusion::Shader>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Shader>::`2::result )
  {
    v8 = UFG::qResourceWarehouse::Instance();
    v7 = UFG::qResourceWarehouse::GetInventory(v8, 0x8B5561A1);
    `UFG::qGetResourceInventory<Illusion::Shader>::`2::result = v7;
  }
  UFG::qResourceHandle::Init(&stru_142128E10, 0x8B5561A1, 0x4D9D1983u, v7);
  return &sCharacterMaterialStaticRenderPass;
}

// File Line: 249
// RVA: 0x55B0
Illusion::eRenderPass::StaticPassData *__fastcall Render::CharacterMaterial::GetCustomRenderPass()
{
  return &sCharacterMaterialStaticRenderPass;
}

