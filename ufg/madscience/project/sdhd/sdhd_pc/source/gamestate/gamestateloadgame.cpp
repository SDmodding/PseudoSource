// File Line: 95
// RVA: 0x14EF5D0
__int64 dynamic_initializer_for__ghXMLMetaDataCache__()
{
  ghXMLMetaDataCache.mCallback = 0i64;
  ghXMLMetaDataCache.mCallbackParam = 0i64;
  ghXMLMetaDataCache.mImpl = 0i64;
  *(_DWORD *)&ghXMLMetaDataCache.mFlags = 536870915;
  ghXMLMetaDataCache._mTargetState.mValue = 1;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__ghXMLMetaDataCache__);
}

// File Line: 101
// RVA: 0x40E470
void LoadXMLProgressionCache(void)
{
  UFG::qString v0; // [rsp+48h] [rbp-30h] BYREF

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
  UFG::qPropertySet *PropertySet; // rbx
  UFG::qArray<unsigned long,0> *v1; // rax
  float v2; // xmm7_4
  UFG::qArray<unsigned long,0> *v3; // rax
  float v4; // xmm6_4
  UFG::qArray<unsigned long,0> *v5; // rax
  float v6; // xmm0_4
  UFG::qArray<unsigned long,0> *v7; // rax
  UFG::qArray<unsigned long,0> *v8; // rax
  UFG::qArray<unsigned long,0> *v9; // rax
  UFG::qSymbol result; // [rsp+50h] [rbp+8h] BYREF
  UFG::qSymbol v11; // [rsp+58h] [rbp+10h] BYREF

  UFG::qSymbol::create_from_string(&result, "config-GameInitializeParameters");
  PropertySet = UFG::PropertySetManager::GetPropertySet(&result);
  v1 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&v11, "ThrottleThresholdToWalk");
  v2 = *UFG::qPropertySet::Get<float>(PropertySet, v1, DEPTH_RECURSE);
  v3 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&v11, "ThrottleThresholdToRun");
  v4 = *UFG::qPropertySet::Get<float>(PropertySet, v3, DEPTH_RECURSE);
  v5 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&v11, "ThrottleThresholdDampingAmount");
  v6 = *UFG::qPropertySet::Get<float>(PropertySet, v5, DEPTH_RECURSE);
  ReadControllerInputTrack::s_CharacterMovementParams.throttleThresholdToWalk = v2;
  ReadControllerInputTrack::s_CharacterMovementParams.throttleThresholdToRun = v4;
  ReadControllerInputTrack::s_CharacterMovementParams.throttleThresholdDampingAmount = v6;
  v7 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&v11, "DistanceToBeConsideredNear");
  UFG::TheAIParameters.m_DistanceToBeConsideredNear = *UFG::qPropertySet::Get<float>(PropertySet, v7, DEPTH_RECURSE);
  v8 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(
                                         &v11,
                                         "MinTimeForRangedAttackerToStayNearPlayer");
  UFG::TheAIParameters.m_MinTimeForRangedAttackerToStayNearPlayer = *UFG::qPropertySet::Get<float>(
                                                                       PropertySet,
                                                                       v8,
                                                                       DEPTH_RECURSE);
  v9 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(
                                         &v11,
                                         "MaxTimeForRangedAttackerToStayNearPlayer");
  UFG::TheAIParameters.m_MaxTimeForRangedAttackerToStayNearPlayer = *UFG::qPropertySet::Get<float>(
                                                                       PropertySet,
                                                                       v9,
                                                                       DEPTH_RECURSE);
}

// File Line: 152
// RVA: 0x14EF630
__int64 UFG::_dynamic_initializer_for__mAsynchronousXMLLoadingCompleteLock__()
{
  UFG::qMutex::qMutex(&UFG::mAsynchronousXMLLoadingCompleteLock, &customCaption);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__mAsynchronousXMLLoadingCompleteLock__);
}

// File Line: 164
// RVA: 0x407F90
void __fastcall UFG::AsyncXMLLoad(void *param)
{
  float v1; // xmm0_4
  UFG::ProgressionTracker *v2; // rax

  v2 = UFG::ProgressionTracker::Instance();
  UFG::ProgressionTracker::LoadGraph(v2, v1);
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::mAsynchronousXMLLoadingCompleteLock);
  UFG::mAsynchronousXMLLoadingComplete = 1;
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::mAsynchronousXMLLoadingCompleteLock);
}

// File Line: 173
// RVA: 0x410710
void __fastcall UFG::GameStateLoadGame::OnEnter(UFG::GameStateLoadGame *this, float fRealTimeDelta)
{
  UFG *v3; // rcx
  UFG *v4; // rcx
  UFG::ProgressionTracker *v5; // rax
  UFG::GameSetup *GameSetup; // rdi
  char *mData; // rbx
  __int64 v8; // rax
  UFG::qSymbol *v9; // rbx
  UFG::GameStatTracker *v10; // rax
  UFG::TiDo *Instance; // rax
  UFG::TiDo *v12; // rax
  UFG::qString v13; // [rsp+20h] [rbp-98h] BYREF
  __int64 v14; // [rsp+48h] [rbp-70h]
  UFG::qString v15; // [rsp+50h] [rbp-68h] BYREF
  UFG::qString result; // [rsp+78h] [rbp-40h] BYREF
  UFG::qWiseSymbol source; // [rsp+C0h] [rbp+8h] BYREF
  UFG::qString *v18; // [rsp+D0h] [rbp+18h] BYREF

  v14 = -2i64;
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
  this->mLoadStage = eLS_INIT;
  v5 = UFG::ProgressionTracker::Instance();
  GameSetup = UFG::ProgressionTracker::GetGameSetup(v5);
  mData = this->mGameStateUserDataStr.mData;
  if ( *mData && (unsigned int)UFG::qStringCompare(this->mGameStateUserDataStr.mData, &customCaption, -1) )
  {
    v18 = &v13;
    UFG::qString::qString(&v13, mData);
    ((void (__fastcall *)(UFG::GameSetup *, __int64))GameSetup->vfptr->LoadConfig)(GameSetup, v8);
    if ( GameSetup->mDebugSaveGame[0]
      && (unsigned int)UFG::qStringCompareInsensitive(GameSetup->mDebugSaveGame, "USER_SAVE", -1) )
    {
      UFG::qString::qString(&v13, GameSetup->mProgressionFlowType);
      UFG::qString::qString(&v15, GameSetup->mDebugSaveGame);
      UFG::qString::MakeLower(&v15);
      UFG::qString::FormatEx(&result, "default-savegames-debugmenu-%s-%s", v13.mData, v15.mData);
      v9 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&v18, result.mData);
      v10 = UFG::GameStatTracker::Instance();
      UFG::GameStatTracker::LoadPresetGame(v10, v9);
      UFG::qString::~qString(&result);
      UFG::qString::~qString(&v15);
      UFG::qString::~qString(&v13);
    }
    UFG::qString::Set(&this->mGameStateUserDataStr, &customCaption);
  }
  _((AMD_HD3D *)2);
  *(__int16 *)((char *)&word_14207B26C + 1) = 257;
  UFG::qWiseSymbol::create_from_string(&source, "loadstart");
  UFG::qWiseSymbol::create_from_string((UFG::qWiseSymbol *)&v18, "loadfinish");
  UFG::qWiseSymbol::operator=(&stru_14207B268, (UFG::qWiseSymbol *)&v18);
  if ( byte_14207B260 != 1 )
  {
    UFG::qWiseSymbol::operator=(&stru_14207B264, &source);
    if ( (_BYTE)word_14207B26C )
    {
      if ( byte_14207B260 && UFG::TiDo::GetIsInstantiated() )
      {
        Instance = UFG::TiDo::GetInstance();
        Instance->vfptr->LoadingGameEnd(Instance, &stru_14207B268);
      }
      if ( (_BYTE)word_14207B26C )
      {
        UFG::qWiseSymbol::operator=(&stru_14207B264, &source);
        if ( UFG::TiDo::GetIsInstantiated() )
        {
          v12 = UFG::TiDo::GetInstance();
          v12->vfptr->LoadingGameStart(v12, &stru_14207B264);
        }
      }
    }
    byte_14207B260 = 1;
  }
  UFG::UIHK_NISOverlay::ShowCurtains(0.0, 1);
  _((AMD_HD3D *)(unsigned int)v18);
  ((void (__fastcall *)(UFG::UIScreenManager *))UFG::UIScreenManager::s_instance->vfptr->update)(UFG::UIScreenManager::s_instance);
  _(UFG::BigFileLogic::SYSTEM_GLOBAL);
  this->mLoadStage = 4;
  _((AMD_HD3D *)source.mUID);
}

// File Line: 237
// RVA: 0x412490
void __fastcall UFG::GameStateLoadGame::OnUpdate(UFG::GameStateLoadGame *this, float fRealTimeDelta)
{
  UFG::UIScreenTextureManager *v3; // rax
  bool v4; // al
  UFG::ProgressionTracker *v5; // rax
  UFG::GameSetup *GameSetup; // rax
  bool v7; // bl
  UFG::qString *v8; // rax
  UFG::qString *p_result; // rcx
  UFG::qString *v10; // rax
  UFG::TiDo *Instance; // rax
  UFG *v12; // rcx
  UFG::qString *v13; // rax
  char *mData; // rbx
  UFG::CopSystem *v15; // rax
  UFG::qString *v16; // rax
  bool v17; // bl
  UFG::qStaticSymbol *DefaultFlow; // rbx
  UFG::ProgressionTracker *v19; // rax
  UFG::qSymbol *ActiveFlow; // rax
  UFG::UIGfxTranslator *m_translator; // rcx
  const char *v22; // rdx
  UFG::ProgressionTracker *v23; // rax
  UFG::qThread v24; // [rsp+40h] [rbp-F8h] BYREF
  UFG::qString result; // [rsp+80h] [rbp-B8h] BYREF
  UFG::qString v26; // [rsp+A8h] [rbp-90h] BYREF
  UFG::qString v27; // [rsp+D0h] [rbp-68h] BYREF
  UFG::qString v28; // [rsp+F8h] [rbp-40h] BYREF
  UFG::qSymbol parentSetName; // [rsp+140h] [rbp+8h] BYREF
  UFG::qSymbol objName; // [rsp+150h] [rbp+18h] BYREF

  v3 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::Update(v3, fRealTimeDelta);
  ((void (__fastcall *)(UFG::UIScreenManager *))UFG::UIScreenManager::s_instance->vfptr->update)(UFG::UIScreenManager::s_instance);
  switch ( this->mLoadStage )
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
      GameSetup = UFG::ProgressionTracker::GetGameSetup(v5);
      UFG::qString::Set(&gCurrentLocationDirectory, GameSetup->mLocationDir);
      v7 = (unsigned int)UFG::BigFileLogic::GetBigFileMode(UFG::BigFileLogic::SYSTEM_GAMEPLAY, 0i64) == 2;
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
      UFG::qString::qString((UFG::qString *)&v24);
      if ( v7 )
      {
        v8 = UFG::qString::FormatEx(&result, "data\\gameplay\\%s\\uniqueuids.bin", gCurrentLocationDirectory.mData);
        UFG::qString::Set((UFG::qString *)&v24, v8->mData, v8->mLength, 0i64, 0);
        p_result = &result;
      }
      else
      {
        v10 = UFG::qString::FormatEx(&v27, "world\\%s\\uniqueuids.bin", gCurrentLocationDirectory.mData);
        UFG::qString::Set((UFG::qString *)&v24, v10->mData, v10->mLength, 0i64, 0);
        p_result = &v27;
      }
      UFG::qString::~qString(p_result);
      UFG::StreamResourceLoader::LoadResourceFile(
        *(const char **)&v24.mStacksize,
        UFG::gMainMemoryPool,
        0,
        0i64,
        0i64,
        0i64);
      this->mLoadStage = 5;
      UFG::qString::~qString((UFG::qString *)&v24);
      return;
    case 5:
      this->mLoadStage = eLS_FINAL|eLS_PARENT|0x4;
      QueueLoadRigs();
      this->mLoadStage = 8;
      return;
    case 8:
      if ( UFG::TiDo::GetIsInstantiated() )
      {
        Instance = UFG::TiDo::GetInstance();
        Instance->vfptr->LoadAudio(Instance, gCurrentLocationDirectory.mData);
      }
      UFG::PedSpawnManager::OnGameEnter(UFG::gpPedSpawnManager);
      this->mLoadStage = 9;
      return;
    case 9:
      if ( UFG::DataStreamer::IsStalled(0i64, 0) || !UFG::DataStreamer::IsBusy(0i64, 0) )
      {
        UFG::SkookumMgr::StartScene(this->mInitialPass);
        UFG::SkookumMgr::InvokeOnLocationChange();
        UFG::qSymbol::create_from_string(&objName, "PlayerOne_Havok");
        UFG::qSymbol::create_from_string(&parentSetName, "object-physical-character-player");
        UFG::SpawnInfoInterface::SpawnObject(&objName, &parentSetName, UnReferenced, 0i64, 0i64, 0i64);
        UFG::CreateCameraObjects(v12);
        LoadGameInitializeParameters();
        this->mLoadStage = 10;
      }
      return;
    case 0xA:
      v13 = UFG::qString::FormatEx(&v26, "Data\\CheckedIn\\Common\\Data\\World\\%s", gCurrentLocationDirectory.mData);
      mData = gCurrentLocationDirectory.mData;
      UFG::qString::Set(&stru_1423AA4D0, v13->mData);
      UFG::qString::Set(&stru_1423AA4A8, mData);
      UFG::qString::~qString(&v26);
      UFG::RenderStageTerrain::Startup(UFG::RenderWorld::msStageTerrain);
      this->mLoadStage = eLS_FINAL|eLS_PARENT|0x8;
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
      this->mLoadStage = 12;
      return;
    case 0xC:
      if ( UFG::DataStreamer::IsStalled(0i64, 0) || !UFG::DataStreamer::IsBusy(0i64, 0) )
      {
        if ( !UFG::mAsynchronousXMLLoadingStarted )
        {
          UFG::qThread::qThread(&v24);
          UFG::qThread::Start(&v24, UFG::AsyncXMLLoad, 0i64);
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
          this->mLoadStage = 13;
        }
      }
      return;
    case 0xD:
      if ( UFG::DataStreamer::IsStalled(0i64, 0) || !UFG::DataStreamer::IsBusy(0i64, 0) )
      {
        UFG::UIScreenManagerBase::queuePopAllScreens(UFG::UIScreenManager::s_instance);
        UFG::UIGfxTranslator::unloadDictionary(UFG::UIScreenManager::s_instance->m_translator, "GameplayAct1");
        UFG::UIGfxTranslator::unloadDictionary(UFG::UIScreenManager::s_instance->m_translator, "GameplayAct2");
        UFG::UIGfxTranslator::unloadDictionary(UFG::UIScreenManager::s_instance->m_translator, "GameplayAct3");
        UFG::UIGfxTranslator::unloadDictionary(UFG::UIScreenManager::s_instance->m_translator, "GameplayDLCCommon");
        UFG::UIGfxTranslator::unloadDictionary(UFG::UIScreenManager::s_instance->m_translator, "GameplayDLCNinNP");
        UFG::UIGfxTranslator::unloadDictionary(UFG::UIScreenManager::s_instance->m_translator, "GameplayDLCCNY");
        UFG::UIGfxTranslator::loadDictionary(UFG::UIScreenManager::s_instance->m_translator, "Gameplay");
        DefaultFlow = UFG::ProgressionTracker::GetDefaultFlow();
        v19 = UFG::ProgressionTracker::Instance();
        ActiveFlow = UFG::ProgressionTracker::GetActiveFlow(v19);
        m_translator = UFG::UIScreenManager::s_instance->m_translator;
        if ( ActiveFlow->mUID == DefaultFlow->mUID )
        {
          UFG::UIGfxTranslator::loadDictionary(m_translator, "GameplayAct1");
          UFG::UIGfxTranslator::loadDictionary(UFG::UIScreenManager::s_instance->m_translator, "GameplayAct2");
          v22 = "GameplayAct3";
        }
        else
        {
          UFG::UIGfxTranslator::loadDictionary(m_translator, "GameplayDLCCommon");
          UFG::UIGfxTranslator::loadDictionary(UFG::UIScreenManager::s_instance->m_translator, "GameplayDLCNinNP");
          v22 = "GameplayDLCCNY";
        }
        UFG::UIGfxTranslator::loadDictionary(UFG::UIScreenManager::s_instance->m_translator, v22);
        this->mLoadStage = 14;
      }
      return;
    case 0xE:
      v23 = UFG::ProgressionTracker::Instance();
      UFG::ProgressionTracker::BindProgressionStage(v23);
      this->mLoadStage = 15;
      return;
    default:
      return;
  }
}

// File Line: 509
// RVA: 0x410E40
void __fastcall UFG::GameStateLoadGame::OnExit(UFG::GameStateLoadGame *this, float fRealTimeDelta)
{
  UFG::AudioTriggerRegion::sm_interiorTransitionCount = 0;
  UFG::AudioTriggerRegion::sm_rainDrawOverride = 0;
  ((void (__fastcall *)(UFG::TiDo *, __int64))UFG::TiDo::m_pInstance->vfptr[1].Close)(UFG::TiDo::m_pInstance, 4i64);
  UFG::Metrics::msInstance.mSimTimeDeltaLocked = FLOAT_N1_0;
  ((void (__fastcall *)(UFG::GameStateLoadGame *, __int64))this->vfptr->ModeSet)(this, 1i64);
  UFG::BigFileLogic::SetSystemBigFileEnabled(UFG::BigFileLogic::SYSTEM_BOOT, 0i64, 0);
  UFG::PhysicsSystem::CalculateWorldBoundaries((UFG::PhysicsSystem *)UFG::BasePhysicsSystem::mInstance);
}

// File Line: 531
// RVA: 0x411D90
// attributes: thunk
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
  AnimationDataBase *Instance; // rax
  UFG::WebSystem *v9; // rax

  v2 = UFG::ObjectResourceManager::Instance();
  UFG::ObjectResourceManager::Update(v2, 0.0);
  v3 = UFG::PartDatabase::Instance();
  UFG::PartDatabase::Update(v3, 0.0);
  ((void (__fastcall *)(UFG::InputSystem *))UFG::gInputSystem->vfptr->Update)(UFG::gInputSystem);
  CheckForConsoleInput(v4);
  UFG::qFileService(v5);
  _(v6);
  UFG::DataStreamer::Service(fRealTimeDelta);
  _(v7);
  Render::StreamingLoopProcessQueuedOperations(1, 0);
  Instance = AnimationDataBase::GetInstance();
  AnimationDataBase::UpdatePrioritySystem(Instance);
  v9 = UFG::WebSystem::Instance();
  UFG::WebSystem::Update(v9, fRealTimeDelta);
  UFG::EventDispatcher::DispatchAllQueuedEvents(&UFG::EventDispatcher::mInstance);
}

