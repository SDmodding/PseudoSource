// File Line: 83
// RVA: 0x14568D0
__int64 dynamic_initializer_for__UFG::RenderStagePlugin::s_RenderStagePluginList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::RenderStagePlugin::s_RenderStagePluginList__);
}

// File Line: 84
// RVA: 0x1456830
__int64 dynamic_initializer_for__UFG::RenderStagePlugin::_TypeIDesc__()
{
  UFG::ComponentIDDesc *v0; // rax
  __int64 result; // rax

  v0 = UFG::RenderStagePlugin::AccessComponentDesc();
  *(_DWORD *)&UFG::RenderStagePlugin::_TypeIDesc.mBaseTypeIndex = *(_DWORD *)&v0->mBaseTypeIndex;
  UFG::RenderStagePlugin::_TypeIDesc.mChildBitMask = v0->mChildBitMask;
  result = v0->mChildren;
  UFG::RenderStagePlugin::_TypeIDesc.mChildren = result;
  return result;
}

// File Line: 88
// RVA: 0x5F190
void __fastcall UFG::RenderStagePlugin::RenderStagePlugin(UFG::RenderStagePlugin *this)
{
  UFG::qNode<UFG::RenderStagePlugin,UFG::RenderStagePlugin> *mPrev; // rax

  UFG::SimComponent::SimComponent(this, 0);
  this->mPrev = &this->UFG::qNode<UFG::RenderStagePlugin,UFG::RenderStagePlugin>;
  this->mNext = &this->UFG::qNode<UFG::RenderStagePlugin,UFG::RenderStagePlugin>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::RenderStagePlugin::`vftable;
  UFG::SimComponent::AddType(this, UFG::RenderStagePlugin::_RenderStagePluginTypeUID, "RenderStagePlugin");
  mPrev = UFG::RenderStagePlugin::s_RenderStagePluginList.mNode.mPrev;
  UFG::RenderStagePlugin::s_RenderStagePluginList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::RenderStagePlugin,UFG::RenderStagePlugin>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::RenderStagePlugin,UFG::RenderStagePlugin> *)&UFG::RenderStagePlugin::s_RenderStagePluginList;
  UFG::RenderStagePlugin::s_RenderStagePluginList.mNode.mPrev = &this->UFG::qNode<UFG::RenderStagePlugin,UFG::RenderStagePlugin>;
}

// File Line: 98
// RVA: 0x5FC70
const char *__fastcall UFG::DamagePostEffect::GetTypeName(UFG::DamagePostEffect *this)
{
  return "DamagePostEffect";
}

// File Line: 101
// RVA: 0x5F040
void __fastcall UFG::DamagePostEffect::DamagePostEffect(UFG::DamagePostEffect *this)
{
  char v2; // cl

  UFG::RenderStagePlugin::RenderStagePlugin(this);
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::DamagePostEffect::`vftable;
  *(_QWORD *)&this->mDamageCurrentMagnitude = 0i64;
  UFG::SimComponent::AddType(this, UFG::DamagePostEffect::_DamagePostEffectTypeUID, "DamagePostEffect");
  v2 = sIsStaticInit;
  if ( !sIsStaticInit )
    v2 = 1;
  sIsStaticInit = v2;
}

// File Line: 116
// RVA: 0x5FCD0
void __fastcall UFG::DamagePostEffect::OnDamage(UFG::DamagePostEffect *this, float magnitude)
{
  float v2; // xmm1_4

  v2 = magnitude * 0.1;
  if ( v2 <= 0.0 )
  {
    v2 = 0.0;
  }
  else if ( v2 >= 1.0 )
  {
    LODWORD(this->mDamageCurrentMagnitude) = (_DWORD)FLOAT_1_0;
    return;
  }
  this->mDamageCurrentMagnitude = v2;
}

// File Line: 124
// RVA: 0x5FED0
void __fastcall UFG::DamagePostEffect::RenderPostEffect(
        UFG::DamagePostEffect *this,
        UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list,
        UFG::RenderContext *render_context,
        float delta_time,
        Illusion::Target **curr_target,
        Illusion::Target **scratch_target)
{
  float v7; // xmm6_4
  Illusion::Material *mMaterial; // rdi
  _WORD *v9; // rbx
  Render::ViewSettings *Identity; // rax
  Illusion::Target **v11; // r14
  __int64 mOffset; // rax
  _WORD *v13; // rax
  Illusion::Target **v14; // rsi
  unsigned int mUID; // r8d
  __int64 v16; // rax
  char *v17; // rbx
  Illusion::StateValues *StateValues; // rax
  Illusion::Target *v19; // rcx
  RenderQueueLayer v20; // [rsp+60h] [rbp-F08h] BYREF
  Render::View v21; // [rsp+140h] [rbp-E28h] BYREF
  LayerSubmitContext ptr; // [rsp+2D0h] [rbp-C98h] BYREF
  Render::Poly poly; // [rsp+F80h] [rbp+18h] BYREF

  if ( render_context->mRenderFeatures.mPostFX )
  {
    v7 = powf(this->mDamageCurrentMagnitude, 4.0) * 12.0;
    if ( v7 > 0.0099999998 )
    {
      mMaterial = Render::gRenderUtilities.mMaterial;
      RenderQueueLayer::RenderQueueLayer(&v20);
      LayerSubmitContext::LayerSubmitContext(&ptr);
      v20.mSerializationList = serialization_list;
      ptr.mRenderQueueProvider = &v20;
      v9 = 0i64;
      ptr.mQueueMode = QM_Single;
      Identity = Render::ViewSettings::GetIdentity();
      Render::View::View(&v21, Identity, &ptr);
      v11 = scratch_target;
      Render::View::BeginTarget(&v21, *scratch_target, "DamagePostEffect", 0, 0, 0i64, 1, 0, 0, 0);
      if ( LODWORD(mMaterial[1].mResourceHandles.UFG::qResourceData::mNode.mNext) != 250757386 )
      {
        UFG::qResourceHandle::Init(
          (UFG::qResourceHandle *)&mMaterial[1].mNode.mChild[1],
          mMaterial[1].mTypeUID,
          0xEF2410Au);
        mOffset = mMaterial->mMaterialUser.mOffset;
        if ( mOffset )
          v13 = (_WORD *)((char *)&mMaterial->mMaterialUser + mOffset);
        else
          v13 = 0i64;
        *v13 |= 0x20u;
      }
      v14 = curr_target;
      mUID = (*curr_target)->mTargetTexture[0]->mNode.mUID;
      if ( LODWORD(mMaterial[1].mStateBlockMask.mFlags[0]) != mUID )
      {
        UFG::qResourceHandle::Init(
          (UFG::qResourceHandle *)&mMaterial[1].mDebugName[20],
          mMaterial[1].mStateBlockMask.mFlags[1],
          mUID);
        v16 = mMaterial->mMaterialUser.mOffset;
        if ( v16 )
          v9 = (_WORD *)((char *)&mMaterial->mMaterialUser + v16);
        *v9 |= 0x20u;
      }
      v17 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x80u, 0x10u);
      *(float *)v17 = v7;
      StateValues = Render::View::GetStateValues(&v21);
      StateValues->mSetValueMask.mFlags[0] |= 0x8000ui64;
      StateValues->mParamValues[15] = v17;
      Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
      Render::View::Draw(&v21, &poly, mMaterial, 0i64);
      Render::View::EndTarget(&v21);
      v19 = *v14;
      *v14 = *v11;
      *v11 = v19;
      `eh vector destructor iterator(
        ptr.mStateArgs.mStateArgs,
        0x10ui64,
        128,
        (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
      RenderQueueLayer::~RenderQueueLayer(&v20);
    }
  }
}

// File Line: 165
// RVA: 0x60EC0
void __fastcall UFG::DamagePostEffect::Update(UFG::DamagePostEffect *this, float sim_time_delta)
{
  this->mDamageCurrentMagnitude = (float)((float)(this->mDamageTargetMagnitude - this->mDamageCurrentMagnitude)
                                        * sim_time_delta)
                                + this->mDamageCurrentMagnitude;
}

// File Line: 174
// RVA: 0x5FC50
UFG::ComponentIDDesc *__fastcall UFG::VisualTreatmentPostEffect::GetDesc(UFG::VisualTreatmentPostEffect *this)
{
  return &UFG::VisualTreatmentPostEffect::_TypeIDesc;
}

// File Line: 177
// RVA: 0x1456890
__int64 dynamic_initializer_for__UFG::VisualTreatmentPostEffect::msStateBlockHandle__()
{
  `eh vector constructor iterator(
    (char *)UFG::VisualTreatmentPostEffect::msStateBlockHandle,
    0x20ui64,
    128,
    (void (__fastcall *)(void *))Illusion::StateBlockHandle::StateBlockHandle);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::VisualTreatmentPostEffect::msStateBlockHandle__);
}

// File Line: 181
// RVA: 0x60BE0
void __fastcall UFG::VisualTreatmentPostEffect::StaticInit(
        const char **visual_treatment_name,
        int num_visualtreatment_names)
{
  __int64 v2; // rbx
  UFG::qResourceWarehouse *v4; // rax
  __int64 v5; // rdi
  __int64 v6; // rbp
  Illusion::StateBlockInventory *Inventory; // r15
  unsigned int v8; // eax
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *StateBlock; // rax
  __int64 v10; // rbx
  unsigned int mNext; // esi
  UFG::qResourceInventory *v12; // rax
  Illusion::StateBlockHandle *v13; // rbx
  UFG::qResourceWarehouse *v14; // rax
  int v15; // eax
  int v16; // eax
  char dest[296]; // [rsp+20h] [rbp-128h] BYREF

  v2 = num_visualtreatment_names;
  v4 = UFG::qResourceWarehouse::Instance();
  v5 = 0i64;
  v6 = v2;
  Inventory = (Illusion::StateBlockInventory *)UFG::qResourceWarehouse::GetInventory(v4, 0x4D04C7F2u);
  if ( (int)v2 <= 0 )
  {
    v15 = UFG::VisualTreatmentPostEffect::msNumVisualTreatments;
  }
  else
  {
    do
    {
      UFG::qSPrintf(dest, 255, "StateBlock.%s_VisualTreatment", visual_treatment_name[v5]);
      v8 = UFG::qStringHashUpper32(dest, 0xFFFFFFFF);
      StateBlock = Illusion::StateBlockInventory::GetStateBlock(Inventory, v8, 1);
      if ( StateBlock )
      {
        v10 = UFG::VisualTreatmentPostEffect::msNumVisualTreatments;
        UFG::VisualTreatmentPostEffect::msStateBlockName[UFG::VisualTreatmentPostEffect::msNumVisualTreatments] = visual_treatment_name[v5];
        mNext = (unsigned int)StateBlock[1].mNode.mNext;
        v12 = `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result;
        v13 = &UFG::VisualTreatmentPostEffect::msStateBlockHandle[v10];
        if ( !`UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result )
        {
          v14 = UFG::qResourceWarehouse::Instance();
          v12 = UFG::qResourceWarehouse::GetInventory(v14, 0x4D04C7F2u);
          `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result = v12;
        }
        UFG::qResourceHandle::Init(v13, 0x4D04C7F2u, mNext, v12);
        v15 = ++UFG::VisualTreatmentPostEffect::msNumVisualTreatments;
      }
      else
      {
        v15 = UFG::VisualTreatmentPostEffect::msNumVisualTreatments;
      }
      ++v5;
    }
    while ( v5 < v6 );
  }
  UFG::VisualTreatmentPostEffect::msStateBlockName[v15] = "Tweaker";
  gVisualTreatmentTweaker = v15;
  v16 = v15 + 1;
  gVisualTreatmentCount = v16;
  UFG::VisualTreatmentPostEffect::msStateBlockName[v16] = "Disable";
  UFG::VisualTreatmentPostEffect::msNumVisualTreatments = v16 + 1;
}

// File Line: 236
// RVA: 0x5F210
void __fastcall UFG::VisualTreatmentPostEffect::VisualTreatmentPostEffect(UFG::VisualTreatmentPostEffect *this)
{
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v3; // rax
  unsigned __int64 v4; // rax
  unsigned int v5; // r10d
  UFG::qResourceData *i; // rdx
  char *v7; // r9
  int v8; // r8d
  char *v9; // rdx
  __int64 v10; // r8
  float *v11; // rax
  float v12; // xmm0_4
  int v13; // ecx
  UFG::qResourceInventory *v14; // rax
  UFG::qResourceWarehouse *v15; // rax
  UFG::qResourceHandle v16; // [rsp+28h] [rbp-40h] BYREF

  UFG::RenderStagePlugin::RenderStagePlugin(this);
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::VisualTreatmentPostEffect::`vftable;
  this->mState.mNumAdditive = 0;
  this->mState.mBasePlaying = 0;
  this->mState.mTreatmentID = 0;
  this->mState.mRenderTreatment = 0;
  this->mSavedState.mNumAdditive = 0;
  this->mSavedState.mBasePlaying = 0;
  this->mSavedState.mTreatmentID = 0;
  this->mSavedState.mRenderTreatment = 0;
  UFG::SimComponent::AddType(
    this,
    UFG::VisualTreatmentPostEffect::_VisualTreatmentPostEffectTypeUID,
    "VisualTreatmentPostEffect");
  UFG::VisualTreatmentPostEffect::msNumVisualTreatments = 0;
  this->mShouldSetCameraFOVOffset = 0;
  this->mCameraFOVOffset = 0.0;
  *(_OWORD *)gVisualTreatmentParams.Value0 = _xmm;
  *(_OWORD *)gVisualTreatmentParams.Value1 = _xmm;
  *(_OWORD *)gVisualTreatmentParams.Value2 = _xmm;
  *(_OWORD *)gVisualTreatmentParams.Value3 = _xmm;
  gVisualTreatmentParams.FovOffset = 0.0;
  LODWORD(gVisualTreatmentParams.TimeScale) = (_DWORD)FLOAT_1_0;
  this->mDefaultVisualTreatmentParams = 0i64;
  UFG::qResourceHandle::qResourceHandle(&v16);
  Inventory = `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result )
  {
    v3 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v3, 0x4D04C7F2u);
    `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(&v16, 0x4D04C7F2u, 0x8906EE5D, Inventory);
  if ( v16.mData )
  {
    v4 = 4i64 * v16.mData[1].mNode.mUID;
    if ( !is_mul_ok(v16.mData[1].mNode.mUID, 4ui64) )
      v4 = -1i64;
    this->mDefaultVisualTreatmentParams = (float *)UFG::qMalloc(v4, "mDefaultVisualTreatmentParams", 0i64);
    v5 = 2;
    for ( i = v16.mData; v5 < v16.mData[1].mNode.mUID; i = v16.mData )
    {
      v7 = (char *)i
         + *(unsigned __int16 *)((char *)&i[1].mResourceHandles.mNode.mNext
                               + 4 * v5
                               + ((HIDWORD(i[1].mNode.mChild[1]) + 15) & 0xFFFFFFF0));
      v8 = *((_DWORD *)v7 + 32);
      if ( !v8 )
        goto LABEL_17;
      v9 = v7 + 132;
      v10 = (unsigned int)(v8 - 1);
      v11 = (float *)(v7 + 140);
      if ( *((float *)v7 + 33) < 0.0 )
      {
        if ( *(float *)&v7[8 * v10 + 132] > 0.0 )
        {
          v13 = 0;
          if ( (_DWORD)v10 )
          {
            while ( *v11 < 0.0 )
            {
              v9 += 8;
              v11 += 2;
              if ( ++v13 >= (unsigned int)v10 )
                goto LABEL_17;
            }
            v12 = (float)((float)(v11[1] - *((float *)v9 + 1))
                        * (float)(COERCE_FLOAT(*(_DWORD *)v9 ^ _xmm[0]) / (float)(*v11 - *(float *)v9)))
                + *((float *)v9 + 1);
            goto LABEL_18;
          }
LABEL_17:
          v12 = 0.0;
          goto LABEL_18;
        }
        v12 = *(float *)&v7[8 * v10 + 136];
      }
      else
      {
        v12 = *((float *)v7 + 34);
      }
LABEL_18:
      this->mDefaultVisualTreatmentParams[v5++] = v12;
    }
  }
  v14 = `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result )
  {
    v15 = UFG::qResourceWarehouse::Instance();
    v14 = UFG::qResourceWarehouse::GetInventory(v15, 0x4D04C7F2u);
    `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result = v14;
  }
  UFG::qResourceHandle::Close(&v16, v14);
  UFG::qResourceHandle::~qResourceHandle(&v16);
}

// File Line: 355
// RVA: 0x5F850
void __fastcall UFG::VisualTreatmentPostEffect::AccumulateTreatment(
        UFG::VisualTreatmentPostEffect *this,
        float *treatmentParams,
        UFG::VisualTreatmentPostEffect::TreatmentComponent *component,
        float sim_time_delta,
        bool *expired)
{
  __int64 v6; // rdi
  __int64 v8; // r9
  float v9; // xmm2_4
  float v10; // xmm1_4
  float v11; // xmm3_4
  float mFadeOutDuration; // xmm4_4
  float v13; // xmm0_4
  float v14; // xmm6_4
  bool v15; // al
  unsigned int v16; // r14d
  float v17; // xmm4_4
  char *v18; // r10
  __int64 v19; // rbx
  unsigned __int16 *v20; // r11
  signed __int64 v21; // rsi
  __int64 v22; // rcx
  int v23; // r8d
  float *v24; // rdx
  __int64 v25; // r8
  float *v26; // rax
  float v27; // xmm3_4
  unsigned int v28; // ecx
  float v29; // xmm0_4
  float v30; // xmm3_4
  float mTimeElapsed; // xmm4_4
  float v32; // xmm4_4
  float *v33; // r10
  __int64 v34; // rbx
  unsigned __int16 *v35; // r11
  __int64 v36; // rcx
  int v37; // r8d
  float *v38; // rdx
  __int64 v39; // r8
  float *v40; // rax
  float v41; // xmm3_4
  unsigned int v42; // ecx
  unsigned int v43; // ecx
  float *mDefaultVisualTreatmentParams; // rdx
  __int64 v45; // rax
  float v46; // [rsp+0h] [rbp-78h]
  float v47; // [rsp+4h] [rbp-74h]
  char v48[72]; // [rsp+8h] [rbp-70h] BYREF

  v6 = *((_QWORD *)&UFG::VisualTreatmentPostEffect::msStateBlockHandle[0].mData + 4 * component->mTreatmentIndex);
  v8 = (*(_DWORD *)(v6 + 108) + 15) & 0xFFFFFFF0;
  v9 = *(float *)(*(unsigned __int16 *)(v8 + v6 + 128) + v6 + 136);
  v10 = *(float *)(*(unsigned __int16 *)(v8 + v6 + 132) + v6 + 136);
  *expired = 0;
  if ( !component->mFadeOut )
  {
    v30 = sim_time_delta + component->mTimeElapsed;
    component->mTimeElapsed = v30;
    if ( v30 > v9 )
    {
      if ( v10 <= 0.0 )
        *expired = 1;
      else
        component->mTimeElapsed = v30 - (float)(v9 - v10);
    }
    mTimeElapsed = component->mTimeElapsed;
    v16 = *(_DWORD *)(v6 + 112);
    v47 = v10;
    v32 = mTimeElapsed / v9;
    v46 = v32;
    if ( v16 <= 2 )
      goto LABEL_39;
    v33 = (float *)v48;
    v34 = v16 - 2;
    v35 = (unsigned __int16 *)(((*(_DWORD *)(v6 + 108) + 15) & 0xFFFFFFF0) + v6 + 136);
    while ( 1 )
    {
      v36 = v6 + *v35;
      v37 = *(_DWORD *)(v36 + 128);
      if ( !v37 )
        goto LABEL_37;
      v38 = (float *)(v36 + 132);
      v39 = (unsigned int)(v37 - 1);
      v40 = (float *)(v36 + 140);
      if ( v32 > *(float *)(v36 + 132) )
      {
        if ( v32 < *(float *)(v36 + 8 * v39 + 132) )
        {
          v42 = 0;
          if ( (_DWORD)v39 )
          {
            while ( v32 > *v40 )
            {
              ++v42;
              v38 += 2;
              v40 += 2;
              if ( v42 >= (unsigned int)v39 )
                goto LABEL_37;
            }
            v41 = (float)((float)((float)(v32 - *v38) / (float)(*v40 - *v38)) * (float)(v40[1] - v38[1])) + v38[1];
            goto LABEL_38;
          }
LABEL_37:
          v41 = 0.0;
          goto LABEL_38;
        }
        v41 = *(float *)(v36 + 8 * v39 + 136);
      }
      else
      {
        v41 = *(float *)(v36 + 136);
      }
LABEL_38:
      *v33++ = v41;
      v35 += 2;
      if ( !--v34 )
        goto LABEL_39;
    }
  }
  v11 = sim_time_delta + component->mFadeOutElapsed;
  mFadeOutDuration = component->mFadeOutDuration;
  component->mFadeOutElapsed = v11;
  v13 = v11 / mFadeOutDuration;
  if ( (float)(v11 / mFadeOutDuration) <= 0.0 )
  {
    v13 = 0.0;
    goto LABEL_6;
  }
  v14 = *(float *)&FLOAT_1_0;
  if ( v13 < 1.0 )
LABEL_6:
    v14 = v13;
  v15 = *expired;
  if ( v11 > mFadeOutDuration )
    v15 = 1;
  v47 = v10;
  *expired = v15;
  v16 = *(_DWORD *)(v6 + 112);
  v17 = component->mTimeElapsed / v9;
  v46 = v17;
  if ( v16 > 2 )
  {
    v18 = v48;
    v19 = v16 - 2;
    v20 = (unsigned __int16 *)(((*(_DWORD *)(v6 + 108) + 15) & 0xFFFFFFF0) + v6 + 136);
    v21 = (char *)this->mDefaultVisualTreatmentParams - v48;
    do
    {
      v22 = v6 + *v20;
      v23 = *(_DWORD *)(v22 + 128);
      if ( !v23 )
        goto LABEL_19;
      v24 = (float *)(v22 + 132);
      v25 = (unsigned int)(v23 - 1);
      v26 = (float *)(v22 + 140);
      if ( v17 > *(float *)(v22 + 132) )
      {
        if ( v17 < *(float *)(v22 + 8 * v25 + 132) )
        {
          v28 = 0;
          if ( (_DWORD)v25 )
          {
            while ( v17 > *v26 )
            {
              ++v28;
              v24 += 2;
              v26 += 2;
              if ( v28 >= (unsigned int)v25 )
                goto LABEL_19;
            }
            v27 = (float)((float)((float)(v17 - *v24) / (float)(*v26 - *v24)) * (float)(v26[1] - v24[1])) + v24[1];
            goto LABEL_20;
          }
LABEL_19:
          v27 = 0.0;
          goto LABEL_20;
        }
        v27 = *(float *)(v22 + 8 * v25 + 136);
      }
      else
      {
        v27 = *(float *)(v22 + 136);
      }
LABEL_20:
      v29 = *(float *)&v18[v21 + 8];
      v18 += 4;
      v20 += 2;
      *((float *)v18 - 1) = (float)((float)(v29 - v27) * v14) + v27;
      --v19;
    }
    while ( v19 );
  }
LABEL_39:
  v43 = 2;
  if ( v16 > 2 )
  {
    mDefaultVisualTreatmentParams = this->mDefaultVisualTreatmentParams;
    do
    {
      v45 = v43++;
      treatmentParams[v45] = (float)(*(&v46 + v45) - mDefaultVisualTreatmentParams[v45]) + treatmentParams[v45];
    }
    while ( v43 < *(_DWORD *)(v6 + 112) );
  }
}

// File Line: 436
// RVA: 0x60530
void __fastcall UFG::VisualTreatmentPostEffect::RenderPostEffect(
        UFG::VisualTreatmentPostEffect *this,
        UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list,
        UFG::RenderContext *render_context,
        float delta_time,
        Illusion::Target **curr_target,
        Illusion::Target **scratch_target)
{
  Illusion::Material *mMaterial; // rbx
  _WORD *v10; // rdi
  Render::ViewSettings *Identity; // rax
  Illusion::Target **v12; // r15
  __int64 mOffset; // rax
  _WORD *v14; // rax
  Illusion::Target **v15; // r14
  unsigned int mUID; // r8d
  __int64 v17; // rax
  _WORD *v18; // rax
  unsigned int v19; // r8d
  __int64 v20; // rax
  char *v21; // rdi
  int v22; // xmm1_4
  Illusion::StateValues *StateValues; // rax
  Illusion::Target *v24; // rcx
  RenderQueueLayer v25; // [rsp+60h] [rbp-F08h] BYREF
  Render::View v26; // [rsp+140h] [rbp-E28h] BYREF
  LayerSubmitContext ptr; // [rsp+2D0h] [rbp-C98h] BYREF
  Render::Poly poly; // [rsp+F80h] [rbp+18h] BYREF

  if ( render_context->mRenderFeatures.mPostFX && this->mState.mRenderTreatment )
  {
    mMaterial = Render::gRenderUtilities.mMaterial;
    RenderQueueLayer::RenderQueueLayer(&v25);
    LayerSubmitContext::LayerSubmitContext(&ptr);
    v25.mSerializationList = serialization_list;
    ptr.mRenderQueueProvider = &v25;
    v10 = 0i64;
    ptr.mQueueMode = QM_Single;
    Identity = Render::ViewSettings::GetIdentity();
    Render::View::View(&v26, Identity, &ptr);
    v12 = scratch_target;
    Render::View::BeginTarget(&v26, *scratch_target, "VisualTreatmentPostEffect", 0, 0, 0i64, 1, 0, 0, 0);
    if ( LODWORD(mMaterial[1].mResourceHandles.UFG::qResourceData::mNode.mNext) != 557606856 )
    {
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&mMaterial[1].mNode.mChild[1],
        mMaterial[1].mTypeUID,
        0x213C67C8u);
      mOffset = mMaterial->mMaterialUser.mOffset;
      if ( mOffset )
        v14 = (_WORD *)((char *)&mMaterial->mMaterialUser + mOffset);
      else
        v14 = 0i64;
      *v14 |= 0x20u;
    }
    v15 = curr_target;
    mUID = (*curr_target)->mTargetTexture[0]->mNode.mUID;
    if ( LODWORD(mMaterial[1].mStateBlockMask.mFlags[0]) != mUID )
    {
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&mMaterial[1].mDebugName[20],
        mMaterial[1].mStateBlockMask.mFlags[1],
        mUID);
      v17 = mMaterial->mMaterialUser.mOffset;
      if ( v17 )
        v18 = (_WORD *)((char *)&mMaterial->mMaterialUser + v17);
      else
        v18 = 0i64;
      *v18 |= 0x20u;
    }
    v19 = render_context->mHalfSizeScratchTargetA->mTargetTexture[0]->mNode.mUID;
    if ( *(_DWORD *)&mMaterial[3].mDebugName[12] != v19 )
    {
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&mMaterial[3].mResourceHandles.UFG::qResourceData::mNode.mNext,
        *(_DWORD *)&mMaterial[3].mDebugName[20],
        v19);
      v20 = mMaterial->mMaterialUser.mOffset;
      if ( v20 )
        v10 = (_WORD *)((char *)&mMaterial->mMaterialUser + v20);
      *v10 |= 0x20u;
    }
    v21 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x80u, 0x10u);
    UFG::qMemCopy(v21, &this->mShaderParams, 0x80u);
    v22 = *((_DWORD *)v21 + 12);
    if ( COERCE_FLOAT(v22 & _xmm) < 0.000099999997 )
      v22 = (int)FLOAT_1_0;
    *((_DWORD *)v21 + 12) = v22;
    StateValues = Render::View::GetStateValues(&v26);
    StateValues->mSetValueMask.mFlags[0] |= 0x8000ui64;
    StateValues->mParamValues[15] = v21;
    Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
    Render::View::Draw(&v26, &poly, mMaterial, 0i64);
    Render::View::EndTarget(&v26);
    v24 = *v15;
    *v15 = *v12;
    *v12 = v24;
    `eh vector destructor iterator(
      ptr.mStateArgs.mStateArgs,
      0x10ui64,
      128,
      (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
    RenderQueueLayer::~RenderQueueLayer(&v25);
  }
},0,0>::~qList<Render::Decal,Render::Decal,0,0>);
    RenderQueueLayer::~RenderQueueLayer(&v25)

// File Line: 478
// RVA: 0x60F80
void __fastcall UFG::VisualTreatmentPostEffect::Update(UFG::VisualTreatmentPostEffect *this, float sim_time_delta)
{
  float *mDefaultVisualTreatmentParams; // rdx
  bool mBasePlaying; // cl
  unsigned int v5; // edi
  char *v6; // rsi
  __int64 v7; // rcx
  float mTodEV; // xmm6_4
  float v9; // xmm6_4
  float v10; // xmm3_4
  float v11; // xmm0_4
  bool v12; // zf
  float v13; // xmm0_4
  float v14; // xmm6_4
  float dest[9]; // [rsp+30h] [rbp-68h] BYREF
  float v16; // [rsp+54h] [rbp-44h]
  float v17; // [rsp+58h] [rbp-40h]
  float v18; // [rsp+5Ch] [rbp-3Ch]
  float v19; // [rsp+6Ch] [rbp-2Ch]
  float v20; // [rsp+70h] [rbp-28h]
  bool expired; // [rsp+A0h] [rbp+8h] BYREF

  mDefaultVisualTreatmentParams = this->mDefaultVisualTreatmentParams;
  if ( !mDefaultVisualTreatmentParams )
    return;
  this->mShouldSetCameraFOVOffset = 0;
  UFG::qMemCopy(dest, mDefaultVisualTreatmentParams, 0x50u);
  mBasePlaying = this->mState.mBasePlaying;
  this->mState.mRenderTreatment = 0;
  if ( !mBasePlaying )
    goto LABEL_27;
  if ( this->mState.mBaseTreatment.mTreatmentIndex == gVisualTreatmentTweaker )
  {
    UFG::qMemCopy(dest, &gVisualTreatmentParams, 0x50u);
    this->mState.mRenderTreatment = 1;
    goto LABEL_14;
  }
  if ( this->mState.mBaseTreatment.mTreatmentIndex < gVisualTreatmentCount )
  {
LABEL_27:
    if ( mBasePlaying )
    {
      this->mState.mRenderTreatment = 1;
      expired = 0;
      UFG::VisualTreatmentPostEffect::AccumulateTreatment(
        this,
        dest,
        &this->mState.mBaseTreatment,
        sim_time_delta,
        &expired);
      if ( expired )
        this->mState.mBasePlaying = 0;
    }
    v5 = 0;
    while ( v5 < this->mState.mNumAdditive )
    {
      this->mState.mRenderTreatment = 1;
      v6 = (char *)this + 28 * v5;
      expired = 0;
      UFG::VisualTreatmentPostEffect::AccumulateTreatment(
        this,
        dest,
        (UFG::VisualTreatmentPostEffect::TreatmentComponent *)(v6 + 124),
        sim_time_delta,
        &expired);
      if ( expired )
      {
        v7 = this->mState.mNumAdditive - 1;
        *((_DWORD *)v6 + 31) = this->mState.mAdditiveTreatment[v7].mTreatmentIndex;
        *((_DWORD *)v6 + 32) = this->mState.mAdditiveTreatment[v7].mPriority;
        *((_DWORD *)v6 + 33) = LODWORD(this->mState.mAdditiveTreatment[v7].mTimeElapsed);
        *((_DWORD *)v6 + 34) = this->mState.mAdditiveTreatment[v7].mId;
        *((_DWORD *)v6 + 35) = LODWORD(this->mState.mAdditiveTreatment[v7].mFadeOutDuration);
        *((_DWORD *)v6 + 36) = LODWORD(this->mState.mAdditiveTreatment[v7].mFadeOutElapsed);
        *((_DWORD *)v6 + 37) = *(_DWORD *)&this->mState.mAdditiveTreatment[v7].mFadeOut;
        --this->mState.mNumAdditive;
      }
      else
      {
        ++v5;
      }
    }
  }
LABEL_14:
  mTodEV = UFG::TimeOfDayManager::GetInstance()->mTodEV;
  v9 = mTodEV + UFG::TimeOfDayManager::GetInstance()->mMeteringEV;
  if ( v9 <= 0.0 )
  {
    v9 = 0.0;
  }
  else
  {
    v10 = *(float *)&FLOAT_1_0;
    if ( v9 >= 1.0 )
      goto LABEL_19;
  }
  v10 = v9;
LABEL_19:
  v16 = v16 + (float)(v10 * 0.0);
  v17 = v17 + (float)(v10 * 0.0);
  v18 = v18 + (float)(v10 * 0.0);
  v11 = FLOAT_0_60000002;
  if ( (float)(v19 + (float)(v10 * -0.2)) <= 0.60000002 )
    v11 = v19 + (float)(v10 * -0.2);
  v12 = !this->mState.mRenderTreatment;
  v19 = v11;
  if ( v12 )
  {
    if ( firstFrameOff )
    {
      this->mShouldSetCameraFOVOffset = 1;
      this->mCameraFOVOffset = 0.0;
      UFG::TimeOfDayManager::GetInstance()->mVisualTreatmentEV = 0.0;
      firstFrameOff = 0;
    }
  }
  else
  {
    v13 = v20;
    this->mShouldSetCameraFOVOffset = 1;
    this->mCameraFOVOffset = v13;
    UFG::TimeOfDayManager::GetInstance();
    UFG::TimeOfDayManager::GetInstance();
    v14 = v16;
    UFG::TimeOfDayManager::GetInstance()->mVisualTreatmentEV = v14;
    UFG::qMemCopy(&this->mShaderParams, dest, 0x80u);
    firstFrameOff = 1;
  }
}

// File Line: 603
// RVA: 0x60AF0
__int64 __fastcall UFG::VisualTreatmentPostEffect::StartVisualTreatment(
        UFG::VisualTreatmentPostEffect *this,
        int index,
        bool isAdditive,
        int priority)
{
  __int64 mNumAdditive; // rax
  unsigned int v6; // ecx
  __int64 result; // rax

  if ( index > -1 && index < UFG::VisualTreatmentPostEffect::msNumVisualTreatments )
  {
    if ( !isAdditive || this->mState.mBasePlaying && priority < this->mState.mBaseTreatment.mPriority )
    {
      if ( !this->mState.mBasePlaying || priority >= this->mState.mBaseTreatment.mPriority )
      {
        result = this->mState.mTreatmentID;
        this->mState.mBaseTreatment.mTreatmentIndex = index;
        this->mState.mBaseTreatment.mPriority = priority;
        this->mState.mBaseTreatment.mTimeElapsed = 0.0;
        this->mState.mBaseTreatment.mFadeOut = 0;
        this->mState.mBaseTreatment.mId = result;
        this->mState.mBasePlaying = 1;
        this->mState.mTreatmentID = result + 1;
        return result;
      }
    }
    else
    {
      mNumAdditive = this->mState.mNumAdditive;
      if ( (unsigned int)mNumAdditive < 5 )
      {
        this->mState.mAdditiveTreatment[mNumAdditive].mTreatmentIndex = index;
        this->mState.mAdditiveTreatment[this->mState.mNumAdditive].mTimeElapsed = 0.0;
        this->mState.mAdditiveTreatment[this->mState.mNumAdditive].mFadeOut = 0;
        this->mState.mAdditiveTreatment[this->mState.mNumAdditive].mId = this->mState.mTreatmentID;
        v6 = this->mState.mNumAdditive;
        result = this->mState.mAdditiveTreatment[this->mState.mNumAdditive].mId;
        ++this->mState.mTreatmentID;
        this->mState.mNumAdditive = v6 + 1;
        return result;
      }
    }
  }
  return 0xFFFFFFFFi64;
}

// File Line: 641
// RVA: 0x60D80
void __fastcall UFG::VisualTreatmentPostEffect::StopVisualTreatment(
        UFG::VisualTreatmentPostEffect *this,
        unsigned int treatmentId,
        float fade_duration)
{
  float v5; // xmm0_4
  unsigned int mNumAdditive; // edx
  __int64 v7; // rcx
  float v8; // xmm0_4
  __int64 v9; // rcx
  __int64 v10; // rdx
  __int64 v11; // rax
  __int64 v12; // rcx

  if ( this->mState.mBasePlaying && this->mState.mBaseTreatment.mId == treatmentId )
  {
    v5 = fade_duration;
    if ( fade_duration < 0.0 )
      LODWORD(v5) = LODWORD(fade_duration) ^ _xmm[0];
    if ( v5 >= 0.001 )
    {
      this->mState.mBaseTreatment.mFadeOutDuration = fade_duration;
      this->mState.mBaseTreatment.mFadeOut = 1;
      this->mState.mBaseTreatment.mFadeOutElapsed = 0.0;
    }
    else
    {
      this->mState.mBasePlaying = 0;
    }
  }
  else
  {
    mNumAdditive = this->mState.mNumAdditive;
    v7 = 0i64;
    if ( mNumAdditive )
    {
      while ( this->mState.mAdditiveTreatment[(unsigned int)v7].mId != treatmentId )
      {
        v7 = (unsigned int)(v7 + 1);
        if ( (unsigned int)v7 >= mNumAdditive )
          return;
      }
      v8 = fade_duration;
      if ( fade_duration < 0.0 )
        LODWORD(v8) = LODWORD(fade_duration) ^ _xmm[0];
      if ( v8 >= 0.001 )
      {
        v11 = (unsigned int)v7;
        v12 = v7;
        this->mState.mAdditiveTreatment[v12].mFadeOut = 1;
        this->mState.mAdditiveTreatment[v12].mFadeOutElapsed = 0.0;
        this->mState.mAdditiveTreatment[v11].mFadeOutDuration = fade_duration;
      }
      else
      {
        v9 = v7;
        v10 = mNumAdditive - 1;
        this->mState.mAdditiveTreatment[v9].mTreatmentIndex = this->mState.mAdditiveTreatment[v10].mTreatmentIndex;
        this->mState.mAdditiveTreatment[v9].mPriority = this->mState.mAdditiveTreatment[v10].mPriority;
        this->mState.mAdditiveTreatment[v9].mTimeElapsed = this->mState.mAdditiveTreatment[v10].mTimeElapsed;
        this->mState.mAdditiveTreatment[v9].mId = this->mState.mAdditiveTreatment[v10].mId;
        this->mState.mAdditiveTreatment[v9].mFadeOutDuration = this->mState.mAdditiveTreatment[v10].mFadeOutDuration;
        this->mState.mAdditiveTreatment[v9].mFadeOutElapsed = this->mState.mAdditiveTreatment[v10].mFadeOutElapsed;
        *(_DWORD *)&this->mState.mAdditiveTreatment[v9].mFadeOut = *(_DWORD *)&this->mState.mAdditiveTreatment[v10].mFadeOut;
        --this->mState.mNumAdditive;
      }
    }
  }
}

// File Line: 680
// RVA: 0x60D60
void __fastcall UFG::VisualTreatmentPostEffect::StopAllVisualTreatments(UFG::VisualTreatmentPostEffect *this)
{
  this->mState.mBasePlaying = 0;
  this->mState.mNumAdditive = 0;
  this->mSavedState.mBasePlaying = 0;
  this->mSavedState.mNumAdditive = 0;
}

// File Line: 700
// RVA: 0x60880
void __fastcall UFG::VisualTreatmentPostEffect::SaveState(UFG::VisualTreatmentPostEffect *this)
{
  UFG::VisualTreatmentPostEffect::State *p_mState; // rdx
  UFG::VisualTreatmentPostEffect::State *p_mSavedState; // r9
  __int64 v3; // rax
  __int128 v4; // xmm0
  __int128 v5; // xmm1
  __int128 v6; // xmm0
  __int128 v7; // xmm1
  __int128 v8; // xmm0
  __int128 v9; // xmm1
  __int128 v10; // xmm0
  __int128 v11; // xmm1
  __int128 v12; // xmm1
  __int64 v13; // rax
  __int128 v14; // xmm0

  p_mState = &this->mState;
  p_mSavedState = &this->mSavedState;
  if ( (((unsigned __int8)((_BYTE)this + 24) | (unsigned __int8)((_BYTE)this + 96)) & 0xF) != 0 )
  {
    memmove(&this->mSavedState, p_mState, 0xB8ui64);
  }
  else
  {
    v3 = 1i64;
    do
    {
      v4 = *(_OWORD *)&p_mState->mBaseTreatment.mTreatmentIndex;
      v5 = *(_OWORD *)&p_mState->mBaseTreatment.mFadeOutDuration;
      p_mSavedState = (UFG::VisualTreatmentPostEffect::State *)((char *)p_mSavedState + 128);
      p_mState = (UFG::VisualTreatmentPostEffect::State *)((char *)p_mState + 128);
      *(_OWORD *)&p_mSavedState[-1].mAdditiveTreatment[1].mTreatmentIndex = v4;
      v6 = *(_OWORD *)&p_mState[-1].mAdditiveTreatment[2].mPriority;
      *(_OWORD *)&p_mSavedState[-1].mAdditiveTreatment[1].mFadeOutDuration = v5;
      v7 = *(_OWORD *)&p_mState[-1].mAdditiveTreatment[2].mFadeOutElapsed;
      *(_OWORD *)&p_mSavedState[-1].mAdditiveTreatment[2].mPriority = v6;
      v8 = *(_OWORD *)&p_mState[-1].mAdditiveTreatment[3].mTimeElapsed;
      *(_OWORD *)&p_mSavedState[-1].mAdditiveTreatment[2].mFadeOutElapsed = v7;
      v9 = *(_OWORD *)&p_mState[-1].mAdditiveTreatment[3].mFadeOut;
      *(_OWORD *)&p_mSavedState[-1].mAdditiveTreatment[3].mTimeElapsed = v8;
      v10 = *(_OWORD *)&p_mState[-1].mAdditiveTreatment[4].mId;
      *(_OWORD *)&p_mSavedState[-1].mAdditiveTreatment[3].mFadeOut = v9;
      v11 = *(_OWORD *)&p_mState[-1].mNumAdditive;
      *(_OWORD *)&p_mSavedState[-1].mAdditiveTreatment[4].mId = v10;
      *(_OWORD *)&p_mSavedState[-1].mNumAdditive = v11;
      --v3;
    }
    while ( v3 );
    v12 = *(_OWORD *)&p_mState->mBaseTreatment.mFadeOutDuration;
    v13 = *(_QWORD *)&p_mState->mAdditiveTreatment[0].mFadeOutElapsed;
    *(_OWORD *)&p_mSavedState->mBaseTreatment.mTreatmentIndex = *(_OWORD *)&p_mState->mBaseTreatment.mTreatmentIndex;
    v14 = *(_OWORD *)&p_mState->mAdditiveTreatment[0].mPriority;
    *(_OWORD *)&p_mSavedState->mBaseTreatment.mFadeOutDuration = v12;
    *(_OWORD *)&p_mSavedState->mAdditiveTreatment[0].mPriority = v14;
    *(_QWORD *)&p_mSavedState->mAdditiveTreatment[0].mFadeOutElapsed = v13;
  }
}

// File Line: 705
// RVA: 0x607D0
void __fastcall UFG::VisualTreatmentPostEffect::RestoreState(UFG::VisualTreatmentPostEffect *this)
{
  UFG::VisualTreatmentPostEffect::State *p_mSavedState; // rdx
  UFG::VisualTreatmentPostEffect::State *p_mState; // r9
  __int64 v3; // rax
  __int128 v4; // xmm0
  __int128 v5; // xmm1
  __int128 v6; // xmm0
  __int128 v7; // xmm1
  __int128 v8; // xmm0
  __int128 v9; // xmm1
  __int128 v10; // xmm0
  __int128 v11; // xmm1
  __int128 v12; // xmm1
  __int64 v13; // rax
  __int128 v14; // xmm0

  p_mSavedState = &this->mSavedState;
  p_mState = &this->mState;
  if ( (((unsigned __int8)((_BYTE)this + 96) | (unsigned __int8)((_BYTE)this + 24)) & 0xF) != 0 )
  {
    memmove(&this->mState, p_mSavedState, 0xB8ui64);
  }
  else
  {
    v3 = 1i64;
    do
    {
      v4 = *(_OWORD *)&p_mSavedState->mBaseTreatment.mTreatmentIndex;
      v5 = *(_OWORD *)&p_mSavedState->mBaseTreatment.mFadeOutDuration;
      p_mState = (UFG::VisualTreatmentPostEffect::State *)((char *)p_mState + 128);
      p_mSavedState = (UFG::VisualTreatmentPostEffect::State *)((char *)p_mSavedState + 128);
      *(_OWORD *)&p_mState[-1].mAdditiveTreatment[1].mTreatmentIndex = v4;
      v6 = *(_OWORD *)&p_mSavedState[-1].mAdditiveTreatment[2].mPriority;
      *(_OWORD *)&p_mState[-1].mAdditiveTreatment[1].mFadeOutDuration = v5;
      v7 = *(_OWORD *)&p_mSavedState[-1].mAdditiveTreatment[2].mFadeOutElapsed;
      *(_OWORD *)&p_mState[-1].mAdditiveTreatment[2].mPriority = v6;
      v8 = *(_OWORD *)&p_mSavedState[-1].mAdditiveTreatment[3].mTimeElapsed;
      *(_OWORD *)&p_mState[-1].mAdditiveTreatment[2].mFadeOutElapsed = v7;
      v9 = *(_OWORD *)&p_mSavedState[-1].mAdditiveTreatment[3].mFadeOut;
      *(_OWORD *)&p_mState[-1].mAdditiveTreatment[3].mTimeElapsed = v8;
      v10 = *(_OWORD *)&p_mSavedState[-1].mAdditiveTreatment[4].mId;
      *(_OWORD *)&p_mState[-1].mAdditiveTreatment[3].mFadeOut = v9;
      v11 = *(_OWORD *)&p_mSavedState[-1].mNumAdditive;
      *(_OWORD *)&p_mState[-1].mAdditiveTreatment[4].mId = v10;
      *(_OWORD *)&p_mState[-1].mNumAdditive = v11;
      --v3;
    }
    while ( v3 );
    v12 = *(_OWORD *)&p_mSavedState->mBaseTreatment.mFadeOutDuration;
    v13 = *(_QWORD *)&p_mSavedState->mAdditiveTreatment[0].mFadeOutElapsed;
    *(_OWORD *)&p_mState->mBaseTreatment.mTreatmentIndex = *(_OWORD *)&p_mSavedState->mBaseTreatment.mTreatmentIndex;
    v14 = *(_OWORD *)&p_mSavedState->mAdditiveTreatment[0].mPriority;
    *(_OWORD *)&p_mState->mBaseTreatment.mFadeOutDuration = v12;
    *(_OWORD *)&p_mState->mAdditiveTreatment[0].mPriority = v14;
    *(_QWORD *)&p_mState->mAdditiveTreatment[0].mFadeOutElapsed = v13;
  }
}

// File Line: 714
// RVA: 0x1456800
__int64 dynamic_initializer_for__UFG::GunRecoilPostEffect::_TypeIDesc__()
{
  UFG::ComponentIDDesc *v0; // rax
  __int64 result; // rax

  v0 = UFG::GunRecoilPostEffect::AccessComponentDesc();
  *(_DWORD *)&UFG::GunRecoilPostEffect::_TypeIDesc.mBaseTypeIndex = *(_DWORD *)&v0->mBaseTypeIndex;
  UFG::GunRecoilPostEffect::_TypeIDesc.mChildBitMask = v0->mChildBitMask;
  result = v0->mChildren;
  UFG::GunRecoilPostEffect::_TypeIDesc.mChildren = result;
  return result;
}

// File Line: 716
// RVA: 0x5F120
void __fastcall UFG::GunRecoilPostEffect::GunRecoilPostEffect(UFG::GunRecoilPostEffect *this)
{
  char v2; // cl

  UFG::RenderStagePlugin::RenderStagePlugin(this);
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::GunRecoilPostEffect::`vftable;
  this->mRecoilValue = 0.0;
  this->mRecoilFalloffScale = 1.0;
  UFG::SimComponent::AddType(this, UFG::GunRecoilPostEffect::_GunRecoilPostEffectTypeUID, "GunRecoilPostEffect");
  v2 = sIsStaticInit_0;
  if ( !sIsStaticInit_0 )
    v2 = 1;
  sIsStaticInit_0 = v2;
}

// File Line: 729
// RVA: 0x602F0
void __fastcall UFG::GunRecoilPostEffect::RenderPostEffect(
        UFG::GunRecoilPostEffect *this,
        UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list,
        UFG::RenderContext *render_context,
        float delta_time,
        Illusion::Target **curr_target,
        Illusion::Target **scratch_target)
{
  float v7; // xmm1_4
  float v8; // xmm6_4
  Illusion::Material *mMaterial; // rdi
  _WORD *v10; // rbx
  Render::ViewSettings *Identity; // rax
  Illusion::Target **v12; // r14
  __int64 mOffset; // rax
  _WORD *v14; // rax
  Illusion::Target **v15; // rsi
  unsigned int mUID; // r8d
  __int64 v17; // rax
  char *v18; // rbx
  Illusion::StateValues *StateValues; // rax
  Illusion::Target *v20; // rcx
  RenderQueueLayer v21; // [rsp+60h] [rbp-F08h] BYREF
  Render::View v22; // [rsp+140h] [rbp-E28h] BYREF
  LayerSubmitContext ptr; // [rsp+2D0h] [rbp-C98h] BYREF
  Render::Poly poly; // [rsp+F80h] [rbp+18h] BYREF

  if ( render_context->mRenderFeatures.mPostFX )
  {
    v7 = this->mRecoilValue <= 0.0 ? 0.0 : this->mRecoilFalloffScale;
    v8 = this->mRecoilValue - v7;
    this->mRecoilValue = v8;
    if ( v8 > 0.0 )
    {
      mMaterial = Render::gRenderUtilities.mMaterial;
      RenderQueueLayer::RenderQueueLayer(&v21);
      LayerSubmitContext::LayerSubmitContext(&ptr);
      v21.mSerializationList = serialization_list;
      ptr.mRenderQueueProvider = &v21;
      v10 = 0i64;
      ptr.mQueueMode = QM_Single;
      Identity = Render::ViewSettings::GetIdentity();
      Render::View::View(&v22, Identity, &ptr);
      v12 = scratch_target;
      Render::View::BeginTarget(&v22, *scratch_target, "GunRecoilPostEffect", 0, 0, 0i64, 1, 0, 0, 0);
      if ( LODWORD(mMaterial[1].mResourceHandles.UFG::qResourceData::mNode.mNext) != -880245061 )
      {
        UFG::qResourceHandle::Init(
          (UFG::qResourceHandle *)&mMaterial[1].mNode.mChild[1],
          mMaterial[1].mTypeUID,
          0xCB8886BB);
        mOffset = mMaterial->mMaterialUser.mOffset;
        if ( mOffset )
          v14 = (_WORD *)((char *)&mMaterial->mMaterialUser + mOffset);
        else
          v14 = 0i64;
        *v14 |= 0x20u;
      }
      v15 = curr_target;
      mUID = (*curr_target)->mTargetTexture[0]->mNode.mUID;
      if ( LODWORD(mMaterial[1].mStateBlockMask.mFlags[0]) != mUID )
      {
        UFG::qResourceHandle::Init(
          (UFG::qResourceHandle *)&mMaterial[1].mDebugName[20],
          mMaterial[1].mStateBlockMask.mFlags[1],
          mUID);
        v17 = mMaterial->mMaterialUser.mOffset;
        if ( v17 )
          v10 = (_WORD *)((char *)&mMaterial->mMaterialUser + v17);
        *v10 |= 0x20u;
      }
      v18 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x80u, 0x10u);
      *(float *)v18 = v8;
      StateValues = Render::View::GetStateValues(&v22);
      StateValues->mSetValueMask.mFlags[0] |= 0x8000ui64;
      StateValues->mParamValues[15] = v18;
      Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
      Render::View::Draw(&v22, &poly, mMaterial, 0i64);
      Render::View::EndTarget(&v22);
      v20 = *v15;
      *v15 = *v12;
      *v12 = v20;
      `eh vector destructor iterator(
        ptr.mStateArgs.mStateArgs,
        0x10ui64,
        128,
        (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
      RenderQueueLayer::~RenderQueueLayer(&v21);
    }
  }
}

// File Line: 777
// RVA: 0x1456770
__int64 dynamic_initializer_for__UFG::AccumulationBufferPostEffect::_TypeIDesc__()
{
  UFG::ComponentIDDesc *v0; // rax
  __int64 result; // rax

  v0 = UFG::AccumulationBufferPostEffect::AccessComponentDesc();
  *(_DWORD *)&UFG::AccumulationBufferPostEffect::_TypeIDesc.mBaseTypeIndex = *(_DWORD *)&v0->mBaseTypeIndex;
  UFG::AccumulationBufferPostEffect::_TypeIDesc.mChildBitMask = v0->mChildBitMask;
  result = v0->mChildren;
  UFG::AccumulationBufferPostEffect::_TypeIDesc.mChildren = result;
  return result;
}

// File Line: 781
// RVA: 0x5EFF0
void __fastcall UFG::AccumulationBufferPostEffect::AccumulationBufferPostEffect(
        UFG::AccumulationBufferPostEffect *this)
{
  UFG::RenderStagePlugin::RenderStagePlugin(this);
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AccumulationBufferPostEffect::`vftable;
  this->mEnable = 0.0;
  UFG::SimComponent::AddType(
    this,
    UFG::AccumulationBufferPostEffect::_AccumulationBufferPostEffectTypeUID,
    "AccumulationBufferPostEffect");
}

// File Line: 787
// RVA: 0x5FD00
void __fastcall UFG::AccumulationBufferPostEffect::RenderPostEffect(
        UFG::AccumulationBufferPostEffect *this,
        UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list,
        UFG::RenderContext *render_context,
        float delta_time,
        Illusion::Target **curr_target)
{
  Illusion::Material *mMaterial; // rbx
  _WORD *v8; // rdi
  Render::ViewSettings *Identity; // rax
  __int64 mOffset; // rax
  _WORD *v11; // rax
  unsigned int mUID; // r8d
  __int64 v13; // rax
  RenderQueueLayer v14; // [rsp+60h] [rbp-EF8h] BYREF
  Render::View v15; // [rsp+140h] [rbp-E18h] BYREF
  LayerSubmitContext ptr; // [rsp+2D0h] [rbp-C88h] BYREF
  Render::Poly poly; // [rsp+F70h] [rbp+18h] BYREF

  if ( render_context->mRenderFeatures.mPostFX && this->mEnable != 0.0 )
  {
    mMaterial = Render::gRenderUtilities.mMaterial;
    RenderQueueLayer::RenderQueueLayer(&v14);
    LayerSubmitContext::LayerSubmitContext(&ptr);
    v14.mSerializationList = serialization_list;
    ptr.mRenderQueueProvider = &v14;
    v8 = 0i64;
    ptr.mQueueMode = QM_Single;
    Identity = Render::ViewSettings::GetIdentity();
    Render::View::View(&v15, Identity, &ptr);
    Render::View::BeginTarget(
      &v15,
      render_context->mHalfSizeScratchTargetA,
      "AccumulationBuffer",
      0,
      0,
      0i64,
      1,
      0,
      0,
      0);
    if ( LODWORD(mMaterial[1].mResourceHandles.UFG::qResourceData::mNode.mNext) != -917770645 )
    {
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&mMaterial[1].mNode.mChild[1],
        mMaterial[1].mTypeUID,
        0xC94BEE6B);
      mOffset = mMaterial->mMaterialUser.mOffset;
      if ( mOffset )
        v11 = (_WORD *)((char *)&mMaterial->mMaterialUser + mOffset);
      else
        v11 = 0i64;
      *v11 |= 0x20u;
    }
    mUID = (*curr_target)->mTargetTexture[0]->mNode.mUID;
    if ( LODWORD(mMaterial[1].mStateBlockMask.mFlags[0]) != mUID )
    {
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&mMaterial[1].mDebugName[20],
        mMaterial[1].mStateBlockMask.mFlags[1],
        mUID);
      v13 = mMaterial->mMaterialUser.mOffset;
      if ( v13 )
        v8 = (_WORD *)((char *)&mMaterial->mMaterialUser + v13);
      *v8 |= 0x20u;
    }
    Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
    Render::View::Draw(&v15, &poly, mMaterial, 0i64);
    Render::View::EndTarget(&v15);
    `eh vector destructor iterator(
      ptr.mStateArgs.mStateArgs,
      0x10ui64,
      128,
      (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
    RenderQueueLayer::~RenderQueueLayer(&v14);
  }
}

// File Line: 823
// RVA: 0x5FC80
const char *__fastcall UFG::FrontEndPauseEffect::GetTypeName(UFG::FrontEndPauseEffect *this)
{
  return "FrontEndPauseEffect";
}

// File Line: 825
// RVA: 0x5F0B0
void __fastcall UFG::FrontEndPauseEffect::FrontEndPauseEffect(UFG::FrontEndPauseEffect *this)
{
  char v2; // cl

  UFG::RenderStagePlugin::RenderStagePlugin(this);
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::FrontEndPauseEffect::`vftable;
  this->mVisualTreatmentIndex = -1;
  *(_QWORD *)&this->mCurrBlurCount = 0i64;
  this->mRestoreVisualTreatmentAfterBlur = 0;
  UFG::SimComponent::AddType(this, UFG::FrontEndPauseEffect::_FrontEndPauseEffectTypeUID, "FrontEndPauseEffect");
  v2 = sIsStaticInit_1;
  if ( !sIsStaticInit_1 )
    v2 = 1;
  sIsStaticInit_1 = v2;
}

// File Line: 837
// RVA: 0x60930
void __fastcall UFG::FrontEndPauseEffect::Start(UFG::FrontEndPauseEffect *this, unsigned int visual_treatment_uid)
{
  UFG::SimObject *m_pSimObject; // rcx
  UFG::SimComponent *ComponentOfType; // rdi
  int v6; // ebx
  unsigned int *p_mNameUID; // rcx
  int *v8; // rcx
  unsigned __int16 *p_m_Flags; // rdx
  __int64 v10; // rax
  __int128 v11; // xmm0
  __int128 v12; // xmm1
  __int128 v13; // xmm0
  __int128 v14; // xmm1
  __int128 v15; // xmm0
  __int128 v16; // xmm1
  __int128 v17; // xmm0
  __int128 v18; // xmm1
  __int128 v19; // xmm1
  __int64 v20; // rax
  __int128 v21; // xmm0
  int mVisualTreatmentIndex; // eax
  int mNext; // ecx
  int Dst[48]; // [rsp+20h] [rbp-C8h] BYREF

  this->mTargetBlurCount = 20;
  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject
    && (ComponentOfType = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::VisualTreatmentPostEffect::_TypeUID)) != 0i64 )
  {
    v6 = 0;
    if ( UFG::VisualTreatmentPostEffect::msNumVisualTreatments <= 0 )
    {
LABEL_7:
      v6 = -1;
    }
    else
    {
      p_mNameUID = &UFG::VisualTreatmentPostEffect::msStateBlockHandle[0].mNameUID;
      while ( *p_mNameUID != visual_treatment_uid )
      {
        ++v6;
        p_mNameUID += 8;
        if ( v6 >= UFG::VisualTreatmentPostEffect::msNumVisualTreatments )
          goto LABEL_7;
      }
    }
    v8 = Dst;
    this->mVisualTreatmentIndex = v6;
    p_m_Flags = &ComponentOfType[1].m_Flags;
    if ( (((unsigned __int8)Dst | (unsigned __int8)((_BYTE)ComponentOfType + 96)) & 0xF) != 0 )
    {
      memmove(Dst, &ComponentOfType[1].m_Flags, 0xB8ui64);
    }
    else
    {
      v10 = 1i64;
      do
      {
        v11 = *(_OWORD *)p_m_Flags;
        v12 = *((_OWORD *)p_m_Flags + 1);
        v8 += 32;
        p_m_Flags += 64;
        *((_OWORD *)v8 - 8) = v11;
        v13 = *((_OWORD *)p_m_Flags - 6);
        *((_OWORD *)v8 - 7) = v12;
        v14 = *((_OWORD *)p_m_Flags - 5);
        *((_OWORD *)v8 - 6) = v13;
        v15 = *((_OWORD *)p_m_Flags - 4);
        *((_OWORD *)v8 - 5) = v14;
        v16 = *((_OWORD *)p_m_Flags - 3);
        *((_OWORD *)v8 - 4) = v15;
        v17 = *((_OWORD *)p_m_Flags - 2);
        *((_OWORD *)v8 - 3) = v16;
        v18 = *((_OWORD *)p_m_Flags - 1);
        *((_OWORD *)v8 - 2) = v17;
        *((_OWORD *)v8 - 1) = v18;
        --v10;
      }
      while ( v10 );
      v19 = *((_OWORD *)p_m_Flags + 1);
      v20 = *((_QWORD *)p_m_Flags + 6);
      *(_OWORD *)v8 = *(_OWORD *)p_m_Flags;
      v21 = *((_OWORD *)p_m_Flags + 2);
      *((_OWORD *)v8 + 1) = v19;
      *((_OWORD *)v8 + 2) = v21;
      *((_QWORD *)v8 + 6) = v20;
    }
    if ( Dst[0] != v6 )
      UFG::VisualTreatmentPostEffect::SaveState((UFG::VisualTreatmentPostEffect *)ComponentOfType);
    mVisualTreatmentIndex = this->mVisualTreatmentIndex;
    if ( mVisualTreatmentIndex <= -1
      || mVisualTreatmentIndex >= UFG::VisualTreatmentPostEffect::msNumVisualTreatments
      || BYTE4(ComponentOfType[4].m_SafePointerList.mNode.mPrev) && *(int *)(&ComponentOfType[1].m_SimObjIndex + 1) > 10 )
    {
      this->mVisualTreatmentId = -1;
    }
    else
    {
      mNext = (int)ComponentOfType[4].m_SafePointerList.mNode.mNext;
      *(_DWORD *)&ComponentOfType[1].m_Flags = mVisualTreatmentIndex;
      *(_QWORD *)(&ComponentOfType[1].m_SimObjIndex + 1) = 10i64;
      LOBYTE(ComponentOfType[1].m_BoundComponentHandles.mNode.mNext) = 0;
      HIDWORD(ComponentOfType[1].m_pSimObject) = mNext;
      BYTE4(ComponentOfType[4].m_SafePointerList.mNode.mPrev) = 1;
      LODWORD(ComponentOfType[4].m_SafePointerList.mNode.mNext) = mNext + 1;
      this->mVisualTreatmentId = mNext;
    }
  }
  else
  {
    this->mVisualTreatmentId = -1;
  }
}

// File Line: 860
// RVA: 0x5FBA0
void __fastcall UFG::FrontEndPauseEffect::End(UFG::FrontEndPauseEffect *this, bool fade)
{
  UFG::SimObject *m_pSimObject; // rcx
  UFG::VisualTreatmentPostEffect *ComponentOfType; // rax
  float v6; // xmm2_4

  this->mTargetBlurCount = 0;
  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
  {
    ComponentOfType = (UFG::VisualTreatmentPostEffect *)UFG::SimObject::GetComponentOfType(
                                                          m_pSimObject,
                                                          UFG::VisualTreatmentPostEffect::_TypeUID);
    if ( ComponentOfType )
    {
      this->mRestoreVisualTreatmentAfterBlur = 1;
      if ( fade )
        v6 = FLOAT_0_75;
      else
        v6 = 0.0;
      UFG::VisualTreatmentPostEffect::StopVisualTreatment(ComponentOfType, this->mVisualTreatmentId, v6);
    }
  }
}

// File Line: 871
// RVA: 0x60EE0
void __fastcall UFG::FrontEndPauseEffect::Update(UFG::FrontEndPauseEffect *this, float sim_time_delta)
{
  unsigned int mCurrBlurCount; // eax
  unsigned int mTargetBlurCount; // ecx
  unsigned int v5; // eax
  unsigned int v6; // eax
  UFG::VisualTreatmentPostEffect *ComponentOfType; // rdi
  UFG::SimObject *m_pSimObject; // rcx

  mCurrBlurCount = this->mCurrBlurCount;
  mTargetBlurCount = this->mTargetBlurCount;
  if ( mCurrBlurCount >= mTargetBlurCount )
  {
    if ( mCurrBlurCount <= mTargetBlurCount )
      goto LABEL_6;
    v5 = mCurrBlurCount - 2;
  }
  else
  {
    v5 = mCurrBlurCount + 2;
  }
  this->mCurrBlurCount = v5;
LABEL_6:
  v6 = this->mCurrBlurCount;
  ComponentOfType = 0i64;
  if ( v6 )
  {
    if ( v6 >= 0x14 )
      v6 = 20;
  }
  else
  {
    v6 = 0;
  }
  m_pSimObject = this->m_pSimObject;
  this->mCurrBlurCount = v6;
  if ( m_pSimObject )
    ComponentOfType = (UFG::VisualTreatmentPostEffect *)UFG::SimObject::GetComponentOfType(
                                                          m_pSimObject,
                                                          UFG::VisualTreatmentPostEffect::_TypeUID);
  if ( this->mCurrBlurCount && ComponentOfType )
    ((void (__fastcall *)(UFG::VisualTreatmentPostEffect *))ComponentOfType->vfptr[17].__vecDelDtor)(ComponentOfType);
  if ( this->mRestoreVisualTreatmentAfterBlur && !this->mCurrBlurCount )
  {
    UFG::VisualTreatmentPostEffect::RestoreState(ComponentOfType);
    this->mRestoreVisualTreatmentAfterBlur = 0;
  }
}

// File Line: 895
// RVA: 0x60110
void __fastcall UFG::FrontEndPauseEffect::RenderPostEffect(
        UFG::FrontEndPauseEffect *this,
        UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list,
        UFG::RenderContext *render_context,
        float delta_time,
        Illusion::Target **curr_target)
{
  unsigned int mCurrBlurCount; // ebx
  __int64 v9; // rsi
  RenderQueueLayer v10; // [rsp+40h] [rbp-D78h] BYREF
  LayerSubmitContext ptr; // [rsp+120h] [rbp-C98h] BYREF

  RenderQueueLayer::RenderQueueLayer(&v10);
  LayerSubmitContext::LayerSubmitContext(&ptr);
  v10.mSerializationList = serialization_list;
  ptr.mRenderQueueProvider = &v10;
  ptr.mQueueMode = QM_Single;
  Render::gRenderUtilities.mSubmitContext = &ptr;
  mCurrBlurCount = gFrontEndPauseCurrCountOverride;
  if ( gFrontEndPauseCurrCountOverride <= 0 )
    mCurrBlurCount = this->mCurrBlurCount;
  if ( mCurrBlurCount )
  {
    Render::RenderUtilities::GaussBlur3x3(
      &Render::gRenderUtilities,
      *curr_target,
      render_context->mHalfSizeScratchTargetB,
      0,
      0i64,
      0xB0A10EFE);
    Render::RenderUtilities::GaussBlur3x3(
      &Render::gRenderUtilities,
      render_context->mHalfSizeScratchTargetB,
      render_context->mQuarterSizeScratchTargetA,
      0,
      0i64,
      0xB0A10EFE);
  }
  if ( mCurrBlurCount > 1 )
  {
    v9 = mCurrBlurCount - 1;
    do
    {
      Render::RenderUtilities::SeparableGaussBlur5x5(
        &Render::gRenderUtilities,
        render_context->mQuarterSizeScratchTargetA,
        render_context->mQuarterSizeScratchTargetB,
        1,
        0xA57D2FB6);
      Render::RenderUtilities::SeparableGaussBlur5x5(
        &Render::gRenderUtilities,
        render_context->mQuarterSizeScratchTargetB,
        render_context->mQuarterSizeScratchTargetA,
        0,
        0xA57D2FB6);
      --v9;
    }
    while ( v9 );
  }
  if ( mCurrBlurCount )
  {
    Render::RenderUtilities::GaussBlur3x3(
      &Render::gRenderUtilities,
      render_context->mQuarterSizeScratchTargetA,
      render_context->mHalfSizeScratchTargetB,
      0,
      0i64,
      0xB0A10EFE);
    Render::RenderUtilities::GaussBlur3x3(
      &Render::gRenderUtilities,
      render_context->mHalfSizeScratchTargetB,
      *curr_target,
      0,
      0i64,
      0xB0A10EFE);
  }
  Render::gRenderUtilities.mSubmitContext = 0i64;
  `eh vector destructor iterator(
    ptr.mStateArgs.mStateArgs,
    0x10ui64,
    128,
    (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
  RenderQueueLayer::~RenderQueueLayer(&v10);
}

