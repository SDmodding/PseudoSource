// File Line: 87
// RVA: 0x14EF4E0
__int64 UFG::_dynamic_initializer_for__gLoadingLogic__()
{
  _((AMD_HD3D *)0xFFFFFFFFi64);
  stru_14207B268.mUID = -1;
  _((AMD_HD3D *)0xFFFFFFFFi64);
  unk_14207B26C = 0;
  unk_14207B26E = 0;
  qword_14207B270 = 0i64;
  UFG::qString::qString(&stru_14207B278);
  unk_14207B230 = UFG::qRandom(9, &UFG::qDefaultSeed);
  UFG::StreamerMetrics::SetDBGFileOpReadCB(UFG::OnFileRead);
  return atexit(UFG::_dynamic_atexit_destructor_for__gLoadingLogic__);
}

// File Line: 101
// RVA: 0x404D50
void __fastcall UFG::LoadingScreenFileRead::LoadingScreenFileRead(UFG::LoadingScreenFileRead *this)
{
  UFG::LoadingScreenFileRead *v1; // rbx

  v1 = this;
  this->mPrev = (UFG::qNode<UFG::LoadingScreenFileRead,UFG::LoadingScreenFileRead> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::LoadingScreenFileRead,UFG::LoadingScreenFileRead> *)&this->mPrev;
  this->mCategory = 7;
  UFG::qString::qString(&this->mFilename);
  v1->mDuration = 0.0;
}

// File Line: 126
// RVA: 0x14EF570
__int64 UFG::_dynamic_initializer_for__gLoadingScreenSessions__()
{
  return atexit(UFG::_dynamic_atexit_destructor_for__gLoadingScreenSessions__);
}

// File Line: 144
// RVA: 0x411050
void __fastcall UFG::OnFileRead(float fStartTime, float fDuration, void *fileOpCallbackData, const char *filename)
{
  const char *v4; // rdi
  void *v5; // rbx
  UFG::allocator::free_link *v6; // rax
  __int64 v7; // rax
  __int64 v8; // rdi
  UFG::qString *v9; // rax
  UFG::qString *v10; // rax
  UFG::qString *v11; // rax
  UFG::qList<UFG::LoadingScreenFileRead,UFG::LoadingScreenFileRead,1,0> *v12; // rcx
  UFG::qNode<UFG::LoadingScreenFileRead,UFG::LoadingScreenFileRead> *v13; // rax
  UFG::allocator::free_link *v14; // rax
  __int64 v15; // rax
  __int64 v16; // rbx
  UFG::qList<UFG::LoadingScreenFileRead,UFG::LoadingScreenFileRead,1,0> *v17; // rcx
  UFG::qNode<UFG::LoadingScreenFileRead,UFG::LoadingScreenFileRead> *v18; // rax
  UFG::qString text; // [rsp+40h] [rbp-C8h]
  UFG::qString v20; // [rsp+78h] [rbp-90h]
  UFG::qString v21; // [rsp+A0h] [rbp-68h]
  UFG::qString result; // [rsp+C8h] [rbp-40h]

  v4 = filename;
  v5 = fileOpCallbackData;
  if ( UFG::gTrackLoadingLogic && UFG::gCurrentLoadingScreenSession )
  {
    UFG::qString::qString(&text);
    if ( (unsigned __int8)UFG::StreamFileWrapper::DBGGetInfoFromFileOpParam(
                            v5,
                            (UFG::StreamFileWrapper::DebugInfo *)&text)
      && text.mData )
    {
      if ( !UFG::qStringFindInsensitive(text.mData, ".temp.bin") )
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
        UFG::qString::qString(&v21, &text);
        v10 = UFG::qString::GetFilenameWithoutExtension(v9, &result);
        v11 = UFG::qString::GetFilenameWithoutExtension(v10, &v20);
        UFG::qString::Set((UFG::qString *)(v8 + 24), v11->mData, v11->mLength, 0i64, 0);
        UFG::qString::~qString(&v20);
        UFG::qString::~qString(&result);
        UFG::qString::~qString(&v21);
        *(_DWORD *)(v8 + 16) = UFG::BandwidthHistory::GetCategoryFromFilename(text.mData);
        v12 = &UFG::gCurrentLoadingScreenSession->mFileReads;
        v13 = UFG::gCurrentLoadingScreenSession->mFileReads.mNode.mPrev;
        v13->mNext = (UFG::qNode<UFG::LoadingScreenFileRead,UFG::LoadingScreenFileRead> *)v8;
        *(_QWORD *)v8 = v13;
        *(_QWORD *)(v8 + 8) = v12;
        v12->mNode.mPrev = (UFG::qNode<UFG::LoadingScreenFileRead,UFG::LoadingScreenFileRead> *)v8;
LABEL_15:
        UFG::gCurrentLoadingScreenSession->mEndTime = UFG::qGetTicks();
        goto LABEL_16;
      }
    }
    else if ( !UFG::qStringFindInsensitive(v4, ".temp.bin") )
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
      UFG::qString::Set((UFG::qString *)(v16 + 24), v4);
      *(_DWORD *)(v16 + 16) = UFG::BandwidthHistory::GetCategoryFromFilename(*(const char **)(v16 + 48));
      v17 = &UFG::gCurrentLoadingScreenSession->mFileReads;
      v18 = UFG::gCurrentLoadingScreenSession->mFileReads.mNode.mPrev;
      v18->mNext = (UFG::qNode<UFG::LoadingScreenFileRead,UFG::LoadingScreenFileRead> *)v16;
      *(_QWORD *)v16 = v18;
      *(_QWORD *)(v16 + 8) = v17;
      v17->mNode.mPrev = (UFG::qNode<UFG::LoadingScreenFileRead,UFG::LoadingScreenFileRead> *)v16;
      goto LABEL_15;
    }
LABEL_16:
    UFG::qString::~qString(&text);
  }
}

// File Line: 232
// RVA: 0x411670
void __fastcall UFG::LoadingLogic::OnPostUpdate(UFG::LoadingLogic *this, float fRealTimeDelta)
{
  UFG::TiDo *v2; // rax
  UFG *v3; // rcx
  UFG::ObjectResourceManager *v4; // rax
  UFG::UIScreenTextureManager *v5; // rax
  UFG *v6; // rcx
  AMD_HD3D *v7; // rcx
  AMD_HD3D *v8; // rcx
  AnimationDataBase *v9; // rax
  bool v10; // bl
  UFG::qSymbol parentSetName; // [rsp+60h] [rbp+18h]
  UFG::qSymbol result; // [rsp+68h] [rbp+20h]

  v2 = UFG::TiDo::GetInstance();
  ((void (__fastcall *)(UFG::TiDo *))v2->vfptr->UpdateFrame)(v2);
  ((void (*)(void))UFG::UIScreenManager::s_instance->vfptr->update)();
  UFG::UpdateSim(0.0, 0i64);
  UFG::RenderWorld::UpdateViews(fRealTimeDelta);
  ((void (*)(void))UFG::BasePhysicsSystem::mInstance->vfptr->PreFrameUpdate)();
  UFG::BasePhysicsSystem::StartAsyncRayCasts(UFG::BasePhysicsSystem::mInstance);
  UFG::BasePhysicsSystem::WaitForAsyncRayCastCompletion(UFG::BasePhysicsSystem::mInstance);
  UFG::BasePhysicsSystem::DispatchAsyncRayCastResultCallbacks(UFG::BasePhysicsSystem::mInstance);
  ((void (*)(void))UFG::gInputSystem->vfptr->Update)();
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
    UFG::SpawnInfoInterface::SpawnObject(&result, &parentSetName, 0, 0i64, 0i64, 0i64);
    UFG::SkookumMgr::InvokeWorldCoroutine((UFG::qSymbol *)&qSymbol__on_change_player.mUID, 0i64);
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
void __fastcall UFG::LoadingLogic::SetLoadLengthHint(UFG::LoadingLogic *this, unsigned int estimatedBytesRemaining)
{
  UFG::LoadingLogic *v2; // rbx
  float v3; // xmm1_4
  float v4; // xmm6_4
  unsigned __int64 v5; // rax
  float v6; // xmm0_4
  bool v7; // cf

  v2 = this;
  if ( this->mIsLoadScreenUp )
  {
    v3 = this->mRunningBandwidthBytesPerSecond;
    if ( v3 <= 0.0 )
    {
      *(_WORD *)&this->mForceLoadTypeToLoadScreen = 257;
    }
    else
    {
      this->mPredictedBytesRemaining = estimatedBytesRemaining;
      v4 = (float)(signed int)estimatedBytesRemaining / v3;
      v5 = UFG::qGetTicks();
      v6 = UFG::qGetTickTime(v2->mLoadStartTime, v5) + v4;
      v7 = v6 < v2->mTimeBeforeSpinner;
      v2->mPredictedLoadTime = v6;
      if ( !v7 && v2->mLoadType != 3 )
        UFG::LoadingLogic::SelectLoadingScreenType(v2);
    }
  }
}

// File Line: 380
// RVA: 0x418470
void __fastcall UFG::LoadingLogic::UpdateLoadTimers(UFG::LoadingLogic *this, float fRealTimeDelta)
{
  UFG::LoadingLogic *v2; // rbx
  unsigned __int64 v3; // rax
  unsigned __int64 v4; // rcx
  float v5; // xmm7_4
  unsigned int v6; // eax
  bool v7; // zf

  v2 = this;
  if ( this->mIsLoadScreenUp )
  {
    v3 = UFG::qGetTicks();
    v4 = v2->mLoadStartTime;
    v2->mLoadEndTime = v3;
    v5 = UFG::qGetTickTime(v4, v3);
    if ( !(unsigned int)UFG::DataStreamer::GetQueuedBytes() )
      v2->mCurrentLoadTimeWithoutQueue = fRealTimeDelta + v2->mCurrentLoadTimeWithoutQueue;
    v6 = UFG::DataStreamer::GetLoadedBytes();
    v7 = v2->mLoadType == 3;
    v2->mTotalLoadBytes = v6;
    if ( !v7 && v2->mForceLoadTypeToLoadScreen )
      UFG::LoadingLogic::SelectLoadingScreenType(v2);
    if ( v5 > v2->mTimeBeforeSpinner && v2->mLoadType == 1 )
    {
      v2->mLoadType = 2;
      UFG::LoadingLogic::StartLoadScreen(v2, 0, 0i64, 0);
    }
    if ( v2->mClearPedsOnNextUpdate )
    {
      UFG::PedSpawnManager::DeletePedsFromDeactivatedRegions(UFG::gpPedSpawnManager);
      v2->mClearPedsOnNextUpdate = 0;
    }
  }
}

// File Line: 413
// RVA: 0x416250
void __fastcall UFG::LoadingLogic::SelectLoadingScreenType(UFG::LoadingLogic *this)
{
  UFG::LoadingLogic *v1; // rdi
  unsigned __int64 v2; // rax
  float v3; // xmm0_4
  float v4; // xmm1_4
  UFG::GameStatTracker *v5; // rax
  UFG::qString *v6; // rax
  int v7; // er8
  UFG::GameStatTracker *v8; // rax
  UFG::GameStatTracker *v9; // rax
  unsigned int v10; // er8
  const char *v11; // rbx
  UFG::UIScreenTextureManager *v12; // rax

  v1 = this;
  v2 = UFG::qGetTicks();
  v3 = UFG::qGetTickTime(v1->mLoadStartTime, v2);
  if ( v1->mAllowLoadScreen )
  {
    if ( v1->mForceLoadTypeToLoadScreen
      || (v4 = v1->mPredictedLoadTime, v4 > v1->mTimeBeforeLoadScreen) && (float)(v4 - v3) > 1.0 )
    {
      v1->mLoadType = 3;
    }
  }
  if ( v1->mLoadType != 3 )
    v1->mLoadType = (v1->mTimeBeforeSpinner < v1->mPredictedLoadTime) + 1;
  if ( (unsigned __int8)UFG::UI::IsGamePaused() && v1->mLoadType == 3 )
    v1->mLoadType = 2;
  if ( v1->mLoadType == 2 )
  {
    UFG::LoadingLogic::StartLoadScreen(v1, 0, 0i64, 0);
  }
  else if ( v1->mLoadType == 3 )
  {
    UFG::qString::Set(&v1->mLoadScreenTexturePack, &customWorldMapCaption);
    v5 = UFG::GameStatTracker::Instance();
    v6 = UFG::GameStatTracker::GetStat(v5, LoadingScreenPriority0);
    v7 = v6->mLength;
    if ( v7
      || (v8 = UFG::GameStatTracker::Instance(),
          v6 = UFG::GameStatTracker::GetStat(v8, LoadingScreenPriority1),
          (v7 = v6->mLength) != 0)
      || (v9 = UFG::GameStatTracker::Instance(),
          v6 = UFG::GameStatTracker::GetStat(v9, LoadingScreenPriority2),
          (v7 = v6->mLength) != 0) )
    {
      UFG::qString::Set(&v1->mLoadScreenTexturePack, v6->mData, v7, 0i64, 0);
    }
    if ( !v1->mLoadScreenTexturePack.mLength )
    {
      v10 = (v1->mLastGenericLoadingScreen + 1) % 9;
      v1->mLastGenericLoadingScreen = v10;
      UFG::qString::Set(&v1->mLoadScreenTexturePack, UFG::sGenericLoadingScreenList[v10]);
    }
    v11 = v1->mLoadScreenTexturePack.mData;
    v12 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::QueueLoadAndPush(v12, "Loading", v11);
    UFG::LoadingLogic::StartLoadScreen(v1, 0, 0i64, 0);
  }
}

// File Line: 519
// RVA: 0x40DC50
char __fastcall UFG::LoadingLogic::IsComplete(UFG::LoadingLogic *this, unsigned int typeflags)
{
  UFG::StreamingMemory::DATA_TYPE *v2; // rdi
  unsigned int v3; // edx
  unsigned int v4; // esi
  char v5; // bl
  char v6; // bp
  char result; // al

  v2 = 0i64;
  v3 = typeflags & 7;
  v4 = 0;
  switch ( v3 )
  {
    case 4u:
      v2 = eLocationDataTypes;
      v4 = 6;
      break;
    case 3u:
      v2 = eTrueCrowdAnimationDataTypes;
      v4 = 3;
      break;
    case 7u:
      v2 = eLocationTrueCrowdAnimationDataTypes;
      v4 = 9;
      break;
  }
  v5 = UFG::DataStreamer::IsBusy(v2, v4);
  v6 = UFG::DataStreamer::IsStalled(v2, v4);
  result = UFG::DataStreamer::IsInLoopCondition(v2, v4);
  if ( !v5 || v6 || result )
    result = 1;
  return result;
}

// File Line: 553
// RVA: 0x417860
void __fastcall UFG::LoadingLogic::StartLoadScreen(UFG::LoadingLogic *this, unsigned int flags, Render::BackgroundImage *images, unsigned int numImages)
{
  unsigned int v4; // er15
  Render::BackgroundImage *v5; // r12
  unsigned int v6; // esi
  UFG::LoadingLogic *v7; // r14
  unsigned int v8; // ebp
  Render::BackgroundImage *v9; // rbx
  UFG::UIScreenTextureManager *v10; // rax
  UFG::DataStreamer *v11; // rcx
  Render::LoadScreenParams pParams; // [rsp+30h] [rbp-48h]

  v4 = numImages;
  v5 = images;
  v6 = flags;
  v7 = this;
  if ( !(unsigned int)Render::IsLoadScreenRendering() )
  {
    v7->mLoadingImages = v5;
    v7->mLoadingImageCount = v4;
    v8 = 0;
    if ( v4 )
    {
      do
      {
        v9 = v7->mLoadingImages;
        v10 = UFG::UIScreenTextureManager::Instance();
        UFG::UIScreenTextureManager::QueueTexturePackLoad(v10, v9[v8++].mTexturePack, VERY_HIGH_PRIORITY, 0i64, 0i64);
      }
      while ( v8 < v7->mLoadingImageCount );
    }
    pParams.mBackgroundImages = v5;
    pParams.mBackgroundImageCount = v4;
    pParams.mSpinnerPosX = FLOAT_0_88999999;
    pParams.mSpinnerPosY = FLOAT_0_87;
    pParams.mbThreadedRender = v6 & 1;
    pParams.mDrawSpinner = ~(unsigned __int8)(v6 >> 1) & 1;
    Render::StartLoadScreen(&pParams);
    UFG::DataStreamer::ResetLoopConditionDetection(v11);
  }
}

// File Line: 572
// RVA: 0x417970
void __fastcall UFG::LoadingLogic::StopLoadScreen(UFG::LoadingLogic *this, float fFadeOutTime)
{
  UFG::LoadingLogic *v2; // rsi
  Render *v3; // rcx
  __int64 v4; // rbp
  Render::BackgroundImage *v5; // rbx
  UFG::UIScreenTextureManager *v6; // rax
  UFG::UIScreenTextureManager *v7; // rax

  v2 = this;
  if ( (unsigned int)Render::IsLoadScreenRendering() )
  {
    Render::StopLoadScreen(v3);
    if ( fFadeOutTime > 0.0 )
      Render::FadeLoadScreen(fFadeOutTime);
    v4 = 0i64;
    if ( v2->mLoadingImageCount )
    {
      do
      {
        v5 = v2->mLoadingImages;
        v6 = UFG::UIScreenTextureManager::Instance();
        UFG::UIScreenTextureManager::ReleaseTexturePack(v6, v5[v4].mTexturePack);
        v4 = (unsigned int)(v4 + 1);
      }
      while ( (unsigned int)v4 < v2->mLoadingImageCount );
    }
    if ( v2->mLoadingImageCount )
    {
      v7 = UFG::UIScreenTextureManager::Instance();
      UFG::UIScreenTextureManager::ForceFlush(v7);
    }
    v2->mLoadingImages = 0i64;
    v2->mLoadingImageCount = 0;
    _((AMD_HD3D *)1);
    UFG::StreamFileWrapper::SetQueueMode(0);
  }
}

// File Line: 598
// RVA: 0x40D070
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
  UFG::qNode<UFG::LoadingScreenSession,UFG::LoadingScreenSession> *v3; // rax
  UFG::TiDo *v4; // rax
  ANTLR3_INPUT_STREAM_struct *v5; // rax
  UFG::DataStreamer *v6; // rcx
  UFG::DataStreamer *v7; // rcx
  UFG::qList<UFG::LoadingScreenFileRead,UFG::LoadingScreenFileRead,1,0> *v8; // [rsp+48h] [rbp+10h]

  if ( qword_14207B270 )
  {
    UFG::GameSlice::SetupTimeAndWeather(qword_14207B270, 1);
    qword_14207B270 = 0i64;
  }
  if ( !unk_14207B26C )
  {
    v0 = UFG::OSuiteDBLogger::Instance();
    UFG::OSuiteDBLogger::FlushIfTimeoutHasElapsed(v0);
    if ( !(_S12_4 & 1) )
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
        v2->mPrev = (UFG::qNode<UFG::LoadingScreenSession,UFG::LoadingScreenSession> *)&v2->mPrev;
        v2->mNext = (UFG::qNode<UFG::LoadingScreenSession,UFG::LoadingScreenSession> *)&v2->mPrev;
        v2->mStartTime = 0i64;
        v2->mEndTime = 0i64;
        v8 = &v2->mFileReads;
        v8->mNode.mPrev = &v8->mNode;
        v8->mNode.mNext = &v8->mNode;
      }
      else
      {
        v2 = 0i64;
      }
      UFG::gCurrentLoadingScreenSession = v2;
      v2->mStartTime = UFG::qGetTicks();
      v1 = UFG::gCurrentLoadingScreenSession;
      v3 = UFG::gLoadingScreenSessions.mNode.mPrev;
      UFG::gLoadingScreenSessions.mNode.mPrev->mNext = (UFG::qNode<UFG::LoadingScreenSession,UFG::LoadingScreenSession> *)&UFG::gCurrentLoadingScreenSession->mPrev;
      v1->mPrev = v3;
      v1->mNext = (UFG::qNode<UFG::LoadingScreenSession,UFG::LoadingScreenSession> *)&UFG::gLoadingScreenSessions;
      UFG::gLoadingScreenSessions.mNode.mPrev = (UFG::qNode<UFG::LoadingScreenSession,UFG::LoadingScreenSession> *)&v1->mPrev;
    }
    if ( unk_14207B260 && (unsigned __int8)UFG::TiDo::GetIsInstantiated() )
    {
      v4 = UFG::TiDo::GetInstance();
      v4->vfptr->LoadingGameStart(v4, &stru_14207B264);
    }
    UFG::UI::LockGameplayInput((UFG::UI *)v1);
    if ( !(unsigned __int8)UFG::UI::IsGamePaused() )
    {
      v5 = (ANTLR3_INPUT_STREAM_struct *)UFG::UIScreenTextureManager::Instance();
      UFG::UIScreenTextureManager::SetGameState(v5, 8u);
    }
    unk_14207B26C = 1;
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
  float v2; // xmm3_4
  UFG::qWiseSymbol *v3; // rax
  UFG::TiDo *v4; // rax
  UFG::qWiseSymbol *v5; // rax
  UFG::UI *v6; // rcx
  ANTLR3_INPUT_STREAM_struct *v7; // rax
  int v8; // eax

  if ( unk_14207B26C )
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
    unk_14207B26C = 0;
    unk_14207B26E = 0;
    dword_14207B234 = UFG::DataStreamer::GetLoadedBytes();
    if ( (unsigned int)dword_14207B234 > 0xA00000 )
    {
      v2 = UFG::qGetTickTime(unk_14207B238, unk_14207B240);
      if ( v2 > 0.0 )
      {
        if ( unk_14207B25C <= 0.0 )
          unk_14207B25C = (float)dword_14207B234 / v2;
        else
          unk_14207B25C = (float)((float)((float)dword_14207B234 / v2) * 0.19999999)
                        + (float)(unk_14207B25C * 0.80000001);
      }
    }
    if ( unk_14207B22C == 3 )
    {
      UFG::qString::Set(&stru_14207B278, &customWorldMapCaption);
      UFG::UIScreenManagerBase::queuePopOverlay(
        (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
        "Loading");
    }
    UFG::LoadingLogic::StopLoadScreen(&UFG::gLoadingLogic, 1.0);
    if ( unk_14207B260 && (unsigned __int8)UFG::TiDo::GetIsInstantiated() )
    {
      v3 = UFG::qWiseSymbol::get_null();
      UFG::qWiseSymbol::operator=(&stru_14207B264, v3);
      v4 = UFG::TiDo::GetInstance();
      v4->vfptr->LoadingGameEnd(v4, &stru_14207B268);
      v5 = UFG::qWiseSymbol::get_null();
      UFG::qWiseSymbol::operator=(&stru_14207B268, v5);
    }
    unk_14207B260 = 0;
    if ( !(unsigned __int8)UFG::UI::IsGamePaused() )
    {
      v7 = (ANTLR3_INPUT_STREAM_struct *)UFG::UIScreenTextureManager::Instance();
      UFG::UIScreenTextureManager::SetGameState(v7, 2u);
    }
    UFG::UI::UnlockGameplayInput(v6);
    if ( _S12_4 & 1 )
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

