// File Line: 30
// RVA: 0xAF55D0
AK::IAkPlugin *__fastcall CreateMeterFX(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPlugin *result; // rax

  result = (AK::IAkPlugin *)in_pAllocator->vfptr->Malloc(in_pAllocator, 112ui64);
  if ( !result )
    return 0i64;
  result->vfptr = (AK::IAkPluginVtbl *)&CAkMeterFX::`vftable';
  result[2].vfptr = 0i64;
  result[3].vfptr = 0i64;
  result[4].vfptr = 0i64;
  result[5].vfptr = 0i64;
  LOBYTE(result[13].vfptr) = 0;
  return result;
}

// File Line: 42
// RVA: 0xAF5620
void __fastcall CAkMeterFX::CAkMeterFX(CAkMeterFX *this)
{
  this->vfptr = (AK::IAkPluginVtbl *)&CAkMeterFX::`vftable';
  this->m_pParams = 0i64;
  this->m_pCtx = 0i64;
  this->m_pAllocator = 0i64;
  this->m_pMeterManager = 0i64;
  this->m_bTerminated = 0;
}

// File Line: 50
// RVA: 0xAF5650
void __fastcall CAkMeterFX::~CAkMeterFX(CAkMeterFX *this)
{
  this->vfptr = (AK::IAkPluginVtbl *)&AK::IAkPlugin::`vftable';
}

// File Line: 67
// RVA: 0xAF5670
signed __int64 __fastcall CAkMeterFX::Init(CAkMeterFX *this, AK::IAkPluginMemAlloc *in_pAllocator, AK::IAkEffectPluginContext *in_pFXCtx, AK::IAkPluginParam *in_pParams, AkAudioFormat *in_rFormat)
{
  CAkMeterManager *v5; // rax
  unsigned __int128 v6; // cx

  this->m_pParams = (CAkMeterFXParams *)in_pParams;
  this->m_pAllocator = in_pAllocator;
  this->m_pCtx = in_pFXCtx;
  this->m_state.uSampleRate = in_rFormat->uSampleRate;
  v6 = __PAIR__((unsigned __int64)this, (unsigned __int64)in_pAllocator);
  v5 = CAkMeterManager::Instance((AK::IAkPluginMemAlloc *)v6);
  *(_QWORD *)(*((_QWORD *)&v6 + 1) + 40i64) = v5;
  if ( !v5 )
    return 2i64;
  *(_QWORD *)(*((_QWORD *)&v6 + 1) + 8i64) = 0i64;
  *(_QWORD *)&v6 = v5->m_meters.m_pLast;
  if ( (_QWORD)v6 )
    *(_QWORD *)(v6 + 8) = *((_QWORD *)&v6 + 1);
  else
    v5->m_meters.m_pFirst = (CAkMeterFX *)*((_QWORD *)&v6 + 1);
  ++v5->m_meters.m_ulNumListItems;
  v5->m_meters.m_pLast = (CAkMeterFX *)*((_QWORD *)&v6 + 1);
  *(_QWORD *)&v6 = *(_QWORD *)(*((_QWORD *)&v6 + 1) + 16i64);
  *(_DWORD *)(*((_QWORD *)&v6 + 1) + 96i64) = *(_DWORD *)(v6 + 16);
  *(_DWORD *)(*((_QWORD *)&v6 + 1) + 100i64) = *(_DWORD *)(v6 + 32);
  return 1i64;
}

// File Line: 90
// RVA: 0xAF56F0
signed __int64 __fastcall CAkMeterFX::Term(CAkMeterFX *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginMemAlloc *v2; // rdi
  CAkMeterFX *v3; // rbx

  v2 = in_pAllocator;
  v3 = this;
  if ( this->m_pMeterManager )
  {
    this->m_bTerminated = 1;
  }
  else
  {
    this->vfptr->__vecDelDtor((AK::IAkPlugin *)this, 0);
    v2->vfptr->Free(v2, v3);
  }
  return 1i64;
}

// File Line: 105
// RVA: 0xAF5750
signed __int64 __fastcall CAkMeterFX::Reset(CAkMeterFX *this)
{
  CAkMeterFXParams *v1; // rdx
  signed __int64 result; // rax

  v1 = this->m_pParams;
  this->m_state.fHoldTime = 0.0;
  this->m_state.fReleaseTarget = v1->RTPC.fMin;
  this->m_state.fLastValue = v1->RTPC.fMin;
  this->m_state.fHoldMemory[0] = v1->RTPC.fMin;
  this->m_state.fHoldMemory[1] = this->m_pParams->RTPC.fMin;
  this->m_state.fHoldMemory[2] = this->m_pParams->RTPC.fMin;
  this->m_state.fHoldMemory[3] = this->m_pParams->RTPC.fMin;
  this->m_state.fHoldMemory[4] = this->m_pParams->RTPC.fMin;
  this->m_state.fHoldMemory[5] = this->m_pParams->RTPC.fMin;
  this->m_state.fHoldMemory[6] = this->m_pParams->RTPC.fMin;
  result = 1i64;
  this->m_state.fHoldMemory[7] = this->m_pParams->RTPC.fMin;
  return result;
}

// File Line: 117
// RVA: 0xAF57D0
signed __int64 __fastcall CAkMeterFX::GetPluginInfo(CAkMeterFX *this, AkPluginInfo *out_rPluginInfo)
{
  out_rPluginInfo->eType = 3;
  *(_WORD *)&out_rPluginInfo->bIsInPlace = 1;
  return 1i64;
}

// File Line: 131
// RVA: 0xAF57F0
void __fastcall CAkMeterFX::Execute(CAkMeterFX *this, AkAudioBuffer *io_pBuffer)
{
  unsigned int v2; // er8
  AkAudioBuffer *v3; // rdi
  CAkMeterFX *i; // rbx
  CAkMeterFXParams *v5; // rax
  AkMeterFXParams *v6; // rsi
  AkMeterFXParams *v7; // rdx
  float v8; // xmm0_4
  CAkMeterFXParams *v9; // rax
  CAkMeterFXParams *v10; // rcx

  v2 = io_pBuffer->uChannelMask;
  v3 = io_pBuffer;
  for ( i = this; v2; v2 &= v2 - 1 )
    ;
  v5 = this->m_pParams;
  v6 = 0i64;
  v7 = (AkMeterFXParams *)&v5->RTPC;
  if ( !v5 )
    v7 = 0i64;
  v8 = AkMeterGetValue(v3, v7, 0i64);
  v9 = i->m_pParams;
  if ( v9 )
    v6 = (AkMeterFXParams *)&v9->RTPC;
  AkMeterApplyBallistics(v8, v3->uMaxFrames, v6, &i->m_state);
  if ( v3->eState == 17 && i->m_pParams->RTPC.fMin < i->m_state.fLastValue )
  {
    AkAudioBuffer::ZeroPadToMaxFrames(v3);
    v3->eState = 45;
  }
  v10 = i->m_pParams;
  i->m_fMin = v10->RTPC.fMin;
  i->m_uGameParamID = v10->NonRTPC.uGameParamID;
}

