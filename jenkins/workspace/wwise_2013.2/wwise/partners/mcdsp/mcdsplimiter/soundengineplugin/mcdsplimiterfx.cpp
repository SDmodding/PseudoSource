// File Line: 31
// RVA: 0xAFC6E0
AK::IAkPlugin *__fastcall CreateMcDSPML1FX(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPlugin *result; // rax

  result = (AK::IAkPlugin *)in_pAllocator->vfptr->Malloc(in_pAllocator, 40ui64);
  if ( !result )
    return 0i64;
  result->vfptr = (AK::IAkPluginVtbl *)&CMcDSPLimiterFX::`vftable;
  result[1].vfptr = 0i64;
  result[2].vfptr = 0i64;
  LODWORD(result[3].vfptr) = -1;
  HIDWORD(result[3].vfptr) = 0;
  return result;
}

// File Line: 40
// RVA: 0xAFC3C0
void __fastcall CMcDSPLimiterFX::CMcDSPLimiterFX(CMcDSPLimiterFX *this)
{
  this->vfptr = (AK::IAkPluginVtbl *)&CMcDSPLimiterFX::`vftable;
  this->m_pSharedParams = 0i64;
  this->m_process = 0i64;
  this->m_FXState.FXTailHandler.uTotalTailFrames = 0;
  this->m_FXState.FXTailHandler.uTailFramesRemaining = -1;
}

// File Line: 52
// RVA: 0xAFC3F0
void __fastcall CMcDSPLimiterFX::~CMcDSPLimiterFX(CMcDSPLimiterFX *this)
{
  this->vfptr = (AK::IAkPluginVtbl *)&AK::IAkPlugin::`vftable;
}

// File Line: 61
// RVA: 0xAFC410
AKRESULT __fastcall CMcDSPLimiterFX::Init(CMcDSPLimiterFX *this, AK::IAkPluginMemAlloc *in_pAllocator, AK::IAkEffectPluginContext *in_pFXCtx, AK::IAkPluginParam *in_pParams, AkAudioFormat *in_rFormat)
{
  AK::IAkPluginMemAlloc *v5; // r15
  CMcDSPLimiterFX *v6; // rsi
  int v7; // edi
  AKRESULT result; // eax
  LimiterProcess *v9; // rax
  int v10; // ebx
  LimiterProcess *v11; // rax
  LimiterProcess *v12; // rax
  unsigned int v13; // edx
  LimiterProcessSurround71FloatImpl *v14; // rcx
  int v15; // eax
  LimiterProcessSurroundFloatImpl *v16; // rcx
  LimiterProcessStereoFloatImpl *v17; // rcx
  LimiterProcessMonoFloatImpl *v18; // rcx

  v5 = in_pAllocator;
  v6 = this;
  v7 = *((_DWORD *)in_rFormat + 1) & 0x3FFFF;
  if ( (unsigned int)(v7 - 3) > 1 && v7 != 63 && v7 != 1599 )
    return 78;
  this->m_pSharedParams = (CMcDSPLimiterFXParams *)in_pParams;
  v9 = (LimiterProcess *)((__int64 (__fastcall *)(AK::IAkPluginMemAlloc *, signed __int64, AK::IAkEffectPluginContext *))in_pAllocator->vfptr->Malloc)(
                           in_pAllocator,
                           216i64,
                           in_pFXCtx);
  v10 = 0;
  if ( v9 )
    LimiterProcess::LimiterProcess(v9);
  else
    v11 = 0i64;
  v6->m_process = v11;
  if ( !v11 )
    return 52;
  if ( in_rFormat->uSampleRate != v11->mSampleRate )
    v11->mSampleRate = in_rFormat->uSampleRate;
  result = MultiChannelSurroundProcess<LimiterProcessMonoFloatImpl,LimiterProcessStereoFloatImpl,LimiterProcessSurroundFloatImpl,LimiterProcessSurround71FloatImpl>::Init(
             (MultiChannelSurroundProcess<LimiterProcessMonoFloatImpl,LimiterProcessStereoFloatImpl,LimiterProcessSurroundFloatImpl,LimiterProcessSurround71FloatImpl> *)&v6->m_process->vfptr,
             v5,
             v7);
  if ( result == 1 )
  {
    v12 = v6->m_process;
    v13 = in_rFormat->uSampleRate;
    v14 = v12->mDSPSurround71Impl;
    if ( v14 )
    {
      v15 = LimiterProcessSurround71FloatImpl::GetNumTailFrames(v14, v13);
    }
    else
    {
      v16 = v12->mDSPSurroundImpl;
      if ( v16 )
      {
        v15 = LimiterProcessSurroundFloatImpl::GetNumTailFrames(v16, v13);
      }
      else
      {
        v17 = v12->mDSPStereoImpl;
        if ( v17 )
        {
          v15 = LimiterProcessStereoFloatImpl::GetNumTailFrames(v17, v13);
        }
        else
        {
          v18 = v12->mDSPMonoImpl;
          if ( !v18 )
          {
LABEL_22:
            v6->m_FXState.uTailLength = v10;
            return 1;
          }
          v15 = LimiterProcessMonoFloatImpl::GetNumTailFrames(v18, v13);
        }
      }
    }
    v10 = v15;
    goto LABEL_22;
  }
  return result;
}

// File Line: 97
// RVA: 0xAFC530
signed __int64 __fastcall CMcDSPLimiterFX::Term(CMcDSPLimiterFX *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  CMcDSPLimiterFX *v2; // rbx
  LimiterProcess *v3; // rcx
  AK::IAkPluginMemAlloc *v4; // rdi
  LimiterProcess *v5; // rsi

  v2 = this;
  v3 = this->m_process;
  v4 = in_pAllocator;
  if ( v3 )
  {
    MultiChannelSurroundProcess<LimiterProcessMonoFloatImpl,LimiterProcessStereoFloatImpl,LimiterProcessSurroundFloatImpl,LimiterProcessSurround71FloatImpl>::Term(
      (MultiChannelSurroundProcess<LimiterProcessMonoFloatImpl,LimiterProcessStereoFloatImpl,LimiterProcessSurroundFloatImpl,LimiterProcessSurround71FloatImpl> *)&v3->vfptr,
      in_pAllocator);
    v5 = v2->m_process;
    if ( v5 )
    {
      v5->vfptr->__vecDelDtor((Process *)v2->m_process, 0);
      v4->vfptr->Free(v4, v5);
    }
    v2->m_process = 0i64;
  }
  v2->vfptr->__vecDelDtor((AK::IAkPlugin *)&v2->vfptr, 0);
  v4->vfptr->Free(v4, v2);
  return 1i64;
}

// File Line: 120
// RVA: 0xAFC5B0
signed __int64 __fastcall CMcDSPLimiterFX::Reset(CMcDSPLimiterFX *this)
{
  return 1i64;
}

// File Line: 137
// RVA: 0xAFC5C0
signed __int64 __fastcall CMcDSPLimiterFX::GetPluginInfo(CMcDSPLimiterFX *this, AkPluginInfo *out_rPluginInfo)
{
  out_rPluginInfo->eType = 3;
  *(_WORD *)&out_rPluginInfo->bIsInPlace = 1;
  return 1i64;
}

// File Line: 150
// RVA: 0xAFC630
float __fastcall CMcDSPLimiterFX::UpdateParameters(CMcDSPLimiterFX *this)
{
  CMcDSPLimiterFXParams *v1; // rax
  LimiterCharacterType v2; // xmm0_4
  int v3; // xmm1_4
  float v4; // xmm2_4
  float v5; // xmm6_4
  float v6; // xmm3_4
  float v7; // xmm4_4
  LimiterProcess *v8; // rax
  __int64 v10; // [rsp+40h] [rbp-28h]

  v1 = this->m_pSharedParams;
  v2 = v1->m_Params.eMode;
  v3 = *(_DWORD *)&v1->m_Params.bParamsHaveChanged;
  v4 = v1->m_Params.fCeiling;
  v5 = v1->m_Params.fThreshold;
  v6 = v1->m_Params.fKnee;
  v7 = v1->m_Params.fRelease;
  v1->m_Params.bParamsHaveChanged = 0;
  if ( (_BYTE)v3 == 1 )
  {
    LODWORD(v10) = v2;
    v8 = this->m_process;
    v8->mParameters.ceiling = v4;
    v8->mParameters.threshold = v5;
    v8->mParameters.knee = v6;
    v8->mParameters.release = v7;
    *(_QWORD *)&v8->mParameters.character = v10;
    ((void (*)(void))this->m_process->vfptr->UpdateProcessValues)();
  }
  return v5;
}

// File Line: 256
// RVA: 0xAFC5E0
void __fastcall CMcDSPLimiterFX::Execute(CMcDSPLimiterFX *this, AkAudioBuffer *io_pBuffer)
{
  AkAudioBuffer *v2; // rdi
  CMcDSPLimiterFX *v3; // rbx

  v2 = io_pBuffer;
  v3 = this;
  CMcDSPLimiterFX::UpdateParameters(this);
  AkFXTailHandler::HandleTail(&v3->m_FXState.FXTailHandler, v2, v3->m_FXState.uTailLength);
  if ( v2->uValidFrames )
    v3->m_process->vfptr->ProcessAudio((Process *)&v3->m_process->vfptr, v2);
}

