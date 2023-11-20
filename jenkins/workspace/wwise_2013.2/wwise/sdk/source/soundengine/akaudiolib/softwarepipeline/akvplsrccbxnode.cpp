// File Line: 59
// RVA: 0xA65AC0
void __fastcall AkVPLSrcCbxRec::ClearVPL(AkVPLSrcCbxRec *this)
{
  AkVPLSrcCbxRec *v1; // r14
  CAkVPLFilterNodeBase **v2; // rbx
  signed __int64 v3; // rsi
  CAkVPLFilterNodeBase *v4; // rdi
  int v5; // ebp

  v1 = this;
  v2 = this->m_pFilter;
  v3 = 4i64;
  do
  {
    if ( *v2 )
    {
      (*(void (**)(void))(*v2)->vfptr[1].gap8)();
      v4 = *v2;
      v5 = g_LEngineDefaultPoolId;
      if ( *v2 )
      {
        v4->vfptr->__vecDelDtor((CAkVPLNode *)&(*v2)->vfptr, 0);
        AK::MemoryMgr::Free(v5, v4);
      }
      *v2 = 0i64;
    }
    ++v2;
    --v3;
  }
  while ( v3 );
  CAkVPLPitchNode::Term(&v1->m_Pitch);
  CAkSrcLpFilter::Term(&v1->m_LPF.m_LPF);
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
  this->m_eState = 0;
  *((_BYTE *)this + 76) = v1 & 0xC3 | 3;
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
  CAkVPLSrcCbxNodeBase *v1; // rsi
  AkRayVolumeData *v2; // rdx
  signed int v3; // edi
  signed __int64 v4; // rbx
  void *v5; // rdx

  v1 = this;
  this->vfptr = (CAkVPLSrcCbxNodeBaseVtbl *)&CAkVPLSrcCbxNodeBase::`vftable;
  v2 = this->m_arVolumeData.m_pItems;
  if ( v2 )
  {
    this->m_arVolumeData.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v2);
    v1->m_arVolumeData.m_pItems = 0i64;
    v1->m_arVolumeData.m_ulReserved = 0;
  }
  v3 = 7;
  v4 = (signed __int64)&v1[1].pNextItem;
  do
  {
    v5 = *(void **)(v4 - 32);
    v4 -= 32i64;
    if ( v5 )
    {
      *(_DWORD *)(v4 + 8) = 0;
      AK::MemoryMgr::Free(g_DefaultPoolId, v5);
      *(_QWORD *)v4 = 0i64;
      *(_DWORD *)(v4 + 12) = 0;
    }
    --v3;
  }
  while ( v3 >= 0 );
  CAkOutputDevices::~CAkOutputDevices(&v1->m_OutputDevices);
}

// File Line: 113
// RVA: 0xA673F0
void __fastcall CAkVPLSrcCbxNodeBase::Start(CAkVPLSrcCbxNodeBase *this)
{
  VPLNodeState v1; // eax
  CAkVPLSrcCbxNodeBase *v2; // rbx

  v1 = this->m_eState;
  v2 = this;
  if ( v1 )
  {
    if ( v1 != 2 )
      ((void (*)(void))this->vfptr->Stop)();
  }
  else
  {
    CAkVPLSrcNode::Start(this->m_pSources[0]);
    v2->m_eState = 1;
  }
}

// File Line: 145
// RVA: 0xA66720
signed __int64 __fastcall CAkVPLSrcCbxNodeBase::FetchStreamedData(CAkVPLSrcCbxNodeBase *this, CAkPBI *in_pCtx)
{
  CAkVPLSrcCbxNodeBase *v2; // rbx
  CAkPBI *v3; // rdi
  AKRESULT v4; // eax
  int v6; // edx
  signed int v7; // ecx

  v2 = this;
  v3 = in_pCtx;
  v4 = CAkVPLSrcNode::FetchStreamedData(this->m_pSources[0]);
  if ( v4 == 63 )
  {
    if ( v3->m_iFrameOffset < 0 && !(*((_BYTE *)v2->m_pSources[0] + 32) & 2) )
      *((_BYTE *)v2 + 76) |= 0x20u;
    return 63i64;
  }
  if ( v4 != 1 )
    return 2i64;
  v6 = v3->m_iFrameOffset;
  v7 = 8;
  if ( *((_BYTE *)v3 + 374) >= 0 )
    v7 = 1024;
  if ( v6 >= (unk_14249E984 + 1) * v7 )
    return 63i64;
  if ( v6 < 0 && !(*((_BYTE *)v2->m_pSources[0] + 32) & 2) )
    *((_BYTE *)v2 + 76) |= 0x20u;
  return 1i64;
}

// File Line: 203
// RVA: 0xA670B0
void __fastcall CAkVPLSrcCbxNodeBase::Pause(CAkVPLSrcCbxNodeBase *this)
{
  CAkVPLSrcCbxNodeBase *v1; // rbx

  v1 = this;
  if ( this->m_eState == 1 )
  {
    CAkVPLSrcNode::Pause(this->m_pSources[0]);
    v1->m_eState = 3;
  }
  else
  {
    ((void (*)(void))this->vfptr->Stop)();
  }
}

// File Line: 242
// RVA: 0xA65150
void __fastcall CAkVPLSrcCbxNode::CAkVPLSrcCbxNode(CAkVPLSrcCbxNode *this)
{
  CAkVPLSrcCbxNode *v1; // rdi

  v1 = this;
  CAkVPLSrcCbxNodeBase::CAkVPLSrcCbxNodeBase((CAkVPLSrcCbxNodeBase *)&this->vfptr);
  v1->m_uChannelMask = 4;
  v1->vfptr = (CAkVPLSrcCbxNodeBaseVtbl *)&CAkVPLSrcCbxNode::`vftable;
  CAkVPLPitchNode::CAkVPLPitchNode(&v1->m_cbxRec.m_Pitch, v1);
  v1->m_cbxRec.m_LPF.vfptr = (CAkVPLNodeVtbl *)&CAkVPLLPFNode::`vftable;
  v1->m_cbxRec.m_LPF.m_pInput = 0i64;
  CAkSrcLpFilter::CAkSrcLpFilter(&v1->m_cbxRec.m_LPF.m_LPF);
  v1->m_cbxRec.m_pFilter[0] = 0i64;
  v1->m_cbxRec.m_pFilter[1] = 0i64;
  v1->m_cbxRec.m_pFilter[2] = 0i64;
  v1->m_cbxRec.m_pFilter[3] = 0i64;
  v1->m_ObstructionLPF.m_pInput = 0i64;
  v1->m_ObstructionLPF.vfptr = (CAkVPLNodeVtbl *)&CAkVPLLPFNode::`vftable;
  CAkSrcLpFilter::CAkSrcLpFilter(&v1->m_ObstructionLPF.m_LPF);
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
  CAkVPLSrcCbxNode *v1; // rbx
  unsigned int v2; // edi
  signed __int64 v3; // rsi
  void *v4; // rdx
  CAkVPLSrcNode *v5; // rcx
  CAkVPLSrcNode *v6; // rdi
  int v7; // esi
  CAkVPLSrcNode *v8; // rcx
  CAkVPLSrcNode *v9; // rdi
  int v10; // esi

  v1 = this;
  v2 = 0;
  if ( this->m_uNumSends )
  {
    do
    {
      v3 = (signed __int64)v1 + 32 * v2;
      v4 = *(void **)(v3 + 112);
      if ( v4 )
      {
        *(_DWORD *)(v3 + 120) = 0;
        AK::MemoryMgr::Free(g_DefaultPoolId, v4);
        *(_QWORD *)(v3 + 112) = 0i64;
        *(_DWORD *)(v3 + 124) = 0;
      }
      ++v2;
    }
    while ( v2 < (unsigned __int8)v1->m_uNumSends );
  }
  v5 = v1->m_pSources[0];
  if ( v5 )
  {
    CAkVPLSrcNode::Term(v5, 0);
    v6 = v1->m_pSources[0];
    v7 = g_LEngineDefaultPoolId;
    if ( v6 )
    {
      v6->vfptr->__vecDelDtor((CAkVPLNode *)&v6->vfptr, 0);
      AK::MemoryMgr::Free(v7, v6);
    }
    v1->m_pSources[0] = 0i64;
  }
  AkVPLSrcCbxRec::ClearVPL(&v1->m_cbxRec);
  CAkSrcLpFilter::Term(&v1->m_ObstructionLPF.m_LPF);
  *((_BYTE *)&v1->0 + 76) |= 1u;
  v8 = v1->m_pSources[1];
  if ( v8 )
  {
    CAkVPLSrcNode::Term(v8, 0);
    v9 = v1->m_pSources[1];
    v10 = g_LEngineDefaultPoolId;
    if ( v9 )
    {
      v9->vfptr->__vecDelDtor((CAkVPLNode *)&v9->vfptr, 0);
      AK::MemoryMgr::Free(v10, v9);
    }
    v1->m_pSources[1] = 0i64;
  }
}

// File Line: 278
// RVA: 0xA67880
void __fastcall CAkVPLSrcCbxNode::Stop(CAkVPLSrcCbxNode *this)
{
  CAkVPLSrcCbxNode *v1; // rbx
  CAkVPLSrcNode *v2; // rcx

  v1 = this;
  v2 = this->m_pSources[0];
  if ( v2 )
    CAkVPLSrcNode::Stop(v2);
  v1->m_eState = 2;
}

// File Line: 297
// RVA: 0xA67260
void __fastcall CAkVPLSrcCbxNode::Resume(CAkVPLSrcCbxNode *this)
{
  CAkVPLSrcCbxNode *v1; // rbx
  __int32 v2; // ecx
  float v3; // xmm0_4

  v1 = this;
  v2 = this->m_eState - 1;
  if ( v2 )
  {
    if ( v2 == 2 )
    {
      v3 = CAkResampler::GetLastRate(&v1->m_cbxRec.m_Pitch.m_Pitch);
      CAkVPLSrcNode::Resume(v1->m_pSources[0], v3);
      v1->m_eState = 1;
    }
    else
    {
      v1->vfptr->Stop((CAkVPLSrcCbxNodeBase *)&v1->vfptr);
    }
  }
}

// File Line: 321
// RVA: 0xA67430
bool __fastcall CAkVPLSrcCbxNode::StartRun(CAkVPLSrcCbxNode *this, AkVPLState *io_state)
{
  unsigned int v2; // esi
  CAkVPLSrcCbxNode *v3; // rbx
  CAkPBI *v4; // rdi
  AkVPLState *v5; // r14
  int v6; // eax
  bool v8; // dl
  bool v9; // r12
  float v10; // xmm0_4
  float v11; // xmm1_4
  char v12; // al
  bool v13; // bp
  char v14; // r15
  char v15; // cl
  CAkVPLSrcNode *v16; // rcx
  AKRESULT v17; // eax
  unsigned __int8 v18; // si
  int v19; // eax
  AkBelowThresholdBehavior v20; // eax
  int v21; // ecx
  int v22; // eax
  bool v23; // si
  int v24; // ecx
  bool v25; // zf
  bool v26; // dl
  float out_fLPF; // [rsp+40h] [rbp-48h]
  unsigned int out_bAudible[4]; // [rsp+90h] [rbp+8h]
  bool out_bNextSilent; // [rsp+A0h] [rbp+18h]
  float out_fObsLPF; // [rsp+A8h] [rbp+20h]

  v2 = this->m_uChannelMask;
  v3 = this;
  v4 = this->m_pSources[0]->m_pCtx;
  v5 = io_state;
  v6 = ((__int64 (__fastcall *)(CAkPBI *))v4->vfptr[6]._Stop)(this->m_pSources[0]->m_pCtx);
  if ( v6 != -1 )
  {
    v5->bStop = 1;
    if ( !v6 )
    {
      v3->vfptr->Stop((CAkVPLSrcCbxNodeBase *)&v3->vfptr);
      return 0;
    }
  }
  v5->uChannelMask = v2;
  v8 = (*((_BYTE *)&v3->0 + 76) >> 4) & 1;
  v5->bIsAuxRoutable = v8;
  CAkVPLSrcCbxNodeBase::GetVolumes(
    (CAkVPLSrcCbxNodeBase *)&v3->vfptr,
    v8,
    v4,
    v2,
    &out_bNextSilent,
    (bool *)out_bAudible,
    &out_fLPF,
    &out_fObsLPF);
  v9 = out_bNextSilent;
  if ( out_bNextSilent || *((_BYTE *)v4 + 374) < 0 )
  {
    v12 = *((_BYTE *)v4 + 373);
    v11 = v3->m_cbxRec.m_LPF.m_LPF.m_InternalLPFState.fTargetLPFPar;
    v10 = v3->m_ObstructionLPF.m_LPF.m_InternalLPFState.fTargetLPFPar;
    if ( v12 & 0x10 )
    {
      v5->bStop = 1;
    }
    else if ( v12 & 0x40 )
    {
      v5->bPause = 1;
    }
  }
  else
  {
    v10 = out_fObsLPF;
    v11 = out_fLPF;
  }
  v13 = out_bAudible[0];
  v14 = 1;
  v5->bAudible = out_bAudible[0];
  if ( v13 )
  {
    if ( v11 >= 0.0 )
    {
      if ( v11 > 100.0 )
        v11 = FLOAT_100_0;
    }
    else
    {
      v11 = 0.0;
    }
    v15 = 1;
    v3->m_cbxRec.m_LPF.m_LPF.m_InternalLPFState.bTargetDirty |= v11 != v3->m_cbxRec.m_LPF.m_LPF.m_InternalLPFState.fTargetLPFPar;
    v3->m_cbxRec.m_LPF.m_LPF.m_InternalLPFState.fTargetLPFPar = v11;
    if ( v10 <= v4->m_EffectiveParams.fOutputBusLPF )
      v10 = v4->m_EffectiveParams.fOutputBusLPF;
    if ( v10 >= 0.0 )
    {
      if ( v10 > 100.0 )
        v10 = FLOAT_100_0;
    }
    else
    {
      v10 = 0.0;
    }
    if ( v10 == v3->m_ObstructionLPF.m_LPF.m_InternalLPFState.fTargetLPFPar )
      v15 = 0;
    v3->m_ObstructionLPF.m_LPF.m_InternalLPFState.bTargetDirty |= v15;
    v3->m_ObstructionLPF.m_LPF.m_InternalLPFState.fTargetLPFPar = v10;
    v16 = v3->m_pSources[0];
    if ( (!(*((_BYTE *)&v3->0 + 76) & 1) || !(*((_BYTE *)v16 + 32) & 1)) && v3->m_eBelowThresholdBehavior == 2 )
    {
      if ( *((_BYTE *)v16 + 32) & 1 )
      {
        v18 = 0;
        v19 = (unsigned __int64)((__int64 (__fastcall *)(CAkPBI *, _QWORD))v4->vfptr[7]._Stop)(
                                  v4,
                                  (unsigned int)v3->m_eVirtualBehavior)
            - 1;
        if ( v19 )
        {
          if ( v19 == 1 )
          {
            v3->vfptr->Stop((CAkVPLSrcCbxNodeBase *)&v3->vfptr);
            return 0;
          }
        }
        else
        {
          v18 = 1;
        }
        if ( v3->m_cbxRec.m_LPF.vfptr->VirtualOff((CAkVPLNode *)&v3->m_cbxRec.m_LPF.vfptr, v3->m_eVirtualBehavior, v18) != 1 )
        {
          v3->vfptr->Stop((CAkVPLSrcCbxNodeBase *)&v3->vfptr);
          return 0;
        }
      }
      else
      {
        v17 = CAkVPLSrcNode::FetchStreamedData(v16);
        if ( v17 == 63 )
        {
          v13 = 0;
          v14 = 0;
        }
        else if ( v17 != 1 )
        {
          v3->vfptr->Stop((CAkVPLSrcCbxNodeBase *)&v3->vfptr);
          v13 = 0;
          v14 = 0;
        }
      }
    }
  }
  else
  {
    v20 = v3->m_eBelowThresholdBehavior;
    if ( v20 == 2 )
    {
      v14 = 0;
      if ( *((_BYTE *)&v3->0 + 76) & 1 )
      {
        v3->m_cbxRec.m_LPF.vfptr->VirtualOn((CAkVPLNode *)&v3->m_cbxRec.m_LPF.vfptr, v3->m_eVirtualBehavior);
        if ( v3->m_eVirtualBehavior != 2 )
          v3->m_cbxRec.m_LPF.vfptr->ReleaseBuffer((CAkVPLNode *)&v3->m_cbxRec.m_LPF.vfptr);
      }
      if ( v3->m_eVirtualBehavior == 1 )
      {
        if ( v4->m_iFrameOffset < v5->uMaxFrames )
        {
          out_bAudible[0] = v5->uMaxFrames;
          v5->result = (__int64)v3->m_cbxRec.m_LPF.vfptr->TimeSkip(
                                  (CAkVPLNode *)&v3->m_cbxRec.m_LPF.vfptr,
                                  out_bAudible);
        }
        v21 = v4->m_iFrameOffset;
        if ( v21 >= 0 )
          v4->m_iFrameOffset = v21 - v5->uMaxFrames;
      }
    }
    else if ( v20 == 1 )
    {
      v3->vfptr->Stop((CAkVPLSrcCbxNodeBase *)&v3->vfptr);
      v14 = 0;
    }
    else
    {
      v13 = 1;
    }
  }
  if ( *((_BYTE *)&v3->0 + 76) & 0x20 )
  {
    v22 = ((__int64 (__fastcall *)(CAkPBI *, _QWORD))v4->vfptr[7]._Stop)(v4, (unsigned int)v3->m_eVirtualBehavior);
    if ( v22 == 1 )
    {
      v3->vfptr->SeekSource((CAkVPLSrcCbxNodeBase *)&v3->vfptr);
      *((_BYTE *)&v3->0 + 76) |= 2u;
    }
    else if ( v22 == 2 )
    {
      v3->vfptr->Stop((CAkVPLSrcCbxNodeBase *)&v3->vfptr);
      v14 = 0;
    }
    *((_BYTE *)&v3->0 + 76) &= 0xDFu;
  }
  v23 = v14 && v4->m_iFrameOffset < v5->uMaxFrames;
  v24 = v4->m_iFrameOffset;
  if ( v24 >= 0 )
    v4->m_iFrameOffset = v24 - v5->uMaxFrames;
  if ( *((_BYTE *)&v3->0 + 76) & 1 )
  {
    if ( !v13 )
      CAkPBI::Virtualize(v4);
  }
  else if ( v13 )
  {
    CAkPBI::Devirtualize(v4, 1);
  }
  *((_BYTE *)&v3->0 + 76) &= 0xFEu;
  *((_BYTE *)&v3->0 + 76) |= v13;
  if ( v23 )
  {
    v25 = v3->m_cbxRec.m_Pitch.m_pPBI == 0i64;
    *((_BYTE *)&v3->0 + 76) ^= (*((_BYTE *)&v3->0 + 76) ^ 2 * v9) & 2;
    if ( v25 )
    {
      if ( CAkVPLSrcCbxNode::AddPipeline(v3) == 1 )
      {
        if ( !(*((_BYTE *)v4 + 372) & 0x20) )
          v4->vfptr[7].~CAkTransportAware((CAkTransportAware *)&v4->vfptr);
        v4->m_Prev2DParams.prev2DParams.m_fPAN_X_2D = 101.0;
        v26 = v5->bIsAuxRoutable;
        v5->uChannelMask = v3->m_uChannelMask;
        CAkVPLSrcCbxNodeBase::GetVolumes(
          (CAkVPLSrcCbxNodeBase *)&v3->vfptr,
          v26,
          v4,
          v3->m_uChannelMask,
          &out_bNextSilent,
          (bool *)out_bAudible,
          &out_fObsLPF,
          &out_fObsLPF);
      }
      else
      {
        v3->vfptr->Stop((CAkVPLSrcCbxNodeBase *)&v3->vfptr);
        v23 = 0;
      }
    }
  }
  *((_BYTE *)&v3->0 + 76) |= 4u;
  return v23;
}

// File Line: 544
// RVA: 0xA666A0
void __fastcall CAkVPLSrcCbxNode::ConsumeBuffer(CAkVPLSrcCbxNode *this, AkVPLState *io_state)
{
  CAkVPLSrcNode *v2; // r9
  AkVPLState *v3; // rbx
  CAkVPLSrcCbxNode *v4; // rsi
  CAkPBI *v5; // rdi
  unsigned int v6; // eax
  CAkVPLSrcNode *v7; // rcx

  v2 = this->m_pSources[0];
  v3 = io_state;
  v4 = this;
  v5 = v2->m_pCtx;
  if ( v5->m_uRegisteredNotif & 0x10000 )
    CAkPositionRepository::UpdatePositionInfo(
      g_pPositionRepository,
      v5->m_UserParams.m_PlayingID,
      &io_state->posInfo,
      v2);
  v6 = ((__int64 (__fastcall *)(CAkPBI *))v5->vfptr[6].~CAkTransportAware)(v5);
  if ( v6 != -1 )
  {
    if ( v6 < v3->uValidFrames )
      v3->uValidFrames = v6;
    v3->bStop = 1;
  }
  v7 = v4->m_pSources[1];
  if ( v7 )
  {
    if ( CAkVPLSrcNode::FetchStreamedData(v7) == 2 )
      v3->result = 2;
  }
}

// File Line: 586
// RVA: 0xA67190
void __fastcall CAkVPLSrcCbxNode::ReleaseBuffer(CAkVPLSrcCbxNode *this)
{
  ((void (*)(void))this->m_cbxRec.m_LPF.vfptr->ReleaseBuffer)();
}

// File Line: 593
// RVA: 0xA67950
void __fastcall CAkVPLSrcCbxNode::SwitchToNextSrc(CAkVPLSrcCbxNode *this)
{
  CAkVPLSrcCbxNode *v1; // rbx
  CAkVPLSrcNode *v2; // rdi
  int v3; // esi
  CAkVPLSrcNode *v4; // rcx
  CAkVPLFilterNodeBase *v5; // rdx
  CAkPBI *v6; // rcx
  CAkInsertFXContext *v7; // rax
  CAkVPLFilterNodeBase *v8; // rdx
  CAkPBI *v9; // rcx
  CAkVPLFilterNodeBase *v10; // rdx
  CAkPBI *v11; // rcx
  CAkVPLFilterNodeBase *v12; // rdx
  CAkPBI *v13; // rcx

  v1 = this;
  CAkVPLSrcNode::Term(this->m_pSources[0], 0);
  v2 = v1->m_pSources[0];
  v3 = g_LEngineDefaultPoolId;
  if ( v2 )
  {
    v2->vfptr->__vecDelDtor((CAkVPLNode *)&v2->vfptr, 0);
    AK::MemoryMgr::Free(v3, v2);
  }
  v4 = v1->m_pSources[1];
  v1->m_pSources[1] = 0i64;
  v1->m_pSources[0] = v4;
  CAkVPLSrcNode::Start(v4);
  v5 = v1->m_cbxRec.m_pFilter[0];
  if ( v5 )
  {
    v6 = v1->m_pSources[0]->m_pCtx;
    v7 = v5->m_pInsertFXContext;
    v5->m_pCtx = v6;
    v7->m_pContext = v6;
  }
  v8 = v1->m_cbxRec.m_pFilter[1];
  if ( v8 )
  {
    v9 = v1->m_pSources[0]->m_pCtx;
    v8->m_pCtx = v9;
    v8->m_pInsertFXContext->m_pContext = v9;
  }
  v10 = v1->m_cbxRec.m_pFilter[2];
  if ( v10 )
  {
    v11 = v1->m_pSources[0]->m_pCtx;
    v10->m_pCtx = v11;
    v10->m_pInsertFXContext->m_pContext = v11;
  }
  v12 = v1->m_cbxRec.m_pFilter[3];
  if ( v12 )
  {
    v13 = v1->m_pSources[0]->m_pCtx;
    v12->m_pCtx = v13;
    v12->m_pInsertFXContext->m_pContext = v13;
  }
}

// File Line: 613
// RVA: 0xA67B50
void __fastcall CAkVPLSrcCbxNode::UpdateFx(CAkVPLSrcCbxNode *this, unsigned int in_uFXIndex)
{
  __int64 v2; // rbp
  CAkVPLSrcCbxNode *v3; // r12
  char v4; // dl
  signed __int64 v5; // rax
  CAkVPLNode **v6; // r8
  CAkVPLNode *v7; // rsi
  __int64 v8; // rcx
  signed __int64 *v9; // rax
  signed __int64 v10; // r14
  __int64 v11; // r15
  int v12; // eax
  int v13; // edx
  char v14; // r8
  unsigned int v15; // edx
  int v16; // ecx
  AK::IAkPlugin *v17; // rbx
  AK::IAkPluginVtbl *v18; // rdi
  int v19; // er13
  signed int v20; // ebx
  signed __int64 v21; // r15
  int v22; // ebx
  __int64 v23; // rcx
  AK::IAkPluginVtbl *v24; // rax
  AK::IAkPluginVtbl *v25; // rax
  int v26; // ebx
  char v27; // al
  int v28; // ebp
  AK::IAkPlugin *out_pEffect; // [rsp+30h] [rbp-58h]
  __int64 v30; // [rsp+38h] [rbp-50h]
  unsigned int *v31; // [rsp+40h] [rbp-48h]
  char v32; // [rsp+48h] [rbp-40h]
  char v33; // [rsp+98h] [rbp+10h]
  unsigned int v34; // [rsp+A0h] [rbp+18h]
  __int64 v35; // [rsp+A8h] [rbp+20h]

  v2 = (signed int)in_uFXIndex;
  v3 = this;
  if ( in_uFXIndex != -1 )
  {
    v4 = 0;
    v34 = v2 + 1;
    v5 = (signed int)v2 + 1;
    v33 = 0;
    if ( v5 >= 4 )
    {
LABEL_6:
      v7 = (CAkVPLNode *)&this->m_cbxRec.m_LPF.vfptr;
    }
    else
    {
      v6 = (CAkVPLNode **)&this->m_cbxRec.m_pFilter[v5];
      while ( 1 )
      {
        v7 = *v6;
        if ( *v6 )
          break;
        ++v5;
        ++v6;
        if ( v5 >= 4 )
          goto LABEL_6;
      }
      v33 = 1;
    }
    v8 = (signed int)v2 - 1;
    if ( (signed int)v2 - 1 < 0 )
    {
LABEL_11:
      v10 = (signed __int64)&v3->m_cbxRec;
    }
    else
    {
      v9 = (signed __int64 *)&v3->m_cbxRec.m_pFilter[(signed int)v2 - 1];
      while ( 1 )
      {
        v10 = *v9;
        if ( *v9 )
          break;
        --v9;
        if ( --v8 < 0 )
          goto LABEL_11;
      }
      v4 = 1;
    }
    v11 = (__int64)v3->m_pSources[0]->m_pCtx;
    v30 = v11;
    v35 = *(_QWORD *)(v11 + 184);
    if ( v4 )
    {
      v12 = (*(__int64 (__fastcall **)(signed __int64))(*(_QWORD *)v10 + 128i64))(v10);
      v13 = (HIDWORD(v35) ^ v12) & 0x3FFFF ^ HIDWORD(v35);
    }
    else
    {
      v13 = HIDWORD(v35);
    }
    v14 = 0;
    v15 = v13 & 0xFF83FFFF | 0x800000;
    v16 = v15 & 0x3FFFF;
    if ( v15 & 0x3FFFF )
    {
      do
      {
        ++v14;
        v16 &= v16 - 1;
      }
      while ( v16 );
    }
    LODWORD(v35) = v3->m_uSampleRate;
    v17 = (AK::IAkPlugin *)(&v3->vfptr + (unsigned int)v2 + 104i64);
    out_pEffect = v17;
    v18 = v17->vfptr;
    HIDWORD(v35) = (v15 & 0xE0FFFFFF | ((v14 * ((v15 >> 18) & 0x3F) & 0xF8 | 0xFFFFFC00) << 21)) & 0xBFFFFFFF | 0x20000000;
    v19 = HIDWORD(v35) & 0x3FFFF;
    if ( v18 )
    {
      v20 = v2;
      v19 = (*((__int64 (__fastcall **)(AK::IAkPluginVtbl *))v18->__vecDelDtor + 16))(v18);
      if ( (signed int)v2 < 4 )
      {
        v21 = (signed __int64)&v3->m_cbxRec.m_pFilter[v2];
        do
        {
          if ( *(_QWORD *)v21 && (*(unsigned __int8 (**)(void))(**(_QWORD **)v21 + 96i64))() && v20 != (_DWORD)v2 )
            break;
          ++v20;
          v21 += 8i64;
        }
        while ( v20 < 4 );
        v11 = v30;
      }
      CAkVPLNode::Disconnect(v7);
      (*((void (__fastcall **)(AK::IAkPluginVtbl *))v18->__vecDelDtor + 10))(v18);
      v22 = g_LEngineDefaultPoolId;
      (*(void (__fastcall **)(AK::IAkPluginVtbl *, _QWORD))v18->__vecDelDtor)(v18, 0i64);
      AK::MemoryMgr::Free(v22, v18);
      v17 = out_pEffect;
      v18 = 0i64;
      out_pEffect->vfptr = 0i64;
    }
    v23 = *(_QWORD *)(v11 + 152);
    v31 = 0i64;
    (*(void (__fastcall **)(__int64, _QWORD, unsigned int **, _QWORD))(*(_QWORD *)v23 + 448i64))(
      v23,
      (unsigned int)v2,
      &v31,
      *(_QWORD *)(v11 + 168));
    if ( v31 )
    {
      out_pEffect = 0i64;
      if ( (unsigned int)CAkEffectsMgr::Alloc(
                           (AK::IAkPluginMemAlloc *)&AkFXMemAlloc::m_instanceLower.vfptr,
                           v31[6],
                           &out_pEffect) != 1 )
        goto LABEL_48;
      out_pEffect->vfptr->GetPluginInfo(out_pEffect, (AkPluginInfo *)&v30);
      if ( BYTE5(v30) )
      {
        out_pEffect->vfptr->Term(out_pEffect, (AK::IAkPluginMemAlloc *)&AkFXMemAlloc::m_instanceLower);
        goto LABEL_48;
      }
      if ( BYTE4(v30) )
      {
        v24 = (AK::IAkPluginVtbl *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 0x50ui64);
        v18 = v24;
        if ( !v24 )
          goto LABEL_48;
        v24->Term = 0i64;
        v24->__vecDelDtor = (void *(__fastcall *)(AK::IAkPlugin *, unsigned int))&CAkVPLFilterNode::`vftable;
      }
      else
      {
        v25 = (AK::IAkPluginVtbl *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 0xD8ui64);
        v18 = v25;
        if ( !v25 )
          goto LABEL_48;
        v25->Term = 0i64;
        v25->__vecDelDtor = (void *(__fastcall *)(AK::IAkPlugin *, unsigned int))&CAkVPLFilterNodeOutOfPlace::`vftable;
        v25[1].GetPluginInfo = 0i64;
        LOWORD(v25[2].__vecDelDtor) = 0;
        v25[2].Term = 0i64;
        v25[2].SupportMediaRelocation = 0i64;
        LOWORD(v25[3].Term) = 0;
        v25[3].Reset = 0i64;
      }
      if ( !v18 )
        goto LABEL_48;
      if ( (*((unsigned int (__fastcall **)(AK::IAkPluginVtbl *, AK::IAkPlugin *, unsigned int **, _QWORD, __int64, __int64 *))v18->__vecDelDtor
            + 9))(
             v18,
             out_pEffect,
             &v31,
             (unsigned int)v2,
             v11,
             &v35) != 1 )
      {
        (*((void (__fastcall **)(AK::IAkPluginVtbl *))v18->__vecDelDtor + 10))(v18);
        v26 = g_LEngineDefaultPoolId;
        (*(void (__fastcall **)(AK::IAkPluginVtbl *, _QWORD))v18->__vecDelDtor)(v18, 0i64);
        AK::MemoryMgr::Free(v26, v18);
        goto LABEL_48;
      }
      v27 = v32;
      v17->vfptr = v18;
      BYTE5(v18->RelocateMedia) = v27;
      (*((void (__fastcall **)(AK::IAkPluginVtbl *, signed __int64))v18->__vecDelDtor + 8))(v18, v10);
      v28 = (*((__int64 (__fastcall **)(AK::IAkPluginVtbl *))v18->__vecDelDtor + 16))(v18);
    }
    else
    {
      v28 = HIDWORD(v35) & 0x3FFFF;
    }
    if ( v28 != v19 )
    {
      if ( v33 )
      {
        v3->vfptr->UpdateFx((CAkVPLSrcCbxNodeBase *)&v3->vfptr, v34);
        goto LABEL_49;
      }
      CAkSrcLpFilter::Term(&v3->m_cbxRec.m_LPF.m_LPF);
      CAkSrcLpFilter::Init(&v3->m_cbxRec.m_LPF.m_LPF, v28, 0);
      CAkSrcLpFilter::Term(&v3->m_ObstructionLPF.m_LPF);
      CAkSrcLpFilter::Init(&v3->m_ObstructionLPF.m_LPF, v28, 0);
      v3->m_uChannelMask = v28;
      CAkPBI::InvalidateFeedbackParameters((CAkPBI *)v11);
    }
    if ( v18 )
      v10 = (signed __int64)v18;
LABEL_48:
    v7->vfptr->Connect(v7, (CAkVPLNode *)v10);
LABEL_49:
    if ( v31 )
      (*(void (**)(void))(*(_QWORD *)v31 + 16i64))();
  }
}

// File Line: 797
// RVA: 0xA67370
void __fastcall CAkVPLSrcCbxNode::SetFxBypass(CAkVPLSrcCbxNode *this, unsigned int in_bitsFXBypass, unsigned int in_uTargetMask)
{
  CAkVPLFilterNodeBase *v3; // r9
  CAkVPLFilterNodeBase *v4; // r9
  CAkVPLFilterNodeBase *v5; // r9
  CAkVPLFilterNodeBase *v6; // rax

  v3 = this->m_cbxRec.m_pFilter[0];
  if ( v3 && in_uTargetMask & 1 )
    v3->m_bBypassed = in_bitsFXBypass & 1;
  v4 = this->m_cbxRec.m_pFilter[1];
  if ( v4 && in_uTargetMask & 2 )
    v4->m_bBypassed = (in_bitsFXBypass >> 1) & 1;
  v5 = this->m_cbxRec.m_pFilter[2];
  if ( v5 && in_uTargetMask & 4 )
    v5->m_bBypassed = (in_bitsFXBypass >> 2) & 1;
  v6 = this->m_cbxRec.m_pFilter[3];
  if ( v6 )
  {
    if ( in_uTargetMask & 8 )
      v6->m_bBypassed = (in_bitsFXBypass >> 3) & 1;
  }
}

// File Line: 807
// RVA: 0xA67160
void __fastcall CAkVPLSrcCbxNode::RefreshBypassFx(CAkVPLSrcCbxNode *this)
{
  CAkVPLSrcCbxNode *v1; // rdi
  unsigned int v2; // ebx

  v1 = this;
  v2 = 0;
  do
    v1->vfptr->RefreshBypassFx((CAkVPLSrcCbxNodeBase *)&v1->vfptr, v2++);
  while ( v2 < 4 );
}

// File Line: 815
// RVA: 0xA670F0
void __fastcall CAkVPLSrcCbxNode::RefreshBypassFx(CAkVPLSrcCbxNode *this, __int64 in_uFXIndex)
{
  CAkVPLSrcNode *v2; // rax
  CAkPBI *v3; // r9
  CAkVPLFilterNodeBase *v4; // rbx
  CAkSoundBase *v5; // r10
  CAkIndexableVtbl *v6; // rax
  CAkRegisteredObj *v7; // r9
  __int64 v8; // rcx
  __int64 v9; // [rsp+20h] [rbp-18h]
  bool v10; // [rsp+28h] [rbp-10h]

  v2 = this->m_pSources[0];
  if ( v2 )
  {
    v3 = v2->m_pCtx;
    v4 = this->m_cbxRec.m_pFilter[(unsigned int)in_uFXIndex];
    v5 = v3->m_pSound;
    if ( v4 )
    {
      v6 = v5->vfptr;
      v7 = v3->m_pGameObj;
      v9 = 0i64;
      ((void (__fastcall *)(CAkSoundBase *, __int64, __int64 *, CAkRegisteredObj *))v6[14].__vecDelDtor)(
        v5,
        in_uFXIndex,
        &v9,
        v7);
      v8 = v9;
      v4->m_bBypassed = v10;
      if ( v8 )
        (*(void (**)(void))(*(_QWORD *)v8 + 16i64))();
    }
  }
}

// File Line: 837
// RVA: 0xA65620
AKRESULT __fastcall CAkVPLSrcCbxNode::AddPipeline(CAkVPLSrcCbxNode *this)
{
  unsigned int v1; // er9
  AkVPLSrcCbxRec *v2; // rbx
  CAkPBI *v3; // r13
  CAkVPLSrcCbxNode *v4; // r12
  CAkSoundBase *v5; // rdi
  unsigned int v6; // eax
  unsigned __int8 v7; // si
  CAkVPLFilterNodeBase **v8; // r15
  unsigned int v9; // er14
  CAkIndexableVtbl *v10; // rax
  CAkRegisteredObj *v11; // r9
  CAkVPLSrcNode *v12; // rax
  CAkVPLSrcNode *v13; // rbx
  int v14; // edi
  unsigned int *v15; // rcx
  __int64 v16; // rax
  AKRESULT result; // eax
  unsigned int v18; // edx
  AKRESULT v19; // ebx
  unsigned int *v20; // [rsp+30h] [rbp-39h]
  __int64 v21; // [rsp+38h] [rbp-31h]
  CAkVPLSrcNode *v22; // [rsp+40h] [rbp-29h]
  AkVPLSrcCbxRec *v23; // [rsp+48h] [rbp-21h]
  AK::IAkPlugin *out_pEffect; // [rsp+D0h] [rbp+67h]
  AkAudioFormat io_pFormat; // [rsp+D8h] [rbp+6Fh]
  char v26; // [rsp+E0h] [rbp+77h]
  char v27; // [rsp+E4h] [rbp+7Bh]
  char v28; // [rsp+E5h] [rbp+7Ch]
  CAkSoundBase *v29; // [rsp+E8h] [rbp+7Fh]

  v1 = this->m_uSampleRate;
  v2 = &this->m_cbxRec;
  v3 = this->m_pSources[0]->m_pCtx;
  v22 = this->m_pSources[0];
  v4 = this;
  io_pFormat = v3->m_sMediaFormat;
  v5 = v3->m_pSound;
  v29 = v3->m_pSound;
  CAkVPLPitchNode::Init(&this->m_cbxRec.m_Pitch, &io_pFormat, v3, v1);
  v6 = v4->m_uSampleRate;
  v23 = v2;
  io_pFormat.uSampleRate = v6;
  v7 = 2;
  v8 = v4->m_cbxRec.m_pFilter;
  v9 = 0;
  while ( 1 )
  {
    v10 = v5->vfptr;
    v11 = v3->m_pGameObj;
    v20 = 0i64;
    ((void (__fastcall *)(CAkSoundBase *, _QWORD, unsigned int **, CAkRegisteredObj *))v10[14].__vecDelDtor)(
      v5,
      v9,
      &v20,
      v11);
    if ( v20 )
      break;
LABEL_20:
    ++v9;
    ++v8;
    if ( v9 >= 4 )
    {
      v4->m_uChannelMask = *((_DWORD *)&io_pFormat + 1) & 0x3FFFF;
      CAkPBI::InvalidateFeedbackParameters(v3);
      result = CAkSrcLpFilter::Init(&v4->m_cbxRec.m_LPF.m_LPF, v4->m_uChannelMask, 0);
      if ( result == 1 )
      {
        v18 = v4->m_uChannelMask;
        *(&v22 + v7) = (CAkVPLSrcNode *)&v4->m_cbxRec.m_LPF;
        result = CAkSrcLpFilter::Init(&v4->m_ObstructionLPF.m_LPF, v18, 0);
        v19 = result;
        if ( result == 1 )
        {
          for ( ; v7; --v7 )
            (*(&v22 + v7))->vfptr->Connect((CAkVPLNode *)*(&v22 + v7), (CAkVPLNode *)*(&v21 + v7));
          v4->vfptr->RefreshBypassFx((CAkVPLSrcCbxNodeBase *)&v4->vfptr);
          result = v19;
        }
      }
      return result;
    }
  }
  out_pEffect = 0i64;
  if ( (unsigned int)CAkEffectsMgr::Alloc(
                       (AK::IAkPluginMemAlloc *)&AkFXMemAlloc::m_instanceLower.vfptr,
                       v20[6],
                       &out_pEffect) != 1 )
  {
LABEL_4:
    if ( v20 )
    {
      (*(void (**)(void))(*(_QWORD *)v20 + 16i64))();
      v20 = 0i64;
    }
    goto LABEL_20;
  }
  out_pEffect->vfptr->GetPluginInfo(out_pEffect, (AkPluginInfo *)&v26);
  if ( v28 )
  {
    out_pEffect->vfptr->Term(out_pEffect, (AK::IAkPluginMemAlloc *)&AkFXMemAlloc::m_instanceLower);
    goto LABEL_4;
  }
  if ( v27 )
  {
    v12 = (CAkVPLSrcNode *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 0x50ui64);
    v13 = v12;
    if ( !v12 )
      goto LABEL_27;
    v12->m_pInput = 0i64;
    v12->vfptr = (CAkVPLNodeVtbl *)&CAkVPLFilterNode::`vftable;
  }
  else
  {
    v13 = (CAkVPLSrcNode *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 0xD8ui64);
    if ( !v13 )
      goto LABEL_27;
    v13->vfptr = (CAkVPLNodeVtbl *)&CAkVPLFilterNodeOutOfPlace::`vftable;
    v13->m_pInput = 0i64;
    *((_QWORD *)&v13[1] + 4) = 0i64;
    LOWORD(v13[2].m_pAnalysisData) = 0;
    v13[2].m_pCtx = 0i64;
    v13[3].m_pInput = 0i64;
    *((_WORD *)&v13[3] + 16) = 0;
    v13[4].vfptr = 0i64;
  }
  if ( v13 )
  {
    if ( ((unsigned int (__fastcall *)(CAkVPLSrcNode *, AK::IAkPlugin *, unsigned int **, _QWORD, CAkPBI *, AkAudioFormat *))v13->vfptr[1].__vecDelDtor)(
           v13,
           out_pEffect,
           &v20,
           v9,
           v3,
           &io_pFormat) == 1 )
    {
      v15 = v20;
      v16 = v7++;
      *v8 = (CAkVPLFilterNodeBase *)v13;
      *(&v22 + v16) = v13;
      if ( v15 )
      {
        (*(void (**)(void))(*(_QWORD *)v15 + 16i64))();
        v20 = 0i64;
      }
    }
    else
    {
      (*(void (__fastcall **)(CAkVPLSrcNode *))v13->vfptr[1].gap8)(v13);
      v14 = g_LEngineDefaultPoolId;
      v13->vfptr->__vecDelDtor((CAkVPLNode *)&v13->vfptr, 0);
      AK::MemoryMgr::Free(v14, v13);
      if ( v20 )
      {
        (*(void (**)(void))(*(_QWORD *)v20 + 16i64))();
        v5 = v29;
        v20 = 0i64;
      }
      else
      {
        v5 = v29;
      }
    }
    goto LABEL_20;
  }
LABEL_27:
  out_pEffect->vfptr->Term(out_pEffect, (AK::IAkPluginMemAlloc *)&AkFXMemAlloc::m_instanceLower);
  if ( v20 )
    (*(void (**)(void))(*(_QWORD *)v20 + 16i64))();
  return 2;
}

// File Line: 985
// RVA: 0xA65F20
void __fastcall CAkVPLSrcCbxNodeBase::ComputeSpeakerMatrix2D(CAkVPLSrcCbxNodeBase *this, bool in_bIsAuxRoutable, CAkPBI *in_pContext, AkArray<AkRayVolumeData,AkRayVolumeData const &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *in_arVolumeData, unsigned int in_uInputConfig, float in_fBehavioralVolume)
{
  AkDeviceInfo *v6; // rax
  AkRayVolumeData *v7; // r14
  CAkPBI *v8; // rdi
  bool v9; // r13
  CAkVPLSrcCbxNodeBase *v10; // rbx
  float v11; // xmm0_4
  AkFeedbackParams *v12; // rcx
  char v13; // al
  int v14; // eax
  unsigned int v15; // esi
  unsigned int v16; // ecx
  AkDeviceInfo *v17; // rbx
  unsigned int v18; // er12
  float v19; // xmm8_4
  float v20; // xmm8_4
  float v21; // xmm7_4
  __m128 v22; // xmm6
  unsigned int in_uOutputConfig; // eax
  __m128 v24; // xmm2
  AkSIMDSpeakerVolumes *v25; // rax
  signed __int64 v26; // rcx
  __int64 v27; // rdx
  __m128 v28; // xmm2
  __m128 v29; // xmm0
  __m128 v30; // xmm1
  unsigned __int64 v31; // rax
  AkSIMDSpeakerVolumes out_pVolumes; // [rsp+40h] [rbp-1B8h]

  v6 = this->m_OutputDevices.m_listDeviceVolumes.m_pFirst;
  v7 = in_arVolumeData->m_pItems;
  v8 = in_pContext;
  v9 = in_bIsAuxRoutable;
  v10 = this;
  if ( v6 )
  {
    v11 = in_pContext->m_EffectiveParams.LPF;
    do
    {
      v6->fLPF = v11;
      v6 = v6->pNextLightItem;
    }
    while ( v6 );
  }
  if ( !(*((_BYTE *)in_pContext + 374) & 0x40) )
    CAkPBI::ValidateFeedbackParameters(in_pContext);
  v12 = v8->m_pFeedbackInfo;
  if ( v8->m_BasePosParams.m_fPAN_X_2D != v8->m_Prev2DParams.prev2DParams.m_fPAN_X_2D
    || v8->m_BasePosParams.m_fPAN_Y_2D != v8->m_Prev2DParams.prev2DParams.m_fPAN_Y_2D
    || v8->m_BasePosParams.m_fCenterPCT != v8->m_Prev2DParams.prev2DParams.m_fCenterPCT
    || v8->m_Prev2DParams.prev2DParams.bIsPannerEnabled != v8->m_BasePosParams.bIsPannerEnabled
    || *((_BYTE *)v8 + 371) & 0x10
    || in_fBehavioralVolume != v8->m_Prev2DParams.prevVolume
    || v7->fDryMixGain != v8->m_Prev2DParams.prevDryLevel
    || v12 && v12->m_NewVolume != v8->m_Prev2DParams.prevMotionVol
    || (v13 = *((_BYTE *)v10 + 76), v13 & 2)
    || v8->m_uRegisteredNotif & 0x10
    || v13 & 0x40 )
  {
    v8->m_Prev2DParams.prev2DParams.m_fPAN_X_2D = v8->m_BasePosParams.m_fPAN_X_2D;
    v8->m_Prev2DParams.prev2DParams.m_fPAN_Y_2D = v8->m_BasePosParams.m_fPAN_Y_2D;
    v8->m_Prev2DParams.prev2DParams.m_fCenterPCT = v8->m_BasePosParams.m_fCenterPCT;
    v14 = *(_DWORD *)&v8->m_BasePosParams.bIsPannerEnabled;
    v8->m_Prev2DParams.prevVolume = in_fBehavioralVolume;
    *(_DWORD *)&v8->m_Prev2DParams.prev2DParams.bIsPannerEnabled = v14;
    v15 = 0;
    v16 = in_uInputConfig;
    for ( v8->m_Prev2DParams.prevDryLevel = v7->fDryMixGain; v16; v16 &= v16 - 1 )
      ++v15;
    v17 = v10->m_OutputDevices.m_listDeviceVolumes.m_pFirst;
    v18 = v15 - 1;
    if ( in_uInputConfig & 8 )
      --v15;
    for ( ; v17; v17 = v17->pNextLightItem )
    {
      v19 = v8->m_BasePosParams.m_fPAN_X_2D;
      v17->fLPF = v8->m_EffectiveParams.LPF;
      v20 = (float)(v19 + 100.0) * 0.0049999999;
      if ( v20 >= 0.0 )
      {
        if ( v20 > 1.0 )
          v20 = *(float *)&FLOAT_1_0;
      }
      else
      {
        v20 = 0.0;
      }
      v21 = (float)(v8->m_BasePosParams.m_fPAN_Y_2D + 100.0) * 0.0049999999;
      if ( v21 >= 0.0 )
      {
        if ( v21 > 1.0 )
          v21 = *(float *)&FLOAT_1_0;
      }
      else
      {
        v21 = 0.0;
      }
      v22 = (__m128)LODWORD(v8->m_BasePosParams.m_fCenterPCT);
      v22.m128_f32[0] = v22.m128_f32[0] * 0.0099999998;
      in_uOutputConfig = AkDeviceInfo::GetOutputConfig(v17);
      v24 = v22;
      CAkSpeakerPan::GetSpeakerVolumes2DPan(
        v20,
        v21,
        v22.m128_f32[0],
        v8->m_BasePosParams.bIsPannerEnabled,
        in_uInputConfig,
        in_uOutputConfig,
        &out_pVolumes);
      if ( v15 )
      {
        v24.m128_f32[0] = in_fBehavioralVolume;
        v25 = &out_pVolumes;
        v26 = (signed __int64)v17->mxDirect;
        v27 = v15;
        v28 = _mm_shuffle_ps(v24, v24, 0);
        do
        {
          v29 = v25->vector[0];
          v30 = v25->vector[1];
          v26 += 64i64;
          ++v25;
          *(__m128 *)(v26 - 64) = _mm_mul_ps(v29, v28);
          *(__m128 *)(v26 - 48) = _mm_mul_ps(v30, v28);
          --v27;
        }
        while ( v27 );
      }
      if ( in_uInputConfig & 8 )
      {
        v31 = (unsigned __int64)v18 << 6;
        *(__m128 *)((char *)v17->mxDirect[0].Next.vector + v31) = 0i64;
        *(_OWORD *)((char *)&v17->mxDirect[0].Next.aVolumes[4] + v31) = 0i64;
        *(float *)((char *)&v17->mxDirect[0].Next.volumes.fLfe + v31) = in_fBehavioralVolume;
      }
      v17->mxAttenuations.dry.fNext = v7->fDryMixGain;
      if ( v9 )
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
  CAkVPLSrcCbxNodeBase *v1; // rbx
  CAkPBI *v2; // rdi
  bool v3; // al
  bool v4; // r14
  float v5; // xmm7_4
  float v6; // xmm6_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm1_4
  unsigned __int8 v10; // al
  CAkRegisteredObj *v11; // rdx
  float v12; // xmm8_4
  float v13; // xmm0_4
  signed int v14; // esi
  __int128 *v15; // rbx
  signed int v16; // edi
  void *v17; // rdx
  AkAuxSendValueEx io_paEnvVal; // [rsp+30h] [rbp-D0h]
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
  __int128 v34; // [rsp+140h] [rbp+40h]

  v1 = this;
  v2 = this->m_pSources[0]->m_pCtx;
  if ( !(*((_BYTE *)v2 + 372) & 0x20) )
    v2->vfptr[7].~CAkTransportAware((CAkTransportAware *)&v2->vfptr);
  v3 = CAkPBI::IsAuxRoutable(v2);
  *((_BYTE *)v1 + 76) &= 0xEFu;
  v4 = v3;
  *((_BYTE *)v1 + 76) |= 16 * v3;
  if ( *((_BYTE *)v2 + 375) & 0x10 )
  {
    v1->m_arVolumeData.m_uLength = 0;
    CAkPBI::VirtualPositionUpdate(v2);
  }
  else
  {
    v5 = FLOAT_2_7866352e7;
    v6 = 0.0;
    v7 = (float)(CAkPBI::GetVoiceVolumedB(v2) + v2->m_EffectiveParams.Volume) * 0.050000001;
    if ( v7 >= -37.0 )
    {
      if ( `AkMath::FastPow10::`4::`local static guard & 1 )
      {
        v9 = *(float *)&`AkMath::FastPow10::`4::SCALE;
      }
      else
      {
        v9 = FLOAT_2_7866352e7;
        `AkMath::FastPow10::`4::`local static guard |= 1u;
        `AkMath::FastPow10::`4::SCALE = LODWORD(FLOAT_2_7866352e7);
      }
      v8 = (float)((float)((float)((float)(COERCE_FLOAT(
                                             ((signed int)(float)((float)(v9 * v7) + 1065353200.0) & 0x7FFFFF)
                                           + 1065353216)
                                         * 0.32518977)
                                 + 0.020805772)
                         * COERCE_FLOAT(((signed int)(float)((float)(v9 * v7) + 1065353200.0) & 0x7FFFFF) + 1065353216))
                 + 0.65304345)
         * COERCE_FLOAT((signed int)(float)((float)(v9 * v7) + 1065353200.0) & 0xFF800000);
    }
    else
    {
      v8 = 0.0;
    }
    v10 = *((_BYTE *)v2 + 371);
    v1->m_fBehavioralVolume = v8 * v2->m_EffectiveParams.fFadeRatio;
    if ( v10 & 3 )
    {
      v14 = ((unsigned int)v10 >> 2) & 3;
      if ( CAkPBI::ComputeVolumeData3D(v2, (AkPositionSourceType)v14, &v1->m_arVolumeData) )
        CAkListener::Get3DVolumes((AkPositionSourceType)v14, v4, v2, &v1->m_arVolumeData);
    }
    else
    {
      if ( !v1->m_arVolumeData.m_uLength
        && !AkArray<AkRayVolumeData,AkRayVolumeData const &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::AddLast(&v1->m_arVolumeData) )
      {
        return 0;
      }
      v11 = v2->m_pGameObj;
      v1->m_arVolumeData.m_pItems->m_uListenerMask = v11->m_PosKeep.m_uListenerMask;
      if ( v4 )
        v12 = v11->m_fDryLevelValue;
      else
        v12 = *(float *)&FLOAT_1_0;
      v13 = CAkPBI::GetOutputBusVolumeValuedB(v2) * 0.050000001;
      if ( v13 >= -37.0 )
      {
        if ( `AkMath::FastPow10::`4::`local static guard & 1 )
        {
          v5 = *(float *)&`AkMath::FastPow10::`4::SCALE;
        }
        else
        {
          `AkMath::FastPow10::`4::SCALE = LODWORD(FLOAT_2_7866352e7);
          `AkMath::FastPow10::`4::`local static guard |= 1u;
        }
        v6 = (float)((float)((float)((float)(COERCE_FLOAT(
                                               ((signed int)(float)((float)(v13 * v5) + 1065353200.0) & 0x7FFFFF)
                                             + 1065353216)
                                           * 0.32518977)
                                   + 0.020805772)
                           * COERCE_FLOAT(((signed int)(float)((float)(v13 * v5) + 1065353200.0) & 0x7FFFFF) + 1065353216))
                   + 0.65304345)
           * COERCE_FLOAT((signed int)(float)((float)(v13 * v5) + 1065353200.0) & 0xFF800000);
      }
      v1->m_arVolumeData.m_pItems->fDryMixGain = v6 * v12;
    }
  }
  if ( !v4 || !(*((_BYTE *)v1 + 76) & 1) )
  {
    v1->m_uNumSends = 0;
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
  CAkPBI::GetAuxSendsValues(v2, &io_paEnvVal);
  MergeLastAndCurrentValues(&io_paEnvVal, v1->m_arSendValues, (*((_BYTE *)v1 + 76) >> 3) & 1, &v1->m_uNumSends);
  *((_BYTE *)v1 + 76) |= 8u;
  v15 = &v34;
  v16 = 7;
  do
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
    --v16;
  }
  while ( v16 >= 0 );
  return 1;
}

// File Line: 1140
// RVA: 0xA65B60
void __fastcall CAkVPLSrcCbxNodeBase::ComputeMaxVolume(CAkVPLSrcCbxNodeBase *this)
{
  float v1; // xmm5_4
  CAkVPLSrcCbxNodeBase *v2; // rdi
  AkDeviceInfo *j; // rax
  float v4; // xmm1_4
  __int64 v5; // rcx
  unsigned __int64 *v6; // rdx
  AkDevice *v7; // rdx
  unsigned int v8; // er10
  AkRayVolumeData *v9; // rcx
  signed __int64 v10; // r9
  float *v11; // rdx
  AkDeviceInfo *i; // rcx
  unsigned __int64 v13; // r10
  __int64 v14; // rax
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm4_4
  unsigned __int64 *v18; // rdx
  AkDevice *v19; // rdx
  unsigned int v20; // er11
  AkRayVolumeData *v21; // rax
  signed __int64 v22; // r9
  float *v23; // rdx
  float v24; // xmm0_4
  float v25; // xmm3_4
  float v26; // xmm4_4
  signed __int64 v27; // r9
  __int64 v28; // r11
  _QWORD *v29; // rax
  signed __int64 v30; // r8
  float v31; // xmm1_4
  float v32; // xmm1_4
  AkHdrBus *v33; // rdx
  AkDeviceInfo *v34; // rax
  float v35; // xmm0_4
  CAkPBI *v36; // rbx
  bool v37; // zf
  float v38; // xmm2_4
  float v39; // xmm0_4
  float v40; // xmm6_4
  AkHdrBus *v41; // rax
  float v42; // xmm0_4

  v1 = this->m_fBehavioralVolume;
  v2 = this;
  if ( *((_BYTE *)this + 76) & 0x10 )
  {
    for ( i = this->m_OutputDevices.m_listDeviceVolumes.m_pFirst; i; i = i->pNextLightItem )
    {
      v13 = i->uDeviceID;
      v14 = 0i64;
      v15 = 0.0;
      v16 = 0.0;
      v17 = 0.0;
      if ( CAkOutputMgr::m_Devices.m_uLength )
      {
        v18 = &CAkOutputMgr::m_Devices.m_pItems->uDeviceID;
        while ( *v18 != v13 )
        {
          v14 = (unsigned int)(v14 + 1);
          v18 += 10;
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
      v20 = v19->uListeners;
      v21 = v2->m_arVolumeData.m_pItems;
      v22 = (signed __int64)&v21[v2->m_arVolumeData.m_uLength];
      if ( v21 != (AkRayVolumeData *)v22 )
      {
        v23 = &v21->fGameDefAuxMixGain;
        do
        {
          if ( (unsigned __int8)v20 & *((_BYTE *)v23 - 7) )
          {
            if ( v15 < (float)((float)(v1 * i->pMixBus->m_fDownstreamGain) * *(v23 - 1)) )
              v15 = v1 * i->pMixBus->m_fDownstreamGain;
            if ( v16 <= *v23 )
              v16 = *v23;
            v24 = v23[1];
            if ( v17 <= v24 )
              v17 = v23[1];
          }
          v23 += 9;
        }
        while ( v23 - 6 != (float *)v22 );
      }
      if ( i->bCrossDeviceSend )
        v15 = 0.0;
      v25 = v16 * v1;
      v26 = v17 * v1;
      if ( (signed int)(unsigned __int8)v2->m_uNumSends > 0 )
      {
        v27 = (signed __int64)&v2->m_arSendValues[0].PerDeviceAuxBusses;
        v28 = (unsigned __int8)v2->m_uNumSends;
        do
        {
          v29 = *(_QWORD **)v27;
          v30 = *(_QWORD *)v27 + 16i64 * *(unsigned int *)(v27 + 8);
          if ( *(_QWORD *)v27 != v30 )
          {
            while ( v13 != *v29 )
            {
              v29 += 2;
              if ( v29 == (_QWORD *)v30 )
                goto LABEL_48;
            }
            if ( *(_DWORD *)(v27 - 4) )
              v31 = v26;
            else
              v31 = v25;
            v32 = v31 * (float)(*(float *)(v29[1] + 1360i64) * *(float *)(v27 - 16));
            if ( v15 < v32 )
              v15 = v32;
          }
LABEL_48:
          v27 += 32i64;
          --v28;
        }
        while ( v28 );
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
        v9 = v2->m_arVolumeData.m_pItems;
        v10 = (signed __int64)&v9[v2->m_arVolumeData.m_uLength];
        if ( v9 != (AkRayVolumeData *)v10 )
        {
          v11 = &v9->fDryMixGain;
          do
          {
            if ( (unsigned __int8)v8 & *((_BYTE *)v11 - 3)
              && v4 < (float)((float)(v1 * j->pMixBus->m_fDownstreamGain) * *v11) )
            {
              v4 = v1 * j->pMixBus->m_fDownstreamGain;
            }
            v11 += 9;
          }
          while ( v11 - 5 != (float *)v10 );
        }
      }
      j->fMaxVolume = v4;
    }
  }
  v33 = v2->m_pHdrBus;
  if ( v33 )
  {
    v34 = v2->m_OutputDevices.m_listDeviceVolumes.m_pFirst;
    if ( v34 )
    {
      while ( v34->uDeviceID )
      {
        v34 = v34->pNextLightItem;
        if ( !v34 )
          return;
      }
      v35 = v34->fMaxVolume;
      v36 = v2->m_pSources[0]->m_pCtx;
      v37 = (*((_BYTE *)&v36->m_EffectiveParams.hdr + 4) & 2) == 0;
      v38 = (float)(COERCE_FLOAT((LODWORD(v35) & 0x7FFFFF) + 1065353216) - 1.0)
          / (float)(COERCE_FLOAT((LODWORD(v35) & 0x7FFFFF) + 1065353216) + 1.0);
      v39 = (float)((float)(unsigned __int8)(LODWORD(v35) >> 23) - 127.0) * 0.69314718;
      v40 = (float)((float)((float)((float)((float)((float)(v38 * v38) * 0.33333334) + 1.0) * (float)(v38 * 2.0)) + v39)
                  * 0.43429449)
          * 20.0;
      v2->m_fMaxVolumeDB = v40;
      if ( v37 )
      {
        if ( v40 > v33->m_fHdrMaxVoiceVolume )
          v33->m_fHdrMaxVoiceVolume = v40;
      }
      else
      {
        v2->vfptr->GetAnalyzedEnvelope(v2);
        if ( COERCE_FLOAT(LODWORD(v39) ^ _xmm[0]) < v36->m_EffectiveParams.hdr.fActiveRange )
        {
          v41 = v2->m_pHdrBus;
          v42 = v39 + v40;
          if ( v42 > v41->m_fHdrMaxVoiceVolume )
            v41->m_fHdrMaxVoiceVolume = v42;
        }
      }
    }
  }
}

// File Line: 1291
// RVA: 0xA668F0
void __fastcall CAkVPLSrcCbxNodeBase::GetVolumes(CAkVPLSrcCbxNodeBase *this, bool in_bIsAuxRoutable, CAkPBI *in_pContext, unsigned int in_uInputConfig, bool *out_bNextSilent, bool *out_bAudible, float *out_fLPF, float *out_fObsLPF)
{
  float *v8; // rdi
  CAkVPLSrcCbxNodeBase *v9; // r14
  float v10; // xmm2_4
  float v11; // xmm1_4
  CAkOutputDevices *v12; // r13
  CAkPBI *v13; // rbp
  AkDeviceInfo *v14; // r9
  float v15; // xmm6_4
  bool v16; // bl
  AkHdrBus *v17; // rax
  float v18; // xmm1_4
  float v19; // xmm3_4
  float v20; // xmm0_4
  float v21; // xmm0_4
  float v22; // xmm0_4
  float v23; // xmm2_4
  float v24; // xmm2_4
  AkDeviceInfo *v25; // rax
  char v26; // r15
  float in_fBehavioralVolume; // xmm6_4
  char v28; // al
  bool v29; // zf
  AkFeedbackParams *v30; // rcx
  unsigned int v31; // edx
  unsigned int v32; // esi
  unsigned int v33; // ecx
  AkDeviceInfo *v34; // rax
  unsigned int v35; // edx
  __int64 v36; // rcx
  float *v37; // rax
  AkDeviceInfo *v38; // rbx
  float v39; // xmm0_4
  float v40; // xmm1_4
  AkFeedbackParams *v41; // rdi
  AkDeviceInfo *v42; // rax
  unsigned int v43; // edx
  __int64 v44; // rcx
  char v45; // al
  unsigned int v46; // edi
  unsigned int v47; // eax
  char v48; // al
  unsigned int v49; // ecx
  __int64 v50; // rax
  unsigned int v51; // ecx
  __int64 v52; // rax
  AkDeviceInfo *v53; // rax
  unsigned int v54; // edx
  __int64 v55; // rcx
  unsigned int v56; // [rsp+A8h] [rbp+20h]

  v56 = in_uInputConfig;
  v8 = out_fLPF;
  v9 = this;
  v10 = 0.0;
  v11 = 0.0;
  v12 = &this->m_OutputDevices;
  v13 = in_pContext;
  *out_fLPF = 0.0;
  *out_fObsLPF = 0.0;
  v14 = this->m_OutputDevices.m_listDeviceVolumes.m_pFirst;
  v15 = this->m_fBehavioralVolume;
  v16 = in_bIsAuxRoutable;
  if ( v14 )
  {
    while ( v14->uDeviceID )
    {
      v14 = v14->pNextLightItem;
      if ( !v14 )
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    v14 = 0i64;
  }
  v17 = this->m_pHdrBus;
  if ( v17 && v14 )
  {
    v18 = v14->fMaxVolume;
    v19 = v17->m_fThreshold + v17->m_fDownstreamGainDB;
    v20 = this->m_fMaxVolumeDB - v19;
    if ( v20 > 0.0 )
      v19 = (float)(v20 * v17->m_fGainFactor) + v19;
    v21 = v17->m_fHdrWinTop;
    if ( v19 > v21 )
      v21 = v19;
    v22 = v21 * -0.050000001;
    if ( v22 >= -37.0 )
    {
      if ( `AkMath::FastPow10::`4::`local static guard & 1 )
      {
        v23 = *(float *)&`AkMath::FastPow10::`4::SCALE;
      }
      else
      {
        v23 = FLOAT_2_7866352e7;
        `AkMath::FastPow10::`4::SCALE = LODWORD(FLOAT_2_7866352e7);
        `AkMath::FastPow10::`4::`local static guard |= 1u;
      }
      v10 = (float)((float)((float)((float)(COERCE_FLOAT(
                                              ((signed int)(float)((float)(v22 * v23) + 1065353200.0) & 0x7FFFFF)
                                            + 1065353216)
                                          * 0.32518977)
                                  + 0.020805772)
                          * COERCE_FLOAT(((signed int)(float)((float)(v22 * v23) + 1065353200.0) & 0x7FFFFF) + 1065353216))
                  + 0.65304345)
          * COERCE_FLOAT((signed int)(float)((float)(v22 * v23) + 1065353200.0) & 0xFF800000);
    }
    v24 = v10 * this->m_pHdrBus->m_fDownstreamGain;
    v15 = v15 * v24;
    v11 = v18 * v24;
    this->m_fBehavioralVolume = v15;
    v14->fMaxVolume = v11;
  }
  v25 = v12->m_listDeviceVolumes.m_pFirst;
  if ( v12->m_listDeviceVolumes.m_pFirst )
  {
    do
    {
      if ( v11 <= v25->fMaxVolume )
        v11 = v25->fMaxVolume;
      v25 = v25->pNextLightItem;
    }
    while ( v25 );
  }
  v26 = v11 <= g_fVolumeThreshold || !this->m_arVolumeData.m_uLength;
  in_fBehavioralVolume = v15 * CAkVPLSrcNode::GetMakeupGain(this->m_pSources[0]);
  if ( v26 && ((v28 = *((_BYTE *)v9 + 76), v28 & 2) || !(v28 & 4)) )
  {
    v29 = (*((_BYTE *)v13 + 374) & 0x40) == 0;
    *((_BYTE *)v9 + 76) = v28 | 2;
    *out_bAudible = 0;
    *out_bNextSilent = v26;
    if ( v29 )
      CAkPBI::ValidateFeedbackParameters(v13);
    v30 = v13->m_pFeedbackInfo;
    if ( v30 )
      AkFeedbackParams::ZeroNewVolumes(v30);
  }
  else
  {
    v31 = v56;
    v32 = 0;
    v33 = v56;
    for ( *out_bAudible = 1; v33; v33 &= v33 - 1 )
      ++v32;
    v34 = v12->m_listDeviceVolumes.m_pFirst;
    if ( v12->m_listDeviceVolumes.m_pFirst )
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
      v31 = v56;
    }
    if ( v26 )
    {
      v53 = v12->m_listDeviceVolumes.m_pFirst;
      if ( v12->m_listDeviceVolumes.m_pFirst )
      {
        do
        {
          v54 = 0;
          do
          {
            v55 = v54++;
            v55 <<= 6;
            *(__m128 *)((char *)v53->mxDirect[0].Next.vector + v55) = 0i64;
            *(_OWORD *)((char *)&v53->mxDirect[0].Next.aVolumes[4] + v55) = 0i64;
          }
          while ( v54 < v32 );
          v53->mxAttenuations.dry.fNext = 0.0;
          v53->mxAttenuations.userDef.fNext = 0.0;
          v53->mxAttenuations.gameDef.fNext = 0.0;
          v53 = v53->pNextLightItem;
        }
        while ( v53 );
      }
    }
    else
    {
      if ( *((_BYTE *)v13 + 371) & 3 )
        CAkListener::ComputeSpeakerMatrix(
          v16,
          v13,
          &v9->m_arVolumeData,
          v31,
          in_fBehavioralVolume,
          &v9->m_OutputDevices);
      else
        CAkVPLSrcCbxNodeBase::ComputeSpeakerMatrix2D(v9, v16, v13, &v9->m_arVolumeData, v31, in_fBehavioralVolume);
      *((_BYTE *)v13 + 371) &= 0xEFu;
      if ( v9->m_OutputDevices.m_uNumDevices )
      {
        v37 = out_fObsLPF;
        *out_fLPF = 100.0;
        *out_fObsLPF = 100.0;
        v38 = v12->m_listDeviceVolumes.m_pFirst;
        if ( v12->m_listDeviceVolumes.m_pFirst )
        {
          do
          {
            v39 = *v8;
            if ( *v8 >= v38->fLPF )
              v39 = v38->fLPF;
            *v8 = v39;
            v40 = *v37;
            if ( *v37 >= v38->fObsLPF )
              v40 = v38->fObsLPF;
            v29 = (*((_BYTE *)v13 + 374) & 0x40) == 0;
            *v37 = v40;
            if ( v29 )
              CAkPBI::ValidateFeedbackParameters(v13);
            v41 = v13->m_pFeedbackInfo;
            if ( v41 )
            {
              AkFeedbackParams::ComputePlayerVolumes(v13->m_pFeedbackInfo, v13);
              v26 &= *((_BYTE *)v41 + 55) & 1;
              if ( v26 )
              {
                v42 = v12->m_listDeviceVolumes.m_pFirst;
                if ( v12->m_listDeviceVolumes.m_pFirst )
                {
                  do
                  {
                    v43 = 0;
                    do
                    {
                      v44 = v43++;
                      v44 <<= 6;
                      *(__m128 *)((char *)v42->mxDirect[0].Next.vector + v44) = 0i64;
                      *(_OWORD *)((char *)&v42->mxDirect[0].Next.aVolumes[4] + v44) = 0i64;
                    }
                    while ( v43 < v32 );
                    v42->mxAttenuations.dry.fNext = 0.0;
                    v42->mxAttenuations.userDef.fNext = 0.0;
                    v42->mxAttenuations.gameDef.fNext = 0.0;
                    v42 = v42->pNextLightItem;
                  }
                  while ( v42 );
                }
                v45 = *((_BYTE *)v9 + 76);
                if ( v45 & 2 || !(v45 & 4) )
                {
                  *((_BYTE *)v9 + 76) = v45 | 2;
                  *out_bAudible = 0;
                }
              }
            }
            if ( v13->m_uRegisteredNotif & 0x10 )
            {
              v46 = v13->m_UserParams.m_PlayingID;
              v47 = AkDeviceInfo::GetOutputConfig(v38);
              CAkListener::DoSpeakerVolumeMatrixCallback(v46, v32, v56, v47, v38);
            }
            v48 = *((_BYTE *)v9 + 76);
            if ( v48 & 2 )
            {
              v49 = 0;
              do
              {
                v50 = v49++;
                v50 <<= 6;
                *(__m128 *)((char *)v38->mxDirect[0].Previous.vector + v50) = 0i64;
                *(_OWORD *)((char *)&v38->mxDirect[0].Previous.aVolumes[4] + v50) = 0i64;
              }
              while ( v49 < v32 );
              v38->mxAttenuations.dry.fPrev = 0.0;
              v38->mxAttenuations.gameDef.fPrev = 0.0;
              v38->mxAttenuations.userDef.fPrev = 0.0;
            }
            else if ( !(v48 & 4) )
            {
              v51 = 0;
              do
              {
                v52 = v51++;
                v52 <<= 6;
                *(__m128 *)((char *)v38->mxDirect[0].Previous.vector + v52) = *(__m128 *)((char *)v38->mxDirect[0].Next.vector
                                                                                        + v52);
                *(_OWORD *)((char *)&v38->mxDirect[0].Previous.aVolumes[4] + v52) = *(_OWORD *)((char *)&v38->mxDirect[0].Next.aVolumes[4]
                                                                                              + v52);
              }
              while ( v51 < v32 );
              v38->mxAttenuations.dry.fPrev = v38->mxAttenuations.dry.fNext;
              v38->mxAttenuations.userDef.fPrev = v38->mxAttenuations.userDef.fNext;
              v38->mxAttenuations.gameDef.fPrev = v38->mxAttenuations.gameDef.fNext;
            }
            v38 = v38->pNextLightItem;
            v8 = out_fLPF;
            v37 = out_fObsLPF;
          }
          while ( v38 );
        }
      }
      else
      {
        *out_bAudible = 0;
        v26 = 1;
      }
    }
    *((_BYTE *)v9 + 76) &= 0xBFu;
    *out_bNextSilent = v26;
  }
}

// File Line: 1501
// RVA: 0xA65930
AKRESULT __fastcall CAkVPLSrcCbxNodeBase::AddSrc(CAkVPLSrcCbxNodeBase *this, CAkPBI *in_pCtx, bool in_bActive)
{
  CAkVPLSrcCbxNodeBase *v3; // rdi
  bool v4; // bl
  CAkVPLSrcNode *v5; // rax
  AKRESULT result; // eax

  v3 = this;
  v4 = in_bActive;
  v5 = CAkVPLSrcNode::Create(in_pCtx);
  if ( v5 )
    result = CAkVPLSrcCbxNodeBase::AddSrc(v3, v5, v4);
  else
    result = 2;
  return result;
}

// File Line: 1510
// RVA: 0xA65980
__int64 __fastcall CAkVPLSrcCbxNodeBase::AddSrc(CAkVPLSrcCbxNodeBase *this, CAkVPLSrcNode *in_pSrc, bool in_bActive)
{
  CAkPBI *v3; // rbp
  bool v4; // r14
  CAkVPLSrcNode *v5; // rsi
  CAkVPLSrcCbxNodeBase *v6; // rbx
  AkBelowThresholdBehavior v7; // eax
  bool v8; // zf
  AkRayVolumeData *v9; // rax
  unsigned int v10; // edi
  AKRESULT v11; // eax
  int v12; // ebx

  v3 = in_pSrc->m_pCtx;
  v4 = in_bActive;
  v5 = in_pSrc;
  v6 = this;
  v3->m_pCbx = this;
  if ( in_bActive )
  {
    v7 = CAkPBI::GetVirtualBehavior(v3, &this->m_eVirtualBehavior);
    v8 = v6->m_arVolumeData.m_ulReserved == 0;
    v6->m_eBelowThresholdBehavior = v7;
    if ( v8 )
    {
      v9 = (AkRayVolumeData *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x24ui64);
      v6->m_arVolumeData.m_pItems = v9;
      if ( !v9 )
      {
        v10 = 2;
        goto LABEL_19;
      }
      v6->m_arVolumeData.m_ulReserved = 1;
    }
  }
  if ( v6->m_eBelowThresholdBehavior == AkBelowThresholdBehavior_ContinueToPlay
    || !CAkPBI::IsInitiallyUnderThreshold(v3, &v6->m_arVolumeData) )
  {
    goto LABEL_24;
  }
  if ( v6->m_eBelowThresholdBehavior == 1 )
  {
    v10 = 3;
LABEL_19:
    CAkVPLSrcNode::Term(v5, CtxDestroyReasonPlayFailed);
    v12 = g_LEngineDefaultPoolId;
    v5->vfptr->__vecDelDtor((CAkVPLNode *)&v5->vfptr, 0);
    AK::MemoryMgr::Free(v12, v5);
    return v10;
  }
  if ( v6->m_eVirtualBehavior == AkVirtualQueueBehavior_FromBeginning && v4 )
  {
    v10 = 1;
    if ( *((_BYTE *)v6 + 76) & 1 )
      CAkPBI::Virtualize(v3);
    *((_BYTE *)v6 + 76) &= 0xFEu;
  }
  else
  {
LABEL_24:
    v11 = CAkVPLSrcNode::FetchStreamedData(v5);
    v10 = v11;
    if ( v11 != 1 && v11 != 63 )
      goto LABEL_19;
  }
  if ( v4 )
  {
    *((_BYTE *)v6 + 76) ^= (*((_BYTE *)v6 + 76) ^ (*((_BYTE *)v3 + 375) >> 6)) & 2;
    v6->m_pSources[0] = v5;
  }
  else
  {
    v6->m_pSources[1] = v5;
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
  CAkVPLSrcCbxNode *v2; // rbx
  CAkVPLSrcNode *v3; // rcx
  CAkVPLSrcNode *v4; // rcx
  CAkVPLSrcNode *v5; // rdi
  int v6; // esi

  v2 = this;
  v3 = this->m_pSources[0];
  if ( v3 && in_pCtx == v3->m_pCtx )
  {
    if ( !(*((_BYTE *)v3 + 32) & 1) || ((unsigned int (*)(void))v3->vfptr[1].VirtualOn)() != 1 )
      v2->vfptr->Stop((CAkVPLSrcCbxNodeBase *)&v2->vfptr);
  }
  else
  {
    v4 = v2->m_pSources[1];
    if ( v4 && in_pCtx == v4->m_pCtx )
    {
      CAkVPLSrcNode::Term(v4, 0);
      v5 = v2->m_pSources[1];
      v6 = g_LEngineDefaultPoolId;
      if ( v5 )
      {
        v5->vfptr->__vecDelDtor((CAkVPLNode *)&v5->vfptr, 0);
        AK::MemoryMgr::Free(v6, v5);
      }
      v2->m_pSources[1] = 0i64;
    }
  }
}

// File Line: 1612
// RVA: 0xA672D0
void __fastcall CAkVPLSrcCbxNode::SeekSource(CAkVPLSrcCbxNode *this)
{
  CAkVPLSrcCbxNode *v1; // rdi
  CAkVPLSrcNode *v2; // rax
  CAkPBI *v3; // rax
  CAkVPLSrcNode *v4; // rax

  v1 = this;
  if ( *(_QWORD *)&this->m_eVirtualBehavior == 0x200000000i64 )
  {
    v2 = this->m_pSources[0];
    if ( v2 )
    {
      v3 = v2->m_pCtx;
      if ( v3 )
      {
        v3->m_uSeekPosition = 0;
        *((_BYTE *)v3 + 375) &= 0xF1u;
      }
    }
  }
  else
  {
    v4 = this->m_pSources[0];
    if ( v4 )
    {
      if ( *((_BYTE *)v4 + 32) & 1 )
      {
        this->m_cbxRec.m_LPF.vfptr->ReleaseBuffer((CAkVPLNode *)&this->m_cbxRec.m_LPF);
        if ( v1->m_cbxRec.m_LPF.vfptr->Seek((CAkVPLNode *)&v1->m_cbxRec.m_LPF.vfptr) != 1 )
          v1->vfptr->Stop((CAkVPLSrcCbxNodeBase *)&v1->vfptr);
      }
    }
  }
}

// File Line: 1656
// RVA: 0xA67030
char __fastcall CAkVPLSrcCbxNode::IsUsingThisSlot(CAkVPLSrcCbxNode *this, CAkUsageSlot *in_pUsageSlot)
{
  CAkUsageSlot *v2; // rbp
  unsigned int v3; // edi
  CAkEffectContextBase ***v4; // rsi
  CAkEffectContextBase **v5; // rbx
  AK::IAkPlugin *v6; // rax

  v2 = in_pUsageSlot;
  v3 = 0;
  v4 = (CAkEffectContextBase ***)this->m_cbxRec.m_pFilter;
  while ( 1 )
  {
    v5 = *v4;
    if ( *v4 )
    {
      if ( v5[3] )
      {
        v6 = (AK::IAkPlugin *)(*(__int64 (__fastcall **)(CAkEffectContextBase **))&(*v5)[3].m_dataArray.m_uLength)(*v4);
        if ( CAkEffectContextBase::IsUsingThisSlot(v5[3], v2, v6) )
          break;
      }
    }
    ++v3;
    ++v4;
    if ( v3 >= 4 )
      return 0;
  }
  return 1;
}

// File Line: 1667
// RVA: 0xA66FC0
char __fastcall CAkVPLSrcCbxNode::IsUsingThisSlot(CAkVPLSrcCbxNode *this, const char *in_pData)
{
  const char *v2; // rsi
  unsigned int v3; // ebx
  CAkVPLFilterNodeBase **v4; // rdi
  CAkEffectContextBase *v5; // rcx

  v2 = in_pData;
  v3 = 0;
  v4 = this->m_cbxRec.m_pFilter;
  while ( 1 )
  {
    if ( *v4 )
    {
      v5 = (CAkEffectContextBase *)&(*v4)->m_pInsertFXContext->vfptr;
      if ( v5 )
      {
        if ( CAkEffectContextBase::IsUsingThisSlot(v5, v2) )
          break;
      }
    }
    ++v3;
    ++v4;
    if ( v3 >= 4 )
      return 0;
  }
  return 1;
}

// File Line: 1678
// RVA: 0xA671B0
void __fastcall CAkVPLSrcCbxNode::RemovePipeline(CAkVPLSrcCbxNode *this, AkCtxDestroyReason in_eReason)
{
  CAkVPLSrcCbxNode *v2; // rbx
  CAkVPLSrcNode *v3; // rcx
  CAkVPLSrcNode *v4; // rdi
  int v5; // esi

  v2 = this;
  v3 = this->m_pSources[0];
  if ( v3 )
  {
    CAkVPLSrcNode::Term(v3, in_eReason);
    v4 = v2->m_pSources[0];
    v5 = g_LEngineDefaultPoolId;
    if ( v4 )
    {
      v4->vfptr->__vecDelDtor((CAkVPLNode *)&v4->vfptr, 0);
      AK::MemoryMgr::Free(v5, v4);
    }
    v2->m_pSources[0] = 0i64;
  }
  AkVPLSrcCbxRec::ClearVPL(&v2->m_cbxRec);
  CAkSrcLpFilter::Term(&v2->m_ObstructionLPF.m_LPF);
  *((_BYTE *)&v2->0 + 76) |= 1u;
}

// File Line: 1692
// RVA: 0xA671A0
void __fastcall CAkVPLSrcCbxNode::RelocateMedia(CAkVPLSrcCbxNode *this, char *in_pNewMedia, char *in_pOldMedia)
{
  CAkVPLPitchNode::RelocateMedia(&this->m_cbxRec.m_Pitch, in_pNewMedia, in_pOldMedia);
}

