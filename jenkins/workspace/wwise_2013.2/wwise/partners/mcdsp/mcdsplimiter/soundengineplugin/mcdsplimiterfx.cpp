// File Line: 31
// RVA: 0xAFC6E0
AK::IAkPlugin *__fastcall CreateMcDSPML1FX(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPlugin *result; // rax

  result = (AK::IAkPlugin *)in_pAllocator->vfptr->Malloc(in_pAllocator, 40i64);
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
AKRESULT __fastcall CMcDSPLimiterFX::Init(
        CMcDSPLimiterFX *this,
        AK::IAkPluginMemAlloc *in_pAllocator,
        AK::IAkEffectPluginContext *in_pFXCtx,
        CMcDSPLimiterFXParams *in_pParams,
        AkAudioFormat *in_rFormat)
{
  int v7; // edi
  AKRESULT result; // eax
  LimiterProcess *v9; // rax
  unsigned int v10; // ebx
  LimiterProcess *v11; // rax
  LimiterProcess *m_process; // rax
  unsigned int uSampleRate; // edx
  LimiterProcessSurround71FloatImpl *mDSPSurround71Impl; // rcx
  int NumTailFrames; // eax
  LimiterProcessSurroundFloatImpl *mDSPSurroundImpl; // rcx
  LimiterProcessStereoFloatImpl *mDSPStereoImpl; // rcx
  LimiterProcessMonoFloatImpl *mDSPMonoImpl; // rcx

  v7 = *((_DWORD *)in_rFormat + 1) & 0x3FFFF;
  if ( (unsigned int)(v7 - 3) > 1 && v7 != 63 && v7 != 1599 )
    return 78;
  this->m_pSharedParams = in_pParams;
  v9 = (LimiterProcess *)((__int64 (__fastcall *)(AK::IAkPluginMemAlloc *, __int64, AK::IAkEffectPluginContext *))in_pAllocator->vfptr->Malloc)(
                           in_pAllocator,
                           216i64,
                           in_pFXCtx);
  v10 = 0;
  if ( v9 )
    LimiterProcess::LimiterProcess(v9);
  else
    v11 = 0i64;
  this->m_process = v11;
  if ( !v11 )
    return 52;
  if ( in_rFormat->uSampleRate != v11->mSampleRate )
    v11->mSampleRate = in_rFormat->uSampleRate;
  result = MultiChannelSurroundProcess<LimiterProcessMonoFloatImpl,LimiterProcessStereoFloatImpl,LimiterProcessSurroundFloatImpl,LimiterProcessSurround71FloatImpl>::Init(
             this->m_process,
             in_pAllocator,
             v7);
  if ( result == AK_Success )
  {
    m_process = this->m_process;
    uSampleRate = in_rFormat->uSampleRate;
    mDSPSurround71Impl = m_process->mDSPSurround71Impl;
    if ( mDSPSurround71Impl )
    {
      NumTailFrames = LimiterProcessSurround71FloatImpl::GetNumTailFrames(mDSPSurround71Impl, uSampleRate);
    }
    else
    {
      mDSPSurroundImpl = m_process->mDSPSurroundImpl;
      if ( mDSPSurroundImpl )
      {
        NumTailFrames = LimiterProcessSurroundFloatImpl::GetNumTailFrames(mDSPSurroundImpl, uSampleRate);
      }
      else
      {
        mDSPStereoImpl = m_process->mDSPStereoImpl;
        if ( mDSPStereoImpl )
        {
          NumTailFrames = LimiterProcessStereoFloatImpl::GetNumTailFrames(mDSPStereoImpl, uSampleRate);
        }
        else
        {
          mDSPMonoImpl = m_process->mDSPMonoImpl;
          if ( !mDSPMonoImpl )
          {
LABEL_22:
            this->m_FXState.uTailLength = v10;
            return 1;
          }
          NumTailFrames = LimiterProcessMonoFloatImpl::GetNumTailFrames(mDSPMonoImpl, uSampleRate);
        }
      }
    }
    v10 = NumTailFrames;
    goto LABEL_22;
  }
  return result;
}

// File Line: 97
// RVA: 0xAFC530
__int64 __fastcall CMcDSPLimiterFX::Term(CMcDSPLimiterFX *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  LimiterProcess *m_process; // rcx
  LimiterProcess *v5; // rsi

  m_process = this->m_process;
  if ( m_process )
  {
    MultiChannelSurroundProcess<LimiterProcessMonoFloatImpl,LimiterProcessStereoFloatImpl,LimiterProcessSurroundFloatImpl,LimiterProcessSurround71FloatImpl>::Term(
      m_process,
      in_pAllocator);
    v5 = this->m_process;
    if ( v5 )
    {
      v5->vfptr->__vecDelDtor(this->m_process, 0);
      in_pAllocator->vfptr->Free(in_pAllocator, v5);
    }
    this->m_process = 0i64;
  }
  this->vfptr->__vecDelDtor(this, 0i64);
  in_pAllocator->vfptr->Free(in_pAllocator, this);
  return 1i64;
}

// File Line: 120
// RVA: 0xAFC5B0
__int64 __fastcall CMcDSPLimiterFX::Reset(CMcDSPLimiterFX *this)
{
  return 1i64;
}

// File Line: 137
// RVA: 0xAFC5C0
__int64 __fastcall CMcDSPLimiterFX::GetPluginInfo(CMcDSPLimiterFX *this, AkPluginInfo *out_rPluginInfo)
{
  out_rPluginInfo->eType = AkPluginTypeEffect;
  *(_WORD *)&out_rPluginInfo->bIsInPlace = 1;
  return 1i64;
}

// File Line: 150
// RVA: 0xAFC630
float __fastcall CMcDSPLimiterFX::UpdateParameters(CMcDSPLimiterFX *this)
{
  CMcDSPLimiterFXParams *m_pSharedParams; // rax
  LimiterCharacterType eMode; // xmm0_4
  int v3; // xmm1_4
  float fCeiling; // xmm2_4
  float fThreshold; // xmm6_4
  float fKnee; // xmm3_4
  float fRelease; // xmm4_4
  LimiterProcess *m_process; // rax
  __int64 v10; // [rsp+40h] [rbp-28h]

  m_pSharedParams = this->m_pSharedParams;
  eMode = m_pSharedParams->m_Params.eMode;
  v3 = *(_DWORD *)&m_pSharedParams->m_Params.bParamsHaveChanged;
  fCeiling = m_pSharedParams->m_Params.fCeiling;
  fThreshold = m_pSharedParams->m_Params.fThreshold;
  fKnee = m_pSharedParams->m_Params.fKnee;
  fRelease = m_pSharedParams->m_Params.fRelease;
  m_pSharedParams->m_Params.bParamsHaveChanged = 0;
  if ( (_BYTE)v3 == 1 )
  {
    LODWORD(v10) = eMode;
    m_process = this->m_process;
    m_process->mParameters.ceiling = fCeiling;
    m_process->mParameters.threshold = fThreshold;
    m_process->mParameters.knee = fKnee;
    m_process->mParameters.release = fRelease;
    *(_QWORD *)&m_process->mParameters.character = v10;
    this->m_process->vfptr->UpdateProcessValues(this->m_process);
  }
  return fThreshold;
}

// File Line: 256
// RVA: 0xAFC5E0
void __fastcall CMcDSPLimiterFX::Execute(CMcDSPLimiterFX *this, AkAudioBuffer *io_pBuffer)
{
  CMcDSPLimiterFX::UpdateParameters(this);
  AkFXTailHandler::HandleTail(&this->m_FXState.FXTailHandler, io_pBuffer, this->m_FXState.uTailLength);
  if ( io_pBuffer->uValidFrames )
    this->m_process->vfptr->ProcessAudio(this->m_process, io_pBuffer);
}

