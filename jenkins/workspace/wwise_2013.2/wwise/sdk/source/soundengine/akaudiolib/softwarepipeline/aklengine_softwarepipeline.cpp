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
  if ( CAkOutputMgr::AddMainDevice(&in_outputSettings, in_eSinkType, 0xFFu, 0i64) != 1
    && CAkOutputMgr::AddMainDevice(&in_outputSettings, AkSink_Dummy, 0xFFu, 0i64) != 1 )
  {
    return 2;
  }
  g_pAkSink = CAkOutputMgr::m_Devices.m_pItems->pSink;
  in_outputSettings.uChannelMask = g_pAkSink->m_SpeakersConfig;
  result = hkaReferencePoseAnimation::getNumOriginalFrames((hkEntitySelectorAll *)g_pAkSink, v1);
  if ( result == 1 )
  {
    result = CAkLEngineCmds::Init();
    if ( result == 1 )
    {
      CAkSpeakerPan::Init();
      result = 1;
    }
  }
  return result;
}

// File Line: 112
// RVA: 0xA535F0
void CAkLEngine::SoftwareTerm(void)
{
  AkStaticArray<void *,void *,2> *v0; // rsi
  signed __int64 v1; // rbp
  void **v2; // rbx
  __int64 v3; // rdi

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
      v2 = v0->m_Items;
      v3 = v0->m_cItems;
      do
      {
        AK::MemoryMgr::Free(g_LEngineDefaultPoolId, *v2);
        ++v2;
        --v3;
      }
      while ( v3 );
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
  AkVPL *v1; // rdi
  CAkVPLMixBusNode *v2; // rsi
  bool v3; // al
  __int64 v4; // rax
  unsigned __int64 *v5; // rcx
  AkDevice *v6; // rsi
  bool v7; // al
  AkAudioBufferBus *io_rpBuffer; // [rsp+30h] [rbp+8h]

  v1 = in_pVPL;
  CAkVPLMixBusNode::GetResultingBuffer(&in_pVPL->m_MixBus, &io_rpBuffer);
  CAkBusVolumes::UpdateFinalVolumes((CAkBusVolumes *)v1->m_MixBus.m_PanningVolumes);
  v2 = &v1->m_MixBus.m_pParent->m_MixBus;
  if ( v2 )
  {
    v3 = CAkVPLMixBusNode::IsPanning(&v1->m_MixBus);
    CAkVPLMixBusNode::ConsumeBuffer(v2, io_rpBuffer, v3, v1->m_MixBus.m_FinalVolumes);
  }
  else
  {
    v4 = 0i64;
    if ( CAkOutputMgr::m_Devices.m_uLength )
    {
      v5 = &CAkOutputMgr::m_Devices.m_pItems->uDeviceID;
      while ( *v5 != v1->m_uDevice )
      {
        v4 = (unsigned int)(v4 + 1);
        v5 += 10;
        if ( (unsigned int)v4 >= CAkOutputMgr::m_Devices.m_uLength )
          return;
      }
      v6 = &CAkOutputMgr::m_Devices.m_pItems[v4];
      if ( v6 )
      {
        v7 = CAkVPLMixBusNode::IsPanning(&v1->m_MixBus);
        CAkVPLFinalMixNode::ConsumeBuffer(v6->pFinalMix, io_rpBuffer, v7, v1->m_MixBus.m_FinalVolumes);
      }
    }
  }
}

// File Line: 176
// RVA: 0x15BDFC0
__int64 dynamic_initializer_for__CAkLEngine::m_arrayVPLs__()
{
  return atexit(dynamic_atexit_destructor_for__CAkLEngine::m_arrayVPLs__);
}

// File Line: 177
// RVA: 0x15BDF80
__int64 dynamic_initializer_for__CAkLEngine::m_CachedAudioBuffers__()
{
  AkStaticArray<void *,void *,2> *v0; // rax
  signed int v1; // ecx

  v0 = CAkLEngine::m_CachedAudioBuffers;
  v1 = 15;
  do
  {
    --v1;
    v0->m_cItems = 0;
    ++v0;
  }
  while ( v1 >= 0 );
  return atexit(dynamic_atexit_destructor_for__CAkLEngine::m_CachedAudioBuffers__);
}

// File Line: 178
// RVA: 0x15BDFB0
__int64 dynamic_initializer_for__CAkLEngine::m_Sources__()
{
  return atexit(dynamic_atexit_destructor_for__CAkLEngine::m_Sources__);
}

// File Line: 181
// RVA: 0xA536E0
void CAkLEngine::Stop(void)
{
  CAkVPLSrcCbxNode *v0; // rax
  CAkVPLSrcCbxNode *v1; // rdx
  CAkVPLSrcCbxNode *v2; // rcx
  CAkVPLSrcCbxNodeBase *v3; // rbx
  CAkVPLSrcCbxNode *v4; // rax
  bool v5; // zf
  CAkBusFX **i; // rbx
  __m128i v7; // [rsp+20h] [rbp-28h]
  __m128i v8; // [rsp+30h] [rbp-18h]

  v0 = CAkLEngine::m_Sources.m_pFirst;
  v1 = 0i64;
  v2 = CAkLEngine::m_Sources.m_pFirst;
  if ( CAkLEngine::m_Sources.m_pFirst )
  {
    while ( 1 )
    {
      v3 = v2->pNextItem;
      v7.m128i_i64[1] = (__int64)v1;
      v7.m128i_i64[0] = (__int64)v2->pNextItem;
      if ( v2 == v0 )
        CAkLEngine::m_Sources.m_pFirst = (CAkVPLSrcCbxNode *)v2->pNextItem;
      else
        v1->pNextItem = v3;
      v4 = CAkLEngine::m_Sources.m_pLast;
      v5 = v2 == CAkLEngine::m_Sources.m_pLast;
      _mm_store_si128(&v8, v7);
      if ( v5 )
        v4 = v1;
      --CAkLEngine::m_Sources.m_ulNumListItems;
      CAkLEngine::m_Sources.m_pLast = v4;
      CAkLEngine::VPLDestroySource((CAkVPLSrcCbxNodeBase *)&v2->vfptr, 0i64);
      if ( !v3 )
        break;
      v1 = (CAkVPLSrcCbxNode *)v8.m128i_i64[1];
      v2 = (CAkVPLSrcCbxNode *)v8.m128i_i64[0];
      v0 = CAkLEngine::m_Sources.m_pFirst;
    }
  }
  CAkLEngine::DestroyAllVPLMixBusses();
  for ( i = (CAkBusFX **)CAkOutputMgr::m_Devices.m_pItems;
        i != (CAkBusFX **)&CAkOutputMgr::m_Devices.m_pItems[CAkOutputMgr::m_Devices.m_uLength];
        i += 10 )
  {
    CAkBusFX::DropFx(*i);
  }
  CAkLEngineCmds::DestroyDisconnectedSources();
}

// File Line: 892
// RVA: 0xA52A10
void __fastcall CAkLEngine::ResetBusVolume(unsigned int in_MixBusID, float in_Volume)
{
  AkVPL **v2; // rbx
  unsigned int i; // esi
  CAkVPLMixBusNode *v4; // rdi

  v2 = CAkLEngine::m_arrayVPLs.m_pItems;
  for ( i = in_MixBusID; v2 != &CAkLEngine::m_arrayVPLs.m_pItems[CAkLEngine::m_arrayVPLs.m_uLength]; ++v2 )
  {
    v4 = (CAkVPLMixBusNode *)*v2;
    if ( AK::CAkBusCtx::ID(&(*v2)->m_MixBus.m_BusContext) == i )
      CAkVPLMixBusNode::ResetNextVolume(v4, in_Volume);
  }
}

// File Line: 914
// RVA: 0xA52A90
void __fastcall CAkLEngine::ResetMasterBusVolume(bool in_bMain, float in_Volume)
{
  __int64 v2; // rax
  unsigned __int64 *v3; // rcx
  CAkBusVolumes **v4; // rbx
  CAkBusVolumes *v5; // rbx
  AkDevice *v6; // rdx
  unsigned int v7; // er8
  AkDevice *v8; // rbx
  CAkBusVolumes *v9; // rdi

  if ( in_bMain )
  {
    v2 = 0i64;
    if ( CAkOutputMgr::m_Devices.m_uLength )
    {
      v3 = &CAkOutputMgr::m_Devices.m_pItems->uDeviceID;
      while ( *v3 )
      {
        v2 = (unsigned int)(v2 + 1);
        v3 += 10;
        if ( (unsigned int)v2 >= CAkOutputMgr::m_Devices.m_uLength )
          return;
      }
      v4 = (CAkBusVolumes **)&CAkOutputMgr::m_Devices.m_pItems[v2];
      if ( v4 )
      {
        v5 = *v4;
        CAkBusVolumes::SetNextVolume(v5, in_Volume);
        CAkBusVolumes::Update2DParams(v5, 0i64);
      }
    }
  }
  else
  {
    v6 = CAkOutputMgr::m_Devices.m_pItems;
    v7 = CAkOutputMgr::m_Devices.m_uLength;
    v8 = CAkOutputMgr::m_Devices.m_pItems;
    if ( CAkOutputMgr::m_Devices.m_pItems != &CAkOutputMgr::m_Devices.m_pItems[CAkOutputMgr::m_Devices.m_uLength] )
    {
      do
      {
        if ( v8->uDeviceID )
        {
          v9 = (CAkBusVolumes *)v8->pFinalMix->m_PanningVolumes;
          CAkBusVolumes::SetNextVolume((CAkBusVolumes *)v8->pFinalMix->m_PanningVolumes, in_Volume);
          CAkBusVolumes::Update2DParams(v9, 0i64);
          v7 = CAkOutputMgr::m_Devices.m_uLength;
          v6 = CAkOutputMgr::m_Devices.m_pItems;
        }
        ++v8;
      }
      while ( v8 != &v6[v7] );
    }
  }
}

// File Line: 943
// RVA: 0xA531A0
void __fastcall CAkLEngine::SetBusVolume(unsigned int in_MixBusID, float in_VolumeOffset)
{
  AkVPL **v2; // rbx
  float v3; // xmm7_4
  unsigned int i; // esi
  AK::CAkBusCtx *v5; // rdi
  float v6; // xmm0_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm1_4

  v2 = CAkLEngine::m_arrayVPLs.m_pItems;
  v3 = in_VolumeOffset;
  for ( i = in_MixBusID; v2 != &CAkLEngine::m_arrayVPLs.m_pItems[CAkLEngine::m_arrayVPLs.m_uLength]; ++v2 )
  {
    v5 = (AK::CAkBusCtx *)*v2;
    if ( AK::CAkBusCtx::ID(&(*v2)->m_MixBus.m_BusContext) == i )
    {
      v6 = v3 + *((float *)&v5[137].m_pBus + 1);
      *((float *)&v5[137].m_pBus + 1) = v6;
      v7 = v6 * 0.050000001;
      if ( v7 >= -37.0 )
      {
        if ( `AkMath::FastPow10'::`4'::`local static guard' & 1 )
        {
          v9 = *(float *)&`AkMath::FastPow10'::`4'::SCALE;
        }
        else
        {
          v9 = FLOAT_2_7866352e7;
          `AkMath::FastPow10'::`4'::`local static guard' |= 1u;
          `AkMath::FastPow10'::`4'::SCALE = LODWORD(FLOAT_2_7866352e7);
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
      *((float *)&v5[136].m_pBus + 1) = v8;
    }
  }
}

// File Line: 965
// RVA: 0xA53360
void __fastcall CAkLEngine::SetMasterBusVolume(bool in_bMain, float in_VolumeOffset)
{
  __int64 v2; // rax
  unsigned __int64 *v3; // rcx
  CAkBusVolumes **v4; // rcx
  AkDevice *v5; // rdx
  unsigned int v6; // er8
  AkDevice *v7; // rbx

  if ( in_bMain )
  {
    v2 = 0i64;
    if ( CAkOutputMgr::m_Devices.m_uLength )
    {
      v3 = &CAkOutputMgr::m_Devices.m_pItems->uDeviceID;
      while ( *v3 )
      {
        v2 = (unsigned int)(v2 + 1);
        v3 += 10;
        if ( (unsigned int)v2 >= CAkOutputMgr::m_Devices.m_uLength )
          return;
      }
      v4 = (CAkBusVolumes **)&CAkOutputMgr::m_Devices.m_pItems[v2];
      if ( v4 )
        CAkBusVolumes::SetVolumeOffset(*v4, in_VolumeOffset);
    }
  }
  else
  {
    v5 = CAkOutputMgr::m_Devices.m_pItems;
    v6 = CAkOutputMgr::m_Devices.m_uLength;
    v7 = CAkOutputMgr::m_Devices.m_pItems;
    if ( CAkOutputMgr::m_Devices.m_pItems != &CAkOutputMgr::m_Devices.m_pItems[CAkOutputMgr::m_Devices.m_uLength] )
    {
      do
      {
        if ( v7->uDeviceID )
        {
          CAkBusVolumes::SetVolumeOffset((CAkBusVolumes *)v7->pFinalMix->m_PanningVolumes, in_VolumeOffset);
          v6 = CAkOutputMgr::m_Devices.m_uLength;
          v5 = CAkOutputMgr::m_Devices.m_pItems;
        }
        ++v7;
      }
      while ( v7 != &v5[v6] );
    }
  }
}

// File Line: 1009
// RVA: 0xA50BE0
void __fastcall CAkLEngine::BypassBusFx(unsigned int in_MixBusID, unsigned int in_bitsFXBypass, unsigned int in_uTargetMask)
{
  AkVPL **v3; // rbx
  unsigned int v4; // esi
  unsigned int v5; // ebp
  unsigned int i; // er14
  AK::CAkBusCtx *v7; // rdi

  v3 = CAkLEngine::m_arrayVPLs.m_pItems;
  v4 = in_uTargetMask;
  v5 = in_bitsFXBypass;
  for ( i = in_MixBusID; v3 != &CAkLEngine::m_arrayVPLs.m_pItems[CAkLEngine::m_arrayVPLs.m_uLength]; ++v3 )
  {
    v7 = (AK::CAkBusCtx *)*v3;
    if ( AK::CAkBusCtx::ID(&(*v3)->m_MixBus.m_BusContext) == i )
      CAkBusFX::SetInsertFxBypass((CAkBusFX *)v7, v5, v4);
  }
}

// File Line: 1034
// RVA: 0xA50C80
void __fastcall CAkLEngine::BypassMasterBusFx(unsigned int in_bitsFXBypass, unsigned int in_uTargetMask)
{
  __int64 v2; // rax
  unsigned int v3; // er11
  unsigned __int64 *v4; // r8
  CAkBusFX **v5; // rcx

  v2 = 0i64;
  v3 = in_bitsFXBypass;
  if ( CAkOutputMgr::m_Devices.m_uLength )
  {
    v4 = &CAkOutputMgr::m_Devices.m_pItems->uDeviceID;
    while ( *v4 )
    {
      v2 = (unsigned int)(v2 + 1);
      v4 += 10;
      if ( (unsigned int)v2 >= CAkOutputMgr::m_Devices.m_uLength )
        return;
    }
    v5 = (CAkBusFX **)&CAkOutputMgr::m_Devices.m_pItems[v2];
    if ( v5 )
      CAkBusFX::SetInsertFxBypass(*v5, v3, in_uTargetMask);
  }
}

// File Line: 1042
// RVA: 0xA52470
void __fastcall CAkLEngine::PositioningChangeNotification(unsigned int in_MixBusID, float in_RTPCValue, AkRTPC_ParameterID in_ParameterID)
{
  AkVPL **v3; // rbx
  AkRTPC_ParameterID v4; // esi
  unsigned int i; // ebp
  AK::CAkBusCtx *v6; // rdi

  v3 = CAkLEngine::m_arrayVPLs.m_pItems;
  v4 = in_ParameterID;
  for ( i = in_MixBusID; v3 != &CAkLEngine::m_arrayVPLs.m_pItems[CAkLEngine::m_arrayVPLs.m_uLength]; ++v3 )
  {
    v6 = (AK::CAkBusCtx *)*v3;
    if ( AK::CAkBusCtx::ID(&(*v3)->m_MixBus.m_BusContext) == i )
      CAkBusVolumes::PositioningChangeNotification((CAkBusVolumes *)v6, in_RTPCValue, v4);
  }
}

// File Line: 1055
// RVA: 0xA537C0
void __fastcall CAkLEngine::StopMixBussesUsingThisSlot(CAkUsageSlot *in_pSlot)
{
  AkVPL **v1; // rbx
  CAkUsageSlot *i; // r14
  AkVPL *v3; // rbp
  unsigned int v4; // esi
  CAkEffectContextBase **v5; // rdi
  AkDevice *j; // rbx
  CAkBusFX *v7; // rbp
  unsigned int v8; // esi
  CAkEffectContextBase **v9; // rdi

  v1 = CAkLEngine::m_arrayVPLs.m_pItems;
  for ( i = in_pSlot; v1 != &CAkLEngine::m_arrayVPLs.m_pItems[CAkLEngine::m_arrayVPLs.m_uLength]; ++v1 )
  {
    v3 = *v1;
    v4 = 0;
    v5 = (CAkEffectContextBase **)&(*v1)->m_MixBus.m_aFX[0].pBusFXContext;
    while ( !*v5 || !CAkEffectContextBase::IsUsingThisSlot(*v5, i, (AK::IAkPlugin *)*(v5 - 1)) )
    {
      ++v4;
      v5 += 5;
      if ( v4 >= 4 )
        goto LABEL_8;
    }
    CAkBusFX::DropFx((CAkBusFX *)v3->m_MixBus.m_PanningVolumes);
LABEL_8:
    ;
  }
  for ( j = CAkOutputMgr::m_Devices.m_pItems; j != &CAkOutputMgr::m_Devices.m_pItems[CAkOutputMgr::m_Devices.m_uLength]; ++j )
  {
    v7 = (CAkBusFX *)j->pFinalMix->m_PanningVolumes;
    if ( j->pFinalMix )
    {
      v8 = 0;
      v9 = (CAkEffectContextBase **)&v7->m_aFX[0].pBusFXContext;
      while ( !*v9 || !CAkEffectContextBase::IsUsingThisSlot(*v9, i, (AK::IAkPlugin *)*(v9 - 1)) )
      {
        ++v8;
        v9 += 5;
        if ( v8 >= 4 )
          goto LABEL_17;
      }
      CAkBusFX::DropFx(v7);
      LODWORD(v7[1].m_PanningVolumes[0].Next.volumes.fFrontLeft) = 2;
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
  __int64 v2; // r9
  AkStaticArray<void *,void *,2> *v3; // r8
  void **v4; // rcx

  if ( in_uSize < 0x800 )
    in_uSize = 2048;
  v2 = CAkLEngine::m_CachedAudioBuffers[(unsigned __int64)(in_uSize - 1) >> 11].m_cItems;
  v3 = &CAkLEngine::m_CachedAudioBuffers[(unsigned __int64)(in_uSize - 1) >> 11];
  if ( (unsigned int)v2 < 2 && (v4 = &v3->m_Items[v2], v3->m_cItems = v2 + 1, v4) )
    *v4 = in_pvBuffer;
  else
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, in_pvBuffer);
}

// File Line: 1136
// RVA: 0xA539E0
void __fastcall CAkLEngine::UpdateMasterBusFX(unsigned int in_uFXIndex)
{
  __int64 v1; // rax
  unsigned int v2; // er10
  unsigned __int64 *v3; // rdx
  CAkBusFX **v4; // rcx

  v1 = 0i64;
  v2 = in_uFXIndex;
  if ( CAkOutputMgr::m_Devices.m_uLength )
  {
    v3 = &CAkOutputMgr::m_Devices.m_pItems->uDeviceID;
    while ( *v3 )
    {
      v1 = (unsigned int)(v1 + 1);
      v3 += 10;
      if ( (unsigned int)v1 >= CAkOutputMgr::m_Devices.m_uLength )
        return;
    }
    v4 = (CAkBusFX **)&CAkOutputMgr::m_Devices.m_pItems[v1];
    if ( v4 )
      CAkBusFX::SetInsertFx(*v4, &g_MasterBusCtx, v2);
  }
}

// File Line: 1143
// RVA: 0xA53A40
void __fastcall CAkLEngine::UpdateMixBusFX(unsigned int in_MixBusID, unsigned int in_uFXIndex)
{
  AkVPL **v2; // rbx
  unsigned int v3; // ebp
  unsigned int i; // er14
  AK::CAkBusCtx *v5; // rdi

  v2 = CAkLEngine::m_arrayVPLs.m_pItems;
  v3 = in_uFXIndex;
  for ( i = in_MixBusID; v2 != &CAkLEngine::m_arrayVPLs.m_pItems[CAkLEngine::m_arrayVPLs.m_uLength]; ++v2 )
  {
    v5 = (AK::CAkBusCtx *)*v2;
    if ( AK::CAkBusCtx::ID(&(*v2)->m_MixBus.m_BusContext) == i && LODWORD(v5[167].m_pBus) != 2 )
      CAkBusFX::SetInsertFx((CAkBusFX *)v5, v5 + 166, v3);
  }
}

// File Line: 1163
// RVA: 0xA517E0
void __fastcall CAkLEngine::ForAllPluginParam(CAkFxBase *in_pFx, void (__fastcall *in_funcForAll)(AK::IAkPluginParam *, CAkRegisteredObj *, void *), void *in_pCookie)
{
  __int64 v3; // rax
  void *v4; // r14
  void (__fastcall *v5)(AK::IAkPluginParam *, CAkRegisteredObj *, void *); // r12
  CAkFxBase *v6; // r15
  unsigned __int64 *v7; // r9
  AkDevice *v8; // rax
  unsigned int v9; // ebx
  AK::IAkPluginParam **v10; // rdi
  CAkFxBase *v11; // rcx
  AkVPL **i; // rbx
  unsigned int v13; // edi
  AK::CAkBusCtx *v14; // rbp
  AK::IAkPluginParam **v15; // rsi
  CAkFxBase *v16; // rcx
  CAkVPLSrcCbxNode *v17; // rbx
  CAkVPLSrcNode *v18; // rcx
  CAkPBI *v19; // rax
  CAkRegisteredObj *v20; // r13
  CAkPBI *v21; // rax
  CAkSoundBase *v22; // r12
  __int64 v23; // r14
  unsigned int v24; // esi
  _RTL_CRITICAL_SECTION *v25; // rbp
  CAkFxBase *v26; // rdi
  unsigned int v27; // esi
  CAkVPLFilterNodeBase **v28; // r14
  CAkVPLFilterNodeBase *v29; // rbp
  CAkIndexableVtbl *v30; // rdi
  CAkPBI *v31; // rax
  CAkFxBase *v32; // rcx
  AkFXDesc out_rFXInfo; // [rsp+20h] [rbp-48h]
  void (__fastcall *v34)(AK::IAkPluginParam *, CAkRegisteredObj *, void *); // [rsp+78h] [rbp+10h]
  void *v35; // [rsp+80h] [rbp+18h]

  v35 = in_pCookie;
  v34 = in_funcForAll;
  v3 = 0i64;
  v4 = in_pCookie;
  v5 = in_funcForAll;
  v6 = in_pFx;
  if ( CAkOutputMgr::m_Devices.m_uLength )
  {
    v7 = &CAkOutputMgr::m_Devices.m_pItems->uDeviceID;
    while ( *v7 )
    {
      v3 = (unsigned int)(v3 + 1);
      v7 += 10;
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
  v10 = &v8->pFinalMix->m_aFX[0].pParam;
  do
  {
    out_rFXInfo.pFx.m_pT = 0i64;
    AK::CAkBusCtx::GetFX(&g_MasterBusCtx, v9, &out_rFXInfo);
    v11 = out_rFXInfo.pFx.m_pT;
    if ( out_rFXInfo.pFx.m_pT )
    {
      if ( out_rFXInfo.pFx.m_pT == v6 && *v10 )
      {
        v5(*v10, 0i64, v4);
        v11 = out_rFXInfo.pFx.m_pT;
      }
      if ( v11 )
      {
        ((void (*)(void))v11->vfptr->Release)();
        out_rFXInfo.pFx.m_pT = 0i64;
      }
    }
    ++v9;
    v10 += 5;
  }
  while ( v9 < 4 );
  for ( i = CAkLEngine::m_arrayVPLs.m_pItems; i != &CAkLEngine::m_arrayVPLs.m_pItems[CAkLEngine::m_arrayVPLs.m_uLength]; ++i )
  {
    v13 = 0;
    v14 = &(*i)->m_MixBus.m_BusContext;
    v15 = &(*i)->m_MixBus.m_aFX[0].pParam;
    do
    {
      out_rFXInfo.pFx.m_pT = 0i64;
      AK::CAkBusCtx::GetFX(v14, v13, &out_rFXInfo);
      v16 = out_rFXInfo.pFx.m_pT;
      if ( out_rFXInfo.pFx.m_pT )
      {
        if ( out_rFXInfo.pFx.m_pT == v6 && *v15 )
        {
          v5(*v15, 0i64, v4);
          v16 = out_rFXInfo.pFx.m_pT;
        }
        if ( v16 )
        {
          ((void (*)(void))v16->vfptr->Release)();
          out_rFXInfo.pFx.m_pT = 0i64;
        }
      }
      ++v13;
      v15 += 5;
    }
    while ( v13 < 4 );
  }
  v17 = CAkLEngine::m_Sources.m_pFirst;
  if ( CAkLEngine::m_Sources.m_pFirst )
  {
    do
    {
      v18 = v17->m_pSources[0];
      if ( v18 )
        v19 = v18->m_pCtx;
      else
        v19 = 0i64;
      v20 = v19->m_pGameObj;
      if ( v18 )
        v21 = v18->m_pCtx;
      else
        v21 = 0i64;
      v22 = v21->m_pSound;
      if ( v18 )
      {
        v23 = ((__int64 (*)(void))v18->vfptr[1].VirtualOff)();
        if ( v23 )
        {
          if ( v22->vfptr->Category((CAkIndexable *)&v22->vfptr) == 4 )
          {
            v24 = (unsigned int)v22[1].vfptr;
            v25 = &g_pIndex->m_idxFxCustom.m_IndexLock.m_csLock;
            EnterCriticalSection(&g_pIndex->m_idxFxCustom.m_IndexLock.m_csLock);
            v26 = (CAkFxBase *)*((_QWORD *)&v25[1].DebugInfo + v24 % 0xC1);
            if ( !v26 )
              goto LABEL_38;
            while ( v26->key != v24 )
            {
              v26 = (CAkFxBase *)v26->pNextItem;
              if ( !v26 )
                goto LABEL_38;
            }
            if ( v26 )
            {
              ++v26->m_lRef;
              LeaveCriticalSection(v25);
              if ( v26 == v6 )
                v34((AK::IAkPluginParam *)v23, v20, v35);
              v26->vfptr->Release((CAkIndexable *)&v26->vfptr);
            }
            else
            {
LABEL_38:
              LeaveCriticalSection(v25);
            }
          }
        }
      }
      v27 = 0;
      v28 = v17->m_cbxRec.m_pFilter;
      do
      {
        v29 = *v28;
        if ( *v28 )
        {
          v30 = v22->vfptr;
          out_rFXInfo.pFx.m_pT = 0i64;
          v31 = CAkVPLSrcCbxNodeBase::GetContext((CAkVPLSrcCbxNodeBase *)&v17->vfptr);
          ((void (__fastcall *)(CAkSoundBase *, _QWORD, AkFXDesc *, CAkRegisteredObj *))v30[14].__vecDelDtor)(
            v22,
            v27,
            &out_rFXInfo,
            v31->m_pGameObj);
          v32 = out_rFXInfo.pFx.m_pT;
          if ( out_rFXInfo.pFx.m_pT )
          {
            if ( out_rFXInfo.pFx.m_pT == v6 && v29->m_pParam )
            {
              v34(v29->m_pParam, v20, v35);
              v32 = out_rFXInfo.pFx.m_pT;
            }
            if ( v32 )
            {
              ((void (*)(void))v32->vfptr->Release)();
              out_rFXInfo.pFx.m_pT = 0i64;
            }
          }
        }
        ++v27;
        ++v28;
      }
      while ( v27 < 4 );
      v17 = (CAkVPLSrcCbxNode *)v17->pNextItem;
    }
    while ( v17 );
  }
}

// File Line: 1268
// RVA: 0xA52B90
CAkVPLSrcCbxNode *__fastcall CAkLEngine::ResolveCommandVPL(AkLECmd *io_cmd)
{
  CAkPBI *v1; // r8
  CAkVPLSrcCbxNode *result; // rax
  AkLECmd *v3; // r9
  CAkVPLSrcNode *v4; // rdx
  CAkVPLSrcNode *v5; // rcx
  CAkVPLSrcNode *v6; // rcx

  v1 = io_cmd->m_pCtx;
  result = CAkLEngine::m_Sources.m_pFirst;
  v3 = io_cmd;
  while ( result )
  {
    v4 = result->m_pSources[0];
    if ( v4 && v4->m_pCtx == v1 || v3->m_eState == 5 && (v5 = result->m_pSources[1]) != 0i64 && v5->m_pCtx == v1 )
    {
      if ( result->m_eState )
        v3->m_bSourceConnected = 1;
      return result;
    }
    result = (CAkVPLSrcCbxNode *)result->pNextItem;
  }
  result = (CAkVPLSrcCbxNode *)v1->m_pCbx;
  if ( !result || ((v6 = result->m_pSources[0]) == 0i64 || v6->m_pCtx != v1) && v3->m_eState != 5 )
    result = 0i64;
  return result;
}

// File Line: 1321
// RVA: 0xA51B30
AkVPL *__fastcall CAkLEngine::GetAndConnectBus(CAkPBI *in_pCtx, CAkVPLSrcCbxNodeBase *in_pCbx, unsigned __int64 in_uDevice)
{
  AkVPL *v3; // rdi
  unsigned __int64 v4; // rbp
  CAkVPLSrcCbxNodeBase *v5; // rsi
  CAkPBI *v6; // r14
  CAkBus *v7; // rax
  unsigned __int8 v8; // r15
  char v9; // r15
  unsigned int v10; // eax
  AkVPL *v11; // rbx
  AkVPL *v12; // rcx
  AK::CAkBusCtx in_ctxBus; // [rsp+40h] [rbp+8h]

  v3 = 0i64;
  v4 = in_uDevice;
  v5 = in_pCbx;
  in_ctxBus.m_pBus = 0i64;
  v6 = in_pCtx;
  v7 = CAkPBI::GetOutputBusPtr(in_pCtx);
  v8 = *((_BYTE *)v6 + 374);
  in_ctxBus.m_pBus = v7;
  v9 = v8 >> 7;
  v10 = AK::CAkBusCtx::ID(&in_ctxBus);
  v11 = CAkLEngine::GetExistingVPLMixBus(v10, v4);
  if ( !v11 )
    v11 = CAkLEngine::GetVPLMixBusInternal(&in_ctxBus, v4, v9);
  if ( v11 )
  {
    if ( *((_BYTE *)v6 + 376) & 1 )
    {
      if ( *((_BYTE *)v11 + 1376) & 2 )
      {
        v3 = v11;
      }
      else
      {
        v12 = v11->m_MixBus.m_pParent;
        if ( v12 )
          v3 = AkVPL::GetHdrBus(v12);
      }
      v5->m_pHdrBus = (AkHdrBus *)v3;
    }
    CAkVPLSrcCbxNodeBase::AddOutputBus(v5, v11, v4, 0);
  }
  return v11;
}

// File Line: 1348
// RVA: 0xA51C00
AkVPL *__fastcall CAkLEngine::GetAuxBus(CAkBus *in_pAuxBus, AkMergedEnvironmentValue *in_pSend, unsigned __int64 in_uDevice, CAkVPLSrcCbxNodeBase *in_pCbx)
{
  AkMergedEnvironmentValue *v4; // rsi
  CAkBus *v5; // r14
  CAkVPLSrcCbxNodeBase *v6; // rbp
  unsigned __int64 v7; // rdi
  AkVPL *v8; // rbx
  unsigned int v9; // eax
  MapStruct<unsigned __int64,AkVPL *> *v10; // rax
  signed __int64 v11; // rcx
  CAkVPLSrcNode *v12; // rcx
  __int64 v13; // rax
  bool v14; // cl
  AkDeviceInfo *v15; // rax
  AK::CAkBusCtx in_ctxBus; // [rsp+48h] [rbp+10h]

  v4 = in_pSend;
  v5 = in_pAuxBus;
  v6 = in_pCbx;
  v7 = in_uDevice;
  v8 = CAkLEngine::GetExistingVPLMixBus(in_pSend->auxBusID, in_uDevice);
  if ( v8 )
    goto LABEL_26;
  in_ctxBus.m_pBus = v5;
  v9 = AK::CAkBusCtx::ID(&in_ctxBus);
  v8 = CAkLEngine::GetExistingVPLMixBus(v9, v7);
  if ( !v8 )
    v8 = CAkLEngine::GetVPLMixBusInternal(&in_ctxBus, v7, 0);
  if ( v8 )
  {
LABEL_26:
    CAkKeyArray<unsigned __int64,AkVPL *,1>::Set(&v4->PerDeviceAuxBusses, v7, v8);
    *((_BYTE *)v8 + 1376) |= 1u;
    v12 = v6->m_pSources[0];
    if ( v12 )
      v12 = (CAkVPLSrcNode *)v12->m_pCtx;
    v13 = (*(__int64 (**)(void))(**((_QWORD **)&v12[3] + 4) + 248i64))();
    v14 = !v13 || *(_BYTE *)(v13 + 304) < 0;
    if ( *((_BYTE *)v5 + 304) >> 7 != v14 )
    {
      v15 = v6->m_OutputDevices.m_listDeviceVolumes.m_pFirst;
      if ( v15 )
      {
        while ( v8 != v15->pMixBus )
        {
          v15 = v15->pNextLightItem;
          if ( !v15 )
            goto LABEL_22;
        }
      }
      else
      {
LABEL_22:
        CAkVPLSrcCbxNodeBase::AddOutputBus(v6, v8, v7, 1);
      }
    }
  }
  else
  {
    v10 = v4->PerDeviceAuxBusses.m_pItems;
    v11 = (signed __int64)&v10[v4->PerDeviceAuxBusses.m_uLength];
    if ( v10 != (MapStruct<unsigned __int64,AkVPL *> *)v11 )
    {
      do
      {
        if ( v10->key == v7 )
          break;
        ++v10;
      }
      while ( v10 != (MapStruct<unsigned __int64,AkVPL *> *)v11 );
      if ( v10 != (MapStruct<unsigned __int64,AkVPL *> *)v11 )
      {
        if ( v4->PerDeviceAuxBusses.m_uLength > 1 )
        {
          v10->key = *(_QWORD *)(v11 - 16);
          v10->item = *(AkVPL **)(v11 - 8);
        }
        --v4->PerDeviceAuxBusses.m_uLength;
      }
    }
  }
  return v8;
}

// File Line: 1411
// RVA: 0xA51610
signed __int64 __fastcall CAkLEngine::EnsureVPLExists(CAkVPLSrcCbxNode *in_pCbx, CAkPBI *in_pCtx)
{
  CAkPBI *v2; // r15
  CAkVPLSrcCbxNode *v3; // rsi
  __int64 v4; // rdx
  AkDevice *v6; // rdx
  unsigned int v7; // er8
  int v8; // er12
  CAkVPLSrcCbxNode *v9; // r14
  AkVPL *v10; // rbp
  AkDevice *v11; // rbx
  AkDeviceInfo *v12; // rax
  unsigned __int64 v13; // rdi
  __int64 v14; // rax
  bool v15; // cl
  __int64 v16; // rdx
  CAkVPLSrcCbxNode *v17; // rcx
  CAkVPLSrcCbxNode *v18; // rax

  v2 = in_pCtx;
  v3 = in_pCbx;
  if ( !(~*((_BYTE *)&in_pCbx->0 + 76) & 1) && CAkVPLSrcCbxNode::AddPipeline(in_pCbx) != 1 )
  {
    LOBYTE(v4) = 1;
    CAkLEngine::VPLDestroySource((CAkVPLSrcCbxNodeBase *)&v3->vfptr, v4);
    return 2i64;
  }
  v6 = CAkOutputMgr::m_Devices.m_pItems;
  v7 = CAkOutputMgr::m_Devices.m_uLength;
  v8 = (unsigned __int8)v2->m_pGameObj->m_PosKeep.m_uListenerMask;
  v9 = 0i64;
  v10 = 0i64;
  v11 = CAkOutputMgr::m_Devices.m_pItems;
  if ( CAkOutputMgr::m_Devices.m_pItems != &CAkOutputMgr::m_Devices.m_pItems[CAkOutputMgr::m_Devices.m_uLength] )
  {
    do
    {
      if ( v8 & v11->uListeners )
      {
        v12 = v3->m_OutputDevices.m_listDeviceVolumes.m_pFirst;
        v13 = v11->uDeviceID;
        if ( v12 )
        {
          while ( v12->uDeviceID != v13 )
          {
            v12 = v12->pNextLightItem;
            if ( !v12 )
              goto LABEL_9;
          }
        }
        else
        {
LABEL_9:
          v10 = 0i64;
          v14 = ((__int64 (*)(void))v2->m_pSound->vfptr[7].Category)();
          v15 = !v14 || *(_BYTE *)(v14 + 304) < 0;
          if ( v15 == (v13 == 0) )
          {
            v10 = CAkLEngine::GetAndConnectBus(v2, (CAkVPLSrcCbxNodeBase *)&v3->vfptr, v13);
            v16 = 2 - (unsigned int)(v10 != 0i64);
            if ( (_DWORD)v16 != 1 )
            {
              LOBYTE(v16) = 1;
              CAkLEngine::VPLDestroySource((CAkVPLSrcCbxNodeBase *)&v3->vfptr, v16);
              return 2i64;
            }
          }
          v7 = CAkOutputMgr::m_Devices.m_uLength;
          v6 = CAkOutputMgr::m_Devices.m_pItems;
        }
      }
      ++v11;
    }
    while ( v11 != &v6[v7] );
  }
  v17 = CAkLEngine::m_Sources.m_pFirst;
  if ( CAkLEngine::m_Sources.m_pFirst )
  {
    do
    {
      if ( !v17->m_OutputDevices.m_uNumDevices )
        break;
      if ( v17->m_OutputDevices.m_listDeviceVolumes.m_pFirst->pMixBus == v10 )
        break;
      v9 = v17;
      v17 = (CAkVPLSrcCbxNode *)v17->pNextItem;
    }
    while ( v17 );
  }
  v3->pNextItem = (CAkVPLSrcCbxNodeBase *)&v17->vfptr;
  if ( v9 )
    v9->pNextItem = (CAkVPLSrcCbxNodeBase *)&v3->vfptr;
  else
    CAkLEngine::m_Sources.m_pFirst = v3;
  v18 = CAkLEngine::m_Sources.m_pLast;
  if ( !v17 )
    v18 = v3;
  ++CAkLEngine::m_Sources.m_ulNumListItems;
  CAkLEngine::m_Sources.m_pLast = v18;
  return 1i64;
}

// File Line: 1477
// RVA: 0xA50890
signed __int64 __fastcall CAkLEngine::AddSound(AkLECmd *io_cmd)
{
  CAkPBI *v1; // rsi
  AkLECmd *v2; // r14
  unsigned int v3; // er8
  CAkVPLSrcCbxNode *v4; // rcx
  CAkVPLSrcNode *v5; // rax
  CAkPBI *v6; // rdx
  CAkVPLSrcCbxNode *v7; // rax
  CAkVPLSrcCbxNode *v8; // rax
  CAkVPLSrcCbxNode *v9; // rbx
  unsigned int v10; // edx
  signed __int64 result; // rax
  AKRESULT v12; // eax
  __int64 v13; // rdx
  AKRESULT v14; // edi

  v1 = io_cmd->m_pCtx;
  v2 = io_cmd;
  v3 = io_cmd->m_pCtx->m_SeqID;
  if ( v3 && (v4 = CAkLEngine::m_Sources.m_pFirst) != 0i64 )
  {
    while ( 1 )
    {
      v5 = v4->m_pSources[0];
      v6 = v5 ? v5->m_pCtx : 0i64;
      if ( v6->m_SeqID == v3 )
        break;
      v4 = (CAkVPLSrcCbxNode *)v4->pNextItem;
      if ( !v4 )
        goto LABEL_8;
    }
    CAkVPLSrcCbxNodeBase::AddSrc((CAkVPLSrcCbxNodeBase *)&v4->vfptr, v1, 0);
    CAkPBI::NotifAddedAsSA(v1);
    result = 5i64;
  }
  else
  {
LABEL_8:
    v7 = (CAkVPLSrcCbxNode *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 0x440ui64);
    if ( v7 && (CAkVPLSrcCbxNode::CAkVPLSrcCbxNode(v7), (v9 = v8) != 0i64) )
    {
      if ( *((_BYTE *)v1 + 374) >= 0 )
        v10 = AkAudioLibSettings::g_pipelineCoreFrequency;
      else
        v10 = (unsigned __int16)(signed int)(float)((float)((float)(signed int)AkAudioLibSettings::g_pipelineCoreFrequency
                                                          * 0.0009765625)
                                                  * 8.0);
      CAkVPLSrcCbxNode::Init(v8, v10);
      v12 = CAkVPLSrcCbxNodeBase::AddSrc((CAkVPLSrcCbxNodeBase *)&v9->vfptr, v1, 1);
      v14 = v12;
      if ( v12 == 63 )
      {
        v9->pNextItem = 0i64;
        if ( CAkLEngineCmds::m_listSrcsNotConnected.m_pLast )
          CAkLEngineCmds::m_listSrcsNotConnected.m_pLast->pNextItem = (CAkVPLSrcCbxNodeBase *)&v9->vfptr;
        else
          CAkLEngineCmds::m_listSrcsNotConnected.m_pFirst = (CAkVPLSrcCbxNodeBase *)&v9->vfptr;
        CAkLEngineCmds::m_listSrcsNotConnected.m_pLast = (CAkVPLSrcCbxNodeBase *)&v9->vfptr;
        result = 1i64;
      }
      else if ( v12 == 1 )
      {
        LODWORD(result) = CAkLEngine::EnsureVPLExists(v9, v1);
        v2->m_bSourceConnected = (_DWORD)result == 1;
        result = (unsigned int)result;
      }
      else
      {
        LOBYTE(v13) = v12 != 3;
        CAkLEngine::VPLDestroySource((CAkVPLSrcCbxNodeBase *)&v9->vfptr, v13);
        result = (unsigned int)v14;
      }
    }
    else
    {
      CAkPBI::Destroy(v1, CtxDestroyReasonPlayFailed);
      result = 2i64;
    }
  }
  return result;
}

// File Line: 1565
// RVA: 0xA53AF0
unsigned int __fastcall CAkLEngine::VPLTryConnectSource(CAkPBI *in_pContext, CAkVPLSrcCbxNodeBase *in_pCbx)
{
  CAkVPLSrcCbxNode *v2; // rbx
  CAkPBI *v3; // rdi
  unsigned int result; // eax
  AKRESULT v5; // er8
  __int64 v6; // rdx
  CAkVPLSrcCbxNodeBase *v7; // rcx
  CAkVPLSrcCbxNodeBase *v8; // rax

  v2 = (CAkVPLSrcCbxNode *)in_pCbx;
  v3 = in_pContext;
  result = CAkVPLSrcCbxNodeBase::FetchStreamedData(in_pCbx, in_pContext);
  v5 = result;
  if ( result != 63 )
  {
    v6 = 0i64;
    v7 = CAkLEngineCmds::m_listSrcsNotConnected.m_pFirst;
    if ( CAkLEngineCmds::m_listSrcsNotConnected.m_pFirst )
    {
      while ( v7 != (CAkVPLSrcCbxNodeBase *)v2 )
      {
        v6 = (__int64)v7;
        v7 = v7->pNextItem;
        if ( !v7 )
          goto LABEL_13;
      }
      if ( v7 )
      {
        if ( v7 == CAkLEngineCmds::m_listSrcsNotConnected.m_pFirst )
          CAkLEngineCmds::m_listSrcsNotConnected.m_pFirst = v7->pNextItem;
        else
          *(_QWORD *)(v6 + 8) = v7->pNextItem;
        v8 = CAkLEngineCmds::m_listSrcsNotConnected.m_pLast;
        if ( v7 == CAkLEngineCmds::m_listSrcsNotConnected.m_pLast )
          v8 = (CAkVPLSrcCbxNodeBase *)v6;
        CAkLEngineCmds::m_listSrcsNotConnected.m_pLast = v8;
      }
    }
LABEL_13:
    if ( v5 == 1 )
    {
      result = CAkLEngine::EnsureVPLExists(v2, v3);
    }
    else
    {
      LOBYTE(v6) = 1;
      CAkLEngine::VPLDestroySource((CAkVPLSrcCbxNodeBase *)&v2->vfptr, v6);
      result = 2;
    }
  }
  return result;
}

// File Line: 1601
// RVA: 0xA520D0
AK::CAkBusCtx *__fastcall CAkLEngine::GetExistingVPLMixBus(unsigned int in_busID, unsigned __int64 in_uDevice)
{
  AkVPL **v2; // rbx
  unsigned __int64 v3; // rsi
  unsigned int v4; // ebp
  AK::CAkBusCtx *v5; // rdi

  v2 = CAkLEngine::m_arrayVPLs.m_pItems;
  v3 = in_uDevice;
  v4 = in_busID;
  if ( CAkLEngine::m_arrayVPLs.m_pItems == &CAkLEngine::m_arrayVPLs.m_pItems[CAkLEngine::m_arrayVPLs.m_uLength] )
    return 0i64;
  while ( 1 )
  {
    v5 = (AK::CAkBusCtx *)*v2;
    if ( AK::CAkBusCtx::ID(&(*v2)->m_MixBus.m_BusContext) == v4
      && v5[171].m_pBus == (CAkBus *)v3
      && LODWORD(v5[167].m_pBus) != 2 )
    {
      break;
    }
    ++v2;
    if ( v2 == &CAkLEngine::m_arrayVPLs.m_pItems[CAkLEngine::m_arrayVPLs.m_uLength] )
      return 0i64;
  }
  return v5;
}

// File Line: 1645
// RVA: 0xA522E0
CAkVPLMixBusNode *__fastcall CAkLEngine::GetVPLMixBusInternal(AK::CAkBusCtx *in_ctxBus, unsigned __int64 in_uDevice, bool in_bForFeedback)
{
  unsigned __int64 v3; // rsi
  bool v4; // bp
  AK::CAkBusCtx *v5; // rdi
  AkVPL *v6; // rbx
  unsigned int v7; // eax
  CAkVPLMixBusNode *v9; // rbx
  AK::CAkBusCtx result; // [rsp+48h] [rbp+20h]

  v3 = in_uDevice;
  v4 = in_bForFeedback;
  v5 = in_ctxBus;
  v6 = 0i64;
  AK::CAkBusCtx::GetParentCtx(in_ctxBus, &result);
  if ( result.m_pBus )
  {
    v7 = AK::CAkBusCtx::ID(&result);
    v6 = (AkVPL *)CAkLEngine::GetExistingVPLMixBus(v7, v3);
    if ( !v6 )
      v6 = CAkLEngine::GetVPLMixBusInternal(&result, v3, v4);
    if ( !v6 )
      return 0i64;
  }
  v9 = CAkLEngine::CreateVPLMixBus((AK::CAkBusCtx)v5->m_pBus, v3, v6, v4);
  if ( !v9 )
    return 0i64;
  if ( !AK::CAkBusCtx::IsTopBusCtx(v5) )
  {
    CAkVPLMixBusNode::InitVolumes(v9);
    CAkVPLMixBusNode::UpdateBypassFx(v9);
  }
  return v9;
}

// File Line: 1679
// RVA: 0xA51530
void __fastcall CAkLEngine::EnsureAuxBusExist(CAkVPLSrcCbxNodeBase *in_pCbx, AkMergedEnvironmentValue *in_pMergedEnvSlot)
{
  AkMergedEnvironmentValue *v2; // rsi
  CAkVPLSrcCbxNodeBase *v3; // rbp
  CAkIndexable *v4; // rax
  CAkBus *v5; // rdi
  AkDevice *v6; // rdx
  unsigned int v7; // er9
  AkDevice *v8; // rbx
  unsigned __int64 v9; // r8

  v2 = in_pMergedEnvSlot;
  v3 = in_pCbx;
  v4 = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, in_pMergedEnvSlot->auxBusID, AkNodeType_Bus);
  v5 = (CAkBus *)v4;
  if ( v4 )
  {
    if ( SLOBYTE(v4[12].key) >= 0 )
    {
      v6 = CAkOutputMgr::m_Devices.m_pItems;
      v7 = CAkOutputMgr::m_Devices.m_uLength;
      v8 = CAkOutputMgr::m_Devices.m_pItems;
      if ( CAkOutputMgr::m_Devices.m_pItems != &CAkOutputMgr::m_Devices.m_pItems[CAkOutputMgr::m_Devices.m_uLength] )
      {
        do
        {
          v9 = v8->uDeviceID;
          if ( v9 )
          {
            CAkLEngine::GetAuxBus(v5, v2, v9, v3);
            v7 = CAkOutputMgr::m_Devices.m_uLength;
            v6 = CAkOutputMgr::m_Devices.m_pItems;
          }
          ++v8;
        }
        while ( v8 != &v6[v7] );
      }
    }
    else
    {
      CAkLEngine::GetAuxBus((CAkBus *)v4, v2, 0i64, v3);
    }
    v5->vfptr->Release((CAkIndexable *)&v5->vfptr);
  }
}

// File Line: 1720
// RVA: 0xA511B0
CAkVPLMixBusNode *__fastcall CAkLEngine::CreateVPLMixBus(AK::CAkBusCtx in_BusCtx, unsigned __int64 in_uDevice, AkVPL *in_pParentBus, bool in_bForFeedback)
{
  AkDevice *v4; // rdi
  bool v5; // r13
  AkVPL *v6; // r15
  unsigned __int64 v7; // rbp
  AkHdrBus *v8; // rax
  CAkVPLMixBusNode *v9; // rbx
  CAkBusFX *v10; // rax
  unsigned int v11; // edx
  unsigned int v12; // esi
  unsigned __int16 v13; // r14
  __int64 v14; // rax
  unsigned __int64 *v15; // rcx
  AkDevice *v16; // rax
  unsigned int v17; // ecx
  unsigned int v18; // er14
  unsigned __int64 v19; // r12
  AkVPL **v20; // rsi
  AkVPL **v21; // rdx
  unsigned __int64 v22; // r8
  unsigned __int64 v23; // rcx
  AkVPL *v24; // rax
  CAkVPLMixBusNode **v25; // rdx
  __int64 v26; // rax
  unsigned __int64 *v27; // rcx
  CAkVPLMixBusNode *v28; // rcx
  int v29; // esi
  AK::CAkBusCtx in_BusCtxa; // [rsp+60h] [rbp+8h]

  in_BusCtxa.m_pBus = in_BusCtx.m_pBus;
  v4 = 0i64;
  v5 = in_bForFeedback;
  v6 = in_pParentBus;
  v7 = in_uDevice;
  if ( in_BusCtx.m_pBus && *((_BYTE *)&in_BusCtx.m_pBus->0 + 83) & 8 )
  {
    v8 = (AkHdrBus *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 0x590ui64);
    v9 = &v8->m_MixBus;
    if ( v8 )
    {
      AkHdrBus::AkHdrBus(v8, in_BusCtxa);
      goto LABEL_7;
    }
  }
  else
  {
    v10 = (CAkBusFX *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 0x570ui64);
    v9 = (CAkVPLMixBusNode *)v10;
    if ( v10 )
    {
      CAkBusFX::CAkBusFX(v10);
      v9->m_BusContext.m_pBus = 0i64;
      LOBYTE(v9[1].m_PanningVolumes[0].Next.aVolumes[4]) &= 0xF4u;
      v9[1].m_PanningVolumes[0].Next.volumes.fFrontLeft = 1.0;
      *(_QWORD *)&v9[1].m_PanningVolumes[0].Next.aVolumes[2] = 0i64;
LABEL_7:
      if ( v5 )
      {
        v11 = 4;
        v12 = 4;
        v13 = 16;
      }
      else
      {
        v13 = 1024;
        if ( v6 )
        {
          v12 = v6->m_MixBus.m_BufferOut.uChannelMask;
        }
        else
        {
          v14 = 0i64;
          if ( CAkOutputMgr::m_Devices.m_uLength )
          {
            v15 = &CAkOutputMgr::m_Devices.m_pItems->uDeviceID;
            while ( *v15 != v7 )
            {
              v14 = (unsigned int)(v14 + 1);
              v15 += 10;
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
          v12 = v16->pSink->m_SpeakersConfig;
        }
        v11 = AK::CAkBusCtx::GetChannelConfig(&in_BusCtxa);
        if ( !v11 )
          v11 = v12;
      }
      if ( CAkVPLMixBusNode::Init(v9, v11, v12, v13, in_BusCtxa) != 1 )
        goto LABEL_41;
      v17 = CAkLEngine::m_arrayVPLs.m_uLength;
      v18 = CAkLEngine::m_arrayVPLs.m_ulReserved;
      v19 = CAkLEngine::m_arrayVPLs.m_uLength;
      if ( CAkLEngine::m_arrayVPLs.m_uLength < (unsigned __int64)CAkLEngine::m_arrayVPLs.m_ulReserved )
      {
        v20 = CAkLEngine::m_arrayVPLs.m_pItems;
      }
      else
      {
        v18 = CAkLEngine::m_arrayVPLs.m_ulReserved + 4;
        v20 = (AkVPL **)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 8i64 * (CAkLEngine::m_arrayVPLs.m_ulReserved + 4));
        if ( !v20 )
          goto LABEL_41;
        v21 = CAkLEngine::m_arrayVPLs.m_pItems;
        v17 = CAkLEngine::m_arrayVPLs.m_uLength;
        v22 = CAkLEngine::m_arrayVPLs.m_uLength;
        if ( CAkLEngine::m_arrayVPLs.m_pItems )
        {
          v23 = 0i64;
          if ( CAkLEngine::m_arrayVPLs.m_uLength )
          {
            do
            {
              v24 = v21[v23++];
              v20[v23 - 1] = v24;
              v21 = CAkLEngine::m_arrayVPLs.m_pItems;
            }
            while ( v23 < v22 );
          }
          AK::MemoryMgr::Free(g_LEngineDefaultPoolId, v21);
          v17 = CAkLEngine::m_arrayVPLs.m_uLength;
        }
        CAkLEngine::m_arrayVPLs.m_pItems = v20;
        CAkLEngine::m_arrayVPLs.m_ulReserved = v18;
      }
      if ( v19 < v18 )
      {
        v25 = (CAkVPLMixBusNode **)&v20[v17];
        CAkLEngine::m_arrayVPLs.m_uLength = v17 + 1;
        if ( v25 )
        {
          *v25 = v9;
          LOBYTE(v9[1].m_PanningVolumes[0].Next.aVolumes[4]) &= 0xF7u;
          *(_QWORD *)&v9[1].m_PanningVolumes[0].Next.aVolumes[2] = v7;
          v9->m_pParent = v6;
          LOBYTE(v9[1].m_PanningVolumes[0].Next.aVolumes[4]) |= 8 * v5;
          if ( !v5 )
          {
            if ( v6 )
            {
              CAkVPLMixBusNode::Connect(&v6->m_MixBus);
            }
            else
            {
              v26 = 0i64;
              if ( CAkOutputMgr::m_Devices.m_uLength )
              {
                v27 = &CAkOutputMgr::m_Devices.m_pItems->uDeviceID;
                while ( *v27 != v7 )
                {
                  v26 = (unsigned int)(v26 + 1);
                  v27 += 10;
                  if ( (unsigned int)v26 >= CAkOutputMgr::m_Devices.m_uLength )
                  {
                    CAkVPLFinalMixNode::Connect((CAkVPLFinalMixNode *)MEMORY[0], v9);
                    return v9;
                  }
                }
                v4 = &CAkOutputMgr::m_Devices.m_pItems[v26];
              }
              CAkVPLFinalMixNode::Connect(v4->pFinalMix, v9);
            }
          }
          return v9;
        }
      }
LABEL_41:
      v28 = &v9->m_pParent->m_MixBus;
      v29 = g_LEngineDefaultPoolId;
      if ( v28 )
        CAkVPLMixBusNode::Disconnect(v28);
      CAkVPLMixBusNode::~CAkVPLMixBusNode(v9);
      AK::MemoryMgr::Free(v29, v9);
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
  CAkVPLMixBusNode *v3; // rcx

  for ( i = CAkLEngine::m_arrayVPLs.m_uLength - 1; i >= 0; --i )
  {
    v1 = g_LEngineDefaultPoolId;
    v2 = CAkLEngine::m_arrayVPLs.m_pItems[i];
    if ( v2 )
    {
      v3 = &v2->m_MixBus.m_pParent->m_MixBus;
      if ( v3 )
        CAkVPLMixBusNode::Disconnect(v3);
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
  AkDevice *v0; // rbx

  v0 = CAkOutputMgr::m_Devices.m_pItems;
  if ( CAkOutputMgr::m_Devices.m_pItems != &CAkOutputMgr::m_Devices.m_pItems[CAkOutputMgr::m_Devices.m_uLength] )
  {
    while ( 1 )
    {
      if ( ((unsigned __int8 (*)(void))v0->pSink->vfptr->IsStarved)() )
      {
        ((void (*)(void))v0->pSink->vfptr->ResetStarved)();
        if ( !CAkLEngine::m_uLastStarvationTime || g_pAudioMgr->m_uBufferTick - CAkLEngine::m_uLastStarvationTime > 8 )
          break;
      }
      ++v0;
      if ( v0 == &CAkOutputMgr::m_Devices.m_pItems[CAkOutputMgr::m_Devices.m_uLength] )
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
void __fastcall CAkLEngine::ReevaluateBussesForDevice(unsigned __int64 in_uDevice, __int64 in_uListenerMask)
{
  CAkVPLSrcCbxNode *v2; // rsi
  unsigned __int8 v3; // r14
  unsigned __int64 v4; // rbp
  CAkVPLSrcNode *v5; // rax
  CAkPBI *v6; // rbx
  AkDeviceInfo *v7; // r8
  AkDeviceInfo *v8; // rax
  AkVPL *v9; // rcx
  AkDeviceInfo *v10; // rbx
  AkDeviceInfo *v11; // rax
  int v12; // edi
  __int64 v13; // rax
  bool v14; // cl

  v2 = CAkLEngine::m_Sources.m_pFirst;
  v3 = in_uListenerMask;
  v4 = in_uDevice;
  if ( CAkLEngine::m_Sources.m_pFirst )
  {
    do
    {
      v5 = v2->m_pSources[0];
      if ( v5 )
        v6 = v5->m_pCtx;
      else
        v6 = 0i64;
      v7 = v2->m_OutputDevices.m_listDeviceVolumes.m_pFirst;
      v8 = v7;
      v9 = 0i64;
      if ( !v7 )
        goto LABEL_21;
      while ( !v9 )
      {
        if ( v8->uDeviceID == v4 )
          v9 = v8->pMixBus;
        v8 = v8->pNextLightItem;
        if ( !v8 )
        {
          if ( !v9 )
            goto LABEL_21;
          break;
        }
      }
      if ( !(v3 & v6->m_pGameObj->m_PosKeep.m_uListenerMask) )
      {
        *((_BYTE *)&v2->0 + 76) |= 0x40u;
        in_uListenerMask = 0i64;
        v10 = v7;
        if ( v7 )
        {
          while ( v10->pMixBus != v9 )
          {
            in_uListenerMask = (__int64)v10;
            v10 = v10->pNextLightItem;
            if ( !v10 )
              goto LABEL_28;
          }
          v11 = v10->pNextLightItem;
          if ( v10 == v7 )
            v2->m_OutputDevices.m_listDeviceVolumes.m_pFirst = v11;
          else
            *(_QWORD *)(in_uListenerMask + 584) = v11;
          v12 = g_LEngineDefaultPoolId;
          v10->vfptr->__vecDelDtor(v10, 0);
          AK::MemoryMgr::Free(v12, v10);
          --v2->m_OutputDevices.m_uNumDevices;
        }
        goto LABEL_28;
      }
      if ( !v9 )
      {
LABEL_21:
        if ( v3 & v6->m_pGameObj->m_PosKeep.m_uListenerMask )
        {
          LOBYTE(in_uListenerMask) = (v3 & v6->m_pGameObj->m_PosKeep.m_uListenerMask) != 0;
          v13 = ((__int64 (__fastcall *)(CAkSoundBase *, __int64))v6->m_pSound->vfptr[7].Category)(
                  v6->m_pSound,
                  in_uListenerMask);
          v14 = !v13 || *(_BYTE *)(v13 + 304) < 0;
          if ( v14 == (v4 == 0) )
            CAkLEngine::GetAndConnectBus(v6, (CAkVPLSrcCbxNodeBase *)&v2->vfptr, v4);
        }
      }
LABEL_28:
      v2 = (CAkVPLSrcCbxNode *)v2->pNextItem;
    }
    while ( v2 );
  }
}

// File Line: 1922
// RVA: 0xA52670
void __fastcall CAkLEngine::ReevaluateBussesForGameObject(CAkRegisteredObj *in_pObj, __int64 in_uOldMask, unsigned int in_uNewMask)
{
  CAkVPLSrcCbxNode *v3; // rbp
  int v4; // er12
  unsigned int v5; // er15
  CAkRegisteredObj *v6; // r13
  CAkVPLSrcNode *v7; // rax
  CAkPBI *v8; // r14
  AkDevice *i; // rbx
  int v10; // ecx
  unsigned __int64 v11; // rdi
  __int64 v12; // rax
  bool v13; // cl
  AkDeviceInfo *v14; // r8
  AkDeviceInfo *j; // rax
  AkDeviceInfo *v16; // rcx
  AkDeviceInfo *v17; // rdi
  AkDeviceInfo *v18; // rax
  int v19; // esi

  v3 = CAkLEngine::m_Sources.m_pFirst;
  v4 = (unsigned __int8)in_pObj->m_PosKeep.m_uListenerMask;
  v5 = in_uNewMask;
  v6 = in_pObj;
  if ( CAkLEngine::m_Sources.m_pFirst )
  {
    do
    {
      v7 = v3->m_pSources[0];
      if ( v7 )
        v8 = v7->m_pCtx;
      else
        v8 = 0i64;
      if ( v8->m_pGameObj == v6 )
      {
        for ( i = CAkOutputMgr::m_Devices.m_pItems;
              i != &CAkOutputMgr::m_Devices.m_pItems[CAkOutputMgr::m_Devices.m_uLength];
              ++i )
        {
          v10 = v4 & i->uListeners;
          if ( v5 & i->uListeners )
          {
            if ( !v10 )
            {
              v11 = i->uDeviceID;
              v12 = ((__int64 (__fastcall *)(CAkSoundBase *, __int64))v8->m_pSound->vfptr[7].Category)(
                      v8->m_pSound,
                      in_uOldMask);
              v13 = !v12 || *(_BYTE *)(v12 + 304) < 0;
              if ( v13 == (v11 == 0) )
                CAkLEngine::GetAndConnectBus(v8, (CAkVPLSrcCbxNodeBase *)&v3->vfptr, v11);
            }
          }
          else if ( v10 )
          {
            v14 = v3->m_OutputDevices.m_listDeviceVolumes.m_pFirst;
            in_uOldMask = 0i64;
            for ( j = v14; j; j = j->pNextLightItem )
            {
              if ( in_uOldMask )
                break;
              if ( j->uDeviceID == i->uDeviceID )
                in_uOldMask = (__int64)j->pMixBus;
            }
            *((_BYTE *)&v3->0 + 76) |= 0x40u;
            v16 = 0i64;
            v17 = v14;
            if ( v14 )
            {
              while ( v17->pMixBus != (AkVPL *)in_uOldMask )
              {
                v16 = v17;
                v17 = v17->pNextLightItem;
                if ( !v17 )
                  goto LABEL_29;
              }
              v18 = v17->pNextLightItem;
              if ( v17 == v14 )
                v3->m_OutputDevices.m_listDeviceVolumes.m_pFirst = v18;
              else
                v16->pNextLightItem = v18;
              v19 = g_LEngineDefaultPoolId;
              v17->vfptr->__vecDelDtor(v17, 0);
              AK::MemoryMgr::Free(v19, v17);
              --v3->m_OutputDevices.m_uNumDevices;
            }
          }
LABEL_29:
          ;
        }
      }
      v3 = (CAkVPLSrcCbxNode *)v3->pNextItem;
    }
    while ( v3 );
  }
}

// File Line: 2055
// RVA: 0xA50A30
void CAkLEngine::AnalyzeMixingGraph(void)
{
  CAkVPLSrcCbxNode *v0; // rbx
  unsigned int v1; // esi
  signed __int64 v2; // rdi
  MapStruct<unsigned __int64,AkVPL *> *v3; // rdx
  unsigned int v4; // eax
  unsigned int v5; // er9
  AkVPL *v6; // rdx
  AkVPL *v7; // rax
  float v8; // xmm0_4
  float v9; // xmm0_4
  __int64 v10; // rax
  unsigned __int64 *v11; // rcx
  AkDevice *v12; // rax
  CAkVPLSrcCbxNode *v13; // rbx
  int v14; // eax
  __int64 i; // rbx
  AkVPL *v16; // rcx

  v0 = CAkLEngine::m_Sources.m_pFirst;
  if ( CAkLEngine::m_Sources.m_pFirst )
  {
    do
    {
      if ( v0->m_eState == 1 )
      {
        if ( !CAkVPLSrcCbxNodeBase::ComputeVolumeRays((CAkVPLSrcCbxNodeBase *)&v0->vfptr) )
          CAkVPLSrcCbxNodeBase::CleanupAuxBusses((CAkVPLSrcCbxNodeBase *)&v0->vfptr);
      }
      else
      {
        v1 = 0;
        if ( v0->m_uNumSends > 0u )
        {
          do
          {
            v2 = v1;
            v3 = v0->m_arSendValues[v2].PerDeviceAuxBusses.m_pItems;
            if ( v3 )
            {
              v0->m_arSendValues[v2].PerDeviceAuxBusses.m_uLength = 0;
              AK::MemoryMgr::Free(g_DefaultPoolId, v3);
              v0->m_arSendValues[v2].PerDeviceAuxBusses.m_pItems = 0i64;
              v0->m_arSendValues[v2].PerDeviceAuxBusses.m_ulReserved = 0;
            }
            ++v1;
          }
          while ( v1 < (unsigned __int8)v0->m_uNumSends );
        }
      }
      v0 = (CAkVPLSrcCbxNode *)v0->pNextItem;
    }
    while ( v0 );
  }
  v4 = CAkLEngine::m_arrayVPLs.m_uLength;
  v5 = 0;
  if ( CAkLEngine::m_arrayVPLs.m_uLength )
  {
    do
    {
      v6 = CAkLEngine::m_arrayVPLs.m_pItems[v5];
      v7 = v6->m_MixBus.m_pParent;
      v8 = v6->m_MixBus.m_fNextVolume;
      v6->m_fDownstreamGain = v8;
      if ( v7 )
      {
        v9 = v8 * v7->m_fDownstreamGain;
      }
      else
      {
        v10 = 0i64;
        if ( !CAkOutputMgr::m_Devices.m_uLength )
          goto LABEL_21;
        v11 = &CAkOutputMgr::m_Devices.m_pItems->uDeviceID;
        while ( *v11 != v6->m_uDevice )
        {
          v10 = (unsigned int)(v10 + 1);
          v11 += 10;
          if ( (unsigned int)v10 >= CAkOutputMgr::m_Devices.m_uLength )
            goto LABEL_21;
        }
        v12 = &CAkOutputMgr::m_Devices.m_pItems[v10];
        if ( !v12 )
          goto LABEL_21;
        v9 = v8 * v12->pFinalMix->m_fNextVolume;
      }
      v6->m_fDownstreamGain = v9;
LABEL_21:
      v4 = CAkLEngine::m_arrayVPLs.m_uLength;
      ++v5;
    }
    while ( v5 < CAkLEngine::m_arrayVPLs.m_uLength );
  }
  v13 = CAkLEngine::m_Sources.m_pFirst;
  if ( CAkLEngine::m_Sources.m_pFirst )
  {
    do
    {
      if ( v13->m_eState == 1 )
        CAkVPLSrcCbxNodeBase::ComputeMaxVolume((CAkVPLSrcCbxNodeBase *)&v13->vfptr);
      v13 = (CAkVPLSrcCbxNode *)v13->pNextItem;
    }
    while ( v13 );
    v4 = CAkLEngine::m_arrayVPLs.m_uLength;
  }
  v14 = v4 - 1;
  for ( i = v14; i >= 0; --i )
  {
    v16 = CAkLEngine::m_arrayVPLs.m_pItems[i];
    if ( *((_BYTE *)v16 + 1376) & 2 )
      AkHdrBus::ComputeHdrAttenuation((AkHdrBus *)v16);
  }
}

// File Line: 2156
// RVA: 0xA505E0
void __fastcall AkHdrBus::AkHdrBus(AkHdrBus *this, AK::CAkBusCtx in_BusCtx)
{
  AkHdrBus *v2; // rbx
  CAkBus *v3; // rdi
  unsigned __int64 v4; // rax
  float v5; // xmm1_4
  char *v6; // r8
  unsigned int v7; // er9
  __int64 v8; // rcx
  __int64 v9; // rdx
  signed __int64 v10; // rdx
  float *v11; // rax
  unsigned __int8 v12; // al
  float out_fRatio; // [rsp+30h] [rbp+8h]
  CAkBus *v14; // [rsp+38h] [rbp+10h]

  v14 = in_BusCtx.m_pBus;
  v2 = this;
  CAkBusFX::CAkBusFX((CAkBusFX *)this->m_MixBus.m_PanningVolumes);
  v3 = v14;
  v2->m_MixBus.m_BusContext.m_pBus = 0i64;
  *((_BYTE *)&v2->0 + 1376) &= 0xF6u;
  *((_BYTE *)&v2->0 + 1376) |= 2u;
  v2->m_fDownstreamGain = 1.0;
  v2->m_uDevice = 0i64;
  v2->m_fHdrMaxVoiceVolume = -4096.0;
  v2->m_fHdrWinTopState = -4096.0;
  v2->m_fReleaseCoef = 0.0;
  CAkBus::GetHdrGainComputer(v3, &v2->m_fThreshold, &out_fRatio);
  v2->m_fGainFactor = 1.0 - (float)(1.0 / out_fRatio);
  v4 = v3->m_RTPCBitArray.m_iBitArray;
  if ( _bittest64((const signed __int64 *)&v4, 0x21ui64) )
  {
    v5 = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, v3, 0x21u, 0i64);
  }
  else
  {
    v6 = v3->m_props.m_pProps;
    out_fRatio = g_AkPropDefault[28].fValue;
    if ( v6 )
    {
      v7 = (unsigned __int8)*v6;
      v8 = 0i64;
      while ( 1 )
      {
        v9 = (unsigned int)(v8 + 1);
        if ( v6[v9] == 28 )
          break;
        v8 = (unsigned int)v9;
        if ( (unsigned int)v9 >= v7 )
          goto LABEL_7;
      }
      v10 = (signed __int64)&v6[4 * v8 + ((v7 + 4) & 0xFFFFFFFC)];
    }
    else
    {
LABEL_7:
      v10 = 0i64;
    }
    v11 = &out_fRatio;
    if ( v10 )
      v11 = (float *)v10;
    out_fRatio = *v11;
    v5 = out_fRatio;
  }
  v12 = *((_BYTE *)v3 + 304);
  *((_BYTE *)v3 + 304) = v12 & 0xDF;
  *((_BYTE *)&v2->0 + 1376) &= 0xFBu;
  *((_BYTE *)&v2->0 + 1376) |= 4 * ((v12 >> 4) & 1);
  if ( v5 <= 0.0 )
    v2->m_fReleaseCoef = 0.0;
  else
    v2->m_fReleaseCoef = expf(-1024.0 / (float)(v5 * 48000.0));
}

// File Line: 2180
// RVA: 0xA50D50
void __fastcall AkHdrBus::ComputeHdrAttenuation(AkHdrBus *this)
{
  CAkBus *v1; // rsi
  AkHdrBus *v2; // rbx
  float v3; // xmm9_4
  bool v4; // al
  float v5; // xmm8_4
  float v6; // xmm1_4
  float v7; // xmm7_4
  float v8; // xmm0_4
  unsigned __int64 v9; // rax
  float v10; // xmm1_4
  char *v11; // r8
  unsigned int v12; // er9
  __int64 v13; // rcx
  __int64 v14; // rdx
  signed __int64 v15; // rdx
  float *v16; // rax
  unsigned __int8 v17; // cl
  char v18; // di
  float v19; // xmm2_4
  float v20; // xmm0_4
  float v21; // xmm2_4
  float v22; // xmm6_4
  float v23; // xmm1_4
  signed int v24; // ecx
  float v25; // xmm1_4
  int v26; // eax
  float out_fHdrThreshold; // [rsp+70h] [rbp+8h]
  float out_fRatio; // [rsp+78h] [rbp+10h]

  v1 = this->m_MixBus.m_BusContext.m_pBus;
  v2 = this;
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
  v4 = CAkBus::GetHdrGainComputer(v1, &out_fHdrThreshold, &out_fRatio);
  v5 = out_fHdrThreshold;
  if ( v4 )
  {
    v2->m_fThreshold = out_fHdrThreshold;
    v6 = 1.0 - (float)(1.0 / out_fRatio);
    v2->m_fGainFactor = v6;
  }
  else
  {
    v6 = v2->m_fGainFactor;
  }
  v7 = 0.0;
  v8 = (float)(v2->m_fHdrMaxVoiceVolume - v3) - v5;
  if ( v8 > 0.0 )
    v5 = (float)(v8 * v6) + v5;
  v9 = v1->m_RTPCBitArray.m_iBitArray;
  if ( _bittest64((const signed __int64 *)&v9, 0x21ui64) )
  {
    v10 = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, v1, 0x21u, 0i64);
  }
  else
  {
    v11 = v1->m_props.m_pProps;
    out_fHdrThreshold = g_AkPropDefault[28].fValue;
    if ( v11 )
    {
      v12 = (unsigned __int8)*v11;
      v13 = 0i64;
      while ( 1 )
      {
        v14 = (unsigned int)(v13 + 1);
        if ( v11[v14] == 28 )
          break;
        v13 = (unsigned int)v14;
        if ( (unsigned int)v14 >= v12 )
          goto LABEL_12;
      }
      v15 = (signed __int64)&v11[4 * v13 + ((v12 + 4) & 0xFFFFFFFC)];
    }
    else
    {
LABEL_12:
      v15 = 0i64;
    }
    v16 = &out_fHdrThreshold;
    if ( v15 )
      v16 = (float *)v15;
    out_fHdrThreshold = *v16;
    v10 = out_fHdrThreshold;
  }
  v17 = *((_BYTE *)v1 + 304);
  *((_BYTE *)v1 + 304) = v17 & 0xDF;
  v18 = (v17 >> 4) & 1;
  if ( (v17 >> 5) & 1 )
  {
    if ( v10 <= 0.0 )
      v2->m_fReleaseCoef = 0.0;
    else
      v2->m_fReleaseCoef = expf(-1024.0 / (float)(v10 * 48000.0));
  }
  v19 = v2->m_fReleaseCoef;
  if ( v18 )
  {
    v20 = v2->m_fHdrWinTopState;
    if ( v5 < v20 )
    {
      v22 = (float)((float)(1.0 - v19) * v5) + (float)(v20 * v19);
      v2->m_fHdrWinTopState = v22;
      if ( (float)(v22 - v5) >= 0.5 )
        *((_BYTE *)&v2->0 + 1376) |= 1u;
      v21 = v2->m_fHdrWinTopState;
    }
    else
    {
      v2->m_fHdrWinTopState = v5;
      v21 = v5;
    }
  }
  else
  {
    if ( (float)(v5 * 0.050000001) >= -37.0 )
    {
      if ( `AkMath::FastPow10'::`4'::`local static guard' & 1 )
      {
        v23 = *(float *)&`AkMath::FastPow10'::`4'::SCALE;
      }
      else
      {
        v23 = FLOAT_2_7866352e7;
        `AkMath::FastPow10'::`4'::SCALE = LODWORD(FLOAT_2_7866352e7);
        `AkMath::FastPow10'::`4'::`local static guard' |= 1u;
      }
      v24 = (signed int)(float)((float)((float)(v5 * 0.050000001) * v23) + 1065353200.0);
      LODWORD(out_fHdrThreshold) = (v24 & 0x7FFFFF) + 1065353216;
      LODWORD(out_fRatio) = v24 & 0xFF800000;
      v7 = (float)((float)((float)((float)(out_fHdrThreshold * 0.32518977) + 0.020805772) * out_fHdrThreshold)
                 + 0.65304345)
         * COERCE_FLOAT(v24 & 0xFF800000);
    }
    v25 = v2->m_fHdrWinTopState;
    if ( v7 < v25 )
    {
      out_fHdrThreshold = (float)((float)(1.0 - v19) * v7) + (float)(v25 * v19);
      v2->m_fHdrWinTopState = out_fHdrThreshold;
      v26 = LODWORD(out_fHdrThreshold) & 0x7FFFFF;
      out_fHdrThreshold = (float)((float)(1.0 - v19) * v7) + (float)(v25 * v19);
      LODWORD(out_fRatio) = v26 + 1065353216;
      v21 = (float)((float)((float)((float)((float)((float)((float)((float)(out_fRatio - 1.0) / (float)(out_fRatio + 1.0))
                                                          * (float)((float)(out_fRatio - 1.0) / (float)(out_fRatio + 1.0)))
                                                  * 0.33333334)
                                          + 1.0)
                                  * (float)((float)((float)(out_fRatio - 1.0) / (float)(out_fRatio + 1.0)) * 2.0))
                          + (float)((float)((float)(unsigned __int8)(LODWORD(out_fHdrThreshold) >> 23) - 127.0)
                                  * 0.69314718))
                  * 0.43429449)
          * 20.0;
      if ( (float)(v21 - v5) >= 0.5 )
        *((_BYTE *)&v2->0 + 1376) |= 1u;
    }
    else
    {
      v2->m_fHdrWinTopState = v7;
      v21 = v5;
    }
  }
  v2->m_fHdrWinTop = v21 + v3;
  CAkBus::NotifyHdrWindowTop(v1, v21);
  v2->m_fHdrMaxVoiceVolume = -4096.0;
}

// File Line: 2283
// RVA: 0xA52890
void CAkLEngine::RemoveMixBusses(void)
{
  __int64 v0; // rbx
  __int64 v1; // r14
  AkVPL *v2; // rdi
  CAkVPLMixBusNode *v3; // rcx
  int v4; // esi
  unsigned int v5; // edx
  AkVPL **v6; // rdi
  AkVPL **v7; // r8

  v0 = CAkLEngine::m_arrayVPLs.m_uLength - 1;
  if ( (signed int)(CAkLEngine::m_arrayVPLs.m_uLength - 1) >= 0 )
  {
    v1 = (signed int)v0;
    do
    {
      v2 = CAkLEngine::m_arrayVPLs.m_pItems[v1];
      if ( v2->m_MixBus.m_eState == 1 || v2->m_MixBus.m_uConnectCount || *((_BYTE *)v2 + 1376) & 1 )
      {
        *((_BYTE *)v2 + 1376) &= 0xFEu;
      }
      else
      {
        v3 = &v2->m_MixBus.m_pParent->m_MixBus;
        v4 = g_LEngineDefaultPoolId;
        if ( v3 )
          CAkVPLMixBusNode::Disconnect(v3);
        CAkVPLMixBusNode::~CAkVPLMixBusNode(&v2->m_MixBus);
        AK::MemoryMgr::Free(v4, v2);
        v5 = CAkLEngine::m_arrayVPLs.m_uLength;
        v6 = &CAkLEngine::m_arrayVPLs.m_pItems[v0];
        v7 = &CAkLEngine::m_arrayVPLs.m_pItems[CAkLEngine::m_arrayVPLs.m_uLength - 1i64];
        if ( v6 < v7 )
        {
          qmemcpy(v6, v6 + 1, 8 * (((unsigned __int64)((char *)v7 - (char *)v6 - 1) >> 3) + 1));
          v5 = CAkLEngine::m_arrayVPLs.m_uLength;
        }
        CAkLEngine::m_arrayVPLs.m_uLength = v5 - 1;
      }
      --v1;
      v0 = (unsigned int)(v0 - 1);
    }
    while ( (signed int)v0 >= 0 );
  }
}

// File Line: 2306
// RVA: 0xA52C00
void __fastcall CAkLEngine::RunVPL(AkRunningVPL *io_runningVPL)
{
  CAkVPLSrcCbxNode *v1; // r14
  __int64 v2; // rbx
  AkRunningVPL *v3; // rdi
  CAkVPLFilterNodeBase *v4; // rcx
  AKRESULT v5; // eax
  AKRESULT v6; // eax
  CAkVPLSrcNode *v7; // rsi
  AKRESULT v8; // eax
  CAkVPLFilterNodeBase *v9; // rcx
  AKRESULT v10; // eax
  AKRESULT v11; // eax
  CAkVPLSrcNode *v12; // rbx
  unsigned int v13; // ebp
  CAkPBI *v14; // rbx
  unsigned int i; // ecx
  __int64 v16; // rdx
  unsigned int *v17; // rsi
  _QWORD *v18; // rbx
  signed __int64 v19; // r15
  AkDeviceInfo *v20; // rax
  CAkVPLMixBusNode *v21; // r13
  __m128 v22; // xmm3
  __m128 v23; // xmm4
  float *v24; // rdx
  float *v25; // r8
  signed __int64 v26; // rcx
  signed __int64 v27; // rax
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
  float *v41; // r8
  float *v42; // r9
  signed __int64 v43; // rdx
  signed __int64 v44; // rax
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
  signed __int64 v57; // rcx
  __m128 v58; // xmm2
  __m128 v59; // xmm3
  __int64 v60; // rax
  __m128 v61; // xmm0
  __m128 v62; // xmm1
  __m128 v63; // xmm0
  char v64[16]; // [rsp+0h] [rbp-278h]
  char v65[16]; // [rsp+10h] [rbp-268h]
  char v66[16]; // [rsp+20h] [rbp-258h]
  char v67[16]; // [rsp+30h] [rbp-248h]
  AkAudioMix in_arMix; // [rsp+40h] [rbp-238h]
  signed __int64 v69; // [rsp+280h] [rbp+8h]
  __int64 v70; // [rsp+288h] [rbp+10h]

  v1 = io_runningVPL->pCbx;
  LODWORD(v2) = 4;
  v3 = io_runningVPL;
$GetFilter:
  while ( (_DWORD)v2 )
  {
    v2 = (unsigned int)(v2 - 1);
    v4 = v1->m_cbxRec.m_pFilter[v2];
    if ( v4 )
    {
      v4->vfptr[1].VirtualOn((CAkVPLNode *)&v4->vfptr, (AkVirtualQueueBehavior)v3);
      if ( v3->state.result != 43 )
      {
        v5 = v3->state.result;
        if ( v5 != 45 && v5 != 17 )
          return;
LABEL_7:
        LODWORD(v2) = v2 + 1;
        goto $ConsumeFilter;
      }
    }
  }
$GetPitch:
  CAkVPLPitchNode::GetBuffer(&v1->m_cbxRec.m_Pitch, &v3->state);
  v6 = v3->state.result;
  if ( v6 == 43 )
  {
    while ( 1 )
    {
      v3->state.uMaxFrames = v3->bFeedbackVPL ? 8 : 1024;
      v7 = v1->m_pSources[0];
      ((void (__fastcall *)(CAkVPLSrcNode *, AkRunningVPL *))v7->vfptr[1].ReleaseBuffer)(v1->m_pSources[0], v3);
      v8 = v3->state.result;
      if ( v8 == 46 && !(*((_BYTE *)v7 + 32) & 2) )
        *((_BYTE *)&v1->0 + 76) |= 0x20u;
      if ( v8 != 45 && v8 != 17 )
        return;
      CAkVPLPitchNode::ConsumeBuffer(&v1->m_cbxRec.m_Pitch, &v3->state);
      if ( v3->state.result != 43 )
      {
        v6 = v3->state.result;
        break;
      }
    }
  }
  if ( v6 != 45 && v6 != 17 )
    return;
$ConsumeFilter:
  while ( (unsigned int)v2 < 4 )
  {
    v9 = v1->m_cbxRec.m_pFilter[(unsigned int)v2];
    if ( !v9 )
      goto LABEL_7;
    ((void (__fastcall *)(CAkVPLFilterNodeBase *, AkRunningVPL *))v9->vfptr[1].VirtualOff)(v9, v3);
    v10 = v3->state.result;
    if ( v10 == 43 )
    {
      if ( (_DWORD)v2 )
        goto $GetFilter;
      goto $GetPitch;
    }
    if ( v10 == 45 )
      goto LABEL_7;
    if ( v10 != 17 )
      return;
    LODWORD(v2) = v2 + 1;
  }
  CAkVPLLPFNode::ConsumeBuffer(&v1->m_cbxRec.m_LPF, &v3->state);
  CAkVPLSrcCbxNode::ConsumeBuffer(v1, &v3->state);
  v11 = v3->state.result;
  if ( v11 == 45 || v11 == 17 )
  {
    CAkPlayingMgr::NotifyMarkers(g_pPlayingMgr, (AkPipelineBuffer *)&v3->state.pData);
    v12 = v1->m_pSources[0];
    v13 = 0;
    if ( v12 )
      v14 = v12->m_pCtx;
    else
      v14 = 0i64;
    if ( !(*((_BYTE *)v14 + 374) & 0x40) )
      CAkPBI::ValidateFeedbackParameters(v14);
    if ( v14->m_pFeedbackInfo && v1->m_OutputDevices.m_uNumDevices > 0 )
    {
      if ( CAkFeedbackDeviceMgr::PrepareAudioProcessing(CAkLEngine::m_pDeviceMgr, v3) )
      {
        CAkFeedbackDeviceMgr::ApplyMotionLPF(v3);
        CAkFeedbackDeviceMgr::ConsumeVPL(CAkLEngine::m_pDeviceMgr, v3);
        CAkFeedbackDeviceMgr::CleanupAudioVPL(v3);
      }
      else
      {
        CAkFeedbackDeviceMgr::ConsumeVPL(CAkLEngine::m_pDeviceMgr, v3);
      }
    }
    if ( v3->state.bAudible )
    {
      for ( i = v3->state.uChannelMask; i; i &= i - 1 )
        ++v13;
      if ( !v3->state.bIsAuxRoutable )
        goto LABEL_67;
      v16 = (unsigned __int8)v1->m_uNumSends;
      v70 = v16;
      if ( v16 <= 0 )
        goto LABEL_67;
      v17 = &v1->m_arSendValues[0].PerDeviceAuxBusses.m_uLength;
      while ( 1 )
      {
        v18 = (_QWORD *)*((_QWORD *)v17 - 1);
        if ( v18 == &v18[2 * *v17] )
          goto LABEL_66;
        v19 = (signed __int64)&v18[2 * *v17];
        v69 = (signed __int64)&v18[2 * *v17];
        do
        {
          v20 = v1->m_OutputDevices.m_listDeviceVolumes.m_pFirst;
          v21 = (CAkVPLMixBusNode *)v18[1];
          if ( v20 )
          {
            while ( v20->uDeviceID != *v18 )
            {
              v20 = v20->pNextLightItem;
              if ( !v20 )
                goto LABEL_64;
            }
            if ( v20 )
            {
              if ( *(v17 - 3) )
              {
                if ( v13 )
                {
                  v39 = (__m128)*(v17 - 6);
                  v40 = (__m128)*(v17 - 5);
                  v41 = (float *)&v20->mxAttenuations.userDef;
                  v42 = &v20->mxAttenuations.userDef.fPrev;
                  v43 = (signed __int64)&v20->mxDirect[0].Previous.aVolumes[4];
                  v44 = -(signed __int64)v20;
                  v45 = &v65[v44];
                  v46 = &v67[v44];
                  v47 = &v64[v44];
                  v48 = &v66[v44];
                  v49 = v13;
                  do
                  {
                    v50 = *(__m128 *)(v43 - 48);
                    v51 = v39;
                    v43 += 64i64;
                    v51.m128_f32[0] = v39.m128_f32[0] * *v41;
                    v52 = _mm_shuffle_ps(v51, v51, 0);
                    *(__m128 *)&v47[v43 - 64] = _mm_mul_ps(v50, v52);
                    v53 = _mm_mul_ps(*(__m128 *)(v43 - 96), v52);
                    v54 = v40;
                    *(__m128 *)&v45[v43 - 64] = v53;
                    v54.m128_f32[0] = v40.m128_f32[0] * *v42;
                    v55 = _mm_shuffle_ps(v54, v54, 0);
                    *(__m128 *)&v48[v43 - 64] = _mm_mul_ps(*(__m128 *)(v43 - 80), v55);
                    *(__m128 *)&v46[v43 - 64] = _mm_mul_ps(*(__m128 *)(v43 - 64), v55);
                    --v49;
                  }
                  while ( v49 );
LABEL_62:
                  v19 = v69;
                }
              }
              else if ( v13 )
              {
                v22 = (__m128)*(v17 - 6);
                v23 = (__m128)*(v17 - 5);
                v24 = (float *)&v20->mxAttenuations.gameDef;
                v25 = &v20->mxAttenuations.gameDef.fPrev;
                v26 = (signed __int64)&v20->mxDirect[0].Previous.aVolumes[4];
                v27 = -(signed __int64)v20;
                v28 = &v65[v27];
                v29 = &v67[v27];
                v30 = &v64[v27];
                v31 = &v66[v27];
                v32 = v13;
                do
                {
                  v33 = *(__m128 *)(v26 - 48);
                  v34 = v22;
                  v26 += 64i64;
                  v34.m128_f32[0] = v22.m128_f32[0] * *v24;
                  v35 = _mm_shuffle_ps(v34, v34, 0);
                  *(__m128 *)&v30[v26 - 64] = _mm_mul_ps(v33, v35);
                  v36 = _mm_mul_ps(*(__m128 *)(v26 - 96), v35);
                  v37 = v23;
                  *(__m128 *)&v28[v26 - 64] = v36;
                  v37.m128_f32[0] = v23.m128_f32[0] * *v25;
                  v38 = _mm_shuffle_ps(v37, v37, 0);
                  *(__m128 *)&v31[v26 - 64] = _mm_mul_ps(*(__m128 *)(v26 - 80), v38);
                  *(__m128 *)&v29[v26 - 64] = _mm_mul_ps(*(__m128 *)(v26 - 64), v38);
                  --v32;
                }
                while ( v32 );
                goto LABEL_62;
              }
              CAkVPLMixBusNode::ConsumeBuffer(v21, &v3->state, &in_arMix);
              goto LABEL_64;
            }
          }
LABEL_64:
          v18 += 2;
        }
        while ( v18 != (_QWORD *)v19 );
        v16 = v70;
LABEL_66:
        v17 += 8;
        v70 = --v16;
        if ( !v16 )
        {
LABEL_67:
          CAkVPLLPFNode::ConsumeBuffer(&v1->m_ObstructionLPF, &v3->state);
          if ( !v3->bFeedbackVPL )
          {
            for ( j = v1->m_OutputDevices.m_listDeviceVolumes.m_pFirst; j; j = j->pNextLightItem )
            {
              if ( !j->bCrossDeviceSend )
              {
                if ( v13 )
                {
                  v57 = (signed __int64)&j->mxDirect[0].Previous.aVolumes[4];
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
                    v61 = *(__m128 *)(v57 - 48);
                    v62 = *(__m128 *)(v57 - 32);
                    v57 += 64i64;
                    *(__m128 *)(v64 - (char *)j + v57 - 64) = _mm_mul_ps(v61, v58);
                    v63 = *(__m128 *)(v57 - 80);
                    *(__m128 *)(v65 - (char *)j + v57 - 64) = _mm_mul_ps(v62, v58);
                    *(__m128 *)(v66 - (char *)j + v57 - 64) = _mm_mul_ps(v63, v59);
                    *(__m128 *)(v67 - (char *)j + v57 - 64) = _mm_mul_ps(v59, *(__m128 *)(v57 - 64));
                    --v60;
                  }
                  while ( v60 );
                }
                CAkVPLMixBusNode::ConsumeBuffer(&j->pMixBus->m_MixBus, &v3->state, &in_arMix);
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
  CAkVPLSrcCbxNode *v0; // rbx
  CAkVPLSrcCbxNode *v1; // rsi
  CAkVPLSrcNode *v2; // rax
  CAkPBI *v3; // rax
  char v4; // al
  CAkVPLSrcNode *v5; // rdi
  CAkVPLSrcCbxNode *v6; // rcx
  CAkVPLSrcNode *v7; // rax
  CAkPBI *v8; // rcx
  CAkVPLSrcCbxNode *v9; // rax
  bool v10; // zf
  __int64 i; // rdi
  CAkVPLMixBusNode *v12; // rbx
  AkDevice *v13; // rbx
  __int64 v14; // rdx
  AkDevice *j; // rdi
  __m128i v16; // [rsp+10h] [rbp-39h]
  __int128 v17; // [rsp+20h] [rbp-29h]
  AkVPLState io_state; // [rsp+30h] [rbp-19h]
  CAkVPLSrcCbxNode *v19; // [rsp+70h] [rbp+27h]
  __int64 v20; // [rsp+78h] [rbp+2Fh]
  char v21; // [rsp+80h] [rbp+37h]

  if ( g_pPositionRepository->m_mapPosInfo.m_uLength )
    QueryPerformanceCounter((LARGE_INTEGER *)&g_pPositionRepository->m_i64LastTimeUpdated);
  CAkLEngineCmds::ProcessDisconnectedSources(0x400u);
  CAkLEngine::AnalyzeMixingGraph();
  v0 = CAkLEngine::m_Sources.m_pFirst;
  v1 = 0i64;
  if ( CAkLEngine::m_Sources.m_pFirst )
  {
    while ( 1 )
    {
      io_state.pData = 0i64;
      io_state.uNumMarkers = 0;
      io_state.pMarkers = 0i64;
      io_state.uMaxFrames = 1024;
      *(_WORD *)&io_state.bPause = 0;
      io_state.result = 43;
      v2 = v0->m_pSources[0];
      if ( v2 )
        v3 = v2->m_pCtx;
      else
        v3 = 0i64;
      v4 = *((_BYTE *)v3 + 374) >> 7;
      v20 = 0i64;
      v21 = v4;
      if ( v4 )
        io_state.uMaxFrames = 8;
      if ( v0->m_eState != 1 )
        break;
      if ( CAkVPLSrcCbxNode::StartRun(v0, &io_state) )
      {
        v19 = v0;
        io_state.uValidFrames = 0;
        io_state.uNumMarkers = 0;
        io_state.pMarkers = 0i64;
        io_state.posInfo.uStartPos = -1;
        CAkLEngine::RunVPL((AkRunningVPL *)&io_state);
        if ( io_state.result == 46 )
          CAkVPLSrcCbxNode::RestorePreviousVolumes(v19, (AkPipelineBuffer *)&io_state.pData);
        else
          CAkVPLSrcCbxNode::ReleaseBuffer(v19);
      }
      if ( io_state.result != 17 )
      {
        if ( io_state.result != 2 && !io_state.bStop )
        {
          if ( io_state.bPause )
            v0->vfptr->Pause((CAkVPLSrcCbxNodeBase *)&v0->vfptr);
          goto LABEL_30;
        }
LABEL_28:
        v6 = v0;
LABEL_29:
        v0->vfptr->Stop((CAkVPLSrcCbxNodeBase *)v6);
        goto LABEL_30;
      }
      if ( io_state.bStop )
        goto LABEL_28;
      v5 = v0->m_pSources[1];
      v6 = v0;
      if ( !v5 )
        goto LABEL_29;
      v0->m_pSources[1] = 0i64;
      CAkVPLSrcCbxNode::RemovePipeline(v0, 0);
      if ( CAkVPLSrcCbxNodeBase::AddSrc((CAkVPLSrcCbxNodeBase *)&v0->vfptr, v5, 1) != 1
        || CAkVPLSrcCbxNode::AddPipeline(v0) != 1 )
      {
        goto LABEL_28;
      }
      CAkVPLSrcNode::Start(v5);
LABEL_30:
      if ( v0->m_eState == 2 )
      {
        v16.m128i_i64[1] = (__int64)v1;
        v16.m128i_i64[0] = (__int64)v0->pNextItem;
        if ( v0 == CAkLEngine::m_Sources.m_pFirst )
          CAkLEngine::m_Sources.m_pFirst = (CAkVPLSrcCbxNode *)v0->pNextItem;
        else
          v1->pNextItem = v0->pNextItem;
        v9 = CAkLEngine::m_Sources.m_pLast;
        v10 = v0 == CAkLEngine::m_Sources.m_pLast;
        _mm_store_si128((__m128i *)&v17, v16);
        if ( v10 )
          v9 = v1;
        --CAkLEngine::m_Sources.m_ulNumListItems;
        CAkLEngine::m_Sources.m_pLast = v9;
        CAkLEngineCmds::DeleteAllCommandsForSource((CAkVPLSrcCbxNodeBase *)&v0->vfptr);
        CAkLEngine::VPLDestroySource((CAkVPLSrcCbxNodeBase *)&v0->vfptr, 0i64);
        v1 = (CAkVPLSrcCbxNode *)*((_QWORD *)&v17 + 1);
        v0 = (CAkVPLSrcCbxNode *)v17;
      }
      else
      {
        v1 = v0;
        v0 = (CAkVPLSrcCbxNode *)v0->pNextItem;
      }
      if ( !v0 )
        goto LABEL_39;
    }
    v7 = v0->m_pSources[0];
    if ( !v7 )
      goto LABEL_30;
    v8 = v7->m_pCtx;
    if ( !v8 || !(*((_BYTE *)v8 + 373) & 0x10) )
      goto LABEL_30;
    io_state.bStop = 1;
    goto LABEL_28;
  }
LABEL_39:
  for ( i = CAkLEngine::m_arrayVPLs.m_uLength - 1; i >= 0; --i )
  {
    v12 = &CAkLEngine::m_arrayVPLs.m_pItems[i]->m_MixBus;
    if ( !(LOBYTE(v12[1].m_PanningVolumes[0].Next.aVolumes[4]) & 8) )
    {
      CAkLEngine::TransferBuffer(CAkLEngine::m_arrayVPLs.m_pItems[i]);
      CAkVPLMixBusNode::ReleaseBuffer(v12);
    }
  }
  v13 = CAkOutputMgr::m_Devices.m_pItems;
  v14 = CAkOutputMgr::m_Devices.m_uLength;
  for ( j = CAkOutputMgr::m_Devices.m_pItems; j != &CAkOutputMgr::m_Devices.m_pItems[CAkOutputMgr::m_Devices.m_uLength]; ++j )
  {
    AkDevice::PushData(j);
    v14 = CAkOutputMgr::m_Devices.m_uLength;
    v13 = CAkOutputMgr::m_Devices.m_pItems;
  }
  if ( v13 != &v13[v14] )
  {
    do
    {
      CAkVPLFinalMixNode::ReleaseBuffer(v13->pFinalMix);
      ++v13;
    }
    while ( v13 != &CAkOutputMgr::m_Devices.m_pItems[CAkOutputMgr::m_Devices.m_uLength] );
  }
}

