// File Line: 101
// RVA: 0xA37550
void __fastcall UFG::qTaskManagerData::qTaskManagerData(UFG::qTaskManagerData *this, UFG::qTaskManager *task_manager)
{
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)&this->mLock, 0xFA0u);
  this->mInLock = 0;
  this->mSyncEvent.mName = "qTaskManagerData.mSyncEvent";
  this->mSyncEvent.mAutoReset = 1;
  this->mSyncEvent.mHandlePlat = CreateEventA(0i64, 0, 0, 0i64);
  this->mEventClose.mName = "qTaskManagerData.mEventClose";
  this->mEventClose.mAutoReset = 0;
  this->mEventClose.mHandlePlat = CreateEventA(0i64, 1, 0, 0i64);
  this->mEventAdd.mName = "qTaskManagerData.mEventAdd";
  this->mEventAdd.mAutoReset = 0;
  this->mEventAdd.mHandlePlat = CreateEventA(0i64, 1, 0, 0i64);
  this->mEventAllDone.mName = "qTaskManagerData.mEventAllDone";
  this->mEventAllDone.mAutoReset = 0;
  this->mEventAllDone.mHandlePlat = CreateEventA(0i64, 1, 0, 0i64);
  `eh vector constructor iterator(this->mThreads, 0x40ui64, 5, (void (__fastcall *)(void *))UFG::qThread::qThread);
  this->mQueuedTasks.mNode.mPrev = &this->mQueuedTasks.mNode;
  this->mQueuedTasks.mNode.mNext = &this->mQueuedTasks.mNode;
  this->mTaskManager = task_manager;
  this->mMaxThreads = 0;
  this->mSyncTask = 0i64;
  this->mNumThreadsRunning = 0;
  this->mNumTotalTasks = 0;
  this->mNumDoneTasks = 0;
  *(_QWORD *)&this->mEnablePrintSingleFrame = 0i64;
  this->mThreadStartCallback = 0i64;
  this->mThreadStopCallback = 0i64;
}

// File Line: 154
// RVA: 0xA37990
void __fastcall UFG::qTaskManagerData::ChangeState(
        UFG::qTaskManagerData *this,
        UFG::qTask *task,
        UFG::qTask::State new_state)
{
  int v5; // r8d
  void *mHandlePlat; // rcx
  UFG::qNode<UFG::qTask,UFG::TaskPlat> *mNext; // rax

  task->mSyncVars.v.mState = new_state;
  v5 = new_state - 1;
  if ( v5 )
  {
    if ( v5 == 3 )
    {
      ++this->mNumDoneTasks;
      UFG::qTaskManagerData::UpdateDependents(this, task);
      if ( this->mSyncTask == task )
      {
        mHandlePlat = this->mSyncEvent.mHandlePlat;
        this->mSyncTask = 0i64;
        SetEvent(mHandlePlat);
      }
      if ( this->mNumDoneTasks == this->mNumTotalTasks )
        SetEvent(this->mEventAllDone.mHandlePlat);
    }
  }
  else
  {
    ResetEvent(this->mEventAllDone.mHandlePlat);
    mNext = this->mQueuedTasks.mNode.mNext;
    this->mQueuedTasks.mNode.mNext = &task->UFG::qNode<UFG::qTask,UFG::TaskPlat>;
    task->UFG::qNode<UFG::qTask,UFG::TaskPlat>::mPrev = &this->mQueuedTasks.mNode;
    task->UFG::qNode<UFG::qTask,UFG::TaskPlat>::mNext = mNext;
    mNext->mPrev = &task->UFG::qNode<UFG::qTask,UFG::TaskPlat>;
    SetEvent(this->mEventAdd.mHandlePlat);
  }
}

// File Line: 243
// RVA: 0xA39810
void __fastcall UFG::qTaskManagerData::UpdateDependents(UFG::qTaskManagerData *this, UFG::qTask *done_task)
{
  UFG::qTaskGroup *mTaskGroup; // rdx
  bool v5; // zf
  unsigned __int64 *mDependents; // rcx
  UFG::qTask *v7; // rdx

  mTaskGroup = done_task->mTaskGroup;
  if ( mTaskGroup && done_task->mFunctionDeclData )
  {
    v5 = mTaskGroup->mEndTask.mSyncVars.v.mNumDependents-- == 1;
    if ( v5 )
      UFG::qTaskManagerData::ChangeState(this, &mTaskGroup->mEndTask, STATE_QUEUED);
  }
  else
  {
    while ( done_task->mSyncVars.v.mDependents )
    {
      mDependents = (unsigned __int64 *)done_task->mSyncVars.v.mDependents;
      done_task->mSyncVars.v.mDependents = *mDependents;
      v7 = (UFG::qTask *)mDependents[1];
      *mDependents = 0i64;
      v5 = v7->mSyncVars.v.mNumDependents-- == 1;
      if ( v5 && v7->mSyncVars.v.mState == 2 )
        UFG::qTaskManagerData::ChangeState(this, v7, STATE_QUEUED);
    }
  }
}

// File Line: 309
// RVA: 0xA37EC0
void __fastcall UFG::qTaskManagerData::ExecuteTask(UFG::qTaskManagerData *this, unsigned int thread_id)
{
  const char *v4; // rbp
  UFG::qTask *v5; // rsi
  UFG::qNode<UFG::qTask,UFG::TaskPlat> *mNext; // rdx
  UFG::qNode<UFG::qTask,UFG::TaskPlat> *v7; // rax
  UFG::qNode<UFG::qTask,UFG::TaskPlat> *mPrev; // rcx
  UFG::qNode<UFG::qTask,UFG::TaskPlat> *v9; // rax
  void (__fastcall *mPPUFunction)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r10
  void *mParam1; // r9
  void *mParam0; // r8
  void *mParam2; // rax
  void *mHandlePlat; // rcx
  UFG::qTaskGroup *mTaskGroup; // rax
  UFG::qNode<UFG::qTask,UFG::qTask> *v16; // rdx
  UFG::qList<UFG::qTask,UFG::qTask,0,0> *i; // r8
  UFG::qNode<UFG::qTask,UFG::TaskPlat> *v18; // rax
  void *mParam3; // [rsp+28h] [rbp-80h]
  char v20; // [rsp+30h] [rbp-78h] BYREF
  int v21; // [rsp+3Ch] [rbp-6Ch]
  int v22; // [rsp+40h] [rbp-68h]
  __int64 v23; // [rsp+48h] [rbp-60h]
  __int64 v24; // [rsp+50h] [rbp-58h]
  __int64 v25; // [rsp+58h] [rbp-50h]
  __int64 v26; // [rsp+60h] [rbp-48h]
  __int64 v27; // [rsp+68h] [rbp-40h]
  __int64 v28; // [rsp+70h] [rbp-38h]

  v4 = &customCaption;
  v5 = 0i64;
  EnterCriticalSection((LPCRITICAL_SECTION)&this->mLock);
  ++this->mInLock;
  if ( (unsigned __int64 *)&this->mQueuedTasks.mNode.mNext[-1] == &this->mThreads[4].mHandlePlat64 )
  {
    ResetEvent(this->mEventAdd.mHandlePlat);
  }
  else
  {
    mNext = this->mQueuedTasks.mNode.mNext;
    v7 = mNext->mNext;
    mPrev = mNext->mPrev;
    v5 = (UFG::qTask *)&mNext[-1];
    mPrev->mNext = v7;
    v7->mPrev = mPrev;
    mNext->mPrev = mNext;
    mNext->mNext = mNext;
    LOWORD(mNext[1].mPrev) = 3;
    v9 = mNext[3].mPrev;
    if ( v9 )
      v4 = (const char *)v9[3].mNext;
    if ( this->mEnablePrintSingleFrame )
      UFG::qPrintf("GameTask: %d - START -      -        - %s\n", thread_id, v4);
  }
  --this->mInLock;
  LeaveCriticalSection((LPCRITICAL_SECTION)&this->mLock);
  if ( v5 )
  {
    mPPUFunction = v5->mPPUFunction;
    if ( mPPUFunction != 0i64
      && (void (__fastcall *)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *))((char *)mPPUFunction + 2) != 0i64
      && (void (__fastcall *)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *))((char *)mPPUFunction + 1) != 0i64 )
    {
      mParam1 = v5->mParam1;
      mParam0 = v5->mParam0;
      mParam3 = v5->mParam3;
      mParam2 = v5->mParam2;
      v21 = 0;
      v22 = 1;
      v25 = 0i64;
      v26 = 0i64;
      v23 = 0i64;
      v24 = 0i64;
      v28 = 0i64;
      v27 = 0i64;
      mPPUFunction(thread_id, (UFG::qMemoryStreamer *)&v20, mParam0, mParam1, mParam2, mParam3);
    }
    EnterCriticalSection((LPCRITICAL_SECTION)&this->mLock);
    ++this->mInLock;
    v5->mSyncVars.v.mState = 4;
    ++this->mNumDoneTasks;
    UFG::qTaskManagerData::UpdateDependents(this, v5);
    if ( this->mSyncTask == v5 )
    {
      mHandlePlat = this->mSyncEvent.mHandlePlat;
      this->mSyncTask = 0i64;
      SetEvent(mHandlePlat);
    }
    if ( this->mNumDoneTasks == this->mNumTotalTasks )
      SetEvent(this->mEventAllDone.mHandlePlat);
    if ( v5->mPPUFunction == (void (__fastcall *)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *))-1i64 )
    {
      mTaskGroup = v5->mTaskGroup;
      v16 = mTaskGroup->mTasks.mNode.mNext;
      for ( i = &mTaskGroup->mTasks; v16 != (UFG::qNode<UFG::qTask,UFG::qTask> *)i; v16 = v16->mNext )
      {
        LOWORD(v16[2].mPrev) = 1;
        v18 = this->mQueuedTasks.mNode.mNext;
        this->mQueuedTasks.mNode.mNext = (UFG::qNode<UFG::qTask,UFG::TaskPlat> *)&v16[1];
        v16[1].mNext = (UFG::qNode<UFG::qTask,UFG::qTask> *)v18;
        v16[1].mPrev = (UFG::qNode<UFG::qTask,UFG::qTask> *)&this->mQueuedTasks;
        v18->mPrev = (UFG::qNode<UFG::qTask,UFG::TaskPlat> *)&v16[1];
      }
      SetEvent(this->mEventAdd.mHandlePlat);
    }
    if ( this->mEnablePrintSingleFrame )
      UFG::qPrintf("GameTask: %d - END   - %4d - %s\n", thread_id, (unsigned int)this->mNumDoneTasks, v4);
    --this->mInLock;
    LeaveCriticalSection((LPCRITICAL_SECTION)&this->mLock);
  }
}

// File Line: 434
// RVA: 0xA396F0
void __fastcall UFG::ThreadFunction_ExecuteTasks(UFG::qTaskManagerData *param)
{
  unsigned int v2; // edi
  __int64 v3; // rdx
  UFG::qEvent *p_mEventClose; // rsi
  UFG::qEvent *p_mEventAdd; // rbp
  void (__fastcall *mThreadStartCallback)(); // rax
  __int64 v7; // rdx
  __int64 v8; // rcx
  void (__fastcall *mThreadStopCallback)(); // rax
  HANDLE Handles[64]; // [rsp+30h] [rbp-208h] BYREF

  v2 = _InterlockedExchangeAdd(&param->mNumThreadsRunning, 1u);
  v3 = tls_index;
  p_mEventClose = &param->mEventClose;
  p_mEventAdd = &param->mEventAdd;
  *(_DWORD *)(*((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 112i64) = v2;
  mThreadStartCallback = param->mThreadStartCallback;
  if ( mThreadStartCallback )
    ((void (__fastcall *)(__int64, __int64))mThreadStartCallback)(112i64, v3);
  while ( 1 )
  {
    Handles[0] = p_mEventClose->mHandlePlat;
    Handles[1] = p_mEventAdd->mHandlePlat;
    if ( WaitForMultipleObjects(2u, Handles, 0, 0xFFFFFFFF) != 1 )
      break;
    UFG::qTaskManagerData::ExecuteTask(param, v2);
  }
  _InterlockedDecrement(&param->mNumThreadsRunning);
  mThreadStopCallback = param->mThreadStopCallback;
  if ( mThreadStopCallback )
    ((void (__fastcall *)(__int64, __int64))mThreadStopCallback)(v8, v7);
}

// File Line: 496
// RVA: 0xA38AC0
void __fastcall UFG::qTaskManager::InitPlat(
        UFG::qTaskManager *this,
        void (__fastcall *startCallback)(),
        void (__fastcall *stopCallback)())
{
  UFG::allocator::free_link *v6; // rax
  UFG::qTaskManagerData *v7; // rax
  int v8; // edi
  int v9; // edi
  __int64 v10; // rbp
  UFG::qTaskManagerData *mData; // r9
  UFG::qThread *v12; // rsi
  int mStacksize; // ecx
  HANDLE Thread; // rax
  int mPriority; // edx
  DWORD mLogicalCoreID; // edx
  void *mHandlePlat; // rcx
  _SYSTEM_INFO SystemInfo; // [rsp+38h] [rbp-60h] BYREF

  v6 = UFG::qMalloc(0x220ui64, "TaskManagerData", 0i64);
  if ( v6 )
    UFG::qTaskManagerData::qTaskManagerData((UFG::qTaskManagerData *)v6, this);
  else
    v7 = 0i64;
  this->mData = v7;
  memset(&SystemInfo, 0, sizeof(SystemInfo));
  GetSystemInfo(&SystemInfo);
  v8 = SystemInfo.dwNumberOfProcessors - 1;
  if ( (signed int)(SystemInfo.dwNumberOfProcessors - 1) < 1 )
    v8 = 1;
  SetEvent(this->mData->mEventAllDone.mHandlePlat);
  this->mData->mSyncTask = 0i64;
  if ( v8 <= 0 )
  {
    v8 = 0;
  }
  else if ( v8 >= 5 )
  {
    v8 = 5;
  }
  this->mData->mMaxThreads = v8;
  this->mData->mNumThreadsRunning = 0;
  this->mData->mThreadStartCallback = startCallback;
  this->mData->mThreadStopCallback = stopCallback;
  v9 = 0;
  if ( this->mData->mMaxThreads > 0 )
  {
    v10 = 0i64;
    do
    {
      this->mData->mThreads[v10].mName = "qTask::Thread";
      mData = this->mData;
      v12 = &this->mData->mThreads[v10];
      v12->mThreadFunction = UFG::ThreadFunction_ExecuteTasks;
      v12->mThreadParam = mData;
      mStacksize = v12->mStacksize;
      if ( mStacksize <= 0 )
        mStacksize = UFG::qThread::mDefaultThreadStackSize;
      Thread = CreateThread(
                 0i64,
                 mStacksize,
                 (LPTHREAD_START_ROUTINE)UFG::ThreadFunction_ExecuteTasks,
                 mData,
                 0,
                 &v12->mThreadIDPlat);
      v12->mHandlePlat = Thread;
      mPriority = v12->mPriority;
      if ( mPriority == -1 )
        mPriority = UFG::qThread::mDefaultThreadPriority;
      if ( Thread != (HANDLE)-1i64 )
        SetThreadPriority(Thread, mPriority);
      mLogicalCoreID = v12->mLogicalCoreID;
      mHandlePlat = v12->mHandlePlat;
      if ( mHandlePlat != (void *)-1i64 && mLogicalCoreID != -1 )
        SetThreadIdealProcessor(mHandlePlat, mLogicalCoreID);
      ++v9;
      ++v10;
    }
    while ( v9 < this->mData->mMaxThreads );
  }
}

// File Line: 533
// RVA: 0xA37A70
void __fastcall UFG::qTaskManager::ClosePlat(UFG::qTaskManager *this)
{
  UFG::qTaskManagerData *mData; // rdi

  if ( this->mData->mNumThreadsRunning > 0 )
  {
    SetEvent(this->mData->mEventClose.mHandlePlat);
    while ( this->mData->mNumThreadsRunning > 0 )
      Sleep(0xAu);
  }
  mData = this->mData;
  if ( this->mData )
  {
    UFG::qTaskManagerData::~qTaskManagerData(this->mData);
    operator delete[](mData);
  }
  this->mData = 0i64;
}

// File Line: 557
// RVA: 0xA38A30
__int64 __fastcall UFG::qTaskManager::GetMaxWorkers(UFG::qTaskManager *this)
{
  __int64 result; // rax

  result = (unsigned int)this->mData->mMaxThreads;
  if ( (int)result < 1 )
    return 1i64;
  return result;
}

// File Line: 564
// RVA: 0xA38D10
void __fastcall UFG::qTaskManager::NextFramePlat(UFG::qTaskManager *this)
{
  UFG::qTaskManagerData *mData; // rbx
  _RTL_CRITICAL_SECTION *v3; // rcx

  mData = this->mData;
  EnterCriticalSection((LPCRITICAL_SECTION)&this->mData->mLock);
  ++mData->mInLock;
  this->mData->mEnablePrintSingleFrame = this->mPrintSingleFrame;
  this->mData->mForceSingleThread = this->mMode == MODE_ZERO_WORKERS;
  v3 = (_RTL_CRITICAL_SECTION *)this->mData;
  --v3[2].LockCount;
  LeaveCriticalSection(v3 + 1);
}

// File Line: 585
// RVA: 0xA395C0
void __fastcall UFG::qTaskManager::SyncPlat(UFG::qTaskManager *this, UFG::qTask *task)
{
  __int64 CurrentThreadId; // rbx
  UFG::qTaskManagerData *mData; // rbx
  _RTL_CRITICAL_SECTION *v6; // rcx
  UFG::qTaskManagerData *v7; // rbx

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId == UFG::qGetMainThreadID() )
  {
    if ( task )
    {
      mData = this->mData;
      EnterCriticalSection((LPCRITICAL_SECTION)&this->mData->mLock);
      ++mData->mInLock;
      this->mData->mSyncTask = task;
      v6 = (_RTL_CRITICAL_SECTION *)this->mData;
      --v6[2].LockCount;
      LeaveCriticalSection(v6 + 1);
      while ( task->mSyncVars.v.mState != 4 )
        WaitForSingleObject(this->mData->mSyncEvent.mHandlePlat, 0x1388u);
    }
    else
    {
      WaitForSingleObject(this->mData->mEventAllDone.mHandlePlat, 0xFFFFFFFF);
    }
  }
  else if ( task )
  {
    while ( task->mSyncVars.v.mState != 4 )
      Sleep(0);
  }
  else
  {
    v7 = this->mData;
    while ( v7->mNumDoneTasks != v7->mNumTotalTasks )
      Sleep(0);
  }
}

// File Line: 679
// RVA: 0xA378B0
void __fastcall UFG::qTaskManager::AddDependentPlat(UFG::qTaskManager *this, UFG::qTask *task, UFG::qTask *dependent)
{
  UFG::qTaskManagerData *mData; // rbx
  char *v7; // rax
  _QWORD *v8; // r8
  _RTL_CRITICAL_SECTION *v9; // rcx

  mData = this->mData;
  EnterCriticalSection((LPCRITICAL_SECTION)&this->mData->mLock);
  ++mData->mInLock;
  v7 = UFG::qLinearAllocator::Malloc(this->mAllocator, 0x10u, 0x10u);
  v8 = v7;
  if ( v7 )
  {
    *(_QWORD *)v7 = 0i64;
    *((_QWORD *)v7 + 1) = task;
  }
  else
  {
    v8 = 0i64;
  }
  *v8 = dependent->mSyncVars.v.mDependents;
  dependent->mSyncVars.v.mDependents = (unsigned __int64)v8;
  if ( dependent->mSyncVars.v.mState != 4 )
    ++task->mSyncVars.v.mNumDependents;
  v9 = (_RTL_CRITICAL_SECTION *)this->mData;
  --v9[2].LockCount;
  LeaveCriticalSection(v9 + 1);
}

// File Line: 707
// RVA: 0xA391C0
void __fastcall UFG::qTaskManager::Queue(UFG::qTaskManager *this, UFG::qTaskGroup *task_group)
{
  UFG::qTaskManagerData *mData; // rbx
  _RTL_CRITICAL_SECTION *v5; // rcx

  mData = this->mData;
  EnterCriticalSection((LPCRITICAL_SECTION)&this->mData->mLock);
  ++mData->mInLock;
  UFG::qTaskManager::AddDependentPlat(this, &task_group->mEndTask, &task_group->mStartTask);
  task_group->mEndTask.mSyncVars.v.mNumDependents += LOWORD(task_group->mNumTasks);
  this->mData->mNumTotalTasks += task_group->mNumTasks;
  UFG::qTaskManager::Queue(this, &task_group->mEndTask);
  UFG::qTaskManager::Queue(this, &task_group->mStartTask);
  v5 = (_RTL_CRITICAL_SECTION *)this->mData;
  --v5[2].LockCount;
  LeaveCriticalSection(v5 + 1);
}

// File Line: 746
// RVA: 0xA390C0
void __fastcall UFG::qTaskManager::Queue(UFG::qTaskManager *this, UFG::qTask *task)
{
  UFG::qTaskManagerData *mData; // rbx
  UFG::qTaskManagerData *v5; // rbx
  UFG::qNode<UFG::qTask,UFG::TaskPlat> *mNext; // rax
  _RTL_CRITICAL_SECTION *p_mLock; // rcx
  UFG::qTaskManagerData *v8; // r8

  mData = this->mData;
  EnterCriticalSection((LPCRITICAL_SECTION)&this->mData->mLock);
  ++mData->mInLock;
  ++this->mData->mNumTotalTasks;
  if ( task->mSyncVars.v.mNumDependents )
  {
    task->mSyncVars.v.mState = 2;
  }
  else
  {
    v5 = this->mData;
    task->mSyncVars.v.mState = 1;
    ResetEvent(v5->mEventAllDone.mHandlePlat);
    mNext = v5->mQueuedTasks.mNode.mNext;
    v5->mQueuedTasks.mNode.mNext = &task->UFG::qNode<UFG::qTask,UFG::TaskPlat>;
    task->UFG::qNode<UFG::qTask,UFG::TaskPlat>::mPrev = &v5->mQueuedTasks.mNode;
    task->UFG::qNode<UFG::qTask,UFG::TaskPlat>::mNext = mNext;
    mNext->mPrev = &task->UFG::qNode<UFG::qTask,UFG::TaskPlat>;
    SetEvent(v5->mEventAdd.mHandlePlat);
  }
  p_mLock = (_RTL_CRITICAL_SECTION *)&this->mData->mLock;
  --p_mLock[1].LockCount;
  LeaveCriticalSection(p_mLock);
  v8 = this->mData;
  if ( !this->mData->mMaxThreads
    && (unsigned __int64 *)&v8->mQueuedTasks.mNode.mNext[-1] != &v8->mThreads[4].mHandlePlat64 )
  {
    do
    {
      UFG::qTaskManagerData::ExecuteTask(v8, 0);
      v8 = this->mData;
    }
    while ( &this->mData->mQueuedTasks.mNode.mNext[-1] != (UFG::qNode<UFG::qTask,UFG::TaskPlat> *)&this->mData->mThreads[4].mHandlePlat64 );
  }
}

