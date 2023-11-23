// File Line: 16
// RVA: 0xACC5E0
AK::IAkPlugin *__fastcall CreateDelayFX(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPlugin *result; // rax
  AK::IAkPlugin *v2; // rbx

  result = (AK::IAkPlugin *)in_pAllocator->vfptr->Malloc(in_pAllocator, 152i64);
  v2 = result;
  if ( result )
  {
    result->vfptr = (AK::IAkPluginVtbl *)&CAkDelayFX::`vftable;
    CAkDelayFXDSP::CAkDelayFXDSP((CAkDelayFXDSP *)&result[1]);
    v2[17].vfptr = 0i64;
    v2[18].vfptr = 0i64;
    return v2;
  }
  return result;
}

// File Line: 38
// RVA: 0xACC720
__int64 __fastcall CAkDelayFX::Init(
        CAkDelayFX *this,
        AK::IAkPluginMemAlloc *in_pAllocator,
        AK::IAkEffectPluginContext *in_pFXCtx,
        CAkDelayFXParams *in_pParams,
        AkAudioFormat *in_rFormat)
{
  AkDelayFXParams *v5; // rbx
  AkDelayFXParams *v8; // rsi
  char v9; // al
  CAkDelayFXParams *m_pParams; // rax
  AKRESULT inited; // ebx
  __int64 result; // rax

  v5 = 0i64;
  this->m_pParams = in_pParams;
  this->m_pAllocator = in_pAllocator;
  v8 = &in_pParams->AkDelayFXParams;
  if ( !in_pParams )
    v8 = 0i64;
  v9 = ((__int64 (__fastcall *)(AK::IAkEffectPluginContext *))in_pFXCtx->vfptr[1].__vecDelDtor)(in_pFXCtx);
  CAkDelayFXDSP::Setup(&this->m_FXState, v8, v9, in_rFormat->uSampleRate);
  m_pParams = this->m_pParams;
  if ( m_pParams )
    v5 = &m_pParams->AkDelayFXParams;
  inited = CAkDelayFXDSP::InitDelay(&this->m_FXState, in_pAllocator, v5, *((_DWORD *)in_rFormat + 1) & 0x3FFFF);
  CAkDelayFXDSP::ComputeTailLength(
    &this->m_FXState,
    this->m_pParams->RTPC.bFeedbackEnabled,
    this->m_pParams->RTPC.fFeedback);
  this->m_pParams->NonRTPC.bHasChanged = 0;
  result = (unsigned int)inited;
  this->m_pParams->RTPC.bHasChanged = 0;
  return result;
}

// File Line: 55
// RVA: 0xACC820
__int64 __fastcall CAkDelayFX::Term(CAkDelayFX *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  CAkDelayFXDSP::TermDelay(&this->m_FXState, in_pAllocator);
  if ( this )
  {
    this->vfptr->__vecDelDtor(this, 0i64);
    in_pAllocator->vfptr->Free(in_pAllocator, this);
  }
  return 1i64;
}

// File Line: 63
// RVA: 0xACC800
__int64 __fastcall CAkDelayFX::Reset(CAkDelayFX *this)
{
  CAkDelayFXDSP::ResetDelay(&this->m_FXState);
  return 1i64;
}

// File Line: 70
// RVA: 0xACC700
__int64 __fastcall CAkDelayFX::GetPluginInfo(CAkDelayFX *this, AkPluginInfo *out_rPluginInfo)
{
  out_rPluginInfo->eType = AkPluginTypeEffect;
  *(_WORD *)&out_rPluginInfo->bIsInPlace = 1;
  return 1i64;
}

// File Line: 94
// RVA: 0xACC640
void __fastcall CAkDelayFX::Execute(CAkDelayFX *this, AkAudioBuffer *io_pBuffer)
{
  CAkDelayFXParams *m_pParams; // rax
  AkDelayFXParams *v3; // rdi
  AkDelayFXParams *v6; // r8
  CAkDelayFXParams *v7; // rax
  CAkDelayFXParams *v8; // rax

  m_pParams = this->m_pParams;
  v3 = 0i64;
  if ( !m_pParams->NonRTPC.bHasChanged )
    goto LABEL_6;
  v6 = &m_pParams->AkDelayFXParams;
  if ( !m_pParams )
    v6 = 0i64;
  if ( CAkDelayFXDSP::InitDelay(&this->m_FXState, this->m_pAllocator, v6, io_pBuffer->uChannelMask) == AK_Success )
  {
    CAkDelayFXDSP::ResetDelay(&this->m_FXState);
    this->m_pParams->NonRTPC.bHasChanged = 0;
LABEL_6:
    v7 = this->m_pParams;
    if ( v7->RTPC.bHasChanged )
    {
      CAkDelayFXDSP::ComputeTailLength(&this->m_FXState, v7->RTPC.bFeedbackEnabled, v7->RTPC.fFeedback);
      this->m_pParams->RTPC.bHasChanged = 0;
    }
    v8 = this->m_pParams;
    if ( v8 )
      v3 = &v8->AkDelayFXParams;
    CAkDelayFXDSP::Process(&this->m_FXState, io_pBuffer, v3);
  }
}

