// File Line: 17
// RVA: 0x14526D0
__int64 dynamic_initializer_for__UFG::qReflectObjectType_Render::UberMaterial_Illusion::rMaterial_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("Render::UberMaterial", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<Render::UberMaterial,Illusion::rMaterial>::sInventory.vfptr,
    "Render::UberMaterial",
    v0);
  UFG::qReflectObjectType<Render::UberMaterial,Illusion::rMaterial>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<Render::UberMaterial>::`vftable;
  UFG::qReflectInventory<Render::UberMaterial>::OnAddToWarehouse(&UFG::qReflectObjectType<Render::UberMaterial,Illusion::rMaterial>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(
    v1,
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<Render::UberMaterial,Illusion::rMaterial>::sInventory.vfptr);
  return atexit(dynamic_atexit_destructor_for__UFG::qReflectObjectType_Render::UberMaterial_Illusion::rMaterial_::sInventory__);
}

// File Line: 18
// RVA: 0x1452650
__int64 dynamic_initializer_for__UFG::qReflectObjectType_Render::CharacterMaterial_Render::UberMaterial_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("Render::CharacterMaterial", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<Render::CharacterMaterial,Render::UberMaterial>::sInventory.vfptr,
    "Render::CharacterMaterial",
    v0);
  UFG::qReflectObjectType<Render::CharacterMaterial,Render::UberMaterial>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<Render::CharacterMaterial>::`vftable;
  UFG::qReflectInventory<Render::CharacterMaterial>::OnAddToWarehouse(&UFG::qReflectObjectType<Render::CharacterMaterial,Render::UberMaterial>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(
    v1,
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<Render::CharacterMaterial,Render::UberMaterial>::sInventory.vfptr);
  return atexit(dynamic_atexit_destructor_for__UFG::qReflectObjectType_Render::CharacterMaterial_Render::UberMaterial_::sInventory__);
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
    OnPropertyChangedMaterial,
    (void (__fastcall *)(char *, void *))OnPropertyChangedMaterial,
    0i64);
  return atexit(dynamic_atexit_destructor_for__UberMaterialNotification__);
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
    OnPropertyChangedMaterial,
    (void (__fastcall *)(char *, void *))OnPropertyChangedMaterial,
    0i64);
  return atexit(dynamic_atexit_destructor_for__CharacterMaterialNotification__);
}

// File Line: 37
// RVA: 0x4A50
void __fastcall Render::UberMaterial::UberMaterial(Render::UberMaterial *this, MemImageLoadFlag f)
{
  Render::UberMaterial *v2; // rdi

  v2 = this;
  Illusion::rMaterial::rMaterial((Illusion::rMaterial *)&this->vfptr, f);
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<Render::UberMaterial,Illusion::rMaterial>::`vftable;
  v2->vfptr = (UFG::qReflectObjectVtbl *)&Render::UberMaterial::`vftable;
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)&v2->DiffuseTexture);
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)&v2->NormalTexture);
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)&v2->GlossinessTexture);
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)&v2->BlendMaskTexture);
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)&v2->mBlendLayer.DiffuseTexture);
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)&v2->mBlendLayer.NormalTexture);
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)&v2->mBlendLayer.GlossinessTexture);
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)&v2->mGrimeLayer.GrimeTexture);
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)&v2->mDetailLayer.DetailNormalTexture);
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)&v2->mReflectionLayer.SphericalEnvTexture);
  *(_QWORD *)&v2->mDebug.mOutput = 0i64;
  v2->mDebug.mIsolateMaterial = 0;
  v2->cbUberParams.VertexInput_PositionScale = 1.0;
  v2->mRenderPass[3].mIsActive = 1;
  Illusion::rMaterial::OnChange((Illusion::rMaterial *)&v2->vfptr);
}

// File Line: 52
// RVA: 0x1452840
__int64 Render::_dynamic_initializer_for__sUberMaterialStaticRenderPass__()
{
  `eh vector constructor iterator(
    &sUberMaterialStaticRenderPass,
    0x20ui64,
    4,
    (void (__fastcall *)(void *))Illusion::ShaderHandle::ShaderHandle);
  return atexit(Render::_dynamic_atexit_destructor_for__sUberMaterialStaticRenderPass__);
}

// File Line: 54
// RVA: 0x57D0
Illusion::eRenderPass::StaticPassData *__fastcall Render::UberMaterial::InitStaticRenderPass(Render::UberMaterial *this)
{
  UFG::qResourceInventory *v1; // rax
  UFG::qResourceWarehouse *v2; // rax
  UFG::qResourceInventory *v3; // rax
  UFG::qResourceWarehouse *v4; // rax
  UFG::qResourceInventory *v5; // rax
  UFG::qResourceWarehouse *v6; // rax
  UFG::qResourceInventory *v7; // rax
  UFG::qResourceWarehouse *v8; // rax

  if ( unk_142128D20 )
    return &sUberMaterialStaticRenderPass;
  v1 = `UFG::qGetResourceInventory<Illusion::Shader>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Shader>::`2::result )
  {
    v2 = UFG::qResourceWarehouse::Instance();
    v1 = UFG::qResourceWarehouse::GetInventory(v2, 0x8B5561A1);
    `UFG::qGetResourceInventory<Illusion::Shader>::`2::result = v1;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&sUberMaterialStaticRenderPass, 0x8B5561A1, 0xBCF15161, v1);
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
void __fastcall Render::UberMaterial::SetStateValuesImpl(Render::UberMaterial *this, Illusion::StateValues *state_values, Illusion::eRenderPass::Enum render_pass)
{
  Render::UberMaterial *v3; // rdi
  Illusion::eRenderPass::Enum v4; // ebp
  Illusion::StateValues *v5; // rbx
  char *v6; // rax
  __int128 *v7; // rdx
  char *v8; // rsi
  char *v9; // rcx
  signed __int64 v10; // r8
  __int128 v11; // xmm0
  Illusion::eAlphaState::Enum v12; // eax
  UFG::qReflectObject *v13; // rax
  UFG::qResourceData *v14; // rax
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

  v3 = this;
  v4 = render_pass;
  v5 = state_values;
  v6 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x1D0u, 0x10u);
  v7 = (__int128 *)&v3->cbUberParams;
  v8 = v6;
  v9 = v6;
  if ( ((unsigned __int8)v6 | (unsigned __int8)((_BYTE)v3 - 112)) & 0xF )
  {
    memmove(v6, v7, 0x1D0ui64);
  }
  else
  {
    v10 = 3i64;
    do
    {
      v11 = *v7;
      v9 += 128;
      v7 += 8;
      *((_OWORD *)v9 - 8) = v11;
      *((_OWORD *)v9 - 7) = *(v7 - 7);
      *((_OWORD *)v9 - 6) = *(v7 - 6);
      *((_OWORD *)v9 - 5) = *(v7 - 5);
      *((_OWORD *)v9 - 4) = *(v7 - 4);
      *((_OWORD *)v9 - 3) = *(v7 - 3);
      *((_OWORD *)v9 - 2) = *(v7 - 2);
      *((_OWORD *)v9 - 1) = *(v7 - 1);
      --v10;
    }
    while ( v10 );
    *(_OWORD *)v9 = *v7;
    *((_OWORD *)v9 + 1) = v7[1];
    *((_OWORD *)v9 + 2) = v7[2];
    *((_OWORD *)v9 + 3) = v7[3];
    *((_OWORD *)v9 + 4) = v7[4];
  }
  v5->mSetValueMask.mFlags[0] |= 0x20000000ui64;
  v5->mParamValues[29] = v8;
  if ( v4 == 3 )
  {
    v12 = v3->mRenderState.AlphaState;
    if ( v12 == 721849354 || v12 == -1145803578 )
    {
      if ( v3->DiffuseTexture.mNameUID )
      {
        v13 = v3->DiffuseTexture.mData;
        if ( v13 )
          v14 = (UFG::qResourceData *)v13[2].mBaseNode.mChildren[1];
        else
          v14 = Illusion::rMaterial::GetDefaultTexture((Illusion::rMaterial *)&v3->vfptr);
        v5->mSetValueMask.mFlags[0] |= 0x20000ui64;
        v5->mParamValues[17] = v14;
      }
    }
    else
    {
      v5->mSetValueMask.mFlags[0] |= 0x20000ui64;
      v5->mParamValues[17] = 0i64;
      v5->mSetValueMask.mFlags[0] &= 0xFFFFFFFFFFFDFFFFui64;
    }
  }
  else
  {
    if ( v3->DiffuseTexture.mNameUID )
    {
      v15 = v3->DiffuseTexture.mData;
      if ( v15 )
        v16 = (UFG::qResourceData *)v15[2].mBaseNode.mChildren[1];
      else
        v16 = Illusion::rMaterial::GetDefaultTexture((Illusion::rMaterial *)&v3->vfptr);
      v5->mSetValueMask.mFlags[0] |= 0x20000ui64;
      v5->mParamValues[17] = v16;
    }
    if ( v3->NormalTexture.mNameUID )
    {
      v17 = v3->NormalTexture.mData;
      if ( v17 )
        v18 = (UFG::qResourceData *)v17[2].mBaseNode.mChildren[1];
      else
        v18 = Illusion::rMaterial::GetDefaultTexture((Illusion::rMaterial *)&v3->vfptr);
      v5->mSetValueMask.mFlags[0] |= 0x40000ui64;
      v5->mParamValues[18] = v18;
    }
    if ( v3->GlossinessTexture.mNameUID )
    {
      v19 = v3->GlossinessTexture.mData;
      if ( v19 )
        v20 = (UFG::qResourceData *)v19[2].mBaseNode.mChildren[1];
      else
        v20 = Illusion::rMaterial::GetDefaultTexture((Illusion::rMaterial *)&v3->vfptr);
      v5->mSetValueMask.mFlags[0] |= 0x80000ui64;
      v5->mParamValues[19] = v20;
    }
    if ( v3->mBlendLayer.mEnable )
    {
      if ( v3->mBlendLayer.DiffuseTexture.mNameUID )
      {
        v21 = v3->mBlendLayer.DiffuseTexture.mData;
        if ( v21 )
          v22 = (UFG::qResourceData *)v21[2].mBaseNode.mChildren[1];
        else
          v22 = Illusion::rMaterial::GetDefaultTexture((Illusion::rMaterial *)&v3->vfptr);
        v5->mSetValueMask.mFlags[0] |= 0x800000ui64;
        v5->mParamValues[23] = v22;
      }
      if ( v3->mBlendLayer.NormalTexture.mNameUID )
      {
        v23 = v3->mBlendLayer.NormalTexture.mData;
        if ( v23 )
          v24 = (UFG::qResourceData *)v23[2].mBaseNode.mChildren[1];
        else
          v24 = Illusion::rMaterial::GetDefaultTexture((Illusion::rMaterial *)&v3->vfptr);
        v5->mSetValueMask.mFlags[0] |= 0x1000000ui64;
        v5->mParamValues[24] = v24;
      }
      if ( v3->mBlendLayer.GlossinessTexture.mNameUID )
      {
        v25 = v3->mBlendLayer.GlossinessTexture.mData;
        if ( v25 )
          v26 = (UFG::qResourceData *)v25[2].mBaseNode.mChildren[1];
        else
          v26 = Illusion::rMaterial::GetDefaultTexture((Illusion::rMaterial *)&v3->vfptr);
        v5->mSetValueMask.mFlags[0] |= 0x2000000ui64;
        v5->mParamValues[25] = v26;
      }
    }
    if ( v3->mGrimeLayer.mEnable && v3->mGrimeLayer.GrimeTexture.mNameUID )
    {
      v27 = v3->mGrimeLayer.GrimeTexture.mData;
      if ( v27 )
        v28 = (UFG::qResourceData *)v27[2].mBaseNode.mChildren[1];
      else
        v28 = Illusion::rMaterial::GetDefaultTexture((Illusion::rMaterial *)&v3->vfptr);
      v5->mSetValueMask.mFlags[0] |= 0x200000ui64;
      v5->mParamValues[21] = v28;
    }
    if ( v3->mDetailLayer.mEnable && v3->mDetailLayer.DetailNormalTexture.mNameUID )
    {
      v29 = v3->mDetailLayer.DetailNormalTexture.mData;
      if ( v29 )
        v30 = (UFG::qResourceData *)v29[2].mBaseNode.mChildren[1];
      else
        v30 = Illusion::rMaterial::GetDefaultTexture((Illusion::rMaterial *)&v3->vfptr);
      v5->mSetValueMask.mFlags[0] |= 0x4000000ui64;
      v5->mParamValues[26] = v30;
    }
    if ( v3->mReflectionLayer.mEnable && v3->mReflectionLayer.SphericalEnvTexture.mNameUID )
    {
      v31 = v3->mReflectionLayer.SphericalEnvTexture.mData;
      if ( v31 )
        v32 = (UFG::qResourceData *)v31[2].mBaseNode.mChildren[1];
      else
        v32 = Illusion::rMaterial::GetDefaultTexture((Illusion::rMaterial *)&v3->vfptr);
      v5->mSetValueMask.mFlags[0] |= 0x8000000ui64;
      v5->mParamValues[27] = v32;
    }
    v33 = v3->BlendMaskTexture.mNameUID == 0;
    v3->cbUberParams.BlendMask_Enable = 0;
    if ( v33 )
    {
      if ( !v3->DiffuseTexture.mNameUID )
        return;
      v34 = v3->DiffuseTexture.mData;
    }
    else
    {
      v3->cbUberParams.BlendMask_Enable = 1;
      if ( !v3->BlendMaskTexture.mNameUID )
        return;
      v34 = v3->BlendMaskTexture.mData;
    }
    if ( v34 )
      v35 = (UFG::qResourceData *)v34[2].mBaseNode.mChildren[1];
    else
      v35 = Illusion::rMaterial::GetDefaultTexture((Illusion::rMaterial *)&v3->vfptr);
    v5->mSetValueMask.mFlags[0] |= 0x400000ui64;
    v5->mParamValues[22] = v35;
  }
}

// File Line: 146
// RVA: 0x5D80
void __fastcall Render::UberMaterial::OnChangeImpl(Render::UberMaterial *this)
{
  Render::eDebugOutput::Enum v1; // eax
  float v2; // xmm6_4
  Render::UberMaterial *v3; // rbx
  UFG::qVector4 *v4; // rax
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  bool v11; // zf
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // eax
  Illusion::eAlphaState::Enum v15; // eax
  float v16; // xmm0_4
  float v17; // xmm0_4
  UFG::qResourceInventory *v18; // rax
  UFG::qResourceWarehouse *v19; // rax
  float v20; // xmm0_4
  int v21; // eax
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

  v1 = Illusion::rMaterial::mDebugOutputAllMaterials;
  v2 = *(float *)&FLOAT_1_0;
  v3 = this;
  if ( this->mDebug.mOutputAllMaterials != Illusion::rMaterial::mDebugOutputAllMaterials )
    v1 = this->mDebug.mOutputAllMaterials;
  Illusion::rMaterial::mDebugOutputAllMaterials = v1;
  v4 = &VectorMask[this->mDiffuseProperties.mTintBlendMask];
  v5 = this->mDiffuseProperties.mTint.g * this->mDiffuseProperties.mTint.g;
  v6 = this->mDiffuseProperties.mTint.b * this->mDiffuseProperties.mTint.b;
  v7 = this->mDiffuseProperties.mTint.a;
  this->cbUberParams.DiffuseTint[0] = this->mDiffuseProperties.mTint.r * this->mDiffuseProperties.mTint.r;
  this->cbUberParams.DiffuseTint[1] = v5;
  this->cbUberParams.DiffuseTint[2] = v6;
  this->cbUberParams.DiffuseTint[3] = v7;
  v8 = v4->y;
  v9 = v4->z;
  v10 = v4->w;
  this->cbUberParams.DiffuseTint_BlendMask[0] = v4->x;
  this->cbUberParams.DiffuseTint_BlendMask[1] = v8;
  this->cbUberParams.DiffuseTint_BlendMask[2] = v9;
  this->cbUberParams.DiffuseTint_BlendMask[3] = v10;
  v11 = this->mGlossinessProperties.mMetallicTint == 0;
  this->cbUberParams.DiffuseTint_Enable = this->mDiffuseProperties.mEnable;
  this->cbUberParams.DiffuseTint_BaseAmount = this->mDiffuseProperties.mTintBaseAmount;
  this->cbUberParams.DiffuseTint_BlendAmount = this->mDiffuseProperties.mTintBlendAmount;
  this->cbUberParams.Glossiness = this->mGlossinessProperties.mGlossiness;
  this->cbUberParams.UseGlossinessTex = this->mGlossinessProperties.mUseGlossinessTex;
  if ( v11 )
  {
    v13 = this->mGlossinessProperties.mMetallic;
    if ( v13 <= 0.050000001 )
    {
      v13 = FLOAT_0_050000001;
    }
    else
    {
      v12 = FLOAT_0_99607843;
      if ( v13 >= 0.99607843 )
        goto LABEL_10;
    }
    v12 = v13;
  }
  else
  {
    v12 = *(float *)&FLOAT_1_0;
  }
LABEL_10:
  v14 = this->mExtraProperties.mNormalMapScale;
  this->cbUberParams.Metallic = v12;
  this->cbUberParams.NormalMapScale = v14;
  this->cbUberParams.EmissiveAmount = this->mEmissiveProperties.mEmissiveAmount;
  this->cbUberParams.EmissiveUseDiffuseAlpha = this->mEmissiveProperties.mEmissiveUseDiffuseAlpha;
  this->cbUberParams.BaseLayer_UVChannel = this->mUVChannel;
  this->cbUberParams.ForceNormalsUp = this->mExtraProperties.mForceNormalsUp;
  v15 = this->mRenderState.AlphaState;
  if ( v15 == 721849354 || v15 == -1145803578 )
    v16 = this->mRenderState.mAlphaClip;
  else
    v16 = 0.0;
  this->cbUberParams.AlphaClip = v16;
  this->cbUberParams.DepthBiasSortLayer[0] = (float)(signed int)this->mRenderState.mDepthBias * 0.00050000002;
  this->cbUberParams.DepthBiasSortLayer[1] = (float)(signed int)this->mRenderState.mDepthBias * 0.000099999997;
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
    v18 = `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::RasterState>::`2::result )
    {
      v19 = UFG::qResourceWarehouse::Instance();
      v18 = UFG::qResourceWarehouse::GetInventory(v19, 0x3BC715E0u);
      `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result = v18;
    }
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v3->mRenderPass[0].mRasterStateHandle.mPrev,
      0x3BC715E0u,
      0xF05AB9A5,
      v18);
  }
  v3->cbUberParams.UVChannelSets[0] = v3->mUVChannels[0].mSet;
  v3->cbUberParams.UVChannelAnimType[0] = v3->mUVChannels[0].mAnimationType;
  v3->cbUberParams.UVChannelScaleOffset[0] = v3->mUVChannels[0].mScaleU;
  v3->cbUberParams.UVChannelScaleOffset[1] = v3->mUVChannels[0].mScaleV;
  v3->cbUberParams.UVChannelScaleOffset[2] = v3->mUVChannels[0].mOffset.x;
  v3->cbUberParams.UVChannelScaleOffset[3] = v3->mUVChannels[0].mOffset.y;
  v3->cbUberParams.UVChannelAnimSpeedNumPages[0] = v3->mUVChannels[0].mAnimSpeed.x;
  v3->cbUberParams.UVChannelAnimSpeedNumPages[1] = v3->mUVChannels[0].mAnimSpeed.y;
  v3->cbUberParams.UVChannelAnimSpeedNumPages[2] = v3->mUVChannels[0].mAnimNumPages.x;
  v3->cbUberParams.UVChannelAnimSpeedNumPages[3] = v3->mUVChannels[0].mAnimNumPages.y;
  v3->cbUberParams.UVChannelSets[1] = v3->mUVChannels[1].mSet;
  v3->cbUberParams.UVChannelAnimType[1] = v3->mUVChannels[1].mAnimationType;
  v3->cbUberParams.UVChannelScaleOffset[4] = v3->mUVChannels[1].mScaleU;
  v3->cbUberParams.UVChannelScaleOffset[5] = v3->mUVChannels[1].mScaleV;
  v3->cbUberParams.UVChannelScaleOffset[6] = v3->mUVChannels[1].mOffset.x;
  v3->cbUberParams.UVChannelScaleOffset[7] = v3->mUVChannels[1].mOffset.y;
  v3->cbUberParams.UVChannelAnimSpeedNumPages[4] = v3->mUVChannels[1].mAnimSpeed.x;
  v3->cbUberParams.UVChannelAnimSpeedNumPages[5] = v3->mUVChannels[1].mAnimSpeed.y;
  v3->cbUberParams.UVChannelAnimSpeedNumPages[6] = v3->mUVChannels[1].mAnimNumPages.x;
  v3->cbUberParams.UVChannelAnimSpeedNumPages[7] = v3->mUVChannels[1].mAnimNumPages.y;
  v3->cbUberParams.UVChannelSets[2] = v3->mUVChannels[2].mSet;
  v3->cbUberParams.UVChannelAnimType[2] = v3->mUVChannels[2].mAnimationType;
  v3->cbUberParams.UVChannelScaleOffset[8] = v3->mUVChannels[2].mScaleU;
  v3->cbUberParams.UVChannelScaleOffset[9] = v3->mUVChannels[2].mScaleV;
  v3->cbUberParams.UVChannelScaleOffset[10] = v3->mUVChannels[2].mOffset.x;
  v3->cbUberParams.UVChannelScaleOffset[11] = v3->mUVChannels[2].mOffset.y;
  v3->cbUberParams.UVChannelAnimSpeedNumPages[8] = v3->mUVChannels[2].mAnimSpeed.x;
  v3->cbUberParams.UVChannelAnimSpeedNumPages[9] = v3->mUVChannels[2].mAnimSpeed.y;
  v3->cbUberParams.UVChannelAnimSpeedNumPages[10] = v3->mUVChannels[2].mAnimNumPages.x;
  v3->cbUberParams.UVChannelAnimSpeedNumPages[11] = v3->mUVChannels[2].mAnimNumPages.y;
  v3->cbUberParams.UVChannelSets[3] = v3->mUVChannels[3].mSet;
  v3->cbUberParams.UVChannelAnimType[3] = v3->mUVChannels[3].mAnimationType;
  v3->cbUberParams.UVChannelScaleOffset[12] = v3->mUVChannels[3].mScaleU;
  v3->cbUberParams.UVChannelScaleOffset[13] = v3->mUVChannels[3].mScaleV;
  v3->cbUberParams.UVChannelScaleOffset[14] = v3->mUVChannels[3].mOffset.x;
  v3->cbUberParams.UVChannelScaleOffset[15] = v3->mUVChannels[3].mOffset.y;
  v3->cbUberParams.UVChannelAnimSpeedNumPages[12] = v3->mUVChannels[3].mAnimSpeed.x;
  v3->cbUberParams.UVChannelAnimSpeedNumPages[13] = v3->mUVChannels[3].mAnimSpeed.y;
  v3->cbUberParams.UVChannelAnimSpeedNumPages[14] = v3->mUVChannels[3].mAnimNumPages.x;
  v3->cbUberParams.UVChannelAnimSpeedNumPages[15] = v3->mUVChannels[3].mAnimNumPages.y;
  if ( v3->mBlendLayer.mUseVertexAlpha )
    v20 = *(float *)&FLOAT_1_0;
  else
    v20 = 0.0;
  v11 = v3->mBlendLayer.mUseDiffuseAlpha == 0;
  v3->cbUberParams.BlendLayer_UseVertexAlpha = v20;
  if ( v11 )
    v2 = 0.0;
  v21 = v3->mBlendLayer.mUVChannel;
  v3->cbUberParams.BlendLayer_UseDiffuseAlpha = v2;
  v3->cbUberParams.BlendLayer_UVChannel = v21;
  v3->cbUberParams.BlendLayer_BlendFalloff = v3->mBlendLayer.mBlendFalloff;
  v22 = &VectorMask[v3->mBlendLayer.mBlendMask];
  v23 = v22->y;
  v24 = v22->z;
  v25 = v22->w;
  v3->cbUberParams.BlendLayer_BlendMask[0] = v22->x;
  v3->cbUberParams.BlendLayer_BlendMask[1] = v23;
  v3->cbUberParams.BlendLayer_BlendMask[2] = v24;
  v3->cbUberParams.BlendLayer_BlendMask[3] = v25;
  v3->cbUberParams.GrimLayer_BaseAmount = v3->mGrimeLayer.mGrimBaseAmount;
  v3->cbUberParams.GrimLayer_BlendAmount = v3->mGrimeLayer.mGrimBlendAmount;
  v3->cbUberParams.GrimeLayer_UVChannel = v3->mGrimeLayer.mUVChannel;
  v26 = &VectorMask[v3->mGrimeLayer.mBlendMask];
  v27 = v26->y;
  v28 = v26->z;
  v29 = v26->w;
  v3->cbUberParams.GrimLayer_BlendMask[0] = v26->x;
  v3->cbUberParams.GrimLayer_BlendMask[1] = v27;
  v3->cbUberParams.GrimLayer_BlendMask[2] = v28;
  v3->cbUberParams.GrimLayer_BlendMask[3] = v29;
  v3->cbUberParams.DetailLayer_BaseAmount = v3->mDetailLayer.mDetailBaseAmount;
  v3->cbUberParams.DetailLayer_BlendAmount = v3->mDetailLayer.mDetailBlendAmount;
  v3->cbUberParams.DetailLayer_UVChannel = v3->mDetailLayer.mUVChannel;
  v30 = &VectorMask[v3->mDetailLayer.mBlendMask];
  v31 = v30->y;
  v32 = v30->z;
  v33 = v30->w;
  v3->cbUberParams.DetailLayer_BlendMask[0] = v30->x;
  v3->cbUberParams.DetailLayer_BlendMask[1] = v31;
  v3->cbUberParams.DetailLayer_BlendMask[2] = v32;
  v3->cbUberParams.DetailLayer_BlendMask[3] = v33;
  v3->cbUberParams.ReflectionLayer_Strength = v3->mReflectionLayer.mReflectionStrength;
  v3->cbUberParams.ReflectionLayer_GlossScale = v3->mReflectionLayer.mReflectionGlossScale;
  v3->cbUberParams.SheenLayer_Enable = v3->mSheenLayer.mEnable;
  v34 = &VectorMask[v3->mSheenLayer.mBlendMask];
  v35 = v34->y;
  v36 = v34->z;
  v37 = v34->w;
  v3->cbUberParams.SheenLayer_BlendMask[0] = v34->x;
  v3->cbUberParams.SheenLayer_BlendMask[1] = v35;
  v3->cbUberParams.SheenLayer_BlendMask[2] = v36;
  v3->cbUberParams.SheenLayer_BlendMask[3] = v37;
  v3->cbUberParams.SheenLayer_RimFalloff = v3->mSheenLayer.mRimFalloff;
  v3->cbUberParams.SheenLayer_RimStrength = v3->mSheenLayer.mRimStrength;
  v3->cbUberParams.SheenLayer_InnerFalloff = v3->mSheenLayer.mInnerFalloff;
  v3->cbUberParams.SheenLayer_InnerStrength = v3->mSheenLayer.mInnerStrength;
  v3->cbUberParams.SheenLayer_DiffuseScale = v3->mSheenLayer.mDiffuseScale;
  v3->cbUberParams.WindLayer_Enable = v3->mWindLayer.mEnable;
  v38 = &VectorMask[v3->mWindLayer.mFlutterVertexColourMask];
  v39 = v38->y;
  v40 = v38->z;
  v41 = v38->w;
  v3->cbUberParams.WindLayer_VertexColourMask[0] = v38->x;
  v3->cbUberParams.WindLayer_VertexColourMask[1] = v39;
  v3->cbUberParams.WindLayer_VertexColourMask[2] = v40;
  v3->cbUberParams.WindLayer_VertexColourMask[3] = v41;
  v3->cbUberParams.WindLayer_SwayScale = v3->mWindLayer.mSwayScale;
  v3->cbUberParams.WindLayer_SwayFrequency = v3->mWindLayer.mSwayFrequency;
  v3->cbUberParams.WindLayer_SwayStiffness = v3->mWindLayer.mSwayStiffness;
  v3->cbUberParams.WindLayer_FlutterScale = v3->mWindLayer.mFlutterScale;
  v3->cbUberParams.WindLayer_FlutterFrequency = v3->mWindLayer.mFlutterFrequency;
  v3->cbUberParams.WindLayer_FlutterSpatialFreq = v3->mWindLayer.mFlutterSpatialFreq;
}

// File Line: 231
// RVA: 0x14527F0
__int64 Render::_dynamic_initializer_for__sCharacterMaterialStaticRenderPass__()
{
  `eh vector constructor iterator(
    &sCharacterMaterialStaticRenderPass,
    0x20ui64,
    4,
    (void (__fastcall *)(void *))Illusion::ShaderHandle::ShaderHandle);
  return atexit(Render::_dynamic_atexit_destructor_for__sCharacterMaterialStaticRenderPass__);
}

// File Line: 234
// RVA: 0x56A0
Illusion::eRenderPass::StaticPassData *__fastcall Render::CharacterMaterial::InitStaticRenderPass(Render::CharacterMaterial *this)
{
  UFG::qResourceInventory *v1; // rax
  UFG::qResourceWarehouse *v2; // rax
  UFG::qResourceInventory *v3; // rax
  UFG::qResourceWarehouse *v4; // rax
  UFG::qResourceInventory *v5; // rax
  UFG::qResourceWarehouse *v6; // rax
  UFG::qResourceInventory *v7; // rax
  UFG::qResourceWarehouse *v8; // rax

  if ( unk_142128DE0 )
    return &sCharacterMaterialStaticRenderPass;
  v1 = `UFG::qGetResourceInventory<Illusion::Shader>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Shader>::`2::result )
  {
    v2 = UFG::qResourceWarehouse::Instance();
    v1 = UFG::qResourceWarehouse::GetInventory(v2, 0x8B5561A1);
    `UFG::qGetResourceInventory<Illusion::Shader>::`2::result = v1;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&sCharacterMaterialStaticRenderPass, 0x8B5561A1, 0x2D2AC914u, v1);
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

