// File Line: 101
// RVA: 0xA37550
void __fastcall UFG::qTaskManagerData::qTaskManagerData(UFG::qTaskManagerData *this, UFG::qTaskManager *task_manager)
{
  UFG::qTaskManager *v2; // rbx
  UFG::qTaskManagerData *v3; // rdi
  UFG::qList<UFG::qTask,UFG::TaskPlat,0,0> *v4; // [rsp+58h] [rbp+10h]

  v2 = task_manager;
  v3 = this;
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)&this->mLock, 0xFA0u);
  v3->mInLock = 0;
  v3->mSyncEvent.mName = "qTaskManagerData.mSyncEvent";
  v3->mSyncEvent.mAutoReset = 1;
  v3->mSyncEvent.mHandlePlat = CreateEventA(0i64, 0, 0, 0i64);
  v3->mEventClose.mName = "qTaskManagerData.mEventClose";
  v3->mEventClose.mAutoReset = 0;
  v3->mEventClose.mHandlePlat = CreateEventA(0i64, 1, 0, 0i64);
  v3->mEventAdd.mName = "qTaskManagerData.mEventAdd";
  v3->mEventAdd.mAutoReset = 0;
  v3->mEventAdd.mHandlePlat = CreateEventA(0i64, 1, 0, 0i64);
  v3->mEventAllDone.mName = "qTaskManagerData.mEventAllDone";
  v3->mEventAllDone.mAutoReset = 0;
  v3->mEventAllDone.mHandlePlat = CreateEventA(0i64, 1, 0, 0i64);
  `eh vector constructor iterator'(v3->mThreads, 0x40ui64, 5, (void (__fastcall *)(void *))UFG::qThread::qThread);
  v4 = &v3->mQueuedTasks;
  v4->mNode.mPrev = &v4->mNode;
  v4->mNode.mNext = &v4->mNode;
  v3->mTaskManager = v2;
  v3->mMaxThreads = 0;
  v3->mSyncTask = 0i64;
  v3->mNumThreadsRunning = 0;
  v3->mNumTotalTasks = 0;
  v3->mNumDoneTasks = 0;
  *(_QWORD *)&v3->mEnablePrintSingleFrame = 0i64;
  v3->mThreadStartCallback = 0i64;
  v3->mThreadStopCallback = 0i64;
}

// File Line: 154
// RVA: 0xA37990
void __fastcall UFG::qTaskManagerData::ChangeState(UFG::qTaskManagerData *this, UFG::qTask *task, UFG::qTask::State new_state)
{
  UFG::qTask *v3; // rdi
  UFG::qTaskManagerData *v4; // rbx
  __int32 v5; // er8
  void *v6; // rcx
  UFG::qNode<UFG::qTask,UFG::TaskPlat> *v7; // rdx
  UFG::qNode<UFG::qTask,UFG::TaskPlat> *v8; // rax

  task->mSyncVars.v.mState = new_state;
  v3 = task;
  v4 = this;
  v5 = new_state - 1;
  if ( v5 )
  {
    if ( v5 == 3 )
    {
      ++this->mNumDoneTasks;
      UFG::qTaskManagerData::UpdateDependents(this, task);
      if ( v4->mSyncTask == v3 )
      {
        v6 = v4->mSyncEvent.mHandlePlat;
        v4->mSyncTask = 0i64;
        SetEvent(v6);
      }
      if ( v4->mNumDoneTasks == v4->mNumTotalTasks )
        SetEvent(v4->mEventAllDone.mHandlePlat);
    }
  }
  else
  {
    ResetEvent(this->mEventAllDone.mHandlePlat);
    v7 = (UFG::qNode<UFG::qTask,UFG::TaskPlat> *)&v3->mPrev;
    v8 = v4->mQueuedTasks.mNode.mNext;
    v4->mQueuedTasks.mNode.mNext = (UFG::qNode<UFG::qTask,UFG::TaskPlat> *)&v3->mPrev;
    v7->mPrev = &v4->mQueuedTasks.mNode;
    v7->mNext = v8;
    v8->mPrev = (UFG::qNode<UFG::qTask,UFG::TaskPlat> *)&v3->mPrev;
    SetEvent(v4->mEventAdd.mHandlePlat);
  }
}

// File Line: 243
// RVA: 0xA39810
void __fastcall UFG::qTaskManagerData::UpdateDependents(UFG::qTaskManagerData *this, UFG::qTask *done_task)
{
  UFG::qTask *v2; // rbx
  UFG::qTaskGroup *v3; // rdx
  UFG::qTaskManagerData *v4; // rsi
  bool v5; // zf
  unsigned __int64 *v6; // rcx
  UFG::qTask *v7; // rdx

  v2 = done_task;
  v3 = done_task->mTaskGroup;
  v4 = this;
  if ( v3 && v2->mFunctionDeclData )
  {
    v5 = v3->mEndTask.mSyncVars.v.mNumDependents-- == 1;
    if ( v5 )
      UFG::qTaskManagerData::ChangeState(this, &v3->mEndTask, STATE_QUEUED);
  }
  else
  {
    while ( v2->mSyncVars.v.mDependents )
    {
      v6 = (unsigned __int64 *)v2->mSyncVars.v.mDependents;
      v2->mSyncVars.v.mDependents = *v6;
      v7 = (UFG::qTask *)v6[1];
      *v6 = 0i64;
      v5 = v7->mSyncVars.v.mNumDependents-- == 1;
      if ( v5 && v7->mSyncVars.v.mState == 2 )
        UFG::qTaskManagerData::ChangeState(v4, v7, STATE_QUEUED);
    }
  }
}

// File Line: 309
// RVA: 0xA37EC0
void __fastcall UFG::qTaskManagerData::ExecuteTask(UFG::qTaskManagerData *this, int thread_id)
{
  UFG::qTaskManagerData *v2; // rbx
  unsigned int v3; // er15
  char *v4; // rbp
  UFG::qTask *v5; // rsi
  UFG::qNode<UFG::qTask,UFG::TaskPlat> *v6; // rdx
  UFG::qNode<UFG::qTask,UFG::TaskPlat> *v7; // rax
  UFG::qNode<UFG::qTask,UFG::TaskPlat> *v8; // rcx
  UFG::qNode<UFG::qTask,UFG::TaskPlat> *v9; // rax
  void (__fastcall *v10)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r10
  void *v11; // r9
  void *v12; // r8
  void *v13; // ST28_8
  void *v14; // rax
  void *v15; // rcx
  UFG::qTaskGroup *v16; // rax
  UFG::qNode<UFG::qTask,UFG::qTask> *v17; // rdx
  signed __int64 i; // r8
  UFG::qNode<UFG::qTask,UFG::TaskPlat> *v19; // rax
  UFG::qNode<UFG::qTask,UFG::qTask> *v20; // rcx
  char v21; // [rsp+30h] [rbp-78h]
  int v22; // [rsp+3Ch] [rbp-6Ch]
  int v23; // [rsp+40h] [rbp-68h]
  __int64 v24; // [rsp+48h] [rbp-60h]
  __int64 v25; // [rsp+50h] [rbp-58h]
  __int64 v26; // [rsp+58h] [rbp-50h]
  __int64 v27; // [rsp+60h] [rbp-48h]
  __int64 v28; // [rsp+68h] [rbp-40h]
  __int64 v29; // [rsp+70h] [rbp-38h]

  v2 = this;
  v3 = thread_id;
  v4 = &customWorldMapCaption;
  v5 = 0i64;
  EnterCriticalSection((LPCRITICAL_SECTION)&this->mLock);
  ++v2->mInLock;
  if ( (unsigned __int64 *)&v2->mQueuedTasks.mNode.mNext[-1] == &v2->mThreads[4].mHandlePlat64 )
  {
    ResetEvent(v2->mEventAdd.mHandlePlat);
  }
  else
  {
    v6 = v2->mQueuedTasks.mNode.mNext;
    v7 = v6->mNext;
    v8 = v6->mPrev;
    v5 = (UFG::qTask *)&v6[-1];
    v8->mNext = v7;
    v7->mPrev = v8;
    v6->mPrev = v6;
    v6->mNext = v6;
    LOWORD(v6[1].mPrev) = 3;
    v9 = v6[3].mPrev;
    if ( v9 )
      v4 = (char *)v9[3].mNext;
    if ( v2->mEnablePrintSingleFrame )
      UFG::qPrintf("GameTask: %d - START -      -        - %s\n", v3, v4);
  }
  --v2->mInLock;
  LeaveCriticalSection((LPCRITICAL_SECTION)&v2->mLock);
  if ( v5 )
  {
    v10 = v5->mPPUFunction;
    if ( v10 != 0i64
      && (void (__fastcall *)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *))((char *)v10 + 2) != 0i64
      && (void (__fastcall *)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *))((char *)v10 + 1) != 0i64 )
    {
      v11 = v5->mParam1;
      v12 = v5->mParam0;
      v13 = v5->mParam3;
      v14 = v5->mParam2;
      v22 = 0;
      v23 = 1;
      v26 = 0i64;
      v27 = 0i64;
      v24 = 0i64;
      v25 = 0i64;
      v29 = 0i64;
      v28 = 0i64;
      v10(v3, (UFG::qMemoryStreamer *)&v21, v12, v11, v14, v13);
    }
    EnterCriticalSection((LPCRITICAL_SECTION)&v2->mLock);
    ++v2->mInLock;
    v5->mSyncVars.v.mState = 4;
    ++v2->mNumDoneTasks;
    UFG::qTaskManagerData::UpdateDependents(v2, v5);
    if ( v2->mSyncTask == v5 )
    {
      v15 = v2->mSyncEvent.mHandlePlat;
      v2->mSyncTask = 0i64;
      SetEvent(v15);
    }
    if ( v2->mNumDoneTasks == v2->mNumTotalTasks )
      SetEvent(v2->mEventAllDone.mHandlePlat);
    if ( v5->mPPUFunction == (void (__fastcall *)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *))-1i64 )
    {
      v16 = v5->mTaskGroup;
      v17 = v16->mTasks.mNode.mNext;
      for ( i = (signed __int64)&v16->mTasks; v17 != (UFG::qNode<UFG::qTask,UFG::qTask> *)i; v17 = v17->mNext )
      {
        LOWORD(v17[2].mPrev) = 1;
        v19 = v2->mQueuedTasks.mNode.mNext;
        v20 = v17 + 1;
        v2->mQueuedTasks.mNode.mNext = (UFG::qNode<UFG::qTask,UFG::TaskPlat> *)&v17[1];
        v20->mNext = (UFG::qNode<UFG::qTask,UFG::qTask> *)v19;
        v20->mPrev = (UFG::qNode<UFG::qTask,UFG::qTask> *)&v2->mQueuedTasks;
        v19->mPrev = (UFG::qNode<UFG::qTask,UFG::TaskPlat> *)&v17[1];
      }
      SetEvent(v2->mEventAdd.mHandlePlat);
    }
    if ( v2->mEnablePrintSingleFrame )
      UFG::qPrintf("GameTask: %d - END   - %4d - %s\n", v3, (unsigned int)v2->mNumDoneTasks, v4);
    --v2->mInLock;
    LeaveCriticalSection((LPCRITICAL_SECTION)&v2->mLock);
  }
}

// File Line: 434
// RVA: 0xA396F0
void __fastcall UFG::ThreadFunction_ExecuteTasks(void *param)
{
  UFG::qTaskManagerData *v1; // rbx
  int v2; // edi
  __int64 v3; // rdx
  char *v4; // rsi
  char *v5; // rbp
  void (__cdecl *v6)(signed __int64, __int64); // rax
  DWORD v7; // eax
  __int64 v8; // rdx
  __int64 v9; // rcx
  void (__fastcall *v10)(); // rax
  HANDLE Handles; // [rsp+30h] [rbp-208h]
  __int64 v12; // [rsp+38h] [rbp-200h]

  v1 = (UFG::qTaskManagerData *)param;
  v2 = _InterlockedExchangeAdd((volatile signed __int32 *)param + 5, 1u);
  v3 = tls_index;
  v4 = (char *)param + 128;
  v5 = (char *)param + 152;
  *(_DWORD *)(*((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 112i64) = v2;
  v6 = (void (__cdecl *)(signed __int64, __int64))*((_QWORD *)param + 3);
  if ( v6 )
    v6(112i64, v3);
  while ( 1 )
  {
    Handles = (HANDLE)*((_QWORD *)v4 + 1);
    v12 = *((_QWORD *)v5 + 1);
    v7 = WaitForMultipleObjects(2u, &Handles, 0, 0xFFFFFFFF);
    if ( v7 >= 0x40 || v7 != 1 )
      break;
    UFG::qTaskManagerData::ExecuteTask(v1, v2);
  }
  _InterlockedDecrement(&v1->mNumThreadsRunning);
  v10 = v1->mThreadStopCallback;
  if ( v10 )
    ((void (__cdecl *)(__int64, __int64))v10)(v9, v8);
}

// File Line: 496
// RVA: 0xA38AC0
void __fastcall UFG::qTaskManager::InitPlat(UFG::qTaskManager *this, void (__fastcall *startCallback)(), void (__fastcall *stopCallback)())
{
  void (__fastcall *v3)(); // rsi
  void (__fastcall *v4)(); // rbp
  UFG::qTaskManager *v5; // rbx
  UFG::allocator::free_link *v6; // rax
  UFG::qTaskManagerData *v7; // rax
  signed int v8; // edi
  int v9; // edi
  __int64 v10; // rbp
  UFG::qTaskManagerData *v11; // r9
  signed __int64 v12; // rsi
  int v13; // ecx
  HANDLE v14; // rax
  int v15; // edx
  DWORD v16; // edx
  void *v17; // rcx
  _SYSTEM_INFO SystemInfo; // [rsp+38h] [rbp-60h]

  v3 = stopCallback;
  v4 = startCallback;
  v5 = this;
  v6 = UFG::qMalloc(0x220ui64, "TaskManagerData", 0i64);
  if ( v6 )
    UFG::qTaskManagerData::qTaskManagerData((UFG::qTaskManagerData *)v6, v5);
  else
    v7 = 0i64;
  v5->mData = v7;
  SystemInfo.dwOemId = 0;
  memset(&SystemInfo.dwPageSize, 0, 0x2Cui64);
  GetSystemInfo(&SystemInfo);
  v8 = SystemInfo.dwNumberOfProcessors - 1;
  if ( (signed int)(SystemInfo.dwNumberOfProcessors - 1) < 1 )
    v8 = 1;
  SetEvent(v5->mData->mEventAllDone.mHandlePlat);
  v5->mData->mSyncTask = 0i64;
  if ( v8 <= 0 )
  {
    v8 = 0;
  }
  else if ( v8 >= 5 )
  {
    v8 = 5;
  }
  v5->mData->mMaxThreads = v8;
  v5->mData->mNumThreadsRunning = 0;
  v5->mData->mThreadStartCallback = v4;
  v5->mData->mThreadStopCallback = v3;
  v9 = 0;
  if ( v5->mData->mMaxThreads > 0 )
  {
    v10 = 0i64;
    do
    {
      v5->mData->mThreads[v10].mName = "qTask::Thread";
      v11 = v5->mData;
      v12 = (signed __int64)&v5->mData->mThreads[v10];
      *(_QWORD *)(v12 + 8) = UFG::ThreadFunction_ExecuteTasks;
      *(_QWORD *)(v12 + 16) = v11;
      v13 = *(_DWORD *)(v12 + 24);
      if ( v13 <= 0 )
        v13 = UFG::qThread::mDefaultThreadStackSize;
      v14 = CreateThread(
              0i64,
              v13,
              (LPTHREAD_START_ROUTINE)UFG::ThreadFunction_ExecuteTasks,
              v11,
              0,
              (LPDWORD)(v12 + 56));
      *(_QWORD *)(v12 + 40) = v14;
      v15 = *(_DWORD *)(v12 + 28);
      if ( v15 == -1 )
        v15 = UFG::qThread::mDefaultThreadPriority;
      if ( v14 != (HANDLE)-1i64 )
        SetThreadPriority(v14, v15);
      v16 = *(_DWORD *)(v12 + 32);
      v17 = *(void **)(v12 + 40);
      if ( v17 != (void *)-1i64 && v16 != -1 )
        SetThreadIdealProcessor(v17, v16);
      ++v9;
      ++v10;
    }
    while ( v9 < v5->mData->mMaxThreads );
  }
}

// File Line: 533
// RVA: 0xA37A70
void __fastcall UFG::qTaskManager::ClosePlat(UFG::qTaskManager *this)
{
  UFG::qTaskManager *v1; // rbx
  UFG::qTaskManagerData *v2; // rdi

  v1 = this;
  if ( this->mData->mNumThreadsRunning > 0 )
  {
    SetEvent(this->mData->mEventClose.mHandlePlat);
    while ( v1->mData->mNumThreadsRunning > 0 )
      Sleep(0xAu);
  }
  v2 = v1->mData;
  if ( v1->mData )
  {
    UFG::qTaskManagerData::~qTaskManagerData(v1->mData);
    operator delete[](v2);
  }
  v1->mData = 0i64;
}

// File Line: 557
// RVA: 0xA38A30
signed __int64 __fastcall UFG::qTaskManager::GetMaxWorkers(UFG::qTaskManager *this)
{
  signed __int64 result; // rax

  result = (unsigned int)this->mData->mMaxThreads;
  if ( (signed int)result < 1 )
    result = 1i64;
  return result;
}

// File Line: 564
// RVA: 0xA38D10
void __fastcall UFG::qTaskManager::NextFramePlat(UFG::qTaskManager *this)
{
  UFG::qTaskManagerData *v1; // rbx
  UFG::qTaskManager *v2; // rdi
  _RTL_CRITICAL_SECTION *v3; // rcx

  v1 = this->mData;
  v2 = this;
  EnterCriticalSection((LPCRITICAL_SECTION)&this->mData->mLock);
  ++v1->mInLock;
  v2->mData->mEnablePrintSingleFrame = v2->mPrintSingleFrame;
  v2->mData->mForceSingleThread = v2->mMode == 0;
  v3 = (_RTL_CRITICAL_SECTION *)v2->mData;
  --v3[2].LockCount;
  LeaveCriticalSection(v3 + 1);
}

// File Line: 585
// RVA: 0xA395C0
void __fastcall UFG::qTaskManager::SyncPlat(UFG::qTaskManager *this, UFG::qTask *task)
{
  UFG::qTask *v2; // rdi
  _RTL_CRITICAL_SECTION **v3; // rsi
  __int64 v4; // rbx
  _RTL_CRITICAL_SECTION *v5; // rbx
  _RTL_CRITICAL_SECTION *v6; // rcx
  _RTL_CRITICAL_SECTION *v7; // rbx

  v2 = task;
  v3 = (_RTL_CRITICAL_SECTION **)this;
  v4 = GetCurrentThreadId();
  if ( v4 == UFG::qGetMainThreadID() )
  {
    if ( v2 )
    {
      v5 = *v3;
      EnterCriticalSection(*v3 + 1);
      ++v5[2].LockCount;
      (*v3)[3].DebugInfo = (_RTL_CRITICAL_SECTION_DEBUG *)v2;
      v6 = *v3;
      --v6[2].LockCount;
      LeaveCriticalSection(v6 + 1);
      while ( v2->mSyncVars.v.mState != 4 )
        WaitForSingleObject((*v3)[2].LockSemaphore, 0x1388u);
    }
    else
    {
      WaitForSingleObject((*v3)[4].LockSemaphore, 0xFFFFFFFF);
    }
  }
  else if ( v2 )
  {
    while ( v2->mSyncVars.v.mState != 4 )
      Sleep(0);
  }
  else
  {
    v7 = *v3;
    while ( HIDWORD(v7[13].OwningThread) != LODWORD(v7[13].OwningThread) )
      Sleep(0);
  }
}

// File Line: 679
// RVA: 0xA378B0
void __fastcall UFG::qTaskManager::AddDependentPlat(UFG::qTaskManager *this, UFG::qTask *task, UFG::qTask *dependent)
{
  UFG::qTask *v3; // rsi
  UFG::qTask *v4; // rdi
  UFG::qTaskManager *v5; // r14
  UFG::qTaskManagerData *v6; // rbx
  char *v7; // rax
  _QWORD *v8; // r8
  _RTL_CRITICAL_SECTION *v9; // rcx

  v3 = dependent;
  v4 = task;
  v5 = this;
  v6 = this->mData;
  EnterCriticalSection((LPCRITICAL_SECTION)&this->mData->mLock);
  ++v6->mInLock;
  v7 = UFG::qLinearAllocator::Malloc(v5->mAllocator, 0x10u, 0x10u);
  v8 = v7;
  if ( v7 )
  {
    *(_QWORD *)v7 = 0i64;
    *((_QWORD *)v7 + 1) = v4;
  }
  else
  {
    v8 = 0i64;
  }
  *v8 = v3->mSyncVars.v.mDependents;
  v3->mSyncVars.v.mDependents = (unsigned __int64)v8;
  if ( v3->mSyncVars.v.mState != 4 )
    ++v4->mSyncVars.v.mNumDependents;
  v9 = (_RTL_CRITICAL_SECTION *)v5->mData;
  --v9[2].LockCount;
  LeaveCriticalSection(v9 + 1);
}

// File Line: 707
// RVA: 0xA391C0
void __fastcall UFG::qTaskManager::Queue(UFG::qTaskManager *this, UFG::qTaskGroup *task_group)
{
  UFG::qTaskManagerData *v2; // rbx
  UFG::qTaskManager *v3; // r14
  UFG::qTaskGroup *v4; // rsi
  _RTL_CRITICAL_SECTION *v5; // rcx

  v2 = this->mData;
  v3 = this;
  v4 = task_group;
  EnterCriticalSection((LPCRITICAL_SECTION)&this->mData->mLock);
  ++v2->mInLock;
  UFG::qTaskManager::AddDependentPlat(v3, &v4->mEndTask, &v4->mStartTask);
  v4->mEndTask.mSyncVars.v.mNumDependents += LOWORD(v4->mNumTasks);
  v3->mData->mNumTotalTasks += v4->mNumTasks;
  UFG::qTaskManager::Queue(v3, &v4->mEndTask);
  UFG::qTaskManager::Queue(v3, &v4->mStartTask);
  v5 = (_RTL_CRITICAL_SECTION *)v3->mData;
  --v5[2].LockCount;
  LeaveCriticalSection(v5 + 1);
}

// File Line: 746
// RVA: 0xA390C0
void __fastcall UFG::qTaskManager::Queue(UFG::qTaskManager *this, UFG::qTask *task)
{
  UFG::qTaskManagerData *v2; // rbx
  UFG::qTaskManager *v3; // rdi
  UFG::qTask *v4; // rsi
  UFG::qTaskManagerData *v5; // rbx
  UFG::qNode<UFG::qTask,UFG::TaskPlat> *v6; // r8
  UFG::qNode<UFG::qTask,UFG::TaskPlat> *v7; // rax
  _RTL_CRITICAL_SECTION *v8; // rcx
  UFG::qTaskManagerData *v9; // r8

  v2 = this->mData;
  v3 = this;
  v4 = task;
  EnterCriticalSection((LPCRITICAL_SECTION)&this->mData->mLock);
  ++v2->mInLock;
  ++v3->mData->mNumTotalTasks;
  if ( v4->mSyncVars.v.mNumDependents )
  {
    v4->mSyncVars.v.mState = 2;
  }
  else
  {
    v5 = v3->mData;
    v4->mSyncVars.v.mState = 1;
    ResetEvent(v5->mEventAllDone.mHandlePlat);
    v6 = (UFG::qNode<UFG::qTask,UFG::TaskPlat> *)&v4->mPrev;
    v7 = v5->mQueuedTasks.mNode.mNext;
    v5->mQueuedTasks.mNode.mNext = (UFG::qNode<UFG::qTask,UFG::TaskPlat> *)&v4->mPrev;
    v6->mPrev = &v5->mQueuedTasks.mNode;
    v6->mNext = v7;
    v7->mPrev = (UFG::qNode<UFG::qTask,UFG::TaskPlat> *)&v4->mPrev;
    SetEvent(v5->mEventAdd.mHandlePlat);
  }
  v8 = (_RTL_CRITICAL_SECTION *)&v3->mData->mLock;
  --v8[1].LockCount;
  LeaveCriticalSection(v8);
  v9 = v3->mData;
  if ( !v3->mData->mMaxThreads
    && (unsigned __int64 *)&v9->mQueuedTasks.mNode.mNext[-1] != &v9->mThreads[4].mHandlePlat64 )
  {
    do
    {
      UFG::qTaskManagerData::ExecuteTask(v9, 0);
      v9 = v3->mData;
    }
    while ( &v3->mData->mQueuedTasks.mNode.mNext[-1] != (UFG::qNode<UFG::qTask,UFG::TaskPlat> *)&v3->mData->mThreads[4].mHandlePlat64 );
  }
}

