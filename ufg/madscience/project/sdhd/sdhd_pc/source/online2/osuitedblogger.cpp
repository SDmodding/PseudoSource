// File Line: 33
// RVA: 0x428270
void __fastcall UFG::OSuiteDBLogger::OSuiteDBLogger(UFG::OSuiteDBLogger *this)
{
  UFG::OSuiteDBLogger *v1; // rdi
  UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *v2; // r14
  unsigned int v3; // ebx
  unsigned __int64 v4; // rax
  UFG::allocator::free_link *v5; // rax
  OSuite::ZMetric **v6; // rsi
  UFG::OSuiteManager *v7; // rax
  signed __int64 v8; // rdx
  UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *v9; // rax

  v1 = this;
  v2 = (UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
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
  if ( v1->m_pendingMetrics.p )
  {
    if ( v1->m_pendingMetrics.size > 0 )
    {
      do
      {
        v5[v3] = (UFG::allocator::free_link)v1->m_pendingMetrics.p[v3];
        ++v3;
      }
      while ( v3 < v1->m_pendingMetrics.size );
    }
    operator delete[](v1->m_pendingMetrics.p);
  }
  v1->m_pendingMetrics.p = v6;
  v1->m_pendingMetrics.capacity = 10;
  *(_WORD *)&v1->mFlushQueued = 0;
  UFG::qEvent::qEvent(&v1->mThreadEvent, "OSuiteDBLogger::ThreadEvent", 1);
  UFG::qThread::qThread(&v1->mUpdateThread, "OSuiteDBLogger::ProcessingThread");
  UFG::qMutex::qMutex(&v1->mPendingListMutex, &customWorldMapCaption);
  v7 = UFG::OSuiteManager::Instance();
  v8 = (signed __int64)&v7->m_lOSuiteObservers;
  v9 = v7->m_lOSuiteObservers.mNode.mNext;
  *(_QWORD *)(v8 + 8) = v2;
  v2->mPrev = (UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *)v8;
  v2->mNext = v9;
  v9->mPrev = v2;
  UFG::qBaseNodeRB::SetUID((UFG::qBaseNodeRB *)&v1->mUpdateThread, 0x8000u);
  UFG::qThread::SetThreadPriority(&v1->mUpdateThread, -2);
  UFG::qThread::Start(&v1->mUpdateThread, UFG::OSuiteDBLogger::ProcessingThread, v1);
}

// File Line: 46
// RVA: 0x42E390
UFG::OSuiteDBLogger *__fastcall UFG::OSuiteDBLogger::Instance()
{
  if ( !(_S8_11 & 1) )
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
  UFG::OSuiteDBLogger *v2; // rbx
  OSuite::ZMemoryBuffer *v3; // rax

  v2 = this;
  if ( !this->m_pWebServiceClient )
  {
    this->m_pWebServiceClient = p;
    v3 = OSuite::ZHttpStreamReader::Size((OSuite::ZMemoryBufferChain *)p);
    v2->m_pMetricAppender = (OSuite::ZMetricAppender *)v3;
    v3[3].m_pBuffer = (void *)604800;
  }
}

// File Line: 71
// RVA: 0x430DB0
void __fastcall UFG::OSuiteDBLogger::Shutdown(UFG::OSuiteDBLogger *this)
{
  UFG::OSuiteDBLogger *v1; // rbx
  OSuite::ZMetricAppender *v2; // rcx

  v1 = this;
  this->mExitRequested = 1;
  UFG::qEvent::Signal(&this->mThreadEvent);
  UFG::qThread::WaitForCompletion(&v1->mUpdateThread);
  v2 = v1->m_pMetricAppender;
  if ( v2 )
    OSuite::ZMetricAppender::Flush(v2);
}

// File Line: 82
// RVA: 0x431470
bool __fastcall UFG::OSuiteDBLogger::Update(UFG::OSuiteDBLogger *this, float timeDelta)
{
  return UFG::OSuiteManager::Instance()->m_bConnected != 0;
}

// File Line: 89
// RVA: 0x42B380
char __fastcall UFG::OSuiteDBLogger::CreateMetric(UFG::OSuiteDBLogger *this, const char *metricsTag)
{
  const char *v2; // rsi
  UFG::OSuiteDBLogger *v3; // rdi
  char *v4; // rbx
  UFG::OnlineManager *v5; // rax
  UFG::OnlineId *v6; // rax
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v7; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v8; // rax
  char *v9; // r8
  int v10; // eax
  int v11; // ecx
  OSuite::ZMetric *v12; // rax
  char v13; // bl
  UFG::OnlineId result; // [rsp+28h] [rbp-50h]
  UFG::qString v16; // [rsp+40h] [rbp-38h]

  v2 = metricsTag;
  v3 = this;
  if ( !UFG::OSuiteManager::Instance()->m_bConnected || v3->m_pMetric )
    return 0;
  v4 = (char *)OSuite::ZMetricAppender::GetProperty(
                 v3->m_pMetricAppender,
                 OSuite::ZMetricAppender::PlayerUIDPropertyName);
  v5 = UFG::OnlineManager::Instance();
  v6 = UFG::OnlineManager::GetOnlineId(v5, &result);
  UFG::OnlineId::ToString(v6, &v16);
  v7 = result.mPrev;
  v8 = result.mNext;
  result.mPrev->mNext = result.mNext;
  v8->mPrev = v7;
  result.mPrev = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&result;
  result.mNext = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&result;
  if ( !v4 )
    goto LABEL_16;
  v9 = (char *)(v16.mData - v4);
  do
  {
    v10 = (unsigned __int8)v9[(_QWORD)v4];
    v11 = (unsigned __int8)*v4 - v10;
    if ( (unsigned __int8)*v4 != v10 )
      break;
    ++v4;
  }
  while ( v10 );
  if ( v11 )
LABEL_16:
    OSuite::ZMetricAppender::SetPlayerUID(v3->m_pMetricAppender, v16.mData);
  v12 = OSuite::ZMetricAppender::NewMetric(v3->m_pMetricAppender, v2);
  v3->m_pMetric = v12;
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
  UFG::OSuiteDBLogger *v2; // rsi
  bool v3; // bp
  UFG::ProgressionTracker *v4; // rax
  UFG::GameSlice *v5; // rax
  int v6; // er8
  UFG::ProgressionTracker *v7; // rax
  UFG::qSymbol *v8; // rax
  const char *v9; // rbx
  UFG::BaseCameraComponent *v10; // rax
  float v11; // xmm1_4
  float v12; // xmm2_4
  unsigned int v13; // eax
  char *v14; // rax
  UFG::GameStatTracker *v15; // rax
  float v16; // xmm0_4
  UFG::GameStatTracker *v17; // rax
  UFG::PersistentData::Time *v18; // rax
  float v19; // xmm0_4
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
  UFG::SimObjectCharacter *v35; // rax
  UFG::SimComponentHolder *v36; // rax
  float *v37; // rbx
  UFG::qVector3 position; // [rsp+20h] [rbp-48h]

  v2 = this;
  v3 = include_metadata;
  v4 = UFG::ProgressionTracker::Instance();
  v5 = UFG::ProgressionTracker::GetActiveMaster(v4);
  v6 = 0;
  if ( v5 && !v5->mInternalSlice && (unsigned int)(v5->mType - 5) <= 6 )
    v6 = v5->mNode.mUID;
  OSuite::ZMetric::SetProperty(v2->m_pMetric, "i32_MissionId", v6);
  v7 = UFG::ProgressionTracker::Instance();
  v8 = UFG::ProgressionTracker::GetActiveFlow(v7);
  OSuite::ZMetric::SetProperty(v2->m_pMetric, "i32_FlowId", v8->mUID);
  v9 = &customWorldMapCaption;
  if ( UFG::SectionChooser::GetBSP() )
  {
    v10 = UFG::Director::Get()->mCurrentCamera;
    if ( v10 )
      v10 = (UFG::BaseCameraComponent *)((char *)v10 + 80);
    v11 = v10->mCamera.mView.v2.y;
    v12 = v10->mCamera.mView.v2.z;
    position.x = v10->mCamera.mView.v2.x;
    position.y = v11;
    position.z = v12;
    v13 = UFG::SectionChooser::GetCellIndexAtPosition(&position, 0);
    v14 = UFG::SectionLayout::GetSectionNameFromCellIndex(v13);
    v9 = &customWorldMapCaption;
    if ( v14 )
      v9 = v14;
  }
  OSuite::ZMetric::SetProperty(v2->m_pMetric, "s_CellID", v9);
  v15 = UFG::GameStatTracker::Instance();
  v16 = UFG::GameStatTracker::GetStat(v15, StoryProgress);
  OSuite::ZMetric::SetProperty(v2->m_pMetric, "f_StoryProgress", v16);
  v17 = UFG::GameStatTracker::Instance();
  v18 = UFG::GameStatTracker::GetTimeStat(v17, PlayTime);
  v19 = UFG::PersistentData::Time::GetTotalTime(v18);
  OSuite::ZMetric::SetProperty(v2->m_pMetric, "f_GamePlayTime", v19);
  if ( v3 )
  {
    v20 = UFG::GameStatTracker::Instance();
    v21 = UFG::GameStatTracker::GetStat(v20, Health);
    OSuite::ZMetric::SetProperty(v2->m_pMetric, "f_Health", v21);
    v22 = UFG::GameStatTracker::Instance();
    v23 = UFG::GameStatTracker::GetStat(v22, MaxHealth);
    OSuite::ZMetric::SetProperty(v2->m_pMetric, "f_MaxHealth", v23);
    v24 = UFG::GameStatTracker::Instance();
    v25 = UFG::GameStatTracker::GetStat(v24, Money);
    OSuite::ZMetric::SetProperty(v2->m_pMetric, "i32_Cash", v25);
    v26 = UFG::GameStatTracker::Instance();
    v27 = UFG::GameStatTracker::GetStat(v26, Standing);
    OSuite::ZMetric::SetProperty(v2->m_pMetric, "i32_FaceXP", v27);
    v28 = UFG::GameStatTracker::Instance();
    v29 = UFG::GameStatTracker::GetStat(v28, CopXP);
    OSuite::ZMetric::SetProperty(v2->m_pMetric, "i32_CopXP", v29);
    v30 = UFG::GameStatTracker::Instance();
    v31 = UFG::GameStatTracker::GetStat(v30, TriadXP);
    OSuite::ZMetric::SetProperty(v2->m_pMetric, "i32_TriadXP", v31);
    v32 = 0.0;
    v33 = 0.0;
    v34 = 0.0;
    v35 = UFG::GetLocalPlayer();
    if ( v35 )
    {
      v36 = v35->m_Components.p;
      v37 = (float *)v36[2].m_pComponent;
      if ( v37 )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v36[2].m_pComponent);
        v32 = v37[44];
        v33 = v37[45];
        v34 = v37[46];
      }
    }
    OSuite::ZMetric::SetProperty(v2->m_pMetric, "f_X", v32);
    OSuite::ZMetric::SetProperty(v2->m_pMetric, "f_Y", v33);
    OSuite::ZMetric::SetProperty(v2->m_pMetric, "f_Z", v34);
  }
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&v2->mPendingListMutex);
  UFG::qArray<UFG::PedSpawningInfo *,0>::Add(
    (UFG::qArray<UFG::qPropertySet *,0> *)&v2->m_pendingMetrics,
    (UFG::qPropertySet *const *)&v2->m_pMetric,
    "qArray.Add");
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v2->mPendingListMutex);
  v2->m_pMetric = 0i64;
  UFG::qEvent::Signal(&v2->mThreadEvent);
}

// File Line: 200
// RVA: 0x42C510
void __fastcall UFG::OSuiteDBLogger::FlushIfTimeoutHasElapsed(UFG::OSuiteDBLogger *this)
{
  UFG::OSuiteDBLogger *v1; // rdi
  OSuite::ZMetricAppender *v2; // rbx
  OSuite::ITransmitter *v3; // rbx
  unsigned __int64 v4; // rax

  v1 = this;
  if ( UFG::OSuiteManager::Instance()->m_bConnected )
  {
    v2 = v1->m_pMetricAppender;
    if ( v2 )
    {
      v3 = v2->m_pTransmitter;
      v4 = OSuite::ZClock::_GetClock();
      if ( OSuite::ZClock::_ClockToTime(v4 - v3->m_lastTransmitTime.m_clock, 0) > 0x12C )
      {
        v1->mFlushQueued = 1;
        UFG::qEvent::Signal(&v1->mThreadEvent);
      }
    }
  }
}

// File Line: 215
// RVA: 0x42EFE0
void __fastcall UFG::OSuiteDBLogger::ProcessingThread(void *param)
{
  void *i; // rbx
  unsigned int v2; // er8
  __int64 v3; // rdx
  OSuite::ZMetric *v4; // rdi

  for ( i = param; !*((_BYTE *)i + 65); UFG::qEvent::Wait((UFG::qEvent *)i + 3) )
  {
    while ( *((_DWORD *)i + 12) > 0u )
    {
      UFG::qMutex::Lock((LPCRITICAL_SECTION)i + 4);
      v2 = *((_DWORD *)i + 12);
      v3 = v2 - 1;
      v4 = *(OSuite::ZMetric **)(*((_QWORD *)i + 7) + 8 * v3);
      if ( v2 <= 1 )
        LODWORD(v3) = 0;
      *((_DWORD *)i + 12) = v3;
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)i + 4);
      OSuite::ZMetricAppender::AddMetric(*((OSuite::ZMetricAppender **)i + 4), v4);
    }
    if ( *((_BYTE *)i + 64) )
    {
      OSuite::ZMetricAppender::Flush(*((OSuite::ZMetricAppender **)i + 4));
      *((_BYTE *)i + 64) = 0;
    }
  }
}

