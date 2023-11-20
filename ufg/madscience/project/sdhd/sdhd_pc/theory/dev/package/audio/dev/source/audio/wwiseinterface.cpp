// File Line: 217
// RVA: 0x1464F70
__int64 dynamic_initializer_for__UFG::WwiseEnvironment::sm_All__()
{
  UFG::qWiseSymbol::create_from_string(&UFG::WwiseEnvironment::sm_All, "EnvType_All");
  return atexit(dynamic_atexit_destructor_for__UFG::WwiseEnvironment::sm_All__);
}

// File Line: 218
// RVA: 0x1464FF0
__int64 dynamic_initializer_for__UFG::WwiseEnvironment::sm_SFX__()
{
  UFG::qWiseSymbol::create_from_string(&UFG::WwiseEnvironment::sm_SFX, "EnvType_SFX");
  return atexit(dynamic_atexit_destructor_for__UFG::WwiseEnvironment::sm_SFX__);
}

// File Line: 219
// RVA: 0x1465020
__int64 dynamic_initializer_for__UFG::WwiseEnvironment::sm_Speech__()
{
  UFG::qWiseSymbol::create_from_string(&UFG::WwiseEnvironment::sm_Speech, "EnvType_Speech");
  return atexit(dynamic_atexit_destructor_for__UFG::WwiseEnvironment::sm_Speech__);
}

// File Line: 224
// RVA: 0x143D90
UFG::qString *__fastcall UFG::ConvertAkLpCtstrToChar(UFG::qString *result, const wchar_t *in_FileName)
{
  UFG::qString *v2; // rbx
  signed __int64 v3; // rax
  char s; // [rsp+30h] [rbp-78h]

  v2 = result;
  v3 = -1i64;
  do
    ++v3;
  while ( in_FileName[v3] );
  wcstombs(&s, in_FileName, (signed int)v3 + 1);
  UFG::qString::qString(v2);
  UFG::qString::Set(v2, &s);
  return v2;
}

// File Line: 255
// RVA: 0x1465050
__int64 dynamic_initializer_for__UFG::WwiseInterface::sm_WwiseLowLevelIODevices__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::WwiseInterface::sm_WwiseLowLevelIODevices__);
}

// File Line: 262
// RVA: 0x1464F60
__int64 dynamic_initializer_for__UFG::WwiseInterface::sm_AfterLoadEvents__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::WwiseInterface::sm_AfterLoadEvents__);
}

// File Line: 302
// RVA: 0x147710
void __fastcall UFG::WwiseInterface::InitializeSoundEngine(UFG::SoundEngineInitParams *params)
{
  UFG::SoundEngineInitParams *v1; // r12
  UFG::LowLevelIODispatcher *v2; // rax
  signed __int64 v3; // r14
  signed __int64 v4; // r12
  char *v5; // rax
  UFG::WwiseDefaultIOHookDeferred *v6; // rax
  UFG::WwiseDefaultIOHookDeferred *v7; // r13
  UFG::qSymbolUC *v8; // rax
  char *v9; // rax
  unsigned int v10; // ecx
  unsigned int v11; // esi
  unsigned int v12; // ebx
  unsigned __int64 v13; // rax
  char *v14; // rax
  UFG::WwiseFilePackageLowLevelIODeferred **v15; // rdi
  UFG::WwiseFilePackageLowLevelIODeferred **v16; // rcx
  unsigned int v17; // er8
  UFG::LowLevelIODispatcher *v18; // rdx
  __int64 v19; // rax
  AK::StreamMgr::IAkFileLocationResolver **v20; // rcx
  signed int v21; // edx
  unsigned int v22; // [rsp+30h] [rbp-90h]
  unsigned int v23; // [rsp+34h] [rbp-8Ch]
  unsigned int v24; // [rsp+38h] [rbp-88h]
  UFG::qSymbol result[2]; // [rsp+40h] [rbp-80h]
  AkDeviceSettings in_deviceSettings; // [rsp+48h] [rbp-78h]
  __int64 v27; // [rsp+80h] [rbp-40h]
  AkPlatformInitSettings out_platformSettings; // [rsp+90h] [rbp-30h]
  AkDeviceSettings v29; // [rsp+E0h] [rbp+20h]
  UFG::SoundEngineInitParams *v30; // [rsp+1A0h] [rbp+E0h]
  AkStreamMgrSettings out_settings; // [rsp+1A8h] [rbp+E8h]
  AkMusicSettings v32; // [rsp+1B0h] [rbp+F0h]
  AkMemSettings in_pSettings; // [rsp+1B8h] [rbp+F8h]

  v27 = -2i64;
  v1 = params;
  v2 = (UFG::LowLevelIODispatcher *)UFG::qMalloc(0x28ui64, "LowLevelIODispatcher", 0i64);
  *(_QWORD *)&result[0].mUID = v2;
  if ( v2 )
  {
    v2->vfptr = (AK::StreamMgr::IAkFileLocationResolverVtbl *)&AK::StreamMgr::IAkFileLocationResolver::`vftable';
    v2->vfptr = (AK::StreamMgr::IAkFileLocationResolverVtbl *)&UFG::LowLevelIODispatcher::`vftable';
    v2->m_arDevices[0] = 0i64;
    v2->m_arDevices[1] = 0i64;
    v2->m_arDevices[2] = 0i64;
    v2->m_uNumDevices = 0;
  }
  else
  {
    v2 = 0i64;
  }
  UFG::WwiseInterface::sm_ioDispatcher = v2;
  in_pSettings.uMaxNumPools = v1->maxMemoryPools;
  if ( AK::MemoryMgr::Init(&in_pSettings) == 1 )
  {
    AK::StreamMgr::GetDefaultSettings(&out_settings);
    out_settings.uMemorySize = v1->memorySize;
    if ( AK::StreamMgr::Create(&out_settings) )
    {
      AK::StreamMgr::SetFileLocationResolver((AK::StreamMgr::IAkFileLocationResolver *)&UFG::WwiseInterface::sm_ioDispatcher->vfptr);
      v23 = v1->affinityMask;
      v24 = v1->stackSize;
      AK::StreamMgr::GetDefaultDeviceSettings(&v29);
      v3 = (signed __int64)&v1->m_devices.mNode.mNext[-1].mNext;
      if ( (int *)v3 != &v1->affinityMask )
      {
        v4 = (signed __int64)&v1->affinityMask;
        do
        {
          AK::StreamMgr::GetDefaultDeviceSettings(&in_deviceSettings);
          in_deviceSettings.uIOMemorySize = *(_DWORD *)(v3 + 28);
          in_deviceSettings.uGranularity = *(_DWORD *)(v3 + 32);
          in_deviceSettings.fTargetAutoStmBufferLength = (float)*(signed int *)(v3 + 36);
          in_deviceSettings.fMaxCacheRatio = *(float *)(v3 + 40);
          in_deviceSettings.uMaxConcurrentIO = *(_DWORD *)(v3 + 44);
          in_deviceSettings.uSchedulerTypeFlags = 2;
          in_deviceSettings.threadProperties.nPriority = 1;
          in_deviceSettings.threadProperties.dwAffinityMask = v23;
          in_deviceSettings.threadProperties.uStackSize = v24;
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
          v7->m_name.mUID = *(_DWORD *)(v3 + 24);
          v8 = (UFG::qSymbolUC *)UFG::WwiseDefaultIOHookDeferredBase::GetName(
                                   (UFG::WwiseDefaultIOHookDeferredBase *)&v7->vfptr,
                                   result);
          v9 = UFG::qSymbol::as_cstr_dbg(v8);
          UFG::qPrintf("Mounting Audio stream device: %s\n", v9);
          UFG::WwiseDefaultIOHookDeferred::Init(v7, &in_deviceSettings, 1);
          v10 = UFG::WwiseInterface::sm_WwiseLowLevelIODevices.size;
          v22 = UFG::WwiseInterface::sm_WwiseLowLevelIODevices.size;
          v11 = UFG::WwiseInterface::sm_WwiseLowLevelIODevices.size + 1;
          if ( UFG::WwiseInterface::sm_WwiseLowLevelIODevices.size + 1 <= UFG::WwiseInterface::sm_WwiseLowLevelIODevices.capacity )
            goto LABEL_44;
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
LABEL_44:
            v15 = UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p;
          }
          else
          {
            v13 = 8i64 * v12;
            if ( !is_mul_ok(v12, 8ui64) )
              v13 = -1i64;
            v14 = UFG::qMalloc(v13, "AddIODevice", 0i64);
            v15 = (UFG::WwiseFilePackageLowLevelIODeferred **)v14;
            v16 = UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p;
            if ( UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p )
            {
              v17 = 0;
              if ( UFG::WwiseInterface::sm_WwiseLowLevelIODevices.size )
              {
                do
                {
                  *(_QWORD *)&v14[8 * v17] = v16[v17];
                  ++v17;
                  v16 = UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p;
                }
                while ( v17 < UFG::WwiseInterface::sm_WwiseLowLevelIODevices.size );
              }
              operator delete[](v16);
            }
            UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p = v15;
            UFG::WwiseInterface::sm_WwiseLowLevelIODevices.capacity = v12;
            v10 = v22;
          }
          UFG::WwiseInterface::sm_WwiseLowLevelIODevices.size = v11;
          v15[v10] = (UFG::WwiseFilePackageLowLevelIODeferred *)v7;
          v18 = UFG::WwiseInterface::sm_ioDispatcher;
          v19 = 0i64;
          v20 = UFG::WwiseInterface::sm_ioDispatcher->m_arDevices;
          while ( *v20 )
          {
            v19 = (unsigned int)(v19 + 1);
            ++v20;
            if ( (unsigned int)v19 >= 3 )
              goto LABEL_35;
          }
          UFG::WwiseInterface::sm_ioDispatcher->m_arDevices[v19] = (AK::StreamMgr::IAkFileLocationResolver *)&v7->vfptr;
          ++v18->m_uNumDevices;
LABEL_35:
          v3 = *(_QWORD *)(v3 + 16) - 8i64;
        }
        while ( v3 != v4 );
        v1 = v30;
      }
      AK::SoundEngine::GetDefaultInitSettings((AkInitSettings *)result);
      AK::SoundEngine::GetDefaultPlatformInitSettings(&out_platformSettings);
      in_deviceSettings.uIOMemorySize = v1->defaultPoolSize;
      in_deviceSettings.pIOMemory = *(void **)&v1->maxNumPaths;
      in_deviceSettings.uIOMemoryAlignment = LODWORD(v1->defaultPoolLowMemoryThreshold);
      in_deviceSettings.ePoolAttributes = 0x8000;
      in_deviceSettings.threadProperties.nPriority = 1;
      v21 = v1->preparedEventPoolSize;
      if ( v21 > 0 )
      {
        in_deviceSettings.uGranularity = AK::MemoryMgr::CreatePool(0i64, v21, 0x400u, 1u, 0);
        hkaReferencePoseAnimation::getNumOriginalFrames(
          (hkEntitySelectorAll *)in_deviceSettings.uGranularity,
          (hkpEntity *)L"PreparedEventPool");
      }
      out_platformSettings.uLEngineDefaultPoolSize = v1->enginePoolSize;
      out_platformSettings.fLEngineDefaultPoolRatioThreshold = v1->lowerEngineLowMemoryThreshold;
      if ( (unsigned int)AK::SoundEngine::Init((AkInitSettings *)result, &out_platformSettings) == 1 )
      {
        AK::MotionEngine::RegisterMotionDevice(0, 0x196u, AkCreateRumblePlugin);
        AK::SoundEngine::RegisterPlugin(
          AkPluginTypeMotionSource,
          0,
          0x195u,
          AkCreateMotionGenerator,
          AkCreateMotionGeneratorParams);
        AK::SoundEngine::SetListenerPipeline(0, 1, 1);
        v32.fStreamingLookAheadRatio = v1->streamingLookAheadRatio;
        AK::MusicEngine::GetDefaultInitSettings(&v32);
        if ( AK::MusicEngine::Init(&v32) == 1 )
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
  UFG::WwiseDefaultIOHookDeferredBase **v0; // rbx
  UFG::WwiseFilePackageLowLevelIODeferred **v1; // rcx
  AK::SoundEngine *v2; // rcx
  UFG::WwiseFilePackageLowLevelIODeferred **v3; // r8
  unsigned int v4; // edx
  unsigned int v5; // edi
  UFG::WwiseDefaultIOHookDeferred **i; // rsi
  UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred> *v7; // rbx
  UFG::WwiseFilePackageLowLevelIODeferred *v8; // rcx
  AK::MemoryMgr *v9; // rcx

  AK::MotionEngine::RemovePlayerMotionDevice(0, 0, 0x196u);
  v0 = (UFG::WwiseDefaultIOHookDeferredBase **)UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p;
  v1 = &UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p[UFG::WwiseInterface::sm_WwiseLowLevelIODevices.size];
  if ( UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p != v1 )
  {
    do
    {
      UFG::WwiseDefaultIOHookDeferredBase::KillAllTransfers(*v0);
      v1 = &UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p[UFG::WwiseInterface::sm_WwiseLowLevelIODevices.size];
      ++v0;
    }
    while ( v0 != (UFG::WwiseDefaultIOHookDeferredBase **)v1 );
  }
  while ( UFG::TiDo::sm_asyncFileCount > 0 )
    ;
  AK::MusicEngine::Term((AK::MusicEngine *)v1);
  if ( (unsigned __int8)AK::SoundEngine::IsInitialized() )
    AK::SoundEngine::Term(v2);
  v3 = UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p;
  v4 = UFG::WwiseInterface::sm_WwiseLowLevelIODevices.size;
  v5 = 0;
  for ( i = (UFG::WwiseDefaultIOHookDeferred **)UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p;
        i != (UFG::WwiseDefaultIOHookDeferred **)&UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p[UFG::WwiseInterface::sm_WwiseLowLevelIODevices.size];
        v3 = UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p )
  {
    v7 = (UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred> *)*i;
    UFG::WwiseDefaultIOHookDeferred::Term(*i);
    UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred>::UnloadAllFilePackages(v7);
    v7->m_packages.m_pFirst = 0i64;
    v4 = UFG::WwiseInterface::sm_WwiseLowLevelIODevices.size;
  }
  if ( v4 )
  {
    do
    {
      v8 = v3[v5];
      if ( v8 )
      {
        v8->vfptr->__vecDelDtor((AK::StreamMgr::IAkFileLocationResolver *)&v8->vfptr, 1u);
        v3 = UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p;
        v4 = UFG::WwiseInterface::sm_WwiseLowLevelIODevices.size;
      }
      ++v5;
    }
    while ( v5 < v4 );
  }
  v9 = (AK::MemoryMgr *)AK::IAkStreamMgr::m_pStreamMgr;
  if ( AK::IAkStreamMgr::m_pStreamMgr )
    ((void (*)(void))AK::IAkStreamMgr::m_pStreamMgr->vfptr->Destroy)();
  AK::MemoryMgr::Term(v9);
}

// File Line: 778
// RVA: 0x14A7A0
void __fastcall UFG::WwiseInterface::PopulateExternalSourcesInfo(UFG::AudioEventExternalSourceInfo *inInfo, AkExternalSourceInfo **outInfo)
{
  AkExternalSourceInfo **v2; // rsi
  UFG::AudioEventExternalSourceInfo *v3; // rbx
  unsigned int v4; // edi
  unsigned __int64 v5; // rax
  char *v6; // rax
  unsigned int v7; // ecx
  int v8; // er8
  _QWORD *v9; // rdx
  unsigned int *v10; // r9
  signed __int64 v11; // r8

  v2 = outInfo;
  v3 = inInfo;
  v4 = inInfo->m_numExternals;
  v5 = 32i64 * inInfo->m_numExternals;
  if ( !is_mul_ok(inInfo->m_numExternals, 0x20ui64) )
    v5 = -1i64;
  v6 = UFG::qMalloc(v5, "WwiseInterface::AkExternalSourceInfo", 0i64);
  v7 = 0;
  if ( v6 )
  {
    v8 = v4 - 1;
    if ( (signed int)(v4 - 1) >= 0 )
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
  *v2 = (AkExternalSourceInfo *)v6;
  if ( v3->m_numExternals )
  {
    v10 = (unsigned int *)(v6 + 28);
    do
    {
      v11 = v7;
      *(v10 - 6) = v3->m_externals.p[v11].m_codecID;
      *(v10 - 7) = v3->m_externals.p[v11].m_externalSourceCookie;
      *v10 = v3->m_externals.p[v11].m_fileId;
      v10 += 8;
      ++v7;
    }
    while ( v7 < v3->m_numExternals );
  }
}

// File Line: 959
// RVA: 0x14C5A0
bool __fastcall UFG::WwiseInterface::SetWwiseSwitch(unsigned int switchId, unsigned int typeId, unsigned __int64 objectId)
{
  unsigned __int64 v3; // rbp
  unsigned int v4; // edi
  unsigned int v5; // esi
  AKRESULT v6; // ebx

  v3 = objectId;
  v4 = typeId;
  v5 = switchId;
  v6 = 2;
  if ( (unsigned __int8)AK::SoundEngine::IsInitialized() && v5 && v4 && !UFG::WwiseInterface::smShuttingDown )
    v6 = AK::SoundEngine::SetSwitch(v5, v4, v3);
  return v6 == 1;
}

// File Line: 975
// RVA: 0x14C510
bool __fastcall UFG::WwiseInterface::SetWwiseState(unsigned int stateId, unsigned int modeId)
{
  unsigned int v2; // edi
  unsigned int v3; // esi
  AKRESULT v4; // ebx

  v2 = modeId;
  v3 = stateId;
  v4 = 2;
  if ( (unsigned __int8)AK::SoundEngine::IsInitialized() && v3 && v2 && !UFG::WwiseInterface::smShuttingDown )
    v4 = AK::SoundEngine::SetState(v3, v2);
  return v4 == 1;
}

// File Line: 993
// RVA: 0x14C440
bool __fastcall UFG::WwiseInterface::SetWwiseRtpcValue(unsigned int rtpcId, float value, unsigned __int64 objectId)
{
  unsigned __int64 v3; // rsi
  unsigned int v4; // edi
  AKRESULT v5; // ebx

  v3 = objectId;
  v4 = rtpcId;
  v5 = 2;
  if ( (unsigned __int8)AK::SoundEngine::IsInitialized() && v4 && !UFG::WwiseInterface::smShuttingDown )
    v5 = AK::SoundEngine::SetRTPCValue(v4, value, v3, 0, AkCurveInterpolation_Linear);
  return v5 == 1;
}

// File Line: 1009
// RVA: 0x14AAB0
__int64 __fastcall UFG::WwiseInterface::PostAudioEvent(unsigned int eventId, unsigned __int64 objectId, unsigned int flags, void (__fastcall *callbackFunc)(AkCallbackType, AkCallbackInfo *), void *pUserData)
{
  void (__fastcall *v5)(AkCallbackType, AkCallbackInfo *); // rsi
  unsigned int v6; // ebp
  unsigned __int64 v7; // r14
  unsigned int v8; // edi
  unsigned int v9; // ebx
  __int64 v10; // r13
  unsigned int v11; // ebx
  unsigned int v12; // edx
  UFG::AudioEventInfo *v13; // rcx

  v5 = callbackFunc;
  v6 = flags;
  v7 = objectId;
  v8 = eventId;
  v9 = 0;
  if ( UFG::WwiseInterface::smLoadScreen )
  {
    v10 = UFG::WwiseInterface::sm_AfterLoadEvents.size;
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
    v13 = &UFG::WwiseInterface::sm_AfterLoadEvents.p[v10];
    v13->eventId = v8;
    v13->objectId = v7;
    v13->flags = v6;
    v13->callbackFun = v5;
    v13->pUserData = pUserData;
    return 0i64;
  }
  if ( (unsigned __int8)AK::SoundEngine::IsInitialized() && v8 && !UFG::WwiseInterface::smShuttingDown )
  {
    if ( !UFG::TiDo::IsEventEnabled(UFG::TiDo::m_pInstance, v8) )
      return 0i64;
    v9 = (unsigned __int64)AK::SoundEngine::PostEvent(v8, v7, v6, v5, pUserData, 0, 0i64, 0);
  }
  return v9;
}

// File Line: 1291
// RVA: 0x148DA0
void __fastcall UFG::WwiseInterface::LocalWwiseOutput(AK::Monitor::ErrorCode in_eErrorCode, const wchar_t *in_pszError, AK::Monitor::ErrorLevel in_eErrorLevel, unsigned int in_playingID, unsigned __int64 in_gameObjID)
{
  AK::Monitor::ErrorLevel v5; // edi
  const wchar_t *v6; // rbx
  signed __int64 v7; // rax
  char v8; // cl
  const char *v9; // rcx
  UFG::qString result; // [rsp+28h] [rbp-30h]

  v5 = in_eErrorLevel;
  v6 = in_pszError;
  UFG::qStringLength(in_pszError);
  str[0] = *(_BYTE *)v6;
  v7 = 0i64;
  if ( str[0] )
  {
    do
    {
      if ( v7 >= 127 )
        break;
      v8 = v6[++v7];
      str[v7] = v8;
    }
    while ( v8 );
  }
  UFG::qString::FormatEx(&result, "Wwise Obj %u :", in_gameObjID);
  v9 = "AK Error: %u %s\n";
  if ( v5 != 2 )
    v9 = "AK Warning: %u %s\n";
  UFG::qPrintf(v9, in_gameObjID, str);
  UFG::qString::~qString(&result);
}

// File Line: 1320
// RVA: 0x146750
__int64 __fastcall UFG::WwiseInterface::GetStreamFileSize(unsigned int fileId)
{
  UFG::WwiseFilePackageLowLevelIODeferred **v1; // rbx
  unsigned int v2; // edi
  __int64 result; // rax
  int v4; // [rsp+20h] [rbp-28h]
  int v5; // [rsp+24h] [rbp-24h]
  char v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  v1 = UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p;
  v2 = fileId;
  v7 = -1;
  v6 = 0;
  v4 = 0;
  v5 = 4;
  if ( UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p == &UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p[UFG::WwiseInterface::sm_WwiseLowLevelIODevices.size] )
    return 0i64;
  while ( 1 )
  {
    result = ((__int64 (__fastcall *)(UFG::WwiseFilePackageLowLevelIODeferred *, _QWORD, int *))(*v1)->vfptr[1].Open)(
               *v1,
               v2,
               &v4);
    if ( result )
      break;
    ++v1;
    if ( v1 == &UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p[UFG::WwiseInterface::sm_WwiseLowLevelIODevices.size] )
      return 0i64;
  }
  return result;
}

// File Line: 1354
// RVA: 0x148AF0
char __fastcall UFG::WwiseInterface::LoadFilePackage(__int64 deviceName, const char *packageName, bool localized, bool dlc)
{
  int *v4; // rdi
  BOOL v5; // er14
  UFG::WwiseDefaultIOHookDeferredBase **v6; // rbx
  UFG::WwiseFilePackageLowLevelIODeferred **v7; // rsi
  int v8; // ebp
  UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred> *v9; // rdi
  const wchar_t *v10; // rax
  const wchar_t *v11; // rax
  UFG::qString result; // [rsp+20h] [rbp-98h]
  AkFileSystemFlags in_pFlags; // [rsp+48h] [rbp-70h]
  __int64 v15; // [rsp+68h] [rbp-50h]
  UFG::qString out_FullFilePath; // [rsp+70h] [rbp-48h]
  UFG::qSymbol v17; // [rsp+D8h] [rbp+20h]

  v15 = -2i64;
  v4 = (int *)deviceName;
  v5 = dlc != 0;
  UFG::qString::FormatEx(&result, "%s", packageName);
  v6 = (UFG::WwiseDefaultIOHookDeferredBase **)UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p;
  v7 = &UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p[UFG::WwiseInterface::sm_WwiseLowLevelIODevices.size];
  if ( UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p != v7 )
  {
    v8 = *v4;
    while ( 1 )
    {
      v9 = (UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred> *)*v6;
      if ( UFG::WwiseDefaultIOHookDeferredBase::GetName(*v6, &v17)->mUID == v8 )
        break;
      ++v6;
      if ( v6 == (UFG::WwiseDefaultIOHookDeferredBase **)v7 )
        goto LABEL_9;
    }
    UFG::qString::qString(&out_FullFilePath);
    in_pFlags.uCacheID = -1;
    *(_QWORD *)&in_pFlags.uCompanyID = 0i64;
    in_pFlags.bIsLanguageSpecific = 0;
    in_pFlags.pCustomParam = 0i64;
    v10 = UFG::qString::GetWideName(&result);
    UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred>::LoadFilePackage(
      v9,
      v10,
      &v17.mUID,
      (UFG::WwiseFilePackageType)v5);
    v11 = UFG::qString::GetWideName(&result);
    UFG::WwiseFileLocationBase::BuildFilePath(
      (UFG::WwiseFileLocationBase *)&v9->vfptr,
      v11,
      &in_pFlags,
      &out_FullFilePath);
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
  UFG::WwiseFilePackageLowLevelIODeferred **v1; // r14
  const char *i; // rbp
  int v3; // eax
  UFG::WwiseDefaultIOHookDeferred *v4; // r8
  UFG::TidoFilePackage *v5; // rcx
  UFG::TidoFilePackage *v6; // rdx
  UFG::TidoFilePackage *v7; // rbx
  AK::StreamMgr::IAkFileLocationResolverVtbl *v8; // rax
  int v9; // edi
  void *v10; // rsi

  v1 = UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p;
  for ( i = packageName;
        v1 != &UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p[UFG::WwiseInterface::sm_WwiseLowLevelIODevices.size];
        ++v1 )
  {
    v3 = UFG::qStringHash32(i, 0xFFFFFFFF);
    v4 = (UFG::WwiseDefaultIOHookDeferred *)*v1;
    v5 = 0i64;
    v6 = (*v1)->m_packages.m_pFirst;
    v7 = v6;
    if ( v6 )
    {
      while ( v7->m_uid != v3 )
      {
        v5 = v7;
        v7 = v7->pNextItem;
        if ( !v7 )
          goto LABEL_13;
      }
      v8 = (AK::StreamMgr::IAkFileLocationResolverVtbl *)v7->pNextItem;
      if ( v7 == v6 )
        v4[1].vfptr = v8;
      else
        v5->pNextItem = (UFG::TidoFilePackage *)v8;
      UFG::WwiseDefaultIOHookDeferred::Close(v4, &v7->m_hFile);
      v9 = v7->m_poolID;
      v10 = v7->m_pToRelease;
      v7->vfptr->__vecDelDtor(v7, 0);
      if ( v9 != -1 )
      {
        if ( v10 )
          AK::MemoryMgr::ReleaseBlock(v9, v10);
        AK::MemoryMgr::DestroyPool(v9);
      }
    }
LABEL_13:
    ;
  }
}

// File Line: 1429
// RVA: 0x14BD70
void __fastcall UFG::WwiseInterface::SetIOPaths(const char *basePath, const char *bankPath, const char *srcPath, const char *langPath, const char *DLCPath)
{
  UFG::WwiseFilePackageLowLevelIODeferred **v5; // rsi
  const char *v6; // r13
  const char *v7; // r15
  const char *v8; // r12
  const char *v9; // rdx
  const char *v10; // r14
  UFG::WwiseFilePackageLowLevelIODeferred *v11; // rdi
  UFG::TidoFilePackage *v12; // rbx
  const wchar_t *v13; // rax
  UFG::AudioFilePackageLUT::StringMap *v14; // rcx
  unsigned __int16 v15; // ax
  const char *v16; // [rsp+50h] [rbp+8h]

  v16 = basePath;
  v5 = UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p;
  v6 = bankPath;
  v7 = langPath;
  v8 = srcPath;
  v9 = basePath;
  if ( UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p != &UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p[UFG::WwiseInterface::sm_WwiseLowLevelIODevices.size] )
  {
    v10 = DLCPath;
    do
    {
      UFG::qString::Set(&(*v5)->m_WwiseBasePath, v9);
      UFG::qString::Set(&(*v5)->m_WwiseBankPath, v6);
      UFG::qString::Set(&(*v5)->m_WwiseSrcPath, v8);
      v11 = *v5;
      UFG::qString::Set(&(*v5)->m_WwiseLangPath, v7);
      v12 = v11->m_packages.m_pFirst;
      if ( v12 )
      {
        do
        {
          if ( v11->m_WwiseLangPath.mLength <= 0 )
          {
            v12->lut.m_curLangID = 0;
          }
          else
          {
            v13 = UFG::qString::GetWideName(&v11->m_WwiseLangPath);
            v14 = v12->lut.m_pLangMap;
            v12->lut.m_curLangID = 0;
            if ( v14 && v13 )
            {
              v15 = UFG::AudioFilePackageLUT::StringMap::GetID(v14, v13);
              if ( v15 )
                v12->lut.m_curLangID = v15;
            }
          }
          v12 = v12->pNextItem;
        }
        while ( v12 );
        v10 = DLCPath;
      }
      UFG::qString::Set(&(*v5)->m_WwiseDLCPath, v10);
      v9 = v16;
      ++v5;
    }
    while ( v5 != &UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p[UFG::WwiseInterface::sm_WwiseLowLevelIODevices.size] );
  }
}

// File Line: 1523
// RVA: 0x14A2A0
AkExternalSourceArray *__fastcall UFG::WwiseInterface::PlayEvent(UFG::AudioEvent *pEvent)
{
  AkExternalSourceInfo *in_pExternalSources; // rbx
  UFG::AudioEvent *in_pCookie; // rdi
  UFG::AudioEventExternalSourceInfo *v3; // rcx
  unsigned int in_cExternals; // eax
  AkExternalSourceArray *result; // rax
  unsigned int v6; // edi
  AkExternalSourceInfo *outInfo; // [rsp+50h] [rbp+8h]

  in_pExternalSources = 0i64;
  in_pCookie = pEvent;
  v3 = pEvent->m_externalInfo;
  in_cExternals = 0;
  outInfo = 0i64;
  if ( v3 && v3->m_numExternals > 0 )
  {
    UFG::WwiseInterface::PopulateExternalSourcesInfo(v3, &outInfo);
    in_pExternalSources = outInfo;
    in_cExternals = in_pCookie->m_externalInfo->m_numExternals;
  }
  result = AK::SoundEngine::PostEvent(
             in_pCookie->m_uEventId,
             (unsigned __int64)in_pCookie->m_pEntity,
             0x30005u,
             UFG::WwiseInterface::WwiseEndEventCallback,
             in_pCookie,
             in_cExternals,
             in_pExternalSources,
             0);
  v6 = (unsigned int)result;
  if ( in_pExternalSources )
  {
    operator delete[](in_pExternalSources);
    result = (AkExternalSourceArray *)v6;
  }
  return result;
}

// File Line: 1602
// RVA: 0x145120
AK::SoundEngine::DynamicSequence::Playlist *__fastcall UFG::WwiseInterface::Enqueue(UFG::AudioDialogEvent *pEvent, unsigned int nodeId, unsigned int msDelay)
{
  unsigned int v3; // er13
  unsigned int v4; // er15
  UFG::AudioDialogEvent *v5; // rsi
  AK::SoundEngine::DynamicSequence::Playlist *result; // rax
  unsigned int v7; // ebp
  AkArray<AK::SoundEngine::DynamicSequence::PlaylistItem,AK::SoundEngine::DynamicSequence::PlaylistItem const &,ArrayPoolDefault,4,AkArrayAllocatorDefault> *v8; // r14
  UFG::AudioEventExternalSourceInfo *v9; // rcx
  unsigned int v10; // ebx
  AkExternalSourceInfo *v11; // rdi
  unsigned int v12; // er12
  AK::SoundEngine::DynamicSequence::PlaylistItem *v13; // rax
  signed int v14; // esi
  AkExternalSourceInfo *outInfo; // [rsp+68h] [rbp+20h]

  v3 = msDelay;
  v4 = nodeId;
  v5 = pEvent;
  if ( !(unsigned __int8)AK::SoundEngine::IsInitialized() )
    return 0i64;
  v7 = v5->m_uPlayingId;
  result = AK::SoundEngine::DynamicSequence::LockPlaylist(v5->m_uPlayingId);
  v8 = (AkArray<AK::SoundEngine::DynamicSequence::PlaylistItem,AK::SoundEngine::DynamicSequence::PlaylistItem const &,ArrayPoolDefault,4,AkArrayAllocatorDefault> *)&result->m_pItems;
  if ( result )
  {
    v9 = v5->m_externalInfo;
    v10 = 0;
    outInfo = 0i64;
    v11 = 0i64;
    v12 = 0;
    if ( v9 && v9->m_numExternals > 0 )
    {
      UFG::WwiseInterface::PopulateExternalSourcesInfo(v9, &outInfo);
      v11 = outInfo;
      v12 = v5->m_externalInfo->m_numExternals;
    }
    v13 = (AK::SoundEngine::DynamicSequence::PlaylistItem *)AkArray<AK::SoundEngine::DynamicSequence::PlaylistItem,AK::SoundEngine::DynamicSequence::PlaylistItem const &,ArrayPoolDefault,4,AkArrayAllocatorDefault>::AddLast(v8);
    if ( v13 )
    {
      v13->audioNodeID = v4;
      v13->msDelay = v3;
      v13->pCustomInfo = 0i64;
      v14 = AK::SoundEngine::DynamicSequence::PlaylistItem::SetExternalSources(v13, v12, v11);
    }
    else
    {
      v14 = 2;
    }
    AK::SoundEngine::DynamicSequence::UnlockPlaylist(v7);
    if ( v11 )
      operator delete[](v11);
    if ( v14 == 1 )
      v10 = v4;
    result = (AK::SoundEngine::DynamicSequence::Playlist *)v10;
  }
  return result;
}

// File Line: 1639
// RVA: 0x1452A0
AK::SoundEngine::DynamicSequence::Playlist *__fastcall UFG::WwiseInterface::EnqueueExternal(unsigned int playingId, unsigned int nodeId, UFG::AudioEventExternalSourceInfo *info, unsigned int msDelay)
{
  unsigned int v4; // er13
  UFG::AudioEventExternalSourceInfo *v5; // rsi
  unsigned int v6; // er12
  unsigned int v7; // er14
  AK::SoundEngine::DynamicSequence::Playlist *result; // rax
  AkArray<AK::SoundEngine::DynamicSequence::PlaylistItem,AK::SoundEngine::DynamicSequence::PlaylistItem const &,ArrayPoolDefault,4,AkArrayAllocatorDefault> *v9; // rbp
  unsigned int v10; // ebx
  AkExternalSourceInfo *v11; // rdi
  unsigned int v12; // er15
  AK::SoundEngine::DynamicSequence::PlaylistItem *v13; // rax
  signed int v14; // esi
  AkExternalSourceInfo *outInfo; // [rsp+20h] [rbp-38h]

  v4 = msDelay;
  v5 = info;
  v6 = nodeId;
  v7 = playingId;
  if ( !(unsigned __int8)AK::SoundEngine::IsInitialized() )
    return 0i64;
  result = AK::SoundEngine::DynamicSequence::LockPlaylist(v7);
  v9 = (AkArray<AK::SoundEngine::DynamicSequence::PlaylistItem,AK::SoundEngine::DynamicSequence::PlaylistItem const &,ArrayPoolDefault,4,AkArrayAllocatorDefault> *)&result->m_pItems;
  if ( result )
  {
    v10 = 0;
    v11 = 0i64;
    outInfo = 0i64;
    v12 = 0;
    if ( v5->m_numExternals )
    {
      UFG::WwiseInterface::PopulateExternalSourcesInfo(v5, &outInfo);
      v12 = v5->m_numExternals;
      v11 = outInfo;
    }
    v13 = (AK::SoundEngine::DynamicSequence::PlaylistItem *)AkArray<AK::SoundEngine::DynamicSequence::PlaylistItem,AK::SoundEngine::DynamicSequence::PlaylistItem const &,ArrayPoolDefault,4,AkArrayAllocatorDefault>::AddLast(v9);
    if ( v13 )
    {
      v13->audioNodeID = v6;
      v13->msDelay = v4;
      v13->pCustomInfo = 0i64;
      v14 = AK::SoundEngine::DynamicSequence::PlaylistItem::SetExternalSources(v13, v12, v11);
    }
    else
    {
      v14 = 2;
    }
    AK::SoundEngine::DynamicSequence::UnlockPlaylist(v7);
    if ( v11 )
      operator delete[](v11);
    if ( v14 == 1 )
      v10 = v6;
    result = (AK::SoundEngine::DynamicSequence::Playlist *)v10;
  }
  return result;
}

// File Line: 1676
// RVA: 0x14E8E0
void __fastcall UFG::WwiseInterface::WwiseEndEventCallback(AkCallbackType in_eType, AkCallbackInfo *in_pCallbackInfo)
{
  AkCallbackInfo *v2; // rdi
  char v3; // al
  const char *v4; // rcx
  UFG::AudioEvent *v5; // rbx
  signed int v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // edx
  unsigned int v9; // ecx

  v2 = in_pCallbackInfo;
  if ( in_eType & 1 )
  {
    v3 = *((_BYTE *)in_pCallbackInfo->pCookie + 144);
    if ( v3 & 0x40 )
      *((_BYTE *)in_pCallbackInfo->pCookie + 144) = v3 | 1;
  }
  else if ( in_eType & 4 )
  {
    v4 = (const char *)in_pCallbackInfo[2].pCookie;
    v5 = (UFG::AudioEvent *)in_pCallbackInfo->pCookie;
    if ( v4 && *v4 == 108 && v4[1] == 101 && v4[2] == 110 && v4[3] == 58 )
    {
      v6 = atol(v4 + 4);
      *((_BYTE *)v5 + 144) |= 2u;
      v5->m_markerCallbackInfo.m_floatParameter = (float)v6 * 0.001;
    }
    else
    {
      v7 = UFG::qStringHashUpper32(v4, 0xFFFFFFFF);
      v8 = v2[1].gameObjID;
      v9 = HIDWORD(v2[1].gameObjID);
      *((_BYTE *)v5 + 144) |= 2u;
      v5->m_markerCallbackInfo.m_position = v9;
      v5->m_markerCallbackInfo.m_identifier = v8;
      v5->m_markerCallbackInfo.m_labelHash = v7;
      v5->m_markerCallbackInfo.m_intParameter = 0;
    }
  }
}

// File Line: 1724
// RVA: 0x14AC60
__int64 __fastcall UFG::WwiseInterface::PrepareMP3(const char *filename)
{
  const char *v1; // rbx
  char *v2; // rbx
  unsigned int v3; // eax
  unsigned __int8 v4; // bl
  UFG::qString v6; // [rsp+30h] [rbp-C8h]
  __int64 v7; // [rsp+58h] [rbp-A0h]
  UFG::qString result; // [rsp+60h] [rbp-98h]
  AkMP3BaseInfo out_info; // [rsp+88h] [rbp-70h]
  wchar_t dest; // [rsp+108h] [rbp+10h]
  _BYTE v11[6]; // [rsp+112h] [rbp+1Ah]
  AkMP3Tag out_pTag; // [rsp+318h] [rbp+220h]

  v7 = -2i64;
  v1 = filename;
  dest = 0;
  memset(v11, 0, 0x206ui64);
  UFG::qWideStringCopy(&dest, v1);
  UFG::qString::qString(&v6);
  UFG::qString::Set(
    &v6,
    (*UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p)->m_WwiseBasePath.mData,
    (*UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p)->m_WwiseBasePath.mLength,
    0i64,
    0);
  UFG::ConvertAkLpCtstrToChar(&result, &dest);
  if ( !(unsigned int)UFG::qString::StartsWith(&result, "\\", -1)
    && !(unsigned int)UFG::qString::EndsWith(&v6, "\\", -1) )
  {
    UFG::qString::operator+=(&v6, "\\");
  }
  v2 = result.mData;
  v3 = UFG::qStringLength(result.mData);
  UFG::qString::append(&v6, v2, v3);
  UFG::qString::~qString(&result);
  out_info.uNumChannels = 0;
  memset(&out_info.uSampleRate, 0, 0x7Aui64);
  out_pTag.wszAlbum[0] = 0;
  memset(&out_pTag.wszAlbum[1], 0, 0x1FEui64);
  memset(out_pTag.wszArtist, 0, 0x400ui64);
  if ( AkMP3InfoRead(v6.mData, &out_info, &out_pTag) )
  {
    AkMP3PrepareForPlayback(&dest, &out_info, (signed int)(float)((float)out_info.msDuration * 0.0), 0i64, 0i64);
    v4 = 1;
  }
  else
  {
    v4 = 0;
  }
  UFG::qString::~qString(&v6);
  return v4;
}

