// File Line: 95
// RVA: 0x14EF5D0
__int64 dynamic_initializer_for__ghXMLMetaDataCache__()
{
  ghXMLMetaDataCache.mCallback = 0i64;
  ghXMLMetaDataCache.mCallbackParam = 0i64;
  ghXMLMetaDataCache.mImpl = 0i64;
  *(_DWORD *)&ghXMLMetaDataCache.mFlags = 536870915;
  ghXMLMetaDataCache._mTargetState.mValue = 1;
  return atexit(dynamic_atexit_destructor_for__ghXMLMetaDataCache__);
}

// File Line: 101
// RVA: 0x40E470
void LoadXMLProgressionCache(void)
{
  UFG::qString v0; // [rsp+48h] [rbp-30h]

  if ( gCreateFinalBinDir )
  {
    UFG::qString::qString(&v0, "data\\global\\xmlcache\\XML_CacheList_MetaData.bin");
    UFG::DataStreamer::QueueStream(&ghXMLMetaDataCache, v0.mData, DATA_SECTION_STD, DEFAULT_PRIORITY, 7u, 0i64, 0i64);
    UFG::qString::~qString(&v0);
  }
}

// File Line: 118
// RVA: 0x40E1A0
void LoadGameInitializeParameters(void)
{
  UFG::qPropertySet *v0; // rbx
  UFG::qSymbol *v1; // rax
  float v2; // xmm7_4
  UFG::qSymbol *v3; // rax
  float v4; // xmm6_4
  UFG::qSymbol *v5; // rax
  float v6; // xmm0_4
  UFG::qSymbol *v7; // rax
  UFG::qSymbol *v8; // rax
  UFG::qSymbol *v9; // rax
  UFG::qSymbol result; // [rsp+50h] [rbp+8h]
  UFG::qSymbol v11; // [rsp+58h] [rbp+10h]

  UFG::qSymbol::create_from_string(&result, "config-GameInitializeParameters");
  v0 = UFG::PropertySetManager::GetPropertySet(&result);
  v1 = UFG::qSymbol::create_from_string(&v11, "ThrottleThresholdToWalk");
  v2 = *UFG::qPropertySet::Get<float>(v0, v1, DEPTH_RECURSE);
  v3 = UFG::qSymbol::create_from_string(&v11, "ThrottleThresholdToRun");
  v4 = *UFG::qPropertySet::Get<float>(v0, v3, DEPTH_RECURSE);
  v5 = UFG::qSymbol::create_from_string(&v11, "ThrottleThresholdDampingAmount");
  v6 = *UFG::qPropertySet::Get<float>(v0, v5, DEPTH_RECURSE);
  ReadControllerInputTrack::s_CharacterMovementParams.throttleThresholdToWalk = v2;
  ReadControllerInputTrack::s_CharacterMovementParams.throttleThresholdToRun = v4;
  ReadControllerInputTrack::s_CharacterMovementParams.throttleThresholdDampingAmount = v6;
  v7 = UFG::qSymbol::create_from_string(&v11, "DistanceToBeConsideredNear");
  UFG::TheAIParameters.m_DistanceToBeConsideredNear = *UFG::qPropertySet::Get<float>(v0, v7, DEPTH_RECURSE);
  v8 = UFG::qSymbol::create_from_string(&v11, "MinTimeForRangedAttackerToStayNearPlayer");
  UFG::TheAIParameters.m_MinTimeForRangedAttackerToStayNearPlayer = *UFG::qPropertySet::Get<float>(
                                                                       v0,
                                                                       v8,
                                                                       DEPTH_RECURSE);
  v9 = UFG::qSymbol::create_from_string(&v11, "MaxTimeForRangedAttackerToStayNearPlayer");
  UFG::TheAIParameters.m_MaxTimeForRangedAttackerToStayNearPlayer = *UFG::qPropertySet::Get<float>(
                                                                       v0,
                                                                       v9,
                                                                       DEPTH_RECURSE);
}

// File Line: 152
// RVA: 0x14EF630
__int64 UFG::_dynamic_initializer_for__mAsynchronousXMLLoadingCompleteLock__()
{
  UFG::qMutex::qMutex(&UFG::mAsynchronousXMLLoadingCompleteLock, &customWorldMapCaption);
  return atexit(UFG::_dynamic_atexit_destructor_for__mAsynchronousXMLLoadingCompleteLock__);
}

// File Line: 164
// RVA: 0x407F90
void __usercall UFG::AsyncXMLLoad(void *param@<rcx>, float a2@<xmm0>)
{
  UFG::ProgressionTracker *v2; // rax

  v2 = UFG::ProgressionTracker::Instance();
  UFG::ProgressionTracker::LoadGraph(v2, a2);
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::mAsynchronousXMLLoadingCompleteLock);
  UFG::mAsynchronousXMLLoadingComplete = 1;
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::mAsynchronousXMLLoadingCompleteLock);
}

// File Line: 173
// RVA: 0x410710
void __fastcall UFG::GameStateLoadGame::OnEnter(UFG::GameStateLoadGame *this, float fRealTimeDelta)
{
  UFG::GameStateLoadGame *v2; // rsi
  UFG *v3; // rcx
  UFG *v4; // rcx
  UFG::ProgressionTracker *v5; // rax
  UFG::GameSetup *v6; // rdi
  const char *v7; // rbx
  __int64 v8; // rax
  UFG::qSymbol *v9; // rbx
  UFG::GameStatTracker *v10; // rax
  UFG::TiDo *v11; // rax
  UFG::TiDo *v12; // rax
  UFG::qString v13; // [rsp+20h] [rbp-98h]
  __int64 v14; // [rsp+48h] [rbp-70h]
  UFG::qString v15; // [rsp+50h] [rbp-68h]
  UFG::qString result; // [rsp+78h] [rbp-40h]
  UFG::qWiseSymbol source; // [rsp+C0h] [rbp+8h]
  UFG::qString *v18; // [rsp+D0h] [rbp+18h]

  v14 = -2i64;
  v2 = this;
  UFG::UIHK_NISOverlay::SetCurtainStateCallbacks(
    UFG::LoadingLogic::OnCurtainsShown,
    UFG::LoadingLogic::OnCurtainsHidden);
  UFG::MemoryUtil_DumpUnmarked("LOAD_GAME OnEnter");
  UFG::MemoryUtil_MarkAllPools(v3);
  UFG::OpenSim(v4);
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::mAsynchronousXMLLoadingCompleteLock);
  UFG::mAsynchronousXMLLoadingComplete = 0;
  UFG::mAsynchronousXMLLoadingStarted = 0;
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::mAsynchronousXMLLoadingCompleteLock);
  UFG::SectionChooser::EnableStreamsUpdate(0);
  gbUseHotswapping = 0;
  UFG::HotSwapFileManager::SetEnabled(0);
  UFG::Metrics::msInstance.mSimTimeDeltaLocked = FLOAT_0_033333335;
  *(_QWORD *)UFG::Metrics::msFramesPerSecBuckets = 0i64;
  qword_14235C0D0 = 0i64;
  qword_14235C0D8 = 0i64;
  dword_14235C0E0 = 0;
  v2->mLoadStage = 0;
  v5 = UFG::ProgressionTracker::Instance();
  v6 = UFG::ProgressionTracker::GetGameSetup(v5);
  v7 = v2->mGameStateUserDataStr.mData;
  if ( *v7 && (unsigned int)UFG::qStringCompare(v2->mGameStateUserDataStr.mData, &customWorldMapCaption, -1) )
  {
    v18 = &v13;
    UFG::qString::qString(&v13, v7);
    ((void (__fastcall *)(UFG::GameSetup *, __int64))v6->vfptr->LoadConfig)(v6, v8);
    if ( v6->mDebugSaveGame[0] && (unsigned int)UFG::qStringCompareInsensitive(v6->mDebugSaveGame, "USER_SAVE", -1) )
    {
      UFG::qString::qString(&v13, v6->mProgressionFlowType);
      UFG::qString::qString(&v15, v6->mDebugSaveGame);
      UFG::qString::MakeLower(&v15);
      UFG::qString::FormatEx(&result, "default-savegames-debugmenu-%s-%s", v13.mData, v15.mData);
      v9 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&v18, result.mData);
      v10 = UFG::GameStatTracker::Instance();
      UFG::GameStatTracker::LoadPresetGame(v10, v9);
      UFG::qString::~qString(&result);
      UFG::qString::~qString(&v15);
      UFG::qString::~qString(&v13);
    }
    UFG::qString::Set(&v2->mGameStateUserDataStr, &customWorldMapCaption);
  }
  _((AMD_HD3D *)2);
  unk_14207B26D = 257;
  UFG::qWiseSymbol::create_from_string(&source, "loadstart");
  UFG::qWiseSymbol::create_from_string((UFG::qWiseSymbol *)&v18, "loadfinish");
  UFG::qWiseSymbol::operator=(&stru_14207B268, (UFG::qWiseSymbol *)&v18);
  if ( unk_14207B260 != 1 )
  {
    UFG::qWiseSymbol::operator=(&stru_14207B264, &source);
    if ( unk_14207B26C )
    {
      if ( unk_14207B260 && (unsigned __int8)UFG::TiDo::GetIsInstantiated() )
      {
        v11 = UFG::TiDo::GetInstance();
        v11->vfptr->LoadingGameEnd(v11, &stru_14207B268);
      }
      if ( unk_14207B26C )
      {
        UFG::qWiseSymbol::operator=(&stru_14207B264, &source);
        if ( (unsigned __int8)UFG::TiDo::GetIsInstantiated() )
        {
          v12 = UFG::TiDo::GetInstance();
          v12->vfptr->LoadingGameStart(v12, &stru_14207B264);
        }
      }
    }
    unk_14207B260 = 1;
  }
  UFG::UIHK_NISOverlay::ShowCurtains(0.0, 1);
  _((AMD_HD3D *)(unsigned int)v18);
  ((void (*)(void))UFG::UIScreenManager::s_instance->vfptr->update)();
  _(UFG::BigFileLogic::SYSTEM_GLOBAL);
  v2->mLoadStage = 4;
  _((AMD_HD3D *)source.mUID);
}

// File Line: 237
// RVA: 0x412490
void __fastcall UFG::GameStateLoadGame::OnUpdate(UFG::GameStateLoadGame *this, float fRealTimeDelta)
{
  UFG::GameStateLoadGame *v2; // rdi
  UFG::UIScreenTextureManager *v3; // rax
  bool v4; // al
  UFG::ProgressionTracker *v5; // rax
  UFG::GameSetup *v6; // rax
  bool v7; // bl
  UFG::qString *v8; // rax
  UFG::qString *v9; // rcx
  UFG::qString *v10; // rax
  UFG::TiDo *v11; // rax
  UFG *v12; // rcx
  UFG::qString *v13; // rax
  char *v14; // rbx
  UFG::CopSystem *v15; // rax
  UFG::qString *v16; // rax
  bool v17; // bl
  UFG::qStaticSymbol *v18; // rbx
  UFG::ProgressionTracker *v19; // rax
  UFG::qSymbol *v20; // rax
  UFG::UIGfxTranslator *v21; // rcx
  const char *v22; // rdx
  UFG::ProgressionTracker *v23; // rax
  UFG::qString v24; // [rsp+40h] [rbp-F8h]
  UFG::qString result; // [rsp+80h] [rbp-B8h]
  UFG::qString v26; // [rsp+A8h] [rbp-90h]
  UFG::qString v27; // [rsp+D0h] [rbp-68h]
  UFG::qString v28; // [rsp+F8h] [rbp-40h]
  UFG::qSymbol parentSetName; // [rsp+140h] [rbp+8h]
  UFG::qSymbol objName; // [rsp+150h] [rbp+18h]

  v2 = this;
  v3 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::Update(v3, fRealTimeDelta);
  ((void (*)(void))UFG::UIScreenManager::s_instance->vfptr->update)();
  switch ( v2->mLoadStage )
  {
    case 4:
      if ( UFG::Metrics::msInstance.mSimTimeScaleMax <= 1.0 )
      {
        UFG::Metrics::msInstance.mSimTimeScaleInGame = UFG::Metrics::msInstance.mSimTimeScaleMax;
        if ( UFG::Metrics::msInstance.mSimTimeScaleMax == 0.0 )
        {
          v4 = 1;
          goto LABEL_7;
        }
      }
      else
      {
        UFG::Metrics::msInstance.mSimTimeScaleInGame = 1.0;
      }
      v4 = 0;
LABEL_7:
      UFG::Metrics::msInstance.mSimPausedInGame = v4;
      UFG::Metrics::msInstance.mSimTimeDeltaStep = 0.0;
      v5 = UFG::ProgressionTracker::Instance();
      v6 = UFG::ProgressionTracker::GetGameSetup(v5);
      UFG::qString::Set(&gCurrentLocationDirectory, v6->mLocationDir);
      v7 = 0;
      if ( (unsigned int)UFG::BigFileLogic::GetBigFileMode(UFG::BigFileLogic::SYSTEM_GAMEPLAY, 0i64) == 2 )
        v7 = 1;
      if ( (unsigned int)UFG::BigFileLogic::GetBigFileMode(
                           UFG::BigFileLogic::SYSTEM_WORLD,
                           gCurrentLocationDirectory.mData) == 1 )
        v7 = 1;
      UFG::SectionChooser::SetToStreamGameplayFromWorldBigFile(v7);
      UFG::BigFileLogic::MountSystemBigFile(UFG::BigFileLogic::SYSTEM_WORLD, gCurrentLocationDirectory.mData, 0i64);
      if ( !gForceLowRes )
        UFG::BigFileLogic::MountSystemBigFile(UFG::BigFileLogic::SYSTEM_WORLD, gCurrentLocationDirectory.mData, "HD");
      if ( !(unsigned int)UFG::BigFileLogic::GetBigFileMode(
                            UFG::BigFileLogic::SYSTEM_WORLD,
                            gCurrentLocationDirectory.mData) )
        UFG::BigFileLogic::SetSystemBigFileEnabled(UFG::BigFileLogic::SYSTEM_BOOT, gCurrentLocationDirectory.mData, 0);
      UFG::qString::qString(&v24);
      if ( v7 )
      {
        v8 = UFG::qString::FormatEx(&result, "data\\gameplay\\%s\\uniqueuids.bin", gCurrentLocationDirectory.mData);
        UFG::qString::Set(&v24, v8->mData, v8->mLength, 0i64, 0);
        v9 = &result;
      }
      else
      {
        v10 = UFG::qString::FormatEx(&v27, "world\\%s\\uniqueuids.bin", gCurrentLocationDirectory.mData);
        UFG::qString::Set(&v24, v10->mData, v10->mLength, 0i64, 0);
        v9 = &v27;
      }
      UFG::qString::~qString(v9);
      UFG::StreamResourceLoader::LoadResourceFile(v24.mData, UFG::gMainMemoryPool, 0, 0i64, 0i64, 0i64);
      v2->mLoadStage = 5;
      UFG::qString::~qString(&v24);
      return;
    case 5:
      v2->mLoadStage = 7;
      QueueLoadRigs();
      v2->mLoadStage = 8;
      return;
    case 8:
      if ( (unsigned __int8)UFG::TiDo::GetIsInstantiated() )
      {
        v11 = UFG::TiDo::GetInstance();
        v11->vfptr->LoadAudio(v11, gCurrentLocationDirectory.mData);
      }
      UFG::PedSpawnManager::OnGameEnter(UFG::gpPedSpawnManager);
      v2->mLoadStage = 9;
      return;
    case 9:
      if ( UFG::DataStreamer::IsStalled(0i64, 0) || !UFG::DataStreamer::IsBusy(0i64, 0) )
      {
        UFG::SkookumMgr::StartScene(v2->mInitialPass);
        UFG::SkookumMgr::InvokeOnLocationChange();
        UFG::qSymbol::create_from_string(&objName, "PlayerOne_Havok");
        UFG::qSymbol::create_from_string(&parentSetName, "object-physical-character-player");
        UFG::SpawnInfoInterface::SpawnObject(&objName, &parentSetName, 0, 0i64, 0i64, 0i64);
        UFG::CreateCameraObjects(v12);
        LoadGameInitializeParameters();
        v2->mLoadStage = 10;
      }
      return;
    case 0xA:
      v13 = UFG::qString::FormatEx(&v26, "Data\\CheckedIn\\Common\\Data\\World\\%s", gCurrentLocationDirectory.mData);
      v14 = gCurrentLocationDirectory.mData;
      UFG::qString::Set(&stru_1423AA4D0, v13->mData);
      UFG::qString::Set(&stru_1423AA4A8, v14);
      UFG::qString::~qString(&v26);
      UFG::RenderStageTerrain::Startup(UFG::RenderWorld::msStageTerrain);
      v2->mLoadStage = 11;
      return;
    case 0xB:
      UFG::SkookumMgr::InvokeOnProjectInit();
      v15 = UFG::CopSystem::Instance();
      ((void (__fastcall *)(UFG::CopSystem *))v15->vfptr[1].__vecDelDtor)(v15);
      v16 = UFG::qString::FormatEx(&v28, "Data\\World\\%s\\AISidewalkGraph", gCurrentLocationDirectory.mData);
      UFG::AISidewalkGraph::SetAIGraphDirectory(v16);
      UFG::qString::~qString(&v28);
      UnloadXMLCache();
      LoadXMLProgressionCache();
      v2->mLoadStage = 12;
      return;
    case 0xC:
      if ( UFG::DataStreamer::IsStalled(0i64, 0) || !UFG::DataStreamer::IsBusy(0i64, 0) )
      {
        if ( !UFG::mAsynchronousXMLLoadingStarted )
        {
          UFG::qThread::qThread((UFG::qThread *)&v24);
          UFG::qThread::Start((UFG::qThread *)&v24, (void (__fastcall *)(void *))UFG::AsyncXMLLoad, 0i64);
          UFG::mAsynchronousXMLLoadingStarted = 1;
          _((AMD_HD3D *)&v24);
        }
        UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::mAsynchronousXMLLoadingCompleteLock);
        v17 = UFG::mAsynchronousXMLLoadingComplete;
        UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::mAsynchronousXMLLoadingCompleteLock);
        if ( v17 )
        {
          UFG::DataStreamer::ReleaseStream(&ghXMLMetaDataCache);
          UFG::SectionChooser::Initialize(gCurrentLocationDirectory.mData);
          v2->mLoadStage = 13;
        }
      }
      return;
    case 0xD:
      if ( UFG::DataStreamer::IsStalled(0i64, 0) || !UFG::DataStreamer::IsBusy(0i64, 0) )
      {
        UFG::UIScreenManagerBase::queuePopAllScreens((UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr);
        UFG::UIGfxTranslator::unloadDictionary(UFG::UIScreenManager::s_instance->m_translator, "GameplayAct1");
        UFG::UIGfxTranslator::unloadDictionary(UFG::UIScreenManager::s_instance->m_translator, "GameplayAct2");
        UFG::UIGfxTranslator::unloadDictionary(UFG::UIScreenManager::s_instance->m_translator, "GameplayAct3");
        UFG::UIGfxTranslator::unloadDictionary(UFG::UIScreenManager::s_instance->m_translator, "GameplayDLCCommon");
        UFG::UIGfxTranslator::unloadDictionary(UFG::UIScreenManager::s_instance->m_translator, "GameplayDLCNinNP");
        UFG::UIGfxTranslator::unloadDictionary(UFG::UIScreenManager::s_instance->m_translator, "GameplayDLCCNY");
        UFG::UIGfxTranslator::loadDictionary(UFG::UIScreenManager::s_instance->m_translator, "Gameplay");
        v18 = UFG::ProgressionTracker::GetDefaultFlow();
        v19 = UFG::ProgressionTracker::Instance();
        v20 = UFG::ProgressionTracker::GetActiveFlow(v19);
        v21 = UFG::UIScreenManager::s_instance->m_translator;
        if ( v20->mUID == v18->mUID )
        {
          UFG::UIGfxTranslator::loadDictionary(v21, "GameplayAct1");
          UFG::UIGfxTranslator::loadDictionary(UFG::UIScreenManager::s_instance->m_translator, "GameplayAct2");
          v22 = "GameplayAct3";
        }
        else
        {
          UFG::UIGfxTranslator::loadDictionary(v21, "GameplayDLCCommon");
          UFG::UIGfxTranslator::loadDictionary(UFG::UIScreenManager::s_instance->m_translator, "GameplayDLCNinNP");
          v22 = "GameplayDLCCNY";
        }
        UFG::UIGfxTranslator::loadDictionary(UFG::UIScreenManager::s_instance->m_translator, v22);
        v2->mLoadStage = 14;
      }
      return;
    case 0xE:
      v23 = UFG::ProgressionTracker::Instance();
      UFG::ProgressionTracker::BindProgressionStage(v23);
      v2->mLoadStage = 15;
      return;
    default:
      return;
  }
}

// File Line: 509
// RVA: 0x410E40
void __fastcall UFG::GameStateLoadGame::OnExit(UFG::GameStateLoadGame *this, float fRealTimeDelta)
{
  UFG::GameStateLoadGame *v2; // rbx

  v2 = this;
  UFG::AudioTriggerRegion::sm_interiorTransitionCount = 0;
  UFG::AudioTriggerRegion::sm_rainDrawOverride = 0;
  ((void (__fastcall *)(UFG::TiDo *, signed __int64))UFG::TiDo::m_pInstance->vfptr[1].Close)(
    UFG::TiDo::m_pInstance,
    4i64);
  UFG::Metrics::msInstance.mSimTimeDeltaLocked = FLOAT_N1_0;
  ((void (__fastcall *)(UFG::GameStateLoadGame *, signed __int64))v2->vfptr->ModeSet)(v2, 1i64);
  UFG::BigFileLogic::SetSystemBigFileEnabled(UFG::BigFileLogic::SYSTEM_BOOT, 0i64, 0);
  UFG::PhysicsSystem::CalculateWorldBoundaries((UFG::PhysicsSystem *)UFG::BasePhysicsSystem::mInstance);
}

// File Line: 531
// RVA: 0x411D90
void __fastcall UFG::GameStateUnloadGame::OnPreUpdate(UFG::GameStateUnloadGame *this, float deltaSeconds)
{
  PoseTaskSubmission::BeginFrame();
}

// File Line: 536
// RVA: 0x411590
void __fastcall UFG::GameStateLoadGame::OnPostUpdate(UFG::GameStateLoadGame *this, float fRealTimeDelta)
{
  UFG::ObjectResourceManager *v2; // rax
  UFG::PartDatabase *v3; // rax
  UFG *v4; // rcx
  UFG *v5; // rcx
  AMD_HD3D *v6; // rcx
  AMD_HD3D *v7; // rcx
  AnimationDataBase *v8; // rax
  UFG::WebSystem *v9; // rax

  v2 = UFG::ObjectResourceManager::Instance();
  UFG::ObjectResourceManager::Update(v2, 0.0);
  v3 = UFG::PartDatabase::Instance();
  UFG::PartDatabase::Update(v3, 0.0);
  ((void (*)(void))UFG::gInputSystem->vfptr->Update)();
  CheckForConsoleInput(v4);
  UFG::qFileService(v5);
  _(v6);
  UFG::DataStreamer::Service(fRealTimeDelta);
  _(v7);
  Render::StreamingLoopProcessQueuedOperations(1, 0);
  v8 = AnimationDataBase::GetInstance();
  AnimationDataBase::UpdatePrioritySystem(v8);
  v9 = UFG::WebSystem::Instance();
  UFG::WebSystem::Update(v9, fRealTimeDelta);
  UFG::EventDispatcher::DispatchAllQueuedEvents(&UFG::EventDispatcher::mInstance);
}

