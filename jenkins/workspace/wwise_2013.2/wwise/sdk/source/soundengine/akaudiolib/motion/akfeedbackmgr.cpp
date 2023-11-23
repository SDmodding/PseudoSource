// File Line: 63
// RVA: 0xA64060
void __fastcall CAkFeedbackDeviceMgr::~CAkFeedbackDeviceMgr(CAkFeedbackDeviceMgr *this)
{
  unsigned int i; // ebx
  int v3; // esi
  CAkSplitterBus *item; // rdi
  CAkKeyArray<unsigned long,CAkFeedbackDeviceMgr::DeviceBus,1> *m_aPlayers; // rbx
  __int64 v6; // rbp
  unsigned int j; // edi
  IAkMotionMixBus *m_pFinalBus; // rcx
  MapStruct<unsigned long,CAkFeedbackDeviceMgr::DeviceBus> *m_pItems; // rdx
  MapStruct<unsigned long,CAkSplitterBus *> *v10; // rdx

  for ( i = 0; i < this->m_aBusses.m_uLength; ++i )
  {
    v3 = g_LEngineDefaultPoolId;
    item = this->m_aBusses.m_pItems[i].item;
    if ( item )
    {
      CAkSplitterBus::~CAkSplitterBus(this->m_aBusses.m_pItems[i].item);
      AK::MemoryMgr::Free(v3, item);
    }
  }
  m_aPlayers = this->m_aPlayers;
  v6 = 4i64;
  do
  {
    for ( j = 0; j < m_aPlayers->m_uLength; ++j )
    {
      m_pFinalBus = m_aPlayers->m_pItems[j].item.m_pFinalBus;
      if ( m_pFinalBus )
      {
        m_pFinalBus->vfptr->Term(m_pFinalBus, &AkFXMemAlloc::m_instanceLower);
        m_aPlayers->m_pItems[j].item.m_pFinalBus = 0i64;
      }
    }
    m_pItems = m_aPlayers->m_pItems;
    if ( m_aPlayers->m_pItems )
    {
      m_aPlayers->m_uLength = 0;
      AK::MemoryMgr::Free(g_DefaultPoolId, m_pItems);
      m_aPlayers->m_pItems = 0i64;
      m_aPlayers->m_ulReserved = 0;
    }
    ++m_aPlayers;
    --v6;
  }
  while ( v6 );
  v10 = this->m_aBusses.m_pItems;
  if ( this->m_aBusses.m_pItems )
  {
    this->m_aBusses.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v10);
    this->m_aBusses.m_pItems = 0i64;
    this->m_aBusses.m_ulReserved = 0;
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
      return CAkFeedbackDeviceMgr::s_pSingleton;
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
__int64 __fastcall CAkFeedbackDeviceMgr::AddPlayerFeedbackDevice(
        CAkFeedbackDeviceMgr *this,
        unsigned __int8 in_iPlayerID,
        unsigned int in_iDeviceCompanyID,
        unsigned int in_iDevicePluginID,
        void *in_pDevice)
{
  __int64 v7; // r12
  CAkKeyArray<unsigned long,CAkFeedbackDeviceMgr::DeviceBus,1> *v9; // r15
  MapStruct<unsigned long,CAkFeedbackDeviceMgr::DeviceBus> *m_pItems; // rax
  unsigned int v11; // ebx
  __int64 v12; // rcx
  AK::IAkPlugin **out_pMixNode; // r14
  MapStruct<unsigned long,CAkFeedbackDeviceMgr::DeviceBus> *v14; // rax
  MapStruct<unsigned long,CAkFeedbackDeviceMgr::DeviceBus> *v16; // rdi
  __int64 v17; // rax
  MapStruct<unsigned long,CAkSplitterBus *> *v18; // rdi
  AKRESULT v19; // ebp
  unsigned int v20; // eax
  unsigned __int8 v21; // cl
  unsigned int *p_m_uLength; // rdx

  v7 = in_iPlayerID;
  CAkLEngine::EnableFeedbackPipeline();
  v9 = &this->m_aPlayers[v7];
  m_pItems = v9->m_pItems;
  v11 = in_iDeviceCompanyID | (in_iDevicePluginID << 16);
  v12 = (__int64)&v9->m_pItems[v9->m_uLength];
  if ( v9->m_pItems != (MapStruct<unsigned long,CAkFeedbackDeviceMgr::DeviceBus> *)v12 )
  {
    do
    {
      if ( m_pItems->key == v11 )
        break;
      ++m_pItems;
    }
    while ( m_pItems != (MapStruct<unsigned long,CAkFeedbackDeviceMgr::DeviceBus> *)v12 );
  }
  if ( m_pItems == (MapStruct<unsigned long,CAkFeedbackDeviceMgr::DeviceBus> *)v12 )
  {
    out_pMixNode = 0i64;
  }
  else
  {
    out_pMixNode = &m_pItems->item.m_pFinalBus;
    if ( m_pItems != (MapStruct<unsigned long,CAkFeedbackDeviceMgr::DeviceBus> *)-8i64 )
      goto LABEL_11;
  }
  v14 = AkArray<MapStruct<unsigned long,CAkFeedbackDeviceMgr::DeviceBus>,MapStruct<unsigned long,CAkFeedbackDeviceMgr::DeviceBus> const &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::AddLast(&this->m_aPlayers[v7]);
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
  if ( (unsigned int)CAkEffectsMgr::AllocFeedbackBus(
                       in_iDeviceCompanyID,
                       in_iDevicePluginID,
                       &g_PDSettings,
                       v7,
                       out_pMixNode,
                       in_pDevice) != 1 )
  {
    v16 = v9->m_pItems;
    v17 = (__int64)&v9->m_pItems[v9->m_uLength];
    if ( v9->m_pItems != (MapStruct<unsigned long,CAkFeedbackDeviceMgr::DeviceBus> *)v17 )
    {
      do
      {
        if ( v16->key == v11 )
          break;
        ++v16;
      }
      while ( v16 != (MapStruct<unsigned long,CAkFeedbackDeviceMgr::DeviceBus> *)v17 );
      if ( v16 != (MapStruct<unsigned long,CAkFeedbackDeviceMgr::DeviceBus> *)v17 )
      {
        if ( (unsigned __int64)v16 < v17 - 16 )
          qmemcpy(
            v16,
            &v16[1],
            8
          * (((((unsigned __int64)(v17 - 16 - (_QWORD)v16 - 1) >> 3) & 0xFFFFFFFFFFFFFFFEui64) + 2) & 0x1FFFFFFFFFFFFFFEi64));
        --v9->m_uLength;
      }
    }
    return 2i64;
  }
  v18 = this->m_aBusses.m_pItems;
  v19 = AK_Success;
  if ( v18 != &v18[this->m_aBusses.m_uLength] )
  {
    while ( 1 )
    {
      v20 = ((__int64 (__fastcall *)(AK::IAkPlugin *))(*out_pMixNode)->vfptr[2].GetPluginInfo)(*out_pMixNode);
      v19 = CAkSplitterBus::AddBus(v18->item, v7, v11, v20);
      if ( v19 != AK_Success )
        break;
      if ( ++v18 == &this->m_aBusses.m_pItems[this->m_aBusses.m_uLength] )
        goto LABEL_27;
    }
    CAkFeedbackDeviceMgr::RemovePlayerFeedbackDevice(this, v7, in_iDeviceCompanyID, in_iDevicePluginID);
  }
LABEL_27:
  *(_WORD *)&this->m_uPlayerMask = 0;
  v21 = 0;
  p_m_uLength = &this->m_aPlayers[0].m_uLength;
  do
  {
    if ( *p_m_uLength )
    {
      this->m_uLastPlayerIndex = v21 + 1;
      this->m_uPlayerMask |= 1 << v21;
    }
    ++v21;
    p_m_uLength += 4;
  }
  while ( v21 < 4u );
  CAkURenderer::InvalidateAllMotionPBIs();
  return (unsigned int)v19;
}  p_m_uLength += 4;
  }
  while ( v21 < 4u );
  CAkURenderer::InvalidateAllMotionPBIs();
  return (unsigned 

// File Line: 150
// RVA: 0xA64BE0
void __fastcall CAkFeedbackDeviceMgr::RemovePlayerFeedbackDevice(
        CAkFeedbackDeviceMgr *this,
        unsigned __int8 in_iPlayerID,
        unsigned int in_iDeviceCompanyID,
        unsigned int in_iDevicePluginID)
{
  unsigned int v6; // esi
  CAkKeyArray<unsigned long,CAkFeedbackDeviceMgr::DeviceBus,1> *v7; // r14
  MapStruct<unsigned long,CAkFeedbackDeviceMgr::DeviceBus> *m_pItems; // rax
  __int64 v9; // rcx
  CAkFeedbackDeviceMgr::DeviceBus *p_item; // r15
  MapStruct<unsigned long,CAkSplitterBus *> *i; // rdi
  MapStruct<unsigned long,CAkFeedbackDeviceMgr::DeviceBus> *v12; // rdi
  __int64 v13; // rax
  unsigned __int8 v14; // cl
  unsigned int *p_m_uLength; // rdx

  v6 = in_iDeviceCompanyID | (in_iDevicePluginID << 16);
  v7 = &this->m_aPlayers[in_iPlayerID];
  m_pItems = v7->m_pItems;
  v9 = (__int64)&v7->m_pItems[v7->m_uLength];
  if ( v7->m_pItems != (MapStruct<unsigned long,CAkFeedbackDeviceMgr::DeviceBus> *)v9 )
  {
    do
    {
      if ( m_pItems->key == v6 )
        break;
      ++m_pItems;
    }
    while ( m_pItems != (MapStruct<unsigned long,CAkFeedbackDeviceMgr::DeviceBus> *)v9 );
    if ( m_pItems != (MapStruct<unsigned long,CAkFeedbackDeviceMgr::DeviceBus> *)v9 )
    {
      p_item = &m_pItems->item;
      if ( m_pItems != (MapStruct<unsigned long,CAkFeedbackDeviceMgr::DeviceBus> *)-8i64 )
      {
        for ( i = this->m_aBusses.m_pItems; i != &this->m_aBusses.m_pItems[this->m_aBusses.m_uLength]; ++i )
          CAkSplitterBus::RemoveBus(i->item, in_iPlayerID, v6);
        if ( p_item->m_pFinalBus )
        {
          ((void (__fastcall *)(IAkMotionMixBus *))p_item->m_pFinalBus->vfptr[1].RelocateMedia)(p_item->m_pFinalBus);
          p_item->m_pFinalBus->vfptr->Term(p_item->m_pFinalBus, &AkFXMemAlloc::m_instanceLower);
          p_item->m_pFinalBus = 0i64;
        }
        v12 = v7->m_pItems;
        v13 = (__int64)&v7->m_pItems[v7->m_uLength];
        if ( v7->m_pItems != (MapStruct<unsigned long,CAkFeedbackDeviceMgr::DeviceBus> *)v13 )
        {
          do
          {
            if ( v12->key == v6 )
              break;
            ++v12;
          }
          while ( v12 != (MapStruct<unsigned long,CAkFeedbackDeviceMgr::DeviceBus> *)v13 );
          if ( v12 != (MapStruct<unsigned long,CAkFeedbackDeviceMgr::DeviceBus> *)v13 )
          {
            if ( (unsigned __int64)v12 < v13 - 16 )
              qmemcpy(
                v12,
                &v12[1],
                8
              * (((((unsigned __int64)(v13 - 16 - (_QWORD)v12 - 1) >> 3) & 0xFFFFFFFFFFFFFFFEui64) + 2) & 0x1FFFFFFFFFFFFFFEi64));
            --v7->m_uLength;
          }
        }
        *(_WORD *)&this->m_uPlayerMask = 0;
        v14 = 0;
        p_m_uLength = &this->m_aPlayers[0].m_uLength;
        do
        {
          if ( *p_m_uLength )
          {
            this->m_uLastPlayerIndex = v14 + 1;
            this->m_uPlayerMask |= 1 << v14;
          }
          ++v14;
          p_m_uLength += 4;
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
  CAkVPLSrcNode *v4; // rdi
  CAkVPLNode *m_pInput; // rsi
  unsigned __int16 uMaxFrames; // bp
  void *pData; // r14
  AkPipelineBufferBase *v8; // rax
  AkFeedbackVPLData *v9; // rdi

  if ( io_runningVPL->bFeedbackVPL || !io_runningVPL->state.uValidFrames )
  {
    LOBYTE(v8) = 0;
  }
  else
  {
    v4 = io_runningVPL->pCbx->m_pSources[0];
    if ( v4 )
      v4 = (CAkVPLSrcNode *)v4->m_pCtx;
    if ( (BYTE6(v4[9].m_pInput) & 0x40) == 0 )
      CAkPBI::ValidateFeedbackParameters((CAkPBI *)v4);
    m_pInput = v4[12].m_pInput;
    if ( m_pInput
      && this->m_uLastPlayerIndex
      && (unsigned int)CAkFeedbackDeviceMgr::GetActivePlayers(this, (CAkPBI *)v4) )
    {
      uMaxFrames = io_runningVPL->state.uMaxFrames;
      pData = io_runningVPL->state.pData;
      v8 = (AkPipelineBufferBase *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 0x18ui64);
      v9 = (AkFeedbackVPLData *)v8;
      if ( v8 )
      {
        v8->pData = 0i64;
        if ( *(float *)&m_pInput[1].vfptr > 0.1
          && AkPipelineBufferBase::GetCachedBuffer(v8, uMaxFrames, WORD2(m_pInput[3].vfptr)) == AK_Success )
        {
          memmove(v9->LPFBuffer.pData, pData, 4 * uMaxFrames * (unsigned __int64)(HIWORD(m_pInput[3].vfptr) & 0xF));
          v9->LPFBuffer.uValidFrames = io_runningVPL->state.uValidFrames;
        }
        io_runningVPL->pFeedbackData = v9;
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
  AkFeedbackVPLData *pFeedbackData; // rcx

  pFeedbackData = io_runningVPL->pFeedbackData;
  if ( pFeedbackData->LPFBuffer.pData )
    AkPipelineBufferBase::ReleaseCachedBuffer(&pFeedbackData->LPFBuffer);
  AK::MemoryMgr::Free(g_LEngineDefaultPoolId, io_runningVPL->pFeedbackData);
  io_runningVPL->pFeedbackData = 0i64;
}

// File Line: 261
// RVA: 0xA643D0
void __fastcall CAkFeedbackDeviceMgr::ApplyMotionLPF(AkRunningVPL *io_runningVPL)
{
  char v1; // di
  CAkVPLSrcNode *v3; // rbx
  CAkPBI *m_pCtx; // rbx
  AkFeedbackParams *m_pFeedbackInfo; // rbx
  float m_LPF; // xmm0_4
  CAkSrcLpFilter *m_pLPFilter; // rax
  float v8; // xmm1_4

  v1 = 0;
  v3 = io_runningVPL->pCbx->m_pSources[0];
  if ( v3 )
    m_pCtx = v3->m_pCtx;
  else
    m_pCtx = 0i64;
  if ( (*((_BYTE *)m_pCtx + 374) & 0x40) == 0 )
    CAkPBI::ValidateFeedbackParameters(m_pCtx);
  m_pFeedbackInfo = m_pCtx->m_pFeedbackInfo;
  if ( m_pFeedbackInfo->m_LPF > 0.1
    && io_runningVPL->pFeedbackData->LPFBuffer.pData
    && (m_pFeedbackInfo->m_pLPFilter || AkFeedbackParams::CreateLowPassFilter(m_pFeedbackInfo)) )
  {
    m_LPF = m_pFeedbackInfo->m_LPF;
    m_pLPFilter = m_pFeedbackInfo->m_pLPFilter;
    v8 = 0.0;
    if ( m_LPF < 0.0 || (v8 = FLOAT_100_0, m_LPF > 100.0) )
      m_LPF = v8;
    if ( m_LPF != m_pLPFilter->m_InternalLPFState.fTargetLPFPar )
      v1 = 1;
    m_pLPFilter->m_InternalLPFState.bTargetDirty |= v1;
    m_pLPFilter->m_InternalLPFState.fTargetLPFPar = m_LPF;
    CAkSrcLpFilter::Execute(m_pFeedbackInfo->m_pLPFilter, &io_runningVPL->pFeedbackData->LPFBuffer);
  }
}

// File Line: 287
// RVA: 0xA64560
void __fastcall CAkFeedbackDeviceMgr::ConsumeVPL(CAkFeedbackDeviceMgr *this, AkRunningVPL *io_runningVPL)
{
  CAkVPLSrcNode *v4; // rbx
  CAkVPLNode *m_pInput; // rax
  CAkSplitterBus *Splitter; // rbp
  unsigned int ActivePlayers; // eax

  v4 = io_runningVPL->pCbx->m_pSources[0];
  if ( v4 )
    v4 = (CAkVPLSrcNode *)v4->m_pCtx;
  if ( (BYTE6(v4[9].m_pInput) & 0x40) == 0 )
    CAkPBI::ValidateFeedbackParameters((CAkPBI *)v4);
  m_pInput = v4[12].m_pInput;
  if ( m_pInput )
  {
    if ( this->m_uLastPlayerIndex )
    {
      Splitter = CAkFeedbackDeviceMgr::GetSplitter(this, (unsigned int)m_pInput->vfptr->ReleaseBuffer);
      if ( Splitter )
      {
        ActivePlayers = CAkFeedbackDeviceMgr::GetActivePlayers(this, (CAkPBI *)v4);
        if ( io_runningVPL->bFeedbackVPL )
        {
          CAkSplitterBus::MixFeedbackBuffer(Splitter, io_runningVPL, ActivePlayers);
        }
        else if ( io_runningVPL->pFeedbackData )
        {
          CAkSplitterBus::MixAudioBuffer(Splitter, io_runningVPL, ActivePlayers);
        }
      }
    }
  }
}

// File Line: 317
// RVA: 0xA64740
CAkSplitterBus *__fastcall CAkFeedbackDeviceMgr::GetSplitter(CAkFeedbackDeviceMgr *this, unsigned int in_idBus)
{
  MapStruct<unsigned long,CAkSplitterBus *> *m_pItems; // rax
  MapStruct<unsigned long,CAkSplitterBus *> *v5; // r8
  CAkSplitterBus **p_item; // rax
  CAkSplitterBus *v7; // rbp
  unsigned __int8 i; // si
  CAkKeyArray<unsigned long,CAkFeedbackDeviceMgr::DeviceBus,1> *v9; // rdi
  MapStruct<unsigned long,CAkFeedbackDeviceMgr::DeviceBus> *j; // rbx
  unsigned int v11; // eax
  CAkSplitterBus *v13; // rax
  int v14; // ebx

  m_pItems = this->m_aBusses.m_pItems;
  v5 = &this->m_aBusses.m_pItems[this->m_aBusses.m_uLength];
  if ( this->m_aBusses.m_pItems != v5 )
  {
    do
    {
      if ( m_pItems->key == in_idBus )
        break;
      ++m_pItems;
    }
    while ( m_pItems != v5 );
  }
  if ( m_pItems == v5 || (p_item = &m_pItems->item) == 0i64 )
  {
    v13 = (CAkSplitterBus *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 0x18ui64);
    v7 = v13;
    if ( v13 )
    {
      CAkSplitterBus::CAkSplitterBus(v13);
      if ( CAkKeyArray<unsigned long,AkStateGroupInfo *,4>::Set(&this->m_aBusses, in_idBus, v7) )
        goto LABEL_7;
      v14 = g_LEngineDefaultPoolId;
      CAkSplitterBus::~CAkSplitterBus(v7);
      AK::MemoryMgr::Free(v14, v7);
    }
    return 0i64;
  }
  v7 = *p_item;
LABEL_7:
  for ( i = 0; i < (unsigned int)this->m_uLastPlayerIndex; ++i )
  {
    v9 = &this->m_aPlayers[i];
    for ( j = v9->m_pItems; j != &v9->m_pItems[v9->m_uLength]; ++j )
    {
      v11 = ((__int64 (__fastcall *)(IAkMotionMixBus *))j->item.m_pFinalBus->vfptr[2].GetPluginInfo)(j->item.m_pFinalBus);
      CAkSplitterBus::AddBus(v7, i, j->key, v11);
    }
  }
  return v7;
}

// File Line: 352
// RVA: 0xA64D50
void __fastcall CAkFeedbackDeviceMgr::RenderData(CAkFeedbackDeviceMgr *this)
{
  unsigned __int8 v1; // r12
  unsigned int i; // r13d
  unsigned int v4; // r15d
  CAkKeyArray<unsigned long,CAkFeedbackDeviceMgr::DeviceBus,1> *v5; // r14
  __int64 v6; // rdi
  unsigned int j; // ebx
  AkAudioBufferBus *out_pAudioBuffer; // [rsp+70h] [rbp+8h] BYREF
  AkAudioBufferBus *out_pFeedbackBuffer; // [rsp+78h] [rbp+10h] BYREF

  v1 = 0;
  for ( i = 0; v1 < (unsigned int)this->m_uLastPlayerIndex; ++v1 )
  {
    v4 = 0;
    v5 = &this->m_aPlayers[v1];
    if ( v5->m_uLength )
    {
      do
      {
        v6 = (__int64)&v5->m_pItems[v4];
        if ( *(_QWORD *)(v6 + 8) )
        {
          for ( j = 0; j < this->m_aBusses.m_uLength; ++j )
          {
            CAkSplitterBus::GetBuffer(
              this->m_aBusses.m_pItems[j].item,
              v1,
              v5->m_pItems[v4].key,
              &out_pAudioBuffer,
              &out_pFeedbackBuffer);
            if ( out_pAudioBuffer && out_pAudioBuffer->uValidFrames )
              (*(void (__fastcall **)(_QWORD))(**(_QWORD **)(v6 + 8) + 56i64))(*(_QWORD *)(v6 + 8));
            if ( out_pFeedbackBuffer && out_pFeedbackBuffer->uValidFrames )
              (*(void (__fastcall **)(_QWORD))(**(_QWORD **)(v6 + 8) + 64i64))(*(_QWORD *)(v6 + 8));
          }
          (*(void (__fastcall **)(_QWORD))(**(_QWORD **)(v6 + 8) + 72i64))(*(_QWORD *)(v6 + 8));
        }
        ++v4;
      }
      while ( v4 < v5->m_uLength );
    }
  }
  if ( this->m_aBusses.m_uLength )
  {
    do
      CAkSplitterBus::ReleaseBuffers(this->m_aBusses.m_pItems[i++].item);
    while ( i < this->m_aBusses.m_uLength );
  }
}

// File Line: 404
// RVA: 0xA64930
void __fastcall CAkFeedbackDeviceMgr::HandleStarvation(CAkFeedbackDeviceMgr *this)
{
  char v1; // dl
  int v2; // esi
  unsigned int i; // ebx
  IAkMotionMixBus *m_pFinalBus; // rcx
  unsigned int m_uLastStarvationTime; // edx
  unsigned int m_uBufferTick; // ecx

  v1 = 0;
  v2 = 0;
  if ( this->m_uLastPlayerIndex )
  {
    while ( !v1 )
    {
      for ( i = 0; i < this->m_aPlayers[v2].m_uLength; ++i )
      {
        if ( v1 )
          break;
        m_pFinalBus = this->m_aPlayers[v2].m_pItems[i].item.m_pFinalBus;
        if ( m_pFinalBus )
          v1 = ((__int64 (__fastcall *)(IAkMotionMixBus *))m_pFinalBus->vfptr[2].Term)(m_pFinalBus);
      }
      if ( ++v2 >= (unsigned int)(unsigned __int8)this->m_uLastPlayerIndex )
      {
        if ( !v1 )
          return;
        break;
      }
    }
    m_uLastStarvationTime = this->m_uLastStarvationTime;
    m_uBufferTick = g_pAudioMgr->m_uBufferTick;
    if ( !m_uLastStarvationTime || m_uBufferTick - m_uLastStarvationTime > 8 )
      this->m_uLastStarvationTime = m_uBufferTick;
  }
}

// File Line: 432
// RVA: 0xA644E0
void __fastcall CAkFeedbackDeviceMgr::CommandTick(CAkFeedbackDeviceMgr *this)
{
  unsigned int i; // esi
  unsigned int j; // ebx
  IAkMotionMixBus *m_pFinalBus; // rcx

  for ( i = 0; i < (unsigned __int8)this->m_uLastPlayerIndex; ++i )
  {
    for ( j = 0; j < this->m_aPlayers[i].m_uLength; ++j )
    {
      m_pFinalBus = this->m_aPlayers[i].m_pItems[j].item.m_pFinalBus;
      if ( m_pFinalBus )
        m_pFinalBus->vfptr[1].SupportMediaRelocation(m_pFinalBus);
    }
  }
}

// File Line: 446
// RVA: 0xA64A80
char __fastcall CAkFeedbackDeviceMgr::IsFeedbackEnabled(CAkFeedbackDeviceMgr *this)
{
  unsigned __int8 v1; // dl

  v1 = 0;
  if ( !this->m_uLastPlayerIndex )
    return 0;
  while ( !this->m_aPlayers[v1].m_uLength )
  {
    if ( ++v1 >= (int)(unsigned __int8)this->m_uLastPlayerIndex )
      return 0;
  }
  return 1;
}

// File Line: 458
// RVA: 0xA649D0
char __fastcall CAkFeedbackDeviceMgr::IsDeviceActive(
        CAkFeedbackDeviceMgr *this,
        unsigned int in_iDeviceCompanyID,
        unsigned int in_iDevicePluginID)
{
  int v3; // edi
  unsigned int v5; // ebx
  MapStruct<unsigned long,CAkFeedbackDeviceMgr::DeviceBus> *m_pItems; // rax
  MapStruct<unsigned long,CAkFeedbackDeviceMgr::DeviceBus> *v7; // rcx

  v3 = 0;
  v5 = in_iDeviceCompanyID | (in_iDevicePluginID << 16);
  if ( !this->m_uLastPlayerIndex )
    return 0;
  while ( 1 )
  {
    m_pItems = this->m_aPlayers[v3].m_pItems;
    v7 = &m_pItems[this->m_aPlayers[v3].m_uLength];
    if ( m_pItems != v7 )
    {
      do
      {
        if ( m_pItems->key == v5 )
          break;
        ++m_pItems;
      }
      while ( m_pItems != v7 );
      if ( m_pItems != v7
        && m_pItems != (MapStruct<unsigned long,CAkFeedbackDeviceMgr::DeviceBus> *)-8i64
        && (unsigned __int8)m_pItems->item.m_pFinalBus->vfptr[2].Reset(m_pItems->item.m_pFinalBus) )
      {
        break;
      }
    }
    if ( ++v3 >= (unsigned int)(unsigned __int8)this->m_uLastPlayerIndex )
      return 0;
  }
  return 1;
}

// File Line: 545
// RVA: 0xA64F60
void __fastcall CAkFeedbackDeviceMgr::Stop(CAkFeedbackDeviceMgr *this)
{
  unsigned int i; // esi
  unsigned int j; // ebx
  IAkMotionMixBus *m_pFinalBus; // rcx

  for ( i = 0; i < (unsigned __int8)this->m_uLastPlayerIndex; ++i )
  {
    for ( j = 0; j < this->m_aPlayers[i].m_uLength; ++j )
    {
      m_pFinalBus = this->m_aPlayers[i].m_pItems[j].item.m_pFinalBus;
      if ( m_pFinalBus )
        ((void (__fastcall *)(IAkMotionMixBus *))m_pFinalBus->vfptr[1].RelocateMedia)(m_pFinalBus);
    }
  }
}

// File Line: 559
// RVA: 0xA646E0
__int64 __fastcall CAkFeedbackDeviceMgr::GetActivePlayers(CAkFeedbackDeviceMgr *this, CAkPBI *pPBI)
{
  CAkRegisteredObj *m_pGameObj; // rax
  int m_uLastPlayerIndex; // r10d
  unsigned int v4; // r9d
  unsigned __int8 v5; // dl
  unsigned int v7; // r11d
  char v8; // cl

  m_pGameObj = pPBI->m_pGameObj;
  m_uLastPlayerIndex = (unsigned __int8)this->m_uLastPlayerIndex;
  v4 = 0;
  v5 = 0;
  if ( this->m_uLastPlayerIndex )
  {
    v8 = 0;
    do
    {
      v7 = CAkListener::m_uFeedbackMask & m_pGameObj->m_PosKeep.m_uListenerMask;
      if ( _bittest((const int *)&v7, (unsigned __int8)this->m_aPlayerToListener[v5]) )
        v4 |= 1 << v8;
      v8 = ++v5;
    }
    while ( v5 < m_uLastPlayerIndex );
  }
  return v4;
}

// File Line: 576
// RVA: 0xA64EC0
void __fastcall CAkFeedbackDeviceMgr::StartOutputCapture(CAkFeedbackDeviceMgr *this, const wchar_t *in_CaptureFileName)
{
  unsigned __int8 i; // si
  unsigned int j; // ebx
  IAkMotionMixBus *m_pFinalBus; // rcx

  for ( i = 0; i < (unsigned int)this->m_uLastPlayerIndex; ++i )
  {
    for ( j = 0; j < this->m_aPlayers[i].m_uLength; ++j )
    {
      m_pFinalBus = this->m_aPlayers[i].m_pItems[j].item.m_pFinalBus;
      if ( m_pFinalBus )
        ((void (__fastcall *)(IAkMotionMixBus *, const wchar_t *))m_pFinalBus->vfptr[2].RelocateMedia)(
          m_pFinalBus,
          in_CaptureFileName);
    }
  }
}

// File Line: 590
// RVA: 0xA64FE0
void __fastcall CAkFeedbackDeviceMgr::StopOutputCapture(CAkFeedbackDeviceMgr *this)
{
  unsigned __int8 i; // si
  unsigned int j; // ebx
  IAkMotionMixBus *m_pFinalBus; // rcx

  for ( i = 0; i < (unsigned int)this->m_uLastPlayerIndex; ++i )
  {
    for ( j = 0; j < this->m_aPlayers[i].m_uLength; ++j )
    {
      m_pFinalBus = this->m_aPlayers[i].m_pItems[j].item.m_pFinalBus;
      if ( m_pFinalBus )
        ((void (__fastcall *)(IAkMotionMixBus *))m_pFinalBus->vfptr[3].__vecDelDtor)(m_pFinalBus);
    }
  }
}

