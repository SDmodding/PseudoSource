// File Line: 42
// RVA: 0x5DDF0
void __fastcall `anonymous namespace::ApplyDiffuseTextureStateOverrides(Illusion::StateValues *state_values)
{
  _QWORD *v1; // r8
  __int64 v2; // rdx
  void *v3; // r10
  void *v4; // r9
  void *v5; // rax
  void *v6; // rax

  v1 = state_values->mParamValues[17];
  v2 = 0i64;
  if ( v1 )
  {
    v3 = state_values->mParamValues[9];
    v4 = state_values->mParamValues[10];
    if ( !v3 || !v4 )
      v2 = (__int64)v1 + v1[14] + 112;
    if ( !v3 )
    {
      v5 = *(void **)(v2 + 16);
      state_values->mSetValueMask.mFlags[0] |= 0x200ui64;
      state_values->mParamValues[9] = v5;
    }
    if ( !v4 )
    {
      v6 = *(void **)(v2 + 48);
      state_values->mSetValueMask.mFlags[0] |= 0x400ui64;
      state_values->mParamValues[10] = v6;
    }
  }
}

// File Line: 85
// RVA: 0x5DE50
void __fastcall `anonymous namespace::ApplyHKAlphaTestFixup(
        Illusion::StateValues *state_values,
        void *aReplacement_Remote,
        void *transparency_state)
{
  _BYTE *v4; // rcx
  unsigned __int16 *v6; // rdx
  Illusion::Texture *v7; // rcx
  Illusion::Texture *v8; // rax

  v4 = state_values->mParamValues[9];
  if ( !v4 )
    goto LABEL_14;
  if ( transparency_state
    && !v4[88]
    && (_BYTE)transparency_state
    && (unsigned __int8)transparency_state < Render::TransparencySystem::msOpaqueIndex )
  {
    if ( (unsigned __int8)transparency_state < (int)BYTE1(transparency_state) )
    {
      v6 = (unsigned __int16 *)*((_QWORD *)&Render::TransparencySystem::msAlphaStateInHandle[0].mData
                               + 4 * (unsigned __int8)transparency_state);
      goto LABEL_10;
    }
    if ( (unsigned __int8)transparency_state > (int)BYTE1(transparency_state) )
    {
      v6 = (unsigned __int16 *)*((_QWORD *)&Render::TransparencySystem::msAlphaStateOutHandle[0].mData
                               + 4 * (unsigned __int8)transparency_state);
LABEL_10:
      if ( v6 )
      {
        state_values->mSetValueMask.mFlags[0] |= 0x200ui64;
        state_values->mParamValues[9] = v6;
        v7 = Render::TransparencySystem::msDitherMaskTextures[v6[50]];
        state_values->mSetValueMask.mFlags[0] |= 0x8000000000000000ui64;
        state_values->mParamValues[63] = v7;
        return;
      }
    }
  }
  if ( v4[93] )
  {
    state_values->mSetValueMask.mFlags[0] |= 0x200ui64;
    state_values->mParamValues[9] = aReplacement_Remote;
  }
LABEL_14:
  v8 = qword_142128EE8;
  state_values->mSetValueMask.mFlags[0] |= 0x8000000000000000ui64;
  state_values->mParamValues[63] = v8;
}

// File Line: 123
// RVA: 0x5E150
void __fastcall `anonymous namespace::InitializeGBufferShaderSelector(
        Illusion::StateValues *state_values,
        Illusion::ShaderSelector *shader_selector)
{
  void *v2; // rax
  void *v3; // r10
  _BYTE *v4; // r9
  char *v5; // r11
  float *v6; // rax
  unsigned __int64 v7; // rax

  v2 = state_values->mParamValues[44];
  v3 = state_values->mParamValues[9];
  v4 = 0i64;
  v5 = 0i64;
  if ( v2 )
    v5 = (char *)state_values->mParamValues[44];
  if ( v3 )
    v4 = state_values->mParamValues[9];
  if ( ((!v2 || (v6 = (float *)(v5 + 128), v5 == (char *)-128i64))
     && (v6 = (float *)state_values->mParamValues[33]) == 0i64
     || v6[2] == 0.0)
    && v3
    && v4[88] )
  {
    shader_selector->mAddState.mFlags[0] &= ~0x800000000ui64;
  }
  else
  {
    shader_selector->mAddState.mFlags[0] |= 0x800000000ui64;
  }
  shader_selector->mAddState.mFlags[0] |= 0x800000000000000ui64;
  v7 = shader_selector->mAddState.mFlags[0];
  if ( state_values->mParamValues[57] )
    shader_selector->mAddState.mFlags[0] = v7 | 0x200000000000000i64;
  else
    shader_selector->mAddState.mFlags[0] = v7 & 0xFDFFFFFFFFFFFFFFui64;
}

// File Line: 193
// RVA: 0x5E050
Illusion::RenderQueue *__fastcall `anonymous namespace::GBufferChooseRenderQueue(
        Illusion::StateValues *state_values,
        UFG::qMemoryStream<Illusion::Shader,1160> *shader_stream,
        Render::CullMetrics *cull_metrics,
        RenderQueueLayer *rq_provider)
{
  float mDistance; // xmm2_4
  float *v6; // r11
  _BYTE *v7; // r8
  float *v8; // rdx
  float v9; // xmm1_4
  float *v10; // rax
  bool v11; // zf
  float v13; // xmm0_4
  int v14; // ecx

  if ( cull_metrics )
    mDistance = cull_metrics->mDistance;
  else
    mDistance = FLOAT_1000_0;
  v6 = (float *)state_values->mParamValues[44];
  v7 = state_values->mParamValues[9];
  v8 = (float *)state_values->mParamValues[33];
  v9 = 0.0;
  v10 = 0i64;
  if ( v6 )
  {
    v10 = v6 + 32;
    v11 = v6[34] == 0.0;
  }
  else
  {
    if ( !v8 )
      goto LABEL_10;
    v11 = v8[2] == 0.0;
  }
  if ( !v11 )
    return RenderQueueLayer::GetSolid1RenderQueue(rq_provider, *((_DWORD *)shader_stream->mMainMemoryAddress + 28));
LABEL_10:
  if ( v7 && v7[88] )
  {
    if ( v10 )
      v9 = v10[3];
    v13 = (float)(1000.0 - (float)(v9 + mDistance)) * 100.0;
    if ( v13 <= 1.0 )
    {
      v13 = *(float *)&FLOAT_1_0;
    }
    else if ( v13 >= 100000.0 )
    {
      return RenderQueueLayer::GetAlphaRenderQueue(rq_provider, (int)100000.0);
    }
    return RenderQueueLayer::GetAlphaRenderQueue(rq_provider, (int)v13);
  }
  else
  {
    v14 = 15;
    if ( (int)mDistance / 15 < 15 )
      v14 = (int)mDistance / 15;
    return RenderQueueLayer::GetSolidRenderQueue(
             rq_provider,
             (v14 << 28) ^ (*((_DWORD *)shader_stream->mMainMemoryAddress + 28) ^ (v14 << 28)) & 0xFFFFFFFu);
  }
}

// File Line: 263
// RVA: 0x5DF20
Illusion::Shader *__fastcall `anonymous namespace::ChooseDepthShader(
        Illusion::StateValues *state_values,
        Illusion::Shader *shader)
{
  __int64 mOffset; // rax
  Illusion::Shader *result; // rax
  unsigned int v5; // ebx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v7; // rax

  if ( (_S1_10 & 1) == 0 )
  {
    _S1_10 |= 1u;
    UFG::qResourceHandle::qResourceHandle(&simpleHandle_2);
    atexit(_anonymous_namespace_::ChooseDepthShader_::_2_::_dynamic_atexit_destructor_for__simpleHandle__);
  }
  mOffset = shader->mShaderUser.mOffset;
  if ( mOffset )
    mOffset += (__int64)&shader->mShaderUser;
  result = *(Illusion::Shader **)(mOffset + 16);
  if ( !result )
  {
    if ( !simpleInit_2 )
    {
      v5 = UFG::qStringHashUpper32("DR_EmitDepthFBX", 0xFFFFFFFF);
      Inventory = `UFG::qGetResourceInventory<Illusion::Shader>::`2::result;
      if ( !`UFG::qGetResourceInventory<Illusion::Shader>::`2::result )
      {
        v7 = UFG::qResourceWarehouse::Instance();
        Inventory = UFG::qResourceWarehouse::GetInventory(v7, 0x8B5561A1);
        `UFG::qGetResourceInventory<Illusion::Shader>::`2::result = Inventory;
      }
      UFG::qResourceHandle::Init(&simpleHandle_2, 0x8B5561A1, v5, Inventory);
      simpleInit_2 = 1;
    }
    return (Illusion::Shader *)simpleHandle_2.mData;
  }
  return result;
}

// File Line: 288
// RVA: 0x5DD30
void __fastcall SimpleTaskSubmitContext::SimpleTaskSubmitContext(SimpleTaskSubmitContext *this)
{
  Illusion::SubmitContext::SubmitContext(this);
  this->vfptr = (Illusion::SubmitContextVtbl *)&SimpleTaskSubmitContext::`vftable;
  this->mRenderQueueProvider = 0i64;
}

// File Line: 292
// RVA: 0x5DDE0
void __fastcall SimpleTaskSubmitContext::AddRenderCommand(
        SimpleTaskSubmitContext *this,
        __int16 command_type,
        __int16 index,
        void *data)
{
  RenderQueueLayer::AddRenderCommand(this->mRenderQueueProvider, command_type, index, data);
}

// File Line: 297
// RVA: 0x5EE80
Illusion::RenderQueue *__fastcall SimpleTaskSubmitContext::OnPreSubmit(
        SimpleTaskSubmitContext *this,
        UFG::qMemoryStream<Illusion::Shader,1160> *shader_stream,
        UFG::BitFlags128 *already_called_funcs_mask)
{
  Illusion::SubmitContext::ApplyStateArgs(this, shader_stream, already_called_funcs_mask);
  return RenderQueueLayer::GetSolidRenderQueue(this->mRenderQueueProvider, 1u);
}

// File Line: 313
// RVA: 0x5DBC0
void __fastcall LayerSubmitContext::LayerSubmitContext(LayerSubmitContext *this)
{
  Illusion::SubmitContext::SubmitContext(this);
  this->vfptr = (Illusion::SubmitContextVtbl *)&RenderSubmitContext::`vftable;
  this->mCullMetrics = 0i64;
  this->mTransparencyState = 0i64;
  this->vfptr = (Illusion::SubmitContextVtbl *)&LayerSubmitContext::`vftable;
  this->mQueueMode = QM_Default;
  this->mRenderQueueProvider = 0i64;
}

// File Line: 317
// RVA: 0x5DDD0
void __fastcall LayerSubmitContext::AddRenderCommand(
        LayerSubmitContext *this,
        __int16 command_type,
        __int16 index,
        void *data)
{
  RenderQueueLayer::AddRenderCommand(this->mRenderQueueProvider, command_type, index, data);
}

// File Line: 322
// RVA: 0x5DFF0
Illusion::RenderQueue *__fastcall LayerSubmitContext::ChooseRenderQueue(
        LayerSubmitContext *this,
        UFG::qMemoryStream<Illusion::Shader,1160> *shader_stream,
        Render::CullMetrics *cull_metrics)
{
  LayerSubmitContext::QueueMode mQueueMode; // ecx
  __int32 v5; // ecx
  _BYTE *v7; // rax

  mQueueMode = this->mQueueMode;
  if ( mQueueMode == QM_Single )
    return RenderQueueLayer::GetSolidRenderQueue(this->mRenderQueueProvider, 1u);
  v5 = mQueueMode - 1;
  if ( !v5 )
  {
    v7 = this->mStateValues.mParamValues[9];
    if ( v7 && v7[88] )
      return RenderQueueLayer::GetSolid1RenderQueue(this->mRenderQueueProvider, 1u);
    return RenderQueueLayer::GetSolidRenderQueue(this->mRenderQueueProvider, 1u);
  }
  if ( v5 == 1 )
    return `anonymous namespace::GBufferChooseRenderQueue(
             &this->mStateValues,
             shader_stream,
             cull_metrics,
             this->mRenderQueueProvider);
  else
    return 0i64;
}

// File Line: 359
// RVA: 0x5EB70
Illusion::RenderQueue *__fastcall LayerSubmitContext::OnPreSubmit(
        LayerSubmitContext *this,
        UFG::qMemoryStream<Illusion::Shader,1160> *shader_stream,
        UFG::BitFlags128 *already_called_funcs_mask)
{
  LayerSubmitContext::QueueMode mQueueMode; // ecx
  __int32 v7; // ecx
  _BYTE *v9; // rax

  Illusion::SubmitContext::ApplyShaderTemplate(this, shader_stream);
  Illusion::SubmitContext::ApplyStateArgs(this, shader_stream, already_called_funcs_mask);
  mQueueMode = this->mQueueMode;
  if ( mQueueMode == QM_Single )
    return RenderQueueLayer::GetSolidRenderQueue(this->mRenderQueueProvider, 1u);
  v7 = mQueueMode - 1;
  if ( !v7 )
  {
    v9 = this->mStateValues.mParamValues[9];
    if ( v9 && v9[88] )
      return RenderQueueLayer::GetSolid1RenderQueue(this->mRenderQueueProvider, 1u);
    return RenderQueueLayer::GetSolidRenderQueue(this->mRenderQueueProvider, 1u);
  }
  if ( v7 == 1 )
    return `anonymous namespace::GBufferChooseRenderQueue(
             &this->mStateValues,
             shader_stream,
             this->mCullMetrics,
             this->mRenderQueueProvider);
  else
    return 0i64;
}

// File Line: 389
// RVA: 0x5DB50
void __fastcall GBufferSubmitContext::GBufferSubmitContext(GBufferSubmitContext *this)
{
  Illusion::SubmitContext::SubmitContext(this);
  this->vfptr = (Illusion::SubmitContextVtbl *)&RenderSubmitContext::`vftable;
  this->mCullMetrics = 0i64;
  this->mTransparencyState = 0i64;
  this->vfptr = (Illusion::SubmitContextVtbl *)&LayerSubmitContext::`vftable;
  this->mQueueMode = QM_Default;
  this->mRenderQueueProvider = 0i64;
  this->vfptr = (Illusion::SubmitContextVtbl *)&GBufferSubmitContext::`vftable;
}

// File Line: 398
// RVA: 0x5E9C0
Illusion::RenderQueue *__fastcall GBufferSubmitContext::OnPreSubmit(
        GBufferSubmitContext *this,
        UFG::qMemoryStream<Illusion::Shader,1160> *shader_stream,
        UFG::BitFlags128 *already_called_funcs_mask)
{
  Illusion::StateValues *p_mStateValues; // rbx
  void *alphaStateNone; // r9
  void *rasterStateNormal; // rcx
  _QWORD *v9; // rcx
  __int64 v10; // rdx
  void *v11; // r9
  void *v12; // r8
  void *v13; // rax
  void *v14; // rax
  void *forceRasterState; // rcx
  char *v16; // rax
  float *v17; // rax
  Illusion::RenderQueue *v19; // rbp
  void *compositeTargetParams; // rdx

  p_mStateValues = &this->mStateValues;
  if ( *((_DWORD *)shader_stream->mMainMemoryAddress + 6) == 775895434 )
  {
    alphaStateNone = this->mPerPhaseParams->alphaStateNone;
    p_mStateValues->mSetValueMask.mFlags[0] |= 0x200ui64;
    this->mStateValues.mParamValues[9] = alphaStateNone;
    rasterStateNormal = this->mPerPhaseParams->rasterStateNormal;
    p_mStateValues->mSetValueMask.mFlags[0] |= 0x400ui64;
    p_mStateValues->mParamValues[10] = rasterStateNormal;
  }
  else
  {
    v9 = this->mStateValues.mParamValues[17];
    v10 = 0i64;
    if ( v9 )
    {
      v11 = p_mStateValues->mParamValues[9];
      v12 = p_mStateValues->mParamValues[10];
      if ( !v11 || !v12 )
        v10 = (__int64)v9 + v9[14] + 112;
      if ( !v11 )
      {
        v13 = *(void **)(v10 + 16);
        p_mStateValues->mSetValueMask.mFlags[0] |= 0x200ui64;
        p_mStateValues->mParamValues[9] = v13;
      }
      if ( !v12 )
      {
        v14 = *(void **)(v10 + 48);
        p_mStateValues->mSetValueMask.mFlags[0] |= 0x400ui64;
        p_mStateValues->mParamValues[10] = v14;
      }
    }
  }
  forceRasterState = this->mPerPhaseParams->forceRasterState;
  if ( forceRasterState )
  {
    p_mStateValues->mSetValueMask.mFlags[0] |= 0x400ui64;
    p_mStateValues->mParamValues[10] = forceRasterState;
    v16 = (char *)this->mStateValues.mParamValues[44];
    if ( v16 )
    {
      v17 = (float *)(v16 + 128);
      if ( v17 )
      {
        if ( *v17 > 0.0 )
          return 0i64;
      }
      if ( v17[1] > 0.0 || v17[2] > 0.0 )
        return 0i64;
    }
  }
  `anonymous namespace::ApplyHKAlphaTestFixup(
    p_mStateValues,
    this->mPerPhaseParams->alphaStatePunchThrough,
    this->mTransparencyState);
  `anonymous namespace::InitializeGBufferShaderSelector(p_mStateValues, this->mShaderSelector);
  v19 = `anonymous namespace::GBufferChooseRenderQueue(
          p_mStateValues,
          shader_stream,
          this->mCullMetrics,
          this->mRenderQueueProvider);
  if ( v19->mUserData )
    compositeTargetParams = this->mPerPhaseParams->compositeTargetParams;
  else
    compositeTargetParams = this->mPerPhaseParams->gbufferTargetParams;
  p_mStateValues->mSetValueMask.mFlags[0] |= 0x800ui64;
  p_mStateValues->mParamValues[11] = compositeTargetParams;
  Illusion::SubmitContext::ApplyShaderTemplate(this, shader_stream);
  Illusion::SubmitContext::ApplyStateArgs(this, shader_stream, already_called_funcs_mask);
  return v19;
}

// File Line: 461
// RVA: 0x5E200
void __fastcall GBufferSubmitContext::OnPostSubmit(GBufferSubmitContext *this, Illusion::RenderQueue *queue)
{
  Illusion::Texture *v2; // rax

  this->mStateValues.mSetValueMask.mFlags[0] |= 0x100000000000ui64;
  this->mStateValues.mParamValues[44] = 0i64;
  v2 = qword_142128EE8;
  this->mStateValues.mSetValueMask.mFlags[0] |= 0x8000000000000000ui64;
  this->mStateValues.mParamValues[63] = v2;
}

// File Line: 475
// RVA: 0x5DA00
void __fastcall ForwardEnvMapSubmitContext::ForwardEnvMapSubmitContext(ForwardEnvMapSubmitContext *this)
{
  Illusion::SubmitContext::SubmitContext(this);
  this->vfptr = (Illusion::SubmitContextVtbl *)&RenderSubmitContext::`vftable;
  this->mCullMetrics = 0i64;
  this->mTransparencyState = 0i64;
  this->vfptr = (Illusion::SubmitContextVtbl *)&LayerSubmitContext::`vftable;
  this->mQueueMode = QM_Default;
  this->mRenderQueueProvider = 0i64;
  this->vfptr = (Illusion::SubmitContextVtbl *)&ForwardEnvMapSubmitContext::`vftable;
  this->mPerPhaseParams = 0i64;
}

// File Line: 479
// RVA: 0x5E410
Illusion::RenderQueue *__fastcall ForwardEnvMapSubmitContext::OnPreSubmit(
        ForwardEnvMapSubmitContext *this,
        UFG::qMemoryStream<Illusion::Shader,1160> *shader_stream,
        UFG::BitFlags128 *already_called_funcs_mask)
{
  Illusion::Texture *v3; // rax
  int v5; // ecx
  void *alphaStateNone; // rcx
  void *rasterStateNormal; // rcx
  _DWORD *v10; // rax
  LayerSubmitContext::QueueMode mQueueMode; // ecx
  __int32 v12; // ecx
  _BYTE *v14; // rax

  v3 = qword_142128EE8;
  this->mStateValues.mSetValueMask.mFlags[0] |= 0x8000000000000000ui64;
  this->mStateValues.mParamValues[63] = v3;
  v5 = *((_DWORD *)shader_stream->mMainMemoryAddress + 6);
  if ( v5 == 1278767530 )
    return 0i64;
  if ( v5 == 775895434 )
  {
    alphaStateNone = this->mPerPhaseParams->alphaStateNone;
    this->mStateValues.mSetValueMask.mFlags[0] |= 0x200ui64;
    this->mStateValues.mParamValues[9] = alphaStateNone;
    rasterStateNormal = this->mPerPhaseParams->rasterStateNormal;
    this->mStateValues.mSetValueMask.mFlags[0] |= 0x400ui64;
    this->mStateValues.mParamValues[10] = rasterStateNormal;
  }
  else
  {
    `anonymous namespace::ApplyDiffuseTextureStateOverrides(&this->mStateValues);
  }
  v10 = this->mStateValues.mParamValues[9];
  if ( v10 )
  {
    if ( v10[6] == 721849354 )
      return 0i64;
  }
  Illusion::SubmitContext::ApplyShaderTemplate(this, shader_stream);
  Illusion::SubmitContext::ApplyStateArgs(this, shader_stream, already_called_funcs_mask);
  mQueueMode = this->mQueueMode;
  if ( mQueueMode == QM_Single )
    return RenderQueueLayer::GetSolidRenderQueue(this->mRenderQueueProvider, 1u);
  v12 = mQueueMode - 1;
  if ( !v12 )
  {
    v14 = this->mStateValues.mParamValues[9];
    if ( v14 && v14[88] )
      return RenderQueueLayer::GetSolid1RenderQueue(this->mRenderQueueProvider, 1u);
    return RenderQueueLayer::GetSolidRenderQueue(this->mRenderQueueProvider, 1u);
  }
  if ( v12 != 1 )
    return 0i64;
  return `anonymous namespace::GBufferChooseRenderQueue(
           &this->mStateValues,
           shader_stream,
           this->mCullMetrics,
           this->mRenderQueueProvider);
}

// File Line: 533
// RVA: 0x5DA70
void __fastcall ForwardReflectedSubmitContext::ForwardReflectedSubmitContext(ForwardReflectedSubmitContext *this)
{
  Illusion::SubmitContext::SubmitContext(this);
  this->vfptr = (Illusion::SubmitContextVtbl *)&RenderSubmitContext::`vftable;
  this->mCullMetrics = 0i64;
  this->mTransparencyState = 0i64;
  this->vfptr = (Illusion::SubmitContextVtbl *)&LayerSubmitContext::`vftable;
  this->mQueueMode = QM_Default;
  this->mRenderQueueProvider = 0i64;
  this->vfptr = (Illusion::SubmitContextVtbl *)&ForwardReflectedSubmitContext::`vftable;
  this->mPerPhaseParams = 0i64;
}

// File Line: 537
// RVA: 0x5E540
Illusion::RenderQueue *__fastcall ForwardReflectedSubmitContext::OnPreSubmit(
        ForwardReflectedSubmitContext *this,
        UFG::qMemoryStream<Illusion::Shader,1160> *shader_stream,
        UFG::BitFlags128 *already_called_funcs_mask)
{
  Illusion::Texture *v6; // rax
  __int64 v7; // rbp
  void *alphaStateNone; // rcx
  void *rasterStateNormal; // rcx
  _QWORD *v10; // rcx
  __int64 v11; // rdx
  void *v12; // r9
  void *v13; // r8
  void *v14; // rax
  void *v15; // rax
  ForwardReflectedSubmitContext::OnPreSubmit::__l7::MapEntry *v16; // r14
  unsigned int v17; // esi
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v19; // rax
  UFG::qResourceInventory *v20; // rax
  UFG::qResourceWarehouse *v21; // rax
  UFG::qResourceInventory *v22; // rax
  UFG::qResourceWarehouse *v23; // rax
  _DWORD *v24; // rcx
  __int64 v26; // rax
  int v27; // edx
  ForwardReflectedSubmitContext::OnPreSubmit::__l7::MapEntry *i; // rcx
  UFG::qResourceData *mData; // rax
  LayerSubmitContext::QueueMode mQueueMode; // ecx
  __int32 v31; // ecx
  _BYTE *v33; // rax

  v6 = qword_142128EE8;
  this->mStateValues.mSetValueMask.mFlags[0] |= 0x8000000000000000ui64;
  this->mStateValues.mParamValues[63] = v6;
  v7 = 0i64;
  if ( *((_DWORD *)shader_stream->mMainMemoryAddress + 6) == 775895434 )
  {
    alphaStateNone = this->mPerPhaseParams->alphaStateNone;
    this->mStateValues.mSetValueMask.mFlags[0] |= 0x200ui64;
    this->mStateValues.mParamValues[9] = alphaStateNone;
    rasterStateNormal = this->mPerPhaseParams->rasterStateNormal;
    this->mStateValues.mSetValueMask.mFlags[0] |= 0x400ui64;
    this->mStateValues.mParamValues[10] = rasterStateNormal;
  }
  else
  {
    v10 = this->mStateValues.mParamValues[17];
    v11 = 0i64;
    if ( v10 )
    {
      v12 = this->mStateValues.mParamValues[9];
      v13 = this->mStateValues.mParamValues[10];
      if ( !v12 || !v13 )
        v11 = (__int64)v10 + v10[14] + 112;
      if ( !v12 )
      {
        v14 = *(void **)(v11 + 16);
        this->mStateValues.mSetValueMask.mFlags[0] |= 0x200ui64;
        this->mStateValues.mParamValues[9] = v14;
      }
      if ( !v13 )
      {
        v15 = *(void **)(v11 + 48);
        this->mStateValues.mSetValueMask.mFlags[0] |= 0x400ui64;
        this->mStateValues.mParamValues[10] = v15;
      }
    }
  }
  v16 = mapTable;
  if ( mapTable )
  {
    v17 = mapTableEntryCount;
  }
  else
  {
    v17 = (_DWORD)mapTable + 3;
    v16 = table;
    if ( (_S2_1 & 1) == 0 )
    {
      _S2_1 |= 1u;
      `eh vector constructor iterator(
        table,
        (unsigned int)((_DWORD)mapTable + 40),
        (_DWORD)mapTable + 3,
        (void (__fastcall *)(void *))`ForwardReflectedSubmitContext::OnPreSubmit::`7::MapEntry::MapEntry);
      atexit(ForwardReflectedSubmitContext::OnPreSubmit_::_10_::_dynamic_atexit_destructor_for__table__);
    }
    table[0]._orgUID = 543723269;
    Inventory = `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::RasterState>::`2::result )
    {
      v19 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v19, 0x3BC715E0u);
      `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Init(&stru_142137048, 0x3BC715E0u, 0xBC9FAF09, Inventory);
    dword_142137068 = -1810908948;
    v20 = `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::RasterState>::`2::result )
    {
      v21 = UFG::qResourceWarehouse::Instance();
      v20 = UFG::qResourceWarehouse::GetInventory(v21, 0x3BC715E0u);
      `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result = v20;
    }
    UFG::qResourceHandle::Init(&stru_142137070, 0x3BC715E0u, 0x940FB8EC, v20);
    dword_142137090 = -262489691;
    v22 = `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::RasterState>::`2::result )
    {
      v23 = UFG::qResourceWarehouse::Instance();
      v22 = UFG::qResourceWarehouse::GetInventory(v23, 0x3BC715E0u);
      `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result = v22;
    }
    UFG::qResourceHandle::Init(&stru_142137098, 0x3BC715E0u, 0x4B6C82C0u, v22);
    mapTable = table;
    mapTableEntryCount = v17;
  }
  v24 = this->mStateValues.mParamValues[10];
  if ( !v24 )
    return 0i64;
  if ( *((_BYTE *)v24 + 91) )
  {
    v26 = 0i64;
    if ( !v17 )
      return 0i64;
    v27 = v24[6];
    for ( i = v16; v27 != i->_orgUID; ++i )
    {
      v26 = (unsigned int)(v26 + 1);
      if ( (unsigned int)v26 >= v17 )
        return 0i64;
    }
    mData = v16[v26]._newState.mData;
    this->mStateValues.mSetValueMask.mFlags[0] |= 0x400ui64;
    this->mStateValues.mParamValues[10] = mData;
  }
  Illusion::SubmitContext::ApplyShaderTemplate(this, shader_stream);
  Illusion::SubmitContext::ApplyStateArgs(this, shader_stream, already_called_funcs_mask);
  mQueueMode = this->mQueueMode;
  if ( mQueueMode == QM_Single )
    return RenderQueueLayer::GetSolidRenderQueue(this->mRenderQueueProvider, 1u);
  v31 = mQueueMode - 1;
  if ( !v31 )
  {
    v33 = this->mStateValues.mParamValues[9];
    if ( v33 && v33[88] )
      return RenderQueueLayer::GetSolid1RenderQueue(this->mRenderQueueProvider, 1u);
    return RenderQueueLayer::GetSolidRenderQueue(this->mRenderQueueProvider, 1u);
  }
  if ( v31 == 1 )
    return `anonymous namespace::GBufferChooseRenderQueue(
             &this->mStateValues,
             shader_stream,
             this->mCullMetrics,
             this->mRenderQueueProvider);
  return (Illusion::RenderQueue *)v7;
}

// File Line: 638
// RVA: 0x5DAE0
void __fastcall ForwardSubmitContext::ForwardSubmitContext(ForwardSubmitContext *this)
{
  Illusion::SubmitContext::SubmitContext(this);
  this->vfptr = (Illusion::SubmitContextVtbl *)&RenderSubmitContext::`vftable;
  this->mCullMetrics = 0i64;
  this->mTransparencyState = 0i64;
  this->vfptr = (Illusion::SubmitContextVtbl *)&LayerSubmitContext::`vftable;
  this->mQueueMode = QM_Default;
  this->mRenderQueueProvider = 0i64;
  this->vfptr = (Illusion::SubmitContextVtbl *)&ForwardSubmitContext::`vftable;
  this->mPerPhaseParams = 0i64;
}

// File Line: 642
// RVA: 0x5E860
Illusion::RenderQueue *__fastcall ForwardSubmitContext::OnPreSubmit(
        ForwardSubmitContext *this,
        UFG::qMemoryStream<Illusion::Shader,1160> *shader_stream,
        UFG::BitFlags128 *already_called_funcs_mask)
{
  Illusion::Texture *v3; // rax
  void *alphaStateNone; // rdx
  void *rasterStateNormal; // rcx
  _QWORD *v9; // rcx
  __int64 v10; // rdx
  void *v11; // r9
  void *v12; // r8
  void *v13; // rax
  void *v14; // rax
  LayerSubmitContext::QueueMode mQueueMode; // edx
  __int32 v16; // edx
  _BYTE *v18; // rax

  v3 = qword_142128EE8;
  this->mStateValues.mSetValueMask.mFlags[0] |= 0x8000000000000000ui64;
  this->mStateValues.mParamValues[63] = v3;
  if ( *((_DWORD *)shader_stream->mMainMemoryAddress + 6) == 775895434 )
  {
    alphaStateNone = this->mPerPhaseParams->alphaStateNone;
    this->mStateValues.mSetValueMask.mFlags[0] |= 0x200ui64;
    this->mStateValues.mParamValues[9] = alphaStateNone;
    rasterStateNormal = this->mPerPhaseParams->rasterStateNormal;
    this->mStateValues.mSetValueMask.mFlags[0] |= 0x400ui64;
    this->mStateValues.mParamValues[10] = rasterStateNormal;
  }
  else
  {
    v9 = this->mStateValues.mParamValues[17];
    v10 = 0i64;
    if ( v9 )
    {
      v11 = this->mStateValues.mParamValues[9];
      v12 = this->mStateValues.mParamValues[10];
      if ( !v11 || !v12 )
        v10 = (__int64)v9 + v9[14] + 112;
      if ( !v11 )
      {
        v13 = *(void **)(v10 + 16);
        this->mStateValues.mSetValueMask.mFlags[0] |= 0x200ui64;
        this->mStateValues.mParamValues[9] = v13;
      }
      if ( !v12 )
      {
        v14 = *(void **)(v10 + 48);
        this->mStateValues.mSetValueMask.mFlags[0] |= 0x400ui64;
        this->mStateValues.mParamValues[10] = v14;
      }
    }
  }
  Illusion::SubmitContext::ApplyShaderTemplate(this, shader_stream);
  Illusion::SubmitContext::ApplyStateArgs(this, shader_stream, already_called_funcs_mask);
  mQueueMode = this->mQueueMode;
  if ( mQueueMode == QM_Single )
    return RenderQueueLayer::GetSolidRenderQueue(this->mRenderQueueProvider, 1u);
  v16 = mQueueMode - 1;
  if ( !v16 )
  {
    v18 = this->mStateValues.mParamValues[9];
    if ( v18 && v18[88] )
      return RenderQueueLayer::GetSolid1RenderQueue(this->mRenderQueueProvider, 1u);
    return RenderQueueLayer::GetSolidRenderQueue(this->mRenderQueueProvider, 1u);
  }
  if ( v16 == 1 )
    return `anonymous namespace::GBufferChooseRenderQueue(
             &this->mStateValues,
             shader_stream,
             this->mCullMetrics,
             this->mRenderQueueProvider);
  else
    return 0i64;
}

// File Line: 685
// RVA: 0x5DCC0
void __fastcall ShadowSubmitContext::ShadowSubmitContext(ShadowSubmitContext *this)
{
  Illusion::SubmitContext::SubmitContext(this);
  this->vfptr = (Illusion::SubmitContextVtbl *)&RenderSubmitContext::`vftable;
  this->mCullMetrics = 0i64;
  this->mTransparencyState = 0i64;
  this->vfptr = (Illusion::SubmitContextVtbl *)&LayerSubmitContext::`vftable;
  this->mQueueMode = QM_Default;
  this->mRenderQueueProvider = 0i64;
  this->vfptr = (Illusion::SubmitContextVtbl *)&ShadowSubmitContext::`vftable;
  this->mPerPhaseParams = 0i64;
}

// File Line: 689
// RVA: 0x5ED40
Illusion::RenderQueue *__fastcall ShadowSubmitContext::OnPreSubmit(
        ShadowSubmitContext *this,
        UFG::qMemoryStream<Illusion::Shader,1160> *shader_stream,
        UFG::BitFlags128 *already_called_funcs_mask)
{
  _QWORD *mMainMemoryAddress; // rax
  __int64 v5; // rcx
  char *v6; // rax
  void *rasterStateInvertCulling; // rcx
  void *alphaStateNoColorWrite; // rcx
  Illusion::Shader *v11; // rax
  LayerSubmitContext::QueueMode mQueueMode; // edx
  __int32 v13; // edx
  _BYTE *v15; // rax

  mMainMemoryAddress = shader_stream->mMainMemoryAddress;
  v5 = mMainMemoryAddress[13];
  v6 = (char *)(mMainMemoryAddress + 13);
  if ( v5 )
    v5 += (__int64)v6;
  if ( !*(_BYTE *)(v5 + 192) )
  {
    rasterStateInvertCulling = this->mPerPhaseParams->rasterStateInvertCulling;
    this->mStateValues.mSetValueMask.mFlags[0] |= 0x400ui64;
    this->mStateValues.mParamValues[10] = rasterStateInvertCulling;
    alphaStateNoColorWrite = this->mPerPhaseParams->alphaStateNoColorWrite;
    this->mStateValues.mSetValueMask.mFlags[0] |= 0x200ui64;
    this->mStateValues.mParamValues[9] = alphaStateNoColorWrite;
    v11 = `anonymous namespace::ChooseDepthShader(
            &this->mStateValues,
            (Illusion::Shader *)shader_stream->mMainMemoryAddress);
    this->mStateValues.mSetValueMask.mFlags[0] |= 2ui64;
    this->mStateValues.mParamValues[1] = v11;
    Illusion::SubmitContext::LoadShader(this, shader_stream);
  }
  Illusion::SubmitContext::ApplyShaderTemplate(this, shader_stream);
  Illusion::SubmitContext::ApplyStateArgs(this, shader_stream, already_called_funcs_mask);
  mQueueMode = this->mQueueMode;
  if ( mQueueMode == QM_Single )
    return RenderQueueLayer::GetSolidRenderQueue(this->mRenderQueueProvider, 1u);
  v13 = mQueueMode - 1;
  if ( !v13 )
  {
    v15 = this->mStateValues.mParamValues[9];
    if ( v15 && v15[88] )
      return RenderQueueLayer::GetSolid1RenderQueue(this->mRenderQueueProvider, 1u);
    return RenderQueueLayer::GetSolidRenderQueue(this->mRenderQueueProvider, 1u);
  }
  if ( v13 == 1 )
    return `anonymous namespace::GBufferChooseRenderQueue(
             &this->mStateValues,
             shader_stream,
             this->mCullMetrics,
             this->mRenderQueueProvider);
  else
    return 0i64;
}

// File Line: 730
// RVA: 0x5DC50
void __fastcall ShadowFrontFaceSubmitContext::ShadowFrontFaceSubmitContext(ShadowFrontFaceSubmitContext *this)
{
  Illusion::SubmitContext::SubmitContext(this);
  this->vfptr = (Illusion::SubmitContextVtbl *)&RenderSubmitContext::`vftable;
  this->mCullMetrics = 0i64;
  this->mTransparencyState = 0i64;
  this->vfptr = (Illusion::SubmitContextVtbl *)&LayerSubmitContext::`vftable;
  this->mQueueMode = QM_Default;
  this->mRenderQueueProvider = 0i64;
  this->vfptr = (Illusion::SubmitContextVtbl *)&ShadowFrontFaceSubmitContext::`vftable;
  this->mPerPhaseParams = 0i64;
}

// File Line: 734
// RVA: 0x5EC40
Illusion::RenderQueue *__fastcall ShadowFrontFaceSubmitContext::OnPreSubmit(
        ShadowFrontFaceSubmitContext *this,
        UFG::qMemoryStream<Illusion::Shader,1160> *shader_stream,
        UFG::BitFlags128 *already_called_funcs_mask)
{
  void *rasterStateNormal; // r9
  Illusion::StateValues *p_mStateValues; // rcx
  void *v8; // r9
  Illusion::Shader *v9; // rax
  LayerSubmitContext::QueueMode mQueueMode; // ecx
  __int32 v11; // ecx
  _BYTE *v13; // rax

  rasterStateNormal = this->mPerPhaseParams->rasterStateNormal;
  this->mStateValues.mSetValueMask.mFlags[0] |= 0x400ui64;
  p_mStateValues = &this->mStateValues;
  p_mStateValues->mParamValues[10] = rasterStateNormal;
  v8 = (void *)*((_QWORD *)p_mStateValues[3].mParamValues[7] + 1);
  p_mStateValues->mSetValueMask.mFlags[0] |= 0x200ui64;
  p_mStateValues->mParamValues[9] = v8;
  v9 = `anonymous namespace::ChooseDepthShader(p_mStateValues, (Illusion::Shader *)shader_stream->mMainMemoryAddress);
  if ( !v9 )
    return 0i64;
  this->mStateValues.mSetValueMask.mFlags[0] |= 2ui64;
  this->mStateValues.mParamValues[1] = v9;
  Illusion::SubmitContext::LoadShader(this, shader_stream);
  Illusion::SubmitContext::ApplyStateArgs(this, shader_stream, already_called_funcs_mask);
  mQueueMode = this->mQueueMode;
  if ( mQueueMode == QM_Single )
    return RenderQueueLayer::GetSolidRenderQueue(this->mRenderQueueProvider, 1u);
  v11 = mQueueMode - 1;
  if ( !v11 )
  {
    v13 = this->mStateValues.mParamValues[9];
    if ( v13 && v13[88] )
      return RenderQueueLayer::GetSolid1RenderQueue(this->mRenderQueueProvider, 1u);
    return RenderQueueLayer::GetSolidRenderQueue(this->mRenderQueueProvider, 1u);
  }
  if ( v11 != 1 )
    return 0i64;
  return `anonymous namespace::GBufferChooseRenderQueue(
           &this->mStateValues,
           shader_stream,
           this->mCullMetrics,
           this->mRenderQueueProvider);
}

// File Line: 772
// RVA: 0x5D980
void __fastcall CompositeSubmitContext::CompositeSubmitContext(CompositeSubmitContext *this)
{
  Illusion::SubmitContext::SubmitContext(this);
  this->vfptr = (Illusion::SubmitContextVtbl *)&RenderSubmitContext::`vftable;
  this->mCullMetrics = 0i64;
  this->mTransparencyState = 0i64;
  this->vfptr = (Illusion::SubmitContextVtbl *)&LayerSubmitContext::`vftable;
  this->mQueueMode = QM_Default;
  this->mRenderQueueProvider = 0i64;
  this->vfptr = (Illusion::SubmitContextVtbl *)&CompositeSubmitContext::`vftable;
  this->mOverrideMode = 0;
  this->mHighlightParams = 0i64;
}

// File Line: 776
// RVA: 0x5E240
Illusion::RenderQueue *__fastcall CompositeSubmitContext::OnPreSubmit(
        CompositeSubmitContext *this,
        UFG::qMemoryStream<Illusion::Shader,1160> *shader_stream,
        UFG::BitFlags128 *already_called_funcs_mask)
{
  __int64 v4; // rdi
  __int32 v7; // ecx
  _QWORD *mMainMemoryAddress; // rax
  __int64 v9; // rcx
  char *v10; // rax
  char *v11; // rcx
  void *rasterStateHighlight; // rcx
  void *alphaStateHighlight; // rcx
  void *textureGBufferNormal; // rcx
  _QWORD *v16; // rax
  __int64 v17; // rcx
  char *v18; // rax
  char *v19; // rax
  void *v20; // rax
  _QWORD *v21; // rcx
  __int64 v22; // rdx
  void *v23; // r9
  void *v24; // r8
  void *v25; // rax
  void *v26; // rax
  LayerSubmitContext::QueueMode mQueueMode; // ecx
  __int32 v28; // ecx
  _BYTE *v30; // rax

  v4 = 0i64;
  v7 = this->mOverrideMode - 1;
  if ( v7 )
  {
    if ( v7 == 1 )
    {
      mMainMemoryAddress = shader_stream->mMainMemoryAddress;
      v9 = mMainMemoryAddress[13];
      v10 = (char *)(mMainMemoryAddress + 13);
      if ( v9 )
        v11 = &v10[v9];
      else
        v11 = 0i64;
      if ( !*((_QWORD *)v11 + 18) )
        return 0i64;
      rasterStateHighlight = this->mHighlightParams->rasterStateHighlight;
      this->mStateValues.mSetValueMask.mFlags[0] |= 0x400ui64;
      this->mStateValues.mParamValues[10] = rasterStateHighlight;
      alphaStateHighlight = this->mHighlightParams->alphaStateHighlight;
      this->mStateValues.mSetValueMask.mFlags[0] |= 0x200ui64;
      this->mStateValues.mParamValues[9] = alphaStateHighlight;
      textureGBufferNormal = this->mHighlightParams->textureGBufferNormal;
      this->mStateValues.mSetValueMask.mFlags[0] |= 0x400000000000ui64;
      this->mStateValues.mParamValues[46] = textureGBufferNormal;
      v16 = shader_stream->mMainMemoryAddress;
      v17 = v16[13];
      v18 = (char *)(v16 + 13);
      if ( v17 )
        v19 = &v18[v17];
      else
        v19 = 0i64;
      v20 = (void *)*((_QWORD *)v19 + 18);
      this->mStateValues.mSetValueMask.mFlags[0] |= 2ui64;
      this->mStateValues.mParamValues[1] = v20;
      Illusion::SubmitContext::LoadShader(this, shader_stream);
    }
  }
  else
  {
    v21 = this->mStateValues.mParamValues[17];
    v22 = 0i64;
    if ( v21 )
    {
      v23 = this->mStateValues.mParamValues[9];
      v24 = this->mStateValues.mParamValues[10];
      if ( !v23 || !v24 )
        v22 = (__int64)v21 + v21[14] + 112;
      if ( !v23 )
      {
        v25 = *(void **)(v22 + 16);
        this->mStateValues.mSetValueMask.mFlags[0] |= 0x200ui64;
        this->mStateValues.mParamValues[9] = v25;
      }
      if ( !v24 )
      {
        v26 = *(void **)(v22 + 48);
        this->mStateValues.mSetValueMask.mFlags[0] |= 0x400ui64;
        this->mStateValues.mParamValues[10] = v26;
      }
    }
  }
  Illusion::SubmitContext::ApplyShaderTemplate(this, shader_stream);
  Illusion::SubmitContext::ApplyStateArgs(this, shader_stream, already_called_funcs_mask);
  mQueueMode = this->mQueueMode;
  if ( mQueueMode == QM_Single )
    return RenderQueueLayer::GetSolidRenderQueue(this->mRenderQueueProvider, 1u);
  v28 = mQueueMode - 1;
  if ( !v28 )
  {
    v30 = this->mStateValues.mParamValues[9];
    if ( v30 && v30[88] )
      return RenderQueueLayer::GetSolid1RenderQueue(this->mRenderQueueProvider, 1u);
    return RenderQueueLayer::GetSolidRenderQueue(this->mRenderQueueProvider, 1u);
  }
  if ( v28 == 1 )
    return `anonymous namespace::GBufferChooseRenderQueue(
             &this->mStateValues,
             shader_stream,
             this->mCullMetrics,
             this->mRenderQueueProvider);
  return (Illusion::RenderQueue *)v4;
}

