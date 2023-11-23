// File Line: 33
// RVA: 0x428270
void __fastcall UFG::OSuiteDBLogger::OSuiteDBLogger(UFG::OSuiteDBLogger *this)
{
  UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *v2; // r14
  unsigned int v3; // ebx
  unsigned __int64 v4; // rax
  UFG::allocator::free_link *v5; // rax
  OSuite::ZMetric **v6; // rsi
  UFG::OSuiteManager *v7; // rax
  UFG::qList<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver,1,0> *p_m_lOSuiteObservers; // rdx
  UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *mNext; // rax

  v2 = &this->UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver>;
  this->mPrev = &this->UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver>;
  this->mNext = &this->UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver>;
  this->vfptr = (UFG::OSuiteManagerObserverVtbl *)&UFG::OSuiteManagerObserver::`vftable;
  this->vfptr = (UFG::OSuiteManagerObserverVtbl *)&UFG::OSuiteDBLogger::`vftable;
  v3 = 0;
  this->m_pWebServiceClient = 0i64;
  this->m_pMetricAppender = 0i64;
  this->m_pendingMetrics.p = 0i64;
  *(_QWORD *)&this->m_pendingMetrics.size = 0i64;
  v4 = 80i64;
  if ( !is_mul_ok(0xAui64, 8ui64) )
    v4 = -1i64;
  v5 = UFG::qMalloc(v4, "qArray.Reallocate(Constructor)", 0i64);
  v6 = (OSuite::ZMetric **)v5;
  if ( this->m_pendingMetrics.p )
  {
    if ( this->m_pendingMetrics.size )
    {
      do
      {
        v5[v3] = (UFG::allocator::free_link)this->m_pendingMetrics.p[v3];
        ++v3;
      }
      while ( v3 < this->m_pendingMetrics.size );
    }
    operator delete[](this->m_pendingMetrics.p);
  }
  this->m_pendingMetrics.p = v6;
  this->m_pendingMetrics.capacity = 10;
  *(_WORD *)&this->mFlushQueued = 0;
  UFG::qEvent::qEvent(&this->mThreadEvent, "OSuiteDBLogger::ThreadEvent", 1);
  UFG::qThread::qThread(&this->mUpdateThread, "OSuiteDBLogger::ProcessingThread");
  UFG::qMutex::qMutex(&this->mPendingListMutex, &customCaption);
  v7 = UFG::OSuiteManager::Instance();
  p_m_lOSuiteObservers = &v7->m_lOSuiteObservers;
  mNext = v7->m_lOSuiteObservers.mNode.mNext;
  p_m_lOSuiteObservers->mNode.mNext = v2;
  v2->mPrev = &p_m_lOSuiteObservers->mNode;
  v2->mNext = mNext;
  mNext->mPrev = v2;
  UFG::qBaseNodeRB::SetUID((UFG::qBaseNodeRB *)&this->mUpdateThread, 0x8000u);
  UFG::qThread::SetThreadPriority(&this->mUpdateThread, -2);
  UFG::qThread::Start(&this->mUpdateThread, UFG::OSuiteDBLogger::ProcessingThread, this);
}

// File Line: 46
// RVA: 0x42E390
UFG::OSuiteDBLogger *__fastcall UFG::OSuiteDBLogger::Instance()
{
  if ( (_S8_11 & 1) == 0 )
  {
    _S8_11 |= 1u;
    UFG::OSuiteDBLogger::OSuiteDBLogger(&instance_2);
    atexit(UFG::OSuiteDBLogger::Instance_::_2_::_dynamic_atexit_destructor_for__instance__);
  }
  return &instance_2;
}

// File Line: 52
// RVA: 0x42E970
void __fastcall UFG::OSuiteDBLogger::OSuiteManagerConnected(UFG::OSuiteDBLogger *this, OSuite::ZWebServiceClient *p)
{
  OSuite::ZMetricAppender *v3; // rax

  if ( !this->m_pWebServiceClient )
  {
    this->m_pWebServiceClient = p;
    v3 = (OSuite::ZMetricAppender *)OSuite::ZHttpStreamReader::Size((OSuite::ZMemoryBufferChain *)p);
    this->m_pMetricAppender = v3;
    v3->m_nTimeoutSecond = 604800i64;
  }
}

// File Line: 71
// RVA: 0x430DB0
void __fastcall UFG::OSuiteDBLogger::Shutdown(UFG::OSuiteDBLogger *this)
{
  OSuite::ZMetricAppender *m_pMetricAppender; // rcx

  this->mExitRequested = 1;
  UFG::qEvent::Signal(&this->mThreadEvent);
  UFG::qThread::WaitForCompletion(&this->mUpdateThread);
  m_pMetricAppender = this->m_pMetricAppender;
  if ( m_pMetricAppender )
    OSuite::ZMetricAppender::Flush(m_pMetricAppender);
}

// File Line: 82
// RVA: 0x431470
bool __fastcall UFG::OSuiteDBLogger::Update(UFG::OSuiteDBLogger *this, float timeDelta)
{
  return UFG::OSuiteManager::Instance()->m_bConnected;
}

// File Line: 89
// RVA: 0x42B380
char __fastcall UFG::OSuiteDBLogger::CreateMetric(UFG::OSuiteDBLogger *this, const char *metricsTag)
{
  char *Property; // rbx
  UFG::OnlineManager *v5; // rax
  UFG::OnlineId *OnlineId; // rax
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *mPrev; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *mNext; // rax
  char *v9; // r8
  int v10; // eax
  int v11; // ecx
  OSuite::ZMetric *v12; // rax
  char v13; // bl
  UFG::OnlineId result; // [rsp+28h] [rbp-50h] BYREF
  UFG::qString v16; // [rsp+40h] [rbp-38h] BYREF

  if ( !UFG::OSuiteManager::Instance()->m_bConnected || this->m_pMetric )
    return 0;
  Property = (char *)OSuite::ZMetricAppender::GetProperty(
                       this->m_pMetricAppender,
                       OSuite::ZMetricAppender::PlayerUIDPropertyName);
  v5 = UFG::OnlineManager::Instance();
  OnlineId = UFG::OnlineManager::GetOnlineId(v5, &result);
  UFG::OnlineId::ToString(OnlineId, &v16);
  mPrev = result.mPrev;
  mNext = result.mNext;
  result.mPrev->mNext = result.mNext;
  mNext->mPrev = mPrev;
  result.mPrev = &result;
  result.mNext = &result;
  if ( !Property )
    goto LABEL_8;
  v9 = (char *)(v16.mData - Property);
  do
  {
    v10 = (unsigned __int8)v9[(_QWORD)Property];
    v11 = (unsigned __int8)*Property - v10;
    if ( v11 )
      break;
    ++Property;
  }
  while ( v10 );
  if ( v11 )
LABEL_8:
    OSuite::ZMetricAppender::SetPlayerUID(this->m_pMetricAppender, v16.mData);
  v12 = OSuite::ZMetricAppender::NewMetric(this->m_pMetricAppender, metricsTag);
  this->m_pMetric = v12;
  if ( v12 )
  {
    UFG::GameStatAction::TemporaryData::Update();
    v13 = 1;
  }
  else
  {
    v13 = 0;
  }
  UFG::qString::~qString(&v16);
  return v13;
}

// File Line: 112
// RVA: 0x430F20
void __fastcall UFG::OSuiteDBLogger::SubmitMetric(UFG::OSuiteDBLogger *this, bool include_metadata)
{
  UFG::ProgressionTracker *v4; // rax
  UFG::GameSlice *ActiveMaster; // rax
  int mUID; // r8d
  UFG::ProgressionTracker *v7; // rax
  UFG::qSymbol *ActiveFlow; // rax
  const char *v9; // rbx
  UFG::BaseCameraComponent *mCurrentCamera; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  unsigned int CellIndexAtPosition; // eax
  char *SectionNameFromCellIndex; // rax
  UFG::GameStatTracker *v15; // rax
  float Stat; // xmm0_4
  UFG::GameStatTracker *v17; // rax
  UFG::PersistentData::Time *TimeStat; // rax
  float TotalTime; // xmm0_4
  UFG::GameStatTracker *v20; // rax
  float v21; // xmm0_4
  UFG::GameStatTracker *v22; // rax
  float v23; // xmm0_4
  UFG::GameStatTracker *v24; // rax
  int v25; // eax
  UFG::GameStatTracker *v26; // rax
  int v27; // eax
  UFG::GameStatTracker *v28; // rax
  int v29; // eax
  UFG::GameStatTracker *v30; // rax
  int v31; // eax
  float v32; // xmm6_4
  float v33; // xmm7_4
  float v34; // xmm8_4
  UFG::SimObjectCharacter *LocalPlayer; // rax
  UFG::SimComponentHolder *p; // rax
  float *m_pComponent; // rbx
  UFG::qVector3 position; // [rsp+20h] [rbp-48h] BYREF

  v4 = UFG::ProgressionTracker::Instance();
  ActiveMaster = UFG::ProgressionTracker::GetActiveMaster(v4);
  mUID = 0;
  if ( ActiveMaster && !ActiveMaster->mInternalSlice && (unsigned int)(ActiveMaster->mType - 5) <= 6 )
    mUID = ActiveMaster->mNode.mUID;
  OSuite::ZMetric::SetProperty(this->m_pMetric, "i32_MissionId", mUID);
  v7 = UFG::ProgressionTracker::Instance();
  ActiveFlow = UFG::ProgressionTracker::GetActiveFlow(v7);
  OSuite::ZMetric::SetProperty(this->m_pMetric, "i32_FlowId", ActiveFlow->mUID);
  v9 = &customCaption;
  if ( UFG::SectionChooser::GetBSP() )
  {
    mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
    if ( mCurrentCamera )
      mCurrentCamera = (UFG::BaseCameraComponent *)((char *)mCurrentCamera + 80);
    y = mCurrentCamera->mCamera.mView.v2.y;
    z = mCurrentCamera->mCamera.mView.v2.z;
    position.x = mCurrentCamera->mCamera.mView.v2.x;
    position.y = y;
    position.z = z;
    CellIndexAtPosition = UFG::SectionChooser::GetCellIndexAtPosition(&position, 0);
    SectionNameFromCellIndex = UFG::SectionLayout::GetSectionNameFromCellIndex(CellIndexAtPosition);
    v9 = &customCaption;
    if ( SectionNameFromCellIndex )
      v9 = SectionNameFromCellIndex;
  }
  OSuite::ZMetric::SetProperty(this->m_pMetric, "s_CellID", v9);
  v15 = UFG::GameStatTracker::Instance();
  Stat = UFG::GameStatTracker::GetStat(v15, StoryProgress);
  OSuite::ZMetric::SetProperty(this->m_pMetric, "f_StoryProgress", Stat);
  v17 = UFG::GameStatTracker::Instance();
  TimeStat = UFG::GameStatTracker::GetTimeStat(v17, PlayTime);
  TotalTime = UFG::PersistentData::Time::GetTotalTime(TimeStat);
  OSuite::ZMetric::SetProperty(this->m_pMetric, "f_GamePlayTime", TotalTime);
  if ( include_metadata )
  {
    v20 = UFG::GameStatTracker::Instance();
    v21 = UFG::GameStatTracker::GetStat(v20, Health);
    OSuite::ZMetric::SetProperty(this->m_pMetric, "f_Health", v21);
    v22 = UFG::GameStatTracker::Instance();
    v23 = UFG::GameStatTracker::GetStat(v22, MaxHealth);
    OSuite::ZMetric::SetProperty(this->m_pMetric, "f_MaxHealth", v23);
    v24 = UFG::GameStatTracker::Instance();
    v25 = UFG::GameStatTracker::GetStat(v24, Money);
    OSuite::ZMetric::SetProperty(this->m_pMetric, "i32_Cash", v25);
    v26 = UFG::GameStatTracker::Instance();
    v27 = UFG::GameStatTracker::GetStat(v26, Standing);
    OSuite::ZMetric::SetProperty(this->m_pMetric, "i32_FaceXP", v27);
    v28 = UFG::GameStatTracker::Instance();
    v29 = UFG::GameStatTracker::GetStat(v28, CopXP);
    OSuite::ZMetric::SetProperty(this->m_pMetric, "i32_CopXP", v29);
    v30 = UFG::GameStatTracker::Instance();
    v31 = UFG::GameStatTracker::GetStat(v30, TriadXP);
    OSuite::ZMetric::SetProperty(this->m_pMetric, "i32_TriadXP", v31);
    v32 = 0.0;
    v33 = 0.0;
    v34 = 0.0;
    LocalPlayer = UFG::GetLocalPlayer();
    if ( LocalPlayer )
    {
      p = LocalPlayer->m_Components.p;
      m_pComponent = (float *)p[2].m_pComponent;
      if ( m_pComponent )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)p[2].m_pComponent);
        v32 = m_pComponent[44];
        v33 = m_pComponent[45];
        v34 = m_pComponent[46];
      }
    }
    OSuite::ZMetric::SetProperty(this->m_pMetric, "f_X", v32);
    OSuite::ZMetric::SetProperty(this->m_pMetric, "f_Y", v33);
    OSuite::ZMetric::SetProperty(this->m_pMetric, "f_Z", v34);
  }
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mPendingListMutex);
  UFG::qArray<UFG::PedSpawningInfo *,0>::Add(
    (UFG::qArray<UFG::qPropertySet *,0> *)&this->m_pendingMetrics,
    (UFG::qPropertySet *const *)&this->m_pMetric,
    "qArray.Add");
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&this->mPendingListMutex);
  this->m_pMetric = 0i64;
  UFG::qEvent::Signal(&this->mThreadEvent);
}

// File Line: 200
// RVA: 0x42C510
void __fastcall UFG::OSuiteDBLogger::FlushIfTimeoutHasElapsed(UFG::OSuiteDBLogger *this)
{
  OSuite::ZMetricAppender *m_pMetricAppender; // rbx
  OSuite::ITransmitter *m_pTransmitter; // rbx
  unsigned __int64 Clock; // rax

  if ( UFG::OSuiteManager::Instance()->m_bConnected )
  {
    m_pMetricAppender = this->m_pMetricAppender;
    if ( m_pMetricAppender )
    {
      m_pTransmitter = m_pMetricAppender->m_pTransmitter;
      Clock = OSuite::ZClock::_GetClock();
      if ( OSuite::ZClock::_ClockToTime(Clock - m_pTransmitter->m_lastTransmitTime.m_clock, UNIT_SECONDS) > 0x12C )
      {
        this->mFlushQueued = 1;
        UFG::qEvent::Signal(&this->mThreadEvent);
      }
    }
  }
}

// File Line: 215
// RVA: 0x42EFE0
void __fastcall UFG::OSuiteDBLogger::ProcessingThread(void *param)
{
  unsigned int v2; // r8d
  __int64 v3; // rdx
  OSuite::ZMetric *v4; // rdi

  while ( !*((_BYTE *)param + 65) )
  {
    while ( *((_DWORD *)param + 12) )
    {
      UFG::qMutex::Lock((LPCRITICAL_SECTION)param + 4);
      v2 = *((_DWORD *)param + 12);
      v3 = v2 - 1;
      v4 = *(OSuite::ZMetric **)(*((_QWORD *)param + 7) + 8 * v3);
      if ( v2 <= 1 )
        LODWORD(v3) = 0;
      *((_DWORD *)param + 12) = v3;
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)param + 4);
      OSuite::ZMetricAppender::AddMetric(*((OSuite::ZMetricAppender **)param + 4), v4);
    }
    if ( *((_BYTE *)param + 64) )
    {
      OSuite::ZMetricAppender::Flush(*((OSuite::ZMetricAppender **)param + 4));
      *((_BYTE *)param + 64) = 0;
    }
    UFG::qEvent::Wait((UFG::qEvent *)param + 3);
  }
}

