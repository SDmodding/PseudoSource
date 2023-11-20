// File Line: 42
// RVA: 0x5DDF0
void __fastcall `anonymous namespace'::ApplyDiffuseTextureStateOverrides(Illusion::StateValues *state_values)
{
  _QWORD *v1; // r8
  signed __int64 v2; // rdx
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
      v2 = (signed __int64)v1 + v1[14] + 112;
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
void __fastcall `anonymous namespace'::ApplyHKAlphaTestFixup(Illusion::StateValues *state_values, void *aReplacement_Remote, void *transparency_state)
{
  Illusion::StateValues *v3; // r9
  _BYTE *v4; // rcx
  void *v5; // r10
  unsigned __int16 *v6; // rdx
  Illusion::Texture *v7; // rcx
  Illusion::Texture *v8; // rax
  void *v9; // [rsp+18h] [rbp+18h]

  v3 = state_values;
  v4 = state_values->mParamValues[9];
  v9 = transparency_state;
  v5 = aReplacement_Remote;
  if ( !v4 )
    goto LABEL_14;
  if ( transparency_state
    && !v4[88]
    && (signed int)(unsigned __int8)transparency_state > 0
    && (unsigned __int8)transparency_state < Render::TransparencySystem::msOpaqueIndex )
  {
    if ( (unsigned __int8)transparency_state < (signed int)BYTE1(v9) )
    {
      v6 = (unsigned __int16 *)*((_QWORD *)&Render::TransparencySystem::msAlphaStateInHandle[0].mData
                               + 4 * (unsigned __int8)transparency_state);
      goto LABEL_10;
    }
    if ( (unsigned __int8)transparency_state > (signed int)BYTE1(v9) )
    {
      v6 = (unsigned __int16 *)*((_QWORD *)&Render::TransparencySystem::msAlphaStateOutHandle[0].mData
                               + 4 * (unsigned __int8)transparency_state);
LABEL_10:
      if ( v6 )
      {
        v3->mSetValueMask.mFlags[0] |= 0x200ui64;
        v3->mParamValues[9] = v6;
        v7 = Render::TransparencySystem::msDitherMaskTextures[v6[50]];
        v3->mSetValueMask.mFlags[0] |= 0x8000000000000000ui64;
        v3->mParamValues[63] = v7;
        return;
      }
      goto LABEL_12;
    }
  }
LABEL_12:
  if ( v4[93] )
  {
    v3->mSetValueMask.mFlags[0] |= 0x200ui64;
    v3->mParamValues[9] = v5;
  }
LABEL_14:
  v8 = qword_142128EE8;
  v3->mSetValueMask.mFlags[0] |= 0x8000000000000000ui64;
  v3->mParamValues[63] = v8;
}

// File Line: 123
// RVA: 0x5E150
void __fastcall `anonymous namespace'::InitializeGBufferShaderSelector(Illusion::StateValues *state_values, Illusion::ShaderSelector *shader_selector)
{
  void *v2; // rax
  void *v3; // r10
  _BYTE *v4; // r9
  char *v5; // r11
  float *v6; // rax
  unsigned __int64 v7; // rax
  unsigned __int64 v8; // rax

  v2 = state_values->mParamValues[44];
  v3 = state_values->mParamValues[9];
  v4 = 0i64;
  v5 = 0i64;
  if ( v2 )
    v5 = (char *)state_values->mParamValues[44];
  if ( v3 )
    v4 = state_values->mParamValues[9];
  if ( (v2 && (v6 = (float *)(v5 + 128), v5 != (char *)-128i64) || (v6 = (float *)state_values->mParamValues[33]) != 0i64)
    && v6[2] != 0.0
    || !v3
    || !v4[88] )
  {
    shader_selector->mAddState.mFlags[0] |= 0x800000000ui64;
  }
  else
  {
    shader_selector->mAddState.mFlags[0] &= 0xFFFFFFF7FFFFFFFFui64;
  }
  shader_selector->mAddState.mFlags[0] |= 0x800000000000000ui64;
  v7 = shader_selector->mAddState.mFlags[0];
  if ( state_values->mParamValues[57] )
    v8 = v7 | 0x200000000000000i64;
  else
    v8 = v7 & 0xFDFFFFFFFFFFFFFFui64;
  shader_selector->mAddState.mFlags[0] = v8;
}

// File Line: 193
// RVA: 0x5E050
Illusion::RenderQueue *__fastcall `anonymous namespace'::GBufferChooseRenderQueue(Illusion::StateValues *state_values, UFG::qMemoryStream<Illusion::Shader,1160> *shader_stream, Render::CullMetrics *cull_metrics, RenderQueueLayer *rq_provider)
{
  UFG::qMemoryStream<Illusion::Shader,1160> *v4; // r10
  float v5; // xmm2_4
  float *v6; // r11
  _BYTE *v7; // r8
  float *v8; // rdx
  float v9; // xmm1_4
  signed __int64 v10; // rax
  bool v11; // zf
  Illusion::RenderQueue *result; // rax
  float v13; // xmm0_4
  int v14; // ecx

  v4 = shader_stream;
  if ( cull_metrics )
    v5 = cull_metrics->mDistance;
  else
    v5 = FLOAT_1000_0;
  v6 = (float *)state_values->mParamValues[44];
  v7 = state_values->mParamValues[9];
  v8 = (float *)state_values->mParamValues[33];
  v9 = 0.0;
  v10 = 0i64;
  if ( v6 )
  {
    v10 = (signed __int64)(v6 + 32);
    v11 = v6[34] == 0.0;
  }
  else
  {
    if ( !v8 )
      goto LABEL_10;
    v11 = v8[2] == 0.0;
  }
  if ( !v11 )
    return RenderQueueLayer::GetSolid1RenderQueue(rq_provider, *((_DWORD *)v4->mMainMemoryAddress + 28));
LABEL_10:
  if ( v7 && v7[88] )
  {
    if ( v10 )
      v9 = *(float *)(v10 + 12);
    v13 = (float)(1000.0 - (float)(v9 + v5)) * 100.0;
    if ( v13 <= 1.0 )
    {
      v13 = *(float *)&FLOAT_1_0;
    }
    else if ( v13 >= 100000.0 )
    {
      return RenderQueueLayer::GetAlphaRenderQueue(rq_provider, (signed int)100000.0);
    }
    result = RenderQueueLayer::GetAlphaRenderQueue(rq_provider, (signed int)v13);
  }
  else
  {
    v14 = 15;
    if ( (signed int)v5 / 15 < 15 )
      v14 = (signed int)v5 / 15;
    result = RenderQueueLayer::GetSolidRenderQueue(
               rq_provider,
               (v14 << 28) ^ (*((_DWORD *)v4->mMainMemoryAddress + 28) ^ (v14 << 28)) & 0xFFFFFFFu);
  }
  return result;
}

// File Line: 263
// RVA: 0x5DF20
Illusion::Shader *__fastcall `anonymous namespace'::ChooseDepthShader(Illusion::StateValues *state_values, Illusion::Shader *shader)
{
  Illusion::Shader *v2; // rbx
  __int64 v3; // rax
  Illusion::Shader *result; // rax
  unsigned int v5; // ebx
  UFG::qResourceInventory *v6; // rax
  UFG::qResourceWarehouse *v7; // rax

  v2 = shader;
  if ( !(_S1_10 & 1) )
  {
    _S1_10 |= 1u;
    UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&simpleHandle_2.mPrev);
    atexit(_anonymous_namespace_::ChooseDepthShader_::_2_::_dynamic_atexit_destructor_for__simpleHandle__);
  }
  v3 = v2->mShaderUser.mOffset;
  if ( v3 )
    v3 += (__int64)&v2->mShaderUser;
  result = *(Illusion::Shader **)(v3 + 16);
  if ( !result )
  {
    if ( !simpleInit_2 )
    {
      v5 = UFG::qStringHashUpper32("DR_EmitDepthFBX", 0xFFFFFFFF);
      v6 = `UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result;
      if ( !`UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result )
      {
        v7 = UFG::qResourceWarehouse::Instance();
        v6 = UFG::qResourceWarehouse::GetInventory(v7, 0x8B5561A1);
        `UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result = v6;
      }
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&simpleHandle_2.mPrev, 0x8B5561A1, v5, v6);
      simpleInit_2 = 1;
    }
    result = (Illusion::Shader *)simpleHandle_2.mData;
  }
  return result;
}

// File Line: 288
// RVA: 0x5DD30
void __fastcall SimpleTaskSubmitContext::SimpleTaskSubmitContext(SimpleTaskSubmitContext *this)
{
  SimpleTaskSubmitContext *v1; // rbx

  v1 = this;
  Illusion::SubmitContext::SubmitContext((Illusion::SubmitContext *)&this->vfptr);
  v1->vfptr = (Illusion::SubmitContextVtbl *)&SimpleTaskSubmitContext::`vftable';
  v1->mRenderQueueProvider = 0i64;
}

// File Line: 292
// RVA: 0x5DDE0
void __fastcall SimpleTaskSubmitContext::AddRenderCommand(SimpleTaskSubmitContext *this, __int16 command_type, __int16 index, void *data)
{
  RenderQueueLayer::AddRenderCommand(this->mRenderQueueProvider, command_type, index, data);
}

// File Line: 297
// RVA: 0x5EE80
Illusion::RenderQueue *__fastcall SimpleTaskSubmitContext::OnPreSubmit(SimpleTaskSubmitContext *this, UFG::qMemoryStream<Illusion::Shader,1160> *shader_stream, UFG::BitFlags128 *already_called_funcs_mask)
{
  SimpleTaskSubmitContext *v3; // rbx

  v3 = this;
  Illusion::SubmitContext::ApplyStateArgs(
    (Illusion::SubmitContext *)&this->vfptr,
    shader_stream,
    already_called_funcs_mask);
  return RenderQueueLayer::GetSolidRenderQueue(v3->mRenderQueueProvider, 1u);
}

// File Line: 313
// RVA: 0x5DBC0
void __fastcall LayerSubmitContext::LayerSubmitContext(LayerSubmitContext *this)
{
  LayerSubmitContext *v1; // rbx

  v1 = this;
  Illusion::SubmitContext::SubmitContext((Illusion::SubmitContext *)&this->vfptr);
  v1->vfptr = (Illusion::SubmitContextVtbl *)&RenderSubmitContext::`vftable';
  v1->mCullMetrics = 0i64;
  v1->mTransparencyState = 0i64;
  v1->vfptr = (Illusion::SubmitContextVtbl *)&LayerSubmitContext::`vftable';
  v1->mQueueMode = 1;
  v1->mRenderQueueProvider = 0i64;
}

// File Line: 317
// RVA: 0x5DDD0
void __fastcall LayerSubmitContext::AddRenderCommand(LayerSubmitContext *this, __int16 command_type, __int16 index, void *data)
{
  RenderQueueLayer::AddRenderCommand(this->mRenderQueueProvider, command_type, index, data);
}

// File Line: 322
// RVA: 0x5DFF0
Illusion::RenderQueue *__fastcall LayerSubmitContext::ChooseRenderQueue(LayerSubmitContext *this, UFG::qMemoryStream<Illusion::Shader,1160> *shader_stream, Render::CullMetrics *cull_metrics)
{
  LayerSubmitContext *v3; // r9
  LayerSubmitContext::QueueMode v4; // ecx
  int v5; // ecx
  Illusion::RenderQueue *result; // rax
  _BYTE *v7; // rax

  v3 = this;
  v4 = this->mQueueMode;
  if ( v4 == QM_Single )
    return RenderQueueLayer::GetSolidRenderQueue(v3->mRenderQueueProvider, 1u);
  v5 = v4 - 1;
  if ( !v5 )
  {
    v7 = v3->mStateValues.mParamValues[9];
    if ( v7 && v7[88] )
      return RenderQueueLayer::GetSolid1RenderQueue(v3->mRenderQueueProvider, 1u);
    return RenderQueueLayer::GetSolidRenderQueue(v3->mRenderQueueProvider, 1u);
  }
  if ( v5 == 1 )
    result = `anonymous namespace'::GBufferChooseRenderQueue(
               &v3->mStateValues,
               shader_stream,
               cull_metrics,
               v3->mRenderQueueProvider);
  else
    result = 0i64;
  return result;
}

// File Line: 359
// RVA: 0x5EB70
Illusion::RenderQueue *__fastcall LayerSubmitContext::OnPreSubmit(LayerSubmitContext *this, UFG::qMemoryStream<Illusion::Shader,1160> *shader_stream, UFG::BitFlags128 *already_called_funcs_mask)
{
  UFG::BitFlags128 *v3; // rbx
  UFG::qMemoryStream<Illusion::Shader,1160> *v4; // rsi
  LayerSubmitContext *v5; // rdi
  LayerSubmitContext::QueueMode v6; // ecx
  int v7; // ecx
  Illusion::RenderQueue *result; // rax
  _BYTE *v9; // rax

  v3 = already_called_funcs_mask;
  v4 = shader_stream;
  v5 = this;
  Illusion::SubmitContext::ApplyShaderTemplate((Illusion::SubmitContext *)&this->vfptr, shader_stream);
  Illusion::SubmitContext::ApplyStateArgs((Illusion::SubmitContext *)&v5->vfptr, v4, v3);
  v6 = v5->mQueueMode;
  if ( v6 == QM_Single )
    return RenderQueueLayer::GetSolidRenderQueue(v5->mRenderQueueProvider, 1u);
  v7 = v6 - 1;
  if ( !v7 )
  {
    v9 = v5->mStateValues.mParamValues[9];
    if ( v9 && v9[88] )
      return RenderQueueLayer::GetSolid1RenderQueue(v5->mRenderQueueProvider, 1u);
    return RenderQueueLayer::GetSolidRenderQueue(v5->mRenderQueueProvider, 1u);
  }
  if ( v7 == 1 )
    result = `anonymous namespace'::GBufferChooseRenderQueue(
               &v5->mStateValues,
               v4,
               v5->mCullMetrics,
               v5->mRenderQueueProvider);
  else
    result = 0i64;
  return result;
}

// File Line: 389
// RVA: 0x5DB50
void __fastcall GBufferSubmitContext::GBufferSubmitContext(GBufferSubmitContext *this)
{
  GBufferSubmitContext *v1; // rbx

  v1 = this;
  Illusion::SubmitContext::SubmitContext((Illusion::SubmitContext *)&this->vfptr);
  v1->vfptr = (Illusion::SubmitContextVtbl *)&RenderSubmitContext::`vftable';
  v1->mCullMetrics = 0i64;
  v1->mTransparencyState = 0i64;
  v1->vfptr = (Illusion::SubmitContextVtbl *)&LayerSubmitContext::`vftable';
  v1->mQueueMode = 1;
  v1->mRenderQueueProvider = 0i64;
  v1->vfptr = (Illusion::SubmitContextVtbl *)&GBufferSubmitContext::`vftable';
}

// File Line: 398
// RVA: 0x5E9C0
Illusion::RenderQueue *__fastcall GBufferSubmitContext::OnPreSubmit(GBufferSubmitContext *this, UFG::qMemoryStream<Illusion::Shader,1160> *shader_stream, UFG::BitFlags128 *already_called_funcs_mask)
{
  UFG::BitFlags128 *v3; // r14
  UFG::qMemoryStream<Illusion::Shader,1160> *v4; // rsi
  GBufferSubmitContext *v5; // rdi
  Illusion::StateValues *v6; // rbx
  void *v7; // r9
  void *v8; // rcx
  _QWORD *v9; // rcx
  signed __int64 v10; // rdx
  void *v11; // r9
  void *v12; // r8
  void *v13; // rax
  void *v14; // rax
  void *v15; // rcx
  char *v16; // rax
  float *v17; // rax
  Illusion::RenderQueue *v19; // rbp
  void *v20; // rdx

  v3 = already_called_funcs_mask;
  v4 = shader_stream;
  v5 = this;
  v6 = &this->mStateValues;
  if ( *((_DWORD *)shader_stream->mMainMemoryAddress + 6) == 775895434 )
  {
    v7 = this->mPerPhaseParams->alphaStateNone;
    v6->mSetValueMask.mFlags[0] |= 0x200ui64;
    this->mStateValues.mParamValues[9] = v7;
    v8 = this->mPerPhaseParams->rasterStateNormal;
    v6->mSetValueMask.mFlags[0] |= 0x400ui64;
    v6->mParamValues[10] = v8;
  }
  else
  {
    v9 = this->mStateValues.mParamValues[17];
    v10 = 0i64;
    if ( v9 )
    {
      v11 = v6->mParamValues[9];
      v12 = v6->mParamValues[10];
      if ( !v11 || !v12 )
        v10 = (signed __int64)v9 + v9[14] + 112;
      if ( !v11 )
      {
        v13 = *(void **)(v10 + 16);
        v6->mSetValueMask.mFlags[0] |= 0x200ui64;
        v6->mParamValues[9] = v13;
      }
      if ( !v12 )
      {
        v14 = *(void **)(v10 + 48);
        v6->mSetValueMask.mFlags[0] |= 0x400ui64;
        v6->mParamValues[10] = v14;
      }
    }
  }
  v15 = v5->mPerPhaseParams->forceRasterState;
  if ( v15 )
  {
    v6->mSetValueMask.mFlags[0] |= 0x400ui64;
    v6->mParamValues[10] = v15;
    v16 = (char *)v5->mStateValues.mParamValues[44];
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
  `anonymous namespace'::ApplyHKAlphaTestFixup(v6, v5->mPerPhaseParams->alphaStatePunchThrough, v5->mTransparencyState);
  `anonymous namespace'::InitializeGBufferShaderSelector(v6, v5->mShaderSelector);
  v19 = `anonymous namespace'::GBufferChooseRenderQueue(v6, v4, v5->mCullMetrics, v5->mRenderQueueProvider);
  if ( v19->mUserData )
    v20 = v5->mPerPhaseParams->compositeTargetParams;
  else
    v20 = v5->mPerPhaseParams->gbufferTargetParams;
  v6->mSetValueMask.mFlags[0] |= 0x800ui64;
  v6->mParamValues[11] = v20;
  Illusion::SubmitContext::ApplyShaderTemplate((Illusion::SubmitContext *)&v5->vfptr, v4);
  Illusion::SubmitContext::ApplyStateArgs((Illusion::SubmitContext *)&v5->vfptr, v4, v3);
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
  ForwardEnvMapSubmitContext *v1; // rbx

  v1 = this;
  Illusion::SubmitContext::SubmitContext((Illusion::SubmitContext *)&this->vfptr);
  v1->vfptr = (Illusion::SubmitContextVtbl *)&RenderSubmitContext::`vftable';
  v1->mCullMetrics = 0i64;
  v1->mTransparencyState = 0i64;
  v1->vfptr = (Illusion::SubmitContextVtbl *)&LayerSubmitContext::`vftable';
  v1->mQueueMode = 1;
  v1->mRenderQueueProvider = 0i64;
  v1->vfptr = (Illusion::SubmitContextVtbl *)&ForwardEnvMapSubmitContext::`vftable';
  v1->mPerPhaseParams = 0i64;
}

// File Line: 479
// RVA: 0x5E410
Illusion::RenderQueue *__fastcall ForwardEnvMapSubmitContext::OnPreSubmit(ForwardEnvMapSubmitContext *this, UFG::qMemoryStream<Illusion::Shader,1160> *shader_stream, UFG::BitFlags128 *already_called_funcs_mask)
{
  Illusion::Texture *v3; // rax
  ForwardEnvMapSubmitContext *v4; // rbx
  int v5; // ecx
  UFG::BitFlags128 *v6; // rbp
  UFG::qMemoryStream<Illusion::Shader,1160> *v7; // rsi
  void *v8; // rcx
  void *v9; // rcx
  _DWORD *v10; // rax
  LayerSubmitContext::QueueMode v11; // ecx
  int v12; // ecx
  _BYTE *v14; // rax

  v3 = qword_142128EE8;
  v4 = this;
  v4->mStateValues.mSetValueMask.mFlags[0] |= 0x8000000000000000ui64;
  this->mStateValues.mParamValues[63] = v3;
  v5 = *((_DWORD *)shader_stream->mMainMemoryAddress + 6);
  v6 = already_called_funcs_mask;
  v7 = shader_stream;
  if ( v5 == 1278767530 )
    return 0i64;
  if ( v5 == 775895434 )
  {
    v8 = v4->mPerPhaseParams->alphaStateNone;
    v4->mStateValues.mSetValueMask.mFlags[0] |= 0x200ui64;
    v4->mStateValues.mParamValues[9] = v8;
    v9 = v4->mPerPhaseParams->rasterStateNormal;
    v4->mStateValues.mSetValueMask.mFlags[0] |= 0x400ui64;
    v4->mStateValues.mParamValues[10] = v9;
  }
  else
  {
    `anonymous namespace'::ApplyDiffuseTextureStateOverrides(&v4->mStateValues);
  }
  v10 = v4->mStateValues.mParamValues[9];
  if ( v10 )
  {
    if ( v10[6] == 721849354 )
      return 0i64;
  }
  Illusion::SubmitContext::ApplyShaderTemplate((Illusion::SubmitContext *)&v4->vfptr, v7);
  Illusion::SubmitContext::ApplyStateArgs((Illusion::SubmitContext *)&v4->vfptr, v7, v6);
  v11 = v4->mQueueMode;
  if ( v11 == QM_Single )
    return RenderQueueLayer::GetSolidRenderQueue(v4->mRenderQueueProvider, 1u);
  v12 = v11 - 1;
  if ( !v12 )
  {
    v14 = v4->mStateValues.mParamValues[9];
    if ( v14 && v14[88] )
      return RenderQueueLayer::GetSolid1RenderQueue(v4->mRenderQueueProvider, 1u);
    return RenderQueueLayer::GetSolidRenderQueue(v4->mRenderQueueProvider, 1u);
  }
  if ( v12 != 1 )
    return 0i64;
  return `anonymous namespace'::GBufferChooseRenderQueue(
           &v4->mStateValues,
           v7,
           v4->mCullMetrics,
           v4->mRenderQueueProvider);
}

// File Line: 533
// RVA: 0x5DA70
void __fastcall ForwardReflectedSubmitContext::ForwardReflectedSubmitContext(ForwardReflectedSubmitContext *this)
{
  ForwardReflectedSubmitContext *v1; // rbx

  v1 = this;
  Illusion::SubmitContext::SubmitContext((Illusion::SubmitContext *)&this->vfptr);
  v1->vfptr = (Illusion::SubmitContextVtbl *)&RenderSubmitContext::`vftable';
  v1->mCullMetrics = 0i64;
  v1->mTransparencyState = 0i64;
  v1->vfptr = (Illusion::SubmitContextVtbl *)&LayerSubmitContext::`vftable';
  v1->mQueueMode = 1;
  v1->mRenderQueueProvider = 0i64;
  v1->vfptr = (Illusion::SubmitContextVtbl *)&ForwardReflectedSubmitContext::`vftable';
  v1->mPerPhaseParams = 0i64;
}

// File Line: 537
// RVA: 0x5E540
Illusion::RenderQueue *__fastcall ForwardReflectedSubmitContext::OnPreSubmit(ForwardReflectedSubmitContext *this, UFG::qMemoryStream<Illusion::Shader,1160> *shader_stream, UFG::BitFlags128 *already_called_funcs_mask)
{
  UFG::BitFlags128 *v3; // r12
  UFG::qMemoryStream<Illusion::Shader,1160> *v4; // r15
  ForwardReflectedSubmitContext *v5; // rdi
  Illusion::Texture *v6; // rax
  Illusion::RenderQueue *v7; // rbp
  void *v8; // rcx
  void *v9; // rcx
  _QWORD *v10; // rcx
  signed __int64 v11; // rdx
  void *v12; // r9
  void *v13; // r8
  void *v14; // rax
  void *v15; // rax
  ForwardReflectedSubmitContext::OnPreSubmit::__l7::MapEntry *v16; // r14
  unsigned int v17; // esi
  UFG::qResourceInventory *v18; // rax
  UFG::qResourceWarehouse *v19; // rax
  UFG::qResourceInventory *v20; // rax
  UFG::qResourceWarehouse *v21; // rax
  UFG::qResourceInventory *v22; // rax
  UFG::qResourceWarehouse *v23; // rax
  _DWORD *v24; // rcx
  __int64 v26; // rax
  int v27; // edx
  ForwardReflectedSubmitContext::OnPreSubmit::__l7::MapEntry *v28; // rcx
  UFG::qResourceData *v29; // rax
  LayerSubmitContext::QueueMode v30; // ecx
  int v31; // ecx
  Illusion::RenderQueue *v32; // rax
  _BYTE *v33; // rax

  v3 = already_called_funcs_mask;
  v4 = shader_stream;
  v5 = this;
  v6 = qword_142128EE8;
  v5->mStateValues.mSetValueMask.mFlags[0] |= 0x8000000000000000ui64;
  this->mStateValues.mParamValues[63] = v6;
  v7 = 0i64;
  if ( *((_DWORD *)shader_stream->mMainMemoryAddress + 6) == 775895434 )
  {
    v8 = this->mPerPhaseParams->alphaStateNone;
    v5->mStateValues.mSetValueMask.mFlags[0] |= 0x200ui64;
    v5->mStateValues.mParamValues[9] = v8;
    v9 = v5->mPerPhaseParams->rasterStateNormal;
    v5->mStateValues.mSetValueMask.mFlags[0] |= 0x400ui64;
    v5->mStateValues.mParamValues[10] = v9;
  }
  else
  {
    v10 = this->mStateValues.mParamValues[17];
    v11 = 0i64;
    if ( v10 )
    {
      v12 = v5->mStateValues.mParamValues[9];
      v13 = v5->mStateValues.mParamValues[10];
      if ( !v12 || !v13 )
        v11 = (signed __int64)v10 + v10[14] + 112;
      if ( !v12 )
      {
        v14 = *(void **)(v11 + 16);
        v5->mStateValues.mSetValueMask.mFlags[0] |= 0x200ui64;
        v5->mStateValues.mParamValues[9] = v14;
      }
      if ( !v13 )
      {
        v15 = *(void **)(v11 + 48);
        v5->mStateValues.mSetValueMask.mFlags[0] |= 0x400ui64;
        v5->mStateValues.mParamValues[10] = v15;
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
    if ( !(_S2_1 & 1) )
    {
      _S2_1 |= 1u;
      `eh vector constructor iterator'(
        table,
        (unsigned int)((_DWORD)mapTable + 40),
        (_DWORD)mapTable + 3,
        (void (__fastcall *)(void *))`ForwardReflectedSubmitContext::OnPreSubmit'::`7'::MapEntry::MapEntry);
      atexit(ForwardReflectedSubmitContext::OnPreSubmit_::_10_::_dynamic_atexit_destructor_for__table__);
    }
    table[0]._orgUID = 543723269;
    v18 = `UFG::qGetResourceInventory<Illusion::RasterState>'::`2'::result;
    if ( !`UFG::qGetResourceInventory<Illusion::RasterState>'::`2'::result )
    {
      v19 = UFG::qResourceWarehouse::Instance();
      v18 = UFG::qResourceWarehouse::GetInventory(v19, 0x3BC715E0u);
      `UFG::qGetResourceInventory<Illusion::RasterState>'::`2'::result = v18;
    }
    UFG::qResourceHandle::Init(&stru_142137048, 0x3BC715E0u, 0xBC9FAF09, v18);
    dword_142137068 = -1810908948;
    v20 = `UFG::qGetResourceInventory<Illusion::RasterState>'::`2'::result;
    if ( !`UFG::qGetResourceInventory<Illusion::RasterState>'::`2'::result )
    {
      v21 = UFG::qResourceWarehouse::Instance();
      v20 = UFG::qResourceWarehouse::GetInventory(v21, 0x3BC715E0u);
      `UFG::qGetResourceInventory<Illusion::RasterState>'::`2'::result = v20;
    }
    UFG::qResourceHandle::Init(&stru_142137070, 0x3BC715E0u, 0x940FB8EC, v20);
    dword_142137090 = -262489691;
    v22 = `UFG::qGetResourceInventory<Illusion::RasterState>'::`2'::result;
    if ( !`UFG::qGetResourceInventory<Illusion::RasterState>'::`2'::result )
    {
      v23 = UFG::qResourceWarehouse::Instance();
      v22 = UFG::qResourceWarehouse::GetInventory(v23, 0x3BC715E0u);
      `UFG::qGetResourceInventory<Illusion::RasterState>'::`2'::result = v22;
    }
    UFG::qResourceHandle::Init(&stru_142137098, 0x3BC715E0u, 0x4B6C82C0u, v22);
    mapTable = table;
    mapTableEntryCount = v17;
  }
  v24 = v5->mStateValues.mParamValues[10];
  if ( !v24 )
    return 0i64;
  if ( *((_BYTE *)v24 + 91) )
  {
    v26 = 0i64;
    if ( !v17 )
      return 0i64;
    v27 = v24[6];
    v28 = v16;
    while ( v27 != v28->_orgUID )
    {
      v26 = (unsigned int)(v26 + 1);
      ++v28;
      if ( (unsigned int)v26 >= v17 )
        return 0i64;
    }
    v29 = v16[v26]._newState.mData;
    v5->mStateValues.mSetValueMask.mFlags[0] |= 0x400ui64;
    v5->mStateValues.mParamValues[10] = v29;
  }
  Illusion::SubmitContext::ApplyShaderTemplate((Illusion::SubmitContext *)&v5->vfptr, v4);
  Illusion::SubmitContext::ApplyStateArgs((Illusion::SubmitContext *)&v5->vfptr, v4, v3);
  v30 = v5->mQueueMode;
  if ( v30 == QM_Single )
    goto LABEL_38;
  v31 = v30 - 1;
  if ( !v31 )
  {
    v33 = v5->mStateValues.mParamValues[9];
    if ( v33 && v33[88] )
    {
      v32 = RenderQueueLayer::GetSolid1RenderQueue(v5->mRenderQueueProvider, 1u);
      goto LABEL_39;
    }
LABEL_38:
    v32 = RenderQueueLayer::GetSolidRenderQueue(v5->mRenderQueueProvider, 1u);
    goto LABEL_39;
  }
  if ( v31 == 1 )
  {
    v32 = `anonymous namespace'::GBufferChooseRenderQueue(
            &v5->mStateValues,
            v4,
            v5->mCullMetrics,
            v5->mRenderQueueProvider);
LABEL_39:
    v7 = v32;
  }
  return v7;
}

// File Line: 638
// RVA: 0x5DAE0
void __fastcall ForwardSubmitContext::ForwardSubmitContext(ForwardSubmitContext *this)
{
  ForwardSubmitContext *v1; // rbx

  v1 = this;
  Illusion::SubmitContext::SubmitContext((Illusion::SubmitContext *)&this->vfptr);
  v1->vfptr = (Illusion::SubmitContextVtbl *)&RenderSubmitContext::`vftable';
  v1->mCullMetrics = 0i64;
  v1->mTransparencyState = 0i64;
  v1->vfptr = (Illusion::SubmitContextVtbl *)&LayerSubmitContext::`vftable';
  v1->mQueueMode = 1;
  v1->mRenderQueueProvider = 0i64;
  v1->vfptr = (Illusion::SubmitContextVtbl *)&ForwardSubmitContext::`vftable';
  v1->mPerPhaseParams = 0i64;
}

// File Line: 642
// RVA: 0x5E860
Illusion::RenderQueue *__fastcall ForwardSubmitContext::OnPreSubmit(ForwardSubmitContext *this, UFG::qMemoryStream<Illusion::Shader,1160> *shader_stream, UFG::BitFlags128 *already_called_funcs_mask)
{
  Illusion::Texture *v3; // rax
  ForwardSubmitContext *v4; // rdi
  UFG::BitFlags128 *v5; // rbp
  UFG::qMemoryStream<Illusion::Shader,1160> *v6; // rsi
  void *v7; // rdx
  void *v8; // rcx
  _QWORD *v9; // rcx
  signed __int64 v10; // rdx
  void *v11; // r9
  void *v12; // r8
  void *v13; // rax
  void *v14; // rax
  LayerSubmitContext::QueueMode v15; // edx
  int v16; // edx
  Illusion::RenderQueue *result; // rax
  _BYTE *v18; // rax

  v3 = qword_142128EE8;
  v4 = this;
  v4->mStateValues.mSetValueMask.mFlags[0] |= 0x8000000000000000ui64;
  this->mStateValues.mParamValues[63] = v3;
  v5 = already_called_funcs_mask;
  v6 = shader_stream;
  if ( *((_DWORD *)shader_stream->mMainMemoryAddress + 6) == 775895434 )
  {
    v7 = this->mPerPhaseParams->alphaStateNone;
    this->mStateValues.mSetValueMask.mFlags[0] |= 0x200ui64;
    this->mStateValues.mParamValues[9] = v7;
    v8 = this->mPerPhaseParams->rasterStateNormal;
    v4->mStateValues.mSetValueMask.mFlags[0] |= 0x400ui64;
    v4->mStateValues.mParamValues[10] = v8;
  }
  else
  {
    v9 = this->mStateValues.mParamValues[17];
    v10 = 0i64;
    if ( v9 )
    {
      v11 = v4->mStateValues.mParamValues[9];
      v12 = v4->mStateValues.mParamValues[10];
      if ( !v11 || !v12 )
        v10 = (signed __int64)v9 + v9[14] + 112;
      if ( !v11 )
      {
        v13 = *(void **)(v10 + 16);
        v4->mStateValues.mSetValueMask.mFlags[0] |= 0x200ui64;
        v4->mStateValues.mParamValues[9] = v13;
      }
      if ( !v12 )
      {
        v14 = *(void **)(v10 + 48);
        v4->mStateValues.mSetValueMask.mFlags[0] |= 0x400ui64;
        v4->mStateValues.mParamValues[10] = v14;
      }
    }
  }
  Illusion::SubmitContext::ApplyShaderTemplate((Illusion::SubmitContext *)&v4->vfptr, v6);
  Illusion::SubmitContext::ApplyStateArgs((Illusion::SubmitContext *)&v4->vfptr, v6, v5);
  v15 = v4->mQueueMode;
  if ( v15 == QM_Single )
    return RenderQueueLayer::GetSolidRenderQueue(v4->mRenderQueueProvider, 1u);
  v16 = v15 - 1;
  if ( !v16 )
  {
    v18 = v4->mStateValues.mParamValues[9];
    if ( v18 && v18[88] )
      return RenderQueueLayer::GetSolid1RenderQueue(v4->mRenderQueueProvider, 1u);
    return RenderQueueLayer::GetSolidRenderQueue(v4->mRenderQueueProvider, 1u);
  }
  if ( v16 == 1 )
    result = `anonymous namespace'::GBufferChooseRenderQueue(
               &v4->mStateValues,
               v6,
               v4->mCullMetrics,
               v4->mRenderQueueProvider);
  else
    result = 0i64;
  return result;
}

// File Line: 685
// RVA: 0x5DCC0
void __fastcall ShadowSubmitContext::ShadowSubmitContext(ShadowSubmitContext *this)
{
  ShadowSubmitContext *v1; // rbx

  v1 = this;
  Illusion::SubmitContext::SubmitContext((Illusion::SubmitContext *)&this->vfptr);
  v1->vfptr = (Illusion::SubmitContextVtbl *)&RenderSubmitContext::`vftable';
  v1->mCullMetrics = 0i64;
  v1->mTransparencyState = 0i64;
  v1->vfptr = (Illusion::SubmitContextVtbl *)&LayerSubmitContext::`vftable';
  v1->mQueueMode = 1;
  v1->mRenderQueueProvider = 0i64;
  v1->vfptr = (Illusion::SubmitContextVtbl *)&ShadowSubmitContext::`vftable';
  v1->mPerPhaseParams = 0i64;
}

// File Line: 689
// RVA: 0x5ED40
Illusion::RenderQueue *__fastcall ShadowSubmitContext::OnPreSubmit(ShadowSubmitContext *this, UFG::qMemoryStream<Illusion::Shader,1160> *shader_stream, UFG::BitFlags128 *already_called_funcs_mask)
{
  _QWORD *v3; // rax
  ShadowSubmitContext *v4; // rdi
  __int64 v5; // rcx
  signed __int64 v6; // rax
  UFG::BitFlags128 *v7; // rbp
  UFG::qMemoryStream<Illusion::Shader,1160> *v8; // rsi
  void *v9; // rcx
  void *v10; // rcx
  Illusion::Shader *v11; // rax
  LayerSubmitContext::QueueMode v12; // edx
  int v13; // edx
  Illusion::RenderQueue *result; // rax
  _BYTE *v15; // rax

  v3 = shader_stream->mMainMemoryAddress;
  v4 = this;
  v5 = v3[13];
  v6 = (signed __int64)(v3 + 13);
  v7 = already_called_funcs_mask;
  v8 = shader_stream;
  if ( v5 )
    v5 += v6;
  if ( !*(_BYTE *)(v5 + 192) )
  {
    v9 = v4->mPerPhaseParams->rasterStateInvertCulling;
    v4->mStateValues.mSetValueMask.mFlags[0] |= 0x400ui64;
    v4->mStateValues.mParamValues[10] = v9;
    v10 = v4->mPerPhaseParams->alphaStateNoColorWrite;
    v4->mStateValues.mSetValueMask.mFlags[0] |= 0x200ui64;
    v4->mStateValues.mParamValues[9] = v10;
    v11 = `anonymous namespace'::ChooseDepthShader(
            &v4->mStateValues,
            (Illusion::Shader *)shader_stream->mMainMemoryAddress);
    v4->mStateValues.mSetValueMask.mFlags[0] |= 2ui64;
    v4->mStateValues.mParamValues[1] = v11;
    Illusion::SubmitContext::LoadShader((Illusion::SubmitContext *)&v4->vfptr, v8);
  }
  Illusion::SubmitContext::ApplyShaderTemplate((Illusion::SubmitContext *)&v4->vfptr, v8);
  Illusion::SubmitContext::ApplyStateArgs((Illusion::SubmitContext *)&v4->vfptr, v8, v7);
  v12 = v4->mQueueMode;
  if ( v12 == QM_Single )
    return RenderQueueLayer::GetSolidRenderQueue(v4->mRenderQueueProvider, 1u);
  v13 = v12 - 1;
  if ( !v13 )
  {
    v15 = v4->mStateValues.mParamValues[9];
    if ( v15 && v15[88] )
      return RenderQueueLayer::GetSolid1RenderQueue(v4->mRenderQueueProvider, 1u);
    return RenderQueueLayer::GetSolidRenderQueue(v4->mRenderQueueProvider, 1u);
  }
  if ( v13 == 1 )
    result = `anonymous namespace'::GBufferChooseRenderQueue(
               &v4->mStateValues,
               v8,
               v4->mCullMetrics,
               v4->mRenderQueueProvider);
  else
    result = 0i64;
  return result;
}

// File Line: 730
// RVA: 0x5DC50
void __fastcall ShadowFrontFaceSubmitContext::ShadowFrontFaceSubmitContext(ShadowFrontFaceSubmitContext *this)
{
  ShadowFrontFaceSubmitContext *v1; // rbx

  v1 = this;
  Illusion::SubmitContext::SubmitContext((Illusion::SubmitContext *)&this->vfptr);
  v1->vfptr = (Illusion::SubmitContextVtbl *)&RenderSubmitContext::`vftable';
  v1->mCullMetrics = 0i64;
  v1->mTransparencyState = 0i64;
  v1->vfptr = (Illusion::SubmitContextVtbl *)&LayerSubmitContext::`vftable';
  v1->mQueueMode = 1;
  v1->mRenderQueueProvider = 0i64;
  v1->vfptr = (Illusion::SubmitContextVtbl *)&ShadowFrontFaceSubmitContext::`vftable';
  v1->mPerPhaseParams = 0i64;
}

// File Line: 734
// RVA: 0x5EC40
Illusion::RenderQueue *__fastcall ShadowFrontFaceSubmitContext::OnPreSubmit(ShadowFrontFaceSubmitContext *this, UFG::qMemoryStream<Illusion::Shader,1160> *shader_stream, UFG::BitFlags128 *already_called_funcs_mask)
{
  UFG::qMemoryStream<Illusion::Shader,1160> *v3; // rsi
  ShadowFrontFaceSubmitContext *v4; // rbx
  void *v5; // r9
  Illusion::StateValues *v6; // rcx
  UFG::BitFlags128 *v7; // rbp
  void *v8; // r9
  Illusion::Shader *v9; // rax
  LayerSubmitContext::QueueMode v10; // ecx
  int v11; // ecx
  _BYTE *v13; // rax

  v3 = shader_stream;
  v4 = this;
  v5 = this->mPerPhaseParams->rasterStateNormal;
  this->mStateValues.mSetValueMask.mFlags[0] |= 0x400ui64;
  v6 = &this->mStateValues;
  v6->mParamValues[10] = v5;
  v7 = already_called_funcs_mask;
  v8 = (void *)*((_QWORD *)v6[3].mParamValues[7] + 1);
  v6->mSetValueMask.mFlags[0] |= 0x200ui64;
  v6->mParamValues[9] = v8;
  v9 = `anonymous namespace'::ChooseDepthShader(v6, (Illusion::Shader *)shader_stream->mMainMemoryAddress);
  if ( !v9 )
    return 0i64;
  v4->mStateValues.mSetValueMask.mFlags[0] |= 2ui64;
  v4->mStateValues.mParamValues[1] = v9;
  Illusion::SubmitContext::LoadShader((Illusion::SubmitContext *)&v4->vfptr, v3);
  Illusion::SubmitContext::ApplyStateArgs((Illusion::SubmitContext *)&v4->vfptr, v3, v7);
  v10 = v4->mQueueMode;
  if ( v10 == QM_Single )
    return RenderQueueLayer::GetSolidRenderQueue(v4->mRenderQueueProvider, 1u);
  v11 = v10 - 1;
  if ( !v11 )
  {
    v13 = v4->mStateValues.mParamValues[9];
    if ( v13 && v13[88] )
      return RenderQueueLayer::GetSolid1RenderQueue(v4->mRenderQueueProvider, 1u);
    return RenderQueueLayer::GetSolidRenderQueue(v4->mRenderQueueProvider, 1u);
  }
  if ( v11 != 1 )
    return 0i64;
  return `anonymous namespace'::GBufferChooseRenderQueue(
           &v4->mStateValues,
           v3,
           v4->mCullMetrics,
           v4->mRenderQueueProvider);
}

// File Line: 772
// RVA: 0x5D980
void __fastcall CompositeSubmitContext::CompositeSubmitContext(CompositeSubmitContext *this)
{
  CompositeSubmitContext *v1; // rbx

  v1 = this;
  Illusion::SubmitContext::SubmitContext((Illusion::SubmitContext *)&this->vfptr);
  v1->vfptr = (Illusion::SubmitContextVtbl *)&RenderSubmitContext::`vftable';
  v1->mCullMetrics = 0i64;
  v1->mTransparencyState = 0i64;
  v1->vfptr = (Illusion::SubmitContextVtbl *)&LayerSubmitContext::`vftable';
  v1->mQueueMode = 1;
  v1->mRenderQueueProvider = 0i64;
  v1->vfptr = (Illusion::SubmitContextVtbl *)&CompositeSubmitContext::`vftable';
  v1->mOverrideMode = 0;
  v1->mHighlightParams = 0i64;
}

// File Line: 776
// RVA: 0x5E240
Illusion::RenderQueue *__fastcall CompositeSubmitContext::OnPreSubmit(CompositeSubmitContext *this, UFG::qMemoryStream<Illusion::Shader,1160> *shader_stream, UFG::BitFlags128 *already_called_funcs_mask)
{
  CompositeSubmitContext *v3; // rbx
  Illusion::RenderQueue *v4; // rdi
  UFG::BitFlags128 *v5; // rbp
  UFG::qMemoryStream<Illusion::Shader,1160> *v6; // rsi
  __int32 v7; // ecx
  _QWORD *v8; // rax
  __int64 v9; // rcx
  signed __int64 v10; // rax
  signed __int64 v11; // rcx
  void *v13; // rcx
  void *v14; // rcx
  void *v15; // rcx
  _QWORD *v16; // rax
  __int64 v17; // rcx
  signed __int64 v18; // rax
  signed __int64 v19; // rax
  void *v20; // rax
  _QWORD *v21; // rcx
  signed __int64 v22; // rdx
  void *v23; // r9
  void *v24; // r8
  void *v25; // rax
  void *v26; // rax
  LayerSubmitContext::QueueMode v27; // ecx
  int v28; // ecx
  Illusion::RenderQueue *v29; // rax
  _BYTE *v30; // rax

  v3 = this;
  v4 = 0i64;
  v5 = already_called_funcs_mask;
  v6 = shader_stream;
  v7 = this->mOverrideMode - 1;
  if ( v7 )
  {
    if ( v7 == 1 )
    {
      v8 = shader_stream->mMainMemoryAddress;
      v9 = v8[13];
      v10 = (signed __int64)(v8 + 13);
      if ( v9 )
        v11 = v10 + v9;
      else
        v11 = 0i64;
      if ( !*(_QWORD *)(v11 + 144) )
        return 0i64;
      v13 = v3->mHighlightParams->rasterStateHighlight;
      v3->mStateValues.mSetValueMask.mFlags[0] |= 0x400ui64;
      v3->mStateValues.mParamValues[10] = v13;
      v14 = v3->mHighlightParams->alphaStateHighlight;
      v3->mStateValues.mSetValueMask.mFlags[0] |= 0x200ui64;
      v3->mStateValues.mParamValues[9] = v14;
      v15 = v3->mHighlightParams->textureGBufferNormal;
      v3->mStateValues.mSetValueMask.mFlags[0] |= 0x400000000000ui64;
      v3->mStateValues.mParamValues[46] = v15;
      v16 = shader_stream->mMainMemoryAddress;
      v17 = v16[13];
      v18 = (signed __int64)(v16 + 13);
      if ( v17 )
        v19 = v17 + v18;
      else
        v19 = 0i64;
      v20 = *(void **)(v19 + 144);
      v3->mStateValues.mSetValueMask.mFlags[0] |= 2ui64;
      v3->mStateValues.mParamValues[1] = v20;
      Illusion::SubmitContext::LoadShader((Illusion::SubmitContext *)&v3->vfptr, shader_stream);
    }
  }
  else
  {
    v21 = v3->mStateValues.mParamValues[17];
    v22 = 0i64;
    if ( v21 )
    {
      v23 = v3->mStateValues.mParamValues[9];
      v24 = v3->mStateValues.mParamValues[10];
      if ( !v23 || !v24 )
        v22 = (signed __int64)v21 + v21[14] + 112;
      if ( !v23 )
      {
        v25 = *(void **)(v22 + 16);
        v3->mStateValues.mSetValueMask.mFlags[0] |= 0x200ui64;
        v3->mStateValues.mParamValues[9] = v25;
      }
      if ( !v24 )
      {
        v26 = *(void **)(v22 + 48);
        v3->mStateValues.mSetValueMask.mFlags[0] |= 0x400ui64;
        v3->mStateValues.mParamValues[10] = v26;
      }
    }
  }
  Illusion::SubmitContext::ApplyShaderTemplate((Illusion::SubmitContext *)&v3->vfptr, v6);
  Illusion::SubmitContext::ApplyStateArgs((Illusion::SubmitContext *)&v3->vfptr, v6, v5);
  v27 = v3->mQueueMode;
  if ( v27 == QM_Single )
    goto LABEL_27;
  v28 = v27 - 1;
  if ( !v28 )
  {
    v30 = v3->mStateValues.mParamValues[9];
    if ( v30 && v30[88] )
    {
      v29 = RenderQueueLayer::GetSolid1RenderQueue(v3->mRenderQueueProvider, 1u);
      goto LABEL_28;
    }
LABEL_27:
    v29 = RenderQueueLayer::GetSolidRenderQueue(v3->mRenderQueueProvider, 1u);
    goto LABEL_28;
  }
  if ( v28 == 1 )
  {
    v29 = `anonymous namespace'::GBufferChooseRenderQueue(
            &v3->mStateValues,
            v6,
            v3->mCullMetrics,
            v3->mRenderQueueProvider);
LABEL_28:
    v4 = v29;
  }
  return v4;
}

