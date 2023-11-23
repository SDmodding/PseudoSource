// File Line: 87
// RVA: 0x14EF4E0
__int64 UFG::_dynamic_initializer_for__gLoadingLogic__()
{
  _((AMD_HD3D *)0xFFFFFFFFi64);
  stru_14207B268.mUID = -1;
  _((AMD_HD3D *)0xFFFFFFFFi64);
  word_14207B26C = 0;
  byte_14207B26E = 0;
  qword_14207B270 = 0i64;
  UFG::qString::qString(&stru_14207B278);
  dword_14207B230 = UFG::qRandom(9u, (unsigned int *)&UFG::qDefaultSeed);
  UFG::StreamerMetrics::SetDBGFileOpReadCB((void (__fastcall *)(float, float, void *, const char *))UFG::OnFileRead);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gLoadingLogic__);
}

// File Line: 101
// RVA: 0x404D50
void __fastcall UFG::LoadingScreenFileRead::LoadingScreenFileRead(UFG::LoadingScreenFileRead *this)
{
  this->mPrev = this;
  this->mNext = this;
  this->mCategory = CategoryData;
  UFG::qString::qString(&this->mFilename);
  this->mDuration = 0.0;
}

// File Line: 126
// RVA: 0x14EF570
__int64 UFG::_dynamic_initializer_for__gLoadingScreenSessions__()
{
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gLoadingScreenSessions__);
}

// File Line: 144
// RVA: 0x411050
void __fastcall UFG::OnFileRead(
        float fStartTime,
        float fDuration,
        UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *fileOpCallbackData,
        const char *filename)
{
  UFG::allocator::free_link *v6; // rax
  __int64 v7; // rax
  __int64 v8; // rdi
  UFG::qString *v9; // rax
  UFG::qString *FilenameWithoutExtension; // rax
  UFG::qString *v11; // rax
  UFG::qList<UFG::LoadingScreenFileRead,UFG::LoadingScreenFileRead,1,0> *p_mFileReads; // rcx
  UFG::qNode<UFG::LoadingScreenFileRead,UFG::LoadingScreenFileRead> *mPrev; // rax
  UFG::allocator::free_link *v14; // rax
  __int64 v15; // rax
  __int64 v16; // rbx
  UFG::qList<UFG::LoadingScreenFileRead,UFG::LoadingScreenFileRead,1,0> *v17; // rcx
  UFG::qNode<UFG::LoadingScreenFileRead,UFG::LoadingScreenFileRead> *v18; // rax
  UFG::StreamFileWrapper::DebugInfo text; // [rsp+40h] [rbp-C8h] BYREF
  UFG::qString v20; // [rsp+78h] [rbp-90h] BYREF
  UFG::qString v21; // [rsp+A0h] [rbp-68h] BYREF
  UFG::qString result; // [rsp+C8h] [rbp-40h] BYREF

  if ( UFG::gTrackLoadingLogic && UFG::gCurrentLoadingScreenSession )
  {
    UFG::qString::qString(&text.mFilename);
    if ( (unsigned __int8)UFG::StreamFileWrapper::DBGGetInfoFromFileOpParam(fileOpCallbackData, &text)
      && text.mFilename.mData )
    {
      if ( !UFG::qStringFindInsensitive(text.mFilename.mData, ".temp.bin") )
      {
        v6 = UFG::qMalloc(0x48ui64, "LoadingScreenFileRead", 0x800ui64);
        if ( v6 )
        {
          UFG::LoadingScreenFileRead::LoadingScreenFileRead((UFG::LoadingScreenFileRead *)v6);
          v8 = v7;
        }
        else
        {
          v8 = 0i64;
        }
        *(float *)(v8 + 64) = fDuration;
        UFG::qString::qString(&v21, &text.mFilename);
        FilenameWithoutExtension = UFG::qString::GetFilenameWithoutExtension(v9, &result);
        v11 = UFG::qString::GetFilenameWithoutExtension(FilenameWithoutExtension, &v20);
        UFG::qString::Set((UFG::qString *)(v8 + 24), v11->mData, v11->mLength, 0i64, 0);
        UFG::qString::~qString(&v20);
        UFG::qString::~qString(&result);
        UFG::qString::~qString(&v21);
        *(_DWORD *)(v8 + 16) = UFG::BandwidthHistory::GetCategoryFromFilename(text.mFilename.mData);
        p_mFileReads = &UFG::gCurrentLoadingScreenSession->mFileReads;
        mPrev = UFG::gCurrentLoadingScreenSession->mFileReads.mNode.mPrev;
        mPrev->mNext = (UFG::qNode<UFG::LoadingScreenFileRead,UFG::LoadingScreenFileRead> *)v8;
        *(_QWORD *)v8 = mPrev;
        *(_QWORD *)(v8 + 8) = p_mFileReads;
        p_mFileReads->mNode.mPrev = (UFG::qNode<UFG::LoadingScreenFileRead,UFG::LoadingScreenFileRead> *)v8;
LABEL_15:
        UFG::gCurrentLoadingScreenSession->mEndTime = UFG::qGetTicks();
      }
    }
    else if ( !UFG::qStringFindInsensitive(filename, ".temp.bin") )
    {
      v14 = UFG::qMalloc(0x48ui64, "LoadingScreenFileRead", 0x800ui64);
      if ( v14 )
      {
        UFG::LoadingScreenFileRead::LoadingScreenFileRead((UFG::LoadingScreenFileRead *)v14);
        v16 = v15;
      }
      else
      {
        v16 = 0i64;
      }
      *(float *)(v16 + 64) = fDuration;
      UFG::qString::Set((UFG::qString *)(v16 + 24), filename);
      *(_DWORD *)(v16 + 16) = UFG::BandwidthHistory::GetCategoryFromFilename(*(const char **)(v16 + 48));
      v17 = &UFG::gCurrentLoadingScreenSession->mFileReads;
      v18 = UFG::gCurrentLoadingScreenSession->mFileReads.mNode.mPrev;
      v18->mNext = (UFG::qNode<UFG::LoadingScreenFileRead,UFG::LoadingScreenFileRead> *)v16;
      *(_QWORD *)v16 = v18;
      *(_QWORD *)(v16 + 8) = v17;
      v17->mNode.mPrev = (UFG::qNode<UFG::LoadingScreenFileRead,UFG::LoadingScreenFileRead> *)v16;
      goto LABEL_15;
    }
    UFG::qString::~qString(&text.mFilename);
  }
}

// File Line: 232
// RVA: 0x411670
void __fastcall UFG::LoadingLogic::OnPostUpdate(UFG::LoadingLogic *this, float fRealTimeDelta)
{
  UFG::TiDo *Instance; // rax
  UFG *v3; // rcx
  UFG::ObjectResourceManager *v4; // rax
  UFG::UIScreenTextureManager *v5; // rax
  UFG *v6; // rcx
  AMD_HD3D *v7; // rcx
  AMD_HD3D *v8; // rcx
  AnimationDataBase *v9; // rax
  bool v10; // bl
  UFG::qSymbol parentSetName; // [rsp+60h] [rbp+18h] BYREF
  UFG::qSymbol result; // [rsp+68h] [rbp+20h] BYREF

  Instance = UFG::TiDo::GetInstance();
  ((void (__fastcall *)(UFG::TiDo *))Instance->vfptr->UpdateFrame)(Instance);
  ((void (__fastcall *)(UFG::UIScreenManager *))UFG::UIScreenManager::s_instance->vfptr->update)(UFG::UIScreenManager::s_instance);
  UFG::UpdateSim(0.0, 0i64);
  UFG::RenderWorld::UpdateViews(fRealTimeDelta);
  ((void (__fastcall *)(UFG::BasePhysicsSystem *))UFG::BasePhysicsSystem::mInstance->vfptr->PreFrameUpdate)(UFG::BasePhysicsSystem::mInstance);
  UFG::BasePhysicsSystem::StartAsyncRayCasts(UFG::BasePhysicsSystem::mInstance);
  UFG::BasePhysicsSystem::WaitForAsyncRayCastCompletion(UFG::BasePhysicsSystem::mInstance);
  UFG::BasePhysicsSystem::DispatchAsyncRayCastResultCallbacks(UFG::BasePhysicsSystem::mInstance);
  ((void (__fastcall *)(UFG::InputSystem *))UFG::gInputSystem->vfptr->Update)(UFG::gInputSystem);
  CheckForConsoleInput(v3);
  v4 = UFG::ObjectResourceManager::Instance();
  UFG::ObjectResourceManager::FlushResources(v4, 0);
  v5 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::Update(v5, fRealTimeDelta);
  UFG::qFileService(v6);
  _(v7);
  _(v8);
  UFG::DataStreamer::Service(fRealTimeDelta);
  Render::StreamingLoopProcessQueuedOperations(1, 0);
  v9 = AnimationDataBase::GetInstance();
  AnimationDataBase::UpdatePrioritySystem(v9);
  UFG::IncrementalActivateManager::Flush();
  ADeferFunc::invoke_deferred();
  UFG::EventDispatcher::DispatchAllQueuedEvents(&UFG::EventDispatcher::mInstance);
  v10 = UFG::GetLocalPlayer() != 0i64;
  UFG::Simulation::DestroyQueuedSimObjects(&UFG::gSim);
  if ( v10 && !UFG::GetLocalPlayer() )
  {
    UFG::qSymbol::create_from_string(&result, "PlayerOne_Havok");
    UFG::qSymbol::create_from_string(&parentSetName, "object-physical-character-player");
    UFG::SpawnInfoInterface::SpawnObject(&result, &parentSetName, UnReferenced, 0i64, 0i64, 0i64);
    UFG::SkookumMgr::InvokeWorldCoroutine(&qSymbol__on_change_player, 0i64);
  }
}

// File Line: 316
// RVA: 0x416690
void __fastcall UFG::LoadingLogic::SetForceLoadScreenOn(UFG::LoadingLogic *this)
{
  *(_WORD *)&this->mForceLoadTypeToLoadScreen = 257;
}

// File Line: 322
// RVA: 0x4165F0
void __fastcall UFG::LoadingLogic::SetAllowLoadScreen(UFG::LoadingLogic *this, bool allow)
{
  this->mAllowLoadScreen = allow;
}

// File Line: 358
// RVA: 0x416720
void __fastcall UFG::LoadingLogic::SetLoadLengthHint(UFG::LoadingLogic *this, signed int estimatedBytesRemaining)
{
  float mRunningBandwidthBytesPerSecond; // xmm1_4
  float v4; // xmm6_4
  unsigned __int64 Ticks; // rax
  float v6; // xmm0_4
  bool v7; // cf

  if ( this->mIsLoadScreenUp )
  {
    mRunningBandwidthBytesPerSecond = this->mRunningBandwidthBytesPerSecond;
    if ( mRunningBandwidthBytesPerSecond <= 0.0 )
    {
      *(_WORD *)&this->mForceLoadTypeToLoadScreen = 257;
    }
    else
    {
      this->mPredictedBytesRemaining = estimatedBytesRemaining;
      v4 = (float)estimatedBytesRemaining / mRunningBandwidthBytesPerSecond;
      Ticks = UFG::qGetTicks();
      v6 = UFG::qGetTickTime(this->mLoadStartTime, Ticks) + v4;
      v7 = v6 < this->mTimeBeforeSpinner;
      this->mPredictedLoadTime = v6;
      if ( !v7 && this->mLoadType != LoadScreen )
        UFG::LoadingLogic::SelectLoadingScreenType(this);
    }
  }
}

// File Line: 380
// RVA: 0x418470
void __fastcall UFG::LoadingLogic::UpdateLoadTimers(UFG::LoadingLogic *this, float fRealTimeDelta)
{
  unsigned __int64 Ticks; // rax
  unsigned __int64 mLoadStartTime; // rcx
  float TickTime; // xmm7_4
  unsigned int LoadedBytes; // eax
  bool v7; // zf

  if ( this->mIsLoadScreenUp )
  {
    Ticks = UFG::qGetTicks();
    mLoadStartTime = this->mLoadStartTime;
    this->mLoadEndTime = Ticks;
    TickTime = UFG::qGetTickTime(mLoadStartTime, Ticks);
    if ( !(unsigned int)UFG::DataStreamer::GetQueuedBytes() )
      this->mCurrentLoadTimeWithoutQueue = fRealTimeDelta + this->mCurrentLoadTimeWithoutQueue;
    LoadedBytes = UFG::DataStreamer::GetLoadedBytes();
    v7 = this->mLoadType == LoadScreen;
    this->mTotalLoadBytes = LoadedBytes;
    if ( !v7 && this->mForceLoadTypeToLoadScreen )
      UFG::LoadingLogic::SelectLoadingScreenType(this);
    if ( TickTime > this->mTimeBeforeSpinner && this->mLoadType == BlackScreen )
    {
      this->mLoadType = Spinner;
      UFG::LoadingLogic::StartLoadScreen(this, 0, 0i64, 0);
    }
    if ( this->mClearPedsOnNextUpdate )
    {
      UFG::PedSpawnManager::DeletePedsFromDeactivatedRegions(UFG::gpPedSpawnManager);
      this->mClearPedsOnNextUpdate = 0;
    }
  }
}

// File Line: 413
// RVA: 0x416250
void __fastcall UFG::LoadingLogic::SelectLoadingScreenType(UFG::LoadingLogic *this)
{
  unsigned __int64 Ticks; // rax
  float TickTime; // xmm0_4
  float mPredictedLoadTime; // xmm1_4
  UFG::GameStatTracker *v5; // rax
  UFG::qString *Stat; // rax
  int mLength; // r8d
  UFG::GameStatTracker *v8; // rax
  UFG::GameStatTracker *v9; // rax
  unsigned int v10; // r8d
  char *mData; // rbx
  UFG::UIScreenTextureManager *v12; // rax

  Ticks = UFG::qGetTicks();
  TickTime = UFG::qGetTickTime(this->mLoadStartTime, Ticks);
  if ( this->mAllowLoadScreen )
  {
    if ( this->mForceLoadTypeToLoadScreen
      || (mPredictedLoadTime = this->mPredictedLoadTime, mPredictedLoadTime > this->mTimeBeforeLoadScreen)
      && (float)(mPredictedLoadTime - TickTime) > 1.0 )
    {
      this->mLoadType = LoadScreen;
    }
  }
  if ( this->mLoadType != LoadScreen )
    this->mLoadType = (this->mTimeBeforeSpinner < this->mPredictedLoadTime) + 1;
  if ( (unsigned __int8)UFG::UI::IsGamePaused() && this->mLoadType == LoadScreen )
    this->mLoadType = Spinner;
  if ( this->mLoadType == Spinner )
  {
    UFG::LoadingLogic::StartLoadScreen(this, 0, 0i64, 0);
  }
  else if ( this->mLoadType == LoadScreen )
  {
    UFG::qString::Set(&this->mLoadScreenTexturePack, &customCaption);
    v5 = UFG::GameStatTracker::Instance();
    Stat = UFG::GameStatTracker::GetStat(v5, LoadingScreenPriority0);
    mLength = Stat->mLength;
    if ( mLength
      || (v8 = UFG::GameStatTracker::Instance(),
          Stat = UFG::GameStatTracker::GetStat(v8, LoadingScreenPriority1),
          (mLength = Stat->mLength) != 0)
      || (v9 = UFG::GameStatTracker::Instance(),
          Stat = UFG::GameStatTracker::GetStat(v9, LoadingScreenPriority2),
          (mLength = Stat->mLength) != 0) )
    {
      UFG::qString::Set(&this->mLoadScreenTexturePack, Stat->mData, mLength, 0i64, 0);
    }
    if ( !this->mLoadScreenTexturePack.mLength )
    {
      v10 = (this->mLastGenericLoadingScreen + 1) % 9;
      this->mLastGenericLoadingScreen = v10;
      UFG::qString::Set(&this->mLoadScreenTexturePack, UFG::sGenericLoadingScreenList[v10]);
    }
    mData = this->mLoadScreenTexturePack.mData;
    v12 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::QueueLoadAndPush(v12, "Loading", mData);
    UFG::LoadingLogic::StartLoadScreen(this, 0, 0i64, 0);
  }
}

// File Line: 519
// RVA: 0x40DC50
char __fastcall UFG::LoadingLogic::IsComplete(UFG::LoadingLogic *this, char typeflags)
{
  UFG::StreamingMemory::DATA_TYPE *v2; // rdi
  int v3; // edx
  unsigned int v4; // esi
  char IsBusy; // bl
  char IsStalled; // bp
  char result; // al

  v2 = 0i64;
  v3 = typeflags & 7;
  v4 = 0;
  switch ( v3 )
  {
    case 4:
      v2 = eLocationDataTypes;
      v4 = 6;
      break;
    case 3:
      v2 = eTrueCrowdAnimationDataTypes;
      v4 = 3;
      break;
    case 7:
      v2 = eLocationTrueCrowdAnimationDataTypes;
      v4 = 9;
      break;
  }
  IsBusy = UFG::DataStreamer::IsBusy(v2, v4);
  IsStalled = UFG::DataStreamer::IsStalled(v2, v4);
  result = UFG::DataStreamer::IsInLoopCondition(v2, v4);
  if ( !IsBusy || IsStalled || result )
    return 1;
  return result;
}

// File Line: 553
// RVA: 0x417860
void __fastcall UFG::LoadingLogic::StartLoadScreen(
        UFG::LoadingLogic *this,
        char flags,
        Render::BackgroundImage *images,
        unsigned int numImages)
{
  unsigned int i; // ebp
  Render::BackgroundImage *mLoadingImages; // rbx
  UFG::UIScreenTextureManager *v10; // rax
  UFG::DataStreamer *v11; // rcx
  Render::LoadScreenParams pParams; // [rsp+30h] [rbp-48h] BYREF

  if ( !Render::IsLoadScreenRendering() )
  {
    this->mLoadingImages = images;
    this->mLoadingImageCount = numImages;
    for ( i = 0; i < this->mLoadingImageCount; ++i )
    {
      mLoadingImages = this->mLoadingImages;
      v10 = UFG::UIScreenTextureManager::Instance();
      UFG::UIScreenTextureManager::QueueTexturePackLoad(
        v10,
        mLoadingImages[i].mTexturePack,
        VERY_HIGH_PRIORITY,
        0i64,
        0i64);
    }
    pParams.mBackgroundImages = images;
    pParams.mBackgroundImageCount = numImages;
    pParams.mSpinnerPosX = FLOAT_0_88999999;
    pParams.mSpinnerPosY = FLOAT_0_87;
    pParams.mbThreadedRender = flags & 1;
    pParams.mDrawSpinner = (flags & 2) == 0;
    Render::StartLoadScreen(&pParams);
    UFG::DataStreamer::ResetLoopConditionDetection(v11);
  }
}

// File Line: 572
// RVA: 0x417970
void __fastcall UFG::LoadingLogic::StopLoadScreen(UFG::LoadingLogic *this, float fFadeOutTime)
{
  Render *v3; // rcx
  __int64 i; // rbp
  Render::BackgroundImage *mLoadingImages; // rbx
  UFG::UIScreenTextureManager *v6; // rax
  UFG::UIScreenTextureManager *v7; // rax

  if ( Render::IsLoadScreenRendering() )
  {
    Render::StopLoadScreen(v3);
    if ( fFadeOutTime > 0.0 )
      Render::FadeLoadScreen(fFadeOutTime);
    for ( i = 0i64; (unsigned int)i < this->mLoadingImageCount; i = (unsigned int)(i + 1) )
    {
      mLoadingImages = this->mLoadingImages;
      v6 = UFG::UIScreenTextureManager::Instance();
      UFG::UIScreenTextureManager::ReleaseTexturePack(v6, mLoadingImages[i].mTexturePack);
    }
    if ( this->mLoadingImageCount )
    {
      v7 = UFG::UIScreenTextureManager::Instance();
      UFG::UIScreenTextureManager::ForceFlush(v7);
    }
    this->mLoadingImages = 0i64;
    this->mLoadingImageCount = 0;
    _((AMD_HD3D *)1);
    UFG::StreamFileWrapper::SetQueueMode(QUEUE_MODE_FIFO);
  }
}

// File Line: 598
// RVA: 0x40D070
// attributes: thunk
bool __fastcall UFG::LoadingLogic::HasRequiredScreensFinished(UFG::LoadingLogic *this)
{
  return Render::HasMinLoadScreenTimeExpired();
}

// File Line: 603
// RVA: 0x40DCF0
_BOOL8 __fastcall UFG::LoadingLogic::IsLoadingScreenUp(UFG::LoadingLogic *this)
{
  return this->mIsLoadScreenUp;
}

// File Line: 613
// RVA: 0x410250
void __fastcall UFG::LoadingLogic::OnCurtainsShown()
{
  UFG::OSuiteDBLogger *v0; // rax
  UFG::LoadingScreenSession *v1; // rcx
  UFG::LoadingScreenSession *v2; // rax
  UFG::qNode<UFG::LoadingScreenSession,UFG::LoadingScreenSession> *mPrev; // rax
  UFG::TiDo *Instance; // rax
  ANTLR3_INPUT_STREAM_struct *v5; // rax
  UFG::DataStreamer *v6; // rcx
  UFG::DataStreamer *v7; // rcx

  if ( qword_14207B270 )
  {
    UFG::GameSlice::SetupTimeAndWeather(qword_14207B270, 1);
    qword_14207B270 = 0i64;
  }
  if ( !(_BYTE)word_14207B26C )
  {
    v0 = UFG::OSuiteDBLogger::Instance();
    UFG::OSuiteDBLogger::FlushIfTimeoutHasElapsed(v0);
    if ( (_S12_4 & 1) == 0 )
    {
      _S12_4 |= 1u;
      dword_1423E330C = UFG::gZoneSpawnsPerFrame;
    }
    UFG::gZoneSpawnsPerFrame = 1000000;
    UFG::StreamFileWrapper::SetSupressCaching_Loading(1);
    if ( UFG::gTrackLoadingLogic && !UFG::gCurrentLoadingScreenSession )
    {
      v2 = (UFG::LoadingScreenSession *)UFG::qMalloc(0x30ui64, "LoadingScreenSession", 0x800ui64);
      if ( v2 )
      {
        v2->mPrev = v2;
        v2->mNext = v2;
        v2->mStartTime = 0i64;
        v2->mEndTime = 0i64;
        v2->mFileReads.mNode.mPrev = &v2->mFileReads.mNode;
        v2->mFileReads.mNode.mNext = &v2->mFileReads.mNode;
      }
      else
      {
        v2 = 0i64;
      }
      UFG::gCurrentLoadingScreenSession = v2;
      v2->mStartTime = UFG::qGetTicks();
      v1 = UFG::gCurrentLoadingScreenSession;
      mPrev = UFG::gLoadingScreenSessions.mNode.mPrev;
      UFG::gLoadingScreenSessions.mNode.mPrev->mNext = UFG::gCurrentLoadingScreenSession;
      v1->mPrev = mPrev;
      v1->mNext = (UFG::qNode<UFG::LoadingScreenSession,UFG::LoadingScreenSession> *)&UFG::gLoadingScreenSessions;
      UFG::gLoadingScreenSessions.mNode.mPrev = v1;
    }
    if ( byte_14207B260 && UFG::TiDo::GetIsInstantiated() )
    {
      Instance = UFG::TiDo::GetInstance();
      Instance->vfptr->LoadingGameStart(Instance, &stru_14207B264);
    }
    UFG::UI::LockGameplayInput((UFG::UI *)v1);
    if ( !(unsigned __int8)UFG::UI::IsGamePaused() )
    {
      v5 = (ANTLR3_INPUT_STREAM_struct *)UFG::UIScreenTextureManager::Instance();
      UFG::UIScreenTextureManager::SetGameState(v5, 8u);
    }
    LOBYTE(word_14207B26C) = 1;
    unk_14207B22C = 0;
    unk_14207B238 = UFG::qGetTicks();
    unk_14207B248 = 0i64;
    unk_14207B250 = 0;
    UFG::DataStreamer::ResetLoadedBytes(v6);
    UFG::DataStreamer::ResetLoopConditionDetection(v7);
  }
  unk_14207B261 = 1;
}

// File Line: 660
// RVA: 0x410050
void __fastcall UFG::LoadingLogic::OnCurtainsHidden()
{
  int v0; // ecx
  UFG::LoadingScreenSession *i; // rax
  float TickTime; // xmm3_4
  UFG::qWiseSymbol *null; // rax
  UFG::TiDo *Instance; // rax
  UFG::qWiseSymbol *v5; // rax
  UFG::UI *v6; // rcx
  ANTLR3_INPUT_STREAM_struct *v7; // rax
  int v8; // eax

  if ( (_BYTE)word_14207B26C )
  {
    if ( UFG::gCurrentLoadingScreenSession )
    {
      UFG::gCurrentLoadingScreenSession->mEndTime = UFG::qGetTicks();
      v0 = 0;
      for ( i = (UFG::LoadingScreenSession *)UFG::gCurrentLoadingScreenSession->mFileReads.mNode.mNext;
            i != (UFG::LoadingScreenSession *)&UFG::gCurrentLoadingScreenSession->mFileReads;
            i = (UFG::LoadingScreenSession *)i->mNext )
      {
        ++v0;
      }
      unk_1423ED044 = v0;
    }
    UFG::gCurrentLoadingScreenSession = 0i64;
    UFG::StreamFileWrapper::SetSupressCaching_Loading(0);
    unk_14207B240 = UFG::qGetTicks();
    word_14207B26C = 0;
    byte_14207B26E = 0;
    dword_14207B234 = UFG::DataStreamer::GetLoadedBytes();
    if ( (unsigned int)dword_14207B234 > 0xA00000 )
    {
      TickTime = UFG::qGetTickTime(unk_14207B238, unk_14207B240);
      if ( TickTime > 0.0 )
      {
        if ( unk_14207B25C <= 0.0 )
          unk_14207B25C = (float)dword_14207B234 / TickTime;
        else
          unk_14207B25C = (float)((float)((float)dword_14207B234 / TickTime) * 0.19999999)
                        + (float)(unk_14207B25C * 0.80000001);
      }
    }
    if ( unk_14207B22C == 3 )
    {
      UFG::qString::Set(&stru_14207B278, &customCaption);
      UFG::UIScreenManagerBase::queuePopOverlay(UFG::UIScreenManager::s_instance, "Loading");
    }
    UFG::LoadingLogic::StopLoadScreen(&UFG::gLoadingLogic, 1.0);
    if ( byte_14207B260 && UFG::TiDo::GetIsInstantiated() )
    {
      null = UFG::qWiseSymbol::get_null();
      UFG::qWiseSymbol::operator=(&stru_14207B264, null);
      Instance = UFG::TiDo::GetInstance();
      Instance->vfptr->LoadingGameEnd(Instance, &stru_14207B268);
      v5 = UFG::qWiseSymbol::get_null();
      UFG::qWiseSymbol::operator=(&stru_14207B268, v5);
    }
    byte_14207B260 = 0;
    if ( !(unsigned __int8)UFG::UI::IsGamePaused() )
    {
      v7 = (ANTLR3_INPUT_STREAM_struct *)UFG::UIScreenTextureManager::Instance();
      UFG::UIScreenTextureManager::SetGameState(v7, 2u);
    }
    UFG::UI::UnlockGameplayInput(v6);
    if ( (_S12_4 & 1) != 0 )
    {
      v8 = dword_1423E330C;
    }
    else
    {
      _S12_4 |= 1u;
      v8 = UFG::gZoneSpawnsPerFrame;
      dword_1423E330C = UFG::gZoneSpawnsPerFrame;
    }
    UFG::gZoneSpawnsPerFrame = v8;
  }
}

