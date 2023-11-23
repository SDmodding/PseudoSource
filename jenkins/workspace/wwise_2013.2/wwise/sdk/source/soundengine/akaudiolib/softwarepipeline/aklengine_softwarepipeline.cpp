// File Line: 58
// RVA: 0xA53500
unsigned int __fastcall CAkLEngine::SoftwareInit()
{
  unsigned int result; // eax
  hkpEntity *v1; // rdx

  if ( !AK::MemoryMgr::IsInitialized() || !AK::IAkStreamMgr::m_pStreamMgr )
    return 2;
  result = CAkLEngine::CreateLEnginePools();
  if ( result != 1 )
    return result;
  CAkListener::Init();
  if ( CAkOutputMgr::AddMainDevice(&g_settings.settingsMainOutput, g_settings.eMainOutputType, 0xFFu, 0i64) != AK_Success
    && CAkOutputMgr::AddMainDevice(&g_settings.settingsMainOutput, AkSink_Dummy, 0xFFu, 0i64) != AK_Success )
  {
    return 2;
  }
  g_pAkSink = CAkOutputMgr::m_Devices.m_pItems->pSink;
  g_settings.settingsMainOutput.uChannelMask = g_pAkSink->m_SpeakersConfig;
  result = hkaReferencePoseAnimation::getNumOriginalFrames((hkEntitySelectorAll *)g_pAkSink, v1);
  if ( result == 1 )
  {
    result = CAkLEngineCmds::Init();
    if ( result == 1 )
    {
      CAkSpeakerPan::Init();
      return 1;
    }
  }
  return result;
}

// File Line: 112
// RVA: 0xA535F0
void CAkLEngine::SoftwareTerm(void)
{
  AkStaticArray<void *,void *,2> *v0; // rsi
  __int64 v1; // rbp
  void **m_Items; // rbx
  __int64 m_cItems; // rdi

  CAkLEngineCmds::Term();
  if ( CAkLEngine::m_arrayVPLs.m_pItems )
  {
    CAkLEngine::m_arrayVPLs.m_uLength = 0;
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, CAkLEngine::m_arrayVPLs.m_pItems);
    CAkLEngine::m_arrayVPLs.m_pItems = 0i64;
    CAkLEngine::m_arrayVPLs.m_ulReserved = 0;
  }
  CAkLEngine::m_Sources.m_pFirst = 0i64;
  CAkLEngine::m_Sources.m_pLast = 0i64;
  CAkLEngine::m_Sources.m_ulNumListItems = 0;
  v0 = CAkLEngine::m_CachedAudioBuffers;
  v1 = 16i64;
  do
  {
    if ( v0->m_cItems )
    {
      m_Items = v0->m_Items;
      m_cItems = v0->m_cItems;
      do
      {
        AK::MemoryMgr::Free(g_LEngineDefaultPoolId, *m_Items++);
        --m_cItems;
      }
      while ( m_cItems );
    }
    v0->m_cItems = 0;
    ++v0;
    --v1;
  }
  while ( v1 );
  CAkEffectsMgr::Term();
  CAkOutputMgr::Term();
  g_pAkSink = 0i64;
  if ( CAkLEngine::m_pDeviceMgr )
  {
    CAkFeedbackDeviceMgr::Destroy();
    CAkLEngine::m_pDeviceMgr = 0i64;
  }
  CAkLEngine::DestroyLEnginePools();
}

// File Line: 145
// RVA: 0xA53900
void __fastcall CAkLEngine::TransferBuffer(AkVPL *in_pVPL)
{
  AkVPL *m_pParent; // rsi
  bool IsPanning; // al
  __int64 v4; // rax
  unsigned __int64 *i; // rcx
  AkDevice *v6; // rsi
  bool v7; // al
  AkAudioBufferBus *io_rpBuffer; // [rsp+30h] [rbp+8h] BYREF

  CAkVPLMixBusNode::GetResultingBuffer(&in_pVPL->m_MixBus, &io_rpBuffer);
  CAkBusVolumes::UpdateFinalVolumes(&in_pVPL->m_MixBus);
  m_pParent = in_pVPL->m_MixBus.m_pParent;
  if ( m_pParent )
  {
    IsPanning = CAkVPLMixBusNode::IsPanning(&in_pVPL->m_MixBus);
    CAkVPLMixBusNode::ConsumeBuffer(&m_pParent->m_MixBus, io_rpBuffer, IsPanning, in_pVPL->m_MixBus.m_FinalVolumes);
  }
  else
  {
    v4 = 0i64;
    if ( CAkOutputMgr::m_Devices.m_uLength )
    {
      for ( i = &CAkOutputMgr::m_Devices.m_pItems->uDeviceID; *i != in_pVPL->m_uDevice; i += 10 )
      {
        v4 = (unsigned int)(v4 + 1);
        if ( (unsigned int)v4 >= CAkOutputMgr::m_Devices.m_uLength )
          return;
      }
      v6 = &CAkOutputMgr::m_Devices.m_pItems[v4];
      if ( v6 )
      {
        v7 = CAkVPLMixBusNode::IsPanning(&in_pVPL->m_MixBus);
        CAkVPLFinalMixNode::ConsumeBuffer(v6->pFinalMix, io_rpBuffer, v7, in_pVPL->m_MixBus.m_FinalVolumes);
      }
    }
  }
}

// File Line: 176
// RVA: 0x15BDFC0
__int64 dynamic_initializer_for__CAkLEngine::m_arrayVPLs__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__CAkLEngine::m_arrayVPLs__);
}

// File Line: 177
// RVA: 0x15BDF80
__int64 dynamic_initializer_for__CAkLEngine::m_CachedAudioBuffers__()
{
  AkStaticArray<void *,void *,2> *v0; // rax
  int i; // ecx

  v0 = CAkLEngine::m_CachedAudioBuffers;
  for ( i = 15; i >= 0; --i )
  {
    v0->m_cItems = 0;
    ++v0;
  }
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__CAkLEngine::m_CachedAudioBuffers__);
}

// File Line: 178
// RVA: 0x15BDFB0
__int64 dynamic_initializer_for__CAkLEngine::m_Sources__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__CAkLEngine::m_Sources__);
}

// File Line: 181
// RVA: 0xA536E0
void CAkLEngine::Stop(void)
{
  CAkVPLSrcCbxNode *m_pFirst; // rax
  CAkVPLSrcCbxNode *v1; // rdx
  CAkVPLSrcCbxNode *v2; // rcx
  CAkVPLSrcCbxNode *pNextItem; // rbx
  CAkVPLSrcCbxNode *m_pLast; // rax
  AkDevice *i; // rbx
  CAkVPLSrcCbxNode *v6; // [rsp+28h] [rbp-20h]

  m_pFirst = CAkLEngine::m_Sources.m_pFirst;
  v1 = 0i64;
  v2 = CAkLEngine::m_Sources.m_pFirst;
  if ( CAkLEngine::m_Sources.m_pFirst )
  {
    while ( 1 )
    {
      pNextItem = (CAkVPLSrcCbxNode *)v2->pNextItem;
      v6 = v1;
      if ( v2 == m_pFirst )
        CAkLEngine::m_Sources.m_pFirst = (CAkVPLSrcCbxNode *)v2->pNextItem;
      else
        v1->pNextItem = pNextItem;
      m_pLast = CAkLEngine::m_Sources.m_pLast;
      if ( v2 == CAkLEngine::m_Sources.m_pLast )
        m_pLast = v1;
      --CAkLEngine::m_Sources.m_ulNumListItems;
      CAkLEngine::m_Sources.m_pLast = m_pLast;
      CAkLEngine::VPLDestroySource(v2, 0i64);
      if ( !pNextItem )
        break;
      v1 = v6;
      v2 = pNextItem;
      m_pFirst = CAkLEngine::m_Sources.m_pFirst;
    }
  }
  CAkLEngine::DestroyAllVPLMixBusses();
  for ( i = CAkOutputMgr::m_Devices.m_pItems; i != &CAkOutputMgr::m_Devices.m_pItems[CAkOutputMgr::m_Devices.m_uLength]; ++i )
    CAkBusFX::DropFx(i->pFinalMix);
  CAkLEngineCmds::DestroyDisconnectedSources();
}

// File Line: 892
// RVA: 0xA52A10
void __fastcall CAkLEngine::ResetBusVolume(unsigned int in_MixBusID, float in_Volume)
{
  AkVPL **i; // rbx
  CAkVPLMixBusNode *v4; // rdi

  for ( i = CAkLEngine::m_arrayVPLs.m_pItems; i != &CAkLEngine::m_arrayVPLs.m_pItems[CAkLEngine::m_arrayVPLs.m_uLength]; ++i )
  {
    v4 = (CAkVPLMixBusNode *)*i;
    if ( AK::CAkBusCtx::ID(&(*i)->m_MixBus.m_BusContext) == in_MixBusID )
      CAkVPLMixBusNode::ResetNextVolume(v4, in_Volume);
  }
}

// File Line: 914
// RVA: 0xA52A90
void __fastcall CAkLEngine::ResetMasterBusVolume(bool in_bMain, float in_Volume)
{
  __int64 v2; // rax
  unsigned __int64 *i; // rcx
  AkDevice *v4; // rbx
  CAkBusVolumes *pFinalMix; // rbx
  AkDevice *m_pItems; // rdx
  unsigned int m_uLength; // r8d
  AkDevice *v8; // rbx
  CAkBusVolumes *v9; // rdi

  if ( in_bMain )
  {
    v2 = 0i64;
    if ( CAkOutputMgr::m_Devices.m_uLength )
    {
      for ( i = &CAkOutputMgr::m_Devices.m_pItems->uDeviceID; *i; i += 10 )
      {
        v2 = (unsigned int)(v2 + 1);
        if ( (unsigned int)v2 >= CAkOutputMgr::m_Devices.m_uLength )
          return;
      }
      v4 = &CAkOutputMgr::m_Devices.m_pItems[v2];
      if ( v4 )
      {
        pFinalMix = v4->pFinalMix;
        CAkBusVolumes::SetNextVolume(pFinalMix, in_Volume);
        CAkBusVolumes::Update2DParams(pFinalMix, 0i64);
      }
    }
  }
  else
  {
    m_pItems = CAkOutputMgr::m_Devices.m_pItems;
    m_uLength = CAkOutputMgr::m_Devices.m_uLength;
    v8 = CAkOutputMgr::m_Devices.m_pItems;
    if ( CAkOutputMgr::m_Devices.m_pItems != &CAkOutputMgr::m_Devices.m_pItems[CAkOutputMgr::m_Devices.m_uLength] )
    {
      do
      {
        if ( v8->uDeviceID )
        {
          v9 = v8->pFinalMix;
          CAkBusVolumes::SetNextVolume(v8->pFinalMix, in_Volume);
          CAkBusVolumes::Update2DParams(v9, 0i64);
          m_uLength = CAkOutputMgr::m_Devices.m_uLength;
          m_pItems = CAkOutputMgr::m_Devices.m_pItems;
        }
        ++v8;
      }
      while ( v8 != &m_pItems[m_uLength] );
    }
  }
}

// File Line: 943
// RVA: 0xA531A0
void __fastcall CAkLEngine::SetBusVolume(unsigned int in_MixBusID, float in_VolumeOffset)
{
  AkVPL **i; // rbx
  AK::CAkBusCtx *v5; // rdi
  float v6; // xmm0_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm1_4

  for ( i = CAkLEngine::m_arrayVPLs.m_pItems; i != &CAkLEngine::m_arrayVPLs.m_pItems[CAkLEngine::m_arrayVPLs.m_uLength]; ++i )
  {
    v5 = (AK::CAkBusCtx *)*i;
    if ( AK::CAkBusCtx::ID(&(*i)->m_MixBus.m_BusContext) == in_MixBusID )
    {
      v6 = in_VolumeOffset + *((float *)&v5[137].m_pBus + 1);
      *((float *)&v5[137].m_pBus + 1) = v6;
      v7 = v6 * 0.050000001;
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
      *((float *)&v5[136].m_pBus + 1) = v8;
    }
  }
}

// File Line: 965
// RVA: 0xA53360
void __fastcall CAkLEngine::SetMasterBusVolume(bool in_bMain, float in_VolumeOffset)
{
  __int64 v2; // rax
  unsigned __int64 *i; // rcx
  AkDevice *v4; // rcx
  AkDevice *m_pItems; // rdx
  unsigned int m_uLength; // r8d
  AkDevice *v7; // rbx

  if ( in_bMain )
  {
    v2 = 0i64;
    if ( CAkOutputMgr::m_Devices.m_uLength )
    {
      for ( i = &CAkOutputMgr::m_Devices.m_pItems->uDeviceID; *i; i += 10 )
      {
        v2 = (unsigned int)(v2 + 1);
        if ( (unsigned int)v2 >= CAkOutputMgr::m_Devices.m_uLength )
          return;
      }
      v4 = &CAkOutputMgr::m_Devices.m_pItems[v2];
      if ( v4 )
        CAkBusVolumes::SetVolumeOffset(v4->pFinalMix, in_VolumeOffset);
    }
  }
  else
  {
    m_pItems = CAkOutputMgr::m_Devices.m_pItems;
    m_uLength = CAkOutputMgr::m_Devices.m_uLength;
    v7 = CAkOutputMgr::m_Devices.m_pItems;
    if ( CAkOutputMgr::m_Devices.m_pItems != &CAkOutputMgr::m_Devices.m_pItems[CAkOutputMgr::m_Devices.m_uLength] )
    {
      do
      {
        if ( v7->uDeviceID )
        {
          CAkBusVolumes::SetVolumeOffset(v7->pFinalMix, in_VolumeOffset);
          m_uLength = CAkOutputMgr::m_Devices.m_uLength;
          m_pItems = CAkOutputMgr::m_Devices.m_pItems;
        }
        ++v7;
      }
      while ( v7 != &m_pItems[m_uLength] );
    }
  }
}

// File Line: 1009
// RVA: 0xA50BE0
void __fastcall CAkLEngine::BypassBusFx(
        unsigned int in_MixBusID,
        unsigned int in_bitsFXBypass,
        unsigned int in_uTargetMask)
{
  AkVPL **i; // rbx
  AK::CAkBusCtx *v7; // rdi

  for ( i = CAkLEngine::m_arrayVPLs.m_pItems; i != &CAkLEngine::m_arrayVPLs.m_pItems[CAkLEngine::m_arrayVPLs.m_uLength]; ++i )
  {
    v7 = (AK::CAkBusCtx *)*i;
    if ( AK::CAkBusCtx::ID(&(*i)->m_MixBus.m_BusContext) == in_MixBusID )
      CAkBusFX::SetInsertFxBypass((CAkBusFX *)v7, in_bitsFXBypass, in_uTargetMask);
  }
}

// File Line: 1034
// RVA: 0xA50C80
void __fastcall CAkLEngine::BypassMasterBusFx(unsigned int in_bitsFXBypass, unsigned int in_uTargetMask)
{
  __int64 v2; // rax
  unsigned __int64 *i; // r8
  AkDevice *v5; // rcx

  v2 = 0i64;
  if ( CAkOutputMgr::m_Devices.m_uLength )
  {
    for ( i = &CAkOutputMgr::m_Devices.m_pItems->uDeviceID; *i; i += 10 )
    {
      v2 = (unsigned int)(v2 + 1);
      if ( (unsigned int)v2 >= CAkOutputMgr::m_Devices.m_uLength )
        return;
    }
    v5 = &CAkOutputMgr::m_Devices.m_pItems[v2];
    if ( v5 )
      CAkBusFX::SetInsertFxBypass(v5->pFinalMix, in_bitsFXBypass, in_uTargetMask);
  }
}

// File Line: 1042
// RVA: 0xA52470
void __fastcall CAkLEngine::PositioningChangeNotification(
        unsigned int in_MixBusID,
        float in_RTPCValue,
        AkRTPC_ParameterID in_ParameterID)
{
  AkVPL **i; // rbx
  AK::CAkBusCtx *v6; // rdi

  for ( i = CAkLEngine::m_arrayVPLs.m_pItems; i != &CAkLEngine::m_arrayVPLs.m_pItems[CAkLEngine::m_arrayVPLs.m_uLength]; ++i )
  {
    v6 = (AK::CAkBusCtx *)*i;
    if ( AK::CAkBusCtx::ID(&(*i)->m_MixBus.m_BusContext) == in_MixBusID )
      CAkBusVolumes::PositioningChangeNotification((CAkBusVolumes *)v6, in_RTPCValue, in_ParameterID);
  }
}

// File Line: 1055
// RVA: 0xA537C0
void __fastcall CAkLEngine::StopMixBussesUsingThisSlot(CAkUsageSlot *in_pSlot)
{
  AkVPL **i; // rbx
  AkVPL *v3; // rbp
  unsigned int v4; // esi
  CAkEffectContextBase **p_pBusFXContext; // rdi
  AkDevice *j; // rbx
  CAkBusFX *pFinalMix; // rbp
  unsigned int v8; // esi
  CAkEffectContextBase **v9; // rdi

  for ( i = CAkLEngine::m_arrayVPLs.m_pItems; i != &CAkLEngine::m_arrayVPLs.m_pItems[CAkLEngine::m_arrayVPLs.m_uLength]; ++i )
  {
    v3 = *i;
    v4 = 0;
    p_pBusFXContext = &(*i)->m_MixBus.m_aFX[0].pBusFXContext;
    while ( !*p_pBusFXContext
         || !CAkEffectContextBase::IsUsingThisSlot(*p_pBusFXContext, in_pSlot, (AK::IAkPlugin *)*(p_pBusFXContext - 1)) )
    {
      ++v4;
      p_pBusFXContext += 5;
      if ( v4 >= 4 )
        goto LABEL_8;
    }
    CAkBusFX::DropFx(&v3->m_MixBus);
LABEL_8:
    ;
  }
  for ( j = CAkOutputMgr::m_Devices.m_pItems; j != &CAkOutputMgr::m_Devices.m_pItems[CAkOutputMgr::m_Devices.m_uLength]; ++j )
  {
    pFinalMix = j->pFinalMix;
    if ( j->pFinalMix )
    {
      v8 = 0;
      v9 = &pFinalMix->m_aFX[0].pBusFXContext;
      while ( !*v9 || !CAkEffectContextBase::IsUsingThisSlot(*v9, in_pSlot, (AK::IAkPlugin *)*(v9 - 1)) )
      {
        ++v8;
        v9 += 5;
        if ( v8 >= 4 )
          goto LABEL_17;
      }
      CAkBusFX::DropFx(pFinalMix);
      pFinalMix[1].m_PanningVolumes[0].Next.vector[0].m128_i32[0] = 2;
    }
LABEL_17:
    ;
  }
}

// File Line: 1093
// RVA: 0xA52080
void *__fastcall CAkLEngine::GetCachedAudioBuffer(unsigned int in_uSize)
{
  AkStaticArray<void *,void *,2> *v1; // rdx
  __int64 v2; // rcx
  void *result; // rax

  if ( in_uSize < 0x800 )
    in_uSize = 2048;
  v1 = &CAkLEngine::m_CachedAudioBuffers[(unsigned __int64)(in_uSize - 1) >> 11];
  if ( !v1->m_cItems )
    return AK::MemoryMgr::Malign(g_LEngineDefaultPoolId, in_uSize, 0x10u);
  v2 = v1->m_cItems - 1;
  result = v1->m_Items[v2];
  v1->m_cItems = v2;
  return result;
}

// File Line: 1118
// RVA: 0xA52840
void __fastcall CAkLEngine::ReleaseCachedAudioBuffer(unsigned int in_uSize, void *in_pvBuffer)
{
  __int64 m_cItems; // r9
  AkStaticArray<void *,void *,2> *v3; // r8
  void **v4; // rcx

  if ( in_uSize < 0x800 )
    in_uSize = 2048;
  m_cItems = CAkLEngine::m_CachedAudioBuffers[(unsigned __int64)(in_uSize - 1) >> 11].m_cItems;
  v3 = &CAkLEngine::m_CachedAudioBuffers[(unsigned __int64)(in_uSize - 1) >> 11];
  if ( (unsigned int)m_cItems < 2 && (v4 = &v3->m_Items[m_cItems], v3->m_cItems = m_cItems + 1, v4) )
    *v4 = in_pvBuffer;
  else
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, in_pvBuffer);
}

// File Line: 1136
// RVA: 0xA539E0
void __fastcall CAkLEngine::UpdateMasterBusFX(unsigned int in_uFXIndex)
{
  __int64 v1; // rax
  unsigned __int64 *i; // rdx
  AkDevice *v4; // rcx

  v1 = 0i64;
  if ( CAkOutputMgr::m_Devices.m_uLength )
  {
    for ( i = &CAkOutputMgr::m_Devices.m_pItems->uDeviceID; *i; i += 10 )
    {
      v1 = (unsigned int)(v1 + 1);
      if ( (unsigned int)v1 >= CAkOutputMgr::m_Devices.m_uLength )
        return;
    }
    v4 = &CAkOutputMgr::m_Devices.m_pItems[v1];
    if ( v4 )
      CAkBusFX::SetInsertFx(v4->pFinalMix, &g_MasterBusCtx, in_uFXIndex);
  }
}

// File Line: 1143
// RVA: 0xA53A40
void __fastcall CAkLEngine::UpdateMixBusFX(unsigned int in_MixBusID, unsigned int in_uFXIndex)
{
  AkVPL **i; // rbx
  AK::CAkBusCtx *v5; // rdi

  for ( i = CAkLEngine::m_arrayVPLs.m_pItems; i != &CAkLEngine::m_arrayVPLs.m_pItems[CAkLEngine::m_arrayVPLs.m_uLength]; ++i )
  {
    v5 = (AK::CAkBusCtx *)*i;
    if ( AK::CAkBusCtx::ID(&(*i)->m_MixBus.m_BusContext) == in_MixBusID && LODWORD(v5[167].m_pBus) != 2 )
      CAkBusFX::SetInsertFx((CAkBusFX *)v5, v5 + 166, in_uFXIndex);
  }
}

// File Line: 1163
// RVA: 0xA517E0
void __fastcall CAkLEngine::ForAllPluginParam(
        CAkFxBase *in_pFx,
        void (__fastcall *in_funcForAll)(AK::IAkPluginParam *, CAkRegisteredObj *, void *),
        void *in_pCookie)
{
  __int64 v3; // rax
  unsigned __int64 *p_uDeviceID; // r9
  AkDevice *v8; // rax
  unsigned int v9; // ebx
  AK::IAkPluginParam **p_pParam; // rdi
  CAkFxBase *m_pT; // rcx
  AkVPL **i; // rbx
  unsigned int v13; // edi
  AK::CAkBusCtx *p_m_BusContext; // rbp
  AK::IAkPluginParam **v15; // rsi
  CAkFxBase *v16; // rcx
  CAkVPLSrcCbxNode *j; // rbx
  CAkVPLSrcNode *v18; // rcx
  CAkPBI *m_pCtx; // rax
  CAkRegisteredObj *m_pGameObj; // r13
  CAkPBI *v21; // rax
  CAkSoundBase *m_pSound; // r12
  AK::IAkPluginParam *v23; // r14
  unsigned int vfptr; // esi
  CAkIndexItem<CAkFxCustom *> *p_m_idxFxCustom; // rbp
  CAkFxBase *pNextItem; // rdi
  unsigned int v27; // esi
  CAkVPLFilterNodeBase **m_pFilter; // r14
  CAkVPLFilterNodeBase *v29; // rbp
  CAkIndexableVtbl *v30; // rdi
  CAkPBI *Context; // rax
  CAkFxBase *v32; // rcx
  AkFXDesc out_rFXInfo; // [rsp+20h] [rbp-48h] BYREF

  v3 = 0i64;
  if ( CAkOutputMgr::m_Devices.m_uLength )
  {
    p_uDeviceID = &CAkOutputMgr::m_Devices.m_pItems->uDeviceID;
    while ( *p_uDeviceID )
    {
      v3 = (unsigned int)(v3 + 1);
      p_uDeviceID += 10;
      if ( (unsigned int)v3 >= CAkOutputMgr::m_Devices.m_uLength )
        goto LABEL_5;
    }
    v8 = &CAkOutputMgr::m_Devices.m_pItems[v3];
  }
  else
  {
LABEL_5:
    v8 = 0i64;
  }
  v9 = 0;
  p_pParam = &v8->pFinalMix->m_aFX[0].pParam;
  do
  {
    out_rFXInfo.pFx.m_pT = 0i64;
    AK::CAkBusCtx::GetFX(&g_MasterBusCtx, v9, &out_rFXInfo);
    m_pT = out_rFXInfo.pFx.m_pT;
    if ( out_rFXInfo.pFx.m_pT )
    {
      if ( out_rFXInfo.pFx.m_pT == in_pFx && *p_pParam )
      {
        in_funcForAll(*p_pParam, 0i64, in_pCookie);
        m_pT = out_rFXInfo.pFx.m_pT;
      }
      if ( m_pT )
      {
        m_pT->vfptr->Release(m_pT);
        out_rFXInfo.pFx.m_pT = 0i64;
      }
    }
    ++v9;
    p_pParam += 5;
  }
  while ( v9 < 4 );
  for ( i = CAkLEngine::m_arrayVPLs.m_pItems; i != &CAkLEngine::m_arrayVPLs.m_pItems[CAkLEngine::m_arrayVPLs.m_uLength]; ++i )
  {
    v13 = 0;
    p_m_BusContext = &(*i)->m_MixBus.m_BusContext;
    v15 = &(*i)->m_MixBus.m_aFX[0].pParam;
    do
    {
      out_rFXInfo.pFx.m_pT = 0i64;
      AK::CAkBusCtx::GetFX(p_m_BusContext, v13, &out_rFXInfo);
      v16 = out_rFXInfo.pFx.m_pT;
      if ( out_rFXInfo.pFx.m_pT )
      {
        if ( out_rFXInfo.pFx.m_pT == in_pFx && *v15 )
        {
          in_funcForAll(*v15, 0i64, in_pCookie);
          v16 = out_rFXInfo.pFx.m_pT;
        }
        if ( v16 )
        {
          v16->vfptr->Release(v16);
          out_rFXInfo.pFx.m_pT = 0i64;
        }
      }
      ++v13;
      v15 += 5;
    }
    while ( v13 < 4 );
  }
  for ( j = CAkLEngine::m_Sources.m_pFirst; j; j = (CAkVPLSrcCbxNode *)j->pNextItem )
  {
    v18 = j->m_pSources[0];
    if ( v18 )
      m_pCtx = v18->m_pCtx;
    else
      m_pCtx = 0i64;
    m_pGameObj = m_pCtx->m_pGameObj;
    if ( v18 )
      v21 = v18->m_pCtx;
    else
      v21 = 0i64;
    m_pSound = v21->m_pSound;
    if ( v18 )
    {
      v23 = (AK::IAkPluginParam *)((__int64 (__fastcall *)(CAkVPLSrcNode *))v18->vfptr[1].VirtualOff)(v18);
      if ( v23 )
      {
        if ( m_pSound->vfptr->Category(m_pSound) == ObjCategory_Sound )
        {
          vfptr = (unsigned int)m_pSound[1].vfptr;
          p_m_idxFxCustom = &g_pIndex->m_idxFxCustom;
          EnterCriticalSection(&g_pIndex->m_idxFxCustom.m_IndexLock.m_csLock);
          pNextItem = (CAkFxBase *)p_m_idxFxCustom->m_mapIDToPtr.m_table[vfptr % 0xC1];
          if ( pNextItem )
          {
            while ( pNextItem->key != vfptr )
            {
              pNextItem = (CAkFxBase *)pNextItem->pNextItem;
              if ( !pNextItem )
                goto LABEL_38;
            }
            ++pNextItem->m_lRef;
            LeaveCriticalSection(&p_m_idxFxCustom->m_IndexLock.m_csLock);
            if ( pNextItem == in_pFx )
              in_funcForAll(v23, m_pGameObj, in_pCookie);
            pNextItem->vfptr->Release(pNextItem);
          }
          else
          {
LABEL_38:
            LeaveCriticalSection(&p_m_idxFxCustom->m_IndexLock.m_csLock);
          }
        }
      }
    }
    v27 = 0;
    m_pFilter = j->m_cbxRec.m_pFilter;
    do
    {
      v29 = *m_pFilter;
      if ( *m_pFilter )
      {
        v30 = m_pSound->vfptr;
        out_rFXInfo.pFx.m_pT = 0i64;
        Context = CAkVPLSrcCbxNodeBase::GetContext(j);
        ((void (__fastcall *)(CAkSoundBase *, _QWORD, AkFXDesc *, CAkRegisteredObj *))v30[14].__vecDelDtor)(
          m_pSound,
          v27,
          &out_rFXInfo,
          Context->m_pGameObj);
        v32 = out_rFXInfo.pFx.m_pT;
        if ( out_rFXInfo.pFx.m_pT )
        {
          if ( out_rFXInfo.pFx.m_pT == in_pFx && v29->m_pParam )
          {
            in_funcForAll(v29->m_pParam, m_pGameObj, in_pCookie);
            v32 = out_rFXInfo.pFx.m_pT;
          }
          if ( v32 )
          {
            v32->vfptr->Release(v32);
            out_rFXInfo.pFx.m_pT = 0i64;
          }
        }
      }
      ++v27;
      ++m_pFilter;
    }
    while ( v27 < 4 );
  }
}

// File Line: 1268
// RVA: 0xA52B90
CAkVPLSrcCbxNode *__fastcall CAkLEngine::ResolveCommandVPL(AkLECmd *io_cmd)
{
  CAkPBI *m_pCtx; // r8
  CAkVPLSrcCbxNode *result; // rax
  CAkVPLSrcNode *v4; // rdx
  CAkVPLSrcNode *v5; // rcx
  CAkVPLSrcNode *v6; // rcx

  m_pCtx = io_cmd->m_pCtx;
  for ( result = CAkLEngine::m_Sources.m_pFirst; result; result = (CAkVPLSrcCbxNode *)result->pNextItem )
  {
    v4 = result->m_pSources[0];
    if ( !v4 || v4->m_pCtx != m_pCtx )
    {
      if ( io_cmd->m_eState != LEStateStopLooping )
        continue;
      v5 = result->m_pSources[1];
      if ( !v5 || v5->m_pCtx != m_pCtx )
        continue;
    }
    if ( result->m_eState )
      io_cmd->m_bSourceConnected = 1;
    return result;
  }
  result = (CAkVPLSrcCbxNode *)m_pCtx->m_pCbx;
  if ( !result )
    return 0i64;
  v6 = result->m_pSources[0];
  if ( (!v6 || v6->m_pCtx != m_pCtx) && io_cmd->m_eState != LEStateStopLooping )
    return 0i64;
  return result;
}

// File Line: 1321
// RVA: 0xA51B30
AkVPL *__fastcall CAkLEngine::GetAndConnectBus(
        CAkPBI *in_pCtx,
        CAkVPLSrcCbxNodeBase *in_pCbx,
        unsigned __int64 in_uDevice)
{
  AkHdrBus *HdrBus; // rdi
  CAkBus *OutputBusPtr; // rax
  unsigned __int8 v8; // r15
  char v9; // r15
  unsigned int v10; // eax
  AkVPL *ExistingVPLMixBus; // rbx
  AkVPL *m_pParent; // rcx
  AK::CAkBusCtx in_ctxBus; // [rsp+40h] [rbp+8h] BYREF

  HdrBus = 0i64;
  in_ctxBus.m_pBus = 0i64;
  OutputBusPtr = CAkPBI::GetOutputBusPtr(in_pCtx);
  v8 = *((_BYTE *)in_pCtx + 374);
  in_ctxBus.m_pBus = OutputBusPtr;
  v9 = v8 >> 7;
  v10 = AK::CAkBusCtx::ID(&in_ctxBus);
  ExistingVPLMixBus = CAkLEngine::GetExistingVPLMixBus(v10, in_uDevice);
  if ( !ExistingVPLMixBus )
    ExistingVPLMixBus = CAkLEngine::GetVPLMixBusInternal(&in_ctxBus, in_uDevice, v9);
  if ( ExistingVPLMixBus )
  {
    if ( (*((_BYTE *)in_pCtx + 376) & 1) != 0 )
    {
      if ( (*((_BYTE *)ExistingVPLMixBus + 1376) & 2) != 0 )
      {
        HdrBus = (AkHdrBus *)ExistingVPLMixBus;
      }
      else
      {
        m_pParent = ExistingVPLMixBus->m_MixBus.m_pParent;
        if ( m_pParent )
          HdrBus = (AkHdrBus *)AkVPL::GetHdrBus(m_pParent);
      }
      in_pCbx->m_pHdrBus = HdrBus;
    }
    CAkVPLSrcCbxNodeBase::AddOutputBus(in_pCbx, ExistingVPLMixBus, in_uDevice, 0);
  }
  return ExistingVPLMixBus;
}

// File Line: 1348
// RVA: 0xA51C00
AkVPL *__fastcall CAkLEngine::GetAuxBus(
        CAkBus *in_pAuxBus,
        AkMergedEnvironmentValue *in_pSend,
        unsigned __int64 in_uDevice,
        CAkVPLSrcCbxNodeBase *in_pCbx)
{
  AkVPL *ExistingVPLMixBus; // rbx
  unsigned int v9; // eax
  MapStruct<unsigned __int64,AkVPL *> *m_pItems; // rax
  MapStruct<unsigned __int64,AkVPL *> *v11; // rcx
  CAkVPLSrcNode *v12; // rcx
  __int64 v13; // rax
  char v14; // cl
  AkDeviceInfo *m_pFirst; // rax
  AK::CAkBusCtx in_ctxBus; // [rsp+48h] [rbp+10h] BYREF

  ExistingVPLMixBus = CAkLEngine::GetExistingVPLMixBus(in_pSend->auxBusID, in_uDevice);
  if ( ExistingVPLMixBus )
    goto LABEL_12;
  in_ctxBus.m_pBus = in_pAuxBus;
  v9 = AK::CAkBusCtx::ID(&in_ctxBus);
  ExistingVPLMixBus = CAkLEngine::GetExistingVPLMixBus(v9, in_uDevice);
  if ( !ExistingVPLMixBus )
    ExistingVPLMixBus = CAkLEngine::GetVPLMixBusInternal(&in_ctxBus, in_uDevice, 0);
  if ( ExistingVPLMixBus )
  {
LABEL_12:
    CAkKeyArray<unsigned __int64,AkVPL *,1>::Set(&in_pSend->PerDeviceAuxBusses, in_uDevice, ExistingVPLMixBus);
    *((_BYTE *)ExistingVPLMixBus + 1376) |= 1u;
    v12 = in_pCbx->m_pSources[0];
    if ( v12 )
      v12 = (CAkVPLSrcNode *)v12->m_pCtx;
    v13 = (*(__int64 (__fastcall **)(_QWORD))(**((_QWORD **)&v12[3] + 4) + 248i64))(*((_QWORD *)&v12[3] + 4));
    v14 = !v13 || *(char *)(v13 + 304) < 0;
    if ( *((_BYTE *)in_pAuxBus + 304) >> 7 != v14 )
    {
      m_pFirst = in_pCbx->m_OutputDevices.m_listDeviceVolumes.m_pFirst;
      if ( m_pFirst )
      {
        while ( ExistingVPLMixBus != m_pFirst->pMixBus )
        {
          m_pFirst = m_pFirst->pNextLightItem;
          if ( !m_pFirst )
            goto LABEL_22;
        }
      }
      else
      {
LABEL_22:
        CAkVPLSrcCbxNodeBase::AddOutputBus(in_pCbx, ExistingVPLMixBus, in_uDevice, 1);
      }
    }
  }
  else
  {
    m_pItems = in_pSend->PerDeviceAuxBusses.m_pItems;
    v11 = &m_pItems[in_pSend->PerDeviceAuxBusses.m_uLength];
    if ( m_pItems != v11 )
    {
      do
      {
        if ( m_pItems->key == in_uDevice )
          break;
        ++m_pItems;
      }
      while ( m_pItems != v11 );
      if ( m_pItems != v11 )
      {
        if ( in_pSend->PerDeviceAuxBusses.m_uLength > 1 )
        {
          m_pItems->key = v11[-1].key;
          m_pItems->item = v11[-1].item;
        }
        --in_pSend->PerDeviceAuxBusses.m_uLength;
      }
    }
  }
  return ExistingVPLMixBus;
}

// File Line: 1411
// RVA: 0xA51610
__int64 __fastcall CAkLEngine::EnsureVPLExists(CAkVPLSrcCbxNode *in_pCbx, CAkPBI *in_pCtx)
{
  __int64 v4; // rdx
  AkDevice *m_pItems; // rdx
  unsigned int m_uLength; // r8d
  int m_uListenerMask; // r12d
  CAkVPLSrcCbxNode *v9; // r14
  AkVPL *v10; // rbp
  AkDevice *v11; // rbx
  AkDeviceInfo *m_pFirst; // rax
  unsigned __int64 uDeviceID; // rdi
  __int64 v14; // rax
  bool v15; // cl
  CAkVPLSrcCbxNode *i; // rcx
  CAkVPLSrcCbxNode *m_pLast; // rax

  if ( (*((_BYTE *)&in_pCbx->CAkVPLSrcCbxNodeBase + 76) & 1) == 0
    || CAkVPLSrcCbxNode::AddPipeline(in_pCbx) == AK_Success )
  {
    m_pItems = CAkOutputMgr::m_Devices.m_pItems;
    m_uLength = CAkOutputMgr::m_Devices.m_uLength;
    m_uListenerMask = (unsigned __int8)in_pCtx->m_pGameObj->m_PosKeep.m_uListenerMask;
    v9 = 0i64;
    v10 = 0i64;
    v11 = CAkOutputMgr::m_Devices.m_pItems;
    if ( CAkOutputMgr::m_Devices.m_pItems != &CAkOutputMgr::m_Devices.m_pItems[CAkOutputMgr::m_Devices.m_uLength] )
    {
      do
      {
        if ( (m_uListenerMask & v11->uListeners) != 0 )
        {
          m_pFirst = in_pCbx->m_OutputDevices.m_listDeviceVolumes.m_pFirst;
          uDeviceID = v11->uDeviceID;
          if ( m_pFirst )
          {
            while ( m_pFirst->uDeviceID != uDeviceID )
            {
              m_pFirst = m_pFirst->pNextLightItem;
              if ( !m_pFirst )
                goto LABEL_9;
            }
          }
          else
          {
LABEL_9:
            v10 = 0i64;
            v14 = ((__int64 (__fastcall *)(CAkSoundBase *))in_pCtx->m_pSound->vfptr[7].Category)(in_pCtx->m_pSound);
            v15 = !v14 || *(char *)(v14 + 304) < 0;
            if ( v15 == (uDeviceID == 0) )
            {
              v10 = CAkLEngine::GetAndConnectBus(in_pCtx, in_pCbx, uDeviceID);
              v4 = 2 - (unsigned int)(v10 != 0i64);
              if ( (_DWORD)v4 != 1 )
                goto LABEL_3;
            }
            m_uLength = CAkOutputMgr::m_Devices.m_uLength;
            m_pItems = CAkOutputMgr::m_Devices.m_pItems;
          }
        }
        ++v11;
      }
      while ( v11 != &m_pItems[m_uLength] );
    }
    for ( i = CAkLEngine::m_Sources.m_pFirst; i; i = (CAkVPLSrcCbxNode *)i->pNextItem )
    {
      if ( !i->m_OutputDevices.m_uNumDevices )
        break;
      if ( i->m_OutputDevices.m_listDeviceVolumes.m_pFirst->pMixBus == v10 )
        break;
      v9 = i;
    }
    in_pCbx->pNextItem = i;
    if ( v9 )
      v9->pNextItem = in_pCbx;
    else
      CAkLEngine::m_Sources.m_pFirst = in_pCbx;
    m_pLast = CAkLEngine::m_Sources.m_pLast;
    if ( !i )
      m_pLast = in_pCbx;
    ++CAkLEngine::m_Sources.m_ulNumListItems;
    CAkLEngine::m_Sources.m_pLast = m_pLast;
    return 1i64;
  }
  else
  {
LABEL_3:
    LOBYTE(v4) = 1;
    CAkLEngine::VPLDestroySource(in_pCbx, v4);
    return 2i64;
  }
}

// File Line: 1477
// RVA: 0xA50890
__int64 __fastcall CAkLEngine::AddSound(AkLECmd *io_cmd)
{
  CAkPBI *m_pCtx; // rsi
  unsigned int m_SeqID; // r8d
  CAkVPLSrcCbxNode *pNextItem; // rcx
  CAkVPLSrcNode *v5; // rax
  CAkPBI *v6; // rdx
  CAkVPLSrcCbxNode *v7; // rax
  CAkVPLSrcCbxNode *v8; // rax
  CAkVPLSrcCbxNode *v9; // rbx
  unsigned int v10; // edx
  __int64 result; // rax
  AKRESULT v12; // eax
  __int64 v13; // rdx
  AKRESULT v14; // edi

  m_pCtx = io_cmd->m_pCtx;
  m_SeqID = io_cmd->m_pCtx->m_SeqID;
  if ( m_SeqID && (pNextItem = CAkLEngine::m_Sources.m_pFirst) != 0i64 )
  {
    while ( 1 )
    {
      v5 = pNextItem->m_pSources[0];
      v6 = v5 ? v5->m_pCtx : 0i64;
      if ( v6->m_SeqID == m_SeqID )
        break;
      pNextItem = (CAkVPLSrcCbxNode *)pNextItem->pNextItem;
      if ( !pNextItem )
        goto LABEL_8;
    }
    CAkVPLSrcCbxNodeBase::AddSrc(pNextItem, m_pCtx, 0);
    CAkPBI::NotifAddedAsSA(m_pCtx);
    return 5i64;
  }
  else
  {
LABEL_8:
    v7 = (CAkVPLSrcCbxNode *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 0x440ui64);
    if ( v7 && (CAkVPLSrcCbxNode::CAkVPLSrcCbxNode(v7), (v9 = v8) != 0i64) )
    {
      if ( *((char *)m_pCtx + 374) >= 0 )
        v10 = AkAudioLibSettings::g_pipelineCoreFrequency;
      else
        v10 = (unsigned __int16)(int)(float)((float)((float)(int)AkAudioLibSettings::g_pipelineCoreFrequency
                                                   * 0.0009765625)
                                           * 8.0);
      CAkVPLSrcCbxNode::Init(v8, v10);
      v12 = CAkVPLSrcCbxNodeBase::AddSrc(v9, m_pCtx, 1);
      v14 = v12;
      if ( v12 == AK_FormatNotReady )
      {
        v9->pNextItem = 0i64;
        if ( CAkLEngineCmds::m_listSrcsNotConnected.m_pLast )
          CAkLEngineCmds::m_listSrcsNotConnected.m_pLast->pNextItem = v9;
        else
          CAkLEngineCmds::m_listSrcsNotConnected.m_pFirst = v9;
        CAkLEngineCmds::m_listSrcsNotConnected.m_pLast = v9;
        return 1i64;
      }
      else if ( v12 == AK_Success )
      {
        LODWORD(result) = CAkLEngine::EnsureVPLExists(v9, m_pCtx);
        io_cmd->m_bSourceConnected = (_DWORD)result == 1;
        return (unsigned int)result;
      }
      else
      {
        LOBYTE(v13) = v12 != AK_PartialSuccess;
        CAkLEngine::VPLDestroySource(v9, v13);
        return (unsigned int)v14;
      }
    }
    else
    {
      CAkPBI::Destroy(m_pCtx, CtxDestroyReasonPlayFailed);
      return 2i64;
    }
  }
}

// File Line: 1565
// RVA: 0xA53AF0
unsigned int __fastcall CAkLEngine::VPLTryConnectSource(CAkPBI *in_pContext, CAkVPLSrcCbxNode *in_pCbx)
{
  unsigned int result; // eax
  AKRESULT v5; // r8d
  __int64 v6; // rdx
  CAkVPLSrcCbxNodeBase *m_pFirst; // rcx
  CAkVPLSrcCbxNodeBase *m_pLast; // rax

  result = CAkVPLSrcCbxNodeBase::FetchStreamedData(in_pCbx, in_pContext);
  v5 = result;
  if ( result != 63 )
  {
    v6 = 0i64;
    m_pFirst = CAkLEngineCmds::m_listSrcsNotConnected.m_pFirst;
    if ( CAkLEngineCmds::m_listSrcsNotConnected.m_pFirst )
    {
      while ( m_pFirst != in_pCbx )
      {
        v6 = (__int64)m_pFirst;
        m_pFirst = m_pFirst->pNextItem;
        if ( !m_pFirst )
          goto LABEL_13;
      }
      if ( m_pFirst )
      {
        if ( m_pFirst == CAkLEngineCmds::m_listSrcsNotConnected.m_pFirst )
          CAkLEngineCmds::m_listSrcsNotConnected.m_pFirst = m_pFirst->pNextItem;
        else
          *(_QWORD *)(v6 + 8) = m_pFirst->pNextItem;
        m_pLast = CAkLEngineCmds::m_listSrcsNotConnected.m_pLast;
        if ( m_pFirst == CAkLEngineCmds::m_listSrcsNotConnected.m_pLast )
          m_pLast = (CAkVPLSrcCbxNodeBase *)v6;
        CAkLEngineCmds::m_listSrcsNotConnected.m_pLast = m_pLast;
      }
    }
LABEL_13:
    if ( v5 == AK_Success )
    {
      return CAkLEngine::EnsureVPLExists(in_pCbx, in_pContext);
    }
    else
    {
      LOBYTE(v6) = 1;
      CAkLEngine::VPLDestroySource(in_pCbx, v6);
      return 2;
    }
  }
  return result;
}

// File Line: 1601
// RVA: 0xA520D0
AK::CAkBusCtx *__fastcall CAkLEngine::GetExistingVPLMixBus(unsigned int in_busID, CAkBus *in_uDevice)
{
  AkVPL **m_pItems; // rbx
  AK::CAkBusCtx *v5; // rdi

  m_pItems = CAkLEngine::m_arrayVPLs.m_pItems;
  if ( CAkLEngine::m_arrayVPLs.m_pItems == &CAkLEngine::m_arrayVPLs.m_pItems[CAkLEngine::m_arrayVPLs.m_uLength] )
    return 0i64;
  while ( 1 )
  {
    v5 = (AK::CAkBusCtx *)*m_pItems;
    if ( AK::CAkBusCtx::ID(&(*m_pItems)->m_MixBus.m_BusContext) == in_busID
      && v5[171].m_pBus == in_uDevice
      && LODWORD(v5[167].m_pBus) != 2 )
    {
      break;
    }
    if ( ++m_pItems == &CAkLEngine::m_arrayVPLs.m_pItems[CAkLEngine::m_arrayVPLs.m_uLength] )
      return 0i64;
  }
  return v5;
}

// File Line: 1645
// RVA: 0xA522E0
AkVPL *__fastcall CAkLEngine::GetVPLMixBusInternal(AK::CAkBusCtx *in_ctxBus, CAkBus *in_uDevice, bool in_bForFeedback)
{
  AkVPL *ExistingVPLMixBus; // rbx
  unsigned int v7; // eax
  AkVPL *VPLMixBus; // rbx
  AK::CAkBusCtx result; // [rsp+48h] [rbp+20h] BYREF

  ExistingVPLMixBus = 0i64;
  AK::CAkBusCtx::GetParentCtx(in_ctxBus, &result);
  if ( result.m_pBus )
  {
    v7 = AK::CAkBusCtx::ID(&result);
    ExistingVPLMixBus = (AkVPL *)CAkLEngine::GetExistingVPLMixBus(v7, in_uDevice);
    if ( !ExistingVPLMixBus )
      ExistingVPLMixBus = CAkLEngine::GetVPLMixBusInternal(&result, (unsigned __int64)in_uDevice, in_bForFeedback);
    if ( !ExistingVPLMixBus )
      return 0i64;
  }
  VPLMixBus = CAkLEngine::CreateVPLMixBus(
                (AK::CAkBusCtx)in_ctxBus->m_pBus,
                (unsigned __int64)in_uDevice,
                ExistingVPLMixBus,
                in_bForFeedback);
  if ( !VPLMixBus )
    return 0i64;
  if ( !AK::CAkBusCtx::IsTopBusCtx(in_ctxBus) )
  {
    CAkVPLMixBusNode::InitVolumes(&VPLMixBus->m_MixBus);
    CAkVPLMixBusNode::UpdateBypassFx(&VPLMixBus->m_MixBus);
  }
  return VPLMixBus;
}

// File Line: 1679
// RVA: 0xA51530
void __fastcall CAkLEngine::EnsureAuxBusExist(
        CAkVPLSrcCbxNodeBase *in_pCbx,
        AkMergedEnvironmentValue *in_pMergedEnvSlot)
{
  CAkParameterNodeBase *NodePtrAndAddRef; // rax
  CAkBus *v5; // rdi
  AkDevice *m_pItems; // rdx
  unsigned int m_uLength; // r9d
  AkDevice *v8; // rbx
  unsigned __int64 uDeviceID; // r8

  NodePtrAndAddRef = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, in_pMergedEnvSlot->auxBusID, AkNodeType_Bus);
  v5 = (CAkBus *)NodePtrAndAddRef;
  if ( NodePtrAndAddRef )
  {
    if ( SLOBYTE(NodePtrAndAddRef[2].m_pFeedbackInfo) >= 0 )
    {
      m_pItems = CAkOutputMgr::m_Devices.m_pItems;
      m_uLength = CAkOutputMgr::m_Devices.m_uLength;
      v8 = CAkOutputMgr::m_Devices.m_pItems;
      if ( CAkOutputMgr::m_Devices.m_pItems != &CAkOutputMgr::m_Devices.m_pItems[CAkOutputMgr::m_Devices.m_uLength] )
      {
        do
        {
          uDeviceID = v8->uDeviceID;
          if ( uDeviceID )
          {
            CAkLEngine::GetAuxBus(v5, in_pMergedEnvSlot, uDeviceID, in_pCbx);
            m_uLength = CAkOutputMgr::m_Devices.m_uLength;
            m_pItems = CAkOutputMgr::m_Devices.m_pItems;
          }
          ++v8;
        }
        while ( v8 != &m_pItems[m_uLength] );
      }
    }
    else
    {
      CAkLEngine::GetAuxBus((CAkBus *)NodePtrAndAddRef, in_pMergedEnvSlot, 0i64, in_pCbx);
    }
    v5->vfptr->Release(v5);
  }
}

// File Line: 1720
// RVA: 0xA511B0
AkVPL *__fastcall CAkLEngine::CreateVPLMixBus(
        AK::CAkBusCtx in_BusCtx,
        unsigned __int64 in_uDevice,
        AkVPL *in_pParentBus,
        bool in_bForFeedback)
{
  AkDevice *v4; // rdi
  AkHdrBus *v8; // rax
  CAkVPLMixBusNode *p_m_MixBus; // rbx
  CAkBusFX *v10; // rax
  unsigned int ChannelConfig; // edx
  unsigned int uChannelMask; // esi
  unsigned __int16 v13; // r14
  __int64 v14; // rax
  unsigned __int64 *p_uDeviceID; // rcx
  AkDevice *v16; // rax
  unsigned int m_uLength; // ecx
  unsigned int m_ulReserved; // r14d
  unsigned __int64 v19; // r12
  AkVPL **m_pItems; // rsi
  AkVPL **v21; // rdx
  unsigned __int64 v22; // r8
  unsigned __int64 v23; // rcx
  AkVPL *v24; // rax
  CAkVPLMixBusNode **v25; // rdx
  __int64 v26; // rax
  unsigned __int64 *i; // rcx
  CAkVPLMixBusNode *v28; // rcx
  int v29; // esi
  AK::CAkBusCtx in_BusCtxa; // [rsp+60h] [rbp+8h] BYREF

  in_BusCtxa.m_pBus = in_BusCtx.m_pBus;
  v4 = 0i64;
  if ( in_BusCtx.m_pBus && (*((_BYTE *)&in_BusCtx.m_pBus->CAkParameterNodeBase + 83) & 8) != 0 )
  {
    v8 = (AkHdrBus *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 0x590ui64);
    p_m_MixBus = &v8->m_MixBus;
    if ( v8 )
    {
      AkHdrBus::AkHdrBus(v8, in_BusCtxa);
      goto LABEL_7;
    }
  }
  else
  {
    v10 = (CAkBusFX *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 0x570ui64);
    p_m_MixBus = (CAkVPLMixBusNode *)v10;
    if ( v10 )
    {
      CAkBusFX::CAkBusFX(v10);
      p_m_MixBus->m_BusContext.m_pBus = 0i64;
      p_m_MixBus[1].m_PanningVolumes[0].Next.vector[1].m128_i8[0] &= 0xF4u;
      p_m_MixBus[1].m_PanningVolumes[0].Next.vector[0].m128_i32[0] = 1065353216;
      p_m_MixBus[1].m_PanningVolumes[0].Next.vector[0].m128_u64[1] = 0i64;
LABEL_7:
      if ( in_bForFeedback )
      {
        ChannelConfig = 4;
        uChannelMask = 4;
        v13 = 16;
      }
      else
      {
        v13 = 1024;
        if ( in_pParentBus )
        {
          uChannelMask = in_pParentBus->m_MixBus.m_BufferOut.uChannelMask;
        }
        else
        {
          v14 = 0i64;
          if ( CAkOutputMgr::m_Devices.m_uLength )
          {
            p_uDeviceID = &CAkOutputMgr::m_Devices.m_pItems->uDeviceID;
            while ( *p_uDeviceID != in_uDevice )
            {
              v14 = (unsigned int)(v14 + 1);
              p_uDeviceID += 10;
              if ( (unsigned int)v14 >= CAkOutputMgr::m_Devices.m_uLength )
                goto LABEL_15;
            }
            v16 = &CAkOutputMgr::m_Devices.m_pItems[v14];
          }
          else
          {
LABEL_15:
            v16 = 0i64;
          }
          uChannelMask = v16->pSink->m_SpeakersConfig;
        }
        ChannelConfig = AK::CAkBusCtx::GetChannelConfig(&in_BusCtxa);
        if ( !ChannelConfig )
          ChannelConfig = uChannelMask;
      }
      if ( CAkVPLMixBusNode::Init(p_m_MixBus, ChannelConfig, uChannelMask, v13, in_BusCtxa) != AK_Success )
        goto LABEL_41;
      m_uLength = CAkLEngine::m_arrayVPLs.m_uLength;
      m_ulReserved = CAkLEngine::m_arrayVPLs.m_ulReserved;
      v19 = CAkLEngine::m_arrayVPLs.m_uLength;
      if ( CAkLEngine::m_arrayVPLs.m_uLength < (unsigned __int64)CAkLEngine::m_arrayVPLs.m_ulReserved )
      {
        m_pItems = CAkLEngine::m_arrayVPLs.m_pItems;
      }
      else
      {
        m_ulReserved = CAkLEngine::m_arrayVPLs.m_ulReserved + 4;
        m_pItems = (AkVPL **)AK::MemoryMgr::Malloc(
                               g_LEngineDefaultPoolId,
                               8i64 * (CAkLEngine::m_arrayVPLs.m_ulReserved + 4));
        if ( !m_pItems )
          goto LABEL_41;
        v21 = CAkLEngine::m_arrayVPLs.m_pItems;
        m_uLength = CAkLEngine::m_arrayVPLs.m_uLength;
        v22 = CAkLEngine::m_arrayVPLs.m_uLength;
        if ( CAkLEngine::m_arrayVPLs.m_pItems )
        {
          v23 = 0i64;
          if ( CAkLEngine::m_arrayVPLs.m_uLength )
          {
            do
            {
              v24 = v21[v23++];
              m_pItems[v23 - 1] = v24;
              v21 = CAkLEngine::m_arrayVPLs.m_pItems;
            }
            while ( v23 < v22 );
          }
          AK::MemoryMgr::Free(g_LEngineDefaultPoolId, v21);
          m_uLength = CAkLEngine::m_arrayVPLs.m_uLength;
        }
        CAkLEngine::m_arrayVPLs.m_pItems = m_pItems;
        CAkLEngine::m_arrayVPLs.m_ulReserved = m_ulReserved;
      }
      if ( v19 < m_ulReserved )
      {
        v25 = (CAkVPLMixBusNode **)&m_pItems[m_uLength];
        CAkLEngine::m_arrayVPLs.m_uLength = m_uLength + 1;
        if ( v25 )
        {
          *v25 = p_m_MixBus;
          p_m_MixBus[1].m_PanningVolumes[0].Next.vector[1].m128_i8[0] &= ~8u;
          p_m_MixBus[1].m_PanningVolumes[0].Next.vector[0].m128_u64[1] = in_uDevice;
          p_m_MixBus->m_pParent = in_pParentBus;
          p_m_MixBus[1].m_PanningVolumes[0].Next.vector[1].m128_i8[0] |= 8 * in_bForFeedback;
          if ( !in_bForFeedback )
          {
            if ( in_pParentBus )
            {
              CAkVPLMixBusNode::Connect(&in_pParentBus->m_MixBus);
            }
            else
            {
              v26 = 0i64;
              if ( CAkOutputMgr::m_Devices.m_uLength )
              {
                for ( i = &CAkOutputMgr::m_Devices.m_pItems->uDeviceID; *i != in_uDevice; i += 10 )
                {
                  v26 = (unsigned int)(v26 + 1);
                  if ( (unsigned int)v26 >= CAkOutputMgr::m_Devices.m_uLength )
                  {
                    CAkVPLFinalMixNode::Connect((CAkVPLFinalMixNode *)MEMORY[0], p_m_MixBus);
                    return (AkVPL *)p_m_MixBus;
                  }
                }
                v4 = &CAkOutputMgr::m_Devices.m_pItems[v26];
              }
              CAkVPLFinalMixNode::Connect(v4->pFinalMix, p_m_MixBus);
            }
          }
          return (AkVPL *)p_m_MixBus;
        }
      }
LABEL_41:
      v28 = &p_m_MixBus->m_pParent->m_MixBus;
      v29 = g_LEngineDefaultPoolId;
      if ( v28 )
        CAkVPLMixBusNode::Disconnect(v28);
      CAkVPLMixBusNode::~CAkVPLMixBusNode(p_m_MixBus);
      AK::MemoryMgr::Free(v29, p_m_MixBus);
      return 0i64;
    }
  }
  return 0i64;
}

// File Line: 1797
// RVA: 0xA514A0
void CAkLEngine::DestroyAllVPLMixBusses(void)
{
  __int64 i; // rbx
  int v1; // esi
  AkVPL *v2; // rdi
  CAkVPLMixBusNode *p_m_MixBus; // rcx

  for ( i = CAkLEngine::m_arrayVPLs.m_uLength - 1; i >= 0; --i )
  {
    v1 = g_LEngineDefaultPoolId;
    v2 = CAkLEngine::m_arrayVPLs.m_pItems[i];
    if ( v2 )
    {
      p_m_MixBus = &v2->m_MixBus.m_pParent->m_MixBus;
      if ( p_m_MixBus )
        CAkVPLMixBusNode::Disconnect(p_m_MixBus);
      CAkVPLMixBusNode::~CAkVPLMixBusNode(&v2->m_MixBus);
      AK::MemoryMgr::Free(v1, v2);
    }
  }
  CAkLEngine::m_arrayVPLs.m_uLength = 0;
}

// File Line: 1831
// RVA: 0xA523A0
void CAkLEngine::HandleStarvation(void)
{
  AkDevice *m_pItems; // rbx

  m_pItems = CAkOutputMgr::m_Devices.m_pItems;
  if ( CAkOutputMgr::m_Devices.m_pItems != &CAkOutputMgr::m_Devices.m_pItems[CAkOutputMgr::m_Devices.m_uLength] )
  {
    while ( 1 )
    {
      if ( m_pItems->pSink->vfptr->IsStarved(m_pItems->pSink) )
      {
        m_pItems->pSink->vfptr->ResetStarved(m_pItems->pSink);
        if ( !CAkLEngine::m_uLastStarvationTime || g_pAudioMgr->m_uBufferTick - CAkLEngine::m_uLastStarvationTime > 8 )
          break;
      }
      if ( ++m_pItems == &CAkOutputMgr::m_Devices.m_pItems[CAkOutputMgr::m_Devices.m_uLength] )
        goto LABEL_8;
    }
    CAkLEngine::m_uLastStarvationTime = g_pAudioMgr->m_uBufferTick;
  }
LABEL_8:
  if ( CAkLEngine::m_pDeviceMgr )
  {
    if ( CAkFeedbackDeviceMgr::IsFeedbackEnabled(CAkLEngine::m_pDeviceMgr) )
      CAkFeedbackDeviceMgr::HandleStarvation(CAkLEngine::m_pDeviceMgr);
  }
}

// File Line: 1868
// RVA: 0xA51520
void CAkLEngine::EnableFeedbackPipeline(void)
{
  CAkLEngine::m_pDeviceMgr = CAkFeedbackDeviceMgr::s_pSingleton;
}

// File Line: 1879
// RVA: 0xA52510
void __fastcall CAkLEngine::ReevaluateBussesForDevice(unsigned __int64 in_uDevice, AkDeviceInfo *in_uListenerMask)
{
  CAkVPLSrcCbxNode *m_pFirst; // rsi
  unsigned __int8 i; // r14
  CAkVPLSrcNode *v5; // rax
  CAkPBI *m_pCtx; // rbx
  AkDeviceInfo *v7; // r8
  AkDeviceInfo *v8; // rax
  AkVPL *pMixBus; // rcx
  AkDeviceInfo *v10; // rbx
  AkDeviceInfo *pNextLightItem; // rax
  int v12; // edi
  __int64 v13; // rax
  bool v14; // cl

  m_pFirst = CAkLEngine::m_Sources.m_pFirst;
  for ( i = (unsigned __int8)in_uListenerMask; m_pFirst; m_pFirst = (CAkVPLSrcCbxNode *)m_pFirst->pNextItem )
  {
    v5 = m_pFirst->m_pSources[0];
    if ( v5 )
      m_pCtx = v5->m_pCtx;
    else
      m_pCtx = 0i64;
    v7 = m_pFirst->m_OutputDevices.m_listDeviceVolumes.m_pFirst;
    v8 = v7;
    pMixBus = 0i64;
    if ( v7 )
    {
      while ( !pMixBus )
      {
        if ( v8->uDeviceID == in_uDevice )
          pMixBus = v8->pMixBus;
        v8 = v8->pNextLightItem;
        if ( !v8 )
        {
          if ( !pMixBus )
            goto LABEL_21;
          break;
        }
      }
      if ( (i & m_pCtx->m_pGameObj->m_PosKeep.m_uListenerMask) == 0 )
      {
        *((_BYTE *)&m_pFirst->CAkVPLSrcCbxNodeBase + 76) |= 0x40u;
        in_uListenerMask = 0i64;
        v10 = v7;
        while ( v10->pMixBus != pMixBus )
        {
          in_uListenerMask = v10;
          v10 = v10->pNextLightItem;
          if ( !v10 )
            goto LABEL_28;
        }
        pNextLightItem = v10->pNextLightItem;
        if ( v10 == v7 )
          m_pFirst->m_OutputDevices.m_listDeviceVolumes.m_pFirst = pNextLightItem;
        else
          in_uListenerMask->pNextLightItem = pNextLightItem;
        v12 = g_LEngineDefaultPoolId;
        v10->vfptr->__vecDelDtor(v10, 0);
        AK::MemoryMgr::Free(v12, v10);
        --m_pFirst->m_OutputDevices.m_uNumDevices;
      }
    }
    else
    {
LABEL_21:
      if ( (i & m_pCtx->m_pGameObj->m_PosKeep.m_uListenerMask) != 0 )
      {
        LOBYTE(in_uListenerMask) = (i & m_pCtx->m_pGameObj->m_PosKeep.m_uListenerMask) != 0;
        v13 = ((__int64 (__fastcall *)(CAkSoundBase *, AkDeviceInfo *))m_pCtx->m_pSound->vfptr[7].Category)(
                m_pCtx->m_pSound,
                in_uListenerMask);
        v14 = !v13 || *(char *)(v13 + 304) < 0;
        if ( v14 == (in_uDevice == 0) )
          CAkLEngine::GetAndConnectBus(m_pCtx, m_pFirst, in_uDevice);
      }
    }
LABEL_28:
    ;
  }
}

// File Line: 1922
// RVA: 0xA52670
void __fastcall CAkLEngine::ReevaluateBussesForGameObject(
        CAkRegisteredObj *in_pObj,
        AkVPL *in_uOldMask,
        unsigned int in_uNewMask)
{
  CAkVPLSrcCbxNode *m_pFirst; // rbp
  int i; // r12d
  CAkVPLSrcNode *v7; // rax
  CAkPBI *m_pCtx; // r14
  AkDevice *j; // rbx
  int v10; // ecx
  unsigned __int64 uDeviceID; // rdi
  __int64 v12; // rax
  bool v13; // cl
  AkDeviceInfo *v14; // r8
  AkDeviceInfo *k; // rax
  AkDeviceInfo *v16; // rcx
  AkDeviceInfo *v17; // rdi
  AkDeviceInfo *pNextLightItem; // rax
  int v19; // esi

  m_pFirst = CAkLEngine::m_Sources.m_pFirst;
  for ( i = (unsigned __int8)in_pObj->m_PosKeep.m_uListenerMask;
        m_pFirst;
        m_pFirst = (CAkVPLSrcCbxNode *)m_pFirst->pNextItem )
  {
    v7 = m_pFirst->m_pSources[0];
    if ( v7 )
      m_pCtx = v7->m_pCtx;
    else
      m_pCtx = 0i64;
    if ( m_pCtx->m_pGameObj == in_pObj )
    {
      for ( j = CAkOutputMgr::m_Devices.m_pItems;
            j != &CAkOutputMgr::m_Devices.m_pItems[CAkOutputMgr::m_Devices.m_uLength];
            ++j )
      {
        v10 = i & j->uListeners;
        if ( (in_uNewMask & j->uListeners) != 0 )
        {
          if ( !v10 )
          {
            uDeviceID = j->uDeviceID;
            v12 = ((__int64 (__fastcall *)(CAkSoundBase *, AkVPL *))m_pCtx->m_pSound->vfptr[7].Category)(
                    m_pCtx->m_pSound,
                    in_uOldMask);
            v13 = !v12 || *(char *)(v12 + 304) < 0;
            if ( v13 == (uDeviceID == 0) )
              CAkLEngine::GetAndConnectBus(m_pCtx, m_pFirst, uDeviceID);
          }
        }
        else if ( v10 )
        {
          v14 = m_pFirst->m_OutputDevices.m_listDeviceVolumes.m_pFirst;
          in_uOldMask = 0i64;
          for ( k = v14; k; k = k->pNextLightItem )
          {
            if ( in_uOldMask )
              break;
            if ( k->uDeviceID == j->uDeviceID )
              in_uOldMask = k->pMixBus;
          }
          *((_BYTE *)&m_pFirst->CAkVPLSrcCbxNodeBase + 76) |= 0x40u;
          v16 = 0i64;
          v17 = v14;
          if ( v14 )
          {
            while ( v17->pMixBus != in_uOldMask )
            {
              v16 = v17;
              v17 = v17->pNextLightItem;
              if ( !v17 )
                goto LABEL_29;
            }
            pNextLightItem = v17->pNextLightItem;
            if ( v17 == v14 )
              m_pFirst->m_OutputDevices.m_listDeviceVolumes.m_pFirst = pNextLightItem;
            else
              v16->pNextLightItem = pNextLightItem;
            v19 = g_LEngineDefaultPoolId;
            v17->vfptr->__vecDelDtor(v17, 0);
            AK::MemoryMgr::Free(v19, v17);
            --m_pFirst->m_OutputDevices.m_uNumDevices;
          }
        }
LABEL_29:
        ;
      }
    }
  }
}

// File Line: 2055
// RVA: 0xA50A30
void CAkLEngine::AnalyzeMixingGraph(void)
{
  CAkVPLSrcCbxNode *i; // rbx
  unsigned int j; // esi
  __int64 v2; // rdi
  MapStruct<unsigned __int64,AkVPL *> *m_pItems; // rdx
  unsigned int m_uLength; // eax
  unsigned int k; // r9d
  AkVPL *v6; // rdx
  AkVPL *m_pParent; // rax
  float m_fNextVolume; // xmm0_4
  float v9; // xmm0_4
  __int64 v10; // rax
  unsigned __int64 *p_uDeviceID; // rcx
  AkDevice *v12; // rax
  CAkVPLSrcCbxNode *m_pFirst; // rbx
  int v14; // eax
  __int64 m; // rbx
  AkVPL *v16; // rcx

  for ( i = CAkLEngine::m_Sources.m_pFirst; i; i = (CAkVPLSrcCbxNode *)i->pNextItem )
  {
    if ( i->m_eState == NodeStatePlay )
    {
      if ( !CAkVPLSrcCbxNodeBase::ComputeVolumeRays(i) )
        CAkVPLSrcCbxNodeBase::CleanupAuxBusses(i);
    }
    else
    {
      for ( j = 0; j < (unsigned __int8)i->m_uNumSends; ++j )
      {
        v2 = j;
        m_pItems = i->m_arSendValues[v2].PerDeviceAuxBusses.m_pItems;
        if ( m_pItems )
        {
          i->m_arSendValues[v2].PerDeviceAuxBusses.m_uLength = 0;
          AK::MemoryMgr::Free(g_DefaultPoolId, m_pItems);
          i->m_arSendValues[v2].PerDeviceAuxBusses.m_pItems = 0i64;
          i->m_arSendValues[v2].PerDeviceAuxBusses.m_ulReserved = 0;
        }
      }
    }
  }
  m_uLength = CAkLEngine::m_arrayVPLs.m_uLength;
  for ( k = 0; k < CAkLEngine::m_arrayVPLs.m_uLength; ++k )
  {
    v6 = CAkLEngine::m_arrayVPLs.m_pItems[k];
    m_pParent = v6->m_MixBus.m_pParent;
    m_fNextVolume = v6->m_MixBus.m_fNextVolume;
    v6->m_fDownstreamGain = m_fNextVolume;
    if ( m_pParent )
    {
      v9 = m_fNextVolume * m_pParent->m_fDownstreamGain;
    }
    else
    {
      v10 = 0i64;
      if ( !CAkOutputMgr::m_Devices.m_uLength )
        goto LABEL_21;
      p_uDeviceID = &CAkOutputMgr::m_Devices.m_pItems->uDeviceID;
      while ( *p_uDeviceID != v6->m_uDevice )
      {
        v10 = (unsigned int)(v10 + 1);
        p_uDeviceID += 10;
        if ( (unsigned int)v10 >= CAkOutputMgr::m_Devices.m_uLength )
          goto LABEL_21;
      }
      v12 = &CAkOutputMgr::m_Devices.m_pItems[v10];
      if ( !v12 )
        goto LABEL_21;
      v9 = m_fNextVolume * v12->pFinalMix->m_fNextVolume;
    }
    v6->m_fDownstreamGain = v9;
LABEL_21:
    m_uLength = CAkLEngine::m_arrayVPLs.m_uLength;
  }
  m_pFirst = CAkLEngine::m_Sources.m_pFirst;
  if ( CAkLEngine::m_Sources.m_pFirst )
  {
    do
    {
      if ( m_pFirst->m_eState == NodeStatePlay )
        CAkVPLSrcCbxNodeBase::ComputeMaxVolume(m_pFirst);
      m_pFirst = (CAkVPLSrcCbxNode *)m_pFirst->pNextItem;
    }
    while ( m_pFirst );
    m_uLength = CAkLEngine::m_arrayVPLs.m_uLength;
  }
  v14 = m_uLength - 1;
  for ( m = v14; m >= 0; --m )
  {
    v16 = CAkLEngine::m_arrayVPLs.m_pItems[m];
    if ( (*((_BYTE *)v16 + 1376) & 2) != 0 )
      AkHdrBus::ComputeHdrAttenuation((AkHdrBus *)v16);
  }
}

// File Line: 2156
// RVA: 0xA505E0
void __fastcall AkHdrBus::AkHdrBus(AkHdrBus *this, AK::CAkBusCtx in_BusCtx)
{
  CAkBus *v3; // rdi
  float RTPCConvertedValue; // xmm1_4
  char *m_pProps; // r8
  unsigned int v6; // r9d
  __int64 v7; // rcx
  __int64 v8; // rdx
  __int64 v9; // rdx
  float *p_out_fRatio; // rax
  char v11; // al
  float out_fRatio; // [rsp+30h] [rbp+8h] BYREF
  CAkBus *m_pBus; // [rsp+38h] [rbp+10h]

  m_pBus = in_BusCtx.m_pBus;
  CAkBusFX::CAkBusFX(&this->m_MixBus);
  v3 = m_pBus;
  this->m_MixBus.m_BusContext.m_pBus = 0i64;
  *((_BYTE *)&this->AkVPL + 1376) &= 0xF6u;
  *((_BYTE *)&this->AkVPL + 1376) |= 2u;
  this->m_fDownstreamGain = 1.0;
  this->m_uDevice = 0i64;
  this->m_fHdrMaxVoiceVolume = -4096.0;
  this->m_fHdrWinTopState = -4096.0;
  this->m_fReleaseCoef = 0.0;
  CAkBus::GetHdrGainComputer(v3, &this->m_fThreshold, &out_fRatio);
  this->m_fGainFactor = 1.0 - (float)(1.0 / out_fRatio);
  if ( (v3->m_RTPCBitArray.m_iBitArray & 0x200000000i64) != 0 )
  {
    RTPCConvertedValue = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, v3, 0x21u, 0i64);
  }
  else
  {
    m_pProps = v3->m_props.m_pProps;
    out_fRatio = g_AkPropDefault[28].fValue;
    if ( m_pProps )
    {
      v6 = (unsigned __int8)*m_pProps;
      v7 = 0i64;
      while ( 1 )
      {
        v8 = (unsigned int)(v7 + 1);
        if ( m_pProps[v8] == 28 )
          break;
        v7 = (unsigned int)v8;
        if ( (unsigned int)v8 >= v6 )
          goto LABEL_7;
      }
      v9 = (__int64)&m_pProps[4 * v7 + ((v6 + 4) & 0xFFFFFFFC)];
    }
    else
    {
LABEL_7:
      v9 = 0i64;
    }
    p_out_fRatio = &out_fRatio;
    if ( v9 )
      p_out_fRatio = (float *)v9;
    out_fRatio = *p_out_fRatio;
    RTPCConvertedValue = out_fRatio;
  }
  v11 = *((_BYTE *)v3 + 304);
  *((_BYTE *)v3 + 304) = v11 & 0xDF;
  *((_BYTE *)&this->AkVPL + 1376) &= ~4u;
  *((_BYTE *)&this->AkVPL + 1376) |= 4 * ((v11 & 0x10) != 0);
  if ( RTPCConvertedValue <= 0.0 )
    this->m_fReleaseCoef = 0.0;
  else
    this->m_fReleaseCoef = expf(-1024.0 / (float)(RTPCConvertedValue * 48000.0));
}

// File Line: 2180
// RVA: 0xA50D50
void __fastcall AkHdrBus::ComputeHdrAttenuation(AkHdrBus *this)
{
  CAkBus *m_pBus; // rsi
  float v3; // xmm9_4
  bool HdrGainComputer; // al
  float v5; // xmm8_4
  float m_fGainFactor; // xmm1_4
  float v7; // xmm7_4
  float v8; // xmm0_4
  float RTPCConvertedValue; // xmm1_4
  char *m_pProps; // r8
  unsigned int v11; // r9d
  __int64 v12; // rcx
  __int64 v13; // rdx
  __int64 v14; // rdx
  float *p_out_fHdrThreshold; // rax
  char v16; // cl
  bool v17; // di
  float m_fReleaseCoef; // xmm2_4
  float m_fHdrWinTopState; // xmm0_4
  float v20; // xmm2_4
  float v21; // xmm6_4
  float v22; // xmm1_4
  int v23; // eax
  float v24; // xmm1_4
  int v25; // eax
  float out_fHdrThreshold; // [rsp+70h] [rbp+8h] BYREF
  float out_fRatio; // [rsp+78h] [rbp+10h] BYREF

  m_pBus = this->m_MixBus.m_BusContext.m_pBus;
  out_fHdrThreshold = this->m_fDownstreamGain;
  LODWORD(out_fRatio) = (LODWORD(out_fHdrThreshold) & 0x7FFFFF) + 1065353216;
  v3 = (float)((float)((float)((float)((float)((float)((float)((float)(out_fRatio - 1.0) / (float)(out_fRatio + 1.0))
                                                     * (float)((float)(out_fRatio - 1.0) / (float)(out_fRatio + 1.0)))
                                             * 0.33333334)
                                     + 1.0)
                             * (float)((float)((float)(out_fRatio - 1.0) / (float)(out_fRatio + 1.0)) * 2.0))
                     + (float)((float)((float)(unsigned __int8)(LODWORD(out_fHdrThreshold) >> 23) - 127.0) * 0.69314718))
             * 0.43429449)
     * 20.0;
  this->m_fDownstreamGainDB = v3;
  HdrGainComputer = CAkBus::GetHdrGainComputer(m_pBus, &out_fHdrThreshold, &out_fRatio);
  v5 = out_fHdrThreshold;
  if ( HdrGainComputer )
  {
    this->m_fThreshold = out_fHdrThreshold;
    m_fGainFactor = 1.0 - (float)(1.0 / out_fRatio);
    this->m_fGainFactor = m_fGainFactor;
  }
  else
  {
    m_fGainFactor = this->m_fGainFactor;
  }
  v7 = 0.0;
  v8 = (float)(this->m_fHdrMaxVoiceVolume - v3) - v5;
  if ( v8 > 0.0 )
    v5 = (float)(v8 * m_fGainFactor) + v5;
  if ( (m_pBus->m_RTPCBitArray.m_iBitArray & 0x200000000i64) != 0 )
  {
    RTPCConvertedValue = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, m_pBus, 0x21u, 0i64);
  }
  else
  {
    m_pProps = m_pBus->m_props.m_pProps;
    out_fHdrThreshold = g_AkPropDefault[28].fValue;
    if ( m_pProps )
    {
      v11 = (unsigned __int8)*m_pProps;
      v12 = 0i64;
      while ( 1 )
      {
        v13 = (unsigned int)(v12 + 1);
        if ( m_pProps[v13] == 28 )
          break;
        v12 = (unsigned int)v13;
        if ( (unsigned int)v13 >= v11 )
          goto LABEL_12;
      }
      v14 = (__int64)&m_pProps[4 * v12 + ((v11 + 4) & 0xFFFFFFFC)];
    }
    else
    {
LABEL_12:
      v14 = 0i64;
    }
    p_out_fHdrThreshold = &out_fHdrThreshold;
    if ( v14 )
      p_out_fHdrThreshold = (float *)v14;
    out_fHdrThreshold = *p_out_fHdrThreshold;
    RTPCConvertedValue = out_fHdrThreshold;
  }
  v16 = *((_BYTE *)m_pBus + 304);
  *((_BYTE *)m_pBus + 304) = v16 & 0xDF;
  v17 = (v16 & 0x10) != 0;
  if ( (v16 & 0x20) != 0 )
  {
    if ( RTPCConvertedValue <= 0.0 )
      this->m_fReleaseCoef = 0.0;
    else
      this->m_fReleaseCoef = expf(-1024.0 / (float)(RTPCConvertedValue * 48000.0));
  }
  m_fReleaseCoef = this->m_fReleaseCoef;
  if ( v17 )
  {
    m_fHdrWinTopState = this->m_fHdrWinTopState;
    if ( v5 < m_fHdrWinTopState )
    {
      v21 = (float)((float)(1.0 - m_fReleaseCoef) * v5) + (float)(m_fHdrWinTopState * m_fReleaseCoef);
      this->m_fHdrWinTopState = v21;
      if ( (float)(v21 - v5) >= 0.5 )
        *((_BYTE *)&this->AkVPL + 1376) |= 1u;
      v20 = this->m_fHdrWinTopState;
    }
    else
    {
      this->m_fHdrWinTopState = v5;
      v20 = v5;
    }
  }
  else
  {
    if ( (float)(v5 * 0.050000001) >= -37.0 )
    {
      if ( (`AkMath::FastPow10::`4::`local static guard & 1) != 0 )
      {
        v22 = *(float *)&`AkMath::FastPow10::`4::SCALE;
      }
      else
      {
        v22 = FLOAT_2_7866352e7;
        `AkMath::FastPow10::`4::SCALE = LODWORD(FLOAT_2_7866352e7);
        `AkMath::FastPow10::`4::`local static guard |= 1u;
      }
      v23 = (int)(float)((float)((float)(v5 * 0.050000001) * v22) + 1065353200.0);
      LODWORD(out_fHdrThreshold) = (v23 & 0x7FFFFF) + 1065353216;
      LODWORD(out_fRatio) = v23 & 0xFF800000;
      v7 = (float)((float)((float)((float)(out_fHdrThreshold * 0.32518977) + 0.020805772) * out_fHdrThreshold)
                 + 0.65304345)
         * COERCE_FLOAT(v23 & 0xFF800000);
    }
    v24 = this->m_fHdrWinTopState;
    if ( v7 < v24 )
    {
      out_fHdrThreshold = (float)((float)(1.0 - m_fReleaseCoef) * v7) + (float)(v24 * m_fReleaseCoef);
      this->m_fHdrWinTopState = out_fHdrThreshold;
      v25 = LODWORD(out_fHdrThreshold) & 0x7FFFFF;
      out_fHdrThreshold = (float)((float)(1.0 - m_fReleaseCoef) * v7) + (float)(v24 * m_fReleaseCoef);
      LODWORD(out_fRatio) = v25 + 1065353216;
      v20 = (float)((float)((float)((float)((float)((float)((float)((float)(out_fRatio - 1.0) / (float)(out_fRatio + 1.0))
                                                          * (float)((float)(out_fRatio - 1.0) / (float)(out_fRatio + 1.0)))
                                                  * 0.33333334)
                                          + 1.0)
                                  * (float)((float)((float)(out_fRatio - 1.0) / (float)(out_fRatio + 1.0)) * 2.0))
                          + (float)((float)((float)(unsigned __int8)(LODWORD(out_fHdrThreshold) >> 23) - 127.0)
                                  * 0.69314718))
                  * 0.43429449)
          * 20.0;
      if ( (float)(v20 - v5) >= 0.5 )
        *((_BYTE *)&this->AkVPL + 1376) |= 1u;
    }
    else
    {
      this->m_fHdrWinTopState = v7;
      v20 = v5;
    }
  }
  this->m_fHdrWinTop = v20 + v3;
  CAkBus::NotifyHdrWindowTop(m_pBus, v20);
  this->m_fHdrMaxVoiceVolume = -4096.0;
}

// File Line: 2283
// RVA: 0xA52890
void CAkLEngine::RemoveMixBusses(void)
{
  __int64 v0; // rbx
  __int64 v1; // r14
  AkVPL *v2; // rdi
  CAkVPLMixBusNode *p_m_MixBus; // rcx
  int v4; // esi
  unsigned int m_uLength; // edx
  AkVPL **v6; // rdi
  AkVPL **v7; // r8

  v0 = CAkLEngine::m_arrayVPLs.m_uLength - 1;
  if ( (signed int)(CAkLEngine::m_arrayVPLs.m_uLength - 1) >= 0 )
  {
    v1 = (int)v0;
    do
    {
      v2 = CAkLEngine::m_arrayVPLs.m_pItems[v1];
      if ( v2->m_MixBus.m_eState == NodeStatePlay || v2->m_MixBus.m_uConnectCount || (*((_BYTE *)v2 + 1376) & 1) != 0 )
      {
        *((_BYTE *)v2 + 1376) &= ~1u;
      }
      else
      {
        p_m_MixBus = &v2->m_MixBus.m_pParent->m_MixBus;
        v4 = g_LEngineDefaultPoolId;
        if ( p_m_MixBus )
          CAkVPLMixBusNode::Disconnect(p_m_MixBus);
        CAkVPLMixBusNode::~CAkVPLMixBusNode(&v2->m_MixBus);
        AK::MemoryMgr::Free(v4, v2);
        m_uLength = CAkLEngine::m_arrayVPLs.m_uLength;
        v6 = &CAkLEngine::m_arrayVPLs.m_pItems[v0];
        v7 = &CAkLEngine::m_arrayVPLs.m_pItems[CAkLEngine::m_arrayVPLs.m_uLength - 1];
        if ( v6 < v7 )
        {
          qmemcpy(v6, v6 + 1, 8 * (((unsigned __int64)((char *)v7 - (char *)v6 - 1) >> 3) + 1));
          m_uLength = CAkLEngine::m_arrayVPLs.m_uLength;
        }
        CAkLEngine::m_arrayVPLs.m_uLength = m_uLength - 1;
      }
      --v1;
      v0 = (unsigned int)(v0 - 1);
    }
    while ( (int)v0 >= 0 );
  }
}

// File Line: 2306
// RVA: 0xA52C00
void __fastcall CAkLEngine::RunVPL(AkRunningVPL *io_runningVPL)
{
  CAkVPLSrcCbxNode *pCbx; // r14
  __int64 v2; // rbx
  CAkVPLFilterNodeBase *v4; // rcx
  AKRESULT result; // eax
  AKRESULT v6; // eax
  CAkVPLSrcNode *v7; // rsi
  AKRESULT v8; // eax
  CAkVPLFilterNodeBase *v9; // rcx
  AKRESULT v10; // eax
  AKRESULT v11; // eax
  CAkVPLSrcNode *v12; // rbx
  unsigned int v13; // ebp
  CAkPBI *m_pCtx; // rbx
  unsigned int i; // ecx
  __int64 m_uNumSends; // rdx
  unsigned int *p_m_uLength; // rsi
  _QWORD *v18; // rbx
  _QWORD *v19; // r15
  AkDeviceInfo *m_pFirst; // rax
  CAkVPLMixBusNode *v21; // r13
  __m128 v22; // xmm3
  __m128 v23; // xmm4
  float *p_gameDef; // rdx
  float *v25; // r8
  __m128 *v26; // rcx
  __int64 v27; // rax
  char *v28; // r9
  char *v29; // r10
  char *v30; // r11
  char *v31; // r15
  __int64 v32; // rax
  __m128 v33; // xmm0
  __m128 v34; // xmm2
  __m128 v35; // xmm2
  __m128 v36; // xmm1
  __m128 v37; // xmm2
  __m128 v38; // xmm2
  __m128 v39; // xmm3
  __m128 v40; // xmm4
  float *p_userDef; // r8
  float *p_fPrev; // r9
  __m128 *v43; // rdx
  __int64 v44; // rax
  char *v45; // r10
  char *v46; // r11
  char *v47; // r15
  char *v48; // r12
  __int64 v49; // rax
  __m128 v50; // xmm0
  __m128 v51; // xmm2
  __m128 v52; // xmm2
  __m128 v53; // xmm1
  __m128 v54; // xmm2
  __m128 v55; // xmm2
  AkDeviceInfo *j; // rbx
  __m128 *v57; // rcx
  __m128 v58; // xmm2
  __m128 v59; // xmm3
  __int64 v60; // rax
  __m128 v61; // xmm0
  __m128 v62; // xmm1
  __m128 v63; // xmm0
  char v64[16]; // [rsp+0h] [rbp-278h] BYREF
  char v65[16]; // [rsp+10h] [rbp-268h] BYREF
  char v66[16]; // [rsp+20h] [rbp-258h] BYREF
  char v67[16]; // [rsp+30h] [rbp-248h] BYREF
  AkAudioMix in_arMix; // [rsp+40h] [rbp-238h] BYREF
  _QWORD *v69; // [rsp+280h] [rbp+8h]
  __int64 v70; // [rsp+288h] [rbp+10h]

  pCbx = io_runningVPL->pCbx;
  LODWORD(v2) = 4;
$GetFilter:
  while ( (_DWORD)v2 )
  {
    v2 = (unsigned int)(v2 - 1);
    v4 = pCbx->m_cbxRec.m_pFilter[v2];
    if ( v4 )
    {
      v4->vfptr[1].VirtualOn(v4, (AkVirtualQueueBehavior)io_runningVPL);
      if ( io_runningVPL->state.result != AK_DataNeeded )
      {
        result = io_runningVPL->state.result;
        if ( result != AK_DataReady && result != AK_NoMoreData )
          return;
LABEL_7:
        LODWORD(v2) = v2 + 1;
        goto $ConsumeFilter;
      }
    }
  }
$GetPitch:
  CAkVPLPitchNode::GetBuffer(&pCbx->m_cbxRec.m_Pitch, &io_runningVPL->state);
  v6 = io_runningVPL->state.result;
  if ( v6 == AK_DataNeeded )
  {
    while ( 1 )
    {
      io_runningVPL->state.uMaxFrames = io_runningVPL->bFeedbackVPL ? 8 : 1024;
      v7 = pCbx->m_pSources[0];
      ((void (__fastcall *)(CAkVPLSrcNode *, AkRunningVPL *))v7->vfptr[1].ReleaseBuffer)(v7, io_runningVPL);
      v8 = io_runningVPL->state.result;
      if ( v8 == AK_NoDataReady && (*((_BYTE *)v7 + 32) & 2) == 0 )
        *((_BYTE *)&pCbx->CAkVPLSrcCbxNodeBase + 76) |= 0x20u;
      if ( v8 != AK_DataReady && v8 != AK_NoMoreData )
        return;
      CAkVPLPitchNode::ConsumeBuffer(&pCbx->m_cbxRec.m_Pitch, &io_runningVPL->state);
      if ( io_runningVPL->state.result != AK_DataNeeded )
      {
        v6 = io_runningVPL->state.result;
        break;
      }
    }
  }
  if ( v6 != AK_DataReady && v6 != AK_NoMoreData )
    return;
$ConsumeFilter:
  while ( (unsigned int)v2 < 4 )
  {
    v9 = pCbx->m_cbxRec.m_pFilter[(unsigned int)v2];
    if ( !v9 )
      goto LABEL_7;
    ((void (__fastcall *)(CAkVPLFilterNodeBase *, AkRunningVPL *))v9->vfptr[1].VirtualOff)(v9, io_runningVPL);
    v10 = io_runningVPL->state.result;
    if ( v10 == AK_DataNeeded )
    {
      if ( (_DWORD)v2 )
        goto $GetFilter;
      goto $GetPitch;
    }
    if ( v10 == AK_DataReady )
      goto LABEL_7;
    if ( v10 != AK_NoMoreData )
      return;
    LODWORD(v2) = v2 + 1;
  }
  CAkVPLLPFNode::ConsumeBuffer(&pCbx->m_cbxRec.m_LPF, &io_runningVPL->state);
  CAkVPLSrcCbxNode::ConsumeBuffer(pCbx, &io_runningVPL->state);
  v11 = io_runningVPL->state.result;
  if ( v11 == AK_DataReady || v11 == AK_NoMoreData )
  {
    CAkPlayingMgr::NotifyMarkers(g_pPlayingMgr, &io_runningVPL->state);
    v12 = pCbx->m_pSources[0];
    v13 = 0;
    if ( v12 )
      m_pCtx = v12->m_pCtx;
    else
      m_pCtx = 0i64;
    if ( (*((_BYTE *)m_pCtx + 374) & 0x40) == 0 )
      CAkPBI::ValidateFeedbackParameters(m_pCtx);
    if ( m_pCtx->m_pFeedbackInfo && pCbx->m_OutputDevices.m_uNumDevices )
    {
      if ( CAkFeedbackDeviceMgr::PrepareAudioProcessing(CAkLEngine::m_pDeviceMgr, io_runningVPL) )
      {
        CAkFeedbackDeviceMgr::ApplyMotionLPF(io_runningVPL);
        CAkFeedbackDeviceMgr::ConsumeVPL(CAkLEngine::m_pDeviceMgr, io_runningVPL);
        CAkFeedbackDeviceMgr::CleanupAudioVPL(io_runningVPL);
      }
      else
      {
        CAkFeedbackDeviceMgr::ConsumeVPL(CAkLEngine::m_pDeviceMgr, io_runningVPL);
      }
    }
    if ( io_runningVPL->state.bAudible )
    {
      for ( i = io_runningVPL->state.uChannelMask; i; i &= i - 1 )
        ++v13;
      if ( !io_runningVPL->state.bIsAuxRoutable )
        goto LABEL_66;
      m_uNumSends = (unsigned __int8)pCbx->m_uNumSends;
      v70 = m_uNumSends;
      if ( !pCbx->m_uNumSends )
        goto LABEL_66;
      p_m_uLength = &pCbx->m_arSendValues[0].PerDeviceAuxBusses.m_uLength;
      while ( 1 )
      {
        v18 = (_QWORD *)*((_QWORD *)p_m_uLength - 1);
        if ( v18 == &v18[2 * *p_m_uLength] )
          goto LABEL_65;
        v19 = &v18[2 * *p_m_uLength];
        v69 = v19;
        do
        {
          m_pFirst = pCbx->m_OutputDevices.m_listDeviceVolumes.m_pFirst;
          v21 = (CAkVPLMixBusNode *)v18[1];
          if ( !m_pFirst )
            goto LABEL_63;
          while ( m_pFirst->uDeviceID != *v18 )
          {
            m_pFirst = m_pFirst->pNextLightItem;
            if ( !m_pFirst )
              goto LABEL_63;
          }
          if ( *(p_m_uLength - 3) )
          {
            if ( v13 )
            {
              v39 = (__m128)*(p_m_uLength - 6);
              v40 = (__m128)*(p_m_uLength - 5);
              p_userDef = (float *)&m_pFirst->mxAttenuations.userDef;
              p_fPrev = &m_pFirst->mxAttenuations.userDef.fPrev;
              v43 = &m_pFirst->mxDirect[0].Previous.vector[1];
              v44 = -(__int64)m_pFirst;
              v45 = &v65[v44];
              v46 = &v67[v44];
              v47 = &v64[v44];
              v48 = &v66[v44];
              v49 = v13;
              do
              {
                v50 = v43[-3];
                v51 = v39;
                v43 += 4;
                v51.m128_f32[0] = v39.m128_f32[0] * *p_userDef;
                v52 = _mm_shuffle_ps(v51, v51, 0);
                *(__m128 *)&v47[(_QWORD)v43 - 64] = _mm_mul_ps(v50, v52);
                v53 = _mm_mul_ps(v43[-6], v52);
                v54 = v40;
                *(__m128 *)&v45[(_QWORD)v43 - 64] = v53;
                v54.m128_f32[0] = v40.m128_f32[0] * *p_fPrev;
                v55 = _mm_shuffle_ps(v54, v54, 0);
                *(__m128 *)&v48[(_QWORD)v43 - 64] = _mm_mul_ps(v43[-5], v55);
                *(__m128 *)&v46[(_QWORD)v43 - 64] = _mm_mul_ps(v43[-4], v55);
                --v49;
              }
              while ( v49 );
              goto LABEL_61;
            }
          }
          else if ( v13 )
          {
            v22 = (__m128)*(p_m_uLength - 6);
            v23 = (__m128)*(p_m_uLength - 5);
            p_gameDef = (float *)&m_pFirst->mxAttenuations.gameDef;
            v25 = &m_pFirst->mxAttenuations.gameDef.fPrev;
            v26 = &m_pFirst->mxDirect[0].Previous.vector[1];
            v27 = -(__int64)m_pFirst;
            v28 = &v65[v27];
            v29 = &v67[v27];
            v30 = &v64[v27];
            v31 = &v66[v27];
            v32 = v13;
            do
            {
              v33 = v26[-3];
              v34 = v22;
              v26 += 4;
              v34.m128_f32[0] = v22.m128_f32[0] * *p_gameDef;
              v35 = _mm_shuffle_ps(v34, v34, 0);
              *(__m128 *)((char *)v26 + (_QWORD)v30 - 64) = _mm_mul_ps(v33, v35);
              v36 = _mm_mul_ps(v26[-6], v35);
              v37 = v23;
              *(__m128 *)((char *)v26 + (_QWORD)v28 - 64) = v36;
              v37.m128_f32[0] = v23.m128_f32[0] * *v25;
              v38 = _mm_shuffle_ps(v37, v37, 0);
              *(__m128 *)((char *)v26 + (_QWORD)v31 - 64) = _mm_mul_ps(v26[-5], v38);
              *(__m128 *)((char *)v26 + (_QWORD)v29 - 64) = _mm_mul_ps(v26[-4], v38);
              --v32;
            }
            while ( v32 );
LABEL_61:
            v19 = v69;
          }
          CAkVPLMixBusNode::ConsumeBuffer(v21, &io_runningVPL->state, &in_arMix);
LABEL_63:
          v18 += 2;
        }
        while ( v18 != v19 );
        m_uNumSends = v70;
LABEL_65:
        p_m_uLength += 8;
        v70 = --m_uNumSends;
        if ( !m_uNumSends )
        {
LABEL_66:
          CAkVPLLPFNode::ConsumeBuffer(&pCbx->m_ObstructionLPF, &io_runningVPL->state);
          if ( !io_runningVPL->bFeedbackVPL )
          {
            for ( j = pCbx->m_OutputDevices.m_listDeviceVolumes.m_pFirst; j; j = j->pNextLightItem )
            {
              if ( !j->bCrossDeviceSend )
              {
                if ( v13 )
                {
                  v57 = &j->mxDirect[0].Previous.vector[1];
                  v58 = _mm_shuffle_ps(
                          (__m128)LODWORD(j->mxAttenuations.dry.fNext),
                          (__m128)LODWORD(j->mxAttenuations.dry.fNext),
                          0);
                  v59 = _mm_shuffle_ps(
                          (__m128)LODWORD(j->mxAttenuations.dry.fPrev),
                          (__m128)LODWORD(j->mxAttenuations.dry.fPrev),
                          0);
                  v60 = v13;
                  do
                  {
                    v61 = v57[-3];
                    v62 = v57[-2];
                    v57 += 4;
                    *(__m128 *)((char *)v57 + v64 - (char *)j - 64) = _mm_mul_ps(v61, v58);
                    v63 = v57[-5];
                    *(__m128 *)((char *)v57 + v65 - (char *)j - 64) = _mm_mul_ps(v62, v58);
                    *(__m128 *)((char *)v57 + v66 - (char *)j - 64) = _mm_mul_ps(v63, v59);
                    *(__m128 *)((char *)v57 + v67 - (char *)j - 64) = _mm_mul_ps(v59, v57[-4]);
                    --v60;
                  }
                  while ( v60 );
                }
                CAkVPLMixBusNode::ConsumeBuffer(&j->pMixBus->m_MixBus, &io_runningVPL->state, &in_arMix);
              }
            }
          }
          return;
        }
      }
    }
  }
}

// File Line: 2547
// RVA: 0xA535B0
void CAkLEngine::SoftwarePerform(void)
{
  CAkLEngineCmds::ProcessAllCommands();
  CAkLEngine::HandleStarvation();
  CAkLEngine::GetBuffer();
  if ( CAkLEngine::m_pDeviceMgr && CAkFeedbackDeviceMgr::IsFeedbackEnabled(CAkLEngine::m_pDeviceMgr) )
    CAkFeedbackDeviceMgr::RenderData(CAkLEngine::m_pDeviceMgr);
  CAkLEngine::RemoveMixBusses();
}

// File Line: 2567
// RVA: 0xA51D60
void CAkLEngine::GetBuffer(void)
{
  CAkVPLSrcCbxNode *m_pFirst; // rbx
  CAkVPLSrcCbxNode *v1; // rsi
  CAkVPLSrcNode *v2; // rax
  CAkPBI *m_pCtx; // rax
  char v4; // al
  CAkVPLSrcNode *v5; // rdi
  CAkVPLSrcCbxNode *v6; // rcx
  CAkVPLSrcNode *v7; // rax
  CAkPBI *v8; // rcx
  CAkVPLSrcCbxNode *m_pLast; // rax
  __int64 i; // rdi
  CAkVPLMixBusNode *p_m_MixBus; // rbx
  AkDevice *m_pItems; // rbx
  __int64 m_uLength; // rdx
  AkDevice *j; // rdi
  __int128 v15; // [rsp+10h] [rbp-39h]
  __int128 v16; // [rsp+20h] [rbp-29h]
  AkRunningVPL io_state; // [rsp+30h] [rbp-19h] BYREF

  if ( g_pPositionRepository->m_mapPosInfo.m_uLength )
    QueryPerformanceCounter((LARGE_INTEGER *)&g_pPositionRepository->m_i64LastTimeUpdated);
  CAkLEngineCmds::ProcessDisconnectedSources(0x400u);
  CAkLEngine::AnalyzeMixingGraph();
  m_pFirst = CAkLEngine::m_Sources.m_pFirst;
  v1 = 0i64;
  if ( CAkLEngine::m_Sources.m_pFirst )
  {
    while ( 1 )
    {
      io_state.state.pData = 0i64;
      io_state.state.uNumMarkers = 0;
      io_state.state.pMarkers = 0i64;
      io_state.state.uMaxFrames = 1024;
      *(_WORD *)&io_state.state.bPause = 0;
      io_state.state.result = AK_DataNeeded;
      v2 = m_pFirst->m_pSources[0];
      if ( v2 )
        m_pCtx = v2->m_pCtx;
      else
        m_pCtx = 0i64;
      v4 = *((_BYTE *)m_pCtx + 374) >> 7;
      io_state.pFeedbackData = 0i64;
      io_state.bFeedbackVPL = v4;
      if ( v4 )
        io_state.state.uMaxFrames = 8;
      if ( m_pFirst->m_eState != NodeStatePlay )
        break;
      if ( CAkVPLSrcCbxNode::StartRun(m_pFirst, &io_state.state) )
      {
        io_state.pCbx = m_pFirst;
        io_state.state.uValidFrames = 0;
        io_state.state.uNumMarkers = 0;
        io_state.state.pMarkers = 0i64;
        io_state.state.posInfo.uStartPos = -1;
        CAkLEngine::RunVPL(&io_state);
        if ( io_state.state.result == AK_NoDataReady )
          CAkVPLSrcCbxNode::RestorePreviousVolumes(io_state.pCbx, &io_state.state);
        else
          CAkVPLSrcCbxNode::ReleaseBuffer(io_state.pCbx);
      }
      if ( io_state.state.result != AK_NoMoreData )
      {
        if ( io_state.state.result != AK_Fail && !io_state.state.bStop )
        {
          if ( io_state.state.bPause )
            m_pFirst->vfptr->Pause(m_pFirst);
          goto LABEL_30;
        }
LABEL_28:
        v6 = m_pFirst;
LABEL_29:
        m_pFirst->vfptr->Stop(v6);
        goto LABEL_30;
      }
      if ( io_state.state.bStop )
        goto LABEL_28;
      v5 = m_pFirst->m_pSources[1];
      v6 = m_pFirst;
      if ( !v5 )
        goto LABEL_29;
      m_pFirst->m_pSources[1] = 0i64;
      CAkVPLSrcCbxNode::RemovePipeline(m_pFirst, CtxDestroyReasonFinished);
      if ( CAkVPLSrcCbxNodeBase::AddSrc(m_pFirst, v5, 1) != AK_Success
        || CAkVPLSrcCbxNode::AddPipeline(m_pFirst) != AK_Success )
      {
        goto LABEL_28;
      }
      CAkVPLSrcNode::Start(v5);
LABEL_30:
      if ( m_pFirst->m_eState == NodeStateStop )
      {
        *((_QWORD *)&v15 + 1) = v1;
        *(_QWORD *)&v15 = m_pFirst->pNextItem;
        if ( m_pFirst == CAkLEngine::m_Sources.m_pFirst )
          CAkLEngine::m_Sources.m_pFirst = (CAkVPLSrcCbxNode *)m_pFirst->pNextItem;
        else
          v1->pNextItem = m_pFirst->pNextItem;
        m_pLast = CAkLEngine::m_Sources.m_pLast;
        v16 = v15;
        if ( m_pFirst == CAkLEngine::m_Sources.m_pLast )
          m_pLast = v1;
        --CAkLEngine::m_Sources.m_ulNumListItems;
        CAkLEngine::m_Sources.m_pLast = m_pLast;
        CAkLEngineCmds::DeleteAllCommandsForSource(m_pFirst);
        CAkLEngine::VPLDestroySource(m_pFirst, 0i64);
        v1 = (CAkVPLSrcCbxNode *)*((_QWORD *)&v16 + 1);
        m_pFirst = (CAkVPLSrcCbxNode *)v16;
      }
      else
      {
        v1 = m_pFirst;
        m_pFirst = (CAkVPLSrcCbxNode *)m_pFirst->pNextItem;
      }
      if ( !m_pFirst )
        goto LABEL_39;
    }
    v7 = m_pFirst->m_pSources[0];
    if ( !v7 )
      goto LABEL_30;
    v8 = v7->m_pCtx;
    if ( !v8 || (*((_BYTE *)v8 + 373) & 0x10) == 0 )
      goto LABEL_30;
    io_state.state.bStop = 1;
    goto LABEL_28;
  }
LABEL_39:
  for ( i = CAkLEngine::m_arrayVPLs.m_uLength - 1; i >= 0; --i )
  {
    p_m_MixBus = &CAkLEngine::m_arrayVPLs.m_pItems[i]->m_MixBus;
    if ( (p_m_MixBus[1].m_PanningVolumes[0].Next.vector[1].m128_i8[0] & 8) == 0 )
    {
      CAkLEngine::TransferBuffer(CAkLEngine::m_arrayVPLs.m_pItems[i]);
      CAkVPLMixBusNode::ReleaseBuffer(p_m_MixBus);
    }
  }
  m_pItems = CAkOutputMgr::m_Devices.m_pItems;
  m_uLength = CAkOutputMgr::m_Devices.m_uLength;
  for ( j = CAkOutputMgr::m_Devices.m_pItems; j != &CAkOutputMgr::m_Devices.m_pItems[CAkOutputMgr::m_Devices.m_uLength]; ++j )
  {
    AkDevice::PushData(j);
    m_uLength = CAkOutputMgr::m_Devices.m_uLength;
    m_pItems = CAkOutputMgr::m_Devices.m_pItems;
  }
  if ( m_pItems != &m_pItems[m_uLength] )
  {
    do
    {
      CAkVPLFinalMixNode::ReleaseBuffer(m_pItems->pFinalMix);
      ++m_pItems;
    }
    while ( m_pItems != &CAkOutputMgr::m_Devices.m_pItems[CAkOutputMgr::m_Devices.m_uLength] );
  }
}

