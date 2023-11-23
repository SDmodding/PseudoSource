// File Line: 30
// RVA: 0xAF55D0
AK::IAkPlugin *__fastcall CreateMeterFX(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPlugin *result; // rax

  result = (AK::IAkPlugin *)in_pAllocator->vfptr->Malloc(in_pAllocator, 112i64);
  if ( !result )
    return 0i64;
  result->vfptr = (AK::IAkPluginVtbl *)&CAkMeterFX::`vftable;
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
  this->vfptr = (AK::IAkPluginVtbl *)&CAkMeterFX::`vftable;
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
  this->vfptr = (AK::IAkPluginVtbl *)&AK::IAkPlugin::`vftable;
}

// File Line: 67
// RVA: 0xAF5670
__int64 __fastcall CAkMeterFX::Init(
        CAkMeterFX *this,
        AK::IAkPluginMemAlloc *in_pAllocator,
        AK::IAkEffectPluginContext *in_pFXCtx,
        CAkMeterFXParams *in_pParams,
        AkAudioFormat *in_rFormat)
{
  CAkMeterManager *v6; // rax
  CAkMeterFX *m_pLast; // rcx
  CAkMeterFXParams *m_pParams; // rcx

  this->m_pParams = in_pParams;
  this->m_pAllocator = in_pAllocator;
  this->m_pCtx = in_pFXCtx;
  this->m_state.uSampleRate = in_rFormat->uSampleRate;
  v6 = CAkMeterManager::Instance(in_pAllocator);
  this->m_pMeterManager = v6;
  if ( !v6 )
    return 2i64;
  this->pNextItem = 0i64;
  m_pLast = v6->m_meters.m_pLast;
  if ( m_pLast )
    m_pLast->pNextItem = this;
  else
    v6->m_meters.m_pFirst = this;
  ++v6->m_meters.m_ulNumListItems;
  v6->m_meters.m_pLast = this;
  m_pParams = this->m_pParams;
  this->m_fMin = m_pParams->RTPC.fMin;
  this->m_uGameParamID = m_pParams->NonRTPC.uGameParamID;
  return 1i64;
}

// File Line: 90
// RVA: 0xAF56F0
__int64 __fastcall CAkMeterFX::Term(CAkMeterFX *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  if ( this->m_pMeterManager )
  {
    this->m_bTerminated = 1;
  }
  else
  {
    this->vfptr->__vecDelDtor(this, 0i64);
    in_pAllocator->vfptr->Free(in_pAllocator, this);
  }
  return 1i64;
}

// File Line: 105
// RVA: 0xAF5750
__int64 __fastcall CAkMeterFX::Reset(CAkMeterFX *this)
{
  CAkMeterFXParams *m_pParams; // rdx
  __int64 result; // rax

  m_pParams = this->m_pParams;
  this->m_state.fHoldTime = 0.0;
  this->m_state.fReleaseTarget = m_pParams->RTPC.fMin;
  this->m_state.fLastValue = m_pParams->RTPC.fMin;
  this->m_state.fHoldMemory[0] = m_pParams->RTPC.fMin;
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
__int64 __fastcall CAkMeterFX::GetPluginInfo(CAkMeterFX *this, AkPluginInfo *out_rPluginInfo)
{
  out_rPluginInfo->eType = AkPluginTypeEffect;
  *(_WORD *)&out_rPluginInfo->bIsInPlace = 1;
  return 1i64;
}

// File Line: 131
// RVA: 0xAF57F0
void __fastcall CAkMeterFX::Execute(CAkMeterFX *this, AkAudioBuffer *io_pBuffer)
{
  unsigned int i; // r8d
  CAkMeterFXParams *m_pParams; // rax
  AkMeterFXParams *v6; // rsi
  AkMeterFXParams *v7; // rdx
  float Value; // xmm0_4
  CAkMeterFXParams *v9; // rax
  CAkMeterFXParams *v10; // rcx

  for ( i = io_pBuffer->uChannelMask; i; i &= i - 1 )
    ;
  m_pParams = this->m_pParams;
  v6 = 0i64;
  v7 = &m_pParams->AkMeterFXParams;
  if ( !m_pParams )
    v7 = 0i64;
  Value = AkMeterGetValue(io_pBuffer, v7, 0i64);
  v9 = this->m_pParams;
  if ( v9 )
    v6 = &v9->AkMeterFXParams;
  AkMeterApplyBallistics(Value, io_pBuffer->uMaxFrames, v6, &this->m_state);
  if ( io_pBuffer->eState == AK_NoMoreData && this->m_pParams->RTPC.fMin < this->m_state.fLastValue )
  {
    AkAudioBuffer::ZeroPadToMaxFrames(io_pBuffer);
    io_pBuffer->eState = AK_DataReady;
  }
  v10 = this->m_pParams;
  this->m_fMin = v10->RTPC.fMin;
  this->m_uGameParamID = v10->NonRTPC.uGameParamID;
}

