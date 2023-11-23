// File Line: 59
// RVA: 0xA65AC0
void __fastcall AkVPLSrcCbxRec::ClearVPL(AkVPLSrcCbxRec *this)
{
  CAkVPLFilterNodeBase **m_pFilter; // rbx
  __int64 v3; // rsi
  CAkVPLFilterNodeBase *v4; // rdi
  int v5; // ebp

  m_pFilter = this->m_pFilter;
  v3 = 4i64;
  do
  {
    if ( *m_pFilter )
    {
      (*(void (__fastcall **)(CAkVPLFilterNodeBase *))(*m_pFilter)->vfptr[1].gap8)(*m_pFilter);
      v4 = *m_pFilter;
      v5 = g_LEngineDefaultPoolId;
      if ( *m_pFilter )
      {
        v4->vfptr->__vecDelDtor(*m_pFilter, 0);
        AK::MemoryMgr::Free(v5, v4);
      }
      *m_pFilter = 0i64;
    }
    ++m_pFilter;
    --v3;
  }
  while ( v3 );
  CAkVPLPitchNode::Term(&this->m_Pitch);
  CAkSrcLpFilter::Term(&this->m_LPF.m_LPF);
}

// File Line: 94
// RVA: 0xA65210
void __fastcall CAkVPLSrcCbxNodeBase::CAkVPLSrcCbxNodeBase(CAkVPLSrcCbxNodeBase *this)
{
  char v1; // al

  this->vfptr = (CAkVPLSrcCbxNodeBaseVtbl *)&CAkVPLSrcCbxNodeBase::`vftable;
  this->m_pHdrBus = 0i64;
  this->m_arVolumeData.m_pItems = 0i64;
  *(_QWORD *)&this->m_arVolumeData.m_uLength = 0i64;
  v1 = *((_BYTE *)this + 76);
  this->m_fBehavioralVolume = 0.0;
  this->m_fMaxVolumeDB = -4096.0;
  this->m_eState = NodeStateInit;
  *((_BYTE *)this + 76) = v1 & 0xC0 | 3;
  this->m_OutputDevices.m_listDeviceVolumes.m_pFirst = 0i64;
  this->m_OutputDevices.m_uNumDevices = 0;
  *(_QWORD *)&this->m_arSendValues[0].fControlValue = 0i64;
  *(_QWORD *)&this->m_arSendValues[0].auxBusID = 0i64;
  this->m_arSendValues[0].PerDeviceAuxBusses.m_pItems = 0i64;
  *(_QWORD *)&this->m_arSendValues[0].PerDeviceAuxBusses.m_uLength = 0i64;
  *(_QWORD *)&this->m_arSendValues[1].fControlValue = 0i64;
  *(_QWORD *)&this->m_arSendValues[1].auxBusID = 0i64;
  this->m_arSendValues[1].PerDeviceAuxBusses.m_pItems = 0i64;
  *(_QWORD *)&this->m_arSendValues[1].PerDeviceAuxBusses.m_uLength = 0i64;
  *(_QWORD *)&this->m_arSendValues[2].fControlValue = 0i64;
  *(_QWORD *)&this->m_arSendValues[2].auxBusID = 0i64;
  this->m_arSendValues[2].PerDeviceAuxBusses.m_pItems = 0i64;
  *(_QWORD *)&this->m_arSendValues[2].PerDeviceAuxBusses.m_uLength = 0i64;
  *(_QWORD *)&this->m_arSendValues[3].fControlValue = 0i64;
  *(_QWORD *)&this->m_arSendValues[3].auxBusID = 0i64;
  this->m_arSendValues[3].PerDeviceAuxBusses.m_pItems = 0i64;
  *(_QWORD *)&this->m_arSendValues[3].PerDeviceAuxBusses.m_uLength = 0i64;
  *(_QWORD *)&this->m_arSendValues[4].fControlValue = 0i64;
  *(_QWORD *)&this->m_arSendValues[4].auxBusID = 0i64;
  this->m_arSendValues[4].PerDeviceAuxBusses.m_pItems = 0i64;
  *(_QWORD *)&this->m_arSendValues[4].PerDeviceAuxBusses.m_uLength = 0i64;
  *(_QWORD *)&this->m_arSendValues[5].fControlValue = 0i64;
  *(_QWORD *)&this->m_arSendValues[5].auxBusID = 0i64;
  this->m_arSendValues[5].PerDeviceAuxBusses.m_pItems = 0i64;
  *(_QWORD *)&this->m_arSendValues[5].PerDeviceAuxBusses.m_uLength = 0i64;
  *(_QWORD *)&this->m_arSendValues[6].fControlValue = 0i64;
  *(_QWORD *)&this->m_arSendValues[6].auxBusID = 0i64;
  this->m_arSendValues[6].PerDeviceAuxBusses.m_pItems = 0i64;
  *(_QWORD *)&this->m_arSendValues[6].PerDeviceAuxBusses.m_uLength = 0i64;
  *(_QWORD *)&this->m_arSendValues[7].fControlValue = 0i64;
  *(_QWORD *)&this->m_arSendValues[7].auxBusID = 0i64;
  this->m_arSendValues[7].PerDeviceAuxBusses.m_pItems = 0i64;
  *(_QWORD *)&this->m_arSendValues[7].PerDeviceAuxBusses.m_uLength = 0i64;
  this->m_uNumSends = 0;
  this->m_pSources[0] = 0i64;
  this->m_pSources[1] = 0i64;
}

// File Line: 100
// RVA: 0xA653B0
void __fastcall CAkVPLSrcCbxNodeBase::~CAkVPLSrcCbxNodeBase(CAkVPLSrcCbxNodeBase *this)
{
  AkRayVolumeData *m_pItems; // rdx
  int v3; // edi
  CAkVPLSrcCbxNodeBase **p_pNextItem; // rbx
  void *v5; // rdx

  this->vfptr = (CAkVPLSrcCbxNodeBaseVtbl *)&CAkVPLSrcCbxNodeBase::`vftable;
  m_pItems = this->m_arVolumeData.m_pItems;
  if ( m_pItems )
  {
    this->m_arVolumeData.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, m_pItems);
    this->m_arVolumeData.m_pItems = 0i64;
    this->m_arVolumeData.m_ulReserved = 0;
  }
  v3 = 7;
  p_pNextItem = &this[1].pNextItem;
  do
  {
    v5 = *(p_pNextItem - 4);
    p_pNextItem -= 4;
    if ( v5 )
    {
      *((_DWORD *)p_pNextItem + 2) = 0;
      AK::MemoryMgr::Free(g_DefaultPoolId, v5);
      *p_pNextItem = 0i64;
      *((_DWORD *)p_pNextItem + 3) = 0;
    }
    --v3;
  }
  while ( v3 >= 0 );
  CAkOutputDevices::~CAkOutputDevices(&this->m_OutputDevices);
}

// File Line: 113
// RVA: 0xA673F0
void __fastcall CAkVPLSrcCbxNodeBase::Start(CAkVPLSrcCbxNodeBase *this)
{
  VPLNodeState m_eState; // eax

  m_eState = this->m_eState;
  if ( m_eState )
  {
    if ( m_eState != NodeStateStop )
      this->vfptr->Stop(this);
  }
  else
  {
    CAkVPLSrcNode::Start(this->m_pSources[0]);
    this->m_eState = NodeStatePlay;
  }
}

// File Line: 145
// RVA: 0xA66720
__int64 __fastcall CAkVPLSrcCbxNodeBase::FetchStreamedData(CAkVPLSrcCbxNodeBase *this, CAkPBI *in_pCtx)
{
  AKRESULT StreamedData; // eax
  int m_iFrameOffset; // edx
  int v7; // ecx

  StreamedData = CAkVPLSrcNode::FetchStreamedData(this->m_pSources[0]);
  if ( StreamedData == AK_FormatNotReady )
  {
    if ( in_pCtx->m_iFrameOffset < 0 && (*((_BYTE *)this->m_pSources[0] + 32) & 2) == 0 )
      *((_BYTE *)this + 76) |= 0x20u;
    return 63i64;
  }
  if ( StreamedData != AK_Success )
    return 2i64;
  m_iFrameOffset = in_pCtx->m_iFrameOffset;
  v7 = 8;
  if ( *((char *)in_pCtx + 374) >= 0 )
    v7 = 1024;
  if ( m_iFrameOffset >= (signed int)((g_settings.uContinuousPlaybackLookAhead + 1) * v7) )
    return 63i64;
  if ( m_iFrameOffset < 0 && (*((_BYTE *)this->m_pSources[0] + 32) & 2) == 0 )
    *((_BYTE *)this + 76) |= 0x20u;
  return 1i64;
}

// File Line: 203
// RVA: 0xA670B0
void __fastcall CAkVPLSrcCbxNodeBase::Pause(CAkVPLSrcCbxNodeBase *this)
{
  if ( this->m_eState == NodeStatePlay )
  {
    CAkVPLSrcNode::Pause(this->m_pSources[0]);
    this->m_eState = NodeStatePause;
  }
  else
  {
    this->vfptr->Stop(this);
  }
}

// File Line: 242
// RVA: 0xA65150
void __fastcall CAkVPLSrcCbxNode::CAkVPLSrcCbxNode(CAkVPLSrcCbxNode *this)
{
  CAkVPLSrcCbxNodeBase::CAkVPLSrcCbxNodeBase(this);
  this->m_uChannelMask = 4;
  this->vfptr = (CAkVPLSrcCbxNodeBaseVtbl *)&CAkVPLSrcCbxNode::`vftable;
  CAkVPLPitchNode::CAkVPLPitchNode(&this->m_cbxRec.m_Pitch, this);
  this->m_cbxRec.m_LPF.vfptr = (CAkVPLNodeVtbl *)&CAkVPLLPFNode::`vftable;
  this->m_cbxRec.m_LPF.m_pInput = 0i64;
  CAkSrcLpFilter::CAkSrcLpFilter(&this->m_cbxRec.m_LPF.m_LPF);
  this->m_cbxRec.m_pFilter[0] = 0i64;
  this->m_cbxRec.m_pFilter[1] = 0i64;
  this->m_cbxRec.m_pFilter[2] = 0i64;
  this->m_cbxRec.m_pFilter[3] = 0i64;
  this->m_ObstructionLPF.m_pInput = 0i64;
  this->m_ObstructionLPF.vfptr = (CAkVPLNodeVtbl *)&CAkVPLLPFNode::`vftable;
  CAkSrcLpFilter::CAkSrcLpFilter(&this->m_ObstructionLPF.m_LPF);
}

// File Line: 246
// RVA: 0xA66FB0
void __fastcall CAkVPLSrcCbxNode::Init(CAkVPLSrcCbxNode *this, unsigned int in_uSampleRate)
{
  this->m_uSampleRate = in_uSampleRate;
}

// File Line: 251
// RVA: 0xA67A40
void __fastcall CAkVPLSrcCbxNode::Term(CAkVPLSrcCbxNode *this)
{
  unsigned int i; // edi
  char *v3; // rsi
  void *v4; // rdx
  CAkVPLSrcNode *v5; // rcx
  CAkVPLSrcNode *v6; // rdi
  int v7; // esi
  CAkVPLSrcNode *v8; // rcx
  CAkVPLSrcNode *v9; // rdi
  int v10; // esi

  for ( i = 0; i < (unsigned __int8)this->m_uNumSends; ++i )
  {
    v3 = (char *)this + 32 * i;
    v4 = (void *)*((_QWORD *)v3 + 14);
    if ( v4 )
    {
      *((_DWORD *)v3 + 30) = 0;
      AK::MemoryMgr::Free(g_DefaultPoolId, v4);
      *((_QWORD *)v3 + 14) = 0i64;
      *((_DWORD *)v3 + 31) = 0;
    }
  }
  v5 = this->m_pSources[0];
  if ( v5 )
  {
    CAkVPLSrcNode::Term(v5, CtxDestroyReasonFinished);
    v6 = this->m_pSources[0];
    v7 = g_LEngineDefaultPoolId;
    if ( v6 )
    {
      v6->vfptr->__vecDelDtor(v6, 0);
      AK::MemoryMgr::Free(v7, v6);
    }
    this->m_pSources[0] = 0i64;
  }
  AkVPLSrcCbxRec::ClearVPL(&this->m_cbxRec);
  CAkSrcLpFilter::Term(&this->m_ObstructionLPF.m_LPF);
  *((_BYTE *)&this->CAkVPLSrcCbxNodeBase + 76) |= 1u;
  v8 = this->m_pSources[1];
  if ( v8 )
  {
    CAkVPLSrcNode::Term(v8, CtxDestroyReasonFinished);
    v9 = this->m_pSources[1];
    v10 = g_LEngineDefaultPoolId;
    if ( v9 )
    {
      v9->vfptr->__vecDelDtor(v9, 0);
      AK::MemoryMgr::Free(v10, v9);
    }
    this->m_pSources[1] = 0i64;
  }
}

// File Line: 278
// RVA: 0xA67880
void __fastcall CAkVPLSrcCbxNode::Stop(CAkVPLSrcCbxNode *this)
{
  CAkVPLSrcNode *v2; // rcx

  v2 = this->m_pSources[0];
  if ( v2 )
    CAkVPLSrcNode::Stop(v2);
  this->m_eState = NodeStateStop;
}

// File Line: 297
// RVA: 0xA67260
void __fastcall CAkVPLSrcCbxNode::Resume(CAkVPLSrcCbxNode *this)
{
  __int32 v2; // ecx
  float LastRate; // xmm0_4

  v2 = this->m_eState - 1;
  if ( v2 )
  {
    if ( v2 == 2 )
    {
      LastRate = CAkResampler::GetLastRate(&this->m_cbxRec.m_Pitch.m_Pitch);
      CAkVPLSrcNode::Resume(this->m_pSources[0], LastRate);
      this->m_eState = NodeStatePlay;
    }
    else
    {
      this->vfptr->Stop(this);
    }
  }
}

// File Line: 321
// RVA: 0xA67430
bool __fastcall CAkVPLSrcCbxNode::StartRun(CAkVPLSrcCbxNode *this, AkVPLState *io_state)
{
  unsigned int m_uChannelMask; // esi
  CAkPBI *m_pCtx; // rdi
  int v6; // eax
  bool v8; // dl
  bool v9; // r12
  float fOutputBusLPF; // xmm0_4
  float fTargetLPFPar; // xmm1_4
  char v12; // al
  char v13; // bp
  char v14; // r15
  char v15; // cl
  CAkVPLSrcNode *v16; // rcx
  AKRESULT StreamedData; // eax
  bool v18; // si
  int v19; // eax
  AkBelowThresholdBehavior m_eBelowThresholdBehavior; // eax
  int m_iFrameOffset; // ecx
  int v22; // eax
  bool v23; // si
  int v24; // ecx
  bool v25; // zf
  bool bIsAuxRoutable; // dl
  float out_fLPF[4]; // [rsp+40h] [rbp-48h] BYREF
  int out_bAudible; // [rsp+90h] [rbp+8h] BYREF
  bool out_bNextSilent; // [rsp+A0h] [rbp+18h] BYREF
  float out_fObsLPF; // [rsp+A8h] [rbp+20h] BYREF

  m_uChannelMask = this->m_uChannelMask;
  m_pCtx = this->m_pSources[0]->m_pCtx;
  v6 = ((__int64 (__fastcall *)(CAkPBI *))m_pCtx->CAkTransportAware::vfptr[6]._Stop)(m_pCtx);
  if ( v6 != -1 )
  {
    io_state->bStop = 1;
    if ( !v6 )
    {
      this->vfptr->Stop(this);
      return 0;
    }
  }
  io_state->uChannelMask = m_uChannelMask;
  v8 = (*((_BYTE *)&this->CAkVPLSrcCbxNodeBase + 76) & 0x10) != 0;
  io_state->bIsAuxRoutable = v8;
  CAkVPLSrcCbxNodeBase::GetVolumes(
    this,
    v8,
    m_pCtx,
    m_uChannelMask,
    &out_bNextSilent,
    (bool *)&out_bAudible,
    out_fLPF,
    &out_fObsLPF);
  v9 = out_bNextSilent;
  if ( out_bNextSilent || *((char *)m_pCtx + 374) < 0 )
  {
    v12 = *((_BYTE *)m_pCtx + 373);
    fTargetLPFPar = this->m_cbxRec.m_LPF.m_LPF.m_InternalLPFState.fTargetLPFPar;
    fOutputBusLPF = this->m_ObstructionLPF.m_LPF.m_InternalLPFState.fTargetLPFPar;
    if ( (v12 & 0x10) != 0 )
    {
      io_state->bStop = 1;
    }
    else if ( (v12 & 0x40) != 0 )
    {
      io_state->bPause = 1;
    }
  }
  else
  {
    fOutputBusLPF = out_fObsLPF;
    fTargetLPFPar = out_fLPF[0];
  }
  v13 = out_bAudible;
  v14 = 1;
  io_state->bAudible = out_bAudible;
  if ( !v13 )
  {
    m_eBelowThresholdBehavior = this->m_eBelowThresholdBehavior;
    if ( m_eBelowThresholdBehavior == AkBelowThresholdBehavior_SetAsVirtualVoice )
    {
      v14 = 0;
      if ( (*((_BYTE *)&this->CAkVPLSrcCbxNodeBase + 76) & 1) != 0 )
      {
        this->m_cbxRec.m_LPF.vfptr->VirtualOn(&this->m_cbxRec.m_LPF, this->m_eVirtualBehavior);
        if ( this->m_eVirtualBehavior != AkVirtualQueueBehavior_Resume )
          this->m_cbxRec.m_LPF.vfptr->ReleaseBuffer(&this->m_cbxRec.m_LPF);
      }
      if ( this->m_eVirtualBehavior == AkVirtualQueueBehavior_FromElapsedTime )
      {
        if ( m_pCtx->m_iFrameOffset < io_state->uMaxFrames )
        {
          out_bAudible = io_state->uMaxFrames;
          io_state->result = (__int64)this->m_cbxRec.m_LPF.vfptr->TimeSkip(
                                        &this->m_cbxRec.m_LPF,
                                        (unsigned int *)&out_bAudible);
        }
        m_iFrameOffset = m_pCtx->m_iFrameOffset;
        if ( m_iFrameOffset >= 0 )
          m_pCtx->m_iFrameOffset = m_iFrameOffset - io_state->uMaxFrames;
      }
    }
    else if ( m_eBelowThresholdBehavior == AkBelowThresholdBehavior_KillVoice )
    {
      this->vfptr->Stop(this);
      v14 = 0;
    }
    else
    {
      v13 = 1;
    }
    goto LABEL_50;
  }
  if ( fTargetLPFPar >= 0.0 )
  {
    if ( fTargetLPFPar > 100.0 )
      fTargetLPFPar = FLOAT_100_0;
  }
  else
  {
    fTargetLPFPar = 0.0;
  }
  v15 = 1;
  this->m_cbxRec.m_LPF.m_LPF.m_InternalLPFState.bTargetDirty |= fTargetLPFPar != this->m_cbxRec.m_LPF.m_LPF.m_InternalLPFState.fTargetLPFPar;
  this->m_cbxRec.m_LPF.m_LPF.m_InternalLPFState.fTargetLPFPar = fTargetLPFPar;
  if ( fOutputBusLPF <= m_pCtx->m_EffectiveParams.fOutputBusLPF )
    fOutputBusLPF = m_pCtx->m_EffectiveParams.fOutputBusLPF;
  if ( fOutputBusLPF >= 0.0 )
  {
    if ( fOutputBusLPF > 100.0 )
      fOutputBusLPF = FLOAT_100_0;
  }
  else
  {
    fOutputBusLPF = 0.0;
  }
  if ( fOutputBusLPF == this->m_ObstructionLPF.m_LPF.m_InternalLPFState.fTargetLPFPar )
    v15 = 0;
  this->m_ObstructionLPF.m_LPF.m_InternalLPFState.bTargetDirty |= v15;
  this->m_ObstructionLPF.m_LPF.m_InternalLPFState.fTargetLPFPar = fOutputBusLPF;
  v16 = this->m_pSources[0];
  if ( ((*((_BYTE *)&this->CAkVPLSrcCbxNodeBase + 76) & 1) == 0 || (*((_BYTE *)v16 + 32) & 1) == 0)
    && this->m_eBelowThresholdBehavior == AkBelowThresholdBehavior_SetAsVirtualVoice )
  {
    if ( (*((_BYTE *)v16 + 32) & 1) == 0 )
    {
      StreamedData = CAkVPLSrcNode::FetchStreamedData(v16);
      if ( StreamedData == AK_FormatNotReady )
      {
        v13 = 0;
        v14 = 0;
      }
      else if ( StreamedData != AK_Success )
      {
        this->vfptr->Stop(this);
        v13 = 0;
        v14 = 0;
      }
      goto LABEL_50;
    }
    v18 = 0;
    v19 = ((__int64 (__fastcall *)(CAkPBI *, _QWORD))m_pCtx->CAkTransportAware::vfptr[7]._Stop)(
            m_pCtx,
            (unsigned int)this->m_eVirtualBehavior)
        - 1;
    if ( v19 )
    {
      if ( v19 == 1 )
      {
LABEL_34:
        this->vfptr->Stop(this);
        return 0;
      }
    }
    else
    {
      v18 = 1;
    }
    if ( this->m_cbxRec.m_LPF.vfptr->VirtualOff(&this->m_cbxRec.m_LPF, this->m_eVirtualBehavior, v18) != AK_Success )
      goto LABEL_34;
  }
LABEL_50:
  if ( (*((_BYTE *)&this->CAkVPLSrcCbxNodeBase + 76) & 0x20) != 0 )
  {
    v22 = ((__int64 (__fastcall *)(CAkPBI *, _QWORD))m_pCtx->CAkTransportAware::vfptr[7]._Stop)(
            m_pCtx,
            (unsigned int)this->m_eVirtualBehavior);
    if ( v22 == 1 )
    {
      this->vfptr->SeekSource(this);
      *((_BYTE *)&this->CAkVPLSrcCbxNodeBase + 76) |= 2u;
    }
    else if ( v22 == 2 )
    {
      this->vfptr->Stop(this);
      v14 = 0;
    }
    *((_BYTE *)&this->CAkVPLSrcCbxNodeBase + 76) &= ~0x20u;
  }
  v23 = v14 && m_pCtx->m_iFrameOffset < io_state->uMaxFrames;
  v24 = m_pCtx->m_iFrameOffset;
  if ( v24 >= 0 )
    m_pCtx->m_iFrameOffset = v24 - io_state->uMaxFrames;
  if ( (*((_BYTE *)&this->CAkVPLSrcCbxNodeBase + 76) & 1) != 0 )
  {
    if ( !v13 )
      CAkPBI::Virtualize(m_pCtx);
  }
  else if ( v13 )
  {
    CAkPBI::Devirtualize(m_pCtx, 1);
  }
  *((_BYTE *)&this->CAkVPLSrcCbxNodeBase + 76) &= ~1u;
  *((_BYTE *)&this->CAkVPLSrcCbxNodeBase + 76) |= v13 & 1;
  if ( v23 )
  {
    v25 = this->m_cbxRec.m_Pitch.m_pPBI == 0i64;
    *((_BYTE *)&this->CAkVPLSrcCbxNodeBase + 76) ^= (*((_BYTE *)&this->CAkVPLSrcCbxNodeBase + 76) ^ (2 * v9)) & 2;
    if ( v25 )
    {
      if ( CAkVPLSrcCbxNode::AddPipeline(this) == AK_Success )
      {
        if ( (*((_BYTE *)m_pCtx + 372) & 0x20) == 0 )
          m_pCtx->CAkTransportAware::vfptr[7].~CAkTransportAware(m_pCtx);
        m_pCtx->m_Prev2DParams.prev2DParams.m_fPAN_X_2D = 101.0;
        bIsAuxRoutable = io_state->bIsAuxRoutable;
        io_state->uChannelMask = this->m_uChannelMask;
        CAkVPLSrcCbxNodeBase::GetVolumes(
          this,
          bIsAuxRoutable,
          m_pCtx,
          this->m_uChannelMask,
          &out_bNextSilent,
          (bool *)&out_bAudible,
          &out_fObsLPF,
          &out_fObsLPF);
      }
      else
      {
        this->vfptr->Stop(this);
        v23 = 0;
      }
    }
  }
  *((_BYTE *)&this->CAkVPLSrcCbxNodeBase + 76) |= 4u;
  return v23;
}

// File Line: 544
// RVA: 0xA666A0
void __fastcall CAkVPLSrcCbxNode::ConsumeBuffer(CAkVPLSrcCbxNode *this, AkVPLState *io_state)
{
  CAkVPLSrcNode *v2; // r9
  CAkPBI *m_pCtx; // rdi
  unsigned int v6; // eax
  CAkVPLSrcNode *v7; // rcx

  v2 = this->m_pSources[0];
  m_pCtx = v2->m_pCtx;
  if ( (m_pCtx->m_uRegisteredNotif & 0x10000) != 0 )
    CAkPositionRepository::UpdatePositionInfo(
      g_pPositionRepository,
      m_pCtx->m_UserParams.m_PlayingID,
      &io_state->posInfo,
      v2);
  v6 = ((__int64 (__fastcall *)(CAkPBI *))m_pCtx->CAkTransportAware::vfptr[6].~CAkTransportAware)(m_pCtx);
  if ( v6 != -1 )
  {
    if ( v6 < io_state->uValidFrames )
      io_state->uValidFrames = v6;
    io_state->bStop = 1;
  }
  v7 = this->m_pSources[1];
  if ( v7 )
  {
    if ( CAkVPLSrcNode::FetchStreamedData(v7) == AK_Fail )
      io_state->result = AK_Fail;
  }
}

// File Line: 586
// RVA: 0xA67190
void __fastcall CAkVPLSrcCbxNode::ReleaseBuffer(CAkVPLSrcCbxNode *this)
{
  this->m_cbxRec.m_LPF.vfptr->ReleaseBuffer(&this->m_cbxRec.m_LPF);
}

// File Line: 593
// RVA: 0xA67950
void __fastcall CAkVPLSrcCbxNode::SwitchToNextSrc(CAkVPLSrcCbxNode *this)
{
  CAkVPLSrcNode *v2; // rdi
  int v3; // esi
  CAkVPLSrcNode *v4; // rcx
  CAkVPLFilterNodeBase *v5; // rdx
  CAkPBI *m_pCtx; // rcx
  CAkInsertFXContext *m_pInsertFXContext; // rax
  CAkVPLFilterNodeBase *v8; // rdx
  CAkPBI *v9; // rcx
  CAkVPLFilterNodeBase *v10; // rdx
  CAkPBI *v11; // rcx
  CAkVPLFilterNodeBase *v12; // rdx
  CAkPBI *v13; // rcx

  CAkVPLSrcNode::Term(this->m_pSources[0], CtxDestroyReasonFinished);
  v2 = this->m_pSources[0];
  v3 = g_LEngineDefaultPoolId;
  if ( v2 )
  {
    v2->vfptr->__vecDelDtor(v2, 0);
    AK::MemoryMgr::Free(v3, v2);
  }
  v4 = this->m_pSources[1];
  this->m_pSources[1] = 0i64;
  this->m_pSources[0] = v4;
  CAkVPLSrcNode::Start(v4);
  v5 = this->m_cbxRec.m_pFilter[0];
  if ( v5 )
  {
    m_pCtx = this->m_pSources[0]->m_pCtx;
    m_pInsertFXContext = v5->m_pInsertFXContext;
    v5->m_pCtx = m_pCtx;
    m_pInsertFXContext->m_pContext = m_pCtx;
  }
  v8 = this->m_cbxRec.m_pFilter[1];
  if ( v8 )
  {
    v9 = this->m_pSources[0]->m_pCtx;
    v8->m_pCtx = v9;
    v8->m_pInsertFXContext->m_pContext = v9;
  }
  v10 = this->m_cbxRec.m_pFilter[2];
  if ( v10 )
  {
    v11 = this->m_pSources[0]->m_pCtx;
    v10->m_pCtx = v11;
    v10->m_pInsertFXContext->m_pContext = v11;
  }
  v12 = this->m_cbxRec.m_pFilter[3];
  if ( v12 )
  {
    v13 = this->m_pSources[0]->m_pCtx;
    v12->m_pCtx = v13;
    v12->m_pInsertFXContext->m_pContext = v13;
  }
}

// File Line: 613
// RVA: 0xA67B50
void __fastcall CAkVPLSrcCbxNode::UpdateFx(CAkVPLSrcCbxNode *this, int in_uFXIndex)
{
  __int64 v2; // rbp
  char v4; // dl
  __int64 v5; // rax
  CAkVPLLPFNode **v6; // r8
  CAkVPLLPFNode *p_m_LPF; // rsi
  __int64 v8; // rcx
  AkVPLSrcCbxRec **v9; // rax
  AkVPLSrcCbxRec *p_m_cbxRec; // r14
  CAkPBI *m_pCtx; // r15
  int v12; // eax
  int v13; // edx
  char v14; // r8
  unsigned int v15; // edx
  int v16; // ecx
  unsigned int v17; // r13d
  unsigned int v18; // edx
  AK::IAkPlugin *v19; // rbx
  AK::IAkPluginVtbl *vfptr; // rdi
  int v21; // r13d
  int v22; // ebx
  CAkVPLFilterNodeBase **v23; // r15
  int v24; // ebx
  CAkSoundBase *m_pSound; // rcx
  AK::IAkPluginVtbl *v26; // rax
  AK::IAkPluginVtbl *v27; // rax
  int v28; // ebx
  char v29; // al
  int v30; // ebp
  AK::IAkPlugin *out_pEffect; // [rsp+30h] [rbp-58h] BYREF
  CAkPBI *v32; // [rsp+38h] [rbp-50h] BYREF
  unsigned int *v33; // [rsp+40h] [rbp-48h] BYREF
  char v34; // [rsp+48h] [rbp-40h]
  char v35; // [rsp+98h] [rbp+10h]
  unsigned int v36; // [rsp+A0h] [rbp+18h]
  AkAudioFormat m_sMediaFormat; // [rsp+A8h] [rbp+20h] BYREF

  v2 = in_uFXIndex;
  if ( in_uFXIndex != -1 )
  {
    v4 = 0;
    v36 = v2 + 1;
    v5 = (int)v2 + 1;
    v35 = 0;
    if ( v5 >= 4 )
    {
LABEL_6:
      p_m_LPF = &this->m_cbxRec.m_LPF;
    }
    else
    {
      v6 = (CAkVPLLPFNode **)&this->m_cbxRec.m_pFilter[v5];
      while ( 1 )
      {
        p_m_LPF = *v6;
        if ( *v6 )
          break;
        ++v5;
        ++v6;
        if ( v5 >= 4 )
          goto LABEL_6;
      }
      v35 = 1;
    }
    v8 = (int)v2 - 1;
    if ( (int)v2 - 1 < 0 )
    {
LABEL_11:
      p_m_cbxRec = &this->m_cbxRec;
    }
    else
    {
      v9 = (AkVPLSrcCbxRec **)(&this->m_cbxRec.m_LPF.m_LPF.m_InternalLPFState.uNumInterBlocks + 4 * (int)v2);
      while ( 1 )
      {
        p_m_cbxRec = *v9;
        if ( *v9 )
          break;
        --v9;
        if ( --v8 < 0 )
          goto LABEL_11;
      }
      v4 = 1;
    }
    m_pCtx = this->m_pSources[0]->m_pCtx;
    v32 = m_pCtx;
    m_sMediaFormat = m_pCtx->m_sMediaFormat;
    if ( v4 )
    {
      v12 = ((__int64 (__fastcall *)(AkVPLSrcCbxRec *))p_m_cbxRec->m_Pitch.vfptr[1].GetPitch)(p_m_cbxRec);
      v13 = (*((_DWORD *)&m_sMediaFormat + 1) ^ v12) & 0x3FFFF ^ *((_DWORD *)&m_sMediaFormat + 1);
    }
    else
    {
      v13 = *((_DWORD *)&m_sMediaFormat + 1);
    }
    v14 = 0;
    v15 = v13 & 0xFF03FFFF | 0x800000;
    v16 = v15 & 0x3FFFF;
    if ( (v15 & 0x3FFFF) != 0 )
    {
      do
      {
        ++v14;
        v16 &= v16 - 1;
      }
      while ( v16 );
    }
    v17 = v15;
    v18 = v15 & 0xE0FFFFFF;
    m_sMediaFormat.uSampleRate = this->m_uSampleRate;
    v19 = (AK::IAkPlugin *)&this->m_cbxRec.m_pFilter[(unsigned int)v2];
    out_pEffect = v19;
    vfptr = v19->vfptr;
    *((_DWORD *)&m_sMediaFormat + 1) = (v18 | (((v14 * ((v17 >> 18) & 0x3F)) & 0xF8 | 0xFFFFFC00) << 21)) & 0x9FFFFFFF | 0x20000000;
    v21 = v18 & 0x3FFFF;
    if ( vfptr )
    {
      v22 = v2;
      v21 = (*((__int64 (__fastcall **)(AK::IAkPluginVtbl *))vfptr->__vecDelDtor + 16))(vfptr);
      if ( (int)v2 < 4 )
      {
        v23 = &this->m_cbxRec.m_pFilter[v2];
        do
        {
          if ( *v23
            && ((unsigned __int8 (__fastcall *)(CAkVPLFilterNodeBase *))(*v23)->vfptr[1].TimeSkip)(*v23)
            && v22 != (_DWORD)v2 )
          {
            break;
          }
          ++v22;
          ++v23;
        }
        while ( v22 < 4 );
        m_pCtx = v32;
      }
      CAkVPLNode::Disconnect(p_m_LPF);
      (*((void (__fastcall **)(AK::IAkPluginVtbl *))vfptr->__vecDelDtor + 10))(vfptr);
      v24 = g_LEngineDefaultPoolId;
      (*(void (__fastcall **)(AK::IAkPluginVtbl *, _QWORD))vfptr->__vecDelDtor)(vfptr, 0i64);
      AK::MemoryMgr::Free(v24, vfptr);
      v19 = out_pEffect;
      vfptr = 0i64;
      out_pEffect->vfptr = 0i64;
    }
    m_pSound = m_pCtx->m_pSound;
    v33 = 0i64;
    ((void (__fastcall *)(CAkSoundBase *, _QWORD, unsigned int **, CAkRegisteredObj *))m_pSound->vfptr[14].__vecDelDtor)(
      m_pSound,
      (unsigned int)v2,
      &v33,
      m_pCtx->m_pGameObj);
    if ( v33 )
    {
      out_pEffect = 0i64;
      if ( (unsigned int)CAkEffectsMgr::Alloc(&AkFXMemAlloc::m_instanceLower, v33[6], &out_pEffect) != 1 )
        goto LABEL_48;
      out_pEffect->vfptr->GetPluginInfo(out_pEffect, (AkPluginInfo *)&v32);
      if ( BYTE5(v32) )
      {
        out_pEffect->vfptr->Term(out_pEffect, &AkFXMemAlloc::m_instanceLower);
        goto LABEL_48;
      }
      if ( BYTE4(v32) )
      {
        v26 = (AK::IAkPluginVtbl *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 0x50ui64);
        vfptr = v26;
        if ( !v26 )
          goto LABEL_48;
        v26->Term = 0i64;
        v26->__vecDelDtor = (void *(__fastcall *)(AK::IAkPlugin *, unsigned int))&CAkVPLFilterNode::`vftable;
      }
      else
      {
        v27 = (AK::IAkPluginVtbl *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 0xD8ui64);
        vfptr = v27;
        if ( !v27 )
          goto LABEL_48;
        v27->Term = 0i64;
        v27->__vecDelDtor = (void *(__fastcall *)(AK::IAkPlugin *, unsigned int))&CAkVPLFilterNodeOutOfPlace::`vftable;
        v27[1].GetPluginInfo = 0i64;
        LOWORD(v27[2].__vecDelDtor) = 0;
        v27[2].Term = 0i64;
        v27[2].SupportMediaRelocation = 0i64;
        LOWORD(v27[3].Term) = 0;
        v27[3].Reset = 0i64;
      }
      if ( !vfptr )
        goto LABEL_48;
      if ( (*((unsigned int (__fastcall **)(AK::IAkPluginVtbl *, AK::IAkPlugin *, unsigned int **, _QWORD, CAkPBI *, AkAudioFormat *))vfptr->__vecDelDtor
            + 9))(
             vfptr,
             out_pEffect,
             &v33,
             (unsigned int)v2,
             m_pCtx,
             &m_sMediaFormat) != 1 )
      {
        (*((void (__fastcall **)(AK::IAkPluginVtbl *))vfptr->__vecDelDtor + 10))(vfptr);
        v28 = g_LEngineDefaultPoolId;
        (*(void (__fastcall **)(AK::IAkPluginVtbl *, _QWORD))vfptr->__vecDelDtor)(vfptr, 0i64);
        AK::MemoryMgr::Free(v28, vfptr);
        goto LABEL_48;
      }
      v29 = v34;
      v19->vfptr = vfptr;
      BYTE5(vfptr->RelocateMedia) = v29;
      (*((void (__fastcall **)(AK::IAkPluginVtbl *, AkVPLSrcCbxRec *))vfptr->__vecDelDtor + 8))(vfptr, p_m_cbxRec);
      v30 = (*((__int64 (__fastcall **)(AK::IAkPluginVtbl *))vfptr->__vecDelDtor + 16))(vfptr);
    }
    else
    {
      v30 = *((_DWORD *)&m_sMediaFormat + 1) & 0x3FFFF;
    }
    if ( v30 != v21 )
    {
      if ( v35 )
      {
        this->vfptr->UpdateFx(this, v36);
        goto LABEL_49;
      }
      CAkSrcLpFilter::Term(&this->m_cbxRec.m_LPF.m_LPF);
      CAkSrcLpFilter::Init(&this->m_cbxRec.m_LPF.m_LPF, v30, 0);
      CAkSrcLpFilter::Term(&this->m_ObstructionLPF.m_LPF);
      CAkSrcLpFilter::Init(&this->m_ObstructionLPF.m_LPF, v30, 0);
      this->m_uChannelMask = v30;
      CAkPBI::InvalidateFeedbackParameters(m_pCtx);
    }
    if ( vfptr )
      p_m_cbxRec = (AkVPLSrcCbxRec *)vfptr;
LABEL_48:
    p_m_LPF->vfptr->Connect(p_m_LPF, &p_m_cbxRec->m_Pitch);
LABEL_49:
    if ( v33 )
      (*(void (__fastcall **)(unsigned int *))(*(_QWORD *)v33 + 16i64))(v33);
  }
}

// File Line: 797
// RVA: 0xA67370
void __fastcall CAkVPLSrcCbxNode::SetFxBypass(CAkVPLSrcCbxNode *this, char in_bitsFXBypass, char in_uTargetMask)
{
  CAkVPLFilterNodeBase *v3; // r9
  CAkVPLFilterNodeBase *v4; // r9
  CAkVPLFilterNodeBase *v5; // r9
  CAkVPLFilterNodeBase *v6; // rax

  v3 = this->m_cbxRec.m_pFilter[0];
  if ( v3 && (in_uTargetMask & 1) != 0 )
    v3->m_bBypassed = in_bitsFXBypass & 1;
  v4 = this->m_cbxRec.m_pFilter[1];
  if ( v4 && (in_uTargetMask & 2) != 0 )
    v4->m_bBypassed = (in_bitsFXBypass & 2) != 0;
  v5 = this->m_cbxRec.m_pFilter[2];
  if ( v5 && (in_uTargetMask & 4) != 0 )
    v5->m_bBypassed = (in_bitsFXBypass & 4) != 0;
  v6 = this->m_cbxRec.m_pFilter[3];
  if ( v6 )
  {
    if ( (in_uTargetMask & 8) != 0 )
      v6->m_bBypassed = (in_bitsFXBypass & 8) != 0;
  }
}

// File Line: 807
// RVA: 0xA67160
void __fastcall CAkVPLSrcCbxNode::RefreshBypassFx(CAkVPLSrcCbxNode *this)
{
  unsigned int i; // ebx

  for ( i = 0; i < 4; ++i )
    this->vfptr->RefreshBypassFx(this, i);
}

// File Line: 815
// RVA: 0xA670F0
void __fastcall CAkVPLSrcCbxNode::RefreshBypassFx(CAkVPLSrcCbxNode *this, __int64 in_uFXIndex)
{
  CAkVPLSrcNode *v2; // rax
  CAkPBI *m_pCtx; // r9
  CAkVPLFilterNodeBase *v4; // rbx
  CAkSoundBase *m_pSound; // r10
  CAkIndexableVtbl *vfptr; // rax
  CAkRegisteredObj *m_pGameObj; // r9
  __int64 v8; // rcx
  __int64 v9; // [rsp+20h] [rbp-18h] BYREF
  bool v10; // [rsp+28h] [rbp-10h]

  v2 = this->m_pSources[0];
  if ( v2 )
  {
    m_pCtx = v2->m_pCtx;
    v4 = this->m_cbxRec.m_pFilter[(unsigned int)in_uFXIndex];
    m_pSound = m_pCtx->m_pSound;
    if ( v4 )
    {
      vfptr = m_pSound->vfptr;
      m_pGameObj = m_pCtx->m_pGameObj;
      v9 = 0i64;
      ((void (__fastcall *)(CAkSoundBase *, __int64, __int64 *, CAkRegisteredObj *))vfptr[14].__vecDelDtor)(
        m_pSound,
        in_uFXIndex,
        &v9,
        m_pGameObj);
      v8 = v9;
      v4->m_bBypassed = v10;
      if ( v8 )
        (*(void (__fastcall **)(__int64))(*(_QWORD *)v8 + 16i64))(v8);
    }
  }
}

// File Line: 837
// RVA: 0xA65620
AKRESULT __fastcall CAkVPLSrcCbxNode::AddPipeline(CAkVPLSrcCbxNode *this)
{
  unsigned int m_uSampleRate; // r9d
  AkVPLSrcCbxRec *p_m_cbxRec; // rbx
  CAkPBI *m_pCtx; // r13
  CAkSoundBase *m_pSound; // rdi
  unsigned int v6; // eax
  unsigned __int8 v7; // si
  CAkVPLFilterNodeBase **m_pFilter; // r15
  unsigned int v9; // r14d
  CAkIndexableVtbl *vfptr; // rax
  CAkRegisteredObj *m_pGameObj; // r9
  CAkVPLFilterNodeBase *v12; // rax
  CAkVPLFilterNodeBase *v13; // rbx
  int v14; // edi
  __int64 v15; // rcx
  __int64 v16; // rax
  AKRESULT result; // eax
  unsigned int m_uChannelMask; // edx
  AKRESULT v19; // ebx
  __int64 v20[2]; // [rsp+30h] [rbp-39h] BYREF
  __int64 v21[16]; // [rsp+40h] [rbp-29h]
  AK::IAkPlugin *out_pEffect; // [rsp+D0h] [rbp+67h] BYREF
  AkAudioFormat io_pFormat; // [rsp+D8h] [rbp+6Fh] BYREF
  char v24; // [rsp+E0h] [rbp+77h] BYREF
  char v25; // [rsp+E4h] [rbp+7Bh]
  char v26; // [rsp+E5h] [rbp+7Ch]
  CAkSoundBase *v27; // [rsp+E8h] [rbp+7Fh]

  m_uSampleRate = this->m_uSampleRate;
  p_m_cbxRec = &this->m_cbxRec;
  m_pCtx = this->m_pSources[0]->m_pCtx;
  v21[0] = (__int64)this->m_pSources[0];
  io_pFormat = m_pCtx->m_sMediaFormat;
  m_pSound = m_pCtx->m_pSound;
  v27 = m_pSound;
  CAkVPLPitchNode::Init(&this->m_cbxRec.m_Pitch, &io_pFormat, m_pCtx, m_uSampleRate);
  v6 = this->m_uSampleRate;
  v21[1] = (__int64)p_m_cbxRec;
  io_pFormat.uSampleRate = v6;
  v7 = 2;
  m_pFilter = this->m_cbxRec.m_pFilter;
  v9 = 0;
  while ( 1 )
  {
    vfptr = m_pSound->vfptr;
    m_pGameObj = m_pCtx->m_pGameObj;
    v20[0] = 0i64;
    ((void (__fastcall *)(CAkSoundBase *, _QWORD, __int64 *, CAkRegisteredObj *))vfptr[14].__vecDelDtor)(
      m_pSound,
      v9,
      v20,
      m_pGameObj);
    if ( v20[0] )
      break;
LABEL_20:
    ++v9;
    ++m_pFilter;
    if ( v9 >= 4 )
    {
      this->m_uChannelMask = *((_DWORD *)&io_pFormat + 1) & 0x3FFFF;
      CAkPBI::InvalidateFeedbackParameters(m_pCtx);
      result = CAkSrcLpFilter::Init(&this->m_cbxRec.m_LPF.m_LPF, this->m_uChannelMask, 0);
      if ( result == AK_Success )
      {
        m_uChannelMask = this->m_uChannelMask;
        v21[v7] = (__int64)&this->m_cbxRec.m_LPF;
        result = CAkSrcLpFilter::Init(&this->m_ObstructionLPF.m_LPF, m_uChannelMask, 0);
        v19 = result;
        if ( result == AK_Success )
        {
          for ( ; v7; --v7 )
            (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v21[v7] + 64i64))(v21[v7], v20[v7 + 1]);
          this->vfptr->RefreshBypassFx(this);
          return v19;
        }
      }
      return result;
    }
  }
  out_pEffect = 0i64;
  if ( (unsigned int)CAkEffectsMgr::Alloc(&AkFXMemAlloc::m_instanceLower, *(_DWORD *)(v20[0] + 24), &out_pEffect) != 1 )
  {
LABEL_4:
    if ( v20[0] )
    {
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v20[0] + 16i64))(v20[0]);
      v20[0] = 0i64;
    }
    goto LABEL_20;
  }
  out_pEffect->vfptr->GetPluginInfo(out_pEffect, (AkPluginInfo *)&v24);
  if ( v26 )
  {
    out_pEffect->vfptr->Term(out_pEffect, &AkFXMemAlloc::m_instanceLower);
    goto LABEL_4;
  }
  if ( v25 )
  {
    v12 = (CAkVPLFilterNodeBase *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 0x50ui64);
    v13 = v12;
    if ( !v12 )
      goto LABEL_27;
    v12->m_pInput = 0i64;
    v12->vfptr = (CAkVPLNodeVtbl *)&CAkVPLFilterNode::`vftable;
  }
  else
  {
    v13 = (CAkVPLFilterNodeBase *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 0xD8ui64);
    if ( !v13 )
      goto LABEL_27;
    v13->vfptr = (CAkVPLNodeVtbl *)&CAkVPLFilterNodeOutOfPlace::`vftable;
    v13->m_pInput = 0i64;
    v13[1].m_pCtx = 0i64;
    LOWORD(v13[1].m_FXID) = 0;
    *(_QWORD *)&v13[1].m_uFXIndex = 0i64;
    v13[2].m_pCtx = 0i64;
    LOWORD(v13[2].m_FXID) = 0;
    *(_QWORD *)&v13[2].m_uFXIndex = 0i64;
  }
  if ( v13 )
  {
    if ( ((unsigned int (__fastcall *)(CAkVPLFilterNodeBase *, AK::IAkPlugin *, __int64 *, _QWORD, CAkPBI *, AkAudioFormat *))v13->vfptr[1].__vecDelDtor)(
           v13,
           out_pEffect,
           v20,
           v9,
           m_pCtx,
           &io_pFormat) == 1 )
    {
      v15 = v20[0];
      v16 = v7++;
      *m_pFilter = v13;
      v21[v16] = (__int64)v13;
      if ( v15 )
      {
        (*(void (__fastcall **)(__int64))(*(_QWORD *)v15 + 16i64))(v15);
        v20[0] = 0i64;
      }
    }
    else
    {
      (*(void (__fastcall **)(CAkVPLFilterNodeBase *))v13->vfptr[1].gap8)(v13);
      v14 = g_LEngineDefaultPoolId;
      v13->vfptr->__vecDelDtor(v13, 0);
      AK::MemoryMgr::Free(v14, v13);
      if ( v20[0] )
      {
        (*(void (__fastcall **)(__int64))(*(_QWORD *)v20[0] + 16i64))(v20[0]);
        m_pSound = v27;
        v20[0] = 0i64;
      }
      else
      {
        m_pSound = v27;
      }
    }
    goto LABEL_20;
  }
LABEL_27:
  out_pEffect->vfptr->Term(out_pEffect, &AkFXMemAlloc::m_instanceLower);
  if ( v20[0] )
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v20[0] + 16i64))(v20[0]);
  return 2;
}

// File Line: 985
// RVA: 0xA65F20
void __fastcall CAkVPLSrcCbxNodeBase::ComputeSpeakerMatrix2D(
        CAkVPLSrcCbxNodeBase *this,
        bool in_bIsAuxRoutable,
        CAkPBI *in_pContext,
        AkArray<AkRayVolumeData,AkRayVolumeData const &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *in_arVolumeData,
        unsigned int in_uInputConfig,
        float in_fBehavioralVolume)
{
  AkDeviceInfo *m_pFirst; // rax
  AkRayVolumeData *m_pItems; // r14
  float LPF; // xmm0_4
  AkFeedbackParams *m_pFeedbackInfo; // rcx
  char v13; // al
  int v14; // eax
  unsigned int v15; // esi
  unsigned int v16; // ecx
  AkDeviceInfo *v17; // rbx
  unsigned int v18; // r12d
  float m_fPAN_X_2D; // xmm8_4
  float v20; // xmm8_4
  float v21; // xmm7_4
  __m128 m_fCenterPCT_low; // xmm6
  unsigned int in_uOutputConfig; // eax
  __m128 v24; // xmm2
  AkSIMDSpeakerVolumes *p_out_pVolumes; // rax
  AkAudioMix *mxDirect; // rcx
  __int64 v27; // rdx
  __m128 v28; // xmm2
  __m128 v29; // xmm0
  __m128 v30; // xmm1
  unsigned __int64 v31; // rax
  AkSIMDSpeakerVolumes out_pVolumes; // [rsp+40h] [rbp-1B8h] BYREF

  m_pFirst = this->m_OutputDevices.m_listDeviceVolumes.m_pFirst;
  m_pItems = in_arVolumeData->m_pItems;
  if ( m_pFirst )
  {
    LPF = in_pContext->m_EffectiveParams.LPF;
    do
    {
      m_pFirst->fLPF = LPF;
      m_pFirst = m_pFirst->pNextLightItem;
    }
    while ( m_pFirst );
  }
  if ( (*((_BYTE *)in_pContext + 374) & 0x40) == 0 )
    CAkPBI::ValidateFeedbackParameters(in_pContext);
  m_pFeedbackInfo = in_pContext->m_pFeedbackInfo;
  if ( in_pContext->m_BasePosParams.m_fPAN_X_2D != in_pContext->m_Prev2DParams.prev2DParams.m_fPAN_X_2D
    || in_pContext->m_BasePosParams.m_fPAN_Y_2D != in_pContext->m_Prev2DParams.prev2DParams.m_fPAN_Y_2D
    || in_pContext->m_BasePosParams.m_fCenterPCT != in_pContext->m_Prev2DParams.prev2DParams.m_fCenterPCT
    || in_pContext->m_Prev2DParams.prev2DParams.bIsPannerEnabled != in_pContext->m_BasePosParams.bIsPannerEnabled
    || (*((_BYTE *)in_pContext + 371) & 0x10) != 0
    || in_fBehavioralVolume != in_pContext->m_Prev2DParams.prevVolume
    || m_pItems->fDryMixGain != in_pContext->m_Prev2DParams.prevDryLevel
    || m_pFeedbackInfo && m_pFeedbackInfo->m_NewVolume != in_pContext->m_Prev2DParams.prevMotionVol
    || (v13 = *((_BYTE *)this + 76), (v13 & 2) != 0)
    || (in_pContext->m_uRegisteredNotif & 0x10) != 0
    || (v13 & 0x40) != 0 )
  {
    in_pContext->m_Prev2DParams.prev2DParams.m_fPAN_X_2D = in_pContext->m_BasePosParams.m_fPAN_X_2D;
    in_pContext->m_Prev2DParams.prev2DParams.m_fPAN_Y_2D = in_pContext->m_BasePosParams.m_fPAN_Y_2D;
    in_pContext->m_Prev2DParams.prev2DParams.m_fCenterPCT = in_pContext->m_BasePosParams.m_fCenterPCT;
    v14 = *(_DWORD *)&in_pContext->m_BasePosParams.bIsPannerEnabled;
    in_pContext->m_Prev2DParams.prevVolume = in_fBehavioralVolume;
    *(_DWORD *)&in_pContext->m_Prev2DParams.prev2DParams.bIsPannerEnabled = v14;
    v15 = 0;
    v16 = in_uInputConfig;
    for ( in_pContext->m_Prev2DParams.prevDryLevel = m_pItems->fDryMixGain; v16; v16 &= v16 - 1 )
      ++v15;
    v17 = this->m_OutputDevices.m_listDeviceVolumes.m_pFirst;
    v18 = v15 - 1;
    if ( (in_uInputConfig & 8) != 0 )
      --v15;
    for ( ; v17; v17 = v17->pNextLightItem )
    {
      m_fPAN_X_2D = in_pContext->m_BasePosParams.m_fPAN_X_2D;
      v17->fLPF = in_pContext->m_EffectiveParams.LPF;
      v20 = (float)(m_fPAN_X_2D + 100.0) * 0.0049999999;
      if ( v20 >= 0.0 )
      {
        if ( v20 > 1.0 )
          v20 = *(float *)&FLOAT_1_0;
      }
      else
      {
        v20 = 0.0;
      }
      v21 = (float)(in_pContext->m_BasePosParams.m_fPAN_Y_2D + 100.0) * 0.0049999999;
      if ( v21 >= 0.0 )
      {
        if ( v21 > 1.0 )
          v21 = *(float *)&FLOAT_1_0;
      }
      else
      {
        v21 = 0.0;
      }
      m_fCenterPCT_low = (__m128)LODWORD(in_pContext->m_BasePosParams.m_fCenterPCT);
      m_fCenterPCT_low.m128_f32[0] = m_fCenterPCT_low.m128_f32[0] * 0.0099999998;
      in_uOutputConfig = AkDeviceInfo::GetOutputConfig(v17);
      v24 = m_fCenterPCT_low;
      CAkSpeakerPan::GetSpeakerVolumes2DPan(
        v20,
        v21,
        m_fCenterPCT_low.m128_f32[0],
        in_pContext->m_BasePosParams.bIsPannerEnabled,
        in_uInputConfig,
        in_uOutputConfig,
        &out_pVolumes);
      if ( v15 )
      {
        v24.m128_f32[0] = in_fBehavioralVolume;
        p_out_pVolumes = &out_pVolumes;
        mxDirect = v17->mxDirect;
        v27 = v15;
        v28 = _mm_shuffle_ps(v24, v24, 0);
        do
        {
          v29 = p_out_pVolumes->vector[0];
          v30 = p_out_pVolumes->vector[1];
          ++mxDirect;
          ++p_out_pVolumes;
          mxDirect[-1].Next.vector[0] = _mm_mul_ps(v29, v28);
          mxDirect[-1].Next.vector[1] = _mm_mul_ps(v30, v28);
          --v27;
        }
        while ( v27 );
      }
      if ( (in_uInputConfig & 8) != 0 )
      {
        v31 = (unsigned __int64)v18 << 6;
        *(__m128 *)((char *)v17->mxDirect[0].Next.vector + v31) = 0i64;
        *(_OWORD *)((char *)&v17->mxDirect[0].Next.aVolumes[4] + v31) = 0i64;
        *(float *)((char *)&v17->mxDirect[0].Next.vector[1].m128_f32[3] + v31) = in_fBehavioralVolume;
      }
      v17->mxAttenuations.dry.fNext = m_pItems->fDryMixGain;
      if ( in_bIsAuxRoutable )
      {
        v17->mxAttenuations.gameDef.fNext = 1.0;
        v17->mxAttenuations.userDef.fNext = 1.0;
      }
    }
  }
}

// File Line: 1068
// RVA: 0xA66300
char __fastcall CAkVPLSrcCbxNodeBase::ComputeVolumeRays(CAkVPLSrcCbxNodeBase *this)
{
  CAkPBI *m_pCtx; // rdi
  bool IsAuxRoutable; // al
  bool v4; // r14
  float v5; // xmm7_4
  float v6; // xmm6_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm1_4
  unsigned __int8 v10; // al
  CAkRegisteredObj *m_pGameObj; // rdx
  float m_fDryLevelValue; // xmm8_4
  float v13; // xmm0_4
  int v14; // esi
  __int128 *v15; // rbx
  int i; // edi
  void *v17; // rdx
  AkAuxSendValueEx io_paEnvVal; // [rsp+30h] [rbp-D0h] BYREF
  __int64 v20; // [rsp+60h] [rbp-A0h]
  __int64 v21; // [rsp+68h] [rbp-98h]
  __int64 v22; // [rsp+80h] [rbp-80h]
  __int64 v23; // [rsp+88h] [rbp-78h]
  __int64 v24; // [rsp+A0h] [rbp-60h]
  __int64 v25; // [rsp+A8h] [rbp-58h]
  __int64 v26; // [rsp+C0h] [rbp-40h]
  __int64 v27; // [rsp+C8h] [rbp-38h]
  __int64 v28; // [rsp+E0h] [rbp-20h]
  __int64 v29; // [rsp+E8h] [rbp-18h]
  __int64 v30; // [rsp+100h] [rbp+0h]
  __int64 v31; // [rsp+108h] [rbp+8h]
  __int64 v32; // [rsp+120h] [rbp+20h]
  __int64 v33; // [rsp+128h] [rbp+28h]
  __int128 v34; // [rsp+140h] [rbp+40h] BYREF

  m_pCtx = this->m_pSources[0]->m_pCtx;
  if ( (*((_BYTE *)m_pCtx + 372) & 0x20) == 0 )
    m_pCtx->CAkTransportAware::vfptr[7].~CAkTransportAware(m_pCtx);
  IsAuxRoutable = CAkPBI::IsAuxRoutable(m_pCtx);
  *((_BYTE *)this + 76) &= ~0x10u;
  v4 = IsAuxRoutable;
  *((_BYTE *)this + 76) |= 16 * IsAuxRoutable;
  if ( (*((_BYTE *)m_pCtx + 375) & 0x10) != 0 )
  {
    this->m_arVolumeData.m_uLength = 0;
    CAkPBI::VirtualPositionUpdate(m_pCtx);
  }
  else
  {
    v5 = FLOAT_2_7866352e7;
    v6 = 0.0;
    v7 = (float)(CAkPBI::GetVoiceVolumedB(m_pCtx) + m_pCtx->m_EffectiveParams.Volume) * 0.050000001;
    if ( v7 >= -37.0 )
    {
      if ( (`AkMath::FastPow10::`4::`local static guard & 1) != 0 )
      {
        v9 = *(float *)&`AkMath::FastPow10::`4::SCALE;
      }
      else
      {
        v9 = FLOAT_2_7866352e7;
        `AkMath::FastPow10::`4::`local static guard |= 1u;
        `AkMath::FastPow10::`4::SCALE = LODWORD(FLOAT_2_7866352e7);
      }
      v8 = (float)((float)((float)((float)(COERCE_FLOAT(((int)(float)((float)(v9 * v7) + 1065353200.0) & 0x7FFFFF) + 1065353216)
                                         * 0.32518977)
                                 + 0.020805772)
                         * COERCE_FLOAT(((int)(float)((float)(v9 * v7) + 1065353200.0) & 0x7FFFFF) + 1065353216))
                 + 0.65304345)
         * COERCE_FLOAT((int)(float)((float)(v9 * v7) + 1065353200.0) & 0xFF800000);
    }
    else
    {
      v8 = 0.0;
    }
    v10 = *((_BYTE *)m_pCtx + 371);
    this->m_fBehavioralVolume = v8 * m_pCtx->m_EffectiveParams.fFadeRatio;
    if ( (v10 & 3) != 0 )
    {
      v14 = (v10 >> 2) & 3;
      if ( CAkPBI::ComputeVolumeData3D(m_pCtx, (AkPositionSourceType)v14, &this->m_arVolumeData) )
        CAkListener::Get3DVolumes((AkPositionSourceType)v14, v4, m_pCtx, &this->m_arVolumeData);
    }
    else
    {
      if ( !this->m_arVolumeData.m_uLength
        && !AkArray<AkRayVolumeData,AkRayVolumeData const &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::AddLast(&this->m_arVolumeData) )
      {
        return 0;
      }
      m_pGameObj = m_pCtx->m_pGameObj;
      this->m_arVolumeData.m_pItems->m_uListenerMask = m_pGameObj->m_PosKeep.m_uListenerMask;
      if ( v4 )
        m_fDryLevelValue = m_pGameObj->m_fDryLevelValue;
      else
        m_fDryLevelValue = *(float *)&FLOAT_1_0;
      v13 = CAkPBI::GetOutputBusVolumeValuedB(m_pCtx) * 0.050000001;
      if ( v13 >= -37.0 )
      {
        if ( (`AkMath::FastPow10::`4::`local static guard & 1) != 0 )
        {
          v5 = *(float *)&`AkMath::FastPow10::`4::SCALE;
        }
        else
        {
          `AkMath::FastPow10::`4::SCALE = LODWORD(FLOAT_2_7866352e7);
          `AkMath::FastPow10::`4::`local static guard |= 1u;
        }
        v6 = (float)((float)((float)((float)(COERCE_FLOAT(((int)(float)((float)(v13 * v5) + 1065353200.0) & 0x7FFFFF) + 1065353216)
                                           * 0.32518977)
                                   + 0.020805772)
                           * COERCE_FLOAT(((int)(float)((float)(v13 * v5) + 1065353200.0) & 0x7FFFFF) + 1065353216))
                   + 0.65304345)
           * COERCE_FLOAT((int)(float)((float)(v13 * v5) + 1065353200.0) & 0xFF800000);
      }
      this->m_arVolumeData.m_pItems->fDryMixGain = v6 * m_fDryLevelValue;
    }
  }
  if ( !v4 || (*((_BYTE *)this + 76) & 1) == 0 )
  {
    this->m_uNumSends = 0;
    return 0;
  }
  io_paEnvVal.PerDeviceAuxBusses.m_pItems = 0i64;
  *(_QWORD *)&io_paEnvVal.PerDeviceAuxBusses.m_uLength = 0i64;
  v20 = 0i64;
  v21 = 0i64;
  v22 = 0i64;
  v23 = 0i64;
  v24 = 0i64;
  v25 = 0i64;
  v26 = 0i64;
  v27 = 0i64;
  v28 = 0i64;
  v29 = 0i64;
  v30 = 0i64;
  v31 = 0i64;
  v32 = 0i64;
  v33 = 0i64;
  CAkPBI::GetAuxSendsValues(m_pCtx, &io_paEnvVal);
  MergeLastAndCurrentValues(&io_paEnvVal, this->m_arSendValues, (*((_BYTE *)this + 76) & 8) != 0, &this->m_uNumSends);
  *((_BYTE *)this + 76) |= 8u;
  v15 = &v34;
  for ( i = 7; i >= 0; --i )
  {
    v17 = (void *)*((_QWORD *)v15 - 4);
    v15 -= 2;
    if ( v17 )
    {
      *((_DWORD *)v15 + 2) = 0;
      AK::MemoryMgr::Free(g_DefaultPoolId, v17);
      *(_QWORD *)v15 = 0i64;
      *((_DWORD *)v15 + 3) = 0;
    }
  }
  return 1;
}

// File Line: 1140
// RVA: 0xA65B60
void __fastcall CAkVPLSrcCbxNodeBase::ComputeMaxVolume(CAkVPLSrcCbxNodeBase *this)
{
  float m_fBehavioralVolume; // xmm5_4
  AkDeviceInfo *j; // rax
  float v4; // xmm1_4
  __int64 v5; // rcx
  unsigned __int64 *v6; // rdx
  AkDevice *v7; // rdx
  unsigned int v8; // r10d
  AkRayVolumeData *v9; // rcx
  AkRayVolumeData *v10; // r9
  float *p_fDryMixGain; // rdx
  AkDeviceInfo *i; // rcx
  unsigned __int64 uDeviceID; // r10
  __int64 v14; // rax
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm4_4
  unsigned __int64 *p_uDeviceID; // rdx
  AkDevice *v19; // rdx
  unsigned int uListeners; // r11d
  AkRayVolumeData *m_pItems; // rax
  AkRayVolumeData *v22; // r9
  float *p_fGameDefAuxMixGain; // rdx
  float v24; // xmm3_4
  float v25; // xmm4_4
  CAkKeyArray<unsigned __int64,AkVPL *,1> *p_PerDeviceAuxBusses; // r9
  __int64 m_uNumSends; // r11
  MapStruct<unsigned __int64,AkVPL *> *v28; // rax
  __int64 v29; // r8
  float v30; // xmm1_4
  float v31; // xmm1_4
  AkHdrBus *m_pHdrBus; // rdx
  AkDeviceInfo *m_pFirst; // rax
  CAkPBI *m_pCtx; // rbx
  bool v35; // zf
  float v36; // xmm2_4
  float v37; // xmm6_4
  double v38; // xmm0_8
  AkHdrBus *v39; // rax
  float v40; // xmm0_4
  float fMaxVolume; // [rsp+40h] [rbp+8h]

  m_fBehavioralVolume = this->m_fBehavioralVolume;
  if ( (*((_BYTE *)this + 76) & 0x10) != 0 )
  {
    for ( i = this->m_OutputDevices.m_listDeviceVolumes.m_pFirst; i; i = i->pNextLightItem )
    {
      uDeviceID = i->uDeviceID;
      v14 = 0i64;
      v15 = 0.0;
      v16 = 0.0;
      v17 = 0.0;
      if ( CAkOutputMgr::m_Devices.m_uLength )
      {
        p_uDeviceID = &CAkOutputMgr::m_Devices.m_pItems->uDeviceID;
        while ( *p_uDeviceID != uDeviceID )
        {
          v14 = (unsigned int)(v14 + 1);
          p_uDeviceID += 10;
          if ( (unsigned int)v14 >= CAkOutputMgr::m_Devices.m_uLength )
            goto LABEL_23;
        }
        v19 = &CAkOutputMgr::m_Devices.m_pItems[v14];
      }
      else
      {
LABEL_23:
        v19 = 0i64;
      }
      uListeners = v19->uListeners;
      m_pItems = this->m_arVolumeData.m_pItems;
      v22 = &m_pItems[this->m_arVolumeData.m_uLength];
      if ( m_pItems != v22 )
      {
        p_fGameDefAuxMixGain = &m_pItems->fGameDefAuxMixGain;
        do
        {
          if ( ((unsigned __int8)uListeners & *((_BYTE *)p_fGameDefAuxMixGain - 7)) != 0 )
          {
            if ( v15 < (float)((float)(m_fBehavioralVolume * i->pMixBus->m_fDownstreamGain) * *(p_fGameDefAuxMixGain - 1)) )
              v15 = m_fBehavioralVolume * i->pMixBus->m_fDownstreamGain;
            if ( v16 <= *p_fGameDefAuxMixGain )
              v16 = *p_fGameDefAuxMixGain;
            if ( v17 <= p_fGameDefAuxMixGain[1] )
              v17 = p_fGameDefAuxMixGain[1];
          }
          p_fGameDefAuxMixGain += 9;
        }
        while ( p_fGameDefAuxMixGain - 6 != (float *)v22 );
      }
      if ( i->bCrossDeviceSend )
        v15 = 0.0;
      v24 = v16 * m_fBehavioralVolume;
      v25 = v17 * m_fBehavioralVolume;
      if ( this->m_uNumSends )
      {
        p_PerDeviceAuxBusses = &this->m_arSendValues[0].PerDeviceAuxBusses;
        m_uNumSends = (unsigned __int8)this->m_uNumSends;
        do
        {
          v28 = p_PerDeviceAuxBusses->m_pItems;
          v29 = (__int64)&p_PerDeviceAuxBusses->m_pItems[p_PerDeviceAuxBusses->m_uLength];
          if ( p_PerDeviceAuxBusses->m_pItems != (MapStruct<unsigned __int64,AkVPL *> *)v29 )
          {
            while ( uDeviceID != v28->key )
            {
              if ( ++v28 == (MapStruct<unsigned __int64,AkVPL *> *)v29 )
                goto LABEL_48;
            }
            if ( p_PerDeviceAuxBusses[-1].m_ulReserved )
              v30 = v25;
            else
              v30 = v24;
            v31 = v30 * (float)(v28->item->m_fDownstreamGain * *(float *)&p_PerDeviceAuxBusses[-1].m_pItems);
            if ( v15 < v31 )
              v15 = v31;
          }
LABEL_48:
          p_PerDeviceAuxBusses += 2;
          --m_uNumSends;
        }
        while ( m_uNumSends );
      }
      i->fMaxVolume = v15;
    }
  }
  else
  {
    for ( j = this->m_OutputDevices.m_listDeviceVolumes.m_pFirst; j; j = j->pNextLightItem )
    {
      v4 = 0.0;
      if ( !j->bCrossDeviceSend )
      {
        v5 = 0i64;
        if ( CAkOutputMgr::m_Devices.m_uLength )
        {
          v6 = &CAkOutputMgr::m_Devices.m_pItems->uDeviceID;
          while ( *v6 != j->uDeviceID )
          {
            v5 = (unsigned int)(v5 + 1);
            v6 += 10;
            if ( (unsigned int)v5 >= CAkOutputMgr::m_Devices.m_uLength )
              goto LABEL_8;
          }
          v7 = &CAkOutputMgr::m_Devices.m_pItems[v5];
        }
        else
        {
LABEL_8:
          v7 = 0i64;
        }
        v8 = v7->uListeners;
        v9 = this->m_arVolumeData.m_pItems;
        v10 = &v9[this->m_arVolumeData.m_uLength];
        if ( v9 != v10 )
        {
          p_fDryMixGain = &v9->fDryMixGain;
          do
          {
            if ( ((unsigned __int8)v8 & *((_BYTE *)p_fDryMixGain - 3)) != 0
              && v4 < (float)((float)(m_fBehavioralVolume * j->pMixBus->m_fDownstreamGain) * *p_fDryMixGain) )
            {
              v4 = m_fBehavioralVolume * j->pMixBus->m_fDownstreamGain;
            }
            p_fDryMixGain += 9;
          }
          while ( p_fDryMixGain - 5 != (float *)v10 );
        }
      }
      j->fMaxVolume = v4;
    }
  }
  m_pHdrBus = this->m_pHdrBus;
  if ( m_pHdrBus )
  {
    m_pFirst = this->m_OutputDevices.m_listDeviceVolumes.m_pFirst;
    if ( m_pFirst )
    {
      while ( m_pFirst->uDeviceID )
      {
        m_pFirst = m_pFirst->pNextLightItem;
        if ( !m_pFirst )
          return;
      }
      m_pCtx = this->m_pSources[0]->m_pCtx;
      fMaxVolume = m_pFirst->fMaxVolume;
      v35 = (*((_BYTE *)&m_pCtx->m_EffectiveParams.hdr + 4) & 2) == 0;
      v36 = (float)(COERCE_FLOAT((LODWORD(fMaxVolume) & 0x7FFFFF) + 1065353216) - 1.0)
          / (float)(COERCE_FLOAT((LODWORD(fMaxVolume) & 0x7FFFFF) + 1065353216) + 1.0);
      v37 = (float)((float)((float)((float)((float)((float)(v36 * v36) * 0.33333334) + 1.0) * (float)(v36 * 2.0))
                          + (float)((float)((float)(unsigned __int8)(LODWORD(fMaxVolume) >> 23) - 127.0) * 0.69314718))
                  * 0.43429449)
          * 20.0;
      this->m_fMaxVolumeDB = v37;
      if ( v35 )
      {
        if ( v37 > m_pHdrBus->m_fHdrMaxVoiceVolume )
          m_pHdrBus->m_fHdrMaxVoiceVolume = v37;
      }
      else
      {
        v38 = ((double (__fastcall *)(CAkVPLSrcCbxNodeBase *))this->vfptr->GetAnalyzedEnvelope)(this);
        if ( COERCE_FLOAT(LODWORD(v38) ^ _xmm[0]) < m_pCtx->m_EffectiveParams.hdr.fActiveRange )
        {
          v39 = this->m_pHdrBus;
          v40 = *(float *)&v38 + v37;
          if ( v40 > v39->m_fHdrMaxVoiceVolume )
            v39->m_fHdrMaxVoiceVolume = v40;
        }
      }
    }
  }
}

// File Line: 1291
// RVA: 0xA668F0
void __fastcall CAkVPLSrcCbxNodeBase::GetVolumes(
        CAkVPLSrcCbxNodeBase *this,
        bool in_bIsAuxRoutable,
        CAkPBI *in_pContext,
        unsigned int in_uInputConfig,
        bool *out_bNextSilent,
        bool *out_bAudible,
        float *out_fLPF,
        float *out_fObsLPF)
{
  float *v8; // rdi
  float v10; // xmm2_4
  float v11; // xmm1_4
  CAkOutputDevices *p_m_OutputDevices; // r13
  AkDeviceInfo *m_pFirst; // r9
  float m_fBehavioralVolume; // xmm6_4
  AkHdrBus *m_pHdrBus; // rax
  float fMaxVolume; // xmm1_4
  float v19; // xmm3_4
  float v20; // xmm0_4
  float m_fHdrWinTop; // xmm0_4
  float v22; // xmm0_4
  float v23; // xmm2_4
  float v24; // xmm2_4
  AkDeviceInfo *i; // rax
  char v26; // r15
  float in_fBehavioralVolume; // xmm6_4
  char v28; // al
  bool v29; // zf
  AkFeedbackParams *m_pFeedbackInfo; // rcx
  unsigned int v31; // edx
  unsigned int v32; // esi
  unsigned int v33; // ecx
  AkDeviceInfo *v34; // rax
  unsigned int v35; // edx
  __int64 v36; // rcx
  float *v37; // rax
  AkDeviceInfo *k; // rbx
  float fLPF; // xmm0_4
  float fObsLPF; // xmm1_4
  AkFeedbackParams *v41; // rdi
  AkDeviceInfo *m; // rax
  unsigned int v43; // edx
  __int64 v44; // rcx
  char v45; // al
  unsigned int m_PlayingID; // edi
  unsigned int OutputConfig; // eax
  char v48; // al
  unsigned int v49; // ecx
  __int64 v50; // rax
  unsigned int v51; // ecx
  __int64 v52; // rax
  AkDeviceInfo *j; // rax
  unsigned int v54; // edx
  __int64 v55; // rcx

  v8 = out_fLPF;
  v10 = 0.0;
  v11 = 0.0;
  p_m_OutputDevices = &this->m_OutputDevices;
  *out_fLPF = 0.0;
  *out_fObsLPF = 0.0;
  m_pFirst = this->m_OutputDevices.m_listDeviceVolumes.m_pFirst;
  m_fBehavioralVolume = this->m_fBehavioralVolume;
  if ( m_pFirst )
  {
    while ( m_pFirst->uDeviceID )
    {
      m_pFirst = m_pFirst->pNextLightItem;
      if ( !m_pFirst )
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    m_pFirst = 0i64;
  }
  m_pHdrBus = this->m_pHdrBus;
  if ( m_pHdrBus && m_pFirst )
  {
    fMaxVolume = m_pFirst->fMaxVolume;
    v19 = m_pHdrBus->m_fThreshold + m_pHdrBus->m_fDownstreamGainDB;
    v20 = this->m_fMaxVolumeDB - v19;
    if ( v20 > 0.0 )
      v19 = (float)(v20 * m_pHdrBus->m_fGainFactor) + v19;
    m_fHdrWinTop = m_pHdrBus->m_fHdrWinTop;
    if ( v19 > m_fHdrWinTop )
      m_fHdrWinTop = v19;
    v22 = m_fHdrWinTop * -0.050000001;
    if ( v22 >= -37.0 )
    {
      if ( (`AkMath::FastPow10::`4::`local static guard & 1) != 0 )
      {
        v23 = *(float *)&`AkMath::FastPow10::`4::SCALE;
      }
      else
      {
        v23 = FLOAT_2_7866352e7;
        `AkMath::FastPow10::`4::SCALE = LODWORD(FLOAT_2_7866352e7);
        `AkMath::FastPow10::`4::`local static guard |= 1u;
      }
      v10 = (float)((float)((float)((float)(COERCE_FLOAT(((int)(float)((float)(v22 * v23) + 1065353200.0) & 0x7FFFFF) + 1065353216)
                                          * 0.32518977)
                                  + 0.020805772)
                          * COERCE_FLOAT(((int)(float)((float)(v22 * v23) + 1065353200.0) & 0x7FFFFF) + 1065353216))
                  + 0.65304345)
          * COERCE_FLOAT((int)(float)((float)(v22 * v23) + 1065353200.0) & 0xFF800000);
    }
    v24 = v10 * this->m_pHdrBus->m_fDownstreamGain;
    m_fBehavioralVolume = m_fBehavioralVolume * v24;
    v11 = fMaxVolume * v24;
    this->m_fBehavioralVolume = m_fBehavioralVolume;
    m_pFirst->fMaxVolume = v11;
  }
  for ( i = p_m_OutputDevices->m_listDeviceVolumes.m_pFirst; i; i = i->pNextLightItem )
  {
    if ( v11 <= i->fMaxVolume )
      v11 = i->fMaxVolume;
  }
  v26 = v11 <= g_fVolumeThreshold || !this->m_arVolumeData.m_uLength;
  in_fBehavioralVolume = m_fBehavioralVolume * CAkVPLSrcNode::GetMakeupGain(this->m_pSources[0]);
  if ( v26 && ((v28 = *((_BYTE *)this + 76), (v28 & 2) != 0) || (v28 & 4) == 0) )
  {
    v29 = (*((_BYTE *)in_pContext + 374) & 0x40) == 0;
    *((_BYTE *)this + 76) = v28 | 2;
    *out_bAudible = 0;
    *out_bNextSilent = v26;
    if ( v29 )
      CAkPBI::ValidateFeedbackParameters(in_pContext);
    m_pFeedbackInfo = in_pContext->m_pFeedbackInfo;
    if ( m_pFeedbackInfo )
      AkFeedbackParams::ZeroNewVolumes(m_pFeedbackInfo);
  }
  else
  {
    v31 = in_uInputConfig;
    v32 = 0;
    v33 = in_uInputConfig;
    for ( *out_bAudible = 1; v33; v33 &= v33 - 1 )
      ++v32;
    v34 = p_m_OutputDevices->m_listDeviceVolumes.m_pFirst;
    if ( p_m_OutputDevices->m_listDeviceVolumes.m_pFirst )
    {
      do
      {
        v35 = 0;
        do
        {
          v36 = v35++;
          v36 <<= 6;
          *(__m128 *)((char *)v34->mxDirect[0].Previous.vector + v36) = *(__m128 *)((char *)v34->mxDirect[0].Next.vector
                                                                                  + v36);
          *(_OWORD *)((char *)&v34->mxDirect[0].Previous.aVolumes[4] + v36) = *(_OWORD *)((char *)&v34->mxDirect[0].Next.aVolumes[4]
                                                                                        + v36);
        }
        while ( v35 < v32 );
        v34->mxAttenuations.dry.fPrev = v34->mxAttenuations.dry.fNext;
        v34->mxAttenuations.userDef.fPrev = v34->mxAttenuations.userDef.fNext;
        v34->mxAttenuations.gameDef.fPrev = v34->mxAttenuations.gameDef.fNext;
        v34 = v34->pNextLightItem;
      }
      while ( v34 );
      v31 = in_uInputConfig;
    }
    if ( v26 )
    {
      for ( j = p_m_OutputDevices->m_listDeviceVolumes.m_pFirst; j; j = j->pNextLightItem )
      {
        v54 = 0;
        do
        {
          v55 = v54++;
          v55 <<= 6;
          *(__m128 *)((char *)j->mxDirect[0].Next.vector + v55) = 0i64;
          *(_OWORD *)((char *)&j->mxDirect[0].Next.aVolumes[4] + v55) = 0i64;
        }
        while ( v54 < v32 );
        j->mxAttenuations.dry.fNext = 0.0;
        j->mxAttenuations.userDef.fNext = 0.0;
        j->mxAttenuations.gameDef.fNext = 0.0;
      }
    }
    else
    {
      if ( (*((_BYTE *)in_pContext + 371) & 3) != 0 )
        CAkListener::ComputeSpeakerMatrix(
          in_bIsAuxRoutable,
          in_pContext,
          &this->m_arVolumeData,
          v31,
          in_fBehavioralVolume,
          &this->m_OutputDevices);
      else
        CAkVPLSrcCbxNodeBase::ComputeSpeakerMatrix2D(
          this,
          in_bIsAuxRoutable,
          in_pContext,
          &this->m_arVolumeData,
          v31,
          in_fBehavioralVolume);
      *((_BYTE *)in_pContext + 371) &= ~0x10u;
      if ( this->m_OutputDevices.m_uNumDevices )
      {
        v37 = out_fObsLPF;
        *out_fLPF = 100.0;
        *out_fObsLPF = 100.0;
        for ( k = p_m_OutputDevices->m_listDeviceVolumes.m_pFirst; k; v37 = out_fObsLPF )
        {
          fLPF = *v8;
          if ( *v8 >= k->fLPF )
            fLPF = k->fLPF;
          *v8 = fLPF;
          fObsLPF = *v37;
          if ( *v37 >= k->fObsLPF )
            fObsLPF = k->fObsLPF;
          v29 = (*((_BYTE *)in_pContext + 374) & 0x40) == 0;
          *v37 = fObsLPF;
          if ( v29 )
            CAkPBI::ValidateFeedbackParameters(in_pContext);
          v41 = in_pContext->m_pFeedbackInfo;
          if ( v41 )
          {
            AkFeedbackParams::ComputePlayerVolumes(in_pContext->m_pFeedbackInfo, in_pContext);
            v26 &= *((_BYTE *)v41 + 55) & 1;
            if ( v26 )
            {
              for ( m = p_m_OutputDevices->m_listDeviceVolumes.m_pFirst; m; m = m->pNextLightItem )
              {
                v43 = 0;
                do
                {
                  v44 = v43++;
                  v44 <<= 6;
                  *(__m128 *)((char *)m->mxDirect[0].Next.vector + v44) = 0i64;
                  *(_OWORD *)((char *)&m->mxDirect[0].Next.aVolumes[4] + v44) = 0i64;
                }
                while ( v43 < v32 );
                m->mxAttenuations.dry.fNext = 0.0;
                m->mxAttenuations.userDef.fNext = 0.0;
                m->mxAttenuations.gameDef.fNext = 0.0;
              }
              v45 = *((_BYTE *)this + 76);
              if ( (v45 & 2) != 0 || (v45 & 4) == 0 )
              {
                *((_BYTE *)this + 76) = v45 | 2;
                *out_bAudible = 0;
              }
            }
          }
          if ( (in_pContext->m_uRegisteredNotif & 0x10) != 0 )
          {
            m_PlayingID = in_pContext->m_UserParams.m_PlayingID;
            OutputConfig = AkDeviceInfo::GetOutputConfig(k);
            CAkListener::DoSpeakerVolumeMatrixCallback(m_PlayingID, v32, in_uInputConfig, OutputConfig, k);
          }
          v48 = *((_BYTE *)this + 76);
          if ( (v48 & 2) != 0 )
          {
            v49 = 0;
            do
            {
              v50 = v49++;
              v50 <<= 6;
              *(__m128 *)((char *)k->mxDirect[0].Previous.vector + v50) = 0i64;
              *(_OWORD *)((char *)&k->mxDirect[0].Previous.aVolumes[4] + v50) = 0i64;
            }
            while ( v49 < v32 );
            k->mxAttenuations.dry.fPrev = 0.0;
            k->mxAttenuations.gameDef.fPrev = 0.0;
            k->mxAttenuations.userDef.fPrev = 0.0;
          }
          else if ( (v48 & 4) == 0 )
          {
            v51 = 0;
            do
            {
              v52 = v51++;
              v52 <<= 6;
              *(__m128 *)((char *)k->mxDirect[0].Previous.vector + v52) = *(__m128 *)((char *)k->mxDirect[0].Next.vector
                                                                                    + v52);
              *(_OWORD *)((char *)&k->mxDirect[0].Previous.aVolumes[4] + v52) = *(_OWORD *)((char *)&k->mxDirect[0].Next.aVolumes[4]
                                                                                          + v52);
            }
            while ( v51 < v32 );
            k->mxAttenuations.dry.fPrev = k->mxAttenuations.dry.fNext;
            k->mxAttenuations.userDef.fPrev = k->mxAttenuations.userDef.fNext;
            k->mxAttenuations.gameDef.fPrev = k->mxAttenuations.gameDef.fNext;
          }
          k = k->pNextLightItem;
          v8 = out_fLPF;
        }
      }
      else
      {
        *out_bAudible = 0;
        v26 = 1;
      }
    }
    *((_BYTE *)this + 76) &= ~0x40u;
    *out_bNextSilent = v26;
  }
}

// File Line: 1501
// RVA: 0xA65930
AKRESULT __fastcall CAkVPLSrcCbxNodeBase::AddSrc(CAkVPLSrcCbxNodeBase *this, CAkPBI *in_pCtx, bool in_bActive)
{
  CAkVPLSrcNode *v5; // rax

  v5 = CAkVPLSrcNode::Create(in_pCtx);
  if ( v5 )
    return CAkVPLSrcCbxNodeBase::AddSrc(this, v5, in_bActive);
  else
    return 2;
}

// File Line: 1510
// RVA: 0xA65980
__int64 __fastcall CAkVPLSrcCbxNodeBase::AddSrc(CAkVPLSrcCbxNodeBase *this, CAkVPLSrcNode *in_pSrc, bool in_bActive)
{
  CAkPBI *m_pCtx; // rbp
  AkBelowThresholdBehavior VirtualBehavior; // eax
  bool v8; // zf
  AkRayVolumeData *v9; // rax
  unsigned int v10; // edi
  AKRESULT StreamedData; // eax
  int v12; // ebx

  m_pCtx = in_pSrc->m_pCtx;
  m_pCtx->m_pCbx = this;
  if ( in_bActive )
  {
    VirtualBehavior = CAkPBI::GetVirtualBehavior(m_pCtx, &this->m_eVirtualBehavior);
    v8 = this->m_arVolumeData.m_ulReserved == 0;
    this->m_eBelowThresholdBehavior = VirtualBehavior;
    if ( v8 )
    {
      v9 = (AkRayVolumeData *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x24ui64);
      this->m_arVolumeData.m_pItems = v9;
      if ( !v9 )
      {
        v10 = 2;
        goto LABEL_19;
      }
      this->m_arVolumeData.m_ulReserved = 1;
    }
  }
  if ( this->m_eBelowThresholdBehavior == AkBelowThresholdBehavior_ContinueToPlay
    || !CAkPBI::IsInitiallyUnderThreshold(m_pCtx, &this->m_arVolumeData) )
  {
    goto LABEL_17;
  }
  if ( this->m_eBelowThresholdBehavior == AkBelowThresholdBehavior_KillVoice )
  {
    v10 = 3;
LABEL_19:
    CAkVPLSrcNode::Term(in_pSrc, CtxDestroyReasonPlayFailed);
    v12 = g_LEngineDefaultPoolId;
    in_pSrc->vfptr->__vecDelDtor(in_pSrc, 0i64);
    AK::MemoryMgr::Free(v12, in_pSrc);
    return v10;
  }
  if ( this->m_eVirtualBehavior == AkVirtualQueueBehavior_FromBeginning && in_bActive )
  {
    v10 = 1;
    if ( (*((_BYTE *)this + 76) & 1) != 0 )
      CAkPBI::Virtualize(m_pCtx);
    *((_BYTE *)this + 76) &= ~1u;
  }
  else
  {
LABEL_17:
    StreamedData = CAkVPLSrcNode::FetchStreamedData(in_pSrc);
    v10 = StreamedData;
    if ( StreamedData != AK_Success && StreamedData != AK_FormatNotReady )
      goto LABEL_19;
  }
  if ( in_bActive )
  {
    *((_BYTE *)this + 76) ^= (*((_BYTE *)this + 76) ^ (*((_BYTE *)m_pCtx + 375) >> 6)) & 2;
    this->m_pSources[0] = in_pSrc;
  }
  else
  {
    this->m_pSources[1] = in_pSrc;
  }
  return v10;
}

// File Line: 1587
// RVA: 0xA67230
void __fastcall CAkVPLSrcCbxNode::RestorePreviousVolumes(CAkVPLSrcCbxNode *this, AkPipelineBuffer *io_pBuffer)
{
  CAkVPLSrcNode *v2; // rax

  v2 = this->m_pSources[0];
  if ( v2 )
    v2->m_pCtx->m_Prev2DParams.prev2DParams.m_fPAN_X_2D = 101.0;
  else
    MEMORY[0x1C8] = 1120534528;
}

// File Line: 1592
// RVA: 0xA678B0
void __fastcall CAkVPLSrcCbxNode::StopLooping(CAkVPLSrcCbxNode *this, CAkPBI *in_pCtx)
{
  CAkVPLSrcNode *v3; // rcx
  CAkVPLSrcNode *v4; // rcx
  CAkVPLSrcNode *v5; // rdi
  int v6; // esi

  v3 = this->m_pSources[0];
  if ( v3 && in_pCtx == v3->m_pCtx )
  {
    if ( (*((_BYTE *)v3 + 32) & 1) == 0
      || ((unsigned int (__fastcall *)(CAkVPLSrcNode *))v3->vfptr[1].VirtualOn)(v3) != 1 )
    {
      this->vfptr->Stop(this);
    }
  }
  else
  {
    v4 = this->m_pSources[1];
    if ( v4 && in_pCtx == v4->m_pCtx )
    {
      CAkVPLSrcNode::Term(v4, CtxDestroyReasonFinished);
      v5 = this->m_pSources[1];
      v6 = g_LEngineDefaultPoolId;
      if ( v5 )
      {
        v5->vfptr->__vecDelDtor(v5, 0);
        AK::MemoryMgr::Free(v6, v5);
      }
      this->m_pSources[1] = 0i64;
    }
  }
}

// File Line: 1612
// RVA: 0xA672D0
void __fastcall CAkVPLSrcCbxNode::SeekSource(CAkVPLSrcCbxNode *this)
{
  CAkVPLSrcNode *v2; // rax
  CAkPBI *m_pCtx; // rax
  CAkVPLSrcNode *v4; // rax

  if ( this->m_eVirtualBehavior || this->m_eBelowThresholdBehavior != AkBelowThresholdBehavior_SetAsVirtualVoice )
  {
    v4 = this->m_pSources[0];
    if ( v4 )
    {
      if ( (*((_BYTE *)v4 + 32) & 1) != 0 )
      {
        this->m_cbxRec.m_LPF.vfptr->ReleaseBuffer(&this->m_cbxRec.m_LPF);
        if ( this->m_cbxRec.m_LPF.vfptr->Seek(&this->m_cbxRec.m_LPF) != AK_Success )
          this->vfptr->Stop(this);
      }
    }
  }
  else
  {
    v2 = this->m_pSources[0];
    if ( v2 )
    {
      m_pCtx = v2->m_pCtx;
      if ( m_pCtx )
      {
        m_pCtx->m_uSeekPosition = 0;
        *((_BYTE *)m_pCtx + 375) &= 0xF1u;
      }
    }
  }
}

// File Line: 1656
// RVA: 0xA67030
char __fastcall CAkVPLSrcCbxNode::IsUsingThisSlot(CAkVPLSrcCbxNode *this, CAkUsageSlot *in_pUsageSlot)
{
  int v3; // edi
  CAkVPLFilterNodeBase **i; // rsi
  CAkEffectContextBase **v5; // rbx
  AK::IAkPlugin *v6; // rax

  v3 = 0;
  for ( i = this->m_cbxRec.m_pFilter; ; ++i )
  {
    v5 = (CAkEffectContextBase **)*i;
    if ( *i )
    {
      if ( v5[3] )
      {
        v6 = (AK::IAkPlugin *)(*(__int64 (__fastcall **)(CAkVPLFilterNodeBase *))&(*v5)[3].m_dataArray.m_uLength)(*i);
        if ( CAkEffectContextBase::IsUsingThisSlot(v5[3], in_pUsageSlot, v6) )
          break;
      }
    }
    if ( (unsigned int)++v3 >= 4 )
      return 0;
  }
  return 1;
}

// File Line: 1667
// RVA: 0xA66FC0
char __fastcall CAkVPLSrcCbxNode::IsUsingThisSlot(CAkVPLSrcCbxNode *this, const char *in_pData)
{
  int v3; // ebx
  CAkVPLFilterNodeBase **i; // rdi
  CAkEffectContextBase *m_pInsertFXContext; // rcx

  v3 = 0;
  for ( i = this->m_cbxRec.m_pFilter; ; ++i )
  {
    if ( *i )
    {
      m_pInsertFXContext = (*i)->m_pInsertFXContext;
      if ( m_pInsertFXContext )
      {
        if ( CAkEffectContextBase::IsUsingThisSlot(m_pInsertFXContext, in_pData) )
          break;
      }
    }
    if ( (unsigned int)++v3 >= 4 )
      return 0;
  }
  return 1;
}

// File Line: 1678
// RVA: 0xA671B0
void __fastcall CAkVPLSrcCbxNode::RemovePipeline(CAkVPLSrcCbxNode *this, AkCtxDestroyReason in_eReason)
{
  CAkVPLSrcNode *v3; // rcx
  CAkVPLSrcNode *v4; // rdi
  int v5; // esi

  v3 = this->m_pSources[0];
  if ( v3 )
  {
    CAkVPLSrcNode::Term(v3, in_eReason);
    v4 = this->m_pSources[0];
    v5 = g_LEngineDefaultPoolId;
    if ( v4 )
    {
      v4->vfptr->__vecDelDtor(v4, 0);
      AK::MemoryMgr::Free(v5, v4);
    }
    this->m_pSources[0] = 0i64;
  }
  AkVPLSrcCbxRec::ClearVPL(&this->m_cbxRec);
  CAkSrcLpFilter::Term(&this->m_ObstructionLPF.m_LPF);
  *((_BYTE *)&this->CAkVPLSrcCbxNodeBase + 76) |= 1u;
}

// File Line: 1692
// RVA: 0xA671A0
void __fastcall CAkVPLSrcCbxNode::RelocateMedia(CAkVPLSrcCbxNode *this, char *in_pNewMedia, char *in_pOldMedia)
{
  CAkVPLPitchNode::RelocateMedia(&this->m_cbxRec.m_Pitch, in_pNewMedia, in_pOldMedia);
}

