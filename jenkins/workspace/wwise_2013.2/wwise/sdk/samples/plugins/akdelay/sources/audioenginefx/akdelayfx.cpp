// File Line: 16
// RVA: 0xACC5E0
AK::IAkPlugin *__fastcall CreateDelayFX(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPlugin *result; // rax
  AK::IAkPlugin *v2; // rbx

  result = (AK::IAkPlugin *)in_pAllocator->vfptr->Malloc(in_pAllocator, 152ui64);
  v2 = result;
  if ( result )
  {
    result->vfptr = (AK::IAkPluginVtbl *)&CAkDelayFX::`vftable;
    CAkDelayFXDSP::CAkDelayFXDSP((CAkDelayFXDSP *)&result[1]);
    v2[17].vfptr = 0i64;
    v2[18].vfptr = 0i64;
    result = v2;
  }
  return result;
}

// File Line: 38
// RVA: 0xACC720
__int64 __fastcall CAkDelayFX::Init(CAkDelayFX *this, AK::IAkPluginMemAlloc *in_pAllocator, AK::IAkEffectPluginContext *in_pFXCtx, AK::IAkPluginParam *in_pParams, AkAudioFormat *in_rFormat)
{
  AkDelayFXParams *v5; // rbx
  AK::IAkPluginMemAlloc *v6; // rbp
  CAkDelayFX *v7; // rdi
  AkDelayFXParams *v8; // rsi
  char v9; // al
  CAkDelayFXParams *v10; // rax
  AKRESULT v11; // ebx
  __int64 result; // rax

  v5 = 0i64;
  v6 = in_pAllocator;
  v7 = this;
  this->m_pParams = (CAkDelayFXParams *)in_pParams;
  this->m_pAllocator = in_pAllocator;
  v8 = (AkDelayFXParams *)&in_pParams[1];
  if ( !in_pParams )
    v8 = 0i64;
  v9 = ((__int64 (__fastcall *)(AK::IAkEffectPluginContext *))in_pFXCtx->vfptr[1].__vecDelDtor)(in_pFXCtx);
  CAkDelayFXDSP::Setup(&v7->m_FXState, v8, v9, in_rFormat->uSampleRate);
  v10 = v7->m_pParams;
  if ( v10 )
    v5 = (AkDelayFXParams *)&v10->RTPC;
  v11 = CAkDelayFXDSP::InitDelay(&v7->m_FXState, v6, v5, *((_DWORD *)in_rFormat + 1) & 0x3FFFF);
  CAkDelayFXDSP::ComputeTailLength(&v7->m_FXState, v7->m_pParams->RTPC.bFeedbackEnabled, v7->m_pParams->RTPC.fFeedback);
  v7->m_pParams->NonRTPC.bHasChanged = 0;
  result = (unsigned int)v11;
  v7->m_pParams->RTPC.bHasChanged = 0;
  return result;
}

// File Line: 55
// RVA: 0xACC820
signed __int64 __fastcall CAkDelayFX::Term(CAkDelayFX *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  CAkDelayFX *v2; // rbx
  AK::IAkPluginMemAlloc *v3; // rdi

  v2 = this;
  v3 = in_pAllocator;
  CAkDelayFXDSP::TermDelay(&this->m_FXState, in_pAllocator);
  if ( v2 )
  {
    v2->vfptr->__vecDelDtor((AK::IAkPlugin *)&v2->vfptr, 0);
    v3->vfptr->Free(v3, v2);
  }
  return 1i64;
}

// File Line: 63
// RVA: 0xACC800
signed __int64 __fastcall CAkDelayFX::Reset(CAkDelayFX *this)
{
  CAkDelayFXDSP::ResetDelay(&this->m_FXState);
  return 1i64;
}

// File Line: 70
// RVA: 0xACC700
signed __int64 __fastcall CAkDelayFX::GetPluginInfo(CAkDelayFX *this, AkPluginInfo *out_rPluginInfo)
{
  out_rPluginInfo->eType = 3;
  *(_WORD *)&out_rPluginInfo->bIsInPlace = 1;
  return 1i64;
}

// File Line: 94
// RVA: 0xACC640
void __fastcall CAkDelayFX::Execute(CAkDelayFX *this, AkAudioBuffer *io_pBuffer)
{
  CAkDelayFXParams *v2; // rax
  AkDelayFXParams *v3; // rdi
  AkAudioBuffer *v4; // rsi
  CAkDelayFX *v5; // rbx
  AkDelayFXParams *v6; // r8
  CAkDelayFXParams *v7; // rax
  CAkDelayFXParams *v8; // rax

  v2 = this->m_pParams;
  v3 = 0i64;
  v4 = io_pBuffer;
  v5 = this;
  if ( !v2->NonRTPC.bHasChanged )
    goto LABEL_6;
  v6 = (AkDelayFXParams *)&v2->RTPC;
  if ( !v2 )
    v6 = 0i64;
  if ( CAkDelayFXDSP::InitDelay(&this->m_FXState, this->m_pAllocator, v6, io_pBuffer->uChannelMask) == 1 )
  {
    CAkDelayFXDSP::ResetDelay(&v5->m_FXState);
    v5->m_pParams->NonRTPC.bHasChanged = 0;
LABEL_6:
    v7 = v5->m_pParams;
    if ( v7->RTPC.bHasChanged )
    {
      CAkDelayFXDSP::ComputeTailLength(&v5->m_FXState, v7->RTPC.bFeedbackEnabled, v7->RTPC.fFeedback);
      v5->m_pParams->RTPC.bHasChanged = 0;
    }
    v8 = v5->m_pParams;
    if ( v8 )
      v3 = (AkDelayFXParams *)&v8->RTPC;
    CAkDelayFXDSP::Process(&v5->m_FXState, v4, v3);
  }
}

