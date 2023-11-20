// File Line: 63
// RVA: 0xA64060
void __fastcall CAkFeedbackDeviceMgr::~CAkFeedbackDeviceMgr(CAkFeedbackDeviceMgr *this)
{
  CAkFeedbackDeviceMgr *v1; // r14
  unsigned int v2; // ebx
  int v3; // esi
  CAkSplitterBus *v4; // rdi
  signed __int64 v5; // rbx
  signed __int64 v6; // rbp
  unsigned int i; // edi
  __int64 v8; // rcx
  void *v9; // rdx
  MapStruct<unsigned long,CAkSplitterBus *> *v10; // rdx

  v1 = this;
  v2 = 0;
  if ( this->m_aBusses.m_uLength )
  {
    do
    {
      v3 = g_LEngineDefaultPoolId;
      v4 = v1->m_aBusses.m_pItems[v2].item;
      if ( v4 )
      {
        CAkSplitterBus::~CAkSplitterBus(v1->m_aBusses.m_pItems[v2].item);
        AK::MemoryMgr::Free(v3, v4);
      }
      ++v2;
    }
    while ( v2 < v1->m_aBusses.m_uLength );
  }
  v5 = (signed __int64)v1->m_aPlayers;
  v6 = 4i64;
  do
  {
    for ( i = 0; i < *(_DWORD *)(v5 + 8); ++i )
    {
      v8 = *(_QWORD *)(*(_QWORD *)v5 + 16i64 * i + 8);
      if ( v8 )
      {
        (*(void (__fastcall **)(__int64, AkFXMemAlloc *))(*(_QWORD *)v8 + 8i64))(v8, &AkFXMemAlloc::m_instanceLower);
        *(_QWORD *)(*(_QWORD *)v5 + 16i64 * i + 8) = 0i64;
      }
    }
    v9 = *(void **)v5;
    if ( *(_QWORD *)v5 )
    {
      *(_DWORD *)(v5 + 8) = 0;
      AK::MemoryMgr::Free(g_DefaultPoolId, v9);
      *(_QWORD *)v5 = 0i64;
      *(_DWORD *)(v5 + 12) = 0;
    }
    v5 += 16i64;
    --v6;
  }
  while ( v6 );
  v10 = v1->m_aBusses.m_pItems;
  if ( v1->m_aBusses.m_pItems )
  {
    v1->m_aBusses.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v10);
    v1->m_aBusses.m_pItems = 0i64;
    v1->m_aBusses.m_ulReserved = 0;
  }
}

// File Line: 88
// RVA: 0xA64610
CAkFeedbackDeviceMgr *__fastcall CAkFeedbackDeviceMgr::Create()
{
  CAkFeedbackDeviceMgr *result; // rax

  result = CAkFeedbackDeviceMgr::s_pSingleton;
  if ( !CAkFeedbackDeviceMgr::s_pSingleton )
  {
    result = (CAkFeedbackDeviceMgr *)AK::MemoryMgr::Malloc(
                                       g_LEngineDefaultPoolId,
                                       (unsigned int)((_DWORD)CAkFeedbackDeviceMgr::s_pSingleton + 104));
    CAkFeedbackDeviceMgr::s_pSingleton = result;
    if ( result )
    {
      result->m_aBusses.m_pItems = 0i64;
      *(_QWORD *)&result->m_aBusses.m_uLength = 0i64;
      result->m_aPlayers[0].m_pItems = 0i64;
      *(_QWORD *)&result->m_aPlayers[0].m_uLength = 0i64;
      result->m_aPlayers[1].m_pItems = 0i64;
      *(_QWORD *)&result->m_aPlayers[1].m_uLength = 0i64;
      result->m_aPlayers[2].m_pItems = 0i64;
      *(_QWORD *)&result->m_aPlayers[2].m_uLength = 0i64;
      result->m_aPlayers[3].m_pItems = 0i64;
      *(_QWORD *)&result->m_aPlayers[3].m_uLength = 0i64;
      result->m_uLastStarvationTime = 0;
      *(_WORD *)&result->m_uPlayerMask = 0;
      *(_DWORD *)result->m_aPlayerToListener = 0;
      *(_QWORD *)result->m_aListenerToPlayer = 0i64;
      result->m_aListenerToPlayer[0] = 15;
      result = CAkFeedbackDeviceMgr::s_pSingleton;
    }
  }
  return result;
}

// File Line: 98
// RVA: 0xA64690
void CAkFeedbackDeviceMgr::Destroy(void)
{
  CAkFeedbackDeviceMgr *v0; // rbx
  int v1; // edi

  v0 = CAkFeedbackDeviceMgr::s_pSingleton;
  v1 = g_LEngineDefaultPoolId;
  if ( CAkFeedbackDeviceMgr::s_pSingleton )
  {
    CAkFeedbackDeviceMgr::~CAkFeedbackDeviceMgr(CAkFeedbackDeviceMgr::s_pSingleton);
    AK::MemoryMgr::Free(v1, v0);
  }
  CAkFeedbackDeviceMgr::s_pSingleton = 0i64;
}

// File Line: 104
// RVA: 0xA641E0
signed __int64 __fastcall CAkFeedbackDeviceMgr::AddPlayerFeedbackDevice(CAkFeedbackDeviceMgr *this, char in_iPlayerID, unsigned int in_iDeviceCompanyID, unsigned int in_iDevicePluginID, void *in_pDevice)
{
  unsigned int v5; // er13
  unsigned int v6; // edi
  __int64 v7; // r12
  CAkFeedbackDeviceMgr *v8; // rsi
  signed __int64 v9; // r15
  _DWORD *v10; // rax
  int v11; // ebx
  signed __int64 v12; // rcx
  IAkMotionMixBus **out_pMixNode; // r14
  MapStruct<unsigned long,CAkFeedbackDeviceMgr::DeviceBus> *v14; // rax
  _DWORD *v16; // rdi
  signed __int64 v17; // rax
  MapStruct<unsigned long,CAkSplitterBus *> *v18; // rdi
  AKRESULT v19; // ebp
  unsigned int v20; // eax
  unsigned __int8 v21; // cl
  unsigned int *v22; // rdx
  unsigned int in_iDeviceCompanyIDa; // [rsp+70h] [rbp+18h]

  in_iDeviceCompanyIDa = in_iDeviceCompanyID;
  v5 = in_iDevicePluginID;
  v6 = in_iDeviceCompanyID;
  v7 = (unsigned __int8)in_iPlayerID;
  v8 = this;
  CAkLEngine::EnableFeedbackPipeline();
  v9 = (signed __int64)v8 + 16 * (v7 + 1);
  v10 = *(_DWORD **)v9;
  v11 = v6 | (v5 << 16);
  v12 = *(_QWORD *)v9 + 16i64 * *(unsigned int *)(v9 + 8);
  if ( *(_QWORD *)v9 != v12 )
  {
    do
    {
      if ( *v10 == v11 )
        break;
      v10 += 4;
    }
    while ( v10 != (_DWORD *)v12 );
  }
  if ( v10 == (_DWORD *)v12 )
  {
    out_pMixNode = 0i64;
  }
  else
  {
    out_pMixNode = (IAkMotionMixBus **)(v10 + 2);
    if ( v10 != (_DWORD *)-8i64 )
      goto LABEL_11;
  }
  v14 = AkArray<MapStruct<unsigned long,CAkFeedbackDeviceMgr::DeviceBus>,MapStruct<unsigned long,CAkFeedbackDeviceMgr::DeviceBus> const &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::AddLast((AkArray<MapStruct<unsigned long,CAkFeedbackDeviceMgr::DeviceBus>,MapStruct<unsigned long,CAkFeedbackDeviceMgr::DeviceBus> const &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *)&(&v8->m_aBusses.m_pItems)[2 * (v7 + 1)]);
  if ( v14 )
  {
    v14->key = v11;
    out_pMixNode = &v14->item.m_pFinalBus;
  }
  if ( !out_pMixNode )
    return 2i64;
LABEL_11:
  if ( *out_pMixNode )
    return 1i64;
  if ( (unsigned int)CAkEffectsMgr::AllocFeedbackBus(v6, v5, &g_PDSettings, v7, out_pMixNode, in_pDevice) != 1 )
  {
    v16 = *(_DWORD **)v9;
    v17 = *(_QWORD *)v9 + 16i64 * *(unsigned int *)(v9 + 8);
    if ( *(_QWORD *)v9 != v17 )
    {
      do
      {
        if ( *v16 == v11 )
          break;
        v16 += 4;
      }
      while ( v16 != (_DWORD *)v17 );
      if ( v16 != (_DWORD *)v17 )
      {
        if ( (unsigned __int64)v16 < v17 - 16 )
          qmemcpy(
            v16,
            v16 + 4,
            8
          * (((((unsigned __int64)(v17 - 16 - (_QWORD)v16 - 1) >> 3) & 0xFFFFFFFFFFFFFFFEui64) + 2) & 0x1FFFFFFFFFFFFFFEi64));
        --*(_DWORD *)(v9 + 8);
      }
    }
    return 2i64;
  }
  v18 = v8->m_aBusses.m_pItems;
  v19 = 1;
  if ( v18 != &v18[v8->m_aBusses.m_uLength] )
  {
    while ( 1 )
    {
      v20 = ((__int64 (*)(void))(*out_pMixNode)->vfptr[2].GetPluginInfo)();
      v19 = CAkSplitterBus::AddBus(v18->item, v7, v11, v20);
      if ( v19 != 1 )
        break;
      ++v18;
      if ( v18 == &v8->m_aBusses.m_pItems[v8->m_aBusses.m_uLength] )
        goto LABEL_27;
    }
    CAkFeedbackDeviceMgr::RemovePlayerFeedbackDevice(v8, v7, in_iDeviceCompanyIDa, v5);
  }
LABEL_27:
  *(_WORD *)&v8->m_uPlayerMask = 0;
  v21 = 0;
  v22 = &v8->m_aPlayers[0].m_uLength;
  do
  {
    if ( *v22 )
    {
      v8->m_uLastPlayerIndex = v21 + 1;
      v8->m_uPlayerMask |= 1 << v21;
    }
    ++v21;
    v22 += 4;
  }
  while ( v21 < 4u );
  CAkURenderer::InvalidateAllMotionPBIs();
  return (unsigned int)v19;
}

// File Line: 150
// RVA: 0xA64BE0
void __fastcall CAkFeedbackDeviceMgr::RemovePlayerFeedbackDevice(CAkFeedbackDeviceMgr *this, char in_iPlayerID, unsigned int in_iDeviceCompanyID, unsigned int in_iDevicePluginID)
{
  CAkFeedbackDeviceMgr *v4; // rbx
  char v5; // bp
  unsigned int v6; // esi
  MapStruct<unsigned long,CAkSplitterBus *> **v7; // r14
  MapStruct<unsigned long,CAkSplitterBus *> *v8; // rax
  signed __int64 v9; // rcx
  CAkSplitterBus **v10; // r15
  MapStruct<unsigned long,CAkSplitterBus *> *i; // rdi
  MapStruct<unsigned long,CAkSplitterBus *> *v12; // rdi
  signed __int64 v13; // rax
  unsigned __int8 v14; // cl
  unsigned int *v15; // rdx

  v4 = this;
  v5 = in_iPlayerID;
  v6 = in_iDeviceCompanyID | (in_iDevicePluginID << 16);
  v7 = &(&this->m_aBusses.m_pItems)[2 * ((unsigned __int8)in_iPlayerID + 1i64)];
  v8 = *v7;
  v9 = (signed __int64)&(*v7)[*((unsigned int *)v7 + 2)];
  if ( *v7 != (MapStruct<unsigned long,CAkSplitterBus *> *)v9 )
  {
    do
    {
      if ( v8->key == v6 )
        break;
      ++v8;
    }
    while ( v8 != (MapStruct<unsigned long,CAkSplitterBus *> *)v9 );
    if ( v8 != (MapStruct<unsigned long,CAkSplitterBus *> *)v9 )
    {
      v10 = &v8->item;
      if ( v8 != (MapStruct<unsigned long,CAkSplitterBus *> *)-8i64 )
      {
        for ( i = v4->m_aBusses.m_pItems; i != &v4->m_aBusses.m_pItems[v4->m_aBusses.m_uLength]; ++i )
          CAkSplitterBus::RemoveBus(i->item, v5, v6);
        if ( *v10 )
        {
          (*(void (**)(void))&(*v10)->m_aBusses.m_pItems[3].m_DeviceID)();
          ((void (__fastcall *)(CAkSplitterBus *, AkFXMemAlloc *))(*v10)->m_aBusses.m_pItems->m_pFeedbackMixBus)(
            *v10,
            &AkFXMemAlloc::m_instanceLower);
          *v10 = 0i64;
        }
        v12 = *v7;
        v13 = (signed __int64)&(*v7)[*((unsigned int *)v7 + 2)];
        if ( *v7 != (MapStruct<unsigned long,CAkSplitterBus *> *)v13 )
        {
          do
          {
            if ( v12->key == v6 )
              break;
            ++v12;
          }
          while ( v12 != (MapStruct<unsigned long,CAkSplitterBus *> *)v13 );
          if ( v12 != (MapStruct<unsigned long,CAkSplitterBus *> *)v13 )
          {
            if ( (unsigned __int64)v12 < v13 - 16 )
              qmemcpy(
                v12,
                &v12[1],
                8
              * (((((unsigned __int64)(v13 - 16 - (_QWORD)v12 - 1) >> 3) & 0xFFFFFFFFFFFFFFFEui64) + 2) & 0x1FFFFFFFFFFFFFFEi64));
            --*((_DWORD *)v7 + 2);
          }
        }
        *(_WORD *)&v4->m_uPlayerMask = 0;
        v14 = 0;
        v15 = &v4->m_aPlayers[0].m_uLength;
        do
        {
          if ( *v15 )
          {
            v4->m_uLastPlayerIndex = v14 + 1;
            v4->m_uPlayerMask |= 1 << v14;
          }
          ++v14;
          v15 += 4;
        }
        while ( v14 < 4u );
        CAkURenderer::InvalidateAllMotionPBIs();
      }
    }
  }
}

// File Line: 182
// RVA: 0xA64AB0
bool __fastcall CAkFeedbackDeviceMgr::PrepareAudioProcessing(CAkFeedbackDeviceMgr *this, AkRunningVPL *io_runningVPL)
{
  AkRunningVPL *v2; // rbx
  CAkFeedbackDeviceMgr *v3; // rbp
  CAkVPLSrcNode *v4; // rdi
  CAkVPLNode *v5; // rsi
  unsigned __int16 v6; // bp
  void *v7; // r14
  AkPipelineBufferBase *v8; // rax
  AkFeedbackVPLData *v9; // rdi

  v2 = io_runningVPL;
  v3 = this;
  if ( io_runningVPL->bFeedbackVPL || !io_runningVPL->state.uValidFrames )
  {
    LOBYTE(v8) = 0;
  }
  else
  {
    v4 = io_runningVPL->pCbx->m_pSources[0];
    if ( v4 )
      v4 = (CAkVPLSrcNode *)v4->m_pCtx;
    if ( !(BYTE6(v4[9].m_pInput) & 0x40) )
      CAkPBI::ValidateFeedbackParameters((CAkPBI *)v4);
    v5 = v4[12].m_pInput;
    if ( v5 && v3->m_uLastPlayerIndex && (unsigned int)CAkFeedbackDeviceMgr::GetActivePlayers(v3, (CAkPBI *)v4) )
    {
      v6 = v2->state.uMaxFrames;
      v7 = v2->state.pData;
      v8 = (AkPipelineBufferBase *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 0x18ui64);
      v9 = (AkFeedbackVPLData *)v8;
      if ( v8 )
      {
        v8->pData = 0i64;
        if ( *(float *)&v5[1].vfptr > 0.1 && AkPipelineBufferBase::GetCachedBuffer(v8, v6, WORD2(v5[3].vfptr)) == 1 )
        {
          memmove(v9->LPFBuffer.pData, v7, 4 * v6 * (unsigned __int64)(HIWORD(v5[3].vfptr) & 0xF));
          v9->LPFBuffer.uValidFrames = v2->state.uValidFrames;
        }
        v2->pFeedbackData = v9;
        LOBYTE(v8) = 1;
      }
    }
    else
    {
      LOBYTE(v8) = 0;
    }
  }
  return (char)v8;
}

// File Line: 246
// RVA: 0xA644A0
void __fastcall CAkFeedbackDeviceMgr::CleanupAudioVPL(AkRunningVPL *io_runningVPL)
{
  AkRunningVPL *v1; // rbx
  AkFeedbackVPLData *v2; // rcx

  v1 = io_runningVPL;
  v2 = io_runningVPL->pFeedbackData;
  if ( v2->LPFBuffer.pData )
    AkPipelineBufferBase::ReleaseCachedBuffer(&v2->LPFBuffer);
  AK::MemoryMgr::Free(g_LEngineDefaultPoolId, v1->pFeedbackData);
  v1->pFeedbackData = 0i64;
}

// File Line: 261
// RVA: 0xA643D0
void __fastcall CAkFeedbackDeviceMgr::ApplyMotionLPF(AkRunningVPL *io_runningVPL)
{
  char v1; // di
  AkRunningVPL *v2; // rsi
  CAkVPLSrcNode *v3; // rbx
  CAkPBI *v4; // rbx
  AkFeedbackParams *v5; // rbx
  float v6; // xmm0_4
  CAkSrcLpFilter *v7; // rax
  float v8; // xmm1_4

  v1 = 0;
  v2 = io_runningVPL;
  v3 = io_runningVPL->pCbx->m_pSources[0];
  if ( v3 )
    v4 = v3->m_pCtx;
  else
    v4 = 0i64;
  if ( !(*((_BYTE *)v4 + 374) & 0x40) )
    CAkPBI::ValidateFeedbackParameters(v4);
  v5 = v4->m_pFeedbackInfo;
  if ( v5->m_LPF > 0.1
    && v2->pFeedbackData->LPFBuffer.pData
    && (v5->m_pLPFilter || AkFeedbackParams::CreateLowPassFilter(v5)) )
  {
    v6 = v5->m_LPF;
    v7 = v5->m_pLPFilter;
    v8 = 0.0;
    if ( v6 < 0.0 || (v8 = FLOAT_100_0, v6 > 100.0) )
      v6 = v8;
    if ( v6 != v7->m_InternalLPFState.fTargetLPFPar )
      v1 = 1;
    v7->m_InternalLPFState.bTargetDirty |= v1;
    v7->m_InternalLPFState.fTargetLPFPar = v6;
    CAkSrcLpFilter::Execute(v5->m_pLPFilter, (AkAudioBuffer *)&v2->pFeedbackData->LPFBuffer.pData);
  }
}

// File Line: 287
// RVA: 0xA64560
void __fastcall CAkFeedbackDeviceMgr::ConsumeVPL(CAkFeedbackDeviceMgr *this, AkRunningVPL *io_runningVPL)
{
  AkRunningVPL *v2; // rdi
  CAkFeedbackDeviceMgr *v3; // rsi
  CAkVPLSrcNode *v4; // rbx
  CAkVPLNode *v5; // rax
  CAkSplitterBus *v6; // rbp
  unsigned int v7; // eax

  v2 = io_runningVPL;
  v3 = this;
  v4 = io_runningVPL->pCbx->m_pSources[0];
  if ( v4 )
    v4 = (CAkVPLSrcNode *)v4->m_pCtx;
  if ( !(BYTE6(v4[9].m_pInput) & 0x40) )
    CAkPBI::ValidateFeedbackParameters((CAkPBI *)v4);
  v5 = v4[12].m_pInput;
  if ( v5 )
  {
    if ( v3->m_uLastPlayerIndex )
    {
      v6 = CAkFeedbackDeviceMgr::GetSplitter(v3, (unsigned int)v5->vfptr->ReleaseBuffer);
      if ( v6 )
      {
        v7 = CAkFeedbackDeviceMgr::GetActivePlayers(v3, (CAkPBI *)v4);
        if ( v2->bFeedbackVPL )
        {
          CAkSplitterBus::MixFeedbackBuffer(v6, v2, v7);
        }
        else if ( v2->pFeedbackData )
        {
          CAkSplitterBus::MixAudioBuffer(v6, v2, v7);
        }
      }
    }
  }
}

// File Line: 317
// RVA: 0xA64740
CAkSplitterBus *__fastcall CAkFeedbackDeviceMgr::GetSplitter(CAkFeedbackDeviceMgr *this, unsigned int in_idBus)
{
  MapStruct<unsigned long,CAkSplitterBus *> *v2; // rax
  unsigned int v3; // ebx
  CAkFeedbackDeviceMgr *v4; // r14
  MapStruct<unsigned long,CAkSplitterBus *> *v5; // r8
  CAkSplitterBus **v6; // rax
  CAkSplitterBus *v7; // rbp
  unsigned __int8 v8; // si
  signed __int64 v9; // rdi
  __int64 i; // rbx
  unsigned int v11; // eax
  CAkSplitterBus *v13; // rax
  int v14; // ebx

  v2 = this->m_aBusses.m_pItems;
  v3 = in_idBus;
  v4 = this;
  v5 = &this->m_aBusses.m_pItems[this->m_aBusses.m_uLength];
  if ( this->m_aBusses.m_pItems != v5 )
  {
    do
    {
      if ( v2->key == in_idBus )
        break;
      ++v2;
    }
    while ( v2 != v5 );
  }
  if ( v2 == v5 || (v6 = &v2->item) == 0i64 )
  {
    v13 = (CAkSplitterBus *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 0x18ui64);
    v7 = v13;
    if ( v13 )
    {
      CAkSplitterBus::CAkSplitterBus(v13);
      if ( CAkKeyArray<unsigned long,AkStateGroupInfo *,4>::Set(&v4->m_aBusses, v3, v7) )
        goto LABEL_7;
      v14 = g_LEngineDefaultPoolId;
      CAkSplitterBus::~CAkSplitterBus(v7);
      AK::MemoryMgr::Free(v14, v7);
    }
    return 0i64;
  }
  v7 = *v6;
LABEL_7:
  v8 = 0;
  if ( v4->m_uLastPlayerIndex )
  {
    do
    {
      v9 = (signed __int64)v4 + 16 * (v8 + 1i64);
      for ( i = *(_QWORD *)v9; i != *(_QWORD *)v9 + 16i64 * *(unsigned int *)(v9 + 8); i += 16i64 )
      {
        v11 = (*(__int64 (**)(void))(**(_QWORD **)(i + 8) + 120i64))();
        CAkSplitterBus::AddBus(v7, v8, *(_DWORD *)i, v11);
      }
      ++v8;
    }
    while ( v8 < v4->m_uLastPlayerIndex );
  }
  return v7;
}

// File Line: 352
// RVA: 0xA64D50
void __fastcall CAkFeedbackDeviceMgr::RenderData(CAkFeedbackDeviceMgr *this)
{
  unsigned __int8 v1; // r12
  unsigned int v2; // er13
  CAkFeedbackDeviceMgr *v3; // rsi
  unsigned int v4; // er15
  signed __int64 v5; // r14
  signed __int64 v6; // rbp
  signed __int64 v7; // rdi
  unsigned int i; // ebx
  AkAudioBufferBus *out_pAudioBuffer; // [rsp+70h] [rbp+8h]
  AkAudioBufferBus *out_pFeedbackBuffer; // [rsp+78h] [rbp+10h]

  v1 = 0;
  v2 = 0;
  v3 = this;
  if ( this->m_uLastPlayerIndex )
  {
    do
    {
      v4 = 0;
      v5 = (signed __int64)v3 + 16 * (v1 + 1i64);
      if ( *(_DWORD *)(v5 + 8) > 0u )
      {
        do
        {
          v6 = 16i64 * v4;
          v7 = v6 + *(_QWORD *)v5;
          if ( *(_QWORD *)(v7 + 8) )
          {
            for ( i = 0; i < v3->m_aBusses.m_uLength; ++i )
            {
              CAkSplitterBus::GetBuffer(
                v3->m_aBusses.m_pItems[i].item,
                v1,
                *(_DWORD *)(*(_QWORD *)v5 + v6),
                &out_pAudioBuffer,
                &out_pFeedbackBuffer);
              if ( out_pAudioBuffer && out_pAudioBuffer->uValidFrames > 0u )
                (*(void (**)(void))(**(_QWORD **)(v7 + 8) + 56i64))();
              if ( out_pFeedbackBuffer && out_pFeedbackBuffer->uValidFrames > 0u )
                (*(void (**)(void))(**(_QWORD **)(v7 + 8) + 64i64))();
            }
            (*(void (**)(void))(**(_QWORD **)(v7 + 8) + 72i64))();
          }
          ++v4;
        }
        while ( v4 < *(_DWORD *)(v5 + 8) );
      }
      ++v1;
    }
    while ( v1 < v3->m_uLastPlayerIndex );
  }
  if ( v3->m_aBusses.m_uLength > 0 )
  {
    do
      CAkSplitterBus::ReleaseBuffers(v3->m_aBusses.m_pItems[v2++].item);
    while ( v2 < v3->m_aBusses.m_uLength );
  }
}

// File Line: 404
// RVA: 0xA64930
void __fastcall CAkFeedbackDeviceMgr::HandleStarvation(CAkFeedbackDeviceMgr *this)
{
  __int64 v1; // rdx
  unsigned int v2; // esi
  CAkFeedbackDeviceMgr *v3; // rbp
  unsigned int v4; // ebx
  CAkSplitterBus *v5; // rcx
  unsigned int v6; // edx
  unsigned int v7; // ecx

  LOBYTE(v1) = 0;
  v2 = 0;
  v3 = this;
  if ( this->m_uLastPlayerIndex )
  {
    while ( !(_BYTE)v1 )
    {
      v4 = 0;
      if ( *(&v3->m_aBusses.m_uLength + 4 * (v2 + 1i64)) )
      {
        do
        {
          if ( (_BYTE)v1 )
            break;
          v5 = (&v3->m_aBusses.m_pItems)[2 * (v2 + 1i64)][v4].item;
          if ( v5 )
            v1 = ((unsigned __int8 (*)(void))v5->m_aBusses.m_pItems[4].m_pFeedbackMixBus)();
          ++v4;
        }
        while ( v4 < *(&v3->m_aBusses.m_uLength + 4 * (v2 + 1i64)) );
      }
      if ( ++v2 >= (unsigned __int8)v3->m_uLastPlayerIndex )
      {
        if ( !(_BYTE)v1 )
          return;
        break;
      }
    }
    v6 = v3->m_uLastStarvationTime;
    v7 = g_pAudioMgr->m_uBufferTick;
    if ( !v6 || v7 - v6 > 8 )
      v3->m_uLastStarvationTime = v7;
  }
}

// File Line: 432
// RVA: 0xA644E0
void __fastcall CAkFeedbackDeviceMgr::CommandTick(CAkFeedbackDeviceMgr *this)
{
  unsigned int v1; // esi
  CAkFeedbackDeviceMgr *v2; // rbp
  unsigned int v3; // ebx
  CAkSplitterBus *v4; // rcx

  v1 = 0;
  v2 = this;
  if ( this->m_uLastPlayerIndex )
  {
    do
    {
      v3 = 0;
      if ( *(&v2->m_aBusses.m_uLength + 4 * (v1 + 1i64)) )
      {
        do
        {
          v4 = (&v2->m_aBusses.m_pItems)[2 * (v1 + 1i64)][v3].item;
          if ( v4 )
            ((void (*)(void))v4->m_aBusses.m_pItems[3].m_pFeedbackMixBus)();
          ++v3;
        }
        while ( v3 < *(&v2->m_aBusses.m_uLength + 4 * (v1 + 1i64)) );
      }
      ++v1;
    }
    while ( v1 < (unsigned __int8)v2->m_uLastPlayerIndex );
  }
}

// File Line: 446
// RVA: 0xA64A80
char __fastcall CAkFeedbackDeviceMgr::IsFeedbackEnabled(CAkFeedbackDeviceMgr *this)
{
  signed int v1; // er8
  unsigned __int8 v2; // dl

  v1 = (unsigned __int8)this->m_uLastPlayerIndex;
  v2 = 0;
  if ( v1 <= 0 )
    return 0;
  while ( !this->m_aPlayers[v2].m_uLength )
  {
    if ( ++v2 >= v1 )
      return 0;
  }
  return 1;
}

// File Line: 458
// RVA: 0xA649D0
char __fastcall CAkFeedbackDeviceMgr::IsDeviceActive(CAkFeedbackDeviceMgr *this, unsigned int in_iDeviceCompanyID, unsigned int in_iDevicePluginID)
{
  unsigned int v3; // edi
  CAkFeedbackDeviceMgr *v4; // rsi
  unsigned int v5; // ebx
  MapStruct<unsigned long,CAkSplitterBus *> *v6; // rax
  signed __int64 v7; // rcx

  v3 = 0;
  v4 = this;
  v5 = in_iDeviceCompanyID | (in_iDevicePluginID << 16);
  if ( !this->m_uLastPlayerIndex )
    return 0;
  while ( 1 )
  {
    v6 = (&v4->m_aBusses.m_pItems)[2 * (v3 + 1i64)];
    v7 = (signed __int64)&v6[*(&v4->m_aBusses.m_uLength + 4 * (v3 + 1i64))];
    if ( v6 != (MapStruct<unsigned long,CAkSplitterBus *> *)v7 )
    {
      do
      {
        if ( v6->key == v5 )
          break;
        ++v6;
      }
      while ( v6 != (MapStruct<unsigned long,CAkSplitterBus *> *)v7 );
      if ( v6 != (MapStruct<unsigned long,CAkSplitterBus *> *)v7
        && v6 != (MapStruct<unsigned long,CAkSplitterBus *> *)-8i64
        && (*(unsigned __int8 (**)(void))&v6->item->m_aBusses.m_pItems[4].m_DeviceID)() )
      {
        break;
      }
    }
    if ( ++v3 >= (unsigned __int8)v4->m_uLastPlayerIndex )
      return 0;
  }
  return 1;
}

// File Line: 545
// RVA: 0xA64F60
void __fastcall CAkFeedbackDeviceMgr::Stop(CAkFeedbackDeviceMgr *this)
{
  unsigned int v1; // esi
  CAkFeedbackDeviceMgr *v2; // rbp
  unsigned int v3; // ebx
  CAkSplitterBus *v4; // rcx

  v1 = 0;
  v2 = this;
  if ( this->m_uLastPlayerIndex )
  {
    do
    {
      v3 = 0;
      if ( *(&v2->m_aBusses.m_uLength + 4 * (v1 + 1i64)) )
      {
        do
        {
          v4 = (&v2->m_aBusses.m_pItems)[2 * (v1 + 1i64)][v3].item;
          if ( v4 )
            (*(void (**)(void))&v4->m_aBusses.m_pItems[3].m_DeviceID)();
          ++v3;
        }
        while ( v3 < *(&v2->m_aBusses.m_uLength + 4 * (v1 + 1i64)) );
      }
      ++v1;
    }
    while ( v1 < (unsigned __int8)v2->m_uLastPlayerIndex );
  }
}

// File Line: 559
// RVA: 0xA646E0
__int64 __fastcall CAkFeedbackDeviceMgr::GetActivePlayers(CAkFeedbackDeviceMgr *this, CAkPBI *pPBI)
{
  CAkRegisteredObj *v2; // rax
  signed int v3; // er10
  unsigned int v4; // er9
  unsigned __int8 v5; // dl
  CAkFeedbackDeviceMgr *v6; // rbx
  unsigned int v7; // er11
  char v8; // cl

  v2 = pPBI->m_pGameObj;
  v3 = (unsigned __int8)this->m_uLastPlayerIndex;
  v4 = 0;
  v5 = 0;
  v6 = this;
  if ( v3 > 0 )
  {
    v8 = 0;
    do
    {
      v7 = CAkListener::m_uFeedbackMask & v2->m_PosKeep.m_uListenerMask;
      if ( _bittest((const signed int *)&v7, (unsigned __int8)v6->m_aPlayerToListener[v5]) )
        v4 |= 1 << v8;
      v8 = ++v5;
    }
    while ( v5 < v3 );
  }
  return v4;
}

// File Line: 576
// RVA: 0xA64EC0
void __fastcall CAkFeedbackDeviceMgr::StartOutputCapture(CAkFeedbackDeviceMgr *this, const wchar_t *in_CaptureFileName)
{
  unsigned __int8 v2; // si
  const wchar_t *v3; // rbp
  CAkFeedbackDeviceMgr *v4; // r14
  unsigned int v5; // ebx
  CAkSplitterBus *v6; // rcx

  v2 = 0;
  v3 = in_CaptureFileName;
  v4 = this;
  if ( this->m_uLastPlayerIndex )
  {
    do
    {
      v5 = 0;
      if ( *(&v4->m_aBusses.m_uLength + 4 * (v2 + 1i64)) )
      {
        do
        {
          v6 = (&v4->m_aBusses.m_pItems)[2 * (v2 + 1i64)][v5].item;
          if ( v6 )
            (*(void (__fastcall **)(CAkSplitterBus *, const wchar_t *))&v6->m_aBusses.m_pItems[5].m_DeviceID)(v6, v3);
          ++v5;
        }
        while ( v5 < *(&v4->m_aBusses.m_uLength + 4 * (v2 + 1i64)) );
      }
      ++v2;
    }
    while ( v2 < v4->m_uLastPlayerIndex );
  }
}

// File Line: 590
// RVA: 0xA64FE0
void __fastcall CAkFeedbackDeviceMgr::StopOutputCapture(CAkFeedbackDeviceMgr *this)
{
  unsigned __int8 v1; // si
  CAkFeedbackDeviceMgr *v2; // rbp
  unsigned int v3; // ebx
  CAkSplitterBus *v4; // rcx

  v1 = 0;
  v2 = this;
  if ( this->m_uLastPlayerIndex )
  {
    do
    {
      v3 = 0;
      if ( *(&v2->m_aBusses.m_uLength + 4 * (v1 + 1i64)) )
      {
        do
        {
          v4 = (&v2->m_aBusses.m_pItems)[2 * (v1 + 1i64)][v3].item;
          if ( v4 )
            ((void (*)(void))v4->m_aBusses.m_pItems[6].m_pAudioMixBus)();
          ++v3;
        }
        while ( v3 < *(&v2->m_aBusses.m_uLength + 4 * (v1 + 1i64)) );
      }
      ++v1;
    }
    while ( v1 < v2->m_uLastPlayerIndex );
  }
}

