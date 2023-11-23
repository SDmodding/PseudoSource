// File Line: 217
// RVA: 0x1464F70
__int64 dynamic_initializer_for__UFG::WwiseEnvironment::sm_All__()
{
  UFG::qWiseSymbol::create_from_string(&UFG::WwiseEnvironment::sm_All, "EnvType_All");
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::WwiseEnvironment::sm_All__);
}

// File Line: 218
// RVA: 0x1464FF0
__int64 dynamic_initializer_for__UFG::WwiseEnvironment::sm_SFX__()
{
  UFG::qWiseSymbol::create_from_string(&UFG::WwiseEnvironment::sm_SFX, "EnvType_SFX");
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::WwiseEnvironment::sm_SFX__);
}

// File Line: 219
// RVA: 0x1465020
__int64 dynamic_initializer_for__UFG::WwiseEnvironment::sm_Speech__()
{
  UFG::qWiseSymbol::create_from_string(&UFG::WwiseEnvironment::sm_Speech, "EnvType_Speech");
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::WwiseEnvironment::sm_Speech__);
}

// File Line: 224
// RVA: 0x143D90
UFG::qString *__fastcall UFG::ConvertAkLpCtstrToChar(UFG::qString *result, const wchar_t *in_FileName)
{
  __int64 v3; // rax
  char s[120]; // [rsp+30h] [rbp-78h] BYREF

  v3 = -1i64;
  do
    ++v3;
  while ( in_FileName[v3] );
  wcstombs(s, in_FileName, (int)v3 + 1);
  UFG::qString::qString(result);
  UFG::qString::Set(result, s);
  return result;
}

// File Line: 255
// RVA: 0x1465050
__int64 dynamic_initializer_for__UFG::WwiseInterface::sm_WwiseLowLevelIODevices__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::WwiseInterface::sm_WwiseLowLevelIODevices__);
}

// File Line: 262
// RVA: 0x1464F60
__int64 dynamic_initializer_for__UFG::WwiseInterface::sm_AfterLoadEvents__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::WwiseInterface::sm_AfterLoadEvents__);
}

// File Line: 302
// RVA: 0x147710
void __fastcall UFG::WwiseInterface::InitializeSoundEngine(UFG::SoundEngineInitParams *params)
{
  char *v2; // rax
  int *p_mNext; // r14
  int *p_affinityMask; // r12
  char *v5; // rax
  UFG::WwiseDefaultIOHookDeferred *v6; // rax
  UFG::WwiseDefaultIOHookDeferred *v7; // r13
  UFG::qSymbolUC *Name; // rax
  char *v9; // rax
  unsigned int size; // ecx
  unsigned int v11; // esi
  unsigned int v12; // ebx
  unsigned __int64 v13; // rax
  char *v14; // rax
  UFG::WwiseFilePackageLowLevelIODeferred **p; // rdi
  UFG::WwiseFilePackageLowLevelIODeferred **v16; // rcx
  unsigned int i; // r8d
  UFG::LowLevelIODispatcher *v18; // rdx
  __int64 v19; // rax
  AK::StreamMgr::IAkFileLocationResolver **m_arDevices; // rcx
  int preparedEventPoolSize; // edx
  unsigned int v22; // [rsp+30h] [rbp-90h]
  int affinityMask; // [rsp+34h] [rbp-8Ch]
  int stackSize; // [rsp+38h] [rbp-88h]
  AkInitSettings result; // [rsp+40h] [rbp-80h] BYREF
  __int64 v26; // [rsp+80h] [rbp-40h]
  AkPlatformInitSettings out_platformSettings; // [rsp+90h] [rbp-30h] BYREF
  AkDeviceSettings v28; // [rsp+E0h] [rbp+20h] BYREF
  UFG::SoundEngineInitParams *v29; // [rsp+1A0h] [rbp+E0h]
  AkStreamMgrSettings out_settings; // [rsp+1A8h] [rbp+E8h] BYREF
  AkMusicSettings v31; // [rsp+1B0h] [rbp+F0h] BYREF
  AkMemSettings in_pSettings; // [rsp+1B8h] [rbp+F8h] BYREF

  v26 = -2i64;
  v2 = UFG::qMalloc(0x28ui64, "LowLevelIODispatcher", 0i64);
  result.pfnAssertHook = (void (__fastcall *)(const char *, const char *, int))v2;
  if ( v2 )
  {
    *(_QWORD *)v2 = &AK::StreamMgr::IAkFileLocationResolver::`vftable;
    *(_QWORD *)v2 = &UFG::LowLevelIODispatcher::`vftable;
    *((_QWORD *)v2 + 1) = 0i64;
    *((_QWORD *)v2 + 2) = 0i64;
    *((_QWORD *)v2 + 3) = 0i64;
    *((_DWORD *)v2 + 8) = 0;
  }
  else
  {
    v2 = 0i64;
  }
  UFG::WwiseInterface::sm_ioDispatcher = (UFG::LowLevelIODispatcher *)v2;
  in_pSettings.uMaxNumPools = params->maxMemoryPools;
  if ( AK::MemoryMgr::Init(&in_pSettings) == AK_Success )
  {
    AK::StreamMgr::GetDefaultSettings(&out_settings);
    out_settings.uMemorySize = params->memorySize;
    if ( AK::StreamMgr::Create(&out_settings) )
    {
      AK::StreamMgr::SetFileLocationResolver(UFG::WwiseInterface::sm_ioDispatcher);
      affinityMask = params->affinityMask;
      stackSize = params->stackSize;
      AK::StreamMgr::GetDefaultDeviceSettings(&v28);
      p_mNext = (int *)&params->m_devices.mNode.mNext[-1].mNext;
      if ( p_mNext != &params->affinityMask )
      {
        p_affinityMask = &params->affinityMask;
        do
        {
          AK::StreamMgr::GetDefaultDeviceSettings((AkDeviceSettings *)&result.uMaxNumPaths);
          result.uDefaultPoolSize = p_mNext[7];
          result.uPrepareEventMemoryPoolID = p_mNext[8];
          *(float *)&result.eMainOutputType = (float)p_mNext[9];
          result.settingsMainOutput.uChannelMask = p_mNext[10];
          result.settingsMainOutput.ePanningRule = p_mNext[11];
          *(_DWORD *)&result.bEnableGameSyncPreparation = 2;
          result.uContinuousPlaybackLookAhead = 1;
          result.uMonitorPoolSize = affinityMask;
          result.uMonitorQueuePoolSize = stackSize;
          v5 = UFG::qMalloc(0x128ui64, "WwiseFilePackageLowLevelIODeferred", 0i64);
          if ( v5 )
          {
            UFG::WwiseFilePackageLowLevelIODeferred::WwiseFilePackageLowLevelIODeferred((UFG::WwiseFilePackageLowLevelIODeferred *)v5);
            v7 = v6;
          }
          else
          {
            v7 = 0i64;
          }
          v7->m_name.mUID = p_mNext[6];
          Name = (UFG::qSymbolUC *)UFG::WwiseDefaultIOHookDeferredBase::GetName(v7, (UFG::qSymbol *)&result);
          v9 = UFG::qSymbol::as_cstr_dbg(Name);
          UFG::qPrintf("Mounting Audio stream device: %s\n", v9);
          UFG::WwiseDefaultIOHookDeferred::Init(v7, (AkDeviceSettings *)&result.uMaxNumPaths, 1);
          size = UFG::WwiseInterface::sm_WwiseLowLevelIODevices.size;
          v22 = UFG::WwiseInterface::sm_WwiseLowLevelIODevices.size;
          v11 = UFG::WwiseInterface::sm_WwiseLowLevelIODevices.size + 1;
          if ( UFG::WwiseInterface::sm_WwiseLowLevelIODevices.size + 1 <= UFG::WwiseInterface::sm_WwiseLowLevelIODevices.capacity )
            goto LABEL_29;
          if ( UFG::WwiseInterface::sm_WwiseLowLevelIODevices.capacity )
            v12 = 2 * UFG::WwiseInterface::sm_WwiseLowLevelIODevices.capacity;
          else
            v12 = 1;
          for ( ; v12 < v11; v12 *= 2 )
            ;
          if ( v12 <= 2 )
            v12 = 2;
          if ( v12 - v11 > 0x10000 )
            v12 = UFG::WwiseInterface::sm_WwiseLowLevelIODevices.size + 65537;
          if ( v12 == UFG::WwiseInterface::sm_WwiseLowLevelIODevices.size )
          {
LABEL_29:
            p = UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p;
          }
          else
          {
            v13 = 8i64 * v12;
            if ( !is_mul_ok(v12, 8ui64) )
              v13 = -1i64;
            v14 = UFG::qMalloc(v13, "AddIODevice", 0i64);
            p = (UFG::WwiseFilePackageLowLevelIODeferred **)v14;
            v16 = UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p;
            if ( UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p )
            {
              for ( i = 0;
                    i < UFG::WwiseInterface::sm_WwiseLowLevelIODevices.size;
                    v16 = UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p )
              {
                *(_QWORD *)&v14[8 * i] = v16[i];
                ++i;
              }
              operator delete[](v16);
            }
            UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p = p;
            UFG::WwiseInterface::sm_WwiseLowLevelIODevices.capacity = v12;
            size = v22;
          }
          UFG::WwiseInterface::sm_WwiseLowLevelIODevices.size = v11;
          p[size] = (UFG::WwiseFilePackageLowLevelIODeferred *)v7;
          v18 = UFG::WwiseInterface::sm_ioDispatcher;
          v19 = 0i64;
          m_arDevices = UFG::WwiseInterface::sm_ioDispatcher->m_arDevices;
          while ( *m_arDevices )
          {
            v19 = (unsigned int)(v19 + 1);
            ++m_arDevices;
            if ( (unsigned int)v19 >= 3 )
              goto LABEL_35;
          }
          UFG::WwiseInterface::sm_ioDispatcher->m_arDevices[v19] = v7;
          ++v18->m_uNumDevices;
LABEL_35:
          p_mNext = (int *)(*((_QWORD *)p_mNext + 2) - 8i64);
        }
        while ( p_mNext != p_affinityMask );
        params = v29;
      }
      AK::SoundEngine::GetDefaultInitSettings(&result);
      AK::SoundEngine::GetDefaultPlatformInitSettings(&out_platformSettings);
      result.uDefaultPoolSize = params->defaultPoolSize;
      *(_QWORD *)&result.uMaxNumPaths = *(_QWORD *)&params->maxNumPaths;
      result.fDefaultPoolRatioThreshold = params->defaultPoolLowMemoryThreshold;
      result.uCommandQueueSize = 0x8000;
      result.uContinuousPlaybackLookAhead = 1;
      preparedEventPoolSize = params->preparedEventPoolSize;
      if ( preparedEventPoolSize > 0 )
      {
        result.uPrepareEventMemoryPoolID = AK::MemoryMgr::CreatePool(0i64, preparedEventPoolSize, 0x400u, 1u, 0);
        hkaReferencePoseAnimation::getNumOriginalFrames(
          (hkEntitySelectorAll *)(unsigned int)result.uPrepareEventMemoryPoolID,
          (hkpEntity *)L"PreparedEventPool");
      }
      out_platformSettings.uLEngineDefaultPoolSize = params->enginePoolSize;
      out_platformSettings.fLEngineDefaultPoolRatioThreshold = params->lowerEngineLowMemoryThreshold;
      if ( (unsigned int)AK::SoundEngine::Init(&result, &out_platformSettings) == 1 )
      {
        AK::MotionEngine::RegisterMotionDevice(0, 0x196u, AkCreateRumblePlugin);
        AK::SoundEngine::RegisterPlugin(
          AkPluginTypeMotionSource,
          0,
          0x195u,
          AkCreateMotionGenerator,
          AkCreateMotionGeneratorParams);
        AK::SoundEngine::SetListenerPipeline(0, 1, 1);
        v31.fStreamingLookAheadRatio = params->streamingLookAheadRatio;
        AK::MusicEngine::GetDefaultInitSettings(&v31);
        if ( AK::MusicEngine::Init(&v31) == AK_Success )
        {
          UFG::WwiseInterface::RegisterPlugins();
          Scaleform::Render::DICommand_ApplyFilter::GetType(0i64);
        }
      }
    }
  }
}

// File Line: 537
// RVA: 0x14B070
void UFG::WwiseInterface::RegisterPlugins(void)
{
  AK::SoundEngine::RegisterCodec(0, 4u, CreateVorbisFilePlugin, CreateVorbisBankPlugin);
  AK::SoundEngine::RegisterPlugin(AkPluginTypeSource, 0x40u, 0, CreateGrainPlayerSource, CreateGrainPlayerSourceParams);
  AK::SoundEngine::RegisterPlugin(AkPluginTypeEffect, 0, 0x73u, CreateMatrixReverbFX, CreateMatrixReverbFXParams);
  AK::SoundEngine::RegisterPlugin(AkPluginTypeEffect, 0, 0x69u, CreateParametricEQFX, CreateParametricEQFXParams);
  AK::SoundEngine::RegisterPlugin(AkPluginTypeEffect, 0, 0x6Au, CreateDelayFX, CreateDelayFXParams);
  AK::SoundEngine::RegisterPlugin(AkPluginTypeEffect, 0, 0x6Cu, CreateCompressorFX, CreateCompressorFXParams);
  AK::SoundEngine::RegisterPlugin(AkPluginTypeEffect, 0, 0x7Du, CreateFlangerFX, CreateFlangerFXParams);
  AK::SoundEngine::RegisterPlugin(AkPluginTypeSource, 0, 0x65u, CreateSilenceSource, CreateSilenceSourceParams);
  AK::SoundEngine::RegisterPlugin(AkPluginTypeSource, 0, 0x66u, CreateToneSource, CreateToneSourceParams);
  AK::SoundEngine::RegisterPlugin(
    AkPluginTypeEffect,
    0,
    0x74u,
    CreateAkSoundSeedImpactFX,
    CreateAkSoundSeedImpactFXParams);
  AK::SoundEngine::RegisterPlugin(AkPluginTypeEffect, 0, 0x76u, CreateRoomVerbFX, CreateRoomVerbFXParams);
  AK::SoundEngine::RegisterPlugin(AkPluginTypeSource, 0, 0x77u, CreateSoundSeedWind, CreateSoundSeedWindParams);
  AK::SoundEngine::RegisterPlugin(AkPluginTypeSource, 0, 0x78u, CreateSoundSeedWoosh, CreateSoundSeedWooshParams);
  AK::SoundEngine::RegisterPlugin(AkPluginTypeEffect, 0, 0x88u, CreatePitchShifterFX, CreatePitchShifterFXParams);
  AK::SoundEngine::RegisterPlugin(AkPluginTypeEffect, 0, 0x82u, CreateTimeStretchFX, CreateTimeStretchFXParams);
  AK::SoundEngine::RegisterPlugin(AkPluginTypeEffect, 0, 0x83u, CreateTremoloFX, CreateTremoloFXParams);
  AK::SoundEngine::RegisterPlugin(AkPluginTypeEffect, 0, 0x81u, CreateMeterFX, CreateMeterFXParams);
  AK::SoundEngine::RegisterPlugin(AkPluginTypeEffect, 0, 0x8Bu, CreateGainFX, CreateGainFXParams);
  AK::SoundEngine::RegisterPlugin(AkPluginTypeEffect, 0, 0x8Au, CreateHarmonizerFX, CreateHarmonizerFXParams);
  AK::SoundEngine::RegisterPlugin(AkPluginTypeEffect, 0x100u, 0x67u, CreateMcDSPML1FX, CreateMcDSPML1FXParams);
  AK::SoundEngine::RegisterPlugin(AkPluginTypeEffect, 0x100u, 0x6Eu, CreateMcDSPFutzBoxFX, CreateMcDSPFutzBoxFXParams);
  AK::SoundEngine::RegisterPlugin(
    AkPluginTypeEffect,
    0,
    0x7Fu,
    CreateConvolutionReverbFX,
    CreateConvolutionReverbFXParams);
  AK::SoundEngine::RegisterPlugin(AkPluginTypeSource, 0, 0xC9u, CreateMP3Source, CreateMP3SourceParams);
}

// File Line: 666
// RVA: 0x14C9B0
void UFG::WwiseInterface::ShutdownSoundEngine(void)
{
  UFG::WwiseDefaultIOHookDeferredBase **p; // rbx
  UFG::WwiseFilePackageLowLevelIODeferred **v1; // rcx
  AK::SoundEngine *v2; // rcx
  UFG::WwiseFilePackageLowLevelIODeferred **v3; // r8
  unsigned int size; // edx
  unsigned int v5; // edi
  UFG::WwiseFilePackageLowLevelIODeferred **i; // rsi
  UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred> *v7; // rbx
  UFG::WwiseFilePackageLowLevelIODeferred *v8; // rcx
  AK::MemoryMgr *v9; // rcx

  AK::MotionEngine::RemovePlayerMotionDevice(0, 0, 0x196u);
  p = UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p;
  v1 = &UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p[UFG::WwiseInterface::sm_WwiseLowLevelIODevices.size];
  if ( UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p != v1 )
  {
    do
    {
      UFG::WwiseDefaultIOHookDeferredBase::KillAllTransfers(*p);
      v1 = &UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p[UFG::WwiseInterface::sm_WwiseLowLevelIODevices.size];
      ++p;
    }
    while ( p != v1 );
  }
  while ( UFG::TiDo::sm_asyncFileCount > 0 )
    ;
  AK::MusicEngine::Term((AK::MusicEngine *)v1);
  if ( AK::SoundEngine::IsInitialized() )
    AK::SoundEngine::Term(v2);
  v3 = UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p;
  size = UFG::WwiseInterface::sm_WwiseLowLevelIODevices.size;
  v5 = 0;
  for ( i = UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p;
        i != &UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p[UFG::WwiseInterface::sm_WwiseLowLevelIODevices.size];
        v3 = UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p )
  {
    v7 = *i;
    UFG::WwiseDefaultIOHookDeferred::Term(*i);
    UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred>::UnloadAllFilePackages(v7);
    v7->m_packages.m_pFirst = 0i64;
    size = UFG::WwiseInterface::sm_WwiseLowLevelIODevices.size;
  }
  if ( size )
  {
    do
    {
      v8 = v3[v5];
      if ( v8 )
      {
        v8->UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred>::UFG::WwiseDefaultIOHookDeferred::UFG::WwiseDefaultIOHookDeferredBase::AK::StreamMgr::IAkFileLocationResolver::vfptr->__vecDelDtor(
          v8,
          1u);
        v3 = UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p;
        size = UFG::WwiseInterface::sm_WwiseLowLevelIODevices.size;
      }
      ++v5;
    }
    while ( v5 < size );
  }
  v9 = (AK::MemoryMgr *)AK::IAkStreamMgr::m_pStreamMgr;
  if ( AK::IAkStreamMgr::m_pStreamMgr )
    AK::IAkStreamMgr::m_pStreamMgr->vfptr->Destroy(AK::IAkStreamMgr::m_pStreamMgr);
  AK::MemoryMgr::Term(v9);
}

// File Line: 778
// RVA: 0x14A7A0
void __fastcall UFG::WwiseInterface::PopulateExternalSourcesInfo(
        UFG::AudioEventExternalSourceInfo *inInfo,
        AkExternalSourceInfo **outInfo)
{
  unsigned int m_numExternals; // edi
  unsigned __int64 v5; // rax
  char *v6; // rax
  unsigned int v7; // ecx
  int v8; // r8d
  _QWORD *v9; // rdx
  unsigned int *v10; // r9
  __int64 v11; // r8

  m_numExternals = inInfo->m_numExternals;
  v5 = 32i64 * m_numExternals;
  if ( !is_mul_ok(m_numExternals, 0x20ui64) )
    v5 = -1i64;
  v6 = UFG::qMalloc(v5, "WwiseInterface::AkExternalSourceInfo", 0i64);
  v7 = 0;
  if ( v6 )
  {
    v8 = m_numExternals - 1;
    if ( (int)(m_numExternals - 1) >= 0 )
    {
      v9 = v6 + 8;
      do
      {
        *(v9 - 1) = 0i64;
        *v9 = 0i64;
        v9[1] = 0i64;
        v9[2] = 0i64;
        v9 += 4;
        --v8;
      }
      while ( v8 >= 0 );
    }
  }
  else
  {
    v6 = 0i64;
  }
  *outInfo = (AkExternalSourceInfo *)v6;
  if ( inInfo->m_numExternals )
  {
    v10 = (unsigned int *)(v6 + 28);
    do
    {
      v11 = v7;
      *(v10 - 6) = inInfo->m_externals.p[v11].m_codecID;
      *(v10 - 7) = inInfo->m_externals.p[v11].m_externalSourceCookie;
      *v10 = inInfo->m_externals.p[v11].m_fileId;
      v10 += 8;
      ++v7;
    }
    while ( v7 < inInfo->m_numExternals );
  }
}

// File Line: 959
// RVA: 0x14C5A0
bool __fastcall UFG::WwiseInterface::SetWwiseSwitch(
        unsigned int switchId,
        unsigned int typeId,
        unsigned __int64 objectId)
{
  AKRESULT v6; // ebx

  v6 = AK_Fail;
  if ( AK::SoundEngine::IsInitialized() && switchId && typeId && !UFG::WwiseInterface::smShuttingDown )
    v6 = AK::SoundEngine::SetSwitch(switchId, typeId, objectId);
  return v6 == AK_Success;
}

// File Line: 975
// RVA: 0x14C510
bool __fastcall UFG::WwiseInterface::SetWwiseState(unsigned int stateId, unsigned int modeId)
{
  AKRESULT v4; // ebx

  v4 = AK_Fail;
  if ( AK::SoundEngine::IsInitialized() && stateId && modeId && !UFG::WwiseInterface::smShuttingDown )
    v4 = AK::SoundEngine::SetState(stateId, modeId);
  return v4 == AK_Success;
}

// File Line: 993
// RVA: 0x14C440
bool __fastcall UFG::WwiseInterface::SetWwiseRtpcValue(unsigned int rtpcId, float value, unsigned __int64 objectId)
{
  AKRESULT v5; // ebx

  v5 = AK_Fail;
  if ( AK::SoundEngine::IsInitialized() && rtpcId && !UFG::WwiseInterface::smShuttingDown )
    v5 = AK::SoundEngine::SetRTPCValue(rtpcId, value, objectId, 0, AkCurveInterpolation_Linear);
  return v5 == AK_Success;
}

// File Line: 1009
// RVA: 0x14AAB0
__int64 __fastcall UFG::WwiseInterface::PostAudioEvent(
        unsigned int eventId,
        unsigned __int64 objectId,
        unsigned int flags,
        void (__fastcall *callbackFunc)(AkCallbackType, AkCallbackInfo *),
        void *pUserData)
{
  unsigned int v9; // ebx
  __int64 size; // r13
  unsigned int v11; // ebx
  unsigned int v12; // edx
  UFG::AudioEventInfo *v13; // rcx

  v9 = 0;
  if ( UFG::WwiseInterface::smLoadScreen )
  {
    size = UFG::WwiseInterface::sm_AfterLoadEvents.size;
    v11 = UFG::WwiseInterface::sm_AfterLoadEvents.size + 1;
    if ( UFG::WwiseInterface::sm_AfterLoadEvents.size + 1 > UFG::WwiseInterface::sm_AfterLoadEvents.capacity )
    {
      if ( UFG::WwiseInterface::sm_AfterLoadEvents.capacity )
        v12 = 2 * UFG::WwiseInterface::sm_AfterLoadEvents.capacity;
      else
        v12 = 1;
      for ( ; v12 < v11; v12 *= 2 )
        ;
      if ( v12 - v11 > 0x10000 )
        v12 = UFG::WwiseInterface::sm_AfterLoadEvents.size + 65537;
      UFG::qArray<UFG::AudioEventInfo,0>::Reallocate(&UFG::WwiseInterface::sm_AfterLoadEvents, v12, "TiDo");
    }
    UFG::WwiseInterface::sm_AfterLoadEvents.size = v11;
    v13 = &UFG::WwiseInterface::sm_AfterLoadEvents.p[size];
    v13->eventId = eventId;
    v13->objectId = objectId;
    v13->flags = flags;
    v13->callbackFun = callbackFunc;
    v13->pUserData = pUserData;
    return 0i64;
  }
  if ( AK::SoundEngine::IsInitialized() && eventId && !UFG::WwiseInterface::smShuttingDown )
  {
    if ( !UFG::TiDo::IsEventEnabled(UFG::TiDo::m_pInstance, eventId) )
      return 0i64;
    return (unsigned int)AK::SoundEngine::PostEvent(eventId, objectId, flags, callbackFunc, pUserData, 0, 0i64, 0);
  }
  return v9;
}

// File Line: 1291
// RVA: 0x148DA0
void __fastcall UFG::WwiseInterface::LocalWwiseOutput(
        AK::Monitor::ErrorCode in_eErrorCode,
        const wchar_t *in_pszError,
        AK::Monitor::ErrorLevel in_eErrorLevel,
        unsigned int in_playingID,
        unsigned __int64 in_gameObjID)
{
  __int64 v7; // rax
  char v8; // cl
  const char *v9; // rcx
  UFG::qString result; // [rsp+28h] [rbp-30h] BYREF

  UFG::qStringLength(in_pszError);
  str[0] = *(_BYTE *)in_pszError;
  v7 = 0i64;
  if ( str[0] )
  {
    do
    {
      if ( v7 >= 127 )
        break;
      v8 = in_pszError[++v7];
      str[v7] = v8;
    }
    while ( v8 );
  }
  UFG::qString::FormatEx(&result, "Wwise Obj %u :", in_gameObjID);
  v9 = "AK Error: %u %s\n";
  if ( in_eErrorLevel != ErrorLevel_Error )
    v9 = "AK Warning: %u %s\n";
  UFG::qPrintf(v9, in_gameObjID, str);
  UFG::qString::~qString(&result);
}

// File Line: 1320
// RVA: 0x146750
__int64 __fastcall UFG::WwiseInterface::GetStreamFileSize(unsigned int fileId)
{
  UFG::WwiseFilePackageLowLevelIODeferred **p; // rbx
  __int64 result; // rax
  int v4[6]; // [rsp+20h] [rbp-28h] BYREF
  char v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  p = UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p;
  v6 = -1;
  v5 = 0;
  v4[0] = 0;
  v4[1] = 4;
  if ( UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p == &UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p[UFG::WwiseInterface::sm_WwiseLowLevelIODevices.size] )
    return 0i64;
  while ( 1 )
  {
    result = ((__int64 (__fastcall *)(UFG::WwiseFilePackageLowLevelIODeferred *, _QWORD, int *))(*p)->UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred>::UFG::WwiseDefaultIOHookDeferred::UFG::WwiseDefaultIOHookDeferredBase::AK::StreamMgr::IAkFileLocationResolver::vfptr[1].Open)(
               *p,
               fileId,
               v4);
    if ( result )
      break;
    if ( ++p == &UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p[UFG::WwiseInterface::sm_WwiseLowLevelIODevices.size] )
      return 0i64;
  }
  return result;
}

// File Line: 1354
// RVA: 0x148AF0
char __fastcall UFG::WwiseInterface::LoadFilePackage(
        int *deviceName,
        const char *packageName,
        bool localized,
        bool dlc)
{
  UFG::WwiseFilePackageType v5; // r14d
  UFG::WwiseFilePackageLowLevelIODeferred **p; // rbx
  UFG::WwiseFilePackageLowLevelIODeferred **v7; // rsi
  int v8; // ebp
  UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred> *v9; // rdi
  const wchar_t *WideName; // rax
  const wchar_t *v11; // rax
  UFG::qString result; // [rsp+20h] [rbp-98h] BYREF
  AkFileSystemFlags in_pFlags; // [rsp+48h] [rbp-70h] BYREF
  __int64 v15; // [rsp+68h] [rbp-50h]
  UFG::qString out_FullFilePath; // [rsp+70h] [rbp-48h] BYREF
  UFG::qSymbol v17; // [rsp+D8h] [rbp+20h] BYREF

  v15 = -2i64;
  v5 = dlc;
  UFG::qString::FormatEx(&result, "%s", packageName);
  p = UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p;
  v7 = &UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p[UFG::WwiseInterface::sm_WwiseLowLevelIODevices.size];
  if ( UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p != v7 )
  {
    v8 = *deviceName;
    while ( 1 )
    {
      v9 = *p;
      if ( UFG::WwiseDefaultIOHookDeferredBase::GetName(*p, &v17)->mUID == v8 )
        break;
      if ( ++p == v7 )
        goto LABEL_9;
    }
    UFG::qString::qString(&out_FullFilePath);
    in_pFlags.uCacheID = -1;
    *(_QWORD *)&in_pFlags.uCompanyID = 0i64;
    in_pFlags.bIsLanguageSpecific = 0;
    in_pFlags.pCustomParam = 0i64;
    WideName = UFG::qString::GetWideName(&result);
    UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred>::LoadFilePackage(v9, WideName, &v17.mUID, v5);
    v11 = UFG::qString::GetWideName(&result);
    UFG::WwiseFileLocationBase::BuildFilePath(&v9->UFG::WwiseFileLocationBase, v11, &in_pFlags, &out_FullFilePath);
    if ( UFG::qGetFileSize(out_FullFilePath.mData) >= 1024 )
    {
      UFG::qPrintf("\nLoading File Package.... %s\n", result.mData);
      UFG::qString::~qString(&out_FullFilePath);
      UFG::qString::~qString(&result);
      return 1;
    }
    UFG::qPrintf("ERROR LOADING FILE PACKAGE.... %s\n", result.mData);
    UFG::qString::~qString(&out_FullFilePath);
  }
LABEL_9:
  UFG::qString::~qString(&result);
  return 0;
}

// File Line: 1405
// RVA: 0x14CF50
void __fastcall UFG::WwiseInterface::UnloadFilePackage(const char *packageName)
{
  UFG::WwiseFilePackageLowLevelIODeferred **i; // r14
  int v3; // eax
  UFG::WwiseDefaultIOHookDeferred *v4; // r8
  UFG::TidoFilePackage *v5; // rcx
  UFG::TidoFilePackage *m_pFirst; // rdx
  UFG::TidoFilePackage *pNextItem; // rbx
  AK::StreamMgr::IAkFileLocationResolverVtbl *v8; // rax
  int m_poolID; // edi
  void *m_pToRelease; // rsi

  for ( i = UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p;
        i != &UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p[UFG::WwiseInterface::sm_WwiseLowLevelIODevices.size];
        ++i )
  {
    v3 = UFG::qStringHash32(packageName, 0xFFFFFFFF);
    v4 = *i;
    v5 = 0i64;
    m_pFirst = (*i)->m_packages.m_pFirst;
    pNextItem = m_pFirst;
    if ( m_pFirst )
    {
      while ( pNextItem->m_uid != v3 )
      {
        v5 = pNextItem;
        pNextItem = pNextItem->pNextItem;
        if ( !pNextItem )
          goto LABEL_13;
      }
      v8 = (AK::StreamMgr::IAkFileLocationResolverVtbl *)pNextItem->pNextItem;
      if ( pNextItem == m_pFirst )
        v4[1].UFG::WwiseDefaultIOHookDeferredBase::AK::StreamMgr::IAkFileLocationResolver::vfptr = v8;
      else
        v5->pNextItem = (UFG::TidoFilePackage *)v8;
      UFG::WwiseDefaultIOHookDeferred::Close(v4, &pNextItem->m_hFile);
      m_poolID = pNextItem->m_poolID;
      m_pToRelease = pNextItem->m_pToRelease;
      pNextItem->vfptr->__vecDelDtor(pNextItem, 0);
      if ( m_poolID != -1 )
      {
        if ( m_pToRelease )
          AK::MemoryMgr::ReleaseBlock(m_poolID, m_pToRelease);
        AK::MemoryMgr::DestroyPool(m_poolID);
      }
    }
LABEL_13:
    ;
  }
}

// File Line: 1429
// RVA: 0x14BD70
void __fastcall UFG::WwiseInterface::SetIOPaths(
        const char *basePath,
        const char *bankPath,
        const char *srcPath,
        const char *langPath,
        const char *DLCPath)
{
  UFG::WwiseFilePackageLowLevelIODeferred **p; // rsi
  const char *v9; // rdx
  const char *v10; // r14
  UFG::WwiseFilePackageLowLevelIODeferred *v11; // rdi
  UFG::TidoFilePackage *m_pFirst; // rbx
  const wchar_t *WideName; // rax
  UFG::AudioFilePackageLUT::StringMap *m_pLangMap; // rcx
  unsigned __int16 ID; // ax

  p = UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p;
  v9 = basePath;
  if ( UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p != &UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p[UFG::WwiseInterface::sm_WwiseLowLevelIODevices.size] )
  {
    v10 = DLCPath;
    do
    {
      UFG::qString::Set(&(*p)->m_WwiseBasePath, v9);
      UFG::qString::Set(&(*p)->m_WwiseBankPath, bankPath);
      UFG::qString::Set(&(*p)->m_WwiseSrcPath, srcPath);
      v11 = *p;
      UFG::qString::Set(&(*p)->m_WwiseLangPath, langPath);
      m_pFirst = v11->m_packages.m_pFirst;
      if ( m_pFirst )
      {
        do
        {
          if ( v11->m_WwiseLangPath.mLength <= 0 )
          {
            m_pFirst->lut.m_curLangID = 0;
          }
          else
          {
            WideName = UFG::qString::GetWideName(&v11->m_WwiseLangPath);
            m_pLangMap = m_pFirst->lut.m_pLangMap;
            m_pFirst->lut.m_curLangID = 0;
            if ( m_pLangMap && WideName )
            {
              ID = UFG::AudioFilePackageLUT::StringMap::GetID(m_pLangMap, WideName);
              if ( ID )
                m_pFirst->lut.m_curLangID = ID;
            }
          }
          m_pFirst = m_pFirst->pNextItem;
        }
        while ( m_pFirst );
        v10 = DLCPath;
      }
      UFG::qString::Set(&(*p)->m_WwiseDLCPath, v10);
      v9 = basePath;
      ++p;
    }
    while ( p != &UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p[UFG::WwiseInterface::sm_WwiseLowLevelIODevices.size] );
  }
}

// File Line: 1523
// RVA: 0x14A2A0
AkExternalSourceArray *__fastcall UFG::WwiseInterface::PlayEvent(UFG::AudioEvent *pEvent)
{
  AkExternalSourceInfo *in_pExternalSources; // rbx
  UFG::AudioEventExternalSourceInfo *m_externalInfo; // rcx
  unsigned int in_cExternals; // eax
  AkExternalSourceArray *result; // rax
  unsigned int v6; // edi
  AkExternalSourceInfo *outInfo; // [rsp+50h] [rbp+8h] BYREF

  in_pExternalSources = 0i64;
  m_externalInfo = pEvent->m_externalInfo;
  in_cExternals = 0;
  outInfo = 0i64;
  if ( m_externalInfo && m_externalInfo->m_numExternals )
  {
    UFG::WwiseInterface::PopulateExternalSourcesInfo(m_externalInfo, &outInfo);
    in_pExternalSources = outInfo;
    in_cExternals = pEvent->m_externalInfo->m_numExternals;
  }
  result = AK::SoundEngine::PostEvent(
             pEvent->m_uEventId,
             (unsigned __int64)pEvent->m_pEntity,
             0x30005u,
             UFG::WwiseInterface::WwiseEndEventCallback,
             pEvent,
             in_cExternals,
             in_pExternalSources,
             0);
  v6 = (unsigned int)result;
  if ( in_pExternalSources )
  {
    operator delete[](in_pExternalSources);
    return (AkExternalSourceArray *)v6;
  }
  return result;
}

// File Line: 1602
// RVA: 0x145120
AK::SoundEngine::DynamicSequence::Playlist *__fastcall UFG::WwiseInterface::Enqueue(
        UFG::AudioDialogEvent *pEvent,
        unsigned int nodeId,
        int msDelay)
{
  AK::SoundEngine::DynamicSequence::Playlist *result; // rax
  unsigned int m_uPlayingId; // ebp
  AkArray<AK::SoundEngine::DynamicSequence::PlaylistItem,AK::SoundEngine::DynamicSequence::PlaylistItem const &,ArrayPoolDefault,4,AkArrayAllocatorDefault> *v8; // r14
  UFG::AudioEventExternalSourceInfo *m_externalInfo; // rcx
  unsigned int v10; // ebx
  AkExternalSourceInfo *v11; // rdi
  unsigned int m_numExternals; // r12d
  AK::SoundEngine::DynamicSequence::PlaylistItem *v13; // rax
  int v14; // esi
  AkExternalSourceInfo *outInfo; // [rsp+68h] [rbp+20h] BYREF

  if ( !AK::SoundEngine::IsInitialized() )
    return 0i64;
  m_uPlayingId = pEvent->m_uPlayingId;
  result = AK::SoundEngine::DynamicSequence::LockPlaylist(m_uPlayingId);
  v8 = result;
  if ( result )
  {
    m_externalInfo = pEvent->m_externalInfo;
    v10 = 0;
    outInfo = 0i64;
    v11 = 0i64;
    m_numExternals = 0;
    if ( m_externalInfo && m_externalInfo->m_numExternals )
    {
      UFG::WwiseInterface::PopulateExternalSourcesInfo(m_externalInfo, &outInfo);
      v11 = outInfo;
      m_numExternals = pEvent->m_externalInfo->m_numExternals;
    }
    v13 = (AK::SoundEngine::DynamicSequence::PlaylistItem *)AkArray<AK::SoundEngine::DynamicSequence::PlaylistItem,AK::SoundEngine::DynamicSequence::PlaylistItem const &,ArrayPoolDefault,4,AkArrayAllocatorDefault>::AddLast(v8);
    if ( v13 )
    {
      v13->audioNodeID = nodeId;
      v13->msDelay = msDelay;
      v13->pCustomInfo = 0i64;
      v14 = AK::SoundEngine::DynamicSequence::PlaylistItem::SetExternalSources(v13, m_numExternals, v11);
    }
    else
    {
      v14 = 2;
    }
    AK::SoundEngine::DynamicSequence::UnlockPlaylist(m_uPlayingId);
    if ( v11 )
      operator delete[](v11);
    if ( v14 == 1 )
      return (AK::SoundEngine::DynamicSequence::Playlist *)nodeId;
    return (AK::SoundEngine::DynamicSequence::Playlist *)v10;
  }
  return result;
}

// File Line: 1639
// RVA: 0x1452A0
AK::SoundEngine::DynamicSequence::Playlist *__fastcall UFG::WwiseInterface::EnqueueExternal(
        unsigned int playingId,
        unsigned int nodeId,
        UFG::AudioEventExternalSourceInfo *info,
        int msDelay)
{
  AK::SoundEngine::DynamicSequence::Playlist *result; // rax
  AkArray<AK::SoundEngine::DynamicSequence::PlaylistItem,AK::SoundEngine::DynamicSequence::PlaylistItem const &,ArrayPoolDefault,4,AkArrayAllocatorDefault> *v9; // rbp
  unsigned int v10; // ebx
  AkExternalSourceInfo *v11; // rdi
  unsigned int m_numExternals; // r15d
  AK::SoundEngine::DynamicSequence::PlaylistItem *v13; // rax
  int v14; // esi
  AkExternalSourceInfo *outInfo; // [rsp+20h] [rbp-38h] BYREF

  if ( !AK::SoundEngine::IsInitialized() )
    return 0i64;
  result = AK::SoundEngine::DynamicSequence::LockPlaylist(playingId);
  v9 = result;
  if ( result )
  {
    v10 = 0;
    v11 = 0i64;
    outInfo = 0i64;
    m_numExternals = 0;
    if ( info->m_numExternals )
    {
      UFG::WwiseInterface::PopulateExternalSourcesInfo(info, &outInfo);
      m_numExternals = info->m_numExternals;
      v11 = outInfo;
    }
    v13 = (AK::SoundEngine::DynamicSequence::PlaylistItem *)AkArray<AK::SoundEngine::DynamicSequence::PlaylistItem,AK::SoundEngine::DynamicSequence::PlaylistItem const &,ArrayPoolDefault,4,AkArrayAllocatorDefault>::AddLast(v9);
    if ( v13 )
    {
      v13->audioNodeID = nodeId;
      v13->msDelay = msDelay;
      v13->pCustomInfo = 0i64;
      v14 = AK::SoundEngine::DynamicSequence::PlaylistItem::SetExternalSources(v13, m_numExternals, v11);
    }
    else
    {
      v14 = 2;
    }
    AK::SoundEngine::DynamicSequence::UnlockPlaylist(playingId);
    if ( v11 )
      operator delete[](v11);
    if ( v14 == 1 )
      return (AK::SoundEngine::DynamicSequence::Playlist *)nodeId;
    return (AK::SoundEngine::DynamicSequence::Playlist *)v10;
  }
  return result;
}

// File Line: 1676
// RVA: 0x14E8E0
void __fastcall UFG::WwiseInterface::WwiseEndEventCallback(AkCallbackType in_eType, AkCallbackInfo *in_pCallbackInfo)
{
  char v3; // al
  const char *pCookie; // rcx
  UFG::AudioEvent *v5; // rbx
  int v6; // eax
  unsigned int v7; // eax
  unsigned int gameObjID; // edx
  unsigned int gameObjID_high; // ecx

  if ( (in_eType & 1) != 0 )
  {
    v3 = *((_BYTE *)in_pCallbackInfo->pCookie + 144);
    if ( (v3 & 0x40) != 0 )
      *((_BYTE *)in_pCallbackInfo->pCookie + 144) = v3 | 1;
  }
  else if ( (in_eType & 4) != 0 )
  {
    pCookie = (const char *)in_pCallbackInfo[2].pCookie;
    v5 = (UFG::AudioEvent *)in_pCallbackInfo->pCookie;
    if ( pCookie && *pCookie == 108 && pCookie[1] == 101 && pCookie[2] == 110 && pCookie[3] == 58 )
    {
      v6 = atol(pCookie + 4);
      *((_BYTE *)v5 + 144) |= 2u;
      v5->m_markerCallbackInfo.m_floatParameter = (float)v6 * 0.001;
    }
    else
    {
      v7 = UFG::qStringHashUpper32(pCookie, 0xFFFFFFFF);
      gameObjID = in_pCallbackInfo[1].gameObjID;
      gameObjID_high = HIDWORD(in_pCallbackInfo[1].gameObjID);
      *((_BYTE *)v5 + 144) |= 2u;
      v5->m_markerCallbackInfo.m_position = gameObjID_high;
      v5->m_markerCallbackInfo.m_identifier = gameObjID;
      *(_QWORD *)&v5->m_markerCallbackInfo.m_labelHash = v7;
    }
  }
}

// File Line: 1724
// RVA: 0x14AC60
__int64 __fastcall UFG::WwiseInterface::PrepareMP3(const char *filename)
{
  char *mData; // rbx
  unsigned int v3; // eax
  unsigned __int8 v4; // bl
  UFG::qString v6; // [rsp+30h] [rbp-C8h] BYREF
  __int64 v7; // [rsp+58h] [rbp-A0h]
  UFG::qString result; // [rsp+60h] [rbp-98h] BYREF
  AkMP3BaseInfo out_info; // [rsp+88h] [rbp-70h] BYREF
  wchar_t dest[264]; // [rsp+108h] [rbp+10h] BYREF
  AkMP3Tag out_pTag; // [rsp+318h] [rbp+220h] BYREF

  v7 = -2i64;
  dest[0] = 0;
  memset(&dest[5], 0, 0x206ui64);
  UFG::qWideStringCopy(dest, filename);
  UFG::qString::qString(&v6);
  UFG::qString::Set(
    &v6,
    (*UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p)->m_WwiseBasePath.mData,
    (*UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p)->m_WwiseBasePath.mLength,
    0i64,
    0);
  UFG::ConvertAkLpCtstrToChar(&result, dest);
  if ( !(unsigned int)UFG::qString::StartsWith(&result, "\\", -1)
    && !(unsigned int)UFG::qString::EndsWith(&v6, "\\", -1) )
  {
    UFG::qString::operator+=(&v6, "\\");
  }
  mData = result.mData;
  v3 = UFG::qStringLength(result.mData);
  UFG::qString::append(&v6, mData, v3);
  UFG::qString::~qString(&result);
  memset(&out_info, 0, sizeof(out_info));
  memset(&out_pTag, 0, sizeof(out_pTag));
  if ( AkMP3InfoRead(v6.mData, &out_info, &out_pTag) )
  {
    AkMP3PrepareForPlayback(dest, &out_info, (int)(float)((float)out_info.msDuration * 0.0), 0i64, 0i64);
    v4 = 1;
  }
  else
  {
    v4 = 0;
  }
  UFG::qString::~qString(&v6);
  return v4;
}

