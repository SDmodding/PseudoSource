// File Line: 83
// RVA: 0x14568D0
__int64 dynamic_initializer_for__UFG::RenderStagePlugin::s_RenderStagePluginList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::RenderStagePlugin::s_RenderStagePluginList__);
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
  UFG::RenderStagePlugin *v1; // rdi
  UFG::qNode<UFG::RenderStagePlugin,UFG::RenderStagePlugin> *v2; // rbx
  UFG::qNode<UFG::RenderStagePlugin,UFG::RenderStagePlugin> *v3; // rax

  v1 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, 0);
  v2 = (UFG::qNode<UFG::RenderStagePlugin,UFG::RenderStagePlugin> *)&v1->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  v1->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::RenderStagePlugin::`vftable';
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v1->vfptr,
    UFG::RenderStagePlugin::_RenderStagePluginTypeUID,
    "RenderStagePlugin");
  v3 = UFG::RenderStagePlugin::s_RenderStagePluginList.mNode.mPrev;
  UFG::RenderStagePlugin::s_RenderStagePluginList.mNode.mPrev->mNext = (UFG::qNode<UFG::RenderStagePlugin,UFG::RenderStagePlugin> *)&v1->mPrev;
  v2->mPrev = v3;
  v1->mNext = (UFG::qNode<UFG::RenderStagePlugin,UFG::RenderStagePlugin> *)&UFG::RenderStagePlugin::s_RenderStagePluginList;
  UFG::RenderStagePlugin::s_RenderStagePluginList.mNode.mPrev = (UFG::qNode<UFG::RenderStagePlugin,UFG::RenderStagePlugin> *)&v1->mPrev;
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
  UFG::SimComponent *v1; // rbx
  char v2; // cl

  v1 = (UFG::SimComponent *)&this->vfptr;
  UFG::RenderStagePlugin::RenderStagePlugin((UFG::RenderStagePlugin *)&this->vfptr);
  v1->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::DamagePostEffect::`vftable';
  v1[1].m_SafePointerList.mNode.mNext = 0i64;
  UFG::SimComponent::AddType(v1, UFG::DamagePostEffect::_DamagePostEffectTypeUID, "DamagePostEffect");
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
void __fastcall UFG::DamagePostEffect::RenderPostEffect(UFG::DamagePostEffect *this, UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list, UFG::RenderContext *render_context, float delta_time, Illusion::Target **curr_target, Illusion::Target **scratch_target)
{
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v6; // rbx
  float v7; // xmm6_4
  Illusion::Material *v8; // rdi
  _WORD *v9; // rbx
  Render::ViewSettings *v10; // rax
  Illusion::Target **v11; // r14
  __int64 v12; // rax
  _WORD *v13; // rax
  Illusion::Target **v14; // rsi
  unsigned int v15; // er8
  __int64 v16; // rax
  char *v17; // rbx
  Illusion::StateValues *v18; // rax
  Illusion::Target *v19; // rcx
  RenderQueueLayer v20; // [rsp+60h] [rbp-F08h]
  Render::View v21; // [rsp+140h] [rbp-E28h]
  LayerSubmitContext ptr; // [rsp+2D0h] [rbp-C98h]
  Render::Poly poly; // [rsp+F80h] [rbp+18h]

  v6 = serialization_list;
  if ( render_context->mRenderFeatures.mPostFX )
  {
    v7 = powf(this->mDamageCurrentMagnitude, 4.0) * 12.0;
    if ( v7 > 0.0099999998 )
    {
      v8 = Render::gRenderUtilities.mMaterial;
      RenderQueueLayer::RenderQueueLayer(&v20);
      LayerSubmitContext::LayerSubmitContext(&ptr);
      v20.mSerializationList = v6;
      ptr.mRenderQueueProvider = &v20;
      v9 = 0i64;
      ptr.mQueueMode = 0;
      v10 = Render::ViewSettings::GetIdentity();
      Render::View::View(&v21, v10, (Illusion::SubmitContext *)&ptr.vfptr);
      v11 = scratch_target;
      Render::View::BeginTarget(&v21, *scratch_target, "DamagePostEffect", 0, 0, 0i64, 1, 0, 0, 0);
      if ( LODWORD(v8[1].mResourceHandles.mNode.mNext) != 250757386 )
      {
        UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v8[1].mNode.mChild[1], v8[1].mTypeUID, 0xEF2410Au);
        v12 = v8->mMaterialUser.mOffset;
        if ( v12 )
          v13 = (_WORD *)((char *)&v8->mMaterialUser + v12);
        else
          v13 = 0i64;
        *v13 |= 0x20u;
      }
      v14 = curr_target;
      v15 = (*curr_target)->mTargetTexture[0]->mNode.mUID;
      if ( LODWORD(v8[1].mStateBlockMask.mFlags[0]) != v15 )
      {
        UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v8[1].mDebugName[20], v8[1].mStateBlockMask.mFlags[1], v15);
        v16 = v8->mMaterialUser.mOffset;
        if ( v16 )
          v9 = (_WORD *)((char *)&v8->mMaterialUser + v16);
        *v9 |= 0x20u;
      }
      v17 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x80u, 0x10u);
      *(float *)v17 = v7;
      v18 = Render::View::GetStateValues(&v21);
      v18->mSetValueMask.mFlags[0] |= 0x8000ui64;
      v18->mParamValues[15] = v17;
      Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
      Render::View::Draw(&v21, &poly, v8, 0i64);
      Render::View::EndTarget(&v21);
      v19 = *v14;
      *v14 = *v11;
      *v11 = v19;
      `eh vector destructor iterator'(
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
  `eh vector constructor iterator'(
    UFG::VisualTreatmentPostEffect::msStateBlockHandle,
    0x20ui64,
    128,
    (void (__fastcall *)(void *))Illusion::StateBlockHandle::StateBlockHandle);
  return atexit(dynamic_atexit_destructor_for__UFG::VisualTreatmentPostEffect::msStateBlockHandle__);
}

// File Line: 181
// RVA: 0x60BE0
void __fastcall UFG::VisualTreatmentPostEffect::StaticInit(const char **visual_treatment_name, int num_visualtreatment_names)
{
  __int64 v2; // rbx
  const char **v3; // r14
  UFG::qResourceWarehouse *v4; // rax
  __int64 v5; // rdi
  __int64 v6; // rbp
  Illusion::StateBlockInventory *v7; // r15
  unsigned int v8; // eax
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *v9; // rax
  __int64 v10; // rbx
  unsigned int v11; // esi
  UFG::qResourceInventory *v12; // rax
  Illusion::StateBlockHandle *v13; // rbx
  UFG::qResourceWarehouse *v14; // rax
  int v15; // eax
  int v16; // eax
  char dest; // [rsp+20h] [rbp-128h]

  v2 = num_visualtreatment_names;
  v3 = visual_treatment_name;
  v4 = UFG::qResourceWarehouse::Instance();
  v5 = 0i64;
  v6 = v2;
  v7 = (Illusion::StateBlockInventory *)UFG::qResourceWarehouse::GetInventory(v4, 0x4D04C7F2u);
  if ( (signed int)v2 <= 0 )
  {
    v15 = UFG::VisualTreatmentPostEffect::msNumVisualTreatments;
  }
  else
  {
    do
    {
      UFG::qSPrintf(&dest, 255, "StateBlock.%s_VisualTreatment", v3[v5]);
      v8 = UFG::qStringHashUpper32(&dest, 0xFFFFFFFF);
      v9 = Illusion::StateBlockInventory::GetStateBlock(v7, v8, 1);
      if ( v9 )
      {
        v10 = UFG::VisualTreatmentPostEffect::msNumVisualTreatments;
        UFG::VisualTreatmentPostEffect::msStateBlockName[v10] = v3[v5];
        v11 = (unsigned int)v9[1].mNode.mNext;
        v12 = `UFG::qGetResourceInventory<Illusion::StateBlock>'::`2'::result;
        v13 = &UFG::VisualTreatmentPostEffect::msStateBlockHandle[v10];
        if ( !`UFG::qGetResourceInventory<Illusion::StateBlock>'::`2'::result )
        {
          v14 = UFG::qResourceWarehouse::Instance();
          v12 = UFG::qResourceWarehouse::GetInventory(v14, 0x4D04C7F2u);
          `UFG::qGetResourceInventory<Illusion::StateBlock>'::`2'::result = v12;
        }
        UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v13->mPrev, 0x4D04C7F2u, v11, v12);
        v15 = UFG::VisualTreatmentPostEffect::msNumVisualTreatments++ + 1;
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
  UFG::VisualTreatmentPostEffect *v1; // rbx
  UFG::qResourceInventory *v2; // rax
  UFG::qResourceWarehouse *v3; // rax
  unsigned __int64 v4; // rax
  unsigned int v5; // er10
  UFG::qResourceData *i; // rdx
  char *v7; // r9
  int v8; // er8
  signed __int64 v9; // rdx
  __int64 v10; // r8
  float *v11; // rax
  float v12; // xmm0_4
  int v13; // ecx
  UFG::qResourceInventory *v14; // rax
  UFG::qResourceWarehouse *v15; // rax
  UFG::qResourceHandle v16; // [rsp+28h] [rbp-40h]

  v1 = this;
  UFG::RenderStagePlugin::RenderStagePlugin((UFG::RenderStagePlugin *)&this->vfptr);
  v1->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::VisualTreatmentPostEffect::`vftable';
  v1->mState.mNumAdditive = 0;
  v1->mState.mBasePlaying = 0;
  v1->mState.mTreatmentID = 0;
  v1->mState.mRenderTreatment = 0;
  v1->mSavedState.mNumAdditive = 0;
  v1->mSavedState.mBasePlaying = 0;
  v1->mSavedState.mTreatmentID = 0;
  v1->mSavedState.mRenderTreatment = 0;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v1->vfptr,
    UFG::VisualTreatmentPostEffect::_VisualTreatmentPostEffectTypeUID,
    "VisualTreatmentPostEffect");
  UFG::VisualTreatmentPostEffect::msNumVisualTreatments = 0;
  v1->mShouldSetCameraFOVOffset = 0;
  v1->mCameraFOVOffset = 0.0;
  *(_OWORD *)gVisualTreatmentParams.Value0 = _xmm;
  *(_OWORD *)gVisualTreatmentParams.Value1 = _xmm;
  *(_OWORD *)gVisualTreatmentParams.Value2 = _xmm;
  *(_OWORD *)gVisualTreatmentParams.Value3 = _xmm;
  gVisualTreatmentParams.FovOffset = 0.0;
  LODWORD(gVisualTreatmentParams.TimeScale) = (_DWORD)FLOAT_1_0;
  v1->mDefaultVisualTreatmentParams = 0i64;
  UFG::qResourceHandle::qResourceHandle(&v16);
  v2 = `UFG::qGetResourceInventory<Illusion::StateBlock>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::StateBlock>'::`2'::result )
  {
    v3 = UFG::qResourceWarehouse::Instance();
    v2 = UFG::qResourceWarehouse::GetInventory(v3, 0x4D04C7F2u);
    `UFG::qGetResourceInventory<Illusion::StateBlock>'::`2'::result = v2;
  }
  UFG::qResourceHandle::Init(&v16, 0x4D04C7F2u, 0x8906EE5D, v2);
  if ( v16.mData )
  {
    v4 = 4i64 * v16.mData[1].mNode.mUID;
    if ( !is_mul_ok(v16.mData[1].mNode.mUID, 4ui64) )
      v4 = -1i64;
    v1->mDefaultVisualTreatmentParams = (float *)UFG::qMalloc(v4, "mDefaultVisualTreatmentParams", 0i64);
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
      v9 = (signed __int64)(v7 + 132);
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
              v9 += 8i64;
              v11 += 2;
              if ( ++v13 >= (unsigned int)v10 )
                goto LABEL_17;
            }
            v12 = (float)((float)(v11[1] - *(float *)(v9 + 4))
                        * (float)(COERCE_FLOAT(*(_DWORD *)v9 ^ _xmm[0]) / (float)(*v11 - *(float *)v9)))
                + *(float *)(v9 + 4);
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
      v1->mDefaultVisualTreatmentParams[v5++] = v12;
    }
  }
  v14 = `UFG::qGetResourceInventory<Illusion::StateBlock>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::StateBlock>'::`2'::result )
  {
    v15 = UFG::qResourceWarehouse::Instance();
    v14 = UFG::qResourceWarehouse::GetInventory(v15, 0x4D04C7F2u);
    `UFG::qGetResourceInventory<Illusion::StateBlock>'::`2'::result = v14;
  }
  UFG::qResourceHandle::Close(&v16, v14);
  UFG::qResourceHandle::~qResourceHandle(&v16);
}

// File Line: 355
// RVA: 0x5F850
void __fastcall UFG::VisualTreatmentPostEffect::AccumulateTreatment(UFG::VisualTreatmentPostEffect *this, float *treatmentParams, UFG::VisualTreatmentPostEffect::TreatmentComponent *component, float sim_time_delta, bool *expired)
{
  UFG::VisualTreatmentPostEffect *v5; // r15
  __int64 v6; // rdi
  float *v7; // rbp
  __int64 v8; // r9
  float v9; // xmm2_4
  float v10; // xmm1_4
  float v11; // xmm3_4
  float v12; // xmm4_4
  float v13; // xmm0_4
  float v14; // xmm6_4
  char v15; // al
  unsigned int v16; // er14
  float v17; // xmm4_4
  char *v18; // r10
  __int64 v19; // rbx
  unsigned __int16 *v20; // r11
  signed __int64 v21; // rsi
  __int64 v22; // rcx
  int v23; // er8
  float *v24; // rdx
  __int64 v25; // r8
  float *v26; // rax
  float v27; // xmm3_4
  unsigned int v28; // ecx
  float v29; // xmm0_4
  float v30; // xmm3_4
  float v31; // xmm4_4
  float v32; // xmm4_4
  float *v33; // r10
  __int64 v34; // rbx
  unsigned __int16 *v35; // r11
  __int64 v36; // rcx
  int v37; // er8
  float *v38; // rdx
  __int64 v39; // r8
  float *v40; // rax
  float v41; // xmm3_4
  unsigned int v42; // ecx
  unsigned int v43; // ecx
  float *v44; // rdx
  __int64 v45; // rax
  float v46; // [rsp+0h] [rbp-78h]
  float v47; // [rsp+4h] [rbp-74h]
  char v48; // [rsp+8h] [rbp-70h]

  v5 = this;
  v6 = *((_QWORD *)&UFG::VisualTreatmentPostEffect::msStateBlockHandle[0].mData + 4 * component->mTreatmentIndex);
  v7 = treatmentParams;
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
    v31 = component->mTimeElapsed;
    v16 = *(_DWORD *)(v6 + 112);
    v47 = v10;
    v32 = v31 / v9;
    v46 = v32;
    if ( v16 <= 2 )
      goto LABEL_39;
    v33 = (float *)&v48;
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
      *v33 = v41;
      ++v33;
      v35 += 2;
      if ( !--v34 )
        goto LABEL_39;
    }
  }
  v11 = sim_time_delta + component->mFadeOutElapsed;
  v12 = component->mFadeOutDuration;
  component->mFadeOutElapsed = v11;
  v13 = v11 / v12;
  if ( (float)(v11 / v12) <= 0.0 )
  {
    v13 = 0.0;
    goto LABEL_6;
  }
  v14 = *(float *)&FLOAT_1_0;
  if ( v13 < 1.0 )
LABEL_6:
    v14 = v13;
  v15 = *expired;
  if ( v11 > v12 )
    v15 = 1;
  v47 = v10;
  *expired = v15;
  v16 = *(_DWORD *)(v6 + 112);
  v17 = component->mTimeElapsed / v9;
  v46 = component->mTimeElapsed / v9;
  if ( v16 > 2 )
  {
    v18 = &v48;
    v19 = v16 - 2;
    v20 = (unsigned __int16 *)(((*(_DWORD *)(v6 + 108) + 15) & 0xFFFFFFF0) + v6 + 136);
    v21 = (char *)this->mDefaultVisualTreatmentParams - &v48;
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
    v44 = v5->mDefaultVisualTreatmentParams;
    do
    {
      v45 = v43++;
      v7[v45] = (float)(*(&v46 + v45) - v44[v45]) + v7[v45];
    }
    while ( v43 < *(_DWORD *)(v6 + 112) );
  }
}

// File Line: 436
// RVA: 0x60530
void __fastcall UFG::VisualTreatmentPostEffect::RenderPostEffect(UFG::VisualTreatmentPostEffect *this, UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list, UFG::RenderContext *render_context, float delta_time, Illusion::Target **curr_target, Illusion::Target **scratch_target)
{
  UFG::RenderContext *v6; // rsi
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v7; // rdi
  UFG::VisualTreatmentPostEffect *v8; // rbp
  Illusion::Material *v9; // rbx
  _WORD *v10; // rdi
  Render::ViewSettings *v11; // rax
  Illusion::Target **v12; // r15
  __int64 v13; // rax
  _WORD *v14; // rax
  Illusion::Target **v15; // r14
  unsigned int v16; // er8
  __int64 v17; // rax
  _WORD *v18; // rax
  unsigned int v19; // er8
  __int64 v20; // rax
  char *v21; // rdi
  int v22; // xmm1_4
  Illusion::StateValues *v23; // rax
  Illusion::Target *v24; // rcx
  RenderQueueLayer v25; // [rsp+60h] [rbp-F08h]
  Render::View v26; // [rsp+140h] [rbp-E28h]
  LayerSubmitContext ptr; // [rsp+2D0h] [rbp-C98h]
  Render::Poly poly; // [rsp+F80h] [rbp+18h]

  v6 = render_context;
  v7 = serialization_list;
  v8 = this;
  if ( render_context->mRenderFeatures.mPostFX && this->mState.mRenderTreatment )
  {
    v9 = Render::gRenderUtilities.mMaterial;
    RenderQueueLayer::RenderQueueLayer(&v25);
    LayerSubmitContext::LayerSubmitContext(&ptr);
    v25.mSerializationList = v7;
    ptr.mRenderQueueProvider = &v25;
    v10 = 0i64;
    ptr.mQueueMode = 0;
    v11 = Render::ViewSettings::GetIdentity();
    Render::View::View(&v26, v11, (Illusion::SubmitContext *)&ptr.vfptr);
    v12 = scratch_target;
    Render::View::BeginTarget(&v26, *scratch_target, "VisualTreatmentPostEffect", 0, 0, 0i64, 1, 0, 0, 0);
    if ( LODWORD(v9[1].mResourceHandles.mNode.mNext) != 557606856 )
    {
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v9[1].mNode.mChild[1], v9[1].mTypeUID, 0x213C67C8u);
      v13 = v9->mMaterialUser.mOffset;
      if ( v13 )
        v14 = (_WORD *)((char *)&v9->mMaterialUser + v13);
      else
        v14 = 0i64;
      *v14 |= 0x20u;
    }
    v15 = curr_target;
    v16 = (*curr_target)->mTargetTexture[0]->mNode.mUID;
    if ( LODWORD(v9[1].mStateBlockMask.mFlags[0]) != v16 )
    {
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v9[1].mDebugName[20], v9[1].mStateBlockMask.mFlags[1], v16);
      v17 = v9->mMaterialUser.mOffset;
      if ( v17 )
        v18 = (_WORD *)((char *)&v9->mMaterialUser + v17);
      else
        v18 = 0i64;
      *v18 |= 0x20u;
    }
    v19 = v6->mHalfSizeScratchTargetA->mTargetTexture[0]->mNode.mUID;
    if ( *(_DWORD *)&v9[3].mDebugName[12] != v19 )
    {
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&v9[3].mResourceHandles.mNode.mNext,
        *(_DWORD *)&v9[3].mDebugName[20],
        v19);
      v20 = v9->mMaterialUser.mOffset;
      if ( v20 )
        v10 = (_WORD *)((char *)&v9->mMaterialUser + v20);
      *v10 |= 0x20u;
    }
    v21 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x80u, 0x10u);
    UFG::qMemCopy(v21, &v8->mShaderParams, 0x80u);
    v22 = *((_DWORD *)v21 + 12);
    if ( COERCE_FLOAT(*((_DWORD *)v21 + 12) & _xmm) < 0.000099999997 )
      v22 = (signed int)FLOAT_1_0;
    *((_DWORD *)v21 + 12) = v22;
    v23 = Render::View::GetStateValues(&v26);
    v23->mSetValueMask.mFlags[0] |= 0x8000ui64;
    v23->mParamValues[15] = v21;
    Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
    Render::View::Draw(&v26, &poly, v9, 0i64);
    Render::View::EndTarget(&v26);
    v24 = *v15;
    *v15 = *v12;
    *v12 = v24;
    `eh vector destructor iterator'(
      ptr.mStateArgs.mStateArgs,
      0x10ui64,
      128,
      (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
    RenderQueueLayer::~RenderQueueLayer(&v25);
  }
}

// File Line: 478
// RVA: 0x60F80
void __fastcall UFG::VisualTreatmentPostEffect::Update(UFG::VisualTreatmentPostEffect *this, float sim_time_delta)
{
  float *v2; // rdx
  UFG::VisualTreatmentPostEffect *v3; // rbx
  bool v4; // cl
  unsigned int v5; // edi
  signed __int64 v6; // rsi
  signed __int64 v7; // rcx
  __int128 v8; // xmm6
  float v9; // xmm6_4
  float v10; // xmm3_4
  float v11; // xmm0_4
  bool v12; // zf
  int v13; // xmm0_4
  float v14; // xmm6_4
  char dest; // [rsp+30h] [rbp-68h]
  float v16; // [rsp+54h] [rbp-44h]
  float v17; // [rsp+58h] [rbp-40h]
  float v18; // [rsp+5Ch] [rbp-3Ch]
  float v19; // [rsp+6Ch] [rbp-2Ch]
  int v20; // [rsp+70h] [rbp-28h]
  bool expired; // [rsp+A0h] [rbp+8h]

  v2 = this->mDefaultVisualTreatmentParams;
  v3 = this;
  if ( !v2 )
    return;
  this->mShouldSetCameraFOVOffset = 0;
  UFG::qMemCopy(&dest, v2, 0x50u);
  v4 = v3->mState.mBasePlaying;
  v3->mState.mRenderTreatment = 0;
  if ( !v4 )
    goto LABEL_28;
  if ( v3->mState.mBaseTreatment.mTreatmentIndex == gVisualTreatmentTweaker )
  {
    UFG::qMemCopy(&dest, &gVisualTreatmentParams, 0x50u);
    v3->mState.mRenderTreatment = 1;
    goto LABEL_15;
  }
  if ( !v4 || v3->mState.mBaseTreatment.mTreatmentIndex < gVisualTreatmentCount )
  {
LABEL_28:
    if ( v4 )
    {
      v3->mState.mRenderTreatment = 1;
      expired = 0;
      UFG::VisualTreatmentPostEffect::AccumulateTreatment(
        v3,
        (float *)&dest,
        &v3->mState.mBaseTreatment,
        sim_time_delta,
        &expired);
      if ( expired )
        v3->mState.mBasePlaying = 0;
    }
    v5 = 0;
    if ( v3->mState.mNumAdditive )
    {
      do
      {
        v3->mState.mRenderTreatment = 1;
        v6 = (signed __int64)v3 + 28 * v5;
        expired = 0;
        UFG::VisualTreatmentPostEffect::AccumulateTreatment(
          v3,
          (float *)&dest,
          (UFG::VisualTreatmentPostEffect::TreatmentComponent *)(v6 + 124),
          sim_time_delta,
          &expired);
        if ( expired )
        {
          v7 = v3->mState.mNumAdditive - 1;
          *(_DWORD *)(v6 + 124) = v3->mState.mAdditiveTreatment[v7].mTreatmentIndex;
          *(_DWORD *)(v6 + 128) = v3->mState.mAdditiveTreatment[v7].mPriority;
          *(float *)(v6 + 132) = v3->mState.mAdditiveTreatment[v7].mTimeElapsed;
          *(_DWORD *)(v6 + 136) = v3->mState.mAdditiveTreatment[v7].mId;
          *(float *)(v6 + 140) = v3->mState.mAdditiveTreatment[v7].mFadeOutDuration;
          *(float *)(v6 + 144) = v3->mState.mAdditiveTreatment[v7].mFadeOutElapsed;
          *(_DWORD *)(v6 + 148) = *(_DWORD *)&v3->mState.mAdditiveTreatment[v7].mFadeOut;
          --v3->mState.mNumAdditive;
        }
        else
        {
          ++v5;
        }
      }
      while ( v5 < v3->mState.mNumAdditive );
    }
  }
LABEL_15:
  v8 = LODWORD(UFG::TimeOfDayManager::GetInstance()->mTodEV);
  v9 = *(float *)&v8 + UFG::TimeOfDayManager::GetInstance()->mMeteringEV;
  if ( v9 <= 0.0 )
  {
    v9 = 0.0;
  }
  else
  {
    v10 = *(float *)&FLOAT_1_0;
    if ( v9 >= 1.0 )
      goto LABEL_20;
  }
  v10 = v9;
LABEL_20:
  v16 = v16 + (float)(v10 * 0.0);
  v17 = v17 + (float)(v10 * 0.0);
  v18 = v18 + (float)(v10 * 0.0);
  v11 = FLOAT_0_60000002;
  if ( (float)(v19 + (float)(v10 * -0.2)) <= 0.60000002 )
    v11 = v19 + (float)(v10 * -0.2);
  v12 = v3->mState.mRenderTreatment == 0;
  v19 = v11;
  if ( v12 )
  {
    if ( firstFrameOff )
    {
      v3->mShouldSetCameraFOVOffset = 1;
      v3->mCameraFOVOffset = 0.0;
      UFG::TimeOfDayManager::GetInstance()->mVisualTreatmentEV = 0.0;
      firstFrameOff = 0;
    }
  }
  else
  {
    v13 = v20;
    v3->mShouldSetCameraFOVOffset = 1;
    LODWORD(v3->mCameraFOVOffset) = v13;
    UFG::TimeOfDayManager::GetInstance();
    UFG::TimeOfDayManager::GetInstance();
    v14 = v16;
    UFG::TimeOfDayManager::GetInstance()->mVisualTreatmentEV = v14;
    UFG::qMemCopy(&v3->mShaderParams, &dest, 0x80u);
    firstFrameOff = 1;
  }
}

// File Line: 603
// RVA: 0x60AF0
signed __int64 __fastcall UFG::VisualTreatmentPostEffect::StartVisualTreatment(UFG::VisualTreatmentPostEffect *this, int index, bool isAdditive, int priority)
{
  UFG::VisualTreatmentPostEffect *v4; // r10
  __int64 v5; // rax
  unsigned int v6; // ecx
  signed __int64 result; // rax

  v4 = this;
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
      v5 = this->mState.mNumAdditive;
      if ( (unsigned int)v5 < 5 )
      {
        this->mState.mAdditiveTreatment[v5].mTreatmentIndex = index;
        this->mState.mAdditiveTreatment[this->mState.mNumAdditive].mTimeElapsed = 0.0;
        this->mState.mAdditiveTreatment[this->mState.mNumAdditive].mFadeOut = 0;
        this->mState.mAdditiveTreatment[this->mState.mNumAdditive].mId = this->mState.mTreatmentID;
        v6 = this->mState.mNumAdditive;
        result = v4->mState.mAdditiveTreatment[v4->mState.mNumAdditive].mId;
        ++v4->mState.mTreatmentID;
        v4->mState.mNumAdditive = v6 + 1;
        return result;
      }
    }
  }
  return 0xFFFFFFFFi64;
}

// File Line: 641
// RVA: 0x60D80
void __fastcall UFG::VisualTreatmentPostEffect::StopVisualTreatment(UFG::VisualTreatmentPostEffect *this, unsigned int treatmentId, float fade_duration)
{
  unsigned int v3; // er9
  UFG::VisualTreatmentPostEffect *v4; // r8
  int v5; // xmm0_4
  unsigned int v6; // edx
  signed __int64 v7; // rcx
  int v8; // xmm0_4
  signed __int64 v9; // rcx
  signed __int64 v10; // rdx
  __int64 v11; // rax
  signed __int64 v12; // rcx

  v3 = treatmentId;
  v4 = this;
  if ( this->mState.mBasePlaying && this->mState.mBaseTreatment.mId == treatmentId )
  {
    *(float *)&v5 = fade_duration;
    if ( fade_duration < 0.0 )
      v5 = LODWORD(fade_duration) ^ _xmm[0];
    if ( *(float *)&v5 >= 0.001 )
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
    v6 = this->mState.mNumAdditive;
    v7 = 0i64;
    if ( v6 )
    {
      while ( v4->mState.mAdditiveTreatment[(unsigned int)v7].mId != v3 )
      {
        v7 = (unsigned int)(v7 + 1);
        if ( (unsigned int)v7 >= v6 )
          return;
      }
      *(float *)&v8 = fade_duration;
      if ( fade_duration < 0.0 )
        v8 = LODWORD(fade_duration) ^ _xmm[0];
      if ( *(float *)&v8 >= 0.001 )
      {
        v11 = (unsigned int)v7;
        v12 = v7;
        v4->mState.mAdditiveTreatment[v12].mFadeOut = 1;
        v4->mState.mAdditiveTreatment[v12].mFadeOutElapsed = 0.0;
        *((float *)&v4->vfptr + 7 * (v11 + 5)) = fade_duration;
      }
      else
      {
        v9 = v7;
        v10 = v6 - 1;
        v4->mState.mAdditiveTreatment[v9].mTreatmentIndex = v4->mState.mAdditiveTreatment[v10].mTreatmentIndex;
        v4->mState.mAdditiveTreatment[v9].mPriority = v4->mState.mAdditiveTreatment[v10].mPriority;
        v4->mState.mAdditiveTreatment[v9].mTimeElapsed = v4->mState.mAdditiveTreatment[v10].mTimeElapsed;
        v4->mState.mAdditiveTreatment[v9].mId = v4->mState.mAdditiveTreatment[v10].mId;
        v4->mState.mAdditiveTreatment[v9].mFadeOutDuration = v4->mState.mAdditiveTreatment[v10].mFadeOutDuration;
        v4->mState.mAdditiveTreatment[v9].mFadeOutElapsed = v4->mState.mAdditiveTreatment[v10].mFadeOutElapsed;
        *(_DWORD *)&v4->mState.mAdditiveTreatment[v9].mFadeOut = *(_DWORD *)&v4->mState.mAdditiveTreatment[v10].mFadeOut;
        --v4->mState.mNumAdditive;
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
  UFG::VisualTreatmentPostEffect::State *v1; // rdx
  UFG::VisualTreatmentPostEffect::State *v2; // r9
  signed __int64 v3; // rax
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

  v1 = &this->mState;
  v2 = &this->mSavedState;
  if ( ((unsigned __int8)((_BYTE)this + 24) | (unsigned __int8)((_BYTE)this + 96)) & 0xF )
  {
    memmove(&this->mSavedState, v1, 0xB8ui64);
  }
  else
  {
    v3 = 1i64;
    do
    {
      v4 = *(_OWORD *)&v1->mBaseTreatment.mTreatmentIndex;
      v5 = *(_OWORD *)&v1->mBaseTreatment.mFadeOutDuration;
      v2 = (UFG::VisualTreatmentPostEffect::State *)((char *)v2 + 128);
      v1 = (UFG::VisualTreatmentPostEffect::State *)((char *)v1 + 128);
      *(_OWORD *)&v2[-1].mAdditiveTreatment[1].mTreatmentIndex = v4;
      v6 = *(_OWORD *)&v1[-1].mAdditiveTreatment[2].mPriority;
      *(_OWORD *)&v2[-1].mAdditiveTreatment[1].mFadeOutDuration = v5;
      v7 = *(_OWORD *)&v1[-1].mAdditiveTreatment[2].mFadeOutElapsed;
      *(_OWORD *)&v2[-1].mAdditiveTreatment[2].mPriority = v6;
      v8 = *(_OWORD *)&v1[-1].mAdditiveTreatment[3].mTimeElapsed;
      *(_OWORD *)&v2[-1].mAdditiveTreatment[2].mFadeOutElapsed = v7;
      v9 = *(_OWORD *)&v1[-1].mAdditiveTreatment[3].mFadeOut;
      *(_OWORD *)&v2[-1].mAdditiveTreatment[3].mTimeElapsed = v8;
      v10 = *(_OWORD *)&v1[-1].mAdditiveTreatment[4].mId;
      *(_OWORD *)&v2[-1].mAdditiveTreatment[3].mFadeOut = v9;
      v11 = *(_OWORD *)&v1[-1].mNumAdditive;
      *(_OWORD *)&v2[-1].mAdditiveTreatment[4].mId = v10;
      *(_OWORD *)&v2[-1].mNumAdditive = v11;
      --v3;
    }
    while ( v3 );
    v12 = *(_OWORD *)&v1->mBaseTreatment.mFadeOutDuration;
    v13 = *(_QWORD *)&v1->mAdditiveTreatment[0].mFadeOutElapsed;
    *(_OWORD *)&v2->mBaseTreatment.mTreatmentIndex = *(_OWORD *)&v1->mBaseTreatment.mTreatmentIndex;
    v14 = *(_OWORD *)&v1->mAdditiveTreatment[0].mPriority;
    *(_OWORD *)&v2->mBaseTreatment.mFadeOutDuration = v12;
    *(_OWORD *)&v2->mAdditiveTreatment[0].mPriority = v14;
    *(_QWORD *)&v2->mAdditiveTreatment[0].mFadeOutElapsed = v13;
  }
}

// File Line: 705
// RVA: 0x607D0
void __fastcall UFG::VisualTreatmentPostEffect::RestoreState(UFG::VisualTreatmentPostEffect *this)
{
  UFG::VisualTreatmentPostEffect::State *v1; // rdx
  UFG::VisualTreatmentPostEffect::State *v2; // r9
  signed __int64 v3; // rax
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

  v1 = &this->mSavedState;
  v2 = &this->mState;
  if ( ((unsigned __int8)((_BYTE)this + 96) | (unsigned __int8)((_BYTE)this + 24)) & 0xF )
  {
    memmove(&this->mState, v1, 0xB8ui64);
  }
  else
  {
    v3 = 1i64;
    do
    {
      v4 = *(_OWORD *)&v1->mBaseTreatment.mTreatmentIndex;
      v5 = *(_OWORD *)&v1->mBaseTreatment.mFadeOutDuration;
      v2 = (UFG::VisualTreatmentPostEffect::State *)((char *)v2 + 128);
      v1 = (UFG::VisualTreatmentPostEffect::State *)((char *)v1 + 128);
      *(_OWORD *)&v2[-1].mAdditiveTreatment[1].mTreatmentIndex = v4;
      v6 = *(_OWORD *)&v1[-1].mAdditiveTreatment[2].mPriority;
      *(_OWORD *)&v2[-1].mAdditiveTreatment[1].mFadeOutDuration = v5;
      v7 = *(_OWORD *)&v1[-1].mAdditiveTreatment[2].mFadeOutElapsed;
      *(_OWORD *)&v2[-1].mAdditiveTreatment[2].mPriority = v6;
      v8 = *(_OWORD *)&v1[-1].mAdditiveTreatment[3].mTimeElapsed;
      *(_OWORD *)&v2[-1].mAdditiveTreatment[2].mFadeOutElapsed = v7;
      v9 = *(_OWORD *)&v1[-1].mAdditiveTreatment[3].mFadeOut;
      *(_OWORD *)&v2[-1].mAdditiveTreatment[3].mTimeElapsed = v8;
      v10 = *(_OWORD *)&v1[-1].mAdditiveTreatment[4].mId;
      *(_OWORD *)&v2[-1].mAdditiveTreatment[3].mFadeOut = v9;
      v11 = *(_OWORD *)&v1[-1].mNumAdditive;
      *(_OWORD *)&v2[-1].mAdditiveTreatment[4].mId = v10;
      *(_OWORD *)&v2[-1].mNumAdditive = v11;
      --v3;
    }
    while ( v3 );
    v12 = *(_OWORD *)&v1->mBaseTreatment.mFadeOutDuration;
    v13 = *(_QWORD *)&v1->mAdditiveTreatment[0].mFadeOutElapsed;
    *(_OWORD *)&v2->mBaseTreatment.mTreatmentIndex = *(_OWORD *)&v1->mBaseTreatment.mTreatmentIndex;
    v14 = *(_OWORD *)&v1->mAdditiveTreatment[0].mPriority;
    *(_OWORD *)&v2->mBaseTreatment.mFadeOutDuration = v12;
    *(_OWORD *)&v2->mAdditiveTreatment[0].mPriority = v14;
    *(_QWORD *)&v2->mAdditiveTreatment[0].mFadeOutElapsed = v13;
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
  UFG::GunRecoilPostEffect *v1; // rbx
  char v2; // cl

  v1 = this;
  UFG::RenderStagePlugin::RenderStagePlugin((UFG::RenderStagePlugin *)&this->vfptr);
  v1->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::GunRecoilPostEffect::`vftable';
  v1->mRecoilValue = 0.0;
  v1->mRecoilFalloffScale = 1.0;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v1->vfptr,
    UFG::GunRecoilPostEffect::_GunRecoilPostEffectTypeUID,
    "GunRecoilPostEffect");
  v2 = sIsStaticInit_0;
  if ( !sIsStaticInit_0 )
    v2 = 1;
  sIsStaticInit_0 = v2;
}

// File Line: 729
// RVA: 0x602F0
void __fastcall UFG::GunRecoilPostEffect::RenderPostEffect(UFG::GunRecoilPostEffect *this, UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list, UFG::RenderContext *render_context, float delta_time, Illusion::Target **curr_target, Illusion::Target **scratch_target)
{
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v6; // rbx
  float v7; // xmm1_4
  float v8; // xmm6_4
  Illusion::Material *v9; // rdi
  _WORD *v10; // rbx
  Render::ViewSettings *v11; // rax
  Illusion::Target **v12; // r14
  __int64 v13; // rax
  _WORD *v14; // rax
  Illusion::Target **v15; // rsi
  unsigned int v16; // er8
  __int64 v17; // rax
  char *v18; // rbx
  Illusion::StateValues *v19; // rax
  Illusion::Target *v20; // rcx
  RenderQueueLayer v21; // [rsp+60h] [rbp-F08h]
  Render::View v22; // [rsp+140h] [rbp-E28h]
  LayerSubmitContext ptr; // [rsp+2D0h] [rbp-C98h]
  Render::Poly poly; // [rsp+F80h] [rbp+18h]

  v6 = serialization_list;
  if ( render_context->mRenderFeatures.mPostFX )
  {
    v7 = this->mRecoilValue <= 0.0 ? 0.0 : this->mRecoilFalloffScale;
    v8 = this->mRecoilValue - v7;
    this->mRecoilValue = v8;
    if ( v8 > 0.0 )
    {
      v9 = Render::gRenderUtilities.mMaterial;
      RenderQueueLayer::RenderQueueLayer(&v21);
      LayerSubmitContext::LayerSubmitContext(&ptr);
      v21.mSerializationList = v6;
      ptr.mRenderQueueProvider = &v21;
      v10 = 0i64;
      ptr.mQueueMode = 0;
      v11 = Render::ViewSettings::GetIdentity();
      Render::View::View(&v22, v11, (Illusion::SubmitContext *)&ptr.vfptr);
      v12 = scratch_target;
      Render::View::BeginTarget(&v22, *scratch_target, "GunRecoilPostEffect", 0, 0, 0i64, 1, 0, 0, 0);
      if ( LODWORD(v9[1].mResourceHandles.mNode.mNext) != -880245061 )
      {
        UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v9[1].mNode.mChild[1], v9[1].mTypeUID, 0xCB8886BB);
        v13 = v9->mMaterialUser.mOffset;
        if ( v13 )
          v14 = (_WORD *)((char *)&v9->mMaterialUser + v13);
        else
          v14 = 0i64;
        *v14 |= 0x20u;
      }
      v15 = curr_target;
      v16 = (*curr_target)->mTargetTexture[0]->mNode.mUID;
      if ( LODWORD(v9[1].mStateBlockMask.mFlags[0]) != v16 )
      {
        UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v9[1].mDebugName[20], v9[1].mStateBlockMask.mFlags[1], v16);
        v17 = v9->mMaterialUser.mOffset;
        if ( v17 )
          v10 = (_WORD *)((char *)&v9->mMaterialUser + v17);
        *v10 |= 0x20u;
      }
      v18 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x80u, 0x10u);
      *(float *)v18 = v8;
      v19 = Render::View::GetStateValues(&v22);
      v19->mSetValueMask.mFlags[0] |= 0x8000ui64;
      v19->mParamValues[15] = v18;
      Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
      Render::View::Draw(&v22, &poly, v9, 0i64);
      Render::View::EndTarget(&v22);
      v20 = *v15;
      *v15 = *v12;
      *v12 = v20;
      `eh vector destructor iterator'(
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
void __fastcall UFG::AccumulationBufferPostEffect::AccumulationBufferPostEffect(UFG::AccumulationBufferPostEffect *this)
{
  UFG::AccumulationBufferPostEffect *v1; // rbx

  v1 = this;
  UFG::RenderStagePlugin::RenderStagePlugin((UFG::RenderStagePlugin *)&this->vfptr);
  v1->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AccumulationBufferPostEffect::`vftable';
  v1->mEnable = 0.0;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v1->vfptr,
    UFG::AccumulationBufferPostEffect::_AccumulationBufferPostEffectTypeUID,
    "AccumulationBufferPostEffect");
}

// File Line: 787
// RVA: 0x5FD00
void __fastcall UFG::AccumulationBufferPostEffect::RenderPostEffect(UFG::AccumulationBufferPostEffect *this, UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list, UFG::RenderContext *render_context, float delta_time, Illusion::Target **curr_target)
{
  UFG::RenderContext *v5; // rsi
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v6; // rdi
  Illusion::Material *v7; // rbx
  _WORD *v8; // rdi
  Render::ViewSettings *v9; // rax
  __int64 v10; // rax
  _WORD *v11; // rax
  unsigned int v12; // er8
  __int64 v13; // rax
  RenderQueueLayer v14; // [rsp+60h] [rbp-EF8h]
  Render::View v15; // [rsp+140h] [rbp-E18h]
  LayerSubmitContext ptr; // [rsp+2D0h] [rbp-C88h]
  Render::Poly poly; // [rsp+F70h] [rbp+18h]

  v5 = render_context;
  v6 = serialization_list;
  if ( render_context->mRenderFeatures.mPostFX && this->mEnable != 0.0 )
  {
    v7 = Render::gRenderUtilities.mMaterial;
    RenderQueueLayer::RenderQueueLayer(&v14);
    LayerSubmitContext::LayerSubmitContext(&ptr);
    v14.mSerializationList = v6;
    ptr.mRenderQueueProvider = &v14;
    v8 = 0i64;
    ptr.mQueueMode = 0;
    v9 = Render::ViewSettings::GetIdentity();
    Render::View::View(&v15, v9, (Illusion::SubmitContext *)&ptr.vfptr);
    Render::View::BeginTarget(&v15, v5->mHalfSizeScratchTargetA, "AccumulationBuffer", 0, 0, 0i64, 1, 0, 0, 0);
    if ( LODWORD(v7[1].mResourceHandles.mNode.mNext) != -917770645 )
    {
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v7[1].mNode.mChild[1], v7[1].mTypeUID, 0xC94BEE6B);
      v10 = v7->mMaterialUser.mOffset;
      if ( v10 )
        v11 = (_WORD *)((char *)&v7->mMaterialUser + v10);
      else
        v11 = 0i64;
      *v11 |= 0x20u;
    }
    v12 = (*curr_target)->mTargetTexture[0]->mNode.mUID;
    if ( LODWORD(v7[1].mStateBlockMask.mFlags[0]) != v12 )
    {
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v7[1].mDebugName[20], v7[1].mStateBlockMask.mFlags[1], v12);
      v13 = v7->mMaterialUser.mOffset;
      if ( v13 )
        v8 = (_WORD *)((char *)&v7->mMaterialUser + v13);
      *v8 |= 0x20u;
    }
    Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
    Render::View::Draw(&v15, &poly, v7, 0i64);
    Render::View::EndTarget(&v15);
    `eh vector destructor iterator'(
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
  UFG::FrontEndPauseEffect *v1; // rbx
  char v2; // cl

  v1 = this;
  UFG::RenderStagePlugin::RenderStagePlugin((UFG::RenderStagePlugin *)&this->vfptr);
  v1->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::FrontEndPauseEffect::`vftable';
  v1->mVisualTreatmentIndex = -1;
  *(_QWORD *)&v1->mCurrBlurCount = 0i64;
  v1->mRestoreVisualTreatmentAfterBlur = 0;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v1->vfptr,
    UFG::FrontEndPauseEffect::_FrontEndPauseEffectTypeUID,
    "FrontEndPauseEffect");
  v2 = sIsStaticInit_1;
  if ( !sIsStaticInit_1 )
    v2 = 1;
  sIsStaticInit_1 = v2;
}

// File Line: 837
// RVA: 0x60930
void __fastcall UFG::FrontEndPauseEffect::Start(UFG::FrontEndPauseEffect *this, unsigned int visual_treatment_uid)
{
  UFG::FrontEndPauseEffect *v2; // rsi
  UFG::SimObject *v3; // rcx
  unsigned int v4; // ebp
  UFG::SimComponent *v5; // rdi
  signed int v6; // ebx
  unsigned int *v7; // rcx
  int *v8; // rcx
  signed __int64 v9; // rdx
  signed __int64 v10; // rax
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
  signed int v22; // eax
  int v23; // ecx
  int Dst; // [rsp+20h] [rbp-C8h]

  v2 = this;
  this->mTargetBlurCount = 20;
  v3 = this->m_pSimObject;
  v4 = visual_treatment_uid;
  if ( v3 && (v5 = UFG::SimObject::GetComponentOfType(v3, UFG::VisualTreatmentPostEffect::_TypeUID)) != 0i64 )
  {
    v6 = 0;
    if ( UFG::VisualTreatmentPostEffect::msNumVisualTreatments <= 0 )
    {
LABEL_7:
      v6 = -1;
    }
    else
    {
      v7 = &UFG::VisualTreatmentPostEffect::msStateBlockHandle[0].mNameUID;
      while ( *v7 != v4 )
      {
        ++v6;
        v7 += 8;
        if ( v6 >= UFG::VisualTreatmentPostEffect::msNumVisualTreatments )
          goto LABEL_7;
      }
    }
    v8 = &Dst;
    v2->mVisualTreatmentIndex = v6;
    v9 = (signed __int64)&v5[1].m_Flags;
    if ( ((unsigned __int8)&Dst | (unsigned __int8)((_BYTE)v5 + 96)) & 0xF )
    {
      memmove(&Dst, &v5[1].m_Flags, 0xB8ui64);
    }
    else
    {
      v10 = 1i64;
      do
      {
        v11 = *(_OWORD *)v9;
        v12 = *(_OWORD *)(v9 + 16);
        v8 += 32;
        v9 += 128i64;
        *((_OWORD *)v8 - 8) = v11;
        v13 = *(_OWORD *)(v9 - 96);
        *((_OWORD *)v8 - 7) = v12;
        v14 = *(_OWORD *)(v9 - 80);
        *((_OWORD *)v8 - 6) = v13;
        v15 = *(_OWORD *)(v9 - 64);
        *((_OWORD *)v8 - 5) = v14;
        v16 = *(_OWORD *)(v9 - 48);
        *((_OWORD *)v8 - 4) = v15;
        v17 = *(_OWORD *)(v9 - 32);
        *((_OWORD *)v8 - 3) = v16;
        v18 = *(_OWORD *)(v9 - 16);
        *((_OWORD *)v8 - 2) = v17;
        *((_OWORD *)v8 - 1) = v18;
        --v10;
      }
      while ( v10 );
      v19 = *(_OWORD *)(v9 + 16);
      v20 = *(_QWORD *)(v9 + 48);
      *(_OWORD *)v8 = *(_OWORD *)v9;
      v21 = *(_OWORD *)(v9 + 32);
      *((_OWORD *)v8 + 1) = v19;
      *((_OWORD *)v8 + 2) = v21;
      *((_QWORD *)v8 + 6) = v20;
    }
    if ( Dst != v6 )
      UFG::VisualTreatmentPostEffect::SaveState((UFG::VisualTreatmentPostEffect *)v5);
    v22 = v2->mVisualTreatmentIndex;
    if ( v22 <= -1
      || v22 >= UFG::VisualTreatmentPostEffect::msNumVisualTreatments
      || BYTE4(v5[4].m_SafePointerList.mNode.mPrev) && *(_DWORD *)(&v5[1].m_SimObjIndex + 1) > 10 )
    {
      v2->mVisualTreatmentId = -1;
    }
    else
    {
      v23 = (int)v5[4].m_SafePointerList.mNode.mNext;
      *(_DWORD *)&v5[1].m_Flags = v22;
      *(_QWORD *)(&v5[1].m_SimObjIndex + 1) = 10i64;
      LOBYTE(v5[1].m_BoundComponentHandles.mNode.mNext) = 0;
      HIDWORD(v5[1].m_pSimObject) = v23;
      BYTE4(v5[4].m_SafePointerList.mNode.mPrev) = 1;
      LODWORD(v5[4].m_SafePointerList.mNode.mNext) = v23 + 1;
      v2->mVisualTreatmentId = v23;
    }
  }
  else
  {
    v2->mVisualTreatmentId = -1;
  }
}

// File Line: 860
// RVA: 0x5FBA0
void __fastcall UFG::FrontEndPauseEffect::End(UFG::FrontEndPauseEffect *this, bool fade)
{
  UFG::FrontEndPauseEffect *v2; // rbx
  UFG::SimObject *v3; // rcx
  bool v4; // di
  UFG::VisualTreatmentPostEffect *v5; // rax
  float v6; // xmm2_4

  v2 = this;
  this->mTargetBlurCount = 0;
  v3 = this->m_pSimObject;
  v4 = fade;
  if ( v3 )
  {
    v5 = (UFG::VisualTreatmentPostEffect *)UFG::SimObject::GetComponentOfType(
                                             v3,
                                             UFG::VisualTreatmentPostEffect::_TypeUID);
    if ( v5 )
    {
      v2->mRestoreVisualTreatmentAfterBlur = 1;
      if ( v4 )
        v6 = FLOAT_0_75;
      else
        v6 = 0.0;
      UFG::VisualTreatmentPostEffect::StopVisualTreatment(v5, v2->mVisualTreatmentId, v6);
    }
  }
}

// File Line: 871
// RVA: 0x60EE0
void __fastcall UFG::FrontEndPauseEffect::Update(UFG::FrontEndPauseEffect *this, float sim_time_delta)
{
  unsigned int v2; // eax
  UFG::FrontEndPauseEffect *v3; // rbx
  unsigned int v4; // ecx
  int v5; // eax
  unsigned int v6; // eax
  UFG::VisualTreatmentPostEffect *v7; // rdi
  UFG::SimObject *v8; // rcx

  v2 = this->mCurrBlurCount;
  v3 = this;
  v4 = this->mTargetBlurCount;
  if ( v2 >= v4 )
  {
    if ( v2 <= v4 )
      goto LABEL_6;
    v5 = v2 - 2;
  }
  else
  {
    v5 = v2 + 2;
  }
  v3->mCurrBlurCount = v5;
LABEL_6:
  v6 = v3->mCurrBlurCount;
  v7 = 0i64;
  if ( v6 )
  {
    if ( v6 >= 0x14 )
      v6 = 20;
  }
  else
  {
    v6 = 0;
  }
  v8 = v3->m_pSimObject;
  v3->mCurrBlurCount = v6;
  if ( v8 )
    v7 = (UFG::VisualTreatmentPostEffect *)UFG::SimObject::GetComponentOfType(
                                             v8,
                                             UFG::VisualTreatmentPostEffect::_TypeUID);
  if ( v3->mCurrBlurCount && v7 )
    ((void (__fastcall *)(UFG::VisualTreatmentPostEffect *))v7->vfptr[17].__vecDelDtor)(v7);
  if ( v3->mRestoreVisualTreatmentAfterBlur )
  {
    if ( !v3->mCurrBlurCount )
    {
      UFG::VisualTreatmentPostEffect::RestoreState(v7);
      v3->mRestoreVisualTreatmentAfterBlur = 0;
    }
  }
}

// File Line: 895
// RVA: 0x60110
void __fastcall UFG::FrontEndPauseEffect::RenderPostEffect(UFG::FrontEndPauseEffect *this, UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list, UFG::RenderContext *render_context, float delta_time, Illusion::Target **curr_target)
{
  UFG::RenderContext *v5; // rdi
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v6; // rbx
  UFG::FrontEndPauseEffect *v7; // rsi
  unsigned int v8; // ebx
  __int64 v9; // rsi
  RenderQueueLayer v10; // [rsp+40h] [rbp-D78h]
  LayerSubmitContext ptr; // [rsp+120h] [rbp-C98h]

  v5 = render_context;
  v6 = serialization_list;
  v7 = this;
  RenderQueueLayer::RenderQueueLayer(&v10);
  LayerSubmitContext::LayerSubmitContext(&ptr);
  v10.mSerializationList = v6;
  ptr.mRenderQueueProvider = &v10;
  ptr.mQueueMode = 0;
  Render::gRenderUtilities.mSubmitContext = (Illusion::SubmitContext *)&ptr;
  v8 = gFrontEndPauseCurrCountOverride;
  if ( gFrontEndPauseCurrCountOverride <= 0 )
    v8 = v7->mCurrBlurCount;
  if ( v8 )
  {
    Render::RenderUtilities::GaussBlur3x3(
      &Render::gRenderUtilities,
      *curr_target,
      v5->mHalfSizeScratchTargetB,
      0,
      0i64,
      0xB0A10EFE);
    Render::RenderUtilities::GaussBlur3x3(
      &Render::gRenderUtilities,
      v5->mHalfSizeScratchTargetB,
      v5->mQuarterSizeScratchTargetA,
      0,
      0i64,
      0xB0A10EFE);
  }
  if ( v8 > 1 )
  {
    v9 = v8 - 1;
    do
    {
      Render::RenderUtilities::SeparableGaussBlur5x5(
        &Render::gRenderUtilities,
        v5->mQuarterSizeScratchTargetA,
        v5->mQuarterSizeScratchTargetB,
        1,
        0xA57D2FB6);
      Render::RenderUtilities::SeparableGaussBlur5x5(
        &Render::gRenderUtilities,
        v5->mQuarterSizeScratchTargetB,
        v5->mQuarterSizeScratchTargetA,
        0,
        0xA57D2FB6);
      --v9;
    }
    while ( v9 );
  }
  if ( v8 )
  {
    Render::RenderUtilities::GaussBlur3x3(
      &Render::gRenderUtilities,
      v5->mQuarterSizeScratchTargetA,
      v5->mHalfSizeScratchTargetB,
      0,
      0i64,
      0xB0A10EFE);
    Render::RenderUtilities::GaussBlur3x3(
      &Render::gRenderUtilities,
      v5->mHalfSizeScratchTargetB,
      *curr_target,
      0,
      0i64,
      0xB0A10EFE);
  }
  Render::gRenderUtilities.mSubmitContext = 0i64;
  `eh vector destructor iterator'(
    ptr.mStateArgs.mStateArgs,
    0x10ui64,
    128,
    (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
  RenderQueueLayer::~RenderQueueLayer(&v10);
}

